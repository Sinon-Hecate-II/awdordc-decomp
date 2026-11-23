/* 53 functions from 0x0200402C to 0x02004FF8 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"
typedef struct { u32 a,b,c,d,e,f,g,h; } FuncCopy8;

typedef struct { u32 x, y, z; } FuncCopyV3;

/* Build the camera's look-at matrix from its eye position `eye`, up vector `up`
 * and `target` point, and load it onto the geometry engine's position matrix
 * stack when `loadToGx` is set.  The matrix goes to `mtx`, or to a local one
 * when the caller passes NULL. */
void G3X_SetCamera(s32 *eye, s32 *up, s32 *target, s32 loadToGx, s32 *mtx) {
    void MTX_LookAt(s32 *, s32 *, s32 *, s32 *);
    M2C_UNK GX_LoadMatrix4x3(M2C_UNK *);
    s32 localMtx[12];
    s32 *matrix = mtx;

    if (matrix == NULL) matrix = localMtx;
    MTX_LookAt(eye, up, target, matrix);
    if (loadToGx == 0) return;
    REG_GX_MTX_MODE = 2;
    GX_LoadMatrix4x3(matrix);
}

void func_02004078(s32 arg0,s32 arg1) {
 *(volatile s32 *)0x04000468=arg1;
 *(volatile s32 *)0x04000468=arg0;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=-arg0;
 *(volatile s32 *)0x04000468=arg1;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=0x1000;
}

/* Copy `size` bytes of palette data to the main engine's BG palette RAM at
 * `offset`: through the GX DMA channel when one is owned and the copy is larger
 * than 28 bytes, on the CPU otherwise. */
void GX_LoadBGPltt(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;

    if (gGxDmaChannel != -1 && size > 0x1CU) {
        DmaCopy16(gGxDmaChannel, src, offset + GX_MAIN_PALETTE_BASE, size);
        return;
    }
    CopyU16(src, offset + GX_MAIN_PALETTE_BASE, size);
}

/* Copy palette data to sub-engine BG palette RAM, using DMA for transfers over 28 bytes when a GX DMA channel is available. */
void GX_LoadSubBGPltt(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;

    if (gGxDmaChannel != -1 && size > 0x1CU) {
        DmaCopy16(gGxDmaChannel, src, offset + GX_SUB_PALETTE_BASE, size);
        return;
    }
    CopyU16(src, offset + GX_SUB_PALETTE_BASE, size);
}

/* Copy palette data into main-engine OBJ palette RAM, using DMA for transfers over 28 bytes when a GX DMA channel is available. */
void GX_LoadOBJPltt(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;

    if (gGxDmaChannel != -1 && size > 0x1CU) {
        DmaCopy16(gGxDmaChannel, src, offset + GX_MAIN_OBJ_PALETTE_BASE, size);
        return;
    }
    CopyU16(src, offset + GX_MAIN_OBJ_PALETTE_BASE, size);
}

/* Copy `size` bytes of palette data to the sub engine's OBJ palette RAM at
 * `offset`: through the GX DMA channel when one is owned and the copy is larger
 * than 28 bytes, on the CPU otherwise. */
void GX_LoadSubOBJPltt(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    if (gGxDmaChannel != -1 && size > 0x1CU) {
        DmaCopy16(gGxDmaChannel, src, offset + GX_SUB_OBJ_PALETTE_BASE, size);
        return;
    }
    CopyU16(src, offset + GX_SUB_OBJ_PALETTE_BASE, size);
}

/* Copy `size` bytes of 3D-sprite OAM data from `src` into the main engine's OAM
   at `offset`: through the GX DMA channel when one is owned and the copy is
   larger than 48 bytes, on the CPU otherwise. */
void GX_LoadOAM(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, offset + GX_MAIN_OBJ_OAM_BASE, size);
        return;
    }
    MIi_CpuCopy32(src, offset + GX_MAIN_OBJ_OAM_BASE, size);
}

/* Copy `size` bytes of 3D-sprite OAM data from `src` into the sub engine's OAM
 * at `offset`: through the GX DMA channel when one is owned and the copy is
 * larger than 48 bytes, on the CPU otherwise. */
void GX_LoadOAMSub(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, offset + GX_SUB_OBJ_OAM_BASE, size);
        return;
    }
    MIi_CpuCopy32(src, offset + GX_SUB_OBJ_OAM_BASE, size);
}

#pragma push
#pragma opt_propagation off
/* Copy `size` bytes of 3D-sprite OBJ character data from `src` into the main
 * engine's OBJ VRAM at `offset`: through the GX DMA channel when one is owned
 * and the copy is larger than 48 bytes, on the CPU otherwise. */
void GX_LoadOBJ(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    register s32 base = GX_MAIN_OBJ_VRAM_BASE;

    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, base + offset, size);
        return;
    }
    MIi_CpuCopy32(src, base + offset, size);
}
#pragma pop
#pragma push
#pragma opt_propagation off
/* Copy `size` bytes of 3D-sprite OBJ character data into the sub engine's OBJ
 * VRAM at `offset`: through the GX DMA channel when one is owned and the copy is
 * larger than 48 bytes, on the CPU otherwise. */
void GX_LoadOBJSub(M2C_UNK src, s32 offset, u32 size) {
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    register u32 base=GX_SUB_OBJ_VRAM_BASE;
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, base + offset, size);
        return;
    }
    MIi_CpuCopy32(src, base + offset, size);
}
#pragma pop

/* Copy `size` bytes of background-map data into the sub screen's BG0 map at
 * `offset`: through the GX DMA channel when one is free and the copy is larger
 * than 28 bytes, on the CPU otherwise. */
void GX_LoadBG0ScrSub(M2C_UNK src, s32 offset, u32 size) {
    s32 func_020036b8();
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 base;

    base = func_020036b8();
    if ((gGxDmaChannel != -1) && (size > 0x1CU)) {
        DmaCopy16(gGxDmaChannel, src, base + offset, size);
        return;
    }
    CopyU16(src, base + offset, size);
}

/* Copy `size` bytes of background-map data into the main screen's BG1 map at
 * `offset`: through the GX DMA channel when one is owned and the copy is larger
 * than 28 bytes, on the CPU otherwise. */
void GX_LoadBG1Scr(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG1ScrPtr();
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 screenBase;

    screenBase = GX_GetBG1ScrPtr();
    if ((gGxDmaChannel != -1) && (size > 0x1CU)) {
        DmaCopy16(gGxDmaChannel, src, screenBase + offset, size);
        return;
    }
    CopyU16(src, screenBase + offset, size);
}

/* Copy `size` bytes of background-map data into the sub screen's BG1 map at
 * `offset`: through the GX DMA channel when one is owned and the copy is larger
 * than 28 bytes, on the CPU otherwise. */
void GX_LoadBG1ScrSub(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG1ScrPtrSub();
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 screenBase;

    screenBase = GX_GetBG1ScrPtrSub();
    if ((gGxDmaChannel != -1) && (size > 0x1CU)) {
        DmaCopy16(gGxDmaChannel, src, screenBase + offset, size);
        return;
    }
    CopyU16(src, screenBase + offset, size);
}

/* Copy `size` bytes of background-map data into the main screen's BG2 map at
 * `offset`: through the GX DMA channel when one is owned and the copy is larger
 * than 28 bytes, on the CPU otherwise. */
void GX_LoadBG2Scr(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG2ScrPtr();
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 screenBase;

    screenBase = GX_GetBG2ScrPtr();
    if ((gGxDmaChannel != -1) && (size > 0x1CU)) {
        DmaCopy16(gGxDmaChannel, src, screenBase + offset, size);
        return;
    }
    CopyU16(src, screenBase + offset, size);
}

/* Copy `size` bytes of BG3 map data from `src` into BG3's screen area at `offset`.
 * The copy runs through the GX DMA channel when one is owned and on the CPU
 * otherwise. */
void GX_LoadBG3Scr(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG3ScrPtr();
    M2C_UNK DmaCopy16(s32, M2C_UNK, s32, u32);
    M2C_UNK CopyU16(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 screenBase;

    screenBase = GX_GetBG3ScrPtr();
    if ((gGxDmaChannel != -1) && (size > 0x1CU)) {
        DmaCopy16(gGxDmaChannel, src, screenBase + offset, size);
        return;
    }
    CopyU16(src, screenBase + offset, size);
}

/* Copy `size` bytes of background character (tile) data into the main screen's
 * BG0 character area at `offset`: through the GX DMA channel when one is owned
 * and the copy is larger than 48 bytes, on the CPU otherwise. */
void GX_LoadBG0Char(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG0CharPtr();
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 charBase;

    charBase = GX_GetBG0CharPtr();
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, charBase + offset, size);
        return;
    }
    MIi_CpuCopy32(src, charBase + offset, size);
}

/* Copy `size` bytes of background character (tile) data into the sub screen's
 * BG0 character area at `offset`: through the GX DMA channel when one is owned
 * and the copy is larger than 48 bytes, on the CPU otherwise. */
void GX_LoadBG0CharSub(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG0CharPtrSub();
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 charBase;

    charBase = GX_GetBG0CharPtrSub();
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, charBase + offset, size);
        return;
    }
    MIi_CpuCopy32(src, charBase + offset, size);
}

/* Copy `size` bytes of background character (tile) data into the main screen's
 * BG1 character area at `offset`: through the GX DMA channel when one is owned
 * and the copy is larger than 48 bytes, on the CPU otherwise. */
void GX_LoadBG1Char(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG1CharPtr();
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 charBase;

    charBase = GX_GetBG1CharPtr();
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, charBase + offset, size);
        return;
    }
    MIi_CpuCopy32(src, charBase + offset, size);
}

/* Copy `size` bytes of background character (tile) data into the sub screen's
 * BG1 character area at `offset`: through the GX DMA channel when one is owned
 * and the copy is larger than 48 bytes, on the CPU otherwise. */
void GX_LoadBG1CharSub(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG1CharPtrSub();
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 charBase;

    charBase = GX_GetBG1CharPtrSub();
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, charBase + offset, size);
        return;
    }
    MIi_CpuCopy32(src, charBase + offset, size);
}

/* Copy `size` bytes of background character (tile) data into the main screen's
 * BG2 character area at `offset`: through the GX DMA channel when one is owned
 * and the copy is larger than 48 bytes, on the CPU otherwise. */
void GX_LoadBG2Char(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG2CharPtr();
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 charBase;

    charBase = GX_GetBG2CharPtr();
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, charBase + offset, size);
        return;
    }
    MIi_CpuCopy32(src, charBase + offset, size);
}

/* Copy `size` bytes of background character (tile) data into the main screen's
 * BG3 character area at `offset`: through the GX DMA channel when one is owned
 * and the copy is larger than 48 bytes, on the CPU otherwise. */
void GX_LoadBG3Char(M2C_UNK src, s32 offset, u32 size) {
    s32 GX_GetBG3CharPtr();
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    s32 charBase;

    charBase = GX_GetBG3CharPtr();
    if (gGxDmaChannel != -1 && size > 0x30U) {
        DmaCopy(gGxDmaChannel, src, charBase + offset, size);
        return;
    }
    MIi_CpuCopy32(src, charBase + offset, size);
}

/* Begins a main-engine background extended-palette load: releases the palette's
 * bank grant, records it, and stores the VRAM base and offset the load copies
 * into, chosen from the banks the release gave back. */
void GX_BeginLoadBGExtPltt(void) {
s32 func_02003370(void); extern M2C_UNK gGxExtPlttLoad;
s32 banks=func_02003370();
M2C_FIELD(&gGxExtPlttLoad,s32 *,GX_EXTPLTT_LOAD_BG_GRANT)=banks;
switch(banks) {
case 0: break;
case VRAM_BANK_E: M2C_FIELD(&gGxExtPlttLoad,M2C_UNK *,GX_EXTPLTT_LOAD_BG_BASE)=(M2C_UNK)GX_BGEXTPLTT_BASE_E; M2C_FIELD(&gGxExtPlttLoad,s32 *,GX_EXTPLTT_LOAD_BG_OFFSET)=0;break;
case VRAM_BANK_G: M2C_FIELD(&gGxExtPlttLoad,M2C_UNK *,GX_EXTPLTT_LOAD_BG_BASE)=(M2C_UNK)GX_BGEXTPLTT_BASE_G; M2C_FIELD(&gGxExtPlttLoad,s32 *,GX_EXTPLTT_LOAD_BG_OFFSET)=GX_BGEXTPLTT_OFFSET_G;break;
case VRAM_BANK_F: case VRAM_BANK_F|VRAM_BANK_G: M2C_FIELD(&gGxExtPlttLoad,M2C_UNK *,GX_EXTPLTT_LOAD_BG_BASE)=(M2C_UNK)GX_BGEXTPLTT_BASE_F; M2C_FIELD(&gGxExtPlttLoad,s32 *,GX_EXTPLTT_LOAD_BG_OFFSET)=0;break;
default: break;
}
}

/* Copy `size` bytes of extended background-palette data from `src` into the
 * main-engine BG extended palette area at `offset`.  GX_BeginLoadBGExtPltt put
 * the area's VRAM base and running offset in gGxExtPlttLoad; the copy runs
 * through the GX DMA channel when one is owned and on the CPU otherwise. */
void GX_LoadBGExtPltt(M2C_UNK src, M2C_UNK offset, M2C_UNK size) {
    M2C_UNK DmaCopyAsync(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxExtPlttLoad;
    M2C_UNK paletteBase = M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, GX_EXTPLTT_LOAD_BG_BASE);
    M2C_UNK paletteOffset = M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, GX_EXTPLTT_LOAD_BG_OFFSET);
    M2C_UNK dst = paletteBase + (s32)offset - paletteOffset;
    if (gGxDmaChannel != -1) {
        DmaCopyAsync(gGxDmaChannel, src, dst, size, 0, 0);
        return;
    }
    MIi_CpuCopy32(src, dst, (u32)size);
}

void GX_EndLoadBGExtPltt(void) {
    M2C_UNK DmaWaitChannel(s32);
    M2C_UNK GX_SetBankForBGExtPalette(M2C_UNK);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxExtPlttLoad;
    if (gGxDmaChannel != -1) {
        DmaWaitChannel(gGxDmaChannel);
    }
    GX_SetBankForBGExtPalette(M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x14));
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x14) = 0;
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x10) = 0;
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0xc) = 0;
}

void GX_BeginLoadOBJExtPltt(void) {
    s32 func_02003394();
    extern M2C_UNK gGxExtPlttLoad;
    s32 v = func_02003394();
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x8) = (M2C_UNK)v;
    if (v == 0) {
        return;
    }
    if (v == 0x20) {
        goto store_6890;
    }
    if (v == 0x40) {
        M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x4) = (M2C_UNK)0x6894000;
        return;
    }
    return;
store_6890:
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x4) = (M2C_UNK)0x6890000;
    return;
}

/* Copy `size` bytes of extended OBJ-palette data from `src` into the main-engine
 * OBJ extended palette area at `offset`.  GX_BeginLoadOBJExtPltt put the area's
 * VRAM base in gGxExtPlttLoad; the copy runs through the GX DMA channel when one
 * is owned and on the CPU otherwise. */
void GX_LoadOBJExtPltt(M2C_UNK src, M2C_UNK offset, M2C_UNK size) {
    M2C_UNK DmaCopyAsync(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxExtPlttLoad;
    M2C_UNK paletteBase = M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, GX_EXTPLTT_LOAD_OBJ_BASE);
    if (gGxDmaChannel != -1) {
        DmaCopyAsync(gGxDmaChannel, src, paletteBase + (s32)offset, size, 0, 0);
        return;
    }
    MIi_CpuCopy32(src, paletteBase + (s32)offset, (u32)size);
}

void GX_EndLoadOBJExtPltt(void) {
    M2C_UNK DmaWaitChannel(s32);
    M2C_UNK GX_SetBankForObjExtPalette(M2C_UNK);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxExtPlttLoad;
    if (gGxDmaChannel != -1) {
        DmaWaitChannel(gGxDmaChannel);
    }
    GX_SetBankForObjExtPalette(M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x8));
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x8) = 0;
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x4) = 0;
}

void GX_BeginLoadBGExtPlttSub(void) {
    s32 func_02003408();
    extern s32 gGxExtPlttLoad;
    gGxExtPlttLoad = func_02003408();
}

/* Copy `size` bytes of extended background-palette data from `src` into the
 * sub-engine BG extended palette area at `offset`.  The copy runs through the GX
 * DMA channel when one is owned and on the CPU otherwise. */
void GX_LoadBGExtPlttSub(M2C_UNK src, M2C_UNK offset, M2C_UNK size) {
    M2C_UNK DmaCopyAsync(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    if (gGxDmaChannel != -1) {
        DmaCopyAsync(gGxDmaChannel, src, (s32)offset + GX_SUB_BG_EXTPLTT_VRAM_BASE, size, 0, 0);
        return;
    }
    MIi_CpuCopy32(src, (s32)offset + GX_SUB_BG_EXTPLTT_VRAM_BASE, (u32)size);
}

void GX_EndLoadBGExtPlttSub(void) {
    M2C_UNK DmaWaitChannel(s32);
    M2C_UNK GX_SetBankForBGExtPlttSub(M2C_UNK);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxExtPlttLoad;
    if (gGxDmaChannel != -1) {
        DmaWaitChannel(gGxDmaChannel);
    }
    GX_SetBankForBGExtPlttSub(gGxExtPlttLoad);
    gGxExtPlttLoad = 0;
}

void GX_BeginLoadOBJExtPlttSub(void) {
    s32 func_02003430();
    extern M2C_UNK gGxExtPlttLoad;
    M2C_FIELD(&gGxExtPlttLoad, s32 *, 0x18) = func_02003430();
}

/* Copy `size` bytes of extended OBJ-palette data from `src` into the sub-engine
 * OBJ extended palette area at `offset`.  The copy runs through the GX DMA
 * channel when one is owned and on the CPU otherwise. */
void GX_LoadOBJExtPlttSub(M2C_UNK src, M2C_UNK offset, M2C_UNK size) {
    M2C_UNK DmaCopyAsync(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    if (gGxDmaChannel != -1) {
        DmaCopyAsync(gGxDmaChannel, src, (s32)offset + GX_SUB_OBJ_EXTPLTT_VRAM_BASE, size, 0, 0);
        return;
    }
    MIi_CpuCopy32(src, (s32)offset + GX_SUB_OBJ_EXTPLTT_VRAM_BASE, (u32)size);
}

void GX_EndLoadOBJExtPlttSub(void) {
    M2C_UNK DmaWaitChannel(s32);
    M2C_UNK GX_SetBankForOBJExtPlttSub(M2C_UNK);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxExtPlttLoad;
    if (gGxDmaChannel != -1) {
        DmaWaitChannel(gGxDmaChannel);
    }
    GX_SetBankForOBJExtPlttSub(M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x18));
    M2C_FIELD(&gGxExtPlttLoad, M2C_UNK *, 0x18) = 0;
}

void GX_BeginLoadTex(void) {
    s32 func_020033b8(void);
    extern u8 data_020e9b40[], data_020e9b42[], data_020e9b44[];
    extern M2C_UNK gGxTexLoad;
    s32 idx;
    u32 a, b, c;

    idx = func_020033b8();
    a = *(volatile u16 *)(data_020e9b40 + idx * 6);
    b = *(volatile u16 *)(data_020e9b42 + idx * 6);
    c = *(volatile u16 *)(data_020e9b44 + idx * 6);
    M2C_FIELD(&gGxTexLoad, s32 *, 0x14) = idx;
    M2C_FIELD(&gGxTexLoad, s32 *, 4) = a << 12;
    M2C_FIELD(&gGxTexLoad, s32 *, 0x18) = b << 12;
    M2C_FIELD(&gGxTexLoad, s32 *, 0x1c) = c << 12;
}

/* Copy `size` bytes from `src` to the texture-bank region at byte `offset`.
   The region may span two physical banks (base2 != 0); a block that crosses the
   split is written to both, with the large head done by DMA when available. */
void LoadTextureBankBlock(M2C_UNK src, u32 offset, u32 size) {
    M2C_UNK DmaCopy(s32, M2C_UNK, s32, u32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    M2C_UNK DmaCopyAsync(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxTexLoad;

    M2C_UNK *bank = &gGxTexLoad;
    s32 base2 = M2C_FIELD(bank, s32 *, 0x18);
    u32 ofs = offset;
    u32 n = size;
    M2C_UNK p = src;
    s32 dst;
    s32 split;

    if (base2 == 0) {
        dst = M2C_FIELD(bank, s32 *, 0x4) + (s32)ofs;
    } else {
        split = M2C_FIELD(bank, s32 *, 0x1c);
        if (ofs + n < (u32)split) {
            dst = M2C_FIELD(bank, s32 *, 0x4) + (s32)ofs;
        } else if (ofs >= (u32)split) {
            dst = base2 + (s32)ofs - split;
        } else {
            u32 head = (u32)split - ofs;
            s32 base = M2C_FIELD(bank, s32 *, 0x4);
            if (gGxDmaChannel != -1 && head > 0x30U) {
                DmaCopy(gGxDmaChannel, p, base + (s32)ofs, head);
            } else {
                MIi_CpuCopy32(p, base + (s32)ofs, head);
            }
            if (gGxDmaChannel != -1) {
                DmaCopyAsync(gGxDmaChannel, p + (M2C_UNK)head, base2, n - head, 0, 0);
            } else {
                MIi_CpuCopy32(p + (M2C_UNK)head, base2, n - head);
            }
            return;
        }
    }

    if (gGxDmaChannel != -1) {
        DmaCopyAsync(gGxDmaChannel, p, dst, n, 0, 0);
    } else {
        MIi_CpuCopy32(p, dst, n);
    }
}

/* Finish a 3D texture-bank load: wait for the async copy on the GX DMA channel,
 * hand the texture area's VRAM bank back with the grant GX_BeginLoadTex took,
 * and clear the area's recorded base, second base, split offset and grant. */
void GX_EndLoadTex(void) {
    M2C_UNK GX_SetBankForTex(s32);
    M2C_UNK DmaWaitChannel(s32);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxTexLoad;
    if (gGxDmaChannel != -1) {
        DmaWaitChannel(gGxDmaChannel);
    }
    GX_SetBankForTex(M2C_FIELD(&gGxTexLoad, M2C_UNK *, GX_TEXLOAD_TEX_GRANT));
    M2C_FIELD(&gGxTexLoad, M2C_UNK *, GX_TEXLOAD_TEX_OFFSET) = 0;
    M2C_FIELD(&gGxTexLoad, M2C_UNK *, GX_TEXLOAD_TEX_BASE2) = 0;
    M2C_FIELD(&gGxTexLoad, M2C_UNK *, GX_TEXLOAD_TEX_BASE) = 0;
    M2C_FIELD(&gGxTexLoad, M2C_UNK *, GX_TEXLOAD_TEX_GRANT) = 0;
}

void func_02004d3c(void) {
 s32 GX_ReleaseBankForOBJExtPltt(); extern M2C_UNK data_020e9b30; extern M2C_UNK gGxTexLoad;
 s32 state=GX_ReleaseBankForOBJExtPltt();
 u32 base=((u16*)&data_020e9b30)[state>>4];
 M2C_FIELD(&gGxTexLoad,s32*,12)=state;
 M2C_FIELD(&gGxTexLoad,u32*,8)=base<<12;
}

/* Copy `size` bytes of texture-palette data from `src` into the main-engine 3D
 * texture palette at byte `offset`.  GX_BeginLoadTexPltt left the palette area's
 * VRAM base in gGxTexLoad; the copy runs through the GX DMA channel when one is
 * owned and on the CPU otherwise. */
void GX_LoadTexPltt(M2C_UNK src, M2C_UNK offset, M2C_UNK size) {
    M2C_UNK DmaCopyAsync(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxTexLoad;
    s32 paletteBase = M2C_FIELD(&gGxTexLoad, s32 *, GX_TEXLOAD_TEXPLTT_BASE);
    if (gGxDmaChannel != -1) {
        DmaCopyAsync(gGxDmaChannel, src, paletteBase + (s32)offset, size, 0, 0);
        return;
    }
    MIi_CpuCopy32(src, paletteBase + (s32)offset, (u32)size);
}

void func_02004ddc(void) {
    M2C_UNK DmaWaitChannel(s32);
    M2C_UNK GX_SetBankForOBJExtPltt(M2C_UNK);
    extern s32 gGxDmaChannel;
    extern M2C_UNK gGxTexLoad;
    if (gGxDmaChannel != -1) {
        DmaWaitChannel(gGxDmaChannel);
    }
    GX_SetBankForOBJExtPltt(M2C_FIELD(&gGxTexLoad, M2C_UNK *, 0xc));
    M2C_FIELD(&gGxTexLoad, M2C_UNK *, 0xc) = 0;
    M2C_FIELD(&gGxTexLoad, M2C_UNK *, 0x8) = 0;
}

typedef u32 Block3[3];
#pragma opt_common_subs off
void func_02004e20(FuncCopyV3 *src, FuncCopyV3 *dst) {
volatile FuncCopyV3 *d=dst;
*d=*src++; *d=*src++; *d=*src++; *d=*src++;
}
#pragma opt_common_subs reset
void func_02004e44(void *arg0, void *arg1) {
    u32 *s = arg0;
    u32 *d = arg1;
    s32 i;
    for (i = 0; i < 16; i++) {
        d[i] = s[i];
    }
}

#pragma scheduling off
void func_02004e60(s32 arg0,u32 mask) {
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void OS_SleepThread(s32);
extern M2C_UNK gOsArea,data_027e00e0;
s32 ret=OS_DisableInterrupts();
if(arg0) M2C_FIELD(&gOsArea,volatile u32 *,0x3ff8)&=~mask;
OS_RestoreInterrupts(ret);
if(!(mask&M2C_FIELD(&gOsArea,volatile u32 *,0x3ff8))) {
do{OS_SleepThread((s32)&data_027e00e0);}while(!(mask&M2C_FIELD(&gOsArea,volatile u32 *,0x3ff8)));
}
}
#pragma scheduling reset
void func_02004ed4(void) {

}

void func_02004ed8(s32 arg0) {
 void OS_DisableIrqMask(s32);
 extern M2C_UNK gDmaTimerIrqHandlers, data_020f5208, data_0212dc24, gOsArea, data_0212dc20;
 s32 field20; u16 shift;
 u32 mask;
 void (*saved)(void *);
 saved = M2C_FIELD(&gDmaTimerIrqHandlers, void (**)(void *), arg0*12);
 shift=M2C_FIELD(&data_020f5208,u16 *,arg0*2);
 mask=1;
 mask<<=shift;
 M2C_FIELD(&gDmaTimerIrqHandlers, void (**)(void *),arg0*12)=0;
 if(saved) saved(M2C_FIELD(&data_0212dc24,void **,arg0*12));
 field20=M2C_FIELD(&data_0212dc20,s32 *,arg0*12);
 M2C_FIELD(&gOsArea,u32 *,0x3ff8) |= mask;
 if(field20==0) OS_DisableIrqMask(mask);
}

void func_02004f60(void) {
    void func_02004ed8(s32);
    func_02004ed8(0);
}

void func_02004f70(void) {
    func_02004ed8(1);
}

void func_02004f80(void) {
    func_02004ed8(2);
}

void func_02004f90(void) {
    func_02004ed8(3);
}

void func_02004fa0(void) {
    func_02004ed8(4);
}

void func_02004fb0(void) {
    func_02004ed8(5);
}

void func_02004fc0(void) {
    func_02004ed8(6);
}

void func_02004fd0(void) {
    func_02004ed8(7);
}

void func_02004fe0(void) {
    extern M2C_UNK data_027e00e0;
    M2C_FIELD(&data_027e00e0, s32 *, 4) = 0;
    M2C_FIELD(&data_027e00e0, s32 *, 0) = 0;
}

