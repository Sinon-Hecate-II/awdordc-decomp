/* 32 functions from 0x0202CD78 to 0x0202DBAC (main), found by ds-decomp. */
#include "common.h"
#include "sound.h"

s32 func_0202cd78(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 GetLoadedArchiveFile();
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, s32);
    s32 Sound_LoadArchiveFile(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d01c;
    s32 var_r2;
    s32 var_r4;

    var_r4 = GetLoadedArchiveFile();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = Sound_GetCurrentArchive();
        }
        var_r4 = Sound_LoadArchiveFile(arg0, &func_0202d01c, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            SetLoadedArchiveFile(arg0, var_r4);
        }
    }
    return var_r4;
}

s32 func_0202cde4(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 GetLoadedArchiveFile();
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, s32);
    s32 Sound_LoadArchiveFile(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d044;
    s32 var_r2;
    s32 var_r4;

    var_r4 = GetLoadedArchiveFile();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = Sound_GetCurrentArchive();
        }
        var_r4 = Sound_LoadArchiveFile(arg0, &func_0202d044, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            SetLoadedArchiveFile(arg0, var_r4);
        }
    }
    return var_r4;
}

s32 LoadWaveArchiveFile(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 GetLoadedArchiveFile();
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, s32);
    s32 Sound_LoadArchiveFile(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d074;
    s32 var_r2;
    s32 var_r4;

    var_r4 = GetLoadedArchiveFile();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = Sound_GetCurrentArchive();
        }
        var_r4 = Sound_LoadArchiveFile(arg0, &func_0202d074, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            SetLoadedArchiveFile(arg0, var_r4);
        }
    }
    return var_r4;
}

M2C_UNK *LoadWaveArchiveFileWithEntryTable(s32 arg0, s32 arg1, s32 arg2) {
    void *Sound_AllocDataBlock(s32 *, s32, s32, s32, s32);
    s32 Sound_ReadArchiveFile(s32, void *, s32, s32);
    M2C_UNK DC_CleanRange(M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 Sound_GetCurrentArchive();
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, M2C_UNK);
    s32 GetLoadedArchiveFile();
    extern M2C_UNK data_0213c254;
    extern M2C_UNK func_0202d0a4;
    s32 r9 = arg0;
    s32 r8 = arg1;
    s32 r7 = arg2;
    M2C_UNK *r5;
    s32 r6;
    s32 r4;
    s32 r3;
    void *temp_r0;

    r5 = (M2C_UNK *)GetLoadedArchiveFile();
    if (r5 == NULL) {
    }
    if (r5 != NULL) {
        return r5;
    }
    if (Sound_ReadArchiveFile(r9, &data_0213c254, 0x3C, 0) != 0x3C) {
        return NULL;
    }
    r6 = M2C_FIELD(&data_0213c254, s32 *, 0x38) * 4;
    r4 = r6 * 2;
    if (r8 == 0) {
        return NULL;
    }
    if (r7 == 0) {
        r3 = 0;
    } else {
        r3 = Sound_GetCurrentArchive();
    }
    r5 = (M2C_UNK *)Sound_AllocDataBlock(r8, r4 + 0x5C, (s32)&func_0202d0a4, r3, r9);
    if (r5 == NULL) {
        return NULL;
    }
    if (Sound_ReadArchiveFile(r9, r5, r6 + 0x3C, 0) != (r6 + 0x3C)) {
        return NULL;
    }
    temp_r0 = r5 + 0x3C; /* cast ignored? */
    MI_CpuCopy8((M2C_UNK)((u8 *)r5 + 0x3C), (M2C_UNK)((u8 *)r5 + 0x3C + (M2C_FIELD(r5, s32 *, 0x38) * 4)), r6);
    MI_CpuFill8((M2C_UNK)((u8 *)r5 + 0x3C), 0, r6);
    DC_CleanRange(r5, r4 + 0x3C);
    if (r7 != 0) {
        SetLoadedArchiveFile(r9, r5);
    }
    return r5;
}

s32 func_0202cfc4(s32 arg0,s32 arg1,s32 arg2) {
s32 OS_DisableInterrupts();
s32 func_0202c014(s32);
s32 GetLoadedArchiveFile(s32);
s32 SetLoadedArchiveFile(s32,s32);
void OS_RestoreInterrupts(s32);
s32 handle;
s32 saved;
if(!arg1)return;
saved=OS_DisableInterrupts();
handle=func_0202c014(arg1);
if(arg0==GetLoadedArchiveFile(arg2))SetLoadedArchiveFile(arg2,0);
func_0202c014(handle);
OS_RestoreInterrupts(saved);
}

void func_0202d01c(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02008e90(s32, s32);
    M2C_UNK func_0202cfc4(s32, M2C_UNK, M2C_UNK);
    func_0202cfc4(arg0, arg2, arg3);
    func_02008e90(arg0, arg0 + arg1);
}

void func_0202d044(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02008eb0(s32, s32);
    M2C_UNK Link_ClearSlotOwners(s32);
    func_0202cfc4(arg0, arg2, arg3);
    func_02008eb0(arg0, arg0 + arg1);
    Link_ClearSlotOwners(arg0);
}

void func_0202d074(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02008ed0(s32, s32);
    M2C_UNK func_02009aa4(s32);
    func_0202cfc4(arg0, arg2, arg3);
    func_02008ed0(arg0, arg0 + arg1);
    func_02009aa4(arg0);
}

void func_0202d0a4(s32 arg0,s32 arg1,s32 arg2,s32 arg3) {
s32 func_02009aa4(s32);
func_0202cfc4(arg0,arg2,arg3);
func_02009aa4(arg0);
}

void FreeWaveArchiveEntry(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK SetPackedTableEntry(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 GetPackedTableEntry(M2C_UNK, M2C_UNK);
    if (arg0 == GetPackedTableEntry(arg2, arg3)) {
        SetPackedTableEntry(arg2, arg3, 0);
    }
    func_02008ed0(arg0, arg0 + arg1);
}

/* LoadWaveArchiveEntry: give entry `entryIndex` of the wave archive its own
 * buffer, reading that entry's slice of archive file `fileId` into a block from
 * `pool` and recording the pointer in the table.  Returns 1 when the entry is
 * already loaded or was loaded now, 0 when it could not be. */
s32 LoadWaveArchiveEntry(s32 archive, u16 entryIndex, s32 fileId, s32 pool) {
    s32 GetPackedTableEntry(M2C_UNK, M2C_UNK);
    s32 GetPackedTableCount(M2C_UNK);
    void *Sound_AllocDataBlock(s32 *, s32, s32, s32, s32);
    s32 Sound_ReadArchiveFile(s32, void *, s32, s32);
    M2C_UNK DC_CleanRange(M2C_UNK, M2C_UNK);
    M2C_UNK SetPackedTableEntry(M2C_UNK, M2C_UNK, M2C_UNK);
    void FreeWaveArchiveEntry(s32, s32, M2C_UNK, M2C_UNK);
    s32 entryCount;
    s32 size;
    s32 start;
    s32 count;

    if (GetPackedTableEntry((M2C_UNK)archive, entryIndex) != 0) {
        return 1;
    }
    entryCount = GetPackedTableCount((M2C_UNK)archive);
    count = M2C_FIELD(archive, s32 *, WAVE_ARCHIVE_COUNT);
    {
        void *sizeTable;
        s32 end;
        s32 lastIndex = entryCount - 1;
        sizeTable = (void *)(archive + (count + entryIndex) * 4);
        start = M2C_FIELD(sizeTable, s32 *, WAVE_ARCHIVE_ENTRIES);
        if ((u32)entryIndex < (u32)lastIndex) {
            end = M2C_FIELD(sizeTable, s32 *, WAVE_ARCHIVE_ENTRIES + 4);
        } else {
            end = M2C_FIELD(archive, s32 *, WAVE_ARCHIVE_FILE_SIZE);
        }
        size = end - start;
    }
    if (pool == 0) {
        return 0;
    }
    {
        void *buffer;
        buffer = Sound_AllocDataBlock((s32 *)pool, size + 32, (s32)FreeWaveArchiveEntry, archive, entryIndex);
        if (buffer == 0) {
            return 0;
        }
        if (size != Sound_ReadArchiveFile(fileId, buffer, size, start)) {
            return 0;
        }
        DC_CleanRange((M2C_UNK)buffer, size);
        SetPackedTableEntry((M2C_UNK)archive, entryIndex, (M2C_UNK)buffer);
    }
    return 1;
}

/* Load every entry of the wave archive that the sound bank's packed entry table
   references for archive slot `archiveSlot`: for each type-1 record whose wave
   archive slot matches, load that entry (from file `waveFileId`) into `archive`.
   Returns 0 when a load fails, 1 when all are loaded. */
s32 LoadBankWaveArchiveEntries(s32 archive,s32 bankTable,s32 archiveSlot,s32 waveFileId,s32 pool) {
void InitPackedTableCursor(void *);
s32 IteratePackedTableRecord(s32,void *,void *);
s32 LoadWaveArchiveEntry(s32,u16,s32,s32);
PackedBankEntry entry;
u32 iter[2];
u32 initial[2];
void *cursor;
InitPackedTableCursor(initial);
iter[0]=initial[0];iter[1]=initial[1];
cursor=iter;
if(!bankTable)return 0;
if(IteratePackedTableRecord(bankTable,&entry,cursor)) do {
if(entry.type==1 && archiveSlot==entry.waveSlot) {
if(!LoadWaveArchiveEntry(archive,entry.waveEntry,waveFileId,pool))return 0;
}
} while(IteratePackedTableRecord(bankTable,&entry,iter));
return 1;
}

/* Initialise the 32 sound channels from the current sound archive's channel
 * table: store each channel's record values, then preallocate its sequence heaps
 * from `pool`.  Returns 0 if a heap cannot be allocated. */
s32 Sound_InitArchiveChannels(s32 pool) {
void *GetSoundArchiveChannelRecord(s32);
void func_0202ab94(s32,u8);
void func_0202abb4(s32,u16);
s32 Sound_CreateChannelHeap(s32,s32,s32);
s32 i; SoundChannelRecord *rec; s32 j; s32 saved=pool;
Sound_GetCurrentArchive();
for(i=0;i<32;i++) {
rec=GetSoundArchiveChannelRecord(i);
if(rec) {
func_0202ab94(i,rec->count);
func_0202abb4(i,rec->volume);
if(rec->heapSize && saved)
for(j=0;j<rec->count;j++)
if(!Sound_CreateChannelHeap(i,saved,rec->heapSize))return 0;
}
}
return 1;
}

s32 func_0202d330(M2C_UNK arg0, s32 arg1) {
    void *func_0202c03c(s32);
    s32 Sound_PlaySequenceById(M2C_UNK, s32, s32, s32, void *, s32);
    void *temp_r0;

    temp_r0 = func_0202c03c(arg1);
    if (temp_r0 == NULL) {
        return 0;
    }
    return Sound_PlaySequenceById(arg0, M2C_FIELD(temp_r0, u8 *, 9), M2C_FIELD(temp_r0, u16 *, 4), M2C_FIELD(temp_r0, u8 *, 8), temp_r0, arg1);
}

s32 func_0202d378(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
void *func_0202c03c(s32);
s32 Sound_PlaySequenceById(s32,s32,s32,s32,void *,s32);
void *p=func_0202c03c(arg4);
if(!p)return 0;
if(arg3<0)arg3=M2C_FIELD(p,u8 *,8);
if(arg2<0)arg2=M2C_FIELD(p,u16 *,4);
if(arg1<0)arg1=M2C_FIELD(p,u8 *,9);
return Sound_PlaySequenceById(arg0,arg1,arg2,arg3,p,arg4);
}

s32 func_0202d3e8(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 *func_0202c0a0(s32);
    s32 Sound_PlaySequenceEntry(M2C_UNK, s32, s32, s32, void *, s32, s32, s32);
    void *GetSoundArchiveEntry(s32, s32);
    s32 *temp_r0_3;
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0_3 = func_0202c0a0(arg1);
    if (temp_r0_3 == NULL) {
        return 0;
    }
    temp_r0_2 = GetLoadedArchiveFile(*temp_r0_3);
    if (temp_r0_2 == 0) {
        return 0;
    }
    temp_r0 = GetSoundArchiveEntry(temp_r0_2, arg2);
    if (temp_r0 == NULL) {
        return 0;
    }
    return Sound_PlaySequenceEntry(arg0, M2C_FIELD(temp_r0, u8 *, 9), M2C_FIELD(temp_r0, u16 *, 4), M2C_FIELD(temp_r0, u8 *, 8), temp_r0, temp_r0_2, arg1, arg2);
}

/* Play entry `entryIndex` of the loaded sound archive `archiveId` on `player`: a
 * negative channel, bank or priority takes the entry's own value.  Returns 0 when
 * the archive record, the loaded archive or the entry cannot be found. */
s32 Sound_PlayArchiveEntry(s32 player,s32 channel,s32 bankId,s32 priority,s32 archiveId,s32 entryIndex) {
s32 *func_0202c0a0(s32);
void *GetSoundArchiveEntry(s32,s32);
s32 Sound_PlaySequenceEntry(s32,s32,s32,s32,void *,s32,s32,s32);
s32 *record; s32 archive; SoundArchiveEntry *entry;
record=func_0202c0a0(archiveId);
if(!record)return 0;
archive=GetLoadedArchiveFile(*record);
if(!archive)return 0;
entry=GetSoundArchiveEntry(archive,entryIndex);
if(!entry)return 0;
if(priority<0)priority=entry->priority;
if(bankId<0)bankId=entry->bankId;
if(channel<0)channel=entry->channel;
return Sound_PlaySequenceEntry(player,channel,bankId,priority,entry,archive,archiveId,entryIndex);
}

/* Plays sequence `sequenceId` of the current sound archive on `player`: takes a
 * voice for `channel` at `priority`, links it to the channel, loads the entry's
 * bank and the sequence archive, starts the voice on the archive's data block,
 * applies the entry's volume and pan, and records the sequence as the player's
 * sound source.  Returns 1, or 0 when a voice or a resource cannot be taken. */
s32 Sound_PlaySequenceById(s32 player, s32 channel, s32 bankId, s32 priority,
                           void *record, s32 sequenceId) {
    void *Sound_AcquireVoice(void *, s32, s32);
    void *Sound_LinkVoiceChannel(s32, void *);
    s32 LoadSoundBank(void *, s32, s32, s32, s32 *);
    s32 LoadSoundSequence(s32, s32, s32, s32, s32 *);
    void Sound_FreeVoice(void *);
    void Sound_StartSequence();
    void Sound_SetVoiceVolume(void *, s8);
    void Sound_SetChannelPan(void *, s32);
    void Sound_SetSequenceSource(void **, s32);

    register SoundArchiveEntry *entry = record;
    void *voice;
    void *channelList;
    s32 sequenceArchive;
    s32 bank;

    voice = Sound_AcquireVoice((void *)player, channel, priority);
    if (voice == 0) {
        return 0;
    }
    channelList = Sound_LinkVoiceChannel(channel, voice);
    if (LoadSoundBank((void *)bankId, 6, (s32)channelList, 0, &bank) != 0) {
        Sound_FreeVoice(voice);
        return 0;
    }
    if (LoadSoundSequence(sequenceId, 1, (s32)channelList, 0, &sequenceArchive) != 0) {
        Sound_FreeVoice(voice);
        return 0;
    }
    Sound_StartSequence(voice, (void *)((u8 *)sequenceArchive + *(s32 *)((u8 *)sequenceArchive + SOUND_ARCHIVE_DATA_OFFSET)), 0, bank);
    ((void (*)(void *, s32))Sound_SetVoiceVolume)((void *)player, entry->volume);
    Sound_SetChannelPan((void *)player, entry->pan);
    Sound_SetSequenceSource((void **)player, sequenceId);
    return 1;
}

/* Plays entry `entry` of the loaded sound archive `archive` on `player`: takes a
 * voice for player channel `channel` at `priority` (a priority below the voice's
 * own is refused), loads sound bank `bankId` into it, starts the voice on the
 * archive's sequence data, applies the entry's volume and pan, and records the
 * sound (archive id + entry index) on the player so its restart callback can
 * find it again.  Returns 1, or 0 when no voice or no bank could be taken. */
s32 Sound_PlaySequenceEntry(s32 player, s32 channel, s32 bankId, s32 priority,
                            void *entry, s32 archive, s32 archiveId, s32 entryIndex) {
    void *Sound_AcquireVoice(void*,s32,s32);
    void *Sound_LinkVoiceChannel(s32,void*);
    s32 LoadSoundBank();
    void Sound_FreeVoice();
    void Sound_StartSequence();
    void Sound_SetSoundSource();
    void Sound_SetVoiceVolume(void*,s8);
    void Sound_SetChannelPan(void*,s32);

    register SoundArchiveEntry *e = (SoundArchiveEntry *)entry;
    s32 bank;
    void *voice;
    void *list;

    voice = Sound_AcquireVoice((void *)player, channel, priority);
    if (!voice) return 0;
    /* Link the voice into the channel's list, then load the entry's bank. */
    list = Sound_LinkVoiceChannel(channel, voice);
    if (LoadSoundBank(bankId, 6, list, 0, &bank)) {
        Sound_FreeVoice(voice);
        return 0;
    }
    /* Start the voice on the archive's sequence data, then apply the entry's
       volume and pan and record the sound on the player. */
    Sound_StartSequence(voice, archive + M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_DATA_OFFSET), e->soundId, bank);
    ((void (*)(void *, s32))Sound_SetVoiceVolume)((void *)player, e->volume);
    Sound_SetChannelPan((void *)player, e->pan);
    Sound_SetSoundSource(player, archiveId, entryIndex);
    return 1;
}

void Sound_StartWorker(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK InitMutex(M2C_UNK *);
    M2C_UNK InitFileRequest(s32);
    M2C_UNK ListInit(M2C_UNK *, M2C_UNK);
    M2C_UNK ListAppend(M2C_UNK *, s32);
    M2C_UNK func_0202b46c(s32);
    M2C_UNK func_0202d7d8(M2C_UNK);
    M2C_UNK func_0202dfcc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gSoundWorkerState;
    extern M2C_UNK gSoundFreeRequests;
    extern M2C_UNK gSoundDecodeLock;
    extern M2C_UNK gSoundRequestPool;
    extern M2C_UNK gSoundWorker;
    extern u8 gSoundPlayerSlots[];
    extern M2C_UNK data_0213cf00;
    s32 temp_r6;
    s32 var_r5;
    s32 var_r9;

    if (M2C_FIELD(&gSoundWorkerState, s32 *, 0) != 0) {
        func_0202d7d8(arg1);
        return;
    }
    M2C_FIELD(&gSoundWorkerState, s32 *, 0) = 1;
    ListInit(&gSoundFreeRequests, 0);
    var_r9 = 0;
loop_4:
    if (var_r9 < 8) {
        ListAppend(&gSoundFreeRequests, (var_r9 * 0x30) + (s32) &gSoundRequestPool);
        var_r9 += 1;
        goto loop_4;
    }
    InitMutex(&gSoundDecodeLock);
    var_r5 = 0;
    M2C_FIELD(&gSoundWorkerState, M2C_UNK **, 8) = &data_0213cf00;
loop_7:
    if (var_r5 < 4) {
        temp_r6 = (var_r5 * 0x174) + (s32) gSoundPlayerSlots;
        M2C_FIELD(temp_r6, s32 *, 0x110) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x110) & ~1);
        InitFileRequest(temp_r6 + 0x5C);
        func_0202b46c(temp_r6);
        M2C_FIELD(temp_r6, s32 *, 0x148) = var_r5;
        M2C_FIELD(temp_r6, s8 *, 0x124) = 0;
        M2C_FIELD(temp_r6, s32 *, 0x12C) = 0;
        M2C_FIELD(temp_r6, s32 *, 0x130) = 0;
        M2C_FIELD(temp_r6, s32 *, 0x120) = 0;
        var_r5 += 1;
        goto loop_7;
    }
    func_0202d7d8(arg1);
    func_0202dfcc(&gSoundWorker, arg0);
}

s32 func_0202d7d8(s32 heap)
{
    u8 *func_0202c294(s32);
    void *Sound_AllocDataBlock(s32 *, s32, s32, s32, s32);
    void Sound_StopPlayer();
    extern u8 gSoundPlayerSlots[];
    extern M2C_UNK Sound_OnDataBlockFreed;
    s32 zero = 0;
    u8 *player = gSoundPlayerSlots;
    const s32 callback = (s32)&Sound_OnDataBlockFreed;
    s32 slot = 0;
    do {
        u8 *entry = func_0202c294(slot);
        if (entry) {
            s32 channel = zero;
            player[0x124] = entry[0];
            if ((s32)entry[0] > 0) {
                do {
                    u8 value = entry[channel + 1];
                    u8 *dst = player + channel;
                    channel++;
                    dst[0x126] = value;
                } while (channel < entry[0]);
            }
            if (heap) {
                s32 size = player[0x124] << 11;
                s32 handle = (s32)Sound_AllocDataBlock((s32 *)heap, size, callback, (s32)player, zero);
                if (!handle)
                    return 0;
                Sound_StopPlayer(player);
                M2C_FIELD(player, s32 *, 0x12c) = handle;
                M2C_FIELD(player, s32 *, 0x130) = size;
            }
        }
        slot++;
        player += 0x174;
    } while (slot < 4);
    return 1;
}

s32 func_0202d8a0(s32 a,s32 b,s32 c){void *func_0202c1cc(s32);s32 Sound_StartPlayer(s32,void *,s32,s32,s32,s32,s32,s32,s32,s32);void *p=func_0202c1cc(b);if(!p)return 0;return Sound_StartPlayer(a,p,M2C_FIELD(p,u8 *,6),M2C_FIELD(p,u8 *,5),b,c,0,0,0,0);}

s32 func_0202d8fc(s32 arg) {
void * volatile *arg0=(void * volatile *)arg;
void *p;
if (*arg0 == 0) return;
p=*arg0;
return M2C_FIELD(p,s32 *,0x110)|=4;
}

s32 func_0202d91c(M2C_UNK arg0) {
    s32 func_0202d8a0();
    M2C_UNK func_0202d8fc(M2C_UNK);
    if (func_0202d8a0() == 0) {
        return 0;
    }
    func_0202d8fc(arg0);
    return 1;
}

void func_0202d944(volatile s32 *arg0,s32 arg1) {
void func_0202de1c(s32,s32);
if(*arg0==0)return;
func_0202de1c(*arg0,arg1);
}

void func_0202d960(void *volatile *a,s32 b){void func_0202eed8(void *,s32);void *p;if(!*a)return;p=*a;if(((s32)(M2C_FIELD(p,u32 *,0x110)<<28)>>31)!=0)return;func_0202eed8(p+0xe8,b<<8);}

void func_0202d994(volatile s32 *a,s32 b,s32 c){extern s16 data_020e9ca0[];void func_0202b7e8(s32,s32,s16);if(!*a)return;func_0202b7e8(*a,b,data_020e9ca0[c]);}

void func_0202d9c0(s32 *arg0) {
    *arg0 = 0;
}

void Sound_ClearPlayerHandle(void **arg0) {
    void *temp_r2;

    temp_r2 = *arg0;
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, s32 *, 0x14C) = 0;
        *arg0 = NULL;
    }
}

void func_0202d9e4(void) {
void func_0202b70c(void *); void func_0202b77c(void *,s32); void Sound_StopPlayer(void *);
s32 GetFadeValue(void *); void AdvanceFade(void *); s32 IsFadeDone(void *);
extern u8 gSoundPlayerSlots[]; extern s16 data_020e9ca0[];
s32 i; s16 a; s32 b; u8 *p; p=gSoundPlayerSlots; i=0;
do {
s32 flags=M2C_FIELD(p,s32 *,0x110);
if((flags<<31)>>31) {
if(!M2C_FIELD(p,s32 *,0x114))Sound_StopPlayer(p);
else {
if(((flags<<29)>>31) && M2C_FIELD(p,s32 *,0x118)) {
func_0202b70c(p);
M2C_FIELD(p,s32 *,0x110)=(M2C_FIELD(p,s32 *,0x110)|2)&~4;
}
if((M2C_FIELD(p,s32 *,0x110)<<30)>>31) {
AdvanceFade(p+0xe8);
a=data_020e9ca0[M2C_FIELD(p,s32 *,0x154)];
b=data_020e9ca0[M2C_FIELD(p,s32 *,0x158)]+(data_020e9ca0[GetFadeValue(p+0xe8)>>8]+a);
if(b!=M2C_FIELD(p,s32 *,0x15c)){func_0202b77c(p,b); M2C_FIELD(p,s32 *,0x15c)=b;}
if(((M2C_FIELD(p,s32 *,0x110)<<28)>>31) && IsFadeDone(p+0xe8))Sound_StopPlayer(p);
}
}
}
i++;p+=0x174;
}while(i<4);
}

/* Takes the sound player slot at slotIndex for the caller, storing it in *handle
 * (after detaching whatever slot that handle held). The slot is usable only when
 * it has sample data; when it is already active, the sound in it is stopped and
 * replaced unless its priority is above `priority`. Marks the slot active and
 * records its new priority. Returns the slot, or 0 when it cannot be taken. */
void *Sound_AcquirePlayer(void **handle,s32 slotIndex,s32 priority){extern u8 gSoundPlayerSlots[];void Sound_ClearPlayerHandle(void **);void Sound_StopPlayer(void *);void *player;if(*handle)Sound_ClearPlayerHandle(handle);player=gSoundPlayerSlots+slotIndex*SOUND_PLAYER_STRIDE;if(!M2C_FIELD(player,s32 *,SOUND_HANDLE_SAMPLE_DATA))return 0;if(((s32)(M2C_FIELD(player,u32 *,SOUND_HANDLE_FLAGS)<<31)>>31)!=0){if(priority<M2C_FIELD(player,s32 *,SOUND_HANDLE_PRIORITY))return 0;Sound_StopPlayer(player);}M2C_FIELD(player,s32 *,SOUND_HANDLE_PRIORITY)=priority;M2C_FIELD(player,u32 *,SOUND_HANDLE_FLAGS)=(M2C_FIELD(player,u32 *,SOUND_HANDLE_FLAGS)&~1)|1;M2C_FIELD(player,void ***,SOUND_HANDLE_OWNER)=handle;*handle=player;return player;}

void Sound_ReleasePlayer(void *arg0) {
s32 *p=M2C_FIELD(arg0,s32 **,0x14c);
if(p){*p=0;M2C_FIELD(arg0,s32 **,0x14c)=0;}
M2C_FIELD(arg0,u32 *,0x110)&=~1;
M2C_FIELD(arg0,u32 *,0x110)&=~4;
M2C_FIELD(arg0,u32 *,0x110)&=~2;
}

