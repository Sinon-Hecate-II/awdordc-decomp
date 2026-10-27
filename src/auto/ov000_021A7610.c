/* 6 functions from 0x021A7610 to 0x021A860C (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_021a7e98(s32 arg0) {
    s32 func_020d2d18(u16, M2C_UNK);
    s32 func_ov000_021a6c8c();
    s32 func_ov000_021a72c0(M2C_UNK);
    s32 func_ov000_021a8784(M2C_UNK);
    extern void **gCurrentMap;
    register void *temp_r4;
    u16 temp_r5;

    if (arg0) {
        temp_r4 = *gCurrentMap;
        temp_r5 = M2C_FIELD(temp_r4, u16 *, 0x52A4);
        if ((s32) (func_020d2d18(temp_r5, 0x15) * 0xA) > M2C_FIELD(((temp_r5 * 0x8C) + temp_r4), s32 *, 0x67A4)) {
            return -1;
        }
    }
    if (func_ov000_021a72c0(0x15) == 0) {
        return -1;
    }
    if (func_ov000_021a8784(0x15) != 0) {
        return -1;
    }
    return func_ov000_021a6c8c();
}
