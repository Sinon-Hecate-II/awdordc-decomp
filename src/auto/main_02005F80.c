/* 61 functions from 0x02005F80 to 0x02006F14 (main), found by ds-decomp. */
#include "common.h"

s32 func_02005f80(void *arg0, s32 arg1) {
    M2C_UNK func_020057f8(void *);
    M2C_UNK func_020058a0();
    s32 func_0200751c();
    void func_02007530(s32);
    extern M2C_UNK data_0212dc80;
    extern M2C_UNK data_0212dcb4;
    void *cur;
    void *prev;
    s32 state;

    cur = M2C_FIELD(&data_0212dc80, void **, 0x2C);
    prev = NULL;
    state = func_0200751c();
    while (cur != NULL && cur != arg0) {
        prev = cur;
        cur = M2C_FIELD(cur, void **, 0x68);
    }
    if (cur == NULL || cur == &data_0212dcb4) {
        func_02007530(state);
        return 0;
    }
    if (M2C_FIELD(cur, s32 *, 0x70) != arg1) {
        if (prev == NULL) {
            M2C_FIELD(&data_0212dc80, void **, 0x2C) = (void *) M2C_FIELD(arg0, void **, 0x68);
        } else {
            M2C_FIELD(prev, void **, 0x68) = (void *) M2C_FIELD(arg0, void **, 0x68);
        }
        M2C_FIELD(arg0, s32 *, 0x70) = arg1;
        func_020057f8(arg0);
        func_020058a0();
    }
    func_02007530(state);
    return 1;
}

s32 func_02006028(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70);
}

void func_02006030(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02007190(void *);
    void func_020072cc(void *, u64, void (*)(void **), void **);
    M2C_UNK func_02005da4(void *);
    extern M2C_UNK data_0212dc80;
    extern void func_020060d8(void **);
    s32 buf[11];
    void *node;
    s32 state;
    u64 delay;

    func_02007190(buf);
    node = M2C_FIELD(M2C_FIELD(&data_0212dc80, void **, 8), void **, 0);
    state = func_0200751c();
    delay = ((u64)(u32)arg0 * 0x82EAULL) >> 6;
    M2C_FIELD(node, void **, 0xB0) = buf;
    func_020072cc(buf, delay, func_020060d8, &node);
    while (node != NULL) {
        func_02005da4(NULL);
    }
    func_02007530(state);
}

void func_020060d8(void **arg0) {
    M2C_UNK func_02005e5c(void *);
    void *temp_r2;

    temp_r2 = *arg0;
    *arg0 = NULL;
    M2C_FIELD(temp_r2, s32 *, 0xB0) = 0;
    func_02005e5c(temp_r2);
}

s32 func_020060f8(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212dc80;
    s32 state;
    s32 temp;

    state = func_0200751c();
    temp = M2C_FIELD(&data_0212dc80, s32 *, 0x30);
    M2C_FIELD(&data_0212dc80, s32 *, 0x30) = arg0;
    func_02007530(state);
    return temp;
}

void func_02006120(void) {
    s32 func_02007508(void);
    M2C_UNK func_02007968(void);
    func_02007508();
    func_02007968();
}

s32 func_02006130(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212dc80;
    s32 state;
    s32 r;
    s32 v;

    state = func_0200751c();
    v = M2C_FIELD(&data_0212dc80, s32 *, 4);
    if ((u32)v < 0xFFFFFFFFu) {
        r = v;
        M2C_FIELD(&data_0212dc80, s32 *, 4) = v + 1;
    }
    func_02007530(state);
    return r;
}

s32 func_02006164(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212dc80;
    s32 state;
    s32 r;
    s32 v;

    state = func_0200751c();
    r = 0;
    v = M2C_FIELD(&data_0212dc80, s32 *, 4);
    if (v != 0) {
        r = v;
        M2C_FIELD(&data_0212dc80, s32 *, 4) = v - 1;
    }
    func_02007530(state);
    return r;
}

void func_02006198(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xB4) = arg1;
}

s32 func_020062b4(void) {
    return 0;
}

s32 func_020062bc(void) {
    extern s32 data_020f5218;
    s32 v = 0x82000001;
    data_020f5218 = v;
    return v;
}

void func_020062d4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg2;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

s32 func_020062fc(void *arg0, s32 arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    M2C_UNK func_02005df4(void *);
    unsigned long long func_020720f0(s32, s32);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x14) <= M2C_FIELD(arg0, s32 *, 0x1C)) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4(arg0);
    }
    ((s32 *)M2C_FIELD(arg0, void **, 0x10))[(s32)(func_020720f0(M2C_FIELD(arg0, s32 *, 0x18) + M2C_FIELD(arg0, s32 *, 0x1C), M2C_FIELD(arg0, s32 *, 0x14)) >> 32)] = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
    func_02005df4((u8 *)arg0 + 8);
    func_02007530(state);
    return 1;
}

s32 func_02006390(void *arg0, s32 *arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    M2C_UNK func_02005df4(void *);
    unsigned long long func_020720f0(s32, s32);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4((u8 *)arg0 + 8);
    }
    if (arg1 != NULL) {
        *arg1 = ((s32 *)M2C_FIELD(arg0, void **, 0x10))[M2C_FIELD(arg0, s32 *, 0x18)];
    }
    M2C_FIELD(arg0, s32 *, 0x18) = (s32)(func_020720f0(M2C_FIELD(arg0, s32 *, 0x18) + 1, M2C_FIELD(arg0, s32 *, 0x14)) >> 32);
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
    func_02005df4(arg0);
    func_02007530(state);
    return 1;
}

s32 func_02006434(void *arg0, s32 arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    M2C_UNK func_02005df4(void *);
    unsigned long long func_020720f0(s32, s32);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x14) <= M2C_FIELD(arg0, s32 *, 0x1C)) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4(arg0);
    }
    M2C_FIELD(arg0, s32 *, 0x18) = (s32)(func_020720f0(M2C_FIELD(arg0, s32 *, 0x18) + M2C_FIELD(arg0, s32 *, 0x14) - 1, M2C_FIELD(arg0, s32 *, 0x14)) >> 32);
    ((s32 *)M2C_FIELD(arg0, void **, 0x10))[M2C_FIELD(arg0, s32 *, 0x18)] = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
    func_02005df4((u8 *)arg0 + 8);
    func_02007530(state);
    return 1;
}

s32 func_020064d0(void *arg0, void **arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4((u8 *)arg0 + 8);
    }
    if (arg1 != NULL) {
        u32 idx = M2C_FIELD(arg0, u32 *, 0x18);
        void *base = M2C_FIELD(arg0, void **, 0x10);
        *arg1 = ((void **)base)[idx];
    }
    func_02007530(state);
    return 1;
}

void func_0200654c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}

void func_02006564(void *arg0) {
    s32 func_0200751c();
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    void func_020066f4(void *, void *);
    extern M2C_UNK data_0212dca4;
    s32 state;
    void *head;
    u32 c;

    state = func_0200751c();
    head = M2C_FIELD(&data_0212dca4, void **, 0x4);
    while (1) {
        void *cur = M2C_FIELD(arg0, void **, 0x8);
        if (cur == NULL) {
            M2C_FIELD(arg0, void **, 0x8) = head;
            c = M2C_FIELD(arg0, u32 *, 0xC);
            c = c + 1;
            M2C_FIELD(arg0, u32 *, 0xC) = c;
            func_020066f4(head, arg0);
            break;
        }
        if (cur == head) {
            c = M2C_FIELD(arg0, u32 *, 0xC);
            c = c + 1;
            M2C_FIELD(arg0, u32 *, 0xC) = c;
            break;
        }
        M2C_FIELD(head, void **, 0x84) = arg0;
        func_02005da4(arg0);
        M2C_FIELD(head, void **, 0x84) = NULL;
    }
    func_02007530(state);
}

void func_020065e8(void *arg0) {
    s32 func_0200751c();
    void func_02007530(s32);
    M2C_UNK func_02005df4(void *);
    void func_02006718(void *, void *);
    extern M2C_UNK data_0212dca4;
    s32 state;
    void *head;
    u32 c;

    state = func_0200751c();
    head = M2C_FIELD(&data_0212dca4, void **, 0x4);
    if (M2C_FIELD(arg0, void **, 0x8) == head) {
        c = M2C_FIELD(arg0, u32 *, 0xC);
        c = c - 1;
        M2C_FIELD(arg0, u32 *, 0xC) = c;
        if (c == 0) {
            func_02006718(head, arg0);
            M2C_FIELD(arg0, void **, 0x8) = NULL;
            func_02005df4(arg0);
        }
    }
    func_02007530(state);
}

void func_02006644(void *arg0) {
    void *func_020057c8(void *);
    M2C_UNK func_02005df4();
    void *temp_r0;

    if (M2C_FIELD(arg0, s32 *, 0x88) == 0) {
        return;
    }
    do {
        temp_r0 = func_020057c8(arg0 + 0x88);
        M2C_FIELD(temp_r0, s32 *, 0xC) = 0;
        M2C_FIELD(temp_r0, s32 *, 8) = 0;
        func_02005df4();
    } while (M2C_FIELD(arg0, s32 *, 0x88) != 0);
}

s32 func_02006680(void *arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_020066f4(void *, void *);
    extern M2C_UNK data_0212dca4;
    void *head;
    void *cur;
    s32 state;
    s32 r6;

    state = func_0200751c();
    head = M2C_FIELD(&data_0212dca4, void **, 0x4);
    cur = M2C_FIELD(arg0, void **, 0x8);
    if (cur == NULL) {
        M2C_FIELD(arg0, void **, 0x8) = head;
        M2C_FIELD(arg0, u32 *, 0xC) = M2C_FIELD(arg0, u32 *, 0xC) + 1;
        func_020066f4(head, arg0);
        r6 = 1;
    } else if (cur == head) {
        M2C_FIELD(arg0, u32 *, 0xC) = M2C_FIELD(arg0, u32 *, 0xC) + 1;
        r6 = 1;
    } else {
        r6 = 0;
    }
    func_02007530(state);
    return r6;
}

void func_020066f4(void *arg0, void *arg1) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0x8C);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, void **, 0x88) = arg1;
    } else {
        M2C_FIELD(temp_r2, void **, 0x10) = arg1;
    }
    M2C_FIELD(arg1, void **, 0x14) = temp_r2;
    M2C_FIELD(arg1, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, void **, 0x8C) = arg1;
}

void func_02006718(void *arg0, void *arg1) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 0x10);
    temp_r1 = M2C_FIELD(arg1, void **, 0x14);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, void **, 0x8C) = temp_r1;
    } else {
        M2C_FIELD(temp_r2, void **, 0x14) = temp_r1;
    }
    if (temp_r1 == NULL) {
        M2C_FIELD(arg0, void **, 0x88) = temp_r2;
        return;
    }
    M2C_FIELD(temp_r1, void **, 0x10) = temp_r2;
}

void func_02006838(void) {
    u32 *io = (u32 *)0x04000000;
    u32 saved = io[0x82];
    io[0x82] = (u32)io;
    if (*(u16 *)((char *)io + 6) != 0) {
        return;
    }
    io[0x82] = saved;
}

void func_02006858(void) {
    M2C_UNK func_02004fe0();
    M2C_UNK func_02005254();
    M2C_UNK func_02005288();
    M2C_UNK func_02005968();
    void func_02006838(void);
M2C_UNK func_020068a0();
    M2C_UNK func_02006ce4();
    M2C_UNK func_020074c0();
    M2C_UNK func_020075b4();
    M2C_UNK func_020077cc();
    M2C_UNK func_02008bb8();
    M2C_UNK func_02009d34();
    M2C_UNK func_0200e2f8();
    M2C_UNK func_02010c14();
    M2C_UNK func_02018f3c();
    func_020068a0();
    func_02009d34();
    func_02005288();
    func_020069a4();
    func_02004fe0();
    func_02005254();
    func_02006ce4();
    func_02008bb8();
    func_020074c0();
    func_020077cc();
    func_02005968();
    func_020075b4();
    func_02018f3c();
    func_02010c14();
    func_0200e2f8();
    func_02006838();
}

s32 func_02006a10(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDC4);
}

s32 func_02006a24(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDA0);
}

s32 func_02006a38(s32 arg0) {
    s32 func_020062bc(void);
    extern M2C_UNK data_0212defc;
    extern M2C_UNK data_027e0000;

    switch (arg0) {
    case 0:
        return 0x023e0000;
    case 1:
        if (M2C_FIELD(&data_0212defc, s32 *, 4) == 0) {
            return 0x02700000;
        }
        if ((func_020062bc() & 3) != 1) {
            return 0x02000000;
        }
        return 0;
    case 2:
        return 0x023e0000;
    case 3:
        return 0x02000000;
    case 4: {
        s32 r0 = (s32)&data_027e0000;
        s32 r1 = 0;
        s32 r2 = 0x800;
        s32 r3 = r0 + 0x3f80;
        r2 = r3 - r2;
        if (r1 != 0) {
            if (r1 < 0) {
                return 0x027e15e0 - r1;
            } else {
                return r2 - r1;
            }
        } else {
            if ((u32)r0 < (u32)0x027e15e0) {
                r0 = 0x027e15e0;
            }
            return r0;
        }
    }
    case 5:
        return 0x027ff680;
    case 6:
        return 0x037f8000;
    default:
        return 0;
    }
}

s32 func_02006b1c(s32 arg0) {
    s32 func_020062bc(void);
    extern M2C_UNK data_0212defc;

    switch (arg0) {
    case 0:
        return 0x0223c840;
    case 2:
        if (M2C_FIELD(&data_0212defc, s32 *, 0x4) == 0) {
            return 0x023e0000;
        }
        if ((func_020062bc() & 0x3) != 1) {
            return 0x01ffc780;
        }
        return 0;
    case 3:
        return 0x027e15e0;
    case 4:
        return 0x027ff000;
    case 5:
        return 0x037f8000;
    case 6:
        return 0;
    default:
        return 0;
    }
}

void func_02006bc4(s32 arg0, s32 arg1) {
    M2C_FIELD((((u32)arg0 * 4) + (s32)0x027FF000), s32 *, 0xDC4) = arg1;
}

void func_02006bd8(s32 arg0, s32 arg1) {
    M2C_FIELD(((arg0 * 4) + (unsigned)0x027FF000), s32 *, 0xDA0) = arg1;
}

s32 func_02006bec(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r2;
    s32 temp_r4;
    s32 temp;
    u32 temp_r5;

    temp_r0 = func_02006a24(arg0);
    if (temp_r0 == 0) {
        return 0;
    }
    temp_r2 = ~(arg2 - 1);
    temp_r4 = temp_r2 & ((temp_r0 + arg2) - 1);
    temp = temp_r4 + arg1;
    temp_r5 = temp_r2 & ((temp + arg2) - 1);
    if (temp_r5 > (u32)func_02006a10(arg0)) {
        return 0;
    }
    func_02006bd8(arg0, temp_r5);
    return temp_r4;
}

void func_02006c58(void) {
    extern M2C_UNK data_0212defc;
    M2C_FIELD(&data_0212defc, s32 *, 4) = 0;
}

void func_02006dd8(s32 arg0) {
    M2C_UNK func_02006dec();
    M2C_UNK func_02006e7c();
    func_02006dec();
    func_02006e7c();
    return;
}

void func_02006ef8(s32 arg0) {
    extern u16 data_0212dfb0;
    data_0212dfb0 |= 1 << arg0;
}

