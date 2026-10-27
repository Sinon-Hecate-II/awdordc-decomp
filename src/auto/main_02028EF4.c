/* 37 functions from 0x02028EF4 to 0x02029E98 (main), found by ds-decomp. */
#include "common.h"

extern u8 data_02138e7c;
extern u8 data_02138e80[16];

void func_02029220(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void *func_02027d50(void);
    void func_02007f8c(void *, s32);
    s32 state;
    void *base;
    void *r1;
    void *ptr;

    state = func_0200751c();
    base = func_02027d50();
    if (base == NULL) {
        func_02007530(state);
        return;
    }
    r1 = (void *)((s8 *)base + 0x2000);
    ptr = M2C_FIELD(r1, void **, 0x270);
    if (ptr != NULL && M2C_FIELD(r1, s32 *, 0x274) > 0) {
        func_02007f8c(ptr, 0);
    }
    func_02007530(state);
}

s32 func_02029274(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void *func_02027d50(void);
    s32 state;
    void *base;
    void *r0;
    void *r1;
    s32 result;

    state = func_0200751c();
    base = func_02027d50();
    result = 0;
    if (base == NULL) {
        func_02007530(state);
        return result;
    }
    r0 = (void *)((s8 *)base + 0x2000);
    r1 = M2C_FIELD(r0, void **, 0x270);
    if (r1 != NULL) {
        u32 v = M2C_FIELD(r0, u32 *, 0x274);
        if (v > 0xCU) {
            result = M2C_FIELD(r1, s32 *, 0);
        }
    }
    func_02007530(state);
    return result;
}

s32 func_020292cc(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void *func_02027d50(void);
    s32 state;
    void *base;
    u8 flag;
    s32 result;

    state = func_0200751c();
    base = func_02027d50();
    if (base == NULL) {
        func_02007530(state);
        return 0;
    }
    flag = M2C_FIELD((void *)((s8 *)base + 0x2000), u8 *, 0x26a);
    if (arg0 != 0) {
        result = (flag != 0) ? 1 : 0;
        M2C_FIELD((void *)((s8 *)base + 0x2000), u8 *, 0x26a) = 1;
    } else {
        result = (flag != 0) ? 1 : 0;
        M2C_FIELD((void *)((s8 *)base + 0x2000), u8 *, 0x26a) = 0;
    }
    func_02007530(state);
    return result;
}

s32 func_02029348(void *arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void *func_02027d50(void);
    void *func_02029594(void *);
    s32 state;
    void *base;
    void *result;

    state = func_0200751c();
    base = func_02027d50();
    if (base == NULL) {
        func_02007530(state);
        return 0;
    }
    if ((result = func_02029594(arg0)) == NULL) {
        func_02007530(state);
        return 0;
    }
    func_02007530(state);
    return (s32)result + 0x10;
}

void func_020293a0(void *arg0, s32 arg1) {
    void *func_02027d50(void);
    void *func_02029528(s32);
    void *func_0202942c(void);
    s32 func_020294f8(void);
    void func_020295e4(void *);
    void func_02007ef4(void *, void *, u32);
    void *base;
    void *node;
    u8 flag;

    base = func_02027d50();
    if (base == NULL) {
        return;
    }
    flag = M2C_FIELD((void *)((s8 *)base + 0x2000), u8 *, 0x26a);
    if (flag != 0) {
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x3c) != 0) {
        return;
    }
    node = func_02029528((s32)arg0 + 4);
    if (node == NULL) {
        node = func_0202942c();
        if (node == NULL) {
            if (M2C_FIELD((void *)((s8 *)base + 0x2000), u32 *, 0x278) == 1) {
                node = (void *)(s32)func_020294f8();
            }
            if (node == NULL) {
                return;
            }
        }
    }
    M2C_FIELD(node, u16 *, 0x2) = (u16)arg1;
    func_02007ef4(arg0, (void *)((s8 *)node + 0x10), 0xc0);
    func_020295e4(node);
}

void *func_0202942c(void) {
    void *func_02027d50(void);
    void *base;
    void *p2000;
    void *hdr;
    u32 cap;
    u32 nslots;
    u32 count;
    u32 i;
    u8 *slotbase;
    void *slot;
    void *prev;

    base = func_02027d50();
    p2000 = (void *)((s8 *)base + 0x2000);
    hdr = M2C_FIELD(p2000, void **, 0x270);
    if (hdr == (void *)0) {
        return (void *)0;
    }
    cap = M2C_FIELD(p2000, u32 *, 0x274);
    if (cap <= 0xCU) {
        return (void *)0;
    }
    nslots = (cap - 0xCU) / 0xD0U;
    if (nslots == 0U) {
        return (void *)0;
    }
    count = M2C_FIELD(hdr, u32 *, 0);
    if (nslots <= count) {
        return (void *)0;
    }
    slotbase = (u8 *)hdr + 0xC;
    for (i = 0; i < nslots; i++) {
        slot = (void *)(slotbase + i * 0xD0);
        if (*(u8 *)slot == 0) {
            goto found;
        }
    }
    return (void *)0;
found:
    *(u8 *)slot = 1;
    count = M2C_FIELD(hdr, u32 *, 0);
    M2C_FIELD(slot, u32 *, 4) = count;
    M2C_FIELD(slot, void **, 0xC) = (void *)0;
    M2C_FIELD(slot, void **, 8) = M2C_FIELD(hdr, void **, 8);
    M2C_FIELD(hdr, void **, 8) = slot;
    prev = M2C_FIELD(slot, void **, 8);
    if (prev != (void *)0) {
        M2C_FIELD(prev, void **, 0xC) = slot;
    } else {
        M2C_FIELD(hdr, void **, 4) = slot;
    }
    count = M2C_FIELD(hdr, u32 *, 0);
    count = count + 1;
    M2C_FIELD(hdr, u32 *, 0) = count;
    return slot;
}

s32 func_020294f8(void) {
    void *func_02027d50();
    void *temp_r0;
    void *temp_r1;

    temp_r0 = func_02027d50();
    temp_r1 = M2C_FIELD(temp_r0, void **, 0x2270);
    if ((temp_r1 != NULL) && ((u32) M2C_FIELD(temp_r0, u32 *, 0x2274) > 0xCU)) {
        return M2C_FIELD(temp_r1, s32 *, 4);
    }
    return 0;
}

void *func_02029528(s32 arg0) {
    s32 func_02029aac(s32, s32);
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *var_r4;

    temp_r0 = func_02027d50();
    temp_r0_2 = temp_r0 + 0x2000;
    var_r4 = NULL;
    temp_r1 = M2C_FIELD(temp_r0, void **, 0x2270);
    if (arg0 == 0) {
        return NULL;
    }
    if ((temp_r1 != NULL) && ((u32) M2C_FIELD(temp_r0_2, u32 *, 0x274) > 0xCU)) {
        var_r4 = M2C_FIELD(temp_r1, void **, 4);
        if (var_r4 != NULL) {
loop_5:
            if (func_02029aac(var_r4 + 0x14, arg0) == 0) {
                var_r4 = M2C_FIELD(var_r4, void **, 0xC);
                if (var_r4 != NULL) {
                    goto loop_5;
                }
            }
        }
    }
    return var_r4;
}

void *func_02029594(void *arg0) {
    void *temp_r0;
    void *temp_r2;
    void *var_r0;

    temp_r0 = (void *)func_02027d50();
    temp_r2 = M2C_FIELD(temp_r0, void **, 0x2270);
    if (temp_r2 == NULL) {
        return NULL;
    }
    if ((u32) M2C_FIELD(temp_r0, u32 *, 0x2274) <= 0xCU) {
        return NULL;
    }
    var_r0 = M2C_FIELD(temp_r2, void **, 0x4);
    if (var_r0 == NULL) {
        return var_r0;
    }
loop_6:
    if (M2C_FIELD(var_r0, void **, 4) != arg0) {
        var_r0 = M2C_FIELD(var_r0, void **, 0xC);
        if (var_r0 != NULL) {
            goto loop_6;
        }
    }
    return var_r0;
}

void func_020295e4(void *arg0) {
    void *temp_r0;
    void *temp_r2_2;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r1_4;
    void *temp_r2;
    void *var_r3;
    register void *temp_r0_2;

    temp_r0 = func_02027d50();
    temp_r1 = temp_r0 + 0x2000;
    temp_r0_2 = M2C_FIELD(temp_r0, void **, 0x2270);
    if ((arg0 != NULL) && (temp_r0_2 != NULL)) {
        if ((u32) M2C_FIELD(temp_r1, u32 *, 0x274) <= 0xCU) {
            return;
        }
        var_r3 = M2C_FIELD(temp_r0_2, void **, 4);
        if (var_r3 != NULL) {
loop_7:
            if (var_r3 == arg0) {
                temp_r2 = M2C_FIELD(var_r3, void **, 8);
                temp_r1_2 = M2C_FIELD(var_r3, void **, 0xC);
                if (temp_r2 != NULL) {
                    M2C_FIELD(temp_r2, void **, 0xC) = temp_r1_2;
                } else {
                    M2C_FIELD(temp_r0_2, void **, 4) = temp_r1_2;
                }
                temp_r2_2 = M2C_FIELD(var_r3, void **, 0xC);
                temp_r1_3 = M2C_FIELD(var_r3, void **, 8);
                if (temp_r2_2 != NULL) {
                    M2C_FIELD(temp_r2_2, void **, 8) = temp_r1_3;
                } else {
                    M2C_FIELD(temp_r0_2, void **, 8) = temp_r1_3;
                }
            } else {
                var_r3 = M2C_FIELD(var_r3, void **, 0xC);
                if (var_r3 != NULL) {
                    goto loop_7;
                }
            }
        }
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
        M2C_FIELD(arg0, void **, 8) = (void *) M2C_FIELD(temp_r0_2, void **, 8);
        M2C_FIELD(temp_r0_2, void **, 8) = arg0;
        temp_r1_4 = M2C_FIELD(arg0, void **, 8);
        if (temp_r1_4 != NULL) {
            M2C_FIELD(temp_r1_4, void **, 0xC) = arg0;
        } else {
            M2C_FIELD(temp_r0_2, void **, 4) = arg0;
        }
        if (var_r3 != NULL) {
            return;
        }
        M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(temp_r0_2, s32 *, 0);
        M2C_FIELD(temp_r0_2, s32 *, 0) = (s32) (M2C_FIELD(temp_r0_2, s32 *, 0) + 1);
    }
}

void func_020296a0(void) {
    void func_0200654c(void *);
    extern M2C_UNK data_02138e50;
    extern M2C_UNK data_02138e5c;

    if (M2C_FIELD(&data_02138e50, u8 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_02138e50, u8 *, 0) = 1;
    M2C_FIELD(&data_02138e50, u32 *, 0x24) = 0;
    M2C_FIELD(&data_02138e50, u32 *, 0x8) = 0;
    M2C_FIELD(&data_02138e50, u32 *, 0x4) = 0;
    func_0200654c(&data_02138e5c);
}

void func_020296e0(void *arg0) {
    extern M2C_UNK data_02138e50;
    if (M2C_FIELD(&data_02138e50, M2C_UNK (**)(void *, void *, void *, u16), 0x28) == NULL) {
        return;
    }
    M2C_FIELD(&data_02138e50, M2C_UNK (**)(void *, void *, void *, u16), 0x28)(arg0 + 0x1E, arg0 + 0x18, arg0 + 0x2C, M2C_FIELD(arg0, u16 *, 6));
}

s32 func_02029848(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    s32 func_02027d50(void);
    void func_02006564(void *);
    void func_020065e8(void *);
    void func_02008048(void *, void *, s32);
    s32 func_02012e74(s32, void *, void *, u32);
    void func_02005da4(void *);
    void func_020299d0(void *);
    extern M2C_UNK data_02138e5c;
    extern M2C_UNK data_02138e54;
    extern M2C_UNK data_02138e50;

    s32 state;
    s32 base2;
    s32 res;
    s32 val;
    s32 r6;

    state = func_0200751c();
    if (func_02027d50() == 0) {
        func_02007530(state);
        return -1;
    }
    func_02006564(&data_02138e5c);
    base2 = func_02027d50();
    if (base2 == 0) {
        func_020065e8(&data_02138e5c);
        func_02007530(state);
        return -1;
    }
    if (M2C_FIELD((void *)(base2 + 0x2000), s32 *, 0x260) == 9) {
        if (M2C_FIELD((void *)(base2 + 0x2000), u8 *, 0x26b) == 1) {
            func_020065e8(&data_02138e5c);
            func_02007530(state);
            return -4;
        }
    }
    func_02008048(arg1, (void *)(base2 + 0xf00), arg2);
    if (arg4 > 0) {
        func_02008048(arg3, (void *)(base2 + 0xf00 + arg2), arg4);
    }
    r6 = arg2 + arg4;
    res = func_02012e74((s32)func_020299d0, arg0, (void *)(base2 + 0xf00), (u32)r6);
    switch (res) {
        case 3:
            break;
        case 0:
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            func_020065e8(&data_02138e5c);
            func_02007530(state);
            return -5;
    }
    func_02005da4(&data_02138e54);
    val = M2C_FIELD(&data_02138e50, s32 *, 0x24);
    if (val == 0) {
        func_020065e8(&data_02138e5c);
        func_02007530(state);
        return r6;
    }
    val;
    func_020065e8(&data_02138e5c);
    func_02007530(state);
    return -5;
}

void func_020299d0(void *arg0) {
    void func_020281f8(void);
    void func_02005df4(void *);
    extern M2C_UNK data_02138e50;
    extern M2C_UNK data_02138e54;

    if (M2C_FIELD(arg0, u16 *, 0) != 0x12) {
        return;
    }
    M2C_FIELD(&data_02138e50, u32 *, 0x24) = M2C_FIELD(arg0, u16 *, 2);
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        return;
    }
    func_020281f8();
    func_02005df4(&data_02138e54);
}

void func_02029a10(void) {
    M2C_UNK func_02029a74(M2C_UNK *);
    extern M2C_UNK data_02138e5c;
    func_02029a74(&data_02138e5c);
}

s32 func_02029a24(void *arg0) {
    extern M2C_UNK func_01ff8000;
    M2C_UNK *temp_r2;

    temp_r2 = M2C_FIELD(arg0, M2C_UNK **, 8);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, M2C_UNK **, 8) = &func_01ff8000;
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1);
        return 1;
    }
    if (temp_r2 != &func_01ff8000) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1);
    return 1;
}

s32 func_02029a74(M2C_UNK *arg0) {
    void func_02005df4(void *);
    extern M2C_UNK func_01ff8000;

    if (M2C_FIELD(arg0, M2C_UNK **, 8) != &func_01ff8000) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xC) -= 1;
    if (M2C_FIELD(arg0, s32 *, 0xC) != 0) {
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 8) = NULL;
    func_02005df4(arg0);
    return;
}

s32 func_02029aac(s32 a, s32 b) {
    u8 *p0 = (u8 *)a;
    u8 *p1 = (u8 *)b;
    s32 i = 0;
    do {
        if (p0[i] != p1[i]) {
            return 0;
        }
        i++;
    } while (i < 6);
    return 1;
}

s32 func_02029ad8(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    s32 func_02027d50(void);
    s32 func_02029b9c(void);
    s32 temp_r4;
    s32 var_r5;
    s32 temp_r0;

    temp_r4 = func_0200751c();
    temp_r0 = func_02027d50();
    var_r5 = 0;
    if (temp_r0 != 0) {
        if (M2C_FIELD(temp_r0, s32 *, 0x2260) == 9) {
            var_r5 = func_02029b9c();
        }
    }
    func_02007530(temp_r4);
    return var_r5;
}

u8 func_02029b1c(void) {
    s32 func_020720f0(s32, s32);
    extern u8 data_02138e7c;
    extern u8 data_02138e80[16];
    u8 n = data_02138e7c;
    s32 sum = 0;
    s32 i;
    u8 *p;
    s32 result;

    if (n > 0x10) {
        p = data_02138e80;
        i = 0;
        do {
            sum += *p;
            p++;
            i++;
        } while (i < 16);
        result = sum / 16;
    } else if (n != 0) {
        p = data_02138e80;
        i = 0;
        do {
            sum += *p;
            p++;
            i++;
        } while (i < n);
        result = func_020720f0(sum, n);
    } else {
        result = 0;
    }
    return (u8)result;
}

s32 func_02029b9c(void) {
    u8 func_02029b1c();
    s32 var_r1;
    u32 temp_r0;

    temp_r0 = func_02029b1c();
    var_r1 = 0;
    if (temp_r0 >= 0x1CU) {
        var_r1 = 3;
    } else if (temp_r0 >= 0x16U) {
        var_r1 = 2;
    } else if (temp_r0 >= 0x10U) {
        var_r1 = 1;
    }
    return var_r1;
}

void func_02029bd0(s32 arg0) {
    extern u8 data_02138e7c;
    extern u8 data_02138e80[16];
    s32 var_r0 = arg0 >> 2;
    u8 var_u8;

    if (!(arg0 & 2)) {
        var_r0 += 0x19;
    }
    var_u8 = (u8)var_r0;
    data_02138e80[data_02138e7c % 16] = var_u8;
    if (data_02138e7c < 0x10) {
        data_02138e7c++;
    } else {
        data_02138e7c = (data_02138e7c + 1) % 16 + 0x10;
    }
}

void func_02029c30(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = arg1;
}

void func_02029c48(void *arg0, void *arg1) {
    u16 off = M2C_FIELD(arg0, u16 *, 0xA);
    void *p = (void *)((s8 *)arg1 + off);
    M2C_FIELD(p, s32 *, 4) = 0;
    M2C_FIELD(p, s32 *, 0) = 0;
    M2C_FIELD(arg0, void **, 0) = arg1;
    M2C_FIELD(arg0, void **, 4) = arg1;
    M2C_FIELD(arg0, u16 *, 8) += 1;
}

s32 func_02029ddc(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        return M2C_FIELD(arg0, s32 *, 0);
    }
    return M2C_FIELD((arg1 + M2C_FIELD(arg0, u16 *, 0xA)), s32 *, 4);
}

s32 func_02029df4(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        return M2C_FIELD(arg0, s32 *, 4);
    }
    return M2C_FIELD((arg1 + M2C_FIELD(arg0, u16 *, 0xA)), s32 *, 0);
}

M2C_UNK func_02029e08(M2C_UNK *arg0, M2C_UNK arg1) {
    s32 func_02029ddc(void *, s32);
    M2C_UNK orig = (M2C_UNK)arg0;
    M2C_UNK key = arg1;
    M2C_UNK cur;
    M2C_UNK r;

    cur = func_02029ddc((void *)arg0, 0);
    while (cur != 0) {
        if (M2C_FIELD((void *)cur, u32 *, 0x18) > (u32)key) {
            goto advance;
        }
        if ((u32)key >= M2C_FIELD((void *)cur, u32 *, 0x1c)) {
            goto advance;
        }
        r = func_02029e08((M2C_UNK *)((s8 *)(void *)cur + 0xc), key);
        if (r != 0) {
            return r;
        }
        return cur;
    advance:
        cur = func_02029ddc((void *)orig, cur);
    }
    return 0;
}

M2C_UNK *func_02029e70(M2C_UNK arg0) {
    s32 func_02029e08(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02138e94;
    M2C_UNK *var_r4;
    s32 temp_r0;

    var_r4 = &data_02138e94;
    temp_r0 = func_02029e08(&data_02138e94, arg0);
    if (temp_r0 != 0) {
        var_r4 = temp_r0 + 0xC;
    }
    return var_r4;
}

