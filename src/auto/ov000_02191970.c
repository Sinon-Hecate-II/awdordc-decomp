/* 2 functions from 0x02191970 to 0x0219234C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gAiUnitLoadCounts[];
extern s8 gTerrainPropertyType[];
#define MAP (*gCurrentMap)
#define SEL M2C_FIELD(MAP,void**,0x52d0)
#define KIND(p) ((u32)(M2C_FIELD(p,u8*,0)<<26)>>26)
#define ROW(y) M2C_FIELD(MAP+(y)*2,u16*,0x3758)
#define CELL(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),s8*,off)
#define TILE(x,y) M2C_FIELD(MAP+(x)+ROW(y),u8*,0x1420)

#pragma optimization_level 4
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_strength_reduction off
void func_ov000_02191970(void){
void SelectMapLayer(void*);void FloodFillUnitRange(s32,s32,u32,s32,s32);
s32 GetAiUnitMoveRange(void*);s32 CanKindLoad(u32,u32);
s32 GetUnitMoveRange(u32,u32);s32 CanReachProperty(s32,s32,s32);
s32 func_ov000_0217bcd4(s32,s32,u32,s32);
s32 IsAllyUnitAtCell(s16,s16);s32 CanUnitKindStandAt(u32,s32,s32);
s32 IsPropertyCell(s32,s32);s32 IsTerrainOnUnitTeam(u32,u32);
void SetMapCursor(s16,s16,s32,s32,s32);void PlanMoveDestination(s32,s32);
s32 bestX=-1,bestY=-1,candidateX=-1,candidateY=-1;
s32 bestDistance=32767,chosen=0,special,index,offset,limit;
s32 distance,otherDistance,x,y,range,d,temporary;
void *unit;
if(M2C_FIELD(SEL,u8*,12))return;
SelectMapLayer(MAP+0x2338);
FloodFillUnitRange(M2C_FIELD(SEL,u8*,1),M2C_FIELD(SEL,u8*,2),KIND(SEL),110,1);
SelectMapLayer(MAP+0x1e30);
limit=GetAiUnitMoveRange(SEL)+1;
index=gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+1;
if(index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51){
offset=index*14;
for(;
index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51;index++,offset+=14){
unit=MAP+0x59a4+offset;
if(!KIND(unit)||!CanKindLoad(KIND(SEL),KIND(unit))||
gAiUnitLoadCounts[index&63]||((u32)(M2C_FIELD(unit,u8*,11)<<24)>>31))continue;
switch(KIND(SEL)){
case 13:if(((u32)(M2C_FIELD(unit,u16*,8)<<16)>>30)==1)break;continue;
case 19:if(((u32)(M2C_FIELD(unit,u16*,8)<<16)>>30)!=0)break;continue;
}
range=GetUnitMoveRange(M2C_FIELD(MAP,u16*,0x52a4),KIND(unit));
{ s32 ux=M2C_FIELD(unit,u8*,1); s32 row=ROW(M2C_FIELD(unit,u8*,2)); d=M2C_FIELD(MAP+ux+row,s8*,0x2338); } special=0;
temporary=limit+range;
if(d<temporary&&(CanReachProperty(M2C_FIELD(unit,u8*,1),M2C_FIELD(unit,u8*,2),range*2-1)==1||
func_ov000_0217bcd4(M2C_FIELD(unit,u8*,1),M2C_FIELD(unit,u8*,2),KIND(unit),range)==1)){special=1;d=temporary;}
if(d>bestDistance+range)continue;
FloodFillUnitRange(M2C_FIELD(unit,u8*,1),M2C_FIELD(unit,u8*,2),KIND(unit),range,1);
distance=32767;otherDistance=32767;
if(((u32)(M2C_FIELD(unit,u16*,8)<<26)>>26)!=63){
SelectMapLayer(MAP+0x3250);
FloodFillUnitRange(M2C_FIELD(SEL,u8*,1),M2C_FIELD(SEL,u8*,2),KIND(SEL),110,0);
SelectMapLayer(MAP+0x1e30);
if(CELL(M2C_FIELD(SEL,u8*,1),M2C_FIELD(SEL,u8*,2),0x3250)<0)continue;
}
for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(MAP+y*4,s8**,0x52e8),s8*,x)<0||
CELL(x,y,0x2338)<0||IsAllyUnitAtCell(x,y)!=0||
!CanUnitKindStandAt(KIND(SEL),x,y)||IsPropertyCell(x,y)==1)continue;
if(IsTerrainOnUnitTeam(M2C_FIELD(MAP,u8*,0x52d4),TILE(x,y))==1&&gTerrainPropertyType[TILE(x,y)&31]!=0)continue;
d=CELL(x,y,0x2338);
if(((u32)(M2C_FIELD(unit,u16*,8)<<26)>>26)!=63){
temporary=CELL(x,y,0x3250);if(temporary<0)temporary=32767;
if(d<limit&&distance<limit){if(otherDistance>=temporary)goto accept;continue;}
else {if(d<=distance)goto accept;continue;}
}else{temporary=32767;if(d>distance)continue;}
accept: distance=d;otherDistance=temporary;candidateX=x;candidateY=y;
}
}
if(distance!=32767){
bestX=candidateX;bestY=candidateY;chosen=index;
if(special==1){if(bestDistance>limit)bestDistance=limit;}
else bestDistance=CELL(candidateX,candidateY,0x2338);
}
}
}
if(bestX==-1)return;
gAiUnitLoadCounts[chosen&63]++;
if(bestDistance<limit)SetMapCursor(bestX,bestY,2,0,0);
else PlanMoveDestination(bestX,bestY);
}
#pragma opt_strength_reduction off
/* AI destination scan: mark every cell a two-tile infantry move can reach from one
 * of the current player's own kind-0x11 properties, flood the acting unit's whole
 * movement range and, among the reachable marked cells that pass the AI target
 * checks, pick the closest one and plan the move to it. */
void SelectAiPropertyDestination(void) {
    void SelectMapLayer(void *);
    void FillMapLayer(s32);
    void FloodFillUnitRange(s32, s32, u32, s32, s32);
    s32 IsAllyUnitAtCell(s16, s16);
    s32 func_ov000_02178e84(s16, s16);
    s32 func_ov000_02178778(s16, s16);
    void PlanMoveDestination(s32, s32);
    s32 best = 0x7fff, bestX = best - 0x8000, bestY = 0;
    s32 x, y, scanX, scanY, distance;
    s16 rowY;
    u8 terrain, unitId;
    void *map = MAP;
    if (M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_FIRST_CARRIED)) return;
    SelectMapLayer(map + MAP_CELL_SCORE);
    FillMapLayer(-1);
    SelectMapLayer(MAP + MAP_CELL_ORDER);
    map = MAP;
    for (y = bestY; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); ++y) {
        for (x = 0; x < M2C_FIELD(map, u16 *, MAP_WIDTH); ++x) {
            u8 *cell = (u8 *)map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            terrain = M2C_FIELD(cell, u8 *, MAP_CELL_TERRAIN);
            if ((terrain & MAP_TERRAIN_KIND_MASK) == 17 && M2C_FIELD(map, u16 *, MAP_CURRENT_OWNER) == (terrain & MAP_TERRAIN_OWNER_MASK)) {
                unitId = cell[0];
                if (!unitId || !(M2C_FIELD(map + unitId * MAP_UNIT_STRIDE, u16 *, 0x59a8) & 1)) {
                    FloodFillUnitRange(x, y, 1, 2, 1);
                    map = MAP;
                    for (scanY = 0; scanY < M2C_FIELD(map, u16 *, MAP_HEIGHT); ++scanY) {
                        for (scanX = 0; scanX < M2C_FIELD(map, u16 *, MAP_WIDTH); ++scanX) {
                            distance = M2C_FIELD(map + scanY * 4, s8 **, MAP_GRID)[scanX];
                            if (distance >= 0) {
                                u8 *target = (u8 *)map + scanX + M2C_FIELD(map + scanY * 2, u16 *, MAP_ROW_OFFSETS);
                                M2C_FIELD(target, s8 *, MAP_CELL_SCORE) = distance;
                            }
                            map = MAP;
                        }
                    }
                }
            }
        }
    }
    {
        void *unit = M2C_FIELD(map, void **, MAP_CURSOR_UNIT);
        FloodFillUnitRange(M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y), KIND(unit), 110, 1);
    }
    {
    s32 x, y;
    map = MAP;
    for (y = 0; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); ++y) {
        x = 0;
        if (x < M2C_FIELD(map, u16 *, MAP_WIDTH)) {
            rowY = (s16)y;
            do {
                if (M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] >= 0 &&
                    M2C_FIELD(map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS), s8 *, MAP_CELL_SCORE) >= 0 &&
                    !IsAllyUnitAtCell((s16)x, rowY) &&
                    func_ov000_02178e84((s16)x, rowY) &&
                    func_ov000_02178778((s16)x, rowY) != 1) {
                    distance = M2C_FIELD(MAP + y * 4, s8 **, MAP_GRID)[x];
                    if (distance <= best) {
                        bestX = x;
                        bestY = y;
                        best = distance;
                    }
                }
                map = MAP;
            } while (++x < M2C_FIELD(map, u16 *, MAP_WIDTH));
        }
    }
    }
    if (bestX == -1) return;
    PlanMoveDestination(bestX, bestY);
}
#pragma opt_strength_reduction reset
