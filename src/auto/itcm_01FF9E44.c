/* 17 functions from 0x01FF8F90 to 0x01FF9ED0 (itcm), found by ds-decomp. */
#include "common.h"

/* Copy data via func_02007ef4 using the current 3D sprite engine's buffer, then mark engine busy (bit 0x10). */
void func_01ff9e44(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_02007ef4(M2C_UNK, s32, M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    func_02007ef4(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, arg2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
}

void func_01ff9e78(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_02008048(M2C_UNK, s32, M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    func_02008048(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, arg2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
}

void func_01ff9eac(M2C_UNK arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    M2C_UNK func_02007ef4(M2C_UNK, s32, M2C_UNK);
    s32 var_r1;

    if (arg1 == 0) {
        var_r1 = 0x05000000;
    } else {
        var_r1 = 0x05000400;
    }
    func_02007ef4(arg0, var_r1 + arg2, arg3);
}
