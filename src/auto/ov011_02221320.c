/* 9 functions from 0x02221320 to 0x02222204 (ov011), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

void func_ov011_02221320(void *arg0, s32 arg1) {
    extern M2C_UNK data_ov011_02228294;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov011_02228294;
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
}

void func_ov011_02221334(void) {

}

s32 func_ov011_02221338(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void ConfigureIntroScreens(void *arg0) {
    M2C_UNK func_020822b8(u16 *);
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 data_027e01d8;
    extern M2C_UNK data_ov011_02227f08;
    typedef struct { u16 a, b, c, d, e, f; } T;
    T first = M2C_FIELD(&data_ov011_02227f08, T *, 0x12);
    T second;
    s32 temp_r4;
    second = M2C_FIELD(&data_ov011_02227f08, T *, 6);
    temp_r4 = data_027e01d8;
    data_027e01d8 = g3DSpriteEngineMain;
    func_020822b8((u16 *)&first);
    data_027e01d8 = g3DSpriteEngineSub;
    func_020822b8((u16 *)&second);
    data_027e01d8 = temp_r4;
}

#pragma opt_common_subs on
#pragma opt_strength_reduction off
/* Initialise the intro overlay's display: configure the VRAM banks, both 3D
   sprite engines and the intro screen configurations, then start the logo
   animation in its initial state. */
void InitIntroScene(void *logo) {
    M2C_UNK func_02082c84(void);
    M2C_UNK GX_SetBankForBG(s32);
    M2C_UNK func_02003124(s32);
    M2C_UNK func_020031cc(s32);
    M2C_UNK GX_SetBankForOBJ(s32);
    M2C_UNK func_02002ab8(s32);
    M2C_UNK func_0200323c(s32);
    M2C_UNK func_020032bc(s32);
    M2C_UNK func_020aca8c(s32);
    M2C_UNK Reset3DSpriteBankState(void);
    M2C_UNK func_01ff9b38(void);
    void ConfigureIntroScreens(void *);
    void InitIntroLogo(void *);

    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;

    s32 savedEngine;
    s32 engineIndex;
    s32 engine;

    func_02082c84();
    GX_SetBankForBG(3);
    func_02003124(4);
    func_020031cc(8);
    GX_SetBankForOBJ(0x10);
    func_02002ab8(0x60);
    func_0200323c(0x80);
    func_020032bc(0x100);
    ConfigureIntroScreens(logo);

    savedEngine = gCur3DSpriteEngine;
    for (engineIndex = 0; engineIndex < 2; engineIndex++) {
        if (engineIndex == 0) {
            gCur3DSpriteEngine = engine = g3DSpriteEngineMain;
        } else {
            gCur3DSpriteEngine = engine = g3DSpriteEngineSub;
        }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)engine; *bankFlags=*bankFlags | 0x10; }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)gCur3DSpriteEngine; *bankFlags=*bankFlags | 0x20; }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)gCur3DSpriteEngine; *bankFlags=*bankFlags | 0x40; }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)gCur3DSpriteEngine; *bankFlags=*bankFlags | 0x80; }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)gCur3DSpriteEngine; *bankFlags=*bankFlags | 0x100; }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)gCur3DSpriteEngine; *bankFlags=*bankFlags & ~0x200; }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)gCur3DSpriteEngine; *bankFlags=*bankFlags & ~0x400; }
        { u16 *volatile bankFlags=(u16 *)*(s32 *)gCur3DSpriteEngine; *bankFlags=*bankFlags & ~0x800; }
        { u16 *volatile oamAttr=(u16 *)(*(s32 *)gCur3DSpriteEngine+0x12); *oamAttr=*oamAttr&~0xC0; }
        ((DS3DSpriteBank *)*(s32 *)gCur3DSpriteEngine)->rowsAbove = 0;
        ((DS3DSpriteBank *)*(s32 *)gCur3DSpriteEngine)->rowsBelow = 0;
        ((DS3DSpriteBank *)*(s32 *)gCur3DSpriteEngine)->filler_53 = 0;
        *(volatile u16 *)((char *)gCur3DSpriteEngine + 0x44) = 0;
        func_020aca8c(3);
        Reset3DSpriteBankState();
        func_01ff9b38();
    }
    gCur3DSpriteEngine = savedEngine;
    *((u8 *)logo + 0x38) = 0;
    InitIntroLogo(logo);
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
void InitIntroLogo(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0) {
        M2C_FIELD(arg0, s16 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x39) = 0;
        M2C_FIELD(arg0, s8 *, 0x36) = 0;
        M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
        M2C_FIELD(arg0, u8 *, 0x38) = 1U;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x34) = 0x20;
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
    M2C_FIELD(arg0, u8 *, 0x38) = 2U;
}

void func_ov011_0222166c(void *arg0) {
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 temp_r1;
    if (M2C_FIELD(arg0, u8 *, 0x39) == 0) {
        temp_r1 = M2C_FIELD(arg0, s32 *, 0x3C);
        if (temp_r1 == 1) {
            M2C_FIELD(arg0, u8 *, 0x38) = 2;
            M2C_FIELD(arg0, s16 *, 0x34) = 0x10;
            SetSpriteAnimation(arg0, 2);
            return;
        }
        if (temp_r1 != 2) {
            M2C_FIELD(arg0, u8 *, 0x38) = 1;
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x38) = 3;
        SetSpriteAnimation(arg0, 6);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 2) return;
    SetSpriteAnimation(arg0, 4);
}

void func_ov011_022216d8(void *arg0, void *arg1, s32 arg2, s32 arg3) {
M2C_UNK SetFileDirectory(M2C_UNK *); M2C_UNK OpenNarcArchive(M2C_UNK *); M2C_UNK LoadNarcFileDecompressed(M2C_UNK *,s32); M2C_UNK LoadNarcFileToSpriteBuffer(M2C_UNK *,s32,s32); M2C_UNK func_0208161c(M2C_UNK *,s32,s32,s32); M2C_UNK func_02081644(M2C_UNK *,s32,s32,s32); M2C_UNK CloseNarcArchive(void); s32 GetLanguage(void); M2C_UNK *GetLocalizedFileName(M2C_UNK *);
extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
extern M2C_UNK data_ov011_022282a0, data_ov011_022282ac, data_ov011_022282bc, data_ov011_022282c8, data_ov011_022282d4, data_ov011_022282e0, data_ov011_022282f4, data_ov011_02228308, data_ov011_0222831c, data_ov011_02228330, data_ov011_02228344, data_ov011_02228358, data_ov011_0222836c, data_ov011_02228380, data_ov011_02228398, data_ov011_022283ac, data_ov011_022283c0, data_ov011_022283d4, data_ov011_022283e4, data_ov011_022283f0, data_ov011_022283fc, data_ov011_0222840c, data_ov011_02228418, data_ov011_02228424, data_ov011_02228438, data_ov011_0222844c, data_ov011_02228460, data_ov011_02228474, data_ov011_02228488, data_ov011_0222849c, data_ov011_022284b0, data_ov011_022284c4, data_ov011_022284dc, data_ov011_022284f0, data_ov011_02228504, data_ov011_02228518, data_ov011_0222852c, data_ov011_02228540, data_ov011_02228554, data_ov011_02228568, data_ov011_02228580, data_ov011_02228594, data_ov011_022285a8, data_ov011_022285bc, data_ov011_022285d0, data_ov011_022285e4, data_ov011_022285f8, data_ov011_0222860c, data_ov011_02228624, data_ov011_02228638, data_ov011_0222864c, data_ov011_02228660, data_ov011_02228674, data_ov011_02228688, data_ov011_0222869c, data_ov011_022286b0, data_ov011_022286c8, data_ov011_022286dc, data_ov011_022286f0, data_ov011_02228704, data_ov011_02228718, data_ov011_0222872c, data_ov011_02228740, data_ov011_02228754, data_ov011_0222876c, data_ov011_02228780, data_ov011_02228794, data_ov011_022287a8, data_ov011_022287bc, data_ov011_022287d0, data_ov011_022287e4, data_ov011_022287f8, data_ov011_02228804, data_ov011_0222880c, data_ov011_02228814, data_ov011_0222881c, data_ov011_02228838, data_ov011_02228850, data_ov011_02228868, data_ov011_02228880, data_ov011_02228898, data_ov011_022288b0, data_ov011_022288c8, data_ov011_022288e0, data_ov011_022288ec, data_ov011_022288f4, data_ov011_022288fc, data_ov011_02228904, data_ov011_02228910, data_ov011_0222891c, data_ov011_02228928;
s32 saved,i,engine,lang;
SetFileDirectory(&data_ov011_022282a0); saved=gCur3DSpriteEngine; i=0;
do { if(i==0) engine=g3DSpriteEngineMain; else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
if(arg2==0 && engine!=g3DSpriteEngineMain) goto inc;
if(arg2==1 && engine!=g3DSpriteEngineSub) goto inc;
if(arg2==3 && engine!=saved) goto inc;
switch((u32)arg1) {
case 0:
OpenNarcArchive(&data_ov011_022282ac);
LoadNarcFileDecompressed(&data_ov011_022282bc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_022282c8,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
LoadNarcFileToSpriteBuffer(&data_ov011_022282d4,0,32);CloseNarcArchive(); break;

case 1:
OpenNarcArchive(&data_ov011_022282e0);
LoadNarcFileDecompressed(&data_ov011_022282f4,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228308,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
LoadNarcFileToSpriteBuffer(&data_ov011_0222831c,0,32);CloseNarcArchive(); break;

case 3:
OpenNarcArchive(&data_ov011_02228330);
LoadNarcFileDecompressed(&data_ov011_02228344,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228358,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_0222836c,arg3,0,512);CloseNarcArchive(); break;

case 4:
OpenNarcArchive(&data_ov011_02228380);
LoadNarcFileDecompressed(&data_ov011_02228398,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_022283ac,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022283c0,arg3,0,512);CloseNarcArchive(); break;

case 5:
OpenNarcArchive(&data_ov011_022283d4);
LoadNarcFileDecompressed(&data_ov011_022283e4,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_0208161c(&data_ov011_022283f0,arg3,0,512);CloseNarcArchive(); break;

case 6:
OpenNarcArchive(&data_ov011_022283fc);
LoadNarcFileDecompressed(&data_ov011_0222840c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_0208161c(&data_ov011_02228418,arg3,0,512);CloseNarcArchive(); break;

case 11:
OpenNarcArchive(&data_ov011_02228424);
LoadNarcFileDecompressed(&data_ov011_02228438,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_0222844c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228460,arg3,0,512);CloseNarcArchive(); break;

case 12:
OpenNarcArchive(&data_ov011_02228474);
LoadNarcFileDecompressed(&data_ov011_02228488,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_0222849c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022284b0,arg3,0,512);CloseNarcArchive(); break;

case 7:
OpenNarcArchive(&data_ov011_022284c4);
LoadNarcFileDecompressed(&data_ov011_022284dc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_022284f0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228504,arg3,0,512);CloseNarcArchive(); break;

case 8:
OpenNarcArchive(&data_ov011_02228518);
LoadNarcFileDecompressed(&data_ov011_0222852c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228540,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228554,arg3,0,512);CloseNarcArchive(); break;

case 9:
OpenNarcArchive(&data_ov011_02228568);
LoadNarcFileDecompressed(&data_ov011_02228580,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228594,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022285a8,arg3,0,512);CloseNarcArchive(); break;

case 10:
OpenNarcArchive(&data_ov011_022285bc);
LoadNarcFileDecompressed(&data_ov011_022285d0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_022285e4,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022285f8,arg3,0,512);CloseNarcArchive(); break;

case 13:
OpenNarcArchive(&data_ov011_0222860c);
LoadNarcFileDecompressed(&data_ov011_02228624,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228638,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_0222864c,arg3,0,512);CloseNarcArchive(); break;

case 14:
OpenNarcArchive(&data_ov011_02228660);
LoadNarcFileDecompressed(&data_ov011_02228674,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228688,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_0222869c,arg3,0,512);CloseNarcArchive(); break;

case 15:
OpenNarcArchive(&data_ov011_022286b0);
LoadNarcFileDecompressed(&data_ov011_022286c8,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_022286dc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_022286f0,arg3,0,512);CloseNarcArchive(); break;

case 16:
OpenNarcArchive(&data_ov011_02228704);
LoadNarcFileDecompressed(&data_ov011_02228718,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_0222872c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_02228740,arg3,0,512);CloseNarcArchive(); break;

case 17:
OpenNarcArchive(&data_ov011_02228754);
LoadNarcFileDecompressed(&data_ov011_0222876c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228780,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228794,arg3,0,512);CloseNarcArchive(); break;

case 18:
OpenNarcArchive(&data_ov011_022287a8);
LoadNarcFileDecompressed(&data_ov011_022287bc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_022287d0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022287e4,arg3,0,512);CloseNarcArchive(); break;

case 19:
OpenNarcArchive(&data_ov011_022287f8);
LoadNarcFileDecompressed(&data_ov011_02228804,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_0222880c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
LoadNarcFileToSpriteBuffer(&data_ov011_02228814,0,32);CloseNarcArchive(); break;

case 20:
OpenNarcArchive(&data_ov011_0222881c);
LoadNarcFileDecompressed(&data_ov011_02228838,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_02228850,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_02228868,arg3,0,512);CloseNarcArchive(); break;

case 21:
OpenNarcArchive(&data_ov011_02228880);
LoadNarcFileDecompressed(&data_ov011_02228898,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_022288b0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_022288c8,arg3,0,512);CloseNarcArchive(); break;

case 22:
lang=GetLanguage(); if(lang==1||lang==2||lang==5) {
OpenNarcArchive(GetLocalizedFileName(&data_ov011_022288e0));
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov011_022288ec), M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov011_022288f4), M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
LoadNarcFileToSpriteBuffer(GetLocalizedFileName(&data_ov011_022288fc),0,32); CloseNarcArchive(); break; }
OpenNarcArchive(&data_ov011_02228904);
LoadNarcFileDecompressed(&data_ov011_02228910,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
LoadNarcFileDecompressed(&data_ov011_0222891c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
LoadNarcFileToSpriteBuffer(&data_ov011_02228928,0,32);CloseNarcArchive(); break;
} M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 1<<arg3;
inc: i++; }while(i<2); gCur3DSpriteEngine=saved;
}

void LoadOpeningScreenAssets(s32 unused, u32 asset, s32 screen) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadDecompressedFileTo(M2C_UNK *, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020812a4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK *GetLocalizedFileName(M2C_UNK *);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern M2C_UNK gOpeningDirectoryPath;
    extern M2C_UNK gPressStartCgPath;
    extern M2C_UNK gPressStartClPath;
    extern M2C_UNK gCopyrightCgPath;
    extern M2C_UNK gCopyrightClPath;
    extern M2C_UNK gPrologueText01CgPath;
    extern M2C_UNK gPrologueText01ClPath;
    extern M2C_UNK gPrologueText02CgPath;
    extern M2C_UNK gPrologueText02ClPath;
    extern M2C_UNK gPrologueText03CgPath;
    extern M2C_UNK gPrologueText03ClPath;
    extern M2C_UNK gPrologueText04CgPath;
    extern M2C_UNK gPrologueText04ClPath;
    extern M2C_UNK gTitleNoaCgPath;
    extern M2C_UNK gTitleNoaClPath;

    s32 savedEngine;
    s32 engineIndex;
    s32 engine;

    /* Load one opening-sequence image and its palette on the requested
       engine (0 main, 1 sub, 3 the one in use), or on both when screen
       is something else. */
    SetFileDirectory(&gOpeningDirectoryPath);

    savedEngine = gCur3DSpriteEngine;

    engineIndex = 0;
    do {
        if (engineIndex == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }

        gCur3DSpriteEngine = engine;

        if (screen == 0 && engine != g3DSpriteEngineMain) goto inc;
        if (screen == 1 && engine != g3DSpriteEngineSub) goto inc;
        if (screen == 3 && engine != savedEngine) goto inc;

        switch (asset) {
            case 0:
                LoadDecompressedFileTo(GetLocalizedFileName(&gPressStartCgPath), M2C_FIELD(engine, s32 *, 0x1C));
                LoadFileToSpriteBuffer(&gPressStartClPath, 0x200, 0x20);
                break;
            case 1:
                LoadDecompressedFileTo(&gCopyrightCgPath, M2C_FIELD(engine, s32 *, 0x1C) + 0x800);
                LoadFileToSpriteBuffer(&gCopyrightClPath, 0x2C0, 0x20);
                break;
            case 3:
                LoadDecompressedFileTo(GetLocalizedFileName(&gPrologueText01CgPath), M2C_FIELD(engine, s32 *, 0x1C));
                LoadFileToSpriteBuffer(&gPrologueText01ClPath, 0x200, 0x20);
                break;
            case 4:
                LoadDecompressedFileTo(GetLocalizedFileName(&gPrologueText02CgPath), M2C_FIELD(engine, s32 *, 0x1C));
                LoadFileToSpriteBuffer(&gPrologueText02ClPath, 0x200, 0x20);
                break;
            case 5:
                LoadDecompressedFileTo(GetLocalizedFileName(&gPrologueText03CgPath), M2C_FIELD(engine, s32 *, 0x1C));
                LoadFileToSpriteBuffer(&gPrologueText03ClPath, 0x200, 0x20);
                break;
            case 6:
                LoadDecompressedFileTo(GetLocalizedFileName(&gPrologueText04CgPath), M2C_FIELD(engine, s32 *, 0x1C));
                LoadFileToSpriteBuffer(&gPrologueText04ClPath, 0x200, 0x20);
                break;
            case 7:
                LoadDecompressedFileTo(&gTitleNoaCgPath, M2C_FIELD(engine, s32 *, 0x1C));
                func_020812a4(&gTitleNoaClPath, 0, 0, 0x200);
                break;
            default:
                break;
        }

inc:
        engineIndex += 1;
    } while (engineIndex < 2);

    gCur3DSpriteEngine = savedEngine;
}

