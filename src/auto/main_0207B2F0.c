/* 39 functions from 0x0207B2F0 to 0x0207C2F0 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
/* The current 3D sprite batch: gSpriteBatch holds a pointer to one. Up to ten sprites are
 * placed into the sprite engine's tile memory. */
typedef struct SpriteBatch {
    s32 baseX;          /* +0x00 tile x the batch is placed at */
    s32 baseY;          /* +0x04 tile y */
    s32 bank;           /* +0x08 sprite engine bank */
    s32 bank2;          /* +0x0C second sprite engine bank */
    s32 tileBase;       /* +0x10 */
    s32 tileOffset[10]; /* +0x14 running tile offset of each placed sprite */
    u8 kind[10];        /* +0x3C tile kind of each placed sprite, 0 = empty */
    u8 selected[10];    /* +0x46 selection state of each placed sprite */
    s32 paletteBase;    /* +0x50 first palette id of the batch's sprites (GetBatchPalette) */
    s32 count;          /* +0x54 sprites placed */
    s32 field58;        /* +0x58 */
    s32 field5C;        /* +0x5C */
    s32 tileStride;     /* +0x60 tiles between two placed sprites (GetBatchSpriteTile) */
    s32 field64;        /* +0x64 kind drawn with the alternate palette */
} SpriteBatch;

#define SPRITE_BATCH ((SpriteBatch *)gSpriteBatch)

u8 IsMapViewScrolling(void);
void SetMapViewPositionToTileCentered(M2C_UNK, M2C_UNK);

#pragma push
#pragma optimization_level 2
s32 ClampMapViewToTile(s32 *px, s32 *py, s32 third) {
    s32 GetMapViewWidth(void);
    s32 GetMapViewHeight(void);
    void SetMapCursorTargetTile(s32, s32);
    extern void *gCurrentMap;
    s32 deltaX = 0;
    s32 deltaY = deltaX;
    s16 rawY = *(s16 *)((u8 *)*(volatile void **)gCurrentMap + 0x514A);
    s16 rawX = *(s16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5148);
    s32 tileX = rawX / 16;
    s32 tileY = rawY / 16;
    s32 halfX = GetMapViewWidth();
    s32 halfY = GetMapViewHeight();
    SetMapCursorTargetTile((s16)*px, (s16)*py);
    if (third != 0) {
        *px -= halfX >> 1;
        *py -= halfY >> 1;
        *py += 1;
        if (*px < 0) *px = 0;
        if (*py < 0) *py = 0;
        if (*px + halfX > *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5144)) *px = *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5144) - halfX;
        if (*py + halfY > *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5146)) *py = *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5146) - halfY;
        if (*px < 0) *px = 0;
        if (*py < 0) *py = 0;
        if (tileX == *px && tileY == *py) return 0;
        goto done_one;
    }
    if (*px < tileX + 1) {
        if (tileX != 0) deltaX = -1;
    }
    if (*py < tileY + 1) {
        if (tileY != 0) deltaY = -1;
    }
    if (*px > tileX + halfX - 2) {
        if (tileX + halfX < *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5144)) deltaX = -(halfX - 2);
    }
    if (*py > tileY + halfY - 2) {
        if (tileY + halfY < *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5146)) deltaY = -(halfY - 2);
    }
    if (deltaX != 0) { *px += deltaX; } else { *px = tileX; }
    if (deltaY != 0) { *py += deltaY; } else { *py = tileY; }
    if (*px < 0) *px = 0;
    if (*py < 0) *py = 0;
    if (*px + halfX > *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5144)) *px = *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5144) - halfX;
    if (*py + halfY > *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5146)) *py = *(u16 *)((u8 *)*(volatile void **)gCurrentMap + 0x5146) - halfY;
    if (*px < 0) *px = 0;
    if (*py < 0) *py = 0;
    if (*px == tileX && *py == tileY) return 0;
done_one:
    return 1;
}
#pragma pop
/* Start scrolling the map view to the target tile (x, y): do nothing while a
 * scroll is still running (its marker sprite exists) or when the view is already
 * there; otherwise clear the view's scroll state and create the map-scroll task,
 * storing the clamped tile the view will pan to.  A nonzero `pan` centers the
 * view on the tile instead of stepping it by one cell. */
s32 ScrollMapViewToTile(s32 x, s32 y, s32 pan) {
    s32 ClampMapViewToTile(s32 *, s32 *, s32);
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    extern M2C_UNK gMapScrollSpriteClass;
    extern void *gCurrentMap;
    void *sprite;
    if (IsMapViewScrolling() != 0) return 1;
    if (ClampMapViewToTile(&x, &y, pan) == 0) return 0;
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_VIEW_SCROLL_STATE) = 0;
    sprite = CreateSpriteFromClass(&gMapScrollSpriteClass, 7);
    ((MapScrollAnim *)sprite)->targetX = x << 4;
    ((MapScrollAnim *)sprite)->targetY = y << 4;
    return 1;
}

/* Clamp the requested tile to the visible map bounds, update the map view, and notify its scroll callback. */
s32 SetMapViewPositionToTile(s32 tileX, s32 tileY, s32 centerOnTile) {
    s32 ClampMapViewToTile(s32 *, s32 *, s32);
    extern void *gCurrentMap;
    void (*scrollDone)(void);

    if (ClampMapViewToTile(&tileX, &tileY, centerOnTile) == 0) return 0;
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_X) = tileX << 4;
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_Y) = tileY << 4;
    scrollDone = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), MAPVIEW_SCROLL_DONE);
    if (scrollDone != NULL) scrollDone();
    return 1;
}

/* Center the starting view on player 1's HQ if available, or on the middle of the map. */
void CenterMapViewAtBattleStart(void) {
    s32 IsPlayerActive(s32);
    s32 PlayerHasHq(s32);
    extern void *gCurrentMap;
    u32 tileX, tileY;
    void *map;

    if (IsPlayerActive(1) != 0 && PlayerHasHq(1) != 0) {
        map = M2C_FIELD(gCurrentMap, void **, 0);
        tileX = M2C_FIELD(map, u8 *, MAP_PLAYER_STATES + MAP_PLAYER_STRIDE + PLAYER_REC_HQ_X) & 0x7F;
        tileY = M2C_FIELD(map, u8 *, MAP_PLAYER_STATES + MAP_PLAYER_STRIDE + PLAYER_REC_HQ_Y) & 0x7F;
    } else {
        map = M2C_FIELD(gCurrentMap, void **, 0);
        tileX = (u32) M2C_FIELD(map, u16 *, MAP_WIDTH) >> 1;
        tileY = (u32) M2C_FIELD(map, u16 *, MAP_HEIGHT) >> 1;
    }
    SetMapViewPositionToTileCentered(tileX, tileY);
}

void SetMapViewToTile(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK SetMapViewPositionToTile(M2C_UNK, M2C_UNK, M2C_UNK);
    SetMapViewPositionToTile(arg0, arg1, 0);
}

void SetMapViewPositionToTileCentered(M2C_UNK arg0, M2C_UNK arg1) {
    SetMapViewPositionToTile(arg0, arg1, 1);
}

s32 StepMapViewToTile(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK ScrollMapViewToTile(M2C_UNK, M2C_UNK, M2C_UNK);
    return ScrollMapViewToTile(arg0, arg1, 0);
}

s32 PanMapViewToTile(M2C_UNK arg0, M2C_UNK arg1) {
    return ScrollMapViewToTile(arg0, arg1, 1);
}

/* Sprite-state callback: step the map view to the tile coordinates stored in the state. */
s32 SpriteState_StepMapViewToTile(void *tilePosition) {
    if (tilePosition == NULL) return 0;
    return StepMapViewToTile(M2C_FIELD(tilePosition, u8 *, 1), M2C_FIELD(tilePosition, u8 *, 2));
}

/* Sprite-state callback: pan the map view to the tile the unit record `unit`
 * stands on. */
s32 PanMapViewToUnit(void *unit) {
    if (unit == NULL) return 0;
    return PanMapViewToTile(M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y));
}

/* TRUE while the map view is panning: its scroll sprite exists. */
u8 IsMapViewScrolling(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gMapScrollSpriteClass;
    u8 scrolling;

    if (FindObjectByClass(&gMapScrollSpriteClass) != 0) {
        scrolling = 1;
    } else {
        scrolling = 0;
    }
    return scrolling;
}

/* Spawn the map-view scroll hold sprite that keeps the view from scrolling while it runs. */
void CreateMapViewScrollHold(s32 owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMapViewScrollHoldClass;
    CreateSpriteObject(&gMapViewScrollHoldClass, owner);
}

/* Point the current map at the built-in storage for its four blocks: the battle
 * map data, the map-view controller, the active unit-move controller slots and
 * the map effect state.  A fresh session calls this while resetting all state. */
void ResetCurrentMapBlocks(void) {
    extern M2C_UNK gBattleMapBuffer;
    extern M2C_UNK gMapViewController;
    extern M2C_UNK gUnitMoveSlots;
    extern M2C_UNK gMapEffectState;
    extern void *gCurrentMap;
    M2C_FIELD(gCurrentMap, M2C_UNK **, MAP_DATA_PTR) = &gBattleMapBuffer;
    M2C_FIELD(gCurrentMap, M2C_UNK **, MAP_VIEW_PTR) = &gMapViewController;
    M2C_FIELD(gCurrentMap, M2C_UNK **, MAP_UNIT_MOVE_PTR) = &gUnitMoveSlots;
    M2C_FIELD(gCurrentMap, M2C_UNK **, MAP_EFFECT_PTR) = &gMapEffectState;
}

/* Configure the current 3D sprite engine: set control bit 3, clear the low 3 bits of the sprite header, then initialise engine slots from the default data block (and a second pass / the alternate block when not on the secondary engine). */
void Init3DSpriteLayers1D(void) {
    void Apply3DSpriteLayout(void *);
    extern M2C_UNK g3DSpriteLayout1D, g3DSpriteLayoutSub;
    extern u16 *g3DSpriteBankMain;
    extern u16 **g3DSpriteEngineMain, **gCur3DSpriteEngine;
    u16 *volatile sprite0;
    u16 *volatile sprite1;
    u16 *volatile sprite2;
    u8 isSecondaryEngine;

    *g3DSpriteBankMain |= 8;
    sprite0 = *gCur3DSpriteEngine;
    *sprite0 = *sprite0 & ~7;
    Apply3DSpriteLayout(&g3DSpriteLayout1D);
    if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
        isSecondaryEngine = 1;
    } else {
        isSecondaryEngine = 0;
    }
    if (isSecondaryEngine) {
        *g3DSpriteBankMain |= 8;
        sprite1 = *gCur3DSpriteEngine;
        *sprite1 = *sprite1 & ~7;
        Apply3DSpriteLayout(&g3DSpriteLayout1D);
        return;
    }
    sprite2 = *gCur3DSpriteEngine;
    *sprite2 = *sprite2 & ~7;
    Apply3DSpriteLayout(&g3DSpriteLayoutSub);
}

/* Configure the current 3D sprite engine's layers for the 2D OBJ character VRAM
 * mapping: on the main engine clear the bank's 1D mapping bit and load the 2D layer
 * layout, otherwise reset the layer attribute's mode bits and use the sub layout. */
void Init3DSpriteLayers2D(void) {
    void Apply3DSpriteLayout(void *);
    extern M2C_UNK g3DSpriteLayout2D, g3DSpriteLayoutSub;
    extern u16 *g3DSpriteBankMain;
    extern u16 **g3DSpriteEngineMain, **gCur3DSpriteEngine;
    u16 *volatile mainBank;
    u16 *volatile engineBank;
    u8 onMain;
    if (gCur3DSpriteEngine == g3DSpriteEngineMain) onMain = 1; else onMain = 0;
    if (onMain) {
        *g3DSpriteBankMain &= ~DS3D_BANK_OBJ_MAPPING_1D;
        mainBank = *gCur3DSpriteEngine;
        *mainBank = *mainBank & ~7;
        Apply3DSpriteLayout(&g3DSpriteLayout2D);
        return;
    }
    engineBank = *gCur3DSpriteEngine;
    *engineBank = *engineBank & ~7;
    Apply3DSpriteLayout(&g3DSpriteLayoutSub);
}

/* Convert a tile type into the movement/collision result used by callers. */
u32 func_0207b9f4(s32 tileX, s32 tileY, u32 tileType) {
    u32 GetMapCellSpriteVariant(s32, s32, M2C_UNK);
    s32 IsOwnedProductionSite(s32, s32);
    M2C_UNK probeResult;
    u32 result;

    result = tileType;
    switch (result) {
    default:
        break;
    case 0:
        if (IsOwnedProductionSite(tileX >> 4, tileY >> 4) != 0) {
            probeResult = 4;
        } else {
            probeResult = 0;
        }
        result = GetMapCellSpriteVariant(tileX, tileY, probeResult);
        break;
    case 1:
        result = GetMapCellSpriteVariant(tileX, tileY, 0);
        break;
    case 2:
        result = 0x10;
        break;
    case 3:
        result = GetMapCellSpriteVariant(tileX, tileY, 4);
        break;
    case 4:
        result = GetMapCellSpriteVariant(tileX, tileY, 8);
        break;
    case 5:
        result = GetMapCellSpriteVariant(tileX, tileY, 0xC);
        break;
    case 6:
        result = 0x11;
        break;
    case 7:
        result = 0x12;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        result += 0xB;
        break;
    }
    return result;
}

/* Return the sprite script for a map cell drawn at the 1/16-cell coordinates
 * (tileX, tileY): project the cell to screen space and add the quadrant it falls
 * in (0..3) to the four-script group based at `baseScript`. */
u32 GetMapCellSpriteVariant(s32 tileX, s32 tileY, M2C_UNK baseScript) {
    void func_02079c90(s32, s32, s32 *);
    s32 pos[3];
    s32 result = baseScript;
    func_02079c90(tileX * 0x30, tileY * 0x30, pos);
    if (pos[0] >= 0xC0) {
        if (pos[1] >= 0x80) result += 2;
        else result += 1;
    } else if (pos[1] >= 0x80) result += 3;
    return result;
}

/* Converts a point on the main screen to a position on the map in
 * MAP_TILE_SUBPIXEL units per cell, clamped to the map's own bounds.  Returns 0
 * once the point had to be clamped (the touch was off the map), 1 when it was
 * already inside. */
s32 ScreenToMapPosition(s32 screenX, s32 screenY, s32 *mapPos) {
    void ScreenToMapFixedPoint(s32, s32, s32 *);
    extern void *gCurrentMap;
    s32 inside = 1;
    s32 maxX, maxY;
    void *map = M2C_FIELD(gCurrentMap, void **, 0);
    maxX = M2C_FIELD(map, u16 *, MAP_WIDTH) * MAP_TILE_SUBPIXEL - 1;
    maxY = M2C_FIELD(map, u16 *, MAP_HEIGHT) * MAP_TILE_SUBPIXEL - 1;
    ScreenToMapFixedPoint(screenX, screenY, mapPos);
    if (mapPos[0] < 0) { inside = 0; mapPos[0] = 0; }
    if (mapPos[1] < 0) { inside = 0; mapPos[1] = 0; }
    if (mapPos[0] > maxX) { mapPos[0] = maxX; inside = 0; }
    if (mapPos[1] > maxY) { inside = 0; mapPos[1] = maxY; }
    return inside;
}

void SetCurrentSpriteBatch(s32 arg0) {
    extern s32 gSpriteBatch;
    gSpriteBatch = arg0;
}

/* Initialises the current 3D sprite batch: remembers the two layers it draws on,
 * the tile offset of its first sprite and the first palette of its sprites,
 * points the batch at the first layer's VRAM address, clears the placed-sprite
 * list and sets the batch's default tile stride. */
void InitSpriteBatch(s32 layer, s32 layer2, s32 tileOffset, s32 paletteBase) {
    void SetSpriteBatchLimits(s32, s32);
    void func_0207bcb0(s32);
    extern s32 gSpriteBatch;
    extern u16 **gCur3DSpriteEngine;
    s32 i;
    SPRITE_BATCH->bank = layer;
    SPRITE_BATCH->bank2 = layer2;
    SPRITE_BATCH->tileBase = DS3D_ENGINE(gCur3DSpriteEngine)->layerVram[layer];
    SPRITE_BATCH->tileOffset[0] = tileOffset;
    SPRITE_BATCH->paletteBase = paletteBase;
    SPRITE_BATCH->count = 0;
    SPRITE_BATCH->field64 = 0;
    SPRITE_BATCH->baseX = 0;
    SPRITE_BATCH->baseY = 0;
    SetSpriteBatchLimits(10, 2);
    func_0207bcb0(0x20);
    for (i = 0; i < 10; i++) {
        SPRITE_BATCH->kind[i] = 0;
    }
}

void SetSpriteBatchHighlightKind(s32 arg0) {
    extern s32 gSpriteBatch;
    M2C_FIELD((void *)gSpriteBatch, s32 *, 0x64) = arg0;
}

/* Set the current 3D sprite batch's two setup limits; InitSpriteBatch always
 * passes 10 (the batch's sprite capacity) and 2. */
void SetSpriteBatchLimits(s32 spriteLimit, s32 secondLimit) {
    extern s32 gSpriteBatch;
    SPRITE_BATCH->field58 = spriteLimit;
    SPRITE_BATCH->field5C = secondLimit;
}

void func_0207bcb0(s32 arg0) {
extern s32 gSpriteBatch;
M2C_FIELD(gSpriteBatch,s32 *,0x60)=arg0;
}

/* Append a sprite of the given kind and selection state to the current 3D sprite
 * batch, advancing the next placed sprite's tile offset past this sprite's tiles
 * (ceil(width / 8) * ceil(height / 8) tiles) and bumping the batch's count. */
void AddSpriteToBatch(s32 kind, s32 selected) {
    extern s32 gSpriteBatch;
    extern u8 gSpriteKindWidths[], gSpriteKindHeights[];
    void AdvanceBatchTileOffset(s32, s32);
    SPRITE_BATCH->kind[SPRITE_BATCH->count] = kind;
    SPRITE_BATCH->selected[SPRITE_BATCH->count] = selected;
    AdvanceBatchTileOffset(SPRITE_BATCH->count, ((gSpriteKindWidths[kind * 8] + 7) >> 3) * ((gSpriteKindHeights[kind * 8] + 7) >> 3));
    SPRITE_BATCH->count++;
}

/* Running tile offset of the batch's placed sprite `sprite`: its tile index within
 * the batch's tile list, one entry per placed sprite. */
s32 GetBatchTileOffset(s32 sprite) {
extern s32 gSpriteBatch;
return SPRITE_BATCH->tileOffset[sprite];
}

/* Reserve `tileCount` tiles for placed sprite `index`: the sprite placed next
 * starts that many tiles after it.  The batch's last slot has no successor. */
void AdvanceBatchTileOffset(s32 index, s32 tileCount) {
    extern s32 gSpriteBatch;
    if (index >= 9) return;
    SPRITE_BATCH->tileOffset[index + 1] = tileCount + SPRITE_BATCH->tileOffset[index];
}

/* Absolute tile (in the batch's tile bank) the placed sprite `sprite` draws at:
 * the batch's tile base plus its tile stride times the sprite's running offset. */
s32 GetBatchSpriteTile(s32 sprite) {
s32 GetBatchTileOffset(s32); extern s32 gSpriteBatch;
SpriteBatch *batch=(SpriteBatch *)gSpriteBatch;
s32 index=GetBatchTileOffset(sprite);
return batch->tileBase+batch->tileStride*index;
}

/* Return the palette id of the current 3D sprite batch's `index`-th palette,
 * `index` entries after the batch's first palette id. */
s32 GetBatchPalette(s32 index) {
    extern s32 gSpriteBatch;

    return SPRITE_BATCH->paletteBase + index;
}

#pragma push
#pragma opt_strength_reduction off
/* Load the current sprite batch's graphics: copy its palette bank, open the menu
 * NARC matching the first placed sprite's source width, then decompress every
 * placed sprite's own file into its tile index. */
void LoadSpriteBatchGraphics(void) {
    s32 GetBatchPalette(s32);
    void CopyToObjPaletteShadow(void *, s32, s32);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK GetLocalizedFileName(M2C_UNK *);
    void OpenNarcArchive(M2C_UNK *);
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK *, M2C_UNK);
    void CloseNarcArchive(void);
    s32 GetBatchSpriteTile(s32);
    extern s32 gSpriteBatch;
    extern u8 gSpriteKindWidths[];
    extern u8 gSpriteKindFileNames[];
    extern M2C_UNK gUiSpritePalette;
    extern M2C_UNK sSpriteBatchDir;
    extern M2C_UNK sMenu00NarcFile;
    extern M2C_UNK sMenu01NarcFile;
    extern M2C_UNK sMenu02NarcFile;

    s32 sprite;
    u8 kind;
    s32 width;
    s32 palette;
    s32 batch;
    s8 *kindCursor;

    palette = GetBatchPalette(0);
    width = 0;
    CopyToObjPaletteShadow(&gUiSpritePalette, palette << 5, 0x60);

    batch = gSpriteBatch;
    sprite = width;
    if (M2C_FIELD(batch, s32 *, 0x54) > 0) {
        kindCursor = (s8 *)batch;
        do {
            kind = M2C_FIELD(kindCursor, u8 *, 0x3C);
            if (kind != 0) {
                width = gSpriteKindWidths[kind << 3];
                break;
            }
            ++sprite;
            ++kindCursor;
        } while (sprite < M2C_FIELD(batch, s32 *, 0x54));
    }

    SetFileDirectory(&sSpriteBatchDir);

    switch (width) {
    case 0x60:
        OpenNarcArchive(GetLocalizedFileName(&sMenu00NarcFile));
        break;
    case 0x40:
        OpenNarcArchive(GetLocalizedFileName(&sMenu01NarcFile));
        break;
    case 0x30:
        OpenNarcArchive(GetLocalizedFileName(&sMenu02NarcFile));
        break;
    }

    for (sprite = 0; sprite < M2C_FIELD(gSpriteBatch, s32 *, 0x54); sprite++) {
        batch = gSpriteBatch;
        kind = M2C_FIELD(batch + sprite, u8 *, 0x3C);
        if (kind != 0) {
            M2C_UNK fileName = M2C_FIELD(&gSpriteKindFileNames, M2C_UNK *, kind << 3);
            M2C_UNK localizedName = GetLocalizedFileName(fileName);
            s32 tileIndex = GetBatchSpriteTile(sprite);
            LoadNarcFileDecompressed(localizedName, tileIndex);
        }
    }

    CloseNarcArchive();
}
#pragma pop
/* Draw the current sprite batch with its graphics at pixel (x, y): place the batch's base tile,
 * submit its tiles, then offset each of the two layers' quads by the leftover sub-tile pixels. */
void DrawSpriteBatchAt(s32 x, s32 y) {
    extern s32 gSpriteBatch;
    extern u16 **gCur3DSpriteEngine;
    void DrawSpriteBatch(void);
    s32 subX, subY;
    u8 layer;

    SPRITE_BATCH->baseX = x >> 3;
    SPRITE_BATCH->baseY = y >> 3;
    DrawSpriteBatch();
    subX = x & 7;
    subY = y & 7;
    layer = SPRITE_BATCH->bank2;
    M2C_FIELD((u8 *)*gCur3DSpriteEngine + layer * 2, s16 *, DS3D_QUAD_X) = 7 - subX;
    M2C_FIELD((u8 *)*gCur3DSpriteEngine + layer * 2, s16 *, DS3D_QUAD_Y) = -3 - subY;
    layer = SPRITE_BATCH->bank;
    M2C_FIELD((u8 *)*gCur3DSpriteEngine + layer * 2, s16 *, DS3D_QUAD_X) = -subX;
    M2C_FIELD((u8 *)*gCur3DSpriteEngine + layer * 2, s16 *, DS3D_QUAD_Y) = -subY;
}

/* Plots the current 3D sprite batch into the sprite engine's tile memory: each placed sprite is
 * written as consecutive tile ids at its position, using the palette of its kind or of the
 * selected sprite. */
void DrawSpriteBatch(void) {
    extern s32 gSpriteBatch;
    extern u16 **gCur3DSpriteEngine;
    s32 sprite;
    s32 x, y;
    s32 totalRows;
    s32 kind, selected;
    s32 stride;
    s32 row;
    s32 col;
    u16 tile;
    s32 rowY;

    totalRows = 0;
    sprite = 0;
    x = SPRITE_BATCH->baseX;
    y = SPRITE_BATCH->baseY;
    for (; sprite < SPRITE_BATCH->count; sprite++) {
        kind = SPRITE_BATCH->kind[sprite];
        selected = SPRITE_BATCH->selected[sprite];
        if (kind) {
            if (SPRITE_BATCH->field64 != kind)
                tile = GetBatchTileOffset(sprite) | ((u32)(GetBatchPalette(0) << 28) >> 16);
            else
                tile = GetBatchTileOffset(sprite) | ((u32)(GetBatchPalette(1) << 28) >> 16);
            if (selected == 1)
                tile = GetBatchTileOffset(sprite) | ((u32)(GetBatchPalette(2) << 28) >> 16);
            for (row = 0; row < GetBatchSpriteRows(sprite); row++) {
                rowY = totalRows + y + row;
                for (col = 0; col < GetBatchSpriteCols(sprite); col++) {
                    stride = rowY * 32;
                    M2C_FIELD((u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine + SPRITE_BATCH->bank * 4, void **, 0x20) + stride * 2, u16 *, (x + col) * 2) = tile;
                    tile++;
                }
            }
            totalRows += GetBatchSpriteRows(sprite);
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1 << SPRITE_BATCH->bank;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1 << SPRITE_BATCH->bank2;
}

/* Number of 8x8 tile columns covered by the source image of placed sprite `index`. */
s32 GetBatchSpriteCols(s32 index) {
    s32 GetBatchSpriteSourceWidth();
    return (s32) (GetBatchSpriteSourceWidth(index) + 7) >> 3;
}

/* Number of 8x8 cells tall that sprite `index`'s source graphic spans. */
s32 GetBatchSpriteRows(s32 index) {
    s32 GetBatchSpriteSourceHeight();
    return (s32) (GetBatchSpriteSourceHeight(index) + 7) >> 3;
}

/* Width in pixels of the source tiles of placed sprite `index`, looked up by its kind. */
s32 GetBatchSpriteSourceWidth(s32 index) {
    extern s32 gSpriteBatch;
    extern u8 gSpriteKindWidths[];
    return gSpriteKindWidths[SPRITE_BATCH->kind[index] * 8];
}

/* Height in pixels of the source tiles of placed sprite `index`, looked up by its kind. */
s32 GetBatchSpriteSourceHeight(s32 index) {
    extern s32 gSpriteBatch;
    extern u8 gSpriteKindHeights[];
    return gSpriteKindHeights[SPRITE_BATCH->kind[index] * 8];
}

/* Load the demo battle's fixed graphics into VRAM: the compressed tile block into
 * the tile area at `tileDest`, then its 32-byte palette into the palette area at
 * `paletteDest`. */
void LoadDemoBattleGraphics(M2C_UNK tileDest, M2C_UNK paletteDest) {
    M2C_UNK GX_BeginLoadTex();
    M2C_UNK GX_EndLoadTex();
    M2C_UNK GX_BeginLoadTexPltt();
    M2C_UNK GX_EndLoadTexPltt();
    M2C_UNK MI_CpuCopy32(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK LoadGraphicsBlock(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gDemoBattleGraphics, gDemoBattlePalette;
    GX_BeginLoadTex();
    LoadGraphicsBlock(&gDemoBattleGraphics, tileDest);
    GX_EndLoadTex();
    GX_BeginLoadTexPltt();
    MI_CpuCopy32(&gDemoBattlePalette, paletteDest, 0x20);
    GX_EndLoadTexPltt();
}

/* Seed the random generator from the RTC: the date (year, month, day) and the
 * time of day (hour, minute, second) are folded into one value, with a fixed
 * seed when the RTC could not be read. */
void SeedRandomFromRtc(void) {
    s32 GetRtcDate(void *);
    s32 GetRtcTime(void *);
    extern s32 gRandomSeed;
    s32 date[4]; /* year, month, day, weekday */
    s32 time[3]; /* hour, minute, second */
    if (GetRtcDate(date) == 0 && GetRtcTime(time) == 0) {
        gRandomSeed = ((((date[0] * 12 + date[1]) * 30 + date[2]) * 24 + time[0]) * 60 + time[1]) * 60 + time[2];
        return;
    }
    gRandomSeed = 0x12345678;
}

void SetRandomSeed(s32 arg0) {
    extern s32 gRandomSeed;
    gRandomSeed = arg0;
}

s32 GetRandomSeed(void) {
    extern s32 gRandomSeed;
    return gRandomSeed;
}
