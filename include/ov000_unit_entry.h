#ifndef OV000_UNIT_ENTRY_H
#define OV000_UNIT_ENTRY_H
#include "common.h"
typedef struct {
    u8 unk0 : 6;      /* +0x00 kind of the unit */
    u8 unk0_6 : 2;    /* +0x00 owner/extra bits */
    u8 unk1[5];       /* +0x01 tile x, tile y, ... */
    u16 unk6 : 7;     /* +0x06 health */
    u16 unk6_7 : 9;   /* +0x06 facing direction in the top five bits */
    u8 unk8[3];       /* +0x08 */
    u8 unkB : 4;      /* +0x0B action state nibble */
    u8 unkB_4 : 1;    /* +0x0B */
    u8 unkB_5 : 3;    /* +0x0B */
    u8 unkC[2];       /* +0x0C carried-unit chain */
} UnkStruct_ov000_021A860C;

/* Unit kind whose unkC[] chain names the units it carries. */
#define UNIT_KIND_CARRIER 21
#endif
