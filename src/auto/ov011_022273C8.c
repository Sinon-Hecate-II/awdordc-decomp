/* 6 functions from 0x022273C8 to 0x02227F08 (ov011), found by ds-decomp. */
#include "common.h"

#pragma opt_instruction_scheduling off
void func_ov011_022273c8(void *arg0) {
    M2C_UNK AddSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    u32 func_0209b5e4(s32, M2C_UNK *);
    M2C_UNK func_0209b67c(u16, s32, u16, u16, s32);
    extern M2C_UNK data_02101f78;
    extern u16 **g3DSpriteEngineSub;
    extern u16 **g3DSpriteEngineMain;
    extern u16 **data_027e01d8;
    extern M2C_UNK data_ov011_02228c38;
    extern M2C_UNK data_ov011_02228c50;
    extern M2C_UNK data_ov011_02228c88;
    extern M2C_UNK data_ov011_02228ca4;
    u16 *volatile sp90;
    u16 *volatile sp8C;
    u16 *volatile sp88;
    u16 *volatile sp84;
    u16 *volatile sp80;
    u16 *volatile sp7C;
    u16 *volatile sp78;
    u16 *volatile sp74;
    u16 *volatile sp70;
    u16 *volatile sp6C;
    u16 *volatile sp68;
    u16 *volatile sp64;
    u16 *volatile sp60;
    u16 *volatile sp5C;
    u16 *volatile sp58;
    u16 *volatile sp54;
    u16 *volatile sp50;
    u16 *volatile sp4C;
    u16 *volatile sp48;
    u16 *volatile sp44;
    u16 *volatile sp40;
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
    u16 **spC;
    u16 **sp8;
    u32 sp4;
    s32 i;
    u16 **engine;
    u16 temp_r11;
    u16 temp_r4;
    u16 temp_r5;
    u16 temp_r6;
    u32 temp_r7;
    u32 temp_r8;
    u32 temp_r9;
    u16 temp_r1;
    u16 temp_r1_16;
    u16 temp_r2;
    u8 temp_r0_7;
    u8 temp_r0_18;
    u8 temp_r0_20;

    if (((u32) M2C_FIELD(arg0, u8 *, 0x38) <= 0x1EU) && (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F) != 0)) {
        spC = data_027e01d8;
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                engine = g3DSpriteEngineMain;
            } else {
                engine = g3DSpriteEngineSub;
            }
            data_027e01d8 = engine;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x50) = EaseInterpolate(0, -0x10, 0, M2C_FIELD(arg0, u8 *, 0x38), 0x1E);
        }
        data_027e01d8 = spC;
        M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) + 1);
    }
    sp8 = data_027e01d8;
    data_027e01d8 = g3DSpriteEngineMain;
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) >= 0x29CCU) {
        sp90 = *g3DSpriteEngineMain;
        *sp90 = (u16) (*sp90 & ~0x10);
        sp8C = *data_027e01d8;
        *sp8C = (u16) (*sp8C & ~0x20);
        sp88 = *data_027e01d8;
        *sp88 = (u16) (*sp88 & ~0x40);
        sp84 = *data_027e01d8;
        *sp84 = (u16) (*sp84 | 0x80);
        sp80 = *data_027e01d8;
        *sp80 = (u16) (*sp80 | 0x100);
        temp_r11 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2000, &data_ov011_02228c38);
        temp_r4 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800, &data_ov011_02228c50);
        temp_r5 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x3000, &data_ov011_02228c88);
        temp_r6 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x3800, &data_ov011_02228ca4);
        temp_r7 = (u32) temp_r11 >> 1;
        func_0209b67c((u16) ((0x80 - temp_r7) & 0x1FF), 0x440, temp_r11, (u16) ((0x3FF & (0x100 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        temp_r8 = (u32) temp_r4 >> 1;
        func_0209b67c((u16) ((0x80 - temp_r8) & 0x1FF), 0x480, temp_r4, (u16) ((0x3FF & (0x140 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        sp4 = (u32) temp_r5 >> 1;
        func_0209b67c((u16) ((0x80 - sp4) & 0x1FF), 0x48E, temp_r5, (u16) ((0x3FF & (0x180 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        temp_r9 = (u32) temp_r6 >> 1;
        func_0209b67c((u16) ((0x80 - temp_r9) & 0x1FF), 0x49C, temp_r6, (u16) ((0x3FF & (0x1C0 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        func_0209b67c((u16) ((0x82 - temp_r7) & 0x1FF), 0x442, temp_r11, (u16) ((0x3FF & (0x100 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        func_0209b67c((u16) ((0x82 - temp_r8) & 0x1FF), 0x482, temp_r4, (u16) ((0x3FF & (0x140 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        func_0209b67c((u16) ((0x82 - sp4) & 0x1FF), 0x490, temp_r5, (u16) ((0x3FF & (0x180 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        func_0209b67c((u16) ((0x82 - temp_r9) & 0x1FF), 0x49E, temp_r6, (u16) ((0x3FF & (0x1C0 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        temp_r1 = M2C_FIELD(arg0, u16 *, 0x3A);
        if ((u32) temp_r1 <= 0x2A08U) {
            temp_r0_7 = EaseInterpolate(4, 0, 0x10, temp_r1 - 0x29CC, 0x3C);
            M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_7;
            sp7C = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
            *sp7C = (u16) ((*sp7C & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_7;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_7);
        }
    }
    data_027e01d8 = g3DSpriteEngineSub;
    if (M2C_FIELD(arg0, u16 *, 0x3A) == 0x2918) {
        sp78 = (u16 *) ((u8 *) *g3DSpriteEngineSub + 0x12);
        *sp78 = (u16) (*sp78 & ~1);
        sp74 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp74 = (u16) (*sp74 & ~2);
        sp70 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp70 = (u16) (*sp70 | 4);
        sp6C = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp6C = (u16) (*sp6C & ~8);
        sp68 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp68 = (u16) (*sp68 & ~0x10);
        sp64 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp64 = (u16) (*sp64 | 0x100);
        sp60 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp60 = (u16) (*sp60 | 0x200);
        sp5C = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp5C = (u16) (*sp5C & ~0x400);
        sp58 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp58 = (u16) (*sp58 | 0x800);
        sp54 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp54 = (u16) (*sp54 | 0x1000);
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3C) = 0;
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x44) = 0;
    }
    temp_r2 = M2C_FIELD(arg0, u16 *, 0x3A);
    if (((u32) temp_r2 >= 0x2918U) && ((u32) temp_r2 <= 0x2990U)) {
        temp_r0_18 = EaseInterpolate(4, 0, 0x10, temp_r2 - 0x2918, 0x78);
        M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_18;
        sp50 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp50 = (u16) ((*sp50 & ~0xC0) | 0x40);
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_18;
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_18);
    }
    if (M2C_FIELD(arg0, u16 *, 0x3A) == 0x29CC) {
        sp4C = *data_027e01d8;
        *sp4C = (u16) (*sp4C | 0x10);
        sp48 = *data_027e01d8;
        *sp48 = (u16) (*sp48 & ~0x20);
        sp44 = *data_027e01d8;
        *sp44 = (u16) (*sp44 | 0x40);
        sp40 = *data_027e01d8;
        *sp40 = (u16) (*sp40 & ~0x80);
        sp3C = *data_027e01d8;
        *sp3C = (u16) (*sp3C | 0x100);
        sp38 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp38 = (u16) (*sp38 & ~1);
        sp34 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp34 = (u16) (*sp34 & ~2);
        sp30 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp30 = (u16) (*sp30 & ~4);
        sp2C = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp2C = (u16) (*sp2C & ~8);
        sp28 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp28 = (u16) (*sp28 | 0x10);
        sp24 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp24 = (u16) (*sp24 | 0x100);
        sp20 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp20 = (u16) (*sp20 | 0x200);
        sp1C = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp1C = (u16) (*sp1C | 0x400);
        sp18 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp18 = (u16) (*sp18 | 0x800);
        sp14 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
        *sp14 = (u16) (*sp14 & ~0x1000);
    }
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) > 0x29CCU) {
        AddSprite(0, 0x50, 0, &data_02101f78, 0);
        temp_r1_16 = M2C_FIELD(arg0, u16 *, 0x3A);
        if ((u32) temp_r1_16 < 0x2A44U) {
            temp_r0_20 = EaseInterpolate(4, 0, 0x10, temp_r1_16 - 0x29CC, 0x78);
            M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_20;
            sp10 = (u16 *) ((u8 *) *data_027e01d8 + 0x12);
            *sp10 = (u16) ((*sp10 & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_20;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_20);
        }
    }
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 4);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    data_027e01d8 = sp8;
    M2C_FIELD(arg0, u16 *, 0x3A) = (u16) (M2C_FIELD(arg0, u16 *, 0x3A) + 1);
}
#pragma opt_instruction_scheduling reset
void func_ov011_02227e88(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) <= 0x2A80U) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov011_02227ea4(M2C_UNK arg0) {
    extern M2C_UNK data_ov011_02228b1c;
    extern M2C_UNK data_ov011_02228a48;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov011_02228a48, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov011_02228b1c;
    }
}

void func_ov011_02227ecc(M2C_UNK arg0) {
    s32 func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_ov011_02225684();
    extern M2C_UNK data_ov011_02228a78;
    if (func_01ffa42c(&data_ov011_02228a78, arg0) == 0) {
        return;
    }
    func_ov011_02225684();
}

void func_ov011_02227ef0(void) {

}

s32 func_ov011_02227ef4(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

