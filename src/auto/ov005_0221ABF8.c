/* 14 functions from 0x0221ABF8 to 0x0221BB70 (ov005), found by ds-decomp. */
#include "common.h"

static inline s32 MaxU8(u8 a, u8 b, u8 c) {
    s32 m;
    if (a > b) m = a; else m = b;
    if (m <= c) m = c;
    return m;
}

M2C_UNK func_ov005_0221abf8(void *arg0) {
    extern M2C_UNK data_0215c334;
    extern u16 *data_02101e84;
    extern M2C_UNK data_02101e88;
    extern M2C_UNK data_ov005_02220aa8, data_ov005_02220fcc, data_ov005_0222120c;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02221218, data_ov005_02221224, data_027e15bc;
    M2C_UNK func_0208116c(M2C_UNK, M2C_UNK, M2C_UNK);
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02007ef4(void *, void *, M2C_UNK);
    M2C_UNK func_0208fe30(M2C_UNK);
    M2C_UNK func_01ffa6fc(void *);
    s32 r5 = 0;
    s32 r6 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x3c) < M2C_FIELD(&data_0215c334, u8 *, 0)) {
        s32 old0 = M2C_FIELD(arg0, s32 *, 0x3c);
        M2C_FIELD(arg0, s32 *, 0x3c) = old0 + 1;
        if (((*data_02101e84) & 1) == 0) { u8 byte0 = M2C_FIELD(data_02101e88, u8 *, 0x14); (void)byte0; }
        if (old0 < 0x64 && M2C_FIELD(arg0, s32 *, 0x3c) >= 0x64) func_0208116c((M2C_UNK)&data_ov005_02220aa8, 0x2c0, 0x20);
        if (M2C_FIELD(arg0, s32 *, 0x3c) == M2C_FIELD(&data_0215c334, u8 *, 0)) {
            void *o0 = func_01ffa3dc((M2C_UNK *)&data_ov005_02220fcc, (M2C_UNK)arg0);
            if (o0 != NULL) {
                M2C_FIELD(o0, M2C_UNK **, 0) = (M2C_UNK *)&data_ov005_0222120c;
                M2C_FIELD(o0, M2C_UNK **, 0x58) = (M2C_UNK *)&data_ov005_02220fcc;
                M2C_FIELD(o0, s32 *, 0x60) = 2;
                M2C_FIELD(o0, s32 *, 0x64) = 0x10;
                M2C_FIELD(o0, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2c0;
                func_02007ef4(M2C_FIELD(o0, void **, 0x54), (void *)((char *)o0 + 0x34), 0x20);
                M2C_FIELD(o0, s32 *, 0x5c) = 0;
                r5 = 1;
            } else r6 = 1;
        } else r6 = 1;
    } else r6 = 1;

    if (M2C_FIELD(arg0, s32 *, 0x40) < M2C_FIELD(&data_0215c334, u8 *, 1)) {
        s32 old1 = M2C_FIELD(arg0, s32 *, 0x40);
        M2C_FIELD(arg0, s32 *, 0x40) = old1 + 1;
        if (old1 < 0x64 && M2C_FIELD(arg0, s32 *, 0x40) >= 0x64) func_0208116c((M2C_UNK)&data_ov005_02220aa8, 0x2e0, 0x20);
        if (M2C_FIELD(arg0, s32 *, 0x40) == M2C_FIELD(&data_0215c334, u8 *, 1)) {
            void *o1 = func_01ffa3dc((M2C_UNK *)&data_ov005_02220fcc, (M2C_UNK)arg0);
            if (o1 != NULL) {
                M2C_FIELD(o1, M2C_UNK **, 0) = (M2C_UNK *)&data_ov005_0222120c;
                M2C_FIELD(o1, M2C_UNK **, 0x58) = (M2C_UNK *)&data_ov005_02220fcc;
                M2C_FIELD(o1, s32 *, 0x60) = 2;
                M2C_FIELD(o1, s32 *, 0x64) = 0x10;
                M2C_FIELD(o1, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2e0;
                func_02007ef4(M2C_FIELD(o1, void **, 0x54), (void *)((char *)o1 + 0x34), 0x20);
                M2C_FIELD(o1, s32 *, 0x5c) = 0;
                r5 = 1;
            } else r6 = 1;
        } else r6 = 1;
    } else r6 = 1;

    if (M2C_FIELD(arg0, s32 *, 0x44) < M2C_FIELD(&data_0215c334, u8 *, 2)) {
        s32 old2 = M2C_FIELD(arg0, s32 *, 0x44);
        M2C_FIELD(arg0, s32 *, 0x44) = old2 + 1;
        if (old2 < 0x64 && M2C_FIELD(arg0, s32 *, 0x44) >= 0x64) func_0208116c((M2C_UNK)&data_ov005_02220aa8, 0x300, 0x20);
        if (M2C_FIELD(arg0, s32 *, 0x44) == M2C_FIELD(&data_0215c334, u8 *, 2)) {
            void *o2 = func_01ffa3dc((M2C_UNK *)&data_ov005_02220fcc, (M2C_UNK)arg0);
            if (o2 != NULL) {
                M2C_FIELD(o2, M2C_UNK **, 0) = (M2C_UNK *)&data_ov005_0222120c;
                M2C_FIELD(o2, M2C_UNK **, 0x58) = (M2C_UNK *)&data_ov005_02220fcc;
                M2C_FIELD(o2, s32 *, 0x60) = 2;
                M2C_FIELD(o2, s32 *, 0x64) = 0x10;
                M2C_FIELD(o2, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x300;
                func_02007ef4(M2C_FIELD(o2, void **, 0x54), (void *)((char *)o2 + 0x34), 0x20);
                M2C_FIELD(o2, s32 *, 0x5c) = 0;
                r5 = 1;
            } else r6 = 1;
        } else r6 = 1;
    } else r6 = 1;

    if (r5 != 0) func_0208fe30((M2C_UNK)&data_ov005_02221218);
    if (r6 != 0) {
        if (((M2C_UNK)data_027e15bc & 3) == 0) func_0208fe30((M2C_UNK)&data_ov005_02221224);
    }
    if (M2C_FIELD(arg0, s32 *, 0x3c) == M2C_FIELD(&data_0215c334, u8 *, 0) &&
        M2C_FIELD(arg0, s32 *, 0x40) == M2C_FIELD(&data_0215c334, u8 *, 1) &&
        M2C_FIELD(arg0, s32 *, 0x44) == M2C_FIELD(&data_0215c334, u8 *, 2)) {
        void *o = func_01ffa3dc((M2C_UNK *)&data_ov005_02220fcc, (M2C_UNK)arg0);
        if (o != NULL) {
            M2C_FIELD(o, M2C_UNK **, 0) = (M2C_UNK *)&data_ov005_0222120c;
            M2C_FIELD(o, M2C_UNK **, 0x58) = (M2C_UNK *)&data_ov005_02220fcc;
            M2C_FIELD(o, s32 *, 0x60) = 2;
            M2C_FIELD(o, s32 *, 0x64) = 0x10;
            M2C_FIELD(o, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x320;
            func_02007ef4(M2C_FIELD(o, void **, 0x54), (void *)((char *)o + 0x34), 0x20);
            M2C_FIELD(o, s32 *, 0x5c) = 0;
            func_01ffa6fc(arg0);
        }
    }
    return 0;
}

void func_ov005_0221b000(void) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_020aad18(s32);
    extern M2C_UNK data_ov005_02220d50;
    func_020aad18(M2C_FIELD(func_01ffa770(&data_ov005_02220d50), s32 *, 0x38));
}

void func_ov005_0221b01c(void *arg0) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_02087db8(void *, s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_01ffa6fc(void *);
    extern u16 *data_02101e84;
    extern M2C_UNK data_ov005_02220d50;
    void *object;
    u8 active;
    if (!(*data_02101e84 & 1)) return;
    func_0208fe30(0x1000D);
    object = M2C_FIELD(M2C_FIELD(func_01ffa770(&data_ov005_02220d50), void **, 0x38), void **, 0x64);
    active = M2C_FIELD(object, u8 *, 0x12) != 0;
    if (active) func_02087db8(object, 1);
    func_01ffa6fc(arg0);
}

void func_ov005_0221b088(void *arg0) {
    M2C_UNK func_01ff9ce8(s32);
    M2C_UNK func_01ffa574(void *);
    s32 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(arg0, s32 *, 0x34) += 1;
    M2C_FIELD(arg0, s32 *, 0x38) = EaseInterpolate(1, 0, 0x100, M2C_FIELD(arg0, s32 *, 0x34), 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x34) != 0x20) return;
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_01ffa574(arg0);
}

M2C_UNK func_ov005_0221b114(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern u8 data_027e0084[];
    M2C_UNK func_0207c964(s32, s32, s32 *, s32 *);
    M2C_UNK AddSprite(u16, u16, u16, void *, s32);
    s32 x0, i0, h0;
    s32 x1, i1, h1;
    s32 x2, i2, h2;
    s32 x3, i3, h3;
    s32 c0, o0, c1, o1, c2, o2, c3, o3;
    s32 shift, adjust;
    u16 engine0;

    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x3C) =
        (u16)(-M2C_FIELD(arg0, s32 *, 0x38));

    x0 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    c0 = M2C_FIELD(arg0, s32 *, 0x3C);
    i0 = 0;
    h0 = x0 & 0xfe00;
    do {
        func_0207c964(c0, 10, &c0, &o0);
        engine0 = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        shift = ((u32)(engine0 << 17)) >> 30;
        adjust = 0x3ff & (0x140 >> shift);
        AddSprite((u16)(((x0 - i0) & 0x1ff) | h0), 0x12,
            (u16)(((o0 & 0x3ff) + adjust) | 0x6000), data_027e0084, 0);
        i0 += 8;
    } while (c0 != 0);

    x1 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    c1 = M2C_FIELD(arg0, s32 *, 0x40);
    i1 = 0;
    h1 = x1 & 0xfe00;
    do {
        func_0207c964(c1, 10, &c1, &o1);
        engine0 = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        shift = ((u32)(engine0 << 17)) >> 30;
        adjust = 0x3ff & (0x140 >> shift);
        AddSprite((u16)(((x1 - i1) & 0x1ff) | h1), 0x26,
            (u16)(((o1 & 0x3ff) + adjust) | 0x7000), data_027e0084, 0);
        i1 += 8;
    } while (c1 != 0);

    x2 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    c2 = M2C_FIELD(arg0, s32 *, 0x44);
    i2 = 0;
    h2 = x2 & 0xfe00;
    do {
        func_0207c964(c2, 10, &c2, &o2);
        engine0 = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        shift = ((u32)(engine0 << 17)) >> 30;
        adjust = 0x3ff & (0x140 >> shift);
        AddSprite((u16)(((x2 - i2) & 0x1ff) | h2), 0x3a,
            (u16)(((o2 & 0x3ff) + adjust) | 0x8000), data_027e0084, 0);
        i2 += 8;
    } while (c2 != 0);

    x3 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    c3 = M2C_FIELD(arg0, s32 *, 0x3C) + M2C_FIELD(arg0, s32 *, 0x40) + M2C_FIELD(arg0, s32 *, 0x44);
    i3 = 0;
    h3 = x3 & 0xfe00;
    do {
        func_0207c964(c3, 10, &c3, &o3);
        engine0 = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        shift = ((u32)(engine0 << 17)) >> 30;
        adjust = 0x3ff & (0x140 >> shift);
        AddSprite((u16)(((x3 - i3) & 0x1ff) | h3), 0x50,
            (u16)(((o3 & 0x3ff) + adjust) | 0x9000), data_027e0084, 0);
        i3 += 8;
    } while (c3 != 0);
    return c3;
}

void func_ov005_0221b424(void) {
    M2C_UNK func_ov005_0221ab98();
    func_ov005_0221ab98();
}

void func_ov005_0221b430(void) {
    M2C_UNK func_ov005_0221abf8();
    func_ov005_0221abf8();
}

void func_ov005_0221b43c(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_01ffaa5c(s32);
    s32 func_01ffaa7c();
    extern M2C_UNK data_ov005_02220b00;
    extern M2C_UNK data_ov005_02220d50;
    extern M2C_UNK data_ov005_02220fb8;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov005_02220b00, func_01ffaa7c());
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    func_01ffaa5c(arg0);
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0x20;
    M2C_FIELD(temp_r0, s8 *, 0x44) = 1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32) M2C_FIELD(func_01ffa770(&data_ov005_02220d50), s32 *, 0x38);
}

void func_ov005_0221b4a8(void) {
    void func_ov005_0221b000(void);
    func_ov005_0221b000();
}

void func_ov005_0221b4b4(void) {
    void func_ov005_0221b01c();
    func_ov005_0221b01c();
}

void func_ov005_0221b4c0(void) {
    void func_ov005_0221b088();
    func_ov005_0221b088();
}

void func_ov005_0221b4cc(void) {
    M2C_UNK func_ov005_0221b114();
    func_ov005_0221b114();
}

void func_ov005_0221b4d8(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_0215c324;
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    M2C_UNK func_01ffa6fc(void *);
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    s32 v;
    s32 n;
    s32 i;

    M2C_FIELD(arg0, s32 *, 0x34) += 1;
    if (M2C_FIELD(arg0, s32 *, 0x34) == 1) {
        sp38 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp38 = (*sp38 & ~0xc0) | 0x40;
        sp34 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp34 = *sp34 & ~1;
        sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp30 = *sp30 & ~2;
        sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp2C = *sp2C | 4;
        sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp28 = *sp28 & ~8;
        sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp24 = *sp24 & ~0x10;
        sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp20 = *sp20 & ~0x20;
        sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp1C = *sp1C & ~0x100;
        sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp18 = *sp18 & ~0x200;
        sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp14 = *sp14 & ~0x400;
        sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp10 = *sp10 | 0x800;
        spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *spC = *spC & ~0x1000;
        sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp8 = *sp8 & ~0x2000;
    }

    v = M2C_FIELD(arg0, s32 *, 0x34);
    if (v <= 0x20) {
        n = EaseInterpolate(0, 0, 0x10, v, 0x20);
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = (u8)n;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = (u8)(0x10 - n);
        M2C_FIELD(arg0, u16 *, 0x38) = (u16)EaseInterpolate(4, -0xa0, 0, v, 0x20);
    }

    for (i = 0; i < MaxU8(M2C_FIELD(&data_0215c324, u8 *, 0xC), M2C_FIELD(&data_0215c324, u8 *, 0xD), M2C_FIELD(&data_0215c324, u8 *, 0xE)); i++) {
        v = M2C_FIELD(arg0, s32 *, 0x34) - i * 2;
        if (v > 0 && v <= 0x20)
            ((u16 *)((u8 *)arg0 + 0x3A))[i] = (u16)EaseInterpolate(4, 0xa0, 0, v, 0x20);
    }

    if (M2C_FIELD(arg0, s32 *, 0x34) != (MaxU8(M2C_FIELD(&data_0215c324, u8 *, 0xC), M2C_FIELD(&data_0215c324, u8 *, 0xD), M2C_FIELD(&data_0215c324, u8 *, 0xE)) - 1) * 2 + 0x20)
        return;

    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 & ~0xc0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = 0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = 0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_01ffa6fc(arg0);
}

void func_ov005_0221b854(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_01ffa730(void *);
    s32 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_020cd1e4();
    extern M2C_UNK data_0215c334;
    extern M2C_UNK data_0215c340;
    extern u16 **data_027e01d8;
    u16 *sp3C;
    u16 *sp38;
    u16 *sp34;
    u16 *sp30;
    u16 *sp2C;
    u16 *sp28;
    u16 *sp24;
    u16 *sp20;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 *sp8;
    u16 *sp4;
    s32 temp_r0;
    s32 var_r0;
    s32 temp_r0_3;
    u16 *temp_r0_2;
    u16 *temp_r1;
    u16 *temp_r1_10;
    u16 *temp_r1_11;
    u16 *temp_r1_12;
    u16 *temp_r1_13;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r1_8;
    u16 *temp_r1_9;
    u16 *temp_r2;

    if (func_020cd1e4() == 0) {
        var_r0 = 0;
    } else if (*(&data_0215c340 + (M2C_FIELD(&data_0215c334, u8 *, 4) * 0xC)) == 0) {
        var_r0 = 0;
    } else {
        var_r0 = 1;
    }
    if (var_r0 == 0) {
        func_01ffa730(arg0);
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x34) + 1;
    M2C_FIELD(arg0, s32 *, 0x34) = temp_r0;
    if (temp_r0 == 1) {
        temp_r1 = *data_027e01d8;
        sp3C = temp_r1;
        *temp_r1 = *sp3C | 0x20;
        temp_r1_2 = *data_027e01d8;
        sp38 = temp_r1_2 + 0x12;
        M2C_FIELD(temp_r1_2, s16 *, 0x12) = (s16) ((*sp38 & ~0xC0) | 0x40);
        temp_r1_3 = *data_027e01d8;
        sp34 = temp_r1_3 + 0x12;
        M2C_FIELD(temp_r1_3, s16 *, 0x12) = (s16) (*sp34 & ~1);
        temp_r1_4 = *data_027e01d8;
        sp30 = temp_r1_4 + 0x12;
        M2C_FIELD(temp_r1_4, s16 *, 0x12) = (s16) (*sp30 | 2);
        temp_r1_5 = *data_027e01d8;
        sp2C = temp_r1_5 + 0x12;
        M2C_FIELD(temp_r1_5, s16 *, 0x12) = (s16) (*sp2C & ~4);
        temp_r1_6 = *data_027e01d8;
        sp28 = temp_r1_6 + 0x12;
        M2C_FIELD(temp_r1_6, s16 *, 0x12) = (s16) (*sp28 & ~8);
        temp_r1_7 = *data_027e01d8;
        sp24 = temp_r1_7 + 0x12;
        M2C_FIELD(temp_r1_7, s16 *, 0x12) = (s16) (*sp24 & ~0x10);
        temp_r1_8 = *data_027e01d8;
        sp20 = temp_r1_8 + 0x12;
        M2C_FIELD(temp_r1_8, s16 *, 0x12) = (s16) (*sp20 & ~0x20);
        temp_r1_9 = *data_027e01d8;
        sp1C = temp_r1_9 + 0x12;
        M2C_FIELD(temp_r1_9, s16 *, 0x12) = (s16) (*sp1C & ~0x100);
        temp_r1_10 = *data_027e01d8;
        sp18 = temp_r1_10 + 0x12;
        M2C_FIELD(temp_r1_10, s16 *, 0x12) = (s16) (*sp18 & ~0x200);
        temp_r1_11 = *data_027e01d8;
        sp14 = temp_r1_11 + 0x12;
        M2C_FIELD(temp_r1_11, s16 *, 0x12) = (s16) (*sp14 & ~0x400);
        temp_r1_12 = *data_027e01d8;
        sp10 = temp_r1_12 + 0x12;
        M2C_FIELD(temp_r1_12, s16 *, 0x12) = (s16) (*sp10 | 0x800);
        temp_r1_13 = *data_027e01d8;
        spC = temp_r1_13 + 0x12;
        M2C_FIELD(temp_r1_13, s16 *, 0x12) = (s16) (*spC | 0x1000);
        temp_r0_2 = *data_027e01d8;
        sp8 = temp_r0_2 + 0x12;
        M2C_FIELD(temp_r0_2, s16 *, 0x12) = (s16) (*sp8 & ~0x2000);
    }
    temp_r0_3 = EaseInterpolate(0, 0, 0x10, M2C_FIELD(arg0, s32 *, 0x34), 0x10);
    M2C_FIELD(*data_027e01d8, s8 *, 0x51) = (s8)temp_r0_3;
    M2C_FIELD(*data_027e01d8, s8 *, 0x52) = (s8) (0x10 - temp_r0_3);
    if (M2C_FIELD(arg0, s32 *, 0x34) != 0x10) {
        return;
    }
    temp_r2 = *data_027e01d8;
    sp4 = temp_r2 + 0x12;
    M2C_FIELD(temp_r2, s16 *, 0x12) = (s16) (*sp4 & ~0xC0);
    M2C_FIELD(*data_027e01d8, s8 *, 0x51) = 0;
    M2C_FIELD(*data_027e01d8, s8 *, 0x52) = 0;
    M2C_FIELD(*data_027e01d8, s8 *, 0x53) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_01ffa6fc(arg0);
}

