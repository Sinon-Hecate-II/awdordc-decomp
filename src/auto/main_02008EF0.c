/* 44 functions from 0x02008EF0 to 0x02009EB0 (main), found by ds-decomp. */
#include "common.h"
#include "sound.h"

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

void ClearSoundChannelCallbacks(void);
typedef struct QueueNode09298 { struct QueueNode09298 *next; } QueueNode09298;
typedef struct { QueueNode09298 *head; s32 count, unk8, unkc; QueueNode09298 *tail; s32 index, unk18, pending, unk20; } State09100;
typedef struct Queue09298 { s32 unk0, unk4; QueueNode09298 *head, *tail; } Queue09298;

/* ARM7 sound command 0x17: silence the sound driver.  HaltWithMessage sends it
 * with 0 after fading the music out, before it halts the game. */
void Sound_StopAllSound(M2C_UNK arg) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0x17, arg, 0, 0, 0);
}

/* Send ARM7 sound command 0x19 with its four arguments.  The streamed voice's
 * teardown (StopStreamVoice) is its only caller: it sends the command with all
 * zeros once the stream reached its end, to end the driver's side of the stream. */
void Sound_EndStreamSound(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    SendArm7Message(0x19, arg0, arg1, arg2, arg3);
}

/* Send ARM7 sound command 6 for hardware `channel`: set channel parameter
 * `parameter` (4 = pan, 6 = volume) to `value` with curve `mode`. */
void Sound_SetChannelParameter(M2C_UNK channel, M2C_UNK parameter, M2C_UNK value, s32 mode) {
    SendArm7Message(6, channel, parameter, value, mode);
}

/* Send ARM7 sound command 7 to set a sequence player's parameter: `player`
 * (low 24 bits) with `mode` in the top byte of the same word, the value, the
 * parameter id (9 = pan, 0xC = the other player parameter in use) and the
 * duration the change runs over. */
void Sound_SetPlayerParameter(s32 player, M2C_UNK value, M2C_UNK parameter, s32 duration, s32 mode) {
    SendArm7Message(7, player | (mode << 0x18), value, parameter, duration);
}

/* Send one command to the ARM7 sound driver: take a command node, fill in its
 * command id and four arguments, and queue it.  Returns 0 if no node could be
 * taken. */
s32 SendArm7Message(int commandId, int arg0, int arg1, int arg2, int arg3) {
    void *AllocSoundCommand(int);
    void *command = AllocSoundCommand(1);
    if (!command) return (s32) command;
    M2C_FIELD(command, s32 *, SOUND_CMD_NODE_ID) = commandId;
    M2C_FIELD(command, s32 *, SOUND_CMD_NODE_ARG0) = arg0;
    M2C_FIELD(command, s32 *, SOUND_CMD_NODE_ARG1) = arg1;
    M2C_FIELD(command, s32 *, SOUND_CMD_NODE_ARG2) = arg2;
    M2C_FIELD(command, s32 *, SOUND_CMD_NODE_ARG3) = arg3;
    return EnqueueSoundCommand(command);
}

/* Bring up the sound command layer once: initialise its mutex, build the ARM7
 * command queue and clear the per-channel callback table. */
void InitSoundCommandSystem(void) {
    extern s32 gSoundCommandSystemReady;
    extern M2C_UNK gSoundMutex;
    if (gSoundCommandSystemReady) return;
    gSoundCommandSystemReady = 1;
    OS_InitMutex(&gSoundMutex);
    InitSoundCommandQueue();
    ClearSoundChannelCallbacks();
}

/* Lock the sound layer's shared OSMutex, guarding the ARM7 command queue. */
void Sound_LockMutex(void) {
    void LockMutex(OSMutex *);
    extern M2C_UNK gSoundMutex;
    LockMutex((OSMutex *)&gSoundMutex);
}

/* Release the mutex that guards the sound command queue. */
void Sound_UnlockMutex(void) {
    void UnlockMutex(void *);
    extern M2C_UNK gSoundMutex;
    UnlockMutex((OSMutex *)&gSoundMutex);
}

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
extern M2C_UNK gSoundCommandQueueState;extern QueueNode09298 *gSoundCommandSentBatches[];
s32 OS_DisableInterrupts(void);s32 Sound_GetProcessedCommandCount(void);
s32 irq; QueueNode09298 *head,*oldTail,*tail;
volatile State09100 *appendState;
State09100 *state;
irq=OS_DisableInterrupts();
if(flags&1){
while(((State09100*)&gSoundCommandQueueState)->count==Sound_GetProcessedCommandCount()){
OS_RestoreInterrupts(irq);WaitCycles(100);irq=OS_DisableInterrupts();
}
}else if(((State09100*)&gSoundCommandQueueState)->count==Sound_GetProcessedCommandCount()){
OS_RestoreInterrupts(irq);return 0;
}
state=(State09100*)&gSoundCommandQueueState;
head=gSoundCommandSentBatches[state->index++];
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
extern M2C_UNK gSoundCommandQueueState; extern u8 gSoundCommandNodes[]; extern QueueNode09298 *gSoundCommandSentBatches[];
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
gSoundCommandSentBatches[idx]=(QueueNode09298*)((State09100*)&gSoundCommandQueueState)->unk8;
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

/* Take a mark to wait on with Sound_WaitForCommand: with commands queued, the
 * number the batch they are sent as will take once the ARM7 reports it; with
 * nothing queued, the count of batches the ARM7 has already taken, which is
 * reached at once. */
s32 Sound_GetQueueMark(void) {
    s32 OS_DisableInterrupts(void);
    extern M2C_UNK gSoundCommandQueueState;
    s32 irq = OS_DisableInterrupts();
    s32 mark;

    if (M2C_FIELD(&gSoundCommandQueueState, s32 *, SOUND_CMD_QUEUE_SEND_HEAD) == 0)
        mark = M2C_FIELD(&gSoundCommandQueueState, s32 *, SOUND_CMD_QUEUE_COMPLETED);
    else
        mark = M2C_FIELD(&gSoundCommandQueueState, s32 *, SOUND_CMD_QUEUE_NEXT_MARK);
    OS_RestoreInterrupts(irq);
    return mark;
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

/* Count the sound command nodes still unused: walk the queue's free list from
 * its head with interrupts locked and return how many nodes remain. */
s32 Sound_CountFreeCommands(void) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    extern M2C_UNK gSoundCommandQueueState;
    s32 state = OS_DisableInterrupts();
    s32 count = 0;
    QueueNode09298 *node = ((State09100 *)&gSoundCommandQueueState)->head;

    if (node) {
        do {
            node = node->next;
            count++;
        } while (node);
    }
    OS_RestoreInterrupts(state);
    return count;
}

/* Count commands waiting on the ARM7 queue's queued-command list while interrupts are disabled. */
s32 Sound_CountQueuedCommands(void) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    extern M2C_UNK gSoundCommandQueueState;
    s32 interruptState = OS_DisableInterrupts();
    s32 count = 0;
    void *node = M2C_FIELD(&gSoundCommandQueueState, void **, 8);

    if (node) {
        do {
            node = *(void **)node;
            count++;
        } while (node);
    }
    OS_RestoreInterrupts(interruptState);
    return count;
}

/* Count the sound commands currently in flight: the command pool's nodes minus
 * the free ones and the ones still waiting on the send list. */
s32 Sound_CountInFlightCommands(void) {
    s32 Sound_CountFreeCommands();
    s32 Sound_CountQueuedCommands();
    s32 freeCommands;

    freeCommands = Sound_CountFreeCommands();
    return (SOUND_CMD_NODE_COUNT - freeCommands) - Sound_CountQueuedCommands();
}

/* FIFO message handler for the sound command channel: `message` carries the
 * hardware channel in its low byte and the generation its callback was registered
 * with in bits 8..15; run the channel's timer callback if that generation still
 * matches. */
void Sound_CommandChannelHandler(s32 tag, s32 message) {
    s32 OS_DisableInterrupts(void);
    s32 saved = OS_DisableInterrupts();

    Sound_DispatchChannelCallback(message);
    OS_RestoreInterrupts(saved);
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

/* Nudge the ARM7's sound side: keep posting an empty message with the sound
 * command FIFO tag until the IPC FIFO takes it (a failed send is retried). */
void Sound_SignalArm7(void) {
    s32 SendFifoMessage(M2C_UNK, M2C_UNK, M2C_UNK);
    do {

    } while (SendFifoMessage(SND_CMD_FIFO_TAG, 0, 0) < 0);
}

/* Takes a free command node off the queue's free list, interrupts locked; returns
 * 0 when the list is empty, and clears the list tail when the last node is taken. */
void *Sound_PopFreeCommand(void) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    extern M2C_UNK gSoundCommandQueueState;
    s32 irq;
    QueueNode09298 *command;
    QueueNode09298 *next;

    irq = OS_DisableInterrupts();
    command = ((State09100 *)&gSoundCommandQueueState)->head;
    if (!command) {
        OS_RestoreInterrupts(irq);
        return 0;
    }
    next = command->next;
    ((State09100 *)&gSoundCommandQueueState)->head = next;
    if (!next) ((State09100 *)&gSoundCommandQueueState)->tail = 0;
    OS_RestoreInterrupts(irq);
    return command;
}

/* Test whether the ARM7 sound command channel can take commands: on hardware
 * that has the channel, probe its status register with interrupts locked and
 * report it ready when the probe reads back nonzero. */
s32 Sound_IsCommandChannelReady(void) {
    s32 func_020062b4(void);
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    s32 irq, status, result;

    if (!func_020062b4()) return 1;
    irq = OS_DisableInterrupts();
    *(volatile s32 *)SND_CMD_CHANNEL_STATUS_REG = SND_CMD_CHANNEL_PROBE;
    status = *(volatile s32 *)SND_CMD_CHANNEL_STATUS_REG;
    OS_RestoreInterrupts(irq);
    if (status) result = 1; else result = 0;
    return result;
}

/* Clear all eight per-channel sound timer callbacks: zero every entry's callback,
 * its argument and its generation counter. */
void ClearSoundChannelCallbacks(void){
    extern M2C_UNK gSoundChannelCallbacks;
    int channel = 0;
    u8 *entry = (u8 *)&gSoundChannelCallbacks;
    int zero = channel;
    do {
        *(s32 *)(entry + SOUND_CHANNEL_CALLBACK_CALLBACK) = zero;
        *(s32 *)(entry + SOUND_CHANNEL_CALLBACK_ARG) = zero;
        channel++;
        entry[SOUND_CHANNEL_CALLBACK_GEN] = zero;
        entry += SOUND_CHANNEL_CALLBACK_SIZE;
    } while (channel < SOUND_CHANNEL_CALLBACK_COUNT);
}

/* Drop the pending ARM7 timer callback of hardware `channel` by bumping its
 * generation counter, so a reply carrying the old generation is ignored. */
void Sound_InvalidateChannelCallback(s32 channel) {
    extern M2C_UNK gSoundChannelCallbacks;
    u8 *entry = (u8 *)&gSoundChannelCallbacks + channel * SOUND_CHANNEL_CALLBACK_SIZE;

    entry[SOUND_CHANNEL_CALLBACK_GEN] = entry[SOUND_CHANNEL_CALLBACK_GEN] + 1;
}

/* Register hardware channel `channel`'s timer callback and its argument in the
 * per-channel table, and return the entry's bumped generation counter, which the
 * ARM7's reply to sound command 0x12 must echo before the callback may run. */
u8 Sound_RegisterChannelCallback(int channel, int callback, int callbackArg) {
    extern M2C_UNK gSoundChannelCallbacks;
    void *entry = (char *)&gSoundChannelCallbacks + channel * SOUND_CHANNEL_CALLBACK_SIZE;
    M2C_FIELD(entry, int *, SOUND_CHANNEL_CALLBACK_CALLBACK) = callback;
    M2C_FIELD(entry, int *, SOUND_CHANNEL_CALLBACK_ARG) = callbackArg;
    return ++M2C_FIELD(entry, u8 *, SOUND_CHANNEL_CALLBACK_GEN);
}

s32 Sound_DispatchChannelCallback(s32 a){
extern M2C_UNK gSoundChannelCallbacks;void *p=(char *)&gSoundChannelCallbacks+(a&255)*12;
if(M2C_FIELD(p,u8 *,8)!=(u8)(a>>8))return;
if(M2C_FIELD(p,void (**)(int),0))M2C_FIELD(p,void (**)(int),0)(M2C_FIELD(p,int *,4));
}

/* Read the ARM7 sound driver's playing-channel mask (bit i set while hardware
 * channel i plays) from the shared command buffer, after dropping the ARM9's
 * cached copy of that word so the ARM7's latest update is read. */
s32 Sound_GetActiveChannels(void) {
    M2C_UNK DC_InvalidateRange(s32 *, M2C_UNK);
    extern s32 *gSoundCommandBufferPtr;

    DC_InvalidateRange(gSoundCommandBufferPtr + 1, 4);
    return gSoundCommandBufferPtr[1];
}

/* Read the command-batch count the ARM7 sound driver has taken so far from the
 * first word of the shared command buffer, after dropping the ARM9's cached copy
 * of that word so the driver's latest update is read. */
s32 Sound_GetProcessedCommandCount(void) {
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
M2C_FIELD(buffer,u32 *,SND_CMD_BUFFER_CHANNELS)=0;M2C_FIELD(buffer,s16 *,SND_CMD_BUFFER_UNK08)=0;M2C_FIELD(buffer,s16 *,SND_CMD_BUFFER_UNK0A)=0;M2C_FIELD(buffer,int *,SND_CMD_BUFFER_PROCESSED)=0;
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

/* Clear the chain of 8-byte link slots rooted at `object`'s +0x18 word: each
 * slot's owner and next are zeroed and cleaned for the ARM7, under the sound
 * mutex. */
void Link_ClearSlotChain(void *object) {
    void *next;
    void *slot;

    Sound_LockMutex();
    slot = M2C_FIELD(object, void **, 0x18);
    if (slot != NULL) {
        do {
            next = M2C_FIELD(slot, void **, 4);
            M2C_FIELD(slot, s32 *, 0) = 0;
            M2C_FIELD(slot, void **, 4) = NULL;
            DC_CleanRange(slot, 8);
            slot = next;
        } while (next != NULL);
    }
    Sound_UnlockMutex();
}

/* Clear a packed-table iterator to its start: entry index 0 and intra-entry
 * index 0, before the first IteratePackedTableRecord call. */
void InitPackedTableCursor(u32 *cursor) {
    volatile u32 cleared[2];

    cursor[0] = 0;
    cleared[0] = 0;
    cleared[1] = 0;
    cursor[1] = 0;
}

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

/* Store `value` in entry `index` of a wave archive's packed pointer table and clean
 * the cache line the slot was written to; the table is updated under the sound mutex. */
void SetPackedTableEntry(s32 archive, s32 index, s32 value) {
    M2C_UNK DC_CleanRange(s32, M2C_UNK);
    Sound_LockMutex();
    M2C_FIELD(archive + index * 4, s32 *, WAVE_ARCHIVE_ENTRIES) = value;
    DC_CleanRange(archive + WAVE_ARCHIVE_ENTRIES + index * 4, 4);
    Sound_UnlockMutex();
}

/* Resolve entry `index` of a wave archive's packed table: its slot holds either
 * an absolute main-RAM pointer or, when below the main-RAM base, an offset into
 * the archive.  Returns NULL when the entry is not loaded. */
void *GetPackedTableEntry(char *archive,s32 index){
void *entry;Sound_LockMutex();entry=M2C_FIELD(archive+index*4,void **,WAVE_ARCHIVE_ENTRIES);
if(entry){if((u32)entry<WAVE_ARCHIVE_POINTER_BASE)entry=archive+(u32)entry;}else entry=0;
Sound_UnlockMutex();return entry;
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
/* Register `handler` as the receiver of IPC FIFO messages tagged `tag` (NULL
 * removes it), mirroring the registration into the shared work area's tag mask
 * that the ARM7 reads, with interrupts off. Returns the previous interrupt state. */
s32 SetFifoMessageHandler(s32 tag, M2C_UNK *handler) {
    s32 OS_DisableInterrupts(void);
    extern s32 gFifoMessageHandlers[];
    s32 irqState;
    s32 *handledTags;

    irqState = OS_DisableInterrupts();
    handledTags = (s32 *)SHARED_WORK_BASE;
    gFifoMessageHandlers[tag] = (s32)handler;
    if (handler) handledTags[SHARED_FIFO_TAG_WORD] |= 1 << tag;
    else handledTags[SHARED_FIFO_TAG_WORD] &= ~(1 << tag);
    return OS_RestoreInterrupts(irqState);
}

/* Checks whether the ARM7/ARM9 shared work area's ready word `wordIndex` (at
 * 0x027FFC00 + 0x388 + wordIndex*4) has bit `fifoTag` set: InitSoundCommandLink
 * polls word 1 for the sound-command FIFO tag until the ARM7 reports the channel
 * ready. */
s32 IsFifoMessageReady(s32 fifoTag, s32 wordIndex) {
    extern u8 data_027ffc00[];
    u32 readyTags = *((u32 *)((u8 *)data_027ffc00 + wordIndex * 4 + 0x388));
    s32 ready = 1;

    if (!(readyTags & (1 << fifoTag))) {
        ready = 0;
    }
    return ready;
}

