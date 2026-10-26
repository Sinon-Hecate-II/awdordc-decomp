/* 17 functions from 0x021707D8 to 0x02171774 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_02170ca0(void) {
    M2C_UNK func_01ffa6fc(s32);
    s32 func_01ffa770(M2C_UNK *);
    M2C_UNK func_0208fe30(s32);
    extern M2C_UNK data_ov000_021b8b88;
    s32 temp_r4;
    temp_r4 = func_01ffa770(&data_ov000_021b8b88);
    func_0208fe30(0x10018);
    func_01ffa6fc(temp_r4);
}

void func_ov000_02170fc4(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020cfd28();
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    func_020cfd28();
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02171028(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8b88;
    func_01ffa3dc(&data_ov000_021b8b88, 7);
}

void func_ov000_021711a4(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    func_0208fe30(0x10018);
}

void func_ov000_021711f0(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *data_02101e84;
    if (!(*data_02101e84 & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_02171214(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8c18;
    func_01ffa3dc(&data_ov000_021b8c18, 7);
}

void func_ov000_021716c0(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020e4ca0();
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x3a) = 0;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x42) = 0;
    func_020e4ca0();
    func_0208fe30(0x10018);
}

void func_ov000_0217172c(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *data_02101e84;
    if (!(*data_02101e84 & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_02171750(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8c94;
    func_01ffa3dc(&data_ov000_021b8c94, 7);
}

s32 func_ov000_02171768(s32 arg0) {
    return (arg0 * 0x10) + 0x430;
}
