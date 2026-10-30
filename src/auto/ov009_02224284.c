/* 36 functions from 0x02224284 to 0x0222525C (ov009), found by ds-decomp. */
#include "common.h"
static inline void ov009SaveInterrupts(u32 *saved) {
    *saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
}
static inline u32 ov009DisableInterrupts(void) {
    u32 previous = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    return previous;
}
static inline u32 ov009RestoreInterrupts(u32 saved) {
    u32 previous = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = saved;
    return previous;
}
#pragma cplusplus on
class Ov009InterruptGuard {
    u32 saved;
public:
    Ov009InterruptGuard() : saved(ov009DisableInterrupts()) {}
    ~Ov009InterruptGuard() { ov009RestoreInterrupts(saved); }
};
#pragma cplusplus off

s32 func_ov009_02224284(void) {
    s32 func_ov009_02224194();
    if (func_ov009_02224194() != 6) {
        return 1;
    }
    return 0;
}

u16 func_ov009_0222429c(void) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    u16 func_ov009_02222a20(u16);
    extern M2C_UNK data_ov009_022268e0;
    func_ov009_02221320(1);
    M2C_FIELD(&data_ov009_022268e0, u16 *, 2) = func_ov009_02222a20(M2C_FIELD(&data_ov009_022268e0, u16 *, 4));
    return M2C_FIELD(&data_ov009_022268e0, u16 *, 2);
}

s32 func_ov009_022242c8(void) {
    s32 func_ov009_02224508(s32);
    M2C_UNK func_ov009_022224e0(void);
    M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
    void func_ov009_022213f0(M2C_UNK, M2C_UNK);
    void *func_0208206c(void);
    M2C_UNK func_ov000_0216a470(void);
    M2C_UNK func_ov000_0216a564(void);
    M2C_UNK func_ov000_0216a76c(void);
    M2C_UNK func_ov000_0216a7c4(void);
    M2C_UNK func_ov009_022241c4(M2C_UNK);
    M2C_UNK func_ov009_02224718(M2C_UNK);
    M2C_UNK func_ov009_02224140(M2C_UNK);
    M2C_UNK func_ov009_02224ba4(M2C_UNK);
    M2C_UNK func_ov009_02224bbc(M2C_UNK);
    M2C_UNK func_ov009_02224bd4(M2C_UNK);
    M2C_UNK func_ov009_02224bec(M2C_UNK);
    M2C_UNK func_ov009_02224c04(M2C_UNK);
    M2C_UNK func_ov009_02224c1c(M2C_UNK);
    M2C_UNK func_ov009_02224b8c(M2C_UNK);
    M2C_UNK func_ov009_02224164(M2C_UNK);
    void func_ov009_02225480(void);
    s32 func_ov009_02222790(void);
    extern M2C_UNK data_ov009_022268e0;
    extern M2C_UNK data_ov009_02226a20;
    extern M2C_UNK data_ov009_02226a40;
    extern M2C_UNK data_ov009_022263e0;
    extern M2C_UNK data_ov009_02226b40;
    extern M2C_UNK data_ov009_02226cc0;
    extern M2C_UNK data_ov009_022269e0;
    extern M2C_UNK data_ov009_02226fe0;

    s32 stk[8];
    u8 *end;
    s32 *sp18;
    u8 *cur;
    s32 x;
    s32 y;
    s32 z = 0;
    s32 r4v;
    s32 r0v;

    if (func_ov009_02224508(0) != 0) {
        return 1;
    }
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x14) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x34) = 0;
    func_ov009_022224e0();

    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x48) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x20) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x28) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x24) = 0;
    func_02007f8c(&data_ov009_02226a20, 0, 0x16);

    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x156) = 0;
    r4v = z - 1;
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x157) = (u8)r4v;
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x158) = (u8)r4v;
    r0v = z - 2;
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x159) = (u8)r0v;
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x15a) = (u8)r0v;
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x15b) = 0;
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x15c) = 0;
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x15d) = (u8)r4v;
    func_02007f8c(&data_ov009_02226a40, 0, 0x40);

    y = M2C_FIELD(&data_ov009_022263e0, s32 *, 0x34);
    x = M2C_FIELD(&data_ov009_022263e0, s32 *, 0x30);

    stk[5] = y;
    stk[4] = x;
    stk[2] = x;
    stk[3] = y;
    stk[6] = x;
    stk[7] = y;

    sp18 = &stk[6];
    cur = (u8 *)&data_ov009_02226b40;
    end = (u8 *)&data_ov009_02226cc0;
    while (cur != end) {
        s32 val = sp18[1];
        if (val & 1) {
            void **fnTable = *(void ***)(cur + (val >> 1));
            void (*cb)(void) = fnTable[sp18[0]];
            cb();
        }
        cur += 0x60;
    }
    stk[0] = sp18[0];
    stk[1] = sp18[1];

    func_ov009_022213f0(&data_ov009_02226a20, func_0208206c());

    func_ov000_0216a470();
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x158) = (u8)func_ov000_0216a564();
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x159) = (u8)func_ov000_0216a76c();
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x15a) = (u8)func_ov000_0216a7c4();

    func_ov009_022241c4(0);
    func_ov009_02224718(0);
    func_ov009_02224140(0);
    func_ov009_02224ba4(0);
    func_ov009_02224bbc(0);
    func_ov009_02224bd4(0);
    func_ov009_02224bec(0);
    func_ov009_02224c04(0);
    func_ov009_02224c1c(0);
    func_ov009_02224b8c(0);
    func_ov009_02224164(1);
    func_ov009_02225480();

    M2C_FIELD(&data_ov009_022268e0, s32 *, 0xc) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x100) = 0;
    M2C_FIELD(&data_ov009_022269e0, u16 *, 0x4) = 0;
    func_02007f8c(&data_ov009_02226fe0, 0, 0x18);

    if (func_ov009_02222790() != 0) {
        return 1;
    }
    return 0;
}

void func_ov009_022244c0(void) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) = 0;
}

void func_ov009_022244d4(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) = 1 << arg0;
}

void func_ov009_022244ec(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, (unsigned)0x50) =
        (M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) | (1 << arg0));
}

s32 func_ov009_02224508(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 var_r2 = 1;
    if (!(M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) & (1 << arg0))) {
        var_r2 = 0;
    }
    return var_r2;
}

void func_ov009_02224528(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 v;
    v = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50);
    v = v & (-1 ^ (1 << arg0));
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x50) = v;
}

void func_ov009_0222454c(void) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x30) = 0;
}

s32 func_ov009_02224560(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    s32 func_ov009_02224718(s32);
    void func_02007e20(void *, void *, s32);
    s32 func_02065210(s32, s32, s32);
    s32 func_ov009_02222f84(void);
    extern M2C_UNK data_ov009_022268e0;
    extern M2C_UNK data_ov009_02226968;
    extern M2C_UNK data_ov009_022263e0;
    extern M2C_UNK data_ov009_0222696e;
    extern M2C_UNK data_ov009_02226cc0;
    extern M2C_UNK data_ov009_02226fe0;

    s32 stk[8];
    s32 x;
    s32 y;
    s32 *p;
    s32 *base;
    s32 *limit;
    s32 val;
    s32 **slot;
    s32 *table;

    func_ov009_02221320(2);
    func_ov009_02224718(arg0);
    M2C_FIELD(&data_ov009_022268e0, u16 *, 6) = (u16)arg2;
    M2C_FIELD(&data_ov009_022268e0, u16 *, 0x84) = 0;

    if (arg1 != 0) {
        func_02007e20((void *)arg1, &data_ov009_02226968, 6);
    } else {
        s32 value;
        s32 count;
        value = (s32)(u8)M2C_FIELD(&data_ov009_022263e0, s32 *, 4);
        count = (s32)&data_ov009_0222696e - (s32)&data_ov009_02226968;
        if (count < 0) count = 0;
        func_02065210((s32)&data_ov009_02226968, value, count);
    }

    x = M2C_FIELD(&data_ov009_022263e0, s32 *, 0x20);
    y = M2C_FIELD(&data_ov009_022263e0, s32 *, 0x24);
    stk[3] = y;
    stk[2] = x;
    stk[4] = x;
    stk[5] = y;
    stk[0] = x;
    stk[1] = y;

    p = (s32 *)stk;
    base = (s32 *)&data_ov009_02226cc0;
    limit = (s32 *)&data_ov009_02226fe0;
    do {
        val = p[1];
        slot = (s32 **)((u8 *)base + (val >> 1));
        if (val & 1) {
            table = *slot;
            ((void (*)(void))(*(s32 *)((u8 *)table + p[0])))();
        }
        base = (s32 *)((u8 *)base + 0xc8);
    } while (base != limit);

    stk[6] = stk[0];
    stk[7] = stk[1];

    if (func_ov009_02222f84() != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

s32 func_ov009_02224688(void) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    if (func_ov009_02224194() != 2) {
        return 0;
    }
    func_ov009_02221320(3);
    return 1;
}

#pragma cplusplus on
extern "C" s32 func_ov009_022246ac(s32 arg0) {
extern M2C_UNK data_ov009_02226cc0;
Ov009InterruptGuard guard;
s32 result = (s32)&data_ov009_02226cc0 + arg0 * 0xc8;
if (M2C_FIELD(result, s32 *, 0xc4) == 0 ||
    M2C_FIELD(result, u16 *, 0x3c) < 0x10U ||
    M2C_FIELD(result, u16 *, 0x40) != 1) result = 0;
return result;
}
#pragma cplusplus off
s32 func_ov009_02224718(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x4C);
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x4C) = arg0;
    return temp_r2;
}

M2C_UNK func_ov009_02224730(M2C_UNK a0, M2C_UNK a1, M2C_UNK a2, M2C_UNK a3) { (void)a0; (void)a1; (void)a2; (void)a3; return 0; }

void func_ov009_0222496c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void *func_ov009_0222497c(void *arg0) {
    void func_ov009_02224d1c(void *);
    if (M2C_FIELD(arg0,void **,4) != NULL) {
        func_ov009_02224d1c(M2C_FIELD(arg0,void **,4));
        M2C_FIELD(arg0,s32 *,4) = 0;
    }
    return arg0;
}

s32 func_ov009_022249a4(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    M2C_UNK func_ov009_022224e0(void);
    void *func_01ffa3dc(M2C_UNK, M2C_UNK);
    void func_02007e98(s32, void *, s32);
    void func_02074114(s32, s32, s32, M2C_UNK (*)(s32), s32);
    void func_02008048(s32, void *, s32);
    M2C_UNK func_020067e0(M2C_UNK, M2C_UNK);
    M2C_UNK func_02006804(void);
    M2C_UNK func_ov009_02223290(void);
    void func_ov009_0222496c(void *);
    void *func_ov009_0222497c(void *);
    extern M2C_UNK data_ov009_022268e0;
    extern M2C_UNK data_ov009_022263e0;
    extern M2C_UNK data_ov009_02226b40;
    extern M2C_UNK data_ov009_02226cc0;
    extern M2C_UNK data_ov009_022264b8;
    extern M2C_UNK data_ov009_022266b0;
    extern M2C_UNK data_ov009_02226638;
    extern M2C_UNK data_ov009_02226688;
    extern M2C_UNK data_ov009_022264e0;
    extern M2C_UNK data_ov009_02226714;
    extern M2C_UNK data_ov009_02226a80;

    s32 stk[8];
    s32 x;
    s32 y;
    s32 val;
    s32 *base;
    s32 *end;
    s32 *slotptr;
    void *ptr;

    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x14) = 0xe0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x34) = 0x200;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x38) = arg0;

    func_ov009_02221320(3);
    func_ov009_022224e0();

    x = M2C_FIELD(&data_ov009_022263e0, s32 *, 0x30);
    y = M2C_FIELD(&data_ov009_022263e0, s32 *, 0x34);
    stk[0] = x;
    stk[1] = y;
    stk[2] = x;
    stk[3] = y;
    stk[4] = x;
    stk[5] = y;

    base = (s32 *)&data_ov009_02226b40;
    end = (s32 *)&data_ov009_02226cc0;
    slotptr = &stk[0];
    do {
        void **tbl;
        val = slotptr[1];
        tbl = (void **)((u8 *)base + (val >> 1));
        if (val & 1) {
            void **base_tbl = (void **)*tbl;
            void (*cb)(void) = (void (*)(void))*(void **)((u8 *)base_tbl + slotptr[0]);
            cb();
        }
        base = (s32 *)((u8 *)base + 0x60);
    } while (base != end);

    {
        u8 b = (u8)M2C_FIELD(&data_ov009_022268e0, u8 *, 0x156);
        b = (u8)(b & (u8)~0x2);
        M2C_FIELD(&data_ov009_022268e0, u8 *, 0x156) = b;
    }
    M2C_FIELD(&data_ov009_022268e0, u8 *, 0x15d) = (u8)arg1;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x48) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x20) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x28) = 0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x24) = 0;

    ptr = func_01ffa3dc(&data_ov009_022264b8, 3);
    if (ptr != 0) {
        M2C_FIELD(ptr, M2C_UNK *, 0) = &data_ov009_022266b0;
        M2C_FIELD(ptr, u16 *, 0x34) = 0;
        M2C_FIELD(ptr, u32 *, 0x38) = 0;
        func_02007e98(0, (u8 *)ptr + 0x3c, 0x10);
    }
    ptr = func_01ffa3dc(&data_ov009_02226638, 3);
    if (ptr != 0) {
        M2C_FIELD(ptr, M2C_UNK *, 0) = &data_ov009_02226688;
        M2C_FIELD(ptr, s32 *, 0x34) = 0;
        M2C_FIELD(ptr, s32 *, 0x38) = 0;
        M2C_FIELD(ptr, s32 *, 0x3c) = 0;
        M2C_FIELD(ptr, s32 *, 0x40) = 0;
        M2C_FIELD(ptr, u16 *, 0x44) = 0;
        M2C_FIELD(ptr, u16 *, 0x46) = 0;
    }
    ptr = func_01ffa3dc(&data_ov009_022264e0, 3);
    if (ptr != 0) {
        M2C_FIELD(ptr, M2C_UNK *, 0) = &data_ov009_02226714;
        func_02074114((s32)((u8 *)ptr + 0x34), 4, 8, (M2C_UNK (*)(s32))func_ov009_0222496c, (s32)func_ov009_0222497c);
    }

    if (arg0 == 1) {
        func_02008048(arg2, &data_ov009_02226a80, 0xc0);
        func_020067e0(&data_ov009_02226a80, 0xc0);
        func_02006804();
        return func_ov009_02223290();
    }
    return 0;
}

s32 func_ov009_02224b8c(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x58);
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x58) = arg0;
    return temp_r2;
}

s32 func_ov009_02224ba4(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x60);
    M2C_FIELD(&data_ov009_022268e0,s32 *,0x60) = arg0;
    return old;
}

s32 func_ov009_02224bbc(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 temp_r2;

    temp_r2 = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x40);
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x40) = arg0;
    return temp_r2;
}

s32 func_ov009_02224bd4(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x1c);
    M2C_FIELD(&data_ov009_022268e0,s32 *,0x1c) = arg0;
    return old;
}

s32 func_ov009_02224bec(s32 arg0) {
 extern M2C_UNK data_ov009_022268e0;
 s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x18);
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x18) = arg0;
 return old;
}

s32 func_ov009_02224c04(s32 arg0) {
 extern M2C_UNK data_ov009_022268e0;
 s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x44);
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x44) = arg0;
 return old;
}

s32 func_ov009_02224c1c(s32 arg0) {
 extern M2C_UNK data_ov009_022268e0;
 s32 old = M2C_FIELD(&data_ov009_022268e0,s32 *,0x54);
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x54) = arg0;
 return old;
}

s32 func_ov009_02224c34(M2C_UNK arg0) {
    s32 func_ov009_02223d40(M2C_UNK);
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223d40(arg0) != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

s32 func_ov009_02224c70(void) {
    s32 func_ov009_02223dc0();
    s32 func_ov009_022241a4();
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223dc0() != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

s32 func_ov009_02224ca4(void) {
    s32 func_ov009_02223e5c();
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223e5c() != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

s32 func_ov009_02224cd8(void) {
    s32 func_ov009_02223ec8();
    if (func_ov009_022241a4() != 0) {
        return 0;
    }
    if (func_ov009_02223ec8() != 0) {
        return 1;
    }
    func_ov009_02221320(8);
    return 0;
}

void func_ov009_02224d0c(M2C_UNK arg0) {
    M2C_UNK func_ov009_0222132c(M2C_UNK, M2C_UNK);
    func_ov009_0222132c(arg0, 0x20);
}

void func_ov009_02224d1c(void *arg0) {
    M2C_UNK func_ov009_02221338(void *, s32);
    func_ov009_02221338(arg0, M2C_FIELD(arg0, s32 *, 8) + 0xC);
}

void *func_ov009_02224d30(void *arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6) {
 void func_02008048(s32, void *, s32);
 M2C_FIELD(arg0,s32 *,0) = 0x5F574C4D;
 M2C_FIELD(arg0,s8 *,4) = arg1;
 M2C_FIELD(arg0,u8 *,5) = (M2C_FIELD(arg0,u8 *,5) & ~0xF) | (arg2 & 0xF);
 M2C_FIELD(arg0,u8 *,5) = (M2C_FIELD(arg0,u8 *,5) & ~0xF0) | ((arg3 & 0xF) << 4);
 M2C_FIELD(arg0,u16 *,6) = arg6;
 M2C_FIELD(arg0,s32 *,8) = arg5;
 if (arg4 != 0 && arg5 != 0) func_02008048(arg4,(u8 *)arg0 + 0xC,arg5);
 return arg0;
}

s32 func_ov009_02224d9c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_ov009_02224194(void);
    M2C_UNK func_ov009_022254a4(void);
    M2C_UNK func_ov009_02224174(void);
    M2C_UNK func_ov009_02225450(void);
    M2C_UNK func_ov009_0222132c(M2C_UNK, M2C_UNK);
    M2C_UNK func_02007f8c(void *, s32, s32);
    void *func_ov009_02224d30(void *, s8, s32, s32, s32, s32, u16);
    extern M2C_UNK data_ov009_022268e0;

    u32 saved;
    u16 masked;
    s32 r5;
    s32 first;
    void *ptr;

    if (func_ov009_02224194() != 4) {
        if (func_ov009_02224194() != 5) {
            return 0;
        }
    }
    if (func_ov009_022254a4() == 0) {
        return 0;
    }
    arg3 = arg3 & func_ov009_02224174();
    first = func_ov009_02225450();
    masked = (u16)(arg3 & (-1 ^ (1 << first)));
    r5 = func_ov009_02225450();

    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;

    ptr = (void *)func_ov009_0222132c((M2C_UNK)(arg2 + 0x10), 0x20);
    if (ptr == 0) {
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = saved;
        return 1;
    }

    func_02007f8c(ptr, 0, 0x10);
    func_ov009_02224d30((u8 *)ptr + 4, (s8)arg0, r5, 0, arg1, arg2, masked);

    if (M2C_FIELD(&data_ov009_022268e0, void **, 0x68) == 0) {
        M2C_FIELD(&data_ov009_022268e0, void **, 0x68) = ptr;
        M2C_FIELD(&data_ov009_022268e0, void **, 0x64) = ptr;
    } else {
        M2C_FIELD(M2C_FIELD(&data_ov009_022268e0, void **, 0x68), void **, 0) = ptr;
        M2C_FIELD(&data_ov009_022268e0, void **, 0x68) = ptr;
    }
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x6c) =
        M2C_FIELD(&data_ov009_022268e0, s32 *, 0x6c) + 1;

    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = saved;
    return 1;
}

s32 func_ov009_02224ec4(s8 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov009_02224194(void);
    s32 func_ov009_022254a4(void);
    s32 func_ov009_02224174(void);
    s32 func_ov009_02225450(void);
    M2C_UNK func_ov009_0222132c(M2C_UNK, M2C_UNK);
    M2C_UNK func_02007f8c(void *, s32, s32);
    void *func_ov009_02224d30(void *, s8, s32, s32, s32, s32, u16);
    extern M2C_UNK data_ov009_022268e0;

    u16 saved;
    void *ptr;
    u16 masked;
    s32 r5;
    s32 first;

    if (func_ov009_02224194() != 4) {
        if (func_ov009_02224194() != 5) {
            return 0;
        }
    }
    if (func_ov009_022254a4() != 0) {
        arg3 = arg3 & func_ov009_02224174();
    }
    first = func_ov009_02225450();
    masked = (u16)(arg3 & ((1 - 2) ^ (1 << first)));
    r5 = func_ov009_02225450();

    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;

    ptr = (void *)func_ov009_0222132c((M2C_UNK)(arg2 + 0x10), 0x20);
    if (ptr == 0) {
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = saved;
        return 1;
    }

    func_02007f8c(ptr, 0, 0x10);
    func_ov009_02224d30((u8 *)ptr + 4, arg0, r5, 1, arg1, arg2, masked);

    if (M2C_FIELD(&data_ov009_022268e0, void **, 0x68) == 0) {
        M2C_FIELD(&data_ov009_022268e0, void **, 0x68) = ptr;
        M2C_FIELD(&data_ov009_022268e0, void **, 0x64) = ptr;
    } else {
        M2C_FIELD(M2C_FIELD(&data_ov009_022268e0, void **,0x68), void **,0) = ptr;
        M2C_FIELD(&data_ov009_022268e0, void **, 0x68) = ptr;
    }
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x6c) =
        M2C_FIELD(&data_ov009_022268e0, s32 *, 0x6c) + 1;

    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = saved;
    return 1;
}

s32 func_ov009_02224fec(s8 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5) {
    M2C_UNK func_ov009_022254a4(void);
    M2C_UNK func_ov009_02224174(void);
    M2C_UNK func_ov009_02225450(void);
    M2C_UNK func_ov009_0222132c(M2C_UNK, M2C_UNK);
    M2C_UNK func_02007f8c(void *, s32, s32);
    void *func_ov009_02224d30(void *, s8, s32, s32, s32, s32, u16);
    extern M2C_UNK data_ov009_022268e0;

    u16 saved;
    u16 masked;
    void *ptr;

    if (func_ov009_022254a4() == 0) {
        return 0;
    }
    arg5 &= func_ov009_02224174();
    masked = (u16)(arg5 & ~(1 << func_ov009_02225450()));

    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;

    ptr = func_ov009_0222132c((u8 *)arg4 + 0x10, 0x20);
    if (ptr == 0) {
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = saved;
        return 1;
    }

    func_02007f8c(ptr, 0, 0x10);
    func_ov009_02224d30((u8 *)ptr + 4, arg0, arg1, arg2, arg3, arg4, masked);

    if (M2C_FIELD(&data_ov009_022268e0, void **, 0x68) == 0) {
        M2C_FIELD(&data_ov009_022268e0, void **, 0x68) = ptr;
        M2C_FIELD(&data_ov009_022268e0, void **, 0x64) = ptr;
    } else {
        M2C_FIELD(M2C_FIELD(&data_ov009_022268e0, void **, 0x68), void **, 0) = ptr;
        M2C_FIELD(&data_ov009_022268e0, void **, 0x68) = ptr;
    }
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x6c) =
        M2C_FIELD(&data_ov009_022268e0, s32 *, 0x6c) + 1;

    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = saved;
    return 1;
}

#pragma optimization_level 4
#pragma opt_propagation on
#pragma opt_deadcode on
s32 func_ov009_022250f8(s32 arg0) {
extern M2C_UNK data_ov009_022269b0;
s32 offset=arg0*12; u32 saved; s32 result=0; u32 nested; void *ptr;
ov009SaveInterrupts(&saved);
if(M2C_FIELD(&data_ov009_022269b0,void**,offset)==NULL){(void)*(volatile u16*)0x04000208; *(volatile u16*)0x04000208=saved; return 0;}
ov009SaveInterrupts(&nested);
ptr=M2C_FIELD(&data_ov009_022269b0,void**,offset);
if(ptr==NULL){(void)*(volatile u16*)0x04000208; *(volatile u16*)0x04000208=nested;}
else {(void)*(volatile u16*)0x04000208; result=M2C_FIELD(ptr,s32*,12); *(volatile u16*)0x04000208=nested;}
result+=12; (void)*(volatile u16*)0x04000208; *(volatile u16*)0x04000208=saved; return result;
}
void *func_ov009_02225178(s32 arg0, void *arg1) {
    void *func_ov009_02224d30(void *, s8, s32, s32, s32, s32, u16);
    M2C_UNK func_ov009_02221338(void *, s32);
    extern M2C_UNK data_ov009_022269b0;
    extern M2C_UNK data_ov009_022269b4;
    extern M2C_UNK data_ov009_022269b8;
    s32 off = arg0 * 0xc;
    volatile u16 *ime = (volatile u16 *)0x04000208;
    u16 saved;
    void *entry;
    void *next;
    void *p10;
    s32 cval;
    u16 aval;
    u8 b8;
    u8 b9;

    saved = *ime;
    *ime = 0;
    entry = M2C_FIELD(&data_ov009_022269b0, void **, off);
    if (entry == (void *)0) {
        (void)*ime;
        *ime = saved;
        return (void *)0;
    }
    p10 = (void *)((u8 *)entry + 0x10);
    cval = M2C_FIELD(entry, s32 *, 0xc);
    aval = M2C_FIELD(entry, u16 *, 0xa);
    b8 = M2C_FIELD(entry, u8 *, 8);
    b9 = M2C_FIELD(entry, u8 *, 9);
    func_ov009_02224d30(arg1, (s8)b8, b9 & 0x0f, (b9 >> 4) & 0x0f, (s32)p10, cval, aval);
    next = M2C_FIELD(entry, void **, 0);
    M2C_FIELD(&data_ov009_022269b0, void **, off) = next;
    if (next == (void *)0) {
        M2C_FIELD(&data_ov009_022269b4, void **, off) = (void *)0;
    }
    func_ov009_02221338(entry, cval + 0x10);
    M2C_FIELD(&data_ov009_022269b8, s32 *, off) -= 1;
    (void)*ime;
    *ime = saved;
    return (void *)(M2C_FIELD(arg1, s32 *, 8) + 0xc);
}

