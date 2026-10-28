/* 3 functions from 0x0207E52C to 0x0207F460 (main), found by ds-decomp. */
#include "common.h"

s32 func_0207ef5c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0207dc0c(s32, s32);
    s32 func_0207de50(s32, s32);
    s32 func_0207e338(s32, s32);
    extern M2C_UNK data_020edebc;
    u16 flags;
    flags = (u16)M2C_FIELD(&data_020edebc, u32 *, arg2 * 8);
    if (arg2 == 0x34) return 5;
    if (flags & 1) return func_0207e338(arg0, arg1);
    if (flags & 2) return func_0207dc0c(arg0, arg1);
    if (!(flags & 4)) return 0;
    return func_0207de50(arg0, arg1);
}

s32 func_0207efb4(s32 arg0) {
    (void)arg0;
    return 0;
}

