/* 13 functions from 0x020BAC24 to 0x020BBBBC (main), found by ds-decomp. */
#include "common.h"

void func_020bac24(void) {
    extern void **gCurrentMap;
    (void)gCurrentMap;
}

void func_020bb028(void) {
    M2C_UNK func_020bf858();
    M2C_UNK func_020cfd28();
    M2C_UNK func_ov000_021696d4();
    func_020bf858();
    func_ov000_021696d4();
    func_020cfd28();
}

void func_020bb03c(void) {
    M2C_UNK func_020baa64();
    M2C_UNK func_020babfc(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020ce630(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020cfd28();
    extern void **gCurrentMap;

    func_020baa64();
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52D0), u8 *, 1) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52D0), u8 *, 2) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
    func_020babfc(
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E0),
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*gCurrentMap + 0x5388));
    func_020ce630(
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E0),
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*gCurrentMap + 0x5388));
    func_020cfd28();
}

void func_020bb0d0(M2C_UNK arg0) {
    M2C_UNK func_0209ecf0(M2C_UNK, M2C_UNK);
    void func_020bb03c(void);
    func_020bb03c();
    func_0209ecf0(arg0, 0);
}

void func_020bb0ec(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0209ea20(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020bb03c();
    func_0209ea20(arg0, arg1, 0);
}

void func_020bb110(void) {
}

void func_020bb458(void) {
    s32 func_020d19b4(u16);
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    M2C_UNK func_020baa64(void);
    M2C_UNK func_020babfc(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020ce630(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0208fb0c(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;

    u8 *unit;

    if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c20(0x13, 1);
    }
    unit = (u8 *)*gCurrentMap + 0x59A4 +
        ((u8 *)*gCurrentMap)[
            M2C_FIELD(*gCurrentMap, s16 *, 0x52DE) * 0 +
            M2C_FIELD(*gCurrentMap, s16 *, 0x52DC) +
            M2C_FIELD(*gCurrentMap, u16 *, 0x3758 + M2C_FIELD(*gCurrentMap, s16 *, 0x52DE) * 2)
        ] * 0xE;
    func_020baa64();
    if (unit[0xC] != 0) {
        unit[0xD] = M2C_FIELD(*gCurrentMap, u8 *, 0x52D4);
    } else {
        unit[0xC] = M2C_FIELD(*gCurrentMap, u8 *, 0x52D4);
    }
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52D0), u16 *, 0x4) =
        (u16)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52D0), u16 *, 0x4) | 0x8);
    {
        u16 h = *(u16 *)(unit + 4);
        *(u16 *)(unit + 4) = (u16)(h | 0x10);
    }
    func_020babfc(
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E0),
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*gCurrentMap + 0x5388));
    func_020ce630(
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E0),
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*gCurrentMap + 0x5388));
    {
        u8 *p = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
        u32 k = (u32)p[0];
        k = (k << 26) >> 26;
        if (k != 1 && k != 2) return;
    }
    func_0208fb0c(
        0x7B,
        M2C_FIELD(*gCurrentMap, s16 *, 0x52DC),
        M2C_FIELD(*gCurrentMap, s16 *, 0x52DE));
}

void func_020bb5c0(void *arg0) {
    M2C_UNK func_020c98d8(s32, s32, M2C_UNK);
    M2C_UNK func_020cb038(s32, M2C_UNK);
    M2C_UNK func_020cb170(s32, M2C_UNK);
    M2C_UNK func_020cb254(s32, M2C_UNK, M2C_UNK);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x54);
    func_020cb038(temp_r4, 0);
    func_020cb170(temp_r4, 0);
    func_020cb254(temp_r4, 1, 1);
    func_020c98d8(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 1);
}

void func_020bb608(s32 arg0) {
    M2C_UNK func_020d19b4(u16);
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    extern s32 data_0215be0c;
    extern s16 data_0212923c[];

    if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c20(0x14, 1);
        {
            u8 *sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
            u8 kind = sel[arg0 + 0xC];
            u8 *u = (u8 *)*gCurrentMap + 0x59A4 + kind * 0xE;
            u16 f;
            s32 idx;
            u8 d;
            f = M2C_FIELD(u, u16 *, 0x4);
            f = (u16)(f & ~0x8);
            M2C_FIELD(u, u16 *, 0x4) = f;
            f = M2C_FIELD(u, u16 *, 0x4);
            f = (u16)(f & ~0x2);
            M2C_FIELD(u, u16 *, 0x4) = f;
            idx = data_0215be0c;
            u[0x1] = (s8)(M2C_FIELD(*gCurrentMap, s16 *, 0x52DC) + data_0212923c[idx * 2]);
            u[0x2] = (s8)(M2C_FIELD(*gCurrentMap, s16 *, 0x52DE) + data_0212923c[idx * 2 + 1]);
            sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
            sel[arg0 + 0xC] = 0;
            if (arg0 == 0) {
                sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
                d = sel[0xD];
                if (d != 0) {
                    sel[0xC] = d;
                    sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
                    sel[0xD] = 0;
                }
            }
        }
    }
    {
        u8 *sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
        u8 kind = sel[0xC];
        if (kind == 0) {
            u16 h = M2C_FIELD(sel, u16 *, 0x4);
            h = (u16)(h & ~0x10);
            M2C_FIELD(sel, u16 *, 0x4) = h;
        }
    }
}

void func_020bb768(void) {
}

void func_020bbac8(void) {
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cb8cc(M2C_UNK);
    s32 func_020d19b4(u16);
    extern void **gCurrentMap;
    if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c20(0x10, 1);
    }
    func_020cb8cc(0);
}

void func_020bbb08(void) {
    M2C_UNK func_020a39f8();
    M2C_UNK func_0207c2e0();
    M2C_UNK func_020a6fcc();
    extern void **gCurrentMap;
    extern u8 data_02156e50[];

    M2C_FIELD(*gCurrentMap, u8 **, 0) = M2C_FIELD(*gCurrentMap, u8 **, 0);
    {
        void *obj = M2C_FIELD(*gCurrentMap, void **, 0);
        u8 *p = (u8 *)obj + 0x5120;
        p[0x3A] = (u8)func_020a39f8();
    }
    *(u32 *)(data_02156e50 + 8) = (u32)func_0207c2e0();
    M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, 0x52A4) * 0x8C, u8 *, 0x67D1) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C2);
    M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, 0x52A4) * 0x8C, u8 *, 0x67D2) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C4);
    func_020a6fcc();
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 1;
}

void func_020bbba4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212afac;
    func_01ffa3dc(&data_0212afac, 7);
}

