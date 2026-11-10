/* 3 functions from 0x02193D6C to 0x02194AB8 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
typedef struct { u16 x:6; u16 y:6; u16 unk:2; u16 state:2; } Position_02194090;
#include "ov000_unit_entry.h"
extern void **gCurrentMap;
extern void *data_ov000_021df580;
extern u16 gPlayerUnitIdBase[];
extern M2C_UNK data_ov000_021b5bfc;
#define MAP (*gCurrentMap)
#define SEL M2C_FIELD(MAP,u8**,0x52d0)
#define KIND(p) ((u32)((p)[0]<<26)>>26)
#define INFO ((u8*)&data_ov000_021b5bfc)
#define ROW(y) M2C_FIELD(MAP+(y)*2,u16*,0x3758)
#define CELL(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),u8*,off)
#define COST(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),s8*,off)
#define PATH(x,y) M2C_FIELD(MAP+(y)*4,s8**,0x52e8)[x]

void func_ov000_02193d6c(void *arg0) { (void)arg0; }

/* Scan reachable cells for a current-player unit that can attack the highlighted unit and move the cursor to it. */
void SelectAttackingUnit(void) {
#pragma opt_strength_reduction off
 u8 *unit;
 s32 foundX=-1, foundY=-1, foundKind=0, cellX,cellY;
 u8 *map;
 func_01ffc328(SEL);
 for(cellY=0;cellY<M2C_FIELD(MAP,u16*,0x5146);cellY++){
  for(cellX=0;cellX<M2C_FIELD(MAP,u16*,0x5144);cellX++){
   map=MAP;
   if((*(s8 **)(map+0x52e8+cellY*4))[cellX]<0)continue;
   if(!map[cellX+*(u16*)(map+0x3758+cellY*2)])continue;
   if(!IsCurrentPlayerUnit(map[cellX+*(u16*)(map+0x3758+cellY*2)+0x508]))continue;
   map=MAP;
   unit=map+0x59a4+14*(s16)map[cellX+*(u16*)(map+0x3758+cellY*2)];
   if(!(INFO[((UnkStruct_ov000_021A860C*)unit)->unk0*0x70+0x13]&0x20))continue;
   if(func_ov000_021a8984(((UnkStruct_ov000_021A860C*)unit)->unkB))continue;
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
 func_ov000_0217c3a4();
 SetMapCursor((s16)foundX,(s16)foundY,7,0,0);
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_02194370(void){
s32 IsPlayerHuman(s32);s32 func_ov000_021a98e4(u32);
s32 func_ov000_021a43c4(void);s32 func_ov000_021a88c8(s32);s32 CanKindAttack(u32,u32);
s32 func_ov000_0217d86c(void);void SelectAttackingUnit(void);
void SelectMapLayer(void*);void func_01ffada0(s32,s32,s32,s32,s32);void FillMapLayer(s32);
s32 func_ov000_021a8984(u32);s32 CanUnitAttackKind(u8*,u32);
s32 func_ov000_021a9084(u32);s32 func_ov000_021a911c(s16,s16,s16);
void PlanMoveDestination(s32,s32);
s32 bestX=-1,bestY=-1,best=32767,index,offset,found,distance;
u32 mode;u8 *unit;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16*,10)<<26)>>29)&4))return;
if(!IsPlayerHuman(M2C_FIELD(MAP,u16*,0x52a4))&&func_ov000_021a98e4(KIND(SEL))==1){
if(KIND(SEL)!=26)return;
if(!func_ov000_021a43c4()&&!func_ov000_021a88c8(24)&&!func_ov000_021a88c8(25))return;
}
if((u32)(SEL[11]<<24)>>31)return;
if(((u32)(M2C_FIELD(SEL,u16*,6)<<25)>>25)<61)return;
if(!CanKindAttack(24,KIND(SEL)))return;
if(func_ov000_0217d86c()==1)return;
SelectAttackingUnit();
mode=(u8)(func_ov000_021a98e4(KIND(SEL))==2);
M2C_FIELD(SEL,u16*,8)=(M2C_FIELD(SEL,u16*,8)&~0xc000)|0x8000;
if(!mode){
SelectMapLayer(MAP+0x3250);
func_01ffada0(SEL[1],SEL[2],KIND(SEL),110,0);
SelectMapLayer(MAP+0x1e30);
}
SelectMapLayer(MAP+0x2338);FillMapLayer(127);SelectMapLayer(MAP+0x1e30);
found=0;
index=gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+1;
if(index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51){offset=index*14;
for(;index<gPlayerUnitIdBase[M2C_FIELD(MAP,u16*,0x52a4)]+51;index++,offset+=14){
unit=(u8*)(MAP+0x59a4)+offset;
if(!KIND(unit)||!(INFO[KIND(unit)*112+19]&32)||func_ov000_021a8984((u32)(unit[11]<<28)>>28)||!CanUnitAttackKind(unit,KIND(SEL)))continue;
if(unit[12]){
if(mode==1)continue;
if(COST(unit[1],unit[2],0x3250)<0)continue;
}
func_01ffada0(unit[1],unit[2],KIND(unit),110,0);
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||!func_ov000_021a9084(CELL(x,y,0x1420)))continue;
{void *base=MAP;u16 row=M2C_FIELD(base+y*2,u16*,0x3758);u8 *cell=(u8*)base+x+row;
distance=M2C_FIELD(base+y*4,s8**,0x52e8)[x];
if(distance>=M2C_FIELD(cell,s8*,0x2338))continue;
if(!mode&&M2C_FIELD(cell,s8*,0x3250)<0)continue;
M2C_FIELD(cell+0x2000,s8*,0x338)=distance;found=1;}
}}
}
}
func_01ffada0(SEL[1],SEL[2],KIND(SEL),110,0);
if(!found){
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||(CELL(x,y,0x1420)&31)!=19||
!func_ov000_021a911c(M2C_FIELD(MAP,s16*,0x52a8),x,y))continue;
distance=PATH(x,y);if(best>=distance){bestX=x;bestY=y;best=distance;}
}}
if(bestX==-1)return;PlanMoveDestination(bestX,bestY);return;
}
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||!func_ov000_021a9084(CELL(x,y,0x1420)))continue;
distance=COST(x,y,0x2338);if(distance==127)continue;
distance+=PATH(x,y);if(best>=distance){bestX=x;bestY=y;best=distance;}
}}
if(bestX==-1)return;PlanMoveDestination(bestX,bestY);
}
#pragma pop
