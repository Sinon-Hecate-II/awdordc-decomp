/* 3 functions from 0x02211200 to 0x02212184 (ov006), found by ds-decomp. */
#include "common.h"

void func_ov006_02211314(M2C_UNK arg0) {
    M2C_UNK func_020899cc(void *, M2C_UNK, s32, s32);
    void *func_0208b564(M2C_UNK);
    s64 func_020c53e4(M2C_UNK);
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;
    void *temp_r0;
    if (func_020c53e4(0) == 0) {
        temp_r4 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        temp_r0 = func_0208b564(arg0);
        func_020899cc(temp_r0, 2, 0x4640, 0x42000001);
        M2C_FIELD(temp_r0, s32 *, 0x58) |= 0x1000;
        gCur3DSpriteEngine = temp_r4;
    }
}
