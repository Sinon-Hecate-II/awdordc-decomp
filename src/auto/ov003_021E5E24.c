/* 35 functions from 0x021E5E24 to 0x021E6E18 (ov003), found by ds-decomp. */
#include "common.h"

M2C_UNK func_ov003_021e6204(M2C_UNK arg0) {
    M2C_UNK func_ov003_021f140c(s32);
    M2C_UNK func_ov006_02218328(M2C_UNK);
    func_ov003_021f140c(1);
    return func_ov006_02218328(arg0);
}

void func_ov003_021e6220(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

/* Sets up rendering layer 0xE1 and its dimensions for the given object. */
void func_ov003_021e6234(void *obj) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020809c0(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_0209b2b4(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    M2C_UNK func_020a68d4();
    M2C_UNK func_020a92bc(s32, s32);
    M2C_UNK func_020c12f8(s32, s32, s32, M2C_UNK);
    M2C_UNK func_020c1878(s32);
    M2C_UNK func_020cf0a8(M2C_UNK);
    M2C_UNK func_020cf278(M2C_UNK);
    s32 func_020cfbdc(M2C_UNK);
    s32 func_ov006_02217d0c();
    extern void **data_027e0058;
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *savedContext;

    func_020a68d4();
    func_020cf278(0xE1);
    func_020cf0a8(0xE1);
    M2C_FIELD(obj, s16 *, 0x62) = (s16) (M2C_FIELD(*data_027e0058, u16 *, 0x5144) * 4);
    M2C_FIELD(obj, s16 *, 0x64) = (s16) (M2C_FIELD(*data_027e0058, u16 *, 0x5146) * 4);
    func_020c1878(M2C_FIELD(obj, s32 *, 0x68) + 4);
    savedContext = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020809c0(M2C_FIELD(data_027e00c4, s32 *, 0x2C), 9, 2);
    func_0209b2b4(0, 0, 3, func_020cfbdc(0xE1), 0x9000, 0x11);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    func_01ff9ce8(0);
    func_020c12f8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 0x143, 5);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = savedContext;
    func_020a92bc(M2C_FIELD(obj, s32 *, 0x58), func_ov006_02217d0c());
}

void func_ov003_021e635c(void) {
    M2C_UNK func_ov003_021e583c();
    func_ov003_021e583c();
}

void func_ov003_021e6368(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021e637c(void *arg0) {
    M2C_UNK func_02088f1c(s32);
    void *temp_r1;
    void *temp_r3;
    void *temp_r3_2;

    temp_r3 = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(temp_r3, s16 *, 0xE) = 0x100;
    M2C_FIELD(temp_r3, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r3, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r3, u16 *, 2) = (u16) M2C_FIELD(temp_r3, u16 *, 4);
    temp_r3_2 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r3_2, s16 *, 0xE) = 0xC0;
    M2C_FIELD(temp_r3_2, s16 *, 0x10) = 0x68;
    M2C_FIELD(temp_r3_2, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r3_2, u16 *, 2) = (u16) M2C_FIELD(temp_r3_2, u16 *, 4);
    temp_r1 = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(temp_r1, s16 *, 0xE) = 0xC0;
    M2C_FIELD(temp_r1, s16 *, 0x10) = 0x90;
    M2C_FIELD(temp_r1, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r1, u16 *, 2) = (u16) M2C_FIELD(temp_r1, u16 *, 4);
    func_02088f1c(M2C_FIELD(arg0, s32 *, 0x5C));
    func_02088f1c(*M2C_FIELD(arg0, s32 **, 0x48));
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov003_021e6404(void) {
    M2C_UNK func_ov003_021e5b18();
    func_ov003_021e5b18();
}

void func_ov003_021e6410(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

void func_ov003_021e6424(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x60)) return;
}

void func_ov003_021e6430(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021e6444(void *arg0) {
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

void func_ov003_021e6470(void) {
    M2C_UNK func_ov003_021e6204();
    func_ov003_021e6204();
}

u8 func_ov003_021e647c(void *arg0) {
    s32 func_020d4810();
    M2C_FIELD(arg0, u8 *, 0x60) = 0;
    M2C_FIELD(arg0, u8 *, 0x60) = func_020d4810() == 0;
    return M2C_FIELD(arg0, u8 *, 0x60);
}

s32 func_ov003_021e6af0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_021e6b04(void) {

}

void func_ov003_021e6c28(void) {

}

u8 func_ov003_021e6cac(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

s32 func_ov003_021e6cc4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

u8 func_ov003_021e6cfc(void) {
    s32 func_020846a4();
    s32 func_0208485c();
    s32 result;
    if (func_020846a4() && func_0208485c()) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_021e6d28(void) {
    s32 func_020846a4();
    s32 func_02084890();
    s32 result;
    if (func_020846a4() && func_02084890()) result = 1;
    else result = 0;
    return result;
}

void func_ov003_021e6d54(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x4D4C5342, arg0);
}

u8 *func_ov003_021e6d6c(void *arg0) {
    extern u16 data_ov003_0220f0b8[];
    s32 var_r4 = 0;

    if (func_ov003_021e6cac(arg0, 0, 3) == 0) {
        if (func_ov003_021e6cac(arg0, 4, 7) != 0) {
            var_r4 = 1;
        } else if (func_ov003_021e6cac(arg0, 8, 0x14) != 0) {
            var_r4 = 2;
        } else if (func_ov003_021e6cac(arg0, 0x15, 0x18) != 0) {
            var_r4 = 3;
        } else if (func_ov003_021e6cac(arg0, 0x19, 0x19) != 0) {
            var_r4 = 4;
        }
    }
    return (u8 *) &data_ov003_0220f0b8[var_r4];
}

u8 func_ov003_021e6e08(void) {
    u8 *func_ov003_021e6d6c();
    return *func_ov003_021e6d6c();
}

