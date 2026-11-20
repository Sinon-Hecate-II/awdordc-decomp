/* 37 functions from 0x0217EB6C to 0x0217FB68 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
typedef struct { u8 bytes[4]; } FourBytes;
typedef struct { u8 bytes[14]; } FourteenBytes;
typedef struct { u16 a,b,c,d; } FourShorts;

#pragma scheduling on
s32 GetMapListTouchedEntry(void){
 s32 TouchRectPressed(void *);s32 func_ov001_0218bd1c(FourShorts *);
 s32 HardwareDivide(u16,s32);
 extern M2C_UNK gTouchScreenRect,gMapListState;
 extern FourBytes gOv001MapListLayout;
 extern u8 gMapListRowToState[],data_ov001_0218f952[];
 FourShorts rect; s32 value,i,j,k;u8 *p;
 if(!TouchRectPressed(&gTouchScreenRect))return 14;
 value=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+4);
 for(i=0;i<4;i++,value++){
 if(value!=2 && value!=6){if(func_ov001_0218bd1c(&rect))return gMapListRowToState[value];}
 rect.b+=29;
 }
 value=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);
 for(j=0;j<4;j++,value++){
 if(value==2){
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+20);
 rect.b+=j*29;
 if(func_ov001_0218bd1c(&rect))return 2;
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+12);
 rect.b+=j*29;
 if(func_ov001_0218bd1c(&rect))return 3;
 break;
 }
 }
 value=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);
 for(k=0;k<4;k++,value++){
 if(value==6){
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+20);
 rect.b+=k*29;
 if(func_ov001_0218bd1c(&rect))return 7;
 rect=*(FourShorts *)((u8 *)&gOv001MapListLayout+12);
 rect.b+=k*29;
 if(func_ov001_0218bd1c(&rect))return 8;
 break;
 }
 }
 p=data_ov001_0218f952;
 for(i=0;i<3;i++,p+=8){if(TouchRectPressed(p))return i+11;}
 return 14;
}
#pragma scheduling reset
s32 func_ov001_0217ede0(s32 arg0) {
    s32 HardwareDivide(u16, s32);
    extern M2C_UNK gMapListState;
    s32 value;
    s32 i;
    value = HardwareDivide(M2C_FIELD(&gMapListState, u16 *, 4), 0x1D);
    for (i = 0; i < 4; i++, value++) {
        if (value == arg0) return i;
    }
    return -1;
}

s32 func_ov001_0217ee24(s32 arg0) {
    s32 HardwareDivide(u16, s32);
    extern M2C_UNK gMapListState;
    s32 result;
    result = HardwareDivide(M2C_FIELD(&gMapListState, u16 *, 4), 0x1D);
    result += arg0;
    return result;
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

void func_ov001_0217efb4(void){s32 HardwareDivide(u16,s32);s32 HardwareDivideRemainder(u16,s32);extern M2C_UNK gMapListState;extern volatile u8 data_ov001_0218f9b0[];s32 i,x;u32 y; if(!M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,0x44))return;i=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);x=HardwareDivideRemainder(M2C_FIELD(&gMapListState,u16 *,4),29)-51;y=data_ov001_0218f9b0[i];*(volatile u32 *)0x04000010=(x<<16)&0x1ff0000;*(volatile u32 *)0x04000018=((x+y)<<16)&0x1ff0000;M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,0x44)=0;}

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

void SelectMapListChoice(u32 a){void MapList_ApplyRowLayout(void);extern M2C_UNK gMapListState;extern u8 data_ov001_0218f9bc[];M2C_FIELD(&gMapListState,u8 *,0)=a;M2C_FIELD(&gMapListState,u8 *,2)=func_ov001_0217ede0(data_ov001_0218f9bc[a]);MapList_ApplyRowLayout();}

void func_ov001_0217f1f0(s32 event) {
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

void func_ov001_0217f4e0(void){void Ov001_LoadObjTile(s32,u8,u8);extern M2C_UNK gMapListState;extern u8 data_ov001_0218f8c0[];u8 v=data_ov001_0218f8c0[M2C_FIELD(&gMapListState,u8 *,0)-11];Ov001_LoadObjTile(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,16),v,v);}

void func_ov001_0217f514(void){extern M2C_UNK gMapListState;M2C_UNK MapListRedrawInfoPanel();s32 i=0;do{u8 *p=(u8 *)M2C_FIELD(&gMapListState,void **,8)+i;if(p[4]){p[4]--;if(!M2C_FIELD((u8 *)M2C_FIELD(&gMapListState,void **,8)+i,u8 *,4))MapListRedrawInfoPanel();}i++;}while(i<4);}

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
    s32 func_0204612c(void *);
    s32 func_020460b0(void *, void *);
    u8 *record = GetCurrentMapRecord();

    if (!record[SAVE_SLOT_MAP_NAME]) return 0;
    if (!record[SAVE_SLOT_EMPTY_B] &&
        !func_0204612c(record + SAVE_SLOT_PLAYER_CODES + 8) &&
        !func_0204612c(record + SAVE_SLOT_PLAYER_CODES + 12)) return 0;
    if (!record[SAVE_SLOT_EMPTY_A]) {
        if (!func_0204612c(record + SAVE_SLOT_PLAYER_CODES)) return 0;
        if (!func_0204612c(record + SAVE_SLOT_PLAYER_CODES + 4)) return 0;
        if (!func_020460b0(record + SAVE_SLOT_PLAYER_CODES, record + SAVE_SLOT_CODE)) return 0;
    }
    return 1;
}

void func_ov001_0217f6cc(void){s32 func_ov001_02186648(void);M2C_UNK Ov001_PlaySound(s32);M2C_UNK func_ov001_02186604();M2C_UNK func_ov001_0218384c(s32);extern M2C_UNK gMapListState;extern M2C_UNK func_ov001_0217f70c;if(func_ov001_02186648())return;Ov001_PlaySound(6);func_ov001_02186604();func_ov001_0218384c(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,12));Ov001_SetStepCallback(&func_ov001_0217f70c);}

void func_ov001_0217f70c(void) {
    s32 Ov001_IsRegionMenuActive();
    extern M2C_UNK func_ov001_0217d744;
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_0217d744);
}

void SetMapListMode(s8 arg0) {
    extern M2C_UNK gMapListState;
    M2C_FIELD(&gMapListState, s8 *, 1) = arg0;
}

void func_ov001_0217f73c(void) {
    M2C_UNK Ov001_LoadSaveSlotObjLayout();
    void MapList_LoadBackground();
    M2C_UNK CommitSaveSlot();
    extern M2C_UNK func_ov001_0217f7f0;
    MapList_LoadBackground();
    Ov001_LoadSaveSlotObjLayout();
    CommitSaveSlot();
    Ov001_SetStepCallback(&func_ov001_0217f7f0);
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

void func_ov001_0217f7f0(void) {
    extern M2C_UNK func_ov001_0217f844;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x14, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x14);
    Ov001_SetStepCallback(&func_ov001_0217f844);
}

void func_ov001_0217f844(void) {
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK func_ov001_0217f894;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_ShowMessage(0x44, 5, 1, -1, 0);
    Ov001_SetStepCallback(&func_ov001_0217f894);
}

void func_ov001_0217f894(void){s32 Ov001_IsRegionMenuActive(void);void func_ov001_0217f8bc(void);void func_ov001_0217f8c0(void);void func_ov001_0217f8c4(void);func_ov001_0217f8bc();func_ov001_0217f8c0();if(Ov001_IsRegionMenuActive())return;Ov001_SetStepCallback(func_ov001_0217f8c4);}

void func_ov001_0217f8bc(void) {

}

void func_ov001_0217f8c0(void) {

}

void func_ov001_0217f8c4(void) {
    extern M2C_UNK func_ov001_0217f900;
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x14, 8);
    Ov001_SetStepCallback(&func_ov001_0217f900);
}

void func_ov001_0217f900(void) {
    M2C_UNK Ov001_FreeOptionBackground();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_FreeOptionBackground();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x14);
    Ov001_SetNextScreenMode(2, 1);
    Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);
}

s32 func_ov001_0217f95c(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_0217f97c(void){void func_ov001_0217f9b8(void);void func_ov001_0217fa38(void);M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);M2C_UNK Ov001_ShowMessageBox(M2C_UNK);M2C_UNK Ov001_LoadSaveSlotObjLayout(void);extern M2C_UNK gOv001OptionExitToConnection;M2C_FIELD(&gOv001OptionExitToConnection,u8 *,0)=0;func_ov001_0217f9b8();Ov001_LoadSaveSlotObjLayout();Ov001_ShowMessageBox(0x25);Ov001_CreateAnimSprite(1);Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217fa38);}

void func_ov001_0217f9b8(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_021908d8;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_021908d8, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_0217fa38(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217fa6c;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_0217fa6c);
}

void func_ov001_0217fa6c(void) {
    void func_ov001_0217fa98(void);
    if (Ov001_IsFadeActive(0) != 0) return;
    func_ov001_02171e20(1);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217fa98);
}

void func_ov001_0217fa98(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_0217fac0;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_0217fac0);
}

void func_ov001_0217fac0(void) {
    M2C_UNK SleepMilliseconds(s32);
    M2C_UNK Ov001_HandleOptionPage1Choice();
    void func_ov001_0217fae0(void);
    void func_ov001_0217fb18(void);
    void func_ov001_0217fb1c(void);
    SleepMilliseconds(10);
    Ov001_HandleOptionPage1Choice();
    func_ov001_0217fae0();
    func_ov001_0217fb18();
    func_ov001_0217fb1c();
}

void func_ov001_0217fae0(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(2) != 0) {
        Ov001_LatchIconRowSelection(0);
        return;
    }
    if (func_ov001_0217f95c() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_0217fb18(void) {

}

void func_ov001_0217fb1c(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK func_ov001_0217fb48;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(7);
    Ov001_SetStepCallback(&func_ov001_0217fb48);
}

void func_ov001_0217fb48(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217fb68;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217fb68);
}

