/* 28 functions from 0x02095C90 to 0x02096C7C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "sound.h"
typedef struct { u8 kind:6; u8 owner:2; u8 rest[13]; } Unit964;
extern u8 data_02102ee4[];
extern u16 gMapConfig[];

/* Set up the telop (caption) window on the sub 3D sprite engine: mount its
 * window and telop graphics, measure the message at telop+0x36, centre it and
 * queue the text for drawing, then hand the engine back to the caller. */
void InitTelopWindow(void *telop) {
    M2C_UNK MeasureStringWidth(M2C_UNK);
    void LoadScenePanelPalette(M2C_UNK);
    void SetStandard3DSpriteLayout(void);
    M2C_UNK DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK OpenNarcArchive(M2C_UNK *);
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK *, M2C_UNK);
    M2C_UNK LoadNarcFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    void CloseNarcArchive(void);
    M2C_UNK Get3DSpriteLayerSize(M2C_UNK, M2C_UNK);
    M2C_UNK OffsetTileIndices(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK CreateMapModeWallpaperSprite(M2C_UNK, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern M2C_UNK sTelopWindowPath;
    extern M2C_UNK sTelopNarcFile;
    extern M2C_UNK sTelopCgFile;
    extern M2C_UNK sTelopScFile;
    extern M2C_UNK sTelopClFile;
    void *savedEngine;
    u16 *volatile statReg0;
    u16 *volatile statReg1;
    u16 *volatile statReg2;
    u16 *volatile statReg3;
    u16 *volatile statReg4;
    s32 centerDelta;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    SetStandard3DSpriteLayout();
    statReg0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *statReg0 = *statReg0 | 0x10;
    statReg1 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *statReg1 = *statReg1 | 0x20;
    statReg2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *statReg2 = *statReg2 | 0x40;
    statReg3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *statReg3 = *statReg3 | 0x80;
    statReg4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *statReg4 = *statReg4 | 0x100;
    M2C_FIELD(telop, u8 *, 0x35) = MeasureStringWidth(telop + 0x36);
    LoadScenePanelPalette(0);
    centerDelta = 0 - (0x100 - M2C_FIELD(telop, u8 *, 0x35));
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3A) =
        (s16)(((s32)(centerDelta + (s32)((u32)centerDelta >> 31))) >> 1);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), u16 *, 0x42) = (u16)0xFFA8;
    {
        s32 firstChar = 0;
        s32 charCount = 0x20;
        DrawTextLine(0, 0, 1, telop + 0x36, firstChar, charCount);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) =
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2;
    SetFileDirectory(&sTelopWindowPath);
    OpenNarcArchive(&sTelopNarcFile);
    LoadNarcFileDecompressed(&sTelopCgFile, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC));
    LoadNarcFileDecompressed(&sTelopScFile, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
    LoadNarcFileToSpriteBuffer(&sTelopClFile, 0x20, 0x20);
    CloseNarcArchive();
    OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20),
                  (u16)Get3DSpriteLayerSize((u8)((u32)(*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x1D) >> 0x1D), 0),
                  0x1000);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) =
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1;
    CreateMapModeWallpaperSprite(2, 0xF);
    M2C_FIELD(telop, s8 *, 0x34) = 0;
    gCur3DSpriteEngine = savedEngine;
}

/* Close the telop (caption) window on the sub 3D sprite engine: delete its
 * wallpaper sprites, apply the display config and set the five layer-mode bits
 * of the engine's sprite bank, then give the engine back to the caller. */
void CloseTelopWindow(void) {
    M2C_UNK DeleteWallpaperSprites();
    M2C_UNK Apply3DSpriteDisplayConfig();
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    u16 *volatile layer0;
    u16 *volatile layer1;
    u16 *volatile layer2;
    u16 *volatile layer3;
    u16 *volatile layer4;
    void *savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    DeleteWallpaperSprites();
    Apply3DSpriteDisplayConfig();
    layer0 = *(u16 **)gCur3DSpriteEngine;
    *layer0 = *layer0 | DS3D_BANK_MODE0;
    layer1 = *(u16 **)gCur3DSpriteEngine;
    *layer1 = *layer1 | DS3D_BANK_MODE1;
    layer2 = *(u16 **)gCur3DSpriteEngine;
    *layer2 = *layer2 | DS3D_BANK_MODE2;
    layer3 = *(u16 **)gCur3DSpriteEngine;
    *layer3 = *layer3 | DS3D_BANK_MODE3;
    layer4 = *(u16 **)gCur3DSpriteEngine;
    *layer4 = *layer4 | DS3D_BANK_MODE4;
    gCur3DSpriteEngine = savedEngine;
}

void func_02095f90(void) {

}

/* Show one line of caption text in the map screen's telop window: drop the
 * window that is up, create the window's sprite from its class and copy the
 * caption into the sprite's text buffer. */
void ShowTelopText(u8 *text) {
    void DeleteTelopWindow(void);
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void StringCopy(void *, u8 *);
    extern M2C_UNK gTelopWindowClass;
    u8 *sprite;

    DeleteTelopWindow();
    sprite = CreateSpriteFromClass(&gTelopWindowClass, 7);
    StringCopy(sprite + TELOP_TEXT, text);
}

/* Remove the map screen's telop (one-line caption) window: delete every sprite
 * made from gTelopWindowClass, the window's sprite class. */
void DeleteTelopWindow(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gTelopWindowClass;
    DeleteSpriteObjectsOfClass(&gTelopWindowClass);
}

void ClearMessageBoxState(void) {
void *Get3DSpriteManager(void);
M2C_FIELD(Get3DSpriteManager(),s8 *,0x46)=0;
}

u8 GetMessageBoxState(void) {
    void *Get3DSpriteManager();
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x46);
}

/* Move the full-screen message box to the given MESSAGE_BOX_STATE_* state. */
void SetMessageBoxState(s8 messageBoxState) {
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_MESSAGE_BOX_STATE) = messageBoxState;
}

/* True while a full-screen message box is up: once the box has been triggered
 * (STARTED) or is fully shown (SHOWING).  Callers use it to hold their own
 * updates while a message is on screen. */
u8 IsMessageBoxActive(void) {
    u8 active;

    if (GetMessageBoxState() == MESSAGE_BOX_STATE_STARTED) {
        return 1U;
    }
    if (GetMessageBoxState() == MESSAGE_BOX_STATE_SHOWING) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* Whether the full-screen message box is off: true only while it is neither
 * opening, showing, nor suppressed. */
u8 IsMessageBoxIdle(void) {
    u8 idle;

    if (GetMessageBoxState() == MESSAGE_BOX_STATE_SUPPRESSED) {
        return 0U;
    }
    if (GetMessageBoxState() == MESSAGE_BOX_STATE_OFF) {
        idle = 1;
    } else {
        idle = 0;
    }
    return idle;
}

/* Consume a Start press that begins a message box: only while the box is off
 * (not idle-animating and not already active) does Start mark it started and
 * report that the caller may skip ahead. */
s32 TryStartDialogSkip(void) {
    extern KeyState *gKeyState;
    if (IsMessageBoxIdle() == 0) {
        return 0;
    }
    if (IsMessageBoxActive() != 0) {
        return 0;
    }
    if (!(gKeyState->pressed & KEY_START)) {
        return 0;
    }
    SetMessageBoxState(1);
    return 1;
}

/* Register the dialog-sequence update as a frame-callback task (priority 5), so
 * the queued dialog scripts advance once per frame. */
void QueueDialogSequenceUpdate(void) {
    M2C_UNK CreateFrameCallbackTask(M2C_UNK *, M2C_UNK);
    extern M2C_UNK UpdateDialogSequences;
    CreateFrameCallbackTask(&UpdateDialogSequences, 5);
}

/* Convert a tile's address in a layer's tilemap (tileAddress minus the layer's
 * tilemap base, 0x40 bytes = 32 tiles per row) to the tile's screen pixel
 * position in pos: 8 pixels per tile, x from the offset inside its row and y from
 * its row. */
void LayerOffsetToPixel(s32 tileAddress, s32 layerBase, s16 *pos) {
    s32 Divide(s32, M2C_UNK);
    s32 offset;

    offset = tileAddress - layerBase;
    pos[0] = (s16) (((u32) (offset & 0x3F) >> 1) * 8);
    pos[1] = (s16) (Divide(offset, 0x40) * 8);
}

/* Lay out the message widget: turn the address of its cells in the layer's
 * tilemap into a screen position, then move the menu cursor (the vertically
 * bobbing one) to the widget's x offset there. */
void LayoutMessageWidget(ScenePanelWidget *widget) {
    M2C_UNK GetMenuCursor(void);
    void SetScenePanelCursorVertical(s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    s16 pos[2];

    LayerOffsetToPixel(widget->tileMap,
                       (s32)((DS3DSpriteEngine *)gCur3DSpriteEngine)->layerTiles[widget->layer],
                       pos);
    SetScenePanelCursorVertical(GetMenuCursor(), pos[0] + widget->x, pos[1]);
}

/* Per-frame input of a scene-panel message widget: while the text is idle the
 * Start key begins it; any of Start, A or B (or a screen touch) then plays the
 * confirm blip, hides the menu cursor and runs the widget's callback, and
 * resumes the widget's sprite animation. */
void UpdateMessageWidget(void *widget) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK GetMenuCursor();
    M2C_UNK HideMenuCursor();
    s32 GetMessageWidgetKeyAction();
    s32 GetScreenTouchConfirm();
    s32 keyAction;
    u16 actions;

    keyAction = GetMessageWidgetKeyAction();
    actions = keyAction | GetScreenTouchConfirm();
    if ((IsMessageBoxIdle() != 0) && (actions & PANEL_INPUT_SKIP)) {
        func_02095ff8(1);
    }
    if (!(actions & (PANEL_INPUT_SKIP | PANEL_INPUT_CONFIRM | PANEL_INPUT_CANCEL))) {
        return;
    }
    PlaySoundEffect(0x10012);
    GetMenuCursor();
    HideMenuCursor();
    M2C_FIELD(widget, M2C_UNK (**)(), 0x44)();
    Sprite_ResumeAnimation(widget);
}

/* Lay out the two-state widget p: turn the address of its selected-half tile in the
 * widget's layer into a screen position, store the two 32x16 half rectangles (slots 1
 * and 2) and move the menu cursor to the half p->0x34 selects. */
M2C_UNK LayoutToggleWidget(void *p) {
s32 GetMenuCursor(void);
void SetWidgetRect(s32,WidgetRect);
void SetScenePanelCursorHorizontal(s32,s32,s32);
extern void *gCur3DSpriteEngine;
s32 cursor=GetMenuCursor();
s32 selX=0,selY=0;
s16 pos[2];
WidgetRect leftHalf,rightHalf;
LayerOffsetToPixel(M2C_FIELD(p,s32 *,0x4c),M2C_FIELD(gCur3DSpriteEngine+M2C_FIELD(p,u8 *,0x40)*4,s32 *,0x20),pos);
leftHalf.y=pos[1];leftHalf.w=32;leftHalf.h=16;
pos[0]+=M2C_FIELD(p,s16 *,0x4a);
leftHalf.x=pos[0];
SetWidgetRect(1,leftHalf);
rightHalf.x=pos[0]+32;rightHalf.y=pos[1];rightHalf.w=32;rightHalf.h=16;
SetWidgetRect(2,rightHalf);
switch(M2C_FIELD(p,s16 *,0x34)) {case 0:selX=pos[0];selY=pos[1];break;case 1:selX=pos[0]+32;selY=pos[1];break;}
SetScenePanelCursorHorizontal(cursor,selX,selY);
}

/* Initialise a two-state widget: draw its label into the widget's tilemap, lay
 * out its two halves and run its callback. */
void InitToggleWidget(ToggleWidget *widget) {
    M2C_UNK LayoutToggleWidget(void *);
    M2C_UNK DrawLocalizedTextToTilemap(M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    DrawLocalizedTextToTilemap(0, 0, widget->tileMap, 0xC0000321, (s32) widget->panelEntry, 0);
    LayoutToggleWidget(widget);
    widget->callback();
}

/* Per-frame input of the two-state widget: left/right switch the selected half
 * with a click sound; A accepts the highlighted half and B cancels (selecting
 * the right half), which sets the map's confirm flag, hides the menu cursor,
 * clears the cursor's panel rows and runs the widget's callback. */
void UpdateToggleWidget(ToggleWidget *widget) {
    M2C_UNK ClearScenePanelRows(M2C_UNK);
    s32 GetPanelKeyAction(void);
    s32 GetPanelTouchAction(void);
    M2C_UNK EnableMapConfirm(void);
    M2C_UNK DisableMapConfirm(void);
    M2C_UNK LayoutToggleWidget(void *);
    M2C_UNK PlaySoundEffect(M2C_UNK);
    s32 GetMenuCursor(void);
    M2C_UNK HideMenuCursor(s32);
    M2C_UNK Sprite_ResumeAnimation(void *);

    s16 selected;
    s16 oldSelected;
    s32 actions;
    s32 touchActions;

    actions = GetPanelKeyAction();
    touchActions = GetPanelTouchAction();
    oldSelected = widget->selected;
    actions = actions | touchActions;
    if (oldSelected != 0) {
        if ((oldSelected == 1) && (actions & PANEL_INPUT_LEFT)) {
            widget->selected = 0;
            LayoutToggleWidget(widget);
            PlaySoundEffect(SOUND_MENU_MOVE);
            return;
        }
        goto block_8;
    }
    if (actions & PANEL_INPUT_RIGHT) {
        widget->selected = 1;
        LayoutToggleWidget(widget);
        PlaySoundEffect(SOUND_MENU_MOVE);
        return;
    }
    if (actions & PANEL_INPUT_CANCEL) {
        widget->selected = 1;
        LayoutToggleWidget(widget);
    }
block_8:
    if (actions & PANEL_INPUT_CONFIRM) {
        PlaySoundEffect(SOUND_MENU_CONFIRM);
    }
    if (actions & PANEL_INPUT_CANCEL) {
        PlaySoundEffect(SOUND_MENU_CANCEL);
    }
    if (!(actions & (PANEL_INPUT_CONFIRM | PANEL_INPUT_CANCEL))) {
        return;
    }
    selected = widget->selected;
    switch (selected) {
    case 0:
        EnableMapConfirm();
        break;
    case 1:
        DisableMapConfirm();
        break;
    }
    HideMenuCursor(GetMenuCursor());
    ClearScenePanelRows(3);
    widget->callback();
    Sprite_ResumeAnimation(widget);
}

/* Loads the current map: campaign/arena maps (id in
 * [MAP_ID_CAMPAIGN_FIRST, MAP_ID_CAMPAIGN_END)) come from the built-in map
 * records, any other id is read from a "/dispos" file.  When the low config flag
 * is clear, every placed unit keeps only the owner of the player's selected
 * unit, then the map view is refreshed. */
void LoadCurrentMap(void){
extern s32 *gCurrentMap;
s32 GetMapRecordBuffer(void);s32 IsLinkSessionActive(void);s32 LoadMapRecord(s32,s32);void RestoreSavedMapUnits(s32);s32 func_020a8b2c(s32);M2C_UNK SetFileDirectory(M2C_UNK *);s32 LoadFileToBuffer(s32,s32);M2C_UNK PlaceMapDeployment(s32,M2C_UNK);M2C_UNK HeapFreeBlock(s32);void GetUnitOwner(void *);void *GetPlayerSelectedUnit(void);void RefreshMapView();
s32 id=M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_ID);
s32 p,i;BattleMapUnitHead *unit; s32 off;
if(id>=MAP_ID_CAMPAIGN_FIRST&&id<MAP_ID_CAMPAIGN_END){
p=GetMapRecordBuffer();
if(!IsLinkSessionActive()){
if(!LoadMapRecord(id,p))return;
}
RestoreSavedMapUnits(p);
}else{
if(!func_020a8b2c(id))return;
SetFileDirectory((M2C_UNK *)data_02102ee4);
p=LoadFileToBuffer(func_020a8b2c(id),1);
PlaceMapDeployment(p,0);
HeapFreeBlock(p);
}
if(!((u32)(gMapConfig[0]<<23)>>31)){
i=1;off=MAP_UNIT_STRIDE;
do{
unit=(BattleMapUnitHead *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS+off);
if(unit->kind&&unit->owner){
GetUnitOwner(unit);
if(unit!=GetPlayerSelectedUnit())unit->owner=0;
}
++i;off+=MAP_UNIT_STRIDE;
}while(i<MAP_UNIT_COUNT);
}
RefreshMapView();
}

/* Load the deployment file at `path` from the "/dispos" directory, place its
 * units (displacing units already on a taken tile when `displace` is set), and
 * free the loaded file. */
void LoadDeploymentFile(s32 path, s32 displace) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    s32 LoadFileToBuffer(s32, s32);
    M2C_UNK PlaceMapDeployment(s32, s32);
    M2C_UNK HeapFreeBlock(s32);
    extern u8 sDisposDirectory[];
    s32 data;

    SetFileDirectory((M2C_UNK *)sDisposDirectory);
    data = LoadFileToBuffer(path, 1);
    PlaceMapDeployment(data, displace);
    HeapFreeBlock(data);
}

