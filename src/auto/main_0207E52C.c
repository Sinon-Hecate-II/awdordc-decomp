/* 3 functions from 0x0207E52C to 0x0207F460 (main), found by ds-decomp. */
#include "common.h"

void func_0207e52c(void *arg0, s32 arg1) { }

s32 func_0207ef5c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0207dc0c(s32, s32);
    s32 func_0207de50(s32, s32);
    s32 func_0207e338(s32, s32);
    extern M2C_UNK data_020edebc;
    u16 flags;
    flags = (u16)M2C_FIELD(&data_020edebc, u32 *, arg2 * 8);
    if (arg2 == 0x34) return 5;
    if (flags & 1) return func_0207e338(arg0, arg1);
    if (flags & 2) return func_0207dc0c(arg0, arg1);
    if (!(flags & 4)) return 0;
    return func_0207de50(arg0, arg1);
}

s32 func_0207efb4(s32 arg0) {
    switch (arg0) {
    case 0x17c: return 1;
    case 2: return 1;
    case 3: return 5;
    case 4: return 8;
    case 7: return 2;
    case 0x20: return 4;
    case 0x21: return 3;
    case 0x22: return 9;
    case 0x23: return 7;
    case 0x24: return 13;
    case 0x25: return 14;
    case 0x27: return 10;
    case 0x142: return 0x1b;
    case 0x146: return 0x3b;
    case 0x162: return 0x1c;
    case 0x166: return 0x3c;
    case 0x168: return 0xc;
    case 0x179: return 0x14;
    case 0x17a: return 0x34;
    case 0x17b: return 0x54;
    case 0x17d: return 0x74;
    case 0x17e: return 0x94;
    case 0x181: return 0x18;
    case 0x182: return 6;
    case 0x19b: return 0x15;
    case 0x19c: return 0x35;
    case 0x19d: return 0x55;
    case 0x19e: return 0x75;
    case 0x19f: return 0x95;
    case 0x1a3: return 0x1a;
    case 0x1bb: return 0x16;
    case 0x1bc: return 0x36;
    case 0x1bd: return 0x56;
    case 0x1be: return 0x76;
    case 0x1bf: return 0x96;
    case 0x1c0: return 0xf;
    case 0x1c1: return 0x11;
    case 0x1c2: return 0x10;
    case 0x1c3: return 0x12;
    case 0x1c4: return 0x13;
    case 0x1c5: return 0x2f;
    case 0x1c6: return 0x31;
    case 0x1c7: return 0x30;
    case 0x1c8: return 0x32;
    case 0x1c9: return 0x33;
    case 0x1ca: return 0x4f;
    case 0x1cb: return 0x51;
    case 0x1cc: return 0x50;
    case 0x1cd: return 0x52;
    case 0x1ce: return 0x53;
    case 0x1cf: return 0x6f;
    case 0x1d0: return 0x71;
    case 0x1d1: return 0x70;
    case 0x1d2: return 0x72;
    case 0x1d3: return 0x73;
    case 0x1d4: return 0x8f;
    case 0x1d5: return 0x91;
    case 0x1d6: return 0x90;
    case 0x1d7: return 0x92;
    case 0x1d8: return 0x93;
    case 0x1d9: return 0x17;
    case 0x1da: return 0x37;
    case 0x1db: return 0x57;
    case 0x1dc: return 0x77;
    case 0x1dd: return 0x97;
    default: return 1;
    }
}

