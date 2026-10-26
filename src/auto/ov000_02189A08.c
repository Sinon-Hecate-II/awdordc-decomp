/* 12 functions from 0x02189A08 to 0x0218A9AC (ov000), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6[8];
} UnkStruct_ov000_02189A08;

void func_ov000_02189df4(void) {
    M2C_UNK func_ov000_02188d64();
    M2C_UNK func_ov000_021895bc();
    extern void **data_027e0058;
    if (M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xC) != 0) {
        func_ov000_02188d64();
        return;
    }
    func_ov000_021895bc();
}

s32 func_ov000_0218a080(u8 arg0) {
    s32 func_ov000_021a98a8(u32);
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    s32 count = 0;
    s32 i;
    u16 start = data_ov000_021aeef4[arg0];

    for (i = start + 1; i < data_ov000_021aeef4[arg0] + 0x33; i++) {
        UnkStruct_ov000_02189A08 *entry = &((UnkStruct_ov000_02189A08 *)((u8 *)*data_027e0058 + 0x59A4))[i];
        u32 type = entry->unk0;
        if (type != 0 && !(entry->unk4 & 8) && func_ov000_021a98a8(type) != 0 && ((s8 **)((u8 *)*data_027e0058 + 0x52E8))[entry->unk2][entry->unk1] != -1) {
            count += 1;
        }
    }
    return count;
}

s32 func_ov000_0218a140(u8 arg0) {
s32 func_ov000_021a98a8(u32);
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
extern u8 data_ov000_021b5bfc[];
s32 count=0;
s32 i;
u16 start=data_ov000_021aeef4[arg0];
for(i=start+1;i<data_ov000_021aeef4[arg0]+0x33;i++){
UnkStruct_ov000_02189A08 *entry=&((UnkStruct_ov000_02189A08 *)((u8 *)*data_027e0058+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && !(entry->unk4&8) && func_ov000_021a98a8(type)==0) {
u8 *info=data_ov000_021b5bfc+entry->unk0*0x70;
if((info[0x13]&7)&&info[0xc]!=0 && ((s8 **)((u8 *)*data_027e0058+0x52e8))[entry->unk2][entry->unk1]!=-1)count++;
}
}
return count;
}

s32 func_ov000_0218a230(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    s32 func_ov000_0218a080(u8);
    extern void **data_027e0058;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (func_020d273c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), i) != 0 && func_020d1938(i) != 0) {
            count += func_ov000_0218a080(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

s32 func_ov000_0218a294(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    s32 func_ov000_0218a140(u8);
    extern void **data_027e0058;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (func_020d273c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), i) != 0 && func_020d1938(i) != 0) {
            count += func_ov000_0218a140(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

