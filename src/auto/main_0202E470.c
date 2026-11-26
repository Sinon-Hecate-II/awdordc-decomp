/* 25 functions from 0x0202E470 to 0x0202F37C (main), found by ds-decomp. */
#include "common.h"
#include "sound.h"
#include "fs.h"
#include "wfc.h"
typedef struct { u8 pad[0xd0a];u8 a;u8 b:2;u8 padb:6;u8 c:4;u8 d:2;u8 padd:2; } Config0202ef;
typedef struct { s32 unk_0; s32 unk_4; } Unk0202ed18;
typedef struct {
 void *sp8; s32 spC,sp10;u32 sp14,sp18,sp1C,sp20; s32 sp24;
 u32 sp28; s32 sp2C;u32 sp30;s32 sp34,sp38;void *sp3C;
} AudioWork470;

static inline void Reset470(void *state,void *src) { *(Unk0202ed18 *)state=*(Unk0202ed18 *)src; }
static inline s16 Decode470(void *state,s32 code) {
extern s8 data_020ea780[16];extern s16 data_020ea790[90];
const s16 *steps=data_020ea790;
const s8 *changes=data_020ea780;
s32 delta,step,index,sample;
index=M2C_FIELD(state,u8 *,2);
sample=M2C_FIELD(state,s16 *,0);
step=steps[index];
delta=step>>3;
if(code&4)delta+=step;
if(code&2)delta+=step>>1;
if(code&1)delta+=step>>2;
if(code&8){sample-=delta;if(sample< -32768)sample=-32768;}
else{sample+=delta;if(sample>32767)sample=32767;}
index+=data_020ea780[code];
if(index<0)index=0;else if(index>88)index=88;
M2C_FIELD(state,s16 *,0)=(s16)sample;M2C_FIELD(state,u8 *,2)=index;
return (s16)sample;
}
s32 Sound_OpenFileSource(void *,s32);
void Sound_ReleaseFileSource(s32);
void Sound_ReadFileSource(void *,s32,s32,s32);
void Sound_CloseFileSource(s32);
s32 Sound_OpenMemorySource(void *,s32);
void Sound_ReleaseMemorySource(void);
s32 Sound_ReadMemorySource(void *,s32,s32,s32);
void Sound_CloseMemorySource(void);
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void Sound_FillRequestBuffers(void *arg0) {
    void LockMutex(void *);
    void UnlockMutex(void *);
    M2C_UNK DC_FlushRange(s32, u32);
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    M2C_UNK Sound_RequestNextSegment(void *);
    u32 U32DivideRem(s32, u32);
    extern s8 data_020ea780[16];
    extern s16 data_020ea790[90];
    extern M2C_UNK gSoundWorkerState;
    extern M2C_UNK gSoundDecodeLock;
    void *sp3C;
    s32 sp38;
    s32 sp34;
    u32 sp30;
    s32 sp2C;
    u32 sp28;
    s32 sp24;
    u32 sp20;
    u32 sp1C;
    u32 sp18;
    u32 sp14;
    s32 sp10;
    s32 spC;
    void *sp8;
    M2C_UNK (*temp_r4_2)(s32, s32, void *, u32, s32, s32);
    s16 temp_ip;
    s16 temp_ip_3;
    s16 temp_lr;
    s16 temp_lr_2;
    s16 temp_lr_3;
    s16 temp_r10_2;
    s16 temp_r10_4;
    s16 temp_r1_2;
    s16 temp_r1_3;
    s16 temp_r2_3;
    s16 temp_r2_5;
    s16 temp_r3_4;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r2_2;
    s32 temp_r2_4;
    s32 temp_r2_6;
    s32 temp_r3;
    s32 temp_r3_5;
    s32 temp_r5;
    s32 var_ip;
    s32 var_ip_2;
    s32 var_ip_3;
    s32 var_lr;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r1_5;
    s32 var_r1_6;
    s32 var_r2;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r4;
    s32 var_r4_3;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u32 temp_r0_4;
    u32 temp_r1;
    u32 temp_r2;
    u32 temp_r3_3;
    s32 temp_r4;
    u32 temp_r6;
    u32 var_r1;
    u32 var_r1_2;
    u32 var_r1_4;
    u8 *var_r0;
    u8 *var_r1_3;
    u8 *var_r4_2;
    u8 temp_ip_2;
    u8 temp_r0_5;
    u8 temp_r10;
    u8 temp_r10_3;
    u8 temp_r3_2;
    void *temp_r0;
    void *var_r5;

    sp8 = arg0;
    sp3C = M2C_FIELD(arg0, void **, 8);
    if ((((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x1A) >> 0x1F) != 0) && ((s32) M2C_FIELD(sp3C, volatile s32 *, 0x114) > 0)) {
        M2C_FIELD(sp3C, volatile s32 *, 0x114) = (s32) (M2C_FIELD(sp3C, volatile s32 *, 0x114) - 1);
    }
    temp_r0_2 = M2C_FIELD(sp8, u32 *, 0x2C);
    sp30 = temp_r0_2;
    sp34 = 0;
    if (temp_r0_2 != 0) {
loop_4:
        if (((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x1A) >> 0x1F) != 0) {
            var_r4 = 0;
            if ((s32) M2C_FIELD(sp8, s32 *, 0x10) > 0) {
                do {
                    MI_CpuFill8(M2C_FIELD((sp8 + (var_r4 * 4)), s32 *, 0x14) + sp34, 0, sp30);
                    var_r4 += 1;
                } while (var_r4 < (s32) M2C_FIELD(sp8, s32 *, 0x10));
            }
        } else {
            temp_r4 = M2C_FIELD(sp3C, u32 *, 0xDC);
            temp_r5 = M2C_FIELD(sp3C, s32 *, 0x160);
            temp_r0_3 = U32DivideRem(temp_r5, temp_r4);
            if (temp_r0_3 < (u32) (M2C_FIELD(sp3C, s32 *, 0xD4) - 1)) {
                var_r1 = temp_r4;
                sp2C = M2C_FIELD(sp3C, s32 *, 0xD8);
            } else {
                sp2C = M2C_FIELD(sp3C, s32 *, 0xE0);
                var_r1 = M2C_FIELD(sp3C, u32 *, 0xE4);
            }
            sp20 = sp30;
            sp28 = temp_r5 - (temp_r0_3 * temp_r4);
            if (M2C_FIELD(sp3C, u8 *, 0xC0) != 0) {
                sp20 = sp30 >> 1;
            }
            temp_r3 = M2C_FIELD(sp3C, s32 *, 0x110);
            if (((s32) (temp_r3 << 0x1B) >> 0x1F) != 0) {
                if (sp28 == 0) {
                    M2C_FIELD(sp3C,s32 *,0x110)=temp_r3&~0x10;
                } else {
                    sp20=sp28;
                    sp28=0;
                }
            }
            sp38 = 0;
            if ((u32) (sp28 + sp20) >= var_r1) {
                sp20 = var_r1 - sp28;
                if (temp_r0_3 >= (u32) (M2C_FIELD(sp3C, s32 *, 0xD4) - 1)) {
                    if (M2C_FIELD(sp3C, u8 *, 0xC1) != 0) {
                        sp38 = 1;
                    } else {
                        M2C_FIELD(sp3C, s32 *, 0x110) = (s32) (M2C_FIELD(sp3C, s32 *, 0x110) | 0x20);
                    }
                }
            }
            temp_r3_2 = M2C_FIELD(sp3C, u8 *, 0xC0);
            var_r1_2 = sp28;
            sp1C = sp20;
            switch (temp_r3_2) {                    /* irregular */
            case 0:
                sp18 = sp20;
                break;
            case 1:
                temp_r1 = sp20 * 2;
                sp1C = temp_r1;
                sp18 = temp_r1;
                var_r1_2 = sp28 * 2;
                break;
            case 2:
                temp_r3_3 = var_r1_2 + sp20 + 1;
                var_r1_2 = sp28 >> 1;
                temp_r2 = (temp_r3_3 >> 1) - var_r1_2;
                sp18 = temp_r2;
                if (sp28 == 0) {
                    sp18 = temp_r2 + 4;
                } else {
                    var_r1_2 += 4;
                }
                sp1C *= 2;
                break;
            }
            sp24 = (M2C_FIELD(sp3C, u8 *, 0xC2) * (temp_r0_3 * M2C_FIELD(sp3C, s32 *, 0xD8))) + var_r1_2 + M2C_FIELD(sp3C, s32 *, 0xD0);
            spC = 0;
            if ((s32) M2C_FIELD(sp8, s32 *, 0x10) > 0) {
                var_r5 = sp3C + 0xF8;
                sp14 = sp28 + sp20;
                sp10 = sp28 & 1;
                temp_r6 = sp14 & ~1;
loop_35:
                var_r1_3 = M2C_FIELD((sp8 + (spC * 4)), s32 *, 0x14) + sp34;
                var_r4_2 = var_r1_3;
                if (spC < (s32) M2C_FIELD(sp3C, u8 *, 0xC2)) {
                    if (M2C_FIELD(sp3C, u8 *, 0xC0) == 2) {
                        LockMutex(&gSoundDecodeLock);
                        var_r1_3 = M2C_FIELD(&gSoundWorkerState, u8 **, 8);
                    }
                    if (M2C_FIELD(sp3C, s32 (**)(void *, u8 *, u32, s32), 0x16C)(sp3C, var_r1_3, sp18, (spC * sp2C) + sp24) != sp18) {
                        sp1C = 0;
                        M2C_FIELD(sp3C, s32 *, 0x110) = (s32) (M2C_FIELD(sp3C, s32 *, 0x110) | 0x20);
                        sp20 = 0;
                        sp38 = 0;
                        if (M2C_FIELD(sp3C, u8 *, 0xC0) == 2) {
                            UnlockMutex(&gSoundDecodeLock);
                        }
                    } else {
                        if (M2C_FIELD(sp3C, u8 *, 0xC0) == 2) {
                            var_r1_3 = M2C_FIELD(&gSoundWorkerState, u8 **, 8);
                            var_r0=var_r1_3;
                            if (sp28 == 0) {
                                var_r0 = var_r1_3 + 4;
                                temp_r2_3=M2C_FIELD(var_r1_3,u16 *,0);
                                temp_r1_2=M2C_FIELD(var_r1_3,u16 *,2);
                                M2C_FIELD(var_r5,u16 *,0)=temp_r2_3;
                                M2C_FIELD(var_r5,u16 *,2)=temp_r1_2;
                            }
                            var_r1_4 = sp28;
                            if (sp10 != 0) {
                                M2C_FIELD(var_r4_2,s16 *,0)=Decode470(var_r5,(*var_r0>>4)&15);
                                var_r4_2 += 2;
                                var_r1_4 += 1;
                                var_r0 += 1;
                            }
                            if (var_r1_4 < temp_r6) {
                                do {
                                    M2C_FIELD(var_r4_2,s16 *,0)=Decode470(var_r5,*var_r0&15);
                                    M2C_FIELD(var_r4_2,s16 *,2)=Decode470(var_r5,(*var_r0>>4)&15);
                                    var_r1_4 += 2;
                                    var_r4_2 += 4;
                                    var_r0 += 1;
                                } while (var_r1_4 < temp_r6);
                            }
                            if (var_r1_4 < sp14) {
                                M2C_FIELD(var_r4_2,s16 *,0)=Decode470(var_r5,*var_r0&15);
                            }
                            UnlockMutex(&gSoundDecodeLock);
                        }
                        goto block_118;
                    }
                } else {
                    if (((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x19) >> 0x1F) != 0) {
                        MI_CpuFill8(var_r1_3, 0, sp1C);
                    } else {
                        MI_CpuCopy8(M2C_FIELD(sp8, s32 *, 0x14) + sp34, var_r1_3, sp1C);
                    }
block_118:
                    var_r5 += 4;
                    temp_r0_6 = spC + 1;
                    spC = temp_r0_6;
                    if (temp_r0_6 < (s32) M2C_FIELD(sp8, s32 *, 0x10)) {
                        goto loop_35;
                    }
                }
            }
            temp_r0_7 = M2C_FIELD(sp3C, s32 *, 0x110);
            if (((s32) (temp_r0_7 << 0x1B) >> 0x1F) != 0) {
                M2C_FIELD(sp3C, s32 *, 0x110) = (s32) (temp_r0_7 & ~0x10);
            } else {
                if (sp38 != 0) {
                    var_r1_6 = M2C_FIELD(sp3C, s32 *, 0xC8);
                } else {
                    var_r1_6 = M2C_FIELD(sp3C, s32 *, 0x160) + sp20;
                }
                M2C_FIELD(sp3C, s32 *, 0x160) = var_r1_6;
                sp34 += sp1C;
                sp30 -= sp1C;
                if ((((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x1A) >> 0x1F) != 0) && (M2C_FIELD(sp3C, s32 *, 0x13C) != 0)) {
                    Sound_RequestNextSegment(sp3C);
                }
            }
            if (sp30 != 0) {
                goto loop_4;
            }
        }
    }
    temp_r4_2 = M2C_FIELD(sp3C, M2C_UNK (**)(s32, s32, void *, u32, s32, s32), 0x134);
    if (temp_r4_2 != NULL) {
        if (M2C_FIELD(sp3C, u8 *, 0xC0) == 0) {
            var_r0_3 = 0;
        } else {
            var_r0_3 = 1;
        }
        temp_r4_2(M2C_FIELD(sp8, s32 *, 0xC), M2C_FIELD(sp8, s32 *, 0x10), sp8 + 0x14, M2C_FIELD(sp8, u32 *, 0x2C), var_r0_3, M2C_FIELD(sp3C, s32 *, 0x138));
    }
    var_r4_3 = 0;
    if ((s32) M2C_FIELD(sp8, s32 *, 0x10) > 0) {
        do {
            DC_FlushRange(M2C_FIELD((sp8 + (var_r4_3 * 4)), s32 *, 0x14), M2C_FIELD(sp8, u32 *, 0x2C));
            var_r4_3 += 1;
        } while (var_r4_3 < (s32) M2C_FIELD(sp8, s32 *, 0x10));
    }
    if (M2C_FIELD(sp8, s32 *, 0xC) == 0) {
        M2C_FIELD(sp3C, s32 *, 0x118) = 1;
    }
}

#pragma pop
/* Choose a sound player's sample-data source callbacks: file-backed when the
 * sound's archive entry is not loaded in memory, otherwise direct from the
 * already loaded archive data. */
void Sound_SetPlayerCallbacks(void *player,s32 soundId) {
 if(GetLoadedArchiveFile(soundId)==0) {
 M2C_FIELD(player,void **,SOUND_HANDLE_START_CB)=Sound_OpenFileSource;
 M2C_FIELD(player,void **,SOUND_HANDLE_RELEASE_CB)=Sound_ReleaseFileSource;
 M2C_FIELD(player,void **,SOUND_HANDLE_READ_CB)=Sound_ReadFileSource;
 M2C_FIELD(player,void **,SOUND_HANDLE_CLOSE_CB)=Sound_CloseFileSource;
 } else {
 M2C_FIELD(player,void **,SOUND_HANDLE_START_CB)=Sound_OpenMemorySource;
 M2C_FIELD(player,void **,SOUND_HANDLE_RELEASE_CB)=Sound_ReleaseMemorySource;
 M2C_FIELD(player,void **,SOUND_HANDLE_READ_CB)=Sound_ReadMemorySource;
 M2C_FIELD(player,void **,SOUND_HANDLE_CLOSE_CB)=Sound_CloseMemorySource;
 }
}

/* Reads the sample header and opens a separate file request for streaming its data. */
s32 Sound_OpenFileSource(void *player, s32 fileId) {
    s32 Sound_ReadArchiveFile(u32, void *, u32, u32);
    void Sound_GetArchiveFileRange(FSFileRange *);
    s32 OpenFileRange(void *, FSFileRange);
    s32 Sound_GetArchiveFileOffset(u32);
    FSFileRange archiveRange;

    if (Sound_ReadArchiveFile(fileId, player + SOUND_HANDLE_SOURCE_HEADER, SOUND_SOURCE_HEADER_SIZE, 0)
        != SOUND_SOURCE_HEADER_SIZE)
        return 0;

    Sound_GetArchiveFileRange(&archiveRange);
    if (!OpenFileRange(player + SOUND_HANDLE_FILE_REQUEST, archiveRange))
        return 0;

    M2C_FIELD(player, s32 *, SOUND_HANDLE_SOURCE_BASE) = Sound_GetArchiveFileOffset(fileId);
    return 1;
}

void Sound_ReleaseFileSource(s32 arg0) {
    M2C_UNK CloseFileRequest(s32);
    CloseFileRequest(arg0 + 0x5C);
}

void Sound_ReadFileSource(void *player, M2C_UNK destination, M2C_UNK byteCount, s32 sourceOffset) {
    M2C_UNK FileRead(void *, M2C_UNK, M2C_UNK);
    M2C_UNK FileSeek(void *, s32, M2C_UNK);

    /* Seek within the archive-backed request and stream the requested sample bytes into the caller's buffer. */
    FileSeek(player + SOUND_HANDLE_FILE_REQUEST, M2C_FIELD(player, s32 *, SOUND_HANDLE_SOURCE_BASE) + sourceOffset, 0);
    FileRead(player + SOUND_HANDLE_FILE_REQUEST, destination, byteCount);
}

void Sound_CloseFileSource(s32 arg0) {
    M2C_UNK CancelFileRequest(s32);
    CancelFileRequest(arg0 + 0x5C);
}

/* Open a sound player's sample data straight from the loaded archive memory of
 * sound `soundId`: remember the loaded block as the player's sample base and
 * copy the file's 0x40-byte sample header in front of the data.  Always
 * returns 1. */
s32 Sound_OpenMemorySource(void *player, s32 soundId) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    s32 GetLoadedArchiveFile(s32);
    s32 block;

    block = GetLoadedArchiveFile(soundId);
    M2C_FIELD(player, s32 *, SOUND_HANDLE_SOURCE_BASE) = block;
    MI_CpuCopy8(block, player + SOUND_HANDLE_SOURCE_HEADER, SOUND_SOURCE_HEADER_SIZE);
    return 1;
}

void Sound_ReleaseMemorySource(void) {

}

/* Copy sample data straight from the loaded archive memory of the sound: the
 * block at SOUND_HANDLE_SOURCE_BASE, shifted by `sourceOffset`, into the
 * caller's buffer.  Returns the number of bytes read. */
s32 Sound_ReadMemorySource(void *player, s32 destination, s32 byteCount, s32 sourceOffset) {
    MI_CpuCopy8(M2C_FIELD(player, s32 *, SOUND_HANDLE_SOURCE_BASE) + sourceOffset, destination, byteCount);
    return byteCount;
}

void Sound_CloseMemorySource(void) {

}

#pragma opt_common_subs off
/* Body of the sound worker task: sleep on its wait queue, then, while holding
 * the request-queue mutex, fill each pending segment request and free it. */
void Sound_WorkerThread(void *worker) {
void OS_SleepThread(void *);void LockMutex(void *);void UnlockMutex(void *);void *Sound_DequeueRequest(void *);void Sound_FillRequestBuffers(void *);void Sound_FreeRequest(void *);
void *request;
char *task=(char*)worker; task+=0xC8; /* the queue mutex (SOUND_TASK_LOCK, 0x4C8) is task + 0x400 */
for(;;){OS_SleepThread((char*)worker+SOUND_TASK_WAIT_QUEUE);for(;;){
LockMutex(task+0x400);request=Sound_DequeueRequest((char*)worker+SOUND_TASK_REQUEST_QUEUE);
if(!request){UnlockMutex(task+0x400);break;}
Sound_FillRequestBuffers(request);Sound_FreeRequest(request);UnlockMutex(task+0x400);
}}
}
#pragma opt_common_subs reset
/* Return entry `index` of the loaded sequence-archive file `archive`, or NULL
 * when the index is out of range or the entry is unused. */
void *GetSoundArchiveEntry(void *archive, s32 index) {
    SoundArchiveEntry *entry;

    if (index < 0) return NULL;
    if ((u32)index >= M2C_FIELD(archive, u32 *, SOUND_FILE_ENTRY_COUNT)) return NULL;
    entry = (SoundArchiveEntry *)((u8 *)archive + SOUND_FILE_ENTRIES + index * SOUND_FILE_ENTRY_SIZE);
    if (entry->soundId == SOUND_FILE_ENTRY_NONE) return NULL;
    return entry;
}

void Sound_ResetFade(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

/* Start the fade at `fade`: keep the envelope's current value as the new
 * starting point, ramp it to `target` over `length` ticks and reset the elapsed
 * count. */
void Sound_StartFade(FadeEnvelope *fade, s32 target, s32 length) {
    s32 GetFadeValue(FadeEnvelope *);

    fade->start = GetFadeValue(fade);
    fade->target = target;
    fade->length = length;
    fade->elapsed = 0;
}

/* The fade envelope's current value: `start` plus the elapsed fraction of the
 * ramp to `target`, or `target` once the fade's full length has elapsed. */
s32 GetFadeValue(FadeEnvelope *fade) {
    s32 RuntimeIntDivMod(s32, s32);
    s32 length = fade->length;
    s32 elapsed = fade->elapsed;
    s32 start;

    if (elapsed >= length) return fade->target;
    start = fade->start;
    return start + RuntimeIntDivMod(elapsed * (fade->target - start), length);
}

void AdvanceFade(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r2 < (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r2 + 1);
    }
}

s32 IsFadeDone(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 8) >= (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        return 1;
    }
    return 0;
}

/* Initializes the networked voice-stream session: allocates its state block and
 * working buffers through the caller-supplied allocator callback, clears them,
 * copies the caller's settings into the global session and starts the WFC
 * session. Returns 1 on success, or 0 after tearing the resources down again
 * when the session cannot start. */
s32 WFC_Init(void *params) {
void CpuFill(s32,void *,s32);s32 Wfc_AcquireWorkBlock(s32,M2C_UNK);void FifoReadWfcSaveSlots(void);s32 WFC_InitSession(void *,s32);void Wfc_FreeWorkBlocks(void);
extern M2C_UNK data_0213d100;
void *block,*buffer;Config0202ef *config;s32 status;
block=M2C_FIELD(params,void *(**)(s32,s32),0)(1,24);
M2C_FIELD(&data_0213d100,void **,16)=block;CpuFill(0,block,24);
block=M2C_FIELD(&data_0213d100,void **,16);
M2C_FIELD(block,s32 *,0)=M2C_FIELD(params,s32 *,0);M2C_FIELD(block,s32 *,4)=M2C_FIELD(params,s32 *,4);
M2C_FIELD(block,u8 *,9)=1;M2C_FIELD(block,u8 *,22)=1;M2C_FIELD(block,u8 *,8)=1;
M2C_FIELD(&data_0213d100,s32 *,0)=Wfc_AcquireWorkBlock(16,0xd18);
M2C_FIELD(&data_0213d100,s32 *,4)=Wfc_AcquireWorkBlock(2,0x2300);
M2C_FIELD(&data_0213d100,s32 *,8)=Wfc_AcquireWorkBlock(4,88);
M2C_FIELD(&data_0213d100,s32 *,12)=Wfc_AcquireWorkBlock(8,12);
CpuFill(0,M2C_FIELD(&data_0213d100,void **,0),0xd18);
CpuFill(0,M2C_FIELD(&data_0213d100,void **,4),0x2300);
CpuFill(0,M2C_FIELD(&data_0213d100,void **,8),88);
CpuFill(0,M2C_FIELD(&data_0213d100,void **,12),12);
config=M2C_FIELD(&data_0213d100,Config0202ef **,0);
config->a=M2C_FIELD(params,u8 *,8);config->b=M2C_FIELD(params,u8 *,9);
buffer=M2C_FIELD(&data_0213d100,void **,12);M2C_FIELD(buffer,s32 *,0)=M2C_FIELD(params,s32 *,0);M2C_FIELD(buffer,s32 *,4)=M2C_FIELD(params,s32 *,4);M2C_FIELD(buffer,s32 *,8)=0;
config->c=M2C_FIELD(params,u8 *,10);config->d=M2C_FIELD(params,u8 *,11);
FifoReadWfcSaveSlots();
status=WFC_InitSession(M2C_FIELD(&data_0213d100,void **,4),0x2300);
if(status==1 || status>=4){Wfc_FreeWorkBlocks();return 0;}return 1;
}

/* Drive the WFC connection one step: dispatch on the current session state,
 * publish the state the step moved to, and finish the session when the state
 * reaches 16 (returning the friend-connection result) or 18 (returning -1). */
s32 Wfc_ProcessStep(void) {
    u32 Wfc_GetSessionState();
    u32 Wfc_StepConnect(); u32 Wfc_StepSession(); u32 Wfc_StepFriends();
    u32 Wfc_StepLink(); u32 Wfc_StepMatch(); u32 Wfc_StepWait();
    s32 OS_DisableInterrupts(); void OS_RestoreInterrupts(s32);
    void Wfc_PublishState(u32); s32 Wfc_GetFriendConnectResult(); void Wfc_ClearWorkFlags();
    u32 state = Wfc_GetSessionState(); s32 irq;
    if (state == 1) state = Wfc_StepConnect();
    else if (state < 7) { irq = OS_DisableInterrupts(); state = Wfc_StepSession(); Wfc_PublishState(state); OS_RestoreInterrupts(irq); }
    else if (state < 9) state = Wfc_StepFriends();
    else if (state < 10) state = Wfc_StepLink();
    else if (state < 16) state = Wfc_StepMatch();
    else if (state == 17) state = Wfc_StepWait();
    Wfc_PublishState(state);
    if (state == 16) { irq = Wfc_GetFriendConnectResult(); Wfc_ClearWorkFlags(); return irq; }
    if (state == 18) { Wfc_ClearWorkFlags(); return -1; }
    return 0;
}

/* Turn the current WFC session state into the connection-progress code the UI
 * shows: 0 idle, 1 connecting, 2 searching, 3 connected, 4 linking, 5 finished;
 * a session that is already over reports the matching WFC error code instead. */
s32 GetWfcSessionProgress(void) {
 u32 Wfc_GetSessionState();
 s32 Wfc_GetConnectionErrorCode(u32);
 u32 state=Wfc_GetSessionState();
 if(state<=1)return 0;
 if(state<7)return 1;
 if(state==9)return 4;
 if(state<10)return 2;
 if(state==11)return 4;
 if(state<16)return 3;
 if(state==16)return 5;
 if(state==17)return 4;
 return Wfc_GetConnectionErrorCode(state);
}

/* The friend slot the current WFC session is match-making with, or
 * WFC_FRIEND_SLOT_NONE when there is no control block or the session is not in a
 * match-making state. */
u8 GetWfcFriendSlot(void) {
    u32 Wfc_GetSessionState();
    extern M2C_UNK gWfcManager;
    u32 state;
    u8 slot;

    slot = WFC_FRIEND_SLOT_NONE;
    if (M2C_FIELD(&gWfcManager, void **, 0x10) == NULL) {
        return WFC_FRIEND_SLOT_NONE;
    }
    state = Wfc_GetSessionState();
    if ((state >= 0xAU) && (state <= 0x10U)) {
        slot = M2C_FIELD(M2C_FIELD(&gWfcManager, void **, 0x10), u8 *, WFC_CONTROL_FRIEND_SLOT);
    }
    return slot;
}

/* Ends the WFC session: when the session has not started or is already over,
 * release its work blocks and report that it is done; otherwise advance its
 * state machine one step and publish the new state.  Returns 1 once the session
 * is over (0 while it is still winding down). */
s32 Wfc_EndSession(void) {
    u32 Wfc_GetSessionState();
    void Wfc_FreeWorkBlocks(void);
    void Wfc_AdvanceSessionState(u8 *);
    void Wfc_PublishState(u32);
    u8 state = Wfc_GetSessionState();

    if (state == WFC_SESSION_STATE_NONE || state == WFC_SESSION_STATE_ENDED) {
        Wfc_FreeWorkBlocks();
        return 1;
    }
    Wfc_AdvanceSessionState(&state);
    Wfc_PublishState(state);
    return 0;
}

/* Store one save slot's 0xF0-byte image in the friend roster's copy of it, at
 * slot * WFC_STATE_SLOT_STRIDE of the WFC friends work block. */
void Wfc_SetSlotImage(s32 slotIndex, M2C_UNK slotImage) {
    M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, M2C_UNK);
    s32 Wfc_GetWorkBlock(M2C_UNK);
    MIi_CpuCopy32(slotImage, Wfc_GetWorkBlock(WFC_WORK_FRIENDS) + (slotIndex << 8), SAVE_SLOT_IMAGE_SIZE);
}

/* Claim an owned WFC work block: set `tag`'s bit in the control block's ownership
 * mask and hand the block to the session's allocator callback.  Returns 0 when the
 * bit was already set, otherwise the callback's result. */
s32 Wfc_AcquireWorkBlock(s32 tag, M2C_UNK size) {
    u8 owned;
    void *state;

    state = Wfc_GetWorkBlock(WFC_WORK_CONTROL);
    owned = M2C_FIELD(state, u8 *, WFC_CONTROL_MASK);
    if (owned & tag) {
        return 0;
    }
    M2C_FIELD(state, u8 *, WFC_CONTROL_MASK) = (u8)(owned | tag);
    return M2C_FIELD(state, s32 (**)(s32, M2C_UNK), 0)(tag, size);
}

/* Release an owned WFC work block: clear its bit in the control block's ownership
 * mask and hand the block back to the session's free-block callback. */
void Wfc_ReleaseWorkBlock(s32 tag, void *block, s32 size) {
    WfcAllocationState *state = Wfc_GetWorkBlock(WFC_WORK_CONTROL);
    u8 mask;

    mask = state->ownedMask;
    if (!(mask & tag)) {
        return;
    }
    state->ownedMask = mask & ~tag;
    state->freeBlock(tag, block, size);
}

