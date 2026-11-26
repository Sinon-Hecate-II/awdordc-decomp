/* 9 functions from 0x021AA3FC to 0x021AAB78 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_unit_entry.h"

/* Area-effect target scoring: a score of AREA_EFFECT_SCORE_NONE means "no
 * candidate cell", and net damage below AREA_EFFECT_MIN_NET_DAMAGE scores 0. */
#define AREA_EFFECT_SCORE_NONE     0x80000001
#define AREA_EFFECT_MIN_NET_DAMAGE 0x2328

/* Estimate the damage an area effect of `unit`'s kind deals to the unit: the
 * kind's attack power times the number of damage steps `power` allows (capped at
 * the unit's HP minus one), halved for friendly units and kept at a floor of 2
 * when the effect kind cannot attack. */
s32 CalcAreaEffectDamage(UnkStruct_ov000_021A860C *unit,s32 power,s32 isEnemy){
s32 GetKindAttackClass(u32);
extern u16 gUnitKindBuildCosts;
s32 damage;u32 hp;u16 hits;u32 kind;
if(unit->unk6<=10)return 2;
if(GetKindAttackClass(unit->unk0)==UNIT_ATTACK_NONE && isEnemy==1)return 2;
kind=unit->unk0;
damage=M2C_FIELD(&gUnitKindBuildCosts,u16 *,kind*0x70);
hp=unit->unk6;
if(power<(s32)hp)hits=power;else hits=hp-1;
damage*=hits;
if(GetKindAttackClass(kind)==UNIT_ATTACK_NONE && isEnemy==0)damage>>=1;
return damage;
}

/* Number of damage steps an area effect of `unit`'s kind lands on it: one for a
 * unit already down to a single bar, then `power` steps capped at the unit's HP
 * minus one, halved for a friendly unit the effect's kind cannot attack. */
u32 CalcAreaEffectUnitCount(UnkStruct_ov000_021A860C *unit,s32 power,s32 isEnemy){
s32 GetKindAttackClass(u32);
u32 hp;u16 hits;
if(unit->unk6<=10)return 1;
if(GetKindAttackClass(unit->unk0)==UNIT_ATTACK_NONE && isEnemy==1)return 1;
hp=unit->unk6;
if(power<(s32)hp)hits=power;else hits=hp-1;
if(GetKindAttackClass(unit->unk0)==UNIT_ATTACK_NONE && isEnemy==0)hits/=2;
return hits;
}

/* Mode-0 area-effect score: the net damage the effect deals (enemy damage total
 * minus friendly total), reported only when it clears AREA_EFFECT_MIN_NET_DAMAGE;
 * AREA_EFFECT_SCORE_NONE when no enemy unit is in range at all. */
s32 CombineAreaEffectDamage(s32 ownDamage, s32 enemyDamage) {
    s32 score;

    if (enemyDamage == 0) {
        return AREA_EFFECT_SCORE_NONE;
    }
    score = enemyDamage - ownDamage;
    if (score < AREA_EFFECT_MIN_NET_DAMAGE) {
        score = 0;
    }
    return score;
}

s32 CombineAreaEffectPenalty(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return 0x80000001;
    }
    return arg1 - (arg0 * 2);
}

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
s32 ScoreAreaEffectCell(void *playerIdx, s32 tileX, s32 tileY, s32 range, s32 count, s32 flag, s32 oldTileX, s32 oldTileY) {
    extern void **gCurrentMap;
    extern void *gAreaEffectFuncs[];
    s32 Unit_IsTargetable(s32,s32);
    u8 Units_ShareOwner(s32,s32);
    typedef s32 (*UnitValueFunc)(void *,s32,s32);
    typedef s32 (*AreaCombineFunc)(s32,s32);
    s32 xmin,ymin,right,bottom,dist,dx,zero,id;
    void *base;
    UnkStruct_ov000_021A860C *unit;
    s32 enemy=0;
    s32 xx,dy,yy;
    s32 own=0;
    xmin=tileX-range;if(xmin<0)xmin=0;
    ymin=tileY-range;if(ymin<0)ymin=0;
    base=*gCurrentMap;
    right=M2C_FIELD(base,u16 *,0x5144)-1;
    if(tileX+range<right)right=tileX+range;
    bottom=M2C_FIELD(base,u16 *,0x5146)-1;
    if(tileY+range<bottom)bottom=tileY+range;
    for(yy=ymin;yy<=bottom;yy++){
    xx=xmin;
    if(xx<=right){
    dy=tileY-yy;
    do {
    dx=tileX-xx;if(dx<=0)dx=xx-tileX;
    zero=0;
    dist=zero;
    dist+=dx;
    if(dy>0)dist+=dy;else dist+=yy-tileY;
    if(dist<0||dist>range)continue;
    if(xx==oldTileX && yy==oldTileY)unit=M2C_FIELD(*gCurrentMap,UnkStruct_ov000_021A860C **,0x52d0);
    else{
    base=*gCurrentMap;
    id=M2C_FIELD((u8 *)base+xx+M2C_FIELD((u8 *)base+yy*2,u16 *,0x3758),u8 *,0x508);
    unit=(UnkStruct_ov000_021A860C *)((u8 *)base+0x59a4)+id;
    }
    if(unit->unk0==0)continue;
    if(flag==1 && Unit_IsTargetable(((u8 *)unit)[1],((u8 *)unit)[2])==0)continue;
    if(unit==0)id=0;
    else id=unit-(UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4);
    if(Units_ShareOwner((s32)playerIdx,(id>>6)+1)==1)own+=((UnitValueFunc)gAreaEffectFuncs[1])(unit,count,0);
    else enemy+=((UnitValueFunc)gAreaEffectFuncs[1])(unit,count,1);
    }while(++xx<=right);
    }
    }
    base=*gCurrentMap;
    id=M2C_FIELD((u8 *)base+(tileX+M2C_FIELD((u8 *)base+tileY*2,u16 *,0x3758)),u8 *,0x508);
    if(id!=0 && Units_ShareOwner((s32)playerIdx,(id>>6)+1)==0)enemy++;
    return ((AreaCombineFunc)gAreaEffectFuncs[0])(own,enemy);
}
#pragma opt_strength_reduction reset
#pragma opt_loop_invariants reset
void SelectAreaEffectTargetOnAllCells(s32, s32, s32, s32, s32, s32);
/* Select a target cell for an area effect of the given mode with that mode's
 * default range (2 cells) and power (30 in mode 0, 80 in mode 1).  Returns 0 for
 * a mode without defaults, otherwise the selection's success flag. */
s32 SelectAreaEffectTargetForMode(s16 *outPos, s32 player, s32 targetableOnly, s32 mode) {
    s32 range;
    s32 power;
    typedef s32 (*Fn)(s32, s32, s32, s32, s32, s32);
    switch (mode) {
    case 0:
        range = 2;
        power = 0x1e;
        break;
    case 1:
        range = 2;
        power = 0x50;
        break;
    default:
        return 0;
    }
    return ((Fn)SelectAreaEffectTargetOnAllCells)(outPos, player, targetableOnly, mode, range, power);
}

/* Picks the map tile with the best area-effect score for a player: installs the
 * per-mode value/combine callbacks, scans the map (optionally skipping impassable
 * cells) and reports whether a candidate beat the mode's baseline score. */
s32 SelectAreaEffectTarget(s16 *outPos, void *player, s32 targetableOnly, s32 mode, s32 range, s32 power, u8 useGridFilter) {
s32 RandomIntRange(s32,s32);
extern void *gAreaEffectCallbacks[];
extern void **gCurrentMap;
s32 oldX,oldY,bestScore,cellX,cellY,score;
void *map;
typedef s32 (*AreaScoreFunc)(void *,s32,s32,s32,s32,s32,s32,s32);
switch(mode){
case 0:
oldX=outPos[0];oldY=outPos[1];bestScore=0;
gAreaEffectCallbacks[1]=(void *)CalcAreaEffectDamage;
gAreaEffectCallbacks[0]=(void *)CombineAreaEffectDamage;
break;
case 1:
oldY=-1;oldX=oldY;bestScore=0x80000001;
switch(RandomIntRange(0,1)){
case 0:gAreaEffectCallbacks[1]=(void *)CalcAreaEffectDamage;break;
case 1:gAreaEffectCallbacks[1]=(void *)CalcAreaEffectUnitCount;break;
}
gAreaEffectCallbacks[0]=(void *)CombineAreaEffectPenalty;
break;
case 6:
oldY=-1;oldX=oldY;
gAreaEffectCallbacks[1]=(void *)CalcAreaEffectDamage;
gAreaEffectCallbacks[0]=(void *)CombineAreaEffectDamage;
bestScore=0x80000001;
break;
default:return 0;
}
if(useGridFilter){
for(cellY=0;cellY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);cellY++){
for(cellX=0;cellX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);cellX++){
map=*gCurrentMap;
if(((s8 **)((u8 *)map+MAP_GRID))[cellY][cellX]<0)continue;
score=((AreaScoreFunc)ScoreAreaEffectCell)(player,cellX,cellY,range,power,targetableOnly,oldX,oldY);
if(score>bestScore){bestScore=score;outPos[0]=cellX;outPos[1]=(s16)cellY;}
}
}
}else{
for(cellY=0;cellY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);cellY++){
for(cellX=0;cellX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);cellX++){
score=((AreaScoreFunc)ScoreAreaEffectCell)(player,cellX,cellY,range,power,targetableOnly,oldX,oldY);
if(score>bestScore){bestScore=score;outPos[0]=cellX;outPos[1]=(s16)cellY;}
}
}
}
if(mode!=0){if(bestScore!=(s32)0x80000001)return 1;}
else if(bestScore!=0)return 1;
return 0;
}

/* Pick the best area-effect target for a player, scanning every map cell:
 * SelectAreaEffectTarget with its impassable-tile grid filter off. */
void SelectAreaEffectTargetOnAllCells(s32 outPos, s32 player, s32 targetableOnly, s32 mode, s32 range, s32 power) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)SelectAreaEffectTarget)(outPos, player, targetableOnly, mode, range, power, 0);
}

/* Pick the best area-effect target for a player, scanning only the map cells the
 * tile grid marks as passable (SelectAreaEffectTarget's grid filter on). */
void SelectAreaEffectTargetOnGrid(s32 outPos, s32 player, s32 targetableOnly, s32 mode, s32 range, s32 power) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)SelectAreaEffectTarget)(outPos, player, targetableOnly, mode, range, power, 1);
}

