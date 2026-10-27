/* 4 functions from 0x020D6E0C to 0x020D7BC8 (main), found by ds-decomp. */
#include "common.h"
static inline void DrawSecond7944(u16 x,u16 y) { extern void *gCur3DSpriteEngine;extern M2C_UNK data_027e0064;void func_01ffaacc(u16,u16,u16,void *,s32);func_01ffaacc(x,y,(u16)(((1023&(0x150>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))|0x9000)+(1023&(0x60>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),&data_027e0064,10); }
static inline s32 SpriteTile7944(s32 tile) { extern void *gCur3DSpriteEngine;return (tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023; }
typedef struct { s32 v[2][2]; } OffsetTable;
extern OffsetTable data_020f4e98;
extern s32 *gCurrentMap;
void func_020d7944(s32, s32, s32, s32);

#pragma opt_common_subs off
void func_020d7944(s32 x,s32 y,s32 index,s32 unit){
s32 func_ov000_0216ccf0(s32);s32 func_ov000_0216cd00(s32);s32 func_ov000_0216cd78(s32,u8);
void func_0207c3dc(s32,s32,s32,s32);void func_01ffaacc(u16,u16,u16,void *,s32);void func_020d694c(s32,u8,s32);
extern void *gCur3DSpriteEngine;extern M2C_UNK data_027e0064;
s32 kind=func_ov000_0216ccf0(unit);s32 slot,color,health,tile;s32 yy,xx;
if(unit==0)slot=0;else slot=(unit-(*gCurrentMap+0x59a4))/14;
color=M2C_FIELD(*gCurrentMap+((slot>>6)+1)*140,u8 *,0x67cd);
health=func_ov000_0216cd00(unit);tile=(index+1)*4+0x218;
func_0207c3dc(func_ov000_0216cd78(kind,color),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+(tile<<5),128,0);
yy=y&255;xx=x&511;
func_01ffaacc((u16)xx,(u16)yy,(u16)((1023&(tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x8000),&data_027e0064,9);
DrawSecond7944((u16)xx,(u16)(yy+0x400));
if(health==10)return;
func_020d694c((x+8)&511,(y+8)&255,health);
}
#pragma opt_common_subs reset
void func_020d7b04(s32 x, s32 y, s32 kind, void *p) {
OffsetTable offsets = data_020f4e98; s32 n = 0; u32 v;
v = ((u8 *)p)[12];
if (v) { func_020d7944(x + offsets.v[kind][0], y-16, n, *gCurrentMap + 0x59a4 + v*14); n++; }
v = ((u8 *)p)[13];
if (!v) return;
func_020d7944(x + offsets.v[kind][n], y-16, n, *gCurrentMap + 0x59a4 + v*14);
}

