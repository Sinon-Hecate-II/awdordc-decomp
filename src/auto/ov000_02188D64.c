/* 4 functions from 0x02188D64 to 0x02189A08 (ov000), found by ds-decomp. */
#include "common.h"


void func_ov000_02188d64(void) {
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_ov000_02189000(s32 x,s32 y,s16 *out) {
extern void **gCurrentMap;
extern u8 data_ov000_021b5bfc[];
s32 func_ov000_021a9084(s32); s32 func_ov000_021a8fc0(s16); s32 func_ov000_021a98e4(s32);
s32 sy; s32 ndy,minx,maxy;
register s32 id,dy,j,i,maxx;
s32 dist,kind,cost,zero,adx;
void *base;
out[0]=0x270f;
minx=x-1;
if(minx<0)minx=0;
i=y-1;
if(i<0)i=0;
base=*gCurrentMap;
maxx=M2C_FIELD(base,u16*,0x5144)-1;
if(x+1<maxx)maxx=x+1;
maxy=M2C_FIELD(base,u16*,0x5146)-1;
if(y+1<maxy)maxy=y+1;
for(;i<=maxy;i++){
j=minx;
if(j<=maxx){
dy=y-i;ndy=i-y;sy=i;
do {
dist=0;
adx=x-j;
if(adx>0)dist=adx+dist;else dist=(j-x)+dist;
if(dy>0)dist=dist+dy;else dist=dist+ndy;
if(dist>=1&&dist<=1){
base=*gCurrentMap;
cost=M2C_FIELD(M2C_FIELD(base+i*4,s8**,0x52e8),s8*,j);
if(cost>=0&&cost<=110){
if(func_ov000_021a9084(M2C_FIELD(base+j+M2C_FIELD(base+i*2,u16*,0x3758),u8*,0x1420))){
base=*gCurrentMap;
id=M2C_FIELD(base+j,u8*,M2C_FIELD(base+i*2,u16*,0x3758));
if(id){
if(!func_ov000_021a8fc0((s16)id))goto next;

base=*gCurrentMap;
kind=(u32)(M2C_FIELD(base+id*14,u8*,0x59a4)<<26)>>26;
if((data_ov000_021b5bfc[kind*112+19]&7)||func_ov000_021a98e4(kind)==1)goto next;
}
{
if(out[0]==0x270f||M2C_FIELD(M2C_FIELD(*gCurrentMap+i*4,s8**,0x52e8),s8*,j)<=M2C_FIELD(M2C_FIELD(*gCurrentMap+out[1]*4,s8**,0x52e8),s8*,out[0])){
out[0]=j;out[1]=(s16)sy;
}
}
}
}
}
next:
j++;
}while(j<=maxx);
}
}
if(out[0]==0x270f)return 0;return 1;
}
#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_ov000_02189248(u8 *arg0,s16 *out) {
extern void **gCurrentMap;
extern u8 *data_ov000_021df580;
extern u8 data_ov000_021b5bfc[];
s32 func_020a33c4(s32); s32 func_020a7b3c(s32,s32,s32,s32);
void func_01ffb554(void *); void func_01ffc328(void *);
s32 func_ov000_021a9084(s32); s32 func_ov000_021a9d8c(s16,s16);
s32 func_ov000_021a8fc0(s16); s32 func_ov000_021a98e4(s32);
s32 sy,bestScore,score,bestCost,y,x;
s32 bestX,bestY,kind,terrain,attr;
volatile s32 id;
s8 *costRow;
u8 *selp;
void *map;
bestScore=0x7fff;
bestCost=bestScore;
score=func_020a7b3c((u32)(arg0[0]<<26)>>26,M2C_FIELD(data_ov000_021df580,u8*,0xc),M2C_FIELD(*gCurrentMap,u16*,0x52a4),func_020a33c4(M2C_FIELD(*gCurrentMap,u16*,0x52a4)));
func_01ffb554((u8*)*gCurrentMap+0x2338);
func_01ffc328(arg0);
func_01ffb554((u8*)*gCurrentMap+0x1e30);
bestX=0x270f;
out[0]=0x270f;
y=0;
map=*gCurrentMap;
while(y<M2C_FIELD(map,u16*,0x5146)){
 x=0;
 if(x<M2C_FIELD(map,u16*,0x5144)){
  sy=(s16)y;
  do{
   costRow=M2C_FIELD((u8*)map+y*4,s8**,0x52e8);
   if(costRow[x]<0)goto nextTile;
   if(M2C_FIELD((u8*)map+x+M2C_FIELD((u8*)map+y*2,u16*,0x3758),s8*,0x2338)<0)goto nextTile;
   if(!func_ov000_021a9084(M2C_FIELD((u8*)map+x+M2C_FIELD((u8*)map+y*2,u16*,0x3758),u8*,0x1420)))goto nextTile;
   if(func_ov000_021a9d8c((s16)x,sy)){
    map=*gCurrentMap;
    id=M2C_FIELD((u8*)map+x,u8*,M2C_FIELD((u8*)map+y*2,u16*,0x3758));
    if(func_ov000_021a8fc0(id)){
     map=*gCurrentMap;
     kind=(u32)(M2C_FIELD((u8*)map+id*14,u8*,0x59a4)<<26)>>26;
     if((data_ov000_021b5bfc[kind*112+19]&7)==0&&func_ov000_021a98e4(kind)!=1){
      if(M2C_FIELD((u8*)*gCurrentMap+y*4,s8**,0x52e8)[x]<=bestCost){
       bestY=sy;bestX=x;
       bestCost=M2C_FIELD((u8*)*gCurrentMap+y*4,s8**,0x52e8)[x];
      }
     }
    }
   }else{
    map=*gCurrentMap;
    terrain=M2C_FIELD((u8*)map+x+M2C_FIELD((u8*)map+y*2,u16*,0x3758),u8*,0x1420)&0x1f;
    if(terrain==0x13||terrain==0x15){
     selp=M2C_FIELD(map,u8**,0x52d0);
     kind=(u32)(selp[0]<<26)>>26;
     if((s32)M2C_FIELD(data_ov000_021b5bfc+kind*112,u8*,0xe)>(s32)(((u32)(M2C_FIELD(selp,u8*,0xa)<<25)>>25))+0x14){
      if(M2C_FIELD((u8*)*gCurrentMap+y*4,s8**,0x52e8)[x]<=bestScore){
       out[0]=(s16)x;out[1]=sy;
       bestScore=M2C_FIELD((u8*)*gCurrentMap+y*4,s8**,0x52e8)[x];
      }
      goto nextTile;
     }
    }
    if(score+M2C_FIELD((u8*)*gCurrentMap+y*4,s8**,0x52e8)[x]<=bestScore){
     out[0]=(s16)x;out[1]=sy;
     bestScore=score+M2C_FIELD((u8*)*gCurrentMap+y*4,s8**,0x52e8)[x];
    }
   }
  nextTile:
   x++;
   map=*gCurrentMap;
  }while(x<M2C_FIELD(map,u16*,0x5144));
 }
 y++;
}
if(out[0]==0x270f){
 if(bestY==0x270f)return 0;
}
out[0]=(s16)bestX;out[1]=(s16)bestY;
return 1;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
M2C_UNK func_ov000_021895bc(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d) { return 0; }

