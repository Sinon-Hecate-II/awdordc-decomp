/* 3 functions from 0x0220ED80 to 0x0220F0B8 (ov003), found by ds-decomp. */
#include "common.h"

void *func_ov003_0220f080(void *arg0) {
    extern M2C_UNK data_ov003_02211028;
    void **temp_r0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_02211028;
    temp_r0 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    return arg0;
}

void func_ov003_0220f0b4(void) {

}
