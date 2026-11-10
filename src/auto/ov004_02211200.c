/* 27 functions from 0x02211200 to 0x022120C0 (ov004), found by ds-decomp. */
#include "common.h"

void func_ov004_02211200(void) {
    M2C_UNK func_ov000_0216a7fc();
    func_ov000_0216a7fc();
}

void func_ov004_0221120c(M2C_UNK arg0) {
    s32 func_020946d0();
    M2C_UNK func_01ffa6fc(M2C_UNK);
    if (func_020946d0() != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov004_0221122c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern u16 data_02168f14;
    extern M2C_UNK data_ov004_02218c00;
    if ((u8)((u32)(data_02168f14 << 29) >> 29)) return;
    func_01ffa42c(&data_ov004_02218c00, arg0);
}

void func_ov004_02211260(void) {
    M2C_UNK func_ov000_0216aabc();
    func_ov000_0216aabc();
}

void func_ov004_0221126c(M2C_UNK arg0) {
    M2C_UNK func_020834c4();
    M2C_UNK func_0208874c();
    s32 func_020cd1e4();
    s32 func_020e4b54();
    M2C_UNK func_ov004_02227ecc_unk(M2C_UNK);
    if (func_020946d0() != 0) {
        return;
    }
    if ((func_020cd1e4() != 0) && (func_020e4b54() != 0)) {
        func_0208874c();
        func_ov004_02227ecc_unk(arg0);
        func_020834c4();
    }
    func_01ffa6fc(arg0);
}

void func_ov004_022112b4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern u16 data_02168f14;
    extern M2C_UNK data_ov004_02218be0;
    if ((u8)((u32)(data_02168f14 << 29) >> 29)) return;
    func_01ffa42c(&data_ov004_02218be0, arg0);
}

void func_ov004_022112e8(void *arg0) {
    M2C_UNK func_0208ffe4(s32, s32, s32);
    M2C_FIELD(arg0, s16 *, 0x34) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x36) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x3A) = 0;
    M2C_FIELD(arg0, s16 *, 0x42) = 0;
    M2C_FIELD(arg0, s16 *, 0x44) = 0;
    M2C_FIELD(arg0, s16 *, 0x46) = 0;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, s16 *, 0x4A) = 0x80;
    M2C_FIELD(arg0, s16 *, 0x4C) = 0x60;
    M2C_FIELD(arg0, s16 *, 0x3C) = 2;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s16 *, 0x40) = 0x78;
    M2C_FIELD(arg0, s16 *, 0x4E) = 0;
    M2C_FIELD(arg0, s16 *, 0x50) = 0;
    M2C_FIELD(arg0, s16 *, 0x52) = 0;
    func_0208ffe4(0, -1, 0xF7);
}

void func_ov004_02211358(void) {
    M2C_UNK func_02091a50();
    M2C_UNK func_020807d0();
    M2C_UNK func_02090034(s32, s32);
    func_02091a50();
    func_020807d0();
    func_02090034(0, 0x1E);
}

M2C_UNK func_ov004_02211374(void *arg0) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 data_ov004_02218cb0;
    unsigned long long func_020720f0(s32, s32);
    s32 func_02091e14(void);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void *func_02082a8c(void *, void *);
    void func_0209dabc(s32, void *);
    void *func_0208931c(void);
    M2C_UNK func_02088f8c(void *, s32, s32, s32, s32, s32);
    void func_0208f998(s32, s32);
    s32 func_0207c2f0(void);
    void *func_0208c528(void *);
    void func_0208bddc(void *, void *, s32, s32, s32);
    M2C_UNK PlaySoundEffect(s32);

    u16 max;
    u16 half;
    s32 spC;
    s16 r11;
    s32 result2;
    s32 savedEngine;
    s32 loop;
    void *spr;
    struct {
        s32 f0;
        s32 f1;
        s16 a;
        s16 b;
        s16 c;
        s16 d;
        s16 e;
    } spblk;

    if (M2C_FIELD(arg0, u16 *, 0x38) < M2C_FIELD(arg0, u16 *, 0x3A)) {
        M2C_FIELD(arg0, u16 *, 0x38) = M2C_FIELD(arg0, u16 *, 0x38) + 1;
    }
    M2C_FIELD(arg0, u16 *, 0x3E) = (u16)(func_020720f0(M2C_FIELD(arg0, u16 *, 0x3E) + 1, M2C_FIELD(arg0, u16 *, 0x40)) >> 32);
    max = M2C_FIELD(arg0, u16 *, 0x3A);
    spC = EaseInterpolate(4, M2C_FIELD(arg0, u16 *, 0x34), M2C_FIELD(arg0, u16 *, 0x36), M2C_FIELD(arg0, u16 *, 0x38), max);
    spC = spC & 0xFFFF;
    r11 = (s16)spC;
    half = (u16)(M2C_FIELD(arg0, u16 *, 0x40) >> 1);
    if (M2C_FIELD(arg0, u16 *, 0x3E) < half) {
        result2 = EaseInterpolate(4, -(s16)M2C_FIELD(arg0, s16 *, 0x3C), (s16)M2C_FIELD(arg0, s16 *, 0x3C), M2C_FIELD(arg0, s16 *, 0x38), half);
    } else {
        result2 = EaseInterpolate(1, (s16)M2C_FIELD(arg0, s16 *, 0x3C), -(s16)M2C_FIELD(arg0, s16 *, 0x3C), M2C_FIELD(arg0, u16 *, 0x3E) - half, half);
    }
    spC = result2 << 16;
    savedEngine = gCur3DSpriteEngine;
    loop = 0;
    while (loop < 2) {
        if (loop == 0) gCur3DSpriteEngine = g3DSpriteEngineMain; else gCur3DSpriteEngine = g3DSpriteEngineSub;
        if (func_02091e14() == 0 && gCur3DSpriteEngine != g3DSpriteEngineMain) goto skip_update;
        if (func_02091e14() == 1 && gCur3DSpriteEngine != g3DSpriteEngineSub) goto skip_update;
        if (func_02091e14() == 3 && gCur3DSpriteEngine != savedEngine) goto skip_update;

        M2C_FIELD(arg0, s16 *, 0x20) = 0;
        spblk.c = r11;
        spblk.d = r11;
        spblk.e = 0;
        spblk.a = M2C_FIELD(arg0, s16 *, 0x4A);
        spblk.b = M2C_FIELD(arg0, s16 *, 0x4C);
        spblk.f0 = M2C_FIELD(arg0, s16 *, 0x4A) + M2C_FIELD(arg0, s16 *, 0x4E) + M2C_FIELD((void *)gCur3DSpriteEngine, s16 *, 0x3C);
        spblk.f1 = M2C_FIELD(arg0, s16 *, 0x4C) + M2C_FIELD(arg0, s16 *, 0x50) + M2C_FIELD((void *)gCur3DSpriteEngine, s16 *, 0x3E) + (spC >> 16);

        func_02082a8c(&spblk, (void *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0) + 0x14);

        spblk.f0 = M2C_FIELD(arg0, s16 *, 0x4A);
        spblk.f1 = M2C_FIELD(arg0, s16 *, 0x4C);
        func_02082a8c(&spblk, (void *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0) + 0x24);

        if (M2C_FIELD(arg0, u16 *, 0x44) > M2C_FIELD(arg0, u16 *, 0x42)) {
            M2C_FIELD(arg0, u16 *, 0x42) = M2C_FIELD(arg0, u16 *, 0x42) + 1;
            if (M2C_FIELD(arg0, u16 *, 0x42) == M2C_FIELD(arg0, u16 *, 0x44)) {
                func_0209dabc(0x1E, arg0);
                spr = func_0208931c();
                M2C_FIELD(spr, u16 *, 0x3E) = 0x35C;
                {
                    s32 uu = M2C_FIELD(spr, u32 *, 0x40);
                    uu = (uu & ~0x3FC0000) | 0x2C0000;
                    M2C_FIELD(spr, u32 *, 0x40) = uu;
                }
                M2C_FIELD(spr, u8 **, 0x44) = (u8 *)data_ov004_02218cb0;
                M2C_FIELD(spr, u16 *, 0x3C) = 0x800;
                func_02088f8c(spr, 0x78, 0x60, 0x78, 0xC0, 0x1E);
                func_0208f998(0xF8, 0x14);
            }
        }

        if (M2C_FIELD(arg0, u16 *, 0x48) > M2C_FIELD(arg0, u16 *, 0x46)) {
            M2C_FIELD(arg0, u16 *, 0x46) = M2C_FIELD(arg0, u16 *, 0x46) + 1;
            if ((M2C_FIELD(arg0, u16 *, 0x46) & 0x1F) == 1) {
                s32 t1 = func_0207c2f0();
                s32 r8 = (t1 % 0xC0) + 0x20 - M2C_FIELD(arg0, s16 *, 0x4E);
                s32 t2 = func_0207c2f0();
                s32 r9 = (t2 % 0x40) + 0x20 - M2C_FIELD(arg0, s16 *, 0x50);
                spr = func_0208c528(arg0);
                func_0208bddc(spr, (void *)data_ov004_02218cb0, 0, 0, 0);
                M2C_FIELD(spr, s32 *, 0x34) = r8;
                M2C_FIELD(spr, s32 *, 0x38) = r9;
                M2C_FIELD(spr, s32 *, 0x3C) = 0;
                PlaySoundEffect(0xFA);
            }
            M2C_FIELD(arg0, u16 *, 0x4E) = (u16)EaseInterpolate(0, 0, 0x20, M2C_FIELD(arg0, u16 *, 0x46), M2C_FIELD(arg0, u16 *, 0x48));
            M2C_FIELD(arg0, u16 *, 0x50) = (u16)EaseInterpolate(0, 0, -96, M2C_FIELD(arg0, u16 *, 0x46), M2C_FIELD(arg0, u16 *, 0x48));
        }

        M2C_FIELD(arg0, u16 *, 0x52) = M2C_FIELD(arg0, u16 *, 0x52) + 1;
        {
            u16 c = M2C_FIELD(arg0, u16 *, 0x52);
            void *eng = (void *)gCur3DSpriteEngine;
            u16 h;
            h = c >> 1;
            h = 0 - h;
            M2C_FIELD(eng, u16 *, 0x38) = h;
            h = c >> 2;
            M2C_FIELD(eng, u16 *, 0x40) = h;
            h = c >> 2;
            h = 0 - h;
            M2C_FIELD(eng, u16 *, 0x3A) = h;
            h = c >> 1;
            M2C_FIELD(eng, u16 *, 0x42) = h;
        }
        loop++;

skip_update:
        ;
    }
    gCur3DSpriteEngine = savedEngine;
    return 0;
}

void func_ov004_02211740(void) {

}

/* Load graphics resources into both screen contexts when the current mode permits. */
void func_ov004_02211744(void *ctx) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
    extern u8 data_ov004_02218cbc[], data_ov004_02218cc4[], data_ov004_02218cd4[], data_ov004_02218ce0[];
    s32 func_02091e14(void);
    s32 savedContext, i;
    M2C_FIELD(ctx, s16 *, 0x42) = 0;
    M2C_FIELD(ctx, s16 *, 0x44) = 48;
    savedContext = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) gCur3DSpriteEngine = g3DSpriteEngineMain; else gCur3DSpriteEngine = g3DSpriteEngineSub;
        if ((func_02091e14() != 0 || gCur3DSpriteEngine == g3DSpriteEngineMain) &&
            (func_02091e14() != 1 || gCur3DSpriteEngine == g3DSpriteEngineSub) &&
            (func_02091e14() != 3 || gCur3DSpriteEngine == savedContext)) {
            func_0200bc5c(data_ov004_02218cbc);
            func_020814e4(data_ov004_02218cc4);
            func_02081590(data_ov004_02218cd4, M2C_FIELD((void *)gCur3DSpriteEngine, u8 **, 0x1c) + 0x6b80);
            func_020815fc(data_ov004_02218ce0, 0x360, 0x20);
            func_02081528();
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedContext;
}

/* Load a graphics resource set into both screen contexts when the current mode permits. */
void func_ov004_02211844(void *ctx) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
    extern u8 data_ov004_02218cec[];
    s32 func_02091e14(void);
    s32 savedContext, i;
    M2C_FIELD(ctx, s16 *, 0x46) = 0;
    M2C_FIELD(ctx, s16 *, 0x48) = 360;
    savedContext = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) gCur3DSpriteEngine = g3DSpriteEngineMain; else gCur3DSpriteEngine = g3DSpriteEngineSub;
        if ((func_02091e14() != 0 || gCur3DSpriteEngine == g3DSpriteEngineMain) &&
            (func_02091e14() != 1 || gCur3DSpriteEngine == g3DSpriteEngineSub) &&
            (func_02091e14() != 3 || gCur3DSpriteEngine == savedContext)) {
            func_0208c5fc(data_ov004_02218cec, 0, 0);
            func_02080774(1, 1, 0, 100, 0);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedContext;
}

void func_ov004_02211924(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
    M2C_FIELD(arg0, s16 *, 0x4A) = arg1;
    M2C_FIELD(arg0, s16 *, 0x4C) = arg2;
    M2C_FIELD(arg0, s16 *, 0x34) = arg3;
    M2C_FIELD(arg0, s16 *, 0x36) = (s16) arg4;
    M2C_FIELD(arg0, s16 *, 0x3A) = (s16) arg5;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
}

void func_ov004_02211ee8(void) {
    void func_ov004_022112e8();
    func_ov004_022112e8();
}

void func_ov004_02211ef4(void) {
    void func_ov004_02211358();
    func_ov004_02211358();
}

void func_ov004_02211f00(void) {
    M2C_UNK func_ov004_02211374();
    func_ov004_02211374();
}

void func_ov004_02211f0c(void) {
    func_ov004_02211740();
}

void func_ov004_02211f18(void) {
    s32 func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_ov004_0221194c(s32, M2C_UNK *);
    extern M2C_UNK data_ov004_02218c20;
    extern M2C_UNK data_ov004_02218d90;
    func_ov004_0221194c(func_01ffa3dc(&data_ov004_02218c20, 7), &data_ov004_02218d90);
}

void func_ov004_02211f3c(void) {
    s32 func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_ov004_0221194c(s32, M2C_UNK *);
    extern M2C_UNK data_ov004_02218c20;
    extern M2C_UNK data_ov004_02218d9c;
    func_ov004_0221194c(func_01ffa3dc(&data_ov004_02218c20, 7), &data_ov004_02218d9c);
}

void func_ov004_02211f60(void) {
    void func_ov004_02211744();
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov004_02218c20;
    if (func_01ffa770(&data_ov004_02218c20) == 0) {
        return;
    }
    func_ov004_02211744();
}

void func_ov004_02211f80(void) {
    void func_ov004_02211844();
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov004_02218c20;
    if (func_01ffa770(&data_ov004_02218c20) == 0) {
        return;
    }
    func_ov004_02211844();
}

void func_ov004_02211fa0(void) {
    s32 func_01ffa770(M2C_UNK *);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK data_ov004_02218c20;
    s32 temp_r0;
    temp_r0 = func_01ffa770(&data_ov004_02218c20);
    if (temp_r0 == 0) return;
    func_ov004_02211924((void *)temp_r0, 0xA0, 0x80, 0x100, 0x800, 0x3C);
    PlaySoundEffect(0x113);
}

void func_ov004_02211ff4(void) {
    s32 func_01ffa770(M2C_UNK *);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK data_ov004_02218c20;
    s32 temp_r0;
    temp_r0 = func_01ffa770(&data_ov004_02218c20);
    if (temp_r0 == 0) return;
    func_ov004_02211924((void *)temp_r0, 0x80, 0x60, 0x400, 0x100, 0x1E);
    PlaySoundEffect(0x112);
}

void func_ov004_02212048(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_ov004_02218c20;
    func_01ffa9e4(&data_ov004_02218c20);
}

s32 func_ov004_0221205c(void) {
    M2C_UNK func_020868e0(M2C_UNK, M2C_UNK);
    s32 func_020869a0(M2C_UNK);
    if (func_020869a0(0x60) != 0) {
        return 0;
    }
    func_020868e0(0x60, 1);
    return 1;
}

void func_ov004_02212088(void *arg0) {
    M2C_UNK func_0208f780(s32);
    s32 var_r0;
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x3A);
    var_r0 = 0x10013;
    if ((u32) temp_r1 >= 0xBU) {
        var_r0 = 0x10014;
    }
    if ((u32) temp_r1 >= 0x11U) {
        var_r0 = 0x10015;
    }
    if ((u32) temp_r1 >= 0x16U) {
        var_r0 = 0x10016;
    }
    func_0208f780(var_r0);
}

