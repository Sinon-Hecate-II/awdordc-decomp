/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"

typedef struct { s32 x; u32 y; } Position;

void func_ov001_02175290(void) {
    s32 func_ov001_0218a24c(s32, M2C_UNK);
    M2C_UNK func_ov001_0218a384(s32, M2C_UNK, u16, u16);
    M2C_UNK func_ov001_0218a474(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a55c(M2C_UNK, M2C_UNK, s32);
    extern u16 data_ov001_0218f66a[];
    extern u16 data_ov001_0218f66c[];
    extern void *data_ov001_02193d20;
    M2C_UNK var_r4;
    s32 temp_ip;
    if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) <= 0xB) var_r4 = 0x44;
    else var_r4 = 0x45;
    func_ov001_0218a55c(0, var_r4, func_ov001_0218a24c(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58), 0));
    func_ov001_0218a474(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58), -1, 2);
    temp_ip = M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) * 2;
    func_ov001_0218a384(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58), -1, data_ov001_0218f66a[temp_ip], data_ov001_0218f66c[temp_ip]);
}

void func_ov001_0217531c(s32 arg0) {
    void func_ov001_02185024(s32);
    extern s8 data_ov001_0218f6a2[][4];
    extern void *data_ov001_02193d20;
    s8 old;
    s8 current;
    old = M2C_FIELD(data_ov001_02193d20, s8 *, 0x63);
    M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = data_ov001_0218f6a2[old][arg0];
    current = M2C_FIELD(data_ov001_02193d20, s8 *, 0x63);
    if (current == 13 && (arg0 == 1 || arg0 == 3)) {
        M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) = old;
    } else if (current == -1) {
        if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 1 || M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 10)
            M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 10;
        else M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 11;
    } else if (current == -2) {
        if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 1 || M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 10)
            M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 1;
        else M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 2;
    }
    func_ov001_02175290();
    func_ov001_02185024(8);
}

void func_ov001_021753c8(M2C_UNK arg0) {
    void func_ov001_02174f68(s32, Position);
    M2C_UNK func_ov001_0218c924(M2C_UNK, void (*)(M2C_UNK));
    void func_ov001_02175440(M2C_UNK);
    extern void *data_ov001_02193d20;
    s32 temp_r2 = *(s32 *)func_ov001_0218a24c(M2C_FIELD(data_ov001_02193d20, s32 *, 0x40), 0);
    Position pos = { (u8)temp_r2 + 12, (u32)(temp_r2 & 0x01FF0000) >> 16 };
    func_ov001_02174f68(4, pos);
    if (pos.x < 192) return;
    func_ov001_0218c924(arg0, func_ov001_02175440);
}

void func_ov001_02175440(M2C_UNK arg0) {
    void func_ov001_02174f68(s32, Position);
    M2C_UNK func_ov001_0218c924(M2C_UNK, void (*)(M2C_UNK));
    void func_ov001_021754b0(M2C_UNK);
    extern void *data_ov001_02193d20;
    s32 temp_r3 = *M2C_FIELD(data_ov001_02193d20, s32 **, 0x34);
    s32 vx = (u8)temp_r3 + 12;
    u32 vy = (u32)(temp_r3 & 0x01FF0000) >> 16;
    Position pos;
    pos.x = vx;
    pos.y = vy;
    func_ov001_02174f68(3, pos);
    if (pos.x >= 0xC0) {
        func_ov001_0218c924(arg0, func_ov001_021754b0);
    }
}

void func_ov001_021754b0(M2C_UNK arg0) {
    void func_ov001_02174f68(s32, Position);
    M2C_UNK func_ov001_0218c924(M2C_UNK, void (*)(M2C_UNK));
    void func_ov001_02175520(M2C_UNK);
    extern void *data_ov001_02193d20;
    s32 temp_r3 = *M2C_FIELD(data_ov001_02193d20, s32 **, 0x28);
    s32 vx = (u8)temp_r3 + 12;
    u32 vy = (u32)(temp_r3 & 0x01FF0000) >> 16;
    Position pos = { vx, vy };
    func_ov001_02174f68(2, pos);
    if (pos.x < 0xC0) return;
    func_ov001_0218c924(arg0, func_ov001_02175520);
}

void func_ov001_02175520(M2C_UNK arg0) {
    void func_ov001_02174f68(s32, Position);
    M2C_UNK func_ov001_0218c924(M2C_UNK, void (*)(M2C_UNK));
    void func_ov001_02175590(M2C_UNK);
    extern void *data_ov001_02193d20;
    s32 temp_r3 = *M2C_FIELD(data_ov001_02193d20, s32 **, 0x1c);
    s32 vx = (u8)temp_r3 + 12;
    u32 vy = (u32)(temp_r3 & 0x01FF0000) >> 16;
    Position pos = { vx, vy };
    func_ov001_02174f68(1, pos);
    if (pos.x < 0xC0) return;
    func_ov001_0218c924(arg0, func_ov001_02175590);
}

void func_ov001_02175590(M2C_UNK arg0) {
    void func_ov001_02174f68(s32, Position);
    M2C_UNK func_ov001_0218c924(M2C_UNK, void (*)(M2C_UNK));
    void func_ov001_02175600(M2C_UNK);
    extern void *data_ov001_02193d20;
    s32 temp_r3 = *M2C_FIELD(data_ov001_02193d20, s32 **, 0x10);
    Position pos = { (u8)temp_r3 + 12, (u32)(temp_r3 & 0x01FF0000) >> 16 };
    func_ov001_02174f68(0, pos);
    if (pos.x < 0xC0) return;
    func_ov001_0218c924(arg0, func_ov001_02175600);
}

void func_ov001_02175600(int arg0) {
extern void *data_ov001_02193d20;
int i; unsigned int *ptr;
func_ov001_0218c92c(0,arg0);
for(i=0;i<4;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218a1cc(((void **)ptr)[i+0x12]);ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218ace0(((void **)ptr)[i]);}
for(i=0;i<2;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218a1cc(((void **)ptr)[i+0x10]);}
for(i=0;i<2;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218c104(((void **)ptr)[i+0xe]);}
for(i=0;i<10;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218c104(((void **)ptr)[i+4]);}
func_ov001_0218b71c((void *)0x02193D20);
}

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

