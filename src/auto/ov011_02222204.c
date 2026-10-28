/* 3 functions from 0x02222204 to 0x022231F8 (ov011), found by ds-decomp. */
#include "common.h"
#define ROTATE_RIGHT(x,n) (((x)>>(n)) | ((x)<<(32-(n))))

void func_ov011_02222204(M2C_UNK arg0) {
    M2C_UNK func_01ff9e00();
    M2C_UNK func_01ffac9c(M2C_UNK, M2C_UNK, s32, M2C_UNK *, s32);
    M2C_UNK func_ov011_022216d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov011_02222010(M2C_UNK, M2C_UNK, M2C_UNK);
    void G3_SubmitSpriteQuad(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s16);
    extern M2C_UNK data_02101f2c;
    extern M2C_UNK data_02101f5c;
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c4;
    extern u16 **data_027e00c8;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 *sp8;
    u16 *sp4;
    s32 var_r9;
    u16 **temp_r11;
    u16 **var_r0;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;

    var_r9 = 0;
    temp_r11 = gCur3DSpriteEngine;
    do {
        if (var_r9 == 0) {
            var_r0 = data_027e00c8;
        } else {
            var_r0 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r0;
        temp_r0 = *var_r0;
        sp18 = temp_r0;
        *temp_r0 = *sp18 | 0x10;
        temp_r0_2 = *gCur3DSpriteEngine;
        sp14 = temp_r0_2;
        *temp_r0_2 = *sp14 | 0x20;
        temp_r0_3 = *gCur3DSpriteEngine;
        sp10 = temp_r0_3;
        *temp_r0_3 = *sp10 | 0x40;
        temp_r0_4 = *gCur3DSpriteEngine;
        spC = temp_r0_4;
        *temp_r0_4 = *spC | 0x80;
        temp_r0_5 = *gCur3DSpriteEngine;
        sp8 = temp_r0_5;
        *temp_r0_5 = *sp8 | 0x100;
        temp_r0_6 = *gCur3DSpriteEngine;
        sp4 = temp_r0_6 + 0x12;
        M2C_FIELD(temp_r0_6, s16 *, 0x12) = (s16) (*sp4 & ~0xC0);
        M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x51) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x52) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x53) = 0;
        func_01ff9e00();
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x38) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3A) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3C) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x44) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3E) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x46) = 0;
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r11;
    G3_SubmitSpriteQuad(arg0, 2, 2, 0x80, 0x60);
    G3_SubmitSpriteQuad(arg0, 2, 3, 0x80, 0x60);
    func_ov011_022216d8(arg0, 3, 0, 3);
    func_ov011_022216d8(arg0, 4, 1, 3);
    func_ov011_022216d8(arg0, 0x13, 2, 0);
    func_ov011_02222010(arg0, 0, 0);
    func_ov011_02222010(arg0, 1, 0);
    func_ov011_02222010(arg0, 7, 1);
    func_01ffac9c(0x40, 0x50, 0, &data_02101f2c, 0);
    func_01ffac9c(0, 0xAA, 0x6040, &data_02101f5c, 0);
    func_01ffac9c(0x80, 0xAA, 0x6060, &data_02101f5c, 0);
}
