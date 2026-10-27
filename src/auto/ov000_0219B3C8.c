/* 2 functions from 0x0219B3C8 to 0x0219B848 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_0219b648(s32 arg0,s32 arg1) {
 void func_01ffb554(void *); void func_01ffada0(s32,s32,s32,s32,s32);void func_01ffb9c4(s32);
 s32 func_ov000_021a9934(s32,s32); s32 ManhattanDistance(s16,s16,s16,s16);
 extern u8 data_ov000_021e0f60[],data_ov000_021b5bfc[],data_0212616c[];
 extern u16 data_ov000_021aeef4[];
 extern void **gCurrentMap;
 s32 x=arg0,y=arg1; u16 best=0; s16 result=0; s32 i; void *map; s8 *costs;
 func_01ffb554(data_ov000_021e0f60);
 map=*gCurrentMap;
 costs=M2C_FIELD(data_0212616c,s8 **,0x64)+data_ov000_021b5bfc[0x82]*32;
 func_01ffada0(x,y,1,3-costs[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,0x3758)),u8 *,0x1420)&31],1);
 func_01ffb9c4(0x6f);
 func_01ffb554((u8 *)*gCurrentMap+0x1e30);
 for(i=data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
 u8 *unit=(u8 *)*gCurrentMap+0x59a4+i*14;
 u32 kind=(u32)(unit[0]<<26)>>26;
 if(kind==0)continue;
 if(!func_ov000_021a9934(19,kind))continue;
 if(((u32)(unit[11]<<28)>>28)!=0)continue;
 if(((s8 *)data_ov000_021e0f60)[unit[2]*M2C_FIELD(*gCurrentMap,u16 *,0x5144)+unit[1]]<0)continue;
 if(((u32)(unit[0]<<26)>>26)==2 && ManhattanDistance(x,y,unit[1],unit[2])>2)continue;
 if(best>ManhattanDistance(x,y,unit[1],unit[2]))continue;
 best=ManhattanDistance(x,y,unit[1],unit[2]);result=i;
 }return result;
}
