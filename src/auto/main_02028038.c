/* 17 functions from 0x02028038 to 0x02028EF4 (main), found by ds-decomp. */
#include "common.h"
typedef struct CallbackArgs_0202810c { s16 a,b; s32 c,d,e; } CallbackArgs_0202810c;
typedef struct State_02028038 { u8 pad[0x260]; s32 state; u32 bits; u8 pad268[0x14]; void (*callback)(CallbackArgs_0202810c *); } State_02028038;

#pragma opt_common_subs off
u16 func_02028038(s32 a){
extern void *data_02138e4c;
s32 i,b,bits,rem;void *p=data_02138e4c;
i=0;b=a;bits=M2C_FIELD(p,u32*,0x2264);do{rem=b%13;if(bits&(1<<(rem+1)))break;i++;b++;}while(i<13);
rem=(a+i)%13;return rem+1;
}
#pragma opt_common_subs on
void func_020280c8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_0202810c(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern void *data_02138e4c;
    s16 temp_r0;

    temp_r0 = M2C_FIELD(data_02138e4c, s16 *, 0x2280);
    M2C_FIELD(data_02138e4c, s16 *, 0x2280) = 0;
    func_0202810c(temp_r0, arg0, arg1, arg2, arg3);
}

M2C_UNK func_0202810c(s16 a,s32 b,s32 c,s32 d,s32 e){
 extern void *data_02138e4c;
 CallbackArgs_0202810c args;
 if(!M2C_FIELD((u8 *)data_02138e4c+0x2000,void (**)(CallbackArgs_0202810c *),0x27c))return;
 args.a=a;args.c=c;args.d=d;args.e=e;args.b=b;
 M2C_FIELD((u8 *)data_02138e4c+0x2000,void (**)(CallbackArgs_0202810c *),0x27c)(&args);
}

#pragma opt_common_subs off
void func_02028160(s32 a){void func_0202826c(void);s32 func_0200751c(void);void func_02007530(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);extern void *data_02138e4c;s32 old=func_0200751c();void *p;if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==9&&a!=9)func_02007338((u8 *)data_02138e4c+0x22cc);p=(u8 *)data_02138e4c+0x2000;if(M2C_FIELD(p,s32 *,0x260)!=11)M2C_FIELD(p,s32 *,0x260)=a;if(a==9)func_020072cc((u8 *)data_02138e4c+0x22cc,0x22f5341,0,func_0202826c,0);func_02007530(old);}
#pragma opt_common_subs on
M2C_UNK func_020281f8(void){void func_0202826c(void);extern void *data_02138e4c;s32 func_0200751c(void);void func_02007530(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);s32 old=func_0200751c();func_02007338((u8 *)data_02138e4c+0x22cc);if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==9)func_020072cc((u8 *)data_02138e4c+0x22cc,0x22f5341,0,func_0202826c,0);func_02007530(old);}

void func_0202826c(void) {
    M2C_UNK func_020281f8();
    M2C_UNK func_02029714();
    func_02029714();
    func_020281f8();
}

u32 func_0202827c(u32 a){s32 __cntlzw(u32);u32 n=0;s32 bit;for(;;){bit=31-__cntlzw(a);if(bit<0)return n;a&=~(1U<<bit);n++;}}

s32 func_020282a8(u32 arg0) {
    return __builtin_clz(arg0);
}

#pragma optimization_level 2
void func_020282b0(void){extern void *data_02138e4c; void func_02028ef4(void);s32 func_02012274(void (*)(void));u8 *p=(u8 *)data_02138e4c+0x2000;if(p[0x26b])return;p[0x26b]=1;if(func_02012274(func_02028ef4)==2)return;func_02028160(11);func_020280c8(7,0,0,0x610);}
#pragma optimization_level reset
void func_0202830c(u16 *p){extern void *data_02138e4c;if(p[1]!=8||p[2]!=22||p[3]!=37)return;switch(M2C_FIELD(data_02138e4c,s32 *,0x2260)){case 8:func_02028160(12);return;case 9:case 12:func_020282b0();return;case 10:func_02028160(12);return;}}

void func_02028384(void *arg0) {
    void func_02028160(s32);
    void func_020280c8(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_02011244(void);
    s32 func_02012158(void *);
    s32 func_02012198(void *);
    s32 func_02013cfc(void *, s32);
    s32 func_02013bc8(void *, s32, s32, void *);
    extern void *data_02138e4c;

    u16 r0v = ((u16 *)arg0)[0];
    u16 v1 = ((u16 *)arg0)[1];
    s32 r2 = 0x14;

    switch (v1) {
    case 0: {
        if (r0v == 0x19) {
            void *base = data_02138e4c;
            u8 b0 = M2C_FIELD((u8 *)base + 0x2000, u8 *, 0x250);
            u8 b1 = M2C_FIELD((u8 *)base + 0x2000, u8 *, 0x251);
            void *p3 = (u8 *)base + 0x2200;
            r2 = func_02013bc8(func_02028384, b0, b1, p3);
        } else if (r0v > 0x19) {
            if (r0v == 0x1d) {
                r2 = func_02013cfc(func_02028384, 0);
            } else if (r0v == 0x27) {
                r2 = func_02012198(func_02028384);
            }
        } else {
            if (r0v == 4) {
                if (func_02011244() == 0) {
                    func_02028160(1);
                    func_020280c8(0, 0, 0, 0x663);
                    return;
                } else {
                    func_02028160(11);
                    func_020280c8(7, 0, 0, 0x66c);
                    return;
                }
            } else if (r0v == 5) {
                func_02028160(3);
                func_020280c8(0, 0, 0, 0x673);
                return;
            } else if (r0v == 6) {
                r2 = func_02012158(func_02028384);
            }
        }
        break;
    }
    case 1: {
        func_02028160(11);
        {
            void *base = data_02138e4c;
            s16 st = M2C_FIELD(base, s16 *, 0x2280);
            M2C_UNK r1 = (st == 5) ? (u8 *)base + 0x2140 : 0;
            func_020280c8(7, r1, 0, 0x6e8);
        }
        return;
    }
    default: {
        func_02028160(12);
        {
            void *base = data_02138e4c;
            s16 st = M2C_FIELD(base, s16 *, 0x2280);
            M2C_UNK r1 = (st == 5) ? (u8 *)base + 0x2140 : 0;
            func_020280c8(1, r1, 0, 0x6de);
        }
        return;
    }
    }

    if (r2 == 2) {
        return;
    }
    if (r2 == 3) {
        /* fall through to L53c */
    } else if (r2 == 8) {
        func_02028160(12);
        {
            void *base = data_02138e4c;
            s16 st = M2C_FIELD(base, s16 *, 0x2280);
            M2C_UNK r1 = (st == 5) ? (u8 *)base + 0x2140 : 0;
            func_020280c8(1, r1, 0, 0x6af);
        }
        return;
    }
    /* L53c */
    func_02028160(11);
    {
        void *base = data_02138e4c;
        s16 st = M2C_FIELD(base, s16 *, 0x2280);
        M2C_UNK r1 = (st == 5) ? (u8 *)base + 0x2140 : 0;
        func_020280c8(7, r1, 0, 0x6b8);
    }
}

void func_02028640(void) { }

void func_02028924(u16 *p){switch(p[1]){case 0:func_02028160(3);func_020280c8(0,0,0,0x783);return;case 1:func_020282b0();return;case 2:case 3:case 4:default:func_02028160(11);func_020280c8(7,0,0,0x793);return;}}

void func_02028c00(u16 *p) {
    extern void *data_02138e4c;
    switch (p[1]) {
    case 0:
        if (M2C_FIELD(data_02138e4c, s32 *, 0x2260) == 0xc) {
            func_02028160(0xa);
            func_020282b0();
            return;
        }
        M2C_FIELD(data_02138e4c, u16 *, 0x2282) = 0;
        func_02028160(3);
        func_020280c8(0, (u8 *)data_02138e4c + 0x2140, 0, 0x83d);
        return;
    case 1:
    case 3:
        func_02028160(0xa);
        func_020282b0();
        return;
    case 2:
    case 4:
    default:
        func_02028160(0xb);
        func_020280c8(7, (u8 *)data_02138e4c + 0x2140, 0, 0x84f);
        return;
    }
}

void func_02028cc8(u16 *p) {
    extern void *data_02138e4c;
    void func_02028160(s32);
    void func_020280c8(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void func_020282b0(void);
    void func_02029bd0(M2C_UNK);
    void func_020067a8(M2C_UNK, M2C_UNK);
    void func_020296e0(M2C_UNK);

    if (p[1] == 4) {
        func_02028160(0xb);
        func_020280c8(7, (u8 *)data_02138e4c + 0x2140, 0, 0x88c);
        return;
    }
    if (p[2] == 0xe) {
        if (M2C_FIELD(data_02138e4c, s32 *, 0x2260) == 0xc) {
            func_02028160(0x8);
            func_020282b0();
            return;
        }
        func_02028160(0x9);
        func_020280c8(0, (u8 *)data_02138e4c + 0x2140, 0, 0x872);
        return;
    }
    if (p[2] == 0xf) {
        void *u = *(void **)((u8 *)p + 8);
        u16 w = *(u16 *)((u8 *)u + 0xe);
        func_02029bd0((w >> 8) & 0xff);
        func_020067a8(u, 0x620);
        func_020296e0(u);
        return;
    }
    func_02028160(0xb);
    func_020280c8(7, (u8 *)data_02138e4c + 0x2140, p[2], 0x881);
    return;
}

void func_02028c00(u16 *);
void func_02028dd8(u16 *p) {
extern void *data_02138e4c;
switch(p[1]){
case 0:
if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==12){func_02028160(10);func_020282b0();return;}
switch(func_0201280c(func_02028c00,0)){
case 2:return;
case 8:func_02028160(12);func_020280c8(1,(u8 *)data_02138e4c+0x2140,0,0x8b4);return;
case 3:func_02028160(10);func_020282b0();return;
default:func_02028160(11);func_020280c8(7,(u8 *)data_02138e4c+0x2140,0,0x8c0);return;
}
case 1:case 3:func_02028160(10);func_020282b0();return;
case 2:case 4:default:func_02028160(11);func_020280c8(7,(u8 *)data_02138e4c+0x2140,0,0x8d3);return;
}
}

