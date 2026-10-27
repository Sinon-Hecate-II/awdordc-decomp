/* 25 functions from 0x0216C7F0 to 0x0216D2B4 (ov000), found by ds-decomp. */
#include "common.h"

void *func_ov000_0216c7f0(void *p){
extern M2C_UNK data_ov000_021b8690;
void func_02082040(void *);
void *q;
M2C_FIELD(p,void **,0)=&data_ov000_021b8690;
q=M2C_FIELD(p,void **,0x40);
if(q)M2C_FIELD(M2C_FIELD(q,void **,0),void (**)(void *),4)(q);
q=M2C_FIELD(p,void **,0x44);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x48);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x4c);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x50);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x54);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x58);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x5c);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
func_02082040(p);
return p;
}

void *func_ov000_0216c928(void *p){
extern M2C_UNK data_ov000_021b8690;
void func_02082040(void *);
void *q;
M2C_FIELD(p,void **,0)=&data_ov000_021b8690;
q=M2C_FIELD(p,void **,0x40);
if(q)M2C_FIELD(M2C_FIELD(q,void **,0),void (**)(void *),4)(q);
q=M2C_FIELD(p,void **,0x44);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x48);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x4c);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x50);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x54);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x58);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
q=M2C_FIELD(p,void **,0x5c);if(q){if(M2C_FIELD(q,void **,0))func_02082040(M2C_FIELD(q,void **,0));func_02082040(q);}
return p;
}

s32 func_ov000_0216ca58(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_r2;

    temp_r2 = *gCurrentMap;
    return M2C_FIELD((temp_r2 + (arg0 + M2C_FIELD((temp_r2 + (arg1 * 2)), u16 *, 0x3758))), u8 *, 0x1420) & 0x1F;
}

s32 func_ov000_0216ca8c(s32 x,s32 y){
extern s32 *gCurrentMap;
void *func_020a45f8(s32,s32);
s32 type,index,p; void *unit; p=*gCurrentMap;
index=x+M2C_FIELD(p+y*2,u16 *,0x3758);
type=M2C_FIELD(p+index,u8 *,0x1420)&31;
switch(M2C_FIELD(p,u8 *,0x5157)){
case 0:if(type==29)return 32;break;
case 4:if(type==29)return 38;if(type==4)return 39;break;
case 8:if(type==29)return 37;if(type==2)return 36;break;
case 9:if(type!=29)break;unit=func_020a45f8(x,y);if(unit){u32 kind=((u32)M2C_FIELD(unit,u16 *,2)<<22)>>28;if(kind==6)return 34;if(kind==7)return 35;}return 33;
}
if(type==1){switch(M2C_FIELD(p+index*2,u16 *,0xa10)){case 4:return 40;case 5:return 41;}}
return type;
}

s32 func_ov000_0216cbc4(s32 arg0) {
 switch(arg0) {
 case 32: arg0=29; break;
 case 38: arg0=29; break;
 case 39: arg0=4; break;
 case 37: arg0=29; break;
 case 36: arg0=2; break;
 case 34: arg0=29; break;
 case 35: arg0=29; break;
 case 33: arg0=29; break;
 case 40: arg0=1; break;
 case 41: arg0=1; break;
 }
 return arg0;
}

s32 func_ov000_0216cc4c(s32 arg0, s32 arg1) {
 s32 func_020cfc0c(s32);
 extern s32 *gCurrentMap;
 s32 temp_r2 = *gCurrentMap;
 return func_020cfc0c(M2C_FIELD(temp_r2 + (arg0 + M2C_FIELD(temp_r2 + arg1 * 2, u16 *, 0x3758)), u8 *, 0x1420));
}

s32 func_ov000_0216cc84(s32 arg0, s32 arg1) {
 s32 func_020d05f4(s32,s32,s32);
 s32 func_0207c8ec(s32,s32);
 extern s32 *gCurrentMap;
 s32 base = *gCurrentMap;
 s32 result = func_0207c8ec(func_020d05f4(M2C_FIELD(base,u16 *,0x52A4),0,M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1*2,u16 *,0x3758)),u8 *,0x1420)&31),10);
 if(result>4) return 4;
 if(result<0) return 0;
 return result;
}

u32 func_ov000_0216ccf0(u8 *arg0) {
    return (u32) (*arg0 << 0x1A) >> 0x1A;
}

s32 func_ov000_0216cd00(void *arg0) {
    s32 func_0207c8ec(s32, M2C_UNK);
    u32 temp_r0;

    temp_r0 = (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
    if (temp_r0 == 0) {
        return 0;
    }
    return func_0207c8ec(temp_r0 - 1, 0xA) + 1;
}

u32 func_ov000_0216cd2c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19;
}

u32 func_ov000_0216cd3c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C;
}

s32 func_ov000_0216cd4c(s32 arg0) {
s32 func_020e3438(s32);extern u8 data_ov000_021b5c69;
return func_020e3438(1)+((&data_ov000_021b5c69)[arg0*0x70]<<8);
}

void *func_ov000_0216cd78(void) {
 s32 func_020a7298();
 extern M2C_UNK data_02121e08;
 return (u8 *)&data_02121e08 + (func_020a7298() << 7);
}

void *func_ov000_0216cd90(s32 arg0) {
    extern M2C_UNK data_02120a20;
    return (u8 *)&data_02120a20 + ((arg0 - 1) << 5);
}

s32 func_ov000_0216cda4(s32 arg0) {
s32 func_020e3438(s32);extern u8 data_ov000_021b8711;
return func_020e3438(0)+((&data_ov000_021b8711)[arg0*3]<<9);
}

void *func_ov000_0216cdcc(s32 arg0) {
extern u8 data_02123c40;extern u8 data_ov000_021b8710;
return &data_02123c40+((&data_ov000_021b8710)[arg0*3]<<8);
}

void *func_ov000_0216cdec(s32 arg0,s32 arg1) {
extern u8 data_02120b20;extern u8 data_ov000_021b8712;
return &data_02120b20+((arg1+(&data_ov000_021b8712)[arg0*3])<<5);
}

void *func_ov000_0216ce10(u32 arg0) {
 extern M2C_UNK data_02120d20;
 switch(arg0) {
 case 1:return (u8 *)&data_02120d20;
 case 2:return (u8 *)&data_02120d20+128;
 case 3:return (u8 *)&data_02120d20+256;
 case 4:return (u8 *)&data_02120d20+384;
 case 5:return (u8 *)&data_02120d20+512;
 case 0:return (u8 *)&data_02120d20+640;
 default:return 0;
 }
}

void *func_ov000_0216ce84(u32 arg0) {
 extern M2C_UNK data_02120780;
 switch(arg0) {
 case 1:return (u8 *)&data_02120780;
 case 2:return (u8 *)&data_02120780+32;
 case 3:return (u8 *)&data_02120780+64;
 case 4:return (u8 *)&data_02120780+96;
 case 0:return (u8 *)&data_02120780+128;
 default:return 0;
 }
}

void func_ov000_0216cee8(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    extern M2C_UNK data_ov000_021b8838;
    func_0200bc5c(&data_ov000_021b8838);
}

void func_ov000_0216cefc(void){
extern void *gCur3DSpriteEngine,*data_027e00c8,*data_ov000_021df5e0;
void *saved=gCur3DSpriteEngine;s32 tile;
gCur3DSpriteEngine=data_027e00c8;
tile=M2C_FIELD(data_ov000_021df5e0,u8 *,17)?1:13;
func_02007e98(0,M2C_FIELD(gCur3DSpriteEngine,s32 *,12),64);
func_020985b0(M2C_FIELD(data_ov000_021df5e0,u8 *,15),0,M2C_FIELD(gCur3DSpriteEngine,s32 *,12)+(tile<<6));
func_02098a34(M2C_FIELD(data_ov000_021df5e0,u8 *,15),0,2,M2C_FIELD(data_ov000_021df5e0,u8 *,17),0);
func_02098844(0,1,21,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),(u16)tile,M2C_FIELD(data_ov000_021df5e0,u8 *,17),1);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,56)=0xffff;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,64)=1;
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=1;
func_ov000_0216cee8();
gCur3DSpriteEngine=saved;
}

void func_ov000_0216d020(void) {
extern void *gCur3DSpriteEngine,*data_027e00c4,*data_ov000_021df5e0;
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c4;
if(M2C_FIELD(data_ov000_021df5e0,u8 *,14)) {
func_02007e98(0,M2C_FIELD(gCur3DSpriteEngine,s32 *,12),64);
func_020985b0(M2C_FIELD(data_ov000_021df5e0,u8 *,15),8,M2C_FIELD(gCur3DSpriteEngine,s32 *,12)+64);
func_02098a34(M2C_FIELD(data_ov000_021df5e0,u8 *,15),8,2,0,0);
func_02098844(8,12,0,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),1,0,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=1;
func_ov000_0216cee8();
}else{
func_020809c0(M2C_FIELD(gCur3DSpriteEngine,s32 *,32)+24,20,24);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=1;
}
gCur3DSpriteEngine=saved;
}

void func_ov000_0216d130(void) {
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_020e3004();
    M2C_UNK *func_020e3018(u8);
    s32 func_020e3218(M2C_UNK *);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021b884c;
    extern void *data_ov000_021df5e0;
    M2C_UNK *temp_r5;
    s32 temp_z;
    void *temp_r4;

    temp_r5 = func_020e3018(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xE));
    temp_z = temp_r5 == NULL;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (!temp_z) {
        func_020e3004();
        func_020e3218(&data_ov000_021b884c);
        func_020814e4();
        func_02081590(func_020e3218(temp_r5), M2C_FIELD(data_027e00c4, s32 *, 0x1C) + 0x2800);
        func_02081528();
        func_ov000_0216cee8();
    } else {
        func_02007e98(0, M2C_FIELD(data_027e00c4, s32 *, 0x1C) + 0x2800, 0x800);
    }
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_0216d1c8(void) {
 void func_02007ef4(void *,s32,s32);
 void func_01ff9e44(void *,s32,s32);
 extern void *data_ov000_021df5e0;
 extern s32 *gCurrentMap;
 extern void *data_027e00c4;
 s32 p = *gCurrentMap + 0x67a4 + M2C_FIELD(data_ov000_021df5e0,u8 *,M2C_FIELD(data_ov000_021df5e0,u8 *,13))*140;
 s32 dest = M2C_FIELD(data_027e00c4,volatile s32 *,28);
 func_02007ef4(func_ov000_0216ce10(M2C_FIELD(p,u8 *,39)),dest+0x3000,128);
 func_01ff9e44(func_ov000_0216ce84(M2C_FIELD(p,u8 *,29)),0x2e0,32);
}

void func_ov000_0216d23c(void) {
 s32 func_020a8b3c(s32);
 void func_0209b59c(s32,s32);
 void func_0209b5e4(s32,s32);
 extern void *data_ov000_021df5e0;
 extern s32 *gCurrentMap;
 extern void *data_027e00c4;
 s32 val=func_020a8b3c(M2C_FIELD(*gCurrentMap + M2C_FIELD(data_ov000_021df5e0,u8 *,M2C_FIELD(data_ov000_021df5e0,u8 *,13))*140,u8 *,0x67cb));
 func_0209b59c(M2C_FIELD(data_027e00c4,s32 *,28)+0x3080,128);
 func_0209b5e4(M2C_FIELD(data_027e00c4,s32 *,28)+0x3080,val);
}

