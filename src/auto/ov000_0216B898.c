/* 10 functions from 0x0216B898 to 0x0216C7F0 (ov000), found by ds-decomp. */
#include "common.h"
extern void *gCur3DSpriteEngine;
extern u8 data_ov000_021b8384[],data_ov000_021b83a0[],data_ov000_021b837c[],data_ov000_021b83d8[],data_ov000_021b8392[];
extern s16 data_020e5b30[];
#define ENGINE M2C_FIELD(gCur3DSpriteEngine,void**,0)
#define SIZE ((u32)(M2C_FIELD(ENGINE,u16*,0)<<17)>>30)
#define ATTR(tile,pal) ((u16)(((tile)>>SIZE & 0x3ff)|(pal)))
#define GET(off) func_020a8ff4(M2C_FIELD(M2C_FIELD(arg0,void**,off),void**,0))

#pragma peephole off
void func_ov000_0216b898(void *arg0){
s32 func_020a8ff4(void*);s32 func_020e31e0(void);
s32 func_ov000_0216b15c(s32,s32,s32,s32);s32 func_020a93e4(void*,u8);
s32 func_0207c8ec(s32,s32);void func_01ff8ddc(s32,s16,s16,s16,s16);
void func_01ffaacc(u16,u16,u16,void*,s32);void func_0209b67c(u16,s32,s32,u16,s32);
s32 x1,x2,y1,y2,anchor,xa,ya,i,tile;u16 *volatile control;
if(!M2C_FIELD(arg0,u8*,0x36))return;
switch(func_020e31e0()){
case 0:{ void *tmp=M2C_FIELD(M2C_FIELD(arg0,void**,0x48),void**,0); xa=(s16)(func_020a8ff4(tmp)-4); }ya=12;x1=GET(0x48);y1=34;x2=GET(0x4c);y2=60;break;
case 2:case 3:
{ void *tmp=M2C_FIELD(M2C_FIELD(arg0,void**,0x48),void**,0); xa=(s16)(func_020a8ff4(tmp)-4); }ya=12;
if(M2C_FIELD(arg0,u8*,0x3d)){x2=GET(0x4c);y2=34;x1=GET(0x48);y1=68;}
else{x1=GET(0x48);y1=34;x2=GET(0x4c);y2=60;}break;
case 1:case 4:case 5:default:{ void *tmp=M2C_FIELD(M2C_FIELD(arg0,void**,0x48),void**,0); xa=(s16)(func_020a8ff4(tmp)-4); }ya=38;x1=GET(0x48);y1=12;
if(M2C_FIELD(arg0,u8*,0x3d)){x2=GET(0x4c);y2=60;}else{x2=GET(0x4c);y2=42;}break;
}
anchor=GET(0x44);i=GET(0x44);
control=(u16*)(ENGINE+0x12);*control=(*control&~0xc0)|0x40;
M2C_FIELD(ENGINE,u8*,0x51)=i;M2C_FIELD(ENGINE,u8*,0x52)=16-anchor;
anchor=GET(0x5c);
if(func_ov000_0216b15c(anchor,134,128,32))func_01ffaacc((u16)(anchor&511),134,ATTR(0x43e,0xb000),data_ov000_021b8384,11);
tile=M2C_FIELD(arg0,u8*,0x3d)?0x368:0x35c;
if(func_ov000_0216b15c(x1,y1,48,16)){u16 x=x1&511;u16 attr=ATTR(tile,0xb000);func_01ffaacc(x,(u16)(y1&255),attr,data_ov000_021b83a0,11);}
{
void *p=M2C_FIELD(arg0,void**,0x40);
if(M2C_FIELD(p,u8*,10)==3)M2C_FIELD(p,u8*,0x17)=28;
else if(M2C_FIELD(p,u8*,10)==2)M2C_FIELD(p,u8*,0x17)=30;
else M2C_FIELD(p,u8*,0x17)=26;
}
M2C_FIELD(M2C_FIELD(arg0,void**,0x40),s16*,6)=x2;
for(i=0;i<M2C_FIELD(M2C_FIELD(arg0,void**,0x40),u8*,10);i++){
s32 x=func_020a93e4(M2C_FIELD(arg0,void**,0x40),(u8)i);
if(func_ov000_0216b15c(x,y2,32,32)){
void *p=M2C_FIELD(arg0,void**,0x40);
s32 offset=(u16)(M2C_FIELD(p,u16*,0x12)+M2C_FIELD(p,u8*,0x16)*M2C_FIELD(p+(i&255),u8*,11));
func_01ffaacc((u16)(x&511),(u16)(y2&255),ATTR(offset+0x374,0xb000),data_ov000_021b837c,11);
}
}
if(GET(0x58)>1){
s32 a,b,c,d,scale1,scale2,sine,cosine;
if((GET(0x58)<0 ? -GET(0x58):GET(0x58))>=2)scale1=GET(0x58);else if(GET(0x58)>2)scale1=2;else if(GET(0x58)<-2)scale1=-2;else scale1=GET(0x58);
cosine=data_020e5b30[1];sine=data_020e5b30[0];
if((GET(0x58)<0 ? -GET(0x58):GET(0x58))>=2)scale2=GET(0x58);else if(GET(0x58)>2)scale2=2;else if(GET(0x58)<-2)scale2=-2;else scale2=GET(0x58);
a=func_0207c8ec(cosine<<4,256);
b=func_0207c8ec((-sine)<<4,scale2);
c=func_0207c8ec(sine<<4,256);
d=func_0207c8ec(cosine<<4,scale1);
func_01ff8ddc(0,a,b,c,d);
x1=GET(0x54);
func_01ffaacc((u16)(x1&511),104,ATTR(0x414,0xb000),data_ov000_021b83d8,11);
if(GET(0x58)>20){x1=GET(0x54);func_0209b67c((u16)((M2C_FIELD(arg0,s16*,0x3e)+x1)&511),360,96,ATTR(0x47e,0x2000),10);}
}
if(M2C_FIELD(arg0,u8*,0x3d)&&func_ov000_0216b15c(xa,ya,48,16))
{u16 x=xa&511;u16 attr=ATTR(0x432,0xb000);func_01ffaacc(x,(u16)(ya&255),attr,data_ov000_021b8392,11);}
}
#pragma scheduling reset
#pragma opt_scheduling reset
#pragma peephole reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
void func_ov000_0216bfa4(void *arg0) {
extern u16 *data_02101e84;
extern u8 *data_02101e88;
func_020a91a8(M2C_FIELD(arg0,s32 *,0x44));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x48));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x4c));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x50));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x54));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x58));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x5c));
switch(M2C_FIELD(arg0,u16 *,0x34)){
case 8:func_0208fe30(0x1003e);
case 0x68:func_0208fe30(0x1003f);
}
if((*data_02101e84 &9)||data_02101e88[0x14]||M2C_FIELD(arg0,u16 *,0x34)==0x83)func_01ffa6fc(arg0);
M2C_FIELD(arg0,u16 *,0x34)++;
}

void func_ov000_0216c068(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(3);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
    M2C_FIELD(arg0, u8 *, 0x36) = 0;
}

void func_ov000_0216c09c(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*callback)(void);u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(callback)callback();
func_020c0a88();
v0=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v0=*v0&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
v1=*(u16 **)gCur3DSpriteEngine;*v1=*v1|0x10;
v2=*(u16 **)gCur3DSpriteEngine;*v2=*v2|0x20;
v3=*(u16 **)gCur3DSpriteEngine;*v3=*v3|0x40;
v4=*(u16 **)gCur3DSpriteEngine;*v4=*v4|0x80;
v5=*(u16 **)gCur3DSpriteEngine;*v5=*v5|0x100;
}

void func_ov000_0216c1c4(void) {
    M2C_UNK func_ov000_0216b194();
    func_ov000_0216b194();
}

void func_ov000_0216c1d0(void) {
    void func_ov000_0216c09c(void);
    func_ov000_0216c09c();
}

void func_ov000_0216c1dc(void) {
    void func_ov000_0216c068();
    func_ov000_0216c068();
}

void func_ov000_0216c1e8(void) {
    void func_ov000_0216b898();
    func_ov000_0216b898();
}

void func_ov000_0216c1f4(void) {
    void func_ov000_0216bfa4();
    func_ov000_0216bfa4();
}

void func_ov000_0216c200(void) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(M2C_UNK);
    M2C_UNK func_020a9218(void *);
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02168f14;
    extern void **data_027e0058;
    extern M2C_UNK data_ov000_021b83f8;
    extern M2C_UNK data_ov000_021b841c;
    extern M2C_UNK data_ov000_021b844c;
    extern M2C_UNK data_ov000_021b8488;
    extern M2C_UNK data_ov000_021b84c4;
    extern M2C_UNK data_ov000_021b8500;
    extern M2C_UNK data_ov000_021b853c;
    extern M2C_UNK data_ov000_021b8578;
    extern M2C_UNK data_ov000_021b8690;
    s8 var_r0;
    u16 temp_ip;
    void *mapPtr;
    void *temp_r0;
    void *temp_r0_10;
    void *temp_r0_11;
    void *temp_r0_12;
    void *temp_r0_13;
    void *temp_r0_14;
    void *temp_r0_15;
    void *temp_r0_16;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r0_8;
    void *temp_r0_9;

    temp_r0 = func_01ffa3dc(&data_ov000_021b8578, 7);
    if (temp_r0 == NULL) {
        return;
    }
    var_r0 = 0;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov000_021b8690;
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x36) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x38) = 0x100;
    temp_ip = M2C_FIELD(*data_027e0058, u16 *, 0x52A4);
    M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8)temp_ip;
    mapPtr = (void*)*data_027e0058;
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8)M2C_FIELD((mapPtr + ((s32)temp_ip * 0x8C)), u8 *, 0x67CB);
    mapPtr = (void*)*data_027e0058;
    M2C_FIELD(temp_r0, s8 *, 0x3C) = (s8)(M2C_FIELD((mapPtr + ((s32)(u8)M2C_FIELD(temp_r0, u8 *, 0x3A) * 0x8C)), u8 *, 0x67C1) - 1);
    if (M2C_FIELD(&data_02168f14, u8 *, 3) != 0) {
        var_r0 = 1;
    }
    M2C_FIELD(temp_r0, s8 *, 0x3D) = var_r0;
    M2C_FIELD(temp_r0, s16 *, 0x3E) = 0;
    temp_r0_2 = func_02082028(0x2C);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_02129870;
        M2C_FIELD(temp_r0_2, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_2, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_2, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_2, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_2, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_2, s8 *, 0x18) = 8;
        {
            u8 a = (u8)(M2C_FIELD(temp_r0_2, u8 *, 0x20) & ~1);
            u8 b = (u8)(a & ~0x1E);
            M2C_FIELD(temp_r0_2, u8 *, 0x20) = (u8)((b & ~0xE0) | 0x40);
        }
        M2C_FIELD(temp_r0_2, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_2, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_2, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_2, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_2, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x40) = temp_r0_2;
    temp_r0_3 = func_02082028(0x10);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(temp_r0_3, M2C_UNK **, 4) = &data_ov000_021b844c;
        M2C_FIELD(temp_r0_3, M2C_UNK **, 8) = &data_ov000_021b844c;
        M2C_FIELD(temp_r0_3, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_3, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_3, s8 *, 0xF) = 0;
        temp_r0_4 = func_02082028(0x12);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_3, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_4, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_4, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_4, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = (u16) M2C_FIELD(temp_r0_4, u16 *, 4);
        }
        M2C_FIELD(temp_r0_3, void **, 0) = temp_r0_4;
        M2C_FIELD(temp_r0_3, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_3, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_3, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_3);
        M2C_FIELD(temp_r0_3, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_3, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_3;
    temp_r0_5 = func_02082028(0x10);
    if (temp_r0_5 != NULL) {
        M2C_FIELD(temp_r0_5, M2C_UNK **, 4) = &data_ov000_021b8488;
        M2C_FIELD(temp_r0_5, M2C_UNK **, 8) = &data_ov000_021b8488;
        M2C_FIELD(temp_r0_5, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_5, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_5, s8 *, 0xF) = 0;
        temp_r0_6 = func_02082028(0x12);
        if (temp_r0_6 != NULL) {
            M2C_FIELD(temp_r0_6, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_5, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_6, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_6, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_6, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = (u16) M2C_FIELD(temp_r0_6, u16 *, 4);
        }
        M2C_FIELD(temp_r0_5, void **, 0) = temp_r0_6;
        M2C_FIELD(temp_r0_5, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_5, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_5, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_5);
        M2C_FIELD(temp_r0_5, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_5, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x48) = temp_r0_5;
    temp_r0_7 = func_02082028(0x10);
    if (temp_r0_7 != NULL) {
        M2C_FIELD(temp_r0_7, M2C_UNK **, 4) = &data_ov000_021b84c4;
        M2C_FIELD(temp_r0_7, M2C_UNK **, 8) = &data_ov000_021b84c4;
        M2C_FIELD(temp_r0_7, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0xF) = 0;
        temp_r0_8 = func_02082028(0x12);
        if (temp_r0_8 != NULL) {
            M2C_FIELD(temp_r0_8, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_7, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_8, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_8, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_8, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_8, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_8, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_8, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_8, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_8, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_8, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_8, u16 *, 2) = (u16) M2C_FIELD(temp_r0_8, u16 *, 4);
        }
        M2C_FIELD(temp_r0_7, void **, 0) = temp_r0_8;
        M2C_FIELD(temp_r0_7, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_7, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_7, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_7);
        M2C_FIELD(temp_r0_7, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x4C) = temp_r0_7;
    temp_r0_9 = func_02082028(0x10);
    if (temp_r0_9 != NULL) {
        M2C_FIELD(temp_r0_9, M2C_UNK **, 4) = &data_ov000_021b853c;
        M2C_FIELD(temp_r0_9, M2C_UNK **, 8) = &data_ov000_021b853c;
        M2C_FIELD(temp_r0_9, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_9, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_9, s8 *, 0xF) = 0;
        temp_r0_10 = func_02082028(0x12);
        if (temp_r0_10 != NULL) {
            M2C_FIELD(temp_r0_10, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_9, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_10, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_10, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_10, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_10, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_10, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_10, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_10, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_10, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_10, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_10, u16 *, 2) = (u16) M2C_FIELD(temp_r0_10, u16 *, 4);
        }
        M2C_FIELD(temp_r0_9, void **, 0) = temp_r0_10;
        M2C_FIELD(temp_r0_9, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_9, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_9, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_9);
        M2C_FIELD(temp_r0_9, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_9, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_9;
    temp_r0_11 = func_02082028(0x10);
    if (temp_r0_11 != NULL) {
        M2C_FIELD(temp_r0_11, M2C_UNK **, 4) = &data_ov000_021b83f8;
        M2C_FIELD(temp_r0_11, M2C_UNK **, 8) = &data_ov000_021b83f8;
        M2C_FIELD(temp_r0_11, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_11, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_11, s8 *, 0xF) = 0;
        temp_r0_12 = func_02082028(0x12);
        if (temp_r0_12 != NULL) {
            M2C_FIELD(temp_r0_12, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_11, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_12, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_12, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_12, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_12, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_12, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_12, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_12, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_12, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_12, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_12, u16 *, 2) = (u16) M2C_FIELD(temp_r0_12, u16 *, 4);
        }
        M2C_FIELD(temp_r0_11, void **, 0) = temp_r0_12;
        M2C_FIELD(temp_r0_11, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_11, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_11, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_11);
        M2C_FIELD(temp_r0_11, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_11, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_11;
    temp_r0_13 = func_02082028(0x10);
    if (temp_r0_13 != NULL) {
        M2C_FIELD(temp_r0_13, M2C_UNK **, 4) = &data_ov000_021b841c;
        M2C_FIELD(temp_r0_13, M2C_UNK **, 8) = &data_ov000_021b841c;
        M2C_FIELD(temp_r0_13, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_13, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_13, s8 *, 0xF) = 0;
        temp_r0_14 = func_02082028(0x12);
        if (temp_r0_14 != NULL) {
            M2C_FIELD(temp_r0_14, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_13, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_14, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_14, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_14, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_14, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_14, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_14, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_14, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_14, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_14, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_14, u16 *, 2) = (u16) M2C_FIELD(temp_r0_14, u16 *, 4);
        }
        M2C_FIELD(temp_r0_13, void **, 0) = temp_r0_14;
        M2C_FIELD(temp_r0_13, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_13, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_13, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_13);
        M2C_FIELD(temp_r0_13, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_13, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x58) = temp_r0_13;
    temp_r0_15 = func_02082028(0x10);
    if (temp_r0_15 != NULL) {
        M2C_FIELD(temp_r0_15, M2C_UNK **, 4) = &data_ov000_021b8500;
        M2C_FIELD(temp_r0_15, M2C_UNK **, 8) = &data_ov000_021b8500;
        M2C_FIELD(temp_r0_15, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_15, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_15, s8 *, 0xF) = 0;
        temp_r0_16 = func_02082028(0x12);
        if (temp_r0_16 != NULL) {
            M2C_FIELD(temp_r0_16, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_15, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_16, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_16, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_16, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_16, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_16, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_16, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_16, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_16, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_16, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_16, u16 *, 2) = (u16) M2C_FIELD(temp_r0_16, u16 *, 4);
        }
        M2C_FIELD(temp_r0_15, void **, 0) = temp_r0_16;
        M2C_FIELD(temp_r0_15, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_15, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_15, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_15);
        M2C_FIELD(temp_r0_15, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_15, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x5C) = temp_r0_15;
}

