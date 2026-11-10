/* 6 functions from 0x02217F5C to 0x02218BAC (ov004), found by ds-decomp. */
#include "common.h"
typedef struct { u16 a, b, c, d, e, f; } Ov004DisplayConfig;

#pragma opt_instruction_scheduling off
void func_ov004_02217f5c(void *arg0) {
    M2C_UNK func_01ff85b8(s32, u16, s32);
    s32 func_01ff9c34(u8, M2C_UNK);
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002c64(M2C_UNK);
    M2C_UNK func_02002e3c(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK func_0200323c(M2C_UNK);
    M2C_UNK func_020032bc(M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    s32 func_0207c8ec(s32, M2C_UNK);
    M2C_UNK func_02081384(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02081400(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(M2C_UNK *, s32);
    M2C_UNK func_020815fc(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_0208168c(s32, M2C_UNK);
    M2C_UNK func_020822b8(u16 *);
    M2C_UNK Reset3DSpriteBankState();
    M2C_UNK func_02082c84();
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02088f1c(void *);
    M2C_UNK func_020994e0();
    M2C_UNK func_0209cce4(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    M2C_UNK func_020ab150(void *, M2C_UNK);
    void *func_020ab1c4(void *);
    M2C_UNK func_020ceb48();
    M2C_UNK func_020cf0a8(s32);
    M2C_UNK func_020cf278(s32);
    s32 func_020e3218(M2C_UNK *);
    M2C_UNK func_ov003_021fef58(void *);
    M2C_UNK func_ov003_021ff36c();
    extern void **g3DSpriteEngineSub;
    extern void **g3DSpriteEngineMain;
    extern void **gCur3DSpriteEngine;
    extern M2C_UNK data_ov004_02218bc4;
    extern M2C_UNK data_ov004_0223c5a8;
    extern M2C_UNK data_ov004_0223c5b0;
    extern M2C_UNK data_ov004_0223c5b8;
    extern M2C_UNK data_ov004_0223c5c0;
    extern M2C_UNK data_ov004_0223c5c8;
    extern M2C_UNK data_ov004_0223c5d0;
    extern M2C_UNK data_ov004_0223c5dc;
    extern M2C_UNK data_ov004_0223c5e8;
    extern M2C_UNK data_ov004_0223c5f4;
    extern M2C_UNK data_ov004_0223c600;
    extern M2C_UNK data_ov004_0223c60c;
    extern M2C_UNK data_ov004_0223c618;
    extern M2C_UNK data_ov004_0223c624;
    extern M2C_UNK data_ov004_0223c630;
    extern M2C_UNK data_ov004_0223c648;
    extern M2C_UNK data_ov004_0223c654;
    extern M2C_UNK data_ov004_0223c660;
    extern M2C_UNK data_ov004_0223c66c;
    extern M2C_UNK func_ov004_022148a4;
    extern M2C_UNK func_ov004_02214904;
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
    s16 temp_r6;
    s16 temp_r6_2;
    s16 temp_r7;
    s16 temp_r7_2;
    s16 temp_r7_3;
    s16 temp_r8;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r2;
    s32 var_r7;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r1;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r1_8;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 temp_r9_3;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void **temp_r5;
    void *var_r5;
    void *var_r8;

    Ov004DisplayConfig sp3C = *(Ov004DisplayConfig *)&data_ov004_02218bc4;
    Ov004DisplayConfig sp30 = *(Ov004DisplayConfig *)((u8 *)&data_ov004_02218bc4 + 12);
    func_02082c84();
    func_02002c64(3);
    GX_SetBankForBG(0x20);
    func_02002968(0x10);
    func_02002e3c(0x40);
    func_02003124(4);
    func_020031cc(8);
    func_0200323c(0x80);
    func_020032bc(0x100);
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_020822b8((u16 *)&sp30);
    temp_r1 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp2C = temp_r1;
    *sp2C = *sp2C | 0x10;
    temp_r1_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp28 = temp_r1_2;
    *sp28 = *sp28 | 0x20;
    temp_r1_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp24 = temp_r1_3;
    *sp24 = *sp24 | 0x40;
    temp_r1_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp20 = temp_r1_4;
    *sp20 = *sp20 | 0x80;
    temp_r0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp1C = temp_r0;
    *sp1C = *sp1C | 0x100;
    Reset3DSpriteBankState();
    M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x44) = 0;
    func_020994e0();
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_020822b8((u16 *)&sp3C);
    temp_r1_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp18 = temp_r1_5;
    *sp18 = *sp18 | 0x10;
    temp_r1_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp14 = temp_r1_6;
    *sp14 = *sp14 | 0x20;
    temp_r1_7 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp10 = temp_r1_7;
    *sp10 = *sp10 | 0x40;
    temp_r1_8 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    spC = temp_r1_8;
    *spC = *spC | 0x80;
    temp_r0_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp8 = temp_r0_2;
    *sp8 = *sp8 | 0x100;
    Reset3DSpriteBankState();
    M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x44) = 0;
    func_020994e0();
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_0200bc5c(&data_ov004_0223c5a8);
    func_02081384(&data_ov004_0223c5f4, 0);
    func_02081400(&data_ov004_0223c5b8, 0, 0x200);
    func_02081384(&data_ov004_0223c5d0, 0x28000);
    func_02081400(&data_ov004_0223c5c0, 0x200, 0x20);
    func_02081384(&data_ov004_0223c660, 0x30000);
    func_02081400(&data_ov004_0223c630, 0x220, 0x20);
    func_020814e4(&data_ov004_0223c624);
    func_0208168c(func_020e3218(&data_ov004_0223c5e8), 0x38000);
    func_0208168c(func_020e3218(&data_ov004_0223c5dc), 0x39000);
    func_02081528();
    func_02081400(&data_ov004_0223c5c8, 0x240, 0xA0);
    func_02081400(&data_ov004_0223c5b0, 0x2E0, 0x20);
    func_02081384(&data_ov004_0223c60c, 0x3A000);
    func_02081400(&data_ov004_0223c600, 0x300, 0x20);
    func_020814e4(&data_ov004_0223c66c);
    func_02081590(&data_ov004_0223c654, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18) + 0x20);
    func_02081590(&data_ov004_0223c648, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
    func_020815fc(&data_ov004_0223c618, 0x1E0, 0x20);
    func_02081528();
    func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), (u16) func_01ff9c34((u8) ((u32) (*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x1D) >> 0x1D), 1), 0xF001);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    func_020a9a30(0, 2, 0x47, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x260);
    temp_r0_3 = func_020ab1c4(arg0);
    func_020aab24(temp_r0_3, 2, 0x140, 3, 0);
    func_020ab150(temp_r0_3, 2);
    M2C_FIELD(temp_r0_3, s16 *, 0x3C) = 0x800;
    func_02088e84(temp_r0_3, 0xE0, 0x9C, 0xE0, 0xBC);
    if (M2C_FIELD(M2C_FIELD(temp_r0_3, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r7 = M2C_FIELD(temp_r0_3, s16 *, 0x52);
        temp_r8 = M2C_FIELD(temp_r0_3, s16 *, 0x50);
        temp_r9 = func_020aae10(temp_r0_3);
        func_02087d84(M2C_FIELD(temp_r0_3, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) func_020aae44(temp_r0_3));
    }
    func_02088f1c(temp_r0_3);
    func_020aad18(temp_r0_3);
    temp_r0_4 = func_020ab1c4(arg0);
    func_020aab24(temp_r0_4, 6, 0x150, 3, 0);
    func_020ab150(temp_r0_4, 0x100);
    M2C_FIELD(temp_r0_4, s16 *, 0x3C) = 0x800;
    func_02088e84(temp_r0_4, 0xC0, 0x9C, 0xC0, 0xBC);
    if (M2C_FIELD(M2C_FIELD(temp_r0_4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r6 = M2C_FIELD(temp_r0_4, s16 *, 0x52);
        temp_r7_2 = M2C_FIELD(temp_r0_4, s16 *, 0x50);
        temp_r9_2 = func_020aae10(temp_r0_4);
        func_02087d84(M2C_FIELD(temp_r0_4, void **, 0x64), 1, temp_r7_2, temp_r6, (u16) temp_r9_2, (u16) func_020aae44(temp_r0_4));
    }
    func_02088f1c(temp_r0_4);
    func_020aad18(temp_r0_4);
    temp_r0_5 = func_020ab1c4(arg0);
    func_020aab24(temp_r0_5, 0x12, 0x160, 3, 0);
    M2C_FIELD(temp_r0_5, s16 *, 0x3C) = 0x800;
    func_020ab150(temp_r0_5, 8);
    func_02088e84(temp_r0_5, 0x80, 0x9C, 0x80, 0xBC);
    if (M2C_FIELD(M2C_FIELD(temp_r0_5, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        temp_r6_2 = M2C_FIELD(temp_r0_5, s16 *, 0x52);
        temp_r7_3 = M2C_FIELD(temp_r0_5, s16 *, 0x50);
        temp_r9_3 = func_020aae10(temp_r0_5);
        func_02087d84(M2C_FIELD(temp_r0_5, void **, 0x64), 1, temp_r7_3, temp_r6_2, (u16) temp_r9_3, (u16) func_020aae44(temp_r0_5));
    }
    func_02088f1c(temp_r0_5);
    func_020aad18(temp_r0_5);
    gCur3DSpriteEngine = temp_r5;
    func_ov003_021fef58(arg0);
    func_0209cce4(&func_ov004_022148a4, 4);
    func_0209cce4(&func_ov004_02214904, 0xA);
    temp_r0_6 = M2C_FIELD(arg0, s32 *, 0x40);
    if ((temp_r0_6 != 0x800) && (temp_r0_6 != 0x1000)) {

    } else {
        if ((s32) M2C_FIELD(arg0, s16 *, 0x50) < (s32) (0x60 - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x44) * temp_r0_6, 0x1000))) {
            M2C_FIELD(arg0, s16 *, 0x50) = (s16) (0x60 - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x44) * M2C_FIELD(arg0, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x52) < (s32) (0x39 - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x46) * M2C_FIELD(arg0, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(arg0, s16 *, 0x52) = (s16) (0x39 - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x46) * M2C_FIELD(arg0, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x50) > (s32) (0xA0 - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x44) * M2C_FIELD(arg0, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(arg0, s16 *, 0x50) = (s16) (0xA0 - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x44) * M2C_FIELD(arg0, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x52) > (s32) (0x5F - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x46) * M2C_FIELD(arg0, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(arg0, s16 *, 0x52) = (s16) (0x5F - func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x46) * M2C_FIELD(arg0, s32 *, 0x40), 0x1000));
        }
    }
    temp_r0_7 = M2C_FIELD(arg0, s32 *, 0x40);
    if ((temp_r0_7 != 0x800) && (temp_r0_7 != 0x1000)) {

    } else {
        if ((s32) M2C_FIELD(arg0, s16 *, 0x44) < 0) {
            M2C_FIELD(arg0, s16 *, 0x44) = 0;
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x46) < 0) {
            M2C_FIELD(arg0, s16 *, 0x46) = 0;
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x44) > 0x200) {
            M2C_FIELD(arg0, s16 *, 0x44) = 0x200;
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x46) > 0x130) {
            M2C_FIELD(arg0, s16 *, 0x46) = 0x130;
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x50) < (s32) (0x100 - func_0207c8ec(M2C_FIELD(arg0, s32 *, 0x40) << 9, 0x1000))) {
            M2C_FIELD(arg0, s16 *, 0x50) = (s16) (0x100 - func_0207c8ec(M2C_FIELD(arg0, s32 *, 0x40) << 9, 0x1000));
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x52) < (s32) (0xC0 - func_0207c8ec(M2C_FIELD(arg0, s32 *, 0x40) * 0x158, 0x1000))) {
            M2C_FIELD(arg0, s16 *, 0x52) = (s16) (0xC0 - func_0207c8ec(M2C_FIELD(arg0, s32 *, 0x40) * 0x158, 0x1000));
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x50) > 0) {
            M2C_FIELD(arg0, s16 *, 0x50) = 0;
        }
        if ((s32) M2C_FIELD(arg0, s16 *, 0x52) > 0) {
            M2C_FIELD(arg0, s16 *, 0x52) = 0;
        }
    }
    var_r7 = 0;
    var_r8 = M2C_FIELD(arg0, void **, 0x5C);
loop_46:
    if (var_r7 < 0) {
        var_r5 = NULL;
    } else if (var_r7 >= 0x40) {
        var_r5 = NULL;
    } else {
        var_r5 = var_r8;
    }
    if (M2C_FIELD(var_r5, u8 *, 4) & 2) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    if (!(var_r2 & 0xFF)) {
        var_r7 += 1;
        var_r8 += 0x20;
        if (var_r7 >= 0x40) {
            var_r5 = NULL;
        } else {
            goto loop_46;
        }
    }
    if (var_r5 != NULL) {
        func_020ceb48();
        func_020cf278(M2C_FIELD(var_r5, u8 *, 7) + 0xA1);
        func_020cf0a8(M2C_FIELD(var_r5, u8 *, 7) + 0xA1);
        func_ov003_021ff36c();
    }
    M2C_FIELD(arg0, s16 *, 0x4C) = 0;
    M2C_FIELD(arg0, s16 *, 0x4E) = 0;
}
#pragma opt_instruction_scheduling reset
void func_ov004_022188b8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov004_022188c4(void *a){extern void **gCurrentMap;extern u32 data_0215d8a0[2];PlaySoundEffect(0x10014);data_0215d8a0[1]=(data_0215d8a0[1]&~0xffff)|(u16)(M2C_FIELD(*gCurrentMap,u16 *,0x5142)-0xa1);if(func_020a8958(M2C_FIELD(*gCurrentMap,u16 *,0x5142)))func_01ffa8c4(a,7);M2C_FIELD(a,u8 *,0x38)=2;M2C_FIELD(a,u8 *,0x36)=0;}

/* Advance a 16-frame transition, linearly raising the 3D sprite engine's visibility and setting its display flags. */
void func_ov004_02218950(void *transition) {
    void func_01ffa6fc(void *);
    s8 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, u8, s32);
    extern void **g3DSpriteEngineMain;
    extern void **gCur3DSpriteEngine;
    u16 *volatile flagsC0;
    u16 *volatile flags01;
    u16 *volatile flags02;
    u16 *volatile flags04;
    u16 *volatile flags08;
    u16 *volatile flags10;
    u16 *volatile flags100;
    u16 *volatile flags200;
    u16 *volatile flags400;
    u16 *volatile flags800;
    u16 *volatile flags1000;
    s8 visibility;
    void **previousEngine;
    void *engine01;
    void *engine02;
    void *engine04;
    void *engine08;
    void *engine10;
    void *engine100;
    void *engine200;
    void *engine400;
    void *engine800;
    void *engine1000;
    void *engine;

    M2C_FIELD(transition, u8 *, 0x36) = (u8) (M2C_FIELD(transition, u8 *, 0x36) + 1);
    visibility = EaseInterpolate(0, 0, 8, M2C_FIELD(transition, u8 *, 0x36), 0x10);
    previousEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    engine = *g3DSpriteEngineMain;
    flagsC0 = engine + 0x12;
    *flagsC0 = (s16) ((*flagsC0 & ~0xC0) | 0xC0);
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x51) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x52) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x53) = visibility;
    engine01 = *gCur3DSpriteEngine;
    flags01 = engine01 + 0x12;
    *flags01 = (s16) ((*flags01 & ~1) | 1);
    engine02 = *gCur3DSpriteEngine;
    flags02 = engine02 + 0x12;
    *flags02 = (s16) (*flags02 | 2);
    engine04 = *gCur3DSpriteEngine;
    flags04 = engine04 + 0x12;
    *flags04 = (s16) (*flags04 | 4);
    engine08 = *gCur3DSpriteEngine;
    flags08 = engine08 + 0x12;
    *flags08 = (s16) (*flags08 | 8);
    engine10 = *gCur3DSpriteEngine;
    flags10 = engine10 + 0x12;
    *flags10 = (s16) (*flags10 | 0x10);
    engine100 = *gCur3DSpriteEngine;
    flags100 = engine100 + 0x12;
    *flags100 = (s16) (*flags100 & ~0x100);
    engine200 = *gCur3DSpriteEngine;
    flags200 = engine200 + 0x12;
    *flags200 = (s16) (*flags200 & ~0x200);
    engine400 = *gCur3DSpriteEngine;
    flags400 = engine400 + 0x12;
    *flags400 = (s16) (*flags400 & ~0x400);
    engine800 = *gCur3DSpriteEngine;
    flags800 = engine800 + 0x12;
    *flags800 = (s16) (*flags800 & ~0x800);
    engine1000 = *gCur3DSpriteEngine;
    flags1000 = engine1000 + 0x12;
    *flags1000 = (s16) (*flags1000 & ~0x1000);
    gCur3DSpriteEngine = previousEngine;
    if ((u32) M2C_FIELD(transition, u8 *, 0x36) < 0x10U) {
        return;
    }
    func_01ffa6fc(transition);
}

void func_ov004_02218b7c(M2C_UNK arg0) {
    M2C_UNK func_ov003_021ff3ac();
    M2C_UNK func_ov004_02213124(M2C_UNK);
    func_ov003_021ff3ac();
    func_ov004_02213124(arg0);
}

void func_ov004_02218b94(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov004_0223c684;
    func_01ffa42c(&data_ov004_0223c684, arg0);
}

