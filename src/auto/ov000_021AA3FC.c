/* 9 functions from 0x021AA3FC to 0x021AAB78 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_021aa3fc(void *arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_021a9904(u32);
    extern u8 data_ov000_021b5c00;
    s32 result;
    u32 f0;
    u32 f6;
    u32 count;
    u16 entry;
    if ((M2C_FIELD(arg0, u16 *, 6) & 0x7FU) <= 0xAU) return 2;
    f0 = ((u8 *)arg0)[0] & 0x3FU;
    if (func_ov000_021a9904(f0) == 2 && arg2 == 1) return 2;
    f6 = M2C_FIELD(arg0, u16 *, 6) & 0x7FU;
    if (arg1 < (s32)f6) count = (u32)arg1;
    else count = f6 - 1U;
    entry = M2C_FIELD(&data_ov000_021b5c00, u16 *, (s32)(f0 * 0x70U));
    result = (s32)entry * (s32)count;
    if (func_ov000_021a9904(f0) == 2 && arg2 == 0) result = result >> 1;
    return result;
}

u32 func_ov000_021aa4a4(void *arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_021a9904(u32);
    u32 temp_r0;
            u32 var_r0;
    u32 var_r5;

    if ((u32) ((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19) <= 0xAU) {
        return 1U;
    }
    if ((func_ov000_021a9904((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) == 2) && (arg2 == 1)) {
        return 1U;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 6) << 0x19;
    if (arg1 < (s32) (temp_r0 >> 0x19)) {
        var_r0 = arg1 << 0x10;
    } else {
        var_r0 = ((temp_r0 >> 0x19) - 1) << 0x10;
    }
    var_r5 = var_r0 >> 0x10;
    if ((func_ov000_021a9904((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) == 2) && (arg2 == 0)) {
        var_r5 = (u32) (var_r5 << 0xF) >> 0x10;
    }
    return var_r5;
}

s32 func_ov000_021aa534(s32 arg0, s32 arg1) {
    s32 var_r0;

    if (arg1 == 0) {
        return 0x80000001;
    }
    var_r0 = arg1 - arg0;
    if (var_r0 < 0x2328) {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021aa558(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return 0x80000001;
    }
    return arg1 - (arg0 * 2);
}

s32 func_ov000_021aa568(void *arg0) {
    return 0;
}

void func_ov000_021aab20(s32, s32, s32, s32, s32, s32);
s32 func_ov000_021aa820(s32 a, s32 b, s32 c, s32 d) {
    s32 x;
    s32 y;
    typedef s32 (*Fn)(s32, s32, s32, s32, s32, s32);
    switch (d) {
    case 0:
        x = 2;
        y = 0x1e;
        break;
    case 1:
        x = 2;
        y = 0x50;
        break;
    default:
        return 0;
    }
    return ((Fn)func_ov000_021aab20)(a, b, c, d, x, y);
}

s32 func_ov000_021aa870(void *arg0) {
    return 0;
}

void func_ov000_021aab20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)func_ov000_021aa870)(a, b, c, d, e, f, 0);
}

void func_ov000_021aab4c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)func_ov000_021aa870)(a, b, c, d, e, f, 1);
}

