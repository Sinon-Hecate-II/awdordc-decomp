#ifndef OV000_UNIT_ENTRY_H
#define OV000_UNIT_ENTRY_H
#include "common.h"
typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1[5];
    u16 unk6 : 7;
    u16 unk6_7 : 9;
    u8 unk8[3];
    u8 unkB : 4;
    u8 unkB_4 : 1;
    u8 unkB_5 : 3;
    u8 unkC[2];
} UnkStruct_ov000_021A860C;
#endif
