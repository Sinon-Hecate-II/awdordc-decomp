/* 24 functions from 0x020756A4 to 0x02076698 (main), found by ds-decomp. */
#include "common.h"
static inline void SetState756(void *a,s32 index,s32 value) { u8 *p=(u8 *)a+0xc0c; s32 shift=(index&3)*2; p[index>>2]=(u8)(p[index>>2]&(-1^(3<<shift)))|(value<<shift); }

typedef struct { u8 pad[0x2050]; u8 active, unk2051, state, unk2053; u8 queue[0x500]; u32 count; } Queue02075;

#pragma push
#pragma opt_common_subs off
void func_020756a4(void *a) {
void *HeapAllocBlock(s32);void HeapFreeBlock(void *);s32 FindFreeNode(void *);void MI_CpuCopy32(void *,void *,s32);s32 SaveArchive_ComputeChecksum(void *,void *);s32 OS_GetLockID(void);void MI_CpuCopy8(void *,void *);
s32 i,state;u8 *p; s32 shift;u8 byte;u32 mask;u8 *out;u16 id;u8 ok;u32 seq;
if(!M2C_FIELD(a,u8 *,0x2050)||M2C_FIELD(a,u8 *,0x2052)==1)return;
for(i=0;i<256;i++){
p=(u8 *)a+(i>>2);shift=(i&3)*2;byte=M2C_FIELD(p,u8 *,0xc0c);state=(byte>>shift)&3;
switch(state){case 2:mask=-1^(3<<shift);byte&=mask;state=(u8)byte;M2C_FIELD(p,u8 *,0xc0c)=(1<<shift)|state;break;case 1:M2C_FIELD(p,u8 *,0xc0c)=byte&(-1^(3<<shift));break;}
}
out=HeapAllocBlock(256);i=M2C_FIELD(a,s32 *,0xc00);
if(i!=-1){p=(u8 *)a+0xc0c;shift=(i&3)*2;p[i>>2]=(u8)(p[i>>2]&(-1^(3<<shift)))|(1<<shift);}
seq=++M2C_FIELD(a,u32 *,0xc08);if(seq==0)++M2C_FIELD(a,u32 *,0xc08);
M2C_FIELD(a,s32 *,0xc00)=FindFreeNode(a);M2C_FIELD(a,s32 *,0xc04)=0;
i=M2C_FIELD(a,s32 *,0xc00);p=(u8 *)a+0xc0c;shift=(i&3)*2;p[i>>2]=(u8)(p[i>>2]&(-1^(3<<shift)))|(3<<shift);
M2C_FIELD(out,u32 *,0)=0x32777364;
if(M2C_FIELD(a,s32 *,0xc04)==0)M2C_FIELD(out,u32 *,8)=M2C_FIELD((u8 *)a+M2C_FIELD(a,s32 *,0xc00)*12,u32 *,0)+1;
M2C_FIELD(out,u16 *,12)=0x54;MI_CpuCopy32((u8 *)a+0xc0c,out+20,64);
out[14]=1;out[15]=1;seq=M2C_FIELD(a,u32 *,0xc08);M2C_FIELD(out,u16 *,16)=seq;M2C_FIELD(out,u16 *,18)=seq>>16;
M2C_FIELD(out,s32 *,4)=SaveArchive_ComputeChecksum(a,out);
id=OS_GetLockID();CARD_LockBackup(id);
SaveDevice_Transfer(out,(M2C_FIELD(a,s32 *,0xc00)<<10)+(M2C_FIELD(a,s32 *,0xc04)<<8),M2C_FIELD(out,u16 *,12),0,0,1,7,10,2);
ok=SaveDevice_WaitForTransferDone()!=0;CARD_UnlockBackup(id);OS_ReleaseLockID(id);
if(!ok){M2C_FIELD(a,u8 *,0x2052)=1;HeapFreeBlock(out);return;}
if(M2C_FIELD(a,s32 *,0xc04)==0)MI_CpuCopy8(out+8,(u8 *)a+M2C_FIELD(a,s32 *,0xc00)*12);
HeapFreeBlock(out);M2C_FIELD(a,u8 *,0x2051)=0;
}
#pragma pop
void func_02075938(void *arg0,s32 arg1) {
M2C_UNK SaveList_Remove(void *);
s32 var_r4,var_r5; u32 temp_r8; void *temp_r7; u8 *byte;
var_r5=arg1;
if(M2C_FIELD(arg0,volatile u8 *,0x2050)==0 || M2C_FIELD(arg0,volatile u8 *,0x2052)==1)return;
if((((s32)M2C_FIELD(arg0+(var_r5>>2),u8 *,0xc0c)>>((u32)(var_r5<<30)>>29))&3)!=3)return;
var_r4=var_r5*12+(s32)arg0;
if(M2C_FIELD(var_r4,u8 *,6)==1)return;
SaveList_Remove(arg0+0xc4c);
loop:
temp_r8=(u32)(var_r5<<30)>>29;
temp_r7=arg0+(var_r5>>2);
byte=(u8 *)temp_r7+0xc0c;
*byte &= -1 ^ (3<<temp_r8);
*byte |= 2<<temp_r8;
var_r5=M2C_FIELD(var_r4,u16 *,10);
if(var_r5!=0xffff){var_r4=var_r5*12+(s32)arg0;goto loop;}
}

#pragma opt_common_subs off
/* Reads the save-block chain whose head is table entry `head` into `dest`: each
   12-byte table entry names one 1KB archive block, whose payload (everything
   past the 0x14- or 0x38-byte block header) is copied out before following the
   entry's next index.  Returns the bytes copied, or 0 when a read failed. */
s32 ReadSaveBlockChain(M2C_UNK *manager,s32 head,s32 dest) {
s32 OS_GetLockID(void);
void *entry; s32 start=dest; u8 ok=1; u16 handle;
if(M2C_FIELD(manager,u8*,0x2050)==0)return 0;
if(M2C_FIELD(manager,u8*,0x2052)==1)return 0;
handle=OS_GetLockID();
while(head!=0xffff){
entry=(void*)manager+head*12;
CARD_LockBackup(handle);
if(M2C_FIELD(entry,u16*,8)==0xffff)
SaveDevice_Transfer((head<<10)+0x38,dest,M2C_FIELD(entry,u16*,4)-0x38,0,0,1,6,1,0);
else
SaveDevice_Transfer((head<<10)+0x14,dest,M2C_FIELD(entry,u16*,4)-0x14,0,0,1,6,1,0);
ok=SaveDevice_WaitForTransferDone()!=0;
CARD_UnlockBackup(handle);
if(!ok){M2C_FIELD(manager,u8*,0x2052)=1;break;}
head=M2C_FIELD(entry,u16*,10);
if(M2C_FIELD(entry,u16*,8)==0xffff)dest+=M2C_FIELD(entry,u16*,4)-0x38;
else dest+=M2C_FIELD(entry,u16*,4)-0x14;
}
OS_ReleaseLockID(handle);
return ok?dest-start:0;
}
#pragma opt_common_subs reset
/* Total payload bytes of the saved-block chain whose head table entry is
 * `index`: walk the index table's next links, adding each block's length minus
 * its SAVE_ARCHIVE_HEADER_SIZE header (SAVE_ARCHIVE_ROOT_SIZE for a chain root).
 * Returns 0 while the save manager is not usable. */
s32 GetSaveBlockChainSize(M2C_UNK *manager, s32 index) {
    void *entry;
    s32 total;

    total = 0;
    if (M2C_FIELD(manager, u8 *, SAVE_MANAGER_ACTIVE) == 0) return 0;
    if (M2C_FIELD(manager, u8 *, SAVE_MANAGER_STATE) == 1) return 0;
    while (index != SAVE_ARCHIVE_LINK_NONE) {
        entry = (void *)manager + index * SAVE_BLOCK_ENTRY_STRIDE;
        if (M2C_FIELD(entry, u16 *, SAVE_BLOCK_ENTRY_PREV) == SAVE_ARCHIVE_LINK_NONE) {
            index = M2C_FIELD(entry, u16 *, SAVE_BLOCK_ENTRY_LENGTH) - SAVE_ARCHIVE_ROOT_SIZE;
        } else {
            index = M2C_FIELD(entry, u16 *, SAVE_BLOCK_ENTRY_LENGTH) - SAVE_ARCHIVE_HEADER_SIZE;
        }
        total += index;
        index = M2C_FIELD(entry, u16 *, SAVE_BLOCK_ENTRY_NEXT);
    }
    return total;
}

/* Applies the queued save-record requests to the (initialised) save list: runs
 * each update, then each delete, then writes the merged list back.  When the
 * save hardware is not ready the list is marked failed and left untouched. */
void SaveList_Flush(M2C_UNK *p) {
u8 *req;u32 i;
if(((Queue02075*)p)->active!=0 && ((Queue02075*)p)->state!=1){
if(!SaveManager_ProbeArchive(p)){((Queue02075*)p)->state=1;return;}
SaveList_ClearUsed((void*)p+0xc4c);
req=(void*)p+0x2054;i=0;
if(((Queue02075*)p)->count>i){
if(i<((Queue02075*)p)->count){
do {
switch(req[15]){
case 1:func_020753f8(p,*(s32*)req,*(s32*)(req+4),*(s32*)(req+8),req[14],*(s32*)(req+16));break;
case 2:func_02075938(p,*(u16*)(req+12));break;
}
i++;req+=20;
}while(i<((Queue02075*)p)->count);
}
}
func_020756a4(p);
((Queue02075*)p)->count=0;
SaveList_Sort((void*)p+0xc4c);
}
}

M2C_UNK SaveList_EnqueueUpdate(M2C_UNK *p,M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 type){
M2C_UNK *GetSaveRecordList(void);s32 GetSaveRecordCount(void);
u8 *q=(u8 *)p+0x2054; u32 seq=0,i,n; s32 found=0;u8 *best,*entry;s32 j,cmp;u32 x,y;
if(!((Queue02075 *)p)->active||((Queue02075 *)p)->state==1)return;
if(type){
n=((Queue02075 *)p)->count;
for(i=0;i<n;i++,q+=20){
if(q[15]==1 && q[14]==type){seq=M2C_FIELD(q,u32 *,16)+1;if(!seq)seq++;found=1;}
}
if(!found){
entry=(u8 *)GetSaveRecordList();best=0;n=GetSaveRecordCount();
for(j=0;j<(s32)n;j++,entry+=40){
if(type==entry[2]){
if(best){
x=M2C_FIELD(best,u32 *,4);y=M2C_FIELD(entry,u32 *,4);
if((y&0xffff0000)==0xffff0000 && !(x&0xffff0000) && x!=0)cmp=0;
else if(!(y&0xffff0000) && (x&0xffff0000)==0xffff0000 && y!=0)cmp=1;
else cmp=y>x;
if(!cmp)continue;
}
best=entry;
}
}
if(best){seq=M2C_FIELD(best,u32 *,4)+1;if(!seq)seq++;}
}
}
q=(u8 *)p+0x2054+((Queue02075 *)p)->count*20;
q[15]=1;M2C_FIELD(q,s32 *,0)=a;M2C_FIELD(q,s32 *,4)=b;M2C_FIELD(q,s32 *,8)=c;q[14]=type;M2C_FIELD(q,u32 *,16)=seq;
((Queue02075 *)p)->count++;
}

/* Queue a save-record delete request (kind SAVE_REQUEST_DELETE) for record id `id`
 * in the save manager's request queue; ignored once the archive is unusable. */
void SaveList_QueueDelete(M2C_UNK *manager, s32 id) {
 s32 entry;
 if ((M2C_FIELD(manager,u8 *,SAVE_MANAGER_ACTIVE)!=0)&&(M2C_FIELD(manager,u8 *,SAVE_MANAGER_STATE)!=1)) {
 entry=M2C_FIELD(manager,s32 *,SAVE_MANAGER_QUEUE_COUNT)*SAVE_REQUEST_STRIDE+(s32)((void *)manager+SAVE_MANAGER_QUEUE);
 M2C_FIELD(entry,u8 *,SAVE_REQUEST_KIND)=SAVE_REQUEST_DELETE;
 M2C_FIELD(entry,s16 *,SAVE_REQUEST_RECORD)=id;
 M2C_FIELD(manager,s32 *,SAVE_MANAGER_QUEUE_COUNT)=M2C_FIELD(manager,s32 *,SAVE_MANAGER_QUEUE_COUNT)+1;
 }
}

/* Boot task that opens the battle-save archive: check that the save device's
 * archive is usable, then scan its blocks and index the newest save records. */
void SaveManager_InitTask(void) {
    void SaveManager_CheckArchive(void *manager);
    void SaveManager_ScanArchive(void *manager);
    extern M2C_UNK gSaveManager;

    SaveManager_CheckArchive(&gSaveManager);
    SaveManager_ScanArchive(&gSaveManager);
}

void SaveList_FlushTask(void) {

    extern M2C_UNK gSaveManager;
    SaveList_Flush(&gSaveManager);
}

/* Boot-time save setup: when the save device is up, ask it for the save-chip
 * configuration the game uses (state 2 = ready) and read its root header, then
 * queue the task that opens and scans the save archive. */
void SaveManager_Start(void) {
s32 OS_GetLockID(void); s32 SaveDevice_GetState(void); s32 SaveDevice_Configure(s32);
s32 rootHeader;u16 archiveLock,rootLock;u8 configured;
if(SaveDevice_IsReady()){
archiveLock=OS_GetLockID();CARD_LockBackup(archiveLock);
configured=SaveDevice_Configure(SAVE_DEVICE_CONFIG);
CARD_UnlockBackup(archiveLock);OS_ReleaseLockID(archiveLock);
if(configured && (u8)SaveDevice_GetState()==SAVE_DEVICE_STATE_READY){
rootLock=OS_GetLockID();CARD_LockBackup(rootLock);
SaveDevice_Transfer(0,&rootHeader,4,0,0,0,6,1,0);
CARD_UnlockBackup(rootLock);OS_ReleaseLockID(rootLock);
}}
CreateTaskSprite(SaveManager_InitTask,1,0x400,0x11,0);
}

/* Queue a save-record write on the global save manager: hand the save data
 * block, its record name, the byte size and the save type (SAVE_TYPE_*) to the
 * queue writer. */
void SaveList_QueueUpdate(void *block, const char *name, s32 size, s32 type) {
    M2C_UNK SaveList_EnqueueUpdate(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK gSaveManager;
    SaveList_EnqueueUpdate(&gSaveManager, block, name, size, type);
}

/* Deletes the oldest save-directory records of `type` so that at most `maxKeep`
   of them remain: the records of that type are collected, and whenever one more
   arrives than fits, the oldest (by timestamp, with the wraparound rule the save
   manager uses elsewhere) is deleted and dropped from the array. */
void PruneSaveRecords(s32 type,s32 maxKeep){
void DeleteSaveRecord(M2C_UNK);
M2C_UNK *GetSaveRecordList(void);s32 GetSaveRecordCount(void);
void *HeapAllocBlock(s32);void HeapFreeBlock(void *);
s32 kept;u8 **keptRecords;s32 oldest,n,i,scanCount,j,bestIsNewer;u8 *p;u32 newTime,bestTime;
p=(u8 *)GetSaveRecordList();n=GetSaveRecordCount();
kept=0;keptRecords=HeapAllocBlock((maxKeep+1)*4);
for(i=0;i<n;i++,p+=SAVE_RECORD_STRIDE){
if(type==p[SAVE_RECORD_TYPE]){
if(kept<maxKeep){keptRecords[kept]=p;kept=kept+1;continue;}
keptRecords[kept]=p;
oldest=0;
scanCount=kept+1;
for(j=1;j<scanCount;j++){
newTime=M2C_FIELD(keptRecords[j],u32 *,SAVE_RECORD_TIME);bestTime=M2C_FIELD(keptRecords[oldest],u32 *,SAVE_RECORD_TIME);
if((bestTime&0xffff0000)==0xffff0000 && !(newTime&0xffff0000) && newTime!=0)bestIsNewer=0;
else if(!(bestTime&0xffff0000) && (newTime&0xffff0000)==0xffff0000 && bestTime!=0)bestIsNewer=1;
else bestIsNewer=bestTime>newTime;
if(bestIsNewer)oldest=j;
}
DeleteSaveRecord(M2C_FIELD(keptRecords[oldest],u16 *,SAVE_RECORD_ID));
for(;oldest<kept;oldest++)keptRecords[oldest]=keptRecords[oldest+1];
}
}
if(keptRecords)HeapFreeBlock(keptRecords);
}

/* Queue the deletion of save-directory record `recordId` on the global save manager. */
void DeleteSaveRecord(s32 recordId) {
    extern M2C_UNK gSaveManager;
    SaveList_QueueDelete(&gSaveManager, recordId);
}

/* Start the save-flush task sprite (depth 1, 0x400-byte stack, priority 0x11)
 * that drains the global save manager's queued record changes. */
void SaveList_StartFlush(void) {
    CreateTaskSprite(SaveList_FlushTask, 1, 0x400, 0x11, 0);
}

/* Load save-directory record `recordId` into `dest` by walking its saved-block
 * chain; returns the bytes loaded, or 0 when the archive is unusable or a block
 * could not be read. */
s32 LoadSaveRecord(u16 recordId, void *dest) {
    s32 ReadSaveBlockChain(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK gSaveManager;
    return ReadSaveBlockChain(&gSaveManager, recordId, (s32)dest);
}

/* Return the total payload size of save-directory record `recordId`'s block chain. */
s32 GetSaveRecordSize(s32 recordId) {
    extern M2C_UNK gSaveManager;
    return GetSaveBlockChainSize(&gSaveManager, recordId);
}

void IsSaveTaskRunning(void) {
    IsTaskSpriteRunning(1);
}

u8 IsSaveArchiveUnusable(void) {
    extern M2C_UNK data_02140a18;
    return M2C_FIELD(&data_02140a18, u8 *, 0x52);
}

u8 IsSaveListDirty(void){extern M2C_UNK data_02140a18;return M2C_FIELD(&data_02140a18,u8*,0x53);}

M2C_UNK *GetSaveRecordList(void) {
    extern M2C_UNK data_0213f664;
    return &data_0213f664;
}

s32 GetSaveRecordCount(void){extern M2C_UNK data_02140a18;return M2C_FIELD(&data_02140a18,s32*,0x4c);}

#pragma push
#pragma opt_common_subs off
void HaltWithMessage(M2C_UNK arg0) {
    M2C_UNK Apply3DSpriteBanks();
    M2C_UNK Update3DSpriteVram();
    M2C_UNK GX_TurnOnDisplay();
    M2C_UNK Sound_StopAllSound(M2C_UNK);
    M2C_UNK Sound_FlushCommands(M2C_UNK);
    M2C_UNK func_02081f08();
    M2C_UNK Apply3DSpriteDisplayConfig();
    M2C_UNK Set3DSpriteVramBanks();
    M2C_UNK FadeOutMusic(M2C_UNK);
    M2C_UNK LoadScenePanelPalette(M2C_UNK);
    M2C_UNK DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 MeasureMessageLinesWidth(M2C_UNK, M2C_UNK);
    s32 MeasureMessageHeight(M2C_UNK);
    extern void *g3DSpriteBankMain;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    u16 *volatile sp3C;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    s32 temp_r1_2;
    s32 temp_r4;
    void *temp_r5;
    s32 var_r6;
    s32 temp_r0_15;
    s32 temp_r1;
    void *var_r0;

    FadeOutMusic(0);
    Sound_StopAllSound(0);
    Sound_FlushCommands(0);
    func_02081f08();
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~1);
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~2);
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~4);
    Apply3DSpriteBanks();
    Set3DSpriteVramBanks();
    *(volatile u16 *)0x04000304 &= ~0x8000;
    GX_TurnOnDisplay();
    var_r6 = 0;
    *(volatile s32 *)0x04001000 |= 0x10000;
    temp_r5 = gCur3DSpriteEngine;
    do {
        if (var_r6 == 0) {
            var_r0 = g3DSpriteEngineMain;
        } else {
            var_r0 = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = var_r0;
        Apply3DSpriteDisplayConfig();
        sp3C = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp3C = *sp3C & ~0x10;
        sp38 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp38 = *sp38 & ~0x20;
        sp34 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp34 = *sp34 & ~0x40;
        sp30 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp30 = *sp30 & ~0x80;
        sp2C = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp2C = *sp2C & ~0x100;
        sp28 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp28 = *sp28 & ~0x200;
        sp24 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp24 = *sp24 & ~0x400;
        sp20 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp20 = *sp20 & ~0x800;
        sp1C = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) + 9;
        *sp1C = (s16) (*sp1C & ~0xC0);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x53) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x50) = 0;
        M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x44) = 0;
        M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x47) = 0;
        var_r6 += 1;
        sp18 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp18 = *sp18 & ~0x10;
        sp14 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp14 = *sp14 | 0x20;
        sp10 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp10 = *sp10 & ~0x40;
        spC = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *spC = *spC & ~0x80;
        sp8 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        *sp8 = *sp8 & ~0x100;
    } while (var_r6 < 2);
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    temp_r4 = MeasureMessageLinesWidth(arg0, 1);
    temp_r1 = 0xC0 - MeasureMessageHeight(arg0);
    temp_r0_15 = 0x100 - temp_r4;
    temp_r1_2 = temp_r1 / 2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3A) = (s16) (0 - (temp_r0_15 / 2));
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x42) = (s16) (0 - temp_r1_2);
    LoadScenePanelPalette(0);
    DrawTextLine(0, 0, 1, arg0, 0, 1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(g3DSpriteEngineMain, u8 *, 0x46) = (u8) (M2C_FIELD(g3DSpriteEngineMain, u8 *, 0x46) | 1);
    M2C_FIELD(g3DSpriteEngineSub, u8 *, 0x46) = (u8) (M2C_FIELD(g3DSpriteEngineSub, u8 *, 0x46) | 1);
    Apply3DSpriteBanks();
    Update3DSpriteVram();
loop_6:
    if ((s32) *(volatile u16 *)0x04000006 < 0xC0) {
        goto loop_6;
    }
    do {

    } while ((s32) *(volatile u16 *)0x04000006 >= 0xC0);
    goto loop_6;
}
#pragma pop
/* Counts the set bits of `value` with the classic SWAR popcount: fold the 2-bit
 * pairs into 2-bit sums, then the 4-, 8- and 16-bit groups, and return the byte. */
u8 CountBits(u32 value) {
    u32 evenBits;
    u32 nibbles;
    u32 bytes;
    u32 halfwords;

    evenBits = value - (0x55555555 & (value >> 1));
    nibbles = (evenBits & 0x33333333) + (0x33333333 & (evenBits >> 2));
    bytes = (nibbles + (nibbles >> 4)) & 0x0F0F0F0F;
    halfwords = bytes + (bytes >> 8);
    return (u8) (halfwords + (halfwords >> 0x10));
}

/* Compute the SHA-1 digest of `length` message bytes and write the 20-byte
 * digest to `digest`. */
void Sha1Digest(u8 *digest, const u8 *message, s32 length) {
    void Sha1Init(Sha1Context *);
    void Sha1Update(void *, void *, u32);
    void SHA1_Finalize(void *, void *);
    u8 context[0x68];
    Sha1Init((Sha1Context *)context);
    Sha1Update(context, (void *)message, length);
    SHA1_Finalize(context, digest);
}

