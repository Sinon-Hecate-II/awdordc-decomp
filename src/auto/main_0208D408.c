/* 7 functions from 0x0208D408 to 0x0208E18C (main), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Draws a horizontal strip of `length` pixels at (x,y) from its right edge
 * leftwards, the mirror of DrawHorizontalBar: the 128/64-pixel head is a flipped
 * rotated quad and the rest is filled with tiles of decreasing width. */
void DrawHorizontalBarReverse(s16 x, s16 y, s16 length, s32 tile, s32 priority) {
    extern s16 gSinCosTable[];
    extern u8 data_020f35ba[];
    extern u8 data_027e007c[];
    extern u8 data_027e00a4[];
    extern u8 data_027e0084[];
    extern void *gCur3DSpriteEngine;
    s32 func_0207c8ec(s32, s32);
    void SetSpriteQuad(s32, s16, s16, s16, s16);
    void AddSprite(u16, u16, u16, void *, s32);

    s16 curY = y;
    s16 curX = x;
    s16 remaining = length;
    s32 tileBase = tile;
    s32 layerPriority = priority;

    if (curY < 0) return;
    if (curY > 0xc0) return;
    if (curX < 0) {
        remaining = (s16)(remaining + curX);
        curX = 0;
    }
    if (curX > 0x100) {
        remaining = (s16)(remaining + (curX - 0x100));
        curX = 0x100;
    }
    {
        s32 sum = curX + remaining;
        if (sum > 0x100) remaining = (s16)(0x100 - curX);
        sum = curX + remaining;
        if (sum < 0) remaining = (s16)(0 - curX);
    }
    curX=(s16)(curX+remaining);
    if (remaining >= 0x40) {
        {
            s16 t0 = gSinCosTable[0];
            s16 t1 = gSinCosTable[1];
            SetSpriteQuad(0x1e,
                (s16)func_0207c8ec((s32)t1 << 4, 0x200),
                (s16)func_0207c8ec((-(s32)t0) << 4, -0x100),
                (s16)func_0207c8ec((s32)t0 << 4, 0x200),
                (s16)func_0207c8ec((s32)t1 << 4, -0x100));
        }
        while (remaining >= 0x80) {
        curX=(s16)(curX-0x80); remaining=(s16)(remaining-0x80);
            AddSprite((u16)((curX & 0x1FF) | 0x3c00),
                          (u16)(((curY - 5) & 0xFF) | 0x300),
                          (u16)tileBase,
                          (void *)data_020f35ba,
                          layerPriority);
        }
        while (remaining >= 0x40) {
        curX=(s16)(curX-0x40); remaining=(s16)(remaining-0x40);
            AddSprite((u16)((curX & 0x1FF) | 0x3c00),
                          (u16)(((curY - 5) & 0xFF) | 0x300),
                          (u16)tileBase,
                          (void *)data_027e007c,
                          layerPriority);
        }
    }
    while (remaining >= 0x20) {
        curX=(s16)(curX-0x20); remaining=(s16)(remaining-0x20);
        AddSprite((u16)((curX & 0x1FF) | 0x2000),
                      (u16)(curY & 0xFF),
                      (u16)tileBase,
                      (void *)data_027e007c,
                      layerPriority);
    }
    while (remaining >= 0x10) {
        curX=(s16)(curX-0x10); remaining=(s16)(remaining-0x10);
        AddSprite((u16)((curX & 0x1FF) | 0x2000),
                      (u16)(curY & 0xFF),
                      (u16)tileBase,
                      (void *)data_027e00a4,
                      layerPriority);
    }
    while (remaining >= 0x8) {
        curX=(s16)(curX-0x8); remaining=(s16)(remaining-0x8);
        AddSprite((u16)((curX & 0x1FF) | 0x2000),
                      (u16)(curY & 0xFF),
                      (u16)tileBase,
                      (void *)data_027e0084,
                      layerPriority);
    }
    while (remaining >= 0x4) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        curX=(s16)(curX-0x4); remaining=(s16)(remaining-0x4);
        AddSprite((u16)((curX & 0x1FF) | 0x2000),
                      (u16)(curY & 0xFF),
                      (u16)(tileBase + (0x3FF & (4 >> (s32)mode))),
                      (void *)data_027e0084,
                      layerPriority);
    }
    while (remaining >= 0x2) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        curX=(s16)(curX-0x2); remaining=(s16)(remaining-0x2);
        AddSprite((u16)((curX & 0x1FF) | 0x2000),
                      (u16)(curY & 0xFF),
                      (u16)(tileBase + (0x3FF & (6 >> (s32)mode))),
                      (void *)data_027e0084,
                      layerPriority);
    }
    while (remaining >= 0x1) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        curX=(s16)(curX-0x1); remaining=(s16)(remaining-0x1);
        AddSprite((u16)((curX & 0x1FF) | 0x2000),
                      (u16)(curY & 0xFF),
                      (u16)(tileBase + (0x3FF & (8 >> (s32)mode))),
                      (void *)data_027e0084,
                      layerPriority);
    }
}
#pragma pop
#pragma push
#pragma opt_lifetimes off
/* Draws a vertical strip of `length` pixels at (x,y) from the bottom of the span
 * upwards, the mirror of DrawVerticalBar: the 128/64-pixel head is a flipped
 * rotated quad and the rest is filled with tiles of decreasing height. */
void DrawVerticalBarReverse(s16 x, s16 y, s16 length, s32 tile, s32 priority) {
    extern s16 gSinCosTable[];
    extern u8 data_020f359e[];
    extern u8 data_027e009c[];
    extern u8 data_027e006c[];
    extern u8 data_027e0084[];
    extern void *gCur3DSpriteEngine;
    s32 func_0207c8ec(s32, s32);
    void SetSpriteQuad(s32, s16, s16, s16, s16);
    void AddSprite(u16, u16, u16, void *, s32);
#define AACC ((void (*)(u16, u16, s32, void *, s32))AddSprite)

    s16 curY = y;
    s16 curX = x;
    s16 remaining = length;
    s32 tileBase = tile;
    s32 layerPriority = priority;

    if (curX < 0) return;
    if (curX > 0x100) return;
    if (curY < 0) {
        remaining = (s16)(remaining + curY);
        curY = 0;
    }
    if (curY > 0xc0) {
        remaining = (s16)(remaining + (curY - 0xc0));
        curY = 0xc0;
    }
    {
        s32 sum = curY + remaining;
        if (sum > 0xc0) remaining = (s16)(0xc0 - curY);
        sum = curY + remaining;
        if (sum < 0) remaining = (s16)(0 - curY);
    }
    curY=(s16)(curY+remaining);
    if (remaining >= 0x40) {
        {
            s16 t0 = gSinCosTable[0];
            s16 t1 = gSinCosTable[1];
            SetSpriteQuad(0x1d,
                (s16)func_0207c8ec((s32)t1 << 4, -0x100),
                (s16)func_0207c8ec((-(s32)t0) << 4, 0x200),
                (s16)func_0207c8ec((s32)t0 << 4, -0x100),
                (s16)func_0207c8ec((s32)t1 << 4, 0x200));
        }
        while (remaining >= 0x80) {
        curY=(s16)(curY-0x80); remaining=(s16)(remaining-0x80);
            AACC((u16)((((curX - 5) & 0x1FF)) | 0x3a00),
                          (u16)((curY & 0xFF) | 0x300),
                          tileBase,
                          (void *)data_020f359e,
                          layerPriority);
            }
        while (remaining >= 0x40) {
        curY=(s16)(curY-0x40); remaining=(s16)(remaining-0x40);
            AACC((u16)((((curX - 5) & 0x1FF)) | 0x3a00),
                          (u16)((curY & 0xFF) | 0x300),
                          tileBase,
                          (void *)data_027e009c,
                          layerPriority);
            }
    }
    while (remaining >= 0x20) {
        curY=(s16)(curY-0x20); remaining=(s16)(remaining-0x20);
        AACC((u16)((curX & 0x1FF) | 0x1000),
                      (u16)(curY & 0xFF),
                      tileBase,
                      (void *)data_027e009c,
                      layerPriority);
    }
    while (remaining >= 0x10) {
        curY=(s16)(curY-0x10); remaining=(s16)(remaining-0x10);
        AACC((u16)((curX & 0x1FF) | 0x1000),
                      (u16)(curY & 0xFF),
                      tileBase,
                      (void *)data_027e006c,
                      layerPriority);
    }
    while (remaining >= 0x8) {
        curY=(s16)(curY-0x8); remaining=(s16)(remaining-0x8);
        AACC((u16)((curX & 0x1FF) | 0x1000),
                      (u16)(curY & 0xFF),
                      tileBase,
                      (void *)data_027e0084,
                      layerPriority);
    }
    while (remaining >= 0x4) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        curY=(s16)(curY-0x4); remaining=(s16)(remaining-0x4);
        AACC((u16)((curX & 0x1FF) | 0x1000),
                      (u16)(curY & 0xFF),
                      (u16)(tileBase + (0x3FF & (4 >> (s32)mode))),
                      (void *)data_027e0084,
                      layerPriority);
    }
    while (remaining >= 0x2) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        curY=(s16)(curY-0x2); remaining=(s16)(remaining-0x2);
        AACC((u16)((curX & 0x1FF) | 0x1000),
                      (u16)(curY & 0xFF),
                      (u16)(tileBase + (0x3FF & (6 >> (s32)mode))),
                      (void *)data_027e0084,
                      layerPriority);
    }
    while (remaining >= 0x1) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        curY=(s16)(curY-0x1); remaining=(s16)(remaining-0x1);
        AACC((u16)((curX & 0x1FF) | 0x1000),
                      (u16)(curY & 0xFF),
                      (u16)(tileBase + (0x3FF & (8 >> (s32)mode))),
                      (void *)data_027e0084,
                      layerPriority);
    }
#undef AACC
}
#pragma pop
void func_0208dd7c(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_UNK DrawHorizontalBar(s16, s16, s16, s32, s32);
    M2C_UNK DrawVerticalBar(s16, s16, s16, s32, s32);
    extern void *gCur3DSpriteEngine;

    switch (arg6) {
        case 1:
            DrawHorizontalBar(arg0, arg1, arg2, arg4, arg5);
            DrawHorizontalBar(arg0, (s16)(arg1 + arg3 - 1), arg2, arg4, arg5);
            DrawVerticalBar(arg0, arg1, (s16)(arg3 - 1),
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            DrawVerticalBar((s16)(arg0 + arg2 - 1), arg1, (s16)(arg3 - 1),
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            break;
        case 2:
            DrawHorizontalBar((s16)(arg0 - 1), (s16)(arg1 - 1), (s16)(arg2 + 2), arg4, arg5);
            DrawHorizontalBar((s16)(arg0 - 1), (s16)(arg1 + arg3 - 1), (s16)(arg2 + 2), arg4, arg5);
            DrawVerticalBar((s16)(arg0 - 1), arg1, arg3,
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            DrawVerticalBar((s16)(arg0 + arg2 - 1), arg1, arg3,
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            break;
    }
}

void func_0208df84(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,s32 arg5) {
 s32 EaseInterpolate(s32,s32,s32,s32,s32);
 void func_0208dd7c(s16,s16,s16,s16,s32,s32,s32);
 extern volatile u32 gFrameCounter;
 s32 n;
 n=((gFrameCounter>>1)&15)<8U ? EaseInterpolate(4,0,2,(gFrameCounter>>1)&15,8):EaseInterpolate(1,2,0,((gFrameCounter>>1)&15)-8,8);
 n--;
 func_0208dd7c((s16)(arg0-n),(s16)(arg1-n),(s16)(arg2+n*2),(s16)(arg3+n*2),arg4,arg5,2);
}

void func_0208e054(s32 arg0, s32 arg1, s16 arg2) {
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    extern M2C_UNK data_0211e0e4;
    extern void *gCur3DSpriteEngine;
    func_0207c780(&data_0211e0e4, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg0);
    M2C_FIELD((M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + (((arg1 + 0x10) << 5) & ~1)), s16 *, 0x1E) = arg2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
}

void func_0208e0b8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK DrawVerticalBar(s16, s16, s16, s32, s32);
    DrawVerticalBar((s16)(arg0 - 1), (s16)(arg1 - 1), (s16)(arg2 + 2), arg3, arg4);
}

void func_0208e0f0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    extern M2C_UNK data_0211e394;
    extern void *gCur3DSpriteEngine;
    s32 temp_r3;
    func_0207c780(&data_0211e394, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg0);
    temp_r3 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + (((arg1 + 0x10) << 5) & ~1);
    M2C_FIELD(temp_r3, s16 *, 6) = arg2;
    M2C_FIELD(temp_r3, s16 *, 8) = arg3;
    M2C_FIELD(temp_r3, s16 *, 0xA) = 0x5AD6;
    M2C_FIELD(temp_r3, s16 *, 0xC) = 0x35AD;
    M2C_FIELD(temp_r3, s16 *, 0xE) = 0x4E73;
    M2C_FIELD(temp_r3, s16 *, 0x10) = 0x6F7B;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
}

