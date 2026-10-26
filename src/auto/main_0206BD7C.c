/* 4 functions from 0x0206BD7C to 0x0206CD20 (main), found by ds-decomp. */
#include "common.h"

s32 func_0206ccb8(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0206adc0(s32, M2C_UNK, s32);
    s32 temp_r3;
    s32 var_r5;
    u32 temp_r2;
    s32 result;
    temp_r3 = M2C_FIELD(arg0, s32 *, 8);
    var_r5 = arg2;
    temp_r2 = M2C_FIELD(arg0, u32 *, 4);
    if ((u32)(temp_r3 + var_r5) > temp_r2) {
        var_r5 = temp_r2 - temp_r3;
    }
    result = func_0206adc0(M2C_FIELD(arg0, s32 *, 0) + (temp_r3 * 2), arg1, var_r5);
    M2C_FIELD(arg0, s32 *, 8) = M2C_FIELD(arg0, s32 *, 8) + var_r5;
    return result;
}

void func_0206ccf8(s32 arg0, s32 arg1, s32 arg2, ...) {
    void func_0206cd20();
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_0206cd20(arg0, arg1, arg2, args);

}
