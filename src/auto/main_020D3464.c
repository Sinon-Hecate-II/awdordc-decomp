/* 30 functions from 0x020D3464 to 0x020D4430 (main), found by ds-decomp. */
#include "common.h"

s32 func_020d3464(void) {
    void func_0209cbe4(void *);
    void func_02081fd4(void);
    void func_0208fe30(s32);
    extern M2C_UNK data_02168f08;
    extern void **gCurrentMap;

    if (M2C_FIELD(&data_02168f08, u16 *, 0x10) == 0) {
        return 0;
    }

    {
        void *base = *gCurrentMap;
        s32 idx = (s32)M2C_FIELD(base, u16 *, 0x52B0) - 13;

        switch (idx) {
        case 0:
        case 8: {
            u16 i = M2C_FIELD(base, u16 *, 0x52A4);
            {
                u8 *p = (u8 *)base + 0x67A4 + i * 0x8C;
                func_0209cbe4(p + 0x88);
            }
            {
                u16 dataVal = M2C_FIELD(&data_02168f08, u16 *, 0x10);
                void *b = *gCurrentMap;
                u16 ii = M2C_FIELD(b, u16 *, 0x52A4);
                u32 *pp = (u32 *)((u8 *)b + ii * 0x8C + 0x682C);
                s32 delta = (s32)dataVal - (s32)*pp;
                if (delta <= 0) {
                    func_02081fd4();
                    b = *gCurrentMap;
                    M2C_FIELD(b, u16 *, 0x52B0) = 0x15;
                    return 1;
                }
                if (delta > 0x258) {
                    break;
                }
                if (delta % 60 != 0) {
                    break;
                }
                func_0208fe30(0x126);
                break;
            }
        }
        case 11:
        case 12:
        case 13: {
            u16 i = M2C_FIELD(base, u16 *, 0x52A4);
            {
                u8 *p = (u8 *)base + 0x67A4 + i * 0x8C;
                func_0209cbe4(p + 0x88);
            }
            break;
        }
        case 7: {
            u16 i = M2C_FIELD(base, u16 *, 0x52A4);
            {
                u8 *p = (u8 *)base + 0x67A4 + i * 0x8C;
                func_0209cbe4(p + 0x88);
            }
        }
        default:
            break;
        }
    }

    return 0;
}

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

s32 func_020d364c(void) {
    M2C_UNK func_ov000_0219c6c0();
    M2C_UNK func_02084644();
    M2C_UNK func_ov009_02224194();
    void func_ov009_022244ec(M2C_UNK);
    M2C_UNK func_ov010_022282f8();
    M2C_UNK func_ov010_02228314(M2C_UNK *, M2C_UNK *);
    void func_ov010_02228298(M2C_UNK);
    M2C_UNK func_02084a6c();
    void func_02081fd4(void);
    extern M2C_UNK data_02168f08;
    extern void **gCurrentMap;

    if (M2C_FIELD(&data_02168f08, u8 *, 4) == 0) {
        return 0;
    }
    if (func_ov000_0219c6c0() != 0) {
        return 0;
    }
    if (M2C_FIELD(&data_02168f08, u8 *, 5) != 0 ||
        M2C_FIELD(&data_02168f08, u8 *, 6) != 0) {
        return 0;
    }

    {
        s32 r4 = 0;
        s32 r5 = 0;
        s32 sw = func_02084644();

        if (sw == 1) {
            if (func_ov009_02224194() == 8) {
                goto ov010;
            }
            if (func_ov009_02224194() != 9) {
                goto tail;
            }
            func_ov009_022244ec(1);
            r4 = 1;
            goto tail;
        } else if (sw == 2) {
            goto ov010;
        } else {
            goto tail;
        }

    ov010: {
            s32 rr = func_ov010_022282f8();
            s32 ok;
            if (rr != 0) {
                ok = 1;
            } else {
                ok = r4;
            }
            if (ok != 0) {
                M2C_UNK a;
                M2C_UNK b;
                func_ov010_02228314(&a, &b);
                switch ((s32)b) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    func_ov010_02228298(6);
                    break;
                default:
                    break;
                }
                r4 = 1;
                if (func_02084a6c() != 0) {
                    r5 = 1;
                }
            }
        }

    tail:
        if (r4 == 0 && r5 == 0) {
            return 0;
        }

        {
            void **gm = gCurrentMap;
            void *outer = *gm;
            void *inner = *(void **)outer;
            u16 *q = (u16 *)((u8 *)inner + 0x5200);
            s32 idx = (s32)q[0xb0 / 2] - 0xd;
            if ((u32)idx > 7) {
                return 0;
            }
            switch (idx) {
            case 0:
            case 1:
            case 6:
            case 7:
                break;
            default:
                return 0;
            }
            M2C_FIELD(&data_02168f08, u8 *, 5) = (u8)r4;
            M2C_FIELD(&data_02168f08, u8 *, 6) = (u8)r5;
            if (r4 != 0) {
                func_02081fd4();
                gm = gCurrentMap;
                outer = *gm;
                inner = *(void **)outer;
                q = (u16 *)((u8 *)inner + 0x5200);
                {
                    u16 old = q[0xb0 / 2];
                    q[0xb2 / 2] = old;
                    q[0xb0 / 2] = 0x17;
                }
            } else if (r5 != 0) {
                func_02081fd4();
                gm = gCurrentMap;
                outer = *gm;
                inner = *(void **)outer;
                q = (u16 *)((u8 *)inner + 0x5200);
                q[0xb0 / 2] = 0x18;
            }
            return 1;
        }
    }

    return 0;
}

void func_020d3830(void) {
    M2C_UNK func_020d4dfc();
    M2C_UNK func_0208b5a8();
    M2C_UNK func_02084644();
    M2C_UNK func_ov009_022241b4();
    void func_ov009_02225fb4(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    M2C_UNK func_ov010_02228314(M2C_UNK *, M2C_UNK *);
    void func_ov010_0222a808(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, void *);
    void func_ov010_02228320();
    void func_ov010_022282d4(M2C_UNK);
    M2C_UNK func_02081fec();
    extern void **gCurrentMap;
    extern M2C_UNK data_02168f08;

    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52B4) != 0) {
        func_020d4dfc();
        return;
    }
    if (func_0208b5a8() != 0) {
        return;
    }
    switch (func_02084644()) {
    case 1:
        func_ov009_02225fb4(0, 0x25c, func_ov009_022241b4(), (void *)7);
        M2C_FIELD(&data_02168f08, u8 *, 7) = 0;
        func_02081fec();
        M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 0x19;
        break;
    case 2: {
        s32 result;
        s32 spare;
        s32 ret = func_ov010_02228314(&result, &spare);
        func_ov010_0222a808(0, 0x25c, ret, result, spare, (void *)7);
        func_ov010_02228320();
        switch (spare) {
        case 0:
        case 1:
        case 2:
            func_ov010_022282d4(6);
            M2C_FIELD(&data_02168f08, u8 *, 5) = 0;
            M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = M2C_FIELD(*gCurrentMap, u16 *, 0x52B2);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            M2C_FIELD(&data_02168f08, u8 *, 7) = 0;
            func_02081fec();
            M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 0x19;
            break;
        case 7:
            break;
        }
        break;
    }
    }
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

#pragma optimization_level 2
void func_020d3aa4(void *arg0) {
    M2C_UNK func_02086330();
    M2C_UNK func_02085054(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02168f08;
    if (M2C_FIELD(&data_02168f08, u8 *, 5) != 0) {
        return;
    }
    if (M2C_FIELD(&data_02168f08, u8 *, 7) != 0) {
        return;
    }
    func_02086330();
    func_02085054(0, 0x25c, arg0);
}
#pragma optimization_level reset
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

void func_020d3b24(void) {
    M2C_UNK func_020d3400();
    M2C_UNK func_020d364c();
    M2C_UNK func_020d3464();
    M2C_UNK func_020d8db0();
    M2C_UNK func_020d46e8();
    M2C_UNK func_020d4774();
    void func_020d4144();
    void func_020d41c4();
    void func_020d422c();
    void func_020d4400();
    void func_020d4430();
    void func_020d447c();
    M2C_UNK func_020d457c();
    void func_020d4280();
    void func_020d42a8();
    void func_020d42d0();
    void func_020d42f8();
    void func_020d432c();
    M2C_UNK func_020d4dfc();
    M2C_UNK func_020d1a1c(M2C_UNK);
    M2C_UNK func_ov000_0219c6e0();
    void func_02084304();
    void func_020d45d8();
    M2C_UNK func_020d4614();
    M2C_UNK func_020d466c();
    void func_020d35d8();
    void func_020d3628();
    void func_020d3830();
    void func_020d3a3c();
    void func_020d3ae4();
    void func_020d3b18();
    extern void **gCurrentMap;

    func_020d3400();

    {
        void *ctl = M2C_FIELD(*gCurrentMap, void **, 4);
        void (*cb)(void) = M2C_FIELD(ctl, void (**)(void), 0x30);
        if (cb != 0) {
            cb();
        }
    }

    if (func_020d364c() != 0) return;
    if (func_020d3464() != 0) return;
    if (func_020d8db0() != 0) return;
    if (func_020d46e8() != 0) return;
    if (func_020d4774() != 0) return;

    {
        void *mainBase = M2C_FIELD(*gCurrentMap, void **, 0);
        u8 *p = (u8 *)mainBase + 0x5200;
        u16 state = *(u16 *)(p + 0xb0);
        if (state > 0x1a) return;
        switch (state) {
        case 0:
            return;
        case 1:
            func_020d4144();
            return;
        case 2:
            func_020d41c4();
            return;
        case 3:
            func_020d422c();
            return;
        case 4:
            func_020d4400();
            return;
        case 5:
            func_020d4430();
            return;
        case 6:
            func_020d447c();
            return;
        case 7:
            func_020d457c();
            return;
        case 8:
            func_020d4280();
            return;
        case 9:
            func_020d42a8();
            return;
        case 10:
            func_020d42d0();
            return;
        case 11:
            func_020d42f8();
            return;
        case 12:
            func_020d432c();
            return;
        case 13:
            func_020d4dfc();
            return;
        case 14:
            return;
        case 15: {
            u16 x = *(u16 *)(p + 0xa4);
            if (func_020d1a1c(x) != 0) {
                func_ov000_0219c6e0();
                return;
            }
            func_02084304();
            return;
        }
        case 16:
            return;
        case 17:
            func_02084304();
            return;
        case 18:
            func_02084304();
            return;
        case 19:
            func_020d45d8();
            return;
        case 20:
            func_020d4614();
            return;
        case 21:
            func_020d466c();
            return;
        case 22:
            func_020d35d8();
            return;
        case 23:
            func_020d3628();
            return;
        case 24:
            func_020d3830();
            return;
        case 25:
            func_020d3a3c();
            return;
        case 26:
            func_020d3ae4();
            return;
        default:
            return;
        }
    }
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

void func_020d3d68(void) {
    u8 *func_020a32f4(s32);
    s32 func_020d243c(s32);
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    void *base;
    u16 cols;
    u16 rows;
    s32 r4;
    s32 r5;
    s32 r6;
    s32 r7;
    s32 val;
    s32 idx;
    s32 end;
    void *p;
    void *rec;
    u8 b0;

    base = *gCurrentMap;
    cols = M2C_FIELD(base, u16 *, 0x5144);
    rows = M2C_FIELD(base, u16 *, 0x5146);
    r5 = cols >> 1;
    r6 = rows >> 1;
    r7 = 0x8C;
    for (r4 = 1; r4 < 5; r4++) {
        p = func_020a32f4(r4);
        if (p != 0) {
            r5 = M2C_FIELD(p, u8 *, 1);
            r6 = M2C_FIELD(p, u8 *, 2);
        } else {
            if (func_020d243c(r4) != 0) {
                base = *gCurrentMap;
                r5 = M2C_FIELD((u8 *)base + r7, u8 *, 0x67CF) & 0x7F;
                r6 = M2C_FIELD((u8 *)base + r7, u8 *, 0x67D0) & 0x7F;
            } else {
                val = data_ov000_021aeef4[r4];
                idx = val + 1;
                end = val + 0x33;
                for (; idx < end; idx++) {
                    base = *gCurrentMap;
                    rec = (u8 *)base + 0x59A4 + idx * 0x0E;
                    b0 = M2C_FIELD(rec, u8 *, 0);
                    b0 = (b0 << 26) >> 26;
                    if (b0 != 0) {
                        r5 = M2C_FIELD(rec, u8 *, 1);
                        r6 = M2C_FIELD(rec, u8 *, 2);
                        break;
                    }
                }
            }
        }
        base = *gCurrentMap;
        M2C_FIELD((u8 *)base + r7, u8 *, 0x67D1) = (u8)r5;
        base = *gCurrentMap;
        M2C_FIELD((u8 *)base + r7, u8 *, 0x67D2) = (u8)r6;
        r7 += 0x8C;
    }
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

s32 func_020d3f48(void) {
    M2C_UNK func_020d1938(s32);
    M2C_UNK func_020d19b4(s32);
    extern void **gCurrentMap;
    extern M2C_UNK data_02168f08;
    u8 team;
    s32 count;
    s32 i;
    s32 off;
    void *base;
    u16 idx;
    u8 v;

    base = *gCurrentMap;
    idx = M2C_FIELD(base, u16 *, 0x52A4);
    if (M2C_FIELD((u8 *)base + idx * 0x8C, u8 *, 0x67BD) != 0) {
        M2C_FIELD(base, u16 *, 0x52B0) = 1;
        return 0;
    }
    if (M2C_FIELD(&data_02168f08, u8 *, 4) != 0) {
        return 0;
    }
    base = *gCurrentMap;
    if (M2C_FIELD(base, u8 *, 0x5156) == 0) {
        if (M2C_FIELD(base, u8 *, 0x5158) != 2) {
            return 0;
        }
    }
    team = 0;
    count = team;
    for (i = 1, off = 0x8C; i < 5; i++, off += 0x8C) {
        if (func_020d1938(i) != 0) {
            if (count == 0) {
                if (func_020d19b4(i) != 0) {
                    base = *gCurrentMap;
                    v = M2C_FIELD((u8 *)base + off, u8 *, 0x67CA);
                    count++;
                    team = v;
                }
            } else {
                if (func_020d19b4(i) != 0) {
                    base = *gCurrentMap;
                    v = M2C_FIELD((u8 *)base + off, u8 *, 0x67CA);
                    if (team != v) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
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
 M2C_UNK func_020d1a90(); M2C_UNK func_020ca484(); M2C_UNK func_02096b50(M2C_UNK); M2C_UNK func_020d3e94(); extern M2C_UNK data_02168f08; extern void **gCurrentMap;
 if(M2C_FIELD(&data_02168f08,u8*,15)!=0 && func_020d1a90()!=0) {
 if(M2C_FIELD(&data_02168f08,u8*,15)==M2C_FIELD(*gCurrentMap,u16*,0x52A2)) goto same;
 }
 M2C_FIELD(*gCurrentMap,u16*,0x52B0)=2;
 func_020ca484(); return;
same:
 func_02096b50(0xc0000347); func_020d3e94();
}

void func_020d41c4(void) {
 M2C_UNK func_020d1b80(); M2C_UNK func_020d3f48(); M2C_UNK func_020b78ac(); M2C_UNK func_020d4060(); void func_020d4110(void); extern void **gCurrentMap;
 void (*cb)(void)=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),void(**)(void),0x40);
 if(cb) cb();
 func_020d1b80();
 M2C_FIELD(*gCurrentMap,u16*,0x52B0)=3;
 if(func_020d3f48()!=0){func_020b78ac();return;}
 if(func_020d4060()==0)return;
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
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 0xc;
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

