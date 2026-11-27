/* 44 functions from 0x020B160C to 0x020B25B8 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ds3dsprite.h"
#include "sprite_slot.h"
#include "battle_map.h"

/* Upload the battle map's graphics to the sprite engine: copy the map tile block
 * and the terrain block, then load the four players' army palettes into OBJ
 * palettes 4..7 and the current player's palette into OBJ palette 3. */
void UploadBattleMapGraphics(void){
s32 func_020a7290(void);void *func_020a7278(void);void *func_020a7284(void);
M2C_UNK MI_CpuCopy32(M2C_UNK *,s32,M2C_UNK);void CopyToObjPaletteShadow(void *,s32,s32);void LoadPlayerArmyPalette(s32);
extern void *gCur3DSpriteEngine;extern void *gCurrentMap;extern u8 gArmyPalettes[];
s32 tileBytes;void *engine;
tileBytes=func_020a7290()<<5;engine=M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0x10);
MI_CpuCopy32(func_020a7278(),engine+0x25c0,tileBytes);
engine=M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0x10)+0x4e0;
MI_CpuCopy32(func_020a7284(),engine+0x3000,0x3c0);
CopyToObjPaletteShadow(gArmyPalettes+(M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+1*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_INDEX_OFF)-1)*32,384,32);
CopyToObjPaletteShadow(gArmyPalettes+(M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+2*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_INDEX_OFF)-1)*32,416,32);
CopyToObjPaletteShadow(gArmyPalettes+(M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+3*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_INDEX_OFF)-1)*32,448,32);
CopyToObjPaletteShadow(gArmyPalettes+(M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+4*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_INDEX_OFF)-1)*32,480,32);
LoadPlayerArmyPalette(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,MAP_CURRENT_PLAYER));}

/* Re-apply the battle map to the map view for its current weather and tileset:
 * clear the unit-move controller slots, upload the scene panel's icon tiles and
 * the under-info panel graphics, then run the view controller's set-terrain
 * callback (MAPVIEW_SET_TERRAIN) with the map's weather and tileset. */
void ApplyMapViewTilesetWeather(void) {
    void ClearUnitMoveSlots(void);
    void LoadScenePanelIconTiles(void);
    void LoadUnderInfoGraphics(void);
    extern void *gCurrentMap;
    void (*setTerrain)(u8, u8);
    void *map;

    ClearUnitMoveSlots();
    LoadScenePanelIconTiles();
    LoadUnderInfoGraphics();
    setTerrain = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, MAP_VIEW_PTR), void (**)(u8, u8), MAPVIEW_SET_TERRAIN);
    if (setTerrain == NULL) {
        return;
    }
    map = M2C_FIELD(gCurrentMap, void **, MAP_DATA_PTR);
    setTerrain(M2C_FIELD(map, u8 *, MAP_WEATHER), M2C_FIELD(map, u8 *, MAP_TILESET));
}

/* Upload the map view's fixed five-tile block into layer 0's VRAM at +0x2480,
 * the tile slot the screen-brighten effect animates. */
void UploadMapViewOverlayTiles(void) {
    M2C_UNK MI_CpuCopy32(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_020f3ca0;
    extern void *gCur3DSpriteEngine;
    MI_CpuCopy32(&data_020f3ca0, M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_LAYER_VRAM) + 0x2480, 0xA0);
}

/* Copy the two 0x800-byte tile blocks of the lower 3D sprite layers from their
 * RAM staging buffers to the layers' VRAM destinations, then load the UI
 * graphics for the top layer. */
void Upload3DSpriteLayerTiles(void) {
 M2C_UNK MI_CpuCopy32(M2C_UNK *,s32,M2C_UNK);
 M2C_UNK LoadUiGraphics();
 extern void *gCur3DSpriteEngine;
 void *engine; s32 vram; M2C_UNK *tiles;
 engine=gCur3DSpriteEngine; vram=M2C_FIELD(engine,volatile s32 *,DS3D_ENGINE_LAYER_VRAM+4); tiles=M2C_FIELD(engine,M2C_UNK * volatile *,DS3D_ENGINE_LAYER_TILES+4);
 MI_CpuCopy32(tiles,vram,0x800);
 engine=gCur3DSpriteEngine; vram=M2C_FIELD(engine,volatile s32 *,DS3D_ENGINE_LAYER_VRAM+8); tiles=M2C_FIELD(engine,M2C_UNK * volatile *,DS3D_ENGINE_LAYER_TILES+8);
 MI_CpuCopy32(tiles,vram,0x800); LoadUiGraphics();
}

void func_020b17dc(void) {
    M2C_UNK func_0207a768();
    M2C_UNK RefreshMapView();
    RefreshMapView();
    func_0207a768();
}

void func_020b17ec(void) {
    void func_020b1800(void);
    M2C_UNK GX_SetBankForObjExtPalette(M2C_UNK);
    func_020b1800();
    GX_SetBankForObjExtPalette(0x40);
}

void func_020b1800(void) {
    M2C_UNK GX_ReleaseBankGrantForObjExtPalette();
    M2C_UNK GX_ReleaseBankGrantForBGExtPalette();
    GX_ReleaseBankGrantForBGExtPalette();
    GX_ReleaseBankGrantForObjExtPalette();
}

/* Assign the VRAM banks the battle map view lays out: texture in A/B, the main
 * engine's BG in D, OBJ in E, OBJ extended palette in F and OBJ palette in G,
 * and the sub engine's BG in C, OBJ in I and BG extended palette in H. */
void SetMapViewVramBanks(void) {
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK GX_SetBankForOBJ(M2C_UNK);
    M2C_UNK GX_SetBankForObjExtPalette(M2C_UNK);
    M2C_UNK GX_SetBankForTex(M2C_UNK);
    M2C_UNK GX_SetBankForOBJExtPltt(M2C_UNK);
    M2C_UNK GX_SetBankForSubBG(M2C_UNK);
    M2C_UNK GX_SetBankForSubOBJ(M2C_UNK);
    M2C_UNK GX_SetBankForBGExtPlttSub(M2C_UNK);
    M2C_UNK GX_ReleaseBankGrants();
    GX_ReleaseBankGrants();
    GX_SetBankForTex(VRAM_BANK_A | VRAM_BANK_B);
    GX_SetBankForBG(VRAM_BANK_D);
    GX_SetBankForOBJ(VRAM_BANK_E);
    GX_SetBankForOBJExtPltt(VRAM_BANK_F);
    GX_SetBankForObjExtPalette(VRAM_BANK_G);
    GX_SetBankForSubBG(VRAM_BANK_C);
    GX_SetBankForSubOBJ(VRAM_BANK_I);
    GX_SetBankForBGExtPlttSub(VRAM_BANK_H);
}

/* The map view's +0x50 setup method: rebuild the battle map's graphics on the
 * main 3D sprite engine (screen mode 3, 1D OBJ mapping), run the view's scroll
 * callback and its graphics upload, copy the map layers and refresh the view,
 * then clear the engine's sprite layers and hand the engine back. */
void InitBattleMapView(void) {
    extern void *gCurrentMap, *gCur3DSpriteEngine, *g3DSpriteEngineMain;
    void *savedEngine;
    void (*callback)(void);
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    ApplyScreenMode(3);
    Init3DSpriteLayers1D();
    InitBattleMapGraphics();
    Reset3DSpriteCorners();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), MAPVIEW_SCROLL_DONE);
    if (callback != NULL) callback();
    LoadScenePanelGraphicsOnBothEngines();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), MAPVIEW_UPLOAD_GRAPHICS);
    if (callback != NULL) callback();
    ApplyMapViewTilesetWeather();
    Upload3DSpriteLayerTiles();
    func_020b17dc();
    ClearAll3DSpriteLayers();
    gCur3DSpriteEngine = savedEngine;
}

/* Sets up the battle-map view on the current 3D sprite engine: configures the
 * screen engine and the sprite bank's OBJ mapping, resets the sprite corners,
 * runs the map-view controller's two callbacks, and uploads the map's tiles,
 * palettes and layer data. */
void InitMapViewScreen(void) {
extern void *gCurrentMap,*gCur3DSpriteEngine;
u16 *volatile bank1;u16 *volatile bank2;void (*callback)(void);
ApplyScreenMode(3);Init3DSpriteLayers2D();
bank1=(u16 *)*(void **)gCur3DSpriteEngine;*bank1=*bank1|DS3D_BANK_OBJ_1D;
bank2=(u16 *)*(void **)gCur3DSpriteEngine;*bank2=*bank2&~DS3D_BANK_OBJ_BOUNDARY_MASK;
Reset3DSpriteCorners();
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x1c);if(callback)callback();
Apply3DSpriteBanks();LoadScenePanelGraphicsOnBothEngines();
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x54);if(callback)callback();
UploadMapViewOverlayTiles();ApplyMapViewTilesetWeather();Upload3DSpriteLayerTiles();func_020b17dc();
}

/* Copy colour `colorIndex` of the shared 16-entry grey ramp (data_020f3c20)
 * into colour 15 of OBJ palette slot `paletteSlot + 11`, then mark the palette
 * dirty; callers step `colorIndex` to pulse that palette's highlight colour. */
void SetObjPaletteRampColor(s32 paletteSlot, s32 colorIndex) {
    M2C_UNK CopyBytesToObjPaletteShadow(void *, s32, M2C_UNK);
    extern u8 data_020f3c20[];
    CopyBytesToObjPaletteShadow(data_020f3c20 + colorIndex * 2, ((paletteSlot + 0xB) << 5) + 0x1E, 2);
}

/* Upload the caller's entry of the army colour table - and the table's first
 * entry - to the two palette rows of a player's army, swapping which row gets
 * which while the player's army icon is animating. */
void func_020b19d0(s32 player, s32 colour) {
    M2C_UNK QueueMainOBJExtPaletteCopy(void *, s32, M2C_UNK, M2C_UNK);
    s32 IsPlayerArmyVariantSet(void);
    extern u8 data_020f3c20[];
    extern void *gCurrentMap;
    s32 playerOffset;
    s32 row1;
    s32 row2;

    if (IsPlayerArmyVariantSet() != 0) {
        row1 = 0;
        row2 = 8;
    } else {
        row1 = 8;
        row2 = 0;
    }
    playerOffset = player * MAP_PLAYER_STRIDE;
    QueueMainOBJExtPaletteCopy(data_020f3c20 + colour * 2, ((row1 + (M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + playerOffset, u8 *, PLAYER_ARMY_INDEX_OFF) - 1)) << 5) + 0x121E, 2, 0);
    QueueMainOBJExtPaletteCopy(data_020f3c20, ((row2 + (M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + playerOffset, u8 *, PLAYER_ARMY_INDEX_OFF) - 1)) << 5) + 0x121E, 2, 0);
}

void func_020b1a84(void) {

}

void func_020b1a88(void) {

}

/* Upload one colour of the OBJ palette's 16-entry brightness ramp (white, down to
 * grey and back - gObjPaletteFadeRamp) to the fixed extended-palette colour at
 * 0x1448: bits 2..5 of `phase` pick the entry, so a caller stepping `phase` makes
 * the colour pulse. */
void UploadPaletteFadeColor(s32 phase) {
    M2C_UNK QueueMainOBJExtPaletteCopy(void *, s32, M2C_UNK, M2C_UNK);
    extern u8 gObjPaletteFadeRamp[];
    QueueMainOBJExtPaletteCopy(gObjPaletteFadeRamp + ((u32)((phase >> 2) << 28) >> 27), 0x1448, 2, 0);
}

/* The battle map view's per-frame callback (MAPVIEW_FRAME_CB): advance the view's
 * own frame tick and the players' army animations with the frame counter. */
void StepMapViewFrame(void) {
    M2C_UNK MapView_UpdateFrame(s32);
    M2C_UNK func_0207ad30(s32);
    extern s32 gFrameCounter;
    MapView_UpdateFrame(gFrameCounter);
    func_0207ad30(gFrameCounter);
}

/* Point the current map at the default battle-map view controller, the one the
 * game uses for a freshly loaded map, the map editor and a resumed save. */
void SetDefaultMapView(void) {
extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *gCurrentMap;
extern u8 gDefaultMapView[];
void *savedEngine=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
M2C_FIELD(gCurrentMap,void **,MAP_VIEW_PTR)=gDefaultMapView;
gCur3DSpriteEngine=savedEngine;
}

u8 SpriteSlotHasFlags(void *arg0, s32 arg1) {
    return (u8) (M2C_FIELD(arg0, u16 *, 0x1C) & arg1);
}

void SetSpriteSlotState(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 3) = arg1;
}

u8 GetSpriteSlotState(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 3);
}

/* Deactivates the sprite slots and resets the manager's focus, screen and pause state. */
void ResetSpriteSlots(void) {
    extern u8 gSpriteSlots[];
    extern void *gSpriteSlotManager;
    s32 slotIndex;
    u8 *slot = gSpriteSlots;

    for (slotIndex = 0; slotIndex < SPRITE_SLOT_COUNT; slotIndex++, slot += SPRITE_SLOT_STRIDE)
        slot[SPRITE_SLOT_VISIBLE] = 0;

    M2C_FIELD(gSpriteSlotManager, s32 *, 0) = 8;
    M2C_FIELD(gSpriteSlotManager, s32 *, 4) = 0;
    M2C_FIELD(gSpriteSlotManager, s32 *, SPRITE_SLOT_MGR_FOCUS) = 0;
    M2C_FIELD(gSpriteSlotManager, u8 *, SPRITE_SLOT_MGR_FOCUS_ID) = 0;
    M2C_FIELD(gSpriteSlotManager, u8 *, SPRITE_SLOT_MGR_SCREEN) = DS3D_TARGET_MAIN;
    M2C_FIELD(gSpriteSlotManager, u8 *, SPRITE_SLOT_MGR_HAS_FOCUS) = 0;
    M2C_FIELD(gSpriteSlotManager, u8 *, SPRITE_SLOT_MGR_UPDATE_PAUSE_DEPTH) = 0;
    M2C_FIELD(gSpriteSlotManager, u8 *, SPRITE_SLOT_MGR_DRAW_PAUSE_DEPTH) = 0;
}

/* The focused slot is interactive while visible and not in its closing/outro animation. */
s32 IsFocusedSpriteSlotInteractive(void) {
    extern void *gSpriteSlotManager;
    void *focusedSlot = M2C_FIELD(gSpriteSlotManager, void **, SPRITE_SLOT_MGR_FOCUS);

    if (!focusedSlot || !M2C_FIELD(focusedSlot, u8 *, SPRITE_SLOT_VISIBLE) ||
        (u8)(M2C_FIELD(focusedSlot, u8 *, SPRITE_SLOT_ANIM) + 253) <= 1) {
        return 0;
    }
    return 1;
}

/* Set the focus frame drawn around a sprite slot from its two corners: the
 * rectangle spans (left, top) to (right, bottom). */
void SetSpriteSlotFrameRect(s16 left,s16 top,s16 right,s16 bottom) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_TL_X)=left;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_TL_Y)=top;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_TR_X)=right;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_TR_Y)=top;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_BL_X)=left;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_BL_Y)=bottom;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_BR_X)=right;
M2C_FIELD(gSpriteSlotManager,s16 *,SPRITE_SLOT_MGR_FRAME_BR_Y)=bottom;
}

/* Set the offsets the sprite-slot focus frame is drawn at, from the top-left
 * corner of its slot (used to scroll a slot's contents in and out). */
void SetSpriteSlotScroll(s16 offsetX, s16 offsetY) {
    extern void *gSpriteSlotManager;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_OFF_X) = offsetX;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_OFF_Y) = offsetY;
}

s32 FocusSpriteSlotById(s32 arg0) {
    s32 FindSpriteSlotById(void);
    M2C_UNK SetSpriteSlotFocus(u8 *, s32);
    SetSpriteSlotFocus((u8 *)FindSpriteSlotById(), arg0);
}

/* Move the sprite-slot focus to the slot whose id is `id` and snap the manager's
 * focus frame onto it without the per-frame easing.  Returns the slot that took
 * focus (its pointer), as FocusSpriteSlotById does. */
s32 SelectSpriteSlot(s32 id) {
    s32 FocusSpriteSlotById(s32);
    void SetSpriteSlotFrameToFocus(void);
    s32 focused;

    focused = FocusSpriteSlotById(id);
    SetSpriteSlotFrameToFocus();
    return focused;
}

void FocusSpriteSlot(u8 *arg0) {
    M2C_UNK SetSpriteSlotFocus(u8 *, s32);
    SetSpriteSlotFocus(arg0, *arg0);
}

/* Stores the new focused slot and invokes its callback when focus moves from an interactive slot. */
M2C_UNK SetSpriteSlotFocus(u8 *slot, s32 slotId) {
    extern void *gSpriteSlotManager;
    void InvokeSpriteSlotFocusCallback(void *);
    s32 changed;

    if (IsFocusedSpriteSlotInteractive() && slot &&
        M2C_FIELD(gSpriteSlotManager, void **, SPRITE_SLOT_MGR_FOCUS) != slot)
        changed = 1;
    else
        changed = 0;

    M2C_FIELD(gSpriteSlotManager, void **, SPRITE_SLOT_MGR_FOCUS) = slot;
    M2C_FIELD(gSpriteSlotManager, u8 *, SPRITE_SLOT_MGR_FOCUS_ID) = slotId;
    if (changed)
        InvokeSpriteSlotFocusCallback(M2C_FIELD(gSpriteSlotManager, void **, SPRITE_SLOT_MGR_FOCUS));
    return (M2C_UNK)M2C_FIELD(gSpriteSlotManager, void **, SPRITE_SLOT_MGR_FOCUS);
}

/* Runs the focused sprite slot's key handler: when the slot has finished its
 * intro, a key is auto-repeating and no touch is down, call the slot's key
 * callback with the slot. */
void HandleFocusedSpriteSlotKey(void){
extern void *gSpriteSlotManager,*gKeyState,*gTouchState;
void *slot;void (*keyCallback)(void *);
if(!IsFocusedSpriteSlotInteractive())return;
slot=M2C_FIELD(gSpriteSlotManager,void **,SPRITE_SLOT_MGR_FOCUS);
if(M2C_FIELD(slot,u8 *,SPRITE_SLOT_ANIM)!=SPRITE_SLOT_ANIM_READY)return;
if(!((KeyState *)gKeyState)->repeat)return;
if(M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE))return;
keyCallback=M2C_FIELD(slot,void (**)(void *),SPRITE_SLOT_KEY_CB);
if(!keyCallback)return;
keyCallback(slot);
}

#pragma push
#pragma opt_common_subs on
void func_020b1d84(void *arg0, s32 arg1, void *arg2) {
extern void *gSpriteSlotManager, *gTouchState, *gCur3DSpriteEngine;
s32 FindSpriteSlotById();
void DrawFrameBorderPulse(s16,s16,s16,s16,u16,s32);
void *p,*q; s32 x,y,r,b,d,v,n,out; s32 force; u16 flags;
FocusSpriteSlotById(M2C_FIELD(gSpriteSlotManager,u8 *,8));
if (!IsFocusedSpriteSlotInteractive()) return;
p=gSpriteSlotManager; q=M2C_FIELD(p,void **,12);
x=M2C_FIELD(q,s16 *,20);y=M2C_FIELD(q,s16 *,22);
b=y+M2C_FIELD(q,s16 *,26); r=x+M2C_FIELD(q,s16 *,24);
force=M2C_FIELD(gTouchState,u8 *,18); if(force==0){
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,16);d=x-v;n=d<0?-d:d; if(n<=1)v=x; else v=M2C_FIELD(p,s16 *,16)+(d>>1); M2C_FIELD(p,s16 *,16)=v;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,18);d=y-v;n=d<0?-d:d; if(n<=1)out=y; else out=v+(d>>1); M2C_FIELD(p,s16 *,18)=out;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,20);d=r-v;n=d<0?-d:d; if(n<=1)out=r; else out=v+(d>>1); M2C_FIELD(p,s16 *,20)=out;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,22);d=y-v;n=d<0?-d:d; if(n>1)y=v+(d>>1); M2C_FIELD(p,s16 *,22)=y;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,24);d=x-v;n=d<0?-d:d; if(n>1)x=v+(d>>1); M2C_FIELD(p,s16 *,24)=x;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,26);d=b-v;n=d<0?-d:d; if(n<=1)out=b; else out=v+(d>>1); M2C_FIELD(p,s16 *,26)=out;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,28);d=r-v;n=d<0?-d:d; if(n>1)r=v+(d>>1); M2C_FIELD(p,s16 *,28)=r;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,30);d=b-v;n=d<0?-d:d; if(n>1)b=v+(d>>1); M2C_FIELD(p,s16 *,30)=b;
}else{
M2C_FIELD(gSpriteSlotManager,s16 *,16)=(s16)x;
M2C_FIELD(gSpriteSlotManager,s16 *,18)=(s16)y;
M2C_FIELD(gSpriteSlotManager,s16 *,20)=(s16)r;
M2C_FIELD(gSpriteSlotManager,s16 *,22)=(s16)y;
M2C_FIELD(gSpriteSlotManager,s16 *,24)=(s16)x;
M2C_FIELD(gSpriteSlotManager,s16 *,26)=(s16)b;
M2C_FIELD(gSpriteSlotManager,s16 *,28)=(s16)r;
M2C_FIELD(gSpriteSlotManager,s16 *,30)=(s16)b;
}
p=(void*)FindSpriteSlotById(M2C_FIELD(gSpriteSlotManager,u8 *,8));
if(!SpriteSlotHasFlags(p,1))return;
SpriteSlotHasFlags(p,0x800);
q=gSpriteSlotManager;
x=M2C_FIELD(q,s16 *,16);y=M2C_FIELD(q,s16 *,18);
flags=(u16)(((0x80 >> ((u32)(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&0x3ff)|0x1000);
DrawFrameBorderPulse((s16)(x+M2C_FIELD(q,s16 *,32)),(s16)(y+M2C_FIELD(q,s16 *,34)),(s16)(M2C_FIELD(q,s16 *,28)-x),(s16)(M2C_FIELD(q,s16 *,30)-y),flags,0);
}
#pragma pop
/* Snap the manager's focus frame to the focused sprite slot: copy the slot's
 * rectangle into the frame's four corners (top-left, top-right, bottom-left,
 * bottom-right) without the easing the per-frame update applies. */
void SetSpriteSlotFrameToFocus(void) {
    extern void *gSpriteSlotManager;
    void *slot;
    s32 h, w, y, x, bottom;

    slot = M2C_FIELD(gSpriteSlotManager, void **, SPRITE_SLOT_MGR_FOCUS);
    if (!slot) return;
    x = M2C_FIELD(slot, s16 *, SPRITE_SLOT_X);
    y = M2C_FIELD(slot, s16 *, SPRITE_SLOT_Y);
    w = M2C_FIELD(slot, s16 *, SPRITE_SLOT_W);
    h = M2C_FIELD(slot, s16 *, SPRITE_SLOT_H);
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_TL_X) = (s16)x;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_TL_Y) = (s16)y;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_TR_X) = (s16)(x + w);
    bottom = y + h;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_TR_Y) = (s16)y;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_BL_X) = (s16)x;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_BL_Y) = (s16)bottom;
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_BR_X) = (s16)(x + w);
    M2C_FIELD(gSpriteSlotManager, s16 *, SPRITE_SLOT_MGR_FRAME_BR_Y) = (s16)bottom;
}

/* Return the first active sprite slot whose id is `id`, or NULL when no slot
 * has that id. */
s32 FindSpriteSlotById(id)
s32 id;
{
    extern u8 gSpriteSlots[];
    s32 i = 0;
    u8 *slot = gSpriteSlots;

    do {
        if (slot[SPRITE_SLOT_VISIBLE] && id == slot[SPRITE_SLOT_ID])
            return (s32)gSpriteSlots + i * SPRITE_SLOT_STRIDE;
        i++;
        slot += SPRITE_SLOT_STRIDE;
    } while (i < SPRITE_SLOT_COUNT);
    return 0;
}

u8 func_020b212c(void) {
    extern void *gSpriteSlotManager;
    return M2C_FIELD(gSpriteSlotManager, u8 *, 8);
}

void ClearSpriteSlotFocusFlag(void) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,u8 *,0x25)=0;
}

void func_020b2158(s8 arg0) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,s8 *,0x25)=arg0;
}

void func_020b216c(void *arg0) {
    M2C_FIELD(arg0, s8 *, 1) = 0;
}

/* Hide every touchable sprite slot: clear the visible flag of each slot. */
void HideAllSpriteSlots(void) {
    extern u8 gSpriteSlots[];
    s32 i = 0;
    u8 *slot = gSpriteSlots;
    u8 zero = i;
    do {
        i++;
        slot[SPRITE_SLOT_VISIBLE] = zero;
        slot += SPRITE_SLOT_STRIDE;
    } while (i < SPRITE_SLOT_COUNT);
}

/* Clear the active bit of every sprite slot that still has the enabled flag,
 * hiding the list's slots before the active ones are closed. */
void HideEnabledSpriteSlots(void) {
    extern u8 gSpriteSlots[];
    s32 slotIndex = 0;
    u8 *slot = gSpriteSlots;

    do {
        if (SpriteSlotHasFlags(slot, SPRITE_SLOT_FLAG_ENABLED) != 0) {
            slot[SPRITE_SLOT_VISIBLE] = 0;
        }
        slotIndex++;
        slot += SPRITE_SLOT_STRIDE;
    } while (slotIndex < SPRITE_SLOT_COUNT);
}

/* Disable touch-clicking on every sprite slot that is not enabled (won't take focus). */
void LockInactiveSpriteSlots(void) {
extern u8 gSpriteSlots[];
s32 i; u8 *slot;
slot=gSpriteSlots; i=0;
do { if(SpriteSlotHasFlags(slot,SPRITE_SLOT_FLAG_ENABLED)!=1) M2C_FIELD(slot,u16 *,SPRITE_SLOT_FLAGS)|=SPRITE_SLOT_FLAG_DISABLED; i++;slot+=SPRITE_SLOT_STRIDE; } while(i<SPRITE_SLOT_COUNT);
}

/* Clear the disabled flag on every sprite slot that is not enabled. */
void UnlockInactiveSpriteSlots(void) {
    extern u8 gSpriteSlots[];
    s32 slotIndex;
    u8 *slot;

    slot = gSpriteSlots;
    slotIndex = 0;
    do {
        if (SpriteSlotHasFlags(slot, SPRITE_SLOT_FLAG_ENABLED) != SPRITE_SLOT_FLAG_ENABLED) {
            M2C_FIELD(slot, u16 *, SPRITE_SLOT_FLAGS) &= ~SPRITE_SLOT_FLAG_DISABLED;
        }
        slotIndex++;
        slot += SPRITE_SLOT_STRIDE;
    } while (slotIndex < SPRITE_SLOT_COUNT);
}

/* Request the closing animation for every active sprite slot that has not started closing yet. */
void CloseAllActiveSpriteSlots(void) {
    extern u8 gSpriteSlots[];
    s32 slotIndex;
    u8 *slot;

    slot = gSpriteSlots;
    slotIndex = 0;
    do {
        if ((slot[SPRITE_SLOT_VISIBLE] != 0) && (slot[SPRITE_SLOT_ANIM] < SPRITE_SLOT_ANIM_CLOSING)) {
            slot[SPRITE_SLOT_ANIM] = SPRITE_SLOT_ANIM_CLOSING;
        }
        slotIndex += 1;
        slot += SPRITE_SLOT_STRIDE;
    } while (slotIndex < SPRITE_SLOT_COUNT);
}

/* Find the first free sprite slot and initialise it from `desc` at (x, y) with
 * id `id`.  Returns the new slot, or 0 when every slot is in use.  The scan
 * stops one short of SPRITE_SLOT_COUNT: the last slot is left reserved. */
s32 AddSpriteSlot(s32 x,s32 y,void *desc,s32 id) {
s32 InitSpriteSlotFromDef(s32,s32,void *,void *,s32);
extern u8 gSpriteSlots[];
u8 *slot=gSpriteSlots; s32 i=0;
do { if(slot[SPRITE_SLOT_VISIBLE]==0) return InitSpriteSlotFromDef(x,y,gSpriteSlots+i*SPRITE_SLOT_STRIDE,desc,id); i++;slot+=SPRITE_SLOT_STRIDE; } while(i<0x54);
return 0;
}

/* Initialize a 0x3C-byte sprite slot (arg2) at board position (x + arg3->dx,
   y + arg3->dy) from the spawn descriptor arg3 (size at +4/+6, rectangles and
   palette at +8..+0xE, six extra dwords at +0x10..+0x24); arg4 is the slot's id.
   The slot is marked visible (byte 1) and gSpriteSlotManager records which screen it
   was created on.  Returns the slot. */
s32 InitSpriteSlotFromDef(s32 x, s32 y, void *slot, void *desc, s32 id) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *gSpriteSlotManager;
    s16 t;
    u8 onUpperScreen;

    t = *(s16 *)((s8 *)desc + 0);
    *(s16 *)((s8 *)slot + 0x14) = (s16)(x + t);

    t = *(s16 *)((s8 *)desc + 2);
    *(s16 *)((s8 *)slot + 0x16) = (s16)(y + t);

    *(s16 *)((s8 *)slot + 0x18) = *(s16 *)((s8 *)desc + 4);
    *(s16 *)((s8 *)slot + 0x1a) = *(s16 *)((s8 *)desc + 6);
    *(u16 *)((s8 *)slot + 0x1c) = *(u16 *)((s8 *)desc + 8);
    *(u16 *)((s8 *)slot + 0x1e) = *(u16 *)((s8 *)desc + 0xa);
    *(u16 *)((s8 *)slot + 0x20) = *(u16 *)((s8 *)desc + 0xc);
    *(u16 *)((s8 *)slot + 0x22) = *(u16 *)((s8 *)desc + 0xe);
    *(s32 *)((s8 *)slot + 0x24) = *(s32 *)((s8 *)desc + 0x10);
    *(s32 *)((s8 *)slot + 0x28) = *(s32 *)((s8 *)desc + 0x14);
    *(s32 *)((s8 *)slot + 0x2c) = *(s32 *)((s8 *)desc + 0x18);
    *(s32 *)((s8 *)slot + 0x30) = *(s32 *)((s8 *)desc + 0x1c);
    *(s32 *)((s8 *)slot + 0x34) = *(s32 *)((s8 *)desc + 0x20);
    *(s32 *)((s8 *)slot + 0x38) = *(s32 *)((s8 *)desc + 0x24);

    *(u8 *)((s8 *)slot + 0) = (u8)id;
    *(u8 *)((s8 *)slot + 3) = 0;
    *(u8 *)((s8 *)slot + 4) = 0;

    t = *(s16 *)((s8 *)slot + 0x14);
    *(s16 *)((s8 *)slot + 0xa) = t;
    *(s16 *)((s8 *)slot + 0x6) = t;

    t = *(s16 *)((s8 *)slot + 0x16);
    *(s16 *)((s8 *)slot + 0xc) = t;
    *(s16 *)((s8 *)slot + 0x8) = t;

    *(s16 *)((s8 *)slot + 0xe) = 0;
    *(u8 *)((s8 *)slot + 1) = 1;

    onUpperScreen = (u8)(gCur3DSpriteEngine == g3DSpriteEngineMain);
    if (onUpperScreen) {
        M2C_FIELD(gSpriteSlotManager, u8 *, 0x24) = 0;
    } else {
        M2C_FIELD(gSpriteSlotManager, u8 *, 0x24) = 1;
    }

    return (s32)slot;
}

/* Runs one frame of the sprite-slot system: for the main and sub screens it focuses
 * the slot under the touch, animates every visible slot, handles touch on the active
 * ones (unless a slot already took focus), then calls each visible slot's per-frame
 * callback and the focused-slot key handler. */
void UpdateSpriteSlots(void) {
s32 IsSpriteDrawPaused(void); s32 IsSpriteUpdatePaused(void); s32 TryFocusSpriteSlot(u8 *);
void AnimateSpriteSlot(u8 *); s32 HandleSpriteSlotTouch(u8 *); void HandleFocusedSpriteSlotKey(void);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub,*gSpriteSlotManager;
extern u8 gSpriteSlots[];
s32 slotFocused=0; void *savedEngine; s32 pass; s32 i; u8 *slot;
if(IsSpriteDrawPaused())return;
if(IsSpriteUpdatePaused())return;
savedEngine=gCur3DSpriteEngine;
for(pass=0;pass<2;pass++){
void *engine=pass==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
u8 slotScreen;
gCur3DSpriteEngine=engine;
slotScreen=M2C_FIELD(gSpriteSlotManager,u8 *,SPRITE_SLOT_MGR_SCREEN);
if(slotScreen==0 && engine!=g3DSpriteEngineMain)continue;
if(slotScreen==1 && engine!=g3DSpriteEngineSub)continue;
if(slotScreen==3 && engine!=savedEngine)continue;
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE){
if(slot[SPRITE_SLOT_VISIBLE] && TryFocusSpriteSlot(slot)){
if(M2C_FIELD(gSpriteSlotManager,u8 *,SPRITE_SLOT_MGR_HAS_FOCUS))slotFocused=1;
break;
}
}
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE)if(slot[SPRITE_SLOT_VISIBLE])AnimateSpriteSlot(slot);
if(slotFocused==0){
s32 touchResult=0;
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE){
if(slot[SPRITE_SLOT_VISIBLE]){
if(slot[SPRITE_SLOT_ANIM]==2)touchResult=HandleSpriteSlotTouch(slot);
if(touchResult)break;
}
}
}
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE){
if(slot[SPRITE_SLOT_VISIBLE]){
void (*updateCallback)(void *)=*(void (**)(void *))(slot+SPRITE_SLOT_UPDATE_CB);
if(updateCallback)updateCallback(slot);
}
}
HandleFocusedSpriteSlotKey();
}
gCur3DSpriteEngine=savedEngine;
}

