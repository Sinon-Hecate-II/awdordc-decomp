/* 19 functions from 0x0200BDA4 to 0x0200CD68 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 first, second; } Unk0200FilePair;

void func_0200bda4(s32 arg0) {
    s32 func_0200558c(void);
    void func_02010c14(void);
    void func_0200b118(void *);
    s32 func_0200b184(void *, M2C_UNK, M2C_UNK);
    void func_0200b6a8(void *, s32, s32);
    s32 func_0200b2bc(void *, s32, s32, s32, s32, s32, void *, void *);
    s32 func_0200bd9c(void);
    s32 func_0200bd94(void);
    s32 func_0200bd20(void);
    s32 func_0200bd28(s32, s32);
    s32 func_0200bcd8(s32, s32, s32, s32);
    extern M2C_UNK data_0212fbfc;
    extern M2C_UNK data_0212fc14;
    extern u32 data_020f5220;

    M2C_FIELD(&data_0212fbfc, s32 *, 4) = arg0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0) = func_0200558c();
    M2C_FIELD(&data_0212fbfc, s32 *, 8) = 0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0xc) = 0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0x10) = 0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0x14) = 0;
    func_02010c14();
    func_0200b118(&data_0212fc14);
    func_0200b184(&data_0212fc14, (M2C_UNK)&data_020f5220, 3);

    if (*(u16 *)0x27ffc40 == 2) {
        M2C_FIELD(&data_0212fbfc, s32 *, 8) = -1;
        M2C_FIELD(&data_0212fbfc, s32 *, 0xc) = 0;
        M2C_FIELD(&data_0212fbfc, s32 *, 0x10) = -1;
        M2C_FIELD(&data_0212fbfc, s32 *, 0x14) = 0;
        func_0200b6a8(&data_0212fc14, (s32)func_0200bd9c, -1);
        func_0200b2bc(&data_0212fc14, 0, 0, 0, 0, 0,
                      (void *)func_0200bd94, (void *)func_0200bd20);
        return;
    }

    func_0200b6a8(&data_0212fc14, (s32)func_0200bd28, 0x602);

    {
        u32 *r4 = (u32 *)0x27ffc40;
        u32 v0 = r4[0x80];
        if (v0 != (u32)-1 && v0 != 0) {
            u32 v2 = r4[0x82];
            if (v2 != (u32)-1 && v2 != 0) {
                func_0200b2bc(&data_0212fc14, 0, (s32)v2, (s32)r4[0x83], (s32)v0, (s32)r4[0x81],
                              (void *)func_0200bcd8, (void *)func_0200bd20);
            }
        }
    }
}

void func_0200beec(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0200b3ec(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212fc14;
    func_0200b3ec(&data_0212fc14, arg0, arg1);
}

#pragma opt_strength_reduction off
u32 func_0200bf0c(void *arg0) {s32 x=M2C_FIELD(arg0,s32 *,28);if(!(((u32)x>>24)&1)) return M2C_FIELD(arg0,u32 *,8);return (u32)(x<<8)>>8;}
#pragma opt_strength_reduction reset
void func_0200bf28(void *arg0) {
    M2C_UNK func_020067a8(s32, s32);
    M2C_UNK func_0200681c(s32, s32);
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    temp_r4 = M2C_FIELD(arg0, s32 *, 4);
    temp_r5 = M2C_FIELD(arg0, s32 *, 8);
    temp_r6 = temp_r5 + M2C_FIELD(arg0, s32 *, 0xC);
    func_0200681c(temp_r4, temp_r6);
    func_020067a8(temp_r4, temp_r6);
    func_02007f8c(temp_r4 + temp_r5, 0, temp_r6 - temp_r5);
}

void func_0200bf64(u32 *arg0,void *arg1) {
    extern M2C_UNK data_0212fc14;
    volatile u32 tmp[2];
    u32 base = (u32)&data_0212fc14;
    u32 x = M2C_FIELD(arg1,u32 *,24);
    tmp[1] = x;
    arg0[0] = base;
    tmp[0] = base;
    arg0[1] = x;
}

#pragma scheduling off
s32 func_0200bf8c(u32 *arg0, s32 arg1, u32 arg2, s32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7) {
    void func_0200b774(void *);
    s32 func_0200b99c(void *, s32, u32, u32, s32);
    s32 func_0200bbe0(void *, void *, s32);
    void func_0200ba9c(void *);
    s32 func_0200b9e4(void *, Unk0200FilePair);
    u32 work[18];
    Unk0200FilePair pair;
    u32 size;
    u32 base;
    u32 shifted;

    if (arg1 == 0) {
        size = arg5;
        base = arg4;
    } else {
        size = arg7;
        base = arg6;
    }
    shifted = arg2 << 5;
    if (size <= shifted) {
        return 0;
    }
    func_0200b774(work);
    if (!func_0200b99c(work, arg3, base + shifted, base + size, -1)) {
        return 0;
    }
    if (func_0200bbe0(work, arg0, 32) != 32) {
        func_0200ba9c(work);
        return 0;
    }
    func_0200ba9c(work);
    arg0[8] = arg1;
    func_0200bf64((u32 *)&pair, arg0);
    if (!func_0200b9e4(work, pair)) {
        return 0;
    }
    arg0[9] = work[9];
    arg0[10] = work[10] - work[9];
    func_0200ba9c(work);
    return 1;
}
#pragma scheduling reset
s32 func_0200c084(u32 *arg0,s32 arg1,u32 arg2) {
void func_0200b774(void *);s32 func_0200b9e4(void *,Unk0200FilePair);void func_0200ba9c(void *);void func_02008048();
extern u32 data_0212fc04[2],data_0212fc0c[2];extern M2C_UNK data_0212fc14;
u32 work[18];Unk0200FilePair pair;u32 *p; register s32 offset;u32 base;
p=arg1==0?data_0212fc04:data_0212fc0c;
base=p[0];if(base){
offset=(s32)arg2*32;
if(p[1]<=(arg2<<5))return 0;
func_02008048(base+offset,arg0,32);
arg0[8]=arg1;func_0200b774(work);func_0200bf64((u32 *)&pair,arg0);
if(!func_0200b9e4(work,pair))return 0;
arg0[9]=work[9];arg0[10]=work[10]-work[9];func_0200ba9c(work);return 1;
}
return func_0200bf8c(arg0,arg1,arg2,(s32)&data_0212fc14,*(u32 *)0x27ffe50,*(u32 *)0x27ffe54,*(u32 *)0x27ffe58,*(u32 *)0x27ffe5c);
}
#pragma optimization_level 4
s32 func_0200c180(u32 arg0,s32 arg1,s32 arg2) {
M2C_UNK func_02007f8c(s32,M2C_UNK,s32);
void func_02008048();void func_0200cd68();
extern u32 data_020f5224[2];
u32 out[5];u8 work[64];u32 i;u32 *p;
func_02007f8c((s32)out,0,20);
func_02008048(data_020f5224[0],work,data_020f5224[1]);
func_0200cd68(out,arg1,arg2,work,data_020f5224[1]);
p=out;for(i=0;i<20;i+=4,p++) if(*p!=*(u32 *)(arg0+i)) break;
return i==20;
}

void func_0200c214(void *arg0) {
    u32 func_0200bf0c(void *);
    s32 func_0200c180(u32, s32, s32);
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    void func_02007958(void);
    void func_02000970(s32);
    M2C_UNK func_020067e0(M2C_UNK, M2C_UNK);
    extern u8 data_0212dbac[];
    extern s16 data_0212dbc0;
    void *r5;
    u32 r4;
    u32 top;
    u32 idx;
    u8 *start;
    u8 *end;
    s32 count;
    void *p;
    u32 rr4;
    u32 rr5;
    u32 pp;
    u32 fn;

    r5 = arg0;
    r4 = func_0200bf0c(r5);

    if (*(u16 *)0x27ffc40 == 2) {
        top = (u32)M2C_FIELD(r5, u32 *, 0x1c) >> 24;
        if (top & 2) {
            start = data_0212dbac;
            end = (u8 *)&data_0212dbc0;
            idx = M2C_FIELD(r5, u32 *, 0x0);
            count = (s32)(end - start) / 20;
            if (idx < (u32)count) {
                p = start + idx * 20;
                if (func_0200c180((u32)p, M2C_FIELD(r5, s32 *, 4), r4) == 0) {
                    func_02007f8c(M2C_FIELD(r5, s32 *, 4), 0, r4);
                    func_02007958();
                    return;
                }
            }
        }
    }

    top = (u32)M2C_FIELD(r5, u32 *, 0x1c) >> 24;
    if (top & 1) {
        func_02000970(M2C_FIELD(r5, s32 *, 4) + (s32)r4);
    }
    func_020067e0(M2C_FIELD(r5, M2C_UNK *, 4), M2C_FIELD(r5, M2C_UNK *, 8));
    rr4 = M2C_FIELD(r5, u32 *, 0x10);
    rr5 = M2C_FIELD(r5, u32 *, 0x14);
    if (rr4 >= rr5) return;
    pp = rr4;
    while (pp < rr5) {
        fn = *(u32 *)pp;
        if (fn) ((void (*)(void))fn)();
        pp += 4;
    }
}

M2C_UNK func_0200c308(void *arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern void *data_0213ea14;
    s32 irq;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 base;
    u32 end;
    void *head;
    void *cur;
    void *next;
    void *prev_kept;
    void *removed_head;
    void *removed_tail;
    u32 node_arg;
    void (*cb)(u32);

    f8 = M2C_FIELD(arg0, u32 *, 8);
    fc = M2C_FIELD(arg0, u32 *, 0xC);
    f4 = M2C_FIELD(arg0, u32 *, 4);
    base = f4;
    removed_head = (void *)0;
    removed_tail = (void *)0;
    end = base + f8 + fc;
    irq = func_0200751c();
    head = data_0213ea14;
    cur = head;
    prev_kept = (void *)0;
    if (head != (void *)0) {
        while (cur != (void *)0) {
            next = M2C_FIELD(cur, void **, 0);
            node_arg = M2C_FIELD(cur, u32 *, 8);
            cb = M2C_FIELD(cur, void (**)(u32), 4);
            if ((node_arg == 0 && (u32)cb >= base && (u32)cb < end) ||
                (node_arg != 0 && node_arg >= base && node_arg < end)) {
                if (removed_tail != (void *)0) {
                    M2C_FIELD(removed_tail, void **, 0) = cur;
                } else {
                    removed_head = cur;
                }
                M2C_FIELD(cur, void **, 0) = (void *)0;
                if (cur == head) {
                    data_0213ea14 = next;
                    head = next;
                }
                if (prev_kept != (void *)0) {
                    M2C_FIELD(prev_kept, void **, 0) = next;
                }
                removed_tail = cur;
            } else {
                prev_kept = cur;
            }
            cur = next;
        }
    }
    func_02007530(irq);
    cur = removed_head;
    while (cur != (void *)0) {
        next = M2C_FIELD(cur, void **, 0);
        cb = M2C_FIELD(cur, void (**)(u32), 4);
        if (cb != (void *)0) {
            cb(M2C_FIELD(cur, u32 *, 8));
        }
        cur = next;
    }
}

s32 func_0200c3f8(void) {
    M2C_UNK func_0200c308();
    func_0200c308();
    return 1;
}

s32 func_0200c408(s32 arg0,s32 arg1) {s32 func_0200c084();u8 temp[44];if(!func_0200c084(temp,arg0,arg1) || !((s32 (*)())func_0200c3f8)(temp)) return 0;return 1;}

void func_0200c454(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

void func_0200c494(void *arg0, void *arg1, u32 arg2) {
    void func_02008048(void *, void *, u32);
    void func_0200c614(void *);
    u64 total = M2C_FIELD(arg0, u64 *, 0x10);
    u32 space = 0x40 - ((u32)total & 0x3f);
    s32 n;

    M2C_FIELD(arg0, u64 *, 0x10) = total + arg2;
    if (space > arg2) {
        if (arg2 == 0) return;
        func_02008048(arg1, (u8 *)arg0 + 0x18 + ((u32)total & 0x3f), arg2);
        return;
    }
    func_02008048(arg1, (u8 *)arg0 + 0x18 + ((u32)total & 0x3f), space);
    func_0200c614(arg0);
    arg2 -= space;
    n = arg2 >> 6;
    arg1 = (u8 *)arg1 + space;
    while (n > 0) {
        func_02008048(arg1, (u8 *)arg0 + 0x18, 0x40);
        arg1 = (u8 *)arg1 + 0x40;
        func_0200c614(arg0);
        n = n - 1;
    }
    if (arg2 & 0x3f)
        func_02008048(arg1, (u8 *)arg0 + 0x18, arg2 & 0x3f);
}

void func_0200c55c(M2C_UNK arg0, void *arg1) {
    void func_0200c494(void *, void *, u32);
    void func_0200c614(void *);
    s32 func_02007f8c();
    void func_02008048();
    extern M2C_UNK data_020f522c;
    s32 temp_r6;
    s32 temp_r7;
    s32 var_r3;
    u32 temp_r3;
    u32 var_r2;

    temp_r3 = M2C_FIELD(arg1, u32 *, 0x10);
    temp_r6 = (M2C_FIELD(arg1, s32 *, 0x14) * 8) | (temp_r3 >> 0x1D);
    temp_r7 = temp_r3 * 8;
    func_0200c494(arg1, &data_020f522c, 1);
    var_r3 = M2C_FIELD(arg1, u32 *, 0x10) & 0x3F;
    var_r2 = 0x40 - var_r3;
    if (var_r2 < 8U) {
        func_02007f8c(arg1 + 0x18 + var_r3);
        func_0200c614(arg1);
        var_r3 = 0;
        var_r2 = 0x40;
    }
    if (var_r2 > 8U) {
        func_02007f8c(arg1 + 0x18 + var_r3, 0, var_r2 - 8);
    }
    M2C_FIELD(arg1, s32 *, 0x50) = temp_r7;
    M2C_FIELD(arg1, s32 *, 0x54) = temp_r6;
    func_0200c614(arg1);
    func_02008048(arg1, arg0, 0x10);
    func_02007f8c(arg1, 0, 0x58);
}

void func_0200c614(void *arg0) { }

void func_0200c9c8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xC3D2E1F0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

void func_0200ca18(void *arg0, void *arg1, u32 arg2) {
    void func_02008048(void *, void *, u32);
    extern void (*data_020f53f4)(void *, void *, u32);
    u8 *buf;
    u32 size;
    void *src;
    u32 pending;
    u32 full;
    s32 remaining;

    size = arg2;
    src = arg1;
    buf = (u8 *)arg0 + 0x20;
    if (size == 0) {
        return;
    }
    {
        u32 lo = M2C_FIELD(arg0, u32 *, 0x14);
        u32 newlo = lo + (size << 3);
        if (newlo < lo) {
            M2C_FIELD(arg0, u32 *, 0x18) = M2C_FIELD(arg0, u32 *, 0x18) + 1;
        }
        M2C_FIELD(arg0, u32 *, 0x18) = M2C_FIELD(arg0, u32 *, 0x18) + (size >> 29);
        M2C_FIELD(arg0, u32 *, 0x14) = newlo;
    }
    pending = M2C_FIELD(arg0, u32 *, 0x1C);
    if (pending != 0) {
        if (pending + size >= 0x40U) {
            u32 take = 0x40U - pending;
            func_02008048(src, buf + pending, take);
            size = size - take;
            src = (u8 *)src + take;
            data_020f53f4(arg0, buf, 0x40);
            M2C_FIELD(arg0, u32 *, 0x1C) = 0;
        } else {
            func_02008048(src, buf + pending, size);
            M2C_FIELD(arg0, u32 *, 0x1C) = M2C_FIELD(arg0, u32 *, 0x1C) + size;
            return;
        }
    }
    if (size >= 0x40U) {
        full = size & ~0x3fU;
        size = size - full;
        if (((u32)src & 3U) == 0U) {
            data_020f53f4(arg0, src, full);
            src = (u8 *)src + full;
        } else {
            remaining = full;
            do {
                func_02008048(src, buf, 0x40);
                src = (u8 *)src + 0x40;
                data_020f53f4(arg0, buf, 0x40);
                remaining = remaining - 0x40;
            } while (remaining > 0);
        }
    }
    M2C_FIELD(arg0, u32 *, 0x1C) = size;
    if (size == 0) {
        return;
    }
    func_02008048(src, buf, size);
}

void func_0200cb6c(void *arg0, void *arg1) {
    extern void (*data_020f53f4)(void *, void *, u32);
    void func_02007e54(u32, void *, s32);
    u32 *w;
    u8 *buf;
    u8 *out;
    s32 orig;
    u32 count;
    u32 i;
    u32 lo;
    u32 hi;
    u32 h0;
    u32 h1;
    u32 h2;
    u32 h3;
    u32 h4;

    w = (u32 *)((u8 *)arg0 + 0x20);
    buf = (u8 *)arg0 + 0x20;
    out = (u8 *)arg1;
    orig = *(s32 *)((u8 *)arg0 + 0x1c);

    if ((orig & 3) == 0) {
        w[orig >> 2] = 0;
    }
    count = (u32)orig;
    buf[count] = 0x80;
    count = count + 1;
    while (count & 3) {
        buf[count] = 0;
        count = count + 1;
    }
    i = (u32)((orig >> 2) + 1);
    if (orig >= 0x38) {
        while (i < 16) {
            w[i] = 0;
            i = i + 1;
        }
        data_020f53f4(arg0, buf, 0x40);
        i = 0;
        while (i < 14) {
            w[i] = 0;
            i = i + 1;
        }
    } else {
        while (i < 16) {
            w[i] = 0;
            i = i + 1;
        }
    }
    lo = *(u32 *)((u8 *)arg0 + 0x14);
    buf[0x3f] = (u8)lo;
    buf[0x3e] = (u8)(lo >> 8);
    buf[0x3d] = (u8)(lo >> 16);
    buf[0x3c] = (u8)(lo >> 24);
    hi = *(u32 *)((u8 *)arg0 + 0x18);
    buf[0x3b] = (u8)hi;
    buf[0x3a] = (u8)(hi >> 8);
    buf[0x39] = (u8)(hi >> 16);
    buf[0x38] = (u8)(hi >> 24);
    data_020f53f4(arg0, buf, 0x40);

    h0 = *(u32 *)((u8 *)arg0 + 0x00);
    h1 = *(u32 *)((u8 *)arg0 + 0x04);
    h2 = *(u32 *)((u8 *)arg0 + 0x08);
    h3 = *(u32 *)((u8 *)arg0 + 0x0c);
    h4 = *(u32 *)((u8 *)arg0 + 0x10);

    out[0] = (u8)(h0 >> 24);
    out[1] = (u8)(h0 >> 16);
    out[2] = (u8)(h0 >> 8);
    out[3] = (u8)h0;
    out[4] = (u8)(h1 >> 24);
    out[5] = (u8)(h1 >> 16);
    out[6] = (u8)(h1 >> 8);
    out[7] = (u8)h1;
    out[8] = (u8)(h2 >> 24);
    out[9] = (u8)(h2 >> 16);
    out[10] = (u8)(h2 >> 8);
    out[11] = (u8)h2;
    out[12] = (u8)(h3 >> 24);
    out[13] = (u8)(h3 >> 16);
    out[14] = (u8)(h3 >> 8);
    out[15] = (u8)h3;
    out[16] = (u8)(h4 >> 24);
    out[17] = (u8)(h4 >> 16);
    out[18] = (u8)(h4 >> 8);
    out[19] = (u8)h4;

    *(u32 *)((u8 *)arg0 + 0x1c) = 0;
    func_02007e54(0, (void *)&arg0, 4);
}

