/* 37 functions from 0x020180C8 to 0x02018FF0 (main), found by ds-decomp. */
#include "common.h"

typedef struct MbCartridgeState {
    u16 checksum;
    u8 reserved[3];
    u8 compareGameCode : 1;
    u8 changed : 1;
    u8 otherFlags : 6;
    u8 padding[2];
    u32 gameCode;
} MbCartridgeState;

#pragma optimization_level 2
void Mb_RemovePlayer(s32 arg0) {
extern M2C_UNK gMbState;
void Mb_HandleWfcEvent(void *);
void MultiBoot_ClearRecordSlot(s32);
M2C_UNK MI_CpuFill8(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_0201280c(void (*)(void *),s32);
s32 i,temp,off;u16 v1,v2;u8 *q;
func_0201280c(Mb_HandleWfcEvent,arg0);
if(arg0==0||(u32)arg0>=16)return;
i=arg0-1;
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i*2+0x1400,u16*,0x8a)=0;
MI_CpuFill8((u8*)M2C_FIELD(&gMbState,void**,12)+0xa8+0x1400+i*4,0,4);
MI_CpuFill8((u8*)M2C_FIELD(&gMbState,void**,12)+0x1340+i*22,0,22);
MultiBoot_ClearRecordSlot(arg0);
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i*2+0x1700,u16*,0x54)=0;
temp=M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i+0x1500,s8*,0x26);
if(temp!=-1){
off=(u8)temp*0x5d4;
q=(u8*)M2C_FIELD(&gMbState,void**,12)+off+0x1d00;
v1=M2C_FIELD(q,u16*,0x4e);M2C_FIELD(q,u16*,0x4e)=v1&~(1<<arg0);
q=(u8*)M2C_FIELD(&gMbState,void**,12)+off+0x1d00;
v2=M2C_FIELD(q,u16*,0x50);M2C_FIELD(q,u16*,0x50)=v2|(1<<arg0);
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i+0x1000,s8*,0x526)=-1;
q=(u8*)M2C_FIELD(&gMbState,void**,12)+off+0x1d00;
M2C_FIELD(q,u16*,0x4c)&=~(1<<arg0);
}
if(M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+0x1500,u16*,0x36)&(1<<arg0)){
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+0x1000,u8*,0x535)--;
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+0x1500,u16*,0x36)&=~(1<<arg0);
}
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i*4+0x1000,u32*,0x4e8)=0;
}
#pragma optimization_level reset
void func_02018254(s16 arg0) {
    extern M2C_UNK gMbState;
    M2C_FIELD(&gMbState, s16 *, 0x26) = arg0;
}

/* Send one multiboot channel packet: queue `data` (length bytes) for the players
 * in playerMask through the WFC channel transport (channel 1, mode 3) with
 * `callback` as its completion handler, then report the send result as multiboot
 * message 0xF.  `timeout` is unused here: multiboot sends always use the fixed
 * channel and mode. */
s32 Mb_SendChannelPacket(M2C_UNK callback, M2C_UNK data, M2C_UNK length, M2C_UNK timeout, u16 playerMask) {
    s32 WFC_SendChannelData(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    void Mb_ReportPacketResult(M2C_UNK, s32);
    s32 result;

    result = WFC_SendChannelData(callback, 0, data, length, (s32) playerMask, 1, 3);
    Mb_ReportPacketResult(0xF, result);
    return result;
}

/* Send one match packet (buffer `data`, `len` bytes, channel `chan`, flags `flags`)
 * over the multiboot link. Returns 1 when the link is not up or the player has
 * given up, otherwise the channel send's result; a result of 2 means the send is
 * queued, so the pending flag is set and 0 is returned. */
s32 Mb_SendMatchPacket(s32 arg0, s32 arg1, s32 arg2) {
extern M2C_UNK gMbState;
void Mb_HandleMatchCommand(void);
void *p;
s32 result;
u16 a = arg1;
u16 b = arg2;
p = M2C_FIELD(&gMbState, void **, 8);
if (M2C_FIELD(p,u16 *,0x528) == 0 || M2C_FIELD(p,u16 *,0x526) == 1) return 1;
switch (M2C_FIELD(p,u16 *,0x524)) {
case 1:
result = Mb_SendChannelPacket(M2C_FIELD(p,s32 *,0x508),arg0,a,(u16)(M2C_FIELD(p,u16 *,0x52c) == 0 ? 1000 : 0),b);
if (result == 2) M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50c)=1;
if (result == 2) return 0;
return result;
case 2:
result = Mb_SendChannelPacket((s32)Mb_HandleMatchCommand,arg0,a,0,b);
if (result == 2) M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50c)=1;
if (result == 2) return 0;
return result;
}
return 1;
}

s32 func_02018390(void) {
    extern M2C_UNK gMbState;
    return M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), s32 *, 8);
}

u16 func_020183a4(void) {
    extern M2C_UNK gMbState;
    return M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u16 *, 0xC);
}

/* Pack the multiboot parent context's four send-status words into the flag byte
 * of a download send: bit n is set when the word at MB_CTX_STATUSn is nonzero. */
u8 Mb_GetDownloadSendFlags(void) {
    extern M2C_UNK gMbState;
    void *ctx = M2C_FIELD(&gMbState, void **, 8);
    u32 status1 = M2C_FIELD(ctx, u16 *, MB_CTX_STATUS1) != 0 ? 2 : 0;
    u32 status0 = M2C_FIELD(ctx, u16 *, MB_CTX_STATUS0) != 0 ? 1 : 0;
    u32 status2 = M2C_FIELD(ctx, u16 *, MB_CTX_STATUS2) != 0 ? 4 : 0;
    u32 status3 = M2C_FIELD(ctx, u16 *, MB_CTX_STATUS3) != 0 ? 8 : 0;
    return (u8)(((status0 | status1) | status2) | status3);
}

/* Whether the multiboot link has started: the parent context's MB_LINK_STARTED
 * flag is set to exactly 1 once the link is up. */
s32 MultiBoot_IsLinkStarted(void) {
    extern M2C_UNK gMbState;
    return M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u8 *, MB_LINK_STARTED) == 1;
}

void Mb_ReportPacketResult(s32 arg0, s32 arg1) {
 extern M2C_UNK data_02136c40;
 u16 buf[2];
 void *p;
 if (arg1 == 2 || arg1 == 0) return;
 buf[0]=arg0;
 p=M2C_FIELD(&data_02136c40,void **,8);
 buf[1]=arg1;
 M2C_FIELD(p,void (**)(u8,void *),0x51c)((u8)(arg0 | 255),buf);
}

void Mb_InitLoadQueue(M2C_UNK arg0) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg0, 0, 0x70);
}

/* Adds a block to a multiboot load queue's block cache under an interrupt
 * lock: the first free slot records the block's image offset, size, buffer and
 * state; the system halts when every slot is in use. */
void Mb_AddImageBlock(MbLoadQueue *queue, u32 offset, u32 size, u8 *data, s32 state) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void SystemHalt();
    MbLoadBlock *end;
    s32 saved;
    MbLoadBlock *block;

    saved = OS_DisableInterrupts();
    block = &queue->blocks[0];
    end = &queue->blocks[MB_LOAD_BLOCK_COUNT];
    for (;;) {
        if (block >= end) SystemHalt();
        if (block->state == 0) {
            block->offset = offset;
            block->size = size;
            block->data = data;
            block->state = state;
            break;
        }
        block++;
    }
    OS_RestoreInterrupts(saved);
}

/* Serves one read of the multiboot download image from the queue's cache: finds
 * the resident (or fixed) block that holds the requested range, copies it into
 * the caller's buffer and clears the queue's pending count.  Returns 1 when the
 * range was copied, 0 when no cached block covers it. */
s32 Mb_CopyImageRange(MbLoadQueue *queue, u32 offset, void *dest, s32 length) {
    s32 OS_DisableInterrupts(void);
    void MI_CpuCopy8(s32, M2C_UNK, s32);
    void OS_RestoreInterrupts(s32);
    MbLoadBlock *end;
    s32 result;
    MbLoadBlock *block;
    s32 relative;
    s32 saved;

    result = 0;
    saved = OS_DisableInterrupts();
    block = &queue->blocks[0];
    end = &queue->blocks[MB_LOAD_BLOCK_COUNT];
    for (; block < end; block++) {
        if ((u32)block->state >= MB_LOAD_STATE_RESIDENT) {
            relative = offset - block->offset;
            if (0 <= relative) {
                if ((u32)(relative + length) <= (u32)block->size) {
                    MI_CpuCopy8((s32)(block->data + relative), dest, length);
                    result = 1;
                    queue->pending = 0;
                    break;
                }
            }
        }
    }
    OS_RestoreInterrupts(saved);
    return result;
}

#pragma optimization_level 3
void MbWorkerTask_Main(void *worker) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void SetThreadPriority(void *, s32);
    void OS_SleepThread(s32);
    s32 GetThreadPriority(void *);
    void TaskExitCurrent(void);

    void *task;

    while (1) {
        s32 saved = OS_DisableInterrupts();
        if (M2C_FIELD(worker, void *volatile *, 0xC0) == (void *)0) {
            do {
                SetThreadPriority(worker, 0);
                OS_SleepThread(0);
            } while (M2C_FIELD(worker, void *volatile *, 0xC0) == (void *)0);
        }
        task = M2C_FIELD(worker, void *volatile *, 0xC0);
        M2C_FIELD(worker, void *volatile *, 0xC0) = M2C_FIELD(M2C_FIELD(worker, void *volatile *, 0xC0), void **, 0);
        SetThreadPriority(worker, (s32)(*(unsigned int *)((u8 *)task + 0x4) >> 1));
        OS_RestoreInterrupts(saved);
        if (*(void **)((u8 *)task + 0x8) != (void *)0) {
            ((void (*)(void *))(*(void **)((u8 *)task + 0x8)))(task);
        }
        {
            s32 completionState = OS_DisableInterrupts();
            void (*onComplete)(void *) = (void (*)(void *))(*(void **)((u8 *)task + 0xc));
            {
                s32 currentPriority = GetThreadPriority(worker);
                s32 nextPriority;
                if (M2C_FIELD(worker, void *volatile *, 0xC0) == 0) {
                    nextPriority = 0;
                } else if ((u32)currentPriority >= (M2C_FIELD(M2C_FIELD(worker, void *volatile *, 0xC0), u32 *, 4) >> 1)) {
                    nextPriority = currentPriority;
                } else {
                    nextPriority = M2C_FIELD(M2C_FIELD(worker, void *volatile *, 0xC0), u32 *, 4) >> 1;
                }
                if (nextPriority != currentPriority) {
                    SetThreadPriority(worker, nextPriority);
                }
            }
            *(void **)((u8 *)task + 0x0) = (void *)0;
            *(unsigned int *)((u8 *)task + 0x4) = *(unsigned int *)((u8 *)task + 0x4) & ~1u;
            if (onComplete != (void (*)(void *))0) {
                onComplete(task);
            }
            if (task != (void *)((u8 *)worker + 0xc4)) {
                OS_RestoreInterrupts(completionState);
                continue;
            }
            TaskExitCurrent();
            return;
        }
    }
}
#pragma optimization_level reset
/* Start the multiboot worker thread on `task`, once: remember it as the current
 * worker, empty its own job record, give it the rest of the work area as its
 * stack and wake it. */
void Mb_StartWorkerTask(M2C_UNK task, s32 workSize) {
    extern s32 gMbWorkerTask;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void MbWorker_ClearJob(M2C_UNK);
    void TaskCreate(M2C_UNK, void (*)(void *), M2C_UNK, M2C_UNK, s32, s32);
    void TaskWake(M2C_UNK);
    void MbWorkerTask_Main(void *);
    s32 saved;
    saved = OS_DisableInterrupts();
    if (gMbWorkerTask == 0) {
        gMbWorkerTask = task;
        MbWorker_ClearJob(task + MB_TASK_JOB_BLOCK);
        M2C_FIELD(task, s32 *, MB_TASK_JOB) = 0;
        TaskCreate(task, MbWorkerTask_Main, task, task + 0xE4 + ((workSize - 0xE4) & ~3), (workSize - 0xE4) & ~3, 0);
        TaskWake(task);
    }
    OS_RestoreInterrupts(saved);
}

/* Whether the multiboot worker thread has been created: Mb_StartWorkerTask has
 * run and the worker has not been stopped again. */
s32 Mb_IsTaskCreated(void) {
    extern s32 gMbWorkerTask;
    if (gMbWorkerTask != 0) {
        return 1;
    }
    return 0;
}

void MbWorker_ClearJob(M2C_UNK arg0) {
    MI_CpuFill8(arg0, 0, 0x20);
}

/* Whether the multiboot worker request `request` is already on the worker's
 * queue: its queued flag is bit 0 of the status word at +0x04, which Mb_QueueTask
 * sets and the worker clears when it picks the request up. */
s32 Mb_IsTaskQueued(void *request) {
    if (((u32) (M2C_FIELD(request, s32 *, 4) << 0x1F) >> 0x1F) != 0) {
        return 1;
    }
    return 0;
}

typedef struct MbWorkerRequest {
    struct MbWorkerRequest *next;
    u32 queued : 1;
    u32 priority : 31;
    void (*run)(void *request);
    void (*finish)(void *request);
} MbWorkerRequest;

/* Queue a job on the multiboot worker: resolve its priority (codes 32..34
 * select a priority relative to the worker thread's own), fill in the job
 * record, then link it into the worker's priority-ordered queue and wake the
 * worker.  The worker's own job record ends the worker when it runs. */
void Mb_QueueTask(M2C_UNK requestNode, s32 run, M2C_UNK finish, s32 requestedPriority) {
    extern s32 gMbWorkerTask;
    s32 Mb_IsTaskCreated(void);
    s32 GetThreadPriority(void *);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void TaskWake(M2C_UNK);
    void *worker;
    s32 saved;
    MbWorkerRequest *request;
    MbWorkerRequest *prev, *next;
    u32 priority;

    worker = (void *)gMbWorkerTask;
    request = (MbWorkerRequest *)requestNode;
    priority = requestedPriority;
    if (!Mb_IsTaskCreated() || request->queued) {
        return;
    }
    if (priority > MB_TASK_PRIORITY_MIN) {
        u32 current = GetThreadPriority(worker);
        if (priority == MB_TASK_PRIORITY_HIGHER) {
            priority = current != 0 ? current - 1 : 0;
        } else if (priority == MB_TASK_PRIORITY_LOWER) {
            priority = current < MB_TASK_PRIORITY_MIN ? current + 1 : MB_TASK_PRIORITY_MIN;
        } else if (priority == MB_TASK_PRIORITY_SAME) {
            priority = current;
        } else {
            priority = MB_TASK_PRIORITY_MIN;
        }
    }

    saved = OS_DisableInterrupts();
    request->queued = 1;
    request->priority = priority;
    request->run = (void (*)(void *))run;
    request->finish = (void (*)(void *))finish;
    if (M2C_FIELD(worker, MbWorkerRequest *volatile *, MB_TASK_JOB) == NULL) {
        if (request == (MbWorkerRequest *)((u8 *)worker + MB_TASK_JOB_BLOCK)) {
            gMbWorkerTask = 0;
        }
        M2C_FIELD(worker, MbWorkerRequest **, MB_TASK_JOB) = request;
        TaskWake((M2C_UNK)worker);
    } else {
        prev = M2C_FIELD(worker, MbWorkerRequest *volatile *, MB_TASK_JOB);
        if (request == (MbWorkerRequest *)((u8 *)worker + MB_TASK_JOB_BLOCK)) {
            while (prev->next != NULL) {
                prev = prev->next;
            }
            prev->next = request;
            gMbWorkerTask = 0;
        } else if (priority < prev->priority) {
            M2C_FIELD(worker, MbWorkerRequest **, MB_TASK_JOB) = request;
            request->next = prev;
        } else {
            goto checkNext;
        advance:
            prev = next;
        checkNext:
            next = prev->next;
            if (next != NULL && priority >= next->priority) {
                goto advance;
            }
            request->next = next;
            prev->next = request;
        }
    }
    OS_RestoreInterrupts(saved);
}

/* Queue the multiboot worker's own exit job, with `finish` as its completion
 * callback, under an interrupt lock; nothing happens when no worker is running. */
void Mb_QueueTaskExit(void (*finish)(void)) {
    extern M2C_UNK gMbWorkerTask;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 Mb_IsTaskCreated(void);
    void Mb_QueueTask(M2C_UNK, s32, M2C_UNK, s32);
    s32 saved;

    saved = OS_DisableInterrupts();
    if (Mb_IsTaskCreated() != 0) {
        Mb_QueueTask((M2C_UNK)((u8 *)gMbWorkerTask + MB_TASK_JOB_BLOCK), 0, (M2C_UNK)finish, 0);
    }
    OS_RestoreInterrupts(saved);
}

/* Size the multiboot info-record reassembly from the parent's `packetSize`: a
 * command-7 packet carries a 2-byte header, so each fragment holds packetSize - 2
 * payload bytes and a full MB_RECORD_SIZE record needs that many fragments. */
void Mb_InitRecordReassembly(s32 packetSize) {
    extern M2C_UNK gMbRecordRx;
    s32 RuntimeIntDivMod(s32, s32);
    MB_RECORD_RX->fragmentSize = packetSize - 2;
    MB_RECORD_RX->fragmentCount = RuntimeIntDivMod(MB_RECORD_SIZE, packetSize - 2);
    MB_RECORD_RX->recordSize = MB_RECORD_SIZE;
}

/* Point the multiboot info-record reassembly at `buffer` and clear its player
 * slots and received-fragment masks. */
void Mb_SetRecordBuffer(u8 *buffer) {
    extern M2C_UNK gMbRecordRx;
    MB_RECORD_RX->buffer = buffer;
    MI_CpuFill8(buffer, 0, MB_RECORD_BUFFER_SIZE);
}

/* Clear a player's 30-byte reassembled multiboot record and its received-fragment mask. */
void MultiBoot_ClearRecordSlot(s32 playerId) {
    extern M2C_UNK gMbRecordRx;
    void *recordBuffer;
    s32 playerIndex;
    
    recordBuffer = M2C_FIELD(&gMbRecordRx, void **, 4);
    if (recordBuffer == NULL) {
        return;
    }
    playerIndex = playerId - 1;
    MI_CpuFill8((void *)((u8 *)recordBuffer + playerIndex * MB_RECORD_SLOT), 0, MB_RECORD_SIZE);
    recordBuffer = M2C_FIELD(&gMbRecordRx, void **, 4);
    M2C_FIELD((u8 *)recordBuffer + playerIndex * 4, u32 *, MB_RECORD_MASK) = 0;
}

/* Copy a multiboot command into a work buffer in its wire form: the one-byte
 * opcode followed, for opcode 4, by its two 16-bit fields little-endian.  Opcode
 * 0 and any unknown opcode are refused; otherwise the end of what was written is
 * returned. */
void *SerializeCommand(void *command, void *out) {
    u8 *p = out;
    *p++ = M2C_FIELD(command, u8 *, 0);
    switch (M2C_FIELD(command, u8 *, 0)) {
    case 4:
        p[0] = M2C_FIELD(command, u16 *, 2);
        p[1] = (M2C_FIELD(command, u16 *, 2) & 0xff00) >> 8;
        p[2] = M2C_FIELD(command, u16 *, 4);
        p[3] = (M2C_FIELD(command, u16 *, 4) & 0xff00) >> 8;
        p += 4;
        break;
    default:
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
        break;
    }
    return p;
}

/* Decode one received multiboot command packet into `header`. A type-7 packet
 * carries a numbered fragment of `player`'s MB_RECORD_SIZE-byte info record:
 * accumulate it and return the finished record (0 while fragments are still
 * missing). Types 8/9 copy the packet's embedded 16-bit value into the header
 * and return a pointer to the packet payload. */
void *MultiBoot_DecodePacket(u8 *packet, u8 *header, s32 player) {
    extern M2C_UNK gMbRecordRx;
    s32 MultiBoot_RecordComplete(s32);
    s32 MultiBoot_StoreRecordFragment(u8 *, s32);
    void MI_CpuCopy8(M2C_UNK, M2C_UNK, s32);

    s32 p = player;
    u8 type = packet[0];

    header[0] = type;
    switch (type) {
    case 7:
        if (MultiBoot_RecordComplete(p) != 0) {
            return (void *)(MB_RECORD_RX->buffer + (p - 1) * MB_RECORD_SLOT);
        }
        {
            u8 fragment = packet[1];
            header[2] = fragment;
            if (fragment > MB_RECORD_RX->fragmentCount) {
                return (void *)0;
            }
            MI_CpuCopy8((M2C_UNK)(packet + 2), (M2C_UNK)(header + 3), MB_RECORD_RX->fragmentSize);
            p = MultiBoot_StoreRecordFragment(header, p);
        }
        break;
    case 8:
        p = (s32)(packet + 3);
        *(u16 *)(header + 2) = packet[1];
        *(u16 *)(header + 2) = (u16)(*(u16 *)(header + 2) | ((packet[2] << 8) & 0xFF00));
        break;
    case 9:
        p = (s32)(packet + 3);
        *(u16 *)(header + 2) = packet[1];
        *(u16 *)(header + 2) = (u16)(*(u16 *)(header + 2) | ((packet[2] << 8) & 0xFF00));
        MI_CpuCopy8((M2C_UNK)p, (M2C_UNK)(header + 4), MB_RECORD_RX->fragmentSize);
        p = p + MB_RECORD_RX->fragmentSize;
        break;
    default:
        return (void *)0;
    }
    return (void *)p;
}

/* Store fragment `header[2]` of `player`'s multiboot info record (its payload
 * follows the header) into that player's slot and mark the fragment received.
 * Returns the finished record once every fragment has arrived, otherwise 0. */
s32 MultiBoot_StoreRecordFragment(u8 *header, s32 player) {
    extern M2C_UNK gMbRecordRx;
    void MI_CpuCopy8(M2C_UNK, M2C_UNK, s32);
    s32 MultiBoot_RecordComplete(s32);

    if (MB_RECORD_RX->buffer == 0) return 0;
    {
        u8 fragment = header[2];
        s32 index;
        if (fragment > MB_RECORD_RX->fragmentCount) return 0;
        index = player - 1;
        MI_CpuCopy8((M2C_UNK)(header + 3), (M2C_UNK)(MB_RECORD_RX->buffer + index * MB_RECORD_SLOT + fragment * MB_RECORD_RX->fragmentSize), MB_RECORD_RX->fragmentSize);
        *(u32 *)(MB_RECORD_RX->buffer + MB_RECORD_MASK + index * 4) |= (1U << fragment);
        if (!MultiBoot_RecordComplete(player)) return 0;
        return (s32)(MB_RECORD_RX->buffer + index * MB_RECORD_SLOT);
    }
}

/* Whether `player`'s multiboot info record has received every fragment: its
 * per-player bitmask has all `fragmentCount` low bits set.  A record with no
 * fragments to collect is complete. */
s32 MultiBoot_RecordComplete(s32 player) {
    extern M2C_UNK gMbRecordRx;
    u16 fragment;
    u32 received;
    s32 fragmentCount;

    fragment = 0;
    fragmentCount = MB_RECORD_RX->fragmentCount;
    if (fragmentCount > 0) {
        received = M2C_FIELD(MB_RECORD_RX->buffer + (player - 1) * 4, u32 *, MB_RECORD_MASK);
        do {
            if (!(received & (1u << fragment))) return 0;
            fragment++;
        } while (fragmentCount > fragment);
    }
    return 1;
}

/* Initialise the DS Download Play boot state: clear the ARM7 boot sync word and
 * remember the OS lock id that guards cartridge-bus access during boot. */
void Mb_InitBootState(void) {
    M2C_UNK CpuSet(s32 *, M2C_UNK *, s32);
    s16 OS_GetLockID(void);
    extern M2C_UNK gMbBootConfig;
    extern M2C_UNK gMbBootSync;
    s32 zero;

    zero = 0;
    /* 32-bit fill of one word with zero (bits 26 and 24 of the CpuSet control). */
    CpuSet(&zero, &gMbBootSync, 0x05000001);
    M2C_FIELD(&gMbBootConfig, s16 *, 6) = OS_GetLockID();
}

/* Returns 1 when the cartridge in the slot still holds the header recorded at
 * boot (Mb_CheckCartridgeHeader) and no game-code comparison was requested
 * (Mb_IsGameCodeCompared), 0 otherwise. */
s32 Mb_IsCartridgeUnchanged(void) {
    u32 Mb_IsGameCodeCompared(void);
    s32 Mb_CheckCartridgeHeader();
    if ((Mb_CheckCartridgeHeader() != 0) && (Mb_IsGameCodeCompared() == 0)) {
        return 1;
    }
    return 0;
}

/* True when the boot state asks for the cartridge's game code to be compared
 * against the header recorded at boot. */
u32 Mb_IsGameCodeCompared(void) {
    extern M2C_UNK data_027ffc30;
    return ((MbCartridgeState *)&data_027ffc30)->compareGameCode;
}

#pragma opt_strength_reduction off
s32 Mb_CheckCartridgeHeader(void) {
    extern M2C_UNK gMbBootConfig;
    extern M2C_UNK data_027ffc30;
    void Mb_LockCartridgeAccess(M2C_UNK, void *);
    void Mb_SaveCartridgeBusConfig(void *);
    void Mb_RestoreCartridgeBusConfig(void *);
    void Mb_UnlockCartridgeAccess(M2C_UNK, void *);
    s32 buf[4];
    s32 r4;
    volatile u8 *base;
    s32 r2;

    {
    MbCartridgeState *shared = (MbCartridgeState *)&data_027ffc30;
    r4 = 1;
    base = (volatile u8 *)0x08000000;

    if ((u16)(0x10000 - r4) == shared->checksum) {
        return 0;
    }
    if (shared->changed == 1) {
        return 0;
    }
    }
    Mb_LockCartridgeAccess(M2C_FIELD(&gMbBootConfig, u16 *, 6), (void *)(&buf[2]));
    Mb_SaveCartridgeBusConfig((void *)buf);

    r2 = base[0xB2];
    if (r2 == 0x96 &&
        ((MbCartridgeState *)&data_027ffc30)->checksum != *(volatile u16 *)(base + 0xBE)) {
        goto changed;
    }
    if (r2 != 0x96 &&
        *(volatile u16 *)0x0801FFFE != ((MbCartridgeState *)&data_027ffc30)->checksum) {
        goto changed;
    }
    {
        MbCartridgeState *shared = (MbCartridgeState *)&data_027ffc30;
        if (shared->gameCode == *(volatile u32 *)(base + 0xAC) || !shared->compareGameCode) {
            goto restore;
        }
changed:
        r4 = 0;
        ((MbCartridgeState *)&data_027ffc30)->changed = 1;
    }
restore:
    Mb_RestoreCartridgeBusConfig(buf);
    Mb_UnlockCartridgeAccess(M2C_FIELD(&gMbBootConfig, u16 *, 6), &buf[2]);
    return r4;
}
#pragma opt_strength_reduction reset
/* Save EXMEMCNT's main-RAM arbitration bits and VRAM priority in `saved`, then
   switch them to the values a multiboot cartridge-header read needs: RAM bits 2-3
   set and the VRAM priority bit cleared. */
void Mb_SaveCartridgeBusConfig(void *saved) {
    M2C_FIELD(saved, s32 *, 0) = (s32) ((s32) (*(u16 *)REG_EXMEMCNT & EXMEMCNT_RAM_MASK) >> 2);
    M2C_FIELD(saved, s32 *, 4) = (s32) ((s32) (*(u16 *)REG_EXMEMCNT & EXMEMCNT_VRAM_PRIORITY) >> 4);
    *(u16 *)REG_EXMEMCNT = (*(u16 *)REG_EXMEMCNT & ~EXMEMCNT_RAM_MASK) | EXMEMCNT_RAM_MASK;
    *(u16 *)REG_EXMEMCNT &= ~EXMEMCNT_VRAM_PRIORITY;
}

#pragma opt_propagation off
/* Put back the EXMEMCNT main-RAM arbitration bits and VRAM priority that
   Mb_SaveCartridgeBusConfig saved in `saved`. */
void Mb_RestoreCartridgeBusConfig(void *saved) {
 u32 value,reg;
 value=M2C_FIELD(saved,u32 *,0);
 reg=*(volatile u16 *)REG_EXMEMCNT;
 reg &=~EXMEMCNT_RAM_MASK;
 reg |=value<<2;
 *(volatile u16 *)REG_EXMEMCNT=reg;
 value=M2C_FIELD(saved,u32 *,4);
 reg=*(volatile u16 *)REG_EXMEMCNT;
 reg &=~EXMEMCNT_VRAM_PRIORITY;
 reg |=value<<4;
 *(volatile u16 *)REG_EXMEMCNT=reg;
}
#pragma opt_propagation reset
/* Take the cartridge-access lock `lockId` if it is free: if the shared OS lock
 * word at 0x027FFFE8 is already owned, leave it alone and only record that.
 * Otherwise keep trying to take it (restoring interrupts while waiting), and
 * save the caller's interrupt mask in `state` for Mb_UnlockCartridgeAccess. */
void Mb_LockCartridgeAccess(M2C_UNK lockId, void *stateBuf) {
    M2C_UNK OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    M2C_UNK OSi_GetLockOwnerId(void *);
    M2C_UNK OSi_TryLockWord(M2C_UNK);
    M2C_UNK WaitByLoop(M2C_UNK);
    MbLockState *state = (MbLockState *)stateBuf;

    for (;;) {
        state->interrupts = OS_DisableInterrupts();
        state->busy = OSi_GetLockOwnerId((void *)0x027FFFE8) & OS_LOCK_WORD_OWNED;
        if (state->busy != 0) return;
        if (OSi_TryLockWord(lockId) == 0) return;
        OS_RestoreInterrupts(state->interrupts);
        WaitByLoop(1);
    }
}

/* Releases the cartridge-access lock `lockId` taken by Mb_LockCartridgeAccess
 * (unless that call found it already owned) and restores the caller's interrupts. */
void Mb_UnlockCartridgeAccess(M2C_UNK lockId, void *stateBuf) {
    M2C_UNK OSi_UnlockWord(M2C_UNK);
    void OS_RestoreInterrupts(s32);
    MbLockState *state = (MbLockState *)stateBuf;

    if (state->busy == 0) {
        OSi_UnlockWord(lockId);
    }
    OS_RestoreInterrupts(state->interrupts);
}

/* Posts the multiboot control message `command` on the boot-handshake FIFO
 * channel, waiting until the FIFO accepts it. */
void Mb_SendControlMessage(M2C_UNK command) {
    M2C_UNK WaitByLoop(M2C_UNK);
    s32 SendFifoMessage(M2C_UNK, M2C_UNK, M2C_UNK);
    if (SendFifoMessage(MB_FIFO_TAG, command, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(1);
    } while (SendFifoMessage(MB_FIFO_TAG, command, 0) != 0);
}

/* Sets the multiboot boot mode: record it in the boot config and, while the
 * cartridge state is not the saved one, switch the boot-mode access bits. */
void Mb_SetBootMode(s32 mode) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 Mb_IsCartridgeUnchanged(void);
    void func_02006cc0(s32, s32);
    extern M2C_UNK gMbBootConfig;
    s32 irq;
    irq = OS_DisableInterrupts();
    gMbBootConfig = (M2C_UNK)mode;
    if (Mb_IsCartridgeUnchanged() == 0) {
        s32 bits;
        if (mode != 0) {
            bits = 0x1000;
        } else {
            bits = 0x5000;
        }
        func_02006cc0(0xf000, bits);
    }
    OS_RestoreInterrupts(irq);
}

/* Bring up DS Download Play once: initialise the boot state and the ARM7 link,
 * wait for the ARM7's channel 13 to come up, install the boot handshake
 * handler, send the boot parameters, then swap in the boot-complete handler,
 * start the multiboot task and register the channel-17 ready handler. */
void Mb_BootInit(void) {
    M2C_UNK PXI_Init();
    s32 SetFifoMessageHandler(s32, M2C_UNK *);
    s32 IsFifoMessageReady(s32, s32);
    void Mb_InitBootState(void);
    void Mb_SetBootMode(s32);
    M2C_UNK Mb_SendBootParams();
    M2C_UNK Mb_StartTask(M2C_UNK *);
    extern MbBootState gMbBootState;
    extern M2C_UNK gMbTask;
    extern M2C_UNK Mb_BootHandshakeHandler;
    extern M2C_UNK Mb_BootCompleteHandler;
    extern M2C_UNK Mb_RemoteReadyHandler;
    if (gMbBootState.initialised != 0) {
        return;
    }
    gMbBootState.initialised = 1;
    Mb_InitBootState();
    gMbBootState.complete = 0;
    PXI_Init();
    do {

    } while (IsFifoMessageReady(0xD, 1) == 0);
    SetFifoMessageHandler(0xD, &Mb_BootHandshakeHandler);
    Mb_SendBootParams();
    SetFifoMessageHandler(0xD, NULL);
    SetFifoMessageHandler(0xD, &Mb_BootCompleteHandler);
    gMbBootState.onComplete = 0;
    Mb_StartTask(&gMbTask);
    SetFifoMessageHandler(0x11, &Mb_RemoteReadyHandler);
    Mb_SetBootMode(0);
}

