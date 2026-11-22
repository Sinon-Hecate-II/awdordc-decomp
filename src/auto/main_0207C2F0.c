/* 43 functions from 0x0207C2F0 to 0x0207D130 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "hw_div.h"
typedef struct { s32 x,y,z; } Vec0207;
extern Vec0207 gMapViewUpVector;

typedef struct Unk0207Color { u32 words[4]; } Unk0207Color;
#define VIEW_PRESET_WIDTH  0x0C /* u8 at +0xC: view width in tiles */
#define VIEW_PRESET_HEIGHT 0x0D /* u8 at +0xD: view height in tiles */
Unk0207Color GetViewZoomPreset(s32);
typedef struct { u16 mode:3; u16 rest:13; } Mode0207;
extern Mode0207 gMapConfig;
extern Unk0207Color data_021017f4[4];
extern void **gCurrentMap;
s32 EaseInterpolate(s32, s32, s32, s32, s32);

s32 NextRandomValue(void) {
    s32 Divide(s32, M2C_UNK);
    extern s32 gRandomSeed;
    s32 temp_r2;
    s32 temp_r4;
    temp_r2 = (gRandomSeed * 4) + 2;
    temp_r4 = temp_r2 * (temp_r2 + 1);
    return gRandomSeed = (temp_r4 + Divide(temp_r4 & ~0x80000000, 7)) & ~0x80000000;
}

s32 RandomIntRange(s32 arg0, s32 arg1) {
    s32 Modulo(s32, s32);
    s32 temp;
    if (arg0 == arg1) return arg0;
    if (arg0 > arg1) {
        temp = arg0;
        arg0 = arg1;
        arg1 = temp;
    }
    return arg0 + Modulo(NextRandomValue() & 0x7fffffff, arg1 - arg0 + 1);
}

s32 StringHasTerminator(u8 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++, arg0++) {
        if (*arg0 == 0) return 1;
    }
    return 0;
}

void func_0207c39c(void *arg0) {
    M2C_UNK MI_CpuCopy32(s32, s32, s32);
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 flags = M2C_FIELD(arg0, s32 *, 0x40);
    s32 src = M2C_FIELD(arg0, s32 *, 0x38);
    s32 dst = M2C_FIELD(arg0, s32 *, 0x3C);
    if (flags & 3) {
        MI_CpuCopy8(src, dst, flags);
    } else {
        MI_CpuCopy32(src, dst, flags);
    }
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) return;
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x38));
}

void QueueMemoryCopy(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK SetSpriteZ(void *, s32);
    void *CreateQueuedSpriteTask(M2C_UNK *, M2C_UNK);
    void func_0207c39c(void *);
    void *temp_r0;

    temp_r0 = CreateQueuedSpriteTask((M2C_UNK *)&func_0207c39c, 2);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x50) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    SetSpriteZ(temp_r0, 0xFF02);
}

void func_0207c42c(void *arg0) {
    M2C_UNK func_02004b54();
    M2C_UNK LoadTextureBankBlock(s32, s32, s32);
    M2C_UNK func_02004cf0();
    M2C_UNK HeapFreeBlock(s32);
    func_02004b54();
    LoadTextureBankBlock(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
    func_02004cf0();
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        return;
    }
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_0207c464(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_r0;

    temp_r0 = CreateQueuedSpriteTask(&func_0207c42c, 0);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x50) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    SetSpriteZ(temp_r0, 0xFF02);
}

void CopyMainOBJExtPaletteWordsTask(void *arg0) {
    M2C_UNK func_02004d3c();
    M2C_UNK GX_LoadTexPltt(s32, s32, s32);
    M2C_UNK func_02004ddc();
    func_02004d3c();
    GX_LoadTexPltt(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
    func_02004ddc();
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        return;
    }
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x38));
}

/* Fill a range of the main-engine OBJ extended palette with one halfword: release
 * the palette's bank grant, look up the VRAM base for the banks it gave back, fill
 * the task's destination halfwords from the task's source, then re-grant the bank
 * and free the source when the task owns it.  The range is a byte count and a
 * byte offset; the fill writes halfwords. */
void FillMainOBJExtPaletteHalfwordsTask(void *task) {
    s32 GX_ReleaseBankForOBJExtPltt(void);
    M2C_UNK GX_SetBankForOBJExtPltt(s32);
    extern u16 gExtPaletteVramBase[];
    s32 base;
    s32 count;
    s32 offset;
    s32 banks;
    count = M2C_FIELD(task, s32 *, DS3D_TASK_SIZE);
    offset = M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET);
    banks = GX_ReleaseBankForOBJExtPltt();
    base = gExtPaletteVramBase[banks >> 4] << 12;
    if (base == 0) return;
    if (count > 0) {
        do {
            count -= 2;
            *(u16 *)(base + offset) = *M2C_FIELD(task, u16 **, DS3D_TASK_SOURCE);
            offset += 2;
        } while (count > 0);
    }
    GX_SetBankForOBJExtPltt(banks);
    if (M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) == 0) return;
    HeapFreeBlock(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE));
}

/* Queue a main OBJ extended palette upload, using a halfword fill for unaligned ranges. */
void QueueMainOBJExtPaletteCopy(s32 source, s32 paletteOffset, s32 byteCount, s32 freeSource) {
    void FillMainOBJExtPaletteHalfwordsTask(void *);
    void *task;

    if (!(byteCount & 3) && !(paletteOffset & 3)) {
        task = CreateQueuedSpriteTask(&CopyMainOBJExtPaletteWordsTask, 0);
    } else {
        task = CreateQueuedSpriteTask(&FillMainOBJExtPaletteHalfwordsTask, 0);
    }
    M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE) = source;
    M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET) = paletteOffset;
    M2C_FIELD(task, s32 *, DS3D_TASK_SIZE) = byteCount;
    M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) = freeSource;
    M2C_FIELD(task, s32 *, 0x48) = 0;
    M2C_FIELD(task, s32 *, 0x4C) = 0;
    SetSpriteZ(task, DS3D_COPY_TASK_Z);
}

/* Run a queued BG extended-palette upload: copy the task's palette to the BG
 * extended-palette area of the main engine, or of the sub engine when that is
 * the screen being drawn, then free the source block if the task owns it. */
void UploadBGExtPaletteTask(void *task) {
    M2C_UNK GX_BeginLoadBGExtPltt(void);
    M2C_UNK GX_LoadBGExtPltt(s32, s32, s32);
    M2C_UNK GX_EndLoadBGExtPltt(void);
    M2C_UNK GX_BeginLoadBGExtPlttSub(void);
    M2C_UNK GX_LoadBGExtPlttSub(s32, s32, s32);
    M2C_UNK GX_EndLoadBGExtPlttSub(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    if ((u8)(gCur3DSpriteEngine == g3DSpriteEngineMain)) {
        GX_BeginLoadBGExtPltt();
        GX_LoadBGExtPltt(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE), M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET), M2C_FIELD(task, s32 *, DS3D_TASK_SIZE));
        GX_EndLoadBGExtPltt();
    } else {
        GX_BeginLoadBGExtPlttSub();
        GX_LoadBGExtPlttSub(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE), M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET), M2C_FIELD(task, s32 *, DS3D_TASK_SIZE));
        GX_EndLoadBGExtPlttSub();
    }
    if (M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) == 0) return;
    HeapFreeBlock(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE));
}

/* Queue an upload of `byteCount` bytes from `source` into the BG extended
 * palette at `offset`, `slot` (0x2000 bytes each) further into it; free the
 * source block after the upload when `freeSource` is set. */
void QueueBGExtPaletteUpload(s32 source, s32 slot, s32 offset, s32 byteCount, u8 freeSource) {
    void UploadBGExtPaletteTask(void *);
    void *task;

    task = CreateQueuedSpriteTask(&UploadBGExtPaletteTask, 0);
    M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE) = source;
    M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET) = (s32) (offset + (slot << 0xD));
    M2C_FIELD(task, s32 *, DS3D_TASK_SIZE) = byteCount;
    M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) = (s32) freeSource;
    M2C_FIELD(task, s32 *, 0x48) = 0;
    M2C_FIELD(task, s32 *, 0x4C) = 0;
    SetSpriteZ(task, DS3D_COPY_TASK_Z);
}

/* Run a queued OBJ extended-palette upload: copy the task's palette to the OBJ
 * extended-palette area of the main engine, or of the sub engine when that is
 * the screen being drawn, then free the source block if the task owns it. */
void UploadOBJExtPaletteTask(void *task) {
    M2C_UNK GX_BeginLoadOBJExtPltt(void);
    M2C_UNK GX_LoadOBJExtPltt(s32, s32, s32);
    M2C_UNK GX_EndLoadOBJExtPltt(void);
    M2C_UNK GX_BeginLoadOBJExtPlttSub(void);
    M2C_UNK GX_LoadOBJExtPlttSub(s32, s32, s32);
    M2C_UNK GX_EndLoadOBJExtPlttSub(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    if ((u8)(gCur3DSpriteEngine == g3DSpriteEngineMain)) {
        GX_BeginLoadOBJExtPltt();
        GX_LoadOBJExtPltt(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE), M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET), M2C_FIELD(task, s32 *, DS3D_TASK_SIZE));
        GX_EndLoadOBJExtPltt();
    } else {
        GX_BeginLoadOBJExtPlttSub();
        GX_LoadOBJExtPlttSub(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE), M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET), M2C_FIELD(task, s32 *, DS3D_TASK_SIZE));
        GX_EndLoadOBJExtPlttSub();
    }
    if (M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) == 0) return;
    HeapFreeBlock(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE));
}

/* Queue an upload of `byteCount` bytes from `source` into the OBJ extended
 * palette at `offset`, `slot` (0x2000 bytes each) further into it; free the
 * source block after the upload when `freeSource` is set. */
void QueueOBJExtPaletteUpload(s32 source, s32 slot, s32 offset, s32 byteCount, u8 freeSource) {
    void UploadOBJExtPaletteTask(void *);
    void *task;

    task = CreateQueuedSpriteTask(&UploadOBJExtPaletteTask, 0);
    M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE) = source;
    M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET) = (s32) (offset + (slot << 0xD));
    M2C_FIELD(task, s32 *, DS3D_TASK_SIZE) = byteCount;
    M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) = (s32) freeSource;
    M2C_FIELD(task, s32 *, 0x48) = 0;
    M2C_FIELD(task, s32 *, 0x4C) = 0;
    SetSpriteZ(task, DS3D_COPY_TASK_Z);
}

void LoadGraphicsBlock(void *arg0, u32 arg1) {
    M2C_UNK MI_CpuCopy32(s32, s32, s32);
    extern void (*data_02101448[])();
    void (*func)();
    u8 index = (s32)(M2C_FIELD(arg0, u8 *, 0) & 0xF0) >> 3;
    if (arg1 < 0x04000000U) index++;
    func = data_02101448[index];
    if (func == NULL) {
        MI_CpuCopy32((s32)arg0, arg1, M2C_FIELD(arg0, u32 *, 0) >> 8);
        return;
    }
    func(arg0, arg1);
}

u32 GetDecompressedSize(u32 *arg0) {
    return (u32) *arg0 >> 8;
}

/* Set up the chunked decompressor for a compressed block: record its type and
 * whether the output lies outside main RAM (VRAM is written 16 bits at a time),
 * initialise that type's decoder state and return the decompressed size. */
u32 InitDecompress(DecompressState *state, u32 *header, u32 dest) {
    M2C_UNK InitLz77Decompress(void *, u32, u32 *);
    M2C_UNK InitHuffmanDecompress(void *, u32, u32 *);
    M2C_UNK InitRleDecompress(void *, u32, u32 *);
    s8 vramFlag;
    u8 compType;

    state->compType = (u8) (*header & 0xF0);
    if (dest >= 0x04000000U) {
        vramFlag = 1;
    } else {
        vramFlag = 0;
    }
    state->vramFlag = vramFlag;
    compType = state->compType;
    switch (compType) {                             /* irregular */
    case COMP_TYPE_LZ77:
        InitLz77Decompress((u8 *)state + 4, dest, header);
        break;
    case COMP_TYPE_HUFFMAN:
        InitHuffmanDecompress((u8 *)state + 4, dest, header);
        break;
    case COMP_TYPE_RLE:
        InitRleDecompress((u8 *)state + 4, dest, header);
        break;
    }
    return (u32) *header >> 8;
}

/* Run one chunk of a compressed block through the decoder its type byte selects:
 * LZ77, Huffman or RLE, with the byte or 16-bit output variant the decoder's
 * flags byte asks for.  Returns the output bytes still to produce. */
s32 DecompressChunk(void *decoder, u32 src, u32 size) {
    s32 RleDecompress8Bit(void *, u32, u32);
    s32 RleDecompress16Bit(void *, u32, u32);
    s32 Lz77Decompress8Bit(void *, u32, u32);
    s32 Lz77Decompress16Bit(void *, u32, u32);
    s32 HuffmanDecompress(void *, u32, u32);
    s32 (*decompress)(void *, u32, u32);
    s32 remaining = 0;
    switch (M2C_FIELD(decoder, u8 *, 0)) {
    case COMP_TYPE_LZ77:
        decompress = M2C_FIELD(decoder, u8 *, 1) == 0 ? Lz77Decompress8Bit : Lz77Decompress16Bit;
        remaining = decompress(decoder + 4, src, size);
        break;
    case COMP_TYPE_HUFFMAN:
        remaining = HuffmanDecompress(decoder + 4, src, size);
        break;
    case COMP_TYPE_RLE:
        decompress = M2C_FIELD(decoder, u8 *, 1) == 0 ? RleDecompress8Bit : RleDecompress16Bit;
        remaining = decompress(decoder + 4, src, size);
        break;
    }
    return remaining;
}

s32 Divide(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A0;
}

s32 Modulo(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A8;
}

/* Hardware 32-bit divide: start the ARM9 divider with the numerator and
   denominator, then read the quotient and the remainder. */
void DivMod(s32 numerator, s32 denominator, s32 *quotient, s32 *remainder) {
    REG_DIVCNT = 0;
    REG_DIV_NUMER = numerator;
    REG_DIV_DENOM = (u32)denominator;
    while (REG_DIVCNT & DIVCNT_BUSY) {}
    *quotient = REG_DIV_RESULT;
    while (REG_DIVCNT & DIVCNT_BUSY) {}
    *remainder = REG_DIVREM_RESULT;
}

s32 func_0207c9c8(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 2;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s32 *)0x04000294 = 0;
    *(volatile s32 *)0x04000298 = arg1;
    *(volatile s32 *)0x0400029C = 0;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A0;
}

s32 func_0207ca08(s32 arg0) {
    *(volatile u16 *)0x040002B0 = 0;
    *(volatile s32 *)0x040002B8 = arg0;
    while (*(volatile u16 *)0x040002B0 & 0x8000) {}
    return *(volatile s32 *)0x040002B4;
}

/* Eased interpolation from `from` to `to` after `elapsed` of `duration` frames:
 * mode picks the curve, one of the EASE_* easing modes. */
s32 EaseInterpolate(s32 mode,s32 from,s32 to,s32 elapsed,s32 duration) {
s32 remaining;
if(duration==0)return to;
switch(mode){
case EASE_LINEAR:return from+Divide(elapsed*(to-from),duration);
case EASE_IN_QUAD:return from+Divide((to-from)*(elapsed*elapsed),duration*duration);
case EASE_IN_CUBIC:return from+Divide((to-from)*(elapsed*(elapsed*elapsed)),duration*(duration*duration));
case EASE_IN_QUART:return from+Divide((to-from)*(elapsed*(elapsed*(elapsed*elapsed))),duration*(duration*(duration*duration)));
case EASE_OUT_QUAD:remaining=duration-elapsed;return to-Divide((to-from)*(remaining*remaining),duration*duration);
case EASE_OUT_CUBIC:remaining=duration-elapsed;return to-Divide((to-from)*(remaining*(remaining*remaining)),duration*(duration*duration));
default:return 0;
}}

s32 IntPow(s32 arg0, s32 arg1) {
    if (arg1 < 0) {
        return 0;
    }
    if (arg1 == 0) {
        return 1;
    }
    return arg0 * IntPow(arg0, arg1 - 1);
}

s32 GetDigitCount(s32 arg0) {
    s32 Divide(s32, M2C_UNK);
    s32 var_r0;
    s32 var_r5;

    var_r0 = arg0;
    var_r5 = 0;
    do {
        var_r0 = Divide(var_r0, 0xA);
        var_r5 += 1;
    } while (var_r0 != 0);
    return var_r5;
}

void func_0207cbb0(void) {
    M2C_UNK InitMapViewCameraVectors(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0214bfac;
    InitMapViewCameraVectors(&data_0214bfac, 0, 0, 0);
}

#pragma opt_if-conversion off
Unk0207Color GetViewZoomPreset(s32 index) {
    Unk0207Color v = data_021017f4[(u8)gMapConfig.mode != 2 ? index : (index + 2)];
    u8 *base;
    s32 limit;

    base = *gCurrentMap;
    limit = *(u16 *)(base + 0x5144);
    if (((u8 *)&v)[12] > limit) {
        ((u8 *)&v)[12] = limit;
        v.words[0] = (((u8 *)&v)[12] - 1) * 0x180;
    }
    limit = *(u16 *)(base + 0x5146);
    if (((u8 *)&v)[13] > limit) {
        ((u8 *)&v)[13] = limit;
        v.words[1] = (((u8 *)&v)[13] - 1) * 0x180;
    }
    return v;
}
#pragma opt_if-conversion reset
M2C_UNK InitMapViewCameraVectors(M2C_UNK *view, M2C_UNK eyeX, M2C_UNK eyeY, M2C_UNK eyeZ) {
    struct Unk3 { s32 a; s32 b; s32 c; };
    extern struct Unk3 data_020ebdc4;
    extern struct Unk3 data_020ebdd0;
    struct Unk3 zero = { 0, 0, 0 };

    /* Seed the camera's eye, ground-plane and up vectors, then save its initial eye point. */
    *(struct Unk3 *)((u8 *)view + 0xF0) = data_020ebdc4;
    *(struct Unk3 *)((u8 *)view + 0xFC) = zero;
    *(struct Unk3 *)((u8 *)view + 0x108) = data_020ebdd0;
    M2C_FIELD(view, s32 *, 0x10) = eyeX;
    M2C_FIELD(view, s32 *, 0x14) = eyeY;
    M2C_FIELD(view, s32 *, 0x18) = eyeZ;
}

/* Rebuilds the map view's camera transform from its eye position: stores the eye
 * point, its ground projection and the up axis into the view object, builds the
 * view matrix from them and inverts it into the view's inverse matrix. */
void BuildMapViewTransform(void *view) {
    void func_0200402c(void *, void *, void *, s32, void *);
    void MTX_Copy33(void *, void *);
    M2C_UNK func_02000ca0(void *, s32);
    Vec0207 eye = {0, 0, 0};
    Vec0207 ground = {0, 0, 0};
    Vec0207 up = gMapViewUpVector;
    s32 matrix[9];

    eye.x = M2C_FIELD(view, s32 *, 0x10);
    eye.y = M2C_FIELD(view, s32 *, 0x14);
    eye.z = M2C_FIELD(view, s32 *, 0x18);
    ground.x = M2C_FIELD(view, s32 *, 0x10);
    ground.y = M2C_FIELD(view, s32 *, 0x14);
    ground.z = 0;
    *(Vec0207 *)((u8 *)view + 0xf0) = eye;
    *(Vec0207 *)((u8 *)view + 0xfc) = ground;
    *(Vec0207 *)((u8 *)view + 0x108) = up;
    func_0200402c(&eye, &up, &ground, 1, (u8 *)view + 0x1c);
    MTX_Copy33((u8 *)view + 0x1c, matrix);
    func_02000ca0(matrix, (s32)view + 0x4c);
}

void func_0207cddc(s32 arg0, M2C_UNK arg1) {
 M2C_UNK func_02000ca0(void *, s32);
 M2C_UNK Matrix3x4To4x4(s32, void *);
 M2C_UNK func_02001524(s32, void *);
 M2C_UNK func_02001748(void *, M2C_UNK, s32);
 s32 sp24[16];
 s32 sp0[9];
 Matrix3x4To4x4(arg0 + 0x1C, sp24);
 func_02001748(sp24, arg1, arg0 + 0x70);
 func_02001524(arg0 + 0x70, sp0);
 func_02000ca0(sp0, arg0 + 0xB0);
}

void func_0207ce28(M2C_UNK arg0) {
    M2C_UNK UpdateViewForZoom(M2C_UNK);
    M2C_UNK ApplyViewZoomOption(M2C_UNK);
    InitMapViewCameraVectors(arg0, 0, 0, 0);
    ApplyViewZoomOption(arg0);
    UpdateViewForZoom(arg0);
}

void func_0207ce54(void) {
    M2C_UNK UpdateMapViewEye();
    UpdateMapViewEye();
}

/* Recompute the map view's eye position (view+0x10/+0x14/+0x18): the view's
 * zoom-scaled offset plus the map scroll in view units, half a cell in. */
M2C_UNK UpdateMapViewEye(void *view) {
 extern void **gCurrentMap;
 M2C_FIELD(view,s32 *,0x10) = M2C_FIELD(view,s32 *,0) + ((M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X) * (s16)MAP_VIEW_EYE_CELL) >> 4) + MAP_VIEW_EYE_HALF_CELL;
 M2C_FIELD(view,s32 *,0x14) = M2C_FIELD(view,s32 *,4) + ((M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y) * (s16)MAP_VIEW_EYE_CELL) >> 4) + MAP_VIEW_EYE_HALF_CELL;
 M2C_FIELD(view,s32 *,0x18) = M2C_FIELD(view,s32 *,8);
}

void SetViewZoom(void *arg0, s16 arg1) {
    void func_0207cfb0(void *, s16);
    M2C_UNK UpdateViewForZoom(M2C_UNK);
    void SaveViewZoomOption(void *);
    func_0207cfb0(arg0, arg1);
    UpdateViewForZoom((M2C_UNK)arg0);
    SaveViewZoomOption(arg0);
}

/* The map view's tile height at zoom fraction zoom (0 = zoomed in, 0x80 = zoomed
 * out): the height bytes of the two zoom presets eased between. */
void GetViewHeightForZoom(s32 zoom) {
    Unk0207Color zoomedIn = GetViewZoomPreset(0);
    Unk0207Color zoomedOut = GetViewZoomPreset(1);
    EaseInterpolate(EASE_LINEAR, ((u8 *)&zoomedIn)[VIEW_PRESET_HEIGHT], ((u8 *)&zoomedOut)[VIEW_PRESET_HEIGHT], zoom, 0x80);
}

/* The map view's tile width at zoom fraction zoom (0 = zoomed in, 0x80 = zoomed
   out): the width bytes of the two zoom presets eased between. */
s32 GetViewWidthForZoom(s32 zoom) {
    Unk0207Color zoomedIn = GetViewZoomPreset(0);
    Unk0207Color zoomedOut = GetViewZoomPreset(1);
    return EaseInterpolate(EASE_LINEAR, ((u8 *)&zoomedIn)[VIEW_PRESET_WIDTH], ((u8 *)&zoomedOut)[VIEW_PRESET_WIDTH], zoom, 0x80);
}

void func_0207cfb0(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xE) = arg1;
}

s16 GetViewZoom(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xE);
}

/* Interpolate the two preset colors (indices 0 and 1) by t/128 and store the result in p. */
M2C_UNK UpdateViewForZoom(M2C_UNK arg) {
    void *p = (void *)arg;
    Unk0207Color colorA = GetViewZoomPreset(0);
    Unk0207Color colorB = GetViewZoomPreset(1);
    s32 t = GetViewZoom(p);

    M2C_FIELD(p, s32 *, 0) = EaseInterpolate(0, colorA.words[0], colorB.words[0], t, 128);
    M2C_FIELD(p, s32 *, 4) = EaseInterpolate(0, colorA.words[1], colorB.words[1], t, 128);
    M2C_FIELD(p, s32 *, 8) = EaseInterpolate(0, colorA.words[2], colorB.words[2], t, 128);
    M2C_FIELD(p, u8 *, 12) = EaseInterpolate(0, ((u8 *)&colorA)[12], ((u8 *)&colorB)[12], t, 128);
    M2C_FIELD(p, u8 *, 13) = EaseInterpolate(0, ((u8 *)&colorA)[13], ((u8 *)&colorB)[13], t, 128);
}

u8 GetMapViewWidth(void) {
    extern void **gCurrentMap;
    return M2C_FIELD(*gCurrentMap, u8 *, 0x6F04);
}

u8 GetMapViewHeight(void) {
 extern void **gCurrentMap;
 return M2C_FIELD(*gCurrentMap, u8 *, 0x6F05);
}

void DrawSprite3DGeometry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6) {
 M2C_UNK func_0207d130(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 func_0207d130(arg0,arg1,arg2,arg3,arg4,arg5,arg6,0,0,0,0);
}

