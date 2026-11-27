/* 23 functions from 0x0217CCE8 to 0x0217DC7C (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ov001_wh.h"
extern M2C_UNK gMapListState;
extern const u8 gMapListChoiceRow[];
void MapList_DismissMessage(void);
void MapList_BeginExit(void);
void MapListSetExtraEmptyA(s32);
void MapListSetExtraEmptyB(s32);

void *GetCurrentMapRecord();

/* Draws the ov001 Wi-Fi failure panel: the error code as a number above the
 * panel, then the message that explains that kind of failure, and closes the
 * panel again.  gOv001WfcErrorCode is the negated WFC error code the failed
 * connection step left (a failure reports -50000 - detail and so on), so each
 * range of codes picks a message index of the overlay's text archive; a
 * failure that came from mode 2 gets a message of its own. */
void DrawWfcErrorPanel(void) {
extern s32 gOv001WfcErrorCode;
extern const u8 gOv001PanelBackgroundIndex[];
extern s32 gOv001MessageArchive;
extern u16 gOv001ErrorCodeFormat[];
extern const u16 gOv001ErrorCodeTextY[], gOv001ErrorCodeTextX[];
void *CreateTextPanel(s32,s32);
s32 Ov001_GetMessageText(s32,s32);
s32 StringFormatWide(void *,s32,void *,...);
void DrawTextRun(void *,s32,s32,s32,s32,u16 *,s32);
void DrawPanelText(void *,s32,s32,s32,s32,s32,s32,s32);
void CloseTextPanel(void *);
s32 Ov001_GetTextFontId(void);
u8 Ov001_GetLanguage(void);
s32 mode, messageCode, messageText; void *panel; u16 text[8]; u16 textY; s32 textX;
Ov001_GetNameEntryMode(0,&mode);
if(gOv001WfcErrorCode >= -20099) messageCode = 0;
else if(gOv001WfcErrorCode >= -20100) messageCode = 2;
else if(gOv001WfcErrorCode >= -20101) messageCode = 19;
else if(gOv001WfcErrorCode >= -20107) messageCode = 2;
else if(gOv001WfcErrorCode >= -20108) messageCode = 18;
else if(gOv001WfcErrorCode >= -20109) messageCode = 2;
else if(gOv001WfcErrorCode >= -20110) messageCode = 3;
else if(gOv001WfcErrorCode >= -20999) messageCode = 2;
else if(gOv001WfcErrorCode >= -22999) messageCode = 0;
else if(gOv001WfcErrorCode >= -23999) messageCode = 19;
else if(gOv001WfcErrorCode >= -49999) messageCode = 0;
else if(gOv001WfcErrorCode >= -50002) messageCode = 7;
else if(gOv001WfcErrorCode >= -50003) messageCode = 5;
else if(gOv001WfcErrorCode >= -50098) messageCode = 0;
else if(gOv001WfcErrorCode >= -50099) messageCode = mode == 2 ? 5 : 7;
else if(gOv001WfcErrorCode >= -51098) messageCode = 0;
else if(gOv001WfcErrorCode >= -51099) messageCode = mode == 2 ? 5 : 8;
else if(gOv001WfcErrorCode >= -51102) messageCode = 9;
else if(gOv001WfcErrorCode >= -51103) messageCode = 5;
else if(gOv001WfcErrorCode >= -51199) messageCode = 0;
else if(gOv001WfcErrorCode >= -51299) messageCode = 20;
else if(gOv001WfcErrorCode >= -51302) messageCode = 21;
else if(gOv001WfcErrorCode >= -51303) messageCode = 4;
else if(gOv001WfcErrorCode >= -51999) messageCode = 0;
else if(gOv001WfcErrorCode >= -52002) messageCode = 10;
else if(gOv001WfcErrorCode >= -52003) messageCode = 22;
else if(gOv001WfcErrorCode >= -52099) messageCode = 0;
else if(gOv001WfcErrorCode >= -52103) messageCode = 11;
else if(gOv001WfcErrorCode >= -52199) messageCode = 0;
else if(gOv001WfcErrorCode >= -52203) messageCode = 11;
else if(gOv001WfcErrorCode >= -52299) messageCode = 0;
else if(gOv001WfcErrorCode >= -52399) messageCode = 2;
else if(gOv001WfcErrorCode >= -52999) messageCode = 0;
else if(gOv001WfcErrorCode >= -53299) messageCode = 2;
else messageCode=0;
panel=CreateTextPanel(0,gOv001PanelBackgroundIndex[Ov001_GetLanguage()]);
messageText=Ov001_GetMessageText(gOv001MessageArchive,messageCode);
StringFormatWide(text,8,gOv001ErrorCodeFormat,-gOv001WfcErrorCode);
textY=gOv001ErrorCodeTextY[Ov001_GetLanguage()*2];
textX=gOv001ErrorCodeTextX[Ov001_GetLanguage()*2];
DrawTextRun(panel,textX,textY,2,10,text,0);
DrawPanelText(panel,13,60,230,94,2,Ov001_GetTextFontId(),messageText);
CloseTextPanel(panel);
}

/* Step that brings up the ov001 Wi-Fi error screen: fade the main engine's
 * background layers and objects in from white, make those planes visible, and
 * hand over to the step that waits for the fade and then draws the error
 * panel. */
void Ov001_FadeInWfcErrorScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_WfcErrorFadeDone;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN,
                    OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN,
                              OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ);
    Ov001_SetStepCallback(&Ov001_WfcErrorFadeDone);
}

/* Step that runs once the Wi-Fi error screen's fade-in has finished: wait for the
 * sub and main engine fades, then put up its single-button icon row and hand over
 * to the step that waits for it to slide in. */
void Ov001_WfcErrorFadeDone(void) {
    void Ov001_WfcErrorWaitIconRow(void);
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) return;
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) return;
    Ov001_CreateMenuIconRow(4);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_WfcErrorWaitIconRow);
}

/* Step that waits for the Wi-Fi error screen's icon row to finish sliding in:
 * once the row takes input, unlock it and hand over to the screen's update
 * step. */
void Ov001_WfcErrorWaitIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK Ov001_UpdateWfcErrorScreen;
    if (Ov001_GetIconRowSelection() == OV001_ICON_ROW_NOT_READY) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&Ov001_UpdateWfcErrorScreen);
}

void Ov001_UpdateWfcErrorScreen(void) {
    void Ov001_WfcErrorMenuConfirmInput(void);
    void func_ov001_0217d110(void);
    void Ov001_ConfirmWfcErrorChoice(void);
    Ov001_WfcErrorMenuConfirmInput();
    func_ov001_0217d110();
    Ov001_ConfirmWfcErrorChoice();
}

/* Wi-Fi error screen's A/confirm input: latch its single OK icon. */
void Ov001_WfcErrorMenuConfirmInput(void) {
    M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(KEY_PRESSED) == 0) {
        return;
    }
    Ov001_LatchIconRowSelection(0);
}

void func_ov001_0217d110(void) {

}

/* The Wi-Fi error screen's icon row was accepted (its only icon is "OK"): play
 * the confirm sound and hand over to the step that closes the screen. */
void Ov001_ConfirmWfcErrorChoice(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void Ov001_PrepareCloseWfcErrorScreen(void);
    if (Ov001_GetIconRowSelection() != 0) return;
    Ov001_PlaySound(OV001_SOUND_CONFIRM);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_PrepareCloseWfcErrorScreen);
}

/* Wi-Fi error screen exit step: lock its single-button icon row, hold it for a
 * few frames, then hand the step over to the screen's fade-out. */
void Ov001_PrepareCloseWfcErrorScreen(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutWfcErrorScreen;
    Ov001_LockIconRow();
    Ov001_StartDelay(OV001_STEP_DELAY_FRAMES);
    Ov001_SetStepCallback(&Ov001_FadeOutWfcErrorScreen);
}

/* Fade out of the ov001 Wi-Fi error screen: wait for the icon row to start
 * sliding out, then start both white fades (the sub plane and the main plane
 * with its background layers and objects) and move to the step that leaves. */
void Ov001_FadeOutWfcErrorScreen(void) {
    M2C_UNK Ov001_StartIconRowSlideOut();
    extern M2C_UNK Ov001_LeaveWfcErrorScreen;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    Ov001_StartIconRowSlideOut();
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG0 | OV001_BLEND_BG2 | OV001_BLEND_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_LeaveWfcErrorScreen);
}

/* Final step leaving the ov001 Wi-Fi error screen: once its closing fades have
 * finished and the icon row has settled, tear the screen down and hand over to
 * the access point menu if a name-entry variant is pending, or back to the map
 * list otherwise. */
void Ov001_LeaveWfcErrorScreen(void) {
    s32 Ov001_IsIconRowIdle();
    M2C_UNK Ov001_FreeMessagePanel();
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNameEntryMode(M2C_UNK, M2C_UNK);
    M2C_UNK SetMapListMode(M2C_UNK);
    M2C_UNK Ov001_FreePageBackground(M2C_UNK);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_GetNameEntryMode(M2C_UNK, s32 *);
    extern M2C_UNK InitMapListScreen;
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    s32 nameEntryVariant;

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
    Ov001_GetNameEntryMode(0, &nameEntryVariant);
    if (nameEntryVariant != 0) {
        Ov001_SetNextScreenMode(2, 1);
        Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);
        return;
    }
    Ov001_SetNextScreenMode(2, 0);
    Ov001_SetNameEntryMode(0, 0);
    SetMapListMode(0);
    Ov001_SetStepCallback(&InitMapListScreen);
}

void Ov001_SetWfcErrorCode(s32 arg0) {
    extern s32 gOv001WfcErrorCode;
    gOv001WfcErrorCode = arg0;
}

/* Build the map-list screen: allocate its list object, load its backgrounds and
 * text, size the scrollbar from the scroll position, create the seven entry
 * sprites and the two scroll callbacks, then start the input step. */
void InitMapListScreen(void) {
    void *GetCurrentMapRecord(void);
    void *Ov001_Alloc(s32, s32);
    extern M2C_UNK gMapListState;
    void ResetMapListState(void);
    void InitMapListGraphics(void);
    u8 Ov001_GetLanguage(void);
    M2C_UNK Ov001_ShowMessagePanel(s32, s32, s32);
    void Ov001_OpenMenuForMode(M2C_UNK);
    void Ov001_LoadMapListSlotObjLayout(void);
    M2C_UNK Ov001_CreateScrollBar(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void *CreateTextPanel(s32, s32);
    void *Ov001_CreateSpriteFromLayout(s32, s32);
    void *Ov001_AddTask(s32, void (*)(void), s32, s32);
    M2C_UNK MapListRedrawInfoPanel(void);
    void MapList_ApplyRowLayout(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern s8 data_ov001_0218f99c[];
    void MapListUpdateBackgroundScroll(void);
    void MapListUpdateRowHighlightTimers(void);
    void Ov001_FadeInMapList(void);

    void *profile;
    s32 i;
    u8 value;
    void *sprite;

    profile = GetCurrentMapRecord();
    M2C_FIELD(&gMapListState, void **, 8) = Ov001_Alloc(0x48, 4);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x43) = M2C_FIELD(profile, u8 *, 0xf6);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x42) = 0xc;
    ResetMapListState();
    InitMapListGraphics();
    if (M2C_FIELD(&gMapListState, u8 *, 1) == 0) {
        value = Ov001_GetLanguage();
        Ov001_ShowMessagePanel(0x30, (s32)data_ov001_0218f99c[value], M2C_FIELD(profile, u8 *, 0xf4) + 1);
    } else {
        Ov001_ShowMessagePanel(0x45, -1, 0);
    }
    Ov001_OpenMenuForMode(1);
    Ov001_LoadMapListSlotObjLayout();
    Ov001_CreateScrollBar(2, 0x55, 0xf1, 0x41,
                        (M2C_FIELD(&gMapListState, u16 *, 4) * 55) / 145);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x14) = CreateTextPanel(0, 1);
    for (i = 0; i < 7; i++) {
        ((void **)M2C_FIELD(&gMapListState, void **, 8))[i + 6] = Ov001_CreateSpriteFromLayout(0, 0x29);
    }
    value = M2C_FIELD(profile, u8 *, 0xe7);
    switch (value) {
        case 1: {
            sprite = Ov001_CreateSpriteFromLayout(0, 0x50);
            M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34) = sprite;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) =
                (M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) & ~0xc00) | 0xc00;
            break;
        }
        case 2: {
            sprite = Ov001_CreateSpriteFromLayout(0, 0x51);
            M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34) = sprite;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) =
                (M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) & ~0xc00) | 0xc00;
            break;
        }
    }
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x3c) = Ov001_AddTask(1, (void (*)(void))MapListUpdateBackgroundScroll, 0, 0x6e);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x00) = Ov001_AddTask(0, (void (*)(void))MapListUpdateRowHighlightTimers, 0, 0x78);
    MapListRedrawInfoPanel();
    MapList_ApplyRowLayout();
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInMapList);
}

/* Set up the map-list screen's graphics: load the two background tile/palette
 * sets and the list-background tilemaps into VRAM, create the background list
 * objects and point the layered background control registers at them. */
void InitMapListGraphics(void) {
    M2C_UNK Ov001_GetLocalizedFileName(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    M2C_UNK Ov001_LoadFile(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK InitMapPreview(M2C_UNK);
    M2C_UNK RequestMapPreviewUpdate(void);
    extern u8 sJb3ListBackPath[];
    extern u8 sYbBgStep2NclPath[];
    extern u8 sYbBgStep21NclPath[];
    extern M2C_UNK sYbObjKbPath, sJbBgStep2NcgPath, sJbBgStep21NcgPath, sJb3ListNscPath;
    extern M2C_UNK gMapListState;
    extern M2C_UNK GX_LoadOBJPltt, GX_LoadBG3Char, GX_LoadBG2Char, GX_LoadBGPltt, GX_LoadBG3Scr;
    typedef struct { u8 bytes[23]; } ListBackPath;
    typedef struct { u8 bytes[21]; } BgStep2Path;
    typedef struct { u8 bytes[22]; } BgStep21Path;
    ListBackPath listBackPath = *(ListBackPath *)sJb3ListBackPath;
    BgStep2Path bgStep2Path = *(BgStep2Path *)sYbBgStep2NclPath;
    BgStep21Path bgStep21Path = *(BgStep21Path *)sYbBgStep21NclPath;

    /* main BG2: 256-colour tiles, 512x256 map */
    M2C_FIELD((void *)0x0400000C, volatile u16 *, 0) =
        (M2C_FIELD((void *)0x0400000C, volatile u16 *, 0) & 0x43) | 0x218 | 0xC00;

    Ov001_LoadAsset(&sYbObjKbPath, &GX_LoadOBJPltt);      /* UI palette */
    Ov001_LoadAsset(&sJbBgStep2NcgPath, &GX_LoadBG3Char); /* background tiles, step 2 */
    Ov001_LoadAsset(&sJbBgStep21NcgPath, &GX_LoadBG2Char);/* background tiles, step 21 */
    Ov001_LoadAsset((void *)&bgStep2Path, &GX_LoadBGPltt);   /* background palette, step 2 */
    Ov001_LoadAsset(&sJb3ListNscPath, &GX_LoadBG3Scr);   /* list tilemap */

    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 8) =
        Ov001_LoadFile(Ov001_GetLocalizedFileName((void *)&listBackPath), 0, 4);
    InitMapPreview(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 8));
    RequestMapPreviewUpdate();
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 12) =
        Ov001_LoadFile(Ov001_GetLocalizedFileName((void *)&bgStep2Path), 0, 4);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 16) =
        Ov001_LoadFile(Ov001_GetLocalizedFileName((void *)&bgStep21Path), 0, 4);

    /* sub BG0/BG1 and main BG0/BG1: 256-colour tiled layers */
    M2C_FIELD((void *)0x04001008, volatile u16 *, 0) = (M2C_FIELD((void *)0x04001008, volatile u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, volatile u16 *, 2) = (M2C_FIELD((void *)0x04001008, volatile u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x04000008, volatile u16 *, 0) = (M2C_FIELD((void *)0x04000008, volatile u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, volatile u16 *, 0) = (M2C_FIELD((void *)0x0400000A, volatile u16 *, 0) & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, volatile u16 *, 2) = (M2C_FIELD((void *)0x0400000A, volatile u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, volatile u16 *, 4) = (M2C_FIELD((void *)0x0400000A, volatile u16 *, 4) & ~3) | 2;
}

/* Set up the ov001 map list's position: unless the screen was reached from the
 * name-entry step (a pending name-entry variant), start the list at the top with
 * no scroll, state 0 and row 0 selected. */
void ResetMapListState(void) {
    M2C_UNK Ov001_GetNameEntryMode(M2C_UNK, s32 *);
    void *GetCurrentMapRecord();
    extern M2C_UNK gMapListState;
    s32 nameEntryVariant;

    GetCurrentMapRecord();
    Ov001_GetNameEntryMode(0, &nameEntryVariant);
    if (nameEntryVariant != 0) {
        return;
    }
    M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL) = 0;
    M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_STATE) = 0;
    M2C_FIELD(&gMapListState, u8 *, OV001_MAP_LIST_ROW) = 0;
}

/* Fades in the ov001 map-list screen: start the sub and main fades from white
 * with the list's background and object planes, show those planes, then run the
 * step that starts the map list's input handling once both fades have finished. */
void Ov001_FadeInMapList(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_StartMapListInput(void);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, GX_PLANEMASK_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_StartMapListInput);
}

/* Step that follows the ov001 map list's fade-in: wait until both the sub and the
 * main fade have finished, then hand the step over to the per-frame map list
 * input update. */
void Ov001_StartMapListInput(void) {
    extern M2C_UNK Ov001_UpdateMapListInput;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_SetStepCallback(&Ov001_UpdateMapListInput);
}

void Ov001_UpdateMapListInput(void) {
    M2C_UNK MapListHandleState();
    void func_ov001_0217d754(void);
    func_ov001_0217d754();
    MapListHandleState();
}

void func_ov001_0217d754(void) {
    extern M2C_UNK gMapListState;
    extern M2C_UNK MapListScrollDown;
    extern M2C_UNK MapListScrollUp;
    s32 HandleMapListTouchChoice(void);
    s32 KeyPressed(s32);
    s32 KeyHeld(s32);
    s32 KeyReleased(s32);
    M2C_UNK DispatchMapListChoice(u32);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void *Ov001_AddTask(s32, void (*)(void), s32, s32);
    M2C_UNK func_ov001_0217f1f0(s32);
    void *obj;

    obj = M2C_FIELD(&gMapListState, void **, 8);
    if (M2C_FIELD(obj, void **, 0x38) != 0 || M2C_FIELD(obj, u8 *, 0x45) != 0) {
        return;
    }
    if (HandleMapListTouchChoice() != 0) {
        return;
    }
    if (KeyPressed(1) != 0) {
        DispatchMapListChoice(M2C_FIELD(&gMapListState, u8 *, 0));
        return;
    }
    if (KeyPressed(2) != 0) {
        Ov001_PlaySound(7);
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x40) = 0xd;
        Ov001_SetStepCallback((M2C_UNK *)&MapList_BeginExit);
        return;
    }
    if (KeyHeld(0x200) != 0) {
        if (M2C_FIELD(&gMapListState, u16 *, 4) == 0x91) {
            if (M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) == 0) {
                Ov001_PlaySound(9);
                M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 1;
            }
            return;
        }
        Ov001_PlaySound(0x13);
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x38) =
            Ov001_AddTask(0, (void (*)(void))&MapListScrollDown, 0, 0x78);
        return;
    }
    if (KeyReleased(0x200) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x100) != 0) {
        if (M2C_FIELD(&gMapListState, u16 *, 4) == 0) {
            if (M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) == 0) {
                Ov001_PlaySound(9);
                M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 1;
            }
            return;
        }
        Ov001_PlaySound(0x13);
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x38) =
            Ov001_AddTask(0, (void (*)(void))&MapListScrollUp, 0, 0x78);
        return;
    }
    if (KeyReleased(0x100) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x40) != 0) {
        func_ov001_0217f1f0(1);
        return;
    }
    if (KeyReleased(0x40) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x80) != 0) {
        func_ov001_0217f1f0(3);
        return;
    }
    if (KeyReleased(0x80) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x20) != 0) {
        func_ov001_0217f1f0(0);
        return;
    }
    if (KeyHeld(0x10) == 0) {
        return;
    }
    func_ov001_0217f1f0(2);
}

/* Handle a touch selection on the ov001 map list: ignore an untouched frame,
 * refuse an entry the working save slot does not allow, select the row, start
 * the highlight of the custom-map row entries and carry the choice out. */
s32 HandleMapListTouchChoice(void) {
    M2C_UNK DispatchMapListChoice(u32);
    s32 IsMapListChoiceAvailable();
    u32 GetMapListTouchedEntry();
    M2C_UNK SelectMapListChoice(u32);
    M2C_UNK MapListHighlightCustomRow();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    u32 choice;

    GetCurrentMapRecord();
    choice = GetMapListTouchedEntry();
    if (choice == OV001_MAP_LIST_NO_TOUCH) {
        return 0;
    }
    if (IsMapListChoiceAvailable() == 0) {
        Ov001_PlaySound(9);
        return 1;
    }
    SelectMapListChoice(choice);
    switch (choice) {
    default:
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        MapListHighlightCustomRow();
        break;
    }
    DispatchMapListChoice(choice);
    return 1;
}

/* Dispatch a screen selection (0..13): set up UI state, graphics, and continue via MapList_BeginExit. */
s32 DispatchMapListChoice(u32 a){
if(IsMapListChoiceAvailable()==0){Ov001_PlaySound(9);return;}
switch(a){
case 2:case 3:Ov001_PlaySound(6);MapListSetExtraEmptyA(((a-2)^1)!=0);return;
case 7:case 8:Ov001_PlaySound(6);MapListSetExtraEmptyB(((a-7)^1)!=0);return;
case 0:case 1:case 4:case 5:case 6:break;
}
M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)=a;
if(a-11<=1){
MapList_UploadSubScreenIcon();
if(IsCurrentSaveSlotValid()==0){
Ov001_PlaySound(9);Ov001_ShowMessage(6,1,1,-1,0);Ov001_SetStepCallback((M2C_UNK *)MapList_DismissMessage);return;
}
if(a==11)Ov001_PlaySound(6);else Ov001_PlaySound(14);
}else if(a==13){MapList_UploadSubScreenIcon();Ov001_PlaySound(7);}
else {Ov001_PlaySound(6);func_ov001_0217e67c(0,1,GetMapListScreenRow(gMapListChoiceRow[a]));MapListUpdateRowSprites();}
Ov001_BlockScrollBar();Ov001_SetStepCallback((M2C_UNK *)MapList_BeginExit);
}

/* Set whether the current map's first optional player code is absent
 * (SAVE_SLOT_EMPTY_A) in the working save slot.  When the flag is cleared, the
 * record's second flag is taken back into the screen's cached copy; the cached
 * copy is written back either way, and the info panel is redrawn. */
void MapListSetExtraEmptyA(s32 empty) {
    M2C_UNK MapListRedrawInfoPanel();
    M2C_UNK Ov001_SetSaveExtraEmptyA(s32);
    M2C_UNK Ov001_SetSaveExtraEmptyB(s32);
    extern M2C_UNK gMapListState;
    s32 emptyB;
    void *record;

    record = GetCurrentMapRecord();
    if (M2C_FIELD(record, u8 *, SAVE_SLOT_EMPTY_A) == empty) return;
    if (empty != 0) {
        emptyB = M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), u8 *, OV001_MAP_LIST_EMPTY_B) != 0;
    } else {
        emptyB = 0;
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), u8 *, OV001_MAP_LIST_EMPTY_B) = M2C_FIELD(record, u8 *, SAVE_SLOT_EMPTY_B);
    }
    Ov001_SetSaveExtraEmptyA(empty);
    Ov001_SetSaveExtraEmptyB(emptyB);
    MapListRedrawInfoPanel();
}

/* Set whether the current map's second optional player code is absent
 * (SAVE_SLOT_EMPTY_B) in the working save slot: nothing to do when the flag
 * already matches, otherwise cache it in the screen object, hand it to the save
 * slot and redraw the info panel. */
void MapListSetExtraEmptyB(s32 empty) {
    M2C_UNK MapListRedrawInfoPanel();
    M2C_UNK Ov001_SetSaveExtraEmptyB(s32);
    extern M2C_UNK gMapListState;
    s32 current;

    current = M2C_FIELD(GetCurrentMapRecord(), u8 *, SAVE_SLOT_EMPTY_B);
    if (current == empty) return;
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), u8 *, OV001_MAP_LIST_EMPTY_B) = empty;
    Ov001_SetSaveExtraEmptyB(empty);
    MapListRedrawInfoPanel();
}

