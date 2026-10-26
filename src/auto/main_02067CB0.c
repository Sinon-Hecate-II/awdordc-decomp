/* 6 functions from 0x02067CB0 to 0x02068C50 (main), found by ds-decomp. */
#include "common.h"

s32 func_02068a04(void *arg0, s32 arg1, s32 arg2) {
    s8 *temp_r1;
    s32 temp_r2;
    switch (arg2) {
    case 0:
        temp_r1 = M2C_FIELD(arg0, s8 **, 0);
        temp_r2 = *temp_r1;
        if (temp_r2 == 0) {
            M2C_FIELD(arg0, s32 *, 4) = 1;
            return -1;
        }
        M2C_FIELD(arg0, s8 **, 0) = temp_r1 + 1;
        return (u8)temp_r2;
    case 1:
        if (M2C_FIELD(arg0, s32 *, 4) != 0) {
            M2C_FIELD(arg0, s32 *, 4) = 0;
            goto done;
        } else {
            M2C_FIELD(arg0, s8 **, 0) -= 1;
        }
    done:
        return arg1;
    case 2:
        return M2C_FIELD(arg0, s32 *, 4);
    default:
        return 0;
    }
}

s32 func_02068a88(s8 *arg0, s32 arg1, s32 arg2) {
    s32 func_02068a04(void *, s32, s32);
    s32 func_02067cb0(s32 (*)(void *, s32, s32), void *, s32, s32, s32);
    struct { s8 *ptr; s32 eof; } state;
    state.ptr = arg0;
    if (arg0 == NULL || *arg0 == 0) return -1;
    state.eof = 0;
    return func_02067cb0(func_02068a04, &state, arg1, arg2, 0);
}

void func_02068adc(s32 arg0, s32 arg1, ...) {
    s32 func_02068a88(s8 *, s32, s32);
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    func_02068a88(arg0, arg1, args);
}

s32 func_02068c34(s8 *arg0) {
    s32 var_r2;
    s8 *var_r0;
    s8 temp_r1;

    var_r0 = arg0;
    var_r2 = -1;
    do {
        temp_r1 = *var_r0;
        var_r0 += 1;
        var_r2 += 1;
    } while (temp_r1 != 0);
    return var_r2;
}
