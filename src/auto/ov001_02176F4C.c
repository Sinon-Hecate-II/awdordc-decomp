/* 48 functions from 0x02176F4C to 0x02177F1C (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ov001_wh.h"
#include "wfc.h"
typedef struct { u8 bytes[22]; } MenuBuf22;
typedef struct { u8 bytes[23]; } MenuBuf23;

/* The 20-byte profile GetWfcProfile fills in; value is nonzero when a Wi-Fi
 * connection profile has been registered. */
typedef struct { u64 value; u32 rest[3]; } WfcProfile;

/* State shared by the ov001 option-menu step functions. */
typedef struct {
    u8 selected;       /* +0x00 selected option, 0..2 */
    u8 paletteLoaded;  /* +0x01 nonzero once the option palette was chosen */
    u8 pad02[2];
    void *palette;     /* +0x04 loaded palette-file (NCL) data */
    void *sprite;      /* +0x08 OBJ handle for the selection cursor */
} Ov001OptionMenuState;

/* Palette file layout of the option screen background. */
#define OV001_PALETTE_NO_PROFILE 0x40  /* colours used when no WFC profile exists */
#define OV001_PALETTE_PROFILE    0xC0  /* colours replaced when none exists */
#define OV001_PALETTE_SIZE       0x200 /* bytes uploaded to palette RAM */

/* Step after the Wi-Fi settings screen's fade-in: once both its fades have
 * finished, open the screen's three-icon row and hand over to the step that
 * enables menu input. */
void Ov001_WaitWfcSettingsFadeIn(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    void Ov001_EnableWfcSettingsMenuInput(void);
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_CreateMenuIconRow(3);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_EnableWfcSettingsMenuInput);
}

/* Wi-Fi settings screen step after its icon row opened: wait for the row's
 * selection to become available, unlock it and hand over to the row's per-frame
 * input update. */
void Ov001_EnableWfcSettingsMenuInput(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    void Ov001_UpdateWfcSettingsMenu(void);
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) return;
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_UpdateWfcSettingsMenu);
}

void Ov001_UpdateWfcSettingsMenu(void) {
    void Ov001_HandleWfcSettingsMenuInput(void);
    void func_ov001_02176ffc(void);
    void Ov001_HandleWfcSettingsChoice(void);
    Ov001_HandleWfcSettingsMenuInput();
    func_ov001_02176ffc();
    Ov001_HandleWfcSettingsChoice();
}

/* Wi-Fi settings screen input: A latches the confirm choice, B the back choice
 * (the icon row keeps the first choice latched). */
void Ov001_HandleWfcSettingsMenuInput(void) {
    if (KeyPressed(KEY_A) != 0) {
        Ov001_LatchIconRowSelection(OV001_CHOICE_CONFIRM);
    }
    if (KeyPressed(KEY_B) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(OV001_CHOICE_BACK);
}

void func_ov001_02176ffc(void) {

}

/* WFC-settings screen choice: BACK locks the row and closes the screen without
 * changes; CONFIRM plays the confirm sound, shows message 0x18 and opens the
 * region-selection menu. */
void Ov001_HandleWfcSettingsChoice(void) {
    void Ov001_WfcSettingsExit(void);
    void Ov001_WfcSettingsRegionChoiceStep(void);
    s32 choice;
    choice = Ov001_GetIconRowSelection();
    switch (choice) {
    case OV001_CHOICE_BACK:
        Ov001_PlaySound(OV001_SOUND_CANCEL);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcSettingsExit);
        return;
    case OV001_CHOICE_CONFIRM:
        Ov001_PlaySound(OV001_SOUND_CONFIRM);
        Ov001_ShowMessage(0x18, 0, 1, -1, 0);
        Ov001_LockIconRow();
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcSettingsRegionChoiceStep);
        return;
    }
}

void Ov001_WfcSettingsExit(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutWfcSettings;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutWfcSettings);
}

/* Fade out the Wi-Fi settings screen: wait for the icon row's fade-in, slide the
 * row out, start the screen fades (keeping the option background when the player
 * chose to reset the WFC settings), then move on to closing the screen. */
void Ov001_FadeOutWfcSettings(void) {
    extern u8 gOv001WfcSettingsReset;
    extern M2C_UNK Ov001_CloseWfcSettingsScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    if (gOv001WfcSettingsReset == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseWfcSettingsScreen);
}

/* Close the Wi-Fi settings screen once its fades finish and its icon row is
 * idle: when the player confirmed resetting the WFC settings it goes on to the
 * reset screen, otherwise it returns to the Wi-Fi option menu (releasing its
 * background and panel too). */
void Ov001_CloseWfcSettingsScreen(void) {
    s32 Ov001_IsIconRowIdle();
    extern M2C_UNK Ov001_InitOptionMenu;
    void func_ov001_02177214(void);
    extern u8 gOv001WfcSettingsReset;
    if (Ov001_IsFadeActive(0) != 0) return;
    if (gOv001WfcSettingsReset == 0 && Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreePageBackground(0);
    if (gOv001WfcSettingsReset == 0) {
        Ov001_FreeMessagePanel();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001WfcSettingsReset == 0) {
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(&Ov001_InitOptionMenu);
        return;
    }
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177214);
}

/* WFC-settings screen step after its popup opened: read the region menu's answer
 * (1 = reset the WFC settings, 0 = cancel) and play the matching sound, then
 * close the popup and wait for it to finish closing. */
void Ov001_WfcSettingsRegionChoiceStep(void) {
    void Ov001_WfcSettingsRegionClosed(void);
    extern u8 gOv001WfcSettingsReset;
    s32 choice;
    choice = Ov001_GetRegionMenuSelection();
    switch (choice) {
    case 1:
        Ov001_PlaySound(0xE);
        gOv001WfcSettingsReset = 1;
        break;
    case 0:
        Ov001_PlaySound(OV001_SOUND_CANCEL);
        break;
    default: return;
    }
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcSettingsRegionClosed);
}

void Ov001_WfcSettingsRegionClosed(void) {
    s32 Ov001_IsRegionMenuActive();
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcSettingsExit);
}

void func_ov001_02177214(void) {
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    void Ov001_LoadResetProfileBg(void);
    M2C_UNK ResetSaveSlotsWithWfcProfile();
    extern M2C_UNK Ov001_FadeInResetProfileScreen;
    Ov001_LoadResetProfileBg();
    Ov001_ShowMessageBox(0x19);
    ResetSaveSlotsWithWfcProfile();
    Ov001_SetStepCallback(&Ov001_FadeInResetProfileScreen);
}

/* Load the shared Multi map background ("char/yb5Multi.nsc.l") for the option
 * menu's reset-profile step, and lower BG0/BG1/BG2 on both engines. */
void Ov001_LoadResetProfileBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001ResetProfileBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001ResetProfileBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fade the WFC-profile reset screen in from white on the main engine and show
 * its background and object planes, then hand over to the step that opens its
 * icon row. */
void Ov001_FadeInResetProfileScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_ResetProfileFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback(&Ov001_ResetProfileFadeDone);
}

/* Step that runs after the WFC-profile reset screen has faded in: show its
 * popup icon row (row 5) and hand over to the step that waits for it. */
void Ov001_ResetProfileFadeDone(void) {
    void Ov001_WaitResetProfileMenu(void);

    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_CreateMenuIconRow(5);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitResetProfileMenu);
}

/* Step that runs once the WFC-profile reset screen's icon row is up: wait for
 * the row's selection to become available, unlock it and hand over to the row's
 * per-frame input update. */
void Ov001_WaitResetProfileMenu(void) {
    extern M2C_UNK Ov001_UpdateResetProfileMenu;

    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateResetProfileMenu);
}

void Ov001_UpdateResetProfileMenu(void) {
    void func_ov001_02177354(void);
    void func_ov001_02177374(void);
    void Ov001_HandleResetProfileMenuChoice(void);
    func_ov001_02177354();
    func_ov001_02177374();
    Ov001_HandleResetProfileMenuChoice();
}

void func_ov001_02177354(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(1) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_02177374(void) {

}

/* WFC-profile reset screen: its single icon-row choice (0) is the confirm
 * action, so play the confirm sound and move on to the step that locks the row
 * and fades to white. */
void Ov001_HandleResetProfileMenuChoice(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void Ov001_CloseResetProfileMenu(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_CloseResetProfileMenu);
}

void Ov001_CloseResetProfileMenu(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_ResetProfileFadeToWhite;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_ResetProfileFadeToWhite);
}

/* Final step of the Wi-Fi profile reset flow: once the icon row's fade-in has
 * finished, fade both screens to white over 64 frames across every blend target,
 * then hand over to the step that waits for the fades and lets the display
 * sleep. */
void Ov001_ResetProfileFadeToWhite(void) {
    void Ov001_WaitResetFadeAndSleep(void);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) return;
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_ALL, 0x40);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_ALL, 0x40);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitResetFadeAndSleep);
}

/* Final step of the Wi-Fi profile reset flow: wait for the sub screen's then the
 * main screen's fade to finish, then hold the display for a while and let it rest. */
void Ov001_WaitResetFadeAndSleep(void) {
    M2C_UNK WaitCycles(M2C_UNK);
    M2C_UNK WakeDisplayWait();
    s32 Ov001_IsFadeActive(M2C_UNK);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    WaitCycles(0x01000000);
    WakeDisplayWait();
}

/* Step callback that opens the ov001 console-info (MAC address) screen: load its
 * background and object layout, show its message panel, draw the two-line
 * MAC-address panel, then start the screen's fade-in. */
void Ov001_OpenMacAddressScreen(void) {
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    void Ov001_LoadMacAddressBackground(void);
    M2C_UNK DrawMacAddressPanel();
    extern M2C_UNK Ov001_FadeInMacAddressScreen;
    Ov001_LoadMacAddressBackground();
    Ov001_LoadObjLayoutBlock(OV001_MAC_ADDRESS_LAYOUT);
    Ov001_ShowMessagePanel(OV001_MSG_MAC_ADDRESS, -1, 0);
    DrawMacAddressPanel();
    Ov001_SetStepCallback(&Ov001_FadeInMacAddressScreen);
}

/* Loads the MAC-address/info screen's background map and gives the main and
 * sub background planes the lowest priority. */
void Ov001_LoadMacAddressBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001MacAddressBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001MacAddressBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Draws a two-line panel: the console's MAC address and its Wi-Fi profile code
 * (or a dashes placeholder when that code is zero), then closes the panel. */
M2C_UNK DrawMacAddressPanel(void) {
void *CreateTextPanel(s32,s32); void GetMacAddress(void *); s32 StringFormatWide(void *,s32,void *,...);
void DrawPanelText(void *,s32,s32,s32,s32,s32,s32,void *); M2C_UNK GetWfcProfile(void *);void CloseTextPanel(void *);
extern u8 sMacAddressFormat[],sGroupedCodeFormat[],sEmptyCodeText[];
u32 profile[5]; u32 groups[4]; char text[42]; u8 macAddress[6]; void *panel; u64 code;s32 i;
panel=CreateTextPanel(0,0);
GetMacAddress(macAddress);
StringFormatWide(text,20,sMacAddressFormat,macAddress[0],macAddress[1],macAddress[2],macAddress[3],macAddress[4],macAddress[5]);
DrawPanelText(panel,8,64,240,28,2,1152,text);
GetWfcProfile(profile);code=*(u64 *)profile;
if(code){
groups[3]=(code%10)*1000;code/=10;
for(i=0;i<3;i++){groups[2-i]=code%10000;code/=10000;}
StringFormatWide(text,20,sGroupedCodeFormat,groups[0],groups[1],groups[2],groups[3]);
}else StringFormatWide(text,20,sEmptyCodeText);
DrawPanelText(panel,8,120,240,28,2,1152,text);
CloseTextPanel(panel);
}

/* Fades in the ov001 MAC-address/info screen: start the sub and main fades
 * from white, enable its background and object planes, then move on to the
 * step that opens its icon row. */
void Ov001_FadeInMacAddressScreen(void) {
    extern M2C_UNK Ov001_MacAddressFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, GX_PLANEMASK_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback(&Ov001_MacAddressFadeDone);
}

/* Step that runs once the ov001 MAC-address screen's fade-in has finished: wait
 * for both engine fades, then put up the screen's icon row and hand over to the
 * step that waits for it to slide in. */
void Ov001_MacAddressFadeDone(void) {
    void Ov001_MacAddressWaitIconRow(void);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) return;
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) return;
    Ov001_CreateMenuIconRow(2);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_MacAddressWaitIconRow);
}

/* Wait for the MAC-address screen's icon row to finish sliding in (selection -2
 * while it is not ready): unlock the row and hand over to the menu's per-frame
 * update step. */
void Ov001_MacAddressWaitIconRow(void) {
    extern M2C_UNK Ov001_UpdateMacAddressMenu;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateMacAddressMenu);
}

void Ov001_UpdateMacAddressMenu(void) {
    void func_ov001_02177794(void);
    void func_ov001_021777b4(void);
    void Ov001_CancelMacAddressMenu(void);
    func_ov001_02177794();
    func_ov001_021777b4();
    Ov001_CancelMacAddressMenu();
}

void func_ov001_02177794(void) {
    if (KeyPressed(2) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_021777b4(void) {

}

/* The MAC-address screen's icon row had its cancel icon chosen: play the cancel
 * sound and hand over to the step that closes the screen. */
void Ov001_CancelMacAddressMenu(void) {
    void Ov001_PrepareCloseMacAddressScreen(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_PlaySound(OV001_SOUND_CANCEL);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_PrepareCloseMacAddressScreen);
}

void Ov001_PrepareCloseMacAddressScreen(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutMacAddress;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutMacAddress);
}

/* Fade out the ov001 MAC-address screen: wait for the icon row's fade-in, slide
 * the row out, start the fades of the sub screen and of the main screen's
 * backgrounds and sprites, then move on to closing the screen. */
void Ov001_FadeOutMacAddress(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern M2C_UNK Ov001_CloseMacAddressScreen;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_CloseMacAddressScreen);
}

/* Closes the MAC-address screen once both of its fades and its icon row have
 * finished: releases the screen's page and option backgrounds, disables the
 * visible planes and returns to the Wi-Fi option menu. */
void Ov001_CloseMacAddressScreen(void) {
    s32 Ov001_IsIconRowIdle();
    M2C_UNK Ov001_FreeMessagePanel();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_InitOptionMenu;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    if (Ov001_IsIconRowIdle() == 0) {
        return;
    }
    Ov001_FreePageBackground(0);
    Ov001_FreeMessagePanel();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback(&Ov001_InitOptionMenu);
}

/* Step callback that opens the ov001 Wi-Fi option menu: reset the menu state,
 * load the background and panels, create the cursor sprite and place it on the
 * current option, lay the choice frame over that option, then start the fade-in. */
void Ov001_InitOptionMenu(void) {
    extern M2C_UNK gOv001OptionMenuState;
    extern M2C_UNK gOv001OptionFrameLeft, gOv001OptionFrameRight, gOv001OptionFrameTop, gOv001OptionFrameBottom;
    void Ov001_LoadOptionMenuBg(void);
    void Ov001_FadeInOptionMenu(void);
    void *Ov001_CreateSpriteFromLayout(s32, s32);
    M2C_UNK Ov001_LoadObjLayoutBlock(s32);
    M2C_UNK Ov001_LoadMenuResource(s32);
    M2C_UNK Ov001_ShowMessagePanel(s32, s32, s32);
    M2C_UNK Ov001_LayoutChoiceFrame(u16, u16, u16, u16);
    void *p;
    s32 offset;
    ((Ov001OptionMenuState *)&gOv001OptionMenuState)->paletteLoaded = 0;
    Ov001_LoadOptionMenuBg();
    Ov001_LoadObjLayoutBlock(16);
    Ov001_LoadMenuResource(3);
    Ov001_ShowMessagePanel(0x39, -1, 0);
    p = Ov001_CreateSpriteFromLayout(0, 0x5b);
    ((Ov001OptionMenuState *)&gOv001OptionMenuState)->sprite = p;
    M2C_FIELD(p, u32 *, 0) = (M2C_FIELD(p, u32 *, 0) & 0xfe00ff00) | 0x84 | 0xe00000;
    p = ((Ov001OptionMenuState *)&gOv001OptionMenuState)->sprite;
    M2C_FIELD(p, u16 *, 4) = (M2C_FIELD(p, u16 *, 4) & ~0xc00) | 0xc00;
    offset = ((Ov001OptionMenuState *)&gOv001OptionMenuState)->selected * 8;
    Ov001_LayoutChoiceFrame(M2C_FIELD(&gOv001OptionFrameLeft, u16 *, offset), M2C_FIELD(&gOv001OptionFrameRight, u16 *, offset), M2C_FIELD(&gOv001OptionFrameTop, u16 *, offset), M2C_FIELD(&gOv001OptionFrameBottom, u16 *, offset));
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInOptionMenu);
}

/* Loads the option screen's tiles, map and palette, copies the no-profile
 * palette over the profile colours while no Wi-Fi profile exists, uploads the
 * palette, frees the temporary files and puts BG1/BG2 on priority 3. */
void Ov001_LoadOptionMenuBg(void) {
    s32 Ov001_GetLocalizedFileName(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    void *Ov001_LoadFile(s32, s32, s32);
    M2C_UNK GetWfcProfile(void *);
    void MI_CpuCopy8(void *, void *, u32);
    void DC_FlushRange(void *, u32);
    void GX_LoadBGPltt(void *, s32, u32);
    void Ov001_FreeFile(void *);
    extern M2C_UNK gOv001OptionBgPalettePath, gOv001OptionBgPaletteBankPath, gOv001OptionBgTilesPath, gOv001OptionMenuMapPath, gOv001OptionMenuState, GX_LoadBG2Char, GX_LoadBG2Scr;
    MenuBuf22 palettePath = *(MenuBuf22 *)&gOv001OptionBgPalettePath;
    MenuBuf23 layoutPath = *(MenuBuf23 *)&gOv001OptionBgPaletteBankPath;
    WfcProfile profile;
    register u8 *dst, *src;
    register s32 i;
    register void *palette;
    Ov001_LoadAsset(&gOv001OptionBgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001OptionMenuMapPath, &GX_LoadBG2Scr);
    M2C_FIELD(&gOv001OptionMenuState, void **, 4) = Ov001_LoadFile(Ov001_GetLocalizedFileName(&layoutPath), 0, 4);
    palette = Ov001_LoadFile(Ov001_GetLocalizedFileName(&palettePath), 0, 4);
    GetWfcProfile(&profile);
    if (profile.value == 0) {
        for (i = 0, dst = (u8 *)palette + OV001_PALETTE_PROFILE, src = (u8 *)palette + OV001_PALETTE_NO_PROFILE; i < 2; i++, dst += 32, src += 32)
            MI_CpuCopy8(dst, src, 32);
    }
    DC_FlushRange(palette, OV001_PALETTE_SIZE);
    GX_LoadBGPltt(palette, 0, OV001_PALETTE_SIZE);
    Ov001_FreeFile(palette);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000a, u16 *, 0) = (M2C_FIELD((void *)0x0400000a, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000a, u16 *, 2) = (M2C_FIELD((void *)0x0400000a, u16 *, 2) & ~3) | 3;
}

/* Fade the option menu in: fade both engines in from white, make the menu's
 * background and sprite planes visible, then hand over to the step that runs once
 * the fade completes. */
void Ov001_FadeInOptionMenu(void) {
    extern M2C_UNK Ov001_OptionMenuFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, OV001_BLEND_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_OptionMenuFadeDone);
}

/* Step that runs once the ov001 option menu's fade-in has finished: wait for the
 * sub and main engine fades, then put up the shared back/confirm icon row and
 * hand over to the step that waits for it to slide in. */
void Ov001_OptionMenuFadeDone(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_OptionMenuWaitIconRow;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_CreateMenuIconRow(0);
    Ov001_SetStepCallback(&Ov001_OptionMenuWaitIconRow);
}

/* Step that runs once the ov001 option menu's icon row is up: wait for the row's
 * selection to become available, unlock it and hand over to the row's per-frame
 * input update. */
void Ov001_OptionMenuWaitIconRow(void) {
    extern M2C_UNK Ov001_UpdateOptionMenu;

    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateOptionMenu);
}

void Ov001_UpdateOptionMenu(void) {
    void Ov001_HandleOptionMenuInput(void);
    void func_ov001_02177ce4(void);
    void Ov001_OptionMenuConfirm(void);
    Ov001_HandleOptionMenuInput();
    func_ov001_02177ce4();
    Ov001_OptionMenuConfirm();
}

#pragma opt_strength_reduction off
/* Input for the ov001 Wi-Fi option menu: a touch on one of the three rows
 * selects it and moves the choice frame there, A confirms, B cancels, and
 * up/down move the selection. */
void Ov001_HandleOptionMenuInput(void){
M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
M2C_UNK Ov001_LayoutChoiceFrame(u16,u16,u16,u16);
void Ov001_MoveOptionSelection(s32);
s32 KeyPressed(s32);s32 KeyHeld(s32);s32 TouchRectPressed(void *);
extern u8 gOv001OptionButtonRects[];
extern M2C_UNK gOv001OptionFrameLeft,gOv001OptionFrameRight,gOv001OptionFrameTop,gOv001OptionFrameBottom,gOv001OptionMenuState;
u32 index;u8 *rect;s32 offset;u16 left,right,top,bottom;
rect=gOv001OptionButtonRects;
for(index=0;index<3;index++,rect+=8){
if(TouchRectPressed(rect)){
Ov001_LatchIconRowSelection(1);
offset=(u8)index*8;
left=M2C_FIELD(&gOv001OptionFrameLeft,u16 *,offset);
right=M2C_FIELD(&gOv001OptionFrameRight,u16 *,offset);
top=M2C_FIELD(&gOv001OptionFrameTop,u16 *,offset);
bottom=M2C_FIELD(&gOv001OptionFrameBottom,u16 *,offset);
M2C_FIELD(&gOv001OptionMenuState,s8 *,0)=index;
Ov001_LayoutChoiceFrame(left,right,top,bottom);return;
}}
if(KeyPressed(1)){Ov001_LatchIconRowSelection(1);return;}
if(KeyPressed(2)){Ov001_LatchIconRowSelection(0);return;}
if(KeyHeld(0x40)){Ov001_MoveOptionSelection(1);return;}
if(!KeyHeld(0x80))return;
Ov001_MoveOptionSelection(3);
}
#pragma opt_strength_reduction reset
void func_ov001_02177ce4(void) {

}

/* Reacts to the option menu's icon row choice: back leaves the menu for the
 * Wi-Fi menu, confirm starts opening the highlighted option - unless that option
 * needs a Wi-Fi profile and none is registered, in which case it buzzes and
 * stays on the menu. */
void Ov001_OptionMenuConfirm(void) {
    M2C_UNK GetWfcProfile(void *);
    M2C_UNK Ov001_SetIconRowSelection(M2C_UNK);
    M2C_UNK Ov001_LoadSelectedOptionTile();
    void Ov001_OptionMenuExit(void);
    extern M2C_UNK gOv001OptionMenuState;
    WfcProfile profile;
    switch (Ov001_GetIconRowSelection()) {
    case OV001_CHOICE_BACK:
        Ov001_PlaySound(OV001_SOUND_CANCEL);
        break;
    case OV001_CHOICE_CONFIRM:
        GetWfcProfile(&profile);
        if (((Ov001OptionMenuState *)&gOv001OptionMenuState)->selected != 0) {
            if (profile.value == 0) {
                Ov001_PlaySound(OV001_SOUND_ERROR);
                Ov001_SetIconRowSelection(-1);
                return;
            }
        }
        Ov001_PlaySound(OV001_SOUND_CONFIRM);
        Ov001_LoadSelectedOptionTile();
        ((Ov001OptionMenuState *)&gOv001OptionMenuState)->paletteLoaded = 1;
        break;
    default:
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_OptionMenuExit);
}

void Ov001_OptionMenuExit(void) {
    extern M2C_UNK Ov001_FadeOutOptionMenu;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutOptionMenu);
}

/* Leave the ov001 option menu: once the sub-screen fade is idle, slide the icon
 * row out when the option palette was loaded, fade both screens to white, then
 * hand over to Ov001_OptionMenuClose. */
void Ov001_FadeOutOptionMenu(void) {
    extern M2C_UNK gOv001OptionMenuState;
    extern M2C_UNK Ov001_OptionMenuClose;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (((Ov001OptionMenuState *)&gOv001OptionMenuState)->paletteLoaded != 0) {
        Ov001_StartIconRowSlideOut();
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_OptionMenuClose);
}

/* Closes the Wi-Fi option menu once the fades have finished: releases its
 * sprites and palette, then opens the selected option screen (or returns to the
 * Wi-Fi menu when the menu was not entered from an option). */
void Ov001_OptionMenuClose(void) {
extern M2C_UNK gOv001OptionMenuState;
void Ov001_OpenWifiMenu(void);void Ov001_OpenMacAddressScreen(void);void Ov001_OpenWfcSettingsScreen(void);void Ov001_OpenWfcEraseScreen(void);
void Ov001_FreeSpriteObjects(void);M2C_UNK Ov001_FreeMessagePanel();M2C_UNK Ov001_SetNextScreenMode(M2C_UNK,M2C_UNK);
s32 Ov001_IsFadeActive(M2C_UNK);
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
if(!Ov001_IsIconRowIdle())return;
Ov001_ReleaseSprite(((Ov001OptionMenuState *)&gOv001OptionMenuState)->sprite);
Ov001_FreeSpriteObjects();Ov001_FreeMessagePanel();
Ov001_FreeFile(((Ov001OptionMenuState *)&gOv001OptionMenuState)->palette);
Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,20);
if(!((Ov001OptionMenuState *)&gOv001OptionMenuState)->paletteLoaded){Ov001_SetNextScreenMode(0,0);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWifiMenu);return;}
switch(((Ov001OptionMenuState *)&gOv001OptionMenuState)->selected){
case OV001_OPTION_MAC_ADDRESS:Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenMacAddressScreen);return;
case OV001_OPTION_WFC_SETTINGS:Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWfcSettingsScreen);return;
case OV001_OPTION_ERASE_WFC:Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWfcEraseScreen);return;
}
}

