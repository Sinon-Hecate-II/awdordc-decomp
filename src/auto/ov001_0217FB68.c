/* 53 functions from 0x0217FB68 to 0x02180B68 (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

void func_ov001_0217fb68(void) {
    extern u8 data_ov001_02193db8;
    extern M2C_UNK Ov001_CloseOptionScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (data_ov001_02193db8 == 0) {
        func_ov001_02171694();
    }
    if (data_ov001_02193db8 == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_CloseOptionScreen);
}

/* Step callback that runs once the option menu's fade-out and the icon-row
 * animation have finished: it tears down the option screen and opens either the
 * friend-list screen (mode 2) or the connection screen (mode 0), according to
 * data_ov001_02193db8. */
void Ov001_CloseOptionScreen(void) {
    M2C_UNK Ov001_FreeOptionSprites(void);
    s32 Ov001_IsIconRowIdle(void);
    M2C_UNK Ov001_FreeOptionBackground(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreeOptionPage(void);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 data_ov001_02193db8;
    extern M2C_UNK func_ov001_0217fd94;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((data_ov001_02193db8 == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (data_ov001_02193db8 == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (data_ov001_02193db8 == 0) {
        Ov001_FreeOptionPage();
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&func_ov001_02181a84);
        return;
    }
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetStepCallback(&func_ov001_0217fd94);
}

void func_ov001_0217fca4(void) {
    s32 Ov001_GetOptionChoice(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_StopSound(void);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 data_ov001_02193db8;
    extern M2C_UNK func_ov001_0217fb48;
    void func_ov001_0217fd28(void);
    switch (Ov001_GetOptionChoice()) {
    case 2:
        data_ov001_02193db8 = 1;
        Ov001_SetStepCallback(&func_ov001_0217fb48);
        return;
    case 4:
        data_ov001_02193db8 = 0;
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
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_0217fd54;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_0217fd54);
}

void func_ov001_0217fd54(void) {
    s32 func_ov001_0218665c();
    extern M2C_UNK func_ov001_0217fb48;
    if (func_ov001_0218665c() != 0) {
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
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    M2C_UNK func_ov001_021722ac(void);
    void func_ov001_0217fdd0(void);
    void func_ov001_0217fe50(void);
    extern u8 data_ov001_02193dbc;
    data_ov001_02193dbc = 0;
    func_ov001_0217fdd0();
    func_ov001_021722ac();
    func_ov001_02171e58(0x2A);
    Ov001_CreateAnimSprite(2);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217fe50);
}

void func_ov001_0217fdd0(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_021908ec;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_021908ec, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
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
    M2C_UNK func_02006030(s32);
    void Ov001_HandleOptionPage2Choice(void);
    void func_ov001_0217fef8(void);
    void func_ov001_0217ff30(void);
    void func_ov001_0217ff34(void);
    func_02006030(10);
    Ov001_HandleOptionPage2Choice();
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
    extern M2C_UNK func_ov001_0217ff80;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217ff80);
}

void func_ov001_0217ff80(void) {
    M2C_UNK func_ov001_02171694();
    extern u8 data_ov001_02193dbc;
    extern M2C_UNK Ov001_CloseMatchSetupScreen;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (data_ov001_02193dbc == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x15, 8);
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
    extern u8 data_ov001_02193dbc;
    extern M2C_UNK Ov001_AdvanceMatchSetup;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((data_ov001_02193dbc == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (data_ov001_02193dbc == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_FreeOptionPage();
    if (data_ov001_02193dbc == 0) {
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
 * and lock the icon row. data_ov001_02193dbc records the branch for the fade-out
 * that follows. */
void Ov001_HandleOptionPage2Choice(void) {
s32 Ov001_GetOptionChoice(void); M2C_UNK Ov001_PlaySound(M2C_UNK); M2C_UNK Ov001_StopSound(void); M2C_UNK Ov001_StoreMatchSetup(void); M2C_UNK Ov001_ShowMessage(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32); M2C_UNK Ov001_LockIconRow(void);
extern u8 data_ov001_02193dbc; void func_ov001_0217ff60(void); void func_ov001_02180178(void);
switch(Ov001_GetOptionChoice()){
case 3: data_ov001_02193dbc=1;Ov001_StopSound();Ov001_StoreMatchSetup();Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217ff60);return;
case 4: data_ov001_02193dbc=0;Ov001_StopSound();Ov001_PlaySound(9);Ov001_ShowMessage(13,1,1,-1,0);Ov001_LockIconRow();Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180178);return;
case 5: data_ov001_02193dbc=0;Ov001_StopSound();Ov001_PlaySound(18);Ov001_ShowMessage(14,1,1,-1,0);Ov001_LockIconRow();Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180178);return;
}}

void func_ov001_02180178(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_021801a4;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_021801a4);
}

void func_ov001_021801a4(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217ff60);
}

void Ov001_AdvanceMatchSetup(void) {
M2C_UNK func_ov001_02171e58(M2C_UNK);
M2C_UNK func_ov001_021722ac(void);
M2C_UNK Ov001_PlaySound(M2C_UNK);
void func_ov001_02180200(void);
void func_ov001_02180280(void);
extern s8 data_ov001_02193dc0;
data_ov001_02193dc0=0;
func_ov001_02180200();
func_ov001_021722ac();
func_ov001_02171e58(0x26);
Ov001_PlaySound(0x10);
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180280);
}

void func_ov001_02180200(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190900;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_02190900, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
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
    extern M2C_UNK func_ov001_02180328;
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_02180328);
}

void func_ov001_02180328(void) {
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

void func_ov001_021803ec(void) {
extern u8 data_ov001_02193dc4;
void func_ov001_021804f0(void);
void func_ov001_02180448(void);
M2C_UNK func_ov001_021722ac(void);
M2C_UNK Ov001_ShowMessagePanel(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_02171dd0(M2C_UNK);
M2C_UNK func_ov001_02171e58(M2C_UNK);
M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
M2C_UNK Ov001_PlaySound(M2C_UNK);
data_ov001_02193dc4=0;
func_ov001_02180448();
func_ov001_021722ac();
Ov001_ShowMessagePanel(0x37,-1,0);
func_ov001_02171dd0(2);
func_ov001_02171e58(0x24);
Ov001_CreateAnimSprite(0);
Ov001_PlaySound(0xb);
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021804f0);
}

void func_ov001_02180448(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190914, data_ov001_0219092c, data_ov001_02190944;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_02190914, &GX_LoadBG2Char);
    Ov001_LoadAsset(&data_ov001_0219092c, &GX_LoadBGPltt);
    Ov001_LoadAsset(&data_ov001_02190944, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_021804f0(void) {
    extern M2C_UNK func_ov001_02180544;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_02180544);
}

void func_ov001_02180544(void) {
void func_ov001_02180584(void);
M2C_UNK func_ov001_021763cc(void);
M2C_UNK func_ov001_02171e20(M2C_UNK);
s32 Ov001_IsFadeActive(s32);
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
func_ov001_021763cc();
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
    M2C_UNK func_02006030(s32);
    void func_ov001_02180790();
    void func_ov001_021805cc(void);
    void func_ov001_02180604(void);
    void func_ov001_02180608(void);
    func_02006030(10);
    func_ov001_02180790();
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
    extern M2C_UNK func_ov001_02180634;
    if (Ov001_GetIconRowSelection() != 0) {
        return;
    }
    Ov001_StopSound();
    Ov001_PlaySound(7);
    Ov001_SetStepCallback(&func_ov001_02180634);
}

void func_ov001_02180634(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02180654;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02180654);
}

void func_ov001_02180654(void) {
    extern u8 data_ov001_02193dc4;
    extern M2C_UNK Ov001_CloseOptionScreen2;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (data_ov001_02193dc4 == 0) {
        func_ov001_02171694();
    }
    if (data_ov001_02193dc4 == 0) {
        Ov001_StartFade(3, 1, 1, 8);
    }
    Ov001_StartFade(3, 0, 0x14, 8);
    Ov001_SetStepCallback(&Ov001_CloseOptionScreen2);
}

/* Step callback that runs once the second option page's fade-out and the
 * icon-row animation have finished: it tears down the option screen and opens
 * either the friend-list screen (mode 2) or the connection screen (mode 0),
 * according to data_ov001_02193dc4. */
void Ov001_CloseOptionScreen2(void) {
    M2C_UNK Ov001_FreeOptionSprites(void);
    s32 Ov001_IsIconRowIdle(void);
    M2C_UNK Ov001_FreeOptionBackground(void);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_FreeOptionPage(void);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern u8 data_ov001_02193dc4;
    extern M2C_UNK func_ov001_0217f97c;
    extern M2C_UNK func_ov001_02181a84;
    if (Ov001_IsFadeActive(0) != 0) return;
    if ((data_ov001_02193dc4 == 0) && (Ov001_IsFadeActive(1) != 0)) return;
    if (Ov001_IsIconRowIdle() == 0) return;
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    if (data_ov001_02193dc4 == 0) {
        Ov001_FreeOptionBackground();
        Ov001_DisableVisiblePlanes(1, 1);
    }
    Ov001_DisableVisiblePlanes(0, 0x15);
    if (data_ov001_02193dc4 == 0) {
        Ov001_FreeOptionPage();
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&func_ov001_02181a84);
        return;
    }
    Ov001_SetNextScreenMode(0, 0);
    Ov001_SetStepCallback(&func_ov001_0217f97c);
}

void func_ov001_02180790(void) {
    s32 Ov001_GetOptionChoice(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern void func_ov001_02180634(void);
    extern void func_ov001_02180814(void);
    M2C_UNK Ov001_StopSound(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_ShowMessage(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Ov001_LockIconRow(void);
    extern u8 data_ov001_02193dc4;

    switch (Ov001_GetOptionChoice()) {
    case 1:
        data_ov001_02193dc4 = 1;
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180634);
        return;
    case 4:
        data_ov001_02193dc4 = 0;
        Ov001_StopSound();
        Ov001_PlaySound(9);
        Ov001_ShowMessage(0xD, 1, 1, -1, 0);
        Ov001_LockIconRow();
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180814);
        return;
    }
}

void func_ov001_02180814(void) {
    extern M2C_UNK func_ov001_02180840;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_02180840);
}

void func_ov001_02180840(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180634);
}

void func_ov001_02180860(void) {
extern u8 gOv001FriendListState;
extern M2C_UNK func_ov001_02180970;
void func_ov001_021808c8(void);
M2C_UNK Ov001_ShowMessagePanel(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_021722ac(void);
M2C_UNK func_ov001_02171dd0(M2C_UNK);
M2C_UNK func_ov001_02183f6c(void);
M2C_UNK func_ov001_02183fd4(void);
M2C_FIELD(&gOv001FriendListState,u16 *,2)=0;
gOv001FriendListState=0;
func_ov001_021808c8();
Ov001_ShowMessagePanel(0x33,-1,0);
func_ov001_021722ac();
func_ov001_02171dd0(2);
func_ov001_02171e58(0x33);
Ov001_CreateAnimSprite(0);
func_ov001_02183f6c();
func_ov001_02183fd4();
Ov001_PlaySound(10);
Ov001_SetStepCallback(&func_ov001_02180970);
}

void func_ov001_021808c8(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190958, data_ov001_02190970, data_ov001_02190988;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;
    Ov001_LoadAsset(&data_ov001_02190958, &GX_LoadBG2Char);
    Ov001_LoadAsset(&data_ov001_02190970, &GX_LoadBGPltt);
    Ov001_LoadAsset(&data_ov001_02190988, &GX_LoadBG2Scr);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02180970(void) {
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

