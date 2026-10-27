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

s32 func_02047098(s32 arg0) { Unk046State s; if (func_02046ebc(&s)==0) return 0; if(func_02045d94(&s,arg0)!=0) return 1; return 0; }

s32 func_020470dc(Unk046State *p, s32 x) { Unk046State s; func_02045cbc(&s); *(u64 *)&p->a=*(u64 *)&p->b; *(u64 *)&p->b=*(u64 *)&s.b; if(func_02045d94(p,x)!=0) return 1; return 0; }

void func_020472cc(Unk046State *p) { Unk046State s; func_02045cbc(&s); *(u64 *)&p->a=*(u64 *)&s.a; *(u64 *)&p->b=*(u64 *)&s.b; p->flag=*(u64 *)&s.a != 0; }

s32 func_02047320(void) { Unk046State s; func_02045cbc(&s); if(*(u64 *)&s.b==0 && *(u64 *)&s.a==0)return 1;return 0; }

u32 func_02047370(u32 n) { return ((n % 3 != 0) + n / 3) * 4; }

void func_020473a8(void) {

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

void func_02047750(s32 arg0) { register M2C_UNK *p; extern M2C_UNK data_020fca58,data_020fcad0,data_020fcaf8; M2C_FIELD(&data_020fca58,s32 *,8)=-1; M2C_FIELD(&data_020fca58,s32 *,0x54)=0; M2C_FIELD(&data_020fca58,s32 *,0x58)=0; if(arg0) p=&data_020fcad0; else p=&data_020fcaf8; M2C_FIELD(&data_020fca58,s32 *,0x5c)=0; M2C_FIELD(&data_020fca58,s32 *,0x60)=0; M2C_FIELD(&data_020fca58,s32 *,0x64)=0; M2C_FIELD(&data_020fca58,M2C_UNK **,0)=p; func_02044e04(0); M2C_FIELD(&data_020fca58,s32 *,4)=3; }

s32 func_020477ac(void) {
    extern M2C_UNK data_020fca58;
    void func_020473a8(void);
    void func_020473ac(void);
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

