/* 9 functions from 0x0216FC60 to 0x021707D8 (ov000), found by ds-decomp. */
#include "common.h"
#include "sound.h"
#include "ds3dsprite.h"

extern u8 gScrollListTabDesc0[40];
extern u8 gScrollListTabDesc1[40];
extern u8 gScrollListTabDesc2[40];
extern u8 gScrollListTabDesc3[40];
extern u8 gScrollListRowDesc[40];

/* Handle a click on one of the unit list's four tab buttons: the button's slot
 * id (SCROLL_LIST_TAB_ID) selects the tab, then the list is rebuilt for it and
 * its tabs and rows are redrawn. */
void ScrollListSelectTab(u8 *selectedButton) {
    void *GetScrollList(void);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK ScrollListRebuild(s16, s16);
    M2C_UNK ScrollListDrawRows(s16);
    M2C_UNK ScrollListDrawTabs(void *);
    ScrollList *list = GetScrollList();
    if (list == NULL) return;
    switch (*selectedButton) {
    case SCROLL_LIST_TAB_ID(0): list->tab = 0; break;
    case SCROLL_LIST_TAB_ID(1): list->tab = 1; break;
    case SCROLL_LIST_TAB_ID(2): list->tab = 2; break;
    case SCROLL_LIST_TAB_ID(3): list->tab = 3; break;
    default: return;
    }
    PlaySoundEffect(SOUND_MENU_TAB);
    ScrollListRebuild(list->tab, list->reverse);
    ScrollListDrawTabs(list);
    ScrollListDrawRows(list->animPos);
}

void ScrollListNavigate(u8 *selection) {
    void *GetScrollList(void);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK ScrollListRebuild(s16, s16);
    M2C_UNK ScrollListDrawRows(s16);
    M2C_UNK ScrollListDrawTabs(void *);
    s32 FindSpriteSlotById(s32);
    void *FocusSpriteSlotById(s32);
    s32 ScrollListScrollUp(void *);
    s16 ScrollListPageUp(void *);
    s32 ScrollListScrollDown(void *);
    s16 ScrollListPageDown(void *);
    void ScrollListConfirm(u8 *);
    M2C_UNK ScrollListCancel(s32);
    extern KeyState *gKeyState;
    ScrollList *list;
    s16 itemCount;
    s32 selected;
    s32 maxScroll;
    s16 scrollPos;
    s16 delta;

    /* Navigate the unit-list menu: d-pad scrolls, L/R change tab, Select/Start flips sort, A/B confirm/cancel. */
    list = (ScrollList *) GetScrollList();
    itemCount = list->count;
    selected = *selection;
    maxScroll = itemCount - 6;
    if (maxScroll < 0) maxScroll = 0;
    if (itemCount <= 1) goto done;
    scrollPos = list->scrollPos;
    if (scrollPos == 0 && selected == 0) {
        if (gKeyState->pressed & KEY_UP) {
            PlaySoundEffect(0x10019);
            list->scrollPos = maxScroll;
            if (list->scrollPos == 0) selected = list->count - 1;
            else selected = 5;
            goto done;
        }
    } else if (gKeyState->repeat & KEY_UP) {
        if (selected >= 2) selected--;
        else if (!ScrollListScrollUp(list)) {
            if (selected > 0) selected--;
        }
        goto done;
    }
    if (scrollPos == maxScroll && ((maxScroll > 0 && selected == 5) || (maxScroll == 0 && selected == itemCount - 1))) {
        if (gKeyState->pressed & KEY_DOWN) {
            PlaySoundEffect(0x10019);
            selected = 0;
            list->scrollPos = selected;
            goto done;
        }
    } else if (gKeyState->repeat & KEY_DOWN) {
        if (selected < 4) {
            if (FindSpriteSlotById(selected + 1)) selected++;
        } else {
            if (!ScrollListScrollDown(list) && FindSpriteSlotById(selected + 1)) selected++;
        }
        goto done;
    }
    if (gKeyState->repeat & KEY_LEFT) {
        if (maxScroll > 0) {
            delta = ScrollListPageUp(list);
            selected -= delta + 6;
            if (selected < 0) selected = 0;
            if (delta != 0 && selected == *selection) PlaySoundEffect(0x10019);
        } else {
            selected = 0;
        }
        goto done;
    }
    if (gKeyState->repeat & KEY_RIGHT) {
        if (maxScroll > 0) {
            delta = ScrollListPageDown(list);
            selected += 6 - delta;
            if (selected >= 6) selected = 5;
            if (delta != 0 && selected == *selection) PlaySoundEffect(0x10019);
        } else {
            selected = itemCount - 1;
        }
    }
done:
    if (selected != *selection) selection = (u8 *) FocusSpriteSlotById(selected);
    if (gKeyState->repeat & KEY_L) {
        if (list->tab == 0) list->tab = 3;
        else list->tab = list->tab - 1;
        PlaySoundEffect(0x10020);
        ScrollListRebuild(list->tab, list->reverse);
        ScrollListDrawTabs(list);
        ScrollListDrawRows(list->animPos);
    }
    if (gKeyState->repeat & KEY_R) {
        if (list->tab == 3) list->tab = 0;
        else list->tab = list->tab + 1;
        PlaySoundEffect(0x10020);
        ScrollListRebuild(list->tab, list->reverse);
        ScrollListDrawTabs(list);
        ScrollListDrawRows(list->animPos);
    }
    if (gKeyState->pressed & (KEY_SELECT | KEY_START)) {
        list->reverse = list->reverse + 1;
        list->reverse = list->reverse & 1;
        PlaySoundEffect(0x10019);
        ScrollListRebuild(list->tab, list->reverse);
        ScrollListDrawRows(list->animPos);
    }
    if (gKeyState->pressed & KEY_A) {
        ScrollListConfirm(selection);
        return;
    }
    if (gKeyState->pressed & KEY_B) {
        ScrollListCancel(0);
    }
}

void func_ov000_0217000c(void) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(0x10019);
}

/* Create the unit list's four tab buttons and a highlight button for every visible
 * row (at most six), then select the first row. */
void ScrollListCreateButtons(void) {
    void *GetScrollList(void);
    M2C_UNK SetSpriteSlotFrameRect(s32,s32,s32,s32);
    M2C_UNK SelectSpriteSlot(s32);
    M2C_UNK AddSpriteSlot(s32,s32,void *,s32);
    ScrollList *list;
    s32 row;
    s32 y;

    list = (ScrollList *) GetScrollList();
    SetSpriteSlotFrameRect(0, -16, 256, -16);
    AddSpriteSlot(0, 0, &gScrollListTabDesc0, SCROLL_LIST_TAB_ID(0));
    AddSpriteSlot(0, 0, &gScrollListTabDesc1, SCROLL_LIST_TAB_ID(1));
    AddSpriteSlot(0, 0, &gScrollListTabDesc2, SCROLL_LIST_TAB_ID(2));
    AddSpriteSlot(0, 0, &gScrollListTabDesc3, SCROLL_LIST_TAB_ID(3));
    row = 0;
    if (list->count > 0) {
        y = SCROLL_LIST_ROW_Y;
    loop:
        if (row != SCROLL_LIST_VISIBLE_ROWS) {
            AddSpriteSlot(SCROLL_LIST_ROW_X, y, &gScrollListRowDesc, row);
            row++;
            y += SCROLL_LIST_ROW_STEP;
            if (row < list->count) goto loop;
        }
    }
    SelectSpriteSlot(0);
}

void *GetScrollList(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gScrollListClass;
    return FindObjectByClass(&gScrollListClass);
}

#pragma push
#pragma opt_propagation off
#pragma opt_scheduling off
void func_ov000_02170110(void *arg0) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK CopyToObjPaletteShadow(s32, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy32(s32, s32, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadFileToAddress(M2C_UNK *, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK Load3DSpritePattern(s32, M2C_UNK, s32, M2C_UNK);
    M2C_UNK ResetTextTiles(M2C_UNK);
    M2C_UNK DrawTextToTilemap(M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    M2C_UNK DrawTilemapNumber(M2C_UNK, M2C_UNK, s32, s16, s32, s32);
    s32 GetArmyStateLabel(u8);
    s32 GetUiColor(M2C_UNK);
    M2C_UNK CreateMenuUnitSprite(void *);
    M2C_UNK CreateMenuTextSprite(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, void *, s32);
    s32 GetLocalizedFileName(M2C_UNK *);
    s32 HeapAllocBlock(M2C_UNK);
    s32 GetArmyStateTiles(u8);
    s32 GetArmyIconPalette(u8);
    s16 CountCurrentPlayerUnits();
    M2C_UNK ScrollListRebuild(s16, s16);
    M2C_UNK ScrollListDrawRows(s16);
    M2C_UNK ScrollListDrawTabs(void *);
    void ScrollListCreateButtons();
    extern void *gCurrentMap;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern M2C_UNK data_ov000_021b8b2c;
    extern M2C_UNK data_ov000_021b8b3c;
    extern M2C_UNK data_ov000_021b8b4c;
    extern M2C_UNK data_ov000_021b8b58;
    extern M2C_UNK data_ov000_021b8b64;
    extern M2C_UNK data_ov000_021b8b78;
    extern M2C_UNK gUnitListRows;
    void *p;
    void *q;
    void *r;
    s32 s;
    s32 index;
    s32 zero;
    M2C_UNK (*t)();

    p = gCurrentMap;
    q = M2C_FIELD(p, void **, 0);
    r = gCur3DSpriteEngine;
    index = M2C_FIELD(q, u16 *, 0x52A4);
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    s = (index * 0x8C) + (s32) (q + 0x67A4);
    t = M2C_FIELD(M2C_FIELD(p, void **, 4), M2C_UNK (**)(), 0x54);
    if (t != NULL) {
        t();
    }
    ResetTextTiles(0);
    M2C_FIELD(&gUnitListRows, s32 *, 4) = HeapAllocBlock(0x40);
    M2C_FIELD(arg0, s16 *, 0x3C) = CountCurrentPlayerUnits();
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x3A) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s16 *, 0x40) = 0;
    ScrollListRebuild(M2C_FIELD(arg0, s16 *, 0x34), M2C_FIELD(arg0, s16 *, 0x36));
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    zero=0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = zero;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 1;
    SetFileDirectory(&data_ov000_021b8b2c);
    GetLocalizedFileName(&data_ov000_021b8b3c);
    OpenNarcArchive();
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8b4c), M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x14));
    CloseNarcArchive();
    LoadFileToSpriteBuffer(&data_ov000_021b8b58, 0xC0, 0x20);
    ScrollListDrawTabs(arg0);
    CreateMenuTextSprite(arg0 + 0x44, 0x5E, 0x8B, 0xA, 0x39C, 3, -1, arg0, 1);
    CreateMenuTextSprite(arg0 + 0x48, 0x82, 0x8B, 0xB, 0x3A4, 3, -1, arg0, zero);
    CreateMenuUnitSprite(arg0);
    LoadFileToAddress(&data_ov000_021b8b64, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x1C) + 0x7780);
    LoadFileToSpriteBuffer(&data_ov000_021b8b78, 0x380, 0x20);
    p = (void *) (M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x1C) + 0x3880);
    MI_CpuCopy32(GetArmyStateTiles(M2C_FIELD(s, u8 *, 0x27)), (s32) p + 0x4000, 0x80);
    CopyToObjPaletteShadow(GetArmyIconPalette(M2C_FIELD(s, u8 *, 0x1D)), 0x3A0, 0x20);
    Load3DSpritePattern(0x6B80, 0xB, GetUiColor(0xC), 2);
    DrawTextToTilemap(5, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), GetArmyStateLabel(M2C_FIELD(s, u8 *, 0x27)), 0, 0);
    DrawTilemapNumber(0x1A, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x3C), 0, 0);
    ScrollListDrawRows(M2C_FIELD(arg0, s16 *, 0x38));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    ScrollListCreateButtons();
    gCur3DSpriteEngine = r;
}
#pragma pop
void func_ov000_021703e8(void *arg0) {
    void AddSprite(s32, s32, u16, void *, s32);
    M2C_UNK MenuSpriteUpdate(void *);
    s32 FX_Div(s32, s32);
    void DrawFrameBorder(s32, s32, s32, s32, u16, s32, s32);
    M2C_UNK ScrollListDrawRows(s16);
    M2C_UNK ScrollListScrollUp(void *);
    M2C_UNK ScrollListScrollDown(void *);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern M2C_UNK gSpriteDesc16x16;
    extern M2C_UNK gSpriteDesc32x16;
    void *spr;
    void *p;
    void *old;
    u32 cond;
    s16 a;
    s16 b;
    s16 step;
    s32 diff;
    s32 v1;
    s32 v2;
    s32 t1;
    s32 t2;
    s32 t3;

    if (M2C_FIELD(arg0, s16 *, 0x3e) == 0) {
        a = M2C_FIELD(arg0, s16 *, 0x3a);
        b = M2C_FIELD(arg0, s16 *, 0x38);
        if (b != (a << 1)) {
            diff = (a << 1) - b;
            if (diff < 0) diff = -diff;
            step = (s16) (diff >> 1);
            if (step == 0) step = 1;
            if (b > (a << 1)) {
                M2C_FIELD(arg0, s16 *, 0x38) -= step;
            } else {
                M2C_FIELD(arg0, s16 *, 0x38) += step;
            }
            M2C_FIELD(arg0, s16 *, 0x3e) = 1;
            ScrollListDrawRows(M2C_FIELD(arg0, s16 *, 0x38));
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x3e) = 0;
    }

    spr = M2C_FIELD(arg0, void **, 0x44);
    if (M2C_FIELD(arg0, s16 *, 0x3a) == 0) {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) + 2) << 24) >> 6);
    } else {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((u32) (u16) ((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) << 24) >> 6);
    }
    M2C_FIELD(spr, u8 *, 0x5a) = 0;

    spr = M2C_FIELD(arg0, void **, 0x48);
    if (M2C_FIELD(arg0, s16 *, 0x3a) >= (M2C_FIELD(arg0, s16 *, 0x3c) - 6)) {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) + 2) << 24) >> 6);
    } else {
        M2C_FIELD(spr, u32 *, 0x40) = (M2C_FIELD(spr, u32 *, 0x40) & ~0x03fc0000)
            | (((u32) (u16) ((u32) (M2C_FIELD(spr, u8 *, 0x59) << 28) >> 28) << 24) >> 6);
    }
    M2C_FIELD(spr, u8 *, 0x5a) = 0;

    MenuSpriteUpdate(M2C_FIELD(arg0, void **, 0x44));
    MenuSpriteUpdate(M2C_FIELD(arg0, void **, 0x48));

    spr = M2C_FIELD(arg0, void **, 0x44);
    p = M2C_FIELD(spr, void **, 0x64);
    cond = 1;
    if (M2C_FIELD(p, s8 *, 0xb) != 1
        && (!((u32) (M2C_FIELD(spr, u8 *, 0x59) << 27) >> 31) || M2C_FIELD(p, s8 *, 0xc) != 1)) {
        cond = 0;
    }
    if (cond & 255) ScrollListScrollUp(arg0);

    spr = M2C_FIELD(arg0, void **, 0x48);
    p = M2C_FIELD(spr, void **, 0x64);
    cond = 1;
    if (M2C_FIELD(p, s8 *, 0xb) != 1
        && (!((u32) (M2C_FIELD(spr, u8 *, 0x59) << 27) >> 31) || M2C_FIELD(p, s8 *, 0xc) != 1)) {
        cond = 0;
    }
    if (cond & 255) ScrollListScrollDown(arg0);

    old = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    v1 = M2C_FIELD(arg0, s16 *, 0x3c) << 12;
    v2 = M2C_FIELD(arg0, s16 *, 0x3a) << 12;
    t1 = FX_Div(0x62000, v1);
    t1 = (s32) (((s64) t1 * 0x6000 + 0x800) >> 12);
    t2 = FX_Div(0x62000 - t1, v1 - 0x6000);
    t2 = (s32) (((s64) t2 * v2 + 0x800) >> 12);
    t3 = t1 >> 12;
    if (t3 > 0x62) t3 = 0x62;
    else if (t3 < 1) t3 = 1;
    DrawFrameBorder(0xf8, (s16) ((t2 >> 12) + 0x28), 2, (s16) t3,
                  (u16) (0xb000 | ((0x35c >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30)) & 0x3ff)),
                  0, 2);
    AddSprite(0x16, 7,
                  (u16) (0xd000 | ((0x3c4 >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30)) & 0x3ff)),
                  &gSpriteDesc16x16, 0);
    AddSprite(0xaa, 0x8b,
                  (u16) (0xc000 | ((0x3bc >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30)) & 0x3ff)),
                  &gSpriteDesc32x16, 0);
    gCur3DSpriteEngine = old;
}

#pragma opt_common_subs off
/* Close the unit-list menu: free its sorted row buffer, clear the two 3D sprite
 * layers it used, mark them dirty and redraw the map view. */
void ScrollListClose(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK RefreshMapView();
    M2C_UNK HeapFreeBlock(s32);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gUnitListRows;
    void *savedEngine;
    void *mainEngine;
    s32 rowsBuffer;

    savedEngine = gCur3DSpriteEngine;
    mainEngine = *(void *volatile *)&g3DSpriteEngineMain;
    rowsBuffer = M2C_FIELD(&gUnitListRows, s32 *, UNIT_LIST_ROWS_PTR);
    gCur3DSpriteEngine = mainEngine;
    HeapFreeBlock(rowsBuffer);
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER1;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
    RefreshMapView();
    gCur3DSpriteEngine = savedEngine;
}
#pragma opt_common_subs reset
/* Open the unit-list menu: its class takes a hold on the map view, builds and
 * draws the list, scrolls it while open, and on close releases the hold and steps
 * the cursor to the selected unit. */
void ScrollListOpen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gScrollListClass;
    CreateSpriteFromClass(&gScrollListClass, DS3D_SPRITE_DEFAULT_LAYER);
}

