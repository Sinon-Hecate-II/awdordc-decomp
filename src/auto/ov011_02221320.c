/* 9 functions from 0x02221320 to 0x02222204 (ov011), found by ds-decomp. */
#include "common.h"

void func_ov011_02221320(void *arg0, s32 arg1) {
    extern M2C_UNK data_ov011_02228294;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov011_02228294;
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
}

void func_ov011_02221334(void) {

}

s32 func_ov011_02221338(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov011_0222134c(void *arg0) {
    M2C_UNK func_020822b8(u16 *);
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov011_02227f08;
    typedef struct { u16 a, b, c, d, e, f; } T;
    T first;
    T second;
    s32 temp_r4;
    first = M2C_FIELD(&data_ov011_02227f08, T *, 0x12);
    temp_r4 = gCur3DSpriteEngine;
    second = M2C_FIELD(&data_ov011_02227f08, T *, 6);
    gCur3DSpriteEngine = data_027e00c8;
    func_020822b8((u16 *)&first);
    gCur3DSpriteEngine = data_027e00c4;
    func_020822b8((u16 *)&second);
    gCur3DSpriteEngine = temp_r4;
}

void func_ov011_0222140c(void *arg0) {
    M2C_UNK func_02082c84(void);
    M2C_UNK func_020026d8(s32);
    M2C_UNK func_02003124(s32);
    M2C_UNK func_020031cc(s32);
    M2C_UNK func_02002968(s32);
    M2C_UNK func_02002ab8(s32);
    M2C_UNK func_0200323c(s32);
    M2C_UNK func_020032bc(s32);
    M2C_UNK func_020aca8c(void);
    M2C_UNK func_02082770(void);
    M2C_UNK func_01ff9b38(void);
    void func_ov011_0222134c(void *);
    void func_ov011_0222161c(void *);

    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;

    s32 saved;
    s32 i;

    func_02082c84();
    func_020026d8(3);
    func_02003124(4);
    func_020031cc(8);
    func_02002968(0x10);
    func_02002ab8(0x60);
    func_0200323c(0x80);
    func_020032bc(0x100);
    func_ov011_0222134c(arg0);

    saved = gCur3DSpriteEngine;
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            gCur3DSpriteEngine = data_027e00c8;
        } else {
            gCur3DSpriteEngine = data_027e00c4;
        }
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine |= 0x10;
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine |= 0x20;
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine |= 0x40;
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine |= 0x80;
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine |= 0x100;
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine &= (u16)~0x200;
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine &= (u16)~0x400;
        *(volatile u16 *)*(s32 *)gCur3DSpriteEngine &= (u16)~0x800;
        *(volatile u16 *)((char *)*(s32 *)gCur3DSpriteEngine + 0x12) &= (u16)~0xC0;
        *(volatile u8 *)((char *)*(s32 *)gCur3DSpriteEngine + 0x51) = 0;
        *(volatile u8 *)((char *)*(s32 *)gCur3DSpriteEngine + 0x52) = 0;
        *(volatile u8 *)((char *)*(s32 *)gCur3DSpriteEngine + 0x53) = 0;
        *(volatile u16 *)((char *)gCur3DSpriteEngine + 0x44) = 0;
        func_020aca8c();
        func_02082770();
        func_01ff9b38();
    }
    gCur3DSpriteEngine = saved;
    *((u8 *)arg0 + 0x38) = 0;
    func_ov011_0222161c(arg0);
}

void func_ov011_0222161c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0) {
        M2C_FIELD(arg0, s16 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x39) = 0;
        M2C_FIELD(arg0, s8 *, 0x36) = 0;
        M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
        M2C_FIELD(arg0, u8 *, 0x38) = 1U;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x34) = 0x20;
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
    M2C_FIELD(arg0, u8 *, 0x38) = 2U;
}

void func_ov011_0222166c(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 temp_r1;
    if (M2C_FIELD(arg0, u8 *, 0x39) == 0) {
        temp_r1 = M2C_FIELD(arg0, s32 *, 0x3C);
        if (temp_r1 == 1) {
            M2C_FIELD(arg0, u8 *, 0x38) = 2;
            M2C_FIELD(arg0, s16 *, 0x34) = 0x10;
            func_01ffa8c4(arg0, 2);
            return;
        }
        if (temp_r1 != 2) {
            M2C_FIELD(arg0, u8 *, 0x38) = 1;
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x38) = 3;
        func_01ffa8c4(arg0, 6);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 2) return;
    func_01ffa8c4(arg0, 4);
}

void func_ov011_02222010(s32 unused, u32 arg0, s32 arg1) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080cfc(M2C_UNK *, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020812a4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK *func_020e3218(M2C_UNK *);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern M2C_UNK data_ov011_02228934;
    extern M2C_UNK data_ov011_02228940;
    extern M2C_UNK data_ov011_02228950;
    extern M2C_UNK data_ov011_02228960;
    extern M2C_UNK data_ov011_02228970;
    extern M2C_UNK data_ov011_02228980;
    extern M2C_UNK data_ov011_02228994;
    extern M2C_UNK data_ov011_022289a4;
    extern M2C_UNK data_ov011_022289b8;
    extern M2C_UNK data_ov011_022289c8;
    extern M2C_UNK data_ov011_022289dc;
    extern M2C_UNK data_ov011_022289ec;
    extern M2C_UNK data_ov011_02228a00;
    extern M2C_UNK data_ov011_02228a10;
    extern M2C_UNK data_ov011_02228a20;

    s32 saved_r5;
    s32 var_r6;
    s32 var_r7;

    func_0200bc5c(&data_ov011_02228934);

    saved_r5 = gCur3DSpriteEngine;

    var_r6 = 0;
    do {
        if (var_r6 == 0) {
            var_r7 = data_027e00c8;
        } else {
            var_r7 = data_027e00c4;
        }

        gCur3DSpriteEngine = var_r7;

        if (arg1 == 0 && var_r7 != data_027e00c8) goto inc;
        if (arg1 == 1 && var_r7 != data_027e00c4) goto inc;
        if (arg1 == 3 && var_r7 != saved_r5) goto inc;

        switch (arg0) {
            case 0:
                func_02080cfc(func_020e3218(&data_ov011_02228940), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_02228950, 0x200, 0x20);
                break;
            case 1:
                func_02080cfc(&data_ov011_02228960, M2C_FIELD(var_r7, s32 *, 0x1C) + 0x800);
                func_0208116c(&data_ov011_02228970, 0x2C0, 0x20);
                break;
            case 3:
                func_02080cfc(func_020e3218(&data_ov011_02228980), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_02228994, 0x200, 0x20);
                break;
            case 4:
                func_02080cfc(func_020e3218(&data_ov011_022289a4), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_022289b8, 0x200, 0x20);
                break;
            case 5:
                func_02080cfc(func_020e3218(&data_ov011_022289c8), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_022289dc, 0x200, 0x20);
                break;
            case 6:
                func_02080cfc(func_020e3218(&data_ov011_022289ec), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_02228a00, 0x200, 0x20);
                break;
            case 7:
                func_02080cfc(&data_ov011_02228a10, M2C_FIELD(var_r7, s32 *, 0x1C));
                func_020812a4(&data_ov011_02228a20, 0, 0, 0x200);
                break;
            default:
                break;
        }

inc:
        var_r6 += 1;
    } while (var_r6 < 2);

    gCur3DSpriteEngine = saved_r5;
}

