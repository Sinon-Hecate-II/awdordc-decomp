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

void func_ov003_021f35b0(void *arg0) {
    void Ov003_StartBattleScene(void *, u8, s32, s32, s32);
    void *ptr = M2C_FIELD(arg0, void **, 0x40);
    Ov003_StartBattleScene(arg0, M2C_FIELD(ptr, u8 **, 8)[M2C_FIELD(ptr, s8 *, 5)], 0, 0, 0);
}

void func_ov003_021f35d8(void *arg0) {
    M2C_UNK SetOv003SceneClass(M2C_UNK);
    M2C_FIELD(arg0, s8 *, 0x44) = 0;
    M2C_FIELD(arg0, s8 *, 0x34) = 4;
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

void func_ov003_021f3688(M2C_UNK arg0) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK **MemAlloc(M2C_UNK);
    M2C_UNK func_020886d4();
    M2C_UNK func_020886fc();
    M2C_UNK PlayMusicTrack(M2C_UNK);
    M2C_UNK MapSettings_SetDefaults(M2C_UNK);
    M2C_UNK MapSettings_CopyToGameSettings(M2C_UNK);
    u32 GetMapCategory();
    void SetOv003SceneState(s32);
    M2C_UNK func_ov003_021f1480(s32);
    extern M2C_UNK data_ov003_0220fca8;
    extern M2C_UNK data_ov003_0220fcdc;
    extern M2C_UNK data_ov003_0220fd9c;
    extern M2C_UNK gOv003BattleSetupVTable;
    extern M2C_UNK data_ov003_0220fdb8;
    M2C_UNK **temp_ip;
    M2C_UNK **temp_lr;
    M2C_UNK **temp_lr_10;
    M2C_UNK **temp_lr_2;
    M2C_UNK **temp_lr_3;
    M2C_UNK **temp_lr_4;
    M2C_UNK **temp_lr_5;
    M2C_UNK **temp_lr_6;
    M2C_UNK **temp_lr_7;
    M2C_UNK **temp_lr_8;
    M2C_UNK **temp_lr_9;
    M2C_UNK **temp_r0_2;
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    u32 temp_r0_3;
    u8 temp_r0_10;
    u8 temp_r0_11;
    u8 temp_r0_12;
    u8 temp_r0_13;
    u8 temp_r0_14;
    u8 temp_r0_4;
    u8 temp_r0_5;
    u8 temp_r0_6;
    u8 temp_r0_7;
    u8 temp_r0_8;
    u8 temp_r0_9;
    void *temp_r0;

    temp_r0 = CreateSpriteObject(&data_ov003_0220fcdc, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gOv003BattleSetupVTable;
        M2C_FIELD(temp_r0, s8 *, 0x34) = 5;
        M2C_FIELD(temp_r0, s8 *, 0x35) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x44) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x45) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x46) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x47) = 1;
        SetOv003SceneState(4);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x38) = MemAlloc(6);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = MemAlloc(0xC);
        temp_r0_2 = MemAlloc(0xC);
        if (temp_r0_2 != NULL) {
            *temp_r0_2 = &data_ov003_0220fd9c;
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_2;
    }
    PlayMusicTrack(4);
    temp_r0_3 = GetMapCategory();
    switch (temp_r0_3) {
    case 28:
        temp_lr = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr, u8 *, 4) = 7U;
        M2C_FIELD(temp_lr, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x27) - 1);
        M2C_FIELD(temp_lr, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x26));
        M2C_FIELD(temp_lr, s8 *, 5) = 0;
        func_ov003_021f1480(7);
        temp_r0_4 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 6:
        temp_lr_2 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_2, u8 *, 4) = 1U;
        M2C_FIELD(temp_lr_2, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1B) - 1);
        M2C_FIELD(temp_lr_2, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1A));
        M2C_FIELD(temp_lr_2, s8 *, 5) = 0;
        func_ov003_021f1480(1);
        temp_r0_5 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_2 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_2 != 0) {
            MapSettings_CopyToGameSettings(0);
            MapSettings_SetDefaults(0);
        }
        func_020886d4();
        return;
    case 22:
    case 23:
        temp_lr_3 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_3, u8 *, 4) = 3U;
        M2C_FIELD(temp_lr_3, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1F) - 1);
        M2C_FIELD(temp_lr_3, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1E));
        M2C_FIELD(temp_lr_3, s8 *, 5) = 0;
        func_ov003_021f1480(3);
        temp_r0_6 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_3 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_3 != 0) {
            MapSettings_CopyToGameSettings(0);
            MapSettings_SetDefaults(0);
        }
        func_020886fc();
        return;
    case 12:
        temp_lr_4 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_4, u8 *, 4) = 5U;
        M2C_FIELD(temp_lr_4, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x23) - 1);
        M2C_FIELD(temp_lr_4, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x22));
        M2C_FIELD(temp_lr_4, s8 *, 5) = 0;
        func_ov003_021f1480(5);
        temp_r0_7 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_4 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_4 != 0) {
            MapSettings_CopyToGameSettings(0);
            MapSettings_SetDefaults(0);
        }
        func_020886fc();
        return;
    case 5:
    case 7:
        temp_ip = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_ip, u8 *, 4) = 0U;
        M2C_FIELD(temp_ip, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x19) - 1);
        M2C_FIELD(temp_ip, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x18));
        M2C_FIELD(temp_ip, s8 *, 5) = 0;
        func_ov003_021f1480(0);
        temp_r0_8 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_5 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_5 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 24:
        func_020886d4();
        temp_lr_5 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_5, u8 *, 4) = 2U;
        M2C_FIELD(temp_lr_5, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1D) - 1);
        M2C_FIELD(temp_lr_5, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x1C));
        M2C_FIELD(temp_lr_5, s8 *, 5) = 0;
        func_ov003_021f1480(2);
        temp_r0_9 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_6 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_6 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 8:
        func_020886fc();
        temp_lr_6 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_6, u8 *, 4) = 6U;
        M2C_FIELD(temp_lr_6, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x25) - 1);
        M2C_FIELD(temp_lr_6, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x24));
        M2C_FIELD(temp_lr_6, s8 *, 5) = 0;
        func_ov003_021f1480(6);
        temp_r0_10 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_7 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_7 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 14:
        func_020886fc();
        temp_lr_7 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_7, u8 *, 4) = 9U;
        M2C_FIELD(temp_lr_7, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2B) - 1);
        M2C_FIELD(temp_lr_7, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2A));
        M2C_FIELD(temp_lr_7, s8 *, 5) = 0;
        func_ov003_021f1480(9);
        temp_r0_11 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_8 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_8 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 15:
        func_020886fc();
        temp_lr_8 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_8, u8 *, 4) = 0xAU;
        M2C_FIELD(temp_lr_8, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2D) - 1);
        M2C_FIELD(temp_lr_8, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2C));
        M2C_FIELD(temp_lr_8, s8 *, 5) = 0;
        func_ov003_021f1480(10);
        temp_r0_12 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_9 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_9 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 16:
        func_020886fc();
        temp_lr_9 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_9, u8 *, 4) = 0xBU;
        M2C_FIELD(temp_lr_9, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2F) - 1);
        M2C_FIELD(temp_lr_9, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x2E));
        M2C_FIELD(temp_lr_9, s8 *, 5) = 0;
        func_ov003_021f1480(11);
        temp_r0_13 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_10 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_10 == 0) {
            return;
        }
        MapSettings_CopyToGameSettings(0);
        MapSettings_SetDefaults(0);
        return;
    case 17:
        func_020886fc();
        temp_lr_10 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x40);
        M2C_FIELD(temp_lr_10, u8 *, 4) = 0xCU;
        M2C_FIELD(temp_lr_10, s8 *, 6) = (s8) (M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x31) - 1);
        M2C_FIELD(temp_lr_10, void **, 8) = (void *) ((u8 *)&data_ov003_0220fdb8 + M2C_FIELD(&data_ov003_0220fca8, u8 *, 0x30));
        M2C_FIELD(temp_lr_10, s8 *, 5) = 0;
        func_ov003_021f1480(12);
        temp_r0_14 = M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x40), u8 *, 4);
        var_r0_11 = PanelHasSelection(M2C_FIELD(temp_r0,void **,0x40));
        if (var_r0_11 == 0) {
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
    void func_ov003_021f1858(void);
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
            func_ov003_021f1858();
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
    void func_ov003_021f1858(void);
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
            func_ov003_021f1858();
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

s16 func_ov003_021f3fe4(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 < arg1) {
        var_r0 += arg2 - arg1;
    } else if (var_r0 >= arg2) {
        var_r0 -= arg2 - arg1;
    }
    return (s16) var_r0;
}

u8 func_ov003_021f400c(void) {
    s32 IsLinkSessionActive();
    u32 GetSessionPlayerCount();
    s32 result;
    if (IsLinkSessionActive() && GetSessionPlayerCount() <= 1U) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_021f4038(void) {
    s32 IsLinkSessionActive();
    s32 IsLocalSessionHost();
    s32 result;
    if (IsLinkSessionActive() && IsLocalSessionHost()) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_021f4064(void) {
    s32 IsLinkSessionActive();
    s32 IsLocalSessionGuest();
    s32 result;
    if (IsLinkSessionActive() && IsLocalSessionGuest()) result = 1;
    else result = 0;
    return result;
}

void func_ov003_021f4090(M2C_UNK arg0) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    Link_CreateStartRequest(0x4D4C5342, arg0);
}

