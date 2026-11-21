/* 5 functions from 0x021A4A98 to 0x021A58C8 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
extern void **gCurrentMap;
extern u8 gUnitKindFlags[],gUnitKindStats[];
#define MAP (*gCurrentMap)
#define KIND(p) ((u32)((p)[0]<<26)>>26)
#define ROW(y) M2C_FIELD(MAP+(y)*2,u16*,0x3758)
#define CELL(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),u8*,off)
static inline s32 UnitIndexA4e08(u8 *p){return p?((s32)(p-(u8*)(MAP+0x59a4)))/14:0;}
static inline s32 UnitOwnerA4e08(u8 *p){return p?(UnitIndexA4e08(p)>>6)+1:0;}

#pragma push
#pragma opt_strength_reduction off
/* Evaluate whether the target group reached from candidate tile (candidateX,
 * candidateY) is worth capturing: flood its tank movement range and the ring
 * around it, reject impact terrain, bases of another team and enemy foot
 * defenders, then return the current player's foot units there plus one, with
 * bit 8 set when the group also holds a kind-24/25 production site. */
s32 EvaluateAiTargetGroupForCapture(u8 candidateX, u8 candidateY) {
    void FloodFillUnitRange(s32, s32, s32, s32, s32);
    void MarkAdjacentCells(s8);
    s32 IsUnitOnCurrentTeam(s32);
    s32 GetTerrainPropertyFlagsAt(s32, s32);
    s32 HasAiOptionalUnitBuildFlag(void);
    s32 CountPlayerUnitsOfKindTotal(s32);
    s32 IsCurrentPlayerUnit(s16);
    u8 IsUnitProductionTerrain(u8);
    s32 IsCellOwnedByOtherArmy(s16, s16, s16);
    u8 IsFootUnitKind(s32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern u8 gUnitKindStats[];

    s32 enemyProperty = 0;
    s32 footUnits = 0;
    s32 productionSite = 0;
    s32 y, x;
    u32 unitId;
    void *map;
    u16 rowOffset;
    u8 terrainKind;
    u32 unitKind;
    s32 result;

    FloodFillUnitRange(candidateX, candidateY, 7, MAP_GRID_NO_UNIT_MAX, 0);
    MarkAdjacentCells(AI_THREAT_RING_FIRST);

    map = *gCurrentMap;
    for (y = 0; y < M2C_FIELD(map,u16*,MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(map,u16*,MAP_WIDTH); x++, map = MAP) {
            void *grid = *(void **)((u8 *)map + y * 4 + MAP_GRID);
            s8 rangeValue = ((s8 *)grid)[x];
            if (rangeValue < 0) continue;
            rowOffset = *(u16 *)((u8 *)map + y * 2 + MAP_ROW_OFFSETS);
            terrainKind = ((u8 *)map + x + rowOffset)[MAP_CELL_TERRAIN] & MAP_TERRAIN_KIND_MASK;
            if (terrainKind == MAP_TERRAIN_IMPACT) return 0;
            if (rangeValue > MAP_GRID_NO_UNIT_MAX) {
                unitId = ((u8 *)map + x + rowOffset)[MAP_CELL_VISIBLE_UNIT];
                if (unitId != 0) IsUnitOnCurrentTeam(unitId);
                continue;
            }
            if (terrainKind == MAP_TERRAIN_BASE) {
                s16 groupBase = *(s16 *)((u8 *)map + MAP_UNIT_GROUP_BASE);
                if (IsCellOwnedByOtherArmy(groupBase, x, y) == 1) return 0;
            }
            if (productionSite == 0) {
                terrainKind = CELL(x, y, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
                if (terrainKind == MAP_TERRAIN_PORT) {
                    if (CountPlayerUnitsOfKindTotal(0x18) != 0) productionSite = 1;
                    else if (HasAiOptionalUnitBuildFlag() == 1) productionSite = 1;
                }
                if (productionSite == 0 && IsUnitProductionTerrain(CELL(x, y, MAP_CELL_TERRAIN)) != 0 &&
                    (CELL(x, y, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK) != MAP_TERRAIN_PORT) {
                    if (CountPlayerUnitsOfKindTotal(0x18) != 0) productionSite = 1;
                    else if ((((u32)M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_MODE) << 20 >> 29) & 4) &&
                             HasAiOptionalUnitBuildFlag() == 1) productionSite = 1;
                }
            }
            unitId = CELL(x, y, MAP_CELL_VISIBLE_UNIT);
            if (unitId == 0) continue;
            if (GetTerrainPropertyFlagsAt(x, y) == 1) enemyProperty = 1;
            if (IsUnitOnCurrentTeam(unitId) == 0) {
                unitKind = KIND((u8 *)MAP + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE);
                {
                    u8 *kindStats = gUnitKindStats + unitKind * UNIT_KIND_STATS_SIZE;
                    if ((kindStats[UNIT_KIND_STATS_FLAGS] & 7) != 0 && IsFootUnitKind(unitKind) != 0) return 0;
                }
            } else {
                if (IsCurrentPlayerUnit(unitId) == 1) {
                    unitKind = KIND((u8 *)MAP + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE);
                    if (IsFootUnitKind(unitKind) != 0) footUnits++;
                }
            }
        }
    }

    if (enemyProperty != 0) {
        if (productionSite != 0) return AI_CAPTURE_EVAL_PRODUCTION_SITE | 1;
        return 1;
    }
    result = footUnits + 1;
    if (productionSite != 0) result |= AI_CAPTURE_EVAL_PRODUCTION_SITE;
    return result;
}
#pragma pop

s32 func_ov000_021a4dc4(void) {
    s32 EvaluateAiTargetGroupForCapture(u8, u8);
    s32 FindAiTargetCandidate(s32);
    extern u8 gAiTargetCandidates;
    extern u8 data_ov000_021e00ad;
    s32 index = FindAiTargetCandidate(1);
    s32 offset;
    if (index == -1) return 0;
    offset = index * 12;
    return EvaluateAiTargetGroupForCapture((&gAiTargetCandidates)[offset], (&data_ov000_021e00ad)[offset]);
}

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_021a4e08(s32 cx,s32 cy,s32 kind){
s32 GetUnitMoveRange(s32,u32);void FloodFillUnitRange(s32,s32,s32,s32,s32);
void MarkAdjacentCells(s8);s32 IsUnitOnCurrentTeam(s32);
s32 GetUnitDamagePercent(u32,s32);s32 Divide(s32,s32);
s32 GetUnitMaxAttackRange(s32,u32);s32 IsMobileIndirectUnitKind(u32);
s32 sum,max;u16 saved=M2C_FIELD(MAP,u16*,0x52b6);s32 x,y,minX,minY,maxX,maxY,distance,value;u32 range;
u8 flags=gUnitKindFlags[kind*112];
u16 health;
u8 *unit;
sum=0;max=0;health=0;
if(flags&16){
FloodFillUnitRange(cx,cy,14,GetUnitMoveRange(M2C_FIELD(MAP,u16*,0x52a4),14),1);
for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(M2C_FIELD(MAP+y*4,s8**,0x52e8)[x]<0||!CELL(x,y,0x508)||!IsUnitOnCurrentTeam(CELL(x,y,0)))continue;
{ void *base=MAP; unit=(u8*)(base+0x59a4)+M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16*,0x3758),u8*,0x508)*14; }
if(KIND(unit)==14)health+=(u32)(M2C_FIELD(unit,u16*,6)<<25)>>25;
}}
minX=cx-9;if(minX<0)minX=0;
minY=cy-9;if(minY<0)minY=0;
maxX=M2C_FIELD(MAP,u16*,0x5144)-1;if(cx+9<maxX)maxX=cx+9;
maxY=M2C_FIELD(MAP,u16*,0x5146)-1;if(cy+9<maxY)maxY=cy+9;
for(y=minY;y<=maxY;y++)for(x=minX;x<=maxX;x++){
distance=0;if(cx-x>0)distance+=cx-x;else distance+=x-cx;if(cy-y>0)distance+=cy-y;else distance+=y-cy;
if(distance<1||distance>9||!CELL(x,y,0x508)||IsUnitOnCurrentTeam(CELL(x,y,0))==1)continue;
{ void *base=MAP; unit=(u8*)(base+0x59a4)+M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16*,0x3758),u8*,0x508)*14; }
if(kind==22&&KIND(unit)!=23)continue;
if(health<100&&(KIND(unit)==14||(u8)(KIND(unit)+240)<=1)&&(gUnitKindStats[kind*112+19]&16)){

M2C_FIELD(MAP,u16*,0x52b6)=UnitOwnerA4e08(unit);
FloodFillUnitRange(unit[1],unit[2],KIND(unit),GetUnitMoveRange(UnitOwnerA4e08(unit),KIND(unit)),1);
MarkAdjacentCells(111);
if(M2C_FIELD(MAP+cy*4,s8**,0x52e8)[cx]<0)continue;
value=Divide(((u32)(M2C_FIELD(unit,u16*,6)<<25)>>25)*GetUnitDamagePercent(KIND(unit),kind),100);
if(kind!=14)sum+=value;else if(value>max)max=value;continue;
}
if((((gUnitKindStats[kind*112+19]&16)||kind==22||kind==25)&&KIND(unit)==23)||
((gUnitKindStats[kind*112+19]&16)&&KIND(unit)==6)||
((u32)(kind-20)<=1&&(KIND(unit)==22||KIND(unit)==15||KIND(unit)==17))){

M2C_FIELD(MAP,u16*,0x52b6)=UnitOwnerA4e08(unit);
FloodFillUnitRange(unit[1],unit[2],KIND(unit),GetUnitMoveRange(UnitOwnerA4e08(unit),KIND(unit)),1);
MarkAdjacentCells(111);
if(M2C_FIELD(MAP+cy*4,s8**,0x52e8)[cx]<0)continue;
value=Divide(((u32)(M2C_FIELD(unit,u16*,6)<<25)>>25)*GetUnitDamagePercent(KIND(unit),kind),100);
if(kind==15&&KIND(unit)==6)value>>=1;sum+=value;continue;
}
range=GetUnitMaxAttackRange(UnitOwnerA4e08(unit),KIND(unit));
if(range<=1)continue;
if(range<distance&&!IsMobileIndirectUnitKind(KIND(unit)))continue;
range=gUnitKindStats[KIND(unit)*112+12];if(range<=2)range=2;if(range>distance)continue;
value=Divide(((u32)(M2C_FIELD(unit,u16*,6)<<25)>>25)*GetUnitDamagePercent(KIND(unit),kind),100);
sum+=value;
}
M2C_FIELD(MAP,u16*,0x52b6)=saved;
return sum+max;
}
#pragma pop
#pragma push
#pragma opt_strength_reduction off
/* For one player, marks each of the player's type-22 units with a type-23 marker
 * and outlines its neighbours in the overlay grid, then adds one to the per-cell
 * influence layer across every valid cell unless the acting player already has a
 * type-23 marker on the map. */
void MarkPlayerInfluence(u8 player){
void FloodFillUnitRange(s32,s32,s32,s32,s32);void MarkAdjacentCells(s8);s32 GetUnitMoveRange(s32,u32);s32 IsUnitOnCurrentTeam(s32);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];
s32 unitId,unitOffset; s32 scanX,scanY;u8 *unit;u8 *otherUnit;s32 x,y;void *base;s32 unitIndex,owner;u32 kind;
M2C_FIELD(*gCurrentMap,u16*,0x52b6)=player;
unitId=gPlayerUnitIdBase[player]+1;if(unitId>=gPlayerUnitIdBase[player]+51)return;unitOffset=unitId*14;
do{
base=*gCurrentMap;unit=(u8*)(base+0x59a4)+unitOffset;
kind=(u32)(unit[0]<<26)>>26;if(!kind)goto next;if(kind!=22)goto next;
if(unit){unitIndex=unit?((s32)(unit-(u8*)(base+0x59a4)))/14:0;owner=(unitIndex>>6)+1;}else owner=0;
FloodFillUnitRange(unit[1],unit[2],23,GetUnitMoveRange(owner,kind),33);MarkAdjacentCells(111);
base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16*,0x5144);x++,base=*gCurrentMap){
if(M2C_FIELD(base+y*4,s8**,0x52e8)[x]<0)continue;
otherUnit=(u8*)(base+0x59a4)+M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16*,0x3758),u8*,0)*14;
unitIndex=otherUnit?((s32)(otherUnit-(u8*)(base+0x59a4)))/14:0;
if(!IsUnitOnCurrentTeam(unitIndex))continue;
if(((u32)(otherUnit[0]<<26)>>26)==23)goto next;
}}
for(scanY=0;scanY<M2C_FIELD(base,u16*,0x5146);scanY++){
for(scanX=0;scanX<M2C_FIELD(base,u16*,0x5144);scanX++,base=*gCurrentMap){
if(M2C_FIELD(base+scanY*4,s8**,0x52e8)[scanX]<0)continue;
M2C_FIELD(base+scanX+M2C_FIELD(base+scanY*2,u16*,0x3758)+0x2000,s8*,0x338)=M2C_FIELD(base+scanX+M2C_FIELD(base+scanY*2,u16*,0x3758),s8*,0x2338)+1;
}}
next:;unitId++;unitOffset+=14;
}while(unitId<gPlayerUnitIdBase[player]+51);
}
#pragma pop
/* Rebuilds the map's influence score layer: clear the score layer to zero,
 * select the layer the range fills work in, add one point to every cell each
 * other player's kind-22 unit can reach, then restore the player being
 * processed. */
void BuildInfluenceMap(void) {
    void FillMapLayer(s32);
    void SelectMapLayer(void *);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void MarkPlayerInfluence(u8);
    extern void **gCurrentMap;
    u16 savedPlayer;
    s32 player;
    void *map;
    map = *gCurrentMap;
    savedPlayer = M2C_FIELD(map, u16 *, MAP_ACTIVE_PLAYER);
    SelectMapLayer(map + MAP_CELL_SCORE);
    FillMapLayer(0);
    SelectMapLayer(*gCurrentMap + MAP_CELL_ORDER);
    for (player = 1; player < 5; player++) {
        if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0)
            MarkPlayerInfluence(player);
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = savedPlayer;
}

