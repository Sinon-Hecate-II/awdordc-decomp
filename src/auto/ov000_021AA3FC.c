/* 9 functions from 0x021AA3FC to 0x021AAB78 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"

s32 func_ov000_021aa3fc(void *arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_021a9904(u32);
    extern u8 data_ov000_021b5c00;
    s32 result;
    u32 f0;
    u32 f6;
    u32 count;
    u16 entry;
    if ((M2C_FIELD(arg0, u16 *, 6) & 0x7FU) <= 0xAU) return 2;
    f0 = ((u8 *)arg0)[0] & 0x3FU;
    if (func_ov000_021a9904(f0) == 2 && arg2 == 1) return 2;
    f6 = M2C_FIELD(arg0, u16 *, 6) & 0x7FU;
    if (arg1 < (s32)f6) count = (u32)arg1;
    else count = f6 - 1U;
    entry = M2C_FIELD(&data_ov000_021b5c00, u16 *, (s32)(f0 * 0x70U));
    result = (s32)entry * (s32)count;
    if (func_ov000_021a9904(f0) == 2 && arg2 == 0) result = result >> 1;
    return result;
}

u32 func_ov000_021aa4a4(void *arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_021a9904(u32);
    u32 temp_r0;
            u32 var_r0;
    u32 var_r5;

    if ((u32) ((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19) <= 0xAU) {
        return 1U;
    }
    if ((func_ov000_021a9904((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) == 2) && (arg2 == 1)) {
        return 1U;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 6) << 0x19;
    if (arg1 < (s32) (temp_r0 >> 0x19)) {
        var_r0 = arg1 << 0x10;
    } else {
        var_r0 = ((temp_r0 >> 0x19) - 1) << 0x10;
    }
    var_r5 = var_r0 >> 0x10;
    if ((func_ov000_021a9904((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) == 2) && (arg2 == 0)) {
        var_r5 = (u32) (var_r5 << 0xF) >> 0x10;
    }
    return var_r5;
}

s32 func_ov000_021aa534(s32 arg0, s32 arg1) {
    s32 var_r0;

    if (arg1 == 0) {
        return 0x80000001;
    }
    var_r0 = arg1 - arg0;
    if (var_r0 < 0x2328) {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021aa558(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return 0x80000001;
    }
    return arg1 - (arg0 * 2);
}

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
s32 func_ov000_021aa568(void *a, s32 x, s32 y, s32 range, s32 count, s32 flag, s32 oldx, s32 oldy) {
extern void **gCurrentMap;
extern void *data_ov000_021e14e0[];
s32 func_ov000_021a93ec(s32,s32);
s32 func_020d273c(void *,s32);
typedef s32 (*Value)(void *,s32,s32);
typedef s32 (*Combine)(s32,s32);
s32 xmin,ymin,right,bottom,dist,dx,zero,id;
void *base;
UnkStruct_ov000_021A860C *unit;
s32 enemy=0;
s32 xx,dy,yy;
s32 own=0;
xmin=x-range;if(xmin<0)xmin=0;
ymin=y-range;if(ymin<0)ymin=0;
base=*gCurrentMap;
right=M2C_FIELD(base,u16 *,0x5144)-1;
if(x+range<right)right=x+range;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
if(y+range<bottom)bottom=y+range;
for(yy=ymin;yy<=bottom;yy++){
xx=xmin;
if(xx<=right){
dy=y-yy;
do {
dx=x-xx;if(dx<=0)dx=xx-x;
zero=0;
dist=zero;
dist+=dx;
if(dy>0)dist+=dy;else dist+=yy-y;
if(dist<0||dist>range)continue;
if(xx==oldx && yy==oldy)unit=M2C_FIELD(*gCurrentMap,UnkStruct_ov000_021A860C **,0x52d0);
else{
base=*gCurrentMap;
id=M2C_FIELD((u8 *)base+xx+M2C_FIELD((u8 *)base+yy*2,u16 *,0x3758),u8 *,0x508);
unit=(UnkStruct_ov000_021A860C *)((u8 *)base+0x59a4)+id;
}
if(unit->unk0==0)continue;
if(flag==1 && func_ov000_021a93ec(((u8 *)unit)[1],((u8 *)unit)[2])==0)continue;
if(unit==0)id=0;
else id=unit-(UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4);
if(func_020d273c(a,(id>>6)+1)==1)own+=((Value)data_ov000_021e14e0[1])(unit,count,0);
else enemy+=((Value)data_ov000_021e14e0[1])(unit,count,1);
}while(++xx<=right);
}
}
base=*gCurrentMap;
id=M2C_FIELD((u8 *)base+(x+M2C_FIELD((u8 *)base+y*2,u16 *,0x3758)),u8 *,0x508);
if(id!=0 && func_020d273c(a,(id>>6)+1)==0)enemy++;
return ((Combine)data_ov000_021e14e0[0])(own,enemy);
}
#pragma opt_strength_reduction reset
#pragma opt_loop_invariants reset
void func_ov000_021aab20(s32, s32, s32, s32, s32, s32);
s32 func_ov000_021aa820(s32 a, s32 b, s32 c, s32 d) {
    s32 x;
    s32 y;
    typedef s32 (*Fn)(s32, s32, s32, s32, s32, s32);
    switch (d) {
    case 0:
        x = 2;
        y = 0x1e;
        break;
    case 1:
        x = 2;
        y = 0x50;
        break;
    default:
        return 0;
    }
    return ((Fn)func_ov000_021aab20)(a, b, c, d, x, y);
}

s32 func_ov000_021aa870(s16 *out, void *a, s32 b, s32 mode, s32 c, s32 d, u8 filter) {
s32 RandomIntRange(s32,s32);
extern void *data_ov000_021e14e0[];
extern void **gCurrentMap;
s32 x,y,best,xx,yy,value;
void *base;
typedef s32 (*Score)(void *,s32,s32,s32,s32,s32,s32,s32);
switch(mode){
case 0:
x=out[0];y=out[1];best=0;
data_ov000_021e14e0[1]=(void *)func_ov000_021aa3fc;
data_ov000_021e14e0[0]=(void *)func_ov000_021aa534;
break;
case 1:
y=-1;x=y;best=0x80000001;
switch(RandomIntRange(0,1)){
case 0:data_ov000_021e14e0[1]=(void *)func_ov000_021aa3fc;break;
case 1:data_ov000_021e14e0[1]=(void *)func_ov000_021aa4a4;break;
}
data_ov000_021e14e0[0]=(void *)func_ov000_021aa558;
break;
case 6:
y=-1;x=y;
data_ov000_021e14e0[1]=(void *)func_ov000_021aa3fc;
data_ov000_021e14e0[0]=(void *)func_ov000_021aa534;
best=0x80000001;
break;
default:return 0;
}
if(filter){
for(yy=0;yy<M2C_FIELD(*gCurrentMap,u16 *,0x5146);yy++){
for(xx=0;xx<M2C_FIELD(*gCurrentMap,u16 *,0x5144);xx++){
base=*gCurrentMap;
if(((s8 **)((u8 *)base+0x52e8))[yy][xx]<0)continue;
value=((Score)func_ov000_021aa568)(a,xx,yy,c,d,b,x,y);
if(value>best){best=value;out[0]=xx;out[1]=(s16)yy;}
}
}
}else{
for(yy=0;yy<M2C_FIELD(*gCurrentMap,u16 *,0x5146);yy++){
for(xx=0;xx<M2C_FIELD(*gCurrentMap,u16 *,0x5144);xx++){
value=((Score)func_ov000_021aa568)(a,xx,yy,c,d,b,x,y);
if(value>best){best=value;out[0]=xx;out[1]=(s16)yy;}
}
}
}
if(mode!=0){if(best!=(s32)0x80000001)return 1;}
else if(best!=0)return 1;
return 0;
}

void func_ov000_021aab20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)func_ov000_021aa870)(a, b, c, d, e, f, 0);
}

void func_ov000_021aab4c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    typedef void (*Fn)(s32, s32, s32, s32, s32, s32, s32);
    ((Fn)func_ov000_021aa870)(a, b, c, d, e, f, 1);
}

