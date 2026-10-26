/* 10 functions from 0x020C2E4C to 0x020C3D34 (main), found by ds-decomp. */
#include "common.h"

u8 func_020c306c(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02129794;
    u8 var_r0;

    if (func_01ffa770(&data_02129794) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020c32b0(void) {
    void func_020c32bc();
    func_020c32bc();
}

void func_020c32bc(void) {
    s32 func_020d19b4();
    M2C_UNK func_0208fe30(s32);
    if (func_020d19b4() != 0) {
        func_0208fe30(0xE1);
        return;
    }
    func_0208fe30(0xE3);
}

void *func_020c32e4(void *arg0) {
    M2C_UNK func_02082040();
    M2C_UNK func_020e35cc();
    extern M2C_UNK data_02129890;
    void *p;
    M2C_FIELD(arg0, void **, 0) = &data_02129890;
    p = M2C_FIELD(arg0, void **, 0x40);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x3C);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(arg0, void **, 0x44);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x48);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x4C);
    if (p != NULL) func_020e35cc(p);
    func_02082040(arg0);
    return arg0;
}

s32 func_020c3360(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void *func_020c3374(void *arg0) {
    M2C_UNK func_02082040();
    M2C_UNK func_020e35cc();
    extern M2C_UNK data_02129890;
    void *p;
    M2C_FIELD(arg0, void **, 0) = &data_02129890;
    p = M2C_FIELD(arg0, void **, 0x40);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x3C);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(arg0, void **, 0x44);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x48);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x4C);
    if (p != NULL) func_020e35cc(p);
    
    return arg0;
}

void func_020c33e8(void) {

}
