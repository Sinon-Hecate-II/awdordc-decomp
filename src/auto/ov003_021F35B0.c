/* 18 functions from 0x021F35B0 to 0x021F40A8 (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_scene.h"
#include "battle_map.h"

static inline s32 PanelHasSelection(void *p) {
    switch (M2C_FIELD(p,u8 *,4)) {
    case 1: case 3: case 5: return 1;
    default: return 0;
    }
}

/* Start the battle scene for the map the setup's menu currently highlights, with
 * no slide direction and no neighbouring move (the confirm came from a panel
 * other than the map list). */
void Ov003_StartSelectedBattleScene(Ov003BattleSetup *setup) {
    void Ov003_StartBattleScene(void *, u8, s32, s32, s32);
    Ov003BattleSetupMenu *menu = setup->menu;

    Ov003_StartBattleScene(setup, menu->items[menu->selection], 0, 0, 0);
}

/* Leave the map-select screen: cancel any pending screen transition, park the
 * battle setup in its idle state and drop the live ov003 scene object. */
void Ov003_ExitMapSelect(Ov003BattleSetup *setup) {
    void SetOv003SceneClass(s32);

    setup->pending = 0;
    setup->state = 4;
    SetOv003SceneClass(0);
}

/* Battle-setup step: set the setup's screen state and mirror the map-select
 * confirm state.  When the map is confirmed (IsMapConfirmEnabled) the confirm
 * state is set to enabled and the step returns; otherwise it is set to disabled
 * and, if the link session is in error, the object plays its back animation. */
void Ov003_UpdateMapConfirmState(Ov003BattleSetup *setup) {
    M2C_UNK GotoSpriteAnimationLabel(void *, M2C_UNK);
    s32 IsSessionInError();
    s32 IsSessionResultHandled();
    s32 IsMapConfirmEnabled();
    M2C_UNK Ov003_SetMapConfirmEnabled();
    setup->state = 2;
    if (IsMapConfirmEnabled() != 0) {
        Ov003_SetMapConfirmEnabled();
        return;
    }
    Ov003_SetMapConfirmDisabled();
    if ((IsSessionInError() == 0) && (IsSessionResultHandled() == 0)) {
        return;
    }
    GotoSpriteAnimationLabel(setup, 5);
}

/* Enter the match scene for the setup: disable map confirming, close the
 * voice-chat UI and create the match-name label off-screen (y = 0x6E0), then on
 * the first call start the scene transition. */
void Ov003_EnterMatchScene(Ov003BattleSetup *setup) {
    M2C_UNK Ov003_SetMapConfirmDisabled();
    M2C_UNK DisableMapConfirm();
    M2C_UNK DeleteVoiceChatWidgets();
    M2C_UNK CreateMatchNameLabel(M2C_UNK, M2C_UNK, void *);
    M2C_UNK Ov003_CreateScreenTransition();

    Ov003_SetMapConfirmDisabled();
    DisableMapConfirm();
    DeleteVoiceChatWidgets();
    CreateMatchNameLabel(0, 0x6E0, setup);
    if (setup->pending != 0) {
        return;
    }
    Ov003_CreateScreenTransition();
    setup->pending = 1;
}

/* Create the battle-setup object and set up its map-list menu for the map
 * category (gMapCategory) the map-select screen opened with: each category picks
 * the menu's list kind, item list and item count, records that kind as the scene's
 * map-list category, and, once the list has a selectable map, resets the map
 * settings and loads the link (or online) overlay.  The switch values are map
 * categories; the item list/count pairs come from the table at
 * data_ov003_0220fca8+0x18 and the list ids from data_ov003_0220fdb8. */
void Ov003_InitBattleSetup(M2C_UNK layer) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK **MemAlloc(M2C_UNK);
    M2C_UNK LoadLinkOverlay();
    M2C_UNK LoadOnlineOverlay();
    M2C_UNK PlayMusicTrack(M2C_UNK);
    M2C_UNK MapSettings_SetDefaults(M2C_UNK);
    M2C_UNK MapSettings_CopyToGameSettings(M2C_UNK);
    u32 GetMapCategory();
    void SetOv003SceneState(s32);
    M2C_UNK SetMapListCategory(s32);
    extern M2C_UNK data_ov003_0220fca8;
    extern M2C_UNK data_ov003_0220fcdc;
    extern M2C_UNK data_ov003_0220fd9c;
    extern M2C_UNK gOv003BattleSetupVTable;
    extern M2C_UNK data_ov003_0220fdb8;
    M2C_UNK **menu0;
    M2C_UNK **menu7;
    M2C_UNK **menu12;
    M2C_UNK **menu1;
    M2C_UNK **menu3;
    M2C_UNK **menu5;
    M2C_UNK **menu2;
    M2C_UNK **menu6;
    M2C_UNK **menu9;
    M2C_UNK **menu10;
    M2C_UNK **menu11;
    M2C_UNK **selectedMenu;
    s32 hasSelection7;
    s32 hasSelection12;
    s32 hasSelection11;
    s32 hasSelection1;
    s32 hasSelection3;
    s32 hasSelection5;
    s32 hasSelection0;
    s32 hasSelection2;
    s32 hasSelection6;
    s32 hasSelection9;
    s32 hasSelection10;
    u32 mapCategory;
    u8 unusedMode12;
    u8 unusedMode11;
    u8 unusedMode10;
    u8 unusedMode1;
    u8 unusedMode3;
    u8 unusedMode5;
    u8 unusedMode0;
    u8 unusedMode2;
    u8 unusedMode6;
    u8 unusedMode9;
    u8 unusedMode7;
    void *setup;

    setup = CreateSpriteObject(&data_ov003_0220fcdc, layer);
    if (setup != NULL) {
        M2C_FIELD(setup, M2C_UNK **, 0) = &gOv003BattleSetupVTable;
        M2C_FIELD(setup, s8 *, 0x34) = 5;
        M2C_FIELD(setup, s8 *, 0x35) = 0;
        M2C_FIELD(setup, s8 *, 0x44) = 0;
        M2C_FIELD(setup, s8 *, 0x45) = 0;
        M2C_FIELD(setup, s8 *, 0x46) = 0;
        M2C_FIELD(setup, s8 *, 0x47) = 1;
        SetOv003SceneState(4);
        M2C_FIELD(setup, M2C_UNK ***, 0x38) = MemAlloc(6);
        M2C_FIELD(setup, M2C_UNK ***, 0x3C) = MemAlloc(0xC);
        selectedMenu = MemAlloc(0xC);
        if (selectedMenu != NULL) {
            *selectedMenu = &data_ov003_0220fd9c;
        }
        M2C_FIELD(setup, M2C_UNK ***, 0x40) = selectedMenu;
    }
    PlayMusicTrack(4);
    mapCategory = GetMapCategory();
    switch (mapCategory) {
    case 28:
        menu7 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu7, u8 *, 4) = 7U;
        M2C_FIELD(menu7, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x27) - 1);
        M2C_FIELD(menu7, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x26));
        M2C_FIELD(menu7, s8 *, 5) = 0;
        SetMapListCategory(7);
        unusedMode7 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection7 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection7 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 6:
        menu1 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu1, u8 *, 4) = 1U;
        M2C_FIELD(menu1, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1B) - 1);
        M2C_FIELD(menu1, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1A));
        M2C_FIELD(menu1, s8 *, 5) = 0;
        SetMapListCategory(1);
        unusedMode1 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection1 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection1 != 0) {
            MapSettings_CopyToGameSettings(0);
            MapSettings_SetDefaults(0);
        }
        LoadLinkOverlay();
        return;
    case 22:
    case 23:
        menu3 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu3, u8 *, 4) = 3U;
        M2C_FIELD(menu3, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1F) - 1);
        M2C_FIELD(menu3, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1E));
        M2C_FIELD(menu3, s8 *, 5) = 0;
        SetMapListCategory(3);
        unusedMode3 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection3 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection3 != 0) {
            MapSettings_CopyToGameSettings(0);
            MapSettings_SetDefaults(0);
        }
        LoadOnlineOverlay();
        return;
    case 12:
        menu5 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu5, u8 *, 4) = 5U;
        M2C_FIELD(menu5, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x23) - 1);
        M2C_FIELD(menu5, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x22));
        M2C_FIELD(menu5, s8 *, 5) = 0;
        SetMapListCategory(5);
        unusedMode5 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection5 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection5 != 0) {
            MapSettings_CopyToGameSettings(0);
            MapSettings_SetDefaults(0);
        }
        LoadOnlineOverlay();
        return;
    case 5:
    case 7:
        menu0 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu0, u8 *, 4) = 0U;
        M2C_FIELD(menu0, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x19) - 1);
        M2C_FIELD(menu0, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x18));
        M2C_FIELD(menu0, s8 *, 5) = 0;
        SetMapListCategory(0);
        unusedMode0 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection0 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection0 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 24:
        LoadLinkOverlay();
        menu2 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu2, u8 *, 4) = 2U;
        M2C_FIELD(menu2, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1D) - 1);
        M2C_FIELD(menu2, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1C));
        M2C_FIELD(menu2, s8 *, 5) = 0;
        SetMapListCategory(2);
        unusedMode2 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection2 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection2 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 8:
        LoadOnlineOverlay();
        menu6 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu6, u8 *, 4) = 6U;
        M2C_FIELD(menu6, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x25) - 1);
        M2C_FIELD(menu6, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x24));
        M2C_FIELD(menu6, s8 *, 5) = 0;
        SetMapListCategory(6);
        unusedMode6 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection6 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection6 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 14:
        LoadOnlineOverlay();
        menu9 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu9, u8 *, 4) = 9U;
        M2C_FIELD(menu9, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2B) - 1);
        M2C_FIELD(menu9, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2A));
        M2C_FIELD(menu9, s8 *, 5) = 0;
        SetMapListCategory(9);
        unusedMode9 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection9 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection9 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 15:
        LoadOnlineOverlay();
        menu10 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu10, u8 *, 4) = 0xAU;
        M2C_FIELD(menu10, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2D) - 1);
        M2C_FIELD(menu10, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2C));
        M2C_FIELD(menu10, s8 *, 5) = 0;
        SetMapListCategory(10);
        unusedMode10 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection10 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection10 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 16:
        LoadOnlineOverlay();
        menu11 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu11, u8 *, 4) = 0xBU;
        M2C_FIELD(menu11, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2F) - 1);
        M2C_FIELD(menu11, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2E));
        M2C_FIELD(menu11, s8 *, 5) = 0;
        SetMapListCategory(11);
        unusedMode11 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection11 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection11 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 17:
        LoadOnlineOverlay();
        menu12 = M2C_FIELD(setup, M2C_UNK ***, 0x40);
        M2C_FIELD(menu12, u8 *, 4) = 0xCU;
        M2C_FIELD(menu12, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x31) - 1);
        M2C_FIELD(menu12, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x30));
        M2C_FIELD(menu12, s8 *, 5) = 0;
        SetMapListCategory(12);
        unusedMode12 = M2C_FIELD(M2C_FIELD(setup, M2C_UNK ***, 0x40), u8 *, 4);
        hasSelection12 = PanelHasSelection(M2C_FIELD(setup,void **,0x40));
        if (hasSelection12 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    default:
        return;
    }
}

/* Tear down the battle setup, restore its scene state, and free its owned buffers and menu. */
void *DestroyOv003BattleSetup(Ov003BattleSetup *setup) {
    extern M2C_UNK gOv003BattleSetupVTable;
    extern void **gCurrentMap;
    s32 GetMapRecordBuffer(void);
    void DoesMapRecordMatchBuffer(u16, s32);
    void SetOv003SceneState(s32);
    s32 GetSceneSlideOffset(void);
    void Ov003_StartScreenFade(void);
    void func_ov003_021f18a4(void);
    void DeleteWallpaperSpritesOnAllEngines(void);
    void DeleteOv003SceneSprite(void);
    M2C_UNK MemFree();
    void *mapName;
    Ov003BattleSetupMenu *menu;
    s32 usesSetupScene;

    setup->vtable = &gOv003BattleSetupVTable;
    mapName = (u8 *)*gCurrentMap + MAP_NAME;
    DoesMapRecordMatchBuffer(M2C_FIELD(mapName, u16 *, MAP_ID - MAP_NAME), GetMapRecordBuffer());
    setup->state = 3;
    menu = setup->menu;
    switch (menu->items[menu->selection]) {
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        usesSetupScene = 1;
        break;
    default:
        usesSetupScene = 0;
        break;
    }
    if (usesSetupScene) {
        SetOv003SceneState(4);
    } else {
        if (!GetSceneSlideOffset()) {
            Ov003_StartScreenFade();
            setup->pending = 0;
        }
        func_ov003_021f18a4();
    }
    DeleteWallpaperSpritesOnAllEngines();
    DeleteOv003SceneSprite();
    MemFree(setup->buffer38);
    MemFree(setup->buffer3C);
    menu = setup->menu;
    if (menu) {
        ((void (*)(void *))M2C_FIELD(M2C_FIELD(menu, void **, 0), void **, 4))(menu);
    }
    MemFree(setup);
    return setup;
}

s32 func_ov003_021f3df4(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Tears down / reinitialises an object: swaps its vtable, refreshes display-related state, checks its mode and either re-enters mode 4 or does a soft reset, then releases resources and invokes its destructor. */
void *func_ov003_021f3e08(void *obj) {
    extern M2C_UNK gOv003BattleSetupVTable;
    extern void **gCurrentMap;
    s32 GetMapRecordBuffer(void);
    void DoesMapRecordMatchBuffer(u16, s32);
    void SetOv003SceneState(s32);
    s32 GetSceneSlideOffset(void);
    void Ov003_StartScreenFade(void);
    void func_ov003_021f18a4(void);
    void DeleteWallpaperSpritesOnAllEngines(void);
    void DeleteOv003SceneSprite(void);
    M2C_UNK MemFree();
    void *base;
    void *inner;
    s32 mode_result;

    M2C_FIELD(obj, void **, 0) = &gOv003BattleSetupVTable;
    base = (u8 *)*gCurrentMap + 0x5120;
    DoesMapRecordMatchBuffer(M2C_FIELD(base, u16 *, 0x22), GetMapRecordBuffer());
    M2C_FIELD(obj, u8 *, 0x34) = 3;
    inner = M2C_FIELD(obj, void **, 0x40);
    switch (M2C_FIELD(inner, u8 **, 8)[M2C_FIELD(inner, s8 *, 5)]) {
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            mode_result = 1;
            break;
        default:
            mode_result = 0;
            break;
    }
    if (mode_result) {
        SetOv003SceneState(4);
    } else {
        if (!GetSceneSlideOffset()) {
            Ov003_StartScreenFade();
            M2C_FIELD(obj, u8 *, 0x44) = 0;
        }
        func_ov003_021f18a4();
    }
    DeleteWallpaperSpritesOnAllEngines();
    DeleteOv003SceneSprite();
    MemFree(M2C_FIELD(obj, void **, 0x38));
    MemFree(M2C_FIELD(obj, void **, 0x3C));
    inner = M2C_FIELD(obj, void **, 0x40);
    if (inner) {
        ((void (*)(void *))M2C_FIELD(M2C_FIELD(inner, void **, 0), void **, 4))(inner);
    }
    return obj;
}

void func_ov003_021f3f08(void) {

}

u8 func_ov003_021f3f0c(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

/* Whether a box at (x, y) of size width x height overlaps the 256x192 screen;
 * the inlined copy of IsBoxOnScreen used to clip the battle-scene text sprites. */
s32 IsOv003BoxOnScreen(s32 x, s32 y, s32 width, s32 height) {
    if (((s32) (x + width) < 0) || (x > SCREEN_WIDTH)) {
        return 0;
    }
    if (((s32) (y + height) < 0) || (y > SCREEN_HEIGHT)) {
        return 0;
    }
    return 1;
}

/* Return 1 when the rectangle (x0, y0) of size (w0, h0) overlaps the rectangle
 * (x1, y1) of size (w1, h1): the two are apart only when one lies entirely past
 * the other on either axis. */
s32 RectsOverlap(s32 x0, s32 y0, s32 w0, s32 h0, s16 x1, s16 y1, s16 w1, s16 h1) {
    if (x0 + w0 < x1 || x1 + w1 < x0) return 0;
    if (y0 + h0 < y1 || y1 + h1 < y0) return 0;
    return 1;
}

/* Wrap `value` into the range [min, max) by adding or subtracting the period
 * (max - min) until it falls inside, truncating the intermediate sum to 16 bits. */
void WrapValueToRange(s32 value, s32 min, s32 max) {
    s16 wrapped;
    s16 wrapped2;
    s32 stillBelow;
    s32 belowMax;
    s32 result;

    result = value;
    if (result < min) {
        do {
            wrapped = result + (max - min);
            stillBelow = min > (s32) wrapped;
            result = (s32) wrapped;
        } while (stillBelow);
    }
    if (result < max) {
        return;
    }
    do {
        wrapped2 = result - (max - min);
        belowMax = max > (s32) wrapped2;
        result = (s32) wrapped2;
    } while (!belowMax);
}

/* Wrap `value` into the range [min, max) in a single step: add the period
 * (max - min) when it is below the range, subtract it when at or above max, and
 * truncate the result to 16 bits. */
s16 WrapValueToRangeOnce(s32 value, s32 min, s32 max) {
    s32 wrapped;

    wrapped = value;
    if (wrapped < min) {
        wrapped += max - min;
    } else if (wrapped >= max) {
        wrapped -= max - min;
    }
    return (s16) wrapped;
}

/* Whether a link session is running but has at most one player: the battle setup
 * treats that as the solo variant of a link battle. */
u8 Ov003Battle_IsSoloLinkSession(void) {
    s32 IsLinkSessionActive();
    u32 GetSessionPlayerCount();
    s32 isSolo;

    if (IsLinkSessionActive() && GetSessionPlayerCount() <= 1U) isSolo = 1;
    else isSolo = 0;
    return isSolo;
}

/* Whether this console is the host of an active link session: used at the
 * map-select confirm so that only the host acknowledges the selection back to
 * the peers. */
u8 Ov003_IsLinkSessionHost(void) {
    s32 IsLinkSessionActive();
    s32 IsLocalSessionHost();
    s32 result;
    if (IsLinkSessionActive() && IsLocalSessionHost()) result = 1;
    else result = 0;
    return result;
}

/* True when the local console is a guest (not the host) in an active link
 * session; the battle draw code uses it with Ov003Battle_IsSoloLinkSession to
 * decide whether to show the opponent's status art. */
u8 Ov003Battle_IsLinkSessionGuest(void) {
    s32 IsLinkSessionActive();
    s32 IsLocalSessionGuest();
    s32 isGuest;

    if (IsLinkSessionActive() && IsLocalSessionGuest()) isGuest = 1;
    else isGuest = 0;
    return isGuest;
}

void func_ov003_021f4090(M2C_UNK arg0) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    Link_CreateStartRequest(0x4D4C5342, arg0);
}

