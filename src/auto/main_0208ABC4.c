/* 24 functions from 0x0208ABC4 to 0x0208B884 (main), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 unk_0x00[0x58];
    s32 unk_0x58_0 : 6;
    s32 unk_0x58_6 : 2;
    s32 unk_0x58_8 : 24;
} Unk0208ABC4;

u8 func_0208b5a8(void);

/* Updates the linked left/right objects' orientation fields when the entity is in state 3. */
void func_0208ad48(void *entity) {
    unsigned flagRight;
    unsigned flagLeft;
    void *objLeft;
    void *objRight;

    objLeft = M2C_FIELD(entity, void **, 0x5C);
    objRight = M2C_FIELD(entity, void **, 0x60);
    if ((u8) ((u32) (M2C_FIELD((int)entity, s32 *, 0x58) << 0x1D) >> 0x1D) != 3) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(objLeft, void **, 0x64), s8 *, 0xC) == 1) {
        flagLeft = 1;
    } else {
        flagLeft = 0;
    }
    if (flagLeft & 0xFF) {
        M2C_FIELD(entity, s32 *, 0x58) = (s32) (M2C_FIELD(entity, s32 *, 0x58) & ~0xC0);
    }
    if (M2C_FIELD(M2C_FIELD(objRight, void **, 0x64), s8 *, 0xC) == 1) {
        flagRight = 1;
    } else {
        flagRight = 0;
    }
    if (flagRight & 0xFF) {
        M2C_FIELD(entity, s32 *, 0x58) = (s32) ((M2C_FIELD(entity, s32 *, 0x58) & ~0xC0) | 0x40);
    }
    if (((s32) (M2C_FIELD(entity, s32 *, 0x58) << 0x18) >> 0x1E) == 0) {
        M2C_FIELD(objLeft, s32 *, 0x40) = (s32) ((M2C_FIELD(objLeft, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(objLeft, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(objRight, s32 *, 0x40) = (s32) ((M2C_FIELD(objRight, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(objRight, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    }
    if (((s32) (M2C_FIELD(entity, s32 *, 0x58) << 0x18) >> 0x1E) != 1) {
        return;
    }
    M2C_FIELD(objLeft, s32 *, 0x40) = (s32) ((M2C_FIELD(objLeft, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(objLeft, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    M2C_FIELD(objRight, s32 *, 0x40) = (s32) ((M2C_FIELD(objRight, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(objRight, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
}

u8 func_0208ae88(Unk0208ABC4 *arg0, s32 arg1) {
    s32 var_r3;
    var_r3 = arg0->unk_0x58_6 != arg1;
    arg0->unk_0x58_6 = arg1;
    return var_r3;
}

void func_0208aebc(void *arg0) {
    M2C_UNK func_02088da8();
    M2C_UNK func_0208a6b0(void *);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((M2C_FIELD(arg0, s32 *, 0x58) & ~0x38) | 8);
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) ((M2C_FIELD(arg0, u8 *, 0x48) & ~0x30) | 0x10);
    M2C_FIELD(arg0, s8 *, 0x4B) = 0;
    M2C_FIELD(arg0, s8 *, 0x4A) = 6;
    if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        func_02088da8();
    }
    if (M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        func_02088da8();
    }
    func_0208a6b0(arg0);
}

void func_0208af20(void *arg0) {
    M2C_UNK func_0208a714(void *);
    s32 temp_r1;
    u32 temp_r2;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x58);
    temp_r2 = (u32) (temp_r1 << 0x1A) >> 0x1D;
    if (temp_r2 == 0) {
        func_01ffa574(arg0, temp_r1, temp_r2);
    } else {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((temp_r1 & ~0x38) | 0x18);
        M2C_FIELD(arg0, u8 *, 0x48) = (u8) ((M2C_FIELD(arg0, u8 *, 0x48) & ~0x30) | 0x20);
        M2C_FIELD(arg0, s8 *, 0x4B) = 0;
        M2C_FIELD(arg0, s8 *, 0x4A) = 8;
        if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
            func_02088da8();
        }
        if (M2C_FIELD(arg0, s32 *, 0x60) != 0) {
            func_02088da8();
        }
    }
    func_0208a714(arg0);
}

void func_0208b4e4(void) {
    M2C_UNK func_0208a750();
    func_0208a750();
}

void func_0208b4f0(void) {
    M2C_UNK func_0208ab78();
    func_0208ab78();
}

void func_0208b4fc(void) {
    M2C_UNK func_02089cb8();
    func_02089cb8();
}

void func_0208b508(void) {
    M2C_UNK func_02089d30();
    func_02089d30();
}

void func_0208b514(void) {
    M2C_UNK func_0208abc4();
    func_0208abc4();
}

void func_0208b520(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_020898d0(void);
    extern M2C_UNK data_021027f0;
    s32 temp_r4;
    void *var_r0;
    temp_r4 = func_0208b5a8();
    var_r0 = func_01ffa3dc(&data_021027f0, arg0);
    if (var_r0 != 0) var_r0 = func_020898d0();
    M2C_FIELD(var_r0, s32 *, 0x58) = (M2C_FIELD(var_r0, s32 *, 0x58) & ~0x2000) | ((u32)(temp_r4 << 31) >> 18);
}

void func_0208b564(s32 arg0) {
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    void *func_020898d0(void);
    extern M2C_UNK data_021027f0;
    s32 temp_r4;
    void *var_r0;
    temp_r4 = func_0208b5a8();
    var_r0 = func_01ffa444(&data_021027f0, arg0);
    if (var_r0 != 0) var_r0 = func_020898d0();
    M2C_FIELD(var_r0, s32 *, 0x58) = (M2C_FIELD(var_r0, s32 *, 0x58) & ~0x2000) | ((u32)(temp_r4 << 31) >> 18);
}

u8 func_0208b5a8(void) {
    u8 var_r0;
    if (func_0208b5ec() != 0) var_r0 = 1;
    else var_r0 = 0;
    return var_r0;
}

s32 func_0208b5c4(void) {
    s32 func_020890d4(void);
    if ((func_0208b5ec() != 0) && (func_020890d4() != 0)) return 1;
    return 0;
}

s32 func_0208b5ec(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_021027f0;
    return func_01ffa770(&data_021027f0);
}

void func_0208b600(void *arg0) {
    M2C_UNK func_0208b884(s32);
    func_0208b884(M2C_FIELD(arg0, s32 *, 0x34));
}

void *func_0208b610(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021026d8;
    void *p = func_01ffa3dc(&data_021026d8, 1);
    M2C_FIELD(p, s32 *, 0x34) = arg0;
    return p;
}

void *func_0208b630(void *arg0) {
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_021025e8;
    func_02089108();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021025e8;
    M2C_FIELD(arg0, s16 *, 0x58) = 0;
    M2C_FIELD(arg0, s16 *, 0x5A) = 0;
    M2C_FIELD(arg0, s8 *, 0x5C) = 0;
    M2C_FIELD(arg0, s8 *, 0x5D) = 0x3C;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0xC0;
    func_02088e84(arg0, 0, 0xA0, 0, 0xC0);
    return arg0;
}

void func_0208b758(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_02086680(M2C_UNK);
    M2C_UNK func_0208b698(M2C_UNK, s32);
    func_0208b698(arg0, func_02086680(arg1));
}

/* Refresh the display banks selected by the entity's mode, then allocate and link a handle for it. */
void func_0208b778(void *entity) {
    extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;
    extern u8 data_0211e1ec[], data_0211e12c[];
    void *savedBank;
    void *bank;
    u32 mode;
    s32 i;

    savedBank = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) {
            bank = data_027e00c8;
        } else {
            bank = data_027e00c4;
        }
        gCur3DSpriteEngine = bank;
        mode = (u32)(M2C_FIELD(entity, u8 *, 0x48) << 28) >> 29;
        if ((mode != 0 || bank == data_027e00c8) &&
            (mode != 1 || bank == data_027e00c4) &&
            (mode != 3 || bank == savedBank)) {
            func_0207c780(data_0211e1ec, M2C_FIELD(bank, u8 **, 0x1C) + (M2C_FIELD(entity, u16 *, 0x3E) << 5));
            func_01ff9e44(data_0211e12c, ((u16)((u32)(M2C_FIELD(entity, u32 *, 0x40) << 6) >> 24) + 16) << 5, 32);
            func_02091d4c(18);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
    M2C_FIELD(entity, void **, 0x60) = func_0208b610((s32)entity);
}

void func_0208b868(void *arg0) {
    M2C_UNK func_01ffa574(s32);
    func_01ffa574(M2C_FIELD(arg0, s32 *, 0x60));
}

void func_0208b878(void) {
    M2C_UNK func_02088c78();
    func_02088c78();
}

