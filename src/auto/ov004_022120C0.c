/* 5 functions from 0x022120C0 to 0x02212918 (ov004), found by ds-decomp. */
#include "common.h"

void func_ov004_0221285c(void) {
    M2C_UNK func_02082770();
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r7;
    s32 var_r1;
    s32 var_r8;

    temp_r7 = gCur3DSpriteEngine;
    var_r8 = 0;
    do {
        if (var_r8 == 0) {
            var_r1 = data_027e00c8;
        } else {
            var_r1 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r1;
        if (var_r1 == data_027e00c4) {
            func_02082770();
        }
        var_r8 += 1;
    } while (var_r8 < 2);
    gCur3DSpriteEngine = temp_r7;
}

void func_ov004_022128b8(void *arg0) {
    M2C_UNK func_01ffa6fc();
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    u16 temp_r1;

    if ((*data_02101e84 & 0xC0B) || (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0)) {
        func_01ffa6fc();
        return;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0x38);
    if ((u32) temp_r1 < 0x384U) {
        M2C_FIELD(arg0, u16 *, 0x38) = (u16) (temp_r1 + 1);
        return;
    }
    func_01ffa6fc();
}

