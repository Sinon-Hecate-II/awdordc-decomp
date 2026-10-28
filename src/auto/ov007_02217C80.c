/* 8 functions from 0x02217C80 to 0x02218AD0 (ov007), found by ds-decomp. */
#include "common.h"

s32 func_ov007_02217c80(void *arg0) {
    s32 func_ov007_02217c50(void *);
    s32 result = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x38) + 1;
    if (result >= func_ov007_02217c50(arg0)) result = 0;
    return result;
}

s32 func_ov007_02217ca8(void *arg0) {
    s32 func_ov007_02217c50(void *);
    s32 result = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x38) - 1;
    if (result < 0) result = func_ov007_02217c50(arg0) - 1;
    return result;
}

void func_ov007_02217cd0(void *arg0) {
    s8 *func_ov007_02217b64(u8);
    void func_01ffa8c4(void *, s32);
    u8 index;
    s8 *table;
    u8 mode;
    index = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x3A);
    table = func_ov007_02217b64(M2C_FIELD(arg0, u8 *, 0x37));
    mode = M2C_FIELD(arg0, u8 *, 0x37);
    switch (mode) {
    case 0:
        if (table[index * 5] == 15 && M2C_FIELD(arg0 + mode, u8 *, 0x38) == 4) return;
        break;
    case 1:
        break;
    }
    M2C_FIELD(arg0, u8 *, 0x36) = 1;
    func_01ffa8c4(arg0, 2);
}

s32 func_ov007_02217d30(void *arg0) {
    s8 *func_ov007_02217b64(u8);
    extern u32 *data_02101e84;
    u8 mode;
    u8 *table;
    u8 *indices;
    u16 *g;
    u8 idx;
    u8 x;
    u8 y;
    u16 flags;
    u8 candidate;

    mode = M2C_FIELD(arg0, u8 *, 0x37);
    table = (u8 *)func_ov007_02217b64(mode);
    indices = (u8 *)arg0 + 0x3A;
    g = (u16 *)(*data_02101e84);
    idx = indices[mode];
    x = table[idx * 5 + 1];
    y = table[idx * 5 + 2];
    flags = g[1];
    candidate = idx;

    if (flags & 0xF0) {
        u8 *ptr = table;
        s32 i = 0;
        u8 m40 = flags & 0x40;
        u8 m80 = flags & 0x80;
        u8 m20 = flags & 0x20;
        u8 m10 = flags & 0x10;
        s8 xm1 = (s8)(x - 1);
        s8 xp1 = (s8)(x + 1);
        u8 ym1 = y - 1;
        u8 yp1 = y + 1;
        if ((s8)*ptr >= 0) {
            do {
                if (m40 && ptr[1] == x && ptr[2] == ym1) candidate = (u8)i;
                if (m80 && ptr[1] == x && ptr[2] == yp1) candidate = (u8)i;
                if (m20 && ptr[2] == y && ptr[1] == (u8)xm1) candidate = (u8)i;
                if (m10 && ptr[2] == y && ptr[1] == (u8)xp1) candidate = (u8)i;
                i++;
                ptr += 5;
            } while ((s8)*ptr >= 0);
        }
    }

    {
        u16 flags2 = g[0];
        if ((flags2 & 0xF0) && candidate == idx) {
            u8 *ptr = table;
            s32 i = 0;
            u8 m40 = flags2 & 0x40;
            u8 m80 = flags2 & 0x80;
            u8 m20 = flags2 & 0x20;
            u8 m10 = flags2 & 0x10;
            u8 cur = candidate;
            if ((s8)*ptr >= 0) {
                do {
                    if (m40 && ptr[1] == x) {
                        u8 cb2 = table[cur * 5 + 2];
                        if (ptr[2] > cb2) cur = (u8)i;
                    }
                    if (m80 && ptr[1] == x) {
                        u8 cb2 = table[cur * 5 + 2];
                        if (ptr[2] < cb2) cur = (u8)i;
                    }
                    if (m20 && ptr[2] == y) {
                        u8 cb1 = table[cur * 5 + 1];
                        if (ptr[1] > cb1) cur = (u8)i;
                    }
                    if (m10 && ptr[2] == y) {
                        u8 cb1 = table[cur * 5 + 1];
                        if (ptr[1] < cb1) cur = (u8)i;
                    }
                    i++;
                    ptr += 5;
                } while ((s8)*ptr >= 0);
            }
            candidate = cur;
        }
    }

    if (candidate == idx) return 0;
    indices[mode] = candidate;
    return 1;
}

void func_ov007_02217f8c(void *arg0) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080cfc(s32, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02089424();
    void *func_020896f0(void *);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    M2C_UNK func_020ab150(void *, M2C_UNK);
    void *func_020ab1c4(void *);
    s32 func_020e3218(M2C_UNK *);
    s8 func_ov007_02211f00();
    s32 func_ov007_02211f30();
    M2C_UNK func_ov007_02211f40();
    s32 func_ov007_02211f90();
    M2C_UNK func_ov007_02211fa0();
    s8 func_ov007_02217b90(M2C_UNK, s32);
    s8 func_ov007_02217c1c();
    extern void *data_027e00c8;
    extern void *data_027e01d8;
    extern M2C_UNK data_ov007_02220030;
    extern M2C_UNK data_ov007_0222003c;
    extern M2C_UNK data_ov007_0222004c;
    extern M2C_UNK data_ov007_0222005c;
    extern M2C_UNK data_ov007_0222006c;
    extern M2C_UNK data_ov007_0222007c;
    extern M2C_UNK data_ov007_02220088;
    extern M2C_UNK data_ov007_02220094;
    extern M2C_UNK data_ov007_022200a0;
    u16 *sp2C;
    u16 *sp28;
    u16 *sp24;
    u16 *sp20;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 *sp8;
    s16 temp_r7;
    s16 temp_r7_2;
    s16 temp_r7_3;
    s16 temp_r8;
    s16 temp_r8_2;
    s16 temp_r8_3;
    s32 temp_r1;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r2;
    u16 temp_r9;
    u16 temp_r9_2;
    u16 temp_r9_3;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r2_4;
    void *temp_r2_5;
    void *temp_r2_6;
    void *temp_r5;
    void *temp_r6;
    void *temp_r6_2;
    void *temp_r6_3;
    var_r2 = 0;
    do {
        temp_r0 = arg0 + (var_r2 * 2);
        var_r2 += 1;
        M2C_FIELD(temp_r0, s16 *, 0x3C) = 0x100;
    } while (var_r2 < 3);
    M2C_FIELD(arg0, s8 *, 0x34) = 1;
    M2C_FIELD(arg0, s8 *, 0x35) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = func_ov007_02211f00();
    M2C_FIELD(arg0, s8 *, 0x3A) = func_ov007_02217b90(0, func_ov007_02211f90());
    M2C_FIELD(arg0, s8 *, 0x3B) = func_ov007_02217b90(1, func_ov007_02211f30());
    func_ov007_02211fa0();
    M2C_FIELD(arg0, s8 *, 0x38) = func_ov007_02217c1c();
    func_ov007_02211f40();
    M2C_FIELD(arg0, s8 *, 0x39) = func_ov007_02217c1c();
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s16 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    temp_r5 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    func_020a9a30(0, 2, 0x47, M2C_FIELD(data_027e00c8, s32 *, 0x30) + 0x260);
    M2C_FIELD(arg0, void **, 0x44) = func_020ab1c4(arg0);
    func_020aab24(M2C_FIELD(arg0, void **, 0x44), 0, 0x35C, 3, 0);
    temp_r6 = M2C_FIELD(arg0, void **, 0x44);
    func_02088e84(temp_r6, 0xC0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
        temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
        temp_r9 = func_020aae10(temp_r6);
        func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (s32) temp_r9, (s32) func_020aae44(temp_r6));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x44), 1);
    M2C_FIELD(arg0, void **, 0x48) = func_020ab1c4(arg0);
    func_020aab24(M2C_FIELD(arg0, void **, 0x48), 2, 0x36C, 3, 0);
    temp_r6_2 = M2C_FIELD(arg0, void **, 0x48);
    func_02088e84(temp_r6_2, 0xE0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(temp_r6_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r7_2 = M2C_FIELD(temp_r6_2, s16 *, 0x52);
        temp_r8_2 = M2C_FIELD(temp_r6_2, s16 *, 0x50);
        temp_r9_2 = func_020aae10(temp_r6_2);
        func_02087d84(M2C_FIELD(temp_r6_2, void **, 0x64), 1, temp_r8_2, temp_r7_2, (s32) temp_r9_2, (s32) func_020aae44(temp_r6_2));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x48), 2);
    M2C_FIELD(arg0, void **, 0x4C) = func_020ab1c4(arg0);
    func_020aab24(M2C_FIELD(arg0, void **, 0x4C), 0x14, 0x37C, 3, 0);
    temp_r6_3 = M2C_FIELD(arg0, void **, 0x4C);
    func_02088e84(temp_r6_3, 0xA0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(temp_r6_3, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        temp_r7_3 = M2C_FIELD(temp_r6_3, s16 *, 0x52);
        temp_r8_3 = M2C_FIELD(temp_r6_3, s16 *, 0x50);
        temp_r9_3 = func_020aae10(temp_r6_3);
        func_02087d84(M2C_FIELD(temp_r6_3, void **, 0x64), 1, temp_r8_3, temp_r7_3, (s32) temp_r9_3, (s32) func_020aae44(temp_r6_3));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x4C), 0x304);
    func_0200bc5c(&data_ov007_02220030);
    func_020e3218(&data_ov007_0222003c);
    func_020814e4();
    func_02081590(func_020e3218(&data_ov007_0222004c), M2C_FIELD(data_027e01d8, s32 *, 0x10));
    func_02081590(func_020e3218(&data_ov007_0222005c), M2C_FIELD(data_027e01d8, s32 *, 0x24));
    func_02081528();
    func_0208116c(&data_ov007_0222006c, 0, 0x20);
    M2C_FIELD(data_027e01d8, s16 *, 0x3A) = 0;
    M2C_FIELD(data_027e01d8, s16 *, 0x42) = 0;
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    func_02080cfc(func_020e3218(&data_ov007_0222007c), M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x7380);
    func_0208116c(&data_ov007_02220088, 0x200, 0x20);
    func_0200bc5c(&data_ov007_02220094);
    func_0208116c(&data_ov007_022200a0, 0x240, 0x20);
    M2C_FIELD(arg0, void **, 0x50) = func_020896f0(arg0);
    func_02089424();
    func_02088da8(M2C_FIELD(arg0, void **, 0x50));
    temp_r2 = M2C_FIELD(arg0, void **, 0x50);
    M2C_FIELD(temp_r2, s32 *, 0x40) = (s32) ((((M2C_FIELD(temp_r2, s32 *, 0x40) & ~0x1FF) | 0x10) & 0xFFFC01FF) | 0x2000);
    M2C_FIELD(arg0, void **, 0x54) = func_020896f0(arg0);
    func_02089424();
    func_02088da8(M2C_FIELD(arg0, void **, 0x54));
    temp_r2_2 = M2C_FIELD(arg0, void **, 0x54);
    temp_r1 = (M2C_FIELD(temp_r2_2, s32 *, 0x40) & ~0x1FF) | 0x10;
    M2C_FIELD(temp_r2_2, s32 *, 0x40) = temp_r1;
    M2C_FIELD(temp_r2_2, s32 *, 0x40) = (s32) ((temp_r1 & 0xFFFC01FF) | 0x2000);
    temp_r0_2 = M2C_FIELD(data_027e01d8, void **, 0);
    sp2C = temp_r0_2 + 0x12;
    M2C_FIELD(temp_r0_2, s16 *, 0x12) = (s16) (*sp2C & ~1);
    temp_r0_3 = M2C_FIELD(data_027e01d8, void **, 0);
    sp28 = temp_r0_3 + 0x12;
    M2C_FIELD(temp_r0_3, s16 *, 0x12) = (s16) (*sp28 | 2);
    temp_r0_4 = M2C_FIELD(data_027e01d8, void **, 0);
    sp24 = temp_r0_4 + 0x12;
    M2C_FIELD(temp_r0_4, s16 *, 0x12) = (s16) (*sp24 & ~4);
    temp_r0_5 = M2C_FIELD(data_027e01d8, void **, 0);
    sp20 = temp_r0_5 + 0x12;
    M2C_FIELD(temp_r0_5, s16 *, 0x12) = (s16) (*sp20 & ~8);
    temp_r0_6 = M2C_FIELD(data_027e01d8, void **, 0);
    sp1C = temp_r0_6 + 0x12;
    M2C_FIELD(temp_r0_6, s16 *, 0x12) = (s16) (*sp1C & ~0x10);
    temp_r0_7 = M2C_FIELD(data_027e01d8, void **, 0);
    sp18 = temp_r0_7 + 0x12;
    M2C_FIELD(temp_r0_7, s16 *, 0x12) = (s16) (*sp18 | 0x100);
    temp_r2_3 = M2C_FIELD(data_027e01d8, void **, 0);
    sp14 = temp_r2_3 + 0x12;
    M2C_FIELD(temp_r2_3, s16 *, 0x12) = (s16) (*sp14 & ~0x200);
    temp_r2_4 = M2C_FIELD(data_027e01d8, void **, 0);
    sp10 = temp_r2_4 + 0x12;
    M2C_FIELD(temp_r2_4, s16 *, 0x12) = (s16) (*sp10 & ~0x400);
    temp_r2_5 = M2C_FIELD(data_027e01d8, void **, 0);
    spC = temp_r2_5 + 0x12;
    M2C_FIELD(temp_r2_5, s16 *, 0x12) = (s16) (*spC & ~0x800);
    temp_r2_6 = M2C_FIELD(data_027e01d8, void **, 0);
    sp8 = temp_r2_6 + 0x12;
    M2C_FIELD(temp_r2_6, s16 *, 0x12) = (s16) (*sp8 & ~0x1000);
    data_027e01d8 = temp_r5;
    func_0208fe30(0x10017);
}

void func_ov007_02218570(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_ov007_02211ea4(u8);
    M2C_UNK func_ov007_02211f10(M2C_UNK);
    M2C_UNK func_ov007_02211f60();
    M2C_UNK func_ov007_02211f70();
    M2C_UNK func_ov007_02211fb0();
    M2C_UNK func_ov007_02211fc0();
    M2C_UNK func_ov007_02217bd0(M2C_UNK, u8);
    M2C_UNK func_ov007_02217be8(M2C_UNK, u8, u8);
    M2C_UNK func_ov007_0221ab4c();
    u8 temp_r0;
    void *temp_r2;
    void *temp_r2_2;

    if (M2C_FIELD(arg0, u8 *, 0x36) != 0) {
        func_ov007_02211ea4(M2C_FIELD(arg0, u8 *, 0x37));
        func_ov007_02211f10(0);
        temp_r0 = M2C_FIELD(arg0, u8 *, 0x37);
        switch (temp_r0) {                          /* irregular */
        case 0:
            func_ov007_02217bd0(0, M2C_FIELD((arg0 + temp_r0), u8 *, 0x3A));
            func_ov007_02211fb0();
            temp_r2 = arg0 + M2C_FIELD(arg0, u8 *, 0x37);
            func_ov007_02217be8(0, M2C_FIELD(temp_r2, u8 *, 0x3A), M2C_FIELD(temp_r2, u8 *, 0x38));
            func_ov007_02211fc0();
            break;
        case 1:
            func_ov007_02217bd0(1, M2C_FIELD((arg0 + temp_r0), u8 *, 0x3A));
            func_ov007_02211f60();
            temp_r2_2 = arg0 + M2C_FIELD(arg0, u8 *, 0x37);
            func_ov007_02217be8(1, M2C_FIELD(temp_r2_2, u8 *, 0x3A), M2C_FIELD(temp_r2_2, u8 *, 0x38));
            func_ov007_02211f70();
            break;
        }
        func_ov007_0221ab4c();
        func_0208fe30(0x10016);
    } else {
        func_0208fe30(0x1000F);
    }
    M2C_FIELD(arg0, s8 *, 0x35) = 1;
}

void func_ov007_0221863c(void *arg0) {
}

void func_ov007_02218a60(void *arg0) {
    M2C_UNK func_02082040(void *);
    M2C_UNK func_020a40c0(u8);
    M2C_UNK func_020e35cc(s32);
    extern void **gCurrentMap;
    void *temp_r4;
    void *temp_r4_2;

    temp_r4 = M2C_FIELD(arg0, void **, 0x58);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    M2C_FIELD(arg0, void **, 0x58) = NULL;
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x5C);
    if (temp_r4_2 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4_2, s32 *, 0x14));
        func_02082040(temp_r4_2);
    }
    M2C_FIELD(arg0, void **, 0x5C) = NULL;
    func_020a40c0(M2C_FIELD(*gCurrentMap, u8 *, 0x5158));
}
