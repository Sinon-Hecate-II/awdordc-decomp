/* 9 functions from 0x021AA3FC to 0x021AAB78 (ov000), found by ds-decomp. */
#include "common.h"

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

