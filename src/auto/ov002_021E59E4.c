/* 1 function from 0x021E59E4 to 0x021E5D5C (ov002), found by ds-decomp. */
#include "common.h"

typedef struct {
    void *tiles;
    void *lowerTilemap;
    void *upperTilemap;
    void *palette;
    u8 unk_0x10[8];
    u16 shadowColorIndex;
} BattleScreenAssets;

typedef struct {
    BattleScreenAssets *assets;
    u8 unk_0x4[20];
} BattleScreenAssetEntry;

typedef struct {
    u8 unk_0x0[0x60];
    u16 shadowColor;
    u8 unk_0x62[2];
} BattleScreenState;

/* Loads the country art for both battle screens: the unit shadow palette
   ("unit_shadow_cl"), then each screen's country tileset (tile graphics to VRAM, the two
   tilemap halves into the 3D-sprite engine's layer buffers, the palette into the OBJ
   palette shadow), storing each screen's unit shadow colour.  The main engine shows the
   player at gPlayerSettings[1] and the sub engine the other one; the sub tilemaps are
   moved up a palette bank and mirrored horizontally, as the main ones are when the first
   player is on the main screen. */
void SetupCountryGraphics(BattleScreenState *screens) {
    extern char sUnitShadowPaletteFile[];
    extern u8 gPlayerSettings[];
    extern BattleScreenAssetEntry gScreenCountryAssets[];
    extern u8 *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    void *LoadFileToBuffer(void *, s32);
    s32 LoadDecompressedFileTo(void *, s32);
    void MirrorTilemapHorizontally(u16 *, s32);
    void MI_CpuCopy32(void *, void *, s32);
    void CopyToObjPaletteShadow(void *, s32, s32);
    void HeapFreeBlock(void *);
    u16 *shadowPalette;
    void *countryPalette;
    s32 i;

    shadowPalette = LoadFileToBuffer(sUnitShadowPaletteFile, 1);
    LoadDecompressedFileTo(gScreenCountryAssets[gPlayerSettings[1]].assets->tiles, 0x6000000);
    LoadDecompressedFileTo(gScreenCountryAssets[gPlayerSettings[1]].assets->upperTilemap, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x28));
    LoadDecompressedFileTo(gScreenCountryAssets[gPlayerSettings[1]].assets->lowerTilemap, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x2c));
    countryPalette = LoadFileToBuffer(gScreenCountryAssets[gPlayerSettings[1]].assets->palette, 1);
    screens[gPlayerSettings[1]].shadowColor = shadowPalette[gScreenCountryAssets[gPlayerSettings[1]].assets->shadowColorIndex];
    CopyToObjPaletteShadow(countryPalette, 0, 0x100);
    HeapFreeBlock(countryPalette);

    if (gPlayerSettings[1] == 0) {
        MirrorTilemapHorizontally(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x28), 32);
        MirrorTilemapHorizontally(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x2c), 32);
    }
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x28), (void *)0x6007800, 0x800);
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x2c), (void *)0x6007000, 0x800);


    LoadDecompressedFileTo(gScreenCountryAssets[!gPlayerSettings[1]].assets->tiles, 0x6008000);
    LoadDecompressedFileTo(gScreenCountryAssets[!gPlayerSettings[1]].assets->upperTilemap, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x28));
    LoadDecompressedFileTo(gScreenCountryAssets[!gPlayerSettings[1]].assets->lowerTilemap, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x2c));
    countryPalette = LoadFileToBuffer(gScreenCountryAssets[!gPlayerSettings[1]].assets->palette, 1);
    {
        s32 screen = gPlayerSettings[1];
        s32 other = !screen;
        screens[screen ? 0 : 1].shadowColor = shadowPalette[gScreenCountryAssets[other].assets->shadowColorIndex];
    }
    CopyToObjPaletteShadow(countryPalette, 0x100, 0x100);
    HeapFreeBlock(countryPalette);

    for (i = 0; i < 0x400; i++) {
        M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x28)[i] += 0x8000;
        M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x2c)[i] += 0x8000;
    }

    if (gPlayerSettings[1] != 0) {
        MirrorTilemapHorizontally(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x28), 32);
        MirrorTilemapHorizontally(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x2c), 32);
    }
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x28), (void *)0x600f800, 0x800);
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x2c), (void *)0x600f000, 0x800);

    HeapFreeBlock(shadowPalette);
}
