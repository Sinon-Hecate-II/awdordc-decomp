/* 9 functions from 0x0219694C to 0x02197814 (ov000), found by ds-decomp. */
#include "common.h"

u8 func_ov000_021973f8(void) {
    extern void **data_027e0058;
    void *temp_r3;
    u32 index;
    u8 result;
    temp_r3 = *data_027e0058;
    index = M2C_FIELD(temp_r3, u16 *, 0x52A4);
    result = M2C_FIELD((s32)temp_r3 + index * 0x8C, u8 *, 0x67CE) != 0;
    return result;
}

s32 func_ov000_02197434(s32 arg0, s32 arg1) {
    s32 func_ov000_021a97d0();
    s32 var_r0;

    var_r0 = func_ov000_021a97d0();
    if ((arg1 == 0xE) && (arg0 == 0xE)) {
        var_r0 = (s32) (var_r0 * 3) >> 1;
    }
    if ((arg1 == 0xE) && (arg0 == 6)) {
        var_r0 *= 2;
    }
    if ((arg1 == 6) && (arg0 == 0xF)) {
        var_r0 = var_r0 >> 1;
    }
    return var_r0;
}

s32 func_ov000_02197470(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0207c8ec(s32, s32);
    s32 func_020a8774(M2C_UNK);
    s32 func_020a87b0(M2C_UNK);
    s32 temp_r1;
    s32 temp_r4;
    s32 var_r6;

    var_r6 = arg0;
    temp_r4 = func_020a8774(arg2);
    temp_r1 = func_020a87b0(arg1);
    if ((temp_r4 == 0) && (temp_r1 == 0)) {

    } else {
        var_r6 = func_0207c8ec(var_r6 * (temp_r4 + 0x64), temp_r1 + 0x64);
    }
    return var_r6;
}

s32 func_ov000_0219763c(s32 arg0, void *arg1, s32 arg2) {
    s32 func_020a7558(void *);
    s32 func_ov000_021a9214(void *, u8, u8);
    s32 func_ov000_021a93a8(void *, u8, u8);
    s32 var_r0;
    s32 var_r4;

    var_r4 = arg2;
    if (func_ov000_021a93a8(arg1, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2)) == 1) {
        var_r4 += 0x14;
    }
    if (func_ov000_021a9214(arg1, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2)) == 1) {
        var_r4 += func_020a7558(arg1) * 0xA;
    }
    if (var_r4 >= 0x64) {
        var_r4 = 0x64;
    }
    var_r0 = func_0207c8ec(arg0 * var_r4, 0x64);
    if (var_r0 >= 0xFF) {
        var_r0 = 0xFF;
    }
    return var_r0;
}

