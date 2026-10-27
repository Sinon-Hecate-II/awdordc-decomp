/* 30 functions from 0x0201CB4C to 0x0201DB20 (main), found by ds-decomp. */
#include "common.h"

void func_0201cfdc(void) {
    u8 *func_0201aacc(s32 *);
    void func_0201ce18(u8 *, s32);
    void func_0201b840(u8 *, s32);
    void func_0201ab8c(void);

    s32 size;
    u8 *buf;
    u32 magic;

    for (;;) {
        buf = func_0201aacc(&size);
        if (size <= 0x22) {
            break;
        }
        magic = M2C_FIELD(buf, u16 *, 0xC);
        magic = (magic << 8) | (magic >> 8);
        magic = magic & 0xFFFF;
        if (magic == 0x800) {
            func_0201ce18(buf + 0xE, size - 0xE);
        } else if (magic == 0x806) {
            func_0201b840(buf + 0xE, size - 0xE);
            func_0201ab8c();
        }
    }
}

u16 func_0201d04c(void) {
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_02137290;

    u16 counter;
    u8 *node;
    u8 *child;
    s32 found;

    for (;;) {
        counter = M2C_FIELD(&data_02137290, u16 *, 8);
        counter = counter + 1;
        if (counter >= 0x400) {
            if (counter >= 0x1388) {
                counter = 0x400;
            }
        }
        M2C_FIELD(&data_02137290, u16 *, 8) = counter;

        node = M2C_FIELD(&data_0212dca4, u8 *, 8);
        found = 0;
        if (node != 0) {
            do {
                child = M2C_FIELD(node, u8 *, 0xA4);
                if (child != 0) {
                    if (M2C_FIELD(child, s32 *, 0) != 0) {
                        if (M2C_FIELD(child, u16 *, 0xA) == counter) {
                            found = 1;
                            break;
                        }
                    }
                }
                node = M2C_FIELD(node, u8 *, 0x68);
            } while (node != 0);
        }
        if (found == 0) {
            break;
        }
    }
    return M2C_FIELD(&data_02137290, u16 *, 8);
}

s32 func_0201d0f4(void) {
    extern M2C_UNK data_02137290;
    u64 mult;
    u64 val;
    u64 add;
    u64 res;

    mult = M2C_FIELD(&data_02137290, u64 *, 0x70);
    val = M2C_FIELD(&data_02137290, u64 *, 0x68);
    add = M2C_FIELD(&data_02137290, u64 *, 0x78);
    res = mult * val + add;
    M2C_FIELD(&data_02137290, u64 *, 0x68) = res;
    return (s32)(res >> 32);
}

void func_0201d138(s32 arg0) {
    extern M2C_UNK data_0212dca4;
    M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), s32 *, 0xA4) = arg0;
}

void func_0201d14c(void) {
    extern M2C_UNK data_0212dca4;
    M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), s32 *, 0xA4) = 0;
}

void func_0201d164(void) {
    extern M2C_UNK data_0212dca4;
    M2C_UNK *inner;
    M2C_UNK *q;
    inner = (M2C_UNK *)M2C_FIELD(&data_0212dca4, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    M2C_FIELD(q, u8 *, 8) = 0xA;
    M2C_FIELD(q, s32 *, 0x44) = 0;
}

void func_0201d190(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_02137290;
    u16 func_0201d04c(void);
    M2C_UNK *inner;
    M2C_UNK *q;
    s32 temp;
    inner = (M2C_UNK *)M2C_FIELD(&data_0212dca4, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    if (arg2 == 0x7F000001) {
        temp = M2C_FIELD(&data_02137290, s32 *, 0x50);
    } else {
        temp = arg2;
    }
    M2C_FIELD(q, u16 *, 0x1A) = (u16)arg1;
    M2C_FIELD(q, u16 *, 0x18) = M2C_FIELD(q, u16 *, 0x1A);
    M2C_FIELD(q, s32 *, 0x20) = temp;
    M2C_FIELD(q, s32 *, 0x1C) = temp;
    if (arg0 != 0) {
        M2C_FIELD(q, s16 *, 0x0A) = (s16)arg0;
        return;
    }
    M2C_FIELD(q, s16 *, 0x0A) = func_0201d04c();
}

void func_0201d1f0(void) {
    extern M2C_UNK data_0212dca4;
    M2C_UNK *inner;
    M2C_UNK *q;
    inner = (M2C_UNK *)M2C_FIELD(&data_0212dca4, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    M2C_FIELD(q, void **, 0) = (void *)inner;
    M2C_FIELD(q, u8 *, 8) = 0;
    M2C_FIELD(q, s32 *, 0x44) = 0;
    M2C_FIELD(q, s32 *, 0x60) = 0;
    M2C_FIELD(q, s32 *, 0x38) = 0;
}

void func_0201d244(void *arg0) {
    extern M2C_UNK data_0212dca4;
    M2C_FIELD(arg0, void **, 0xA4) = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), void **, 0xA4);
}

void func_0201d25c(void *arg0) {
    M2C_UNK func_02005da4(M2C_UNK);
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 func_0201d0f4();
    s32 temp_r0;
    s32 temp_r4;

    temp_r0 = func_0201d0f4();
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x30) = temp_r0;
    M2C_FIELD(arg0, s8 *, 8) = 1;
    temp_r4 = func_0200751c();
    M2C_FIELD(arg0, s32 *, 4) = 1;
    func_02005da4(0);
    func_02007530(temp_r4);
}

void func_0201d434(void *arg0) {
    M2C_UNK func_02005ec8();
    M2C_UNK func_0201bf58(void *, M2C_UNK);
    M2C_UNK func_0201bf6c(void *, M2C_UNK);
    u8 temp_r1;

    func_02005ec8();
    temp_r1 = M2C_FIELD(arg0, u8 *, 8);
    if ((u32) (u8) (temp_r1 + 0xFD) <= 1U) {
        func_0201bf6c(arg0, 0x19);
        M2C_FIELD(arg0, u8 *, 8) = 7U;
        return;
    }
    if (temp_r1 == 0) {
        return;
    }
    func_0201bf58(arg0, 0x1A);
}

s32 func_0201d548(s32 *arg0, void *arg1) {
    s32 func_0200751c();
    M2C_UNK func_02005da4(M2C_UNK);
    M2C_UNK func_02007530(s32);
    s32 var_r6;
    s32 temp_r7;

    temp_r7 = func_0200751c();
    var_r6 = M2C_FIELD(arg1, s32 *, 0x44);
    while (var_r6 == 0) {
        M2C_FIELD(arg1, s32 *, 4) = 3;
        func_02005da4(0);
        var_r6 = M2C_FIELD(arg1, s32 *, 0x44);
    }
    func_02007530(temp_r7);
    *arg0 = var_r6;
    return M2C_FIELD(arg1, s32 *, 0x40);
}

s32 func_0201d744(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
    extern M2C_UNK data_02137290;
    M2C_UNK func_0201b524(M2C_UNK, s32, M2C_UNK, s32, s32);
    M2C_UNK func_02005ec8(void);

    M2C_UNK v8;
    s32 v11;
    M2C_UNK v10;
    s32 v9;
    s32 v6;
    s32 v5;
    s32 v7;
    s32 v4;
    s32 v1;
    s32 sum;
    u16 global;
    s32 zero;

    v8 = arg2;
    v11 = arg3;
    v10 = arg0;
    v9 = arg1;
    v6 = M2C_FIELD(v8, s32 *, 0x34);
    if (v11 != 0) {
        v5 = 1;
    } else {
        v5 = M2C_FIELD(v8, u16 *, 0x2C);
    }
    v7 = (v6 << 1) + 4;

    for (;;) {
        v4 = M2C_FIELD(v8, u16 *, 0x2E);
        global = M2C_FIELD(&data_02137290, u16 *, 0x2);
        v1 = M2C_FIELD(v8, s32 *, 0x34);
        if ((u32)v4 >= (u32)v5) {
            v4 = v5;
        }
        if ((u32)global < (u32)v4) {
            v4 = global;
        }
        if (v11 == 0) {
            v4 &= ~1;
        }
        if (v9 < v4) {
            v4 = v9;
        }
        sum = v7 + (v1 - v6);
        if (sum == 0) {
            v4 = 0;
        }
        v6 = v1;
        v7 = sum - 1;
        if (v4 == 0) {
            break;
        }
        zero = 0;
        v5 = v5 - v4;
        func_0201b524(v10, v4, v8, 0x18, zero);
        func_02005ec8();
        v10 = (M2C_UNK)((u8 *)v10 + v4);
        v9 = v9 - v4;
        if (v9 == 0) {
            break;
        }
        if (M2C_FIELD(v8, u8 *, 8) != 4) {
            break;
        }
    }
    return v4;
}

void func_0201d808(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_0201d744(M2C_UNK, s32, s32, s32);
    if ((func_0201d744(arg0, arg1, arg4, arg5) != 0) && (arg3 != 0)) {
        func_0201d744(arg2, arg3, arg4, 0);
    }
}

s32 func_0201da4c(s32 a,s32 b,s32 c,s32 d){
extern M2C_UNK data_0212dca4;extern M2C_UNK data_02137290;
void func_0201b3e8(s32,s32,void *);void func_0201b338(s32,s32,void *);s32 func_02024f9c(s32,s32,s32,s32,void *);s32 func_0201d844(s32,s32,s32,s32,void *);
void *p; s32 result;
p=M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),void **,0xa4);
if(p!=0){
if(M2C_FIELD(p,u8 *,8)==10){if(b)func_0201b3e8(a,b,p);if(d)func_0201b3e8(c,d,p);result=b+d;}
else if(M2C_FIELD(p,u8 *,8)==11){if(b)func_0201b338(a,b,p);if(d)func_0201b338(c,d,p);result=b+d;}
else if(M2C_FIELD(p,u8 *,9))result=func_02024f9c(a,b,c,d,p);
else result=func_0201d844(a,b,c,d,p);
if(M2C_FIELD(&data_02137290,u8 *,0)==0)return result;
}return 0;
}

