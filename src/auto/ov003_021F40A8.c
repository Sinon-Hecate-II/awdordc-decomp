/* 1 function from 0x021F40A8 to 0x021F66D4 (ov003), found by ds-decomp. */
#include "common.h"
#define OV3KIND(a) (M2C_FIELD((a), u8 *, 0x3b) & 0xf)

void func_ov003_021f40a8(void *arg0) {
    void func_ov003_021f1b7c(s32, void *);
    void func_ov003_021f1b38(s32, void *);
    void func_01ff9b38(void);
    void *func_020896f0(void *);
    void func_020893f4(void *, void *, s32);
    void func_02089438(void *);
    void func_02088da8(void *);
    void *func_0208bc24(void *);
    void func_0208b758(void *, s32);
    void func_02088f1c(void *);
    void func_ov003_021f14a0(void);
    void func_ov006_02217464(void *);
    void func_020ab344(void *, s32);
    void *func_02082028(s32);
    extern u16 data_ov003_0220fde8;
    extern u16 data_ov003_0220fdf0;
    extern u16 data_ov003_0220fdea;
    extern u16 data_ov003_0220fdee;
    extern u16 data_ov003_0220fdec;
    extern u16 data_ov003_0220fde4;
    extern u8 data_ov003_022100e4[16];
    extern u8 data_ov003_0220fb28[16];
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    void *q;
    void *o;
    void *saved;

    func_ov003_021f1b7c(0, &data_ov003_0220fde8);
    func_ov003_021f1b7c(1, &data_ov003_0220fdf0);
    func_ov003_021f1b7c(3, &data_ov003_0220fdea);
    func_01ff9b38();
    q = M2C_FIELD(arg0, void **, 0x6c);
    o = func_020896f0(arg0);
    M2C_FIELD(q, void **, 0) = o;
    func_020893f4(o, (void *)0x8b80, 1);
    o = M2C_FIELD(q, void **, 0);
    M2C_FIELD(o, u16 *, 0x34) = 6;
    M2C_FIELD(o, u16 *, 0x36) = 0x28;
    M2C_FIELD(o, u32 *, 0x40) =
        (((M2C_FIELD(o, u32 *, 0x40) & 0xFFFFFE00) | 0x70) & 0xFFFC01FF) | 0x1E00;
    func_02089438(o);
    o = M2C_FIELD(q, void **, 0);
    M2C_FIELD(o, u16 *, 0x3c) = 0x400;
    o = M2C_FIELD(q, void **, 0);
    M2C_FIELD(o, u8 *, 0x58) = 1;
    o = M2C_FIELD(q, void **, 0);
    func_02088da8(o);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    o = func_0208bc24(arg0);
    M2C_FIELD(q, void **, 4) = o;
    M2C_FIELD(o, u16 *, 0x3e) = 0x36c;
    o = M2C_FIELD(q, void **, 4);
    M2C_FIELD(o, u32 *, 0x40) = (M2C_FIELD(o, u32 *, 0x40) & ~0x3FC0000) | 0x300000;
    o = M2C_FIELD(q, void **, 4);
    func_02088da8(o);
    data_027e00c4 = saved;
    if (OV3KIND(arg0) == 4) {
        func_0208b758(M2C_FIELD(q, void **, 4), 0x4700001d);
    } else if (OV3KIND(arg0) == 6) {
        func_0208b758(M2C_FIELD(q, void **, 4), 0x47000025);
    } else if (OV3KIND(arg0) == 7) {
        func_0208b758(M2C_FIELD(q, void **, 4), 0x47000026);
    } else if (OV3KIND(arg0) == 8) {
        func_0208b758(M2C_FIELD(q, void **, 4), 0x47000027);
    } else {
        func_0208b758(M2C_FIELD(q, void **, 4), 0x47000013);
    }
    func_02088f1c(M2C_FIELD(q, void **, 4));
    if (OV3KIND(arg0) == 4) {
        func_ov003_021f14a0();
    }
    if (OV3KIND(arg0) == 5) {
        func_02088da8(M2C_FIELD(q, void **, 0));
    } else if (OV3KIND(arg0) == 1) {
    } else {
        func_02088da8(M2C_FIELD(q, void **, 0));
    }
    if (OV3KIND(arg0) == 6) {
        func_ov006_02217464(arg0);
    }
    if (OV3KIND(arg0) == 0 || OV3KIND(arg0) == 2 || OV3KIND(arg0) == 3 ||
        OV3KIND(arg0) == 4 || OV3KIND(arg0) == 6 || OV3KIND(arg0) == 7 ||
        OV3KIND(arg0) == 8) {
        func_ov003_021f1b38(0, &data_ov003_0220fdee);
        func_ov003_021f1b38(1, &data_ov003_0220fdec);
        func_ov003_021f1b38(3, &data_ov003_0220fde4);
        func_01ff9b38();
        o = func_02082028(0x68);
        if (o) {
            M2C_FIELD(o, void **, 0) = &data_ov003_022100e4;
            M2C_FIELD(o, u8 *, 0x4) = 0;
            M2C_FIELD(o, u16 *, 0x6) = 7;
            M2C_FIELD(o, u16 *, 0x8) = 2;
            M2C_FIELD(o, u8 *, 0xa) = 0x10;
            M2C_FIELD(o, u8 *, 0xb) = 0x78;
            M2C_FIELD(o, void **, 0x10) = &data_ov003_0220fb28;
            M2C_FIELD(o, u32 *, 0x14) = 0;
            M2C_FIELD(o, u32 *, 0x18) = 0;
            M2C_FIELD(o, u32 *, 0x1c) = 0;
            M2C_FIELD(o, u32 *, 0x20) = 1;
            M2C_FIELD(o, u8 *, 0x24) = 1;
            M2C_FIELD(o, u16 *, 0x28) = 0;
            M2C_FIELD(o, u16 *, 0x2a) = 0;
            M2C_FIELD(o, u16 *, 0x2c) = 0;
            M2C_FIELD(o, u16 *, 0x2e) = 0;
            M2C_FIELD(o, u8 *, 0x30) = 1;
            M2C_FIELD(o, u8 *, 0x31) = 0;
            M2C_FIELD(o, u16 *, 0x32) = 0;
            M2C_FIELD(o, u16 *, 0x34) = 0;
            M2C_FIELD(o, u16 *, 0x36) = 1;
            M2C_FIELD(o, u16 *, 0x38) = 0;
            M2C_FIELD(o, u16 *, 0x3a) = 1;
            M2C_FIELD(o, u16 *, 0x3c) = 1;
            M2C_FIELD(o, u16 *, 0x3e) = 0;
            M2C_FIELD(o, u16 *, 0x40) = 0;
            M2C_FIELD(o, u16 *, 0x32) = M2C_FIELD(o, u16 *, 0x34);
            M2C_FIELD(o, u8 *, 0x42) = 4;
            M2C_FIELD(o, u8 *, 0x43) = 0;
            M2C_FIELD(o, u16 *, 0x44) = 0;
            M2C_FIELD(o, u16 *, 0x46) = 0;
            M2C_FIELD(o, u16 *, 0x48) = 1;
            M2C_FIELD(o, u16 *, 0x4a) = 0;
            M2C_FIELD(o, u16 *, 0x4c) = 1;
            M2C_FIELD(o, u16 *, 0x4e) = 1;
            M2C_FIELD(o, u16 *, 0x50) = 0;
            M2C_FIELD(o, u16 *, 0x52) = 0;
            M2C_FIELD(o, u16 *, 0x44) = M2C_FIELD(o, u16 *, 0x46);
            M2C_FIELD(o, u8 *, 0x54) = 4;
            M2C_FIELD(o, u8 *, 0x55) = 0;
            M2C_FIELD(o, u16 *, 0x56) = 0;
            M2C_FIELD(o, u16 *, 0x58) = 0;
            M2C_FIELD(o, u16 *, 0x5a) = 1;
            M2C_FIELD(o, u16 *, 0x5c) = 0;
            M2C_FIELD(o, u16 *, 0x5e) = 1;
            M2C_FIELD(o, u16 *, 0x60) = 1;
            M2C_FIELD(o, u16 *, 0x62) = 0;
            M2C_FIELD(o, u16 *, 0x64) = 0;
            M2C_FIELD(o, u16 *, 0x56) = M2C_FIELD(o, u16 *, 0x58);
            M2C_FIELD(o, u16 *, 0x28) = 0;
            M2C_FIELD(o, u16 *, 0x2a) = 0;
            M2C_FIELD(o, u16 *, 0x2c) = 0;
            M2C_FIELD(o, u16 *, 0x2e) = 0;
            M2C_FIELD(o, u16 *, 0x3e) = 0;
            M2C_FIELD(o, u16 *, 0x40) = 0;
            M2C_FIELD(o, u16 *, 0x3c) = 4;
            M2C_FIELD(o, u16 *, 0x32) = M2C_FIELD(o, u16 *, 0x34);
            M2C_FIELD(o, u16 *, 0x50) = 0;
            M2C_FIELD(o, u16 *, 0x52) = 0;
            M2C_FIELD(o, u16 *, 0x4e) = 5;
            M2C_FIELD(o, u16 *, 0x44) = M2C_FIELD(o, u16 *, 0x46);
            M2C_FIELD(o, u16 *, 0x62) = 0;
            M2C_FIELD(o, u16 *, 0x64) = 0;
            M2C_FIELD(o, u16 *, 0x60) = 5;
            M2C_FIELD(o, u16 *, 0x56) = M2C_FIELD(o, u16 *, 0x58);
            M2C_FIELD(arg0, void **, 0x4c) = o;
            M2C_FIELD(o, u16 *, 0x28) = 0;
            M2C_FIELD(o, u16 *, 0x2a) = 0;
            M2C_FIELD(o, u16 *, 0x2c) = 0;
            M2C_FIELD(o, u16 *, 0x2e) = 0;
            func_020ab344(o, 1);
        }
    }
}
