/* 18 functions from 0x02046D38 to 0x02047B84 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u32 lo, hi; } Unk046Pair;
typedef struct { Unk046Pair a, b; s32 flag; } Unk046State;
void func_02045cbc(void *);
s32 func_02045d94(void *, s32);
s32 func_02046ebc(void *);

u64 func_02046d38(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    void func_02008048(u8 *, u8 *, u32);
    extern u8 data_020ea944[];
    extern u8 data_020ea94c[];

    register u32 vlr asm("lr");
    register u32 r12v asm("r12");
    register u32 r4 asm("r4");
    register u32 r5 asm("r5");
    register u32 r6 asm("r6");
    register u32 r7 asm("r7");
    u32 r2;
    u32 r3;
    u32 r0;
    u32 r1;
    u8 sp8[8];
    u8 sp0[8];
    s32 i;

    sp8[0]=0; (void)sp8; (void)sp0;

    vlr = 0;
    r12v = vlr & 0;
    r4 = 0xffff;
    r5 = r4 + 0xff0000;
    r2 = arg2 & 0x1;
    r6 = r12v << 0x2;
    r3 = arg3 & 0x3;
    r5 = arg1 & r5;
    r1 = r3 | (r2 << 0x2);
    r6 = r6 | (r2 >> 0x1e);
    r7 = r12v << 0x3;
    r2 = arg0 & r4;
    r0 = r1 | (r5 << 0x3);
    r1 = r0 | (r2 << 0x1b);
    r3 = (r12v << 0x1b) | (r2 >> 0x5);
    r7 = r7 | (r5 >> 0x1d);
    r0 = r12v | r6;
    r0 = r7 | r0;
    r0 = r3 | r0;

    *(u32 *)&sp8[0] = r1;
    *(u32 *)&sp8[4] = r0;

    i = 0;
    r2 = (u32)&sp8[0] + 0; /* placeholder */
    {
        u8 *p = sp8;
        for (i = 0; i < 6; i++) {
            p[i] ^= 0xd6;
        }
    }

    {
        for (i = 0; i < 5; i++) {
            u8 x = sp8[i];
            sp8[i] = data_020ea94c[x & 0x0f] | (data_020ea94c[(x >> 4) & 0x0f] << 4);
        }
    }

    func_02008048(sp8, sp0, 8);

    {
        extern u8 data_020ea944[];
        for (i = 0; i < 5; i++) {
            sp8[data_020ea944[i]] = sp0[i];
        }
    }

    sp8[5] &= 7;
    sp8[6] = 0;
    sp8[7] = 0;

    {
        u32 lo = *(u32 *)&sp8[0];
        u32 hi = *(u32 *)&sp8[4];
        u32 nlo = lo << 1;
        u32 nhi = (hi << 1) | (lo >> 31);
        *(u32 *)&sp8[0] = nlo;
        *(u32 *)&sp8[4] = nhi;
    }

    sp8[0] |= (sp8[5] >> 3) & 1;

    for (i = 0; i < 6; i++) {
        sp8[i] ^= 0x67;
    }

    sp8[7] = 0;
    sp8[5] &= 7;
    sp8[6] = 0;

    return *(u64 *)&sp8[0];
}

s32 func_02046ebc(void *arg0) {
    void func_02045cbc(void *);
    void func_0200ee70(void);
    s32 func_0200ef4c(void *);
    s32 func_0200eff8(void *);
    long long func_0200f7e0(void *, void *);
    u16 func_02006f8c(void);
    void func_02007724(void *);
    u64 func_02007004(void);
    u64 func_02046d38(u32, u32, u32, u32);

    u8 *p = (u8 *)arg0;
    u8 sp[0x24];
    long long diff;
    u32 seed;
    u32 spval;
    u8 flag;
    u32 r9;
    u16 f10;
    u32 r8;
    u16 cand;
    u64 res;

    func_02045cbc(p);
    func_0200ee70();
    if (func_0200ef4c(&sp[0x14]) != 0) return 0;
    if (func_0200eff8(&sp[0x8]) != 0) return 0;

    diff = func_0200f7e0(&sp[0x14], &sp[0x8]);
    if (diff < 0) return 0;
    if (func_02006f8c() == 0) return 0;

    seed = (u32)diff + (u32)func_02007004;
    func_02007724(sp);
    spval = sp[2] | (sp[1] << 8) | (sp[0] << 16);
    flag = (spval != 0x9bf) ? 1 : 0;
    r9 = seed * 0x5d588b65u + 0x269ec3u;
    f10 = (u16)(((r9 >> 16) * 1000u) >> 16);
    *(u16 *)(p + 0x10) = f10;
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 4) = 0;
    cand = *(u16 *)(p + 0x12);
    r8 = sp[5] | (sp[4] << 8) | (sp[3] << 16);
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 12) = 0;

    if (cand == 0) {
        do { r9 = r9 * 0x5d588b65u + 0x269ec3u; } while (r9 == 0);
        cand = (u16)r9;
        *(u16 *)(p + 0x12) = cand;
        res = func_02046d38(cand, r8, flag, 0);
        *(u32 *)(p + 8) = (u32)res;
        *(u32 *)(p + 12) = (u32)(res >> 32);
        if (*(u32 *)(p + 8) != 0 || *(u32 *)(p + 12) != 0) {
            return 1;
        }
    }

    cand = *(u16 *)(p + 0x12) + 1;
    *(u16 *)(p + 0x12) = cand;
    res = func_02046d38(cand, r8, flag, 0);
    *(u32 *)(p + 8) = (u32)res;
    *(u32 *)(p + 12) = (u32)(res >> 32);
    if (*(u32 *)(p + 8) != 0 || *(u32 *)(p + 12) != 0) {
        return 1;
    }

    for (;;) {
        r9 = r9 * 0x5d588b65u + 0x269ec3u;
        if (r9 == 0) {
            r9 = r9 * 0x5d588b65u + 0x269ec3u;
            continue;
        }
        cand = (u16)r9;
        if (*(u16 *)(p + 0x12) == cand) {
            r9 = r9 * 0x5d588b65u + 0x269ec3u;
            continue;
        }
        *(u16 *)(p + 0x12) = cand;
        res = func_02046d38(cand, r8, flag, 0);
        *(u32 *)(p + 8) = (u32)res;
        *(u32 *)(p + 12) = (u32)(res >> 32);
        if (*(u32 *)(p + 8) == 0 && *(u32 *)(p + 12) == 0) {
            r9 = r9 * 0x5d588b65u + 0x269ec3u;
            continue;
        }
        return 1;
    }
}

s32 func_02047098(s32 arg0) { Unk046State s; if (func_02046ebc(&s)==0) return 0; if(func_02045d94(&s,arg0)!=0) return 1; return 0; }

s32 func_020470dc(Unk046State *p, s32 x) { Unk046State s; func_02045cbc(&s); *(u64 *)&p->a=*(u64 *)&p->b; *(u64 *)&p->b=*(u64 *)&s.b; if(func_02045d94(p,x)!=0) return 1; return 0; }

s32 func_0204712c(void *arg0) {
    void func_02045cbc(void *);
    void func_0200ee70(void);
    s32 func_0200ef4c(void *);
    s32 func_0200eff8(void *);
    long long func_0200f7e0(void *, void *);
    u16 func_02006f8c(void);
    void func_02007724(void *);
    u64 func_02007004(void);
    u64 func_02046d38(u32, u32, u32, u32);

    u8 *p;
    u8 sp[0x24];
    long long diff;
    u32 seed;
    u32 spval;
    u8 flag;
    u32 r9;
    u16 f10;
    u32 r8;
    u16 cand;
    u64 res;

    p = arg0;
    sp[0] = 0; sp[1] = 0; sp[2] = 0; sp[3] = 0; sp[4] = 0; sp[5] = 0;

    func_02045cbc(p);
    func_0200ee70();
    if (func_0200ef4c(&sp[0x14]) != 0) return 0;
    if (func_0200eff8(&sp[0x8]) != 0) return 0;

    diff = func_0200f7e0(&sp[0x14], &sp[0x8]);
    if (diff < 0) return 0;
    if (func_02006f8c() == 0) return 0;

    seed = (u32)diff + (u32)func_02007004;
    func_02007724(sp);
    spval = sp[2] | (sp[1] << 8) | (sp[0] << 16);
    flag = (spval != 0x9bf) ? 1 : 0;
    r9 = seed * 0x5d588b65u + 0x269ec3u;
    f10 = (u16)(((r9 >> 16) * 1000u) >> 16);
    *(u32 *)((u8 *)p + 0x8) = 0;
    *(u32 *)((u8 *)p + 0xc) = 0;
    *(u16 *)((u8 *)p + 0x10) = f10;
    r8 = sp[5] | (sp[4] << 8) | (sp[3] << 16);

    r9 = r9 * 0x5d588b65u + 0x269ec3u;
    for (;;) {
        if (r9 == 0) { r9 = r9 * 0x5d588b65u + 0x269ec3u; continue; }
        cand = (u16)r9;
        if (*(u16 *)((u8 *)p + 0x12) == cand) { r9 = r9 * 0x5d588b65u + 0x269ec3u; continue; }
        *(u16 *)((u8 *)p + 0x12) = cand;
        res = func_02046d38(cand, r8, flag, 0);
        *(u32 *)((u8 *)p + 0x8) = (u32)res;
        *(u32 *)((u8 *)p + 0xc) = (u32)(res >> 32);
        if (*(u32 *)((u8 *)p + 0x8) == 0 && *(u32 *)((u8 *)p + 0xc) == 0) {
            r9 = r9 * 0x5d588b65u + 0x269ec3u;
            continue;
        }
        return 1;
    }
}

void func_020472cc(Unk046State *p) { Unk046State s; func_02045cbc(&s); *(u64 *)&p->a=*(u64 *)&s.a; *(u64 *)&p->b=*(u64 *)&s.b; p->flag=*(u64 *)&s.a != 0; }

s32 func_02047320(void) { Unk046State s; func_02045cbc(&s); if(*(u64 *)&s.b==0 && *(u64 *)&s.a==0)return 1;return 0; }

u32 func_02047370(u32 n) { return ((n % 3 != 0) + n / 3) * 4; }

void func_020473a8(void) {

}

void func_020473ac(void *arg0, u32 arg1, s32 arg2) {
    void func_020651a4(void *, const void *, s32);
    void func_02076658(u8 *, u8 *, s32);
    s32 func_02068c34(const void *);
    s32 func_02068eac(void *, void *, s32);
    void func_020376d8(s32, s32, s32);
    extern M2C_UNK data_020fca58;
    extern u8 data_020ea95c[];
    extern u8 data_020fca88[];
    extern u8 data_020fcac0[];
    extern u8 data_020fcac8[];

    s8 sp[0x48];
    s32 state;
    s32 i;
    u8 *base;
    u8 *target;
    s32 len;

    M2C_FIELD(&data_020fca58, s32 *, 0x8) = -1;
    state = M2C_FIELD(&data_020fca58, s32 *, 0x4);
    if (state == 1) return;
    if (arg2 != 0) {
        M2C_FIELD(&data_020fca58, s32 *, 0x4) = 1;
        return;
    }
    if (state == 5) {
        if (arg1 == 0x20) {
            for (i = 0; i < 8; i++) {
                sp[i*2] = data_020ea95c[i*2];
                sp[i*2+1] = data_020ea95c[i*2+1];
            }
            sp[16] = data_020ea95c[16];
            for (i = 0; i < 10; i++) {
                sp[0x11 + i*2] = data_020fca88[i*2];
                sp[0x11 + i*2 + 1] = data_020fca88[i*2 + 1];
            }
            func_020651a4(sp + 0x25, arg0, 0x20);
            target = M2C_FIELD(&data_020fca58, u8 *, 0x58) + 0x14;
            func_02076658(target, sp + 0x11, 0x34);
            base = M2C_FIELD(&data_020fca58, u8 *, 0x58);
            for (i = 0; i < 20; i++) {
                u8 hi = target[i] >> 4;
                u8 lo = target[i] & 0x0f;
                base[i*2] = sp[hi];
                base[i*2+1] = sp[lo];
            }
            len = func_02068c34(data_020fcac0);
            base[-len] = 0x26;
            M2C_FIELD(&data_020fca58, s32 *, 0x4) = 6;
            return;
        } else {
            M2C_FIELD(&data_020fca58, s32 *, 0x4) = 1;
            func_020376d8(0, (s32)arg0, 0);
            return;
        }
    }
    if (state == 7) {
        len = func_02068c34(data_020fcac8);
        if (func_02068eac(arg0, data_020fcac8, len) == 0) {
            func_020376d8(0, (s32)arg0, 0);
            M2C_FIELD(&data_020fca58, s32 *, 0x4) = 1;
            return;
        } else {
            if (M2C_FIELD(&data_020fca58, s32 *, 0x60) != 0) {
                func_020376d8(0, (s32)M2C_FIELD(&data_020fca58, s32 *, 0x60), 0);
            }
            M2C_FIELD(&data_020fca58, s32 **, 0x60) = (s32 *)arg0;
            M2C_FIELD(&data_020fca58, s32 *, 0x64) = (s32)arg1;
            M2C_FIELD(&data_020fca58, s32 *, 0x4) = 8;
            return;
        }
    }
}

void func_020475b8(s32 arg0) {
    extern s32 data_0213db80;
    data_0213db80 = arg0 | (arg0 << 0x10);
}

s32 func_020475cc(void) { extern M2C_UNK data_020fca58; extern s32 data_0213db80; data_0213db80=(M2C_FIELD(&data_020fca58,s32 *,0x44)*data_0213db80+M2C_FIELD(&data_020fca58,s32 *,0x48))%M2C_FIELD(&data_020fca58,s32 *,0x4c); return (data_0213db80>>16)&255; }

s32 func_0204760c(u8 *arg0, u8 *arg1, u32 arg2, u8 *arg3, u32 arg4) {
    extern M2C_UNK data_020fca58;
    u8 *p;
    u32 sum;
    u32 n;
    s32 i, k, l;
    u8 *func_02037694(s32, s32);
    void func_020475b8(s32);
    s32 func_020475cc(void);
    void func_02049ab8(u8 *, u8 *, s32, s32);

    n = arg4 + arg2;
    sum = 0;
    p = func_02037694(0, n + 4);
    if (p == 0) return 2;
    for (i = 0; i < arg2; i++) p[i + 4] = arg1[i];
    for (i = 0; i < arg4; i++) p[arg2 + i + 4] = arg3[i];
    for (k = 0; k < n; k++) sum += p[k + 4];
    func_020475b8(sum);
    for (l = 0; l < n; l++) {
        p[l + 4] ^= func_020475cc();
    }
    sum ^= M2C_FIELD(&data_020fca58, u32 *, 0x50);
    p[0] = sum >> 24;
    p[1] = sum >> 16;
    p[2] = sum >> 8;
    p[3] = sum;
    func_02049ab8(p, arg0, n + 4, 2);
    func_020376d8(0, (s32)p, 0);
    arg0[func_02047370(n + 4)] = 0;
    return 0;
}

#pragma opt_propagation off
void func_02047750(s32 arg0) { M2C_UNK *p; extern M2C_UNK data_020fca58,data_020fcad0,data_020fcaf8; M2C_FIELD(&data_020fca58,s32 *,8)=-1; M2C_FIELD(&data_020fca58,s32 *,0x54)=0; M2C_FIELD(&data_020fca58,s32 *,0x58)=0; p=arg0?&data_020fcad0:&data_020fcaf8; M2C_FIELD(&data_020fca58,s32 *,0x5c)=0; M2C_FIELD(&data_020fca58,s32 *,0x60)=0; M2C_FIELD(&data_020fca58,s32 *,0x64)=0; M2C_FIELD(&data_020fca58,M2C_UNK **,0)=p; func_02044e04(0); M2C_FIELD(&data_020fca58,s32 *,4)=3; }
#pragma opt_propagation reset
s32 func_020477ac(void) {
    extern M2C_UNK data_020fca58;
    void func_020473a8(void);
    void func_020473ac(void *, u32, s32);
    M2C_UNK func_02045110(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02044e68(void);

    switch (M2C_FIELD(&data_020fca58, s32 *, 4)) {
    case 5:
        {
            M2C_UNK r = func_02045110(M2C_FIELD(&data_020fca58, M2C_UNK *, 0x54), (M2C_UNK)0, (M2C_UNK)0,
                          (M2C_UNK)func_020473a8, (M2C_UNK)func_020473ac, (M2C_UNK)0);
            M2C_FIELD(&data_020fca58, M2C_UNK *, 8) = r;
            M2C_FIELD(&data_020fca58, s32 *, 4) = ((s32)r >= 0) ? 5 : 1;
        }
        break;
    case 6:
        if (func_02044e68() == 0) {
            M2C_FIELD(&data_020fca58, s32 *, 4) = 1;
        }
        break;
    case 7:
        {
            M2C_UNK r = func_02045110(M2C_FIELD(&data_020fca58, M2C_UNK *, 0x54), (M2C_UNK)0, (M2C_UNK)0,
                          (M2C_UNK)func_020473a8, (M2C_UNK)func_020473ac, (M2C_UNK)0);
            M2C_FIELD(&data_020fca58, M2C_UNK *, 8) = r;
            M2C_FIELD(&data_020fca58, s32 *, 4) = ((s32)r >= 0) ? 7 : 1;
        }
        break;
    case 8:
        if (func_02044e68() == 0) {
            M2C_FIELD(&data_020fca58, s32 *, 4) = 1;
        }
        break;
    default:
        break;
    }
    return M2C_FIELD(&data_020fca58, s32 *, 4);
}

s32 func_020477ac(void);

void func_020478b8(void) { extern M2C_UNK data_020fca58; M2C_UNK func_020376d8(s32,s32,s32); s32 p; p=M2C_FIELD(&data_020fca58,s32 *,0x54);if(p) {func_020376d8(0,p,0);M2C_FIELD(&data_020fca58,s32 *,0x54)=0;} p=M2C_FIELD(&data_020fca58,s32 *,0x60);if(p) {func_020376d8(0,p,0);M2C_FIELD(&data_020fca58,s32 *,0x64)=0;M2C_FIELD(&data_020fca58,s32 *,0x60)=0;} func_02044e28(); M2C_FIELD(&data_020fca58,s32 *,4)=2; }

s32 func_02047928(s32 *arg0) {
    extern M2C_UNK data_020fca58;
    *arg0 = M2C_FIELD(&data_020fca58, s32 *, 0x64);
    return M2C_FIELD(&data_020fca58, s32 *, 0x60);
}

s32 func_02047940(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    extern M2C_UNK data_020fca58;
    extern M2C_UNK data_020fcb1c;
    extern M2C_UNK data_020fcb24;
    extern unsigned char data_020fcac0[];
    extern M2C_UNK data_020fcb50;
    extern M2C_UNK data_020fcb8c;
    extern M2C_UNK data_020fca68;
    extern M2C_UNK data_020fcb88;
    extern M2C_UNK data_020fcb6c;
    M2C_UNK func_020675e4(M2C_UNK, M2C_UNK, ...);

    s32 r5 = 0;
    void *ptr;
    M2C_UNK tmp;
    s32 len_cb1c, len_cb24, len_cac0, len_after;
    s32 len_cb50, len_cb8c, len_data0, len_cb88;
    s32 accum;
    s32 len_ptr;
    s32 len_cb1c2, len_cb242;
    u32 arr[5];
    s32 res;
    s32 len_cac0b;

    if (M2C_FIELD(&data_020fca58, s32 *, 0x0c) != 1) {
        return 3;
    }

    if (M2C_FIELD(&data_020fca58, s32 *, 0x54) != 0) {
        func_020376d8(0, M2C_FIELD(&data_020fca58, s32 *, 0x54), 0);
        M2C_FIELD(&data_020fca58, s32 *, 0x54) = 0;
        r5 = func_02047370((u32)((s32 *)arg4)[0] + 0x18);
    }

    len_cb1c = func_02068c34(data_020fcb1c);
    len_cb24 = func_02068c34(data_020fcb24);
    len_cac0 = func_02068c34(data_020fcac0);

    len_after = func_02068c34(func_0206f8b8((void *)arg2, &tmp, 10));

    len_cb50 = func_02068c34(data_020fcb50);
    len_cb8c = func_02068c34(data_020fcb8c);
    len_data0 = func_02068c34(M2C_FIELD(&data_020fca58, M2C_UNK *, 0x00));
    len_cb88 = func_02068c34(data_020fcb88);

    accum = len_data0 + len_cb88;
    accum = len_cb8c + accum;
    accum = len_cb50 + accum;
    accum = len_after + accum;
    accum = len_cac0 + accum;
    accum = len_cb24 + accum;
    accum = len_cb1c + accum;
    accum = r5 + accum;

    ptr = func_02037694(0, accum + 1);
    M2C_FIELD(&data_020fca58, void **, 0x54) = ptr;
    if (ptr == 0) {
        return 2;
    }

    func_020675e4(ptr, data_020fcb6c,
                    M2C_FIELD(&data_020fca58, s32 *, 0x00),
                    data_020fca68,
                    data_020fcb8c, arg2, data_020fcb24, data_020fcb88);

    len_ptr = func_02068c34(ptr);
    M2C_FIELD(&data_020fca58, void **, 0x5c) = (void *)((u8 *)ptr + len_ptr);

    len_cb1c2 = func_02068c34(data_020fcb1c);
    len_cb242 = func_02068c34(data_020fcb24);
    M2C_FIELD(&data_020fca58, s32 *, 0x58) =
        (s32)M2C_FIELD(&data_020fca58, void **, 0x5c) - len_cb1c2 - len_cb242;

    arr[0] = (u32)arg2;
    arr[1] = (u32)arg3;
    arr[2] = (u32)arg1;
    arr[3] = (u32)arg0;
    arr[4] = (u32)*(u32 *)arg4;

    res = func_0204760c(M2C_FIELD(&data_020fca58, void **, 0x5c), arr, 0x14, (void *)((u8 *)arg4 + 4), *(s32 *)arg4);
    if (res == 2) {
        func_020376d8(0, M2C_FIELD(&data_020fca58, s32 *, 0x54), 0);
        M2C_FIELD(&data_020fca58, s32 *, 0x54) = 0;
        return 2;
    } else {
        len_cac0b = func_02068c34(data_020fcac0);
        *(u8 *)((u8 *)M2C_FIELD(&data_020fca58, void **, 0x58) - len_cac0b) = 0;
        M2C_FIELD(&data_020fca58, s32 *, 0x04) = 4;
        return 0;
    }
}

