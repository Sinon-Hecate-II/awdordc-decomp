/* 31 functions from 0x02000000 to 0x02001068 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 a; s32 b; } Pair_100c;

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
  void func_020e4490(void);
  void func_020e4570(void);
  void func_02086508(void);
  void func_020e4594(void);
  func_020e4570();
  func_02086508();
  func_020e4594();
  for (;;)
  {
    func_020e4490();
  }

}

#pragma push
#pragma opt_strength_reduction off
s32 func_02000ca0(void *arg0,void *arg1){
void func_02002030(s32,s32);
s32 func_02001ff8(void);
void func_02007f4c(void *,void *);
s32 *m=arg0,*d=arg1; s32 temp[9];
s64 c0,c1,c2; s32 det,inv,a,b,c,e;
if(arg0==arg1)d=temp;
c0=(s32)(((s64)m[3]*m[8]-(s64)m[5]*m[6]+0x800)>>12);
c1=(s32)(((s64)m[4]*m[8]-(s64)m[5]*m[7]+0x800)>>12);
c2=(s32)(((s64)m[3]*m[7]-(s64)m[4]*m[6]+0x800)>>12);
det=(s32)(((s64)m[0]*c1-(s64)m[1]*c0+(s64)m[2]*c2+0x800)>>12);
if(det==0)return -1;
func_02002030(det,0);
a=(s32)(((s64)m[1]*m[8]-(s64)m[7]*m[2])>>12);
b=(s32)(((s64)m[1]*m[5]-(s64)m[4]*m[2])>>12);
c=(s32)(((s64)m[0]*m[8]-(s64)m[6]*m[2])>>12);
e=(s32)(((s64)m[0]*m[5]-(s64)m[3]*m[2])>>12);
inv=func_02001ff8();
d[0]=(s32)((inv*c1)>>12);
d[1]=-(s32)(((s64)inv*a)>>12);
d[2]=(s32)(((s64)inv*b)>>12);
d[3]=-(s32)((inv*c0)>>12);
d[4]=(s32)(((s64)inv*c)>>12);
d[5]=-(s32)(((s64)inv*e)>>12);
d[6]=(s32)((inv*c2)>>12);
a=(s32)(((s64)m[0]*m[7]-(s64)m[6]*m[1])>>12);
d[7]=-(s32)(((s64)inv*a)>>12);
c0=(s32)(((s64)m[0]*m[4]-(s64)m[3]*m[1])>>12);
d[8]=(s32)((inv*c0)>>12);
if(d==temp)func_02007f4c(temp,arg1);
return 0;
}
#pragma pop
void func_02000f90(void *arg0, void *arg1, void *arg2) {
 s32 *a=arg0,*m=arg1,*o=arg2;
 s32 x=a[0], y=a[1], z=a[2]; s64 t;
 t=(s64)y*m[3]; t=(s64)x*m[0]+t; t+=(s64)z*m[6]; o[0]=t>>12;
 t=(s64)y*m[4]; t=(s64)x*m[1]+t; t+=(s64)z*m[7]; o[1]=t>>12;
 t=(s64)y*m[5]; t=(s64)x*m[2]+t; t+=(s64)z*m[8]; o[2]=t>>12;
}

#pragma push
#pragma opt_propagation off
void func_0200100c(Pair_100c *p) { Pair_100c a={4096,0}, b={0,0}; *p++=a; *p++=b; *p++=a; *p++=b; *p++=a; *p++=b; }
#pragma pop
