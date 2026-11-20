/* 11 functions from 0x02218FD0 to 0x02219FA0 (ov005), found by ds-decomp. */
#include "common.h"
#include "sprite_script.h"

/* A result-screen spark (SpawnResultSpark in ov005_02219FA0.c): a two-screen
 * particle that drifts towards the top-right corner and is deleted once it has
 * left the 256x384 view. */
#define RESULT_SPARK_SPRITES 0x34 /* void *[2]: the spark's main- and sub-screen sprite objects */
#define RESULT_SPARK_X       0x3C /* s32 horizontal position in the view */
#define RESULT_SPARK_Y       0x40 /* s32 vertical position in the two-screen view */
#define RESULT_SPARK_VARIANT 0x44 /* s32 sprite/motion variant */
#define RESULT_SPARK_END_X   0x108 /* x at which the spark has left the right edge */
#define RESULT_SPARK_END_Y   (-8)  /* y at which the spark has left the top edge */

/* The result-screen slide object (AnimateResultSlide and its draw callback). */
#define RESULT_SLIDE_TIMER  0x3C /* s32: frames the slide has run (0..16) */
#define RESULT_SLIDE_Y      0x40 /* s32: y position the slide has reached */
#define RESULT_SLIDE_ACTIVE 0x44 /* u8: nonzero while the slide band is shown */

#pragma scheduling off
void func_ov005_02218fd0(void *arg0) {
    M2C_UNK func_01ff85b8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_020026d8(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002ab8(M2C_UNK);
    M2C_UNK func_02002bb8(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK GX_SetBankForBGExtPlttSub(M2C_UNK);
    M2C_UNK GX_SetBankForOBJExtPlttSub(M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080cfc(M2C_UNK *, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(M2C_UNK *, s32);
    M2C_UNK func_020815fc(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020822b8(M2C_UNK *);
    M2C_UNK func_02082c84();
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02087db8(void *, M2C_UNK);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02091cd0();
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK func_02098b94(s32, s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    M2C_UNK func_020ab150(void *, M2C_UNK);
    void *func_020ab1c4(M2C_UNK);
    M2C_UNK *func_020e3218(M2C_UNK *);
    s32 func_ov005_02218e54();
    s32 func_ov005_02218edc();
    extern M2C_UNK data_0215c334;
    extern u16 data_02168f14;
    extern void **data_027e0058;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02220a9c;
    extern M2C_UNK data_ov005_02221058;
    extern M2C_UNK data_ov005_02221060;
    extern M2C_UNK data_ov005_0222106c;
    extern M2C_UNK data_ov005_0222107c;
    extern M2C_UNK data_ov005_0222108c;
    extern M2C_UNK data_ov005_0222109c;
    extern M2C_UNK data_ov005_022210ac;
    extern M2C_UNK data_ov005_022210b8;
    extern M2C_UNK data_ov005_022210c8;
    extern M2C_UNK data_ov005_022210d0;
    extern M2C_UNK data_ov005_022210e0;
    extern M2C_UNK data_ov005_022210f0;
    extern M2C_UNK data_ov005_02221100;
    extern M2C_UNK data_ov005_02221110;
    extern M2C_UNK data_ov005_02221124;
    extern M2C_UNK data_ov005_02221130;
    extern M2C_UNK data_ov005_0222113c;
    extern M2C_UNK data_ov005_02221148;
    extern M2C_UNK data_ov005_02221150;
    extern M2C_UNK data_ov005_02221160;
    extern M2C_UNK data_ov005_02221168;
    extern M2C_UNK data_ov005_02221170;
    extern M2C_UNK data_ov005_02221180;
    extern M2C_UNK data_ov005_02221190;
    extern M2C_UNK data_ov005_0222119c;
    extern M2C_UNK data_ov005_022211a8;
    extern M2C_UNK data_ov005_022211b4;
    extern M2C_UNK data_ov005_022211c0;
    extern M2C_UNK data_ov005_022211cc;
    extern M2C_UNK data_ov005_022211d8;
    extern M2C_UNK data_ov005_022211e4;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    s32 sp8;
    M2C_UNK *var_r0_5;
    void *temp_r5;
    void *temp_r5_2;
    void *temp_r5_3;
    s16 temp_r6;
    s16 temp_r6_2;
    s16 temp_r6_3;
    s16 temp_r6_4;
    s16 temp_r6_5;
    s16 temp_r6_6;
    s16 temp_r7;
    s16 temp_r7_2;
    s16 temp_r7_3;
    s16 temp_r7_4;
    s16 temp_r7_5;
    s16 temp_r7_6;
    s32 temp_r1;
    s32 temp_r4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_7;
    s32 var_r1_2;
    s32 var_r1_3;
    s32 var_r1_4;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    s32 var_r7;
    s32 var_r9;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    u16 *temp_r0_7;
    s32 temp_r8;
    s32 temp_r8_2;
    s32 temp_r8_3;
    s32 temp_r8_4;
    s32 temp_r8_5;
    s32 temp_r8_6;
    void *temp_r0_10;
    void *temp_r0_8;
    void *temp_r0_9;
    s32 var_r0_6;
    s32 var_r1;

    func_02082c84();
    func_020026d8(1);
    func_02002968(2);
    func_02003124(4);
    func_020031cc(8);
    func_02002ab8(0x40);
    func_02002bb8(0x20);
    GX_SetBankForBGExtPlttSub(0x80);
    GX_SetBankForOBJExtPlttSub(0x100);
    func_02091cd0();
    var_r7 = 0;
    sp8 = gCur3DSpriteEngine;
    do {
        if (var_r7 == 0) {
            var_r1 = data_027e00c8;
        } else {
            var_r1 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r1;
        func_020822b8(&data_ov005_02220a9c);
        var_r7 += 1;
        temp_r0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        sp24 = temp_r0;
        *sp24 = *sp24 | 0x10;
        temp_r0_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        sp20 = temp_r0_2;
        *sp20 = *sp20 | 0x20;
        temp_r0_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        sp1C = temp_r0_3;
        *sp1C = *sp1C | 0x40;
        temp_r0_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        sp18 = temp_r0_4;
        *sp18 = *sp18 | 0x80;
        temp_r0_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        sp14 = temp_r0_5;
        *sp14 = *sp14 | 0x100;
        temp_r0_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        sp10 = temp_r0_6;
        *sp10 = *sp10 | 0x1000;
        temp_r0_7 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        spC = temp_r0_7;
        *spC = (*spC & ~0x6000) | 0x2000;
    } while (var_r7 < 2);
    gCur3DSpriteEngine = data_027e00c8;
    func_02091d4c(0);
    M2C_FIELD(arg0, void **, 0x38) = func_020ab1c4(7);
    func_020aab24(M2C_FIELD(arg0, void **, 0x38), 1, 0x158, 4, 1);
    temp_r5 = M2C_FIELD(arg0, void **, 0x38);
    func_02088e84(temp_r5, 0, 0xC0, 0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r8 = func_020aae10(temp_r5);
        func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7, temp_r6, (u16) temp_r8, (u16) func_020aae44(temp_r5));
    }
    var_r1_2 = 0;
    M2C_FIELD(temp_r5, s16 *, 0x34) = 0;
    M2C_FIELD(temp_r5, s16 *, 0x36) = 0xC0;
    if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
        var_r1_2 = 1;
    }
    if (var_r1_2 & 0xFF) {
        temp_r6_2 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7_2 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r8_2 = func_020aae10(temp_r5);
        func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7_2, temp_r6_2, (u16) temp_r8_2, (u16) func_020aae44(temp_r5));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x38), 1);
    var_r2 = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s8 *, 0x49) = 0;
    temp_r0_8 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 0x64);
    if (M2C_FIELD(temp_r0_8, u8 *, 0x12) != 0) {
        var_r2 = 1;
    }
    if (var_r2 & 0xFF) {
        func_02087db8(temp_r0_8, 1);
    }
    M2C_FIELD(arg0, void **, 0x3C) = func_020ab1c4(7);
    func_020aab24(M2C_FIELD(arg0, void **, 0x3C), 0xE, 0x168, 4, 1);
    temp_r5_2 = M2C_FIELD(arg0, void **, 0x3C);
    func_02088e84(temp_r5_2, 0, 0xC0, 0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r6_3 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
        temp_r7_3 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
        temp_r8_3 = func_020aae10(temp_r5_2);
        func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r7_3, temp_r6_3, (u16) temp_r8_3, (u16) func_020aae44(temp_r5_2));
    }
    var_r1_3 = 0;
    M2C_FIELD(temp_r5_2, s16 *, 0x34) = 0;
    M2C_FIELD(temp_r5_2, s16 *, 0x36) = 0xC0;
    if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r1_3 = 1;
    }
    if (var_r1_3 & 0xFF) {
        temp_r6_4 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
        temp_r7_4 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
        temp_r8_4 = func_020aae10(temp_r5_2);
        func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r7_4, temp_r6_4, (u16) temp_r8_4, (u16) func_020aae44(temp_r5_2));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x3C), 0x200);
    var_r2_2 = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), s8 *, 0x49) = 0;
    temp_r0_9 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), void **, 0x64);
    if (M2C_FIELD(temp_r0_9, u8 *, 0x12) != 0) {
        var_r2_2 = 1;
    }
    if (var_r2_2 & 0xFF) {
        func_02087db8(temp_r0_9, 1);
    }
    M2C_FIELD(arg0, void **, 0x40) = func_020ab1c4(7);
    func_020aab24(M2C_FIELD(arg0, void **, 0x40), 0xF, 0x170, 4, 1);
    temp_r5_3 = M2C_FIELD(arg0, void **, 0x40);
    func_02088e84(temp_r5_3, 0, 0xC0, 0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r5_3, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        temp_r6_5 = M2C_FIELD(temp_r5_3, s16 *, 0x52);
        temp_r7_5 = M2C_FIELD(temp_r5_3, s16 *, 0x50);
        temp_r8_5 = func_020aae10(temp_r5_3);
        func_02087d84(M2C_FIELD(temp_r5_3, void **, 0x64), 1, temp_r7_5, temp_r6_5, (u16) temp_r8_5, (u16) func_020aae44(temp_r5_3));
    }
    var_r1_4 = 0;
    M2C_FIELD(temp_r5_3, s16 *, 0x34) = 0;
    M2C_FIELD(temp_r5_3, s16 *, 0x36) = 0xC0;
    if (M2C_FIELD(M2C_FIELD(temp_r5_3, void **, 0x64), u8 *, 0x12) != 0) {
        var_r1_4 = 1;
    }
    if (var_r1_4 & 0xFF) {
        temp_r6_6 = M2C_FIELD(temp_r5_3, s16 *, 0x52);
        temp_r7_6 = M2C_FIELD(temp_r5_3, s16 *, 0x50);
        temp_r8_6 = func_020aae10(temp_r5_3);
        func_02087d84(M2C_FIELD(temp_r5_3, void **, 0x64), 1, temp_r7_6, temp_r6_6, (u16) temp_r8_6, (u16) func_020aae44(temp_r5_3));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x40), 0x100);
    var_r2_3 = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0x49) = 0;
    temp_r0_10 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 0x64);
    if (M2C_FIELD(temp_r0_10, u8 *, 0x12) != 0) {
        var_r2_3 = 1;
    }
    if (var_r2_3 & 0xFF) {
        func_02087db8(temp_r0_10, 1);
    }
    func_020a9a30(1, 0, 2, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2800);
    func_020a9a30(1, 2, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2C0);
    func_020a9a30(1, 2, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2E0);
    func_020a9a30(1, 2, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x300);
    func_0200bc5c(&data_ov005_02221058);
    func_0208116c(&data_ov005_02221060, 0x320, 0x20);
    func_020814e4(&data_ov005_0222106c);
    func_02081590(&data_ov005_0222107c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
    func_02081590(&data_ov005_0222108c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
    func_020815fc(&data_ov005_0222109c, 0x120, 0xE0);
    func_02081528();
    func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0x800, 0x9000);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    func_02080cfc(&data_ov005_022210ac, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3700);
    func_0208116c(&data_ov005_022210b8, 0x3C0, 0x20);
    gCur3DSpriteEngine = data_027e00c4;
    func_02091d4c(0);
    func_020a9a30(1, 0, 2, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2800);
    func_020a9a30(1, 2, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2C0);
    func_0200bc5c(&data_ov005_022210c8);
    func_020814e4(&data_ov005_022210d0);
    func_02081590(&data_ov005_022210e0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
    func_02081590(&data_ov005_022210f0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
    func_020815fc(&data_ov005_02221100, 0x120, 0xC0);
    func_02081528();
    func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0x800, 0x9000);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    if (M2C_FIELD(*data_027e0058, u16 *, 0x5142) == 0xBA) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (var_r0_4 & 0xFF) {
        var_r0_5 = func_020e3218(&data_ov005_02221110);
    } else {
        var_r0_5 = func_020e3218(&data_ov005_02221124);
    }
    func_02080cfc(var_r0_5, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x7100);
    func_0208116c(&data_ov005_02221130, 0x360, 0x20);
    func_0208116c(&data_ov005_0222113c, 0x380, 0x20);
    var_r9 = 0;
    gCur3DSpriteEngine = sp8;
    do {
        if (var_r9 == 0) {
            var_r0_6 = data_027e00c8;
        } else {
            var_r0_6 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r0_6;
        func_0200bc5c(&data_ov005_02221148);
        func_0208116c(&data_ov005_02221150, 0x40, 0x20);
        func_02080cfc(&data_ov005_02221160, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2F00);
        func_0208116c(&data_ov005_02221168, 0x3E0, 0x20);
        if (((u32) (data_02168f14 << 0x1D) >> 0x1D) != 1) {
            var_r0_7 = 1;
        } else {
            var_r0_7 = 0;
        }
        if (!(var_r0_7 & 0xFF)) {
            func_02080cfc(&data_ov005_02221170, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3B00);
            func_0208116c(&data_ov005_02221180, 0x340, 0x20);
        } else {
            switch (M2C_FIELD(&data_0215c334, u8 *, 3)) {
            default:
                break;
            case 4:
                func_02080cfc(&data_ov005_02221190, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3B00);
                func_0208116c(&data_ov005_0222119c, 0x340, 0x20);
                break;
            case 3:
                func_02080cfc(&data_ov005_022211a8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3B00);
                func_0208116c(&data_ov005_022211b4, 0x340, 0x20);
                break;
            case 2:
                func_02080cfc(&data_ov005_022211c0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3B00);
                func_0208116c(&data_ov005_022211cc, 0x340, 0x20);
                break;
            case 1:
                func_02080cfc(&data_ov005_022211d8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3B00);
                func_0208116c(&data_ov005_022211e4, 0x340, 0x20);
                break;
            }
        }
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = sp8;
    temp_r4 = func_ov005_02218e54();
    temp_r1 = func_ov005_02218edc();
    if (temp_r4 == 0) {
        return;
    }
    func_02098b94(temp_r4, temp_r1, 0x7100, 4);
}
#pragma scheduling reset
void func_ov005_02219a24(void *p){
extern s32 data_027e01d8;
s32 i,v; u32 a,b;
if(M2C_FIELD(p,s32 *,0x60)<=0){Sprite_ResumeAnimationRepeat(p);return;}
M2C_FIELD(p,s32 *,0x5c)++;
v=EaseInterpolate(0,0,16,M2C_FIELD(p,s32 *,0x5c),M2C_FIELD(p,s32 *,0x60));
a=(u8)(16-v);b=(u8)v;
for(i=0;i<16;i++){
M2C_FIELD(p,u16 **,0x54)[i]=BlendRgb555_16(((u16 *)p)[i+26],(u16)M2C_FIELD(p,s32 *,0x58),a,b);
}
M2C_FIELD(data_027e01d8,u8 *,0x46)|=16;
if(M2C_FIELD(p,s32 *,0x5c)==M2C_FIELD(p,s32 *,0x60)){
M2C_FIELD(p,s32 *,0x5c)=0;Sprite_ResumeAnimation(p);
}
}

#pragma push
#pragma opt_instruction_scheduling off
void func_ov005_02219aec(void *p){
extern s32 data_027e01d8;
s32 i,v; u32 a,b;
if(M2C_FIELD(p,s32 *,0x64)<=0){Sprite_ResumeAnimationRepeat(p);return;}
M2C_FIELD(p,s32 *,0x5c)++;
v=EaseInterpolate(0,16,0,M2C_FIELD(p,s32 *,0x5c),M2C_FIELD(p,s32 *,0x64));
a=(u8)(16-v);b=(u8)v;
i=0; do {
M2C_FIELD(p,u16 **,0x54)[i]=BlendRgb555_16(((u16 *)p)[i+26],(u16)M2C_FIELD(p,s32 *,0x58),a,b);
i++; }while(i<16);
M2C_FIELD(data_027e01d8,u8 *,0x46)|=16;
if(M2C_FIELD(p,s32 *,0x5c)==M2C_FIELD(p,s32 *,0x64)){
M2C_FIELD(p,s32 *,0x5c)=0;Sprite_ResumeAnimation(p);
}
}
#pragma pop
void func_ov005_02219bb4(void) {
    void func_ov005_02219a24();
    func_ov005_02219a24();
}

void func_ov005_02219bc0(void) {
    void func_ov005_02219aec();
    func_ov005_02219aec();
}

/* Advances the result screen's background reveal: over 16 frames it slides the page
 * sprite down from y=160 to y=192, then loads the "/result" background image and
 * retires the transition object. */
void AnimateResultSlide(void *p) {
extern s32 gCur3DSpriteEngine;
extern u8 sResultDir[], sResultBackgroundFile[];
s32 GetUnitSpriteWidth(void *); s32 GetUnitSpriteHeight(void *);
void *q; s16 a,b,y,c,d; s32 t,u,v,w;
M2C_FIELD(p,s32 *,0x3c)++;
M2C_FIELD(p,s32 *,0x40)=EaseInterpolate(4,32,0,M2C_FIELD(p,s32 *,0x3c),16);
y=(s16)(M2C_FIELD(p,s32 *,0x40)+160);
q=M2C_FIELD(p,void **,0x34);
func_02088e84(q,224,y,224,y);
if(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0) t=1; else t=0;
if(t&255){a=M2C_FIELD(q,s16 *,0x52);b=M2C_FIELD(q,s16 *,0x50);u=GetUnitSpriteWidth(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,b,a,(u16)u,(u16)GetUnitSpriteHeight(q));}
M2C_FIELD(q,s16 *,0x34)=224;M2C_FIELD(q,s16 *,0x36)=y;
if(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0) v=1; else v=0;
if(v&255){c=M2C_FIELD(q,s16 *,0x52);d=M2C_FIELD(q,s16 *,0x50);w=GetUnitSpriteWidth(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,d,c,(u16)w,(u16)GetUnitSpriteHeight(q));}
if(M2C_FIELD(p,s32 *,0x3c)==16){
M2C_FIELD(p,s32 *,0x3c)=0;M2C_FIELD(p,u8 *,0x44)=0;
SetFileDirectory(sResultDir);
LoadDecompressedFileTo(sResultBackgroundFile,M2C_FIELD(gCur3DSpriteEngine,void **,0x2c)+0x540);
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,void **,0x2c)+0x540,192,0x9000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
func_01ffaa6c(M2C_FIELD(p,void **,0x38));M2C_FIELD(p,s32 *,0x38)=0;Sprite_ResumeAnimation(p);
}
}

/* Draw the result screen's sliding band while it is active: four 64x32 sprites
 * across the screen at the slide's y, with the tile base shifted by the sprite
 * bank's OBJ boundary mode. */
void DrawResultSlideBand(void *slide) {
M2C_UNK AddSprite(u16,u16,u16,void *,s32);
extern s32 gCur3DSpriteEngine; extern s32 gSpriteDesc64x32;
s32 slideY; s32 screenY; s32 column; s32 columnX; u16 bankFlags; u32 boundary; s32 xMask=511,tileMask=1023,tileBase=440;
if(!M2C_FIELD(slide,u8 *,RESULT_SLIDE_ACTIVE))return;
slideY=M2C_FIELD(slide,s32 *,RESULT_SLIDE_Y);
screenY=(slideY&0xff00)|((slideY+0xa0)&255);
for(column=0;column<4;column++){
columnX=column*64;
bankFlags=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,s32 *,0),u16 *,0);
boundary=((u32)bankFlags<<17)>>30;
AddSprite((u16)(columnX&xMask),screenY,(u16)((tileMask&(tileBase>>boundary))|0xec00),&gSpriteDesc64x32,0);
}
}

void func_ov005_02219e40(void) {
    void AnimateResultSlide();
    AnimateResultSlide();
}

void func_ov005_02219e4c(void) {
    void DrawResultSlideBand();
    DrawResultSlideBand();
}

#pragma opt_strength_reduction off
/* Draw the result-screen spark on both screens: for each screen, point the current
 * 3D sprite engine at that screen's engine and move every script player of the
 * spark's sprite object to the spark's position, the top screen's copy 192 rows up. */
void DrawResultSpark(void *spark){
M2C_UNK SpritePlayer_SetListPosition(s32,s32,s16);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 *subEngine=&g3DSpriteEngineSub,*mainEngine=&g3DSpriteEngineMain,*curEngine=&gCur3DSpriteEngine;
s32 saved; s32 screen,players,x,y;
saved=*curEngine;screen=0;
do{
if(screen==0)*curEngine=*mainEngine;else *curEngine=*subEngine;
x=M2C_FIELD(spark,s32*,RESULT_SPARK_X);y=M2C_FIELD(spark,s32*,RESULT_SPARK_Y);x=(s32)((s32)x<<16);
players=M2C_FIELD(M2C_FIELD(spark+screen*4,void**,RESULT_SPARK_SPRITES),s32*,SPRITE_OWNER_PLAYER_LIST);
if(screen==0)y-=192;
x=(s32)((s32)x>>16);if(players)SpritePlayer_SetListPosition(players,x,(s16)y);
screen++;
}while(screen<2);
gCur3DSpriteEngine=saved;
}
#pragma opt_strength_reduction on
/* Advance a result-screen spark one frame: the sprite variant chooses how fast it
 * drifts along each axis (variant 1 moves x every other frame, variant 3 y every
 * other frame, any other variant both every frame), then redraw it and delete it
 * once it has left the top or right edge of the view. */
void UpdateResultSpark(void *spark) {
    M2C_UNK DeleteSpriteObject(void *);
    void DrawResultSpark(void *);
    extern s32 gFrameCounter;
    s32 variant;

    variant = M2C_FIELD(spark, s32 *, RESULT_SPARK_VARIANT);
    switch (variant) {                              /* irregular */
    case 1:
        if (gFrameCounter & 1) {
            M2C_FIELD(spark, s32 *, RESULT_SPARK_X) = (s32) (M2C_FIELD(spark, s32 *, RESULT_SPARK_X) + 1);
        }
        M2C_FIELD(spark, s32 *, RESULT_SPARK_Y) = (s32) (M2C_FIELD(spark, s32 *, RESULT_SPARK_Y) - 1);
        break;
    case 3:
        M2C_FIELD(spark, s32 *, RESULT_SPARK_X) = (s32) (M2C_FIELD(spark, s32 *, RESULT_SPARK_X) + 1);
        if (gFrameCounter & 1) {
            M2C_FIELD(spark, s32 *, RESULT_SPARK_Y) = (s32) (M2C_FIELD(spark, s32 *, RESULT_SPARK_Y) - 1);
        }
        break;
    default:
        M2C_FIELD(spark, s32 *, RESULT_SPARK_X) = (s32) (M2C_FIELD(spark, s32 *, RESULT_SPARK_X) + 1);
        M2C_FIELD(spark, s32 *, RESULT_SPARK_Y) = (s32) (M2C_FIELD(spark, s32 *, RESULT_SPARK_Y) - 1);
        break;
    }
    DrawResultSpark(spark);
    if (((s32) M2C_FIELD(spark, s32 *, RESULT_SPARK_X) < RESULT_SPARK_END_X) && ((s32) M2C_FIELD(spark, s32 *, RESULT_SPARK_Y) >= RESULT_SPARK_END_Y)) {
        return;
    }
    DeleteSpriteObject(spark);
}

