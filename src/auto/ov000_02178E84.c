/* 5 functions from 0x02178E84 to 0x02179E48 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_02179b08(void *arg0) {
s32 func_ov000_021a89a4(void *);s32 func_ov000_021a98a8(u32);
extern u8 data_ov000_021b5c0f[];extern void *data_ov000_021df57c;extern void *data_ov000_021df580;
s32 value;s32 scale;u32 id;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,10)<<26)>>29)&4))return 110;
id=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;if(!(data_ov000_021b5c0f[id*0x70]&7))return 110;
if((u32)(M2C_FIELD(arg0,u8 *,11)<<24)>>31)return 110;
if(func_ov000_021a98a8(id)&&M2C_FIELD(data_ov000_021df580,u8 *,5)<4U)value=4;else value=func_ov000_021a89a4(arg0);
if(((u32)(M2C_FIELD(arg0,u8 *,11)<<27)>>31)!=0)scale=M2C_FIELD(data_ov000_021df57c,u8 *,15);else scale=M2C_FIELD(data_ov000_021df57c,u8 *,14);
value*=scale;if(value>110)value=110;return value;
}

s32 func_ov000_02179ce4(u8 *arg0) {
    s32 func_ov000_02179be0(u8 *, void *, u32);
    extern void **data_027e0058;
    s32 result;
    u32 value;
    u8 *saved;
    void *base;
    base = (u8 *)*data_027e0058 + 0x5000;
    saved = M2C_FIELD(base, u8 **, 0x2D0);
    value = (u32)(*arg0 << 26) >> 26;
    if (value == 0) return 0x6E;
    M2C_FIELD(base, u8 **, 0x2D0) = arg0;
    result = (func_ov000_02179be0(arg0, base, value) * 3) >> 2;
    M2C_FIELD(*data_027e0058, u8 **, 0x52D0) = saved;
    return result;
}
