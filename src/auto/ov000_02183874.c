/* 1 function from 0x02183874 to 0x021843EC (ov000), found by ds-decomp. */
#include "common.h"

extern void *gCurrentMap;
void func_ov000_02183874(void) {
    MI_CpuFill8(gCurrentMap, 0, 0xa1);
}
