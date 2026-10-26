/* 16 functions from 0x0217F754 to 0x02180738 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0217f754(s32 x,s32 y,u8 *out,u8 *value) {
s32 func_ov000_021a9904(u32); u8 func_ov000_0217f318(s32,s32); u8 func_ov000_0217f494(s32,s32); s32 func_020a85c8(u32);
extern void **data_027e0058;
u8 *p; u8 result;
if(func_ov000_021a9904((u32)(M2C_FIELD(*data_027e0058,u8 **,0x52d0)[0]<<26)>>26)==0){
result=func_ov000_0217f318(x,y);
if(!result)return;
*out=4;*value=result;
return;
}
if(func_ov000_021a9904((u32)(M2C_FIELD(*data_027e0058,u8 **,0x52d0)[0]<<26)>>26)!=1)return;
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
if(p[1]!=x || p[2]!=y) {
if(!func_020a85c8((u32)(p[0]<<26)>>26))return;
}
result=func_ov000_0217f494(x,y);
if(result) { *out=4;*value=result; return; }
return;
}

s32 func_ov000_02180410(void) {
    extern u16 data_02168f14;
    extern void **data_027e0058;
    void *temp_r1;
    if (((u32)(data_02168f14 << 29) >> 29) & 0xFF) return 0;
    temp_r1 = *data_027e0058;
    if (M2C_FIELD(temp_r1, u16 *, 0x5142) == 0xAF && M2C_FIELD(temp_r1, u16 *, 0x52A4) == 2) return 1;
    return 0;
}

void func_ov000_0218046c(void) {
    M2C_UNK func_ov000_021972e0();
    extern void **data_027e0058;
    if (M2C_FIELD(*data_027e0058, u16 *, 0x5142) != 0xAF) {
        return;
    }
    func_ov000_02198c08();
    func_ov000_021972e0();
}

void func_ov000_0218049c(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218edd8();
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
}

void func_ov000_021804b0(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218edd8();
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
}

void func_ov000_021804c4(void) {
    M2C_UNK func_ov000_0218cfec();
    M2C_UNK func_ov000_02198c08();
    func_ov000_02198c08();
    func_ov000_0218cfec();
}

void func_ov000_021804d4(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_0219553c();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **data_027e0058;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *data_027e0058;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_021954a4();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_0219553c();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_0218053c(void) {
    M2C_UNK func_ov000_02198c08();
    M2C_UNK func_ov000_0218eea8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_0219553c();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **data_027e0058;
    void *temp_r3;
    func_ov000_02198c08();
    func_ov000_0218eea8();
    func_ov000_0218ca94();
    temp_r3 = *data_027e0058;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_021954a4();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_0219553c();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_021805a0(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_0219553c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **data_027e0058;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *data_027e0058;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_0219553c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_021954a4();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180608(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_02195750();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **data_027e0058;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *data_027e0058;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_02195750();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_021954a4();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180670(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_02195ea4();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **data_027e0058;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *data_027e0058;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_02195ea4();
    func_ov000_0218ae58();
    func_ov000_021954a4();
    func_ov000_02194370();
    func_ov000_021965dc();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_021806d8(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_0219604c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **data_027e0058;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *data_027e0058;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_0219604c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

