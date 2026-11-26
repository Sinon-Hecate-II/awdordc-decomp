/* 9 functions from 0x0219694C to 0x02197814 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct MapScan96 { u8 pad[0x24]; u16 width, height; } MapScan96;
typedef struct KindScan96 { u8 pad[12]; u8 minRange; u8 rest[99]; } KindScan96;
/* A unit record's combat fields: the low four bits of the word at +6 (= the
   `status` member, actually the ammo count) follow the health points. */
typedef struct UnitScan96 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 health:7; u16 status:4; u16 rest:5; } UnitScan96;

typedef struct Map972e0 { u8 pad[0x5144]; volatile u16 width; u16 height; } Map972e0;

#pragma opt_strength_reduction off
#pragma opt_strength_reduction off
u32 ScoreMapCellNear(s32 xOrig, s32 yOrig) {
    extern void **gCurrentMap;
    extern u8 gAiRangeBitmap[];
    s32 IsTerrainExcludedForPlayer(s32, s32);

    u32 result = 0;
    u8 hasFlag = 0;

    s32 yMax, xMin, yMin, xMax;
    s32 col, row;
    s32 dist, dy, dx;
    u16 rowOffset;
    s32 vIndex;
    s8 *rowPtr;
    s8 terrainVal;
    u8 prop;
    s32 funcRes;
    u32 linear;
    u16 rowOffsetOrig;
    u32 finalIdx;
    s8 *rowPtr0;
    s8 terrain0;

    xMin = xOrig - 2;
    xMin = xMin >= 0 ? xMin : 0;
    yMin = yOrig - 2;
    yMin = yMin >= 0 ? yMin : 0;
    xMax = M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) - 1;
    if (xOrig + 2 < xMax) xMax = xOrig + 2;
    yMax = M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT) - 1;
    if (yOrig + 2 < yMax) yMax = yOrig + 2;

    for (row = yMin; row <= yMax; row++) {
        col = xMin;
        if (col > xMax) continue;
        do {
            dx = xOrig - col;
            if (dx <= 0) dx = col - xOrig;
            dist = 0;
            dist += dx;
            dy = yOrig - row;
            if (dy > 0) dist += dy; else dist += row - yOrig;
            if (dist < 0 || dist > 2) goto next;

            rowOffset = M2C_FIELD((u8 *)*gCurrentMap + row * 2, u16 *, 0x3758);
            vIndex = rowOffset + col;
                    if ((u8)(M2C_FIELD(((u8 *)*gCurrentMap) + ((u32)vIndex >> 3), u8 *, MAP_CELL_BITMAP_TEAM_A) & (1 << (vIndex & 7)))) goto next;

            rowPtr = M2C_FIELD(((u8 *)*gCurrentMap) + row * 4, s8 **, 0x52e8);
            terrainVal = rowPtr[col];


            if (terrainVal != 0) {
                prop = M2C_FIELD((u8 *)*gCurrentMap + col + rowOffset, u8 *, 0x1420);
                if (prop & 0xe0) hasFlag = 1;
                funcRes = IsTerrainExcludedForPlayer((s32)(M2C_FIELD(((u8 *)*gCurrentMap), u16 *, 0x52a4) & 0xff), prop);
                if (funcRes != 0) result += 0x1000000; else result += 0x100000;
                linear = row * M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) + col;
                if ((u8)(gAiRangeBitmap[linear >> 3] & (1 << (linear & 7)))) result += 0x10000;
            } else {
                prop = M2C_FIELD((u8 *)*gCurrentMap + col + rowOffset, u8 *, 0x1420);
                if (prop & 0xe0) result += 0x100; else result += 0x10;
                linear = row * M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) + col;
                if ((u8)(gAiRangeBitmap[linear >> 3] & (1 << (linear & 7)))) result += 1;
            }
        next:
            col++;
        } while (col <= xMax);
    }

    if (!hasFlag) return 0;

    rowOffsetOrig = M2C_FIELD((u8 *)((u8 *)*gCurrentMap) + yOrig * 2, u16 *, 0x3758);
    finalIdx = xOrig + rowOffsetOrig;
    result <<= 2;
    if (!(u8)(M2C_FIELD(((u8 *)*gCurrentMap) + (finalIdx >> 3), u8 *, MAP_CELL_BITMAP_TEAM_A) & (1 << (finalIdx & 7)))) {
        funcRes = IsTerrainExcludedForPlayer((s32)(M2C_FIELD(((u8 *)*gCurrentMap), u16 *, 0x52a4) & 0xff), M2C_FIELD(((u8 *)*gCurrentMap) + finalIdx, u8 *, 0x1420));
        if (funcRes != 0) {
            rowPtr0 = M2C_FIELD((u8 *)*gCurrentMap + yOrig * 4, s8 **, 0x52e8);
            terrain0 = rowPtr0[xOrig];
            if (terrain0 != 0) result += 3; else result += 2;
        } else { result += 1; }
    }
    return result;
}
#pragma opt_strength_reduction reset

/* Mark the cells the current player's healthy indirect units can hit enemy
 * tanks (kind 7), and the enemy-owned airports they can hit, in the map grid.
 * Then aim the kind-5 unit under the cursor at the best-scored cell within
 * AI_FLARE_TARGET_RADIUS tiles of it: give that unit AI command 21 there. */
void TagAiKind5TargetCells(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern KindScan96 gUnitKindStats[];
extern u8 *gAiCommandState;
s32 func_ov000_02178e84(s32,s32);
void FillMapLayer(s32);
s32 GetUnitAttackClass(u32);
s32 GetUnitDamagePercent(s32,s32);
s32 GetUnitAttackRangeMax(void *);
u32 ScoreMapCellNear(s32,s32);
void SetMapCursor(s32,s32,s32,s32,s32);
u8 *map,*unit; MapScan96 *bounds; s32 bestX,bestY,unitId,unitOffset,minX,maxY,minX2,maxY2,minScanX,cellX,cellY,minY,maxX,distance,unused; u32 unusedScore,score;
map=*gCurrentMap; unit=M2C_FIELD(map,u8 **,MAP_CURSOR_UNIT);
if(!((UnitScan96 *)unit)->status)return;
if(!func_ov000_02178e84(unit[MAP_UNIT_X],unit[MAP_UNIT_Y]))return;
FillMapLayer(0);
unitId=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+1;
if(unitId<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+MAP_UNIT_GROUP_SCAN){unitOffset=unitId*MAP_UNIT_STRIDE;do{
unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+unitOffset;
if(!((u32)(unit[MAP_UNIT_KIND]<<26)>>26)||((UnitScan96 *)unit)->health<=AI_FLARE_UNIT_MIN_HEALTH||!((UnitScan96 *)unit)->status||(M2C_FIELD(unit,u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_LOADED)||GetUnitAttackClass((u32)(unit[MAP_UNIT_KIND]<<26)>>26)!=UNIT_ATTACK_INDIRECT)goto nextUnit;
if(GetUnitDamagePercent((u32)(unit[MAP_UNIT_KIND]<<26)>>26,UNIT_KIND_TANK)){
minX=unit[MAP_UNIT_X]-GetUnitAttackRangeMax(unit)<0?0:unit[MAP_UNIT_X]-GetUnitAttackRangeMax(unit);
minY=unit[MAP_UNIT_Y]-GetUnitAttackRangeMax(unit)<0?0:unit[MAP_UNIT_Y]-GetUnitAttackRangeMax(unit);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+MAP_NAME);maxX=unit[MAP_UNIT_X]+GetUnitAttackRangeMax(unit)>=bounds->width-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,MAP_WIDTH)-1:unit[MAP_UNIT_X]+GetUnitAttackRangeMax(unit);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+MAP_NAME);maxY=unit[MAP_UNIT_Y]+GetUnitAttackRangeMax(unit)>=bounds->height-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,MAP_HEIGHT)-1:unit[MAP_UNIT_Y]+GetUnitAttackRangeMax(unit);
unused=0;for(cellY=minY;cellY<=maxY;cellY++)for(cellX=minX;cellX<=maxX;cellX++){
distance=0; if(unit[MAP_UNIT_X]-cellX>0)distance+=unit[MAP_UNIT_X]-cellX;else distance+=cellX-unit[MAP_UNIT_X]; if(unit[MAP_UNIT_Y]-cellY>0)distance+=unit[MAP_UNIT_Y]-cellY;else distance+=cellY-unit[MAP_UNIT_Y];
if(distance<gUnitKindStats[(u32)(unit[MAP_UNIT_KIND]<<26)>>26].minRange||distance>GetUnitAttackRangeMax(unit))continue;
map=*gCurrentMap; score=M2C_FIELD((u32)map+(cellY<<1),u16 *,MAP_ROW_OFFSETS)+cellX;
if((u8)(map[MAP_CELL_BITMAP_TEAM_A+(score>>3)]&(1<<(score&7))))continue;

M2C_FIELD((u32)map+(cellY<<2),u8 **,MAP_GRID)[cellX]=1;
}}if(GetUnitDamagePercent((u32)(unit[MAP_UNIT_KIND]<<26)>>26,AI_COUNTER_UNIT_KIND)){
minX2=unit[MAP_UNIT_X]-GetUnitAttackRangeMax(unit)<0?0:unit[MAP_UNIT_X]-GetUnitAttackRangeMax(unit);
minY=unit[MAP_UNIT_Y]-GetUnitAttackRangeMax(unit)<0?0:unit[MAP_UNIT_Y]-GetUnitAttackRangeMax(unit);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+MAP_NAME);maxX=unit[MAP_UNIT_X]+GetUnitAttackRangeMax(unit)>=bounds->width-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,MAP_WIDTH)-1:unit[MAP_UNIT_X]+GetUnitAttackRangeMax(unit);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+MAP_NAME);maxY2=unit[MAP_UNIT_Y]+GetUnitAttackRangeMax(unit)>=bounds->height-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,MAP_HEIGHT)-1:unit[MAP_UNIT_Y]+GetUnitAttackRangeMax(unit);
unused=0;for(cellY=minY;cellY<=maxY2;cellY++)for(cellX=minX2;cellX<=maxX;cellX++){
distance=0; if(unit[MAP_UNIT_X]-cellX>0)distance+=unit[MAP_UNIT_X]-cellX;else distance+=cellX-unit[MAP_UNIT_X]; if(unit[MAP_UNIT_Y]-cellY>0)distance+=unit[MAP_UNIT_Y]-cellY;else distance+=cellY-unit[MAP_UNIT_Y];
if(distance<gUnitKindStats[(u32)(unit[MAP_UNIT_KIND]<<26)>>26].minRange||distance>GetUnitAttackRangeMax(unit))continue;
map=*gCurrentMap; score=M2C_FIELD((u32)map+(cellY<<1),u16 *,MAP_ROW_OFFSETS)+cellX;
if((u8)(map[MAP_CELL_BITMAP_TEAM_A+(score>>3)]&(1<<(score&7))))continue;
if((M2C_FIELD((u32)map+cellX+M2C_FIELD((u32)map+(cellY<<1),u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK)!=MAP_TERRAIN_AIRPORT||!(M2C_FIELD((u32)map+cellX+M2C_FIELD((u32)map+(cellY<<1),u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_OWNER_MASK))continue;
M2C_FIELD((u32)map+(cellY<<2),u8 **,MAP_GRID)[cellX]=1;
}}nextUnit: unitId++;unitOffset+=MAP_UNIT_STRIDE;}while(unitId<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+MAP_UNIT_GROUP_SCAN);}
{ s32 minScanX,minScanY,maxScanY; u32 scanBest; s32 scanX,scanY,maxScanX,scanDistance; u8 *scanUnit;
map=*gCurrentMap; scanUnit=M2C_FIELD(map,u8 **,MAP_CURSOR_UNIT);
scanBest=0;minScanX=scanUnit[MAP_UNIT_X]-AI_FLARE_TARGET_RADIUS<0?0:scanUnit[MAP_UNIT_X]-AI_FLARE_TARGET_RADIUS;minScanY=scanUnit[MAP_UNIT_Y]-AI_FLARE_TARGET_RADIUS;if(minScanY<0)minScanY=0;maxScanX=M2C_FIELD(map,u16 *,MAP_WIDTH)-1;if(scanUnit[MAP_UNIT_X]+AI_FLARE_TARGET_RADIUS<maxScanX)maxScanX=scanUnit[MAP_UNIT_X]+AI_FLARE_TARGET_RADIUS;maxScanY=M2C_FIELD(map,u16 *,MAP_HEIGHT)-1;if(scanUnit[MAP_UNIT_Y]+AI_FLARE_TARGET_RADIUS<maxScanY)maxScanY=scanUnit[MAP_UNIT_Y]+AI_FLARE_TARGET_RADIUS;
unused=0;for(scanY=minScanY;scanY<=maxScanY;scanY++)for(scanX=minScanX;scanX<=maxScanX;scanX++){scanUnit=M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT);scanDistance=0; if(scanUnit[MAP_UNIT_X]-scanX>0)scanDistance+=scanUnit[MAP_UNIT_X]-scanX;else scanDistance+=scanX-scanUnit[MAP_UNIT_X]; if(scanUnit[MAP_UNIT_Y]-scanY>0)scanDistance+=scanUnit[MAP_UNIT_Y]-scanY;else scanDistance+=scanY-scanUnit[MAP_UNIT_Y];if(scanDistance<0||scanDistance>AI_FLARE_TARGET_RADIUS)continue;score=ScoreMapCellNear(scanX,scanY);if(!score||scanBest>score)continue;if(scanBest==score&&gAiCommandState[AI_COMMAND_STATE_TIEBREAK]<AI_FLARE_TIEBREAK_CUTOFF)continue;scanBest=score;bestX=scanX;bestY=scanY;}
if(!scanBest)return;scanUnit=M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT);SetMapCursor(scanUnit[MAP_UNIT_X],scanUnit[MAP_UNIT_Y],21,(u8)bestX,(u8)bestY);
}}
#pragma opt_strength_reduction reset
/* Flood-fill the cursor unit's movement range, then plan a move: prefer the
 * reachable tile (0,4) when it is reachable, otherwise the lowest-cost tile of
 * the leftmost reachable column. */
void PlanAiUnitMove(void) {
    extern void **gCurrentMap;
    void FloodFillUnitRange(s32, s32, s32, s32, s32);
    void PlanMoveDestination(s32, s32);
    Map972e0 *base;
    u8 *unit;
    s32 x, y, bestX, bestY, best;

    base = *gCurrentMap;
    unit = M2C_FIELD(base, u8 **, MAP_CURSOR_UNIT);
    FloodFillUnitRange(unit[1], unit[2], (u32)(unit[0] << 26) >> 26, 110, 0);
    base = *gCurrentMap;
    if (M2C_FIELD(M2C_FIELD(base, void **, 0x52f8), s8 *, 0) >= 0) {
        PlanMoveDestination(0, 4);
        return;
    }
    bestX = -1; best = 32767;
    for (x = 0; x < base->width; x++) {
        for (y = 0; y < base->height; y++) {
            s32 v = *(s8 *)((u32)x + (u32)M2C_FIELD((void *)((u32)base + (u32)y * 4), s8 **, MAP_GRID));
            if (v >= 0 && v <= best) { best = v; bestX = x; bestY = y; }
        }
        if (bestX != -1) break;
    }
    if (bestX == -1) return;
    PlanMoveDestination(bestX, bestY);
}

/* Whether the map's current player is AI-controlled: nonzero when that player's
 * PLAYER_REC_AI_MODE byte is set.  (Callers pass a unit kind to it; the function
 * itself takes no argument.) */
u8 IsCurrentPlayerAiControlled(void) {
    extern void **gCurrentMap;
    void *map;
    u32 player;
    u8 result;

    map = *gCurrentMap;
    player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
    result = M2C_FIELD((s32) map + player * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0;
    return result;
}

/* Return the percent damage attacker kind `attackerKind` deals to defender kind
 * `defenderKind`, with the AI's extra matchup multipliers on top of the weapon
 * damage table: the counter unit kind (0xE) against itself (x1.5) and against
 * kind 6 (x2), and kind 15 against kind 6 (x0.5). */
s32 GetModifiedDamagePercent(s32 attackerKind, s32 defenderKind) {
    s32 GetUnitDamagePercent();
    s32 damage;

    damage = GetUnitDamagePercent();
    if ((defenderKind == 0xE) && (attackerKind == 0xE)) {
        damage = (s32) (damage * 3) >> 1;
    }
    if ((defenderKind == 0xE) && (attackerKind == 6)) {
        damage *= 2;
    }
    if ((defenderKind == 6) && (attackerKind == 0xF)) {
        damage = damage >> 1;
    }
    return damage;
}

/* Scale attack damage by (100 + the attacker's owner-group attack bonus) over
 * (100 + the defender's owner-group defense bonus); leave it unchanged when both
 * bonuses are zero. */
s32 ApplyAttackBonus(s32 damage, M2C_UNK defenderOwner, M2C_UNK attackerOwner) {
    s32 Divide(s32, s32);
    s32 GetOwnerGroupAttackBonus(M2C_UNK);
    s32 GetOwnerGroupDefenseBonus(M2C_UNK);
    s32 defenseBonus;
    s32 attackBonus;
    s32 result;

    result = damage;
    attackBonus = GetOwnerGroupAttackBonus(attackerOwner);
    defenseBonus = GetOwnerGroupDefenseBonus(defenderOwner);
    if ((attackBonus == 0) && (defenseBonus == 0)) {

    } else {
        result = Divide(result * (attackBonus + 0x64), defenseBonus + 0x64);
    }
    return result;
}

/* Scales a base value by percentage modifiers derived from up to two optional unit pointers; returns the base unchanged when neither modifier applies. */
s32 ApplyCoZoneBonus(s32 base, void *firstUnit, void *secondUnit) {
    s32 GetCoZoneAttackBonus(u32, s32, s32);
    s32 GetCoZoneDefenseBonus(u32, s32, s32);
    s32 GetPlayerArmyVariantIfSet(u16);
    s32 IsUnitSelected(void *);
    s32 Divide(s32, s32);
    extern void **gCurrentMap;
    s32 n, idx, a, b;
    if (secondUnit && IsUnitSelected(secondUnit)) {
        if (secondUnit) { if (!secondUnit) n = 0; else n = (s32)((u8 *)secondUnit - ((u8 *)*gCurrentMap + 0x59a4)) / 14; idx = (n >> 6) + 1; } else idx = 0;
        a = GetCoZoneAttackBonus((u32)(M2C_FIELD(secondUnit, u8 *, 0) << 26) >> 26, idx, 0);
    } else a = 0;
    if (firstUnit && (IsUnitSelected(firstUnit) || GetPlayerArmyVariantIfSet(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)))) {
        if (firstUnit) { if (!firstUnit) n = 0; else n = (s32)((u8 *)firstUnit - ((u8 *)*gCurrentMap + 0x59a4)) / 14; idx = (n >> 6) + 1; } else idx = 0;
        b = GetCoZoneDefenseBonus((u32)(M2C_FIELD(firstUnit, u8 *, 0) << 26) >> 26, idx, GetPlayerArmyVariantIfSet(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)));
    } else b = 0;
    if (a == 0 && b == 0) { } else base = Divide(base * (a + 100), b + 100);
    return base;
}

/* Scale `value` by a unit's health percentage `healthPercent`, with a bonus for
 * a unit standing on a property it can capture; the percentage is capped at 100
 * and the result at 255.  Returns the scaled value. */
s32 ApplyHealthBonus(s32 value, void *unit, s32 healthPercent) {
    s32 func_020a7558(void *);
    s32 IsCaptureTargetAt(void *, u8, u8);
    s32 func_ov000_021a93a8(void *, u8, u8);
    s32 result;
    s32 percent;

    percent = healthPercent;
    if (func_ov000_021a93a8(unit, M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y)) == 1) {
        percent += 0x14;
    }
    if (IsCaptureTargetAt(unit, M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y)) == 1) {
        percent += func_020a7558(unit) * 0xA;
    }
    if (percent >= 0x64) {
        percent = 0x64;
    }
    result = Divide(value * percent, 0x64);
    if (result >= 0xFF) {
        result = 0xFF;
    }
    return result;
}

/* Returns the terrain damage rating for tile (x, y); for most unit kinds it blends the unit's stats through ApplyCoZoneBonus and clamps to the existing tile rating. */
s32 GetTileDamageRating(s32 x, s32 y, void *unit, u32 hp) {
    s32 ApplyCoZoneBonus(s32, void *, void *);
    s32 GetModifiedDamagePercent(s32, s32);
    s32 ApplyAttackBonus(s32, M2C_UNK, M2C_UNK);
    s32 ApplyHealthBonus(s32, void *, s32);
    s32 GetUnitAttackClass(u32);
    extern void **gCurrentMap;
    extern u8 gAiInfluenceMap[];
    void *base;
    s32 v, result, old;
    if (GetUnitAttackClass((u32)(M2C_FIELD(unit, u8 *, 0) << 26) >> 26)) {
        base = *gCurrentMap;
        return M2C_FIELD((u8 *)base + (x + M2C_FIELD((u8 *)base + y * 2, u16 *, 0x3758)), u8 *, 0x2840);
    }
    v = GetModifiedDamagePercent((u32)(M2C_FIELD(unit, u8 *, 0) << 26) >> 26, (u32)(*M2C_FIELD(*gCurrentMap, u8 **, 0x52d0) << 26) >> 26);
    v = ApplyAttackBonus(v, (u32)(*M2C_FIELD(*gCurrentMap, u8 **, 0x52d0) << 24) >> 30, (u32)(M2C_FIELD(unit, u8 *, 0) << 24) >> 30);
    v = ApplyCoZoneBonus(v, M2C_FIELD(*gCurrentMap, void **, 0x52d0), unit);
    result = ApplyHealthBonus(v, unit, (u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25);
    base = *gCurrentMap;
    old = M2C_FIELD((u8 *)base + (x + M2C_FIELD((u8 *)base + y * 2, u16 *, 0x3758)), u8 *, 0x2840);
    if (result == old) {
        result = ApplyHealthBonus(v, unit, hp);
        old = gAiInfluenceMap[y * M2C_FIELD(*gCurrentMap, u16 *, 0x5144) + x];
        if (result <= old) result = old;
        return result;
    }
    return old;
}

