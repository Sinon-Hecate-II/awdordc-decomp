/* 16 functions from 0x0208E18C to 0x0208EE90 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 a; s32 b; } Pair;
typedef struct { u8 pad[0x60]; u64 v; u64 *p; } UnkNode0208EE1C;


void func_0208e18c(void) { }

void func_0208e7ec(u32 arg0,s32 arg1) { extern u8 data_02102888[],data_02102898[],data_021028a4[],data_021028b0[]; extern s32 gCur3DSpriteEngine; void *p; func_0200bc5c(data_02102888); func_020814e4(data_02102898); func_02081590(data_021028a4,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+arg0); func_020815fc(data_021028b0,(arg1+16)<<5,32); func_02081528(); p=(void *)gCur3DSpriteEngine; M2C_FIELD(p,u8 *,0x46)|=16; }

void func_0208e864(s16 arg0, s32 arg1, u16 arg2, u8 arg3, s32 arg4) {
s32 func_0207c8ec(s32,s32);
void func_01ffaacc(u16,u16,u16,void *,u8);
extern s32 gCur3DSpriteEngine;
extern u8 data_027e00a4[],data_027e0084[];
s32 minutes,centis;
u16 y;
const s32 mask=0x3ff;
minutes=func_0207c8ec(arg4,60);
centis=func_0207c8ec((arg4%60)*100,60);
if(arg4<600)arg2+=(32>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask;
y=(u16)arg1;
func_01ffaacc((u16)arg0,y,(u16)(arg2+((22>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),data_027e00a4,arg3);
arg0+=48;
func_01ffaacc((u16)arg0,y,(u16)(arg2+(((centis%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),data_027e0084,arg3);
arg0-=8;
centis=func_0207c8ec(centis,10);
func_01ffaacc((u16)arg0,y,(u16)(arg2+(((centis%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),data_027e0084,arg3);
arg0-=8;
func_01ffaacc((u16)arg0,y,(u16)(arg2+((20>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),data_027e0084,arg3);
arg0-=8;
do{
func_01ffaacc((u16)arg0,y,(u16)(arg2+(((minutes%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),data_027e0084,arg3);
minutes=func_0207c8ec(minutes,10);
arg0-=8;
}while(minutes!=0);
}

void func_0208eb30(void *arg0, u32 arg1, s32 arg2) {

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
const s32 mask1023 = 0x3ff;
s32 saved,bank,i,clamped;
u32 mode,shift,palSrc;
u16 pal,base,tile,bankVal;
void **bankPtr;
s16 sx,sy;
u8 byte;
if(M2C_FIELD(p,s32 *,0x58)>0)M2C_FIELD(p,s32 *,0x58)--;
if(M2C_FIELD(p,s32 *,0x58)<0)M2C_FIELD(p,s32 *,0x58)=0;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)bank=data_027e00c8;else bank=data_027e00c4;
gCur3DSpriteEngine=bank;
mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if((mode!=0||bank==data_027e00c8)&&(mode!=1||bank==data_027e00c4)&&(mode!=3||bank==saved)){
bankPtr=(void **)bank;
palSrc=M2C_FIELD(p,u32 *,0x40);
bankVal=M2C_FIELD(bankPtr,u16 *,0);
pal=(u16)((u32)(palSrc<<6)>>24);
base=M2C_FIELD(p,u16 *,0x3c);
tile=M2C_FIELD(p,u16 *,0x3e);
clamped=M2C_FIELD(p,s32 *,0x58);
shift=(((u32)bankVal)<<17)>>30;
sx=M2C_FIELD(p,s16 *,0x34);
sy=M2C_FIELD(p,s16 *,0x38);
byte=M2C_FIELD(p,u8 *,0x49);
func_0208e864((s16)(((s32)sx+(s32)sy)&(mask1023-0x200)),
(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255,
(u16)(base|((u16)(pal<<12))|((((u32)tile>>shift))&mask1023)),
byte,clamped);
}}
gCur3DSpriteEngine=saved;
}

void *func_0208ecc0(void *arg0) { M2C_UNK func_02089108(); extern M2C_UNK data_021025d4; extern s32 data_027e00c8,gCur3DSpriteEngine; u8 var_r0,var_r0_2; func_02089108(); M2C_FIELD(arg0,M2C_UNK **,0)=&data_021025d4; if(gCur3DSpriteEngine==data_027e00c8)var_r0=1;else var_r0=0; if(var_r0!=1)var_r0_2=1;else var_r0_2=0; M2C_FIELD(arg0,u8 *,0x48)=(u8)((M2C_FIELD(arg0,u8 *,0x48)&~0xE)|((u32)(var_r0_2<<29)>>28)); M2C_FIELD(arg0,s16 *,0x34)=0; M2C_FIELD(arg0,s16 *,0x36)=0; M2C_FIELD(arg0,s32 *,0x58)=0; M2C_FIELD(arg0,s16 *,0x3c)=0; return arg0; }

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
    void *func_0208ecc0();
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

#pragma opt_propagation off
void func_0208ee1c(UnkNode0208EE1C *s) {
    if (s->p) {
        *s->p = s->v;
    }
}

void *func_0208ee34(void *arg0) { void *p=M2C_FIELD(arg0,void **,0x68); if(p) *(u64 *)p=M2C_FIELD(arg0,u64 *,0x60); func_02082040(arg0); return arg0; }

#pragma opt_propagation reset
void func_0208ee60(void *arg0, u32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    func_0208e7ec(arg1, arg2);
}

