/* 5 functions from 0x02089D30 to 0x0208ABC4 (main), found by ds-decomp. */
#include "common.h"

u32 func_0208a6b0(void *arg0) {
    u32 func_020846a4(void);
    u32 func_0208fe30(M2C_UNK);
    u32 func_0208ff4c(M2C_UNK);
    M2C_UNK func_0208ffe4(M2C_UNK, M2C_UNK, s32);
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_3;

    if (func_0208ff4c(4) == 0) {
        func_0208fe30(0x125);
    }
    temp_r0_3 = (u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x1D) >> 0x1D;
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    temp_r0_2 = func_020846a4();
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    func_0208ffe4(0, -1, 0x10013);
    temp_r0 = M2C_FIELD(arg0, u32 *, 0x58) | 0x4000;
    M2C_FIELD(arg0, u32 *, 0x58) = temp_r0;
    return temp_r0;
}

u32 func_0208a714(void *arg0) {
    u32 func_0208fe30(M2C_UNK);
    u32 func_0208ff4c(M2C_UNK);
    M2C_UNK func_02090034(M2C_UNK, M2C_UNK);
    u32 temp_r0;
    u32 temp_r0_2;

    temp_r0_2 = (u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x11) >> 0x1F;
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    func_02090034(0, 0);
    temp_r0 = func_0208ff4c(4);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    return func_0208fe30(0x124);
}

void func_0208ab78(void *arg0) {
    M2C_UNK func_02082770();
    M2C_UNK func_02082994();
    M2C_UNK func_020b26dc();
    M2C_UNK func_020d472c();
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x15) >> 0x1F) & 0xFF) {
        func_02082994();
        func_02082770();
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x13) >> 0x1F) & 0xFF) {
        func_020d472c();
        func_020b26dc();
    }
    func_0208a714(arg0);
}

