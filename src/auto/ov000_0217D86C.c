/* 4 functions from 0x0217D86C to 0x0217E798 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; u8 x,y; u8 rest[11]; } Unit7DC;

s32 func_ov000_0217dcd0(void){
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
void func_01ffb554(void *);
s32 func_ov000_02179be0(void);
void func_01ffada0(u8,u8,u8,s32,s32);
void func_01ffb9c4(s8);
s32 func_020d1938(s32);
s32 func_020d273c(u16,s32);
u8 *unit;
s32 p,end,i;
u32 kind;
if(((u32)(**(u8 **)((u8 *)*gCurrentMap+0x52d0)<<26)>>26)!=23)return 0;
func_01ffb554((u8 *)*gCurrentMap+0x2338);
unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
func_01ffada0(unit[1],unit[2],((Unit7DC *)unit)->kind,func_ov000_02179be0(),1);
func_01ffb9c4(0x6f);
for(p=1;p<5;p++){
if(!func_020d1938(p))continue;
if(func_020d273c(*(u16 *)((u8 *)*gCurrentMap+0x52a4),p)==1)continue;
i=data_ov000_021aeef4[p]+1;end=data_ov000_021aeef4[p]+0x33;
for(;i<end;i++){
Unit7DC *entry=&((Unit7DC *)((u8 *)*gCurrentMap+0x59a4))[i];
kind=entry->kind;
if(kind && kind==22 && (*(s8 **)((u8 *)*gCurrentMap+0x52e8+entry->y*4))[entry->x]>=0){
func_01ffb554((u8 *)*gCurrentMap+0x1e30);return 1;
}
}}
func_01ffb554((u8 *)*gCurrentMap+0x1e30);return 0;
}

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
