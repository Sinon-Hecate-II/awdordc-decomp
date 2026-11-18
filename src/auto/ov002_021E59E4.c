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

void func_ov002_021e59e4(BattleScreenState *scene) {
    extern char data_ov002_021f2d84[];
    extern u8 gPlayerSettings[];
    extern BattleScreenAssetEntry data_ov002_021f30f8[];
    extern u8 *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    void *LoadFileToBuffer(void *, s32);
    s32 LoadDecompressedFileTo(void *, s32);
    void func_ov002_021e5988(u16 *, s32);
    void MI_CpuCopy32(void *, void *, s32);
    void CopyToObjPaletteShadow(void *, s32, s32);
    void HeapFreeBlock(void *);
    u16 *colors;
    void *palette;
    s32 i;

    colors = LoadFileToBuffer(data_ov002_021f2d84, 1);
    LoadDecompressedFileTo(data_ov002_021f30f8[gPlayerSettings[1]].assets->tiles, 0x6000000);
    LoadDecompressedFileTo(data_ov002_021f30f8[gPlayerSettings[1]].assets->upperTilemap, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x28));
    LoadDecompressedFileTo(data_ov002_021f30f8[gPlayerSettings[1]].assets->lowerTilemap, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x2c));
    palette = LoadFileToBuffer(data_ov002_021f30f8[gPlayerSettings[1]].assets->palette, 1);
    scene[gPlayerSettings[1]].shadowColor = colors[data_ov002_021f30f8[gPlayerSettings[1]].assets->shadowColorIndex];
    CopyToObjPaletteShadow(palette, 0, 0x100);
    HeapFreeBlock(palette);

    if (gPlayerSettings[1] == 0) {
        func_ov002_021e5988(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x28), 32);
        func_ov002_021e5988(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x2c), 32);
    }
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x28), (void *)0x6007800, 0x800);
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineMain, u16 **, 0x2c), (void *)0x6007000, 0x800);


    LoadDecompressedFileTo(data_ov002_021f30f8[!gPlayerSettings[1]].assets->tiles, 0x6008000);
    LoadDecompressedFileTo(data_ov002_021f30f8[!gPlayerSettings[1]].assets->upperTilemap, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x28));
    LoadDecompressedFileTo(data_ov002_021f30f8[!gPlayerSettings[1]].assets->lowerTilemap, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x2c));
    palette = LoadFileToBuffer(data_ov002_021f30f8[!gPlayerSettings[1]].assets->palette, 1);
    {
        s32 screen = gPlayerSettings[1];
        s32 other = !screen;
        scene[screen ? 0 : 1].shadowColor = colors[data_ov002_021f30f8[other].assets->shadowColorIndex];
    }
    CopyToObjPaletteShadow(palette, 0x100, 0x100);
    HeapFreeBlock(palette);

    for (i = 0; i < 0x400; i++) {
        M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x28)[i] += 0x8000;
        M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x2c)[i] += 0x8000;
    }

    if (gPlayerSettings[1] != 0) {
        func_ov002_021e5988(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x28), 32);
        func_ov002_021e5988(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x2c), 32);
    }
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x28), (void *)0x600f800, 0x800);
    MI_CpuCopy32(M2C_FIELD(g3DSpriteEngineSub, u16 **, 0x2c), (void *)0x600f000, 0x800);

    HeapFreeBlock(colors);
}
