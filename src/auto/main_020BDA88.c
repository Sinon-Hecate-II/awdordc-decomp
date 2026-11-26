/* 31 functions from 0x020BDA88 to 0x020BE718 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
extern M2C_UNK gGameSettings,data_0215d990,gOptionBits;
typedef struct { s16 a,b,c,d; } EntryBE;

static inline s32 IsNewerValue(u32 b, u32 a) {
    register u32 result asm("lr") = a & 0xffff0000;
    if (result == 0xffff0000 && !(b & 0xffff0000) && b != 0) result = 0;
    else if (!result && (b & 0xffff0000) == 0xffff0000 && a != 0) result = 1;
    else result = a > b;
    return result;
}

/* Convert the polled touch point to map tile coordinates and, when a tile is under it, record the touched tile in the map context (and in the hover-from-tile state when applicable), notifying the caller of the chosen tile index. */
void func_020bda88(s32 *outTileIndex, s32 arg) {
    void ScreenToMapPosition(u16 touchX, u16 touchY, s32 *coords);
    s32 Divide(s32 value, s32 divisor);
    s32 IsTouchInputDisabled(void);
    s32 FindMapCursorOptionAt(s32 tileX, s32 tileY, s32 mask);
    void CreateTouchCursor(s16 x, s16 y);
    void DeleteTouchCursor(void);
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 coords[3];
    s32 pixelX, pixelY, tileIndex;
    u16 touchX = M2C_FIELD(gTouchState, u16 *, 0);
    u16 touchY = M2C_FIELD(gTouchState, u16 *, 2);
    void *map;
    if (IsTouchInputDisabled() != 0) return;
    if (M2C_FIELD(gTouchState, u8 *, 0x12) == 0) return;
    ScreenToMapPosition(touchX, touchY, coords);
    pixelX = Divide(coords[0], 0x300);
    pixelY = Divide(coords[1], 0x300);
    tileIndex = FindMapCursorOptionAt(pixelX, pixelY, arg);
    if (tileIndex >= 0) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = pixelX;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = pixelY;
        *outTileIndex = tileIndex;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = pixelX;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = pixelY;
        map = *gCurrentMap;
        CreateTouchCursor(M2C_FIELD(map, s16 *, 0x52CA), M2C_FIELD(map, s16 *, 0x52CC));
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, 0x52CA) == pixelX && M2C_FIELD(map, s16 *, 0x52CC) == pixelY) return;
    DeleteTouchCursor();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = 255;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = 255;
}

/* Return confirm or cancel when the stylus is released on its starting cursor-option tile. */
s32 GetMapCursorOptionTouchAction(s32 optionMask) {
    s32 IsTouchInputDisabled(void);
    void ScreenToMapPosition(u16, u16, s32 *);
    s32 Divide(s32, s32);
    void HideTouchCursor(void);
    s32 FindMapCursorOptionAt(s32, s32, s32);
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 mapPosition[3];
    u16 touchX, touchY;
    s32 tileX, tileY, action;
    touchX = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_X);
    touchY = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_Y);
    if (IsTouchInputDisabled() != 0) return 0;
    ScreenToMapPosition(touchX, touchY, mapPosition);
    tileX = Divide(mapPosition[0], MAP_TILE_SUBPIXEL);
    tileY = Divide(mapPosition[1], MAP_TILE_SUBPIXEL);
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_RELEASED) == 0) return 0;
    if (tileX == M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_X) &&
        tileY == M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_Y)) {
        HideTouchCursor();
        if (FindMapCursorOptionAt(tileX, tileY, optionMask) >= 0) action = MAP_ACTION_CONFIRM;
        else action = MAP_ACTION_CANCEL;
    } else action = 0;
    return action;
}

/* Part of the battle-map cursor-settle check: answer MAP_ACTION_CANCEL (a nonzero
 * "settled") while the stylus is not being dragged, and 0 once a touch has been
 * held long enough to count as a drag. */
s32 GetMapSettleTouchAction(void) {
    s32 IsTouchInputDisabled();
    extern void *gTouchState;

    if (IsTouchInputDisabled() != 0) {
        return 0;
    }
    if ((M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE) == 0) ||
        ((u32) M2C_FIELD(gTouchState, u8 *, TOUCH_HOLD_FRAMES) < TOUCH_DRAG_FRAMES)) {
        return MAP_ACTION_CANCEL;
    }
    return 0;
}

/* Touch handler for the aiming cursor. Once a touch is held to a drag, delete the
 * touch cursor and clear the touched tile; when the stylus is released on the tile
 * the drag started on, hide the touch cursor and report a confirm action. */
s32 GetAimCursorTouchAction(void) {
    s32 IsTouchInputDisabled(void);
    void DeleteTouchCursor(void);
    void HideTouchCursor(void);
    extern void *gTouchState;
    extern void **gCurrentMap;

    if (IsTouchInputDisabled()) return 0;
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE) && M2C_FIELD(gTouchState, u8 *, TOUCH_HOLD_FRAMES) == TOUCH_DRAG_FRAMES) {
        DeleteTouchCursor();
        M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_X) = MAP_TOUCH_NO_TILE;
        M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_Y) = MAP_TOUCH_NO_TILE;
    }
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_RELEASED) &&
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X) == M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_X) &&
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y) == M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_Y)) {
        HideTouchCursor();
        return MAP_ACTION_CONFIRM;
    }
    return 0;
}

/* Update the selection cursor from the current stylus position and return any resulting action code. */
s32 GetMapCursorTouchAction(void) {
    s32 IsTouchInputDisabled(void);
    s32 IsTouchOnCenterMapButton(s32, s32);
    void DeleteTouchCursor(void);
    void HideTouchCursor(void);
    extern void *gTouchState;
    extern void **gCurrentMap;

    u16 touchX, touchY;
    touchX = M2C_FIELD(gTouchState, u16 *, 0);
    touchY = M2C_FIELD(gTouchState, u16 *, 2);
    if (IsTouchInputDisabled()) return 0;
    if (M2C_FIELD(gTouchState, u8 *, 0x14)) {
        if (IsTouchOnCenterMapButton(touchX, touchY)) return 32;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x12) && M2C_FIELD(gTouchState, u8 *, 0x10) == 20) {
        DeleteTouchCursor();
        M2C_FIELD(*gCurrentMap, s16 *, 0x52ca) = 255;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52cc) = 255;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x16) &&
        M2C_FIELD(*gCurrentMap, s16 *, 0x52c2) == M2C_FIELD(*gCurrentMap, s16 *, 0x52ca) &&
        M2C_FIELD(*gCurrentMap, s16 *, 0x52c4) == M2C_FIELD(*gCurrentMap, s16 *, 0x52cc)) {
        HideTouchCursor();
        return 16;
    }
    return 0;
}

/* Whether (x, y) is on the top middle touch button: confirm in cursor mode,
 * "next target" while picking a target. */
s32 IsTouchOnMiddleButton(s32 x, s32 y) {
    if ((x >= MAP_BUTTON_MIDDLE_X0) && (x <= MAP_BUTTON_MIDDLE_X1) &&
        (y >= MAP_BUTTON_ROW_Y0) && (y <= MAP_BUTTON_ROW_Y1)) {
        return 1;
    }
    return 0;
}

/* Whether a stylus position lies on the battle map's top-centre 32x16 touch
 * button (the A/confirm button, which also steps to the next target). */
s32 IsTouchOnCenterMapButton(s32 x, s32 y) {
    if ((x >= MAP_TOP_BUTTON_CENTER) && (x <= MAP_TOP_BUTTON_CENTER + MAP_TOP_BUTTON_SPAN) &&
        (y >= MAP_TOP_BUTTON_Y_MIN) && (y <= MAP_TOP_BUTTON_Y_MAX)) {
        return 1;
    }
    return 0;
}

/* Whether a stylus position lies on the top-centre "next target" button that
 * cycles the selected target in the map's target-selection screens. */
s32 IsTouchOnNextButton(s32 x, s32 y) {
    if ((x >= MAP_TOP_BUTTON_CENTER) && (x <= MAP_TOP_BUTTON_CENTER + MAP_TOP_BUTTON_SPAN) &&
        (y >= MAP_TOP_BUTTON_Y_MIN) && (y <= MAP_TOP_BUTTON_Y_MAX)) {
        return 1;
    }
    return 0;
}

/* Whether (x, y) is on the top left touch button (cancel/back). */
s32 IsTouchOnLeftButton(s32 x, s32 y) {
    if ((x >= MAP_BUTTON_LEFT_X0) && (x <= MAP_BUTTON_LEFT_X1) &&
        (y >= MAP_BUTTON_ROW_Y0) && (y <= MAP_BUTTON_ROW_Y1)) {
        return 1;
    }
    return 0;
}

/* Whether a stylus position lies on the battle map's top-right 32x16 touch
 * button, which opens the map menu (the R key's action). */
s32 IsTouchOnMapMenuButton(s32 x, s32 y) {
    if ((x >= MAP_TOP_BUTTON_RIGHT) && (x <= MAP_TOP_BUTTON_RIGHT + MAP_TOP_BUTTON_SPAN) &&
        (y >= MAP_TOP_BUTTON_Y_MIN) && (y <= MAP_TOP_BUTTON_Y_MAX)) {
        return 1;
    }
    return 0;
}

/* Draw a 32x16 UI sprite at screen position (112, 0), with OAM flags 0x9000 and
 * base tile 0x1F0 (one of the small pieces the unit-info panel's cancel path
 * draws). */
void func_020bdfa8(void) {
    M2C_UNK DrawSizedOamSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    DrawSizedOamSprite(0x70, 0, 0x20, 0x10, 0x9000, 0x1F0);
}

/* Draw the unit-info panel's 32x16 "next target" button sprite at (112, 0) using
 * base tile 0x1F8 (the tile sits inside the button's touch region, x 0x70..0x90). */
void DrawNextButtonSprite(void) {
    DrawSizedOamSprite(0x70, 0, 0x20, 0x10, 0x9000, 0x1F8);
}

/* Draw a 32x16 UI sprite at screen position (112, 0), with OAM flags 0x9000 and
 * base tile 0x1E8 (one of the small pieces the unit-info panel's cancel path
 * draws). */
void func_020be010(void) {
    DrawSizedOamSprite(0x70, 0, 0x20, 0x10, 0x9000, 0x1E8);
}

/* Draw a 32x16 UI sprite at screen position (64, 0), with OAM flags 0x9000 and
 * base tile 0x200 (one of the small pieces the unit-info panel's cancel path
 * draws). */
void func_020be044(void) {
    DrawSizedOamSprite(0x40, 0, 0x20, 0x10, 0x9000, 0x200);
}

/* Draw the map-menu touch button: a 32x16 sprite at screen position (160, 0) with
 * OAM flags 0x9000 and base tile 0x208. Touching its region opens the map menu. */
void DrawMapMenuButtonSprite(void) {
    DrawSizedOamSprite(0xA0, 0, 0x20, 0x10, 0x9000, 0x208);
}

/* Draw a sprite using the size template and the active engine's OBJ tile boundary. */
M2C_UNK DrawSizedOamSprite(s32 screenX, s32 screenY, s32 width, s32 height, s32 objFlags, s32 baseTile) {
    void *GetSpriteDescForSize(s32, s32);
    M2C_UNK AppendSpriteDescToOam(u16, u8, u16, SpriteQuadTemplate *);
    extern void *gCur3DSpriteEngine;
    SpriteQuadTemplate *spriteTemplate;
    u32 objX;
    u32 tileShift;
    u32 attributes;

    spriteTemplate = GetSpriteDescForSize(width, height);
    objX = screenX & DS3D_OBJ_X_MASK;
    screenY = (u8)screenY;
    tileShift = (u32)(DS3D_BANK(gCur3DSpriteEngine)->flags << (32 - DS3D_BANK_OBJ_BOUNDARY_SHIFT - DS3D_BANK_OBJ_BOUNDARY_BITS)) >>
                (32 - DS3D_BANK_OBJ_BOUNDARY_BITS);
    attributes = objFlags | ((baseTile >> tileShift) & DS3D_OBJ_TILE_MASK);
    return AppendSpriteDescToOam((u16)objX, (u8)screenY, (u16)attributes, spriteTemplate);
}

M2C_UNK *GetSaveRecordBuffer(void) {
    extern M2C_UNK gGameSettingsSaveBuffer;
    return &gGameSettingsSaveBuffer;
}

void func_020be12c(void) {

}

/* Free the save block a save-progress indicator sprite owns
 * (SAVE_INDICATOR_BLOCK), halting first with the load-failure message when the
 * save archive has become unusable. */
void FreeSaveIndicatorBlock(void *sprite) {
    s32 IsSaveArchiveUnusable();
    M2C_UNK HaltWithMessage();
    M2C_UNK GetLocalizedText(s32);
    M2C_UNK HeapFreeBlock(s32);
    s32 block;

    block = M2C_FIELD(sprite, s32 *, SAVE_INDICATOR_BLOCK);
    if (IsSaveArchiveUnusable() != 0) {
        GetLocalizedText(0xC000034C);
        HaltWithMessage();
    }
    if (block == 0) {
        return;
    }
    HeapFreeBlock(block);
}

/* Save-progress indicator completion: delete the indicator sprite once the
 * background save task has finished. */
void FinishSaveIndicator(void *sprite) {
    s32 IsSaveTaskRunning();
    void DeleteSpriteObject(void *);
    if (IsSaveTaskRunning() != 0) {
        return;
    }
    DeleteSpriteObject(sprite);
}

/* Create the save-progress indicator sprite on the default layer, handing it the
 * save block it will free once the background save task finishes. */
void CreateSaveIndicator(void *block) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gSaveIndicatorClass;
    M2C_FIELD(CreateSpriteFromClass(&gSaveIndicatorClass, 6), void **, SAVE_INDICATOR_BLOCK) = block;
}

/* Whether a save is in progress: the save indicator sprite exists, or the save
 * task is still running. */
u8 IsSaveInProgress(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gSaveIndicatorClass;
    u8 result;

    if (FindObjectByClass(&gSaveIndicatorClass)) return 1;
    if (IsSaveTaskRunning()) result = 1; else result = 0;
    return result;
}

void func_020be1dc(s32 arg0) {
void *func_02076228(void);s32 func_02076234(void);
M2C_UNK func_02076010(s32,s32);M2C_UNK func_02076180(u16);
u8 *p,*best;s32 n,i,id;register s32 better;register u32 high;u32 b,a;
switch(arg0){case 2:case 3:case 4:func_02076010(arg0,1);return;}
p=func_02076228();best=0;n=func_02076234();i=0;
if(n>0)do{if(arg0==p[2]){if(best){better=IsNewerValue(M2C_FIELD(best,u32 *,4),M2C_FIELD(p,u32 *,4));
if(!better)goto next;
}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id==-1)return;
func_02076180((u16)id);
}

void QueueSaveRecord(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK SaveList_QueueUpdate(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    SaveList_QueueUpdate(arg0, 0, arg1, arg2);
}

/* Snapshot the live game settings into `buffer`, drop the old shared settings
 * record, and queue the snapshot as save record type 4. */
void QueueSettingsRecord(void *buffer) {
    M2C_UNK SnapshotGameSettings(void *);

    SnapshotGameSettings(buffer);
    func_020be1dc(SAVE_TYPE_SETTINGS);
    QueueSaveRecord(buffer, SAVE_SETTINGS_RECORD_SIZE, SAVE_TYPE_SETTINGS);
}

/* Load the newest save-directory record of type `type`: walk the save directory,
 * keep the record of that type with the largest timestamp, load it, and show the
 * load-failure message when the load reports a problem. */
u8 LoadNewestSaveRecord(s32 type,M2C_UNK arg1){
void *GetSaveRecordList(void);s32 GetSaveRecordCount(void);s32 LoadSaveRecord(u16,M2C_UNK);s32 IsSaveArchiveUnusable(void);M2C_UNK GetLocalizedText(s32);M2C_UNK HaltWithMessage();
u8 *record,*best;s32 n,i,id; s32 isNewer;u8 result;
record=GetSaveRecordList();best=0;n=GetSaveRecordCount();i=0;
if(n>0)do{if(type==record[SAVE_RECORD_TYPE]){if(best){isNewer=IsNewerValue(M2C_FIELD(best,u32 *,SAVE_RECORD_TIME),M2C_FIELD(record,u32 *,SAVE_RECORD_TIME));
if(!isNewer)goto next;
}best=record;}next:i++;record+=SAVE_RECORD_STRIDE;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id==-1)return 0;
result=LoadSaveRecord(id,arg1);
if(IsSaveArchiveUnusable()){GetLocalizedText(0xc000034d);HaltWithMessage();}
return result;
}

/* Queue a save: write the `size`-byte record in `buffer` as record type
 * `saveType`, and unless that is the shared settings type (4) also snapshot the
 * global settings into a fresh block and queue that as the shared record.  Then
 * start the save task and hand the block to the save indicator sprite. */
void WriteSaveRecord(s32 saveType, void *buffer, s32 size) {
    s32 HeapAllocBlock(s32);
    s32 block = 0;
    func_020be1dc(saveType);
    QueueSaveRecord(buffer, size, (u8)saveType);
    if (saveType != 4) {
        block = HeapAllocBlock(0x6000);
        QueueSettingsRecord(block);
    }
    SaveList_StartFlush();
    CreateSaveIndicator(block);
}

/* Delete the previously saved record of `saveType` (the old copy of a record
 * about to be replaced or cleared) and then write the current game-settings
 * snapshot as the shared settings record, unless `saveType` is that settings
 * record itself: start the save and hand the settings block to the save
 * progress indicator. */
void DeleteSaveRecordAndSaveSettings(s32 saveType) {
    s32 HeapAllocBlock(s32);
    s32 block = 0;

    func_020be1dc(saveType);
    if (saveType != SAVE_TYPE_SETTINGS) {
        block = HeapAllocBlock(0x6000);
        QueueSettingsRecord(block);
    }
    SaveList_StartFlush();
    CreateSaveIndicator(block);
}

s32 SaveRecordExistsForType(s32 arg0) { void *GetSaveRecordList(void); s32 GetSaveRecordCount(void); u8 *p,*best; s32 n,i,better,id;u32 b,a,high;
p=GetSaveRecordList();best=0;n=GetSaveRecordCount();i=0;
if(n>0)do{if(arg0==p[2]){if(best){a=M2C_FIELD(p,u32 *,4);b=M2C_FIELD(best,u32 *,4);high=a&0xffff0000;
if(high==0xffff0000 && !(b&0xffff0000) && b!=0)better=0;
else if(high==0 && (b&0xffff0000)==0xffff0000 && a!=0)better=1;
else better=a>b;
if(!better)goto next;
}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;return id!=-1; }

/* Erase the save directory: prune every record of each save type from the shared
 * settings type (SAVE_TYPE_SETTINGS) up to 0x3A down to none, then start the save
 * flush and show the save indicator. */
void EraseAllSaveData(void) {
    M2C_UNK PruneSaveRecords(s32, M2C_UNK);
    M2C_UNK SaveList_StartFlush();
    s32 saveType;

    saveType = SAVE_TYPE_SETTINGS;
    do {
        PruneSaveRecords(saveType, 0);
        saveType += 1;
    } while (saveType < 0x3B);
    SaveList_StartFlush();
    CreateSaveIndicator(0);
}

/* Restore the game settings to their defaults: mark the settings block valid,
 * clear and re-stamp the option/zoom word, reset the army/unit option tables
 * and the save records, set the default slot words and clear the per-slot
 * setting words. Runs at startup and whenever the settings magic is missing. */
void InitDefaultGameSettings(void) {
M2C_UNK func_02086b9c();M2C_UNK ClearRecordValues();M2C_UNK UnlockCosForMap(M2C_UNK);M2C_UNK SetCoUnlocked(s32,s32);M2C_UNK SetCoSavedMode(s32,s32);M2C_UNK SetMusicVolumeSetting(M2C_UNK);M2C_UNK SetSoundEffectVolumeSetting(M2C_UNK);M2C_UNK MapSettings_SetDefaults(M2C_UNK);M2C_UNK ClearAllCampaignSaveHeaders();M2C_UNK ResetCampaignProgress();
s32 i,slot,entry; s32 flagOff,modeOff;
M2C_FIELD(&gGameSettings,s32 *,0x128)=GAME_SETTINGS_MAGIC;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~15;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x70;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0xc00;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x3000;
M2C_FIELD(&data_0215d990,u16 *,0x2e)|=0x4000;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x8000;
MapSettings_SetDefaults(0);
i=0;flagOff=0;modeOff=0;
do{SetCoUnlocked(i,flagOff);SetCoSavedMode(i,modeOff);++i;}while(i<15);
UnlockCosForMap(0);ClearAllCampaignSaveHeaders();ResetCampaignProgress();func_02086b9c();ClearRecordValues();
M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380)|0x80;
SetMusicVolumeSetting(95);SetSoundEffectVolumeSetting(95);
slot=0;
M2C_FIELD(&gGameSettings,s32 *,0x140)=0;
M2C_FIELD(&gGameSettings,s32 *,0x144)=1;
M2C_FIELD(&gGameSettings,s32 *,0x148)=1;
M2C_FIELD(&gGameSettings,s32 *,0x14c)=6;
M2C_FIELD(&gGameSettings,s32 *,0x150)=0;
M2C_FIELD(&gGameSettings,s32 *,0x154)=0;
M2C_FIELD(&gGameSettings,s32 *,0x158)=0;
do{M2C_FIELD((u8 *)&gOptionBits+(u32)slot*8,s16 *,0x36)=0;++slot;}while(slot<4);
entry=0;
do{M2C_FIELD((u8 *)&gOptionBits+(u32)entry*2,s16 *,8)=0;++entry;}while(entry<4);
}

