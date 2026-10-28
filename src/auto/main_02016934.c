/* 2 functions from 0x02016934 to 0x02017158 (main), found by ds-decomp. */
#include "common.h"

void func_02016934(void *arg0) {}

void func_020170e8(void *arg0) {
    extern M2C_UNK data_02136c40;
    u16 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 4);
    switch ((s32) temp_r0) {
    case 7:
    case 9:
    case 25:
    case 26:
        break;
    case 21:
        M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), void (**)(s32, void *), 0x51C)(9, arg0);
        break;
    }
}
