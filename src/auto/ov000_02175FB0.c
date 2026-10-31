/* 7 functions from 0x02175FB0 to 0x02176E28 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_02175fb0(void *arg0) { }

void func_ov000_021769dc(void *arg0) {
    M2C_UNK func_ov000_02175878(void *);
    M2C_UNK func_ov000_02175ed8(void *);
    void *temp_r2;
    temp_r2 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_r2, s32 *, 4) = M2C_FIELD(temp_r2, s32 *, 8);
    func_ov000_02175ed8(arg0);
    func_ov000_02175878(arg0);
    M2C_FIELD(arg0, s32 *, 0) = 1 - M2C_FIELD(arg0, s32 *, 0);
}

void func_ov000_02176a0c(M2C_UNK arg0) {
    M2C_UNK func_ov000_02175740(M2C_UNK);
    M2C_UNK func_ov000_021759b8(M2C_UNK);
    M2C_UNK func_ov000_02175a20(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x38) = 2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x40) = 1;
    func_ov000_02175740(arg0);
    func_ov000_021759b8(arg0);
    func_ov000_02175a20(arg0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02176a9c(M2C_UNK arg0) {
    M2C_UNK func_ov000_02175740();
    M2C_UNK func_ov000_02175a20(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_ov000_02175740();
    func_ov000_02175a20(arg0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = temp_r4;
}

#pragma opt_strength_reduction off
void func_ov000_02176af8(s32 arg0, s32 arg1) {
extern s32 data_ov000_021ae40c[];extern u8 data_ov000_021ae2c8[];extern u8 data_ov000_021ae2cc[];
s32 func_020a799c(s32,s32,s32);
s32 i,j,value,kind,tmp; s32 *table=(s32 *)((u8 *)data_ov000_021ae40c+arg1*48);void *p;
for(i=0;i<6;i++){p=M2C_FIELD(arg0,void **,16);M2C_FIELD((u8 *)p+i*4,s32 *,0x64)=table[i+(M2C_FIELD(p,s32 *,16)>0?0:6)];}
for(i=0;i<8;i++){M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+i*4,s32 *,0x7c)=0;M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+i*4,s32 *,0x9c)=0;}
M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0xfc)=0;
M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x100)=0;
for(i=1;i<27;i++){
value=func_020a799c(i,arg1,0);
if(value>=90)kind=3;else if(value>=70)kind=2;else if(value>0)kind=1;else kind=0;
switch(kind){
case 3:
if(M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0xfc)<8){
M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0xfc)*4,s32 *,0x7c)=i;
M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0xfc)*4,s32 *,0xbc)=value;
M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0xfc)++;
}break;
case 2:
if(M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x100)<8){
M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x100)*4,s32 *,0x9c)=i;
M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x100)*4,s32 *,0xdc)=value;
M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x100)++;
}break;
}
}
for(i=0;i<M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0xfc)-1;i++)for(j=i+1;j<M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0xfc);j++){void *left=(u8 *)M2C_FIELD(arg0,void **,16)+i*4;void *right=(u8 *)M2C_FIELD(arg0,void **,16)+j*4;if(M2C_FIELD(left,s32 *,0xbc)<M2C_FIELD(right,s32 *,0xbc)){tmp=M2C_FIELD(left,s32 *,0x7c);M2C_FIELD(left,s32 *,0x7c)=M2C_FIELD(right,s32 *,0x7c);M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+j*4,s32 *,0x7c)=tmp;tmp=M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+i*4,s32 *,0xbc);M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+i*4,s32 *,0xbc)=M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+j*4,s32 *,0xbc);M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+j*4,s32 *,0xbc)=tmp;}}
for(i=0;i<M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x100)-1;i++)for(j=i+1;j<M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x100);j++){void *left=(u8 *)M2C_FIELD(arg0,void **,16)+i*4;void *right=(u8 *)M2C_FIELD(arg0,void **,16)+j*4;if(M2C_FIELD(left,s32 *,0xdc)<M2C_FIELD(right,s32 *,0xdc)){tmp=M2C_FIELD(left,s32 *,0x9c);M2C_FIELD(left,s32 *,0x9c)=M2C_FIELD(right,s32 *,0x9c);M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+j*4,s32 *,0x9c)=tmp;tmp=M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+i*4,s32 *,0xdc);M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+i*4,s32 *,0xdc)=M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+j*4,s32 *,0xdc);M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,16)+j*4,s32 *,0xdc)=tmp;}}
{u32 a=M2C_FIELD((u8 *)data_ov000_021ae2c8+arg1*12,s32 *,0);u32 b=M2C_FIELD((u8 *)data_ov000_021ae2cc+arg1*12,s32 *,0);M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x58)=a;M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x5c)=b;}}
u8 func_ov000_02176dcc(void *arg0) {
    s32 func_020d46e8();
    s32 func_020d4ea8();
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0xC) == 0) {
        return 0U;
    }
    if (func_020d46e8() != 0) {
        return 0U;
    }
    if (func_020d4ea8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_02176e08(s32 arg0) {
    switch (arg0) {
    case 0xE:
    case 0x10:
    case 0x11:
        return 1;
    default:
        return 0;
    }
}

