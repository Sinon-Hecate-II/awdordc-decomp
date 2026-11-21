/* 4 functions from 0x0218BBD0 to 0x0218CBC0 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

typedef struct { u8 kind:6; u8 flags:2; u8 pad[5]; u16 health:7; u16 flags2:4; u16 value:5; u8 bytes8[3]; u8 state:4; u8 stateFlags:4; u8 tail[2]; } Unit0218C4;

#pragma opt_if-conversion reset
#pragma opt_instruction_scheduling reset
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma opt_peephole reset
#pragma opt_strength_reduction off
#pragma opt_if-conversion off
int SelectIndirectAttackAction(void *arg0) {
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern u8 *gAiUnitTypeTuning;
    void BuildUnitMoveRange(void *);
    void MarkAdjacentCells(int);
    s32 IsUnitSelected(void *);
    s32 GetUnitAttackRangeMax(void *);
    u8 *func_020a47e0(s32, s32);
    s32 MapOrder_IsEnemyOwned(void);
    s32 GetUnitMaxWeaponDamagePercent(void *, s32);
    s32 Divide(s32, s32);
    s32 func_ov000_02178268(s32, s32, s16 *);
    s32 func_020d1690(s32, s32, s16 *);
    s32 IsFootUnitKind(s32);
    s32 func_ov000_021a9c90(s32, s32);
    s32 func_ov000_02178e84(s32, s32);
    s32 IsCellVisibleToCurrentTeam(s16, s16);
    s32 GetKindAttackClass(s32);
    s32 CanAttackUnitFrom(s32, s32, void *);
    s32 func_ov000_02176e28(s32, s16 *);
    void ClearUnitMoveTarget(void);
    void SetMapCursor(s32, s32, s32, s32, s32);
    s16 position[2];
    s32 bestScore = 0, bestId = 0;
    s32 bestHealth = 0xff;
    s32 terrainFlags = 0, flags = 0;
    volatile s32 maxX, maxY; s32 minX, minY;
    extern s8 gTerrainPropertyType[];
    extern u8 gUnitKindFlags[], gUnitKindStats[];
    s32 savedX, savedY;
    u8 *unit;
    u8 *other;
    s32 i, y, x, health, kind, damage, score, bonus;

    if (IsUnitSelected(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)) != 0) flags |= 0x400000;
    if (((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->state != 6) {
        if (IsTerrainOnUnitTeam(M2C_FIELD(*gCurrentMap,u8 *,0x52d4), M2C_FIELD((u8 *)*gCurrentMap + (M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] + M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] * 2, u16 *, 0x3758)), u8 *, 0x1420)) == 1 && (M2C_FIELD((u8 *)*gCurrentMap + (M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] + M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] * 2, u16 *, 0x3758)), u8 *, 0x1420) & 31) == 17 && ((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->health > 80)
            terrainFlags |= 0x40000;
        else if ((IsTerrainOnUnitTeam(M2C_FIELD(*gCurrentMap,u8 *,0x52d4), M2C_FIELD((u8 *)*gCurrentMap + (M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] + M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] * 2, u16 *, 0x3758)), u8 *, 0x1420)) == 1 && gTerrainPropertyType[M2C_FIELD((u8 *)*gCurrentMap + (M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] + M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] * 2, u16 *, 0x3758)), u8 *, 0x1420) & 31] != 0) ||
            ((gUnitKindFlags[((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->kind * 112] & 7) && ((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->health <= 70 && IsPropertyAllowedForKind(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->kind, M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1], M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2]) == 0))
            terrainFlags |= 0x10000;
    }
    position[0] = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1]; position[1] = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2];
    minX = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] - GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)) < 0 ? 0 : M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] - GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
    minY = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] - GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)) < 0 ? 0 : M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] - GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
    if (M2C_FIELD((u8 *)*gCurrentMap + 0x5120,u16 *,0x24)-1 <= M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] + GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))) maxX = M2C_FIELD((u8 *)*gCurrentMap + 0x5120,u16 *,0x24)-1; else maxX = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] + GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
    if (M2C_FIELD((u8 *)*gCurrentMap + 0x5120,u16 *,0x26)-1 <= M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] + GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))) maxY = M2C_FIELD((u8 *)*gCurrentMap + 0x5120,u16 *,0x26)-1; else maxY = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] + GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
    for (y=minY; y<=maxY; y++) {
        for (x=minX; x<=maxX; x++) {
            s32 dx = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1] - x, dy;
            if (dx <= 0) dx = x - M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1];
            i = dx;
            dy = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2] - y;
            if (dx <= 0) dx = x - M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1];
            if (dy <= 0) dy = y - M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2];
            if (i+dy < gUnitKindStats[((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->kind*112+12] || i+dy > GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))) continue;
            unit = func_020a47e0(x, y);
            if (unit != 0 && MapOrder_IsEnemyOwned() != 0) {
                health = unit[4];
                kind = ((u32)M2C_FIELD(unit, u16 *, 2) << 0x16) >> 0x1c;
            } else if ((((u32)M2C_FIELD(gAiCommandState, u8 *, 7) << 0x1d) >> 0x1f) != 0) {
                kind = 1;
                health = M2C_FIELD((u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x539c) & 0x7f;
                if (health == 0) goto c20;
                if (M2C_FIELD((u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0) != 0) goto c20;
            } else {
                goto c20;
            }

            damage = Divide(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->health * GetUnitMaxWeaponDamagePercent(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), kind), 100);
            if (damage < health && damage < 10) continue;
            func_020d1690(M2C_FIELD(*gCurrentMap, u8 *, 0x52d4), kind, position);
            if (M2C_FIELD(*gCurrentMap, s16 *, 0x6ed6) == 0) continue;
            if (damage >= bestHealth) {
                if (damage < health) continue;
                if (bestHealth > health) continue;
            } else {
                if (bestHealth < health) continue;
            }

            if (M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD((u8 *)*gCurrentMap, u16 *, 0x52a4) * 0x8c + 0x67ce, u8 *, 0) == 3) {
                if (damage < health) {
                    {
                        u8 *tile = (u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758);
                        if (!(M2C_FIELD(tile, u8 *, 0x2840) < gAiUnitTypeTuning[1] && M2C_FIELD(tile, u8 *, 0x2d48) < gAiUnitTypeTuning[2])) continue;
                    }
                }
            }
            if (func_ov000_02178e84(position[0], position[1]) == 0) continue;
            bestHealth = health;
            savedX = (s16)x;
            savedY = (s16)y;
            continue;

        c20:
            {
                u8 *base = (u8 *)*gCurrentMap + 0x59a4;
                u8 *tile = (u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758);
                s32 id = tile[0];
                other = base + id * 14;
                if (((Unit0218C4 *)other)->kind == 0) continue;
                if (func_020d27a4(M2C_FIELD(*gCurrentMap, u8 *, 0x52d4), other ? (s32)((other - base) / 14) : 0) == 1) continue;
                if (IsCellVisibleToCurrentTeam((s16)x, (s16)y) == 0) continue;
                    {
                    score = func_ov000_02176e28(flags | (terrainFlags | ((u8 *)*gCurrentMap)[other[1] + M2C_FIELD((u8 *)*gCurrentMap + other[2] * 2, u16 *, 0x3758)]), position);
                    if (score == 0) continue;
                    if (score < bestScore) continue;
                    bestScore = score;
                    bestId = ((u8 *)*gCurrentMap)[x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758)];
                }
            }
        }
    }

    if (bestScore != 0) {
        if (arg0 != 0) return 1;
        ClearUnitMoveTarget();
        SetMapCursor(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1], M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2], 4, (u8)bestId, 0);
    }
    if (bestHealth != 0xff) {
        if (arg0 != 0) return 1;
        ClearUnitMoveTarget();
        SetMapCursor(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[1], M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[2], 5, (u8)savedY, (u8)savedX);
    }
    return 0;
}
#pragma opt_if-conversion reset
s32 SelectMovingIndirectAttackAction(s32 arg0) {
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern u8 *gAiUnitTypeTuning;
    void BuildUnitMoveRange(void *);
    void MarkAdjacentCells(int);
    s32 IsUnitSelected(void *);
    s32 GetUnitAttackRangeMax(void *);
    u8 *func_020a47e0(s32, s32);
    s32 MapOrder_IsEnemyOwned(void);
    s32 GetUnitMaxWeaponDamagePercent(void *, s32);
    s32 Divide(s32, s32);
    s32 func_ov000_02178268(s32, s32, s16 *);
    s32 func_020d1690(s32, s32, s16 *);
    s32 IsFootUnitKind(s32);
    s32 func_ov000_021a9c90(s32, s32);
    s32 func_ov000_02178e84(s32, s32);
    s32 IsCellVisibleToCurrentTeam(s16, s16);
    s32 GetKindAttackClass(s32);
    s32 CanAttackUnitFrom(s32, s32, void *);
    s32 func_ov000_02176e28(s32, s16 *);
    void ClearUnitMoveTarget(void);
    void SetMapCursor(s32, s32, s32, s32, s32);
    s16 position[2];
    s32 bestX = -1, bestY = -1, bestScore = 0, bestId = 0, bestX2 = -1, bestY2 = -1;
    s32 flags = 0;
    s32 savedX, savedY;
    s32 bestHealth = 0xff;
    u8 *unit;
    u8 *other;
    s32 i, x, y, kind, health, damage, score, bonus;

    if (IsUnitSelected(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)) != 0) flags |= 0x400000;
    BuildUnitMoveRange(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
    for (i = 0; i < GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)); i++)
        MarkAdjacentCells((s8)(i + 0x6f));

    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
            if (M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52e8)[x] < 0) continue;
            unit = func_020a47e0(x, y);
            if (unit != 0 && MapOrder_IsEnemyOwned() != 0) {
                health = unit[4];
                kind = ((u32)M2C_FIELD(unit, u16 *, 2) << 0x16) >> 0x1c;
            } else if ((((u32)M2C_FIELD(gAiCommandState, u8 *, 7) << 0x1d) >> 0x1f) != 0) {
                kind = 1;
                health = M2C_FIELD((u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x539c) & 0x7f;
                if (health == 0) goto c20;
                if (M2C_FIELD((u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0) != 0) goto c20;
            } else {
                goto c20;
            }

            damage = Divide(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->health * GetUnitMaxWeaponDamagePercent(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), kind), 100);
            if (damage < health && damage < 10) continue;
            if (func_ov000_02178268(x, y, position) == 0) continue;
            func_020d1690(M2C_FIELD(*gCurrentMap, u8 *, 0x52d4), kind, position);
            if (M2C_FIELD(*gCurrentMap, s16 *, 0x6ed6) == 0) continue;
            if (damage >= bestHealth) {
                if (damage < health) continue;
                if (bestHealth > health) continue;
            } else {
                if (bestHealth < health) continue;
            }

            if (M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD((u8 *)*gCurrentMap, u16 *, 0x52a4) * 0x8c + 0x67ce, u8 *, 0) == 3) {
                if (damage < health) {
                    if (IsFootUnitKind(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->kind) == 0) {
                        u8 *tile = (u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758);
                        if (!(M2C_FIELD(tile, u8 *, 0x2840) < gAiUnitTypeTuning[1] && M2C_FIELD(tile, u8 *, 0x2d48) < gAiUnitTypeTuning[2])) continue;
                    }
                }
            }
            if (M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD((u8 *)*gCurrentMap, u16 *, 0x52a4) * 0x8c + 0x67ce, u8 *, 0) == 2) {
                if (func_ov000_021a9c90(bestX, bestY) >= 2) {
                    if (IsFootUnitKind(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->kind) == 0) {
                        u8 *tile = (u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758);
                        if (M2C_FIELD(tile, u8 *, 0x2d48) >= gAiUnitTypeTuning[2]) continue;
                    }
                }
            }
            if (func_ov000_02178e84(position[0], position[1]) == 0) continue;
            bestHealth = health;
            bestX2 = position[0];
            bestY2 = position[1];
            savedX = (s16)x;
            savedY = (s16)y;
            continue;

        c20:
            {
                u8 *base = (u8 *)*gCurrentMap + 0x59a4;
                u8 *tile = (u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758);
                s32 id = tile[0];
                other = base + id * 14;
                if (((Unit0218C4 *)other)->kind == 0) continue;
                if (func_020d27a4(M2C_FIELD(*gCurrentMap, u8 *, 0x52d4), other ? (s32)((other - base) / 14) : 0) == 1) continue;
                if (IsCellVisibleToCurrentTeam((s16)x, (s16)y) == 0) continue;
                if (func_ov000_02178268(x, y, position) == 0) continue;
                {
                    u32 v2 = M2C_FIELD((u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758), u8 *, 0x2d48);
                    u32 d2 = gAiUnitTypeTuning[2];
                    bonus = 0;
                    if (v2 >= d2) goto bonus_chk;
                    {
                        u32 v1 = M2C_FIELD((u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758), u8 *, 0x2840);
                        u32 d1 = gAiUnitTypeTuning[1];
                        if (v1 < d1) goto score;
                    }
                bonus_chk:
                    if (other[0xc] == 0 && GetKindAttackClass(((Unit0218C4 *)other)->kind) == 2 && CanAttackUnitFrom(position[0], position[1], other) == 0)
                        bonus = 0x80000;
                score:
                    score = func_ov000_02176e28(flags | (bonus | ((u8 *)*gCurrentMap)[x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758)]), position);
                    if (score == 0) continue;
                    if (score < bestScore) continue;
                    bestScore = score;
                    bestX = position[0];
                    bestY = position[1];
                    bestId = ((u8 *)*gCurrentMap)[x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758)];
                }
            }
        }
    }

    if (bestScore != 0) {
        if (arg0 != 0) return 1;
        ClearUnitMoveTarget();
        SetMapCursor((s16)bestX, (s16)bestY, 4, (u8)bestId, 0);
    }
    if (bestHealth != 0xff) {
        if (arg0 != 0) return 1;
        ClearUnitMoveTarget();
        SetMapCursor((s16)bestX2, (s16)bestY2, 5, (u8)savedY, (u8)savedX);
    }
    return 0;
}
#pragma opt_strength_reduction reset
/* Perform the attack the AI unit under the cursor picked: a direct unit fires at an
 * adjacent target, an indirect one moves to a firing tile when it can or fires from
 * where it stands (argument 0 = really act, not just check). */
void RunAiAttackAction(void) {
extern void **gCurrentMap;
switch(GetUnitAttackClass((u32)(*M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT)<<26)>>26)){
case UNIT_ATTACK_DIRECT: SelectDirectAttackAction(0); return;
case UNIT_ATTACK_INDIRECT: if(IsMobileIndirectUnitKind((u32)(*M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT)<<26)>>26))SelectMovingIndirectAttackAction(0);else SelectIndirectAttackAction(0);return;
}}

/* Whether the AI unit under the cursor has an attack action it can take: a
 * direct-combat action, or for an indirect unit the moving or static fire
 * action.  The selectors are asked to check only (argument 1 = dry run). */
s32 AiUnitHasAttackTarget(void) {
extern void **gCurrentMap;
u32 kind=(u32)(*M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT)<<26)>>26;
if(kind==6)return 0;
switch(GetUnitAttackClass(kind)){
case UNIT_ATTACK_DIRECT: return SelectDirectAttackAction(1);
case UNIT_ATTACK_INDIRECT: if(IsMobileIndirectUnitKind((u32)(*M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT)<<26)>>26))return SelectMovingIndirectAttackAction(1);else return SelectIndirectAttackAction(1);
default:return 0;
}}

