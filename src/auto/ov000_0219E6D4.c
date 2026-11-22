/* 14 functions from 0x0219E6D4 to 0x0219F6D0 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

#pragma inline_depth(0)
static inline s32 E6D4Offset(s16 index) { return index * (s16)14; }
static inline s32 E6D4Call(u8 *p,s16 index) { s32 StepMapViewToTile(u8,u8); u8 *q=p+0x59a4+E6D4Offset(index);return StepMapViewToTile(q[1],q[2]); }
static inline s32 E6D4Check(u8 *p, s16 index) { u8 *q=p+0x59a4+E6D4Offset(index); s32 yes=M2C_FIELD(p+M2C_FIELD(p,u16*,0x52a4)*0x8c,u8*,0x67c3); s32 y=q[2]; u32 x=q[1],bit; if(yes&2)yes=1;else{bit=x+M2C_FIELD(p+y*2,u16*,0x3758);yes=1;if((u8)(M2C_FIELD(p+(bit>>3),u8*,0x5201)&(1<<(bit&7)))==0)yes=0;} return yes; }

/* AI turn-plan phase 7: no single unit is picked.  Install the army-wide
 * MarkAiUnitAttackCells action, which marks the cells each of the current
 * player's units can attack; the AI_UNIT_LIST_NO_UNIT entry runs it once
 * without a cursor unit. */
void StartAiAttackCellScanPhase(void) {
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK MarkAiUnitAttackCells;

    gAiUnitListCursor = &gAiUnitList;
    *gAiUnitListCursor++ = AI_UNIT_LIST_NO_UNIT;
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &MarkAiUnitAttackCells;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn phase starter for kind-5 units (the kind-5..6 family, such as
 * submarines): collect the current player's available kind-5 units into
 * gAiUnitList and install their action callback. */
void SelectAiKind5Unit(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiKind5Action;
    s32 unitId;
    s32 offset;
    s8 *cursor;
    u16 groupBase;
    u32 kind;
    void *units;
    void *map;
    void *unit;

    gAiUnitListCursor = &gAiUnitList;
    map = *gCurrentMap;
    groupBase = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
    unitId = groupBase + 1;
    if (unitId < groupBase + MAP_UNIT_GROUP_SCAN) {
        offset = unitId * MAP_UNIT_STRIDE;
        do {
            units = (u8 *)map + MAP_UNIT_RECORDS;
            kind = (u32)(M2C_FIELD(units, u8 *, offset + MAP_UNIT_KIND) << 26) >> 26;
            if (kind != 0) {
                unit = (u8 *)units + offset;
                if (!(M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) & 1) && kind == 5) {
                    cursor = gAiUnitListCursor;
                    gAiUnitListCursor = cursor + 1;
                    *cursor = unitId;
                }
            }
            unitId++;
            map = *gCurrentMap;
            offset += MAP_UNIT_STRIDE;
        } while (unitId < gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &RunAiKind5Action;
    gAiCommandState[AI_COMMAND_STATE_PHASE] = 2;
}

void func_ov000_0219e830(void) {
    extern s8 *gAiCommandState;
    *gAiCommandState = 4;
}

/* Run the AI's unit-selection step for the current plan phase: call the routine
 * the normal role table holds for that phase, or the blind one when the AI cannot
 * see its units (fog of war, or snow cutting vision), then move on to the next
 * plan phase. */
void RunAiUnitSelectionStep(void) {
    extern void (*data_ov000_021df42c[])(void);
    extern void (*data_ov000_021df4b8[])(void);
    extern s8 *gAiCommandState;
    extern void **gCurrentMap;
    void *map;
    map = *gCurrentMap;
    if (M2C_FIELD(map, u8 *, MAP_FOG) == 0 && M2C_FIELD(map, u8 *, MAP_WEATHER) != WEATHER_SNOW) {
        data_ov000_021df42c[M2C_FIELD(gAiCommandState, u8 *, AI_STATE_PHASE)]();
    } else {
        data_ov000_021df4b8[M2C_FIELD(gAiCommandState, u8 *, AI_STATE_PHASE)]();
    }
    M2C_FIELD(gAiCommandState, u8 *, AI_STATE_PHASE)++;
}

/* Whether the AI action view may be skipped: the battle has ended while another
 * console's AI command is being replayed, unless this console is the host and the
 * current player is a CPU. */
s32 ShouldSkipAiActionView(void) {
    s32 IsLocalSessionHost();
    extern u8 gBattleEndState;
    extern u16 gLinkAiCommandStage;
    extern void **gCurrentMap;
    void *map;
    if (gBattleEndState == 0) {
        return 0;
    }
    if (IsLocalSessionHost() != 0) {
        map = *gCurrentMap;
        if (M2C_FIELD((u8 *) map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, PLAYER_CONTROL_OFF) == PLAYER_CONTROL_CPU) {
            return 0;
        }
    }
    if (gLinkAiCommandStage != AI_COMMAND_STAGE_BUSY) {
        return 0;
    }
    return 1;
}

/* Runs the handler of the AI command's current step (AI_COMMAND_STATE_STEP) and
 * keeps dispatching while the handler returns nonzero: the handlers advance the
 * step themselves and return 0 once the AI has to wait for the screen. */
s32 ProcessAiCommandStep(void) {
    s32 func_ov000_0219e9f4();
    s32 RunAiCommandMoveStep();
    s32 func_ov000_0219f0d8();
    s32 ProcessAiCommandDelay();
    s32 func_ov000_0219f918();
    s32 PlayAiAttackEffect();
    s32 func_ov000_0219f9c0();
    s32 func_ov000_0219fa0c();
    s32 FinishAiUnitMove();
    s32 func_ov000_0219fa98();
    extern s8 *gAiCommandState;
    s32 continues;
    continues = 0;
    do {
        switch (M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_STEP)) {
        case 0:
            continues = func_ov000_0219e9f4();
            break;
        case 1:
            continues = RunAiCommandMoveStep();
            break;
        case 2:
            continues = func_ov000_0219f0d8();
            break;
        case 3:
            continues = func_ov000_0219f918();
            break;
        case 4:
            continues = PlayAiAttackEffect();
            break;
        case 5:
            continues = func_ov000_0219fa0c();
            break;
        case 6:
            continues = func_ov000_0219f9c0();
            break;
        case 7:
            continues = ProcessAiCommandDelay();
            break;
        case 8:
            continues = FinishAiUnitMove();
            break;
        case 9:
            continues = func_ov000_0219fa98();
            break;
        default:
            continues = 0;
            break;
        }
    } while (continues != 0);
    return continues;
}

#pragma push
#pragma opt_common_subs off
s32 func_ov000_0219e9f4(void)
{
    s32 SetRandomSeed(s32);
    s32 StepMapViewToTile(u8, u8);
    void func_020844a0(u8 *, u8 *);
    void func_020d61f0(void);
    s32 IsPlayerLocallyControlled(s32);
    s32 IsLocalSessionHost(void);
    u8 IsUnitSubmerged(void *);
    u8 func_020a7d68(void *);
    s32 ShouldSkipAiActionView(void);
    extern u8 gAiCommand[];
    extern s8 *gAiCommandState;
    extern void **gCurrentMap;
    extern u8 gCommandPath[];
    extern u8 gBattleEndState;

    u8 *map;
    u8 *unit;
    u16 player;
    u16 flags;
    u32 cell;
    u8 x, y;
    u8 kind;
    s32 visible;
    s32 scrolling;

    SetRandomSeed(M2C_FIELD(gAiCommand, s32 *, AI_COMMAND_SEED));
    kind = gAiCommand[AI_COMMAND_KIND];
    if (kind == 20) {
        gAiCommandState[AI_COMMAND_STATE_STEP] = 2;
        return 1;
    }

    switch (kind) {
    case 1:
    case 12:
    case 13:
    case 15:
    case 16:
    case 17:
    case 18:
        scrolling = 0;
        if (kind == 15) {
            M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID) = gAiCommand[AI_COMMAND_ACTOR];
            map = *gCurrentMap;
            M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT) =
                map + MAP_UNIT_RECORDS + M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID) * MAP_UNIT_STRIDE;
            unit = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
            if (unit != NULL)
                ((BattleMapUnitHead *)unit)->fuel = gAiCommand[AI_COMMAND_FUEL_LEFT];
        }
        if (gAiCommand[AI_COMMAND_KIND] == 16) {
            M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID) = gAiCommand[AI_COMMAND_ACTOR];
            map = *gCurrentMap;
            M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT) =
                map + MAP_UNIT_RECORDS + M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID) * MAP_UNIT_STRIDE;
            map = *gCurrentMap;
            player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
            unit = M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT);
            y = unit[MAP_UNIT_Y];
            x = unit[MAP_UNIT_X];
            if (M2C_FIELD(map + player * MAP_PLAYER_STRIDE, u8 *, 0x67c3) & 2) {
                visible = 1;
            } else {
                visible = 1;
                    cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
                if ((u8)(M2C_FIELD(map + (cell >> 3), u8 *, MAP_CELL_BITMAP) & (visible << (cell & 7))) == 0)
                    visible = 0;
            }
            if (visible)
                scrolling = StepMapViewToTile(x, y);
        }
        gAiCommandState[AI_COMMAND_STATE_STEP] = 2;
        return (u8)(scrolling == 0);
    }

    M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID) = gAiCommand[AI_COMMAND_ACTOR];
    map = *gCurrentMap;
    M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT) =
        map + MAP_UNIT_RECORDS + M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID) * MAP_UNIT_STRIDE;
    M2C_FIELD(*gCurrentMap, u16 *, MAP_PATH_X) = gAiCommand[AI_COMMAND_OLD_X];
    M2C_FIELD(*gCurrentMap, u16 *, MAP_PATH_Y) = gAiCommand[AI_COMMAND_OLD_Y];
    M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_OLD_X) = gAiCommand[AI_COMMAND_OLD_X];
    M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_OLD_Y) = gAiCommand[AI_COMMAND_OLD_Y];
    M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_X) = gAiCommand[AI_COMMAND_CURSOR_X];
    M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_Y) = gAiCommand[AI_COMMAND_CURSOR_Y];

    if ((u8)(gAiCommand[AI_COMMAND_KIND] + 0xea) <= 1) {
        scrolling = 0;
        if (!ShouldSkipAiActionView()) {
            map = *gCurrentMap;
            player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
            unit = M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT);
            y = unit[MAP_UNIT_Y];
            x = unit[MAP_UNIT_X];
            if (M2C_FIELD(map + player * MAP_PLAYER_STRIDE, u8 *, 0x67c3) & 2) {
                visible = 1;
            } else {
                visible = 1;
                    cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
                if ((u8)(M2C_FIELD(map + (cell >> 3), u8 *, MAP_CELL_BITMAP) & (visible << (cell & 7))) == 0)
                    visible = 0;
            }
            if (visible)
                scrolling = StepMapViewToTile(x, y);
        }
        func_020844a0(gCommandPath, (u8 *)*gCurrentMap + MAP_CURSOR_PATH);
        func_020d61f0();
        gAiCommandState[AI_COMMAND_STATE_STEP] = 2;
        return (u8)(scrolling == 0);
    }

    if (!IsPlayerLocallyControlled(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) {
        map = *gCurrentMap;
        unit = M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT);
        flags = M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS);
        if (!(flags & 8)) {
            M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER) = 0;
        } else {
            M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) = flags & ~8;
            map = *gCurrentMap;
            y = gAiCommand[AI_COMMAND_OLD_Y];
            x = gAiCommand[AI_COMMAND_OLD_X];
            cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER) = map[cell];
        }
    }

    if ((M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) == 14 && gBattleEndState && !IsLocalSessionHost()) ||
        M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) == 19) {
        M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_DIR) = 0;
        unit = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
        ((BattleMapUnitHead *)unit)->fuel = gAiCommand[AI_COMMAND_FUEL_LEFT];
        gAiCommandState[AI_COMMAND_STATE_STEP] = 1;
    }

    scrolling = 0;
    if (!ShouldSkipAiActionView()) {
        map = *gCurrentMap;
        player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
        unit = M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT);
        visible = M2C_FIELD(map + player * MAP_PLAYER_STRIDE, u8 *, 0x67c3);
        y = unit[MAP_UNIT_Y];
        x = unit[MAP_UNIT_X];
        if (visible & 2) {
            visible = 1;
        } else {
            cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            visible = 1;
            if ((u8)(M2C_FIELD(map + (cell >> 3), u8 *, MAP_CELL_BITMAP) & (visible << (cell & 7))) == 0)
                visible = 0;
        }
        if ((u8)!visible == 0 && (!IsUnitSubmerged(unit) ||
            func_020a7d68(M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT)))) {
            unit = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
            scrolling = StepMapViewToTile(unit[MAP_UNIT_X], unit[MAP_UNIT_Y]);
        }
    }
    gAiCommandState[AI_COMMAND_STATE_STEP] = 1;
    return (u8)(scrolling == 0);
}
#pragma pop
/* AI command step 1: clear the old cursor sprites, restore the command's path
 * onto the map and line the acting unit up for its move, then work out whether
 * the path ends in an attack (which records a battle command).  Starts the unit
 * move, advances the command to step 2 and returns 1 when the path is already at
 * its destination (MOVE_DIR_STOP), so the command machine can carry on at once. */
s32 RunAiCommandMoveStep(void) {
    void func_020d61f0(void);
    void *CreateUnitMoveForUnit(void *);
    void RefreshMapView(void);
    void func_020844a0(u8 *, u8 *);
    s32 ResolvePathAttack(s32, s32, s32, void *, s32);
    s32 IsPlayerLocallyControlled(s32);
    void SetBattleCommand(s32, s32, s32, s32);
    void func_020a64ec(void *);
    extern void **gCurrentMap;
    extern u8 gCommandPath[];
    extern u8 gAiCommand[];
    extern s8 *gAiCommandState;

    s32 attack;

    func_020d61f0();
    CreateUnitMoveForUnit(*(void **)((u8 *)*gCurrentMap + MAP_CURSOR_UNIT));
    RefreshMapView();
    func_020844a0(gCommandPath, (u8 *)*gCurrentMap + MAP_CURSOR_PATH);
    attack = ResolvePathAttack(
        *(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_OLD_X),
        *(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_OLD_Y),
        (*(BattleMapUnitHead **)((u8 *)*gCurrentMap + MAP_CURSOR_UNIT))->kind,
        (u8 *)*gCurrentMap + MAP_CURSOR_PATH,
        4);
    if (attack != 0) {
        if (IsPlayerLocallyControlled(*(u16 *)((u8 *)*gCurrentMap + MAP_CURRENT_PLAYER)) != 0) {
            SetBattleCommand(0xf, *(u8 *)((u8 *)*gCurrentMap + MAP_CURSOR_UNIT_ID), 0, 0);
        }
        gAiCommand[AI_COMMAND_KIND] = 2;
    }
    func_020a64ec((u8 *)*gCurrentMap + MAP_CURSOR_PATH);
    gAiCommandState[AI_COMMAND_STATE_STEP] = 2;
    return (*(s8 *)((u8 *)*gCurrentMap + MAP_CURSOR_PATH) == MOVE_DIR_STOP) ? 1 : 0;
}

#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_ov000_0219f0d8(void) {
    s32 IsPlayerHuman(s32);
    void SetMapCursorTargetTile(s32, s32);
    void RevealUnitsAroundCursor(s32, s32, void *);
    void MarkPathThreatRange(s32, s32, void *);
    void RefreshMapView(void);
    void func_020bbc2c(s32);
    void BattleUpdateUnitCursor(void);
    void func_ov000_0219f3fc(void);
    void func_ov000_0219f448(void);
    void ApplyWeatherCommand(void);
    u8 AiMoveCursorToCommandTile(void);
    u8 AiMoveCursorToCommandPoint(void);
    void LoadUnitIntoTransport(void);
    void func_ov000_0219fabc(s32);
    void func_020bb768(void);
    void func_020bbac8(void);
    void SubmergeUnit(void);
    void SurfaceUnit(void);
    void DestroyCursorUnit(void);
    void func_020cbffc(void);
    void func_020cc028(void);
    s32 func_ov000_0219f6d0(void);
    s32 func_ov000_0219f6fc(void);
    void AiProduceCargoUnit(void);
    void func_020bc0e0(void);
    void BeginUnitAction(void);
    void func_020bb028(void);
    void func_020bb110(void);
    extern u8 gAiCommand[];
    extern void **gCurrentMap;
    extern s8 *gAiCommandState;

    switch (gAiCommand[0]) {
    case 2: case 13: case 14: case 16: case 17:
    case 18: case 19: case 21: case 23:
        break;
    default:
        *(u16 *)(*(u8 **)((u8 *)*gCurrentMap + 0x52d0) + 4) |= 1;
        *(s8 *)(*(u8 **)((u8 *)*gCurrentMap + 0x52d0) + 1) = *(s16 *)((u8 *)*gCurrentMap + 0x52dc);
        *(s8 *)(*(u8 **)((u8 *)*gCurrentMap + 0x52d0) + 2) = *(s16 *)((u8 *)*gCurrentMap + 0x52de);
        if (IsPlayerHuman(*(u16 *)((u8 *)*gCurrentMap + 0x52a4)) != 0) {
            SetMapCursorTargetTile(*(s16 *)((u8 *)*gCurrentMap + 0x52dc), *(s16 *)((u8 *)*gCurrentMap + 0x52de));
            RevealUnitsAroundCursor(*(s16 *)((u8 *)*gCurrentMap + 0x52e0), *(s16 *)((u8 *)*gCurrentMap + 0x52e2), (u8 *)*gCurrentMap + 0x5388);
            MarkPathThreatRange(*(s16 *)((u8 *)*gCurrentMap + 0x52e0), *(s16 *)((u8 *)*gCurrentMap + 0x52e2), (u8 *)*gCurrentMap + 0x5388);
        }
        RefreshMapView();
        break;
    }

    switch (gAiCommand[0]) {
    case 0:
    case 1:
    case 16:
        break;
    case 2:
        func_ov000_0219f3fc();
        break;
    case 3:
        func_ov000_0219f448();
        break;
    case 4:
        ApplyWeatherCommand();
        break;
    case 5:
        func_020bbc2c(*(u16 *)((u8 *)*gCurrentMap + 0x52a4));
        BattleUpdateUnitCursor();
        break;
    case 6:
        BattleUpdateUnitCursor();
        break;
    case 7:
        func_020bb110();
        BattleUpdateUnitCursor();
        break;
    case 8:
        return AiMoveCursorToCommandTile();
    case 9:
        return AiMoveCursorToCommandPoint();
    case 10:
        LoadUnitIntoTransport();
        BattleUpdateUnitCursor();
        break;
    case 11:
        func_ov000_0219fabc(1);
        func_ov000_0219fabc(0);
        gAiCommandState[1] = 8;
        break;
    case 12:
        func_020bb768();
        BattleUpdateUnitCursor();
        break;
    case 13:
        func_020bbac8();
        break;
    case 14:
        SubmergeUnit();
        BattleUpdateUnitCursor();
        break;
    case 15:
        SurfaceUnit();
        BattleUpdateUnitCursor();
        break;
    case 17:
        DestroyCursorUnit();
        break;
    case 18:
        func_020cbffc();
        break;
    case 19:
        func_020cc028();
        break;
    case 20:
        return func_ov000_0219f6d0();
    case 21:
        return func_ov000_0219f6fc();
    case 22:
        AiProduceCargoUnit();
        BattleUpdateUnitCursor();
        break;
    case 23:
        func_020bc0e0();
        BattleUpdateUnitCursor();
        break;
    case 24: {
        u8 *d = gAiCommand;
        *(u8 *)((u8 *)*gCurrentMap + d[6] * 0x8c + 0x67ce) = d[7];
        break;
    }
    default: {
        BeginUnitAction();
        func_020bb028();
        gAiCommandState[0] = 2;
        gAiCommandState[1] = 0;
        break;
    }
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
void func_ov000_0219f3fc(void) {
    void PlaySoundAtTile(s32, u8, u8);
    void ProduceUnit(u8, u8, u8);
    extern u8 gAiCommand[];
    extern s8 *gAiCommandState;
    ProduceUnit(gAiCommand[2], gAiCommand[3], gAiCommand[1]);
    PlaySoundAtTile(0x111, gAiCommand[2], gAiCommand[3]);
    M2C_FIELD(gAiCommandState, s8 *, 1) = 9;
}

void func_ov000_0219f448(void) {
    void PlaySoundAtTile(s32, u8, u8);
    void ProduceUnit(u8, u8, u8);
    extern u8 gAiCommand[];
    extern s8 *gAiCommandState;
    ProduceUnit(gAiCommand[2], gAiCommand[3], gAiCommand[1]);
    PlaySoundAtTile(0x111, gAiCommand[2], gAiCommand[3]);
    M2C_FIELD(gAiCommandState, s8 *, 1) = 9;
}

/* AI command kind 4: apply a weather change to the battle map.  It switches the
 * map to its weather state, spawns the weather sprite and resets the AI command
 * phase, then copies the command's weather start and the four per-player change
 * delays onto the map. */
void ApplyWeatherCommand(void) {
extern void **gCurrentMap;
extern s8 *gAiCommandState;
extern u8 gAiCommand[];
void func_020a6fcc(void);
s32 i;
u8 *p;
M2C_FIELD(*gCurrentMap,u16 *,MAP_STATE)=1;
func_020a6fcc();
p=gAiCommand;
*gAiCommandState=AI_COMMAND_PHASE_START_TURN;
M2C_FIELD(*gCurrentMap,u8 *,MAP_WEATHER_START)=p[6];
for(i=0;i<4;i++){
M2C_FIELD((u8 *)*gCurrentMap+i,u8 *,MAP_WEATHER_DELAY)=p[12];
p++;
}
}

#pragma opt_common_subs off
#pragma opt_propagation off
/* AI command 8, "move the cursor": when the command's target tile is on the current
   player's team (or in the second team's visibility bitmap), move the map cursor
   to that tile and report 1; then reset the command timer and advance the AI
   command step.  The target tile is the unit record's x/y at gAiCommand[6]. */
u8 AiMoveCursorToCommandTile(void){
extern void **gCurrentMap;
extern u8 gAiCommand[];
extern s8 *gAiCommandState;
extern s32 gAiCommandTimer;
s32 StepMapViewToTile(u8,u8);
u8 result;
s32 value;
u8 *p;
s16 index;
s32 offset;
u8 *q;
s32 yes,y;
u32 x,bit;
p=*gCurrentMap;
index=gAiCommand[AI_COMMAND_UNIT];
offset=index*(s16)14;
yes=M2C_FIELD(p+M2C_FIELD(p,u16 *,MAP_CURRENT_PLAYER)*140,u8 *,0x67c3);
q=p+0x59a4+offset;
y=q[2];x=q[1];
value=0;
if(yes&2)yes=1;
else{
bit=x+M2C_FIELD(p+y*2,u16 *,MAP_ROW_OFFSETS);
yes=1;
if((u8)(M2C_FIELD(p+(bit>>3),u8 *,MAP_CELL_BITMAP)&(1<<(bit&7)))==0)yes=0;
}
if(yes){
q=p+0x59a4+offset;
value=StepMapViewToTile(q[1],q[2]);
}
gAiCommandTimer=0;
M2C_FIELD(gAiCommandState,u8 *,AI_COMMAND_STATE_STEP)=7;
result=value==0;
return result;
}
/* AI command 9: move the cursor to the tile named by the command's two
 * parameters when the current player can see it; clear the command timer and
 * advance to step 7, otherwise fail to step 3.  Returns 1 when the move
 * failed. */
u8 AiMoveCursorToCommandPoint(void){
s32 StepMapViewToTile(u8,u8);extern void **gCurrentMap;extern u8 gAiCommand[];extern s8 *gAiCommandState;extern s32 gAiCommandTimer;
void *map=*gCurrentMap;u8 y=gAiCommand[7],x=gAiCommand[6];s32 moved=0;u32 index;u32 flags; s32 visible;
flags=M2C_FIELD((u8 *)map+M2C_FIELD(map,u16 *,0x52a4)*140,u8 *,0x67c3);
if(flags&2)visible=1;
else {
visible=1;
index=x+M2C_FIELD((u8 *)map+y*2,u16 *,MAP_ROW_OFFSETS);
if(!(u8)(M2C_FIELD((u8 *)map+(index>>3),u8 *,MAP_CELL_BITMAP)&(1<<(index&7))))visible=0;
}
if(visible){moved=StepMapViewToTile(x,y);gAiCommandTimer=0;gAiCommandState[1]=7;}else gAiCommandState[1]=3;
return moved==0;
}

