/* 36 functions from 0x0202AE00 to 0x0202BD7C (main), found by ds-decomp. */
#include "common.h"
#include "sound.h"
void func_0202b338();
typedef struct { u32 words[2]; } Unk02BDFileRange;
typedef struct { s32 pad[3]; s32 buffer0, buffer1, size, unk18, state, unk20, channel0, channel1, channel; } AudioBufferState;
extern s32 gSoundChannelSampleState[];
extern s32 gSoundSegmentOffsets[16];
void func_0202b8e0(void *);

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

void func_0202aeb4(void) {
    s32 func_02009800(void);
    void *ListNext(void *, s32);
    s32 func_02009524(void *);
    M2C_UNK func_02008c38(u8, s32);
    void func_02008c18(u8);
    void func_0202b338(void *);
    void func_0202ef34(void *);
    s32 func_0202ef00(void *);
    s32 func_0202ef4c(void *);
    void func_0202b298(void *);
    extern M2C_UNK gActiveVoices;
    extern s16 data_020e9ca0[];
    s32 r11;
    void *r6;
    void *r7;
    s32 r4;
    r11 = func_02009800();
    r6 = ListNext(&gActiveVoices, 0);
    if (r6 == 0) {
        return;
    }
    r4 = -0x8000;
    do {
        r7 = ListNext(&gActiveVoices, r6);
        if (*(u8 *)((u8 *)r6 + 0x2D) == 0) {
            if (func_02009524(*(void **)((u8 *)r6 + 0x30))) {
                *(u8 *)((u8 *)r6 + 0x2D) = 1;
            }
            if (*(u8 *)((u8 *)r6 + 0x2D) == 0) {
                goto tail;
            }
            if (r11 & (1 << *(u8 *)((u8 *)r6 + 0x3C))) {
                goto tail;
            }
            func_0202b338(r6);
            goto next;
        }
        func_0202ef34((u8 *)r6 + 0x1C);
        {
            void *four = *(void **)((u8 *)r6 + 0x04);
            u8 v41 = *(u8 *)((u8 *)r6 + 0x41);
            u8 fi  = *(u8 *)((u8 *)four + 0x20);
            u8 v40 = *(u8 *)((u8 *)r6 + 0x40);
            s32 r8v = data_020e9ca0[v41];
            s32 r10 = data_020e9ca0[fi];
            s32 r9v = data_020e9ca0[v40];
            s32 ef = func_0202ef00((u8 *)r6 + 0x1C);
            s32 r89 = r9v + r8v;
            s32 pef = data_020e9ca0[ef >> 8];
            s32 r10r = r10 + r89;
            s32 r8final = pef + r10r;
            if (r8final < r4) {
                r8final = r4;
            } else if (r8final > 0x7FFF) {
                r8final = 0x7FFF;
            }
            if (r8final != *(s16 *)((u8 *)r6 + 0x3E)) {
                func_02008c38(*(u8 *)((u8 *)r6 + 0x3C), r8final);
                *(s16 *)((u8 *)r6 + 0x3E) = (s16) r8final;
            }
        }
        if (*(u8 *)((u8 *)r6 + 0x2C) == 2) {
            if (func_0202ef4c((u8 *)r6 + 0x1C)) {
                func_0202b298(r6);
            }
        }
    tail:
        if (*(u8 *)((u8 *)r6 + 0x2F)) {
            func_02008c18(*(u8 *)((u8 *)r6 + 0x3C));
            *(u8 *)((u8 *)r6 + 0x2F) = 0;
        }
    next:
        r6 = r7;
    } while (r7 != 0);
}

void *Sound_AcquireVoice(void *a,s32 b,s32 c){
extern M2C_UNK gSoundChannels;void *ListNext();void *func_0202b2d0();void func_0202acbc();
void func_0202b298(void *);M2C_UNK func_0202b1f4(M2C_UNK *,void *);void *old=M2C_FIELD(a,void **,0);void *p=(u8 *)&gSoundChannels+b*36;void *q;
if(old)func_0202acbc(a);
if(M2C_FIELD(p,u16 *,8)>=M2C_FIELD(p,u32 *,24)){q=ListNext(p,0);if(!q)return 0;if(c<M2C_FIELD(q,u8 *,61))return 0;func_0202b298(q);}
q=func_0202b2d0(c);if(!q)return 0;func_0202b1f4(p,q);M2C_FIELD(q,void **,0)=a;M2C_FIELD(a,void **,0)=q;return q;
}

void Sound_FreeVoice(void) {
    void func_0202b338();
    func_0202b338();
}

void Sound_StartSequence(void *a){
void func_0202b1ac(void *);void func_02008bf0();void func_02008ca0();s32 Sound_GetCommandCounter();void *p=M2C_FIELD(a,void **,4);
func_02008bf0(M2C_FIELD(a,u8 *,60));if(M2C_FIELD(p,s32 *,28))func_02008ca0(M2C_FIELD(a,u8 *,60),65535,M2C_FIELD(p,s32 *,28));
func_0202b1ac(a);M2C_FIELD(a,s32 *,48)=Sound_GetCommandCounter();M2C_FIELD(a,u8 *,47)=1;M2C_FIELD(a,u8 *,44)=1;
}

void func_0202b10c(void *a,s32 b){void func_0202b298(void *);M2C_UNK func_0202eed8(void *,M2C_UNK,M2C_UNK);void func_0202b40c(void *,s8);if(!a||!M2C_FIELD(a,u8 *,44))return;if(!b){func_0202b298(a);return;}func_0202eed8(a+28,0,b);func_0202b40c(a,0);M2C_FIELD(a,u8 *,44)=2;}

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

M2C_UNK func_0202b1f4(M2C_UNK *a,void *b){void *ListNext();M2C_UNK func_02029d18();void *p=ListNext(a,0);while(p){if(M2C_FIELD(b,u8 *,61)<M2C_FIELD(p,u8 *,61))break;p=ListNext(a,p);}func_02029d18(a,p,b);M2C_FIELD(b,void **,4)=a;}

M2C_UNK func_0202b244(void *a){extern M2C_UNK gActiveVoices;void *ListNext();M2C_UNK func_02029d18();void *p=ListNext(&gActiveVoices,0);while(p){if(M2C_FIELD(a,u8 *,61)<M2C_FIELD(p,u8 *,61))break;p=ListNext(&gActiveVoices,p);}func_02029d18(&gActiveVoices,p,a);}

void func_0202b298(void *arg0) {
    M2C_UNK func_02008bd0(u8);
    M2C_UNK func_02008c38(u8, s32);
    if (M2C_FIELD(arg0, u8 *, 0x2C) == 2) {
        func_02008c38(M2C_FIELD(arg0, u8 *, 0x3C), 0xFFFFFD2D);
    }
    func_02008bd0(M2C_FIELD(arg0, u8 *, 0x3C));
    func_0202b338(arg0);
}

void *func_0202b2d0(s32 a){void *ListNext();M2C_UNK ListRemove();M2C_UNK func_0202b244(void *);extern M2C_UNK gFreeVoices,gActiveVoices;void *p=ListNext(&gFreeVoices,0);if(!p){p=ListNext(&gActiveVoices,0);if(a<M2C_FIELD(p,u8 *,61))return 0;func_0202b298(p);}ListRemove(&gFreeVoices,p);M2C_FIELD(p,u8 *,61)=a;func_0202b244(p);return p;}

void func_0202b338(void *a){M2C_UNK ListRemove();void ListAppend();extern M2C_UNK gActiveVoices,gFreeVoices;void *p=M2C_FIELD(a,void **,0);void *list;
if(p){M2C_FIELD(p,s32 *,0)=0;M2C_FIELD(a,s32 *,0)=0;}
list=M2C_FIELD(a,void **,4);ListRemove(list,a);M2C_FIELD(a,s32 *,4)=0;
if(M2C_FIELD(a,void **,8)){ListAppend(list+12,M2C_FIELD(a,void **,8));M2C_FIELD(M2C_FIELD(a,void **,8),s32 *,12)=0;M2C_FIELD(a,s32 *,8)=0;}
ListRemove(&gActiveVoices,a);ListAppend(&gFreeVoices,a);M2C_FIELD(a,u8 *,44)=0;
}

void func_0202b3bc(void *arg0) {
    M2C_UNK func_0202c51c();
    extern M2C_UNK gSoundChannels;
    void *temp_r1;

    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        return;
    }
    func_0202c51c();
    temp_r1 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = 0;
        return;
    }
    ListRemove((M2C_FIELD(arg0, s32 *, 0x10) * 0x24) + (s32) &gSoundChannels + 0xC, arg0);
}

void func_0202b40c(void *arg0, s8 arg1) {
    M2C_UNK func_0202b1f4(M2C_UNK *, void *);
    M2C_UNK func_0202b244(void *);
    extern M2C_UNK gActiveVoices;
    M2C_UNK *temp_r4;

    temp_r4 = M2C_FIELD(arg0, M2C_UNK **, 4);
    if (temp_r4 != NULL) {
        ListRemove(temp_r4, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 4) = NULL;
    }
    ListRemove(&gActiveVoices, arg0);
    M2C_FIELD(arg0, s8 *, 0x3D) = arg1;
    if (temp_r4 != NULL) {
        func_0202b1f4(temp_r4, arg0);
    }
    func_0202b244(arg0);
}

void func_0202b46c(void *a){void ListInit();void func_0202b9d0(void *);s32 func_0202ba1c(void *);extern M2C_UNK data_0213bb84,gPlayingVoices;
if(!data_0213bb84){ListInit(&gPlayingVoices,0);data_0213bb84=1;}
M2C_FIELD(a,void (**)(void *),8)=func_0202b9d0;M2C_FIELD(a,void **,12)=a;
M2C_FIELD(a,s32 (**)(void *),20)=func_0202ba1c;M2C_FIELD(a,void **,24)=a;
M2C_FIELD(a,s32 *,68)=0;M2C_FIELD(a,s32 *,72)=0;
M2C_FIELD(a,u32 *,36)&=~1;M2C_FIELD(a,u32 *,36)&=~2;
}

s32 func_0202b4e4(void *a,s32 n,u8 *p){s32 func_0202aa64(s32);s32 bits=0; s32 i;for(i=0;i<n;i++){M2C_FIELD(a+i,u8 *,76)=p[i];bits|=1<<p[i];}if(!func_0202aa64(bits))return 0;M2C_FIELD(a,s32 *,72)=n;M2C_FIELD(a,s32 *,68)=bits;return 1;}

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
    s32 func_020722fc(s32, s32);
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
            s32 q = func_020722fc(channelBytes, r2 * (segments << 5));
            M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES) = q * segments << 5;
            {
                s32 r0 = M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES);
                if (playMode == SOUND_PLAY_MODE_HALF) {
                    r0 = (s32)((u32)r0 >> 1);
                }
                timerPeriod = func_020722fc(rate * r0, segments);
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
    M2C_FIELD(player, s32 *, SOUND_PLAYER_CHANNEL) = 0;
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

void Sound_StopIfPlaying(void *a){void func_0202b86c(void *);if(((s32)(M2C_FIELD(a,u32 *,36)<<31)>>31)==0)return;func_0202b86c(a);}

void func_0202b77c(void *a,s32 b){s32 func_020098d0(s32);s32 ch;s32 r,i;M2C_FIELD(a,s32 *,60)=b;i=0;if(M2C_FIELD(a,s32 *,72)<=0)return;do{ch=M2C_FIELD(a+i,u8 *,76);r=func_020098d0(M2C_FIELD(a,s32 *,60)+gSoundChannelSampleState[ch*2+1]);func_02008dfc(1<<ch,r&255,r>>8);i++;}while(i<M2C_FIELD(a,s32 *,72));}

#pragma opt_common_subs off
void func_0202b7e8(void *a,register s32 b,s32 c){
M2C_UNK func_02008dfc(s32,s32,s32);s32 func_020098d0(s32);extern M2C_UNK data_0213bbd8;
s32 r,lo,mask;
if(b>M2C_FIELD(a,s32 *,72)-1)return;
b=M2C_FIELD(a+b,u8 *,76);M2C_FIELD(&data_0213bbd8,s32 *,b*8)=c;
r=func_020098d0(M2C_FIELD(a,s32 *,60)+c);
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

void func_0202b86c(void *a){M2C_UNK Sound_StopChannels(s32,M2C_UNK,s32,M2C_UNK);M2C_UNK func_0200ee40(void *);M2C_UNK func_0200ee58(void *);M2C_UNK Sound_FlushCommands(M2C_UNK);M2C_UNK Sound_WaitForCommand(s32);s32 Sound_GetCommandCounter();s32 r;if(((s32)(M2C_FIELD(a,s32 *,36)<<30)>>31)!=0){Sound_StopChannels(M2C_FIELD(a,s32 *,68),0,1<<M2C_FIELD(a,s32 *,64),0);func_0200ee40(a+8);func_0200ee58(a+20);M2C_FIELD(a,s32 *,36)&=~2;r=Sound_GetCommandCounter();Sound_FlushCommands(1);Sound_WaitForCommand(r);}func_0202b8e0(a);}

void func_0202b8e0(void *arg0) {
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
    s32 func_020722fc(s32, s32);
    void *player = (void *)arg0;
    s32 size, offset, i, next, value;
    size = func_020722fc(M2C_FIELD(player, s32 *, SOUND_PLAYER_NOTE_BYTES), M2C_FIELD(player, s32 *, SOUND_PLAYER_SEGMENTS));
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

s32 func_0202ba1c(void *arg0) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 temp_r0;
    s32 temp_r6;

    temp_r0 = (s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F;
    if (temp_r0 == 0) {
        return temp_r0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        do {
            temp_r6 = OS_DisableInterrupts();
            Sound_StartSegment(arg0, 1);
            OS_RestoreInterrupts(temp_r6);
        } while (M2C_FIELD(arg0, s32 *, 0x38) != 0);
    }
    return func_02008cc8(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
}

void func_0202ba8c(void) {
    extern M2C_UNK gStreamSoundState;
    M2C_FIELD(&gStreamSoundState, s32 *, 0) = 0;
    M2C_FIELD(&gStreamSoundState, s32 *, 0x48) = 0;
}

void func_0202baa4(void){void func_0202ef34(void *);s32 func_0202ef4c(void *);s32 func_0202ef00(void *);void StopStreamVoice(void);M2C_UNK func_02008dfc();extern M2C_UNK gStreamSoundState,gStreamVoice;void *p=&gStreamVoice;s32 volume;
if(!M2C_FIELD(&gStreamSoundState,s32 *,72))return;if(M2C_FIELD(p,s32 *,4))return;func_0202ef34(p+60);
if(M2C_FIELD(p,s32 *,76)&&func_0202ef4c(p+60)){StopStreamVoice();return;}
volume=func_0202ef00(p+60)>>8;if(volume==M2C_FIELD(p,s32 *,80))return;func_02008dfc(M2C_FIELD(p,s32 *,36),volume,0);M2C_FIELD(p,s32 *,80)=volume;
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

void func_0202bc1c(void){M2C_UNK Sound_StopChannels(s32,s32,s32,s32);s32 Sound_GetCommandCounter();M2C_UNK Sound_FlushCommands(s32);M2C_UNK Sound_WaitForCommand(s32);extern M2C_UNK gStreamSoundState,gStreamVoice;s32 r;void *p=&gStreamVoice;s32 channel;if(!M2C_FIELD(&gStreamSoundState,s32 *,72))return;channel=M2C_FIELD(p,s32 *,44);Sound_StopChannels(M2C_FIELD(p,s32 *,36),M2C_FIELD(p,s32 *,40),channel>=0?1<<channel:0,0);r=Sound_GetCommandCounter();Sound_FlushCommands(1);Sound_WaitForCommand(r);}

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
void func_0202bd00(void *a,s32 b,s32 c,s32 d){M2C_UNK InitFileRequest(void *);s32 func_0200b95c(void *,s32);s32 OpenFileRange(void *,Unk02BDFileRange);s32 LoadResourceArchive(void *,s32,s32);extern void *gCurrentArchive;
M2C_FIELD(a,s32 *,140)=0;M2C_FIELD(a,s32 *,132)=0;M2C_FIELD(a,s32 *,136)=0;
if(!func_0200b95c(a+124,b))return;InitFileRequest(a+52);
if(!OpenFileRange(a+52,M2C_FIELD(a,Unk02BDFileRange *,124)))return;M2C_FIELD(a,s32 *,48)=1;
if(LoadResourceArchive(a,c,d))gCurrentArchive=a;
}

