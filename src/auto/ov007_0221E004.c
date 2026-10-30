/* 9 functions from 0x0221E004 to 0x0221EDA8 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_0221e004(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

M2C_UNK func_ov007_0221e010(void) {
    return 0;
}

void func_ov007_0221e568(u8 *arg0) {
    M2C_UNK func_0207c8ec(u8, M2C_UNK);
    M2C_UNK func_0207c928(u8, M2C_UNK);
    M2C_UNK func_020b1c60(u8);
    extern u16 *data_02101e84;
    M2C_UNK func_ov007_0221e010(void);
    extern u8 data_ov007_0221f5a4[];
    register u8 *ptr = arg0;
    register u8 var_r7;
    register u16 temp_r5;
    register u16 temp_r6;

    var_r7 = *ptr;
    temp_r5 = data_02101e84[0];
    temp_r6 = data_02101e84[1];
    if (temp_r5 & 1) {
        func_ov007_0221e010();
        return;
    }
    if (temp_r6 & 0x40) {
        if (func_0207c8ec(var_r7, 0xF) == 0) {
            if (temp_r6 == temp_r5) {
                var_r7 = data_ov007_0221f5a4[func_0207c928(var_r7, 0xF)];
            }
        } else {
            var_r7 -= 0xF;
        }
        if (0x4BU > var_r7) {
            goto block_15;
        }
    } else if (temp_r6 & 0x80) {
        if (func_0207c8ec(var_r7, 0xF) == 4) {
            if (temp_r6 == temp_r5) {
                var_r7 = data_ov007_0221f5a4[func_0207c928(var_r7, 0xF)];
            }
        } else {
            var_r7 += 0xF;
        }
        if ((u32) var_r7 < 0x4BU) {
            goto block_15;
        }
    } else {
block_15:
        if (temp_r6 & 0x20) {
            if (func_0207c928(var_r7, 0xF) == 0) {
                if (temp_r6 == temp_r5) {
                    var_r7 += 0xE;
                }
            } else {
                var_r7 -= 1;
            }
        } else if (temp_r6 & 0x10) {
            if (func_0207c928(var_r7, 0xF) == 0xE) {
                if (temp_r6 == (int)temp_r5) {
                    var_r7 -= 0xE;
                }
            } else {
                ++var_r7;
            }
        }
    }
    if (*ptr == var_r7) {
        return;
    }
    func_020b1c60(var_r7);
}

void func_ov007_0221e6bc(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov007_0221e6d0(void *arg0) {
extern u16 **gCur3DSpriteEngine, **data_027e00c8;
extern s16 data_ov007_02220dd0[],data_ov007_02220d58[],data_ov007_02220d80[],data_ov007_02220da8[];
void *func_020b22a4(s32,s32,void*,s32);
void func_020b1c78(s32); void func_020b2158(s32);
void func_02087d18(s32,s16,s16,s32,s32,u16,s32);
void *saved=gCur3DSpriteEngine;
s16 *table; s32 y, x, k, a, b, c; u8 i;
gCur3DSpriteEngine=data_027e00c8;
y=0; k=0; table=data_ov007_02220dd0;
do { x=0; do {
void *p=func_020b22a4(x*table[2],y*table[3],table,k);
x++; M2C_FIELD(p,void**,0x10)=arg0; k++;
} while(x<15); y++; } while(y<5);
a=0; table=data_ov007_02220d58; do {void *p=func_020b22a4(a*table[2],0,table,a+100); a++; M2C_FIELD(p,void**,0x10)=arg0;} while(a<3);
b=0; table=data_ov007_02220d80; do {void *p=func_020b22a4(b*table[2],0,table,b+103); b++; M2C_FIELD(p,void**,0x10)=arg0;} while(b<2);
c=0; table=data_ov007_02220da8; do {void *p=func_020b22a4(c*table[2],0,table,c+105); c++; M2C_FIELD(p,void**,0x10)=arg0;} while(c<2);
gCur3DSpriteEngine=saved;func_020b1c78(0);func_020b2158(0);
for(i=0;i<17;i++) func_02087d18(M2C_FIELD(arg0,s32*,0x38),(s16)(i*8+16),16,8,16,i,14);
}

void func_ov007_0221e85c(void *arg0) {
    M2C_UNK func_02087e34(s32);
    M2C_UNK func_020b2140();
    M2C_UNK func_020b2178();
    func_020b2178();
    func_02087e34(M2C_FIELD(arg0, s32 *, 0x38));
    func_020b2140();
}

void func_ov007_0221e878(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_01ff9dd8(M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02080cfc(s32, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_020822b8(M2C_UNK *);
    M2C_UNK func_0208ca2c(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK func_020a92bc(void *, M2C_UNK);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK func_020aeebc(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020e32e8(M2C_UNK *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c8;
    extern M2C_UNK data_ov007_02220d40;
    extern M2C_UNK data_ov007_02220d4c;
    extern M2C_UNK data_ov007_02221980;
    extern M2C_UNK data_ov007_0222198c;
    extern M2C_UNK data_ov007_02221998;
    extern M2C_UNK data_ov007_022219a8;
    extern M2C_UNK data_ov007_022219b8;
    extern M2C_UNK data_ov007_022219c8;
    extern M2C_UNK data_ov007_022219d8;
    volatile u16 *sp14;
    volatile u16 *sp10;
    volatile u16 *spC;
    volatile u16 *sp8;
    volatile u16 *sp4;
    volatile u16 *sp0;
    s32 var_r0;
    s32 var_r2;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    void *temp_lr;
    void *temp_r1;
    void *temp_r4;

    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x16) = 2;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x14) = 8;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x17) = 8;
    func_020a92bc(M2C_FIELD(arg0, void **, 0x44), 0);
    temp_r1 = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(temp_r1, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r1, u8 *, 0x20) & ~0xE0) | 0x40);
    temp_lr = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(temp_lr, u8 *, 0x28) = (u8) (M2C_FIELD(temp_lr, u8 *, 0x28) & ~0xE0);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s16 *, 0x12) = 0x250;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x21) = 0x16;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_020822b8(&data_ov007_02220d4c);
    temp_r0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp14 = temp_r0;
    *temp_r0 = *sp14 | 0x10;
    temp_r0_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp10 = temp_r0_2;
    *temp_r0_2 = *sp10 | 0x20;
    temp_r0_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    spC = temp_r0_3;
    *temp_r0_3 = *spC | 0x40;
    temp_r0_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp8 = temp_r0_4;
    *temp_r0_4 = *sp8 | 0x80;
    temp_r0_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp4 = temp_r0_5;
    *temp_r0_5 = *sp4 | 0x100;
    temp_r0_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp0 = (volatile u16 *)(temp_r0_6 + 0x12);
    M2C_FIELD(temp_r0_6, s16 *, 0x12) = (s16) (*sp0 & ~0xC0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x53) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3A) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x42) = 0;
    func_01ff9ce8(1);
    func_01ff9ce8(0);
    func_01ff9ce8(3);
    func_01ff9dd8(1);
    func_01ff9dd8(0);
    func_01ff9dd8(3);
    func_0200bc5c(&data_ov007_02221980);
    func_02080cfc(func_020e32e8(&data_ov007_0222198c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10));
    func_020e32e8(&data_ov007_02221998);
    func_020814e4();
    var_r2 = 0;
loop_1:
    if (M2C_FIELD(arg0, s32 *, 0x34) == *(&data_ov007_02220d40 + (var_r2 * 4))) {
        var_r0 = var_r2 + 0x64;
    } else {
        var_r2 += 1;
        if (var_r2 >= 3) {
            var_r0 = 0x64;
        } else {
            goto loop_1;
        }
    }
    switch (var_r0) {                               /* irregular */
    case 0x66:
        func_02081590(func_020e32e8(&data_ov007_022219a8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    case 0x64:
        func_02081590(func_020e32e8(&data_ov007_022219b8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    case 0x65:
        func_02081590(func_020e32e8(&data_ov007_022219c8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    }
    func_02081528();
    func_0208116c(&data_ov007_022219d8, 0xA0, 0x60);
    func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 0x18, 5);
    func_02091d4c(4);
    func_02091d4c(0x17);
    func_020aeebc(2, 0xF, 6);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    func_020a9a30(1, 0, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x4A00);
    func_020a9a30(1, 2, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2C0);
    func_0208ca2c(0x1000, 1, func_020ae22c(9), 2);
    gCur3DSpriteEngine = temp_r4;
    func_020b2178();
}

void func_ov007_0221ec34(void) {
    M2C_UNK func_020af1f8();
    func_020af1f8();
}

extern u16 **data_027e00c8;
extern u16 **data_027e01d8;
extern u16 **gCur3DSpriteEngine;
void func_ov007_0221ec40(void *arg0) {
    M2C_UNK func_0208df84(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    u16 func_0209b5e4(s32, M2C_UNK *);
    M2C_UNK func_0209b67c(u16, M2C_UNK, u16, u16, s32);
    s32 func_0209c268(M2C_UNK *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c8;
    extern M2C_UNK data_ov007_02221e0c;
    extern M2C_UNK data_ov007_02221e10;
    u16 **sp8;
    M2C_UNK *var_r10;
    s16 var_r6;
    s32 var_r8;
    s32 var_r9;
    u16 temp_r5;

    sp8 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_0208df84(M2C_FIELD(arg0, s16 *, 0x3E), M2C_FIELD(arg0, s16 *, 0x40), 8, 0x10, (s32) (u16) ((0x3FF & (0x80 >> ((u32) (**data_027e00c8 << 0x11) >> 0x1E))) | 0x1000), 0);
    var_r6 = 0x10;
    var_r8 = 0x4D00;
    var_r9 = 0;
    if (M2C_FIELD(&data_ov007_02221e0c, s32 *, 4) != 0) {
        var_r10 = &data_ov007_02221e10;
        do {
            temp_r5 = func_0209b5e4(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + var_r8, var_r10);
            func_0209b67c((u16) (var_r6 + ((u32) (8 - func_0209c268(var_r10)) >> 1)), 0x10, temp_r5, (u16) ((0x3FF & ((s32) (var_r8 >> 5) >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x7000), 0);
            var_r8 = (s32) (u16) (var_r8 + (((u32) (((u32) (temp_r5 + 7) >> 3) + 3) >> 2) << 8));
            var_r9 += 1;
            var_r6 += 8;
            var_r10 += 4;
        } while (*(&data_ov007_02221e10 + (var_r9 * 4)) != 0);
    }
    gCur3DSpriteEngine = sp8;
}

