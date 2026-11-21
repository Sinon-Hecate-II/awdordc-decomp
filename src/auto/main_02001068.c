/* 15 functions from 0x02001068 to 0x02002060 (main), found by ds-decomp. */
#include "common.h"

typedef struct UnkVec3 { s32 x,y,z; } UnkVec3;
typedef struct Matrix01148 { s32 m[12]; } Matrix01148;
typedef struct Matrix016 { s32 m[16]; } Matrix016;

/* Append a local translation (x, y, z) to a Q12 4x3 matrix: the rotation part is
 * copied to dst and the translation row becomes src's own plus the delta rotated
 * by the source rotation. */
void MTX_TransApply43(s32 *src,s32 *dst,s32 x,s32 y,s32 z) {
void MTX_Copy33(void *,void *);
if(src!=dst) MTX_Copy33(src,dst);
dst[MTX43_TRANS+0]=src[MTX43_TRANS+0]+(s32)(((long long)x*src[MTX43_ROT+0]+(long long)y*src[MTX43_ROT+3]+(long long)z*src[MTX43_ROT+6])>>MTX_FX_SHIFT);
dst[MTX43_TRANS+1]=src[MTX43_TRANS+1]+(s32)(((long long)x*src[MTX43_ROT+1]+(long long)y*src[MTX43_ROT+4]+(long long)z*src[MTX43_ROT+7])>>MTX_FX_SHIFT);
dst[MTX43_TRANS+2]=src[MTX43_TRANS+2]+(s32)(((long long)x*src[MTX43_ROT+2]+(long long)y*src[MTX43_ROT+5]+(long long)z*src[MTX43_ROT+8])>>MTX_FX_SHIFT);
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

/* Build the Q12 look-at view matrix `mtx` from eye position `camPos`, up vector
 * `camUp` and the point `target`: normalize the forward (eye - target), right
 * (up x forward) and true-up (forward x right) axes, store them as the rotation
 * columns and set the translation from the eye position against each axis. */
void MTX_LookAt(s32 *camPos, s32 *camUp, s32 *target, s32 *mtx) {
#pragma opt_propagation on
    s32 sp18[3];
    s32 sp0c[3];
    s32 sp00[3];
    s32 *up = camUp;
    s32 *pos = camPos;
    s32 *out = mtx;

    sp18[0] = pos[0] - target[0];
    sp18[1] = pos[1] - target[1];
    sp18[2] = pos[2] - target[2];
    func_020021c0(sp18, sp18);
    Vec3CrossProduct(up, sp18, sp0c);
    func_020021c0(sp0c, sp0c);
    Vec3CrossProduct(sp18, sp0c, sp00);
    out[0] = sp0c[0];
    out[1] = sp00[0];
    out[2] = sp18[0];
    out[3] = sp0c[1];
    out[4] = sp00[1];
    out[5] = sp18[1];
    out[6] = sp0c[2];
    out[7] = sp00[2];
    out[8] = sp18[2];
    out[9] = -Vec3DotProduct(pos, sp0c);
    out[10] = -Vec3DotProduct(pos, sp00);
    out[11] = -Vec3DotProduct(pos, sp18);
}

void func_02001524(void *arg0,UnkVec3 *arg1) {
*arg1++=*(UnkVec3 *)arg0; arg0=(u8 *)arg0+16;
*arg1++=*(UnkVec3 *)arg0; arg0=(u8 *)arg0+16;
*arg1++=*(UnkVec3 *)arg0;
}

/* Applies a local translation (x, y, z) to a Q12 4x4 matrix: copies the
 * matrix and adds the delta, rotated by the source rotation, to the
 * translation column. */
void MTX_TransApply44(s32 *src, s32 *dst, s32 x, s32 y, s32 z) {
    void MTX_Copy43(void *, void *);
    if (src != dst)
        MTX_Copy43(src, dst);
    dst[MTX44_TRANS + 0] = src[MTX44_TRANS + 0] + (s32)(((s64)x * src[0] + (s64)y * src[4] + (s64)z * src[8]) >> MTX_FX_SHIFT);
    dst[MTX44_TRANS + 1] = src[MTX44_TRANS + 1] + (s32)(((s64)x * src[1] + (s64)y * src[5] + (s64)z * src[9]) >> MTX_FX_SHIFT);
    dst[MTX44_TRANS + 2] = src[MTX44_TRANS + 2] + (s32)(((s64)x * src[2] + (s64)y * src[6] + (s64)z * src[10]) >> MTX_FX_SHIFT);
    dst[MTX44_TRANS + 3] = src[MTX44_TRANS + 3] + (s32)(((s64)x * src[3] + (s64)y * src[7] + (s64)z * src[11]) >> MTX_FX_SHIFT);
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

void func_02001748(void *arg0, void *arg1, void *arg2) {
    Matrix016 tmp;
    s32 *a = arg0, *b = arg1;
    s32 *out = arg2 == arg1 ? tmp.m : arg2;
    s32 b0_1;
    s32 b0_0;
    s32 b0_2;
    s32 b0_3;
    s32 b1_1;
    s32 b1_0;
    s32 b1_2;
    s32 b1_3;
    s32 b3_1;
    s32 b3_0;
    s32 b3_2;
    s32 b3_3;
    s32 b2_1;
    s32 b2_0;
    s32 b2_2;
    s32 b2_3;
    s32 b5_1;
    s32 b5_0;
    s32 b5_2;
    s32 b5_3;
    s32 b7_1;
    s32 b7_0;
    s32 b7_2;
    s32 b7_3;
    s32 b4_1;
    s32 b4_0;
    s32 b4_2;
    s32 b4_3;
    s32 b9_1;
    s32 b9_0;
    s32 b9_2;
    s32 b9_3;
    s32 b11_1;
    s32 b11_0;
    s32 b11_2;
    s32 b11_3;
    s32 b10_1;
    s32 b10_0;
    s32 b10_2;
    s32 b10_3;
    s32 b13_1;
    s32 b13_0;
    s32 b13_2;
    s32 b13_3;
    s32 b12_1;
    s32 b12_0;
    s32 b12_2;
    s32 b12_3;
    s32 b15_1;
    s32 b15_0;
    s32 b15_2;
    s32 b15_3;
    {
        s32 a1 = a[1];
        s32 a0 = a[0];
        s32 a2 = a[2];
        s32 a3 = a[3];
        b0_1 = b[4];
        b0_0 = b[0];
        b0_2 = b[8];
        b0_3 = b[12];
        out[0] = (s32)(((s64)(s32)a0 * b0_0 + (s64)(s32)a1 * b0_1 + (s64)(s32)a2 * b0_2 + (s64)(s32)a3 * b0_3) >> MTX_FX_SHIFT);
        b1_1 = b[5];
        b1_0 = b[1];
        b1_2 = b[9];
        b1_3 = b[13];
        out[1] = (s32)(((s64)(s32)a0 * b1_0 + (s64)(s32)a1 * b1_1 + (s64)(s32)a2 * b1_2 + (s64)(s32)a3 * b1_3) >> MTX_FX_SHIFT);
        b3_1 = b[7];
        b3_0 = b[3];
        b3_2 = b[11];
        b3_3 = b[15];
        out[3] = (s32)(((s64)(s32)a0 * b3_0 + (s64)(s32)a1 * b3_1 + (s64)(s32)a2 * b3_2 + (s64)(s32)a3 * b3_3) >> MTX_FX_SHIFT);
        b2_1 = b[6];
        b2_0 = b[2];
        b2_2 = b[10];
        b2_3 = b[14];
        out[2] = (s32)(((s64)(s32)a0 * b2_0 + (s64)(s32)a1 * b2_1 + (s64)(s32)a2 * b2_2 + (s64)(s32)a3 * b2_3) >> MTX_FX_SHIFT);
    }
    {
        s64 a1 = a[5];
        s64 a0 = a[4];
        s64 a2 = a[6];
        s64 a3 = a[7];
        out[6] = (s32)(((s64)a0 * (s64)b2_0 + (s64)a1 * (s64)b2_1 + (s64)a2 * (s64)b2_2 + (s64)a3 * (s64)b2_3) >> MTX_FX_SHIFT);
        b5_1 = b[5];
        b5_0 = b[1];
        b5_2 = b[9];
        b5_3 = b[13];
        out[5] = (s32)(((s64)(s32)a0 * b5_0 + (s64)(s32)a1 * b5_1 + (s64)(s32)a2 * b5_2 + (s64)(s32)a3 * b5_3) >> MTX_FX_SHIFT);
        b7_1 = b[7];
        b7_0 = b[3];
        b7_2 = b[11];
        b7_3 = b[15];
        out[7] = (s32)(((s64)(s32)a0 * b7_0 + (s64)(s32)a1 * b7_1 + (s64)(s32)a2 * b7_2 + (s64)(s32)a3 * b7_3) >> MTX_FX_SHIFT);
        b4_1 = b[4];
        b4_0 = b[0];
        b4_2 = b[8];
        b4_3 = b[12];
        out[4] = (s32)(((s64)(s32)a0 * b4_0 + (s64)(s32)a1 * b4_1 + (s64)(s32)a2 * b4_2 + (s64)(s32)a3 * b4_3) >> MTX_FX_SHIFT);
    }
    {
        s64 a1 = a[9];
        s64 a0 = a[8];
        s64 a2 = a[10];
        s64 a3 = a[11];
        out[8] = (s32)(((s64)a0 * (s64)b4_0 + (s64)a1 * (s64)b4_1 + (s64)a2 * (s64)b4_2 + (s64)a3 * (s64)b4_3) >> MTX_FX_SHIFT);
        b9_1 = b[5];
        b9_0 = b[1];
        b9_2 = b[9];
        b9_3 = b[13];
        out[9] = (s32)(((s64)(s32)a0 * b9_0 + (s64)a1 * (s64)b9_1 + (s64)(s32)a2 * b9_2 + (s64)(s32)a3 * b9_3) >> MTX_FX_SHIFT);
        b11_1 = b[7];
        b11_0 = b[3];
        b11_2 = b[11];
        b11_3 = b[15];
        out[11] = (s32)(((s64)(s32)a0 * b11_0 + (s64)a1 * (s64)b11_1 + (s64)(s32)a2 * b11_2 + (s64)(s32)a3 * b11_3) >> MTX_FX_SHIFT);
        b10_1 = b[6];
        b10_0 = b[2];
        b10_2 = b[10];
        b10_3 = b[14];
        out[10] = (s32)(((s64)(s32)a0 * b10_0 + (s64)a1 * (s64)b10_1 + (s64)(s32)a2 * b10_2 + (s64)(s32)a3 * b10_3) >> MTX_FX_SHIFT);
    }
    {
        s64 a1 = a[13];
        s64 a0 = a[12];
        s64 a2 = a[14];
        s64 a3 = a[15];
        out[14] = (s32)(((s64)(s32)a0 * b10_0 + (s64)(s32)a1 * b10_1 + (s64)(s32)a2 * b10_2 + (s64)(s32)a3 * b10_3) >> MTX_FX_SHIFT);
        b13_1 = b[5];
        b13_0 = b[1];
        b13_2 = b[9];
        b13_3 = b[13];
        out[13] = (s32)(((s64)a0 * (s64)b13_0 + (s64)a1 * (s64)b13_1 + (s64)a2 * (s64)b13_2 + (s64)a3 * (s64)b13_3) >> MTX_FX_SHIFT);
        b12_1 = b[4];
        b12_0 = b[0];
        b12_2 = b[8];
        b12_3 = b[12];
        out[12] = (s32)(((s64)a0 * (s64)b12_0 + (s64)a1 * (s64)b12_1 + (s64)a2 * (s64)b12_2 + (s64)a3 * (s64)b12_3) >> MTX_FX_SHIFT);
        b15_1 = b[7];
        b15_0 = b[3];
        b15_2 = b[11];
        b15_3 = b[15];
        out[15] = (s32)(((s64)a0 * (s64)b15_0 + (s64)a1 * (s64)b15_1 + (s64)a2 * (s64)b15_2 + (s64)a3 * (s64)b15_3) >> MTX_FX_SHIFT);
    }
    if (out == tmp.m)
        *(Matrix016 *)arg2 = tmp;
}

u64 func_02001fd4(void);
#pragma push
#pragma opt_strength_reduction off
void GX_BuildOrthoMatrix(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *p) {
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
