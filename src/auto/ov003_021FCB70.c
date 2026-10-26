/* 24 functions from 0x021FCB70 to 0x021FD850 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021fcd10(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fcd24(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fcd30(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021fd094(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd0a0(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

/* Refreshes an entity's display data: reinitializes its two display objects and then releases the pending handles stored in its part list (plus an extra handle when the low state nibble equals 2). */
void func_ov003_021fd0b4(void *entity) {
    M2C_UNK func_02088ff4(s32);
    s16 func_020a8ff4(void *);
    s32 func_ov003_021f15d4();
    s16 func_ov003_021f1608();
    s16 displayValue;
    s32 flag;
    void *first;
    void *second;
    void *parts;

    displayValue = func_ov003_021f1608();
    first = M2C_FIELD(entity, void **, 0x58);
    M2C_FIELD(first, s16 *, 0xE) = func_020a8ff4(first);
    M2C_FIELD(first, s16 *, 0x10) = displayValue;
    M2C_FIELD(first, s16 *, 0xC) = 12;
    M2C_FIELD(first, u16 *, 2) = M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(entity, void **, 0x64);
    M2C_FIELD(second, s16 *, 0xE) = func_020a8ff4(second);
    M2C_FIELD(second, s16 *, 0x10) = -32;
    M2C_FIELD(second, s16 *, 0xC) = 12;
    M2C_FIELD(second, u16 *, 2) = M2C_FIELD(second, u16 *, 4);
    if (!func_ov003_021f15d4()) {
        return;
    }
    parts = M2C_FIELD(entity, void **, 0x68);
    func_02088ff4(M2C_FIELD(parts, s32 *, 0));
    func_02088ff4(M2C_FIELD(parts, s32 *, 4));
    func_02088ff4(M2C_FIELD(parts, s32 *, 8));
    func_02088ff4(M2C_FIELD(parts, s32 *, 12));
    func_02088ff4(M2C_FIELD(parts, s32 *, 16));
    func_02088ff4(M2C_FIELD(parts, s32 *, 20));
    if (((u32)(M2C_FIELD(entity, u8 *, 0x3b) << 28) >> 28) == 2) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag & 255) {
        func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 32));
    }
    func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x6c), s32 *, 4));
}

void func_ov003_021fd18c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021fd1a0(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x58);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021fd1cc(void) {
    M2C_UNK func_ov003_021f66d4();
    func_ov003_021f66d4();
}

void func_ov003_021fd1d8(void) {
    M2C_UNK func_ov003_021f6724();
    func_ov003_021f6724();
}

void func_ov003_021fd1e4(void) {
    M2C_UNK func_ov003_021f8c20();
    func_ov003_021f8c20();
}

void func_ov003_021fd1f0(void *arg0) {
    s32 func_020846a4();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f152c(M2C_UNK);
    s32 func_ov003_021f153c();
    M2C_UNK func_ov003_022006dc(M2C_UNK);
    M2C_UNK func_ov006_02217178(void *);
    s32 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        return;
    }
    if (func_020846a4() == 0) {
        return;
    }
    if (func_ov003_021f153c() != 0) {
        return;
    }
    func_ov003_021f152c(1);
    func_ov003_021f140c(1);
    func_ov003_022006dc(1);
    func_ov006_02217178(arg0);
}

u8 func_ov003_021fd250(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_021fd270(void *arg0) {
    s32 a, b, c, result;
    u32 value;
    s32 either;
    result = 1;
    either = 1;
    value = (u32)(M2C_FIELD(arg0, u8 *, 0x3B) << 28) >> 28;
    if (value == 6) a = 1; else a = 0;
    if (!(a & 0xFF)) {
        if (value == 7) b = 1; else b = 0;
        if (!(b & 0xFF)) either = 0;
    }
    if (either == 0) {
        if (value == 8) c = 1; else c = 0;
        if (!(c & 0xFF)) result = 0;
    }
    return result;
}

/* Clears the low state bits of an entity, switches it to state 4 handling, and updates its display lists/palette. */
void func_ov003_021fd2d0(void *entity) {
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_020893a8(s32, s32, M2C_UNK, s32);
    M2C_UNK func_0208b758(s32, s32);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK func_ov003_021fc98c(void *, M2C_UNK);
    M2C_UNK func_ov006_02217840(void *);
    M2C_UNK func_ov006_02217c74(void *);
    M2C_UNK func_ov006_02217cb8(void *);
    extern void *gCur3DSpriteEngine;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;

    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 6) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        func_ov006_02217840(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 8) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        func_ov006_02217c74(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 7) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        func_ov006_02217cb8(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (!(var_r0_4 & 0xFF)) {
        return;
    }
    M2C_FIELD(entity, u8 *, 0x3E) = (u8) (M2C_FIELD(entity, u8 *, 0x3E) & ~7);
    func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 3, 7);
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3E) << 0x18) >> 0x1F) != 0) {
        func_ov003_021fc98c(entity, 4);
    }
    func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x10, 3, 6);
    func_0208b758(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 4), 0x4700001D);
    func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 8));
    func_020893a8(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 0), 0x8B80, 1, func_020ae22c(0x11));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_ov003_021fd430(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fd444(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd450(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd45c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fd470(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd47c(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

