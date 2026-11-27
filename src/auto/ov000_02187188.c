/* 9 functions from 0x02187188 to 0x02187F7C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
extern void (*gAiPriorityScore)(void);
void AiFootUnitBalanceScore(void);
extern void **gCurrentMap;
extern u32 gFrameCounter;

/* Score a tile as an AI move destination for a unit: -1 when off-map, held by
 * an ally or impassable; otherwise a packed score from the terrain move cost,
 * the indirect threat on the tile and a capture-target bonus. */
s32 MoveDestinationScore(s32 x, s32 y, u8 *unit) {
    extern void **gCurrentMap;
    extern u8 gMovementTypeTable[];
    extern s8 gTerrainPropertyType[];
    extern M2C_UNK gMovementCostTable;
    s32 IsAllyUnitAtCell(s16, s16);
    s32 IsTerrainOnUnitTeam(s32, s32);
    s32 GetTerrainDefenseFromStars(s32, s32, s32);
    s32 Divide(s32, s32);
    s32 IsCaptureTargetAt(void *, s32, s32);
    s32 func_ov000_021a93a8(void *, s32, s32);
    s32 score = 0;
    s32 indirectThreat;
    void *map;
    s32 terrain, unitKind;

    if (x < 0 || y < 0 || x >= M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) || y >= M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT)) {
        return -1;
    }
    if (IsAllyUnitAtCell((s16)x, (s16)y)) {
        return -1;
    }
    map = *gCurrentMap;
    unitKind = (u32)(unit[0] << 26) >> 26;
    terrain = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
    if (M2C_FIELD((s8 *)M2C_FIELD(&gMovementCostTable, void **, 0x64) + gMovementTypeTable[unitKind * 0x70] * 32, s8 *, terrain) < 0) {
        return -1;
    }
    indirectThreat = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_THREAT_INDIRECT);
    if (gTerrainPropertyType[terrain] == 0 || IsTerrainOnUnitTeam(M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID), M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN)) == 0) {
        map = *gCurrentMap;
        score += (Divide(GetTerrainDefenseFromStars(M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER), 1, terrain), 10) + 1) << 4;
    }
    score += (0x100 - indirectThreat) << 8;
    if (gTerrainPropertyType[terrain] == 0) {
        if (IsCaptureTargetAt(unit, x, y) == 1) {
            score += 0x10000;
        }
    }
    if (func_ov000_021a93a8(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), x, y) == 1) {
        score += 0x20000;
    }
    return score;
}

s32 func_ov000_02187320(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    s32 MoveDestinationScore(s32, s32, u8 *);
    long noResult = MAP_DESTINATION_NONE;
    s32 x = arg0;
    s32 y = arg1;
    s16 *out = arg2;
    s16 *out2 = arg3;
    s32 rowB;
    s32 offsetB;
    u8 *unitB;
    s32 minX;
    unsigned long offsetA;
    s32 maxY;
    u8 *unitA;
    s32 rowA;
    s32 dir;
    register s32 bestScore, tx, dy0, dy1, ty, maxX;
    void *base;
    s32 score;
    register s32 adx;
    s32 dist;

    dir = M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, 0xC);
    if (!dir) return 0;
    offsetA = dir * MAP_UNIT_STRIDE;
    unitA = (u8 *) *gCurrentMap + MAP_UNIT_RECORDS;
    minX = x - 1;
    bestScore = 0;
    *out = (s16) noResult;
    if (minX < 0) minX = 0;
    ty = y - 1;
    if (ty < 0) ty = 0;
    base = *gCurrentMap;
    maxX = M2C_FIELD(base, u16 *, MAP_WIDTH) - 1;
    if (x + 1 < maxX) maxX = x + 1;
    maxY = M2C_FIELD(base, u16 *, MAP_HEIGHT) - 1;
    if (y + 1 < maxY) maxY = y + 1;
    if (ty <= maxY) {
        do {
            tx = minX;
            if (tx <= maxX) {
                do {
                    dy0 = y - ty;
                    dy1 = ty - y;
                    rowA = ty;
                    adx = x - tx;
                    if (adx <= 0) adx = tx - x;
                    dist = 0;
                    dist = adx + dist;
                    if (dy0 > 0) dist = dist + dy0;
                    else dist = dist + dy1;
                    if (dist >= 1 && dist <= 1) {
                        score = MoveDestinationScore(tx, ty, unitA + offsetA);
                        if (score >= bestScore && (score != bestScore || !(gFrameCounter & 1))) {
                            bestScore = score;
                            out[0] = (s16) tx;
                            out[1] = (s16) rowA;
                        }
                    }
                    tx++;
                } while (tx <= maxX);
            }
            ty++;
        } while (ty <= (int)maxY);
    }
    if (out[0] == (s16) noResult) return 0;

    dir = M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, 0xD);
    if (dir == 0) return 1;
    offsetB = dir * MAP_UNIT_STRIDE;
    unitB = (u8 *) *gCurrentMap + MAP_UNIT_RECORDS;
    *out2 = (s16) noResult;
    minX = x - 1;
    bestScore = 0;
    if (minX < 0) minX = 0;
    ty = y - 1;
    if (0 > ty) ty = 0;
    base = *gCurrentMap;
    maxX = M2C_FIELD(base, u16 *, MAP_WIDTH) - 1;
    if (x + 1 < maxX) maxX = x + 1;
    maxY = M2C_FIELD(base, u16 *, MAP_HEIGHT) - 1;
    if (y + 1 < maxY) maxY = y + 1;
    if ((s32)ty <= maxY) {
        do {
            tx = minX;
            if (tx <= maxX) {
                do {
                    dy0 = y - ty;
                    dy1 = ty - y;
                    rowB = ty;
                    adx = x - tx;
                    if (0 >= adx) adx = tx - x;
                    dist = 0;
                    dist = adx + dist;
                    if (0 < dy0) dist = dist + dy0;
                    else dist = dist + dy1;
                    if (dist >= 1 && dist <= 1) {
                        if (tx != out[0] || ty != out[1]) {
                            score = MoveDestinationScore(tx, ty, unitB + offsetB);
                            if (score >= bestScore && (score != bestScore || !((s32)gFrameCounter & 1))) {
                                bestScore = score;
                                out2[0] = (s16) tx;
                                out2[1] = (s16) rowB;
                            }
                        }
                    }
                    ++tx;
                } while (maxX >= tx);
            }
            ty++;
        } while (maxY >= ty);
    }
    if (out2[0] == (s16) noResult) return 1;
    return 2;
}

#pragma push
#pragma optimize_for_size on
void func_ov000_02187664(s32 arg0, s32 arg1) {
    extern void **gCurrentMap;
    s32 func_ov000_02187320(s32, s32, void *, void *);
    s32 GetAiCargoDropDirection(s32, s32, s32, s32);
    s32 TryUnitAiActions(s32, s32);
    void SetMapCursor(s32, s32, s32, s32, s32);
    s32 IsFootUnitKind(u32);

    s16 pos1[2];
    s16 pos2[2];
    s32 t;
    u8 *unitC;
    u8 *unitD;

    s32 r = func_ov000_02187320(arg0, arg1, pos1, pos2);
    if (r == 0) return;
    t = GetAiCargoDropDirection(arg0, arg1, pos1[0], pos1[1]);
    if (r >= 2) {
    if (TryUnitAiActions(arg0, arg1) == 1) {
        r = GetAiCargoDropDirection(arg0, arg1, pos2[0], pos2[1]);
        SetMapCursor((s16)arg0, (s16)arg1, 8, (u8)t, (u8)r);
    } else {
    unitC = (u8 *)*gCurrentMap + 0x59A4 + M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xC) * 0xE;
    if (!IsFootUnitKind((u32)(unitC[0] << 26) >> 26) && ((u32)(unitC[0] << 26) >> 26) != 0x0D && ((u32)(unitC[11] << 28) >> 28) < 6) {
    unitD = (u8 *)*gCurrentMap + 0x59A4 + M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xD) * 0xE;
    if (!IsFootUnitKind((u32)(unitD[0] << 26) >> 26) && ((u32)(unitD[0] << 26) >> 26) != 0x0D && ((u32)(unitD[11] << 28) >> 28) < 6) {
    unitD[11] = (unitD[11] & 0xF0) | ((u32)(unitC[11] << 28) >> 28);
    SetMapCursor((s16)arg0, (s16)arg1, 8, t & 0xff, 0);
    }
    }
    }
    }
}
#pragma pop
#pragma push
#pragma optimize_for_size on
#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Choose the AI's move destination for the unit under the cursor: build the
 * unit's move range, then scan the reachable cells for the one with the highest
 * range value (a transport that can unload gets a bonus) and the lowest threat,
 * breaking ties by the frame counter, and move the cursor there. */
void SelectBestMoveCell(void) {
    extern void **gCurrentMap;
    extern u32 gFrameCounter;
    s32 IsAllyUnitAtCell(s16, s16);
    s32 CountAdjacentAccessibleCells(s32, s32);
    void BuildUnitMoveRange(void *);
    void *map;
    void *unit;
    s32 bestX = -1;
    s32 bestY = -1;
    s32 bestVal = 0;
    s32 bestSub = 0x7fff;
    s32 y;
    s32 x;
    s32 score;
    s32 threat;
    s32 adjacent;

    BuildUnitMoveRange(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT));
    map = *gCurrentMap;
    y = bestVal;
    if (y < M2C_FIELD(map, u16 *, MAP_HEIGHT)) do {
        x = 0;
        if (x < M2C_FIELD(map, u16 *, MAP_WIDTH)) do {
            if (M2C_FIELD(M2C_FIELD(map + y * 4, s8 **, MAP_GRID), s8 *, x) < 0) {
                continue;
            }
            if (IsAllyUnitAtCell((s16)x, (s16)y) != 0) {
                continue;
            }
            map = *gCurrentMap;
            if (M2C_FIELD(map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), s8 *, 0x3250) == 0) {
                continue;
            }
            adjacent = CountAdjacentAccessibleCells(x, y);
            if (adjacent == 0) {
                continue;
            }
            map = *gCurrentMap;
            unit = M2C_FIELD(map, void **, MAP_CURSOR_UNIT);
            score = M2C_FIELD(map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), u8 *, 0x3250);
            if (M2C_FIELD(unit, u8 *, 0xD) != 0 && adjacent >= 2) {
                score |= 0x100;
            }
            if (bestVal > score) {
                continue;
            }
            {
                u8 *cell = (u8 *)map + x;
                threat = M2C_FIELD(cell + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), u8 *, MAP_CELL_THREAT_DIRECT)
                  + M2C_FIELD(cell + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), u8 *, MAP_CELL_THREAT_INDIRECT) * 2;
            }
            if (bestVal == score && bestSub < threat) {
                continue;
            }
            if (bestVal == score && bestSub == threat && (gFrameCounter & 1) != 0) {
                continue;
            }
            bestX = x;
            bestY = y;
            bestVal = score;
            bestSub = threat;
        } while (map = *gCurrentMap, ++x < M2C_FIELD(map, u16 *, MAP_WIDTH));
    } while (++y < M2C_FIELD(map, u16 *, MAP_HEIGHT));
    if (bestVal == 0) {
        return;
    }
    func_ov000_02187664(bestX, bestY);
}
#pragma pop

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Pick where the AI's current unit should move: scan every reachable cell and
   take the lowest-cost one, preferring cells whose property flag bit 0x80 is
   set, then hand the choice to PlanMoveDestination. */
void ChooseMoveDestination(void){
 extern u8 *gAiCommandState;
 s32 FloodFillUnitRange();
 s32 CountAdjacentAccessibleCells(s32,s32);
 s32 Divide(s32,s32);
 s32 Modulo(s32,s32);
 void PlanMoveDestination(s32,s32);
 u8 *unit;
 s32 bestX,bestY,bestCost,bestFlag,y,x,flag,cost,mask;
 void *mapBase;
 bestX=-1;bestY=-1;bestCost=32767;bestFlag=0;
 unit=M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT);
 FloodFillUnitRange(unit[1],unit[2],(u32)(unit[0]<<26)>>26,110,1);
 mapBase=*gCurrentMap;
 for(y=0;y<M2C_FIELD(mapBase,u16 *,MAP_HEIGHT);y++){
 for(x=0;x<M2C_FIELD(mapBase,u16 *,MAP_WIDTH);x++,mapBase=*gCurrentMap){
 s32 cellCost=M2C_FIELD(mapBase+y*4,s8 **,MAP_GRID)[x];
 if(cellCost<0 || cellCost<=gAiCommandState[5])continue;
 if(M2C_FIELD(mapBase+x+M2C_FIELD(mapBase+y*2,u16 *,MAP_ROW_OFFSETS),s8 *,0x3250)==0)continue;
 if(!CountAdjacentAccessibleCells(x,y))continue;
 cost=Divide(M2C_FIELD(*gCurrentMap+y*4,s8 **,MAP_GRID)[x],gAiCommandState[5])+1;
 if(Modulo(M2C_FIELD(*gCurrentMap+y*4,s8 **,MAP_GRID)[x],gAiCommandState[5])==0)--cost;
 mapBase=*gCurrentMap;
 flag=M2C_FIELD(mapBase+x+M2C_FIELD(mapBase+y*2,u16 *,MAP_ROW_OFFSETS),u8 *,0x3250);
 if(bestCost<cost){
 if(bestFlag&128)continue;
 if(!(flag&128))continue;
 if(bestCost+1<cost)continue;
 }
 mask=bestFlag&128;
 if(!mask && (flag&128)){
 if(bestCost+1>=cost)goto accept;
 continue;
 }
 else if(mask && !(flag&128)){
 if(bestCost-1>cost)goto accept;
 continue;
 }
 {
 if(bestCost<cost)continue;
 if(bestCost==cost && bestFlag>flag)continue;
 }
 accept: bestX=x;bestY=y;bestCost=cost;bestFlag=flag;
 }
 }
 if(bestX==-1)return;
 PlanMoveDestination(bestX,bestY);
}
#pragma pop
void func_ov000_02187c3c(void) {
    extern void **gCurrentMap;
    extern u8 *gAiCommandState;
    s32 FloodFillUnitRange(s32, s32, s32, s32, s32, s32);
    s32 CountAdjacentAccessibleCells(s32, s32);
    s32 Divide(s32, s32);
    s32 Modulo(s32, s32);
    void PlanMoveDestination(s32, s32);

    s32 bestX = -1;
    s32 bestY = -1;
    s32 bestSub = 0x7fff;
    s32 bestVal = 0;
    s32 y, x, score;

    FloodFillUnitRange(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0x1),
                  M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0x2),
                  ((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0x0) << 26) >> 26),
                  0x6e, 1, -1);

    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
            s32 val;
            if (M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x] < 0) continue;
            if (M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x] <= gAiCommandState[5]) continue;
            if (M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), s8 *, 0x3250) == 0) continue;
            if (CountAdjacentAccessibleCells(x, y) == 0) continue;
            val = Divide(M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x], gAiCommandState[5]) + 1;
            if (Modulo(M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x], gAiCommandState[5]) == 0) val--;
            if (bestSub < val) continue;
            score = M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x3250);
            if (bestSub != val) goto update;
            if (bestVal > score) continue;
        update:
            bestX = x;
            bestY = y;
            bestSub = val;
            bestVal = score;
        }
    }
    if (bestVal == 0) return;
    PlanMoveDestination(bestX, bestY);
}
#pragma opt_strength_reduction reset
/* Finish planning the AI's next move: pick the best cell for the unit under the
 * cursor, choose its destination for the foot-unit priority, then run the
 * production move chooser. */
void FinalizeAiProductionMove(void) {
SelectBestMoveCell();
if(gAiPriorityScore==AiFootUnitBalanceScore) ChooseMoveDestination();
func_ov000_02187c3c();
}

#pragma optimization_level 2
u8 AiRangeReachesAssignedMoveTarget(void) {
void *base=*gCurrentMap;
void *unit=M2C_FIELD(base,void **,0x52d0);
u32 v=M2C_FIELD(unit,u16 *,8);
s32 shift=v<<26; u32 x=(u32)shift>>26;
u32 y; u8 result;
if(x==63) return 0;
y=(u32)(v<<20)>>26;
if(((s8 **)((u8 *)base+0x52e8))[y][x]>=0) result=1; else result=0;
return result;
}
#pragma optimization_level reset
u8 IsUnitProductionTerrain(s32);
#pragma opt_strength_reduction off
/* Find the first map cell that can produce units and is reachable (its MAP_GRID
 * value is not negative).  Writes the cell's x and y to `tile` and returns 1, or
 * returns 0 when no such cell exists. */
s32 FindReachableProductionTile(s16 *tile) {
    extern void **gCurrentMap;
    u8 *map = *gCurrentMap;
    s32 x;
    s32 y;

    for (y = 0; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(map, u16 *, MAP_WIDTH); x++) {
            if (M2C_FIELD(map + (y << 2), s8 **, MAP_GRID)[x] >= 0 &&
                IsUnitProductionTerrain(M2C_FIELD(M2C_FIELD(map + (y << 1), u16 *, MAP_ROW_OFFSETS) + (map + x), u8 *, MAP_CELL_TERRAIN))) {
                tile[0] = x;
                tile[1] = y;
                return 1;
            }
            map = *gCurrentMap;
        }
    }
    return 0;
}
#pragma opt_strength_reduction reset
