/* 16 functions from 0x0217F754 to 0x02180738 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
static inline s32 SearchStart(s32 value) { return value; }
static inline void *SearchMapDimensions(void *map) { return (u8*)map+0x5120; }
static inline u16 SearchMapWidth(void *map) { return M2C_FIELD(map,u16*,0x5144); }
static inline u16 SearchMapHeight(void *map) { return M2C_FIELD(map,u16*,0x5146); }
static inline u16 SearchMapDimension(void *dims,s32 axis) { return M2C_FIELD(dims,u16*,0x24+axis*2); }
static inline s32 UnitSearchDistance(u8 *unit,s32 x,s32 y) { s32 d=0;if(unit[1]-x>0)d+=unit[1]-x;else d+=x-unit[1];if(unit[2]-y>0)d+=unit[2]-y;else d+=y-unit[2];return d; }
static inline s32 MapSearchDistance(s32 x0, s32 y0, s32 x1, s32 y1) {
 s32 distance=0;
 if(x0-x1>0)distance+=x0-x1;else distance+=x1-x0;
 if(y0-y1>0)distance+=y0-y1;else distance+=y1-y0;
 return distance;
}

void func_ov000_0217f754(s32 x, s32 y, u8 *out, u8 *value) {
    s32 GetKindAttackClass(u32);
    u8 func_ov000_0217f318(s32, s32);
    u8 func_ov000_0217f494(s32, s32);
    s32 IsMobileIndirectUnitKind(u32);
    extern void **gCurrentMap;
    u8 *p;
    u8 result;
    if (GetKindAttackClass((u32)(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[0] << 26) >> 26) == 0) {
        result = func_ov000_0217f318(x, y);
        if (!result) return;
        *out = 4;
        *value = result;
        return;
    }
    if (GetKindAttackClass((u32)(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[0] << 26) >> 26) != 1) return;
    p = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0);
    if (p[1] != x || p[2] != y) {
        if (!IsMobileIndirectUnitKind((u32)(p[0] << 26) >> 26)) return;
    }
    result = func_ov000_0217f494(x, y);
    if (result) {
        *out = 4;
        *value = result;
        return;
    }
    return;
}

/* Point the AI at the unit with id `unitId`: put `fromUnitId` back on its cell in
   the map's occupancy table, take the new unit off its cell, move the path start
   and the old cursor position to its tile, and pick the action's random tie-break
   and its movement range. */
void SetAiActingUnit(s32 fromUnitId, s32 unitId) {
    extern void **gCurrentMap;
    extern u8 *gAiCommandState;
    s32 NextRandomValue(void);
    s32 Modulo(s32, s32);
    u8 GetAiUnitMoveRange(void *);
    u8 *map, *from, *to;

    map = *gCurrentMap;
    from = map + MAP_UNIT_RECORDS + MAP_UNIT_STRIDE * fromUnitId;
    to = map + MAP_UNIT_RECORDS + MAP_UNIT_STRIDE * unitId;
    map[from[MAP_UNIT_X] + M2C_FIELD(map + 2 * from[MAP_UNIT_Y], u16 *, MAP_ROW_OFFSETS)] = fromUnitId;
    M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT) = to;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID) = unitId;
    map = *gCurrentMap;
    map[to[MAP_UNIT_X] + M2C_FIELD(map + 2 * to[MAP_UNIT_Y], u16 *, MAP_ROW_OFFSETS)] = 0;
    M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X) = to[MAP_UNIT_X];
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_X) = M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y) = to[MAP_UNIT_Y];
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_Y) = M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y);
    gAiCommandState[AI_COMMAND_STATE_TIEBREAK] = Modulo(NextRandomValue(), 100);
    gAiCommandState[AI_COMMAND_STATE_MOVE_RANGE] = GetAiUnitMoveRange(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT));
}

#pragma opt_strength_reduction off
void func_ov000_0217f96c(void *arg0) {
extern void **gCurrentMap;
void SelectMapLayer(void*); void BuildUnitMoveRangeBlockingUnits(void*); void MarkAdjacentCells(s32);
s32 AreUnitIdsOnSameTeam(s32,s32); s32 IsCellVisibleToCurrentTeam(s16,s16); s32 FindBestAdjacentTile(s32,s32,s16*);
s32 GetAiTargetScore(s32,s16*); s32 HasBetterAttackerNearby(void*);
void SetMapCursor(s32,s32,s32,s32,s32); void ChooseAiUnitMoveDestination(s32);
s32 bestX=-1,bestY=-1,best=0,score,id=0;
s32 x,y; s16 pos[2]; u8 *map,*unit,*other;
s32 minX,maxY,n,ux,uy,minY,maxX,xx,yy,index;
SelectMapLayer((u8*)*gCurrentMap+0x2338);
BuildUnitMoveRangeBlockingUnits(arg0);
SelectMapLayer((u8*)*gCurrentMap+0x1e30);
BuildUnitMoveRangeBlockingUnits(M2C_FIELD(*gCurrentMap,void**,0x52d0));
{
s32 ax,ay;
for(ay=0;ay<M2C_FIELD(*gCurrentMap,u16*,0x5146);ay++)
for(ax=0;ax<M2C_FIELD(*gCurrentMap,u16*,0x5144);ax++){
map=*gCurrentMap;
if(M2C_FIELD(map+ay*4,s8**,0x52e8)[ax]>=0 && M2C_FIELD(map+ax+M2C_FIELD(map+ay*2,u16*,0x3758),s8*,0x2338)<0)
M2C_FIELD(map+ay*4,s8**,0x52e8)[ax]=-1;
}
}
MarkAdjacentCells(111);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++)
for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
map=*gCurrentMap;
if(M2C_FIELD(map+y*4,s8**,0x52e8)[x]<0)continue;
unit=map+0x59a4+14*(s16)map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
if(((u32)(unit[0]<<26)>>26)==0)continue;
index=unit?(unit-(map+0x59a4))/14:0;
if(AreUnitIdsOnSameTeam(M2C_FIELD(map,u8*,0x52d4),index)==1)continue;
if(!IsCellVisibleToCurrentTeam((s16)x,(s16)y))continue;
if(!FindBestAdjacentTile(x,y,pos))continue;
map=*gCurrentMap;
score=GetAiTargetScore(map[x+M2C_FIELD(map+y*2,u16*,0x3758)]|0x30000,pos);
if(!score || score<best)continue;
if(HasBetterAttackerNearby(unit)==1){
u8 *nearMap;
ux=unit[1];uy=unit[2];n=0;
minX=ux-1;if(minX<0)minX=0;
minY=uy-1;if(minY<0)minY=0;
nearMap=*gCurrentMap;
maxX=M2C_FIELD(nearMap,u16*,0x5144)-1;if(ux+1<maxX)maxX=ux+1;
maxY=M2C_FIELD(nearMap,u16*,0x5146)-1;if(uy+1<maxY)maxY=uy+1;
for(yy=minY;yy<=maxY;yy++)for(xx=minX;xx<=maxX;xx++){
s32 dist=0;
if(ux-xx>0)dist+=ux-xx;else dist+=xx-ux;
if(uy-yy>0)dist+=uy-yy;else dist+=yy-uy;
if(dist<1 || dist>1)continue;
nearMap=*gCurrentMap;
if(M2C_FIELD(nearMap+yy*4,s8**,0x52e8)[xx]<0)continue;
other=nearMap+0x59a4+14*(nearMap+M2C_FIELD(nearMap+yy*2,u16*,0x3758))[xx];
if(((u32)(other[0]<<26)>>26)!=0 && (M2C_FIELD(other,u16*,4)&1))continue;
n++;
}
if(n<=1)continue;
}
best=score;bestX=pos[0];bestY=pos[1];
map=*gCurrentMap;id=map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
}
if(best)SetMapCursor((s16)bestX,(s16)bestY,4,(u8)id,0);
SelectMapLayer((u8*)*gCurrentMap+0x2338);
BuildUnitMoveRangeBlockingUnits(arg0);
SelectMapLayer((u8*)*gCurrentMap+0x1e30);
ChooseAiUnitMoveDestination(1);
}
#pragma opt_strength_reduction off
void func_ov000_0217fe68(void *arg0) {
extern void **gCurrentMap;extern u8 gUnitKindStats[];
s32 GetUnitAttackRangeMax(void*); s32 AreUnitIdsOnSameTeam(s32,s32);s32 IsCellVisibleToCurrentTeam(s16,s16);s32 GetAiTargetScore(s32,s16*);
void SetMapCursor(s32,s32,s32,s32,s32);void SelectMapLayer(void*);void BuildUnitMoveRangeBlockingUnits(void*);void ChooseAiUnitMoveDestination(s32);
s32 best=0,id=0; s16 pos[2];s32 minX,minY,maxX,maxY,x,y,distance,score,index;u8 *unit,*map;
pos[0]=M2C_FIELD(*gCurrentMap,u8**,0x52d0)[1];pos[1]=M2C_FIELD(*gCurrentMap,u8**,0x52d0)[2];
minX=(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[1]-GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)))<0?0:(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[1]-GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)));
minY=(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[2]-GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)))<0?0:(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[2]-GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)));
if((M2C_FIELD(*gCurrentMap,u8**,0x52d0)[1]+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)))>=M2C_FIELD(SearchMapDimensions(*gCurrentMap),u16*,0x24)-1) maxX=M2C_FIELD(*gCurrentMap,u16*,0x5144)-1;else maxX=(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[1]+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)));
if((M2C_FIELD(*gCurrentMap,u8**,0x52d0)[2]+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)))>=M2C_FIELD(SearchMapDimensions(*gCurrentMap),u16*,0x26)-1) maxY=M2C_FIELD(*gCurrentMap,u16*,0x5146)-1;else maxY=(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[2]+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)));
for(y=minY;y<=maxY;y++)for(x=minX;x<=maxX;x++){
unit=M2C_FIELD(*gCurrentMap,u8**,0x52d0);
distance=0;if(unit[1]-x>0)distance+=unit[1]-x;else distance+=x-unit[1];if(unit[2]-y>0)distance+=unit[2]-y;else distance+=y-unit[2];
if(distance<gUnitKindStats[((u32)(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[0]<<26)>>26)*112+12])continue;
if(distance>GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8**,0x52d0)))continue;
map=*gCurrentMap;unit=map+0x59a4+14*(s16)map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
if(!((u32)(unit[0]<<26)>>26))continue;
index=unit?(unit-(map+0x59a4))/14:0;
if(AreUnitIdsOnSameTeam(M2C_FIELD(map,u8*,0x52d4),index)==1)continue;
if(!IsCellVisibleToCurrentTeam((s16)x,(s16)y))continue;
map=*gCurrentMap;
score=GetAiTargetScore(map[unit[1]+M2C_FIELD(map+unit[2]*2,u16*,0x3758)]|0x30000,pos);
if(!score||score<best)continue;
best=score;map=*gCurrentMap;id=map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
}
if(best)SetMapCursor(M2C_FIELD(*gCurrentMap,u8**,0x52d0)[1],M2C_FIELD(*gCurrentMap,u8**,0x52d0)[2],4,(u8)id,0);
SelectMapLayer((u8*)*gCurrentMap+0x2338);BuildUnitMoveRangeBlockingUnits(arg0);SelectMapLayer((u8*)*gCurrentMap+0x1e30);ChooseAiUnitMoveDestination(1);
}
#pragma opt_strength_reduction reset
void func_ov000_02180268(s32 x,s32 y){
extern void **gCurrentMap;extern u8 *gAiCommandState;extern u8 *gAiUnitListCursor;
s32 GetKindAttackClass(u32);void func_ov000_0217f96c(void *);void func_ov000_0217fe68(void *);void SetMapCursor(s32,s32,s32,s32,s32);
u8 *base=*gCurrentMap;u8 *p,*q;u32 index,selected;
index=base[x+M2C_FIELD(base+(unsigned)y*2,u16 *,0x3758)];selected=M2C_FIELD(base,u8 *,0x52d4);p=(u8 *)((u32)(base+0x59a4)+index*14);q=M2C_FIELD(base,u8 **,0x52d0);
if(M2C_FIELD(p,u16 *,4)&1)return;
if((u32)(p[11]<<28)>>28==6)return;
M2C_FIELD(gAiCommandState,u16 *,8)|=1;
if(((u32)(M2C_FIELD(p,u16 *,6)<<16)>>27)!=0 || ((u32)(M2C_FIELD(q,u16 *,6)<<25)>>25)<((u32)(M2C_FIELD((u32)p,u16 *,6)<<25)>>25)){
SetAiActingUnit(selected,(u32)index);gAiUnitListCursor -= 1;
if((u32)(M2C_FIELD(p,u16 *,6)<<16)>>27)SetMapCursor(p[1],p[2],3,0,0);
switch(GetKindAttackClass((u32)(q[0]<<26)>>26)){case 0:func_ov000_0217f96c(q);break;case 1:func_ov000_0217fe68(q);break;}
SetAiActingUnit(index,selected);++gAiUnitListCursor;
}else{
*gAiUnitListCursor=index;gAiUnitListCursor -= 1;
switch(GetKindAttackClass((u32)(p[0]<<26)>>26)){case 0:func_ov000_0217f96c(p);break;case 1:func_ov000_0217fe68(p);break;}
++gAiUnitListCursor;
}
}

/* True when the battle runs in the default config mode (the low five bits of
 * gMapConfig are zero) and map 0xAF's view belongs to player 2: the AI's special
 * map-175 override. */
s32 IsAiMap175Player2Override(void) {
 extern u16 gMapConfig;
 extern void **gCurrentMap;
 void *map;
 if (((u32)(gMapConfig<<29)>>29)&0xFF) return 0;
 map=*gCurrentMap;
 switch(M2C_FIELD(map,u16 *,MAP_ID)) { case 0xAF: if(M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)==2)return 1; break; }
 return 0;
}

/* AI override for map 0xAF (175): on that map only, clear the influence maps
 * and plan the AI unit's move. */
void RunAiMap175MoveOverride(void) {
    M2C_UNK PlanAiUnitMove();
    extern void **gCurrentMap;
    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_ID) != 0xAF) {
        return;
    }
    ClearAiInfluenceMaps();
    PlanAiUnitMove();
}

/* AI step shared by role-4/6 states 0, 2-5, 7 and 8: rebuild the influence maps,
 * pick the acting unit's target and carry out the attack. */
void RunAiRole4Or6AttackStep(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK RunAiAttackAction();
    M2C_UNK SelectAiActionTarget();
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
}

/* Role-4/6 action for a unit in AI step 1 or 9 (cases 1 and 9 of the
 * RunAiRole4Or6Action dispatcher, src/auto/ov000_02180738.c): rebuild the
 * influence maps, pick the acting unit's target and carry out its attack. */
void RunAiRole4Or6Step1Or9Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
}

/* Role-4/6 AI step-6 handler (case 6 of the RunAiRole4Or6Action callback): clear
 * the influence maps and pick the acting unit's attack target. */
void RunAiRole4Or6Step6TargetAction(void) {
    M2C_UNK SelectUnitAttackTarget();
    M2C_UNK ClearAiInfluenceMaps();
    ClearAiInfluenceMaps();
    SelectUnitAttackTarget();
}

/* One step of an AI unit's action: build the influence maps, pick and run an
 * attack, find a move target, and - when the current player's AI mode is on -
 * pick an enemy attack destination; then plan every destination kind and finish
 * the unit's action. */
void RunAiAttackAndPlanStep(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanEnemyUnitAttackDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPropertyAttackDestination();
    M2C_UNK PlanEnemyHqAttackDestinationAlt();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *map;

    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    map = *gCurrentMap;
    if (M2C_FIELD((s8 *)map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0) {
        func_ov000_02186a18();
    }
    PlanEnemyUnitAttackDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPropertyAttackDestination();
    PlanEnemyHqAttackDestinationAlt();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* AI unit action step 1: clear and rebuild the influence maps, pick the acting
 * unit's move action and run its attack, let an AI-controlled player refine it,
 * then plan every destination kind and finish the unit's action. */
void RunAiUnitActionStep1(void) {
    M2C_UNK ClearAiInfluenceMaps();
    M2C_UNK SelectAiMoveActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK PlanEnemyUnitAttackDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPropertyAttackDestination();
    M2C_UNK PlanEnemyHqAttackDestinationAlt();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *map;

    ClearAiInfluenceMaps();
    SelectAiMoveActionTarget();
    RunAiAttackAction();
    map = *gCurrentMap;
    if (M2C_FIELD((s8 *)map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0) {
        func_ov000_02186a18();
    }
    PlanEnemyUnitAttackDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPropertyAttackDestination();
    PlanEnemyHqAttackDestinationAlt();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* Role-4/6 AI unit at step 2: rebuild the influence maps and pick the acting
 * unit's action, then run this step's destination planners.  When the current
 * player is AI-controlled, pick an attack position first. */
void RunAiRole4Or6Step2Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanEnemyHqAttackDestinationAlt();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPropertyAttackDestination();
    M2C_UNK PlanEnemyUnitAttackDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *map;
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    map = *gCurrentMap;
    if (M2C_FIELD((s8 *)map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0) {
        func_ov000_02186a18();
    }
    PlanEnemyHqAttackDestinationAlt();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPropertyAttackDestination();
    PlanEnemyUnitAttackDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* AI unit action pipeline for AI step 3: rebuild the influence maps and the
   action target, run the attack it chose, find a move target, let players with
   an AI behaviour mode refine it, then plan the production-site, attack,
   property, enemy-unit and port destinations and finish the action. */
void RunAiUnitActionStep3(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanCapturablePropertyDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPropertyAttackDestination();
    M2C_UNK PlanEnemyUnitAttackDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *map;

    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    map = *gCurrentMap;
    if (M2C_FIELD((u8 *)map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0) {
        func_ov000_02186a18();
    }
    PlanCapturablePropertyDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPropertyAttackDestination();
    PlanEnemyUnitAttackDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* Role-4/6 AI step-4 action: build the influence maps, pick the unit's attack
 * target and run its attack, find the best move target, look for an indirect
 * attack tile when the current player is in an aggressive AI mode, then plan the
 * step-4 move and the unit's attack/property/port destinations and finish. */
void RunAiRole4Or6Step4Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanAiStep4Destination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK PlanEnemyUnitAttackDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectPropertyAttackDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *map;

    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    map = *gCurrentMap;
    if (M2C_FIELD((s8 *)map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0) {
        func_ov000_02186a18();
    }
    PlanAiStep4Destination();
    SelectAttackMoveDestination();
    PlanEnemyUnitAttackDestination();
    PlanProductionSiteDestination();
    SelectPropertyAttackDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* Role-4/6 AI step-5 action: build the influence maps and pick the acting unit's
 * attack target, run the in-place attack when the owning player's AI mode calls
 * for it, then plan the HQ, production-site and attack/port destinations and
 * finish the unit's action. */
void RunAiRole4Or6Step5Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanHqDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *map;

    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    map = *gCurrentMap;
    if (M2C_FIELD((s8 *)map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0) {
        func_ov000_02186a18();
    }
    PlanHqDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

