/* 4 functions from 0x020D6E0C to 0x020D7BC8 (main), found by ds-decomp. */
#include "common.h"
static inline s32 Tile6e0c(s32 tile, s32 offset) {
extern void *gCur3DSpriteEngine;
return (((tile >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((offset >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023);
}
static inline void Draw6e0c(s32 x,s32 y,s32 tile,s32 offset,void *data) {
void func_01ffaacc(u16,u16,u16,void *,s32);
func_01ffaacc((u16)x,(u16)y,(u16)Tile6e0c(tile,offset),data,10);
}
static inline void DrawSecond7944(u16 x,u16 y) { extern void *gCur3DSpriteEngine;extern M2C_UNK data_027e0064;void func_01ffaacc(u16,u16,u16,void *,s32);func_01ffaacc(x,y,(u16)(((1023&(0x150>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))|0x9000)+(1023&(0x60>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),&data_027e0064,10); }
static inline s32 SpriteTile7944(s32 tile) { extern void *gCur3DSpriteEngine;return (tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023; }
typedef struct { s32 v[2][2]; } OffsetTable;
extern OffsetTable data_020f4e98;
extern s32 *gCurrentMap;
void func_020d7944(s32, s32, s32, s32);

#pragma push
#pragma opt_strength_reduction off
void func_020d6e0c(s32 x,s32 y,s32 unused,s32 mode) {
void func_01ffaacc(u16,u16,u16,void *,s32);
extern void *gCur3DSpriteEngine;
extern M2C_UNK data_02101f0c;
extern M2C_UNK data_02101f1c;
extern M2C_UNK data_027e0064;
extern M2C_UNK data_027e006c;
extern M2C_UNK data_027e0074;
extern M2C_UNK data_027e0084;
extern M2C_UNK data_027e009c;
extern M2C_UNK data_027e00a4;
extern M2C_UNK data_027e00b4;
s32 y0,x0,x1,x2,y1;
if(mode==0) {
y0=((y+24)&255)+0x400;x0=x&511;
func_01ffaacc((u16)x0,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_02101f1c,10);
x1=(x+64)&511;func_01ffaacc((u16)x1,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e0064,10);
x2=(x+80)&511;func_01ffaacc((u16)x2,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e006c,10);
y1=((y+40)&255)+0x400;func_01ffaacc((u16)x0,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_02101f0c,10);
func_01ffaacc((u16)x1,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e00a4,10);
func_01ffaacc((u16)x2,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e0084,10);
} else {
y0=(y&255)+0x400;x0=x&511;
func_01ffaacc((u16)x0,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e00b4,10);
x1=(x+64)&511;func_01ffaacc((u16)x1,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e0074,10);
x2=(x+80)&511;func_01ffaacc((u16)x2,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e009c,10);
y1=((y+32)&255)+0x400;func_01ffaacc((u16)x0,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_02101f1c,10);
func_01ffaacc((u16)x1,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e0064,10);
func_01ffaacc((u16)x2,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_027e006c,10);
}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=(*p & ~0xc0)|0x40;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=8;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=8;
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~1;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~2;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~4;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~8;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~16;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x100;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x200;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x400;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x800;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x1000;}
}
#pragma pop
void func_020d759c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    (void) arg0; (void) arg1; (void) arg2;
}

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
yy+=0x400;
{
u32 a=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0);
u32 b=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0);
s32 t=(0x150 >> ((a<<17)>>30))&1023;
s32 t2=(0x60 >> ((b<<17)>>30))&1023;
func_01ffaacc((u16)xx,(u16)yy,(u16)((t|0x9000)+t2),&data_027e0064,10);
}
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
static inline s32 SecondTile7944(void) {
extern void *gCur3DSpriteEngine;
u32 b,a;
a=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0);
b=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0);
return (((0x150 >> ((a<<17)>>30))&1023)|0x9000)+((0x60 >> ((b<<17)>>30))&1023);
}
