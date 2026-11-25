/* 17 functions from 0x02076698 to 0x02077624 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u8 values[128]; } ColorTable;
extern const ColorTable data_020eb2e0, data_020eb360, data_020eb3e0, data_020eb460;

/* Build the CRC-8 lookup table (one entry per input byte, bits fed in from the
 * most significant) that Crc8Update indexes. */
void BuildCrc8Table(u8 *table, u32 polynomial) {
    u32 crc;
    u32 tableIndex;
    u32 bitIndex;

    for (tableIndex = 0; tableIndex < 256; tableIndex++) {
        crc = tableIndex;
        for (bitIndex = 0; bitIndex < 8; bitIndex++) {
            if (crc & 128) crc = (crc << 1) ^ polynomial;
            else crc <<= 1;
        }
        table[tableIndex] = crc;
    }
}

/* Fold `size` bytes at `data` through the CRC-8 lookup table and store the
 * updated checksum back in *state. */
s32 Crc8Update(s32 table, u8 *state, s32 data, s32 size) {
    u32 crc = *state;
    u32 i;
    u8 *bytes = (u8 *)data;

    for (i = 0; i < (u32)size; i++) {
        crc = ((u8 *)table)[(u8)(crc ^ *bytes++)];
    }
    *state = crc;
}

/* Build the reflected CRC-16 lookup table used for save and map-record checksums. */
void BuildCrc16Table(u16 *table, u32 polynomial) {
    u32 crc;
    u32 bitIndex;
    u32 tableIndex;

    for (tableIndex = 0; tableIndex < 256; tableIndex++) {
        crc = tableIndex;
        for (bitIndex = 0; bitIndex < 8; bitIndex++) {
            if (crc & 1)
                crc = (crc >> 1) ^ polynomial;
            else
                crc >>= 1;
        }
        table[tableIndex] = crc;
    }
}

/* Fold `size` bytes at `data` through the reflected CRC-16 lookup table and
 * store the updated checksum back in *state. */
s32 Crc16Update(s32 table, u16 *state, s32 data, s32 size) {
    u32 crc = *state;
    u32 i;
    u8 *bytes = (u8 *)data;

    for (i = 0; i < (u32)size; i++) {
        crc = M2C_FIELD(table, u16 *, ((crc ^ *bytes++) << 24) >> 23) ^ (crc >> 8);
    }
    *state = crc;
}

/* Build the reflected CRC-32 lookup table (one entry per input byte) that
 * Crc32Update indexes with CRC32_POLYNOMIAL. */
void BuildCrc32Table(u32 *table, u32 polynomial) {
    u32 crc;
    u32 tableIndex;
    u32 bitIndex;
    u32 zero;

    tableIndex = 0;
    zero = 0;
    do {
        crc = tableIndex;
        bitIndex = zero;
        do {
            if (crc & 1) crc = polynomial ^ (crc >> 1);
            else crc >>= 1;
            bitIndex++;
        } while (bitIndex < 8);
        table[tableIndex] = crc;
        tableIndex++;
    } while (tableIndex < 256);
}

/* Fold `size` bytes at `data` through the reflected CRC-32 lookup table and
 * store the updated checksum back in *state. */
s32 Crc32Update(s32 table, s32 *state, s32 data, s32 size) {
    u32 crc = *state;
    u32 i;
    u8 *bytes = (u8 *)data;

    for (i = 0; i < (u32)size; i++) {
        crc = ((u32 *)table)[(u8)(crc ^ *bytes++)] ^ (crc >> 8);
    }
    *state = crc;
}

/* CRC-8 of `size` bytes at `data` through the lookup `table`, computed from a
 * zero initial checksum. */
u8 Crc8Block(s32 table, s32 data, s32 size) {
    s32 Crc8Update(s32, u8 *, s32, s32);
    u8 checksum;

    checksum = 0;
    Crc8Update(table, &checksum, data, size);
    return checksum;
}

/* Reflected CRC-16 of `size` bytes at `data` through the lookup `table`,
 * computed from a zero initial checksum. */
u16 Crc16Block(s32 table, s32 data, s32 size) {
    s32 Crc16Update(s32, u16 *, s32, s32);
    u16 checksum;

    checksum = 0;
    Crc16Update(table, &checksum, data, size);
    return checksum;
}

/* CRC-32 of `size` bytes at `data` through `table`, preset to all ones and
 * complemented at the end, as the ZIP/PNG CRC-32. */
s32 Crc32Block(s32 table, s32 data, s32 size) {
    s32 Crc32Update(s32, s32 *, s32, s32);
    s32 crc;

    crc = -1;
    Crc32Update(table, &crc, data, size);
    return ~crc;
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
/* Reserve the corner colours of the 2x2 cell block whose top-left cell is (x,y)
 * for a map effect (a beam or an impact): write the reserved corner code there
 * so the terrain overlay pass leaves those corners alone. */
void PinMapCellCorners(s32 x,s32 y) {
 extern void *gCurrentMap;
 extern M2C_UNK gMapCellCornerColors;
 u8 *dimensions;
 s32 column0,column1;
 s32 code;
 if(x<0 || y<0) return;
 dimensions=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x5120;
 if(x>=M2C_FIELD(dimensions,u16 *,0x24) || y>=M2C_FIELD(dimensions,u16 *,0x26)) return;
 code=MAP_CORNER_COLOR_RESERVED;
 column0=(s32)&gMapCellCornerColors+x*MAP_CORNER_COLOR_STRIDE;
 column1=(s32)&gMapCellCornerColors+(x+1)*MAP_CORNER_COLOR_STRIDE;
 M2C_FIELD(y+0,u8 *,column0)=code;
 M2C_FIELD(y+0,u8 *,column1)=code;
 M2C_FIELD(y+1,u8 *,column0)=code;
 M2C_FIELD(y+1,u8 *,column1)=code;
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

void ResetMapViewRaiseTimer(void) {
    extern M2C_UNK gMapHighlightState;
    M2C_FIELD(&gMapHighlightState, s32 *, 0xC) = 0;
}

void func_020774b0(void) {
 extern M2C_UNK gMapHighlightState;
 s32 n=M2C_FIELD(&gMapHighlightState,s32 *,12);
 if(n<8) M2C_FIELD(&gMapHighlightState,s32 *,12)=n+1;
}

/* True while the map view shows a map order's effect highlight: the view has the
 * highlight enabled and the cells' raise timer has started. */
s32 IsOrderEffectHighlightActive(void) {
    extern void *gCurrentMap;
    extern M2C_UNK gMapHighlightState;

    if (M2C_FIELD(M2C_FIELD(gCurrentMap, void **, MAP_VIEW_PTR), s32 *, MAPVIEW_ORDER_EFFECT))
        return M2C_FIELD(&gMapHighlightState, s32 *, MAP_VIEW_RAISE_TIMER) != 0;
    return 0;
}

void func_0207750c(void) {
 extern s32 data_027e15bc;
 extern M2C_UNK data_02140f70;
 ColorTable a=data_020eb2e0;
 ColorTable b=data_020eb360;
 ColorTable c=data_020eb3e0;
 ColorTable d=data_020eb460;
 s32 i=data_027e15bc & 127;
 s32 x=((volatile u8 *)a.values)[i>>1], y=((volatile u8 *)b.values)[i>>1], z=((volatile u8 *)c.values)[i>>1];
 M2C_FIELD(&data_02140f70,u16 *,16)=x;
 M2C_FIELD(&data_02140f70,u16 *,18)=y;
 M2C_FIELD(&data_02140f70,u16 *,20)=c.values[i>>1];
 M2C_FIELD(&data_02140f70,u16 *,22)=d.values[i>>1];
}

