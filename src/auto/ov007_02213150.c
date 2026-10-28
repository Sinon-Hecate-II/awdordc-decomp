/* 22 functions from 0x02213150 to 0x02213E88 (ov007), found by ds-decomp. */
#include "common.h"

/* Refreshes 8 sprites for the current mode, then runs mode post-processing. */
void func_ov007_02213150(void) {
    M2C_UNK func_02088eec(s32, M2C_UNK);
    M2C_UNK func_ov007_02212dcc();
    void func_ov007_0221327c();
    extern M2C_UNK data_ov007_02221a50;
    s32 mode;

    func_ov007_0221327c();
    mode = func_ov007_02211f00();
    if (mode != 0) {
        if (mode == 1) {
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 8), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 4), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0xC), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x10), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x14), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x18), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x1C), 6);
        }
    } else {
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 8), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 4), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x20), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x24), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x28), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x2C), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x30), 6);
    }
    func_ov007_02212dcc();
}

void func_ov007_0221327c(void) {
    M2C_UNK func_02088fc4(s32, M2C_UNK);
    s32 func_02089064(s32);
    extern M2C_UNK data_ov007_02221a50;
    s32 i;
    i = 0;
    do {
        if (func_02089064(((s32 *)&data_ov007_02221a50)[i]) != 0)
            func_02088fc4(((s32 *)&data_ov007_02221a50)[i], 4);
        i++;
    } while (i < 13);
}

void func_ov007_022132bc(void) {
    M2C_UNK func_ov007_02211ea4(M2C_UNK);
    s32 func_ov007_02211f00();
    M2C_UNK func_ov007_02211f10(M2C_UNK);
    M2C_UNK func_ov007_0221ab4c();
    s32 temp_r0;

    temp_r0 = func_ov007_02211f00();
    if (temp_r0 != 0) {
        if (temp_r0 == 1) {
            func_ov007_02211ea4(0);
            func_ov007_02211f10(0);
        }
    } else {
        func_ov007_02211ea4(1);
        func_ov007_02211f10(0);
    }
    func_ov007_0221ab4c();
    func_0208fe30(0x10020);
}

void func_ov007_0221330c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f6b0;
    func_01ffa3dc(&data_ov007_0221f6b0, 7);
}

u8 func_ov007_02213324(void) {
    s32 func_020c7eb8(u16);
    extern void **gCurrentMap;
    u8 var_r0;

    if (func_020c7eb8(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov007_02213358(void) {
    return 2;
}

void func_ov007_02213360(void) {
    M2C_UNK func_ov007_0221c51c();
    func_ov007_0221c51c();
}

void func_ov007_0221336c(void) {
    M2C_UNK func_ov007_0221c630();
    func_ov007_0221c630();
}

void func_ov007_02213378(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020cfd28();
    M2C_UNK func_ov007_022121b0();
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_ov007_02214864(s32);
    M2C_UNK func_ov007_0221ab68();
    func_ov007_02214864(M2C_FIELD(arg0, s32 *, 0x5C));
    func_020cfd28();
    func_ov007_022121b0();
    func_ov007_0221ab68();
    func_ov007_022121d4(1);
    func_0208fe30(0x11D);
}

void func_ov007_022133a8(s32 arg0, s32 arg1) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void func_02086720(s32);
    extern M2C_UNK data_ov007_0221f7c0;
    func_02086720(arg0);
    M2C_FIELD(func_01ffa3dc(&data_ov007_0221f7c0, 7), s32 *, 0x5C) = arg1;
}

void func_ov007_022133cc(void) {
    void func_ov007_022133a8(M2C_UNK, M2C_UNK);
    func_ov007_022133a8(0x46000000, 8);
}

void func_ov007_022133e0(void) {
    func_ov007_022133a8(0x46000001, 1);
}

void func_ov007_022133f8(void) {
    func_ov007_022133a8(0x46000002, 4);
}

void func_ov007_02213410(void) {
    func_ov007_022133a8(0x46000003, 3);
}

void func_ov007_02213428(void) {
    func_ov007_022133a8(0x46000004, -1);
}

void func_ov007_02213440(M2C_UNK arg0, M2C_UNK arg1) {
M2C_UNK func_020c0b88(M2C_UNK);
M2C_UNK func_020c0b40();
func_020c0b88(arg1);
func_020c0784();
func_020c0b40();
}

void func_ov007_02213458(void) {
    M2C_UNK func_020c0adc();
    M2C_UNK func_020c0784();
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020cfd28();
    s32 func_020c0b9c();
    M2C_UNK func_020c0634(M2C_UNK *, s32, s32, u16, s32);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_0221fa40;
    func_020c0adc();
    func_020c0784();
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    func_020cfd28();
    func_020c0634(&data_ov007_0221fa40, 0x60, 0x30, (u16)func_020c0b9c(), 0x50);
}

void func_ov007_022134b4(void *arg0) {
    M2C_UNK func_ov007_02214a6c(s32, s32);
    M2C_UNK func_0207b754(u32, u32);
    M2C_UNK func_0207cfc0(void *);
    extern void **gCurrentMap;
    void *p;
    func_ov007_02214a6c(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C));
    func_020cfd28();
    func_ov007_022121b0();
    func_ov007_0221ab68();
    func_ov007_022121d4(1);
    p = *gCurrentMap;
    func_0207b754((u32)M2C_FIELD(p, u16 *, 0x5144) >> 1, (u32)M2C_FIELD(p, u16 *, 0x5146) >> 1);
    func_0207cfc0((u8 *)*gCurrentMap + 0x6EF8);
    func_0208fe30(0x11D);
}

void func_ov007_0221352c(s32 arg0, s32 arg1) {
    extern M2C_UNK data_ov007_0221f740;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov007_0221f740, 7);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg1;
}

#pragma opt_lifetimes off
#pragma scheduling off
void func_ov007_02213554(void *arg0) {
    M2C_UNK func_0200bc5c(M2C_UNK);
    void *func_020e3218(M2C_UNK);
    void func_020814e4(M2C_UNK);
    void func_02081590(M2C_UNK, M2C_UNK);
    void func_02081528(void);
    void func_0208116c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020896f0(M2C_UNK);
    void func_02089424(void);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void *func_020ab1c4(M2C_UNK);
    void func_020aab24(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02088e84(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020aae10(M2C_UNK);
    M2C_UNK func_020aae44(M2C_UNK);
    void func_02087d84(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020ab150(M2C_UNK, M2C_UNK);
    void func_02088f1c(M2C_UNK);
    extern M2C_UNK data_ov007_0221fdb0, data_ov007_0221fdbc, data_ov007_0221fdcc, data_ov007_0221fdd8, data_ov007_0221fde4;
    extern void *gCur3DSpriteEngine;
    extern void **gCurrentMap;

    s32 r4 = (s32) arg0;
    s32 r5;
    s32 r6 = 0x39C;

    func_0200bc5c(&data_ov007_0221fdb0);
    M2C_FIELD(*(void **) gCur3DSpriteEngine, u16 *, 0x3A) = 0;
    M2C_FIELD(*(void **) gCur3DSpriteEngine, u16 *, 0x42) = 0;
    func_020814e4(func_020e3218(&data_ov007_0221fdbc));
    func_02081590(func_020e3218(&data_ov007_0221fdcc), M2C_FIELD(gCur3DSpriteEngine, void **, 0x10));
    func_02081590(func_020e3218(&data_ov007_0221fdd8), M2C_FIELD(gCur3DSpriteEngine, void **, 0x24));
    func_02081528();
    func_0208116c(&data_ov007_0221fde4, 0, 0x20);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(r4, s32 *, 0x34) = M2C_FIELD(M2C_FIELD(*gCurrentMap, s32 *, 0), u16 *, 0x5144);
    M2C_FIELD(r4, s32 *, 0x38) = M2C_FIELD(M2C_FIELD(*gCurrentMap, s32 *, 0), u16 *, 0x5146);
    M2C_FIELD(r4, s32 *, 0x3C) = 0;
    func_020896f0(r4);
    func_02089424();
    func_020a9a30(1, 0, 3, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x6B80);
    func_020a9a30(1, 2, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x360);
    func_020a9a30(0, 2, 0x47, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x260);
    M2C_FIELD(r4, void **, 0x40) = func_020ab1c4(r4);
    func_020aab24(M2C_FIELD(r4, void **, 0x40), 8, r6, 3, 0);
    r5 = M2C_FIELD(r4, void **, 0x40);
    func_02088e84(r5, 0x58, 0x50, 0x58, 0x50);
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    M2C_FIELD(r5, u16 *, 0x34) = 0x58;
    M2C_FIELD(r5, u16 *, 0x36) = 0x50;
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    func_020ab150(M2C_FIELD(r4, void **, 0x40), 0);
    r6 = (r6 + 8) & 0xFFFF;
    M2C_FIELD(r4, void **, 0x44) = func_020ab1c4(r4);
    func_020aab24(M2C_FIELD(r4, void **, 0x44), 9, r6, 3, 0);
    r5 = M2C_FIELD(r4, void **, 0x44);
    func_02088e84(r5, 0x58, 0x70, 0x58, 0x70);
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    M2C_FIELD(r5, u16 *, 0x34) = 0x58;
    M2C_FIELD(r5, u16 *, 0x36) = 0x70;
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    func_020ab150(M2C_FIELD(r4, void **, 0x44), 0);
    r6 = (r6 + 8) & 0xFFFF;
    M2C_FIELD(r4, void **, 0x48) = func_020ab1c4(r4);
    func_020aab24(M2C_FIELD(r4, void **, 0x48), 8, r6, 3, 0);
    r5 = M2C_FIELD(r4, void **, 0x48);
    func_02088e84(r5, 0x88, 0x50, 0x88, 0x50);
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    M2C_FIELD(r5, u16 *, 0x34) = 0x88;
    M2C_FIELD(r5, u16 *, 0x36) = 0x50;
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    func_020ab150(M2C_FIELD(r4, void **, 0x48), 0);
    r6 = (r6 + 8) & 0xFFFF;
    M2C_FIELD(r4, void **, 0x4C) = func_020ab1c4(r4);
    func_020aab24(M2C_FIELD(r4, void **, 0x4C), 9, r6, 3, 0);
    r5 = M2C_FIELD(r4, void **, 0x4C);
    func_02088e84(r5, 0x88, 0x70, 0x88, 0x70);
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    M2C_FIELD(r5, u16 *, 0x34) = 0x88;
    M2C_FIELD(r5, u16 *, 0x36) = 0x70;
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    func_020ab150(M2C_FIELD(r4, void **, 0x4C), 0);

    r6 = (r6 + 8) & 0xFFFF;
    r5 = (s32) func_020ab1c4(r4);
    func_020aab24(r5, 0, r6, 3, 0);
    func_02088e84(r5, 0xC0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(r5, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r5, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r5, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r5);
        u16 t0 = (u16) func_020aae44(r5);
        func_02087d84(M2C_FIELD(r5, void **, 0x64), 1, t8, t7, t9, t0);
    }
    func_020ab150(r5, 1);
    func_02088f1c(r5);

    {
        s32 size6 = (r6 + 0x10) & 0xFFFF;
        r6 = (s32) func_020ab1c4(r4);
        func_020aab24(r6, 2, size6, 3, 0);
    }
    func_02088e84(r6, 0xE0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(r6, void **, 0x64), u8 *, 0x12)) {
        s16 t7 = (s16) M2C_FIELD(r6, s16 *, 0x52);
        s16 t8 = (s16) M2C_FIELD(r6, s16 *, 0x50);
        u16 t9 = (u16) func_020aae10(r6);
        u16 t0 = (u16) func_020aae44(r6);
        func_02087d84(M2C_FIELD(r6, void **, 0x64), 1, t8, t7, t9, t0);
    }
    func_020ab150(r6, 2);
    func_02088f1c(r6);
}
#pragma scheduling reset
#pragma opt_lifetimes reset
void func_ov007_02213cf4(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

/* Configures the 3D sprite engine for the requested unit selection mode (arg0->0x3c, 0 or 1), then draws a tile-selection panel sprite via func_020a94fc. */
void func_ov007_02213d1c(void *obj) {
    void *func_02089714(void);
    extern u8 data_02129870[];
    u32 sp[11];
    void *engine = func_02089714();
    switch (M2C_FIELD(obj, s32 *, 0x3c)) {
    case 0:
        M2C_FIELD(engine, s16 *, 0x34) = 0x5c;
        M2C_FIELD(engine, s16 *, 0x36) = 0x60;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & ~0x1ff) | 0x18;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & 0xfffc01ff) | 0x2000;
        break;
    case 1:
        M2C_FIELD(engine, s16 *, 0x34) = 0x8c;
        M2C_FIELD(engine, s16 *, 0x36) = 0x60;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & ~0x1ff) | 0x18;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & 0xfffc01ff) | 0x2000;
        break;
    }
    M2C_FIELD(sp, void **, 0) = data_02129870;
    M2C_FIELD(sp, u8 *, 4) = 0;
    M2C_FIELD(sp, u8 *, 0x14) = 8;
    M2C_FIELD(sp, u8 *, 0x15) = 8;
    M2C_FIELD(sp, u8 *, 0x16) = 1;
    M2C_FIELD(sp, u8 *, 0x17) = 8;
    M2C_FIELD(sp, u8 *, 0x18) = 8;
    M2C_FIELD(sp, u8 *, 0x20) = ((u8)((u8)(M2C_FIELD(sp, u8 *, 0x20) & ~1) & ~0x1e) & ~0xe0) | 0x40;
    M2C_FIELD(sp, u32 *, 0x24) = 0;
    M2C_FIELD(sp, u8 *, 0x29) = 0;
    M2C_FIELD(sp, u16 *, 0x12) = 0x35c;
    M2C_FIELD(sp, u8 *, 0x21) = 11;
    M2C_FIELD(sp, u8 *, 0x28) = ((u8)(M2C_FIELD(sp, u8 *, 0x28) & ~0xe0) & ~0x1f) | 0x11;
    func_020a947c(sp, 3);
    func_020a92bc(sp, M2C_FIELD(obj, s32 *, 0x34));
    M2C_FIELD(sp, s16 *, 6) = 0x75;
    M2C_FIELD(sp, s16 *, 8) = 0x60;
    func_020a94fc(sp);
    func_020a92bc(sp, M2C_FIELD(obj, s32 *, 0x38));
    M2C_FIELD(sp, s16 *, 6) = 0xa5;
    M2C_FIELD(sp, s16 *, 8) = 0x60;
    func_020a94fc(sp);
}

