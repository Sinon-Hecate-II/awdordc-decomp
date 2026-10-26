/* 7 functions from 0x0207DE50 to 0x0207E52C (main), found by ds-decomp. */
#include "common.h"
extern u16 data_020ebfbc[64];
extern u16 data_020ec0bc[256];
extern u16 data_020ebebc[64];
extern u16 data_020ec03c[64];
extern u16 data_020ebf3c[64];

u16 func_0207e338(s32 x,s32 y) { u16 table[256]; u32 count; u16 *dst; const u16 *src; src=data_020ec0bc; dst=table; count=128; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 28) >> 23) + ((u32)(x << 28) >> 27)) + 1; }

u16 func_0207e39c(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebebc; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 7; }

u16 func_0207e400(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ec03c; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 53; }

u16 func_0207e464(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebf3c; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 220; }

u16 func_0207e4c8(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebfbc; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 224; }

extern u16 data_020ebfbc[64];
