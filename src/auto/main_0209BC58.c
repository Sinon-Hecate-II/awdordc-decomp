/* 34 functions from 0x0209BC58 to 0x0209CC04 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
typedef struct { s16 value; s8 mode; u8 low:4; u8 high:4; } SpriteAttribute0209;

/* The fields of a text object (TextState, main_0209ACC4.c) that this file touches. */
typedef struct TextState0209 {
    u8  filler_00[0x4a];
    u8  cellX;      /* +0x4A current cell x offset in the line */
    u8  cellY;      /* +0x4B current cell y offset in the line */
    u16 linePixel;  /* +0x4C pixel offset of the current line */
    u16 lineStart;  /* +0x4E pixel offset the line starts at */
    void (*callback)(void); /* +0x50 redraw callback */
    s8  delay;      /* +0x54 frames left before the next step */
    s8  speed;      /* +0x55 frames per step */
    u8  column;     /* +0x56 pixel offset inside the current cell (0..7) */
} TextState0209;
/* One map's progress record in gMapProgressRecords, indexed by mapId - 0xA1.
 * Each field name gives its bit offset, low end first:
 *   state (0-2)    "new" marker: 0 none, 1 newly unlocked, 2 seen,
 *                  3 best score improved, 4 improvement acknowledged
 *   field3 (3-6)   player slot the record was set for
 *   field7 (7-16)  map/turn word
 *   field17 (17-25) best score
 *   field26 (26-28) rating rank before the last update
 *   field29 (29-31) current rating rank (record >> 29) */
typedef struct SpriteStateWord {
    u32 state : 3;
    u32 field3 : 4;
    u32 field7 : 10;
    u32 field17 : 9;
    u32 field26 : 3;
    u32 field29 : 3;
} SpriteStateWord;

extern s32 gCur3DSpriteEngine;
extern s32 g3DSpriteEngineMain;
/* gCarriedUnitIconTable holds one SpriteAttribute0209 icon record per carried-unit
 * slot, in two halves: the active main sprite engine uses the first 32 records and
 * the sub engine the next 32. */
#define CARRIED_UNIT_ICON_COUNT 32
#define CARRIED_UNIT_ICON_HALF_SHIFT 7 /* bytes into the sub engine's half: CARRIED_UNIT_ICON_COUNT * 4 */
extern u8 gCarriedUnitIconTable[256];
extern s32 gMapProgressRecords[58];  // 232 bytes / 4
extern s32 gSaveSlotSummary[2];   // 8 bytes / 4

/* Draw one line of the text script `text` into the current screen engine's shared
 * default text object (see DS3D_ENGINE_TEXT_STATE) at cell (x, y), with glyph
 * palette `palette`, the layer's VRAM and tile addresses and the cell attributes,
 * then create the sprite that renders the object. */
void DrawScreenTextLine(M2C_UNK x, M2C_UNK y, M2C_UNK palette, s32 layerVram, s32 layerTiles, s32 text, u16 attr, u16 tile) {
    s32 CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK StopTextObject(s32);
    M2C_UNK InitTextObject(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16);
    extern M2C_UNK gScreenTextLineSpriteClass;
    extern s32 gCur3DSpriteEngine;
    s32 textObject;
    textObject = M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_TEXT_STATE);
    InitTextObject(textObject, x, y, palette, layerVram, layerTiles, text, (s32)attr, (s32)tile);
    StopTextObject(textObject);
    CreateSpriteFromClass(&gScreenTextLineSpriteClass, 7);
}

/* Create a message sprite for the localized string `textId` drawn as one line at
 * cell (x, y) on DS 3D sprite layer `layer`, using that layer's VRAM address and
 * tile buffer. */
void CreateLocalizedMessageSpriteOnLayer(s32 x, s32 y, s32 layer, s32 textId, u16 attr, u16 tile) {
    void CreateLocalizedMessageSprite(s32, s32, s32, s32, s32, s32, u16, u16);
    extern s32 gCur3DSpriteEngine;
    void *layerFields;

    layerFields = gCur3DSpriteEngine + (layer * 4);
    CreateLocalizedMessageSprite(x, y, layer, M2C_FIELD(layerFields, s32 *, DS3D_ENGINE_LAYER_VRAM), M2C_FIELD(layerFields, s32 *, DS3D_ENGINE_LAYER_TILES), textId, (s32) attr, (s32) tile);
}

/* Create a message sprite whose text is the localized string for `textId`. */
void CreateLocalizedMessageSprite(s32 x, s32 y, s32 palette, s32 layerVram, s32 layerTiles, s32 textId, u16 attr, u16 tile) {
    s32 GetLocalizedText(s32);
    s32 CreateMessageSprite(s32,s32,s32,s32,s32,s32,u16,u16);
    CreateMessageSprite(x, y, palette, layerVram, layerTiles, GetLocalizedText(textId), attr, tile);
}

/* Create a message-box text sprite and set it up to draw the text script `text`
 * at cell (x, y) with glyph palette `palette`, the layer's VRAM and tile
 * addresses and the cell attributes. */
s32 CreateMessageSprite(s32 x, s32 y, s32 palette, s32 layerVram, s32 layerTiles, s32 text, u16 attr, u16 tile) {
    s32 CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK InitTextObject(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16);
    extern M2C_UNK gMessageSpriteClass;
    s32 temp_r0;
    temp_r0 = CreateSpriteFromClass(&gMessageSpriteClass, 7);
    InitTextObject(temp_r0, x, y, palette, layerVram, layerTiles, text, (s32)attr, (s32)tile);
    return temp_r0;
}

/* Initialise a text object to draw the text script `text` at cell (x, y) with
 * glyph palette `palette`, the layer's VRAM and tile addresses, cell attribute
 * `attr` and line pixel offset `tile`; the glyph draw attribute is left 0. */
s32 InitTextObject(s32 textObject, s32 x, s32 y, s32 palette, s32 layerVram, s32 layerTiles, s32 text, u16 attr, u16 tile) {
    void InitTextStateEx(void *, s32, s32, s32, s32, s32, s32, u16, u16, u16);
    InitTextStateEx((void *)textObject, x, y, palette, layerVram, layerTiles, text, attr, 0, tile);
}

#pragma scheduling on
void InitTextStateEx(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u16 arg7, u16 arg8, u16 arg9) {
    void (*Get3DSpriteLayerDirtyMarker(u32))(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;

    M2C_FIELD(arg0, s32 *, 0x34) = arg6;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, u8 *, 0x57) = (u8)arg3;
    M2C_FIELD(arg0, s32 *, 0x3c) = arg4;
    M2C_FIELD(arg0, s32 *, 0x40) = arg5;
    M2C_FIELD(arg0, u16 *, 0x44) = arg7;
    M2C_FIELD(arg0, u16 *, 0x46) = arg8;
    M2C_FIELD(arg0, u16 *, 0x4e) = arg9;
    M2C_FIELD(arg0, u16 *, 0x4c) = arg9;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, u8 *, 0x48) = (u8)(arg1 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x49) = (u8)(arg2 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x4a) = (u8)(arg1 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x4b) = (u8)(arg2 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x54) = (s8)-1;
    M2C_FIELD(arg0, u8 *, 0x55) = 2;
    M2C_FIELD(arg0, s32 *, 0x50) = (s32)Get3DSpriteLayerDirtyMarker((u32)arg3);
    {
        u32 temp_r0 = gCur3DSpriteEngine == g3DSpriteEngineMain ? 1u : 0u;
        temp_r0 = (s32)(u8)temp_r0;
        if (temp_r0 != 1) {
            temp_r0 = 1;
        } else {
            temp_r0 = 0;
        }
        M2C_FIELD(arg0, u8 *, 0x5a) = (u8)temp_r0;
    }
    M2C_FIELD(arg0, u8 *, 0x56) = 0;
    M2C_FIELD(arg0, u8 *, 0x58) = 0;
    M2C_FIELD(arg0, u8 *, 0x59) = 0;
    M2C_FIELD(arg0, u8 *, 0x5c) = 0;
}
#pragma scheduling off
/* (Re)configure a text object's line without touching its script cursor or
 * timers: set its glyph palette (+0x57), x pixel position (+0x3C), glyph cell
 * buffer (+0x40), base cell attribute (+0x44), line pixel offset and start
 * (+0x4C/+0x4E) and the line's first and current cell (+0x48..+0x4B). */
void SetTextObjectLine(void *textObject,s32 lineX,s32 lineY,s32 palette,s32 pixelX,s32 cells,u16 baseAttr,u16 linePixel) {
M2C_FIELD(textObject,u8 *,0x57)=palette;
M2C_FIELD(textObject,s32 *,0x3c)=pixelX;
M2C_FIELD(textObject,s32 *,0x40)=cells;
M2C_FIELD(textObject,u16 *,0x44)=baseAttr;
M2C_FIELD(textObject,u16 *,0x4e)=linePixel;
M2C_FIELD(textObject,u16 *,0x4c)=linePixel;
M2C_FIELD(textObject,u8 *,0x48)=(u8)lineX;
M2C_FIELD(textObject,u8 *,0x49)=(u8)lineY;
M2C_FIELD(textObject,u8 *,0x4a)=(u8)lineX;
M2C_FIELD(textObject,u8 *,0x4b)=(u8)lineY;
}

/* Returns 1 while any message or text sprite is still alive. */
u8 IsTextSpriteActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gMessageSpriteClass;
    extern M2C_UNK gTextLineSpriteClass;
    extern M2C_UNK gScreenTextLineSpriteClass;
    u8 active;

    if (FindObjectByClass(&gMessageSpriteClass) != 0) {
        return 1U;
    }
    if (FindObjectByClass(&gTextLineSpriteClass) != 0) {
        return 1U;
    }
    if (FindObjectByClass(&gScreenTextLineSpriteClass) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* Delete every text sprite still alive: the message sprites and the sprites of
 * both text-line classes. */
void DeleteTextSprites(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gMessageSpriteClass, gTextLineSpriteClass, gScreenTextLineSpriteClass;
    DeleteSpriteObjectsOfClass(&gMessageSpriteClass);
    DeleteSpriteObjectsOfClass(&gTextLineSpriteClass);
    DeleteSpriteObjectsOfClass(&gScreenTextLineSpriteClass);
}

/* Delete every live sprite of the two text-line classes: the in-world text line
 * and the screen text line. */
void DeleteTextLineSprites(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gTextLineSpriteClass;
    extern M2C_UNK gScreenTextLineSpriteClass;
    DeleteSpriteObjectsOfClass(&gTextLineSpriteClass);
    DeleteSpriteObjectsOfClass(&gScreenTextLineSpriteClass);
}

void func_0209bfc8(void) {
    M2C_UNK FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gMessageSpriteClass;
    FindObjectByClass(&gMessageSpriteClass);
}

/* Draw the localized text whose id is `textId` into the tilemap at `tiles`,
 * starting at cell (x, y), with cell attributes `attrs` and glyph set `variant`. */
void DrawLocalizedTextToTilemap(s32 x, s32 y, s32 tiles, s32 textId, u16 attrs, u16 variant) {
    M2C_UNK DrawTextToTilemap(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16);
    DrawTextToTilemap(x, y, tiles, GetLocalizedText(textId), (s32) attrs, (s32) variant);
}

/* Draw the text script `text` at cell (x, y) in the tilemap at `tiles`, with
 * tile attribute base `attrs` and glyph variant `variant`. Forwards to
 * DrawCachedTextToTilemap, which caches each string's glyph positions. */
s32 DrawTextToTilemap(s32 x, s32 y, s32 tiles, s32 text, u16 attrs, u16 variant) {
s32 DrawCachedTextToTilemap(s32,s32,s32,s32,u16,u16);
DrawCachedTextToTilemap(x,y,tiles,text,attrs,variant);
}

/* Writes an unsigned decimal number right to left from (rightX, y), using two tiles per digit. */
void DrawTilemapNumber(s32 rightX, s32 y, s32 tiles, u32 value, u16 attrs, u16 variant) {
    u32 remaining;
    u16 firstTile;
    s16 *entry;

    remaining = value;
    entry = (s16 *)(tiles + (rightX * 2) + (y << TILEMAP_GLYPH_ROW_SHIFT));
    firstTile = TILEMAP_DIGIT_FIRST_TILE;
    if (variant == TILEMAP_GLYPH_ALT_VARIANT) {
        firstTile += TILEMAP_GLYPH_ALT_TILE_OFFSET;
    }
    do {
        u32 digit;

        digit = remaining % 10;
        *entry = (s16)(attrs | (firstTile + (digit * 2)));
        *(s16 *)((u8 *)entry + TILEMAP_GLYPH_ROW_BYTES) =
            (s16)(attrs | ((firstTile + (digit * 2)) + 1));
        entry = (s16 *)((u8 *)entry - 2);
        remaining = remaining / 10;
    } while (remaining != 0);
}

/* Write one symbol of the number font (a plus, minus, decimal point or comma
 * character code) at tile column `x`, row `y` of the tilemap at `tiles`: the
 * upper entry holds the glyph's first half and the entry one row below its second
 * half, both OR'ed with `attrs`; `variant` 3 selects the alternate glyph set. */
void DrawTilemapSymbol(s32 x, s32 y, s32 tiles, s32 symbol, u16 attrs, u16 variant) {
    u16 tile;

    x = tiles + x * 2 + (y << 6); /* x becomes the address of the tilemap entry */
    tile = 0x10;
    switch (symbol) {
    case 0x2b: tile += 0x14; break;
    case 0x2d: tile += 0x16; break;
    case 0x3d: tile += 0x18; break;
    case 0x47: tile += 0x1a; break;
    }
    if (variant == 3) tile += 0x1c;
    *(s16 *)x = (s16)(tile | attrs);
    *(s16 *)((u8 *)x + 0x40) = (s16)((tile + 1) | attrs);
}

/* Advances a text object's current glyph column (0..7) by `delta`; each full cell
 * moves the line one cell on (two pixels) and the drawing cursor with it. Returns
 * nonzero while the column is part-way through a cell. */
s32 AdvanceTextColumn(TextState0209 *text, s32 delta) {
    s32 sum;
    u32 column;

    sum = text->column + delta;
    column = sum & 0xFF;
    text->column = (u8)sum;
    if (column >= 8) {
        do {
            text->column = (u8)(text->column - 8);
            text->linePixel = (u16)(text->linePixel + 2);
            text->cellX = (u8)(text->cellX + 1);
            column = text->column;
        } while (column >= 8);
    }
    if (column != 0) {
        return 1;
    }
    return 0;
}

/* Measure one glyph at `glyph`: add its pixel advance to *width (including the
 * one-pixel gap that follows it once something has already been measured) and
 * return the number of bytes the glyph occupies (2 for a lead byte or an escape
 * pair, 1 for a plain glyph, 0 for a NULL pointer). */
s32 MeasureGlyphWidth(u8 *glyph, s32 *width) {
    u8 IsLeadByte(u8 *);
    u8 IsGlyphEscape(u8 *);
    extern u8 gGlyphWidthTable[256];

    if (glyph != NULL) {
        if (IsLeadByte(glyph)) {
            *width += 8;
            return 2;
        }
        if (IsGlyphEscape(glyph)) {
            if (*width != 0) {
                *width += 1;
            }
            *width += gGlyphWidthTable[glyph[1]];
            return 2;
        }
        if (*width != 0) {
            *width += 1;
        }
        *width += gGlyphWidthTable[glyph[0]];
        return 1;
    }
    return 0;
}

/* Pixel width of a plain text string: walk it glyph by glyph, adding each
 * glyph's advance to the running width. */
s32 MeasureStringWidth(u8 *text) {
    s32 MeasureGlyphWidth(u8 *, s32 *);
    s32 width;
    u8 *cursor;

    cursor = text;
    width = 0;
    if ((cursor != NULL) && (*cursor != 0)) {
        do {
            cursor = &cursor[MeasureGlyphWidth(cursor, &width)];
        } while (*cursor != 0);
    }
    return width;
}

s32 func_0209c2a8(void) {
    s32 MeasureMessageWidth();
    s32 temp_r1;

    temp_r1 = MeasureMessageWidth() + 6;
    return (s32) (temp_r1 + ((u32) (temp_r1 >> 2) >> 0x1D)) >> 3;
}

/* Pixel width of a message string: walks it, honouring the message control
 * codes (0x0B 0x80/0x81 and 0x08 are fixed 16px items, 0x0B 0x82/0x83 insert
 * the current player's commander name, 0x16/0x17/0x1C/0x1D are two-byte codes
 * with no width) and adding each glyph's advance. */
s32 MeasureMessageWidth(u8 *text) {
    s32 GetLocalizedText(u32);
    s32 MeasureStringWidth(u8 *);
    s32 MeasureGlyphWidth(u8 *, s32 *);
    extern u8 gMovementCostTable[];
    extern void **gCurrentMap;
    s32 width;
    u8 *cursor;
    u8 c;

    width = 0;
    cursor = text;
    c = *cursor;
    while (c != 0) {
        switch (c) {
        case 0xB:
            switch (cursor[1]) {
            case 0x80:
            case 0x81:
                width += 0x10;
                cursor += 2;
                break;
            case 0x82:
            case 0x83: {
                u8 *map;
                u16 player;
                /* the player record's commander id (low byte at +0x6C) picks
                 * the commander data record, whose first word is its name */
                map = (u8 *)*gCurrentMap;
                player = M2C_FIELD(map, u16 *, 0x52A4);
                width += MeasureStringWidth((u8 *)GetLocalizedText(M2C_FIELD(gMovementCostTable + ((u32)(M2C_FIELD(map + (u32)player * 0x8C, s32 *, 0x6810) << 24) >> 24) * 0x9C, u32 *, 0)));
                cursor += 2;
                break;
            }
            }
            break;
        case 0x8:
            width += 0x10;
            cursor += 2;
            break;
        case 0x16:
        case 0x17:
        case 0x1C:
        case 0x1D:
            cursor += 2;
            break;
        default:
            cursor += MeasureGlyphWidth(cursor, &width);
            break;
        }
        c = *cursor;
    }
    if (width < 0) width = 0;
    return width;
}

/* Advance a text object's script cursor (the byte pointer at +0x34) by one byte. */
void Text_AdvanceScript(void *text) {
    M2C_FIELD(text, s32 *, 0x34) = (s32) (M2C_FIELD(text, s32 *, 0x34) + 1);
}

/* Advance the text object's script cursor one byte, then keep skipping while it
 * sits on a line end (CR or LF), so the cursor lands on the next drawn byte. */
void Text_SkipLineEnds(void *text) {
    void Text_AdvanceScript(void *);
    Text_AdvanceScript(text);
    if (*(u8 *) M2C_FIELD(text, void **, 0x34) == TEXT_CODE_LINE_END ||
        *(u8 *) M2C_FIELD(text, void **, 0x34) == TEXT_CODE_LINE_END_ALT) {
        Text_SkipLineEnds(text);
    }
}

/* Pixel width of a message string.  Like MeasureMessageWidth, but when
 * stopAtBreak is set it stops at the first line break and returns that line's
 * width; otherwise it returns the widest of the lines, where a line ends at
 * 0x0A/0x0D.  0x04 is a one-byte code, 0x16/0x17/0x1C/0x1D two-byte codes with
 * no width, everything else is a glyph laid out by MeasureGlyphWidth. */
s32 MeasureMessageLinesWidth(u8 *text, s32 stopAtBreak) {
    s32 MeasureGlyphWidth(u8 *, s32 *);
    s32 width;
    s32 lineStart;
    s32 widest = 0;
    u8 *cursor = text;
    u8 c;

    width = 0;
    if (!cursor) {
        return 0;
    }
    c = *cursor;
    if (c) {
        lineStart = 0;
        do {
            switch (c) {
            case 0x0A:
            case 0x0D:
                if (!stopAtBreak) {
                    return width;
                }
                cursor++;
                if (width > widest) {
                    widest = width;
                }
                width = lineStart;
                break;
            case 0x04:
                cursor++;
                break;
            case 0x16:
            case 0x17:
            case 0x1C:
            case 0x1D:
                cursor += 2;
                break;
            default:
                cursor += MeasureGlyphWidth(cursor, &width);
                break;
            }
            c = *cursor;
        } while (c);
    }
    if (widest > width) {
        width = widest;
    }
    return width;
}

/* Height in pixels of a message string: each line is 0x10 pixels tall, so the
 * result counts one line per 0x0A/0x0D break.  0x16/0x17/0x1C/0x1D introduce a
 * two-byte code with no glyph of its own; every other byte advances one.  A NULL
 * string has no height. */
s32 MeasureMessageHeight(u8 *text) {
    s32 height;
    u8 *cursor;
    u8 c;

    cursor = text;
    height = 0x10;
    if (cursor == NULL) {
        return 0;
    }
    c = *cursor;
    if (c != 0) {
        do {
            switch ((s32) c) {
            case 10:
            case 13:
                height += 0x10;
                cursor += 1;
                break;
            case 23:
            case 28:
                /* fallthrough */
            case 22:
                cursor += 2;
                break;
            default:
                cursor += 1;
                break;
            }
            c = *cursor;
        } while (c != 0);
    }
    return height;
}

/* Return the start of line `line` of `text`: skip that many line ends, each the
 * next TEXT_CODE_LINE_END (or TEXT_CODE_LINE_END_ALT when the line has none),
 * and point just past it.  Returns NULL when `text` is NULL or holds fewer than
 * `line` lines. */
void *Text_GetLineStart(void *text, s32 line) {
    void *FindTextControlCode(M2C_UNK, M2C_UNK, M2C_UNK);
    void *cur;
    s32 i;

    if (text == NULL) {
        return NULL;
    }
    cur = text;
    i = 0;
    if (line > 0) {
        do {
            void *lineEnd;

            lineEnd = FindTextControlCode(cur, TEXT_CODE_LINE_END, 1);
            if (lineEnd == NULL) {
                lineEnd = FindTextControlCode(cur, TEXT_CODE_LINE_END_ALT, 1);
                if (lineEnd == NULL) {
                    return NULL;
                }
            }
            i++;
            cur = (void *)((u8 *)lineEnd + 1);
        } while (i < line);
    }
    return cur;
}

/* Point just past the text's first line break (TEXT_CODE_LINE_BREAK), skipping
 * one more byte when the break is followed by a CR (0xD) or LF (0xA); NULL when
 * the text has no line break. */
void *Text_FindLineBreakEnd(void *text) {
    void *FindTextControlCode(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 next;
    void *code;
    void *end;

    code = FindTextControlCode((M2C_UNK)text, TEXT_CODE_LINE_BREAK, 1);
    if (code != NULL) {
        next = M2C_FIELD(code, u8 *, 1);
        end = (void *)((u8 *)code + 1);
        if ((next != 0xA) && (next != 0xD)) {

        } else {
            end = (void *)((u8 *)end + 1);
        }
        return end;
    }
    return NULL;
}

/* Return a text line's alignment from its TEXT_CODE_LINE_ALIGN control code:
 * TEXT_LINE_ALIGN_CENTER/LEFT/RIGHT, or CENTER when the line carries no such
 * code or an unknown operand. */
s32 GetTextLineAlignment(u8 *text) {
    void *FindTextControlCode(M2C_UNK, M2C_UNK, M2C_UNK);
    void *code;
    u8 align;

    code = FindTextControlCode((M2C_UNK)text, TEXT_CODE_LINE_ALIGN, 0);
    if (code == 0) {
        goto fail;
    }
    align = *(u8 *)((u8 *)code + 1) & 0x7F;
    switch (align) {
    case TEXT_LINE_ALIGN_CENTER:
    case 1:
    case TEXT_LINE_ALIGN_LEFT:
    case TEXT_LINE_ALIGN_RIGHT:
        return align;
    default:
        break;
    }
fail:
    return 0;
}

/* Return the icon record for carried-unit slot `slot`, from the half of
 * gCarriedUnitIconTable that belongs to the active 3D sprite engine (the main
 * engine's first half, the sub engine's second). */
void *GetCarriedUnitIcon(s32 slot) {
 u8 isMain=(gCur3DSpriteEngine==g3DSpriteEngineMain);
 s32 subHalf=isMain!=1;
 u8 *base=gCarriedUnitIconTable;
 return base+(subHalf<<CARRIED_UNIT_ICON_HALF_SHIFT)+(slot<<2);
}

/* Set the carried-unit icon's tile index, palette and square dimensions (in 8-pixel units). */
void SetCarriedUnitIconSprite(s32 slot, s16 tileIndex, s8 palette, s32 unused, u8 size) {
    void *GetCarriedUnitIcon(s32);
    SpriteAttribute0209 *icon = GetCarriedUnitIcon(slot);
    icon->value = tileIndex;
    icon->mode = palette;
    icon->low = size;
    icon->high = size;
}

/* Draw the icon of the unit carried in list slot `slot` at screen position
 * (x, y): look up the slot's icon record, size its sprite from the record's
 * width and height nibbles (in 8-pixel units), and add that sprite with
 * `tileBase`, the record's tile index shifted by the engine's display mode and
 * its palette, at `priority`. */
void DrawCarriedUnitIcon(s32 slot, s32 x, s32 y, s32 tileBase, s32 priority) {
    void *GetCarriedUnitIcon(s32);
    s32 GetSpriteDescForSize(s32, s32);
    void AddSprite(s32, s32, s32, s32, s32);
    extern M2C_UNK gCur3DSpriteEngine;
    u8 *icon = GetCarriedUnitIcon(slot);
    u8 size = icon[3];
    s32 sprite = GetSpriteDescForSize((u32)(size << 28) >> 25, ((u32)(size << 24) >> 28) << 3);
    if (sprite) {
        AddSprite(x, y, (u16)(tileBase | (1023 & (*(u16 *)icon >> ((u32)(***(u16 ***)(&gCur3DSpriteEngine) << 17) >> 30))) | ((u32)(icon[2] << 28) >> 16)), sprite, priority);
    }
}

#pragma opt_propagation off
/* Clears every map progress record back to its initial zero state and sets the
 * low three bits of the save-slot summary status word (gSaveSlotSummary + 8) to
 * 1, marking the progress as freshly reset. */
void ResetMapProgress(void) {
    s32 i;
    SpriteStateWord *record;
    record = (SpriteStateWord *) gMapProgressRecords;
    i = 0;
    do {
        record->state = 0;
        record->field3 = 0;
        record->field7 = 0;
        record->field17 = 0;
        record->field26 = 0;
        record->field29 = 0;
        record++;
        i++;
    } while (i < 64);
    *(s32 *) ((u8 *) &gSaveSlotSummary + 8) = (*(s32 *) ((u8 *) &gSaveSlotSummary + 8) & ~7) | 1;
}
#pragma opt_propagation reset
/* When a map's view is closed, mark this session's map progress as seen: every
 * record's "newly unlocked" state (1) and "score improved" state (3) advance to
 * 2 and 4, and the current rating rank is latched into the previous-rank slot
 * (field26 <- field29) so the map list stops flagging the change. */
void AcknowledgeMapProgress(void) {
    s32 i;
    SpriteStateWord *record;
    record = (SpriteStateWord *) gMapProgressRecords;
    i = 0;
    do {
        i++;
        if (record->state == 1) record->state = 2;
        if (record->state == 3) record->state = 4;
        record->field26 = record->field29;
        record++;
    } while (i < 64);
}

void func_0209c8d4(void) {
    s32 GetActiveOverlay();
    s32 IsLinkSessionActive();
    M2C_UNK SetCampaignMapPlayed(u16, M2C_UNK);
    M2C_UNK SetCampaignMapCleared(u16, M2C_UNK);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    s32 GetRatingRank(s32);
    M2C_UNK UnlockCosForMap(u16);
    s32 IsCoUnlocked(s32);
    s32 DidPlayerWin();
    s32 HasActiveHumanPlayer();
    s32 HasHumanPlayerGivenUp();
    s32 IsFinalCampaignMap();
    extern M2C_UNK gCoState;
    extern M2C_UNK gCoPlayerSlots;
    extern s32 gSaveSlotSummary[2];
    extern s32 gMapProgressRecords[58];
    extern u16 gMapConfig;
    extern void **data_027e0058;
    s32 temp_r0_3;
    s32 var_r0;
    s32 var_r5;
    s32 var_r7;
    s32 temp_r9;
    u16 temp_r8;
    u32 var_r1;
    u8 temp_r11;

    temp_r11 = M2C_FIELD(&gCoState, u8 *, 4);
    temp_r8 = M2C_FIELD(*data_027e0058, u16 *, 0x5142);
    var_r7 = 0;
    temp_r9 = temp_r8 - 0xA1;
    do {
        if (IsCoUnlocked(var_r7) != 0) {
            var_r0 = M2C_FIELD(&gCoState, s32 *, 8) | (1 << var_r7);
        } else {
            var_r0 = M2C_FIELD(&gCoState, s32 *, 8) & (-1 ^ (1 << var_r7));
        }
        var_r7 += 1;
        M2C_FIELD(&gCoState, s32 *, 8) = var_r0;
    } while (var_r7 < 0xF);
    if (IsLinkSessionActive() == 0) {
        SetCampaignMapPlayed(temp_r8, 1);
        if (DidPlayerWin() != 0) {
            if ((HasActiveHumanPlayer() != 0) && (HasHumanPlayerGivenUp() == 0)) {
                AddRecordValue(0x1A, 1);
                SetCampaignMapCleared(temp_r8, 1);
            }
            switch (temp_r8) {                      /* switch 1; irregular */
            case 0xB1:                              /* switch 1 */
                AddRecordValue(0x1D, 1);
                break;
            case 0xBA:                              /* switch 1 */
                AddRecordValue(0x1E, 1);
                break;
            }
            if (!(((u32) (gMapConfig << 0x1D) >> 0x1D) & 0xFF)) {
                SpriteStateWord *records = (SpriteStateWord *)gMapProgressRecords;
                {
                    u16 score = M2C_FIELD(&gCoState, u16 *, 6);
                    if (score >= records[temp_r9].field17) {
                        records[temp_r9].field3 = M2C_FIELD(&gCoPlayerSlots, u16 *, temp_r11 * CO_SLOT_STRIDE);
                        records[temp_r9].field17 = score;
                        records[temp_r9].field7 = M2C_FIELD(*data_027e0058, u16 *, 0x52A2);
                        records[temp_r9].field26 = records[temp_r9].field29;
                        records[temp_r9].field29 = GetRatingRank(score);
                    }
                    if (records[temp_r9].state < 3) {
                        records[temp_r9].state = 3;
                    } else {
                        records[temp_r9].state = 4;
                    }
                }
                UnlockCosForMap(temp_r8);
                if (IsFinalCampaignMap() != 0) {
                    var_r1 = (u32) (gSaveSlotSummary[0] << 8) >> 0x18;
                    if ((s32) var_r1 < 0xFF) {
                        var_r1 += 1;
                    }
                    gSaveSlotSummary[0] = (*(volatile s32 *)gSaveSlotSummary & ~0xFF0000) | ((u32) (var_r1 << 0x18) >> 8);
                }
                switch (M2C_FIELD(&gCoState, u8 *, 3)) { /* switch 2 */
                default:                            /* switch 2 */
                    break;
                case 4:                             /* switch 2 */
                    AddRecordValue(2, 1);
                    break;
                case 3:                             /* switch 2 */
                    AddRecordValue(3, 1);
                    break;
                case 2:                             /* switch 2 */
                    AddRecordValue(4, 1);
                    break;
                case 1:                             /* switch 2 */
                    AddRecordValue(5, 1);
                    break;
                }
            }
        }
    }
    var_r5 = 0;
    do {
        if (!(M2C_FIELD(&gCoState, s32 *, 8) & (1 << var_r5)) && (IsCoUnlocked(var_r5) != 0)) {
            M2C_FIELD(&gCoState, s32 *, 8) = (s32) (M2C_FIELD(&gCoState, s32 *, 8) | (1 << var_r5));
        } else {
            M2C_FIELD(&gCoState, s32 *, 8) = (s32) (M2C_FIELD(&gCoState, s32 *, 8) & (-1 ^ (1 << var_r5)));
        }
        var_r5 += 1;
    } while (var_r5 < 0xF);
    temp_r0_3 = GetActiveOverlay();
    switch (temp_r0_3) {                            /* switch 3; irregular */
    case 1:                                         /* switch 3 */
        AddRecordValue(0x21, 1);
        return;
    case 2:                                         /* switch 3 */
        AddRecordValue(0x20, 1);
        return;
    }
}

#pragma opt_propagation reset
/* Saturating increment of a play- or turn-time counter: add one tick, capped at
 * TIME_COUNTER_MAX (999:59:59) instead of wrapping. */
void IncrementCounter(u32 *counter) {
    u32 next;

    next = *counter + 1;
    if (next >= TIME_COUNTER_MAX) {
        *counter = TIME_COUNTER_MAX;
        return;
    }
    *counter = next;
}

