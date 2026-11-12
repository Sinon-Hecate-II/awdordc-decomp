/* 17 functions from 0x01FF8F90 to 0x01FF9ED0 (itcm), found by ds-decomp. */
#include "common.h"

/* Copy data via MI_CpuCopy32 using the current 3D sprite engine's buffer, then mark engine busy (bit 0x10). */
void func_01ff9e44(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK MI_CpuCopy32(M2C_UNK, s32, M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    MI_CpuCopy32(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, arg2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
}

void func_01ff9e78(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK MI_CpuCopy8(M2C_UNK, s32, M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    MI_CpuCopy8(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, arg2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
}

void CopyToSpritePaletteVram(M2C_UNK arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    M2C_UNK MI_CpuCopy32(M2C_UNK, s32, M2C_UNK);
    s32 var_r1;

    if (arg1 == 0) {
        var_r1 = 0x05000000;
    } else {
        var_r1 = 0x05000400;
    }
    MI_CpuCopy32(arg0, var_r1 + arg2, arg3);
}
