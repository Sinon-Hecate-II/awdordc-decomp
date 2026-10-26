/* 81 functions from 0x022056BC to 0x022066A8 (ov003), found by ds-decomp. */
#include "common.h"

extern void **data_027e0058;

M2C_UNK **func_ov003_02205e34(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020990c0();
    M2C_UNK func_02082040();
    extern M2C_UNK data_ov003_02210754;
    register s32 var_r4;

    *arg0 = &data_ov003_02210754;
    func_020990c0();
    var_r4 = 0;
    do {
        if (arg0[var_r4 + 5] != 0) {
            func_01ffa574();
        }
        if (arg0[var_r4 + 9] != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while (var_r4 < 4);
    func_02082040(arg0);
    return arg0;
}

M2C_UNK **func_ov003_02205e94(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020741c4(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    M2C_UNK func_02082040();
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK func_ov003_021f05f8;
    register u8 var_r5;
    M2C_UNK *temp_r0;

    *arg0 = &data_ov003_02210764;
    var_r5 = 0;
    do {
        temp_r0 = arg0[var_r5 + 0x32];
        if (temp_r0 != NULL) {
            M2C_FIELD(*temp_r0, M2C_UNK (**)(), 0x4)();
        }
        var_r5 += 1;
    } while (var_r5 < 8);
    var_r5 = 0;
    do {
        if (arg0[var_r5 + 0x3A] != 0) {
            func_01ffa574();
        }
        var_r5 += 1;
    } while (var_r5 < 9);
    func_020741c4((u8 *)arg0 + 8, 8, 0x18, &func_ov003_021f05f8);
    func_02082040(arg0);
    return arg0;
}

M2C_UNK **func_ov003_0220607c(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020990c0();
    extern M2C_UNK data_ov003_02210754;
    register s32 var_r4;

    *arg0 = &data_ov003_02210754;
    func_020990c0();
    var_r4 = 0;
    do {
        if (arg0[var_r4 + 5] != 0) {
            func_01ffa574();
        }
        if (arg0[var_r4 + 9] != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while (var_r4 < 4);
    return arg0;
}

M2C_UNK **func_ov003_022060d4(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020741c4(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK func_ov003_021f05f8;
    register u8 var_r5;
    M2C_UNK *temp_r0;
    M2C_UNK (**temp_vt)(void);

    *arg0 = &data_ov003_02210764;
    var_r5 = 0;
    do {
        temp_r0 = arg0[var_r5 + 0x32];
        if (temp_r0 != 0) {
            temp_vt = *temp_r0;
            temp_vt[1]();
        }
        var_r5 += 1;
    } while (var_r5 < 8);
    var_r5 = 0;
    do {
        if (arg0[var_r5 + 0x3A] != 0) {
            func_01ffa574();
        }
        var_r5 += 1;
    } while (var_r5 < 9);
    func_020741c4((u8 *)arg0 + 8, 8, 0x18, &func_ov003_021f05f8);
    return arg0;
}

s32 func_ov003_02206160(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_02206174(M2C_UNK arg0, s32 arg1) {
    extern M2C_UNK data_02168f14;
    u16 v;
    v = M2C_FIELD(&data_02168f14, u16 *, 0);
    v = (u16)((v & ~0x100) | ((arg1 & 1) << 8));
    M2C_FIELD(&data_02168f14, u16 *, 0) = v;
}

s32 func_ov003_0220619c(void) {
    extern M2C_UNK data_02168f14;
    u16 v;
    v = (u16)M2C_FIELD(&data_02168f14, u16 *, 0);
    return (s32)((v >> 8) & 1);
}

s32 func_ov003_022061b4(void) {
    return 1;
}

s32 func_ov003_022061bc(void) {
    return 1;
}

s32 func_ov003_022061c4(void) {
    return 1;
}

s32 func_ov003_022061cc(void) {
    return 0;
}

void func_ov003_022061d4(void) {

}

s32 func_ov003_022061d8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_ov003_02206270(void) {
    return 1;
}

s32 func_ov003_02206278(void) {
    return 1;
}

s32 func_ov003_02206280(void) {
    return 3;
}

s32 func_ov003_02206288(void) {
    return 0;
}

void func_ov003_02206290(void) {

}

s32 func_ov003_02206294(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022062a8(s32 arg0, s16 arg1) {
    extern M2C_UNK data_02168f14;
    M2C_FIELD(&data_02168f14, s16 *, 0x6) = arg1;
}

u16 func_ov003_022062b8(void) {
    extern M2C_UNK data_02168f14;
    return M2C_FIELD(&data_02168f14, u16 *, 6);
}

s32 func_ov003_022062c8(void) {
    return 0;
}

s32 func_ov003_022062d0(void) {
    return 0x1F4;
}

s32 func_ov003_022062d8(void) {
    return 0x251C;
}

s32 func_ov003_022062e4(void) {
    return 0;
}

void func_ov003_022062ec(void) {

}

s32 func_ov003_022062f0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_ov003_02206314(void) {
    extern M2C_UNK data_02168f14;
    return M2C_FIELD(&data_02168f14, s32 *, 8);
}

s32 func_ov003_02206324(void) {
    return 0;
}

s32 func_ov003_0220632c(void) {
    return 0x3E8;
}

s32 func_ov003_02206334(void) {
    return 0x182B8;
}

s32 func_ov003_02206340(void) {
    return 0;
}

void func_ov003_02206348(void) {

}

s32 func_ov003_0220634c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_ov003_02206390(void) {
    return 0;
}

s32 func_ov003_02206398(void) {
    return 1;
}

s32 func_ov003_022063a0(void) {
    return 0x63;
}

s32 func_ov003_022063a8(void) {
    return 4;
}

void func_ov003_022063b0(void) {

}

s32 func_ov003_022063b4(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022063c8(s32 arg0, u8 arg1) {
    extern void **data_027e0058;
    s8 var_r1;

    switch (arg1 & 0xff) {
    case 0:
        var_r1 = 0;
        break;
    case 1:
        var_r1 = 3;
        break;
    case 2:
        var_r1 = 1;
        break;
    case 3:
        var_r1 = 2;
        break;
    default:
        var_r1 = 0;
        break;
    }
    M2C_FIELD(*data_027e0058, s8 *, 0x5157) = var_r1;
}

s32 func_ov003_02206428(void) {
    extern void **data_027e0058;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(*data_027e0058, u8 *, 0x5157);
    switch (temp_r0) {
    case 0:
        return 0;
    case 3:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    default:
        return 0;
    }
}

s32 func_ov003_02206484(void) {
    return 1;
}

s32 func_ov003_0220648c(void) {
    return 1;
}

s32 func_ov003_02206494(void) {
    return 3;
}

s32 func_ov003_0220649c(void) {
    return 0;
}

void func_ov003_022064a4(void) {

}

s32 func_ov003_022064a8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022064bc(s32 arg0_unused, s32 arg1) {
    extern void **data_027e0058;
    u16 var_r3;

    if (arg1 == 4) {
        var_r3 = 0;
        M2C_FIELD(*data_027e0058, s8 *, 0x5159) = 1;
    } else {
        var_r3 = arg1;
        M2C_FIELD(*data_027e0058, s8 *, 0x5159) = 0;
    }
    M2C_FIELD(*data_027e0058, u8 *, 0x5158) = (u8) var_r3;
    M2C_FIELD(*data_027e0058, u8 *, 0x515A) = (u8) var_r3;
    M2C_FIELD(*data_027e0058, u8 *, 0x515B) = (u8) var_r3;
}

u8 func_ov003_02206544(void **arg0) {
    void *temp_r1 = *data_027e0058;
    if (M2C_FIELD(temp_r1, u8 *, 0x5159) != 1) {
        return M2C_FIELD(temp_r1, u8 *, 0x515B);
    }
    return M2C_FIELD(arg0[0], u8 (**)(void **), 0xC)(arg0);
}

s32 func_ov003_0220657c(void) {
    return 4;
}

s32 func_ov003_02206584(void) {
    return 1;
}

s32 func_ov003_0220658c(void) {
    return 1;
}

s32 func_ov003_02206594(void) {
    return 0;
}

void func_ov003_0220659c(void) {

}

s32 func_ov003_022065a0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022065b4(s32 arg0_unused, s8 arg1) {
    extern void **data_027e0058;
    M2C_FIELD(*data_027e0058, s8 *, 0x5156) = arg1;
}

u8 func_ov003_022065d0(void) {
    extern void **data_027e0058;
    return M2C_FIELD(*data_027e0058, u8 *, 0x5156);
}

s32 func_ov003_022065ec(void) {
    return 1;
}

s32 func_ov003_022065f4(void) {
    return 1;
}

s32 func_ov003_022065fc(void) {
    return 1;
}

s32 func_ov003_02206604(void) {
    return 0;
}

void func_ov003_0220660c(void) {

}

u8 func_ov003_02206690(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

