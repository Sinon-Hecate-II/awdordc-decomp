/* 7 functions from 0x02185360 to 0x021862E8 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u8 data_ov000_021e0550[];
extern u8 data_ov000_021e0f60[];

void func_ov000_02185360(s32 x,s32 y,s32 unit,s32 radius){
s32 left,xx,yy,right,bottom,top,dist;
s32 func_020ce0ec(u8,u8);
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(y+radius<bottom)bottom=y+radius;
for(yy=top;yy<=bottom;yy++){
xx=left; while(xx<=right){
dist=0;
if(x-xx>0)dist+=x-xx;else dist+=xx-x;
if(y-yy>0)dist+=y-yy;else dist+=yy-y;
if(dist>=0 && dist<=radius){
if(dist<=1 || !func_020ce0ec(unit,M2C_FIELD((u8 *)*gCurrentMap+xx+((u16 *)*gCurrentMap)[yy+0x1bac],u8 *,0x1420)))data_ov000_021e0f60[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=1;
}
xx++;
}
}
}

void func_ov000_021854e0(s32 x,s32 y,s32 radius,s32 offset){
s32 left,right,xx,yy,bottom,top,dist;
left=offset+(x-radius);if(left<0)left=0;
top=offset+(y-radius);if(top<0)top=0;
right=(offset+(x+radius)<M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1)?offset+(x+radius):M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;
bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;
if(offset+(y+radius)<bottom)bottom=offset+(y+radius);
for(yy=top;yy<=bottom;yy++){
xx=left; while(xx<=right){
dist=0;
if(x-xx>0)dist+=x-xx;else dist+=xx-x;
if(y-yy>0)dist+=y-yy;else dist+=yy-y;
if(dist>=0 && dist<=radius+offset)data_ov000_021e0550[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=255;
xx++;
}
}
}

s32 func_ov000_02185fb8(u8 *a,u8 *b,s32 c){
 s32 func_0206409c(s32); s32 func_ov000_021a97e0(s32,u32); extern void **gCurrentMap;
 s32 dist,n;
 dist=func_0206409c(a[1]-b[1]);
 dist+=func_0206409c(a[2]-b[2]);
 if(b){if(!b)n=0;else n=((s32)b-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;
 if(dist>c+(func_ov000_021a97e0(n,(u32)(b[0]<<26)>>26)+1))return 0;return 1;
}
