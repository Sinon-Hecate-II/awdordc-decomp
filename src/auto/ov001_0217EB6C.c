/* 37 functions from 0x0217EB6C to 0x0217FB68 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "wfc.h"
#include "ov001_wh.h"
typedef struct { u8 bytes[4]; } FourBytes;
typedef struct { u8 bytes[14]; } FourteenBytes;
typedef struct { u16 a,b,c,d; } FourShorts;

#pragma scheduling on
s32 GetMapListTouchedEntry(void){
 s32 TouchRectPressed(void *);s32 TouchRectSizePressed(FourShorts *);
 s32 HardwareDivide(u16,s32);
 extern M2C_UNK gTouchScreenRect,gMapListState;
 extern FourBytes gOv001MapListLayout;
 extern u8 gMapListRowToState[],data_ov001_0218f952[];
 FourShorts rect; s32 value,i,j,k;u8 *p;
 if(!TouchRectPressed(&gTouchScreenRect))return 14;
 value=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+4);
 for(i=0;i<4;i++,value++){
 if(value!=2 && value!=6){if(TouchRectSizePressed(&rect))return gMapListRowToState[value];}
 rect.b+=29;
 }
 value=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);
 for(j=0;j<4;j++,value++){
 if(value==2){
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+20);
 rect.b+=j*29;
 if(TouchRectSizePressed(&rect))return 2;
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+12);
 rect.b+=j*29;
 if(TouchRectSizePressed(&rect))return 3;
 break;
 }
 }
 value=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);
 for(k=0;k<4;k++,value++){
 if(value==6){
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+20);
 rect.b+=k*29;
 if(TouchRectSizePressed(&rect))return 7;
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+12);
 rect.b+=k*29;
 if(TouchRectSizePressed(&rect))return 8;
 break;
 }
 }
 p=data_ov001_0218f952;
 for(i=0;i<3;i++,p+=8){if(TouchRectPressed(p))return i+11;}
 return 14;
}
#pragma scheduling reset
/* Screen row (0..3) at which the given absolute list row is shown under the
 * current scroll position, or -1 when the row is not one of the visible rows. */
s32 GetMapListScreenRow(s32 row) {
    s32 HardwareDivide(u16, s32);
    extern M2C_UNK gMapListState;
    s32 visibleRow;
    s32 i;

    visibleRow = HardwareDivide(M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL), OV001_MAP_LIST_ROW_HEIGHT);
    for (i = 0; i < 4; i++, visibleRow++) {
        if (visibleRow == row) return i;
    }
    return -1;
}

/* Absolute list row shown at the given visible row (0..3) under the current
 * scroll position: the first visible row is the scroll offset's row. */
s32 GetMapListRowAt(s32 visibleRow) {
    s32 HardwareDivide(u16, s32);
    extern M2C_UNK gMapListState;
    s32 row;

    row = HardwareDivide(M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL), OV001_MAP_LIST_ROW_HEIGHT);
    row += visibleRow;
    return row;
}

/* One step of the map-list scroll-up animation: move the scroll position a row
 * step toward the top, and once it lands on a row boundary rebuild the row
 * sprites, move the scroll bar handle and hand the finished scroll back to the
 * list state machine. */
void MapListScrollUp(s32 message) {
    s32 HardwareDivideRemainder(u16, s32);
    extern M2C_UNK gMapListState;
    s32 delta, remainder;
    Ov001_BlockScrollBar();
    Ov001_FreeSpriteObjects();
    if ((u32)M2C_FIELD(&gMapListState, u16 *, 4) > 6U)
        M2C_FIELD(&gMapListState, u16 *, 4) = M2C_FIELD(&gMapListState, u16 *, 4) - 6;
    else
        M2C_FIELD(&gMapListState, u16 *, 4) = 0;
    remainder = HardwareDivideRemainder(M2C_FIELD(&gMapListState, u16 *, 4), 29);
    if (remainder == 23) {
        MapListRedrawInfoPanel();
        return;
    }
    if (remainder > 23) {
        delta = 29 - remainder;
        M2C_FIELD(&gMapListState, u16 *, 4) = M2C_FIELD(&gMapListState, u16 *, 4) + (29 - remainder);
        remainder = 0;
    }
    MapListUpdateRowSprites();
    if (remainder != 0) return;
    Ov001_UpdateScrollbarHandle((M2C_FIELD(&gMapListState, u16 *, 4) * 55) / 145);
    Ov001_UnblockScrollBar();
    MapList_UpdateStateFromRow();
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, 0x38) = 0;
    Ov001_PostTaskMessage(0, message);
}

/* One step of the map-list scroll-down animation, the mirror of MapListScrollUp:
 * move the scroll position a row step toward the bottom, and once it lands on a
 * row boundary rebuild the rows' sprites, move the scroll-bar handle, snap the
 * selected row's state and hand the finished scroll back to the list state
 * machine; between boundaries it only advances the row sprites. */
void MapListScrollDown(s32 message) {
    s32 HardwareDivideRemainder(u16, s32);
    M2C_UNK Ov001_BlockScrollBar();
    M2C_UNK Ov001_FreeSpriteObjects();
    M2C_UNK MapListUpdateRowSprites();
    M2C_UNK MapListRedrawInfoPanel();
    M2C_UNK Ov001_UpdateScrollbarHandle(s32);
    M2C_UNK Ov001_UnblockScrollBar();
    M2C_UNK MapList_UpdateStateFromRow();
    M2C_UNK Ov001_PostTaskMessage(s32, s32);
    extern M2C_UNK gMapListState;
    s32 remainder;
    Ov001_BlockScrollBar();
    Ov001_FreeSpriteObjects();
    M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL) = M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL) + OV001_MAP_LIST_SCROLL_STEP;
    remainder = HardwareDivideRemainder(M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL), OV001_MAP_LIST_ROW_HEIGHT);
    if (remainder >= OV001_MAP_LIST_SCROLL_STEP) {
        MapListUpdateRowSprites();
        return;
    }
    M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL) = M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL) - remainder;
    MapListRedrawInfoPanel();
    Ov001_UpdateScrollbarHandle((M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL) * OV001_MAP_LIST_HANDLE_TRAVEL) / OV001_MAP_LIST_SCROLL_MAX);
    Ov001_UnblockScrollBar();
    MapList_UpdateStateFromRow();
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), s32 *, OV001_MAP_LIST_TASK) = 0;
    Ov001_PostTaskMessage(0, message);
}

/* Refresh the map list's background scroll when the screen object asks for it:
 * set the vertical scroll of BG0 to the list's position within the top row and
 * BG2 to that plus the top row's extra offset, then clear the request. */
void MapListUpdateBackgroundScroll(void){
 s32 HardwareDivide(u16,s32);s32 HardwareDivideRemainder(u16,s32);
 extern M2C_UNK gMapListState;
 extern volatile u8 gMapListRowBgOffset[];
 s32 row,scroll;u32 rowOffset;
 if(!M2C_FIELD(M2C_FIELD(&gMapListState,void **,OV001_MAP_LIST_OBJECT),u8 *,OV001_MAP_LIST_BG_DIRTY))return;
 row=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,OV001_MAP_LIST_SCROLL),OV001_MAP_LIST_ROW_HEIGHT);
 scroll=HardwareDivideRemainder(M2C_FIELD(&gMapListState,u16 *,OV001_MAP_LIST_SCROLL),OV001_MAP_LIST_ROW_HEIGHT)-51;
 rowOffset=gMapListRowBgOffset[row];
 REG_BG0OFS=(scroll<<16)&0x1ff0000;
 REG_BG2OFS=((scroll+rowOffset)<<16)&0x1ff0000;
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,OV001_MAP_LIST_OBJECT),u8 *,OV001_MAP_LIST_BG_DIRTY)=0;
}

/* Selects a map-layout entry from the state index and applies it via Ov001_LayoutChoiceFrameRow. */
void MapList_ApplyRowLayout(void) {
    extern FourteenBytes data_ov001_0218f8e0;
    extern M2C_UNK gMapListState;
    extern u16 data_ov001_0218f96a[], data_ov001_0218f96e[], data_ov001_0218f96c[];
    void Ov001_LayoutChoiceFrameRow(s32, u16, u16, u16);
    FourteenBytes layout = data_ov001_0218f8e0;
    FourShorts entry;
    s32 i = layout.bytes[M2C_FIELD(&gMapListState, u8 *, 0)];
    if (i >= 3) {
        Ov001_LayoutChoiceFrameRow(3, data_ov001_0218f96a[i * 4], data_ov001_0218f96e[i * 4], data_ov001_0218f96c[i * 4]);
        return;
    }
    entry = ((FourShorts *)data_ov001_0218f96a)[i];
    entry.b += M2C_FIELD(&gMapListState, u8 *, 2) * 29;
    Ov001_LayoutChoiceFrameRow(1, entry.a, entry.c, entry.b);
}

/* Set the map-list screen's state from the list row under the selection: the two
 * save rows (2 and 6) pick one of two states from the working save slot's
 * empty-code flags (SAVE_SLOT_EMPTY_A/B), every other row takes its state from
 * gMapListRowToState.  The sub-screen states 11..13 keep the list's row layout,
 * and the row layout is re-applied either way. */
M2C_UNK MapList_UpdateStateFromRow(void) {
    void *GetCurrentMapRecord(void);
    s32 HardwareDivide(u16, s32);
    void MapList_ApplyRowLayout(void);
    extern M2C_UNK gMapListState;
    extern u8 gMapListRowToState[];
    u8 *record;
    s32 row, selected;

    if ((u8)(M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) + 0xF5) <= 2) {
        MapList_ApplyRowLayout();
        return;
    }
    record = GetCurrentMapRecord();
    row = HardwareDivide(M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL), OV001_MAP_LIST_ROW_HEIGHT);
    selected = M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_ROW);
    selected += row;
    switch (selected) {
    case 2:
        if (record[SAVE_SLOT_EMPTY_A]) M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) = 2;
        else M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) = 3;
        break;
    case 6:
        if (record[SAVE_SLOT_EMPTY_B]) M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) = 7;
        else M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) = 8;
        break;
    default:
        M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) = gMapListRowToState[selected];
        break;
    }
    MapList_ApplyRowLayout();
}

/* Select map-list choice `choice`: make it the screen's state, move the row
 * highlight to the list row the choice stands for and lay that row out. */
void SelectMapListChoice(u32 choice) {
    void MapList_ApplyRowLayout(void);
    extern M2C_UNK gMapListState;
    extern u8 gMapListChoiceRow[];
    M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) = choice;
    M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_ROW) = GetMapListScreenRow(gMapListChoiceRow[choice]);
    MapList_ApplyRowLayout();
}

void MapList_ApplyInputEvent(s32 event) {
    void *GetCurrentMapRecord(void);
    M2C_UNK Ov001_PlaySound(s32);
    s32 Ov001_AddTask(s32, void (*)(s32), s32, s32);
    extern M2C_UNK gMapListState;
    void *context;
    s32 result;
    u8 state;

    context = GetCurrentMapRecord();
    result = 0;
    state = M2C_FIELD(&gMapListState, u8 *, 0);
    if (state == 8 && !M2C_FIELD(context, u8 *, 0xf5)) {
        if (event == 0 || event == 2) return;
    }
    switch (state) {
    case 0:
        if (event == 1) {
            M2C_FIELD(&gMapListState, u8 *, 0) = 11;
        } else if (event == 3) {
            M2C_FIELD(&gMapListState, u8 *, 2) = M2C_FIELD(&gMapListState, u8 *, 2) + 1;
        } else {
            result = 2;
        }
        break;
    case 10:
        if (event == 1) {
            M2C_FIELD(&gMapListState, u8 *, 2) = M2C_FIELD(&gMapListState, u8 *, 2) - 1;
        } else if (event == 3) {
            M2C_FIELD(&gMapListState, u8 *, 0) = M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x42);
        } else {
            result = 2;
        }
        break;
    case 11:
        if (event == 1) {
            if (M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47)) return;
            Ov001_PlaySound(9);
            M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 1;
            return;
        } else if (event == 3) {
            M2C_FIELD(&gMapListState, u8 *, 0) = 0;
            M2C_FIELD(&gMapListState, u8 *, 2) = 0;
            M2C_FIELD(&gMapListState, u16 *, 4) = 0;
            MapListRedrawInfoPanel();
            Ov001_UpdateScrollbarHandle(0);
        } else {
            result = 2;
        }
        break;
    case 12:
    case 13:
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x42) = state;
        if (event == 1) {
            M2C_FIELD(&gMapListState, u8 *, 0) = 10;
            M2C_FIELD(&gMapListState, u8 *, 2) = 3;
            M2C_FIELD(&gMapListState, u16 *, 4) = 145;
            MapListRedrawInfoPanel();
            Ov001_UpdateScrollbarHandle(55);
        } else if (event == 3) {
            if (M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47)) return;
            Ov001_PlaySound(9);
            M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 1;
            return;
        } else {
            if (state == 12) {
                M2C_FIELD(&gMapListState, u8 *, 0) = 13;
            } else {
                M2C_FIELD(&gMapListState, u8 *, 0) = 12;
            }
        }
        break;
    default:
        if (event == 1) {
            if (M2C_FIELD(&gMapListState, u8 *, 2)) {
                M2C_FIELD(&gMapListState, u8 *, 2) = M2C_FIELD(&gMapListState, u8 *, 2) - 1;
            } else {
                Ov001_PlaySound(19);
                M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, 0x38) = Ov001_AddTask(0, MapListScrollUp, 0, 120);
                return;
            }
        } else if (event == 3) {
            if (M2C_FIELD(&gMapListState, u8 *, 2) < 3) {
                M2C_FIELD(&gMapListState, u8 *, 2) = M2C_FIELD(&gMapListState, u8 *, 2) + 1;
            } else {
                Ov001_PlaySound(19);
                M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, 0x38) = Ov001_AddTask(0, MapListScrollDown, 0, 120);
                return;
            }
        } else {
            result = 2;
            if (state == 2) {
                M2C_FIELD(&gMapListState, u8 *, 0) = 3;
            } else if (state == 3) {
                M2C_FIELD(&gMapListState, u8 *, 0) = 2;
            } else if (state == 7) {
                M2C_FIELD(&gMapListState, u8 *, 0) = 8;
            } else if (state == 8) {
                M2C_FIELD(&gMapListState, u8 *, 0) = 7;
            } else {
                break;
            }
            Ov001_PlaySound(8);
            MapList_ApplyRowLayout();
        }
        break;
    }
    if (result == 2) return;
    Ov001_PlaySound(8);
    if (result == 0) MapList_UpdateStateFromRow();
}

/* Upload the icon tile of the current save-slot sub-screen (states 11..13) from
 * the list's OBJ tilemap to the same OBJ VRAM tile slot, so the entry the player
 * just picked shows its icon. */
void MapList_UploadSubScreenIcon(void) {
    void Ov001_LoadObjTile(s32, u8, u8);
    extern M2C_UNK gMapListState;
    extern u8 gMapListSaveIconTile[];
    u8 tile = gMapListSaveIconTile[M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) - OV001_MAP_LIST_SAVE_SCREEN_FIRST];

    Ov001_LoadObjTile(M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), s32 *, OV001_MAP_LIST_OBJ_TILEMAP), tile, tile);
}

/* Per-frame map-list task: tick down each of the four rows' custom-map highlight
 * timers and redraw the info panel when one expires. */
void MapListUpdateRowHighlightTimers(void){extern M2C_UNK gMapListState;M2C_UNK MapListRedrawInfoPanel();s32 i=0;do{u8 *object=(u8 *)M2C_FIELD(&gMapListState,void **,OV001_MAP_LIST_OBJECT)+i;if(object[OV001_MAP_LIST_ROW_HIGHLIGHT]){object[OV001_MAP_LIST_ROW_HIGHLIGHT]--;if(!M2C_FIELD((u8 *)M2C_FIELD(&gMapListState,void **,OV001_MAP_LIST_OBJECT)+i,u8 *,OV001_MAP_LIST_ROW_HIGHLIGHT))MapListRedrawInfoPanel();}i++;}while(i<4);}

/* Highlights the custom-map row the player just picked on the map list: the
 * four entries that open a custom-map list come as two pairs (local maps 2 and
 * 3, link maps 7 and 8), so the picked entry's highlight timer is started (20
 * frames, counted down by the row update task) and its pair's timer cleared. */
void MapListHighlightCustomRow(void) {
extern M2C_UNK gMapListState;
extern FourBytes gOv001MapListLayout;
FourBytes entries=gOv001MapListLayout; s32 slot;
for(slot=0;slot<4;slot++) {
if(M2C_FIELD(&gMapListState,u8 *,0)==entries.bytes[slot]){
M2C_FIELD(M2C_FIELD(&gMapListState,void **,8)+slot,u8 *,4)=20;
if(slot&1) { M2C_FIELD(M2C_FIELD(&gMapListState,void **,8)+(slot-1),u8 *,4)=0; return; }
else M2C_FIELD(M2C_FIELD(&gMapListState,void **,8)+(slot+1),u8 *,4)=0;
return;
}
}
}

/* Whether the working save slot can be opened: a map name must be stored, each
   stored pair of player codes must be present (the second pair needs only one
   valid code, the first pair both), and the first pair must agree with the slot's
   stored code word. */
s32 IsCurrentSaveSlotValid(void) {
    void *GetCurrentMapRecord(void);
    s32 IsValidTextChar(void *);
    s32 IsSavedPlayerCodeValid(void *, void *);
    u8 *record = GetCurrentMapRecord();

    if (!record[SAVE_SLOT_MAP_NAME]) return 0;
    if (!record[SAVE_SLOT_EMPTY_B] &&
        !IsValidTextChar(record + SAVE_SLOT_PLAYER_CODES + 8) &&
        !IsValidTextChar(record + SAVE_SLOT_PLAYER_CODES + 12)) return 0;
    if (!record[SAVE_SLOT_EMPTY_A]) {
        if (!IsValidTextChar(record + SAVE_SLOT_PLAYER_CODES)) return 0;
        if (!IsValidTextChar(record + SAVE_SLOT_PLAYER_CODES + 4)) return 0;
        if (!IsSavedPlayerCodeValid(record + SAVE_SLOT_PLAYER_CODES, record + SAVE_SLOT_CODE)) return 0;
    }
    return 1;
}

/* Map-list message-box step: wait for the player to confirm the message, then
 * play the confirm sound, close the box, restore the list background's palette
 * from its loaded palette file, and switch to the step that waits for the box to
 * finish closing. */
void MapList_DismissMessage(void) {
    s32 Ov001_GetRegionMenuSelection(void);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_CloseRegionMenu();
    M2C_UNK Ov001_LoadMainPalette(s32);
    extern M2C_UNK gMapListState;
    extern M2C_UNK MapList_WaitMessageClosed;

    if (Ov001_GetRegionMenuSelection()) return;
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_LoadMainPalette(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, OV001_MAP_LIST_PALETTE));
    Ov001_SetStepCallback(&MapList_WaitMessageClosed);
}

/* Map-list step after a message box was dismissed: once the region menu has
 * finished closing, return to the map list's input step. */
void MapList_WaitMessageClosed(void) {
    s32 Ov001_IsRegionMenuActive();
    extern M2C_UNK Ov001_UpdateMapListInput;
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_UpdateMapListInput);
}

void SetMapListMode(s8 arg0) {
    extern M2C_UNK gMapListState;
    M2C_FIELD(&gMapListState, s8 *, 1) = arg0;
}

/* Step that hands another screen back to the ov001 map list: reload its
 * background and save-slot sprites, commit the working save slot and fade the
 * list back in. */
void Ov001_ReopenMapListScreen(void) {
    M2C_UNK Ov001_LoadSaveSlotObjLayout();
    void MapList_LoadBackground();
    M2C_UNK CommitSaveSlot();
    extern M2C_UNK Ov001_FadeInMapListScreen;
    MapList_LoadBackground();
    Ov001_LoadSaveSlotObjLayout();
    CommitSaveSlot();
    Ov001_SetStepCallback(&Ov001_FadeInMapListScreen);
}

/* Reload what the map-list screen draws behind its list: the background's
 * character, palette and screen files, then the two background layers of each
 * engine are pushed to the lowest priority so the list's sprites stay in front. */
void MapList_LoadBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK sMapListBgCharName, sMapListBgPaletteName, sMapListBgScreenName;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

    Ov001_LoadAsset(&sMapListBgCharName, &GX_LoadBG2Char);
    Ov001_LoadAsset(&sMapListBgPaletteName, &GX_LoadBGPltt);
    Ov001_LoadAsset(&sMapListBgScreenName, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

/* Fades in the ov001 map-list screen: start the sub and main fades from white,
 * enable its background and object planes, then move on to the step that shows
 * the connect message. */
void Ov001_FadeInMapListScreen(void) {
    extern M2C_UNK Ov001_ShowMapListConnectMessage;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, GX_PLANEMASK_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback(&Ov001_ShowMapListConnectMessage);
}

/* Map-list fade-in step: once both engines' fades have finished, show the
 * connect message and install the step that waits for it to be dismissed. */
void Ov001_ShowMapListConnectMessage(void) {
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_MapListRegionClosed;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_ShowMessage(0x44, 5, 1, -1, 0);
    Ov001_SetStepCallback(&Ov001_MapListRegionClosed);
}

/* Per-frame map-list step that runs after the connect message is up: wait for
 * the region-column menu to close, then fade the map list out to the access-point
 * screen. */
void Ov001_MapListRegionClosed(void) {
    s32 Ov001_IsRegionMenuActive(void);
    void func_ov001_0217f8bc(void);
    void func_ov001_0217f8c0(void);
    void Ov001_FadeOutMapListForAccessPoint(void);

    func_ov001_0217f8bc();
    func_ov001_0217f8c0();
    if (Ov001_IsRegionMenuActive()) {
        return;
    }
    Ov001_SetStepCallback(Ov001_FadeOutMapListForAccessPoint);
}

void func_ov001_0217f8bc(void) {

}

void func_ov001_0217f8c0(void) {

}

/* Fade the map list out to white (sub BG0, main BG2 and OBJ) and move on to the
 * step that closes it and opens the access-point menu. */
void Ov001_FadeOutMapListForAccessPoint(void) {
    extern M2C_UNK Ov001_CloseMapListForAccessPoint;
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_CloseMapListForAccessPoint);
}

/* Fade-out completion step of the map-list screen: once both engines' fades have
 * finished, free the option background, disable its visible planes, set the
 * access-point screen mode and install Ov001_OpenAccessPointMenu as the next
 * step. */
void Ov001_CloseMapListForAccessPoint(void) {
    M2C_UNK Ov001_FreeMessagePanel();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_FreeMessagePanel();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x14);
    Ov001_SetNextScreenMode(2, 1);
    Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);
}

/* TRUE while the console's lid is closed (bit SHARED_LID_CLOSED of the shared
 * work area's lid word). */
s32 Ov001_CheckLidClosed(void) {
    if (((s32) (*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

/* Open the connection screen by loading its background and message, then scheduling its fade-in. */
void Ov001_OpenConnectionScreen(void) {
    void Ov001_LoadConnectionBackground(void);
    void Ov001_FadeInConnectionScreen(void);
    M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
    extern u8 gOv001OptionExitToConnection;

    gOv001OptionExitToConnection = 0;
    Ov001_LoadConnectionBackground();
    Ov001_LoadSaveSlotObjLayout();
    Ov001_ShowMessageBox(OV001_MSG_CONNECTION);
    Ov001_CreateAnimSprite(1);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInConnectionScreen);
}

/* Loads the connection screen's background map and gives both engines'
 * background planes the lowest priority so the screen's sprites and text draw
 * over it. */
void Ov001_LoadConnectionBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001ConnectionBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001ConnectionBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Step that fades the connection screen in from white on the main engine, reveals
 * its background and sprite planes, then hands over to the step that runs once the
 * fade has finished. */
void Ov001_FadeInConnectionScreen(void) {
    extern M2C_UNK Ov001_ConnectionScreenFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_ConnectionScreenFadeDone);
}

/* Connection-screen step once the fade-in has finished: wait for the main engine's
 * fade, put up the shared back/confirm icon row and install the step that waits for
 * the player's choice. */
void Ov001_ConnectionScreenFadeDone(void) {
    void Ov001_ConnectionScreenWaitIconRow(void);
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) return;
    Ov001_CreateMenuIconRow(1);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_ConnectionScreenWaitIconRow);
}

/* Step that runs once the Wi-Fi connection screen's icon row is up: wait for the
 * row's selection to become available, unlock it and hand over to the row's
 * per-frame input update. */
void Ov001_ConnectionScreenWaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK Ov001_UpdateOptionPage1;

    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateOptionPage1);
}

/* Option page 1's per-frame step: wait a frame, then process the page's choice,
 * its B/lid cancel input, the no-op step and the back choice. */
void Ov001_UpdateOptionPage1(void) {
    M2C_UNK SleepMilliseconds(s32);
    M2C_UNK Ov001_HandleOptionPage1Choice();
    void Ov001_CancelOptionSelection(void);
    void func_ov001_0217fb18(void);
    void Ov001_HandleOptionPage1Back(void);
    SleepMilliseconds(10);
    Ov001_HandleOptionPage1Choice();
    Ov001_CancelOptionSelection();
    func_ov001_0217fb18();
    Ov001_HandleOptionPage1Back();
}

/* Cancel the option-screen selection, latching the back choice: either the
 * player pressed B, or the console's lid was closed. */
void Ov001_CancelOptionSelection(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    s32 Ov001_CheckLidClosed(void);
    if (KeyPressed(KEY_B) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
        return;
    }
    if (Ov001_CheckLidClosed() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_0217fb18(void) {

}

/* Option-menu step that runs after the page-1 input pass: when the player chose
 * back (selection 0), play the cancel sound and prepare to leave the screen. */
void Ov001_HandleOptionPage1Back(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK Ov001_PrepareOptionScreenExit;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(OV001_SOUND_CANCEL);
    Ov001_SetStepCallback(&Ov001_PrepareOptionScreenExit);
}

/* Option-screen exit step after the player chose back: lock the icon row,
 * hold it for a few frames, then hand the step over to the screen's fade-out. */
void Ov001_PrepareOptionScreenExit(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_BeginOptionScreenExit;
    Ov001_LockIconRow();
    Ov001_StartDelay(OV001_STEP_DELAY_FRAMES);
    Ov001_SetStepCallback(&Ov001_BeginOptionScreenExit);
}

