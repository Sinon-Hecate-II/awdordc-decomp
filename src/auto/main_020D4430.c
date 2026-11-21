/* 54 functions from 0x020D4430 to 0x020D5430 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
void UpdateMapCursor(void);
void UpdateUnitSelectCursor(void);
void UpdateAimingCursor(void);

void func_020d4430(void){extern void **gCurrentMap;if((s32)M2C_FIELD(*gCurrentMap,u16*,0x52a2)>1)func_020a2b84(M2C_FIELD(*gCurrentMap,u16*,0x52a4));func_ov000_0216a86c();M2C_FIELD(*gCurrentMap,u16*,0x52b0)=6;}

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
func_020994e0(0);
if(IsPlayerCursorOwner(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))){
state=(u8 *)*gCurrentMap+0x67a4+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c;
StepMapViewToTile(M2C_FIELD(state,u8 *,0x2d),M2C_FIELD(state,u8 *,0x2e));
}
if(IsMapViewScrolling())return;
func_020a2b84(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
RefreshMapCursorCellCache();BeginWeatherResetTransition();func_020a694c();ApplyTurnRepairs();RefreshMapView();
M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=7;
}

void func_020d457c(void){extern void **gCurrentMap;if(func_0208f8a0())return;BuildArmyInfoWindow();if(M2C_FIELD(*gCurrentMap,u16*,0x52a2)==1){if(M2C_FIELD(*gCurrentMap,u16*,0x52a4)==1)M2C_FIELD(*gCurrentMap,u16*,0x52b0)=10;else M2C_FIELD(*gCurrentMap,u16*,0x52b0)=9;}else M2C_FIELD(*gCurrentMap,u16*,0x52b0)=8;}

void func_020d45d8(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=M2C_FIELD(*gCurrentMap,u16*,0x52b2);M2C_FIELD(*gCurrentMap,u16*,0x52b2)=0;func_020ca4c0();}

void func_020d4614(void){extern void **gCurrentMap;if(IsDialogActive())return;func_020d33ec();func_020cce4c();M2C_FIELD(*gCurrentMap,u16*,0x52b0)=0;}

void func_020d464c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=20;}

void func_020d466c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=13;}

void func_020d468c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ac)=1;}

void func_020d46ac(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ac)=0;}

u8 func_020d46cc(void) {
    extern void **gCurrentMap;
    return M2C_FIELD(*gCurrentMap, u8 *, 0x52AC);
}

s32 func_020d46e8(void){extern void **gCurrentMap;return M2C_FIELD(*gCurrentMap,s8*,0x52aa);}

void func_020d4704(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,0x52aa)++;}

void func_020d472c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,0x52aa)--;}

void func_020d4754(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,0x52aa)=0;}

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
    M2C_UNK func_020d4ae8();
    M2C_UNK func_020b1ae0();
    func_020b1ae0();
    func_020d4ae8();
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

void func_020d4960(void *arg0){extern M2C_UNK gBattleEndState; void *func_02084cc0(void *); void func_02086330(void *); if(M2C_FIELD(&gBattleEndState,u8*,0)==0)return;func_02086330(func_02084cc0(arg0));}

/* Hand the finished battle over to its ending: in team mode (config mode 0) pick
 * the special ending when the player won on map BA with the clear counter at 1,
 * otherwise the standard one; in free-play mode (mode 1) choose the ending from
 * the recorded battle-end conditions and then clear that record. */
void FinishBattle(void) {
    M2C_UNK func_02088634();
    M2C_UNK func_0209f858();
    s32 DidPlayerWin();
    M2C_UNK func_020cd5ac();
    M2C_UNK func_020d887c();
    M2C_UNK func_020d88ac();
    M2C_UNK func_020d895c();
    M2C_UNK func_020d8cc8();
    s32 func_020e4b54();
    extern s32 gSaveSlotSummary;
    extern M2C_UNK gBattleEndState;
    extern u16 gMapConfig;
    u32 battleMode;

    battleMode = (u32) (gMapConfig << 0x1D) >> 0x1D;
    switch ((u8) battleMode) {
    case 0:
        if ((DidPlayerWin() != 0) && (func_020e4b54() != 0) && (((u32) (gSaveSlotSummary << 8) >> 0x18) == 1)) {
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
                func_020d895c();
            }
            func_020d8cc8();
            func_0209f858();
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
func_020b1ae0();
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),void(**)(void),0x50);
if(callback)callback();
InitBattleMapPresentation();
func_020a2b84(M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER));
func_020d93a8();
}

void func_020d4ac8(s16 arg0) {
    extern M2C_UNK data_0212bdcc;
    M2C_FIELD(CreateSpriteFromClass(&data_0212bdcc, 7), s16 *, 0x34) = arg0;
}

int func_020d4ae8(void){extern void **gCurrentMap;int (*cb)(void);func_020d3d24();cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),int(**)(void),0x4c);if(cb)cb();cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),int(**)(void),0x50);if(cb)return cb();return (int)cb;}

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

int func_020d4ba4(void){func_020a44e8();func_020d4d78();func_020d33ec();func_ov000_021696d4();func_02090034(1,10);func_02090034(2,10);}

M2C_UNK RestoreBattleMapView(void){extern void **gCurrentMap;void (*cb)(void)=M2C_FIELD(gCurrentMap[1],void (**)(void),0x50);if(cb)cb();LoadScenePanelGraphicsOnBothEngines();InitBattleMapPresentation();RefreshMapView();}

void func_020d4c08(void) {
    M2C_UNK func_020d4ba4();
    M2C_UNK func_020d8e28();
    func_020d8e28();
    func_020d4ba4();
}

void func_020d4c18(void) {
    M2C_UNK CreateSubScreenUi();
    M2C_UNK RestoreBattleMapView();
    RestoreBattleMapView();
    CreateSubScreenUi();
}

void func_020d4ca4(void *);
void func_020d4c28(void *arg0){G3X_Reset();func_02077c10();func_020d4ca4(arg0);}

void func_020d4c44(void) {
    M2C_UNK StepBattleMap();
    StepBattleMap();
}

void *func_020d4cd4(void);
u8 func_020d4cb0(void *);
void func_020d4cc8(void *);
void func_020d4c50(void){void *p=func_020d4cd4();if(!p)return;if(!func_020d4cb0(p))return;func_02077c64();func_02077c78();func_020d4cc8(p);}

void func_020d4c80(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK func_01ffaa0c(u16);
    func_01ffaa0c((u16) M2C_FIELD(arg0, s32 *, 0x5C));
    Sprite_ResumeAnimation(arg0);
}

void func_020d4ca4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 1;
}

u8 func_020d4cb0(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020d4cc8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void *func_020d4cd4(void) {
    void *func_01ffa860(M2C_UNK *, s32);
    extern M2C_UNK data_0212bd84;
    return func_01ffa860(&data_0212bd84, 0xFF03);
}

/* Create the battle map view's three sprite objects (the map itself and its two
 * overlay layers) at the view's Z marker, unless one of them is already there.
 * The map's object starts out not pending; the secondary engine is updated too
 * once the battle has ended. */
void CreateBattleMapViewSprites(void) {
    s32 FindObjectByZ(s32);
    s32 CreateSpriteFromClass(void *, s32);
    void SetSpriteZ(s32, s32);
    void func_020d4cc8(void *);
    extern M2C_UNK data_0212bd84, data_0212bdb4, data_0212bd9c;
    extern M2C_UNK gBattleEndState;
    s32 map;

    if (FindObjectByZ(BATTLE_END_SPRITE_Z)) return;
    map = CreateSpriteFromClass(&data_0212bd84, 4);
    SetSpriteZ(map, BATTLE_END_SPRITE_Z);
    func_020d4cc8((void *)map);
    SetSpriteZ(CreateSpriteFromClass(&data_0212bdb4, 6), BATTLE_END_SPRITE_Z);
    SetSpriteZ(CreateSpriteFromClass(&data_0212bd9c, 10), BATTLE_END_SPRITE_Z);
    if (M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_ENDED)) CreateSubScreenLinkIndicator();
}

int func_020d4d78(void){s32 FindObjectByZ(s32);void *func_0209cce4(void (*)(void *),int);if(!FindObjectByZ(0xff03))return;M2C_FIELD(func_0209cce4(func_020d4c80,2),s32*,0x5c)=0xff03;}

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
case 4:func_020d61ac();break;
case 5:UpdateMapTargetCursor();break;
case 6:func_020d6310();break;
case 7:func_020d6350();break;
case 8:UpdateMapSelectionCursor();break;
case 9:func_020d54b4();break;
case 10:func_020d54b8();break;
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
s32 func_020d8f60(void); s32 func_020bd13c(void); s32 func_ov000_0216ab64(s32); s32 func_020bc910(void); s32 HandleMapTouchRelease(void);
s32 hadSelection, cancelled, playSound, key;
hadSelection=func_020d8f60();
cancelled=0; playSound=0;
key=func_020bd13c();
switch(key) { case 0x1000: playSound=1; break; case 0: cancelled=1; playSound=1; break; }
if(playSound) { func_020cf828(0x1001a); func_0207a7a4(1,4); }
MapCursor_StepTowardTarget(0);
if(IsMapCursorIdle()) {
if(func_ov000_0216ab64(1)) return;
switch(key) {
case 0: case 0x20: case 0x1000:
if(func_020bc910()) return;
if(HandleMapTouchRelease()) return;
break;
case 0x10: func_020c752c(); return;
case 0x100: CreateMapMenu(); return;
case 0x40: func_020d8fa0(); break;
case 0x80: break;
}
}
DrawUnitInfoPanel(0);
if(!cancelled) return;
func_020bdfa8(); func_020be078();
if(!hadSelection) return;
func_020be044();
}

void func_020d5068(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b4)=0;}

u8 func_020d5088(void *arg0) {
    s32 func_020a735c();
    u8 var_r0;

    if (func_020a735c() != 0x14) {
        return 0U;
    }
    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Update the battle-map aiming cursor each frame: choose the cursor graphic for
 * the aimed tile (a unit that can act, a reachable tile, or an empty/locked one),
 * then act on the keys - confirm moves the cursor to the aimed tile, dismiss
 * selects the unit under it and closes the target cursor, and R/X open the
 * related menus. */
void UpdateAimingCursor(void) {
 extern void **gCurrentMap;
 extern u8 data_0211fbc4[];
 u32 func_020bca68(void);
 u32 GetTouchReleaseKeyAction(void);
 void *map;
 u32 keys;
 func_020cf850(0x1001a);
 func_0207a7a4(1,4);
 map=*gCurrentMap;
 if (M2C_FIELD(M2C_FIELD((u8*)map+M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y)*4, s8 **,MAP_GRID)+M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X),s8*,0)>110) {
 MapCursor_StepTowardTarget(2);
 } else if(func_020d5088(M2C_FIELD(map,void**,MAP_CURSOR_UNIT))) {
 map=*gCurrentMap;
 if(M2C_FIELD((u8*)map+(M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X)+M2C_FIELD((u8*)map+M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y)*2,u16*,MAP_ROW_OFFSETS)),s8*,MAP_CELL_ORDER)>=0) {
 StepMapCursorAndNotifyOffset(1,GetUnitAttackRangeMax(M2C_FIELD(map,void**,MAP_CURSOR_UNIT)));
 } else MapCursor_StepTowardTarget(1);
 } else {
 map=*gCurrentMap;
 if(func_020ba790(M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X),M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y)))MapCursor_StepTowardTarget(2);
 else MapCursor_StepTowardTarget(1);
 }
 if(IsMapCursorIdle()){
 keys=0;
 keys|=func_020bca68();
 keys|=GetTouchReleaseKeyAction();
 if(keys&0x10){ /* confirm the aimed tile */
 map=*gCurrentMap;
 MoveCursorTo(M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_X),M2C_FIELD(map,s16*,MAP_CURSOR_TARGET_Y));
 func_0207b040();
 } else if(keys&0x20) { /* select the unit under the cursor */
 map=M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT);
 StepMapViewToTile(M2C_FIELD(map,u8*,MAP_UNIT_X),M2C_FIELD(map,u8*,MAP_UNIT_Y));
 func_ov000_021696d4();
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
 else if(keys&0x40)func_020d8fa0(); /* X close */
 }
 DrawUnitInfoPanel(2);
}

void CloseAimingCursor(void){extern void **gCurrentMap;func_020b2268();PlaySoundEffect(0x1000f);M2C_FIELD(*gCurrentMap,u16*,0x52b4)=0;}

/* Aim-cursor handler for battle-map mode 3: shows the cursor over the aimed tile
   and, when that tile holds one of the current player's ready units, on confirm
   records command 0x10 for that unit and points the map cursor at it; B cancels,
   R opens the map menu and X closes it. */
void UpdateUnitSelectCursor(void) {
extern void **gCurrentMap;
s32 IsSelectableUnitAt(s32,s32);
s32 func_020bcaf0(void);
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
keys |= func_020bcaf0();
keys |= GetAimCursorTouchAction();
if(keys&0x20) {CloseAimingCursor();return;}
if(keys&0x100) {CreateMapMenu();return;}
if(keys&0x40) {func_020d8fa0();return;}
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

