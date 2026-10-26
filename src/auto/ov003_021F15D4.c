/* 32 functions from 0x021F15D4 to 0x021F25CC (ov003), found by ds-decomp. */
#include "common.h"

s32 func_ov003_021f15d4(void) {
    s32 func_ov003_021f1584();
    s32 func_ov003_021f15ac();
    u8 func_ov003_021f1bfc(void);
    s32 temp_r0;
    temp_r0 = func_ov003_021f1bfc();
    switch (temp_r0) {
    case 1: return func_ov003_021f1584();
    case 2: return func_ov003_021f15ac();
    default: return 0;
    }
}

s32 func_ov003_021f1608(void) {
    s32 func_ov003_021f1594();
    s32 func_ov003_021f15bc();
    u8 func_ov003_021f1bfc(void);
    s32 temp_r0;
    temp_r0 = func_ov003_021f1bfc();
    switch (temp_r0) {
    case 1: return func_ov003_021f1594();
    case 2: return func_ov003_021f15bc();
    default: return 0;
    }
}

void func_ov003_021f17e0(void) {
    M2C_UNK func_ov003_021f13c8();
    M2C_UNK func_01ffaa5c();
    s32 func_ov003_021f13c8();
    if (func_ov003_021f13c8() == 0) {
        return;
    }
    func_ov003_021f13c8();
    func_01ffaa5c();
}

u8 func_ov003_021f17fc(void) {
    s32 func_ov003_021f13c8();
    u8 var_r0;
    if (func_ov003_021f13c8() == 0) return 0U;
    if (M2C_FIELD(func_ov003_021f13c8(), u8 *, 0x31) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021f182c(void) {
    M2C_UNK func_020ad2a0(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    if (func_ov003_021f13c8() == 0) {
        return;
    }
    func_020ad2a0(2, 8, 2, func_ov003_021f13c8());
}

void func_ov003_021f1858(void) {
    M2C_UNK func_020ad348(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    if (func_ov003_021f13c8() == 0) {
        return;
    }
    func_020ad348(2, 8, 2, func_ov003_021f13c8());
}

void func_ov003_021f1884(s16 arg0) {
    extern u8 data_ov003_022111c0;
    M2C_FIELD(&data_ov003_022111c0, s16 *, 8) = arg0;
}

u16 func_ov003_021f1894(void) {
    extern u8 data_ov003_022111c0;
    return M2C_FIELD(&data_ov003_022111c0, u16 *, 8);
}

void func_ov003_021f18a4(void) {
    func_ov003_021f140c(3);
}

void func_ov003_021f18b4(u8 *arg0) {
    void func_020af144(u8, u8, u8, u8);
    void func_020af178(u8, u8);
    void func_020af19c(u8, u8);
    extern M2C_UNK data_ov003_0220fc78;
    u8 temp_r0;
    u8 temp_r1;
    temp_r1 = arg0[3];
    temp_r0 = arg0[0];
    if (temp_r0 & temp_r1) {
        func_020af144(arg0[1], arg0[2], arg0[4], arg0[5]);
    } else if (temp_r0 != 0) {
        func_020af178(arg0[1], arg0[2]);
    } else if (temp_r1 != 0) {
        func_020af19c(arg0[4], arg0[5]);
    }
    M2C_FIELD(&data_ov003_0220fc78, u8 **, 4) = arg0;
}

void func_ov003_021f1920(void) {
    M2C_UNK func_020af1e4();
    func_020af1e4();
}

void func_ov003_021f1a58(void) {
    M2C_UNK func_01ffa574(s32);
    extern u8 data_ov003_022111c0;
    func_01ffa574(M2C_FIELD(&data_ov003_022111c0, s32 *, 0x10));
}

void func_ov003_021f1a70(void) {
    extern M2C_UNK data_ov003_0220fc88;
    u8 i;
    u8 j;
    i = 0;
    do {
        j = 0;
        do {
            M2C_FIELD((s32)&data_ov003_0220fc88 + i * 16, s32 *, j * 4) = 0;
            j++;
        } while ((u32)j < 4);
        i++;
    } while ((u32)i < 2);
}

void func_ov003_021f1ab8(s32 arg0) {
    M2C_UNK func_020822b8();
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_0220fc78;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_020822b8();
    gCur3DSpriteEngine = temp_r4;
    M2C_FIELD(&data_ov003_0220fc78, s32 *, 8) = arg0;
}

void func_ov003_021f1af8(s32 arg0) {
    M2C_UNK func_020822b8();
    extern s32 data_027e00c4;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_0220fc78;
    s32 temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020822b8();
    gCur3DSpriteEngine = temp_r4;
    M2C_FIELD(&data_ov003_0220fc78, s32 *, 12) = arg0;
}

void func_ov003_021f1b38(s32 arg0, s32 arg1) {
    M2C_UNK func_02082340();
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_0220fc88;
    s32 temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_02082340();
    gCur3DSpriteEngine = temp_r4;
    M2C_FIELD(&data_ov003_0220fc88, s32 *, arg0 * 4) = arg1;
}

void func_ov003_021f1b7c(s32 arg0, s32 arg1) {
    M2C_UNK func_02082340();
    extern s32 data_027e00c4;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_0220fc98;
    s32 temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_02082340();
    gCur3DSpriteEngine = temp_r4;
    M2C_FIELD(&data_ov003_0220fc98, s32 *, arg0 * 4) = arg1;
}

void func_ov003_021f1bc0(void) {
    extern u8 data_ov003_022111c0;
    data_ov003_022111c0 = 0;
}

void func_ov003_021f1bd4(void) {
    extern u8 data_ov003_022111c0;
    data_ov003_022111c0 = 1;
}

void func_ov003_021f1be8(void) {
    extern u8 data_ov003_022111c0;
    data_ov003_022111c0 = 2;
}

u8 func_ov003_021f1bfc(void) {
    extern u8 data_ov003_022111c0;
    return data_ov003_022111c0;
}

void func_ov003_021f242c(u16 *arg0) {
    u8 i, j;
    u16 a, b;
    i = 0;
    do {
        j = 0;
        do {
            b = arg0[j + 1];
            a = arg0[j];
            if ((a > b && a != 0xFFFF && b != 0xFFFF) || (a == 0xFFFF && b != 0xFFFF)) {
                arg0[j] = b;
                arg0[j + 1] = a;
            }
            j++;
        } while ((u32)j < 4);
        i++;
    } while ((u32)i < 4);
}

void func_ov003_021f24ac(void *arg0, void *arg1) {
    void func_02007e20(void *, void *, u32);
    extern M2C_UNK data_ov003_022111de;
    extern M2C_UNK data_ov003_022111d4;
    func_02007e20(arg0, &data_ov003_022111de, 10);
    func_02007e20(arg1, &data_ov003_022111d4, 10);
    func_ov003_021f242c((u16 *)&data_ov003_022111de);
    func_ov003_021f242c((u16 *)&data_ov003_022111d4);
}

void func_ov003_021f24ec(void *arg0, void *arg1) {
    void func_02007e20(void *, void *, u32);
    extern M2C_UNK data_ov003_022111de;
    extern M2C_UNK data_ov003_022111d4;
    func_02007e20(&data_ov003_022111de, arg0, 10);
    func_02007e20(&data_ov003_022111d4, arg1, 10);
}

M2C_UNK func_ov003_021f2524(M2C_UNK *arg0) {
    u8 count, i;
    count = 0;
    i = 0;
    do {
        if (((u16 *)arg0)[i] != 0xFFFF) count++;
        i++;
    } while ((u32)i < 5);
    return count;
}

void func_ov003_021f2560(void) {
    M2C_UNK func_ov003_021f2524(M2C_UNK *);
    extern M2C_UNK data_ov003_022111de;
    func_ov003_021f2524(&data_ov003_022111de);
}

void func_ov003_021f2574(void) {
    M2C_UNK func_ov003_021f2524(M2C_UNK *);
    extern M2C_UNK data_ov003_022111d4;
    func_ov003_021f2524(&data_ov003_022111d4);
}

void func_ov003_021f2588(u32 arg0) {
    extern M2C_UNK data_ov003_022111d4;
    u8 i;
    u16 value = 0xFFFF;
    i = 0;
    do {
        if (arg0 == M2C_FIELD(&data_ov003_022111d4, u16 *, i * 2)) {
            M2C_FIELD(&data_ov003_022111d4, u16 *, i * 2) = value;
        }
        i++;
    } while ((u32)i < 5);
    func_ov003_021f242c((u16 *)&data_ov003_022111d4);
}

