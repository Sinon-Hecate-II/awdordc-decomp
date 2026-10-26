/* 12 functions from 0x0217DC7C to 0x0217EB6C (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_0217ded8(void) {
    M2C_UNK func_ov001_02183a08();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217def8;
    func_ov001_02183a08();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217def8);
}

void func_ov001_0217def8(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217df44;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x1D, 8);
    func_ov001_02175d54(&func_ov001_0217df44);
}

void func_ov001_0217e238(void) {
    s32 func_02002088(u16, s32);
    M2C_UNK func_ov001_0217e2f8(s32, s32);
    M2C_UNK func_ov001_0217e494(s32, s32);
    M2C_UNK func_ov001_0217e95c();
    M2C_UNK func_ov001_02183720();
    M2C_UNK func_ov001_02183738(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b1ec(s32, M2C_UNK);
    M2C_UNK func_ov001_0218b298(s32);
    extern u16 data_ov001_0218f8fe[];
    extern M2C_UNK data_ov001_02193dac;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r4 = func_02002088(M2C_FIELD(&data_ov001_02193dac, u16 *, 4), 0x1D);
    func_ov001_0218b1ec(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 0x14), 0);
    var_r5 = var_r4;
    var_r6 = 0;
    do {
        func_ov001_0217e2f8(var_r5, var_r6);
        var_r6 += 1;
        var_r5 += 1;
    } while (var_r6 < 5);
    func_ov001_02183738(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 8) + (data_ov001_0218f8fe[var_r4] * 2), 0, 0x1E, 0x13);
    var_r5 = 0;
    do {
        func_ov001_0217e494(var_r4, var_r5);
        var_r5 += 1;
        var_r4 += 1;
    } while (var_r5 < 5);
    func_ov001_02183720();
    func_ov001_0218b298(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 0x14));
    func_ov001_0217e95c();
}

s32 func_ov001_0217e5e8(u32 arg0) {
    void *func_ov001_0218445c();
    s32 var_r1;
    void *temp_r0;

    temp_r0 = func_ov001_0218445c();
    var_r1 = 1;
    switch (arg0) {
    default:
        break;
    case 7:
        if (M2C_FIELD(temp_r0, u8 *, 0xF5) == 0) {
            var_r1 = 0;
        }
        break;
    case 0:
    case 1:
        if ((u32) (u8) (M2C_FIELD(temp_r0, u8 *, 0xE7) + 0xFF) <= 1U) {
            var_r1 = 0;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (M2C_FIELD(temp_r0, u8 *, 0xF5) != 0) {
            var_r1 = 0;
        }
        break;
    case 9:
    case 10:
        if (M2C_FIELD(temp_r0, u8 *, 0xF6) != 0) {
            var_r1 = 0;
        }
        break;
    }
    return var_r1;
}

void func_ov001_0217e8d4(void *arg0, s32 arg1) {
    M2C_UNK func_0206ccf8(M2C_UNK *, M2C_UNK, M2C_UNK *, u8, s32, s32, s32);
    M2C_UNK func_ov001_0218b080(s32, M2C_UNK, s32, M2C_UNK, s32, M2C_UNK *, s32);
    extern M2C_UNK data_ov001_02190874;
    extern M2C_UNK data_ov001_02193dac;
    u8 spC[0x20];

    func_0206ccf8(spC, 0x10, &data_ov001_02190874, M2C_FIELD(arg0, u8 *, 0), (s32) M2C_FIELD(arg0, u8 *, 1), (s32) M2C_FIELD(arg0, u8 *, 2), (s32) M2C_FIELD(arg0, u8 *, 3));
    func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 0x14), 0x5F, (arg1 * 0x1D) + 8, 2, 7, spC, 1);
}

