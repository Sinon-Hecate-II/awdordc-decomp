/* 4 functions from 0x02188D64 to 0x02189A08 (ov000), found by ds-decomp. */
#include "common.h"


void func_ov000_02188d64(void){
extern void **gCurrentMap;extern u8 *data_ov000_021df580;
s32 func_ov000_021a98a8(s32);s32 func_ov000_021a9c28(void);s32 func_020d243c(u16);
void func_ov000_02188370(void);void func_ov000_021884e4(void);void func_ov000_02188688(void);void func_ov000_02188790(void);void func_ov000_021888ec(void);void func_ov000_02188a38(void);
u8 *p,*unit;u8 id,tmp;
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
id=p[13];
if(id && func_ov000_021a98a8((u32)(M2C_FIELD((u8 *)*gCurrentMap+id*14,u8 *,0x59a4)<<26)>>26) &&
!func_ov000_021a98a8((u32)(M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u8 **,0x52d0)[12]*14,u8 *,0x59a4)<<26)>>26)){
{u8 *p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);u8 tmp=p[12];p[12]=p[13];M2C_FIELD(*gCurrentMap,u8 **,0x52d0)[13]=tmp;}
M2C_FIELD(data_ov000_021df580,u16 *,8)|=64;
}
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
id=p[12];
unit=(u8 *)*gCurrentMap+0x59a4+(s16)id*14;
if(((u32)(unit[0]<<26)>>26)==13 && p[13]){
p[12]=p[13];
M2C_FIELD(*gCurrentMap,u8 **,0x52d0)[13]=id;
unit=(u8 *)*gCurrentMap+0x59a4+M2C_FIELD(*gCurrentMap,u8 **,0x52d0)[12]*14;
M2C_FIELD(data_ov000_021df580,u16 *,8)|=64;
}
if(func_ov000_021a98a8((u32)(unit[0]<<26)>>26) || ((u32)(unit[0]<<26)>>26)==13)func_ov000_02188370();
else switch((u32)(unit[11]<<28)>>28){
case 0:case 1:func_ov000_021884e4();break;
case 2:if(func_ov000_021a9c28()==1)func_ov000_02188688();else func_ov000_021884e4();break;
case 3:case 4:func_ov000_02188790();break;
case 5:if(func_020d243c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))==1)func_ov000_021888ec();else func_ov000_02188790();break;
case 7:case 8:case 9:func_ov000_02188a38();break;
}
if(M2C_FIELD(data_ov000_021df580,u16 *,8)&64){
{u8 *p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);u8 tmp=p[12];p[12]=p[13];M2C_FIELD(*gCurrentMap,u8 **,0x52d0)[13]=tmp;}
M2C_FIELD(data_ov000_021df580,u16 *,8)&=~64;
}
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
register s32 sy,bestScore,score,y,x,bestCost;
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
#pragma opt_common_subs off
#pragma opt_strength_reduction on
void func_ov000_021895bc(void){
 extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 data_ov000_021df7e4[];extern u8 *data_ov000_021df580;
 void func_01ffada0();void func_01ffb9c4();s32 func_ov000_021a9934();s32 func_0207c8ec();s32 func_ov000_021a8fc0(s16);s32 func_ov000_02189248(u8 *,s16 *);void SetMapCursor();void PlanMoveDestination();void func_ov000_02189a08();
 s32 bestx,besty,best,index,offset,minx,maxy; s16 out[2];
 register s32 zero;register u8 *other;register s32 score,x;register u8 *unit;register s32 y,maxx;void *map,*tile;s32 n,dx,dy,dist,ux,uy;
 bestx=-1;besty=bestx;best=bestx+0x8000;
 unit=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
 func_01ffada0(unit[1],unit[2],(u32)(unit[0]<<26)>>26,110,1);
 func_01ffb9c4(111);
 map=*gCurrentMap;
 index=gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+1;
 if(index<gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+51){offset=index*14;do{
 unit=(u8 *)map+0x59a4+offset;
 n=(u32)(unit[0]<<26)>>26;if(!n)goto next;
 if(M2C_FIELD(unit,u16 *,4)&8)goto next;
 if(M2C_FIELD(M2C_FIELD(map+unit[2]*4,s8 **,0x52e8),s8 *,unit[1])<0)goto next;
 if(!func_ov000_021a9934((u32)(M2C_FIELD(map,u8 **,0x52d0)[0]<<26)>>26,n))goto next;
 if((u32)(M2C_FIELD(unit,u16 *,8)<<16)>>30!=2)goto next;
 if(data_ov000_021df7e4[index&63])goto next;
 if(!func_ov000_02189000(unit[1],unit[2],out))goto next;
 score=(func_0207c8ec(M2C_FIELD(M2C_FIELD(*gCurrentMap+out[1]*4,s8 **,0x52e8),s8 *,out[0]),data_ov000_021df580[5])+1)<<7;
 ux=unit[1];uy=unit[2];minx=ux-4;if(minx<0)minx=0;
 y=uy-4;if(y<0)y=0;
 map=*gCurrentMap;
 maxx=M2C_FIELD(map,u16 *,0x5144)-1;if(ux+4<maxx)maxx=ux+4;
 maxy=M2C_FIELD(map,u16 *,0x5146)-1;if(uy+4<maxy)maxy=uy+4;
 for(;y<=maxy;y++){
 x=minx;if(x<=maxx){do{
 dist=0;dist+=(unit[1]-x>0)?unit[1]-x:x-unit[1];dist+=(unit[2]-y>0)?unit[2]-y:y-unit[2];
 if(dist>=0&&dist<=4){
 map=*gCurrentMap;n=M2C_FIELD(map+y*2,u16 *,0x3758);tile=map+x+n;n=M2C_FIELD(map+x,u8 *,n);
 other=(u8 *)map+0x59a4+(s16)n*14;
 if(((u32)(other[0]<<26)>>26)&&func_ov000_021a8fc0(M2C_FIELD(tile,u8 *,0x508))){
 if((u32)(M2C_FIELD(other,u16 *,8)<<16)>>30==2)score--;
 }
 }
 x++;}while(x<=maxx);}
 }
 if(best>=score){best=score;bestx=unit[1];besty=unit[2];}
 next:index++;offset+=14;map=*gCurrentMap;
 }while(index<gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+51); }
 if(bestx!=-1){
 unit=(u8 *)map+0x59a4+M2C_FIELD(map,u8 *,bestx+M2C_FIELD(map+besty*2,u16 *,0x3758))*14;
 if(func_ov000_02189248(unit,out)==1){
 map=*gCurrentMap;
 n=M2C_FIELD(map,u8 *,bestx+M2C_FIELD(map+besty*2,u16 *,0x3758));
 data_ov000_021df7e4[n&63]++;
 ux=out[0];uy=out[1];map=*gCurrentMap;
 if(M2C_FIELD(map,u8 *,ux+M2C_FIELD(map+uy*2,u16 *,0x3758))==0&&M2C_FIELD(M2C_FIELD(map+uy*4,s8 **,0x52e8),s8 *,ux)<=data_ov000_021df580[5]){
 SetMapCursor(ux,uy,2,0,0);return;
 }
 PlanMoveDestination(ux,uy);return;
 }
 }
 func_ov000_02189a08();
}
