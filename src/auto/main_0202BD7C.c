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
    void *func_0202c5f0(s32 *, s32, s32, s32, s32);
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
        objectBuffer = func_0202c5f0((s32 *)pool, archive->objectSize, (s32)&func_0202c488, (s32)archive, 0);
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
        dataBuffer = func_0202c5f0((s32 *)pool, archive->dataSize, (s32)&func_0202c494, (s32)archive, 0);
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
                extraBuffer = func_0202c5f0((s32 *)pool, extraSize, (s32)&func_0202c4a0, (s32)archive, 0);
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

    func_02007e70(base, archive, 0x30);
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

s32 func_0202c014(s32 arg0){extern s32 gCurrentArchive;s32 old=gCurrentArchive;gCurrentArchive=arg0;return old;}

s32 func_0202c02c(void) {
    extern s32 gCurrentArchive;
    return gCurrentArchive;
}

void *func_0202c03c(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,8);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c0a0(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0xc);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *GetSoundBankRecord(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x10);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *GetWaveArchiveRecord(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x14);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c1cc(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x24);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c230(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x18);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c294(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x20);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *GetSoundGroupRecord(s32 arg0){extern s32 gCurrentArchive;void *root=(void *)gCurrentArchive;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x1c);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

s32 func_0202c35c(u32 a){extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,12);}

s32 func_0202c384(u32 a){extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,16);}

s32 func_0202c3ac(u32 a,void *b,u32 n,u32 off) {
extern s32 gCurrentArchive;s32 FileSeek(void *,u32,s32);s32 FileRead(void *,void *,u32);
void *root=(void *)gCurrentArchive;void *p=M2C_FIELD(root,void **,0x84);
if(a>=M2C_FIELD(p,u32 *,8))return -1;
p=p+12+a*16;
if(n>M2C_FIELD(p,u32 *,4)-off)n=M2C_FIELD(p,u32 *,4)-off;
if(!FileSeek(root+52,M2C_FIELD(p,u32 *,0)+off,0))return -1;
return FileRead(root+52,b,n);
}

void func_0202c424(volatile u32 *p) {extern s32 gCurrentArchive;u32 a=M2C_FIELD(gCurrentArchive,volatile u32 *,0x7c),b=M2C_FIELD(gCurrentArchive,volatile u32 *,0x80);p[0]=a;p[1]=b;}

s32 func_0202c444(u32 a) {extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,20);}

s32 func_0202c46c(s32 a,s32 b) {extern s32 gCurrentArchive;void *p=M2C_FIELD(gCurrentArchive,void **,0x84)+a*16;M2C_FIELD(p,s32 *,20)=b;return (s32)p;}

void func_0202c488(M2C_UNK arg0, M2C_UNK arg1, void *arg2) {
    M2C_FIELD(arg2, s32 *, 0x8C) = 0;
}

void func_0202c494(s32 a,s32 b,void *p) {M2C_FIELD(p,s32 *,0x84)=0;}

void func_0202c4a0(s32 a,s32 b,void *p){M2C_FIELD(p,s32 *,0x88)=0;}

u32 func_0202c4ac(s32 arg0, s32 arg1) {
    s32 func_0202a638(s32, s32, M2C_UNK);
    s32 func_0202c7b8(u32, s32);
    s32 temp_r0_2;
    u32 temp_r0;
    u32 temp_r1;
    u32 temp_r5;

    temp_r0 = arg0 + arg1;
    temp_r5 = (arg0 + 3) & ~3;
    if (temp_r5 > temp_r0) {
        return 0U;
    }
    temp_r1 = temp_r0 - temp_r5;
    if (temp_r1 < 0x10U) {
        return 0U;
    }
    temp_r0_2 = func_0202a638(temp_r5 + 0x10, temp_r1 - 0x10, 0);
    if (temp_r0_2 == 0) {
        return 0U;
    }
    if (func_0202c7b8(temp_r5, temp_r0_2) != 0) {
        return temp_r5;
    }
    func_0202a670(temp_r0_2);
    return 0U;
}

void func_0202c51c(s32 *arg0) {
    M2C_UNK func_0202a670(s32);
    M2C_UNK Sound_FreeAllBlocks();
    Sound_FreeAllBlocks();
    func_0202a670(*arg0);
}

/* Frees every block group of the sound player `player`: calls each block's
 * release callback, unlinks the group from the player's list, resets the
 * player's heap and flushes the sound commands, then adds a fresh block. */
s32 Sound_FreeAllBlocks(void *player){
s32 ListNext(void *,M2C_UNK);void ListRemove(void *,void *);void func_0202a6b0(s32,s32);void Sound_FlushAndWait(void);s32 func_0202c7ec(void *);
void *group;s32 changed=0;void *block;
group=(void *)ListNext(player+4,0);
while(group){
block=(void *)ListNext(group,0);
while(block){
if(M2C_FIELD(block,void (**)(void *,s32,s32,s32),12)){
M2C_FIELD(block,void (**)(void *,s32,s32,s32),12)(block+32,M2C_FIELD(block,s32 *,8),M2C_FIELD(block,s32 *,16),M2C_FIELD(block,s32 *,20));changed=1;
}
block=(void *)ListNext(group,(s32)block);
}
ListRemove(player+4,group);group=(void *)ListNext(player+4,0);
}
func_0202a6b0(M2C_FIELD(player,s32 *,0),3);if(changed)Sound_FlushAndWait();return func_0202c7ec(player);
}

void *func_0202c5f0(s32 *arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4){
s32 ListNext(void *,M2C_UNK);M2C_UNK ListAppend(s32,void *);void *func_0202a67c(s32,s32,M2C_UNK);register unsigned int temp_r0_2;void *temp_r0;
temp_r0=func_0202a67c(*arg0,((arg1+31)&~31)+32,32);if(!temp_r0)return 0;
temp_r0_2=ListNext(arg0+1,0);M2C_FIELD(temp_r0,s32 *,8)=arg1;M2C_FIELD(temp_r0,s32 *,12)=arg2;M2C_FIELD((u32)temp_r0,s32 *,16)=arg3;M2C_FIELD(temp_r0,s32 *,20)=arg4;ListAppend(temp_r0_2,temp_r0);return temp_r0+32;
}

s32 func_0202c658(void *arg0) {
    s32 func_0202a714(s32, u16);
    M2C_UNK func_0202a764(s32, M2C_UNK);
    s32 func_0202c7ec(void *);
    if (func_0202a714(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, u16 *, 0xC)) == 0) {
        return -1;
    }
    if (func_0202c7ec(arg0) != 0) {
        return M2C_FIELD(arg0, u16 *, 0xC) - 1;
    }
    func_0202a764(M2C_FIELD(arg0, s32 *, 0), 0);
    return -1;
}

void func_0202c6a4(void *p, s32 count) {
    s32 ListNext(void *, M2C_UNK);
    void ListRemove(void *, void *);
    s32 func_0202a764(s32, s32);
    s32 func_0202a714(s32, u16);
    void Sound_FlushAndWait(void);
    s32 func_0202c7ec(void *);
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
        a = (void *)ListNext(p + 4, 0);
        b = (void *)ListNext(a, (s32)b);
        while (b) {
            if (M2C_FIELD(b, void (**)(void *, s32, s32, s32), 12)) {
                M2C_FIELD(b, void (**)(void *, s32, s32, s32), 12)(b + 32, M2C_FIELD(b, s32 *, 8), M2C_FIELD(b, s32 *, 16), M2C_FIELD(b, s32 *, 20));
                changed = 1;
            }
            b = (void *)ListNext(a, (s32)b);
        }
        ListRemove(p + 4, a);
    }
    func_0202a764(M2C_FIELD(p, s32 *, 0), count);
    if (changed) {
        Sound_FlushAndWait();
    }
    func_0202a714(M2C_FIELD(p, s32 *, 0), M2C_FIELD(p, u16 *, 12));
    func_0202c7ec(p);
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

void func_0202c7a8(M2C_UNK arg0) {
    M2C_UNK ListInit(M2C_UNK, M2C_UNK);
    ListInit(arg0, 0);
}

s32 func_0202c7b8(u32 p,s32 a){s32 func_0202c7ec(void *);ListInit(p+4,12);M2C_FIELD(p,s32 *,0)=a;return func_0202c7ec(p)!=0;}

s32 func_0202c7ec(void *p){
void *func_0202a67c(s32,s32,M2C_UNK);void func_0202c7a8(s32);M2C_UNK ListAppend(s32,void *);
void *q=func_0202a67c(M2C_FIELD(p,s32 *,0),20,4);if(!q)return 0;func_0202c7a8((s32)q);ListAppend((s32)(p+4),q);return 1;
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

s32 LoadSoundSequence(s32 a,s32 flags,s32 b,s32 c,s32 *out) {
s32 LoadSoundBank(s32,s32,s32,s32,s32);
void *p=func_0202c03c(a);s32 r;
if(!p)return 2;
r=LoadSoundBank(M2C_FIELD(p,u16 *,4),flags,b,c,0);if(r)return r;
a=M2C_FIELD(p,s32 *,0);
if(flags&1){r=func_0202cd0c(a,b,c);if(!r)return 6;}else r=func_0202c444(a);
if(out)*out=r;return 0;
}

s32 LoadSoundSequenceArchive(s32 a,s32 flags,s32 b,s32 c,s32 out) {
s32 func_0202cd78(s32,s32,s32);
void *p=func_0202c0a0(a);s32 r;
if(!p)return 3;
a=M2C_FIELD(p,s32 *,0);
if(flags&8){r=func_0202cd78(a,b,c);if(!r)return 7;}else r=func_0202c444(a);
if(out)*(s32 *)out=r;return 0;
}

/* Loads a sound-archive bank: resolves its bank record, loads the bank file
 * itself (or reuses the already loaded object) and then each of the up to four
 * wave archives the bank references.  Returns 0 or a nonzero error code
 * (4 = no bank record, 5 = no wave archive record, 8/9 = load failed). */
s32 LoadSoundBank(s32 bankId,s32 flags,s32 pool,s32 create,s32 out) {
s32 func_0202cde4(s32,s32,s32);s32 LoadBankWaveArchiveEntries(s32,s32,s32,s32,s32);
void *bankRecord;void *waveRecord;s32 bank;s32 i;s32 loadWaveArchives;s32 result;s32 waveObject;
bankRecord=GetSoundBankRecord(bankId);if(!bankRecord)return 4;
if(flags&2){bank=func_0202cde4(M2C_FIELD(bankRecord,s32 *,0),pool,create);if(!bank)return 8;}
else bank=func_0202c444(M2C_FIELD(bankRecord,u32 *,0));
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

s32 LoadWaveArchive(s32 a,s32 flags,s32 b,s32 c,s32 *out) {
s32 func_0202ce50(u32,s32,s32);s32 func_0202cebc(u32,s32,s32);
Unk0202PackedId *p=GetWaveArchiveRecord(a);s32 r;
if(!p)return 5;
if(flags&4){if(p->flags&1)r=func_0202cebc(p->id,b,c);else r=func_0202ce50(p->id,b,c);if(!r)return 9;}else r=func_0202c444(p->id);
if(out)*out=r;return 0;
}

s32 func_0202cc6c(s32 a,M2C_UNK *b,s32 c,s32 d,s32 pool) {
void DC_CleanRange(void *,s32);
s32 n=func_0202c384(a);void *p;
if(!n)return 0;if(!pool)return 0;
p=func_0202c5f0((s32 *)pool,n+32,(s32)b,c,d);if(!p)return 0;
if(n!=func_0202c3ac(a,p,n,0))return 0;
DC_CleanRange(p,n);return (s32)p;
}

s32 func_0202cd0c(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 func_0202c444();
    M2C_UNK func_0202c46c(M2C_UNK, s32);
    s32 func_0202cc6c(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d01c;
    s32 var_r2;
    s32 var_r4;

    var_r4 = func_0202c444();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = func_0202c02c();
        }
        var_r4 = func_0202cc6c(arg0, &func_0202d01c, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            func_0202c46c(arg0, var_r4);
        }
    }
    return var_r4;
}

