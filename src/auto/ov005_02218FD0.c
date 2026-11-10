/* 11 functions from 0x02218FD0 to 0x02219FA0 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_02218fd0(void *arg0) {
    M2C_UNK func_01ff85b8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002ab8(M2C_UNK);
    M2C_UNK func_02002bb8(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK func_0200323c(M2C_UNK);
    M2C_UNK func_020032bc(M2C_UNK);
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
    extern u16 gMapConfig;
    extern void **data_027e0058;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
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
    GX_SetBankForBG(1);
    func_02002968(2);
    func_02003124(4);
    func_020031cc(8);
    func_02002ab8(0x40);
    func_02002bb8(0x20);
    func_0200323c(0x80);
    func_020032bc(0x100);
    func_02091cd0();
    var_r7 = 0;
    sp8 = gCur3DSpriteEngine;
    do {
        if (var_r7 == 0) {
            var_r1 = g3DSpriteEngineMain;
        } else {
            var_r1 = g3DSpriteEngineSub;
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
    gCur3DSpriteEngine = g3DSpriteEngineMain;
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
    gCur3DSpriteEngine = g3DSpriteEngineSub;
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
            var_r0_6 = g3DSpriteEngineMain;
        } else {
            var_r0_6 = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = var_r0_6;
        func_0200bc5c(&data_ov005_02221148);
        func_0208116c(&data_ov005_02221150, 0x40, 0x20);
        func_02080cfc(&data_ov005_02221160, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2F00);
        func_0208116c(&data_ov005_02221168, 0x3E0, 0x20);
        if (((u32) (gMapConfig << 0x1D) >> 0x1D) != 1) {
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

void func_ov005_02219a24(void *p){
extern s32 data_027e01d8;
s32 i,v; u32 a,b;
if(M2C_FIELD(p,s32 *,0x60)<=0){func_01ffa730(p);return;}
M2C_FIELD(p,s32 *,0x5c)++;
v=EaseInterpolate(0,0,16,M2C_FIELD(p,s32 *,0x5c),M2C_FIELD(p,s32 *,0x60));
a=(u8)(16-v);b=(u8)v;
for(i=0;i<16;i++){
M2C_FIELD(p,u16 **,0x54)[i]=func_020ae354(((u16 *)p)[i+26],(u16)M2C_FIELD(p,s32 *,0x58),a,b);
}
M2C_FIELD(data_027e01d8,u8 *,0x46)|=16;
if(M2C_FIELD(p,s32 *,0x5c)==M2C_FIELD(p,s32 *,0x60)){
M2C_FIELD(p,s32 *,0x5c)=0;func_01ffa6fc(p);
}
}

#pragma push
#pragma opt_instruction_scheduling off
void func_ov005_02219aec(void *p){
extern s32 data_027e01d8;
s32 i,v; u32 a,b;
if(M2C_FIELD(p,s32 *,0x64)<=0){func_01ffa730(p);return;}
M2C_FIELD(p,s32 *,0x5c)++;
v=EaseInterpolate(0,16,0,M2C_FIELD(p,s32 *,0x5c),M2C_FIELD(p,s32 *,0x64));
a=(u8)(16-v);b=(u8)v;
i=0; do {
M2C_FIELD(p,u16 **,0x54)[i]=func_020ae354(((u16 *)p)[i+26],(u16)M2C_FIELD(p,s32 *,0x58),a,b);
i++; }while(i<16);
M2C_FIELD(data_027e01d8,u8 *,0x46)|=16;
if(M2C_FIELD(p,s32 *,0x5c)==M2C_FIELD(p,s32 *,0x64)){
M2C_FIELD(p,s32 *,0x5c)=0;func_01ffa6fc(p);
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

void func_ov005_02219bcc(void *p) {
extern s32 gCur3DSpriteEngine;
extern u8 data_ov005_022211f0[], data_ov005_022211f8[];
s32 func_020aae10(void *); s32 func_020aae44(void *);
void *q; s16 a,b,y,c,d; s32 t,u,v,w;
M2C_FIELD(p,s32 *,0x3c)++;
M2C_FIELD(p,s32 *,0x40)=EaseInterpolate(4,32,0,M2C_FIELD(p,s32 *,0x3c),16);
y=(s16)(M2C_FIELD(p,s32 *,0x40)+160);
q=M2C_FIELD(p,void **,0x34);
func_02088e84(q,224,y,224,y);
if(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0) t=1; else t=0;
if(t&255){a=M2C_FIELD(q,s16 *,0x52);b=M2C_FIELD(q,s16 *,0x50);u=func_020aae10(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,b,a,(u16)u,(u16)func_020aae44(q));}
M2C_FIELD(q,s16 *,0x34)=224;M2C_FIELD(q,s16 *,0x36)=y;
if(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0) v=1; else v=0;
if(v&255){c=M2C_FIELD(q,s16 *,0x52);d=M2C_FIELD(q,s16 *,0x50);w=func_020aae10(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,d,c,(u16)w,(u16)func_020aae44(q));}
if(M2C_FIELD(p,s32 *,0x3c)==16){
M2C_FIELD(p,s32 *,0x3c)=0;M2C_FIELD(p,u8 *,0x44)=0;
func_0200bc5c(data_ov005_022211f0);
func_02080cfc(data_ov005_022211f8,M2C_FIELD(gCur3DSpriteEngine,void **,0x2c)+0x540);
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,void **,0x2c)+0x540,192,0x9000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
func_01ffaa6c(M2C_FIELD(p,void **,0x38));M2C_FIELD(p,s32 *,0x38)=0;func_01ffa6fc(p);
}
}

void func_ov005_02219d98(void *arg0) {
M2C_UNK AddSprite(u16,u16,u16,void *,s32);
extern s32 gCur3DSpriteEngine; extern s32 data_027e00b4;
s32 val; s32 y; s32 i; s32 x; u16 t; u32 bits; s32 mask=511,mask2=1023,base=440;
if(!M2C_FIELD(arg0,u8 *,0x44))return;
val=M2C_FIELD(arg0,s32 *,0x40);
y=(val&0xff00)|((val+0xa0)&255);
for(i=0;i<4;i++){
x=i*64;
t=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,s32 *,0),u16 *,0);
bits=((u32)t<<17)>>30;
AddSprite((u16)(x&mask),y,(u16)((mask2&(base>>bits))|0xec00),&data_027e00b4,0);
}
}

void func_ov005_02219e40(void) {
    void func_ov005_02219bcc();
    func_ov005_02219bcc();
}

void func_ov005_02219e4c(void) {
    void func_ov005_02219d98();
    func_ov005_02219d98();
}

#pragma opt_strength_reduction off
void func_ov005_02219e58(void *arg0){
M2C_UNK func_02090810(s32,s32,s16);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 *second=&g3DSpriteEngineSub,*first=&g3DSpriteEngineMain,*eng=&gCur3DSpriteEngine;
s32 saved; s32 i,a,x,y;
saved=*eng;i=0;
do{
if(i==0)*eng=*first;else *eng=*second;
x=M2C_FIELD(arg0,s32*,0x3c);y=M2C_FIELD(arg0,s32*,0x40);x=(s32)((s32)x<<16);
a=M2C_FIELD(M2C_FIELD(arg0+i*4,void**,0x34),s32*,0x38);
if(i==0)y-=192;
x=(s32)((s32)x>>16);if(a)func_02090810(a,x,(s16)y);
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
#pragma opt_strength_reduction on
void func_ov005_02219ee0(void *arg0) {
    M2C_UNK DeleteSpriteObject(void *);
    void func_ov005_02219e58(void *);
    extern s32 gFrameCounter;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x44);
    switch (temp_r0) {                              /* irregular */
    case 1:
        if (gFrameCounter & 1) {
            M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
        }
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) - 1);
        break;
    case 3:
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
        if (gFrameCounter & 1) {
            M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) - 1);
        }
        break;
    default:
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) - 1);
        break;
    }
    func_ov005_02219e58(arg0);
    if (((s32) M2C_FIELD(arg0, s32 *, 0x3C) < 0x108) && ((s32) M2C_FIELD(arg0, s32 *, 0x40) >= -8)) {
        return;
    }
    DeleteSpriteObject(arg0);
}

