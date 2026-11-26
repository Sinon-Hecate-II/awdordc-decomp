/* 13 functions from 0x02014B34 to 0x02015AA0 (main), found by ds-decomp. */
#include "common.h"

/* Start the battle of the next player group that has joined players: cycle to the
 * group after the one started last, send that group's unit roster (command 3) to its
 * members and return the send result, or 21 when no group has players yet.
 * The playerMask argument is unused: the mask is rebuilt from the player states. */
s32 StartGroupBattle(u16 playerMask) {
 s32 SerializeCommand(s8 *,void *);s32 SendMatchPacket(s32,u16,s32);
 extern u8 gGroupStartCursor;extern void *gMbWork;
 M2C_UNK MI_CpuFill8(M2C_UNK,M2C_UNK,M2C_UNK);M2C_UNK MI_CpuCopy8(M2C_UNK,M2C_UNK,M2C_UNK);
 void *work;u8 command[6];u8 members[16];s32 writePos;s8 group=-1;u16 idx,idx2,mask=0;u8 tries,candidate;s8 owner;
 MI_CpuFill8((s32)members,0,16);work=gMbWork;
 for(idx=1;idx<=15;idx++){
 if(M2C_FIELD(work+idx*4,s32 *,MB_PLAYER_STATE)==MB_PLAYER_STATE_GROUPED){
 owner=M2C_FIELD(work+idx,s8 *,MB_PLAYER_GROUP);members[owner]++;
 }}
 candidate=gGroupStartCursor;
 for(tries=0;tries<16;tries++){
 candidate=(candidate+1)%16;
 if(M2C_FIELD(work+MB_GROUPS+candidate*MB_GROUP_STRIDE,u8 *,MB_GROUP_ACTIVE)&&members[candidate]){
 group=candidate;break;
 }}
 if(group==-1)return 21;
 gGroupStartCursor=group;
 for(idx2=1;idx2<=15;idx2++){
 if(M2C_FIELD(work+idx2*4,s32 *,MB_PLAYER_STATE)==MB_PLAYER_STATE_GROUPED && group==M2C_FIELD(work+idx2,s8 *,MB_PLAYER_GROUP))mask|=1<<idx2;
 }
 command[0]=3;*(s16 *)(command+2)=group;
 writePos=SerializeCommand((s8 *)command,work);
 if(writePos)MI_CpuCopy8((s32)(gMbWork+MB_GROUPS+group*MB_GROUP_STRIDE),writePos,0xe4);
 return SendMatchPacket(0xea,mask,(s32)gMbWork);
}

/* Multiboot image-load task: read the cached block the loader picked (arg0+0x10)
 * out of the archive named in the load queue (arg0+0x14) into the block's own
 * buffer, over the block's range [offset, offset+size).  Marks the block resident
 * once the whole range is read; on failure it resets the block to the empty one
 * at offset 0 and still marks it resident. */
void Mb_LoadBlockTask(void *arg0) {
 s32 FindArchive(void *,s32);
 void InitFileRequest(void *);
 s32 OpenFileDirect(void *,s32,s32,s32,s32);
 void CloseFileRequest(void *);
 s32 FileRead(void *,s32,s32);
 u32 request[18];
 MbLoadBlock *block;
 MbLoadQueue *queue;
 s32 offset;
 queue=M2C_FIELD(arg0,MbLoadQueue **,0x14); block=M2C_FIELD(arg0,MbLoadBlock **,0x10);
 InitFileRequest(request);
 offset=block->offset;
 if(OpenFileDirect(request,FindArchive(&queue->name,queue->nameLength),offset,offset+block->size,-1)!=0){
 if(block->size==FileRead(request,block->data,block->size)) block->state=MB_LOAD_STATE_RESIDENT;
 CloseFileRequest(request);
 }
 if(block->state==MB_LOAD_STATE_RESIDENT)return;
 block->offset=0; block->state=MB_LOAD_STATE_RESIDENT;
}

#pragma push
#pragma opt_common_subs off
s32 func_02014d6c(void) {
    extern void *gMbWork;
    void AdvanceGroupChunkCursor(s32);
    s32 Mb_GetChunkTransfer(void *,void *,u16,void *);
    s32 SerializeCommand(s8 *,void *);
    s32 Mb_CopyImageRange(void *,u32,s32,u32);
    s32 func_0201874c(void *);
    void SystemHalt(void);
    void Mb_QueueTask(void *,void (*)(void *),s32,s32);
    s32 SendMatchPacket(s32,u16,s32);
    u8 packet[8];
    u32 output[4];
    u8 tries,candidate;
    s32 i;
    s32 offset;
    void *buffer;
    void *task;
    u32 *best;
    void *base;
    void *entry;
    void *loopEntry;
    u32 (*records)[4];
    s32 j;
    s32 command;
    u32 size;
    u32 bank;
    s32 *table;
    void *interior;
    u32 position;
    u32 previous;
    if (!M2C_FIELD(gMbWork,u8 *,0x1524)) return 21;
    for (tries=0;tries<16;tries++) {
        M2C_FIELD(gMbWork,u8 *,0x1525)=(M2C_FIELD(gMbWork,u8 *,0x1525)+1)%16;
        base=gMbWork;
        candidate=M2C_FIELD(base,u8 *,0x1525);
        loopEntry=base+candidate*0x5d4;
        if (M2C_FIELD(loopEntry,u8 *,0x1d52) && M2C_FIELD(loopEntry,u16 *,0x1d4c)) break;
    }
    if (tries==16) return 21;
    AdvanceGroupChunkCursor(candidate);
    base=gMbWork;
    i=M2C_FIELD(base,u8 *,0x1525);
    if (!Mb_GetChunkTransfer(output,base+0x1d2c+i*0x5d4,M2C_FIELD(base+i*0x5d4,u16 *,0x1d48),base+0x1788+i*0x5d4)) return 21;
    base=gMbWork;
    packet[0]=4;
    *(u16 *)(packet+2)=M2C_FIELD(base,u8 *,0x1525);
    *(u16 *)(packet+4)=M2C_FIELD(base+M2C_FIELD(base,u8 *,0x1525)*0x5d4,u16 *,0x1d48);
    command=SerializeCommand((s8 *)packet,base);
    base=gMbWork;
    entry=base+M2C_FIELD(base,u8 *,0x1525)*0x5d4;
    bank=((u8 *)output)[12];
    position=output[2];
    interior=entry+0x1000;
    table=M2C_FIELD(interior,s32 **,0xd58);
    previous=M2C_FIELD(entry+bank*4,u32 *,0x1d2c);
    offset=table[bank]+(position-previous);
    buffer=M2C_FIELD(interior,void **,0xd54);
    size=output[1];
    if (!Mb_CopyImageRange(buffer,offset,command,size)) {
        task=gMbWork+0x7ce0;
        if (!func_0201874c(task)) {
            if (M2C_FIELD(buffer,u32 *,0)) M2C_FIELD(buffer,u32 *,0)--;
            else {
                records=(u32 (*)[4])(buffer+0x30);
                best=0;
                for(j=0;j<4;j++) {
                    if (records[j][3]==2) {
                        if (!best || M2C_FIELD(best,u32 *,0)>records[j][0]) best=records[j];
                    }
                }
                if (!best) SystemHalt();
                M2C_FIELD(buffer,u32 *,0)=2;
                M2C_FIELD(best,s32 *,12)=1;
                M2C_FIELD(best,u32 *,0)=offset&~31;
                M2C_FIELD(task,void **,16)=best;
                M2C_FIELD(task,void **,20)=buffer;
                Mb_QueueTask(task,Mb_LoadBlockTask,0,4);
            }
        }
        return 21;
    }
    base=gMbWork;
    return SendMatchPacket(output[1]+6,M2C_FIELD(base+M2C_FIELD(base,u8 *,0x1525)*0x5d4,u16 *,0x1d4c),(s32)base);
}
#pragma pop
/* Select units by state into priority groups, then dispatch the matching network action. */
void func_02015008(void) {
extern void *gMbWork;
void FillU16(s32,void *,s32); s32 Mb_SendPlayerCommand(s32,u16); s32 StartGroupBattle(u16); s32 func_02014d6c(void);
u16 masks[5];u16 i; s32 result;
FillU16(0,masks,10);
for(i=1;i<=15;i++){
switch(M2C_FIELD((u8 *)gMbWork+4*i,s32 *,0x14e4)){
case 2:masks[0]|=1<<i;break;
case 5:masks[1]|=1<<i;break;
case 4:masks[2]|=1<<i;break;
case 8:masks[3]|=1<<i;break;
case 11:masks[4]|=1<<i;break;
}
}
if(masks[3])result=Mb_SendPlayerCommand(5,masks[3]);
else if(masks[0])result=Mb_SendPlayerCommand(1,masks[0]);
else if(masks[4])result=Mb_SendPlayerCommand(6,masks[4]);
else if(masks[2])result=Mb_SendPlayerCommand(2,masks[2]);
else if(masks[1])result=StartGroupBattle(masks[1]);
else result=func_02014d6c();
if(result==21)Mb_SendPlayerCommand(0,0xffff);
}

/* Move group `group`'s outgoing chunk cursor on towards the chunk its members
 * asked for: one step on while that chunk is at most two ahead, otherwise
 * straight to it.  Does nothing while no member of the group waits for a chunk
 * (the group record's active flag, cursor, goal and pending-member mask live at
 * MB_GROUPS + MB_GROUP_ACTIVE / CHUNK_CURSOR / CHUNK_GOAL / 0x5C4). */
void AdvanceGroupChunkCursor(s32 group) {
 extern s32 gGroupChunkPendingMask;
    extern void *gMbWork;
 u16 cursor,goal; void *record;
 if(!(gGroupChunkPendingMask & (1<<group)))return;
 record=(void *)(group*0x5d4+gMbWork);
 if(M2C_FIELD(record,u8 *,0x1d52)!=0 && M2C_FIELD(record,u16 *,0x1d4c)!=0){
 cursor=M2C_FIELD(record+0x1d00,u16 *,0x48); goal=M2C_FIELD(record,u16 *,0x1d4a);
 if((u32)goal<=(u32)cursor && (s32)cursor<=goal+2){M2C_FIELD(record+0x1d00,u16 *,0x48)=cursor+1;return;}
 M2C_FIELD(record+0x1d00,u16 *,0x48)=goal;
 }
}

u32 func_02015204(u32 arg0, u32 arg1) {
    u32 var_r1;

    var_r1 = arg1;
    if (var_r1 <= arg0) {
        var_r1 = arg0;
    }
    return var_r1;
}

/* Whether `player` is a multiboot player number (1..MB_PLAYER_MAX); 0 is the
 * local console and higher values are unused slots. */
s32 Mb_IsValidPlayer(u32 player) {
    if ((player >= 1U) && (player <= MB_PLAYER_MAX)) {
        return 1;
    }
    return 0;
}

void func_02015230(M2C_UNK arg0, s16 arg1) {
    M2C_UNK Mb_DispatchPlayerEvent(M2C_UNK, M2C_UNK, s16 *);
    s16 sp0;

    sp0 = arg1;
    Mb_DispatchPlayerEvent(arg0, 0xD, &sp0);
}

