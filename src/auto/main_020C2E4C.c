/* 10 functions from 0x020C2E4C to 0x020C3D34 (main), found by ds-decomp. */
#include "common.h"

s32 func_020c2e4c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    void *func_02082028(u32);
    void *func_020e34bc(u32);
    extern M2C_UNK data_02129794;
    extern M2C_UNK data_02129890;
    extern M2C_UNK data_02129870;
    typedef struct { u8 active:1; u8 mode:4; u8 kind:3; } Ov006C24Flags;
    void *obj;
    void *p;
    volatile u8 *qp;
    u8 tmp;
    u8 r3v;
    s32 diff;

    obj = func_01ffa3dc(&data_02129794, 7);
    if (obj != 0) {
        M2C_FIELD(obj, void **, 0) = &data_02129890;
        M2C_FIELD(obj, u8 *, 0x34) = 0;
        M2C_FIELD(obj, u8 *, 0x35) = 0;
        M2C_FIELD(obj, u8 *, 0x36) = 0;
        M2C_FIELD(obj, u8 *, 0x39) = arg4;
        M2C_FIELD(obj, u32 *, 0x3c) = 0;
        M2C_FIELD(obj, u32 *, 0x40) = 0;
        M2C_FIELD(obj, u32 *, 0x44) = 0;
        M2C_FIELD(obj, u32 *, 0x48) = 0;
        M2C_FIELD(obj, u32 *, 0x4c) = 0;
        qp = (volatile u8 *)obj + 0x50;
        tmp = *qp;
        r3v = (u8)(tmp & ~1);
        *qp = r3v;
        tmp = (u8)(r3v & 0xff);
        tmp = (u8)(tmp & ~2);
        tmp = (u8)(tmp & 0xff);
        *qp = (u8)(tmp & ~0xfc);
        p = func_02082028(6);
        if (p != 0) {
            M2C_FIELD(p, u8 *, 0) = (u8)arg0;
            M2C_FIELD(p, u8 *, 1) = (u8)arg1;
            M2C_FIELD(p, u8 *, 2) = (u8)arg2;
            M2C_FIELD(p, u8 *, 3) = (u8)arg3;
            M2C_FIELD(p, u8 *, 4) = arg4;
            M2C_FIELD(p, u8 *, 5) = arg5;
        }
        M2C_FIELD(obj, void **, 0x40) = p;
        p = func_02082028(0x2C);
        if (p != 0) {
            M2C_FIELD(p, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(p, u8 *, 4) = 0;
            M2C_FIELD(p, u16 *, 0x12) = 0;
            M2C_FIELD(p, u8 *, 0x14) = 8;
            M2C_FIELD(p, u8 *, 0x15) = 8;
            M2C_FIELD(p, u8 *, 0x16) = 1;
            M2C_FIELD(p, u8 *, 0x17) = 8;
            M2C_FIELD(p, u8 *, 0x18) = 8;
            M2C_FIELD(p, Ov006C24Flags *, 0x20).active = 0;
            M2C_FIELD(p, Ov006C24Flags *, 0x20).mode = 0;
            M2C_FIELD(p, Ov006C24Flags *, 0x20).kind = 2;
            M2C_FIELD(p, u8 *, 0x21) = 0;
            M2C_FIELD(p, u32 *, 0x24) = 0;
            M2C_FIELD(p, u8 *, 0x28) = (u8)(M2C_FIELD(p, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(p, u8 *, 0x29) = 0;
        }
        M2C_FIELD(obj, void **, 0x3c) = p;
        diff = (s32)(unsigned char)arg5 - (s32)(unsigned char)arg4;
        if (diff < 3) {
            M2C_FIELD(obj, u8 *, 0x37) = 6;
        } else {
            diff = diff - 3;
            diff = diff + diff * 2;
            diff = diff + 6;
            M2C_FIELD(obj, u8 *, 0x37) = (u8)diff;
        }
        M2C_FIELD(obj, u8 *, 0x38) = (u8)(M2C_FIELD(obj, u8 *, 0x37) + 0x2D);
        p = func_02082028(0x12);
        if (p != 0) {
            M2C_FIELD(p, u8 *, 0) = 4;
            M2C_FIELD(p, u8 *, 1) = 0;
            M2C_FIELD(p, u16 *, 2) = 0;
            M2C_FIELD(p, u16 *, 4) = 0;
            M2C_FIELD(p, s16 *, 6) = 1;
            M2C_FIELD(p, s16 *, 8) = 0;
            M2C_FIELD(p, s16 *, 0xA) = 1;
            M2C_FIELD(p, s16 *, 0xC) = 1;
            M2C_FIELD(p, s16 *, 0xE) = 0;
            M2C_FIELD(p, s16 *, 0x10) = 0;
            M2C_FIELD(p, u16 *, 2) = M2C_FIELD(p, u16 *, 4);
        }
        M2C_FIELD(obj, void **, 0x44) = p;
        p = func_02082028(0x12);
        if (p != 0) {
            M2C_FIELD(p, u8 *, 0) = 4;
            M2C_FIELD(p, u8 *, 1) = 0;
            M2C_FIELD(p, u16 *, 2) = 0;
            M2C_FIELD(p, u16 *, 4) = 0;
            M2C_FIELD(p, s16 *, 6) = 1;
            M2C_FIELD(p, s16 *, 8) = 0;
            M2C_FIELD(p, s16 *, 0xA) = 1;
            M2C_FIELD(p, s16 *, 0xC) = 1;
            M2C_FIELD(p, s16 *, 0xE) = 0;
            M2C_FIELD(p, s16 *, 0x10) = 0;
            M2C_FIELD(p, u16 *, 2) = M2C_FIELD(p, u16 *, 4);
        }
        M2C_FIELD(obj, void **, 0x48) = p;
        p = func_020e34bc(0x100);
        M2C_FIELD(obj, void **, 0x4c) = p;
        M2C_FIELD(obj, u8 *, 0x36) = 0;
    }
    return 0;
}

u8 func_020c306c(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02129794;
    u8 var_r0;

    if (func_01ffa770(&data_02129794) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020c3090(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    void *func_02082028(u32);
    void *func_020e34bc(u32);
    extern M2C_UNK data_02129794;
    extern M2C_UNK data_02129890;
    extern M2C_UNK data_02129870;
    typedef struct { u8 active:1; u8 mode:4; u8 kind:3; } Ov006C24Flags;
    void *obj;
    void *p;
    volatile u8 *qp;
    u8 tmp;
    u8 r3v;
    s32 a5;
    s32 a4;
    s32 diff;

    obj = func_01ffa3dc(&data_02129794, 7);
    if (obj != 0) {
        M2C_FIELD(obj, void **, 0) = &data_02129890;
        M2C_FIELD(obj, u8 *, 0x34) = 0;
        M2C_FIELD(obj, u8 *, 0x35) = 0;
        M2C_FIELD(obj, u8 *, 0x36) = 0;
        M2C_FIELD(obj, u8 *, 0x39) = arg4;
        M2C_FIELD(obj, u32 *, 0x3c) = 0;
        M2C_FIELD(obj, u32 *, 0x40) = 0;
        M2C_FIELD(obj, u32 *, 0x44) = 0;
        M2C_FIELD(obj, u32 *, 0x48) = 0;
        M2C_FIELD(obj, u32 *, 0x4c) = 0;
        qp = (volatile u8 *)obj + 0x50;
        tmp = *qp;
        r3v = (u8)(tmp & ~1);
        *qp = r3v;
        tmp = (u8)(r3v & 0xff);
        tmp = (u8)(tmp & ~2);
        tmp = (u8)(tmp & 0xff);
        *qp = (u8)(tmp & ~0xfc);
        p = func_02082028(6);
        if (p != 0) {
            M2C_FIELD(p, u8 *, 0) = (u8)arg0;
            M2C_FIELD(p, u8 *, 1) = (u8)arg1;
            M2C_FIELD(p, u8 *, 2) = (u8)arg2;
            M2C_FIELD(p, u8 *, 3) = (u8)arg3;
            M2C_FIELD(p, u8 *, 4) = arg4;
            M2C_FIELD(p, u8 *, 5) = arg5;
        }
        M2C_FIELD(obj, void **, 0x40) = p;
        p = func_02082028(0x2C);
        if (p != 0) {
            M2C_FIELD(p, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(p, u8 *, 4) = 0;
            M2C_FIELD(p, u16 *, 0x12) = 0;
            M2C_FIELD(p, u8 *, 0x14) = 8;
            M2C_FIELD(p, u8 *, 0x15) = 8;
            M2C_FIELD(p, u8 *, 0x16) = 1;
            M2C_FIELD(p, u8 *, 0x17) = 8;
            M2C_FIELD(p, u8 *, 0x18) = 8;
            M2C_FIELD(p, Ov006C24Flags *, 0x20).active = 0;
            M2C_FIELD(p, Ov006C24Flags *, 0x20).mode = 0;
            M2C_FIELD(p, Ov006C24Flags *, 0x20).kind = 2;
            M2C_FIELD(p, u8 *, 0x21) = 0;
            M2C_FIELD(p, u32 *, 0x24) = 0;
            M2C_FIELD(p, u8 *, 0x28) = (u8)(M2C_FIELD(p, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(p, u8 *, 0x29) = 0;
        }
        M2C_FIELD(obj, void **, 0x3c) = p;
        a5 = (s32)(unsigned char)arg5;
        a4 = (s32)(unsigned char)arg4;
        diff = a5 - a4;
        if (diff < 3) {
            M2C_FIELD(obj, u8 *, 0x37) = 6;
        } else {
            diff = diff - 3;
            diff = diff + diff * 2;
            diff = diff + 6;
            M2C_FIELD(obj, u8 *, 0x37) = (u8)diff;
        }
        M2C_FIELD(obj, u8 *, 0x38) = (u8)(M2C_FIELD(obj, u8 *, 0x37) + 0x2D);
        p = func_02082028(0x12);
        if (p != 0) {
            M2C_FIELD(p, u8 *, 0) = 4;
            M2C_FIELD(p, u8 *, 1) = 0;
            M2C_FIELD(p, u16 *, 2) = 0;
            M2C_FIELD(p, u16 *, 4) = 0;
            M2C_FIELD(p, s16 *, 6) = 1;
            M2C_FIELD(p, s16 *, 8) = 0;
            M2C_FIELD(p, s16 *, 0xA) = 1;
            M2C_FIELD(p, s16 *, 0xC) = 1;
            M2C_FIELD(p, s16 *, 0xE) = 0;
            M2C_FIELD(p, s16 *, 0x10) = 0;
            M2C_FIELD(p, u16 *, 2) = M2C_FIELD(p, u16 *, 4);
        }
        M2C_FIELD(obj, void **, 0x44) = p;
        p = func_02082028(0x12);
        if (p != 0) {
            M2C_FIELD(p, u8 *, 0) = 4;
            M2C_FIELD(p, u8 *, 1) = 0;
            M2C_FIELD(p, u16 *, 2) = 0;
            M2C_FIELD(p, u16 *, 4) = 0;
            M2C_FIELD(p, s16 *, 6) = 1;
            M2C_FIELD(p, s16 *, 8) = 0;
            M2C_FIELD(p, s16 *, 0xA) = 1;
            M2C_FIELD(p, s16 *, 0xC) = 1;
            M2C_FIELD(p, s16 *, 0xE) = 0;
            M2C_FIELD(p, s16 *, 0x10) = 0;
            M2C_FIELD(p, u16 *, 2) = M2C_FIELD(p, u16 *, 4);
        }
        M2C_FIELD(obj, void **, 0x48) = p;
        p = func_020e34bc(0x100);
        M2C_FIELD(obj, void **, 0x4c) = p;
        M2C_FIELD(obj, u8 *, 0x36) = 1;
    }
}

void func_020c32b0(void) {
    void func_020c32bc();
    func_020c32bc();
}

void func_020c32bc(void) {
    s32 func_020d19b4();
    M2C_UNK func_0208fe30(s32);
    if (func_020d19b4() != 0) {
        func_0208fe30(0xE1);
        return;
    }
    func_0208fe30(0xE3);
}

void *func_020c32e4(void *arg0) {
    M2C_UNK func_02082040();
    M2C_UNK func_020e35cc();
    extern M2C_UNK data_02129890;
    void *p;
    M2C_FIELD(arg0, void **, 0) = &data_02129890;
    p = M2C_FIELD(arg0, void **, 0x40);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x3C);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(arg0, void **, 0x44);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x48);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x4C);
    if (p != NULL) func_020e35cc(p);
    func_02082040(arg0);
    return arg0;
}

s32 func_020c3360(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void *func_020c3374(void *arg0) {
    M2C_UNK func_02082040();
    M2C_UNK func_020e35cc();
    extern M2C_UNK data_02129890;
    void *p;
    M2C_FIELD(arg0, void **, 0) = &data_02129890;
    p = M2C_FIELD(arg0, void **, 0x40);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x3C);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(arg0, void **, 0x44);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x48);
    if (p != NULL) func_02082040(p);
    p = M2C_FIELD(arg0, void **, 0x4C);
    if (p != NULL) func_020e35cc(p);
    
    return arg0;
}

void func_020c33e8(void) {

}
