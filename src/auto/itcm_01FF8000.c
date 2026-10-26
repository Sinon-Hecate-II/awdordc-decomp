/* 22 functions from 0x01FF8000 to 0x01FF8F90 (itcm), found by ds-decomp. */
#include "common.h"

void func_01ff8000(void) {
 extern void (*data_027e0000[])(void);
 u32 bits,n=0;
 if(!*(volatile u32 *)0x4000208)return;
 bits=*(volatile u32 *)0x4000210 & *(volatile u32 *)0x4000214;
 if(!bits)return;
 while(bits>>1){bits>>=1;n++;}
 *(volatile u32 *)0x4000214=1u<<n;
 data_027e0000[n]();
}

void func_01ff81e4(void) {
    M2C_UNK func_01ff8300();
    extern volatile u16 data_0212dfe4;
    M2C_UNK func_01ff8218();
    do {

    } while (data_0212dfe4 == 0);
    *(s16 *)0x04000208 = 0;
    func_01ff8300();
    func_01ff8218();
}

void func_01ff82e4(u32 r0, void *r1, u32 r2) {
    u32 *p = r1;
    u32 *end = (u32 *)((u8 *)p + r2);
    if (p < end) {
        do {
            *p++ = r0;
        } while (p < end);
    }
}

s32 func_01ff8300(void) {
    s32 func_01ff83a8(u32, void *, s32);
    void func_0200673c(void);
    void func_02006748(void);
    void func_02006804(void);
    void func_02006810(void);
    s32 func_0200751c(void);
    void func_02007530(s32);

    u32 r4;
    u32 r5;
    void *r6;
    s32 r7;
    s32 r8;
    void *r9;
    s32 r10;
    s32 r11;
    s32 diff;

    r4 = *(u32 *)0x027FFC2C;
    if (r4 >= 0x8000U) {
        func_01ff83a8(r4, (void *)0x027FFC2C + 0x1D4, 0x160);
    }

    r5 = *(u32 *)0x027FFE20;
    r6 = *(void **)((char *)0x027FFE20 + 0x8);
    r7 = *(s32 *)((char *)0x027FFE20 + 0xC);
    r8 = *(s32 *)((char *)0x027FFE20 + 0x10);
    r9 = *(void **)((char *)0x027FFE20 + 0x18);
    r10 = *(s32 *)((char *)0x027FFE20 + 0x1C);

    r11 = func_0200751c();
    func_02006748();
    func_0200673c();
    func_02007530(r11);
    func_02006810();
    func_02006804();

    r5 += r4;
    if (r5 < 0x8000U) {
        diff = 0x8000 - r5;
        r6 = (char *)r6 + diff;
        r7 -= diff;
        r5 = 0x8000;
    }

    func_01ff83a8(r5, r6, r7);
    return func_01ff83a8(r8 + r4, r9, r10);
}

int func_01ff83a8(u32 arg0, void *arg1, s32 arg2) {
    u32 val1;
    u32 mask;
    u32 val3;
    s32 r12;
    volatile u8 *reg_base;
    u32 r9;
    u32 *fifo;
    u32 r8;
    u32 loaded;

    val1 = *(u32 *)0x027FFE60;
    mask = arg0 & 0x1ff;
    val3 = (val1 & ~0x7000000) | 0xa1000000;
    r12 = -(s32)mask;

    if (*(volatile u32 *)0x040001A4 & 0x80000000) {
        return arg0;
    }

    reg_base = (volatile u8 *)0x040001A1;
    reg_base[0] = 0x80;

    if (r12 >= arg2) {
        return arg0 + r12;
    }

    arg0 += r12;
    r9 = arg0 >> 8;
    fifo = (u32 *)0x04100010;
    reg_base[7] = 0xb7;

    do {
        reg_base[8] = (u8)(arg0 >> 24);
        reg_base[9] = (u8)(arg0 >> 16);
        reg_base[10] = (u8)r9;
        reg_base[11] = (u8)arg0;
        reg_base[12] = 0;
        reg_base[13] = 0;
        reg_base[14] = 0;

        *(volatile u32 *)&reg_base[3] = val3;
        r8 = *(volatile u32 *)&reg_base[3];

        if (r8 & 0x00800000) {
            do {
                loaded = *fifo;
                if (r12 >= 0 && r12 < arg2) {
                    *(u32 *)((char *)arg1 + r12) = loaded;
                }
                r12 += 4;
                r8 = *(volatile u32 *)&reg_base[3];
            } while (r8 & 0x80000000);
        }

        if (r12 >= arg2) {
            break;
        }
        r9 += 2;
        arg0 += 0x200;
    } while (1);

    return arg0;
}

void func_01ff8480(s32 a,s32 b,s32 c,s32 d) {
 s32 func_0200751c(void); void func_02007530(s32);
 s32 state=func_0200751c();
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
 func_02007530(state);
}

void func_01ff84c0(s32 a,s32 b,s32 c,s32 d) {
 s32 func_0200751c(void); void func_02007530(s32);
 s32 state=func_0200751c();
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
 (void)*(volatile u32 *)0x40000b0;
 (void)*(volatile u32 *)0x40000b0;
 if(a==0){p[0]=0;p[1]=0;p[2]=0x81400001;}
 func_02007530(state);
}

void func_01ff8530(s32 a,s32 b,s32 c,s32 d) {
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
}

void func_01ff8554(s32 a,s32 b,s32 c,s32 d){volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);p[0]=b;p[1]=c;p[2]=d;(void)*(volatile u32 *)0x40000b0;(void)*(volatile u32 *)0x40000b0;if(!a){p[0]=0;p[1]=0;p[2]=0x81400001;}(void)*(volatile u32 *)0x40000b0;(void)*(volatile u32 *)0x40000b0;}

void func_01ff85b8(u16 *p,s32 size,s32 add){u16 n=size>>1;u16 *q;u16 v;if(!n)return;do{q=p;v=*p++;*q=v+add;n--;}while(n);}

void func_01ff85ec(void) {
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x48) = 0;
    M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x4A) = 0;
    func_02007e98(0xC0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x34), 0x400);
}

void func_01ff873c(void){extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8;void func_02007ef4(void *,void *,s32);void func_01ff8624(s32,s32);void *saved=gCur3DSpriteEngine;void *p;s32 i=0;u8 same;do{p=i==0?data_027e00c8:data_027e00c4;same=p==data_027e00c8;gCur3DSpriteEngine=p;func_02007ef4(M2C_FIELD(p,void **,0x34),(void *)(same==1?0x7000000:0x7000400),0x400);func_01ff8624(M2C_FIELD(gCur3DSpriteEngine,u8 *,0x48),0);func_01ff85ec();i++;}while(i<2);gCur3DSpriteEngine=saved;}

void func_01ff87e4(void){extern void *gCur3DSpriteEngine,*data_027e00c8,*data_027e00c4;void func_01ff8624(s32,s32);void *saved=gCur3DSpriteEngine;void *p;s32 i=0;do{if(i)p=data_027e00c8;else p=data_027e00c4;gCur3DSpriteEngine=p;func_01ff8624(M2C_FIELD(p,u8 *,0x4b),M2C_FIELD(p,u8 *,0x4c));i++;}while(i<2);gCur3DSpriteEngine=saved;}

void func_01ff883c(s32 x,s32 y,s32 attr,u16 *src){
extern void *gCur3DSpriteEngine;
u16 *dst; s32 count; s32 lo,hi,mask=0x3ff,xmask; s32 a,b,c,shift, ay,ax,ah,bh,ch,cl; u16 *base; void *p; u8 n;
count=*src++;
p=gCur3DSpriteEngine;base=M2C_FIELD(p,u16 * volatile *,0x34); n=M2C_FIELD(p,volatile u8 *,0x48);dst=base+n*4;
if(!count)return;
hi=attr&0xfc00;lo=attr&mask;xmask=mask-0x200;
do{
if(M2C_FIELD(gCur3DSpriteEngine,u8 *,0x48)>=128)return;
a=src[0];
dst[0]=((a|y)&0xff00)+((M2C_FIELD(gCur3DSpriteEngine,s16 *,0x3e)+(a+y))&255);
b=src[1];
dst[1]=((b|x)&0xfe00)+((M2C_FIELD(gCur3DSpriteEngine,s16 *,0x3c)+(b+x))&xmask);
c=src[2];src+=3;
shift=(u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)<<17)>>30;
dst[2]=(c&0xfc00)+((lo+(((c&mask)>>shift)&mask))&mask)+hi;
dst+=4;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x48)++;
}while(--count);
}

void func_01ff8ddc(s32 a,s16 b,s16 c,s16 d,s16 e) {
 extern void *gCur3DSpriteEngine;
 s32 n=a*16;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+3]=b;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+7]=c;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+11]=d;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+15]=e;
}

