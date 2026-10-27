/* 4 functions from 0x0217D86C to 0x0217E798 (ov000), found by ds-decomp. */
#include "common.h"

u8 func_ov000_0217e6bc(s32 arg0,s32 arg1){
s32 ManhattanDistance(u8,u8,s16,s16);extern void **gCurrentMap;extern void *data_ov000_021df580;
void *base,*world,*entry;u8 result;
base=(u8 *)*gCurrentMap+0x5000;
if(!M2C_FIELD(base,u8 *,0x2d6))return 1;
base=M2C_FIELD(base,void **,0x2d0);
if(((u32)(M2C_FIELD(base,u8 *,0)<<26)>>26)!=17)return 1;
if(ManhattanDistance(M2C_FIELD(base,u8 *,1),M2C_FIELD(base,u8 *,2),(s16)arg0,(s16)arg1)<=(s32)(M2C_FIELD(data_ov000_021df580,u8 *,5)*2))return 1;
world=*gCurrentMap;entry=(u8 *)world+0x59a4+M2C_FIELD((u8 *)world+0x5000,u8 *,0x2d6)*14;
if(((u32)(M2C_FIELD(entry,u16 *,6)<<25)>>25)<=30)return 1;
if(((u32)(M2C_FIELD(entry,u8 *,10)<<25)>>25)<=10)result=1;else result=0;
return result;
}
