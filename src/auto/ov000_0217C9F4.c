/* 7 functions from 0x0217C9F4 to 0x0217D86C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
extern void **gCurrentMap;
static inline s32 UnitIndexC9f4(void *p) { s32 n; if(p)n=((u8 *)p-((u8 *)*gCurrentMap+0x59a4))/14;else n=0;return n; }
static inline s32 UnitOwnerC9f4(void *p) { if(p)return (UnitIndexC9f4(p)>>6)+1;return 0; }
typedef struct {
unsigned char kind:6, flags0:2;
u8 x,y,pad3[5];
unsigned short targetX:6,targetY:6,field12:2,mode:2;
u8 pad10;
unsigned char field11:5, active:1,field11hi:2;
u8 pad12[2];
} Unit0217d428;
static inline s32 DistanceC9f4(Unit0217d428 *p,s32 x,s32 y) {s32 d=0,t; t=p->x-x;if(t<=0)t=x-p->x;d+=t;t=p->y-y;if(t<=0)t=y-p->y;return d+t;}
typedef struct { u8 pad[3];u8 count;u8 pad4[2]; } Record0217d428;
static inline void SetTarget0217d428(Unit0217d428 *unit,u16 x,u16 y) {
unit->targetX=x;unit->targetY=y;
}

#pragma opt_strength_reduction off
s32 CountThreateningEnemies(Unit0217d428 *unit) {
s32 GetUnitAttackClass(u32);
s32 func_ov000_0217c4c8(void *);
s32 GetUnitMoveRange(s32,u32);
s32 UnitKindMasksOverlap(void *,void *);
s32 IsUnitOnCurrentTeam(s32);
extern u8 gUnitKindStats[],gUnitKindFlags[];
s32 count=0,maxY,minY,maxX,minX,x,y,dx,dy; u32 dist;
u8 *map,*record,*units; s32 id; void *dimensions;
if(GetUnitAttackClass(unit->kind)==1)return func_ov000_0217c4c8(unit);
if(GetUnitAttackClass(unit->kind)!=0)return count;
if(unit->kind==25 && ((u32)(M2C_FIELD(unit,u16*,6)<<21)>>28)==0)return count;
minX=unit->x-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
if(minX<0)minX=0;
else minX=unit->x-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
minY=unit->y-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
if(minY<0)minY=0;
else minY=unit->y-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
dimensions=(u8 *)*gCurrentMap+0x5120;
if(unit->x+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind)>=M2C_FIELD(dimensions,u16*,0x24)-1)
maxX=M2C_FIELD(*gCurrentMap,u16*,0x5144)-1;
else maxX=unit->x+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
dimensions=(u8 *)*gCurrentMap+0x5120;
if(unit->y+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind)>=M2C_FIELD(dimensions,u16*,0x26)-1)
maxY=M2C_FIELD(*gCurrentMap,u16*,0x5146)-1;
else maxY=unit->y+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
for(y=minY;y<=maxY;y++){
for(x=minX;x<=maxX;x++){
dx=unit->x-x;if(dx<=0)dx=x-unit->x;
dist=0;
dist=dx+dist;
dy=unit->y-y;if(dy<=0)dy=y-unit->y;
dist+=(u32)dy;
if(dist<0x80000000U){ if((s32)dist>GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind))continue;
map=*gCurrentMap;
id=map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
if(id && IsUnitOnCurrentTeam(id)){
map=*gCurrentMap;
units=map+0x59a4;
id=map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
record=units+id*14;
if(UnitKindMasksOverlap(record,unit)){
count++;
if(gUnitKindStats[((Unit0217d428 *)record)->kind*112+19]&16)count++;
}
}
}
}
}
if(UnitKindMasksOverlap(M2C_FIELD(*gCurrentMap,void**,0x52d0),unit)==1){
count++;
if(gUnitKindFlags[((Unit0217d428 *)M2C_FIELD(*gCurrentMap,void**,0x52d0))->kind*112]&16)count++;
}
return count;
}
#pragma opt_propagation on
#pragma opt_strength_reduction on
int func_ov000_0217d000(int unitKind, int terrain) {
    switch (terrain & 0x1F) {
    case 0x11:
        switch (unitKind) {
        case 0:
            goto unavailable;
        case 4: case 6: case 7: case 9: case 10: case 11:
        case 15: case 17: case 18: case 20: case 21: case 26:
            return 1;
        }
        break;
    case 0x12:
        switch (unitKind) {
        default:
        case 0:
            goto terrain13;
        case 6: case 12: case 14: case 16: case 17: case 21:
            return 1;
        }
        /* fall through */
    case 0x13:
terrain13:
        switch (unitKind) {
        case 15: case 17: case 18: case 20: case 21: case 22: case 23:
            return 1;
        }
        break;
    }
unavailable:
    return 0;
}

#pragma opt_strength_reduction off
/* Build the selected unit's attack-range overlay around tile (x,y) and scan the map:
   return 1 if the covered cells contain a healthy, direct-attacking friendly unit (not the
   selected one) that can damage the target unit, 0 otherwise. Restores the order layer. */
s32 CanAttackUnitFrom(s32 x,s32 y,u8 *target){
extern void **gCurrentMap;
extern void *gAiCommandState;
extern u8 *gAiUnitTypeTuning;
void SelectMapLayer(void *);
void FloodFillUnitRange(s32,s32,u32,s32,s32);
u8 *candidate;
s32 row,col,map,unitIndex;
u8 *unitsBase;
s32 rowOffset;
u32 threshold;
SelectMapLayer((u8 *)*gCurrentMap+MAP_CELL_SCORE);
FloodFillUnitRange(x,y,((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT),u8 *,0)<<26)>>26),M2C_FIELD(gAiCommandState,u8 *,5),0);
map=(s32)*gCurrentMap;
row=0;
if(row<M2C_FIELD(map,u16 *,MAP_HEIGHT))do {
col=0;
if(col<M2C_FIELD(map,u16 *,MAP_WIDTH))do {
if(M2C_FIELD(M2C_FIELD(map+row*4,s8 **,MAP_GRID),s8 *,col)<0)goto next;
unitsBase=(u8 *)map+MAP_UNIT_RECORDS;
rowOffset=M2C_FIELD(map+row*2,u16 *,MAP_ROW_OFFSETS);
candidate=unitsBase+M2C_FIELD(rowOffset,u8 *,map+col)*14;
if(!((u32)(candidate[0]<<26)>>26)||candidate==M2C_FIELD(map,u8 **,MAP_CURSOR_UNIT))goto next;
unitIndex=candidate ? (candidate-unitsBase)/14:0;
if(!AreUnitIdsOnSameTeam(M2C_FIELD(map,u8 *,MAP_CURSOR_UNIT_ID),unitIndex))goto next;
if(!GetUnitDamagePercent((u32)(candidate[0]<<26)>>26,(u32)(target[0]<<26)>>26))goto next;
if(GetKindAttackClass((u32)(candidate[0]<<26)>>26))goto next;
if(IsFootUnitKind((u32)(candidate[0]<<26)>>26))goto next;
if(((u32)(candidate[0]<<26)>>26)==4)goto next;
if(((u32)(M2C_FIELD(candidate,u16 *,6)<<25)>>25)<60)goto next;
if(M2C_FIELD(candidate,u16 *,4)&1){
map=(s32)*gCurrentMap;
threshold=gAiUnitTypeTuning[2];
rowOffset=M2C_FIELD(map+row*2,u16 *,MAP_ROW_OFFSETS);
if(M2C_FIELD(rowOffset+(map+col),u8 *,0x2d48)<threshold)goto next;
}
SelectMapLayer((u8 *)*gCurrentMap+MAP_CELL_ORDER);
return 1;
next:
map=(s32)*gCurrentMap;
col++;
}while(col<M2C_FIELD(map,u16 *,MAP_WIDTH));
row++;
}while(row<M2C_FIELD(map,u16 *,MAP_HEIGHT));
SelectMapLayer((u8 *)map+MAP_CELL_ORDER);
return 0;
}
#pragma opt_strength_reduction on
/* Capture-order follow-up from SetMapCursor: when the order is a capture, the
 * cursor unit is healthy and the capture will finish this turn, mark the unit
 * as having its AI move target assigned so the AI keeps it on the property. */
void MarkCaptureUnitHasTarget(s32 command) {
    s32 WillFinishCaptureThisTurn(void *);
    extern void **gCurrentMap;
    void *unit;

    if (command != 3) return;
    unit = M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    if (((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 25) >> 25) < MAP_UNIT_HEALTH_HEALTHY) return;
    if (WillFinishCaptureThisTurn(unit) != 1) return;
    unit = M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    if (((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == 0) {
        M2C_FIELD(unit, u8 *, MAP_UNIT_AI_STATE) |= MAP_UNIT_AI_HAS_TARGET;
    }
}

#pragma push
#pragma opt_strength_reduction off
/* AI: for each active unit of the current player, finds the reachable tile with
 * the lowest influence value, records how many units target it and sets the unit's
 * move target; clears the unit's active flag when the target is within its budget. */
void AssignUnitMoveTargets(void) {
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];
s32 IsFootUnitKind(u32);s32 func_ov000_02179b08(void *);void FloodFillUnitRange(s32,s32,u32,s32,s32);
s32 IsPropertyCell(s32,s32);s32 GetAiUnitMoveRange(void *);
s32 unitId,unitOffset,bestX,bestY,bestScore,x,y,value,tileId;Unit0217d428 *unit;u8 *rec;void *p;
unitId=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16*,0x52a4)]+1;
if(unitId>=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16*,0x52a4)]+51)return;
unitOffset=unitId*14;do{
unit=(Unit0217d428*)((u8*)*gCurrentMap+0x59a4+unitOffset);
if(unit->kind==0)goto nextUnit;
if(!IsFootUnitKind(unit->kind))goto nextUnit;
if(unit->active==0)goto nextUnit;
value=func_ov000_02179b08(unit);
FloodFillUnitRange(unit->x,unit->y,unit->kind,value,0);
bestY=-1;bestX=-1;bestScore=32767;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
p=*gCurrentMap;
if(M2C_FIELD((u8*)p+y*4,s8 **,0x52e8)[x]<0)continue;
if(!IsPropertyCell(x,y))continue;
p=*gCurrentMap;tileId=M2C_FIELD((u8*)p+x+M2C_FIELD((u8*)p+y*2,u16*,0x3758),s8*,0x1928);
if(M2C_FIELD((u8*)p+tileId*6,u8*,0x6c63)!=0)continue;
value=M2C_FIELD((u8*)p+y*4,s8 **,0x52e8)[x];
if(bestScore>=value){bestX=x;bestY=y;bestScore=value;}
}}
if(bestScore==32767)goto nextUnit;
p=*gCurrentMap;tileId=M2C_FIELD((u8*)p+bestX+M2C_FIELD((u8*)p+bestY*2,u16*,0x3758),s8*,0x1928);
((Record0217d428*)((u8*)p+0x6c60))[tileId].count++;
SetTarget0217d428(unit,bestX,bestY);
if(bestScore<=GetAiUnitMoveRange(unit))unit->active=0;
else unit->mode=1;
nextUnit: unitId++;unitOffset+=14;
}while(unitId<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16*,0x52a4)]+51);
}
#pragma opt_strength_reduction off
/* AI action: releases the move targets assigned to the current player's active
 * foot units, decrementing the use count of each targeted property cell. */
void ReleaseUnitMoveTargets(void) {
    extern u16 gPlayerUnitIdBase[];
    s32 IsFootUnitKind(u32);

    register u16 *groupBaseTable = gPlayerUnitIdBase;

    void **mapSlot;
    void *map;
    register s32 unitIndex;
    u16 groupBase;
    register BattleMapUnitHead *unit;
    register s32 unitOffset;
    u8 *property;

    mapSlot = gCurrentMap;
    map = *mapSlot;
    groupBase = groupBaseTable[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
    unitIndex = (s32)groupBase + 1;
    if (unitIndex >= (s32)groupBase + MAP_UNIT_GROUP_SCAN) return;

    unitOffset = unitIndex * MAP_UNIT_STRIDE;

    for (;;) {
        mapSlot = gCurrentMap;
        map = *mapSlot;
        unit = (BattleMapUnitHead *)((u8 *)map + MAP_UNIT_RECORDS + unitOffset);

        if (!unit->kind || !IsFootUnitKind(unit->kind) || !unit->unkB5) goto loopinc;

        {
            u32 targetX = unit->targetX;
            if (targetX != MAP_UNIT_TARGET_NONE) {
                u32 targetY = unit->targetY;
                u16 row = *(u16 *)((u8 *)*gCurrentMap + targetY * 2 + MAP_ROW_OFFSETS);
                s8 cellIndex = *(s8 *)((u8 *)*gCurrentMap + targetX + row + MAP_CELL_PROPERTY_INDEX);
                property = (u8 *)*gCurrentMap + MAP_PROPERTY_CELLS + (s32)cellIndex * MAP_PROPERTY_STRIDE;
            } else {
                u8 y = unit->y;
                u16 row = *(u16 *)((u8 *)*gCurrentMap + (u32)y * 2 + MAP_ROW_OFFSETS);
                s8 cellIndex = *(s8 *)((u8 *)*gCurrentMap + (u32)unit->x + row + MAP_CELL_PROPERTY_INDEX);
                property = (u8 *)*gCurrentMap + MAP_PROPERTY_CELLS + (s32)cellIndex * MAP_PROPERTY_STRIDE;
            }
        }

        if (property[MAP_PROPERTY_COUNT] != 0) property[MAP_PROPERTY_COUNT]--;
        unit->targetX = MAP_UNIT_TARGET_NONE;
        unit->targetY = MAP_UNIT_TARGET_NONE;
        unit->unkB5 = 0;

loopinc:
        mapSlot = gCurrentMap;
        map = *mapSlot;
        unitIndex++;
        unitOffset = unitOffset + MAP_UNIT_STRIDE;
        groupBase = groupBaseTable[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
        if (unitIndex < (s32)groupBase + MAP_UNIT_GROUP_SCAN) continue;
        break;
    }
}
#pragma opt_strength_reduction on
/* Drop the action flag BeginAiTurn raises (bit 3 of the AI command state's
 * flags) once the AI starts picking its units' actions for the turn. */
void ClearAiActionFlags(void) {
    extern void *gAiCommandState;

    M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_FLAGS) =
        (u8)(M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_FLAGS) & ~8);
}
