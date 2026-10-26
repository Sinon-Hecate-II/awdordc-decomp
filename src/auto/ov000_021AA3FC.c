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
