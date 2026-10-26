/* 6 functions from 0x0216D2B4 to 0x0216E178 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0216e054(void) {
    extern void *data_ov000_021df5e0;
    M2C_UNK func_ov000_0216cee8(void);
    M2C_UNK func_020b1c60(u8);
    M2C_UNK func_ov000_0216cefc(void);
    M2C_UNK func_ov000_0216dd0c(void);
    func_ov000_0216cee8();
    func_020b1c60(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xD));
    func_ov000_0216cefc();
    M2C_FIELD(data_ov000_021df5e0, u8 *, 0x11) = 1 - M2C_FIELD(data_ov000_021df5e0, u8 *, 0x11);
    M2C_FIELD(data_ov000_021df5e0, s16 *, 0x14) = -1;
    func_ov000_0216dd0c();
}

void func_ov000_0216e09c(u8 arg0) {
    extern void *data_ov000_021df5e0;
    M2C_FIELD(data_ov000_021df5e0, u8 *, 0xD) = arg0;
    M2C_FIELD(data_ov000_021df5e0, u8 *, 0xE) = (u8) M2C_FIELD((data_ov000_021df5e0 + M2C_FIELD(data_ov000_021df5e0, u8 *, 0xD)), u8 *, 4);
    M2C_FIELD(data_ov000_021df5e0, u8 *, 0xF) = (u8) M2C_FIELD(data_ov000_021df5e0, u8 *, 0xE);
}

void func_ov000_0216e0d0(u8 *arg0) {
    extern void *data_ov000_021df5e0;
    M2C_UNK func_0208fe30(s32);
    void func_ov000_0216e054(void);
    if (M2C_FIELD(data_ov000_021df5e0, u8 *, 0xD) == *arg0) return;
    func_0208fe30(0x10019);
    func_ov000_0216e09c(*arg0);
    func_ov000_0216e054();
}

void func_ov000_0216e110(void) {
    extern void *data_ov000_021df5e0;
    extern M2C_UNK data_ov000_021b8790;
    M2C_UNK func_020b22a4(s32, M2C_UNK, M2C_UNK *, s32);
    M2C_UNK func_020b1c78(u8);
    s32 i;
    s32 x;
    i = 0;
    if (i < M2C_FIELD(data_ov000_021df5e0, u8 *, 0xC)) {
        x = 0x50;
        do {
            func_020b22a4(x, 0xA8, &data_ov000_021b8790, i);
            i++;
            x += 0x18;
        } while (i < M2C_FIELD(data_ov000_021df5e0, u8 *, 0xC));
    }
    func_020b1c78(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xD));
}

