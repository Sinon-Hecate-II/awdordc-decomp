/* 6 functions from 0x02217F5C to 0x02218BAC (ov004), found by ds-decomp. */
#include "common.h"

void func_ov004_022188b8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov004_022188c4(void *a){extern void **gCurrentMap;extern u32 data_0215d8a0[2];func_0208fe30(0x10014);data_0215d8a0[1]=(data_0215d8a0[1]&~0xffff)|(u16)(M2C_FIELD(*gCurrentMap,u16 *,0x5142)-0xa1);if(func_020a8958(M2C_FIELD(*gCurrentMap,u16 *,0x5142)))func_01ffa8c4(a,7);M2C_FIELD(a,u8 *,0x38)=2;M2C_FIELD(a,u8 *,0x36)=0;}

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

