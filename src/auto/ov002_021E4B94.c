/* 3 functions from 0x021E4B94 to 0x021E59E4 (ov002), found by ds-decomp. */
#include "common.h"

void func_ov002_021e5974(s32 *arg0, s32 *arg1) {
    s32 temp_r3;

    temp_r3 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_r3;
}

void func_ov002_021e5988(u16 *arg0, s32 arg1) {
    s32 j;
    s32 i;
    u16 a;
    u16 b;
    for (i = 0; i < arg1; i++) {
        for (j = 0; j < 16; j++) {
            a = arg0[31 - j];
            b = arg0[j];
            arg0[j] = a ^ 0x400;
            arg0[31 - j] = b ^ 0x400;
        }
        arg0 += 32;
    }
}

