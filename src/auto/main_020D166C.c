/* 23 functions from 0x020D166C to 0x020D2470 (main), found by ds-decomp. */
#include "common.h"

void func_020d166c(s32 a,s32 b){void func_020d0de4(s16,s16);if(!b)return;func_020d0de4((s16)a,(s16)b);}

s32 func_020d18e8(s32 *arg0) {
    M2C_UNK func_020a7310(s32);
    func_020a7310(*arg0);
    return 0;
}

void func_020d18fc(s32 a){extern void **data_027e0058;u8 *p=(u8 *)*data_027e0058+0x67a4+a*0x8c;if((u32)M2C_FIELD(p,u16 *,0x20)<0xffff)M2C_FIELD(p,u16 *,0x20)++;}

s32 func_020d1938(s32 a){extern void **data_027e0058;u8 result;u8 *p=(u8 *)*data_027e0058+0x67a4+a*0x8c;if(!p[0x1e])return 0;if(M2C_FIELD(p,u16 *,0x1a)==0)result=1;else result=0;return result;}

u8 func_020d1980(s32 a){extern void **data_027e0058;return ((u8 *)*data_027e0058+a*0x8c)[0x67c2]!=0;}

s32 func_020d19b4(s32 a){extern void **data_027e0058;return (u8)(((u8 *)*data_027e0058+a*0x8c)[0x67c2]==1);}

u8 func_020d19e8(s32 a){extern void **data_027e0058;return ((u8 *)*data_027e0058+a*0x8c)[0x67c2]==2;}

s32 func_020d1a1c(s32 arg0) {
 s32 func_0208485c();
 extern M2C_UNK data_02168f08;
 if(M2C_FIELD(&data_02168f08,u8 *,4)==0)return 1;
 if(func_020d19b4(arg0))return 1;
 if(func_0208485c() && func_020d19e8(arg0))return 1;
 return 0;
}

u8 func_020d1a74(void) {
    s32 func_020a334c();
    u8 var_r0;

    if (func_020a334c() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020d1a90(void) {
 extern void **data_027e0058;
 u16 n=M2C_FIELD(*data_027e0058,u16 *,0x52a4);
 do { n++; if(n==5)n=1; } while(!func_020d1938(n));
 return n<M2C_FIELD(*data_027e0058,u16 *,0x52a4);
}

s32 func_020d1afc(void) {
    s32 func_020d1938(s32);
    s32 var_r5;
    s32 var_r6;

    var_r6 = 1;
    var_r5 = 0;
    do {
        if ((func_020d1938(var_r6) != 0) && (func_020d19b4(var_r6) != 0)) {
            var_r5 = 1;
        }
        var_r6 += 1;
    } while (var_r6 < 5);
    return var_r5;
}

s32 func_020d1b40(void) {
    s32 func_020d19b4(s32);
    s32 func_020d3214(s32);
    s32 var_r4;

    var_r4 = 1;
loop_1:
    if ((func_020d19b4(var_r4) != 0) && (func_020d3214(var_r4) != 0)) {
        return 1;
    }
    var_r4 += 1;
    if (var_r4 >= 5) {
        return 0;
    }
    goto loop_1;
}

void func_020d1b80(void){
void func_020bf85c(void);void func_02091c20(s32,s32);extern void **data_027e0058;
s32 active=func_020d1afc();s32 one=1;u8 *p;
do {
M2C_FIELD(*data_027e0058,u16 *,0x52a4)++;
if(M2C_FIELD(*data_027e0058,u16 *,0x52a4)==5){func_020bf85c();M2C_FIELD(*data_027e0058,u16 *,0x52a4)=one;if(active)func_02091c20(one,one);}
}while(!func_020d1938(M2C_FIELD(*data_027e0058,u16 *,0x52a4)));
p=*data_027e0058;M2C_FIELD(p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,s32 *,0x682c)=0;
}

void func_020d1c38(void) {
    extern void **data_027e0058;
    M2C_FIELD(*data_027e0058, s16 *, 0x52C0) = 0;
}

void func_020d1c58(void){
extern void **data_027e0058;extern u16 data_ov000_021aeef4[];
void func_020cd8a8(void);void func_020cd754(s32);void func_020d0270(void);void func_020cea28(void);
M2C_FIELD(*data_027e0058,u16 *,0x52a6)=M2C_FIELD(*data_027e0058,u16 *,0x52a4)<<5;
M2C_FIELD(*data_027e0058,u16 *,0x52a8)=data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52a4)];
M2C_FIELD(*data_027e0058,u16 *,0x52b6)=M2C_FIELD(*data_027e0058,u16 *,0x52a4);
func_020cd8a8();func_020cd754((u8)M2C_FIELD(*data_027e0058,u16 *,0x52b8));func_020d0270();func_020cea28();
}

void func_020d1ce0(void){
extern void **data_027e0058;void func_020d2d80(s32);void func_020d2d60(s32);void func_020d2d90(s32);s32 func_020d0590(s32);void func_020cf498(s16,s16);void func_020d1d9c(void);u8 *p;
M2C_FIELD(*data_027e0058,u16 *,0x52c0)=0;
func_020d2d80(M2C_FIELD(*data_027e0058,u16 *,0x52a4));
func_020d2d60(M2C_FIELD(*data_027e0058,u16 *,0x52a4));
func_020d2d90(M2C_FIELD(*data_027e0058,u16 *,0x52a4));
if(func_020d0590(M2C_FIELD(*data_027e0058,u16 *,0x52a4))){
p=*data_027e0058;p=p+0x67a4+M2C_FIELD(p,u16 *,0x52a4)*0x8c;func_020cf498(p[0x2d],p[0x2e]);}
func_020d1d9c();
}

void func_020d1d9c(void) {
 void func_020c0a1c(s32); void func_020c09c0(s32);
 extern void **data_027e0058;
 func_020c0a1c(3);
 func_020c09c0(M2C_FIELD(*data_027e0058,u16 *,0x52a4));
}

void func_020d2168(void) {

}

s32 func_020d243c(s32 a){extern void **data_027e0058;return (u8)((((u8 *)*data_027e0058+a*0x8c)[0x67cf]&0x80)==0);}

