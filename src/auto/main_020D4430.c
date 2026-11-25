/* 54 functions from 0x020D4430 to 0x020D5430 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
void UpdateMapCursor(void);
void UpdateUnitSelectCursor(void);
void UpdateAimingCursor(void);

/* Turn-start setup step (MAP_STATE_TURN_START_SETUP): from the second turn on,
 * start the current player's music, run the map event's turn-start script, then
 * advance to MAP_STATE_TURN_START. */
void TurnStartSetupStep(void) {
    extern void **gCurrentMap;
    if ((s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_TURN) > 1) PlayPlayerMusic(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    RunTurnStartEvent();
    M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) = MAP_STATE_TURN_START;
}

/* Advances the battle state machine one step: bail out when locked or busy,
   handle the current entry's pending flag, otherwise run the step sequence. */
void func_020d447c(void) {
extern void **gCurrentMap;
void RefreshMapCursorCellCache(void);
u8 IsMapViewScrolling(void);
void *state;
if(IsDialogActive())return;
if(IsMapViewScrolling())return;
state=*gCurrentMap;
if(M2C_FIELD((u8 *)state+M2C_FIELD(state,u16 *,0x52a4)*0x8c,u8 *,0x67bd)){
M2C_FIELD(state,u16 *,0x52b0)=1;return;
}
ResetTextTiles(0);
if(IsPlayerCursorOwner(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))){
state=(u8 *)*gCurrentMap+0x67a4+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c;
StepMapViewToTile(M2C_FIELD(state,u8 *,0x2d),M2C_FIELD(state,u8 *,0x2e));
}
if(IsMapViewScrolling())return;
PlayPlayerMusic(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
RefreshMapCursorCellCache();BeginWeatherResetTransition();func_020a694c();ApplyTurnRepairs();RefreshMapView();
M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=7;
}

/* Turn-banner step (MAP_STATE_TURN_BANNER): once the music fade-out from the last
 * phase has finished, build the army-info window and pick the turn-intro step -
 * TURN_INTRO3 for player 1 on the first turn, TURN_INTRO2 for the other players
 * then, TURN_INTRO1 on later turns. */
void TurnBannerStep(void){extern void **gCurrentMap;if(IsMusicFadingOut())return;BuildArmyInfoWindow();if(M2C_FIELD(*gCurrentMap,u16*,MAP_TURN)==1){if(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)==1)M2C_FIELD(*gCurrentMap,u16*,MAP_STATE)=MAP_STATE_TURN_INTRO3;else M2C_FIELD(*gCurrentMap,u16*,MAP_STATE)=MAP_STATE_TURN_INTRO2;}else M2C_FIELD(*gCurrentMap,u16*,MAP_STATE)=MAP_STATE_TURN_INTRO1;}

/* MAP_STATE_RETURN step: go back to the state saved in MAP_RETURN_STATE, clear
 * that slot, then check whether the battle has ended. */
void MapStateReturnStep(void) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) = M2C_FIELD(*gCurrentMap, u16 *, MAP_RETURN_STATE);
    M2C_FIELD(*gCurrentMap, u16 *, MAP_RETURN_STATE) = 0;
    CheckBattleEnd();
}

/* Battle-finish step (MAP_STATE_BATTLE_FINISH): wait while a dialog is still up,
 * then stop the battle turn timer, create the battle-finish sprite and leave the
 * map state machine stopped (MAP_STATE_NONE). */
void BattleFinishStep(void) {
    extern void **gCurrentMap;

    if (IsDialogActive()) return;
    DisableBattleTurnTimer();
    func_020cce4c();
    M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) = MAP_STATE_NONE;
}

void func_020d464c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=20;}

void func_020d466c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=13;}

void SetMapCommandPending(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ac)=1;}

void ClearMapCommandPending(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ac)=0;}

u8 IsMapCommandPending(void) {
    extern void **gCurrentMap;
    return M2C_FIELD(*gCurrentMap, u8 *, 0x52AC);
}

s32 GetMapViewHoldCount(void){extern void **gCurrentMap;return M2C_FIELD(*gCurrentMap,s8*,MAP_VIEW_HOLD);}

void AcquireMapViewHold(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,MAP_VIEW_HOLD)++;}

void ReleaseMapViewHold(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,MAP_VIEW_HOLD)--;}

void ResetMapViewHold(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,MAP_VIEW_HOLD)=0;}

u8 IsUnitMoveActive(void){extern void **gCurrentMap;return M2C_FIELD(*gCurrentMap,u8*,0x52ab);}

void func_020d4790(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ab)=1;}

void func_020d47b0(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ab)=0;}

void EnableMapConfirm(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ad)=1;}

void DisableMapConfirm(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ad)=0;}

u8 IsMapConfirmEnabled(void){extern void **gCurrentMap;return M2C_FIELD(*gCurrentMap,u8*,0x52ad);}

/* Normalize the current map/arena id into the base slot (225), copying its
   entry there when it falls in the arena range [225,425). */
void func_020d482c(void) {
    extern void **gCurrentMap;
    extern u16 gMapConfig;
    void *GetMapRecord(s32);
    s32 func_020a89a4(s32);
    void *dst;
    u32 mapId;
    s32 inRange;

    if ((u8)((u32)(gMapConfig << 29) >> 29) == 0)
        InitBattleMapConfig();
    if (IsLinkSessionActive()) {
        mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
        inRange = 0;
        if (mapId >= 225)
            inRange = mapId < 425;
        if (inRange) {
            dst = GetMapRecord(225);
            MI_CpuCopy32(GetMapRecord(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)), dst, 84);
            M2C_FIELD(*gCurrentMap, u16 *, 0x5142) = 225;
        }
        if (func_02084830())
            M2C_FIELD(&gMapConfig, u16 *, 4) = func_020a89a4(M2C_FIELD(*gCurrentMap, u16 *, 0x5142));
    }
    ResetDialogUI();
    MapSettings_SavePlayers(0);
    AddRecordValue(25, 1);
}

void func_020d4928(void) {
    M2C_UNK CreateSubScreenUi();
    M2C_UNK InitBattleMapPresentation();
    M2C_UNK InitPlayerCursorPositions();
    M2C_UNK LoadCurrentMap();
    M2C_UNK SetupBattleMapView();
    M2C_UNK SetDefaultMapView();
    SetDefaultMapView();
    SetupBattleMapView();
    LoadCurrentMap();
    InitPlayerCursorPositions();
    InitBattleMapPresentation();
    CreateSubScreenUi();
}

void func_020d4948(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212be74;
    CreateSpriteFromClass(&data_0212be74, 7);
}

void func_020d4960(void *arg0){extern M2C_UNK gBattleEndState; void *CreateSessionDepartureObject(void *); void DeleteVoiceChatWidgets(void *); if(M2C_FIELD(&gBattleEndState,u8*,0)==0)return;DeleteVoiceChatWidgets(CreateSessionDepartureObject(arg0));}

/* Hand the finished battle over to its ending: in team mode (config mode 0) pick
 * the special ending when the player won on map BA with the clear counter at 1,
 * otherwise the standard one; in free-play mode (mode 1) choose the ending from
 * the recorded battle-end conditions and then clear that record. */
void FinishBattle(void) {
    M2C_UNK func_02088634();
    M2C_UNK ResetBattleEndState();
    s32 DidPlayerWin();
    M2C_UNK func_020cd5ac();
    M2C_UNK func_020d887c();
    M2C_UNK func_020d88ac();
    M2C_UNK SetMapConfigMode1();
    M2C_UNK func_020d8cc8();
    s32 IsFinalCampaignMap();
    extern s32 gSaveSlotSummary;
    extern M2C_UNK gBattleEndState;
    extern u16 gMapConfig;
    u32 battleMode;

    battleMode = (u32) (gMapConfig << 0x1D) >> 0x1D;
    switch ((u8) battleMode) {
    case 0:
        if ((DidPlayerWin() != 0) && (IsFinalCampaignMap() != 0) && (((u32) (gSaveSlotSummary << 8) >> 0x18) == 1)) {
            func_020d88ac();
            return;
        }
        func_02088634();
        func_020cd5ac();
        return;
    case 1:
        if (M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_ENDED) != 0) {
            if ((M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_FLAG1) != 0) || ((M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_FLAG2) != 0) && (M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_FLAG3) == 0))) {
                func_020d887c();
            } else {
                SetMapConfigMode1();
            }
            func_020d8cc8();
            ResetBattleEndState();
            return;
        }
        func_020d887c();
        return;
    }
}

void func_020d4a50(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212be0c;
    CreateSpriteFromClass(&data_0212be0c, 7);
}

/* Start callback of the saved-battle loading sprite: reset the battle map, resume
 * the save type stored in the sprite (+0x34), restore the view controller and
 * rebuild the battle presentation, its UI and the current player's music. */
void ResumeSavedBattleView(void *sprite) {
extern void **gCurrentMap;
void (*callback)(void);
ResetBattleMap();
ResumeSavedBattle(M2C_FIELD(sprite,s16*,0x34));
func_020d1c38();
SetDefaultMapView();
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),void(**)(void),0x50);
if(callback)callback();
InitBattleMapPresentation();
PlayPlayerMusic(M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER));
func_020d93a8();
}

void func_020d4ac8(s16 arg0) {
    extern M2C_UNK data_0212bdcc;
    M2C_FIELD(CreateSpriteFromClass(&data_0212bdcc, 7), s16 *, 0x34) = arg0;
}

/* Reset and start the battle map, then run the map-view controller's callbacks:
 * its setup callback after the load, and its restore callback (whose result is
 * returned) before the presentation is built. */
int SetupBattleMapView(void) {
    extern void **gCurrentMap;
    int (*cb)(void);

    ResetBattleMapAndBeginPhase();
    cb = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, MAP_VIEW_PTR), int (**)(void), MAPVIEW_SETUP_CB);
    if (cb) cb();
    cb = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, MAP_VIEW_PTR), int (**)(void), MAPVIEW_RESTORE_CB);
    if (cb) return cb();
    return (int)cb;
}

extern void CreateBattleMapViewSprites(void);
extern void CreateWeatherEffectSprite(void);
extern void EnableBattleTurnTimer(void);
extern void RefreshMapCursorCellCache(void);
extern int IsLinkSessionActive(void);
extern void CreateSubScreenLinkIndicator(void);
extern void PlaySlotScriptedSoundAtVolume(int, int, int, int);
/* Set up the battle display and restart its turn timer and scripted audio. */
int InitBattleMapPresentation(void) {
    extern void **gCurrentMap;
    void (*setupView)(void);
    void *viewController;

    viewController = (void *)gCurrentMap;
    viewController = ((void **)viewController)[MAPVIEW_CONTROLLER_INDEX];
    setupView = M2C_FIELD(viewController, void (**)(void), MAPVIEW_INIT_PRESENTATION);

    if (setupView != 0) {
        setupView();
    }

    CreateBattleMapViewSprites();
    CreateWeatherEffectSprite();
    EnableBattleTurnTimer();
    RefreshMapCursorCellCache();

    if (IsLinkSessionActive() == 1) {
        CreateSubScreenLinkIndicator();
    }

    PlaySlotScriptedSoundAtVolume(1, -1, 0x108, 0);
    PlaySlotScriptedSoundAtVolume(2, -1, 0x109, 0);
}

/* Tear down the main engine's battle presentation: drop the weather-effect and
 * battle-end sprites, stop the unit-move objects and the battle turn timer, and
 * silence the battle's two scripted sound slots. */
int ShutdownBattleMapPresentation(void) {
    DeleteWeatherEffectSprites();
    ScheduleBattleEndSpriteRemoval();
    DisableBattleTurnTimer();
    DeleteAllUnitMoveObjects();
    StopSlotSound(1, 10);
    StopSlotSound(2, 10);
}

/* Restore the battle map view (save resume): run the view's restore callback,
 * then rebuild the scene panel graphics and the battle map view. */
M2C_UNK RestoreBattleMapView(void) {
    extern void **gCurrentMap;
    M2C_UNK LoadScenePanelGraphicsOnBothEngines();
    M2C_UNK RefreshMapView();
    void (*restoreView)(void);
    void *viewController;

    viewController = (void *)gCurrentMap;
    viewController = ((void **)viewController)[MAPVIEW_CONTROLLER_INDEX];
    restoreView = M2C_FIELD(viewController, void (**)(void), MAPVIEW_RESTORE_CB);

    if (restoreView != 0) {
        restoreView();
    }

    LoadScenePanelGraphicsOnBothEngines();
    InitBattleMapPresentation();
    RefreshMapView();
}

void func_020d4c08(void) {
    M2C_UNK ShutdownBattleMapPresentation();
    M2C_UNK RebuildSubScreenUi();
    RebuildSubScreenUi();
    ShutdownBattleMapPresentation();
}

void func_020d4c18(void) {
    M2C_UNK CreateSubScreenUi();
    M2C_UNK RestoreBattleMapView();
    RestoreBattleMapView();
    CreateSubScreenUi();
}

void func_020d4ca4(void *);
void func_020d4c28(void *arg0){G3X_Reset();UpdateMapView();func_020d4ca4(arg0);}

void func_020d4c44(void) {
    M2C_UNK StepBattleMap();
    StepBattleMap();
}

void *FindBattleMapObject(void);
u8 IsBattleMapFramePending(void *);
void ClearBattleMapFramePending(void *);
/* Draw the battle map's requested frame: when the map's sprite object (at
 * BATTLE_END_SPRITE_Z) exists and has a frame pending, reset the renderer, render
 * the map, swap the display buffers and clear the pending request. */
void DrawBattleMapFrame(void){
    void *map = FindBattleMapObject();
    if(!map) return;
    if(!IsBattleMapFramePending(map)) return;
    func_02077c64();
    func_02077c78();
    ClearBattleMapFramePending(map);
}

void RemoveBattleEndSpritesTask(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK DeleteSpriteObjectsWithZ(u16);
    DeleteSpriteObjectsWithZ((u16) M2C_FIELD(arg0, s32 *, 0x5C));
    Sprite_ResumeAnimation(arg0);
}

void func_020d4ca4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 1;
}

u8 IsBattleMapFramePending(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void ClearBattleMapFramePending(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void *FindBattleMapObject(void) {
    void *Find3DSpriteByClassAndZ(M2C_UNK *, s32);
    extern M2C_UNK data_0212bd84;
    return Find3DSpriteByClassAndZ(&data_0212bd84, 0xFF03);
}

/* Create the battle map view's three sprite objects (the map itself and its two
 * overlay layers) at the view's Z marker, unless one of them is already there.
 * The map's object starts out not pending; the secondary engine is updated too
 * once the battle has ended. */
void CreateBattleMapViewSprites(void) {
    s32 FindObjectByZ(s32);
    s32 CreateSpriteFromClass(void *, s32);
    void SetSpriteZ(s32, s32);
    void ClearBattleMapFramePending(void *);
    extern M2C_UNK data_0212bd84, data_0212bdb4, data_0212bd9c;
    extern M2C_UNK gBattleEndState;
    s32 map;

    if (FindObjectByZ(BATTLE_END_SPRITE_Z)) return;
    map = CreateSpriteFromClass(&data_0212bd84, 4);
    SetSpriteZ(map, BATTLE_END_SPRITE_Z);
    ClearBattleMapFramePending((void *)map);
    SetSpriteZ(CreateSpriteFromClass(&data_0212bdb4, 6), BATTLE_END_SPRITE_Z);
    SetSpriteZ(CreateSpriteFromClass(&data_0212bd9c, 10), BATTLE_END_SPRITE_Z);
    if (M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_ENDED)) CreateSubScreenLinkIndicator();
}

/* When the battle-end sprite set is present, queue a frame-callback task that
 * removes it: the task deletes every sprite object at BATTLE_END_SPRITE_Z. */
int ScheduleBattleEndSpriteRemoval(void) {
    s32 FindObjectByZ(s32);
    void *CreateFrameCallbackTask(void (*)(void *), int);
    if (!FindObjectByZ(BATTLE_END_SPRITE_Z)) return;
    M2C_FIELD(CreateFrameCallbackTask(RemoveBattleEndSpritesTask, 2), s32 *, 0x5C) = BATTLE_END_SPRITE_Z;
}

u8 func_020d4dac(void) {
    s32 FindObjectByZ(s32);
    u8 var_r0;

    if (FindObjectByZ(0xFF03) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsMapCursorIdle(void){extern void **gCurrentMap;return (M2C_FIELD(*gCurrentMap,u8*,0x5154)&15)==0;}

void func_020d5068(void);
/* Runs the per-frame update handler of the battle map's current input mode
   (MAP_MODE): normal cursor, aiming, unit selection, touch selection, etc. */
void UpdateMapMode(void){
extern void **gCurrentMap;
switch(M2C_FIELD(*gCurrentMap,u16*,MAP_MODE)){
case 0:UpdateMapCursor();break;
case 1:func_020d5068();break;
case 2:UpdateAimingCursor();break;
case 3:UpdateUnitSelectCursor();break;
case 4:OpenMapActionMenuAtCursor();break;
case 5:UpdateMapTargetCursor();break;
case 6:UpdateMapCommandReplay();break;
case 7:UpdateMapCursorReturn();break;
case 8:UpdateMapSelectionCursor();break;
case 9:func_020d54b4();break;
case 10:UpdateMapCursorSettle();break;
}
}

/* The interaction state of the battle map for the HUD: whether the local human
 * player is driving the cursor or a menu, or the map shows a non-human turn or
 * is blocked by a dialog or another state. */
int GetMapInputState(void) {
    extern void **gCurrentMap;
    u16 state;
    if (!IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) return MAP_INPUT_NOT_HUMAN;
    if (IsDialogActive()) return MAP_INPUT_BLOCKED;
    state = M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE);
    if (state == 12 || state == 13 || state == 20) {
        switch (M2C_FIELD(*gCurrentMap, u16 *, MAP_MODE)) {
        case 0:
        case 2:
        case 3: return MAP_INPUT_CURSOR;
        case 4:
        case 5: return MAP_INPUT_MENU;
        }
    }
    return MAP_INPUT_BLOCKED;
}

/* Battle-map cursor handler (cursor mode 0): plays the cursor sound when the
 * touch cursor moved or was cancelled, moves the cursor, lets the state's touch
 * handler consume the key, draws the unit-info panel and, on a cancel action,
 * clears the unit selection. */
void UpdateMapCursor(void) {
s32 IsUiCancelAvailable(void); s32 func_020bd13c(void); s32 RunCursorIdleEvent(s32); s32 func_020bc910(void); s32 HandleMapTouchRelease(void);
s32 hadSelection, cancelled, playSound, key;
hadSelection=IsUiCancelAvailable();
cancelled=0; playSound=0;
key=func_020bd13c();
switch(key) { case 0x1000: playSound=1; break; case 0: cancelled=1; playSound=1; break; }
if(playSound) { func_020cf828(0x1001a); func_0207a7a4(1,4); }
MapCursor_StepTowardTarget(0);
if(IsMapCursorIdle()) {
if(RunCursorIdleEvent(1)) return;
switch(key) {
case 0: case 0x20: case 0x1000:
if(func_020bc910()) return;
if(HandleMapTouchRelease()) return;
break;
case 0x10: OpenBattleMenu(); return;
case 0x100: CreateMapMenu(); return;
case 0x40: HandleUiCancel(); break;
case 0x80: break;
}
}
DrawUnitInfoPanel(0);
if(!cancelled) return;
func_020bdfa8(); DrawMapMenuButtonSprite();
if(!hadSelection) return;
func_020be044();
}

void func_020d5068(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b4)=0;}

/* Whether the unit under the cursor is a mobile indirect unit that still has ammo
 * (so the aiming cursor cycles tiles by its attack range). */
u8 IsMobileIndirectUnitWithAmmo(void *unit) {
    s32 GetMapUnitKind(void *);
    u8 hasAmmo;

    if (GetMapUnitKind(unit) != 0x14) {
        return 0U;
    }
    if (((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO) << 0x15) >> 0x1C) != 0) {
        hasAmmo = 1;
    } else {
        hasAmmo = 0;
    }
    return hasAmmo;
}

/* Update the battle-map aiming cursor each frame: choose the cursor graphic for
 * the aimed tile (a unit that can act, a reachable tile, or an empty/locked one),
 * then act on the keys - confirm moves the cursor to the aimed tile, dismiss
 * selects the unit under it and closes the target cursor, and R/X open the
 * related menus. */
void UpdateAimingCursor(void) {
 extern void **gCurrentMap;
 extern u8 data_0211fbc4[];
 u32 GetAimCursorKeyAction(void);
 u32 GetTouchReleaseKeyAction(void);
 void *map;
 u32 keys;
 func_020cf850(0x1001a);
 func_0207a7a4(1,4);
 map=*gCurrentMap;
 if (M2C_FIELD(M2C_FIELD((u8*)map+M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y)*4, s8 **,MAP_GRID)+M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X),s8*,0)>110) {
 MapCursor_StepTowardTarget(2);
 } else if(IsMobileIndirectUnitWithAmmo(M2C_FIELD(map,void**,MAP_CURSOR_UNIT))) {
 map=*gCurrentMap;
 if(M2C_FIELD((u8*)map+(M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X)+M2C_FIELD((u8*)map+M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y)*2,u16*,MAP_ROW_OFFSETS)),s8*,MAP_CELL_ORDER)>=0) {
 StepMapCursorAndNotifyOffset(1,GetUnitAttackRangeMax(M2C_FIELD(map,void**,MAP_CURSOR_UNIT)));
 } else MapCursor_StepTowardTarget(1);
 } else {
 map=*gCurrentMap;
 if(CanLoadUnitAt(M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X),M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y)))MapCursor_StepTowardTarget(2);
 else MapCursor_StepTowardTarget(1);
 }
 if(IsMapCursorIdle()){
 keys=0;
 keys|=GetAimCursorKeyAction();
 keys|=GetTouchReleaseKeyAction();
 if(keys&0x10){ /* confirm the aimed tile */
 map=*gCurrentMap;
 MoveCursorTo(M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X),M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y));
 func_0207b040();
 } else if(keys&0x20) { /* select the unit under the cursor */
 map=M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT);
 StepMapViewToTile(M2C_FIELD(map,u8*,MAP_UNIT_X),M2C_FIELD(map,u8*,MAP_UNIT_Y));
 DeleteAllUnitMoveObjects();
 map=*gCurrentMap;
 if(M2C_FIELD(map,u8*,MAP_CURSOR_CARRIER)) {
 map=M2C_FIELD(map,void**,MAP_CURSOR_UNIT);
 M2C_FIELD(map,u16*,MAP_UNIT_FLAGS)|=0xa;
 }
 RefreshMapView();func_0207a768();func_0207b040();
 M2C_FIELD(*gCurrentMap,u16*,MAP_MODE)=0;
 DeleteSpriteObjectsOfClass(data_0211fbc4);
 PlaySoundEffect(0x1000f);
 } else if(keys&0x100)CreateMapMenu(); /* R menu */
 else if(keys&0x40)HandleUiCancel(); /* X close */
 }
 DrawUnitInfoPanel(2);
}

/* Leave the battle-map aiming cursor: close its sprite slots, play the cancel
 * sound and drop the map back to its idle input mode (MAP_MODE). */
void CloseAimingCursor(void) {
    extern void **gCurrentMap;
    CloseAllActiveSpriteSlots();
    PlaySoundEffect(0x1000f); /* SOUND_MENU_CANCEL */
    M2C_FIELD(*gCurrentMap, u16 *, MAP_MODE) = 0;
}

/* Aim-cursor handler for battle-map mode 3: shows the cursor over the aimed tile
   and, when that tile holds one of the current player's ready units, on confirm
   records command 0x10 for that unit and points the map cursor at it; B cancels,
   R opens the map menu and X closes it. */
void UpdateUnitSelectCursor(void) {
extern void **gCurrentMap;
s32 IsSelectableUnitAt(s32,s32);
s32 GetUnitSelectKeyAction(void);
s32 GetAimCursorTouchAction(void);
s32 valid, keys;
u32 unitId;
void *map;
keys=0;
func_020cf828(0x1001a);
func_0207a7a4(1,4);
valid=IsSelectableUnitAt(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X),M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y));
if(valid) MapCursor_StepTowardTarget(4); else MapCursor_StepTowardTarget(5);
if(!IsMapCursorIdle()) return;
keys |= GetUnitSelectKeyAction();
keys |= GetAimCursorTouchAction();
if(keys&0x20) {CloseAimingCursor();return;}
if(keys&0x100) {CreateMapMenu();return;}
if(keys&0x40) {HandleUiCancel();return;}
if(keys&0x10) {
if(valid) {
map=*gCurrentMap;
unitId=M2C_FIELD(map,u8 *,M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_X)+M2C_FIELD((u8 *)map+M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_Y)*2,u16 *,MAP_ROW_OFFSETS));
SetBattleCommand(0x10,unitId,0,0);
M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT)=(u8 *)map+MAP_UNIT_RECORDS+unitId*MAP_UNIT_STRIDE;
DestroyCursorUnit();
} else CloseAimingCursor();
}
}

