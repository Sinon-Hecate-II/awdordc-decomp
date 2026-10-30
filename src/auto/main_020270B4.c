/* 16 functions from 0x020270B4 to 0x02028038 (main), found by ds-decomp. */
#include "common.h"
extern s32 data_02138e4c;
void func_02027e80(s32, void *, s32);
s32 func_0200751c(void);
void func_02007530(s32);
void func_02028160(s32);

void func_02028018(void);
s32 func_020270b4(void *p,u32 size) {
s32 s=func_0200751c();
if(data_02138e4c){func_02007530(s);return 1;}
if(!p){func_02007530(s);return 1;}
if((u32)p&31){func_02007530(s);return 1;}
if(size<0x2300){func_02007530(s);return 6;}
data_02138e4c=(s32)p;
M2C_FIELD(p,s32 *,0x2260)=1;
M2C_FIELD((void *)data_02138e4c,u16 *,0x2280)=0;
M2C_FIELD((void *)data_02138e4c,u16 *,0x2268)=0;
M2C_FIELD((void *)data_02138e4c,u8 *,0x226a)=0;
M2C_FIELD((void *)data_02138e4c,u8 *,0x226b)=0;
M2C_FIELD((void *)data_02138e4c,u16 *,0x2282)=0;
M2C_FIELD((void *)data_02138e4c,u16 *,0x22f8)=0;
func_02028018();func_020296a0();
if(!func_02006f8c())func_02006f14();
if(!func_02007180())func_02007140();
func_02007190((void *)(data_02138e4c+0x22cc));
func_02007530(s);return 0;
}

s32 func_020271cc(void){s32 s=func_0200751c(); void *p=(void *)data_02138e4c; if(!p){func_02007530(s);return 1;} if(M2C_FIELD(p,s32 *,0x2260)!=1){func_02007530(s);return 1;} data_02138e4c=0;func_02007530(s);return 0;}

s32 func_02027224(void *a, s32 b) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02027d60(void *, s32);
    void func_02028160(s32);
    s32 func_02011034(s32, s32);
    s32 func_020119dc(s32);
    s32 func_020120f8(void *);
    u16 func_02011d58(void);
    s32 func_02011244(void);
    void func_0202830c(void);
    void func_02028384(void);
    extern s32 data_02138e4c;

    s32 s;
    void *p;
    s32 state;
    s32 r;
    u16 masked;
    s32 t;
    s32 u;

    s = func_0200751c();
    p = (void *)data_02138e4c;
    if (p == 0) {
        func_02007530(s);
        return 1;
    }
    state = M2C_FIELD(p, s32 *, 0x2260);
    switch (state) {
    case 1:
        func_02027d60(a, b);
        break;
    case 2:
        func_02007530(s);
        return 2;
    case 3:
        func_02007530(s);
        return 0;
    default:
        func_02007530(s);
        return 1;
    }

    masked = (u16)M2C_FIELD((void *)data_02138e4c, u32 *, 0x226c);
    r = func_02011034(data_02138e4c, (s32)masked);

    switch (r) {
    case 3:
        func_02028160(0xB);
        func_02007530(s);
        return 7;
    case 4:
        func_02007530(s);
        return 5;
    default:
        func_02028160(0xB);
        func_02007530(s);
        return 7;
    case 0: {
        t = func_02011d58();
        if (t != 0) {
            t = func_020119dc((s32)func_0202830c);
            if (t != 0) {
                func_02028160(0xB);
                func_02007530(s);
                return 7;
            }
            t = func_020120f8((void *)func_02028384);
            if (t == 2) {
                func_02028160(2);
                M2C_FIELD((void *)data_02138e4c, u16 *, 0x2280) = 1;
                func_02007530(s);
                return 3;
            }
            if (t == 3) {
                func_02028160(0xB);
                func_02007530(s);
                return 7;
            }
            if (t == 8) {
                func_02028160(0xC);
                func_02007530(s);
                return 1;
            }
            func_02028160(0xB);
            func_02007530(s);
            return 7;
        } else {
            u = func_02011244();
            if (u == 0) {
                func_02007530(s);
                return 5;
            }
            func_02028160(0xB);
            func_02007530(s);
            return 7;
        }
    }
    }
}

void func_02028384(void);
s32 func_02027428(void) {
    s32 s = func_0200751c();
    void *p = (void *)data_02138e4c;
    s32 v;
    s32 r;

    if (p == 0) {
        func_02007530(s);
        return 1;
    }
    v = M2C_FIELD(p, s32 *, 0x2260);
    switch (v) {
    case 1:
        func_02007530(s);
        return 1;
    case 3:
        r = func_020121d8((M2C_UNK)func_02028384);
        switch (r) {
        case 2:
            func_02028160(4);
            M2C_FIELD((void *)data_02138e4c, u16 *, 0x2280) = 2;
            func_02007530(s);
            return 3;
        case 8:
            func_02007530(s);
            return 4;
        case 3:
        default:
            func_02028160(0xB);
            func_02007530(s);
            return 7;
        }
    case 4:
        func_02007530(s);
        return 2;
    default:
        func_02007530(s);
        return 0;
    }
}

void func_02027518(s32 a,s32 b){s32 func_020276b0(void); s32 func_02027538(); if(a==0 || b==0)func_020276b0();else func_02027538();}

void func_02028640(void);
s32 func_02027538(s32 a,s32 b,s32 c){
s32 s=func_0200751c();void *p=(void *)data_02138e4c;
if(!p){func_02007530(s);return 1;}
switch(M2C_FIELD(p,s32 *,0x2260)){
case 5:func_02027e80(a,b,c);func_02007530(s);return 2;
case 6:func_02027e80(a,b,c);func_02007530(s);return 0;
default:func_02007530(s);return 1;
case 3:break;
}
func_02027e80(a,b,c);
func_020067a8(M2C_FIELD((void *)data_02138e4c,s32 *,0x2288),M2C_FIELD((void *)data_02138e4c,u16 *,0x228c));
M2C_FIELD((void *)data_02138e4c,s32 *,0x2284)++;
switch(func_020125b0((M2C_UNK)func_02028640,data_02138e4c+0x2288)){
case 2:func_02028160(5);M2C_FIELD((void *)data_02138e4c,u16 *,0x2280)=3;break;
case 8:func_02007530(s);return 4;
case 3:default:func_02028160(11);func_02007530(s);return 7;
}
func_02007530(s);return 3;
}

s32 func_020276b0(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02028160(s32);
    extern M2C_UNK data_02138e4c;
    void *ptr;
    s32 st;
    s32 r = func_0200751c();
    ptr = (void *)M2C_FIELD(&data_02138e4c, M2C_UNK *, 0);
    if (ptr == 0) {
        func_02007530(r);
        return 1;
    }
    st = M2C_FIELD(ptr, s32 *, 0x2260);
    switch (st) {
    case 3:
        func_02028160(7);
        M2C_FIELD(ptr, u16 *, 0x2280) = 4;
        func_02007530(r);
        return 3;
    case 6:
        func_02007530(0);
        return 2;
    case 7:
        func_02007530(0);
        return 0;
    default:
        func_02007530(0);
        return 1;
    }
}

s32 func_02027754(void *a, void *b, s32 c) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02007f8c(void *, u32, u32);
    void func_02008048(void *, void *, u32);
    u32 func_02027cb4(u32);
    void func_02028160(s32);
    void func_02028384(void);
    s32 func_02013d4c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16);
    s32 s = func_0200751c();
    void *p = (void *)data_02138e4c;
    s32 state;
    if (p == 0) {
        func_02007530(s);
        return 1;
    }
    state = M2C_FIELD(p, s32 *, 0x2260);
    switch (state) {
    case 3:
        if (a == 0) {
            func_02007530(s);
            return 1;
        }
        if (M2C_FIELD(a, u16 *, 0x3c) == 0) {
            func_02007530(s);
            return 1;
        }
        if (b != 0) {
            if (M2C_FIELD(b, u8 *, 0) >= 4 || M2C_FIELD(b, u8 *, 1) >= 4) {
                func_02007530(s);
                return 1;
            }
            M2C_FIELD((void *)data_02138e4c, u8 *, 0x2250) = M2C_FIELD(b, u8 *, 0);
            M2C_FIELD((void *)data_02138e4c, u8 *, 0x2251) = M2C_FIELD(b, u8 *, 1);
            if (M2C_FIELD((void *)data_02138e4c, u8 *, 0x2250) == 0) {
                func_02007f8c((void *)((char *)data_02138e4c + 0x2200), 0, 0x50);
            } else {
                func_02008048((void *)((char *)b + 2), (void *)((char *)data_02138e4c + 0x2200), 0x50);
            }
        } else {
            func_02007f8c((void *)((char *)data_02138e4c + 0x2200), 0, 0x52);
        }
        func_02008048(a, (void *)((char *)data_02138e4c + 0x2140), 0xc0);
        {
            u16 r2 = M2C_FIELD((void *)data_02138e4c, u16 *, 0x216e);
            r2 |= 3;
            M2C_FIELD((void *)data_02138e4c, u16 *, 0x2170) = r2;
        }
        func_02027cb4((u32)c);
        {
            s32 r = func_02013d4c((M2C_UNK)func_02028384, (M2C_UNK)0xffff, 0x50, 0xffff, (u16)0xffff);
            switch (r) {
            case 2:
                func_02028160(8);
                M2C_FIELD((void *)data_02138e4c, u16 *, 0x2280) = 5;
                break;
            case 3:
            default:
                func_02028160(0xb);
                func_02007530(s);
                return 7;
            case 8:
                func_02007530(s);
                return 4;
            }
        }
        func_02007530(s);
        return 3;
    case 8:
        func_02007530(s);
        return 2;
    case 9:
        func_02007530(s);
        return 0;
    default:
        func_02007530(s);
        return 1;
    }
}

void func_02028dd8(void);
s32 func_02027958(void) {
    s32 s;
    void *p;
    s32 st;
    s32 r;
    s = func_0200751c();
    p = (void *)data_02138e4c;
    if (p == 0) {
        func_02007530(s);
        return 1;
    }
    st = M2C_FIELD(p, s32 *, 0x2260);
    if (st == 3) {
        func_02007530(s);
        return 0;
    }
    if (st == 10) {
        func_02007530(s);
        return 2;
    }
    if (st != 9) {
        func_02007530(s);
        return 1;
    }
    if (M2C_FIELD(p, u8 *, 0x226b) == 1) {
        func_02028160(10);
        M2C_FIELD((void *)data_02138e4c, u16 *, 0x2280) = 6;
    } else {
        r = func_02012f40((void *)func_02028dd8);
        if (r == 2) {
            func_02028160(10);
            M2C_FIELD((void *)data_02138e4c, u16 *, 0x2280) = 6;
        } else if (r == 8) {
            func_02007530(s);
            return 4;
        } else {
            func_02028160(11);
            func_02007530(s);
            return 7;
        }
    }
    func_02007530(s);
    return 3;
}

void func_02027a74(void){}

s32 func_02027c84(void){s32 s=func_0200751c();s32 r=0;void *p=(void *)data_02138e4c;if(p)r=M2C_FIELD(p,s32 *,0x2260);func_02007530(s);return r;}

u32 func_02027cb4(u32 arg){u32 old;u32 a=arg;s32 s=func_0200751c();u32 mask=0;void *p=(void *)data_02138e4c;old=M2C_FIELD(p+0x2000,u32 *,0x264);if(!p){func_02007530(s);return 0;}if(a&0x8000){mask|=0x3ffe;if(!(a&0x3ffe))a|=0xa082;}if(a&0x20000)mask|=0x10000;if(a&0x80000)mask|=0x40000;if(a&0x200000)mask|=0x100000;if(a&0x800000)mask|=0x400000;M2C_FIELD(p+0x2000,u32 *,0x264)=a|(old&~mask);func_02007530(s);return old;}

s32 func_02027d50(void) {
    extern s32 data_02138e4c;
    return data_02138e4c;
}

void func_02007f8c(void *, u32, u32);
void func_02027d60(void *a, s32 b) {
    if (a == 0) {
        M2C_FIELD((void *)data_02138e4c, s32 *, 0x226c) = 3;
        M2C_FIELD((void *)data_02138e4c, s32 *, 0x2270) = 0;
        M2C_FIELD((void *)data_02138e4c, s32 *, 0x2274) = 0;
        M2C_FIELD((void *)data_02138e4c, s32 *, 0x2278) = 0;
        return;
    }
    {
        u32 v0 = M2C_FIELD(a, u32 *, 0);
        u32 v4 = M2C_FIELD(a, u32 *, 4);
        u32 v8 = M2C_FIELD(a, u32 *, 8);
        u32 v12 = M2C_FIELD(a, u32 *, 12);
        u32 rem;
        M2C_FIELD((void *)data_02138e4c, u32 *, 0x226c) = v0 & 3;
        rem = (4 - (v4 & 3)) & 3;
        if (rem + 12 > v8) {
            M2C_FIELD((void *)data_02138e4c, u32 *, 0x2270) = 0;
            M2C_FIELD((void *)data_02138e4c, u32 *, 0x2274) = 0;
        } else {
            M2C_FIELD((void *)data_02138e4c, u32 *, 0x2270) = (v4 + 3) & ~3;
            M2C_FIELD((void *)data_02138e4c, u32 *, 0x2274) =
                v8 - ((4 - (v4 & 3)) & 3);
        }
        func_02007f8c(M2C_FIELD((void *)data_02138e4c, void **, 0x2270), 0,
                       M2C_FIELD((void *)data_02138e4c, u32 *, 0x2274));
        M2C_FIELD((void *)data_02138e4c, u32 *, 0x2278) = v12;
        M2C_FIELD((void *)data_02138e4c, u32 *, 0x227c) = (u32)b;
    }
}

void func_02027e80(s32 a, void *b, s32 c) {
    u32 func_02027cb4(u32);
    s32 func_02028038(s32);
    u16 func_02011e98(void);
    void func_02008048(void *, void *, u32);
    extern s32 data_02138e4c;
    extern u8 data_020ea758[];
    extern u8 data_020ea760[];
    u8 *r4 = (u8 *)b;
    s32 tmp;
    u32 i;
    func_02027cb4((u32)c);
    M2C_FIELD((void *)data_02138e4c, void **, 0x2288) = (void *)((s32)data_02138e4c + 0x1500);
    M2C_FIELD((void *)data_02138e4c, u16 *, 0x228c) = 0x400;
    tmp = func_02028038(0);
    M2C_FIELD((void *)data_02138e4c, u16 *, 0x228e) = (u16)(((s32)1 << tmp) >> 1);
    if (M2C_FIELD((void *)data_02138e4c, u16 *, 0x2268) == 0) {
        u16 v = func_02011e98();
        M2C_FIELD((void *)data_02138e4c, u16 *, 0x2290) = v;
        {
            u32 x = M2C_FIELD((void *)data_02138e4c, u32 *, 0x2264);
            M2C_FIELD((void *)data_02138e4c, u16 *, 0x2298) = (x & 0x300000) != 0x300000 ? 1 : 0;
        }
    }
    if (a == 0) {
        func_02008048((void *)data_020ea758, (void *)((u8 *)data_02138e4c + 0x2292), 6);
    } else {
        func_02008048((void *)a, (void *)((u8 *)data_02138e4c + 0x2292), 6);
    }
    if (b == 0 || b == data_020ea760) {
        func_02008048((void *)data_020ea760, (void *)((u8 *)data_02138e4c + 0x229c), 0x20);
        M2C_FIELD((void *)data_02138e4c, u16 *, 0x229a) = 0;
    } else {
        func_02008048((void *)b, (void *)((u8 *)data_02138e4c + 0x229c), 0x20);
        i = 0;
        if (r4[0] != 0) {
            for (;;) {
                i++;
                if (i >= 0x20) {
                    r4++;
                    break;
                }
                r4++;
                if (r4[0] == 0) break;
            }
        }
        M2C_FIELD((void *)data_02138e4c, u16 *, 0x229a) = (u16)i;
    }
    M2C_FIELD((void *)data_02138e4c, u32 *, 0x2284) = 0;
}

void func_02028018(void){M2C_FIELD((void *)data_02138e4c,u32 *,0x2264)=0xaaa082;}

