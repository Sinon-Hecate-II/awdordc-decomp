/* 16 functions from 0x0208E18C to 0x0208EE90 (main), found by ds-decomp. */
#include "common.h"


void func_0208e18c(void) { }

void func_0208e864(s16 arg0, s32 arg1, u16 arg2, u8 arg3, s32 arg4) {
    return;
}

void func_0208eb30(void *arg0, u32 arg1, s32 arg2) {
    M2C_UNK func_0208e7ec(u32, s32);
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    func_0208e7ec(arg1, arg2);
}

void func_0208eb60(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
}

u8 func_0208eb68(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s32 *, 0x58) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0208eb80(void *p) {
extern s32 gCur3DSpriteEngine,data_027e00c4,data_027e00c8;
void func_0208e864(s16,s32,u16,u8,s32);
s32 saved,bank,i;u32 mode;u16 pal,base,tile;
if(M2C_FIELD(p,s32 *,0x58)>0)M2C_FIELD(p,s32 *,0x58)--;
if(M2C_FIELD(p,s32 *,0x58)<0)M2C_FIELD(p,s32 *,0x58)=0;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)bank=data_027e00c8;else bank=data_027e00c4;
gCur3DSpriteEngine=bank;
mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if((mode!=0||bank==data_027e00c8)&&(mode!=1||bank==data_027e00c4)&&(mode!=3||bank==saved)){
base=M2C_FIELD(p,u16 *,0x3c);tile=M2C_FIELD(p,u16 *,0x3e);
pal=(u16)((u32)(M2C_FIELD(p,u32 *,0x40)<<6)>>24);
func_0208e864((s16)((M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38))&511),
(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255,
(u16)(base|((u16)(pal<<12))|(((u32)tile>>((u32)(M2C_FIELD(*(void **)bank,u16 *,0)<<17)>>30))&1023)),
M2C_FIELD(p,u8 *,0x49),M2C_FIELD(p,s32 *,0x58));
}}
gCur3DSpriteEngine=saved;
}

void func_0208ed40(void) {

}

s32 func_0208ed44(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_0208ed58(void *p){func_0208eb80(p);}

void func_0208ed64(M2C_UNK arg0) {
    s32 func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208ecc0();
    extern M2C_UNK data_021026b8;
    if (func_01ffa3dc(&data_021026b8, arg0) == 0) {
        return;
    }
    func_0208ecc0();
}

void *func_0208ed88(void *arg0) {
    M2C_UNK func_02089108();
    extern M2C_UNK data_02102624;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    u8 var_r0;
    u8 var_r0_2;

    func_02089108();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02102624;
    if (gCur3DSpriteEngine == data_027e00c8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 1) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) ((M2C_FIELD(arg0, u8 *, 0x48) & ~0xE) | ((u32) (var_r0_2 << 0x1D) >> 0x1C));
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 9;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    return arg0;
}

void func_0208ee60(void *arg0, u32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    func_0208e7ec(arg1, arg2);
}

