/* 15 functions from 0x02001068 to 0x02002060 (main), found by ds-decomp. */
#include "common.h"

typedef struct UnkVec3 { s32 x,y,z; } UnkVec3;

void func_02001068(s32 *arg0,s32 *arg1,s32 arg2,s32 arg3,s32 arg4) {
void func_02007f4c(void *,void *);
if(arg0!=arg1) func_02007f4c(arg0,arg1);
arg1[9]=arg0[9]+(s32)(((long long)arg2*arg0[0]+(long long)arg3*arg0[3]+(long long)arg4*arg0[6])>>12);
arg1[10]=arg0[10]+(s32)(((long long)arg2*arg0[1]+(long long)arg3*arg0[4]+(long long)arg4*arg0[7])>>12);
arg1[11]=arg0[11]+(s32)(((long long)arg2*arg0[2]+(long long)arg3*arg0[5]+(long long)arg4*arg0[8])>>12);
}

s32 func_02001114(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p = arg0;
    *p++ = arg1;
    p[7] = arg3;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    *p++ = arg2;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    p++;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    return (s32)p;
}

#pragma thumb on
void func_0200112c(s32 *arg0, s32 arg1, s32 arg2) {
    s32 *p = arg0;
    *p++ = arg2;
    *p++ = arg1;
    *p++ = 0;
    *p++ = -arg1;
    *p++ = arg2;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0x1000;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
}
#pragma thumb off
void func_02001148(void *arg0, void *arg1, void *arg2) { (void)arg0; (void)arg1; (void)arg2; }

void func_0200141c(s32 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 sp18[3];
    s32 sp0c[3];
    s32 sp00[3];
    s32 r5 = arg1;
    s32 *r6 = arg0;
    s32 *r4 = arg3;

    sp18[0] = r6[0] - arg2[0];
    sp18[1] = r6[1] - arg2[1];
    sp18[2] = r6[2] - arg2[2];
    func_020021c0(sp18);
    func_0200213c(r5, sp18, sp0c);
    func_020021c0(sp0c);
    func_0200213c(r5, sp18, sp00);
    r4[0] = sp0c[0];
    r4[1] = sp0c[1];
    r4[2] = sp18[0];
    r4[3] = sp18[1];
    r4[4] = sp18[2];
    r4[5] = sp00[0];
    r4[6] = sp00[1];
    r4[7] = sp00[2];
    r4[8] = sp18[2];
    r4[9] = -func_02002100(r6, sp00);
    r4[10] = -func_02002100(r6, sp18);
    r4[11] = -func_02002100(r6, sp18);
}

void func_02001524(void *arg0,UnkVec3 *arg1) {
*arg1++=*(UnkVec3 *)arg0; arg0=(u8 *)arg0+16;
*arg1++=*(UnkVec3 *)arg0; arg0=(u8 *)arg0+16;
*arg1++=*(UnkVec3 *)arg0;
}

void func_0200154c(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    void func_02007f68(void *, void *);
    if (arg0 != arg1) func_02007f68(arg0, arg1);
    arg1[12] = arg0[12] + (s32)(((long long)arg3 * arg0[4] + (long long)arg2 * arg0[0] + (long long)arg4 * arg0[8]) >> 12);
    arg1[13] = arg0[13] + (s32)(((long long)arg3 * arg0[5] + (long long)arg2 * arg0[1] + (long long)arg4 * arg0[9]) >> 12);
    arg1[14] = arg0[14] + (s32)(((long long)arg3 * arg0[6] + (long long)arg2 * arg0[2] + (long long)arg4 * arg0[10]) >> 12);
    arg1[15] = arg0[15] + (s32)(((long long)arg3 * arg0[7] + (long long)arg2 * arg0[3] + (long long)arg4 * arg0[11]) >> 12);
}

void func_02001624(s32 *arg0,s32 *arg1,s32 arg2,s32 arg3,s32 arg4) {
arg1[0]=(s32)(((long long)arg2*arg0[0])>>12);
arg1[1]=(s32)(((long long)arg2*arg0[1])>>12);
arg1[2]=(s32)(((long long)arg2*arg0[2])>>12);
arg1[3]=(s32)(((long long)arg2*arg0[3])>>12);
arg1[4]=(s32)(((long long)arg3*arg0[4])>>12);
arg1[5]=(s32)(((long long)arg3*arg0[5])>>12);
arg1[6]=(s32)(((long long)arg3*arg0[6])>>12);
arg1[7]=(s32)(((long long)arg3*arg0[7])>>12);
arg1[8]=(s32)(((long long)arg4*arg0[8])>>12);
arg1[9]=(s32)(((long long)arg4*arg0[9])>>12);
arg1[10]=(s32)(((long long)arg4*arg0[10])>>12);
arg1[11]=(s32)(((long long)arg4*arg0[11])>>12);
if(arg0!=arg1) { s32 a=arg0[13], b=arg0[12]; arg1[12]=b; arg1[13]=a; a=arg0[15]; b=arg0[14]; arg1[14]=b; arg1[15]=a; }
}

void func_02001748(void *a, void *b, void *c) { (void)a;(void)b;(void)c; }

u64 func_02001fd4(void);
#pragma opt_strength_reduction off
void func_02001dac(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *p) {
    s64 t1;
    s64 q1;
    s64 t2;
    s64 q2;
    s64 t3;
    s64 q3;

    func_02002030(d - c);

    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[11] = 0;
    p[15] = g;

    t1 = (s64)func_02001fd4();

    *(volatile s32 *)0x04000290 = 0;
    *(volatile s32 *)0x04000294 = 0x1000;
    *(volatile s32 *)0x04000298 = a - b;
    *(volatile s32 *)0x0400029c = 0;

    if (g != 0x1000) {
        q1 = ((s64)t1 * g) / 0x1000;
    } else {
        q1 = t1;
    }
    p[0] = (s32)(((q1 << 13) + 0x80000000ULL) >> 32);

    t2 = (s64)func_02001fd4();

    *(volatile s32 *)0x04000290 = 0;
    *(volatile s32 *)0x04000294 = 0x1000;
    *(volatile s32 *)0x04000298 = e - f;
    *(volatile s32 *)0x0400029c = 0;

    if (g != 0x1000) {
        q2 = ((s64)t2 * g) / 0x1000;
    } else {
        q2 = t2;
    }
    p[5] = (s32)(((q2 << 13) + 0x80000000ULL) >> 32);

    t3 = (s64)func_02001fd4();

    if (g != 0x1000) {
        q3 = ((s64)t3 * g) / 0x1000;
    } else {
        q3 = t3;
    }

    p[10] = (s32)(((q3 << 13) + 0x80000000ULL) >> 32);
    p[12] = (s32)(((q1 * (-(c + d))) + 0x80000000ULL) >> 32);
    p[13] = (s32)(((q2 * (-(a + b))) + 0x80000000ULL) >> 32);
    p[14] = (s32)(((q3 * (e + f)) + 0x80000000ULL) >> 32);
}
void func_02001fb4(void) {
    M2C_UNK func_02001ff8();
    M2C_UNK func_02002060();
    func_02002060();
    func_02001ff8();
}

void func_02001fc4(void) {
    M2C_UNK func_02002030();
    func_02002030();
    func_02001ff8();
}

u64 func_02001fd4(void) {
while (*(volatile u16 *)0x04000280 & 0x8000) {}
return *(u64 *)0x040002a0;
}

s32 func_02001ff8(void) {
while (*(volatile u16 *)0x04000280 & 0x8000) {}
return (*(volatile u64 *)0x040002a0 + 0x80000) >> 20;
}

#pragma opt_common_subs off

#pragma opt_common_subs reset
