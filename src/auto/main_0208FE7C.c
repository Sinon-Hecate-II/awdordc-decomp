/* 45 functions from 0x0208FE7C to 0x02090E0C (main), found by ds-decomp. */
#include "common.h"
#include "sprite_script.h"
#include "sound.h"
static inline void CallNodeMethod(void *node) {
    M2C_FIELD(*(void **)node, void (**)(void *), 0)(node);
}

void func_02090574(void);

s32 func_0208fe7c(s32 arg0, s32 arg1) {
    s32 PlaySoundEffect(s32);

    if (PlaySoundEffect(arg0) != 0) {
        func_0208fea0(arg1);
    }
    return 1;
}

s32 func_0208fea0(M2C_UNK arg0) {
    M2C_UNK Sound_FadeEffectVolume(M2C_UNK, M2C_UNK, M2C_UNK);
    Sound_FadeEffectVolume(-1, arg0, 0);
    return 1;
}

/* Fade the sound-effect player's volume to targetVolume over frames frames; a
 * snapVolume other than -1 sets the volume at once before the fade starts.
 * Returns 0 while the sound system is off or the player is not ready. */
s32 Sound_FadeEffectVolume(s32 snapVolume, s32 targetVolume, s32 frames) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gSoundEffectPlayer;
    u8 IsSoundPlayerReady(void);
    M2C_UNK Sound_StartPlayerVolumeFade(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    if (IsSoundPlayerReady() == 0) {
        return 0;
    }
    if (snapVolume != -1) {
        Sound_StartPlayerVolumeFade(&gSoundEffectPlayer, snapVolume, 0);
    }
    Sound_StartPlayerVolumeFade(&gSoundEffectPlayer, targetVolume, frames);
    return 1;
}

u8 IsSoundPlayerReady(void) {
    extern M2C_UNK gSoundDriverState;
    u8 var_r0;

    if (M2C_FIELD(&gSoundDriverState, s32 *, 4) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 Sound_WasPlayedWithin(s32 arg0) {
    extern M2C_UNK gSoundDriverState;
    extern s32 gFrameCounter;
    u8 var_r0;

    if (IsSoundPlayerReady() == 0) {
        return 0;
    }
    if ((u32) gFrameCounter <= (u32) (M2C_FIELD(&gSoundDriverState, s32 *, 0x1C) + arg0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Pan the sound-effect player (0xFFFF tells the driver to keep the volume it has).
 * Returns 0 while the sound system is off or the player is not ready, 1 once the
 * pan was handed to the driver. */
s32 SetSoundEffectPan(M2C_UNK pan) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gSoundEffectPlayer;
    u8 IsSoundPlayerReady(void);
    M2C_UNK Sound_SetPlayerPan(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    if (IsSoundPlayerReady() == 0) {
        return 0;
    }
    Sound_SetPlayerPan(&gSoundEffectPlayer, 0xFFFF, pan);
    return 1;
}

/* Play packed sound `packedSoundId` (its low 16 bits name the sound, the high 16
 * bits its archive) on sound-effect slot `slot`, stopping the slot's current sound
 * first; `channel` -1 uses the slot's default channel. Returns 0 while the sound
 * system is off, 1 once the sound was handed to the slot. */
s32 PlaySlotPendingSound(s32 slot, M2C_UNK channel, M2C_UNK packedSoundId) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gSoundEffectSlotHandles;
    M2C_UNK Sound_PlayPackedId(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 StopSlotSound(s32, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    StopSlotSound(slot, 0);
    Sound_PlayPackedId(&gSoundEffectSlotHandles + slot, channel, packedSoundId);
    return 1;
}

/* Stop the sound playing in effect slot `slot`: the slot's voice is released at
 * once when `fadeFrames` is 0, otherwise faded out over that many frames.  Returns
 * 0 while the sound system is off or the slot is already silent. */
s32 StopSlotSound(s32 slot, s32 fadeFrames) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gSoundEffectSlotHandles;
    u8 IsSlotSoundActive(s32);
    M2C_UNK Sound_StopPlayerVoice(M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    if (IsSlotSoundActive(slot) == 0) {
        return 0;
    }
    Sound_StopPlayerVoice(&gSoundEffectSlotHandles + slot, fadeFrames);
    return 1;
}

u8 IsSlotSoundActive(s32 arg0) {
    extern M2C_UNK gSoundEffectSlotHandles;
    u8 var_r0;

    if ((&gSoundEffectSlotHandles)[arg0] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Hand a pending volume change for slot `slot` to the sound driver, but only
 * while the sound system is up and the slot's player is active. Returns 0 when
 * nothing was handed over, 1 once the driver took it. */
s32 SetSlotSoundPending(s32 slot, s32 volume, s32 frames) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gSoundEffectSlotHandles;
    u8 IsSlotSoundActive(s32);
    M2C_UNK func_0202ad50(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    if (IsSlotSoundActive(slot) == 0) {
        return 0;
    }
    func_0202ad50(&gSoundEffectSlotHandles + slot, (M2C_UNK)(u16)volume, frames);
    return 1;
}

/* Set the pan of the sound playing on effect slot `slot` (-0x80 hard left,
 * 0x7F hard right). Returns 0 while the sound system is off or the slot is
 * silent, 1 once the pan was handed to the driver. */
s32 SetSlotSoundPan(s32 slot, s32 pan) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gSoundEffectSlotHandles;
    u8 IsSlotSoundActive(s32);
    M2C_UNK Sound_SetPlayerPan(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    if (IsSlotSoundActive(slot) == 0) {
        return 0;
    }
    Sound_SetPlayerPan(&gSoundEffectSlotHandles + slot, 0xFFFF, pan);
    return 1;
}

/* Fade the scripted sound playing in effect slot `slot` to `volume` over
 * `frames` frames. Returns 0 while the sound system is off or the slot is
 * silent, 1 once the fade was handed to the driver. */
s32 PlaySlotScriptedSound(s32 slot, s32 volume, s32 frames) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gSoundEffectSlotHandles;
    u8 IsSlotSoundActive(s32);
    M2C_UNK Sound_StartPlayerVolumeFade(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    if (IsSlotSoundActive(slot) == 0) {
        return 0;
    }
    Sound_StartPlayerVolumeFade(&gSoundEffectSlotHandles + slot, volume, frames);
    return 1;
}

s32 PlaySlotScriptedSoundAtVolume(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    s32 PlaySlotPendingSound(s32, M2C_UNK, M2C_UNK);
    s32 PlaySlotScriptedSound(s32, s32, s32);

    if (PlaySlotPendingSound(arg0, arg1, arg2) != 0) {
        PlaySlotScriptedSound(arg0, arg3, 0);
    }
    return 1;
}

/* Starts music track `trackId`: an id with bit 0x10000 names a sound-archive
 * entry played on the streamed music player, any other id a music sequence
 * played on the sequence player.  Returns 0 while the sound system is off or the
 * player could not start, 1 once it started. */
s32 StartMusicTrack(s32 trackId) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gMusicSoundPlayer;
    extern M2C_UNK gMusicSequencePlayer;
    s32 Sound_StartArchiveSound(M2C_UNK player, M2C_UNK soundId, s32 arg);
    s32 Sound_PlaySequenceRecord(M2C_UNK player, s32 sequenceId);

    s32 started;
    u16 id;

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    id = (u16) trackId;
    if (trackId & 0x10000) {
        started = Sound_StartArchiveSound(&gMusicSoundPlayer, id, 0) & 0xFF;
        func_02090574();
    } else {
        started = Sound_PlaySequenceRecord(&gMusicSequencePlayer, id) & 0xFF;
    }
    if (started == 0) {
        return 0;
    }
    return 1;
}

/* Fade the running music players out to silence over `frames` frames (0 stops
 * them at once): each of the sequence and streamed-sound players is left alone
 * when it is not active.  Returns 0 while the sound system is off. */
s32 FadeOutMusic(s32 frames) {
    extern M2C_UNK gSoundDriverState, gMusicSequencePlayer, gMusicSoundPlayer;
    u8 IsMusicSequencePlayerActive(void);
    u8 IsMusicSoundPlayerActive(void);
    M2C_UNK func_0202ac60(M2C_UNK, M2C_UNK);
    void func_0202d944(M2C_UNK, s32);
    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) return 0;
    if (IsMusicSequencePlayerActive() != 0) func_0202ac60(&gMusicSequencePlayer, frames);
    if (IsMusicSoundPlayerActive() != 0) func_0202d944(&gMusicSoundPlayer, frames);
    return 1;
}

/* Fade the volume of both of the game's sound players (the sequence player and
 * the effect player) to `targetVolume` over `frames` frames.  A `snapVolume`
 * other than -1 sets the volume to it at once before the fade starts. */
s32 Sound_FadeVolume(s32 snapVolume, s32 targetVolume, s32 frames) {
    extern M2C_UNK gSoundDriverState;
    extern M2C_UNK gMusicSequencePlayer;
    extern M2C_UNK gMusicSoundPlayer;
    u8 IsMusicSequencePlayerActive(void);
    u8 IsMusicSoundPlayerActive(void);
    M2C_UNK Sound_StartPlayerVolumeFade(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0202d960(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return 0;
    }
    if (IsMusicSequencePlayerActive() != 0) {
        if (snapVolume != -1) {
            Sound_StartPlayerVolumeFade(&gMusicSequencePlayer, snapVolume, 0);
        }
        Sound_StartPlayerVolumeFade(&gMusicSequencePlayer, targetVolume, frames);
    }
    if (IsMusicSoundPlayerActive() != 0) {
        if (snapVolume != -1) {
            func_0202d960(&gMusicSoundPlayer, snapVolume, 0);
        }
        func_0202d960(&gMusicSoundPlayer, targetVolume, frames);
    }
    return 1;
}

u8 IsMusicSequencePlayerActive(void) {
    extern M2C_UNK gSoundDriverState;
    u8 var_r0;

    if (M2C_FIELD(&gSoundDriverState, s32 *, 0xC) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsMusicSoundPlayerActive(void) {
    extern M2C_UNK gSoundDriverState;
    u8 var_r0;

    if (M2C_FIELD(&gSoundDriverState, s32 *, 0x8) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02090390(void) {
    extern M2C_UNK gSoundDriverState;
    void func_0202a9f0(void);

    if (M2C_FIELD(&gSoundDriverState, u8 *, 0) == 0) {
        return;
    }
    func_0202a9f0();
}

void func_020903b0(void) {
    extern M2C_UNK gSoundDriverState;
    s32 Sound_PushHeapSection(void *);

    if (M2C_FIELD(&gSoundDriverState, u8 *, 0) == 0) {
        return;
    }
    Sound_PushHeapSection(M2C_FIELD(&gSoundDriverState, void **, 0x10));
}

void func_020903d4(void) {
    void LoadSoundSequenceArchiveAndBank(s32, s32);
    M2C_UNK func_02090448(M2C_UNK);
    LoadSoundSequenceArchiveAndBank(1, 0x24);
    func_02090448(1);
}

/* Load a sequence archive and a sound bank into the sound player's heap: the two
 * loads run between the heap-access calls of func_0202c784.  Does nothing while
 * the sound system is off. */
void LoadSoundSequenceArchiveAndBank(s32 archiveId, s32 bankId) {
    extern M2C_UNK gSoundDriverState;
    s32 func_0202c784(M2C_UNK *);
    s32 func_0202c860(M2C_UNK, M2C_UNK);
    s32 func_0202c88c(M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&gSoundDriverState, u8 *, SOUND_STATE_ENABLED) == 0) {
        return;
    }
    func_0202c784(M2C_FIELD(&gSoundDriverState, M2C_UNK *, SOUND_STATE_PLAYER));
    func_0202c860(archiveId, M2C_FIELD(&gSoundDriverState, M2C_UNK *, SOUND_STATE_PLAYER));
    func_0202c88c(bankId, M2C_FIELD(&gSoundDriverState, M2C_UNK *, SOUND_STATE_PLAYER));
    func_0202c784(M2C_FIELD(&gSoundDriverState, M2C_UNK *, SOUND_STATE_PLAYER));
}

M2C_UNK func_02090448(M2C_UNK arg0) {
    extern M2C_UNK gSoundDriverState;
    s32 func_0202c784(M2C_UNK *);
    M2C_UNK func_0202c848(M2C_UNK, M2C_UNK);

    func_0202c784(M2C_FIELD(&gSoundDriverState, M2C_UNK *, 0x10));
    func_0202c848(arg0, M2C_FIELD(&gSoundDriverState, M2C_UNK *, 0x10));
    func_0202c784(M2C_FIELD(&gSoundDriverState, M2C_UNK *, 0x10));
}

void func_02090480(s32 arg0) {
    M2C_UNK func_0202c778(M2C_UNK);
    M2C_UNK func_0202c6a4(M2C_UNK, s32);
    extern M2C_UNK gSoundDriverState;

    if (M2C_FIELD(&gSoundDriverState, u8 *, 0) == 0) {
        return;
    }
    {
        M2C_UNK r0;
        s32 diff;

        r0 = func_0202c778(M2C_FIELD(&gSoundDriverState, M2C_UNK *, 0x10));
        if (r0 == 0) {
            return;
        }
        diff = r0 - arg0;
        if (diff < 0) {
            diff = 0;
        }
        func_0202c6a4(M2C_FIELD(&gSoundDriverState, M2C_UNK *, 0x10), diff);
    }
}

/* Effective music volume: the channel's three 0..127 volume levels (master, the
 * player's music setting and the fade/duck level) multiplied together and scaled
 * back to the 0..127 range by dividing by full volume once per level. */
s32 GetMusicVolume(void) {
    extern M2C_UNK gMusicVolumeLevels;
    s32 volume;
    s32 level;

    volume = SOUND_VOLUME_MAX;
    level = 0;
    do {
        volume = volume * M2C_FIELD(&gMusicVolumeLevels, u8 *, level);
        level += 1;
    } while (level < SOUND_VOLUME_LEVELS);
    level = 0;
    do {
        volume = volume / SOUND_VOLUME_MAX;
        level += 1;
    } while (level < SOUND_VOLUME_LEVELS);
    return volume;
}

/* Combine the SOUND_VOLUME_LEVELS volume factors of the sound-effect channels
 * (master, user setting and fade, each 0..SOUND_VOLUME_MAX) into their single
 * effective volume, kept within 0..SOUND_VOLUME_MAX. */
s32 Sound_GetEffectVolume(void) {
    extern M2C_UNK gSoundEffectVolumeLevels;
    s32 volume;
    s32 level;

    volume = SOUND_VOLUME_MAX;
    level = 0;
    do {
        volume = volume * M2C_FIELD(&gSoundEffectVolumeLevels, u8 *, level);
        level += 1;
    } while (level < SOUND_VOLUME_LEVELS);
    level = 0;
    do {
        volume = volume / SOUND_VOLUME_MAX;
        level += 1;
    } while (level < SOUND_VOLUME_LEVELS);
    return volume;
}

void func_02090574(void) {
extern M2C_UNK gSoundDriverState;
extern M2C_UNK gMusicSoundPlayer;
s32 GetMusicVolume(void);
void func_0202d994(volatile s32 *, s32, s32);
if(M2C_FIELD(&gSoundDriverState,s32 *,8)!=0) {
s32 value=GetMusicVolume();
func_0202d994(&gMusicSoundPlayer,0,value);
func_0202d994(&gMusicSoundPlayer,1,value);
}
}

void func_020905bc(void) {
    M2C_UNK func_0202ab7c(M2C_UNK, s32);
    s32 GetMusicVolume();

    func_0202ab7c(0, GetMusicVolume());
    func_02090574();
}

void func_020905d8(void) {
    s32 Sound_GetEffectVolume();
    s32 temp_r4;
    s32 var_r5;

    temp_r4 = Sound_GetEffectVolume();
    var_r5 = 1;
    do {
        func_0202ab7c(var_r5, temp_r4);
        var_r5 += 1;
    } while (var_r5 <= 0xB);
}

void func_02090604(void) {
    extern M2C_UNK gMusicVolumeLevels;
    extern M2C_UNK gSoundEffectVolumeLevels;
    void func_020905bc(void);
    void func_020905d8(void);
    u8 *var_r2;
    u8 *var_r3;
    s32 var_r1;

    var_r2 = (u8 *)&gMusicVolumeLevels;
    var_r3 = (u8 *)&gSoundEffectVolumeLevels;
    var_r1 = 0;
    do {
        var_r1 += 1;
        *var_r2++ = 0x7F;
        *var_r3++ = 0x7F;
    } while (var_r1 < 3);
    func_020905bc();
    func_020905d8();
}

void SetMusicVolumeLevel(s32 arg0, s32 arg1) {
    extern M2C_UNK gMusicVolumeLevels;
    s32 var_r1;

    var_r1 = arg1;
    if (var_r1 > 0x7F) {
        var_r1 = 0x7F;
    } else if (var_r1 < 0) {
        var_r1 = 0;
    }
    M2C_FIELD(&gMusicVolumeLevels, u8 *, arg0) = var_r1;
    func_020905bc();
}

void SetSoundEffectVolumeLevel(s32 arg0, s32 arg1) {
    extern M2C_UNK gSoundEffectVolumeLevels;
    s32 var_r1;

    var_r1 = arg1;
    if (var_r1 > 0x7F) {
        var_r1 = 0x7F;
    } else if (var_r1 < 0) {
        var_r1 = 0;
    }
    M2C_FIELD(&gSoundEffectVolumeLevels, u8 *, arg0) = var_r1;
    func_020905d8();
}

u8 func_02090698(s32 arg0) {
    extern M2C_UNK gMusicVolumeLevels;
    return M2C_FIELD(&gMusicVolumeLevels, u8 *, arg0);
}

/* Initialise a freshly allocated script player for `object`: attach the script and the
 * slot's entries, set the position, tile and priority, and make it the object's first
 * player.  x carries its upper bits in SPRITE_PLAYER_X_HIGH, y likewise. */
void SpritePlayer_Init(void *player, void *object, u8 *script, u8 slot, u16 x, u16 y, u16 tile, s32 priority) {
    u8 *scriptData;
    u32 posY;

    M2C_FIELD(player, u8 **, SPRITE_PLAYER_SCRIPT) = script;
    M2C_FIELD(player, u8 *, SPRITE_PLAYER_SLOT) = slot;
    M2C_FIELD(player, void **, SPRITE_PLAYER_FRAME_TABLE) = script + *(u32 *)M2C_FIELD(player, u8 **, SPRITE_PLAYER_SCRIPT);
    scriptData = M2C_FIELD(player, u8 **, SPRITE_PLAYER_SCRIPT);
    M2C_FIELD(player, void **, SPRITE_PLAYER_CURSOR) = scriptData + M2C_FIELD(scriptData + M2C_FIELD(player, u8 *, SPRITE_PLAYER_SLOT) * 4, u32 *, 4);
    M2C_FIELD(player, s16 *, SPRITE_PLAYER_X) = x & 0x1ff;
    if (x & 0x100) M2C_FIELD(player, s16 *, SPRITE_PLAYER_X) |= 0xfe00;
    posY = y;
    M2C_FIELD(player, s16 *, SPRITE_PLAYER_Y) = posY & 255;
    if (posY >= 192) M2C_FIELD(player, s16 *, SPRITE_PLAYER_Y) |= 0xff00;
    M2C_FIELD(player, u16 *, SPRITE_PLAYER_X_HIGH) = x & 0xfe00;
    M2C_FIELD(player, u16 *, SPRITE_PLAYER_Y_HIGH) = posY & 0xff00;
    M2C_FIELD(player, u16 *, SPRITE_PLAYER_TILE) = tile;
    M2C_FIELD(player, s8 *, SPRITE_PLAYER_PRIORITY) = priority;
    M2C_FIELD(player, s8 *, SPRITE_PLAYER_PRIORITY_ADD) = 0;
    M2C_FIELD(player, u8 *, SPRITE_PLAYER_FLAGS) = 0;
    M2C_FIELD(player, s32 *, SPRITE_PLAYER_DELAY) = 0;
    M2C_FIELD(player, void **, SPRITE_PLAYER_OWNER) = object;
    M2C_FIELD(player, s32 *, SPRITE_PLAYER_PREV) = 0;
    M2C_FIELD(player, s32 *, SPRITE_PLAYER_NEXT) = 0;
    M2C_FIELD(object, void **, SPRITE_OWNER_PLAYER_LIST) = player;
}

/* Appends a new script player to the end of `parent`'s list and starts it on the
 * same script at the given slot: it copies the position, tile, priority and flags
 * of the list's last player (whose script and owner it inherits), resets its wait
 * counter and links it in after that player. */
void SpritePlayer_SpawnChild(void *player, void *parent, s32 slot) {
    s32 *temp_ip;
    s32 *temp_ip_2;
    void *temp_r2;
    void *tail;
    void *walker;

    tail = parent;
    walker = M2C_FIELD(tail, void **, SPRITE_PLAYER_NEXT);
    if (walker != NULL) {
        do {
            tail = walker;
            walker = M2C_FIELD(walker, void **, SPRITE_PLAYER_NEXT);
        } while (walker != NULL);
    }
    M2C_FIELD(player, s32 **, SPRITE_PLAYER_SCRIPT) = (s32 *) M2C_FIELD(tail, s32 **, SPRITE_PLAYER_SCRIPT);
    M2C_FIELD(player, u8 *, SPRITE_PLAYER_SLOT) = slot;
    temp_ip = M2C_FIELD(player, s32 **, SPRITE_PLAYER_SCRIPT);
    M2C_FIELD(player, void **, SPRITE_PLAYER_FRAME_TABLE) = (void *) ((s8 *) temp_ip + *temp_ip);
    temp_ip_2 = M2C_FIELD(player, s32 **, SPRITE_PLAYER_SCRIPT);
    M2C_FIELD(player, void **, SPRITE_PLAYER_CURSOR) = (void *) ((s8 *) temp_ip_2 + M2C_FIELD(temp_ip_2 + M2C_FIELD(player, u8 *, SPRITE_PLAYER_SLOT), s32 *, 4));
    M2C_FIELD(player, s16 *, SPRITE_PLAYER_X) = (s16) M2C_FIELD(tail, s16 *, SPRITE_PLAYER_X);
    M2C_FIELD(player, s16 *, SPRITE_PLAYER_Y) = (s16) M2C_FIELD(tail, s16 *, SPRITE_PLAYER_Y);
    M2C_FIELD(player, u16 *, SPRITE_PLAYER_X_HIGH) = (u16) M2C_FIELD(tail, u16 *, SPRITE_PLAYER_X_HIGH);
    M2C_FIELD(player, u16 *, SPRITE_PLAYER_Y_HIGH) = (u16) M2C_FIELD(tail, u16 *, SPRITE_PLAYER_Y_HIGH);
    M2C_FIELD(player, u16 *, SPRITE_PLAYER_TILE) = (u16) M2C_FIELD(tail, u16 *, SPRITE_PLAYER_TILE);
    M2C_FIELD(player, s8 *, SPRITE_PLAYER_PRIORITY) = (s8) M2C_FIELD(tail, s8 *, SPRITE_PLAYER_PRIORITY);
    M2C_FIELD(player, u8 *, SPRITE_PLAYER_FLAGS) = (u8) M2C_FIELD(tail, u8 *, SPRITE_PLAYER_FLAGS);
    M2C_FIELD(player, s32 *, SPRITE_PLAYER_DELAY) = 0;
    M2C_FIELD(player, s32 *, SPRITE_PLAYER_OWNER) = (s32) M2C_FIELD(tail, s32 *, SPRITE_PLAYER_OWNER);
    M2C_FIELD(player, void **, SPRITE_PLAYER_PREV) = tail;
    temp_r2 = M2C_FIELD(tail, void **, SPRITE_PLAYER_NEXT);
    M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT) = temp_r2;
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, SPRITE_PLAYER_PREV) = player;
    }
    M2C_FIELD(tail, void **, SPRITE_PLAYER_NEXT) = player;
}

void SpritePlayer_SetListPosition(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0x20) = (u16)arg1;
    M2C_FIELD(arg0, u16 *, 0x22) = (u16)arg2;
    arg0 = M2C_FIELD(arg0, void **, 0x8);
    if (arg0 != 0) {
        SpritePlayer_SetListPosition(arg0, arg1, arg2);
    }
}

/* Unlink a script player from its owner's list and free it. */
void SpritePlayer_Remove(void *player) {
    M2C_UNK MemFree();
    void *prev;
    void *next;
    void *newHead;

    prev = M2C_FIELD(player, void **, SPRITE_PLAYER_PREV);
    if (prev != NULL) {
        M2C_FIELD(prev, void **, SPRITE_PLAYER_NEXT) = (void *) M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT);
        next = M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT);
        if (next != NULL) {
            M2C_FIELD(next, void **, SPRITE_PLAYER_PREV) = (void *) M2C_FIELD(player, void **, SPRITE_PLAYER_PREV);
        }
        if (player == NULL) {
            return;
        }
        MemFree();
        return;
    }
    M2C_FIELD(M2C_FIELD(player, void **, SPRITE_PLAYER_OWNER), void **, SPRITE_OWNER_PLAYER_LIST) = (void *) M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT);
    newHead = M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT);
    if (newHead != NULL) {
        M2C_FIELD(newHead, void **, SPRITE_PLAYER_PREV) = NULL;
    }
    if (player == NULL) {
        return;
    }
    MemFree();
}

void func_02090894(void **arg0) {
    M2C_UNK MemFree(void **);
    void SpritePlayer_AdvanceToCommand(void *);
    void **var_r4;
    void **temp_r5;

    var_r4 = arg0;
    SpritePlayer_AdvanceToCommand(arg0);
    if (arg0 != NULL) {
        do {
            temp_r5 = M2C_FIELD(var_r4, void ***, 8);
            if (var_r4 != NULL) {
                MemFree(var_r4);
            }
            var_r4 = temp_r5;
        } while (temp_r5 != NULL);
    }
    M2C_FIELD(*arg0, s32 *, 0x38) = 0;
}

/* Advances one frame of a script player: while its delay counter is nonzero it
   only counts down; otherwise it walks the 0x10-byte script entries at the
   cursor - executing command entries (stop, relative jump, linear search, spawn
   a child player) and arming the next wait from a delay entry - then recurses
   into the next player in the list. */
void func_020908dc(void *player) {
    void SpritePlayer_Remove(void *);
    void SpritePlayer_SpawnChild(void *, void *, s32);
    void *MemAlloc(s32);
    u8 *cursor;
    u8 *entry;
    void *nextPlayer;

    nextPlayer = M2C_FIELD(player, void **, 8);
    if (M2C_FIELD(player, s32 *, 0x1C) != 0) {
        goto decr;
    }
    goto skip;
    for (;;) {
        if (M2C_FIELD(M2C_FIELD(player, u8 **, 0x10), u8 *, 3) != 0) {
            switch (M2C_FIELD(M2C_FIELD(player, u8 **, 0x10), u8 *, 2)) {
            case 0:
            case 0xFF:
                SpritePlayer_Remove(player);
                goto done;
            case 1:
                M2C_FIELD(player, u8 **, 0x10) = (u8 *)M2C_FIELD(player, s32 **, 0xC)
                     + M2C_FIELD(M2C_FIELD(player, s32 **, 0xC) + M2C_FIELD(player, u8 *, 0x2C), s32 *, 4);
                goto skip;
            case 2:
                goto done;
            case 3:
                break;
            case 4:
                entry = (u8 *)M2C_FIELD(player, s32 **, 0xC)
                     + M2C_FIELD(M2C_FIELD(player, s32 **, 0xC) + M2C_FIELD(player, u8 *, 0x2C), s32 *, 4);
                while (M2C_FIELD(entry, u8 *, 3) == 0 || M2C_FIELD(entry, u8 *, 2) != 0xFF) {
                    if (M2C_FIELD(entry, u8 *, 3) != 0 && M2C_FIELD(entry, u8 *, 2) == 3
                        && M2C_FIELD(entry, s16 *, 6) == M2C_FIELD(M2C_FIELD(player, u8 **, 0x10), s16 *, 6)) {
                        M2C_FIELD(player, void **, 0x10) = entry;
                        break;
                    }
                    M2C_FIELD(player, u8 **, 0x10) = M2C_FIELD(player, u8 **, 0x10) + 0x10;
                }
                goto skip;
            case 0x10:
                if (M2C_FIELD(M2C_FIELD(player, u8 **, 0x10), s16 *, 6) > 0) {
                    entry = MemAlloc(0x30);
                    if (entry != NULL) {
                        SpritePlayer_SpawnChild(entry, player, M2C_FIELD(M2C_FIELD(player, u8 **, 0x10), s16 *, 6) - 1);
                    }
                    nextPlayer = M2C_FIELD(player, void **, 8);
                }
                break;
            case 0x11:
                M2C_FIELD(player, u8 *, 0x2B) = M2C_FIELD(M2C_FIELD(player, u8 **, 0x10), u16 *, 6);
                break;
            default:
                break;
            }
        }
        M2C_FIELD(player, u8 **, 0x10) = M2C_FIELD(player, u8 **, 0x10) + 0x10;
    skip:
        cursor = M2C_FIELD(player, u8 **, 0x10);
        if (M2C_FIELD(cursor, u8 *, 3) != 0 || M2C_FIELD(cursor, u16 *, 0) == 0) {
            continue;
        }
        M2C_FIELD(player, s32 *, 0x1C) = M2C_FIELD(cursor, u16 *, 0);
        M2C_FIELD(player, s32 *, 0x18) = M2C_FIELD(player, s32 *, 0xC)
            + M2C_FIELD(M2C_FIELD(player, s32 **, 0x14) + M2C_FIELD(M2C_FIELD(player, u8 **, 0x10), u8 *, 2), s32 *, 0);
        M2C_FIELD(player, u8 **, 0x10) = M2C_FIELD(player, u8 **, 0x10) + 0x10;
        break;
    }
decr:
    M2C_FIELD(player, s32 *, 0x1C) = M2C_FIELD(player, s32 *, 0x1C) - 1;
done:
    if (nextPlayer != NULL) {
        func_020908dc(nextPlayer);
    }
}

/* Walk every script player in the list forward past its wait entries to the next
 * control command, spawning the child players a SPRITE_SCRIPT_SPAWN command asks
 * for; the owning sprite's auxiliary object list is released first.  Recurses
 * into the next player in the list. */
void SpritePlayer_AdvanceToCommand(void *player) {
    void Sprite_DestroyAuxList(void *);
    void SpritePlayer_SpawnChild(void *, void *, s32);
    void *MemAlloc(s32);
    u8 *cursor;
    u8 *entry;
    void *next;

    next = M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT);
    if (M2C_FIELD(M2C_FIELD(player, void **, SPRITE_PLAYER_OWNER), s32 *, SPRITE_OWNER_AUX_LIST) != 0) {
        Sprite_DestroyAuxList((void *)M2C_FIELD(M2C_FIELD(player, void **, SPRITE_PLAYER_OWNER), s32 *, SPRITE_OWNER_AUX_LIST));
    }
    goto skip;
    for (;;) {
        if (M2C_FIELD(M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR), u8 *, SPRITE_ENTRY_KIND) != 0) {
            switch (M2C_FIELD(M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR), u8 *, SPRITE_ENTRY_COMMAND)) {
            case SPRITE_SCRIPT_STOP:
            case SPRITE_SCRIPT_JUMP:
            case SPRITE_SCRIPT_RETURN:
                goto done;
            case SPRITE_SCRIPT_SKIP:
                break;
            case SPRITE_SCRIPT_SEARCH:
                entry = (u8 *)M2C_FIELD(player, s32 **, SPRITE_PLAYER_SCRIPT)
                     + M2C_FIELD(M2C_FIELD(player, s32 **, SPRITE_PLAYER_SCRIPT) + M2C_FIELD(player, u8 *, SPRITE_PLAYER_SLOT), s32 *, 4);
                while (M2C_FIELD(entry, u8 *, SPRITE_ENTRY_KIND) == 0 || M2C_FIELD(entry, u8 *, SPRITE_ENTRY_COMMAND) != SPRITE_SCRIPT_LOOP) {
                    if (M2C_FIELD(entry, u8 *, SPRITE_ENTRY_KIND) != 0 && M2C_FIELD(entry, u8 *, SPRITE_ENTRY_COMMAND) == SPRITE_SCRIPT_SKIP
                        && M2C_FIELD(entry, s16 *, SPRITE_ENTRY_ARG) == M2C_FIELD(M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR), s16 *, SPRITE_ENTRY_ARG)) {
                        M2C_FIELD(player, void **, SPRITE_PLAYER_CURSOR) = entry;
                        break;
                    }
                    M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR) = M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR) + SPRITE_ENTRY_SIZE;
                }
                goto skip;
            case SPRITE_SCRIPT_SPAWN:
                if (M2C_FIELD(M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR), s16 *, SPRITE_ENTRY_ARG) > 0) {
                    entry = MemAlloc(SPRITE_PLAYER_SIZE);
                    if (entry != NULL) {
                        SpritePlayer_SpawnChild(entry, player, M2C_FIELD(M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR), s16 *, SPRITE_ENTRY_ARG) - 1);
                    }
                    next = M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT);
                }
                break;
            case SPRITE_SCRIPT_LOOP:
                goto done;
            default:
                break;
            }
        }
        M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR) = M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR) + SPRITE_ENTRY_SIZE;
    skip:
        cursor = M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR);
        if (M2C_FIELD(cursor, u8 *, SPRITE_ENTRY_KIND) != 0 || M2C_FIELD(cursor, u16 *, SPRITE_ENTRY_WAIT) == 0) {
            goto after;
        }
        M2C_FIELD(player, u8 **, SPRITE_PLAYER_CURSOR) = cursor + SPRITE_ENTRY_SIZE;
        goto skip;
    after:
        ;
    }
done:
    if (next != NULL) {
        SpritePlayer_AdvanceToCommand(next);
    }
}

/* Draw one script player into the 3D sprite engine, then every player after it
 * on the same owner's list (SPRITE_PLAYER_NEXT).  Hidden players are skipped and
 * the draw helper is picked by SPRITE_PLAYER_FLAG_3D. */
void SpritePlayer_DrawList(void *player) {
    void AddSpriteEntry(s32, s32, s32, s32, s32, void *, s32);
    void AddSpriteEntry3D(s32, s32, s32, s32, s32, void *, s32);

    u8 flags;

    flags = M2C_FIELD(player, u8 *, SPRITE_PLAYER_FLAGS);
    if (flags & SPRITE_PLAYER_FLAG_HIDDEN) {
        return;
    }
    if ((flags & SPRITE_PLAYER_FLAG_3D) == 0) {
        AddSpriteEntry(M2C_FIELD(player, s16 *, SPRITE_PLAYER_X),
                      M2C_FIELD(player, s16 *, SPRITE_PLAYER_Y),
                      (u16)M2C_FIELD(player, u16 *, SPRITE_PLAYER_X_HIGH),
                      (u16)M2C_FIELD(player, u16 *, SPRITE_PLAYER_Y_HIGH),
                      M2C_FIELD(player, u16 *, SPRITE_PLAYER_TILE),
                      (void *)M2C_FIELD(player, void **, SPRITE_PLAYER_FRAME),
                      M2C_FIELD(player, s8 *, SPRITE_PLAYER_PRIORITY) + M2C_FIELD(player, s8 *, SPRITE_PLAYER_PRIORITY_ADD));
    } else {
        AddSpriteEntry3D(M2C_FIELD(player, s16 *, SPRITE_PLAYER_X),
                      M2C_FIELD(player, s16 *, SPRITE_PLAYER_Y),
                      (u16)M2C_FIELD(player, u16 *, SPRITE_PLAYER_X_HIGH),
                      (u16)M2C_FIELD(player, u16 *, SPRITE_PLAYER_Y_HIGH),
                      M2C_FIELD(player, u16 *, SPRITE_PLAYER_TILE),
                      (void *)M2C_FIELD(player, void **, SPRITE_PLAYER_FRAME),
                      M2C_FIELD(player, s8 *, SPRITE_PLAYER_PRIORITY) + M2C_FIELD(player, s8 *, SPRITE_PLAYER_PRIORITY_ADD));
    }
    if (M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT) != 0) {
        SpritePlayer_DrawList(M2C_FIELD(player, void **, SPRITE_PLAYER_NEXT));
    }
}

void Sprite_DestroyAuxList(void *arg0) {
    void *var_r0;
    void *temp_r5;
    void *temp_r4;

    var_r0 = arg0;
    temp_r5 = var_r0;
    if (temp_r5 != 0) {
        do {
            temp_r4 = M2C_FIELD(var_r0, void **, 0xC);
            if (var_r0 != 0) {
                M2C_FIELD(M2C_FIELD(var_r0, void **, 0), void (**)(void *), 8)(var_r0);
            }
            var_r0 = temp_r4;
        } while (temp_r4 != 0);
    }
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 4), s32 *, 0x3C) = 0;
}

s32 func_02090cbc(void *p) {
void func_020908dc(void *);void func_02090d84(void *);void DeleteSpriteObject(void *);void SpritePlayer_DrawList(void *);
void *q;
if(M2C_FIELD(p,void **,0x38))func_020908dc(M2C_FIELD(p,void **,0x38));
q=M2C_FIELD(p,void **,0x3C);
if(q) {
Call02090Node(q);q=M2C_FIELD(q,void **,0xC);
if(q) {
Call02090Node(q);q=M2C_FIELD(q,void **,0xC);
if(q) {
Call02090Node(q);q=M2C_FIELD(q,void **,0xC);
if(q) {
Call02090Node(q);q=M2C_FIELD(q,void **,0xC);
if(q)func_02090d84(q);
}}}}
if(!M2C_FIELD(p,void **,0x38) && !M2C_FIELD(p,void **,0x3C))DeleteSpriteObject(p);
else if(M2C_FIELD(p,void **,0x38))SpritePlayer_DrawList(M2C_FIELD(p,void **,0x38));
}

#pragma optimization_level 4
void func_02090d84(void *arg0) {
void *node;
CallNodeMethod(arg0); node=arg0;
node=M2C_FIELD(node,void **,12); if(!node)return;
CallNodeMethod(node);
node=M2C_FIELD(node,void **,12); if(!node)return;
CallNodeMethod(node);
node=M2C_FIELD(node,void **,12); if(!node)return;
CallNodeMethod(node);
node=M2C_FIELD(node,void **,12); if(!node)return;
func_02090d84(node);
}
#pragma optimization_level reset
void func_02090e00(void) {
    M2C_UNK func_02090cbc();
    func_02090cbc();
}
