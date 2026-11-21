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
    u8  flags;         /* +0x5C bit1 = pending redraw, bit3 = text stored */
    u8  filler_5D[3];
    void *sound;       /* +0x60 sound effect played on each glyph */
} TextState;

/* Advance a text object by one script step: interpret the next byte-code
 * command, lay out and draw its glyph into the current line's cell buffer, and
 * return 0 once the script is exhausted (1 means keep going). */
s32 DrawTextStep(void *arg0) {
    s32 PlaySoundEffect(void *);
    s32 func_02099818(u8, s32, u8, u16);
    M2C_UNK func_02099854(void *, s32, u8, u16);
    s32 func_020999b8(void *);
    s32 func_020999e8(void *);
    M2C_UNK func_02099a30(void *);
    s32 IsLeadByte(void *);
    s32 IsGlyphEscape(void *);
    u32 func_02099e6c(void *, s32);
    M2C_UNK func_0209ac6c(void *, s32);
    s32 func_0209c168(void *, s32);
    M2C_UNK func_0209c418(void *);
    TextState *st = arg0;
    s32 var_r6;
    s32 temp_r7;
    s32 temp_r8;
    void *notify;

main_loop:
    {
        u32 sw = func_02099e6c(st, func_020999e8(st));
        switch (sw) {
        case 0:
            return 0;
        case 3:
            if ((s8) st->delay < 0) goto end_block;
            return 1;
        case 2:
            if (func_020999b8(st) != 0) goto end_block;
            return 1;
        default:
        case 1:
            temp_r7 = IsLeadByte(st->cursor);
            temp_r8 = IsGlyphEscape(st->cursor);
            if (func_020999b8(st) == 0) {
                if (st->flags & 0x2) {
                    func_02099a30(st);
                    st->flags = (u8) (st->flags & ~0x2);
                    return 1;
                }
                if (!(st->cellX == st->lineX && st->column == 0)) {
                    func_0209c168(st, 1);
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
                        var_r6 = func_02099818(M2C_FIELD(p, u8 *, 1), pixels + (t1 << 5), st->column, st->attr16);
                    } else {
                        u16 t1 = st->linePixel;
                        pixels = M2C_FIELD(st, volatile s32 *, 0x3c);
                        var_r6 = func_02099818(M2C_FIELD(p, u8 *, 0), pixels + (t1 << 5), st->column, st->attr16);
                    }
                }
                if ((u8) st->column <= 1U) {
                    func_0209ac6c(st, func_020999e8(st));
                }
                if (func_0209c168(st, var_r6) != 0) {
                    func_0209ac6c(st, func_020999e8(st));
                }
                if ((notify = st->sound) != 0 && (s8) st->speed != 0) {
                    PlaySoundEffect(notify);
                }
            }
            if (!(temp_r7 == 0 && temp_r8 == 0)) {
                func_0209c418(st);
            }
            func_0209c418(st);
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
    s32 func_020952a4(void);
    s32 func_020953e8(void);
    s32 func_0209546c(void);
    void func_02095ff8(s8);
    s32 func_02096038(void);
    s32 HideAllScenePanels(void);
    s32 IsAnyScenePanelAnimating(void);
    s32 func_020999b8(void *);
    M2C_UNK StopTextObject(M2C_UNK);
    s32 DrawTextStep(void *);
    u32 func_0209dc9c(void);
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

    actionMask = func_0209dc9c();
    actionMask = actionMask | GetTextObjectTouchConfirm();
    actionMask = (u16)actionMask;

    if (st->flags & 0x1) {
        if (FindObjectByClass(&data_02102eac) != 0) return;
        if (FindObjectByClass(&data_02102e74) != 0) return;
        if (IsAnyScenePanelAnimating() != 0) return;
        if (func_020952a4() != 0) return;
        if (func_020953e8() != 0) return;
        if (func_0209546c() != 0) return;
    }

    if (st->speed >= 1 && func_02096038()) {
        if (actionMask & 0x400) func_02095ff8(1);
        if ((actionMask & 0x30) && st->linePixel != st->lineStart)
            StopTextObject((s32)st);
    }
    if (func_020999b8(st)) StopTextObject((s32)st);
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

void func_0209b084(void *entity) {
    s32 func_02095fe8(void);
    void func_02095ff8(s8);
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    void Clear3DSpriteLayer(u8);
    void func_02095fc0(void);
    void func_02097768(void);
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
    extern M2C_UNK data_02102eac, data_02102e74;

    s32 saved;
    s32 i;

    if (func_02095fe8() == 3) {
        func_02095ff8(0);
        if (func_02095fe8() == 2) {
            func_02095ff8(0);
        }
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

    if (!(M2C_FIELD(entity, u8 *, 0x5c) & 0x8)) goto skip8;
    func_02095fc0();
    func_02097768();
skip8:
    return;
}

void func_0209b190(M2C_UNK arg0) {
    M2C_UNK Sprite_ResumeAnimation(M2C_UNK);
    s32 IsAnyScenePanelAnimating();
    if (IsAnyScenePanelAnimating() != 0) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
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

void func_0209b26c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16);
    DrawTextLine(arg0, arg1, arg2, GetLocalizedText(arg3), arg4, arg5);
}

void DrawTextLine(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209b32c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);

    func_0209b32c(arg0, arg1, arg2, arg3, arg4, 0, arg5);
}

void func_0209b2dc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5, u16 arg6) {
    void func_0209b32c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);
    func_0209b32c(arg0, arg1, arg2, GetLocalizedText(arg3), arg4, arg5, arg6);
}

void func_0209b32c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5, u16 arg6) {
    M2C_UNK func_0209b370(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16, u16);
    extern s32 gCur3DSpriteEngine;
    void *temp_r6;

    temp_r6 = gCur3DSpriteEngine + (arg2 * 4);
    func_0209b370(arg0, arg1, arg2, M2C_FIELD(temp_r6, s32 *, 0xC), M2C_FIELD(temp_r6, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5, (s32) arg6);
}

#pragma opt_propagation on
M2C_UNK func_0209b370(M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 d,s32 e,s32 f,u16 g,u16 h,u16 i) {
M2C_UNK func_0209be10(s32,M2C_UNK,M2C_UNK,M2C_UNK,s32,s32,s32,u16,u16,u16);
M2C_UNK StopTextObject(s32);void *CreateSpriteFromClass(M2C_UNK *,s32);
extern s32 gCur3DSpriteEngine;extern M2C_UNK data_021032d8;
s32 p=gCur3DSpriteEngine;
p=M2C_FIELD(p,s32 *,0x54);
func_0209be10(p,a,b,c,d,e,f,g,h,i);
StopTextObject(p);CreateSpriteFromClass(&data_021032d8,7);
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

void ClearTextBitmap(M2C_UNK arg0, s32 arg1) {
    M2C_UNK MI_CpuFill32(M2C_UNK, M2C_UNK, s32);
    MI_CpuFill32(0, arg0, ((s32) (((s32) (arg1 + 7) >> 3) + 3) >> 2) << 8);
}

void RenderLocalizedTextToTiles(M2C_UNK arg0, M2C_UNK arg1) {
    s32 GetLocalizedText(M2C_UNK);
    M2C_UNK RenderTextToTiles(M2C_UNK, s32);
    RenderTextToTiles(arg0, GetLocalizedText(arg1));
}

/* Renders a text string into a temporary bitmap and splits it into the label
 * tile layout at the destination; returns the text's width in pixels. */
s32 RenderTextToTiles(s32 destination, s32 text) {
    s32 MeasureMessageLinesWidth(s32, M2C_UNK);
    s32 HeapAllocBlock(s32);
    void ClearTextBitmap(M2C_UNK, s32);
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
void func_0209b8c0(void *arg0) {
    void SplitTextBitmapHalves(s32, s32, u16);
    M2C_UNK HeapFreeBlock(s32);
    SplitTextBitmapHalves(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), (u16) M2C_FIELD(arg0, s32 *, 0x3C));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x34));
}

void CreateTextBitmapSplitter(s32 arg0, s32 arg1, s32 arg2) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTextBitmapSplitterClass;
    void *temp_r0;

    temp_r0 = CreateSpriteFromClass(&gTextBitmapSplitterClass, 1);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
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
void func_0209bbd0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209bc18(M2C_UNK, M2C_UNK, s32, s32, u16, u16);
    M2C_UNK GetLocalizedText(M2C_UNK);

    func_0209bc18(arg0, arg1, arg2, GetLocalizedText(arg3), arg4, arg5);
}

void func_0209bc18(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5) {
    M2C_UNK DrawScreenTextLine(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    void *temp_r5;

    temp_r5 = gCur3DSpriteEngine + (arg2 * 4);
    DrawScreenTextLine(arg0, arg1, arg2, M2C_FIELD(temp_r5, s32 *, 0xC), M2C_FIELD(temp_r5, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5);
}

