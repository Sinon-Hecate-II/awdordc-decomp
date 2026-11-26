/* 152 functions from 0x020D8BB4 to 0x020D9A98 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "sound.h"
typedef struct { u16 values[6]; } SetupParams12;

/* A UI screen sprite object: it plays its own sprite animation once the slide
 * tween it owns at +0x68 has run its course. */
typedef struct UiScreenSprite {
    u8 pad00[0x68];
    SpriteTween *tween; /* +0x68: slide tween, finished when current == duration */
} UiScreenSprite;

void func_020d8bb4(void) {
M2C_UNK SetTextMode(u32);
s32 func_020bee64();
s32 func_020bf054(s32,s32);
M2C_UNK func_020ceec8();
s32 CheckVersusSaveSlot(s32);
s32 CampaignSaveSlotInUse(s32);
extern M2C_UNK gOptionBits;
extern u16 data_02168f14;
extern s8 gSaveRecordExists;
s32 k,j,t,i; s8 *p;
u16 flags; u32 mode;
flags=data_02168f14;
mode=M2C_FIELD(&gOptionBits,u16 *,6)&15;
data_02168f14=(flags&~7)|3;
SetTextMode(mode);
func_020ceec8();
i=0;p=&gSaveRecordExists;
do {i++;*p=0;p+=1;}while(i<59);
k=0;
do {
switch(k){
case 0:
j=0;
do {t=func_020bf054(k,j);
if(func_020bee64()!=0 || CampaignSaveSlotInUse(j)!=0) (&gSaveRecordExists)[t]=1;else (&gSaveRecordExists)[t]=0;
j++;}while(j<3);
break;
case 1:
t=func_020bf054(k,0);
if(func_020bee64()!=0 && CheckVersusSaveSlot(k)!=0) (&gSaveRecordExists)[t]=1;else (&gSaveRecordExists)[t]=0;
break;
}
k++;
}while(k<=1);
}

void func_020d8cc4(void) {

}

void func_020d8cc8(void) {

}

void func_020d8ccc(s16 arg0) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s16 *, 0x5142) = arg0;
}

void SetUiModeParameter(s32 arg0) {
    extern void *gUiMode;
    M2C_FIELD(gUiMode, s32 *, 8) = arg0;
}

void func_020d8cfc(void) {

}

/* Whether the sub screen's UI object exists: the lookup runs on the sub engine,
 * with the current engine put back afterwards. */
u8 HasSubScreenUi(void) {
    s32 FindObjectByClass(void *);
    extern M2C_UNK gSubScreenUiClass;
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    u8 found;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (FindObjectByClass(&gSubScreenUiClass) != 0) found = 1;
    else found = 0;
    gCur3DSpriteEngine = savedEngine;
    return found;
}

/* Starts the sub-screen UI (UI mode 3) for the requested mode: record the mode and
 * its parameter, clear the previous and current mode, create the sub-screen's
 * sprite on the sub engine and put the old engine back. */
void StartSubScreenUi(M2C_UNK mode, M2C_UNK param) {
    M2C_UNK CreateSpriteFromClass(void *, s32);
    extern void *gUiMode;
    extern M2C_UNK gSubScreenUiClass;
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;

    ((UiModeState *)gUiMode)->param = param;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    ((UiModeState *)gUiMode)->previous = 0;
    ((UiModeState *)gUiMode)->current = 0;
    ((UiModeState *)gUiMode)->requested = mode;
    CreateSpriteFromClass(&gSubScreenUiClass, 8);
    gCur3DSpriteEngine = savedEngine;
}

/* Whether the UI mode switch is still in progress: busy while the screen change
 * that covers the swap is up, while the requested mode has not become current
 * yet, or until the new mode's sprite object has appeared in the sub engine. */
u8 IsUiModeSwitchBusy(void) {
    s32 FindObjectByClass(void *);
    extern void *gUiMode;
    extern M2C_UNK gUiModeSwitchClass;
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    u8 busy;
    if (HasSubScreenUi() == 0) return 0;
    if (((UiModeState *)gUiMode)->requested != ((UiModeState *)gUiMode)->current) return 1;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (FindObjectByClass(&gUiModeSwitchClass) != 0) busy = 1;
    else busy = 0;
    gCur3DSpriteEngine = savedEngine;
    return busy;
}

/* Rebuild the sub-screen UI on the sub engine: create the sprite for the current
 * UI mode and drop the sub-screen UI objects that were up, then restore the
 * engine the caller was drawing on. */
void RebuildSubScreenUi(void) {
    void CreateUiModeSprite(void);
    void DeleteSpriteObjectsOfClass(void *);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub;
    extern M2C_UNK gSubScreenUiClass;
    void *savedEngine;

    if (!HasSubScreenUi()) return;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    CreateUiModeSprite();
    DeleteSpriteObjectsOfClass(&gSubScreenUiClass);
    gCur3DSpriteEngine = savedEngine;
}

/* Enters the sub screen's UI (mode 3): when the sub-screen UI object exists, save
   the current UI mode and switch to mode 3 with the stored parameter, drawing on
   the sub engine. */
void EnterSubScreenUi(void) {
    s32 SetUiMode(s32, s32);
    extern void *gUiMode;
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub;
    void *savedEngine;
    if (!HasSubScreenUi()) return;
    ((UiModeState *)gUiMode)->saved = ((UiModeState *)gUiMode)->current;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    SetUiMode(3, ((UiModeState *)gUiMode)->param);
    gCur3DSpriteEngine = savedEngine;
}

/* Leaves the sub screen (mode 3): when its UI object exists, asks for the mode
 * that was saved while it was up, drawing on the sub engine. */
void LeaveSubScreenUi(void) {
    s32 SetUiMode(s32, s32);
    extern void *gUiMode;
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub;
    void *savedEngine;

    if (!HasSubScreenUi()) return;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    SetUiMode(((UiModeState *)gUiMode)->saved, ((UiModeState *)gUiMode)->param);
    gCur3DSpriteEngine = savedEngine;
}

/* Ask for UI mode `mode` with `param` as the new mode's parameter: returns 0
 * when that mode is already in effect, 1 once the switch is requested. */
s32 SetUiMode(s32 mode, s32 param) {
    extern void *gUiMode;
    if (mode == ((UiModeState *)gUiMode)->current) return 0;
    ((UiModeState *)gUiMode)->requested = mode;
    ((UiModeState *)gUiMode)->param = param;
    return 1;
}

s32 GetUiMode(void){extern void *gUiMode;return M2C_FIELD(gUiMode,s16 *,2);}

/* Whether the X (cancel) key does anything in the current UI mode: mode 1 (the
 * battle map) can toggle the map info window's panel and mode 2 can cancel its
 * screen change. */
s32 IsUiCancelAvailable(void){
s32 Ov000_InfoWindow_CanCancel(void);
s32 IsScreenTransitionEnabled(void);
extern void *gUiMode;
switch(((UiModeState *)gUiMode)->current){
case 1:return Ov000_InfoWindow_CanCancel();
case 2:return IsScreenTransitionEnabled();
default:return 0;
}
}

/* Handles the X (cancel) key for the current UI mode: when the mode can take a
 * cancel, runs its close handler - toggles the battle-info window's panel
 * (mode 1) or cancels the screen transition (mode 2) - plays the close sound
 * and reports the key as consumed. */
s32 HandleUiCancel(void) {
    void Ov000_InfoWindow_Cancel(void);
    void CancelScreenTransition(void);
    void PlaySoundEffect(s32);
    extern void *gUiMode;

    if (!IsUiCancelAvailable()) return 0;
    switch (((UiModeState *)gUiMode)->current) {
    case 1: Ov000_InfoWindow_Cancel(); break;
    case 2: CancelScreenTransition(); break;
    }
    PlaySoundEffect(SOUND_MENU_CLOSE);
    return 1;
}

void func_020d8ff8(void) {
    M2C_UNK DeleteSpriteObjectsWithZ(s32);
    DeleteSpriteObjectsWithZ(0xFF05);
}

void func_020d900c(void) {

}

/* Sub-screen UI script step: while the requested UI mode has not become current
 * yet, restart the sprite's animation at label 2 (the waiting state); once it
 * has, the switch is done and the script carries on. */
void WaitForUiModeSwitch(void *sprite){void GotoSpriteAnimationLabel(void *,s32);extern void *gUiMode;if(M2C_FIELD(gUiMode,s16 *,2)==M2C_FIELD(gUiMode,s16 *,4))return;GotoSpriteAnimationLabel(sprite,2);}

void func_020d903c(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212c4c8;
    CreateSpriteObject(&data_0212c4c8, arg0);
}

/* Apply the UI mode SetUiMode asked for, once the screen change covering it has
 * finished: move the current mode to the previous one, make the requested mode
 * current, and create the mode-switch transition sprite owned by `owner`. */
void ApplyUiModeSwitch(s32 owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gUiModeSwitchClass;
    extern void *gUiMode;
    ((UiModeState *)gUiMode)->previous = ((UiModeState *)gUiMode)->current;
    ((UiModeState *)gUiMode)->current = ((UiModeState *)gUiMode)->requested;
    CreateSpriteObject(&gUiModeSwitchClass, owner);
}

/* Initialises the 3D sprite engine of the current screen: loads the shared setup
   block, runs the sub engine's teardown, clears the sprite bank's low control
   bits, sets up the sprite source banks and texture, then enables the five
   sprite layers (bits 4..8 of the bank's flags word). */
void func_020d908c(void) {
    M2C_UNK ScheduleBattleEndSpriteRemoval(void);
    void Apply3DSpriteLayout(void *);
    void Reset3DSpriteBankState(void);
    void Reset3DSpriteCorners(void);
    void LoadUiGraphics(void);
    void LoadGraphicsBlock(M2C_UNK *, M2C_UNK);
    void OffsetTileIndices(void *, s32, s32);
    void CopyToObjPaletteShadow(M2C_UNK *, s32, s32);
    void LoadScenePanelGraphicsOnBothEngines(void);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern u16 data_020f4ea8[6];
    extern M2C_UNK data_020efad4;
    extern M2C_UNK data_020f28f0;
    extern M2C_UNK data_020f28d0;
    SetupParams12 setup;
    void *savedEngine;
    u16 *volatile bankFlags;
    u16 *volatile layer1;
    u16 *volatile layer2;
    u16 *volatile layer3;
    u16 *volatile layer4;
    u16 *volatile layer5;
    s32 i;
    setup = *(const SetupParams12 *)data_020f4ea8;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    ScheduleBattleEndSpriteRemoval();
    gCur3DSpriteEngine = savedEngine;
    bankFlags = (u16 *)*(void **)gCur3DSpriteEngine;
    *bankFlags = (u16)(*bankFlags & ~7);
    Apply3DSpriteLayout(&setup);
    Reset3DSpriteBankState();
    Reset3DSpriteCorners();
    LoadUiGraphics();
    LoadGraphicsBlock(&data_020efad4, (M2C_UNK)M2C_FIELD(gCur3DSpriteEngine, void **, 0x18));
    LoadGraphicsBlock(&data_020f28f0, (M2C_UNK)M2C_FIELD(gCur3DSpriteEngine, void **, 0x2C));
    OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine, void **, 0x2C), 0x800, 0x1000);
    CopyToObjPaletteShadow(&data_020f28d0, 0x20, 0x20);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x8);
    LoadScenePanelGraphicsOnBothEngines();
    layer1 = (u16 *)*(void **)gCur3DSpriteEngine;
    *layer1 = (u16)(*layer1 | 0x10);
    layer2 = (u16 *)*(void **)gCur3DSpriteEngine;
    *layer2 = (u16)(*layer2 | 0x20);
    layer3 = (u16 *)*(void **)gCur3DSpriteEngine;
    *layer3 = (u16)(*layer3 | 0x40);
    layer4 = (u16 *)*(void **)gCur3DSpriteEngine;
    *layer4 = (u16)(*layer4 | 0x80);
    layer5 = (u16 *)*(void **)gCur3DSpriteEngine;
    *layer5 = (u16)(*layer5 | 0x100);
}

/* Clears the UI screen's two base 3D sprite layers (0 and 1) on the current
 * engine and marks both for rebuild. */
void ClearUiScreenLayers(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(0);
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER1);
}

void func_020d9284(void) {
    M2C_UNK Ov000_InfoWindow_Create();
    Ov000_InfoWindow_Create();
}

void func_020d9290(void) {
    M2C_UNK Ov000_InfoWindow_Destroy();
    Ov000_InfoWindow_Destroy();
}

void func_020d929c(void){void CreateScreenChangeSprite(s32);extern void *gUiMode;CreateScreenChangeSprite(M2C_FIELD(gUiMode,s32 *,8));}

void func_020d92b8(void) {
    M2C_UNK DeleteScreenChangeSprite();
    DeleteScreenChangeSprite();
}

/* Start a dark fade-out (8 frames) on the sub screen, the fade sprite owned by
 * `parent`, unless the sub-screen UI (UI mode 3) is currently up. */
void FadeOutSubScreen(s32 parent) {
    M2C_UNK StartScreenFadeChildren(s32, s32, s32, s32);
    extern void *gUiMode;
    if (((UiModeState *)gUiMode)->current == UI_MODE_SUB_SCREEN) return;
    StartScreenFadeChildren(TRANSITION_MODE_DARK, 8, DS3D_TARGET_SUB, parent);
}

/* Create a dark screen transition (8 frames) on the sub screen, its transition
 * sprite owned by `parent`, unless the sub-screen UI (UI mode 3) is currently up. */
void CreateSubScreenTransition(s32 parent) {
    M2C_UNK CreateScreenTransitionChildren(s32, s32, s32, s32);
    extern void *gUiMode;
    if (((UiModeState *)gUiMode)->current == UI_MODE_SUB_SCREEN) return;
    CreateScreenTransitionChildren(TRANSITION_MODE_DARK, 8, DS3D_TARGET_SUB, parent);
}

/* Create the sprite of the current UI mode from that mode's sprite class: the
 * +0x04 pointer of its record in the per-mode screen class table (read through
 * the data_0212c4fc label), owned by layer 8 of the sub screen's engine. */
void CreateUiModeSprite(void) {
    M2C_UNK CreateSpriteFromClass(void *, s32);
    extern void *gUiMode;
    extern M2C_UNK data_0212c4fc;
    s16 mode;

    mode = ((UiModeState *) gUiMode)->current;
    CreateSpriteFromClass(*(void **) ((u8 *) &data_0212c4fc + mode * UI_MODE_ENTRY_SIZE), 8);
}

/* Create the current UI mode's sprite object owned by `owner` (the mode's class
 * comes from gUiModeSpriteClasses). */
void CreateUiModeChildSprite(s32 owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, s32);
    extern void *gUiMode;
    extern M2C_UNK gUiModeSpriteClasses;

    CreateSpriteObject(*(M2C_UNK **)((u8 *)&gUiModeSpriteClasses + M2C_FIELD(gUiMode, s16 *, 2) * 12), owner);
}

void CreateSubScreenUi(void) {
    void StartSubScreenUi(M2C_UNK, M2C_UNK);
    StartSubScreenUi(1, 0);
}

/* Start the sub-screen UI for the UI mode currently in effect, with that mode's
 * parameter. */
void StartSubScreenUiForCurrentMode(void) {
    extern void *gUiMode;
    StartSubScreenUi(((UiModeState *)gUiMode)->current, ((UiModeState *)gUiMode)->param);
}

void func_020d93c8(void) {
    M2C_UNK func_020da480();
    func_020da480();
}

void func_020d93d4(void) {
    M2C_UNK func_020da7e8();
    func_020da7e8();
}

/* Processes two current-entity slots, creating/updating linked objects for an entity when conditions allow. */
void func_020d93e0(void *entity) {
    s32 IsLinkSessionActive(void);
    s32 IsSessionResultHandled(void);
    s32 GetOverlayEventFlags(void);
    s32 FindTextLayer(void);
    void StartWindowClose(void);
    void *CreateTextLayer(void *);
    void RenderTextLayerMessage(void *, s32, s32, u32);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;

    void *savedEntity;
    s32 i;
    void *created;

    if (!IsLinkSessionActive()) return;
    if (IsSessionResultHandled()) return;
    if (!GetOverlayEventFlags()) return;
    M2C_FIELD(entity, u16 *, 0x48) |= 0x1000;
    if (FindTextLayer()) StartWindowClose();
    savedEntity = gCur3DSpriteEngine;
    for (i = 0; i < 2; i++) {
        gCur3DSpriteEngine = (i == 0) ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        if (M2C_FIELD(entity, u8 *, 0x44) == 0 && gCur3DSpriteEngine != g3DSpriteEngineMain) continue;
        if (M2C_FIELD(entity, u8 *, 0x44) == 1 && gCur3DSpriteEngine != g3DSpriteEngineSub) continue;
        if (M2C_FIELD(entity, u8 *, 0x44) == 3 && gCur3DSpriteEngine != savedEntity) continue;
        created = CreateTextLayer(entity);
        RenderTextLayerMessage(created, 2, M2C_FIELD(entity, u16 *, 0x46) << 5, 0x44000001);
        M2C_FIELD(created, u32 *, 0x58) |= 0x1000;
    }
    gCur3DSpriteEngine = savedEntity;
}

/* Resume a UI screen sprite's own animation once its slide tween has finished
 * (the tween's frame counter has reached its duration). */
void ResumeUiSpriteAnimationWhenTweenDone(void *object) {
    void Sprite_ResumeAnimation(void *);
    SpriteTween *tween;
    u8 finished;

    tween = ((UiScreenSprite *)object)->tween;
    finished = tween->current == tween->duration;
    if (!finished) return;
    Sprite_ResumeAnimation(object);
}

void func_020d9508(void) {
    M2C_UNK func_020daa9c();
    func_020daa9c();
}

void func_020d9514(void) {
    M2C_UNK func_020daaa8();
    func_020daaa8();
}

void func_020d9520(void) {
    M2C_UNK func_020daab4();
    func_020daab4();
}

void func_020d952c(void) {
    M2C_UNK func_020daac0();
    func_020daac0();
}

void func_020d9538(void) {
    M2C_UNK func_020db140();
    func_020db140();
}

void func_020d9544(void) {
    M2C_UNK func_020db14c();
    func_020db14c();
}

void func_020d9550(void) {
    M2C_UNK func_020db158();
    func_020db158();
}

void func_020d955c(void) {
    M2C_UNK func_020db164();
    func_020db164();
}

void func_020d9568(void) {
    M2C_UNK func_020db170();
    func_020db170();
}

void func_020d9574(void) {
    M2C_UNK func_020db188();
    func_020db188();
}

void func_020d9580(void) {
    M2C_UNK func_020db17c();
    func_020db17c();
}

void func_020d958c(void) {
    M2C_UNK func_020db194();
    func_020db194();
}

void func_020d9598(void) {
    M2C_UNK func_020dbd00();
    func_020dbd00();
}

void func_020d95a4(void) {
    M2C_UNK func_020dbd0c();
    func_020dbd0c();
}

void func_020d95b0(void) {
    M2C_UNK func_020dbd18();
    func_020dbd18();
}

void func_020d95bc(void) {
    M2C_UNK func_020dbd24();
    func_020dbd24();
}

void func_020d95c8(void) {
    M2C_UNK func_020dbd30();
    func_020dbd30();
}

void func_020d95d4(void) {
    M2C_UNK func_020dbd3c();
    func_020dbd3c();
}

void func_020d95e0(void) {
    M2C_UNK func_020dbd48();
    func_020dbd48();
}

void func_020d95ec(void) {
    M2C_UNK func_020dbd54();
    func_020dbd54();
}

void func_020d95f8(void) {
    M2C_UNK func_020dbe74();
    func_020dbe74();
}

void func_020d9604(void) {
    M2C_UNK func_020dbe80();
    func_020dbe80();
}

void func_020d9610(void) {
    M2C_UNK func_020dbe8c();
    func_020dbe8c();
}

void func_020d961c(void) {
    M2C_UNK func_020dbe98();
    func_020dbe98();
}

void func_020d9628(void) {
    M2C_UNK func_020dbea4();
    func_020dbea4();
}

void func_020d9634(void) {
    M2C_UNK func_020dbeb0();
    func_020dbeb0();
}

void func_020d9640(void *arg0) {
    M2C_UNK func_ov009_022241dc();
    if (!(M2C_FIELD(arg0, u16 *, 0x48) & 1)) {
        return;
    }
    func_ov009_022241dc();
}

/* Resume the player-list panel's sprite animation, except while this is the
 * local player's panel (flags bit 0) and the single-card link is still
 * announcing the players. */
void ResumePlayerListPanelAnimation(void *panel) {
    s32 IsLinkAnnouncePending();
    if ((M2C_FIELD(panel, u16 *, 0x48) & 1) && (IsLinkAnnouncePending() != 0)) {
        return;
    }
    Sprite_ResumeAnimation(panel);
}

void func_020d9684(void) {
    M2C_UNK func_020dc5e4();
    func_020dc5e4();
}

void func_020d9690(void) {
    M2C_UNK func_020dc5f0();
    func_020dc5f0();
}

void func_020d969c(void) {
    M2C_UNK func_020dc5fc();
    func_020dc5fc();
}

void func_020d96a8(void) {
    M2C_UNK func_020dc608();
    func_020dc608();
}

void func_020d96b4(void) {
    M2C_UNK func_020dca5c();
    func_020dca5c();
}

void func_020d96c0(void) {
    M2C_UNK func_020dca68();
    func_020dca68();
}

void func_020d96cc(void) {
    M2C_UNK func_020dca74();
    func_020dca74();
}

void func_020d96d8(void) {
    M2C_UNK func_020dca80();
    func_020dca80();
}

void func_020d96e4(void) {
    M2C_UNK func_020dcb44();
    func_020dcb44();
}

void func_020d96f0(void) {
    M2C_UNK func_020dcb50();
    func_020dcb50();
}

void func_020d96fc(void) {
    M2C_UNK func_020dcb5c();
    func_020dcb5c();
}

void func_020d9708(void) {
    M2C_UNK func_020dcb68();
    func_020dcb68();
}

void func_020d9714(void) {
    M2C_UNK func_020dd498();
    func_020dd498();
}

void func_020d9720(void) {
    M2C_UNK func_020dd4a4();
    func_020dd4a4();
}

void func_020d972c(void) {
    M2C_UNK func_020dd4b0();
    func_020dd4b0();
}

void func_020d9738(void) {
    M2C_UNK func_020dd4bc();
    func_020dd4bc();
}

void func_020d9744(void) {
    M2C_UNK func_020dd4c8();
    func_020dd4c8();
}

void func_020d9750(void) {
    M2C_UNK func_020dd4d4();
    func_020dd4d4();
}

void func_020d975c(void) {
    M2C_UNK func_020dd4e0();
    func_020dd4e0();
}

void func_020d9768(void) {
    M2C_UNK func_020dd4ec();
    func_020dd4ec();
}

void func_020d9774(void) {
    M2C_UNK func_020dde3c();
    func_020dde3c();
}

void func_020d9780(void) {
    M2C_UNK func_020dde48();
    func_020dde48();
}

void func_020d978c(void) {
    M2C_UNK func_020dde54();
    func_020dde54();
}

void func_020d9798(void) {
    M2C_UNK func_020dde60();
    func_020dde60();
}

void func_020d97a4(void) {
    M2C_UNK func_020dde6c();
    func_020dde6c();
}

void func_020d97b0(void) {
    M2C_UNK func_020dde78();
    func_020dde78();
}

void func_020d97bc(void) {
    M2C_UNK func_020dde84();
    func_020dde84();
}

void func_020d97c8(void) {
    M2C_UNK func_020dde90();
    func_020dde90();
}

void func_020d97d4(void) {
    M2C_UNK func_020ddf78();
    func_020ddf78();
}

void func_020d97e0(void) {
    M2C_UNK func_020ddf84();
    func_020ddf84();
}

void func_020d97ec(void) {
    M2C_UNK func_020ddf90();
    func_020ddf90();
}

void func_020d97f8(void) {
    M2C_UNK func_020ddf9c();
    func_020ddf9c();
}

void func_020d9804(void) {
    M2C_UNK func_020ddfa8();
    func_020ddfa8();
}

void func_020d9810(void) {
    M2C_UNK func_020ddfb4();
    func_020ddfb4();
}

void func_020d981c(void) {
    M2C_UNK func_020ddfc0();
    func_020ddfc0();
}

void func_020d9828(void) {
    M2C_UNK func_020ddfcc();
    func_020ddfcc();
}

void func_020d9834(void) {
    M2C_UNK func_020deb74();
    func_020deb74();
}

void func_020d9840(void) {
    M2C_UNK func_020deb84();
    func_020deb84();
}

void func_020d984c(void) {
    M2C_UNK func_020deb94();
    func_020deb94();
}

void func_020d9858(void) {
    M2C_UNK func_020deba4();
    func_020deba4();
}

void func_020d9864(void) {
    M2C_UNK func_020debb4();
    func_020debb4();
}

void func_020d9870(void) {
    M2C_UNK func_020debc4();
    func_020debc4();
}

void func_020d987c(void) {
    M2C_UNK func_020debd4();
    func_020debd4();
}

void func_020d9888(void) {
    M2C_UNK func_020debe4();
    func_020debe4();
}

void func_020d9894(void) {
    M2C_UNK func_020e0134();
    func_020e0134();
}

void func_020d98a0(void) {
    M2C_UNK func_020e0140();
    func_020e0140();
}

void func_020d98ac(void) {
    M2C_UNK func_020e014c();
    func_020e014c();
}

void func_020d98b8(void) {
    M2C_UNK func_020e0158();
    func_020e0158();
}

void func_020d98c4(void) {
    M2C_UNK func_020e0164();
    func_020e0164();
}

void func_020d98d0(void) {
    M2C_UNK func_020e0170();
    func_020e0170();
}

void func_020d98dc(void) {
    M2C_UNK func_020e017c();
    func_020e017c();
}

void func_020d98e8(void) {
    M2C_UNK func_020e0188();
    func_020e0188();
}

void func_020d98f4(void) {
    M2C_UNK func_020e035c();
    func_020e035c();
}

void func_020d9900(void) {
    M2C_UNK func_020e0368();
    func_020e0368();
}

void func_020d990c(void) {
    M2C_UNK SlideOutOnlineMenu();
    SlideOutOnlineMenu();
}

void func_020d9918(void) {
    M2C_UNK func_020e03ac();
    func_020e03ac();
}

void func_020d9924(void) {
    M2C_UNK DismissOnlineMenu();
    DismissOnlineMenu();
}

void func_020d9930(void) {
    M2C_UNK func_020e0468();
    func_020e0468();
}

void func_020d993c(void) {
    M2C_UNK func_020e0474();
    func_020e0474();
}

void func_020d9948(void) {
    M2C_UNK func_020e0480();
    func_020e0480();
}

void func_020d9954(void) {
    M2C_UNK func_020e048c();
    func_020e048c();
}

void func_020d9960(void) {
    M2C_UNK CreateLinkPlayerMaskListener();
    CreateLinkPlayerMaskListener();
}

void func_020d996c(void) {
    M2C_UNK RefreshLinkPlayerSprites();
    RefreshLinkPlayerSprites();
}

void func_020d9978(void) {
    M2C_UNK func_020e0abc();
    func_020e0abc();
}

void func_020d9984(void) {
    M2C_UNK func_020e0ac8();
    func_020e0ac8();
}

void func_020d9990(void) {
    M2C_UNK func_020e0ad4();
    func_020e0ad4();
}

void func_020d999c(void) {
    M2C_UNK func_020e0ae0();
    func_020e0ae0();
}

void func_020d99a8(void) {
    M2C_UNK func_020e0aec();
    func_020e0aec();
}

void func_020d99b4(void) {
    M2C_UNK func_020e0af8();
    func_020e0af8();
}

void func_020d99c0(void) {
    M2C_UNK func_020e0d84();
    func_020e0d84();
}

void func_020d99cc(void) {
    M2C_UNK func_020e0d90();
    func_020e0d90();
}

void func_020d99d8(void) {
    M2C_UNK func_020e0d9c();
    func_020e0d9c();
}

void func_020d99e4(void) {
    M2C_UNK func_020e0da8();
    func_020e0da8();
}

void func_020d99f0(void) {
    M2C_UNK func_020e0db4();
    func_020e0db4();
}

void func_020d99fc(void) {
    M2C_UNK func_020e0dc0();
    func_020e0dc0();
}

void func_020d9a08(void) {
    M2C_UNK PublishStatusAndStartMatch();
    PublishStatusAndStartMatch();
}

void func_020d9a14(void) {
    M2C_UNK RequestLinkMatchStart();
    RequestLinkMatchStart();
}

void func_020d9a20(void) {
    M2C_UNK PublishStatusAndStartMatch2();
    PublishStatusAndStartMatch2();
}

void func_020d9a2c(void) {
    M2C_UNK ConfirmLinkMenuStart();
    ConfirmLinkMenuStart();
}

void func_020d9a38(void) {
    M2C_UNK PublishStatusAndStartMatch3();
    PublishStatusAndStartMatch3();
}

void func_020d9a44(void) {
    M2C_UNK PublishStatusAndStartMatch4();
    PublishStatusAndStartMatch4();
}

void func_020d9a50(void) {
    M2C_UNK func_020e0ecc();
    func_020e0ecc();
}

void func_020d9a5c(void) {
    M2C_UNK func_020e0ed8();
    func_020e0ed8();
}

void func_020d9a68(void) {
    M2C_UNK func_020e0ee4();
    func_020e0ee4();
}

void func_020d9a74(void) {
    M2C_UNK func_020e0ef0();
    func_020e0ef0();
}

void func_020d9a80(void) {
    M2C_UNK func_020e0efc();
    func_020e0efc();
}

void func_020d9a8c(void) {
    M2C_UNK func_020e0f08();
    func_020e0f08();
}

