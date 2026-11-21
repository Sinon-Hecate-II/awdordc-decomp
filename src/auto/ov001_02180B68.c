/* 27 functions from 0x02180B68 to 0x02181A84 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "wfc.h"
typedef struct { u8 bytes[22]; } PathBuffer80;
extern u8 gOv001Step11PalettePath[];
extern u16 sOv001MenuSpriteX[], sOv001MenuSpriteY[];
extern M2C_UNK gOv001WayObjPalettePath, gOv001Step1TilesPath, gOv001Step1PalettePath, gOv001AccessPointTilemapPath;
extern M2C_UNK gOv001MenuRegion;
extern M2C_UNK GX_LoadOBJPltt, GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

void func_ov001_02180b68(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(2) == 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_02180b8c(void) {

}

void func_ov001_02180b90(void) {
    s32 Ov001_GetIconRowSelection(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    void func_ov001_02180bbc(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_StopSound();
    Ov001_PlaySound(7);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180bbc);
}

void func_ov001_02180bbc(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02180bdc;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02180bdc);
}

void func_ov001_02180bdc(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_LeaveFriendList;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_LeaveFriendList);
}

/* Final step of the ov001 Wi-Fi friend-list screen: after the closing fade, the
 * icon row and the WFC roster request have settled, it tears the screen down and
 * hands over to the friend map list when a friend can be picked, or back to the
 * Wi-Fi mode menu otherwise. */
void Ov001_LeaveFriendList(void) {
    M2C_UNK Ov001_FreeOptionSprites();
    s32 Ov001_IsIconRowIdle();
    M2C_UNK Ov001_FreeOptionBackground();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNameEntryMode(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02183fa0();
    s32 Ov001_CloseFriendRoster();
    void *GetCurrentMapRecord();
    M2C_UNK LoadSaveSlot(u8);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001FriendListState;
    extern M2C_UNK MapSelectList_Init;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    if (Ov001_IsIconRowIdle() == 0) {
        return;
    }
    do {

    } while (Ov001_CloseFriendRoster() == 0);
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    Ov001_FreeOptionBackground();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001FriendListState != OV001_FRIEND_LIST_AVAILABLE) {
        func_ov001_02183fa0();
        LoadSaveSlot(M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xF4));
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&func_ov001_02181a84);
        return;
    }
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetNameEntryMode(0, 0);
    Ov001_SetStepCallback(&MapSelectList_Init);
}

void func_ov001_02180cf8(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK func_ov001_02180d24;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&func_ov001_02180d24);
}

void func_ov001_02180d24(void) {
    s32 Ov001_IsRegionMenuActive();
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180bbc);
}

void Ov001_OpenAccessPointMenu(void) {
    void *Ov001_Alloc(s32, s32);
    void Ov001_LoadAccessPointMenuGraphics(void);
    void Ov001_InitSaveSlotSprites(void);
    void Ov001_UpdateMenuCursor(void);
    void func_ov001_02180fbc(void);
    void Ov001_LoadObjLayoutBlock(s32);
    void Ov001_ShowMessagePanel(s32, s32, s32);
    void Ov001_OpenMenuForMode(s32);
    extern M2C_UNK gOv001MenuRegion;
    void *temp_r0;
    temp_r0 = Ov001_Alloc(0x20, 4);
    M2C_FIELD(&gOv001MenuRegion, void **, 4) = temp_r0;
    M2C_FIELD(temp_r0, u8 *, 0x1D) = 0;
    Ov001_LoadAccessPointMenuGraphics();
    Ov001_LoadObjLayoutBlock(1);
    Ov001_ShowMessagePanel(0x2F, -1, 0);
    Ov001_OpenMenuForMode(0);
    Ov001_InitSaveSlotSprites();
    Ov001_UpdateMenuCursor();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180fbc);
}

/* Load the access-point menu palettes, tiles and tilemap, and set its background priorities. */
void Ov001_LoadAccessPointMenuGraphics(void) {
    s32 Ov001_LocalizePath(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    s32 Ov001_LoadFile(s32, M2C_UNK, M2C_UNK);
    void Ov001_EnableVisiblePlanes(s32, s32);
    PathBuffer80 palettePath = *(PathBuffer80 *)gOv001Step11PalettePath;
    Ov001_LoadAsset(&gOv001WayObjPalettePath, &GX_LoadOBJPltt);
    Ov001_LoadAsset(&gOv001Step1TilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001Step1PalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001AccessPointTilemapPath, &GX_LoadBG2Scr);
    *M2C_FIELD(&gOv001MenuRegion, s32 **, 4) = Ov001_LoadFile(Ov001_LocalizePath(&palettePath), 0, 4);
    Ov001_EnableVisiblePlanes(1, 16);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

/* Create the ov001 menu's save-slot sprites: for each of the three slots the
 * status icon of its top-row item (the empty-slot icon when the slot is erased)
 * and, for a written slot, the item sprite of its middle-row cell. */
void Ov001_InitSaveSlotSprites(void) {
    s32 Ov001_GetSaveSlotStatus(s32);
    s32 Ov001_CreateSprite(s32, s32, s32);
    void Ov001_MoveSpriteLayout(s32, s32, u16, u16);
    void Ov001_SetSpritePalette(s32, s32, s32);
    extern u8 sOv001SaveSlotIconIds[];
    typedef struct { u16 x, y; } SpritePos;
    s32 screen;
    s32 status;
    s32 slot;
    s32 emptyIcon;
    s32 layout;
    s32 pos;

    slot = 0;
    screen = slot;
    layout = -1;
    emptyIcon = 3;
    do {
        status = Ov001_GetSaveSlotStatus(slot);
        if (status == 0xff) {
            status = emptyIcon;
        } else {
            s32 sprite = Ov001_CreateSprite(screen, 0x11, 1);
            pos = slot + 3;
            ((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot] = (void *)sprite;
            Ov001_MoveSpriteLayout((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot],
                                   layout, ((const SpritePos *)sOv001MenuSpriteX)[pos].x,
                                   ((const SpritePos *)sOv001MenuSpriteX)[pos].y);
            Ov001_SetSpritePalette((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot], layout, 3);
        }
        {
            s32 sprite = Ov001_CreateSprite(0, sOv001SaveSlotIconIds[status], 1);
            ((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->top[slot] = (void *)sprite;
            Ov001_MoveSpriteLayout((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->top[slot],
                                   layout, ((const SpritePos *)sOv001MenuSpriteX)[slot].x,
                                   ((const SpritePos *)sOv001MenuSpriteX)[slot].y);
            Ov001_SetSpritePalette((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->top[slot], layout, 3);
        }
        slot++;
    } while (slot < 3);
}

void func_ov001_02180fbc(void) {
    extern M2C_UNK func_ov001_02181010;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x14, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x14);
    Ov001_SetStepCallback(&func_ov001_02181010);
}

void func_ov001_02181010(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    void func_ov001_0218104c(void);
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0218104c);
}

void func_ov001_0218104c(void) {
    s32 Ov001_GetIconRowSelection(void);
    s32 func_ov001_02185714(void);
    M2C_UNK Ov001_UnlockIconRow();
    void func_ov001_02181080(void);
    if (Ov001_GetIconRowSelection() == -2) return;
    if (func_ov001_02185714() == 1) return;
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02181080);
}

void func_ov001_02181080(void) {
    void func_ov001_02181094(void);
    void func_ov001_02181188(void);
    void Ov001_HandleRegionMenuChoice(void);
    func_ov001_02181094();
    func_ov001_02181188();
    Ov001_HandleRegionMenuChoice();
}

/* Scan the seven candidate regions; activate the first matching one, otherwise handle button fallbacks. */
void func_ov001_02181094(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    void Ov001_UpdateMenuCursor(void);
    s32 KeyPressed(s32);
    void Ov001_MoveMenuRegion(s32);
    s32 KeyHeld(s32);
    s32 TouchRectPressed(void *);
    extern u8 data_ov001_0218fa02[];
    extern M2C_UNK gOv001MenuRegion;
    u32 index;
    u8 *entry;
    entry = data_ov001_0218fa02;
    for (index = 0; index < 7; index++, entry += 8) {
        if (TouchRectPressed(entry) != 0) {
            Ov001_LatchIconRowSelection(1);
            M2C_FIELD(&gOv001MenuRegion, u8 *, 0) = index;
            Ov001_UpdateMenuCursor();
            return;
        }
    }
    if (KeyPressed(1) != 0) {
        Ov001_LatchIconRowSelection(1);
        return;
    }
    if (KeyPressed(2) != 0) {
        Ov001_LatchIconRowSelection(0);
        return;
    }
    if (KeyHeld(0x40) != 0) {
        Ov001_MoveMenuRegion(1);
        return;
    }
    if (KeyHeld(0x80) != 0) {
        Ov001_MoveMenuRegion(3);
        return;
    }
    if (KeyHeld(0x20) != 0) {
        Ov001_MoveMenuRegion(0);
        return;
    }
    if (KeyHeld(0x10) == 0) return;
    Ov001_MoveMenuRegion(2);
}

void func_ov001_02181188(void) {

}

/* Acts on the ov001 icon row's selection on the region menu: the left bar goes
 * back (or advances the layout-dependent step), the right bar confirms the
 * highlighted region, opening its map list or starting a new game when full. */
void Ov001_HandleRegionMenuChoice(void) {
s32 Ov001_GetIconRowSelection(void),Ov001_GetScreenLayout(void),Ov001_GetLanguage(void);
s32 Ov001_GetSaveSlotStatus();
M2C_UNK Ov001_PlaySound(s32),Ov001_SetIconRowSelection(s32),Ov001_LockIconRow(void);
M2C_UNK Ov001_ShowMessage(s32,s32,s32,s32,s32);
M2C_UNK LoadSaveSlot(u8);
void Ov001_ShowSelectedSaveSlot(void),Ov001_ShowRegionIcon(void),func_ov001_021812c0(void);
extern s8 data_ov001_0218fa74[];
extern M2C_UNK Ov001_FadeToShutdownScreen,Ov001_HandleEraseSaveSlotChoice;
u8 region;
s32 record, languageFrame;
switch(Ov001_GetIconRowSelection()) {
case 0:
switch(Ov001_GetScreenLayout()) {
case 0: Ov001_PlaySound(7); M2C_FIELD(M2C_FIELD(&gOv001MenuRegion,void **,4),u8 *,0x1d)=2; break;
case 1: Ov001_LockIconRow(); Ov001_SetStepCallback(&Ov001_FadeToShutdownScreen); return;
} goto done;
case 1:
M2C_FIELD(M2C_FIELD(&gOv001MenuRegion,void **,4),u8 *,0x1d)=1;
region=M2C_FIELD(&gOv001MenuRegion,u8 *,0);
if(region>=4) {
record=region-4;
if(Ov001_GetSaveSlotStatus(record)==255) {Ov001_PlaySound(9);Ov001_SetIconRowSelection(-1);return;}
Ov001_PlaySound(6);
languageFrame = data_ov001_0218fa74[Ov001_GetLanguage()];
Ov001_ShowMessage(70,0,1,languageFrame,record+1);
Ov001_ShowSelectedSaveSlot();Ov001_LockIconRow();Ov001_SetStepCallback(&Ov001_HandleEraseSaveSlotChoice);return;
}
if(region<=2)LoadSaveSlot(region);
Ov001_PlaySound(6);Ov001_ShowRegionIcon();
done:
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021812c0);
break;
}
}

void func_ov001_021812c0(void) {
    M2C_UNK func_ov001_0218560c();
    extern M2C_UNK gOv001MenuRegion;
    extern M2C_UNK Ov001_FadeOutRegionMenu;
    if (M2C_FIELD(M2C_FIELD(&gOv001MenuRegion, void **, 4), u8 *, 0x1D) == 2) {
        func_ov001_0218560c();
    }
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeOutRegionMenu);
}

/* Fade the ov001 region menu out and hand over to its teardown step; when the
 * chosen region has an entry to open, the icon row slides out first. */
void Ov001_FadeOutRegionMenu(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    void *GetCurrentMapRecord();
    extern M2C_UNK gOv001MenuRegion;
    extern M2C_UNK Ov001_FinishRegionMenu;
    if (Ov001_IsFadeActive(1) != 0) return;
    if (((Ov001MenuRegion *) &gOv001MenuRegion)->sprites->mode == 1 &&
        (((Ov001MenuRegion *) &gOv001MenuRegion)->index == 3 ||
         M2C_FIELD(GetCurrentMapRecord(), u8 *, SAVE_SLOT_STATUS_REL) != 0xFF)) {
        Ov001_StartIconRowSlideOut();
    }
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x14, 8);
    Ov001_SetStepCallback(&Ov001_FinishRegionMenu);
}

#pragma opt_strength_reduction off
/* Last step of the region-menu screen: release the item sprites and the region
 * selector, load the map-list assets, and hand over to the next screen's step
 * callback (map list or layout screen, depending on the chosen region). */
void Ov001_FinishRegionMenu(void){
extern M2C_UNK data_ov001_021909f4,data_ov001_02193dd0;
extern M2C_UNK Ov001_OpenWifiMenu,func_ov001_02181a84,InitMapListScreen,func_ov001_02182d0c;
s32 Ov001_IsFadeActive(s32);s32 Ov001_IsMenuLayoutReady(void);s32 Ov001_IsIconRowIdle(void);void *GetCurrentMapRecord(void);
void Ov001_DestroySprite(s32);
u32 i;s32 p;
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
if(!Ov001_IsMenuLayoutReady())return;
if(!Ov001_IsIconRowIdle())return;
for(i=0;i<3;i++){p=(s32)((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->top[i];if(p)Ov001_DestroySprite(p);}
for(i=0;i<3;i++){p=(s32)((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->middle[i];if(p)Ov001_DestroySprite(p);}
Ov001_FreeSpriteObjects();Ov001_FreeOptionBackground();
Ov001_FreeFile(((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->obj);
Ov001_LoadAsset(&data_ov001_021909f4,&GX_LoadOBJPltt);
Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,20);
if(((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->mode==2){
Ov001_SetNextScreenMode(0,0);Ov001_SetStepCallback(&Ov001_OpenWifiMenu);
}else switch(((Ov001MenuRegion*)&gOv001MenuRegion)->index){
case 0:case 1:case 2:
Ov001_SetNextScreenMode(2,0);
if(M2C_FIELD(GetCurrentMapRecord(),u8 *,0xe7)==255)Ov001_SetStepCallback(&func_ov001_02181a84);
else{Ov001_SetNameEntryMode(0,0);SetMapListMode(0);Ov001_SetStepCallback(&InitMapListScreen);}break;
case 3:Ov001_SetNextScreenMode(2,1);Ov001_SetStepCallback(&func_ov001_02182d0c);break;
}
Ov001_FreeAlloc(&data_ov001_02193dd0);
}
/* Redraw the selection frame around the ov001 menu's chosen region: regions 0..2
 * take their frame edges (left, right, top, bottom) from the menu frame tables,
 * while the wide bottom bar (region 3) uses a two-sprite row frame. */
void Ov001_UpdateMenuCursor(void) {
    void Ov001_LayoutChoiceFrameRow(s32, u16, u16, u16);
    void Ov001_LayoutChoiceFrame(u16, u16, u16, u16);
    extern u16 gOv001MenuFrameLeft[];
    extern u16 gOv001MenuFrameTop[];
    extern u16 gOv001MenuFrameRight[];
    extern u16 gOv001MenuFrameBottom[];
    s32 frameOffset;
    s32 rowOffset;

    if ((u32)((Ov001MenuRegion *)&gOv001MenuRegion)->index < 4U) {
        frameOffset = ((Ov001MenuRegion *)&gOv001MenuRegion)->index * 4;
        Ov001_LayoutChoiceFrame(gOv001MenuFrameLeft[frameOffset], gOv001MenuFrameRight[frameOffset],
            gOv001MenuFrameTop[frameOffset], gOv001MenuFrameBottom[frameOffset]);
        return;
    }
    rowOffset = ((Ov001MenuRegion *)&gOv001MenuRegion)->index * 4;
    Ov001_LayoutChoiceFrameRow(0, gOv001MenuFrameLeft[rowOffset], gOv001MenuFrameRight[rowOffset],
        gOv001MenuFrameTop[rowOffset]);
}

/* Moves the selection around the ov001 menu screen's seven touch regions by
   one direction (two rows of three item sprites plus the wide bar below them).
   Left/right wrap within a row; up/down cross between rows through the bar.
   Plays a sound and moves the cursor sprite when the selection changed. */
void Ov001_MoveMenuRegion(s32 direction) {
extern M2C_UNK gOv001MenuRegion;
s32 changed = 1;
switch (((Ov001MenuRegion *)&gOv001MenuRegion)->index) {
case 0:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=0;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=2; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=1; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=4; break;
case 1:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=1;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=0; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=2; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=5; break;
case 2:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=2;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=1; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=0; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=6; break;
case 3:
{u8 column = ((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column; s32 next=column+4; if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=next; else if(direction==OV001_DIR_DOWN) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=column; else changed=0;} break;
case 4:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=0;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=6; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=5; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=0; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; break;
case 5:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=1;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=4; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=6; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=1; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; break;
case 6:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=2;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=5; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=4; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=2; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; break;
} if(changed){Ov001_PlaySound(8);Ov001_UpdateMenuCursor();}}

/* Show the selected save slot (region 4..6, slot 0..2) as chosen: load the
 * chosen layout of its middle-row sprite, place it on the slot row and give it
 * palette 3. */
void Ov001_ShowSelectedSaveSlot(void) {
    s32 Ov001_GetSpriteObjEntry(s32, s32);
    void Ov001_MoveSpriteLayout(s32, s32, u16, u16);
    void Ov001_SetSpritePalette(s32, s32, s32);
    void Ov001_LoadSpriteObjLayout(s32, s32, s32);
    extern M2C_UNK gOv001MenuRegion;
    extern u16 sOv001MenuSpriteX[];
    extern u16 sOv001MenuSpriteY[];
    s32 slot;
    s32 pos;
    slot = M2C_FIELD(&gOv001MenuRegion, u8 *, 0) - 4;
    Ov001_LoadSpriteObjLayout(0, 0x32, Ov001_GetSpriteObjEntry(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + slot * 4, s32 *, 0x10), 0));
    pos = (slot + 3) * 2;
    Ov001_MoveSpriteLayout(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + slot * 4, s32 *, 0x10), -1, sOv001MenuSpriteX[pos], sOv001MenuSpriteY[pos]);
    Ov001_SetSpritePalette(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + slot * 4, s32 *, 0x10), -1, 3);
}

/* Handle the erase-save-slot dialog's answer for the save slot under the menu
 * cursor (region 4..6): yes (1) erases the slot and shows its empty top-row
 * icon in place of the middle-row one; no (0) restores the middle-row icon.
 * Any other answer leaves the menu open. */
void Ov001_HandleEraseSaveSlotChoice(void) {
s32 Ov001_GetRegionMenuSelection(void);
M2C_UNK Ov001_PlaySound(s32);
void Ov001_EraseSaveSlot(s32);
s32 Ov001_GetSpriteObjEntry(s32,s32);
void Ov001_LoadSpriteObjLayout(s32,s32,s32);
void Ov001_MoveSpriteLayout(s32,s32,u16,u16);
void Ov001_SetSpritePalette(s32,s32,s32);
void Ov001_DestroySprite(s32);
M2C_UNK Ov001_CloseRegionMenu();
void func_ov001_02181990(void);
register s32 slot=((Ov001MenuRegion *)&gOv001MenuRegion)->index-4;
switch(Ov001_GetRegionMenuSelection()) {
case 1:
Ov001_PlaySound(14);
Ov001_EraseSaveSlot(slot);
Ov001_LoadSpriteObjLayout(0,86,Ov001_GetSpriteObjEntry((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->top[slot],0));
Ov001_MoveSpriteLayout((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->top[slot],-1,((const u16 (*)[2])sOv001MenuSpriteX)[slot][0],((const u16 (*)[2])sOv001MenuSpriteY)[slot][0]);
Ov001_SetSpritePalette((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->top[slot],-1,3);
Ov001_DestroySprite((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot]);
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot]=0;
break;
case 0:
Ov001_PlaySound(7);
Ov001_LoadSpriteObjLayout(0,17,Ov001_GetSpriteObjEntry((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot],0));
Ov001_MoveSpriteLayout((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot],-1,((const u16 (*)[2])sOv001MenuSpriteX)[(slot+3)][0],((const u16 (*)[2])sOv001MenuSpriteY)[(slot+3)][0]);
Ov001_SetSpritePalette((s32)((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->middle[slot],-1,3);
break;
default:return;
}
Ov001_CloseRegionMenu();
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02181990);
}

void func_ov001_02181990(void) {
    M2C_UNK Ov001_UnlockIconRow();
    void func_ov001_02181080(void);
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02181080);
}

/* Show the highlighted region's icon: upload that region's tile from the loaded
 * menu graphics into OBJ VRAM, then give the region's item sprite the palette
 * that matches its save-slot status (an empty or invalid slot uses the last
 * palette).  Regions 4..6 have no icon here. */
void Ov001_ShowRegionIcon(void) {
void Ov001_LoadObjTile(s32,u8,u8);s32 Ov001_GetSaveSlotStatus();void Ov001_SetSpriteAttrs(s32,s32,s32,u8);
extern u8 sOv001RegionIconTable[];extern M2C_UNK gOv001MenuRegion;
u8 iconTiles[4]={sOv001RegionIconTable[0],sOv001RegionIconTable[1],sOv001RegionIconTable[2],sOv001RegionIconTable[3]};
u8 statusPalettes[4]={sOv001RegionIconTable[4],sOv001RegionIconTable[5],sOv001RegionIconTable[6],sOv001RegionIconTable[7]};s32 palette;u8 tile;u8 *tiles=iconTiles;
if(((Ov001MenuRegion *)&gOv001MenuRegion)->index>3)return;
tile=tiles[((Ov001MenuRegion *)&gOv001MenuRegion)->index];
Ov001_LoadObjTile(M2C_FIELD(M2C_FIELD(&gOv001MenuRegion,void **,4),s32 *,0),tile,tile);
if(((Ov001MenuRegion *)&gOv001MenuRegion)->index==3)return;
palette=Ov001_GetSaveSlotStatus();if(palette>2)palette=3;
Ov001_SetSpriteAttrs(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion,void **,4)+((Ov001MenuRegion *)&gOv001MenuRegion)->index*4,s32 *,4),-1,0,statusPalettes[palette]);
}

