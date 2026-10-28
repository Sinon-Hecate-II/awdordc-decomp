/* 14 functions from 0x0221BB70 to 0x0221CAA0 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_0221bb70(M2C_UNK arg0) {
    M2C_UNK func_01ffa730(M2C_UNK);
    s32 func_02097e84();
    void *func_0209bccc(s32, s32, s32, s32, s32, s32);
    s32 func_020cd1e4();
    M2C_UNK func_ov005_02218e54();
    s32 func_ov005_02218f50();
    extern M2C_UNK data_0215c334;
    extern M2C_UNK data_0215c340;
    s32 enabled;
    void *object;
    if (func_020cd1e4() == 0) enabled = 0;
    else if (M2C_FIELD(&data_0215c340, u16 *, M2C_FIELD(&data_0215c334, u8 *, 4) * 12) == 0) enabled = 0;
    else enabled = 1;
    if (enabled == 0) {
        func_01ffa730(arg0);
        return;
    }
    object = func_0209bccc(2, 0x14, 0, func_ov005_02218f50(), 0, 1);
    M2C_FIELD(object, u16 *, 0x46) = 12;
    M2C_FIELD(object, u8 *, 0x55) = 2;
    func_ov005_02218e54();
    M2C_FIELD(object, s32 *, 0x60) = func_02097e84();
    M2C_FIELD(object, u8 *, 0x5C) |= 4;
}

M2C_UNK func_ov005_0221bc28(void) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_020aad18(s32);
    extern M2C_UNK data_ov005_02220d50;
    func_020aad18(M2C_FIELD(func_01ffa770(&data_ov005_02220d50), s32 *, 0x38));
}

void func_ov005_0221bc44(M2C_UNK arg0) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_02087db8(void *, s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_01ffa6fc(M2C_UNK);
    extern u16 *data_02101e84;
    extern M2C_UNK data_ov005_02220d50;
    void *object;
    u8 active;
    if (!(*data_02101e84 & 1)) return;
    func_0208fe30(0x1000D);
    object = M2C_FIELD(M2C_FIELD(func_01ffa770(&data_ov005_02220d50), void **, 0x38), void **, 0x64);
    active = M2C_FIELD(object, u8 *, 0x12) != 0;
    if (active) func_02087db8(object, 1);
    func_01ffa6fc(arg0);
}

M2C_UNK func_ov005_0221bcb0() {
    return 0;
}

int func_ov005_0221c150(void *arg0) {
    return 0;
}

void func_ov005_0221c9c0(void) {
    M2C_UNK func_ov005_0221b4d8();
    func_ov005_0221b4d8();
}

void func_ov005_0221c9cc(void) {
    M2C_UNK func_ov005_0221b854();
    func_ov005_0221b854();
}

void func_ov005_0221c9d8(void) {
    void func_ov005_0221bb70();
    func_ov005_0221bb70();
}

void func_ov005_0221c9e4(M2C_UNK arg0) {
    s32 func_0209bf28();
    M2C_UNK func_01ffa6fc(M2C_UNK);
    if (func_0209bf28() != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov005_0221ca04(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_01ffaa5c(s32);
    s32 func_01ffaa7c();
    extern M2C_UNK data_ov005_02220b00;
    extern M2C_UNK data_ov005_02220d50;
    extern M2C_UNK data_ov005_02220fb8;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov005_02220b00, func_01ffaa7c());
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    func_01ffaa5c(arg0);
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0x20;
    M2C_FIELD(temp_r0, s8 *, 0x44) = 1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32) M2C_FIELD(func_01ffa770(&data_ov005_02220d50), s32 *, 0x38);
}

void func_ov005_0221ca70(void) {
    M2C_UNK func_ov005_0221bc28();
    func_ov005_0221bc28();
}

void func_ov005_0221ca7c(void) {
    void func_ov005_0221bc44();
    func_ov005_0221bc44();
}

void func_ov005_0221ca88(void) {
    M2C_UNK func_ov005_0221bcb0();
    func_ov005_0221bcb0();
}

void func_ov005_0221ca94(void) {
    M2C_UNK func_ov005_0221c150();
    func_ov005_0221c150();
}

