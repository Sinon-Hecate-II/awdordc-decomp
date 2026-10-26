/* 24 functions from 0x020B9C8C to 0x020BAC24 (main), found by ds-decomp. */
#include "common.h"

void func_020b9dc8(void) {

}

void func_020b9dcc(void) {
 void func_020b9978(void); void func_01ff9ce8(s32); void func_0207a668(void); void func_020b2268(void);
 extern void **data_027e0058;
 extern void *gCur3DSpriteEngine;
 void (*callback)(void);
 func_020b9978();
 func_01ff9ce8(2);
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 callback=M2C_FIELD(M2C_FIELD(data_027e0058,void **,4),void (**)(void),4);
 if(callback) callback();
 func_0207a668(); func_020b2268();
}

s32 func_020b9e20(s32 arg0, s32 arg1) {
 s32 func_020b9e70(s32,s32); s32 func_020b9ec0(s32,s32);
 extern M2C_UNK data_02168f14;
 if(M2C_FIELD(&data_02168f14,u32 *,12)&(1<<(u8)arg1)) return 0;
 switch((u8)((u32)(M2C_FIELD(&data_02168f14,u16 *,0)<<29)>>29)) {
 case 0: return func_020b9ec0(arg0,arg1);
 case 1: default: return func_020b9e70(arg0,arg1);
 }
}

s32 func_020b9e70(s32 arg0,s32 arg1) {
 s32 func_020a7bbc(s32);
 extern M2C_UNK data_ov000_021aab78;
 if(M2C_FIELD(&data_ov000_021aab78,s8 *,arg1)==-1) return 0;
 if(func_020a7bbc(arg1)==0) return 0;
 switch(arg1) { case 17: return 0; default: return 1; }
}

#pragma opt_common_subs off
s32 func_020ba12c(s32 x,s32 y,s32 type,s32 mode) {
extern void **data_027e0058;
extern u8 data_ov000_021b5c0e[];
extern M2C_UNK data_0212616c;
u8 *p; s32 index;
if(x<0 || y<0)goto fail;
p=*data_027e0058;
if(x>=M2C_FIELD(p,u16 *,0x5144)||y>=M2C_FIELD(p,u16 *,0x5146))goto fail;
goto valid;
fail:return 0;
valid:
if(mode){
index=x+M2C_FIELD(p+y*2,u16 *,0x3758);
if(p[index])return 0;
}else{
index=x+M2C_FIELD(p+y*2,u16 *,0x3758);
if(M2C_FIELD(p+index,u8 *,0x508))return 0;
}
if(M2C_FIELD((s8 *)M2C_FIELD(&data_0212616c,void **,0x64)+data_ov000_021b5c0e[type*0x70]*32,s8 *,M2C_FIELD(p+index,u8 *,0x1420)&31)<0)return 0;
return 1;
}
#pragma opt_common_subs reset
s8 func_020ba320(s32 a,s32 b,s32 c) {
 s32 func_020ba448(s32,s32,s32);
 s8 r=0;
 if(func_020ba448(a,b-1,c)==1)r|=4;
 if(func_020ba448(a,b+1,c)==1)r|=8;
 if(func_020ba448(a,b,c-1)==1)r|=1;
 if(func_020ba448(a,b,c+1)==1)r|=2;
 return r;
}

u8 func_020ba3b4(void *arg0) {
 extern M2C_UNK data_ov000_021b5c0b;
 s32 func_020a76d4();
 u8 var_r0;
 if (M2C_FIELD(&data_ov000_021b5c0b,u8 *,((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70) == 1) return 1;
 if(func_020a76d4(arg0)!=1)return 0;
 if(((u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28)!=0)var_r0=1;else var_r0=0;
 return var_r0;
}

u8 func_020ba414(void *arg0) {
    s32 func_020a76d4();
    u8 var_r0;

    if (func_020a76d4() < 2) {
        return 0U;
    }
    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020ba448(s32 a,s32 x,s32 y) {
extern void **data_027e0058;
s32 func_020a84b4(s32,s32);s32 func_020a81c8(void *);s32 func_020d277c(s32,void *);
u8 *p,*base; s32 offset; u8 result;
if(x<0 || y<0)goto fail;
p=*data_027e0058;
if(x>=M2C_FIELD(p,u16 *,0x5144)||y>=M2C_FIELD(p,u16 *,0x5146))goto fail;
goto valid;
fail:return 0;
valid:
if(func_020a84b4(x,y))return 0;
p=*data_027e0058;
base=p+0x59a4;
offset=(s16)p[x+M2C_FIELD(p+y*2,u16 *,0x3758)]*(s16)14;
if(!func_020a81c8(base+offset))return 0;
if(func_020d277c(a,base+offset))result=1;else result=0;
return result;
}

void func_020ba770(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020ba654(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020ba654(arg0, arg1, arg2, 0);
}

void func_020ba780(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_020ba654(arg0, arg1, arg2, 1);
}

s32 func_020ba924(s32 a,s32 b) {
 extern void **data_027e0058;
 extern u8 data_ov000_021b56c0[];
 s32 func_020d27ec(s32,s32);
 s32 p=(s32)*data_027e0058;
 u8 t=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420);
 if(func_020d27ec(M2C_FIELD(p,u8 *,0x52d4),t))return 0;
 return data_ov000_021b56c0[t&31];
}

u8 func_020ba980(s32 a,s32 b) {
 extern void **data_027e0058;
 u8 *p; s32 v; u8 result;
 if(a<0||b<0)goto fail;
 p=*data_027e0058;
 if(a>=M2C_FIELD(p,u16 *,0x5144)||b>=M2C_FIELD(p,u16 *,0x5146))goto fail;
 goto valid;
 fail:return 0;
 valid:v=p[a+M2C_FIELD(p+b*2,u16 *,0x3758)];
 if(!v)return 0;
 if((v>>6)+1!=M2C_FIELD(p,u16 *,0x52a4))return 0;
 if(M2C_FIELD(p+v*14,u16 *,0x59a8)&1)result=0;else result=1;
 return result;
}

s32 func_020baa1c(s32 a,s32 b) {
 extern void **data_027e0058;
 s32 p=(s32)*data_027e0058;
 switch(M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31){case 24:return 1;default:return 0;}
}

void func_020baa64(void) {
 extern void **data_027e0058;
 void *p=*data_027e0058;
 void *q;
 if(M2C_FIELD(p,s16 *,0x52d8)==M2C_FIELD(p,s16 *,0x52dc) && M2C_FIELD(p,s16 *,0x52da)==M2C_FIELD(p,s16 *,0x52de))return;
 q=M2C_FIELD(p,void **,0x52d0);
 M2C_FIELD(q,u16 *,6)&=~0xf800;
}

void func_020baaac(void) {
 extern void **data_027e0058;
 void *p;
 p=*data_027e0058;
 M2C_FIELD(p,s16 *,0x52d8)=M2C_FIELD(p,s16 *,0x52dc);
 p=*data_027e0058;
 M2C_FIELD(p,s16 *,0x52da)=M2C_FIELD(p,s16 *,0x52de);
}

void func_020babfc(void) {
    M2C_UNK func_020baae0(s16, s16);
    extern void **data_027e0058;
    void *temp_r0;

    temp_r0 = *data_027e0058;
    func_020baae0(M2C_FIELD(temp_r0, s16 *, 0x52DC), M2C_FIELD(temp_r0, s16 *, 0x52DE));
}

