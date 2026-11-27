/* 53 functions from 0x0217FB68 to 0x02180B68 (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
#include "gx.h"
#include "ov001_wh.h"

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
    M2C_UNK Ov001_FreeMessagePanel(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreeOptionPage(void);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001OptionExitToConnection;
    extern M2C_UNK Ov001_OpenMatchSetupScreen;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((gOv001OptionExitToConnection == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001OptionExitToConnection == 0) {
        Ov001_FreeMessagePanel();
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
    Ov001_SetStepCallback(&Ov001_OpenMatchSetupScreen);
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
    extern M2C_UNK Ov001_PrepareOptionScreenExit;
    void Ov001_ConfirmLeaveOptionMessage(void);
    switch (Ov001_GetOptionChoice()) {
    case 2:
        gOv001OptionExitToConnection = 1;
        Ov001_SetStepCallback(&Ov001_PrepareOptionScreenExit);
        return;
    case 4:
        gOv001OptionExitToConnection = 0;
        Ov001_StopSound();
        Ov001_PlaySound(9);
        Ov001_ShowMessage(0xD, 1, 1, -1, 0);
        Ov001_LockIconRow();
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_ConfirmLeaveOptionMessage);
        return;
    }
}

/* Option-screen cancel message: once the player confirms the message box
 * (selection 0), play the confirm sound, close the box and wait for it to go
 * before the option screen fades out. */
void Ov001_ConfirmLeaveOptionMessage(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK Ov001_CloseLeaveOptionMessage;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_CloseLeaveOptionMessage);
}

/* Option-screen step after the "leave" confirmation box has closed: wait for the
 * region menu to finish, then fade the option screen out. */
void Ov001_CloseLeaveOptionMessage(void) {
    s32 Ov001_IsRegionMenuActive();
    extern M2C_UNK Ov001_PrepareOptionScreenExit;
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_PrepareOptionScreenExit);
}

/* Whether the console's lid is closed, using the shared lid word's top bit; the
 * match-setup popup treats that like pressing B (back). */
s32 Ov001_IsLidClosedForMatchSetup(void) {
    if (((s32) (*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

/* Open the ov001 download-play match-setup screen: clear the stored-setup flag,
 * load the shared "xb4Multi" background and the save-slot object layout, show the
 * screen's help text and banner sprite, then hand over to the fade-in. */
void Ov001_OpenMatchSetupScreen(void) {
    M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
    void Ov001_LoadXb4MultiBackground(void);
    void Ov001_FadeInMatchSetupScreen(void);
    extern u8 gOv001MatchSetupStored;
    gOv001MatchSetupStored = 0;
    Ov001_LoadXb4MultiBackground();
    Ov001_LoadSaveSlotObjLayout();
    Ov001_ShowMessageBox(OV001_MSG_MATCH_SETUP);
    Ov001_CreateAnimSprite(2);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInMatchSetupScreen);
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

/* Fade the ov001 download-play match-setup screen in from white, revealing the
 * BG0, BG2 and OBJ planes, then build the screen's menu icon row. */
void Ov001_FadeInMatchSetupScreen(void) {
    extern M2C_UNK Ov001_BeginMatchSetupMenu;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN,
                    OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN,
                              OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_BeginMatchSetupMenu);
}

/* Step that runs after the download-play match-setup screen has faded in: show
 * the popup's icon row (row 1) and hand over to the step that waits for it. */
void Ov001_BeginMatchSetupMenu(void) {
    void Ov001_WaitMatchSetupMenu(void);

    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_CreateMenuIconRow(1);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitMatchSetupMenu);
}

/* Wait for the download-play match-setup popup's icon row to finish sliding in
 * (selection -2 while it is not ready): unlock the row and hand over to the
 * popup's per-frame menu step. */
void Ov001_WaitMatchSetupMenu(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK Ov001_UpdateMatchSetupMenu;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateMatchSetupMenu);
}

/* Download-play match-setup popup's per-frame step: wait a frame, then process the
 * second page's menu choice, the popup's B/lid input and the back choice. */
void Ov001_UpdateMatchSetupMenu(void) {
    M2C_UNK SleepMilliseconds(s32);
    void Ov001_HandleMatchSetupPage2Choice(void);
    void Ov001_HandleMatchSetupMenuInput(void);
    void func_ov001_0217ff30(void);
    void Ov001_HandleMatchSetupBack(void);
    SleepMilliseconds(10);
    Ov001_HandleMatchSetupPage2Choice();
    Ov001_HandleMatchSetupMenuInput();
    func_ov001_0217ff30();
    Ov001_HandleMatchSetupBack();
}

/* Match-setup popup input: B latches the popup's only choice, the back icon,
 * and so does closing the console's lid (Ov001_IsLidClosedForMatchSetup is the
 * lid-state test). */
void Ov001_HandleMatchSetupMenuInput(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    s32 Ov001_IsLidClosedForMatchSetup(void);
    if (KeyPressed(KEY_B) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
        return;
    }
    if (Ov001_IsLidClosedForMatchSetup() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_0217ff30(void) {

}

/* Match-setup menu step: once the icon row latched the back choice (0), play the
 * cancel sound and leave the page; any other selection keeps the menu open. */
void Ov001_HandleMatchSetupBack(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK Ov001_BeginMatchSetupExit;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(OV001_SOUND_CANCEL);
    Ov001_SetStepCallback(&Ov001_BeginMatchSetupExit);
}

/* Match-setup page exit step (back chosen): lock the icon row, hold it for a few
 * frames, then hand the step over to the page's fade-out. */
void Ov001_BeginMatchSetupExit(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutMatchSetup;
    Ov001_LockIconRow();
    Ov001_StartDelay(OV001_STEP_DELAY_FRAMES);
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
    M2C_UNK Ov001_FreeMessagePanel(void);
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
        Ov001_FreeMessagePanel();
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
extern u8 gOv001MatchSetupStored; void Ov001_BeginMatchSetupExit(void); void Ov001_ConfirmMatchSetupMessage(void);
switch(Ov001_GetOptionChoice()){
case 3: gOv001MatchSetupStored=1;Ov001_StopSound();Ov001_StoreMatchSetup();Ov001_SetStepCallback((M2C_UNK *)&Ov001_BeginMatchSetupExit);return;
case 4: gOv001MatchSetupStored=0;Ov001_StopSound();Ov001_PlaySound(9);Ov001_ShowMessage(13,1,1,-1,0);Ov001_LockIconRow();Ov001_SetStepCallback((M2C_UNK *)&Ov001_ConfirmMatchSetupMessage);return;
case 5: gOv001MatchSetupStored=0;Ov001_StopSound();Ov001_PlaySound(18);Ov001_ShowMessage(14,1,1,-1,0);Ov001_LockIconRow();Ov001_SetStepCallback((M2C_UNK *)&Ov001_ConfirmMatchSetupMessage);return;
}}

/* Match-setup cancel message: once the player confirms the message box (option
 * 0), play the confirm sound, close the box and wait for it to go before the
 * page fades out. */
void Ov001_ConfirmMatchSetupMessage(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK Ov001_LeaveMatchSetupMessage;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6); /* OV001_SOUND_CONFIRM (ov001_wh.h) */
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_LeaveMatchSetupMessage);
}

/* Match-setup cancel step: once the cancel message box has closed, hand the
 * step over to the page's exit. */
void Ov001_LeaveMatchSetupMessage(void) {
    s32 Ov001_IsRegionMenuActive();
    void Ov001_BeginMatchSetupExit(void);
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_BeginMatchSetupExit);
}

/* Open the advance match-setup screen, reset its timer, show its background and message, then schedule the fade-in. */
void Ov001_AdvanceMatchSetup(void) {
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void Ov001_LoadMatchSetupBackground(void);
    void Ov001_FadeInMatchSetupAdvance(void);
    extern s8 gOv001MatchSetupSaveFrames;

    gOv001MatchSetupSaveFrames = 0;
    Ov001_LoadMatchSetupBackground();
    Ov001_LoadSaveSlotObjLayout();
    Ov001_ShowMessageBox(OV001_MSG_MATCH_SETUP_ADVANCE);
    Ov001_PlaySound(0x10);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInMatchSetupAdvance);
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

/* Step that fades the advance match-setup screen in from white on the main engine,
 * reveals its background and sprite planes, then hands over to the step that runs
 * once the fade has finished. */
void Ov001_FadeInMatchSetupAdvance(void) {
    extern M2C_UNK Ov001_MatchSetupAdvanceFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_MatchSetupAdvanceFadeDone);
}

/* Step after the advance match-setup screen has faded in: wait for the main
 * engine's fade, then hand the step to the save-delay stage. */
void Ov001_MatchSetupAdvanceFadeDone(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_MatchSetupSaveDelayStep;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_MatchSetupSaveDelayStep);
}

void Ov001_MatchSetupSaveDelayStep(void) {
    void func_ov001_021802e8(void);
    void Ov001_TickMatchSetupSaveDelay(void);
    Ov001_TickMatchSetupSaveDelay();
    func_ov001_021802e8();
}

void func_ov001_021802e8(void) {

}

/* Fade both screens out to white, then move on to closing the match set-up and
 * opening the save-slot menu. */
void Ov001_FadeOutMatchSetupForSave(void) {
    extern M2C_UNK Ov001_CloseMatchSetupForSave;
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_CloseMatchSetupForSave);
}

/* Waits for both fades, clears the match setup display, and opens the save slot menu. */
void Ov001_CloseMatchSetupForSave(void) {
    M2C_UNK Ov001_FreeMessagePanel(void);
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
    Ov001_FreeMessagePanel();
    Ov001_DisableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_DisableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetNameEntryMode(0, 1);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_PrepareSaveSlotMenu);
}

/* Wait 120 frames on the match-setup screen, then move on to fading both
 * screens out towards the save slot menu. */
void Ov001_TickMatchSetupSaveDelay(void) {
    extern s8 gOv001MatchSetupSaveFrames;
    void Ov001_FadeOutMatchSetupForSave(void);
    M2C_FIELD(&gOv001MatchSetupSaveFrames,u8 *,0) = M2C_FIELD(&gOv001MatchSetupSaveFrames,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&gOv001MatchSetupSaveFrames,u8 *,0) < 120U) return;
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeOutMatchSetupForSave);
}

/* TRUE while the console's lid is closed (bit SHARED_LID_CLOSED of the shared
 * work area's lid word); the option page 2 popup treats that like the B press. */
s32 Ov001_IsLidClosedForOptionPage2(void) {
    if (((s32) (*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED) >> 0xF) != 0) {
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

/* Show the option menu's second page: fade both engines in from white, make the
 * page's background and sprite planes visible, then hand over to the fade's
 * completion step. */
void Ov001_FadeInOptionPage2(void) {
    extern M2C_UNK Ov001_OptionPage2FadeInStep;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, OV001_BLEND_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_OptionPage2FadeInStep);
}

/* Completion step of the option page 2 fade-in: once both the sub and the main
 * fade have finished, open the option page, build the option menu's icon row
 * (menu id 1) and wait for that row's intro before unlocking it. */
void Ov001_OptionPage2FadeInStep(void) {
void Ov001_UnlockOptionPage2IconRow(void);
M2C_UNK Ov001_OpenOptionPage(void);
M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
s32 Ov001_IsFadeActive(s32);
if(Ov001_IsFadeActive(OV001_FADE_SUB))return;
if(Ov001_IsFadeActive(OV001_FADE_MAIN))return;
Ov001_OpenOptionPage();
Ov001_CreateMenuIconRow(1);
Ov001_SetStepCallback((M2C_UNK *)&Ov001_UnlockOptionPage2IconRow);
}

/* Wait for the ov001 option page 2's icon row to finish sliding in (selection
 * -2 while it is not ready): unlock the row and hand over to the page's
 * per-frame menu step. */
void Ov001_UnlockOptionPage2IconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK Ov001_UpdateOptionPage2Menu;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateOptionPage2Menu);
}

/* Option page 2's per-frame step: wait a frame, then process the page's menu
 * choice, its B/lid input, the no-op step and the back choice. */
void Ov001_UpdateOptionPage2Menu(void) {
    M2C_UNK SleepMilliseconds(s32);
    void Ov001_HandleOptionPage2Choice();
    void Ov001_HandleOptionPage2MenuInput(void);
    void func_ov001_02180604(void);
    void Ov001_HandleOptionPage2Back(void);
    SleepMilliseconds(10);
    Ov001_HandleOptionPage2Choice();
    Ov001_HandleOptionPage2MenuInput();
    func_ov001_02180604();
    Ov001_HandleOptionPage2Back();
}

/* Option page 2's popup input: B latches the page's only choice, the back icon,
 * and so does closing the console's lid (Ov001_IsLidClosedForOptionPage2 is the inlined copy
 * of the shared lid-state test). */
void Ov001_HandleOptionPage2MenuInput(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(KEY_B) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
        return;
    }
    if (Ov001_IsLidClosedForOptionPage2() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_02180604(void) {

}

/* Option page 2's step: once the icon row latched the back choice (0), play the
 * cancel sound and leave the page; any other selection keeps the menu open. */
void Ov001_HandleOptionPage2Back(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK Ov001_OptionPage2ConfirmStep;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(OV001_SOUND_CANCEL);
    Ov001_SetStepCallback(&Ov001_OptionPage2ConfirmStep);
}

/* Option page 2's exit step (back chosen): lock the icon row, hold it for a few
 * frames, then hand the step over to the page's fade-out. */
void Ov001_OptionPage2ConfirmStep(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_OptionPage2FadeOutStep;
    Ov001_LockIconRow();
    Ov001_StartDelay(OV001_STEP_DELAY_FRAMES);
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
    M2C_UNK Ov001_FreeMessagePanel(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreeOptionPage(void);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001OptionPage2ExitToConnection;
    extern M2C_UNK Ov001_OpenConnectionScreen;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((gOv001OptionPage2ExitToConnection == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001OptionPage2ExitToConnection == 0) {
        Ov001_FreeMessagePanel();
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
    Ov001_SetStepCallback(&Ov001_OpenConnectionScreen);
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

/* Cancel step of the second option page: while the region menu reports a
 * nonzero selection nothing happens; at zero it plays the confirm sound, closes
 * the region menu and moves on to the step that waits for the close. */
void Ov001_OptionPage2CancelStep(void) {
    extern M2C_UNK Ov001_OptionPage2CancelDoneStep;

    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_OptionPage2CancelDoneStep);
}

/* Second option page's cancel-done step: wait for the region menu to finish
 * closing, then return to the page's confirm step. */
void Ov001_OptionPage2CancelDoneStep(void) {
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

/* Fade in the friend-list screen's panel and screen and show its planes, then wait
 * for the fade in the next step. */
void Ov001_FadeInFriendListScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern M2C_UNK Ov001_FriendListFadeDone;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&Ov001_FriendListFadeDone);
}

/* Step that runs once the friend-list screen's fade-in has finished: wait for the
 * sub and main engine fades, then put up its single-button icon row and hand over
 * to the step that waits for it to slide in. */
void Ov001_FriendListFadeDone(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    extern M2C_UNK Ov001_FriendListWaitIconRow;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_CreateMenuIconRow(1);
    Ov001_SetStepCallback(&Ov001_FriendListWaitIconRow);
}

/* Step of the ov001 Wi-Fi friend-list screen that waits for its icon row to slide
   in: while the row is not ready, wait; then unlock it and hand over to the step
   that handles the screen's input. */
void Ov001_FriendListWaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK Ov001_UpdateFriendList;
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateFriendList);
}

/* Per-frame step of the ov001 Wi-Fi friend-list screen: process the panel input,
 * run the empty per-frame hook, then handle the back choice and the roster
 * fetch result. */
void Ov001_UpdateFriendList(void) {
    M2C_UNK Ov001_HandleFriendListBack();
    void Ov001_CheckFriendList(void);

    Ov001_HandleFriendListMenuInput();
    Ov001_FriendListNoop();
    Ov001_HandleFriendListBack();
    Ov001_CheckFriendList();
}

/* Step callback of the Wi-Fi friend-list screen: after waiting for the roster
 * fetch, show the "no friends" message or the "friend unavailable" message when
 * no friend can be picked, otherwise continue to the friend selection.  Both
 * message paths lock the icon row and run the message step Ov001_ConfirmLeaveFriendList. */
void Ov001_CheckFriendList(void) {
    M2C_UNK Ov001_StopSound(void);
    s32 Ov001_GetFriendSlots(void **);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 gOv001FriendListState;
    extern M2C_UNK Ov001_ConfirmLeaveFriendList, Ov001_BackOutFriendList;
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
        Ov001_SetStepCallback(&Ov001_ConfirmLeaveFriendList);
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
        Ov001_SetStepCallback(&Ov001_ConfirmLeaveFriendList);
        return;
    }
    M2C_FIELD(&gOv001FriendListState, u8 *, OV001_FRIEND_LIST_STATE) = OV001_FRIEND_LIST_AVAILABLE;
    Ov001_PlaySound(15);
    Ov001_SetStepCallback(&Ov001_BackOutFriendList);
}

