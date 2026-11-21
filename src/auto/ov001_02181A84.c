/* 42 functions from 0x02181A84 to 0x02182A4C (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "wfc.h"

/* Load the background-step character data and enable display backgrounds. */
void func_ov001_02181a84(void) {
    M2C_UNK GetCurrentMapRecord(void);
    M2C_UNK Ov001_GetLanguage(void);
    void func_ov001_02181ba8(void);
    M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_OpenMenuForMode(M2C_UNK);
    M2C_UNK Ov001_HasOptionFlag(M2C_UNK);
    M2C_UNK Ov001_LayoutChoiceFrame(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK);
    extern M2C_UNK gOv001IconMenuState;
    extern M2C_UNK data_ov001_0218fb38;
    extern M2C_UNK data_ov001_0218faf6;
    extern M2C_UNK data_ov001_0218fafa;
    extern M2C_UNK data_ov001_0218faf8;
    extern M2C_UNK data_ov001_0218fafc;
    extern void func_ov001_02181c94(void);

    M2C_UNK r4;
    M2C_UNK r5;
    M2C_UNK r6;
    M2C_UNK r3;
    M2C_UNK r12p;
    M2C_UNK r1p;
    M2C_UNK r2p;
    M2C_UNK r3p;
    M2C_UNK rowByte;

    r4 = GetCurrentMapRecord();
    M2C_FIELD(&gOv001IconMenuState, u8 *, 2) = 0;
    if ((s8)M2C_FIELD(&gOv001IconMenuState, s8 *, 0) == 0) {
        M2C_FIELD(&gOv001IconMenuState, s8 *, 0) = 1;
    }
    if (Ov001_GetLanguage() != 0) {
        if ((s8)M2C_FIELD(&gOv001IconMenuState, u8 *, 1) == 2) {
            M2C_FIELD(&gOv001IconMenuState, u8 *, 1) = 0;
        }
        if ((s8)M2C_FIELD(&gOv001IconMenuState, u8 *, 0) == 2) {
            M2C_FIELD(&gOv001IconMenuState, u8 *, 0) = 1;
        }
        func_ov001_02181ba8();
        Ov001_LoadSaveSlotObjLayout();
        r5 = Ov001_GetLanguage();
        {
            u8 u = (u8)M2C_FIELD((void *)r4, u8 *, 0xF4);
            s8 d = (s8)M2C_FIELD(&data_ov001_0218fb38, s8 *, r5);
            Ov001_ShowMessagePanel(0x32, d, u + 1);
        }
        Ov001_OpenMenuForMode(1);
    }

    r6 = Ov001_HasOptionFlag(1);
    r5 = Ov001_HasOptionFlag(1);
    r4 = Ov001_HasOptionFlag(1);
    r3 = Ov001_HasOptionFlag(1);

    r12p = (M2C_UNK)((u8 *)&data_ov001_0218faf6 + r6 * 32);
    rowByte = (s8)M2C_FIELD(&gOv001IconMenuState, s8 *, 1);
    r1p = (M2C_UNK)((u8 *)&data_ov001_0218fafa + r5 * 32);
    r2p = (M2C_UNK)((u8 *)&data_ov001_0218faf8 + r4 * 32);
    r5 = rowByte * 8;
    r3p = (M2C_UNK)((u8 *)&data_ov001_0218fafc + r3 * 32);

    Ov001_LayoutChoiceFrame(
        *(u16 *)((u8 *)r12p + r5),
        *(u16 *)((u8 *)r1p + r5),
        *(u16 *)((u8 *)r2p + r5),
        *(u16 *)((u8 *)r3p + r5)
    );

    Ov001_SetStepCallback((M2C_UNK)&func_ov001_02181c94);
}

void func_ov001_02181ba8(void) {
    s32 Ov001_LocalizePath(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    s32 Ov001_LoadFile(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_0218fa80;
    extern M2C_UNK data_ov001_02190a0c;
    extern M2C_UNK data_ov001_02190a24;
    extern M2C_UNK data_ov001_02190a3c;
    extern M2C_UNK gOv001IconMenuState;
    extern M2C_UNK GX_LoadBGPltt;
    extern M2C_UNK GX_LoadBG2Scr;
    extern M2C_UNK GX_LoadBG2Char;
    typedef struct { u8 bytes[22]; } PathBuffer;
    PathBuffer pathBuffer = *(PathBuffer *)&data_ov001_0218fa80;
    Ov001_LoadAsset(&data_ov001_02190a0c, &GX_LoadBG2Char);
    Ov001_LoadAsset(&data_ov001_02190a24, &GX_LoadBGPltt);
    Ov001_LoadAsset(&data_ov001_02190a3c, &GX_LoadBG2Scr);
    M2C_FIELD(&gOv001IconMenuState, s32 *, 4) = Ov001_LoadFile(Ov001_LocalizePath(&pathBuffer), 0, 4);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02181c94(void) {
    extern M2C_UNK func_ov001_02181ce8;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x14, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x14);
    Ov001_SetStepCallback(&func_ov001_02181ce8);
}

void func_ov001_02181ce8(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK func_ov001_02181d24;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    Ov001_SetStepCallback(&func_ov001_02181d24);
}

void func_ov001_02181d24(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_02181d4c;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02181d4c);
}

extern void func_ov001_02181d60(void);
extern void func_ov001_02181ee4(void);
extern void func_ov001_02181ee8(void);
void func_ov001_02181d4c(void) {
    void func_ov001_02181d60(void);
    void func_ov001_02181ee4(void);
    void func_ov001_02181ee8(void);
    func_ov001_02181d60();
    func_ov001_02181ee4();
    func_ov001_02181ee8();
}

void func_ov001_02181d60(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    M2C_UNK Ov001_LayoutChoiceFrame(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_HasOptionFlag(M2C_UNK);
    void func_ov001_021820f0(M2C_UNK);
    s32 KeyPressed(s32);
    s32 KeyHeld(s32);
    s32 TouchRectPressed(void *);
    extern M2C_UNK data_ov001_0218fab6;
    extern M2C_UNK data_ov001_0218faf6;
    extern M2C_UNK data_ov001_0218faf8;
    extern M2C_UNK data_ov001_0218fafa;
    extern M2C_UNK data_ov001_0218fafc;
    extern M2C_UNK gOv001IconMenuState;

    u32 index;
    u8 *entry;
    M2C_UNK rowByte;
    M2C_UNK r12p, r1p, r2p, r3p;
    M2C_UNK r6, r5, r4, r3;

    for (index = 0; index < 4; index++) {
        entry = (u8 *)&data_ov001_0218fab6 + Ov001_HasOptionFlag(1) * 32 + index * 8;
        if (TouchRectPressed(entry) != 0) {
            Ov001_LatchIconRowSelection(1);
            M2C_FIELD(&gOv001IconMenuState, s8 *, 1) = (s8)index;
            r6 = Ov001_HasOptionFlag(1);
            r5 = Ov001_HasOptionFlag(1);
            r4 = Ov001_HasOptionFlag(1);
            r3 = Ov001_HasOptionFlag(1);
            r12p = (M2C_UNK)((u8 *)&data_ov001_0218faf6 + r6 * 32);
            rowByte = (s8)M2C_FIELD(&gOv001IconMenuState, s8 *, 1);
            r1p = (M2C_UNK)((u8 *)&data_ov001_0218fafa + r5 * 32);
            r2p = (M2C_UNK)((u8 *)&data_ov001_0218faf8 + r4 * 32);
            r5 = rowByte * 8;
            r3p = (M2C_UNK)((u8 *)&data_ov001_0218fafc + r3 * 32);
            Ov001_LayoutChoiceFrame(
                *(u16 *)((u8 *)r12p + r5),
                *(u16 *)((u8 *)r1p + r5),
                *(u16 *)((u8 *)r2p + r5),
                *(u16 *)((u8 *)r3p + r5)
            );
            return;
        }
    }
    if (KeyPressed(1) != 0) { Ov001_LatchIconRowSelection(1); return; }
    if (KeyPressed(2) != 0) { Ov001_LatchIconRowSelection(0); return; }
    if (KeyHeld(0x40) != 0) { func_ov001_021820f0(1); return; }
    if (KeyHeld(0x80) != 0) { func_ov001_021820f0(3); return; }
    if (KeyHeld(0x20) != 0) { func_ov001_021820f0(0); return; }
    if (KeyHeld(0x10) == 0) return;
    func_ov001_021820f0(2);
}

void func_ov001_02181ee4(void) {

}

void func_ov001_02181ee8(void) {
    s32 Ov001_GetIconRowSelection(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void func_ov001_021821e4(void);
    void func_ov001_02181f3c(void);
    extern M2C_UNK gOv001IconMenuState;
    switch (Ov001_GetIconRowSelection()) {
    case 0: Ov001_PlaySound(7); break;
    case 1:
        Ov001_PlaySound(6);
        func_ov001_021821e4();
        M2C_FIELD(&gOv001IconMenuState, u8 *, 2) = 1;
        break;
    default: return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02181f3c);
}

void func_ov001_02181f3c(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutMenu;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&Ov001_FadeOutMenu);
}

/* Fade out the ov001 icon menu after its choice was locked: slide the icon row
 * out when the choice was confirmed (not cancelled), fade the screen, and hand
 * over to Ov001_MenuConfirm. */
void Ov001_FadeOutMenu(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern M2C_UNK gOv001IconMenuState;
    extern M2C_UNK Ov001_MenuConfirm;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (((Ov001IconMenuState *) &gOv001IconMenuState)->confirmed != 0) {
        Ov001_StartIconRowSlideOut();
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_MenuConfirm);
}

/* Confirm/exit step of the ov001 icon menu: once the closing animation and the
 * icon row have settled, tears the screen down (frees its loaded file), starts
 * the fade and hands control to the step function of the chosen entry - a play
 * mode, the region menu (when the menu flag is set) or the map-list/name-entry
 * path (case 3). */
void Ov001_MenuConfirm(void){
extern M2C_UNK gOv001IconMenuState;
extern M2C_UNK Ov001_OpenAccessPointMenu,Ov001_OpenFriendListScreen,func_ov001_02179718,func_ov001_021803ec,InitMapListScreen;
s32 Ov001_IsFadeActive(s32);s32 Ov001_IsIconRowIdle(void);
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
if(!Ov001_IsIconRowIdle())return;
Ov001_FreeSpriteObjects();Ov001_FreeOptionBackground();Ov001_FreeFile(M2C_FIELD(&gOv001IconMenuState,void **,4));
Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,20);
if(!M2C_FIELD(&gOv001IconMenuState,u8 *,2)){Ov001_SetNextScreenMode(2,0);Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);return;}
switch(M2C_FIELD(&gOv001IconMenuState,s8 *,1)){
case 0:Ov001_SetNextScreenMode(2,1);Ov001_SetStepCallback(&Ov001_OpenFriendListScreen);return;
case 1:Ov001_SetNextScreenMode(2,1);Ov001_SetStepCallback(&func_ov001_02179718);return;
case 2:Ov001_SetNextScreenMode(2,1);Ov001_SetStepCallback(&func_ov001_021803ec);return;
case 3:Ov001_SetNextScreenMode(2,0);Ov001_SetNameEntryMode(0,0);SetMapListMode(1);Ov001_SetStepCallback(&InitMapListScreen);return;
}
}

void func_ov001_021820f0(M2C_UNK arg0) {
    M2C_UNK Ov001_HasOptionFlag(M2C_UNK);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_LayoutChoiceFrame(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gOv001IconMenuState;
    extern M2C_UNK data_ov001_0218fa96;
    extern M2C_UNK data_ov001_0218faf6;
    extern M2C_UNK data_ov001_0218fafa;
    extern M2C_UNK data_ov001_0218faf8;
    extern M2C_UNK data_ov001_0218fafc;

    s32 temp_r4;
    s32 temp_idx;
    s32 temp_offset;
    s8 temp_val;
    s32 row;
    s32 r6, r5, temp_r4b, r3;
    M2C_UNK a, b, c, d;

    temp_r4 = (s8)M2C_FIELD(&gOv001IconMenuState, s8 *, 1);
    temp_idx = Ov001_HasOptionFlag(1);
    temp_offset = (s32)&data_ov001_0218fa96 + temp_idx * 16 + temp_r4 * 4;
    temp_val = M2C_FIELD(arg0, s8 *, temp_offset);
    if (temp_val == -1) {
        return;
    }
    if (temp_val == 0) {
        M2C_FIELD(&gOv001IconMenuState, s8 *, 0) = temp_r4;
    }
    if (temp_val != -2) {
        M2C_FIELD(&gOv001IconMenuState, s8 *, 1) = temp_val;
        return;
    }

    M2C_FIELD(&gOv001IconMenuState, s8 *, 1) = M2C_FIELD(&gOv001IconMenuState, s8 *, 0);
    Ov001_PlaySound(8);
    r6 = Ov001_HasOptionFlag(1);
    r5 = Ov001_HasOptionFlag(1);
    temp_r4b = Ov001_HasOptionFlag(1);
    r3 = Ov001_HasOptionFlag(1);
    row = M2C_FIELD(&gOv001IconMenuState, s8 *, 1) * 8;

    a = *(u16 *)((u8 *)&data_ov001_0218faf6 + r6 * 32 + row);
    b = *(u16 *)((u8 *)&data_ov001_0218fafa + r5 * 32 + row);
    c = *(u16 *)((u8 *)&data_ov001_0218faf8 + temp_r4b * 32 + row);
    d = *(u16 *)((u8 *)&data_ov001_0218fafc + r3 * 32 + row);

    Ov001_LayoutChoiceFrame(a, b, c, d);
}

void func_ov001_021821e4(void) {
    M2C_UNK Ov001_LoadObjTile(s32, u8, u8);
    struct Table { u8 values[4]; };
    extern struct Table data_ov001_0218fa7c;
    extern M2C_UNK gOv001IconMenuState;
    struct Table table = data_ov001_0218fa7c;
    u8 value = table.values[M2C_FIELD(&gOv001IconMenuState, s8 *, 1)];
    Ov001_LoadObjTile(M2C_FIELD(&gOv001IconMenuState, s32 *, 4), value, value);
}

/* Entry step of the online match's WFC connect screen: load its background, show
 * the "connecting" panel and the selected save slot's map sprite on the plain
 * map path, set up the menu, then start the WFC connection and hand over to the
 * fade-in step. */
void Ov001_OpenWfcConnectScreen(void) {
    M2C_UNK Ov001_CreateAnimSprite(M2C_UNK);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_OpenMenuForMode(M2C_UNK);
    M2C_UNK Ov001_LoadSaveSlotObjLayout();
    M2C_UNK Ov001_ShowWfcIcon(M2C_UNK);
    void Ov001_LoadWfcConnectBg(void);
    void Ov001_StartWfcConnect(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    extern s8 gOv001WfcConnected;
    extern M2C_UNK Ov001_FadeInWfcConnectScreen;
    s32 nameEntryMode;

    gOv001WfcConnected = 0;
    Ov001_LoadWfcConnectBg();
    Ov001_GetNameEntryMode(0, &nameEntryMode);
    if (nameEntryMode == 0) {
        Ov001_ShowMessagePanel(OV001_MSG_CONNECTING, -1, 0);
    }
    Ov001_OpenMenuForMode(2);
    if (nameEntryMode == 0) {
        Ov001_LoadSaveSlotObjLayout();
    }
    Ov001_ShowMessageBox(0x2C);
    Ov001_CreateAnimSprite(0);
    Ov001_StartWfcConnect();
    Ov001_ShowWfcIcon(0);
    Ov001_PlaySound(0xC);
    Ov001_SetStepCallback(&Ov001_FadeInWfcConnectScreen);
}

/* Loads the WFC connection screen's background: tile graphics, palette and map,
 * then puts BG0/BG1 on the lowest priority. */
void Ov001_LoadWfcConnectBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcConnectBgTilesPath, gOv001WfcConnectBgPalettePath, gOv001WfcConnectBgMapPath;
    extern M2C_UNK GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001WfcConnectBgTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001WfcConnectBgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001WfcConnectBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_SUB_BG1CNT = (REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (REG_BG1CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG2CNT = (REG_BG2CNT & ~BG_PRIORITY_MASK) | 3;
}

/* Starts the Wi-Fi (WFC) connection for the current save slot: copies the WFC
 * init-parameter template, selects the saved friend list to connect with (4 when
 * the name was just entered, otherwise the save slot + 1), initializes WFC and
 * halts when that fails, publishes the slot's record for the normal map path and
 * queues the connection step task. */
void Ov001_StartWfcConnect(void) {
    extern u8 sWfcInitParams[];
    extern void Ov001_WfcConnectStep(s32);

    void *mapRecord;
    M2C_UNK nameEntryMode;
    u8 wfcParams[12];

    mapRecord = GetCurrentMapRecord();
    MIi_CpuCopy32(sWfcInitParams, wfcParams, 0xC);
    Ov001_GetNameEntryMode(0, &nameEntryMode);
    if (nameEntryMode == 2) {
        wfcParams[10] = 4;
    } else {
        wfcParams[10] = M2C_FIELD(mapRecord, u8 *, SAVE_SLOT_INDEX_REL) + 1;
    }
    if (WFC_Init(wfcParams) == 0) {
        SystemHalt();
    }
    if (nameEntryMode == 0) {
        Wfc_SetSlotImage(M2C_FIELD(mapRecord, u8 *, SAVE_SLOT_INDEX_REL), mapRecord);
    }
    Ov001_AddTask(0, (void *)Ov001_WfcConnectStep, 0, 0x78);
}

/* Start the Wi-Fi connect screen's fade-in: fade in the main screen's plane set
 * and, when no name was just entered, the second screen's too, then wait for the
 * fade to finish. */
void Ov001_FadeInWfcConnectScreen(void) {
    void Ov001_WaitWfcConnectFadeIn(void);
    s32 nameEntryArg;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_GetNameEntryMode(0, &nameEntryArg);
    if (nameEntryArg == 0) {
        Ov001_StartFade(2, 1, 1, 8);
        Ov001_EnableVisiblePlanes(1, 1);
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WaitWfcConnectFadeIn);
}

void Ov001_WaitWfcConnectFadeIn(void) {
    extern M2C_UNK func_ov001_021824a8;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_021824a8);
}

void func_ov001_021824a8(void) {
    void func_ov001_021824bc(void);
    void func_ov001_021824c0(void);
    void func_ov001_021824c4(void);
    func_ov001_021824bc();
    func_ov001_021824c0();
    func_ov001_021824c4();
}

void func_ov001_021824bc(void) {

}

void func_ov001_021824c0(void) {

}

void func_ov001_021824c4(void) {

}

void Ov001_FadeOutWfcConnectScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021824f0;
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_021824f0);
}

void func_ov001_021824f0(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_CloseWfcConnectScreen;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_CloseWfcConnectScreen);
}

/* Close the Wi-Fi connect screen once the connection attempt has finished:
 * store the console's Wi-Fi profile code in the first two save slots, free the
 * screen's sprites and backgrounds, then show the success or error screen
 * according to the connection result. */
void Ov001_CloseWfcConnectScreen(void) {
    s32 GetSaveData();
    s32 Wfc_EndSession();
    s32 GetWfcProfileCode();
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    M2C_UNK Ov001_FreeOptionSprites();
    M2C_UNK Ov001_FreePageBackground(s32);
    M2C_UNK Ov001_DisableVisiblePlanes(s32, s32);
    M2C_UNK Ov001_SetNextScreenMode(s32, s32);
    extern s8 gOv001WfcConnected;
    extern M2C_UNK Ov001_ShowWfcErrorScreen;
    void Ov001_ShowWfcSuccessScreen(void);
    s32 saveData;

    saveData = GetSaveData();
    if (Wfc_EndSession() == 0) return;
    MI_CpuCopy8(GetWfcProfileCode(), saveData + SAVE_SLOT_CODE, SAVE_SLOT_PROFILE_CODE_SIZE);
    MI_CpuCopy8(GetWfcProfileCode(), saveData + SAVE_SLOT_SIZE + SAVE_SLOT_CODE, SAVE_SLOT_PROFILE_CODE_SIZE);
    Ov001_FreeOptionSprites();
    Ov001_FreePageBackground(0);
    Ov001_DisableVisiblePlanes(0, 0x15);
    if ((u8) gOv001WfcConnected == 0) {
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(&Ov001_ShowWfcErrorScreen);
        return;
    }
    Ov001_SetNextScreenMode(0, 1);
    Ov001_SetStepCallback((M2C_UNK *) &Ov001_ShowWfcSuccessScreen);
}

/* Wi-Fi connection step task: advance the WFC session; once it finishes, stop
 * the connecting icon and sound, flag a successful connection (or record the
 * failure progress) with its sound, then fade the screen out and finish the task. */
void Ov001_WfcConnectStep(s32 task) {
    s32 Wfc_ProcessStep(void);
    s32 GetWfcSessionProgress(void);
    void Ov001_SetWfcErrorCode(s32);
    extern s8 gOv001WfcConnected;
    s32 result = Wfc_ProcessStep();
    if (result == 0) return;
    Ov001_HideWfcIcon();
    Ov001_StopSound();
    if (result > 0) {
        gOv001WfcConnected = 1;
        Ov001_PlaySound(0x11);
    } else {
        Ov001_SetWfcErrorCode(GetWfcSessionProgress());
        Ov001_PlaySound(0x12);
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeOutWfcConnectScreen);
    Ov001_PostTaskMessage(0, task);
}

void func_ov001_02182614(s32 arg0, s32 arg1) {
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    Ov001_Alloc(arg1, 0x20);
}

void func_ov001_02182628(s32 arg0, s32 arg1) {
    M2C_UNK func_ov001_0218b760(M2C_UNK);
    func_ov001_0218b760(arg1);
}

void Ov001_ShowWfcSuccessScreen(void) {
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    void Ov001_LoadWfcSuccessBackground();
    extern u8 gOv001WfcSuccessFrames;
    extern M2C_UNK func_ov001_021826d4;
    gOv001WfcSuccessFrames = 0;
    Ov001_LoadWfcSuccessBackground();
    Ov001_ShowMessageBox(0x2D);
    Ov001_SetStepCallback(&func_ov001_021826d4);
}

/* Load the WFC success screen's background map into BG2 and give the sub- and
 * main-engine background layers it uses priority 3. */
void Ov001_LoadWfcSuccessBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcSuccessBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001WfcSuccessBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

void func_ov001_021826d4(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02182708;
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_02182708);
}

void func_ov001_02182708(void) {
    extern M2C_UNK func_ov001_0218272c;
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_0218272c);
}

void func_ov001_0218272c(void) {
    void Ov001_WfcSuccessTimeoutStep(void);
    void func_ov001_0218273c(void);
    Ov001_WfcSuccessTimeoutStep();
    func_ov001_0218273c();
}

void func_ov001_0218273c(void) {

}

void Ov001_LeaveWfcSuccessScreen(void) {
    M2C_UNK Ov001_GetNameEntryMode(M2C_UNK, s32 *);
    M2C_UNK func_ov001_0218560c();
    extern M2C_UNK Ov001_FinishWfcScreen;
    s32 sp0;

    Ov001_GetNameEntryMode(0, &sp0);
    if (sp0 != 0) {
        func_ov001_0218560c();
    }
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&Ov001_FinishWfcScreen);
}

/* Last step of the Wi-Fi (WFC) screen: waits for both close fades and for the menu
   layout to settle, frees the screen's backgrounds and hides its planes, then goes to
   the map list when the name entry mode is 0 and to the Wi-Fi menu otherwise. */
void Ov001_FinishWfcScreen(void) {
    M2C_UNK Ov001_FreeOptionBackground();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNameEntryMode(M2C_UNK, M2C_UNK);
    s32 Ov001_IsMenuLayoutReady();
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_OpenWifiMenu;
    extern M2C_UNK InitMapListScreen;
    s32 nameEntryMode;

    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    if (Ov001_IsMenuLayoutReady() == 0) {
        return;
    }
    Ov001_FreePageBackground(0);
    Ov001_FreeOptionBackground();
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x15);
    Ov001_SetNextScreenMode(2, 1);
    Ov001_GetNameEntryMode(0, &nameEntryMode);
    if (nameEntryMode == 0) {
        Ov001_SetNameEntryMode(0, 0);
        Ov001_SetStepCallback(&InitMapListScreen);
        return;
    }
    Ov001_SetStepCallback(&Ov001_OpenWifiMenu);
}

/* Step that holds the Wi-Fi success screen for OV001_WFC_SUCCESS_FRAMES frames,
 * then picks the next step: shut the screen down when the layout is the Wi-Fi
 * layout and a name entry is pending, otherwise fade on to the map list or the
 * Wi-Fi menu. */
void Ov001_WfcSuccessTimeoutStep(void) {
    s32 Ov001_GetScreenLayout(void);
    extern u8 gOv001WfcSuccessFrames;
    extern M2C_UNK Ov001_FadeToShutdownScreen;
    s32 nameEntryMode;
    s32 layout;

    if ((u32)++gOv001WfcSuccessFrames < OV001_WFC_SUCCESS_FRAMES) return;
    Ov001_GetNameEntryMode(0, &nameEntryMode);
    layout = Ov001_GetScreenLayout();
    if ((layout != 0) && (layout == 1) && (nameEntryMode != 0)) {
        Ov001_SetStepCallback(&Ov001_FadeToShutdownScreen);
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_LeaveWfcSuccessScreen);
}

void Ov001_PrepareSaveSlotMenu(void) {
    M2C_UNK func_ov001_02183fa0(void);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_LoadSaveSlotObjLayout(void);
    M2C_UNK CommitSaveSlot(void);
    void Ov001_LoadSaveSlotMenuBg(void);
    void func_ov001_02182970(void);
    s32 sp0;
    func_ov001_02183fa0();
    Ov001_GetNameEntryMode(0, &sp0);
    Ov001_LoadSaveSlotMenuBg();
    Ov001_ShowMessagePanel(0x31, -1, 0);
    if (sp0 != 2) Ov001_LoadSaveSlotObjLayout();
    if (sp0 == 1) CommitSaveSlot();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02182970);
}

/* Load the save slot menu's background map and lower the priority of the sub
 * engine's BG0/BG1 and the main engine's BG1/BG2. */
void Ov001_LoadSaveSlotMenuBg(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001SaveSlotMenuBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;

    Ov001_LoadAsset(&gOv001SaveSlotMenuBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16) ((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16) ((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG1CNT = (u16) ((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16) ((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

void func_ov001_02182970(void) {
    extern M2C_UNK Ov001_ShowSaveSlotMenu;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x14, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x14);
    Ov001_SetStepCallback(&Ov001_ShowSaveSlotMenu);
}

/* Fade-in step of the save-slot menu: once both fades are done, it shows the menu
 * with the title its name-entry argument picks (a save that went through the name
 * entry and one started without it get different texts) and hands over to the
 * step that waits for a row and closes the menu. */
void Ov001_ShowSaveSlotMenu(void) {
    struct Titles { s32 values[3]; }; /* one message id per name-entry argument */
    extern struct Titles gOv001SaveSlotMenuTitles;
    extern M2C_UNK Ov001_CloseSaveSlotMenuStep;
    M2C_UNK Ov001_ShowMessage(s32, s32, s32, s32, s32);
    struct Titles titles = gOv001SaveSlotMenuTitles;
    s32 nameEntryArg;

    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_GetNameEntryMode(0, &nameEntryArg);
    Ov001_ShowMessage(titles.values[nameEntryArg], 1, 1, -1, 0);
    Ov001_SetStepCallback(&Ov001_CloseSaveSlotMenuStep);
}

