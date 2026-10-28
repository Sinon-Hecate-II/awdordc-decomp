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
s32 func_0207ca38(s32,s32,s32,s32,s32);
s32 func_020ae3e0(s32,s32,u8,u8);
void func_01ffa574(void *);
u16 *dest;
s32 i;
u8 a;
if (!(M2C_FIELD(arg0,u8 *,0x35)&1)) return;
dest=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+((M2C_FIELD(arg0,u8 *,0x34)<<5)&~1));
M2C_FIELD(arg0,u8 *,0x36)++;
if(M2C_FIELD(arg0,u8 *,0x35)&2)
a=func_0207ca38(0,32,0,M2C_FIELD(arg0,u8 *,0x36),M2C_FIELD(arg0,u8 *,0x37));
else a=func_0207ca38(0,0,32,M2C_FIELD(arg0,u8 *,0x36),M2C_FIELD(arg0,u8 *,0x37));
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
void func_0208cadc(s16 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4) {
    extern s16 data_020e5b30[];
    extern u8 data_020f35ba[];
    extern u8 data_027e007c[];
    extern u8 data_027e00a4[];
    extern u8 data_027e0084[];
    extern void *gCur3DSpriteEngine;
    s32 func_0207c8ec(s32, s32);
    void func_01ff8ddc(s32, s16, s16, s16, s16);
    void func_01ffaacc(u16, u16, u16, void *, s32);

    s16 r9 = arg1;
    s16 r10 = arg0;
    s16 r8 = arg2;
    s32 r7 = arg3;
    s32 r6 = arg4;

    if (r9 < 0) return;
    if (r9 > 0xc0) return;
    if (r10 < 0) {
        r8 = (s16)(r8 + r10);
        r10 = 0;
    }
    if (r10 > 0x100) {
        r8 = (s16)(r8 + (r10 - 0x100));
        r10 = 0x100;
    }
    {
        s32 sum = r10 + r8;
        if (sum > 0x100) r8 = (s16)(0x100 - r10);
        sum = r10 + r8;
        if (sum < 0) r8 = (s16)(0 - r10);
    }
    if (r8 >= 0x40) {
        {
            s16 t0 = data_020e5b30[0];
            s16 t1 = data_020e5b30[1];
            func_01ff8ddc(0x1c,
                (s16)func_0207c8ec((s32)t1 << 4, 0x200),
                (s16)func_0207c8ec((-(s32)t0) << 4, 0x100),
                (s16)func_0207c8ec((s32)t0 << 4, 0x200),
                (s16)func_0207c8ec((s32)t1 << 4, 0x100));
        }
        while (r8 >= 0x80) {
            func_01ffaacc((u16)((r10 & 0x1FF) | 0x3800),
                          (u16)(((r9 - 4) & 0xFF) | 0x300),
                          (u16)r7,
                          (void *)data_020f35ba,
                          r6);
            { s16 tt = (s16)(r8 - 0x80); r8 = tt; r10 = (s16)(r10 + 0x80); }
        }
        while (r8 >= 0x40) {
            func_01ffaacc((u16)((r10 & 0x1FF) | 0x3800),
                          (u16)(((r9 - 4) & 0xFF) | 0x300),
                          (u16)r7,
                          (void *)data_027e007c,
                          r6);
            { s16 tt = (s16)(r8 - 0x40); r8 = tt; r10 = (s16)(r10 + 0x40); }
        }
    }
    while (r8 >= 0x20) {
        func_01ffaacc((u16)(r10 & 0x1FF),
                      (u16)(r9 & 0xFF),
                      (u16)r7,
                      (void *)data_027e007c,
                      r6);
        { s16 tt = (s16)(r8 - 0x20); r8 = tt; r10 = (s16)(r10 + 0x20); }
    }
    while (r8 >= 0x10) {
        func_01ffaacc((u16)(r10 & 0x1FF),
                      (u16)(r9 & 0xFF),
                      (u16)r7,
                      (void *)data_027e00a4,
                      r6);
        { s16 tt = (s16)(r8 - 0x10); r8 = tt; r10 = (s16)(r10 + 0x10); }
    }
    while (r8 >= 0x8) {
        func_01ffaacc((u16)(r10 & 0x1FF),
                      (u16)(r9 & 0xFF),
                      (u16)r7,
                      (void *)data_027e0084,
                      r6);
        { s16 tt = (s16)(r8 - 0x8); r8 = tt; r10 = (s16)(r10 + 0x8); }
    }
    while (r8 >= 0x4) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        func_01ffaacc((u16)(r10 & 0x1FF),
                      (u16)(r9 & 0xFF),
                      (u16)(r7 + (0x3FF & (4 >> (s32)mode))),
                      (void *)data_027e0084,
                      r6);
        { s16 tt = (s16)(r8 - 0x4); r8 = tt; r10 = (s16)(r10 + 0x4); }
    }
    while (r8 >= 0x2) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        func_01ffaacc((u16)(r10 & 0x1FF),
                      (u16)(r9 & 0xFF),
                      (u16)(r7 + (0x3FF & (6 >> (s32)mode))),
                      (void *)data_027e0084,
                      r6);
        { s16 tt = (s16)(r8 - 0x2); r8 = tt; r10 = (s16)(r10 + 0x2); }
    }
    while (r8 >= 0x1) {
        u32 mode = ((u32)(**(u16 **)gCur3DSpriteEngine << 17)) >> 30;
        func_01ffaacc((u16)(r10 & 0x1FF),
                      (u16)(r9 & 0xFF),
                      (u16)(r7 + (0x3FF & (8 >> (s32)mode))),
                      (void *)data_027e0084,
                      r6);
        { s16 tt = (s16)(r8 - 0x1); r8 = tt; r10 = (s16)(r10 + 0x1); }
    }
}
M2C_UNK func_0208cf94(s16 a, s16 b, s16 c, s32 d, s32 e) { return 0; }

