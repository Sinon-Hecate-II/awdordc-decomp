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

s32 func_02000ca0(void *arg0, void *arg1) {
    (void)arg0; (void)arg1;
    return 0;
}

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
