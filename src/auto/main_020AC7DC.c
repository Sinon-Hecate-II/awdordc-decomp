/* 37 functions from 0x020AC7DC to 0x020AD78C (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

s32 *RecordsMenu_GetRecord(s32);

/* Per-frame update of a screen-fade transition sprite: advances its elapsed
 * frames and, on each screen it selected, eases its bank brightness (modes 0/1)
 * or split windows (mode 2); once the duration is reached it applies the new
 * screen mode and lets the sprite's animation finish. */
void ScreenFadeSprite_Update(void *fade) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub,g3DSpriteEngineMain;
s32 EaseInterpolate(s32,s32,s32,s32,s32);
s32 amount; register s8 pos,neg;s32 savedEngine,engine; register s32 i;u8 screenMode;
M2C_FIELD(fade,u16 *,TRANSITION_SPRITE_ELAPSED)++;
amount=EaseInterpolate(0,0,16,M2C_FIELD(fade,u16 *,TRANSITION_SPRITE_ELAPSED),M2C_FIELD(fade,u16 *,TRANSITION_SPRITE_LENGTH));

savedEngine=gCur3DSpriteEngine;
i=0;

do {
if(i==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
screenMode=M2C_FIELD(fade,u8 *,TRANSITION_SPRITE_SCREEN);
if(screenMode==0 && engine!=g3DSpriteEngineMain)goto next;
if(screenMode==1 && engine!=g3DSpriteEngineSub)goto next;
if(screenMode==3 && engine!=savedEngine)goto next;
switch(M2C_FIELD(fade,s32 *,TRANSITION_SPRITE_MODE)){
case 0:M2C_FIELD(M2C_FIELD(engine,void **,0),s8 *,0x50)=(s8)-amount;break;
case 1:M2C_FIELD(M2C_FIELD(engine,void **,0),s8 *,0x50)=(s8)amount;break;
case 2:UpdateSplitTransition(M2C_FIELD(fade,u16 *,TRANSITION_SPRITE_LENGTH)-M2C_FIELD(fade,u16 *,TRANSITION_SPRITE_ELAPSED));break;
}
if(M2C_FIELD(fade,u16 *,TRANSITION_SPRITE_ELAPSED)>=M2C_FIELD(fade,u16 *,TRANSITION_SPRITE_LENGTH)){
ApplyScreenMode((u8)M2C_FIELD(fade,s32 *,TRANSITION_SPRITE_MODE));
Sprite_ResumeAnimation(fade);
}
next: i++;
}while(i<2);
gCur3DSpriteEngine=savedEngine;
if(M2C_FIELD(fade,s32 *,0x18)==1)func_020ac598(M2C_FIELD(fade,u8 *,TRANSITION_SPRITE_SCREEN));
}

s32 func_020ac924(M2C_UNK parent, s32 type) {
    s32 Find3DSpriteByClassAndZ(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gScreenTransitionClass, gScreenFadeClass;
    switch (type) {
    case 0:
        return Find3DSpriteByClassAndZ(&gScreenTransitionClass, parent);
    case 1:
        return Find3DSpriteByClassAndZ(&gScreenFadeClass, parent);
    default:
        return 0;
    }
}

void DeleteScreenTransitionSprites(M2C_UNK parent) {
    void DeleteSpriteObject(M2C_UNK);
    s32 func_020ac924(M2C_UNK, s32);
    DeleteSpriteObject(func_020ac924(parent, 0));
    DeleteSpriteObject(func_020ac924(parent, 1));
}

void SetScreenMode(s32 mode) {
s32 GetScreenMode(u8); void ConfigureScreenEngine(u8,s32,s32);
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain;
u8 currentIsPrimary, screen; u16 *volatile p; u16 *volatile q;
if(gCur3DSpriteEngine==g3DSpriteEngineMain)currentIsPrimary=1;else currentIsPrimary=0;
if(currentIsPrimary!=1)screen=1;else screen=0;
if(mode==3)mode=GetScreenMode(screen);
DeleteScreenTransitionSprites(screen);ConfigureScreenEngine(screen,0,mode);
switch(mode){
case 0: case 1: M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x50)=0;break;
case 2:
p=*(u16 **)gCur3DSpriteEngine;*p = *p & ~0x200;
q=*(u16 **)gCur3DSpriteEngine;*q = *q & ~0x400;
break;
}
/* Configure the active display for the requested mode. */
}

M2C_UNK ApplyScreenMode(M2C_UNK arg0) {
    s32 GetScreenMode(u8);
    void DeleteScreenTransitionSprites(M2C_UNK);
    void ConfigureScreenEngine(u8, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    u8 currentIsPrimary;
    u8 screen;
    s32 mode;
    u16 *volatile sp44;
    u16 *volatile sp40;
    u16 *volatile sp3c;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2c;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1c;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;

    if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
        currentIsPrimary = 1;
    } else {
        currentIsPrimary = 0;
    }
    if (currentIsPrimary != 1) {
        screen = 1;
    } else {
        screen = 0;
    }
    if (arg0 == 3) {
        mode = GetScreenMode(screen);
        DeleteScreenTransitionSprites(screen);
        ConfigureScreenEngine(screen, 1, mode);
        switch (mode) {
        case 0:
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = -16;
            break;
        case 1:
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = 0x10;
            break;
        case 2:
            break;
        }
    } else {
        sp44 = (u16 *)*(u8 **)gCur3DSpriteEngine;
        *sp44 = *sp44 | 0x200;

        sp40 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp40 = *sp40 & ~1;

        sp3c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp3c = *sp3c & ~2;

        sp38 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp38 = *sp38 & ~4;

        sp34 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp34 = *sp34 & ~8;

        sp30 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp30 = *sp30 & ~0x10;

        sp2c = (u16 *)*(u8 **)gCur3DSpriteEngine;
        *sp2c = *sp2c | 0x400;

        sp28 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp28 = *sp28 & ~0x100;

        sp24 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp24 = *sp24 & ~0x200;

        sp20 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp20 = *sp20 & ~0x400;

        sp1c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp1c = *sp1c & ~0x800;

        sp18 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp18 = *sp18 & ~0x1000;

        sp14 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp14 = (*sp14 & ~1) | 1;

        sp10 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp10 = *sp10 | 0x2;

        spC = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *spC = *spC | 0x4;

        sp8 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp8 = *sp8 | 0x8;

        sp4 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp4 = *sp4 | 0x10;

        sp0 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp0 = *sp0 | 0x20;

        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x48) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4a) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x49) = 0xff;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4b) = 0xc0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4c) = 1;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4e) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4d) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4f) = 0xc0;
    }
}

void FinishCurrentScreenTransition(void) {
    s32 GetScreenFlag(u8);
    M2C_UNK ApplyScreenMode(M2C_UNK);
    extern s32 g3DSpriteEngineMain, gCur3DSpriteEngine;
    u8 main = gCur3DSpriteEngine == g3DSpriteEngineMain;
    u8 other = main != 1;
    if (GetScreenFlag(other) != 1)
        return;
    ApplyScreenMode(3);
}

/* Plays a display transition on the screen that is not the active one: unless the
 * transition is instant (length 0, which applies the mode at once), create its
 * sprite on `layer` there, animating `mode` for `length` frames. */
void CreateScreenTransitionSprite(s32 mode, s16 length, s32 layer) {
 void *CreateSpriteFromClass(M2C_UNK *, s32);
 s32 GetScreenFlag(u8);
 void SetScreenMode(s32);
 extern M2C_UNK gScreenTransitionClass;
 extern s32 g3DSpriteEngineMain, gCur3DSpriteEngine;
 s32 spriteLayer;
 u8 currentIsPrimary;
 u8 screen;
 void *sprite;
 if(gCur3DSpriteEngine == g3DSpriteEngineMain) currentIsPrimary=1; else currentIsPrimary=0;
 if(currentIsPrimary != 1) screen=1; else screen=0;
 spriteLayer=layer;
 if(spriteLayer==0) spriteLayer=7;
 if(length==0) {
 DeleteScreenTransitionSprites(screen);
 SetScreenMode(mode);
 return;
 }
 if(GetScreenFlag(screen)==0) return;
 DeleteScreenTransitionSprites(screen);
 sprite=CreateSpriteFromClass(&gScreenTransitionClass,spriteLayer);
 M2C_FIELD(sprite,s16 *,DS3D_SPRITE_Z)=screen;
 M2C_FIELD(sprite,u8 *,TRANSITION_SPRITE_SCREEN)=screen;
 M2C_FIELD(sprite,s16 *,TRANSITION_SPRITE_LENGTH)=length;
 M2C_FIELD(sprite,s32 *,TRANSITION_SPRITE_MODE)=mode;
 M2C_FIELD(sprite,s32 *,TRANSITION_SPRITE_PARENT)=0;
}

/* Starts the screen-change transition on the screen the active 3D-sprite engine
 * draws to: a transition object slides the screen sideways (mode 0/1) or splits
 * it (mode 2) over `duration` frames.  A zero duration applies the mode at once
 * instead, and nothing is created when the screen is already set up for the
 * other kind of transition. */
void StartScreenFade(s32 mode, s16 duration, s32 createMode) {
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    s32 GetScreenFlag(u8);
    M2C_UNK ApplyScreenMode(M2C_UNK);
    extern M2C_UNK gScreenFadeClass;
    extern s32 g3DSpriteEngineMain, gCur3DSpriteEngine;
    s32 variant;
    u8 isPrimary;
    u8 screen;
    DS3DSpriteScreenFade *fade;

    if (gCur3DSpriteEngine == g3DSpriteEngineMain) isPrimary = 1; else isPrimary = 0;
    if (isPrimary != 1) screen = 1; else screen = 0;
    variant = createMode;
    if (variant == 0) variant = 7;
    if (duration == 0) {
        DeleteScreenTransitionSprites(screen);
        ApplyScreenMode(mode);
        return;
    }
    if (GetScreenFlag(screen) == 1) return;
    DeleteScreenTransitionSprites(screen);
    fade = CreateSpriteFromClass(&gScreenFadeClass, variant);
    M2C_FIELD(fade, s16 *, DS3D_SPRITE_Z) = screen;
    fade->screen = screen;
    fade->length = duration;
    fade->mode = mode;
    fade->resource = 0;
}

/* Creates a screen-change transition sprite on the screen that is not active,
 * attached as a child of `parent`: the parent's child count is incremented so it
 * is not updated and outlives the transition (the transition's destructor
 * releases it again).  A zero length applies the mode at once instead, and
 * nothing is created when the screen is already set up for the other kind of
 * transition. */
void CreateScreenTransitionChild(s32 mode, s16 length, s32 parent) {
void *CreateSpriteFromClass(M2C_UNK *, s32);
s32 GetScreenFlag(u8);
void SetScreenMode(s32);
M2C_UNK IncrementSpriteChildCount(s32);
extern M2C_UNK gScreenTransitionClass;
extern s32 g3DSpriteEngineMain, gCur3DSpriteEngine;
u8 isPrimary, screen;
void *sprite;
if(gCur3DSpriteEngine == g3DSpriteEngineMain) isPrimary=1; else isPrimary=0;
if(isPrimary != 1) screen=1; else screen=0;
if(length==0) {
DeleteScreenTransitionSprites(screen);
SetScreenMode(mode);
return;
}
if(GetScreenFlag(screen)==0) return;
DeleteScreenTransitionSprites(screen);
sprite=CreateSpriteFromClass(&gScreenTransitionClass,1);
M2C_FIELD(sprite,s16 *,DS3D_SPRITE_Z)=screen;
M2C_FIELD(sprite,u8 *,TRANSITION_SPRITE_SCREEN)=screen;
M2C_FIELD(sprite,s16 *,TRANSITION_SPRITE_LENGTH)=length;
M2C_FIELD(sprite,s32 *,TRANSITION_SPRITE_MODE)=mode;
M2C_FIELD(sprite,s32 *,TRANSITION_SPRITE_PARENT)=parent;
IncrementSpriteChildCount(parent);
}

/* Starts a screen fade attached to a parent sprite (it counts as one of the
 * parent's children, so the parent waits for it): on the screen the active
 * 3D-sprite engine does NOT draw to, fades `mode` over `duration` frames.  A zero
 * duration applies the mode at once instead, and nothing is created when the
 * screen is already set up for a fade. */
void StartScreenFadeChild(s32 mode, s16 duration, s32 parent) {
void *CreateSpriteFromClass(M2C_UNK *, s32);
s32 GetScreenFlag(u8);
M2C_UNK ApplyScreenMode(M2C_UNK);
M2C_UNK IncrementSpriteChildCount(s32);
extern M2C_UNK gScreenFadeClass;
extern s32 g3DSpriteEngineMain, gCur3DSpriteEngine;
u8 isPrimary, screen;
void *fade;
if(gCur3DSpriteEngine == g3DSpriteEngineMain) isPrimary=1; else isPrimary=0;
if(isPrimary != 1) screen=1; else screen=0;
if(duration==0) {
DeleteScreenTransitionSprites(screen);
ApplyScreenMode(mode);
return;
}
if(GetScreenFlag(screen)==1) return;
DeleteScreenTransitionSprites(screen);
fade=CreateSpriteFromClass(&gScreenFadeClass,1);
M2C_FIELD(fade,s16 *,DS3D_SPRITE_Z)=screen;
M2C_FIELD(fade,u8 *,TRANSITION_SPRITE_SCREEN)=screen;
M2C_FIELD(fade,s16 *,TRANSITION_SPRITE_LENGTH)=duration;
M2C_FIELD(fade,s32 *,TRANSITION_SPRITE_MODE)=mode;
M2C_FIELD(fade,s32 *,TRANSITION_SPRITE_PARENT)=parent;
IncrementSpriteChildCount(parent);
}

/* Starts a screen transition on the main screen, the sub screen, both screens
 * or whichever screen is active: switches gCur3DSpriteEngine to each engine in
 * turn and creates the transition sprite on the selected ones, then puts the
 * previous engine back. */
void CreateScreenTransitions(s32 mode, s16 length, s32 target, s32 variant) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    s32 savedEngine;
    s32 engine;
    s32 screen;

    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        if (((target != DS3D_TARGET_MAIN) || (engine == g3DSpriteEngineMain)) &&
            ((target != DS3D_TARGET_SUB) || (engine == g3DSpriteEngineSub)) &&
            ((target != DS3D_TARGET_ACTIVE) || (engine == savedEngine))) {
            CreateScreenTransitionSprite(mode, length, variant);
        }
        screen += 1;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Starts a screen fade on the main screen, the sub screen, both screens or
 * whichever screen is active: switches gCur3DSpriteEngine to each engine in
 * turn and creates the fade on the selected ones, then puts the previous engine
 * back. */
void StartScreenFades(s32 mode, s16 length, s32 target, s32 variant) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    s32 savedEngine;
    s32 engine;
    s32 screen;

    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        if (((target != DS3D_TARGET_MAIN) || (engine == g3DSpriteEngineMain)) &&
            ((target != DS3D_TARGET_SUB) || (engine == g3DSpriteEngineSub)) &&
            ((target != DS3D_TARGET_ACTIVE) || (engine == savedEngine))) {
            StartScreenFade(mode, length, variant);
        }
        screen += 1;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Creates a screen transition on the main screen, the sub screen, both screens
 * or whichever screen is active, each one attached as a child of `parent`
 * (unlike CreateScreenTransitions, the transition follows that sprite): switches
 * gCur3DSpriteEngine to each engine in turn and creates the transition sprite on
 * the selected ones, then puts the previous engine back. */
void CreateScreenTransitionChildren(s32 mode, s16 length, s32 target, s32 parent) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    s32 savedEngine;
    s32 engine;
    s32 screen;

    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        if (((target != DS3D_TARGET_MAIN) || (engine == g3DSpriteEngineMain)) &&
            ((target != DS3D_TARGET_SUB) || (engine == g3DSpriteEngineSub)) &&
            ((target != DS3D_TARGET_ACTIVE) || (engine == savedEngine))) {
            CreateScreenTransitionChild(mode, length, parent);
        }
        screen += 1;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Starts a screen fade on the main screen, the sub screen, both screens or
 * whichever screen is active, each one attached as a child of `parent` (unlike
 * StartScreenFades, the fade follows that sprite): switches gCur3DSpriteEngine to
 * each engine in turn and creates the fade on the selected ones, then puts the
 * previous engine back. */
void StartScreenFadeChildren(s32 mode, s16 length, s32 target, s32 parent) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    s32 savedEngine;
    s32 engine;
    s32 screen;

    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        if (((target != DS3D_TARGET_MAIN) || (engine == g3DSpriteEngineMain)) &&
            ((target != DS3D_TARGET_SUB) || (engine == g3DSpriteEngineSub)) &&
            ((target != DS3D_TARGET_ACTIVE) || (engine == savedEngine))) {
            StartScreenFadeChild(mode, length, parent);
        }
        screen += 1;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
}

u8 IsScreenFadeActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gScreenTransitionClass;
    extern M2C_UNK gScreenFadeClass;
    u8 var_r0;

    if (FindObjectByClass(&gScreenTransitionClass) != 0) {
        return 1U;
    }
    if (FindObjectByClass(&gScreenFadeClass) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK LocalizeMapBackgroundFileName(s32 arg0, M2C_UNK *arg1) {
    u8 GetLanguage(void);
    M2C_UNK *GetLocalizedFileName(s32);

    if ((arg0 != 0x2E) && (arg0 != 0x2F)) {
        goto done;
    }
    if (GetLanguage() != 2) {
        goto done;
    }
    return (M2C_UNK) GetLocalizedFileName((s32) arg1);
done:
    return (M2C_UNK) arg1;
}

/* Build a map background's ".narc" archive name: copy the background's base name,
 * append the extension and localize the result. */
void BuildMapBackgroundNarcName(s32 background) {
 M2C_UNK StringCopy(M2C_UNK *, s32);
 M2C_UNK StringAppend(M2C_UNK *, M2C_UNK *);
 M2C_UNK LocalizeMapBackgroundFileName(s32, M2C_UNK *);
 extern s32 gMapBackgroundNames[];
 extern M2C_UNK gNarcFileExtension, gMapBackgroundNarcName;
 StringCopy(&gMapBackgroundNarcName, gMapBackgroundNames[background]);
 StringAppend(&gMapBackgroundNarcName, &gNarcFileExtension);
 LocalizeMapBackgroundFileName(background, &gMapBackgroundNarcName);
}
