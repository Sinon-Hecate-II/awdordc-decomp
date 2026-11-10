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
void func_0200673c(void); void func_02006748(void); void func_02006804(void); void func_02006810(void); s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
s32 state;
u32 start;
void *dst;
s32 size;
u32 start2;
void *dst2;
s32 size2;
s32 diff;
u32 base;
base=*(u32*)0x27ffc2c;
if(base>=0x8000) func_01ff83a8(base,(void*)0x27ffe00,0x160);
start=*(u32*)0x27ffe20; dst=*(void**)0x27ffe28; size=*(s32*)0x27ffe2c; start2=*(s32*)0x27ffe30; dst2=*(void**)0x27ffe38; size2=*(s32*)0x27ffe3c;
state=OS_DisableInterrupts(); func_02006748(); func_0200673c(); OS_RestoreInterrupts(state); func_02006810(); func_02006804();
start+=base;
if(start<0x8000) { diff=0x8000-start; dst=(u8*)dst+diff; size-=diff; start=0x8000; }
func_01ff83a8(start,dst,size);
return func_01ff83a8(start2+base,dst2,size2);
}

int func_01ff83a8(unsigned int addr, void *dst, int size)
{
    unsigned int control;
    unsigned int status;
    unsigned int addressHigh;
    unsigned int value;
    int offset;

    volatile unsigned char *regs;
    volatile unsigned int *romdata;

    control = *(volatile unsigned int *)0x027FFE60;
    offset = -(int)(addr & 0x1FF);
    control = (control & ~0x07000000U) | 0xA1000000U;

    if ((*(volatile unsigned int *)0x040001A4 & 0x80000000U) != 0)
        return addr;

    regs = (volatile unsigned char *)0x040001A1;
    regs[0] = 0x80;

    addr += offset;

    if (offset >= size)
        return addr;

    romdata = (volatile unsigned int *)0x04100010;

    addressHigh = addr >> 8;

    do {
        regs[7] = 0xB7;
        regs[8] = (unsigned char)(addr >> 24);
        regs[9] = (unsigned char)(addr >> 16);
        regs[10] = (unsigned char)addressHigh;
        regs[11] = (unsigned char)addr;
        regs[12] = 0;
        regs[13] = 0;
        regs[14] = 0;

        *(volatile unsigned int *)(regs + 3) = control;

        do {
            status = *(volatile unsigned int *)(regs + 3);

            if (status & 0x00800000U) {
                value = *romdata;

                if (offset >= 0 && offset < size)
                    *(unsigned int *)((unsigned char *)dst + offset) = value;

                offset += 4;
            }
        } while (status & 0x80000000U);

        addressHigh += 2;
        addr += 0x200;

    } while (offset < size);

    return addr;
}

void func_01ff8480(s32 a,s32 b,s32 c,s32 d) {
 s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
 s32 state=OS_DisableInterrupts();
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
 OS_RestoreInterrupts(state);
}

void func_01ff84c0(s32 a,s32 b,s32 c,s32 d) {
 s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
 s32 state=OS_DisableInterrupts();
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
 (void)*(volatile u32 *)0x40000b0;
 (void)*(volatile u32 *)0x40000b0;
 if(a==0){p[0]=0;p[1]=0;p[2]=0x81400001;}
 OS_RestoreInterrupts(state);
}

void func_01ff8530(s32 a,s32 b,s32 c,s32 d) {
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
}

#pragma optimization_level 2
void func_01ff8554(s32 a, s32 b, s32 c, s32 d) {
    volatile u32 *p = (volatile u32 *)(0x40000b0 + a * 12);
    p[0] = b;
    p[1] = c;
    p[2] = d;
    (void)*(volatile u32 *)0x40000b0;
    (void)*(volatile u32 *)0x40000b0;
    if (a == 0) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0x81400001;
    }
    (void)*(volatile u32 *)0x40000b0;
    (void)*(volatile u32 *)0x40000b0;
}
void func_01ff85b8(u16 *p,s32 size,s32 add){u16 n=size>>1;u16 *q;u16 v;if(!n)return;do{q=p;v=*p++;*q=v+add;n--;}while(n);}

void func_01ff85ec(void) {
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x48) = 0;
    M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x4A) = 0;
    func_02007e98(0xC0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x34), 0x400);
}

void func_01ff8624(s32 start, s32 end) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain;
    void *base;
    u16 *dst;
    s32 limit, i, n, a, b, c, j;
    u8 same;
    n = M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a);
    same = gCur3DSpriteEngine == g3DSpriteEngineMain;
    if (same == 1) base = (void *)0x7000000; else base = (void *)0x7000400;
    limit = 0x80 - start;
    if (n > limit) n = limit;
    dst = (u16 *)((u8 *)base + start * 8);
    i = 0;
    if (n > 0) {
        a = 0; b = 1; c = 2;
        do {
            dst[0] = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0x38)[a];
            i++;
            dst[1] = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0x38)[b];
            dst[2] = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0x38)[c];
            a += 4; b += 4; c += 4;
            dst += 4;
        } while (i < n);
    }
    j = n;
    if (n < end) {
        do {
            dst[0] = 0xc0; dst[1] = 0; dst[2] = 0;
            j++;
            dst += 4;
        } while (j < end);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4b) = start;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4c) = n;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a) = 0;
}

void func_01ff873c(void) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    void func_02007ef4(void *, void *, s32);
    void func_01ff8624(s32, s32);
    void func_01ff85ec(void);
    void *saved = gCur3DSpriteEngine;
    void *p;
    void *dest;
    s32 i = 0;
    u8 same;
    do {
        p = i == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        same = p == g3DSpriteEngineMain;
        gCur3DSpriteEngine = p;
        if (same == 1) {
            dest = (void *)0x7000000;
        } else {
            dest = (void *)0x7000400;
        }
        func_02007ef4(M2C_FIELD(p, void **, 0x34), dest, 0x400);
        func_01ff8624(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48), 0);
        func_01ff85ec();
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
}

void func_01ff87e4(void){extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;void func_01ff8624(s32,s32);void *saved=gCur3DSpriteEngine;void *p;s32 i=0;do{p=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;gCur3DSpriteEngine=p;func_01ff8624(M2C_FIELD(p,u8 *,0x4b),M2C_FIELD(p,u8 *,0x4c));i++;}while(i<2);gCur3DSpriteEngine=saved;}

/* Draw a run of sprites from src into the current 3D sprite engine bank. */
void func_01ff883c(s32 x, s32 y, s32 attr, u16 *src) {
    extern void *gCur3DSpriteEngine;
    u16 *dst;
    s32 count;
    s32 lo, hi, mask = 0x3ff, xmask;
    s32 a, b, c, shift, ay, ax, ah, bh, ch, cl;
    u16 *base;
    void *engine;
    u8 n;

    count = *src++;
    engine = gCur3DSpriteEngine;
    base = M2C_FIELD(engine, u16 * volatile *, 0x34);
    n = M2C_FIELD(engine, volatile u8 *, 0x48);
    dst = base + n * 4;
    if (!count) {
        return;
    }
    hi = attr & 0xfc00;
    lo = attr & mask;
    xmask = mask - 0x200;
    do {
        if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48) >= 128) {
            return;
        }
        a = src[0];
        dst[0] = ((a | y) & 0xff00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3e) + (a + y)) & 255);
        b = src[1];
        dst[1] = ((b | x) & 0xfe00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (b + x)) & xmask);
        c = src[2];
        src += 3;
        shift = (u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30;
        dst[2] = (c & 0xfc00) + ((lo + (((c & mask) >> shift) & mask)) & mask) + hi;
        dst += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48)++;
    } while (--count);
}

#pragma optimization_level 2
void func_01ff8930(s32 x, s32 y, s32 xoffs, s32 yoffs, u16 attr, u16 *src) {
    extern void *gCur3DSpriteEngine;
    u16 *dst;
    s32 count;
    s32 lo, hi;
    s32 a, b, c, shift;
    s32 ypos;
    u16 *base;
    void *engine;
    u8 n;

    count = *src++;
    engine = gCur3DSpriteEngine;
    base = M2C_FIELD(engine, u16 * volatile *, 0x34);
    n = M2C_FIELD(engine, volatile u8 *, 0x48);
    dst = base + n * 4;
    if (!count) {
        return;
    }
    ypos = y + (s8)yoffs;
    lo = attr & 0x3ff;
    hi = attr & 0xfc00;
    do {
        if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48) >= 0x80) return;
        a = src[0];
        if (ypos + (s8)a <= -64 || ypos + (s8)a > 0xc0) {
            src += 3;
            count--;
            continue;
        }
        dst[0] = ((a | yoffs) & 0xff00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3e) + (y + (a + yoffs))) & 255);
        b = src[1];
        count--;
        dst[1] = ((b | xoffs) & 0xfe00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (x + (b + xoffs))) & ((u32)-64 >> 23));
        c = src[2];
        src += 3;
        shift = (u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30;
        dst[2] = (c & 0xfc00) + ((lo + (((c & 0x3ff) >> shift) & 0x3ff)) & 0x3ff) + hi;
        dst += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48)++;
    } while (count);
}
#pragma optimization_level 4
void func_01ff8a8c(s32 x, s32 y, u32 attr, u16 *src) {
    extern void *gCur3DSpriteEngine;
    extern u8 data_02101f94[];
    u16 *dst;
    s32 count;
    s32 lo, hi, mask = 0x3ff, xmask;
    u16 *base;
    void *engine;
    u8 n;
    s32 i;

    count = *src++;
    engine = gCur3DSpriteEngine;
    base = M2C_FIELD(engine, u16 * volatile *, 0x34);
    n = M2C_FIELD(engine, volatile u8 *, 0x48);
    dst = base + n * 4;
    if (!count) {
        return;
    }
    hi = attr & 0xfc00;
    lo = attr & mask;
    xmask = mask - 0x200;

    do {

        s32 b,c;
        u8 orient0,orient1;
        s32 index;
        s32 field3e;
        s32 field3c;
        s16 part;
        s32 shift;
        s32 val;

if(M2C_FIELD(gCur3DSpriteEngine,u8 *,0x48)>=128)return;
        engine = gCur3DSpriteEngine;
        field3e = M2C_FIELD(engine, s16 *, 0x3e);

        orient0=(src[1]>>14)&255;
orient1=(src[0]>>14)&255;
        dst[0] = ((src[0] | y) & 0xff00) + ((field3e + (src[0] + y)) & 0xff);

        b = src[1];
        
        index = orient0 + (orient1 << 2);

        part = b & xmask;
        if (part & 0x100) {
            part |= 0xfe00;
        }
        part = -part;
        part = part - data_02101f94[index * 2];

        engine = gCur3DSpriteEngine;
        field3c = M2C_FIELD(engine, s16 *, 0x3c);
        val = field3c + (x + part);
        dst[1] = ((b | x) & 0xfe00) + (val & xmask);

        if (src[1] & 0x1000) {
            dst[1] = dst[1] & ~0x1000;
        } else {
            dst[1] = dst[1] | 0x1000;
        }

        c = src[2];
        src += 3;

        engine = gCur3DSpriteEngine;
        shift = (u32)((*(u16 *)M2C_FIELD(engine, void **, 0)) << 17) >> 30;
        engine = gCur3DSpriteEngine;
        {
            s32 loval = (c & mask) >> shift;
            loval = loval & mask;
            loval = (lo + loval) & mask;
            dst[2] = (c & 0xfc00) + loval + hi;
        }

        dst += 4;
        engine = gCur3DSpriteEngine;
        M2C_FIELD(engine, u8 *, 0x48)++;
    } while (--count);
}

void func_01ff8c0c(s32 p0, s32 p1, s32 p2, s32 p3, u16 p4, u16 *p5) {
    extern void *gCur3DSpriteEngine;
    extern u8 data_02101f94[];
    u16 *dst;
    s32 count;
    s32 lo, hi, mask = 0x3ff;
    u16 *base;
    u8 n;
    s32 ypos;
    s32 limit = -64;

    count = *p5++;
    base = M2C_FIELD(gCur3DSpriteEngine, u16 * volatile *, 0x34);
    n = M2C_FIELD(gCur3DSpriteEngine, volatile u8 *, 0x48);
    dst = base + n * 4;
    if (!count) return;
    ypos = p1 + (s8)p3;
    hi = p4 & 0xfc00;
    lo = p4 & mask;
    if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48) >= 0x80) return;
    do {
        u16 a;
        s32 b, c;
        u8 orient0, orient1;
        s32 index;
        s32 field3e;
        s16 part;
        s32 shift, val;
        a = p5[0];
        if (ypos + (s8)a <= limit || ypos + (s8)a > 0xc0) {
            p5 += 3;
            count--;
            continue;
        }
        orient1 = (a >> 14) & 255;
        field3e = M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3e);
        dst[0] = ((a | p3) & 0xff00) + ((field3e + (p1 + (a + p3))) & 0xff);
        b = p5[1];
        orient0 = (b >> 14) & 255;
        index = orient0 + (orient1 << 2);
        part = b & 0x1ff;
        if (part & 0x100) part |= 0xfe00;
        part = -part;
        part = part - data_02101f94[index * 2];
        val = M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (p0 + (p2 + part));
        dst[1] = ((b | p2) & 0xfe00) + (val & 0x1ff);
        if (p5[1] & 0x1000) dst[1] = dst[1] & ~0x1000;
        else dst[1] = dst[1] | 0x1000;
        c = p5[2];
        p5 += 3;
        shift = ((u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0)) << 17) >> 30;
        {
            s32 loval = (c & mask) >> shift;
            loval = loval & mask;
            loval = (lo + loval) & mask;
            dst[2] = (c & 0xfc00) + loval + hi;
        }
        dst += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48)++;
        count--;
    } while (count);
}

void SetSpriteQuad(s32 a,s16 b,s16 c,s16 d,s16 e) {
 extern void *gCur3DSpriteEngine;
 s32 n=a*16;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+3]=b;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+7]=c;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+11]=d;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+15]=e;
}

void *func_01ff8e44(s32 a, s32 b) {
    extern u8 gSpriteDesc8x8[8];
    extern u8 data_027e006c[8];
    extern u8 data_027e009c[8];
    extern u8 gSpriteDesc16x8[8];
    extern u8 data_027e0064[8];
    extern u8 data_027e0074[8];
    extern u8 data_027e007c[8];
    extern u8 gSpriteDesc32x16[8];
    extern u8 data_027e00ac[8];
    extern u8 data_027e0094[8];
    extern u8 data_027e00b4[8];
    extern u8 data_027e008c[8];

    switch (a) {
    case 0x08:
        switch (b) {
        case 0x08: return gSpriteDesc8x8;
        case 0x10: return data_027e006c;
        case 0x20: return data_027e009c;
        }
        break;
    case 0x10:
        switch (b) {
        case 0x08: return gSpriteDesc16x8;
        case 0x10: return data_027e0064;
        case 0x20: return data_027e0074;
        }
        break;
    case 0x20:
        switch (b) {
        case 0x08: return data_027e007c;
        case 0x10: return gSpriteDesc32x16;
        case 0x20: return data_027e00ac;
        case 0x40: return data_027e0094;
        }
        break;
    case 0x40:
        switch (b) {
        case 0x20: return data_027e00b4;
        case 0x40: return data_027e008c;
        }
        break;
    }
    return 0;
}

