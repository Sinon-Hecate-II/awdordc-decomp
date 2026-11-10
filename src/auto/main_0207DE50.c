/* 7 functions from 0x0207DE50 to 0x0207E52C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { s16 coords[12]; } TerrainCoords24;
extern const s16 gTerrainNeighborOffsets[12];
extern void **gCurrentMap;
extern u16 *gTerrainTileset[2];
extern const u32 gTerrainClassFlags[];
extern u16 gTerrainDualVariantTable[256];
extern u16 data_020ebfbc[64];
extern u16 data_020ec0bc[256];
extern u16 data_020ebebc[64];
extern u16 data_020ec03c[64];
extern u16 data_020ebf3c[64];

#pragma opt_common_subs on
/* 4-neighbour autotile variant for the 0x109 terrain family: collects which
 * orthogonal neighbours carry the 0xA0000 class flag while dropping the ones that
 * also carry 0x40000, fixes up sides that fall off the map edge and returns
 * 0x109 + the resulting 4-bit mask. */
u16 GetTerrainEdgeVariant(s32 x, s32 y) {
    TerrainCoords24 neighborB, neighborA, neighborBase;
    s32 i;
    u8 mask = 0, blocked;

    neighborBase = *(const TerrainCoords24 *)gTerrainNeighborOffsets;
    neighborA = neighborBase;
    {
        s16 *p = neighborA.coords;
        for (i = 0; i < 4; i++, p += 3) {
            s32 nx, ny;
            nx = x + p[0];
            ny = y + p[1];
            if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && ny < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT)) {
                u16 rowOffset = M2C_FIELD((u8 *)*gCurrentMap + ny * 2, u16 *, MAP_ROW_OFFSETS);
                u16 tileId = M2C_FIELD((u8 *)*gCurrentMap + (nx + rowOffset) * 2, u16 *, MAP_CELL_TILE_ID);
                if (((const u32 (*)[2])gTerrainClassFlags)[gTerrainTileset[1][tileId]][0] & 0xa0000) mask |= 1 << i;
            }
        }
    }
    blocked = 0;
    neighborB = neighborBase;
    {
        s32 j;
        s16 *p = neighborB.coords;
        for (j = 0; j < 4; j++, p += 3) {
            s32 nx, ny;
            nx = x + p[0];
            ny = y + p[1];
            if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && ny < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT)) {
                u16 rowOffset = M2C_FIELD((u8 *)*gCurrentMap + ny * 2, u16 *, MAP_ROW_OFFSETS);
                u16 tileId = M2C_FIELD((u8 *)*gCurrentMap + (nx + rowOffset) * 2, u16 *, MAP_CELL_TILE_ID);
                if (((const u32 (*)[2])gTerrainClassFlags)[gTerrainTileset[1][tileId]][0] & 0x40000) blocked |= 1 << j;
            }
        }
    }
    mask &= (blocked ^ -1);
    switch (mask) {
    case 1:
        if (!(x >= 0 && (y + 1) >= 0 && (x) < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && (y + 1) < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT))) mask |= 8;
        break;
    case 2:
        if (!((x + 1) >= 0 && (y) >= 0 && (x + 1) < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && (y) < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT))) mask |= 4;
        break;
    case 4:
        if (!((x - 1) >= 0 && (y) >= 0 && (x - 1) < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && (y) < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT))) mask |= 2;
        break;
    case 8:
        if (!(x >= 0 && (y - 1) >= 0 && (x) < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && (y - 1) < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT))) mask |= 1;
        break;
    }
    return mask + 0x109;
}
/* 4-neighbour autotile variant for the 0xE3 terrain family: builds a mask of the
   orthogonal neighbours carrying the 0x90000 class flag and one of those
   carrying 0x40000, then returns the tile from the 16x16 variant table. */
u16 GetTerrainDualVariant(s32 x, s32 y) {
    TerrainCoords24 neighborA, neighborB, neighborBase;
    s32 j;
    u8 maskB, maskA = 0;

    neighborBase = *(const TerrainCoords24 *)gTerrainNeighborOffsets;
    neighborA = neighborBase;
    {
        s32 i;
        s16 *p = neighborA.coords;
        for (i = 0; i < 4; i++, p += 3) {
            s32 nx, ny;
            nx = x + p[0];
            ny = y + p[1];
            if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && ny < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT)) {
                u16 rowOffset = M2C_FIELD((u8 *)*gCurrentMap + ny * 2, u16 *, MAP_ROW_OFFSETS);
                u16 tileId = M2C_FIELD((u8 *)*gCurrentMap + (nx + rowOffset) * 2, u16 *, MAP_CELL_TILE_ID);
                if (((const u32 (*)[2])gTerrainClassFlags)[gTerrainTileset[1][tileId]][0] & 0x90000) maskA |= 1 << i;
            }
        }
    }
    maskB = 0;
    neighborB = neighborBase;
    {
        s16 *p = neighborB.coords;
        for (j = 0; j < 4; j++, p += 3) {
            s32 nx, ny;
            nx = x + p[0];
            ny = y + p[1];
            if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) && ny < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT)) {
                u16 rowOffset = M2C_FIELD((u8 *)*gCurrentMap + ny * 2, u16 *, MAP_ROW_OFFSETS);
                u16 tileId = M2C_FIELD((u8 *)*gCurrentMap + (nx + rowOffset) * 2, u16 *, MAP_CELL_TILE_ID);
                if (((const u32 (*)[2])gTerrainClassFlags)[gTerrainTileset[1][tileId]][0] & 0x40000) maskB |= 1 << j;
            }
        }
    }
    return gTerrainDualVariantTable[maskA + (maskB << 4)];
}
#pragma opt_common_subs reset
u16 func_0207e338(s32 x,s32 y) { u16 table[256]; u32 count; u16 *dst; const u16 *src; src=data_020ec0bc; dst=table; count=128; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 28) >> 23) + ((u32)(x << 28) >> 27)) + 1; }

u16 func_0207e39c(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebebc; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 7; }

u16 func_0207e400(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ec03c; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 53; }

u16 func_0207e464(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebf3c; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 220; }

u16 func_0207e4c8(s32 x,s32 y) { u16 table[64]; u32 count; u16 *dst; const u16 *src; src=data_020ebfbc; dst=table; count=32; do { u16 a=src[0]; u16 b=src[1]; src+=2; dst[0]=a; dst[1]=b; dst+=2; count-=1; } while(count != 0); return *(u16 *)((u8 *)table + ((u32)(y << 29) >> 25) + ((u32)(x << 29) >> 28)) + 224; }

extern u16 data_020ebfbc[64];
