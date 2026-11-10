/* 26 functions from 0x020AE768 to 0x020AF760 (main), found by ds-decomp. */
#include "common.h"
static inline u16 SpriteTileSize(s32 n) { return n << 12; }

void func_020ae768(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020ae67c(M2C_UNK, M2C_UNK);
    M2C_UNK func_020ae728(M2C_UNK, M2C_UNK);
    if (arg0 == 1) {
        func_020ae67c(arg1, arg2);
    }
    if (arg0 != 2) {
        return;
    }
    func_020ae728(arg1, arg2);
}

#pragma opt_lifetimes off
void func_020ae7a4(u32 a,u32 b,u16 c) {
extern void *gCur3DSpriteEngine;
u32 offset=a<<5;
u8 *tiles=M2C_FIELD(gCur3DSpriteEngine,u8 **,0x30);
offset &=~1;
a=b<<1;
b=(u32)(tiles+offset);
M2C_FIELD((void *)b,u16 *,a)=c;
}
#pragma opt_lifetimes reset
s32 func_020ae7cc(s32 arg0) {
    extern M2C_UNK data_020f4d30;
    return (0x14 * arg0) + (s32) &data_020f4d30;
}

void func_020ae7e0(void) {
    M2C_UNK func_020ae7ec();
    func_020ae7ec();
}

s32 func_020ae7ec(void) { return 0; }

#pragma opt_common_subs off
void func_020aebb8(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_020e31e0(void);
    M2C_UNK *func_020e3218(M2C_UNK *);
    void func_020675e4(void *, void *, ...);
    void func_0200bc5c(void *);
    void func_02082134(s32, s32);
    void func_020814e4(void *);
    void func_02081590(void *, s32);
    void func_02081578(void *, void *);
    s32 func_01ff9c34(u8, s32);
    void func_01ff85b8(void *, u16, u16);
    void func_02081528(void);
    extern void *gCur3DSpriteEngine;
    extern char data_02127eac[], data_02127eb8[], data_02127ec0[], data_02127ec8[], data_02127ed0[];

    void *r6 = arg0;
    s32 r5 = arg1;
    s32 r4 = arg2;
    char sp100[0x100];
    char sp0[0x100];

    if (func_020e31e0() == 2 && *(u8 *)((char *)r6 + 0x34) == 0) {
        func_020675e4(sp100, func_020e3218(*(void **)(*(void **)((char *)r6 + 0x38))));
    } else {
        func_020675e4(sp100, *(void **)(*(void **)((char *)r6 + 0x38)));
    }
    func_02082134(r5, *(u8 *)((char *)*(void **)((char *)r6 + 0x38) + 4));
    func_0200bc5c(data_02127eac);
    func_020675e4(sp0, data_02127eb8, sp100);
    func_020814e4(sp0);
    func_020675e4(sp0, data_02127ec0, sp100);
    func_02081590(sp0, *(s32 *)((char *)gCur3DSpriteEngine + r5 * 4 + 0xc));
    func_020675e4(sp0, data_02127ec8, sp100);
    func_02081590(sp0, *(s32 *)((char *)gCur3DSpriteEngine + r5 * 4 + 0x20));
    func_020675e4(sp0, data_02127ed0, sp100);
    func_02081578(sp0, (void *)((char *)*(void **)((char *)gCur3DSpriteEngine + 0x30) + (r4 << 5)));
    {
        void *e0 = *(void **)gCur3DSpriteEngine;
        u8 low = (u8)(((u32)(*(u16 *)e0 << 29)) >> 29);
        s32 vv = func_01ff9c34(low, r5);
        s32 sz = SpriteTileSize(r4);
        u16 vv16 = vv;
        u16 sz16 = (u16)(sz & 0xffff);
        void *ptr = *(void **)((char *)gCur3DSpriteEngine + r5 * 4 + 0x20);
        func_01ff85b8(ptr, vv16, sz16);
    }
    func_02081528();
    *(u8 *)((char *)gCur3DSpriteEngine + 0x46) |= 0x10;
    *(u8 *)((char *)gCur3DSpriteEngine + 0x46) |= 1 << r5;
}
#pragma opt_common_subs reset
M2C_UNK func_020aed50(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d, s32 e) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    extern M2C_UNK data_02127e4c, data_02127e40;
    void *func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_020ae7cc(s32);
    /* func_020aebb8 is defined above. */
    void *saved = gCur3DSpriteEngine;
    void *p;
    void *saved2;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    p = func_01ffa3dc(&data_02127e4c, 1);
    if (p) {
        M2C_FIELD(p, void **, 0) = &data_02127e40;
        M2C_FIELD(p, u8 *, 0x34) = e;
        M2C_FIELD(p, s32 *, 0x38) = func_020ae7cc(e);
        M2C_FIELD(p, u8 *, 0x3c) = a;
        M2C_FIELD(p, u8 *, 0x3d) = b;
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x3e) = M2C_FIELD(q, s16 *, 0x10);
        }
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x40) = M2C_FIELD(q, s16 *, 0x12);
        }
        saved2 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        func_020aebb8(p, a, b);
        gCur3DSpriteEngine = saved2;
        M2C_FIELD(p, s16 *, 0x42) = 0;
    }

    gCur3DSpriteEngine = g3DSpriteEngineSub;
    p = func_01ffa3dc(&data_02127e4c, 1);
    if (p) {
        M2C_FIELD(p, void **, 0) = &data_02127e40;
        M2C_FIELD(p, u8 *, 0x34) = e;
        M2C_FIELD(p, s32 *, 0x38) = func_020ae7cc(e);
        M2C_FIELD(p, u8 *, 0x44) = c;
        M2C_FIELD(p, u8 *, 0x45) = d;
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x46) = M2C_FIELD(q, s16 *, 0x10) + M2C_FIELD(q, s16 *, 0x0a);
        }
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x48) = M2C_FIELD(q, s16 *, 0x12) + M2C_FIELD(q, s16 *, 0x0a);
        }
        saved2 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineSub;
        func_020aebb8(p, c, d);
        gCur3DSpriteEngine = saved2;
        M2C_FIELD(p, s16 *, 0x4a) = 0;
    }
    saved2 = (void *)saved2;
    gCur3DSpriteEngine = saved;
}

void func_020aeebc(M2C_UNK a,M2C_UNK b,s32 c) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK data_02127e4c,data_02127e40;
void *func_01ffa3dc(M2C_UNK *,s32);
void *saved=gCur3DSpriteEngine;
void *p;
gCur3DSpriteEngine=g3DSpriteEngineMain;
p=func_01ffa3dc(&data_02127e4c,1);
if(p) {
void *saved2;
M2C_FIELD(p,void **,0)=&data_02127e40;
M2C_FIELD(p,u8 *,0x34)=c;
M2C_FIELD(p,s32 *,0x38)=func_020ae7cc(c);
M2C_FIELD(p,u8 *,0x3c)=a;
M2C_FIELD(p,u8 *,0x3d)=b;
M2C_FIELD(p,s16 *,0x3e)=M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0x10);
M2C_FIELD(p,s16 *,0x40)=M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0x12);
saved2=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
func_020aebb8(p,a,b);
gCur3DSpriteEngine=saved2;
M2C_FIELD(p,s16 *,0x42)=0;
}
gCur3DSpriteEngine=saved;
}

void func_020aef7c(M2C_UNK a,M2C_UNK b,s32 c) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;
extern M2C_UNK data_02127e4c,data_02127e40;
void *func_01ffa3dc(M2C_UNK *,s32);
void *saved=gCur3DSpriteEngine; void *p;
gCur3DSpriteEngine=g3DSpriteEngineSub;
p=func_01ffa3dc(&data_02127e4c,1);
if(p) {void *saved2;
M2C_FIELD(p,void **,0)=&data_02127e40;
M2C_FIELD(p,u8 *,0x34)=c;
M2C_FIELD(p,s32 *,0x38)=func_020ae7cc(c);
M2C_FIELD(p,u8 *,0x44)=a; M2C_FIELD(p,u8 *,0x45)=b;
M2C_FIELD(p,s16 *,0x46)=M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0x10)+M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0xa);
M2C_FIELD(p,s16 *,0x48)=M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0x12)+M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0xa);
saved2=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineSub;
func_020aebb8(p,a,b); gCur3DSpriteEngine=saved2;
M2C_FIELD(p,s16 *,0x4a)=0;
} gCur3DSpriteEngine=saved;
}

void func_020af04c(M2C_UNK a,M2C_UNK b,s32 c) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
void func_020aef7c(M2C_UNK,M2C_UNK,s32);
if((u8)(gCur3DSpriteEngine==g3DSpriteEngineMain))func_020aeebc(a,b,c);
if((u8)(gCur3DSpriteEngine==g3DSpriteEngineSub))func_020aef7c(a,b,c);
}

s32 func_020af0d4(void) {
extern u16 data_02168f14;
switch((u32)(data_02168f14<<29)>>29) {
case 0:return 0;
case 1:return 4;
case 2:return 6;
case 3:return 4;
case 4:case 6:case 7:return 5;
default:return 0;
}
}

void func_020af144(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_020aed50(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_020aed50(arg0, arg1, arg2, arg3, func_020af0d4());
}

void func_020af178(M2C_UNK arg0, M2C_UNK arg1) {
    
    s32 func_020af0d4();
    func_020aeebc(arg0, arg1, func_020af0d4());
}

void func_020af19c(M2C_UNK arg0, M2C_UNK arg1) {
    void func_020aef7c(M2C_UNK, M2C_UNK, s32);
    func_020aef7c(arg0, arg1, func_020af0d4());
}

void func_020af1c0(M2C_UNK arg0, M2C_UNK arg1) {
    
    func_020af04c(arg0, arg1, func_020af0d4());
}

void func_020af1e4(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02127e4c;
    func_01ffa9e4(&data_02127e4c);
}

void func_020af1f8(void) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK data_02127e4c;
M2C_UNK func_01ffa9f8(M2C_UNK *);
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
func_01ffa9f8(&data_02127e4c);
gCur3DSpriteEngine=saved;
}

void func_020af230(void) {
    M2C_UNK func_01ffa9f8(M2C_UNK *);
    extern M2C_UNK data_02127e4c;
    func_01ffa9f8(&data_02127e4c);
}

M2C_UNK func_020af244(void *p) {
    M2C_UNK func_0207c928(M2C_UNK);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    extern M2C_UNK data_027e00bc;

    s32 idx;
    void *base;
    void *dBase;
    s16 *pp = (s16 *)p;
    s16 v;
    u16 w0, w1;
    s32 dx, dy;
    u32 c, value;
    s32 t;

    if (*(void **)gCur3DSpriteEngine == *(void **)g3DSpriteEngineMain) {
        if (pp[0x1D] != 0) {
            if (!func_0207c928(pp[0x21])) {
                idx = ((u8 *)p)[0x34];
                base = *(void **)gCur3DSpriteEngine;
                ((s16 *)base)[idx + 0x1C] = pp[0x1B];
            }
            pp[0x1B] = (s16)(pp[0x1B] + pp[0x1E]);
            if (pp[0x1B] >= 0x100) pp[0x1B] = 0;
        }
        if (pp[0x1F] != 0) {
            if (!func_0207c928(pp[0x21])) {
                idx = ((u8 *)p)[0x34];
                base = *(void **)gCur3DSpriteEngine;
                ((s16 *)base)[idx + 0x20] = pp[0x1C];
            }
            pp[0x1C] = (s16)(pp[0x1C] + pp[0x20]);
            if (pp[0x1C] >= 0x100) pp[0x1C] = 0;
        }
        idx = ((u8 *)p)[0x34];
        base = *(void **)gCur3DSpriteEngine;
        dBase = *(void **)g3DSpriteEngineMain;
        w0 = ((u16 *)base)[idx + 0x1C];
        w1 = ((u16 *)base)[idx + 0x20];
        dx = (s32)w0 - (s32)((s16 *)dBase)[0x1E];
        dy = (s32)w1 - (s32)((s16 *)dBase)[0x1F];
        c = (u32)data_027e00bc;
        value = (c & (u32)dx) | ((c << 16) & (u32)(dy << 16));
        if (idx <= 3) *(u32 *)(0x4000010 + idx * 4) = value;
        pp[0x21] = (s16)(pp[0x21] + 1);
        if (pp[0x21] >= 0x400) pp[0x21] = (s16)(pp[0x21] - 0x400);
    } else {
        if (pp[0x25] != 0) {
            if (!func_0207c928(pp[0x29])) {
                idx = ((u8 *)p)[0x44];
                base = *(void **)gCur3DSpriteEngine;
                ((s16 *)base)[idx + 0x1C] = pp[0x23];
            }
            pp[0x23] = (s16)(pp[0x23] + pp[0x26]);
            if (pp[0x23] >= 0x100) pp[0x23] = 0;
        }
        if (pp[0x27] != 0) {
            if (!func_0207c928(pp[0x29])) {
                idx = ((u8 *)p)[0x44];
                base = *(void **)gCur3DSpriteEngine;
                ((s16 *)base)[idx + 0x20] = pp[0x24];
            }
            pp[0x24] = (s16)(pp[0x24] + pp[0x28]);
            if (pp[0x24] >= 0x100) pp[0x24] = 0;
        }
        idx = ((u8 *)p)[0x44];
        base = *(void **)gCur3DSpriteEngine;
        dBase = *(void **)g3DSpriteEngineMain;
        w0 = ((u16 *)base)[idx + 0x1C];
        w1 = ((u16 *)base)[idx + 0x20];
        dx = (s32)w0 - (s32)((s16 *)dBase)[0x1E];
        dy = (s32)w1 - (s32)((s16 *)dBase)[0x1F];
        c = (u32)g3DSpriteEngineSub;
        value = (c & (u32)dx) | ((c << 16) & (u32)(dy << 16));
        if (idx <= 3) *(u32 *)(0x4001010 + idx * 4) = value;
        pp[0x29] = (s16)(pp[0x29] + 1);
        if (pp[0x29] >= 0x400) pp[0x29] = (s16)(pp[0x29] - 0x400);
    }
    return 0;
}

void func_020af620(void) {
    M2C_UNK func_020af244();
    func_020af244();
}

/* Creates two 3D sprite objects (primary then secondary engine) carrying a pair of 4-value payloads. */
void func_020af62c(s32 a, s32 b, s32 c, s32 d, s16 e, u8 f, s16 g, s16 h, s16 i, s16 j) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    extern M2C_UNK data_02127e7c, data_02127e2c;
    void *func_01ffa3dc(M2C_UNK *, s32);
    void *saved = gCur3DSpriteEngine;
    void *p;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    p = func_01ffa3dc(&data_02127e7c, 1);
    if (p) {
        M2C_FIELD(p, void **, 0) = &data_02127e2c;
        M2C_FIELD(p, u8 *, 0x34) = a;
        M2C_FIELD(p, s16 *, 0x36) = 0;
        M2C_FIELD(p, s16 *, 0x38) = 0;
        M2C_FIELD(p, s16 *, 0x42) = 0;
        M2C_FIELD(p, s16 *, 0x3a) = b;
        M2C_FIELD(p, s16 *, 0x3c) = c;
        M2C_FIELD(p, s16 *, 0x3e) = d;
        M2C_FIELD(p, s16 *, 0x40) = e;
    }

    gCur3DSpriteEngine = g3DSpriteEngineSub;
    p = func_01ffa3dc(&data_02127e7c, 1);
    if (p) {
        M2C_FIELD(p, void **, 0) = &data_02127e2c;
        M2C_FIELD(p, u8 *, 0x44) = f;
        M2C_FIELD(p, s16 *, 0x46) = 0;
        M2C_FIELD(p, s16 *, 0x48) = 0;
        M2C_FIELD(p, s16 *, 0x52) = 0;
        M2C_FIELD(p, s16 *, 0x4a) = g;
        M2C_FIELD(p, s16 *, 0x4c) = h;
        M2C_FIELD(p, s16 *, 0x4e) = i;
        M2C_FIELD(p, s16 *, 0x50) = j;
    }

    gCur3DSpriteEngine = saved;
}

void func_020af71c(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02127e7c;
    func_01ffa9e4(&data_02127e7c);
}

s32 func_020af730(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020af744(void) {

}

s32 func_020af748(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020af75c(void) {

}

