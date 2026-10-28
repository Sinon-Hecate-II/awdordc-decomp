/* 10 functions from 0x0221D818 to 0x0221E5A0 (ov005), found by ds-decomp. */
#include "common.h"

M2C_UNK func_ov005_0221d818(M2C_UNK arg0) { }

void func_ov005_0221e1b8(void) {
    M2C_UNK func_ov005_0221caa0();
    func_ov005_0221caa0();
}

void func_ov005_0221e1c4(void) {
    M2C_UNK func_ov005_0221cff8();
    func_ov005_0221cff8();
}

void func_ov005_0221e1d0(void) {
    M2C_UNK func_ov005_0221d160();
    func_ov005_0221d160();
}

void func_ov005_0221e1dc(void) {
    M2C_UNK func_01ffaa8c();
    func_01ffaa8c();
}

void func_ov005_0221e1e8(void) {
    M2C_UNK func_ov005_0221d818();
    func_ov005_0221d818();
}

void func_ov005_0221e1f4(M2C_UNK arg0) {
    M2C_UNK func_02086344();
    M2C_UNK func_02095ff8(M2C_UNK);
    M2C_UNK func_ov005_02218fd0(M2C_UNK);
    func_02095ff8(3);
    func_02086344();
    func_ov005_02218fd0(arg0);
}

void func_ov005_0221e214(void) {
    M2C_UNK func_02095fd4();
    M2C_UNK func_02086370();
    func_020ab200();
    func_0209bf7c();
    func_02095fd4();
    func_02086370();
}

#pragma opt_strength_reduction off
void func_ov005_0221e22c(M2C_UNK arg0){
 s32 func_020cd1e4(void); void *func_01ffa42c(M2C_UNK *,M2C_UNK);
 M2C_UNK func_0200bc5c(M2C_UNK *);
 void *func_02090eb8(M2C_UNK *,s32,s32,s32,u16,s32,void *);
 void func_ov005_0221a38c(void *); s32 RandomIntRange(s32,s32);
 void func_ov005_02219fa0(s32,s32,s32);
 extern M2C_UNK data_ov005_02220db8,data_ov005_02220f90,data_ov005_02220a4c,data_ov005_02220a78;
 extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8;
 extern u16 data_02168f14; extern u8 data_0215c334[];
 void *result,*saved; s32 i,x,y,flag;
 if(!func_020cd1e4())return;
 result=func_01ffa42c(&data_ov005_02220db8,arg0);
 if(result){
 M2C_FIELD(result,void **,0)=&data_ov005_02220f90;
 M2C_FIELD(result,u8 *,0x44)=0;M2C_FIELD(result,u8 *,0x45)=0;M2C_FIELD(result,u8 *,0x46)=0;M2C_FIELD(result,u8 *,0x47)=0;
 M2C_FIELD(result,u16 *,0x48)=0;M2C_FIELD(result,u16 *,0x4a)=0;M2C_FIELD(result,u16 *,0x4c)=0;M2C_FIELD(result,u16 *,0x4e)=0;
 M2C_FIELD(result,u16 *,0x50)=0;M2C_FIELD(result,u16 *,0x52)=0;M2C_FIELD(result,u16 *,0x54)=0;M2C_FIELD(result,u16 *,0x56)=0;
 M2C_FIELD(result,s32 *,0x40)=0;M2C_FIELD(result,s32 *,0x3c)=432;
 func_0200bc5c(&data_ov005_02220a4c);
 saved=gCur3DSpriteEngine;
 for(i=0;i<2;i++){
 gCur3DSpriteEngine=i==0?data_027e00c8:data_027e00c4;
 M2C_FIELD(result+i*4,void **,0x34)=func_02090eb8(&data_ov005_02220a78,0,0,0,(u16)(0xa000|((472 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&1023)),0,result);
 }
 gCur3DSpriteEngine=saved;func_ov005_0221a38c(result);
 }
 if(((u32)(data_02168f14<<29)>>29)!=1)flag=1;else flag=0;
 if((flag&255) && data_0215c334[3]!=4)return;
 for(i=0;i<8;i++){x=RandomIntRange(-48,-16);y=RandomIntRange(288,352);func_ov005_02219fa0(x,y,RandomIntRange(0,3));}
 for(i=0;i<16;i++){x=RandomIntRange(-32,128);y=RandomIntRange(400,432);func_ov005_02219fa0(x,y,RandomIntRange(0,3));}
}
/* Initializes ov005's scene state when the system is ready and the global mode is not state 1. */
void func_ov005_0221e468(M2C_UNK arg0) {
    M2C_UNK func_01ff85b8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_01ff9ce8(M2C_UNK);
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02082134(M2C_UNK, M2C_UNK);
    s32 func_020cd1e4();
    s32 func_020e3218(M2C_UNK *);
    extern u16 data_02168f14;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02220a2c;
    extern M2C_UNK data_ov005_02220a90;
    extern M2C_UNK data_ov005_02220bf0;
    extern M2C_UNK data_ov005_02220e30;
    extern M2C_UNK data_ov005_02220ebc;
    extern M2C_UNK data_ov005_02220f7c;
    s32 flag;
    void *result;
    void *savedPtr;

    if (func_020cd1e4() == 0) {
        return;
    }
    if (((u32) (data_02168f14 << 0x1D) >> 0x1D) != 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (!(flag & 0xFF)) {
        return;
    }
    result = func_01ffa42c(&data_ov005_02220bf0, arg0);
    if (result == NULL) {
        return;
    }
    M2C_FIELD(result, M2C_UNK **, 0) = &data_ov005_02220f7c;
    func_0200bc5c(&data_ov005_02220a2c);
    savedPtr = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_02082134(2, 1);
    func_01ff9ce8(2);
    func_020e3218(&data_ov005_02220ebc);
    func_020814e4();
    func_02081590(func_020e3218(&data_ov005_02220a90), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
    func_02081590(func_020e3218(&data_ov005_02220e30), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
    func_02081528();
    func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 0x800, 0x2000);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    gCur3DSpriteEngine = savedPtr;
    M2C_FIELD(result, s32 *, 0x34) = 0;
    M2C_FIELD(result, s32 *, 0x3C) = 0;
    M2C_FIELD(result, s32 *, 0x40) = 0;
    M2C_FIELD(result, s32 *, 0x44) = 0;
    M2C_FIELD(result, s32 *, 0x38) = -0x100;
}

