/* 5 functions from 0x02052600 to 0x0205342C (main), found by ds-decomp. */
#include "common.h"

s32 func_02052e18(void **arg0, M2C_UNK arg1) {
    M2C_UNK func_0204fed0(void **, M2C_UNK, s32);
    extern M2C_UNK data_020fe834;
    extern M2C_UNK data_020fe84c;
    extern M2C_UNK data_020fe854;
    void *temp_r4;

    temp_r4 = *arg0;
    if ((s32) M2C_FIELD(temp_r4, s32 *, 0x448) > 0) {
        func_0204fea0(arg0, arg1, &data_020fe834);
        func_0204fed0(arg0, arg1, M2C_FIELD(temp_r4, s32 *, 0x198));
        func_0204fea0(arg0, arg1, M2C_FIELD(temp_r4, M2C_UNK **, 0x440));
        func_0204fea0(arg0, arg1, &data_020fe84c);
        M2C_FIELD(temp_r4, s32 *, 0x448) = 0;
    }
    if ((s32) M2C_FIELD(temp_r4, s32 *, 0x458) > 0) {
        func_0204fea0(arg0, arg1, &data_020fe854);
        func_0204fed0(arg0, arg1, M2C_FIELD(temp_r4, s32 *, 0x198));
        func_0204fea0(arg0, arg1, M2C_FIELD(temp_r4, M2C_UNK **, 0x450));
        func_0204fea0(arg0, arg1, &data_020fe84c);
        M2C_FIELD(temp_r4, s32 *, 0x458) = 0;
    }
    return 0;
}

s32 func_02052edc(s32 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0204fea0(s32 *, s32, M2C_UNK);
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = *arg0;
    temp_r0 = func_0204fea0(arg0, temp_r4 + 0x440, arg1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    var_r0 = func_0204fea0(arg0, temp_r4 + 0x440, arg2);
    if (var_r0 == 0) {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_02052f1c(s32 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0204fea0(s32 *, s32, M2C_UNK);
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = *arg0;
    temp_r0 = func_0204fea0(arg0, temp_r4 + 0x450, arg1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    var_r0 = func_0204fea0(arg0, temp_r4 + 0x450, arg2);
    if (var_r0 == 0) {
        var_r0 = 0;
    }
    return var_r0;
}

