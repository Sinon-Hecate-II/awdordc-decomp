/* 47 functions from 0x02090E0C to 0x02091E04 (main), found by ds-decomp. */
#include "common.h"

extern u8 data_020f362c[];

void func_02091110(void *arg0) {
    void func_02091230(void);
    void func_02091248(s32);
    s32 func_0207c928(s32, s32);
    s32 func_0207d0f0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u8);
    void func_0209177c(M2C_UNK);
    register M2C_UNK arg1 asm("r1");
    register M2C_UNK arg2 asm("r2");
    register M2C_UNK arg3 asm("r3");
    void *obj;
    M2C_UNK r6;
    M2C_UNK r5;
    M2C_UNK r4;
    u8 b22;
    u8 b21;
    u8 and8;

    r6 = arg1;
    r5 = arg2;
    r4 = arg3;
    obj = arg0;
    if (obj == NULL || M2C_FIELD(obj, s32 *, 0) == 0) {
        return;
    }
    b22 = M2C_FIELD(obj, u8 *, 0x22);
    if (b22 & 0x40) {
        M2C_FIELD(obj, u8 *, 0x22) = (u8)(b22 & ~0x40);
    } else {
        if (b22 & 0x10) {
            b21 = M2C_FIELD(obj, u8 *, 0x21);
            (void)b21;
            func_02091230();
        } else if (b22 & 0x20) {
            u8 buf[0x24];
            s32 i;
            u8 *src = (u8 *)data_020f362c;
            u8 *dst = buf + 0xc;
            i = 0xb;
            do {
                dst[0] = src[0];
                dst[1] = src[1];
                src += 2;
                dst += 2;
                i -= 1;
            } while (i != 0);
            {
                s32 idx = (s32)(M2C_FIELD(obj, s16 *, 0x18) >> 2);
                idx = func_0207c928(idx, 0x16);
                func_02091248(buf[0xc + idx]);
            }
        } else {
            b21 = M2C_FIELD(obj, u8 *, 0x21);
            func_02091248(b21);
        }
        b21 = M2C_FIELD(obj, u8 *, 0x21);
        if (b21 != 0) {
            and8 = (u8)(M2C_FIELD(obj, u8 *, 0x22) & 0x8);
            func_0207d0f0(M2C_FIELD(obj, M2C_UNK *, 0x10), r6, M2C_FIELD(obj, M2C_UNK *, 0x28), M2C_FIELD(obj, M2C_UNK *, 0x2c), r5, r4, and8);
        }
    }
    if (M2C_FIELD(obj, s32 *, 0x30) == 0) {
        return;
    }
    if (!(M2C_FIELD(obj, u8 *, 0x22) & 0x1)) {
        return;
    }
    func_0209177c((M2C_UNK)obj);
}
M2C_UNK func_02090e0c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, s32 arg5, s32 arg6, s32 arg7) {
    extern M2C_UNK data_021029d8;
    extern M2C_UNK data_021029cc;
    M2C_UNK func_01ffa3dc(M2C_UNK, M2C_UNK);
    M2C_UNK func_02082028(M2C_UNK);
    void func_020906a8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void *r4;
    M2C_UNK alloc;

    if (arg7 == 0) {
        arg7 = 9;
    }
    r4 = (void *)func_01ffa3dc((M2C_UNK)&data_021029d8, arg7);
    if (r4 != 0) {
        *(M2C_UNK *)r4 = (M2C_UNK)&data_021029cc;
        M2C_FIELD(r4, M2C_UNK *, 0x40) = arg0;
        M2C_FIELD(r4, M2C_UNK *, 0x38) = 0;
        M2C_FIELD(r4, M2C_UNK *, 0x3C) = 0;
        M2C_FIELD(r4, M2C_UNK *, 0x34) = 0;
        M2C_FIELD(r4, u8 *, 0x44) = *((u8 *)&arg6);
        alloc = func_02082028(0x30);
        if (alloc != 0) {
            func_020906a8(alloc, (M2C_UNK)r4, arg0, arg1, arg2, arg3, arg4, arg5);
        }
    }
    return (M2C_UNK)r4;
}

void func_02090eb8(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2,M2C_UNK arg3,u16 arg4,s32 arg5,s32 arg6) {
s32 func_02081070(M2C_UNK,M2C_UNK);
M2C_UNK func_02090e0c(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,s32,s32,s32);
func_02090e0c(func_02081070(arg0,1),arg1,arg2,arg3,arg4,arg5,1,arg6);
}

void *func_02090f0c(void *arg0) {
    M2C_UNK func_02090894();
    M2C_UNK func_02090c7c();
    M2C_UNK func_020e35cc(s32);
    M2C_UNK func_02082040();
    extern M2C_UNK data_021029cc;
    M2C_UNK (*temp_r1)(void *);

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021029cc;
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_02090894();
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_02090c7c();
    }
    temp_r1 = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x34);
    if (temp_r1 != NULL) {
        temp_r1(arg0);
    }
    if (M2C_FIELD(arg0, u8 *, 0x44) != 0) {
        func_020e35cc(M2C_FIELD(arg0, s32 *, 0x40));
    }
    func_02082040(arg0);
    return arg0;
}

void *func_02090f78(void *arg0) {
    M2C_UNK func_02090894();
    M2C_UNK func_02090c7c();
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_021029cc;
    M2C_UNK *d = &data_021029cc;
    M2C_UNK (*temp_r1)(void *);

    M2C_FIELD(arg0, M2C_UNK **, 0) = d;
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_02090894();
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_02090c7c();
    }
    temp_r1 = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x34);
    if (temp_r1 != NULL) {
        temp_r1(arg0);
    }
    if (M2C_FIELD(arg0, u8 *, 0x44) != 0) {
        func_020e35cc(M2C_FIELD(arg0, s32 *, 0x40));
    }
    return arg0;
}

void func_02090fdc(void *arg0) {
    M2C_UNK func_020910d0(void *);
    M2C_UNK func_01ffa574(void *);
    volatile s32 sp8;
    volatile s32 sp4;
    volatile s32 sp0;
    s32 *temp_r0;
    s32 var_r0;
    s32 var_r1;

    sp0 = M2C_FIELD(arg0, s32 *, 0x5C) * 0x30;
    sp4 = M2C_FIELD(arg0, s32 *, 0x60) * 0x30;
    sp8 = M2C_FIELD(arg0, s32 *, 0x64);
    {
        M2C_UNK (*fp)(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK) = (M2C_UNK(*)(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK))func_020910d0;
        if (fp((M2C_UNK)M2C_FIELD(arg0, s32 **, 0x58), (M2C_UNK)&sp0, 0x30000, 0) != 0) {
            return;
        }
    }
    temp_r0 = M2C_FIELD(arg0, s32 **, 0x58);
    var_r1 = 1;
    if ((temp_r0 != NULL) && (*temp_r0 != 0)) {
        var_r1 = 0;
    }
    if (var_r1 == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_0209106c(void *arg0) {
    void func_020912a4(s32 *);
    void (*fp)(s32 *) = func_020912a4;
    fp(M2C_FIELD(arg0, s32 **, 0x58));
}

#pragma optimization_level 4
#pragma scheduling off
s32 func_0209107c(void *arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5,s32 arg6,s32 arg7,u8 arg8) { M2C_UNK func_02091af8(void*,s32,s32); s32 func_0207d0f0(s32,s32,s32,s32,s32,s32,u8); s32 r=func_02091af8(arg0,arg1,arg2); if(!r)return 0; func_0207d0f0(r,arg3,arg4,arg5,arg6,arg7,arg8);return 1; }
#pragma scheduling reset
#pragma optimization_level reset
M2C_UNK func_020910d0(void *arg0) {
void func_02091110(void *); void func_020913c4(void *); M2C_UNK func_020913d4(M2C_UNK);
s32 ok=(arg0!=0 && *(s32 *)arg0!=0);
if(ok==0) return 0;
func_02091110(arg0); func_020913c4(arg0); return func_020913d4((M2C_UNK)arg0);
}

extern void func_02091110(void *);

void func_02091230(void) {
    *(s32 *)0x040004A4 = 0x081E4080;
}

void func_02091248(s32 arg0) {
    s32 var_r1;

    if (arg0 == 0x1F) {
        var_r1 = 0;
    } else {
        var_r1 = 0x3F;
    }
    *(s32 *)0x040004A4 = (var_r1 << 0x18) | 0x80 | (arg0 << 0x10);
}

s32 func_02091270(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
            void func_02091954(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020919b4(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_020919b4(0);
    func_02091954(temp_r0, arg0, arg1, arg2);
    return temp_r0;
}

void func_020912a4(s32 *arg0) {
    if (arg0 != NULL && *arg0 != 0) {
        *arg0 = 0;
    }
}

s32 func_020912bc(s32 *arg0, s32 arg1, s32 arg2) {
    void func_020912ec(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020913c4(void *);
    M2C_UNK func_020913d4(M2C_UNK);

    if (arg0 != (void *)0 && *arg0 != 0) {
        func_020912ec((M2C_UNK)arg0, (M2C_UNK)arg1, (M2C_UNK)arg2);
        func_020913c4((void *)arg0);
        return func_020913d4((M2C_UNK)arg0);
    }
    return 0;
}

void func_020912ec(M2C_UNK a, M2C_UNK x, M2C_UNK y) {
void func_02091570(M2C_UNK);
void func_0209177c(M2C_UNK);
void func_01ffaacc(u16,u16,u16,s32,s32);
extern void *gCur3DSpriteEngine;
void *p=(void *)a;
u32 flags=0, v;
if (!p || !*(s32 *)p) return;
if (M2C_FIELD(p,s32 *,0x14)) {
func_02091570(a);
flags=(M2C_FIELD(p,u8 *,0x23)&31)<<9;
}
v=M2C_FIELD(p,u32 *,0x28);
func_01ffaacc((u16)(x|flags),(u16)y,(u16)((v&0xfc00)|(((v&0x3ff)>>((u32)(**(u16 **)gCur3DSpriteEngine <<17)>>30))&0x3ff)),M2C_FIELD(p,s32 *,0x10),M2C_FIELD(p,s8 *,0x20));
if (M2C_FIELD(p,s32 *,0x30) && (M2C_FIELD(p,u8 *,0x22)&1)) func_0209177c(a);
}

void func_020913c4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x18) = (s16) (M2C_FIELD(arg0, s16 *, 0x18) + 1);
}

#pragma opt_if-conversion off
M2C_UNK func_020913d4(M2C_UNK arg0raw) {
    void func_020912a4(s32 *);
    void *arg0 = (void *)arg0raw;
    M2C_UNK *cur;
    u16 word0;
    u16 cmd;
    u8 flags;
    u32 idx;
    void *base;
    void *p10;
    u16 first;
    u32 masked;

    if (arg0 == (void *)0 || *(s32 *)arg0 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16 *, 0x1C) == 0) {
        return 0xFFFF;
    }

    if (M2C_FIELD(arg0, s16 *, 0x1A) != 0) {
        M2C_FIELD(arg0, s16 *, 0x1A) = (s16)(M2C_FIELD(arg0, s16 *, 0x1A) - 1);
        if (M2C_FIELD(arg0, s16 *, 0x1A) > 0) {
            return 0xFFFF;
        }
        M2C_FIELD(arg0, s16 *, 0x1A) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0xC) = M2C_FIELD(arg0, M2C_UNK **, 0xC) + 1;

        cur = M2C_FIELD(arg0, M2C_UNK *, 0xC);
        word0 = *(u16 *)cur;
        if (word0 == 0) {
            cmd = *((u16 *)cur + 1);
            switch (cmd) {
            case 0:
                func_020912a4((s32 *)arg0);
                return 0;
            case 1:
                return 1;
            case 0xFF:
                M2C_FIELD(arg0, M2C_UNK **, 0xC) = M2C_FIELD(arg0, M2C_UNK **, 0x8);
                return func_020913d4(arg0raw);
            default:
                M2C_FIELD(arg0, u16 *, 0x24) = cmd;
                M2C_FIELD(arg0, M2C_UNK **, 0xC) = M2C_FIELD(arg0, M2C_UNK **, 0xC) + 1;
                return func_020913d4(arg0raw);
            }
        }

        {
            u16 maxv = M2C_FIELD(arg0, u16 *, 0x1C);
            M2C_FIELD(arg0, u16 *, 0x1E) = (u16)(word0 * maxv + M2C_FIELD(arg0, u16 *, 0x1E));
            if (M2C_FIELD(arg0, u16 *, 0x1E) >= 0x100) {
                M2C_FIELD(arg0, s16 *, 0x1A) = (s16)(M2C_FIELD(arg0, u16 *, 0x1E) >> 8);
                M2C_FIELD(arg0, u16 *, 0x1E) = (u16)(M2C_FIELD(arg0, u16 *, 0x1E) & 0xFF);
            } else {
                M2C_FIELD(arg0, s16 *, 0x1A) = 1;
            }
            return func_020913d4(arg0raw);
        }
    }

    flags = M2C_FIELD(arg0, u8 *, 0x22);
    cur = M2C_FIELD(arg0, M2C_UNK *, 0xC);
    if ((flags & 0x2) == 0) {
        idx = *((u16 *)cur + 1);
        base = M2C_FIELD(arg0, void **, 0x4);
        M2C_FIELD(arg0, void **, 0x10) = (void *)(((void **)base)[idx]);
    } else {
        idx = *((u16 *)cur + 1);
        base = (void *)M2C_FIELD(arg0, void **, 0x4);
        masked = *(u16 *)((u8 *)base + idx * 2);
        masked = masked & ~1U;
        M2C_FIELD(arg0, void **, 0x10) = (void *)((u8 *)base + masked);
    }

    p10 = M2C_FIELD(arg0, void **, 0x10);
    first = *(u16 *)p10;
    if (!(first & 0x8000)) {
        M2C_FIELD(arg0, void **, 0x14) = (void *)0;
    } else {
        M2C_FIELD(arg0, void **, 0x14) = p10;
        masked = first & 0x7FFF;
        M2C_FIELD(arg0, void **, 0x10) = (void *)((u8 *)p10 + (masked * 3 + 1) * 2);
        flags = (u8)(flags | 0x1);
        M2C_FIELD(arg0, u8 *, 0x22) = flags;
    }
    return 0xFFFF;
}
#pragma opt_if-conversion reset
void func_02091570(M2C_UNK a) {
    s32 func_0207c8ec(s32, s32);
    void func_01ff8ddc(s32, s16, s16, s16, s16);
    extern s16 data_020e5b30[];
    void *arg0 = (void *)a;
    s32 *sp4 = (s32 *)arg0;

    s32 res2,r4,res1,r5,r6,r7;
    u16 *r8p;
    s16 r9s;
    s32 res3,r10,r11;
    s16 r3s,res4;
    s32 r1,count,r9i,r3i;

    r6 = -2;

    if (arg0 == (void *)0) return;
    if (*sp4 == 0) return;
    {
        u8 *base = *(u8 **)((char *)arg0 + 0x14);
        if (base == (u8 *)0) return;
        r8p = (u16 *)(base + 2);
        count = *(u16 *)base & 0x7FFF;
    }
    r7 = 0;
    if (count <= 0) return;

    do {
        r5 = r8p[2];
        if (r5 >= 2) {
            r10 = r5;
        } else if ((u32)r5 > 2U) {
            r10 = 2;
        } else if (r5 < -2) {
            r10 = -2;
        } else {
            r10 = r5;
        }

        r1 = r8p[1];

        r3i = ((s32)r8p[0]) >> 4;
        r3s = data_020e5b30[r3i * 2 + 1];

        if (r1 >= 2) {
            r4 = r1;
        } else if ((u32)r1 > 2U) {
            r4 = 2;
        } else if (r1 < -2) {
            r4 = -2;
        } else {
            r4 = r1;
        }

        r9i = ((s32)r8p[0]) >> 4;
        r9s = data_020e5b30[r9i * 2];

        if (r5 < 2) {
            if ((u32)r5 > 2U) r5 = 2;
            else if (r5 < -2) r5 = -2;
        }

        if (r1 < 2) {
            if ((u32)r1 > 2U) r1 = 2;
            else if (r1 < -2) r1 = -2;
        }

        r11 = (s32)r3s << 4;
        res1 = func_0207c8ec(r11, r1);
        res2 = func_0207c8ec((-(s32)r9s) << 4, r5);
        res3 = func_0207c8ec((s32)r9s << 4, r4);
        res4 = (s16)func_0207c8ec(r11, r10);

        func_01ff8ddc((((s32)*(u8 *)((char *)arg0 + 0x23)) + r7) & 0xFF,
                     res1, res2, res3, res4);
        r7 += 1;
        r8p += 3;
    } while (r7 < count);
}

void func_02091700(void *arg0,s32 arg1) {
void func_02091928(void *);
void *root;
u8 *base;
void *tail;
u32 off;
if(arg0==NULL)return;
root=*(void **)arg0;
if(root==NULL)return;
if(M2C_FIELD(arg0,u8 *,0x22)&2) {
base=(u8 *)root;
off=*(u16 *)(base+2)&~1u;
base+=off;
tail=base+(*(u16 *)(base+arg1*2)&~1u);
M2C_FIELD(arg0,void **,8)=tail;
base=*(u8 **)arg0;
off=*(u16 *)(base+2)&~1u;
base+=off;
tail=base+(*(u16 *)(base+arg1*2)&~1u);
} else {
u32 idx=arg1+1;
M2C_FIELD(arg0,void **,8)=((void **)root)[idx];
tail=((void **)root)[idx];
}
M2C_FIELD(arg0,void **,12)=tail;
func_02091928(arg0);
}

void func_0209177c(M2C_UNK a) {
    void func_0207c3dc(s32, s32, s32, s32);
    void func_0207c464(s32, s32, s32, s32);
    extern u8 data_02102a10[];
    extern void *gCur3DSpriteEngine;

    M2C_UNK arg0 = a;
    void **r4;
    u8 *r5;
    s32 r6;
    u16 *r7;
    u16 *r8;
    s32 r9;
    s32 r11;

    if (arg0 == 0) {
        return;
    }
    if (*(s32 *)arg0 == 0) {
        return;
    }

    r4 = (void **)&gCur3DSpriteEngine;
    r5 = data_02102a10;
    r6 = 0;
    r11 = 0;

    {
        u8 *base = (u8 *)M2C_FIELD(arg0, void **, 0x10);
        u16 count = *(u16 *)base;
        r7 = (u16 *)(base + 2);
        r8 = r7 + (count * 3);
        r9 = (s32)count - 1;
        if ((s32)count <= 0) {
            goto cleanup;
        }
    }

loop:
    {
        void *engine = *r4;

        if (((*(u16 *)engine) & 0x1000) != 0) {
            u8 byte22 = *(u8 *)((char *)arg0 + 0x22);
            u16 first = r7[0];
            u16 second = r7[1];
            s32 idx = ((second & 0xC000) >> 14) + ((first & 0xC000) >> 12);
            u8 m1 = r5[idx * 2];
            u8 m2 = r5[idx * 2 + 1];
            s32 product = (s32)m1 * (s32)m2;
            s32 offsetVal = *(s32 *)((char *)arg0 + 0x30) + (r8[0] << 5);
            s32 spirit = *(s32 *)((char *)arg0 + 0x28);

            if (byte22 & 0x04) {
                func_0207c464(offsetVal, spirit + r6, product << 5, r11);
            } else {
                s32 spiritShifted = ((u32)spirit << 22) >> 17;
                s32 secondArg = *(s32 *)((char *)engine + 0x1C) + spiritShifted + r6;
                func_0207c3dc(offsetVal, secondArg, product << 5, 0);
            }
        }
    }

    {
        u16 first = r7[0];
        u16 second = r7[1];
        s32 idx = ((second & 0xC000) >> 14) + ((first & 0xC000) >> 12);
        u8 m1 = r5[idx * 2];
        u8 m2 = r5[idx * 2 + 1];
        s32 product = (s32)m1 * (s32)m2;
        r6 += product << 5;
    }

    if (r9 > 0) {
        r7 += 3;
        r8 += 1;
        r9 -= 1;
        goto loop;
    }

cleanup:
    {
        u8 b = *(u8 *)((char *)arg0 + 0x22);
        b &= (u8)~0x01;
        *(u8 *)((char *)arg0 + 0x22) = b;
    }
}

void func_020918a4(M2C_UNK arg0, M2C_UNK arg1) {
    char *r0 = (char *)arg0;
    char *base;
    char *r3;
    u32 off0;
    u32 off2;
    u32 b;
    u32 nested;
    *(M2C_UNK *)r0 = arg1;
    if (((unsigned char *)r0)[0x22] & 0x2) {
        base = (char *)*(M2C_UNK *)r0;
        off0 = *(unsigned short *)base;
        off0 = off0 & ~1;
        *(M2C_UNK *)(r0 + 4) = (M2C_UNK)(base + off0);
        r3 = (char *)*(M2C_UNK *)r0;
        off2 = *(unsigned short *)(r3 + 2);
        b = off2 & ~1;
        nested = *(unsigned short *)(r3 + b);
        nested = nested & ~1;
        *(M2C_UNK *)(r0 + 8) = (M2C_UNK)(r3 + b + nested);
        r3 = (char *)*(M2C_UNK *)r0;
        off2 = *(unsigned short *)(r3 + 2);
        b = off2 & ~1;
        nested = *(unsigned short *)(r3 + b);
        nested = nested & ~1;
        *(M2C_UNK *)(r0 + 0xC) = (M2C_UNK)(r3 + b + nested);
    } else {
        base = (char *)*(M2C_UNK *)r0;
        *(M2C_UNK *)(r0 + 4) = *(M2C_UNK *)base;
        *(M2C_UNK *)(r0 + 8) = *(M2C_UNK *)(base + 4);
        *(M2C_UNK *)(r0 + 0xC) = *(M2C_UNK *)(base + 4);
    }
}

void func_02091928(void *arg0) {
    M2C_UNK func_020913d4(M2C_UNK);
    u16 temp_r4;
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    temp_r4 = M2C_FIELD(arg0, u16 *, 0x1C);
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    M2C_FIELD(arg0, u16 *, 0x1C) = 0x100;
    func_020913d4((M2C_UNK)arg0);
    M2C_FIELD(arg0, u16 *, 0x1C) = temp_r4;
}

void func_02091954(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2,M2C_UNK arg3) {
void func_020918a4(M2C_UNK, M2C_UNK); M2C_UNK func_020913d4(M2C_UNK);
void *r5=(void*)arg0; M2C_UNK r4=arg2; M2C_UNK r1;
M2C_FIELD(r5,u8*,0x22)=arg3; func_020918a4(arg0,arg1); r1=0;
M2C_FIELD(r5,s32*,0x30)=r1; M2C_FIELD(r5,s32*,0x28)=r1; M2C_FIELD(r5,s32*,0x2c)=r1;
M2C_FIELD(r5,s16*,0x18)=r1; M2C_FIELD(r5,s16*,0x1a)=r1;
M2C_FIELD(r5,u8*,0x20)=r4; M2C_FIELD(r5,u8*,0x21)=31; M2C_FIELD(r5,s32*,0x14)=r1;
M2C_FIELD(r5,u8*,0x23)=r1; M2C_FIELD(r5,s16*,0x1a)=r1;
M2C_FIELD(r5,s16*,0x1c)=256; M2C_FIELD(r5,s16*,0x1e)=r1; M2C_FIELD(r5,s16*,0x24)=r1;
func_020913d4((M2C_UNK)r5);
}

s32 func_020919b4(M2C_UNK arg0) {
extern s32 data_02157918; s32 i=0; s32 *p=&data_02157918;
do { if(*p==arg0) return i*0x34+(s32)&data_02157918;
p=(s32*)((u8*)p+0x34); ++i;
}while(i<32); return 0;
}

void func_020919f4(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    s32 func_020912bc(s32 *, s32, s32);
    s32 *temp_r0;
    s32 var_r1;

    if (func_020912bc(M2C_FIELD(arg0, s32 **, 0x58), M2C_FIELD(arg0, s32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x60)) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 **, 0x58);
    var_r1 = 1;
    if ((temp_r0 != NULL) && (*temp_r0 != 0)) {
        var_r1 = 0;
    }
    if (var_r1 == 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_02091a40(void *arg0) {
    func_020912a4(M2C_FIELD(arg0, s32 **, 0x58));
}

void func_02091a50(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102a28;
    extern M2C_UNK data_021029f0;
    func_01ffa9e4(&data_02102a28);
    func_01ffa9e4(&data_021029f0);
}

u16 func_02091a70(void *arg0) {
    u16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(arg0, u16 *, 0x24) = 0U;
    return temp_r2;
}

#pragma push
#pragma scheduling off
s32 func_02091a84(void *arg0) {
    u16 *p = M2C_FIELD(arg0, u16 **, 0x8);
    s32 sum = 0;

    for (;;) {
        u16 a = p[0];
        if (a == 0) {
            u16 b = p[1];
            if (b == 0 || b == 1 || b == 0xFF) {
                return sum;
            }
            sum = sum + b;
        } else {
            sum = sum + a;
        }
        p = p + 2;
    }
}
#pragma pop
void func_02091abc(void) {

}

#pragma push
#pragma scheduling off
s32 func_02091ac0(void *arg0) {
    u16 *p = M2C_FIELD(arg0, u16 **, 0x8);
    s32 sum = 0;

    do {
        u16 a = p[0];
        if (a == 0) {
            u16 b = p[1];
            if (b == 0 || b == 1 || b == 0xff) {
                return sum;
            }
        }
        sum = sum + 1;
        p = p + 2;
    } while (1);
}
#pragma pop
void func_02091af4(void) {

}

s32 func_02091af8(void *arg,s32 b,s32 c){
u16 *a=arg;
s32 func_0207c928(s32,s32);
u16 *table,*seq,*p; s32 sum;
table=(u16 *)((u8 *)a+(a[0]&~1));
p=(u16 *)((u8 *)a+(a[1]&~1));
seq=(u16 *)((u8 *)p+(p[b]&~1));
p=seq;sum=0;
while(p[0]){sum+=p[0];p+=2;}
switch(p[1]){
case 255:c=func_0207c928(c,sum);break;
case 1:if(c>sum)c=sum;break;
case 0:return 0;
}
if(seq[0]){do{c-=*(volatile u16 *)seq;if(c<=0)break;seq+=2;}while(seq[0]);}
return (s32)((u8 *)table+(table[seq[1]]&~1));
}

void func_02091bcc(void) {
    M2C_UNK func_02091c88(s32, s32);
    s32 var_r5;

    var_r5 = 0;
    do {
        func_02091c88(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0x5E);
}

void func_02091bf4(void) {
    M2C_UNK func_0209cbe4(s32 *);
    extern M2C_UNK data_0215d9b8;
    s32 sp0;

    sp0 = M2C_FIELD(&data_0215d9b8, s32 *, 0x74);
    func_0209cbe4(&sp0);
    func_02091c88(0, sp0);
}

#pragma peephole off
void func_02091c20(s32 index,s32 value) {
extern u32 data_0215da2c[];
if(value+data_0215da2c[index]<0xf423fU) { data_0215da2c[index]=data_0215da2c[index]+value; return; }
data_0215da2c[index]=0xf423fU;
}
#pragma peephole off
void func_02091c54(s32 index,s32 value) {
extern u32 data_0215da2c[];
if(value+data_0215da2c[index]<0x5f5e0ffU) { data_0215da2c[index]=data_0215da2c[index]+value; return; }
data_0215da2c[index]=0x5f5e0ffU;
}
#pragma peephole reset
M2C_UNK func_02091c88(M2C_UNK arg0, M2C_UNK arg1) {
    extern unsigned int data_0215da2c[];
    data_0215da2c[arg0] = (unsigned int)arg1;
}

void func_02091c98(void) {
extern void *gCur3DSpriteEngine;
extern M2C_UNK data_0211e738;
extern M2C_UNK data_0211e068;
func_0207c780(&data_0211e738,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c));
func_01ff9e44(&data_0211e068,0x200,0x20);
}

void func_02091cd0(void) {
extern void *gCur3DSpriteEngine;
extern void *data_027e00c4;
extern void *data_027e00c8;
void *save=gCur3DSpriteEngine;
s32 i=0;
do {
gCur3DSpriteEngine=i==0?data_027e00c8:data_027e00c4;
func_02091c98();
i++;
}while(i<2);
gCur3DSpriteEngine=save;
}

void func_02091d20(void) {
M2C_UNK func_02007e20(M2C_UNK*,s32,M2C_UNK);
extern M2C_UNK data_020f41e0; extern void *gCur3DSpriteEngine;
func_02007e20(&data_020f41e0,M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x800,0x800);
}

void func_02091d4c(s32 arg0) {
    M2C_UNK func_01ff9e44(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_0211e088;
    func_01ff9e44(&data_0211e088, arg0 << 5, 0x20);
}

void func_02091d6c(s32 a,s32 b) {
extern void *gCur3DSpriteEngine;
func_02091d4c(a);
if(b!=0)return;
func_020ae528(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+((a<<5)&~1));
}

M2C_UNK *func_02091da8(void) {
    extern M2C_UNK data_02157f98;
    return &data_02157f98;
}

u8 func_02091db4(void) {
    return M2C_FIELD(func_02091da8(), u8 *, 0x48);
}

u8 func_02091dc4(s32 arg0) {
    M2C_UNK *func_02091da8(void);
    M2C_UNK *base = func_02091da8();
    return M2C_FIELD((char *)base + arg0, u8 *, 0x44);
}

s32 func_02091ddc(M2C_UNK arg0) {
    u8 func_02091dc4(M2C_UNK);
    if (func_02091dc4(arg0) == 0x2) {
        return 0x3;
    }
    func_02091dc4(arg0);
    return 0x2;
}

