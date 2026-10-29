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
volatile s32 *p=(volatile s32 *)0x04000280;
s32 v=1;*(volatile s16 *)p=v;
v=0;p[4]=v;v=0x1000;p[5]=v;p[6]=arg0;v=0;p[7]=v;return v;
}
