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

void func_0208c8c0(void *arg0) {
extern void *gCur3DSpriteEngine;
s32 EaseInterpolate(s32,s32,s32,s32,s32);
s32 func_020ae3e0(s32,s32,u8,u8);
void func_01ffa574(void *);
u16 *dest;
s32 i;
u8 a;
if (!(M2C_FIELD(arg0,u8 *,0x35)&1)) return;
dest=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+((M2C_FIELD(arg0,u8 *,0x34)<<5)&~1));
M2C_FIELD(arg0,u8 *,0x36)++;
if(M2C_FIELD(arg0,u8 *,0x35)&2)
a=EaseInterpolate(0,32,0,M2C_FIELD(arg0,u8 *,0x36),M2C_FIELD(arg0,u8 *,0x37));
else a=EaseInterpolate(0,0,32,M2C_FIELD(arg0,u8 *,0x36),M2C_FIELD(arg0,u8 *,0x37));
for(i=0;i<15;i++) { dest[i+1]=func_020ae3e0(((u16 *)arg0)[i+0x1c],((u16 *)arg0)[i+0x2b],(u8)(32-a),a); }
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=0x10;
if(M2C_FIELD(arg0,u8 *,0x36)<M2C_FIELD(arg0,u8 *,0x37)) return;
M2C_FIELD(arg0,u8 *,0x36)=0;
if(M2C_FIELD(arg0,u8 *,0x35)&4) M2C_FIELD(arg0,u8 *,0x35)^=2;
else M2C_FIELD(arg0,u8 *,0x35)=0;
if(M2C_FIELD(arg0,u8 *,0x35)&8) func_01ffa574(arg0);
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

void func_0208ca08(void *arg0) {
    func_0208c8c0(arg0);
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

#pragma opt_strength_reduction off
/* Draws a horizontal strip of `length` pixels at (x,y), filling it with tiles of
 * decreasing width (128 down to 1). The first 128/64-pixel chunk is drawn as a
 * rotated quad using the sin/cos table, giving the slanted look of UI frames. */
void DrawHorizontalBar(s16 x, s16 y, s16 length, s32 tile, s32 priority) {
    extern s16 gSinCosTable[];
    extern u8 data_020f35ba[];
    extern u8 data_027e007c[];
    extern u8 data_027e00a4[];
    extern u8 data_027e0084[];
    extern void *gCur3DSpriteEngine;
    s32 func_0207c8ec(s32, s32);
    void SetSpriteQuad(s32, s16, s16, s16, s16);
    void AddSprite(u16, u16, u16, void *, s32);

    s16 y0 = y;
    s16 px = x;
    s16 len = length;
    s32 t = tile;
    s32 pri = priority;

    if (y0 < 0) return;
    if (y0 > 0xc0) return;
    if (px < 0) {
        len = (s16)(len + px);
        px = 0;
    }
    if (px > 0x100) {
        len = (s16)(len + (px - 0x100));
        px = 0x100;
    }
    {
        s32 sum = px + len;
        if (sum > 0x100) len = (s16)(0x100 - px);
        sum = px + len;
        if (sum < 0) len = (s16)(0 - px);
    }
    if (len >= 0x40) {
        {
            s16 t0 = gSinCosTable[0];
            s16 t1 = gSinCosTable[1];
            SetSpriteQuad(0x1c,
                (s16)func_0207c8ec((s32)t1 << 4, 0x200),
                (s16)func_0207c8ec((-(s32)t0) << 4, 0x100),
                (s16)func_0207c8ec((s32)t0 << 4, 0x200),
                (s16)func_0207c8ec((s32)t1 << 4, 0x100));
        }
        while (len >= 0x80) {
            AddSprite((u16)((px & 0x1FF) | 0x3800),
                          (u16)(((y0 - 4) & 0xFF) | 0x300),
                          (u16)t,
                          (void *)data_020f35ba,
                          pri);
            px=(s16)(px+0x80); len=(s16)(len-0x80);
        }
        while (len >= 0x40) {
            AddSprite((u16)((px & 0x1FF) | 0x3800),
                          (u16)(((y0 - 4) & 0xFF) | 0x300),
                          (u16)t,
                          (void *)data_027e007c,
                          pri);
            px=(s16)(px+0x40); len=(s16)(len-0x40);
        }
    }
    while (len >= 0x20) {
        AddSprite((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)t,
                      (void *)data_027e007c,
                      pri);
        px=(s16)(px+0x20); len=(s16)(len-0x20);
    }
    while (len >= 0x10) {
        AddSprite((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)t,
                      (void *)data_027e00a4,
                      pri);
        px=(s16)(px+0x10); len=(s16)(len-0x10);
    }
    while (len >= 0x8) {
        AddSprite((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)t,
                      (void *)data_027e0084,
                      pri);
        px=(s16)(px+0x8); len=(s16)(len-0x8);
    }
    while (len >= 0x4) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        AddSprite((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)(t + (0x3FF & (4 >> (s32)mode))),
                      (void *)data_027e0084,
                      pri);
        px=(s16)(px+0x4); len=(s16)(len-0x4);
    }
    while (len >= 0x2) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        AddSprite((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)(t + (0x3FF & (6 >> (s32)mode))),
                      (void *)data_027e0084,
                      pri);
        px=(s16)(px+0x2); len=(s16)(len-0x2);
    }
    while (len >= 0x1) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        AddSprite((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)(t + (0x3FF & (8 >> (s32)mode))),
                      (void *)data_027e0084,
                      pri);
        px=(s16)(px+0x1); len=(s16)(len-0x1);
    }
}
/* Draws a vertical strip of `length` pixels at (x,y), filling it with tiles of
 * decreasing height (128 down to 1). The first 128/64-pixel chunk is drawn as a
 * rotated quad using the sin/cos table, for the slanted look of UI frames. */
void DrawVerticalBar(s16 x, s16 y, s16 length, s32 tile, s32 priority) {
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

    s16 y0 = y;
    s16 px = x;
    s16 len = length;
    s32 t = tile;
    s32 pri = priority;

    if (px < 0) return;
    if (px > 0x100) return;
    if (y0 < 0) {
        len = (s16)(len + y0);
        y0 = 0;
    }
    if (y0 > 0xc0) {
        len = (s16)(len + (y0 - 0xc0));
        y0 = 0xc0;
    }
    {
        s32 sum = y0 + len;
        if (sum > 0xc0) len = (s16)(0xc0 - y0);
        sum = y0 + len;
        if (sum < 0) len = (s16)(0 - y0);
    }
    if (len >= 0x40) {
        {
            s16 t0 = gSinCosTable[0];
            s16 t1 = gSinCosTable[1];
            SetSpriteQuad(0x1b,
                (s16)func_0207c8ec((s32)t1 << 4, 0x100),
                (s16)func_0207c8ec((-(s32)t0) << 4, 0x200),
                (s16)func_0207c8ec((s32)t0 << 4, 0x100),
                (s16)func_0207c8ec((s32)t1 << 4, 0x200));
        }
        while (len >= 0x80) {
            AACC((u16)((((px - 4) & 0x1FF)) | 0x3600),
                          (u16)((y0 & 0xFF) | 0x300),
                          t,
                          (void *)data_020f359e,
                          pri);
            y0=(s16)(y0+0x80); len=(s16)(len-0x80);
        }
        while (len >= 0x40) {
            AACC((u16)((((px - 4) & 0x1FF)) | 0x3600),
                          (u16)((y0 & 0xFF) | 0x300),
                          t,
                          (void *)data_027e009c,
                          pri);
            y0=(s16)(y0+0x40); len=(s16)(len-0x40);
        }
    }
    while (len >= 0x20) {
        AACC((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      t,
                      (void *)data_027e009c,
                      pri);
        y0=(s16)(y0+0x20); len=(s16)(len-0x20);
    }
    while (len >= 0x10) {
        AACC((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      t,
                      (void *)data_027e006c,
                      pri);
        y0=(s16)(y0+0x10); len=(s16)(len-0x10);
    }
    while (len >= 0x8) {
        AACC((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      t,
                      (void *)data_027e0084,
                      pri);
        y0=(s16)(y0+0x8); len=(s16)(len-0x8);
    }
    while (len >= 0x4) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        AACC((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)(t + (0x3FF & (4 >> (s32)mode))),
                      (void *)data_027e0084,
                      pri);
        y0=(s16)(y0+0x4); len=(s16)(len-0x4);
    }
    while (len >= 0x2) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        AACC((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)(t + (0x3FF & (6 >> (s32)mode))),
                      (void *)data_027e0084,
                      pri);
        y0=(s16)(y0+0x2); len=(s16)(len-0x2);
    }
    while (len >= 0x1) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        AACC((u16)(px & 0x1FF),
                      (u16)(y0 & 0xFF),
                      (u16)(t + (0x3FF & (8 >> (s32)mode))),
                      (void *)data_027e0084,
                      pri);
        y0=(s16)(y0+0x1); len=(s16)(len-0x1);
    }
#undef AACC
}

