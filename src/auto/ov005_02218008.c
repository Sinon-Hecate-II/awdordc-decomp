/* 11 functions from 0x02218008 to 0x02218FD0 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_0221885c(void) {
    M2C_UNK func_020b1c78(s16);
    M2C_UNK func_ov005_02217f6c();
    extern void *data_ov005_02221310;
    func_ov005_02217f6c();
    func_020b1c78(M2C_FIELD(data_ov005_02221310, s16 *, 0xE));
}

void func_ov005_02218db4(M2C_UNK arg0) {
 M2C_UNK func_ov005_0221887c(M2C_UNK); M2C_UNK func_ov005_02218a14(M2C_UNK); M2C_UNK func_ov005_02218bd0(M2C_UNK);
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
 s32 func_020cd1e4(); extern void **data_027e0058; extern u8 data_ov005_02221024[]; extern u8 data_0215c334[]; extern u16 data_0215c340[];
 s32 a,b; u16 x;
 if(func_020cd1e4()) {
 a=0; x=M2C_FIELD(*data_027e0058,u16 *,0x5142);
 if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
 if(a) b=1; else b=0;
 if(b&255) return data_ov005_02221024[(x-0xa1)*2];
 }
 return *(u16 *)((u8 *)data_0215c340 + (s16)data_0215c334[4]*(s16)12);
}

u32 func_ov005_02218edc(void) {
 s32 func_020cd1e4(); extern void **data_027e0058; extern u8 data_ov005_02221024[];
 s32 a,b; u16 x;
 if(func_020cd1e4()) {
 a=0; x=M2C_FIELD(*data_027e0058,u16 *,0x5142);
 if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
 if(a) b=1; else b=0;
 if(b&255) return data_ov005_02221024[(x-0xa1)*2+1];
 }
 return 9;
}

s32 func_ov005_02218f50(void) {
s32 func_020a30c0(u16); extern void **data_027e0058; extern u32 data_ov005_02220ce8[]; extern u8 data_0215c334[]; extern u16 data_0215c340[];
s32 a,b; u16 x;
a=0; x=M2C_FIELD(*data_027e0058,u16 *,0x5142);
if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
if(a) b=1; else b=0;
if(b&255) return data_ov005_02220ce8[x-0xa1];
return func_020a30c0(*(u16 *)((u8 *)data_0215c340 + (s16)data_0215c334[4]*(s16)12));
}

