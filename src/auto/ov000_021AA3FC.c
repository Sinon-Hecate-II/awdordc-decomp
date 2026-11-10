/* 9 functions from 0x021AA3FC to 0x021AAB78 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_unit_entry.h"

s32 CalcAreaEffectDamage(void *arg0,s32 arg1,s32 arg2){
s32 func_ov000_021a9904(u32);
extern u16 data_ov000_021b5c00;
s32 result;u32 n;u16 count;u32 kind;
if(((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)<=10)return 2;
if(func_ov000_021a9904((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)==2 && arg2==1)return 2;
kind=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;
result=M2C_FIELD(&data_ov000_021b5c00,u16 *,kind*0x70);
n=(u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25;
if(arg1<(s32)n)count=arg1;else count=n-1;
result*=count;
if(func_ov000_021a9904(kind)==2 && arg2==0)result>>=1;
return result;
}

u32 CalcAreaEffectUnitCount(void *arg0,s32 arg1,s32 arg2){
s32 func_ov000_021a9904(u32);
u32 n;u16 count;
if(((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)<=10)return 1;
if(func_ov000_021a9904((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)==2 && arg2==1)return 1;
n=(u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25;
if(arg1<(s32)n)count=arg1;else count=n-1;
if(func_ov000_021a9904((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)==2 && arg2==0)count/=2;
return count;
}

s32 CombineAreaEffectDamage(s32 arg0, s32 arg1) {
    s32 var_r0;

    if (arg1 == 0) {
        return 0x80000001;
    }
    var_r0 = arg1 - arg0;
    if (var_r0 < 0x2328) {
        var_r0 = 0;
    }
    return var_r0;
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
void func_ov000_021aab20(s32, s32, s32, s32, s32, s32);
s32 func_ov000_021aa820(s32 a, s32 b, s32 c, s32 d) {
    s32 x;
    s32 y;
    typedef s32 (*Fn)(s32, s32, s32, s32, s32, s32);
    switch (d) {
    case 0:
        x = 2;
        y = 0x1e;
        break;
    case 1:
        x = 2;
        y = 0x50;
        break;
    default:
        return 0;
    }
    return ((Fn)func_ov000_021aab20)(a, b, c, d, x, y);
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

void func_ov000_021aab20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)SelectAreaEffectTarget)(a, b, c, d, e, f, 0);
}

void func_ov000_021aab4c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)SelectAreaEffectTarget)(a, b, c, d, e, f, 1);
}

