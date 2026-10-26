/* 19 functions from 0x02211200 to 0x022121F8 (ov005), found by ds-decomp. */
#include "common.h"

s32 func_ov005_0221174c(void) {
s32 func_02086658(s32); s32 func_020af1e4(); s32 func_ov003_021ff7ac(); s32 func_02088624();
func_02086658(4); func_020af1e4(); func_ov003_021ff7ac(); func_02088624();
}

s32 func_ov005_02211988(void *arg0) {
s32 func_020c818c(s32,s32);
extern void **data_027e0058;
return func_020c818c(M2C_FIELD(*data_027e0058,u16 *,0x5142),M2C_FIELD(arg0,s32 *,0x34)+1);
}

void func_ov005_022119b4(void) {
    M2C_UNK func_ov005_02211200();
    func_ov005_02211200();
}

void func_ov005_022119c0(void) {
    M2C_UNK func_ov005_0221174c();
    func_ov005_0221174c();
}

void func_ov005_022119cc(void) {
    M2C_UNK func_ov005_02211768();
    func_ov005_02211768();
}

void func_ov005_022119d8(void) {
    M2C_UNK func_ov005_02211988();
    func_ov005_02211988();
}

void func_ov005_022119e4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    s32 func_020c80ec(u16);
    extern u8 data_02168f0c;
    extern void **data_027e0058;
    extern M2C_UNK data_ov005_022200a0;
    if (data_02168f0c != 0) {
        return;
    }
    if (func_020c80ec(M2C_FIELD(*data_027e0058, u16 *, 0x5142)) == 0) {
        return;
    }
    func_01ffa42c(&data_ov005_022200a0, arg0);
}

s32 func_ov005_02211a38(s32 arg0) {
    extern s32 data_ov005_02221300;
    return (0xA * arg0) + (data_ov005_02221300 + 0x10);
}

u8 func_ov005_02211a54(s32 arg0,s32 arg1) {
s32 func_ov000_0216a3a8(s32,s32);
extern s32 data_ov005_02221300;
u8 result;
if(M2C_FIELD(data_ov005_02221300,u8 *,0)!=0)return 0;
if(func_ov000_0216a3a8(arg0,arg1)==0)result=1;else result=0;
return result;
}

void func_ov005_02211a8c(void) {
extern s32 data_ov005_02221300, gCur3DSpriteEngine,data_027e00c4;
extern M2C_UNK data_ov005_02220270;
s32 func_ov000_0216a38c(s32,s32); s32 func_ov000_0216a414(s32,s32);
void func_0208b758(s32,s32); void func_0208b698(s32,void *);
s32 q,index,old,b,a;
s32 p=data_ov005_02221300;
a=M2C_FIELD(func_ov005_02211a38(M2C_FIELD(p,s8 *,1)),s16 *,2);
b=M2C_FIELD(p,s8 *,2);
a+=b;
b=0;
q=func_ov000_0216a38c(M2C_FIELD(p,s8 *,1),b+a);
index=func_ov000_0216a414(M2C_FIELD(data_ov005_02221300,s8 *,1),b+a);
old=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c4;
if(func_ov005_02211a54(M2C_FIELD(data_ov005_02221300,s8 *,1),b+a)==0)
func_0208b758(M2C_FIELD(data_ov005_02221300,s32 *,0x48),M2C_FIELD(q+index*4,s32 *,0x1c));
else func_0208b698(M2C_FIELD(data_ov005_02221300,s32 *,0x48),&data_ov005_02220270);
gCur3DSpriteEngine=old;
}

void func_ov005_02211b4c(void) {
    s32 func_0207c8ec(s32, s32);
    extern M2C_UNK data_0215d9b8;
    extern s32 data_ov005_02221300;
    s32 timeVal;

    timeVal = M2C_FIELD(&data_0215d9b8, s32 *, 0x74);
    M2C_FIELD(data_ov005_02221300, s32 *, 4) = func_0207c8ec(timeVal, 0x34BC0);
    if (M2C_FIELD(data_ov005_02221300, s32 *, 4) > 0x3E7) {
        M2C_FIELD(data_ov005_02221300, s32 *, 4) = 0x3E7;
        M2C_FIELD(data_ov005_02221300, s32 *, 8) = 0x3B;
        M2C_FIELD(data_ov005_02221300, s32 *, 12) = 0x3B;
        return;
    }
    M2C_FIELD(data_ov005_02221300, s32 *, 8) = func_0207c8ec(timeVal, 0xE10) % 60;
    M2C_FIELD(data_ov005_02221300, s32 *, 12) = func_0207c8ec(timeVal, 0x3C) % 60;
}

void func_ov005_02211c24(s32 arg0) {
s32 p=func_ov005_02211a38(arg0);
s32 q=func_ov000_0216a38c(arg0,0);
M2C_FIELD(p,s16 *,8)=0; M2C_FIELD(p,s16 *,6)=0;
while(M2C_FIELD(q,s32 *,0)) {
if(!func_ov005_02211a54(arg0,M2C_FIELD(p,s16 *,8))) M2C_FIELD(p,s16 *,6)++;
M2C_FIELD(p,s16 *,8)++;
q+=0x30;
}
}

void func_ov005_02211c94(void) {
extern s32 data_ov005_02221300;
M2C_FIELD(data_ov005_02221300,s32 *,0x34)=func_ov000_0216a77c(func_ov000_0216a76c());
M2C_FIELD(data_ov005_02221300,s32 *,0x38)=func_ov000_0216a7d4(func_ov000_0216a7c4());
M2C_FIELD(data_ov005_02221300,u8 *,0x32)=func_ov000_0216a564(func_ov000_0216a470());
M2C_FIELD(data_ov005_02221300,s32 *,0x3c)=func_ov000_0216a59c(func_ov000_0216a564(func_ov000_0216a470()));
}

s32 func_ov005_02212118(void) {
extern s32 data_ov005_02221300;
void func_0208fe30(s32);
s32 p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
s32 n=M2C_FIELD(p,s16 *,2);
if(!n)return 0;
M2C_FIELD(p,s16 *,2)=n-1;
func_0208fe30(0x10019);func_ov005_02211a8c();return 1;
}

s16 func_ov005_02212160(void) {
extern s32 data_ov005_02221300;
s32 p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
s16 old=M2C_FIELD(p,s16 *,2);
M2C_FIELD(p,s16 *,2)=old-7;
if(M2C_FIELD(p,s16 *,2)<0)M2C_FIELD(p,s16 *,2)=0;
return M2C_FIELD(p,s16 *,2)-old;
}

s32 func_ov005_022121a8(void) {
extern s32 data_ov005_02221300;
void func_0208fe30(s32);
s32 p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
s16 n=M2C_FIELD(p,s16 *,2);
s32 next=n+7;
if(next>=M2C_FIELD(p,s16 *,8))return 0;
M2C_FIELD(p,s16 *,2)++;
func_0208fe30(0x10019);
func_ov005_02211a8c();
return 1;
}

