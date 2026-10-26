/* 12 functions from 0x01FFADA0 to 0x01FFBD90 (itcm), found by ds-decomp. */
#include "common.h"

typedef struct UnkB454Bits { u32 value : 8; u32 rest : 24; } UnkB454Bits;

void func_01ffb3d0(s8 arg0) {
extern void **data_027e0058;
s32 y=0,x; void *base=*data_027e0058;
for(;y<M2C_FIELD(base,u16 *,0x5146);y++) {
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++) {
((s8 **)base)[y+0x14ba][x]=arg0;
base=*data_027e0058;
}
}
}

void func_01ffb454(s32 arg0) {
extern u8 data_ov000_021b5bfc[]; extern u8 data_0212616c[]; extern s8 *data_027e00cc; extern void **data_027e0058; extern u8 data_02168f08[];
s32 func_020a33c4(s32);
s32 i; u8 *unit=data_ov000_021b5bfc+arg0*0x70;
for(i=0;i<32;i++) {
void *base=*data_027e0058;
s32 index=M2C_FIELD(base,u16 *,0x52b6);
u8 *entry=(u8 *)base+0x67a4+index*0x8c;
u32 variant;
s32 type;
s8 *table;
variant=(u32)(M2C_FIELD(data_02168f08,u16 *,12)<<18)>>31; if(variant) variant=((UnkB454Bits *)(entry+0x6c))->value;
type=func_020a33c4(index);
table=M2C_FIELD(data_0212616c+variant*0x9c+type*0x28+entry[0x25]*4,s8 **,0x64);
data_027e00cc[i]=(table+unit[0x12]*32)[i];
}
}

void func_01ffb50c(void) {
extern s8 data_ov000_021b54e0[]; extern s8 *data_027e00cc;
s32 i; s8 *p=data_ov000_021b54e0;
i=0; do { s32 value=*(p++); if(value) data_027e00cc[i]=1; else ((u8 *)data_027e00cc)[i]=255; i++; } while(i<32);
}

void func_01ffb554(s32 arg0) {
extern void **data_027e0058; extern s8 *data_027e00cc;
s32 i=0; void *base=*data_027e0058;
for(;i<M2C_FIELD(base,u16 *,0x5146);i++) {
((s32 *)base)[i+0x14ba]=arg0+((u16 *)base)[i+0x1bac];
base=*data_027e0058;
}
data_027e00cc[0x24]=M2C_FIELD(base,u16 *,0x5144);
data_027e00cc[0x25]=M2C_FIELD(*data_027e0058,u16 *,0x5146);
}

void func_01ffb734(int cx,int cy,int radius,s8 value) {
 extern void **data_027e0058;
 int x,d,right,bottom,left,top; void *base=*data_027e0058;
 left=cx-radius;if(left<0)left=0;top=cy-radius;if(top<0)top=0;
 right=M2C_FIELD(base,u16 *,0x5144)-1;if(cx+radius<right)right=cx+radius;
 bottom=M2C_FIELD(base,u16 *,0x5146)-1;if(cy+radius<bottom)bottom=cy+radius;
 for(;top<=bottom;top++)for(x=left;x<=right;x++){
 d=0;
 if(cx-x>0)d+=cx-x;else d+=x-cx;
 if(cy-top>0)d+=cy-top;else d+=top-cy;
 if(d>=0 && d<=radius)((s8 **)*data_027e0058)[top+0x14ba][x]=value;
 }
}

void func_01ffb918(s32 arg0,s32 arg1,s32 arg2,s8 arg3,u8 arg4) {
extern void **data_027e0058;
s32 radius=1,left,y,x; void *base;
if(arg4) radius+=2;
left=arg0-radius; arg2=arg0+radius;
if(left<0) left=0;
base=*data_027e0058;
if(arg2>M2C_FIELD(base,u16 *,0x5144)-1) arg2=M2C_FIELD(base,u16 *,0x5144)-1;
for(arg0=0;arg0<M2C_FIELD(base,u16 *,0x5146);arg0++) {
for(x=left;x<=arg2;x++) {
((s8 **)*data_027e0058)[arg0+0x14ba][x]=arg3;
}
base=*data_027e0058;
}
}

