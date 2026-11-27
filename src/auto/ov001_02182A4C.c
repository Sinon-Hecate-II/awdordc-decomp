/* 60 functions from 0x02182A4C to 0x02183A20 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ov001_wh.h"

/* Save-slot menu step: poll its two per-frame input hooks, then - once the message
 * box has answered with its first choice - play the confirm sound, close the box
 * and hand over to the step that fades the menu out towards the WFC connect
 * screen. */
void Ov001_CloseSaveSlotMenuStep(void) {
    void func_ov001_02182a88(void);
    void func_ov001_02182a8c(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    void Ov001_FadeOutSaveSlotMenu(void);

    func_ov001_02182a88();
    func_ov001_02182a8c();
    if (Ov001_GetRegionMenuSelection() != 0) return;
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_CloseRegionMenu();
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeOutSaveSlotMenu);
}

void func_ov001_02182a88(void) {}

void func_ov001_02182a8c(void) {}

/* Save-slot menu fade-out step: wait until the region menu has fully closed, then
 * fade the main screen out to white over its BG2 and OBJ planes and hand over to
 * the step that reveals the Wi-Fi connection screen.  Idle while the region menu
 * is still open. */
void Ov001_FadeOutSaveSlotMenu(void) {
    s32 Ov001_IsRegionMenuActive();
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_WaitWfcConnectFadeOut(void);
    if (Ov001_IsRegionMenuActive() != 0) return;
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitWfcConnectFadeOut);
}

/* Wait for the fade-out of the closing region menu, hide the main engine's BG2 and
 * OBJ planes, ask for the Wi-Fi menu layout with its icon row, then open the Wi-Fi
 * connection screen. */
void Ov001_WaitWfcConnectFadeOut(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_OpenWfcConnectScreen;
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) return;
    Ov001_DisableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetNextScreenMode(0, OV001_SCREEN_CREATE_ICON_ROW);
    Ov001_SetStepCallback(&Ov001_OpenWfcConnectScreen);
}

/* Open the Wi-Fi connection-complete screen: reset its frame counter, load the
 * shared Multi background and the object layout block, show the connection
 * message and play the success chime, then hand over to the fade-in step. */
void Ov001_OpenWfcConnectDoneScreen(void) {
    void Ov001_LoadWfcConnectDoneBg(void);
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_SetStepCallback();
    void Ov001_FadeInWfcConnectDoneScreen(void);
    extern u8 gOv001WfcConnectDoneFrames;
    gOv001WfcConnectDoneFrames = 0;
    Ov001_LoadWfcConnectDoneBg();
    Ov001_LoadObjLayoutBlock(8);
    Ov001_ShowMessageBox(0x29);
    Ov001_PlaySound(OV001_SOUND_SAVED);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInWfcConnectDoneScreen);
}

/* Load the Wi-Fi connect screen's shared Multi background ("char/xb4Multi.nsc.l")
 * for the connection-complete step, and lower BG0/BG1/BG2 on both engines. */
void Ov001_LoadWfcConnectDoneBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcConnectDoneBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001WfcConnectDoneBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fade the Wi-Fi connection-complete message in from white, showing the main
 * screen's BG0/BG2 and sprite planes, then hand over to the step that waits for
 * the fade to finish. */
void Ov001_FadeInWfcConnectDoneScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    void Ov001_WaitWfcConnectDoneFadeIn(void);

    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitWfcConnectDoneFadeIn);
}

/* Step of the WFC connection-done screen: once the main screen's fade-in has
 * finished, hand the screen over to Ov001_UpdateWfcConnectDone. */
void Ov001_WaitWfcConnectDoneFadeIn(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_UpdateWfcConnectDone;

    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_UpdateWfcConnectDone);
}

void Ov001_UpdateWfcConnectDone(void) {
    void Ov001_TickWfcConnectDoneDelay(void);
    void func_ov001_02182c28(void);
    Ov001_TickWfcConnectDoneDelay();
    func_ov001_02182c28();
}

void func_ov001_02182c28(void) {

}

#pragma push
#pragma opt_common_subs off
/* Close the Wi-Fi connection-complete screen: fade both engines out to white
 * (the sub screen's BG0, the main screen's BG0/BG2 and sprites), then hand over
 * to the step that closes the save-name entry. */
void Ov001_CloseWfcConnectDoneScreen(void) {
    void Ov001_CloseSaveNameEntry(void);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_CloseSaveNameEntry);
}

void Ov001_CloseSaveNameEntry(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_FreeMessagePanel(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNameEntryMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_PrepareSaveSlotMenu;

    /* Wait for both screen fades, then clear the name-entry UI and switch to save-slot selection. */
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_FreePageBackground(0);
    Ov001_FreeMessagePanel();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetNameEntryMode(0, 2);
    Ov001_SetStepCallback(&Ov001_PrepareSaveSlotMenu);
}
#pragma pop
/* Count the ticks the ov001 Wi-Fi connection-complete screen has waited: once
 * the message has been up for OV001_WFC_CONNECT_DONE_FRAMES, hand over to the
 * step that fades the screen out to white. */
void Ov001_TickWfcConnectDoneDelay(void) {
    extern u8 gOv001WfcConnectDoneFrames;
    gOv001WfcConnectDoneFrames = gOv001WfcConnectDoneFrames + 1;
    if ((u32)gOv001WfcConnectDoneFrames < OV001_WFC_CONNECT_DONE_FRAMES) return;
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_CloseWfcConnectDoneScreen);
}

/* Open the WFC connection screen's second step: clear the connection choice, load
 * the step's background, object layout block, message panel and menu, show its
 * message box, then hand over to the step's fade-in. */
void Ov001_OpenWfcConnectStep2Screen(void) {
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_OpenMenuForMode(M2C_UNK);
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_LoadWfcConnectStep2Bg(void);
    void Ov001_FadeInWfcConnectStep2(void);
    extern u8 gOv001WfcConnectChosen;
    gOv001WfcConnectChosen = 0;
    Ov001_LoadWfcConnectStep2Bg();
    Ov001_LoadObjLayoutBlock(8);
    Ov001_ShowMessagePanel(0x38, -1, 0);
    Ov001_OpenMenuForMode(1);
    Ov001_ShowMessageBox(0x27);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInWfcConnectStep2);
}

/* Loads the WFC connection screen's step 2 background: tile graphics, palette
 * and the shared multiplayer map, then puts BG0/BG1 on the lowest priority. */
void Ov001_LoadWfcConnectStep2Bg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcConnectStep2BgTilesPath, gOv001WfcConnectStep2BgPalettePath, gOv001WfcConnectStep2BgMapPath;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001WfcConnectStep2BgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001WfcConnectStep2BgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001WfcConnectStep2BgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

/* Fade the WFC connection screen's second step in from white and show its planes:
 * the sub screen blends BG0, the main screen BG0/BG2 and the sprites. */
void Ov001_FadeInWfcConnectStep2(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_WaitWfcConnectStep2FadeIn(void);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, OV001_BLEND_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitWfcConnectStep2FadeIn);
}

/* Wait for the WFC connect screen's step-2 fade-in to finish on both engines,
 * then bring in the screen's back/confirm icon row and hand over to the step
 * that watches the row. */
void Ov001_WaitWfcConnectStep2FadeIn(void) {
    extern M2C_UNK Ov001_WaitWfcConnectIconRow;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_CreateMenuIconRow(OV001_ICON_ROW_WFC_CONNECT);
    Ov001_SetStepCallback(&Ov001_WaitWfcConnectIconRow);
}

#pragma push
#pragma opt_common_subs off
/* Step that runs while the Wi-Fi connect screen's icon row slides in: once the
 * row takes input (its selection is no longer OV001_ICON_ROW_NOT_READY), unlock
 * it and hand over to the step that handles the connect menu's choices. */
void Ov001_WaitWfcConnectIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK Ov001_WfcConnectIconRowStep;
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) return;
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_WfcConnectIconRowStep);
}
void Ov001_WfcConnectIconRowStep(void) {
 void Ov001_HandleWfcConnectMenuInput(void);
 void func_ov001_02182f08(void);
 void Ov001_ApplyWfcMenuSelection(void);
 Ov001_HandleWfcConnectMenuInput();
 func_ov001_02182f08();
 Ov001_ApplyWfcMenuSelection();
}

/* WFC connect menu input step: A latches the confirm choice, B the back
 * choice, for the icon row the screen is showing. */
void Ov001_HandleWfcConnectMenuInput(void) {
    if (KeyPressed(KEY_A) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_CONFIRM);
    }
    if (KeyPressed(KEY_B) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_02182f08(void) {

}

/* Apply the icon-row choice on the Wi-Fi menu: leaving without connecting plays
 * the cancel sound, choosing to connect marks the choice and plays the confirm
 * sound; either way the menu moves on to its close.  A selection of -2 (nothing
 * chosen) is ignored. */
void Ov001_ApplyWfcMenuSelection(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern u8 gOv001WfcConnectChosen;
    void Ov001_PrepareCloseWfcMenu(void);

    switch (Ov001_GetIconRowSelection()) {
    case 0: Ov001_PlaySound(OV001_SOUND_CANCEL); break;
    case 1:
        Ov001_PlaySound(OV001_SOUND_CONFIRM);
        gOv001WfcConnectChosen = 1;
        break;
    default: return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_PrepareCloseWfcMenu);
}

/* WFC menu close step: stop the icon row from taking input, hold the screen for
 * OV001_STEP_DELAY_FRAMES, then hand over to Ov001_StartCloseWfcMenu. */
void Ov001_PrepareCloseWfcMenu(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_StartCloseWfcMenu;

    Ov001_LockIconRow();
    Ov001_StartDelay(OV001_STEP_DELAY_FRAMES);
    Ov001_SetStepCallback(&Ov001_StartCloseWfcMenu);
}

/* WFC menu closing step: wait for the top-screen fade to finish, slide the icon
   row out, fade both screens out (the top screen only when the player did not
   choose to connect to Nintendo WFC) and move on to Ov001_CloseWfcMenuScreen. */
void Ov001_StartCloseWfcMenu(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern u8 gOv001WfcConnectChosen;
    extern M2C_UNK Ov001_CloseWfcMenuScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    if (gOv001WfcConnectChosen == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseWfcMenuScreen);
}

/* Last step of the Nintendo WFC menu screen: once the fades finish, free the
 * screen's backgrounds and hand over to the next screen's step callback, the
 * access-point menu, or the WFC connection screen when the player chose to
 * connect to Nintendo WFC. */
void Ov001_CloseWfcMenuScreen(void) {
    s32 Ov001_IsIconRowIdle();
    M2C_UNK Ov001_FreeMessagePanel();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001WfcConnectChosen;
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    extern M2C_UNK Ov001_OpenUsbConnectScreen;
    if (Ov001_IsFadeActive(0) != 0) return;
    if (gOv001WfcConnectChosen == 0 && Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreePageBackground(0);
    if (gOv001WfcConnectChosen == 0) {
        Ov001_FreeMessagePanel();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001WfcConnectChosen == 0) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);
        return;
    }
    Ov001_SetNextScreenMode(2, 1);
    Ov001_SetStepCallback(&Ov001_OpenUsbConnectScreen);
}

/* Whether the console's lid is closed: the Wi-Fi connection-wait screen treats a
 * closed lid like a B press and backs out of the connection. */
s32 Ov001_IsLidClosedForConnectionWait(void) {
    if (((s32)(*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

/* Open the Wi-Fi connect screen: load the Nintendo USB connector's background
 * and the menu, copy the player's nickname out of the system user profile (the
 * profile sits at +0x16, its nickname text at +4 and length at +0x1a) and show
 * the message that names the player, then start the WFC connection and move to
 * the fade-out step that closes the screen. */
void Ov001_OpenUsbConnectScreen(void) {
    M2C_UNK GetSystemUserProfile(u8 *);
    M2C_UNK FillU16(M2C_UNK, u8 *, s32);
    M2C_UNK CopyU16(u8 *, u8 *, s32);
    M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
    M2C_UNK Ov001_OpenMenuForMode(M2C_UNK);
    M2C_UNK Ov001_ShowMessageWithName(u8 *, M2C_UNK);
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_LoadUsbConnectBg(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_ConnectToWfcServer(M2C_UNK *);
    extern u8 gOv001WfcScreenState;
    extern M2C_UNK Ov001_HandleConnectionStatus;
    extern M2C_UNK Ov001_FadeInUsbConnectScreen;
    u8 nameBuffer[0x6C];

    gOv001WfcScreenState = 0;
    Ov001_LoadUsbConnectBg();
    Ov001_LoadObjLayoutBlock(8);
    Ov001_OpenMenuForMode(2);
    GetSystemUserProfile(&nameBuffer[0x16]);
    FillU16(0, &nameBuffer[0], 0x16);
    CopyU16(&nameBuffer[0x1A], &nameBuffer[0], M2C_FIELD(nameBuffer, u16 *, 0x30) * 2);
    Ov001_ShowMessageWithName(&nameBuffer[0], 0x28);
    Ov001_CreateAnimSprite(0);
    Ov001_ConnectToWfcServer((M2C_UNK *) &Ov001_HandleConnectionStatus);
    Ov001_PlaySound(0xB);
    Ov001_SetStepCallback(&Ov001_FadeInUsbConnectScreen);
}

/* Loads the background of the screen that connects to WFC through the Nintendo
 * USB connector: step 3 tile graphics, palette and the USB map, then puts
 * BG0/BG1 on the lowest priority. */
void Ov001_LoadUsbConnectBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001UsbConnectBgTilesPath, gOv001UsbConnectBgPalettePath, gOv001UsbConnectBgMapPath;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001UsbConnectBgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001UsbConnectBgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001UsbConnectBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

/* Fade in the Nintendo USB-connector WFC connect screen from white and show its
 * planes (the main screen's BG0, BG2 and sprites), then hand over to the step
 * that shows the screen's icon row. */
void Ov001_FadeInUsbConnectScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern M2C_UNK Ov001_UsbConnectFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_UsbConnectFadeDone);
}

/* Step that runs once the USB-connector Wi-Fi connect screen has faded in: put
 * up the screen's icon row (id 2, the single-icon row holding only the back
 * icon) and hand over to the step that waits for the row to slide in. */
void Ov001_UsbConnectFadeDone(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    extern M2C_UNK Ov001_UsbConnectWaitIconRow;

    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_CreateMenuIconRow(2);
    Ov001_SetStepCallback(&Ov001_UsbConnectWaitIconRow);
}

/* Step that runs while the USB-connector Wi-Fi connect screen's icon row slides
 * in: once the row takes input (its selection is no longer
 * OV001_ICON_ROW_NOT_READY), unlock it and hand over to the step that waits for
 * the connection status. */
void Ov001_UsbConnectWaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern M2C_UNK Ov001_UpdateConnectionWait;
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) return;
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateConnectionWait);
}

void Ov001_UpdateConnectionWait(void) {
    void Ov001_HandleConnectionWaitInput(void);
    void func_ov001_021832c8(void);
    void Ov001_CancelConnectionWait(void);
    Ov001_HandleConnectionWaitInput();
    func_ov001_021832c8();
    Ov001_CancelConnectionWait();
}

/* Wi-Fi connection-wait screen input: B latches the icon row's only choice, the
 * back icon, and so does closing the console's lid. */
void Ov001_HandleConnectionWaitInput(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(KEY_B) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
        return;
    }
    if (Ov001_IsLidClosedForConnectionWait() == 0) return;
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_021832c8(void) {

}

/* Runs each frame while the Wi-Fi connection is being waited on: nothing has
 * been reported and the player tapped the icon row's back icon, so give up on
 * the connection, mark it lost and hand over to the closing step. */
void Ov001_CancelConnectionWait(void) {
    void Ov001_StartConnectionClose(void);
    extern u8 gOv001WfcScreenState;
    M2C_UNK Ov001_StopSound();
    if (gOv001WfcScreenState) {
        return;
    }
    if (Ov001_GetIconRowSelection() != OV001_CHOICE_BACK) {
        return;
    }
    gOv001WfcScreenState = OV001_WFC_SCREEN_DISCONNECTED;
    Ov001_StopSound();
    Ov001_PlaySound(OV001_SOUND_CANCEL);
    Ov001_SetStepCallback((M2C_UNK *) &Ov001_StartConnectionClose);
}

/* Wi-Fi connection screen exit step: hold the icon row for a short delay, then
 * fade the connection screen out. */
void Ov001_StartConnectionClose(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_StartConnectionFadeOut;
    Ov001_LockIconRow();
    Ov001_StartDelay(OV001_STEP_DELAY_FRAMES);
    Ov001_SetStepCallback(&Ov001_StartConnectionFadeOut);
}

/* Fade the Wi-Fi connection screen out: slide the icon row away and fade both
 * engines; the sub engine only fades when its status message is up, that is
 * when the connection was lost or nobody joined. */
void Ov001_StartConnectionFadeOut(void) {
    extern u8 gOv001WfcScreenState;
    extern M2C_UNK Ov001_CloseConnectionScreen;
    M2C_UNK Ov001_StartIconRowSlideOut();

    if (Ov001_IsFadeActive(OV001_FADE_SUB)) return;
    Ov001_StartIconRowSlideOut();
    /* Adding 254 is subtracting 2 in 8 bits: only states 2 and 3 pass. */
    if ((u8)(gOv001WfcScreenState + 254) <= 1) {
        Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN,
                    OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_CloseConnectionScreen);
}

/* Sets up the overlay 001 mode based on the selected slot/state, runs init hooks, then schedules render callbacks. */
void Ov001_CloseConnectionScreen(void) {
    M2C_UNK Ov001_FreeOptionSprites(void);
    s32 Ov001_IsIconRowIdle(void);
    M2C_UNK Ov001_FreeMessagePanel(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    void func_ov001_02185dac(void);
    extern u8 gOv001WfcScreenState;
    extern void Ov001_OpenAccessPointMenu(void);
    extern void Ov001_OpenWfcConnectStep2Screen(void);
    extern void Ov001_OpenWfcConnectDoneScreen(void);

    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    if ((gOv001WfcScreenState == 2) && (Ov001_IsFadeActive(1) != 0)) {
        return;
    }
    if (Ov001_IsIconRowIdle() == 0) {
        return;
    }
    func_ov001_02185dac();
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (gOv001WfcScreenState == 2 || gOv001WfcScreenState == 3) {
        Ov001_FreeMessagePanel();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001WfcScreenState == 2) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenAccessPointMenu);
        return;
    }
    if (gOv001WfcScreenState == 3) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWfcConnectStep2Screen);
        return;
    }
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWfcConnectDoneScreen);
}

/* Connection-status callback of the Wi-Fi screen: while no screen has been
 * picked yet, the watch's status (0 = no player on the connection, 1 = every
 * player online, 2 = some offline, 3 = the connection was lost) selects the
 * sound, message box and step callback of the screen that follows.  A second
 * report is ignored and leaves the picked screen alone. */
M2C_UNK Ov001_HandleConnectionStatus(M2C_UNK status) {
    M2C_UNK Ov001_StopSound(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Ov001_LockIconRow();
    void Ov001_SetConnectionStatusCallback(s32);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern u8 gOv001WfcScreenState;
    void Ov001_ConfirmNoPlayersMessage(void);
    void Ov001_StartConnectionClose(void);
    void Ov001_ConnectionChoiceStep(void);

    if (gOv001WfcScreenState != 0) {
        return status;
    }
    switch (status) {
    case 0:
        gOv001WfcScreenState = 3;
        Ov001_StopSound();
        Ov001_PlaySound(0x12);
        Ov001_ShowMessage(0x10, 1, 1, -1, 0);
        Ov001_LockIconRow();
        return Ov001_SetStepCallback((M2C_UNK *)&Ov001_ConfirmNoPlayersMessage);
    case 1:
        gOv001WfcScreenState = 1;
        Ov001_StopSound();
        return Ov001_SetStepCallback((M2C_UNK *)&Ov001_StartConnectionClose);
    case 2:
        Ov001_StopSound();
        Ov001_SetConnectionStatusCallback(0);
        Ov001_ShowMessage(0x11, 0, 1, -1, 0);
        Ov001_LockIconRow();
        return Ov001_SetStepCallback((M2C_UNK *)&Ov001_ConnectionChoiceStep);
    case 3:
        gOv001WfcScreenState = 2;
        Ov001_StopSound();
        Ov001_PlaySound(9);
        return Ov001_SetStepCallback((M2C_UNK *)&Ov001_StartConnectionClose);
    }
    return status;
}

/* "No players joined" message on the Wi-Fi connection screen: when the player
 * confirms it (option 0), play the confirm sound, close the box and hand over to
 * the step that waits for it to go and then closes the connection. */
void Ov001_ConfirmNoPlayersMessage(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK Ov001_CloseEmptyRegionMessage;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_CloseEmptyRegionMessage);
}

/* After the empty-region message closes, start closing the connection screen. */
void Ov001_CloseEmptyRegionMessage(void) {
    s32 Ov001_IsRegionMenuActive();
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_StartConnectionClose);
}

/* Step that handles the player's answer to the Wi-Fi connection status message:
 * the two-option menu reports option 1 as "no players" and option 0 as
 * "connected" (with a sound each); any other value means the menu is still open.
 * The menu is then closed and the step resumes waiting for the connection. */
void Ov001_ConnectionChoiceStep(void) {
    void Ov001_ResumeConnectionWait(void);
    extern u8 gOv001WfcScreenState;

    switch (Ov001_GetRegionMenuSelection()) {
    case 1:
        gOv001WfcScreenState = OV001_WFC_SCREEN_NO_PLAYERS;
        Ov001_PlaySound(6);
        break;
    case 0:
        gOv001WfcScreenState = OV001_WFC_SCREEN_CONNECTED;
        Ov001_PlaySound(7);
        break;
    default:
        return;
    }
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_ResumeConnectionWait);
}

/* Step after the region menu closes on the Wi-Fi connection screen: when the
   connection is already complete, go straight to the screen's closing step;
   otherwise re-arm the connection status callback and go back to the step that
   waits for the other players. */
void Ov001_ResumeConnectionWait(void) {
    M2C_UNK Ov001_UnlockIconRow();
    void Ov001_SetConnectionStatusCallback(s32);
    extern u8 gOv001WfcScreenState;
    void Ov001_UpdateConnectionWait(void);
          M2C_UNK Ov001_HandleConnectionStatus(M2C_UNK);
      if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    if (gOv001WfcScreenState == OV001_WFC_SCREEN_CONNECTED) {
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_StartConnectionClose);
        return;
    }
    Ov001_PlaySound(0xB);
    Ov001_UnlockIconRow();
    gOv001WfcScreenState = OV001_WFC_SCREEN_NONE;
    Ov001_SetConnectionStatusCallback((M2C_UNK)&Ov001_HandleConnectionStatus);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_UpdateConnectionWait);
}

/* Allocate the ov001 map-preview buffer, copy the given 32x24 tilemap into it
 * and start the task that flushes the tilemap to BG2. */
void InitMapPreview(void *tilemap) {
    extern void *gOv001MapPreview;
    void *Ov001_Alloc(s32, s32);
    void MI_CpuCopy32(void *, void *, s32);
    s32 Ov001_AddTask(s32, void (*)(), s32, s32);
    void FlushMapPreview(void);
    Ov001MapPreview *preview = Ov001_Alloc(sizeof(Ov001MapPreview), 4);
    gOv001MapPreview = preview;
    MI_CpuCopy32(tilemap, preview->tiles, 0x600);
    M2C_FIELD(gOv001MapPreview, s32 *, 0) = Ov001_AddTask(1, FlushMapPreview, 0, 120);
}

#pragma opt_propagation off
/* Free the map preview: give back the task that flushes its tilemap to BG2, then
 * free the preview object and clear its pointer.  The object is spelled through
 * gOv001Scrollbar, three pointer slots after it, so the literal pool keeps two
 * equal address words the way the original does. */
void FreeMapPreview(void) {
    extern void *gOv001MapPreview;
    extern void *gOv001Scrollbar;
    void Ov001_ReturnTaskNodeVeneer(s32, s32);
    void Ov001_FreeAlloc(void *);
    Ov001_ReturnTaskNodeVeneer(1, *(s32 *)*(s32 *)&gOv001MapPreview);
    Ov001_FreeAlloc(&gOv001Scrollbar - 3);
}
#pragma opt_propagation reset
/* Mark the ov001 map preview's tilemap as needing a flush to BG2, which the
 * preview's task then does on its next run. */
void RequestMapPreviewUpdate(void) {
    extern void *gOv001MapPreview;

    ((Ov001MapPreview *)gOv001MapPreview)->dirty = 1;
}

/* Copy `rowCount` rows of `wordsPerRow` u16 tiles from a source tilemap into the
 * map preview's BG2 tilemap, starting at tile column `destColumn`; both tilemaps
 * advance one 32-tile row (64 bytes) per row. */
void CopyMapPreviewRows(void *source, s32 destColumn, s32 wordsPerRow, s32 rowCount) {
    extern void *gOv001MapPreview;
    u8 *src = source;
    u8 *dst = (u8 *)((Ov001MapPreview *)gOv001MapPreview)->tiles + destColumn * 2;
    s32 i;

    for (i = 0; i < rowCount; i++) {
        CopyU16(src, dst, wordsPerRow * 2);
        src += 64;
        dst += 64;
    }
}

/* Flush the ov001 map preview's dirty BG2 tilemap: clean it out of the data
 * cache, load it into BG2, then clear the dirty flag. */
void FlushMapPreview(void) {
    extern void *gOv001MapPreview;
    void DC_FlushRange();
    void GX_LoadBG2Scr();
    if (!((Ov001MapPreview *)gOv001MapPreview)->dirty) return;
    DC_FlushRange(((Ov001MapPreview *)gOv001MapPreview)->tiles, sizeof(((Ov001MapPreview *)gOv001MapPreview)->tiles));
    GX_LoadBG2Scr(((Ov001MapPreview *)gOv001MapPreview)->tiles, 0, sizeof(((Ov001MapPreview *)gOv001MapPreview)->tiles));
    ((Ov001MapPreview *)gOv001MapPreview)->dirty = 0;
}

/* Queue a 32-byte OBJ tile copy from `sourceAddress` to the selected OBJ VRAM tile. */
void Ov001_LoadObjTile(s32 sourceAddress, s32 sourceTile, s32 destinationTile) {
    extern void *gOv001MapPreview;
    void Ov001_CopyObjTileTask(s32);
    s32 Ov001_AddTask(s32, void (*)(), s32, s32);

    M2C_FIELD(&gOv001MapPreview, s32 *, 4) = sourceAddress + (sourceTile << 5);
    M2C_FIELD(&gOv001MapPreview, s32 *, 8) = (destinationTile << 5) + 0x5000000;
    Ov001_AddTask(1, Ov001_CopyObjTileTask, 0, 0x78);
}

/* Task that copies the OBJ tile staged in gOv001MapPreview (its source and
 * destination VRAM addresses) and posts the finished task back to task group 1. */
void Ov001_CopyObjTileTask(s32 task) {
    extern void *gOv001MapPreview;
    M2C_UNK CopyU16(void *, void *, s32);
    void Ov001_PostTaskMessage(s32, s32);

    CopyU16(M2C_FIELD(&gOv001MapPreview, s32 *, OV001_MAP_PREVIEW_COPY_SOURCE),
            M2C_FIELD(&gOv001MapPreview, s32 *, OV001_MAP_PREVIEW_COPY_DEST),
            OV001_MAP_PREVIEW_COPY_WORDS);
    Ov001_PostTaskMessage(1, task);
}

/* Queue a copy of the main-screen palette set at `paletteSource` into main
 * palette RAM: stage the source address in the map-preview buffer and start the
 * task that copies it there. */
void Ov001_LoadMainPalette(s32 paletteSource) {
    extern void *gOv001MapPreview;
    void Ov001_LoadMainPaletteTask();
    s32 Ov001_AddTask(s32, void (*)(), s32, s32);
    M2C_FIELD(&gOv001MapPreview, s32 *, 4) = paletteSource;
    Ov001_AddTask(1, Ov001_LoadMainPaletteTask, 0, 0x78);
}

/* Task that copies the main palette set staged at gOv001MapPreview+4 into the
 * main engine's palette RAM, then posts the task's done message. */
void Ov001_LoadMainPaletteTask(s32 task) {
    extern void *gOv001MapPreview;
    CopyU16(M2C_FIELD(&gOv001MapPreview, s32 *, 4), GX_MAIN_PALETTE_BASE, GX_PALETTE_SIZE / 2);
    Ov001_PostTaskMessage(1, task);
}

/* Build the ov001 friend-roster screen's vertical scroll bar: allocate its
 * 0x20-byte state, place and palettise its sprite at (x, y), and start the
 * task that drives it.  kind picks the bar sprite, track its length in pixels
 * and handlePos the starting handle offset. */
void Ov001_CreateScrollBar(s32 kind, s32 track, s32 x, s32 y, s32 handlePos) {
    extern void *gOv001Scrollbar;
    extern u8 gOv001ScrollBarSpriteIds[];
    void *Ov001_Alloc(s32, s32);
    void func_ov001_0218b2bc(s32, s32, void *);
    M2C_UNK Ov001_CreateSprite(M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_MoveSpriteLayout(M2C_UNK, s32, s32, s32);
    void Ov001_SetSpritePalette(M2C_UNK, s32, s32);
    s32 Ov001_AddTask(s32, void (*)(), s32, s32);
    void func_ov001_02183a20(void);

    void *p;
    M2C_UNK t;

    p = Ov001_Alloc(0x20, 0x4);
    gOv001Scrollbar = p;
    *(u8 *)((char *)p + OV001_SCROLLBAR_KIND) = (u8)kind;
    *(u8 *)((char *)gOv001Scrollbar + OV001_SCROLLBAR_TRACK) = (u8)track;
    *(u8 *)((char *)gOv001Scrollbar + OV001_SCROLLBAR_HANDLE_POS) = (u8)handlePos;
    func_ov001_0218b2bc(x, y, (char *)gOv001Scrollbar + OV001_SCROLLBAR_X);
    t = Ov001_CreateSprite(0, gOv001ScrollBarSpriteIds[kind], 1);
    *(M2C_UNK *)gOv001Scrollbar = t;
    Ov001_MoveSpriteLayout(*(M2C_UNK *)gOv001Scrollbar, -1, x, y + handlePos);
    Ov001_SetSpritePalette(*(M2C_UNK *)gOv001Scrollbar, -1, 1);
    *(M2C_UNK *)((char *)gOv001Scrollbar + OV001_SCROLLBAR_TASK) = Ov001_AddTask(0, func_ov001_02183a20, 0, 0x80);
}

/* Tear down the friend-roster screen's scroll bar: give back its update task,
 * destroy the bar sprite and free the bar object (and clear its pointer). */
void Ov001_DestroyScrollBar(void) {
    extern void *gOv001Scrollbar;
    extern void *gWfcFriendRoster;
    void Ov001_ReturnTaskNodeVeneer(s32, s32);
    void Ov001_FreeAlloc(void *);
    Ov001_ReturnTaskNodeVeneer(0, M2C_FIELD(gOv001Scrollbar, s32 *, OV001_SCROLLBAR_TASK));
    Ov001_DestroySprite(M2C_FIELD(gOv001Scrollbar, s32 *, OV001_SCROLLBAR_SPRITE));
    /* The bar object sits just before gWfcFriendRoster; spelled through it so the
     * literal pool keeps two address words, as the original does. */
    Ov001_FreeAlloc(&gWfcFriendRoster - 1);
}

u8 GetMenuRow(void) {
    extern void *gOv001Scrollbar;
    return M2C_FIELD(gOv001Scrollbar, u8 *, 0x1A);
}

u8 GetMenuState(void){extern void *gOv001Scrollbar;return M2C_FIELD(gOv001Scrollbar,u8 *,29);}

void Ov001_UpdateScrollbarHandle(void) { M2C_UNK Ov001_SetScrollbarHandlePos(); Ov001_SetScrollbarHandlePos(); }

/* Clear the ov001 friend-roster scroll bar's blocked flag so its update task
 * starts handling touches again. */
void Ov001_UnblockScrollBar(void) {
    extern void *gOv001Scrollbar;

    M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_BLOCKED) = 0;
}

/* Set the ov001 friend-roster scroll bar's blocked flag so its update task leaves
 * the bar alone (e.g. while a selection is latched). */
void Ov001_BlockScrollBar(void) {
    extern void *gOv001Scrollbar;

    M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_BLOCKED) = 1;
}

