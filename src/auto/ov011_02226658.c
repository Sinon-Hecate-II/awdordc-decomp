/* 2 functions from 0x02226658 to 0x022273C8 (ov011), found by ds-decomp. */
#include "common.h"
typedef struct { u8 active:1; u8 remaining:7; } TransitionFlags;

#pragma opt_common_subs off
u32 func_ov011_02226658(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK DeleteSpriteObject();
    u8 func_01ffa6fc(void *);
    s32 EaseInterpolate(s32, s32, M2C_UNK, s32, s32);
    M2C_UNK func_ov011_022257b4(void *);
    M2C_UNK func_ov011_022257c4(void *);
    M2C_UNK func_ov011_0222588c(void *);
    s32 func_ov011_02225a18(void *);
    M2C_UNK func_ov011_02225a24(void *, u16, u16);
    M2C_UNK func_ov011_02225a9c(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u16 *gKeyState;
    extern void *data_02101e88;
    extern u16 **g3DSpriteEngineSub;
    extern u16 **g3DSpriteEngineMain;
    extern u16 **gCur3DSpriteEngine;
    u16 *volatile sp7C;
    u16 *volatile sp78;
    u16 *volatile sp74;
    u16 *volatile sp70;
    u16 *volatile sp6C;
    u16 *volatile sp68;
    u16 *volatile sp64;
    u16 *volatile sp60;
    u16 *volatile sp5C;
    u16 *volatile sp58;
    u16 *volatile sp54;
    u16 *volatile sp50;
    u16 *volatile sp4C;
    u16 *volatile sp48;
    u16 *volatile sp44;
    u16 *volatile sp40;
    u16 *volatile sp3C;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 **sp4;
    s32 temp_r0_3;
    s32 var_r5;
    s32 var_r9;
    u16 **temp_r1_8;
    u16 **temp_r4;
    u16 **var_r0;
    u16 *temp_r0_10;
    u16 *temp_r0_11;
    u16 *temp_r0_12;
    u16 *temp_r0_13;
    u16 *temp_r0_15;
    u16 *temp_r0_17;
    u16 *temp_r0_5;
    u16 *temp_r0_7;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r2;
    u16 *temp_r2_2;
    u16 *temp_r2_3;
    u16 *temp_r2_4;
    u16 *temp_r2_5;
    u16 *temp_r2_6;
    u16 *temp_r2_7;
    u16 *temp_r3;
    u16 *temp_r3_2;
    u16 *temp_r3_3;
    u16 *temp_r3_4;
    u16 *temp_r3_5;
    u16 *temp_r6;
    u16 *temp_r6_2;
    u16 *temp_r7;
    u16 *temp_r7_2;
    u16 *temp_r7_3;
    u16 *temp_r7_4;
    u32 temp_r0;
    u8 temp_r0_14;
    u8 temp_r0_16;
    u8 temp_r0_2;
    u8 temp_r0_4;
    u8 temp_r0_6;
    u8 temp_r1;
    u8 temp_r2_8;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) < 0x29CCU) {
        if ((u32) M2C_FIELD(arg0, u8 *, 0x37) >= 0xC8U) {
            M2C_FIELD(arg0, u8 *, 0x37) = 0U;
        }
        if (M2C_FIELD(arg0, u8 *, 0x37) == 0) {
            M2C_FIELD(arg0, u8 *, 0x35) = (u8) (M2C_FIELD(arg0, u8 *, 0x35) & ~0xF);
            M2C_FIELD(arg0, u8 *, 0x34) = (u8) ((u8) (M2C_FIELD(arg0, u8 *, 0x34) & ~4) & ~8);
            temp_r0_3 = func_ov011_02225a18(arg0);
            switch (temp_r0_3) {                    /* irregular */
            case 1:
                func_ov011_022257b4(arg0);
                temp_r1 = M2C_FIELD(arg0, u8 *, 0x34);
                M2C_FIELD(arg0, u8 *, 0x34) = ((temp_r1 & ~0xF0) | ((u32)((u8)(((u32)(temp_r1<<24)>>28)+1)<<28)>>24));
                M2C_FIELD(arg0, s32 *, 0x4C) = (s32) (M2C_FIELD(arg0, s32 *, 0x4C) + 0x10);
                M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 4);
                /* fallthrough */
            case 2:
                func_ov011_0222588c(arg0);
                if (func_ov011_02225a18(arg0) != 2) {
                    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 8);
                }
                break;
            case 0:
                M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) & ~2);
                sp7C = *gCur3DSpriteEngine;
                *sp7C = *sp7C | 0x10;
                sp78 = *gCur3DSpriteEngine;
                *sp78 = *sp78 & ~0x20;
                sp74 = *gCur3DSpriteEngine;
                *sp74 = *sp74 & ~0x40;
                sp70 = *gCur3DSpriteEngine;
                *sp70 = *sp70 | 0x80;
                sp6C = *gCur3DSpriteEngine;
                *sp6C = *sp6C | 0x100;
                func_01ff9ce8(1);
                func_01ff9ce8(2);
                break;
            }
        }
        if ((M2C_FIELD(arg0, s32 *, 0x50) != 0) && (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1E) >> 0x1F) != 0)) {
            func_ov011_022257c4(arg0);
        }
        temp_r0_4 = M2C_FIELD(arg0, u8 *, 0x37);
        if ((u32) temp_r0_4 <= 0x1EU) {
            sp68 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
            *sp68 = (u16) (*sp68 & ~1);
            sp64 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
            *sp64 = *sp64 & ~2;
            sp60 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
            *sp60 = (s16) (*sp60 & ~4);
            sp5C = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
            *sp5C = (s16) (*sp5C & ~8);
            sp58 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
            *sp58 = (s16) ((*sp58 & ~0x10) | ((u32) (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1D) >> 0x1F) << 0x1F) >> 0x1B));
            temp_r0_6 = EaseInterpolate(4, 0, 0x10, M2C_FIELD(arg0, u8 *, 0x37), 0x1E);
            M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_6;
            sp54 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
            *sp54 = (s16) ((*sp54 & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), u8 *, 0x51) = temp_r0_6;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_6);
        } else if ((u32) temp_r0_4 >= 0xAAU) {
            if (func_ov011_02225a18(arg0) == 0) {
                temp_r1_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
                M2C_FIELD(temp_r1_3, u16 *, 6) = (u16) ((M2C_FIELD(temp_r1_3, u16 *, 6) & ~3) | 1);
                temp_r1_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
                M2C_FIELD(temp_r1_4, u16 *, 8) = (u16) ((M2C_FIELD(temp_r1_4, u16 *, 8) & ~3) | 2);
                temp_r1_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
                M2C_FIELD(temp_r1_5, u16 *, 0xA) = (u16) ((M2C_FIELD(temp_r1_5, u16 *, 0xA) & ~3) | 3);
                temp_r1_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
                M2C_FIELD(temp_r1_6, u16 *, 0xC) = (u16) (M2C_FIELD(temp_r1_6, u16 *, 0xC) & ~3);
                sp50 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp50 = (s16) (*sp50 & ~1);
                sp4C = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp4C = (s16) (*sp4C & ~2);
                sp48 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp48 = (s16) (*sp48 & ~4);
                sp44 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp44 = (s16) (*sp44 | 8);
                sp40 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp40 = (s16) (*sp40 & ~0x10);
                sp3C = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp3C = (s16) (*sp3C & ~0x100);
                sp38 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp38 = (s16) (*sp38 & ~0x200);
                sp34 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp34 = *sp34 | 0x400;
                sp30 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp30 = (s16) (*sp30 & ~0x800);
                sp2C = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp2C = (s16) (*sp2C | 0x1000);
                sp28 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp28 = (s16) (*sp28 & ~0x2000);
                temp_r0_14 = EaseInterpolate(4, 0x10, 0, M2C_FIELD(arg0, u8 *, 0x37) - 0xAA, 0x1E);
                M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_14;
                sp24 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp24 = (s16) ((*sp24 & ~0xC0) | 0x40);
                M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = (s8) (0x10 - temp_r0_14);
                M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), u8 *, 0x52) = temp_r0_14;
            } else {
                sp20 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp20 = (u16) (*sp20 & ~1);
                sp1C = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp1C = *sp1C & ~2;
                sp18 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp18 = (s16) (*sp18 & ~4);
                sp14 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp14 = (s16) (*sp14 & ~8);
                sp10 = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *sp10 = (s16) ((*sp10 & ~0x10) | ((u32) (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1C) >> 0x1F) << 0x1F) >> 0x1B));
                temp_r0_16 = EaseInterpolate(4, 0x10, 0, M2C_FIELD(arg0, u8 *, 0x37) - 0xAA, 0x1E);
                M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_16;
                spC = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
                *spC = (s16) ((*spC & ~0xC0) | 0x40);
                M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), u8 *, 0x51) = temp_r0_16;
                M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_16);
            }
        }
    }
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_ov011_02225a9c(arg0, -0x68, 0, 0);
    func_ov011_02225a9c(arg0, 0, 0, 1);
    func_ov011_02225a9c(arg0, -0x68, 0, 2);
    func_ov011_02225a9c(arg0, 0, 0, 3);
    func_ov011_02225a9c(arg0, -0x68, 0, 4);
    func_ov011_02225a9c(arg0, 0, 0, 5);
    func_ov011_02225a9c(arg0, -0x68, 0, 6);
    func_ov011_02225a9c(arg0, 0, 0, 7);
    func_ov011_02225a9c(arg0, -0x68, 0, 8);
    func_ov011_02225a9c(arg0, 0, 0, 9);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    gCur3DSpriteEngine = temp_r4;
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        func_ov011_02225a24(arg0, M2C_FIELD(data_02101e88, u16 *, 0), M2C_FIELD(data_02101e88, u16 *, 2));
        gCur3DSpriteEngine = temp_r4;
    }
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) >= 0x28FAU) {
        func_01ffa6fc(arg0);
    }
    if (*gKeyState & 8) {
        temp_r2_8 = M2C_FIELD(arg0, u8 *, 0x34);
        if ((((u32) (temp_r2_8 << 0x1F) >> 0x1F) == 0) && ((u32) M2C_FIELD(arg0, u16 *, 0x3A) < 0x28DCU)) {
            M2C_FIELD(arg0, u8 *, 0x34) = (u8) ((temp_r2_8 & ~1) | 1);
        }
    }
    if (((u32) M2C_FIELD(arg0, u8 *, 0x38) < 0x1EU) && (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F) != 0)) {
        var_r9 = 0;
        sp4 = gCur3DSpriteEngine;
        do {
            if (var_r9 == 0) {
                var_r0 = g3DSpriteEngineMain;
            } else {
                var_r0 = g3DSpriteEngineSub;
            }
            gCur3DSpriteEngine = var_r0;
            var_r9 += 1;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), u8 *, 0x50) = EaseInterpolate(0, 0, -0x10, M2C_FIELD(arg0, u8 *, 0x38), 0x1E);
        } while (var_r9 < 2);
        gCur3DSpriteEngine = sp4;
    }
    temp_r0_2 = M2C_FIELD(arg0, u8 *, 0x38);
    if ((u32) temp_r0_2 < 0x1EU) {
        return temp_r0_2;
    }
    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F;
    if (temp_r0 == 0) {
        return (u8) temp_r0;
    }
    var_r5 = 0;
    M2C_FIELD(arg0, u16 *, 0x3A) = 0x29CBU;
    do {
        if (M2C_FIELD((arg0 + (var_r5 * 4)), s32 *, 0x40) != 0) {
            DeleteSpriteObject();
            M2C_FIELD((arg0 + (var_r5 * 4)), s32 *, 0x40) = 0;
        }
        var_r5 += 1;
    } while (var_r5 < 3);
    temp_r1_8 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    temp_r0_17 = *g3DSpriteEngineSub;
    sp8 = (u16 *)((u8 *)temp_r0_17 + 0x12);
    *sp8 = (*sp8 & ~0xC0) | 0x40;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 0x10;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0;
    gCur3DSpriteEngine = temp_r1_8;
    return func_01ffa6fc(arg0);
}
#pragma opt_common_subs reset
void func_ov011_02227048(void *a){
s32 func_ov011_02226550(s32 *,s32);extern u16 **g3DSpriteEngineSub,**g3DSpriteEngineMain,**gCur3DSpriteEngine;extern s32 data_ov011_02228c30;
u16 *volatile p0;
u16 *volatile p1;
u16 *volatile p2;
u16 *volatile p3;
u16 *volatile p4;
u16 *volatile p5;
u16 *volatile p6;
u16 *volatile p7;
u16 *volatile p8;
u16 *volatile p9;
u16 *volatile p10;
u16 *volatile p11;
u16 *volatile p12;
u16 *volatile p13;
u16 *volatile p14;
u16 *volatile p15;
u16 *volatile p16;
u16 *volatile p17;
u16 *volatile p18;
u16 *volatile p19;
u16 **old;u16 *p;
if(((TransitionFlags *)((u8 *)a+0x34))->active)M2C_FIELD(a,u8 *,0x38)=0;
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
p=*gCur3DSpriteEngine;M2C_FIELD(p,u16 *,6)=(M2C_FIELD(p,u16 *,6)&~3)|0;
p=*gCur3DSpriteEngine;M2C_FIELD(p,u16 *,8)=(M2C_FIELD(p,u16 *,8)&~3)|1;
p=*gCur3DSpriteEngine;M2C_FIELD(p,u16 *,10)=(M2C_FIELD(p,u16 *,10)&~3)|2;
p=*gCur3DSpriteEngine;M2C_FIELD(p,u16 *,12)=(M2C_FIELD(p,u16 *,12)&~3)|3;
p0=*gCur3DSpriteEngine;*p0=*p0&~16;
p1=*gCur3DSpriteEngine;*p1=*p1&~32;
p2=*gCur3DSpriteEngine;*p2=*p2&~64;
p3=*gCur3DSpriteEngine;*p3=*p3|128;
p4=*gCur3DSpriteEngine;*p4=*p4&~256;
p5=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p5=*p5&~1;
p6=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p6=*p6&~2;
p7=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p7=*p7&~4;
p8=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p8=*p8&~8;
p9=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p9=*p9|16;
p10=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p10=*p10&~256;
p11=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p11=*p11&~512;
p12=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p12=*p12&~1024;
p13=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p13=*p13|2048;
p14=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*p14=*p14&~4096;
gCur3DSpriteEngine=g3DSpriteEngineSub;
p15=*gCur3DSpriteEngine;*p15=*p15|16;
p16=*gCur3DSpriteEngine;*p16=*p16&~32;
p17=*gCur3DSpriteEngine;*p17=*p17|64;
p18=*gCur3DSpriteEngine;*p18=*p18|128;
p19=*gCur3DSpriteEngine;*p19=*p19&~256;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x3c)=0;M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x44)=0;
func_ov011_02226550(&data_ov011_02228c30,2);gCur3DSpriteEngine=old;
}
#pragma opt_common_subs reset
