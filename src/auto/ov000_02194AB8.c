/* 7 functions from 0x02194AB8 to 0x021959CC (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_021954a4(void) {
    s32 func_ov000_02194ab8(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02194ab8(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_021954dc(s16 *arg0) {
    void func_ov000_02179be0();
    void func_ov000_02179d3c();
    s32 func_ov000_021786a8(s16 *);
    s32 func_ov000_02179e48(s16 *);
    s16 sp0[2];

    func_ov000_02179be0();
    func_ov000_02179d3c();
    if (func_ov000_021786a8(sp0) == 0) {
        return 0;
    }
    if (func_ov000_02179e48(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_0219553c(void) {
    s32 func_ov000_021954dc(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_021954dc(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

void func_ov000_02195750(void) {
    s32 func_ov000_02195574(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02195574(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

