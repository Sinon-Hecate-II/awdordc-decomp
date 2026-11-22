/* 53 functions from 0x02178E80 to 0x02179E74 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
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
    extern M2C_UNK func_ov001_02179320;
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreePageBackground(0);
    if (M2C_FIELD(&gOv001MessageState, u8 *, OV001_MESSAGE_OPTION) == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (M2C_FIELD(&gOv001MessageState, u8 *, OV001_MESSAGE_OPTION) == 0) {
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(&Ov001_InitOptionMenu);
        return;
    }
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback(&func_ov001_02179320);
}

/* Step of the ov001 profile screen that shows the confirmation message: resets the
 * choice state, loads the text background, copies the profile message into a local
 * buffer and draws it in a text panel, then registers the continuation callback and
 * shows message 29 before the fade-out step takes over. */
void Ov001_ShowProfileMessage(void) {
    void *func_ov001_02176114(void);
    void Ov001_LoadProfileMessageBg(void);
    void func_ov001_021792ec(void);
    void func_ov001_02179078(void);
    s32 CreateTextPanel(s32, s32);
    M2C_UNK FillU16(s32, void *, s32);
    M2C_UNK CopyU16(void *, void *, s32);
    M2C_UNK DrawPanelText(s32, s32, s32, s32, s32, s32, s32, void *);
    extern s8 gOv001ProfileChoice;
    u8 textBuf[22];
    s32 panel;
    void *message;

    message = func_ov001_02176114();
    panel = CreateTextPanel(0, 0);
    M2C_FIELD(&gOv001ProfileChoice, u8 *, OV001_CHOICE_OPTION) = 0;
    M2C_FIELD(&gOv001ProfileChoice, u8 *, OV001_CHOICE_CONFIRMED) = 0;
    Ov001_LoadProfileMessageBg();
    FillU16(0, textBuf, 22);
    CopyU16(message + 2, textBuf, M2C_FIELD(message, u8 *, 1) * 2);
    DrawPanelText(panel, 8, 53, 240, 28, 2, 0x480, textBuf);
    CloseTextPanel(panel);
    Ov001_SetProfileScreenCallback(func_ov001_021792ec);
    Ov001_ShowMessage(29, 4, 0, -1, 0);
    Ov001_SetStepCallback(func_ov001_02179078);
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

void func_ov001_02179078(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021790ac;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_021790ac);
}

void func_ov001_021790ac(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK func_ov001_021790d0;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_021790d0);
}

void func_ov001_021790d0(void) {
    s32 Ov001_GetRegionMenuSelection();
    void Ov001_ProfileChoiceStep(void);
    if (Ov001_GetRegionMenuSelection() == -2) {
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
extern M2C_UNK func_ov001_02178bc0, Ov001_InitOptionMenu, func_ov001_02177fd8;
if(M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_CONFIRMED) || !M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_OPTION))
if(!Ov001_IsProfileScreenDone())return;
Ov001_FreePageBackground(0);
Ov001_DisableVisiblePlanes(0,21);
if(!M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_OPTION)) {
Ov001_FreeOptionBackground();Ov001_DisableVisiblePlanes(1,1);
}
Ov001_SetNextScreenMode(0,1);
if(M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_CONFIRMED)) {
Ov001_SetStepCallback(&func_ov001_02178bc0);return;
}
if(!M2C_FIELD(&gOv001ProfileChoice,u8 *,OV001_CHOICE_OPTION)) {
Ov001_DisableVisiblePlanes(1,1);
Ov001_SetStepCallback(&Ov001_InitOptionMenu);return;
}
Ov001_SetStepCallback(&func_ov001_02177fd8);
}

void func_ov001_021792ec(void) {
    extern s8 gOv001ProfileChoice;
    gOv001ProfileChoice = 1;
}

s32 func_ov001_02179300(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02179320(void) {
 M2C_UNK func_ov001_02175f8c(M2C_UNK *);
 M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
 M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
 void Ov001_WfcEraseResultCallback(s32);
 void Ov001_LoadWfcEraseResultBackground(void);
 void func_ov001_021793ec(void);
 extern u8 gOv001WfcEraseResult;
 func_ov001_02175f8c((M2C_UNK *)&Ov001_WfcEraseResultCallback);
 gOv001WfcEraseResult=0;
 Ov001_LoadWfcEraseResultBackground();
 Ov001_ShowMessageBox(0x1C);
 Ov001_CreateAnimSprite(0);
 Ov001_PlaySound(11);
 Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021793ec);
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

void func_ov001_021793ec(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    void func_ov001_02179420(void);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_02179420);
}

void func_ov001_02179420(void) {
    void func_ov001_0217944c(void);
    if (Ov001_IsFadeActive(0) != 0) return;
    func_ov001_02171e20(1);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217944c);
}

void func_ov001_0217944c(void) {
    s32 Ov001_GetIconRowSelection();
    extern M2C_UNK func_ov001_02179470;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_02179470);
}

void func_ov001_02179470(void) {
 void func_ov001_02179484(void);
 void func_ov001_021794bc(void);
 void func_ov001_021794c0(void);
 func_ov001_02179484();
 func_ov001_021794bc();
 func_ov001_021794c0();
}

void func_ov001_02179484(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(2) != 0) {
        Ov001_LatchIconRowSelection(0);
        return;
    }
    if (func_ov001_02179300() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_021794bc(void) {

}

void func_ov001_021794c0(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern M2C_UNK Ov001_LeaveWfcEraseScreen;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(7);
    Ov001_SetStepCallback(&Ov001_LeaveWfcEraseScreen);
}

void Ov001_LeaveWfcEraseScreen(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_StartProfileExitTask();
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern u8 gOv001WfcEraseResult;
    extern M2C_UNK Ov001_SlideOutProfileIconRow;
    if (gOv001WfcEraseResult == 0) {
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
    void func_ov001_02178bc0(void);
    if (Ov001_IsFadeActive(0) != 0) return;
    if (gOv001WfcEraseResult == 0 && Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    if (gOv001WfcEraseResult == 0 && Ov001_IsProfileScreenDone() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001WfcEraseResult == 0) {
        Ov001_FreeOptionBackground();
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
        Ov001_SetStepCallback(func_ov001_02178bc0);
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

s32 func_ov001_021796f8(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
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

void Ov001_WirelessScreenFadeDone(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    void func_ov001_021798b0(void);
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(1);
    Ov001_SetStepCallback(&func_ov001_021798b0);
}

void func_ov001_021798b0(void) {
    s32 Ov001_AddTask(s32, void (*)(void), s32, s32);
    void func_ov001_02179bd0(void);
    extern M2C_UNK func_ov001_021798f8;
    extern u8 gOv001WirelessState;
    if (Ov001_GetIconRowSelection() == -2) return;
    M2C_FIELD(&gOv001WirelessState, s32 *, 4) = Ov001_AddTask(1, &func_ov001_02179bd0, 0, 0x78);
    Ov001_SetStepCallback(&func_ov001_021798f8);
}

/* Poll a pending online battle connection and, on success, hand off to the appropriate follow-up handler. */
void func_ov001_021798f8(void) {
    void func_ov001_021799cc(void);
    void func_ov001_02179a04(void);
    void func_ov001_02179a08(void);
    s32 Ov001_UpdateWirelessSetup(void);
    void func_ov001_02179c38(void);
    void func_ov001_02179bec(void);
    M2C_UNK func_ov001_0218c94c(s32, s32);
    M2C_UNK Ov001_StopSound(void);
    M2C_UNK Ov001_ShowMessage(s32, s32, s32, s32, s32);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 gOv001WirelessState;
    s32 pending;
    func_ov001_021799cc();
    func_ov001_02179a04();
    func_ov001_02179a08();
    switch (Ov001_UpdateWirelessSetup()) {
    case 0:
        return;
    case 1:
        pending = M2C_FIELD(&gOv001WirelessState, s32 *, 4);
        if (!pending) return;
        M2C_FIELD(&gOv001WirelessState, u8 *, 0) = 1;
        func_ov001_0218c94c(1, pending);
        M2C_FIELD(&gOv001WirelessState, s32 *, 4) = 0;
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02179c38);
        return;
    case 2:
        pending = M2C_FIELD(&gOv001WirelessState, s32 *, 4);
        if (!M2C_FIELD(&gOv001WirelessState, s32 *, 4)) return;
        Ov001_StopSound();
        Ov001_ShowMessage(12, 1, 1, -1, 0);
        Ov001_PlaySound(9);
        Ov001_LockIconRow();
        func_ov001_0218c94c(1, M2C_FIELD(&gOv001WirelessState, s32 *, 4));
        M2C_FIELD(&gOv001WirelessState, s32 *, 4) = 0;
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02179bec);
        return;
    }
}

void func_ov001_021799cc(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(2) != 0) {
        Ov001_LatchIconRowSelection(0);
        return;
    }
    if (func_ov001_021796f8() == 0) return;
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_02179a04(void) {

}

void func_ov001_02179a08(void) {
    extern u8 gOv001WirelessState;
    extern M2C_UNK func_ov001_02179c84;
    if (Ov001_GetIconRowSelection() != 0) return;
    if (M2C_FIELD(&gOv001WirelessState, s32 *, 4) == 0) return;
    Ov001_PostTaskMessage(1, M2C_FIELD(&gOv001WirelessState, s32 *, 4));
    M2C_FIELD(&gOv001WirelessState, s32 *, 4) = 0;
    Ov001_LockIconRow();
    Ov001_SetStepCallback(&func_ov001_02179c84);
}

void func_ov001_02179a54(void) {
    extern u8 gOv001WirelessState;
    void Ov001_FadeOutWirelessScreen(void);
    Ov001_LockIconRow();
    if (M2C_FIELD(&gOv001WirelessState, s32 *, 4) != 0) {
        func_ov001_0218c94c(1, M2C_FIELD(&gOv001WirelessState, s32 *, 4));
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
    extern void func_ov001_02179cb4(void);

    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    if (gOv001WirelessState == 0 && Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsIconRowIdle() == 0) {
        return;
    }

    func_ov001_021757d0(gOv001WirelessState != 0);
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);

    if (gOv001WirelessState == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);

    if (gOv001WirelessState == 0) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(func_ov001_02181a84);
    } else {
        Ov001_SetNextScreenMode(0, 0);
        Ov001_SetStepCallback(func_ov001_02179cb4);
    }
}

void func_ov001_02179bd0(void) {
    void func_ov001_021799cc(void);
    void func_ov001_02179a08(void);
    M2C_UNK Ov001_UpdateInput();
    M2C_UNK func_ov001_0218c7d4(M2C_UNK);
    Ov001_UpdateInput();
    func_ov001_0218c7d4(0);
    func_ov001_021799cc();
    func_ov001_02179a08();
}

void func_ov001_02179bec(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK func_ov001_02179c18;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&func_ov001_02179c18);
}

void func_ov001_02179c18(void) {
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    s32 Ov001_IsRegionMenuActive();
    void func_ov001_02179a54(void);
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02179a54);
}

void func_ov001_02179c38(void) {
extern u8 gOv001WirelessState;
u8 *p;
func_ov001_021799cc();
func_ov001_02179a04();
func_ov001_02179a08();
p=&gOv001WirelessState;
M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,2)+1;
if(M2C_FIELD(p,u16 *,2)<0x438U) return;
Ov001_StopSound();
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02179a54);
}

void func_ov001_02179c84(void) {
extern u8 gOv001WirelessState;
Ov001_StopSound();
Ov001_PlaySound(7);
gOv001WirelessState=0;
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02179a54);
}

void func_ov001_02179cb4(void) {
extern u8 data_ov001_02193d94;
void Ov001_LoadSaveScreenBg(void);
void func_ov001_02179d5c(void);
data_ov001_02193d94=0;
Ov001_LoadSaveScreenBg();
Ov001_LoadSaveSlotObjLayout();
Ov001_ShowMessageBox(0x23);
Ov001_PlaySound(0x10);
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02179d5c);
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

void func_ov001_02179d5c(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02179d90;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_02179d90);
}

void func_ov001_02179d90(void) {
    extern M2C_UNK func_ov001_02179db4;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_02179db4);
}

void func_ov001_02179db4(void) {
 void func_ov001_02179e74(void);
 void func_ov001_02179dc4(void);
 func_ov001_02179e74();
 func_ov001_02179dc4();
}

void func_ov001_02179dc4(void) {

}

void func_ov001_02179dc8(void) {
    extern M2C_UNK Ov001_CloseSaveScreen;
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseSaveScreen);
}

/* Final step of the ov001 save screen: once both of its fades have finished it
 * releases the screen's page and option backgrounds, hides the visible planes
 * and hands over to the step that commits the save and opens the save-slot menu. */
void Ov001_CloseSaveScreen(void) {
    M2C_UNK Ov001_FreeOptionBackground();
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
    Ov001_FreeOptionBackground();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetNameEntryMode(0, 1);
    Ov001_SetStepCallback(&func_ov001_021828ac);
}

