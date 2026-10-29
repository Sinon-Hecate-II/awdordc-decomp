/* 9 functions from 0x0216FC60 to 0x021707D8 (ov000), found by ds-decomp. */
#include "common.h"

extern u8 data_ov000_021b8a00[40];
extern u8 data_ov000_021b89d8[40];
extern u8 data_ov000_021b8a28[40];
extern u8 data_ov000_021b8a50[40];
extern u8 data_ov000_021b89b0[40];

void func_ov000_0216fc60(u8 *arg0) {
    void *func_ov000_021700fc(void);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_ov000_0216ecc8(s16, s16);
    M2C_UNK func_ov000_0216f8c4(s16);
    M2C_UNK func_ov000_0216f9b4(void *);
    void *p = func_ov000_021700fc();
    if (p == NULL) return;
    switch (*arg0) {
    case 0xFB: M2C_FIELD(p, s16 *, 0x34) = 0; break;
    case 0xFA: M2C_FIELD(p, s16 *, 0x34) = 1; break;
    case 0xF9: M2C_FIELD(p, s16 *, 0x34) = 2; break;
    case 0xF8: M2C_FIELD(p, s16 *, 0x34) = 3; break;
    default: return;
    }
    func_0208fe30(0x10020);
    func_ov000_0216ecc8(M2C_FIELD(p,s16 *,0x34), M2C_FIELD(p,s16 *,0x36));
    func_ov000_0216f9b4(p);
    func_ov000_0216f8c4(M2C_FIELD(p,s16 *,0x38));
}

void func_ov000_0216fcf8(void *arg0) {
    return;
}

void func_ov000_0217000c(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov000_02170020(void) {
    void *func_ov000_021700fc(void);
    M2C_UNK func_020b1bf4(s32, s32, s32, s32);
    M2C_UNK func_020b1c78(s32);
    M2C_UNK func_020b22a4(s32, s32, void *, s32);
    
    void *p;
    s32 r7;
    s16 limit;
    s32 r8;
    s32 r5;
    
    p = func_ov000_021700fc();
    func_020b1bf4(0, -0x10, 0x100, -0x10);
    
    func_020b22a4(0, 0, (void*)&data_ov000_021b8a00, 0xfb);
    func_020b22a4(0, 0, (void*)&data_ov000_021b89d8, 0xfa);
    func_020b22a4(0, 0, (void*)&data_ov000_021b8a28, 0xf9);
    func_020b22a4(0, 0, (void*)&data_ov000_021b8a50, 0xf8);
    
    r7 = 0;
    limit = M2C_FIELD(p, s16 *, 0x3c);
    if (limit > 0) {
        r8 = 0x27;
        r5 = 4;
        do {
            if (r7 != 6) {
                func_020b22a4(r5, r8, (void*)&data_ov000_021b89b0, r7);
            }
            r7++;
            r8 += 0x10;
        } while (r7 < limit);
    }
    func_020b1c78(0);
}

void *func_ov000_021700fc(void) {
    void *func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov000_021b8a78;
    return func_01ffa770(&data_ov000_021b8a78);
}

void func_ov000_02170110(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_01ff9e44(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_02007ef4(s32, s32, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080c50(M2C_UNK *, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_0208ca2c(s32, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020994e0(M2C_UNK);
    M2C_UNK func_0209c024(M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    M2C_UNK func_0209c048(M2C_UNK, M2C_UNK, s32, s16, s32, s32);
    s32 func_020a8b3c(u8);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK func_020c0fac(void *);
    M2C_UNK func_020e3058(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, void *, s32);
    s32 func_020e3218(M2C_UNK *);
    s32 func_020e34bc(M2C_UNK);
    s32 func_ov000_0216ce10(u8);
    s32 func_ov000_0216ce84(u8);
    s16 func_ov000_0216ec1c();
    M2C_UNK func_ov000_0216ecc8(s16, s16);
    M2C_UNK func_ov000_0216f8c4(s16);
    M2C_UNK func_ov000_0216f9b4(void *);
    void func_ov000_02170020();
    extern void *data_027e0058;
    extern void *data_027e00c8;
    extern void *data_027e01d8;
    extern M2C_UNK data_ov000_021b8b2c;
    extern M2C_UNK data_ov000_021b8b3c;
    extern M2C_UNK data_ov000_021b8b4c;
    extern M2C_UNK data_ov000_021b8b58;
    extern M2C_UNK data_ov000_021b8b64;
    extern M2C_UNK data_ov000_021b8b78;
    extern M2C_UNK data_ov000_021df5e4;
    M2C_UNK (*temp_r2)();
    s32 temp_r5_2;
    s32 temp_r7;
    void *temp_r4;
    void *temp_r5;

    temp_r5 = M2C_FIELD(data_027e0058, void **, 0);
    temp_r4 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    temp_r2 = M2C_FIELD(M2C_FIELD(data_027e0058, void **, 4), M2C_UNK (**)(), 0x54);
    temp_r5_2 = (M2C_FIELD(temp_r5, u16 *, 0x52A4) * 0x8C) + (s32) (temp_r5 + 0x67A4);
    if (temp_r2 != NULL) {
        temp_r2();
    }
    func_020994e0(0);
    M2C_FIELD(&data_ov000_021df5e4, s32 *, 4) = func_020e34bc(0x40);
    M2C_FIELD(arg0, s16 *, 0x3C) = func_ov000_0216ec1c();
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x3A) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s16 *, 0x40) = 0;
    func_ov000_0216ecc8(M2C_FIELD(arg0, s16 *, 0x34), M2C_FIELD(arg0, s16 *, 0x36));
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(M2C_FIELD(data_027e01d8, void **, 0), s16 *, 0x3A) = 0;
    M2C_FIELD(M2C_FIELD(data_027e01d8, void **, 0), s16 *, 0x42) = 1;
    func_0200bc5c(&data_ov000_021b8b2c);
    func_020e3218(&data_ov000_021b8b3c);
    func_020814e4();
    func_02081590(func_020e3218(&data_ov000_021b8b4c), M2C_FIELD(data_027e00c8, s32 *, 0x14));
    func_02081528();
    func_0208116c(&data_ov000_021b8b58, 0xC0, 0x20);
    func_ov000_0216f9b4(arg0);
    func_020e3058(arg0 + 0x44, 0x5E, 0x8B, 0xA, 0x39C, 3, -1, arg0, 1);
    func_020e3058(arg0 + 0x48, 0x82, 0x8B, 0xB, 0x3A4, 3, -1, arg0, 0);
    func_020c0fac(arg0);
    func_02080c50(&data_ov000_021b8b64, M2C_FIELD(data_027e00c8, s32 *, 0x1C) + 0x7780);
    func_0208116c(&data_ov000_021b8b78, 0x380, 0x20);
    temp_r7 = M2C_FIELD(data_027e00c8, s32 *, 0x1C) + 0x3880;
    func_02007ef4(func_ov000_0216ce10(M2C_FIELD(temp_r5_2, u8 *, 0x27)), temp_r7 + 0x4000, 0x80);
    func_01ff9e44(func_ov000_0216ce84(M2C_FIELD(temp_r5_2, u8 *, 0x1D)), 0x3A0, 0x20);
    func_0208ca2c(0x6B80, 0xB, func_020ae22c(0xC), 2);
    func_0209c024(5, 1, M2C_FIELD(data_027e01d8, s32 *, 0x24), func_020a8b3c(M2C_FIELD(temp_r5_2, u8 *, 0x27)), 0, 0);
    func_0209c048(0x1A, 1, M2C_FIELD(data_027e01d8, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x3C), 0, 0);
    func_ov000_0216f8c4(M2C_FIELD(arg0, s16 *, 0x38));
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 4);
    func_ov000_02170020();
    data_027e01d8 = temp_r4;
}

void func_ov000_021703e8(void *arg0) {
    void func_01ffaacc(s32, s32, u16, void *, s32);
    M2C_UNK func_020aacf0(void *);
    s32 func_02001fb4(s32, s32);
    void func_0208dd7c(s32, s32, s32, s32, u16, s32, s32);
    M2C_UNK func_ov000_0216f8c4(s16);
    M2C_UNK func_ov000_0216facc(void *);
    M2C_UNK func_ov000_0216fb2c(void *);
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern M2C_UNK data_027e0064;
    extern M2C_UNK data_027e005c;
    void *spr;
    void *p;
    void *old;
    u32 cond;
    s16 a;
    s16 b;
    s16 step;
    s32 diff;
    s32 v1;
    s32 v2;
    s32 t1;
    s32 t2;
    s32 t3;

    if (M2C_FIELD(arg0, s16 *, 0x3e) == 0) {
        a = M2C_FIELD(arg0, s16 *, 0x3a);
        b = M2C_FIELD(arg0, s16 *, 0x38);
        if (b != (a << 1)) {
            diff = (a << 1) - b;
            if (diff < 0) diff = -diff;
            step = (s16) (diff >> 1);
            if (step == 0) step = 1;
            if (b > (a << 1)) {
                M2C_FIELD(arg0, s16 *, 0x38) -= step;
            } else {
                M2C_FIELD(arg0, s16 *, 0x38) += step;
            }
            M2C_FIELD(arg0, s16 *, 0x3e) = 1;
            func_ov000_0216f8c4(M2C_FIELD(arg0, s16 *, 0x38));
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x3e) = 0;
    }

    spr = M2C_FIELD(arg0, void **, 0x44);
    if (M2C_FIELD(arg0, s16 *, 0x3a) == 0) {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) + 2) << 24) >> 6);
    } else {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((u32) (u16) ((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) << 24) >> 6);
    }
    M2C_FIELD(spr, u8 *, 0x5a) = 0;

    spr = M2C_FIELD(arg0, void **, 0x48);
    if (M2C_FIELD(arg0, s16 *, 0x3c) - 6 <= M2C_FIELD(arg0, s16 *, 0x3a)) {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) + 2) << 24) >> 6);
    } else {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((u32) (u16) ((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) << 24) >> 6);
    }
    M2C_FIELD(spr, u8 *, 0x5a) = 0;

    func_020aacf0(M2C_FIELD(arg0, void **, 0x44));
    func_020aacf0(M2C_FIELD(arg0, void **, 0x48));

    spr = M2C_FIELD(arg0, void **, 0x44);
    p = M2C_FIELD(spr, void **, 0x64);
    cond = 1;
    if (M2C_FIELD(p, s8 *, 0xb) != 1
        && (!((u32) (M2C_FIELD(spr, u8 *, 0x59) << 27) >> 31) || M2C_FIELD(p, s8 *, 0xc) != 1)) {
        cond = 0;
    }
    if (cond & 255) func_ov000_0216facc(arg0);

    spr = M2C_FIELD(arg0, void **, 0x48);
    p = M2C_FIELD(spr, void **, 0x64);
    cond = 1;
    if (M2C_FIELD(p, s8 *, 0xb) != 1
        && (!((u32) (M2C_FIELD(spr, u8 *, 0x59) << 27) >> 31) || M2C_FIELD(p, s8 *, 0xc) != 1)) {
        cond = 0;
    }
    if (cond & 255) func_ov000_0216fb2c(arg0);

    old = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    v1 = M2C_FIELD(arg0, s16 *, 0x3c) << 12;
    v2 = M2C_FIELD(arg0, s16 *, 0x3a) << 12;
    t1 = func_02001fb4(0x62000, v1);
    t1 = (s32) (((s64) t1 * 0x6000 + 0x800) >> 12);
    t2 = func_02001fb4(0x62000 - t1, v1 - 0x6000);
    t2 = (s32) (((s64) t2 * v2 + 0x800) >> 12);
    t3 = t1 >> 12;
    if (t3 > 0x62) t3 = 0x62;
    else if (t3 < 1) t3 = 1;
    func_0208dd7c(0xf8, (s16) ((t2 >> 12) + 0x28), 2, (s16) t3,
                  (u16) (0xb000 | ((0x35c >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30)) & 0x3ff)),
                  0, 2);
    func_01ffaacc(0x16, 7,
                  (u16) (0xd000 | ((0x3c4 >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30)) & 0x3ff)),
                  &data_027e0064, 0);
    func_01ffaacc(0xaa, 0x8b,
                  (u16) (0xc000 | ((0x3bc >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30)) & 0x3ff)),
                  &data_027e005c, 0);
    gCur3DSpriteEngine = old;
}

void func_ov000_0217074c(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020cfd28();
    M2C_UNK func_020e35cc(s32);
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021df5e4;
    void *temp_r4;
    void *next;
    s32 value;
    temp_r4 = gCur3DSpriteEngine;
    next = data_027e00c8;
    value = 0;
    value = M2C_FIELD(&data_ov000_021df5e4, s32 *, 4);
    gCur3DSpriteEngine = next;
    func_020e35cc(value);
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    func_020cfd28();
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_021707c0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8a78;
    func_01ffa3dc(&data_ov000_021b8a78, 7);
}

