/* 68 functions from 0x02177F1C to 0x02178E80 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ov001_wh.h"
#include "wfc.h"

/* Moves the Wi-Fi option menu's selection one row: direction 1 is up (two rows
 * forward modulo the option count), anything else down; plays the move sound and
 * lays the choice frame over the newly selected row. */
void Ov001_MoveOptionSelection(s32 direction) {
    s32 HardwareDivideRemainder(s32, s32);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_LayoutChoiceFrame(u16,u16,u16,u16);
    extern M2C_UNK gOv001OptionFrameLeft;
    extern M2C_UNK gOv001OptionFrameTop;
    extern M2C_UNK gOv001OptionFrameRight;
    extern M2C_UNK gOv001OptionFrameBottom;
    extern M2C_UNK gOv001OptionMenuState;
    s32 offset;
    if (direction == 1) {
        M2C_FIELD(&gOv001OptionMenuState, u8 *, 0) = HardwareDivideRemainder(M2C_FIELD(&gOv001OptionMenuState, u8 *, 0) + 2, OV001_OPTION_COUNT);
    } else {
        M2C_FIELD(&gOv001OptionMenuState, u8 *, 0) = HardwareDivideRemainder(M2C_FIELD(&gOv001OptionMenuState, u8 *, 0) + 1, OV001_OPTION_COUNT);
    }
    Ov001_PlaySound(OV001_SOUND_MOVE);
    offset = M2C_FIELD(&gOv001OptionMenuState, u8 *, 0) * 8;
    Ov001_LayoutChoiceFrame(M2C_FIELD(&gOv001OptionFrameLeft,u16 *,offset), M2C_FIELD(&gOv001OptionFrameRight,u16 *,offset), M2C_FIELD(&gOv001OptionFrameTop,u16 *,offset), M2C_FIELD(&gOv001OptionFrameBottom,u16 *,offset));
}

/* Copy the OBJ tile of the ov001 option menu's selected row: gOv001OptionIconTiles
 * maps the selected option to its tile index, used as both the source tile in the
 * loaded option graphics and its OBJ destination. */
void Ov001_LoadSelectedOptionTile(void) {
    void Ov001_LoadObjTile(s32, u8, u8);
    extern M2C_UNK gOv001OptionIconTiles;
    extern M2C_UNK gOv001OptionMenuState;
    u8 tile;

    tile = M2C_FIELD(&gOv001OptionIconTiles, u8 *, M2C_FIELD(&gOv001OptionMenuState, u8 *, OV001_OPTION_MENU_SELECTED));
    Ov001_LoadObjTile(M2C_FIELD(&gOv001OptionMenuState, s32 *, OV001_OPTION_MENU_GFX), tile, tile);
}

/* Open the ov001 WFC profile-setup screen: load the shared Multi background, put
 * up its message box, the profile-setup sprite and the WFC icon, play the open
 * sound and hand over to the fade-in step. */
void Ov001_OpenProfileSetupScreen(void) {
    void Ov001_LoadMultiBackground(void);
    void Ov001_FadeInProfileSetupScreen(void);
    M2C_UNK Ov001_ShowMessageBox(s32);
    M2C_UNK Ov001_CreateAnimSprite(s32);
    M2C_UNK Ov001_ShowWfcIcon(s32);
    M2C_UNK Ov001_PlaySound(s32);
    Ov001_LoadMultiBackground();
    Ov001_ShowMessageBox(30);
    Ov001_CreateAnimSprite(0);
    Ov001_ShowWfcIcon(1);
    Ov001_PlaySound(OV001_SOUND_OPEN);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInProfileSetupScreen);
}

/* Set up the shared ov001 "Multi" background: load its screen map and give the
 * main and sub background planes the lowest priority so the screen's sprites and
 * text draw over it. */
void Ov001_LoadMultiBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001MultiBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001MultiBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fade in the Wi-Fi profile-setup screen: fade the main engine in from white
 * with its BG0/BG2 and OBJ planes, show those planes, then hand over to the
 * step that waits for the fade to finish. */
void Ov001_FadeInProfileSetupScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_WaitProfileSetupFadeIn;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_WaitProfileSetupFadeIn);
}

/* Once the profile-setup screen's fade-in has finished, give the screen over to
 * the WFC profile screen: install its completion callback and the step that
 * waits on it. */
void Ov001_WaitProfileSetupFadeIn(void) {
    M2C_UNK Ov001_SetProfileScreenCallback(M2C_UNK *);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_ProfileScreenStep;
    extern M2C_UNK Ov001_ProfileScreenCallback;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetProfileScreenCallback(&Ov001_ProfileScreenCallback);
    Ov001_SetStepCallback(&Ov001_ProfileScreenStep);
}

void Ov001_ProfileScreenStep(void) {
    void func_ov001_02178104(void);
    void func_ov001_02178108(void);
    func_ov001_02178104();
    func_ov001_02178108();
}

void func_ov001_02178104(void) {

}

void func_ov001_02178108(void) {

}

void Ov001_FadeOutProfileScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_CloseWfcProfileScreen;
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseWfcProfileScreen);
}

/* Close the Wi-Fi profile screen once its fades are done and the profile task
 * has finished: hide the WFC icon, free the screen's sprites and background,
 * hide its planes, then show the screen that follows from the profile result
 * (no profile change, profile saved, or the alternate profile action). */
void Ov001_CloseWfcProfileScreen(void) {
    M2C_UNK Ov001_FreeOptionSprites();
    M2C_UNK Ov001_HideWfcIcon();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    s32 Ov001_IsProfileScreenDone();
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern s8 gOv001ProfileScreenResult;
    void func_ov001_02178250(void);
    void Ov001_OpenProfileResultScreen(void);
    void Ov001_OpenProfileReturnScreen(void);
    if (Ov001_IsFadeActive(0) != 0) return;
    if (Ov001_IsProfileScreenDone() == 0) return;
    Ov001_HideWfcIcon();
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    Ov001_DisableVisiblePlanes(0, 0x15);
    Ov001_SetNextScreenMode(0, 1);
    if ((u8) gOv001ProfileScreenResult == 0) {
        Ov001_SetStepCallback((M2C_UNK *) &Ov001_OpenProfileReturnScreen);
        return;
    }
    if ((u8) gOv001ProfileScreenResult == 2) {
        Ov001_SetStepCallback((M2C_UNK *) &Ov001_OpenProfileResultScreen);
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *) &func_ov001_02178250);
}

/* Completion callback of the WFC profile screen: event 2 means a profile was
 * obtained, so write it into the save slots and mark the screen as saved; event
 * 3 is the failed attempt; any other event leaves the profile unchanged.  Plays
 * the matching sound, clears the callback and fades the screen out. */
void Ov001_ProfileScreenCallback(s32 event) {
    M2C_UNK Ov001_StartProfileExitTask();
    M2C_UNK ResetSaveSlotsWithWfcProfile();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound();
    extern s8 gOv001ProfileScreenResult;
    if (event == 2) {
        ResetSaveSlotsWithWfcProfile();
        gOv001ProfileScreenResult = OV001_PROFILE_SAVED;
        Ov001_StopSound();
        Ov001_PlaySound(OV001_SOUND_SAVED);
    } else if (event == 3) {
        gOv001ProfileScreenResult = OV001_PROFILE_OTHER;
        Ov001_StopSound();
        Ov001_PlaySound(OV001_SOUND_FAILED);
    } else {
        gOv001ProfileScreenResult = OV001_PROFILE_NO_CHANGE;
        Ov001_StopSound();
        Ov001_PlaySound(OV001_SOUND_FAILED);
    }
    Ov001_SetProfileScreenCallback(0);
    Ov001_StartProfileExitTask();
    Ov001_SetStepCallback(&Ov001_FadeOutProfileScreen);
}

void func_ov001_02178250(void) {
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    void Ov001_LowerBackgroundPriorities(void);
    extern M2C_UNK func_ov001_021782d8;
    Ov001_LowerBackgroundPriorities();
    Ov001_ShowMessageBox(0x1F);
    Ov001_SetStepCallback(&func_ov001_021782d8);
}

/* Put background planes 0-2 on both engines at the lowest priority, so the
 * screen's sprites and text draw over them. */
void Ov001_LowerBackgroundPriorities(void) {
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

void func_ov001_021782d8(void) {
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_ProfileSavedFadeDone;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&Ov001_ProfileSavedFadeDone);
}

/* Step that runs once the WFC profile-saved popup (message box 0x1F) has faded
 * in: show its icon row (row 5) and hand over to the step that waits for it. */
void Ov001_ProfileSavedFadeDone(void) {
    void Ov001_ProfileSavedWaitIconRow(void);

    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_CreateMenuIconRow(5);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_ProfileSavedWaitIconRow);
}

void Ov001_ProfileSavedWaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_02178360;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02178360);
}

void func_ov001_02178360(void) {
    void func_ov001_02178374(void);
    void func_ov001_02178394(void);
    void func_ov001_02178398(void);
    func_ov001_02178374();
    func_ov001_02178394();
    func_ov001_02178398();
}

void func_ov001_02178374(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(1) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_02178394(void) {

}

void func_ov001_02178398(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void func_ov001_021783c0(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_PlaySound(6);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021783c0);
}

void func_ov001_021783c0(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutScreenToWhite;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutScreenToWhite);
}

/* Once the option menu's fade has settled, fade the sub and main screens out to
 * white over 64 frames and move on to the step that waits for them. */
void Ov001_FadeOutScreenToWhite(void) {
    void Ov001_WaitFadeOutAndWakeDisplay(void);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) return;
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_ALL, 0x40);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_ALL, 0x40);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitFadeOutAndWakeDisplay);
}

/* Final step of the ov001 option-menu fade-to-white flow: wait for the sub then
 * the main screen's fade to finish, then hold the display for a while and let it
 * rest. */
void Ov001_WaitFadeOutAndWakeDisplay(void) {
    M2C_UNK WaitCycles(M2C_UNK);
    M2C_UNK WakeDisplayWait();
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    WaitCycles(0x01000000);
    WakeDisplayWait();
}

void func_ov001_02178460(void) {
    void Ov001_ResetBackgroundPriorities(void);
    extern M2C_UNK Ov001_FadeInWfcEraseMessage;
    Ov001_ResetBackgroundPriorities();
    Ov001_ShowMessageBox(0x1A);
    Ov001_SetStepCallback(&Ov001_FadeInWfcEraseMessage);
}

/* Put background planes 0-2 on both engines at the lowest priority, so the
   message box and sprites of this WFC step draw over them. */
void Ov001_ResetBackgroundPriorities(void) {
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Step that fades the Wi-Fi erase-in-progress message screen in from white on the
 * main engine, reveals its background and sprite planes, then hands over to the
 * step that runs once the fade has finished. */
void Ov001_FadeInWfcEraseMessage(void) {
    extern M2C_UNK Ov001_WfcEraseMessageFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_WfcEraseMessageFadeDone);
}

/* Step that runs once the Wi-Fi erase-in-progress message's fade-in has
 * finished: wait for both engine fades, then put up its icon row and hand over
 * to the step that waits for it to slide in. */
void Ov001_WfcEraseMessageFadeDone(void) {
    void Ov001_WfcEraseMessageWaitIconRow(void);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) return;
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) return;
    Ov001_CreateMenuIconRow(4);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcEraseMessageWaitIconRow);
}

void Ov001_WfcEraseMessageWaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_02178580;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02178580);
}

void func_ov001_02178580(void) {
    void func_ov001_02178594(void);
    void func_ov001_021785b4(void);
    void func_ov001_021785b8(void);
    func_ov001_02178594();
    func_ov001_021785b4();
    func_ov001_021785b8();
}

void func_ov001_02178594(void) {
    if (KeyPressed(1) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_021785b4(void) {

}

void func_ov001_021785b8(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void func_ov001_021785e0(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_PlaySound(6);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021785e0);
}

void func_ov001_021785e0(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutWfcEraseMessage;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutWfcEraseMessage);
}

/* Leave the Wi-Fi erase-in-progress message: once the icon row has settled,
 * slide it out, fade the main screen to white and hand over to the step that
 * closes the message and opens the erase-result screen. */
void Ov001_FadeOutWfcEraseMessage(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern M2C_UNK Ov001_CloseWfcEraseMessage;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_CloseWfcEraseMessage);
}

/* Close the Wi-Fi data-erase screen's message once its fade finishes and its
 * icon row is idle: release the page background, hide the main screen's planes
 * and continue to the erase-result screen. */
void Ov001_CloseWfcEraseMessage(void) {
    s32 Ov001_IsIconRowIdle();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_OpenWfcEraseResultScreen;
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    if (Ov001_IsIconRowIdle() == 0) {
        return;
    }
    Ov001_FreePageBackground(0);
    Ov001_DisableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback(&Ov001_OpenWfcEraseResultScreen);
}

/* Set up the Wi-Fi data-erase screen: load its background and object layout,
 * show its warning panel and info box, and start the fade-in. */
void Ov001_OpenWfcEraseScreen(void) {
    s8 Ov001_ShowMessagePanel(s32, s32, s32);
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    void Ov001_LoadWfcEraseBackground(void);
    void Ov001_FadeInWfcEraseScreen(void);
    extern u8 gOv001WfcEraseConfirmed;
    gOv001WfcEraseConfirmed = 0;
    Ov001_LoadWfcEraseBackground();
    Ov001_LoadObjLayoutBlock(OV001_WFC_ERASE_LAYOUT);
    Ov001_ShowMessagePanel(OV001_MSG_WFC_ERASE, -1, 0);
    Ov001_ShowMessageBox(OV001_MSG_WFC_ERASE_INFO);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInWfcEraseScreen);
}

/* Loads the Wi-Fi erase screen's background map (the shared "Multi" screen)
 * and gives the main and sub background planes the lowest priority. */
void Ov001_LoadWfcEraseBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcEraseBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001WfcEraseBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fade in the Wi-Fi data-erase screen's option panel and screen, show the screen's
 * planes, then wait for the fade in the next step. */
void Ov001_FadeInWfcEraseScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern M2C_UNK Ov001_WfcEraseFadeDone;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&Ov001_WfcEraseFadeDone);
}

/* Step that runs once the Wi-Fi data-erase screen has faded in: put up the
 * screen's icon row (id 3, the back/confirm row) and hand over to the step that
 * waits for the row to slide in. */
void Ov001_WfcEraseFadeDone(void) {
    void Ov001_WfcEraseWaitIconRow(void);

    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_CreateMenuIconRow(3);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcEraseWaitIconRow);
}

void Ov001_WfcEraseWaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK Ov001_UpdateWfcEraseMenu;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateWfcEraseMenu);
}

void Ov001_UpdateWfcEraseMenu(void) {
    void Ov001_HandleWfcEraseMenuInput(void);
    void func_ov001_02178848(void);
    void Ov001_HandleWfcEraseChoice(void);
    Ov001_HandleWfcEraseMenuInput();
    func_ov001_02178848();
    Ov001_HandleWfcEraseChoice();
}

/* Wi-Fi data-erase confirmation input: A latches the confirm choice, B the back
 * choice (the icon row keeps the first choice latched). */
void Ov001_HandleWfcEraseMenuInput(void) {
    if (KeyPressed(KEY_A) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_CONFIRM);
    }
    if (KeyPressed(KEY_B) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_02178848(void) {

}

/* Wi-Fi data-erase screen choice: BACK plays the cancel sound, CONFIRM plays the
 * confirm sound and flags the erase as confirmed; either way the icon row is
 * then locked and the screen starts fading out. */
void Ov001_HandleWfcEraseChoice(void) {
    extern u8 gOv001WfcEraseConfirmed;
    void Ov001_WfcEraseExit(void);
    switch (Ov001_GetIconRowSelection()) {
    case OV001_CHOICE_BACK: Ov001_PlaySound(OV001_SOUND_CANCEL); break;
    case OV001_CHOICE_CONFIRM:
        Ov001_PlaySound(OV001_SOUND_CONFIRM);
        gOv001WfcEraseConfirmed = 1;
        break;
    default: return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcEraseExit);
}

void Ov001_WfcEraseExit(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutWfcEraseScreen;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutWfcEraseScreen);
}

/* Fade the Wi-Fi data-erase screen out once the icon row's selection is locked:
 * slide the icon row out (and fade its own panel too when the erase was not
 * confirmed), fade out the erase screen, and continue to Ov001_CloseWfcEraseScreen. */
void Ov001_FadeOutWfcEraseScreen(void) {
    extern u8 gOv001WfcEraseConfirmed;
    extern M2C_UNK Ov001_CloseWfcEraseScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    if (gOv001WfcEraseConfirmed == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseWfcEraseScreen);
}

/* Close the Wi-Fi data-erase screen once its fades finish and its icon row is
 * idle: a confirmed erase continues to the erase-result screen, while a
 * cancelled one returns to the Wi-Fi option menu (releasing its background and
 * panel too). */
void Ov001_CloseWfcEraseScreen(void) {
    s32 Ov001_IsIconRowIdle();
    extern M2C_UNK Ov001_InitOptionMenu;
    void func_ov001_02178460(void);
    extern u8 gOv001WfcEraseConfirmed;
    if (Ov001_IsFadeActive(0) != 0) return;
    if (gOv001WfcEraseConfirmed == 0 && Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreePageBackground(0);
    if (gOv001WfcEraseConfirmed == 0) {
        Ov001_FreeMessagePanel();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001WfcEraseConfirmed == 0) {
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(&Ov001_InitOptionMenu);
        return;
    }
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02178460);
}

/* Open the Wi-Fi profile-result screen: load its background, show its message box
 * and start the screen's fade-in. */
void Ov001_OpenProfileResultScreen(void) {
    void Ov001_LoadProfileResultBg(void);
    extern s8 gOv001ProfileResultFrames;
    extern M2C_UNK Ov001_FadeInProfileResultScreen;
    gOv001ProfileResultFrames = 0;
    Ov001_LoadProfileResultBg();
    Ov001_ShowMessageBox(OV001_MSG_PROFILE_RESULT);
    Ov001_SetStepCallback(&Ov001_FadeInProfileResultScreen);
}

/* Load the shared Multi map background ("char/yb5Multi.nsc.l") for the WFC
 * profile-result screen and give the background planes the lowest priority so
 * the screen's sprites and text draw over it. */
void Ov001_LoadProfileResultBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001ProfileResultBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001ProfileResultBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fade in the Wi-Fi profile-result screen: fade the main screen from white and
 * reveal its background/OBJ planes, then hand over to the step that waits for
 * the fade and the profile task. */
void Ov001_FadeInProfileResultScreen(void) {
    void Ov001_WaitProfileResultFadeIn(void);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitProfileResultFadeIn);
}

/* Step of the Wi-Fi profile-result screen that waits for its fade-in and for the
 * profile task to finish, then hands over to the step that holds the screen for
 * its delay. */
void Ov001_WaitProfileResultFadeIn(void) {
    s32 Ov001_IsProfileScreenDone();
    extern M2C_UNK Ov001_ProfileResultDelayStep;

    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    if (Ov001_IsProfileScreenDone() == 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_ProfileResultDelayStep);
}

void Ov001_ProfileResultDelayStep(void) {
    void Ov001_TickProfileResultDelay(void);
    void func_ov001_02178ae8(void);
    Ov001_TickProfileResultDelay();
    func_ov001_02178ae8();
}

void func_ov001_02178ae8(void) {

}

/* Fade the sub and main screens out to white, then move on to the step that
 * closes the Wi-Fi profile-result screen. */
void Ov001_FadeOutProfileResultScreen(void) {
    extern M2C_UNK Ov001_CloseProfileResultScreen;
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_CloseProfileResultScreen);
}

/* Close the WFC profile-result screen once its fades have finished: release the
 * result screen's background and panel, lower the visible planes, and return to
 * the Wi-Fi option menu. */
void Ov001_CloseProfileResultScreen(void) {
    M2C_UNK Ov001_FreeMessagePanel();
    extern M2C_UNK Ov001_InitOptionMenu;
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
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback(&Ov001_InitOptionMenu);
}

/* Hold the Wi-Fi profile-result screen for 120 frames: advance its timer once
 * per frame, then hand over to the step that fades the screen out. */
void Ov001_TickProfileResultDelay(void) {
    extern s8 gOv001ProfileResultFrames;
    void Ov001_FadeOutProfileResultScreen(void);
    M2C_FIELD(&gOv001ProfileResultFrames,u8 *,0) = M2C_FIELD(&gOv001ProfileResultFrames,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&gOv001ProfileResultFrames,u8 *,0) < 120U) return;
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeOutProfileResultScreen);
}

/* Open the Wi-Fi profile-return screen: load its background, show its message
 * box and text panel, then start the screen's fade-in. */
void Ov001_OpenProfileReturnScreen(void) {
    s8 Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_LoadProfileReturnBg(void);
    extern s8 gOv001MessageState;
    extern M2C_UNK Ov001_FadeInProfileReturnScreen;
    Ov001_LoadProfileReturnBg();
    Ov001_ShowMessageBox(OV001_MSG_PROFILE_RETURN);
    gOv001MessageState = Ov001_ShowMessagePanel(0x3C, -1, 0);
    Ov001_SetStepCallback(&Ov001_FadeInProfileReturnScreen);
}

/* Reload the shared Multi map background ("char/yb5Multi.nsc.l") when the profile
 * screen is left, and put BG0/BG1/BG2 on the lowest priority on both engines. */
void Ov001_LoadProfileReturnBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001ProfileReturnBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001ProfileReturnBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fade in the profile-return background and, when the message panel is on screen,
 * the message window; then install the step that waits for the fades to finish. */
void Ov001_FadeInProfileReturnScreen(void) {
    extern s8 gOv001MessageState;
    void Ov001_WaitProfileReturnFadeIn(void);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    if ((u8)gOv001MessageState != 0) {
        Ov001_StartFade(2, 1, 1, 8);
        Ov001_EnableVisiblePlanes(1, 1);
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitProfileReturnFadeIn);
}

/* Step that runs once the profile-return screen's fade-in has finished: wait for
 * the sub and main engine fades, then put up the popup's back/confirm icon row and
 * hand over to the step that waits for the row and the profile task. */
void Ov001_WaitProfileReturnFadeIn(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    void Ov001_ProfileReturnWaitIconRow(void);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) return;
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) return;
    Ov001_CreateMenuIconRow(3);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_ProfileReturnWaitIconRow);
}

/* Wait step for the profile-return popup: hold until the icon row has slid in
 * (its selection is past OV001_ICON_ROW_NOT_READY) and the profile task has
 * finished, then unlock the row and hand over to the message-menu step. */
void Ov001_ProfileReturnWaitIconRow(void) {
    void Ov001_UpdateMessageMenu(void);
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    if (Ov001_IsProfileScreenDone() == 0) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_UpdateMessageMenu);
}

void Ov001_UpdateMessageMenu(void) {
    void Ov001_HandleMessageMenuInput(void);
    void func_ov001_02178da0(void);
    void Ov001_MessageChoiceStep(void);
    Ov001_HandleMessageMenuInput();
    func_ov001_02178da0();
    Ov001_MessageChoiceStep();
}

/* Message popup input: A latches the confirm choice, B the back choice (the icon
 * row keeps the first choice latched). */
void Ov001_HandleMessageMenuInput(void) {
    if (KeyPressed(KEY_A) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_CONFIRM);
    }
    if (KeyPressed(KEY_B) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_02178da0(void) {

}

/* Popup step: read the player's choice from the message popup's icon row - the
 * confirm icon records option 1, the back icon option 0, each playing its sound -
 * and move on to lock the choice; an unlatched row does nothing. */
void Ov001_MessageChoiceStep(void) {
    s32 Ov001_GetIconRowSelection(void);
    M2C_UNK Ov001_PlaySound(s32);
    extern s8 gOv001MessageState;
    extern M2C_UNK Ov001_LockMessageChoice;
    switch (Ov001_GetIconRowSelection()) {
    case OV001_CHOICE_CONFIRM:
        M2C_FIELD(&gOv001MessageState, u8 *, OV001_MESSAGE_OPTION) = 1;
        Ov001_PlaySound(OV001_SOUND_CONFIRM);
        break;
    case OV001_CHOICE_BACK:
        M2C_FIELD(&gOv001MessageState, u8 *, OV001_MESSAGE_OPTION) = 0;
        Ov001_PlaySound(OV001_SOUND_CANCEL);
        break;
    default:
        return;
    }
    Ov001_SetStepCallback(&Ov001_LockMessageChoice);
}

void Ov001_LockMessageChoice(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutMessageScreen;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutMessageScreen);
}

/* Fade the Wi-Fi settings screen's two-choice message popup out once the top
 * screen's fade has finished: slide the icon row out (also fading its own panel
 * when the first option was picked), fade out the settings screen, and continue
 * to Ov001_CloseMessageScreen. */
void Ov001_FadeOutMessageScreen(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_StartIconRowSlideOut(void);
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s8 gOv001MessageState;
    extern M2C_UNK Ov001_CloseMessageScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    if (M2C_FIELD(&gOv001MessageState, u8 *, OV001_MESSAGE_OPTION) == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseMessageScreen);
}

