/* 11 functions from 0x0208C830 to 0x0208D408 (main), found by ds-decomp. */
#include "common.h"

void func_0208c830(void *arg0, s8 arg1) {
    extern void *gCur3DSpriteEngine;
    s32 i;
    u16 *dest;
    if (arg1 == 0) {
        dest = (u16 *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + ((M2C_FIELD(arg0, u8 *, 0x34) << 5) & ~1));
        for (i = 0; i < 15; i++) {
            dest[i + 1] = ((u16 *)arg0)[i + 0x2B];
        }
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = arg1;
    M2C_FIELD(arg0, s8 *, 0x35) = 1;
}

M2C_UNK func_0208c8a8(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x34) = 0;
    M2C_FIELD(arg0, u8 *, 0x36) = 0;
    M2C_FIELD(arg0, u8 *, 0x37) = 0;
    M2C_FIELD(arg0, u8 *, 0x35) = 0;
}

void func_0208c9ec(void) {

}

void func_0208c9f0(void) {
    M2C_UNK func_0208c8a8();
    func_0208c8a8();
}

void func_0208c9fc(void) {
    func_0208c9ec();
}

void func_0208ca08(void) {
    M2C_UNK func_0208c8c0();
    func_0208c8c0();
}

void func_0208ca14(M2C_UNK arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021027c0;
    func_01ffa3dc(&data_021027c0, arg0);
}

void func_0208ca2c(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    s16 func_020ae354(s16, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0211e278;
    extern M2C_UNK data_0211e304;
    extern void *gCur3DSpriteEngine;
    s16 temp_r0;
    void *temp_r2;

    switch (arg3) {                                 /* irregular */
    case 1:
        func_0207c780(&data_0211e278, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg0);
        break;
    case 2:
        func_0207c780(&data_0211e304, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg0);
        break;
    }
    temp_r0 = func_020ae354(arg2, 0, 8, 8);
    temp_r2 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + (((arg1 + 0x10) << 5) & ~1);
    M2C_FIELD(temp_r2, s16 *, 2) = arg2;
    M2C_FIELD(temp_r2, s16 *, 4) = temp_r0;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
}

