/* 1 function from 0x02178778 to 0x02178E84 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern void *data_ov000_021df580;
typedef struct Bits787 {u8 low:6;u8 rest:2;} Bits787;
typedef struct Bit2787 {u8 low:2;u8 bit:1;u8 rest:5;} Bit2787;
typedef struct Bit7787 {u8 low:7;u8 bit:1;} Bit7787;
typedef struct Mode787 {u16 low:3;u16 mode:3;u16 rest:10;} Mode787;
extern u8 data_ov000_021b5bfc[];
static inline s32 Distance787(s32 x,s32 xx,s32 y,s32 yy){s32 v; s32 n=0; v=x-xx; if(v>0)n+=v;else n+=xx-x;v=y-yy;if(v>0)n+=v;else n+=yy-y;return n;}
static inline s32 Min787(s32 a,s32 b){if(a<b)b=a;return b;}
static inline s32 Max787(s32 a,s32 b){if(a<b)a=b;return a;}
static inline void *Map787(void){return *gCurrentMap;}
static inline u8 Cell787(s32 x,s32 y){void *m=Map787();u8 *p=(u8 *)m+x;u16 row=M2C_FIELD((u8 *)m+y*2,u16 *,0x3758);return p[row];}
static inline void *Unit787(s32 id){return (u8 *)Map787()+0x59a4+id*14;}
static inline void *Selected787(void){return M2C_FIELD(Map787(),void **,0x52d0);}
static inline u8 Kind787(void *u){return M2C_FIELD(u,Bits787 *,0).low;}

#pragma opt_strength_reduction off
s32 func_ov000_02178778(s32 x,s32 y){
s32 func_ov000_021a9084(s32);s32 func_020d27c0(s32);s32 func_ov000_021a9d8c(s16,s16);s32 func_ov000_021a8fc0(s16);s32 func_ov000_021a98e4(s32);s32 func_ov000_021a98a8(s32);
s32 left,top,right,bottom,xx,yy,id,count;void *m,*u,*sel; s32 found;u32 attr;
if(M2C_FIELD(data_ov000_021df580,Mode787 *,10).mode&4){s32 left,top,right,bottom,xx,yy,id;
left=Max787(x-1,0);top=Max787(y-1,0);m=Map787();right=Min787(x+1,M2C_FIELD(m,u16 *,0x5144)-1);bottom=Min787(y+1,M2C_FIELD(m,u16 *,0x5146)-1);
for(yy=top;yy<=bottom;yy++)for(xx=left;xx<=right;xx++){
{s32 dist=Distance787(x,xx,y,yy);if(dist<1)continue;if(dist>1)continue;
m=Map787();if(func_ov000_021a9084(M2C_FIELD((u8 *)m+xx+M2C_FIELD((u8 *)m+yy*2,u16 *,0x3758),u8 *,0x1420))!=0){
id=Cell787(xx,yy);if(id!=0 && func_020d27c0(id)!=0 && ((u32)(M2C_FIELD(Unit787(id),u16 *,8)<<16)>>30)==2)return 1;
}}}
}
count=0;left=Max787(x-1,0);top=Max787(y-1,0);m=Map787();right=Min787(x+1,M2C_FIELD(m,u16 *,0x5144)-1);bottom=Min787(y+1,M2C_FIELD(m,u16 *,0x5146)-1);
for(yy=top;yy<=bottom;yy++){for(xx=left;xx<=right;xx++){
{s32 dist=Distance787(x,xx,y,yy);if(dist<1)continue;if(dist>1)continue;
m=Map787();u=(u8 *)m+xx;{u16 row=M2C_FIELD((u8 *)m+yy*2,u16 *,0x3758);sel=(u8 *)u+row;id=M2C_FIELD(u,u8 *,row);}
if((id!=0 || (M2C_FIELD(data_ov000_021df580,Bit2787 *,7).bit==0 && (M2C_FIELD(sel,u8 *,0x539c)&127)!=0)) && func_020d27c0(id)!=1){
s16 cx=(s16)xx,cy=(s16)yy;
s32 l=Max787(cx-1,0),t=((cy-1)<0?0:cy-1),r=Min787(cx+1,M2C_FIELD(Map787(),u16 *,0x5144)-1),b=Min787(cy+1,M2C_FIELD(Map787(),u16 *,0x5146)-1),ix,iy;
for(iy=t;iy<=b;iy++)for(ix=l;ix<=r;ix++){
s32 dist=Distance787(cx,ix,cy,iy);if(dist<1)continue;if(dist>1)continue;if( M2C_FIELD(M2C_FIELD((u8 *)Map787()+iy*4,s8 **,0x52e8),s8 *,ix)>=0 && func_ov000_021a9d8c((s16)ix,(s16)iy)==0)count++;
}
if(count==1)goto escape;
count=0;
}}}}
escape:
if(count==0)return 0;
found=0;left=Max787(x-4,0);top=Max787(y-4,0);m=Map787();right=Min787(x+4,M2C_FIELD(m,u16 *,0x5144)-1);bottom=Min787(y+4,M2C_FIELD(m,u16 *,0x5146)-1);
for(yy=top;yy<=bottom;yy++)for(xx=left;xx<=right;xx++){
s32 distance=Distance787(x,xx,y,yy);
if(distance>=1 && distance<=4){
id=Cell787(xx,yy);if(id!=0){m=Map787();sel=M2C_FIELD(m,void **,0x52d0);
if( (xx!=M2C_FIELD(sel,u8 *,1) || yy!=M2C_FIELD(sel,u8 *,2)) && func_ov000_021a8fc0((s16)id)!=0){
u=Unit787(id);if((M2C_FIELD(u,u16 *,4)&1)==0){
sel=Selected787();
if((x==M2C_FIELD(sel,u8 *,1) && y==M2C_FIELD(sel,u8 *,2)) || (M2C_FIELD(u,Bit7787 *,10).bit==0)){
if(func_ov000_021a98e4(Kind787(u))==0){
attr=data_ov000_021b5bfc[Kind787(Selected787())*112+19];
if(attr&7){if(data_ov000_021b5bfc[Kind787(u)*112+19]&7)goto compatible;else goto next_tile;}
else {if(!(attr&32) || !(data_ov000_021b5bfc[Kind787(u)*112+19]&32))continue;}
compatible:if(func_ov000_021a98a8(Kind787(u))==0){found=1;goto done;}
}}}}}}next_tile:;}
done:return (u8)(found!=0);
}
#pragma opt_strength_reduction reset
