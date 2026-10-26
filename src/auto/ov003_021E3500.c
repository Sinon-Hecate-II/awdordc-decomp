/* 7 functions from 0x021E3500 to 0x021E4448 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021e36cc(void *arg0) {
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    func_ov003_021f1bd4();
    if (M2C_FIELD(arg0, u8 *, 0x39) != 0) {
        func_02088da8(M2C_FIELD(arg0, s32 *, 0x4C));
    }
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021e3708(void) {
    M2C_UNK func_01ffa6fc();
    func_01ffa6fc();
}
