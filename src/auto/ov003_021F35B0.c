/* 18 functions from 0x021F35B0 to 0x021F40A8 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021f35b0(void *arg0) {
    void func_ov003_021f163c(void *, u8, s32, s32, s32);
    void *ptr = M2C_FIELD(arg0, void **, 0x40);
    func_ov003_021f163c(arg0, M2C_FIELD(ptr, u8 **, 8)[M2C_FIELD(ptr, s8 *, 5)], 0, 0, 0);
}

void func_ov003_021f35d8(void *arg0) {
    M2C_UNK func_ov003_021f13ec(M2C_UNK);
    M2C_FIELD(arg0, s8 *, 0x44) = 0;
    M2C_FIELD(arg0, s8 *, 0x34) = 4;
    func_ov003_021f13ec(0);
}

void func_ov003_021f35f8(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    s32 func_0208471c();
    s32 func_0208477c();
    s32 func_020d4810();
    M2C_UNK func_ov003_021f1bd4();
    M2C_FIELD(arg0, s8 *, 0x34) = 2;
    if (func_020d4810() != 0) {
        func_ov003_021f1bd4();
        return;
    }
    func_ov003_021f1be8();
    if ((func_0208471c() == 0) && (func_0208477c() == 0)) {
        return;
    }
    func_01ffa8c4(arg0, 5);
}

void func_ov003_021f3648(void *arg0) {
    M2C_UNK func_02085054(M2C_UNK, M2C_UNK, void *);
    M2C_UNK func_02086330();
    M2C_UNK func_020d47f0();
    M2C_UNK func_ov003_021f182c();
    M2C_UNK func_ov003_021f1be8();
    func_ov003_021f1be8();
    func_020d47f0();
    func_02086330();
    func_02085054(0, 0x6E0, arg0);
    if (M2C_FIELD(arg0, u8 *, 0x44) != 0) {
        return;
    }
    func_ov003_021f182c();
    M2C_FIELD(arg0, u8 *, 0x44) = 1U;
}

void *func_ov003_021f3cec(void *obj) {
    extern M2C_UNK data_ov003_0220fdac;
    extern void **gCurrentMap;
    s32 func_020c79ec(void);
    void func_020c8664(u16, s32);
    void func_ov003_021f140c(s32);
    s32 func_ov003_021f1608(void);
    void func_ov003_021f1858(void);
    void func_ov003_021f18a4(void);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    M2C_UNK func_02082040();
    void *base;
    void *inner;
    s32 mode_result;

    M2C_FIELD(obj, void **, 0) = &data_ov003_0220fdac;
    base = (u8 *)*gCurrentMap + 0x5120;
    func_020c8664(M2C_FIELD(base, u16 *, 0x22), func_020c79ec());
    M2C_FIELD(obj, u8 *, 0x34) = 3;
    inner = M2C_FIELD(obj, void **, 0x40);
    switch (M2C_FIELD(inner, u8 **, 8)[M2C_FIELD(inner, s8 *, 5)]) {
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            mode_result = 1;
            break;
        default:
            mode_result = 0;
            break;
    }
    if (mode_result) {
        func_ov003_021f140c(4);
    } else {
        if (!func_ov003_021f1608()) {
            func_ov003_021f1858();
            M2C_FIELD(obj, u8 *, 0x44) = 0;
        }
        func_ov003_021f18a4();
    }
    func_020af1e4();
    func_ov003_021f1a58();
    func_02082040(M2C_FIELD(obj, void **, 0x38));
    func_02082040(M2C_FIELD(obj, void **, 0x3C));
    inner = M2C_FIELD(obj, void **, 0x40);
    if (inner) {
        ((void (*)(void *))M2C_FIELD(M2C_FIELD(inner, void **, 0), void **, 4))(inner);
    }
    func_02082040(obj);
    return obj;
}

s32 func_ov003_021f3df4(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

/* Tears down / reinitialises an object: swaps its vtable, refreshes display-related state, checks its mode and either re-enters mode 4 or does a soft reset, then releases resources and invokes its destructor. */
void *func_ov003_021f3e08(void *obj) {
    extern M2C_UNK data_ov003_0220fdac;
    extern void **gCurrentMap;
    s32 func_020c79ec(void);
    void func_020c8664(u16, s32);
    void func_ov003_021f140c(s32);
    s32 func_ov003_021f1608(void);
    void func_ov003_021f1858(void);
    void func_ov003_021f18a4(void);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    M2C_UNK func_02082040();
    void *base;
    void *inner;
    s32 mode_result;

    M2C_FIELD(obj, void **, 0) = &data_ov003_0220fdac;
    base = (u8 *)*gCurrentMap + 0x5120;
    func_020c8664(M2C_FIELD(base, u16 *, 0x22), func_020c79ec());
    M2C_FIELD(obj, u8 *, 0x34) = 3;
    inner = M2C_FIELD(obj, void **, 0x40);
    switch (M2C_FIELD(inner, u8 **, 8)[M2C_FIELD(inner, s8 *, 5)]) {
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            mode_result = 1;
            break;
        default:
            mode_result = 0;
            break;
    }
    if (mode_result) {
        func_ov003_021f140c(4);
    } else {
        if (!func_ov003_021f1608()) {
            func_ov003_021f1858();
            M2C_FIELD(obj, u8 *, 0x44) = 0;
        }
        func_ov003_021f18a4();
    }
    func_020af1e4();
    func_ov003_021f1a58();
    func_02082040(M2C_FIELD(obj, void **, 0x38));
    func_02082040(M2C_FIELD(obj, void **, 0x3C));
    inner = M2C_FIELD(obj, void **, 0x40);
    if (inner) {
        ((void (*)(void *))M2C_FIELD(M2C_FIELD(inner, void **, 0), void **, 4))(inner);
    }
    return obj;
}

void func_ov003_021f3f08(void) {

}

u8 func_ov003_021f3f0c(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

s32 func_ov003_021f3f24(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

s32 func_ov003_021f3f5c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    if (arg0 + arg2 < arg4 || arg4 + arg6 < arg0) return 0;
    if (arg1 + arg3 < arg5 || arg5 + arg7 < arg1) return 0;
    return 1;
}

void func_ov003_021f3fa0(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_r0;
    s16 temp_r0_2;
    s32 temp_gt;
    s32 temp_gt_2;
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 < arg1) {
        do {
            temp_r0 = var_r0 + (arg2 - arg1);
            temp_gt = arg1 > (s32) temp_r0;
            var_r0 = (s32) temp_r0;
        } while (temp_gt);
    }
    if (var_r0 < arg2) {
        return;
    }
    do {
        temp_r0_2 = var_r0 - (arg2 - arg1);
        temp_gt_2 = arg2 > (s32) temp_r0_2;
        var_r0 = (s32) temp_r0_2;
    } while (!temp_gt_2);
}

s16 func_ov003_021f3fe4(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 < arg1) {
        var_r0 += arg2 - arg1;
    } else if (var_r0 >= arg2) {
        var_r0 -= arg2 - arg1;
    }
    return (s16) var_r0;
}

u8 func_ov003_021f400c(void) {
    s32 func_020846a4();
    u32 func_02084a0c();
    s32 result;
    if (func_020846a4() && func_02084a0c() <= 1U) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_021f4038(void) {
    s32 func_020846a4();
    s32 func_0208485c();
    s32 result;
    if (func_020846a4() && func_0208485c()) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_021f4064(void) {
    s32 func_020846a4();
    s32 func_02084890();
    s32 result;
    if (func_020846a4() && func_02084890()) result = 1;
    else result = 0;
    return result;
}

void func_ov003_021f4090(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x4D4C5342, arg0);
}

