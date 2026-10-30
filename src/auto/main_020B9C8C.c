/* 24 functions from 0x020B9C8C to 0x020BAC24 (main), found by ds-decomp. */
#include "common.h"
static inline s32 DistanceBAAE0(s32 x,s32 y,s32 xx,s32 yy) { s32 d=0; if(x-xx>0)d+=x-xx;else d+=xx-x; if(y-yy>0)d+=y-yy;else d+=yy-y; return d; }
typedef struct { u8 pad0[0x508]; u8 cells[0x3250]; u16 rows[0x40]; u8 pad37d8[0x196c]; u16 width,height; u8 pad5148[0x85c]; u8 units[256][14]; } MapBAAE0;

void func_020b9c8c(u8 *arg0) {
 void func_020994e0(s32); void func_02091cd0(void); void func_020c0a88(void);
 void func_020cfd28(void); void func_0200bc5c(void *);
 M2C_UNK func_020e3218(void *); void func_020814e4(void);
 void func_02081590(M2C_UNK,M2C_UNK); void func_020815fc(M2C_UNK,s32,s32); void func_02081528(void);
 void func_01ff85b8(M2C_UNK,s32,s32); void func_020b9bec(void); void func_020b9c40(void);
 void func_0208fe30(s32); void func_020b9558(u8); void func_020c0fac(void *);
 extern void **gCurrentMap; extern void *gCur3DSpriteEngine;
 extern M2C_UNK data_021291f0; extern M2C_UNK data_021291f8;
 extern M2C_UNK data_0212920c; extern M2C_UNK data_0212921c; extern M2C_UNK data_0212922c;
 extern u8 data_0215d850[];
 void (*callback)(void);
 func_020994e0(0);
 func_02091cd0();
 func_020c0a88();
 callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x54);
 if(callback)callback();
 func_020cfd28();
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=0;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=0;
 M2C_FIELD(arg0,u16 *,0x34)=0;
 M2C_FIELD(arg0,u16 *,0x36)=0;
 func_0200bc5c(&data_021291f0);
 func_020e3218(&data_021291f8);
 func_020814e4();
 func_02081590(func_020e3218(&data_0212920c),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x14)+0x2480);
 func_02081590(func_020e3218(&data_0212921c),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28));
 func_020815fc(func_020e3218(&data_0212922c),0xc0,0x20);
 func_02081528();
 func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28),0x100,0x6124);
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 func_020b9bec(); func_020b9c40();
 func_0208fe30(0x10017);
 func_020b9558(data_0215d850[8]);
 func_020c0fac(arg0);
}

void func_020b9dc8(void) {

}

void func_020b9dcc(void) {
 void func_020b9978(void); void func_01ff9ce8(s32); void func_0207a668(void); void func_020b2268(void);
 extern void **gCurrentMap;
 extern void *gCur3DSpriteEngine;
 void (*callback)(void);
 func_020b9978();
 func_01ff9ce8(2);
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),4);
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

/* Report whether facility type `facility` is available on the current map in
 * mode 0: reject it if the per-facility table (data_ov000_021aab78) marks it
 * invalid (-1) or its attribute word (data_ov000_021b5c00[type*0x70]) is zero;
 * otherwise each facility type is blocked on the special maps whose id lies in
 * [0xa1, limit] (larger limits cover more facilities). */
s32 func_020b9ec0(s32 unit, s32 facility) {
    s32 func_020a7bbc(s32);
    s32 func_ov004_02213820(void);
    extern M2C_UNK data_ov000_021aab78;
    extern void **gCurrentMap;
    u16 mapId;
    (void)unit;
    if (M2C_FIELD(&data_ov000_021aab78, s8 *, facility) == -1) return 0;
    if (func_020a7bbc(facility) == 0) return 0;
    switch (facility) {
    case 17:
        return 0;
    default:
        switch (facility) {
        case 8:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xaa) return 0;
            break;
        case 9:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xae) return 0;
            break;
        case 26:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa5) return 0;
            if (mapId == 0xa5 && func_ov004_02213820() == 0) return 0;
            break;
        case 6: case 11: case 12:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa6) return 0;
            break;
        case 18: case 19:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa7) return 0;
            break;
        case 13: case 14: case 15: case 16:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa8) return 0;
            break;
        case 24: case 25:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xaa) return 0;
            break;
        case 20: case 22: case 23:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xab) return 0;
            break;
        case 21:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xac) return 0;
            break;
        }
        return 1;
    }
}

#pragma opt_common_subs off
s32 func_020ba12c(s32 x,s32 y,s32 type,s32 mode) {
extern void **gCurrentMap;
extern u8 data_ov000_021b5c0e[];
extern M2C_UNK data_0212616c;
u8 *p; s32 index;
if(x<0 || y<0)goto fail;
p=*gCurrentMap;
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

s32 func_020ba1fc(s32 x,s32 y,s32 n){
extern void **gCurrentMap;s32 func_020c94ec(void);
s32 off;u8 *base;s8 mask=0;
if(!n)return mask;
base=(u8 *)*gCurrentMap+0x59a4;off=n*14;
if(!(func_020c94ec()&4)&&func_020ba12c(x-1,y,(u32)(base[off]<<26)>>26,1)==1)mask|=4;
if(!(func_020c94ec()&8)&&func_020ba12c(x+1,y,(u32)(base[off]<<26)>>26,1)==1)mask|=8;
if(!(func_020c94ec()&1)&&func_020ba12c(x,y-1,(u32)(base[off]<<26)>>26,1)==1)mask|=1;
if(!(func_020c94ec()&2)&&func_020ba12c(x,y+1,(u32)(base[off]<<26)>>26,1)==1)mask|=2;
return mask;
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
extern void **gCurrentMap;
s32 func_020a84b4(s32,s32);s32 func_020a81c8(void *);s32 func_020d277c(s32,void *);
u8 *p,*base; s32 offset; u8 result;
if(x<0 || y<0)goto fail;
p=*gCurrentMap;
if(x>=M2C_FIELD(p,u16 *,0x5144)||y>=M2C_FIELD(p,u16 *,0x5146))goto fail;
goto valid;
fail:return 0;
valid:
if(func_020a84b4(x,y))return 0;
p=*gCurrentMap;
base=p+0x59a4;
offset=(s16)p[x+M2C_FIELD(p+y*2,u16 *,0x3758)]*(s16)14;
if(!func_020a81c8(base+offset))return 0;
if(func_020d277c(a,base+offset))result=1;else result=0;
return result;
}

s32 func_020ba510(s32 x,s32 y){
extern void **gCurrentMap;
extern u8 data_ov000_021b5c66[],data_ov000_021b5c05[],data_ov000_021b5c0a[];
s32 func_020a8604(s32);
u8 *p,*u; s32 n;
if(x<0||y<0)goto fail;
p=*gCurrentMap;
if(x>=M2C_FIELD(p,u16 *,0x5144)||y>=M2C_FIELD(p,u16 *,0x5146))goto fail;
goto valid;
fail:return 0;
valid:n=M2C_FIELD(p+(x+M2C_FIELD(p+y*2,u16 *,0x3758)),u8 *,0x508);
if(!n)return 0;
if((n&0xc0)!=M2C_FIELD(p,u16 *,0x52a8))return 0;
u=p+0x59a4+n*14;
if(u==M2C_FIELD(p,u8 **,0x52d0))return 0;
if(!data_ov000_021b5c66[((u32)(u[0]<<26)>>26)*112])return 0;
if(func_020a8604((u32)(u[0]<<26)>>26) || data_ov000_021b5c05[((u32)(u[0]<<26)>>26)*112]==((u32)(M2C_FIELD(u,u16 *,6)<<21)>>28)){
if(data_ov000_021b5c0a[((u32)(u[0]<<26)>>26)*112]==((u32)(u[10]<<25)>>25))return 0;
}
return 1;
}

s32 func_020ba654(s32 arg0,s32 x,s32 y,s32 slot){
extern void **gCurrentMap;extern u8 data_ov000_021b5c0e[];extern s8 data_ov000_021b54a0[];extern M2C_UNK data_0212616c;
s32 func_020ba1fc(s32,s32,s32);
u8 *p=(u8 *)arg0,*base,*unit,*cargo=p+12;s32 kind,tile;s16 n;
if(!func_020ba1fc(x,y,cargo[slot]))return 0;
base=*gCurrentMap;
unit=base+0x59a4+(s16)cargo[slot]*(s16)14;
if(data_ov000_021b5c0e[((u32)(p[0]<<26)>>26)*112]==7){
if(!data_ov000_021b54a0[M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),u8 *,0x1420)&31])return 0;
}
if(M2C_FIELD((s8 *)M2C_FIELD(&data_0212616c,void **,0x64)+data_ov000_021b5c0e[((u32)(unit[0]<<26)>>26)*112]*32,s8 *,M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),u8 *,0x1420)&31)==-1)return 0;
return 1;
}

void func_020ba770(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020ba654(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020ba654(arg0, arg1, arg2, 0);
}

void func_020ba780(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_020ba654(arg0, arg1, arg2, 1);
}

u8 func_020ba790(s32 x,s32 y){
extern void **gCurrentMap;extern u8 data_ov000_021b5c0e[];extern s8 data_ov000_021b54a0[];extern M2C_UNK data_0212616c;
s32 func_020a6fe4(void *,s32);
u8 *base=*gCurrentMap,*units=base+0x59a4;s32 offset,kind,tile;u8 *selected;u8 id;
id=base[x+M2C_FIELD(base+y*2,u16 *,0x3758)];offset=(s16)id*(s16)14;
if(!id)return 0;
if((id&0xc0)!=(M2C_FIELD(base,u8 *,0x52d4)&0xc0))return 0;
if(!func_020a6fe4(units+offset,(u32)(M2C_FIELD(M2C_FIELD(base,u8 **,0x52d0),u8 *,0)<<26)>>26))return 0;
base=*gCurrentMap;selected=M2C_FIELD(base,u8 **,0x52d0);
if(selected[1]==x&&selected[2]==y)return 0;
kind=data_ov000_021b5c0e[((u32)(units[offset]<<26)>>26)*112];
if(kind==7){if(!data_ov000_021b54a0[M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),u8 *,0x1420)&31])return 0;}
tile=M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),u8 *,0x1420)&31;
if(M2C_FIELD((s8 *)M2C_FIELD(&data_0212616c,void **,0x64)+kind*32,s8 *,tile)==-1)return 0;
return M2C_FIELD((s8 *)M2C_FIELD(&data_0212616c,void **,0x64)+data_ov000_021b5c0e[((u32)(selected[0]<<26)>>26)*112]*32,s8 *,tile)!=-1;
}

s32 func_020ba924(s32 a,s32 b) {
 extern void **gCurrentMap;
 extern u8 data_ov000_021b56c0[];
 s32 func_020d27ec(s32,s32);
 s32 p=(s32)*gCurrentMap;
 u8 t=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420);
 if(func_020d27ec(M2C_FIELD(p,u8 *,0x52d4),t))return 0;
 return data_ov000_021b56c0[t&31];
}

u8 func_020ba980(s32 a,s32 b) {
 extern void **gCurrentMap;
 u8 *p; s32 v; u8 result;
 if(a<0||b<0)goto fail;
 p=*gCurrentMap;
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
 extern void **gCurrentMap;
 s32 p=(s32)*gCurrentMap;
 switch(M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31){case 24:return 1;default:return 0;}
}

void func_020baa64(void) {
 extern void **gCurrentMap;
 void *p=*gCurrentMap;
 void *q;
 if(M2C_FIELD(p,s16 *,0x52d8)==M2C_FIELD(p,s16 *,0x52dc) && M2C_FIELD(p,s16 *,0x52da)==M2C_FIELD(p,s16 *,0x52de))return;
 q=M2C_FIELD(p,void **,0x52d0);
 M2C_FIELD(q,u16 *,6)&=~0xf800;
}

void func_020baaac(void) {
 extern void **gCurrentMap;
 void *p;
 p=*gCurrentMap;
 M2C_FIELD(p,s16 *,0x52d8)=M2C_FIELD(p,s16 *,0x52dc);
 p=*gCurrentMap;
 M2C_FIELD(p,s16 *,0x52da)=M2C_FIELD(p,s16 *,0x52de);
}

void func_020baae0(s16 x,s16 y) {
extern void **gCurrentMap;
MapBAAE0 *p; s32 d; s32 xx; s32 right; s32 yy; s32 bottom; s32 left=x-1; s32 top; u8 *unit;
if(left<0)left=0;
top=y-1;p=*gCurrentMap;if(top<0)top=0;
right=p->width-1 < x+1 ? p->width-1 : x+1;
bottom=p->height-1 < y+1 ? p->height-1 : y+1;
for(yy=top;yy<=bottom;yy++)for(xx=left;xx<=right;xx++){
d=DistanceBAAE0(x,y,xx,yy);
if(d<1 || d>1)continue;
p=*gCurrentMap;
unit=p->units[p->cells[xx+p->rows[yy]]];
if(((u32)(unit[0]<<26)>>26) && (M2C_FIELD(unit,u16 *,4)&32))M2C_FIELD(unit,u16 *,4)|=64;
}
}

void func_020babfc(void) {
    void func_020baae0(s16, s16);
    extern void **gCurrentMap;
    void *temp_r0;

    temp_r0 = *gCurrentMap;
    func_020baae0(M2C_FIELD(temp_r0, s16 *, 0x52DC), M2C_FIELD(temp_r0, s16 *, 0x52DE));
}

