/* 18 functions from 0x020DE264 to 0x020DF1D0 (main), found by ds-decomp. */
#include "common.h"

void func_020de610(void) {

}

void func_020de868(s32 arg0, s32 arg1, void *arg2) {
    if (arg0 != 0) {
        return;
    }
    if (arg1 != 0) {
        M2C_FIELD(arg2, u16 *, 0x48) = (u16) (M2C_FIELD(arg2, u16 *, 0x48) | 0x100);
    }
}

s32 func_020de884(M2C_UNK arg0) {
    M2C_UNK func_0203c0b0(M2C_UNK, M2C_UNK *, s32);
    void *func_ov010_02229b00();
    extern M2C_UNK data_0212c5c8;
    if (!(M2C_FIELD(func_ov010_02229b00(), u8 *, 0x1A) & 2)) {
        return -1;
    }
    func_0203c0b0(arg0, &data_0212c5c8, 0x5DC000);
    return 0x7FFFFF;
}

void func_020deb74(M2C_UNK arg0) {
    M2C_UNK func_020ddfd8(M2C_UNK, M2C_UNK);
    func_020ddfd8(arg0, 0);
}

void func_020deb84(M2C_UNK arg0) {
    M2C_UNK func_020ddfd8(M2C_UNK, M2C_UNK);
    func_020ddfd8(arg0, 1);
}

void func_020deb94(M2C_UNK arg0) {
    M2C_UNK func_020de264(M2C_UNK, M2C_UNK);
    func_020de264(arg0, 0);
}

void func_020deba4(M2C_UNK arg0) {
    M2C_UNK func_020de264(M2C_UNK, M2C_UNK);
    func_020de264(arg0, 1);
}

void func_020debb4(M2C_UNK arg0) {
    M2C_UNK func_020de614(M2C_UNK, M2C_UNK);
    func_020de614(arg0, 0);
}

void func_020debc4(M2C_UNK arg0) {
    M2C_UNK func_020de614(M2C_UNK, M2C_UNK);
    func_020de614(arg0, 1);
}

void func_020debd4(M2C_UNK arg0) {
    M2C_UNK func_020de8c4(M2C_UNK, M2C_UNK);
    func_020de8c4(arg0, 0);
}

void func_020debe4(M2C_UNK arg0) {
    M2C_UNK func_020de8c4(M2C_UNK, M2C_UNK);
    func_020de8c4(arg0, 1);
}

