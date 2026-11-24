/* 32 functions from 0x021F15D4 to 0x021F25CC (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_mapselect.h"
static inline void loadBank3(s32 k,u32 m) {
extern s32 gCur3DSpriteEngine;
void LoadSpriteResource(s32,s32,s32,void *);
LoadSpriteResource(2,2,k,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+(m<<5));
}

s32 GetSceneSlideDirection(void) {
    s32 func_ov003_021f1584();
    s32 func_ov003_021f15ac();
    u8 GetMapConfirmState(void);
    s32 temp_r0;
    temp_r0 = GetMapConfirmState();
    switch (temp_r0) {
    case 1: return func_ov003_021f1584();
    case 2: return func_ov003_021f15ac();
    default: return 0;
    }
}

s32 GetSceneSlideOffset(void) {
    s32 func_ov003_021f1594();
    s32 func_ov003_021f15bc();
    u8 GetMapConfirmState(void);
    s32 temp_r0;
    temp_r0 = GetMapConfirmState();
    switch (temp_r0) {
    case 1: return func_ov003_021f1594();
    case 2: return func_ov003_021f15bc();
    default: return 0;
    }
}

/* Reset the shared battle-scene state for entry, store the animation direction
 * and neighbour flags (c, d, e), then start the scene type picked by kind. */
void Ov003_StartBattleScene(void *entry,u32 kind,M2C_UNK c,M2C_UNK d,u8 e) {
    void ClearSceneLayerOverrides(void);
    void func_ov003_021f1bc0(void);
    func_ov003_021f1bc0();
    func_ov003_021f14d8(c,d,e);
    SetOv003SceneClass(0);
    ClearSceneLayerOverrides();
    func_ov003_021f14b4();
    switch(kind){
    case 0: func_ov003_021fd488(entry); return;
    case 1: func_ov003_021f01f0(entry); return;
    case 2: func_ov003_021f05fc(entry); return;
    case 3: func_ov003_022056bc(entry); return;
    case 4: func_ov003_021fd850(entry); return;
    case 5: func_ov003_021fdc1c(entry); return;
    case 6: func_ov003_021fdfe8(entry); return;
    case 7: CreateOv003SceneView(entry); return;
    case 8:
    case 9: CreateLocalPlayerNameLabel(0,0x6e0,entry); return;
    case 10: func_020e0f14(entry); return;
    case 11: func_020e147c(entry); return;
    case 12: func_020e19e8(entry); return;
    case 13: func_020e1f54(entry); return;
    case 14: func_020e24c0(entry); return;
    case 15: func_020e2a2c(entry); return;
    case 16:
    case 17:
        ApplyBgLayerVisibility();
        DeleteVoiceChatWidgets();
        CreateMatchNameLabel(0,0x6e0,entry);
        return;
    case 18: func_ov003_021fe3b4(entry); return;
    case 19: func_ov003_021fe780(entry); return;
    case 20: func_ov003_021feb4c(entry); return;
    case 21: CreateOv003Scene(entry); return;
    default: return;
    }
}

void func_ov003_021f17e0(void) {
    M2C_UNK func_ov003_021f13c8();
    M2C_UNK IncrementSpriteChildCount();
    s32 func_ov003_021f13c8();
    if (func_ov003_021f13c8() == 0) {
        return;
    }
    func_ov003_021f13c8();
    IncrementSpriteChildCount();
}

u8 func_ov003_021f17fc(void) {
    s32 func_ov003_021f13c8();
    u8 var_r0;
    if (func_ov003_021f13c8() == 0) return 0U;
    if (M2C_FIELD(func_ov003_021f13c8(), u8 *, 0x31) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void Ov003_CreateScreenTransition(void) {
    M2C_UNK CreateScreenTransitionChildren(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    if (func_ov003_021f13c8() == 0) {
        return;
    }
    CreateScreenTransitionChildren(2, 8, 2, func_ov003_021f13c8());
}

void func_ov003_021f1858(void) {
    M2C_UNK StartScreenFadeChildren(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    if (func_ov003_021f13c8() == 0) {
        return;
    }
    StartScreenFadeChildren(2, 8, 2, func_ov003_021f13c8());
}

void func_ov003_021f1884(s16 arg0) {
    extern u8 gOv003SceneState;
    M2C_FIELD(&gOv003SceneState, s16 *, 8) = arg0;
}

u16 func_ov003_021f1894(void) {
    extern u8 gOv003SceneState;
    return M2C_FIELD(&gOv003SceneState, u16 *, 8);
}

void func_ov003_021f18a4(void) {
    SetOv003SceneState(3);
}

/* Set up the scene's wallpaper sprites from its 6-byte layer descriptor and
 * remember that descriptor in the shared scene config: create the main-screen
 * sprite when the descriptor enables it, the sub-screen one likewise, or both. */
void ApplySceneLayers(u8 *layers) {
    void func_020af144(u8, u8, u8, u8);
    void func_020af178(u8, u8);
    void func_020af19c(u8, u8);
    extern M2C_UNK gSceneConfig;
    u8 mainOn;
    u8 subOn;

    subOn = layers[SCENE_LAYER_SUB_ON];
    mainOn = layers[SCENE_LAYER_MAIN_ON];
    if (mainOn & subOn) {
        func_020af144(layers[SCENE_LAYER_MAIN_LAYER], layers[SCENE_LAYER_MAIN_PALETTE], layers[SCENE_LAYER_SUB_LAYER], layers[SCENE_LAYER_SUB_PALETTE]);
    } else if (mainOn != 0) {
        func_020af178(layers[SCENE_LAYER_MAIN_LAYER], layers[SCENE_LAYER_MAIN_PALETTE]);
    } else if (subOn != 0) {
        func_020af19c(layers[SCENE_LAYER_SUB_LAYER], layers[SCENE_LAYER_SUB_PALETTE]);
    }
    M2C_FIELD(&gSceneConfig, u8 **, 4) = layers;
}

void func_ov003_021f1920(void) {
    M2C_UNK func_020af1e4();
    func_020af1e4();
}

/* Create the scene's 3D sprite on each engine its definition asks for
 * (DS3D_TARGET_*): load the definition's tile and palette into the asked
 * sprite bank slot, make the sprite the scene sprite, and record which sprite
 * sheet it uses before remembering the definition in the scene config. */
void CreateScene3DSprite(void *definition) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineMain, g3DSpriteEngineSub;
    extern u8 gOv003SceneState;
    extern M2C_UNK gSceneConfig;
    void *Create3DSprite(s32);
    s32 func_020aaf74(void *);
    void LoadSpriteResource(s32, s32, s32, void *);
    SceneSpriteDef *def = definition;
    s32 savedEngine = gCur3DSpriteEngine;
    s32 engine;
    void *sprite;
    s32 engineIndex = 0;
    u8 screen;
    s32 bank, tile;
    u32 palette;

    do {
        if (engineIndex == 0) engine = g3DSpriteEngineMain;
        else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        screen = def->targetScreen;
        if (screen == DS3D_TARGET_MAIN && engine != g3DSpriteEngineMain) continue;
        if (screen == DS3D_TARGET_SUB && engine != g3DSpriteEngineSub) continue;
        if (screen == DS3D_TARGET_ACTIVE && engine != savedEngine) continue;
        sprite = Create3DSprite(9);
        M2C_FIELD(&gOv003SceneState, void **, 16) = sprite;
        bank = def->bank;
        palette = def->palette;
        tile = def->tile;
        M2C_FIELD(sprite, u8 *, 0x58) = bank;
        LoadSpriteResource(2, 0, bank, (u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x1c) + (tile << 5));
        {
            u8 *current = (u8 *)*(volatile s32 *)&gCur3DSpriteEngine;
            LoadSpriteResource(2, 2, bank, &M2C_FIELD(current, u8 **, 0x30)[palette * 32]);
        }
        M2C_FIELD(sprite, s32 *, 0x44) = func_020aaf74(sprite);
        M2C_FIELD(sprite, u16 *, 0x3e) = tile & 0x7ffffff;
        M2C_FIELD(sprite, u32 *, 0x40) = (M2C_FIELD(sprite, u32 *, 0x40) & ~0x3fc0000) | ((palette << 24) >> 6);
        M2C_FIELD(sprite, u16 *, 0x3c) = 0xc00;
    } while (++engineIndex < 2);

    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(&gSceneConfig, void **, 0) = definition;
}

void DeleteOv003SceneSprite(void) {
    M2C_UNK DeleteSpriteObject(s32);
    extern u8 gOv003SceneState;
    DeleteSpriteObject(M2C_FIELD(&gOv003SceneState, s32 *, 0x10));
}

/* Clear gSceneLayerOverrides, the scene's per-engine BG-layer override table:
 * zero every layer slot on the main and sub engines. */
void ClearSceneLayerOverrides(void) {
    extern s32 gSceneLayerOverrides[SCENE_ENGINE_COUNT][SCENE_LAYER_COUNT];
    u8 engine = 0;
    u8 layer;

    do {
        layer = 0;
        do {
            gSceneLayerOverrides[engine][layer] = 0;
            layer++;
        } while (layer < SCENE_LAYER_COUNT);
        engine++;
    } while (engine < SCENE_ENGINE_COUNT);
}

/* Apply a 3D sprite layout preset on the main 2D engine and remember it as the
 * scene's main-screen layout. */
void SetSceneLayoutMain(void *layout) {
    M2C_UNK Apply3DSpriteLayout(void *);
    extern M2C_UNK gSceneConfig;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Apply3DSpriteLayout(layout);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(&gSceneConfig, void **, SCENE_CONFIG_MAIN_LAYOUT) = layout;
}

void SetSceneLayoutSub(s32 arg0) {
    M2C_UNK Apply3DSpriteLayout();
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK gSceneConfig;
    s32 temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    Apply3DSpriteLayout();
    gCur3DSpriteEngine = temp_r4;
    M2C_FIELD(&gSceneConfig, s32 *, 12) = arg0;
}

/* Set one BG-layer override on the main 2D engine: apply the override with the
 * main engine made current, then store the value in the main engine's override
 * row. */
void SetSceneLayerOverrideMain(s32 layer, s32 value) {
    M2C_UNK Configure3DSpriteLayer();
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    extern s32 gSceneLayerOverrides[SCENE_ENGINE_COUNT][SCENE_LAYER_COUNT];
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Configure3DSpriteLayer();
    gCur3DSpriteEngine = savedEngine;
    gSceneLayerOverrides[SCENE_ENGINE_MAIN][layer] = value;
}

/* Set one BG-layer override on the sub 2D engine: apply the override with the sub
 * engine made current, then store the value in the sub engine's override row. */
void SetSceneLayerOverrideSub(s32 layer, s32 value) {
    M2C_UNK Configure3DSpriteLayer();
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK gSceneLayerOverridesSub;
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    Configure3DSpriteLayer();
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(&gSceneLayerOverridesSub, s32 *, layer * 4) = value;
}

void func_ov003_021f1bc0(void) {
    extern u8 gOv003SceneState;
    gOv003SceneState = 0;
}

void Ov003_SetMapConfirmEnabled(void) {
    extern u8 gOv003SceneState;
    gOv003SceneState = 1;
}

void Ov003_SetMapConfirmDisabled(void) {
    extern u8 gOv003SceneState;
    gOv003SceneState = 2;
}

u8 GetMapConfirmState(void) {
    extern u8 gOv003SceneState;
    return gOv003SceneState;
}

/* Enables the configured BG0-BG3 layer (and disables the rest) on both the
 * main and sub 2D engines, using the shared 6-byte layer descriptor:
 * [0]=main on, [1]=main layer, [3]=sub on, [4]=sub layer. */
M2C_UNK ApplyBgLayerVisibility(void) {
    extern M2C_UNK gCur3DSpriteEngine;
    extern M2C_UNK g3DSpriteEngineMain;
    extern M2C_UNK gSceneConfig;
    extern M2C_UNK g3DSpriteEngineSub;
    u8 *layers;
    s32 savedEngine;
    u8 layer;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    for (layer = 0; layer < 4; layer++) {
        layers = M2C_FIELD(&gSceneConfig, u8 **, 4);
        if (layers[0] != 0 && layers[1] == layer) {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x100; break; }
            }
        } else {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x100; break; }
            }
        }
    }
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    for (layer = 0; layer < 4; layer++) {
        layers = M2C_FIELD(&gSceneConfig, u8 **, 4);
        if (layers[3] != 0 && layers[4] == layer) {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x100; break; }
            }
        } else {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x100; break; }
            }
        }
    }
    gCur3DSpriteEngine = savedEngine;
    return (M2C_UNK)&gCur3DSpriteEngine;
}

/* Show on the main 2D engine, then on the sub engine, the four BG layers the
 * current scene uses and hide the rest.  A layer is used when the scene set an
 * override pointer for it (gSceneLayerOverrides) or when the shared layer
 * descriptor (gSceneConfig[4]: [0]/[1] main, [3]/[4] sub) names it. */
void ApplySceneLayerVisibility(void) {
    extern M2C_UNK gCur3DSpriteEngine;
    extern M2C_UNK g3DSpriteEngineMain;
    extern M2C_UNK gSceneConfig;
    extern s32 gSceneLayerOverrides[2][4];
    extern M2C_UNK g3DSpriteEngineSub;
    u8 *descriptor;
    u8 layer;
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    for (layer = 0; layer < 4; layer++) {
        if (gSceneLayerOverrides[0][layer] != 0 || ((descriptor = M2C_FIELD(&gSceneConfig, u8 **, 4))[0] != 0 && descriptor[1] == layer)) {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x100; break; }
            }
        } else {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x100; break; }
            }
        }
    }
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    for (layer = 0; layer < 4; layer++) {
        if (gSceneLayerOverrides[1][layer] != 0 || ((descriptor = M2C_FIELD(&gSceneConfig, u8 **, 4))[3] != 0 && descriptor[4] == layer)) {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg | 0x100; break; }
            }
        } else {
            switch (layer) {
            case 0: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x10; break; }
            case 1: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x20; break; }
            case 2: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x40; break; }
            case 3: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x80; break; }
            case 4: { u16 *volatile reg = *(u16 **)gCur3DSpriteEngine; *reg = *reg & ~0x100; break; }
            }
        }
    }
    gCur3DSpriteEngine = savedEngine;
}

/* Sort a 5-entry map-id list in place, leaving MAP_PICK_EMPTY (0xFFFF) slots
 * at the end. */
void SortMapIdList(u16 *mapIds) {
    u8 pass, slot;
    u16 left, right;
    pass = 0;
    do {
        slot = 0;
        do {
            right = mapIds[slot + 1];
            left = mapIds[slot];
            if ((left > right && left != MAP_PICK_EMPTY && right != MAP_PICK_EMPTY) || (left == MAP_PICK_EMPTY && right != MAP_PICK_EMPTY)) {
                mapIds[slot] = right;
                mapIds[slot + 1] = left;
            }
            slot++;
        } while ((u32)slot < MAP_PICK_SLOTS - 1);
        pass++;
    } while ((u32)pass < MAP_PICK_SLOTS - 1);
}

void func_ov003_021f24ac(void *arg0, void *arg1) {
    void CopyU16(void *, void *, u32);
    extern M2C_UNK data_ov003_022111de;
    extern M2C_UNK gDownloadedMapIds;
    CopyU16(arg0, &data_ov003_022111de, 10);
    CopyU16(arg1, &gDownloadedMapIds, 10);
    SortMapIdList((u16 *)&data_ov003_022111de);
    SortMapIdList((u16 *)&gDownloadedMapIds);
}

void func_ov003_021f24ec(void *arg0, void *arg1) {
    void CopyU16(void *, void *, u32);
    extern M2C_UNK data_ov003_022111de;
    extern M2C_UNK gDownloadedMapIds;
    CopyU16(&data_ov003_022111de, arg0, 10);
    CopyU16(&gDownloadedMapIds, arg1, 10);
}

M2C_UNK func_ov003_021f2524(M2C_UNK *arg0) {
    u8 count, i;
    count = 0;
    i = 0;
    do {
        if (((u16 *)arg0)[i] != 0xFFFF) count++;
        i++;
    } while ((u32)i < 5);
    return count;
}

void func_ov003_021f2560(void) {
    M2C_UNK func_ov003_021f2524(M2C_UNK *);
    extern M2C_UNK data_ov003_022111de;
    func_ov003_021f2524(&data_ov003_022111de);
}

void func_ov003_021f2574(void) {
    M2C_UNK func_ov003_021f2524(M2C_UNK *);
    extern M2C_UNK gDownloadedMapIds;
    func_ov003_021f2524(&gDownloadedMapIds);
}

/* Remove a downloaded map ID from the five-slot list, then keep the remaining IDs sorted. */
void RemoveDownloadedMapId(u32 mapId) {
extern M2C_UNK gDownloadedMapIds;
u16 *mapIds=(u16 *)&gDownloadedMapIds;
u8 slot=0;
do { if(mapId==mapIds[slot]) mapIds[slot]=MAP_PICK_EMPTY; slot++; } while(slot<MAP_PICK_SLOTS);
SortMapIdList((u16 *)&gDownloadedMapIds);
}

