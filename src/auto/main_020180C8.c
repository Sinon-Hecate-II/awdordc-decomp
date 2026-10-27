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

s32 func_020182b0(s32 arg0, s32 arg1, s32 arg2) {
extern M2C_UNK data_02136c40;
void func_02017158(void);
void *p;
s32 result;
u16 a = arg1;
u16 b = arg2;
p = M2C_FIELD(&data_02136c40, void **, 8);
if (M2C_FIELD(p,u16 *,0x528) == 0 || M2C_FIELD(p,u16 *,0x526) == 1) return 1;
switch (M2C_FIELD(p,u16 *,0x524)) {
case 1:
result = func_02018264(M2C_FIELD(p,s32 *,0x508),arg0,a,(u16)(M2C_FIELD(p,u16 *,0x52c) == 0 ? 1000 : 0),b);
if (result == 2) M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u8 *,0x50c)=1;
if (result == 2) return 0;
return result;
case 2:
result = func_02018264((s32)func_02017158,arg0,a,0,b);
if (result == 2) M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u8 *,0x50c)=1;
if (result == 2) return 0;
return result;
}
return 1;
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

void func_02018584(void *r7) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02005f80(void *, s32);
    void func_02005da4(s32);
    s32 func_02006028(void *);
    void func_02005bbc(void);

    s32 saved;
    void *r4;
    void (*r6)(void *);

    while (1) {
        saved = func_0200751c();
        if (M2C_FIELD(r7, void **, 0xc0) == (void *)0) {
            do {
                r6 = (void (*)(void *))0;
                r4 = (void *)0;
                func_02005f80(r7, 0);
                func_02005da4(0);
            } while (M2C_FIELD(r7, void **, 0xc0) == (void *)0);
        }
        r4 = M2C_FIELD(r7, void **, 0xc0);
        M2C_FIELD(r7, void **, 0xc0) = M2C_FIELD(r4, void **, 0x0);
        func_02005f80(r7, (s32)(M2C_FIELD(r4, u32 *, 0x4) >> 1));
        func_02007530(saved);
        if (M2C_FIELD(r4, void **, 0x8) != (void *)0) {
            ((void (*)(void *))M2C_FIELD(r4, void **, 0x8))(r4);
        }
        saved = func_0200751c();
        r6 = (void (*)(void *))M2C_FIELD(r4, void **, 0xc);
        {
            s32 val = func_02006028(r7);
            s32 adj;
            if (M2C_FIELD(r7, void **, 0xc0) == (void *)0) {
                adj = 0;
            } else {
                u32 half = M2C_FIELD(M2C_FIELD(r7, void **, 0xc0), u32 *, 0x4) >> 1;
                adj = (u32)val >= half ? val : (s32)half;
            }
            if (adj != val) {
                func_02005f80(r7, adj);
            }
        }
        M2C_FIELD(r4, void **, 0x0) = (void *)0;
        M2C_FIELD(r4, u32 *, 0x4) = (u32)(M2C_FIELD(r4, u32 *, 0x4) & ~1u);
        if (r6 != (void (*)(void *))0) {
            r6(r4);
        }
        if (r4 != (void *)((u8 *)r7 + 0xc4)) {
            func_02007530(saved);
            continue;
        }
        func_02005bbc();
        return;
    }
}

void func_0201869c(M2C_UNK arg0, s32 arg1) {
    extern s32 data_02136c80;
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02018738(M2C_UNK);
    void func_02005ac0(M2C_UNK, void (*)(void *), M2C_UNK, M2C_UNK, s32, s32);
    void func_02005e5c(M2C_UNK);
    void func_02018584(void *);
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

void func_02018764(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
    extern s32 data_02136c80;
    s32 func_0201871c(void);
    s32 func_02006028(void *);
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02005e5c(M2C_UNK);
    s32 saved;
    void *base;
    void *p;
    s32 r6;
    base = (void *)data_02136c80;
    p = (void *)arg0;
    if (!func_0201871c()) {
        return;
    }
    if (M2C_FIELD(p, u32 *, 4) & 1) {
        return;
    }
    r6 = arg3;
    if (r6 > 0x1f) {
        s32 v = func_02006028(base);
        if (r6 == 0x20) {
            r6 = (v == 0) ? 0 : v - 1;
        } else if (r6 == 0x21) {
            r6 = (v < 0x1f) ? v + 1 : 0x1f;
        } else if (r6 == 0x22) {
            r6 = v;
        } else {
            r6 = 0x1f;
        }
    }
    saved = func_0200751c();
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~1u) | 1u;
    M2C_FIELD(p, u32 *, 4) = (u32)(1u | ((u32)r6 << 1));
    M2C_FIELD(p, void **, 8) = (void *)arg1;
    M2C_FIELD(p, void **, 0xc) = (void *)arg2;
    if (M2C_FIELD(base, void **, 0xc0) == (void *)0) {
        if (p == (void *)((u8 *)base + 0xc4)) {
            data_02136c80 = 0;
        }
        M2C_FIELD(base, void **, 0xc0) = p;
        M2C_FIELD(p, void **, 0) = (void *)0;
        func_02005e5c((M2C_UNK)base);
    } else {
        if (p == (void *)((u8 *)base + 0xc4)) {
            void **curp = (void **)M2C_FIELD(base, void ***, 0xc0);
            while (M2C_FIELD(curp, void **, 0) != (void *)0) {
                curp = (void **)M2C_FIELD(curp, void **, 0);
            }
            M2C_FIELD(curp, void **, 0) = p;
            data_02136c80 = 0;
        } else {
            void **head = (void **)M2C_FIELD(base, void ***, 0xc0);
            if ((u32)r6 < (M2C_FIELD(head, u32 *, 4) >> 1)) {
                M2C_FIELD(base, void **, 0xc0) = p;
                M2C_FIELD(p, void **, 0) = (void *)head;
            } else {
                void **prev = head;
                void **cur;
                for (;;) {
                    cur = (void **)M2C_FIELD(prev, void **, 0);
                    if (cur == (void *)0) {
                        break;
                    }
                    if ((u32)r6 < (M2C_FIELD(cur, u32 *, 4) >> 1)) {
                        break;
                    }
                    prev = cur;
                }
                if (cur != (void *)0) {
                    M2C_FIELD(p, void **, 0) = (void *)cur;
                } else {
                    M2C_FIELD(p, void **, 0) = (void *)0;
                }
                M2C_FIELD(prev, void **, 0) = p;
            }
        }
    }
    func_02007530(saved);
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

void *func_02018a28(u8 *arg0, u8 *arg1, s32 arg2) {
    extern M2C_UNK data_02136c84;
    s32 func_02018bd0(s32);
    s32 func_02018b44(u8 *, s32);
    void func_02008048(M2C_UNK, M2C_UNK, s32);

    s32 r4 = arg2;
    u8 type = arg0[0];

    arg1[0] = type;
    switch (type) {
    case 7:
        if (func_02018bd0(r4) != 0) {
            return (void *)(M2C_FIELD(&data_02136c84, M2C_UNK *, 4) + (r4 - 1) * 32);
        }
        {
            u8 v = arg0[1];
            arg1[2] = v;
            if (v > M2C_FIELD(&data_02136c84, s32 *, 0xC)) {
                return (void *)0;
            }
            func_02008048((M2C_UNK)(arg0 + 2), (M2C_UNK)(arg1 + 3), M2C_FIELD(&data_02136c84, s32 *, 8));
            r4 = func_02018b44(arg1, r4);
        }
        break;
    case 8:
        r4 = (s32)(arg0 + 3);
        *(u16 *)(arg1 + 2) = arg0[1];
        *(u16 *)(arg1 + 2) = (u16)(*(u16 *)(arg1 + 2) | ((arg0[2] << 8) & 0xFF00));
        break;
    case 9:
        r4 = (s32)(arg0 + 3);
        *(u16 *)(arg1 + 2) = arg0[1];
        *(u16 *)(arg1 + 2) = (u16)(*(u16 *)(arg1 + 2) | ((arg0[2] << 8) & 0xFF00));
        func_02008048((M2C_UNK)r4, (M2C_UNK)(arg1 + 4), M2C_FIELD(&data_02136c84, s32 *, 8));
        r4 = r4 + M2C_FIELD(&data_02136c84, s32 *, 8);
        break;
    default:
        return (void *)0;
    }
    return (void *)r4;
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

s32 func_02018c9c(void) {
    extern M2C_UNK data_02136c98;
    extern M2C_UNK data_027ffc30;
    void func_02018e24(M2C_UNK, void *);
    void func_02018da8(void *);
    void func_02018df0(void *);
    void func_02018e80(M2C_UNK, void *);
    s32 buf[4];
    s32 r4;
    volatile u8 *base;
    u8 r2;

    r4 = 1;
    base = (volatile u8 *)0x08000000;

    if (M2C_FIELD(&data_027ffc30, u16 *, 0) == (u16)0xFFFF) {
        return 0;
    }
    if (((M2C_FIELD(&data_027ffc30, u8 *, 5) << 30) >> 31) == 1) {
        return 0;
    }
    func_02018e24(M2C_FIELD(&data_02136c98, u16 *, 6), (void *)(&buf[2]));
    func_02018da8((void *)buf);

    r2 = base[0xB2];
    if (r2 == 0x96) {
        if (M2C_FIELD(&data_027ffc30, u16 *, 0) != *(volatile u16 *)(base + 0xBE)) {
            goto fail;
        }
    } else {
        if (M2C_FIELD(&data_027ffc30, u16 *, 0) != *(volatile u16 *)0x0801FFFE) {
            goto fail;
        }
    }
    if (M2C_FIELD(&data_027ffc30, u32 *, 8) != *(volatile u32 *)(base + 0xAC)) {
        if (M2C_FIELD(&data_027ffc30, u8 *, 5) & 1) {
            r4 = 0;
            M2C_FIELD(&data_027ffc30, u8 *, 5) |= 2;
            func_02018df0((void *)buf);
            func_02018e80(M2C_FIELD(&data_02136c98, u16 *, 6), (void *)(&buf[2]));
        }
    }
    return r4;

fail:
    return 0;
}

void func_02018da8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((s32) (*(u16 *)0x04000204 & 0xC) >> 2);
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((s32) (*(u16 *)0x04000204 & 0x10) >> 4);
    *(u16 *)0x04000204 = (*(u16 *)0x04000204 & ~0xC) | 0xC;
    *(u16 *)0x04000204 &= ~0x10;
}

void func_02018df0(void *arg0) {
    volatile u16 *p = (volatile u16 *)0x04000204;
    u16 h;
    s32 a;
    s32 b;
    h = *p;
    a = *(s32 *)arg0;
    h = (u16)((h & ~0xC) | (a << 2));
    *p = h;
    h = *p;
    b = *((s32 *)arg0 + 1);
    h = (u16)((h & ~0x10) | (b << 4));
    *p = h;
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

void func_02018e80(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_020054c0(void);
    void func_02007530(s32);
    void *r4 = arg1;
    s32 tmp = M2C_FIELD(r4, s32 *, 0);
    if (tmp == 0) {
        func_020054c0();
    }
    func_02007530(M2C_FIELD(r4, s32 *, 4));
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

