/* 6 functions from 0x02200EE4 to 0x02201E88 (ov003), found by ds-decomp. */
#include "common.h"
extern u16 **gCur3DSpriteEngine;

u8 func_ov003_02201500(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_0220151c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Set bits 4-8 of the word pointed to by *gCur3DSpriteEngine from five boolean flags. */
void func_ov003_0220153c(s32 flag0, s32 flag1, s32 flag2, s32 flag3, u8 flag4) {
u16 * volatile reg0;
u16 * volatile reg1;
u16 * volatile reg2;
u16 * volatile reg3;
u16 * volatile reg4;
reg0 = *gCur3DSpriteEngine; *reg0 = (*reg0 & ~16) | ((u32)(flag0 << 31) >> 27);
reg1 = *gCur3DSpriteEngine; *reg1 = (*reg1 & ~32) | ((u32)(flag1 << 31) >> 26);
reg2 = *gCur3DSpriteEngine; *reg2 = (*reg2 & ~64) | ((u32)(flag2 << 31) >> 25);
reg3 = *gCur3DSpriteEngine; *reg3 = (*reg3 & ~128) | ((u32)(flag3 << 31) >> 24);
reg4 = *gCur3DSpriteEngine; *reg4 = (*reg4 & ~256) | ((u32)(flag4 << 31) >> 23);
}

