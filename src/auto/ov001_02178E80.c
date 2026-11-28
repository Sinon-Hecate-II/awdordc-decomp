/* 53 functions from 0x02178E80 to 0x02179E74 (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
#include "gx.h"
#include "ov001_menu.h"
#include "ov001_wh.h"

/* The ov001 profile screen's confirmation state (gOv001ProfileChoice). */
#define OV001_CHOICE_CONFIRMED 0x00 /* u8: set once the player has confirmed an option */
#define OV001_CHOICE_OPTION    0x01 /* u8: the option the player picked (0 or 1) */

/* Step that leaves the Wi-Fi settings screen after its two-choice message popup:
 * once both fades and the icon row are idle it frees the page background, hides
 * the screen's planes (and, when the first option was picked, also frees the
 * option background and hides plane 1) and installs the next step: the option
 * menu when the first option was picked, the follow-up screen otherwise. */
void Ov001_CloseMessageScreen(void) {
    s32 Ov001_IsIconRowIdle();
    extern M2C_UNK gOv001MessageState;
    extern M2C_UNK Ov001_InitOptionMenu;
    extern M2C_UNK Ov001_OpenWfcEraseResultScreen;
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreePageBackground(0);
    if (M2C_FIELD(&gOv001MessageState, u8 *, OV001_MESSAGE_OPTION) == 0) {
        Ov001_FreeMessagePanel();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (M2C_FIELD(&gOv001MessageState, u8 *, OV001_MESSAGE_OPTION) == 0) {
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(&Ov001_InitOptionMenu);
        return;
    }
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback(&Ov001_OpenWfcEraseResultScreen);
}

/* Step of the ov001 profile screen that shows the confirmation message: resets the
 * choice state, loads the text background, copies the profile message into a local
 * buffer and draws it in a text panel, then registers the continuation callback and
 * shows message 29 before the fade-out step takes over. */
void Ov001_ShowProfileMessage(void) {
    void *Ov001_GetProfileMessage(void);
    void Ov001_LoadProfileMessageBg(void);
    void Ov001_ConfirmProfileChoice(void);
    void Ov001_FadeInProfileMessage(void);
    s32 CreateTextPanel(s32, s32);
    M2C_UNK FillU16(s32, void *, s32);
    M2C_UNK CopyU16(void *, void *, s32);
    M2C_UNK DrawPanelText(s32, s32, s32, s32, s32, s32, s32, void *);
    extern s8 gOv001ProfileChoice;
    u8 textBuf[22];
    s32 panel;
    void *message;

    message = Ov001_GetProfileMessage();
    panel = CreateTextPanel(0, 0);
    M2C_FIELD(&gOv001ProfileChoice, u8 *, OV001_CHOICE_OPTION) = 0;
    M2C_FIELD(&gOv001ProfileChoice, u8 *, OV001_CHOICE_CONFIRMED) = 0;
    Ov001_LoadProfileMessageBg();
    FillU16(0, textBuf, 22);
    CopyU16(message + 2, textBuf, M2C_FIELD(message, u8 *, 1) * 2);
    DrawPanelText(panel, 8, 53, 240, 28, 2, 0x480, textBuf);
    CloseTextPanel(panel);
    Ov001_SetProfileScreenCallback(Ov001_ConfirmProfileChoice);
    Ov001_ShowMessage(29, 4, 0, -1, 0);
    Ov001_SetStepCallback(Ov001_FadeInProfileMessage);
}

/* Load the profile confirmation message's background map and put BG0/BG1/BG2 on
 * the lowest priority on both engines. */
void Ov001_LoadProfileMessageBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001ProfileMessageBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001ProfileMessageBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Step that fades the profile confirmation-message screen in from white on the main
 * engine, reveals its background and sprite planes, then hands over to the step that
 * runs once the fade has finished. */
void Ov001_FadeInProfileMessage(void) {
    extern M2C_UNK Ov001_ProfileMessageFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_ProfileMessageFadeDone);
}

/* Step after the profile confirmation message's fade-in: once the main engine's
 * fade finishes, hand over to the step that waits for the player's menu choice. */
void Ov001_ProfileMessageFadeDone(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_WaitProfileChoiceMenu;
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_WaitProfileChoiceMenu);
}

/* Profile screen step that follows the message fade: keep waiting until the region
 * menu starts taking input, then install the step that reads the player's pick. */
void Ov001_WaitProfileChoiceMenu(void) {
    s32 Ov001_GetRegionMenuSelection();
    void Ov001_ProfileChoiceStep(void);
    if (Ov001_GetRegionMenuSelection() == OV001_REGION_SELECTED_PENDING) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_ProfileChoiceStep);
}

/* Profile screen step that waits for the player's pick in the two-option menu:
 * it records option 0 (with sound 7) or option 1 (sound 0xE), clears the profile
 * screen callback, closes the region menu and hands the step to the fade-out. */
void Ov001_ProfileChoiceStep(void) {
    void func_ov001_02179164(void);
    void func_ov001_02179168(void);
    void Ov001_ProfileFadeOutStep(void);
    extern s8 gOv001ProfileChoice;
    s32 selection;

    func_ov001_02179164();
    func_ov001_02179168();
    selection = Ov001_GetRegionMenuSelection();
    switch (selection) {
    case 0:
        M2C_FIELD(&gOv001ProfileChoice, u8 *, OV001_CHOICE_OPTION) = 0;
        Ov001_PlaySound(7);
        break;
    case 1:
        M2C_FIELD(&gOv001ProfileChoice, u8 *, OV001_CHOICE_OPTION) = 1;
        Ov001_PlaySound(0xE);
        break;
    default: return;
    }
    Ov001_SetProfileScreenCallback(0);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_ProfileFadeOutStep);
}

void func_ov001_02179164(void) {

}

void func_ov001_02179168(void) {

}

/* Profile screen step after its choice menu has closed: once the region menu is
 * gone, fade out the option plane too when the player picked the first option
 * (OV001_CHOICE_OPTION 0), then fade out the screen's planes and install the
 * step that runs when the fade-out has finished. */
void Ov001_ProfileFadeOutStep(void) {
    extern s8 gOv001ProfileChoice;
    extern M2C_UNK Ov001_ProfileFadeDoneStep;
    if (Ov001_IsRegionMenuActive() != 0) return;
    if (M2C_FIELD(&gOv001ProfileChoice, u8 *, OV001_CHOICE_OPTION) == 0) {
        Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_ProfileFadeDoneStep);
}

/* Step that runs once the profile screen's fade-out has finished: wait for both
 * engine fades, then either advance the profile setup (when the player picked the
 * second option without confirming) or start the profile exit task, and hand the
 * step to Ov001_CloseProfileScreen. */
void Ov001_ProfileFadeDoneStep(void) {
 M2C_UNK Ov001_StartProfileExitTask();
 M2C_UNK Ov001_AdvanceProfileSetup();
 extern s8 gOv001ProfileChoice;
 extern M2C_UNK Ov001_CloseProfileScreen;
 if(Ov001_IsFadeActive(OV001_FADE_SUB)!=0)return;
 if(Ov001_IsFadeActive(OV001_FADE_MAIN)!=0)return;
 if(M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_CONFIRMED)==0 && M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_OPTION)==1) {
 Ov001_AdvanceProfileSetup();
 }else {Ov001_StartProfileExitTask();}
 Ov001_SetStepCallback(&Ov001_CloseProfileScreen);
}

/* Step that leaves the ov001 online profile screen.  When the player confirmed
 * an option or picked the first one it first waits for the profile task to finish;
 * then it disables the screen's planes, frees the option background if the first
 * option was picked, and installs the next step: the follow-up screen when an
 * option was confirmed, the option menu when the first option was not picked, and
 * the alternate screen otherwise. */
void Ov001_CloseProfileScreen(void) {
s32 Ov001_IsProfileScreenDone(void);
extern s8 gOv001ProfileChoice;
extern M2C_UNK Ov001_OpenProfileReturnScreen, Ov001_InitOptionMenu, Ov001_OpenProfileSetupScreen;
if(M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_CONFIRMED) || !M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_OPTION))
if(!Ov001_IsProfileScreenDone())return;
Ov001_FreePageBackground(0);
Ov001_DisableVisiblePlanes(0,21);
if(!M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_OPTION)) {
Ov001_FreeMessagePanel();Ov001_DisableVisiblePlanes(1,1);
}
Ov001_SetNextScreenMode(0,1);
if(M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_CONFIRMED)) {
Ov001_SetStepCallback(&Ov001_OpenProfileReturnScreen);return;
}
if(!M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_OPTION)) {
Ov001_DisableVisiblePlanes(1,1);
Ov001_SetStepCallback(&Ov001_InitOptionMenu);return;
}
Ov001_SetStepCallback(&Ov001_OpenProfileSetupScreen);
}

/* Profile message callback: record that the player confirmed the choice. */
void Ov001_ConfirmProfileChoice(void) {
    extern s8 gOv001ProfileChoice;
    gOv001ProfileChoice = 1;
}

/* TRUE while the console's lid is closed (bit SHARED_LID_CLOSED of the shared
 * work area's lid word), i.e. the game should go to sleep. */
s32 Ov001_IsLidClosed(void) {
    if (((s32) (*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

/* Opens the Wi-Fi data-erase result screen: installs the profile callback that
 * records the outcome, resets that outcome, loads the result background, shows the
 * result message box, sprite and sound, then hands over to the fade-in step. */
void Ov001_OpenWfcEraseResultScreen(void) {
    M2C_UNK Ov001_InitProfileScreen(M2C_UNK *);
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
    void Ov001_WfcEraseResultCallback(s32);
    void Ov001_LoadWfcEraseResultBackground(void);
    void Ov001_FadeInWfcEraseResultScreen(void);
    extern u8 gOv001WfcEraseResult;
    Ov001_InitProfileScreen((M2C_UNK *)&Ov001_WfcEraseResultCallback);
    gOv001WfcEraseResult = OV001_PROFILE_NO_CHANGE;
    Ov001_LoadWfcEraseResultBackground();
    Ov001_ShowMessageBox(OV001_MSG_WFC_ERASE_RESULT);
    Ov001_CreateAnimSprite(0);
    Ov001_PlaySound(OV001_SOUND_OPEN);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInWfcEraseResultScreen);
}

/* Loads the background map of the step that reports the Wi-Fi data-erase
 * result (the shared "Multi" screen) and lowers the BG priorities. */
void Ov001_LoadWfcEraseResultBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcEraseResultBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001WfcEraseResultBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Step that fades the Wi-Fi data-erase result screen in from white on the main
 * engine, reveals its background and sprite planes, then hands over to the step
 * that runs once the fade has finished. */
void Ov001_FadeInWfcEraseResultScreen(void) {
    extern M2C_UNK Ov001_WfcEraseResultFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_WfcEraseResultFadeDone);
}

/* Step that runs after the Wi-Fi data-erase result screen has faded in: show the
 * popup's icon row (row 1) and hand over to the step that waits for it. */
void Ov001_WfcEraseResultFadeDone(void) {
    void Ov001_WaitWfcEraseResultMenu(void);

    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_CreateMenuIconRow(1);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitWfcEraseResultMenu);
}

/* Wait for the icon row of the Wi-Fi erase-result screen to slide in: once the
 * row reports a selection (not OV001_ICON_ROW_NOT_READY), hand the step over to
 * the erase-result menu's update. */
void Ov001_WaitWfcEraseResultMenu(void) {
    s32 Ov001_GetIconRowSelection();
    extern M2C_UNK Ov001_UpdateWfcEraseResultMenu;
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_UpdateWfcEraseResultMenu);
}

/* Per-frame step of the WFC-erase result menu: read the menu's input, run its
 * (empty) hook and then act on the latched choice. */
void Ov001_UpdateWfcEraseResultMenu(void) {
 void Ov001_HandleWfcEraseResultMenuInput(void);
 void Ov001_WfcEraseResultMenuNoop(void);
 void Ov001_HandleWfcEraseResultChoice(void);
 Ov001_HandleWfcEraseResultMenuInput();
 Ov001_WfcEraseResultMenuNoop();
 Ov001_HandleWfcEraseResultChoice();
}

/* Wi-Fi data-erase result popup input: B latches the popup's only choice, the
 * back icon, and so does closing the console's lid. */
void Ov001_HandleWfcEraseResultMenuInput(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    s32 Ov001_IsLidClosed(void);
    if (KeyPressed(KEY_B) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
        return;
    }
    if (Ov001_IsLidClosed() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void Ov001_WfcEraseResultMenuNoop(void) {

}

/* Wi-Fi data-erase result popup: once the player latches the back choice, stop
 * the popup's sound, play the cancel sound and hand the step to the leave screen. */
void Ov001_HandleWfcEraseResultChoice(void) {
    s32 Ov001_GetIconRowSelection(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK Ov001_LeaveWfcEraseScreen;
    if (Ov001_GetIconRowSelection() != OV001_CHOICE_BACK) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(OV001_SOUND_CANCEL);
    Ov001_SetStepCallback(&Ov001_LeaveWfcEraseScreen);
}

/* Step that leaves the Wi-Fi data-erase result screen once the player dismissed its
 * popup: when the erase left the profile unchanged it first starts the profile exit
 * task, then locks the icon row, waits 8 frames and slides the icon row away. */
void Ov001_LeaveWfcEraseScreen(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_StartProfileExitTask();
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern u8 gOv001WfcEraseResult;
    extern M2C_UNK Ov001_SlideOutProfileIconRow;
    if (gOv001WfcEraseResult == OV001_PROFILE_NO_CHANGE) {
        Ov001_StartProfileExitTask();
    }
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_SlideOutProfileIconRow);
}

/* Step that, once the profile action has finished, slides the icon row out and
 * fades the screen away; when no action ran it first waits for the profile task. */
void Ov001_SlideOutProfileIconRow(void) {
    s32 Ov001_IsProfileScreenDone();
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern u8 gOv001WfcEraseResult;
    extern M2C_UNK func_ov001_021795a4;

    if (Ov001_IsFadeActive(1) != 0) return;
    if (gOv001WfcEraseResult == OV001_PROFILE_NO_CHANGE && Ov001_IsProfileScreenDone() == 0) return;
    Ov001_StartIconRowSlideOut();
    if (gOv001WfcEraseResult == OV001_PROFILE_NO_CHANGE) Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_021795a4);
}

/* Starts the selected battle mode: validates state, then schedules the
 * appropriate per-mode update callback via the state dispatch. */
void func_ov001_021795a4(void) {
    s32 Ov001_IsIconRowIdle(void);
    s32 Ov001_IsProfileScreenDone(void);
    extern u8 gOv001WfcEraseResult;
    void Ov001_InitOptionMenu(void);
    void Ov001_OpenProfileReturnScreen(void);
    if (Ov001_IsFadeActive(0) != 0) return;
    if (gOv001WfcEraseResult == 0 && Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    if (gOv001WfcEraseResult == 0 && Ov001_IsProfileScreenDone() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001WfcEraseResult == 0) {
        Ov001_FreeMessagePanel();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001WfcEraseResult == 0) {
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(Ov001_InitOptionMenu);
        return;
    }
    if (gOv001WfcEraseResult == 2) {
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(Ov001_OpenProfileReturnScreen);
        return;
    }
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback(Ov001_ShowProfileMessage);
}

/* Completion callback of the Wi-Fi data-erase screen: event 0 means the data
 * was erased (mark the profile as saved, success sound), any other event that
 * the erase failed (profile other, failure sound).  Clears the callback and
 * hands the step to the icon-row exit. */
void Ov001_WfcEraseResultCallback(s32 event) {
    extern u8 gOv001WfcEraseResult;
    void Ov001_LeaveWfcEraseScreen(void);
    Ov001_StopSound();
    if (event == 0) {
        gOv001WfcEraseResult = OV001_PROFILE_SAVED;
        Ov001_PlaySound(OV001_SOUND_SAVED);
    } else {
        gOv001WfcEraseResult = OV001_PROFILE_OTHER;
        Ov001_PlaySound(OV001_SOUND_FAILED);
    }
    Ov001_SetProfileScreenCallback(0);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_LeaveWfcEraseScreen);
}

/* TRUE while the console's lid is closed (bit SHARED_LID_CLOSED of the shared
 * work area's lid word); the wireless setup input treats that like the B press. */
s32 Ov001_IsLidClosedForWireless(void) {
    if (((s32) (*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

/* Opens the local wireless (multi-card) setup screen: resets the connection timer,
 * loads the setup background and the save-slot object layout, draws the setup
 * message panel and message box, opens the icon menu, initialises the wireless
 * session and installs the fade-in step. */
void Ov001_OpenWirelessScreen(void) {
    extern u8 gOv001WirelessState;
    void Ov001_LoadWirelessSetupBg(void);
    void Ov001_FadeInWirelessScreen(void);
    M2C_UNK Ov001_LoadSaveSlotObjLayout();
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_OpenMenuForMode(M2C_UNK);
    M2C_UNK Ov001_InitWirelessSetup();
    M2C_FIELD(&gOv001WirelessState, u16 *, OV001_WIRELESS_TIMER) = 0;
    Ov001_LoadWirelessSetupBg();
    Ov001_LoadSaveSlotObjLayout();
    Ov001_ShowMessagePanel(0x36, -1, 0);
    Ov001_OpenMenuForMode(2);
    Ov001_ShowMessageBox(0x22);
    Ov001_CreateAnimSprite(0);
    Ov001_InitWirelessSetup();
    Ov001_PlaySound(0xB);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInWirelessScreen);
}

/* Loads the local wireless (multi-card) setup screen's background: tile
 * graphics, palette and map, then puts BG0/BG1 on the lowest priority. */
void Ov001_LoadWirelessSetupBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WirelessBgTilesPath, gOv001WirelessBgPalettePath, gOv001WirelessBgMapPath;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001WirelessBgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001WirelessBgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001WirelessBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

/* Fade the local wireless screen in: fade both engines in from white, make the
 * screen's background and sprite planes visible, then hand over to the step that
 * runs once the fade completes. */
void Ov001_FadeInWirelessScreen(void) {
    extern M2C_UNK Ov001_WirelessScreenFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, OV001_BLEND_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_WirelessScreenFadeDone);
}

/* Once the local wireless screen's fade-in has finished on both engines, put up
 * its single-button icon row and move on to starting the wireless setup task. */
void Ov001_WirelessScreenFadeDone(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    void Ov001_StartWirelessSetupTask(void);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_CreateMenuIconRow(1);
    Ov001_SetStepCallback(&Ov001_StartWirelessSetupTask);
}

/* Wireless screen step: once the icon row is selectable, start the wireless
 * setup's per-frame task and move on to the step that polls the connection. */
void Ov001_StartWirelessSetupTask(void) {
    s32 Ov001_AddTask(s32, void (*)(void), s32, s32);
    void Ov001_WirelessSetupFrameTask(void);
    extern M2C_UNK Ov001_PollWirelessSetup;
    extern u8 gOv001WirelessState;
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) return;
    M2C_FIELD(&gOv001WirelessState, s32 *, OV001_WIRELESS_TASK) = Ov001_AddTask(1, &Ov001_WirelessSetupFrameTask, 0, 0x78);
    Ov001_SetStepCallback(&Ov001_PollWirelessSetup);
}

/* Poll a pending online battle connection and, on success, hand off to the appropriate follow-up handler. */
void Ov001_PollWirelessSetup(void) {
    void Ov001_HandleWirelessSetupInput(void);
    void func_ov001_02179a04(void);
    void Ov001_CancelWirelessSetupTask(void);
    s32 Ov001_UpdateWirelessSetup(void);
    void Ov001_WaitForWirelessConnection(void);
    void Ov001_AcknowledgeWirelessError(void);
    M2C_UNK Ov001_ReturnTaskNodeVeneer(s32, s32);
    M2C_UNK Ov001_StopSound(void);
    M2C_UNK Ov001_ShowMessage(s32, s32, s32, s32, s32);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 gOv001WirelessState;
    s32 pending;
    Ov001_HandleWirelessSetupInput();
    func_ov001_02179a04();
    Ov001_CancelWirelessSetupTask();
    switch (Ov001_UpdateWirelessSetup()) {
    case 0:
        return;
    case 1:
        pending = M2C_FIELD(&gOv001WirelessState, s32 *, 4);
        if (!pending) return;
        M2C_FIELD(&gOv001WirelessState, u8 *, 0) = 1;
        Ov001_ReturnTaskNodeVeneer(1, pending);
        M2C_FIELD(&gOv001WirelessState, s32 *, 4) = 0;
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitForWirelessConnection);
        return;
    case 2:
        pending = M2C_FIELD(&gOv001WirelessState, s32 *, 4);
        if (!M2C_FIELD(&gOv001WirelessState, s32 *, 4)) return;
        Ov001_StopSound();
        Ov001_ShowMessage(12, 1, 1, -1, 0);
        Ov001_PlaySound(9);
        Ov001_LockIconRow();
        Ov001_ReturnTaskNodeVeneer(1, M2C_FIELD(&gOv001WirelessState, s32 *, 4));
        M2C_FIELD(&gOv001WirelessState, s32 *, 4) = 0;
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_AcknowledgeWirelessError);
        return;
    }
}

/* Local wireless (multi-card) setup popup input: B latches the popup's only
 * choice, the back icon, and so does closing the console's lid. */
void Ov001_HandleWirelessSetupInput(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(KEY_B) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
        return;
    }
    if (Ov001_IsLidClosedForWireless() == 0) return;
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_02179a04(void) {

}

/* Wireless setup step: when the player picks the back icon while the screen's
 * connection task is still pending, post that task for release, forget it and
 * lock the icon row, then hand the step to Ov001_BeginWirelessCancel. */
void Ov001_CancelWirelessSetupTask(void) {
    extern u8 gOv001WirelessState;
    extern M2C_UNK Ov001_BeginWirelessCancel;
    if (Ov001_GetIconRowSelection() != OV001_CHOICE_BACK) return;
    if (M2C_FIELD(&gOv001WirelessState, s32 *, OV001_WIRELESS_TASK) == 0) return;
    Ov001_PostTaskMessage(1, M2C_FIELD(&gOv001WirelessState, s32 *, OV001_WIRELESS_TASK));
    M2C_FIELD(&gOv001WirelessState, s32 *, OV001_WIRELESS_TASK) = 0;
    Ov001_LockIconRow();
    Ov001_SetStepCallback(&Ov001_BeginWirelessCancel);
}

/* Abandon the wireless connection setup: lock the icon row, hand the pending
 * connection task back to its task group and move on to fade the screen out. */
void Ov001_AbandonWirelessConnection(void) {
    extern u8 gOv001WirelessState;
    void Ov001_FadeOutWirelessScreen(void);
    M2C_UNK Ov001_ReturnTaskNodeVeneer(s32, s32);
    Ov001_LockIconRow();
    if (M2C_FIELD(&gOv001WirelessState, s32 *, OV001_WIRELESS_TASK) != 0) {
        Ov001_ReturnTaskNodeVeneer(1, M2C_FIELD(&gOv001WirelessState, s32 *, OV001_WIRELESS_TASK));
    }
    Ov001_StartDelay(8);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeOutWirelessScreen);
}

/* Fade the local wireless (multi-card) setup screen out once the icon row's
 * selection is locked: slide the icon row out (and fade its own panel too when no
 * connection was made), fade out the setup screen, and continue to
 * Ov001_CloseWirelessScreen. */
void Ov001_FadeOutWirelessScreen(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern u8 gOv001WirelessState;
    extern M2C_UNK Ov001_CloseWirelessScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    if (M2C_FIELD(&gOv001WirelessState, u8 *, OV001_WIRELESS_CONNECTED) == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseWirelessScreen);
}

void Ov001_CloseWirelessScreen(void) {
    extern u8 gOv001WirelessState;
    extern void func_ov001_02181a84(void);
    extern void Ov001_OpenSaveScreen(void);

    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    if (gOv001WirelessState == 0 && Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsIconRowIdle() == 0) {
        return;
    }

    Ov001_FinishWirelessSetup(gOv001WirelessState != 0);
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);

    if (gOv001WirelessState == 0) {
        Ov001_FreeMessagePanel();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);

    if (gOv001WirelessState == 0) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(func_ov001_02181a84);
    } else {
        Ov001_SetNextScreenMode(0, 0);
        Ov001_SetStepCallback(Ov001_OpenSaveScreen);
    }
}

/* Per-frame task of the local wireless (multi-card) setup screen: refresh the
 * screen's input and task groups, then read the icon row's input and cancel the
 * setup when the player picks the back icon. */
void Ov001_WirelessSetupFrameTask(void) {
    void Ov001_HandleWirelessSetupInput(void);
    void Ov001_CancelWirelessSetupTask(void);
    M2C_UNK Ov001_UpdateInput();
    M2C_UNK Ov001_UpdateTaskGroup(M2C_UNK);
    Ov001_UpdateInput();
    Ov001_UpdateTaskGroup(0);
    Ov001_HandleWirelessSetupInput();
    Ov001_CancelWirelessSetupTask();
}

/* Wireless setup step after its error message appeared: when the player takes the
 * popup's confirm choice, play the confirm sound, close the popup and hand the
 * step to the one that waits for it to close. */
void Ov001_AcknowledgeWirelessError(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK Ov001_WaitWirelessMessageClose;

    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_WaitWirelessMessageClose);
}

/* Wait for the wireless setup's message popup to finish closing, then abandon the
 * connection attempt. */
void Ov001_WaitWirelessMessageClose(void) {
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    s32 Ov001_IsRegionMenuActive();
    void Ov001_AbandonWirelessConnection(void);

    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_AbandonWirelessConnection);
}

/* Wireless setup wait step: after the connection task was posted it keeps polling
 * the icon row's input and counts frames; once OV001_WIRELESS_TIMEOUT frames pass
 * without a reply it stops the connection sound and gives the attempt up. */
void Ov001_WaitForWirelessConnection(void) {
    extern u8 gOv001WirelessState;
    u8 *state;

    Ov001_HandleWirelessSetupInput();
    func_ov001_02179a04();
    Ov001_CancelWirelessSetupTask();
    state = &gOv001WirelessState;
    M2C_FIELD(state, u16 *, OV001_WIRELESS_TIMER) = M2C_FIELD(state, u16 *, OV001_WIRELESS_TIMER) + 1;
    if (M2C_FIELD(state, u16 *, OV001_WIRELESS_TIMER) < OV001_WIRELESS_TIMEOUT) return;
    Ov001_StopSound();
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_AbandonWirelessConnection);
}

/* Start cancelling the local wireless (multi-card) setup screen: silence the
 * screen's sounds, clear the connected flag and hand the step to
 * Ov001_AbandonWirelessConnection. */
void Ov001_BeginWirelessCancel(void) {
    extern u8 gOv001WirelessState;
    Ov001_StopSound();
    Ov001_PlaySound(7);
    M2C_FIELD(&gOv001WirelessState, u8 *, OV001_WIRELESS_CONNECTED) = 0;
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_AbandonWirelessConnection);
}

/* Open the ov001 save screen: reset its frame timer, load the screen background
   and the save-slot object layout, show its message box and the "saved" sound,
   then hand the step over to the fade-in. */
void Ov001_OpenSaveScreen(void) {
    extern u8 gOv001SaveScreenTimer;
    void Ov001_LoadSaveScreenBg(void);
    void Ov001_FadeInSaveScreen(void);
    gOv001SaveScreenTimer = 0;
    Ov001_LoadSaveScreenBg();
    Ov001_LoadSaveSlotObjLayout();
    Ov001_ShowMessageBox(OV001_MSG_SAVE_SCREEN);
    Ov001_PlaySound(OV001_SOUND_SAVED);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInSaveScreen);
}

/* Load the ov001 save screen's background map and lower the priority of the sub
 * engine's BG0/BG1 and the main engine's BG1/BG2. */
void Ov001_LoadSaveScreenBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001SaveScreenBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001SaveScreenBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fade in the save screen: fade the main screen from white and reveal its
 * background/OBJ planes, then hand over to the step that waits for the fade. */
void Ov001_FadeInSaveScreen(void) {
    void Ov001_WaitSaveScreenFadeIn(void);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitSaveScreenFadeIn);
}

/* Step after the save screen's fade-in: once the main screen's fade has finished,
 * move on to the save screen's delay step. */
void Ov001_WaitSaveScreenFadeIn(void) {
    extern M2C_UNK Ov001_SaveScreenDelayStep;

    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_SaveScreenDelayStep);
}

void Ov001_SaveScreenDelayStep(void) {
 void Ov001_TickSaveDelay(void);
 void func_ov001_02179dc4(void);
 Ov001_TickSaveDelay();
 func_ov001_02179dc4();
}

void func_ov001_02179dc4(void) {

}

/* Start the fade-out of both screens for the ov001 save screen, then install the
 * step that finishes closing it once the fades have run. */
void Ov001_FadeOutSaveScreen(void) {
    extern M2C_UNK Ov001_CloseSaveScreen;
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseSaveScreen);
}

/* Final step of the ov001 save screen: once both of its fades have finished it
 * releases the screen's page and option backgrounds, hides the visible planes
 * and hands over to the step that commits the save and opens the save-slot menu. */
void Ov001_CloseSaveScreen(void) {
    M2C_UNK Ov001_FreeMessagePanel();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNameEntryMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021828ac;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_FreePageBackground(0);
    Ov001_FreeMessagePanel();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetNameEntryMode(0, 1);
    Ov001_SetStepCallback(&func_ov001_021828ac);
}

