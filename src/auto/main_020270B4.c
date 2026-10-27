/* 16 functions from 0x020270B4 to 0x02028038 (main), found by ds-decomp. */
#include "common.h"
extern s32 data_02138e4c;
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

s32 func_02027c84(void){s32 s=func_0200751c();s32 r=0;void *p=(void *)data_02138e4c;if(p)r=M2C_FIELD(p,s32 *,0x2260);func_02007530(s);return r;}

u32 func_02027cb4(u32 arg){u32 old;u32 a=arg;s32 s=func_0200751c();u32 mask=0;void *p=(void *)data_02138e4c;old=M2C_FIELD(p+0x2000,u32 *,0x264);if(!p){func_02007530(s);return 0;}if(a&0x8000){mask|=0x3ffe;if(!(a&0x3ffe))a|=0xa082;}if(a&0x20000)mask|=0x10000;if(a&0x80000)mask|=0x40000;if(a&0x200000)mask|=0x100000;if(a&0x800000)mask|=0x400000;M2C_FIELD(p+0x2000,u32 *,0x264)=a|(old&~mask);func_02007530(s);arg=old;return arg;}

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

void func_02028018(void){M2C_FIELD((void *)data_02138e4c,u32 *,0x2264)=0xaaa082;}

