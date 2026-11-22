/* 53 functions from 0x0217FB68 to 0x02180B68 (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
#include "gx.h"

/* First step of leaving the ov001 option screen: once the sub-screen fade has
 * finished, slide the icon row out (unless the menu is exiting to the
 * connection screen), fade the option screen out and hand over to
 * Ov001_CloseOptionScreen. */
void Ov001_BeginOptionScreenExit(void) {
    extern u8 gOv001OptionExitToConnection;
    extern M2C_UNK Ov001_CloseOptionScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (gOv001OptionExitToConnection == 0) {
        Ov001_StartIconRowSlideOut();
    }
    if (gOv001OptionExitToConnection == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseOptionScreen);
}

/* Step callback that runs once the option menu's fade-out and the icon-row
 * animation have finished: it tears down the option screen and opens either the
 * friend-list screen (mode 2) or the connection screen (mode 0), according to
 * gOv001OptionExitToConnection. */
void Ov001_CloseOptionScreen(void) {
    M2C_UNK Ov001_FreeOptionSprites(void);
    s32 Ov001_IsIconRowIdle(void);
    M2C_UNK Ov001_FreeOptionBackground(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreeOptionPage(void);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001OptionExitToConnection;
    extern M2C_UNK func_ov001_0217fd94;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((gOv001OptionExitToConnection == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001OptionExitToConnection == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001OptionExitToConnection == 0) {
        Ov001_FreeOptionPage();
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&func_ov001_02181a84);
        return;
    }
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetStepCallback(&func_ov001_0217fd94);
}

/* Handle a choice on the ov001 option menu's first page: the second menu item
 * records that the menu exits to the connection screen, while leaving records
 * the friend list and shows the cancel message. */
void Ov001_HandleOptionPage1Choice(void) {
    s32 Ov001_GetOptionChoice(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound(void);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 gOv001OptionExitToConnection;
    extern M2C_UNK func_ov001_0217fb48;
    void func_ov001_0217fd28(void);
    switch (Ov001_GetOptionChoice()) {
    case 2:
        gOv001OptionExitToConnection = 1;
        Ov001_SetStepCallback(&func_ov001_0217fb48);
        return;
    case 4:
        gOv001OptionExitToConnection = 0;
        Ov001_StopSound();
        Ov001_PlaySound(9);
        Ov001_ShowMessage(0xD, 1, 1, -1, 0);
        Ov001_LockIconRow();
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217fd28);
        return;
    }
}

void func_ov001_0217fd28(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK func_ov001_0217fd54;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&func_ov001_0217fd54);
}

void func_ov001_0217fd54(void) {
    s32 Ov001_IsRegionMenuActive();
    extern M2C_UNK func_ov001_0217fb48;
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_0217fb48);
}

s32 func_ov001_0217fd74(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_0217fd94(void) {
    M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
    void Ov001_LoadXb4MultiBackground(void);
    void func_ov001_0217fe50(void);
    extern u8 gOv001MatchSetupStored;
    gOv001MatchSetupStored = 0;
    Ov001_LoadXb4MultiBackground();
    Ov001_LoadSaveSlotObjLayout();
    Ov001_ShowMessageBox(0x2A);
    Ov001_CreateAnimSprite(2);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217fe50);
}

/* Load the "xb4Multi" background screen map and give the main and sub background
 * planes the lowest priority so the screen's sprites and text draw over it. */
void Ov001_LoadXb4MultiBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001Xb4MultiBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001Xb4MultiBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

void func_ov001_0217fe50(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217fe84;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_0217fe84);
}

void func_ov001_0217fe84(void) {
    void func_ov001_0217feb0(void);
    if (Ov001_IsFadeActive(0) != 0) return;
    func_ov001_02171e20(1);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217feb0);
}

void func_ov001_0217feb0(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_0217fed8;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_0217fed8);
}

void func_ov001_0217fed8(void) {
    M2C_UNK SleepMilliseconds(s32);
    void Ov001_HandleMatchSetupPage2Choice(void);
    void func_ov001_0217fef8(void);
    void func_ov001_0217ff30(void);
    void func_ov001_0217ff34(void);
    SleepMilliseconds(10);
    Ov001_HandleMatchSetupPage2Choice();
    func_ov001_0217fef8();
    func_ov001_0217ff30();
    func_ov001_0217ff34();
}

void func_ov001_0217fef8(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(2) != 0) {
        Ov001_LatchIconRowSelection(0);
        return;
    }
    if (func_ov001_0217fd74() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_0217ff30(void) {

}

void func_ov001_0217ff34(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK func_ov001_0217ff60;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(7);
    Ov001_SetStepCallback(&func_ov001_0217ff60);
}

void func_ov001_0217ff60(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutMatchSetup;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&Ov001_FadeOutMatchSetup);
}

/* Fade the match-setup page out: once the sub-screen fade is idle, slide the icon
 * row out, fade both screens to white - the sub-screen fade only when the edited
 * setup was not stored - then hand over to Ov001_CloseMatchSetupScreen. */
void Ov001_FadeOutMatchSetup(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern u8 gOv001MatchSetupStored;
    extern M2C_UNK Ov001_CloseMatchSetupScreen;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    if (gOv001MatchSetupStored == 0) {
        Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_CloseMatchSetupScreen);
}

/* Step callback that runs once the match-setup option page's fades and the
   icon-row animation have finished: it releases the page's sprites and
   background, then opens either the download-play screen (mode 2) when the
   branch flag is clear, or advances the match setup (mode 0) when it is set. */
void Ov001_CloseMatchSetupScreen(void) {
    M2C_UNK Ov001_FreeOptionSprites(void);
    s32 Ov001_IsIconRowIdle(void);
    M2C_UNK Ov001_FreeOptionBackground(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreeOptionPage(void);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001MatchSetupStored;
    extern M2C_UNK Ov001_AdvanceMatchSetup;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((gOv001MatchSetupStored == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001MatchSetupStored == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_FreeOptionPage();
    if (gOv001MatchSetupStored == 0) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&func_ov001_02181a84);
        return;
    }
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetStepCallback(&Ov001_AdvanceMatchSetup);
}

/* Second page of the ov001 download-play setup wizard: on selection 3 it stores
 * the edited match setup (Ov001_StoreMatchSetup) and advances; on selection 4 or
 * 5 it cancels - stop the sound, play the cancel sound, show the matching message
 * and lock the icon row. gOv001MatchSetupStored records the branch for the fade-out
 * that follows. */
void Ov001_HandleMatchSetupPage2Choice(void) {
s32 Ov001_GetOptionChoice(void); M2C_UNK Ov001_PlaySound(M2C_UNK); M2C_UNK Ov001_StopSound(void); M2C_UNK Ov001_StoreMatchSetup(void); M2C_UNK Ov001_ShowMessage(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32); M2C_UNK Ov001_LockIconRow(void);
extern u8 gOv001MatchSetupStored; void func_ov001_0217ff60(void); void func_ov001_02180178(void);
switch(Ov001_GetOptionChoice()){
case 3: gOv001MatchSetupStored=1;Ov001_StopSound();Ov001_StoreMatchSetup();Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217ff60);return;
case 4: gOv001MatchSetupStored=0;Ov001_StopSound();Ov001_PlaySound(9);Ov001_ShowMessage(13,1,1,-1,0);Ov001_LockIconRow();Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180178);return;
case 5: gOv001MatchSetupStored=0;Ov001_StopSound();Ov001_PlaySound(18);Ov001_ShowMessage(14,1,1,-1,0);Ov001_LockIconRow();Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180178);return;
}}

void func_ov001_02180178(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK func_ov001_021801a4;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&func_ov001_021801a4);
}

void func_ov001_021801a4(void) {
    s32 Ov001_IsRegionMenuActive();
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217ff60);
}

void Ov001_AdvanceMatchSetup(void) {
M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
M2C_UNK Ov001_PlaySound(M2C_UNK);
void Ov001_LoadMatchSetupBackground(void);
void func_ov001_02180280(void);
extern s8 data_ov001_02193dc0;
data_ov001_02193dc0=0;
Ov001_LoadMatchSetupBackground();
Ov001_LoadSaveSlotObjLayout();
Ov001_ShowMessageBox(0x26);
Ov001_PlaySound(0x10);
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180280);
}

/* Loads the background map of the match-setup advance screen and gives the
 * main and sub background planes the lowest priority. */
void Ov001_LoadMatchSetupBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001MatchSetupBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001MatchSetupBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

void func_ov001_02180280(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021802b4;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_021802b4);
}

void func_ov001_021802b4(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK func_ov001_021802d8;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_021802d8);
}

void func_ov001_021802d8(void) {
    void func_ov001_021802e8(void);
    void func_ov001_02180398(void);
    func_ov001_02180398();
    func_ov001_021802e8();
}

void func_ov001_021802e8(void) {

}

void func_ov001_021802ec(void) {
    extern M2C_UNK Ov001_CloseMatchSetupForSave;
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseMatchSetupForSave);
}

/* Waits for both fades, clears the match setup display, and opens the save slot menu. */
void Ov001_CloseMatchSetupForSave(void) {
    M2C_UNK Ov001_FreeOptionBackground(void);
    M2C_UNK Ov001_SetNextScreenMode(s32, s32);
    void Ov001_SetNameEntryMode(s32, s32);
    M2C_UNK Ov001_FreePageBackground(s32);
    M2C_UNK Ov001_DisableVisiblePlanes(s32, s32);
    void Ov001_PrepareSaveSlotMenu(void);

    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_FreePageBackground(0);
    Ov001_FreeOptionBackground();
    Ov001_DisableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_DisableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetNameEntryMode(0, 1);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_PrepareSaveSlotMenu);
}

void func_ov001_02180398(void) {
    extern s8 data_ov001_02193dc0;
    void func_ov001_021802ec(void);
    M2C_FIELD(&data_ov001_02193dc0,u8 *,0) = M2C_FIELD(&data_ov001_02193dc0,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&data_ov001_02193dc0,u8 *,0) < 120U) return;
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021802ec);
}

s32 func_ov001_021803cc(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

/* Open the ov001 option screen's second page: clear its exit flag, load the
 * page background and the save-slot object layout, fill in the text and menu,
 * and hand over to the fade-in. */
void Ov001_OpenOptionPage2(void) {
extern u8 gOv001OptionPage2ExitToConnection;
void Ov001_FadeInOptionPage2(void);
void Ov001_LoadOptionPageBg(void);
M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
M2C_UNK Ov001_ShowMessagePanel(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK Ov001_OpenMenuForMode(M2C_UNK);
M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
M2C_UNK Ov001_PlaySound(M2C_UNK);
gOv001OptionPage2ExitToConnection=0;
Ov001_LoadOptionPageBg();
Ov001_LoadSaveSlotObjLayout();
Ov001_ShowMessagePanel(0x37,-1,0);
Ov001_OpenMenuForMode(2);
Ov001_ShowMessageBox(0x24);
Ov001_CreateAnimSprite(0);
Ov001_PlaySound(0xb);
Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInOptionPage2);
}

/* Loads the ov001 option-page screen's background: tile graphics, palette and
 * map, then puts BG0/BG1 on the lowest priority. */
void Ov001_LoadOptionPageBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001OptionPageBgTilesPath, gOv001OptionPageBgPalettePath, gOv001OptionPageBgMapPath;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001OptionPageBgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001OptionPageBgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001OptionPageBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

void Ov001_FadeInOptionPage2(void) {
    extern M2C_UNK Ov001_OptionPage2FadeInStep;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&Ov001_OptionPage2FadeInStep);
}

void Ov001_OptionPage2FadeInStep(void) {
void func_ov001_02180584(void);
M2C_UNK Ov001_OpenOptionPage(void);
M2C_UNK func_ov001_02171e20(M2C_UNK);
s32 Ov001_IsFadeActive(s32);
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
Ov001_OpenOptionPage();
func_ov001_02171e20(1);
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180584);
}

void func_ov001_02180584(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_021805ac;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_021805ac);
}

void func_ov001_021805ac(void) {
    M2C_UNK SleepMilliseconds(s32);
    void Ov001_HandleOptionPage2Choice();
    void func_ov001_021805cc(void);
    void func_ov001_02180604(void);
    void func_ov001_02180608(void);
    SleepMilliseconds(10);
    Ov001_HandleOptionPage2Choice();
    func_ov001_021805cc();
    func_ov001_02180604();
    func_ov001_02180608();
}

void func_ov001_021805cc(void) {
    if (KeyPressed(2) != 0) {
        Ov001_LatchIconRowSelection(0);
        return;
    }
    if (func_ov001_021803cc() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_02180604(void) {

}

void func_ov001_02180608(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK Ov001_OptionPage2ConfirmStep;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(7);
    Ov001_SetStepCallback(&Ov001_OptionPage2ConfirmStep);
}

void Ov001_OptionPage2ConfirmStep(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK Ov001_OptionPage2FadeOutStep;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&Ov001_OptionPage2FadeOutStep);
}

/* Fade out the second option page and slide away the icon row when leaving for the friend list. */
void Ov001_OptionPage2FadeOutStep(void) {
    extern u8 gOv001OptionPage2ExitToConnection;
    extern M2C_UNK Ov001_CloseOptionScreen2;
    const s32 fadeFrames = 8;

    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (gOv001OptionPage2ExitToConnection == 0) {
        Ov001_StartIconRowSlideOut();
    }
    if (gOv001OptionPage2ExitToConnection == 0) {
        Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, fadeFrames);
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ, fadeFrames);
    Ov001_SetStepCallback(&Ov001_CloseOptionScreen2);
}

/* Step callback that runs once the second option page's fade-out and the
 * icon-row animation have finished: it tears down the option screen and opens
 * either the friend-list screen (mode 2) or the connection screen (mode 0),
 * according to gOv001OptionPage2ExitToConnection. */
void Ov001_CloseOptionScreen2(void) {
    M2C_UNK Ov001_FreeOptionSprites(void);
    s32 Ov001_IsIconRowIdle(void);
    M2C_UNK Ov001_FreeOptionBackground(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreeOptionPage(void);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001OptionPage2ExitToConnection;
    extern M2C_UNK func_ov001_0217f97c;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((gOv001OptionPage2ExitToConnection == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001OptionPage2ExitToConnection == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001OptionPage2ExitToConnection == 0) {
        Ov001_FreeOptionPage();
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&func_ov001_02181a84);
        return;
    }
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetStepCallback(&func_ov001_0217f97c);
}

/* Handle a choice on the second page of the ov001 option menu: the first choice
 * exits to the connection screen, while leaving records that the page returns to
 * the friend list, plays the cancel sound and shows the cancel message. */
void Ov001_HandleOptionPage2Choice(void) {
    s32 Ov001_GetOptionChoice(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern void Ov001_OptionPage2ConfirmStep(void);
    extern void Ov001_OptionPage2CancelStep(void);
    M2C_UNK Ov001_StopSound(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 gOv001OptionPage2ExitToConnection;

    switch (Ov001_GetOptionChoice()) {
    case 1:
        gOv001OptionPage2ExitToConnection = 1;
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_OptionPage2ConfirmStep);
        return;
    case 4:
        gOv001OptionPage2ExitToConnection = 0;
        Ov001_StopSound();
        Ov001_PlaySound(9);
        Ov001_ShowMessage(0xD, 1, 1, -1, 0);
        Ov001_LockIconRow();
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_OptionPage2CancelStep);
        return;
    }
}

void Ov001_OptionPage2CancelStep(void) {
    extern M2C_UNK func_ov001_02180840;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&func_ov001_02180840);
}

void func_ov001_02180840(void) {
    s32 Ov001_IsRegionMenuActive();
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_OptionPage2ConfirmStep);
}

/* Opens the ov001 Wi-Fi friend-list screen: resets the friend-list state, loads
 * the screen's background, message panel and menu, allocates the friend roster,
 * starts the roster fetch and fades the screen in. */
void Ov001_OpenFriendListScreen(void) {
    extern u8 gOv001FriendListState;
    extern M2C_UNK Ov001_FadeInFriendListScreen;
    void Ov001_LoadFriendListBg(void);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
    M2C_UNK Ov001_OpenMenuForMode(M2C_UNK);
    M2C_UNK Ov001_AllocFriendRoster(void);
    M2C_UNK Ov001_OpenFriendRoster(void);
    M2C_FIELD(&gOv001FriendListState, u16 *, OV001_FRIEND_LIST_TIMER) = 0;
    M2C_FIELD(&gOv001FriendListState, u8 *, OV001_FRIEND_LIST_STATE) = 0;
    Ov001_LoadFriendListBg();
    Ov001_ShowMessagePanel(OV001_MSG_FRIEND_LIST, -1, 0);
    Ov001_LoadSaveSlotObjLayout();
    Ov001_OpenMenuForMode(2);
    Ov001_ShowMessageBox(OV001_MSG_FRIEND_LIST);
    Ov001_CreateAnimSprite(0);
    Ov001_AllocFriendRoster();
    Ov001_OpenFriendRoster();
    Ov001_PlaySound(10);
    Ov001_SetStepCallback(&Ov001_FadeInFriendListScreen);
}

/* Loads the friend-list screen's background: tile graphics, palette and map,
 * then puts BG0/BG1 on the lowest priority. */
void Ov001_LoadFriendListBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001FriendListBgTilesPath, gOv001FriendListBgPalettePath, gOv001FriendListBgMapPath;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001FriendListBgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001FriendListBgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001FriendListBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

void Ov001_FadeInFriendListScreen(void) {
    extern M2C_UNK func_ov001_021809c4;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_021809c4);
}

void func_ov001_021809c4(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    extern M2C_UNK func_ov001_02180a00;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(1);
    Ov001_SetStepCallback(&func_ov001_02180a00);
}

void func_ov001_02180a00(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_02180a28;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02180a28);
}

void func_ov001_02180a28(void) {
    M2C_UNK func_ov001_02180b90();
    void Ov001_CheckFriendList(void);
    func_ov001_02180b68();
    func_ov001_02180b8c();
    func_ov001_02180b90();
    Ov001_CheckFriendList();
}

/* Step callback of the Wi-Fi friend-list screen: after waiting for the roster
 * fetch, show the "no friends" message or the "friend unavailable" message when
 * no friend can be picked, otherwise continue to the friend selection.  Both
 * message paths lock the icon row and run the message step func_ov001_02180cf8. */
void Ov001_CheckFriendList(void) {
    M2C_UNK Ov001_StopSound(void);
    s32 Ov001_GetFriendSlots(void **);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 gOv001FriendListState;
    extern M2C_UNK func_ov001_02180cf8, func_ov001_02180bbc;
    void *slots;
    s32 friendCount;
    s32 busyCount;
    WfcFriendSlot *slot;

    M2C_FIELD(&gOv001FriendListState, u16 *, OV001_FRIEND_LIST_TIMER) =
        M2C_FIELD(&gOv001FriendListState, u16 *, OV001_FRIEND_LIST_TIMER) + 1;
    if (M2C_FIELD(&gOv001FriendListState, u16 *, OV001_FRIEND_LIST_TIMER) < OV001_FRIEND_LIST_WAIT) return;

    Ov001_StopSound();
    friendCount = Ov001_GetFriendSlots(&slots);
    if (friendCount == 0) {
        M2C_FIELD(&gOv001FriendListState, u8 *, OV001_FRIEND_LIST_STATE) = OV001_FRIEND_LIST_EMPTY;
        Ov001_ShowMessage(OV001_MSG_NO_FRIENDS, 1, 1, -1, 0);
        Ov001_PlaySound(18);
        Ov001_LockIconRow();
        Ov001_SetStepCallback(&func_ov001_02180cf8);
        return;
    }
    busyCount = 0;
    if (friendCount > 0) {
        slot = slots;
        do {
            if (slot->status != WFC_FRIEND_SLOT_UNAVAILABLE) break;
            busyCount++;
            slot++;
        } while (busyCount < friendCount);
    }
    if (busyCount == friendCount) {
        M2C_FIELD(&gOv001FriendListState, u8 *, OV001_FRIEND_LIST_STATE) = OV001_FRIEND_LIST_ALL_BUSY;
        Ov001_ShowMessage(OV001_MSG_FRIEND_UNAVAILABLE, 1, 1, -1, 0);
        Ov001_PlaySound(18);
        Ov001_LockIconRow();
        Ov001_SetStepCallback(&func_ov001_02180cf8);
        return;
    }
    M2C_FIELD(&gOv001FriendListState, u8 *, OV001_FRIEND_LIST_STATE) = OV001_FRIEND_LIST_AVAILABLE;
    Ov001_PlaySound(15);
    Ov001_SetStepCallback(&func_ov001_02180bbc);
}

