/* 11 functions from 0x02066BA8 to 0x020677B8 (main), found by ds-decomp. */
#include "common.h"

s32 func_020673cc(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_02064684(M2C_UNK, M2C_UNK, s32, s32);
    s32 var_r5;

    var_r5 = arg0;
    if (arg2 != func_02064684(arg1, 1, arg2, var_r5)) {
        var_r5 = 0;
    }
    return var_r5;
}

s32 func_020673f8(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_020651a4(s32, M2C_UNK, s32);
    s32 temp_r3;
    s32 var_r5;
    u32 temp_r2;

    temp_r3 = M2C_FIELD(arg0, s32 *, 8);
    var_r5 = arg2;
    temp_r2 = M2C_FIELD(arg0, u32 *, 4);
    if ((u32) (temp_r3 + var_r5) > temp_r2) {
        var_r5 = temp_r2 - temp_r3;
    }
    func_020651a4(M2C_FIELD(arg0, s32 *, 0) + temp_r3, arg1, var_r5);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + var_r5);
    return 1;
}

u32 func_02067554(char *arg0, u32 arg1, s32 arg2, void *arg3) {
    u32 func_02066ba8();
    struct { char *buffer; u32 size; u32 position; } state;
    u32 result;
    state.buffer = arg0;
    state.size = arg1;
    state.position = 0;
    result = func_02066ba8(func_020673f8, &state, arg2, arg3);
    if (arg0 == 0) return result;
    if (result < arg1) {
        arg0[result] = 0;
        return result;
    }
    if (arg1 != 0) (arg0 + arg1)[-1] = 0;
    return result;
}

void func_020675bc(s32 arg0, s32 arg1, s32 arg2, ...) {
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_02067554(arg0, arg1, arg2, args);

}

void func_020675e4(s32 arg0, s32 arg1, ...) {
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    func_02067554((char *)arg0, -1, arg1, args);
}

s32 func_02067774(void) {
    extern s32 data_02100554;
    u32 value;
    value = (data_02100554 * 0x41C64E6D) + 0x3039;
    data_02100554 = value;
    return 0x7FFF & (value >> 16);
}

void func_020677a8(s32 arg0) {
    extern s32 data_02100554;
    data_02100554 = arg0;
}
