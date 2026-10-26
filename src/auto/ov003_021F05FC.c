/* 38 functions from 0x021F05FC to 0x021F15D4 (ov003), found by ds-decomp. */
#include "common.h"

s32 func_ov003_021f0dcc(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

M2C_UNK **func_ov003_021f0de0(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020990c0();
    M2C_UNK func_0209940c();
    extern M2C_UNK data_ov003_0220fb08;
    register s32 var_r4;
    *arg0 = &data_ov003_0220fb08;
    func_0209940c();
    func_020990c0();
    var_r4 = 0;
    do {
        if (arg0[var_r4 + 0x11] != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while (var_r4 < 0xD);
    func_02082040(arg0);
    return arg0;
}

M2C_UNK **func_ov003_021f0e30(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020741c4(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_ov003_0220fb18;
    extern M2C_UNK func_ov003_021f05f8;
    u8 var_r4;
    *arg0 = &data_ov003_0220fb18;
    var_r4 = 0;
    do {
        if (M2C_FIELD(((s32)arg0 + (var_r4 * 4)), s32 *, 0x78) != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while ((u32)var_r4 < 0x1AU);
    func_020741c4((u8 *)arg0 + 0x14, 4, 0x18, &func_ov003_021f05f8);
    func_02082040(arg0);
    return arg0;
}

M2C_UNK **func_ov003_021f128c(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020990c0();
    M2C_UNK func_0209940c();
    extern M2C_UNK data_ov003_0220fb08;
    register s32 var_r4;
    *arg0 = &data_ov003_0220fb08;
    func_0209940c();
    func_020990c0();
    var_r4 = 0;
    do {
        if (arg0[var_r4 + 0x11] != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while (var_r4 < 0xD);
    
    return arg0;
}

M2C_UNK **func_ov003_021f12d4(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020741c4(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_ov003_0220fb18;
    extern M2C_UNK func_ov003_021f05f8;
    u8 var_r4;
    *arg0 = &data_ov003_0220fb18;
    var_r4 = 0;
    do {
        if (M2C_FIELD(((s32)arg0 + (var_r4 * 4)), s32 *, 0x78) != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while ((u32)var_r4 < 0x1AU);
    func_020741c4((u8 *)arg0 + 0x14, 4, 0x18, &func_ov003_021f05f8);
    return arg0;
}

void func_ov003_021f1330(void) {

}

s32 func_ov003_021f1334(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_ov003_021f13c8(void) {
    s32 func_01ffa770();
    extern M2C_UNK data_ov003_022111c0;
    if (M2C_FIELD(&data_ov003_022111c0, s32 *, 0xC) == 0) {
        return 0;
    }
    return func_01ffa770();
}

void func_ov003_021f13ec(s32 arg0) {
    void func_ov003_021f140c(s8);
    extern M2C_UNK data_ov003_022111c0;
    func_ov003_021f140c(0);
    M2C_FIELD(&data_ov003_022111c0, s32 *, 0xC) = arg0;
}

void func_ov003_021f140c(s8 arg0) {
    extern M2C_UNK data_ov003_022111c0;
    M2C_FIELD(&data_ov003_022111c0, s8 *, 5) = arg0;
}

u8 func_ov003_021f141c(void) {
    extern M2C_UNK data_ov003_022111c0;
    return M2C_FIELD(&data_ov003_022111c0, u8 *, 5);
}

u8 func_ov003_021f142c(void) {
    u8 var_r0;

    if (func_ov003_021f141c() == 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_021f1448(void) {
    u8 var_r0;

    if (func_ov003_021f141c() == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_021f1464(void) {
    u8 var_r0;

    if (func_ov003_021f141c() == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021f1480(s8 arg0) {
    extern M2C_UNK data_ov003_022111c0;
    M2C_FIELD(&data_ov003_022111c0, s8 *, 6) = arg0;
}

u8 func_ov003_021f1490(void) {
    extern M2C_UNK data_ov003_022111c0;
    return M2C_FIELD(&data_ov003_022111c0, u8 *, 6);
}

void func_ov003_021f14a0(void) {
    extern M2C_UNK data_ov003_022111c0;
    M2C_FIELD(&data_ov003_022111c0, u8 *, 1) = 1;
}

void func_ov003_021f14b4(void) {
    extern M2C_UNK data_ov003_022111c0;
    M2C_FIELD(&data_ov003_022111c0, u8 *, 1) = 0;
}

u8 func_ov003_021f14c8(void) {
    extern M2C_UNK data_ov003_022111c0;
    return M2C_FIELD(&data_ov003_022111c0, u8 *, 1);
}

void func_ov003_021f14d8(s8 arg0, s8 arg1, s8 arg2) {
    extern M2C_UNK data_ov003_022111c0;
    M2C_FIELD(&data_ov003_022111c0, s8 *, 4) = arg0;
    M2C_FIELD(&data_ov003_022111c0, s8 *, 2) = arg1;
    M2C_FIELD(&data_ov003_022111c0, s8 *, 3) = arg2;
}

s32 func_ov003_021f14f0(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0;
    case 1:
        return -0x100;
    case 2:
        return 0x100;
    default:
        return 0;
    }
}

void func_ov003_021f152c(s8 arg0) {
    extern M2C_UNK data_ov003_022111c0;
    M2C_FIELD(&data_ov003_022111c0, s8 *, 4) = arg0;
}

s32 func_ov003_021f153c(void) {
    extern M2C_UNK data_ov003_022111c0;
    switch (M2C_FIELD(&data_ov003_022111c0, u8 *, 4)) {
    case 0: return 0;
    case 1: return 0x100;
    case 2: return -0x100;
    default: return 0;
    }
}

u8 func_ov003_021f1584(void) {
extern M2C_UNK data_ov003_022111c0;
return M2C_FIELD(&data_ov003_022111c0,u8 *,2);
}

s32 func_ov003_021f1594(void) {
extern M2C_UNK data_ov003_022111c0;
return func_ov003_021f14f0(M2C_FIELD(&data_ov003_022111c0,u8 *,2));
}

u8 func_ov003_021f15ac(void) {
    extern M2C_UNK data_ov003_022111c0;
    return M2C_FIELD(&data_ov003_022111c0, u8 *, 3);
}

s32 func_ov003_021f15bc(void) {
extern M2C_UNK data_ov003_022111c0;
return func_ov003_021f14f0(M2C_FIELD(&data_ov003_022111c0,u8 *,3));
}

