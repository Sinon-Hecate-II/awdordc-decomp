/* 18 functions from 0x020DE264 to 0x020DF1D0 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
M2C_UNK func_020de264(M2C_UNK arg0, M2C_UNK arg1) {
    void func_01ff9ce8(u8);
    void func_0200bc5c(void *);
    void *func_020e3218(void *);
    void func_020814e4(void *);
    void func_02081590(void *, void *);
    void func_02081528(void);
    void func_02080944(void *, s32, s32, s32);
    void func_0208e7ec(s32, s32);
    void func_02088f1c(void *);
    void func_02088da8(void *);
    void func_0208b758(void *, u32);
    s32 func_020a8ff4(void *);
    void func_ov010_02228d48(s32, s32, s32, s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern void *data_027e00c4;
    extern M2C_UNK data_0212d428;
    extern M2C_UNK data_0212d430;
    extern M2C_UNK data_0212d440;
    extern M2C_UNK data_0212d450;
    void func_020de50c(void);
    void func_020de5b0(void);
    void func_020de610(void);

    void *old = gCur3DSpriteEngine;
    s32 code;
    s32 code2;
    void *p;
    u8 low;
    u32 val;
    s32 t;
    s32 v3c;
    s32 v34;
    s32 v38;
    s32 tmp;

    gCur3DSpriteEngine = data_027e00c8;
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x2;
    func_0200bc5c(&data_0212d428);
    func_020814e4(func_020e3218(&data_0212d430));

    v34 = M2C_FIELD((void *)arg0, s32 *, 0x34);
    code = -1;
    if (v34 != 0) {
        if (v34 == 1) code = 2;
        if (v34 == 2) code = 2;
    } else {
        v38 = M2C_FIELD((void *)arg0, s32 *, 0x38);
        if (v38 == 1) code = 2; else code = 4;
    }

    if (code == 2) {
        func_02081590(func_020e3218(&data_0212d450), M2C_FIELD(gCur3DSpriteEngine, void **, 0x20));
    } else if (code == 4) {
        func_02081590(func_020e3218(&data_0212d440), M2C_FIELD(gCur3DSpriteEngine, void **, 0x20));
    }

    func_02081528();
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, void **, 0x20), 0x20, 0x18, 0x5);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x1;
    gCur3DSpriteEngine = data_027e00c4;
    func_0208e7ec(0x3c00, 0x7);

    gCur3DSpriteEngine = old;

    M2C_FIELD((void *)arg0, u16 *, 0x48) |= 0x20;

    p = M2C_FIELD((void *)arg0, void **, 0x54);
    low = M2C_FIELD(p, u8 *, 0x59);
    low = (u8)((low << 28) >> 28);
    val = M2C_FIELD(p, u32 *, 0x40);
    val &= ~0x03FC0000u;
    val |= ((u32)(low + 2)) << 18;
    M2C_FIELD(p, u32 *, 0x40) = val;
    M2C_FIELD(p, u8 *, 0x5a) = 0;

    func_02088f1c(M2C_FIELD((void *)arg0, void **, 0x58));
    func_02088da8(M2C_FIELD((void *)arg0, void **, 0x60));
    func_0208b758(M2C_FIELD((void *)arg0, void **, 0x64), 0x44000011U);
    func_02088f1c(M2C_FIELD((void *)arg0, void **, 0x64));

    p = M2C_FIELD((void *)arg0, void **, 0x68);
    if (func_020a8ff4(p) != 0) {
        t = func_020a8ff4(p);
        M2C_FIELD(p, u16 *, 0xe) = (u16)t;
        M2C_FIELD(p, u16 *, 0x10) = 0;
        M2C_FIELD(p, u16 *, 0xc) = 0xc;
        M2C_FIELD(p, u16 *, 0x2) = M2C_FIELD(p, u16 *, 0x4);
        M2C_FIELD((void *)arg0, u16 *, 0x48) &= ~0x100;
        M2C_FIELD((void *)arg0, u16 *, 0x48) &= ~0x200;
    }

    v3c = M2C_FIELD((void *)arg0, s32 *, 0x3c);
    if (v3c == 0) {
        M2C_FIELD((void *)arg0, u16 *, 0x4a) = 0xa;
    } else if (v3c == 1) {
        M2C_FIELD((void *)arg0, u16 *, 0x4a) = 0xa;
        func_020de5b0;
    }

    M2C_FIELD((void *)arg0, u8 *, 0x41) = 0;
    M2C_FIELD((void *)arg0, u16 *, 0x4c) = 0x708;

    v34 = M2C_FIELD((void *)arg0, s32 *, 0x34);
    code2 = -1;
    if (v34 != 0) {
        if (v34 == 1) code2 = 2;
        if (v34 == 2) code2 = 2;
        tmp = v34;
    } else {
        v38 = M2C_FIELD((void *)arg0, s32 *, 0x38);
        if (v38 == 1) code2 = 2; else code2 = 4;
        tmp = v38;
    }

    v3c = M2C_FIELD((void *)arg0, s32 *, 0x3c);
    func_ov010_02228d48((s32)arg1, code2, (s32)func_020de610, (s32)arg0, tmp, (s32)arg0, v3c);
}
void func_020de610(void) {

}

M2C_UNK func_020de614(M2C_UNK a0, M2C_UNK a1) { (void)a0; (void)a1; return 0; }

void func_020de868(s32 arg0, s32 arg1, void *arg2) {
    if (arg0 != 0) {
        return;
    }
    if (arg1 != 0) {
        M2C_FIELD(arg2, u16 *, 0x48) = (u16) (M2C_FIELD(arg2, u16 *, 0x48) | 0x100);
    }
}

s32 func_020de884(M2C_UNK arg0) {
    M2C_UNK func_0203c0b0(M2C_UNK, M2C_UNK *, s32);
    void *func_ov010_02229b00();
    extern M2C_UNK data_0212c5c8;
    if (!(M2C_FIELD(func_ov010_02229b00(), u8 *, 0x1A) & 2)) {
        return -1;
    }
    func_0203c0b0(arg0, &data_0212c5c8, 0x5DC000);
    return 0x7FFFFF;
}

M2C_UNK func_020de8c4(M2C_UNK arg0, M2C_UNK arg1) {
    (void)arg0; (void)arg1;
    return 0;
}

void func_020deb74(M2C_UNK arg0) {
    M2C_UNK func_020ddfd8(M2C_UNK, M2C_UNK);
    func_020ddfd8(arg0, 0);
}

void func_020deb84(M2C_UNK arg0) {
    M2C_UNK func_020ddfd8(M2C_UNK, M2C_UNK);
    func_020ddfd8(arg0, 1);
}

void func_020deb94(M2C_UNK arg0) {
    M2C_UNK func_020de264(M2C_UNK, M2C_UNK);
    func_020de264(arg0, 0);
}

void func_020deba4(M2C_UNK arg0) {
    M2C_UNK func_020de264(M2C_UNK, M2C_UNK);
    func_020de264(arg0, 1);
}

void func_020debb4(M2C_UNK arg0) {
    M2C_UNK func_020de614(M2C_UNK, M2C_UNK);
    func_020de614(arg0, 0);
}

void func_020debc4(M2C_UNK arg0) {
    M2C_UNK func_020de614(M2C_UNK, M2C_UNK);
    func_020de614(arg0, 1);
}

void func_020debd4(M2C_UNK arg0) {
    M2C_UNK func_020de8c4(M2C_UNK, M2C_UNK);
    func_020de8c4(arg0, 0);
}

void func_020debe4(M2C_UNK arg0) {
    M2C_UNK func_020de8c4(M2C_UNK, M2C_UNK);
    func_020de8c4(arg0, 1);
}

void func_020debf4() {
    return;
}

