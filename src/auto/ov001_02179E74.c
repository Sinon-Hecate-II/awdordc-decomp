/* 17 functions from 0x02179E74 to 0x0217AE38 (ov001), found by ds-decomp. */
#include "common.h"
void MapSelectList_HandleIconRowChoice(void);

/* Hold the save screen for 120 frames: advance its timer once per frame, then
 * hand over to the step that fades the screen out. */
void Ov001_TickSaveDelay(void) {
    extern s8 gOv001SaveScreenTimer;
    void Ov001_FadeOutSaveScreen(void);
    M2C_FIELD(&gOv001SaveScreenTimer,u8 *,0) = M2C_FIELD(&gOv001SaveScreenTimer,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&gOv001SaveScreenTimer,u8 *,0) < 120U) return;
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeOutSaveScreen);
}

/* Enter the map-select list screen: allocate and initialise its list object,
 * load its backgrounds and row label sprites, create its text panel and scroll
 * task, then hand over to the fade-in step. */
void MapSelectList_Init(void) {
    extern M2C_UNK gMapSelectState;
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_GetNameEntryMode(M2C_UNK *, M2C_UNK);
    M2C_UNK Ov001_GetFriendSlots(M2C_UNK);
    void InitMapSelectGraphics(void);
    void Ov001_LoadSaveSlotObjLayout(void);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_OpenMenuForMode(M2C_UNK);
    void MapSelectList_InitScrollBar(void);
    void MapSelectList_InitRows(void);
    M2C_UNK CreateTextPanel(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_AddTask(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void MapSelectList_Redraw(void);
    void MapSelectList_ApplyRowLayout(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void MapSelectListUpdateBackgroundScroll(void);
    void MapSelectList_FadeIn(void);
    s32 nameEntryMode;

    M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ) = Ov001_Alloc((M2C_UNK)0x5c, (M2C_UNK)4);
    Ov001_GetNameEntryMode(&nameEntryMode, 0);
    if (nameEntryMode == 0) {
        M2C_FIELD(&gMapSelectState, u8 *, MAPSELECT_STATE_CURSOR) = 0;
        M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) = 0;
    }
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_COUNT) =
        (u8)Ov001_GetFriendSlots(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ));
    InitMapSelectGraphics();
    Ov001_LoadSaveSlotObjLayout();
    Ov001_ShowMessagePanel((M2C_UNK)0x34, (M2C_UNK)(0x34 - 0x35), (M2C_UNK)0);
    Ov001_OpenMenuForMode((M2C_UNK)2);
    MapSelectList_InitScrollBar();
    MapSelectList_InitRows();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_TEXT_PANEL) = (s32)CreateTextPanel((M2C_UNK)0, (M2C_UNK)0);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_TASK) =
        (s32)Ov001_AddTask((M2C_UNK)1, (M2C_UNK)MapSelectListUpdateBackgroundScroll, (M2C_UNK)0, (M2C_UNK)0x6e);
    MapSelectList_Redraw();
    MapSelectList_ApplyRowLayout();
    Ov001_SetStepCallback((M2C_UNK *)&MapSelectList_FadeIn);
}

/* Set up the map-select screen's graphics: load the list-background tilemap and
 * the step-31 background tiles into VRAM, upload the tilemap, then point the
 * layered background control registers at the new layers. */
void InitMapSelectGraphics(void) {
    s32 Ov001_GetLocalizedFileName(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    s32 Ov001_LoadFile(s32, M2C_UNK, M2C_UNK);
    M2C_UNK InitMapPreview(M2C_UNK);
    M2C_UNK RequestMapPreviewUpdate(void);
    extern M2C_UNK sXb4ApListBackNscPath;
    extern M2C_UNK sYbBgStep31NclPath;
    extern M2C_UNK sJb4ApListNscPath;
    extern M2C_UNK GX_LoadBG3Scr;
    extern M2C_UNK gMapSelectState;
    typedef struct { u8 bytes[25]; } ListBackPath;
    typedef struct { u8 bytes[22]; } BgStep31Path;
    ListBackPath listBackPath = *(ListBackPath *)&sXb4ApListBackNscPath;
    BgStep31Path bgStep31Path = *(BgStep31Path *)&sYbBgStep31NclPath;
    Ov001_LoadAsset(&sJb4ApListNscPath, &GX_LoadBG3Scr);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 4) =
        Ov001_LoadFile(Ov001_GetLocalizedFileName(&listBackPath), 0, 4);
    InitMapPreview(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 4));
    RequestMapPreviewUpdate();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 8) =
        Ov001_LoadFile(Ov001_GetLocalizedFileName(&bgStep31Path), 0, 4);
    /* sub BG0/BG1 and main BG0/BG1: 256-colour tiled layers */
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x04000008, u16 *, 0) = (M2C_FIELD((void *)0x04000008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 4) = (M2C_FIELD((void *)0x0400000A, u16 *, 4) & ~3) | 2;
}

/* Creates the map-select list's scroll bar: sets how far the list can scroll from
 * the number of maps, picks the bar's handle size, and places the handle at the
 * position that matches the list's current scroll. */
void MapSelectList_InitScrollBar(void) {
    s32 HardwareDivide(s32, u16); /* hardware divide unit: quotient */
    M2C_UNK Ov001_CreateScrollBar(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK gMapSelectState;
    s32 handlePos;
    s32 kind;
    u8 count;

    handlePos = 0;
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u16 *, MAPSELECT_MAX_SCROLL) =
        (u16)((M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_COUNT) - MAPSELECT_NO_SCROLL_MAX) * MAPSELECT_ROW_UNITS);
    count = M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_COUNT);
    if ((u32)count <= (u32)MAPSELECT_NO_SCROLL_MAX) {
        kind = handlePos;
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_LAST_ROW) = handlePos;
    } else if ((u32)count <= (u32)MAPSELECT_SHORT_HANDLE_MAX) {
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_LAST_ROW) = MAPSELECT_HANDLE_TRAVEL_SHORT;
        kind = MAPSELECT_HANDLE_SHORT;
    } else {
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_LAST_ROW) = MAPSELECT_HANDLE_TRAVEL_LONG;
        kind = MAPSELECT_HANDLE_LONG;
    }
    if (kind != 0) {
        handlePos = HardwareDivide(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) * M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_LAST_ROW), M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u16 *, MAPSELECT_MAX_SCROLL));
    }
    Ov001_CreateScrollBar(kind, MAPSELECT_SCROLLBAR_TRACK, MAPSELECT_SCROLLBAR_X, MAPSELECT_SCROLLBAR_Y, handlePos);
}

#pragma opt_common_subs off
/* Create the map-select list's row sprites: up to MAPSELECT_ROWS row-label and
 * map-name objects, into whose first one the label and name tile sets are loaded;
 * the resulting tile words fill the list's label and name tile tables, and every
 * created row gets its priority bits set. */
void MapSelectList_InitRows(void) {
void *Ov001_CreateSpriteFromLayout(M2C_UNK, M2C_UNK);
void Ov001_LoadSpriteObjLayout(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK gMapSelectState;
extern u8 data_ov001_0218f814[];
extern u8 data_ov001_0218f818[];
s32 rowCount = *(u8 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ)) + MAPSELECT_COUNT);
s32 i = 0;
if (rowCount > MAPSELECT_ROWS) rowCount = MAPSELECT_ROWS;
for (i = 0; i < rowCount; i++) {
        ((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_A_INDEX + i] = Ov001_CreateSpriteFromLayout(0, MAPSELECT_ROW_LABEL_SPRITE);
        ((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_B_INDEX + i] = Ov001_CreateSpriteFromLayout(0, MAPSELECT_ROW_NAME_SPRITE);
}
for (i = 0; (u32)i < MAPSELECT_LABEL_TILES_COUNT; i++) {
Ov001_LoadSpriteObjLayout(0, (M2C_UNK)data_ov001_0218f814[i], ((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_A_INDEX]);
((u16 *)((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ)))[MAPSELECT_LABEL_TILES_INDEX + i] = *(u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_A_INDEX] + MAPSELECT_ROW_TILE) & 0x3ff;
}
for (i = 0; (u32)i < MAPSELECT_NAME_TILES_COUNT; i++) {
Ov001_LoadSpriteObjLayout(0, (M2C_UNK)data_ov001_0218f818[i], ((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_B_INDEX]);
((u16 *)((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ)))[MAPSELECT_NAME_TILES_INDEX + i] = *(u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_B_INDEX] + MAPSELECT_ROW_TILE) & 0x3ff;
}
for (i = 0; i < rowCount; i++) {
u16 *tile = (u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_A_INDEX + i] + MAPSELECT_ROW_TILE);
*tile = (*tile & ~0xc00) | 0xc00;
tile = (u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[MAPSELECT_ROW_OBJS_B_INDEX + i] + MAPSELECT_ROW_TILE);
*tile = (*tile & ~0xc00) | 0xc00;
}
}
#pragma opt_common_subs reset
/* Fade the map-select list screen in from white and show its planes: the sub
 * screen blends BG0, the main screen BG0/BG2/BG3 and the sprites. */
void MapSelectList_FadeIn(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void MapSelectList_FadeInDone(void);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_BG3 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, OV001_BLEND_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_BG3 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback((M2C_UNK *)&MapSelectList_FadeInDone);
}

/* Step that runs once the map-select list's fade-in has finished: wait for the
 * sub and main engine fades, then put up the shared back/confirm icon row and
 * hand over to the step that waits for it to slide in. */
void MapSelectList_FadeInDone(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK MapSelectList_WaitIconRow;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_CreateMenuIconRow(0);
    Ov001_SetStepCallback(&MapSelectList_WaitIconRow);
}

/* Step that waits for the map-select list's icon row to finish sliding in,
 * then unlocks it and hands over to the list's input-update step. */
void MapSelectList_WaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK MapSelectList_Update;
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&MapSelectList_Update);
}

/* Per-frame update step of the map-select list: poll and apply this frame's
 * input, then act on any icon-row choice latched during it. */
void MapSelectList_Update(void) {
    void MapSelectList_PollInput(void);
    void MapSelectList_HandleInput(void);

    MapSelectList_PollInput();
    MapSelectList_HandleInput();
    MapSelectList_HandleIconRowChoice();
}

/* Polls the map-select list's touch rows and keys: a tapped/held row becomes the
 * selected map, A confirms, B cancels, and L/R or the D-pad scroll or switch the
 * list panel. */
void MapSelectList_PollInput(void) {
extern M2C_UNK gMapSelectState; extern u8 gTouchScreenRect[],gMapSelectRowRects[];
s32 TouchRectPressed(void *);s32 TouchRectHeld(void *);s32 KeyPressed(s32);s32 KeyHeld(s32);s32 KeyReleased(s32);
void Ov001_LatchIconRowSelection(s32);void MapSelectList_ApplyRowLayout(void);M2C_UNK Ov001_PlaySound(s32);void Ov001_BlockScrollBar(void);void MapSelectList_PageDown(void);void MapSelectList_PageUp(void);void MapSelectList_MoveCursor(s32);
u8 *heldRect; s32 row; s32 index; u8 *pressedRect;
if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)||M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x57))return;
if(TouchRectPressed(gTouchScreenRect)){
M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s8 *,0x50)=-1;
for(index=0,pressedRect=gMapSelectRowRects;(u32)index<5;index++,pressedRect+=8){
if(TouchRectPressed(pressedRect)){
if(index<4){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s8 *,0x50)=index;break;}
Ov001_LatchIconRowSelection(1);M2C_FIELD(&gMapSelectState,u8 *,0)=index;MapSelectList_ApplyRowLayout();return;
}}}
if(TouchRectHeld(gTouchScreenRect)){
for(heldRect=gMapSelectRowRects,row=0;row<4;row++,heldRect+=8){
if(TouchRectHeld(heldRect)){
if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s8 *,0x50)!=row)break;
if(row>=M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x51)){Ov001_PlaySound(9);break;}
Ov001_LatchIconRowSelection(1);M2C_FIELD(&gMapSelectState,u8 *,0)=row;MapSelectList_ApplyRowLayout();return;
}}}
if(KeyPressed(KEY_A)){Ov001_LatchIconRowSelection(1);Ov001_BlockScrollBar();return;}
if(KeyPressed(KEY_B)){Ov001_LatchIconRowSelection(0);return;}
if(KeyHeld(KEY_L)){MapSelectList_PageDown();return;}
if(KeyReleased(KEY_L)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0;return; }
if(KeyHeld(KEY_R)){MapSelectList_PageUp();return;}
if(KeyReleased(KEY_R)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0;return; }
if(KeyHeld(KEY_UP)){MapSelectList_MoveCursor(1);return;}
if(KeyReleased(KEY_UP)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0;return; }
if(KeyHeld(KEY_DOWN)){MapSelectList_MoveCursor(3);return;}
if(KeyReleased(KEY_DOWN)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0; }
}

/* Per-frame input handler for the map-select list: handles page jumps and
 * row-by-row scrolling, plays the cursor-move or bump sound, and schedules
 * the scroll-snap callback that finishes the scroll animation. */
void MapSelectList_HandleInput(void) {
 extern M2C_UNK gMapSelectState;
 extern M2C_UNK MapSelectList_ScrollUp,MapSelectList_ScrollDown;
 s32 GetMenuState(void);
 s32 Ov001_GetScrollBarHandlePos(void);
 s32 HardwareDivide(s32,u16);
 s32 HardwareDivideRemainder(s32,s32);
 M2C_UNK Ov001_LockIconRow();
 void Ov001_FreeSpriteObjects(void);
 M2C_UNK Ov001_UnlockIconRow();
 M2C_UNK Ov001_PlaySound(s32);
 void MapSelectList_Redraw(void);
 void MapSelectList_ApplyRowLayout(void);
 s32 Ov001_AddTask(s32,s32,s32,s32);
 s32 remainder;
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)) return;
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55))
 --M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55);
 switch(GetMenuState()) {
 case 1:
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x57)=1;
 Ov001_LockIconRow();return;
 case 2:
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55)) return;
 Ov001_FreeSpriteObjects();
 M2C_FIELD(&gMapSelectState,u16 *,2)=HardwareDivide(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u16 *,0x40)*Ov001_GetScrollBarHandlePos(),M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x53));
 MapSelectList_Redraw();
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55)=4;return;
 case 3:
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x57)=0;
 Ov001_UnlockIconRow();
 M2C_FIELD(&gMapSelectState,u16 *,2)=HardwareDivide(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u16 *,0x40)*Ov001_GetScrollBarHandlePos(),M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x53));
 Ov001_PlaySound(0x13);
 MapSelectList_Redraw();
 remainder=HardwareDivideRemainder(M2C_FIELD(&gMapSelectState,u16 *,2),0x1c);
 if(remainder==0) {MapSelectList_ApplyRowLayout();return;}
 if(remainder<14) {
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=Ov001_AddTask(0,(s32)&MapSelectList_ScrollUp,0,120);
 return;
 }

 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=Ov001_AddTask(0,(s32)&MapSelectList_ScrollDown,0,120);
 return;
 case 4:
 if(M2C_FIELD(&gMapSelectState,u16 *,2)==0) {
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58))return;
 Ov001_PlaySound(9);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58)=1;return;
 }
 Ov001_PlaySound(0x13);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=Ov001_AddTask(0,(s32)&MapSelectList_ScrollUp,0,120);return;
 case 6:
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x51)<=4 || M2C_FIELD(&gMapSelectState,u16 *,2)==M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u16 *,0x40)) {
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58))return;
 Ov001_PlaySound(9);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58)=1;return;
 }
 Ov001_PlaySound(0x13);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=Ov001_AddTask(0,(s32)&MapSelectList_ScrollDown,0,120);return;
 case 5:case 7:
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58)=0;return;
 default:return;
 }
}

#pragma optimize_for_speed off
void MapSelectList_HandleIconRowChoice(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void MapSelectList_LoadObjTile(void);
    s32 HardwareDivide(s32, u16);
    void Ov001_BlockScrollBar(void);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_ConfirmMapSelectNotice(void);
    void MapSelectList_BeginExit(void);
    extern M2C_UNK gMapSelectState;
    void *map;
    s32 r;
    map = M2C_FIELD(&gMapSelectState, void **, 4);
    if (M2C_FIELD(map, M2C_UNK *, 0x38) != 0) return;
    if (M2C_FIELD(map, u8 *, 0x57) != 0) return;
    r = Ov001_GetIconRowSelection();
    switch (r) {
    case 0:
        Ov001_PlaySound(7);
        goto done;
    case 1:
        if (M2C_FIELD(&gMapSelectState, u8 *, 0) == 4) {
            map = M2C_FIELD(&gMapSelectState, void **, 4);
            M2C_FIELD(map, u8 *, 0x54) = 1;
            Ov001_PlaySound(6);
            MapSelectList_LoadObjTile();
            goto done;
        } else {
            u8 field28;
            s32 idx = (u8)M2C_FIELD(&gMapSelectState, u8 *, 0) + HardwareDivide(M2C_FIELD(&gMapSelectState, u16 *, 2), 0x1c);
            field28 = M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), void **, 0) + idx * 42, u8 *, 0x28);
            if (field28 == 2) {
                Ov001_PlaySound(9);
                Ov001_BlockScrollBar();
                Ov001_LockIconRow();
                Ov001_ShowMessage(0xe, 1, 1, -1, 0);
                Ov001_SetStepCallback((M2C_UNK *)&Ov001_ConfirmMapSelectNotice);
                goto done;
            } else {
                void *map2 = M2C_FIELD(&gMapSelectState, void **, 4);
                M2C_FIELD(map2, u8 *, 0x54) = 1;
                map = M2C_FIELD(&gMapSelectState, void **, 4);
                M2C_FIELD(map, u8 *, 0x52) = (u8)idx;
                Ov001_PlaySound(6);
                Ov001_SetStepCallback((M2C_UNK *)&MapSelectList_BeginExit);
                goto done;
            }
        }
    default:
        break;
    }
done:
    return;
}
#pragma optimize_for_speed reset
/* Map-select list exit step (a map was chosen): lock the icon row, hold it for a
 * few frames, then hand the step over to the screen's fade-out. */
void MapSelectList_BeginExit(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK MapSelectList_FadeOut;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&MapSelectList_FadeOut);
}

/* Fade the map-select list out: once the previous fade has finished, slide the
 * icon row away when a map was chosen (otherwise lock it), then start the white
 * fade over both screens and hand over to MapSelectList_Leave. */
void MapSelectList_FadeOut(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gMapSelectState;
    extern M2C_UNK MapSelectList_Leave;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_CHOSEN) != 0) {
        Ov001_StartIconRowSlideOut();
    } else {
        Ov001_LockIconRow();
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, 1, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, 0x1D, 8);
    Ov001_SetStepCallback(&MapSelectList_Leave);
}

#pragma optimization_level 4
#pragma opt_strength_reduction off
/* Leaves the map-select list: once the fades have finished, frees the list's
 * row sprites and loaded backgrounds and starts the selected map's preview,
 * the match, or the cancel path. */
void MapSelectList_Leave(void) {
extern s32 gMapSelectState,data_ov001_02193d9c;
extern s32 func_ov001_02181a84,Ov001_OpenFriendListScreen,InitNameEntryScreen,Ov001_PrepareSaveSlotMenu;
s32 Ov001_IsFadeActive(s32);s32 Ov001_IsIconRowIdle(void);void *GetCurrentMapRecord(void);
s32 i; void *obj;
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
if(!Ov001_IsIconRowIdle())return;
Ov001_ReturnTaskNodeVeneer(1,M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x3c));
for(i=0;i<MAPSELECT_ROWS;i++){
obj=M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4)+i*4,void **,MAPSELECT_ROW_OBJS_A);if(obj)Ov001_ReleaseSprite(obj);
obj=M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4)+i*4,void **,MAPSELECT_ROW_OBJS_B);if(obj)Ov001_ReleaseSprite(obj);
}
Ov001_FreePanelBackground(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),void **,12));
Ov001_DestroyScrollBar();Ov001_FreeSpriteObjects();Ov001_FreeMessagePanel();FreeMapPreview();
Ov001_FreeFile(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),void **,4));
Ov001_FreeFile(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),void **,8));
Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,29);
*(u32 *)0x04000010=0;*(u32 *)0x04000018=0;
if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,MAPSELECT_CHOSEN)==0){
Ov001_FreeFriendRoster();LoadSaveSlot(M2C_FIELD(GetCurrentMapRecord(),u8 *,0xf4));Ov001_SetNextScreenMode(2,0);Ov001_SetStepCallback(&func_ov001_02181a84);
}else if(M2C_FIELD(&gMapSelectState,u8 *,0)==4){
Ov001_FreeFriendRoster();Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback(&Ov001_OpenFriendListScreen);
}else{
obj=M2C_FIELD(&gMapSelectState,void **,4);
Ov001_SetSaveMapName(M2C_FIELD(obj,void **,MAPSELECT_ENTRIES)+M2C_FIELD(obj,u8 *,MAPSELECT_INDEX)*MAPSELECT_ENTRY_SIZE);
Ov001_SetNextScreenMode(0,0);
obj=M2C_FIELD(&gMapSelectState,void **,4);
if(M2C_FIELD(M2C_FIELD(obj,void **,MAPSELECT_ENTRIES)+M2C_FIELD(obj,u8 *,MAPSELECT_INDEX)*MAPSELECT_ENTRY_SIZE,u8 *,MAPSELECT_ENTRY_FLAG)){
Ov001_SetNextScreenMode(0,1);Ov001_SetNameEntryMode(1,1);Ov001_SetStepCallback(&InitNameEntryScreen);
}else{
Ov001_SetNextScreenMode(0,1);Ov001_SetNameEntryMode(0,1);Ov001_SetStepCallback(&Ov001_PrepareSaveSlotMenu);
}
}
Ov001_FreeAlloc(&data_ov001_02193d9c);
}
/* Redraws the map-select list's visible rows: clears the row-name panel, draws
 * each visible map's name into it, points each row's label and name sprites at
 * that map's tiles, then closes the panel and lays the rows out again. */
void MapSelectList_Redraw(void) {
    s32 HardwareDivide(s32, u16); /* hardware divide unit: quotient */
    void MapSelectList_DrawMapName(s32, s32);
    M2C_UNK MapSelectList_SetRowTiles(s32, s32);
    M2C_UNK MapSelectList_PositionRows();
    M2C_UNK TextPanel_ClearText(M2C_UNK, M2C_UNK);
    M2C_UNK CloseTextPanel(M2C_UNK);
    extern M2C_UNK gMapSelectState;
    s32 visibleRows;
    s32 firstRow;
    s32 row;
    s32 mapIndex;

    mapIndex = HardwareDivide(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL), MAPSELECT_ROW_UNITS);
    visibleRows = M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_COUNT);
    TextPanel_ClearText(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_TEXT_PANEL), 0);
    if (visibleRows > MAPSELECT_ROWS) {
        visibleRows = MAPSELECT_ROWS;
    }
    firstRow = mapIndex;
    row = 0;
    if (visibleRows > 0) {
        do {
            MapSelectList_DrawMapName(firstRow, row);
            row += 1;
            firstRow += 1;
        } while (row < visibleRows);
    }
    row = 0;
    if (visibleRows > 0) {
        do {
            MapSelectList_SetRowTiles(mapIndex, row);
            row += 1;
            mapIndex += 1;
        } while (row < visibleRows);
    }
    CloseTextPanel(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_TEXT_PANEL));
    MapSelectList_PositionRows();
}

/* Draws the name of the map at list position `index` on row `row` of the
   map-select list: up to 16 characters on the first line and, when the name is
   longer, the next 16 on a second line 12 pixels below. */
void MapSelectList_DrawMapName(s32 index, s32 row) {
extern M2C_UNK gMapSelectState;
s32 StringLengthUpTo(u8 *,s32);
M2C_UNK MI_CpuFill8(void *,s32,s32);
M2C_UNK DrawTextRun(void *,s32,s32,s32,s32,u16 *,s32);
u16 buf[17];
s32 offset=index*MAPSELECT_ENTRY_SIZE;
s32 len=StringLengthUpTo(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),u8 **,MAPSELECT_ENTRIES)+offset,32);
s32 y=row*28;
s32 n,i;
void *ctx;
if(index>=M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),u8 *,MAPSELECT_COUNT))return;
if(len<=16)y+=6;
MI_CpuFill8(buf,0,34);
n=len<=16?len:16;
i=0;
if(n>0){ctx=M2C_FIELD(&gMapSelectState, void **, 4);
do {buf[i]=M2C_FIELD(ctx,u8 **,MAPSELECT_ENTRIES)[offset+i];}while(++i<n);
}
DrawTextRun(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),void **,MAPSELECT_TEXT_PANEL),10,y,2,10,buf,1);
if(len<=16)return;
MI_CpuFill8(buf,0,34);
len-=16;
index=0;
if(len>0){ctx=M2C_FIELD(&gMapSelectState, void **, 4);
do {buf[index]=M2C_FIELD(ctx,u8 **,MAPSELECT_ENTRIES)[offset+index+16];}while(++index<len);
}
DrawTextRun(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),void **,MAPSELECT_TEXT_PANEL),10,y+12,2,10,buf,1);
}

