/* 9 functions from 0x02198848 to 0x02199614 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_02198c08(void) {
    M2C_UNK func_02007f8c(M2C_UNK *, M2C_UNK, s32);
    M2C_UNK func_ov000_0219c508(s32, M2C_UNK);
    extern s32 *data_027e0058;
    extern M2C_UNK data_ov000_021e0a58;
    func_ov000_0219c508(*data_027e0058 + 0x2840, 0);
    func_ov000_0219c508(*data_027e0058 + 0x2D48, 0);
    func_02007f8c(&data_ov000_021e0a58, 0, 0x508);
}

void func_ov000_02198f60(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_02198da4(u8);
    extern s32 *data_027e0058;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*data_027e0058, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), i) == 0) {
            func_ov000_02198da4(i);
        }
    }
    M2C_FIELD(*data_027e0058, u16 *, 0x52B6) = saved;
}

void func_ov000_02199330(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_02198fec(u8);
    extern s32 *data_027e0058;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*data_027e0058, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), i) == 0) {
            func_ov000_02198fec(i);
        }
    }
    M2C_FIELD(*data_027e0058, u16 *, 0x52B6) = saved;
}

void func_ov000_02199588(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_021993bc(u8);
    extern s32 *data_027e0058;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*data_027e0058, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), i) == 0) {
            func_ov000_021993bc(i);
        }
    }
    M2C_FIELD(*data_027e0058, u16 *, 0x52B6) = saved;
}

