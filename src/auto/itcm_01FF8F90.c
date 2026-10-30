/* 17 functions from 0x01FF8F90 to 0x01FF9ED0 (itcm), found by ds-decomp. */
#include "common.h"

s32 func_01ff8f90(s32 arg0, s32 arg1, u16 *arg2) {
    s32 sp0;
    s32 temp_r10;
    s32 temp_r3_3;
    s32 temp_r5;
    s32 temp_r7_2;
    s32 temp_r8;
    s32 temp_r9;
    s32 var_ip;
    s32 var_r5;
    s32 var_r6;
    u16 temp_r3;
    u16 temp_r3_2;
    u16 temp_r7;
    u8 temp_r4;
    u8 temp_r8_2;
    void *var_r2;

    if (arg2 != NULL) {
        temp_r3 = *arg2;
        var_r2 = arg2 + 2;
        var_ip = 0;
        sp0 = (s32) temp_r3;
        if ((s32) temp_r3 > 0) {
loop_3:
            temp_r3_2 = M2C_FIELD(var_r2, u16 *, 2);
            temp_r7 = M2C_FIELD(var_r2, u16 *, 0);
            var_r5 = 8;
            temp_r8 = temp_r3_2 & 0x4000;
            var_r6 = 8;
            temp_r9 = temp_r3_2 & 0x8000;
            if (temp_r8 == 0x4000) {
                var_r5 = 0x10;
                var_r6 = 0x10;
            }
            temp_r10 = temp_r3_2 & 0xC000;
            if (temp_r9 == 0x8000) {
                var_r5 = 0x20;
                var_r6 = 0x20;
            }
            if (temp_r10 == 0xC000) {
                var_r5 = 0x40;
                var_r6 = 0x40;
            }
            if ((temp_r7 & 0x4000) == 0x4000) {
                var_r5 = 0x10;
                if (temp_r8 == 0x4000) {
                    var_r5 = 0x20;
                }
                var_r6 = 8;
                if (temp_r9 == 0x8000) {
                    var_r5 = 0x20;
                    var_r6 = 0x10;
                }
                if (temp_r10 == 0xC000) {
                    var_r5 = 0x40;
                    var_r6 = 0x20;
                }
            }
            if ((temp_r7 & 0x8000) == 0x8000) {
                var_r6 = 0x10;
                if (temp_r8 == 0x4000) {
                    var_r6 = 0x20;
                }
                var_r5 = 8;
                if (temp_r9 == 0x8000) {
                    var_r5 = 0x10;
                    var_r6 = 0x20;
                }
                if (temp_r10 == 0xC000) {
                    var_r5 = 0x20;
                    var_r6 = 0x40;
                }
            }
            temp_r7_2 = arg0 + (temp_r3_2 & 0x1FF);
            temp_r8_2 = arg1 + (u8) temp_r7;
            temp_r3_3 = temp_r7_2 & 0x1FF;
            if ((temp_r3_3 <= 0x100) && ((s32) temp_r8_2 <= 0xC0)) {
                return 1;
            }
            temp_r5 = (var_r5 + temp_r7_2) & 0x1FF;
            if ((temp_r5 <= 0x100) && ((s32) temp_r8_2 <= 0xC0)) {
                return 1;
            }
            temp_r4 = var_r6 + temp_r8_2;
            if ((temp_r5 <= 0x100) && ((s32) temp_r4 <= 0xC0)) {
                return 1;
            }
            if ((temp_r3_3 <= 0x100) && ((s32) temp_r4 <= 0xC0)) {
                return 1;
            }
            var_ip += 1;
            var_r2 += 6;
            if (var_ip >= sp0) {
                return 0;
            }
            goto loop_3;
        }
    }
    return 0;
}

void func_01ff90e4(s32 arg0, s32 arg1, u32 arg2, u16 *arg3)
{
    extern u16 **gCur3DSpriteEngine;
    u16 *dst;
    s32 count;
    s32 lo, hi, mask = 0x3ff, xmask;
    s32 a, b, c, shift;
    u16 *base;
    void *engine;
    u8 n;

    count = *arg3++;
    engine = gCur3DSpriteEngine;
    base = M2C_FIELD(engine, u16 * volatile *, 0x38);
    n = M2C_FIELD(engine, volatile u8 *, 0x4a);
    dst = base + n * 4;
    if (!count) {
        return;
    }
    hi = arg2 & 0xfc00;
    lo = arg2 & mask;
    xmask = mask - 0x200;
    do {
        if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a) >= 128) {
            return;
        }
        a = arg3[0];
        dst[0] = ((a | arg1) & 0xff00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3e) + (a + arg1)) & 255);
        b = arg3[1];
        dst[1] = ((b | arg0) & 0xfe00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (b + arg0)) & xmask);
        c = arg3[2];
        arg3 += 3;
        shift = (u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30;
        dst[2] = (c & 0xfc00) + ((lo + (((c & mask) >> shift) & mask)) & mask) + hi;
        dst += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a)++;
    } while (--count);
}

M2C_UNK func_01ff91d8(void) {
return 0;
}

M2C_UNK func_01ff9690() { return 0; }

void func_01ff9ab4(void) {
    extern u16 *data_027e00bc;
    func_0200245c(((u32)(M2C_FIELD(data_027e00bc, u16 *, 4) << 31) >> 31) != 0);
    func_02002428(((u32)(M2C_FIELD(data_027e00bc, u16 *, 4) << 30) >> 31) != 0);
    if (((u32)(M2C_FIELD(data_027e00bc, u16 *, 4) << 29) >> 31) != 0) {
        *(volatile u16 *)0x04000004 |= 0x20;
    } else {
        *(volatile u16 *)0x04000004 &= ~0x20;
    }
}

void func_01ff9b38(void) {
    M2C_UNK func_01ff9690();
    void func_0207fafc(void);
    func_01ff9ab4();
    func_01ff91d8();
    func_01ff9690();
    func_0207fafc();
}

u8 func_01ff9b70(u8 arg0,u32 arg1) {
u8 result;
switch(arg0){case 0:return 1;case 1:case 3:if(arg1<=2)result=1;else result=0;return result;case 2:case 4:case 5:if(arg1<=1)result=1;else result=0;return result;default:return 0;}
}

u8 func_01ff9bcc(s32 arg0,s32 arg1) {
u8 a,b,c;
switch(arg0){case 1:if(arg1==3)a=1;else a=0;return a;case 2:if((u32)(u8)(arg1+0xfe)<=1)b=1;else b=0;return b;case 4:if(arg1==2)c=1;else c=0;return c;default:return 0;}
}

s32 func_01ff9c34(u8 arg0, s32 arg1) {
    extern u16 **gCur3DSpriteEngine;
    extern s32 data_01ff9b50[];
    extern s32 data_01ff9b60[];
    if (func_01ff9b70(arg0, arg1) != 0) {
        return data_01ff9b50[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30];
    }
    if (func_01ff9bcc(arg0, arg1) != 0) {
        return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30];
    }
    return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30] * 2;
}

void func_01ff9ce8(u8 arg0) {
    s32 func_01ff9c34(u8, s32);
    M2C_UNK func_02007e98(M2C_UNK, s32, s32);
    extern u16 **gCur3DSpriteEngine;
    func_02007e98(0, M2C_FIELD(&gCur3DSpriteEngine[arg0], s32 *, 0x20), func_01ff9c34((u8)(((u32)(**gCur3DSpriteEngine << 0x1D) >> 0x1D)), arg0));
}

void func_01ff9d38(s32 arg0) {
    extern u16 *data_027e00bc;
    extern s32 data_027e00c8;
    func_02007e98(0, M2C_FIELD((data_027e00c8 + (arg0 * 4)), s32 *, 0x20), func_01ff9c34((u8) ((u32) (*data_027e00bc << 0x1D) >> 0x1D), arg0));
}

void func_01ff9d88(s32 arg0) {
    extern u16 *data_027e00c0;
    extern s32 data_027e00c4;
    func_02007e98(0, M2C_FIELD((data_027e00c4 + (arg0 * 4)), s32 *, 0x20), func_01ff9c34((u8) ((u32) (*data_027e00c0 << 0x1D) >> 0x1D), arg0));
}

#pragma opt_propagation off
void func_01ff9dd8(u8 arg0) { M2C_UNK func_02007e98(M2C_UNK,s32,s32); extern u16 **gCur3DSpriteEngine; s32 dest; dest=M2C_FIELD((char *)gCur3DSpriteEngine + arg0*4,s32 *,0xC); { s32 zero=0; s32 size=0x40; func_02007e98(zero,dest,size); } }
#pragma opt_propagation reset
void func_01ff9e00(void) {
    extern u16 **gCur3DSpriteEngine;
    s32 i;
    for (i = 0; i < 4; i++) {
        func_01ff9dd8((u8)i);
        func_01ff9ce8((u8)i);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1 << i;
    }
}

