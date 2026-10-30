/* 37 functions from 0x02183A20 to 0x02184960 (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02183a20(void) {
    s32 func_ov001_02183d80(void);
    void func_ov001_02183cec(s8);
    s32 func_ov001_02183e0c(void);
    void func_ov001_02183d18(void);
    void func_ov001_02183ba4(void);
    void func_ov001_02185024(s32);
    void func_ov001_02185048(s32);
    void func_ov001_0218bd64(M2C_UNK *);
    extern void *data_ov001_02193dfc;
    s32 r;

    M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1d) = 0;
    switch ((u8)M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1c)) {
        case 0: {
            r = (s32)(u8)M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1e);
            if (r != 0) {
                return;
            }
            r = func_ov001_02183d80();
            switch (r) {
                case 0:
                    return;
                case 1: {
                    if ((u8)M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1b) == 0) {
                        return;
                    }
                    func_ov001_02185024(0x16);
                    func_ov001_02185048(0);
                    M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1d) = 1;
                    func_ov001_0218bd64((M2C_UNK *)((u8 *)data_ov001_02193dfc + 0x14));
                    M2C_FIELD(data_ov001_02193dfc, u8 *, 0x18) = M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1a);
                    M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1c) = 1;
                    return;
                }
                case 2:
                    func_ov001_02183cec(2);
                    return;
                case 3:
                    func_ov001_02183cec(3);
                    return;
                case 4:
                    func_ov001_02183d18();
                    return;
                default:
                    return;
            }
        }
        case 1:
            func_ov001_02183ba4();
            return;
        case 2: {
            r = ((s32 (*)(s32))func_ov001_02183e0c)(2);
            if (r != 2) {
                M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1d) = 5;
                M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1c) = 0;
                return;
            }
            r = func_ov001_02183d80();
            if (r != 2) {
                return;
            }
            func_ov001_02183cec(2);
            return;
        }
        case 3: {
            r = ((s32 (*)(s32))func_ov001_02183e0c)(3);
            if (r != 3) {
                M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1d) = 7;
                M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1c) = 0;
                return;
            }
            r = func_ov001_02183d80();
            if (r != 3) {
                return;
            }
            func_ov001_02183cec(3);
            return;
        }
        default:
            return;
    }
}

void func_ov001_02183ba4(void) {
    s32 func_ov001_0218bb6c(M2C_UNK *);
    void func_ov001_0218bd64(M2C_UNK *);
    void func_ov001_02183c74(s32);
    void func_ov001_02183f30(s32);
    void func_ov001_0218508c(void);
    extern void *data_ov001_02193dfc;
    extern u8 data_ov001_0218fb5c[];
    extern u8 data_ov001_0218fd20[];
    M2C_UNK sp0;
    void *base;
    s32 r4;
    u16 spf0;
    u16 spf2;
    s32 thr;

    if (func_ov001_0218bb6c((M2C_UNK *)data_ov001_0218fd20) != 0) {
        func_ov001_0218bd64(&sp0);
        spf0 = M2C_FIELD(&sp0, u16 *, 0x0);
        base = data_ov001_02193dfc;
        thr = M2C_FIELD(base, u16 *, 0x10) - 0x1e;
        if (spf0 >= thr) {
            spf2 = M2C_FIELD(&sp0, u16 *, 0x2);
            r4 = (s32)(u8)M2C_FIELD(base, u8 *, 0x18) + ((s32)spf2 - (s32)(u16)M2C_FIELD(base, u16 *, 0x16));
            if (r4 < 0) {
                r4 = 0;
            } else {
                s32 lim = (s32)(u8)M2C_FIELD(base, u8 *, 0x19) - (s32)(u8)data_ov001_0218fb5c[(u8)M2C_FIELD(base, u8 *, 0x1b)];
                if (r4 >= lim) {
                    r4 = lim;
                }
            }
            func_ov001_02183c74(r4);
            func_ov001_02183f30(r4);
            M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1d) = 2;
            return;
        }
    }
    func_ov001_0218508c();
    M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1c) = 0;
    M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1d) = 3;
}

void func_ov001_02183c74(s32 arg0) {
    s32 func_02002088(s32, s32);
    void func_ov001_02185048(M2C_UNK);
    void func_ov001_02185068(s32, s32);
    extern void *data_ov001_02193dfc;
    s32 field;
    s32 r4;
    s32 r1;

    field = M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1A);
    r4 = field - arg0;
    if (r4 < 0) {
        r4 = -r4;
    }
    func_ov001_02185048(r4 < 2 ? 0 : (r4 >= 6 ? 0x7F : func_02002088(0x7F, 6 - r4)));
    r1 = r4 < 2 ? -256 : (r4 >= 6 ? 0x100 : func_02002088(0x200, 6 - r4) - 0x100);
    func_ov001_02185068(0xFFFF, r1);
}

void func_ov001_02183cec(s8 arg0) {
    extern void *data_ov001_02193dfc;
    s8 var_r1;

    M2C_FIELD(data_ov001_02193dfc, s8 *, 0x1C) = arg0;
    if (arg0 == 2) {
        var_r1 = 4;
    } else {
        var_r1 = 6;
    }
    M2C_FIELD(data_ov001_02193dfc, s8 *, 0x1D) = var_r1;
}

#pragma peephole off
void func_ov001_02183d18(void) {
    void func_ov001_0218bd64(M2C_UNK *);
    void func_ov001_02183f30(s32);
    extern void *data_ov001_02193dfc;
    extern u8 data_ov001_0218fb5c[];
    M2C_UNK sp0;
    u32 arrval;
    u16 field12;
    u16 sp_half;
    s32 v;
    u8 field19;
    s32 lim;

    func_ov001_0218bd64(&sp0);
    arrval = data_ov001_0218fb5c[M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1B)];
    field12 = M2C_FIELD(data_ov001_02193dfc, u16 *, 0x12);
    sp_half = M2C_FIELD(&sp0, u16 *, 0x2);
    v = (s32)sp_half - (s32)field12;
    v -= (s32)(arrval >> 1);
    if (v < 0) {
        v = 0;
    } else {
        field19 = M2C_FIELD(data_ov001_02193dfc, u8 *, 0x19);
        lim = (s32)field19 - (s32)arrval;
        if (v >= lim) {
            v = lim;
        }
        func_ov001_02183f30(v);
    }
    M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1D) = 3;
}
#pragma peephole reset
s32 func_ov001_02183d80(void) {
    void func_ov001_02183e58(s32, M2C_UNK *);
    s32 func_ov001_0218bbd8(M2C_UNK *);
    s32 func_ov001_0218bc44(M2C_UNK *);
    s32 sp0[2];
    s32 var_r5;

    func_ov001_02183e58(1, sp0);
    if (func_ov001_0218bc44(sp0) != 0) {
        return 1;
    }
    var_r5 = 2;
loop_3:
    func_ov001_02183e58(var_r5, sp0);
    if (func_ov001_0218bc44(sp0) != 0) {
        return var_r5;
    }
    var_r5 += 1;
    if (var_r5 > 3) {
        func_ov001_02183e58(4, sp0);
        if (func_ov001_0218bbd8(sp0) != 0) {
            return 4;
        }
        return 0;
    }
    goto loop_3;
}

s32 func_ov001_02183e0c(void) {
    void func_ov001_02183e58(s32, M2C_UNK *);
    s32 func_ov001_0218bb6c(M2C_UNK *);
    s32 sp0[2];
    s32 var_r5;

    var_r5 = 2;
loop_1:
    func_ov001_02183e58(var_r5, sp0);
    if (func_ov001_0218bb6c(sp0) != 0) {
        return var_r5;
    }
    var_r5 += 1;
    if (var_r5 <= 3) {
        goto loop_1;
    }
    return 0;
}

void func_ov001_02183e58(s32 arg0, M2C_UNK *arg1) {
    extern void *data_ov001_02193dfc;
    extern u8 data_ov001_0218fb5c[];
    u16 f10;
    f10 = M2C_FIELD(data_ov001_02193dfc, u16 *, 0x10);
    M2C_FIELD(arg1, u16 *, 0x0) = f10;
    M2C_FIELD(arg1, u16 *, 0x4) = (u16)(f10 + 0xC);
    switch (arg0) {
        case 0:
        default:
            break;
        case 1: {
            M2C_FIELD(arg1, u16 *, 0x2) = (u16)(M2C_FIELD(data_ov001_02193dfc, u16 *, 0x12) + M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1A));
            M2C_FIELD(arg1, u16 *, 0x6) = (u16)(M2C_FIELD(arg1, u16 *, 0x2) + (u16)data_ov001_0218fb5c[M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1B)]);
            break;
        }
        case 2: {
            M2C_FIELD(arg1, u16 *, 0x2) = (u16)(M2C_FIELD(data_ov001_02193dfc, u16 *, 0x12) - 0xD);
            M2C_FIELD(arg1, u16 *, 0x6) = M2C_FIELD(data_ov001_02193dfc, u16 *, 0x12);
            break;
        }
        case 3: {
            M2C_FIELD(arg1, u16 *, 0x2) = (u16)(M2C_FIELD(data_ov001_02193dfc, u16 *, 0x12) + M2C_FIELD(data_ov001_02193dfc, u8 *, 0x19));
            M2C_FIELD(arg1, u16 *, 0x6) = (u16)(M2C_FIELD(arg1, u16 *, 0x2) + 0xD);
            break;
        }
        case 4: {
            u16 f12;
            f12 = M2C_FIELD(data_ov001_02193dfc, u16 *, 0x12);
            M2C_FIELD(arg1, u16 *, 0x2) = f12;
            M2C_FIELD(arg1, u16 *, 0x6) = (u16)(f12 + M2C_FIELD(data_ov001_02193dfc, u8 *, 0x19));
            break;
        }
    }
}

void func_ov001_02183f30(s32 arg0) {
    s32 func_ov001_0218a384(M2C_UNK, s32, u16, s32);
    extern void *data_ov001_02193dfc;
    u16 f10;
    u16 f12;
    void *nested;
    void *base;

    base = data_ov001_02193dfc;
    f12 = M2C_FIELD(base, u16 *, 0x12);
    f10 = M2C_FIELD(base, u16 *, 0x10);
    nested = M2C_FIELD(base, void **, 0x0);
    func_ov001_0218a384(nested, -1, f10, arg0 + (s32)f12);
    M2C_FIELD(data_ov001_02193dfc, s8 *, 0x1A) = (s8)arg0;
}

void func_ov001_02183f6c(void) {
    s32 func_ov001_0218b6f8(s32, M2C_UNK);
    extern s32 data_ov001_02193e00;
    if (data_ov001_02193e00 != 0) {
        return;
    }
    data_ov001_02193e00 = func_ov001_0218b6f8(0x1E60, 0x20);
}

#pragma push
#pragma peephole off
void func_ov001_02183fa0(void) {
    u16 func_02011d58(void);
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern M2C_UNK data_ov001_02193e00;
    if (data_ov001_02193e00 == 0) return;
    while (func_02011d58() != 0x8000) {}
    func_ov001_0218b71c(&data_ov001_02193e00);
}
#pragma pop
s32 func_ov001_02183fd4(void) {
    s32 func_02007df8(s32, void *, s32);
    s32 func_02012218(void *, void (*)(void), s32);
    s32 func_02011af8(void *);
    u16 func_02011e98(void);
    s32 func_ov001_021840a0(void);
    void func_ov001_021841cc();
    extern s32 data_ov001_02193e00;
    extern u32 data_ov001_0218fb6c[];
    typedef struct { u32 w[17]; } Blk;
    s32 *gp = (s32 *)&data_ov001_02193e00;

    func_02007df8(0, (u8 *)(*gp) + 0x1300, 0x348);
    if (func_02012218((void *)(*gp), (void (*)(void))func_ov001_021841cc, 3) != 2) {
        return 0;
    }
    func_02011af8((void *)((u8 *)(*gp) + 0x168c));
    {
        u8 *base = (u8 *)(*gp);
        if (*(u16 *)(base + 0x168c) == 2) {
            const u32 *srcp = (const u32 *)data_ov001_0218fb6c;
            s32 n = 4;
            (void)n;
            *(Blk *)(base + 0x1648) = *(const Blk *)srcp;
            *(u8 **)(base + 0x1648) = base + 0xf00;
            *(u16 *)((u8 *)(*(s32 *)&data_ov001_02193e00) + 0x1650) = func_02011e98();
        }
    }
    return func_ov001_021840a0() ? 1 : 0;
}

s32 func_ov001_021840a0(void) {
    s32 func_020125b0(void (*)(void), void *);
    void func_ov001_021841cc();
    extern s32 data_ov001_02193e00;
    void *base = (void *)data_ov001_02193e00;
    if (func_020125b0(func_ov001_021841cc, (s8 *)base + 0x1648) == 2) {
        return 1;
    }
    return 0;
}

s32 func_ov001_021840d4(void) {
    s32 func_02011af8(void *);
    s32 func_02012274(void (*)(void));
    s32 func_020122ac(void (*)(void));
    void func_ov001_021841cc();
    extern s32 data_ov001_02193e00;

    *(u8 *)((s8 *)data_ov001_02193e00 + 0x1e5c) = 1;
    func_02011af8((void *)((s8 *)data_ov001_02193e00 + 0x168c));
    if (*(u16 *)((s8 *)data_ov001_02193e00 + 0x168c) != 2) {
        if (func_02012274(func_ov001_021841cc) != 2) {
            return 0;
        }
        do {
            func_02011af8((void *)((s8 *)data_ov001_02193e00 + 0x168c));
        } while (*(u16 *)((s8 *)data_ov001_02193e00 + 0x168c) != 2);
    }
    if (func_020122ac(func_ov001_021841cc) != 2) {
        return 0;
    }
    return 1;
}

s32 func_ov001_02184170(void **arg0) {
    s32 func_0206527c(M2C_UNK, M2C_UNK, s32);
    extern u8 data_ov001_0218fb64[];
    extern s32 data_ov001_02193e00;
    u8 *r5 = data_ov001_0218fb64;
    u8 *r8 = (u8 *)data_ov001_02193e00 + 0x1300;
    s32 r6 = 0;
    s32 r7 = 0;

    *arg0 = r8;
    while (r7 < 20) {
        if (func_0206527c((M2C_UNK)(r8 + 0x20), (M2C_UNK)r5, 6) != 0) {
            r6 = r6 + 1;
        }
        r7 = r7 + 1;
        r8 = r8 + 0x2a;
    }
    return r6;
}

void func_ov001_021841cc(u16 *p) {
    s32 func_ov001_021840a0(void);
    void func_ov001_02184230(u16 *);
    void func_02007958(u16 *);
    extern s32 data_ov001_02193e00;
    u8 *q;

    if (p[1]) {
        return;
    }
    q = (u8 *)data_ov001_02193e00 + 0x1000;
    if (q[0xe5c] == 0 && p[0] == 0x26) {
        switch (p[4]) {
            case 5:
                func_ov001_02184230(p);
                func_ov001_021840a0();
                break;
            case 4:
                func_ov001_021840a0();
                break;
            default:
                func_02007958(p);
                break;
        }
    }
}

void func_ov001_02184230(u16 *arg0) {
    void func_020067a8(void *, s32);
    void func_02008048(void *, void *, u32);
    s32 func_0206527c(M2C_UNK, M2C_UNK, s32);
    void func_02011f2c(M2C_UNK *, M2C_UNK *);
    extern s32 data_ov001_02193e00;
    extern u8 data_ov001_0218fb64[];
    extern u8 data_ov001_0218fb60[];

    typedef struct { u8 kind; u8 length; u8 pad[2]; void *data; } ParsedItem;
    typedef struct { u8 count; u8 pad[3]; ParsedItem items[16]; } ParsedItems;

    u8 *base = (u8 *)arg0;
    u8 *slots = (u8 *)data_ov001_02193e00 + 0x1300;
    s32 cnt = *(s16 *)(base + 0xe);
    s32 i;

    func_020067a8((void *)((u8 *)data_ov001_02193e00 + 0xf00), 0x400);

    for (i = 0; i < cnt; i++) {
        u8 *r4 = *(u8 **)(base + 0x10 + i * 4);
        s32 j;
        u8 *slot;
        if (r4[0xc] == 0) continue;
        if (*(u16 *)(r4 + 0x3c) != 0) continue;

        /* first search */
        slot = slots;
        j = 0;
        for (;;) {
            if (func_0206527c((M2C_UNK)(slot + 0x20), (M2C_UNK)(r4 + 4), 6) == 0) {
                break;
            }
            j++;
            if (j >= 20) {
                break;
            }
            slot += 0x2a;
        }

        if (j == 20) {
            s32 jj;
            slot = slots;
            jj = 0;
            for (;;) {
                if (func_0206527c((M2C_UNK)(slot + 0x20), (M2C_UNK)data_ov001_0218fb64, 6) == 0) {
                    break;
                }
                jj++;
                if (jj >= 20) {
                    break;
                }
                slot += 0x2a;
            }
            if (jj == 20) {
                return;
            }
            slot = slots + jj * 0x2a;
        } else {
            slot = slots + j * 0x2a;
        }

        func_02008048((void *)(r4 + 4), (void *)(slot + 0x20), 6);
        func_02008048((void *)(r4 + 0xc), (void *)slot, 0x20);
        *(u16 *)(slot + 0x26) = *(u16 *)(base + 0x50 + i * 2);

        if (((*(u16 *)(r4 + 0x2c)) & 0x10) == 0) {
            slot[0x28] = 0;
            continue;
        }

        slot[0x28] = 1;
        {
            ParsedItems parsed;
            u8 pc;
            s32 k;
            func_02011f2c((M2C_UNK *)&parsed, (M2C_UNK *)r4);
            pc = parsed.count;
            if (pc > 0) {
                for (k = 0; k < pc; k++) {
                    if (parsed.items[k].kind == 0x30) {
                        slot[0x28] = 2;
                        break;
                    }
                    if (parsed.items[k].kind == 0xdd &&
                        parsed.items[k].length >= 4) {
                        if (func_0206527c((M2C_UNK)parsed.items[k].data,
                                            (M2C_UNK)data_ov001_0218fb60, 4) == 0) {
                            slot[0x28] = 2;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void func_ov001_02184404(void) {
    s32 func_ov001_0218b6f8(s32, M2C_UNK);
    void func_02076710(u16 *, u32);
    s32 func_02045eb4(M2C_UNK);
    extern s32 data_ov001_02193e04;

    data_ov001_02193e04 = func_ov001_0218b6f8(0x6f8, 0x20);
    func_02076710((u16 *)(data_ov001_02193e04 + 0x4f8), 0xa001);
    func_02045eb4((M2C_UNK)data_ov001_02193e04);
}

void func_ov001_02184448(void) {
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern M2C_UNK data_ov001_02193e04;
    func_ov001_0218b71c(&data_ov001_02193e04);
}

s32 func_ov001_0218445c(void) {
    extern s32 data_ov001_02193e04;
    return data_ov001_02193e04 + 0x400;
}

void func_ov001_02184470(s8 arg0) {
    extern s32 data_ov001_02193e04;
    M2C_FIELD((void *)data_ov001_02193e04, s8 *, 0x4f5) = arg0;
}

void func_ov001_02184484(s8 arg0) {
    extern s32 data_ov001_02193e04;
    M2C_FIELD((void *)data_ov001_02193e04, s8 *, 0x4f6) = arg0;
}

void func_ov001_02184498(void *arg0) {
    void func_02008048(void *, void *, u32);
    extern s32 data_ov001_02193e04;
    func_02008048(arg0, (void *)((s8 *)data_ov001_02193e04 + 0x440), 0x20);
    *(u8 *)((s8 *)data_ov001_02193e04 + 0x4e7) = 0;
}

void func_ov001_021844c8(u8 *arg0) {
    void func_02007f8c(void *, s32, u32);
    void func_02008048(void *, void *, u32);
    s32 func_ov001_0218c3e0(u8 *, s32);
    s32 func_ov001_02184f4c(u8);
    extern s32 data_ov001_02193e04;

    u8 *base;
    s32 r5;
    base = (u8 *)data_ov001_02193e04;

    func_02007f8c(base + 0x480, 0, 0x10);
    r5 = func_ov001_0218c3e0(arg0, 0x20);

    switch (r5) {
        case 0:
        case 10:
        case 0x1a:
        case 0x20: {
            u8 *r8 = base + 0x480;
            s32 r4 = 0;
            base[0x4e6] = (u8)(base[0x4e6] & 0x03);
            if (r5 > 0) {
                do {
                    s32 hi = func_ov001_02184f4c(arg0[r4]);
                    s32 lo = func_ov001_02184f4c(arg0[r4 + 1]);
                    *r8++ = (u8)((hi << 4) | lo);
                    r4 += 2;
                } while (r4 < r5);
            }
            break;
        }
        default: {
            base[0x4e6] = (u8)((base[0x4e6] & 0x03) | 0x04);
            func_02008048(arg0, base + 0x480, 0x10);
            break;
        }
    }

    switch (r5) {
        case 0:
            base[0x4e6] = (u8)(base[0x4e6] & 0xfc);
            break;
        case 5:
        case 10:
            base[0x4e6] = (u8)((base[0x4e6] & 0xfc) | 0x01);
            break;
        case 13:
        case 0x1a:
            base[0x4e6] = (u8)((base[0x4e6] & 0xfc) | 0x02);
            break;
        default:
            base[0x4e6] = (u8)((base[0x4e6] & 0xfc) | 0x03);
            break;
    }
}

void func_ov001_02184660(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 data_ov001_02193e04;
    func_ov001_02184ec4(arg0, (u8 *)data_ov001_02193e04 + 0x4c0);
}

void func_ov001_0218467c(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 data_ov001_02193e04;
    func_ov001_02184ec4(arg0, (u8 *)data_ov001_02193e04 + 0x4f0);
}

void func_ov001_02184698(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 data_ov001_02193e04;
    func_ov001_02184ec4(arg0, (u8 *)data_ov001_02193e04 + 0x4c4);
}

void func_ov001_021846b8(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 data_ov001_02193e04;
    func_ov001_02184ec4(arg0, (u8 *)data_ov001_02193e04 + 0x4c8);
}

void func_ov001_021846d8(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 data_ov001_02193e04;
    func_ov001_02184ec4(arg0, (u8 *)data_ov001_02193e04 + 0x4cc);
}

void func_ov001_021846f8(u8 *arg0) {
    void func_02008048(void *, void *, u32);
    extern s32 data_ov001_02193e04;
    func_02008048((void *)((u8 *)data_ov001_02193e04 + 0x440), arg0, 0x20);
}

void func_ov001_0218471c(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 data_ov001_02193e04;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)data_ov001_02193e04;
    u8 t0 = p[0x4c2];
    u8 t1 = p[0x4c3];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4c0], p[0x4c1], t0, t1);
}

void func_ov001_0218475c(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 data_ov001_02193e04;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)data_ov001_02193e04;
    u8 t0 = p[0x4f2];
    u8 t1 = p[0x4f3];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4f0], p[0x4f1], t0, t1);
}

void func_ov001_0218479c(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 data_ov001_02193e04;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)data_ov001_02193e04;
    u8 *q = (u8 *)((u32)p + 0xc4);
    u8 t0 = q[0x402];
    u8 t1 = q[0x403];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4c4], q[0x401], t0, t1);
}

void func_ov001_021847e0(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 data_ov001_02193e04;
    extern char data_ov001_02190b58[];
    u8 *q;
    u8 *p = (u8 *)data_ov001_02193e04;
    u8 t0;
    u8 t1;

    q = p + 0xc8;
    t0 = q[0x402];
    t1 = q[0x403];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4c8], q[0x401], t0, t1);
}

void func_ov001_02184824(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 data_ov001_02193e04;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)data_ov001_02193e04;
    u8 *q = p + 0xcc;
    u8 t0 = q[0x402];
    u8 t1 = q[0x403];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4cc], q[0x401], t0, t1);
}

u8 func_ov001_02184868(s32 arg0) {
    extern s32 data_ov001_02193e04;
    return *((u8 *)((s8 *)data_ov001_02193e04 + (arg0 << 8) + 0xe7));
}

void func_ov001_02184880(s32 arg0) {
    s32 func_0206527c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02046058(u8, M2C_UNK *);
    extern s32 data_ov001_02193e04;
    extern u8 data_ov001_0218fbb0[];
    u8 *base = (u8 *)data_ov001_02193e04;
    u8 *page = base + (arg0 << 8);
    u8 *src = page;
    u8 *dst = base + 0x400;
    s32 count = 0x78;
    do {
        u8 a = src[0];
        u8 b = src[1];
        dst[0] = a;
        dst[1] = b;
        src += 2;
        dst += 2;
        count--;
    } while (count != 0);
    base[0x4f4] = (u8)arg0;
    if (func_0206527c((M2C_UNK)(page + 0xc0), (M2C_UNK)data_ov001_0218fbb0, 4) == 0) {
        ((u8 *)data_ov001_02193e04)[0x4f5] = 1;
    } else {
        ((u8 *)data_ov001_02193e04)[0x4f5] = 0;
    }
    if (func_0206527c((M2C_UNK)(page + 0xc8), (M2C_UNK)data_ov001_0218fbb0, 4) != 0) {
        ((u8 *)data_ov001_02193e04)[0x4f6] = 0;
    } else if (func_0206527c((M2C_UNK)(page + 0xcc), (M2C_UNK)data_ov001_0218fbb0, 4) == 0) {
        ((u8 *)data_ov001_02193e04)[0x4f6] = 1;
    } else {
        ((u8 *)data_ov001_02193e04)[0x4f6] = 0;
    }
    func_02046058(page[0xd0], (M2C_UNK *)(data_ov001_02193e04 + 0x4f0));
}

