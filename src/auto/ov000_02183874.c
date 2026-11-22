/* 1 function from 0x02183874 to 0x021843EC (ov000), found by ds-decomp. */
#include "common.h"

extern void **gCurrentMap;
extern u8 data_ov000_021dfb04[],data_ov000_021dfa60[],gUnitKindStats[];
extern u16 gPlayerUnitIdBase[];
s32 GetUnitAttackClass(u32);
s32 IsMobileIndirectUnitKind(u32);
s32 GetUnitDamagePercent(u32,s32);
s32 GetUnitMaxAttackRange();
static inline s32 UnitIndex83874(u8 *p) { if(p==0)return 0;return (s32)(p-((u8 *)*gCurrentMap+0x59a4))/14; }
static inline s32 UnitOwner83874(u8 *p) { if(p!=0)return (UnitIndex83874(p)>>6)+1;return 0; }
static inline s32 Distance83874(s32 x,s32 y,s32 xx,s32 yy) { s32 d=0;if(x-xx>0)d+=x-xx;else d+=xx-x;if(y-yy>0)d+=y-yy;else d+=yy-y;return d; }
#pragma opt_common_subs off
#pragma opt_propagation off
void MarkAiUnitAttackCells(void) {
s32 i,left,top,right,bottom,x,y,dx,dy,dist;u32 idx;u8 *p,*bounds,*map;
MI_CpuFill8(data_ov000_021dfb04,0,0xa1);
MI_CpuFill8(data_ov000_021dfa60,0,0xa1);
map=*gCurrentMap;
for(i=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;(map=*gCurrentMap),i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++){
p=map+0x59a4+i*14;
if(!((u32)(p[0]<<26)>>26))continue;
if(!(M2C_FIELD(p,u16 *,4)&1))continue;
if(M2C_FIELD(p,u16 *,4)&8)continue;
if(GetUnitAttackClass((u32)(p[0]<<26)>>26)!=1)continue;
if(IsMobileIndirectUnitKind((u32)(p[0]<<26)>>26))continue;
if(((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<80)continue;
if(GetUnitDamagePercent((u32)(p[0]<<26)>>26,7)){
if(p[1]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1<0)left=0;else left=p[1]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
if(p[2]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1<0)top=0;else top=p[2]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
bounds=(u8 *)*gCurrentMap+0x5120;
if(p[1]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1>=M2C_FIELD(bounds,u16 *,36)-1)right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;else right=p[1]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
bounds=(u8 *)*gCurrentMap+0x5120;
if(p[2]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1>=M2C_FIELD(bounds,u16 *,38)-1)bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;else bottom=p[2]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
for(y=top;y<=bottom;y++)for(x=left;x<=right;x++){
dist=Distance83874(p[1],p[2],x,y);
if(dist<(gUnitKindStats[((u32)(p[0]<<26)>>26)*112+12]<=2?2:gUnitKindStats[((u32)(p[0]<<26)>>26)*112+12]))continue;
if(dist>GetUnitMaxAttackRange(UnitOwner83874(p)-1)-1)continue;
idx=y*M2C_FIELD(*gCurrentMap,u16 *,0x5144)+x;
data_ov000_021dfb04[idx>>3]|=1<<(idx&7);
}}
else {
if(p[1]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1<0)left=0;else left=p[1]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
if(p[2]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1<0)top=0;else top=p[2]-GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
bounds=(u8 *)*gCurrentMap+0x5120;
if(p[1]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1>=M2C_FIELD(bounds,u16 *,36)-1)right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;else right=p[1]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
bounds=(u8 *)*gCurrentMap+0x5120;
if(p[2]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1>=M2C_FIELD(bounds,u16 *,38)-1)bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;else bottom=p[2]+GetUnitMaxAttackRange(UnitOwner83874(p)-1,(u32)(p[0]<<26)>>26)-1;
for(y=top;y<=bottom;y++)for(x=left;x<=right;x++){
dist=Distance83874(p[1],p[2],x,y);
if(dist<(gUnitKindStats[((u32)(p[0]<<26)>>26)*112+12]<=2?2:gUnitKindStats[((u32)(p[0]<<26)>>26)*112+12]))continue;
if(dist>GetUnitMaxAttackRange(UnitOwner83874(p)-1)-1)continue;
idx=y*M2C_FIELD(*gCurrentMap,u16 *,0x5144)+x;
data_ov000_021dfa60[idx>>3]|=1<<(idx&7);
}}
}}
