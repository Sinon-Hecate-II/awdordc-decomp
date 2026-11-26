/* 22 functions from 0x0209ACC4 to 0x0209BC58 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#pragma opt_propagation off
static inline void EmitSprite(u16 x, s32 yArg, u32 tile, u16 *desc) {
    void DS3D_AddSpriteQuad(u16, u16, u32, u16 *);
    s32 y = (u16)yArg;
    DS3D_AddSpriteQuad(x,(u16)y,tile,desc);
}
static inline void DrawSpritePair(s32 xArg, s32 y, s32 tile, u16 *desc) {
    s32 x = (u16)xArg;
    void DS3D_AddSpriteQuad(u16, u16, u32, u16 *);
    extern s32 gCur3DSpriteEngine;
    DS3D_AddSpriteQuad(x,(u16)y,(u16)tile,desc);
    DS3D_AddSpriteQuad(x,(u16)((y & 0xff00)|((y+8)&255)),(u16)(tile+(0x3ff & (4 >> (((u32)**(u16 **)gCur3DSpriteEngine <<17)>>30)))),desc);
}
#pragma opt_propagation reset

#pragma push
#pragma opt_propagation off
static inline void EmitSpritePriority(u16 x,s32 yArg,u32 tile,void *desc,s32 priority) {
void AddSprite(s32,s32,s32,void *,s32);
s32 y=(u16)yArg;
((void (*)(u16,u16,u32,void *,s32))AddSprite)(x,(u16)y,tile,desc,priority);
}
static inline void DrawSpritePairPriority(s32 xArg,s32 y,s32 tile,void *desc,s32 priority) {
s32 x=(u16)xArg;
void AddSprite(s32,s32,s32,void *,s32);
extern s32 gCur3DSpriteEngine;
((void (*)(u16,u16,u16,void *,s32))AddSprite)(x,(u16)y,(u16)tile,desc,priority);
((void (*)(u16,u16,u16,void *,s32))AddSprite)(x,(u16)((y&0xff00)|((y+8)&255)),(u16)(tile+(0x3ff&(4>>(s32)(((u32)**(u16 **)gCur3DSpriteEngine<<17)>>30)))),desc,priority);
}
#pragma pop
typedef struct { s32 digits[10]; } DigitTable;
extern const DigitTable gDigitStrings;

/* State of a text object: a cursor into a byte-code text script and the glyph
 * cell buffer of the current line that the script is drawn into. */
typedef struct TextState {
    u8  filler_00[0x34];
    u8 *cursor;        /* +0x34 current byte of the text script */
    u8 *next;          /* +0x38 saved script pointer (used by the 0 command) */
    s32 pixelX;        /* +0x3C x position in pixels */
    u16 *cells;        /* +0x40 glyph cell buffer base */
    u16 baseAttr;      /* +0x44 attribute OR-ed into every cell */
    u16 attr16;        /* +0x46 attribute handed to the glyph draw call */
    u8  lineX;         /* +0x48 first cell x of the line */
    u8  lineY;         /* +0x49 first cell y of the line */
    u8  cellX;         /* +0x4A current cell x offset in the line */
    u8  cellY;         /* +0x4B current cell y offset in the line */
    u16 linePixel;     /* +0x4C pixel offset of the current line */
    u16 lineStart;     /* +0x4E pixel offset the line starts at */
    void (*callback)(void); /* +0x50 redraw callback */
    s8  delay;         /* +0x54 frames left before the next step */
    s8  speed;         /* +0x55 frames per step; nonzero also enables the tick sound */
    u8  column;        /* +0x56 pixel offset inside the current cell (0..7) */
    s8  palette;       /* +0x57 glyph palette */
    u8  unk58;         /* +0x58 */
    u8  unk59;         /* +0x59 */
    u8  screenMode;    /* +0x5A which sprite engine to draw on */
    u8  unk5B;         /* +0x5B */
    u8  flags;         /* +0x5C bit0 = waiting for the active message box (IsTextWaitingForMessageBox),
                        * bit1 = pending redraw, bit3 = text stored */
    u8  filler_5D[3];
    void *sound;       /* +0x60 sound effect played on each glyph */
} TextState;

/* Advance a text object by one script step: interpret the next byte-code
 * command, lay out and draw its glyph into the current line's cell buffer, and
 * return 0 once the script is exhausted (1 means keep going). */
s32 DrawTextStep(void *arg0) {
    s32 PlaySoundEffect(void *);
    s32 DrawGlyph(u8, s32, u8, u16);
    M2C_UNK func_02099854(void *, s32, u8, u16);
    s32 IsTextWaitingForMessageBox(void *);
    s32 GetTextCursorCell(void *);
    M2C_UNK RedrawTextObject(void *);
    s32 IsLeadByte(void *);
    s32 IsGlyphEscape(void *);
    u32 func_02099e6c(void *, s32);
    M2C_UNK WriteTextCellTilePair(void *, s32);
    s32 AdvanceTextColumn(void *, s32);
    M2C_UNK Text_AdvanceScript(void *);
    TextState *st = arg0;
    s32 var_r6;
    s32 temp_r7;
    s32 temp_r8;
    void *notify;

main_loop:
    {
        u32 sw = func_02099e6c(st, GetTextCursorCell(st));
        switch (sw) {
        case 0:
            return 0;
        case 3:
            if ((s8) st->delay < 0) goto end_block;
            return 1;
        case 2:
            if (IsTextWaitingForMessageBox(st) != 0) goto end_block;
            return 1;
        default:
        case 1:
            temp_r7 = IsLeadByte(st->cursor);
            temp_r8 = IsGlyphEscape(st->cursor);
            if (IsTextWaitingForMessageBox(st) == 0) {
                if (st->flags & 0x2) {
                    RedrawTextObject(st);
                    st->flags = (u8) (st->flags & ~0x2);
                    return 1;
                }
                if (!(st->cellX == st->lineX && st->column == 0)) {
                    AdvanceTextColumn(st, 1);
                }
                if (temp_r7 != 0) {
                    func_02099854(st->cursor, st->pixelX + (st->linePixel << 5), st->column, st->attr16);
                    var_r6 = 7;
                } else {
                    s32 pixels;
                    void *p = st->cursor;

                    if (temp_r8 != 0) {
                        u16 t1 = st->linePixel;
                        pixels = M2C_FIELD(st, volatile s32 *, 0x3c);
                        var_r6 = DrawGlyph(M2C_FIELD(p, u8 *, 1), pixels + (t1 << 5), st->column, st->attr16);
                    } else {
                        u16 t1 = st->linePixel;
                        pixels = M2C_FIELD(st, volatile s32 *, 0x3c);
                        var_r6 = DrawGlyph(M2C_FIELD(p, u8 *, 0), pixels + (t1 << 5), st->column, st->attr16);
                    }
                }
                if ((u8) st->column <= 1U) {
                    WriteTextCellTilePair(st, GetTextCursorCell(st));
                }
                if (AdvanceTextColumn(st, var_r6) != 0) {
                    WriteTextCellTilePair(st, GetTextCursorCell(st));
                }
                if ((notify = st->sound) != 0 && (s8) st->speed != 0) {
                    PlaySoundEffect(notify);
                }
            }
            if (!(temp_r7 == 0 && temp_r8 == 0)) {
                Text_AdvanceScript(st);
            }
            Text_AdvanceScript(st);
end_block:
            if ((s8) st->delay < 0) {
                goto main_loop;
            }
            return 1;
        }
    }
}

/* Per-frame update of a text object: handles action input, ticks the step delay,
 * runs the redraw callback and advances the text script on the mapped screen. */
void UpdateTextObject(TextState *st) {
    s32 IsMusicFadeWaitSpriteActive(void);
    s32 IsScreenTransitionWaitSpriteActive(void);
    s32 IsScriptWaitSpriteActive(void);
    void SetMessageBoxState(s8);
    s32 IsMessageBoxIdle(void);
    s32 HideAllScenePanels(void);
    s32 IsAnyScenePanelAnimating(void);
    s32 IsTextWaitingForMessageBox(void *);
    M2C_UNK StopTextObject(M2C_UNK);
    s32 DrawTextStep(void *);
    u32 GetTextObjectKeyAction(void);
    u32 GetTextObjectTouchConfirm(void);
    M2C_UNK DeleteSpriteObject(M2C_UNK);
    M2C_UNK Sprite_ResumeAnimation(M2C_UNK);
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02102eac;
    extern M2C_UNK data_02102e74;
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;

    u32 actionMask;
    s32 savedEngine;
    s32 screenIndex;

    actionMask = GetTextObjectKeyAction();
    actionMask = actionMask | GetTextObjectTouchConfirm();
    actionMask = (u16)actionMask;

    if (st->flags & 0x1) {
        if (FindObjectByClass(&data_02102eac) != 0) return;
        if (FindObjectByClass(&data_02102e74) != 0) return;
        if (IsAnyScenePanelAnimating() != 0) return;
        if (IsMusicFadeWaitSpriteActive() != 0) return;
        if (IsScreenTransitionWaitSpriteActive() != 0) return;
        if (IsScriptWaitSpriteActive() != 0) return;
    }

    if (st->speed >= 1 && IsMessageBoxIdle()) {
        if (actionMask & 0x400) SetMessageBoxState(1);
        if ((actionMask & 0x30) && st->linePixel != st->lineStart)
            StopTextObject((s32)st);
    }
    if (IsTextWaitingForMessageBox(st)) StopTextObject((s32)st);
    st->delay = st->delay+1;
    {
        s32 t=st->delay;
        if (t >= 0 && t < st->speed) return;
        if (t >= 0) st->delay=0;
        st->callback();
    }
    savedEngine = gCur3DSpriteEngine;
    {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            s32 engine;
            if (screenIndex == 0) engine = g3DSpriteEngineMain; else engine = g3DSpriteEngineSub;
            gCur3DSpriteEngine = engine;
            {
                u8 mode = st->screenMode;
                if (mode == 0) {
                    if (engine != g3DSpriteEngineMain) goto skip_tail;
                }
                if (mode == 1) {
                    if (engine != g3DSpriteEngineSub) goto skip_tail;
                }
                if (mode == 3) {
                    if (engine != savedEngine) goto skip_tail;
                }
            }
            if (DrawTextStep(st) == 0) {
                if (st->flags & 0x1) {
                    HideAllScenePanels();
                    Sprite_ResumeAnimation(st);
                } else {
                    DeleteSpriteObject(st);
                }
            }
        skip_tail:
            ;
        }
    }
    gCur3DSpriteEngine = savedEngine;
}

#pragma optimization_level 3
void func_0209b084(void *entity) {
    s32 GetMessageBoxState(void);
    void SetMessageBoxState(s8);
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    void Clear3DSpriteLayer(u8);
    void DeleteTelopWindow(void);
    void func_02097768(void);
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
    extern M2C_UNK data_02102eac, data_02102e74;

    s32 saved;
    s32 i;

    if (GetMessageBoxState() == 3) {
        SetMessageBoxState(0);
    }
    if (GetMessageBoxState() == 2) {
        SetMessageBoxState(0);
    }
    DeleteSpriteObjectsOfClass(&data_02102eac);
    DeleteSpriteObjectsOfClass(&data_02102e74);

    if (!(M2C_FIELD(entity, u8 *, 0x5c) & 0x4)) {
        saved = gCur3DSpriteEngine;
        for (i = 0; i < 2; i++) {
            gCur3DSpriteEngine = (i == 0) ? g3DSpriteEngineMain : g3DSpriteEngineSub;
            {
                u8 mode = M2C_FIELD(entity, u8 *, 0x5a);
                if (mode == 0 && gCur3DSpriteEngine != g3DSpriteEngineMain) continue;
                if (mode == 1 && gCur3DSpriteEngine != g3DSpriteEngineSub) continue;
                if (mode == 3 && gCur3DSpriteEngine != saved) continue;
            }
            Clear3DSpriteLayer(M2C_FIELD(entity, u8 *, 0x57));
            {
                u8 *p = (u8 *)gCur3DSpriteEngine;
                s8 idx = M2C_FIELD(entity, s8 *, 0x57);
                p[0x46] = (u8)(p[0x46] | (1 << idx));
            }
        }
        gCur3DSpriteEngine = saved;
    }

    if (M2C_FIELD(entity, u8 *, 0x5c) & 0x8) {
        DeleteTelopWindow();
        func_02097768();
    }
}
#pragma optimization_level reset
/* Resume the animation of a sprite, but hold it while any scene panel is still
 * animating (the panels take priority over the sprite's motion). */
void Sprite_ResumeAnimationUnlessScenePanelsAnimating(M2C_UNK sprite) {
    M2C_UNK Sprite_ResumeAnimation(M2C_UNK);
    s32 IsAnyScenePanelAnimating();
    if (IsAnyScenePanelAnimating() != 0) {
        return;
    }
    Sprite_ResumeAnimation(sprite);
}

/* Initialise a new text object from the current screen engine's shared default
 * text object (its script pointer, layout, glyph attributes, timing and flags). */
void InitTextState(TextState *st) {
    extern s32 gCur3DSpriteEngine;
    TextState *defaults = M2C_FIELD(gCur3DSpriteEngine, TextState **, 0x54);

    st->cursor = defaults->cursor;
    st->next = defaults->next;
    st->palette = defaults->palette;
    st->pixelX = defaults->pixelX;
    st->cells = defaults->cells;
    st->baseAttr = defaults->baseAttr;
    st->attr16 = defaults->attr16;
    st->lineStart = defaults->linePixel;
    st->linePixel = defaults->linePixel;
    st->sound = defaults->sound;
    st->lineX = defaults->lineX;
    st->lineY = defaults->lineY;
    st->cellX = defaults->cellX;
    st->cellY = defaults->cellY;
    st->delay = defaults->delay;
    st->speed = defaults->speed;
    st->callback = defaults->callback;
    st->column = defaults->column;
    st->unk58 = defaults->unk58;
    st->unk59 = defaults->unk59;
    st->flags = defaults->flags;
}

/* Resolve a localized text id and draw the line at (x, y) with the given layer
 * palette and glyph attributes. */
void DrawLocalizedText(s32 x, s32 y, s32 palette, s32 textId, u16 attr, u16 attr16) {
    void DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16);
    DrawTextLine(x, y, palette, GetLocalizedText(textId), attr, attr16);
}

/* Draw one line of the glyph text `text` at (x, y) on the current engine layer
 * `palette`, with base cell attribute `attr` and the line's pixel offset
 * `lineOffset`; the per-glyph draw attribute is left 0. */
void DrawTextLine(M2C_UNK x, M2C_UNK y, M2C_UNK palette, M2C_UNK text, u16 attr, u16 lineOffset) {
    void DrawTextLineCore(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);

    DrawTextLineCore(x, y, palette, text, attr, 0, lineOffset);
}

/* Draw a line of localized text: resolve the text id for the current locale and
 * hand the line's position, palette, glyph attributes and line offset to the
 * shared text-line renderer. */
void DrawLocalizedTextLine(s32 x, s32 y, s32 palette, s32 textId, u16 attr, u16 attr16, u16 lineOffset) {
    void DrawTextLineCore(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);
    DrawTextLineCore(x, y, palette, GetLocalizedText(textId), attr, attr16, lineOffset);
}

/* Draw one line of glyph text at (x, y) in the current screen engine's layer
 * `palette`: take that layer's VRAM destination and tile buffer and hand the line
 * position, text, glyph attributes and line offset to func_0209b370. */
void DrawTextLineCore(M2C_UNK x, M2C_UNK y, M2C_UNK palette, M2C_UNK text, u16 attr, u16 attr16, u16 lineOffset) {
    M2C_UNK func_0209b370(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16, u16);
    extern s32 gCur3DSpriteEngine;
    void *layer;

    layer = gCur3DSpriteEngine + (palette * 4);
    func_0209b370(x, y, palette, M2C_FIELD(layer, s32 *, DS3D_ENGINE_LAYER_VRAM), M2C_FIELD(layer, s32 *, DS3D_ENGINE_LAYER_TILES), text, (s32) attr, (s32) attr16, (s32) lineOffset);
}

#pragma opt_propagation on
M2C_UNK func_0209b370(M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 d,s32 e,s32 f,u16 g,u16 h,u16 i) {
M2C_UNK InitTextStateEx(s32,M2C_UNK,M2C_UNK,M2C_UNK,s32,s32,s32,u16,u16,u16);
M2C_UNK StopTextObject(s32);void *CreateSpriteFromClass(M2C_UNK *,s32);
extern s32 gCur3DSpriteEngine;extern M2C_UNK gTextLineSpriteClass;
s32 p=gCur3DSpriteEngine;
p=M2C_FIELD(p,s32 *,0x54);
InitTextStateEx(p,a,b,c,d,e,f,g,h,i);
StopTextObject(p);CreateSpriteFromClass(&gTextLineSpriteClass,7);
}
#pragma opt_propagation reset
/* Draws a decimal number into text-line cells: one digit per column, starting
 * at column/row and moving one column left per digit, each digit written two
 * tiles on from the last. */
void DrawNumber(s16 column, s32 row, s32 layer, s32 number, u16 attr, u16 tile) {
 s32 Divide(s32,s32);
 DigitTable table=gDigitStrings;
 do {DrawTextLine(column,row,layer,table.digits[number%10],attr,tile);
 number=Divide(number,10); if(!number) return;
 tile+=2; column--;
 } while(1);
}

/* Copies a text bitmap into the label tile buffer block by block, taking the
 * even pixel rows of each eight-row block first and the odd rows after them. */
void SplitTextBitmapHalves(M2C_UNK source,M2C_UNK destination,u16 width){
s32 HeapAllocBlock(); M2C_UNK HeapFreeBlock(s32);void MI_CpuCopy32(M2C_UNK,M2C_UNK,u32);
s32 block,blockCount; M2C_UNK temp;u8 *src,*dst;
src=(u8 *)source;dst=(u8 *)destination;
temp=HeapAllocBlock(TEXT_BITMAP_BLOCK_BYTES);
blockCount=(((s32)width+7)>>3)+3;blockCount>>=2;
block=0;if(blockCount>0)do{
MI_CpuCopy32(src,temp,TEXT_BITMAP_BLOCK_BYTES);
MI_CpuCopy32(temp,dst,TEXT_BITMAP_ROW_BYTES);
MI_CpuCopy32((u8 *)temp+64,dst+32,TEXT_BITMAP_ROW_BYTES);
MI_CpuCopy32((u8 *)temp+128,dst+64,TEXT_BITMAP_ROW_BYTES);
MI_CpuCopy32((u8 *)temp+192,dst+96,TEXT_BITMAP_ROW_BYTES);
MI_CpuCopy32((u8 *)temp+32,dst+128,TEXT_BITMAP_ROW_BYTES);
MI_CpuCopy32((u8 *)temp+96,dst+160,TEXT_BITMAP_ROW_BYTES);
MI_CpuCopy32((u8 *)temp+160,dst+192,TEXT_BITMAP_ROW_BYTES);
MI_CpuCopy32((u8 *)temp+224,dst+224,TEXT_BITMAP_ROW_BYTES);
src+=TEXT_BITMAP_BLOCK_BYTES;dst+=TEXT_BITMAP_BLOCK_BYTES;
block++;}while(block<blockCount);
HeapFreeBlock((s32)temp);
}

/* Zero the text bitmap `bitmap`: enough TEXT_BITMAP_BLOCK_BYTES-byte blocks for a
 * text line `width` pixels wide. */
void ClearTextBitmap(s32 bitmap, s32 width) {
    M2C_UNK MI_CpuFill32(M2C_UNK, M2C_UNK, s32);
    MI_CpuFill32(0, bitmap, (s32) TEXT_BITMAP_BLOCKS(width) << 8);
}

/* Render the localized text `textId` into the label tile layout at `destination`. */
void RenderLocalizedTextToTiles(s32 destination, s32 textId) {
    s32 GetLocalizedText(s32);
    s32 RenderTextToTiles(s32, s32);

    RenderTextToTiles(destination, GetLocalizedText(textId));
}

/* Renders a text string into a temporary bitmap and splits it into the label
 * tile layout at the destination; returns the text's width in pixels. */
s32 RenderTextToTiles(s32 destination, s32 text) {
    s32 MeasureMessageLinesWidth(s32, M2C_UNK);
    s32 HeapAllocBlock(s32);
    void SplitTextBitmapHalves(s32, s32, u16);
    M2C_UNK HeapFreeBlock(s32);
    s32 width, bitmap;

    width = MeasureMessageLinesWidth(text, 0);
    if ((((((width + 7) >> 3) + 3) >> 2) << 8) > 0) {
        bitmap = HeapAllocBlock(((((width + 7) >> 3) + 3) >> 2) << 8);
        ClearTextBitmap(bitmap, width);
        func_0209b370(0, 0, 4, bitmap, 0, text, 0, 0, 0);
        SplitTextBitmapHalves(bitmap, destination, (u16)width);
        HeapFreeBlock(bitmap);
    }
    return width;
}

#pragma push
#pragma scheduling off
/* Draw a 16-pixel-tall run of map tiles, width pixels wide starting at tile baseTile, at (x, y)
 * as priority-ordered 3D sprites; 4-cell pieces use the 32x16 descriptor, then 2-cell and 1-cell
 * pieces use the 16x8 and 8x8 ones stacked in pairs, advancing across the tile grid and wrapping
 * the screen x coordinate at 512. */
void DrawTileRow(s32 x,s32 y,s32 width,u16 baseTile,s32 priority) {
extern u8 gSpriteDesc32x16[],gSpriteDesc16x8[],gSpriteDesc8x8[];
extern s32 gCur3DSpriteEngine;
s32 cells=(width+7)>>3;u32 curX=x,curY=y;u16 tile=baseTile;
if(cells>=4)do {
u32 mode,nextTile,nextX;
EmitSpritePriority((u16)curX,curY,tile,gSpriteDesc32x16,priority);
mode=((u32)**(u16 **)gCur3DSpriteEngine<<17)>>30;
nextTile=tile+(0x3ff&(8>>(s32)mode));
nextX=(((curX&0x1ff)+32)&0x1ff)|(curX&0xfe00);
tile=(u16)nextTile;curX=(u16)nextX;cells-=4;
}while(cells>=4);
if(cells>=2){
u32 mode;
DrawSpritePairPriority(curX,curY,tile,gSpriteDesc16x8,priority);
mode=((u32)**(u16 **)gCur3DSpriteEngine<<17)>>30;
tile=(u16)(tile+(0x3ff&(2>>(s32)mode)));
curX=(u16)((((curX&0x1ff)+16)&0x1ff)|(curX&0xfe00));
cells-=2;
}
if(cells>=1)DrawSpritePairPriority(curX,curY,tile,gSpriteDesc8x8,priority);
}
#pragma pop
/* Text bitmap splitter sprite update: copy the source bitmap into the
 * destination in split eight-row blocks, then free the source bitmap. */
void UpdateTextBitmapSplitter(void *sprite) {
    void SplitTextBitmapHalves(s32, s32, u16);
    M2C_UNK HeapFreeBlock(s32);
    SplitTextBitmapHalves(M2C_FIELD(sprite, s32 *, TEXT_SPLIT_SOURCE), M2C_FIELD(sprite, s32 *, TEXT_SPLIT_DESTINATION), (u16) M2C_FIELD(sprite, s32 *, TEXT_SPLIT_WIDTH));
    HeapFreeBlock(M2C_FIELD(sprite, s32 *, TEXT_SPLIT_SOURCE));
}

/* Spawn a text bitmap splitter sprite that copies `bitmap` (of `width` pixels)
 * into `destination`, one 8-row block at a time, and then frees the bitmap. */
void CreateTextBitmapSplitter(s32 bitmap, s32 destination, s32 width) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTextBitmapSplitterClass;
    void *sprite;

    sprite = CreateSpriteFromClass(&gTextBitmapSplitterClass, 1);
    M2C_FIELD(sprite, s32 *, TEXT_SPLIT_SOURCE) = bitmap;
    M2C_FIELD(sprite, s32 *, TEXT_SPLIT_DESTINATION) = destination;
    M2C_FIELD(sprite, s32 *, TEXT_SPLIT_WIDTH) = width;
}

/* Renders a text id into a temporary bitmap and hands it to a new splitter
 * sprite that will copy it into `destination`; returns the text width in pixels. */
s32 RenderTextToBitmap(s32 destination, s32 text) {
    M2C_UNK func_0209b370(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16, u16);
    s32 MeasureMessageLinesWidth(s32, M2C_UNK);
    s32 HeapAllocBlock();
    s32 width;
    s32 bitmap;

    width = MeasureMessageLinesWidth(text, 0);
    if ((s32) (((s32) (((s32) (width + 7) >> 3) + 3) >> 2) << 8) > 0) {
        bitmap = HeapAllocBlock();
        ClearTextBitmap(bitmap, width);
        func_0209b370(0, 0, 4, bitmap, 0, text, 0, 0, 0);
        CreateTextBitmapSplitter(bitmap, destination, width);
    }
    return width;
}

#pragma scheduling off
void func_0209b9a8(s32 a0, s32 a1, s32 a2, u16 a3) {
    void DS3D_AddSpriteQuad(u16, u16, u32, u16 *);
    extern u8 gSpriteDesc32x16[];
    extern u8 gSpriteDesc16x8[];
    extern u8 gSpriteDesc8x8[];
    extern s32 gCur3DSpriteEngine;

    s32 n = ((s32)a2 + 7) >> 3;
    u32 x = a0;
    u32 y = a1;
    u16 param = a3;

    if (n >= 4) {
        do {
            u32 mode;
            u32 nextParam;
            u32 nextX;
            EmitSprite((u16)x, y, (u32)param, (u16 *)gSpriteDesc32x16);
            n -= 4;
            mode = (u32)(((u32)(**(u16 **)gCur3DSpriteEngine) << 17) >> 30);
            nextParam = param + (0x3ff & (8 >> (s32)mode));
            nextX = ((((x & 0x1ff) + 0x20) & 0x1ff) | (x & 0xfe00));
            param = (u16)nextParam;
            x = (u16)nextX;
        } while (n >= 4);
    }

    if (n >= 2) {
        u32 mode;
        DrawSpritePair(x,y,param,(u16 *)gSpriteDesc16x8);
        mode = (u32)(((u32)(**(u16 **)gCur3DSpriteEngine) << 17) >> 30);
        param = (u16)(param + (0x3ff & (2 >> (s32)mode)));
        x = (u16)((((((x & 0x1ff) + 0x10) & 0x1ff) | (x & 0xfe00))));
        n -= 2;
    }

    if (n >= 1) {
        DrawSpritePair(x,y,param,(u16 *)gSpriteDesc8x8);
    }
}
#pragma scheduling reset
/* Resolve the localized text id and draw one line of it on the current screen
 * engine's layer at (x, y) with glyph palette `palette`. */
void DrawLocalizedScreenTextLine(M2C_UNK x, M2C_UNK y, M2C_UNK palette, M2C_UNK textId, u16 attr, u16 tile) {
    void DrawScreenText(M2C_UNK, M2C_UNK, s32, s32, u16, u16);
    M2C_UNK GetLocalizedText(M2C_UNK);

    DrawScreenText(x, y, palette, GetLocalizedText(textId), attr, tile);
}

/* Draw one line of the text script `text` at cell (x, y) on the current screen
 * engine's layer `palette`: take that layer's VRAM destination and tile buffer
 * and hand the line position, text and glyph attributes to the screen text-line
 * renderer. */
void DrawScreenText(M2C_UNK x, M2C_UNK y, M2C_UNK palette, M2C_UNK text, u16 attr, u16 tile) {
    M2C_UNK DrawScreenTextLine(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    void *layer;

    layer = gCur3DSpriteEngine + (palette * 4);
    DrawScreenTextLine(x, y, palette, M2C_FIELD(layer, s32 *, DS3D_ENGINE_LAYER_VRAM), M2C_FIELD(layer, s32 *, DS3D_ENGINE_LAYER_TILES), text, (s32) attr, (s32) tile);
}

