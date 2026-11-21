/* 22 functions from 0x01FF8000 to 0x01FF8F90 (itcm), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "dma.h"

void func_01ff8000(void) {
 extern void (*gOsArea[])(void);
 u32 bits,n=0;
 if(!*(volatile u32 *)0x4000208)return;
 bits=*(volatile u32 *)0x4000210 & *(volatile u32 *)0x4000214;
 if(!bits)return;
 while(bits>>1){bits>>=1;n++;}
 *(volatile u32 *)0x4000214=1u<<n;
 gOsArea[n]();
}

void func_01ff81e4(void) {
    M2C_UNK LoadCardImage();
    extern volatile u16 data_0212dfe4;
    M2C_UNK func_01ff8218();
    do {

    } while (data_0212dfe4 == 0);
    *(s16 *)0x04000208 = 0;
    LoadCardImage();
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

/* Load a card image into memory: re-read the 0x160-byte image header from card
 * offset 0x027FFC2C when that holds a card address, reset the card and its DMA
 * around the transfer, then load the two blocks the header describes (each a
 * source offset relative to the header, a destination pointer and a size).  A
 * block that starts below CARD_SECURE_AREA_END skips the unreadable part.
 * Returns the address the second read ended at. */
s32 LoadCardImage(void) {
    s32 ReadCardRange(u32, void *, s32);
    void func_0200673c(void);
    void func_02006748(void);
    void func_02006804(void);
    void func_02006810(void);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    u32 cardBase, block0Src;
    void *block0Dst;
    s32 block0Size;
    u32 block1Src;
    void *block1Dst;
    s32 block1Size, irqState, skip;

    cardBase = *(u32 *)0x27ffc2c;
    if (cardBase >= CARD_SECURE_AREA_END)
        ReadCardRange(cardBase, (void *)MB_WINDOW_HEADER_START, MB_WINDOW_HEADER_SIZE);
    block0Src = *(u32 *)0x27ffe20;
    block0Dst = *(void **)0x27ffe28;
    block0Size = *(s32 *)0x27ffe2c;
    block1Src = *(s32 *)0x27ffe30;
    block1Dst = *(void **)0x27ffe38;
    block1Size = *(s32 *)0x27ffe3c;
    irqState = OS_DisableInterrupts();
    func_02006748();
    func_0200673c();
    OS_RestoreInterrupts(irqState);
    func_02006810();
    func_02006804();
    block0Src += cardBase;
    if (block0Src < CARD_SECURE_AREA_END) {
        skip = CARD_SECURE_AREA_END - block0Src;
        block0Dst = (u8 *)block0Dst + skip;
        block0Size -= skip;
        block0Src = CARD_SECURE_AREA_END;
    }
    ReadCardRange(block0Src, block0Dst, block0Size);
    return ReadCardRange(block1Src + cardBase, block1Dst, block1Size);
}

#pragma opt_strength_reduction off
/* Reads `size` bytes of the card at `addr` into `dst` through the card's read
 * command, one page at a time: each command fetches CARD_PAGE_SIZE bytes into the
 * data port and the words are copied out as they become ready.  The read starts
 * a little before the data so that the partial first word of a page is skipped.
 * Returns the address the last command ended at. */
int ReadCardRange(unsigned int addr, void *dst, int size)
{
    unsigned int control;
    unsigned int status;
    unsigned int addressHigh;
    unsigned int value;
    int offset;

    volatile unsigned char *regs;
    volatile unsigned int *romdata;

    control = (*(unsigned int *)CARD_HEADER_CONTROL & ~0x07000000U) | 0xA1000000U;
    offset = -(int)(addr & (CARD_PAGE_SIZE - 1));

    while (*(volatile unsigned int *)CARD_REG_ROMCTRL & 0x80000000U) {}

    regs = (volatile unsigned char *)CARD_REG_COMMAND;
    regs[0] = 0x80;

    addr += offset;

    if (offset >= size)
        return addr;

    romdata = (volatile unsigned int *)CARD_REG_DATA;

    addressHigh = addr >> 8;

    do {
        regs[7] = CARD_READ_OPCODE;
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
                    *(unsigned int *)((unsigned int)dst + offset) = value;

                offset += 4;
            }
        } while (status & 0x80000000U);

        addressHigh += 2;
        addr += CARD_PAGE_SIZE;

    } while (offset < size);

    return addr;
}
#pragma opt_strength_reduction reset
void DmaStartTransferLocked(s32 a,s32 b,s32 c,s32 d) {
 s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
 s32 state=OS_DisableInterrupts();
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
 OS_RestoreInterrupts(state);
}

/* Start a DMA transfer on `channel` with interrupts held off, then flush the
 * channel-0 registers: the two reads of DMA0's source register let the queued
 * register writes settle, and channel 0 is left with the idle transfer. */
void DmaStartTransferLockedFlushed(s32 channel, s32 src, s32 dst, s32 control) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 state = OS_DisableInterrupts();
    volatile u32 *regs = (volatile u32 *)DMA_CHANNEL_BASE(channel);
    regs[0] = src;
    regs[1] = dst;
    regs[2] = control;
    (void)*(volatile u32 *)DMA_CHANNEL_BASE(0);
    (void)*(volatile u32 *)DMA_CHANNEL_BASE(0);
    if (channel == 0) {
        regs[0] = 0;
        regs[1] = 0;
        regs[2] = DMA_CTRL_IDLE_CH0;
    }
    OS_RestoreInterrupts(state);
}

void DmaStartTransfer(s32 a,s32 b,s32 c,s32 d) {
 volatile u32 *p=(volatile u32 *)(0x40000b0+a*12);
 p[0]=b;p[1]=c;p[2]=d;
}

#pragma optimization_level 2
/* Starts a DMA transfer on `channel` and flushes channel 0's registers: channel 0
 * is left in its idle state, and the two reads of DMA0's source register let the
 * queued register writes settle. */
void DmaStartTransferFlushed(s32 channel, s32 src, s32 dst, s32 control) {
    volatile u32 *regs = (volatile u32 *)DMA_CHANNEL_BASE(channel);
    regs[0] = src;
    regs[1] = dst;
    regs[2] = control;
    (void)*(volatile u32 *)DMA_CHANNEL_BASE(0);
    (void)*(volatile u32 *)DMA_CHANNEL_BASE(0);
    if (channel == 0) {
        regs[0] = 0;
        regs[1] = 0;
        regs[2] = DMA_CTRL_IDLE_CH0;
    }
    (void)*(volatile u32 *)DMA_CHANNEL_BASE(0);
    (void)*(volatile u32 *)DMA_CHANNEL_BASE(0);
}
void AddToU16Array(u16 *p,s32 size,s32 add){u16 n=size>>1;u16 *q;u16 v;if(!n)return;do{q=p;v=*p++;*q=v+add;n--;}while(n);}

void Reset3DSpriteOam(void) {
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x48) = 0;
    M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x4A) = 0;
    MI_CpuFill32(0xC0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x34), 0x400);
}

void Write3DSpriteOamEntries(s32 start, s32 end) {
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

/* Upload both 3D sprite engines' OAM to the hardware, main engine first: copy
 * the engine's 0x400-byte OAM shadow to its OAM window, write the quads queued
 * since the last frame and clear the engine for the next one.  The engine that
 * was current when the function was called is current again afterwards. */
void Upload3DSpriteOam(void) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    void MI_CpuCopy32(void *, void *, s32);
    void Write3DSpriteOamEntries(s32, s32);
    void Reset3DSpriteOam(void);
    void *saved = gCur3DSpriteEngine;
    void *engine;
    void *dest;
    s32 i = 0;
    u8 isMain;
    do {
        engine = i == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        isMain = engine == g3DSpriteEngineMain;
        gCur3DSpriteEngine = engine;
        if (isMain == 1) {
            dest = (void *)DS3D_OAM_MAIN;
        } else {
            dest = (void *)DS3D_OAM_SUB;
        }
        MI_CpuCopy32(M2C_FIELD(engine, void **, DS3D_ENGINE_OAM), dest, DS3D_OAM_BYTES);
        Write3DSpriteOamEntries(M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_COUNT), 0);
        Reset3DSpriteOam();
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
}

void func_01ff87e4(void){extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;void Write3DSpriteOamEntries(s32,s32);void *saved=gCur3DSpriteEngine;void *p;s32 i=0;do{p=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;gCur3DSpriteEngine=p;Write3DSpriteOamEntries(M2C_FIELD(p,u8 *,0x4b),M2C_FIELD(p,u8 *,0x4c));i++;}while(i<2);gCur3DSpriteEngine=saved;}

/* Draw a run of sprites from src into the current 3D sprite engine bank. */
void AppendSpriteDescToOam(s32 x, s32 y, s32 attr, u16 *src) {
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
    s32 ypos, lo, hi;
    s32 c, b, a;
    u32 shift;
    u16 *base;
    void *engine;
    u8 n;
    s32 tileMask = 0x3ff;
    s32 topLimit = -64;

    count = *src++;
    engine = gCur3DSpriteEngine;
    base = M2C_FIELD(engine, u16 * volatile *, 0x34);
    n = M2C_FIELD(engine, volatile u8 *, 0x48);
    dst = base + n * 4;
    if (!count) {
        return;
    }
    ypos = y + (s8)yoffs;
    lo = attr & tileMask;
    hi = attr & 0xfc00;
    do {
        if (M2C_FIELD((engine = gCur3DSpriteEngine), u8 *, 0x48) >= 0x80) return;
        a = src[0];
        if (ypos + (s8)a <= topLimit || ypos + (s8)a > 0xc0) {
            src += 3;
            count--;
            continue;
        }
        dst[0] = ((a | yoffs) & 0xff00) + ((M2C_FIELD(engine, s16 *, 0x3e) + (y + (a + yoffs))) & 255);
        b = src[1];
        count--;
        dst[1] = ((b | xoffs) & 0xfe00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (x + (b + xoffs))) & ((u32)topLimit >> 23));
        c = src[2];
        src += 3;
        shift = (u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30;
        dst[2] = (c & 0xfc00) + ((lo + (((c & tileMask) >> shift) & tileMask)) & tileMask) + hi;
        dst += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x48)++;
    } while (count);
}
#pragma optimization_level 4
void func_01ff8a8c(s32 x, s32 y, u32 attr, volatile u16 *src) {
    extern void *gCur3DSpriteEngine;
    extern u8 data_02101f94[];
    u16 *dst;
    s32 count;
    s32 hi, xmask, lo, mask = 0x3ff;
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

        volatile s16 *engineYOffset;
        s32 c, b, a, xFlags, yFlags;
        u8 orient0;
        s32 orient1;
        s32 index;
        s32 field3e;
        s32 field3c;
        s16 part;
        s32 shift;
        s32 val;

if(M2C_FIELD(gCur3DSpriteEngine,u8 *,0x48)>=128)return;
        engine = gCur3DSpriteEngine;
        engineYOffset = (volatile s16 *)((u8 *)engine + 0x3e);
        field3e = *engineYOffset;

        orient0 = (src[1] >> 14) & 255;
        a = src[0];
        orient1 = a >> 14;
        yFlags = a | y;
        dst[0] = (yFlags & 0xff00) + ((field3e + (a + y)) & 0xff);

        b = src[1];
        
        index = orient0 + ((u8)orient1 << 2);

        part = b & xmask;
        if (part & 0x100) {
            part |= 0xfe00;
        }
        part = -part;
        xFlags = (b | x) & 0xfe00;
        part = part - data_02101f94[index * 2];

        engine = gCur3DSpriteEngine;
        field3c = M2C_FIELD(engine, s16 *, 0x3c);
        val = field3c + (x + part);
        dst[1] = xFlags + (val & xmask);

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
    s32 hi, lo;
    s32 mask = 0x3ff;
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
    lo = p4 & mask;
    hi = p4 & 0xfc00;
    do {
        u16 a;
        s32 b, c;
        u8 orient0, orient1;
        s32 index;
        s32 field3e;
        s16 part;
        s32 shift, val;
        void *engine = gCur3DSpriteEngine;
        if (M2C_FIELD(engine, u8 *, 0x48) >= 0x80) return;
        a = p5[0];
        if (ypos + (s8)a <= limit || ypos + (s8)a > 0xc0) {
            p5 += 3;
            count--;
            continue;
        }
        field3e = M2C_FIELD(engine, s16 *, 0x3e);
        orient1 = (a >> 14) & 255;
        b = ((volatile u16 *)p5)[1];
        dst[0] = ((a | p3) & 0xff00) + ((field3e + (p1 + (a + p3))) & 0xff);
        orient0 = (b >> 14) & 255;
        index = orient0 + (orient1 << 2);
        b = ((volatile u16 *)p5)[1];
        part = b & ((u32)limit >> 23);
        if (part & 0x100) part |= 0xfe00;
        part = -part;
        part = part - data_02101f94[index * 2];
        val = M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (p0 + (p2 + part));
        dst[1] = ((b | p2) & 0xfe00) + (val & ((u32)limit >> 23));
        count--;
        if (((volatile u16 *)p5)[1] & 0x1000) dst[1] = dst[1] & ~0x1000;
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
    } while (count);
}

/* Set the four affine matrix parameters (PA, PB, PC, PD) of the sprite quad in
 * OAM slot `slot`: the parameters are the fourth halfword of the four OAM
 * entries the slot's parameter block covers. */
void SetSpriteQuad(s32 slot, s16 pa, s16 pb, s16 pc, s16 pd) {
    extern void *gCur3DSpriteEngine;
    s32 n = slot * 16;
    ((s16 *)DS3D_ENGINE(gCur3DSpriteEngine)->oamEntries)[n + 3] = pa;
    ((s16 *)DS3D_ENGINE(gCur3DSpriteEngine)->oamEntries)[n + 7] = pb;
    ((s16 *)DS3D_ENGINE(gCur3DSpriteEngine)->oamEntries)[n + 11] = pc;
    ((s16 *)DS3D_ENGINE(gCur3DSpriteEngine)->oamEntries)[n + 15] = pd;
}

/* Returns the 3D sprite quad template for a width x height sprite among the
 * fixed OAM size classes (8 to 64 pixels per side), or NULL when the size has
 * no template.  A template is a SpriteQuadTemplate: one quad and its three OAM
 * attribute words. */
void *GetSpriteDescForSize(s32 width, s32 height) {
    extern u8 gSpriteDesc8x8[8];
    extern u8 gSpriteDesc8x16[8];
    extern u8 gSpriteDesc8x32[8];
    extern u8 gSpriteDesc16x8[8];
    extern u8 gSpriteDesc16x16[8];
    extern u8 gSpriteDesc16x32[8];
    extern u8 gSpriteDesc32x8[8];
    extern u8 gSpriteDesc32x16[8];
    extern u8 gSpriteDesc32x32[8];
    extern u8 gSpriteDesc32x64[8];
    extern u8 gSpriteDesc64x32[8];
    extern u8 gSpriteDesc64x64[8];

    switch (width) {
    case 0x08:
        switch (height) {
        case 0x08: return gSpriteDesc8x8;
        case 0x10: return gSpriteDesc8x16;
        case 0x20: return gSpriteDesc8x32;
        }
        break;
    case 0x10:
        switch (height) {
        case 0x08: return gSpriteDesc16x8;
        case 0x10: return gSpriteDesc16x16;
        case 0x20: return gSpriteDesc16x32;
        }
        break;
    case 0x20:
        switch (height) {
        case 0x08: return gSpriteDesc32x8;
        case 0x10: return gSpriteDesc32x16;
        case 0x20: return gSpriteDesc32x32;
        case 0x40: return gSpriteDesc32x64;
        }
        break;
    case 0x40:
        switch (height) {
        case 0x20: return gSpriteDesc64x32;
        case 0x40: return gSpriteDesc64x64;
        }
        break;
    }
    return 0;
}

