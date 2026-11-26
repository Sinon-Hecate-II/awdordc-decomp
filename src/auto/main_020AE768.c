/* 26 functions from 0x020AE768 to 0x020AF760 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "gx.h"
static inline u16 SpriteTileSize(s32 n) { return n << 12; }

/* Apply the CO face palette style `style` in place to `palette` (`length` bytes):
 * FACE_PALETTE_SEPIA tints it warm, FACE_PALETTE_GRAY converts it to grayscale,
 * and FACE_PALETTE_NORMAL leaves it unchanged. */
void ApplyFacePaletteStyle(u8 style, M2C_UNK palette, s32 length) {
    M2C_UNK ApplySepiaToPalette(M2C_UNK, M2C_UNK);
    M2C_UNK ApplyGrayscaleToPalette(M2C_UNK, M2C_UNK);

    if (style == FACE_PALETTE_SEPIA) {
        ApplySepiaToPalette(palette, length);
    }
    if (style != FACE_PALETTE_GRAY) {
        return;
    }
    ApplyGrayscaleToPalette(palette, length);
}

#pragma opt_lifetimes off
void Set3DSpritePaletteColor(u32 a,u32 b,u16 c) {
extern void *gCur3DSpriteEngine;
u32 offset=a<<5;
u8 *tiles=M2C_FIELD(gCur3DSpriteEngine,u8 **,0x30);
offset &=~1;
a=b<<1;
b=(u32)(tiles+offset);
M2C_FIELD((void *)b,u16 *,a)=c;
}
#pragma opt_lifetimes reset
s32 GetWallpaperFileSet(s32 arg0) {
    extern M2C_UNK gWallpaperFileSets;
    return (0x14 * arg0) + (s32) &gWallpaperFileSets;
}

void func_020ae7ec(void *sprite);
void func_020ae7e0(void *sprite) {
    func_020ae7ec(sprite);
}

#pragma scheduling off
#pragma opt_lifetimes off
void func_020ae7ec(void *sprite) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    extern void *g3DSpriteBankMain;
    s32 Modulo(s32, s32);
    u8 period = M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), u8 *, 0xC);
    u8 main = gCur3DSpriteEngine == g3DSpriteEngineMain;
    u8 layer;
    s16 dx, dy;
    if (main) {
        if (period && !Modulo(M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_STATE), period)) {
            DS3D_BANK(gCur3DSpriteEngine)->corner[M2C_FIELD(sprite, u8 *, WALLPAPER_MAIN_LAYER)] = M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_A);
            M2C_FIELD((u8 *)DS3D_BANK(gCur3DSpriteEngine) + M2C_FIELD(sprite, u8 *, WALLPAPER_MAIN_LAYER) * 2, s16 *, 0x40) = M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_B);
            M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_A) += M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), s8 *, 0xD);
            if (M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_A) >= M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), u16 *, 6))
                M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_A) = 0;
            M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_B) += M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), s8 *, 0xE);
            if (M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_B) >= M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), u16 *, 8))
                M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_OFFSET_B) = 0;
        }
        layer = M2C_FIELD(sprite, u8 *, WALLPAPER_MAIN_LAYER);
        {
            void **engine = gCur3DSpriteEngine;
            DS3DSpriteEngine *offsetEngine = DS3D_ENGINE(g3DSpriteEngineMain);
            u16 x = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x38);
            u16 y = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x40);
            dx = x - offsetEngine->offsetX;
            dy = y - offsetEngine->offsetY;
        }
        switch (layer) {
        case 0:
            if (!((u8)((u32)(((DS3DSpriteBank *)g3DSpriteBankMain)->flags << 28) >> 31)))
                {u16 mask = 0x1ff; volatile u32 *reg = &REG_BG0OFS; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));}
            break;
        case 1: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04000014; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));} break;
        case 2: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04000018; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));} break;
        case 3: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x0400001C; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));} break;
        }
        M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_STATE)++;
        if (M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_STATE) >= 1024)
            M2C_FIELD(sprite, s16 *, WALLPAPER_MAIN_STATE) -= 1024;
    } else {
        if (period && !Modulo(M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_STATE), period)) {
            DS3D_BANK(gCur3DSpriteEngine)->corner[M2C_FIELD(sprite, u8 *, WALLPAPER_SUB_LAYER)] = M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_A);
            M2C_FIELD((u8 *)DS3D_BANK(gCur3DSpriteEngine) + M2C_FIELD(sprite, u8 *, WALLPAPER_SUB_LAYER) * 2, s16 *, 0x40) = M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_B);
            M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_A) += M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), s8 *, 0xD);
            if (M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_A) >= M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), u16 *, 6))
                M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_A) = 0;
            M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_B) += M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), s8 *, 0xE);
            if (M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_B) >= M2C_FIELD(M2C_FIELD(sprite, WallpaperFileSet **, WALLPAPER_FILE_SET), u16 *, 8))
                M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_OFFSET_B) = 0;
        }
        layer = M2C_FIELD(sprite, u8 *, WALLPAPER_SUB_LAYER);
        {
            void **engine = gCur3DSpriteEngine;
            DS3DSpriteEngine *offsetEngine = DS3D_ENGINE(g3DSpriteEngineSub);
            u16 x = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x38);
            u16 y = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x40);
            dx = x - offsetEngine->offsetX;
            dy = y - offsetEngine->offsetY;
        }
        switch (layer) {
        case 0: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04001010; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));} break;
        case 1: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04001014; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));} break;
        case 2: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04001018; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));} break;
        case 3: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x0400101C; u32 yMask = mask; yMask <<= 16; *reg = (mask & (u32)dx) | (yMask & ((u32)dy << 16));} break;
        }
        M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_STATE)++;
        if (M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_STATE) >= 1024)
            M2C_FIELD(sprite, s16 *, WALLPAPER_SUB_STATE) -= 1024;
    }
}
#pragma opt_lifetimes reset
#pragma scheduling reset
void LoadWallpaperGraphics(void *wallpaperSprite, s32 layerIndex, s32 paletteIndex) {
    M2C_UNK GetLanguage(void);
    M2C_UNK *GetLocalizedFileName(M2C_UNK *);
    void StringFormat(void *, void *, ...);
    void SetFileDirectory(void *);
    void Set3DSpriteLayerSize(s32, s32);
    void OpenNarcArchive(void *);
    void LoadNarcFileDecompressed(void *, s32);
    void LoadNarcFileRaw(void *, void *);
    s32 Get3DSpriteLayerSize(u8, s32);
    void OffsetTileIndices(void *, u16, u16);
    void CloseNarcArchive(void);
    extern void *gCur3DSpriteEngine;
    extern char sWallpaperDirectory[], sWallpaperNarcFormat[], sWallpaperCgFormat[], sWallpaperScFormat[], sWallpaperClFormat[];

    char fileNameBuffer[0x100];
    char filePathBuffer[0x100];

    /* Load this wallpaper's graphics and palette files into the current sprite layer. */
    if (GetLanguage() == 2 && *(u8 *)((char *)wallpaperSprite + 0x34) == 0) {
        StringFormat(fileNameBuffer, GetLocalizedFileName(*(void **)(*(void **)((char *)wallpaperSprite + 0x38))));
    } else {
        StringFormat(fileNameBuffer, *(void **)(*(void **)((char *)wallpaperSprite + 0x38)));
    }
    Set3DSpriteLayerSize(layerIndex, *(u8 *)((char *)*(void **)((char *)wallpaperSprite + 0x38) + 4));
    SetFileDirectory(sWallpaperDirectory);
    StringFormat(filePathBuffer, sWallpaperNarcFormat, fileNameBuffer);
    OpenNarcArchive(filePathBuffer);
    StringFormat(filePathBuffer, sWallpaperCgFormat, fileNameBuffer);
    LoadNarcFileDecompressed(filePathBuffer, *(s32 *)((char *)gCur3DSpriteEngine + layerIndex * 4 + 0xc));
    StringFormat(filePathBuffer, sWallpaperScFormat, fileNameBuffer);
    LoadNarcFileDecompressed(filePathBuffer, *(s32 *)((char *)gCur3DSpriteEngine + layerIndex * 4 + 0x20));
    StringFormat(filePathBuffer, sWallpaperClFormat, fileNameBuffer);
    LoadNarcFileRaw(filePathBuffer, (void *)((char *)*(void **)((char *)gCur3DSpriteEngine + 0x30) + (paletteIndex << 5)));
    {
        void *spriteBank = *(void **)gCur3DSpriteEngine;
        u8 bankMode = (u8)(((u32)(*(u16 *)spriteBank << 29)) >> 29);
        s32 layerTileCount = Get3DSpriteLayerSize(bankMode, layerIndex);
        s32 paletteOffset = SpriteTileSize(paletteIndex);
        u16 layerTileCount16 = layerTileCount;
        u16 paletteOffset16 = (u16)(paletteOffset & 0xffff);
        void *layerTileBuffer = *(void **)((char *)gCur3DSpriteEngine + layerIndex * 4 + 0x20);
        OffsetTileIndices(layerTileBuffer, layerTileCount16, paletteOffset16);
    }
    CloseNarcArchive();
    *(u8 *)((char *)gCur3DSpriteEngine + 0x46) |= 0x10;
    *(u8 *)((char *)gCur3DSpriteEngine + 0x46) |= 1 << layerIndex;
}
#pragma optimization_level 3
void CreateWallpaperSprites(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d, s32 e) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    extern M2C_UNK gWallpaperSpriteClass, gWallpaperSpriteVtbl;
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK GetWallpaperFileSet(s32);
    /* LoadWallpaperGraphics is defined above. */
    void **engine = &gCur3DSpriteEngine;
    void *saved = *engine;
    void *p;

    *engine = g3DSpriteEngineMain;
    p = CreateSpriteFromClass(&gWallpaperSpriteClass, 1);
    if (p) {
        void *saved2;
        M2C_FIELD(p, void **, 0) = &gWallpaperSpriteVtbl;
        M2C_FIELD(p, u8 *, 0x34) = e;
        M2C_FIELD(p, s32 *, 0x38) = GetWallpaperFileSet(e);
        M2C_FIELD(p, u8 *, 0x3c) = a;
        M2C_FIELD(p, u8 *, 0x3d) = b;
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x3e) = M2C_FIELD(q, s16 *, 0x10);
        }
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x40) = M2C_FIELD(q, s16 *, 0x12);
        }
        saved2 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        LoadWallpaperGraphics(p, a, b);
        gCur3DSpriteEngine = saved2;
        M2C_FIELD(p, s16 *, 0x42) = 0;
    }

    gCur3DSpriteEngine = g3DSpriteEngineSub;
    p = CreateSpriteFromClass(&gWallpaperSpriteClass, 1);
    if (p) {
        void *saved2;
        M2C_FIELD(p, void **, 0) = &gWallpaperSpriteVtbl;
        M2C_FIELD(p, u8 *, 0x34) = e;
        M2C_FIELD(p, s32 *, 0x38) = GetWallpaperFileSet(e);
        M2C_FIELD(p, u8 *, 0x44) = c;
        M2C_FIELD(p, u8 *, 0x45) = d;
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x46) = M2C_FIELD(q, s16 *, 0x10) + M2C_FIELD(q, s16 *, 0x0a);
        }
        {
            void *q = M2C_FIELD(p, void **, 0x38);
            M2C_FIELD(p, s16 *, 0x48) = M2C_FIELD(q, s16 *, 0x12) + M2C_FIELD(q, s16 *, 0x0a);
        }
        saved2 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineSub;
        LoadWallpaperGraphics(p, c, d);
        gCur3DSpriteEngine = saved2;
        M2C_FIELD(p, s16 *, 0x4a) = 0;
    }
    gCur3DSpriteEngine = saved;
}
#pragma optimization_level reset
/* Create the main-screen wallpaper sprite for wallpaper set `set` on sprite layer
 * `layer` with palette `palette`: take the set's two position offsets, then load
 * the set's graphics and palette into the sprite. */
void CreateMainWallpaperSprite(s32 layer,s32 palette,s32 set) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK gWallpaperSpriteClass,gWallpaperSpriteVtbl;
void *CreateSpriteFromClass(M2C_UNK *,s32);
void *saved=gCur3DSpriteEngine;
void *p;
gCur3DSpriteEngine=g3DSpriteEngineMain;
p=CreateSpriteFromClass(&gWallpaperSpriteClass,1);
if(p) {
void *saved2;
M2C_FIELD(p,void **,DS3D_SPRITE_CLASS)=&gWallpaperSpriteVtbl;
M2C_FIELD(p,u8 *,WALLPAPER_SET)=set;
M2C_FIELD(p,s32 *,WALLPAPER_FILE_SET)=GetWallpaperFileSet(set);
M2C_FIELD(p,u8 *,WALLPAPER_MAIN_LAYER)=layer;
M2C_FIELD(p,u8 *,WALLPAPER_MAIN_PALETTE)=palette;
M2C_FIELD(p,s16 *,WALLPAPER_MAIN_OFFSET_A)=((WallpaperFileSet *)M2C_FIELD(p,void **,WALLPAPER_FILE_SET))->offsetA;
M2C_FIELD(p,s16 *,WALLPAPER_MAIN_OFFSET_B)=((WallpaperFileSet *)M2C_FIELD(p,void **,WALLPAPER_FILE_SET))->offsetB;
saved2=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
LoadWallpaperGraphics(p,layer,palette);
gCur3DSpriteEngine=saved2;
M2C_FIELD(p,s16 *,WALLPAPER_MAIN_STATE)=0;
}
gCur3DSpriteEngine=saved;
}

/* Create the top-screen (sub engine) wallpaper sprite for wallpaper set `set` on
 * layer `layer` with palette `palette`: its two position offsets are the set's
 * reading offsets plus the set's second-screen gap. */
void CreateSubWallpaperSprite(s32 layer,s32 palette,s32 set) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;
extern M2C_UNK gWallpaperSpriteClass,gWallpaperSpriteVtbl;
void *CreateSpriteFromClass(M2C_UNK *,s32);
void *saved=gCur3DSpriteEngine; void *p;
gCur3DSpriteEngine=g3DSpriteEngineSub;
p=CreateSpriteFromClass(&gWallpaperSpriteClass,1);
if(p) {void *saved2;
M2C_FIELD(p,void **,DS3D_SPRITE_CLASS)=&gWallpaperSpriteVtbl;
M2C_FIELD(p,u8 *,0x34)=set;
M2C_FIELD(p,s32 *,0x38)=GetWallpaperFileSet(set);
M2C_FIELD(p,u8 *,0x44)=layer; M2C_FIELD(p,u8 *,0x45)=palette;
M2C_FIELD(p,s16 *,0x46)=M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0x10)+M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0xa);
M2C_FIELD(p,s16 *,0x48)=M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0x12)+M2C_FIELD(M2C_FIELD(p,void **,0x38),s16 *,0xa);
saved2=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineSub;
LoadWallpaperGraphics(p,layer,palette); gCur3DSpriteEngine=saved2;
M2C_FIELD(p,s16 *,0x4a)=0;
} gCur3DSpriteEngine=saved;
}

/* Create the wallpaper sprite on whichever 3D sprite engine is current: the main
 * engine's wallpaper sprite or the sub engine's. */
void CreateWallpaperSprite(M2C_UNK layer, M2C_UNK palette, s32 set) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    void CreateSubWallpaperSprite(M2C_UNK, M2C_UNK, s32);
    if ((u8)(gCur3DSpriteEngine == g3DSpriteEngineMain)) CreateMainWallpaperSprite(layer, palette, set);
    if ((u8)(gCur3DSpriteEngine == g3DSpriteEngineSub)) CreateSubWallpaperSprite(layer, palette, set);
}

/* Return the wallpaper set (index into gWallpaperFileSets) shown behind the
 * battle for the current map mode, the low three bits of gMapConfig. */
s32 GetMapModeWallpaperSet(void) {
    extern u16 gMapConfig;
    switch ((u32)(gMapConfig << 29) >> 29) {
    case 0:
        return 0;
    case 1:
        return 4;
    case 2:
        return 6;
    case 3:
        return 4;
    case 4:
    case 6:
    case 7:
        return 5;
    default:
        return 0;
    }
}

/* Create the main- and sub-screen wallpaper sprites for the current map mode:
 * both use the wallpaper set the map mode selector picks. */
void CreateMapModeWallpaperSprites(M2C_UNK mainLayer, M2C_UNK mainPalette, M2C_UNK subLayer, M2C_UNK subPalette) {
    s32 wallpaperSet = GetMapModeWallpaperSet();
    CreateWallpaperSprites(mainLayer, mainPalette, subLayer, subPalette, wallpaperSet);
}

/* Create the main-screen wallpaper sprite for the current map mode's wallpaper
 * set, on sprite layer `layer` with palette `palette`. */
void CreateMapModeMainWallpaperSprite(M2C_UNK layer, M2C_UNK palette) {
    s32 GetMapModeWallpaperSet();
    CreateMainWallpaperSprite(layer, palette, GetMapModeWallpaperSet());
}

/* Create the sub-screen wallpaper sprite for the current map mode's wallpaper
 * set, on sprite layer `layer` with palette `palette`. */
void CreateMapModeSubWallpaperSprite(M2C_UNK layer, M2C_UNK palette) {
    void CreateSubWallpaperSprite(s32, s32, s32);
    CreateSubWallpaperSprite(layer, palette, GetMapModeWallpaperSet());
}

/* Create the current map mode's wallpaper sprite on whichever 3D sprite engine is
 * current, on sprite layer `layer` with palette `palette`. */
void CreateMapModeWallpaperSprite(M2C_UNK layer, M2C_UNK palette) {
    CreateWallpaperSprite(layer, palette, GetMapModeWallpaperSet());
}

void DeleteWallpaperSpritesOnAllEngines(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gWallpaperSpriteClass;
    DeleteSpriteObjectsOfClass(&gWallpaperSpriteClass);
}

/* Delete every wallpaper sprite drawn on the main screen's engine: make the
 * main engine current, delete gWallpaperSpriteClass' objects there and restore
 * the previously current engine. */
void DeleteMainWallpaperSprites(void) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain;
    extern M2C_UNK gWallpaperSpriteClass;
    M2C_UNK DeleteSpriteObjectsOfClassOnCurrentEngine(M2C_UNK *);
    void *savedEngine = gCur3DSpriteEngine;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    DeleteSpriteObjectsOfClassOnCurrentEngine(&gWallpaperSpriteClass);
    gCur3DSpriteEngine = savedEngine;
}

void DeleteWallpaperSprites(void) {
    M2C_UNK DeleteSpriteObjectsOfClassOnCurrentEngine(M2C_UNK *);
    extern M2C_UNK gWallpaperSpriteClass;
    DeleteSpriteObjectsOfClassOnCurrentEngine(&gWallpaperSpriteClass);
}

#pragma opt_common_subs off
#pragma opt_propagation off
void func_020af244(void *sprite) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    extern void *g3DSpriteBankMain;
    s32 Modulo(s32, s32);
    u8 main = gCur3DSpriteEngine == g3DSpriteEngineMain;
    u8 layer;
    s16 dx, dy;
    if (main) {
        {
            s16 period = M2C_FIELD(sprite, s16 *, 0x3a);
            if (period && !Modulo(M2C_FIELD(sprite, s16 *, 0x42), period)) {
                M2C_FIELD((u8 *)DS3D_BANK(gCur3DSpriteEngine) + M2C_FIELD(sprite, u8 *, 0x34) * 2, s16 *, 0x38) = M2C_FIELD(sprite, s16 *, 0x36);
                M2C_FIELD(sprite, s16 *, 0x36) += M2C_FIELD(sprite, s16 *, 0x3c);
                if (M2C_FIELD(sprite, s16 *, 0x36) >= 256) M2C_FIELD(sprite, s16 *, 0x36) = 0;
            }
        }
        {
            s16 period = M2C_FIELD(sprite, s16 *, 0x3e);
            if (period && !Modulo(M2C_FIELD(sprite, s16 *, 0x42), period)) {
                M2C_FIELD((u8 *)DS3D_BANK(gCur3DSpriteEngine) + M2C_FIELD(sprite, u8 *, 0x34) * 2, s16 *, 0x40) = M2C_FIELD(sprite, s16 *, 0x38);
                M2C_FIELD(sprite, s16 *, 0x38) += M2C_FIELD(sprite, s16 *, 0x40);
                if (M2C_FIELD(sprite, s16 *, 0x38) >= 256) M2C_FIELD(sprite, s16 *, 0x38) = 0;
            }
        }
        layer = M2C_FIELD(sprite, u8 *, 0x34);
        {
            void **engine = gCur3DSpriteEngine;
            DS3DSpriteEngine *offsetEngine = DS3D_ENGINE(g3DSpriteEngineMain);
            u16 x = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x38);
            u16 y = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x40);
            dx = x - offsetEngine->offsetX;
            dy = y - offsetEngine->offsetY;
        }
        switch (layer) {
        case 0:
            if (!((u8)((u32)(((DS3DSpriteBank *)g3DSpriteBankMain)->flags << 28) >> 31)))
                {u16 mask = 0x1ff; volatile u32 *reg = &REG_BG0OFS; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));}
            break;
        case 1: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04000014; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));} break;
        case 2: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04000018; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));} break;
        case 3: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x0400001C; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));} break;
        }
        M2C_FIELD(sprite, s16 *, 0x42)++;
        if (M2C_FIELD(sprite, s16 *, 0x42) >= 1024)
            M2C_FIELD(sprite, s16 *, 0x42) -= 1024;
    } else {
        {
            s16 period = M2C_FIELD(sprite, s16 *, 0x4a);
            if (period && !Modulo(M2C_FIELD(sprite, s16 *, 0x52), period)) {
                M2C_FIELD((u8 *)DS3D_BANK(gCur3DSpriteEngine) + M2C_FIELD(sprite, u8 *, 0x44) * 2, s16 *, 0x38) = M2C_FIELD(sprite, s16 *, 0x46);
                M2C_FIELD(sprite, s16 *, 0x46) += M2C_FIELD(sprite, s16 *, 0x4c);
                if (M2C_FIELD(sprite, s16 *, 0x46) >= 256) M2C_FIELD(sprite, s16 *, 0x46) = 0;
            }
        }
        {
            s16 period = M2C_FIELD(sprite, s16 *, 0x4e);
            if (period && !Modulo(M2C_FIELD(sprite, s16 *, 0x52), period)) {
                M2C_FIELD((u8 *)DS3D_BANK(gCur3DSpriteEngine) + M2C_FIELD(sprite, u8 *, 0x44) * 2, s16 *, 0x40) = M2C_FIELD(sprite, s16 *, 0x48);
                M2C_FIELD(sprite, s16 *, 0x48) += M2C_FIELD(sprite, s16 *, 0x50);
                if (M2C_FIELD(sprite, s16 *, 0x48) >= 256) M2C_FIELD(sprite, s16 *, 0x48) = 0;
            }
        }
        layer = M2C_FIELD(sprite, u8 *, 0x44);
        {
            void **engine = gCur3DSpriteEngine;
            DS3DSpriteEngine *offsetEngine = DS3D_ENGINE(g3DSpriteEngineSub);
            u16 x = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x38);
            u16 y = M2C_FIELD((u8 *)*engine + layer * 2, u16 *, 0x40);
            dx = x - offsetEngine->offsetX;
            dy = y - offsetEngine->offsetY;
        }
        switch (layer) {
        case 0: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04001010; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));} break;
        case 1: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04001014; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));} break;
        case 2: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x04001018; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));} break;
        case 3: {u16 mask = 0x1ff; volatile u32 *reg = &*(volatile u32 *)0x0400101C; *reg = (mask & (u32)dx) | (((u32)mask << 16) & ((u32)dy << 16));} break;
        }
        M2C_FIELD(sprite, s16 *, 0x52)++;
        if (M2C_FIELD(sprite, s16 *, 0x52) >= 1024)
            M2C_FIELD(sprite, s16 *, 0x52) -= 1024;
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
void func_020af620(void *sprite) {
    func_020af244(sprite);
}

/* Creates two 3D sprite objects (primary then secondary engine) carrying a pair of 4-value payloads. */
void func_020af62c(s32 a, s32 b, s32 c, s32 d, s16 e, u8 f, s16 g, s16 h, s16 i, s16 j) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    extern M2C_UNK data_02127e7c, data_02127e2c;
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    void *saved = gCur3DSpriteEngine;
    void *p;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    p = CreateSpriteFromClass(&data_02127e7c, 1);
    if (p) {
        M2C_FIELD(p, void **, 0) = &data_02127e2c;
        M2C_FIELD(p, u8 *, 0x34) = a;
        M2C_FIELD(p, s16 *, 0x36) = 0;
        M2C_FIELD(p, s16 *, 0x38) = 0;
        M2C_FIELD(p, s16 *, 0x42) = 0;
        M2C_FIELD(p, s16 *, 0x3a) = b;
        M2C_FIELD(p, s16 *, 0x3c) = c;
        M2C_FIELD(p, s16 *, 0x3e) = d;
        M2C_FIELD(p, s16 *, 0x40) = e;
    }

    gCur3DSpriteEngine = g3DSpriteEngineSub;
    p = CreateSpriteFromClass(&data_02127e7c, 1);
    if (p) {
        M2C_FIELD(p, void **, 0) = &data_02127e2c;
        M2C_FIELD(p, u8 *, 0x44) = f;
        M2C_FIELD(p, s16 *, 0x46) = 0;
        M2C_FIELD(p, s16 *, 0x48) = 0;
        M2C_FIELD(p, s16 *, 0x52) = 0;
        M2C_FIELD(p, s16 *, 0x4a) = g;
        M2C_FIELD(p, s16 *, 0x4c) = h;
        M2C_FIELD(p, s16 *, 0x4e) = i;
        M2C_FIELD(p, s16 *, 0x50) = j;
    }

    gCur3DSpriteEngine = saved;
}

void func_020af71c(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02127e7c;
    DeleteSpriteObjectsOfClass(&data_02127e7c);
}

s32 func_020af730(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_020af744(void) {

}

s32 func_020af748(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_020af75c(void) {

}

