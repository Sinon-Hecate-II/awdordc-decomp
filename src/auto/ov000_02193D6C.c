/* 3 functions from 0x02193D6C to 0x02194AB8 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
#include "ov000_unit_entry.h"
typedef struct { u16 x:6; u16 y:6; u16 unk:2; u16 state:2; } Position_02194090;
#include "ov000_unit_entry.h"
extern void **gCurrentMap;
extern void *gAiCommandState;
extern u16 gPlayerUnitIdBase[];
extern M2C_UNK gUnitKindStats;
#define MAP (*gCurrentMap)
#define SEL M2C_FIELD(MAP,u8**,0x52d0)
#define KIND(p) ((u32)((p)[0]<<26)>>26)
#define INFO ((u8*)&gUnitKindStats)
#define ROW(y) M2C_FIELD(MAP+(y)*2,u16*,0x3758)
#define CELL(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),u8*,off)
#define COST(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),s8*,off)
#define PATH(x,y) M2C_FIELD(MAP+(y)*4,s8**,0x52e8)[x]

#pragma opt_strength_reduction off
/* AI destination scan for the Rig (kind 13): pick a plain or shoal cell to build
 * a temporary airfield (plain) or temporary port (shoal) on, preferring the cell
 * farthest from the AI's other builders and properties that is least exposed to
 * enemy threat, then move the AI's cursor there. */
void SelectAiRigBuildDestination(s32 force) {
    s32 GetCaptureTurnsLeft(void *);
    s32 IsAllyUnitAtCell(s16, s16);
    u8 IsPlainOrShoalTerrain(s32, s32);
    s32 func_ov000_02193a40(s32, s32, s32);
    UnkStruct_ov000_021A860C *unit = (UnkStruct_ov000_021A860C *)SEL;
    s32 bestX, bestY, bestScore, bestCost;
    s32 score, cost, x, y;
    s16 rowY;
    void *map;
    if (unit->unk0 != UNIT_KIND_RIG) return;
    if (!((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO) << 21) >> 28)) return;
    if (unit->unkC[0]) return;                     /* the Rig must carry nothing to build */
    if (!CanSaveHiddenTerrainMap()) return;
    if (!force && GetCaptureTurnsLeft(SEL) >= 5) return;
    unit = (UnkStruct_ov000_021A860C *)SEL;
    if ((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) << 16) >> 27)
        SetMapCursor(unit->unk1[0], unit->unk1[1], 24, 0, 0);
    BuildUnitMoveRange(SEL);
    bestY = 9999;
    bestX = bestY;
    bestScore = -1;
    bestCost = 0x7fff;
    map = MAP;
    for (y = 0; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); ++y) {
        x = 0;
        if (x < M2C_FIELD(map, u16 *, MAP_WIDTH)) {
            rowY = (s16)y;
            do {
                if (M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] >= 0 &&
                    !IsAllyUnitAtCell((s16)x, rowY) && IsPlainOrShoalTerrain(x, y)) {
                    u8 terrain = CELL(x, y, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
                    /* The terrain predicate above admits only plain and shoal. */
                    switch (terrain) {
                    case MAP_TERRAIN_PLAIN:
                        if (!(((u32)(M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_MODE) << 26) >> 29) & 2)) break;
                        score = func_ov000_02193a40(x, y, 1);
                        goto choose;
                    case MAP_TERRAIN_SHOAL:
                        if (!(((u32)(M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_MODE) << 26) >> 29) & 4)) break;
                        score = func_ov000_02193a40(x, y, 0);
                    default:
                    choose:
                        if (!force && score <= 5) break;
                        if (bestScore <= score) {
                            u8 *cell;
                            map = MAP;
                            cell = (u8 *)map + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
                            cost = M2C_FIELD(cell, u8 *, MAP_CELL_THREAT_DIRECT) + M2C_FIELD(cell, u8 *, MAP_CELL_THREAT_INDIRECT);
                            if (bestScore == score) {
                                if (bestCost < cost) break;
                                if (bestCost == cost && M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_TIEBREAK) < 50) break;
                            }
                            bestX = x;
                            bestY = y;
                            bestScore = score;
                            bestCost = cost;
                        }
                        break;
                    }
                }
                map = MAP;
            } while (++x < M2C_FIELD(map, u16 *, MAP_WIDTH));
        }
    }
    if (bestScore == -1) return;
    ClearUnitMoveTarget();
    SetMapCursor((s16)bestX, (s16)bestY, 24, 0, 0);
}
#pragma opt_strength_reduction reset
/* Scan reachable cells for a current-player unit that can attack the highlighted unit and move the cursor to it. */
void SelectAttackingUnit(void) {
#pragma opt_strength_reduction off
 u8 *unit;
 s32 foundX=-1, foundY=-1, foundKind=0, cellX,cellY;
 u8 *map;
 BuildUnitMoveRange(SEL);
 for(cellY=0;cellY<M2C_FIELD(MAP,u16*,0x5146);cellY++){
  for(cellX=0;cellX<M2C_FIELD(MAP,u16*,0x5144);cellX++){
   map=MAP;
   if((*(s8 **)(map+0x52e8+cellY*4))[cellX]<0)continue;
   if(!map[cellX+*(u16*)(map+0x3758+cellY*2)])continue;
   if(!IsCurrentPlayerUnit(map[cellX+*(u16*)(map+0x3758+cellY*2)+0x508]))continue;
   map=MAP;
   unit=map+0x59a4+14*(s16)map[cellX+*(u16*)(map+0x3758+cellY*2)];
   if(!(INFO[((UnkStruct_ov000_021A860C*)unit)->unk0*0x70+0x13]&0x20))continue;
   if(IsMidActionStep(((UnkStruct_ov000_021A860C*)unit)->unkB))continue;
   if(!CanUnitAttackKind(unit,((UnkStruct_ov000_021A860C*)SEL)->unk0))continue;
   if(foundKind!=0 && foundKind!=24){
    if(foundKind!=25)continue;
    if(((UnkStruct_ov000_021A860C*)unit)->unk0==24)continue;
   }
   foundX=cellX;foundY=cellY;foundKind=((UnkStruct_ov000_021A860C*)unit)->unk0;
  }
 }
 if(foundX==-1)return;
 ((Position_02194090 *)(SEL+8))->state=0;
 if(((UnkStruct_ov000_021A860C*)SEL)->unkB==2 || ((UnkStruct_ov000_021A860C*)SEL)->unkB==5){
  ((UnkStruct_ov000_021A860C*)SEL)->unkB=0;
  ((Position_02194090 *)(SEL+8))->x=63;
  ((Position_02194090 *)(SEL+8))->y=63;
 }
 map=MAP;
 unit=map+0x59a4+14*map[foundX+*(u16*)(map+0x3758+foundY*2)];
 ((Position_02194090 *)(unit+8))->x=(u16)foundX;
 ((Position_02194090 *)(unit+8))->y=(u16)foundY;
 ClearUnitMoveTarget();
 SetMapCursor((s16)foundX,(s16)foundY,7,0,0);
}

#pragma push
#pragma opt_strength_reduction off
void PlanProductionSiteDestination(void){
s32 IsPlayerHuman(s32);s32 GetUnitAttackClass(u32);
s32 HasAiOptionalUnitBuildFlag(void);s32 CountPlayerUnitsOfKind(s32);s32 CanKindCarryKind(u32,u32);
s32 func_ov000_0217d86c(void);void SelectAttackingUnit(void);
void SelectMapLayer(void*);void FloodFillUnitRange(s32,s32,s32,s32,s32);void FillMapLayer(s32);
s32 IsMidActionStep(u32);s32 CanUnitAttackKind(u8*,u32);
s32 IsUnitProductionTerrain(u32);s32 IsCellOwnedByUnitPlayer(s16,s16,s16);
void PlanMoveDestination(s32,s32);
s32 bestX=-1,bestY=-1,best=32767,index,offset,found,distance;
u32 mode;u8 *unit;
if(!(((u32)(M2C_FIELD(gAiCommandState,u16*,10)<<26)>>29)&4))return;
if(!IsPlayerHuman(M2C_FIELD(MAP,u16*,0x52a4))&&GetUnitAttackClass(KIND(SEL))==1){
if(KIND(SEL)!=26)return;
}
if(!HasAiOptionalUnitBuildFlag()&&!CountPlayerUnitsOfKind(24)&&!CountPlayerUnitsOfKind(25))return;
if((u32)(SEL[11]<<24)>>31)return;
if(((u32)(M2C_FIELD(SEL,u16*,6)<<25)>>25)<61)return;
if(!CanKindCarryKind(24,KIND(SEL)))return;
if(func_ov000_0217d86c()==1)return;
SelectAttackingUnit();
mode=(u8)(GetUnitAttackClass(KIND(SEL))==2);
M2C_FIELD(SEL,u16*,8)=(M2C_FIELD(SEL,u16*,8)&~0xc000)|0x8000;
if(!mode){
SelectMapLayer(MAP+0x3250);
FloodFillUnitRange(SEL[1],SEL[2],KIND(SEL),110,0);
SelectMapLayer(MAP+0x1e30);
}
SelectMapLayer(MAP+0x2338);FillMapLayer(127);SelectMapLayer(MAP+0x1e30);
found=0;
index=gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+1;
if(index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51){
offset=index*14;
do {
unit=(u8*)(MAP+0x59a4)+offset;
if(!KIND(unit)||!(INFO[KIND(unit)*112+19]&32)||IsMidActionStep((u32)(unit[11]<<28)>>28)||!CanUnitAttackKind(unit,KIND(SEL)))goto nextUnit;
if(unit[12]){
if(mode==1)goto nextUnit;
if(COST(unit[1],unit[2],0x3250)<0)goto nextUnit;
}
FloodFillUnitRange(unit[1],unit[2],KIND(unit),110,0);
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||!IsUnitProductionTerrain(CELL(x,y,0x1420)))continue;
{void *base=MAP;u16 row=M2C_FIELD(base+y*2,u16*,0x3758);u8 *cell=(u8*)base+x+row;
distance=M2C_FIELD(base+y*4,s8**,0x52e8)[x];
if(distance>=M2C_FIELD(cell,s8*,0x2338))continue;
if(!mode){ if(M2C_FIELD(cell,s8*,0x3250)<0)continue; }
M2C_FIELD(cell+0x2000,s8*,0x338)=distance;found=1;}
}}
nextUnit:
index++;
offset+=14;
} while(index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51);
}
FloodFillUnitRange(SEL[1],SEL[2],KIND(SEL),110,0);
if(!found){
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||(CELL(x,y,0x1420)&31)!=19||
!IsCellOwnedByUnitPlayer(M2C_FIELD(MAP,s16*,0x52a8),x,y))continue;
distance=PATH(x,y);if(best>=distance){bestX=x;bestY=y;best=distance;}
}}
if(bestX==-1)return;PlanMoveDestination(bestX,bestY);return;
}
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||!IsUnitProductionTerrain(CELL(x,y,0x1420)))continue;
{s32 cost=COST(x,y,0x2338);if(cost==127)continue;
distance=PATH(x,y);distance+=cost;}if(best>=distance){bestX=x;bestY=y;best=distance;}
}}
if(bestX==-1)return;PlanMoveDestination(bestX,bestY);
}
#pragma pop
