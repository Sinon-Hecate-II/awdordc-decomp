/* 42 functions from 0x02224B9C to 0x02225A9C (ov011), found by ds-decomp. */
#include "common.h"
typedef struct { s32 a,b,c,d; } MenuRecord011;
static inline s32 *NextMenuRecord011(void *a) { s32 *p=M2C_FIELD(a,s32 **,0x4c); M2C_FIELD(a,s32 **,0x4c)=p+4; return p; }
static inline void ReadMenuRecord011(void *a,s32 *v,s32 *l) {
s32 *p=M2C_FIELD(a,s32 **,0x4c);
*v=p[2]; *l=p[3]; M2C_FIELD(a,s32 **,0x4c)=p+4;
}
typedef struct { u8 pad[0x35]; u8 count:4; u8 other:4; } MenuCount011;
typedef struct { s32 words[5]; } ContextTemplate;
extern ContextTemplate data_ov011_02227f3c;

/* Stages of the overlay 011 intro presentation object (stored at +0x3C by
 * InitIntroObject): the opening presentation, the title, then the sequence. */
enum {
    INTRO_PRESENTATION_OPENING  = 0,
    INTRO_PRESENTATION_TITLE    = 1,
    INTRO_PRESENTATION_SEQUENCE = 2
};
extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain, *data_027e01d8;

/* An entry of the intro menu built by func_ov011_0222588c: a 3D sprite object
   (fields at +0x34 and up) plus the animation state the intro menu drives. */
#include "intro_menu.h"

/* Submit a 2D sprite/quad to one of the two 3D sprite engines (screen 0 or 1,
   selected by arg1, or to the engine already active when arg1 is 3) using the
   geometry template data_ov011_02227f3c with its corner fields overwritten;
   arg2 picks the vertex list offset inside the active engine's state block. */
#pragma push
#pragma opt_common_subs off
void func_ov011_02224b9c(M2C_UNK arg0, u32 arg1) {
    M2C_UNK LoadOpeningScreenAssets(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK LoadOpeningAssetSet(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s16 EaseInterpolate(M2C_UNK, M2C_UNK, s16, u32, s32);
    M2C_UNK Set3DSpriteBlendLayers(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void G3_SubmitSpriteQuad(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s16);
    void func_ov011_02224e04(M2C_UNK, s32, s32, s32, s32);
    extern M2C_UNK data_ov011_02227f08;
    extern M2C_UNK gIntroAnimState;
    const u8 values[5]={M2C_FIELD(&data_ov011_02227f08,u8 *,0),M2C_FIELD(&data_ov011_02227f08,u8 *,1),M2C_FIELD(&data_ov011_02227f08,u8 *,2),M2C_FIELD(&data_ov011_02227f08,u8 *,3),M2C_FIELD(&data_ov011_02227f08,u8 *,4)};
    register u8 *states=values;
    switch (arg1) {
    default:
        break;
    case 1:
        LoadOpeningScreenAssets(arg0, 5, 0);
        LoadOpeningAssetSet(arg0, 9, 0, 2);
        LoadOpeningAssetSet(arg0, 0xA, 1, 2);
        LoadOpeningAssetSet(arg0, 0xD, 0, 3);
        LoadOpeningAssetSet(arg0, 0xE, 1, 3);
        G3_SubmitSpriteQuad(arg0, 2, 2, 0x100, 0x80);
        G3_SubmitSpriteQuad(arg0, 2, 3, 0, 0x80);
        /* fallthrough */
    case 0:
        M2C_FIELD(&gIntroAnimState, u8 *, 0) = 0U;
        M2C_FIELD(&gIntroAnimState, volatile u16 *, 2) = 0U;
        return;
    case 3:
        if ((M2C_FIELD(&gIntroAnimState, volatile u16 *, 2) == states[M2C_FIELD(&gIntroAnimState, u8 *, 0)]) && ((u32) M2C_FIELD(&gIntroAnimState, u8 *, 0) > 4U)) {
            M2C_FIELD(&gIntroAnimState, volatile u16 *, 2) = 0U;
            M2C_FIELD(&gIntroAnimState, u8 *, 0) = (u8) (M2C_FIELD(&gIntroAnimState, u8 *, 0) + 1);
        }
        if ((u32) M2C_FIELD(&gIntroAnimState, u8 *, 0) <= 4U) {
            u8 temp_ip = states[M2C_FIELD(&gIntroAnimState, u8 *, 0)];
            if ((s32)M2C_FIELD(&gIntroAnimState,u8 *,0) % 2 != 0) {
                Set3DSpriteBlendLayers(arg0, 2, 3, 2, (u16) EaseInterpolate(0, 0, (s16)0x10, M2C_FIELD(&gIntroAnimState, volatile u16 *, 2), (s32) temp_ip));
            } else {
                Set3DSpriteBlendLayers(arg0, 2, 3, 2, (u16) EaseInterpolate(0, (s16)0x10, 0, M2C_FIELD(&gIntroAnimState, volatile u16 *, 2), (s32) temp_ip));
            }
        }
        M2C_FIELD(&gIntroAnimState, volatile u16 *, 2) = (u16) (M2C_FIELD(&gIntroAnimState, volatile u16 *, 2) + 1);
        G3_SubmitSpriteQuad(arg0, 2, 2, 0x80, 0x60);
        G3_SubmitSpriteQuad(arg0, 2, 3, 0x80, 0x60);
        return;
    case 4:
        LoadOpeningAssetSet(arg0, 0xF, 0, 3);
        LoadOpeningAssetSet(arg0, 0x10, 1, 3);
        /* fallthrough */
    case 5:
        M2C_FIELD(&gIntroAnimState, u8 *, 0) = 0U;
        M2C_FIELD(&gIntroAnimState, volatile u16 *, 2) = 0U;
        /* fallthrough */
        return;
    }
}
#pragma pop
void G3_SubmitSpriteQuad(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s16 arg4) {
void Build3DSpriteTransform(void *, void *);
ContextTemplate temp = data_ov011_02227f3c;
void *saved; void *p; s32 i;
((s16 *)&temp)[4]=arg3; ((s16 *)&temp)[5]=(s16)arg4;
saved=gCur3DSpriteEngine; i=0;
do {
if(i==0)p=g3DSpriteEngineMain; else p=g3DSpriteEngineSub;
gCur3DSpriteEngine=p;
if((arg1!=0 || p==g3DSpriteEngineMain) && (arg1!=1 || p==g3DSpriteEngineSub) && (arg1!=3 || p==saved)) {
switch(arg2) {case 2: Build3DSpriteTransform(&temp,(u8 *)*(void **)p+0x14); break; case 3: Build3DSpriteTransform(&temp,(u8 *)*(void **)p+0x24); break;}
}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}

/* Load the intro's fourth stage: asset sets 7 and 8 onto screen buffers 0 and 1,
 * set 4 on screen 0, then submit the stage's 2D sprite quad. */
void LoadIntroStage4Assets(M2C_UNK entry) {
    M2C_UNK LoadOpeningScreenAssets(M2C_UNK, M2C_UNK, M2C_UNK);

    LoadOpeningAssetSet(entry, 7, 0, 3);
    LoadOpeningAssetSet(entry, 8, 1, 3);
    LoadOpeningScreenAssets(entry, 4, 0);
    G3_SubmitSpriteQuad(entry, 2, 2, 0x80, 0x20);
}

void func_ov011_02224f64(void) {
    M2C_UNK InitIntroScene();
    InitIntroScene();
}

void func_ov011_02224f70(void) {
    M2C_UNK UpdateIntroSequence();
    UpdateIntroSequence();
}

void func_ov011_02224f7c(void) {

}

/* VCOUNT interrupt handler for the intro's scanline fade: each line it writes
   BLDALPHA so the blended layer fades out over the top 160 scanlines, from a
   half mix (EVA 8, EVB 8) down to layer B alone (EVA 0, EVB 16). */
void IntroFadeScanlineHandler(void) {
    u32 scanline = *(u16 *)GX_VCOUNT & 255;
    u8 eva = 0;
    u8 evb;
    if (scanline < 160) {
        eva = 8 - (s32)(scanline * 8) / 160;
    }
    evb = 16 - eva;
    *(u16 *)GX_BLDALPHA_MAIN = (eva & 31) | ((evb & 31) << 8);
}

/* Load the opening's two company logos into screen buffer 0 of the main and sub
   screens: logo_is on the main screen and logo_nintendo on the sub screen. */
void LoadOpeningLogos(M2C_UNK unused) {
    LoadOpeningAssetSet(unused, 1, 1, 0);
    LoadOpeningAssetSet(unused, 0, 0, 0);
}

/* Start the intro's opening stage: reset the logo object's animation, rebuild the
 * opening scene's sprites and switch the music to the intro theme. */
void Ov011_StartIntroOpening(void *intro) {
    M2C_UNK PlayMusicTrack(s32);
    M2C_UNK InitIntroLogo();
    M2C_UNK InitIntroOpeningScene(M2C_UNK);

    InitIntroLogo();
    InitIntroOpeningScene(intro);
    PlayMusicTrack(0x1001D);
}

void func_ov011_02225034(void) {
    M2C_UNK func_ov011_022224a8();
    func_ov011_022224a8();
}

void func_ov011_02225040(void) {
    M2C_UNK AdvanceIntroLogo();
    AdvanceIntroLogo();
}

void func_ov011_0222504c(void) {
    M2C_UNK func_ov011_02223cb8();
    func_ov011_02223cb8();
}

void func_ov011_02225058(void) {
    M2C_UNK func_ov011_022242dc();
    func_ov011_022242dc();
}

void func_ov011_02225064(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x39) = (u8) (M2C_FIELD(arg0, u8 *, 0x39) + 1);
}

void func_ov011_02225074(M2C_UNK arg0) {
    M2C_UNK HandleIntroInput();
    M2C_UNK func_ov011_022224a8(M2C_UNK);
    HandleIntroInput();
    func_ov011_022224a8(arg0);
}

void func_ov011_0222508c(void) {
    M2C_UNK InstallHBlankIrqHandler(void (*)(void));
    void IntroFadeScanlineHandler(void);
    InstallHBlankIrqHandler(&IntroFadeScanlineHandler);
}

void func_ov011_022250a0(void) {
    M2C_UNK StopHBlankIrq();
    StopHBlankIrq();
}

void func_ov011_022250ac(M2C_UNK arg0) {
    M2C_UNK LoadOpeningAssetSet(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    LoadOpeningAssetSet(arg0, 0x16, 0, 0);
}

/* Create the intro's opening presentation object as a child of `parent`: a sprite
 * of the intro class gIntroSpriteClass initialised with INTRO_MODE 0. */
void CreateIntroOpening(M2C_UNK parent) {
    s32 CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK InitIntroObject(s32, M2C_UNK);
    extern M2C_UNK gIntroSpriteClass;
    s32 sprite;

    sprite = CreateSpriteObject(&gIntroSpriteClass, parent);
    if (sprite == 0) {
        return;
    }
    InitIntroObject(sprite, 0);
}

/* Create the intro's title presentation object as a child of `parent`: a sprite
 * of the intro class data_ov011_02227fa4 initialised with INTRO_MODE 1. */
void CreateIntroTitle(M2C_UNK parent) {
    s32 CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK InitIntroObject(s32, M2C_UNK);
    extern M2C_UNK data_ov011_02227fa4;
    s32 sprite;

    sprite = CreateSpriteObject(&data_ov011_02227fa4, parent);
    if (sprite == 0) {
        return;
    }
    InitIntroObject(sprite, 1);
}

/* Create the intro's sequence presentation object as a child of `parent`: a
 * sprite of the intro class initialised in the sequence stage. */
void CreateIntroSequence(M2C_UNK parent) {
    s32 CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK InitIntroObject(s32, M2C_UNK);
    extern M2C_UNK gIntroSpriteClass;
    s32 sprite;

    sprite = CreateSpriteObject(&gIntroSpriteClass, parent);
    if (sprite == 0) return;
    InitIntroObject(sprite, INTRO_PRESENTATION_SEQUENCE);
}

/* Initialize the DS 3D graphics hardware: reset the geometry engine, configure the LCD display control mode,
   program the viewport/projection matrix blocks, and set up the 3D command and capture registers. */
void Ov011_Init3DRendering(void) {
    M2C_UNK G3X_Reset();
    M2C_UNK GX_SetClearColor(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32);
    M2C_UNK GX_SetOrthoProjection(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32);
    G3X_Reset();
    *(u16 *)0x04000060 = (*(u16 *)0x04000060 & ~0x3000) | 8;
    GX_SetClearColor(0, 0, 0x7FFF, 0x3F, 0);
    M2C_FIELD((void *)0x040004C8, s32 *, 0) = 0x1FF00000;
    M2C_FIELD((void *)0x040004C8, s32 *, 4) = 0x7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -8) = 0x7FFFFFFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -4) = 0x7FFF7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, 0xB8) = 0xBFFF0000;
    M2C_FIELD((void *)0x040004C8, s32 *, -0x88) = 0;
    GX_SetOrthoProjection(0, 0xC0, 0, 0x100, -0x3E8, 0, 0x1000, 1, 0);
    M2C_FIELD((void *)0x04000440, s32 *, 0) = 3;
    M2C_FIELD((void *)0x04000440, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x04000440, s32 *, 0) = 2;
    M2C_FIELD((void *)0x04000440, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x04000440, s32 *, 0x44) = 0x20000000;
    M2C_FIELD((void *)0x04000440, s32 *, 0xC) = 0;
}

void Ov011_Swap3DBuffers(void) {
    *(s32 *)0x04000540 = 1;
}

/* Create the entry's main-screen sprite and reserve its texture and palette slots. */
void InitIntroMenuEntry(void *entry) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK StringFormat(void *, M2C_UNK *, s32);
    M2C_UNK LoadAnimatedSpriteAssets(void *, void *, void *, M2C_UNK *, s32, s32, s32);
    M2C_UNK SetAnimatedSpriteFrame(void *, M2C_UNK);
    void *CreateAnimatedSpriteObject(void *);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain;
    extern M2C_UNK sIntroMenuTextureFormat, sIntroMenuContextFormat, sIntroMenuDirectory, sIntroMapUnitClutFile;
    extern s32 gIntroMenuTextureOffset;
    char texturePath[32], contextPath[32];
    void *savedEngine;
    void *sprite;
    s32 x, y;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    ((MenuEntry011 *)entry)->posX = 0;
    ((MenuEntry011 *)entry)->posY = 0;
    ((MenuEntry011 *)entry)->slideFromX = 0;
    ((MenuEntry011 *)entry)->slideFromY = 0;
    ((MenuEntry011 *)entry)->slideToX = 0;
    ((MenuEntry011 *)entry)->slideToY = 0;
    ((MenuEntry011 *)entry)->age = 0;
    ((MenuEntry011 *)entry)->slideTimer = 0;
    ((MenuEntry011 *)entry)->slideSpeed = 1;
    StringFormat(texturePath, &sIntroMenuTextureFormat, (s32)((MenuEntry011 *)entry)->name);
    StringFormat(contextPath, &sIntroMenuContextFormat, (s32)((MenuEntry011 *)entry)->name);
    SetFileDirectory(&sIntroMenuDirectory);
    ((MenuEntry011 *)entry)->sprite = CreateAnimatedSpriteObject(entry);
    LoadAnimatedSpriteAssets(((MenuEntry011 *)entry)->sprite, texturePath, contextPath,
        &sIntroMapUnitClutFile, gIntroMenuTextureOffset, ((MenuEntry011 *)entry)->index, 1);
    SetAnimatedSpriteFrame(((MenuEntry011 *)entry)->sprite, INTRO_MENU_INITIAL_FRAME);
    y = ((MenuEntry011 *)entry)->posY;
    x = ((MenuEntry011 *)entry)->posX;
    sprite = ((MenuEntry011 *)entry)->sprite;
    M2C_FIELD(sprite, s32 *, ANIMATED_SPRITE_X) = x;
    M2C_FIELD(sprite, s32 *, ANIMATED_SPRITE_Y) = y;
    M2C_FIELD(sprite, s32 *, ANIMATED_SPRITE_Z) = 0;
    gIntroMenuTextureOffset += INTRO_MENU_TEXTURE_STRIDE;
    gCur3DSpriteEngine = savedEngine;
}

/* Advance a menu entry's slide from (fromX, fromY) to (toX, toY) over `frames`
 * frames: interpolate the entry's position for the current frame and move its
 * animated sprite there; once the last frame is reached the sprite is deleted. */
void IntroMenu_UpdateEntrySlide(void *arg0, M2C_UNK fromX, M2C_UNK fromY, s16 toX, s16 toY, register u32 frames) {
 M2C_UNK DeleteSpriteObject(void *);
 s16 EaseInterpolate(M2C_UNK, M2C_UNK, s16, u32, s32);
 u32 timer; void *sprite; s32 x,y;
 timer=((MenuEntry011 *)arg0)->slideTimer;
 if(timer >= (u32)(frames-1)) {
 if(((MenuEntry011 *)arg0)->sprite!=NULL) DeleteSpriteObject(((MenuEntry011 *)arg0)->sprite);
 ((MenuEntry011 *)arg0)->sprite=NULL; return; }
 ((MenuEntry011 *)arg0)->posX=EaseInterpolate(0,fromX,toX,timer,frames);
 ((MenuEntry011 *)arg0)->posY=EaseInterpolate(0,fromY,toY,((MenuEntry011 *)arg0)->slideTimer,frames);
 sprite=((MenuEntry011 *)arg0)->sprite; if(!sprite)return;
 y=((MenuEntry011 *)arg0)->posY; x=((MenuEntry011 *)arg0)->posX;
 M2C_FIELD(sprite,s32 *,ANIMATED_SPRITE_X)=x; M2C_FIELD(sprite,s32 *,ANIMATED_SPRITE_Y)=y; M2C_FIELD(sprite,s32 *,ANIMATED_SPRITE_Z)=0;
}

void func_ov011_022253f0(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    M2C_FIELD(arg0, s16 *, 0x3C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = arg2;
    M2C_FIELD(arg0, s16 *, 0x40) = arg3;
    M2C_FIELD(arg0, s16 *, 0x42) = arg4;
}

void func_ov011_02225408(void *arg0, u8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x35) = arg1;
}

void func_ov011_02225410(void *arg0, u8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x34) = arg1;
}

void func_ov011_02225418(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
}

void func_ov011_02225420(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
}

/* Renders the entry's localized label into the sprite buffer and draws the
 * two-row highlight bar behind it, positioned from the entry's index. */
void DrawMenuEntryHighlight(MenuEntry011 *entry) {
    s32 RuntimeIntDivMod(s32, s32);
    s32 GetLocalizedText(s32);
    s32 RenderTextToTiles(s32, s32);
    void DrawTileRow(u16, s32, u16, s32, s32);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    s16 labelWidth;
    s16 x2;
    s16 width;
    s32 clamped;
    s32 step1;
    s32 slotB;
    s32 step2;
    s32 slotA;
    u8 count;
    u8 count2;
    s16 x;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    entry->textWidth = RenderTextToTiles(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + ((((entry->index + 1) << 6) + 0x40) << 5), GetLocalizedText(entry->labelId));
    labelWidth = entry->textWidth;
    x = 0x80 - ((s32) (labelWidth + ((u32) labelWidth >> 0x1F)) >> 1);
    clamped = entry->posX - x;
    if (clamped < labelWidth) {
        entry->textWidth = (s16) clamped;
    }
    width = entry->textWidth;
    x2 = x;
    if ((s32) width > 0) {
        count = entry->count;
        slotA = entry->index + 1;
        step1 = RuntimeIntDivMod(0x80, count);
        DrawTileRow((u16) (x2 & 0x1FF), (u16) ((u8) (((step1 * slotA) + 0x28) - RuntimeIntDivMod(0x80, count * 2)) | 0x400), (u16) width, (u16) ((0x3FF & ((s32) ((slotA << 6) + 0x40) >> ((u32) (*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        count2 = entry->count;
        slotB = entry->index + 1;
        step2 = RuntimeIntDivMod(0x80, count2);
        DrawTileRow((u16) ((x2 + 2) & 0x1FF), (u16) ((u8) (((step2 * slotB) + 0x2A) - RuntimeIntDivMod(0x80, count2 * 2)) | 0x400), (u16) entry->textWidth, (u16) ((0x3FF & ((s32) ((slotB << 6) + 0x40) >> ((u32) (*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
    }
    gCur3DSpriteEngine = savedEngine;
}

void func_ov011_02225600(void) {

}

/* Per-frame step of one intro-menu entry: count one more update of the entry's
 * age and advance its slide timer by its slide speed. */
void IntroMenu_AdvanceEntryTimers(MenuEntry011 *entry) {
    entry->age = (s32) (entry->age + 1);
    entry->slideTimer = (s32) (entry->slideTimer + entry->slideSpeed);
}

/* Per-frame update of one intro-menu entry: draw its label's highlight if it has
 * one, advance its slide from its from-point to its to-point, and delete the entry
 * once it has lived INTRO_MENU_ENTRY_LIFETIME updates. */
void UpdateIntroMenuEntry(MenuEntry011 *entry) {
    M2C_UNK DeleteSpriteObject(void *);
    void DrawMenuEntryHighlight();
    if (entry->labelId) DrawMenuEntryHighlight(entry);
    IntroMenu_UpdateEntrySlide(entry, entry->slideFromX, entry->slideFromY, entry->slideToX, entry->slideToY, INTRO_MENU_ENTRY_SLIDE_FRAMES);
    if ((u32) entry->age < INTRO_MENU_ENTRY_LIFETIME) return;
    DeleteSpriteObject(entry);
}

/* Initialise the intro-menu object before it starts walking the menu script:
   install its vtable, clear the flags, timers, entry sprites and shown label,
   point the cursor at the first gIntroMenuTable step and load its UI graphics. */
IntroMenu011 *InitIntroMenu(IntroMenu011 *menu) {
    M2C_UNK LoadUiGraphicsBank(s32);
    extern M2C_UNK gIntroMenuVTable;
    extern IntroMenuStep gIntroMenuTable[];
    s32 i;

    menu->vtable = &gIntroMenuVTable;
    i = 0;
    menu->flags |= INTRO_MENU_FLAG_ACTIVE;
    menu->timer = 0;
    menu->fadeTimer = 0;
    menu->appearTimer = 0;
    menu->flags &= ~INTRO_MENU_PHASE_MASK;
    menu->entryCount &= ~INTRO_MENU_COUNT_MASK;
    menu->labelId = 0;
    do {
        menu->entries[i] = NULL;
        i++;
    } while (i < 3);
    menu->step = gIntroMenuTable;
    LoadUiGraphicsBank(10);
    return menu;
}

/* Intro-menu vtable destroy entry: reset the object's vtable, delete its three
 * entry sprites and release UI graphics bank 10, without freeing the object. */
void *IntroMenu_Destroy(IntroMenu011 *menu) {
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK FreeUiGraphicsBank(s32);
    extern M2C_UNK gIntroMenuVTable;
    register s32 i;

    menu->vtable = &gIntroMenuVTable;
    i = 0;
    do {
        void *p = menu->entries[i];
        if (p) {
            DeleteSpriteObject(p);
            menu->entries[i] = 0;
        }
        i++;
    } while (i < 3);
    FreeUiGraphicsBank(10);
    return menu;
}

/* Intro-menu vtable destroy-and-free entry: reset the object's vtable, delete its
 * three entry sprites, release UI graphics bank 10 and free the object. */
void *IntroMenu_DestroyAndFree(IntroMenu011 *menu) {
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK FreeUiGraphicsBank(s32);
    extern M2C_UNK gIntroMenuVTable;
    register s32 i;
    menu->vtable = &gIntroMenuVTable;
    i = 0;
    do {
        void *p = menu->entries[i];
        if (p) {
            DeleteSpriteObject(p);
            menu->entries[i] = 0;
        }
        i++;
    } while (i < 3);
    FreeUiGraphicsBank(10);
    MemFree(menu);
    return menu;
}

void func_ov011_022257b4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 4);
}

/* Draw the intro-menu entry's localized label centred on the main screen:
 * measure the label's width and draw its two tile rows (shadow and text). */
void DrawIntroMenuLabel(void *entry) {
s32 GetLocalizedText(s32); s32 RenderTextToTiles(s32,s32); void DrawTileRow(u16,s32,u16,s32,s32);
extern void *g3DSpriteEngineMain; extern void *gCur3DSpriteEngine;
s16 labelWidth,x; u16 w; void *savedEngine;
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
labelWidth=RenderTextToTiles(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c),GetLocalizedText(M2C_FIELD(entry,s32 *,0x50)));
x=128-labelWidth/2;w=labelWidth;
DrawTileRow((u16)(x&511),14,w,0xf800,11);
DrawTileRow((u16)((x+1)&511),15,w,0xe800,17);
gCur3DSpriteEngine=savedEngine;
}

#pragma opt_common_subs off
void func_ov011_0222588c(void *a) {
extern s32 data_ov011_02228cec;
s32 func_ov011_02225a18(void *); void *SpawnIntroMenuEntry(void *);
s32 values[3],labels[3]; s32 i,n; register u32 k; s32 *p; s32 v,l; u8 y;
data_ov011_02228cec=0; ((MenuCount011 *)a)->count=0;
while(func_ov011_02225a18(a)==2 && (k=((MenuCount011 *)a)->count)<3) {
p=M2C_FIELD(a,s32 **,0x4c); v=p[2];l=p[3]; M2C_FIELD(a,s32 **,0x4c)+=4;
values[k]=v;labels[k]=l; ((MenuCount011 *)a)->count=(u8)(((MenuCount011 *)a)->count+1);
}
for(i=0,n=((MenuCount011 *)a)->count;i<n;i++,n=((MenuCount011 *)a)->count) {
((void **)((u8 *)a+0x40))[i]=SpawnIntroMenuEntry(a);
func_ov011_02225420(((void **)((u8 *)a+0x40))[i],labels[i]);
func_ov011_02225408(((void **)((u8 *)a+0x40))[i],(u8)i);
func_ov011_02225238(((void **)((u8 *)a+0x40))[i]);
y=60+(128/n)*(i+1)-128/(n*2);
func_ov011_022253f0(((void **)((u8 *)a+0x40))[i],-16,y,272,y);
func_ov011_02225418(((void **)((u8 *)a+0x40))[i],values[i]);
func_ov011_02225410(((void **)((u8 *)a+0x40))[i],((MenuCount011 *)a)->count);
}}
#pragma opt_common_subs reset
s32 func_ov011_02225a18(void *arg0) {
    return *M2C_FIELD(arg0, s32 **, 0x4C);
}

/* Double the slide speed of every intro menu entry under the touch point. */
void IntroMenu_AccelerateTouchedEntry(void *menuObject, s32 touchX, s32 touchY) {
    IntroMenu011 *menu = menuObject;
    s16 x, y;
    s32 entryIndex;
    MenuEntry011 *entry;

    entryIndex = 0;
    if ((s32)((u32)(menu->entryCount << 28) >> 28) <= 0) {
        return;
    }
    do {
        entry = menu->entries[entryIndex];
        x = entry->posX;
        if (x - INTRO_MENU_ENTRY_TOUCH_RADIUS <= touchX && touchX < x + INTRO_MENU_ENTRY_TOUCH_RADIUS) {
            y = entry->posY;
            if (y - INTRO_MENU_ENTRY_TOUCH_RADIUS <= touchY && touchY < y + INTRO_MENU_ENTRY_TOUCH_RADIUS) {
                entry->slideSpeed = INTRO_MENU_ENTRY_FAST_SLIDE;
            }
        }
        entryIndex++;
    } while (entryIndex < (s32)((u32)(menu->entryCount << 28) >> 28));
}

