/* 55 functions from 0x0208EE90 to 0x0208FE7C (main), found by ds-decomp. */
#include "common.h"
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
    M2C_UNK func_0208f890();
    func_0208f890();
}

void func_0208f5d8(void) {
    PlayMusicTrack(4);
}

s32 GetLanguageIndex(void) {
    u32 GetLanguage();
    u32 temp_r0;

    temp_r0 = GetLanguage();
    switch (temp_r0) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        return 1;
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
void func_0208fce8(void);
void func_02088724(void);
void func_02037854(s32);
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
func_0208fce8();
func_02088724();
func_02037854(2);
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

s32 func_0208f770(void) {
    extern s32 data_02102910;
    return data_02102910;
}

M2C_UNK PlayMusicTrack(s32 arg0) {
extern s32 data_02102910;
void func_0208f904(void);
void func_020901e0(s32);
void func_020ad594(s32);
void func_020ad640(void);
s32 current=data_02102910;
if(current==arg0) return current;
func_0208f904();
func_020901e0(arg0);
data_02102910=arg0;
func_020ad594(arg0);
func_020ad640();
}

void func_0208f7c0(void *arg0) {
    PlayMusicTrack(M2C_FIELD(arg0, s32 *, 0x5C));
}

void func_0208f7d0(s32 arg0) {
    M2C_UNK func_0208f890();
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    extern s32 data_02102910;
    extern M2C_UNK data_0210295c;
    if (data_02102910 == arg0) {
        return;
    }
    func_0208f890();
    M2C_FIELD(CreateSpriteFromClass(&data_0210295c, 7), s32 *, 0x5C) = arg0;
}

void func_0208f808(void) {
    extern s32 data_02102910;
    data_02102910 = 0xffff;
}

void func_0208f820(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_FIELD(arg0, s16 *, 0x6C)--;
    if (M2C_FIELD(arg0, s16 *, 0x6C) != 0) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

void func_0208f844(s32 arg0) {
    void func_02090248(s32);
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    extern s32 data_02102910;
    extern M2C_UNK data_02102934;
    if (data_02102910 == 0xFFFF) {
        return;
    }
    if (arg0 == 0) {
        arg0 = 1;
    }
    func_02090248(arg0);
    M2C_FIELD(CreateSpriteFromClass(&data_02102934, 7), s16 *, 0x6C) = (s16)arg0;
}

M2C_UNK func_0208f890(void) {
    void func_0208f844(s32);
    func_0208f844(0x1E);
}

u8 func_0208f8a0(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02102934;
    u8 var_r0;

    if (FindObjectByClass(&data_02102934) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0208f8c4(void) {
    M2C_UNK func_0208f8ec(M2C_UNK, M2C_UNK);
    func_0208f8ec(0x40, 0x1E);
}

void func_0208f8d8(void) {
    func_0208f8ec(0x7F, 0x1E);
}

s32 func_0208f8ec(s32 a,s32 b){s32 Sound_FadeVolume(s32,s32,s32);return Sound_FadeVolume(-1,a,b);}

void func_0208f904(void){
 M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK*);
 void func_02090248(s32);
 extern M2C_UNK data_02102934,data_0210295c;
 extern s32 data_02102910;
 DeleteSpriteObjectsOfClass(&data_02102934);DeleteSpriteObjectsOfClass(&data_0210295c);
 func_02090248(0);data_02102910=0xffff;
}

void func_0208f940(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
}

void func_0208f94c(void *arg0) {
    M2C_UNK DeleteSpriteObject(void *);
    s16 temp_r1;
    s32 temp_r4;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x54);
    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (temp_r1 + 1);
    if ((s32) temp_r1 < (s32) M2C_FIELD(arg0, s16 *, 0x52)) {
        return;
    }
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x64);
    if (func_0208fe7c(M2C_FIELD(arg0, s32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x60)) != 0) {
        SetSoundEffectVolume(temp_r4);
    }
    DeleteSpriteObject(arg0);
}

void func_0208f998(s32 arg0, s16 arg1) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102984;
    void *temp_r0;

    temp_r0 = CreateSpriteFromClass(&data_02102984, 7);
    M2C_FIELD(temp_r0, s32 *, 0x5C) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x60) = 0x7F;
    M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x52) = arg1;
}

void func_0208f9d0(void *a){
 u64 U32DivideRem(s32,s16);
 s32 PlaySoundEffect(s32);
 extern s32 gFrameCounter;
 if((u32)(U32DivideRem(gFrameCounter,M2C_FIELD(a,s16*,0x52))>>32)!=0)return;
 PlaySoundEffect(M2C_FIELD(a,s32*,0x5c));
}

void func_0208fa00(s32 a,s32 b){
 void *CreateSpriteFromClass(M2C_UNK*,M2C_UNK);
 extern M2C_UNK data_02102914;
 void *p=CreateSpriteFromClass(&data_02102914,7);
 M2C_FIELD(p,s32*,0x5c)=a;M2C_FIELD(p,s16*,0x52)=b;
}

void func_0208fa28(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02102914;
    DeleteSpriteObjectsOfClass(&data_02102914);
}

s32 func_0208fa3c(void) {
    s32 GetViewZoom(s32);
    extern s32 *gCurrentMap;
    s32 var_r0;

    if (GetViewZoom(*gCurrentMap + 0x6EF8) <= 0) {
        var_r0 = 0x10;
    } else {
        var_r0 = 0x18;
    }
    if (var_r0 == 0x10) {
        return 0x5F;
    }
    return 0x7F;
}

s32 func_0208fa78(s32 a,s32 b){
 void MapTileToScreen(s32,s32,s32*);
 s32 EaseInterpolate(s32,s32,s32,s32,s32);
 s32 v[3];
 MapTileToScreen(a,b,v);
 if(v[0]<0)return -32;
 if(v[0]>256)return 32;
 return EaseInterpolate(0,-32,32,v[0],256);
}

void func_0208facc(M2C_UNK arg0) {
    s32 func_0208fa3c();
    M2C_UNK func_0208fe7c(M2C_UNK, s32);
    func_0208fe7c(arg0, func_0208fa3c());
}

void PlaySoundEffectOnChannel0(M2C_UNK arg0) {
    M2C_UNK PlaySlotScriptedSoundAtVolume(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    PlaySlotScriptedSoundAtVolume(0, -1, arg0, func_0208fa3c());
}

void PlaySoundAtTile(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0208fa78(M2C_UNK, M2C_UNK);
    M2C_UNK SetSoundEffectVolume(s32);
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = func_0208fa3c();
    temp_r4 = func_0208fa78(arg1, arg2);
    if (func_0208fe7c(arg0, temp_r5) == 0) {
        return;
    }
    SetSoundEffectVolume(temp_r4);
}

void SpawnSoundEffectAtTile(s32 a,s32 b,s32 c,s32 d){
 void *CreateSpriteFromClass(M2C_UNK*,M2C_UNK);
 extern M2C_UNK data_02102984;
 void *p=CreateSpriteFromClass(&data_02102984,7);
 M2C_FIELD(p,s32*,0x5c)=a;
 M2C_FIELD(p,s32*,0x60)=func_0208fa3c();
 M2C_FIELD(p,s32*,0x64)=func_0208fa78(b,c);
 M2C_FIELD(p,s16*,0x52)=d;
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
    extern M2C_UNK data_0215783c, data_02157834, data_02157838, data_02157850, gSoundDriverState, gSoundFrameIds;
    extern s32 gFrameCounter;
    s32 i;
    u8 *handle;

    InitSoundDriver();
    func_0202acb0(&data_0215783c);
    func_0202acb0(&data_02157834);
    func_0202d9c0(&data_02157838);
    for (handle = (u8 *)&data_02157850, i = 0; i < SOUND_SLOT_COUNT; i++, handle += 4) {
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
    func_02090604();
    func_020903b0();
}
void func_0208fc4c(void) {

}

/* Bring the sound player up: take the driver's heap from the game heap, create
 * the driver's own sound heap inside it, open the sound archive into that heap,
 * initialise the archive's channels and the sound worker, then mark the driver
 * enabled and apply its settings. */
void OpenSoundPlayer(void){
 s32 func_020e34f4(s32);s32 Sound_CreateHeap(s32,s32);
 extern M2C_UNK gSoundDriverState,gSoundArchive,gSoundArchivePath;
 s32 player;
 if(M2C_FIELD(&gSoundDriverState,u8*,SOUND_STATE_ENABLED))return;
 if(!M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_HEAP))M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_HEAP)=func_020e34f4(SOUND_HEAP_BYTES);
 player=Sound_CreateHeap(M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_HEAP),SOUND_HEAP_BYTES);
 M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYER)=player;
 Sound_OpenArchive(&gSoundArchive,&gSoundArchivePath,player,0);
 Sound_InitArchiveChannels(M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYER));
 Sound_StartWorker(SOUND_WORKER_PRIORITY,M2C_FIELD(&gSoundDriverState,s32*,SOUND_STATE_PLAYER));
 M2C_FIELD(&gSoundDriverState,u8*,SOUND_STATE_ENABLED)=1;func_020903b0();
}

void func_0208fce8(void) {
    M2C_UNK func_0202ac70(M2C_UNK);
    M2C_UNK Sound_DestroyHeap(s32);
    M2C_UNK HeapFreeBlock();
    extern M2C_UNK gSoundDriverState;
    if (M2C_FIELD(&gSoundDriverState, u8 *, 0) == 0) {
        return;
    }
    func_0202ac70(0);
    Sound_DestroyHeap(M2C_FIELD(&gSoundDriverState, s32 *, 0x14));
    M2C_FIELD(&gSoundDriverState, u8 *, 0) = 0U;
    if (M2C_FIELD(&gSoundDriverState, s32 *, 0x14) == 0) {
        return;
    }
    HeapFreeBlock();
    M2C_FIELD(&gSoundDriverState, s32 *, 0x14) = 0;
}

void func_0208fd40(M2C_UNK *a,s32 b,u32 c){
 u32 hi=(c&0xffff0000)>>16;u32 lo=(u16)c;
 if(hi){Sound_PlayArchiveEntry(a,b,-1,-1,hi,lo);return;}
 func_0202d378(a,b,-1,-1,lo);
}

void func_0208fd94(void) {
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
s32 PlaySoundEffect(s32 a){
 s32 Sound_ClaimPlaySlot(s32);
 void func_0208fd40(M2C_UNK*,s32,u32);
 extern M2C_UNK gSoundDriverState,data_02157834;
 u8 enabled=M2C_FIELD(&gSoundDriverState,u8*,0);
 if(enabled==0)return 0;
 if(!Sound_ClaimPlaySlot(a))return 0;
 func_0208fd40(&data_02157834,-1,a);return 1;
}

