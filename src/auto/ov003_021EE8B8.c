/* 3 functions from 0x021EE8B8 to 0x021EF758 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021ef1e8(void *arg0) {
    void func_01ffa6fc(void *);
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0xC) {
        func_01ffa6fc(arg0);
    }
    M2C_FIELD(arg0, u8 *, 0x38)++;
}
