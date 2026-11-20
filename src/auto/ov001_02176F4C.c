/* 48 functions from 0x02176F4C to 0x02177F1C (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
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

void func_ov001_02176f4c(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    void func_ov001_02176f88(void);
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    func_ov001_02171e20(3);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176f88);
}

void func_ov001_02176f88(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    void func_ov001_02176fb0(void);
    if (Ov001_GetIconRowSelection() == -2) return;
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176fb0);
}

void func_ov001_02176fb0(void) {
    void func_ov001_02176fc4(void);
    void func_ov001_02176ffc(void);
    void func_ov001_02177000(void);
    func_ov001_02176fc4();
    func_ov001_02176ffc();
    func_ov001_02177000();
}

void func_ov001_02176fc4(void) {
    if (KeyPressed(1) != 0) {
        Ov001_LatchIconRowSelection(1);
    }
    if (KeyPressed(2) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_02176ffc(void) {

}

void func_ov001_02177000(void) {
    void func_ov001_02177068(void);
    void func_ov001_021771a4(void);
    s32 temp_r0;
    temp_r0 = Ov001_GetIconRowSelection();
    switch (temp_r0) {
    case 0:
        Ov001_PlaySound(7);
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177068);
        return;
    case 1:
        Ov001_PlaySound(6);
        Ov001_ShowMessage(0x18, 0, 1, -1, 0);
        Ov001_LockIconRow();
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021771a4);
        return;
    }
}

void func_ov001_02177068(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02177088;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02177088);
}

void func_ov001_02177088(void) {
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
        Ov001_FreeOptionBackground();
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

void func_ov001_021771a4(void) {
    void func_ov001_021771f4(void);
    extern u8 gOv001WfcSettingsReset;
    s32 temp_r0;
    temp_r0 = func_ov001_02186648();
    switch (temp_r0) {
    case 1:
        Ov001_PlaySound(0xE);
        gOv001WfcSettingsReset = 1;
        break;
    case 0:
        Ov001_PlaySound(7);
        break;
    default: return;
    }
    func_ov001_02186604();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021771f4);
}

void func_ov001_021771f4(void) {
    s32 Ov001_IsRegionMenuActive();
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177068);
}

void func_ov001_02177214(void) {
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    void func_ov001_02177238(void);
    M2C_UNK ResetSaveSlotsWithWfcProfile();
    extern M2C_UNK func_ov001_021772b8;
    func_ov001_02177238();
    Ov001_ShowMessageBox(0x19);
    ResetSaveSlotsWithWfcProfile();
    Ov001_SetStepCallback(&func_ov001_021772b8);
}

void func_ov001_02177238(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190534;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_02190534, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021772b8(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021772ec;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_021772ec);
}

void func_ov001_021772ec(void) {
    void func_ov001_02177318(void);
    if (Ov001_IsFadeActive(0) != 0) return;
    func_ov001_02171e20(5);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177318);
}

void func_ov001_02177318(void) {
    extern M2C_UNK func_ov001_02177340;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02177340);
}

void func_ov001_02177340(void) {
    void func_ov001_02177354(void);
    void func_ov001_02177374(void);
    void func_ov001_02177378(void);
    func_ov001_02177354();
    func_ov001_02177374();
    func_ov001_02177378();
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

void func_ov001_02177378(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void func_ov001_021773a0(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_PlaySound(6);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021773a0);
}

void func_ov001_021773a0(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_021773c0;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_021773c0);
}

void func_ov001_021773c0(void) {
    void func_ov001_0217740c(void);
    if (Ov001_IsFadeActive(1) != 0) return;
    Ov001_StartFade(3, 1, 0x3F, 0x40);
    Ov001_StartFade(3, 0, 0x3F, 0x40);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217740c);
}

void func_ov001_0217740c(void) {
    M2C_UNK WaitCycles(M2C_UNK);
    M2C_UNK WakeDisplayWait();
    s32 Ov001_IsFadeActive(M2C_UNK);
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    WaitCycles(0x01000000);
    WakeDisplayWait();
}

void Ov001_OpenMacAddressScreen(void) {
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    void func_ov001_02177474(void);
    M2C_UNK DrawMacAddressPanel();
    extern M2C_UNK func_ov001_021776c8;
    func_ov001_02177474();
    Ov001_LoadObjLayoutBlock(0x11);
    Ov001_ShowMessagePanel(0x3A, -1, 0);
    DrawMacAddressPanel();
    Ov001_SetStepCallback(&func_ov001_021776c8);
}

void func_ov001_02177474(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190548;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_02190548, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
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

void func_ov001_021776c8(void) {
    extern M2C_UNK func_ov001_0217771c;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_0217771c);
}

void func_ov001_0217771c(void) {
    void func_ov001_02177758(void);
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    func_ov001_02171e20(2);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177758);
}

void func_ov001_02177758(void) {
    extern M2C_UNK func_ov001_02177780;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02177780);
}

void func_ov001_02177780(void) {
    void func_ov001_02177794(void);
    void func_ov001_021777b4(void);
    void func_ov001_021777b8(void);
    func_ov001_02177794();
    func_ov001_021777b4();
    func_ov001_021777b8();
}

void func_ov001_02177794(void) {
    if (KeyPressed(2) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_021777b4(void) {

}

void func_ov001_021777b8(void) {
    void func_ov001_021777e0(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_PlaySound(7);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021777e0);
}

void func_ov001_021777e0(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02177800;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02177800);
}

void func_ov001_02177800(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern M2C_UNK func_ov001_02177850;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_02177850);
}

void func_ov001_02177850(void) {
    s32 Ov001_IsIconRowIdle();
    M2C_UNK Ov001_FreeOptionBackground();
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
    Ov001_FreeOptionBackground();
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
    s32 Ov001_LocalizePath(void *);
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
    M2C_FIELD(&gOv001OptionMenuState, void **, 4) = Ov001_LoadFile(Ov001_LocalizePath(&layoutPath), 0, 4);
    palette = Ov001_LoadFile(Ov001_LocalizePath(&palettePath), 0, 4);
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

void Ov001_FadeInOptionMenu(void) {
    extern M2C_UNK func_ov001_02177b78;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x14, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x14);
    Ov001_SetStepCallback(&func_ov001_02177b78);
}

void func_ov001_02177b78(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK func_ov001_02177bb4;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    Ov001_SetStepCallback(&func_ov001_02177bb4);
}

void func_ov001_02177bb4(void) {
    extern M2C_UNK func_ov001_02177bdc;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02177bdc);
}

void func_ov001_02177bdc(void) {
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
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&Ov001_FadeOutOptionMenu);
}

void Ov001_FadeOutOptionMenu(void) {
    extern M2C_UNK gOv001OptionMenuState;
    extern M2C_UNK Ov001_OptionMenuClose;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (M2C_FIELD(&gOv001OptionMenuState, u8 *, 1) != 0) {
        Ov001_StartIconRowSlideOut();
    }
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x14, 8);
    Ov001_SetStepCallback(&Ov001_OptionMenuClose);
}

/* Closes the Wi-Fi option menu once the fades have finished: releases its
 * sprites and palette, then opens the selected option screen (or returns to the
 * Wi-Fi menu when the menu was not entered from an option). */
void Ov001_OptionMenuClose(void) {
extern M2C_UNK gOv001OptionMenuState;
void Ov001_OpenWifiMenu(void);void Ov001_OpenMacAddressScreen(void);void Ov001_OpenWfcSettingsScreen(void);void Ov001_OpenWfcEraseScreen(void);
void Ov001_FreeSpriteObjects(void);M2C_UNK Ov001_FreeOptionBackground();M2C_UNK Ov001_SetNextScreenMode(M2C_UNK,M2C_UNK);
s32 Ov001_IsFadeActive(M2C_UNK);
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
if(!Ov001_IsIconRowIdle())return;
Ov001_ReleaseSprite(((Ov001OptionMenuState *)&gOv001OptionMenuState)->sprite);
Ov001_FreeSpriteObjects();Ov001_FreeOptionBackground();
Ov001_FreeFile(((Ov001OptionMenuState *)&gOv001OptionMenuState)->palette);
Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,20);
if(!((Ov001OptionMenuState *)&gOv001OptionMenuState)->paletteLoaded){Ov001_SetNextScreenMode(0,0);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWifiMenu);return;}
switch(((Ov001OptionMenuState *)&gOv001OptionMenuState)->selected){
case OV001_OPTION_MAC_ADDRESS:Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenMacAddressScreen);return;
case OV001_OPTION_WFC_SETTINGS:Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWfcSettingsScreen);return;
case OV001_OPTION_ERASE_WFC:Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenWfcEraseScreen);return;
}
}

