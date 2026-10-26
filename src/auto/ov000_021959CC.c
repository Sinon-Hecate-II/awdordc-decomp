/* 15 functions from 0x021959CC to 0x0219694C (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_02195ea4(void) {
    s32 func_ov000_021a98e4(u32);
    s32 func_ov000_02195b80(s16 *);
    s32 func_ov000_02195788(s16 *);
    s32 func_ov000_0217e6bc(s16,s16);
    void func_ov000_0218a9ac(s16,s16);
    extern void **data_027e0058;
    s16 sp0[2];
    if (func_ov000_021a98e4((u32)(*M2C_FIELD(*data_027e0058,u8 **,0x52d0)<<26)>>26)==1) {
        if (func_ov000_02195b80(sp0)==0) return;
    } else {
        if (func_ov000_02195788(sp0)==0) return;
    }
    if (func_ov000_0217e6bc(sp0[0],sp0[1])==0) return;
    func_ov000_0218a9ac(sp0[0],sp0[1]);
}

void func_ov000_0219604c(void) {
    s32 func_ov000_02195f1c(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02195f1c(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

void func_ov000_0219619c(void) {
    s32 func_ov000_02196084(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196084(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

void func_ov000_021962f8(void) {
    s32 func_ov000_021961d4(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_021961d4(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_02196330(void) {
    s32 func_020a32f4(s32);
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    extern void **data_027e0058;
    s32 var_r5;

    var_r5 = 1;
loop_1:
    if ((func_020d1938(var_r5) != 0) && (func_020d273c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), var_r5) == 0) && (func_020a32f4(var_r5) != 0)) {
        return 1;
    }
    var_r5 += 1;
    if (var_r5 >= 5) {
        return 0;
    }
    goto loop_1;
}

s32 func_ov000_02196398(s16 *arg0) {
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

void func_ov000_021963f8(void) {
    s32 func_ov000_02196398(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196398(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

