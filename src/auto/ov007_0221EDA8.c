/* 10 functions from 0x0221EDA8 to 0x0221F500 (ov007), found by ds-decomp. */
#include "common.h"

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

