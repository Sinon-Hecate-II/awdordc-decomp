/* 2 functions from 0x021F9FE0 to 0x021FAD10 (ov003), found by ds-decomp. */
#include "common.h"
extern u16 data_ov003_0220feac[64];
extern void *gCur3DSpriteEngine;

void func_ov003_021f9fe0(s32 a, s32 b, s32 c) {
    (void)a; (void)b; (void)c;
}

void func_ov003_021fac2c(s32 a, s32 b, s32 c, s32 d, u16 tile) {
    s16 func_0207c8ec(s32, s32);
    s16 func_0207c928(s32, s32);
    extern u16 data_ov003_0220feac[];
    extern void *gCur3DSpriteEngine;

    s16 x;
    s16 y;
    s32 row;
    s32 col;
    s32 off;
    s32 pos;
    u16 i;
    u16 k;

    x = func_0207c928(a, 2) * 15;
    y = func_0207c928(func_0207c8ec(a, 2) * 2, 32);
    pos = y * 32 + x;
    off = 0;
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 14; col++) {
            k = (func_0207c928(a, 2) == 0) ? 0 : 16;
            i = col + off;
            M2C_FIELD(gCur3DSpriteEngine, u16 **, 0x2C)[pos + i] =
                ((tile + data_ov003_0220feac[i + k]) & 0x3FF) | 0x9000;
        }
        off += 32;
    }
}
