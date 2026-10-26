/* 4 functions from 0x02192D88 to 0x02193D6C (ov000), found by ds-decomp. */
#include "common.h"

u32 func_ov000_02193998(void) {
extern void **data_027e0058;
u16 flags;
u32 x;
u8 *p;
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
x=(u32)(p[0]<<26)>>26; if(x!=13)return x;
flags=*(u16 *)(p+6);
x=(u32)(flags<<21)>>28;
if(x==0)return flags;
x=(u32)(flags<<16)>>27;
if(x==0)return x;
x=func_020cccdc(); if(!x)return x;
{s32 v=func_ov000_021a8b78(M2C_FIELD(*data_027e0058,void **,0x52d0));if(v>=3)return v;}
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
return func_ov000_02199d74(p[1],p[2],24,0,0);
}
