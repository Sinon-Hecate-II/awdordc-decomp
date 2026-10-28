/* 11 functions from 0x02218008 to 0x02218FD0 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_02218008(void *arg0) {
}

void func_ov005_0221885c(void) {
    M2C_UNK func_020b1c78(s16);
    M2C_UNK func_ov005_02217f6c();
    extern void *data_ov005_02221310;
    func_ov005_02217f6c();
    func_020b1c78(M2C_FIELD(data_ov005_02221310, s16 *, 0xE));
}

void func_ov005_0221887c(M2C_UNK arg0) {
extern void *data_ov005_02221310; extern void *gCur3DSpriteEngine; extern void *data_027e00c8;
extern u8 data_ov005_022209d8[],data_ov005_022209ec[],data_ov005_02220a04[];
void func_020a9a30(s32,s32,u8,void *); void *func_020e3218(void *); void func_020814e4(void *); void func_020816cc(void *,void *,s32,s32); void func_02081528(void); void func_ov005_0221730c(void); void func_ov005_0221760c(void);
void *saved; void *engine; s32 flag;
if(M2C_FIELD(data_ov005_02221310,s16 *,2)!=M2C_FIELD(data_ov005_02221310,s16 *,4)){
if(M2C_FIELD(data_ov005_02221310,s16 *,4)==0) flag=1; else flag=0;
saved=gCur3DSpriteEngine; engine=data_027e00c8; gCur3DSpriteEngine=engine;
func_020a9a30(0,0,(u8)(s16)flag,(u8 *)M2C_FIELD(engine,void **,0x1c)+0x6b80);
M2C_FIELD(M2C_FIELD(data_ov005_02221310,void **,0x24),u16 *,0x3e)=0x35c;
gCur3DSpriteEngine=saved;
}
if(M2C_FIELD(data_ov005_02221310,s16 *,2)!=M2C_FIELD(data_ov005_02221310,s16 *,4)){
func_ov005_0221730c(); saved=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
func_020814e4(func_020e3218(data_ov005_022209d8));
if(M2C_FIELD(data_ov005_02221310,s16 *,4)==0) func_020816cc(func_020e3218(data_ov005_022209ec),M2C_FIELD(gCur3DSpriteEngine,void **,0x28),0,0);
else func_020816cc(func_020e3218(data_ov005_02220a04),M2C_FIELD(gCur3DSpriteEngine,void **,0x28),0,0);
func_02081528(); M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4; gCur3DSpriteEngine=saved;
}
if(M2C_FIELD(data_ov005_02221310,s16 *,0xc)!=M2C_FIELD(data_ov005_02221310,s16 *,0xe)) func_ov005_0221760c();
if(M2C_FIELD(data_ov005_02221310,s16 *,6)>0) M2C_FIELD(data_ov005_02221310,s16 *,6)--;
M2C_FIELD(data_ov005_02221310,s16 *,2)=M2C_FIELD(data_ov005_02221310,s16 *,4);
M2C_FIELD(data_ov005_02221310,s16 *,0xc)=M2C_FIELD(data_ov005_02221310,s16 *,0xe);
}

void func_ov005_02218a14(M2C_UNK arg0) {
u32 func_020719d4(s32); u32 func_02071a64(u32,u32); u32 func_02071564(u32,u32); u32 func_02070f24(u32,u32); s32 func_020719a0(u32);
M2C_UNK func_ov005_02217f6c(); M2C_UNK func_020b1c78(s16); void func_01ffa6fc(s32); M2C_UNK func_020b2178(); void func_0208fe30(s32); s32 func_020bf894(s16); void func_0208b758(void *,u32); s16 func_020bf8cc(s16); void func_ov005_02217334(s16);
extern void *data_ov005_02221310; extern u16 *data_02101e84;
void *p=data_ov005_02221310; s32 n=M2C_FIELD(p,s16 *,6); u32 f;
f=func_02071a64(-0x3c800000,func_020719d4(n)); f=func_02071a64(f,func_020719d4(n)); f=func_02071564(f,func_020719d4(225)); M2C_FIELD(p,s16 *,8)=func_020719a0(f);
f=func_02071a64(-0x3c800000,func_020719d4(n)); f=func_02071a64(f,func_020719d4(n)); f=func_02071564(f,func_020719d4(225)); M2C_FIELD(data_ov005_02221310,s16 *,10)=func_020719a0(func_02070f24(0x43800000,f));
if(M2C_FIELD(data_ov005_02221310,s16 *,6)==1){func_ov005_02217f6c();func_020b1c78(M2C_FIELD(data_ov005_02221310,s16 *,14));}
if(M2C_FIELD(data_ov005_02221310,s16 *,6)>0)return;
if(*data_02101e84&2){func_01ffa6fc(arg0);func_020b2178();func_0208fe30(0x1000f);return;}
if((*data_02101e84&1) && func_020bf894(M2C_FIELD(data_ov005_02221310,s16 *,16))){
func_0208b758(M2C_FIELD(data_ov005_02221310,void **,28),0x40000001);
M2C_FIELD(data_ov005_02221310,s16 *,4)=1;M2C_FIELD(data_ov005_02221310,s16 *,6)=15;
M2C_FIELD(data_ov005_02221310,s16 *,20)=func_020bf8cc(M2C_FIELD(data_ov005_02221310,s16 *,16));
func_ov005_02217334(M2C_FIELD(data_ov005_02221310,s16 *,20));func_020b2178();func_0208fe30(0x10016);
}
}

void func_ov005_02218bd0(M2C_UNK arg0){
extern void *data_ov005_02221310;extern u16 *data_02101e84;
u32 func_020719d4(s32);u32 func_02071a64(u32,u32);u32 func_02071564(u32,u32);u32 func_02070f24(u32,u32);s32 func_020719a0(u32);
void func_ov005_02217fc8(void);M2C_UNK func_020b1c78(s16);void func_020bf8fc(s32,s32);void func_ov005_022173b4(s32);void func_0208b758(void *,u32);M2C_UNK func_020b2178();void func_0208fe30(s32);
void *p=data_ov005_02221310;s32 t=M2C_FIELD(p,s16 *,6);u32 v;
v=func_02071a64(0x43800000,func_020719d4(t));v=func_02071a64(v,func_020719d4(t));v=func_02071564(v,func_020719d4(225));
M2C_FIELD(p,s16 *,8)=func_020719a0(func_02070f24(0xc3800000,v));
v=func_02071a64(0x43800000,func_020719d4(t));v=func_02071a64(v,func_020719d4(t));v=func_02071564(v,func_020719d4(225));
M2C_FIELD(data_ov005_02221310,s16 *,10)=func_020719a0(v);
if(M2C_FIELD(data_ov005_02221310,s16 *,6)==1){func_ov005_02217fc8();func_020b1c78(M2C_FIELD(data_ov005_02221310,s16 *,0x12));}
if(M2C_FIELD(data_ov005_02221310,s16 *,6)>0)return;
if(*data_02101e84&2){
func_020bf8fc(M2C_FIELD(data_ov005_02221310,s16 *,0x10),M2C_FIELD(data_ov005_02221310,s16 *,0x14));
func_ov005_022173b4(M2C_FIELD(data_ov005_02221310,s16 *,0x10));
func_0208b758(M2C_FIELD(data_ov005_02221310,void **,0x1c),0x40000000);
M2C_FIELD(data_ov005_02221310,s16 *,4)=0;M2C_FIELD(data_ov005_02221310,s16 *,6)=15;
func_020b2178();func_0208fe30(0x1000f);return;
}
if(*data_02101e84&1){
if(M2C_FIELD(data_ov005_02221310,s16 *,0x14)!=M2C_FIELD(data_ov005_02221310,s16 *,0x12))M2C_FIELD(data_ov005_02221310,u8 *,0)=1;
M2C_FIELD(data_ov005_02221310,s16 *,0x14)=M2C_FIELD(data_ov005_02221310,s16 *,0x12);
func_0208b758(M2C_FIELD(data_ov005_02221310,void **,0x1c),0x40000000);
M2C_FIELD(data_ov005_02221310,s16 *,4)=0;M2C_FIELD(data_ov005_02221310,s16 *,6)=15;
func_020b2178();func_0208fe30(0x10016);
}
}

void func_ov005_02218db4(M2C_UNK arg0) {
   
 extern void *data_ov005_02221310;
 func_ov005_0221887c(arg0);
 switch(M2C_FIELD(data_ov005_02221310,s16 *,4)) {case 0: func_ov005_02218a14(arg0); return; case 1: func_ov005_02218bd0(arg0); return;}
}

void func_ov005_02218dfc(void) {
 M2C_UNK func_020af1e4(); M2C_UNK func_020842d4(); M2C_UNK func_020b2178(); M2C_UNK func_020e35cc(); M2C_UNK func_02086658(s32);
 extern void *data_ov005_02221310;
 func_020af1e4(); func_020842d4(); func_020b2178();
 if(data_ov005_02221310) {func_020e35cc(); data_ov005_02221310=0;}
 func_02086658(10);
}

void func_ov005_02218e3c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220850;
    func_01ffa42c(&data_ov005_02220850, arg0);
}

u32 func_ov005_02218e54(void) {
 s32 func_020cd1e4(); extern void **gCurrentMap; extern u8 data_ov005_02221024[]; extern u8 data_0215c334[]; extern u16 data_0215c340[];
 s32 a,b; u16 x;
 if(func_020cd1e4()) {
 a=0; x=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
 if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
 if(a) b=1; else b=0;
 if(b&255) return data_ov005_02221024[(x-0xa1)*2];
 }
 return *(u16 *)((u8 *)data_0215c340 + (s16)data_0215c334[4]*(s16)12);
}

u32 func_ov005_02218edc(void) {
 s32 func_020cd1e4(); extern void **gCurrentMap; extern u8 data_ov005_02221024[];
 s32 a,b; u16 x;
 if(func_020cd1e4()) {
 a=0; x=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
 if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
 if(a) b=1; else b=0;
 if(b&255) return data_ov005_02221024[(x-0xa1)*2+1];
 }
 return 9;
}

s32 func_ov005_02218f50(void) {
s32 func_020a30c0(u16); extern void **gCurrentMap; extern u32 data_ov005_02220ce8[]; extern u8 data_0215c334[]; extern u16 data_0215c340[];
s32 a,b; u16 x;
a=0; x=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
if(a) b=1; else b=0;
if(b&255) return data_ov005_02220ce8[x-0xa1];
return func_020a30c0(*(u16 *)((u8 *)data_0215c340 + (s16)data_0215c334[4]*(s16)12));
}

