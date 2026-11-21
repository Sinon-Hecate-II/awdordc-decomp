/* 14 functions from 0x02199614 to 0x0219A584 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
#include "ov000_unit_entry.h"
typedef struct { u16 value:7; } Field7;

/* Builds the influence (threat) field of one player's units.  For each unit
 * that can act it computes an influence strength and either adds it to the
 * eligible map cells' field at map+0x2840 or lets AddUnitThreatInfluence apply
 * the unit's area of effect.  MAP_ACTIVE_PLAYER names the player processed. */
void BuildPlayerInfluence(u8 player) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 func_ov000_021973f8(s32);
s32 GetModifiedDamagePercent(s32,s32);
s32 ApplyAttackBonus(s32,s32,s32);
s32 ApplyCoZoneBonus(s32,s32,void*);
s32 ApplyHealthBonus(s32,void*,s32);
void AddUnitThreatInfluence(void*,s32,s32,s32,s32,s32,s32);
s32 IsCarrierUnitKind(s32);
s32 GetUnitAttackClass(s32);
s32 GetUnitMoveRange(s32,s32);
s32 FloodFillUnitRange(s32,s32,s32,s32,s32);
void MarkAdjacentCells(s32);
s32 tileX,tileY;
s32 unitId,influence;
UnkStruct_ov000_021A860C *unit;
u8 *map,*cell;
s32 owner,id,amount;
if(!func_ov000_021973f8(21))return;
M2C_FIELD(*gCurrentMap,u16 *,MAP_ACTIVE_PLAYER)=player;
for(unitId=gPlayerUnitIdBase[player]+1;unitId<gPlayerUnitIdBase[player]+51;unitId++){
map=(u8 *)*gCurrentMap;
unit=(UnkStruct_ov000_021A860C *)(map+MAP_UNIT_RECORDS+unitId*14);
if(!unit->unk0)continue;
if(M2C_FIELD(unit,u16 *,4)&8){
s32 unitY=((u8 *)unit)[2];s32 unitX=((u8 *)unit)[1];s32 row=M2C_FIELD(map+unitY*2,u16 *,MAP_ROW_OFFSETS);
id=M2C_FIELD(map+unitX+row,u8 *,0x508);
if(!IsCarrierUnitKind(((UnkStruct_ov000_021A860C *)(map+id*14+MAP_UNIT_RECORDS))->unk0))continue;
}
influence=GetModifiedDamagePercent(unit->unk0,21);
if(influence<25)continue;
influence=ApplyAttackBonus(influence,0,unit->unk0_6);
influence=ApplyCoZoneBonus(influence,0,unit);
influence=ApplyHealthBonus(influence,unit,unit->unk6);
if(!GetUnitAttackClass(unit->unk0)){
if(unit){if(!unit)id=0;else id=unit-(UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS);owner=(id>>6)+1;}else owner=0;
owner=GetUnitMoveRange(owner,unit->unk0);
FloodFillUnitRange(((u8 *)unit)[1],((u8 *)unit)[2],unit->unk0,owner,1);
MarkAdjacentCells(111);
for(tileY=0;tileY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);tileY++){
for(tileX=0;tileX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);tileX++){
map=(u8 *)*gCurrentMap;
if(((s8 **)(map+0x52e8))[tileY][tileX]>=0){
cell=map+tileX+((u16 *)map)[tileY+0x1bac];
amount=influence+((u8 *)(cell+0x2000))[0x840];
if(amount>=255)amount=255;
M2C_FIELD(cell,u8 *,0x2840)=amount;
}
}
}
}else AddUnitThreatInfluence(unit,influence,21,100,0,1,0);
}
}

/* Rebuilds the influence maps from the units of every player hostile to the
 * current one: clear the AI influence maps, refresh the order overlays, build
 * each such player's unit influence, then restore the active player. */
void BuildPlayerInfluenceMaps(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void ClearAiInfluenceMaps(void);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void BuildPlayerInfluence(u8);
    extern s32 *gCurrentMap;
    u16 savedPlayer;
    s32 player;

    savedPlayer = M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER);
    ClearAiInfluenceMaps();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (player = 1; player < 5; player++) {
        if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0) {
            BuildPlayerInfluence(player);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = savedPlayer;
}

#pragma opt_common_subs off
#pragma opt_propagation off
/* AI phase 2, one step per frame: takes the unit id under gAiUnitListCursor,
 * makes it the map's cursor unit (looking up its transport and clearing the
 * tile it stands on), resets the AI command state and runs the installed
 * gAiUnitAction callback to fill in the unit's command.  A filled command moves
 * the AI on to its action phase; otherwise the unit's tile is restored, the
 * cursor advances, and an exhausted list returns to the unit-planning phase. */
void PickAiUnitAction(void)
{
    s32 NextRandomValue(void);
    s32 Modulo(s32, s32);
    s32 func_02072b04(void *);
    s32 GetAiUnitMoveRange(BattleMapUnitHead *);
    extern s32 *gCurrentMap;
    extern u8 *gAiUnitListCursor;
    extern u8 *gAiCommandState;
    extern u8 *gAiSettings;
    extern u8 *gAiUnitTypeTuning;
    extern u8 gAiCommand[];
    extern M2C_UNK data_ov000_021df604;
    extern void (*gAiUnitAction)(void);

    s32 id = *gAiUnitListCursor;
    if (id == AI_UNIT_LIST_END) {
        gAiCommandState[AI_COMMAND_STATE_PHASE] = AI_COMMAND_PHASE_PLAN_UNITS;
        return;
    }

    if (id != AI_UNIT_LIST_NO_UNIT) {
        BattleMapUnitHead *unit;
        u8 *map;
        u16 flags;
        s32 slot;
        M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID) = id;
        map = (u8 *)*gCurrentMap;
        slot = M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID);
        M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT) =
            (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS) + slot;
        {
            u8 *settings = gAiSettings;
            unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
            gAiUnitTypeTuning = settings + 0x14 + 12 * (unit->kind - 1);
        }
        M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_CARRIER) = 0;
        unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
        flags = unit->flags;
        if ((flags & 1) || !unit->kind) {
            gAiUnitListCursor++;
            return;
        }
        if (flags & 8) {
            s32 x, y, row;
            unit->flags = flags & ~8;
            map = (u8 *)*gCurrentMap;
            unit = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);
            y = unit->y;
            x = unit->x;
            row = M2C_FIELD(map + 2 * y, u16 *, MAP_ROW_OFFSETS);
            M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER) = map[x + row];
        }

        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X) = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->x;
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_X) = M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X);
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y) = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->y;
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_Y) = M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y);
        gAiCommandState[AI_COMMAND_STATE_FLAGS] &= ~1;
        gAiCommandState[AI_COMMAND_STATE_FLAGS] &= ~2;
        M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_ACTION_FLAGS) = 0;
        gAiCommand[AI_COMMAND_KIND] = 0;
        gAiCommand[AI_COMMAND_READY] = 0;
        gAiCommand[AI_COMMAND_UNIT] = 0;
        gAiCommand[AI_COMMAND_ARG_Y] = 0;
        map = (u8 *)*gCurrentMap;
        if (!M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER)) {
            s32 x, y, row;
            unit = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);
            y = unit->y;
            x = unit->x;
            row = M2C_FIELD(map + 2 * y, u16 *, MAP_ROW_OFFSETS);
            map[x + row] = 0;
        }
        gAiCommandState[AI_COMMAND_STATE_TIEBREAK] = Modulo(NextRandomValue(), 100);
        gAiCommandState[AI_COMMAND_STATE_MOVE_RANGE] = GetAiUnitMoveRange(M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT));
    } else {
        gAiCommand[AI_COMMAND_READY] = 0;
    }

    if (func_02072b04(&data_ov000_021df604) == 0)
        gAiUnitAction();
    if (!gAiCommand[AI_COMMAND_READY]) {
        if (*gAiUnitListCursor != AI_UNIT_LIST_NO_UNIT) {
            u8 *map = (u8 *)*gCurrentMap;
            if (M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER)) {
                M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT)->flags |= 8;
                M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_CARRIER) = 0;
            } else {
                BattleMapUnitHead *unit = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);
                s32 tileUnitId = M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID);
                s32 y = unit->y;
                s32 x = unit->x;
                s32 row = M2C_FIELD(map + 2 * y, u16 *, MAP_ROW_OFFSETS);
                map[x + row] = tileUnitId;
            }
        }
        gAiUnitListCursor++;
        return;
    }
    gAiUnitListCursor++;
    gAiCommandState[AI_COMMAND_STATE_PHASE] = AI_COMMAND_PHASE_ACT;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
void func_ov000_02199ce0(void) {
void SendLinkCommand(void *,s32);
extern u8 data_ov000_021df7d0[];
extern u8 gBattleCommand[];
s32 i;
u8 *s;
u8 *d;
s=data_ov000_021df7d0;
d=gBattleCommand;
d[0]=s[0]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[1]=s[1];
*(s32 *)(d+8)=*(s32 *)(s+8);
d[6]=s[6]; d[7]=s[7]; d[0x12]=s[0x12];
for(i=0;i<6;i++,s++,d++) d[12]=s[12];
SendLinkCommand(gBattleCommand,0x14);
}
#pragma opt_lifetimes reset
void SetMapCursor(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    void func_ov000_0217e798(M2C_UNK, M2C_UNK, u8 *, u8 *, u8 *);
    void MarkCaptureUnitHasTarget(s32);
    M2C_UNK func_02072b10(M2C_UNK *, M2C_UNK);
    void BuildUnitMoveRange(void *);
    void func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    s32 UnpackCursorPath(void *, void *);
    s32 GetRandomSeed(void);
    s32 GetUnitMoveFuelCost(s32, s32);
    void func_ov000_02199ce0(void);
    extern s32 *gCurrentMap;
    extern M2C_UNK data_ov000_021df604;
    extern u8 gCommandPath[];
    extern u8 gAiCommand[];
    extern u8 gBattleEndState[];

    u8 *unit;
    s32 result;
    u8 *state;

    func_ov000_0217e798(arg0, arg1, &arg2, &arg3, &arg4);

    MarkCaptureUnitHasTarget(arg2);

    unit = *(u8 **)((u8 *)*gCurrentMap + 0x52D0);

    if (unit[1] == arg0 && unit[2] == arg1 &&
        (arg2 == 2 || ((u8 *)*gCurrentMap)[0x52D6] != 0)) {

        unit[0xA] |= 0x80;
        func_02072b10(&data_ov000_021df604, 1);
    }
    BuildUnitMoveRange(unit);
        func_01ffc4b8(arg0, arg1, (s32)(((u8 *)*gCurrentMap) + 0x5388));
        UnpackCursorPath(((u8 *)*gCurrentMap) + 0x5388, gCommandPath);

        gAiCommand[1] = ((u8 *)*gCurrentMap)[0x52D4];

        *(s32 *)(gAiCommand + 8) = GetRandomSeed();

        gAiCommand[4] = (u8)*((s16 *)(((u8 *)*gCurrentMap) + 0x52D8));
        gAiCommand[5] = (u8)*((s16 *)(((u8 *)*gCurrentMap) + 0x52DA));
        gAiCommand[2] = (u8)arg0;
        gAiCommand[3] = (u8)arg1;
        gAiCommand[0] = arg2;
        gAiCommand[6] = arg3;
        gAiCommand[7] = arg4;

        result=GetUnitMoveFuelCost((s32)*(u8 **)((u8 *)*gCurrentMap+0x52d0),((u8 *)*gCurrentMap)[0x52d5]);
        state=gAiCommand;
        unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
        ((volatile u8 *)state)[0x13] = 1;
        ((volatile u8 *)state)[0x12] = ((u32)(unit[10]<<25)>>25)-result;

    if (*(volatile u8 *)gBattleEndState != 0) {
        func_ov000_02199ce0();
    }
    func_02072b10(&data_ov000_021df604, 1);
}

void func_ov000_02199f38(void) {
    M2C_UNK func_02072b10(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021df604;
    func_02072b10(&data_ov000_021df604, 1);
}

/* Copies the cursor state into the battle command record gAiCommand: the actor
 * and command kind, the cursor and the tile it moved from, the two command
 * parameters and the random seed, plus the fuel the actor has left after the
 * move.  When the battle has ended the finished record is sent over the link. */
void SetBattleCommand(s32 kind, s32 actor, s32 arg, s32 argY) {
    s32 UnpackCursorPath(void *, void *);
    s32 GetRandomSeed(void);
    s32 GetUnitMoveFuelCost(s32, s32);
    void SendBattleCommandPacket(s32, s32, s32, s32);
    extern s32 *gCurrentMap;
    extern u8 gCommandPath[];
    extern u8 gAiCommand[];
    extern u8 gBattleEndState[];
    UnpackCursorPath((u8 *)*gCurrentMap + MAP_CURSOR_PATH, gCommandPath);
    gAiCommand[AI_COMMAND_ACTOR] = (u8)actor;
    *(s32 *)(gAiCommand + AI_COMMAND_SEED) = GetRandomSeed();
    gAiCommand[AI_COMMAND_KIND] = (u8)kind;
    gAiCommand[AI_COMMAND_CURSOR_X] = (u8)*(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_X);
    gAiCommand[AI_COMMAND_CURSOR_Y] = (u8)*(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_Y);
    gAiCommand[AI_COMMAND_OLD_X] = (u8)*(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_OLD_X);
    gAiCommand[AI_COMMAND_OLD_Y] = (u8)*(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_OLD_Y);
    gAiCommand[AI_COMMAND_UNIT] = (u8)arg;
    gAiCommand[AI_COMMAND_ARG_Y] = (u8)argY;
    if (*(s32 *)((u8 *)*gCurrentMap + MAP_CURSOR_UNIT) != 0) {
        s32 fuelCost = GetUnitMoveFuelCost(*(s32 *)((u8 *)*gCurrentMap + MAP_CURSOR_UNIT),
                                     (u8)*((u8 *)*gCurrentMap + MAP_CURSOR_DIR));
        volatile u8 *actingUnit = (volatile u8 *)*(s32 *)((u8 *)*gCurrentMap + MAP_CURSOR_UNIT);
        gAiCommand[AI_COMMAND_FUEL_LEFT] = (((u32)actingUnit[0xa] << 25) >> 25) - fuelCost;
    }
    if (gBattleEndState[0] != BATTLE_END_ENDED) {
        SendBattleCommandPacket(kind, actor, arg, argY);
    }
}

/* Keeps the AI-known mark of the unit under the cursor in step with the battle
 * command being replayed: a kind-4 command (a weather change) marks the unit as
 * known to the AI, while a command that moved the cursor to another tile clears
 * the mark.  A missing or dead unit under the cursor is left alone. */
void UpdateCursorUnitAiKnown(void) {
    extern s32 *gCurrentMap;
    extern u8 gAiCommand[];
    u8 *unit = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);

    if (!unit || !((BattleMapUnitHead *)unit)->health) return;

    if (gAiCommand[AI_COMMAND_KIND] == 4) {
        unit[MAP_UNIT_AI_STATE] |= MAP_UNIT_AI_KNOWN;
    } else if (gAiCommand[AI_COMMAND_CURSOR_X] != gAiCommand[AI_COMMAND_OLD_X] ||
               gAiCommand[AI_COMMAND_CURSOR_Y] != gAiCommand[AI_COMMAND_OLD_Y]) {
        unit[MAP_UNIT_AI_STATE] &= ~MAP_UNIT_AI_KNOWN;
    }
}

#pragma push
#pragma opt_strength_reduction off
/* Remembers the enemy units the AI can see: for every cell of the first team's
 * visibility bitmap that holds a unit of another army, set MAP_UNIT_AI_KNOWN on
 * that unit so the AI keeps tracking it (targeting, movement blocking) even when
 * it later leaves the AI's sight.  Runs at the end of the AI's turn. */
void MarkKnownEnemyUnits(void) {
    extern s32 *gCurrentMap;
    s32 IsCellUnitOnSameArmy(s32, s16, s16);
    s32 x, y;
    u32 idx;
    u8 *map = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(map, u16 *, MAP_WIDTH); x++) {
            idx = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            if ((u8)(M2C_FIELD(map + (idx >> 3), u8 *, MAP_CELL_BITMAP_TEAM_A) & (1 << (idx & 7))) &&
                M2C_FIELD(M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS) + (map + x), u8 *, MAP_CELL_VISIBLE_UNIT) != 0) {
                if (IsCellUnitOnSameArmy((u8)M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER), x, y) == 0) {
                    map = (u8 *)*gCurrentMap;
                    M2C_FIELD(map + MAP_UNIT_RECORDS + M2C_FIELD(M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS) + (map + x), u8 *, MAP_CELL_VISIBLE_UNIT) * MAP_UNIT_STRIDE, u8 *, MAP_UNIT_AI_STATE) |= MAP_UNIT_AI_KNOWN;
                }
            }
            map = (u8 *)*gCurrentMap;
        }
    }
}
/* Begins the AI's turn (the phase-0 handler of the AI command state machine):
 * points the cursor at the acting player's first unit, resets the command state,
 * runs the turn's setup steps (unit parameters, target areas, ...), and leaves
 * the state machine in phase 1. */
void BeginAiTurn(void) {
    void func_020c93cc(void);
    void SetupAiUnitParameters(u16);
    void UpdateAiCapabilityFlags(void);
    void func_ov000_0219a370(void);
    void MarkAiTargetAreas(void);
    void ClearAiUnitActions(void);
    void func_ov000_0219a6c8(void);
    void CountEnemyProperties(void);
    void Ov000_AssignAiOrders(void);
    void func_ov000_02181c88(void);
    void func_ov000_0219a350(void);
    void UpdateAiSupplyStates(void);
    s32 func_ov000_021a9b84(void);
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 *gAiCommandState;

    {
        u8 *map = *(u8 **)gCurrentMap;
        u16 player = *(u16 *)(map + MAP_CURRENT_PLAYER);
        map[MAP_CURSOR_UNIT_ID] = (u8)gPlayerUnitIdBase[player];
    }
    {
        u8 *map = *(u8 **)gCurrentMap;
        *(u8 **)(map + MAP_CURSOR_UNIT) = map + MAP_UNIT_RECORDS + map[MAP_CURSOR_UNIT_ID] * 0xe;
    }
    func_020c93cc();
    gAiCommandState[AI_COMMAND_STATE_ATTACKER] = (*(u8 **)gCurrentMap)[MAP_WEATHER];
    if ((*(u8 **)gCurrentMap)[MAP_WEATHER_MODE] == 1) {
        gAiCommandState[AI_COMMAND_STATE_PLAYER] = 0;
    } else {
        gAiCommandState[AI_COMMAND_STATE_PLAYER] = (*(u8 **)gCurrentMap)[MAP_WEATHER];
    }
    SetupAiUnitParameters(*(u16 *)(*(u8 **)gCurrentMap + MAP_CURRENT_PLAYER));
    UpdateAiCapabilityFlags();
    func_ov000_0219a370();
    MarkAiTargetAreas();
    ClearAiUnitActions();
    func_ov000_0219a6c8();
    CountEnemyProperties();
    Ov000_AssignAiOrders();
    func_ov000_02181c88();
    func_ov000_0219a350();
    UpdateAiSupplyStates();
    if (func_ov000_021a9b84() == 1) {
        gAiCommandState[AI_COMMAND_STATE_FLAGS] |= 0x04;
    } else {
        gAiCommandState[AI_COMMAND_STATE_FLAGS] &= ~0x04;
    }
    gAiCommandState[AI_COMMAND_STATE_FLAGS] |= 0x08;
    gAiCommandState[0x2] = 0;
    gAiCommandState[AI_COMMAND_STATE_STEP] = 0;
    gAiCommandState[AI_COMMAND_STATE_PHASE] = 1;
}

#pragma pop
void func_ov000_0219a350(void) {
    extern void *gAiState;
    M2C_FIELD(gAiState, s8 *, 2) = 0;
    M2C_FIELD(gAiState, s8 *, 3) = 0;
}

void func_ov000_0219a370(void) {
    extern s32 *gCurrentMap;
    s32 var_r1;
    void *var_r2;

    var_r1 = 0;
    var_r2 = *gCurrentMap + 0x6C60;
    do {
        M2C_FIELD(var_r2, s8 *, 3) = 0;
        M2C_FIELD(var_r2, s8 *, 4) = 0;
        var_r1 += 1;
        M2C_FIELD(var_r2, s8 *, 5) = 0;
        var_r2 += 6;
    } while (var_r1 < 0x63);
}

/* Count player `player`'s properties from the eight per-kind counters in the
 * player's map record, plus one; the AI weighs the enemy total with it. */
s32 CountPlayerProperties(s32 player) {
    extern s32 *gCurrentMap;
    u8 *record = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
    s32 sum = 0;
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 1];
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 0];
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 2];
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 3];
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 4];
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 5];
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 6];
    sum += record[PLAYER_REC_PROPERTY_COUNTS + 7];
    return sum + 1;
}

#pragma push
#pragma opt_strength_reduction off
/* For every property cell in the map's property list: if the cell is not marked
 * in the score layer yet, flood-fills a foot unit's movement range from it
 * (using the order layer as scratch), marks every reached cell in the score
 * layer, and counts the distinct target areas it found. */
void MarkAiTargetAreas(void) {
void SelectMapLayer(s32);
void FillMapLayer(s32);
M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
extern s32 *gCurrentMap;
extern u8 *gAiCommandState;
s32 areaCount=0;
u8 *entry;
s32 col,row;
u8 *map;
SelectMapLayer((s32)*gCurrentMap+MAP_CELL_SCORE);
FillMapLayer(areaCount);
SelectMapLayer((s32)*gCurrentMap+MAP_CELL_ORDER);
map=(u8 *)*gCurrentMap;
for(entry=map+MAP_PROPERTY_CELLS;*entry!=MAP_PROPERTY_END;entry+=MAP_PROPERTY_STRIDE){
if(M2C_FIELD(map+M2C_FIELD(entry,u8 *,MAP_PROPERTY_X)+M2C_FIELD(map+M2C_FIELD(entry,u8 *,MAP_PROPERTY_Y)*2,u16 *,MAP_ROW_OFFSETS),s8 *,MAP_CELL_SCORE)==0){
FloodFillUnitRange(M2C_FIELD(entry,u8 *,MAP_PROPERTY_X),M2C_FIELD(entry,u8 *,MAP_PROPERTY_Y),1,0x6e,0);
map=(u8 *)*gCurrentMap;
for(row=0;row<M2C_FIELD(map,u16 *,MAP_HEIGHT);row++){
for(col=0;col<M2C_FIELD(map,u16 *,MAP_WIDTH);col++){
if(M2C_FIELD(map+row*4,s8 **,MAP_GRID)[col]>=0){
M2C_FIELD(map+col+M2C_FIELD(map+row*2,u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_SCORE)=1;
}
map=(u8 *)*gCurrentMap;
}
}
areaCount++;
}
}
M2C_FIELD(gAiCommandState,u8 *,AI_COMMAND_STATE_TARGET_AREAS)=areaCount;
}
#pragma pop
