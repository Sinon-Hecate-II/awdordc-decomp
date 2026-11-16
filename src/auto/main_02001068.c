/* 15 functions from 0x02001068 to 0x02002060 (main), found by ds-decomp. */
#include "common.h"

typedef struct UnkVec3 { s32 x,y,z; } UnkVec3;
typedef struct Matrix01148 { s32 m[12]; } Matrix01148;
typedef struct Matrix016 { s32 m[16]; } Matrix016;

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
void func_02001148(void *arg0,void *arg1,void *arg2){Matrix01148 tmp;s32 *a=arg0,*b=arg1,*out;s32 u,v,w;out=arg2==arg1?tmp.m:arg2;
{ s32 x,y,z;
x=a[0];y=a[1];z=a[2];
u=b[0];v=b[3];w=b[6];
out[0]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[1];v=b[4];w=b[7];
out[1]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[2];v=b[5];w=b[8];
out[2]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
}
{ s64 x,y,z;
x=a[3];y=a[4];z=a[5];
out[5]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[1];v=b[4];w=b[7];
out[4]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[0];v=b[3];w=b[6];
out[3]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
}
{ s32 x,y,z;
x=a[6];y=a[7];z=a[8];
out[6]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[1];v=b[4];w=b[7];
out[7]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[2];v=b[5];w=b[8];
out[8]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
}
{ s64 x,y,z;
x=a[9];y=a[10];z=a[11];
out[11]=b[11]+(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[1];v=b[4];w=b[7];
out[10]=b[10]+(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
u=b[0];v=b[3];w=b[6];
out[9]=b[9]+(s32)(((s64)x*u+(s64)y*v+(s64)z*w)>>12);
}
if(out==tmp.m)*(Matrix01148*)arg2=tmp;
}

void func_0200141c(s32 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
#pragma opt_propagation on
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

/* Scale the three basis columns of a 4x4 Q12 matrix by (x, y, z) -- that is,
   dst = src * diag(x, y, z, 1).  The translation column is copied unchanged. */
void MatrixScale44(s32 *src, s32 *dst, s32 x, s32 y, s32 z) {
    dst[0] = (s32)(((long long)x * src[0]) >> 12);
    dst[1] = (s32)(((long long)x * src[1]) >> 12);
    dst[2] = (s32)(((long long)x * src[2]) >> 12);
    dst[3] = (s32)(((long long)x * src[3]) >> 12);
    dst[4] = (s32)(((long long)y * src[4]) >> 12);
    dst[5] = (s32)(((long long)y * src[5]) >> 12);
    dst[6] = (s32)(((long long)y * src[6]) >> 12);
    dst[7] = (s32)(((long long)y * src[7]) >> 12);
    dst[8] = (s32)(((long long)z * src[8]) >> 12);
    dst[9] = (s32)(((long long)z * src[9]) >> 12);
    dst[10] = (s32)(((long long)z * src[10]) >> 12);
    dst[11] = (s32)(((long long)z * src[11]) >> 12);
    if (src != dst) {
        s32 a = src[13], b = src[12];
        dst[12] = b;
        dst[13] = a;
        a = src[15];
        b = src[14];
        dst[14] = b;
        dst[15] = a;
    }
}

void func_02001748(void *arg0,void *arg1,void *arg2){Matrix016 tmp;s32 *a=arg0,*b=arg1,*out;s32 u,v,w,t;out=arg2==arg1?tmp.m:arg2;
{ s32 x,y,z,q;
x=a[0];y=a[1];z=a[2];q=a[3];
u=b[0];v=b[4];w=b[8];t=b[12];
out[0]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[1];v=b[5];w=b[9];t=b[13];
out[1]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[3];v=b[7];w=b[11];t=b[15];
out[3]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[2];v=b[6];w=b[10];t=b[14];
out[2]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
}
{ s64 x,y,z,q;
x=a[4];y=a[5];z=a[6];q=a[7];
out[6]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[1];v=b[5];w=b[9];t=b[13];
out[5]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[3];v=b[7];w=b[11];t=b[15];
out[7]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[0];v=b[4];w=b[8];t=b[12];
out[4]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
}
{ s64 x,y,z,q;
x=a[8];y=a[9];z=a[10];q=a[11];
out[8]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[1];v=b[5];w=b[9];t=b[13];
out[9]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[3];v=b[7];w=b[11];t=b[15];
out[11]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[2];v=b[6];w=b[10];t=b[14];
out[10]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
}
{ s64 x,y,z,q;
x=a[12];y=a[13];z=a[14];q=a[15];
out[14]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[1];v=b[5];w=b[9];t=b[13];
out[13]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[0];v=b[4];w=b[8];t=b[12];
out[12]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
u=b[3];v=b[7];w=b[11];t=b[15];
out[15]=(s32)(((s64)x*u+(s64)y*v+(s64)z*w+(s64)q*t)>>12);
}
if(out==tmp.m)*(Matrix016*)arg2=tmp;
}

u64 func_02001fd4(void);
#pragma push
#pragma opt_strength_reduction off
void func_02001dac(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *p) {
    s64 t1;
    s64 q1;
    s64 t2;
    s64 q2;
    s64 t3;
    s64 q3;
    s64 product;

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

    *(volatile u64 *)0x04000290 = (u64)0x1000 << 32;
    *(volatile u64 *)0x04000298 = (u32)(a-b);

    if (g != 0x1000) {
        q1 = ((s64)t1 * g) / 0x1000;
    } else {
        q1 = t1;
    }
    p[0] = (s32)(((q1 << 13) + 0x80000000ULL) >> 32);

    t2 = (s64)func_02001fd4();

    *(volatile u64 *)0x04000290 = (u64)0x1000 << 32;
    *(volatile u64 *)0x04000298 = (u32)(e-f);

    if (g != 0x1000) {
        q2 = ((s64)t2 * g) / 0x1000;
    } else {
        q2 = t2;
    }
    p[5] = (s32)(((q2 << 13) + 0x80000000ULL) >> 32);

    t3 = (s64)func_02001fd4();

    if (g != 0x1000) {
        product=t3*g;
        q3=product/4096LL;
    } else {
        q3 = t3;
    }

    p[10] = (s32)(((q3 << 13) + 0x80000000ULL) >> 32);
    p[12] = (s32)(((q1 * (-(d + c))) + 0x80000000ULL) >> 32);
    p[13] = (s32)(((q2 * (-(a + b))) + 0x80000000ULL) >> 32);
    p[14] = (s32)(((q3 * (f + e)) + 0x80000000ULL) >> 32);
}
#pragma pop
void FX_Div(void) {
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
