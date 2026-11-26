/* 28 functions from 0x0217AE38 to 0x0217BD88 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ov001_wh.h"
void Ov001_LoadNameEntryGraphics(void);
void UpdateNameEntryCursor(void);
void RedrawNameEntryText(void);

void MapSelectList_ApplyRowLayout(void);

/* Give the (row)th label and map-name sprite of the map-select list the tiles of
 * entry mapIndex: the label's tile comes from MAPSELECT_LABEL_TILES indexed by the
 * entry's flag byte, the name's from MAPSELECT_NAME_TILES indexed by the entry's
 * name id.  Entries past the end of the list are ignored. */
void MapSelectList_SetRowTiles(s32 mapIndex, s32 row) {
    extern M2C_UNK gMapSelectState;
    s32 entryOffset;
    void *labelSprite, *nameSprite;
    if (mapIndex >= M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_COUNT)) return;
    entryOffset = mapIndex * MAPSELECT_ENTRY_SIZE;
    labelSprite = M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ) + row * 4, void **, MAPSELECT_ROW_OBJS_A);
    M2C_FIELD(labelSprite, u16 *, MAPSELECT_ROW_TILE) = (M2C_FIELD(labelSprite, u16 *, MAPSELECT_ROW_TILE) & ~0x3FF) | M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ) + 2 * M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), void **, MAPSELECT_ENTRIES) + entryOffset, u8 *, MAPSELECT_ENTRY_FLAG), u16 *, MAPSELECT_LABEL_TILES);
    nameSprite = M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ) + row * 4, void **, MAPSELECT_ROW_OBJS_B);
    M2C_FIELD(nameSprite, u16 *, MAPSELECT_ROW_TILE) = (M2C_FIELD(nameSprite, u16 *, MAPSELECT_ROW_TILE) & ~0x3FF) | M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ) + 2 * M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), void **, MAPSELECT_ENTRIES) + entryOffset, u16 *, MAPSELECT_ENTRY_NAME_ID), u16 *, MAPSELECT_NAME_TILES);
}

/* Place the visible row sprites down the screen: the label and the map name of
 * each of the up-to-five visible rows, one 0x1C-pixel row apart, offset by the
 * list's current scroll position; then flag the BG scroll registers as dirty. */
void MapSelectList_PositionRows(void) {
    s32 HardwareDivideRemainder(u16, s32); /* hardware divide unit: remainder */
    extern M2C_UNK gMapSelectState;
    u32 *label, *name;
    s32 y, count, row;

    y = MAPSELECT_ROW_BASE_Y - HardwareDivideRemainder(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL), MAPSELECT_ROW_UNITS);
    count = M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_COUNT);
    row = 0;
    if (count > MAPSELECT_ROWS) count = MAPSELECT_ROWS;
    while (row < count) {
        label = ((u32 **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[row + 4];
        *label = (*label & 0xfe00ff00) | (u8)(y - 2) | (MAPSELECT_ROW_LABEL_X << 16);
        name = ((u32 **)M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ))[row + 9];
        row++;
        *name = (*name & 0xfe00ff00) | (u8)(y + 1) | (MAPSELECT_ROW_NAME_X << 16);
        y += MAPSELECT_ROW_UNITS;
    }
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_SCROLL_DIRTY) = 1;
}

/* Page the map-select list up towards its first row: pull the scroll position
 * back four units a frame; when the step crosses a row boundary, snap the scroll
 * back to the row and stop there.  Keep the row labels in step with the scroll,
 * and at the end of the step redraw the visible rows, release the scroll bar and
 * report the task's result.  Runs as the repeated-key scroll task. */
void MapSelectList_ScrollUp(s32 task) {
    s32 HardwareDivideRemainder(u16, s32); /* hardware divide unit: remainder */
    s32 HardwareDivide(s32, s32); /* hardware divide unit: quotient */
    extern M2C_UNK gMapSelectState;
    s32 remainder;

    Ov001_BlockScrollBar();
    Ov001_FreeSpriteObjects();
    if ((u32)M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) > 4U) {
        M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) = M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) - 4;
    } else {
        M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) = 0;
    }
    remainder = HardwareDivideRemainder(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL), MAPSELECT_ROW_UNITS);
    if (remainder == MAPSELECT_ROW_UNITS - 4) {
        MapSelectList_Redraw();
        return;
    }
    if (remainder > MAPSELECT_ROW_UNITS - 4) {
        M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) = M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) + (MAPSELECT_ROW_UNITS - remainder);
        remainder = 0;
    }
    MapSelectList_PositionRows();
    if (remainder != 0) return;
    HardwareDivide(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) * M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_LAST_ROW), M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u16 *, MAPSELECT_MAX_SCROLL));
    Ov001_UpdateScrollbarHandle();
    Ov001_UnblockScrollBar();
    MapSelectList_ApplyRowLayout();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_SCROLL_ANIM) = 0;
    Ov001_PostTaskMessage(0, task);
}

/* Page the map-select list down towards its last row: push the scroll position
 * forward four units a frame; once the step lands on a row boundary, snap the
 * scroll to it and finish - redraw the visible rows, move the scroll bar handle,
 * release the scroll bar and report the task's result.  Before then the rows are
 * only moved on screen.  Runs as the repeated-key scroll task. */
void MapSelectList_ScrollDown(s32 task) {
    s32 HardwareDivideRemainder(u16, s32); /* hardware divide unit: remainder */
    extern M2C_UNK gMapSelectState;
    s32 remainder;

    Ov001_BlockScrollBar();
    Ov001_FreeSpriteObjects();
    M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) = M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) + 4;
    remainder = HardwareDivideRemainder(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL), MAPSELECT_ROW_UNITS);
    if (remainder >= 4) {
        MapSelectList_PositionRows();
        return;
    }
    M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) = M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) - remainder;
    MapSelectList_Redraw();
    HardwareDivide(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) * M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_LAST_ROW), M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u16 *, MAPSELECT_MAX_SCROLL));
    Ov001_UpdateScrollbarHandle();
    Ov001_UnblockScrollBar();
    MapSelectList_ApplyRowLayout();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_SCROLL_ANIM) = 0;
    Ov001_PostTaskMessage(0, task);
}

/* If the map-select list moved, recompute the background scroll from the list's
 * scroll position and write it into the offset registers of both scrolling BG
 * layers, then clear the dirty flag. */
void MapSelectListUpdateBackgroundScroll(void) {
    s32 HardwareDivideRemainder(u16, M2C_UNK);
    extern M2C_UNK gMapSelectState;
    s32 scrollY;

    if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_SCROLL_DIRTY) == 0) {
        return;
    }
    scrollY = 0x01FF0000 & ((HardwareDivideRemainder(M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL), MAPSELECT_ROW_UNITS) - 0x32) << 0x10);
    REG_BG0OFS = scrollY;
    REG_BG2OFS = scrollY;
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_SCROLL_DIRTY) = 0U;
}

/* Give the map-select list's highlight frame the layout of the highlighted row:
 * the row's left and right end pieces and its y come from the layout table, and the
 * last visible row uses the third row style instead of the second. */
void MapSelectList_ApplyRowLayout(void) {
    void Ov001_LayoutChoiceFrameRow(s32, u16, u16, u16);
    extern u16 data_ov001_0218f7ec[], data_ov001_0218f7ee[], data_ov001_0218f7f0[];
    extern M2C_UNK gMapSelectState;
    u32 row = M2C_FIELD(&gMapSelectState, u8 *, MAPSELECT_STATE_CURSOR);
    Ov001_LayoutChoiceFrameRow(row < MAPSELECT_ROWS - 1 ? 2 : 3, data_ov001_0218f7ec[row * 4], data_ov001_0218f7f0[row * 4], data_ov001_0218f7ee[row * 4]);
}

/* Map-select list D-pad handler: moves the highlighted row up (dir == 1) or
 * down (dir == 3). At the top or bottom of the list it wraps the cursor or
 * pages the list on (scheduling the scroll animation at MAPSELECT_SCROLL_ANIM),
 * plays the cursor-move sound, or the no-move sound once per held key
 * (MAPSELECT_BUMP_LATCH). */
void MapSelectList_MoveCursor(s32 dir){
void MapSelectList_PageDown(void);
extern M2C_UNK gMapSelectState;
s32 Ov001_AddTask(s32,void (*)(s32),s32,s32);
s32 moved=1;s32 row=M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR);
switch(row) {
case 0: if(dir==1) {if(!M2C_FIELD(&gMapSelectState,u16 *,MAPSELECT_STATE_SCROLL)) M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=4;else {
Ov001_PlaySound(19);
M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),s32 *,MAPSELECT_SCROLL_ANIM)=Ov001_AddTask(0,MapSelectList_ScrollUp,0,120);return;
}} else {if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_COUNT)>1)M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row+1;else moved=0;}break;
case 1:case 2: if(dir==1)M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row-1;else {if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_COUNT)>(row+1))M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row+1;else moved=0;}break;
case 3:if(dir==1)M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row-1;else {MapSelectList_PageDown();return;}break;
case 4:if(dir==1)moved=0;else {M2C_FIELD(&gMapSelectState,u16 *,MAPSELECT_STATE_SCROLL)=0;M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=0;MapSelectList_Redraw();Ov001_UpdateScrollbarHandle(0);}break;
}
if(!moved){if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_BUMP_LATCH))return;Ov001_PlaySound(9);M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_BUMP_LATCH)=1;return;}
Ov001_PlaySound(8);MapSelectList_ApplyRowLayout();
}

/* Page the map-select list up from its first row: when the list is already at
 * its top play the no-move sound once per held key, otherwise start the
 * scroll-up task. */
void MapSelectList_PageUp(void) {
    M2C_UNK Ov001_PlaySound(s32);
    s32 Ov001_AddTask(s32, void (*)(s32), s32, s32);
    extern M2C_UNK gMapSelectState;
    if (M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) == 0) {
        if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_BUMP_LATCH) != 0) return;
        Ov001_PlaySound(9);
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_BUMP_LATCH) = 1;
        return;
    }
    Ov001_PlaySound(0x13);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_SCROLL_ANIM) = Ov001_AddTask(0, MapSelectList_ScrollUp, 0, 0x78);
}

/* Page the map-select list down from its last row: when the list is already at
 * its bottom (or holds only the visible rows) play the no-move sound once per
 * held key, otherwise start the scroll-down task. */
void MapSelectList_PageDown(void) {
    M2C_UNK Ov001_PlaySound(s32);
    s32 Ov001_AddTask(s32, void (*)(s32), s32, s32);
    extern M2C_UNK gMapSelectState;
    if (M2C_FIELD(&gMapSelectState, u16 *, MAPSELECT_STATE_SCROLL) == M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u16 *, MAPSELECT_MAX_SCROLL) || M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_COUNT) <= 4) {
        if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_BUMP_LATCH) != 0) return;
        Ov001_PlaySound(9);
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), u8 *, MAPSELECT_BUMP_LATCH) = 1;
        return;
    }
    Ov001_PlaySound(0x13);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_SCROLL_ANIM) = Ov001_AddTask(0, MapSelectList_ScrollDown, 0, 0x78);
}

/* Copy the map-select list's OBJ tile from the step-31 background set: the tile
 * number in sMapSelectObjTiles is both the source tile and the OBJ VRAM slot. */
void MapSelectList_LoadObjTile(void) {
    M2C_UNK Ov001_LoadObjTile(s32, u8, u8);
    struct Table { u8 values[1]; };
    extern struct Table sMapSelectObjTiles;
    extern M2C_UNK gMapSelectState;
    struct Table table = sMapSelectObjTiles;
    u8 value = table.values[0];
    Ov001_LoadObjTile(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, MAPSELECT_STATE_OBJ), s32 *, MAPSELECT_OBJ_STEP31_BG), value, value);
}

/* Step while the map-select notice is up: once the choice is confirmed
 * (Ov001_GetRegionMenuSelection returns 0) play the confirm sound, close the
 * message menu and install the step that restores the map-select input. */
void Ov001_ConfirmMapSelectNotice(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK MapSelectList_ResumeInput;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&MapSelectList_ResumeInput);
}

/* Step that restores the map-select list after its region menu closes: re-enable
 * the icon row and the scroll bar, then hand over to the list's update step.
 * Does nothing while the region menu is still open. */
void MapSelectList_ResumeInput(void) {
    M2C_UNK Ov001_UnlockIconRow();
    M2C_UNK Ov001_UnblockScrollBar();
    s32 Ov001_IsRegionMenuActive();
    void MapSelectList_Update(void);
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_UnblockScrollBar();
    Ov001_SetStepCallback(&MapSelectList_Update);
}

/* Sets up the ov001 name-entry screen: gets its state block, loads the saved
 * name (when the current mode has one), picks the on-screen keyboard and message
 * for the mode, creates the text panel and cursor sprite and installs the first
 * step callback. */
void InitNameEntryScreen(void) {
extern void *gOv001NameEntryConfig; extern void *gNameEntryState;
void *Ov001_Alloc(s32,s32);void Ov001_GetNameEntryMode(s32 *,s32);
s32 StringLengthUpTo(void *,s32);void *CreateTextPanel(s32,s32);void *Ov001_CreateSpriteFromLayout(s32,s32);
void Ov001_FadeInNameEntryScreen(void);
u8 modeMessages[2]={M2C_FIELD(&gOv001NameEntryConfig,u8 *,0),M2C_FIELD(&gOv001NameEntryConfig,u8 *,1)};s32 mode,variant;
gNameEntryState=Ov001_Alloc(44,4);
Ov001_GetNameEntryMode(&mode,(s32)&variant);
if(mode==0) {Ov001_LoadSavedMapName((u8 *)gNameEntryState+NAME_ENTRY_TEXT); M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)=StringLengthUpTo((u8 *)gNameEntryState+NAME_ENTRY_TEXT,NAME_ENTRY_MAX_LENGTH);}
Ov001_LoadNameEntryGraphics();Ov001_LoadObjLayoutBlock(mode+9);
if(variant==1)Ov001_ShowMessagePanel(53,-1,0);else Ov001_ShowMessagePanel(modeMessages[mode],-1,0);
Ov001_OpenMenuForMode(2);
M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_PANEL)=CreateTextPanel(0,0);
M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_CURSOR)=Ov001_CreateSpriteFromLayout(0,62);
M2C_FIELD(M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_CURSOR),u16 *,4)=(M2C_FIELD(M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_CURSOR),u16 *,4)&~0xc00)|0xc00;
UpdateNameEntryCursor();RedrawNameEntryText();Ov001_SetStepCallback((s32 *)Ov001_FadeInNameEntryScreen);
}

/* Load the name-entry screen's graphics: keyboard OBJ palette, BG2 tiles,
 * BG palette and tilemap, then set background priorities (sub BG0/BG1 and
 * main BG1 lowest at 3, main BG0 at 2) so the keyboard sits in front. */
void Ov001_LoadNameEntryGraphics(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001NameEntryObjPalettePath;
    extern M2C_UNK gOv001NameEntryBgTilesPath;
    extern M2C_UNK gOv001NameEntryBgPalettePath;
    extern M2C_UNK gOv001NameEntryBgMapPath;
    extern M2C_UNK GX_LoadBGPltt;
    extern M2C_UNK GX_LoadOBJPltt;
    extern M2C_UNK GX_LoadBG2Scr;
    extern M2C_UNK GX_LoadBG2Char;
    Ov001_LoadAsset(&gOv001NameEntryObjPalettePath, &GX_LoadOBJPltt);
    Ov001_LoadAsset(&gOv001NameEntryBgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001NameEntryBgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001NameEntryBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 2;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

/* Fade in the name-entry screen's panel and screen and show its planes, then open
 * the on-screen keyboard in the next step. */
void Ov001_FadeInNameEntryScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_OpenNameEntryKeyboard;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&Ov001_OpenNameEntryKeyboard);
}

/* Step that runs once the name-entry screen has faded in: opens the on-screen
 * keyboard and sets its keys for the current name - nothing to delete while the
 * name is empty, nothing to add once it holds its full 32 characters - then waits
 * for the first key. */
void Ov001_OpenNameEntryKeyboard(void) {
    s32 Ov001_IsFadeActive(s32);
    M2C_UNK Ov001_OpenKeyboard(void);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_SetKeyboardCanDelete(s32);
    M2C_UNK Ov001_SetKeyboardCanAdd(s32);
    void Ov001_WaitKeyboardFirstKey(void);
    M2C_UNK Ov001_SetStepCallback();
    extern void *gNameEntryState;
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_OpenKeyboard();
    Ov001_PlaySound(0x14);
    if (M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_LENGTH) == 0) {
        Ov001_SetKeyboardCanDelete(0);
    }
    if (M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_LENGTH) == NAME_ENTRY_MAX_LENGTH) {
        Ov001_SetKeyboardCanAdd(0);
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitKeyboardFirstKey);
}

/* Step after the ov001 name-entry keyboard has opened: wait until the player
 * presses a key, then hand the step to the keyboard's input handler. */
void Ov001_WaitKeyboardFirstKey(void) {
    s32 GetKeyboardKey();
    void Ov001_KeyboardInputStep(void);
    if (GetKeyboardKey() == KBD_KEY_NONE) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_KeyboardInputStep);
}

void Ov001_KeyboardInputStep(void) {
    void HandleNameEntryInput(void);
    void func_ov001_0217b8f4(void);
    HandleNameEntryInput();
    func_ov001_0217b8f4();
}

/* Handles one event of the on-screen keyboard in the ov001 name-entry screen: a
 * delete removes the last character, cancel ends the entry, OK ends it only when
 * the text is valid, and a character key appends it while the buffer has room. */
void HandleNameEntryInput(void) {
extern void *gNameEntryState;
void func_ov001_0217b8f8(void);
s32 key=GetKeyboardKey(); s32 *obj;
switch(key){
case KBD_KEY_DELETE:
if(M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)){
Ov001_PlaySound(3);
M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)--;
M2C_FIELD((u8 *)gNameEntryState+M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH),u8 *,NAME_ENTRY_TEXT)=0;
if(!M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH))Ov001_SetKeyboardCanDelete(0);
Ov001_SetKeyboardCanAdd(1);
}
break;
case 0:break;
case KBD_KEY_CANCEL:
Ov001_PlaySound(7);M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_RESULT)=0;Ov001_SetStepCallback(func_ov001_0217b8f8);return;
case KBD_KEY_OK:
if(IsNameEntryValid()){
Ov001_PlaySound(6);M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_RESULT)=1;
}else{M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_RESULT)=2;Ov001_PlaySound(9);}
obj=M2C_FIELD(gNameEntryState,s32 **,NAME_ENTRY_CURSOR);*obj=(*obj&0xc1fffcff)|0x200;
Ov001_SetStepCallback(func_ov001_0217b8f8);return;
case KBD_KEY_SPACE:
default:
if(M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)!=32){
Ov001_PlaySound(1);
M2C_FIELD((u8 *)gNameEntryState+M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH),u8 *,NAME_ENTRY_TEXT)=key;
M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)++;
Ov001_SetKeyboardCanDelete(1);
if(M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)==32)Ov001_SetKeyboardCanAdd(0);
}
break;
}
RedrawNameEntryText();UpdateNameEntryCursor();
}

void func_ov001_0217b8f4(void) {

}

void func_ov001_0217b8f8(void) {
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FinishNameEntryKeyboard;
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FinishNameEntryKeyboard);
}

/* Name-entry teardown step: once the screen's fade has finished, close the
 * on-screen keyboard, play its close sound and hand the entry's result on to
 * Ov001_HandleNameEntryResult. */
void Ov001_FinishNameEntryKeyboard(void) {
    M2C_UNK Ov001_StartKeyboardClose();
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_HandleNameEntryResult;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartKeyboardClose();
    Ov001_PlaySound(OV001_SOUND_KEYBOARD_CLOSE);
    Ov001_SetStepCallback(&Ov001_HandleNameEntryResult);
}

/* Acts on the on-screen keyboard's name-entry result once the menu task has
 * finished: a cancelled entry (0) moves straight on, a rejected name (2) shows
 * the "invalid name" message and a valid name shows the completion message for
 * the entry's mode (the two message ids at gOv001NameEntryConfig+8/+0xC). */
void Ov001_HandleNameEntryResult(void) {
    s32 Ov001_IsMenuActive();
    void Ov001_GetNameEntryMode(s32 *, s32);
    M2C_UNK Ov001_ShowMessage(s32, s32, s32, s32, s32);
    extern void *gOv001NameEntryConfig;
    extern void *gNameEntryState;
    extern M2C_UNK Ov001_CloseNameEntryScreen;
    extern M2C_UNK Ov001_HandleNameEntryRegionChoice;
    extern M2C_UNK Ov001_RetryNameEntry;
    s32 modeMessages[2];
    s32 mode;
    u8 result;

    modeMessages[0] = M2C_FIELD(&gOv001NameEntryConfig, s32 *, 8);
    modeMessages[1] = M2C_FIELD(&gOv001NameEntryConfig, s32 *, 0xC);
    if (Ov001_IsMenuActive() != 0) return;
    result = M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_RESULT);
    if (result == 0) {
        Ov001_SetStepCallback(&Ov001_CloseNameEntryScreen);
        return;
    }
    if (result == 2) {
        Ov001_ShowMessage(6, 3, 1, -1, 0);
        Ov001_SetStepCallback(&Ov001_RetryNameEntry);
        return;
    }
    Ov001_GetNameEntryMode(0, &mode);
    Ov001_ShowMessage(modeMessages[mode], 2, 1, -1, 0);
    Ov001_SetStepCallback(&Ov001_HandleNameEntryRegionChoice);
}

#pragma merge_constants off
/* Leave the name-entry screen once its keyboard and messages are done: free its
 * background, cursor sprite and page, load the main OBJ palette and hide the
 * planes, then pick the next screen from the saved entry mode and the entry's
 * result - the map list for the no-argument mode, the map-select list after a
 * cancelled entry, or the save-slot menu after an accepted name. */
void Ov001_CloseNameEntryScreen(void) {
    M2C_UNK Ov001_FreeMessagePanel(void);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    M2C_UNK Ov001_ReleaseSprite(M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    void Ov001_DisableVisiblePlanes(s32, s32);
    void Ov001_GetNameEntryMode(s32 *, s32);
    void Ov001_SetNextScreenMode(s32, s32);
    void Ov001_SetNameEntryMode(s32, s32);
    s32 Ov001_SetStepCallback(s32 *);
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern void *gNameEntryState;
    extern s32 data_ov001_02193d9c;
    extern void *gOv001ObjMainPalettePath;
    extern void GX_LoadOBJPltt(void);
    extern void InitMapListScreen(void);
    extern void MapSelectList_Init(void);
    extern void Ov001_PrepareSaveSlotMenu(void);
    s32 entryMode, entryArg;

    Ov001_FreeMessagePanel();
    Ov001_ReleaseSprite(M2C_FIELD(gNameEntryState, void **, NAME_ENTRY_CURSOR));
    Ov001_FreePageBackground(0);
    Ov001_LoadAsset((M2C_UNK *)&gOv001ObjMainPalettePath, (M2C_UNK *)&GX_LoadOBJPltt);
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    Ov001_GetNameEntryMode(&entryMode, (s32)&entryArg);
    if (entryArg == 0) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetNameEntryMode(0, entryMode);
        Ov001_SetStepCallback((s32 *)InitMapListScreen);
    } else {
        if (M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_RESULT) == 0) {
            Ov001_SetNextScreenMode(0, 1);
            Ov001_SetNameEntryMode(1, 0);
            Ov001_SetStepCallback((s32 *)MapSelectList_Init);
        } else {
            Ov001_SetNextScreenMode(0, 0);
            Ov001_SetNameEntryMode(0, 1);
            Ov001_SetStepCallback((s32 *)Ov001_PrepareSaveSlotMenu);
        }
    }
    Ov001_FreeAlloc(&data_ov001_02193d9c + 1);
}
#pragma merge_constants reset
/* Draws the entered name on the name-entry panel: one glyph per character in
 * two rows of 16, substituting a dash for spaces, then closes the panel. */
void RedrawNameEntryText(void) {
extern void *gNameEntryState; extern u8 gNameEntryColumnX[];
void TextPanel_ClearText(s32,s32);void DrawPanelText(s32,s32,s32,s32,s32,s32,s32,void *);void CloseTextPanel(s32);
u16 glyphs[6]; u16 *rect; s32 column,i; u8 c;
rect=&glyphs[2];rect[1]=0;rect[2]=0;rect[3]=0;rect[0]=0;
glyphs[3]=32;glyphs[4]=14;glyphs[5]=16;
TextPanel_ClearText(M2C_FIELD(gNameEntryState,s32 *,NAME_ENTRY_PANEL),0);
i=0;column=i;glyphs[1]=i;
do {
if(i==16){column=0;glyphs[3]=49;}
c=M2C_FIELD((u8 *)gNameEntryState+i,u8 *,NAME_ENTRY_TEXT);
if(c==32)glyphs[0]=0xe01d;else glyphs[0]=c;
glyphs[2]=gNameEntryColumnX[column];
DrawPanelText(M2C_FIELD(gNameEntryState,s32 *,NAME_ENTRY_PANEL),glyphs[2],glyphs[3],glyphs[4],glyphs[5],2,0x480,glyphs);
i++;column++;
}while(i<32);
CloseTextPanel(M2C_FIELD(gNameEntryState,s32 *,NAME_ENTRY_PANEL));
}

/* Places the name-entry cursor under the next free character: the text column is
   the character count's low nibble and the row its high nibble, clamped to the
   last cell of the second row once all 32 characters are used. */
void UpdateNameEntryCursor(void) {
    extern void *gNameEntryState;
    extern u8 gNameEntryRowY[];
    extern u8 gNameEntryColumnX[];
    void *obj;
    s32 *cursor;
    u8 length;
    s32 column, row;

    obj = gNameEntryState;
    length = M2C_FIELD(obj, u8 *, NAME_ENTRY_LENGTH);
    cursor = M2C_FIELD(obj, s32 **, NAME_ENTRY_CURSOR);
    column = length & 0xF;
    row = length >> 4;
    if (length >= NAME_ENTRY_MAX_LENGTH) {
        row = 1;
        column = 0xF;
    }
    *cursor = (*cursor & NAME_ENTRY_CURSOR_POS_MASK) | gNameEntryRowY[row] | ((u32)gNameEntryColumnX[column] << 0x17 >> 7);
}

/* Handles the region menu's answer on the name-entry screen: stores the selected
   region into the entry's result byte, plays the cancel sound (0) or accept
   sound (1), then closes the menu and moves on to finish name entry.  A rejected
   choice leaves the menu open. */
void Ov001_HandleNameEntryRegionChoice(void) {
    extern void *gNameEntryState;
    extern M2C_UNK Ov001_FinishNameEntry;
    M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_RESULT) = Ov001_GetRegionMenuSelection();
    switch (M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_RESULT)) {
    case 0: Ov001_PlaySound(7); break;
    case 1: Ov001_PlaySound(0xE); break;
    default: return;
    }
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_FinishNameEntry);
}

/* Final name-entry step, run once the region menu has been answered: waits for
   the menu to close, then either clears the cursor of a cancelled entry and
   resumes the entry screen (result 0) or passes the entered text to that entry
   mode's accept handler and leaves the screen. */
void Ov001_FinishNameEntry(void) {
    s32 Ov001_IsRegionMenuActive(void);
    s32 Ov001_SetStepCallback(s32 *);
    void Ov001_GetNameEntryMode(s32 *, s32);
    void Ov001_OpenNameEntryKeyboard(void);
    void Ov001_CloseNameEntryScreen(void);
    extern void *gOv001NameEntryConfig;
    extern void *gNameEntryState;

    void *acceptHandlers[2];
    s32 mode;

    acceptHandlers[0] = M2C_FIELD(&gOv001NameEntryConfig, void **, NAME_ENTRY_CONFIG_ACCEPT);
    acceptHandlers[1] = M2C_FIELD(&gOv001NameEntryConfig, void **, NAME_ENTRY_CONFIG_ACCEPT + 4);

    if (Ov001_IsRegionMenuActive()) return;
    if (M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_RESULT) == 0) {
        s32 *cursor = M2C_FIELD(gNameEntryState, s32 **, NAME_ENTRY_CURSOR);
        *cursor &= NAME_ENTRY_CURSOR_MASK;
        Ov001_SetStepCallback((s32 *)Ov001_OpenNameEntryKeyboard);
        return;
    }
    Ov001_GetNameEntryMode(&mode, 0);
    ((void (*)(void *))acceptHandlers[mode])((u8 *)gNameEntryState + NAME_ENTRY_TEXT);
    Ov001_SetStepCallback((s32 *)Ov001_CloseNameEntryScreen);
}

