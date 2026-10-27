/* 3 functions from 0x02190F74 to 0x02191970 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6;u8 flags:2;u8 pad[5];u16 health:7;u16 flags2:4;u16 value:5;u8 tail[6]; } Unit1911;
typedef struct { u8 pad[0x3758];u16 rows[64];u8 pad2[0x196c];u16 width,height;u8 pad3[0x188];Unit1911 *selected;u8 pad4[0x14];s8 *grid[64]; } Map1911;
static inline s32 Health1911(Unit1911 *u) {s32 h=u->health;return h?func_0207c8ec(h-1,10)+1:0;}

void func_ov000_021911bc(void){
#pragma push
#pragma opt_common_subs off
extern void **gCurrentMap;
void func_01ffc328(void *);
s32 func_ov000_021a8fc0(s16);
s32 func_0207c8ec(s32,s32);
void func_ov000_02199d74(s16,s16,s32,s32,s32);
s32 id,x,y,h,cur;Map1911 *map;Unit1911 *unit;
func_01ffc328(M2C_FIELD(*gCurrentMap,void **,0x52d0));
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(map->grid[y][x]<0)continue;
id=((u8 *)map)[x+map->rows[y]];
if(!id)continue;
if(!func_ov000_021a8fc0((s16)id))continue;
map=*gCurrentMap;unit=(Unit1911 *)((u8 *)map+0x59a4)+id;
if(!unit->value)continue;
if(unit->kind!=map->selected->kind)continue;
h=Health1911(unit);
if(h==10)continue;
cur=Health1911(((Map1911 *)*gCurrentMap)->selected);
if(h>=7&&cur>=7)continue;
if(h+cur>15)continue;
func_ov000_02199d74((s16)x,(s16)y,9,0,0);
}
}
#pragma pop
}
