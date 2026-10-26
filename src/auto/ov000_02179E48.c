/* 10 functions from 0x02179E48 to 0x0217ACD4 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_0217aa2c(s32 x,s32 y) {
extern void **data_027e0058;
void **state=data_027e0058;
void *base=*state;
register s32 left,top,right,bottom; s32 i,result,d,v;
left=x-1;
if(left<0)left=0;
top=y-1;
if(top<0)top=0;
right=M2C_FIELD(base,u16 *,0x5144)-1;
right=right>x+1?x+1:right;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
bottom=bottom>y+1?y+1:bottom;
result=111;
for(;top<=bottom;top++){
for(i=left;i<=right;i++){
d=0;
if(x-i>0)d+=x-i;else d+=i-x;
if(y-top>0)d+=y-top;else d+=top-y;
if(d<1)continue;
if(d>1)continue;
v=M2C_FIELD(((s8 **)((u8 *)*state+0x52e8))[top],s8 *,i);
if(v<0)continue;
if(v<result)result=v;
}}
return result;
}

u8 func_ov000_0217ab10(s32 arg0, s32 arg1, s32 arg2) {
 extern void **data_027e0058;
 s32 func_020d27c0(s32);
 void *base = *data_027e0058;
 u8 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 if (id == 0) return 0;
 return func_020d27c0(id) != 1;
}

u8 func_ov000_0217ab5c(s32 arg0, s32 arg1, s32 arg2) {
 extern void **data_027e0058;
 s32 func_ov000_021a97d0(s32, s32);
 void *base;
 u8 id;
 if (func_ov000_0217ab10(arg0,arg1,0) == 0) return 0;
 base = *data_027e0058;
 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 return func_ov000_021a97d0(arg2, ((u32)(M2C_FIELD(base + id * 14, u8 *, 0x59A4) << 26) >> 26)) > 1;
}

u8 func_ov000_0217abd8(s32 arg0, s32 arg1) {
 extern void **data_027e0058;
 s32 func_ov000_021a9860(s32,s32);
 s32 func_ov000_021a8fc0(s32);
 s32 func_ov000_021a98a8(s32);
 void *base;
 s32 id;
 if (func_ov000_021a9860(arg0,arg1) == 0) return 0;
 base = *data_027e0058;
 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 if (id == 0) return 1;
 if (func_ov000_021a8fc0((s16)id) == 0) return 0;
 return func_ov000_021a98a8(((u32)(M2C_FIELD(*data_027e0058 + id * 14, u8 *, 0x59A4) << 26) >> 26)) == 0;
}

u8 func_ov000_0217ac78(s32 arg0, s32 arg1) {
    extern void **data_027e0058;
    u8 temp_r2;
    u8 var_r0;
    void *temp_r3;

    temp_r3 = *data_027e0058;
    temp_r2 = M2C_FIELD((temp_r3 + (arg0 + M2C_FIELD((temp_r3 + (arg1 * 2)), u16 *, 0x3758))), u8 *, 0x1420);
    if ((temp_r2 & 0x1F) != 0x11) {
        return 0U;
    }
    if (M2C_FIELD(temp_r3, u16 *, 0x52A6) == (temp_r2 & 0xE0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}
