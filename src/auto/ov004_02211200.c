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

void func_ov004_02211740(void) {

}

/* Load graphics resources into both screen contexts when the current mode permits. */
void func_ov004_02211744(void *ctx) {
    extern s32 gCur3DSpriteEngine, data_027e00c4, data_027e00c8;
    extern u8 data_ov004_02218cbc[], data_ov004_02218cc4[], data_ov004_02218cd4[], data_ov004_02218ce0[];
    s32 func_02091e14(void);
    s32 savedContext, i;
    M2C_FIELD(ctx, s16 *, 0x42) = 0;
    M2C_FIELD(ctx, s16 *, 0x44) = 48;
    savedContext = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) gCur3DSpriteEngine = data_027e00c8; else gCur3DSpriteEngine = data_027e00c4;
        if ((func_02091e14() != 0 || gCur3DSpriteEngine == data_027e00c8) &&
            (func_02091e14() != 1 || gCur3DSpriteEngine == data_027e00c4) &&
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
    extern s32 gCur3DSpriteEngine, data_027e00c4, data_027e00c8;
    extern u8 data_ov004_02218cec[];
    s32 func_02091e14(void);
    s32 savedContext, i;
    M2C_FIELD(ctx, s16 *, 0x46) = 0;
    M2C_FIELD(ctx, s16 *, 0x48) = 360;
    savedContext = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) gCur3DSpriteEngine = data_027e00c8; else gCur3DSpriteEngine = data_027e00c4;
        if ((func_02091e14() != 0 || gCur3DSpriteEngine == data_027e00c8) &&
            (func_02091e14() != 1 || gCur3DSpriteEngine == data_027e00c4) &&
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
    M2C_UNK func_0208fe30(s32);
    extern M2C_UNK data_ov004_02218c20;
    s32 temp_r0;
    temp_r0 = func_01ffa770(&data_ov004_02218c20);
    if (temp_r0 == 0) return;
    func_ov004_02211924((void *)temp_r0, 0xA0, 0x80, 0x100, 0x800, 0x3C);
    func_0208fe30(0x113);
}

void func_ov004_02211ff4(void) {
    s32 func_01ffa770(M2C_UNK *);
    M2C_UNK func_0208fe30(s32);
    extern M2C_UNK data_ov004_02218c20;
    s32 temp_r0;
    temp_r0 = func_01ffa770(&data_ov004_02218c20);
    if (temp_r0 == 0) return;
    func_ov004_02211924((void *)temp_r0, 0x80, 0x60, 0x400, 0x100, 0x1E);
    func_0208fe30(0x112);
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

