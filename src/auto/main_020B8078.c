/* 20 functions from 0x020B8078 to 0x020B8CCC (main), found by ds-decomp. */
#include "common.h"

extern u8 data_021290b4[40];
extern void *gCur3DSpriteEngine;
extern void *data_027e00c8;
extern u8 data_02129114[12];
extern u8 data_02129120[16];
extern u8 data_02129130[16];
extern u8 data_02129140[16];

void func_020b8078(void *arg0) {
    extern void **gCurrentMap;
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    s32 func_020abe90(M2C_UNK);
    void *func_020b7f58(M2C_UNK);
    void *func_020b7fb8(M2C_UNK);
    void *func_020b8018(M2C_UNK);
    s32 func_020cd1e4();
    s32 func_020cd28c();
    s32 func_020cd2b8();
    s32 func_020cd2f8();
    s32 func_020cd3bc();
    extern M2C_UNK data_0212906c;
    extern M2C_UNK data_02129074;
    extern M2C_UNK data_02129084;
    extern M2C_UNK data_02129094;
    extern M2C_UNK data_021290a4;
    extern M2C_UNK func_020b7c4c;
    extern M2C_UNK func_020b7c5c;
    extern M2C_UNK func_020b7ef0;
    register void *var_r4 asm("r4");
    register u8 var_r5 asm("r5");
    u8 temp_r0;

    var_r4 = NULL;
    var_r5 = (u8) M2C_FIELD(*gCurrentMap, u16 *, 0x52A4);
    if (func_020abe90(3) == 1) {
        return;
    }
    if (func_020cd1e4() != 0) {
        var_r4 = func_020b7f58(arg0);
        var_r5 = (u8) func_020cd2f8();
    } else if (func_020cd28c() != 0) {
        var_r4 = func_020b7fb8(arg0);
        var_r5 = (u8) func_020cd3bc();
    } else if (func_020cd2b8() != 0) {
        var_r4 = func_020b8018(arg0);
    }
    if (var_r4 == NULL) {
        return;
    }
    M2C_FIELD(var_r4, s32 *, 0x34) = 0x80;
    M2C_FIELD(var_r4, s32 *, 0x38) = 0x60;
    M2C_FIELD(var_r4, s32 *, 0x3C) = 0;
    M2C_FIELD(var_r4, s32 *, 0x44) = (s32) (M2C_FIELD(var_r4, s32 *, 0x44) | 0x300000);
    M2C_FIELD(var_r4, M2C_UNK **, 0x68) = &func_020b7c4c;
    M2C_FIELD(var_r4, M2C_UNK **, 0x6C) = &func_020b7c5c;
    M2C_FIELD(var_r4, M2C_UNK **, 0x70) = &func_020b7ef0;
    func_0200bc5c(&data_0212906c);
    temp_r0 = M2C_FIELD(((var_r5 * 0x8C) + (s32) *gCurrentMap), u8 *, 0x67C1);
    switch (temp_r0) {
    case 1:
        func_0208116c(&data_02129074, 0x360, 0x20);
        return;
    case 2:
        func_0208116c(&data_02129084, 0x360, 0x20);
        return;
    case 3:
        func_0208116c(&data_02129094, 0x360, 0x20);
        return;
    case 4:
        func_0208116c(&data_021290a4, 0x360, 0x20);
        return;
    }
    return;
}

void func_020b8208(void *arg0) {
s16 *p=(s16 *)arg0;
p[42]=0; p[41]=4;
}

void func_020b821c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    s8 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s16, s32);
    M2C_UNK func_02082770();
    extern void *data_027e00bc;
    s8 temp_r4;

    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (M2C_FIELD(arg0, s16 *, 0x54) + 1);
    temp_r4 = func_0207ca38(0, 0, 4, M2C_FIELD(arg0, s16 *, 0x54), (s32) M2C_FIELD(arg0, s16 *, 0x52));
    func_02082770();
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) ((M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0xC0) | 0xC0);
    M2C_FIELD(data_027e00bc, s8 *, 0x53) = temp_r4;
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) ((M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~1) | 1);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~2);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~4);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~8);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x10);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x100);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x200);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x400);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x800);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x1000);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x54) < (s32) M2C_FIELD(arg0, s16 *, 0x52)) {
        return;
    }
    func_01ffa574(arg0);
}

void func_020b8338(void *arg0) {
s16 *p=(s16 *)arg0;
p[42]=0; p[41]=2;
}

void func_020b834c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    s8 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s16, s32);
    M2C_UNK func_02082770();
    extern void *data_027e00bc;
    s8 temp_r4;

    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (M2C_FIELD(arg0, s16 *, 0x54) + 1);
    temp_r4 = func_0207ca38(0, 4, 0, M2C_FIELD(arg0, s16 *, 0x54), (s32) M2C_FIELD(arg0, s16 *, 0x52));
    func_02082770();
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) ((M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0xC0) | 0xC0);
    M2C_FIELD(data_027e00bc, s8 *, 0x53) = temp_r4;
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) ((M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~1) | 1);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~2);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~4);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~8);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x10);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x100);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x200);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x400);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x800);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x1000);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x54) < (s32) M2C_FIELD(arg0, s16 *, 0x52)) {
        return;
    }
    func_02082770();
    func_01ffa574(arg0);
}

u8 func_020b846c(M2C_UNK arg0) {
    void *func_020b895c(void);
    s32 func_02086a00(M2C_UNK);
    void *temp_r4;
    temp_r4 = func_020b895c();
    return (func_02086a00(arg0) != 0) || (M2C_FIELD(temp_r4, u8 *, 0x34) != 0);
}

void func_020b8594(s32 arg0) {
    M2C_UNK func_020809c0(s32, M2C_UNK, M2C_UNK);
    void func_020b84a0(s32, s32);
    extern s32 data_0215d84c;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;
    s32 var_r7_2;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    data_0215d84c = 0x124;
    func_020809c0(M2C_FIELD(data_027e00c8, s32 *, 0x24) + 0x140, 0x20, 0xC);
    if (arg0 & 1) {
        var_r5 = 0;
        var_r6 = arg0 >> 1;
        var_r7 = -1;
        do {
            func_020b84a0(var_r7, var_r6);
            var_r5 += 1;
            var_r6 += 1;
            var_r7 += 2;
        } while (var_r5 < 7);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x100, 0x19, 1);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x440, 0x19, 1);
    } else {
        var_r7_2 = 0;
        var_r6_2 = 0;
        var_r5_2 = arg0 >> 1;
        do {
            func_020b84a0(var_r6_2, var_r5_2);
            var_r7_2 += 1;
            var_r5_2 += 1;
            var_r6_2 += 2;
        } while (var_r7_2 < 6);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    gCur3DSpriteEngine = temp_r4;
}

s32 func_020b8694(void *arg0) {
s32 n=M2C_FIELD(arg0,s16 *,0x40);
switch(n) { case 0: return 0; default: M2C_FIELD(arg0,s16 *,0x40)=n-1; return 1; }
}
#pragma optimization_level 4
s16 func_020b86b4(void *arg0) {
    s16 temp_r2;
    temp_r2 = M2C_FIELD(arg0, s16 *, 0x40);
    M2C_FIELD(arg0, s16 *, 0x40) = (s16)(temp_r2 - 6);
    if (M2C_FIELD(arg0, s16 *, 0x40) < 0) {
        M2C_FIELD(arg0, s16 *, 0x40) = 0;
    }
    return (s16)(M2C_FIELD(arg0, s16 *, 0x40) - temp_r2);
}

s32 func_020b86e4(void *arg0) {
    s16 old = M2C_FIELD(arg0, s16 *, 0x40);
    if (old + 6 >= M2C_FIELD(arg0, s16 *, 0x42)) return 0;
    M2C_FIELD(arg0, s16 *, 0x40)++;
    return 1;
}

s16 func_020b870c(void *arg0){
s16 old=M2C_FIELD(arg0,s16*,0x40);s32 max;
M2C_FIELD(arg0,volatile s16*,0x40)=old+6;
max=M2C_FIELD(arg0,volatile s16*,0x42)-6;
if(M2C_FIELD(arg0,s16*,0x40)>max)M2C_FIELD(arg0,s16*,0x40)=max;
return M2C_FIELD(arg0,s16*,0x40)-old;
}

M2C_UNK func_020b8740(void) {
    void *func_020b895c(void);
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b21a0();
    M2C_UNK func_020b2268();
    void *temp_r4;
    temp_r4 = func_020b895c();
    func_0208fe30(0x10018);
    func_01ffa6fc(temp_r4);
    func_020b21a0();
    func_020b2268();
}

void func_020b876c(void) {
    M2C_UNK func_020b8740();
    func_020b8740();
}

void func_020b8778(void) {
    M2C_UNK func_020b8740();
    M2C_UNK func_020ae068();
    func_020ae068();
    func_020b8740();
}

void func_020b8788(u8 *a){void *func_020b895c(void);s32 func_020b20e0(s32);void func_020b1c60(s32);extern u16 *data_02101e84;void *p=func_020b895c();s32 max=M2C_FIELD(p,s16 *,0x42)-6;s32 n=*a;s32 pos=M2C_FIELD(p,s16 *,0x40);if(max<0)max=0;
if(pos==0&&n==0){if(data_02101e84[0]&64){M2C_FIELD(p,s16 *,0x40)=max;n=5;goto done;}}
else if(data_02101e84[1]&64){if(n>=2)n--;else if(!func_020b8694(p)&&n>0)n--;goto done;}
if(pos==max&&n==5){if(data_02101e84[0]&128){n=0;M2C_FIELD(p,s16 *,0x40)=n;goto done;}}
else if(data_02101e84[1]&128){if(n<4){if(func_020b20e0(n+1))n++;}else if(!func_020b86e4(p)){if(func_020b20e0(n+1))n++;}goto done;}
if(data_02101e84[1]&32){n-=func_020b86b4(p)+6;if(n<0)n=0;func_020b8594(M2C_FIELD(p,s16 *,0x3e));}
else if(data_02101e84[1]&16){n+=6-func_020b870c(p);if(n>=6)n=5;func_020b8594(M2C_FIELD(p,s16 *,0x3e));}
done:if(n!=*a)func_020b1c60(n);M2C_FIELD(p,s16 *,0x3a)=n;}

void func_020b88f8(u8 *arg0) {
    void *func_020b895c(void);
    M2C_FIELD(func_020b895c(), s16 *, 0x3a) = *arg0;
}

void func_020b8910(void) {
    void *func_020b895c(void);
    s32 i;
    s32 y;
    func_020b895c();
    i = 0;
    y = 0x27;
    do {
        func_020b22a4(4, y, data_021290b4, i);
        i++;
        y += 0x10;
    } while (i < 6);
    func_020b1c78(0);
}

#pragma optimization_level 2
/* Returns the active instance registered under data_021290dc. */
void *func_020b895c(void) {
    void *func_01ffa770();
    extern M2C_UNK data_021290dc;
    return func_01ffa770(&data_021290dc);
}

void func_020b8970(void *arg0) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    void func_01ff9ce8(s32);
    void func_02080944(void *, s32, s32, s32);
    void func_02080cfc(void *, void *);
    void func_02087d84(void *, s32, s32, s32, s32, s32);
    void func_02088e84(void *, s32, s32, s32, s32);
    void func_02088f1c(void *);
    void func_0208ca2c(void *, s32, s32, s32);
    void func_020994e0(s32);
    void func_0209c024(s32, s32, void *, s32, s32, s32);
    void func_0209c048(s32, s32, void *, s32, s32, s32);
    s32 func_020a8b78(void);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    s32 func_020ae22c(s32);
    u8 func_020b846c(s32);
    void func_020b8594(s32);
    void func_020b8910(void);
    void func_020c0fac(void *);
    s32 func_020cd6fc(void);
    void func_020e3058(void *, s32, s32, s32, s32, s32, s32, void *, s32);
    void *func_020e3218(void *);
    void *temp_r4;
    void *temp_r5;
    s16 temp_r6;
    s16 temp_r7;
    s32 temp_r9;
    s32 temp_r10;
    s32 var_r5;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_020994e0(0);
    M2C_FIELD(arg0, u8 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x3a) = 0;
    M2C_FIELD(arg0, s16 *, 0x42) = 0x2e;
    M2C_FIELD(arg0, s16 *, 0x3e) = 0;
    M2C_FIELD(arg0, s16 *, 0x40) = 0;
    M2C_FIELD(arg0, s16 *, 0x44) = 0;
    M2C_FIELD(arg0, s16 *, 0x3c) = 0;
    M2C_FIELD(arg0, s16 *, 0x46) = 0;
    if (func_020cd6fc() != 0) {
        M2C_FIELD(arg0, u8 *, 0x34) = 1;
    }
    var_r5 = 0;
    if (M2C_FIELD(arg0, s16 *, 0x42) > 0) {
        do {
            if (func_020b846c(var_r5) != 0) {
                M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 1);
            }
            var_r5++;
        } while (var_r5 < M2C_FIELD(arg0, s16 *, 0x42));
    }
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3a) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    func_0200bc5c((M2C_UNK *) data_02129114);
    func_02080cfc(func_020e3218(data_02129120), M2C_FIELD(data_027e00c8, void **, 0x14));
    func_02080cfc(func_020e3218(data_02129130), M2C_FIELD(gCur3DSpriteEngine, void **, 0x28));
    func_0208116c((M2C_UNK *) data_02129140, 0xc0, 0x20);
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, void **, 0x28), 0x20, 0x18, 6);
    func_020e3058((u8 *) arg0 + 0x48, 0x5e, 0x8b, 0xa, 0x39c, 3, -1, arg0, 1);
    func_020e3058((u8 *) arg0 + 0x4c, 0x82, 0x8b, 0xb, 0x3a4, 3, -1, arg0, 0);
    func_020e3058((u8 *) arg0 + 0x50, 0xc0, 0xa0, 0, 0x3ac, 3, 1, arg0, 0);
    temp_r5 = M2C_FIELD(arg0, void **, 0x50);
    func_02088e84(temp_r5, 0xc0, 0xa0, 0x100, 0xa0);
    if ((u8) (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0)) {
        temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r9 = func_020aae10(temp_r5);
        temp_r10 = func_020aae44(temp_r5);
        func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7, temp_r6, (u16) temp_r9, (u16) temp_r10);
    }
    func_02088f1c(M2C_FIELD(arg0, void **, 0x50));
    func_020c0fac(arg0);
    func_0208ca2c((void *) 0x6b80, 0xb, func_020ae22c(0xc), 2);
    func_0209c048(0x1b, 3, M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), M2C_FIELD(arg0, s16 *, 0x44), 0, 0);
    func_0209c024(0x1c, 3, M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), func_020a8b78(), 0, 0);
    func_0209c048(0x1e, 3, M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), M2C_FIELD(arg0, s16 *, 0x42), 0, 0);
    func_020b8594(M2C_FIELD(arg0, s16 *, 0x3e));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    func_020b8910();
    gCur3DSpriteEngine = temp_r4;
}

#pragma optimization_level 4
