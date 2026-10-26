/* 13 functions from 0x020BAC24 to 0x020BBBBC (main), found by ds-decomp. */
#include "common.h"

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
    extern void **data_027e0058;

    func_020baa64();
    M2C_FIELD(M2C_FIELD(*data_027e0058, u8 **, 0x52D0), u8 *, 1) =
        (u8)M2C_FIELD(*data_027e0058, s16 *, 0x52DC);
    M2C_FIELD(M2C_FIELD(*data_027e0058, u8 **, 0x52D0), u8 *, 2) =
        (u8)M2C_FIELD(*data_027e0058, s16 *, 0x52DE);
    func_020babfc(
        M2C_FIELD(*data_027e0058, s16 *, 0x52E0),
        M2C_FIELD(*data_027e0058, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*data_027e0058 + 0x5388));
    func_020ce630(
        M2C_FIELD(*data_027e0058, s16 *, 0x52E0),
        M2C_FIELD(*data_027e0058, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*data_027e0058 + 0x5388));
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

void func_020bbac8(void) {
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cb8cc(M2C_UNK);
    s32 func_020d19b4(u16);
    extern void **data_027e0058;
    if (func_020d19b4(M2C_FIELD(*data_027e0058, u16 *, 0x52A4)) != 0) {
        func_02091c20(0x10, 1);
    }
    func_020cb8cc(0);
}

void func_020bbb08(void) {
    M2C_UNK func_020a39f8();
    M2C_UNK func_0207c2e0();
    M2C_UNK func_020a6fcc();
    extern void **data_027e0058;
    extern u8 data_02156e50[];

    M2C_FIELD(*data_027e0058, u8 **, 0) = M2C_FIELD(*data_027e0058, u8 **, 0);
    {
        void *obj = M2C_FIELD(*data_027e0058, void **, 0);
        u8 *p = (u8 *)obj + 0x5120;
        p[0x3A] = (u8)func_020a39f8();
    }
    *(u32 *)(data_02156e50 + 8) = (u32)func_0207c2e0();
    M2C_FIELD((u8 *)*data_027e0058 + M2C_FIELD(*data_027e0058, u16 *, 0x52A4) * 0x8C, u8 *, 0x67D1) =
        (u8)M2C_FIELD(*data_027e0058, s16 *, 0x52C2);
    M2C_FIELD((u8 *)*data_027e0058 + M2C_FIELD(*data_027e0058, u16 *, 0x52A4) * 0x8C, u8 *, 0x67D2) =
        (u8)M2C_FIELD(*data_027e0058, s16 *, 0x52C4);
    func_020a6fcc();
    M2C_FIELD(*data_027e0058, u16 *, 0x52B0) = 1;
}

void func_020bbba4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212afac;
    func_01ffa3dc(&data_0212afac, 7);
}

