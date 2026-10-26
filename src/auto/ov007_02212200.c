/* 6 functions from 0x02212200 to 0x02213150 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_02212cbc(void) {
    M2C_UNK func_020ab200();
    func_020ab200();
}

void func_ov007_02212cc8(M2C_UNK arg0) {
    M2C_UNK func_01ffa8c4(M2C_UNK, M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    s32 func_020d46e8(void);
    M2C_UNK func_ov007_02211f10(s32);
    s32 func_ov007_02211f20(void);
    M2C_UNK func_ov007_02212dcc(void);
    extern u16 *data_02101e84;
    s32 initialTimer;

    initialTimer = func_ov007_02211f20();
    if (*data_02101e84 & 1) {
        func_ov007_02211f10(0);
    }
    if (*data_02101e84 & 2) {
        func_ov007_02211f10(1);
    }
    if (*data_02101e84 & 0x400) {
        func_ov007_02211f10(2);
    }
    if (*data_02101e84 & 0x800) {
        func_ov007_02211f10(3);
    }
    if (*data_02101e84 & 0xC0B) {
        func_ov007_02212dcc();
    }
    if (initialTimer != func_ov007_02211f20()) {
        func_0208fe30(0x10011);
    }
    if (func_020d46e8() == 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov007_02212da0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f6e8;
    func_01ffa3dc(&data_ov007_0221f6e8, 7);
}

void func_ov007_02212db8(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_ov007_0221f6e8;
    func_01ffa9e4(&data_ov007_0221f6e8);
}

