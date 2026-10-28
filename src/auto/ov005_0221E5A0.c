/* 9 functions from 0x0221E5A0 to 0x0221F4F8 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_0221e5a0(M2C_UNK arg0) {
    (void)arg0;
    return;
}

void func_ov005_0221e88c(void *arg0) {
    (void)arg0;
}

s32 func_ov005_0221eef4(void *arg0) {
    s32 func_020ad3f0(void);
    s32 func_01ffa3dc(s32 *, void *);
    extern u32 data_027e15bc;
    extern void **data_027e00c4, **data_027e00c8, **gCur3DSpriteEngine;
    extern u16 *data_02101e84;
    extern s32 data_ov005_02220ad0[];
    volatile u16 *volatile p;
    void **saved;
    void **chosen;
    s32 i;
    if (!(data_027e15bc & 3)) {
        saved = gCur3DSpriteEngine;
        i = 0;
        do {
            if (i == 0) chosen = data_027e00c8;
            else chosen = data_027e00c4;
            i++;
            gCur3DSpriteEngine = chosen;
            p = (u16 *)((u8 *)*chosen + 0x3E);
            *p = *p + 1;
        } while (i < 2);
        gCur3DSpriteEngine = saved;
    }
    if (*data_02101e84 & 8) {
        if (!func_020ad3f0()) func_01ffa3dc(data_ov005_02220ad0, arg0);
    }
}

void func_ov005_0221efac(void) {
    M2C_UNK func_ov005_0221eef4();
    func_ov005_0221eef4();
}

void func_ov005_0221efb8(void) {
    M2C_UNK func_0208f780(s32);
    extern u16 data_02168f14;
    extern void **gCurrentMap;
    s32 var_r0;
    u16 temp_r1;

    var_r0 = 0x10017;
    if (!(((u32) (data_02168f14 << 0x1D) >> 0x1D) & 0xFF)) {
        temp_r1 = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
        if ((s32) temp_r1 <= 0xB0) {
            if (((s32) temp_r1 < 0xB0) && (temp_r1 != 0xAA)) {

            } else {
                goto block_9;
            }
        } else if ((s32) temp_r1 <= 0xB5) {
            if (temp_r1 != 0xB5) {

            } else {
                goto block_9;
            }
        } else if (temp_r1 == 0xBA) {
block_9:
            var_r0 = 0x10018;
        }
    }
    func_0208f780(var_r0);
}

void func_ov005_0221f038(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    s32 func_02081070(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220a44;
    extern M2C_UNK data_ov005_02220a6c;
    extern M2C_UNK data_ov005_02220d50;
    extern M2C_UNK data_ov005_02220fe0;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_ov005_02220d50, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov005_02220fe0;
    func_0200bc5c(&data_ov005_02220a44);
    M2C_FIELD(temp_r0, s32 *, 0x34) = func_02081070(&data_ov005_02220a6c, 1);
}

void func_ov005_0221f084(void *arg0) {
    M2C_UNK func_0207c650(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02080cfc(s32, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(M2C_UNK *, s32);
    s32 func_020815bc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208232c();
    M2C_UNK func_02082340(M2C_UNK, u16 *);
    M2C_UNK func_02082cb4();
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02091cd0();
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    M2C_UNK func_020ab150(void *, M2C_UNK);
    void *func_020ab1c4(void *);
    s32 func_020e3218(M2C_UNK *);
    extern void **data_027e00c4;
    extern void **data_027e00c8;
    extern void *data_027e01d8;
    extern u16 data_ov005_02220078;
    extern M2C_UNK data_ov005_02221230;
    extern M2C_UNK data_ov005_02221238;
    extern M2C_UNK data_ov005_0222124c;
    extern M2C_UNK data_ov005_02221260;
    extern M2C_UNK data_ov005_02221274;
    extern M2C_UNK data_ov005_02221288;
    extern M2C_UNK data_ov005_0222129c;
    extern M2C_UNK data_ov005_022212b0;
    extern M2C_UNK data_ov005_022212c4;
    extern M2C_UNK data_ov005_022212d4;
    extern M2C_UNK data_ov005_022212e4;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 sp8;
    s16 temp_r5;
    s16 temp_r6;
    s32 var_r0_2;
    s32 var_r9;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 temp_r7;
    void *temp_r11;
    void *temp_r4;
    void *var_r0;

    sp8 = data_ov005_02220078;
    func_02082cb4();
    func_02091cd0();
    func_0200bc5c(&data_ov005_02221230);
    temp_r11 = data_027e01d8;
    var_r9 = 0;
    do {
        if (var_r9 == 0) {
            var_r0 = data_027e00c8;
        } else {
            var_r0 = data_027e00c4;
        }
        data_027e01d8 = var_r0;
        func_0208232c();
        func_02082340(3, &sp8);
        var_r9 += 1;
        temp_r0 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp1C = temp_r0;
        *temp_r0 = *sp1C & ~0x10;
        temp_r0_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp18 = temp_r0_2;
        *temp_r0_2 = *sp18 & ~0x20;
        temp_r0_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp14 = temp_r0_3;
        *temp_r0_3 = *sp14 & ~0x40;
        temp_r0_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp10 = temp_r0_4;
        *temp_r0_4 = *sp10 | 0x80;
        temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        spC = temp_r0_5;
        *temp_r0_5 = *spC | 0x100;
    } while (var_r9 < 2);
    data_027e01d8 = data_027e00c8;
    func_020814e4(&data_ov005_02221238);
    func_02081590(&data_ov005_0222124c, M2C_FIELD(data_027e01d8, s32 *, 0x18));
    func_02081590(&data_ov005_02221260, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x3C) = func_020815bc(&data_ov005_02221274, 0x200);
    func_0207c650(M2C_FIELD(arg0, s32 *, 0x3C), 3, 0, 0x200, 0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    func_02081528();
    func_02080cfc(func_020e3218(&data_ov005_02221288), M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800);
    func_0208116c(&data_ov005_0222129c, 0x2C0, 0x20);
    data_027e01d8 = data_027e00c4;
    func_020814e4(&data_ov005_022212b0);
    func_02081590(&data_ov005_022212c4, M2C_FIELD(data_027e01d8, s32 *, 0x18));
    func_02081590(&data_ov005_022212d4, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x40) = func_020815bc(&data_ov005_022212e4, 0x200);
    func_0207c650(M2C_FIELD(arg0, s32 *, 0x40), 3, 0, 0x200, 0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    func_02081528();
    data_027e01d8 = data_027e00c8;
    M2C_FIELD(arg0, void **, 0x34) = func_020ab1c4(arg0);
    func_020aab24(M2C_FIELD(arg0, void **, 0x34), 1, 0x120, 3, 1);
    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    func_02088e84(temp_r4, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r5 = M2C_FIELD(temp_r4, s16 *, 0x52);
        temp_r6 = M2C_FIELD(temp_r4, s16 *, 0x50);
        temp_r7 = func_020aae10(temp_r4);
        func_02087d84(M2C_FIELD(temp_r4, void **, 0x64), 1, temp_r6, temp_r5, (s32) temp_r7, (s32) func_020aae44(temp_r4));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x34), 1);
    func_020aad18(M2C_FIELD(arg0, void **, 0x34));
    func_02088da8(M2C_FIELD(arg0, void **, 0x34));
    data_027e01d8 = temp_r11;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
}

void func_ov005_0221f3e8(void *arg0) {
    M2C_UNK func_01ffa6fc();
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    s32 temp_r1;

    if (*data_02101e84 & 0xC0B) {
        func_01ffa6fc();
        return;
    }
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
        func_01ffa6fc();
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r1 < 0x84) {
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) (temp_r1 + 1);
    }
}

void func_ov005_0221f448(void *arg0) {
    s32 func_020e35cc(s32);
    extern void **data_027e00c4, **data_027e00c8, **gCur3DSpriteEngine;
    u16 *volatile p;
    void **saved;
    s32 i;
    void **chosen;
    i = 0;
    saved = gCur3DSpriteEngine;
    do {
        if (i == 0) chosen = data_027e00c8;
        else chosen = data_027e00c4;
        i++;
        gCur3DSpriteEngine = chosen;
        p = (u16 *)((u8 *)*chosen + 0x12);
        *p = *p & ~0xC0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x51) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x52) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x53) = 0;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x3C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x40));
}

