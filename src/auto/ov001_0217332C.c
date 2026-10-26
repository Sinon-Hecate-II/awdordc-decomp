/* 12 functions from 0x0217332C to 0x0217416C (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_0217355c(u8 arg0, s32 arg1, s32 arg2, u32 arg3);
void func_ov001_0217385c(s32 arg0, s32 arg1);
s32 *func_ov001_0218a24c(s32 arg0, s32 arg1);
void func_ov001_0218c924(void *arg0, void *arg1);
extern void *data_ov001_02193d1c;
extern u8 data_ov001_0218f36c[];
void func_ov001_02173ebc(void *arg0);
void func_ov001_02173f30(void *arg0);
void func_ov001_02173fa4(void *arg0);
void func_ov001_02174018(void *arg0);
extern M2C_UNK func_ov001_0217408c;

void func_ov001_021737d8(s8 arg0) {
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;

    var_r5 = 0;
    var_r6 = 0;
    var_r4 = 0;
    var_r7 = 0;
    M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11D) = arg0;
    do {
        func_ov001_0217355c(arg0, var_r4, *(u16*)(data_ov001_0218f36c + var_r7 * 4 + 2), 0);
        var_r4 += 1;
        var_r7 += 0xC;
    } while (var_r4 < 4);
    if (arg0 == 2) {
        var_r5 = 1;
    } else if (arg0 == 1) {
        var_r6 = 1;
    }
    func_ov001_0217385c(0x2F, var_r5);
    func_ov001_0217385c(0x30, var_r6);
}

void func_ov001_02173e38(void *arg0) {
    s32 sp0;
    u32 sp4;
    s32 temp_r3;

    temp_r3 = *func_ov001_0218a24c(M2C_FIELD(data_ov001_02193d1c, s32 *, 0xFC), 0);
    sp0 = (temp_r3 & 0xff) + 0xC;
    sp4 = (u32)(temp_r3 & 0x01FF0000) >> 0x10;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 4, sp0, sp4);
    if (sp0 < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02173ebc);
}

void func_ov001_02173ebc(void *arg0) {
    u32 sp4;
    s32 temp_r3;
    s32 sp0;

    temp_r3 = *(s32 *)M2C_FIELD(data_ov001_02193d1c, s32 **, 0xC0);
    sp4 = ((u32)temp_r3 & 0x01FF0000) >> 0x10;
    sp0 = (temp_r3 & 0xff) + 0xC;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, sp0, sp4);
    if (sp0 < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02173f30);
}

void func_ov001_02173f30(void *arg0) {
    s32 sp0;
    u32 sp4;
    u32 temp_ip;

    temp_ip = *(u32 *)M2C_FIELD(data_ov001_02193d1c, u32 **, 0x90);
    sp4 = (temp_ip & 0x01FF0000) >> 0x10;
    sp0 = (temp_ip & 0xff) + 0xC;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, sp0, sp4);
    if (sp0 < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02173fa4);
}

void func_ov001_02173fa4(void *arg0) {
    s32 sp0;
    u32 sp4;
    u32 temp_ip;

    temp_ip = *(u32 *)M2C_FIELD(data_ov001_02193d1c, u32 **, 0x60);
    sp4 = (temp_ip & 0x01FF0000) >> 0x10;
    sp0 = (temp_ip & 0xff) + 0xC;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 1, sp0, sp4);
    if (sp0 < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02174018);
}

void func_ov001_02174018(void *arg0) {
    s32 sp0;
    u32 sp4;
    u32 temp_ip;

    temp_ip = *(u32 *)M2C_FIELD(data_ov001_02193d1c, u32 **, 0x30);
    sp4 = (temp_ip & 0x01FF0000) >> 0x10;
    sp0 = (temp_ip & 0xff) + 0xC;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 0, sp0, sp4);
    if (sp0 < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_0217408c);
}

