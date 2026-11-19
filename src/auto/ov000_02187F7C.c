/* 26 functions from 0x02187F7C to 0x02188D64 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
void func_ov000_02188688(void);
u8 func_ov000_021889ac(void);

u8 AiRangeReachesPlayerHq(void);


#pragma opt_strength_reduction off
void func_ov000_02187f7c(void) {
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    s32 GetAiUnitSearchRange(void *);
    s32 func_ov000_02187eac(s16 *);
    u8 IsUnitProductionTerrain(s32);
    void SelectMapLayer(void *);
    void FillMapCellLayer(void *, s32);
    u8 *map = *gCurrentMap;
    BattleMapUnitHead *cursor = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    BattleMapUnitHead *table = (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS);
    s32 offset = (s16)cursor->firstCarried * (s16)sizeof(BattleMapUnitHead);
    s32 range;
    s16 tile[2];

    if (!((BattleMapUnitHead *)((u8 *)table + offset))->kind) return;
    range = GetAiUnitSearchRange((u8 *)table + offset);
    cursor = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    FloodFillUnitRange(cursor->x, cursor->y, cursor->kind, MAP_GRID_NO_UNIT_MAX, 0);
    FillMapCellLayer((u8 *)*gCurrentMap + 0x3250, 0);
nextTile:
    if (!func_ov000_02187eac(tile)) return;
    {
        s32 x, y;
        SelectMapLayer((u8 *)*gCurrentMap + MAP_CELL_SCORE);
        FloodFillUnitRange(tile[0], tile[1], (u32)(M2C_FIELD((u8 *)table, u8 *, offset) << 26) >> 26, range, 0);
        if (data_ov000_021df64c() == 1) {
            s32 score = data_ov000_021df648();
            map = *gCurrentMap;
            for (y = 0; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); y++) {
                for (x = 0; x < M2C_FIELD(map, u16 *, MAP_WIDTH); x++) {
                    u8 *cell;
                    if (M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] >= 0 &&
                        IsUnitProductionTerrain(M2C_FIELD(map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), u8 *, MAP_CELL_TERRAIN))) {
                        map = *gCurrentMap;
                        cell = (map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)) + 0x3000;
                        if (M2C_FIELD(cell, u8 *, 0x250) < score) {
                            M2C_FIELD(cell, s8 *, 0x250) = score;
                            M2C_FIELD(gAiCommandState, u16 *, 8) |= 8;
                        }
                        map = *gCurrentMap;
                        M2C_FIELD(map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), s8 *, MAP_CELL_ORDER) = -1;
                    }
                    map = *gCurrentMap;
                }
            }
        } else {
            map = *gCurrentMap;
            for (y = 0; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); y++) {
                for (x = 0; x < M2C_FIELD(map, u16 *, MAP_WIDTH); x++) {
                    if (M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] >= 0 &&
                        IsUnitProductionTerrain(M2C_FIELD(map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), u8 *, MAP_CELL_TERRAIN))) {
                        map = *gCurrentMap;
                        M2C_FIELD(map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), s8 *, MAP_CELL_ORDER) = -1;
                    }
                    map = *gCurrentMap;
                }
            }
        }
        SelectMapLayer(map + MAP_CELL_ORDER);
        goto nextTile;
    }
}
#pragma opt_strength_reduction reset
s32 func_ov000_021882c4(void) {
    s32 CountUnusedCapturableProperties();
    s32 flag, count, current;
    if (func_ov000_02187e50() == 1) return 0;
    flag = CountAiAttackTargetUnits();
    if (flag) count = CountCapturableProperties();
    else count = CountUnusedCapturableProperties();
    if (count == 0) return 0;
    current = CountActiveTeamFootUnits();
    if (flag == 0) {
        if (current < count + 1) return 1;
    } else {
        if (current < count + 2) return 1;
    }
    return 0;
}

s32 func_ov000_02188338(void) {
    s32 CountActiveTeamFootUnits();
    s32 AiHasAttackTargetOrFootUnit();
    s32 temp_r4;
    s32 var_r0;
    s32 var_r5;

    temp_r4 = CountCapturableProperties();
    if (AiHasAttackTargetOrFootUnit() == 0) {
        var_r5 = 0x80;
    } else {
        var_r5 = 0;
    }
    var_r0 = (temp_r4 + 2) - CountActiveTeamFootUnits();
    if (var_r0 & 0x80) {
        var_r0 = 0x7F;
    }
    return var_r0 | var_r5;
}

void func_ov000_02188370(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = func_ov000_021882c4;
    data_ov000_021df648 = func_ov000_02188338;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
}

/* Whether the AI may still act with the foot unit at (x, y): flood-fill that
 * unit's search range, then return 1 while the team's active foot units stay
 * under the capturable properties plus two, 0 once they reach it. */
u8 CanDoFootAiAction(s32 x, s32 y) {
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *map, *unitBase;

    map = *gCurrentMap;
    unitBase = (u8 *)map + MAP_UNIT_RECORDS;
    offset = M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, 0x0D) * MAP_UNIT_STRIDE;
    FloodFillUnitRange(x, y, (u32)(M2C_FIELD(unitBase, u8 *, offset) << 26) >> 26, GetAiUnitSearchRange((u8 *)unitBase + offset), 0);
    current = CountActiveTeamFootUnits();
    if (current < CountCapturableProperties() + 2) result = 1;
    else result = 0;
    return result;
}

u8 func_ov000_02188448(void) {
    s32 func_ov000_02187e50();
    s32 temp_r0;
    u8 var_r0;

    if (func_ov000_02187e50() == 1) {
        return 0U;
    }
    temp_r0 = CountAiAttackTargetUnits();
    if (temp_r0 == 0) {
        return 0U;
    }
    if (CountTeamAttackUnits() < (s32) (temp_r0 + 5)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_02188488(void) {
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r2;

    temp_r4 = CountAiAttackTargetUnits();
    temp_r0 = CountTeamAttackUnits();
    if (temp_r4 > 5) {
        var_r2 = 5;
    } else {
        var_r2 = temp_r4;
    }
    if (((s32) (temp_r4 - var_r2) < temp_r0) && ((s32) (temp_r4 + var_r2) > temp_r0)) {
        var_r1 = 0x80;
    } else {
        var_r1 = 0;
    }
    if (temp_r4 > temp_r0) {
        var_r0_2 = temp_r4 - temp_r0;
    } else {
        var_r0_2 = temp_r0 - temp_r4;
    }
    var_r0 = var_r0_2 + 1;
    if (var_r0 & 0x80) {
        var_r0 = 0x7F;
    }
    return var_r0 | var_r1;
}

void func_ov000_021884e4(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))func_ov000_02188448;
    data_ov000_021df648 = func_ov000_02188488;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_02188688();
}

/* AI action check for unit AI states 0 and 1: flood-fill the acting unit's
 * movement range from (x,y), then report whether the enemy offers attack
 * targets and the team's attack units do not already outnumber them by five. */
u8 CanDoAiAction01(s32 x, s32 y) {
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 targetCount, unitOffset;
    u8 result;
    void *map, *unitRecords;
    map = *gCurrentMap;
    unitRecords = (u8 *)map + MAP_UNIT_RECORDS;
    unitOffset = M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED) * MAP_UNIT_STRIDE;
    FloodFillUnitRange(x, y, (u32)(M2C_FIELD(unitRecords, u8 *, unitOffset) << 26) >> 26, GetAiUnitSearchRange((u8 *)unitRecords + unitOffset), 0);

    targetCount = CountAiAttackTargetUnits();
    if (targetCount == 0) return 0;
    if (CountTeamAttackUnits() < targetCount + 5) result = 1;
    else result = 0;
    return result;
}

/* Returns 1 when the HQ cell of an enemy player (active, has an HQ, other team
 * than the current player) lies in the movement range marked in the map grid,
 * i.e. the AI unit whose range was just flood-filled could reach an enemy HQ.
 * This is the objective check of AI state 2. */
s32 AiRangeReachesEnemyHq(void) {
    s32 IsPlayerActive(s32);
    s32 PlayerHasHq(s32);
    s32 IsSameTeam(u16, s32);
    extern void **gCurrentMap;
    s32 player, offset;
    void *base, *entry;
    if (func_ov000_02187e50() == 1) return 0;
    for (player = 1, offset = MAP_PLAYER_STRIDE; player < 5; player++, offset += MAP_PLAYER_STRIDE) {
        if (IsPlayerActive(player) && !IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) && PlayerHasHq(player)) {
            base = *gCurrentMap;
            entry = (u8 *)base + offset;
            if (M2C_FIELD(M2C_FIELD((u8 *)base + ((u32)(M2C_FIELD(entry, u8 *, MAP_PLAYER_STATES + PLAYER_REC_HQ_Y) << 25) >> 23), s8 **, MAP_GRID), s8 *, M2C_FIELD(entry, u8 *, MAP_PLAYER_STATES + PLAYER_REC_HQ_X) & 0x7F) > 0) return 1;
        }
    }
    return 0;
}

s32 func_ov000_02188680(void) {
    return 1;
}

void func_ov000_02188688(void) {
    s32 AiRangeReachesEnemyHq(void);
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = AiRangeReachesEnemyHq;
    data_ov000_021df648 = func_ov000_02188680;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
}

void CanDoAiAction2(s32 arg0, s32 arg1) {
    s32 AiRangeReachesEnemyHq(void);
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, GetAiUnitSearchRange((u8 *)table + offset), 0);

    AiRangeReachesEnemyHq();
}

u8 func_ov000_02188744(void) {
    s32 CountAiAttackTargetUnits();
    s32 temp_r4;
    u8 var_r0;

    if (CountAiAttackTargetUnits() == 0) {
        return 0U;
    }
    temp_r4 = CountCapturableProperties();
    if (temp_r4 > CountTeamAttackUnits()) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_02188778(void) {
    s32 CountCapturableProperties();
    s32 CountTeamAttackUnits();
    s32 temp_r4;

    temp_r4 = CountCapturableProperties();
    return temp_r4 - CountTeamAttackUnits();
}

void func_ov000_02188790(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))func_ov000_02188744;
    data_ov000_021df648 = func_ov000_02188778;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_021884e4();
}

void CanDoAiAction34(s32 arg0, s32 arg1) {
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, GetAiUnitSearchRange((u8 *)table + offset), 0);
    func_ov000_02188744();
}

/* Returns 1 when the HQ cell of the current player (the side whose turn it is)
 * lies in the movement range marked in the map grid, i.e. the AI unit whose range
 * was just flood-filled could reach that HQ.
 * This is the objective check of AI state 5. */
u8 AiRangeReachesPlayerHq(void) {
    s32 PlayerHasHq(s32);
    extern void **gCurrentMap;
    void *base, *entry;
    u8 result;
    if (func_ov000_02187e50() == 1) return 0;
    if (PlayerHasHq(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) == 0) return 0;
    base = *gCurrentMap;
    entry = (u8 *)base + MAP_PLAYER_STATES + M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE;
    if (M2C_FIELD(M2C_FIELD((u8 *)base + ((u32)(M2C_FIELD(entry, u8 *, PLAYER_REC_HQ_Y) << 25) >> 23), s8 **, MAP_GRID), s8 *, M2C_FIELD(entry, u8 *, PLAYER_REC_HQ_X) & 0x7F) > 0) result = 1;
    else result = 0;
    return result;
}

s32 func_ov000_021888e4(void) {
    return 1;
}

void func_ov000_021888ec(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))AiRangeReachesPlayerHq;
    data_ov000_021df648 = func_ov000_021888e4;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_021884e4();
}

void CanDoAiAction5(s32 arg0, s32 arg1) {
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, GetAiUnitSearchRange((u8 *)table + offset), 0);
    AiRangeReachesPlayerHq();
}

#pragma opt_lifetimes off
u8 func_ov000_021889ac(void) {
    extern void **gCurrentMap;
    u16 value;
    s8 *bank;
    void *base, *entry;
    u8 result;
    base = *gCurrentMap;
    entry = (u8 *)base + 0x59A4 + M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xC) * 14;
    if (func_ov000_02187e50() == 1) return 0;
    value = M2C_FIELD(entry, u16 *, 8);
    bank = M2C_FIELD((u8 *)*gCurrentMap + (((u32)(value << 20) >> 26) * 4), s8 **, 0x52E8);
    if (bank[((u32)(value << 26) >> 26)] > 0) result = 1;
    else result = 0;
    return result;
}
#pragma opt_lifetimes reset
s32 func_ov000_02188a30(void) {
    return 1;
}

void func_ov000_02188a38(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))func_ov000_021889ac;
    data_ov000_021df648 = func_ov000_02188a30;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_021884e4();
}

/* For AI states 7..9: checks that the acting unit has an assigned move target
 * and that the target cell is inside the movement area just flood-filled. */
u8 CanDoAiAction789(s32 x, s32 y) {
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 unitOffset;
    void *map, *unitRecords;
    u16 target;
    s8 *targetRow;
    u8 result;

    map = *gCurrentMap;
    unitRecords = (u8 *)map + MAP_UNIT_RECORDS;
    unitOffset = M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED) * MAP_UNIT_STRIDE;
    FloodFillUnitRange(x, y, (u32)(M2C_FIELD(unitRecords, u8 *, unitOffset) << 26) >> 26, GetAiUnitSearchRange((u8 *)unitRecords + unitOffset), 0);

    target = M2C_FIELD((u8 *)unitRecords + unitOffset, u16 *, MAP_UNIT_TARGET);
    if (((u32)(target << 26) >> 26) == MAP_UNIT_TARGET_NONE) return 0;

    targetRow = M2C_FIELD((u8 *)*gCurrentMap + (((u32)(target << 20) >> 26) * 4), s8 **, MAP_GRID);
    if (targetRow[((u32)(target << 26) >> 26)] > 0) result = 1;
    else result = 0;
    return result;
}

#pragma push
#pragma opt_condition off
#pragma opt_strength_reduction off
/* Runs the AI action check for the unit's current state; if that action is not
 * possible, tries the fallback actions and records the state that can act. */
s32 TryUnitAiActions(s32 x, s32 y) {
    s32 IsFootUnitKind(s32);
    u8 CanDoFootAiAction(s32, s32);
    u8 CanDoAiAction01(s32, s32);
    u8 CanDoAiAction789(s32, s32);
    extern void **gCurrentMap;
    void *map, *unitBase;
    u8 *unit;
    s32 (*check)(s32, s32);
    s32 state;
    s32 result;

    map = *gCurrentMap;
    unitBase = (u8 *)map + MAP_UNIT_RECORDS;
    unit = (u8 *)unitBase + M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED) * MAP_UNIT_STRIDE;

    if (IsFootUnitKind(((u32)(unit[MAP_UNIT_KIND] << 26) >> 26)) != 0 || ((u32)(unit[MAP_UNIT_KIND] << 26) >> 26) == 0x0D) {
        check = (s32 (*)(s32, s32))CanDoFootAiAction;
    } else {
        state = ((u32)(unit[MAP_UNIT_AI_STATE] << 28) >> 28);
        switch (state) {
            case 0:
            case 1:
                check = (s32 (*)(s32, s32))CanDoAiAction01;
                break;
            case 2:
                check = (s32 (*)(s32, s32))CanDoAiAction2;
                break;
            case 3:
            case 4:
                check = (s32 (*)(s32, s32))CanDoAiAction34;
                break;
            case 5:
                check = (s32 (*)(s32, s32))CanDoAiAction5;
                break;
            case 7:
            case 8:
            case 9:
                check = (s32 (*)(s32, s32))CanDoAiAction789;
                break;
            default:
                check = 0;
                break;
        }
    }

    result = check(x, y);
    if (result == 1) return 1;

    state = ((u32)(unit[MAP_UNIT_AI_STATE] << 28) >> 28);
    switch (state) { case 7: case 8: case 9: return 0; default: break; }

    if (CanDoAiAction01(x, y) == 1) {
        unit[MAP_UNIT_AI_STATE] = (u8)(unit[MAP_UNIT_AI_STATE] & ~MAP_UNIT_AI_STATE_MASK);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_X_MASK) | MAP_UNIT_TARGET_NONE);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_Y_MASK) | MAP_UNIT_TARGET_Y_NONE);
        return 1;
    }
    if (((s32 (*)(s32, s32))CanDoAiAction34)(x, y) == 1) {
        unit[MAP_UNIT_AI_STATE] = (u8)((unit[MAP_UNIT_AI_STATE] & ~MAP_UNIT_AI_STATE_MASK) | 0x03);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_X_MASK) | MAP_UNIT_TARGET_NONE);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_Y_MASK) | MAP_UNIT_TARGET_Y_NONE);
        return 1;
    }
    if (((s32 (*)(s32, s32))CanDoAiAction2)(x, y) == 1) {
        unit[MAP_UNIT_AI_STATE] = (u8)((unit[MAP_UNIT_AI_STATE] & ~MAP_UNIT_AI_STATE_MASK) | 0x02);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_X_MASK) | MAP_UNIT_TARGET_NONE);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_Y_MASK) | MAP_UNIT_TARGET_Y_NONE);
        return 1;
    }
    return 0;
}
#pragma pop
