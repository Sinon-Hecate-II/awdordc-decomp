/* 17 functions from 0x02179E74 to 0x0217AE38 (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02179e74(void) {
    extern s8 data_ov001_02193d94;
    void func_ov001_02179dc8(void);
    M2C_FIELD(&data_ov001_02193d94,u8 *,0) = M2C_FIELD(&data_ov001_02193d94,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&data_ov001_02193d94,u8 *,0) < 120U) return;
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02179dc8);
}

void func_ov001_02179ea8(void) {
    extern M2C_UNK data_ov001_02193d98;
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175db4(M2C_UNK *, M2C_UNK);
    M2C_UNK func_ov001_02184170(M2C_UNK);
    void func_ov001_02179f80(void);
    void func_ov001_021722ac(void);
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_02171dd0(M2C_UNK);
    void func_ov001_0217a0d4(void);
    void func_ov001_0217a17c(void);
    M2C_UNK func_ov001_0218ad0c(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c884(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_0217ac18(void);
    void func_ov001_0217b130(void);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_0217b0d4(void);
    void func_ov001_0217a2f0(void);
    s32 temp;

    M2C_FIELD(&data_ov001_02193d98, void **, 4) = func_ov001_0218b6f8((M2C_UNK)0x5c, (M2C_UNK)4);
    func_ov001_02175db4(&temp, 0);
    if (temp == 0) {
        M2C_FIELD(&data_ov001_02193d98, u8 *, 0) = 0;
        M2C_FIELD(&data_ov001_02193d98, u16 *, 2) = 0;
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51) =
            (u8)func_ov001_02184170(M2C_FIELD(&data_ov001_02193d98, void **, 4));
        func_ov001_02179f80();
        func_ov001_021722ac();
        func_ov001_02171c24((M2C_UNK)0x34, (M2C_UNK)(0x34 - 0x35), (M2C_UNK)0);
        func_ov001_02171dd0((M2C_UNK)2);
        func_ov001_0217a0d4();
        func_ov001_0217a17c();
    }
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0xc) = (s32)func_ov001_0218ad0c((M2C_UNK)0, (M2C_UNK)0);
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0x3c) =
        (s32)func_ov001_0218c884((M2C_UNK)1, (M2C_UNK)func_ov001_0217b0d4, (M2C_UNK)0, (M2C_UNK)0x6e);
    func_ov001_0217ac18();
    func_ov001_0217b130();
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217a2f0);
}

void func_ov001_0217a0d4(void) {
    s32 func_02002088(s32, u16);
    M2C_UNK func_ov001_021838a8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_ov001_02193d98;
    s32 var_r0;
    s32 var_r4;
    u8 temp_r1;

    var_r0 = 0;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u16 *, 0x40) = (u16)((M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51) - 4) * 0x1c);
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51);
    if ((u32)temp_r1 <= 4U) {
        var_r4 = var_r0;
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53) = var_r0;
    } else if ((u32)temp_r1 <= 8U) {
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53) = 0x1f;
        var_r4 = 1;
    } else {
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53) = 0x37;
        var_r4 = 2;
    }
    if (var_r4 != 0) {
        var_r0 = func_02002088(M2C_FIELD(&data_ov001_02193d98, u16 *, 2) * M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53), M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u16 *, 0x40));
    }
    func_ov001_021838a8(var_r4, 0x55, 0xec, 0x3f, var_r0);
}

void func_ov001_0217a2f0(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_0217a344(void);
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x1D, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x1D);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217a344);
}

void func_ov001_0217a344(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217a380;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    func_ov001_02175d54(&func_ov001_0217a380);
}

void func_ov001_0217a380(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_0217a3a8;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_0217a3a8);
}

void func_ov001_0217a3a8(void) {
    M2C_UNK func_ov001_0217a3bc();
    M2C_UNK func_ov001_0217a880();
    M2C_UNK func_ov001_0217a610();
    func_ov001_0217a3bc();
    func_ov001_0217a610();
    func_ov001_0217a880();
}

void func_ov001_0217a98c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217a9ac;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217a9ac);
}

void func_ov001_0217a9ac(void) {
    M2C_UNK func_ov001_02171694();
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d98;
    extern M2C_UNK func_ov001_0217aa1c;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x54) != 0) {
        func_ov001_02171694();
    } else {
        func_ov001_02171750();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x1D, 8);
    func_ov001_02175d54(&func_ov001_0217aa1c);
}

void func_ov001_0217ac18(void) {
    s32 func_02002088(s32, u16);
    M2C_UNK func_ov001_0217acc0(s32, s32);
    M2C_UNK func_ov001_0217ae38(s32, s32);
    M2C_UNK func_ov001_0217aec4();
    M2C_UNK func_ov001_0218b1ec(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b298(M2C_UNK);
    extern M2C_UNK data_ov001_02193d98;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;

    var_r7 = func_02002088(M2C_FIELD(&data_ov001_02193d98, u16 *, 2), 0x1c);
    var_r4 = M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51);
    func_ov001_0218b1ec(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0xc), 0);
    if (var_r4 > 5) {
        var_r4 = 5;
    }
    var_r5 = var_r7;
    var_r6 = 0;
    if (var_r4 > 0) {
        do {
            func_ov001_0217acc0(var_r5, var_r6);
            var_r6 += 1;
            var_r5 += 1;
        } while (var_r6 < var_r4);
    }
    var_r5 = 0;
    if (var_r4 > 0) {
        do {
            func_ov001_0217ae38(var_r7, var_r5);
            var_r5 += 1;
            var_r7 += 1;
        } while (var_r5 < var_r4);
    }
    func_ov001_0218b298(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0xc));
    func_ov001_0217aec4();
}

