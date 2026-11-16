/* Upload dirty sprite layers and palettes to VRAM. */
#include "common.h"
#include "ds3dsprite.h"

#pragma opt_common_subs off
void Update3DSpriteVram(void) {
    s32 Get3DSpriteLayerSize(u8, s32);
    void MI_CpuCopy32(void *, s32, s32);
    void CopyToSpritePaletteVram(void *, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain, g3DSpriteEngineSub;
    extern u16 *g3DSpriteBankMain;

    s32 savedEngine = gCur3DSpriteEngine;
    s32 layerIndex = 0, screenIndex = 0, layerSize;
    u32 vramBase;
    void *engine;
    u8 isMainScreen, isMainEngine;

    /* Upload changed layers and palette data for both sprite engines, then clear their dirty flags. */
    do {
        engine = (void *)(screenIndex == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub);
        isMainScreen = (s32)engine == g3DSpriteEngineMain;
        gCur3DSpriteEngine = (s32)engine;
        if (isMainScreen == 1) vramBase = 0x6000000;
        else vramBase = 0x6200000;
        for (layerIndex = 0; layerIndex < 4; layerIndex++) {
            engine = (void *)gCur3DSpriteEngine;
            if ((M2C_FIELD(engine, u8 *, 0x46) & (1 << layerIndex)) && !(M2C_FIELD(engine, u8 *, 0x47) & (1 << layerIndex))) {
                isMainEngine = (s32)engine == g3DSpriteEngineMain;
                layerSize = Get3DSpriteLayerSize((u8)((u32)(*M2C_FIELD(engine, u16 **, 0) << 29) >> 29), (u8)layerIndex);
                {
                    s32 destination;
                    if (isMainEngine) destination = ((u32)(g3DSpriteBankMain[1] << 29) >> 29) << 16;
                    else destination = 0;
                    destination = vramBase + destination;
                    engine = (void *)gCur3DSpriteEngine;
                    {
                        u8 *layerControl = *(u8 **)engine;
                        void *layerTileBuffer = ((void **)((u8 *)engine + 0x20))[layerIndex];
                        destination += ((u32)(M2C_FIELD(layerControl + layerIndex * 2, u16 *, 6) << 19) >> 27) << 11;
                        MI_CpuCopy32(layerTileBuffer, destination, layerSize);
                    }
                }
            }
        }
        engine = (void *)gCur3DSpriteEngine;
        if ((M2C_FIELD(engine, u8 *, 0x46) & 16) && !(M2C_FIELD(engine, u8 *, 0x47) & 16)) {
            *M2C_FIELD(engine, u16 **, 0x30) = M2C_FIELD(engine, u16 *, 0x44);
            CopyToSpritePaletteVram(M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x30), (u8)screenIndex, 0, 1024);
        }
        M2C_FIELD((void *)gCur3DSpriteEngine, u8 *, 0x47) = 0;
        engine = (void *)gCur3DSpriteEngine;
        M2C_FIELD(engine, u8 *, 0x46) = M2C_FIELD(engine, u8 *, 0x47);
        screenIndex++;
    } while (screenIndex < 2);
    gCur3DSpriteEngine = savedEngine;
}
#pragma opt_common_subs reset
