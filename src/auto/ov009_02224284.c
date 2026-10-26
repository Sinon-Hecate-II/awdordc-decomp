/* 36 functions from 0x02224284 to 0x0222525C (ov009), found by ds-decomp. */
#include "common.h"

s32 func_ov009_02224284(void) {
    s32 func_ov009_02224194();
    if (func_ov009_02224194() != 6) {
        return 1;
    }
    return 0;
}

u16 func_ov009_0222429c(void) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    u16 func_ov009_02222a20(u16);
    extern M2C_UNK data_ov009_022268e0;
    func_ov009_02221320(1);
    M2C_FIELD(&data_ov009_022268e0, u16 *, 2) = func_ov009_02222a20(M2C_FIELD(&data_ov009_022268e0, u16 *, 4));
    return M2C_FIELD(&data_ov009_022268e0, u16 *, 2);
}

void func_ov009_022244c0(void) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) = 0;
}

void func_ov009_022244d4(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) = 1 << arg0;
}

void func_ov009_022244ec(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) = (1 << arg0) | M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50);
}

s32 func_ov009_02224508(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 var_r2 = 1;
    if (!(M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) & (1 << arg0))) {
        var_r2 = 0;
    }
    return var_r2;
}

void func_ov009_02224528(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) = (-1 ^ (1 << arg0)) & M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50);
}

void func_ov009_0222454c(void) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x30) = 0;
}

s32 func_ov009_02224688(void) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    if (func_ov009_02224194() != 2) {
        return 0;
    }
    func_ov009_02221320(3);
    return 1;
}

s32 func_ov009_022246ac(s32 arg0) {
    extern M2C_UNK data_ov009_02226cc0;
    s32 result;
    s32 interrupt;
    u16 saved;
    result = (s32)&data_ov009_02226cc0 + 0xc8 * arg0;
    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    interrupt = saved;
    if (M2C_FIELD(result,s32 *,0xc4) == 0 ||
        M2C_FIELD(result,u16 *,0x3c) < 0x10U ||
        M2C_FIELD(result,u16 *,0x40) != 1) result = 0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = interrupt;
    return result;
}

s32 func_ov009_02224718(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x4C);
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x4C) = arg0;
    return temp_r2;
}

void func_ov009_0222496c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void *func_ov009_0222497c(void *arg0) {
    void func_ov009_02224d1c(void *);
    if (M2C_FIELD(arg0,void **,4) != NULL) {
        func_ov009_02224d1c(M2C_FIELD(arg0,void **,4));
        M2C_FIELD(arg0,s32 *,4) = 0;
    }
    return arg0;
}

s32 func_ov009_02224b8c(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x58);
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x58) = arg0;
    return temp_r2;
}

s32 func_ov009_02224ba4(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x60);
    M2C_FIELD(&data_ov009_022268e0,s32 *,0x60) = arg0;
    return old;
}

s32 func_ov009_02224bbc(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 temp_r2;

    temp_r2 = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x40);
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x40) = arg0;
    return temp_r2;
}

s32 func_ov009_02224bd4(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x1c);
    M2C_FIELD(&data_ov009_022268e0,s32 *,0x1c) = arg0;
    return old;
}

s32 func_ov009_02224bec(s32 arg0) {
 extern M2C_UNK data_ov009_022268e0;
 s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x18);
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x18) = arg0;
 return old;
}

s32 func_ov009_02224c04(s32 arg0) {
 extern M2C_UNK data_ov009_022268e0;
 s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x44);
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x44) = arg0;
 return old;
}

s32 func_ov009_02224c1c(s32 arg0) {
 extern M2C_UNK data_ov009_022268e0;
 s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x54);
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x54) = arg0;
 return old;
}

s32 func_ov009_02224c34(M2C_UNK arg0) {
    s32 func_ov009_02223d40(M2C_UNK);
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223d40(arg0) != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

s32 func_ov009_02224c70(void) {
    s32 func_ov009_02223dc0();
    s32 func_ov009_022241a4();
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223dc0() != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

s32 func_ov009_02224ca4(void) {
    s32 func_ov009_02223e5c();
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223e5c() != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

s32 func_ov009_02224cd8(void) {
    s32 func_ov009_02223ec8();
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223ec8() != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

void func_ov009_02224d0c(M2C_UNK arg0) {
    M2C_UNK func_ov009_0222132c(M2C_UNK, M2C_UNK);
    func_ov009_0222132c(arg0, 0x20);
}

void func_ov009_02224d1c(void *arg0) {
    M2C_UNK func_ov009_02221338(void *, s32);
    func_ov009_02221338(arg0, M2C_FIELD(arg0, s32 *, 8) + 0xC);
}

void *func_ov009_02224d30(void *arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6) {
 void func_02008048(s32, void *, s32);
 M2C_FIELD(arg0,s32 *,0) = 0x5F574C4D;
 M2C_FIELD(arg0,s8 *,4) = arg1;
 M2C_FIELD(arg0,u8 *,5) = (M2C_FIELD(arg0,u8 *,5) & ~0xF) | (arg2 & 0xF);
 M2C_FIELD(arg0,u8 *,5) = (M2C_FIELD(arg0,u8 *,5) & ~0xF0) | ((arg3 & 0xF) << 4);
 M2C_FIELD(arg0,u16 *,6) = arg6;
 M2C_FIELD(arg0,s32 *,8) = arg5;
 if (arg4 != 0 && arg5 != 0) func_02008048(arg4,(u8 *)arg0 + 0xC,arg5);
 return arg0;
}

s32 func_ov009_022250f8(s32 arg0) {
    extern M2C_UNK data_ov009_022269b0;
    s32 offset = arg0 * 12;
    s32 result = 0;
    M2C_UNK *ptr;
    u32 saved = ov009_disable_irq();
    if (M2C_FIELD(&data_ov009_022269b0, void **, offset) == NULL) {
        ov009_restore_irq(saved);
        return 0;
    }
    {
        u32 nested = ov009_disable_irq();
        ptr = M2C_FIELD(&data_ov009_022269b0, void **, offset);
        if (ptr == NULL) {
            (void)*(volatile u16 *)0x04000208;
            *(volatile u16 *)0x04000208 = nested;
        } else {
            (void)*(volatile u16 *)0x04000208;
            result = M2C_FIELD(ptr, s32 *, 12);
            *(volatile u16 *)0x04000208 = nested;
        }
    }
    result += 12;
    ov009_restore_irq(saved);
    return result;
}

