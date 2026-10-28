/* 5 functions from 0x02178E84 to 0x02179E48 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_02178e84(s32 arg0, s32 arg1) {
    return 1;
}

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

s32 func_ov000_02179be0(u8 *arg0,void *arg1,u32 arg2) {
s32 func_ov000_021a98a8(u32);
extern void **gCurrentMap;
extern u8 data_ov000_021b5c0f[];
extern void *data_ov000_021df57c;
extern void *data_ov000_021df580;
s32 value,scale;u32 id;void *p;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,10)<<26)>>29)&4))return 110;
p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
id=(u32)(M2C_FIELD(p,u8 *,0)<<26)>>26;
if(!(data_ov000_021b5c0f[id*0x70]&7))return 110;
if((u32)(M2C_FIELD(p,u8 *,11)<<24)>>31)return 110;
if(func_ov000_021a98a8(id)&&M2C_FIELD(data_ov000_021df580,u8 *,5)<4U)value=4;
else value=M2C_FIELD(data_ov000_021df580,u8 *,5);
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<27)>>31)!=0)scale=M2C_FIELD(data_ov000_021df57c,u8 *,15);
else scale=M2C_FIELD(data_ov000_021df57c,u8 *,14);
value=scale*value;if(value>110)value=110;else value=value;return value;
}

s32 func_ov000_02179ce4(u8 *arg0) {
    s32 func_ov000_02179be0(u8 *, void *, u32);
    extern void **gCurrentMap;
    s32 result;
    u32 value;
    u8 *saved;
    void *base;
    base = (u8 *)*gCurrentMap + 0x5000;
    saved = M2C_FIELD(base, u8 **, 0x2D0);
    value = (u32)(*arg0 << 26) >> 26;
    if (value == 0) return 0x6E;
    M2C_FIELD(base, u8 **, 0x2D0) = arg0;
    result = (func_ov000_02179be0(arg0, base, value) * 3) >> 2;
    M2C_FIELD(*gCurrentMap, u8 **, 0x52D0) = saved;
    return result;
}

void func_ov000_02179d3c(M2C_UNK arg0) {
M2C_UNK func_01ffada0(u8,u8,u32,M2C_UNK,s32);
M2C_UNK func_01ffb9c4(s8);
s32 func_020a76d4(void *);
s32 func_ov000_021a97e0(u16,s32);
s32 func_ov000_021a98e4(void);
extern void **gCurrentMap;
extern u8 data_ov000_021b5c08[];
s32 i,n;void *p,*base;
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
func_01ffada0(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),(u32)(M2C_FIELD(p,u8 *,0)<<26)>>26,arg0,0);
base=*gCurrentMap;
if(((u32)(M2C_FIELD(M2C_FIELD(base,void **,0x52D0),u8 *,0)<<26)>>26)==21)
n=func_ov000_021a97e0(M2C_FIELD(base,u16 *,0x52A4),17)+1;
else if(func_ov000_021a98e4()==1)n=func_020a76d4(M2C_FIELD(*gCurrentMap,void **,0x52D0));
else n=data_ov000_021b5c08[((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u8 *,0)<<26)>>26)*0x70];
i=0;if(n<=0)return;do{func_01ffb9c4((s8)(i+0x6F));i++;}while(i<n);
}

