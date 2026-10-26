/* 4 functions from 0x0206CD20 to 0x0206CE00 (main), found by ds-decomp. */
#include "common.h"

s32 func_0206cd20(u16 *arg0, u32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 func_0206ccb8(void *, M2C_UNK, s32);
    s32 func_0206c3c8(s32 (*)(void *, M2C_UNK, s32), void *, M2C_UNK, M2C_UNK);
    struct { u16 *buffer; u32 size; s32 count; } state;
    s32 result;
    state.buffer = arg0;
    state.size = arg1;
    state.count = 0;
    result = func_0206c3c8(func_0206ccb8, &state, arg2, arg3);
    if (result < 0) return result;
    if ((u32)result < arg1) {
        arg0[result] = 0;
        return result;
    }
    (arg0 + arg1)[-1] = 0;
    return -1;
}

s32 func_0206cd90(u16 *arg0) {
    s32 var_r2;
    u16 *var_r0;
    u16 temp_r1;
    var_r0 = arg0;
    var_r2 = -1;
    do {
        temp_r1 = *var_r0++;
        var_r2 += 1;
    } while (temp_r1 != 0);
    return var_r2;
}

u16 *func_0206cdac(u16 *arg0, u16 *arg1) {
    u16 *dest = arg0;
    while ((*dest++ = *arg1++) != 0) {}
    return arg0;
}

u16 *func_0206cdcc(u16 *arg0, s32 arg1) {
    u16 var_r2;
    while ((var_r2 = *arg0++) != 0) {
        if (var_r2 == arg1) return arg0 - 1;
    }
    if (arg1 != 0) return 0;
    return arg0 - 1;
}

