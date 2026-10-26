/* 9 functions from 0x0204E408 to 0x0204EEE8 (main), found by ds-decomp. */
#include "common.h"

void func_0204e7f0(void **arg0) {
    M2C_UNK func_020377c4(void *);
    M2C_UNK func_02048dc4(s32);
    M2C_UNK func_02052038(void **, M2C_UNK);
    void *temp_r4;

    temp_r4 = *arg0;
    func_02052038(arg0, 1);
    func_020377c4(M2C_FIELD(temp_r4, void **, 0x460));
    M2C_FIELD(temp_r4, void **, 0x460) = NULL;
    func_02048dc4(M2C_FIELD(temp_r4, s32 *, 0x428));
    func_020377c4(temp_r4);
    *arg0 = NULL;
}

s32 func_0204ee40(void **arg0, void *arg1) {
    M2C_UNK func_0204fea0(void **, void *, M2C_UNK *);
    M2C_UNK func_0204fed0(void **, void *, s32);
    extern M2C_UNK data_020fdd94;
    extern M2C_UNK data_020fdda0;
    extern M2C_UNK data_020fddac;
    extern M2C_UNK data_020fddbc;
    extern M2C_UNK data_020fddc4;
    void *temp_r4;

    temp_r4 = *arg0;
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdd94);
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdda0);
    func_0204fed0(arg0, temp_r4 + 0x1F4, M2C_FIELD(temp_r4, s32 *, 0x198));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fddac);
    func_0204fed0(arg0, temp_r4 + 0x1F4, M2C_FIELD(arg1, s32 *, 0));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fddbc);
    func_0204fea0(arg0, temp_r4 + 0x1F4, M2C_FIELD(arg1, M2C_UNK **, 0x10));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fddc4);
    return 0;
}

