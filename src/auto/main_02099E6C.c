/* 3 functions from 0x02099E6C to 0x0209ACC4 (main), found by ds-decomp. */
#include "common.h"

void func_0209ac6c(void *arg0, void *arg1) {
    if (arg1 == NULL) {
        return;
    }
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 0x4C) | M2C_FIELD(arg0, u16 *, 0x44));
    M2C_FIELD(arg1, s16 *, 0x40) = (s16) ((M2C_FIELD(arg0, u16 *, 0x4C) + 1) | M2C_FIELD(arg0, u16 *, 0x44));
}

void func_0209ac9c(void *arg0) {
    s8 func_02095fe8();
    M2C_UNK func_020974d0(void *);
    M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) | 1);
    M2C_FIELD(arg0, s8 *, 0x5B) = func_02095fe8();
    func_020974d0(arg0);
}
