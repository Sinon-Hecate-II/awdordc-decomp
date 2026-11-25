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
    extern void **data_027e0058;
    extern u32 gFrameCounter;
    s32 sp2C;
    s32 sp28;
    void *sp24;
    s32 sp20;
    s32 sp1C;
    void *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *sp4;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r1_2;
    s32 temp_r1_3;
    s32 temp_r1_5;
    s32 temp_r1_6;
    s32 temp_r5;
    s32 temp_r6;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r8;
    s32 var_r8_2;
    u8 temp_r1;
    u8 temp_r1_4;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r3;
    void *temp_r4;

    sp0 = arg1;
    temp_r4 = *data_027e0058;
    sp4 = arg3;
    temp_r1 = M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x52D0), u8 *, 0xC);
    if (temp_r1 == 0) {
        return 0;
    }
    sp1C = temp_r1 * 0xE;
    sp18 = temp_r4 + 0x59A4;
    temp_r0 = arg0 - 1;
    sp14 = temp_r0;
    var_r4 = 0;
    M2C_FIELD(arg2, s16 *, 0) = 0x270F;
    if (temp_r0 < 0) {
        sp14 = 0;
    }
    var_r7 = sp0 - 1;
    temp_r1_2 = arg0 + 1;
    if (var_r7 < 0) {
        var_r7 = 0;
    }
    temp_r2 = *data_027e0058;
    var_r8 = M2C_FIELD(temp_r2, u16 *, 0x5144) - 1;
    if (temp_r1_2 < var_r8) {
        var_r8 = temp_r1_2;
    }
    temp_r1_3 = sp0 + 1;
    temp_r0_2 = M2C_FIELD(temp_r2, u16 *, 0x5146) - 1;
    sp10 = temp_r0_2;
    if (temp_r1_3 < temp_r0_2) {
        sp10 = temp_r1_3;
    }
    if (var_r7 <= sp10) {
        do {
            var_r5 = sp14;
            if (var_r5 <= var_r8) {
                temp_r6 = sp0 - var_r7;
                sp20 = (s32) (s16) var_r7;
                do {
                    var_r1 = arg0 - var_r5;
                    if (var_r1 <= 0) {
                        var_r1 = var_r5 - arg0;
                    }
                    if (temp_r6 > 0) {
                        var_r0 = var_r1 + temp_r6;
                    } else {
                        var_r0 = var_r1 + (var_r7 - sp0);
                    }
                    if ((var_r0 >= 1) && (var_r0 <= 1)) {
                        temp_r0_3 = MoveDestinationScore((s32) var_r5, (s32) var_r7, (u8 *)(sp18 + sp1C));
                        if ((temp_r0_3 >= var_r4) && ((temp_r0_3 != var_r4) || !(gFrameCounter & 1))) {
                            var_r4 = temp_r0_3;
                            M2C_FIELD(arg2, s16 *, 0) = (s16) var_r5;
                            M2C_FIELD(arg2, s16 *, 2) = (s16) sp20;
                        }
                    }
                    var_r5 += 1;
                } while (var_r5 <= var_r8);
            }
            var_r7 += 1;
        } while (var_r7 <= sp10);
    }
    if (M2C_FIELD(arg2, s16 *, 0) == 0x270F) {
        return 0;
    }
    temp_r3 = *data_027e0058;
    temp_r1_4 = M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0xD);
    if (temp_r1_4 == 0) {
        return 1;
    }
    sp28 = temp_r1_4 * 0xE;
    M2C_FIELD(sp4, s16 *, 0) = 0x270F;
    sp24 = temp_r3 + 0x59A4;
    temp_r0_4 = arg0 - 1;
    spC = temp_r0_4;
    var_r6 = 0;
    if (temp_r0_4 < 0) {
        spC = 0;
    }
    var_r7_2 = sp0 - 1;
    temp_r1_5 = arg0 + 1;
    if (var_r7_2 < 0) {
        var_r7_2 = 0;
    }
    temp_r2_2 = *data_027e0058;
    var_r8_2 = M2C_FIELD(temp_r2_2, u16 *, 0x5144) - 1;
    if (temp_r1_5 < var_r8_2) {
        var_r8_2 = temp_r1_5;
    }
    temp_r1_6 = sp0 + 1;
    temp_r0_5 = M2C_FIELD(temp_r2_2, u16 *, 0x5146) - 1;
    sp8 = temp_r0_5;
    if (temp_r1_6 < temp_r0_5) {
        sp8 = temp_r1_6;
    }
    if (var_r7_2 <= sp8) {
        do {
            var_r4_2 = spC;
            if (var_r4_2 <= var_r8_2) {
                temp_r5 = sp0 - var_r7_2;
                sp2C = (s32) (s16) var_r7_2;
                do {
                    var_r1_2 = arg0 - var_r4_2;
                    if (var_r1_2 <= 0) {
                        var_r1_2 = var_r4_2 - arg0;
                    }
                    if (temp_r5 > 0) {
                        var_r0_2 = var_r1_2 + temp_r5;
                    } else {
                        var_r0_2 = var_r1_2 + (var_r7_2 - sp0);
                    }
                    if ((var_r0_2 >= 1) && (var_r0_2 <= 1)) {
                        if ((var_r4_2 == M2C_FIELD(arg2, s16 *, 0)) && (var_r7_2 == M2C_FIELD(arg2, s16 *, 2))) {
                        } else {
                            temp_r0_6 = MoveDestinationScore((s32) var_r4_2, (s32) var_r7_2, (u8 *)(sp24 + sp28));
                            if ((temp_r0_6 >= var_r6) && ((temp_r0_6 != var_r6) || !(gFrameCounter & 1))) {
                                var_r6 = temp_r0_6;
                                M2C_FIELD(sp4, s16 *, 0) = (s16) var_r4_2;
                                M2C_FIELD(sp4, s16 *, 2) = (s16) sp2C;
                            }
                        }
                    }
                    var_r4_2 += 1;
                } while (var_r4_2 <= var_r8_2);
            }
            var_r7_2 += 1;
        } while (var_r7_2 <= sp8);
    }
    if (M2C_FIELD(sp4, s16 *, 0) == 0x270F) {
        return 1;
    }
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
