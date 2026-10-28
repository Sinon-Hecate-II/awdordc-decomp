/* 38 functions from 0x021F05FC to 0x021F15D4 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021f05fc(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02074114(M2C_UNK **, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK **func_02082028(M2C_UNK);
    void func_ov003_021f13ec(s32);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220f8e0;
    extern M2C_UNK data_ov003_0220faf8;
    extern M2C_UNK data_ov003_0220fb08;
    extern M2C_UNK data_ov003_0220fb18;
    extern M2C_UNK data_ov003_0220fb38;
    extern M2C_UNK data_ov003_0220fb64;
    extern M2C_UNK func_ov003_021f05cc;
    extern M2C_UNK func_ov003_021f05f8;
    register void *temp_r0 asm("r4");
    register u8 temp_r5 asm("r5");
    register u8 temp_ip asm("r12");
    register u8 temp_r5_2 asm("r5");
    M2C_UNK **temp_r0_10;
    M2C_UNK **temp_r0_2;
    M2C_UNK **temp_r0_3;
    M2C_UNK **temp_r0_4;
    M2C_UNK **temp_r0_5;
    M2C_UNK **temp_r0_6;
    M2C_UNK **temp_r0_7;
    M2C_UNK **temp_r0_8;
    M2C_UNK **temp_r0_9;
    M2C_UNK **temp_r1;
    M2C_UNK **temp_r1_2;
    M2C_UNK **temp_r2;
    s32 var_r3;
    u8 var_r1;
    u8 var_r3_2;

    func_ov003_021f13ec((s32)&data_ov003_0220f8e0);
    temp_r0 = func_01ffa3dc(&data_ov003_0220f8e0, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_0220fb38;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220fb64;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        temp_r5 = M2C_FIELD(temp_r0, u8 *, 0x39) & ~2;
        M2C_FIELD(temp_r0, u8 *, 0x39) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((u8) (temp_r5 & ~0xC) & ~0xF0);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~1) & ~2;
        temp_r5_2 = (u8) (temp_ip & ~4) & ~8;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = temp_r5_2;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (temp_r5_2 & ~0x70) & ~0x80);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x54) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x64) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x68) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x6C) = NULL;
        temp_r0_2 = func_02082028(0x12);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = temp_r0_2;
        temp_r0_3 = func_02082028(0x14);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &data_ov003_0220faf8;
            M2C_FIELD(temp_r0_3, s16 *, 4) = 8;
            M2C_FIELD(temp_r0_3, s16 *, 6) = 4;
            M2C_FIELD(temp_r0_3, s16 *, 8) = 0xA0;
            M2C_FIELD(temp_r0_3, s16 *, 0xA) = 0xA0;
            M2C_FIELD(temp_r0_3, s8 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x13) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x10) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0x11) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xE) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xF) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xC) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xD) = 0x63;
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_3;
        temp_r0_4 = func_02082028(0x12);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_4, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_4, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_4, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = (u16) M2C_FIELD(temp_r0_4, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = temp_r0_4;
        temp_r0_5 = func_02082028(0x12);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_5, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_5, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_5, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_5, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_5, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_5, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_5, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_5, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_5, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_5, u16 *, 2) = (u16) M2C_FIELD(temp_r0_5, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = temp_r0_5;
        temp_r0_6 = func_02082028(0x12);
        if (temp_r0_6 != NULL) {
            M2C_FIELD(temp_r0_6, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_6, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_6, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_6, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = (u16) M2C_FIELD(temp_r0_6, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C) = temp_r0_6;
        temp_r0_7 = func_02082028(0x12);
        if (temp_r0_7 != NULL) {
            M2C_FIELD(temp_r0_7, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_7, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_7, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_7, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_7, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_7, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_7, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_7, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_7, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_7, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_7, u16 *, 2) = (u16) M2C_FIELD(temp_r0_7, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = temp_r0_7;
        temp_r0_8 = func_02082028(0x48);
        if (temp_r0_8 != NULL) {
            var_r1 = 0;
            M2C_FIELD(temp_r0_8, M2C_UNK **, 0) = NULL;
            M2C_FIELD(temp_r0_8, s32 *, 4) = 0;
            do {
                temp_r2 = &temp_r0_8[var_r1];
                M2C_FIELD(temp_r2, s32 *, 8) = 0;
                M2C_FIELD(temp_r2, s32 *, 0x18) = 0;
                M2C_FIELD(temp_r2, s32 *, 0x28) = 0;
                var_r1 += 1;
                M2C_FIELD(temp_r2, s32 *, 0x38) = 0;
            } while ((u32) var_r1 < 4U);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x64) = temp_r0_8;
        temp_r0_9 = func_02082028(0x80);
        if (temp_r0_9 != NULL) {
            var_r3 = 0;
            *temp_r0_9 = &data_ov003_0220fb08;
            do {
                temp_r1 = &temp_r0_9[var_r3];
                var_r3 += 1;
                M2C_FIELD(temp_r1, s32 *, 0x44) = 0;
            } while (var_r3 < 0xD);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x68) = temp_r0_9;
        temp_r0_10 = func_02082028(0xE8);
        if (temp_r0_10 != NULL) {
            *temp_r0_10 = &data_ov003_0220fb18;
            func_02074114(temp_r0_10 + 0x14, 4, 0x18, &func_ov003_021f05cc, &func_ov003_021f05f8);
            var_r3_2 = 0;
            do {
                temp_r1_2 = &temp_r0_10[var_r3_2];
                var_r3_2 += 1;
                M2C_FIELD(temp_r1_2, s32 *, 0x78) = 0;
            } while ((u32) var_r3_2 < 0x1AU);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x6C) = temp_r0_10;
    }
    M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~1) | 1);
}

void func_ov003_021f09dc(void *arg0) {
}

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

M2C_UNK func_ov003_021f0e94(M2C_UNK arg0) {
    return 0;
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

void func_ov003_021f1348(s32 arg0) {
    M2C_UNK func_ov003_021f0e94(s32);
    func_ov003_021f0e94(arg0 + 0xFFFFFFCC);
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

