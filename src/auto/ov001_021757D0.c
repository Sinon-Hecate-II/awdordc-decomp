/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"

typedef struct { s32 x; u32 y; } Position;

void func_ov001_021757d0(s32 arg0) {
    M2C_UNK func_ov001_0216d14c();
    M2C_UNK func_ov001_02184b50(void *);
    extern M2C_UNK data_ov001_02193d24;
    extern M2C_UNK data_ov001_02193d28;
    func_ov001_0216d14c();
    if (arg0 != 0) {
        if ((M2C_FIELD(M2C_FIELD(&data_ov001_02193d24, void **, 4), u8 *, 0x116) == 0) && (M2C_FIELD(&data_ov001_02193d24, u8 *, 0) == 1)) {
            func_ov001_02184b50(M2C_FIELD(&data_ov001_02193d24, void **, 4) + 0x117);
        }
    }
    func_ov001_0218b71c(&data_ov001_02193d28);
}

s32 func_ov001_02175820(void) {
    extern M2C_UNK data_ov001_02193d24;
    s32 func_ov001_0216ad74(M2C_UNK);
    if (func_ov001_0216ad74(M2C_FIELD(&data_ov001_02193d24, M2C_UNK *, 4)) == 0) {
        M2C_FIELD(&data_ov001_02193d24, u8 *, 0) = 1;
        return 1;
    }
    {
        u8 c = M2C_FIELD(M2C_FIELD(&data_ov001_02193d24, M2C_UNK *, 4), u8 *, 0x116);
        if (c == 1) goto L0;
        if ((u8)(c + 0xFD) > 2) goto L2;
    L0:
        return 0;
    L2:
        return 2;
    }
}

void func_ov001_02175880(M2C_UNK arg0) {
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK);
    func_ov001_0218b6f8(arg0, 0x20);
}

void func_ov001_02175890(void) {
    M2C_UNK func_ov001_0218b760();
    func_ov001_0218b760();
}

s32 func_ov001_0217589c(M2C_UNK arg0, s32 arg1, s32 arg2) {
    void func_ov001_02176628(void);
    u8 *p;
    s32 zero;
    extern u8 data_ov001_02193d2c;
    s32 func_ov001_02175928(s32, s32);
    void func_ov001_021759c4(void);
    void func_ov001_02175a8c(void);
    void func_ov001_02184f68(void);
    void func_ov001_02175d54(s32);
    void func_ov001_0218b850(void);
    void func_ov001_0218c7d4(s32);
    void func_ov001_0218bdb0(void);
    void func_ov001_0218c63c(void);
    void func_02007598(void);
    void func_ov001_02175d04(void);
    p = (u8 *)&data_ov001_02193d2c;
    zero = 0;
    M2C_FIELD(p, M2C_UNK *, 4) = arg0;
    if (func_ov001_02175928(arg1, arg2) == 0) {
        return -1;
    }
    M2C_FIELD(p, u8 *, 1) = 0;
    func_ov001_021759c4();
    func_ov001_02175a8c();
    func_ov001_02184f68();
    func_ov001_02175d54((s32)func_ov001_02176628);
    func_ov001_0218b850();
    {
        void (*fp)(void) = M2C_FIELD(p, void (**)(void), 0xc);
        fp();
    }
    func_ov001_0218c7d4(zero);
    func_ov001_0218bdb0();
    func_ov001_0218c63c();
    func_02007598();
    if (M2C_FIELD(p, u8 *, 1) != 0) {
        func_ov001_02175d04();
    }
    return zero;
}

s32 func_ov001_02175928(s32 arg0, s32 arg1) {
    extern u8 data_ov001_02193d2c;
    M2C_FIELD(&data_ov001_02193d2c, u8 *, 0) = (u8)arg0;
    M2C_FIELD(&data_ov001_02193d2c, s32 *, 8) = arg1;
    if (arg0 < 0) {
        return 0;
    }
    if (arg0 > 6) {
        return 0;
    }
    if (arg0 == 1) {
        if ((((u32)arg1 >> 4) & ~2u) != 0) {
            return 0;
        }
    }
    if ((M2C_FIELD(&data_ov001_02193d2c, s32 *, 8) & 0xF) > 1) {
        return 0;
    }
    if (arg0 != 0) {
        if (((u32)arg1 >> 4) & 1u) {
            return 0;
        }
    } else {
        s32 val = M2C_FIELD(&data_ov001_02193d2c, s32 *, 8);
        if (!(((u32)val >> 4) & 1u)) {
            return 0;
        }
    }
    return 1;
}

void func_ov001_021759c4(void) {
    extern u8 data_ov001_02193d2c;
    *(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = 0;
    *(volatile u32 *)0x4001000 &= ~0x10000;
}

void func_ov001_02175a8c(void) {
    void func_0200245c(s32);
    void func_020026d8(s32);
    void func_02002968(s32);
    void func_02002514(s32, s32, s32);
    void func_02002598(void *, s32);
    void func_020039a0(s32, s32, s32);
    void func_02003124(s32);
    void func_020031cc(s32);
    void func_0200257c(s32);
    void func_ov001_0218aab4(void);
    void func_ov001_0218bfd4(void);
    void func_ov001_0218c168(void);
    void func_ov001_02189f48(void);
    void func_020024cc(void);

    func_0200245c(0);
    func_020026d8(1);
    func_02002968(2);
    func_02002514(1, 0, 0);

    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x1f00);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xe000);
    func_02002598((void *)0x0400006C, 0);

    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & 0xffcfffef) | 0x10 | 0x200000;
    *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & ~0x40);
    *(volatile u16 *)0x0400000a = (*(volatile u16 *)0x0400000a & ~0x40);
    *(volatile u16 *)0x0400000c = (*(volatile u16 *)0x0400000c & ~0x40);
    *(volatile u16 *)0x0400000e = (*(volatile u16 *)0x0400000e & ~0x40);
    *(volatile u32 *)0x04000010 = 0;
    *(volatile u32 *)0x04000014 = 0;
    *(volatile u32 *)0x04000018 = 0;
    *(volatile u32 *)0x0400001c = 0;
    func_020039a0(0x04000050, 0x3f, 0x10);
    func_02003124(0x80);
    func_020031cc(0x100);
    func_0200257c(0);

    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0xe000);
    func_02002598((void *)0x0400106C, 0);

    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & 0xffcfffef) | 0x10;
    *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & ~0x40);
    *(volatile u16 *)0x0400100a = (*(volatile u16 *)0x0400100a & ~0x40);
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & ~0x40);
    *(volatile u16 *)0x0400100e = (*(volatile u16 *)0x0400100e & ~0x40);
    *(volatile u32 *)0x04001010 = 0;
    *(volatile u32 *)0x04001014 = 0;
    *(volatile u32 *)0x04001018 = 0;
    *(volatile u32 *)0x0400101c = 0;
    func_020039a0(0x04001050, 0x3f, 0x10);

    *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & 0x43) | 0xc00;
    *(volatile u16 *)0x0400000a = (*(volatile u16 *)0x0400000a & 0x43) | 0x108 | 0xc00;
    *(volatile u16 *)0x0400000c = (*(volatile u16 *)0x0400000c & 0x43) | 0xe10;
    *(volatile u16 *)0x0400000e = (*(volatile u16 *)0x0400000e & 0x43) | 0xf10;
    *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & 0x43) | 0xc00;
    *(volatile u16 *)0x0400100a = (*(volatile u16 *)0x0400100a & 0x43) | 0xd00;
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & 0x43) | 0xe00;
    *(volatile u16 *)0x0400100e = (*(volatile u16 *)0x0400100e & 0x43) | 0xf00;

    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x38000000);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x7000000);
    *(volatile u16 *)0x04000304 = (*(volatile u16 *)0x04000304 & ~0x8000);

    func_ov001_0218aab4();
    func_ov001_0218bfd4();
    func_ov001_0218c168();
    func_ov001_02189f48();
    func_020024cc();

    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 | 0x10000);
    func_0200245c(1);
}

void func_ov001_02175d04(void) {
    M2C_UNK func_02002490();
    M2C_UNK func_ov001_02184ff8();
    M2C_UNK func_ov001_02189c80();
    M2C_UNK func_ov001_0218a01c();
    M2C_UNK func_ov001_0218a7ec();
    M2C_UNK func_ov001_0218abb8();
    M2C_UNK func_ov001_0218b688();
    M2C_UNK func_ov001_0218b818();
    M2C_UNK func_ov001_0218bea0();
    M2C_UNK func_ov001_0218c0b8();
    M2C_UNK func_ov001_0218c4c0();
    M2C_UNK func_ov001_0218c668();
    M2C_UNK func_ov001_0218c78c();
    func_02002490();
    *(s32 *)0x04001000 &= ~0x10000;
    func_ov001_0218c668();
    func_ov001_0218b818();
    func_ov001_0218bea0();
    func_ov001_02184ff8();
    func_ov001_0218a01c();
    func_ov001_0218c0b8();
    func_ov001_0218abb8();
    func_ov001_0218a7ec();
    func_ov001_02189c80();
    func_ov001_0218c78c();
    func_ov001_0218b688();
    func_ov001_0218c4c0();
}

void func_ov001_02175d54(s32 arg0) {
    extern u8 data_ov001_02193d2c;
    M2C_FIELD(&data_ov001_02193d2c, s32 *, 0xc) = arg0;
}

void func_ov001_02175d64(s32 arg0, s32 arg1) {
    extern u8 data_ov001_02193d2c;
    M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x10) = arg0;
    M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x14) = arg1;
}

void func_ov001_02175d78(s32 *arg0, s32 *arg1) {
    extern u8 data_ov001_02193d2c;
    if (arg0 != 0) {
        *arg0 = M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x10);
    }
    if (arg1 != 0) {
        *arg1 = M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x14);
    }
}

void func_ov001_02175da0(s32 arg0, s32 arg1) {
    extern u8 data_ov001_02193d2c;
    M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x18) = arg0;
    M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x1c) = arg1;
}

void func_ov001_02175db4(s32 *arg0, s32 *arg1) {
    extern u8 data_ov001_02193d2c;
    if (arg0 != 0) {
        *arg0 = M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x18);
    }
    if (arg1 != 0) {
        *arg1 = M2C_FIELD(&data_ov001_02193d2c, s32 *, 0x1c);
    }
}

u8 func_ov001_02175ddc(void) {
    extern u8 data_ov001_02193d2c;
    return data_ov001_02193d2c;
}

s32 func_ov001_02175dec(void) {
    extern u8 data_ov001_02193d2c;
    typedef struct { u32 a, b; unsigned val : 4; } S;
    return ((S *)&data_ov001_02193d2c)->val;
}

s32 func_ov001_02175e04(s32 arg0) {
    extern u8 data_ov001_02193d2c;
    if (arg0 & ((u32)M2C_FIELD(&data_ov001_02193d2c, s32 *, 8) >> 4)) {
        return 1;
    }
    return 0;
}

void func_ov001_02175e20(void) {
    extern u8 data_ov001_02193d2c;
    M2C_FIELD(&data_ov001_02193d2c, u8 *, 1) = 1;
}

s32 func_ov001_02175e34(void) {
    extern u8 data_ov001_02193d2c;
    u8 r1 = data_ov001_02193d2c;
    if (r1 == 6) {
        return 0x38;
    }
    if (r1 == 1) {
        if (!(( ((u32)M2C_FIELD(&data_ov001_02193d2c, s32 *, 8)) >> 4) & 2)) {
            return 0x37;
        }
    }
    return (r1 + 0x31) & 0xFF;
}

void func_ov001_02175e74(void) {
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a698(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d4c;
    M2C_UNK val;
    M2C_UNK res;
    val = func_ov001_0218b6f8(0x64, 0x4);
    data_ov001_02193d4c = val;
    res = func_ov001_0218a698(0x8, val, 0xc);
    M2C_FIELD((void *)data_ov001_02193d4c, M2C_UNK *, 0x60) = res;
}

void func_ov001_02175eb0(void) {
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern M2C_UNK data_ov001_02193d4c;
    func_ov001_0218b71c(&data_ov001_02193d4c);
}

M2C_UNK func_ov001_02175ec4(M2C_UNK arg0) {
    M2C_UNK func_ov001_0218a74c(M2C_UNK);
    M2C_UNK func_ov001_02189dc8(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d4c;
    M2C_UNK var_r4;
    M2C_UNK local;
    M2C_UNK ret;
    M2C_UNK r2;
    M2C_UNK r1;
    var_r4 = func_ov001_0218a74c(M2C_FIELD(data_ov001_02193d4c, M2C_UNK *, 0x60));
    ret = func_ov001_02189dc8(arg0, &local, 4);
    r2 = ret + 0x20;
    M2C_FIELD(var_r4, M2C_UNK *, 0x8) = ret;
    M2C_FIELD(var_r4, M2C_UNK *, 0x0) = r2 + 0x10;
    r1 = M2C_FIELD(r2, M2C_UNK *, 0x4);
    M2C_FIELD(var_r4, M2C_UNK *, 0x4) = r2 + r1 + 0x8;
    return var_r4;
}

void func_ov001_02175f1c(M2C_UNK arg0) {
    M2C_UNK func_ov001_02189ebc(M2C_UNK);
    M2C_UNK func_ov001_0218a6f4(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d4c;
    func_ov001_02189ebc(M2C_FIELD((void *)arg0, M2C_UNK *, 0x8));
    func_ov001_0218a6f4(M2C_FIELD((void *)data_ov001_02193d4c, M2C_UNK *, 0x60), arg0);
}

s32 func_ov001_02175f48(M2C_UNK arg0, u32 arg1) {
    void **p = (void **)arg0;
    arg1 = (arg1 << 16) >> 16;
    return ((s32 *)p[0])[(u32)arg1] + (s32)p[1];
}
