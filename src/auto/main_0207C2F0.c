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

/* Advance gRandomSeed one step of the game's pseudo-random generator and return
 * the new value, kept non-negative. */
s32 NextRandomValue(void) {
    s32 Divide(s32, M2C_UNK);
    extern s32 gRandomSeed;
    s32 base;
    s32 mixed;

    base = (gRandomSeed * 4) + 2;
    mixed = base * (base + 1);
    return gRandomSeed = (mixed + Divide(mixed & ~0x80000000, 7)) & ~0x80000000;
}

/* Return a random integer in [min, max], bounds included: order the two bounds
 * first, then spread the generator's 31-bit value over the range's size. */
s32 RandomIntRange(s32 min, s32 max) {
    s32 Modulo(s32, s32);
    s32 temp;
    if (min == max) return min;
    if (min > max) {
        temp = min;
        min = max;
        max = temp;
    }
    return min + Modulo(NextRandomValue() & 0x7fffffff, max - min + 1);
}

/* Return 1 when a NUL terminator occurs within the first `length` bytes of
 * `string`, 0 when the whole range is non-zero (a full, unterminated field). */
s32 StringHasTerminator(u8 *string, s32 length) {
    s32 i;
    for (i = 0; i < length; i++, string++) {
        if (*string == 0) return 1;
    }
    return 0;
}

/* Run a queued memory-copy task: copy the task's byte count from its source to its
 * destination (byte by byte when the count is not a whole number of words, in
 * 32-bit words otherwise), then free the source block when the task owns it. */
void RunMemoryCopyTask(void *task) {
    M2C_UNK MI_CpuCopy32(s32, s32, s32);
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 size = M2C_FIELD(task, s32 *, DS3D_TASK_SIZE);
    s32 src = M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE);
    s32 dst = M2C_FIELD(task, s32 *, DS3D_TASK_DEST);
    if (size & 3) {
        MI_CpuCopy8(src, dst, size);
    } else {
        MI_CpuCopy32(src, dst, size);
    }
    if (M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) == 0) return;
    HeapFreeBlock(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE));
}

/* Queue a memory copy: the task runner copies `size` bytes from `source` to
 * `dest` (32-bit words when the size is word-aligned, bytes otherwise) and frees
 * the source block afterwards when `freeSource` is set. */
void QueueMemoryCopy(s32 source, s32 dest, s32 size, s32 freeSource) {
    M2C_UNK SetSpriteZ(void *, s32);
    void *CreateQueuedSpriteTask(M2C_UNK *, M2C_UNK);
    void RunMemoryCopyTask(void *);
    void *task;

    task = CreateQueuedSpriteTask((M2C_UNK *)&RunMemoryCopyTask, 2);
    M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE) = source;
    M2C_FIELD(task, s32 *, DS3D_TASK_DEST) = dest;
    M2C_FIELD(task, s32 *, DS3D_TASK_SIZE) = size;
    M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) = freeSource;
    M2C_FIELD(task, s32 *, 0x48) = 0;
    M2C_FIELD(task, s32 *, 0x4C) = 0;
    SetSpriteZ(task, DS3D_COPY_TASK_Z);
}

/* Run a queued texture-bank copy: upload the task's source block into the 3D
 * texture area at the task's byte offset, then free the source block when the
 * task owns it. */
void TextureBankCopyTask(void *task) {
    M2C_UNK GX_BeginLoadTex();
    M2C_UNK LoadTextureBankBlock(s32, s32, s32);
    M2C_UNK GX_EndLoadTex();
    M2C_UNK HeapFreeBlock(s32);
    GX_BeginLoadTex();
    LoadTextureBankBlock(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE), M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET), M2C_FIELD(task, s32 *, DS3D_TASK_SIZE));
    GX_EndLoadTex();
    if (M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) == 0) {
        return;
    }
    HeapFreeBlock(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE));
}

/* Queue a copy of `size` bytes from `source` into the texture-bank region at byte
 * `offset`; the source block is freed afterwards when `freeSource` is set. */
void QueueTextureBankCopy(s32 source, s32 offset, s32 size, s32 freeSource) {
    void *task;

    task = CreateQueuedSpriteTask(&TextureBankCopyTask, 0);
    M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE) = source;
    M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET) = offset;
    M2C_FIELD(task, s32 *, DS3D_TASK_SIZE) = size;
    M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) = freeSource;
    M2C_FIELD(task, s32 *, 0x48) = 0;
    M2C_FIELD(task, s32 *, 0x4C) = 0;
    SetSpriteZ(task, DS3D_COPY_TASK_Z);
}

void CopyMainOBJExtPaletteWordsTask(void *task) {
    M2C_UNK GX_BeginLoadTexPltt();
    M2C_UNK GX_LoadTexPltt(s32, s32, s32);
    M2C_UNK GX_EndLoadTexPltt();

    /* Upload the queued palette block to texture-palette VRAM, then free it when owned by the task. */
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE), M2C_FIELD(task, s32 *, DS3D_TASK_OFFSET), M2C_FIELD(task, s32 *, DS3D_TASK_SIZE));
    GX_EndLoadTexPltt();
    if (M2C_FIELD(task, s32 *, DS3D_TASK_FREE_SOURCE) == 0) {
        return;
    }
    HeapFreeBlock(M2C_FIELD(task, s32 *, DS3D_TASK_SOURCE));
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

/* Decompress the graphics block `block` into `dest`: its header's type nibble
 * selects the compression type and the handler table holds a VRAM and a main-RAM
 * variant of each type (the RAM one an entry further).  A type without a handler
 * is uncompressed and copied word for word. */
void LoadGraphicsBlock(void *block, u32 dest) {
    M2C_UNK MI_CpuCopy32(s32, s32, s32);
    extern void (*gDecompressBlockHandlers[])();
    void (*handler)();
    u8 index = (s32)(M2C_FIELD(block, u8 *, COMP_BLOCK_WORD) & COMP_BLOCK_TYPE_MASK) >> 3;
    if (dest < COMP_BLOCK_RAM_END) index++;
    handler = gDecompressBlockHandlers[index];
    if (handler == NULL) {
        MI_CpuCopy32((s32)block, dest, M2C_FIELD(block, u32 *, COMP_BLOCK_WORD) >> COMP_BLOCK_SIZE_SHIFT);
        return;
    }
    handler(block, dest);
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

/* Signed 32-bit quotient from the ARM9's hardware divider. */
s32 Divide(s32 numerator, s32 denominator) {
    REG_DIVCNT = 0;
    REG_DIV_NUMER = numerator;
    REG_DIV_DENOM = (u32) denominator;
    while (REG_DIVCNT & DIVCNT_BUSY) {}
    return REG_DIV_RESULT;
}

/* Signed 32-bit remainder from the ARM9's hardware divider. */
s32 Modulo(s32 numerator, s32 denominator) {
    REG_DIVCNT = 0;
    REG_DIV_NUMER = numerator;
    REG_DIV_DENOM = (u32) denominator;
    while (REG_DIVCNT & DIVCNT_BUSY) {}
    return REG_DIVREM_RESULT;
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

/* Unsigned 32-bit division on the ARM9 divider: the numerator is written as a
 * zero-extended 64-bit value (division mode 2), so both operands are treated as
 * unsigned, and the quotient is returned. */
s32 UnsignedDivide(s32 numerator, s32 denominator) {
    REG_DIVCNT = 2;
    REG_DIV_NUMER64 = (u32) numerator;
    REG_DIV_DENOM = (u32) denominator;
    while (REG_DIVCNT & DIVCNT_BUSY) {}
    return REG_DIV_RESULT;
}

/* Integer square root in the ARM9's square-root hardware: write the operand,
 * wait for the busy bit to clear, then read the result. */
s32 HardwareSquareRoot(s32 value) {
    *(volatile u16 *)REG_SQRTCNT = 0;
    *(volatile s32 *)REG_SQRT_PARAM = value;
    while (*(volatile u16 *)REG_SQRTCNT & SQRTCNT_BUSY) {}
    return *(volatile s32 *)REG_SQRT_RESULT;
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

/* `base` raised to the non-negative integer power `exponent`; a negative
 * exponent yields 0. */
s32 IntPow(s32 base, s32 exponent) {
    if (exponent < 0) {
        return 0;
    }
    if (exponent == 0) {
        return 1;
    }
    return base * IntPow(base, exponent - 1);
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

void InitDefaultMapCamera(void) {
    M2C_UNK InitMapViewCameraVectors(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gDefaultMapCamera;
    InitMapViewCameraVectors(&gDefaultMapCamera, 0, 0, 0);
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
    void G3X_SetCamera(void *, void *, void *, s32, void *);
    void MTX_Copy33(void *, void *);
    M2C_UNK MTX_Inverse33(void *, s32);
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
    G3X_SetCamera(&eye, &up, &ground, 1, (u8 *)view + 0x1c);
    MTX_Copy33((u8 *)view + 0x1c, matrix);
    MTX_Inverse33(matrix, (s32)view + 0x4c);
}

/* Compose the map view's view and projection matrices: expand the view's affine
 * 3x4 eye matrix to 4x4, multiply it by `projection` into view+MAP_VIEW_PROJECTION,
 * then store the inverse of that matrix's 3x3 part at view+MAP_VIEW_MATRIX, which
 * the view uses to unproject screen points back into map space. */
void BuildMapViewScreenTransform(void *view, M2C_UNK projection) {
    M2C_UNK MTX_Inverse33(void *, s32);
    M2C_UNK Matrix3x4To4x4(s32, void *);
    M2C_UNK MTX_Copy33From44(s32, void *);
    M2C_UNK MTX_Mult4x4(void *, M2C_UNK, s32);
    s32 eyeMatrix[16];
    s32 projection33[9];

    Matrix3x4To4x4((s32)view + 0x1C, eyeMatrix);
    MTX_Mult4x4(eyeMatrix, projection, (s32)view + MAP_VIEW_PROJECTION);
    MTX_Copy33From44((s32)view + MAP_VIEW_PROJECTION, projection33);
    MTX_Inverse33(projection33, (s32)view + MAP_VIEW_MATRIX);
}

/* Reset the map view's camera: put its eye and origin vectors back to the
 * defaults at the map's corner, then apply the player's zoom option and rebuild
 * the zoom-dependent view colours. */
void ResetMapViewCamera(void *view) {
    M2C_UNK UpdateViewForZoom(M2C_UNK);
    M2C_UNK ApplyViewZoomOption(M2C_UNK);
    InitMapViewCameraVectors(view, 0, 0, 0);
    ApplyViewZoomOption(view);
    UpdateViewForZoom(view);
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
    void SetViewZoomField(void *, s16);
    M2C_UNK UpdateViewForZoom(M2C_UNK);
    void SaveViewZoomOption(void *);
    SetViewZoomField(arg0, arg1);
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

void SetViewZoomField(void *arg0, s16 arg1) {
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

/* Submit a sprite frame's 3D geometry: draw each quad of the frame's attribute
 * list with the given texture, palette, scale, rotation and centring flag. */
void DrawSprite3DGeometry(const u16 *attr, const s32 *position, u32 texture, u32 palette,
                          s32 scale, s32 angle, u8 centered) {
    void DrawSpriteFrameQuads(const u16 *, const s32 *, u32, u32, s32, s32, s32, s32, s32, s32, s32);
    DrawSpriteFrameQuads(attr, position, texture, palette, scale, angle, centered, 0, 0, 0, 0);
}

