/* 36 functions from 0x0202AE00 to 0x0202BD7C (main), found by ds-decomp. */
#include "common.h"
#include "sound.h"
void Sound_RecycleVoice();
typedef struct { u32 words[2]; } Unk02BDFileRange;
typedef struct { s32 pad[3]; s32 buffer0, buffer1, size, unk18, state, unk20, channel0, channel1, channel; } AudioBufferState;
extern s32 gSoundChannelSampleState[];
extern s32 gSoundSegmentOffsets[16];
void Sound_UnlinkPlayingVoice(void *);

/* Resets the sound driver's voices and channels: both voice lists are cleared
 * and all 16 voices parked on the free list, then each of the 32 channels gets
 * an empty voice list and sequence list, a voice limit of 1 and full volume. */
void Sound_InitVoices(void) {
    extern M2C_UNK gActiveVoices, gFreeVoices, gVoicePool, gSoundChannels;
    void ListInit();
    void ListAppend();
    u8 *channel;
    s32 j;
    s32 i;
    u8 *voice;

    ListInit(&gActiveVoices, SOUND_VOICE_LINKS);
    ListInit(&gFreeVoices, SOUND_VOICE_LINKS);
    for (i = 0, voice = (u8 *)&gVoicePool; i < SOUND_VOICE_COUNT; i++, voice += SOUND_VOICE_SIZE) {
        voice[SOUND_VOICE_STATE] = 0;
        voice[SOUND_VOICE_CHANNEL] = i;
        ListAppend(&gFreeVoices, voice);
    }
    for (j = 0, channel = (u8 *)&gSoundChannels; j < SOUND_CHANNEL_COUNT; j++, channel += SOUND_CHANNEL_SIZE) {
        ListInit(channel + SOUND_CHANNEL_VOICE_LIST, SOUND_CHANNEL_VOICE_LINKS);
        ListInit(channel + SOUND_CHANNEL_SEQ_LIST, 0);
        channel[SOUND_CHANNEL_VOLUME] = SOUND_VOLUME_MAX;
        M2C_FIELD(channel, s32 *, SOUND_CHANNEL_VOICE_LIMIT) = 1;
        M2C_FIELD(channel, s32 *, SOUND_CHANNEL_UNK_1C) = 0;
    }
}

/* Per-frame driver voice update (func_0202a9f0): start each pending voice once
 * its start command has been processed by the ARM7, drop voices whose hardware
 * channel the ARM7 no longer reports, fold the channel, voice and envelope levels
 * into each voice's channel volume and release the voices whose fade-out ended. */
void Sound_UpdateVoices(void) {
    s32 func_02009800(void);
    void *ListNext(void *, s32);
    s32 Sound_IsCommandReached(void *);
    M2C_UNK func_02008c38(u8, s32);
    void func_02008c18(u8);
    void Sound_RecycleVoice(void *);
    void AdvanceFade(void *);
    s32 GetFadeValue(void *);
    s32 IsFadeDone(void *);
    void Sound_ReleaseVoice(void *);
    extern M2C_UNK gActiveVoices;
    extern s16 gSoundVoiceVolumeTable[];
    s32 channelStatus;
    void *voice;
    void *nextVoice;
    s32 volumeFloor;
    channelStatus = func_02009800();
    voice = ListNext(&gActiveVoices, 0);
    if (voice == 0) {
        return;
    }
    volumeFloor = -0x8000;
    do {
        nextVoice = ListNext(&gActiveVoices, voice);
        if (M2C_FIELD(voice, u8 *, SOUND_VOICE_STARTED) == 0) {
            if (Sound_IsCommandReached(M2C_FIELD(voice, void **, SOUND_VOICE_START_MARK))) {
                M2C_FIELD(voice, u8 *, SOUND_VOICE_STARTED) = 1;
            }
        }
        if (M2C_FIELD(voice, u8 *, SOUND_VOICE_STARTED) != 0 &&
            !(channelStatus & (1 << M2C_FIELD(voice, u8 *, SOUND_VOICE_CHANNEL)))) {
            Sound_RecycleVoice(voice);
            goto next;
        }
        AdvanceFade((u8 *)voice + SOUND_VOICE_ENVELOPE);
        {
            void *channelBase = M2C_FIELD(voice, void **, SOUND_VOICE_CHANNEL_BASE);
            u8 expression = M2C_FIELD(voice, u8 *, SOUND_VOICE_EXPRESSION);
            u8 channelVolume = M2C_FIELD(channelBase, u8 *, SOUND_CHANNEL_VOLUME);
            u8 volume = M2C_FIELD(voice, u8 *, SOUND_VOICE_VOLUME);
            s32 expressionValue = gSoundVoiceVolumeTable[expression];
            s32 volumeValue = gSoundVoiceVolumeTable[volume];
            s32 channelValue = gSoundVoiceVolumeTable[channelVolume];
            s32 envelope = GetFadeValue((u8 *)voice + SOUND_VOICE_ENVELOPE);
            s32 voiceValue = volumeValue + expressionValue;
            s32 envelopeValue = gSoundVoiceVolumeTable[envelope >> 8];
            s32 total = channelValue + voiceValue;
            s32 newVolume = envelopeValue + total;
            if (newVolume < volumeFloor) {
                newVolume = volumeFloor;
            } else if (newVolume > 0x7FFF) {
                newVolume = 0x7FFF;
            }
            if (newVolume != M2C_FIELD(voice, s16 *, SOUND_VOICE_LAST_VOLUME)) {
                func_02008c38(M2C_FIELD(voice, u8 *, SOUND_VOICE_CHANNEL), newVolume);
                M2C_FIELD(voice, s16 *, SOUND_VOICE_LAST_VOLUME) = (s16) newVolume;
            }
        }
        if (M2C_FIELD(voice, u8 *, SOUND_VOICE_STATE) == 2) {
            if (IsFadeDone((u8 *)voice + SOUND_VOICE_ENVELOPE)) {
                Sound_ReleaseVoice(voice);
            }
        }
        if (M2C_FIELD(voice, u8 *, SOUND_VOICE_STOP_PENDING)) {
            func_02008c18(M2C_FIELD(voice, u8 *, SOUND_VOICE_CHANNEL));
            M2C_FIELD(voice, u8 *, SOUND_VOICE_STOP_PENDING) = 0;
        }
    next:
        voice = nextVoice;
    } while (nextVoice != 0);
}

/* Gives a player a driver voice on one of its channels: detaches the voice the
 * player already holds, frees the channel's lowest-priority voice when the
 * channel is full and the request's priority allows it, allocates a voice of
 * that priority, inserts it into the channel's priority-ordered list and links
 * it to the player.  Returns the voice, or NULL when the channel is full of
 * higher-priority voices or no voice can be taken. */
void *Sound_AcquireVoice(void *player, s32 channel, s32 priority) {
    extern M2C_UNK gSoundChannels;
    void *ListNext();
    void *Sound_AllocVoice();
    void func_0202acbc();
    void Sound_ReleaseVoice(void *);
    M2C_UNK Sound_InsertChannelVoice(M2C_UNK *, void *);
    void *previous = M2C_FIELD(player, void **, SOUND_PLAYER_VOICE);
    void *channelVoices = (u8 *)&gSoundChannels + channel * SOUND_CHANNEL_SIZE;
    void *voice;

    if (previous) func_0202acbc(player);
    if (M2C_FIELD(channelVoices, u16 *, SOUND_LIST_COUNT) >= M2C_FIELD(channelVoices, u32 *, SOUND_CHANNEL_VOICE_LIMIT)) {
        voice = ListNext(channelVoices, 0);
        if (!voice) return 0;
        if (priority < M2C_FIELD(voice, u8 *, SOUND_VOICE_PRIORITY)) return 0;
        Sound_ReleaseVoice(voice);
    }
    voice = Sound_AllocVoice(priority);
    if (!voice) return 0;
    Sound_InsertChannelVoice(channelVoices, voice);
    M2C_FIELD(voice, void **, SOUND_VOICE_PLAYER) = player;
    M2C_FIELD(player, void **, SOUND_PLAYER_VOICE) = voice;
    return voice;
}

void Sound_FreeVoice(void) {
    void Sound_RecycleVoice();
    Sound_RecycleVoice();
}

void Sound_StartSequence(void *a){
void func_0202b1ac(void *);void func_02008bf0();void func_02008ca0();s32 Sound_GetCommandCounter();void *p=M2C_FIELD(a,void **,4);
func_02008bf0(M2C_FIELD(a,u8 *,60));if(M2C_FIELD(p,s32 *,28))func_02008ca0(M2C_FIELD(a,u8 *,60),65535,M2C_FIELD(p,s32 *,28));
func_0202b1ac(a);M2C_FIELD(a,s32 *,48)=Sound_GetCommandCounter();M2C_FIELD(a,u8 *,47)=1;M2C_FIELD(a,u8 *,44)=1;
}

void func_0202b10c(void *a,s32 b){void Sound_ReleaseVoice(void *);M2C_UNK func_0202eed8(void *,M2C_UNK,M2C_UNK);void Sound_SetVoicePriority(void *,s8);if(!a||!M2C_FIELD(a,u8 *,44))return;if(!b){Sound_ReleaseVoice(a);return;}func_0202eed8(a+28,0,b);Sound_SetVoicePriority(a,0);M2C_FIELD(a,u8 *,44)=2;}

void *Sound_LinkVoiceChannel(s32 a,void *b){extern M2C_UNK gSoundChannels;void *ListNext();M2C_UNK ListRemove();M2C_UNK Sound_FreeAllBlocks();void *p=(u8 *)&gSoundChannels+a*36;void *q=ListNext(p+12,0);if(!q)return 0;ListRemove(p+12,q);M2C_FIELD(q,void **,12)=b;M2C_FIELD(b,void **,8)=q;Sound_FreeAllBlocks(M2C_FIELD(q,void **,8));return M2C_FIELD(q,void **,8);}

void func_0202b1ac(void *arg0) {
    M2C_UNK func_0202eec0(void *);
    M2C_UNK func_0202eed8(void *, M2C_UNK, M2C_UNK);
    M2C_FIELD(arg0, s8 *, 0x2E) = 0;
    M2C_FIELD(arg0, s8 *, 0x2D) = 0;
    M2C_FIELD(arg0, s8 *, 0x2F) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s8 *, 0x40) = 0x7F;
    M2C_FIELD(arg0, s8 *, 0x41) = 0x7F;
    func_0202eec0(arg0 + 0x1C);
    func_0202eed8(arg0 + 0x1C, 0x7F00, 1);
}

M2C_UNK Sound_InsertChannelVoice(M2C_UNK *a,void *b){void *ListNext();M2C_UNK ListInsertBefore();void *p=ListNext(a,0);while(p){if(M2C_FIELD(b,u8 *,61)<M2C_FIELD(p,u8 *,61))break;p=ListNext(a,p);}ListInsertBefore(a,p,b);M2C_FIELD(b,void **,4)=a;}

M2C_UNK Sound_InsertActiveVoice(void *a){extern M2C_UNK gActiveVoices;void *ListNext();M2C_UNK ListInsertBefore();void *p=ListNext(&gActiveVoices,0);while(p){if(M2C_FIELD(a,u8 *,61)<M2C_FIELD(p,u8 *,61))break;p=ListNext(&gActiveVoices,p);}ListInsertBefore(&gActiveVoices,p,a);}

void Sound_ReleaseVoice(void *arg0) {
    M2C_UNK func_02008bd0(u8);
    M2C_UNK func_02008c38(u8, s32);
    if (M2C_FIELD(arg0, u8 *, 0x2C) == 2) {
        func_02008c38(M2C_FIELD(arg0, u8 *, 0x3C), 0xFFFFFD2D);
    }
    func_02008bd0(M2C_FIELD(arg0, u8 *, 0x3C));
    Sound_RecycleVoice(arg0);
}

/* Take a voice of at least `priority`: the first free voice, or the lowest-priority
 * active voice when none is free (which is released for reuse).  Returns the voice
 * with its priority set, or NULL when every active voice outranks the request. */
void *Sound_AllocVoice(s32 priority) {
    void *ListNext();
    M2C_UNK ListRemove();
    M2C_UNK Sound_InsertActiveVoice(void *);
    void Sound_ReleaseVoice(void *);
    extern M2C_UNK gFreeVoices, gActiveVoices;
    void *voice = ListNext(&gFreeVoices, 0);

    if (!voice) {
        voice = ListNext(&gActiveVoices, 0);
        if (priority < M2C_FIELD(voice, u8 *, SOUND_VOICE_PRIORITY)) return 0;
        Sound_ReleaseVoice(voice);
    }
    ListRemove(&gFreeVoices, voice);
    M2C_FIELD(voice, u8 *, SOUND_VOICE_PRIORITY) = priority;
    Sound_InsertActiveVoice(voice);
    return voice;
}

/* Detaches a driver voice from its player and channel and returns it to the
 * free voice list, marked free: the player forgets the voice, the voice leaves
 * the channel's voice list and the channel heap it holds goes back on the
 * channel's sequence list. */
void Sound_RecycleVoice(void *voice) {
    M2C_UNK ListRemove();
    void ListAppend();
    extern M2C_UNK gActiveVoices, gFreeVoices;
    void *player = M2C_FIELD(voice, void **, SOUND_VOICE_PLAYER);
    void *channel;

    if (player) {
        M2C_FIELD(player, s32 *, SOUND_PLAYER_VOICE) = 0;
        M2C_FIELD(voice, s32 *, SOUND_VOICE_PLAYER) = 0;
    }
    channel = M2C_FIELD(voice, void **, SOUND_VOICE_CHANNEL_BASE);
    ListRemove(channel, voice);
    M2C_FIELD(voice, s32 *, SOUND_VOICE_CHANNEL_BASE) = 0;
    if (M2C_FIELD(voice, void **, SOUND_VOICE_HEAP)) {
        ListAppend((u8 *)channel + SOUND_CHANNEL_SEQ_LIST, M2C_FIELD(voice, void **, SOUND_VOICE_HEAP));
        M2C_FIELD(M2C_FIELD(voice, void **, SOUND_VOICE_HEAP), s32 *, SOUND_CHANNEL_HEAP_OWNER) = 0;
        M2C_FIELD(voice, s32 *, SOUND_VOICE_HEAP) = 0;
    }
    ListRemove(&gActiveVoices, voice);
    ListAppend(&gFreeVoices, voice);
    M2C_FIELD(voice, u8 *, SOUND_VOICE_STATE) = 0;
}

void Sound_FreeChannelHeap(void *arg0) {
    M2C_UNK Sound_DestroyHeap();
    extern M2C_UNK gSoundChannels;
    void *temp_r1;

    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        return;
    }
    Sound_DestroyHeap();
    temp_r1 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = 0;
        return;
    }
    ListRemove((M2C_FIELD(arg0, s32 *, 0x10) * 0x24) + (s32) &gSoundChannels + 0xC, arg0);
}

/* Give a voice a new priority: detach it from its channel's voice list and the
 * active-voice list, store the priority, then re-insert it into both lists in
 * priority order. */
void Sound_SetVoicePriority(void *voice, s8 priority) {
    M2C_UNK Sound_InsertChannelVoice(M2C_UNK *, void *);
    M2C_UNK Sound_InsertActiveVoice(void *);
    extern M2C_UNK gActiveVoices;
    M2C_UNK *channel;

    channel = M2C_FIELD(voice, M2C_UNK **, SOUND_VOICE_CHANNEL_BASE);
    if (channel != NULL) {
        ListRemove(channel, voice);
        M2C_FIELD(voice, M2C_UNK **, SOUND_VOICE_CHANNEL_BASE) = NULL;
    }
    ListRemove(&gActiveVoices, voice);
    M2C_FIELD(voice, s8 *, SOUND_VOICE_PRIORITY) = priority;
    if (channel != NULL) {
        Sound_InsertChannelVoice(channel, voice);
    }
    Sound_InsertActiveVoice(voice);
}

/* Initialise a sound player object: set up the playing-voice list on first use,
 * install the player's stop and release hooks (both handed the player back),
 * clear its channel mask and note count and mark it as neither playing nor
 * holding hardware channels. */
void Sound_InitPlayer(void *a) {
    void ListInit(M2C_UNK *, s32);
    void func_0202b9d0(void *);
    s32 Sound_ResumePlayer(void *);
    extern M2C_UNK gPlayingVoicesReady, gPlayingVoices;

    if (!gPlayingVoicesReady) {
        ListInit(&gPlayingVoices, 0);
        gPlayingVoicesReady = 1;
    }
    M2C_FIELD(a, void (**)(void *), SOUND_PLAYER_STOP_CB) = func_0202b9d0;
    M2C_FIELD(a, void **, SOUND_PLAYER_STOP_DATA) = a;
    M2C_FIELD(a, s32 (**)(void *), SOUND_PLAYER_RELEASE_CB) = Sound_ResumePlayer;
    M2C_FIELD(a, void **, SOUND_PLAYER_RELEASE_DATA) = a;
    M2C_FIELD(a, s32 *, SOUND_PLAYER_CHANNEL_MASK) = 0;
    M2C_FIELD(a, s32 *, SOUND_PLAYER_NOTE_COUNT) = 0;
    M2C_FIELD(a, u32 *, SOUND_PLAYER_FLAGS) &= ~SOUND_PLAYER_FLAG_PLAYING;
    M2C_FIELD(a, u32 *, SOUND_PLAYER_FLAGS) &= ~SOUND_PLAYER_FLAG_CHANNELS;
}

/* Give the player the `count` hardware channels listed in `channels`: store them
   as its note list, build their bit mask and reserve it with the sound driver.
   Returns 0 (leaving the player unchanged) when a channel is already taken. */
s32 Sound_AssignPlayerChannels(void *player, s32 count, u8 *channels) {
    s32 Sound_ReserveChannels(s32);
    s32 mask = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        M2C_FIELD(player + i, u8 *, SOUND_PLAYER_NOTES) = channels[i];
        mask |= 1 << channels[i];
    }
    if (!Sound_ReserveChannels(mask)) return 0;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT) = count;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_CHANNEL_MASK) = mask;
    return 1;
}

void Sound_StopVoices(void *arg0) {
    M2C_UNK func_0202aaac();
    if (M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        return;
    }
    func_0202aaac();
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Starts one sound voice: splits its sample data into segments, loads each
 * note's channel start address and sound registers, installs the segment timer
 * callback, links the voice into the playing list and kicks off the first
 * segment with interrupts off. */
s32 Sound_StartVoice(void *player, s32 playMode, s32 sampleData, s32 channelBytes, s32 rate, s32 segments, s32 segmentCallback, s32 callbackArg) {
    extern M2C_UNK gPlayingVoices;
    void Sound_StopIfPlaying(void *);
    s32 U32DivideRem(s32, s32);
    s32 Sound_AllocChannel(void);
    void func_02008e44(s32, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    void func_02008d54(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void ListAppend(M2C_UNK, void *);
    s32 OS_DisableInterrupts(void);
    M2C_UNK Sound_StartSegment(M2C_UNK, M2C_UNK);
    M2C_UNK OS_RestoreInterrupts(s32);
    void Sound_AdvanceVoice(M2C_UNK);

    s32 timerPeriod;
    s32 hwChannel;
    s32 irqState;
    register s32 *channelInfo;
    register s32 noteIndex;

    if ((M2C_FIELD(player, s32 *, SOUND_PLAYER_FLAGS) << 31) >> 31) {
        Sound_StopIfPlaying(player);
    }
        {
            s32 r2 = M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT);
            s32 q = U32DivideRem(channelBytes, r2 * (segments << 5));
            M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES) = q * segments << 5;
            {
                s32 r0 = M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES);
                if (playMode == SOUND_PLAY_MODE_HALF) {
                    r0 = (s32)((u32)r0 >> 1);
                }
                timerPeriod = U32DivideRem(rate * r0, segments);
            }
        }
        hwChannel = Sound_AllocChannel();
        M2C_FIELD(player, s32 *, SOUND_PLAYER_HW_CHANNEL) = hwChannel;
        if (hwChannel < 0) {
            return 0;
        }

    noteIndex = 0;
    if (M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT) > 0) {
        s32 rateShifted;
        s32 zero;
        channelInfo = gSoundChannelSampleState;
        rateShifted = rate << 5;
        zero = noteIndex;
        do {
            u8 ch = *((u8 *)player + noteIndex + SOUND_PLAYER_NOTES);
            s32 val = M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES) * noteIndex + sampleData;
            ((s32 (*)[2])channelInfo)[ch][0] = val;
            ((s32 (*)[2])channelInfo)[ch][1] = zero;
            func_02008e44(ch, playMode, ((s32 (*)[2])channelInfo)[ch][0], 1, zero, (u32)M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES) >> 2, 0x7F, zero, rateShifted, 0x40);
            noteIndex++;
        } while (noteIndex < M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT));
    }

    func_02008d54(M2C_FIELD(player, s32 *, SOUND_PLAYER_HW_CHANNEL), timerPeriod, timerPeriod, (M2C_UNK)Sound_AdvanceVoice, (s32)player);
    ListAppend(&gPlayingVoices, player);
    M2C_FIELD(player, s32 *, SOUND_PLAYER_PLAY_MODE) = playMode;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_SEGMENTS) = segments;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_SEGMENT_CB) = segmentCallback;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_CB_ARG) = callbackArg;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_CURRENT_SEGMENT) = 0;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_VOLUME) = 0;
    M2C_FIELD(player, u32 *, SOUND_PLAYER_FLAGS) = (M2C_FIELD(player, u32 *, SOUND_PLAYER_FLAGS) & ~1u) | 1u;

    irqState = OS_DisableInterrupts();
    M2C_FIELD(player, s32 *, SOUND_PLAYER_SEGMENTS) = 1;
    Sound_StartSegment((M2C_UNK)player, 0);
    M2C_FIELD(player, s32 *, SOUND_PLAYER_SEGMENTS) = segments;
    OS_RestoreInterrupts(irqState);

    return 1;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
s32 func_0202b70c(void *arg0) {
    M2C_UNK func_02008cc8(s32, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_0200ee10(void *);
    M2C_UNK func_0200ee28(void *);
    s32 temp_r0;
    s32 temp_r0_2;

    func_02008cc8(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
    temp_r0_2 = (s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F;
    if (temp_r0_2 != 0) {
        return temp_r0_2;
    }
    func_0200ee10(arg0 + 8);
    func_0200ee28(arg0 + 0x14);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x24) | 2;
    M2C_FIELD(arg0, s32 *, 0x24) = temp_r0;
    return temp_r0;
}

void Sound_StopIfPlaying(void *a){void Sound_StopVoice(void *);if(((s32)(M2C_FIELD(a,u32 *,36)<<31)>>31)==0)return;Sound_StopVoice(a);}

/* Set the player's volume and write it to each of the player's channels: compute
 * each channel's hardware volume from the player volume plus the channel's own
 * level and send it to the ARM7. */
void Sound_SetPlayerVolume(void *player, s32 volume) {
    s32 SND_CalcVolume(s32);
    s32 channel;
    s32 value;
    s32 i;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_VOLUME) = volume;
    i = 0;
    if (M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT) <= 0) return;
    do {
        channel = M2C_FIELD(player + i, u8 *, SOUND_PLAYER_NOTES);
        value = SND_CalcVolume(M2C_FIELD(player, s32 *, SOUND_PLAYER_VOLUME) + gSoundChannelSampleState[channel * 2 + 1]);
        func_02008dfc(1 << channel, value & 255, value >> 8);
        i++;
    } while (i < M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT));
}

#pragma opt_common_subs off
void func_0202b7e8(void *a,register s32 b,s32 c){
M2C_UNK func_02008dfc(s32,s32,s32);s32 SND_CalcVolume(s32);extern M2C_UNK data_0213bbd8;
s32 r,lo,mask;
if(b>M2C_FIELD(a,s32 *,72)-1)return;
b=M2C_FIELD(a+b,u8 *,76);M2C_FIELD(&data_0213bbd8,s32 *,b*8)=c;
r=SND_CalcVolume(M2C_FIELD(a,s32 *,60)+c);
func_02008dfc(1<<b,(u8)r,(s32)r>>8);
}
#pragma opt_common_subs on
void Sound_SetChannelVolume(void *arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_02008e24(s32, M2C_UNK);
    if (arg1 > (s32) (M2C_FIELD(arg0, s32 *, 0x48) - 1)) {
        return;
    }
    func_02008e24(1 << M2C_FIELD((arg0 + arg1), u8 *, 0x4C), arg2);
}

/* Stops an active voice, unregisters its sleep hooks and waits for ARM7 before unlinking it. */
void Sound_StopVoice(void *player) {
    M2C_UNK Sound_StopChannels(s32, M2C_UNK, s32, M2C_UNK);
    M2C_UNK PM_DeletePreSleepCallback(void *);
    M2C_UNK PM_DeletePostSleepCallback(void *);
    M2C_UNK Sound_FlushCommands(M2C_UNK);
    M2C_UNK Sound_WaitForCommand(s32);
    s32 Sound_GetCommandCounter();
    s32 commandTag;

    if (((s32)(M2C_FIELD(player, s32 *, SOUND_PLAYER_FLAGS) << 30) >> 31) != 0) {
        Sound_StopChannels(M2C_FIELD(player, s32 *, SOUND_PLAYER_CHANNEL_MASK),
                           0, 1 << M2C_FIELD(player, s32 *, SOUND_PLAYER_HW_CHANNEL), 0);
        PM_DeletePreSleepCallback(player + SOUND_PLAYER_STOP_CB);
        PM_DeletePostSleepCallback(player + SOUND_PLAYER_RELEASE_CB);
        M2C_FIELD(player, s32 *, SOUND_PLAYER_FLAGS) &= ~SOUND_PLAYER_FLAG_CHANNELS;
        commandTag = Sound_GetCommandCounter();
        Sound_FlushCommands(SOUND_FLUSH_BLOCK);
        Sound_WaitForCommand(commandTag);
    }
    Sound_UnlinkPlayingVoice(player);
}

void Sound_UnlinkPlayingVoice(void *arg0) {
    M2C_UNK ListRemove(M2C_UNK *, void *);
    M2C_UNK func_0202ab40(s32);
    extern M2C_UNK gPlayingVoices;
    func_0202ab40(M2C_FIELD(arg0, s32 *, 0x40));
    ListRemove(&gPlayingVoices, arg0);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~1);
}

void Sound_AdvanceVoice(M2C_UNK arg0) {
    M2C_UNK Sound_StartSegment(M2C_UNK, M2C_UNK);
    Sound_StartSegment(arg0, 1);
}

/* Start the player's current sample segment: split its note bytes into one
   chunk per segment, move each hardware channel's sample address on to the
   segment, hand those addresses to the player's segment callback and advance the
   segment index, wrapping to 0 (also the return value) after the last segment. */
M2C_UNK Sound_StartSegment(M2C_UNK arg0, M2C_UNK mode) {
    s32 U32DivideRem(s32, s32);
    void *player = (void *)arg0;
    s32 size, offset, i, next, value;
    size = U32DivideRem(M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES), M2C_FIELD(player, s32 *, SOUND_PLAYER_SEGMENTS));
    offset = size * M2C_FIELD(player, s32 *, SOUND_PLAYER_CURRENT_SEGMENT);
    for (i = 0; i < M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT); i++) {
        value = M2C_FIELD(gSoundChannelSampleState, s32 *, M2C_FIELD(player + i, u8 *, SOUND_PLAYER_NOTES) * SOUND_CHANNEL_STATE_STRIDE);
        value += offset;
        gSoundSegmentOffsets[i] = value;
    }
    M2C_FIELD(player, void (**)(s32, s32, s32 *, s32, s32, s32), SOUND_PLAYER_SEGMENT_CB)(mode, M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_COUNT), gSoundSegmentOffsets, size, M2C_FIELD(player, s32 *, SOUND_PLAYER_PLAY_MODE), M2C_FIELD(player, s32 *, SOUND_PLAYER_CB_ARG));
    i = M2C_FIELD(player, s32 *, SOUND_PLAYER_CURRENT_SEGMENT) + 1;
    M2C_FIELD(player, s32 *, SOUND_PLAYER_CURRENT_SEGMENT) = i;
    next = M2C_FIELD(player, s32 *, SOUND_PLAYER_SEGMENTS);
    if (i >= next) {
        next = 0;
        M2C_FIELD(player, s32 *, SOUND_PLAYER_CURRENT_SEGMENT) = next;
    }
    return next;
}

void func_0202b9d0(void *arg0) {
    M2C_UNK Sound_StopChannels(s32, M2C_UNK, s32, M2C_UNK);
    M2C_UNK Sound_FlushCommands(M2C_UNK);
    M2C_UNK Sound_WaitForCommand(s32);
    s32 Sound_GetCommandCounter();
    s32 temp_r4;

    if (((s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F) == 0) {
        return;
    }
    Sound_StopChannels(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
    temp_r4 = Sound_GetCommandCounter();
    Sound_FlushCommands(1);
    Sound_WaitForCommand(temp_r4);
}

/* Post-sleep resume callback: ends the player's pending sample segments, then
 * re-arms its hardware channels. Returns 0 when the player holds no channels. */
s32 Sound_ResumePlayer(void *player) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 active;
    s32 irqState;

    active = (s32) (M2C_FIELD(player, s32 *, SOUND_PLAYER_FLAGS) << 0x1E) >> 0x1F;
    if (active == 0) {
        return active;
    }
    if (M2C_FIELD(player, s32 *, SOUND_PLAYER_CURRENT_SEGMENT) != 0) {
        do {
            irqState = OS_DisableInterrupts();
            Sound_StartSegment(player, 1);
            OS_RestoreInterrupts(irqState);
        } while (M2C_FIELD(player, s32 *, SOUND_PLAYER_CURRENT_SEGMENT) != 0);
    }
    return func_02008cc8(M2C_FIELD(player, s32 *, SOUND_PLAYER_CHANNEL_MASK), 0, 1 << M2C_FIELD(player, s32 *, SOUND_PLAYER_HW_CHANNEL), 0);
}

void func_0202ba8c(void) {
    extern M2C_UNK gStreamSoundState;
    M2C_FIELD(&gStreamSoundState, s32 *, 0) = 0;
    M2C_FIELD(&gStreamSoundState, s32 *, 0x48) = 0;
}

/* Per-frame volume update of the streamed voice: advances the open voice's fade
 * and, once the fade has run out while a refill is pending, stops the stream;
 * otherwise it writes the fade's volume to the stream's channels as soon as it
 * changes. */
void UpdateStreamVoiceVolume(void){
    void AdvanceFade(void *);s32 IsFadeDone(void *);s32 GetFadeValue(void *);void StopStreamVoice(void);M2C_UNK func_02008dfc();
    extern M2C_UNK gStreamSoundState,gStreamVoice;
    void *voice=&gStreamVoice;
    s32 volume;
    if(!M2C_FIELD(&gStreamSoundState,s32 *,STREAM_STATE_VOICE))return;
    if(M2C_FIELD(voice,s32 *,STREAM_VOICE_ENDED))return;
    AdvanceFade((u8 *)voice+STREAM_VOICE_ENVELOPE);
    if(M2C_FIELD(voice,s32 *,STREAM_VOICE_REFILL)&&IsFadeDone((u8 *)voice+STREAM_VOICE_ENVELOPE)){StopStreamVoice();return;}
    volume=GetFadeValue((u8 *)voice+STREAM_VOICE_ENVELOPE)>>8;
    if(volume==M2C_FIELD(voice,s32 *,STREAM_VOICE_VOLUME))return;
    func_02008dfc(M2C_FIELD(voice,s32 *,STREAM_VOICE_MASK_A),volume,0);
    M2C_FIELD(voice,s32 *,STREAM_VOICE_VOLUME)=volume;
}

/* Stops the streamed sound voice: silences its channel masks, waits for the
 * sound driver to apply the stop, frees the channel allocations and clears the
 * voice. */
void StopStreamVoice(void) {
extern M2C_UNK gStreamSoundState,gStreamVoice,gSoundCommandQueue;
s32 OS_ReceiveMessage(); M2C_UNK func_0202aadc(); M2C_UNK func_0202aaac(); M2C_UNK func_0202ab40(s32); M2C_UNK func_02008f10();
s32 Sound_GetCommandCounter(); M2C_UNK Sound_FlushCommands(M2C_UNK); M2C_UNK Sound_WaitForCommand(s32);
void *voice=&gStreamVoice; s32 channelUsed,mark;
if(!M2C_FIELD(&gStreamSoundState,s32 *,STREAM_STATE_VOICE))return;
channelUsed=M2C_FIELD(voice,s32 *,STREAM_VOICE_CHANNEL)>=0;
Sound_StopChannels(M2C_FIELD(voice,s32 *,STREAM_VOICE_MASK_A),M2C_FIELD(voice,s32 *,STREAM_VOICE_MASK_B),channelUsed?1<<M2C_FIELD(voice,s32 *,STREAM_VOICE_CHANNEL):0,0);
if(channelUsed){mark=Sound_GetCommandCounter();Sound_FlushCommands(1);Sound_WaitForCommand(mark);while(OS_ReceiveMessage(&gSoundCommandQueue,0,0)){}}
if(M2C_FIELD(voice,s32 *,STREAM_VOICE_MASK_B))func_0202aadc(M2C_FIELD(voice,s32 *,STREAM_VOICE_MASK_B));
if(M2C_FIELD(voice,s32 *,STREAM_VOICE_RESERVED))func_0202aaac(M2C_FIELD(voice,s32 *,STREAM_VOICE_RESERVED));
if(channelUsed)func_0202ab40(M2C_FIELD(voice,s32 *,STREAM_VOICE_CHANNEL));
if(M2C_FIELD(voice,s32 *,STREAM_VOICE_ENDED)==1)func_02008f10(0,0,0,0);
M2C_FIELD(voice,s32 *,STREAM_VOICE_ACTIVE)=0;
}

/* Stop the streamed voice's hardware channels and wait for the sound driver to
 * apply the stop; the voice itself stays open. */
void StopStreamChannels(void) {
    M2C_UNK Sound_StopChannels(s32, s32, s32, s32);
    s32 Sound_GetCommandCounter();
    M2C_UNK Sound_FlushCommands(s32);
    M2C_UNK Sound_WaitForCommand(s32);
    extern M2C_UNK gStreamSoundState, gStreamVoice;
    s32 mark;
    void *voice = &gStreamVoice;
    s32 channel;
    if (!M2C_FIELD(&gStreamSoundState, s32 *, STREAM_STATE_VOICE)) return;
    channel = M2C_FIELD(voice, s32 *, STREAM_VOICE_CHANNEL);
    Sound_StopChannels(M2C_FIELD(voice, s32 *, STREAM_VOICE_MASK_A), M2C_FIELD(voice, s32 *, STREAM_VOICE_MASK_B), channel >= 0 ? 1 << channel : 0, 0);
    mark = Sound_GetCommandCounter();
    Sound_FlushCommands(SOUND_FLUSH_BLOCK);
    Sound_WaitForCommand(mark);
}

#pragma opt_common_subs off
void func_0202bc7c(void) {
void CpuFill(s32,s32,s32); void DC_FlushRange(s32,s32); M2C_UNK func_02008cc8();
extern M2C_UNK gStreamSoundState,gStreamVoice;
AudioBufferState *p=(AudioBufferState *)&gStreamVoice;
s32 channel; register s32 dest,size;
if(!M2C_FIELD(&gStreamSoundState,s32 *,72))return;
dest=p->buffer0;
size=p->size;
p->state=0;
CpuFill(0,dest,size);
CpuFill(0,p->buffer1,p->size);
DC_FlushRange(p->buffer0,p->size);
DC_FlushRange(p->buffer1,p->size);
channel=p->channel;
func_02008cc8(p->channel0,p->channel1,channel>=0?1<<channel:0,0);
}
#pragma opt_common_subs on
/* Opens the sound archive whose file path is `path` into `archive`: clears the
 * archive's loaded-section pointers, resolves the path and opens the file range
 * through the archive's own file request, marks the archive open, then loads its
 * sections into `pool` (plus the optional extra section when `loadExtra` is set);
 * on success the archive becomes the current sound archive. */
void Sound_OpenArchive(void *archive, s32 path, s32 pool, s32 loadExtra) {
    M2C_UNK InitFileRequest(void *);
    s32 func_0200b95c(void *, s32);
    s32 OpenFileRange(void *, Unk02BDFileRange);
    s32 LoadResourceArchive(void *, s32, s32);
    extern void *gCurrentArchive;
    M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_DATA_BLOCK) = 0;
    M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_TABLE) = 0;
    M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_FILE) = 0;
    if (!func_0200b95c(archive + SOUND_ARCHIVE_FILE_RANGE, path)) return;
    InitFileRequest(archive + SOUND_ARCHIVE_FILE_REQUEST);
    if (!OpenFileRange(archive + SOUND_ARCHIVE_FILE_REQUEST, M2C_FIELD(archive, Unk02BDFileRange *, SOUND_ARCHIVE_FILE_RANGE))) return;
    M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_OPENED) = 1;
    if (LoadResourceArchive(archive, pool, loadExtra)) gCurrentArchive = archive;
}

