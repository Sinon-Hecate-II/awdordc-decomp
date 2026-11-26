/* 17 functions from 0x01FF8F90 to 0x01FF9ED0 (itcm), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "gx.h"

/* Copy data via MI_CpuCopy32 using the current 3D sprite engine's buffer, then mark engine busy (bit 0x10). */
void CopyToObjPaletteShadow(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK MI_CpuCopy32(M2C_UNK, s32, M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    MI_CpuCopy32(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, arg2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
}

/* Copy `size` bytes of OBJ palette data from `src` to the current 3D sprite
 * engine's palette shadow (its RAM copy, uploaded to VRAM at the next flush) at
 * byte offset `destOffset`, then mark the palette dirty. */
void CopyBytesToObjPaletteShadow(void *src, s32 destOffset, u32 size) {
    void MI_CpuCopy8(void *, u32, u32);
    extern u16 **gCur3DSpriteEngine;
    MI_CpuCopy8(src, (u32)M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_PALETTES) + destOffset, size);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_PALETTE;
}

/* Copy `size` bytes of palette data from `src` into the palette RAM of the main
 * engine (`screen` 0) or the sub engine (`screen` 1), at byte offset `offset`
 * within that engine's palette. */
void CopyToSpritePaletteVram(void *src, s32 screen, s32 offset, u32 size) {
    M2C_UNK MI_CpuCopy32(M2C_UNK, s32, M2C_UNK);
    u32 paletteBase;

    if (screen == 0) {
        paletteBase = GX_MAIN_PALETTE_BASE;
    } else {
        paletteBase = GX_SUB_PALETTE_BASE;
    }
    MI_CpuCopy32((M2C_UNK) src, (s32) (paletteBase + offset), (M2C_UNK) size);
}
