/* 10 functions from 0x020C1F58 to 0x020C2E4C (main), found by ds-decomp. */
#include "common.h"

void func_020c2ca0(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(arg0, u8 *, 0x35) = 0;
}

void func_020c2e10(void) {
    M2C_UNK func_020c1f58();
    func_020c1f58();
}

void func_020c2e1c(void) {
    M2C_UNK func_020c2cec();
    func_020c2cec();
}

void func_020c2e28(void) {
    void func_020c2ca0();
    func_020c2ca0();
}

void func_020c2e34(void) {
    M2C_UNK func_020c253c();
    func_020c253c();
}

void func_020c2e40(void) {
    M2C_UNK func_020c2aa4();
    func_020c2aa4();
}

