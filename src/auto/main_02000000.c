/* 31 functions from 0x02000000 to 0x02001068 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
void func_02000954(s32 value, s32 *dest, s32 size) {
    s32 end = (s32)dest + size;
    while ((s32)dest < end) {
        *dest++ = value;
    }
}
#pragma opt_strength_reduction reset
void AutoloadCallback(void) {

}

void func_02000b98(void) {

}

void func_02000b9c(void) {

}

