/* 37 functions from 0x020180C8 to 0x02018FF0 (main), found by ds-decomp. */
#include "common.h"

void func_02018254(s16 arg0) {
    extern M2C_UNK data_02136c40;
    M2C_FIELD(&data_02136c40, s16 *, 0x26) = arg0;
}

s32 func_02018264(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4) {
    s32 func_02012c28(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    void func_02018438(M2C_UNK, s32);
    s32 temp_r0;

    temp_r0 = func_02012c28(arg0, 0, arg1, arg2, (s32) arg4, 1, 3);
    func_02018438(0xF, temp_r0);
    return temp_r0;
}

s32 func_02018390(void) {
    extern M2C_UNK data_02136c40;
    return M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), s32 *, 8);
}

u16 func_020183a4(void) {
    extern M2C_UNK data_02136c40;
    return M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), u16 *, 0xC);
}

u8 func_020183b8(void) {
    extern M2C_UNK data_02136c40;
    void *p = M2C_FIELD(&data_02136c40, void **, 8);
    u32 r2 = M2C_FIELD(p, u16 *, 0x12) != 0 ? 2 : 0;
    u32 r3 = M2C_FIELD(p, u16 *, 0xE) != 0 ? 1 : 0;
    u32 r12 = M2C_FIELD(p, u16 *, 0x14) != 0 ? 4 : 0;
    u32 r1 = M2C_FIELD(p, u16 *, 0x16) != 0 ? 8 : 0;
    return (u8)(((r3 | r2) | r12) | r1);
}

s32 func_02018418(void) {
    extern M2C_UNK data_02136c40;
    return M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), u8 *, 0x50d) == 1;
}

void func_02018438(s32 arg0, s32 arg1) {
    extern M2C_UNK data_02136c40;
    u16 buf[2];
    void **p;
    if (arg1 == 2 || arg1 == 0) {
        return;
    }
    buf[0] = (u16)arg0;
    p = M2C_FIELD(&data_02136c40, void **, 8);
    buf[1] = (u16)arg1;
    M2C_FIELD(p, void (**)(s32, void *), 0x51c)(0xff, buf);
}

void func_02018470(M2C_UNK arg0) {
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0x70);
}

s32 func_020184ec(s32 *arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
    s32 func_0200751c(void);
    void func_02008048(s32, M2C_UNK, s32);
    void func_02007530(s32);
    u8 *end;
    s32 result;
    u8 *p;
    s32 temp_r0;
    s32 saved;
    result = 0;
    saved = func_0200751c();
    p = (u8 *)arg0 + 0x30;
    end = (u8 *)arg0 + 0x70;
    for (; p < end; p += 0x10) {
        if (M2C_FIELD(p, u32 *, 0xC) >= 2U) {
            temp_r0 = arg1 - M2C_FIELD(p, s32 *, 0);
            if (0 <= temp_r0) {
                if ((u32)(temp_r0 + arg3) <= (u32)M2C_FIELD(p, u32 *, 4)) {
                    func_02008048(M2C_FIELD(p, s32 *, 8) + temp_r0, arg2, arg3);
                    result = 1;
                    *arg0 = 0;
                    break;
                }
            }
        }
    }
    func_02007530(saved);
    return result;
}

void func_0201869c(M2C_UNK arg0, s32 arg1) {
    extern s32 data_02136c80;
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02018738(M2C_UNK);
    void func_02005ac0(M2C_UNK, void (*)(void), M2C_UNK, M2C_UNK, s32, s32);
    void func_02005e5c(M2C_UNK);
    void func_02018584(void);
    s32 saved;
    saved = func_0200751c();
    if (data_02136c80 == 0) {
        data_02136c80 = arg0;
        func_02018738(arg0 + 0x000000C4);
        M2C_FIELD(arg0, s32 *, 0x000000C0) = 0;
        func_02005ac0(arg0, func_02018584, arg0, arg0 + 0x000000E4 + ((arg1 - 0x000000E4) & ~3), (arg1 - 0x000000E4) & ~3, 0);
        func_02005e5c(arg0);
    }
    func_02007530(saved);
}

s32 func_0201871c(void) {
    extern s32 data_02136c80;
    if (data_02136c80 != 0) {
        return 1;
    }
    return 0;
}

void func_02018738(M2C_UNK arg0) {
    func_02007f8c(arg0, 0, 0x20);
}

s32 func_0201874c(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, s32 *, 4) << 0x1F) >> 0x1F) != 0) {
        return 1;
    }
    return 0;
}

void func_020188c8(M2C_UNK arg0) {
    extern M2C_UNK data_02136c80;
    s32 func_0200751c(void);
    void func_02007530(s32);
    s32 func_0201871c(void);
    void func_02018764(M2C_UNK, s32, M2C_UNK, s32);
    s32 saved;
    saved = func_0200751c();
    if (func_0201871c() != 0) {
        func_02018764((M2C_UNK)((u8 *)data_02136c80 + 0xC4), 0, arg0, 0);
    }
    func_02007530(saved);
}

void func_02018910(s32 arg0) {
    extern M2C_UNK data_02136c84;
    s32 func_020720f0(s32, s32);
    M2C_FIELD(&data_02136c84, s32 *, 8) = arg0 - 2;
    M2C_FIELD(&data_02136c84, s32 *, 12) = func_020720f0(0x1E, arg0 - 2);
    M2C_FIELD(&data_02136c84, s32 *, 16) = 0x1E;
}

void func_02018940(s32 arg0) {
    extern M2C_UNK data_02136c84;
    M2C_FIELD(&data_02136c84, s32 *, 4) = arg0;
    func_02007f8c(arg0, 0, 0x21C);
}

void func_02018960(s32 arg0) {
    extern M2C_UNK data_02136c84;
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 idx;
    M2C_UNK base;
    idx = arg0 - 1;
    base = M2C_FIELD(&data_02136c84, M2C_UNK *, 4);
    if (base == (M2C_UNK)0) {
        return;
    }
    func_02007f8c((M2C_UNK)((u8 *)base + idx * 32), (M2C_UNK)0, (M2C_UNK)0x1E);
    base = M2C_FIELD(&data_02136c84, M2C_UNK *, 4);
    M2C_FIELD((u8 *)base + idx * 4, M2C_UNK *, 0x1E0) = (M2C_UNK)0;
}

void func_02018c24(void) {
    M2C_UNK CpuSet(s32 *, M2C_UNK *, s32);
    s16 func_0200558c();
    extern M2C_UNK data_02136c98;
    extern M2C_UNK data_02136c9c;
    s32 sp0;

    sp0 = 0;
    CpuSet(&sp0, &data_02136c9c, 0x05000001);
    M2C_FIELD(&data_02136c98, s16 *, 6) = func_0200558c();
}

s32 func_02018c5c(void) {
    u32 func_02018c84(void);
    s32 func_02018c9c();
    if ((func_02018c9c() != 0) && (func_02018c84() == 0)) {
        return 1;
    }
    return 0;
}

u32 func_02018c84(void) {
    extern M2C_UNK data_027ffc30;
    return (u32) (M2C_FIELD(&data_027ffc30, u8 *, 5) << 0x1F) >> 0x1F;
}

void func_02018da8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((s32) (*(u16 *)0x04000204 & 0xC) >> 2);
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((s32) (*(u16 *)0x04000204 & 0x10) >> 4);
    *(u16 *)0x04000204 = (*(u16 *)0x04000204 & ~0xC) | 0xC;
    *(u16 *)0x04000204 &= ~0x10;
}

void func_02018df0(void *arg0) {
    *(u16 *)0x04000204 = (*(u16 *)0x04000204 & ~0xC) | (M2C_FIELD(arg0, s32 *, 0) * 4);
    *(u16 *)0x04000204 = (*(u16 *)0x04000204 & ~0x10) | (M2C_FIELD(arg0, s32 *, 4) * 0x10);
}

void func_02018e24(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_0200751c(void);
    void func_02007530(M2C_UNK);
    M2C_UNK func_02005584(M2C_UNK);
    M2C_UNK func_020054cc(M2C_UNK);
    M2C_UNK WaitByLoop(M2C_UNK);
    M2C_UNK saved;
    M2C_UNK r;
    saved = func_0200751c();
    M2C_FIELD(arg1, M2C_UNK *, 4) = saved;
    r = func_02005584((M2C_UNK)0x27FFFE8) & 0x40;
    M2C_FIELD(arg1, M2C_UNK *, 0) = r;
    if (r != 0) {
        return;
    }
    if (func_020054cc(arg0) == 0) {
        return;
    }
    func_02007530(saved);
    WaitByLoop(1);
}

void func_02018ea4(M2C_UNK arg0) {
    M2C_UNK WaitByLoop(M2C_UNK);
    s32 func_02009eb0(M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_02009eb0(0xD, arg0, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(1);
    } while (func_02009eb0(0xD, arg0, 0) != 0);
}

void func_02018ef4(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    s32 func_02018c5c(void);
    void func_02006cc0(s32, s32);
    extern M2C_UNK data_02136c98;
    s32 saved;
    saved = func_0200751c();
    data_02136c98 = (M2C_UNK)arg0;
    if (func_02018c5c() == 0) {
        s32 r1;
        if (arg0 != 0) {
            r1 = 0x1000;
        } else {
            r1 = 0x5000;
        }
        func_02006cc0(0xf000, r1);
    }
    func_02007530(saved);
}

void func_02018f3c(void) {
    M2C_UNK func_02009d34();
    M2C_UNK func_02009e40(M2C_UNK, M2C_UNK *);
    s32 func_02009e8c(M2C_UNK, M2C_UNK);
    void func_02018ef4(M2C_UNK);
    M2C_UNK func_02018ff0();
    M2C_UNK func_02019294(M2C_UNK *);
    extern M2C_UNK data_02136ca0;
    extern M2C_UNK data_02136d80;
    extern M2C_UNK func_020191e4;
    extern M2C_UNK func_02019210;
    extern M2C_UNK func_02019280;
    if (M2C_FIELD(&data_02136ca0, s32 *, 8) != 0) {
        return;
    }
    M2C_FIELD(&data_02136ca0, s32 *, 8) = 1;
    func_02018c24();
    M2C_FIELD(&data_02136ca0, s32 *, 0xC) = 0;
    func_02009d34();
    do {

    } while (func_02009e8c(0xD, 1) == 0);
    func_02009e40(0xD, &func_020191e4);
    func_02018ff0();
    func_02009e40(0xD, NULL);
    func_02009e40(0xD, &func_02019210);
    M2C_FIELD(&data_02136ca0, s32 *, 0x18) = 0;
    func_02019294(&data_02136d80);
    func_02009e40(0x11, &func_02019280);
    func_02018ef4(0);
}

