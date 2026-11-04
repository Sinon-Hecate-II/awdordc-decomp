/* 15 functions from 0x02001068 to 0x02002060 (main), found by ds-decomp. */
#include "common.h"

typedef struct UnkVec3 { s32 x,y,z; } UnkVec3;

#pragma thumb on

#pragma thumb off

u64 func_02001fd4(void);
#pragma opt_strength_reduction off

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma opt_common_subs off
s32 func_02002030(s32 arg0) {
    volatile u16 *p = (volatile u16 *)0x04000280;
    p[0] = 1;
    *(volatile s32 *)((u8 *)p + 0x10) = 0;
    *(volatile s32 *)((u8 *)p + 0x14) = 0x1000;
    *(volatile s32 *)((u8 *)p + 0x18) = arg0;
    {
        s32 z = 0 + 0;
        *(volatile s32 *)((u8 *)p + 0x1c) = z;
        return z;
    }
}
#pragma opt_common_subs reset
