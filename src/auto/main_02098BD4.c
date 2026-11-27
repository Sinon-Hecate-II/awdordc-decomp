/* 52 functions from 0x02098BD4 to 0x02099B18 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

/* The text-object fields this file touches (TextState in main_0209ACC4.c). */
typedef struct TextStateCells {
    u8 filler_00[0x40];
    u16 *cells;             /* +0x40 glyph cell buffer base */
    u8 filler_44[4];
    u8 lineX;               /* +0x48 first cell x of the text area */
    u8 lineY;               /* +0x49 first cell y of the text area */
    u8 filler_4A[6];
    void (*callback)(void); /* +0x50 redraw callback */
    u8 filler_54[4];
    u8 width;               /* +0x58 widest line, in cells */
    u8 height;              /* +0x59 number of lines */
} TextStateCells;

/* Four glyph pixels expanded to 8 bits each: `word` shifts them by one pixel
 * per 4 bits, `half` is the two tilemap entries one row writes. */
typedef union { u32 word; u16 half[2]; u8 byte[4]; } GlyphPixelWord;

typedef struct { s32 values[12]; } Unk02098BD4Table;
extern Unk02098BD4Table data_020f36bc;

/* The fields of a text object (TextState, main_0209ACC4.c) that RedrawTextObject
 * uses: its glyph cell buffer and the line rectangle it redraws. */
typedef struct TextObjectRect {
    u8  filler_00[0x40];
    u16 *cells;           /* +0x40 glyph cell buffer the line is drawn into */
    u8  filler_44[4];
    u8  lineX;            /* +0x48 first cell column of the line */
    u8  lineY;            /* +0x49 first cell row of the line */
    u8  filler_4A[6];
    void (*redraw)(void); /* +0x50 redraw callback */
    u8  filler_54[4];
    u8  width;            /* +0x58 cell columns to clear */
    u8  height;           /* +0x59 cell rows to clear */
} TextObjectRect;

/* The fields of a text object (TextState, main_0209ACC4.c) that this file uses. */
typedef struct TextState0209 {
    u8 filler_00[0x40];
    u16 *cells;             /* +0x40 glyph cell buffer base */
    u16 baseAttr;           /* +0x44 attribute OR-ed into every cell */
    u16 attr16;             /* +0x46 attribute handed to the glyph draw call */
    u8  lineX;              /* +0x48 first cell x of the line */
    u8  lineY;              /* +0x49 first cell y of the line */
    u8  cellX;              /* +0x4A current cell x offset in the line */
    u8  cellY;              /* +0x4B current cell y offset in the line */
    u16 linePixel;          /* +0x4C pixel offset of the current line */
    u16 lineStart;          /* +0x4E pixel offset the line starts at */
    void (*callback)(void); /* +0x50 redraw callback */
    s8  delay;              /* +0x54 frames left before the next step */
    s8  speed;              /* +0x55 frames per step */
    u8  column;             /* +0x56 pixel offset inside the current cell (0..7) */
    s8  palette;            /* +0x57 glyph palette */
    u8  width;              /* +0x58 tile width of the line */
    u8  height;             /* +0x59 tile height of the line */
    u8  filler_5A[2];
    u8  flags;              /* +0x5C TEXT_FLAG_* */
} TextState0209;
/* TextState0209.flags bits. */
#define TEXT_FLAG_PENDING_REDRAW 0x02 /* set: clear and redraw the line on the next step */

/* Indexes the CO face layout table by expression (0..11, in three-step groups)
 * and by the face's variant flag, and returns the face tile record chosen. */
s32 GetFaceTileRecord(M2C_UNK expr, u8 variant) {
Unk02098BD4Table table=data_020f36bc;
s32 i=0;
switch(expr) {
case 0: i=0; break;
case 1: i=2; break;
case 2: i=4; break;
case 3: i=4; break;
case 4: i=4; break;
case 5: i=6; break;
case 6: i=6; break;
case 7: i=6; break;
case 8: i=8; break;
case 9: i=8; break;
case 10: i=8; break;
case 11: i=10; break;
}
if(variant) i++;
return table.values[i];
}

/* Add one tile of a CO face as a 3D sprite at (x, y): the tile record comes from
 * the face table row chosen by `expr` and `variant`, `tile` is the packed OBJ
 * tile/palette word and `priority` the OBJ priority. */
void AddFaceSpriteTile(s32 expr,s32 x,u32 y,M2C_UNK tile,u8 variant,s32 priority) {
M2C_UNK AddSprite(u16,u8,M2C_UNK,s32,s32);
s32 faceTemplate=GetFaceTileRecord(expr,variant);
y=(u8)y;
x &= DS3D_OBJ_X_MASK;
AddSprite((u16)x,y,tile,faceTemplate,priority);
}

/* Load CO face `faceId`'s texture graphics from the face archive into `dest`:
 * skip unknown face ids, then open sFaceNarcName and decompress the localized
 * sFaceTextureName file to the destination. */
M2C_UNK LoadFaceTextureGfx(M2C_UNK faceId, s32 dest) {
    M2C_UNK SetFileDirectory();
    M2C_UNK OpenNarcArchive(M2C_UNK *);
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    s32 GetFaceTexturePath(M2C_UNK);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern M2C_UNK sFaceNarcName, sFaceTextureName;
    if (GetFaceTexturePath(faceId) == 0) return;
    SetFileDirectory();
    OpenNarcArchive(&sFaceNarcName);
    LoadNarcFileDecompressed(GetLocalizedFileName(&sFaceTextureName), dest);
    CloseNarcArchive();
}

/* Load CO face `faceId`'s 16-colour palette into the current 3D sprite engine's
 * sprite palette slot `paletteSlot`: skip unknown face ids, then read
 * sFacePaletteName's palette and copy it into the engine's palette buffer. */
M2C_UNK LoadFacePaletteToSpriteBuffer(M2C_UNK faceId, u16 paletteSlot) {
    M2C_UNK SetFileDirectory();
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, s32, M2C_UNK);
    s32 GetFaceTexturePath(M2C_UNK);
    extern M2C_UNK sFacePaletteName;
    if (GetFaceTexturePath(faceId) == 0) return;
    SetFileDirectory();
    LoadFileToSpriteBuffer(&sFacePaletteName, paletteSlot << DS3D_PALETTE_SHIFT, DS3D_PALETTE_BYTES);
}

/* Load CO face `faceId`'s texture graphics into the current 3D sprite engine's
 * texture area at byte offset `textureOffset`, and its palette into engine OBJ
 * palette slot `paletteSlot`. */
void LoadFaceTextureAndPalette(s32 faceId, s32 textureOffset, s32 paletteSlot) {
    M2C_UNK LoadFaceTextureGfx(s32, s32);
    M2C_UNK LoadFacePaletteToSpriteBuffer(s32, u16);
    extern void *gCur3DSpriteEngine;
    LoadFaceTextureGfx(faceId, M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_TEXTURE) + textureOffset);
    LoadFacePaletteToSpriteBuffer(faceId, (u16) (paletteSlot + DS3D_OBJ_PALETTE_BASE));
}

M2C_UNK *GetFaceSpriteTemplate(void) {
    extern M2C_UNK data_020f3650;
    return &data_020f3650;
}

/* Add a CO face sprite using the shared face template, with the supplied position, tile, and priority. */
void AddFaceSprite(s32 x, s32 y, M2C_UNK tile, s32 priority) {
    M2C_UNK AddSprite(u16, u8, M2C_UNK, s32, s32);
    s32 faceTemplate = (s32)GetFaceSpriteTemplate();

    y = (u8)y;
    x &= 0x1FF;
    AddSprite((u16)x, y, tile, faceTemplate, priority);
}

/* Set a linked face child's texture offset and face palette row: `textureOffset`
 * is a byte offset into the face texture (stored in 32-byte blocks) and `tileRow`
 * picks the row of the face's 16-colour palette; the child is left hidden until
 * the face is drawn again. */
void SetFaceChildTextureRow(void *child, u32 textureOffset, s32 tileRow) {
    M2C_UNK Hide3DSprite(void *);
    M2C_FIELD(child, s16 *, FACE_SPRITE_TEXTURE) = (s16) (textureOffset >> 5);
    M2C_FIELD(child, s32 *, FACE_SPRITE_TILE) = (s32) ((M2C_FIELD(child, s32 *, FACE_SPRITE_TILE) & ~FACE_SPRITE_TILE_ROW_MASK) | ((u32) (tileRow << 0x18) >> 6));
    Hide3DSprite(child);
}

u8 IsFaceSpriteLoaded(void *);
/* Assigns face id `faceId` to a CO face sprite: resets its tile row and quad
 * template and, when a face is loaded, reloads its texture and palette on every
 * display engine it targets. */
void SetFaceSpriteFace(void *face, s32 faceId) {
extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
void *oldEngine; void *engine; s32 bank; u32 screen;
M2C_FIELD(face,u8*,FACE_SPRITE_FACE)=faceId;
M2C_FIELD(face,u8*,FACE_SPRITE_TILE_ROW)=3;
M2C_FIELD(face,M2C_UNK **,DS3D_SPRITE_TEMPLATE)=GetFaceSpriteTemplate();
if (!IsFaceSpriteLoaded(face)) return;
oldEngine=gCur3DSpriteEngine; bank=0;
do {
if(bank==0) engine=g3DSpriteEngineMain; else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
screen=((u32)M2C_FIELD(face,u8*,FACE_SPRITE_SCREEN)<<28)>>29;
if ((screen!=0 || engine==g3DSpriteEngineMain) && (screen!=1 || engine==g3DSpriteEngineSub) && (screen!=3 || engine==oldEngine))
LoadFaceTextureAndPalette(faceId,M2C_FIELD(face,u16*,0x3e)<<5,(u16)((M2C_FIELD(face,u32*,FACE_SPRITE_TILE)<<6)>>24));
bank += 1;
} while(bank<2);
gCur3DSpriteEngine=oldEngine;
}

void SetFaceSpriteExpression(void *arg0, u8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x59) = arg1;
}

/* Reload the palette of the face sprite's texture on every display engine it
 * is drawn on and, when no expression is set, darken its 32 colours by 6 steps. */
void RefreshFaceSpritePalette(void *face) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    M2C_UNK LoadFacePalette(M2C_UNK, u16);
    u8 IsFaceSpriteLoaded(void *);
    M2C_UNK FadePaletteTowardsBlack(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void *savedEngine;
    s32 bank;
    void *engine;
    u32 screen;
    s32 zero = 0;
    s32 steps = 10;

    if (!IsFaceSpriteLoaded(face)) return;
    savedEngine = gCur3DSpriteEngine;
    bank = 0;
    do {
        if (bank == 0) engine = g3DSpriteEngineMain; else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        screen = (u32)(M2C_FIELD(face, u8 *, FACE_SPRITE_SCREEN) << 28) >> 29;
        if (((screen != 0) || (engine == g3DSpriteEngineMain)) &&
            ((screen != 1) || (engine == g3DSpriteEngineSub)) &&
            ((screen != 3) || (engine == savedEngine))) {
            LoadFacePalette((M2C_UNK)M2C_FIELD(face, u8 *, FACE_SPRITE_FACE),
                (u16)(((M2C_FIELD(face, u32 *, FACE_SPRITE_TILE) << 6) >> 24) + 0x10));
            if (M2C_FIELD(face, u8 *, FACE_SPRITE_EXPRESSION) == 0) {
                FadePaletteTowardsBlack(
                    (M2C_UNK)(M2C_FIELD(gCur3DSpriteEngine, M2C_UNK *, 0x30) +
                        ((((M2C_FIELD(face, u32 *, FACE_SPRITE_TILE) << 6) >> 24) + 0x10) << 5 & ~1)),
                    zero, steps, 6);
            }
        }
        bank++;
    } while (bank < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Whether the CO face sprite has a face loaded (FACE_SPRITE_FACE is nonzero). */
u8 IsFaceSpriteLoaded(void *face) {
    u8 loaded;

    if (M2C_FIELD(face, u8 *, FACE_SPRITE_FACE) != 0) {
        loaded = 1;
    } else {
        loaded = 0;
    }
    return loaded;
}

M2C_UNK func_0209902c(void *arg0) {
 M2C_FIELD(arg0,s8 *,0x58)=0;
 M2C_FIELD(arg0,s8 *,0x59)=1;
}

/* Per-frame update of a CO face sprite: once a face is loaded, advance its fade
 * and slide animations and draw the actor. */
M2C_UNK UpdateFaceSprite(void *face) {
 void UpdateSpriteFade(void *);
 void UpdateSpriteSlide(void *);
 void DrawSpriteActor(void *);
 if(IsFaceSpriteLoaded(face)==0) return;
 UpdateSpriteFade(face);
 UpdateSpriteSlide(face);
 DrawSpriteActor(face);
}

void func_02099070(void) {
    M2C_UNK func_0209902c();
    func_0209902c();
}

void func_0209907c(void) {
    M2C_UNK UpdateFaceSprite();
    UpdateFaceSprite();
}

/* Create the linked face-child object (the sprite FACE_SPRITE_CHILD points at,
 * refreshed with its parent face) from gFaceChildSpriteClass, defaulting the layer
 * to 7, and install its vtable.  Returns the new sprite, or NULL. */
void **CreateFaceChildSprite(s32 layer) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK gFaceChildSpriteClass, gFaceChildSpriteVtbl;
    void **result;
    if (layer == 0) layer = 7;
    result = CreateSpriteFromClass(&gFaceChildSpriteClass, layer);
    if (result != 0) {
        Init3DSpriteActor();
        *result = &gFaceChildSpriteVtbl;
    }
    return result;
}

void DeleteAllFaceChildren(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gFaceChildSpriteClass;
    DeleteSpriteObjectsOfClass(&gFaceChildSpriteClass);
}

/* Point a CO face sprite at graphics row `textureOffset` (in 32-unit steps) of
 * its texture and at OBJ palette row `paletteRow`, then hide it so the change
 * takes effect on the next draw. */
void SetFaceSpriteTextureRow(void *face, u32 textureOffset, s32 paletteRow) {
    M2C_UNK Hide3DSprite();
    M2C_FIELD(face, s16 *, SPRITE_ACTOR_TILE_ROW) = (s16) (textureOffset >> 5);
    M2C_FIELD(face, s32 *, SPRITE_ACTOR_PALETTE) = (s32) ((M2C_FIELD(face, s32 *, SPRITE_ACTOR_PALETTE) & ~SPRITE_ACTOR_PALETTE_MASK) | ((u32) (paletteRow << 0x18) >> 6));
    Hide3DSprite();
}

void SetFaceSpritePose(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
u8 func_02097ce4(s32);
u8 func_02099320(void *);
void func_020985b0(s32, s32, s32);
void func_02098e2c(void *, s32);
void func_02099204(void *);
extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;

void *old; void *v; s32 i; u32 mode;
M2C_FIELD(arg0, u8 *, 0x58) = (u8)arg1;
M2C_FIELD(arg0, u8 *, 0x59) = (u8)arg2;
M2C_FIELD(arg0, u8 *, 0x49) = func_02097ce4(M2C_FIELD(arg0,u8*,0x58));
if (func_02099320(arg0)) {
old = gCur3DSpriteEngine;
i = 0;
do {
if (i == 0) v = data_027e00c8; else v = data_027e00c4;
gCur3DSpriteEngine = v;
mode = ((u32)M2C_FIELD(arg0, u8 *, 0x48) << 28) >> 29;
if ((mode != 0 || v == data_027e00c8) &&
(mode != 1 || v == data_027e00c4) &&
(mode != 3 || v == old)) {
func_020985b0(arg1, arg2, M2C_FIELD(v, s32 *, 0x1C) + (M2C_FIELD(arg0, u16 *, 0x3e) << 5));
}
i++;
} while (i < 2);
gCur3DSpriteEngine = old;
}
if (arg3) {
func_02098e2c(M2C_FIELD(arg0, void **, 0x60), arg1);
}
func_02099204(arg0);
}

void SetFaceSpriteActive(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5C) = arg1;
}

void SetFaceSpritePalette(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5D) = arg1;
}

/* Reloads a CO face sprite's palette on every engine it targets, choosing the
 * palette effects from whether the face is active and its palette style, then
 * refreshes its linked face object. */
void RefreshFaceSprite(void *p) {
u8 FaceSpriteIsLoaded(void *);void LoadFacePaletteAt(s32,s32,u16,u8);void SetFaceSpriteExpression(void *,u8);void RefreshFaceSpritePalette(void *);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*g3DSpriteEngineMain;
register void **engine;register u8 effects;register void *old;register s32 i;void *v;u32 mode;
if(FaceSpriteIsLoaded(p)){
engine=&gCur3DSpriteEngine;
effects=0;
if(M2C_FIELD(p,u8 *,FACE_SPRITE_ACTIVE)==0)effects|=FACE_EFFECT_DIM;
old=*engine;
if(M2C_FIELD(p,u8 *,FACE_SPRITE_PALETTE)==1)effects|=FACE_EFFECT_SEPIA;
if(M2C_FIELD(p,u8 *,FACE_SPRITE_PALETTE)==2)effects|=FACE_EFFECT_GRAY;
i=0;do{
if(i==0)v=g3DSpriteEngineMain;else v=g3DSpriteEngineSub;
*engine=v;mode=(u32)(M2C_FIELD(p,u8 *,FACE_SPRITE_SCREEN)<<28)>>29;
if((mode!=0 || v==g3DSpriteEngineMain)&&(mode!=1 || v==g3DSpriteEngineSub)&&(mode!=3 || v==old))
LoadFacePaletteAt(M2C_FIELD(p,u8 *,FACE_SPRITE_FACE),M2C_FIELD(p,u8 *,FACE_SPRITE_EXPRESSION),(u16)((M2C_FIELD(p,u32 *,FACE_SPRITE_TILE)<<6)>>24),effects);
i++;
}while(i<2);
gCur3DSpriteEngine=old;
}
if(M2C_FIELD(p,void **,FACE_SPRITE_CHILD)){SetFaceSpriteExpression(M2C_FIELD(p,void **,FACE_SPRITE_CHILD),M2C_FIELD(p,u8 *,FACE_SPRITE_ACTIVE));RefreshFaceSpritePalette(M2C_FIELD(p,void **,FACE_SPRITE_CHILD));}
}

void SetFaceSpriteLayout(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5A) = arg1;
}

void SetFaceSpriteVariant(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5B) = arg1;
}

/* Whether the CO face sprite has a face loaded (FACE_SPRITE_FACE is nonzero);
 * the copy the face refresh and draw helpers use. */
u8 FaceSpriteIsLoaded(void *face) {
    u8 loaded;

    if (M2C_FIELD(face, u8 *, FACE_SPRITE_FACE) != 0) {
        loaded = 1;
    } else {
        loaded = 0;
    }
    return loaded;
}

/* Reset a CO face sprite to its blank state (no face, expression, layout or
 * variant, default palette style), mark it active and create its linked face
 * child object. */
M2C_UNK InitFaceSprite(void *face) {
    M2C_FIELD(face, s8 *, FACE_SPRITE_FACE) = 0;
    M2C_FIELD(face, s8 *, FACE_SPRITE_EXPRESSION) = 0;
    M2C_FIELD(face, s8 *, FACE_SPRITE_LAYOUT) = 0;
    M2C_FIELD(face, s8 *, FACE_SPRITE_VARIANT) = 0;
    M2C_FIELD(face, s8 *, FACE_SPRITE_ACTIVE) = 1;
    M2C_FIELD(face, s8 *, FACE_SPRITE_PALETTE) = 0;
    M2C_FIELD(face, void **, FACE_SPRITE_CHILD) = CreateFaceChildSprite((s32)face);
}

/* Draw a CO face sprite: pick its face tile row from its expression and variant,
 * advance its fade and slide animations, then draw it at its own position. */
M2C_UNK DrawFaceSprite(void *face){
 void UpdateSpriteFade(void*);void UpdateSpriteSlide(void*);
 s32 GetFaceTileRecord(M2C_UNK,u8);
 void DrawSpriteActorAt(void*,s32,s32,s32,s32);
 s32 record;if(!FaceSpriteIsLoaded(face))return;
 record=GetFaceTileRecord(M2C_FIELD(face,u8*,FACE_SPRITE_EXPRESSION),M2C_FIELD(face,u8*,FACE_SPRITE_VARIANT));
 UpdateSpriteFade(face);UpdateSpriteSlide(face);
 DrawSpriteActorAt(face,M2C_FIELD(face,s16*,0x34),M2C_FIELD(face,s16*,0x36),M2C_FIELD(face,s8*,FACE_SPRITE_TILE_ROW),record);
}

void func_020993bc(void) {
    M2C_UNK InitFaceSprite();
    InitFaceSprite();
}

void func_020993c8(void) {
    M2C_UNK DrawFaceSprite();
    DrawFaceSprite();
}

/* Create a CO face sprite owned by `owner` (a parent sprite or a layer index; 7
 * when none is given): build it from the face sprite class, then initialise its
 * 3D sprite actor and install the face-sprite vtable. */
void **CreateFaceSprite(s32 owner) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK gFaceSpriteClass, gFaceSpriteVtbl;
    void **result;
    if (owner == 0) owner = 7;
    result = CreateSpriteFromClass(&gFaceSpriteClass, owner);
    if (result != 0) {
        Init3DSpriteActor();
        *result = &gFaceSpriteVtbl;
    }
    return result;
}

void DeleteAllFaceSprites(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gFaceSpriteClass;
    DeleteSpriteObjectsOfClass(&gFaceSpriteClass);
}

void func_02099420(void) {

}

s32 func_02099424(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_02099438(void) {

}

s32 func_0209943c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Set up the current engine's text on `layer`: forget the cached strings, start
 * the next string at tile `baseTile` + TEXT_FIRST_TILE, and copy glyph tile set
 * `tileSet` (TEXT_GLYPH_TILES bytes) into the layer from tile `baseTile` + 16. */
M2C_UNK InitTextTiles(s32 layer, s32 baseTile, s32 tileSet) {
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gTextGlyphTiles0, gTextGlyphTiles1;
    void MI_CpuCopy32(void *, void *, s32);
    void *text = M2C_FIELD(gCur3DSpriteEngine, void **, DS3D_ENGINE_TEXT_CACHE);
    M2C_FIELD(text, u16 *, TEXT_CACHE_NEXT_TILE) = baseTile + TEXT_FIRST_TILE;
    M2C_FIELD(text, u8 *, TEXT_CACHE_EMPTY) = 1;
    M2C_FIELD(text, u8 *, TEXT_CACHE_LAYER) = layer;
    switch (tileSet) {
    case 0:
        MI_CpuCopy32(&gTextGlyphTiles0, (u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine + layer * 4, void **, 12) + ((baseTile + TEXT_GLYPH_OFFSET) << 5), TEXT_GLYPH_TILES);
        break;
    case 1:
        MI_CpuCopy32(&gTextGlyphTiles1, (u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine + layer * 4, void **, 12) + ((baseTile + TEXT_GLYPH_OFFSET) << 5), TEXT_GLYPH_TILES);
        break;
    }
}

/* Reset the text layer of the current 3D sprite engine to the default glyph
 * tile set, starting the next cached string at tile `baseTile` + TEXT_FIRST_TILE. */
void ResetTextTiles(s32 baseTile) {
    M2C_UNK InitTextTiles(s32, s32, s32);
    InitTextTiles(TEXT_GLYPH_LAYER, baseTile, TEXT_GLYPH_SET_DEFAULT);
}

/* Fill two tilemap rows for a cached glyph string, alternating even and odd tile IDs across the rows. */
void WriteCachedGlyphTilemap(u16 *tilemap, s32 firstTile, s32 tileCount) {
    s32 column = 0;
    if (tileCount <= 0) return;
    {
        s32 evenTile = firstTile;
        s32 oddTileOffset = 1;
        do {
            tilemap[column] = (u16)evenTile;
            tilemap[column + 32] = (u16)(firstTile + oddTileOffset);
            column++;
            evenTile += 2;
            oddTileOffset += 2;
        } while (column < tileCount);
    }
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 DrawCachedTextToTilemap(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    extern void *gCur3DSpriteEngine;
    s32 StringCompare(void *, void *);
    s32 StringLength(M2C_UNK);
    void StringCopy(M2C_UNK, M2C_UNK);
    s32 func_0209b370(s32, s32, s32, s32, s32, s32, u16, u16, u16);
    void WriteCachedGlyphTilemap(u16 *, s32, s32);
    s32 MeasureStringWidth(M2C_UNK);

    register void *obj;
    register s32 cursor;
    register s32 idx;
    register void *engine;
    u16 u;
    u8 byte2;
    u8 byte302;
    s32 engineEntry;
    s32 funcResult;
    register s32 width;
    register s32 cur300;
    s32 len;
    s32 end;

    engine = gCur3DSpriteEngine;
    obj = M2C_FIELD(engine, void **, 0x50);

    if (arg3 == 0 || *(u8 *)arg3 == 0) return -1;
    cursor = 0;
    idx = 0;
    if (*(u8 *)obj != 1) {
        for (;;) {
            if (*((u8 *)obj + idx * 4 + 0x203) == arg5) {
                if (StringCompare((void *)((u8 *)obj + cursor), (void *)arg3) == 0) {
                    u = *(u16 *)((u8 *)obj + idx * 4 + 0x200);
                    byte2 = *((u8 *)obj + idx * 4 + 0x202);
                    WriteCachedGlyphTilemap((u16 *)(arg2 + arg0 * 2 + arg1 * 64),
                                 (u16)(arg4 + u), byte2);
                    return idx;
                }
            }
            len = StringLength((M2C_UNK)((u8 *)obj + cursor));
            cursor = cursor + len + 1;
            idx++;
            if (*((u8 *)obj + cursor) == 1) break;
        }
    }

    byte302 = *((u8 *)obj + 0x302);
    engineEntry = *(s32 *)((u8 *)engine + (byte302 * 4) + 0x0C);

    func_0209b370((s32)(s16)arg0, (s32)(s16)arg1, 4, engineEntry,
                   arg2, (s32)arg3, (u16)arg4, (u16)arg5, *(u16 *)((u8 *)obj + 0x300));

    funcResult = MeasureStringWidth(arg3);
    width = (funcResult + 7) >> 3;
    arg0 = *(u16 *)((u8 *)obj + 0x300);

    cur300 = arg0;
    *(u16 *)((u8 *)obj + idx * 4 + 0x200) = cur300;
    *((u8 *)obj + idx * 4 + 0x202) = (u8)width;
    *((u8 *)obj + idx * 4 + 0x203) = (u8)arg5;

    *(u16 *)((u8 *)obj + 0x300) = (u16)(*(u16 *)((u8 *)obj + 0x300) + width * 2);

    StringCopy((M2C_UNK)((u8 *)obj + cursor), (M2C_UNK)arg3);

    len = StringLength((M2C_UNK)arg3);
    end = cursor + len + 1;
    *((u8 *)obj + end) = 1;

    return idx;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
/* Draw one 16-pixel-tall glyph of `width` 4bpp pixels (two pixels per byte of
 * glyphBitmap) into the 4bpp tilemap `tilemap`, shifted right by `shift` pixels
 * and with `palette` added to every nonzero pixel; a glyph that runs past the
 * eight-pixel cell also writes the neighbouring tile.  Returns the width. */
s32 DrawGlyphTiles(s32 glyphBitmap,u8 width,M2C_UNK tilemap,M2C_UNK shift,s32 palette) {
u8 *src=(u8 *)glyphBitmap;u16 *dst=(u16 *)tilemap;
GlyphPixelWord buf[2];u16 *out; s32 clear,offset; s32 shiftLeft,shiftRight,row,col,byteCount;u32 pixelByte;u8 byte;u8 *p;
shift&=7;
if(shift<=1){for(clear=0;clear<32;clear++)dst[clear]=0;}
if(shift+width>8){offset=((shift+width)&8)<<2;for(clear=0;clear<32;clear++)dst[clear+offset]=0;}
if(width!=0){
byteCount=(width+1)>>1;shiftLeft=shift*4;shiftRight=(8-shift)*4;
for(row=0;row<16;row++){
buf[1].word=0;buf[0].word=0;
for(col=0;col<byteCount;col++){
pixelByte=*src;
if(pixelByte&15)pixelByte+=palette;
src=src+1;
if(pixelByte&240)pixelByte+=palette<<4;
buf[0].byte[col]=buf[1].byte[col]=pixelByte;
}
buf[0].word<<=shiftLeft;
dst[0]|=buf[0].half[0];dst[1]|=buf[0].half[1];
buf[1].word>>=shiftRight;
if(buf[1].word){dst[32]|=buf[1].half[0];dst[33]|=buf[1].half[1];}
dst+=2;
}
}
return width;
}
#pragma scheduling on
/* Draw the glyph for byte value `glyph` into the 4bpp tilemap `tilemap`, shifted
 * right by `shift` pixels and using palette number `palette`, and return the
 * glyph's pixel advance.  The bitmap and advance come from the shared glyph
 * tables indexed by the byte value. */
u8 DrawGlyph(s32 glyph, s32 tilemap, s32 shift, s32 palette) {
    M2C_UNK DrawGlyphTiles(s32, u8, M2C_UNK, M2C_UNK, s32);
    DrawGlyphTiles(gGlyphBitmapTable[glyph], gGlyphWidthTable[glyph], tilemap, shift, palette);
    return gGlyphWidthTable[glyph];
}

#pragma opt_common_subs off
void func_02099854(void *arg0,s32 arg1,s32 arg2,s32 arg3){

extern u8 data_0211dcf0[];
u16 *dst; s32 row,offset,col; u16 *src; u16 a=arg3*16,b=a*16,c=b*16,t,x,y,z,w;u8 key,index;void *node;
key=M2C_FIELD(arg0,u8 *,0);index=M2C_FIELD(arg0,u8 *,1);
if(index<0x40U){key=0x96;index=0xb2;}
retry:
node=M2C_FIELD(data_0211dcf0+index*4,void **,-0x100);
if(node!=0){
scan:
if(M2C_FIELD(node,u8 *,4)!=key){
node=M2C_FIELD(node,void **,0);
if(node==0){key=0x81;index=0x48;goto retry;}
if(node!=0)goto scan;
}}
if(node==0){key=0x81;index=0x48;goto retry;}
src=node+6;
if(arg2){func_020996d0(src,7,arg1,arg2,arg3);return;}
for(row=0,offset=0;row<2;row++,offset+=32){
 dst=(u16 *)(arg1+offset);
 for(col=0;col<16;col++){t=*src;x=t&15;y=t&0xf0;z=t&0xf00;w=t&0xf000;
if(x)x+=arg3;
src++;
if(y)y+=a;if(z)z+=b;if(w)w+=c;
*dst++=w|(z|(x|y));
}
 }
}
#pragma opt_common_subs reset
/* Nonzero while a message box is active and this text object has been flagged
 * (flags bit 0) as waiting for it, so its text script must not advance. */
u8 IsTextWaitingForMessageBox(void *text) {
    s32 IsMessageBoxActive();
    u8 waiting;

    if (IsMessageBoxActive() == 0) {
        return 0U;
    }
    if (M2C_FIELD(text, u8 *, 0x5C) & 1) {
        waiting = 1;
    } else {
        waiting = 0;
    }
    return waiting;
}

/* Pointer to the text object's current glyph cell in its line cell buffer (the
 * cursor position); 0 when the object has no cell buffer. */
s32 GetTextCursorCell(TextState0209 *text) {
    u16 *cells = text->cells;
    s32 x, y;

    if (!cells) return 0;
    x = text->cellX;
    y = text->cellY;
    return (s32)(cells + x + (y << 5));
}

/* Pointer to the first glyph cell of the text object's current line in its line
 * cell buffer; 0 when the object has no cell buffer. */
u16 *GetTextLineStartCell(void *arg0) {
    TextState0209 *text = arg0;
    u16 *cells = text->cells;

    if (cells == 0) return 0;
    return cells + text->lineX + (text->lineY << 5);
}

/* Erase the text object's drawn cell area in its glyph cell buffer and invoke
 * its redraw callback. */
void RedrawTextObject(TextStateCells *text) {
 M2C_UNK ClearTileRect(s32,u8,u8);
 u16 *cells=text->cells;
 if(cells==0) return;
 ClearTileRect((s32)(cells+text->lineX+(text->lineY<<5)),text->width,text->height);
 text->callback();
}

/* Close the text object's current line: record how many cells it spans in the
 * object's width, then move the cursor back to the line's first column. */
M2C_UNK EndTextLine(TextState0209 *text) {
    register s32 cells = text->cellX - text->lineX + 2;
    if (text->width < cells) text->width = cells;
    text->cellX = text->lineX;
    text->column = 0;
}

/* Close the text object's current line vertically: record how many rows it spans
 * in the object's height, then move the cursor back to the line's first row. */
M2C_UNK EndTextLineRows(TextState0209 *text) {
    s32 rows = text->cellY - text->lineY + 2;

    if (text->height < rows) text->height = rows;
    text->cellY = text->lineY;
}

/* Close the text object's current line in both directions (record its width and
 * height, move the cursor back to the line's origin) and flag the line for redraw. */
void EndTextLineAndMarkRedraw(TextState0209 *text) {
    EndTextLine(text);
    EndTextLineRows(text);
    text->flags |= TEXT_FLAG_PENDING_REDRAW;
}

/* Whether `text` starts with a double-byte character's lead byte: the byte has
 * its high bit set, as the game's Shift-JIS text marks such characters. */
u8 IsLeadByte(u8 *text) {
    u8 lead;

    if (*text & 0x80) {
        lead = 1;
    } else {
        lead = 0;
    }
    return lead;
}

/* Whether `text` starts with the game-text escape (TEXT_ESCAPE_CHAR), whose next
 * byte is a raw glyph code rather than an encoded character. */
u8 IsGlyphEscape(u8 *text) {
    u8 escape;

    if (*text == TEXT_ESCAPE_CHAR) {
        escape = 1;
    } else {
        escape = 0;
    }
    return escape;
}

