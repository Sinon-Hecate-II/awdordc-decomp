/* 17 functions from 0x02094D8C to 0x02095C90 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

/* Frame countdown of the scene-script wait sprite: CreateScriptWaitSprite creates the
 * sprite (class gScriptWaitSpriteClass) with it and the sprite's update callback steps it,
 * resuming the script when it reaches 0 or the player skips the dialog. */
#define SCRIPT_WAIT_FRAMES 0x6C /* s16 frames left to wait */

typedef struct SpriteControl094df0 { u16 mode:3; u16 rest:13; } SpriteControl094df0;
typedef struct SpriteBuffer094df0 { u8 bytes[1]; } SpriteBuffer094df0;
static inline u8 IsMain094df0(void) { extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain; u8 value; if(gCur3DSpriteEngine==g3DSpriteEngineMain)value=1;else value=0; return value; }
static inline void *SpriteBufferAt094df0(s32 buffer,s32 offset) { return (u8*)buffer+offset; }

/* Highlight face `faceIndex` of the two-face scene panel, unless a message box is
 * up: while one is shown the panels belong to it. */
void HighlightScenePanelFaceUnlessMessageBox(s32 faceIndex) {
    s32 IsMessageBoxActive();
    void HighlightScenePanelFace(s32);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    HighlightScenePanelFace(faceIndex);
}

/* Clears the current scene-panel highlight: with the single-panel layout (fewer
 * than two 3D sprites) it clears the panel highlight, with the two-face layout
 * (exactly two 3D sprites) it clears both faces. */
void ClearScenePanelHighlight(void) {
    s32 Get3DSpriteCount();
    M2C_UNK HighlightScenePanel(M2C_UNK);
    s32 spriteCount;

    if (IsMessageBoxActive() != 0) {
        return;
    }
    spriteCount = Get3DSpriteCount();
    switch (spriteCount) {                          /* irregular */
    case 0:
    case 1:
        HighlightScenePanel(-1);
        return;
    case 2:
        HighlightScenePanelFace(-1);
        return;
    }
}

#pragma inline_depth(2)
void func_02094df0(s32 arg0, s32 arg1, s32 arg2) {
u8 Get3DSpriteScreenMode(s32);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
extern M2C_UNK data_02102d0c;
s32 saved, i, bank, engine;
s32 amount, buffer;
u16 *volatile p28; u16 *volatile p24; u16 *volatile p20; u16 *volatile p1c; u16 *volatile p18; u16 *volatile p14; u16 *volatile p10;
if(IsMessageBoxActive())return;
saved=gCur3DSpriteEngine;
i=0;
do {
if(i==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
if(arg0==0 && engine!=g3DSpriteEngineMain)goto end;
if(arg0==1 && engine!=g3DSpriteEngineSub)goto end;
if(arg0==3 && engine!=saved)goto end;
bank=0;
p28=*(u16**)engine; *p28 = *p28 & ~0x40;
p24=*(u16**)gCur3DSpriteEngine; *p24 = *p24 & ~0x80;
SetFileDirectory(&data_02102d0c);
BuildMapBackgroundNarcName(arg2);OpenNarcArchive();
if(arg2==0x4a){
BuildMapBackgroundCgName(arg2);LoadNarcFileDecompressed(GetLocalizedFileName(),M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32*,0xc));
BuildMapBackgroundScName(arg2);LoadNarcFileDecompressed(GetLocalizedFileName(),M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32*,0x20));
}else {
LoadNarcFileDecompressed(BuildMapBackgroundCgName(arg2),M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32*,0xc));
LoadNarcFileDecompressed(BuildMapBackgroundScName(arg2),M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32*,0x20));
}
if(arg1==2)bank=0;
if(arg1==3)bank=1;
BuildMapBackgroundClName(arg2);
switch(func_02081568()){
case 0x100:
amount=(u8)(bank*6+4); bank=amount<<5;
M2C_FIELD((s32)(*(u16**)gCur3DSpriteEngine+3+arg1),u16*,0)&=~0x80;
LoadNarcFileToSpriteBuffer(BuildMapBackgroundClName(arg2),bank,0xc0);
ApplyFacePaletteStyle((u8)GetFacePaletteStyle(),M2C_FIELD(gCur3DSpriteEngine,s32*,0x30)+(bank&~1),0xc0);
OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32*,0x20),(u16)Get3DSpriteLayerSize((u8)((*(SpriteControl094df0**)gCur3DSpriteEngine)->mode),(u8)arg1),(u16)((amount&15)<<12));
break;
case 0x200:
M2C_FIELD((s32)(*(u16**)gCur3DSpriteEngine+3+(u32)arg1),u16*,0)|=0x80;
buffer=LoadNarcFileToNewBuffer(BuildMapBackgroundClName(arg2),0x200);
ApplyFacePaletteStyle((u8)GetFacePaletteStyle(),buffer,0x200);
QueueBGExtPaletteUpload(buffer,arg1,bank<<9,0x200,1);
OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32*,0x20),(u16)Get3DSpriteLayerSize((u8)((*(SpriteControl094df0**)gCur3DSpriteEngine)->mode),(u8)arg1),(u16)((bank&15)<<12));
break;
}
M2C_FIELD(*(s32*)gCur3DSpriteEngine+(u8)arg1*2,u16*,0x38)=0;
M2C_FIELD(*(s32*)gCur3DSpriteEngine+(u8)arg1*2,u16*,0x40)=0;
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1<<arg1;
switch((u8)Get3DSpriteScreenMode(((u8)(gCur3DSpriteEngine==g3DSpriteEngineMain))!=1)){
case 0:p20=*(u16**)gCur3DSpriteEngine;*p20=*p20|0x10;break;
case 1:p1c=*(u16**)gCur3DSpriteEngine;*p1c=*p1c|0x20;break;
case 2:p18=*(u16**)gCur3DSpriteEngine;*p18=*p18|0x40;break;
case 3:p14=*(u16**)gCur3DSpriteEngine;*p14=*p14|0x80;break;
case 4:p10=*(u16**)gCur3DSpriteEngine;*p10=*p10|0x100;break;
}
MarkMapBackgroundSeen(arg2);CloseNarcArchive();
end:i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
/* Play the records-screen track a script asked for: a gRecordTracks index plays
 * that record, RECORD_TRACK_STOP fades the music out and RECORD_TRACK_WAIT
 * starts a sprite that waits for the fade to finish. */
void RecordsMenu_PlayTrack(s32 track) {
    extern M2C_UNK gMusicFadeWaitSpriteClass;
    if (IsMessageBoxActive()) return;
    switch (track) {
    case RECORD_TRACK_STOP: FadeOutMusicDefault(); return;
    case RECORD_TRACK_WAIT: CreateSpriteFromClass(&gMusicFadeWaitSpriteClass, 7); return;
    default: PlayMusicTrack(RecordsMenu_GetRecordTrack(track)); return;
    }
}

/* Whether the sprite that waits for the music to finish fading out (the one
 * RECORD_TRACK_WAIT creates) is still running. */
u8 IsMusicFadeWaitSpriteActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gMusicFadeWaitSpriteClass;
    u8 active;

    if (FindObjectByClass(&gMusicFadeWaitSpriteClass) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* Text-script command: play the preset sound effect the command's operand
 * selects from the script's sound table, unless a message box is up. */
void ScriptCmd_PlaySound(s32 soundIndex) {
    s32 PlaySoundEffect(s32);
    s32 GetScriptSoundId(s32);

    if (IsMessageBoxActive() != 0) {
        return;
    }
    PlaySoundEffect(GetScriptSoundId(soundIndex));
}

/* Scene-script opcode: `isFade` 0 creates a screen transition object and 1 a
 * screen fade, in `mode` (dark, bright or split) for `duration` frames, on the
 * script's target screen and layer 7.  While a message box is up the change is
 * applied at once (duration 0). */
void StartScriptedScreenTransition(s32 isFade,s32 mode,s32 duration) {
u32 target=(u8)GetScriptTransitionTarget();
if(IsMessageBoxActive())duration=0;
switch(isFade) {
case 0:CreateScreenTransitions((u8)mode,(u16)duration,target,7);return;
case 1:StartScreenFades((u8)mode,(u16)duration,target,7);return;
}
}

/* Resume the script after the fade ends or after skipping both screen transitions. */
void WaitForScreenFadeOrSkip(void *scriptSprite) {
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain, gCur3DSpriteEngine;
    s32 savedEngine, engineIndex, engine;

    if (IsScreenFadeActive()) {
        if (!TryStartDialogSkip()) {
            return;
        }
        savedEngine = gCur3DSpriteEngine;
        engineIndex = DS3D_TARGET_MAIN;
        do {
            if (engineIndex == DS3D_TARGET_MAIN) {
                engine = g3DSpriteEngineMain;
            } else {
                engine = g3DSpriteEngineSub;
            }
            gCur3DSpriteEngine = engine;
            FinishCurrentScreenTransition();
            engineIndex++;
        } while (engineIndex < DS3D_TARGET_SUB + 1);
        gCur3DSpriteEngine = savedEngine;
    }
    Sprite_ResumeAnimation(scriptSprite);
}

/* Create the screen-transition wait object: it holds the scene script until the
 * running screen transition or fade has finished (or the player skips it), then
 * resumes the script. */
void CreateScreenTransitionWaitSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gScreenTransitionWaitSpriteClass;
    CreateSpriteFromClass(&gScreenTransitionWaitSpriteClass, 7);
}

/* TRUE while the screen-transition wait sprite (gScreenTransitionWaitSpriteClass)
 * is on screen. */
u8 IsScreenTransitionWaitSpriteActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gScreenTransitionWaitSpriteClass;
    u8 active;

    if (FindObjectByClass(&gScreenTransitionWaitSpriteClass) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* Scene-script wait sprite's update: resume the script after SCRIPT_WAIT_FRAMES
 * frames, or at once when the player skips the dialog. */
void WaitForScriptFramesOrSkip(void *sprite) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    s32 TryStartDialogSkip();
    s16 framesLeft;

    if (TryStartDialogSkip() != 0) {
        Sprite_ResumeAnimation(sprite);
        return;
    }
    framesLeft = M2C_FIELD(sprite, s16 *, SCRIPT_WAIT_FRAMES);
    M2C_FIELD(sprite, s16 *, SCRIPT_WAIT_FRAMES) = (s16) (framesLeft - 1);
    if (framesLeft != 0) {
        return;
    }
    Sprite_ResumeAnimation(sprite);
}

/* Create the scene-script wait sprite (class gScriptWaitSpriteClass) with a frame
 * countdown of `frames`; the sprite resumes the script when it reaches 0. */
void CreateScriptWaitSprite(s16 frames) {
    extern M2C_UNK gScriptWaitSpriteClass;
    M2C_FIELD(CreateSpriteFromClass(&gScriptWaitSpriteClass, 7), s16 *, SCRIPT_WAIT_FRAMES) = frames;
}

/* TRUE while a scene-script wait sprite (gScriptWaitSpriteClass) is on screen. */
u8 IsScriptWaitSpriteActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gScriptWaitSpriteClass;
    u8 active;

    if (FindObjectByClass(&gScriptWaitSpriteClass) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

void func_02095490(void *arg0) {
    u8 Get3DSpriteScreenMode(s32);
    s32 GetOther3DSpriteScreenMode(s32);
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain, gCur3DSpriteEngine;
    unsigned int saved;
    register u8 mode;
    s32 i;
    long engine;
    u8 type;
    u16 *volatile sp4C;
    u16 *volatile sp48;
    u16 *volatile sp44;
    u16 *volatile sp40;
    u16 *volatile sp3C;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;

    mode = Get3DSpriteScreenMode(M2C_FIELD(arg0, s32 *, 0x5C));
    type = (u8)GetOther3DSpriteScreenMode(M2C_FIELD(arg0, s32 *, 0x5C));
    saved = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) engine = g3DSpriteEngineMain; else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        {
            unsigned screen = M2C_FIELD(arg0, s32 *, 0x5C);
            if (screen == 0 && engine != g3DSpriteEngineMain) goto end;
            if (screen == 1 && engine != g3DSpriteEngineSub) goto end;
            if (screen == 3 && engine != saved) goto end;
        }
        switch (mode) {
        case 0:
            sp4C = *(u16 **)(engine);
            *sp4C = (u16)(*sp4C | 0x10);
            break;
        case 1:
            sp48 = *(u16 **)(engine);
            *sp48 = (u16)(*sp48 | 0x20);
            break;
        case 2:
            sp44 = *(u16 **)(engine);
            *sp44 = (u16)(*sp44 | 0x40);
            break;
        case 3:
            sp40 = *(u16 **)(engine);
            *sp40 = (u16)(*sp40 | 0x80);
            break;
        case 4:
            sp3C = *(u16 **)(engine);
            *sp3C = (u16)(*sp3C | 0x100);
            break;
        }
        switch (type) {
        case 0:
            sp38 = *(u16 **)gCur3DSpriteEngine;
            *sp38 = (u16)(*sp38 | 0x10);
            break;
        case 1:
            sp34 = *(u16 **)gCur3DSpriteEngine;
            *sp34 = (u16)(*sp34 | 0x20);
            break;
        case 2:
            sp30 = *(u16 **)gCur3DSpriteEngine;
            *sp30 = (u16)(*sp30 | 0x40);
            break;
        case 3:
            sp2C = *(u16 **)gCur3DSpriteEngine;
            *sp2C = (u16)(*sp2C | 0x80);
            break;
        case 4:
            sp28 = *(u16 **)gCur3DSpriteEngine;
            *sp28 = (u16)(*sp28 | 0x100);
            break;
        }
        sp24 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp24 = (u16)(*sp24 & ~1);
        sp20 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp20 = (u16)(*sp20 & ~2);
        sp1C = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp1C = (u16)(*sp1C | 4);
        sp18 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp18 = (u16)(*sp18 & ~8);
        sp14 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp14 = (u16)(*sp14 & ~0x10);
        sp10 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp10 = (u16)(*sp10 & ~0x100);
        spC = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *spC = (u16)(*spC & ~0x200);
        sp8 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp8 = (u16)(*sp8 & ~0x400);
        sp4 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp4 = (u16)(*sp4 | 0x800);
        sp0 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp0 = (u16)(*sp0 & ~0x1000);
        ++i;
    } while (i < 2);

end:
    gCur3DSpriteEngine = saved;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
}

#pragma push
void func_0209583c(void *arg0){
u8 Get3DSpriteScreenMode(s32);s32 GetOther3DSpriteScreenMode(s32);
M2C_UNK StoreOtherScreenMode(s32);
extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub,g3DSpriteEngineMain;
s32 old,newv;s32 saved,engine;s32 i;
old=Get3DSpriteScreenMode(M2C_FIELD(arg0,s32 *,0x5c));
newv=GetOther3DSpriteScreenMode(M2C_FIELD(arg0,s32 *,0x5c));
saved=gCur3DSpriteEngine;old=(u8)old;newv=(u8)newv;
for(i=0;i<2;i++){
if(i==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
if(M2C_FIELD(arg0,s32 *,0x5c)==0 && engine!=g3DSpriteEngineMain)continue;
if(M2C_FIELD(arg0,s32 *,0x5c)==1 && engine!=g3DSpriteEngineSub)continue;
if(M2C_FIELD(arg0,s32 *,0x5c)==3 && engine!=saved)continue;
switch((u8)old){case 0:{u16 *volatile p=*(u16 **)engine;*p=*p&~16;break;}
case 1:{u16 *volatile p=*(u16 **)engine;*p=*p&~32;break;}
case 2:{u16 *volatile p=*(u16 **)engine;*p=*p&~64;break;}
case 3:{u16 *volatile p=*(u16 **)engine;*p=*p&~128;break;}
case 4:{u16 *volatile p=*(u16 **)engine;*p=*p&~256;break;}}
switch((u8)newv){case 0:{u16 *volatile p=*(u16 **)gCur3DSpriteEngine;*p=*p|16;break;}
case 1:{u16 *volatile p=*(u16 **)gCur3DSpriteEngine;*p=*p|32;break;}
case 2:{u16 *volatile p=*(u16 **)gCur3DSpriteEngine;*p=*p|64;break;}
case 3:{u16 *volatile p=*(u16 **)gCur3DSpriteEngine;*p=*p|128;break;}
case 4:{u16 *volatile p=*(u16 **)gCur3DSpriteEngine;*p=*p|256;break;}}
{u16 *volatile p=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*p=*p&~0xc0;}
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
}
gCur3DSpriteEngine=saved;
StoreOtherScreenMode(M2C_FIELD(arg0,s32 *,0x5c));
}
#pragma pop
/* Advances a 3D sprite screen split by one frame: eases the two halves apart,
 * writes the split rows into the engine's bank for every screen the object
 * affects, and deletes the object once the split has run its full length. */
void Update3DSpriteSplit(DS3DSpriteSplit *split) {
    u8 Get3DSpriteScreenMode(s32);
    s32 GetOther3DSpriteScreenMode(s32);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void DeleteSpriteObject(void *);
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
    u16 *volatile attrA;
    u16 *volatile attrB;
    s32 mode, screen;
    u32 topRows;
    u8 bottomRows;
    s32 saved, engine;
    s32 i;

    mode = Get3DSpriteScreenMode(split->screen);
    GetOther3DSpriteScreenMode(split->screen);
    split->elapsed++;
    bottomRows = EaseInterpolate(0, 0, 16, split->elapsed, split->length);
    saved = gCur3DSpriteEngine;
    topRows = 16 - bottomRows;
    i = 0;
    do {
        if (i == 0) engine = g3DSpriteEngineMain; else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        screen = split->screen;
        if (screen == 0 && engine != g3DSpriteEngineMain) goto next;
        if (screen == 1 && engine != g3DSpriteEngineSub) goto next;
        if (screen == 3 && engine != saved) goto next;
        switch (mode) {
        case 2:
            attrA = (u16 *)(*(u8 **)engine + 18);
            *attrA = (*attrA & ~0xC0) | 0x40;
            ((DS3DSpriteBank *)(*(void **)gCur3DSpriteEngine))->rowsAbove = topRows;
            ((DS3DSpriteBank *)(*(void **)gCur3DSpriteEngine))->rowsBelow = bottomRows;
            break;
        case 3:
            attrB = (u16 *)(*(u8 **)engine + 18);
            *attrB = (*attrB & ~0xC0) | 0x40;
            ((DS3DSpriteBank *)(*(void **)gCur3DSpriteEngine))->rowsAbove = bottomRows;
            ((DS3DSpriteBank *)(*(void **)gCur3DSpriteEngine))->rowsBelow = topRows;
            break;
        }
next:
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
    if (split->elapsed < split->length) return;
    DeleteSpriteObject(split);
}

/* Creates the 3D sprite that splits the 3D-sprite screen `screen` (0 main, 1 sub,
 * 3 the active one) in two over `length` frames; the sprite is owned by `owner`
 * (a parent sprite or a layer index).  Nothing is created while a message box is up. */
void CreateScreenSplitSprite(s32 screen, s32 length, M2C_UNK owner) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gScreenSplitClass;
    DS3DSpriteSplit *split;

    if (IsMessageBoxActive() != 0) {
        return;
    }
    split = CreateSpriteObject(&gScreenSplitClass, owner);
    split->screen = screen;
    split->length = length;
}

