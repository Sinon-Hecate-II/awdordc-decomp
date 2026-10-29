/* 15 functions from 0x02001068 to 0x02002060 (main), found by ds-decomp. */
#include "common.h"

typedef struct UnkVec3 { s32 x,y,z; } UnkVec3;

#pragma thumb on

#pragma thumb off

u64 func_02001fd4(void);
#pragma opt_strength_reduction off

#pragma opt_common_subs off

#pragma opt_common_subs reset

s32 func_02002030(s32 arg0) {
M2C_FIELD((void *)0x04000280,s16 *,0)=1;
M2C_FIELD((void *)0x04000280,s32 *,0x10)=0;
M2C_FIELD((void *)0x04000280,s32 *,0x14)=0x1000;
M2C_FIELD((void *)0x04000280,s32 *,0x18)=arg0;
M2C_FIELD((void *)0x04000280,s32 *,0x1c)=0;
return 0;
}
