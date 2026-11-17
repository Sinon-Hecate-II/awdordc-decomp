/* 27 functions from 0x02180B68 to 0x02181A84 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "wfc.h"
typedef struct { u8 bytes[22]; } PathBuffer80;
extern u8 gOv001Step11PalettePath[];
extern u16 data_ov001_0218f9ea[], data_ov001_0218f9ec[];
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
    M2C_UNK func_ov001_02171694();
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_LeaveFriendList;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    func_ov001_02171694();
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
    s32 func_ov001_021840d4();
    void *GetCurrentMapRecord();
    M2C_UNK func_ov001_02184880(u8);
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

    } while (func_ov001_021840d4() == 0);
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    Ov001_FreeOptionBackground();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001FriendListState != OV001_FRIEND_LIST_AVAILABLE) {
        func_ov001_02183fa0();
        func_ov001_02184880(M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xF4));
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
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_02180d24;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
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
    void func_ov001_02180eb4(void);
    void Ov001_UpdateMenuCursor(void);
    void func_ov001_02180fbc(void);
    void func_ov001_02172250(s32);
    void Ov001_ShowMessagePanel(s32, s32, s32);
    void func_ov001_02171dd0(s32);
    extern M2C_UNK gOv001MenuRegion;
    void *temp_r0;
    temp_r0 = Ov001_Alloc(0x20, 4);
    M2C_FIELD(&gOv001MenuRegion, void **, 4) = temp_r0;
    M2C_FIELD(temp_r0, u8 *, 0x1D) = 0;
    Ov001_LoadAccessPointMenuGraphics();
    func_ov001_02172250(1);
    Ov001_ShowMessagePanel(0x2F, -1, 0);
    func_ov001_02171dd0(0);
    func_ov001_02180eb4();
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

void func_ov001_02180eb4(void) {
    s32 Ov001_GetSaveSlotStatus(void);
    M2C_UNK Ov001_CreateSprite(M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_MoveSpriteLayout(s32, s32, u16, u16);
    void Ov001_SetSpritePalette(s32, s32, s32);
    extern M2C_UNK gOv001MenuRegion;
    extern u16 data_ov001_0218f9ea[];
    extern u8 data_ov001_0218f9c8[];
    s32 i;
    M2C_UNK idx;
    M2C_UNK handle;

    i = 0;
    while (i < 3) {
        idx = Ov001_GetSaveSlotStatus();
        if (idx == 0xff) {
            idx = 3;
            goto second;
        }
        handle = Ov001_CreateSprite(0, 0x11, 1);
        M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, M2C_UNK *, 0x10) = handle;
        Ov001_MoveSpriteLayout(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x10),
            -1,
            data_ov001_0218f9ea[(i + 3) * 2],
            data_ov001_0218f9ea[(i + 3) * 2 + 1]);
        Ov001_SetSpritePalette(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x10),
            -1, 3);

second:
        handle = Ov001_CreateSprite(0, data_ov001_0218f9c8[idx], 1);
        M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, M2C_UNK *, 0x4) = handle;
        Ov001_MoveSpriteLayout(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x4),
            -1,
            data_ov001_0218f9ea[i * 2],
            data_ov001_0218f9ea[i * 2 + 1]);
        Ov001_SetSpritePalette(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x4),
            -1, 3);

        i = i + 1;
    }
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
M2C_UNK func_ov001_02184880(u8);
void func_ov001_02181794(void),Ov001_ShowRegionIcon(void),func_ov001_021812c0(void);
extern s8 data_ov001_0218fa74[];
extern M2C_UNK func_ov001_02176578,func_ov001_02181824;
u8 region;
s32 record, languageFrame;
switch(Ov001_GetIconRowSelection()) {
case 0:
switch(Ov001_GetScreenLayout()) {
case 0: Ov001_PlaySound(7); M2C_FIELD(M2C_FIELD(&gOv001MenuRegion,void **,4),u8 *,0x1d)=2; break;
case 1: Ov001_LockIconRow(); Ov001_SetStepCallback(&func_ov001_02176578); return;
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
func_ov001_02181794();Ov001_LockIconRow();Ov001_SetStepCallback(&func_ov001_02181824);return;
}
if(region<=2)func_ov001_02184880(region);
Ov001_PlaySound(6);Ov001_ShowRegionIcon();
done:
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021812c0);
break;
}
}

void func_ov001_021812c0(void) {
    M2C_UNK func_ov001_0218560c();
    extern M2C_UNK gOv001MenuRegion;
    extern M2C_UNK func_ov001_021812fc;
    if (M2C_FIELD(M2C_FIELD(&gOv001MenuRegion, void **, 4), u8 *, 0x1D) == 2) {
        func_ov001_0218560c();
    }
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021812fc);
}

void func_ov001_021812fc(void) {
    M2C_UNK func_ov001_02171694();
    void *GetCurrentMapRecord();
    extern M2C_UNK gOv001MenuRegion;
    extern M2C_UNK Ov001_FinishRegionMenu;
    if (Ov001_IsFadeActive(1) != 0) return;
    if (M2C_FIELD(M2C_FIELD(&gOv001MenuRegion, void **, 4), u8 *, 0x1D) == 1 &&
        (M2C_FIELD(&gOv001MenuRegion, u8 *, 0) == 3 ||
         M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xE7) != 0xFF)) {
        func_ov001_02171694();
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
s32 Ov001_IsFadeActive(s32);s32 func_ov001_02185b34(void);s32 Ov001_IsIconRowIdle(void);void *GetCurrentMapRecord(void);
void Ov001_DestroySprite(s32);
u32 i;s32 p;
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
if(!func_ov001_02185b34())return;
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
void Ov001_UpdateMenuCursor(void) {
    void Ov001_LayoutChoiceFrameRow(s32, u16, u16, u16);
    void Ov001_LayoutChoiceFrame(u16, u16, u16, u16);
    extern M2C_UNK gOv001MenuRegion;
    extern u16 data_ov001_0218fa3a[];
    extern u16 data_ov001_0218fa3c[];
    extern u16 data_ov001_0218fa3e[];
    extern u16 data_ov001_0218fa40[];
    s32 temp_ip;
    s32 temp_r3;
    if ((u32)M2C_FIELD(&gOv001MenuRegion, u8 *, 0) < 4U) {
        temp_ip = M2C_FIELD(&gOv001MenuRegion, u8 *, 0) * 4;
        Ov001_LayoutChoiceFrame(data_ov001_0218fa3a[temp_ip], data_ov001_0218fa3e[temp_ip], data_ov001_0218fa3c[temp_ip], data_ov001_0218fa40[temp_ip]);
        return;
    }
    temp_r3 = M2C_FIELD(&gOv001MenuRegion, u8 *, 0) * 4;
    Ov001_LayoutChoiceFrameRow(0, data_ov001_0218fa3a[temp_r3], data_ov001_0218fa3e[temp_r3], data_ov001_0218fa3c[temp_r3]);
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

void func_ov001_02181794(void) {
    s32 Ov001_GetSpriteObjEntry(s32, s32);
    void Ov001_MoveSpriteLayout(s32, s32, u16, u16);
    void Ov001_SetSpritePalette(s32, s32, s32);
    void Ov001_LoadSpriteObjLayout(s32, s32, s32);
    extern M2C_UNK gOv001MenuRegion;
    extern u16 data_ov001_0218f9ea[];
    extern u16 data_ov001_0218f9ec[];
    s32 temp_r3;
    s32 temp_r4;
    temp_r4 = M2C_FIELD(&gOv001MenuRegion, u8 *, 0) - 4;
    Ov001_LoadSpriteObjLayout(0, 0x32, Ov001_GetSpriteObjEntry(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + temp_r4 * 4, s32 *, 0x10), 0));
    temp_r3 = (temp_r4 + 3) * 2;
    Ov001_MoveSpriteLayout(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + temp_r4 * 4, s32 *, 0x10), -1, data_ov001_0218f9ea[temp_r3], data_ov001_0218f9ec[temp_r3]);
    Ov001_SetSpritePalette(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + temp_r4 * 4, s32 *, 0x10), -1, 3);
}

void func_ov001_02181824(void) {
s32 func_ov001_02186648(void);
M2C_UNK Ov001_PlaySound(s32);
void func_ov001_02184c70(s32);
s32 Ov001_GetSpriteObjEntry(s32,s32);
void Ov001_LoadSpriteObjLayout(s32,s32,s32);
void Ov001_MoveSpriteLayout(s32,s32,u16,u16);
void Ov001_SetSpritePalette(s32,s32,s32);
void Ov001_DestroySprite(s32);
M2C_UNK func_ov001_02186604();
void func_ov001_02181990(void);
register s32 i=M2C_FIELD(&gOv001MenuRegion,u8 *,0)-4;
switch(func_ov001_02186648()) {
case 1:
Ov001_PlaySound(14);
func_ov001_02184c70(i);
Ov001_LoadSpriteObjLayout(0,86,Ov001_GetSpriteObjEntry(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,4),0));
Ov001_MoveSpriteLayout(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,4),-1,data_ov001_0218f9ea[i*2],data_ov001_0218f9ec[i*2]);
Ov001_SetSpritePalette(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,4),-1,3);
Ov001_DestroySprite(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16));
M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16)=0;
break;
case 0:
Ov001_PlaySound(7);
Ov001_LoadSpriteObjLayout(0,17,Ov001_GetSpriteObjEntry(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16),0));
Ov001_MoveSpriteLayout(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16),-1,data_ov001_0218f9ea[(i+3)*2],data_ov001_0218f9ec[(i+3)*2]);
Ov001_SetSpritePalette(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16),-1,3);
break;
default:return;
}
func_ov001_02186604();
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

