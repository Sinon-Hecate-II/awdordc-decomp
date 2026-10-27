/* 8 functions from 0x0217ACD4 to 0x0217BCD4 (ov000), found by ds-decomp. */
#include "common.h"

#pragma scheduling off
s32 func_ov000_0217ae9c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_01ffb454(s32);
    s32 func_ov000_0217acd4(s32);
    s32 func_ov000_021a97e0(u16, s32);
    extern void **gCurrentMap;
    extern void *data_027e00cc;
    extern void *data_027e0a98;
    extern void *data_027e0a90;
    extern s32 data_027e0a94;
    extern s8 data_027e0a8c;
    u8 state;
    void *p;
    data_027e0a94 = 0;
    data_027e0a98 = data_027e00cc + 0x28;
    data_027e0a8c = 0;
    data_027e0a90 = data_027e00cc + 0x5A0;
    M2C_FIELD(data_027e00cc, s16 *, 0x20) = arg3;
    M2C_FIELD(data_027e00cc, s16 *, 0x22) = func_ov000_021a97e0(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), arg2);
    M2C_FIELD(data_027e00cc, s8 *, 0x26) = arg2;
    func_01ffb454(arg2);
    M2C_FIELD(data_027e0a98, s8 *, 0) = arg0;
    M2C_FIELD(data_027e0a98, s8 *, 1) = arg1;
    M2C_FIELD(data_027e0a98, s8 *, 2) = 1;
    M2C_FIELD(data_027e0a98, s8 *, 3) = 0;
    p = data_027e0a98 + 4;
    data_027e0a98 = p;
    M2C_FIELD(p, s8 *, 2) = 0;
    for (;;) {
        if (data_027e0a8c == 0) {
            data_027e0a98 = data_027e00cc + 0x5A0;
            data_027e0a90 = data_027e00cc + 0x28;
            data_027e0a8c = 1;
        } else {
            data_027e0a98 = data_027e00cc + 0x28;
            data_027e0a90 = data_027e00cc + 0x5A0;
            data_027e0a8c = 0;
            data_027e0a94 = 0;
        }
        state = M2C_FIELD(data_027e0a90, u8 *, 2);
        if (state == 0) {
            M2C_FIELD(data_027e00cc, s8 *, 0x24) = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
            M2C_FIELD(data_027e00cc, s8 *, 0x25) = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
            return 0;
        }
        while (state != 0) {
            switch (state) {
            case 1:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            case 2:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            case 3:
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            case 4:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                break;
            case 5:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            }
            M2C_FIELD(data_027e0a98, s8 *, 2) = 0;
            p = data_027e0a90 + 4;
            data_027e0a90 = p;
            state = M2C_FIELD(p, u8 *, 2);
        }
    }
found:
    M2C_FIELD(data_027e00cc, s8 *, 0x24) = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
    M2C_FIELD(data_027e00cc, s8 *, 0x25) = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
    return 1;
}
#pragma scheduling reset
s32 func_ov000_0217bc34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov000_0217ab10();
    s32 func_ov000_0217ae9c(s32, s32, s32, s32);
    extern s32 (*data_ov000_021df650)();

    data_ov000_021df650 = func_ov000_0217ab10;
    if (data_ov000_021df650() == 1) {
        return 1;
    }
    return func_ov000_0217ae9c(arg0, arg1, arg2, arg3);
}

s32 func_ov000_0217bc84(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_0217ac78(s32, s32, s32);
    s32 func_ov000_0217b8f0(s32, s32, s32, s32);
    extern s32 (*data_ov000_021df650)();

    data_ov000_021df650 = func_ov000_0217ac78;
    if (data_ov000_021df650(arg0, arg1, 0) == 1) {
        return 1;
    }
    return func_ov000_0217b8f0(arg0, arg1, 0, arg2);
}
