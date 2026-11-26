/* 9 functions from 0x02074920 to 0x020756A4 (main), found by ds-decomp. */
#include "common.h"
#define SAVE_LIST_COUNT 128  /* records a save list holds */
#define SAVE_LIST_PAYLOAD 32 /* bytes of payload a save record carries */

typedef struct { u16 id; u8 kind; u8 active; s32 value; u8 data[SAVE_LIST_PAYLOAD]; } Entry_02074920;
typedef struct { Entry_02074920 entries[128]; u32 count; } List_02074920;

/* The save-chain table: 256 fixed 12-byte nodes plus a 2-bit rank for each
 * node (0..2 = free with a reuse count, 3 = the node is in the chain). */
#define NODE_COUNT       256
#define NODE_STRIDE      12
#define NODE_RANK_TABLE  0xC0C
#define NODE_RANK_MASK   3
#define NODE_RANK_IN_CHAIN 3
#define NODE_KIND_CHAIN  1   /* node kind of a record that is in the chain */
#define NODE_NONE        0xFFFF

/* Pick the free node the save writer should use next: the lowest rank wins,
 * then the oldest value, with kind-1 (chained) nodes avoided while free. */
u16 FindFreeNode(void *table) {
u8 *node;
s32 nodeIndex;
s32 keepOld;
u32 nodeValue;
u16 bestIndex;
u8 bestRank;
u8 bestKind;
u32 bestValue;
s32 rank;
bestIndex=NODE_NONE;
node=table;
for(nodeIndex=0;nodeIndex<NODE_COUNT;nodeIndex++,node+=NODE_STRIDE) {
rank=(M2C_FIELD((u8 *)table+(nodeIndex>>2),u8 *,NODE_RANK_TABLE)>>((nodeIndex&3)*2))&NODE_RANK_MASK;
switch(rank) {
case 0: case 1: case 2:
if(bestIndex==NODE_NONE) break;
if(rank>bestRank)continue;
if(rank<bestRank)break;
{
u8 nodeKind=M2C_FIELD(node,u8 *,6);
if(nodeKind!=bestKind && rank!=0) {
if(nodeKind==NODE_KIND_CHAIN)continue;
if(bestKind==NODE_KIND_CHAIN)break;
}
nodeValue=M2C_FIELD(node,u32 *,0);
if((nodeValue&0xffff0000)==0xffff0000 && !(bestValue&0xffff0000) && bestValue!=0)keepOld=0;
else if(!(nodeValue&0xffff0000) && (bestValue&0xffff0000)==0xffff0000 && nodeValue!=0)keepOld=1;
else keepOld=nodeValue>bestValue;
if(keepOld)continue;
}
break;
case NODE_RANK_IN_CHAIN: continue;
}
bestRank=rank;
bestIndex=nodeIndex;
bestValue=M2C_FIELD(node,u32 *,0);
bestKind=M2C_FIELD(node,u8 *,6);
}
return bestIndex;
}

/* Mark every record of the save list unused by clearing its active flag. */
void SaveList_ClearUsed(List_02074920 *list) {
u32 i=0;
for(;i<list->count;i++) list->entries[i].active=0;
}

/* Append a record (slot id, kind, value and an optional 32-byte payload) to the
 * save list, unless the list is already full. */
void SaveList_AddRecord(List_02074920 *list, u16 id, u8 kind, s32 value, void *data) {
    void MI_CpuCopy32(void *, void *, u32);
    void MI_CpuFill32(s32, void *, u32);
    u32 n = list->count;
    Entry_02074920 *entry;

    if (n >= SAVE_LIST_COUNT) return;
    entry = &list->entries[n];
    entry->id = id;
    entry->kind = kind;
    entry->active = 1;
    entry->value = value;
    if (data) MI_CpuCopy32(data, entry->data, SAVE_LIST_PAYLOAD);
    else MI_CpuFill32(0, entry->data, SAVE_LIST_PAYLOAD);
    list->count++;
}

/* Removes the save record with the given slot id from the save list, moving the
 * records after it down one place. */
void SaveList_Remove(List_02074920 *list, s32 id) {
    void MI_CpuCopy8(void *, void *, u32);
    Entry_02074920 *entry;
    u32 i, count;

    count = list->count;
    i = 0;
    entry = list->entries;
    for (; i < count; i++, entry++) {
        if (id == entry->id) {
            if (i < count - 1) {
                Entry_02074920 *cur = &list->entries[i];
                do {
                    MI_CpuCopy8(cur + 1, cur, 40);
                    i++;
                    cur++;
                } while (i < list->count - 1);
            }
            list->count--;
            return;
        }
    }
}

/* Sorts the entry list by kind and id using bubble sort. */
u32 SaveList_Sort(List_02074920 *list) {
    void MI_CpuCopy8(void *, void *, u32);
    u32 i;
    Entry_02074920 *cur;
    u32 j;
    u8 scratch[0x28];
    u32 count;
    u32 limit;
    u32 subLimit;

    count = list->count;
    if (count <= 1U) {
        return count;
    }
    limit = count - 1;
    j = 0;
    if (limit == 0) {
        return count;
    }
    do {
        i = 0;
        subLimit = limit - j;
        if (subLimit != 0) {
            cur = list->entries;
            do {
                u8 nextKind = (cur + 1)->kind;
                u8 curKind = cur->kind;
                if (((u32)curKind > (u32)nextKind) || (curKind == nextKind && cur->id > (cur + 1)->id)) {
                    MI_CpuCopy8(cur, scratch, 0x28);
                    MI_CpuCopy8(cur + 1, cur, 0x28);
                    MI_CpuCopy8(scratch, cur + 1, 0x28);
                }
                i = i + 1;
                limit = list->count - 1;
                subLimit = limit - j;
                cur = cur + 1;
            } while (i < subLimit);
        }
        j = j + 1;
    } while (j < limit);
    return subLimit;
}

/* Set up the save manager's backup archive: when an archive already exists check
 * that its root header is a valid Wi-Fi save ("dsw2") and that it holds command
 * 0x1202 with status 2, then store the outcome in the manager's archive-status
 * byte (0x2050) and flag a fresh save (0x2052) when the archive is unusable. */
void SaveManager_CheckArchive(void *arg0) {
    s32 OS_GetLockID(void);
    void OS_ReleaseLockID(u8);
    s32 SaveDevice_IsReady(void);
    void CARD_LockBackup(u16);
    void CARD_UnlockBackup(u8);
    s32 SaveDevice_Transfer(s32, s32 *, s32, s32, s32, s32, s32, s32, s32);
    s32 SaveDevice_GetState(void);
    s32 SaveDevice_Configure(s32);
    u8 headerOk;
    u16 handle2;
    u16 handle;
    s32 result;

    if (SaveDevice_IsReady() == 0) {
        handle = 0;
    } else {
        handle = (u16)OS_GetLockID();
        ((void(*)(M2C_UNK))CARD_LockBackup)(handle);
        headerOk = (u8)SaveDevice_Configure(0x1202);
        ((void(*)(M2C_UNK))CARD_UnlockBackup)(handle);
        ((void(*)(M2C_UNK))OS_ReleaseLockID)(handle);
        if (headerOk == 0) {
            handle = 0;
        } else {
            if ((u8)SaveDevice_GetState() != 2) {
                handle = 0;
            } else {
                handle2 = (u16)OS_GetLockID();
                ((void(*)(M2C_UNK))CARD_LockBackup)(handle2);
                handle = (u8)SaveDevice_Transfer(0, &result, 4, 0, 0, 0, 6, 1, 0);
                ((void(*)(M2C_UNK))CARD_UnlockBackup)(handle2);
                ((void(*)(M2C_UNK))OS_ReleaseLockID)(handle2);
                if (handle == 0) {
                    handle = 0;
                }
            }
        }
    }
    M2C_FIELD(arg0, u8 *, 0x2050) = (u8)handle;
    if ((handle & 0xFF) == 0) {
        M2C_FIELD(arg0, u8 *, 0x2052) = 1;
    }
}

/* Probe the save archive before it is written: the archive must be initialised
 * and not marked unusable, and a 4-byte read at its start must succeed. Returns
 * 1 when the archive can be accessed, 0 otherwise. */
u8 SaveManager_ProbeArchive(void *manager) {
s32 OS_GetLockID(void); void OS_ReleaseLockID(u8); void CARD_LockBackup(u16); void CARD_UnlockBackup(u8);
s32 SaveDevice_Transfer(s32,s32 *,s32,s32,s32,s32,s32,s32,s32);
s32 header; u8 lockIdLow; u8 result; u16 lockId;
if(!M2C_FIELD(manager,u8 *,SAVE_MANAGER_ACTIVE)) return 0;
if(M2C_FIELD(manager,u8 *,SAVE_MANAGER_STATE)==1) return 0;
lockId=OS_GetLockID(); CARD_LockBackup(lockId); lockIdLow=lockId;
if(SaveDevice_Transfer(0,&header,4,0,0,0,6,1,0)) result=1; else result=0;
CARD_UnlockBackup(lockIdLow); OS_ReleaseLockID(lockIdLow); return result;
}

void SaveManager_ScanArchive(s32 arg0){
void *HeapAllocBlock(u32);void HeapFreeBlock(void *);s32 OS_GetLockID(void);void OS_ReleaseLockID(u8);void CARD_LockBackup(u16);void CARD_UnlockBackup(u8);
s32 SaveDevice_Transfer(s32,s32 *,s32,s32,s32,s32,s32,s32,s32);s32 IsSaveArchiveBlockValid(void *,void *);s32 SaveArchive_IsChecksumValid(void *,void *);s32 IsNodeChainValid(void *,u16);
void MI_CpuCopy32(void *,void *,u32);void MI_CpuFill32(s32,void *,u32);void MI_CpuFill8(void *,s32,u32);void MI_CpuCopy8(void *,void *,u32);
u8 *a=(u8 *)arg0;s32 selected;u8 *p;u8 *buf;u8 low;u32 stamp;s32 page;s32 i;u16 id;u8 ok0,ok1,ok2,ok;s32 off,off20,off256;u32 value,old; s32 newer;u8 rank; s32 shift;u32 *count;u16 invalid=65535;s32 mask;
buf=HeapAllocBlock(1024);selected=-1;stamp=0;page=0;if(!a[0x2050]||a[0x2052]==1)return;
id=OS_GetLockID();low=id;i=0;p=a;off=0;off20=20;off256=256;
for(;i<256;p+=12,off+=1024,off256+=1024,off20+=1024,i++){
CARD_LockBackup(low);ok0=SaveDevice_Transfer(off,(s32 *)buf,20,0,0,0,6,1,0)!=0;CARD_UnlockBackup(low);
if(!ok0){a[0x2052]=1;goto empty;}
if(!IsSaveArchiveBlockValid(a,buf))goto empty;
CARD_LockBackup(low);ok1=SaveDevice_Transfer(off20,(s32 *)(buf+20),M2C_FIELD(buf,u16*,12)-20,0,0,0,6,1,0)!=0;CARD_UnlockBackup(low);
if(ok1 == 0){a[0x2052]=1;goto empty;}
if(!SaveArchive_IsChecksumValid(a,buf))goto empty;
MI_CpuCopy32(buf+8,p,12);
if(buf[14]==1){
value=M2C_FIELD(buf,u16*,16)|(M2C_FIELD(buf,u16*,18)<<16);
if(selected!=-1){
old=M2C_FIELD(a+selected*12,u16*,8)|(M2C_FIELD(a+selected*12,u16*,10)<<16);
if((value&0xffff0000)==0xffff0000 && !(old&0xffff0000) && old!=0)newer=0;
else if(!(value&0xffff0000) && (old&0xffff0000)==0xffff0000 && value!=0)newer=1;
else newer=value>old;
if(!newer)continue;
}
stamp=value;page=0;selected=i;
CARD_LockBackup(low);ok2=SaveDevice_Transfer(off256,(s32 *)(buf+256),768,0,0,0,6,1,0)!=0;CARD_UnlockBackup(low);
if(!ok2)a[0x2052]=1;
}continue;
empty:MI_CpuFill32(0,p,12);
}
if(selected==-1){a[0x2051]=1;M2C_FIELD((unsigned short)a,s32*,0xc00)=-1;M2C_FIELD(a,s32*,0xc04)=-1;M2C_FIELD(a,s32*,0xc08)=0;MI_CpuFill8(a+0xc0c,0,64);goto fail;}
goto found;
fail:OS_ReleaseLockID(low);HeapFreeBlock(buf);return;
found:a[0x2051]=0;CARD_LockBackup(low);ok=SaveDevice_Transfer((selected<<10)+(page<<8),(s32 *)buf,256,0,0,0,6,1,0)!=0;CARD_UnlockBackup(low);
if(ok==1){M2C_FIELD(a,s32*,0xc00)=selected;M2C_FIELD(a,s32*,0xc04)=page;M2C_FIELD(a,u32*,0xc08)=stamp;MI_CpuCopy8(buf+20,a+0xc0c,64);}else{a[0x2052]=1;goto fail;}
OS_ReleaseLockID(low);HeapFreeBlock(buf);
mask=invalid-65536;for(i=0,p=a;i<256;i++,p+=12){rank=(a[0xc0c+(i>>2)]>>((i&3)*2))&3;if(rank==3&&p[6]==0){a[0xc0c+(i>>2)]&=(mask^(3<<((i&3)*2)));a[0x2053]=1;}}
count=(u32 *)(a+0x204c);M2C_FIELD(a,u32*,0x204c)=0;mask=invalid-65536;
for(i=0,p=a,off20=20;i<256;off20+=1024,i++,p+=12){
shift=(i&3)*2;if(((a[0xc0c+(i>>2)]>>shift)&3)!=3||p[6]==1)continue;
if(!IsNodeChainValid((unsigned)a,(u16)i)){a[0xc0c+(i>>2)]&=(mask^(3<<shift));a[0x2053]=1;continue;}
if(M2C_FIELD(p,u16*,8)!=65535)continue;
M2C_FIELD(a+M2C_FIELD(a,u32*,0x204c)*40,u16*,0xc4c)=i;
M2C_FIELD(a+M2C_FIELD(a,u32*,0x204c)*40,u8*,0xc4e)=p[6];
M2C_FIELD(a+M2C_FIELD(a,u32*,0x204c)*40,u8*,0xc4f)=0;
CARD_LockBackup(low);ok=SaveDevice_Transfer(off20,(s32 *)(((u8 *)((List_02074920 *)(a+0xc4c))->entries+M2C_FIELD(a,u32*,0x204c)*40)+4),36,0,0,0,6,1,0)!=0;CARD_UnlockBackup(low);
if(ok == 0){a[0x2052]=1;MI_CpuFill32(0,((u8 *)((List_02074920 *)(a+0xc4c))->entries+M2C_FIELD(a,u32*,0x204c)*40)+4,36);}
*count=*count+1;
}SaveList_Sort((List_02074920 *)(a+0xc4c));return;
}

/* Write a ranked list of entries to a save buffer. */
void func_020753f8(void *a, void *b, void *c, s32 d, u8 e, u32 f) {
void *HeapAllocBlock(u32); void HeapFreeBlock(void *); s32 OS_GetLockID(void); void OS_ReleaseLockID(u8); void CARD_LockBackup(u16); void CARD_UnlockBackup(u8);
void MI_CpuCopy32(void *,void *,u32); void MI_CpuFill32(s32,void *,u32); void MI_CpuCopy8(void *,void *,u32);
u32 SaveArchive_ComputeChecksum(void *,void *); s32 SaveDevice_Transfer(s32,s32 *,s32,s32,s32,s32,s32,s32,s32); s32 SaveDevice_WaitForTransferDone(void);
u8 *p; s32 idx; u16 prev; s32 mask; u16 id; u8 ok; u32 n;
if(!M2C_FIELD(a,u8 *,0x2050)||M2C_FIELD(a,u8 *,0x2052)==1||!e)return;
p=HeapAllocBlock(0x400); prev=0xffff; idx=FindFreeNode(a);
SaveList_AddRecord((List_02074920 *)((u8 *)a+0xc4c),(u16)idx,e,f,c);
id=OS_GetLockID();
mask=prev-0x10000;
while(d){
M2C_FIELD((u8 *)a+(idx>>2),u8 *,0xc0c)&=(mask^(3<<((idx&3)*2)));
M2C_FIELD((u8 *)a+(idx>>2),u8 *,0xc0c)|=3<<((idx&3)*2);
M2C_FIELD(p,u32 *,0)=0x32777364;
M2C_FIELD(p,u32 *,8)=M2C_FIELD((u8 *)a+idx*12,u32 *,0)+1;
if(prev==0xffff){
n=d+0x38; if(n>0x400)n=0x400; M2C_FIELD(p,u16 *,12)=n;
d-=M2C_FIELD(p,u16 *,12)-0x38;
M2C_FIELD(p,u32 *,20)=f;
if(c)MI_CpuCopy32(c,p+24,32);else MI_CpuFill32(0,p+24,32);
MI_CpuCopy32(b,p+0x38,M2C_FIELD(p,u16 *,12)-(s32)((p+0x38)-p));
b=(u8 *)b+(M2C_FIELD(p,u16 *,12)-(s32)((p+0x38)-p));
}else{
n=d+0x14;if(n>0x400)n=0x400;M2C_FIELD(p,u16 *,12)=n;
d-=M2C_FIELD(p,u16 *,12)-0x14;
MI_CpuCopy32(b,p+0x14,M2C_FIELD(p,u16 *,12)-0x14);
b=(u8 *)b+(M2C_FIELD(p,u16 *,12)-0x14);
}
M2C_FIELD(p,u8 *,14)=e;M2C_FIELD(p,u8 *,15)=1;M2C_FIELD(p,u16 *,16)=prev;
M2C_FIELD(p,u16 *,18)=d?FindFreeNode(a):0xffff;
M2C_FIELD(p,u32 *,4)=SaveArchive_ComputeChecksum(a,p);
CARD_LockBackup(id);
SaveDevice_Transfer((s32)p,(s32 *)(idx<<10),M2C_FIELD(p,u16 *,12),0,0,1,7,10,2);
ok=SaveDevice_WaitForTransferDone()!=0;((void(*)(u32))CARD_UnlockBackup)(id);
if(!ok){M2C_FIELD((u8 *)a+0x2000,u8 *,0x52)=1;break;}
MI_CpuCopy8(p+8,(u8 *)a+idx*12,12);
prev=idx;idx=M2C_FIELD(p,u16 *,18);
}
((void(*)(u32))OS_ReleaseLockID)(id);HeapFreeBlock(p);
}

