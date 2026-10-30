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
void func_0200673c(void); void func_02006748(void); void func_02006804(void); void func_02006810(void); s32 func_0200751c(void); void func_02007530(s32);
u32 base,start; void *dst; s32 size,start2; void *dst2; s32 size2,state,diff;
base=*(u32*)0x27ffc2c;
if(base>=0x8000) func_01ff83a8(base,(void*)0x27ffe00,0x160);
start=*(u32*)0x27ffe20; dst=*(void**)0x27ffe28; size=*(s32*)0x27ffe2c; start2=*(s32*)0x27ffe30; dst2=*(void**)0x27ffe38; size2=*(s32*)0x27ffe3c;
state=func_0200751c(); func_02006748(); func_0200673c(); func_02007530(state); func_02006810(); func_02006804();
start+=base;
if(start<0x8000) { diff=0x8000-start; dst=(u8*)dst+diff; size-=diff; start=0x8000; }
func_01ff83a8(start,dst,size);
return func_01ff83a8(start2+base,dst2,size2);
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

void func_01ff8624(s32 start, s32 end) {
    extern void *gCur3DSpriteEngine, *data_027e00c8;
    void *base;
    u16 *dst;
    s32 limit, i, n, a, b, c, j;
    u8 same;
    n = M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a);
    same = gCur3DSpriteEngine == data_027e00c8;
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

void func_01ff873c(void){
extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8;
void func_02007ef4(void *,void *,s32);void func_01ff8624(s32,s32);
void *saved=gCur3DSpriteEngine,*p,*dest; s32 i=0;u8 same;
do{
p=i==0?data_027e00c8:data_027e00c4;
same=p==data_027e00c8;gCur3DSpriteEngine=p;
if(same==1)dest=(void *)0x7000000;else dest=(void *)0x7000400;
func_02007ef4(M2C_FIELD(p,void **,52),dest,1024);
func_01ff8624(M2C_FIELD(gCur3DSpriteEngine,u8 *,72),0);func_01ff85ec();i++;
}while(i<2);gCur3DSpriteEngine=saved;
}

void func_01ff87e4(void){extern void *gCur3DSpriteEngine,*data_027e00c8,*data_027e00c4;void func_01ff8624(s32,s32);void *saved=gCur3DSpriteEngine;void *p;s32 i=0;do{p=i==0?data_027e00c8:data_027e00c4;gCur3DSpriteEngine=p;func_01ff8624(M2C_FIELD(p,u8 *,0x4b),M2C_FIELD(p,u8 *,0x4c));i++;}while(i<2);gCur3DSpriteEngine=saved;}

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

void func_01ff8930(s32 x, s32 y, s32 xoffs, s32 yoffs, u16 attr, u16 *src) {
    extern void *gCur3DSpriteEngine;
    u16 *dst;
    s32 count;
    s32 lo, hi;
    s32 mask = 0x3ff;
    s32 a, b, c, shift;
    u16 *base;
    void *engine;
    u8 n;
    s32 limit = -64;

    count = *src++;
    engine = gCur3DSpriteEngine;
    base = M2C_FIELD(engine, u16 * volatile *, 0x34);
    n = M2C_FIELD(engine, volatile u8 *, 0x48);
    dst = base + n * 4;
    if (!count) {
        return;
    }
    lo = attr & mask;
    hi = attr & 0xfc00;
    if (n >= 0x80) {
        return;
    }
    do {
        a = src[0];
        if (y + (s8)yoffs + (s8)a <= limit || y + (s8)yoffs + (s8)a > 0xc0) {
            src += 3;
            count--;
            continue;
        }
        dst[0] = ((a | yoffs) & 0xff00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3e) + (y + a + yoffs)) & 255);
        b = src[1];
        count--;
        dst[1] = ((b | xoffs) & 0xfe00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (x + b + xoffs)) & ((u32)limit >> 23));
        c = src[2];
        src += 3;
        shift = (u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30;
        dst[2] = (c & 0xfc00) + ((lo + (((c & mask) >> shift) & mask)) & mask) + hi;
        dst += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48)++;
    } while (count);
}

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

    engine = gCur3DSpriteEngine;
    if (M2C_FIELD(engine, u8 *, 0x48) >= 0x80) {
        return;
    }

    do {
        s32 a, b, c;
        s32 orient0, orient1;
        s32 index;
        s32 field3e;
        s32 field3c;
        s32 part;
        s32 shift;
        s32 val;

        engine = gCur3DSpriteEngine;
        field3e = M2C_FIELD(engine, s16 *, 0x3e);

        a = src[0];
        dst[0] = ((a | y) & 0xff00) + ((field3e + (a + y)) & 0xff);

        b = src[1];
        orient0 = (b >> 14) & 0xff;
        orient1 = (a >> 14) & 0xff;
        index = orient0 + (orient1 << 2);

        part = b & 0x1ff;
        if (part & 0x100) {
            part |= 0xfe00;
        }
        part = -part;
        part = part - data_02101f94[index * 2];

        engine = gCur3DSpriteEngine;
        field3c = M2C_FIELD(engine, s16 *, 0x3c);
        val = field3c + x + part;
        dst[1] = ((b | x) & 0xfe00) + (val & xmask);

        if (b & 0x1000) {
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
            u32 loval = (c & mask) >> shift;
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
    void *engine;
    u16 *src;
    u16 count;
    u16 *base;
    u8 idx;
    u16 *rec;
    s32 stack8;
    u16 flags;
    s32 stack4;
    s32 stack0;
    s32 first;
    s16 e3e;
    u8 firstHi;
    u16 u;
    u8 uhi;
    s32 m;
    u8 dv;
    u16 w;
    u16 *field0ptr;
    u16 e0val;
    u32 shift;
    s32 part;
    s32 tmp;

    engine = gCur3DSpriteEngine;
    src = p5;
    count = *src++;
    base = *(u16 **)((u8 *)engine + 0x34);
    idx = *((u8 *)engine + 0x48);
    rec = base + (s32)idx * 4;
    if (count == 0) {
        return;
    }
    stack8 = p1 + ((p3 << 24) >> 24);
    flags = p4;
    stack4 = (s32)(flags & 0x3ff);
    stack0 = (s32)(flags & 0xfc00);

    engine = gCur3DSpriteEngine;
    if (*((u8 *)engine + 0x48) >= 0x80) {
        return;
    }

    while (count != 0) {
        first = (s32)(u16)src[0];
        {
            s32 r7 = stack8 + ((first << 24) >> 24);
            if (r7 > -64 && r7 <= 0xc0) {
                engine = gCur3DSpriteEngine;
                e3e = *(s16 *)((u8 *)engine + 0x3e);
                firstHi = (u8)((first >> 14) & 0xff);
                rec[0] = (u16)(((first | p3) & 0xff00) + (u8)(e3e + p1 + first + p3));

                u = src[1];
                uhi = (u8)((u >> 14) & 0xff);
                m = (s32)(u & 0x1ff);
                if (m & 0x100) {
                    m |= 0xfe00;
                }
                dv = data_02101f94[(uhi + firstHi * 4) << 1];

                m = -m - dv;
                m = (s16)m;
                m = p2 + m;
                m = p0 + m;
                m = *(s16 *)((u8 *)engine + 0x3c) + m;
                m = m & 0x1ff;
                rec[1] = (u16)(((u | (u16)p2) & 0xfe00) + m);

                {
                    u16 tsrc = src[1];
                    u16 rv = rec[1];
                    if (tsrc & 0x1000) {
                        rv = (u16)(rv & ~0x1000);
                    } else {
                        rv = (u16)(rv | 0x1000);
                    }
                    rec[1] = rv;
                }

                w = src[2];
                field0ptr = *(u16 **)((u8 *)engine + 0x00);
                e0val = field0ptr[0];
                shift = ((u32)e0val << 17) >> 30;
                part = 0x3ff & (((s32)(w & dv)) >> (s32)shift);
                tmp = stack4 + part;
                tmp = tmp & 0x3ff;
                tmp = (s32)(w & 0xfc00) + tmp;
                rec[2] = (u16)(stack0 + tmp);

                engine = gCur3DSpriteEngine;
                rec += 4;
                *((u8 *)engine + 0x48) = (u8)(*((u8 *)engine + 0x48) + 1);
            }
        }
        src += 3;
        count--;
    }
}

void func_01ff8ddc(s32 a,s16 b,s16 c,s16 d,s16 e) {
 extern void *gCur3DSpriteEngine;
 s32 n=a*16;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+3]=b;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+7]=c;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+11]=d;
 ((s16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x34))[n+15]=e;
}

void *func_01ff8e44(s32 a, s32 b) {
    extern u8 data_027e0084[8];
    extern u8 data_027e006c[8];
    extern u8 data_027e009c[8];
    extern u8 data_027e00a4[8];
    extern u8 data_027e0064[8];
    extern u8 data_027e0074[8];
    extern u8 data_027e007c[8];
    extern u8 data_027e005c[8];
    extern u8 data_027e00ac[8];
    extern u8 data_027e0094[8];
    extern u8 data_027e00b4[8];
    extern u8 data_027e008c[8];

    switch (a) {
    case 0x08:
        switch (b) {
        case 0x08: return data_027e0084;
        case 0x10: return data_027e006c;
        case 0x20: return data_027e009c;
        }
        break;
    case 0x10:
        switch (b) {
        case 0x08: return data_027e00a4;
        case 0x10: return data_027e0064;
        case 0x20: return data_027e0074;
        }
        break;
    case 0x20:
        switch (b) {
        case 0x08: return data_027e007c;
        case 0x10: return data_027e005c;
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

