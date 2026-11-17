/* 38 functions from 0x02175F60 to 0x02176F4C (ov001), found by ds-decomp. */
#include "common.h"
static inline s32 ov001_event_value(u8 value) { return value; }

struct MenuValues2 { u8 values[2]; };
extern struct MenuValues2 data_ov001_0218f6f4;

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
void func_ov001_02175f8c(void *arg0) {
    s32 Ov001_Alloc(s32, s32);
    s32 Ov001_GetMessageText(M2C_UNK, u32);
    s32 func_ov001_02175e34(void);
    void func_ov001_02188c78(M2C_UNK, void *);
    s32 func_ov001_02188ec4(void);
    void SystemHalt(void);
    M2C_UNK Ov001_AddTask(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK);
    extern void *data_ov001_02193d50;
    extern u8 data_ov001_0219031c[28];
    extern M2C_UNK gOv001MessageArchive;
    extern void func_ov001_0217612c(void *);
    typedef struct {
        u32 a, b, c, d, e, f;
        u8 g;
        u8 pad[3];
    } Buf28;
    Buf28 buf;
    data_ov001_02193d50 = (void *)Ov001_Alloc(0x1E2A4, 0x20);
    M2C_FIELD(data_ov001_02193d50, M2C_UNK *, 0x1E298) = (M2C_UNK)arg0;
    arg0 = 0;
    M2C_FIELD(data_ov001_02193d50, u8 *, 0x1E2A0) = 0;
    M2C_FIELD(data_ov001_02193d50, u8 *, 0x1E2A1) = 0;
    buf = *(Buf28 *)data_ov001_0219031c;
    buf.b = Ov001_GetMessageText(gOv001MessageArchive, 0);
    buf.c = Ov001_GetMessageText(gOv001MessageArchive, 1);
    buf.g = (u8)func_ov001_02175e34();
    func_ov001_02188c78((M2C_UNK)data_ov001_02193d50, &buf);
    if (func_ov001_02188ec4() == 0) SystemHalt();
    M2C_FIELD(data_ov001_02193d50, M2C_UNK *, 0x1E29C) = Ov001_AddTask(0, (M2C_UNK *)&func_ov001_0217612c, 0, 0x78);
}

void func_ov001_02176078(void) {
    M2C_UNK Ov001_AddTask(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02176098;
    Ov001_AddTask(0, &func_ov001_02176098, 0, 0x78);
}

void func_ov001_02176098(M2C_UNK arg0) {
    s32 Ov001_LeaveProfileSetup();
    M2C_UNK Ov001_PostTaskMessage(M2C_UNK, M2C_UNK);
    extern void *data_ov001_02193d50;
    if (Ov001_LeaveProfileSetup() == 0) {
        return;
    }
    M2C_FIELD(data_ov001_02193d50, u8 *, 0x1E2A1) = 1;
    Ov001_PostTaskMessage(0, arg0);
}

s32 Ov001_IsProfileScreenDone(void) {
    extern void *data_ov001_02193d50;
    return data_ov001_02193d50 == 0;
}

void func_ov001_021760f0(s32 arg0) {
    extern void *data_ov001_02193d50;
    M2C_FIELD(data_ov001_02193d50, s32 *, 0x1E298) = arg0;
}

void func_ov001_02176108(void) {
    M2C_UNK func_ov001_02188f0c();
    func_ov001_02188f0c();
}

void *func_ov001_02176114(void) {
    extern void *data_ov001_02193d50;
    u8 *p = (u8 *)data_ov001_02193d50;
    p = p + 0x2280;
    p = p + 0x1C000;
    return p;
}

#pragma push
#pragma opt_propagation off
void func_ov001_0217612c(void *arg0) {
void func_ov001_02188f40(void); s32 func_ov001_021892c4(void*,void*); extern void *data_ov001_02193d50;
M2C_UNK Ov001_PostTaskMessage(M2C_UNK,M2C_UNK); M2C_UNK Ov001_FreeAlloc(M2C_UNK*);
void *func_ov001_02189308(void); void CopyU16(const void*,void*,u32);
u8 sp1,sp0; u8 *main; void (*fp)(s32);
func_ov001_02188f40();
if(M2C_FIELD(data_ov001_02193d50,u8*,0x1e2a0)!=0 && M2C_FIELD(data_ov001_02193d50,u8*,0x1e2a1)==0){
fp=(void(*)(s32))M2C_FIELD(data_ov001_02193d50,void**,0x1e298);if(fp)fp(0);return;}
func_ov001_021892c4(&sp1,&sp0);
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
main=(u8*)data_ov001_02193d50+0x2280;CopyU16(func_ov001_02189308(),main+0x1c000,0x16);
fp=(void(*)(s32))M2C_FIELD(data_ov001_02193d50,void**,0x1e298);
if(fp==0){M2C_FIELD(data_ov001_02193d50,u8*,0x1e2a0)=1;return;}fp(0);return;
block13:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(data_ov001_02193d50,void**,0x1e298);
if(fp==0){M2C_FIELD(data_ov001_02193d50,u8*,0x1e2a0)=1;return;}fp(1);return;
block20:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(data_ov001_02193d50,void**,0x1e298);
if(fp==0){M2C_FIELD(data_ov001_02193d50,u8*,0x1e2a0)=1;return;}fp(3);return;
block26:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(data_ov001_02193d50,void**,0x1e298);
if(fp==0){M2C_FIELD(data_ov001_02193d50,u8*,0x1e2a0)=1;return;}fp(4);return;
block12:
if(sp0==0)return;

fp=(void(*)(s32))M2C_FIELD(data_ov001_02193d50,void**,0x1e298);
if(fp==0){M2C_FIELD(data_ov001_02193d50,u8*,0x1e2a0)=1;return;}fp(2);return;
tail:Ov001_PostTaskMessage(0,(M2C_UNK)arg0);Ov001_FreeAlloc((M2C_UNK*)&data_ov001_02193d50);done:return;}
#pragma pop
void func_ov001_021763cc(void) {
    s32 Ov001_Alloc(s32, s32);
    s32 func_ov001_021711e0(s32, s32, void *, void *, void *, s32);
    void func_ov001_02176544(void *);
    void func_ov001_0217655c(s32);
    void func_ov001_0217656c(void);
    extern M2C_UNK gOv001OptionPageState;
    s32 v = 0xC;
    gOv001OptionPageState = Ov001_Alloc(v, v - 0x10);
    if (func_ov001_021711e0(0xF, 0x40, func_ov001_02176544, func_ov001_0217655c, func_ov001_0217656c, 0x800) != 1) {
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

void func_ov001_02176544(void *arg0) {
 typedef struct { s32 values[3]; } State;
 extern M2C_UNK gOv001OptionPageState;
 *(State *)gOv001OptionPageState = *(State *)arg0;
}

void func_ov001_0217655c(M2C_UNK arg0) {
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    Ov001_Alloc(arg0, 0x20);
}

void func_ov001_0217656c(void) {
    M2C_UNK func_ov001_0218b760();
    func_ov001_0218b760();
}

void func_ov001_02176578(void) {
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021765b4;
    Ov001_StartFade(3, 1, 0x3F, 0x14);
    Ov001_StartFade(3, 0, 0x3F, 0x14);
    Ov001_SetStepCallback(&func_ov001_021765b4);
}

void func_ov001_021765b4(void) {
    M2C_UNK func_ov001_02171fc0();
    M2C_UNK func_ov001_0217223c();
    M2C_UNK func_ov001_02175e20();
    M2C_UNK func_ov001_02175eb0();
    M2C_UNK func_ov001_02175f1c(s32);
    M2C_UNK func_ov001_02184448();
    M2C_UNK func_ov001_0218a534(M2C_UNK);
    M2C_UNK func_ov001_0218c99c(M2C_UNK, M2C_UNK);
    extern s32 gOv001MessageArchive;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_0218c99c(0, 0);
    func_ov001_0218c99c(1, 0);
    func_ov001_0218a534(1);
    func_ov001_0218a534(0);
    func_ov001_0217223c();
    func_ov001_02171fc0();
    func_ov001_02175f1c(gOv001MessageArchive);
    func_ov001_02175eb0();
    func_ov001_02184448();
    func_ov001_02175e20();
}

/* First step of the ov001 screen: initialise its subsystems, load the message
 * archive for the current language and the character, background and object
 * resources of both screens, set the background priority and fade in, then
 * advance to the next step. */
void Ov001_InitScreen(void) {
    void func_ov001_02184404(void);
    void func_ov001_02175e74(void);
    void func_ov001_02171fa0(void);
    void func_ov001_021721c4(void);
    void func_ov001_02171c10(void);
    u8 Ov001_GetLanguage(void);
    s32 Ov001_HasOptionFlag(s32);
    s32 Ov001_GetScreenLayout(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_LoadMessageArchive(M2C_UNK);
    s32 Ov001_LocalizePath(void *);
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
    extern M2C_UNK func_0200466c;
    extern M2C_UNK func_02004108;
    extern M2C_UNK func_02004314;
    extern M2C_UNK func_020041b8;
    extern M2C_UNK GX_LoadBG2Char;
    extern M2C_UNK GX_LoadBGPltt;
    extern M2C_UNK func_020042bc;
    extern M2C_UNK GX_LoadOBJPltt;
    extern M2C_UNK func_0200442c;
    extern M2C_UNK func_ov001_02176808;

    /* Bring up the screen's subsystems. */
    func_ov001_02184404();
    func_ov001_02175e74();
    func_ov001_02171fa0();
    func_ov001_021721c4();
    func_ov001_02171c10();
    /* English has a separate US archive selected by option flag 2. */
    if (Ov001_GetLanguage() == 1 && Ov001_HasOptionFlag(2) != 0) {
        gOv001MessageArchive = Ov001_LoadMessageArchive((M2C_UNK)&gOv001MessagePathUsa);
    } else {
        gOv001MessageArchive = Ov001_LoadMessageArchive((M2C_UNK)gOv001MessageFilePaths[Ov001_GetLanguage()]);
    }
    /* Character banks: 1 = top screen, 0 = bottom screen. */
    Ov001_LoadCharBank(1, Ov001_LocalizePath(&gOv001TopCharPath));
    Ov001_LoadCharBank(0, Ov001_LocalizePath(&gOv001BottomCharPath));
    Ov001_LoadAsset(&gOv001TopBgTilesPath, &func_0200466c);
    Ov001_LoadAsset(&gOv001TopBgMapPath, &func_02004108);
    Ov001_LoadAsset(&gOv001TopObjTilesPath, &func_02004314);
    Ov001_LoadAsset(&gOv001ObjMapPath, &func_020041b8);
    Ov001_LoadAsset(&gOv001BottomBgStep1TilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001BottomBgStep1MapPath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001BottomObjTilesPath, &func_020042bc);
    Ov001_LoadAsset(&gOv001BottomObjMapPath, &GX_LoadOBJPltt);
    /* The top screen's layout depends on the screen variant. */
    switch (Ov001_GetScreenLayout()) {
    case 0:
        Ov001_LoadAsset(&gOv001TopScreenPath, &func_0200442c);
        break;
    case 1:
        Ov001_LoadAsset(&gOv001TopStep1Path, &func_0200442c);
        break;
    }
    /* Both screens' BG1 use priority 3; the main screen's is written twice to
     * match the original's display register sequence. */
    M2C_FIELD((void *)0x0400100A, u16 *, 0) = (M2C_FIELD((void *)0x0400100A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    Ov001_EnableVisiblePlanes(1, 2);
    Ov001_EnableVisiblePlanes(0, 2);
    Ov001_SetStepCallback(&func_ov001_02176808);
}

void func_ov001_02176808(void) {
    extern M2C_UNK func_ov001_02176844;
    Ov001_StartFade(2, 1, 2, 0x14);
    Ov001_StartFade(2, 0, 2, 0x14);
    Ov001_SetStepCallback(&func_ov001_02176844);
}

void func_ov001_02176844(void) {
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    s32 Ov001_GetScreenLayout();
    extern M2C_UNK Ov001_OpenWifiMenu;
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    s32 temp_r0;

    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    temp_r0 = Ov001_GetScreenLayout();
    switch (temp_r0) {                              /* irregular */
    case 0:
        Ov001_SetNextScreenMode(0, 1);
        Ov001_SetStepCallback(&Ov001_OpenWifiMenu);
        return;
    case 1:
        Ov001_SetNextScreenMode(1, 1);
        Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);
        return;
    }
}

void Ov001_OpenWifiMenu(void) {
 void func_ov001_02176934(void);
 M2C_UNK func_ov001_02172250(M2C_UNK);
 M2C_UNK Ov001_ShowMessagePanel(M2C_UNK,M2C_UNK,M2C_UNK);
 M2C_UNK Ov001_LoadMenuResource(M2C_UNK);
 M2C_UNK Ov001_LayoutChoiceFrame(u16,u16,u16,u16);
 void func_ov001_02176a20(void);
 extern u8 gOv001ChoiceState;
   extern u16 gOv001ChoiceFrameLeft, gOv001ChoiceFrameTop, gOv001ChoiceFrameRight, gOv001ChoiceFrameBottom;
 s32 offset;
 func_ov001_02176934();
 func_ov001_02172250(0);
 Ov001_ShowMessagePanel(0x2e,-1,0);
 Ov001_LoadMenuResource(4);
 offset = gOv001ChoiceState * 8;
 Ov001_LayoutChoiceFrame(M2C_FIELD(&gOv001ChoiceFrameLeft,u16 *,offset),M2C_FIELD(&gOv001ChoiceFrameRight,u16 *,offset),M2C_FIELD(&gOv001ChoiceFrameTop,u16 *,offset),M2C_FIELD(&gOv001ChoiceFrameBottom,u16 *,offset));
 Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176a20);
}

/* Loads the step-screen background NCL file and registers its rendering callbacks, then selects VRAM banks 3 for the displays. */
void func_ov001_02176934(void) {
    s32 Ov001_LocalizePath(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    s32 Ov001_LoadFile(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_0218f716;
    extern M2C_UNK data_ov001_021904dc;
    extern M2C_UNK data_ov001_021904f4;
    extern M2C_UNK data_ov001_0219050c;
    extern M2C_UNK GX_LoadBGPltt;
    extern u8 gOv001ChoiceState;
    extern M2C_UNK GX_LoadBG2Scr;
    extern M2C_UNK GX_LoadBG2Char;
    typedef struct { u8 bytes[22]; } Text;
    Text text = *(Text *)&data_ov001_0218f716;
    Ov001_LoadAsset(&data_ov001_021904f4, &GX_LoadBGPltt);
    Ov001_LoadAsset(&data_ov001_0219050c, &GX_LoadBG2Scr);
    Ov001_LoadAsset(&data_ov001_021904dc, &GX_LoadBG2Char);
    M2C_FIELD(&gOv001ChoiceState, s32 *, 4) = Ov001_LoadFile(Ov001_LocalizePath(&text), 0, 4);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02176a20(void) {
    extern M2C_UNK func_ov001_02176a74;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x14, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x14);
    Ov001_SetStepCallback(&func_ov001_02176a74);
}

void func_ov001_02176a74(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 Ov001_IsFadeActive(M2C_UNK);
    extern M2C_UNK func_ov001_02176ab0;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    Ov001_SetStepCallback(&func_ov001_02176ab0);
}

void func_ov001_02176ab0(void) {
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
    void func_ov001_02176c1c(void);
    Ov001_HandleChoiceInput();
    func_ov001_02176c18();
    func_ov001_02176c1c();
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
extern u8 gOv001ChoiceState;
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
M2C_FIELD(&gOv001ChoiceState,s8 *,0)=index;
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

void func_ov001_02176c1c(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void func_ov001_02176df0(void);
    void func_ov001_02176c6c(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    s32 temp_r0;

    temp_r0 = Ov001_GetIconRowSelection();
    switch (temp_r0) {                              /* irregular */
    case 0:
        Ov001_PlaySound(7);
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176578);
        return;
    case 1:
        Ov001_PlaySound(6);
        func_ov001_02176df0();
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176c6c);
        return;
    }
}

void func_ov001_02176c6c(void) {
    M2C_UNK Ov001_LockIconRow();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02176c8c;
    Ov001_LockIconRow();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02176c8c);
}

void func_ov001_02176c8c(void) {
    extern M2C_UNK func_ov001_02176cd8;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x16, 8);
    Ov001_SetStepCallback(&func_ov001_02176cd8);
}

void func_ov001_02176cd8(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_FreeSpriteObjects();
    M2C_UNK Ov001_FreeOptionBackground();
    M2C_UNK Ov001_FreeFile(s32);
    M2C_UNK Ov001_DisableVisiblePlanes(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetNextScreenMode(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern u8 gOv001ChoiceState;
    extern M2C_UNK Ov001_OpenAccessPointMenu;
    extern M2C_UNK Ov001_InitOptionMenu;

    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    if (Ov001_IsFadeActive(0) != 0) {
        return;
    }
    Ov001_FreeSpriteObjects();
    Ov001_FreeOptionBackground();
    Ov001_FreeFile(M2C_FIELD(&gOv001ChoiceState, s32 *, 4));
    Ov001_DisableVisiblePlanes(1, 1);
    Ov001_DisableVisiblePlanes(0, 0x14);
    switch (gOv001ChoiceState) {                  /* irregular */
    case 0:
        Ov001_SetNextScreenMode(1, 0);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenAccessPointMenu);
        return;
    case 1:
        Ov001_SetNextScreenMode(0, 0);
        Ov001_SetStepCallback((M2C_UNK *)&Ov001_InitOptionMenu);
        return;
    }
}

void Ov001_MoveChoiceSelection(s32 arg0) {
    M2C_UNK Ov001_LayoutChoiceFrame(u16, u16, u16, u16);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    extern u16 gOv001ChoiceFrameLeft, gOv001ChoiceFrameTop, gOv001ChoiceFrameRight, gOv001ChoiceFrameBottom;
    extern u8 gOv001ChoiceState;
    s32 offset;

    if ((arg0 != 1) && (arg0 != 3)) {
        gOv001ChoiceState ^= 1;
        Ov001_PlaySound(8);
        offset = gOv001ChoiceState * 8;
        Ov001_LayoutChoiceFrame(M2C_FIELD(&gOv001ChoiceFrameLeft, u16 *, offset), M2C_FIELD(&gOv001ChoiceFrameRight, u16 *, offset), M2C_FIELD(&gOv001ChoiceFrameTop, u16 *, offset), M2C_FIELD(&gOv001ChoiceFrameBottom, u16 *, offset));
    }
}

void func_ov001_02176df0(void) {
M2C_UNK Ov001_LoadObjTile(s32,u8,u8);
extern u8 gOv001ChoiceState;
struct MenuValues2 table=data_ov001_0218f6f4;
u8 value=table.values[gOv001ChoiceState];
Ov001_LoadObjTile(M2C_FIELD(&gOv001ChoiceState,s32 *,4),value,value);
}

void Ov001_OpenWfcSettingsScreen(void) {
    M2C_UNK Ov001_ShowMessagePanel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    M2C_UNK func_ov001_02172250(M2C_UNK);
    void func_ov001_02176e78();
    extern s8 gOv001WfcSettingsReset;
    extern M2C_UNK func_ov001_02176ef8;
    gOv001WfcSettingsReset = 0;
    func_ov001_02176e78();
    func_ov001_02172250(0x12);
    Ov001_ShowMessagePanel(0x3B, -1, 0);
    func_ov001_02171e58(0x17);
    Ov001_SetStepCallback(&func_ov001_02176ef8);
}

void func_ov001_02176e78(void) {
 M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
 extern M2C_UNK data_ov001_02190520;
 extern M2C_UNK GX_LoadBG2Scr;
 Ov001_LoadAsset(&data_ov001_02190520, &GX_LoadBG2Scr);
 M2C_FIELD((void *)0x04001008,u16 *,0) = (M2C_FIELD((void *)0x04001008,u16 *,0) & ~3) | 3;
 M2C_FIELD((void *)0x04001008,u16 *,2) = (M2C_FIELD((void *)0x04001008,u16 *,2) & ~3) | 3;
 *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
 M2C_FIELD((void *)0x0400000a,u16 *,0) = (M2C_FIELD((void *)0x0400000a,u16 *,0) & ~3) | 3;
 M2C_FIELD((void *)0x0400000a,u16 *,2) = (M2C_FIELD((void *)0x0400000a,u16 *,2) & ~3) | 3;
}

void func_ov001_02176ef8(void) {
    extern M2C_UNK func_ov001_02176f4c;
    Ov001_StartFade(2, 1, 1, 8);
    Ov001_StartFade(2, 0, 0x15, 8);
    Ov001_EnableVisiblePlanes(1, 1);
    Ov001_EnableVisiblePlanes(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_02176f4c);
}

