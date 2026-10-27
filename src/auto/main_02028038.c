/* 17 functions from 0x02028038 to 0x02028EF4 (main), found by ds-decomp. */
#include "common.h"
typedef struct CallbackArgs_0202810c { s16 a,b; s32 c,d,e; } CallbackArgs_0202810c;
typedef struct State_02028038 { u8 pad[0x260]; s32 state; u32 bits; u8 pad268[0x14]; void (*callback)(CallbackArgs_0202810c *); } State_02028038;

u16 func_02028038(s32 a){extern void *data_02138e4c;s32 bits=M2C_FIELD(data_02138e4c,u32 *,0x2264);s32 b=a,i;for(i=0;i<13;i++,b++){if(bits&(1<<(b%13+1)))break;}return (a+i)%13+1;}

void func_020280c8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_0202810c(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern void *data_02138e4c;
    s16 temp_r0;

    temp_r0 = M2C_FIELD(data_02138e4c, s16 *, 0x2280);
    M2C_FIELD(data_02138e4c, s16 *, 0x2280) = 0;
    func_0202810c(temp_r0, arg0, arg1, arg2, arg3);
}

M2C_UNK func_0202810c(s16 a,s32 b,s32 c,s32 d,s32 e){extern void *data_02138e4c;State_02028038 *p=(State_02028038 *)((u8 *)data_02138e4c+0x2000);CallbackArgs_0202810c args;if(!p->callback)return;args.a=a;args.c=c;args.d=d;args.e=e;args.b=b;p->callback(&args);}

void func_02028160(s32 a){void func_0202826c(void);s32 func_0200751c(void);void func_02007530(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);extern void *data_02138e4c;s32 old=func_0200751c();State_02028038 *p;s32 state;if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==9&&a!=9)func_02007338((u8 *)data_02138e4c+0x22cc);p=(State_02028038 *)data_02138e4c;p=(State_02028038 *)((u8 *)p+0x2000);if(p->state!=11)p->state=a;if(a==9)func_020072cc((u8 *)data_02138e4c+0x22cc,0x22f5341,0,func_0202826c,0);func_02007530(old);}

M2C_UNK func_020281f8(void){void func_0202826c(void);extern void *data_02138e4c;s32 func_0200751c(void);void func_02007530(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);s32 old=func_0200751c();func_02007338((u8 *)data_02138e4c+0x22cc);if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==9)func_020072cc((u8 *)data_02138e4c+0x22cc,0x22f5341,0,func_0202826c,0);func_02007530(old);}

void func_0202826c(void) {
    M2C_UNK func_020281f8();
    M2C_UNK func_02029714();
    func_02029714();
    func_020281f8();
}

u32 func_0202827c(u32 a){s32 __cntlzw(u32);u32 n=0;s32 bit;for(;;){bit=31-__cntlzw(a);if(bit<0)return n;a&=~(1U<<bit);n++;}}

void func_020282b0(void){extern void *data_02138e4c; void func_02028ef4(void);s32 func_02012274(void (*)(void));volatile u8 *p=(u8 *)data_02138e4c+0x2000;if(p[0x26b])return;p[0x26b]=1;if(func_02012274(func_02028ef4)==2)return;func_02028160(11);func_020280c8(7,0,0,0x610);}

void func_0202830c(u16 *p){extern void *data_02138e4c;if(p[1]!=8||p[2]!=22||p[3]!=37)return;switch(M2C_FIELD(data_02138e4c,s32 *,0x2260)){case 8:func_02028160(12);return;case 9:case 12:func_020282b0();return;case 10:func_02028160(12);return;}}

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

