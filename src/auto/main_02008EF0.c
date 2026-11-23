/* 44 functions from 0x02008EF0 to 0x02009EB0 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u16 values[5]; } Unk02009B0CFields;
typedef struct { u16 values[6]; } Unk02009B0CRecord;
typedef struct Shared09d40 { u8 pad[0x388]; u32 value; } Shared09d40;
extern u16 gLinkInitialized;
extern s32 gFifoMessageHandlers[32];
void FifoReceiveHandler(void);
void InitSoundCommandQueue(void);
void InitSoundCommandLink(void);
void *AllocSoundCommand(int);
s32 Sound_FlushCommands(s32);
void Sound_InitCommandBuffer(void *);
typedef struct Link09a0c { void *owner; struct Link09a0c *next; } Link09a0c;

void func_0200973c(void);
typedef struct QueueNode09298 { struct QueueNode09298 *next; } QueueNode09298;
typedef struct { QueueNode09298 *head; s32 count, unk8, unkc; QueueNode09298 *tail; s32 index, unk18, pending, unk20; } State09100;
typedef struct Queue09298 { s32 unk0, unk4; QueueNode09298 *head, *tail; } Queue09298;

void func_02008ef0(M2C_UNK arg0) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0x17, arg0, 0, 0, 0);
}

void func_02008f10(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    SendArm7Message(0x19, arg0, arg1, arg2, arg3);
}

void func_02008f38(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    SendArm7Message(6, arg0, arg1, arg2, arg3);
}

void func_02008f60(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    SendArm7Message(7, arg0 | (arg4 << 0x18), arg1, arg2, arg3);
}

s32 SendArm7Message(int a,int b,int c,int d,int e){void *AllocSoundCommand(int);void *p=AllocSoundCommand(1);if(!p)return (s32)p;M2C_FIELD(p,s32 *,4)=a;M2C_FIELD(p,s32 *,8)=b;M2C_FIELD(p,s32 *,12)=c;M2C_FIELD(p,s32 *,16)=d;M2C_FIELD(p,s32 *,20)=e;return EnqueueSoundCommand(p);}

void func_02008fcc(void){extern s32 data_0212e000;extern M2C_UNK data_0212e004;if(data_0212e000)return;data_0212e000=1;InitMutex(&data_0212e004);InitSoundCommandQueue();func_0200973c();}

void Sound_LockMutex(void) {
    M2C_UNK LockMutex(M2C_UNK *);
    extern M2C_UNK data_0212e004;
    LockMutex(&data_0212e004);
}

void Sound_UnlockMutex(void){M2C_UNK UnlockMutex(M2C_UNK *);extern M2C_UNK data_0212e004;UnlockMutex(&data_0212e004);}

#pragma opt_strength_reduction off
#pragma peephole off
/* Set up the ARM7 sound command queue: chain the node pool into a free list,
 * reset the queue state and the driver work area, point the shared
 * command-argument buffer at its base and post command 29 with that buffer so
 * the ARM7 side knows where the arguments live. */
void InitSoundCommandQueue(void){
extern u8 gSoundCommandNodes[];
extern M2C_UNK gSoundCommandQueueState,gSoundWork,gSoundCommandQueueEnd,gSoundCommandBuffer;
extern s32 *gSoundCommandBufferPtr;
int index;void *command;
InitSoundCommandLink();
M2C_FIELD(&gSoundCommandQueueState,void **,0)=&gSoundCommandNodes;
index=0;goto check;
loop:M2C_FIELD(&gSoundCommandNodes,void **,index*24)=(char *)&gSoundCommandNodes+(index+1)*24;
index++;check: if(index<255)goto loop;
M2C_FIELD(&gSoundWork,int *,0xac8)=0;
M2C_FIELD(&gSoundCommandQueueState,void **,16)=&gSoundCommandQueueEnd;
M2C_FIELD(&gSoundCommandQueueState,int *,8)=0;
M2C_FIELD(&gSoundCommandQueueState,int *,12)=0;
M2C_FIELD(&gSoundCommandQueueState,int *,28)=0;
M2C_FIELD(&gSoundCommandQueueState,int *,20)=0;
M2C_FIELD(&gSoundCommandQueueState,int *,24)=0;
M2C_FIELD(&gSoundCommandQueueState,int *,32)=1;
M2C_FIELD(&gSoundCommandQueueState,int *,4)=0;
gSoundCommandBufferPtr=(s32 *)&gSoundCommandBuffer;
Sound_InitCommandBuffer((void *)gSoundCommandBufferPtr);
command=AllocSoundCommand(1);
if(!command)return;
M2C_FIELD(command,int *,4)=29;
M2C_FIELD(command,s32 **,8)=gSoundCommandBufferPtr;
EnqueueSoundCommand(command);Sound_FlushCommands(1);
}
#pragma peephole on
s32 Sound_DequeueCommand(s32 flags){
extern M2C_UNK gSoundCommandQueueState;extern QueueNode09298 *data_0212e044[];
s32 OS_DisableInterrupts(void);s32 func_0200982c(void);
s32 irq; QueueNode09298 *head,*oldTail,*tail;
volatile State09100 *appendState;
State09100 *state;
irq=OS_DisableInterrupts();
if(flags&1){
while(((State09100*)&gSoundCommandQueueState)->count==func_0200982c()){
OS_RestoreInterrupts(irq);WaitCycles(100);irq=OS_DisableInterrupts();
}
}else if(((State09100*)&gSoundCommandQueueState)->count==func_0200982c()){
OS_RestoreInterrupts(irq);return 0;
}
state=(State09100*)&gSoundCommandQueueState;
head=data_0212e044[state->index++];
if(state->index>8)state->index=0;
tail=head;
if(tail->next){do{tail=tail->next;}while(tail->next);}
appendState = (State09100*)&gSoundCommandQueueState;
oldTail = appendState->tail;
if(oldTail) oldTail->next=head;
else appendState->head=head;
state = (State09100*)&gSoundCommandQueueState;
state->tail=tail;
state->pending--;
state->count++;
OS_RestoreInterrupts(irq);
return (s32)head;
}
/* Take a free node of the ARM7 sound command queue so a command can be written
 * into it. Bit 0 of `flags` makes it wait for one: it first discards commands
 * that are still only queued when others are already in flight, or else flushes
 * the queue to the ARM7, then blocks until a command has been handed over. */
void *AllocSoundCommand(int flags) {
    void Sound_SignalArm7(void);
    s32 Sound_FlushCommands(s32);
    s32 Sound_IsCommandChannelReady(void);
    void *Sound_PopFreeCommand(void);
    s32 Sound_DequeueCommand(int);
    void *command;

    if (!Sound_IsCommandChannelReady()) return 0;
    command = Sound_PopFreeCommand();
    if (command) return command;
    if (!(flags & 1)) return 0;
    if (Sound_CountInFlightCommands() > 0) {
        while (Sound_DequeueCommand(0) != 0) {
        }
        command = Sound_PopFreeCommand();
        if (command) return command;
    } else {
        Sound_FlushCommands(1);
    }
    Sound_SignalArm7();
    do {
        Sound_DequeueCommand(1);
        command = Sound_PopFreeCommand();
    } while (!command);
    return command;
}


#pragma opt_common_subs off
s32 EnqueueSoundCommand(M2C_UNK *arg0) {
s32 OS_DisableInterrupts(void);extern M2C_UNK gSoundCommandQueueState;
s32 s=OS_DisableInterrupts(); M2C_UNK **p=(M2C_UNK **)&gSoundCommandQueueState;
if(p[3]==0)p[2]=arg0;else *p[3]=arg0;
p[3]=arg0;*arg0=0;return OS_RestoreInterrupts(s);
}
#pragma opt_common_subs reset
s32 Sound_FlushCommands(s32 flags) {
s32 OS_DisableInterrupts(void); s32 OS_RestoreInterrupts(s32);
s32 Sound_DequeueCommand(s32); M2C_UNK DC_FlushRange(M2C_UNK,M2C_UNK);
s32 SendFifoMessage(s32,M2C_UNK,s32); void Sound_SignalArm7(void);
extern M2C_UNK gSoundCommandQueueState; extern u8 gSoundCommandNodes[]; extern QueueNode09298 *data_0212e044[];
s32 irq=OS_DisableInterrupts();

if(!((State09100*)&gSoundCommandQueueState)->unk8){OS_RestoreInterrupts(irq);return 1;}
if(((State09100*)&gSoundCommandQueueState)->pending>=8){
if(!(flags&1)){OS_RestoreInterrupts(irq);return 0;}
do {Sound_DequeueCommand(1);} while(((State09100*)&gSoundCommandQueueState)->pending>=8);
if(!((State09100*)&gSoundCommandQueueState)->unk8){OS_RestoreInterrupts(irq);return 1;}
}
DC_FlushRange((M2C_UNK)&gSoundCommandNodes,0x1800);
if(SendFifoMessage(7,((State09100*)&gSoundCommandQueueState)->unk8,0)<0){
u8 *buf;
if(!(flags&1)){OS_RestoreInterrupts(irq);return 0;}
buf=&gSoundCommandNodes[0];
goto retry;
again: {
OS_RestoreInterrupts(irq);
Sound_DequeueCommand(0);
irq=OS_DisableInterrupts();
DC_FlushRange((M2C_UNK)buf,0x1800);
if(!((State09100*)&gSoundCommandQueueState)->unk8){OS_RestoreInterrupts(irq);return 1;}
}
retry:
if(((State09100*)&gSoundCommandQueueState)->pending>=8)goto again;
if(SendFifoMessage(7,((State09100*)&gSoundCommandQueueState)->unk8,0)<0)goto again;
}
{

s32 idx=((State09100*)&gSoundCommandQueueState)->unk18;
data_0212e044[idx]=(QueueNode09298*)((State09100*)&gSoundCommandQueueState)->unk8;
((State09100*)&gSoundCommandQueueState)->unk18=idx+1;
if(((State09100*)&gSoundCommandQueueState)->unk18>8)((State09100*)&gSoundCommandQueueState)->unk18=0;
}
((State09100*)&gSoundCommandQueueState)->unk8=0;
((State09100*)&gSoundCommandQueueState)->unkc=0;
((State09100*)&gSoundCommandQueueState)->pending++;
((State09100*)&gSoundCommandQueueState)->unk20++;
OS_RestoreInterrupts(irq);
if(flags&2)Sound_SignalArm7();
return 1;
}
#pragma opt_common_subs reset
/* Block until the ARM7 sound driver has processed every command queued up to
 * the counter `mark`: drop commands still only queued, wake the ARM7, then wait
 * for its completion counter to reach the mark.  Returns at once if it already
 * has. */
void Sound_WaitForCommand(int mark) {
void Sound_SignalArm7(void);
if(Sound_IsCommandReached(mark))return;
while(Sound_DequeueCommand(0)){}
if(Sound_IsCommandReached(mark))return;
Sound_SignalArm7();
if(Sound_IsCommandReached(mark))return;
do {Sound_DequeueCommand(1);}while(!Sound_IsCommandReached(mark));
}

s32 Sound_GetCommandCounter(void) {
s32 OS_DisableInterrupts(void);extern M2C_UNK gSoundCommandQueueState;
s32 s=OS_DisableInterrupts();s32 r;
if(M2C_FIELD(&gSoundCommandQueueState,s32 *,8)==0)r=M2C_FIELD(&gSoundCommandQueueState,s32 *,4);else r=M2C_FIELD(&gSoundCommandQueueState,s32 *,32);
OS_RestoreInterrupts(s);return r;
}

/* Test whether the driver's completed-command counter has reached a queue mark, accounting for wraparound. */
s32 Sound_IsCommandReached(u32 commandMark) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    extern M2C_UNK gSoundCommandQueueState;
    s32 interruptState = OS_DisableInterrupts();
    s32 reached;
    u32 completedCount = M2C_FIELD(&gSoundCommandQueueState, u32 *, 4);

    if (commandMark > completedCount) {
        if (commandMark - completedCount < 0x80000000U) {
            reached = 0;
        } else {
            reached = 1;
        }
    } else {
        if (completedCount - commandMark < 0x80000000U) {
            reached = 1;
        } else {
            reached = 0;
        }
    }
    OS_RestoreInterrupts(interruptState);
    return reached;
}

s32 func_02009574(void){s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);extern M2C_UNK gSoundCommandQueueState;s32 state=OS_DisableInterrupts();s32 count=0;void *p=M2C_FIELD(&gSoundCommandQueueState,void **,0);if(p){do{p=*(void **)p;count++;}while(p);}OS_RestoreInterrupts(state);return count;}

s32 func_020095b0(void){s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);extern M2C_UNK gSoundCommandQueueState;s32 state=OS_DisableInterrupts();s32 count=0;void *p=M2C_FIELD(&gSoundCommandQueueState,void **,8);if(p){do{p=*(void **)p;count++;}while(p);}OS_RestoreInterrupts(state);return count;}

s32 Sound_CountInFlightCommands(void) {
    s32 func_02009574();
    s32 func_020095b0();
    s32 temp_r4;

    temp_r4 = func_02009574();
    return (0x100 - temp_r4) - func_020095b0();
}

void Sound_CommandChannelHandler(int unused,int arg1) {
s32 OS_DisableInterrupts(void);s32 s=OS_DisableInterrupts();func_020097bc(arg1);OS_RestoreInterrupts(s);
}

/* Ready the ARM7 sound command channel: install its FIFO message handler and,
 * when the channel is usable, wait until the ARM7 firmware reports it ready. */
void InitSoundCommandLink(void) {
    M2C_UNK WaitCycles(M2C_UNK);
    s32 Sound_IsCommandChannelReady();
    M2C_UNK SetFifoMessageHandler(M2C_UNK, M2C_UNK *);
    s32 IsFifoMessageReady(M2C_UNK, M2C_UNK);
    extern void Sound_CommandChannelHandler(int, int);
    SetFifoMessageHandler(SND_CMD_FIFO_TAG, (M2C_UNK *)&Sound_CommandChannelHandler);
    if (!Sound_IsCommandChannelReady()) return;
    if (IsFifoMessageReady(SND_CMD_FIFO_TAG, 1)) return;
    do {
        WaitCycles(SND_CMD_LINK_POLL_DELAY);
    } while (!IsFifoMessageReady(SND_CMD_FIFO_TAG, 1));
}

void Sound_SignalArm7(void) {
    s32 SendFifoMessage(M2C_UNK, M2C_UNK, M2C_UNK);
    do {

    } while (SendFifoMessage(7, 0, 0) < 0);
}

void *Sound_PopFreeCommand(void){s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);extern M2C_UNK gSoundCommandQueueState;s32 state=OS_DisableInterrupts();void *p=M2C_FIELD(&gSoundCommandQueueState,void **,0);void *next;if(!p){OS_RestoreInterrupts(state);return 0;}next=*(void **)p;M2C_FIELD(&gSoundCommandQueueState,void **,0)=next;if(!next)M2C_FIELD(&gSoundCommandQueueState,s32 *,16)=0;OS_RestoreInterrupts(state);return p;}

s32 Sound_IsCommandChannelReady(void){s32 func_020062b4(void);s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);s32 state,v,result;if(!func_020062b4())return 1;state=OS_DisableInterrupts();*(volatile s32 *)0x04fff200=16;v=*(volatile s32 *)0x04fff200;OS_RestoreInterrupts(state);if(v)result=1;else result=0;return result;}

void func_0200973c(void){extern M2C_UNK data_0212fb00;int i=0;u8 *p=(u8 *)&data_0212fb00;int zero=i;do{*(s32 *)p=zero;*(s32 *)(p+4)=zero;i++;p[8]=zero;p+=12;}while(i<8);}

void func_0200976c(s32 arg0) {
    extern M2C_UNK data_0212fb00;
    s32 temp_r1;

    temp_r1 = (arg0 * 0xC) + (s32) &data_0212fb00;
    M2C_FIELD(temp_r1, u8 *, 8) = (u8) (M2C_FIELD(temp_r1, u8 *, 8) + 1);
}

u8 func_0200978c(int a,int b,int c){extern M2C_UNK data_0212fb00;void *p=(char *)&data_0212fb00+a*12;M2C_FIELD(p,int *,0)=b;M2C_FIELD(p,int *,4)=c;return ++M2C_FIELD(p,u8 *,8);}

s32 func_020097bc(s32 a){
extern M2C_UNK data_0212fb00;void *p=(char *)&data_0212fb00+(a&255)*12;
if(M2C_FIELD(p,u8 *,8)!=(u8)(a>>8))return;
if(M2C_FIELD(p,void (**)(int),0))M2C_FIELD(p,void (**)(int),0)(M2C_FIELD(p,int *,4));
}

s32 func_02009800(void){M2C_UNK DC_InvalidateRange(s32 *,M2C_UNK);extern s32 *gSoundCommandBufferPtr;DC_InvalidateRange(gSoundCommandBufferPtr+1,4);return gSoundCommandBufferPtr[1];}

s32 func_0200982c(void) {
    M2C_UNK DC_InvalidateRange(s32 *, M2C_UNK);
    extern s32 *gSoundCommandBufferPtr;
    DC_InvalidateRange(gSoundCommandBufferPtr, 4);
    return *gSoundCommandBufferPtr;
}

/* Resets the ARM7 sound driver's shared command-argument buffer: clears its
 * handshake counters and status words, fills the 16 argument entries' parameter
 * arrays with -1 and their value words with 0, and clears the final parameter
 * array, then flushes the buffer for the ARM7 to read. */
void Sound_InitCommandBuffer(void *buffer){
int entryIndex,paramIndex;void *entry=buffer;
M2C_FIELD(buffer,int *,SND_CMD_BUFFER_COUNTER1)=0;M2C_FIELD(buffer,s16 *,SND_CMD_BUFFER_UNK08)=0;M2C_FIELD(buffer,s16 *,SND_CMD_BUFFER_UNK0A)=0;M2C_FIELD(buffer,int *,SND_CMD_BUFFER_COUNTER0)=0;
for(entryIndex=0;entryIndex<SND_CMD_BUFFER_ENTRY_COUNT;entryIndex++,entry=(char *)entry+SND_CMD_BUFFER_ENTRY_STRIDE){M2C_FIELD(entry,int *,SND_CMD_BUFFER_ENTRY_VALUE)=0;for(paramIndex=0;paramIndex<SND_CMD_BUFFER_PARAM_COUNT;paramIndex++)((s16 *)entry+paramIndex)[SND_CMD_BUFFER_ENTRY_PARAMS/2]=-1;}
for(paramIndex=0;paramIndex<SND_CMD_BUFFER_PARAM_COUNT;paramIndex++)((s16 *)buffer+paramIndex)[SND_CMD_BUFFER_TAIL_PARAMS/2]=-1;
DC_FlushRange(buffer,SND_CMD_BUFFER_SIZE);
}

/* Convert a NitroSDK volume (0 is full, down to -723 in the SDK's logarithmic
 * units) into the ARM7 volume word: the linear amplitude byte from
 * gSoundVolumeTable in the low 8 bits and the 2-bit volume step picked by the
 * -60/-120/-240 boundaries in bits 8-9. */
u16 SND_CalcVolume(s32 volume) {
    extern u8 gSoundVolumeTable[];
    int step;
    u8 amplitude;

    if (volume < -723) volume = -723;
    else if (volume > 0) volume = 0;

    amplitude = gSoundVolumeTable[volume + 723];

    if (volume < -240) step = 3;
    else if (volume < -120) step = 2;
    else if (volume < -60) step = 1;
    else step = 0;

    return amplitude | (step << 8);
}

/* Make `newOwner` the owner of link slot `index` of `object`: detach the slot
 * from its previous owner's linked list, prepend it to newOwner's list (both
 * list heads live at +0x18) and clean the slot's and the owners' caches; holds
 * the sound mutex throughout. */
void Link_SetSlotOwner(void *object,int index,void *newOwner){
Link09a0c *entry,*p,*next;void *previousOwner;
Sound_LockMutex();
previousOwner=((Link09a0c *)object+index)[3].owner;
if(previousOwner){
if(newOwner==previousOwner){Sound_UnlockMutex();return;}
entry=(Link09a0c *)((char *)object+24)+index;
p=M2C_FIELD(previousOwner,Link09a0c **,24);
if(entry==p){M2C_FIELD(previousOwner,Link09a0c **,24)=((Link09a0c *)object+index)[3].next;DC_CleanRange(((Link09a0c *)object+index)[3].owner,60);}
else{
if(p){do{next=p->next;if(entry==next)break;p=next;}while(next);}
p->next=((Link09a0c *)object+index)[3].next;DC_CleanRange(p,8);
}
}
p=M2C_FIELD(newOwner,Link09a0c **,24);
M2C_FIELD(newOwner,Link09a0c **,24)=(Link09a0c *)((char *)object+24)+index;
((Link09a0c *)object+index)[3].next=p;
((Link09a0c *)object+index)[3].owner=newOwner;
Sound_UnlockMutex();DC_CleanRange(object,60);DC_CleanRange(newOwner,60);
}

/* Detaches all four link slots of an object from their owners' slot lists,
 * cleaning the caches of the slots and of the owners they had; holds the sound
 * mutex throughout. */
void Link_ClearSlotOwners(void *object) {
    int i;
    Link09a0c *slot, *p, *next;
    void *owner;

    Sound_LockMutex();
    slot = (Link09a0c *)((char *)object + 24);
    for (i = 0; i < 4; i++, slot++) {
        owner = ((Link09a0c *)object + i)[3].owner;
        if (owner) {
            p = M2C_FIELD(owner, Link09a0c **, 24);
            if (slot == p) {
                M2C_FIELD(owner, Link09a0c **, 24) = ((Link09a0c *)object + i)[3].next;
                DC_CleanRange(owner, 60);
            } else {
                if (p) {
                    do {
                        next = p->next;
                        if (slot == next) break;
                        p = next;
                    } while (next);
                }
                p->next = ((Link09a0c *)object + i)[3].next;
                DC_CleanRange(p, 8);
            }
        }
    }
    Sound_UnlockMutex();
}

void func_02009aa4(void *arg0) {
    void *temp_r6;
    void *var_r0;

    Sound_LockMutex();
    var_r0 = M2C_FIELD(arg0, void **, 0x18);
    if (var_r0 != NULL) {
        do {
            temp_r6 = M2C_FIELD(var_r0, void **, 4);
            M2C_FIELD(var_r0, s32 *, 0) = 0;
            M2C_FIELD(var_r0, void **, 4) = NULL;
            DC_CleanRange(var_r0, 8);
            var_r0 = temp_r6;
        } while (temp_r6 != NULL);
    }
    Sound_UnlockMutex();
}

void InitPackedTableCursor(u32 *a){volatile u32 zero[2];a[0]=0;zero[0]=0;zero[1]=0;a[1]=0;}

/* Iterate the entries of a packed animation table: read the entry-table word
   (entry type in the low byte, data offset in the upper 24 bits) and copy the
   associated record into outEntry. Types 1-5 copy one shared 10-byte field
   block; type 16 walks a variable run of 12-byte records; type 17 up to eight
   12-byte records prefixed by a present-flags table. cursor holds the iterator
   state (entry index, intra-entry index); returns 1 while entries remain. */
s32 IteratePackedTableRecord(void *animation,u8 *outEntry,s32 *cursor) {
while((u32)cursor[0]<M2C_FIELD(animation,u32*,0x38)){
u32 entry=M2C_FIELD((u8*)animation+cursor[0]*4,u32*,0x3c);
s32 entryType=entry&255;
u32 dataOffset=entry>>8;
outEntry[0]=entry;
switch(entryType){
case 1: case 2: case 3: case 4: case 5:
*(Unk02009B0CFields*)(outEntry+2)=*(Unk02009B0CFields*)((u8*)animation+dataOffset);
cursor[0]++; return 1;
case 16:{
u8 *recordSet=(u8*)animation+dataOffset;
while((u32)cursor[1]<(u32)(recordSet[1]-recordSet[0]+1)){
*(Unk02009B0CRecord*)outEntry=*(Unk02009B0CRecord*)(recordSet+2+cursor[1]*12);
cursor[1]++;return 1;
}
break;
}
case 17:{
u8 *recordSet=(u8*)animation+dataOffset;
while((u32)cursor[1]<8){
if(!recordSet[cursor[1]])break;
*(Unk02009B0CRecord*)outEntry=*(Unk02009B0CRecord*)(recordSet+8+cursor[1]*12);
cursor[1]++;return 1;
}
break;
}
}
cursor[0]++;cursor[1]=0;
}
return 0;
}

s32 GetPackedTableCount(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x38);
}

void SetPackedTableEntry(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK DC_CleanRange(s32, M2C_UNK);
    Sound_LockMutex();
    M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 0x3C) = arg2;
    DC_CleanRange(arg0 + 0x3C + (arg1 * 4), 4);
    Sound_UnlockMutex();
}

void *GetPackedTableEntry(char *a,s32 b){
void *v;Sound_LockMutex();v=M2C_FIELD(a+b*4,void **,60);
if(v){if((u32)v<0x2000000U)v=a+(u32)v;}else v=0;
Sound_UnlockMutex();return v;
}

void PXI_Init(void) {
    M2C_UNK InitArm7Link();
    InitArm7Link();
}

#pragma scheduling off
/* Connect to the ARM7 firmware once: reset the FIFO channel, install the FIFO
 * receive interrupt and clear the message handlers, then wait until the
 * firmware's channel report reads idle, stopping every channel it names. */
s32 InitArm7Link(void){
s32 OS_DisableInterrupts(void);s32 state=OS_DisableInterrupts();int i,timeout,value,stable;
if(!gLinkInitialized){
gLinkInitialized=1;
{Shared09d40 *p=(Shared09d40 *)0x027ffc00; p->value=0;}
for(i=0;i<32;i++)gFifoMessageHandlers[i]=0;
*(volatile u16 *)0x04000184=0xc408;
OS_SetIrqMask(0x40000);OS_SetIrqHandler(0x40000,FifoReceiveHandler);OS_EnableIrqMask(0x40000);
stable=0;
for(;;){value=*(volatile u16 *)0x04000180&15;
*(volatile u16 *)0x04000180=value<<8;
if(!value&&stable>4)break;
timeout=1000;
while((*(volatile u16 *)0x04000180&15)==value){
if(timeout<=0){stable=0;break;}timeout--;
}
stable++;
}
}
return OS_RestoreInterrupts(state);
}
#pragma scheduling on
s32 SetFifoMessageHandler(s32 a,M2C_UNK *b){
s32 OS_DisableInterrupts(void);extern s32 gFifoMessageHandlers[];
s32 s=OS_DisableInterrupts();s32 *base=(s32 *)0x027ffc00;
gFifoMessageHandlers[a]=(s32)b;
if(b)base[226]|=1<<a;
else base[226]&=~(1<<a);
return OS_RestoreInterrupts(s);
}

s32 IsFifoMessageReady(s32 a, s32 b) {
    extern u8 data_027ffc00[];
    u32 val = *((u32 *)((u8 *)data_027ffc00 + b * 4 + 0x388));
    s32 r = 1;
    if (!(val & (1 << a))) {
        r = 0;
    }
    return r;
}

