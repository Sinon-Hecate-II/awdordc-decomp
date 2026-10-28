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

void func_020c33ec(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_01ffaacc(u16, u8, u16, M2C_UNK *, s32);
    s32 func_02070f24(s32, s32);
    s16 func_020719a0(s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_02098844(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    extern M2C_UNK data_02101f0c;
    extern void *data_02164094;
    extern void *data_027e00c4;
    extern void *data_027e01d8;
    u16 *sp7C;
    u16 *sp78;
    u16 *sp74;
    u16 *sp70;
    u16 *sp6C;
    u16 *sp68;
    u16 *sp64;
    u16 *sp60;
    u16 *sp5C;
    u16 *sp58;
    u16 *sp54;
    u16 *sp50;
    u16 *sp4C;
    u16 *sp48;
    u16 *sp44;
    u16 *sp40;
    u16 *sp3C;
    u16 *sp38;
    u16 *sp34;
    u16 *sp30;
    u16 *sp2C;
    u16 *sp28;
    u16 *sp24;
    u16 *sp20;
    u16 *sp1C;
    u16 *sp18;
    s32 sp14;
    void *sp10;
    s32 spC;
    s16 temp_r0_11;
    s16 temp_r0_12;
    s16 temp_r0_13;
    s16 temp_r4_12;
    s32 temp_r0;
    s32 temp_r0_10;
    s32 temp_r0_15;
    s32 temp_r0_16;
    s32 temp_r0_2;
    s32 temp_r0_8;
    s32 temp_r0_9;
    s32 temp_r4_7;
    s32 var_r0;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r9;
    s32 var_r9_2;
    u16 *temp_r0_14;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    u16 *temp_r0_7;
    u16 *temp_r1;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r2;
    u16 *temp_r3;
    u16 *temp_r3_2;
    u16 *temp_r3_3;
    u16 *temp_r3_4;
    u16 *temp_r4_10;
    u16 *temp_r4_11;
    u16 *temp_r4_2;
    u16 *temp_r4_3;
    u16 *temp_r4_4;
    u16 *temp_r4_5;
    u16 *temp_r4_9;
    u16 *temp_r6;
    u16 *temp_r6_2;
    u16 *temp_r6_3;
    u16 *temp_r6_4;
    void *temp_r4;
    void *temp_r4_6;
    void *temp_r4_8;

    sp10 = data_027e01d8;
    data_027e01d8 = data_027e00c4;
    temp_r0 = M2C_FIELD(data_02164094, s32 *, 0);
    if (temp_r0 < 0x37) {
        if (temp_r0 == 0) {
            func_01ff9ce8(3);
            func_02098844(8, 0xC, 0, M2C_FIELD(data_027e01d8, s32 *, 0x2C), 1, 0, 0);
            M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
            temp_r6 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp7C = temp_r6;
            *temp_r6 = *sp7C | 0x10;
            temp_r6_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp78 = temp_r6_2;
            *temp_r6_2 = *sp78 | 0x20;
            temp_r6_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp74 = temp_r6_3;
            *temp_r6_3 = *sp74 & ~0x40;
            temp_r6_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp70 = temp_r6_4;
            *temp_r6_4 = *sp70 | 0x80;
            temp_r1 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp6C = temp_r1;
            *temp_r1 = *sp6C | 0x100;
            M2C_FIELD(data_02164094, s32 *, 0x10) = 0xC3200000;
            M2C_FIELD(data_02164094, s16 *, 0x1C) = -0x104;
            M2C_FIELD(data_02164094, s16 *, 0x20) = 0x104;
            M2C_FIELD(data_02164094, s16 *, 0x24) = 0x10;
        }
        temp_r4 = data_02164094;
        temp_r0_2 = M2C_FIELD(temp_r4, s32 *, 0x10);
        if ((s32) M2C_FIELD(temp_r4, s32 *, 0) < 0x19) {
            var_r0 = func_02070f24(temp_r0_2, 0x40C00000);
        } else {
            var_r0 = func_02070f24(temp_r0_2, 0x3E99999A);
        }
        M2C_FIELD(temp_r4, s32 *, 0x10) = var_r0;
        temp_r4_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp68 = temp_r4_2 + 0x10;
        M2C_FIELD(temp_r4_2, s16 *, 0x10) = (s16) ((*sp68 & ~1) | 1);
        temp_r4_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp64 = temp_r4_3 + 0x10;
        M2C_FIELD(temp_r4_3, s16 *, 0x10) = (s16) (*sp64 | 2);
        temp_r4_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp60 = temp_r4_4 + 0x10;
        M2C_FIELD(temp_r4_4, s16 *, 0x10) = (s16) (*sp60 | 4);
        temp_r4_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp5C = temp_r4_5 + 0x10;
        M2C_FIELD(temp_r4_5, s16 *, 0x10) = (s16) (*sp5C | 8);
        temp_r1_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp58 = temp_r1_2 + 0x10;
        M2C_FIELD(temp_r1_2, s16 *, 0x10) = (s16) (*sp58 | 0x10);
        M2C_FIELD(data_02164094, s16 *, 0x16) = 0;
        M2C_FIELD(data_02164094, s16 *, 0x1A) = 0xC0;
    } else if (temp_r0 < 0x41) {
        if (temp_r0 == 0x37) {
            func_01ff9ce8(3);
            func_02098844(0xB, 0, 8, M2C_FIELD(data_027e01d8, s32 *, 0x2C), 0x1E1, 1, 0);
            M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
            temp_r3 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp54 = temp_r3;
            *temp_r3 = *sp54 | 0x10;
            temp_r3_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp50 = temp_r3_2;
            *temp_r3_2 = *sp50 | 0x20;
            temp_r3_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp4C = temp_r3_3;
            *temp_r3_3 = *sp4C | 0x40;
            temp_r3_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp48 = temp_r3_4;
            *temp_r3_4 = *sp48 | 0x80;
            temp_r1_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp44 = temp_r1_3;
            *temp_r1_3 = *sp44 | 0x100;
            M2C_FIELD(data_02164094, s32 *, 0x10) = 0xC3160000;
        }
        M2C_FIELD(data_02164094, s16 *, 0x24) = (s16) (M2C_FIELD(data_02164094, s16 *, 0x24) - 1);
        if ((s32) M2C_FIELD(data_02164094, s16 *, 0x24) < 8) {
            M2C_FIELD(data_02164094, s16 *, 0x24) = 8;
        }
        temp_r4_6 = data_02164094;
        M2C_FIELD(temp_r4_6, s32 *, 0x10) = func_02070f24(M2C_FIELD(temp_r4_6, s32 *, 0x10), 0x41000000);
        temp_r0_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp40 = temp_r0_3 + 0x10;
        M2C_FIELD(temp_r0_3, s16 *, 0x10) = (s16) ((*sp40 & ~1) | 1);
        temp_r0_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp3C = temp_r0_4 + 0x10;
        M2C_FIELD(temp_r0_4, s16 *, 0x10) = (s16) (*sp3C | 2);
        temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp38 = temp_r0_5 + 0x10;
        M2C_FIELD(temp_r0_5, s16 *, 0x10) = (s16) (*sp38 & ~4);
        temp_r0_6 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp34 = temp_r0_6 + 0x10;
        M2C_FIELD(temp_r0_6, s16 *, 0x10) = (s16) (*sp34 & ~8);
        temp_r0_7 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp30 = temp_r0_7 + 0x10;
        M2C_FIELD(temp_r0_7, s16 *, 0x10) = (s16) (*sp30 | 0x10);
        temp_r0_8 = M2C_FIELD(data_02164094, s32 *, 0) - 0x37;
        temp_r4_7 = ((u32) (temp_r0_8 << 5) >> 0x1F) + ((temp_r0_8 << 5) / 10);
        M2C_FIELD(data_02164094, s16 *, 0x16) = (s16) (0x60 - temp_r4_7);
        M2C_FIELD(data_02164094, s16 *, 0x1A) = (s16) (temp_r4_7 + 0x60);
    } else {
        if (temp_r0 == 0x4E) {
            func_0208fe30(0x116);
        }
        if (M2C_FIELD(data_02164094, s32 *, 0) == 0x5E) {
            func_0208fe30(0x117);
        }
        temp_r0_9 = M2C_FIELD(data_02164094, s32 *, 0);
        if ((temp_r0_9 >= 0x4E) && (temp_r0_9 < 0x58)) {
            M2C_FIELD(data_02164094, s16 *, 0x1C) = (s16) (M2C_FIELD(data_02164094, s16 *, 0x1C) + 0x1A);
        }
        temp_r0_10 = M2C_FIELD(data_02164094, s32 *, 0);
        if ((temp_r0_10 >= 0x55) && (temp_r0_10 < 0x5F)) {
            M2C_FIELD(data_02164094, s16 *, 0x20) = (s16) (M2C_FIELD(data_02164094, s16 *, 0x20) - 0x1A);
        }
        temp_r4_8 = data_02164094;
        M2C_FIELD(temp_r4_8, s32 *, 0x10) = func_02070f24(M2C_FIELD(temp_r4_8, s32 *, 0x10), 0x3E19999A);
        temp_r2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp2C = temp_r2 + 0x10;
        *sp2C = (M2C_FIELD(temp_r2, u16 *, 0x10) & ~1) | 1;
        temp_r4_9 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp28 = temp_r4_9 + 0x10;
        M2C_FIELD(temp_r4_9, s16 *, 0x10) = (s16) (*sp28 | 2);
        temp_r4_10 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp24 = temp_r4_10 + 0x10;
        M2C_FIELD(temp_r4_10, s16 *, 0x10) = (s16) (*sp24 & ~4);
        temp_r4_11 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp20 = temp_r4_11 + 0x10;
        M2C_FIELD(temp_r4_11, s16 *, 0x10) = (s16) (*sp20 & ~8);
        temp_r1_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp1C = temp_r1_4 + 0x10;
        M2C_FIELD(temp_r1_4, s16 *, 0x10) = (s16) (*sp1C | 0x10);
        M2C_FIELD(data_02164094, s16 *, 0x16) = 0x40;
        M2C_FIELD(data_02164094, s16 *, 0x1A) = 0x80;
    }
    M2C_FIELD(data_02164094, s16 *, 0xA) = (s16) (M2C_FIELD(data_02164094, s16 *, 0xA) - 0xC);
    temp_r0_11 = M2C_FIELD(data_02164094, s16 *, 0xA);
    if ((s32) temp_r0_11 < 0) {
        M2C_FIELD(data_02164094, s16 *, 0xA) = (s16) (temp_r0_11 + 0x100);
    }
    M2C_FIELD(data_02164094, s16 *, 0xC) = (s16) (M2C_FIELD(data_02164094, s16 *, 0xC) - 7);
    temp_r0_12 = M2C_FIELD(data_02164094, s16 *, 0xC);
    if ((s32) temp_r0_12 < 0) {
        M2C_FIELD(data_02164094, s16 *, 0xC) = (s16) (temp_r0_12 + 0x100);
    }
    M2C_FIELD(data_02164094, s16 *, 0x14) = 0;
    M2C_FIELD(data_02164094, s16 *, 0x18) = 0xFF;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x48) = (s8) M2C_FIELD(data_02164094, s16 *, 0x14);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x4A) = (s8) M2C_FIELD(data_02164094, s16 *, 0x16);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x49) = (s8) M2C_FIELD(data_02164094, s16 *, 0x18);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x4B) = (s8) M2C_FIELD(data_02164094, s16 *, 0x1A);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x38) = (s16) M2C_FIELD(data_02164094, s16 *, 0xA);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3A) = (s16) M2C_FIELD(data_02164094, s16 *, 0xC);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x42) = 0;
    temp_r0_13 = func_020719a0(M2C_FIELD(data_02164094, s32 *, 0x10));
    sp14 = 0;
    var_r7 = sp14;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3E) = temp_r0_13;
    var_r8 = var_r7;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x46) = (s16) var_r7;
    temp_r0_14 = M2C_FIELD(data_027e01d8, u16 **, 0);
    temp_r4_12 = M2C_FIELD(data_02164094, s16 *, 0x24);
    sp18 = temp_r0_14 + 0x12;
    M2C_FIELD(temp_r0_14, s16 *, 0x12) = (s16) ((*sp18 & ~0xC0) | 0x40);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = (u8) temp_r4_12;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x52) = (u8) temp_r4_12;
    do {
        var_r6 = 0;
        var_r9 = 0x40;
        var_r10 = 0;
loop_30:
        func_01ffaacc((u16) ((M2C_FIELD(data_02164094, s16 *, 0x1C) + var_r8) & 0x1FF), (u8) (M2C_FIELD(data_02164094, s16 *, 0x1E) + var_r10), (u16) ((0x3FF & ((s32) (var_r9 + var_r7) >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0x6000), &data_02101f0c, 0);
        var_r6 += 1;
        var_r9 += 0x20;
        var_r10 += 8;
        if (var_r6 < 4) {
            goto loop_30;
        }
        var_r7 += 8;
        temp_r0_15 = sp14 + 1;
        sp14 = temp_r0_15;
        var_r8 += 0x40;
    } while (temp_r0_15 < 4);
    var_r6_2 = 0;
    spC = 0;
    var_r7_2 = 0;
    do {
        var_r10_2 = 0;
        var_r8_2 = 0xC0;
        var_r9_2 = 0;
loop_34:
        func_01ffaacc((u16) ((M2C_FIELD(data_02164094, s16 *, 0x20) + var_r7_2) & 0x1FF), (u8) (M2C_FIELD(data_02164094, s16 *, 0x22) + var_r9_2), (u16) ((0x3FF & ((s32) (var_r8_2 + var_r6_2) >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0x6000), &data_02101f0c, 0);
        var_r10_2 += 1;
        var_r8_2 += 0x20;
        var_r9_2 += 8;
        if (var_r10_2 < 6) {
            goto loop_34;
        }
        var_r6_2 += 8;
        temp_r0_16 = spC + 1;
        spC = temp_r0_16;
        var_r7_2 += 0x40;
    } while (temp_r0_16 < 4);
    data_027e01d8 = sp10;
}

