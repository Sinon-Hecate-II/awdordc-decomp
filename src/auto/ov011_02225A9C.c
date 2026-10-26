/* 5 functions from 0x02225A9C to 0x02226658 (ov011), found by ds-decomp. */
#include "common.h"

void func_ov011_022264e4(void) {
    M2C_UNK func_0209cd00(M2C_UNK *);
    M2C_UNK func_020af1e4();
    extern M2C_UNK func_ov011_0222513c;
    extern M2C_UNK func_ov011_02225224;
    func_0209cd00(&func_ov011_0222513c);
    func_0209cd00(&func_ov011_02225224);
    func_020af1e4();
}

void func_ov011_02226508(void *arg0) {
    extern s32 gCur3DSpriteEngine;
    M2C_FIELD(arg0, u16 *, 0x3A)++;
    M2C_FIELD(arg0, u8 *, 0x37)++;
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F) == 0) return;
    gCur3DSpriteEngine = gCur3DSpriteEngine;
    M2C_FIELD(arg0, u8 *, 0x38)++;
}

