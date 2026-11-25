/* 38 functions from 0x02175F60 to 0x02176F4C (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
#include "gx.h"
#include "ov001_wh.h"
static inline s32 ov001_event_value(u8 value) { return value; }

struct MenuValues2 { u8 values[2]; };
extern struct MenuValues2 gOv001WifiMenuOptionTiles;

#pragma opt_common_subs off
void func_ov001_02175f60(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0 = (u8 *)M2C_FIELD(arg0, void **, 4) + M2C_FIELD(arg0, u32 **, 0)[(u16)arg1];
    if (arg2 >= 0) {
        ((u16 *)arg0)[arg2] = (u16)(arg3 + 0x30);
    }
}
#pragma opt_common_subs reset
/* Set up the ov001 online profile screen: allocate its work block, store the
 * task's continuation callback, copy the default match settings, hand the
 * block to the profile subsystem and install the screen's task. */
void Ov001_InitProfileScreen(void *arg0) {
    s32 Ov001_Alloc(s32, s32);
    s32 Ov001_GetMessageText(M2C_UNK, u32);
    s32 Ov001_GetConnectEntryId(void);
    void func_ov001_02188c78(M2C_UNK, void *);
    s32 Ov001_StartProfileTransfer(void);
    void SystemHalt(void);
    M2C_UNK Ov001_AddTask(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK);
    extern void *gOv001ProfileBlock;
    extern u8 data_ov001_0219031c[28];
    extern M2C_UNK gOv001MessageArchive;
    extern void func_ov001_0217612c(void *);
    typedef struct {
        u32 a, b, c, d, e, f;
        u8 g;
        u8 pad[3];
    } Buf28;
    Buf28 buf;
    gOv001ProfileBlock = (void *)Ov001_Alloc(0x1E2A4, 0x20);
    M2C_FIELD(gOv001ProfileBlock, M2C_UNK *, 0x1E298) = (M2C_UNK)arg0;
    arg0 = 0;
    M2C_FIELD(gOv001ProfileBlock, u8 *, 0x1E2A0) = 0;
    M2C_FIELD(gOv001ProfileBlock, u8 *, 0x1E2A1) = 0;
    buf = *(Buf28 *)data_ov001_0219031c;
    buf.b = Ov001_GetMessageText(gOv001MessageArchive, 0);
    buf.c = Ov001_GetMessageText(gOv001MessageArchive, 1);
    buf.g = (u8)Ov001_GetConnectEntryId();
    func_ov001_02188c78((M2C_UNK)gOv001ProfileBlock, &buf);
    if (Ov001_StartProfileTransfer() == 0) SystemHalt();
    M2C_FIELD(gOv001ProfileBlock, M2C_UNK *, 0x1E29C) = Ov001_AddTask(0, (M2C_UNK *)&func_ov001_0217612c, 0, 0x78);
}

void Ov001_StartProfileExitTask(void) {
    M2C_UNK Ov001_AddTask(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_ExitProfileTask;
    Ov001_AddTask(0, &Ov001_ExitProfileTask, 0, 0x78);
}

/* The WFC profile screen's exit task: wait for the profile subsystem to finish
 * leaving its setup, mark the screen's teardown as ready so the update task can
 * free the work block, and complete this task. */
void Ov001_ExitProfileTask(M2C_UNK task) {
    s32 Ov001_LeaveProfileSetup();
    M2C_UNK Ov001_PostTaskMessage(M2C_UNK, M2C_UNK);
    extern void *gOv001ProfileBlock;
    if (Ov001_LeaveProfileSetup() == 0) {
        return;
    }
    M2C_FIELD(gOv001ProfileBlock, u8 *, OV001_PROFILE_BLOCK_EXIT_DONE) = 1;
    Ov001_PostTaskMessage(0, task);
}

s32 Ov001_IsProfileScreenDone(void) {
    extern void *gOv001ProfileBlock;
    return gOv001ProfileBlock == 0;
}

void Ov001_SetProfileScreenCallback(s32 arg0) {
    extern void *gOv001ProfileBlock;
    M2C_FIELD(gOv001ProfileBlock, s32 *, 0x1E298) = arg0;
}

void Ov001_AdvanceProfileSetup(void) {
    M2C_UNK Ov001_AdvanceLinkState();
    Ov001_AdvanceLinkState();
}

void *func_ov001_02176114(void) {
    extern void *gOv001ProfileBlock;
    u8 *p = (u8 *)gOv001ProfileBlock;
    p = p + 0x2280;
    p = p + 0x1C000;
    return p;
}

#pragma push
#pragma opt_propagation off
void func_ov001_0217612c(void *arg0) {
void Ov001_UpdateProfileSetup(void); s32 Ov001_PollProfileState(void*,void*); extern void *gOv001ProfileBlock;
M2C_UNK Ov001_PostTaskMessage(M2C_UNK,M2C_UNK); M2C_UNK Ov001_FreeAlloc(M2C_UNK*);
void *func_ov001_02189308(void); void CopyU16(const void*,void*,u32);
u8 sp1,sp0; u8 *main; void (*fp)(s32);
Ov001_UpdateProfileSetup();
if(M2C_FIELD(gOv001ProfileBlock,u8*,0x1e2a0)!=0 && M2C_FIELD(gOv001ProfileBlock,u8*,0x1e2a1)==0){
fp=(void(*)(s32))M2C_FIELD(gOv001ProfileBlock,void**,0x1e298);if(fp)fp(0);return;}
Ov001_PollProfileState(&sp1,&sp0);
{s32 v=(s32)(u32)sp1;
if(v>26)goto high26;
if(v>=26)goto block26;
if(v>=21)goto high20;
switch((s32)v){
case 0:goto done;
case 1:goto done;
case 2:goto done;
case 3:goto done;
case 4:goto done;
case 5:goto block5;
case 6:goto done;
case 7:goto done;
case 8:goto done;
case 9:goto done;
case 10:goto done;
case 11:goto done;
case 12:goto block12;
case 13:goto block13;
case 14:goto done;
case 15:goto done;
case 16:goto done;
case 17:goto done;
case 18:goto done;
case 19:goto done;
case 20:goto block20;
default:goto done;}
high20:if(v==23)goto block20;return;
high26:if(v>29)goto high29;if(v==29)goto block26;return;
high29:if(v==34)goto tail;return;
}
block5:

if(sp0==0)return;
main=(u8*)gOv001ProfileBlock+0x2280;CopyU16(func_ov001_02189308(),main+0x1c000,0x16);
fp=(void(*)(s32))M2C_FIELD(gOv001ProfileBlock,void**,0x1e298);
if(fp==0){M2C_FIELD(gOv001ProfileBlock,u8*,0x1e2a0)=1;return;}fp(0);return;
block13:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(gOv001ProfileBlock,void**,0x1e298);
if(fp==0){M2C_FIELD(gOv001ProfileBlock,u8*,0x1e2a0)=1;return;}fp(1);return;
block20:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(gOv001ProfileBlock,void**,0x1e298);
if(fp==0){M2C_FIELD(gOv001ProfileBlock,u8*,0x1e2a0)=1;return;}fp(3);return;
block26:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(gOv001ProfileBlock,void**,0x1e298);
if(fp==0){M2C_FIELD(gOv001ProfileBlock,u8*,0x1e2a0)=1;return;}fp(4);return;
block12:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(gOv001ProfileBlock,void**,0x1e298);
if(fp==0){M2C_FIELD(gOv001ProfileBlock,u8*,0x1e2a0)=1;return;}fp(2);return;
tail:Ov001_PostTaskMessage(0,(M2C_UNK)arg0);Ov001_FreeAlloc((M2C_UNK*)&gOv001ProfileBlock);done:return;}
#pragma pop
/* Open the ov001 option page: allocate its 12-byte state block, start the overlay's
 * Wi-Fi session with the page's state/alloc/cleanup callbacks (0x800-byte packet
 * buffer) and wait briefly for it to come up. */
void Ov001_OpenOptionPage(void) {
    s32 Ov001_Alloc(s32, s32);
    s32 func_ov001_021711e0(s32, s32, void *, void *, void *, s32);
    void Ov001_StoreOptionPageState(void *);
    void Ov001_AllocWhBuffer(s32);
    void func_ov001_0217656c(void);
    extern M2C_UNK gOv001OptionPageState;
    s32 stateSize = 0xC;

    gOv001OptionPageState = Ov001_Alloc(stateSize, stateSize - 0x10);
    if (func_ov001_021711e0(0xF, 0x40, Ov001_StoreOptionPageState, Ov001_AllocWhBuffer, func_ov001_0217656c, 0x800) != 1) {
        SystemHalt();
    }
    SleepMilliseconds(0xA);
}

void Ov001_FreeOptionPage(void) {
    M2C_UNK SystemHalt();
    s32 func_ov001_021712c8();
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK gOv001OptionPageState;
    if (func_ov001_021712c8() != 1) {
        SystemHalt();
    }
    Ov001_FreeAlloc(&gOv001OptionPageState);
}

/* Map the option page's current state to the caller's selection code:
 * 1/2 = the two menu items, 4 = leave; state 6 is the download-play confirm,
 * where a valid received link-match setup (name class 0..3 and the flag at
 * +0x24 set) yields 3 (proceed and store the setup) and anything else yields
 * 5 (cancel). Any other state returns the caller's default. */
s32 Ov001_GetOptionChoice(s32 defaultChoice) {
    s32 Ov001_CopyLinkMatchSetup(void *);
    extern M2C_UNK gOv001OptionPageState;
    s32 setup[58];
    switch (*(u32 *)gOv001OptionPageState) {
    case 0:
    case 1:
    case 3:
    case 5: return 0;
    case 2: return 1;
    case 4: return 2;
    case 6:
        if (Ov001_CopyLinkMatchSetup(setup) != 1) SystemHalt();
        if (setup[8] >= 0 && setup[8] <= 3 && setup[9] == 1) return 3;
        return 5;
    case 7: return 4;
    }
    return defaultChoice;
}

void Ov001_StoreMatchSetup(void) {
 s32 Ov001_CopyLinkMatchSetup(void *);
 M2C_UNK StoreLinkMatchSetup(void *);
 s32 state[58];
 if(Ov001_CopyLinkMatchSetup(state) != 1) SystemHalt();
 StoreLinkMatchSetup(state);
}

void Ov001_StoreOptionPageState(void *arg0) {
 typedef struct { s32 values[3]; } State;
 extern M2C_UNK gOv001OptionPageState;
 *(State *)gOv001OptionPageState = *(State *)arg0;
}

void Ov001_AllocWhBuffer(M2C_UNK arg0) {
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    Ov001_Alloc(arg0, 0x20);
}

void func_ov001_0217656c(void) {
    M2C_UNK Ov001_FreeHeapBlock();
    Ov001_FreeHeapBlock();
}

/* Fade both screens to white across every plane, then hand over to
 * Ov001_ShutdownScreen, which releases the ov001 resources and exits. */
void Ov001_FadeToShutdownScreen(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK Ov001_ShutdownScreen;
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, OV001_BLEND_ALL, 0x14);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, OV001_BLEND_ALL, 0x14);
    Ov001_SetStepCallback(&Ov001_ShutdownScreen);
}

/* Final step of the ov001 front end's shutdown: once both screens' fade-outs
 * have finished, stop the task groups, release the character banks, the
 * highlight tilemap, the choice-frame sprites, the message archive and its
 * queue, and the save data, then ask the main loop to exit. */
void Ov001_ShutdownScreen(void) {
    M2C_UNK Ov001_FreeChoiceFrame();
    M2C_UNK Ov001_FreeHighlightTilemap();
    M2C_UNK Ov001_RequestScreenExit();
    M2C_UNK Ov001_FreeMessageArchiveQueue();
    M2C_UNK Ov001_ReleaseMessageArchive(s32);
    M2C_UNK Ov001_FreeSaveData();
    M2C_UNK Ov001_FreeCharBank(M2C_UNK);
    M2C_UNK Ov001_SetTaskGroupEnabled(M2C_UNK, M2C_UNK);
    extern s32 gOv001MessageArchive;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_SetTaskGroupEnabled(0, 0);
    Ov001_SetTaskGroupEnabled(1, 0);
    Ov001_FreeCharBank(1);
    Ov001_FreeCharBank(0);
    Ov001_FreeHighlightTilemap();
    Ov001_FreeChoiceFrame();
    Ov001_ReleaseMessageArchive(gOv001MessageArchive);
    Ov001_FreeMessageArchiveQueue();
    Ov001_FreeSaveData();
    Ov001_RequestScreenExit();
}

/* First step of the ov001 screen: initialise its subsystems, load the message
 * archive for the current language and the character, background and object
 * resources of both screens, set the background priority and fade in, then
 * advance to the next step. */
void Ov001_InitScreen(void) {
    void Ov001_AllocSaveData(void);
    void Ov001_InitMessageArchiveQueue(void);
    void func_ov001_02171fa0(void);
    void Ov001_InitHighlightBackground(void);
    void func_ov001_02171c10(void);
    u8 Ov001_GetLanguage(void);
    s32 Ov001_HasOptionFlag(s32);
    s32 Ov001_GetScreenLayout(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_LoadMessageArchive(M2C_UNK);
    s32 Ov001_GetLocalizedFileName(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    void Ov001_LoadCharBank(s32, M2C_UNK);
    M2C_UNK Ov001_EnableVisiblePlanes(M2C_UNK, M2C_UNK);
    extern s32 gOv001MessageArchive;
    extern M2C_UNK gOv001MessagePathUsa;
    extern M2C_UNK gOv001MessageFilePaths[7];
    extern M2C_UNK gOv001TopCharPath;
    extern M2C_UNK gOv001BottomCharPath;
    extern M2C_UNK gOv001TopBgTilesPath;
    extern M2C_UNK gOv001TopBgMapPath;
    extern M2C_UNK gOv001TopObjTilesPath;
    extern M2C_UNK gOv001ObjMapPath;
    extern M2C_UNK gOv001BottomBgStep1TilesPath;
    extern M2C_UNK gOv001BottomBgStep1MapPath;
    extern M2C_UNK gOv001BottomObjTilesPath;
    extern M2C_UNK gOv001BottomObjMapPath;
    extern M2C_UNK gOv001TopScreenPath;
    extern M2C_UNK gOv001TopStep1Path;
    extern M2C_UNK GX_LoadBG1CharSub;
    extern M2C_UNK GX_LoadSubBGPltt;
    extern M2C_UNK GX_LoadOBJSub;
    extern M2C_UNK GX_LoadSubOBJPltt;
    extern M2C_UNK GX_LoadBG2Char;
    extern M2C_UNK GX_LoadBGPltt;
    extern M2C_UNK GX_LoadOBJ;
    extern M2C_UNK GX_LoadOBJPltt;
    extern M2C_UNK GX_LoadBG1ScrSub;
    extern M2C_UNK Ov001_FadeInInitialMenu;

    /* Bring up the screen's subsystems. */
    Ov001_AllocSaveData();
    Ov001_InitMessageArchiveQueue();
    func_ov001_02171fa0();
    Ov001_InitHighlightBackground();
    func_ov001_02171c10();
    /* English has a separate US archive selected by option flag 2. */
    if (Ov001_GetLanguage() == 1 && Ov001_HasOptionFlag(2) != 0) {
        gOv001MessageArchive = Ov001_LoadMessageArchive((M2C_UNK)&gOv001MessagePathUsa);
    } else {
        gOv001MessageArchive = Ov001_LoadMessageArchive((M2C_UNK)gOv001MessageFilePaths[Ov001_GetLanguage()]);
    }
    /* Character banks: 1 = top screen, 0 = bottom screen. */
    Ov001_LoadCharBank(1, Ov001_GetLocalizedFileName(&gOv001TopCharPath));
    Ov001_LoadCharBank(0, Ov001_GetLocalizedFileName(&gOv001BottomCharPath));
    Ov001_LoadAsset(&gOv001TopBgTilesPath, &GX_LoadBG1CharSub);
    Ov001_LoadAsset(&gOv001TopBgMapPath, &GX_LoadSubBGPltt);
    Ov001_LoadAsset(&gOv001TopObjTilesPath, &GX_LoadOBJSub);
    Ov001_LoadAsset(&gOv001ObjMapPath, &GX_LoadSubOBJPltt);
    Ov001_LoadAsset(&gOv001BottomBgStep1TilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001BottomBgStep1MapPath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001BottomObjTilesPath, &GX_LoadOBJ);
    Ov001_LoadAsset(&gOv001BottomObjMapPath, &GX_LoadOBJPltt);
    /* The top screen's layout depends on the screen variant. */
    switch (Ov001_GetScreenLayout()) {
    case 0:
        Ov001_LoadAsset(&gOv001TopScreenPath, &GX_LoadBG1ScrSub);
        break;
    case 1:
        Ov001_LoadAsset(&gOv001TopStep1Path, &GX_LoadBG1ScrSub);
        break;
    }
    /* Both screens' BG1 use priority 3; the main screen's is written twice to
     * match the original's display register sequence. */
    M2C_FIELD((void *)0x0400100A, u16 *, 0) = (M2C_FIELD((void *)0x0400100A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    Ov001_EnableVisiblePlanes(1, 2);
    Ov001_EnableVisiblePlanes(0, 2);
    Ov001_SetStepCallback(&Ov001_FadeInInitialMenu);
}

/* Second ov001 step: fade both screens in from white over BG1 and, once those
 * fades finish, open the initial menu. */
void Ov001_FadeInInitialMenu(void) {
    extern M2C_UNK Ov001_OpenInitialMenuAfterFade;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, OV001_BLEND_BG1, 20);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, OV001_BLEND_BG1, 20);
    Ov001_SetStepCallback(&Ov001_OpenInitialMenuAfterFade);
}

/* Wait for both screen fades, then open the initial menu selected by the layout. */
void Ov001_OpenInitialMenuAfterFade(void) {
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    s32 Ov001_GetScreenLayout(void);
    extern M2C_UNK Ov001_OpenWifiMenu;
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    s32 layout;

    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    layout = Ov001_GetScreenLayout();
    switch (layout) {                              /* irregular */
    case OV001_LAYOUT_WIFI_MENU:
        Ov001_SetNextScreenMode(0, OV001_SCREEN_CREATE_ICON_ROW);
        Ov001_SetStepCallback(&Ov001_OpenWifiMenu);
        return;
    case OV001_LAYOUT_ACCESS_POINT_MENU:
        Ov001_SetNextScreenMode(1, OV001_SCREEN_CREATE_ICON_ROW);
        Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);
        return;
    }
}

/* Open the ov001 Wi-Fi menu (its two options open the access-point list or the
 * options menu): load its background and object layout, show the menu's
 * explanation text, lay the choice frame out around the current selection and
 * chain to the fade-in step. */
void Ov001_OpenWifiMenu(void) {
    void Ov001_LoadWifiMenuBackground(void);
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_LoadMenuResource(M2C_UNK);
    M2C_UNK Ov001_LayoutChoiceFrame(u16, u16, u16, u16);
    void Ov001_FadeInWifiMenu(void);
    extern u8 gOv001WifiMenuSelection;
    extern u16 gOv001ChoiceFrameLeft, gOv001ChoiceFrameTop, gOv001ChoiceFrameRight, gOv001ChoiceFrameBottom;
    s32 offset;

    Ov001_LoadWifiMenuBackground();
    Ov001_LoadObjLayoutBlock(0);
    Ov001_ShowMessagePanel(0x2E, -1, 0); /* explanation text of the menu */
    Ov001_LoadMenuResource(4);
    offset = gOv001WifiMenuSelection * 8;
    Ov001_LayoutChoiceFrame(M2C_FIELD(&gOv001ChoiceFrameLeft, u16 *, offset),
                            M2C_FIELD(&gOv001ChoiceFrameRight, u16 *, offset),
                            M2C_FIELD(&gOv001ChoiceFrameTop, u16 *, offset),
                            M2C_FIELD(&gOv001ChoiceFrameBottom, u16 *, offset));
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeInWifiMenu);
}

/* Loads the step-screen background NCL file and registers its rendering callbacks, then selects VRAM banks 3 for the displays. */
void Ov001_LoadWifiMenuBackground(void) {
    s32 Ov001_GetLocalizedFileName(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    s32 Ov001_LoadFile(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK gOv001WifiMenuLayoutPath;
    extern M2C_UNK gOv001WifiMenuBgTilesPath;
    extern M2C_UNK gOv001WifiMenuBgPalettePath;
    extern M2C_UNK gOv001WifiMenuBgMapPath;
    extern M2C_UNK GX_LoadBGPltt;
    extern u8 gOv001WifiMenuSelection;
    extern M2C_UNK GX_LoadBG2Scr;
    extern M2C_UNK GX_LoadBG2Char;
    typedef struct { u8 bytes[22]; } Text;
    Text text = *(Text *)&gOv001WifiMenuLayoutPath;
    Ov001_LoadAsset(&gOv001WifiMenuBgPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001WifiMenuBgMapPath, &GX_LoadBG2Scr);
    Ov001_LoadAsset(&gOv001WifiMenuBgTilesPath, &GX_LoadBG2Char);
    M2C_FIELD(&gOv001WifiMenuSelection, s32 *, 4) = Ov001_LoadFile(Ov001_GetLocalizedFileName(&text), 0, 4);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

/* Fades in the ov001 Wi-Fi menu: start the sub and main fades from white with
 * the menu's background and object planes, show those planes, then run the step
 * that brings the menu up once both fades have finished. */
void Ov001_FadeInWifiMenu(void) {
    extern M2C_UNK Ov001_OpenWifiMenuAfterFade;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, GX_PLANEMASK_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback(&Ov001_OpenWifiMenuAfterFade);
}

/* Once the Wi-Fi menu's fade-in has finished on both engines, bring in its
 * back/confirm icon row and hand over to the step that waits for the row to
 * slide in and unlock. */
void Ov001_OpenWifiMenuAfterFade(void) {
    M2C_UNK Ov001_CreateMenuIconRow(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK Ov001_WaitWifiMenuIconRow;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(OV001_FADE_MAIN) != 0) {
        return;
    }
    Ov001_CreateMenuIconRow(OV001_ICON_ROW_WIFI_MENU);
    Ov001_SetStepCallback(&Ov001_WaitWifiMenuIconRow);
}

void Ov001_WaitWifiMenuIconRow(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_UnlockIconRow();
    extern M2C_UNK func_ov001_02176ad8;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    Ov001_UnlockIconRow();
    Ov001_SetStepCallback(&func_ov001_02176ad8);
}

void func_ov001_02176ad8(void) {
    void Ov001_HandleChoiceInput(void);
    void func_ov001_02176c18(void);
    void Ov001_HandleWifiMenuChoice(void);
    Ov001_HandleChoiceInput();
    func_ov001_02176c18();
    Ov001_HandleWifiMenuChoice();
}

#pragma opt_strength_reduction off
/* Input for the two-option step menu: a touch on an option's rectangle or A
 * confirms, B cancels, and left/right move the selection and re-lay out the
 * frame of the newly selected option. */
void Ov001_HandleChoiceInput(void){
M2C_UNK Ov001_LatchIconRowSelection(M2C_UNK);
M2C_UNK Ov001_LayoutChoiceFrame(u16,u16,u16,u16);
void Ov001_MoveChoiceSelection(s32);
s32 KeyPressed(s32);s32 KeyHeld(s32);s32 TouchRectPressed(void *);
extern u8 gOv001ChoiceTouchRects[];
/* Frame rectangle of each option: its left, right, top and bottom edge, one
 * entry every 8 bytes. */
extern u16 gOv001ChoiceFrameLeft,gOv001ChoiceFrameRight,gOv001ChoiceFrameTop,gOv001ChoiceFrameBottom;
extern u8 gOv001WifiMenuSelection;
u32 index;u8 *rect;s32 offset;u16 left,right,top,bottom;
rect=gOv001ChoiceTouchRects;
for(index=0;index<2;index++,rect+=8){
if(TouchRectPressed(rect)){
Ov001_LatchIconRowSelection(1);
offset=(u8)index*8;
left=M2C_FIELD(&gOv001ChoiceFrameLeft,u16 *,offset);
right=M2C_FIELD(&gOv001ChoiceFrameRight,u16 *,offset);
top=M2C_FIELD(&gOv001ChoiceFrameTop,u16 *,offset);
bottom=M2C_FIELD(&gOv001ChoiceFrameBottom,u16 *,offset);
M2C_FIELD(&gOv001WifiMenuSelection,s8 *,0)=index;
Ov001_LayoutChoiceFrame(left,right,top,bottom);return;
}
}
if(KeyPressed(KEY_A)){Ov001_LatchIconRowSelection(1);return;}
if(KeyPressed(KEY_B)){Ov001_LatchIconRowSelection(0);return;}
if(KeyHeld(KEY_UP)){Ov001_MoveChoiceSelection(1);return;}
if(KeyHeld(KEY_DOWN)){Ov001_MoveChoiceSelection(3);return;}
if(KeyHeld(KEY_LEFT)){Ov001_MoveChoiceSelection(0);return;}
if(!KeyHeld(KEY_RIGHT))return;
Ov001_MoveChoiceSelection(2);
}
#pragma opt_strength_reduction reset
void func_ov001_02176c18(void) {

}

/* Act on the Wi-Fi menu's latched icon-row choice: BACK fades the screen out to
 * shutdown, CONFIRM loads the highlighted option's tile and hands the menu to its
 * exit step.  Any other selection (no choice latched yet) does nothing. */
void Ov001_HandleWifiMenuChoice(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void Ov001_LoadSelectedWifiMenuTile(void);
    void Ov001_WifiMenuExit(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    s32 choice;

    choice = Ov001_GetIconRowSelection();
    switch (choice) {
    case OV001_CHOICE_BACK:
        Ov001_PlaySound(OV001_SOUND_CANCEL);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_FadeToShutdownScreen);
        return;
    case OV001_CHOICE_CONFIRM:
        Ov001_PlaySound(OV001_SOUND_CONFIRM);
        Ov001_LoadSelectedWifiMenuTile();
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_WifiMenuExit);
        return;
    }
}

void Ov001_WifiMenuExit(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_FadeOutWifiMenu;
    Ov001_LockIconRow();
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_FadeOutWifiMenu);
}

/* Fade the Wi-Fi menu out to white once its sub-screen fade has finished, then
 * hand over to Ov001_FinishWifiMenu, which releases the menu's resources. */
void Ov001_FadeOutWifiMenu(void) {
    extern M2C_UNK Ov001_FinishWifiMenu;
    if (Ov001_IsFadeActive(OV001_FADE_SUB) != 0) {
        return;
    }
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_SUB, GX_PLANEMASK_BG0, 8);
    Ov001_StartFade(OV001_FADE_TO_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 8);
    Ov001_SetStepCallback(&Ov001_FinishWifiMenu);
}

/* Runs after the Wi-Fi menu's fade-outs have finished: frees the menu's sprites,
 * background and text file, hides its planes, and hands over to whichever menu
 * the player picked (the access-point list or the options menu). */
void Ov001_FinishWifiMenu(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_FreeSpriteObjects();
    M2C_UNK Ov001_FreeMessagePanel();
    M2C_UNK Ov001_FreeFile(s32);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern u8 gOv001WifiMenuSelection;
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    extern M2C_UNK Ov001_InitOptionMenu;

    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_FreeSpriteObjects();
    Ov001_FreeMessagePanel();
    Ov001_FreeFile(M2C_FIELD(&gOv001WifiMenuSelection, s32 *, OV001_WIFI_MENU_TEXT));
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x14);
    switch (M2C_FIELD(&gOv001WifiMenuSelection, u8 *, OV001_WIFI_MENU_CHOICE)) {
    case OV001_WIFI_MENU_ACCESS_POINT:
        Ov001_SetNextScreenMode(1, 0);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenAccessPointMenu);
        return;
    case OV001_WIFI_MENU_OPTIONS:
        Ov001_SetNextScreenMode(0, 0);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_InitOptionMenu);
        return;
    }
}

/* Left/right input for the two-option Wi-Fi menu: toggles the selected option,
 * plays the move sound and re-lays the choice frame around the new option.  The
 * vertical directions are ignored. */
void Ov001_MoveChoiceSelection(s32 direction) {
    M2C_UNK Ov001_LayoutChoiceFrame(u16, u16, u16, u16);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    extern u16 gOv001ChoiceFrameLeft, gOv001ChoiceFrameTop, gOv001ChoiceFrameRight, gOv001ChoiceFrameBottom;
    extern u8 gOv001WifiMenuSelection;
    s32 frameOffset;

    if ((direction != OV001_DIR_UP) && (direction != OV001_DIR_DOWN)) {
        gOv001WifiMenuSelection ^= 1;
        Ov001_PlaySound(8);
        frameOffset = gOv001WifiMenuSelection * 8;
        Ov001_LayoutChoiceFrame(M2C_FIELD(&gOv001ChoiceFrameLeft, u16 *, frameOffset), M2C_FIELD(&gOv001ChoiceFrameRight, u16 *, frameOffset), M2C_FIELD(&gOv001ChoiceFrameTop, u16 *, frameOffset), M2C_FIELD(&gOv001ChoiceFrameBottom, u16 *, frameOffset));
    }
}

/* Copy the picture tile of the selected Wi-Fi menu option (its index is stored
 * per option in gOv001WifiMenuOptionTiles) into the OBJ tile it is drawn from. */
void Ov001_LoadSelectedWifiMenuTile(void) {
M2C_UNK Ov001_LoadObjTile(s32,u8,u8);
extern u8 gOv001WifiMenuSelection;
struct MenuValues2 tiles=gOv001WifiMenuOptionTiles;
u8 tile=tiles.values[gOv001WifiMenuSelection];
Ov001_LoadObjTile(M2C_FIELD(&gOv001WifiMenuSelection,s32 *,OV001_WIFI_MENU_TEXT),tile,tile);
}

/* Open the ov001 WFC settings screen from the option menu: clear the screen's
 * reset flag, load its background and object layout, draw its message panel and
 * the one-shot info box, then hand over to the fade-in step. */
void Ov001_OpenWfcSettingsScreen(void) {
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_ShowMessageBox(M2C_UNK);
    M2C_UNK Ov001_LoadObjLayoutBlock(M2C_UNK);
    void Ov001_LoadWfcSettingsBackground();
    extern s8 gOv001WfcSettingsReset;
    extern M2C_UNK Ov001_FadeInWfcSettingsScreen;
    gOv001WfcSettingsReset = 0;
    Ov001_LoadWfcSettingsBackground();
    Ov001_LoadObjLayoutBlock(OV001_WFC_SETTINGS_LAYOUT);
    Ov001_ShowMessagePanel(OV001_MSG_WFC_SETTINGS, -1, 0);
    Ov001_ShowMessageBox(OV001_MSG_WFC_SETTINGS_INFO);
    Ov001_SetStepCallback(&Ov001_FadeInWfcSettingsScreen);
}

/* Load the Wi-Fi settings background map (char/yb5Multi.nsc.l) into BG2 and put
 * BG0..BG2 of the main engine and BG0/BG1 of the sub engine at the lowest
 * priority, so that the map covers them. */
void Ov001_LoadWfcSettingsBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcSettingsBgMapPath;
    extern M2C_UNK GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001WfcSettingsBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fades in the ov001 WFC settings screen: start the sub and main fades from
 * white with the screen's background and object planes, show those planes, then
 * run the step that waits for the fades and opens the settings menu. */
void Ov001_FadeInWfcSettingsScreen(void) {
    extern M2C_UNK Ov001_WaitWfcSettingsFadeIn;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, GX_PLANEMASK_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback(&Ov001_WaitWfcSettingsFadeIn);
}

