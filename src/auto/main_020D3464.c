/* 30 functions from 0x020D3464 to 0x020D4430 (main), found by ds-decomp. */
#include "common.h"

void func_020d35d8(void) {
    M2C_UNK func_020d4dfc();
    M2C_UNK func_02081fec();
    M2C_UNK func_020b7bbc();
    extern void **gCurrentMap;
    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52B4) != 0) {
        func_020d4dfc();
        return;
    }
    func_02081fec();
    func_020b7bbc();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 0x16;
}

void func_020d3628(void) {
    M2C_UNK func_020844f8();
    M2C_UNK func_020bbb08();
    extern M2C_UNK data_02168f08;
    func_020bbb08();
    if (M2C_FIELD(&data_02168f08, u8 *, 4) == 0) {
        return;
    }
    func_020844f8();
}

void func_020d39a4(void) {
    M2C_UNK data_ov004_0222866c(M2C_UNK);
    data_ov004_0222866c(0);
}

s32 func_020d39b4(void) {
    M2C_UNK func_02084644();
    M2C_UNK func_ov010_02228678(M2C_UNK *);
    extern M2C_UNK data_02168f08;
    s32 local;
    if (func_02084644() != 2) {
        return 0;
    }
    if (func_ov010_02228678(&local) != 0) {
        return 1;
    }
    M2C_FIELD(&data_02168f08, u8 *, 7) = local;
    return 0;
}

void func_020d39f4(s32 arg0) {
    M2C_UNK func_02084644();
    M2C_UNK func_01ffa42c(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02168f08;
    extern M2C_UNK data_0212b9d4;
    switch (func_02084644()) {                      /* irregular */
    case 1:
        M2C_FIELD(&data_02168f08, u8 *, 7) = 0;
        return;
    case 2:
        func_01ffa42c(&data_0212b9d4, arg0);
        return;
    }
}

void func_020d3a3c(void) {
    M2C_UNK func_020d4dfc();
    M2C_UNK func_0208b5a8();
    M2C_UNK func_02081fec();
    void func_01ffa3dc(void *, s32);
    extern void **gCurrentMap;
    extern char data_0212ba7c[];
    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52B4) != 0) {
        func_020d4dfc();
        return;
    }
    if (func_0208b5a8() != 0) {
        return;
    }
    func_02081fec();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 25;
    func_01ffa3dc(data_0212ba7c, 7);
}

void func_020d3aa4(void *arg0) {
    M2C_UNK func_02086330();
    M2C_UNK func_02085054(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02168f08;
    if (M2C_FIELD(&data_02168f08, u8 *, 5) == 0 && M2C_FIELD(&data_02168f08, u8 *, 7) == 0) {
        func_02086330();
        func_02085054(0, 0x25c, arg0);
    }
}

void func_020d3ae4(void) {
    void func_01ffa3dc(void *, s32);
    extern void **gCurrentMap;
    extern char data_0212b9ac[];
    func_01ffa3dc(data_0212b9ac, 7);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 26;
}

void func_020d3b18(void) {
    M2C_UNK func_020d4614();
    func_020d4614();
}

void func_020d3cec(void) {
    M2C_UNK func_020ceec8();
    M2C_UNK func_020e3320();
    M2C_UNK func_020e3344();
    extern s32 data_0211fb58;
    extern s32 data_0215be00;
    extern s32 data_0215be04;
    data_0215be04 = data_0211fb58;
    data_0215be00 = data_0211fb58;
    func_020ceec8();
    func_020e3320();
    func_020e3344();
}

void func_020d3d24(void) {
    M2C_UNK func_020ceb48();
    M2C_UNK func_020ceec8();
    M2C_UNK func_020cf0a8(M2C_UNK);
    M2C_UNK func_020ceea8();
    M2C_UNK func_020a23c4();
    M2C_UNK func_020cfd14();
    M2C_UNK func_0207b6d0();
    M2C_UNK func_020d1c58();
    M2C_UNK func_020d1ce0();
    extern void **gCurrentMap;
    func_020ceb48();
    func_020ceec8();
    func_020cf0a8(M2C_FIELD(*gCurrentMap, u16 *, 0x5142));
    func_020ceea8();
    func_020a23c4();
    func_020cfd14();
    func_0207b6d0();
    func_020d1c58();
    func_020d1ce0();
}

s32 func_020d3e94(void) {
    M2C_UNK func_020d1938(s32);
    M2C_UNK func_020c9ebc(s32, s32);
    M2C_UNK func_020c9b70();
    extern void **gCurrentMap;
    s32 i;
    s32 off;
    s32 max;
    void *base;

    max = 0;
    for (i = 1, off = 0x8C; i < 5; i++, off += 0x8C) {
        if (func_020d1938(i) != 0) {
            s32 value;
            base = *gCurrentMap;
            value = M2C_FIELD((u8 *)base + off, u8 *, 0x67BC);
            if (max < value) {
                max = value;
            }
        }
    }
    for (i = 1, off = 0x8C; i < 5; i++, off += 0x8C) {
        if (func_020d1938(i) != 0) {
            base = *gCurrentMap;
            if (max > M2C_FIELD((u8 *)base + off, u8 *, 0x67BC)) {
                func_020c9ebc(i, 0x20);
            }
        }
    }
    func_020c9b70();
}

s32 func_020d4060(void) {
    M2C_UNK func_020d1938(s32);
    M2C_UNK func_020d19e8(s32);
    extern M2C_UNK data_02168f08;
    extern void *data_02101e84;
    s32 i;

    if (M2C_FIELD(&data_02168f08, u8 *, 4) != 0) {
        for (i = 1; i < 5; i++) {
            if (func_020d1938(i) != 0 && func_020d19e8(i) == 0) {
                return 0;
            }
        }
    } else {
        if ((M2C_FIELD(data_02101e84, u16 *, 0x6) & 0xC0B) == 0) {
            return 0;
        }
        for (i = 1; i < 5; i++) {
            if (func_020d1938(i) != 0 && func_020d19e8(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void func_020d4110(void) {
    M2C_UNK func_020d3e94();
    void func_01ffa3dc(void *, s32);
    extern M2C_UNK data_02168f08;
    extern char data_0212ba3c[];
    if (M2C_FIELD(&data_02168f08, u8 *, 4) != 0) {
        func_020d3e94();
        return;
    }
    func_01ffa3dc(data_0212ba3c, 7);
}

void func_020d4144(void) {
    M2C_UNK func_020d1a90();
    M2C_UNK func_020ca484();
    M2C_UNK func_02096b50(M2C_UNK);
    M2C_UNK func_020d3e94();
    extern M2C_UNK data_02168f08;
    extern void **gCurrentMap;
    if (M2C_FIELD(&data_02168f08, u8 *, 0xF) != 0 && func_020d1a90() != 0) {
        if (M2C_FIELD(*gCurrentMap, u16 *, 0x52A2) != M2C_FIELD(&data_02168f08, u8 *, 0xF)) {
            M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 2;
            func_020ca484();
            return;
        }
    }
    func_02096b50(0xc0000347);
    func_020d3e94();
}

void func_020d41c4(void) {
    M2C_UNK func_020d1b80();
    M2C_UNK func_020d3f48();
    M2C_UNK func_020b78ac();
    M2C_UNK func_020d4060();
    void func_020d4110(void);
    extern void **gCurrentMap;
    if (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 4), M2C_UNK *, 0x40) != 0) {
        ((void(*)(void)) M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 4), M2C_UNK *, 0x40))();
        func_020d1b80();
        M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 3;
    }
    if (func_020d3f48() != 0) {
        func_020b78ac();
        return;
    }
    if (func_020d4060() == 0) {
        return;
    }
    func_020d4110();
}

void func_020d422c(void) {
    M2C_UNK func_020a3498(M2C_UNK);
    M2C_UNK func_020d1c58();
    M2C_UNK func_020d1ce0();
    M2C_UNK func_020a23c4();
    M2C_UNK func_020cfd28();
    void func_020d427c(void);
    extern void **gCurrentMap;
    func_020a3498(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4));
    func_020d1c58();
    func_020d1ce0();
    func_020a23c4();
    func_020cfd28();
    func_020d427c();
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 4;
}

void func_020d427c(void) {

}

void func_020d4280(void) {
    M2C_UNK func_020cbda4();
    extern void **gCurrentMap;
    func_020cbda4();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 9;
}

void func_020d42a8(void) {
    M2C_UNK func_020cbc08();
    extern void **gCurrentMap;
    func_020cbc08();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 0xa;
}

void func_020d42d0(void) {
    M2C_UNK func_ov000_0216a8a4();
    extern void **gCurrentMap;
    func_ov000_0216a8a4();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 11;
}

void func_020d42f8(void) {
    M2C_UNK func_020946d0();
    M2C_UNK func_020a5ac8();
    extern void **gCurrentMap;
    if (func_020946d0() != 0) {
        return;
    }
    func_020a5ac8();
    M2C_FIELD(**(void ***)gCurrentMap, u16 *, 0x52B0) = 0xc;
}

void func_020d432c(void) {
    M2C_UNK func_020c0a1c(M2C_UNK);
    void func_ov000_0219c7c4(void);
    extern void **gCurrentMap;
    extern M2C_UNK data_02168f08;

    void *base;
    u32 r3;
    u8 *r1;
    u16 idx;
    u8 val;
    u16 tmp;

    func_020c0a1c(3);
    base = *gCurrentMap;
    r3 = M2C_FIELD(base, u32 *, 0);
    r1 = (u8 *)r3 + 0x5200;
    idx = M2C_FIELD(r1, u16 *, 0xa4);
    val = M2C_FIELD((void *)r3, u8 *, idx * 0x8c + 0x67c2);

    switch (val) {
    case 0:
        return;
    case 1:
        tmp = M2C_FIELD(&data_02168f08, u16 *, 0xc);
        if ((((u32)tmp << 22) >> 31) == 0) {
            M2C_FIELD(r1, u16 *, 0xb0) = 0xd;
            return;
        }
        M2C_FIELD(r1, u16 *, 0xb0) = 0xe;
        func_ov000_0219c7c4();
        return;
    case 2:
        M2C_FIELD(r1, u16 *, 0xb0) = 0xe;
        func_ov000_0219c7c4();
        return;
    case 3:
    case 4:
    case 5:
    case 6:
        M2C_FIELD(r1, u16 *, 0xb0) = 0x13;
        return;
    default:
        return;
    }
}

void func_020d4400(void) {
    M2C_UNK func_0208f8a0();
    extern void **gCurrentMap;
    if (func_0208f8a0() != 0) {
        return;
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 5;
}

