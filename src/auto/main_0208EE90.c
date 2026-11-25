/* 55 functions from 0x0208EE90 to 0x0208FE7C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "sound.h"
extern M2C_UNK gSoundTimerState;
extern u32 gSoundTimerTicks[9], gSoundTimerElapsed[9];

#pragma push
#pragma optimization_level 3
M2C_UNK func_0208ee90(void *p) {
    void AddSprite(u16,u16,u16,void *,s32);
    M2C_UNK Sprite_ResumeAnimation(void *);
    extern u16 *gKeyState;
    extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain, **g3DSpriteEngineSub;
    extern u8 gSpriteDesc8x8[];
    s32 j, index, screen;
s32 drawCount;
    s64 value, delta;
    register void **saved;
    u16 x, attr, priority;
    u32 y;
    s32 mode;
    if(gKeyState[1]&16) {
        if(M2C_FIELD(p,s32 *,0x58)==0) {
            if(gKeyState[0]&16) M2C_FIELD(p,s32 *,0x58)=M2C_FIELD(p,s32 *,0x5c)-1;
        } else M2C_FIELD(p,s32 *,0x58)--;
    }
    if(gKeyState[1]&32) {
        if(M2C_FIELD(p,s32 *,0x58)==M2C_FIELD(p,s32 *,0x5c)-1) {
            if(gKeyState[0]&32) M2C_FIELD(p,s32 *,0x58)=0;
        } else M2C_FIELD(p,s32 *,0x58)++;
    }
    if(gKeyState[1]&64) { s64 value;
        index=M2C_FIELD(p,s32 *,0x58);
        value=M2C_FIELD(p,s64 *,0x60);
        for(j=index;j!=0;j--) value/=10;
        if(value%10==9) delta=-9;else delta=1;
        for(;j!=index;j++) delta*=10;
        M2C_FIELD(p,s64 *,0x60)+=delta;
    }
    if(gKeyState[1]&128) { s64 value;
        index=M2C_FIELD(p,s32 *,0x58);
        value=M2C_FIELD(p,s64 *,0x60);
        for(j=index;j!=0;j--) value/=10;
        if(value%10==0) delta=9;else delta=-1;
        for(;j!=index;j++) delta*=10;
        M2C_FIELD(p,s64 *,0x60)+=delta;
    }
    saved=gCur3DSpriteEngine;
    for(screen=0;screen<2;screen++) {
        gCur3DSpriteEngine=screen==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
        mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
        if(mode==0 && gCur3DSpriteEngine!=g3DSpriteEngineMain) continue;
        if(mode==1 && gCur3DSpriteEngine!=g3DSpriteEngineSub) continue;
        if(mode==3 && gCur3DSpriteEngine!=saved) continue;
        x=(M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38))&511;
        y=(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255;
        priority=(u32)(M2C_FIELD(p,u32 *,0x40)<<6)>>24;
        attr=M2C_FIELD(p,u16 *,0x3c)|((M2C_FIELD(p,u16 *,0x3e)>>((u32)(M2C_FIELD(*gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)|(priority<<12);
        drawCount=M2C_FIELD(p,s32 *,0x5c);
        value=M2C_FIELD(p,s64 *,0x60);
        priority=M2C_FIELD(p,u8 *,0x49);
        AddSprite((u16)(x-M2C_FIELD(p,s32 *,0x58)*8),(u16)(y-8),(u16)(attr+((24>>((u32)(M2C_FIELD(*gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),gSpriteDesc8x8,priority);
        AddSprite((u16)(x-M2C_FIELD(p,s32 *,0x58)*8),(u16)(y+8),(u16)(attr+((56>>((u32)(M2C_FIELD(*gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),gSpriteDesc8x8,priority);
        for(;drawCount>0;drawCount--) {
            AddSprite(x,y,(u16)(attr+(((value%10*2)>>((u32)(M2C_FIELD(*gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),gSpriteDesc8x8,priority);
            x-=8;
            value/=10;
        }
    }
    gCur3DSpriteEngine=saved;
    if(gKeyState[0]&1)Sprite_ResumeAnimation(p);
}
#pragma pop
void func_0208f3a4(void) {
    M2C_UNK func_0208ee90();
    func_0208ee90();
}

void CreateNumberDisplay(M2C_UNK arg0) {
    s32 CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK InitNumberDisplay();
    extern M2C_UNK gNumberDisplayStateClass;
    if (CreateSpriteObject(&gNumberDisplayStateClass, arg0) == 0) {
        return;
    }
    InitNumberDisplay();
}

void func_0208f3d4(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r0 > 0) {
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) (temp_r0 - 1);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x34)();
    Sprite_ResumeAnimation(arg0);
}

#pragma opt_common_subs off
u16 Crc16(u8 *arg0, s32 arg1) {
    u32 crc = 0;
    u32 byte;
    s32 i;
    u32 poly;

    if (arg1 > 0) {
        poly = 0x18003;
        do {
            byte = *arg0;
            i = 0;
            do {
                crc = crc << 1;
                if (crc & 0x10000) {
                    crc = crc << 16;
                    crc = poly ^ (crc >> 16);
                }
                byte = byte << 17;
                crc = crc << 16;
                byte = byte >> 16;
                crc = crc >> 16;
                if (byte & 0x100) {
                    crc = crc ^ 1;
                }
                i = i + 1;
            } while (i < 8);
            arg1 = arg1 - 1;
            arg0 = arg0 + 1;
        } while (arg1 > 0);
    }
    return (u16)crc;
}
#pragma opt_common_subs reset
void func_0208f478(void) {

}

s32 func_0208f47c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_0208f490(void) {

}

s32 func_0208f494(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_0208f4a8(void) {

}

s32 func_0208f4ac(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_0208f4c0(void) {

}

s32 func_0208f4c4(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_0208f4d8(void) {
    s32 GetSystemTick();
    extern M2C_UNK gSoundTimerState;
    M2C_FIELD(&gSoundTimerState, s32 *, 4) = GetSystemTick();
}

/* End-of-frame sound driver tick: measures the system ticks elapsed since the
 * frame start and converts that, plus the pending per-slot tick counts, to the
 * sound engine's time base (1000 / TICKS_TO_MS_DIVISOR per tick). */
void SoundEngineUpdateTimers(void) {
    s32 GetSystemTick(void);
    u64 U64Divide(u64, u64);
    s32 i;
    u32 elapsed;

    elapsed = GetSystemTick() - M2C_FIELD(&gSoundTimerState, u32 *, 4);
    M2C_FIELD(&gSoundTimerState, u32 *, 4) = elapsed;
    M2C_FIELD(&gSoundTimerState, u32 *, 0x28) = U64Divide((u64)elapsed * 64000, TICKS_TO_MS_DIVISOR);
    for (i = 0; i < 3; i++) {
        gSoundTimerElapsed[i + 1] = U64Divide((u64)gSoundTimerTicks[i + 1] * 64000, TICKS_TO_MS_DIVISOR);
        gSoundTimerTicks[i + 1] = 0;
    }
    M2C_FIELD(&gSoundTimerState, u32 *, 0x38) = U64Divide((u64)M2C_FIELD(&gSoundTimerState, u32 *, 0x14) * 64000, TICKS_TO_MS_DIVISOR);
}

void func_0208f5cc(void) {
    M2C_UNK FadeOutMusicDefault();
    FadeOutMusicDefault();
}

void func_0208f5d8(void) {
    PlayMusicTrack(4);
}

/* The console's language as an index the front end supports: the six localized
 * languages map to themselves, anything else (unset or Korean) falls back to
 * English. */
s32 GetLanguageIndex(void) {
    u32 GetLanguage();
    u32 language;

    language = GetLanguage();
    switch (language) {
    case LANGUAGE_UNSET:
        return LANGUAGE_UNSET;
    case LANGUAGE_ENGLISH:
        return LANGUAGE_ENGLISH;
    case LANGUAGE_FRENCH:
        return LANGUAGE_FRENCH;
    case LANGUAGE_GERMAN:
        return LANGUAGE_GERMAN;
    case LANGUAGE_ITALIAN:
        return LANGUAGE_ITALIAN;
    case LANGUAGE_SPANISH:
        return LANGUAGE_SPANISH;
    default:
        return LANGUAGE_ENGLISH;
    }
}

/* Runs the ov001 front end (title and menu screens): shuts down the FIFO
 * receive handler, the IRQ mask, VBlank interrupts and the sound engine, loads
 * resource set 2, then runs the overlay with the console's language on a
 * temporary work buffer.  Afterwards it restores the handlers and interrupts,
 * resets the sound engine and turns the display back on. */
void RunFrontEndOverlay(void) {
s32 OS_GetIrqHandler(s32);
void OS_SetIrqHandler(s32,s32);
void OS_DisableIrqMask(s32);
void GX_SetVBlankIrq(s32);
void ShutdownSound(void);
void func_02088724(void);
void SetNasServerEnvironment(s32);
void *func_020e3580(s32,s32);
void Ov001_RunFrontEnd(void *,s32,s32);
M2C_UNK HeapFreeBlock();
void func_0208859c(void);
void func_02088634(void);
void InitSound(void);
void OS_EnableIrqMask(s32);
void func_02007598(void);
void GX_TurnOnDisplay(void);
s32 savedFifoHandler;void *workBuffer;u16 imeState;
savedFifoHandler=OS_GetIrqHandler(1);
OS_SetIrqHandler(1,0);
OS_DisableIrqMask(1);
GX_SetVBlankIrq(0);
ShutdownSound();
func_02088724();
SetNasServerEnvironment(2);
workBuffer=func_020e3580(0x40000,0x20);
if(GetLanguageIndex()==0) Ov001_RunFrontEnd(workBuffer,GetLanguageIndex(),0x10);
else Ov001_RunFrontEnd(workBuffer,GetLanguageIndex(),0);
HeapFreeBlock(workBuffer);
func_0208859c();
func_02088634();
InitSound();
OS_SetIrqHandler(1,savedFifoHandler);
OS_EnableIrqMask(1);
imeState=*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=1;
GX_SetVBlankIrq(1);
func_02007598();
GX_TurnOnDisplay();
*(volatile u32 *)0x4001000 |= 0x10000;
}

void func_0208f730(M2C_UNK arg0) {
    extern M2C_UNK data_021028c4;
    extern M2C_UNK data_021028d0;
    M2C_UNK **temp_r0;

    temp_r0 = CreateSpriteObject(&data_021028d0, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_021028c4;
    }
}

void func_0208f758(void) {

}

s32 func_0208f75c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

s32 GetCurrentMusicTrack(void) {
    extern s32 gCurrentMusicTrack;
    return gCurrentMusicTrack;
}

/* Switch the running music to `track`: unless it is already playing, cancel any
 * pending fades, start the track, remember it, and mark its records-menu entry as
 * heard. */
s32 PlayMusicTrack(s32 track) {
    extern s32 gCurrentMusicTrack;
    void StopMusicAndFades(void);
    void StartMusicTrack(s32);
    s32 RecordsMenu_FindTrackIndex(s32);
    void MarkRecordsMusicEntryHeard(s32);
    s32 current = gCurrentMusicTrack;

    if (current == track) return current;
    StopMusicAndFades();
    StartMusicTrack(track);
    gCurrentMusicTrack = track;
    MarkRecordsMusicEntryHeard(RecordsMenu_FindTrackIndex(track));
}

void func_0208f7c0(void *arg0) {
    PlayMusicTrack(M2C_FIELD(arg0, s32 *, 0x5C));
}

void ChangeMusicTrackWithFade(s32 arg0) {
    M2C_UNK FadeOutMusicDefault();
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    extern s32 gCurrentMusicTrack;
    extern M2C_UNK gMusicPlayAfterFadeClass;
    if (gCurrentMusicTrack == arg0) {
        return;
    }
    FadeOutMusicDefault();
    M2C_FIELD(CreateSpriteFromClass(&gMusicPlayAfterFadeClass, 7), s32 *, 0x5C) = arg0;
}

void func_0208f808(void) {
    extern s32 gCurrentMusicTrack;
    gCurrentMusicTrack = 0xffff;
}

void func_0208f820(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_FIELD(arg0, s16 *, 0x6C)--;
    if (M2C_FIELD(arg0, s16 *, 0x6C) != 0) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

/* Fade the running music out over `frames` frames (0 means one frame) by
 * spawning the fade-out timer object; does nothing when music is stopped. */
void FadeOutMusicOverFrames(s32 frames) {
    void FadeOutMusic(s32);
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    extern s32 gCurrentMusicTrack;
    extern M2C_UNK gMusicFadeOutClass;

    if (gCurrentMusicTrack == MUSIC_NONE) {
        return;
    }
    if (frames == 0) {
        frames = 1;
    }
    FadeOutMusic(frames);
    M2C_FIELD(CreateSpriteFromClass(&gMusicFadeOutClass, 7), s16 *, MUSIC_FADE_FRAMES) = (s16)frames;
}

M2C_UNK FadeOutMusicDefault(void) {
    void FadeOutMusicOverFrames(s32);
    FadeOutMusicOverFrames(0x1E);
}

u8 IsMusicFadingOut(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gMusicFadeOutClass;
    u8 var_r0;

    if (FindObjectByClass(&gMusicFadeOutClass) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void FadeMusicToHalfVolume(void) {
    M2C_UNK func_0208f8ec(M2C_UNK, M2C_UNK);
    func_0208f8ec(0x40, 0x1E);
}

void FadeMusicToFullVolume(void) {
    func_0208f8ec(0x7F, 0x1E);
}

s32 func_0208f8ec(s32 a,s32 b){s32 Sound_FadeVolume(s32,s32,s32);return Sound_FadeVolume(-1,a,b);}

/* Stop all music: delete the pending fade-out and play-after-fade sprite objects,
 * cut the current track and mark that no track is playing. */
void StopMusicAndFades(void){
 M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK*);
 void FadeOutMusic(s32);
 extern M2C_UNK gMusicFadeOutClass,gMusicPlayAfterFadeClass;
 extern s32 gCurrentMusicTrack;
 DeleteSpriteObjectsOfClass(&gMusicFadeOutClass);DeleteSpriteObjectsOfClass(&gMusicPlayAfterFadeClass);
 FadeOutMusic(0);gCurrentMusicTrack=MUSIC_NONE;
}

void func_0208f940(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
}

/* Update the delayed one-shot sound-effect sprite: count the elapsed frames and,
 * once SOUND_EFFECT_DELAY is reached, play SOUND_EFFECT_ID at SOUND_EFFECT_VOLUME,
 * pan it by SOUND_EFFECT_PAN and delete the sprite. */
void UpdateDelayedSoundEffect(void *sprite) {
    M2C_UNK DeleteSpriteObject(void *);
    s16 elapsed;
    s32 pan;

    elapsed = M2C_FIELD(sprite, s16 *, SOUND_EFFECT_ELAPSED);
    M2C_FIELD(sprite, s16 *, SOUND_EFFECT_ELAPSED) = (s16) (elapsed + 1);
    if ((s32) elapsed < (s32) M2C_FIELD(sprite, s16 *, SOUND_EFFECT_DELAY)) {
        return;
    }
    pan = M2C_FIELD(sprite, s32 *, SOUND_EFFECT_PAN);
    if (Sound_PlayEffectAtVolume(M2C_FIELD(sprite, s32 *, SOUND_EFFECT_ID), M2C_FIELD(sprite, s32 *, SOUND_EFFECT_VOLUME)) != 0) {
        SetSoundEffectPan(pan);
    }
    DeleteSpriteObject(sprite);
}

/* Spawn a delayed one-shot sound effect that plays `soundId` at maximum volume,
 * centered, after `delay` frames. */
void SpawnSoundEffectFullVolume(s32 soundId, s16 delay) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gDelayedSoundEffectClass;
    void *sprite;

    sprite = CreateSpriteFromClass(&gDelayedSoundEffectClass, 7);
    M2C_FIELD(sprite, s32 *, SOUND_EFFECT_ID) = soundId;
    M2C_FIELD(sprite, s32 *, SOUND_EFFECT_VOLUME) = SOUND_VOLUME_MAX;
    M2C_FIELD(sprite, s32 *, SOUND_EFFECT_PAN) = 0;
    M2C_FIELD(sprite, s16 *, SOUND_EFFECT_DELAY) = delay;
}

void func_0208f9d0(void *a){
 u64 U32DivideRem(s32,s16);
 s32 PlaySoundEffect(s32);
 extern s32 gFrameCounter;
 if((u32)(U32DivideRem(gFrameCounter,M2C_FIELD(a,s16*,0x52))>>32)!=0)return;
 PlaySoundEffect(M2C_FIELD(a,s32*,0x5c));
}

void StartLoopingSoundEffect(s32 a,s32 b){
 void *CreateSpriteFromClass(M2C_UNK*,M2C_UNK);
 extern M2C_UNK gLoopingSoundEffectClass;
 void *p=CreateSpriteFromClass(&gLoopingSoundEffectClass,7);
 M2C_FIELD(p,s32*,0x5c)=a;M2C_FIELD(p,s16*,0x52)=b;
}

void StopLoopingSoundEffects(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gLoopingSoundEffectClass;
    DeleteSpriteObjectsOfClass(&gLoopingSoundEffectClass);
}

/* Volume map sound effects play at: reduced while the view is zoomed out (small
 * cells), full while it is zoomed in. */
s32 GetSoundEffectVolume(void) {
    s32 GetViewZoom(s32);
    extern s32 *gCurrentMap;
    s32 cellSize;

    if (GetViewZoom(*gCurrentMap + MAP_VIEW_ZOOM) <= 0) {
        cellSize = MAP_SPRITE_ZOOM_SMALL;
    } else {
        cellSize = MAP_SPRITE_ZOOM_LARGE;
    }
    if (cellSize == MAP_SPRITE_ZOOM_SMALL) {
        return SOUND_EFFECT_VOLUME_FAR;
    }
    return SOUND_EFFECT_VOLUME_NEAR;
}

/* Stereo pan (-32..32) for a sound played at map tile (tileX, tileY): based on
 * the tile's screen x, clamped at the screen edges and eased across its width. */
s32 MapTileToSoundPan(s32 tileX,s32 tileY){
 void MapTileToScreen(s32,s32,s32*);
 s32 EaseInterpolate(s32,s32,s32,s32,s32);
 s32 screen[3];
 MapTileToScreen(tileX,tileY,screen);
 if(screen[0]<0)return -32;
 if(screen[0]>256)return 32;
 return EaseInterpolate(0,-32,32,screen[0],256);
}

void func_0208facc(M2C_UNK arg0) {
    s32 GetSoundEffectVolume();
    M2C_UNK Sound_PlayEffectAtVolume(M2C_UNK, s32);
    Sound_PlayEffectAtVolume(arg0, GetSoundEffectVolume());
}

void PlaySoundEffectOnChannel0(M2C_UNK arg0) {
    M2C_UNK PlaySlotScriptedSoundAtVolume(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    PlaySlotScriptedSoundAtVolume(0, -1, arg0, GetSoundEffectVolume());
}

/* Play sound effect soundId at the current zoom-based volume and pan it by the
 * map tile (tileX, tileY) it plays at. */
void PlaySoundAtTile(s32 soundId, s32 tileX, s32 tileY) {
    s32 MapTileToSoundPan(s32, s32);
    s32 Sound_PlayEffectAtVolume(s32, s32);
    s32 SetSoundEffectPan(s32);
    s32 volume;
    s32 pan;

    volume = GetSoundEffectVolume();
    pan = MapTileToSoundPan(tileX, tileY);
    if (Sound_PlayEffectAtVolume(soundId, volume) == 0) {
        return;
    }
    SetSoundEffectPan(pan);
}

/* Spawn a delayed one-shot sound effect: record the effect id, the current
 * zoom-based volume, the stereo pan of the tile it plays at and the delay. */
void SpawnSoundEffectAtTile(s32 soundId, s32 tileX, s32 tileY, s32 delay) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gDelayedSoundEffectClass;
    void *sprite = CreateSpriteFromClass(&gDelayedSoundEffectClass, 7);
    M2C_FIELD(sprite, s32 *, SOUND_EFFECT_ID) = soundId;
    M2C_FIELD(sprite, s32 *, SOUND_EFFECT_VOLUME) = GetSoundEffectVolume();
    M2C_FIELD(sprite, s32 *, SOUND_EFFECT_PAN) = MapTileToSoundPan(tileX, tileY);
    M2C_FIELD(sprite, s16 *, SOUND_EFFECT_DELAY) = delay;
}

#pragma opt_common_subs on
#pragma opt_strength_reduction on
/* Bring the game's sound system up: initialise the SDK sound handles (one per
 * sound slot), clear the driver state (disabled, no sound started this frame,
 * frame counter stamped) and the per-frame played list, then open the sound
 * player and configure it. */
void InitSound(void) {
    void OpenSoundPlayer(void);
    void func_0208fc4c(void);
    extern M2C_UNK gMusicSequencePlayer, gSoundEffectPlayer, gMusicSoundPlayer, gSoundEffectSlotHandles, gSoundDriverState, gSoundFrameIds;
    extern s32 gFrameCounter;
    s32 i;
    u8 *handle;

    InitSoundDriver();
    func_0202acb0(&gMusicSequencePlayer);
    func_0202acb0(&gSoundEffectPlayer);
    func_0202d9c0(&gMusicSoundPlayer);
    for (handle = (u8 *)&gSoundEffectSlotHandles, i = 0; i < SOUND_SLOT_COUNT; i++, handle += 4) {
        func_0202acb0(handle);
    }
    M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) = 0;
    M2C_FIELD(&gSoundDriverState, s32 *, SOUND_STATE_PLAYED_COUNT) = 0;
    M2C_FIELD(&gSoundDriverState, s32 *, SOUND_STATE_FRAME) = gFrameCounter;
    i = 0;
    do {
        ((volatile s32 *)&gSoundFrameIds)[i] = 0;
        ++i;
    } while (i < SOUND_PLAYED_MAX);
    OpenSoundPlayer();
    func_0208fc4c();
    func_020903d4();
    func_0208fc4c();
    Sound_InitVolumes();
    func_020903b0();
}
void func_0208fc4c(void) {

}

/* Bring the sound player up: take the driver's heap from the game heap, create
 * the driver's own sound heap inside it, open the sound archive into that heap,
 * initialise the archive's channels and the sound worker, then mark the driver
 * enabled and apply its settings. */
void OpenSoundPlayer(void){
 s32 HeapAllocBlockTail(s32);s32 Sound_CreateHeap(s32,s32);
 extern M2C_UNK gSoundDriverState,gSoundArchive,gSoundArchivePath;
 s32 player;
 if(M2C_FIELD(&gSoundDriverState,u8*,SOUND_STATE_ENABLED))return;
 if(!M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_HEAP))M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_HEAP)=HeapAllocBlockTail(SOUND_HEAP_BYTES);
 player=Sound_CreateHeap(M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_HEAP),SOUND_HEAP_BYTES);
 M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYER)=player;
 Sound_OpenArchive(&gSoundArchive,&gSoundArchivePath,player,0);
 Sound_InitArchiveChannels(M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYER));
 Sound_StartWorker(SOUND_WORKER_PRIORITY,M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYER));
 M2C_FIELD(&gSoundDriverState,u8*,SOUND_STATE_ENABLED)=1;func_020903b0();
}

/* Shut the game's sound system down: reset the sound engine, destroy the driver's
   sound heap and, when the raw heap block is still allocated, release it and
   clear the state. */
void ShutdownSound(void) {
    M2C_UNK Sound_FadeOutAllVoices(M2C_UNK);
    M2C_UNK Sound_DestroyHeap(s32);
    M2C_UNK HeapFreeBlock();
    extern M2C_UNK gSoundDriverState;
    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return;
    }
    Sound_FadeOutAllVoices(0);
    Sound_DestroyHeap(M2C_FIELD(&gSoundDriverState, s32 *, SOUND_STATE_HEAP));
    M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) = 0U;
    if (M2C_FIELD(&gSoundDriverState, s32 *, SOUND_STATE_HEAP) == 0) {
        return;
    }
    HeapFreeBlock();
    M2C_FIELD(&gSoundDriverState, s32 *, SOUND_STATE_HEAP) = 0;
}

/* Play a sound effect from a packed id: the high 16 bits name the archive the
 * sound comes from (0 for a plain sequence), the low 16 bits the sequence or
 * archive entry. */
void Sound_PlayPackedId(M2C_UNK *player,s32 channel,u32 packedId){
 u32 archiveId=(packedId&0xffff0000)>>16;u32 soundId=(u16)packedId;
 if(archiveId){Sound_PlayArchiveEntry(player,channel,-1,-1,archiveId,soundId);return;}
 Sound_PlaySequence(player,channel,-1,-1,soundId);
}

void Sound_StopPlayerVoice(void) {
    M2C_UNK func_0202ac60();
    func_0202ac60();
}

#pragma opt_strength_reduction off
/* Claims one of the SOUND_PLAYED_MAX per-frame sound-id slots for `soundId`:
 * returns 1 and remembers the id when it has not been started yet this frame, 0
 * when it already has.  A frame change clears the list first. */
s32 Sound_ClaimPlaySlot(s32 soundId) {
extern M2C_UNK gSoundDriverState; extern s32 gFrameCounter; extern M2C_UNK gSoundFrameIds;
u32 i,count;
if(M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_FRAME)!=gFrameCounter){
M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYED_COUNT)=0;
M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_FRAME)=gFrameCounter;
}
count=M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYED_COUNT);
for(i=0;i<count;i++){if(soundId==M2C_FIELD(&gSoundFrameIds,s32*,i<<2))return 0;}
if(count<SOUND_PLAYED_MAX){
u32 next = M2C_FIELD(&gSoundDriverState,volatile u32*,SOUND_STATE_PLAYED_COUNT)+1;
M2C_FIELD(&gSoundFrameIds,s32*,count<<2)=soundId;
M2C_FIELD(&gSoundDriverState,u32*,SOUND_STATE_PLAYED_COUNT)=next;
} return 1;
}
/* Plays packed sound `soundId` on the sound-effect player, at most once per
 * frame: returns 0 while the sound system is off or the sound was already
 * started this frame, 1 once it was handed to the driver. */
s32 PlaySoundEffect(s32 soundId) {
    s32 Sound_ClaimPlaySlot(s32);
    void Sound_PlayPackedId(M2C_UNK *, s32, u32);
    extern M2C_UNK gSoundDriverState, gSoundEffectPlayer;
    u8 enabled = M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED);

    if (enabled == 0) {
        return 0;
    }
    if (!Sound_ClaimPlaySlot(soundId)) {
        return 0;
    }
    Sound_PlayPackedId(&gSoundEffectPlayer, -1, soundId);
    return 1;
}

