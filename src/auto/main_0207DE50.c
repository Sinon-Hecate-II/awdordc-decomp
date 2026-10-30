/* 7 functions from 0x0207DE50 to 0x0207E52C (main), found by ds-decomp. */
#include "common.h"
typedef struct { s16 coords[12]; } TerrainCoords24;
extern const s16 data_020ebe58[12];
extern void **gCurrentMap;
extern u16 *data_02101884[2];
extern const u32 data_020edebc[];
extern u16 data_02101ac4[256];
extern u16 data_020ebfbc[64];
extern u16 data_020ec0bc[256];
extern u16 data_020ebebc[64];
extern u16 data_020ec03c[64];
extern u16 data_020ebf3c[64];

#pragma opt_common_subs off
s32 func_0207de50(s32 arg0, s32 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

#pragma opt_common_subs on
u16 func_0207e150(s32 x,s32 y) { TerrainCoords24 first, second, base; s32 j; u8 b,a=0;
base = *(const TerrainCoords24 *)data_020ebe58;
first = base;
{s32 i; s16 *p=first.coords; for(i=0;i<4;i++,p+=3) { s32 nx,ny; nx=x+p[0]; ny=y+p[1]; if(nx>=0 && ny>=0 && nx<M2C_FIELD(*gCurrentMap,u16 *,0x5144) && ny<M2C_FIELD(*gCurrentMap,u16 *,0x5146)) { u16 off=M2C_FIELD((u8 *)*gCurrentMap+ny*2,u16 *,0x3758); u16 tile=M2C_FIELD((u8 *)*gCurrentMap+(nx+off)*2,u16 *,0xa10); if(((const u32 (*)[2])data_020edebc)[data_02101884[1][tile]][0]&0x90000) a |= 1<<i; } }}
b=0;
second = base;
{ s16 *p=second.coords; for(j=0;j<4;j++,p+=3) { s32 nx,ny; nx=x+p[0]; ny=y+p[1]; if(nx>=0 && ny>=0 && nx<M2C_FIELD(*gCurrentMap,u16 *,0x5144) && ny<M2C_FIELD(*gCurrentMap,u16 *,0x5146)) { u16 off=M2C_FIELD((u8 *)*gCurrentMap+ny*2,u16 *,0x3758); u16 tile=M2C_FIELD((u8 *)*gCurrentMap+(nx+off)*2,u16 *,0xa10); if(((const u32 (*)[2])data_020edebc)[data_02101884[1][tile]][0]&0x40000) b |= 1<<j; } }}
return data_02101ac4[a+(b<<4)]; }
#pragma opt_common_subs reset
u16 func_0207e338(s32 x,s32 y) { u16 table[256]; u32 count; u16 *dst; const u16 *src; src=data_020ec0bc; dst=table; count=128; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 28) >> 23) + ((u32)(x << 28) >> 27)) + 1; }

u16 func_0207e39c(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebebc; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 7; }

u16 func_0207e400(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ec03c; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 53; }

u16 func_0207e464(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebf3c; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 220; }

u16 func_0207e4c8(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebfbc; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 224; }

extern u16 data_020ebfbc[64];
