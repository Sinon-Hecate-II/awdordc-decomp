/* 10 functions from 0x0221EDA8 to 0x0221F500 (ov007), found by ds-decomp. */
#include "common.h"
typedef struct { u8 active:1; u8 mode:4; u8 kind:3; } Ov006C24Flags;
static inline void *InitOv007Text(void *child) {
 s32 func_020e34bc(M2C_UNK); M2C_UNK func_02007f8c(s32,M2C_UNK,M2C_UNK);
    if (child != NULL) {
        M2C_FIELD(child, s16 *, 0x10) = 0x11;
        M2C_FIELD(child, s8 *, 0x12) = 0;
        M2C_FIELD(child, s32 *, 0) = 0;
        M2C_FIELD(child, s32 *, 4) = 0;
        M2C_FIELD(child, s8 *, 8) = -1;
        M2C_FIELD(child, s8 *, 9) = -1;
        M2C_FIELD(child, s8 *, 0xA) = -1;
        M2C_FIELD(child, s8 *, 0xB) = -1;
        M2C_FIELD(child, u8 *, 0xD) = 0xFF;
        M2C_FIELD(child, s8 *, 0xC) = -1;
        M2C_FIELD(child, s8 *, 0xE) = 0;
        M2C_FIELD(child, u8 *, 0xF) = 0xFF;
        M2C_FIELD(child, s32 *, 0x14) = func_020e34bc(0xCC);
        func_02007f8c(M2C_FIELD(child, void **, 0x14), 0, 0xCC);
    }

return child;
}


void func_ov007_0221f220(void) {
    M2C_UNK func_ov007_0221ec40();
    func_ov007_0221ec40();
}

void func_ov007_0221f22c(void) {
    M2C_UNK func_ov007_0221e878();
    func_ov007_0221e878();
}

void func_ov007_0221f238(void) {
    M2C_UNK func_ov007_0221e6d0();
    func_ov007_0221e6d0();
}

void func_ov007_0221f244(void) {
    M2C_UNK func_ov007_0221e85c();
    func_ov007_0221e85c();
}

void func_ov007_0221f250(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_ov007_0221f264(void) {
    M2C_UNK func_ov007_0221ec34();
    func_ov007_0221ec34();
}

void func_ov007_0221f270(u8 *arg0) {
    void *func_01ffa42c(M2C_UNK *);
    M2C_UNK func_02007e98(M2C_UNK, M2C_UNK *, M2C_UNK);
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_02008048(u8 *, M2C_UNK *, M2C_UNK);
    void *func_02082028(M2C_UNK);
    s32 func_02099ae8(u8 *);
    s32 func_02099b00(u8 *);
    s32 func_020e31e0();
    s32 func_020e34bc(M2C_UNK);
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_ov007_02220df8;
    extern M2C_UNK data_ov007_02220ea0;
    extern M2C_UNK data_ov007_02221224;
    extern M2C_UNK data_ov007_02221974;
    extern u8 *data_ov007_02221e0c;
    extern M2C_UNK data_ov007_02221e10;
    M2C_UNK *var_r1;
    u32 var_r8;
    s32 temp_r0_3;
    M2C_UNK *var_r9;
    u8 *var_r5;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_4;

    var_r5 = arg0;
    temp_r0 = func_01ffa42c(&data_ov007_02220df8);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov007_02221974;
    if (func_020e31e0() == 0) {
        var_r1 = &data_ov007_02221224;
    } else {
        var_r1 = &data_ov007_02220ea0;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = var_r1;
    M2C_FIELD(temp_r0, void **, 0x38) = NULL;
    M2C_FIELD(temp_r0, s8 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x3E) = -0x8000;
    M2C_FIELD(temp_r0, s16 *, 0x40) = -0x8000;
    M2C_FIELD(temp_r0, void **, 0x44) = NULL;
    data_ov007_02221e0c = var_r5;
    func_02007e98(0, &data_ov007_02221e10, 0x44);
    var_r9 = &data_ov007_02221e10;
    var_r8 = 0;
    while ((*var_r5 != 0) && (var_r8 < 0x10U)) {
        if ((func_02099ae8(var_r5) != 0) || (func_02099b00(var_r5) != 0)) {
            func_02008048(var_r5, var_r9, 2);
            var_r5 += 2;
        } else {
            func_02008048(var_r5, var_r9, 1);
            var_r5 += 1;
        }
        var_r8 += 1;
        var_r9 = (M2C_UNK *)((u8 *)var_r9 + 4);

    }
    temp_r0_2 = InitOv007Text(func_02082028(0x24));
    M2C_FIELD(temp_r0, void **, 0x38) = temp_r0_2;
    temp_r0_4 = func_02082028(0x2C);
    if (temp_r0_4 != NULL) {
        M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = &data_02129870;
        M2C_FIELD(temp_r0_4, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_4, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_4, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_4, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_4, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_4, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_4, Ov006C24Flags *, 0x20).active = 0;
        M2C_FIELD(temp_r0_4, Ov006C24Flags *, 0x20).mode = 0;
        M2C_FIELD(temp_r0_4, Ov006C24Flags *, 0x20).kind = 2;
        M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_4;
}

void *func_ov007_0221f458(void *arg0) {
    M2C_UNK func_02082040(void *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_ov007_02221974;
    void *temp_r4;
    void *temp_r0;

    M2C_FIELD(arg0, void **, 0) = &data_ov007_02221974;
    temp_r4 = M2C_FIELD(arg0, void **, 0x38);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
    }
    func_02082040(arg0);
    return arg0;
}

void *func_ov007_0221f4b0(void *arg0) {
    M2C_UNK func_02082040(void *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_ov007_02221974;
    void *temp_r4;
    void *temp_r0;

    M2C_FIELD(arg0, void **, 0) = &data_ov007_02221974;
    temp_r4 = M2C_FIELD(arg0, void **, 0x38);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
    }
    
    return arg0;
}

