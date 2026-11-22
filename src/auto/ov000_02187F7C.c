/* 26 functions from 0x02187F7C to 0x02188D64 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
void func_ov000_02188688(void);
u8 AiAssignedTargetInMovementRange(void);

u8 AiRangeReachesPlayerHq(void);


#pragma opt_strength_reduction off
void AiScoreProductionTiles(void) {
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern s32 (*gAiPriorityPredicate)(void);
    extern s32 (*gAiPriorityScore)(void);
    s32 GetAiUnitSearchRange(void *);
    s32 FindReachableProductionTile(s16 *);
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
    if (!FindReachableProductionTile(tile)) return;
    {
        s32 x, y;
        SelectMapLayer((u8 *)*gCurrentMap + MAP_CELL_SCORE);
        FloodFillUnitRange(tile[0], tile[1], (u32)(M2C_FIELD((u8 *)table, u8 *, offset) << 26) >> 26, range, 0);
        if (gAiPriorityPredicate() == 1) {
            s32 score = gAiPriorityScore();
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
/* Request more foot units for reachable properties unless the existing move target is in range. */
s32 AiNeedsMoreFootUnitsInRange(void) {
    s32 CountUnusedCapturableProperties(void);
    s32 attackTargets, propertyScore, teamFootUnits;

    if (AiRangeReachesAssignedMoveTarget() == 1) return 0;
    attackTargets = CountAiAttackTargetUnits();
    if (attackTargets) {
        propertyScore = CountCapturableProperties();
    } else {
        propertyScore = CountUnusedCapturableProperties();
    }
    if (propertyScore == 0) return 0;
    teamFootUnits = CountActiveTeamFootUnits();
    if (attackTargets == 0) {
        if (teamFootUnits < propertyScore + AI_FOOT_UNIT_BUFFER_NO_TARGETS) return 1;
    } else {
        if (teamFootUnits < propertyScore + AI_FOOT_UNIT_BUFFER_WITH_TARGETS) return 1;
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
    extern s32 (*gAiPriorityPredicate)(void);
    extern s32 (*gAiPriorityScore)(void);
    gAiPriorityPredicate = AiNeedsMoreFootUnitsInRange;
    gAiPriorityScore = func_ov000_02188338;
    AiScoreProductionTiles();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) FinalizeAiProductionMove();
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

u8 AiNeedsMoreAttackUnits(void) {
    s32 AiRangeReachesAssignedMoveTarget();
    s32 temp_r0;
    u8 var_r0;

    if (AiRangeReachesAssignedMoveTarget() == 1) {
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

/* AI production priority for attack units, from the counts of enemy attack
 * targets and the team's attack-capable units: AI_SCORE_FLAG is set while the
 * two counts are within min(targets, 5) of each other, and the low bits are
 * |targets - teamAttackers| + 1, capped at AI_SCORE_MAX. */
s32 AiAttackUnitBalanceScore(void) {
    s32 teamAttackers;
    s32 targets;
    s32 magnitude;
    s32 imbalance;
    s32 flag;
    s32 clamp;

    targets = CountAiAttackTargetUnits();
    teamAttackers = CountTeamAttackUnits();
    if (targets > 5) {
        clamp = 5;
    } else {
        clamp = targets;
    }
    if (((s32) (targets - clamp) < teamAttackers) && ((s32) (targets + clamp) > teamAttackers)) {
        flag = AI_SCORE_FLAG;
    } else {
        flag = 0;
    }
    if (targets > teamAttackers) {
        imbalance = targets - teamAttackers;
    } else {
        imbalance = teamAttackers - targets;
    }
    magnitude = imbalance + 1;
    if (magnitude & AI_SCORE_FLAG) {
        magnitude = AI_SCORE_MAX;
    }
    return magnitude | flag;
}

/* Run the AI's attack-unit production priority, then the enemy-HQ one: install
 * the priority's predicate (attack units still needed) and score (attack-unit
 * balance), score the reachable production tiles, finalize the best move when
 * the pass improved a tile's score, and continue with the enemy-HQ priority. */
void AiPrioritiseAttackUnitProduction(void) {
    extern void *gAiCommandState;
    extern s32 (*gAiPriorityPredicate)(void);
    extern s32 (*gAiPriorityScore)(void);
    gAiPriorityPredicate = (s32 (*)(void))AiNeedsMoreAttackUnits;
    gAiPriorityScore = AiAttackUnitBalanceScore;
    AiScoreProductionTiles();
    if (M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_ACTION_FLAGS) & AI_ACTION_PRODUCTION_IMPROVED) FinalizeAiProductionMove();
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
    if (AiRangeReachesAssignedMoveTarget() == 1) return 0;
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
    extern s32 (*gAiPriorityPredicate)(void);
    extern s32 (*gAiPriorityScore)(void);
    gAiPriorityPredicate = AiRangeReachesEnemyHq;
    gAiPriorityScore = func_ov000_02188680;
    AiScoreProductionTiles();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) FinalizeAiProductionMove();
}

/* AI action check for unit AI state 2: flood-fill the acting unit's movement
 * range from (x, y), then run the objective check that rejects the action when
 * an enemy HQ lies inside it. */
void CanDoAiAction2(s32 x, s32 y) {
    s32 AiRangeReachesEnemyHq(void);
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 unitOffset;
    void *map, *unitRecords;
    map = *gCurrentMap;
    unitRecords = (u8 *)map + MAP_UNIT_RECORDS;
    unitOffset = M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED) * MAP_UNIT_STRIDE;
    FloodFillUnitRange(x, y, (u32)(M2C_FIELD(unitRecords, u8 *, unitOffset) << 26) >> 26, GetAiUnitSearchRange((u8 *)unitRecords + unitOffset), 0);

    AiRangeReachesEnemyHq();
}

u8 AiPropertiesOutnumberAttackUnits(void) {
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

s32 AiPropertyCaptureScore(void) {
    s32 CountCapturableProperties();
    s32 CountTeamAttackUnits();
    s32 temp_r4;

    temp_r4 = CountCapturableProperties();
    return temp_r4 - CountTeamAttackUnits();
}

/* AI action planner (unit AI states 3/4, and state 5 without an HQ): enter the
 * property-capture option by installing the "capturable properties outnumber
 * attack units" priority predicate and its score, search the production tiles
 * for a usable move and, when one is found, choose that move's destination; then
 * let the attack-unit planner add its own option too. */
void AiPrioritisePropertyCapture(void) {
    extern void *gAiCommandState;
    extern s32 (*gAiPriorityPredicate)(void);
    extern s32 (*gAiPriorityScore)(void);
    gAiPriorityPredicate = (s32 (*)(void))AiPropertiesOutnumberAttackUnits;
    gAiPriorityScore = AiPropertyCaptureScore;
    AiScoreProductionTiles();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) FinalizeAiProductionMove();
    AiPrioritiseAttackUnitProduction();
}

/* AI action kind 34: flood-fill the cursor unit's search range from (x, y), then
 * check whether the team's capturable properties outnumber its attack units. */
void CanDoAiAction34(s32 x, s32 y) {
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 unitOffset;
    void *map, *units;
    map = *gCurrentMap;
    units = (u8 *)map + MAP_UNIT_RECORDS;
    unitOffset = M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED) * MAP_UNIT_STRIDE;
    FloodFillUnitRange(x, y, (u32)(M2C_FIELD(units, u8 *, unitOffset) << 26) >> 26, GetAiUnitSearchRange((u8 *)units + unitOffset), 0);
    AiPropertiesOutnumberAttackUnits();
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
    if (AiRangeReachesAssignedMoveTarget() == 1) return 0;
    if (PlayerHasHq(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) == 0) return 0;
    base = *gCurrentMap;
    entry = (u8 *)base + MAP_PLAYER_STATES + M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE;
    if (M2C_FIELD(M2C_FIELD((u8 *)base + ((u32)(M2C_FIELD(entry, u8 *, PLAYER_REC_HQ_Y) << 25) >> 23), s8 **, MAP_GRID), s8 *, M2C_FIELD(entry, u8 *, PLAYER_REC_HQ_X) & 0x7F) > 0) result = 1;
    else result = 0;
    return result;
}

s32 AiReachPlayerHqScore(void) {
    return 1;
}

/* AI production priority for reaching the current player's HQ: installs the
 * reach-player-HQ predicate and its constant score, scores the reachable
 * production tiles, finalizes the best move when a tile's score improved, and
 * continues with the attack-unit priority. */
void AiPrioritiseReachPlayerHq(void) {
    extern void *gAiCommandState;
    extern s32 (*gAiPriorityPredicate)(void);
    extern s32 (*gAiPriorityScore)(void);
    gAiPriorityPredicate = (s32 (*)(void))AiRangeReachesPlayerHq;
    gAiPriorityScore = AiReachPlayerHqScore;
    AiScoreProductionTiles();
    if (M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_ACTION_FLAGS) & AI_ACTION_PRODUCTION_IMPROVED) FinalizeAiProductionMove();
    AiPrioritiseAttackUnitProduction();
}

/* Whether AI action 5 is possible from (x, y): flood-fill the cursor unit's search
 * range, using its own kind and range, then test that range against the player's HQ. */
void CanDoAiAction5(s32 x, s32 y) {
    s32 GetAiUnitSearchRange(void *);
    extern void **gCurrentMap;
    s32 offset;
    void *base, *table;

    base = *gCurrentMap;
    table = (u8 *)base + MAP_UNIT_RECORDS;
    offset = M2C_FIELD(M2C_FIELD(base, void **, MAP_CURSOR_UNIT), u8 *, 0xD) * MAP_UNIT_STRIDE;
    FloodFillUnitRange(x, y, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, GetAiUnitSearchRange((u8 *)table + offset), 0);
    AiRangeReachesPlayerHq();
}

#pragma opt_lifetimes off
u8 AiAssignedTargetInMovementRange(void) {
    extern void **gCurrentMap;
    u16 value;
    s8 *bank;
    void *base, *entry;
    u8 result;
    base = *gCurrentMap;
    entry = (u8 *)base + 0x59A4 + M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xC) * 14;
    if (AiRangeReachesAssignedMoveTarget() == 1) return 0;
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

/* AI action planner (unit AI states 7..9): install the "assigned move target is
 * in movement range" priority predicate and its constant score, search the
 * production tiles for a usable move and, when one is found, choose that move's
 * destination; then let the attack-unit planner add its own option too. */
void AiPrioritiseAssignedMoveTarget(void) {
    extern void *gAiCommandState;
    extern s32 (*gAiPriorityPredicate)(void);
    extern s32 (*gAiPriorityScore)(void);
    gAiPriorityPredicate = (s32 (*)(void))AiAssignedTargetInMovementRange;
    gAiPriorityScore = func_ov000_02188a30;
    AiScoreProductionTiles();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) FinalizeAiProductionMove();
    AiPrioritiseAttackUnitProduction();
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
