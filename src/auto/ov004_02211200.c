/* 27 functions from 0x02211200 to 0x022120C0 (ov004), found by ds-decomp. */
#include "common.h"
struct ScreenConfig1194 { u16 value[6]; };
struct ScreenConfigFields1194 { u16 a,b,c,d,e,f; };

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
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK data_ov004_02218c00;
    if ((u8)((u32)(gMapConfig << 29) >> 29)) return;
    CreateSpriteObject(&data_ov004_02218c00, arg0);
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
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK data_ov004_02218be0;
    if ((u8)((u32)(gMapConfig << 29) >> 29)) return;
    CreateSpriteObject(&data_ov004_02218be0, arg0);
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
            SetFileDirectory(data_ov004_02218cbc);
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

void func_ov004_0221194c(M2C_UNK arg0, M2C_UNK *arg1) {
    M2C_UNK func_01ff85b8(s32, u16, M2C_UNK);
    u32 func_01ff9c34(u8, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK StringFormat(void *, void *, void *);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(M2C_UNK *, s32);
    M2C_UNK func_020815fc(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_0208161c(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020822b8(u16 *);
    s32 func_02091e14();
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov004_02218bac;
    extern M2C_UNK data_ov004_02218cf8;
    extern M2C_UNK data_ov004_02218d00;
    extern M2C_UNK data_ov004_02218d10;
    extern M2C_UNK data_ov004_02218d1c;
    extern M2C_UNK data_ov004_02218d28;
    extern M2C_UNK data_ov004_02218d34;
    extern M2C_UNK data_ov004_02218d40;
    extern M2C_UNK data_ov004_02218d48;
    extern M2C_UNK data_ov004_02218d50;
    extern M2C_UNK data_ov004_02218d58;
    extern M2C_UNK data_ov004_02218d60;
    extern M2C_UNK data_ov004_02218d6c;
    extern M2C_UNK data_ov004_02218d78;
    extern M2C_UNK data_ov004_02218d84;
    u8 buffer[32];
    u16 config[6];u16 b,a,d,c,e,f;
    u16 *volatile sp3C;
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
    u16 *volatile sp0;
    u16 *temp_r0;
    u16 *temp_r0_10;
    u16 *temp_r0_11;
    u16 *temp_r0_12;
    u16 *temp_r0_13;
    u16 *temp_r0_14;
    u16 *temp_r0_15;
    u16 *temp_r0_16;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    u16 *temp_r0_7;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    s32 temp_r8;
    s32 var_r9;
    s32 var_r0;

    var_r9 = 0;
a=M2C_FIELD(&data_ov004_02218bac,u16 *,0);b=M2C_FIELD(&data_ov004_02218bac,u16 *,2);
config[0]=a;config[1]=b;
d=M2C_FIELD(&data_ov004_02218bac,u16 *,6);c=M2C_FIELD(&data_ov004_02218bac,u16 *,4);
config[3]=d;config[2]=c;
e=M2C_FIELD(&data_ov004_02218bac,u16 *,8);f=M2C_FIELD(&data_ov004_02218bac,u16 *,10);
config[4]=e;config[5]=f;
    temp_r8=gCur3DSpriteEngine;
    do {
        if (var_r9 == 0) {
            var_r0 = g3DSpriteEngineMain;
        } else {
            var_r0 = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = var_r0;
        if (((func_02091e14() != 0) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) && ((func_02091e14() != 1) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) && ((func_02091e14() != 3) || (gCur3DSpriteEngine == temp_r8))) {
            func_020822b8(config);
            SetFileDirectory(&data_ov004_02218cf8);
            func_020814e4(&data_ov004_02218d00);
            func_02081590(&data_ov004_02218d10, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC));
            func_020815fc(&data_ov004_02218d1c, 0, 0x20);
            func_02081590(&data_ov004_02218d28, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
            func_02081590(&data_ov004_02218d34, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            func_02081528();
            StringFormat(buffer, &data_ov004_02218d40, arg1);
            func_020814e4(buffer);
            StringFormat(buffer, &data_ov004_02218d48, arg1);
            func_02081590(buffer, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
            StringFormat(buffer, &data_ov004_02218d50, arg1);
            func_02081590(buffer, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
            StringFormat(buffer, &data_ov004_02218d58, arg1);
            func_0208161c(buffer, 2, 0, 0x200);
            func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), (u16)func_01ff9c34((u8) ((u32) (*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x1D) >> 0x1D), 2), 0);
            func_02081528();
            func_020814e4(&data_ov004_02218d60);
            func_02081590(&data_ov004_02218d6c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
            func_02081590(&data_ov004_02218d78, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
            func_0208161c(&data_ov004_02218d84, 3, 0x200, 0x200);
            func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), (u16)func_01ff9c34((u8) ((u32) (*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x1D) >> 0x1D), 3), 0x1000);
            func_02081528();
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x38) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x40) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3A) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x42) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3C) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x44) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3E) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x46) = 0;
            temp_r0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp3C = (u16*)((u8*)temp_r0+0x12);
            *sp3C = (s16) ((*sp3C & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 4;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0xC;
            temp_r0_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp38 = (u16*)((u8*)temp_r0_2+0x12);
            *sp38 = (s16) (*sp38 & ~1);
            temp_r0_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp34 = (u16*)((u8*)temp_r0_3+0x12);
            *sp34 = (s16) (*sp34 | 2);
            temp_r0_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp30 = (u16*)((u8*)temp_r0_4+0x12);
            *sp30 = (s16) (*sp30 & ~4);
            temp_r0_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp2C = (u16*)((u8*)temp_r0_5+0x12);
            *sp2C = (s16) (*sp2C & ~8);
            temp_r0_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp28 = (u16*)((u8*)temp_r0_6+0x12);
            *sp28 = (s16) (*sp28 & ~0x10);
            temp_r0_7 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp24 = (u16*)((u8*)temp_r0_7+0x12);
            *sp24 = (s16) (*sp24 & ~0x100);
            temp_r0_8 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp20 = (u16*)((u8*)temp_r0_8+0x12);
            *sp20 = (s16) (*sp20 & ~0x200);
            temp_r0_9 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp1C = (u16*)((u8*)temp_r0_9+0x12);
            *sp1C = (s16) (*sp1C & ~0x400);
            temp_r0_10 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp18 = (u16*)((u8*)temp_r0_10+0x12);
            *sp18 = (s16) (*sp18 | 0x800);
            temp_r0_11 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp14 = (u16*)((u8*)temp_r0_11+0x12);
            *sp14 = (s16) (*sp14 & ~0x1000);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
            temp_r0_12 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp10 = temp_r0_12;
            *sp10 = *sp10 & ~0x10;
            temp_r0_13 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            spC = temp_r0_13;
            *spC = *spC | 0x20;
            temp_r0_14 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp8 = temp_r0_14;
            *sp8 = *sp8 | 0x40;
            temp_r0_15 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp4 = temp_r0_15;
            *sp4 = *sp4 | 0x80;
            temp_r0_16 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp0 = temp_r0_16;
            *sp0 = *sp0 | 0x100;
        }
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r8;
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
    void func_ov004_0221194c(s32, M2C_UNK *);
    extern M2C_UNK data_ov004_02218c20;
    extern M2C_UNK data_ov004_02218d90;
    func_ov004_0221194c(func_01ffa3dc(&data_ov004_02218c20, 7), &data_ov004_02218d90);
}

void func_ov004_02211f3c(void) {
    s32 func_01ffa3dc(M2C_UNK *, s32);
    void func_ov004_0221194c(s32, M2C_UNK *);
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

