/* 9 functions from 0x0217BCD4 to 0x0217C9F4 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_0217bcf4(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_0217abd8(s32, s32, s32);
    s32 func_ov000_0217b8f0(s32, s32, s32, s32);
    extern s32 (*data_ov000_021df650)(s32, s32, s32);

    data_ov000_021df650 = func_ov000_0217abd8;
    if (data_ov000_021df650(arg0, arg1, 0) == 1) {
        return 1;
    }
    return func_ov000_0217b8f0(arg0, arg1, 0, arg2);
}

s32 func_ov000_0217bd44(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern void **gCurrentMap;
    u8 temp_lr;
    void *temp_r4;

    temp_r4 = *gCurrentMap;
    temp_lr = M2C_FIELD((temp_r4 + (arg2 + M2C_FIELD((temp_r4 + (arg3 * 2)), u16 *, 0x3758))), u8 *, 0x508);
    if ((temp_lr != 0) && (M2C_FIELD(temp_r4, u8 *, 0x52D4) != temp_lr)) {
        return 5;
    }
    if (arg0 > arg2) {
        return 4;
    }
    if (arg0 < arg2) {
        return 2;
    }
    if (arg1 > arg3) {
        return 1;
    }
    if (arg1 < arg3) {
        return 3;
    }
    return 0;
}

s32 func_ov000_0217c2d4(u8 *arg0) {
    s32 func_01ffada0(s32, s32, s32, s32, s32);
    s32 func_ov000_021a9860(s32, s32);
    extern void **gCurrentMap;
    s32 x;
    s32 y;
    void *base;

    func_01ffada0(arg0[1], arg0[2], (arg0[0] << 26) >> 26, 0x6e, 0);

    base = *gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, 0x5146); y++) {
        for (x = y; x < M2C_FIELD(base, u16 *, 0x5144); x++) {
            if ((((s8 **)((u8 *)base + 0x52e8))[y])[x] >= 0) {
                if (func_ov000_021a9860(x, y) == 1) {
                    return 1;
                }
            }
            base = *gCurrentMap;
        }
        base = *gCurrentMap;
    }
    return 0;
}

