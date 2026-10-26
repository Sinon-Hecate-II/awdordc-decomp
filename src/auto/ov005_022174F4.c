/* 9 functions from 0x022174F4 to 0x02218008 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_0221760c(void) {
extern void *data_ov005_02221310,*gCur3DSpriteEngine,*data_027e00c8;
s32 value=M2C_FIELD(data_ov005_02221310,s16 *,0x10);
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
if(func_020bf894(M2C_FIELD(data_ov005_02221310,s16 *,0x10)))
func_02098d78(value,0x8380,6);
else func_02007e98(0,M2C_FIELD(data_027e00c8,s32 *,0x1c)+0x8380,0x20);
gCur3DSpriteEngine=saved;
M2C_FIELD(data_ov005_02221310,s16 *,0x18)=-1;
}

void func_ov005_02217dc0(u8 *arg0) {
extern void *data_02101e84,*data_ov005_02221310;
u32 old=*arg0; u16 keys=M2C_FIELD(data_02101e84,u16 *,2);s32 value=old;
if(keys&0x40)value=old-4;
else if(keys&0x80)value=old+4;
else if(keys&0x20)value=old-1;
else if(keys&0x10)value=old+1;
if(value<0)value+=12;
if(value>11)value-=12;
if(value!=old)func_020b1c60(value);
M2C_FIELD(data_ov005_02221310,s16 *,0xe)=value;
M2C_FIELD(data_ov005_02221310,s16 *,0x10)=M2C_FIELD(data_ov005_02221310,s16 *,0xe)+1;
}

void func_ov005_02217e4c(u8 *arg0) {
    M2C_UNK func_0208fe30(s32);
    extern void *data_ov005_02221310;
    M2C_FIELD(data_ov005_02221310, s16 *, 0xE) = (s16) *arg0;
    M2C_FIELD(data_ov005_02221310, s16 *, 0x10) = (s16) (M2C_FIELD(data_ov005_02221310, s16 *, 0xE) + 1);
    func_0208fe30(0x10019);
}

void func_ov005_02217e84(u8 *arg0) {
extern void *data_02101e84;
u16 keys;s32 old; s32 value;
old=*arg0;keys=M2C_FIELD(data_02101e84,u16 *,2);value=old;
if(keys&0x20) {if(old<=0) {if(M2C_FIELD(data_02101e84,u16 *,0)&0x20)value=old-1;}else value=old-1;}
else if(keys&0x10) {if(old>=3) {if(M2C_FIELD(data_02101e84,u16 *,0)&0x10)value=old+1;}else value=old+1;}
if(value<0)value=3;
if(value>3)value=0;
if(value!=old)func_020b1c60(value);
func_ov005_02217334(value);
}

void func_ov005_02217f18(u8 *arg0) {
extern void *data_ov005_02221310;
M2C_FIELD(data_ov005_02221310,s16 *,0x12)=*arg0;
func_ov005_02217334(*arg0);
func_020bf8fc(M2C_FIELD(data_ov005_02221310,s16 *,0x10),M2C_FIELD(data_ov005_02221310,s16 *,0x12));
func_ov005_022173b4(M2C_FIELD(data_ov005_02221310,s16 *,0x10));
func_0208fe30(0x10019);
}

void func_ov005_02217f6c(void) {
M2C_UNK func_020b22a4(s32,s32,M2C_UNK *,s32);
extern M2C_UNK data_ov005_02220800;
s32 i=0;
do {
func_020b22a4((i%4)*50+30,(i/4)*18+87,&data_ov005_02220800,i);
i++;
}while(i<12);
}

void func_ov005_02217fc8(void) {
    M2C_UNK func_020b22a4(s32, M2C_UNK, M2C_UNK *, s32);
    extern M2C_UNK data_ov005_02220828;
    s32 var_r6;
    s32 var_r7;

    var_r6 = 0;
    var_r7 = 0xE;
    do {
        func_020b22a4(var_r7, 0x5A, &data_ov005_02220828, var_r6);
        var_r6 += 1;
        var_r7 += 0x3C;
    } while (var_r6 < 4);
}

