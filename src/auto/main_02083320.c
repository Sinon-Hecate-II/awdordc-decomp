/* 14 functions from 0x02083320 to 0x02084304 (main), found by ds-decomp. */
#include "common.h"
extern s32 gCur3DSpriteEngine;
extern u8 data_027e0074[];
extern u8 data_02101fdc[];
void func_01ffaacc(u16,u16,u16,void *,s32);

typedef struct { u16 unused:13; u16 mode:2; u16 last:1; } DrawControl;
typedef struct { u8 pad[15]; u8 low:4; u8 high:4; } Unk0208349c;
typedef struct { u8 pad[0x44]; s8 values[16]; } Unk0208352c;

u8 func_02083320(s32 arg0,s32 arg1) {
 s32 func_020846a4();
 if(func_020846a4()==0) return 1;
 return (u8)((s32)(u16)(arg0-225)/50)==(u8)(arg1-8);
}

void func_0208337c(void) {
 extern s8 data_02156cdc;
 s32 i,j; s8 *p,*a,*b;
 a=&data_02156cdc; i=0; b=a;
 do { j=0; *a=0;
 do { p=b+j; M2C_FIELD(p,s8 *,169)=0; ++j; M2C_FIELD(p,s8 *,13)=0; }while(j<12);
 ++i; ++a; b+=12;
 }while(i<13);
}

void func_020833d0(void) {
 extern s8 data_02156cdc;
 s32 i,j; s8 *p,*a,*b;
 a=&data_02156cdc; i=0; b=a;
 do { switch(i) {
 case 1: case 3: case 4: case 5: case 6: case 9: case 10: case 11: case 12:
 j=0; *a=0;
 do { p=b+j; M2C_FIELD(p,s8 *,169)=0; ++j; M2C_FIELD(p,s8 *,13)=0; }while(j<12);
 break; default: break;
 }
 ++i; ++a; b+=12;
 }while(i<13);
}

void func_02083464(void) {
 extern void *data_02101fd4;
 s32 i;
 M2C_FIELD(data_02101fd4,u8 *,17)&=~1;
 for(i=0;i<14;i++) M2C_FIELD(data_02101fd4,u8 *,i)=0;
}

void func_0208349c(s32 arg0) {
 extern void *data_02101fd4;
 ((Unk0208349c *)data_02101fd4)->high=(u8)arg0;
}

void func_020834c4(void) {
 extern void *data_02101fd4;
 s32 i;
 M2C_FIELD(data_02101fd4,u8 *,17)=0;
 func_0208349c(0); func_02083464();
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,15)=0;
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,16)=16;
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,17)=16;
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,18)=0;
 for(i=0;i<15;i++) M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,i)=0;
}

void func_0208352c(void *arg0) {
 M2C_UNK func_01ffa8c4(void *,M2C_UNK);
 s32 func_0207ca38(s32,s32,s32,s32,s32);
 s32 i,n,a;
 i=0; M2C_FIELD(arg0,u16 *,0x54)=0;
 if(M2C_FIELD(arg0,u8 *,0x62)==0) {func_01ffa8c4(arg0,0);return;}
 n=M2C_FIELD(arg0,u16 *,0x5a);
 if(n<=0) return;
 do {
 a=func_0207ca38(0,0,48,i,M2C_FIELD(arg0,volatile u16 *,0x5a)-1);
 a=(a+func_0207ca38(4,0,48,i,n-1))>>1;
 M2C_FIELD(arg0,volatile s8 *,i+0x44)=a;
 n=M2C_FIELD(arg0,u16 *,0x5a);
 ++i;
 }while(i<n);
}

void func_020841c8(void *a){
s32 i; u16 x,y; void *p;
x=M2C_FIELD(a,u16 *,0x56);y=M2C_FIELD(a,u16 *,0x58);
for(i=0;i<M2C_FIELD(a,u16 *,0x5a);i++){
p=(char*)a+(u32)i;
func_01ffaacc((u16)(x&511),(u16)(y&255),(u16)(M2C_FIELD(a,u16 *,0x60)|(((M2C_FIELD(a,u16 *,0x5c)+(M2C_FIELD(p,s8 *,0x34)<<3))>>(((**(DrawControl ***)&gCur3DSpriteEngine)->mode)))&1023)+((M2C_FIELD(a,u16 *,0x5e)&15)<<12)),data_027e0074,M2C_FIELD(a,s8 *,0x63));
if(M2C_FIELD(p,s8 *,0x34)==255)x+=14;
else x+=data_02101fdc[M2C_FIELD(p,s8 *,0x34)]-2;
}}

void func_020842b4(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02101ff8;
    extern M2C_UNK data_02102040;
    func_01ffa9e4(&data_02101ff8);
    func_01ffa9e4(&data_02102040);
}

void func_020842d4(void) {
    extern s32 data_027e00c4;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020842b4();
    gCur3DSpriteEngine = temp_r4;
}

