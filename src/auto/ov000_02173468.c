/* 6 functions from 0x02173468 to 0x021743F0 (ov000), found by ds-decomp. */
#include "common.h"

u8 func_ov000_02173e6c(void *arg0) {
    s32 func_020d46e8();
    s32 func_020d4ea8();
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x14) == 0) {
        return 0U;
    }
    if (func_020d46e8() != 0) {
        return 0U;
    }
    if (func_020d4ea8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void *func_ov000_02173ea8(void *a){s32 p;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,8)=1;M2C_FIELD(a,s32 *,12)=0;M2C_FIELD(a,u8 *,16)=0;M2C_FIELD(a,u8 *,17)=1;M2C_FIELD(a,u8 *,18)=0;M2C_FIELD(a,u8 *,19)=0;M2C_FIELD(a,u8 *,20)=0;M2C_FIELD(a,s16 *,22)=-1;M2C_FIELD(a,s16 *,24)=-1;M2C_FIELD(a,u8 *,26)=255;p=func_02082028(20);if(p)p=func_ov000_02175088(p);M2C_FIELD(a,s32 *,0)=p;p=func_02082028(28);if(p)p=func_ov000_021724dc(p);M2C_FIELD(a,s32 *,4)=p;M2C_FIELD(a,s32 *,28)=func_020e31e0();return a;}

void *func_ov000_02173f30(void *arg0) {
    M2C_UNK func_02082040(s32);
    M2C_UNK func_ov000_021725c8(s32);
    M2C_UNK func_ov000_0217519c(s32);
    s32 temp_r4;
    s32 temp_r4_2;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r4 != 0) {
        func_ov000_0217519c(temp_r4);
        func_02082040(temp_r4);
    }
    temp_r4_2 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r4_2 != 0) {
        func_ov000_021725c8(temp_r4_2);
        func_02082040(temp_r4_2);
    }
    return arg0;
}

void func_ov000_021743ec(void) {

}
