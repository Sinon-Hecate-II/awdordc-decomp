/* 17 functions from 0x02076698 to 0x02077624 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 values[128]; } ColorTable;
extern const ColorTable data_020eb2e0, data_020eb360, data_020eb3e0, data_020eb460;

void func_02076698(u8 *table,u32 poly){u32 v,i,j;
for(i=0;i<256;i++){v=i;for(j=0;j<8;j++){if(v&128)v=(v<<1)^poly;else v<<=1;}table[i]=v;}
}

s32 func_020766d8(s32 table,u8 *crc,s32 data,s32 size){u32 v,i;u8 *p=(u8*)data;v=*crc;
for(i=0;i<(u32)size;i++)v=((u8*)table)[(u8)(v^*p++)];*crc=v;
}

void func_02076710(u16 *table,u32 poly){u32 v,j,i;
for(i=0;i<256;i++){v=i;for(j=0;j<8;j++){if(v&1)v=(v>>1)^poly;else v>>=1;}table[i]=v;}
}

s32 func_02076754(s32 table,u16 *state,s32 data,s32 size) {
 u32 crc=*state; u32 i; u8 *p=(u8 *)data;
 for(i=0;i<(u32)size;i++) crc=M2C_FIELD(table,u16 *, ((crc ^ *p++) << 24) >> 23) ^ (crc >> 8);
 *state=crc;
}

void func_02076794(u32 *table,u32 poly) {
 u32 crc; u32 i; u32 j; u32 zero;
 i=0; zero=0;
 do { crc=i; j=zero;
 do { if(crc&1) crc=poly^(crc>>1); else crc>>=1; j++; }while(j<8);
 table[i]=crc; i++;
 }while(i<256);
}

s32 func_020767d4(s32 table,s32 *state,s32 data,s32 size) {
 u32 crc=*state; u32 i; u8 *p=(u8 *)data;
 for(i=0;i<(u32)size;i++) crc=((u32 *)table)[(u8)(crc ^ *p++)] ^ (crc >> 8);
 *state=crc;
}

u8 func_02076810(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020766d8(M2C_UNK, u8 *, M2C_UNK, M2C_UNK);
    u8 sp0;

    sp0 = 0;
    func_020766d8(arg0, &sp0, arg1, arg2);
    return sp0;
}

u16 Crc16Block(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02076754(M2C_UNK, u16 *, M2C_UNK, M2C_UNK);
    u16 sp0;

    sp0 = 0;
    func_02076754(arg0, &sp0, arg1, arg2);
    return sp0;
}

s32 func_02076860(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020767d4(M2C_UNK, s32 *, M2C_UNK, M2C_UNK);
    s32 sp0;

    sp0 = -1;
    func_020767d4(arg0, &sp0, arg1, arg2);
    return ~sp0;
}

/* Clears the map view's render caches: the per-cell corner colour codes, the
 * cell display, shade and move-range buffers, and the two cell corner-variant
 * buffers. */
void ClearMapRenderBuffers(void) {
    M2C_UNK MI_CpuFill32(M2C_UNK, M2C_UNK *, s32);
    extern M2C_UNK gMapMoveRangeFlags;
    extern M2C_UNK gMapCellShades;
    extern M2C_UNK gMapCellCodes;
    extern M2C_UNK gMapCellCornerColors;
    extern M2C_UNK gMapCellCornerA;
    extern M2C_UNK gMapCellCornerB;
    MI_CpuFill32(0, &gMapCellCornerColors, 0x834);
    MI_CpuFill32(0, &gMapCellCodes, 0x900);
    MI_CpuFill32(0, &gMapCellShades, 0x900);
    MI_CpuFill32(0, &gMapMoveRangeFlags, 0x900);
    MI_CpuFill32(0, &gMapCellCornerA, 0x1200);
    MI_CpuFill32(0, &gMapCellCornerB, 0x1200);
}

#pragma opt_propagation off
void func_02076910(s32 x,s32 y) {
 extern void *gCurrentMap;
 extern M2C_UNK gMapCellCornerColors;
 void *p;
 s32 a,b;
 s32 v;
 if(x<0 || y<0) return;
 p=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x5120;
 if(x>=M2C_FIELD(p,u16 *,0x24) || y>=M2C_FIELD(p,u16 *,0x26)) return;
 v=7;
 a=(s32)&gMapCellCornerColors+x*42;
 b=(s32)&gMapCellCornerColors+(x+1)*42;
 M2C_FIELD(y+0,u8 *,a)=v;
 M2C_FIELD(y+0,u8 *,b)=v;
 M2C_FIELD(y+1,u8 *,a)=v;
 M2C_FIELD(y+1,u8 *,b)=v;
}
#pragma opt_strength_reduction off
#pragma opt_propagation off
extern void *gCurrentMap;

static inline s32 OverlayTerrainIs(s32 x, s32 y, s32 terrain)
{
    u8 *map;
    u8 *dimensions;
    s32 index;

    if (x >= 0 && y >= 0) {
        map = M2C_FIELD(gCurrentMap, u8 **, 0);
        dimensions = map + 0x5120;
        if (x < M2C_FIELD(dimensions, u16 *, 0x24) &&
            y < M2C_FIELD(dimensions, u16 *, 0x26)) {
            index = x + M2C_FIELD(map + y * 2, u16 *, 0x3758);
            if (M2C_FIELD(map + index, u8 *, 0x1420) == terrain)
                return 1;
        }
    }
    return 0;
}

static inline s32 OverlayTerrainDiffers(s32 x, s32 y, s32 terrain)
{
    u8 *map;
    u8 *dimensions;
    s32 index;

    if (x >= 0 && y >= 0) {
        map = M2C_FIELD(gCurrentMap, u8 **, 0);
        dimensions = map + 0x5120;
        if (x < M2C_FIELD(dimensions, u16 *, 0x24) &&
            y < M2C_FIELD(dimensions, u16 *, 0x26)) {
            index = x + M2C_FIELD(map + y * 2, u16 *, 0x3758);
            if (M2C_FIELD(map + index, u8 *, 0x1420) != terrain)
                return 1;
        }
    }
    return 0;
}

static inline s32 OverlayTopDiffers(u8 *map, s32 x, s32 y, s32 width, s32 height, s32 row, s32 terrain)
{
    if (x >= 0 && y >= 0 && x < width && y < height) {
        if (M2C_FIELD(map + (x + row), u8 *, 0x1420) != terrain)
            return 1;
    }
    return 0;
}

#pragma opt_lifetimes off
#pragma opt_common_subs off
void func_02076980(s32 x0, s32 y, s32 x1, s32 y1)
{
    extern M2C_UNK gMapCellCornerColors;
    u8 *dimensions = M2C_FIELD(gCurrentMap, u8 **, 0) + 0x5120;
    s32 width = M2C_FIELD(dimensions, u16 *, 0x24);
    s32 height = M2C_FIELD(dimensions, u16 *, 0x26);
    s32 x, code, top, maxX;
    u8 *overlay;

    if (x0 < 0)
        x0 = 0;
    if (y < 0)
        y = 0;
    if (x1 > width - 1)
        x1 = width - 1;
    if (y1 > height - 1)
        y1 = height - 1;

    goto check_y;
    next_y:
        x = x0;
        top = y - 1;
        maxX = x1 + 1;
        overlay = (u8 *)&gMapCellCornerColors;
        goto check_x;
    next_x: {
            if (M2C_FIELD(y, u8 *, (s32)overlay + x * 42) == 7)
                goto advance_x;
            {
                s32 left = x - 1;
                if (left >= 0 && top >= 0) {
                    u8 *map = M2C_FIELD(gCurrentMap, u8 **, 0);
                    u8 *size = map + 0x5120;
                    s32 mapWidth = M2C_FIELD(size, u16 *, 0x24);
                    s32 mapHeight;
                    if (left < mapWidth && top < (mapHeight = M2C_FIELD(size, u16 *, 0x26))) {
                        s32 row = M2C_FIELD(map + top * 2, u16 *, 0x3758);
                        s32 tile = M2C_FIELD(map + (left + row), u8 *, 0x1420);
                        if (tile == 4) {
                            if (OverlayTopDiffers(map, x, top, mapWidth, mapHeight, row, 4))
                                code = 3;
                            else if (OverlayTerrainDiffers(x - 1, y, 4))
                                code = 3;
                            else
                                code = OverlayTerrainDiffers(x, y, 4) ? 3 : 1;
                            goto store_overlay;
                        }
                        if (tile == 29) {
                            if (OverlayTopDiffers(map, x, top, mapWidth, mapHeight, row, 29))
                                code = 3;
                            else if (OverlayTerrainDiffers(x - 1, y, 29))
                                code = 3;
                            else
                                code = OverlayTerrainDiffers(x, y, 29) ? 3 : 1;
                            goto store_overlay;
                        }
                    }
                }
            }
            if (OverlayTerrainIs(x - 1, top, 3) &&
                       OverlayTerrainDiffers(x, top, 8) &&
                       OverlayTerrainDiffers(x - 1, y, 8) &&
                       OverlayTerrainDiffers(x, y, 8)) {
                code = 2;
            } else if (OverlayTerrainIs(x, top, 3) &&
                       OverlayTerrainDiffers(x - 1, top, 8) &&
                       OverlayTerrainDiffers(x - 1, y, 8) &&
                       OverlayTerrainDiffers(x, y, 8)) {
                code = 2;
            } else if (OverlayTerrainIs(x - 1, y, 3) &&
                       OverlayTerrainDiffers(x, top, 8) &&
                       OverlayTerrainDiffers(x - 1, top, 8) &&
                       OverlayTerrainDiffers(x, y, 8)) {
                code = 2;
            } else if (OverlayTerrainIs(x, y, 3) &&
                       OverlayTerrainDiffers(x, top, 8) &&
                       OverlayTerrainDiffers(x - 1, y, 8) &&
                       OverlayTerrainDiffers(x - 1, top, 8)) {
                code = 2;
            } else if (!OverlayTerrainDiffers(x, y, 8)) {
                if (OverlayTerrainDiffers(x - 1, top, 8))
                    code = 0;
                else if (OverlayTerrainDiffers(x, top, 8))
                    code = 0;
                else
                    code = OverlayTerrainDiffers(x - 1, y, 8) ? 0 : 4;
                goto store_overlay;
            } else {
                code = 0;
            }
        store_overlay:
            M2C_FIELD(y, u8 *, (s32)overlay + x * 42) = code;
        }
    advance_x:
        x++;
    check_x:
        if (x <= maxX)
            goto next_x;
        y++;
    check_y:
        if (y <= y1 + 1)
            goto next_y;
}
#pragma opt_common_subs reset
#pragma opt_lifetimes reset
void func_02077480(void){extern M2C_UNK gMapHighlightState;
if(M2C_FIELD(&gMapHighlightState,s32*,12)==0)M2C_FIELD(&gMapHighlightState,s32*,12)=1;
}

void func_0207749c(void) {
    extern M2C_UNK gMapHighlightState;
    M2C_FIELD(&gMapHighlightState, s32 *, 0xC) = 0;
}

void func_020774b0(void) {
 extern M2C_UNK gMapHighlightState;
 s32 n=M2C_FIELD(&gMapHighlightState,s32 *,12);
 if(n<8) M2C_FIELD(&gMapHighlightState,s32 *,12)=n+1;
}

s32 func_020774cc(void) {
 extern void *gCurrentMap;
 extern M2C_UNK gMapHighlightState;
 if(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),s32 *,0x60)) return M2C_FIELD(&gMapHighlightState,s32 *,12)!=0;
 return 0;
}

void func_0207750c(void) {
 extern s32 gFrameCounter;
 extern M2C_UNK gMapHighlightState;
 ColorTable a=data_020eb2e0;
 ColorTable b=data_020eb360;
 ColorTable c=data_020eb3e0;
 ColorTable d=data_020eb460;
 s32 i=gFrameCounter & 127;
 s32 x=((volatile u8 *)a.values)[i>>1], y=((volatile u8 *)b.values)[i>>1], z=((volatile u8 *)c.values)[i>>1];
 M2C_FIELD(&gMapHighlightState,u16 *,16)=x;
 M2C_FIELD(&gMapHighlightState,u16 *,18)=y;
 M2C_FIELD(&gMapHighlightState,u16 *,20)=c.values[i>>1];
 M2C_FIELD(&gMapHighlightState,u16 *,22)=d.values[i>>1];
}

