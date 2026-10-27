/* 3 functions from 0x021843EC to 0x02185360 (ov000), found by ds-decomp. */
#include "common.h"
static inline s32 Distance851B8(s32 x,s32 y,s32 xx,s32 yy) { s32 d=0;if(x-xx>0)d+=x-xx;else d+=xx-x;if(y-yy>0)d+=y-yy;else d+=yy-y;return d; }
typedef struct { u8 pad[0x3758];u16 rows[64];u8 pad2[0x196c];u16 width,height; } Map851B8;
static inline s32 Min851B8(s32 a,s32 b) { return b<a?b:a; }
static inline u8 Terrain851B8(s32 x,s32 y) { extern void **gCurrentMap;u8 *p=*gCurrentMap;return M2C_FIELD(p+x+M2C_FIELD(p+y*2,u16 *,0x3758),u8 *,0x1420); }

#pragma opt_common_subs off
void func_ov000_0218500c(s32 x,s32 y,s32 type,s32 radius){
extern void **gCurrentMap;extern u8 data_ov000_021e0550[];
s32 func_020ce0ec(u8,s32);
s32 xx;u8 *cell;s32 delta,yy,right,bottom,left,top,d;u8 *base;
left=x-radius;if(left<0)left=0;top=y-radius;if(top<0)top=0;
base=*gCurrentMap;right=((Map851B8 *)base)->width-1;if(x+radius<right)right=x+radius;
bottom=((Map851B8 *)base)->height-1;if(y+radius<bottom)bottom=y+radius;
for(yy=top;yy<=bottom;yy++){for(xx=left;xx<=right;xx++){cell=data_ov000_021e0550+xx;
d=0;if(x-xx>0)d+=x-xx;else d+=xx-x;
if(y-yy>0)d+=y-yy;else d+=yy-y;
if(d>=0&&d<=radius){
if(d!=0&&func_020ce0ec((u8)(type>>5),M2C_FIELD((u8 *)*gCurrentMap+xx+((Map851B8 *)*gCurrentMap)->rows[yy],u8 *,0x1420))){
cell[yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]|=0x80;
}else data_ov000_021e0550[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=255;
}
}}
}
#pragma opt_common_subs reset

void func_ov000_021851b8(s32 x,s32 y,s32 type,s32 radius){
extern void **gCurrentMap;extern u8 data_ov000_021e0550[];
s32 func_020ce0ec(u8,s32);
s32 xx,d,bottom,left,yy,top,right;u8 *base;
left=x-radius;if(left<0)left=0;top=y-radius;if(top<0)top=0;
base=*gCurrentMap;right=((Map851B8 *)base)->width-1;if(x+radius<right)right=x+radius;
bottom=((Map851B8 *)base)->height-1;if(y+radius<bottom)bottom=y+radius;
for(yy=top;yy<=bottom;yy++){for(xx=left;xx<=right;xx++){
d=0;if(x-xx>0)d+=x-xx;else d+=xx-x;
if(y-yy>0)d+=y-yy;else d+=yy-y;
if(d>=0&&d<=radius){
if(d>1&&func_020ce0ec((u8)type,M2C_FIELD((u8 *)*gCurrentMap+xx+((Map851B8 *)*gCurrentMap)->rows[yy],u8 *,0x1420))){
data_ov000_021e0550[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]|=0x80;
}else data_ov000_021e0550[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=255;
}
}}
}
#pragma opt_common_subs reset
