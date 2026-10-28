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

extern void func_020e4490(void);
extern void func_020e4570(void);
extern void func_02086508(void);
extern void func_020e4594(void);
void main(void)
{
    func_020e4490();
    func_020e4570();
    func_02086508();
    func_020e4594();
}

s32 func_02000ca0(void *arg0, void *arg1) {
    (void)arg0; (void)arg1;
    return 0;
}

void func_02000f90(void *arg0, void *arg1, void *arg2) {
    s32 *p = arg0;
    s32 *q = arg1;
    s32 *r = arg2;
    s32 x0 = (s32)p[0];
    s32 x1 = (s32)p[1];
    s32 x2 = (s32)p[2];
    r[0] = (s32)(((s64)x1 * q[3] + (s64)x0 * q[0] + (s64)x2 * q[6]) >> 12);
    r[1] = (s32)(((s64)x1 * q[4] + (s64)x0 * q[1] + (s64)x2 * q[7]) >> 12);
    r[2] = (s32)(((s64)x1 * q[5] + (s64)x0 * q[2] + (s64)x2 * q[8]) >> 12);
}

