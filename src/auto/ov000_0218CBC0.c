/* 5 functions from 0x0218CBC0 to 0x0218D908 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0218cfec(void) {
    M2C_UNK func_ov000_0218bbd0(M2C_UNK);
    M2C_UNK func_ov000_0218cbc0();
    s32 func_ov000_021a98e4(u32);
    extern void **data_027e0058;
    s32 temp_r0;

    temp_r0 = func_ov000_021a98e4((u32) (*M2C_FIELD(*data_027e0058, u8 **, 0x52D0) << 0x1A) >> 0x1A);
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_ov000_0218cbc0();
        return;
    case 1:
        func_ov000_0218bbd0(0);
        return;
    }
}

s32 func_ov000_0218d40c(void){
extern void **data_027e0058; extern u8 data_ov000_021b5c0a[],data_ov000_021b5c05[];
u8 *p=M2C_FIELD(*data_027e0058,u8 **,0x52D0); u32 type;
if(((u32)(M2C_FIELD(p,volatile u16 *,6)<<25)>>25)<=90)return 1;
type=(u32)(p[0]<<26)>>26;
if((s32)((u32)(p[10]<<25)>>25)<(s32)data_ov000_021b5c0a[type*112]>>1){
if(type!=1 && type!=2)return 1;
}
if(data_ov000_021b5c05[type*112]>=6U && ((u32)(M2C_FIELD(p,volatile u16 *,6)<<21)>>28)<=3)return 1;
return 0;
}

