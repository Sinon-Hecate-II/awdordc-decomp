/* 6 functions from 0x02177CE0 to 0x02178778 (ov000), found by ds-decomp. */
#include "common.h"

u8 func_ov000_021786a8(s16 *out) {
s32 func_020d1938(s32); s32 func_020d243c(s32); s32 func_020d273c(u16,s32);
extern void **data_027e0058;
s32 best=0x7fff,i,offset,x,y,v;
void *base,*entry;
for(i=1,offset=0x8c;i<5;i++,offset+=0x8c) {
if(func_020d1938(i) && !func_020d273c(M2C_FIELD(*data_027e0058,u16*,0x52a4),i) && func_020d243c(i)) {
base=*data_027e0058;entry=(u8*)base+offset;
x=M2C_FIELD(entry,u8*,0x67cf)&127;
y=M2C_FIELD(entry,u8*,0x67d0)&127;
v=M2C_FIELD(M2C_FIELD((u8*)base+y*4,s8**,0x52e8),s8*,x);
if(v>=0 && v<=best){out[0]=x;best=v;out[1]=y;}
}
}
return best!=0x7fff;
}
