/* 4 functions from 0x0220DE5C to 0x0220ED80 (ov003), found by ds-decomp. */
#include "common.h"

void *func_ov003_0220ed30(void *arg0) {
    extern M2C_UNK data_ov003_02211028;
    M2C_UNK func_02082040();
    void **temp_r0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_02211028;
    temp_r0 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    func_02082040(arg0);
    return arg0;
}

s32 func_ov003_0220ed6c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}
