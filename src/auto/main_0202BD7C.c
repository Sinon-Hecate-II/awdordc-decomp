/* 43 functions from 0x0202BD7C to 0x0202CD78 (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
#include "sound.h"
typedef struct { u32 id:24; u32 flags:8; } Unk0202PackedId;

/* Load a resource archive: read its 0x30-byte header, then allocate and read
   the object-table, data and optional extra sections from the file into the
   given memory pool. */
s32 LoadResourceArchive(void *archiveData, s32 pool, s32 loadExtra) {
    s32 FileRead(void *, void *, u32);
    s32 FileSeek(void *, u32, s32);
    void *Sound_AllocDataBlock(s32 *, s32, s32, s32, s32);
    extern M2C_UNK func_0202c488;
    extern M2C_UNK func_0202c494;
    extern M2C_UNK func_0202c4a0;
    ResourceArchive *archive = (ResourceArchive *)archiveData;
    void *objectBuffer;
    void *dataBuffer;
    void *extraBuffer;
    s32 extraSize;
    s32 bytesRead;

    if (FileSeek(archive->request, 0, 0) == 0) {
        return 0;
    }
    if (FileRead(archive->request, archive, 0x30) != 0x30) {
        return 0;
    }
    if (pool != 0) {
        objectBuffer = Sound_AllocDataBlock((s32 *)pool, archive->objectSize, (s32)&func_0202c488, (s32)archive, 0);
        archive->objectBlock = objectBuffer;
        if (objectBuffer == 0) {
            return 0;
        }
        if (FileSeek(archive->request, archive->objectOffset, 0) == 0) {
            return 0;
        }
        bytesRead = FileRead(archive->request, archive->objectBlock, archive->objectSize);
        if (bytesRead != archive->objectSize) {
            return 0;
        }
        dataBuffer = Sound_AllocDataBlock((s32 *)pool, archive->dataSize, (s32)&func_0202c494, (s32)archive, 0);
        archive->dataBlock = dataBuffer;
        if (dataBuffer == 0) {
            return 0;
        }
        if (FileSeek(archive->request, archive->dataOffset, 0) == 0) {
            return 0;
        }
        bytesRead = FileRead(archive->request, archive->dataBlock, archive->dataSize);
        if (bytesRead != archive->dataSize) {
            return 0;
        }
        if (loadExtra != 0) {
            extraSize = archive->extraSize;
            if (extraSize != 0) {
                extraBuffer = Sound_AllocDataBlock((s32 *)pool, extraSize, (s32)&func_0202c4a0, (s32)archive, 0);
                archive->extraBlock = extraBuffer;
                if (extraBuffer == 0) {
                    return 0;
                }
                if (FileSeek(archive->request, archive->extraOffset, 0) == 0) {
                    return 0;
                }
                bytesRead = FileRead(archive->request, archive->extraBlock, archive->extraSize);
                if (bytesRead != archive->extraSize) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* Initialises the current sound archive `archive` from the archive file loaded
 * at `base`: copies the 0x30-byte header into the archive, turns the header's
 * offsets (data block, object table, object file) into pointers into `base`, and
 * does the same for every object table entry's data offset. */
void InitSoundArchive(void *archive, s32 base) {
    extern s32 gCurrentArchive;
    u32 i;
    s32 offset;
    void *entry;

    MIi_CpuCopy32(base, archive, 0x30);
    offset = M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_DATA_OFFSET);
    M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_DATA_BLOCK) = offset == 0 ? 0 : base + offset;
    offset = M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_TABLE_OFFSET);
    M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_TABLE) = offset == 0 ? 0 : base + offset;
    offset = M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_FILE_OFFSET);
    M2C_FIELD(archive, s32 *, SOUND_ARCHIVE_FILE) = offset == 0 ? 0 : base + offset;
    /* Relocate each object's data offset to a pointer as well. */
    for (i = 0; i < M2C_FIELD(M2C_FIELD(archive, void **, SOUND_ARCHIVE_TABLE), u32 *, SOUND_ARCHIVE_ENTRY_COUNT); i++) {
        entry = M2C_FIELD(archive, void **, SOUND_ARCHIVE_TABLE) + SOUND_ARCHIVE_ENTRIES + i * SOUND_ARCHIVE_ENTRY_SIZE;
        offset = M2C_FIELD(entry, s32 *, SOUND_ARCHIVE_ENTRY_OFFSET);
        M2C_FIELD(entry, s32 *, SOUND_ARCHIVE_ENTRY_DATA) = offset == 0 ? 0 : base + offset;
    }
    M2C_FIELD(archive, s32 *, 0x30) = 0;
    gCurrentArchive = (s32)archive;
}

s32 Sound_SetCurrentArchive(s32 arg0){extern s32 gCurrentArchive;s32 old=gCurrentArchive;gCurrentArchive=arg0;return old;}

s32 Sound_GetCurrentArchive(void) {
    extern s32 gCurrentArchive;
    return gCurrentArchive;
}

/* Return the sound archive's sequence-table record `index`, or NULL when the
 * archive has no such record. */
void *GetSoundSequenceRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *section;
    s32 offset;
    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_SEQUENCE);
    section = offset == 0 ? 0 : dataBlock + offset;
    if (!section) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(section, u32 *, 0)) return 0;
    offset = M2C_FIELD(section + index*4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

/* Return the sound archive's sequence-archive record `index`, or NULL when the
 * archive has no such record. */
void *GetSoundSequenceArchiveRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *section;
    s32 offset;
    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_SEQUENCE_ARCHIVE);
    section = offset == 0 ? 0 : dataBlock + offset;
    if (!section) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(section, u32 *, 0)) return 0;
    offset = M2C_FIELD(section + index*4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

/* Resolves an index to its sound-bank record in the current archive's loaded data
 * block: the bank table at SOUND_DATA_BANK is a {count, offset[count]} section
 * whose offsets are relative to the block, so the record sits at the index's
 * offset from the block.  Returns NULL for an out-of-range index or a zero
 * offset. */
void *GetSoundBankRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *table;
    s32 offset;

    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_BANK);
    table = offset == 0 ? 0 : dataBlock + offset;
    if (!table) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(table, u32 *, 0)) return 0;
    offset = M2C_FIELD(table + index * 4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

/* Return the sound archive's wave-archive record `index`, or NULL when the
 * archive has no such record. */
void *GetWaveArchiveRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *section;
    s32 offset;
    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_WAVE_ARCHIVE);
    section = offset == 0 ? 0 : dataBlock + offset;
    if (!section) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(section, u32 *, 0)) return 0;
    offset = M2C_FIELD(section + index*4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

/* Return the sound archive's sound record `index`, or NULL when the archive has
 * no such record. */
void *GetSoundRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *section;
    s32 offset;
    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_SOUND);
    section = offset == 0 ? 0 : dataBlock + offset;
    if (!section) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(section, u32 *, 0)) return 0;
    offset = M2C_FIELD(section + index*4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

/* Resolves an index to its channel record in the current archive's loaded data
 * block: the channel table at SOUND_DATA_CHANNEL is a {count, offset[count]}
 * section whose offsets are relative to the block, so the record sits at the
 * index's offset from the block.  Returns NULL for an out-of-range index or a
 * zero offset. */
void *GetSoundArchiveChannelRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *table;
    s32 offset;

    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_CHANNEL);
    table = offset == 0 ? 0 : dataBlock + offset;
    if (!table) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(table, u32 *, 0)) return 0;
    offset = M2C_FIELD(table + index * 4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

/* Resolves an index to its player record in the current archive's loaded data
 * block: the player table at SOUND_DATA_PLAYER_CHANNELS is a {count, offset[count]}
 * section whose offsets are relative to the block, so the record sits at the
 * index's offset from the block.  Returns NULL for an out-of-range index or a
 * zero offset. */
void *GetSoundPlayerRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *table;
    s32 offset;

    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_PLAYER_CHANNELS);
    table = offset == 0 ? 0 : dataBlock + offset;
    if (!table) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(table, u32 *, 0)) return 0;
    offset = M2C_FIELD(table + index * 4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

/* Return the sound archive's sound-group record `index`, or NULL when the archive
 * has no such record. */
void *GetSoundGroupRecord(s32 index) {
    extern s32 gCurrentArchive;
    void *archive = (void *)gCurrentArchive;
    void *dataBlock, *section;
    s32 offset;
    dataBlock = M2C_FIELD(archive, void **, SOUND_ARCHIVE_DATA_BLOCK);
    offset = M2C_FIELD(dataBlock, s32 *, SOUND_DATA_GROUP);
    section = offset == 0 ? 0 : dataBlock + offset;
    if (!section) return 0;
    if (index < 0) return 0;
    if ((u32)index >= M2C_FIELD(section, u32 *, 0)) return 0;
    offset = M2C_FIELD(section + index*4, s32 *, 0x4);
    dataBlock = M2C_FIELD(archive, void * volatile *, SOUND_ARCHIVE_DATA_BLOCK);
    return offset == 0 ? 0 : dataBlock + offset;
}

s32 Sound_GetArchiveFileOffset(u32 a){extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,12);}

s32 Sound_GetArchiveFileSize(u32 a){extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,16);}

/* Read file `index` of the current sound archive into `buffer`: at most `size`
 * bytes starting `offset` bytes into the file, clipped to the file's size.
 * Returns the number of bytes read, or -1 when the file does not exist or the
 * read could not be started. */
s32 Sound_ReadArchiveFile(u32 index, void *buffer, u32 size, u32 offset) {
    extern s32 gCurrentArchive;
    s32 FileSeek(void *, u32, s32);
    s32 FileRead(void *, void *, u32);
    void *archive = (void *)gCurrentArchive;
    SoundArchiveFileTable *table = (SoundArchiveFileTable *)M2C_FIELD(archive, void **, SOUND_ARCHIVE_TABLE);
    SoundArchiveFileEntry *file;

    if (index >= table->count) return -1;
    file = &table->files[index];
    if (size > file->size - offset) size = file->size - offset;
    if (!FileSeek(archive + SOUND_ARCHIVE_FILE_REQUEST, file->offset + offset, 0)) return -1;
    return FileRead(archive + SOUND_ARCHIVE_FILE_REQUEST, buffer, size);
}

void Sound_GetArchiveFileRange(volatile u32 *p) {extern s32 gCurrentArchive;u32 a=M2C_FIELD(gCurrentArchive,volatile u32 *,0x7c),b=M2C_FIELD(gCurrentArchive,volatile u32 *,0x80);p[0]=a;p[1]=b;}

s32 GetLoadedArchiveFile(u32 a) {extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,20);}

s32 SetLoadedArchiveFile(s32 a,s32 b) {extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84)+a*16;M2C_FIELD(p,s32 *,20)=b;return (s32)p;}

void func_0202c488(M2C_UNK arg0, M2C_UNK arg1, void *arg2) {
    M2C_FIELD(arg2, s32 *, 0x8C) = 0;
}

void func_0202c494(s32 a,s32 b,void *p) {M2C_FIELD(p,s32 *,0x84)=0;}

void func_0202c4a0(s32 a,s32 b,void *p){M2C_FIELD(p,s32 *,0x88)=0;}

/* Aligns the buffer and creates a sound heap with its first allocation section. */
u32 Sound_CreateHeap(s32 buffer, s32 size) {
    s32 CreateFrameHeap(u32, u32, s32);
    s32 Sound_InitHeap(u32, s32);
    s32 frameHeap;
    u32 bufferEnd;
    u32 heapSize;
    u32 heapStart;

    bufferEnd = buffer + size;
    heapStart = (buffer + (SOUND_HEAP_ALIGNMENT - 1)) & ~(SOUND_HEAP_ALIGNMENT - 1);
    if (heapStart > bufferEnd) {
        return 0U;
    }
    heapSize = bufferEnd - heapStart;
    if (heapSize < SOUND_HEAP_HEADER_SIZE) {
        return 0U;
    }
    frameHeap = CreateFrameHeap(heapStart + SOUND_HEAP_HEADER_SIZE, heapSize - SOUND_HEAP_HEADER_SIZE, 0);
    if (frameHeap == 0) {
        return 0U;
    }
    if (Sound_InitHeap(heapStart, frameHeap) != 0) {
        return heapStart;
    }
    DestroyFrameHeap(frameHeap);
    return 0U;
}

void Sound_DestroyHeap(s32 *arg0) {
    M2C_UNK DestroyFrameHeap(s32);
    M2C_UNK Sound_FreeAllBlocks();
    Sound_FreeAllBlocks();
    DestroyFrameHeap(*arg0);
}

/* Frees every block group of the sound player `player`: calls each block's
 * release callback, unlinks the group from the player's list, resets the
 * player's heap and flushes the sound commands, then adds a fresh block. */
s32 Sound_FreeAllBlocks(void *player){
s32 ListPrev(void *,M2C_UNK);void ListRemove(void *,void *);void func_0202a6b0(s32,s32);void Sound_FlushAndWait(void);s32 Sound_CreateHeapSection(void *);
void *group;s32 changed=0;void *block;
group=(void *)ListPrev(player+4,0);
while(group){
block=(void *)ListPrev(group,0);
while(block){
if(M2C_FIELD(block,void (**)(void *,s32,s32,s32),12)){
M2C_FIELD(block,void (**)(void *,s32,s32,s32),12)(block+32,M2C_FIELD(block,s32 *,8),M2C_FIELD(block,s32 *,16),M2C_FIELD(block,s32 *,20));changed=1;
}
block=(void *)ListPrev(group,(s32)block);
}
ListRemove(player+4,group);group=(void *)ListPrev(player+4,0);
}
func_0202a6b0(M2C_FIELD(player,s32 *,0),3);if(changed)Sound_FlushAndWait();return Sound_CreateHeapSection(player);
}

/* Take a `size`-byte data block from the sound heap in `pool` (32-byte aligned,
 * with the block header in front), record its free callback, argument and index,
 * and link it into the pool's block list.  Returns the payload, or NULL. */
void *Sound_AllocDataBlock(s32 *pool,s32 size,s32 freeCallback,s32 freeArg,s32 index){
s32 ListPrev(void *,M2C_UNK);M2C_UNK ListAppend(s32,void *);void *Sound_HeapAlloc(s32,s32,M2C_UNK);register unsigned int blockList;void *block;
block=Sound_HeapAlloc(*pool,((size+31)&~31)+32,32);if(!block)return 0;
blockList=ListPrev(pool+1,0);M2C_FIELD(block,s32 *,SOUND_BLOCK_SIZE)=size;M2C_FIELD(block,s32 *,SOUND_BLOCK_FREE)=freeCallback;M2C_FIELD((u32)block,s32 *,SOUND_BLOCK_FREE_ARG)=freeArg;M2C_FIELD(block,s32 *,SOUND_BLOCK_INDEX)=index;ListAppend(blockList,block);return block+SOUND_BLOCK_DATA;
}

/* Push a new, empty section onto the sound heap: record the frame-heap state
 * under the new section's index so the section's allocations can be rolled back,
 * then append the section.  Returns the section's index, or -1 when the record or
 * the section allocation failed. */
s32 Sound_PushHeapSection(void *player) {
    s32 RecordFrameHeapState(s32, u16);
    M2C_UNK UnrecordFrameHeapState(s32, M2C_UNK);
    s32 Sound_CreateHeapSection(void *);
    if (RecordFrameHeapState(M2C_FIELD(player, s32 *, SOUND_HEAP_FRAME), M2C_FIELD(player, u16 *, SOUND_HEAP_SECTION_COUNT)) == 0) {
        return -1;
    }
    if (Sound_CreateHeapSection(player) != 0) {
        return M2C_FIELD(player, u16 *, SOUND_HEAP_SECTION_COUNT) - 1;
    }
    UnrecordFrameHeapState(M2C_FIELD(player, s32 *, SOUND_HEAP_FRAME), 0);
    return -1;
}

void func_0202c6a4(void *p, s32 count) {
    s32 ListPrev(void *, M2C_UNK);
    void ListRemove(void *, void *);
    s32 UnrecordFrameHeapState(s32, s32);
    s32 RecordFrameHeapState(s32, u16);
    void Sound_FlushAndWait(void);
    s32 Sound_CreateHeapSection(void *);
    s32 Sound_FreeAllBlocks(void *);
    void *a;
    s32 changed;
    void *b;

    b = 0;
    changed = 0;
    if (count == 0) {
        Sound_FreeAllBlocks(p);
        return;
    }
    while (count < M2C_FIELD(p, u16 *, 12)) {
        a = (void *)ListPrev(p + 4, 0);
        b = (void *)ListPrev(a, (s32)b);
        while (b) {
            if (M2C_FIELD(b, void (**)(void *, s32, s32, s32), 12)) {
                M2C_FIELD(b, void (**)(void *, s32, s32, s32), 12)(b + 32, M2C_FIELD(b, s32 *, 8), M2C_FIELD(b, s32 *, 16), M2C_FIELD(b, s32 *, 20));
                changed = 1;
            }
            b = (void *)ListPrev(a, (s32)b);
        }
        ListRemove(p + 4, a);
    }
    UnrecordFrameHeapState(M2C_FIELD(p, s32 *, 0), count);
    if (changed) {
        Sound_FlushAndWait();
    }
    RecordFrameHeapState(M2C_FIELD(p, s32 *, 0), M2C_FIELD(p, u16 *, 12));
    Sound_CreateHeapSection(p);
}

s32 func_0202c778(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 0xC) - 1;
}

s32 func_0202c784(s32 *arg0) {
    u32 func_0202a6dc(s32, M2C_UNK);
    u32 temp_r0;

    temp_r0 = func_0202a6dc(*arg0, 0x20);
    if (temp_r0 < 0x20U) {
        return 0;
    }
    return (temp_r0 - 0x20) & ~0x1F;
}

void Sound_InitHeapSectionList(M2C_UNK arg0) {
    M2C_UNK ListInit(M2C_UNK, M2C_UNK);
    ListInit(arg0, 0);
}

s32 Sound_InitHeap(u32 p,s32 a){s32 Sound_CreateHeapSection(void *);ListInit(p+4,12);M2C_FIELD(p,s32 *,0)=a;return Sound_CreateHeapSection(p)!=0;}

/* Allocate an empty heap section, initialize its list header, and append it to the heap's section list. */
s32 Sound_CreateHeapSection(void *heap) {
    void *Sound_HeapAlloc(s32, s32, M2C_UNK);
    void Sound_InitHeapSectionList(s32);
    M2C_UNK ListAppend(s32, void *);
    void *section = Sound_HeapAlloc(M2C_FIELD(heap, s32 *, SOUND_HEAP_FRAME), 20, SOUND_HEAP_ALIGNMENT);
    if (!section) return 0;
    Sound_InitHeapSectionList((s32)section);
    ListAppend((s32)(heap + SOUND_HEAP_SECTIONS), section);
    return 1;
}

void Sound_FlushAndWait(void) {
    M2C_UNK Sound_FlushCommands(M2C_UNK);
    M2C_UNK Sound_WaitForCommand(s32);
    s32 Sound_GetCommandCounter();
    s32 temp_r4;

    temp_r4 = Sound_GetCommandCounter();
    Sound_FlushCommands(1);
    Sound_WaitForCommand(temp_r4);
}

s32 func_0202c848(void) {
    s32 func_0202c8b8();
    if (func_0202c8b8() == 0) {
        return 1;
    }
    return 0;
}

s32 func_0202c860(M2C_UNK arg0,M2C_UNK arg1){s32 LoadSoundSequenceArchive(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32);if(LoadSoundSequenceArchive(arg0,255,arg1,1,0)==0)return 1;return 0;}

s32 func_0202c88c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 LoadSoundBank(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    if (LoadSoundBank(arg0, 0xFF, arg1, 1, 0) == 0) {
        return 1;
    }
    return 0;
}

/* Loads every sound resource of a sound group (the group record for id groupId)
   into memory pool `pool`: sequence, bank, wave archive and sequence archive
   items, in the group's order.  Returns 0, or the first loader's error code. */
s32 func_0202c8b8(s32 groupId,s32 pool) {
void *group=GetSoundGroupRecord(groupId);u32 i;SoundGroupItem *item;s32 error;
if(!group)return 1;
i=0;
if(i<M2C_FIELD(group,u32 *,0)){
item=group+4;
do{
switch(item->type){
case SOUND_GROUP_SEQUENCE:error=LoadSoundSequence(item->index,item->flags,pool,1,0);if(error)return error;break;
case SOUND_GROUP_SEQUENCE_ARCHIVE:error=LoadSoundSequenceArchive(item->index,item->flags,pool,1,0);if(error)return error;break;
case SOUND_GROUP_BANK:error=LoadSoundBank(item->index,item->flags,pool,1,0);if(error)return error;break;
case SOUND_GROUP_WAVE_ARCHIVE:error=LoadWaveArchive(item->index,item->flags,pool,1,0);if(error)return error;break;
}
i++;item++;
}while(i<M2C_FIELD(group,u32 *,0));
}
return 0;
}

/* Loads the sound sequence named by sequenceId along with the bank it plays on:
 * loads the sequence's bank, then either reads the sequence from its archive file
 * or reuses the already loaded one.  Stores it in *out when out is set.  Returns 0
 * on success, 2 when the sequence has no record, 6 when its file fails to load. */
s32 LoadSoundSequence(s32 sequenceId,s32 flags,s32 pool,s32 create,s32 *out) {
s32 LoadSoundBank(s32,s32,s32,s32,s32);
SoundSequenceRecord *record=GetSoundSequenceRecord(sequenceId);s32 result;
if(!record)return 2;
result=LoadSoundBank(record->bankId,flags,pool,create,0);if(result)return result;
sequenceId=record->fileId;
if(flags&SOUND_LOAD_SEQUENCE){result=LoadSoundSequenceFile(sequenceId,pool,create);if(!result)return 6;}else result=GetLoadedArchiveFile(sequenceId);
if(out)*out=result;return 0;
}

/* Loads the sequence archive named by archiveId: reads its file when the
   SOUND_LOAD_SEQUENCE_ARCHIVE flag is set, otherwise reuses the already loaded
   archive, and stores it in *out when out is set.  Returns 0 on success, 3 when
   the archive has no record, or 7 when its file fails to load. */
s32 LoadSoundSequenceArchive(s32 archiveId, s32 flags, s32 pool, s32 create, s32 *out) {
    s32 LoadSoundSequenceArchiveFile(s32, s32, s32);
    SoundSequenceArchiveRecord *record = GetSoundSequenceArchiveRecord(archiveId);
    s32 result;
    if (!record) return 3;
    archiveId = record->fileId;
    if (flags & SOUND_LOAD_SEQUENCE_ARCHIVE) {
        result = LoadSoundSequenceArchiveFile(archiveId, pool, create);
        if (!result) return 7;
    } else {
        result = GetLoadedArchiveFile(archiveId);
    }
    if (out) *out = result;
    return 0;
}

/* Loads a sound-archive bank: resolves its bank record, loads the bank file
 * itself (or reuses the already loaded object) and then each of the up to four
 * wave archives the bank references.  Returns 0 or a nonzero error code
 * (4 = no bank record, 5 = no wave archive record, 8/9 = load failed). */
s32 LoadSoundBank(s32 bankId,s32 flags,s32 pool,s32 create,s32 out) {
s32 LoadSoundBankArchiveFile(s32,s32,s32);s32 LoadBankWaveArchiveEntries(s32,s32,s32,s32,s32);
void *bankRecord;void *waveRecord;s32 bank;s32 i;s32 loadWaveArchives;s32 result;s32 waveObject;
bankRecord=GetSoundBankRecord(bankId);if(!bankRecord)return 4;
if(flags&2){bank=LoadSoundBankArchiveFile(M2C_FIELD(bankRecord,s32 *,0),pool,create);if(!bank)return 8;}
else bank=GetLoadedArchiveFile(M2C_FIELD(bankRecord,u32 *,0));
loadWaveArchives=flags&4;
for(i=0;i<4;i++){
if(((u16 *)bankRecord)[i+2]==SOUND_FILE_NONE)continue;
waveRecord=GetWaveArchiveRecord(((u16 *)bankRecord)[i+2]);if(!waveRecord)return 5;
result=LoadWaveArchive(((u16 *)bankRecord)[i+2],flags,pool,create,&waveObject);if(result)return result;
if(((Unk0202PackedId *)waveRecord)->flags&1 && loadWaveArchives){
if(!LoadBankWaveArchiveEntries(waveObject,bank,i,((Unk0202PackedId *)waveRecord)->id,pool))return 9;
}
if(bank&&waveObject)Link_SetSlotOwner(bank,i,waveObject);
}
if(out)*(s32 *)out=bank;
return 0;
}

/* Loads the wave archive named by the packed record for waveArchiveId: either
 * from its file (rebuilding the entry table when the record says it has one)
 * or from the already loaded files. Stores the archive in *out when out is set.
 * Returns 0 on success, 5 for a missing record, 9 when the load fails. */
s32 LoadWaveArchive(s32 waveArchiveId,s32 flags,s32 pool,s32 create,s32 *out) {
s32 LoadWaveArchiveFile(u32,s32,s32);s32 LoadWaveArchiveFileWithEntryTable(u32,s32,s32);
Unk0202PackedId *record=GetWaveArchiveRecord(waveArchiveId);s32 result;
if(!record)return 5;
if(flags&SOUND_LOAD_WAVE_ARCHIVE){if(record->flags&SOUND_RECORD_WAVE_ENTRY_TABLE)result=LoadWaveArchiveFileWithEntryTable(record->id,pool,create);else result=LoadWaveArchiveFile(record->id,pool,create);if(!result)return 9;}else result=GetLoadedArchiveFile(record->id);
if(out)*out=result;return 0;
}

/* Loads sound-archive file `fileId` into a fresh block of `pool` (allocated with
   the given free callback, context and index), reads it whole and flushes the
   loaded bytes from the data cache; returns the block, or 0 on failure. */
s32 Sound_LoadArchiveFile(s32 fileId, M2C_UNK *freeCallback, s32 freeArg, s32 freeIndex, s32 pool) {
    void DC_CleanRange(void *, s32);
    s32 size = Sound_GetArchiveFileSize(fileId);
    void *block;

    if (!size) return 0;
    if (!pool) return 0;
    block = Sound_AllocDataBlock((s32 *)pool, size + 32, (s32)freeCallback, freeArg, freeIndex);
    if (!block) return 0;
    if (size != Sound_ReadArchiveFile(fileId, block, size, 0)) return 0;
    DC_CleanRange(block, size);
    return (s32)block;
}

/* Load and cache the sound sequence file `fileId`: if it is already loaded return
 * that block, otherwise read it from `pool` with the sequence free callback and,
 * when `create` is set, record the loaded block.  Returns the block, or 0 on
 * failure. */
s32 LoadSoundSequenceFile(s32 fileId, s32 pool, s32 create) {
    s32 GetLoadedArchiveFile();
    M2C_UNK SetLoadedArchiveFile(M2C_UNK, s32);
    s32 Sound_LoadArchiveFile(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d01c;
    s32 freeArg;
    s32 block;

    block = GetLoadedArchiveFile();
    if (block == 0) {
        if (create == 0) {
            freeArg = 0;
        } else {
            freeArg = Sound_GetCurrentArchive();
        }
        block = Sound_LoadArchiveFile(fileId, &func_0202d01c, freeArg, fileId, pool);
        if ((create != 0) && (block != 0)) {
            SetLoadedArchiveFile(fileId, block);
        }
    }
    return block;
}

