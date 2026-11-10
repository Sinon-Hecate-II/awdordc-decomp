/* 1 function from 0x021F40A8 to 0x021F66D4 (ov003), found by ds-decomp. */
#include "common.h"
#define OV3KIND(a) (M2C_FIELD((a), u8 *, 0x3b) & 0xf)

#pragma push
#pragma inline_depth(0)
void func_ov003_021f40a8(void *arg0) {
    void func_ov003_021f1b7c(s32, void *);
    void func_ov003_021f1b38(s32, void *);
    void func_01ff9b38(void);
    void *func_020896f0(void *);
    void func_020893f4(void *, void *, s32);
    void func_02089438(void *);
    void func_02088da8(void *);
    void *func_0208bc24(void *);
    void func_0208b758(void *, s32);
    void func_02088f1c(void *);
    void func_ov003_021f14a0(void);
    void func_ov006_02217464(void *);
    void ScrollListTo(void *, s32, s32);
    void *MemAlloc(s32);
    extern u16 data_ov003_0220fde8;
    extern u16 data_ov003_0220fdf0;
    extern u16 data_ov003_0220fdea;
    extern u16 data_ov003_0220fdee;
    extern u16 data_ov003_0220fdec;
    extern u16 data_ov003_0220fde4;
    extern u8 data_ov003_022100e4[16];
    extern u8 data_ov003_0220fb28[16];
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern u8 data_ov003_022100f4[16];
    void *func_020e34bc(s32);
    void func_02007f8c(void *,s32,s32);
    s32 func_0207c928(s32,s32);
    s32 func_0207c8ec(s32,s32);
    void func_02087d18(void *,s16,s16,s32,s32,u16,s32);
    void *func_020ab1c4(void *);
    void func_020aab24(void *,s32,s32,s32,s32);
    void func_02088e84(void *,s32,s32,s32,s32);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    void func_02087d84(void *,s32,s16,s16,u16,u16);
    void func_020830ec(s32,void *,s32);
    void *list;
    void *p;
    s32 n,x,y; s32 i;
    void *q;
    void *o;
    void *saved;

    list=(u8 *)M2C_FIELD(arg0,void **,0x44)+0x2e;
    func_ov003_021f1b7c(0, &data_ov003_0220fde8);
    func_ov003_021f1b7c(1, &data_ov003_0220fdf0);
    func_ov003_021f1b7c(3, &data_ov003_0220fdea);
    func_01ff9b38();
    q = M2C_FIELD(arg0, void **, 0x6c);
    o = func_020896f0(arg0);
    M2C_FIELD(q, void **, 0) = o;
    func_020893f4(o, (void *)0x8b80, 1);
    o = M2C_FIELD(q, void **, 0);
    M2C_FIELD(o, u16 *, 0x34) = 6;
    M2C_FIELD(o, u16 *, 0x36) = 0x28;
    M2C_FIELD(o, u32 *, 0x40) =
        (((M2C_FIELD(o, u32 *, 0x40) & 0xFFFFFE00) | 0x70) & 0xFFFC01FF) | 0x1E00;
    func_02089438(M2C_FIELD(q, void **, 0));
    o = M2C_FIELD(q, void **, 0);
    M2C_FIELD(o, u16 *, 0x3c) = 0x400;
    o = M2C_FIELD(q, void **, 0);
    M2C_FIELD(o, u8 *, 0x58) = 1;
    o = M2C_FIELD(q, void **, 0);
    func_02088da8(o);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    o = func_0208bc24(arg0);
    M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4) = o;
    M2C_FIELD(o, u16 *, 0x3e) = 0x36c;
    o = M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4);
    M2C_FIELD(o, u32 *, 0x40) = (M2C_FIELD(o, u32 *, 0x40) & ~0x3FC0000) | 0x300000;
    o = M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4);
    func_02088da8(o);
    gCur3DSpriteEngine = saved;
    if ((u8)(OV3KIND(arg0) == 4)) {
        func_0208b758(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4), 0x4700001d);
    } else if ((u8)(OV3KIND(arg0) == 6)) {
        func_0208b758(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4), 0x47000025);
    } else if ((u8)(OV3KIND(arg0) == 7)) {
        func_0208b758(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4), 0x47000026);
    } else if ((u8)(OV3KIND(arg0) == 8)) {
        func_0208b758(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4), 0x47000027);
    } else {
        func_0208b758(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4), 0x47000013);
    }
    func_02088f1c(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c), void **, 4));
    if ((u8)(OV3KIND(arg0) == 4)) {
        func_ov003_021f14a0();
    }
    if ((u8)(OV3KIND(arg0) == 5) || (u8)(OV3KIND(arg0) == 1)) {
 func_02088da8(M2C_FIELD(q, void **, 0));
 }
 if ((u8)(OV3KIND(arg0) == 6)) {
        func_ov006_02217464(arg0);
    }
    if ((u8)(OV3KIND(arg0) == 0) || (u8)(OV3KIND(arg0) == 2) || (u8)(OV3KIND(arg0) == 3) ||
        (u8)(OV3KIND(arg0) == 4) || (u8)(OV3KIND(arg0) == 6) || (u8)(OV3KIND(arg0) == 7) ||
        (u8)(OV3KIND(arg0) == 8)) {
        func_ov003_021f1b38(0, &data_ov003_0220fdee);
        func_ov003_021f1b38(1, &data_ov003_0220fdec);
        func_ov003_021f1b38(3, &data_ov003_0220fde4);
        func_01ff9b38();
        o = MemAlloc(0x68);
        if (o) {
            M2C_FIELD(o, void **, 0) = &data_ov003_022100e4;
            M2C_FIELD(o, u8 *, 0x4) = 0;
            M2C_FIELD(o, u16 *, 0x6) = 7;
            M2C_FIELD(o, u16 *, 0x8) = 2;
            M2C_FIELD(o, u8 *, 0xa) = 0x10;
            M2C_FIELD(o, u8 *, 0xb) = 0x78;
            M2C_FIELD(o, void **, 0x10) = &data_ov003_0220fb28;
            M2C_FIELD(o, u32 *, 0x14) = 0;
            M2C_FIELD(o, u32 *, 0x18) = 0;
            M2C_FIELD(o, u32 *, 0x1c) = 0;
            M2C_FIELD(o, u32 *, 0x20) = 1;
            M2C_FIELD(o, u8 *, 0x24) = 1;
            M2C_FIELD(o, u16 *, 0x28) = 0;
            M2C_FIELD(o, u16 *, 0x2a) = 0;
            M2C_FIELD(o, u16 *, 0x2c) = 0;
            M2C_FIELD(o, u16 *, 0x2e) = 0;
            M2C_FIELD(o, u8 *, 0x30) = 1;
            M2C_FIELD(o, u8 *, 0x31) = 0;
            M2C_FIELD(o, u16 *, 0x32) = 0;
            M2C_FIELD(o, u16 *, 0x34) = 0;
            M2C_FIELD(o, u16 *, 0x36) = 1;
            M2C_FIELD(o, u16 *, 0x38) = 0;
            M2C_FIELD(o, u16 *, 0x3a) = 1;
            M2C_FIELD(o, u16 *, 0x3c) = 1;
            M2C_FIELD(o, u16 *, 0x3e) = 0;
            M2C_FIELD(o, u16 *, 0x40) = 0;
            M2C_FIELD(o, u16 *, 0x32) = M2C_FIELD(o, u16 *, 0x34);
            M2C_FIELD(o, u8 *, 0x42) = 4;
            M2C_FIELD(o, u8 *, 0x43) = 0;
            M2C_FIELD(o, u16 *, 0x44) = 0;
            M2C_FIELD(o, u16 *, 0x46) = 0;
            M2C_FIELD(o, u16 *, 0x48) = 1;
            M2C_FIELD(o, u16 *, 0x4a) = 0;
            M2C_FIELD(o, u16 *, 0x4c) = 1;
            M2C_FIELD(o, u16 *, 0x4e) = 1;
            M2C_FIELD(o, u16 *, 0x50) = 0;
            M2C_FIELD(o, u16 *, 0x52) = 0;
            M2C_FIELD(o, u16 *, 0x44) = M2C_FIELD(o, u16 *, 0x46);
            M2C_FIELD(o, u8 *, 0x54) = 4;
            M2C_FIELD(o, u8 *, 0x55) = 0;
            M2C_FIELD(o, u16 *, 0x56) = 0;
            M2C_FIELD(o, u16 *, 0x58) = 0;
            M2C_FIELD(o, u16 *, 0x5a) = 1;
            M2C_FIELD(o, u16 *, 0x5c) = 0;
            M2C_FIELD(o, u16 *, 0x5e) = 1;
            M2C_FIELD(o, u16 *, 0x60) = 1;
            M2C_FIELD(o, u16 *, 0x62) = 0;
            M2C_FIELD(o, u16 *, 0x64) = 0;
            M2C_FIELD(o, u16 *, 0x56) = M2C_FIELD(o, u16 *, 0x58);
            M2C_FIELD(o, u16 *, 0x28) = 0;
            M2C_FIELD(o, u16 *, 0x2a) = 0;
            M2C_FIELD(o, u16 *, 0x2c) = 0;
            M2C_FIELD(o, u16 *, 0x2e) = 0;
            M2C_FIELD(o, u16 *, 0x3e) = 0;
            M2C_FIELD(o, u16 *, 0x40) = 0;
            M2C_FIELD(o, u16 *, 0x3c) = 4;
            M2C_FIELD(o, u16 *, 0x32) = M2C_FIELD(o, u16 *, 0x34);
            M2C_FIELD(o, u16 *, 0x50) = 0;
            M2C_FIELD(o, u16 *, 0x52) = 0;
            M2C_FIELD(o, u16 *, 0x4e) = 5;
            M2C_FIELD(o, u16 *, 0x44) = M2C_FIELD(o, u16 *, 0x46);
            M2C_FIELD(o, u16 *, 0x62) = 0;
            M2C_FIELD(o, u16 *, 0x64) = 0;
            M2C_FIELD(o, u16 *, 0x60) = 5;
            M2C_FIELD(o, u16 *, 0x56) = M2C_FIELD(o, u16 *, 0x58);
            M2C_FIELD(arg0, void **, 0x4c) = o;
            M2C_FIELD(o, u16 *, 0x28) = 0;
            M2C_FIELD(o, u16 *, 0x2a) = 0;
            M2C_FIELD(o, u16 *, 0x2c) = 0;
            M2C_FIELD(o, u16 *, 0x2e) = 0;
            ScrollListTo(M2C_FIELD(arg0, void **, 0x4c), 0, 1);
        }
o=MemAlloc(0x18); if(o){
M2C_FIELD(o, void * *, 0) = &data_ov003_0220fb28;
M2C_FIELD(o, u32 *, 4) = 0;
M2C_FIELD(o, u32 *, 8) = 0;
M2C_FIELD(o, u32 *, 12) = 0;
M2C_FIELD(o, u32 *, 16) = 1;
M2C_FIELD(o, u8 *, 20) = 1;
}
M2C_FIELD(arg0, void **, 0x5c)=o;
o=MemAlloc(0x34); if(o){
M2C_FIELD(o, void * *, 0) = &data_ov003_022100f4;
M2C_FIELD(o, u16 *, 4) = 0;
M2C_FIELD(o, void * *, 8) = &data_ov003_0220fb28;
M2C_FIELD(o, u32 *, 12) = 0;
M2C_FIELD(o, u32 *, 16) = 0;
M2C_FIELD(o, u32 *, 20) = 0;
M2C_FIELD(o, u32 *, 24) = 1;
M2C_FIELD(o, u8 *, 28) = 1;
M2C_FIELD(o, u8 *, 32) = 4;
M2C_FIELD(o, u8 *, 33) = 0;
M2C_FIELD(o, u16 *, 34) = 0;
M2C_FIELD(o, u16 *, 36) = 0;
M2C_FIELD(o, u16 *, 40) = 0;
M2C_FIELD(o, u16 *, 46) = 0;
M2C_FIELD(o, u16 *, 48) = 0;
M2C_FIELD(o, u16 *, 38) = 1;
M2C_FIELD(o, u16 *, 42) = 1;
M2C_FIELD(o, u16 *, 44) = 1;
M2C_FIELD(o, u16 *, 34) = M2C_FIELD(o,u16 *,36);
}
M2C_FIELD(arg0,void **,0x60)=o;
M2C_FIELD(o, u16 *, 4) = 0x70;
M2C_FIELD(M2C_FIELD(arg0,void **,0x60),u16 *,0x2c)=12;
o=MemAlloc(0x12); if(o){
M2C_FIELD(o, u8 *, 0) = 4;
M2C_FIELD(o, u8 *, 1) = 0;
M2C_FIELD(o, u16 *, 2) = 0;
M2C_FIELD(o, u16 *, 4) = 0;
M2C_FIELD(o, u16 *, 8) = 0;
M2C_FIELD(o, u16 *, 14) = 0;
M2C_FIELD(o, u16 *, 16) = 0;
M2C_FIELD(o, u16 *, 6) = 1;
M2C_FIELD(o, u16 *, 10) = 1;
M2C_FIELD(o, u16 *, 12) = 1;
M2C_FIELD(o, u16 *, 2) = M2C_FIELD(o,u16 *,4);
}
M2C_FIELD(arg0,void **,0x58)=o;
M2C_FIELD(o, u16 *, 14) = 0;
M2C_FIELD(o, u16 *, 16) = 0;
M2C_FIELD(o, u16 *, 12) = 12;
M2C_FIELD(o, u16 *, 2) = M2C_FIELD(o,u16 *,4);
o=MemAlloc(0x12); if(o){
M2C_FIELD(o, u8 *, 0) = 4;
M2C_FIELD(o, u8 *, 1) = 0;
M2C_FIELD(o, u16 *, 2) = 0;
M2C_FIELD(o, u16 *, 4) = 0;
M2C_FIELD(o, u16 *, 8) = 0;
M2C_FIELD(o, u16 *, 14) = 0;
M2C_FIELD(o, u16 *, 16) = 0;
M2C_FIELD(o, u16 *, 6) = 1;
M2C_FIELD(o, u16 *, 10) = 1;
M2C_FIELD(o, u16 *, 12) = 1;
M2C_FIELD(o, u16 *, 2) = M2C_FIELD(o,u16 *,4);
}
M2C_FIELD(arg0,void **,0x64)=o;
M2C_FIELD(o, u16 *, 14) = 0;
M2C_FIELD(o, u16 *, 16) = 0;
M2C_FIELD(o, u16 *, 12) = 12;
M2C_FIELD(o, u16 *, 2) = M2C_FIELD(o,u16 *,4);
o=MemAlloc(0x28); if(o){
M2C_FIELD(o, u32 *, 0) = 0;
M2C_FIELD(o, u32 *, 4) = 0;
M2C_FIELD(o, u32 *, 8) = 0;
M2C_FIELD(o, u32 *, 12) = 0;
M2C_FIELD(o, u32 *, 16) = 0;
M2C_FIELD(o, u32 *, 20) = 0;
M2C_FIELD(o, u32 *, 24) = 0;
M2C_FIELD(o, u32 *, 28) = 0;
M2C_FIELD(o, u32 *, 32) = 0;
M2C_FIELD(o, u32 *, 36) = 0;
}
M2C_FIELD(arg0,void **,0x68)=o;
o=MemAlloc(0x24); if(o){
 p=M2C_FIELD(arg0,void **,0x4c); n=(s16)(M2C_FIELD(p,s16 *,6)*M2C_FIELD(p,s16 *,8));
M2C_FIELD(o, s16 *, 16) = n;
M2C_FIELD(o, u8 *, 18) = 0;
M2C_FIELD(o, u32 *, 0) = 0;
M2C_FIELD(o, u32 *, 4) = 0;
M2C_FIELD(o, u8 *, 8) = -1;
M2C_FIELD(o, u8 *, 9) = -1;
M2C_FIELD(o, u8 *, 10) = -1;
M2C_FIELD(o, u8 *, 11) = -1;
M2C_FIELD(o, u8 *, 13) = 255;
M2C_FIELD(o, u8 *, 12) = -1;
M2C_FIELD(o, u8 *, 14) = 0;
M2C_FIELD(o, u8 *, 15) = 255;
n=(s16)n*12; M2C_FIELD(o,void **,20)=func_020e34bc(n); func_02007f8c(M2C_FIELD(o,void **,20),0,n);
}
M2C_FIELD(arg0,void **,0x70)=o;
for(i=0; i<(s16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,6)*M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,8));i++){
 n=M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,8);
 x=func_0207c928(i,n); y=func_0207c8ec(i,n);
 func_02087d18(M2C_FIELD(arg0,void **,0x70),(s16)(x*120+6),(s16)(y*16+40),120,16,(u16)(i+10),14);
}
p=M2C_FIELD(arg0,void **,0x68);
M2C_FIELD(p,void **,0)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,0),1,320,3,1);{void *sprite=M2C_FIELD(p,void **,0);func_02088e84(sprite,192,160,192,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,0));
M2C_FIELD(p,void **,4)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,4),68,336,3,1);{void *sprite=M2C_FIELD(p,void **,4);func_02088e84(sprite,0,160,0,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,4));
M2C_FIELD(p,void **,8)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,8),69,352,3,1);{void *sprite=M2C_FIELD(p,void **,8);func_02088e84(sprite,0,160,0,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,8));
M2C_FIELD(p,void **,12)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,12),2,368,3,0);{void *sprite=M2C_FIELD(p,void **,12);func_02088e84(sprite,224,160,224,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,12));
M2C_FIELD(p,void **,16)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,16),14,416,3,0);{void *sprite=M2C_FIELD(p,void **,16);func_02088e84(sprite,56,-32,56,-32);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}M2C_FIELD(sprite,s16 *,0x34)=56;M2C_FIELD(sprite,s16 *,0x36)=-32;if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,16));
M2C_FIELD(p,void **,20)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,20),15,432,3,0);{void *sprite=M2C_FIELD(p,void **,20);func_02088e84(sprite,168,-32,168,-32);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}M2C_FIELD(sprite,s16 *,0x34)=168;M2C_FIELD(sprite,s16 *,0x36)=-32;if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,20));
M2C_FIELD(p,void **,24)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,24),10,448,3,0);{void *sprite=M2C_FIELD(p,void **,24);func_02088e84(sprite,90,116,90,116);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}if((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)){s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,96,156,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,24));
M2C_FIELD(p,void **,28)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,28),11,464,3,0);{void *sprite=M2C_FIELD(p,void **,28);func_02088e84(sprite,122,116,122,116);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}if((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)){s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,128,156,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,28));
M2C_FIELD(p,void **,32)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,32),27,480,3,0);{void *sprite=M2C_FIELD(p,void **,32);func_02088e84(sprite,0,160,0,160);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,32));
M2C_FIELD(p,void **,36)=func_020ab1c4(arg0);func_020aab24(M2C_FIELD(p,void **,36),70,384,3,0);{void *sprite=M2C_FIELD(p,void **,36);func_02088e84(sprite,160,160,160,160);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(p,void **,36));

if((u8)(OV3KIND(arg0)==0))func_020830ec(0,list,0);
else if((u8)(OV3KIND(arg0)==2)||(u8)(OV3KIND(arg0)==6)||(u8)(OV3KIND(arg0)==7)||(u8)(OV3KIND(arg0)==8))func_020830ec(7,list,0);
else if((u8)(OV3KIND(arg0)==4))func_020830ec(6,list,0);
else if((u8)(OV3KIND(arg0)==3))func_020830ec(8,list,0);
o=M2C_FIELD(arg0,void **,92);M2C_FIELD(o,s32 *,8)=(M2C_FIELD(list,u8 *,0x1800)-1);
if(M2C_FIELD(o,u8 *,20)){
while(M2C_FIELD(o,s32 *,4)>M2C_FIELD(o,s32 *,8)){M2C_FIELD(o,s32 *,4)-=M2C_FIELD(o,s32 *,8)-M2C_FIELD(o,s32 *,12)+1;}
while(M2C_FIELD(o,s32 *,4)<M2C_FIELD(o,s32 *,12)){M2C_FIELD(o,s32 *,4)+=M2C_FIELD(o,s32 *,8)-M2C_FIELD(o,s32 *,12)+1;}
}else{n=M2C_FIELD(o,s32 *,4);if(n>M2C_FIELD(o,s32 *,8))n=M2C_FIELD(o,s32 *,8);else if(n<M2C_FIELD(o,s32 *,12))n=M2C_FIELD(o,s32 *,12);M2C_FIELD(o,s32 *,4)=n;}
o=M2C_FIELD(arg0,void **,96);M2C_FIELD(o,s32 *,16)=(s16)(M2C_FIELD(list,u8 *,0x1800)-1);
if(M2C_FIELD(o,u8 *,28)){
while(M2C_FIELD(o,s32 *,12)>M2C_FIELD(o,s32 *,16)){M2C_FIELD(o,s32 *,12)-=M2C_FIELD(o,s32 *,16)-M2C_FIELD(o,s32 *,20)+1;}
while(M2C_FIELD(o,s32 *,12)<M2C_FIELD(o,s32 *,20)){M2C_FIELD(o,s32 *,12)+=M2C_FIELD(o,s32 *,16)-M2C_FIELD(o,s32 *,20)+1;}
}else{n=M2C_FIELD(o,s32 *,12);if(n>M2C_FIELD(o,s32 *,16))n=M2C_FIELD(o,s32 *,16);else if(n<M2C_FIELD(o,s32 *,20))n=M2C_FIELD(o,s32 *,20);M2C_FIELD(o,s32 *,12)=n;}

    }
}
#pragma pop
