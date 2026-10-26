/* 7 functions from 0x020D6398 to 0x020D6E0C (main), found by ds-decomp. */
#include "common.h"

s32 func_020d66fc(s8 *arg0) {
    s32 value;
    while ((value = *arg0) != 4 && value != -1) {
        if (value == 10) return 1;
        arg0++;
    }
    return 0;
}

void func_020d672c(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080cfc(s32, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    s32 func_020e3218(M2C_UNK *);
    extern M2C_UNK data_0212beec;
    extern M2C_UNK data_0212bef8;
    extern M2C_UNK data_0212bf08;
    extern u16 **gCur3DSpriteEngine;
    func_0200bc5c(&data_0212beec);
    func_02080cfc(func_020e3218(&data_0212bef8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2A00);
    func_0208116c(&data_0212bf08, 0x320, 0x20);
}

void func_020d694c(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_01ffaacc(M2C_UNK, M2C_UNK, u16, M2C_UNK *, s32);
    extern M2C_UNK data_027e0084;
    extern u16 **gCur3DSpriteEngine;
    s32 x;
    s32 color;
    s32 value;
    s32 digit;
    s32 mode1;
    s32 mode2;
    s32 first;
    s32 second;
    u16 tile;

    x = arg0;
    color = arg1 & 0xFF;
    value = arg2;
    do {
        digit = value % 10;
        mode1 = (s32)((u32)(*(u16 *)*(u32 *)gCur3DSpriteEngine << 0x11) >> 0x1E);
        first = 0x150 >> mode1;
        first &= 0x3FF;
        mode2 = (s32)((u32)(*(u16 *)gCur3DSpriteEngine << 0x11) >> 0x1E);
        second = (digit * 2) >> mode2;
        second &= 0x3FF;
        tile = (u16)((first | 0x9000) + second);
        func_01ffaacc(x & 0x1FF, color, tile, &data_027e0084, 8);
        x -= 8;
        value /= 10;
    } while (value != 0);
}

