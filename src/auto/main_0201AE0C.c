/* 15 functions from 0x0201AE0C to 0x0201BDE0 (main), found by ds-decomp. */
#include "common.h"

void func_0201b338(void *arg0, void *arg1, void *arg2) {
    M2C_UNK func_0201a588(M2C_UNK, M2C_UNK);
    M2C_UNK func_0201a63c(M2C_UNK);
    M2C_UNK func_0201b140(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_02137290;
    void *var_r4;
    u16 temp_lr;
    u32 temp_val;
    u32 sp_0;
    u32 sp_4;

    var_r4 = (void *) M2C_FIELD(arg2, u32 *, 0x4C);
    M2C_FIELD(var_r4, s16 *, 0x22) = 8;
    M2C_FIELD(var_r4, s16 *, 0x26) = (s16) ((u32)(&data_0212dca4) >> 4); // wait, ldr r2, [pc, #0x88] -> ldr r2, [data_0212dca4 + 4] or something. Let's use extern u32 data_02137290; extern u32 data_0212dca4;
}

void func_0201b798(void *arg0) {
    M2C_UNK func_02008048(M2C_UNK *, void *, M2C_UNK);
    M2C_UNK func_0201a824(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_02137778;
    u16 temp_ip;
    u16 temp_ip_2;

    M2C_FIELD(arg0, s16 *, 6) = 0x200;
    func_02008048(arg0 + 8, arg0 + 0x12, 0xA);
    func_02008048(&data_02137778, arg0 + 8, 6);
    temp_ip = (u16) ((u32) M2C_FIELD(&data_02137290, u32 *, 0x50) >> 0x10);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((temp_ip >> 8) | (temp_ip << 8));
    temp_ip_2 = (u16) M2C_FIELD(&data_02137290, u32 *, 0x50);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((temp_ip_2 >> 8) | (temp_ip_2 << 8));
    func_02008048(arg0 + 0x12, arg0 - 0xE, 6);
    func_02008048(&data_02137778, arg0 - 8, 6);
    func_0201a824(arg0 - 0xE, 0x2A, 0, 0);
}

s32 func_0201bb68(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 != -1) && (arg1 != 0) && (arg1 != -1)) {
        return 1;
    }
    return 0;
}

s32 func_0201bd2c(void *arg0, void *arg1, void *arg2) {
    s32 var_ip;
    s32 var_r3;
    s32 var_r5;
    s32 var_r6;
    u16 temp_lr;
    u16 temp_lr_2;
    u16 temp_lr_3;
    u16 temp_r4_2;
    u8 temp_r4;

    temp_r4 = M2C_FIELD(arg2, u8 *, 8);
    var_r3 = 0;
    var_r5 = 0;
    if ((temp_r4 != 0xA) && (temp_r4 != 0xB)) {
        var_r5 = 1;
    }
    var_ip = 0;
    var_r6 = 0;
    if (var_r5 != 0) {
        temp_lr = M2C_FIELD(arg1, u16 *, 2);
        if (M2C_FIELD(arg2, u16 *, 0xA) == (u16) ((temp_lr >> 8) | (temp_lr << 8))) {
            var_r6 = 1;
        }
    }
    if (var_r6 != 0) {
        temp_lr_2 = M2C_FIELD(arg1, u16 *, 0);
        if (M2C_FIELD(arg2, u16 *, 0x18) == (u16) ((temp_lr_2 >> 8) | (temp_lr_2 << 8))) {
            var_ip = 1;
        }
    }
    if (var_ip != 0) {
        temp_lr_3 = M2C_FIELD(arg0, u16 *, 0xC);
        temp_r4_2 = M2C_FIELD(arg0, u16 *, 0xE);
        if (M2C_FIELD(arg2, s32 *, 0x1C) == ((u16) ((temp_r4_2 >> 8) | (temp_r4_2 << 8)) | ((u16) ((temp_lr_3 >> 8) | (temp_lr_3 << 8)) << 0x10))) {
            var_r3 = 1;
        }
    }
    return var_r3;
}

