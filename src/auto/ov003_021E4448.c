/* 36 functions from 0x021E4448 to 0x021E5118 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021e450c(void) {

}

void func_ov003_021e4610(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021e4624(void) {
    M2C_UNK func_ov003_021e2518();
    func_ov003_021e2518();
}

void func_ov003_021e4630(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021e4644(void *arg0) {
    M2C_UNK func_02088d94(s32);
    M2C_UNK func_02088f1c(s32);
    void *temp_ip;
    void *temp_r1;
    void *temp_r5;

    temp_ip = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(temp_ip, s16 *, 0xE) = 0x100;
    M2C_FIELD(temp_ip, s16 *, 0x10) = 0;
    M2C_FIELD(temp_ip, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_ip, u16 *, 2) = (u16) M2C_FIELD(temp_ip, u16 *, 4);
    temp_r1 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r1, s16 *, 0xE) = -0x20;
    M2C_FIELD(temp_r1, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r1, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r1, u16 *, 2) = (u16) M2C_FIELD(temp_r1, u16 *, 4);
    func_02088d94(M2C_FIELD(arg0, s32 *, 0x4C));
    func_02088f1c(M2C_FIELD(arg0, s32 *, 0x58));
    temp_r5 = M2C_FIELD(arg0, void **, 0x44);
    func_02088f1c(M2C_FIELD(temp_r5, s32 *, 0));
    func_02088f1c(M2C_FIELD(temp_r5, s32 *, 4));
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov003_021e46bc(void) {
    M2C_UNK func_ov003_021e2628();
    func_ov003_021e2628();
}

void func_ov003_021e46c8(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

u32 func_ov003_021e46dc(void *arg0) {
    u32 func_02088ff4(s32);
    s16 func_020a8ff4(void *);
    u32 temp_r0;
    void *temp_r4;
    void *temp_r5;
    void *temp_r5_2;

    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x60) << 0x18) >> 0x1F;
    if (temp_r0 == 0) {
        return temp_r0;
    }
    temp_r5 = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(temp_r5, s16 *, 0xE) = func_020a8ff4(temp_r5);
    M2C_FIELD(temp_r5, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r5, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r5, u16 *, 2) = (u16) M2C_FIELD(temp_r5, u16 *, 4);
    temp_r5_2 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r5_2, s16 *, 0xE) = func_020a8ff4(temp_r5_2);
    M2C_FIELD(temp_r5_2, s16 *, 0x10) = -0x20;
    M2C_FIELD(temp_r5_2, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r5_2, u16 *, 2) = (u16) M2C_FIELD(temp_r5_2, u16 *, 4);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    temp_r4 = M2C_FIELD(arg0, void **, 0x44);
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0));
    return func_02088ff4(M2C_FIELD(temp_r4, s32 *, 4));
}

void func_ov003_021e4764(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021e4778(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x3C);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e47a4(void) {
    M2C_UNK func_ov003_021e4448();
    func_ov003_021e4448();
}

void func_ov003_021e47b0(void) {
    M2C_UNK func_ov003_021e4510();
    func_ov003_021e4510();
}

void func_ov003_021e48dc(void) {
    M2C_UNK func_ov003_021f14a0();
    func_ov003_021f14a0();
}

void func_ov003_021e48e8(void *arg0) {
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    func_ov003_021f1bd4();
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
}

s32 func_ov003_021e4e58(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

M2C_UNK **func_ov003_021e4e6c(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_02082040();
    extern M2C_UNK data_ov003_0220f45c;
    u8 var_r4;

    *arg0 = &data_ov003_0220f45c;
    var_r4 = 0;
    do {
        if (M2C_FIELD(((s32)arg0 + (var_r4 * 4)), s32 *, 0xC) != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while ((u32) var_r4 < 0xBU);
    func_02082040(arg0);
    return arg0;
}

M2C_UNK **func_ov003_021e4fec(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    extern M2C_UNK data_ov003_0220f45c;
    u8 var_r4;

    *arg0 = &data_ov003_0220f45c;
    var_r4 = 0;
    do {
        if (M2C_FIELD(((s32)arg0 + (var_r4 * 4)), s32 *, 0xC) != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while ((u32) var_r4 < 0xBU);
    return arg0;
}

void func_ov003_021e5030(void) {

}

s32 func_ov003_021e5034(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_021e5048(void) {

}

s32 func_ov003_021e504c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

#pragma peephole off
#pragma interworking off
void func_ov003_021e5060(s32 arg0) {
    M2C_UNK func_ov003_021e4eb8(s32);
    func_ov003_021e4eb8(arg0 + 0xFFFFFFCC);
}
#pragma interworking reset
#pragma peephole reset
s32 func_ov003_021e50e0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

