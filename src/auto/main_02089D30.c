/* 5 functions from 0x02089D30 to 0x0208ABC4 (main), found by ds-decomp. */
#include "common.h"

void func_02089d30(void *arg0) { }

u32 func_0208a6b0(void *arg0) {
    u32 func_020846a4(void);
    u32 func_0208fe30(M2C_UNK);
    u32 func_0208ff4c(M2C_UNK);
    M2C_UNK func_0208ffe4(M2C_UNK, M2C_UNK, s32);
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_3;

    if (func_0208ff4c(4) == 0) {
        func_0208fe30(0x125);
    }
    temp_r0_3 = (u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x1D) >> 0x1D;
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    temp_r0_2 = func_020846a4();
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    func_0208ffe4(0, -1, 0x10013);
    temp_r0 = M2C_FIELD(arg0, u32 *, 0x58) | 0x4000;
    M2C_FIELD(arg0, u32 *, 0x58) = temp_r0;
    return temp_r0;
}

u32 func_0208a714(void *arg0) {
    u32 func_0208fe30(M2C_UNK);
    u32 func_0208ff4c(M2C_UNK);
    M2C_UNK func_02090034(M2C_UNK, M2C_UNK);
    u32 temp_r0;
    u32 temp_r0_2;

    temp_r0_2 = (u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x11) >> 0x1F;
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    func_02090034(0, 0);
    temp_r0 = func_0208ff4c(4);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    return func_0208fe30(0x124);
}

void func_0208a750(void *arg0) {
    s32 func_020abe90(u32);
    s32 func_020ad3f0();
    M2C_UNK func_020b269c();
    M2C_UNK func_020d4704();
    extern u16 **data_027e01d8;
    u16 *sp60;
    u16 *sp5C;
    u16 *sp58;
    u16 *sp54;
    u16 *sp50;
    u16 *sp4C;
    u16 *sp48;
    u16 *sp44;
    u16 *sp40;
    u16 *sp3C;
    u16 *sp38;
    u16 *sp34;
    u16 *sp30;
    u16 *sp2C;
    u16 *sp28;
    u16 *sp24;
    u16 *sp20;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 *sp8;
    u16 *sp4;
    u16 *sp0;
    s32 temp_r0_3;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r1;
    u16 *temp_r1_10;
    u16 *temp_r1_11;
    u16 *temp_r1_12;
    u16 *temp_r1_13;
    u16 *temp_r1_14;
    u16 *temp_r1_15;
    u16 *temp_r1_16;
    u16 *temp_r1_17;
    u16 *temp_r1_18;
    u16 *temp_r1_19;
    u16 *temp_r1_20;
    u16 *temp_r1_21;
    u16 *temp_r1_22;
    u16 *temp_r1_23;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r1_8;
    u16 *temp_r1_9;

    if ((func_020ad3f0() != 0) || (func_020abe90((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1C) >> 0x1D) == 1)) {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) & ~0x400);
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x13) >> 0x1F) & 0xFF) {
        func_020d4704();
        func_020b269c();
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x15) >> 0x1F) & 0xFF) {
        func_02082994();
        temp_r1 = *data_027e01d8;
        sp60 = temp_r1 + 0xE;
        M2C_FIELD(temp_r1, s16 *, 0xE) = (s16) (*sp60 & ~0x20);
        temp_r1_2 = *data_027e01d8;
        sp5C = temp_r1_2 + 0x10;
        M2C_FIELD(temp_r1_2, s16 *, 0x10) = (s16) (*sp5C | 0x20);
        temp_r1_3 = *data_027e01d8;
        sp58 = temp_r1_3;
        *temp_r1_3 = *sp58 | 0x200;
        temp_r1_4 = *data_027e01d8;
        sp54 = temp_r1_4;
        *temp_r1_4 = *sp54 & ~0x400;
        temp_r1_5 = *data_027e01d8;
        sp50 = temp_r1_5;
        *temp_r1_5 = *sp50 & ~0x800;
        temp_r1_6 = *data_027e01d8;
        sp4C = temp_r1_6 + 0xE;
        M2C_FIELD(temp_r1_6, s16 *, 0xE) = (s16) ((*sp4C & ~1) | 1);
        temp_r1_7 = *data_027e01d8;
        sp48 = temp_r1_7 + 0xE;
        M2C_FIELD(temp_r1_7, s16 *, 0xE) = (s16) (*sp48 | 2);
        temp_r1_8 = *data_027e01d8;
        sp44 = temp_r1_8 + 0xE;
        M2C_FIELD(temp_r1_8, s16 *, 0xE) = (s16) (*sp44 | 4);
        temp_r1_9 = *data_027e01d8;
        sp40 = temp_r1_9 + 0xE;
        M2C_FIELD(temp_r1_9, s16 *, 0xE) = (s16) (*sp40 | 8);
        temp_r1_10 = *data_027e01d8;
        sp3C = temp_r1_10 + 0xE;
        M2C_FIELD(temp_r1_10, s16 *, 0xE) = (s16) (*sp3C | 0x10);
        temp_r1_11 = *data_027e01d8;
        sp38 = temp_r1_11 + 0x10;
        M2C_FIELD(temp_r1_11, s16 *, 0x10) = (s16) ((*sp38 & ~1) | 1);
        temp_r1_12 = *data_027e01d8;
        sp34 = temp_r1_12 + 0x10;
        M2C_FIELD(temp_r1_12, s16 *, 0x10) = (s16) (*sp34 | 2);
        temp_r1_13 = *data_027e01d8;
        sp30 = temp_r1_13 + 0x10;
        M2C_FIELD(temp_r1_13, s16 *, 0x10) = (s16) (*sp30 | 4);
        temp_r1_14 = *data_027e01d8;
        sp2C = temp_r1_14 + 0x10;
        M2C_FIELD(temp_r1_14, s16 *, 0x10) = (s16) (*sp2C | 8);
        temp_r0 = *data_027e01d8;
        sp28 = temp_r0 + 0x10;
        M2C_FIELD(temp_r0, s16 *, 0x10) = (s16) (*sp28 | 0x10);
        func_02082770();
        temp_r1_15 = *data_027e01d8;
        sp24 = temp_r1_15 + 0x12;
        M2C_FIELD(temp_r1_15, s16 *, 0x12) = (s16) ((*sp24 & ~1) | 1);
        temp_r1_16 = *data_027e01d8;
        sp20 = temp_r1_16 + 0x12;
        M2C_FIELD(temp_r1_16, s16 *, 0x12) = (s16) (*sp20 | 2);
        temp_r1_17 = *data_027e01d8;
        sp1C = temp_r1_17 + 0x12;
        M2C_FIELD(temp_r1_17, s16 *, 0x12) = (s16) (*sp1C | 4);
        temp_r1_18 = *data_027e01d8;
        sp18 = temp_r1_18 + 0x12;
        M2C_FIELD(temp_r1_18, s16 *, 0x12) = (s16) (*sp18 | 8);
        temp_r1_19 = *data_027e01d8;
        sp14 = temp_r1_19 + 0x12;
        M2C_FIELD(temp_r1_19, s16 *, 0x12) = (s16) (*sp14 | 0x10);
        temp_r1_20 = *data_027e01d8;
        sp10 = temp_r1_20 + 0x12;
        M2C_FIELD(temp_r1_20, s16 *, 0x12) = (s16) (*sp10 & ~0x100);
        temp_r1_21 = *data_027e01d8;
        spC = temp_r1_21 + 0x12;
        M2C_FIELD(temp_r1_21, s16 *, 0x12) = (s16) (*spC & ~0x200);
        temp_r1_22 = *data_027e01d8;
        sp8 = temp_r1_22 + 0x12;
        M2C_FIELD(temp_r1_22, s16 *, 0x12) = (s16) (*sp8 & ~0x400);
        temp_r1_23 = *data_027e01d8;
        sp4 = temp_r1_23 + 0x12;
        M2C_FIELD(temp_r1_23, s16 *, 0x12) = (s16) (*sp4 & ~0x800);
        temp_r0_2 = *data_027e01d8;
        sp0 = temp_r0_2 + 0x12;
        M2C_FIELD(temp_r0_2, s16 *, 0x12) = (s16) (*sp0 & ~0x1000);
    }
    temp_r0_3 = M2C_FIELD(arg0, s32 *, 0x58);
    if (((u32) (temp_r0_3 << 0x12) >> 0x1F) & 0xFF) {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((temp_r0_3 & ~0x1FC00000) | 0x01000000);
    }
}

void func_0208ab78(void *arg0) {
    M2C_UNK func_02082770();
    M2C_UNK Reset3DSpriteEngineState();
    M2C_UNK func_020b26dc();
    M2C_UNK func_020d472c();
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x15) >> 0x1F) & 0xFF) {
        Reset3DSpriteEngineState();
        func_02082770();
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x13) >> 0x1F) & 0xFF) {
        func_020d472c();
        func_020b26dc();
    }
    func_0208a714(arg0);
}

