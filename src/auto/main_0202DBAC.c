/* 14 functions from 0x0202DBAC to 0x0202E470 (main), found by ds-decomp. */
#include "common.h"
#include "sound.h"
void Sound_StopPlayer(void *);
void Sound_ReleaseChannel(void *);
void Sound_FreeRequest(M2C_UNK);
void Sound_RemoveRequestsForPlayer(M2C_UNK,void *);

/* Set up and start one sound/music player slot from a sample descriptor:
 * pick the slot, install its callbacks, derive its sample rate and channel
 * count, acquire the channel, then start the voice on the hardware. */
s32 Sound_StartPlayer(void **handle, void *sample, s32 slotIndex, s32 priority, s32 startPos, s32 lengthMs, s32 loopStart, s32 loopEnd, s32 streamCallback, s32 streamArg) {
    void *Sound_AcquirePlayer(void **, s32, s32);
    M2C_UNK Sound_SetPlayerCallbacks(void *, s32);
    void Sound_ReleasePlayer(void *);
    u64 U64Divide(u64, u64);
    void Sound_ResetFade(void *);
    void Sound_StartFade(void *, s32, s32);
    s32 Sound_AcquireChannel(void *, s32, s32);
    u32 U32DivideRem(u32, u32);
    s32 Sound_StartVoice(void *, s32, s32, s32, s32, s32, s32, s32);
    void Sound_ReleaseChannel(void *);
    void Sound_SetChannelVolume(void *, s32, M2C_UNK);
    void Sound_QueueSegment();

    void *player;
    void *pb;
    s32 playMode;
    s32 channels;
    s32 playType;

    player = Sound_AcquirePlayer(handle, slotIndex, priority);
    pb = sample;
    if (player == 0) {
        return 0;
    }
    Sound_SetPlayerCallbacks(player, *(s32 *)pb);
    if (M2C_FIELD(player, s32 (**)(void *, s32), 0x164)(player, *(s32 *)pb) == 0) {
        Sound_ReleasePlayer(player);
        return 0;
    }

    M2C_FIELD(player, s32 *, 0x160) = (s32)U64Divide((u64)(u32)M2C_FIELD(player, u16 *, 0xC4) * (u32)lengthMs, 0x3E8ULL);
    if (M2C_FIELD(player, s32 *, 0x160) != 0 && M2C_FIELD(player, u8 *, 0xC0) == 2) {
        M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) | 0x10;
    } else {
        M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x10;
    }

    M2C_FIELD(player, s32 *, 0x114) = 4;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x20;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x2;
    M2C_FIELD(player, s32 *, 0x118) = 0;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x4;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x8;
    M2C_FIELD(player, s32 *, 0x11C) = 0;
    M2C_FIELD(player, s32 *, 0x134) = loopStart;
    M2C_FIELD(player, s32 *, 0x138) = loopEnd;
    M2C_FIELD(player, s32 *, 0x13C) = streamCallback;
    M2C_FIELD(player, s32 *, 0x140) = streamArg;
    M2C_FIELD(player, s32 *, 0x144) = startPos;
    M2C_FIELD(player, s32 *, 0x15C) = 0;
    M2C_FIELD(player, s32 *, 0x154) = *(u8 *)((u8 *)pb + 4);
    M2C_FIELD(player, s32 *, 0x158) = 0x7F;
    Sound_ResetFade((u8 *)player + 0xE8);
    Sound_StartFade((u8 *)player + 0xE8, 0x7F00, 1);

    playType = M2C_FIELD(player, u8 *, 0xC0);
    switch (playType) { case 0: playMode = 0; break; case 1: case 2: playMode = 1; break; }

    channels = M2C_FIELD(player, u8 *, 0xC2);
    if (*(u8 *)((u8 *)pb + 7) & 0x1) {
        channels = 2;
    }
    if (channels > M2C_FIELD(player, u8 *, 0x124)) {
        channels = M2C_FIELD(player, u8 *, 0x124);
    }
    M2C_FIELD(player, u32 *, 0x110) = (M2C_FIELD(player, u32 *, 0x110) & ~0x40) | ((u32)((channels == 1) << 31) >> 25);

    if (Sound_AcquireChannel(player, channels, (s32)((u8 *)player + 0x126)) == 0) {
        M2C_FIELD(player, void (**)(void *), 0x168)(player);
        Sound_ReleasePlayer(player);
        return 0;
    }

    {
        s32 scaledSize = M2C_FIELD(player, s32 *, 0x130) * channels;
        s32 channelBytes = (s32)U32DivideRem((u32)scaledSize, (u32)M2C_FIELD(player, u8 *, 0x124));
        if (Sound_StartVoice(player, playMode, M2C_FIELD(player, s32 *, 0x12C), channelBytes, M2C_FIELD(player, u16 *, 0xC6), 4, (M2C_UNK)Sound_QueueSegment, (M2C_UNK)player) == 0) {
            Sound_ReleaseChannel(player);
            M2C_FIELD(player, void (**)(void *), 0x168)(player);
            Sound_ReleasePlayer(player);
            return 0;
        }
    }

    if (channels == 2) {
        Sound_SetChannelVolume(player, 0, (M2C_UNK)0);
        Sound_SetChannelVolume(player, 1, (M2C_UNK)0x7F);
    }

    return 1;
}

/* Fades a sound player out to silence over `length` frames and marks it stopping,
 * dropping its priority so a new sound may replace it; stops it at once when it is
 * not playing or no fade length was given. */
void Sound_FadeOutPlayer(void *player, s32 length) {
 void Sound_StopPlayer(void *);
 void Sound_StartFade(void *, s32, s32);
 s32 flags = M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS);
 if (SOUND_HANDLE_FLAG_IS_SET(flags, SOUND_HANDLE_BIT_PLAYING) == 0) {
  Sound_StopPlayer(player);
  return;
 }
 if (length == 0) {
  Sound_StopPlayer(player);
  return;
 }
 Sound_StartFade((u8 *)player + SOUND_HANDLE_FADE, 0, length);
 M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) |= 1 << SOUND_HANDLE_BIT_STOPPING;
 M2C_FIELD(player, s32 *, SOUND_HANDLE_PRIORITY) = 0;
}

/* Stop a sound player: under the sound task's locks, stop the voices if it is
 * playing, close the sample source, and release the player's channels, queued
 * segment requests and slot. */
void Sound_StopPlayer(void *player) {
    M2C_UNK LockMutex(M2C_UNK *);
    M2C_UNK UnlockMutex(M2C_UNK *);
    M2C_UNK Sound_StopIfPlaying(void *);
    M2C_UNK Sound_ReleasePlayerResources(void *);
    extern M2C_UNK gSoundWorkerState;
    extern M2C_UNK gSoundWorkerLock;
    LockMutex(&gSoundWorkerLock);
    if (M2C_FIELD(&gSoundWorkerState, s32 *, SOUND_TASK_STATE_TASK) != 0) {
        LockMutex(M2C_FIELD(&gSoundWorkerState, s32 *, SOUND_TASK_STATE_TASK) + SOUND_TASK_LOCK);
    }
    if (SOUND_HANDLE_FLAG_IS_SET(M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS), SOUND_HANDLE_BIT_PLAYING) != 0) {
        Sound_StopIfPlaying(player);
    }
    if (SOUND_HANDLE_FLAG_IS_SET(M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS), SOUND_HANDLE_BIT_ACTIVE) != 0) {
        M2C_FIELD(player, void (**)(void *), SOUND_HANDLE_CLOSE_CB)(player);
    }
    Sound_ReleasePlayerResources(player);
    UnlockMutex(&gSoundWorkerLock);
    if (M2C_FIELD(&gSoundWorkerState, s32 *, SOUND_TASK_STATE_TASK) == 0) {
        return;
    }
    UnlockMutex(M2C_FIELD(&gSoundWorkerState, s32 *, SOUND_TASK_STATE_TASK) + SOUND_TASK_LOCK);
}

/* Release everything a sound player slot still owns: return its hardware channel,
 * run its release callback, drop its queued segment requests from the global
 * request queue and from the worker task's queue, and detach the player.  Does
 * nothing unless the slot is active. */
M2C_UNK Sound_ReleasePlayerResources(void *player) {
void Sound_RemoveRequestsForPlayer(M2C_UNK,void *); void Sound_ReleasePlayer(void *);
extern M2C_UNK gSoundRequestQueue; extern M2C_UNK gSoundWorkerState;
if(SOUND_HANDLE_FLAG_IS_SET(M2C_FIELD(player,s32 *,SOUND_HANDLE_FLAGS),SOUND_HANDLE_BIT_ACTIVE)==0) return;
Sound_ReleaseChannel(player);
M2C_FIELD(player,void (**)(void *),SOUND_HANDLE_RELEASE_CB)(player);
Sound_RemoveRequestsForPlayer((M2C_UNK)&gSoundRequestQueue,player);
if(M2C_FIELD(&gSoundWorkerState,void **,SOUND_TASK_STATE_TASK)) Sound_RemoveRequestsForPlayer((M2C_UNK)((u8 *)M2C_FIELD(&gSoundWorkerState,void **,SOUND_TASK_STATE_TASK)+SOUND_TASK_REQUEST_QUEUE),player);
Sound_ReleasePlayer(player);
}

s32 Sound_AcquireChannel(void *arg0,s32 arg1,s32 arg2) {
s32 Sound_AssignPlayerChannels(void *,s32,s32);
if(M2C_FIELD(arg0,s32 *,0x120)==0 && Sound_AssignPlayerChannels(arg0,arg1,arg2)==0) return 0;
M2C_FIELD(arg0,s32 *,0x120)++; return 1;
}

void Sound_ReleaseChannel(void *arg0) {
    M2C_UNK Sound_StopVoices();
    s32 temp_r1;
    s32 temp_r1_2;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x120);
    if (temp_r1 == 0) {
        return;
    }
    temp_r1_2 = temp_r1 - 1;
    M2C_FIELD(arg0, s32 *, 0x120) = temp_r1_2;
    if (temp_r1_2 != 0) {
        return;
    }
    Sound_StopVoices();
}

/* Create the sound worker thread inside `worker`: give it `priority`, a
 * SOUND_WORKER_STACK_SIZE-byte stack in the block, the Sound_WorkerThread body
 * and an empty segment-request list and mutex; clear its wait queue and wake it. */
void CreateSoundWorkerTask(void *worker, s32 priority) {
    M2C_UNK TaskCreate(void *, M2C_UNK *, void *, s32, s32, s32);
    M2C_UNK TaskWake(void *);
    M2C_UNK InitMutex(void *);
    M2C_UNK ListInit(void *, M2C_UNK);
    extern M2C_UNK Sound_WorkerThread;
    TaskCreate(worker, &Sound_WorkerThread, worker, worker + SOUND_TASK_WAIT_QUEUE, SOUND_WORKER_STACK_SIZE, priority);
    ListInit(worker + SOUND_TASK_REQUEST_QUEUE, 0);
    InitMutex(worker + SOUND_TASK_LOCK);
    M2C_FIELD(worker, s32 *, SOUND_TASK_WAIT_QUEUE_TAIL) = 0;
    M2C_FIELD(worker, s32 *, SOUND_TASK_WAIT_QUEUE) = 0;
    TaskWake(worker);
}

/* Remove every queued sound-segment request for `player` from `list` and free
 * it.  Interrupts are disabled so the sound task cannot pop a request from under
 * the walk. */
void Sound_RemoveRequestsForPlayer(M2C_UNK list, void *player) {
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(s32);
    void *ListNext(M2C_UNK, M2C_UNK);
    M2C_UNK ListRemove(M2C_UNK, void *);
    s32 saved;
    void *node, *next;

    saved = OS_DisableInterrupts();
    node = ListNext(list, 0);
    while (node) {
        next = ListNext(list, (M2C_UNK)node);
        if (M2C_FIELD(node, void **, SOUND_REQUEST_PLAYER) == player) {
            ListRemove(list, node);
            Sound_FreeRequest((M2C_UNK)node);
        }
        node = next;
    }
    OS_RestoreInterrupts(saved);
}

/* Take the first queued segment request off `list` with interrupts held off, and
 * drop the owning player's queued-request count.  Returns the request, or NULL
 * when the list is empty. */
void *Sound_DequeueRequest(void *list) {
    M2C_UNK ListRemove(M2C_UNK, void *);
    void *ListNext(M2C_UNK, M2C_UNK);
    s32 saved;
    void *request;
    void *player;

    saved = OS_DisableInterrupts();
    request = ListNext((M2C_UNK)list, 0);
    if (request != NULL) {
        ListRemove((M2C_UNK)list, request);
        player = M2C_FIELD(request, void **, SOUND_REQUEST_PLAYER);
        M2C_FIELD(player, s32 *, SOUND_HANDLE_REQUEST_COUNT) = (s32) (M2C_FIELD(player, s32 *, SOUND_HANDLE_REQUEST_COUNT) - 1);
    }
    OS_RestoreInterrupts(saved);
    return request;
}

#pragma opt_common_subs off
/* Take a free segment-request node from the sound request pool with interrupts
 * held off; returns NULL when every node is in use. */
M2C_UNK Sound_AllocRequest(void) {
    extern M2C_UNK gSoundFreeRequests[];
    s32 savedInterrupts;
    M2C_UNK request;

    savedInterrupts = OS_DisableInterrupts();
    request = (M2C_UNK)ListNext((M2C_UNK)gSoundFreeRequests, 0);
    if (request != 0) ListRemove((M2C_UNK)&gSoundFreeRequests, (void *)request);
    OS_RestoreInterrupts(savedInterrupts);
    return request;
}
#pragma opt_common_subs reset
void Sound_FreeRequest(M2C_UNK arg0) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK ListAppend(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gSoundFreeRequests[];
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    ListAppend(gSoundFreeRequests, arg0);
    OS_RestoreInterrupts(temp_r4);
}

/* A sound data block was freed: if it held this player's sample data, stop the
 * player, forget the block and release the voice channels it had acquired. */
void Sound_OnDataBlockFreed(s32 dataBlock, s32 size, void *player) {
M2C_UNK LockMutex(M2C_UNK *); M2C_UNK UnlockMutex(M2C_UNK *); M2C_UNK Sound_StopVoices();
extern M2C_UNK gSoundWorkerState; extern M2C_UNK gSoundWorkerLock;
if(dataBlock!=M2C_FIELD(player,s32 *,SOUND_HANDLE_SAMPLE_DATA)) return;
LockMutex(&gSoundWorkerLock);
if(M2C_FIELD(&gSoundWorkerState,s32 *,SOUND_TASK_STATE_TASK)) LockMutex(M2C_FIELD(&gSoundWorkerState,s32 *,SOUND_TASK_STATE_TASK)+SOUND_TASK_LOCK);
Sound_StopPlayer(player);
M2C_FIELD(player,s32 *,SOUND_HANDLE_SAMPLE_DATA)=0; M2C_FIELD(player,s32 *,SOUND_HANDLE_CHANNEL_BYTES)=0; M2C_FIELD(player,u8 *,SOUND_HANDLE_MAX_CHANNELS)=0;
if(M2C_FIELD(player,s32 *,SOUND_HANDLE_CHANNEL_REFS)>0) {
Sound_StopVoices(player); M2C_FIELD(player,s32 *,SOUND_HANDLE_CHANNEL_REFS)=0;
}
UnlockMutex(&gSoundWorkerLock);
if(!M2C_FIELD(&gSoundWorkerState,s32 *,SOUND_TASK_STATE_TASK)) return;
UnlockMutex(M2C_FIELD(&gSoundWorkerState,s32 *,SOUND_TASK_STATE_TASK)+SOUND_TASK_LOCK);
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
/* A player's segment callback, run when a segment starts: queues a request for
 * the sound worker to fill the segment's note buffers.  When the player already
 * has two requests queued, it first drops the player's oldest request and
 * silences the note buffers that request would have filled. */
void Sound_QueueSegment(s32 mode, s32 noteCount, u8 **buffers, s32 size, s32 playMode, s32 callbackArg) {
    M2C_UNK ListNext(M2C_UNK, M2C_UNK);
    M2C_UNK ListRemove(M2C_UNK, void *);
    void Sound_FreeRequest(M2C_UNK);
    M2C_UNK Sound_AllocRequest(void);
    M2C_UNK ListAppend(M2C_UNK *, M2C_UNK);
    void OS_WakeupThread(void *);
    void MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    extern M2C_UNK gSoundRequestQueue;
    extern M2C_UNK gSoundWorker;
    extern M2C_UNK gSoundWorkerState;

    u8 *player = (u8 *)callbackArg;
    M2C_UNK request;
    void *worker;
    s32 i;

    if (M2C_FIELD(player, s32 *, SOUND_HANDLE_REQUEST_COUNT) >= 2) {
        M2C_UNK oldRequest;
        s32 note;
        oldRequest = ListNext((M2C_UNK)&gSoundRequestQueue, 0);
        while (oldRequest != 0) {
            if (M2C_FIELD(oldRequest, void **, SOUND_REQUEST_PLAYER) == player)
                break;
            oldRequest = ListNext((M2C_UNK)&gSoundRequestQueue, oldRequest);
        }
        note = 0;
        if (M2C_FIELD(oldRequest, s32 *, SOUND_REQUEST_NOTE_COUNT) > 0) {
            do {
                MI_CpuFill8(M2C_FIELD((u8 *)oldRequest + note * 4, u8 **, SOUND_REQUEST_BUFFERS), 0, M2C_FIELD(oldRequest, M2C_UNK *, SOUND_REQUEST_SIZE));
                ++note;
            } while (note < M2C_FIELD(oldRequest, s32 *, SOUND_REQUEST_NOTE_COUNT));
        }
        ListRemove((M2C_UNK)&gSoundRequestQueue, (void *)oldRequest);
        --M2C_FIELD(player, s32 *, SOUND_HANDLE_REQUEST_COUNT);
        Sound_FreeRequest(oldRequest);
    }

    request = Sound_AllocRequest();
    M2C_FIELD(request, void **, SOUND_REQUEST_PLAYER) = player;
    M2C_FIELD(request, s32 *, SOUND_REQUEST_MODE) = mode;
    M2C_FIELD(request, s32 *, SOUND_REQUEST_NOTE_COUNT) = noteCount;
    for (i = 0; i < noteCount; i++) {
        M2C_FIELD((u8 *)request + i * 4, u8 **, SOUND_REQUEST_BUFFERS) = buffers[i];
    }
    M2C_FIELD(request, s32 *, SOUND_REQUEST_SIZE) = size;

    worker = &gSoundWorker;
    if (mode == 0) {
        void *current = M2C_FIELD(&gSoundWorkerState, void **, SOUND_TASK_STATE_TASK);
        if (current != NULL) worker = current;
    }
    *(s32 *)((u8 *)player + SOUND_HANDLE_REQUEST_COUNT) = *(s32 *)((u8 *)player + SOUND_HANDLE_REQUEST_COUNT) + 1;
    ListAppend((M2C_UNK *)((u8 *)worker + SOUND_TASK_REQUEST_QUEUE), request);
    OS_WakeupThread((void *)((u8 *)worker + SOUND_TASK_WAIT_QUEUE));
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
/* Asks the player's segment callback for the next streamed segment, looks the
 * returned sound id up in the archive, restarts the voices with it and
 * recomputes the samples left.  Gives up if the callback or the sound is
 * missing, or if the restart changed the sound kind or the sample rate. */
void Sound_RequestNextSegment(void *player) {
    s32 *GetSoundRecord(s32);
    M2C_UNK Sound_SetPlayerCallbacks(void *, s32);
    u64 U64Divide(u64, u64);
    s32 *sample;
    u8 oldType;
    u16 oldRate;
    s32 segment[4];

    segment[2] = M2C_FIELD(player, s32 *, SOUND_HANDLE_SLOT_INDEX);
    segment[3] = M2C_FIELD(player, s32 *, SOUND_HANDLE_SOUND_ID);
    segment[0] = M2C_FIELD(player, s32 *, SOUND_HANDLE_SOUND_ID);
    segment[1] = 0;
    if (M2C_FIELD(player, s32 (**)(M2C_UNK, s32 *, s32 *, s32), SOUND_HANDLE_SEGMENT_CB)(0, &segment[2], &segment[0], M2C_FIELD(player, s32 *, SOUND_HANDLE_SEGMENT_ARG)) == 0) {
        return;
    }
    sample = GetSoundRecord(segment[0]);
    if (sample == 0) {
        return;
    }
    oldType = M2C_FIELD(player, u8 *, SOUND_HANDLE_TYPE);
    oldRate = M2C_FIELD(player, u16 *, SOUND_HANDLE_RATE);
    M2C_FIELD(player, M2C_UNK (**)(void *), SOUND_HANDLE_RELEASE_CB)(player);
    Sound_SetPlayerCallbacks(player, *sample);
    if (M2C_FIELD(player, s32 (**)(void *, s32), SOUND_HANDLE_START_CB)(player, *sample) == 0) {
        return;
    }
    if (oldRate != M2C_FIELD(player, u16 *, SOUND_HANDLE_RATE)) {
        return;
    }
    if (oldType == 0 && M2C_FIELD(player, u8 *, SOUND_HANDLE_TYPE) != 0) {
        return;
    }
    if (oldType != 0 && M2C_FIELD(player, u8 *, SOUND_HANDLE_TYPE) == 0) {
        return;
    }
    M2C_FIELD(player, s32 *, SOUND_HANDLE_SOUND_ID) = segment[0];
    M2C_FIELD(player, s32 *, SOUND_HANDLE_SAMPLES_LEFT) = (s32)U64Divide((u64)(u32)M2C_FIELD(player, u16 *, SOUND_HANDLE_RATE) * (u32)segment[1], 0x3E8ULL);
    if (M2C_FIELD(player, s32 *, SOUND_HANDLE_SAMPLES_LEFT) != 0 && M2C_FIELD(player, u8 *, SOUND_HANDLE_TYPE) == 2) {
        M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) = (M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) | 0x10);
    } else {
        M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) = (M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) & ~0x10);
    }
    M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) = (M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) & ~0x20);
}

