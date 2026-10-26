/* 3 functions from 0x021F66D4 to 0x021F7164 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021f66d4(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_02084d3c(s32 *, M2C_UNK);
    M2C_UNK func_02084d88(s32 *, M2C_UNK);
    M2C_UNK func_02084e74();
    s32 buffer[9];

    if (func_02084d3c(buffer, 0x24) == 0) {
        return;
    }
    buffer[0] = 0;
    buffer[1] = 0;
    func_02084d88(buffer, 0x24);
    func_02084e74();
    func_01ffa6fc(arg0);
}

void func_ov003_021f6724(void *arg0) {
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_ov003_021f8c20(void *);
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x68);
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 4));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 8));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0xC));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0x10));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0x14));
    func_ov003_021f8c20(arg0);
}
