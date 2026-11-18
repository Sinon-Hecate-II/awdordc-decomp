/* 60 functions from 0x02182A4C to 0x02183A20 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"

void func_ov001_02182a4c(void) {
    void func_ov001_02182a88(void);
    void func_ov001_02182a8c(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    void func_ov001_02182a90(void);
    func_ov001_02182a88();
    func_ov001_02182a8c();
    if (func_ov001_02186648() != 0) return;
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_PlaySound(6);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182a90);
}

void func_ov001_02182a88(void) {}

void func_ov001_02182a8c(void) {}

void func_ov001_02182a90(void) {
    s32 Ov001_IsRegionMenuActive();
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_02182ac4(void);
    if (Ov001_IsRegionMenuActive() != 0) return;
    Ov001_StartFade(3, 0, 0x14, 8);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182ac4);
}

void func_ov001_02182ac4(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0218223c;
    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_DisableVisiblePlanes(0, 0x14);
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback(&func_ov001_0218223c);
}

void func_ov001_02182b00(void) {
 void func_ov001_02182b40(void);
 M2C_UNK func_ov001_02172250(M2C_UNK);
 M2C_UNK func_ov001_02171e58(M2C_UNK);
 M2C_UNK Ov001_PlaySound(M2C_UNK);
 M2C_UNK Ov001_SetStepCallback();
 void func_ov001_02182bc0(void);
 extern u8 data_ov001_02193de4;
 data_ov001_02193de4 = 0;
 func_ov001_02182b40();
 func_ov001_02172250(8);
 func_ov001_02171e58(0x29);
 Ov001_PlaySound(0x10);
 Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182bc0);
}

void func_ov001_02182b40(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190abc;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_02190abc, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02182bc0(void) {
M2C_UNK Ov001_StartFade(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK,M2C_UNK);void func_ov001_02182bf4(void);
Ov001_StartFade(2,0,0x15,8);Ov001_EnableVisiblePlanes(0,0x15);Ov001_SetStepCallback((M2C_UNK*)&func_ov001_02182bf4);
}

void func_ov001_02182bf4(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK func_ov001_02182c18;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_02182c18);
}

void func_ov001_02182c18(void) {
    void func_ov001_02182cd8(void);
    void func_ov001_02182c28(void);
    func_ov001_02182cd8();
    func_ov001_02182c28();
}

void func_ov001_02182c28(void) {

}

#pragma push
#pragma opt_common_subs off
void func_ov001_02182c2c(void) {
void func_ov001_02182c68(void);
Ov001_StartFade(3,1,1,8);Ov001_StartFade(3,0,0x15,8);Ov001_SetStepCallback((M2C_UNK*)&func_ov001_02182c68);
}

void func_ov001_02182c68(void) {
s32 Ov001_IsFadeActive(M2C_UNK);M2C_UNK Ov001_FreeOptionBackground();
M2C_UNK Ov001_SetNextScreenMode(M2C_UNK,M2C_UNK);M2C_UNK Ov001_SetNameEntryMode(M2C_UNK,M2C_UNK);
M2C_UNK Ov001_FreePageBackground(M2C_UNK);M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK,M2C_UNK);
extern M2C_UNK func_ov001_021828ac;
if(Ov001_IsFadeActive(1)!=0)return;if(Ov001_IsFadeActive(0)!=0)return;
Ov001_FreePageBackground(0);Ov001_FreeOptionBackground();Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,0x15);
Ov001_SetNextScreenMode(0,0);Ov001_SetNameEntryMode(0,2);Ov001_SetStepCallback(&func_ov001_021828ac);
}
#pragma pop
void func_ov001_02182cd8(void) {
    extern u8 data_ov001_02193de4;
    data_ov001_02193de4 = data_ov001_02193de4 + 1;
    if ((u32)data_ov001_02193de4 < 120U) return;
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182c2c);
}

void func_ov001_02182d0c(void) {
    M2C_UNK func_ov001_02172250(M2C_UNK);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02171dd0(M2C_UNK);
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_LoadWfcConnectStep2Bg(void);
    void func_ov001_02182e04(void);
    extern u8 gOv001WfcConnectChosen;
    gOv001WfcConnectChosen = 0;
    Ov001_LoadWfcConnectStep2Bg();
    func_ov001_02172250(8);
    Ov001_ShowMessagePanel(0x38, -1, 0);
    func_ov001_02171dd0(1);
    func_ov001_02171e58(0x27);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182e04);
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

void func_ov001_02182e04(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void func_ov001_02182e58(void);
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182e58);
}

void func_ov001_02182e58(void) {
    extern M2C_UNK func_ov001_02182e94;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(6);
    Ov001_SetStepCallback(&func_ov001_02182e94);
}

#pragma push
#pragma opt_common_subs off
void func_ov001_02182e94(void) {
s32 Ov001_GetIconRowSelection(); M2C_UNK Ov001_UnlockIconRow(); extern M2C_UNK func_ov001_02182ebc;
if(Ov001_GetIconRowSelection()==-2)return;
Ov001_UnlockIconRow();Ov001_SetStepCallback(&func_ov001_02182ebc);
}
void func_ov001_02182ebc(void) {
 void func_ov001_02182ed0(void);
 void func_ov001_02182f08(void);
 void func_ov001_02182f0c(void);
 func_ov001_02182ed0();
 func_ov001_02182f08();
 func_ov001_02182f0c();
}

void func_ov001_02182ed0(void) {
    if (KeyPressed(1) != 0) {
        Ov001_LatchIconRowSelection(1);
    }
    if (KeyPressed(2) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_02182f08(void) {

}

void func_ov001_02182f0c(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern u8 gOv001WfcConnectChosen;
    void func_ov001_02182f5c(void);
    switch (Ov001_GetIconRowSelection()) {
    case 0: Ov001_PlaySound(7); break;
    case 1:
        Ov001_PlaySound(6);
        gOv001WfcConnectChosen = 1;
        break;
    default: return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182f5c);
}

void func_ov001_02182f5c(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02182f7c;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02182f7c);
}

void func_ov001_02182f7c(void) {
    M2C_UNK func_ov001_02171694();
    extern u8 gOv001WfcConnectChosen;
    extern M2C_UNK Ov001_CloseWfcMenuScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    func_ov001_02171694();
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
    M2C_UNK Ov001_FreeOptionBackground();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 gOv001WfcConnectChosen;
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    extern M2C_UNK Ov001_OpenWfcConnectScreen;
    if (Ov001_IsFadeActive(0) != 0) return;
    if (gOv001WfcConnectChosen == 0 && Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreePageBackground(0);
    if (gOv001WfcConnectChosen == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (gOv001WfcConnectChosen == 0) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);
        return;
    }
    Ov001_SetNextScreenMode(2, 1);
    Ov001_SetStepCallback(&Ov001_OpenWfcConnectScreen);
}

s32 func_ov001_02183098(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void Ov001_OpenWfcConnectScreen(void) {
    M2C_UNK func_02007740(u8 *);
    M2C_UNK FillU16(M2C_UNK, u8 *, s32);
    M2C_UNK CopyU16(u8 *, u8 *, s32);
    M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
    M2C_UNK func_ov001_02171dd0(M2C_UNK);
    M2C_UNK Ov001_ShowMessageWithName(u8 *, M2C_UNK);
    M2C_UNK func_ov001_02172250(M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_LoadUsbConnectBg(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_ConnectToWfcServer(M2C_UNK *);
    extern u8 gOv001WfcScreenState;
    extern M2C_UNK Ov001_HandleConnectionStatus;
    extern M2C_UNK func_ov001_021831f4;
    u8 sp[0x6C];

    gOv001WfcScreenState = 0;
    Ov001_LoadUsbConnectBg();
    func_ov001_02172250(8);
    func_ov001_02171dd0(2);
    func_02007740(&sp[0x16]);
    FillU16(0, &sp[0], 0x16);
    CopyU16(&sp[0x1A], &sp[0], M2C_FIELD(sp, u16 *, 0x30) * 2);
    Ov001_ShowMessageWithName(&sp[0], 0x28);
    Ov001_CreateAnimSprite(0);
    Ov001_ConnectToWfcServer((M2C_UNK *)&Ov001_HandleConnectionStatus);
    Ov001_PlaySound(0xB);
    Ov001_SetStepCallback(&func_ov001_021831f4);
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

void func_ov001_021831f4(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern M2C_UNK func_ov001_02183228;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_02183228);
}

void func_ov001_02183228(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    extern M2C_UNK func_ov001_02183254;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(2);
    Ov001_SetStepCallback(&func_ov001_02183254);
}

void func_ov001_02183254(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern M2C_UNK func_ov001_0218327c;
    if (Ov001_GetIconRowSelection() == -2) return;
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_0218327c);
}

void func_ov001_0218327c(void) {
    void func_ov001_02183290(void);
    void func_ov001_021832c8(void);
    void func_ov001_021832cc(void);
    func_ov001_02183290();
    func_ov001_021832c8();
    func_ov001_021832cc();
}

void func_ov001_02183290(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(2) != 0) {
        Ov001_LatchIconRowSelection(0);
        return;
    }
    if (func_ov001_02183098() == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_021832c8(void) {

}

void func_ov001_021832cc(void){void func_ov001_02183318(void);extern u8 gOv001WfcScreenState;M2C_UNK Ov001_StopSound();if(gOv001WfcScreenState)return;if(Ov001_GetIconRowSelection())return;gOv001WfcScreenState=2;Ov001_StopSound();Ov001_PlaySound(7);Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02183318);}

void func_ov001_02183318(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02183338;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02183338);
}

void func_ov001_02183338(void){extern u8 gOv001WfcScreenState;extern M2C_UNK func_ov001_021833a4;M2C_UNK func_ov001_02171694();if(Ov001_IsFadeActive(1))return;func_ov001_02171694();if((u8)(gOv001WfcScreenState+254)<=1)Ov001_StartFade(3,1,1,8);Ov001_StartFade(3,0,21,8);Ov001_SetStepCallback(&func_ov001_021833a4);}

/* Sets up the overlay 001 mode based on the selected slot/state, runs init hooks, then schedules render callbacks. */
void func_ov001_021833a4(void) {
    M2C_UNK Ov001_FreeOptionSprites(void);
    s32 Ov001_IsIconRowIdle(void);
    M2C_UNK Ov001_FreeOptionBackground(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    void func_ov001_02185dac(void);
    extern u8 gOv001WfcScreenState;
    extern void Ov001_OpenAccessPointMenu(void);
    extern void func_ov001_02182d0c(void);
    extern void func_ov001_02182b00(void);

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
        Ov001_FreeOptionBackground();
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
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182d0c);
        return;
    }
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182b00);
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
    void func_ov001_02183584(void);
    void func_ov001_02183318(void);
    void func_ov001_021835d0(void);

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
        return Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02183584);
    case 1:
        gOv001WfcScreenState = 1;
        Ov001_StopSound();
        return Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02183318);
    case 2:
        Ov001_StopSound();
        Ov001_SetConnectionStatusCallback(0);
        Ov001_ShowMessage(0x11, 0, 1, -1, 0);
        Ov001_LockIconRow();
        return Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021835d0);
    case 3:
        gOv001WfcScreenState = 2;
        Ov001_StopSound();
        Ov001_PlaySound(9);
        return Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02183318);
    }
    return status;
}

void func_ov001_02183584(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_021835b0;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_021835b0);
}

void func_ov001_021835b0(void) {
    s32 Ov001_IsRegionMenuActive();
    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02183318);
}

void func_ov001_021835d0(void){void func_ov001_0218362c(void);extern u8 gOv001WfcScreenState;switch(func_ov001_02186648()){case 1:gOv001WfcScreenState=3;Ov001_PlaySound(6);break;case 0:gOv001WfcScreenState=1;Ov001_PlaySound(7);break;default:return;}func_ov001_02186604();Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0218362c);}

void func_ov001_0218362c(void) {
    M2C_UNK Ov001_UnlockIconRow();
    void Ov001_SetConnectionStatusCallback(s32);
    extern u8 gOv001WfcScreenState;
    void func_ov001_0218327c(void);
          M2C_UNK Ov001_HandleConnectionStatus(M2C_UNK);
      if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    if (gOv001WfcScreenState == 1) {
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02183318);
        return;
    }
    Ov001_PlaySound(0xB);
    Ov001_UnlockIconRow();
    gOv001WfcScreenState = 0;
    Ov001_SetConnectionStatusCallback((M2C_UNK)&Ov001_HandleConnectionStatus);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0218327c);
}

void InitMapPreview(void *a){extern void *gOv001MapPreview;void *Ov001_Alloc(s32,s32);void MI_CpuCopy32(void *,void *,s32);s32 Ov001_AddTask(s32,void (*)(),s32,s32);void FlushMapPreview(void);void *p=Ov001_Alloc(0x608,4);gOv001MapPreview=p;MI_CpuCopy32(a,(u8 *)p+4,0x600);M2C_FIELD(gOv001MapPreview,s32 *,0)=Ov001_AddTask(1,FlushMapPreview,0,120);}

#pragma opt_propagation off
void FreeMapPreview(void){extern void *gOv001MapPreview;extern void *gOv001Scrollbar;void func_ov001_0218c94c(s32,s32);void Ov001_FreeAlloc(void *);func_ov001_0218c94c(1,*(s32 *)*(s32 *)&gOv001MapPreview);Ov001_FreeAlloc(&gOv001Scrollbar-3);}
#pragma opt_propagation reset
void RequestMapPreviewUpdate(void) {
    extern void *gOv001MapPreview;
    M2C_FIELD(gOv001MapPreview, s8 *, 0x604) = 1;
}

void CopyMapPreviewRows(void *a,s32 b,s32 c,s32 d){extern void *gOv001MapPreview;u8 *src=a;u8 *dst=(u8 *)gOv001MapPreview+4+b*2;s32 i;for(i=0;i<d;i++){CopyU16(src,dst,c*2);src+=64;dst+=64;}}

void FlushMapPreview(void){
extern void *gOv001MapPreview;void DC_FlushRange();void GX_LoadBG2Scr();
if(!M2C_FIELD(gOv001MapPreview,u8 *,0x604))return;
DC_FlushRange((u8 *)gOv001MapPreview+4,0x600);
GX_LoadBG2Scr((u8 *)gOv001MapPreview+4,0,0x600);
M2C_FIELD(gOv001MapPreview,u8 *,0x604)=0;
}

void Ov001_LoadObjTile(s32 a,s32 b,s32 c){
extern void *gOv001MapPreview;void func_ov001_02183820();s32 Ov001_AddTask(s32,void (*)(),s32,s32);
M2C_FIELD(&gOv001MapPreview,s32 *,4)=a+(b<<5);
M2C_FIELD(&gOv001MapPreview,s32 *,8)=(c<<5)+0x5000000;
Ov001_AddTask(1,func_ov001_02183820,0,0x78);
}

void func_ov001_02183820(s32 a){
extern void *gOv001MapPreview;
CopyU16(M2C_FIELD(&gOv001MapPreview,s32 *,4),M2C_FIELD(&gOv001MapPreview,s32 *,8),32);
Ov001_PostTaskMessage(1,a);
}

void func_ov001_0218384c(s32 a){
extern void *gOv001MapPreview;void func_ov001_02183878();s32 Ov001_AddTask(s32,void (*)(),s32,s32);
M2C_FIELD(&gOv001MapPreview,s32 *,4)=a;
Ov001_AddTask(1,func_ov001_02183878,0,0x78);
}

void func_ov001_02183878(s32 a){
extern void *gOv001MapPreview;
CopyU16(M2C_FIELD(&gOv001MapPreview,s32 *,4),0x5000000,0x200);Ov001_PostTaskMessage(1,a);
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

void func_ov001_02183980(void) {
extern void *gOv001Scrollbar; extern void *gWfcFriendRoster;
void func_ov001_0218c94c(s32, s32);
void Ov001_FreeAlloc(void *);
func_ov001_0218c94c(0,M2C_FIELD(gOv001Scrollbar,s32*,12));
Ov001_DestroySprite(M2C_FIELD(gOv001Scrollbar,s32*,0));
Ov001_FreeAlloc(&gWfcFriendRoster-1);
}

u8 GetMenuRow(void) {
    extern void *gOv001Scrollbar;
    return M2C_FIELD(gOv001Scrollbar, u8 *, 0x1A);
}

u8 GetMenuState(void){extern void *gOv001Scrollbar;return M2C_FIELD(gOv001Scrollbar,u8 *,29);}

void Ov001_UpdateScrollbarHandle(void) { M2C_UNK Ov001_SetScrollbarHandlePos(); Ov001_SetScrollbarHandlePos(); }

void Ov001_UnblockScrollBar(void){extern void *gOv001Scrollbar;M2C_FIELD(gOv001Scrollbar,u8 *,30)=0;}

void Ov001_BlockScrollBar(void){extern void *gOv001Scrollbar;M2C_FIELD(gOv001Scrollbar,u8 *,30)=1;}

