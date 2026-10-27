/* 8 functions from 0x02217C80 to 0x02218AD0 (ov007), found by ds-decomp. */
#include "common.h"

s32 func_ov007_02217c80(void *arg0) {
    s32 func_ov007_02217c50(void *);
    s32 result = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x38) + 1;
    if (result >= func_ov007_02217c50(arg0)) result = 0;
    return result;
}

s32 func_ov007_02217ca8(void *arg0) {
    s32 func_ov007_02217c50(void *);
    s32 result = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x38) - 1;
    if (result < 0) result = func_ov007_02217c50(arg0) - 1;
    return result;
}

void func_ov007_02217cd0(void *arg0) {
    s8 *func_ov007_02217b64(u8);
    void func_01ffa8c4(void *, s32);
    u8 index;
    s8 *table;
    u8 mode;
    index = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x3A);
    table = func_ov007_02217b64(M2C_FIELD(arg0, u8 *, 0x37));
    mode = M2C_FIELD(arg0, u8 *, 0x37);
    switch (mode) {
    case 0:
        if (table[index * 5] == 15 && M2C_FIELD(arg0 + mode, u8 *, 0x38) == 4) return;
        break;
    case 1:
        break;
    }
    M2C_FIELD(arg0, u8 *, 0x36) = 1;
    func_01ffa8c4(arg0, 2);
}

void func_ov007_02218570(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_ov007_02211ea4(u8);
    M2C_UNK func_ov007_02211f10(M2C_UNK);
    M2C_UNK func_ov007_02211f60();
    M2C_UNK func_ov007_02211f70();
    M2C_UNK func_ov007_02211fb0();
    M2C_UNK func_ov007_02211fc0();
    M2C_UNK func_ov007_02217bd0(M2C_UNK, u8);
    M2C_UNK func_ov007_02217be8(M2C_UNK, u8, u8);
    M2C_UNK func_ov007_0221ab4c();
    u8 temp_r0;
    void *temp_r2;
    void *temp_r2_2;

    if (M2C_FIELD(arg0, u8 *, 0x36) != 0) {
        func_ov007_02211ea4(M2C_FIELD(arg0, u8 *, 0x37));
        func_ov007_02211f10(0);
        temp_r0 = M2C_FIELD(arg0, u8 *, 0x37);
        switch (temp_r0) {                          /* irregular */
        case 0:
            func_ov007_02217bd0(0, M2C_FIELD((arg0 + temp_r0), u8 *, 0x3A));
            func_ov007_02211fb0();
            temp_r2 = arg0 + M2C_FIELD(arg0, u8 *, 0x37);
            func_ov007_02217be8(0, M2C_FIELD(temp_r2, u8 *, 0x3A), M2C_FIELD(temp_r2, u8 *, 0x38));
            func_ov007_02211fc0();
            break;
        case 1:
            func_ov007_02217bd0(1, M2C_FIELD((arg0 + temp_r0), u8 *, 0x3A));
            func_ov007_02211f60();
            temp_r2_2 = arg0 + M2C_FIELD(arg0, u8 *, 0x37);
            func_ov007_02217be8(1, M2C_FIELD(temp_r2_2, u8 *, 0x3A), M2C_FIELD(temp_r2_2, u8 *, 0x38));
            func_ov007_02211f70();
            break;
        }
        func_ov007_0221ab4c();
        func_0208fe30(0x10016);
    } else {
        func_0208fe30(0x1000F);
    }
    M2C_FIELD(arg0, s8 *, 0x35) = 1;
}

void func_ov007_02218a60(void *arg0) {
    M2C_UNK func_02082040(void *);
    M2C_UNK func_020a40c0(u8);
    M2C_UNK func_020e35cc(s32);
    extern void **gCurrentMap;
    void *temp_r4;
    void *temp_r4_2;

    temp_r4 = M2C_FIELD(arg0, void **, 0x58);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    M2C_FIELD(arg0, void **, 0x58) = NULL;
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x5C);
    if (temp_r4_2 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4_2, s32 *, 0x14));
        func_02082040(temp_r4_2);
    }
    M2C_FIELD(arg0, void **, 0x5C) = NULL;
    func_020a40c0(M2C_FIELD(*gCurrentMap, u8 *, 0x5158));
}
