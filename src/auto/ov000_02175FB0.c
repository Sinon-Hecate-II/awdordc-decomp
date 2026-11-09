/* 7 functions from 0x02175FB0 to 0x02176E28 (ov000), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
void func_ov000_02175fb0(void *a) {
extern void *gCur3DSpriteEngine,*data_027e00c4;
void func_01ffaacc(u16,u16,u16,void *,s32);
s32 func_0207c8ec(s32,s32);
extern u8 data_ov000_021deb7c[],data_ov000_021deb20[],data_027e0084[],data_ov000_021deb10[],data_ov000_021deb18[],data_027e0064[],data_02101f0c[];extern s32 data_ov000_021df600;extern s16 data_020e5b30[];
s32 func_020a72b0(s32,s32);u8 func_ov000_02176dcc(void *);
void func_01ff8ddc(s32,s16,s16,s16,s16);
s32 level,n,d,i,ratio,den,sn,cs,aa,bb,cc,dd,x; void *old=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c4;
func_01ffaacc(4,1,0xc144,data_ov000_021deb7c,0);func_01ffaacc(135,20,0xe16b,data_ov000_021deb20,0);func_01ffaacc(196,20,0xe179,data_ov000_021deb20,0);
level=0;if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,76))level=func_0207c8ec(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,76)-1,10)+1;
if(level>9){level=10;func_01ffaacc(158,40,0x8081,data_027e0084,0);func_01ffaacc(166,40,0x8080,data_027e0084,0);}else func_01ffaacc(166,40,(u16)(((level+128)&1023)|0x8000),data_027e0084,0);
func_01ffaacc(179,40,0x9081,data_027e0084,0);func_01ffaacc(187,40,0x9080,data_027e0084,0);
{s32 index0,position0;
for(index0=10-level;index0<10;index0++)func_01ffaacc((u16)((9-index0)*4+158),37,0x60b1,data_027e0084,0);}

if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28)){
n=func_0207c8ec(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24),10);d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24)-n*10;if(n>0){func_01ffaacc(158,53,(u16)(((n+128)&1023)|32768),data_027e0084,0);
}
func_01ffaacc(166,53,(u16)(((d+128)&1023)|32768),data_027e0084,0);

n=func_0207c8ec(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28),10);d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28)-n*10;if(n>0){func_01ffaacc(179,53,(u16)(((n+128)&1023)|36864),data_027e0084,0);
}
func_01ffaacc(187,53,(u16)(((d+128)&1023)|36864),data_027e0084,0);

if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24)>0){
if(!(data_ov000_021df600&1)){M2C_FIELD(data_ov000_021deb10,volatile u16 *,12)=0x4400;data_ov000_021df600|=1;}
ratio=func_0207c8ec(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24)*312,M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28));x=126+(ratio>>4);cs=data_020e5b30[1];
if((ratio<0?-ratio:ratio)>=2)den=ratio;else if(ratio>2)den=2;else{den=-2;if(ratio>=den)den=ratio;}
sn=data_020e5b30[0];
n=ratio;
if((ratio<0?-ratio:ratio)<2){if(ratio>2)n=2;else if(ratio< -2)n=-2;}
aa=func_0207c8ec(cs<<4,n);bb=func_0207c8ec((-sn)<<4,256);cc=func_0207c8ec(sn<<4,den);dd=func_0207c8ec(cs<<4,256);
func_01ff8ddc(2,(s16)aa,(s16)bb,(s16)cc,(s16)dd);
func_01ffaacc((u16)x,46,0x60a8,data_ov000_021deb18,0);

}
}else {func_01ffaacc(162,53,0x808a,data_027e0084,0);
func_01ffaacc(183,53,0x908a,data_027e0084,0);
}
if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,20)){func_01ffaacc(166,66,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,16)+128)&1023)|32768),data_027e0084,0);
func_01ffaacc(179,66,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,20)+128)&1023)|36864),data_027e0084,0);
}
else {func_01ffaacc(166,66,0x808a,data_027e0084,0);
func_01ffaacc(179,66,0x908a,data_027e0084,0);
}
func_01ffaacc(166,79,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,40)+128)&1023)|32768),data_027e0084,0);

d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,44);if(d){if(d>0)n=11;else{n=10;d*=n-11;}
func_01ffaacc(174,79,(u16)(((n+128)&1023)|40960),data_027e0084,0);
func_01ffaacc(181,79,(u16)(((d+128)&1023)|40960),data_027e0084,0);
}
func_01ffaacc(166,92,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,64)+128)&1023)|32768),data_027e0084,0);
d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,68);if(d){if(d>0)n=11;else{n=10;d*=n-11;}
func_01ffaacc(174,92,(u16)(((n+128)&1023)|40960),data_027e0084,0);
func_01ffaacc(181,92,(u16)(((d+128)&1023)|40960),data_027e0084,0);
}
if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,48)==M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,52)){func_01ffaacc(166,105,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,48)+128)&1023)|32768),data_027e0084,0);
}else{
func_01ffaacc(158,105,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,48)+128)&1023)|32768),data_027e0084,0);
func_01ffaacc(166,105,0x808a,data_027e0084,0);
func_01ffaacc(174,105,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,52)+128)&1023)|32768),data_027e0084,0);

}
d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,56);if(d){if(d>0)n=11;else{n=10;d*=n-11;}func_01ffaacc(182,105,(u16)(((n+128)&1023)|40960),data_027e0084,0);
func_01ffaacc(189,105,(u16)(((d+128)&1023)|40960),data_027e0084,0);
}
{s32 index1,position1;
for(index1=0,position1=39;index1<6;index1++,position1+=13){func_01ffaacc(240,(u16)position1,(u16)(((176-M2C_FIELD(M2C_FIELD(a,void **,16)+index1*4,s32 *,100))&1023)|0x6000),data_027e0084,0);
}
}
{s32 index2,position2;
for(index2=0,position2=145;index2<M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,252);index2++,position2+=15){n=M2C_FIELD(M2C_FIELD(a,void **,16)+index2*4,s32 *,124);if(n){n=func_020a72b0(0,n);func_01ffaacc((u16)position2,121,(u16)(((n+391)&1023)|0xf000),data_027e0064,index2);
}}
}
{s32 index3,position3;
for(index3=0,position3=145;index3<M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,256);index3++,position3+=15){if(index3>=7)break;n=M2C_FIELD(M2C_FIELD(a,void **,16)+index3*4,s32 *,156);if(n){n=func_020a72b0(0,n);func_01ffaacc((u16)position3,140,(u16)(((n+391)&1023)|0xf000),data_027e0064,index3);
}}}

if(func_ov000_02176dcc(a)){
func_01ffaacc(128,176,0x6120,data_02101f0c,1);
func_01ffaacc(192,176,0x6128,data_02101f0c,1);
func_01ffaacc(128,184,0x6130,data_02101f0c,1);
func_01ffaacc(192,184,0x6138,data_02101f0c,1);
func_01ffaacc(114,178,0xb140,data_027e0064,1);

func_ov000_02174da4(0,182);
}
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction reset
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
{s32 offset=arg1*12; s32 a,b; a=*(volatile s32 *)(data_ov000_021ae2c8+offset);b=*(volatile s32 *)(data_ov000_021ae2cc+offset);M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x58)=a;M2C_FIELD(M2C_FIELD(arg0,void **,16),s32 *,0x5c)=b;}}
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

