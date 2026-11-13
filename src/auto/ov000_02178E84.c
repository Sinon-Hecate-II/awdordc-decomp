/* 5 functions from 0x02178E84 to 0x02179E48 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern s8 data_ov000_021b54c0[],data_ov000_021b5480[];
extern u8 gUnitKindFlags[];
extern u32 gUnitKindStats[];
extern void *gAiCommandState;
static inline s32 ov000_visibility_radius(void){
s32 func_020a33c4(u16);s32 ComputeUnitMoveRange(s32,u8,u16,s32,s32);
s32 bonus=func_020a33c4(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
return ComputeUnitMoveRange(24,M2C_FIELD(gAiCommandState,u8 *,12),M2C_FIELD(*gCurrentMap,u16 *,0x52a4),bonus,0);
}
static inline s32 ov000_scan_distance(s32 x,s32 y,s32 cx,s32 cy){
s32 d=0,dx=cx-x,dy=cy-y;
if(dx>0)d+=dx;else d+=x-cx;
if(dy>0)d+=dy;else d+=y-cy;
return d;
}


#pragma opt_strength_reduction off
s32 func_ov000_02178e84(s32 arg0,s32 arg1) {
s32 func_020d2d18(u16,u8);s32 IsTerrainOnUnitTeam(s16,s32);s32 IsUnitOnCurrentTeam(s32);s32 IsFootUnitKind(u32);s32 func_ov000_021a9318(s32,s32,s32);
u8 *unit;void *map;u32 terrain,kind; s32 x,y,d,xmin,ymin,xmax,ymax,radius,width,scanX,scanY;u16 player;u8 *selected;void *snapshot;
map=*gCurrentMap;unit=M2C_FIELD(map,u8 **,0x52d0);
if(((u32)(unit[11]<<28)>>28)==6)return 1;
terrain=M2C_FIELD(map+(arg0+M2C_FIELD(map+arg1*2,u16 *,0x3758)),u8 *,0x1420);
if(!data_ov000_021b54c0[terrain&31])return 1;
if(!IsTerrainOnUnitTeam(M2C_FIELD(map,s16 *,0x52a8),terrain)){
unit=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
if(IsFootUnitKind((u32)(unit[0]<<26)>>26))return 1;
xmin=arg0-3;if(xmin<0)xmin=0;
ymin=arg1-3;if(ymin<0)ymin=0;
map=*gCurrentMap;
xmax=M2C_FIELD(map,u16 *,0x5144)-1;if(arg0+3<xmax)xmax=arg0+3;
ymax=M2C_FIELD(map,u16 *,0x5146)-1;if(arg1+3<ymax)ymax=arg1+3;
for(y=ymin;y<=ymax;y++)for(x=xmin;x<=xmax;x++){
d=ov000_scan_distance(x,y,arg0,arg1);
if(d<1||d>3)continue;
map=*gCurrentMap;
kind=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
unit=map+0x59a4+(s16)kind*(s16)14;
if(((u32)(unit[0]<<26)>>26)==0)continue;
if(IsUnitOnCurrentTeam(kind)!=1)continue;
if(!IsFootUnitKind((u32)(unit[0]<<26)>>26))continue;
if(!(M2C_FIELD(unit,u16 *,4)&1))return 0;
}
map=*gCurrentMap;
terrain=M2C_FIELD(map+(arg0+M2C_FIELD(map+arg1*2,u16 *,0x3758)),u8 *,0x1420)&31;
if(terrain==19||terrain==21){
xmin=arg0-ov000_visibility_radius()<0?0:arg0-ov000_visibility_radius();
ymin=arg1-ov000_visibility_radius()<0?0:arg1-ov000_visibility_radius();
map=*gCurrentMap;
if(arg0+ov000_visibility_radius()>=M2C_FIELD(map,u16 *,0x5144)-1)xmax=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;
else xmax=arg0+ov000_visibility_radius();
map=*gCurrentMap;
if(arg1+ov000_visibility_radius()>=M2C_FIELD(map,u16 *,0x5146)-1)ymax=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;
else ymax=arg1+ov000_visibility_radius();
for(y=ymin;y<=ymax;y++)for(x=xmin;x<=xmax;x++){
d=ov000_scan_distance(x,y,arg0,arg1);
if(d<1||d>ov000_visibility_radius())continue;
map=*gCurrentMap;kind=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
unit=map+0x59a4+(s16)kind*(s16)14;
if(((u32)(unit[0]<<26)>>26)==0)continue;
if(IsUnitOnCurrentTeam(kind)!=1)continue;
kind=(u32)(unit[0]<<26)>>26;
if((u8)(kind+232)>1)continue;
if(!(M2C_FIELD(unit,u16 *,4)&1))return 0;
}
}
return 1;
}
map=*gCurrentMap;
terrain=M2C_FIELD(map+(arg0+M2C_FIELD(map+arg1*2,u16 *,0x3758)),u8 *,0x1420)&31;
if(!data_ov000_021b5480[terrain])return 1;
unit=M2C_FIELD(map,u8 **,0x52d0);
if(func_ov000_021a9318((u32)(unit[0]<<26)>>26,arg0,arg1)&&((u32)(M2C_FIELD(gAiCommandState,u8 *,7)<<30)>>31))return 1;
map=*gCurrentMap;unit=M2C_FIELD(map,u8 **,0x52d0);kind=(u32)(unit[0]<<26)>>26;
if(gUnitKindFlags[kind*112]&32){
xmin=arg0-6;if(xmin<0)xmin=0;ymin=arg1-6;if(ymin<0)ymin=0;
xmax=M2C_FIELD(map,u16 *,0x5144)-1;if(arg0+6<xmax)xmax=arg0+6;
ymax=M2C_FIELD(map,u16 *,0x5146)-1;if(arg1+6<ymax)ymax=arg1+6;
for(y=ymin;y<=ymax;y++)for(x=xmin;x<=xmax;x++){
d=ov000_scan_distance(x,y,arg0,arg1);
if(d<1||d>6)continue;
map=*gCurrentMap;kind=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
unit=map+0x59a4+(s16)kind*(s16)14;
if(((u32)(unit[0]<<26)>>26)==0)continue;
if(IsUnitOnCurrentTeam(kind)!=1)continue;
kind=(u32)(unit[0]<<26)>>26;
if(!(M2C_FIELD((u8 *)gUnitKindStats+kind*112,u8 *,19)&32))continue;
if(!((u32)(M2C_FIELD(unit,u16 *,8)<<18)>>30))continue;
if(!(M2C_FIELD(unit,u16 *,4)&1))return 0;
}
}
map=*gCurrentMap;selected=M2C_FIELD(map,u8 **,0x52d0);
if(((u32)(selected[0]<<26)>>26)==21&&selected[13]==0){
if(selected[12]){
unit=map+0x59a4+selected[12]*14;
if(((u32)(unit[0]<<26)>>26)==17)goto checkCurrent;
}
player=M2C_FIELD(map,u16 *,0x52a4);
if(func_020d2d18(player,17)*10<=M2C_FIELD(map+player*140,s32 *,0x67a4)){
map=*gCurrentMap;
y=0;if(y<M2C_FIELD(map,u16 *,0x5146)){width=M2C_FIELD(map,u16 *,0x5144);
do{for(x=0;x<width;x++){
if(x==arg0&&y==arg1)continue;
terrain=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420);
if((terrain&31)==19&&(terrain&224)==M2C_FIELD(map,u16 *,0x52a6))return 1;
}y++;}while(y<M2C_FIELD(map,u16 *,0x5146));}
}
}
checkCurrent:map=*gCurrentMap;
terrain=M2C_FIELD(map+(arg0+M2C_FIELD(map+arg1*2,u16 *,0x3758)),u8 *,0x1420);
if((terrain&31)==19&&(terrain&224)==M2C_FIELD(map,u16 *,0x52a6)){
player=M2C_FIELD(map,u16 *,0x52a4);
if(func_020d2d18(player,20)*10<=M2C_FIELD(map+player*140,s32 *,0x67a4))return 0;
}
snapshot=*gCurrentMap;selected=M2C_FIELD(snapshot,u8 **,0x52d0);kind=(u32)(selected[0]<<26)>>26;
if(kind==24){
xmin=arg0-6;if(xmin<0)xmin=0;ymin=arg1-6;if(ymin<0)ymin=0;
xmax=M2C_FIELD(snapshot,u16 *,0x5144)-1;if(arg0+6<xmax)xmax=arg0+6;
ymax=M2C_FIELD(snapshot,u16 *,0x5146)-1;if(arg1+6<ymax)ymax=arg1+6;
for(y=ymin;y<=ymax;y++)for(x=xmin;x<=xmax;x++){
d=ov000_scan_distance(x,y,arg0,arg1);if(d<1||d>6)continue;
map=*gCurrentMap;terrain=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420);
if((terrain&31)==17&&(terrain&224)==M2C_FIELD(map,u16 *,0x52a6))return 1;
}
}
if(kind==25){
xmin=arg0-3;if(xmin<0)xmin=0;ymin=arg1-3;if(ymin<0)ymin=0;
xmax=M2C_FIELD(snapshot,u16 *,0x5144)-1;if(arg0+3<xmax)xmax=arg0+3;
ymax=M2C_FIELD(snapshot,u16 *,0x5146)-1;if(arg1+3<ymax)ymax=arg1+3;
for(scanY=ymin;scanY<=ymax;scanY++)for(scanX=xmin;scanX<=xmax;scanX++){
d=ov000_scan_distance(scanX,scanY,arg0,arg1);if(d<1||d>3)continue;
map=*gCurrentMap;terrain=M2C_FIELD(map+scanX+M2C_FIELD(map+scanY*2,u16 *,0x3758),u8 *,0x1420);
if((terrain&31)==17&&(terrain&224)==M2C_FIELD(map,u16 *,0x52a6))return 1;
}
}
return 0;
}
#pragma opt_propagation off
s32 func_ov000_02179b08(void *arg0) {
s32 func_ov000_021a89a4(void *);s32 IsFootUnitKind(u32);
extern u8 gUnitKindFlags[];extern void *gAiSettings;extern void *gAiCommandState;
s32 value;u8 scale;u32 id;
if(!(((u32)(M2C_FIELD(gAiCommandState,u16 *,10)<<26)>>29)&4))return 110;
id=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;if(!(gUnitKindFlags[id*0x70]&7))return 110;
if((u32)(M2C_FIELD(arg0,u8 *,11)<<24)>>31)return 110;
if(IsFootUnitKind(id)&&M2C_FIELD(gAiCommandState,u8 *,5)<4U)value=4;else value=func_ov000_021a89a4(arg0);
if(((u32)(M2C_FIELD(arg0,u8 *,11)<<27)>>31)!=0)scale=M2C_FIELD(gAiSettings,u8 *,15);else scale=M2C_FIELD(gAiSettings,u8 *,14);
value*=scale; if(value>110) { value=110; } else { value=value; } return value;
}
#pragma opt_propagation reset
s32 GetAiUnitRange(u8 *arg0,void *arg1,u32 arg2) {
s32 IsFootUnitKind(u32);
extern void **data_027e0058;
extern u8 gUnitKindFlags[];
extern void *gAiSettings;
extern void *gAiCommandState;
s32 value,scale;u32 id;void *p;
if(!(((u32)(M2C_FIELD(gAiCommandState,u16 *,10)<<26)>>29)&4))return 110;
p=M2C_FIELD(*data_027e0058,void **,0x52d0);
id=(u32)(M2C_FIELD(p,u8 *,0)<<26)>>26;
if(!(gUnitKindFlags[id*0x70]&7))return 110;
if((u32)(M2C_FIELD(p,u8 *,11)<<24)>>31)return 110;
if(IsFootUnitKind(id)&&M2C_FIELD(gAiCommandState,u8 *,5)<4U)value=4;
else value=M2C_FIELD(gAiCommandState,u8 *,5);
if(((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058,void **,0x52d0),u8 *,11)<<27)>>31)!=0)scale=M2C_FIELD(gAiSettings,u8 *,15);
else scale=M2C_FIELD(gAiSettings,u8 *,14);
value*=scale;if(value>110)value=110;return value;
}

s32 func_ov000_02179ce4(u8 *arg0) {
    s32 GetAiUnitRange(u8 *, void *, u32);
    extern void **gCurrentMap;
    s32 result;
    u32 value;
    u8 *saved;
    void *base;
    base = (u8 *)*gCurrentMap + 0x5000;
    saved = M2C_FIELD(base, u8 **, 0x2D0);
    value = (u32)(*arg0 << 26) >> 26;
    if (value == 0) return 0x6E;
    M2C_FIELD(base, u8 **, 0x2D0) = arg0;
    result = (GetAiUnitRange(arg0, base, value) * 3) >> 2;
    M2C_FIELD(*gCurrentMap, u8 **, 0x52D0) = saved;
    return result;
}

void func_ov000_02179d3c(M2C_UNK arg0) {
M2C_UNK FloodFillUnitRange(u8,u8,u32,M2C_UNK,s32);
M2C_UNK MarkAdjacentCells(s8);
s32 GetUnitAttackRangeMax(void *);
s32 GetUnitMoveRange(u16,s32);
s32 GetUnitAttackClass(void);
extern void **gCurrentMap;
extern u8 gUnitMinAttackRange[];
s32 i,n;void *p,*base;
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
FloodFillUnitRange(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),(u32)(M2C_FIELD(p,u8 *,0)<<26)>>26,arg0,0);
base=*gCurrentMap;
if(((u32)(M2C_FIELD(M2C_FIELD(base,void **,0x52D0),u8 *,0)<<26)>>26)==21)
n=GetUnitMoveRange(M2C_FIELD(base,u16 *,0x52A4),17)+1;
else if(GetUnitAttackClass()==1)n=GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,void **,0x52D0));
else n=gUnitMinAttackRange[((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u8 *,0)<<26)>>26)*0x70];
i=0;if(n<=0)return;do{MarkAdjacentCells((s8)(i+0x6F));i++;}while(i<n);
}

