/* 2 functions from 0x02191970 to 0x0219234C (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 data_ov000_021df7e4[];
extern s8 data_ov000_021b55a0[];
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
void SelectMapLayer(void*);void func_01ffada0(s32,s32,u32,s32,s32);
s32 func_ov000_021a89a4(void*);s32 CanKindAttack(u32,u32);
s32 GetUnitMoveRange(u32,u32);s32 func_ov000_0217bcf4(s32,s32,s32);
s32 func_ov000_0217bcd4(s32,s32,u32,s32);
s32 func_ov000_021a9d8c(s16,s16);s32 func_ov000_021a9a28(u32,s32,s32);
s32 func_ov000_021a9860(s32,s32);s32 func_020d27ec(u32,u32);
void SetMapCursor(s16,s16,s32,s32,s32);void PlanMoveDestination(s32,s32);
s32 bestX=-1,bestY=-1,candidateX=-1,candidateY=-1;
s32 bestDistance=32767,chosen=0,special,index,offset,limit;
s32 distance,otherDistance,x,y,range,d,temporary;
void *unit;
if(M2C_FIELD(SEL,u8*,12))return;
SelectMapLayer(MAP+0x2338);
func_01ffada0(M2C_FIELD(SEL,u8*,1),M2C_FIELD(SEL,u8*,2),KIND(SEL),110,1);
SelectMapLayer(MAP+0x1e30);
limit=func_ov000_021a89a4(SEL)+1;
index=gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+1;
if(index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51){
offset=index*14;
for(;
index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51;index++,offset+=14){
unit=MAP+0x59a4+offset;
if(!KIND(unit)||!CanKindAttack(KIND(SEL),KIND(unit))||
data_ov000_021df7e4[index&63]||((u32)(M2C_FIELD(unit,u8*,11)<<24)>>31))continue;
switch(KIND(SEL)){
case 13:if(((u32)(M2C_FIELD(unit,u16*,8)<<16)>>30)==1)break;continue;
case 19:if(((u32)(M2C_FIELD(unit,u16*,8)<<16)>>30)!=0)break;continue;
}
range=GetUnitMoveRange(M2C_FIELD(MAP,u16*,0x52a4),KIND(unit));
{ s32 ux=M2C_FIELD(unit,u8*,1); s32 row=ROW(M2C_FIELD(unit,u8*,2)); d=M2C_FIELD(MAP+ux+row,s8*,0x2338); } special=0;
temporary=limit+range;
if(d<temporary&&(func_ov000_0217bcf4(M2C_FIELD(unit,u8*,1),M2C_FIELD(unit,u8*,2),range*2-1)==1||
func_ov000_0217bcd4(M2C_FIELD(unit,u8*,1),M2C_FIELD(unit,u8*,2),KIND(unit),range)==1)){special=1;d=temporary;}
if(d>bestDistance+range)continue;
func_01ffada0(M2C_FIELD(unit,u8*,1),M2C_FIELD(unit,u8*,2),KIND(unit),range,1);
distance=32767;otherDistance=32767;
if(((u32)(M2C_FIELD(unit,u16*,8)<<26)>>26)!=63){
SelectMapLayer(MAP+0x3250);
func_01ffada0(M2C_FIELD(SEL,u8*,1),M2C_FIELD(SEL,u8*,2),KIND(SEL),110,0);
SelectMapLayer(MAP+0x1e30);
if(CELL(M2C_FIELD(SEL,u8*,1),M2C_FIELD(SEL,u8*,2),0x3250)<0)continue;
}
for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(MAP+y*4,s8**,0x52e8),s8*,x)<0||
CELL(x,y,0x2338)<0||func_ov000_021a9d8c(x,y)!=0||
!func_ov000_021a9a28(KIND(SEL),x,y)||func_ov000_021a9860(x,y)==1)continue;
if(func_020d27ec(M2C_FIELD(MAP,u8*,0x52d4),TILE(x,y))==1&&data_ov000_021b55a0[TILE(x,y)&31]!=0)continue;
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
data_ov000_021df7e4[chosen&63]++;
if(bestDistance<limit)SetMapCursor(bestX,bestY,2,0,0);
else PlanMoveDestination(bestX,bestY);
}
#pragma optimization_level reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
void func_ov000_02192018(void) {
}
