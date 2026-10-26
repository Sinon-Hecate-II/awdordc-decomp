/* 17 functions from 0x01FF8F90 to 0x01FF9ED0 (itcm), found by ds-decomp. */
#include "common.h"

void func_01ff90e4(s32 arg0, s32 arg1, u32 arg2, u16 *arg3)
{
    extern u16 **gCur3DSpriteEngine;
    u16 *entry;
    u16 *dst;
    u16 count;
    u32 high;
    u32 low;
    u32 value;
    u32 shift;

    count = *arg3++;
    entry = *gCur3DSpriteEngine;

    dst = (u16 *)((u8 *)M2C_FIELD(entry, u32 *, 0x38) +
                  (M2C_FIELD(entry, u8 *, 0x4A) << 3));

    if (count == 0) {
        return;
    }

    high = arg2 & 0xFC00;
    low = arg2 & 0x3FF;

    if (M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4A) >= 0x80) {
        return;
    }

    do {
        count--;

        entry = *gCur3DSpriteEngine;
        value = arg3[0];

        dst[0] = ((value | arg1) & 0xFF00) +
                 ((M2C_FIELD(entry, s16 *, 0x3E) +
                   value + arg1) & 0xFF);

        value = arg3[1];
        entry = *gCur3DSpriteEngine;

        dst[1] = ((value | arg0) & 0xFE00) +
                 ((M2C_FIELD(entry, s16 *, 0x3C) +
                   value + arg0) & 0x1FF);

        value = arg3[2];
        entry = *gCur3DSpriteEngine;

        shift = (*(u16 *)M2C_FIELD(entry, u32 *, 0x00) >> 13) & 3;

        dst[2] = high +
                 ((value & 0xFC00) +
                 ((low + ((value & 0x3FF) >> shift)) & 0x3FF));

        arg3 += 3;
        dst = (u16 *)((u8 *)dst + 8);

        entry = *gCur3DSpriteEngine;
        M2C_FIELD(entry, u8 *, 0x4A)++;

    } while (count != 0);
}

void func_01ff9ab4(void) {
    extern u16 *data_027e00bc;
    func_0200245c(((u32)(M2C_FIELD(data_027e00bc, u16 *, 4) << 31) >> 31) != 0);
    func_02002428(((u32)(M2C_FIELD(data_027e00bc, u16 *, 4) << 30) >> 31) != 0);
    if (((u32)(M2C_FIELD(data_027e00bc, u16 *, 4) << 29) >> 31) != 0) {
        *(volatile u16 *)0x04000004 |= 0x20;
    } else {
        *(volatile u16 *)0x04000004 &= ~0x20;
    }
}

void func_01ff9b38(void) {
    M2C_UNK func_01ff9690();
    M2C_UNK func_0207fafc();
    func_01ff9ab4();
    func_01ff91d8();
    func_01ff9690();
    func_0207fafc();
}

u8 func_01ff9b70(u8 arg0, u32 arg1) {
    u8 result;
    switch (arg0) {
    case 0: return 1;
    case 1:
    case 3:
        if (arg1 <= 2) result = 1; else result = 0;
        return result;
    case 2:
    case 4:
    case 5:
        if (arg1 <= 1) result = 1; else result = 0;
        return result;
    default: return 0;
    }
}

u8 func_01ff9bcc(s32 arg0, s32 arg1) {
    u8 var_r0;
    u8 var_r0_2;
    u8 var_r0_3;

    switch (arg0) {                                 /* irregular */
    case 1:
        if (arg1 == 3) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    case 2:
        if ((u32) (u8) (arg1 + 0xFE) <= 1U) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        return var_r0_2;
    case 4:
        if (arg1 == 2) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        return var_r0_3;
    default:
        return 0U;
    }
}

s32 func_01ff9c34(u8 arg0, s32 arg1) {
    extern u16 **gCur3DSpriteEngine;
    extern s32 data_01ff9b50[];
    extern s32 data_01ff9b60[];
    if (func_01ff9b70(arg0, arg1) != 0) {
        return data_01ff9b50[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30];
    }
    if (func_01ff9bcc(arg0, arg1) != 0) {
        return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30];
    }
    return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30] * 2;
}

void func_01ff9ce8(u8 arg0) {
    s32 func_01ff9c34(u8, s32);
    M2C_UNK func_02007e98(M2C_UNK, s32, s32);
    extern u16 **gCur3DSpriteEngine;
    func_02007e98(0, M2C_FIELD(&gCur3DSpriteEngine[arg0], s32 *, 0x20), func_01ff9c34((u8) ((u32) (**gCur3DSpriteEngine << 0x1D) >> 0x1D), arg0));
}

void func_01ff9d38(s32 arg0) {
    extern u16 *data_027e00bc;
    extern s32 data_027e00c8;
    func_02007e98(0, M2C_FIELD((data_027e00c8 + (arg0 * 4)), s32 *, 0x20), func_01ff9c34((u8) ((u32) (*data_027e00bc << 0x1D) >> 0x1D), arg0));
}

void func_01ff9d88(s32 arg0) {
    extern u16 *data_027e00c0;
    extern s32 data_027e00c4;
    func_02007e98(0, M2C_FIELD((data_027e00c4 + (arg0 * 4)), s32 *, 0x20), func_01ff9c34((u8) ((u32) (*data_027e00c0 << 0x1D) >> 0x1D), arg0));
}

void func_01ff9dd8(u8 arg0) {
    M2C_UNK func_02007e98(M2C_UNK, s32, s32);
    extern u16 **gCur3DSpriteEngine;
    u16 **entry = &gCur3DSpriteEngine[arg0];
    s32 dest = M2C_FIELD(entry, s32 *, 0xC);
    func_02007e98(0, dest, 0x40);
}

void func_01ff9e00(void) {
    extern u16 **gCur3DSpriteEngine;
    s32 i;
    for (i = 0; i < 4; i++) {
        func_01ff9dd8(i);
        func_01ff9ce8(i);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1 << i;
    }
}

void func_01ff9e44(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_02007ef4(M2C_UNK, s32, M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    func_02007ef4(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, arg2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
}

void func_01ff9e78(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_02008048(M2C_UNK, s32, M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    func_02008048(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, arg2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
}

void func_01ff9eac(M2C_UNK arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    M2C_UNK func_02007ef4(M2C_UNK, s32, M2C_UNK);
    s32 var_r1;

    if (arg1 == 0) {
        var_r1 = 0x05000000;
    } else {
        var_r1 = 0x05000400;
    }
    func_02007ef4(arg0, var_r1 + arg2, arg3);
}

