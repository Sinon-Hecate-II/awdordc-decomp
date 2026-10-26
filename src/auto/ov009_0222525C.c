/* 84 functions from 0x0222525C to 0x02226214 (ov009), found by ds-decomp. */
#include "common.h"

void func_ov009_0222525c(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    M2C_UNK func_ov009_02221320(M2C_UNK);
    s32 func_ov009_02223ce4();
    extern M2C_UNK data_ov009_022264b8;
    extern M2C_UNK data_ov009_022264e0;
    extern M2C_UNK data_ov009_02226638;
    func_01ffa9e4(&data_ov009_022264b8);
    func_01ffa9e4(&data_ov009_02226638);
    func_01ffa9e4(&data_ov009_022264e0);
    if (func_ov009_02223ce4() != 0) {
        return;
    }
    func_ov009_02221320(9);
}

void func_ov009_0222529c(void) {
    s32 func_ov009_02224194();
    s32 func_ov009_022241a4();
    s32 func_ov009_02224688();
    s32 func_ov009_02223b5c();
    s32 func_ov009_02223c08();
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    M2C_UNK func_ov009_02221320(M2C_UNK);
    extern M2C_UNK data_ov009_022264b8, data_ov009_02226638, data_ov009_022264e0;
    s32 state = func_ov009_02224194();
    if (state == 1) return;
    if (state == 2) {
        if (func_ov009_02224688() != 0) return;
        func_ov009_0222525c();
        return;
    }
    if (state != 5 && state != 4) {
        func_ov009_0222525c();
        return;
    }
    func_ov009_02221320(3);
    func_01ffa9e4(&data_ov009_022264b8);
    func_01ffa9e4(&data_ov009_02226638);
    func_01ffa9e4(&data_ov009_022264e0);
    switch (func_ov009_022241a4()) {
    case 0:
        if (func_ov009_02223b5c() != 0) return;
        func_ov009_0222525c();
        return;
    case 1:
        if (func_ov009_02223c08() != 0) return;
        func_ov009_0222525c();
        return;
    }
}

void func_ov009_02225348(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov009_02226440;
    func_01ffa42c(&data_ov009_02226440, arg0);
}

s32 func_ov009_02225360(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    M2C_UNK func_ov009_02221320(M2C_UNK);
    M2C_UNK func_ov009_022224e0();
    M2C_UNK func_ov009_022227d4();
    M2C_UNK func_ov009_022244c0();
    s32 func_02011a20(s32, s32, s32);
    s32 func_020122ac(void *);
    void func_ov009_02223cbc(void);
    extern M2C_UNK data_ov009_022264b8, data_ov009_02226638, data_ov009_022264e0;
    func_ov009_02221320(1);
    func_ov009_022224e0();
    func_01ffa9e4(&data_ov009_022264b8);
    func_01ffa9e4(&data_ov009_02226638);
    func_01ffa9e4(&data_ov009_022264e0);
    if (func_02011a20(0xC, 0, 0) != 0) {
        func_ov009_022227d4();
        func_ov009_02221320(8);
        return 0;
    }
    if (func_02011a20(4, 0, 0) != 0) {
        func_ov009_022227d4();
        func_ov009_02221320(8);
        return 0;
    }
    if (func_020122ac(&func_ov009_02223cbc) != 2) {
        func_ov009_022227d4();
        func_ov009_02221320(8);
        return 0;
    }
    func_ov009_022244c0();
    return 1;
}

void func_ov009_02225420(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov009_02226468;
    func_01ffa42c(&data_ov009_02226468, arg0);
}

void func_ov009_02225438(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov009_02226490;
    func_01ffa42c(&data_ov009_02226490, arg0);
}

s32 func_ov009_02225450(void) {
    s32 func_02011934();
    return func_02011934() & 0xFF;
}

u8 func_ov009_02225460(void) {
    extern M2C_UNK data_ov009_022268e0;
    return M2C_FIELD(&data_ov009_022268e0, u8 *, 0x157);
}

void func_ov009_02225470(void) {
    M2C_UNK func_02076614();
    M2C_UNK func_ov009_02224174();
    func_ov009_02224174();
    func_02076614();
}

void func_ov009_02225480(void) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s16 *, 8) = 0;
}

u16 func_ov009_02225494(void) {
    extern M2C_UNK data_ov009_022268e0;
    return M2C_FIELD(&data_ov009_022268e0, u16 *, 8);
}

s32 func_ov009_022254a4(void) {
    s32 func_ov009_02225450();
    if ((func_ov009_02224194() != 4) && (func_ov009_02224194() != 5)) {
        return 1;
    }
    if (func_ov009_02225450() == 0) {
        return 1;
    }
    return 0;
}

s32 func_ov009_022254d8(void) {
    if ((func_ov009_02224194() != 4) && (func_ov009_02224194() != 5)) {
        return 0;
    }
    if (func_ov009_02225450() != 0) {
        return 1;
    }
    return 0;
}

M2C_UNK func_ov009_0222550c(void *arg0, s32 arg1) {
    M2C_UNK func_ov009_02224d9c(s32, void *, s32, s32);
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 4) = 1 << func_ov009_02225450();
    M2C_FIELD(&data_ov009_022268e0, void **, 0x48) = arg0;
    if (func_ov009_022254a4() == 0) return;
    func_ov009_02224d9c(2, M2C_FIELD(&data_ov009_022268e0, void **, 0x48), 8, 0xFFFF);
}

s32 func_ov009_02225560(s32 arg0) {
    s32 func_ov009_02224174();
    s32 func_ov009_02224194();
    M2C_UNK func_ov009_02224d9c(s32, void *, s32, s32);
    extern M2C_UNK data_ov009_022268e0;
    s32 temp_r4;
    s32 var_r5;
    temp_r4 = func_ov009_02224174();
    var_r5 = 0;
    if (M2C_FIELD(&data_ov009_022268e0, void **, 0x48) != NULL &&
        temp_r4 != (temp_r4 & M2C_FIELD(M2C_FIELD(&data_ov009_022268e0, void **, 0x48), u16 *, 4))) var_r5 = 1;
    if (func_ov009_02224194() == 8 || func_ov009_02224194() == 9) var_r5 = 0;
    if (!(temp_r4 & 1)) var_r5 = 0;
    if (var_r5 == 0 && func_ov009_022254a4() != 0)
        func_ov009_02224d9c(3, M2C_FIELD(&data_ov009_022268e0, void **, 0x48), 8, 0xFFFF);
    return var_r5;
}

void func_ov009_022255ec() {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, void **, 0x48) = NULL;
}

void func_ov009_02225600(void *arg0) {
    M2C_UNK func_ov009_0222550c(void *, s32);
    func_ov009_0222550c(arg0 + 0x38, M2C_FIELD(arg0, s32 *, 0x34));
}

s32 func_ov009_02225614(s32 arg0) {
    s32 func_ov009_02225560(s32);
    if ((func_ov009_02224194() != 4) && (func_ov009_02224194() != 5)) {
        return 0;
    }
    return func_ov009_02225560(arg0 + 0x38);
}

void func_ov009_02225644(s32 arg0) {
    void func_ov009_022255ec();
    func_ov009_022255ec(arg0 + 0x38);
}

void *func_ov009_02225654(s32 arg0, M2C_UNK arg1) {
    extern M2C_UNK data_ov009_02226550;
    extern M2C_UNK data_ov009_02226700;
    void *temp_r0;

    if ((func_ov009_02224194() != 4) && (func_ov009_02224194() != 5)) {
        return NULL;
    }
    temp_r0 = func_01ffa42c(&data_ov009_02226550, arg1);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov009_02226700;
        M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    }
    return temp_r0;
}

M2C_UNK func_ov009_022256a4(s32 arg0) {
    s32 func_ov009_02223fbc();
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(arg0, u16 *, 2) = 1 << func_ov009_02225450();
    M2C_FIELD(arg0, u8 *, 0) = func_ov009_02223fbc();
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x20) = arg0;
}

s32 func_ov009_022256d4(s32 arg0) {
    s32 func_ov009_02224174();
    extern M2C_UNK data_ov009_022268e0;
    s32 mask, var_r4;
    if (M2C_FIELD(&data_ov009_022268e0, u16 **, 0x20) != NULL &&
        (var_r4 = func_ov009_02224174(), mask = func_ov009_02224174(), var_r4 != (M2C_FIELD(M2C_FIELD(&data_ov009_022268e0, u16 **, 0x20), u16 *, 2) & mask))) var_r4 = 1;
    else var_r4 = 0;
    if (*M2C_FIELD(&data_ov009_022268e0, u8 **, 0x20) == 0) var_r4 = 0;
    if (func_ov009_02224194() != 4 && func_ov009_02224194() != 5) var_r4 = 0;
    if (func_ov009_02224194() == 8 || func_ov009_02224194() == 9) var_r4 = 0;
    return var_r4;
}

void func_ov009_02225768(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, void **, 0x20) = NULL;
}

void func_ov009_0222577c(s32 arg0) {
    M2C_UNK func_ov009_022256a4(s32);
    func_ov009_022256a4(arg0 + 0x34);
}

void func_ov009_0222578c(s32 arg0) {
    M2C_UNK func_ov009_022256d4(s32);
    func_ov009_022256d4(arg0 + 0x34);
}

void func_ov009_0222579c(s32 arg0) {
    void func_ov009_02225768(s32);
    func_ov009_02225768(arg0 + 0x34);
}

void func_ov009_022257ac(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_022266ec;
    extern M2C_UNK data_ov009_02226588;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa42c(&data_ov009_02226588, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_022266ec;
    }
}

M2C_UNK func_ov009_022257d4(s32 arg0) {
    M2C_UNK func_ov009_02224024();
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(arg0, u8 *, 0) = 0;
    M2C_FIELD(arg0, u16 *, 2) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x24) = arg0;
    return func_ov009_02224024();
}

s32 func_ov009_022257f8(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 var_r4 = 0;
    if (M2C_FIELD(&data_ov009_022268e0, u8 **, 0x24) != NULL &&
        *M2C_FIELD(&data_ov009_022268e0, u8 **, 0x24) != 0) var_r4 = 1;
    if (func_ov009_02224194() != 4 && func_ov009_02224194() != 5) var_r4 = 0;
    if (func_ov009_022254a4() != 0) var_r4 = 0;
    if (func_ov009_02224194() == 8 || func_ov009_02224194() == 9) var_r4 = 0;
    return var_r4;
}

void func_ov009_02225864() {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, void **, 0x24) = NULL;
}

void func_ov009_02225878(s32 arg0) {
    M2C_UNK func_ov009_022257d4(s32);
    func_ov009_022257d4(arg0 + 0x34);
}

void func_ov009_02225888(s32 arg0) {
    M2C_UNK func_ov009_022257f8(s32);
    func_ov009_022257f8(arg0 + 0x34);
}

void func_ov009_02225898(s32 arg0) {
    void func_ov009_02225864();
    func_ov009_02225864(arg0 + 0x34);
}

void func_ov009_022258a8(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_022266d8;
    extern M2C_UNK data_ov009_022265c0;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa42c(&data_ov009_022265c0, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_022266d8;
    }
}

s32 func_ov009_022258d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02007f8c(arg3, 0, arg1);
    *(s32 *)arg4 = 0;
    return 1;
}

s32 func_ov009_022258f8(void) {
    return 0;
}

void func_ov009_02225900(void *arg0) {
    M2C_UNK func_ov009_022258d0(s32, s32, s32, s32, s32);
    func_ov009_022258d0(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), M2C_FIELD(arg0, s32 *, 0x44));
}

void func_ov009_02225928(void) {
    M2C_UNK func_ov009_022258f8();
    func_ov009_022258f8();
}

void func_ov009_02225934(void) {

}

void func_ov009_02225938(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    extern M2C_UNK data_ov009_02226518;
    extern M2C_UNK data_ov009_022266c4;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_ov009_02226518, arg5);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov009_022266c4;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x44) = arg4;
}

s32 func_ov009_02225a98(s32 arg0) {
    s32 func_ov009_02224174();
    extern M2C_UNK data_ov009_022268e0;
    s32 first, mask;
    if (M2C_FIELD(&data_ov009_022268e0, void **, 0x28) != NULL) {
        first = func_ov009_02224174();
        mask = func_ov009_02224174();
        if (first != (*M2C_FIELD(&data_ov009_022268e0, u16 **, 0x28) & mask)) return 1;
    }
    return 0;
}

void func_ov009_02225ae0(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, void **, 0x28) = NULL;
}

void func_ov009_02225af4(s32 arg0) {
    M2C_UNK func_ov009_0222598c(s32);
    func_ov009_0222598c(arg0 + 0x34);
}

s32 func_ov009_02225b04(s32 arg0) {
    s32 func_ov009_02225a98(s32);
    if ((func_ov009_02224194() != 4) && (func_ov009_02224194() != 5)) {
        return 0;
    }
    return func_ov009_02225a98(arg0 + 0x34);
}

void func_ov009_02225b34(s32 arg0) {
    void func_ov009_02225ae0(s32);
    func_ov009_02225ae0(arg0 + 0x34);
}

void func_ov009_02225b44(void *arg0) {
    M2C_UNK func_020c4dd0(s32);
    func_020c4dd0(M2C_FIELD(arg0, s32 *, 0x18));
}

void func_ov009_02225b54(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_0222669c;
    extern M2C_UNK data_ov009_022265f8;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa42c(&data_ov009_022265f8, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_0222669c;
    }
}

void func_ov009_02225b7c(void) {

}

s32 func_ov009_02225b80(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void *func_ov009_02225b94(void *arg0) {
    M2C_UNK func_ov009_02224d1c();
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_ov009_02224d1c();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    return arg0;
}

void *func_ov009_02225bbc(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_ov009_02224d1c();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    func_02082040(arg0);
    return arg0;
}

s32 func_ov009_02225bec(s32 arg0) {
    M2C_UNK func_020741c4(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov009_0222497c;
    func_020741c4(arg0 + 0x34, 4, 8, &func_ov009_0222497c);
    return arg0;
}

s32 func_ov009_02225c14(s32 arg0) {
    M2C_UNK func_020741c4(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov009_0222497c;
    func_020741c4(arg0 + 0x34, 4, 8, &func_ov009_0222497c);
    func_02082040(arg0);
    return arg0;
}

void func_ov009_02225c44(void) {

}

s32 func_ov009_02225c48(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov009_02225c5c(void) {

}

s32 func_ov009_02225c60(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov009_02225c74(void) {

}

s32 func_ov009_02225c78(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov009_02225c8c(void) {

}

s32 func_ov009_02225c90(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov009_02225ca4(void) {

}

s32 func_ov009_02225ca8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov009_02225cbc(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC4) = 0;
}

void func_ov009_02225ccc(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

s32 func_ov009_02225ce0(s32 arg0, s32 arg1) {
    s32 func_ov009_02224194();
    switch (func_ov009_02224194()) {
    case 8:
    case 9:
        return 0;
    default:
        return arg1 != func_ov009_02224194();
    }
}

void func_ov009_02225d14(void) {
    M2C_UNK func_01ffaa8c();
    func_01ffaa8c();
}

void func_ov009_02225d20(void *arg0) {
    M2C_UNK func_02086680(s32);
    s32 func_ov009_022241b4();
    M2C_UNK func_ov009_022244ec(M2C_UNK);
    s32 func_ov009_02224508(M2C_UNK);
    M2C_UNK (*temp_r2)(s32, s32);
    s32 temp_r4;

    if ((func_ov009_02224194() != 8) && (func_ov009_02224194() != 9)) {
        return;
    }
    temp_r4 = func_ov009_022241b4();
    if (func_ov009_02224508(1) != 0) {
        return;
    }
    func_02086680(0x4400000A);
    func_ov009_022244ec(1);
    temp_r2 = M2C_FIELD(arg0, M2C_UNK (**)(s32, s32), 0x34);
    if (temp_r2 == NULL) {
        return;
    }
    temp_r2(temp_r4, M2C_FIELD(arg0, s32 *, 0x18));
}

void func_ov009_02225d88(s32 arg0) {
    void *func_01ffa3dc(void *);
    extern M2C_UNK data_ov009_02226874, data_ov009_02226750;
    void *temp_r0;
    temp_r0 = func_01ffa3dc(&data_ov009_02226874);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, void **, 0) = &data_ov009_02226750;
        M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    }
}

void func_ov009_02225db4(void) {
    M2C_UNK func_01ffa574();
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov009_02226874;
    if (func_01ffa770(&data_ov009_02226874) == 0) {
        return;
    }
    func_01ffa574();
}

void func_ov009_02225dd4(void *arg0) {
    s32 func_020abe90(M2C_UNK);
    M2C_UNK func_020ad348(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(arg0, u8 *, 0x34) & 1) && (func_020abe90(0) == 0)) {
        func_020ad348(2, 8, 0, arg0);
    }
    if (!(M2C_FIELD(arg0, u8 *, 0x34) & 2)) {
        return;
    }
    if (func_020abe90(1) != 0) {
        return;
    }
    func_020ad348(2, 8, 1, arg0);
}

void func_ov009_02225f44(void) {

}

void func_ov009_02225f48(void *arg0) {
    M2C_UNK func_020ad2a0(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (func_020abe90(0) == 1) {
        func_020ad2a0(2, 8, 0, arg0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
    }
    if (func_020abe90(1) != 1) {
        return;
    }
    func_020ad2a0(2, 8, 1, arg0);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 2);
}

M2C_UNK func_ov009_02225fb4(s8 arg0, u16 arg1, s32 arg2, void *arg3) {
    void *func_01ffa444(void *, void *);
    extern M2C_UNK data_ov009_0222682c, data_ov009_0222673c;
    void *temp_r0;
    if (arg2 == 0) return;
    temp_r0 = func_01ffa444(&data_ov009_0222682c, arg3);
    if (temp_r0 == NULL) return;
    M2C_FIELD(temp_r0, void **, 0) = &data_ov009_0222673c;
    M2C_FIELD(temp_r0, u8 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x35) = arg0;
    M2C_FIELD(temp_r0, u16 *, 0x36) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
    if (arg2 == 8) {
        M2C_FIELD(temp_r0, s32 *, 0x38) = 0x4400000B;
        M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x38) = 0x4400000A;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 2;
}

void func_ov009_02226034(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x34) & 1) && (func_020abe90(0) == 0)) {
        func_020ad348(2, 8, 0, arg0);
    }
    if (!(M2C_FIELD(arg0, u8 *, 0x34) & 2)) {
        return;
    }
    if (func_020abe90(1) != 0) {
        return;
    }
    func_020ad348(2, 8, 1, arg0);
}

void func_ov009_022260a0(void *arg0) {
    M2C_UNK func_ov009_02225fb4(s8, u16, s32, void *);
    void func_ov009_022261e4(M2C_UNK, u16, void *);
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r2 == 0) {
        return;
    }
    func_ov009_02225fb4(M2C_FIELD(arg0, s8 *, 0x35), M2C_FIELD(arg0, u16 *, 0x36), temp_r2, arg0);
    func_ov009_022261e4(-1, M2C_FIELD(arg0, u16 *, 0x36), arg0);
}

void func_ov009_022260d8(void) {

}

void func_ov009_022260dc(void *arg0) {
    if (func_020abe90(0) == 1) {
        func_020ad2a0(2, 8, 0, arg0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
    }
    if (func_020abe90(1) != 1) {
        return;
    }
    func_020ad2a0(2, 8, 1, arg0);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 2);
}

void func_ov009_02226148(void) {
    M2C_UNK func_020d47f0();
    func_020d47f0();
}

void func_ov009_02226154(void) {
    M2C_UNK func_020852a8();
    M2C_UNK func_020852e0();
    M2C_UNK func_020d47d0();
    s32 func_ov009_02224194();
    if (func_ov009_02224194() == 1) {
        func_020d47d0();
        func_020852a8();
        return;
    }
    func_020d47f0();
    func_020852e0();
}

void func_ov009_0222617c(s32 arg0, s32 arg1, void *arg2) {
    void *func_01ffa444(void *, void *);
    s32 func_0208206c();
    M2C_UNK func_02085c4c();
    M2C_UNK func_ov009_02223f34(s32);
    M2C_UNK func_ov009_02223f44(s32, M2C_UNK);
    s32 func_ov009_022242c8();
    M2C_UNK func_ov009_02224528(M2C_UNK);
    M2C_UNK func_ov009_0222454c();
    extern M2C_UNK data_ov009_02226784;
    if (func_ov009_02224194() != 0) {
        func_020d47d0();
        return;
    }
    func_020d47f0();
    func_ov009_02224528(1);
    if (func_ov009_022242c8() == 0) return;
    func_ov009_0222454c();
    func_ov009_02223f34(0x654);
    func_ov009_02223f44(func_0208206c(), 0x14);
    func_02085c4c();
    func_01ffa444(&data_ov009_02226784, arg2);
}

void func_ov009_022261e4(M2C_UNK arg0, u16 arg1, void *arg2) {
    s32 func_ov009_02224194(void);
    M2C_UNK func_020d47d0(void);
    void *func_01ffa444(void *, void *);
    extern M2C_UNK data_ov009_022267b4;
    if (func_ov009_02224194() == 0) {
        func_020d47d0();
        return;
    }
    func_01ffa444(&data_ov009_022267b4, arg2);
}

