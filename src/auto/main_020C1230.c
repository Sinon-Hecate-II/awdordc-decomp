/* 27 functions from 0x020C1230 to 0x020C1F58 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
extern s32 gOccupationBackgroundNames[];

/* Draw the current map into a map-preview layer: create the layer's preview
 * sprite at its VRAM once (later calls leave it alone), start the per-frame
 * cursor colour animation, then draw the map into tile `tile` with OBJ palette
 * `palette`. */
void DrawMapPreview(s32 layerVram, M2C_UNK layerTiles, s32 tile, M2C_UNK palette) {
    M2C_UNK CreateFrameCallbackTask(M2C_UNK *, M2C_UNK);
    s32 CreateMapPreviewLayerSprite(s32);
    M2C_UNK DrawMapPreviewLayerCore(s32, M2C_UNK, s32, M2C_UNK);
    extern M2C_UNK AnimateMapPreviewCursorColor;
    if (CreateMapPreviewLayerSprite(layerVram + (tile << 5)) == 0) {
        return;
    }
    CreateFrameCallbackTask(&AnimateMapPreviewCursorColor, 1);
    DrawMapPreviewLayerCore(layerVram, layerTiles, tile, palette);
}

/* Take the map view's sprites down: stop the cursor colour animation, then
 * delete the preview layer and the frame-rectangle sprites. */
void RemoveMapViewSprites(void) {
 void DeleteFrameCallbackTask(void (*)(void)); void RemoveMapPreviewLayerSprite(void); void RemoveFrameRectSprites(void); void AnimateMapPreviewCursorColor(void);
 DeleteFrameCallbackTask(AnimateMapPreviewCursorColor); RemoveMapPreviewLayerSprite(); RemoveFrameRectSprites();
}

/* Draw the current map into one VRAM layer of the map preview: refresh the player
 * colour indices, load the preview palette into OBJ palette slot `palette`, copy
 * the layer's tile graphics, then fill its tilemap with those tiles in that
 * palette. */
M2C_UNK DrawMapPreviewLayerCore(s32 layerVram, M2C_UNK layerTilemap, s32 tile, s32 palette) {
    M2C_UNK CopyToObjPaletteShadow(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK RefreshPlayerColorIndices();
    M2C_UNK FillMapPreviewTilemap(M2C_UNK, s32);
    void CopyMapPreviewTiles(M2C_UNK);
    extern M2C_UNK gMapPreviewPalettes;
    extern s32 gMapPreviewPaletteSlot;
    gMapPreviewPaletteSlot = palette;
    RefreshPlayerColorIndices();
    CopyToObjPaletteShadow(&gMapPreviewPalettes, palette << 5, 0x20);
    CopyMapPreviewTiles(layerVram + (tile << 5));
    return FillMapPreviewTilemap(layerTilemap, (tile & 0x3FF) | (u16)(palette << 12));
}

/* Draw the current map into one layer of a 3D sprite map preview: refresh the
 * player colour indices, load the preview palette into OBJ palette slot
 * `palette`, copy the map's tile graphics into the layer's VRAM starting at
 * tile `tile`, and fill the layer's tilemap with those tiles in that palette. */
void DrawMapPreviewLayer(s32 layerVram, M2C_UNK layerTilemap, s32 tile, s32 palette) {
    M2C_UNK CopyToObjPaletteShadow(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK RefreshPlayerColorIndices();
    M2C_UNK FillMapPreviewTilemap(M2C_UNK, s32);
    extern M2C_UNK gMapPreviewPalettes;
    extern s32 gMapPreviewPaletteSlot;
    s32 vramOffset;

    gMapPreviewPaletteSlot = palette;
    RefreshPlayerColorIndices();
    CopyToObjPaletteShadow(&gMapPreviewPalettes, palette << 5, 0x20);
    vramOffset = layerVram + (tile << 5);
    CopyMapPreviewTopHalf(vramOffset);
    CopyMapPreviewBottomHalf(vramOffset);
    FillMapPreviewTilemap(layerTilemap, (tile & 0x3FF) | (u16) (palette << 0xC));
}

/* Per-frame map-preview cursor animation: copy the cursor colour the frame counter
 * selects out of the colour ramp over colour 14 of the OBJ palette slot the preview
 * was drawn with, which marks that engine's palette dirty. */
void AnimateMapPreviewCursorColor(void) {
    M2C_UNK CopyBytesToObjPaletteShadow(void *, s32, M2C_UNK);
    extern s32 gMapPreviewPalettes;
    extern s32 gMapPreviewPaletteSlot;
    extern s32 gFrameCounter;

    CopyBytesToObjPaletteShadow(
        (char *)&gMapPreviewPalettes + MAP_PREVIEW_CURSOR_RAMP + ((u32)(gFrameCounter & 0x3C) >> 1),
        (gMapPreviewPaletteSlot << 5) + MAP_PREVIEW_CURSOR_COLOR * 2,
        2
    );
}

/* Copy a map preview's tile graphics into `dst`: the top half of the rows, then
 * the bottom half. */
void CopyMapPreviewTiles(M2C_UNK dst) {
    M2C_UNK CopyMapPreviewTopHalf();
    M2C_UNK CopyMapPreviewBottomHalf(M2C_UNK);
    CopyMapPreviewTopHalf(dst);
    CopyMapPreviewBottomHalf(dst);
}

/* Fills a map-preview tilemap with consecutive tile ids starting at firstTile:
 * the preview is 32 entries per row, using (map width + 1) / 2 entries for each
 * of the (map height + 1) / 2 rows that make up the preview. */
M2C_UNK FillMapPreviewTilemap(M2C_UNK tilemap,s32 firstTile) {
 extern void **gCurrentMap;
 s32 index=0,y=index,x,row;
 void *base=*gCurrentMap;
 s32 height=M2C_FIELD(base,volatile u16 *,MAP_HEIGHT);
 s32 width=M2C_FIELD(base,volatile u16 *,MAP_WIDTH);
 width++;
 height=(((height+1)&~1)>>1)<<4;
 width&=~1;
 if(height<=0) return;
 row=0;
 width>>=1;
 do {
 for(x=0;x<width;x++) { ((u16 *)tilemap)[row+x]=firstTile+index++; }
 y+=16; row+=32;
 } while(y<height);
}

/* Stamp a colour marker for every visible unit onto the map-preview tile buffer. */
void DrawMapUnitMarkers(u16 *dst) {
    s32 IsUnitVisible(void*);
    extern void **gCurrentMap;
    extern u16 gPreviewTileGfx[],gUnitMarkerMasks[],gPreviewColumnOffset[],gTileGfxRowOffset[],gPreviewRowOffset[];
    extern u8 gPlayerColorIndex[];
    s32 i,owner,x,y;
    u8 *unit;
    u16 *out,*src;
    u32 kind;
    for(i=1;i<256;i++){
        unit=(u8*)*gCurrentMap+MAP_UNIT_RECORDS+i*MAP_UNIT_STRIDE;
        kind=(u32)(unit[0]<<26)>>26;
        if(kind && IsUnitVisible(unit)){
            x=unit[MAP_UNIT_X];y=unit[MAP_UNIT_Y];
            if(unit){if(unit) owner=(s32)(unit-((u8*)*gCurrentMap+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;else owner=0;owner=(owner>>6)+1;}else owner=0;
            src=gPreviewTileGfx+gTileGfxRowOffset[MAP_PREVIEW_UNIT_TILE_BASE+gPlayerColorIndex[owner]];
            out=dst+gPreviewColumnOffset[x]+gPreviewRowOffset[y];
            out[0]&=gUnitMarkerMasks[0];out[2]&=gUnitMarkerMasks[1];out[4]&=gUnitMarkerMasks[2];out[6]&=gUnitMarkerMasks[3];
            out[0]|=src[0];out[2]|=src[2];out[4]|=src[4];out[6]|=src[6];
        }
    }
}

#pragma opt_global_reg off
M2C_UNK CopyMapPreviewTopHalf(s32 arg){
u32 IsBattleEndSpritePresent(void);u16 *func_020c10a4(s32,s32,s32);
extern void **gCurrentMap;extern u16 gPreviewColumnOffset[],gPreviewRowOffset[];
s32 a[2],b[2],half,w,h,mode,x,y,sum; u8 *map; s32 width,height;u16 *src,*out; s32 index;u16 *dst=(u16 *)arg;
mode=IsBattleEndSpritePresent();
map=*gCurrentMap;
width=M2C_FIELD(map,u16 *,0x5144);
height=M2C_FIELD(map,u16 *,0x5146);
w=(width+1)&~1;
h=(height+1)&~1;
half=h>>1;
a[0]=1;a[1]=15;b[0]=8;b[1]=w*8-8;
{s32 i=0,s=0;for(;i<w;i++){gPreviewColumnOffset[i]=s;s+=a[i&1];}}
{s32 s=0,j=0;for(;j<h;j++){gPreviewRowOffset[j]=s;s+=b[j&1];}}
for(y=0;y<half;y++)for(x=0;x<w;x++){
src=func_020c10a4(x,y,mode);
index=gPreviewRowOffset[y];
out=dst+gPreviewColumnOffset[x]+index;
out[0]=src[0];out[2]=src[2];out[4]=src[4];out[6]=src[6];
}
}
#pragma opt_global_reg reset
M2C_UNK CopyMapPreviewBottomHalf(M2C_UNK p){
u32 IsBattleEndSpritePresent(void);u16 *func_020c10a4(s32,s32,s32);
extern void **gCurrentMap;extern u16 gPreviewColumnOffset[],gPreviewRowOffset[];
s32 x,y,w,z,h;u16 *src,*dst;void *base;z=IsBattleEndSpritePresent();base=*gCurrentMap;
h=M2C_FIELD(base,volatile u16 *,0x5146+0);w=M2C_FIELD(base,volatile u16 *,0x5144+0);
w=(w+1)&~1;h=(h+1)&~1;
for(y=h>>1;y<h;y++){for(x=0;x<w;x++){src=func_020c10a4(x,y,z);dst=(u16*)p+gPreviewColumnOffset[x]+gPreviewRowOffset[y];dst[0]=src[0];dst[2]=src[2];dst[4]=src[4];dst[6]=src[6];}}
}

/* Update the cursor color for a map-preview layer from the animated palette ramp. */
void AnimateMapPreviewLayerCursorColor(void *arg0) {
    M2C_UNK CopyBytesToObjPaletteShadow(void *, s32, M2C_UNK);
    extern s32 gMapPreviewPalettes;
    extern s32 gFrameCounter;

    CopyBytesToObjPaletteShadow(
        (char *)&gMapPreviewPalettes + 0x40 + ((u32)(gFrameCounter & 0x3C) >> 1),
        (M2C_FIELD(arg0, s16 *, 0x5A) << 5) + 0x1C,
        2
    );
}

#pragma opt_strength_reduction off
/* Tally the map's properties: clear the per-owner count grid (MAP_PROPERTY_GRID_BANDS
 * bands of MAP_PROPERTY_GRID_COLUMNS columns, one column per property kind), then
 * walk every cell and bump, for its owner band, the count of the cell's terrain
 * kind.  Returns how many properties were counted. */
s32 CountMapProperties(u8 *dst) {
    s32 GetPropertyCountColumn(s32);
    extern void **gCurrentMap;
    u8 *base;
    s32 count = 0;
    s32 x, y;
    s32 slot, band;
    u16 rowOff;
    u8 val;
    u16 cell;

    {
        s32 rowIndex = 0;
        s32 colIndex;
        u8 *row = dst;
        for (; rowIndex < MAP_PROPERTY_GRID_BANDS; rowIndex++, row += MAP_PROPERTY_GRID_COLUMNS) {
            for (colIndex = 0; colIndex < MAP_PROPERTY_GRID_COLUMNS; colIndex++) {
                row[colIndex] = 0;
            }
        }
    }

    base = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(base, u16 *, MAP_WIDTH); x++) {
                {
                    u8 *p = base + y * 2 + 0x3700;
                    rowOff = *(volatile u16 *)(p + 0x58); /* MAP_ROW_OFFSETS[y] */
                }
                {
                    u8 *q = base + (x + rowOff) * 2 + 0xA00;
                    cell = *(volatile u16 *)(q + 0x10); /* MAP_CELL_TILE_ID[x + rowOff] */
                }
                {
                    u8 *r = base + cell + 0x6000;
                    val = *(volatile u8 *)(r + 0xA60); /* MAP_TILE_TERRAIN[tileId] */
                }
                band = (val & MAP_TERRAIN_OWNER_MASK) >> 5;
                slot = GetPropertyCountColumn(val);
                if (slot >= 0) {
                    u8 *pp = dst + band * MAP_PROPERTY_GRID_COLUMNS;
                    pp[slot]++;
                    count++;
                }
                base = (u8 *)*gCurrentMap;
        }
    }
    return count;
}
#pragma opt_strength_reduction reset
/* Return a map unit-category count for one player band, or sum that category across all five bands when playerBand is negative. */
s32 GetUnitCategoryCount(s32 categoryOffset, u8 *countGrid, s32 playerBand) {
    s32 count = 0;
    if (playerBand < 0) {
        countGrid = (u8 *)categoryOffset + (s32)countGrid;
        for (playerBand = 0; playerBand < 5; playerBand++, countGrid += 12) count += *countGrid;
    } else count += countGrid[playerBand * 12 + categoryOffset];
    return count;
}
#pragma opt_strength_reduction reset
/* Map a cell's terrain kind (the low five bits of its terrain byte) to the slot
 * it occupies in the per-player 12-entry terrain tally, or -1 when the kind is
 * not tallied. */
s32 GetPropertyCountColumn(s32 terrain) {
    switch ((u32)(terrain & 31)) {
    case 15: return 0;
    case 16: return 1;
    case 17: return 2;
    case 18: return 3;
    case 19: return 4;
    case 20: return 5;
    case 21: return 6;
    case 22: return 7;
    case 23: return 9;
    case 24: return 8;
    case 25: return 8;
    case 28: return 10;
    case 26: return 11;
    default: return -1;
    }
}

/* TRUE when `terrain` has one of the tallied property/feature terrain kinds, i.e.
 * one that GetPropertyCountColumn gives a slot in the property tally. */
u8 IsPropertyTerrainKind(s32 terrain) {
    s32 GetPropertyCountColumn(s32);

    return GetPropertyCountColumn(terrain) >= 0;
}

/* Give a frame-rectangle sprite its border pattern: load the frame pattern (block
 * 1) into the current 3D sprite engine at tile `tile`, tinted with the frame-rect
 * UI colour, in OBJ palette slot `palette`. */
void SetFrameRectPattern(s32 tile, s32 palette) {
    s32 GetUiColor(s32);
    Load3DSpritePattern(tile << 5, (u16)palette, GetUiColor(UI_COLOR_FRAME_RECT), 1);
}

/* Draw the border of the frame rectangle whose top-left corner is (x, y): the
 * screen corners (0,0) and (256,192) are mapped to frame-tile coordinates, and
 * DrawFrameBorder stamps the rectangle they span in palette `pal` with tile id
 * `tile`, its tile id packed with the palette and the engine's display mode. */
void DrawFrameRectBorder(s32 x, s32 y, s32 tile, s32 pal) {
    void ScreenToMapPosition(s32, s32, s32 *);
    s32 Divide(s32, s32);
    void DrawFrameBorder(s16, s16, s16, s16, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    s32 topLeft[3], bottomRight[3];
    s32 left, top;

    ScreenToMapPosition(0, 0, topLeft);
    ScreenToMapPosition(256, 192, bottomRight);
    topLeft[0] = Divide(topLeft[0] + 24, 192);
    topLeft[1] = Divide(topLeft[1] + 24, 192);
    bottomRight[0] = Divide(bottomRight[0] + 24, 192);
    bottomRight[1] = Divide(bottomRight[1] + 24, 192);
    left = x + topLeft[0];
    top = y + topLeft[1];
    DrawFrameBorder((s16)left, (s16)top, (s16)(x + bottomRight[0] - left), (s16)(y + bottomRight[1] - top),
        (u16)((tile >> SPRITE_ENGINE_MODE(gCur3DSpriteEngine) & 1023) | (u16)(pal << 12)), 0, FRAME_BORDER_INSIDE);
}

/* Per-frame draw callback of a frame-rectangle sprite: on each engine the
 * sprite's screen mode allows, loads the rectangle's frame tile pattern with
 * its palette, then restores the engine that was current before. */
void DrawFrameRectPattern(void *rect) {
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain, gCur3DSpriteEngine;
    s32 savedEngine, pass, engine, screen;

    savedEngine = gCur3DSpriteEngine;
    pass = 0;
    do {
        if (pass == 0) engine = g3DSpriteEngineMain;
        else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        screen = M2C_FIELD(rect, s32 *, FRAME_RECT_SCREEN);
        if (((screen != 0) || (engine == g3DSpriteEngineMain)) && ((screen != 1) || (engine == g3DSpriteEngineSub)) && ((screen != 3) || (engine == savedEngine))) {
            SetFrameRectPattern(M2C_FIELD(rect, s32 *, FRAME_RECT_TILE), M2C_FIELD(rect, s32 *, FRAME_RECT_PAL));
        }
        pass++;
    } while (pass < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Draws the border of one frame-rectangle sprite: the border is stamped once for
 * each screen, but only on the screens the sprite's mode allows (main only, sub
 * only, or the engine that is active when the sprite is drawn). */
void DrawFrameRectSprite(void *rect){extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine; s32 savedEngine,pass,engine,screen; savedEngine=gCur3DSpriteEngine;pass=0;do{if(pass==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;gCur3DSpriteEngine=engine;screen=M2C_FIELD(rect,s32 *,FRAME_RECT_SCREEN);if(((screen!=0)||(engine==g3DSpriteEngineMain))&&((screen!=1)||(engine==g3DSpriteEngineSub))&&((screen!=3)||(engine==savedEngine)))DrawFrameRectBorder(M2C_FIELD(rect,s32 *,FRAME_RECT_X),M2C_FIELD(rect,s32 *,FRAME_RECT_Y),M2C_FIELD(rect,s32 *,FRAME_RECT_TILE),M2C_FIELD(rect,s32 *,FRAME_RECT_PAL));pass++;}while(pass<2);gCur3DSpriteEngine=savedEngine;}

/* Create a frame-rectangle sprite at (left, top) showing frame tile `tile` in
 * OBJ palette `palette`, drawn on the sprite engine that is current now. */
void SetFrameRect(s32 left, s32 top, s32 tile, s32 palette) {
    void *CreateSpriteFromClass(void *, s32);
    extern M2C_UNK gFrameRectSpriteClass;
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineMain;
    void *rect = CreateSpriteFromClass(&gFrameRectSpriteClass, 7);

    M2C_FIELD(rect, s32 *, FRAME_RECT_X) = left;
    M2C_FIELD(rect, s32 *, FRAME_RECT_Y) = top;
    M2C_FIELD(rect, s32 *, FRAME_RECT_TILE) = tile;
    M2C_FIELD(rect, s32 *, FRAME_RECT_PAL) = palette;
    M2C_FIELD(rect, s32 *, FRAME_RECT_SCREEN) = ((u8)(gCur3DSpriteEngine == g3DSpriteEngineMain) != 1);
}

/* Delete every sprite object of the frame-rectangle class (the border sprites
 * that SetFrameRect creates and DrawFrameRectSprite draws around a map frame). */
void RemoveFrameRectSprites(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gFrameRectSpriteClass;
    DeleteSpriteObjectsOfClass(&gFrameRectSpriteClass);
}

/* Return 1 when value lies within the inclusive range min..max, else 0.  The
 * occupation screen calls it (discarding the result) to note that a terrain
 * kind's background index names one of the backgrounds. */
u8 Main_IsValueInRange(s32 value, s32 min, s32 max) {
    s32 inRange;

    if ((min <= value) && (value <= max)) inRange = 1;
    else inRange = 0;
    return inRange;
}

/* Map property terrain to the occupation screen's background index, using the airport art as the fallback. */
s32 GetOccupationBackgroundIndex(s32 terrainKind) {
    switch (terrainKind) {
    case MAP_TERRAIN_AIRPORT:       return 0;
    case MAP_TERRAIN_PORT:          return 1;
    case MAP_TERRAIN_HQ:            return 2;
    case MAP_TERRAIN_CITY:          return 3;
    case MAP_TERRAIN_BASE:          return 4;
    case MAP_TERRAIN_COM_TOWER:     return 5;
    case MAP_TERRAIN_RADAR:         return 6;
    case MAP_TERRAIN_TEMP_AIRFIELD: return 7;
    case MAP_TERRAIN_TEMP_PORT:     return 8;
    default:                        return 0;
    }
}

/* OBJ tile offset of the occupation screen's background graphic for property
 * terrain kind `terrainKind`: the background index times the per-background tile
 * stride, based at OCCUPATION_BACKGROUND_TILE_BASE. */
u16 GetOccupationBackgroundTileOffset(s32 terrainKind) {
    return (u16) ((GetOccupationBackgroundIndex(terrainKind) * OCCUPATION_BACKGROUND_TILE_STEP) + OCCUPATION_BACKGROUND_TILE_BASE);
}

/* Name of the occupation screen's background graphic for property terrain
 * `terrainKind`: look its background index up and return that background's name. */
s32 GetOccupationBackgroundName(s32 terrainKind) {
    s32 index = GetOccupationBackgroundIndex(terrainKind);
    Main_IsValueInRange((s16) index, 0, OCCUPATION_BACKGROUND_COUNT - 1); /* the index names one of the backgrounds */
    return gOccupationBackgroundNames[index];
}

/* First sprite tile of CO `coId`'s portrait strip, or CO_PORTRAIT_TILE_NONE when
 * the CO has no portrait; the slot order is the sheet's, where ids 3 and 4 are
 * swapped. */
u16 GetCOPortraitOffset(u32 coId) {
 switch(coId) {
 case 0:return CO_PORTRAIT_TILE_NONE;
 case 1:coId=0;break;
 case 2:coId=1;break;
 case 3:coId=3;break;
 case 4:coId=2;break;
 }
 return coId*CO_PORTRAIT_TILE_STRIDE+CO_PORTRAIT_TILE_BASE;
}

/* UI tint colour an army's occupation cut-in panel blends toward: army 1 is red,
 * 2 blue and 3 cyan; army 4 and every other id are untinted. */
s32 GetArmyColor(u32 armyId) {
    s32 GetUiColor(s32);
    switch (armyId) {
    case 1:
        return GetUiColor(2);
    case 2:
        return GetUiColor(4);
    case 3:
        return GetUiColor(5);
    case 4:
        return GetUiColor(0);
    case 0:
    default:
        return 0;
    }
}

