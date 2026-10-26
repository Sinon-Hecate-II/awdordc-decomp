/* 21 functions from 0x021E3210 to 0x021E41AC (ov002), found by ds-decomp. */
#include "common.h"

void func_ov002_021e36d0(void *a) {
s8 func_ov002_021e30d0(void *);void *p;s32 i;
M2C_FIELD(a,s8 *,102)=func_ov002_021e30d0(a+34);if(!M2C_FIELD(a,u8 *,101))return;
for(p=a+34,i=0;i<5;i++,p+=4)M2C_FIELD(p,u8 *,2)&=~7;
{void *q; s32 j;for(q=a+54,j=0;j<5;j++,q+=4)M2C_FIELD(q,u8 *,2)&=~7;}
{void *q; s32 j;for(q=a+74,j=0;j<5;j++,q+=4)M2C_FIELD(q,u8 *,2)&=~7;}
{void *q; s32 j;for(q=a+38,j=1;j<5;j++,q+=4)M2C_FIELD(q,s16 *,0)=-1;}
}

void func_ov002_021e3890(s32 arg0) {
    extern u8 gPlayerSettings;
    s32 var_lr;
    s32 var_r4;
    u8 *var_r5;
    s32 var_r6;
    u8 temp_r2;
    var_lr = 0;
    var_r5 = &gPlayerSettings;
    var_r4 = arg0;
    do {
        if (var_lr == 0) var_r6 = 1;
        else var_r6 = 0;
        M2C_FIELD(var_r4, u8 *, 0x64) = var_lr;
        M2C_FIELD(var_r4, s32 *, 0x60) = var_r6 * 0x68 + arg0;
        temp_r2 = M2C_FIELD(M2C_FIELD(var_r5, void **, 4), u8 *, 0x3C);
        var_lr += 1;
        var_r5 += 0x18;
        M2C_FIELD(var_r4, u8 *, 0x65) = temp_r2;
        var_r4 += 0x68;
    } while (var_lr < 2);
}

/* Rebuild both players' status panels: the two 0x68-byte panel objects at p
   and p+0x68 take their value and thresholds from the versus player settings,
   then have their icons, positions and gauges refreshed. */
void PlayerPanels_Init(void *p){
void func_ov002_021e2eb8(void *,s32,s32);void func_ov002_021e3044(void *,s32,s32);
void func_ov002_021e3100(void *);void func_ov002_021e3210(void *);void func_ov002_021e3578(void *);
extern u8 gPlayerSettings;
func_ov002_021e2eb8(p,M2C_FIELD(M2C_FIELD(&gPlayerSettings,void **,4)+M2C_FIELD(&gPlayerSettings,u8 *,0x13)*4,s32 *,0x2c),0);
func_ov002_021e2eb8(p+0x68,M2C_FIELD(M2C_FIELD(&gPlayerSettings,void **,0x1c)+M2C_FIELD(&gPlayerSettings,u8 *,0x2b)*4,s32 *,0x2c),0);
func_ov002_021e3044(p,(M2C_FIELD(&gPlayerSettings,u8 *,0xd)+9)/10,(M2C_FIELD(&gPlayerSettings,u8 *,0xe)+9)/10);
func_ov002_021e3044(p+0x68,(M2C_FIELD(&gPlayerSettings,u8 *,0x25)+9)/10,(M2C_FIELD(&gPlayerSettings,u8 *,0x26)+9)/10);
func_ov002_021e3100(p);func_ov002_021e3100(p+0x68);
func_ov002_021e3210(p);func_ov002_021e3210(p+0x68);
func_ov002_021e3578(p);func_ov002_021e3578(p+0x68);
func_ov002_021e36d0(p);func_ov002_021e36d0(p+0x68);
}

M2C_UNK func_ov002_021e39e8(s32 *p) {
u32 v;
if(*p&1){*(volatile u16 *)0x4000304|=0x8000;func_020033f4();func_02003124(4);func_02003104(8);v=0x80330000;*(volatile u32 *)0x4000064=v;}
else{*(volatile u16 *)0x4000304&=~0x8000;func_020033e0();func_020031cc(8);func_02003104(4);v=0x80320000;*(volatile u32 *)0x4000064=v;}return ++*p;
}

#pragma opt_strength_reduction off
M2C_UNK func_ov002_021e3a7c(s32 *p) {
    extern u8 gPlayerSettings;
    extern u8 data_ov002_021f30f4;
    void func_02082098(s32, s32);
    void func_02082104(s32, s32);
    void func_02082134(s32, s32);
    s32 i;
    if (*p & 1) {
        func_02082098(2, 0);
        func_02082098(3, 0);
        func_02082104(2, 15);
        func_02082104(3, 14);
        i = M2C_FIELD(&gPlayerSettings, u8 *, 1);
        if (M2C_FIELD(M2C_FIELD(&data_ov002_021f30f4, void **, i * 24), u8 *, 0x3D) != 2) {
            func_02082134(3, 1);
        } else {
            func_02082134(3, 0);
        }
    } else {
        func_02082098(2, 2);
        func_02082098(3, 2);
        func_02082104(2, 31);
        func_02082104(3, 30);
        if (M2C_FIELD(&gPlayerSettings, u8 *, 1) == 0) {
            i = 1;
        } else {
            i = 0;
        }
        if (M2C_FIELD(M2C_FIELD(&data_ov002_021f30f4, void **, i * 24), u8 *, 0x3D) != 2) {
            func_02082134(3, 1);
        } else {
            func_02082134(3, 0);
        }
    }
}
#pragma opt_strength_reduction on
void func_ov002_021e3b7c(M2C_UNK *p) {
extern u32 gCur3DSpriteEngine, data_027e00c4;
extern u8 data_027e008c[];
s32 x,y,tx,ty; u32 old; u16 v;
if(*p&1)return;
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
for(y=0,ty=0;y<192;y+=64,ty+=8){
v=(u16)((y&255)|0xc00);
for(x=0,tx=0;x<256;x+=64,tx+=8)
func_01ffaacc((u16)(x&511),v,(u16)(((tx+(ty<<5))&1023)|0xf000),data_027e008c,0);
}
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction on
void func_ov002_021e3c5c(void) {
    M2C_UNK func_ov002_021e39e8(M2C_UNK *);
    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e39e8(&data_ov002_021f3014);
}

void func_ov002_021e3c70(void) {
    M2C_UNK func_ov002_021e3a7c(M2C_UNK *);
    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e3a7c(&data_ov002_021f3014);
}

void func_ov002_021e3c84(void) {

    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e3b7c(&data_ov002_021f3014);
}

void func_ov002_021e3dd4(void) {
    M2C_UNK func_0209cd00(void (*)(void));
    func_0209cd00(func_ov002_021e3c5c);
    func_0209cd00(func_ov002_021e3c70);
    func_0209cd00(func_ov002_021e3c84);
}

s32 func_ov002_021e3e00(s32 *arg0) {
    return *arg0 & 1;
}

void func_ov002_021e3e0c(void *arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB) {
    M2C_FIELD(arg0, s16 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = arg3;
    M2C_FIELD(arg0, u16 *, 0xC) = arg4;
    M2C_FIELD(arg0, u16 *, 0xE) = arg5;
    M2C_FIELD(arg0, u16 *, 0xA) = arg6;
    M2C_FIELD(arg0, u16 *, 8) = arg7;
    M2C_FIELD(arg0, u8 *, 0x11) = arg8;
    M2C_FIELD(arg0, u8 *, 0x10) = arg9;
    M2C_FIELD(arg0, u8 *, 0x12) = argA;
    M2C_FIELD(arg0, u8 *, 0x13) = argB;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}

void func_ov002_021e3e64(void *arg0) {
    u16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u16 *, 6);
    if ((u32) temp_r2 < (u32) M2C_FIELD(arg0, u16 *, 8)) {
        M2C_FIELD(arg0, u16 *, 6) = (u16) (temp_r2 + 1);
    }
}

void func_ov002_021e3e7c(void *p) {
s32 func_0207ca38(s32,s32,s32,s32,s32);s32 a,b;
if(M2C_FIELD(p,u16 *,6)>=M2C_FIELD(p,u16 *,8))return;
a=func_0207ca38(0,M2C_FIELD(p,u8 *,16),0,M2C_FIELD(p,u16 *,6),M2C_FIELD(p,u16 *,8));
b=func_0207ca38(4,M2C_FIELD(p,u16 *,12),M2C_FIELD(p,u16 *,14),M2C_FIELD(p,u16 *,6),M2C_FIELD(p,u16 *,8));
func_02087048(M2C_FIELD(p,u8 *,17),(u8)a);func_0208718c();
func_020872c8(M2C_FIELD(p,u8 *,18)?M2C_FIELD(p,s16 *,0):-M2C_FIELD(p,s16 *,0),M2C_FIELD(p,s16 *,2),M2C_FIELD(p,s16 *,4),b,32,M2C_FIELD(p,u16 *,10));
func_02087048(0,31);
}

void func_ov002_021e3f28(void) {

}
