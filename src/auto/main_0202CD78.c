/* 32 functions from 0x0202CD78 to 0x0202DBAC (main), found by ds-decomp. */
#include "common.h"
#include "sound.h"

/* Load and cache sound sequence-archive file `fileId`: if it is already loaded
 * return that block, otherwise read it from `pool` with the sequence free
 * callback and, when `create` is set, record the loaded block.  Returns the
 * block, or 0 on failure. */
s32 LoadSoundSequenceArchiveFile(s32 fileId, s32 pool, s32 create) {
    s32 GetLoadedArchiveFile();
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, s32);
    s32 Sound_LoadArchiveFile(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK FreeSequenceArchiveFile;
    s32 freeArg;
    s32 block;

    block = GetLoadedArchiveFile(fileId);
    if (block == 0) {
        if (create == 0) {
            freeArg = 0;
        } else {
            freeArg = Sound_GetCurrentArchive();
        }
        block = Sound_LoadArchiveFile(fileId, &FreeSequenceArchiveFile, freeArg, fileId, pool);
        if ((create != 0) && (block != 0)) {
            SetLoadedArchiveFile(fileId, block);
        }
    }
    return block;
}

/* Loads the sound-archive bank file `fileId` into a fresh block of `pool` unless
 * it is already loaded, and records it in the archive's file table when `create`
 * is set; returns the loaded bank archive, or 0 when it could not be loaded. */
s32 LoadSoundBankArchiveFile(M2C_UNK fileId, s32 pool, s32 create) {
    s32 GetLoadedArchiveFile();
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, s32);
    s32 Sound_LoadArchiveFile(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK FreeBankArchiveFile;
    s32 freeArg;
    s32 archive;

    archive = GetLoadedArchiveFile();
    if (archive == 0) {
        if (create == 0) {
            freeArg = 0;
        } else {
            freeArg = Sound_GetCurrentArchive();
        }
        archive = Sound_LoadArchiveFile(fileId, &FreeBankArchiveFile, freeArg, fileId, pool);
        if ((create != 0) && (archive != 0)) {
            SetLoadedArchiveFile(fileId, archive);
        }
    }
    return archive;
}

/* Load wave archive `fileId` from block pool `pool`: read it into a new block
 * (freed by FreeWaveArchiveFile and owned by the current archive when `cache` is
 * set) and, if `cache` is set, register the block in the archive's file table.
 * Returns the block, or the cached block when it was already loaded. */
s32 LoadWaveArchiveFile(s32 fileId, s32 pool, s32 cache) {
    s32 GetLoadedArchiveFile(s32);
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, s32);
    s32 Sound_LoadArchiveFile(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK FreeWaveArchiveFile;
    s32 archive;
    s32 block;

    block = GetLoadedArchiveFile(fileId);
    if (block == 0) {
        if (cache == 0) {
            archive = 0;
        } else {
            archive = Sound_GetCurrentArchive();
        }
        block = Sound_LoadArchiveFile(fileId, &FreeWaveArchiveFile, archive, fileId, pool);
        if ((cache != 0) && (block != 0)) {
            SetLoadedArchiveFile(fileId, block);
        }
    }
    return block;
}

#pragma opt_common_subs off
/* Loads the wave archive `fileId` whose own file carries its entry table, unless it
 * is already cached.  The file's header sizes the two tables the block keeps: a
 * table of per-entry data pointers (cleared so the entries load lazily) followed by
 * the entry-offset table copied out of the file.  The block is freed by
 * func_0202d0a4 and, when `cache` is set, owned by and registered with the current
 * archive.  Returns the block, or 0 when it could not be loaded. */
M2C_UNK *LoadWaveArchiveFileWithEntryTable(s32 fileId, s32 pool, s32 cache) {
    void *Sound_AllocDataBlock(s32 *, s32, s32, s32, s32);
    s32 Sound_ReadArchiveFile(s32, void *, s32, s32);
    M2C_UNK DC_CleanRange(M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, M2C_UNK);
    s32 GetLoadedArchiveFile(s32);
    static s32 header[WAVE_ARCHIVE_ENTRIES / sizeof(s32)];
    extern M2C_UNK func_0202d0a4;
    s32 bothTablesBytes;
    M2C_UNK *block;
    s32 tableBytes;
    s32 owner;

    block = (M2C_UNK *)GetLoadedArchiveFile(fileId);
    if (block == NULL) {
        if (Sound_ReadArchiveFile(fileId, header, WAVE_ARCHIVE_ENTRIES, 0) != WAVE_ARCHIVE_ENTRIES) {
            return NULL;
        }
        tableBytes = M2C_FIELD(header, s32 *, WAVE_ARCHIVE_COUNT) * 4;
        bothTablesBytes = tableBytes * 2;
        if (pool == 0) {
            return NULL;
        }
        if (cache == 0) {
            owner = 0;
        } else {
            owner = Sound_GetCurrentArchive();
        }
        block = (M2C_UNK *)Sound_AllocDataBlock((s32 *)pool, bothTablesBytes + 0x5C, (s32)&func_0202d0a4, owner, fileId);
        if (block == NULL) {
            return NULL;
        }
        {
            s32 readSize = Sound_ReadArchiveFile(fileId, block, tableBytes + WAVE_ARCHIVE_ENTRIES, 0);
            if (readSize != tableBytes + WAVE_ARCHIVE_ENTRIES) {
                return NULL;
            }
        }
        MI_CpuCopy8((M2C_UNK)((u8 *)block + WAVE_ARCHIVE_ENTRIES), (M2C_UNK)((u8 *)block + WAVE_ARCHIVE_ENTRIES + M2C_FIELD(block, s32 *, WAVE_ARCHIVE_COUNT) * 4), tableBytes);
        MI_CpuFill8((M2C_UNK)((u8 *)block + WAVE_ARCHIVE_ENTRIES), 0, tableBytes);
        DC_CleanRange(block, bothTablesBytes + WAVE_ARCHIVE_ENTRIES);
        if (cache != 0) {
            SetLoadedArchiveFile(fileId, block);
        }
    }
    return block;
}
#pragma opt_common_subs reset
/* Clear, in the archive `owner`'s loaded-file table, the cache slot for `fileId`
 * when the block being released is the one it holds.  The table is read through the
 * current-archive global, so the owner is installed around the lookup and the
 * previous archive put back afterwards; interrupts are masked meanwhile. */
s32 Sound_UntrackArchiveFile(s32 block, s32 owner, s32 fileId) {
    s32 OS_DisableInterrupts();
    s32 Sound_SetCurrentArchive(s32);
    s32 GetLoadedArchiveFile(s32);
    s32 SetLoadedArchiveFile(s32, s32);
    void OS_RestoreInterrupts(s32);
    s32 handle;
    s32 saved;
    if (!owner) return;
    saved = OS_DisableInterrupts();
    handle = Sound_SetCurrentArchive(owner);
    if (block == GetLoadedArchiveFile(fileId)) SetLoadedArchiveFile(fileId, 0);
    Sound_SetCurrentArchive(handle);
    OS_RestoreInterrupts(saved);
}

/* Free a loaded sequence archive block (`size` bytes, file `fileId` of the
 * `owner` archive): clear the block's cache slot in the owner's loaded-file
 * table and tell the ARM7 to release its memory. */
void FreeSequenceArchiveFile(s32 block, s32 size, s32 owner, s32 fileId) {
    M2C_UNK Sound_FreeSequenceMemory(s32, s32);
    M2C_UNK Sound_UntrackArchiveFile(s32, M2C_UNK, M2C_UNK);

    Sound_UntrackArchiveFile(block, owner, fileId);
    Sound_FreeSequenceMemory(block, block + size);
}

/* Free a loaded bank archive block: untrack it from `owner`'s loaded-file table
 * (file `fileId`), tell the ARM7 to release its `size` bytes and drop the sound
 * slots that still point into the block. */
void FreeBankArchiveFile(s32 block, s32 size, s32 owner, s32 fileId) {
    M2C_UNK Sound_FreeBankArchiveMemory(s32, s32);
    M2C_UNK Link_ClearSlotOwners(s32);

    Sound_UntrackArchiveFile(block, owner, fileId);
    Sound_FreeBankArchiveMemory(block, block + size);
    Link_ClearSlotOwners(block);
}

/* Release the loaded wave archive block at `block` (`size` bytes, `fileId` in
 * `owner` archive): clear the block's cache slot in the owner's loaded-file
 * table, tell the ARM7 the wave-archive data is freed and clear the block's
 * link-slot chain. */
void FreeWaveArchiveFile(s32 block, s32 size, M2C_UNK owner, M2C_UNK fileId) {
    M2C_UNK Sound_FreeWaveArchiveMemory(s32, s32);
    M2C_UNK Link_ClearSlotChain(s32);
    Sound_UntrackArchiveFile(block, owner, fileId);
    Sound_FreeWaveArchiveMemory(block, block + size);
    Link_ClearSlotChain(block);
}

void func_0202d0a4(s32 arg0,s32 arg1,s32 arg2,s32 arg3) {
s32 Link_ClearSlotChain(s32);
Sound_UntrackArchiveFile(arg0,arg2,arg3);
Link_ClearSlotChain(arg0);
}

/* Free a wave-archive entry block: clear its packed-table slot when the table
   still points at this block, then release the block back to the ARM7 sound heap. */
void FreeWaveArchiveEntry(s32 block, s32 size, M2C_UNK archive, M2C_UNK entryIndex) {
    M2C_UNK SetPackedTableEntry(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 GetPackedTableEntry(M2C_UNK, M2C_UNK);
    M2C_UNK Sound_FreeWaveArchiveMemory(s32, s32);
    if (block == GetPackedTableEntry(archive, entryIndex)) {
        SetPackedTableEntry(archive, entryIndex, 0);
    }
    Sound_FreeWaveArchiveMemory(block, block + size);
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

/* Play sequence `sequenceId` of the current sound archive on `player`, with the
 * channel, bank and priority its own sequence record carries. */
s32 Sound_PlaySequenceRecord(M2C_UNK player, s32 sequenceId) {
    void *GetSoundSequenceRecord(s32);
    s32 Sound_PlaySequenceById(M2C_UNK, s32, s32, s32, void *, s32);
    SoundSequenceRecord *record;

    record = GetSoundSequenceRecord(sequenceId);
    if (record == NULL) {
        return 0;
    }
    return Sound_PlaySequenceById(player, record->channel, record->bankId, record->priority, record, sequenceId);
}

/* Play sequence `sequenceId` of the current sound archive on `player`: a
 * negative channel, bank or priority takes the sequence record's own value. */
s32 Sound_PlaySequence(s32 player, s32 channel, s32 bankId, s32 priority, s32 sequenceId) {
    void *GetSoundSequenceRecord(s32);
    s32 Sound_PlaySequenceById(s32, s32, s32, s32, void *, s32);
    SoundSequenceRecord *record = GetSoundSequenceRecord(sequenceId);

    if (!record) return 0;
    if (priority < 0) priority = record->priority;
    if (bankId < 0) bankId = record->bankId;
    if (channel < 0) channel = record->channel;
    return Sound_PlaySequenceById(player, channel, bankId, priority, record, sequenceId);
}

/* Play entry `entryIndex` of sequence archive `archiveId` on `player`, using the
 * channel, bank and priority the entry itself carries.  Returns 0 when the
 * archive record, the loaded archive or the entry cannot be found. */
s32 Sound_PlaySequenceArchiveEntry(s32 player, s32 archiveId, s32 entryIndex) {
    s32 *GetSoundSequenceArchiveRecord(s32);
    s32 Sound_PlaySequenceEntry(s32, s32, s32, s32, void *, s32, s32, s32);
    void *GetSoundArchiveEntry(s32, s32);
    s32 *record;
    s32 archive;
    SoundArchiveEntry *entry;

    record = GetSoundSequenceArchiveRecord(archiveId);
    if (record == NULL) {
        return 0;
    }
    archive = GetLoadedArchiveFile(*record);
    if (archive == 0) {
        return 0;
    }
    entry = GetSoundArchiveEntry(archive, entryIndex);
    if (entry == NULL) {
        return 0;
    }
    return Sound_PlaySequenceEntry(player, entry->channel, entry->bankId, entry->priority, entry, archive, archiveId, entryIndex);
}

/* Play entry `entryIndex` of the loaded sound archive `archiveId` on `player`: a
 * negative channel, bank or priority takes the entry's own value.  Returns 0 when
 * the archive record, the loaded archive or the entry cannot be found. */
s32 Sound_PlayArchiveEntry(s32 player,s32 channel,s32 bankId,s32 priority,s32 archiveId,s32 entryIndex) {
s32 *GetSoundSequenceArchiveRecord(s32);
void *GetSoundArchiveEntry(s32,s32);
s32 Sound_PlaySequenceEntry(s32,s32,s32,s32,void *,s32,s32,s32);
s32 *record; s32 archive; SoundArchiveEntry *entry;
record=GetSoundSequenceArchiveRecord(archiveId);
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

#pragma opt_strength_reduction off
/* Bring the sound worker up: mark it ready, put the request nodes on the free
 * list, start the decode lock, initialise the four player slots and create the
 * worker task.  When the worker already exists, only refresh the slots. */
void Sound_StartWorker(M2C_UNK taskPriority, M2C_UNK heap) {
    M2C_UNK InitMutex(M2C_UNK *);
    M2C_UNK InitFileRequest(s32);
    M2C_UNK ListInit(M2C_UNK *, M2C_UNK);
    M2C_UNK ListAppend(M2C_UNK *, s32);
    M2C_UNK Sound_InitPlayer(s32);
    M2C_UNK InitSoundPlayerSlots(M2C_UNK);
    M2C_UNK CreateSoundWorkerTask(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gSoundWorkerState;
    extern M2C_UNK gSoundFreeRequests;
    extern M2C_UNK gSoundDecodeLock;
    extern M2C_UNK gSoundRequestPool;
    extern M2C_UNK gSoundWorker;
    extern u8 gSoundPlayerSlots[];
    extern M2C_UNK gSoundDecodeState;
    s32 requestPool;
    s32 slots;
    s32 slot;
    M2C_UNK *freeRequests;
    s32 player;
    s32 request;

    if (M2C_FIELD(&gSoundWorkerState, s32 *, SOUND_TASK_STATE_READY) != 0) {
        InitSoundPlayerSlots(heap);
        return;
    }
    M2C_FIELD(&gSoundWorkerState, s32 *, SOUND_TASK_STATE_READY) = 1;
    ListInit(&gSoundFreeRequests, 0);
    request = 0;
    freeRequests = &gSoundFreeRequests;
    requestPool = (s32)&gSoundRequestPool;
    goto checkRequests;
appendRequest:
        ListAppend(freeRequests, (request * SOUND_REQUEST_STRIDE) + requestPool);
    ++request;
checkRequests:
    if (request < SOUND_REQUEST_COUNT) goto appendRequest;
    InitMutex(&gSoundDecodeLock);
    slot = 0;
    M2C_FIELD(&gSoundWorkerState, M2C_UNK **, SOUND_TASK_STATE_DECODER) = &gSoundDecodeState;
    slots = (s32)gSoundPlayerSlots;
    goto checkSlots;
initSlot:
        player = (slot * SOUND_PLAYER_STRIDE) + slots;
        M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) = (s32) (M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) & ~(1 << SOUND_HANDLE_BIT_ACTIVE));
        InitFileRequest(player + SOUND_HANDLE_FILE_REQUEST);
        Sound_InitPlayer(player); /* install the slot's voice callbacks and clear its voice state */
        M2C_FIELD(player, s32 *, SOUND_HANDLE_SLOT_INDEX) = slot;
        M2C_FIELD(player, s8 *, SOUND_HANDLE_MAX_CHANNELS) = 0;
        M2C_FIELD(player, s32 *, SOUND_HANDLE_SAMPLE_DATA) = 0;
        M2C_FIELD(player, s32 *, SOUND_HANDLE_CHANNEL_BYTES) = 0;
        M2C_FIELD(player, s32 *, SOUND_HANDLE_CHANNEL_REFS) = 0;
    ++slot;
checkSlots:
    if (slot < SOUND_PLAYER_SLOTS) goto initSlot;
    InitSoundPlayerSlots(heap);
    CreateSoundWorkerTask(&gSoundWorker, taskPriority);
}
#pragma opt_strength_reduction reset
s32 InitSoundPlayerSlots(s32 heap)
{
    u8 *GetSoundPlayerRecord(s32);
    void *Sound_AllocDataBlock(s32 *, s32, s32, s32, s32);
    void Sound_StopPlayer();
    extern u8 gSoundPlayerSlots[];
    extern M2C_UNK Sound_OnDataBlockFreed;
    s32 zero = 0;
    u8 *player = gSoundPlayerSlots;
    const s32 callback = (s32)&Sound_OnDataBlockFreed;
    s32 slot = 0;
    do {
        u8 *entry = GetSoundPlayerRecord(slot);
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

/* Start sound `soundId` of the current sound archive on the player `handle`: look
 * the sound up in the sound table and start it on a player slot with the record's
 * own priority, for `lengthMs` (0 = play to the end).  Returns 0 when the sound is
 * not in the archive, else the result of Sound_StartPlayer. */
s32 Sound_StartArchiveRecord(s32 handle,s32 soundId,s32 lengthMs){void *GetSoundRecord(s32);s32 Sound_StartPlayer(s32,void *,s32,s32,s32,s32,s32,s32,s32,s32);void *p=GetSoundRecord(soundId);if(!p)return 0;return Sound_StartPlayer(handle,p,M2C_FIELD(p,u8 *,SOUND_RECORD_SLOT),M2C_FIELD(p,u8 *,SOUND_RECORD_PRIORITY),soundId,lengthMs,0,0,0,0);}

/* Mark the sound player held by the handle variable at `handle` as waiting for
 * its first segment (SOUND_HANDLE_BIT_PENDING); an empty handle is left alone.
 * Returns the player's new flags. */
s32 Sound_SetPlayerPending(s32 handle) {
    void * volatile *handleVar = (void * volatile *)handle;
    void *player;

    if (*handleVar == 0) return;
    player = *handleVar;
    return M2C_FIELD(player, s32 *, SOUND_HANDLE_FLAGS) |= 1 << SOUND_HANDLE_BIT_PENDING;
}

/* Start the sound `soundId` of the current sound archive on the player the
 * handle variable at `handle` names, for `lengthMs` (0 = play to the end), then
 * mark the player as waiting for its first segment.  Returns 0 when the sound is
 * not in the archive, else 1. */
s32 Sound_StartArchiveSound(s32 handle, s32 soundId, s32 lengthMs) {
    s32 Sound_StartArchiveRecord(s32, s32, s32);
    s32 Sound_SetPlayerPending(s32);

    if (Sound_StartArchiveRecord(handle, soundId, lengthMs) == 0) {
        return 0;
    }
    Sound_SetPlayerPending(handle);
    return 1;
}

void func_0202d944(volatile s32 *arg0,s32 arg1) {
void Sound_FadeOutPlayer(s32,s32);
if(*arg0==0)return;
Sound_FadeOutPlayer(*arg0,arg1);
}

void func_0202d960(void *volatile *a,s32 b){void Sound_StartFade(void *,s32);void *p;if(!*a)return;p=*a;if(((s32)(M2C_FIELD(p,u32 *,0x110)<<28)>>31)!=0)return;Sound_StartFade(p+0xe8,b<<8);}

/* Set the volume of a sound player's voice from a level index: map the level
 * through gSoundVoiceVolumeTable and hand the note's channel its new level. */
void Sound_SetVoiceVolumeFromLevel(volatile s32 *player,s32 note,s32 level){
    extern s16 gSoundVoiceVolumeTable[];
    void Sound_SetNoteVolumeLevel(s32,s32,s16);
    if(!*player)return;
    Sound_SetNoteVolumeLevel(*player,note,gSoundVoiceVolumeTable[level]);
}

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

#pragma opt_instruction_scheduling off
void Sound_UpdatePlayerChannels(void) {
void Sound_StartPlayerChannels(void *); void func_0202b77c(void *,s32); void func_0202de74(void *);
s32 func_0202ef00(void *); void func_0202ef34(void *); s32 func_0202ef4c(void *);
extern u8 data_0213c92c[]; extern s16 data_020e9ca0[];
s32 i; s16 a; s32 b; u8 *p; p=data_0213c92c; i=0;
do {
s32 flags=M2C_FIELD(p,s32 *,0x110);
if((flags<<31)>>31) {
if(!M2C_FIELD(p,s32 *,0x114))func_0202de74(p);
else {
if(((flags<<29)>>31) && M2C_FIELD(p,s32 *,0x118)) {
Sound_StartPlayerChannels(p);
M2C_FIELD(p,s32 *,0x110)=(M2C_FIELD(p,s32 *,0x110)|2)&~4;
}
if((M2C_FIELD(p,s32 *,0x110)<<30)>>31) {
func_0202ef34(p+0xe8);
a=data_020e9ca0[M2C_FIELD(p,s32 *,0x154)];
b=data_020e9ca0[M2C_FIELD(p,s32 *,0x158)]+(data_020e9ca0[func_0202ef00(p+0xe8)>>8]+a);
if(b!=M2C_FIELD(p,s32 *,0x15c)){func_0202b77c(p,b); M2C_FIELD(p,s32 *,0x15c)=b;}
if(((M2C_FIELD(p,s32 *,0x110)<<28)>>31) && func_0202ef4c(p+0xe8))func_0202de74(p);
}
}
}
i++;p+=0x174;
}while(i<4);
}
#pragma opt_instruction_scheduling reset
/* Takes the sound player slot at slotIndex for the caller, storing it in *handle
 * (after detaching whatever slot that handle held). The slot is usable only when
 * it has sample data; when it is already active, the sound in it is stopped and
 * replaced unless its priority is above `priority`. Marks the slot active and
 * records its new priority. Returns the slot, or 0 when it cannot be taken. */
void *Sound_AcquirePlayer(void **handle,s32 slotIndex,s32 priority){extern u8 gSoundPlayerSlots[];void Sound_ClearPlayerHandle(void **);void Sound_StopPlayer(void *);void *player;if(*handle)Sound_ClearPlayerHandle(handle);player=gSoundPlayerSlots+slotIndex*SOUND_PLAYER_STRIDE;if(!M2C_FIELD(player,s32 *,SOUND_HANDLE_SAMPLE_DATA))return 0;if(((s32)(M2C_FIELD(player,u32 *,SOUND_HANDLE_FLAGS)<<31)>>31)!=0){if(priority<M2C_FIELD(player,s32 *,SOUND_HANDLE_PRIORITY))return 0;Sound_StopPlayer(player);}M2C_FIELD(player,s32 *,SOUND_HANDLE_PRIORITY)=priority;M2C_FIELD(player,u32 *,SOUND_HANDLE_FLAGS)=(M2C_FIELD(player,u32 *,SOUND_HANDLE_FLAGS)&~1)|1;M2C_FIELD(player,void ***,SOUND_HANDLE_OWNER)=handle;*handle=player;return player;}

/* Release the sound player `player`: detach the caller's handle variable it still
 * owns, clear the player's active, playing and waiting (pending) flags, and leave
 * the slot free for Sound_AcquirePlayer to hand out again. */
void Sound_ReleasePlayer(void *player) {
    s32 *owner = M2C_FIELD(player, s32 **, SOUND_HANDLE_OWNER);

    if (owner != NULL) {
        *owner = 0;
        M2C_FIELD(player, s32 **, SOUND_HANDLE_OWNER) = 0;
    }
    M2C_FIELD(player, u32 *, SOUND_HANDLE_FLAGS) &= ~(1 << SOUND_HANDLE_BIT_ACTIVE);
    M2C_FIELD(player, u32 *, SOUND_HANDLE_FLAGS) &= ~(1 << SOUND_HANDLE_BIT_PENDING);
    M2C_FIELD(player, u32 *, SOUND_HANDLE_FLAGS) &= ~(1 << SOUND_HANDLE_BIT_PLAYING);
}

