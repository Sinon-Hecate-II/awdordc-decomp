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
void func_02016934(void *);
void func_02018960(s32);
M2C_UNK MI_CpuFill8(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_0201280c(void (*)(void *),s32);
s32 i,temp,off;u16 v1,v2;u8 *q;
func_0201280c(func_02016934,arg0);
if(arg0==0||(u32)arg0>=16)return;
i=arg0-1;
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i*2+0x1400,u16*,0x8a)=0;
MI_CpuFill8((u8*)M2C_FIELD(&gMbState,void**,12)+0xa8+0x1400+i*4,0,4);
MI_CpuFill8((u8*)M2C_FIELD(&gMbState,void**,12)+0x1340+i*22,0,22);
func_02018960(arg0);
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

s32 Mb_SendChannelPacket(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4) {
    s32 WFC_SendChannelData(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    void Mb_ReportPacketResult(M2C_UNK, s32);
    s32 temp_r0;

    temp_r0 = WFC_SendChannelData(arg0, 0, arg1, arg2, (s32) arg4, 1, 3);
    Mb_ReportPacketResult(0xF, temp_r0);
    return temp_r0;
}

/* Send one match packet (buffer `data`, `len` bytes, channel `chan`, flags `flags`)
 * over the multiboot link. Returns 1 when the link is not up or the player has
 * given up, otherwise the channel send's result; a result of 2 means the send is
 * queued, so the pending flag is set and 0 is returned. */
s32 Mb_SendMatchPacket(s32 arg0, s32 arg1, s32 arg2) {
extern M2C_UNK gMbState;
void func_02017158(void);
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
result = Mb_SendChannelPacket((s32)func_02017158,arg0,a,0,b);
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

u8 func_020183b8(void) {
    extern M2C_UNK gMbState;
    void *p = M2C_FIELD(&gMbState, void **, 8);
    u32 r2 = M2C_FIELD(p, u16 *, 0x12) != 0 ? 2 : 0;
    u32 r3 = M2C_FIELD(p, u16 *, 0xE) != 0 ? 1 : 0;
    u32 r12 = M2C_FIELD(p, u16 *, 0x14) != 0 ? 4 : 0;
    u32 r1 = M2C_FIELD(p, u16 *, 0x16) != 0 ? 8 : 0;
    return (u8)(((r3 | r2) | r12) | r1);
}

s32 func_02018418(void) {
    extern M2C_UNK gMbState;
    return M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u8 *, 0x50d) == 1;
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

void Mb_AddImageBlock(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4){
s32 OS_DisableInterrupts();void OS_RestoreInterrupts(s32);void SystemHalt();
u32 end; s32 saved; u32 p;
saved=OS_DisableInterrupts();p=arg0+0x30;end=arg0+0x70;
for(;;){
if(p>=end)SystemHalt();
if(M2C_FIELD(p,s32 *,12)==0){
M2C_FIELD(p,s32 *,0)=arg1;M2C_FIELD(p,s32 *,4)=arg2;M2C_FIELD(p,s32 *,8)=arg3;M2C_FIELD(p,s32 *,12)=arg4;break;
}
p+=16;
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

void MbWorkerTask_Main(void *r7) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void SetThreadPriority(void *, s32);
    void OS_SleepThread(s32);
    s32 GetThreadPriority(void *);
    void func_02005bbc(void);

    s32 saved;
    void *r4;
    void (*r6)(void *);

    while (1) {
        saved = OS_DisableInterrupts();
        if (*(void **)((u8 *)r7 + 0xc0) == (void *)0) {
            do {
                r6 = (void (*)(void *))0;
                r4 = (void *)0;
                SetThreadPriority(r7, 0);
                OS_SleepThread(0);
            } while (*(void **)((u8 *)r7 + 0xc0) == (void *)0);
        }
        r4 = *(void **)((u8 *)r7 + 0xc0);
        *(void **)((u8 *)r7 + 0xc0) = *(void **)((u8 *)r4 + 0x0);
        SetThreadPriority(r7, (s32)(*(unsigned int *)((u8 *)r4 + 0x4) >> 1));
        OS_RestoreInterrupts(saved);
        if (*(void **)((u8 *)r4 + 0x8) != (void *)0) {
            ((void (*)(void *))(*(void **)((u8 *)r4 + 0x8)))(r4);
        }
        saved = OS_DisableInterrupts();
        r6 = (void (*)(void *))(*(void **)((u8 *)r4 + 0xc));
        {
            s32 val = GetThreadPriority(r7);
            s32 adj;
            void *p = *(void **)((u8 *)r7 + 0xc0);
            if (p == (void *)0) {
                adj = 0;
            } else {
                unsigned int half = *(unsigned int *)((u8 *)p + 0x4) >> 1;
                if ((unsigned int)val < half) {
                    adj = (s32)half;
                } else {
                    adj = val;
                }
            }
            if (adj != val) {
                SetThreadPriority(r7, adj);
            }
        }
        *(void **)((u8 *)r4 + 0x0) = (void *)0;
        *(unsigned int *)((u8 *)r4 + 0x4) = *(unsigned int *)((u8 *)r4 + 0x4) & ~1u;
        if (r6 != (void (*)(void *))0) {
            r6(r4);
        }
        if (r4 != (void *)((u8 *)r7 + 0xc4)) {
            OS_RestoreInterrupts(saved);
            continue;
        }
        func_02005bbc();
        return;
    }
}

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

s32 func_0201874c(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, s32 *, 4) << 0x1F) >> 0x1F) != 0) {
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

void Mb_QueueTaskExit(M2C_UNK arg0) {
    extern M2C_UNK gMbWorkerTask;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 Mb_IsTaskCreated(void);
    void Mb_QueueTask(M2C_UNK, s32, M2C_UNK, s32);
    s32 saved;
    saved = OS_DisableInterrupts();
    if (Mb_IsTaskCreated() != 0) {
        Mb_QueueTask((M2C_UNK)((u8 *)gMbWorkerTask + 0xC4), 0, arg0, 0);
    }
    OS_RestoreInterrupts(saved);
}

void func_02018910(s32 arg0) {
    extern M2C_UNK gMbRecordRx;
    s32 RuntimeIntDivMod(s32, s32);
    M2C_FIELD(&gMbRecordRx, s32 *, 8) = arg0 - 2;
    M2C_FIELD(&gMbRecordRx, s32 *, 12) = RuntimeIntDivMod(0x1E, arg0 - 2);
    M2C_FIELD(&gMbRecordRx, s32 *, 16) = 0x1E;
}

void func_02018940(s32 arg0) {
    extern M2C_UNK gMbRecordRx;
    M2C_FIELD(&gMbRecordRx, s32 *, 4) = arg0;
    MI_CpuFill8(arg0, 0, 0x21C);
}

void func_02018960(s32 arg0) {
    extern M2C_UNK gMbRecordRx;
    void *base;
    s32 idx;
    
    base = M2C_FIELD(&gMbRecordRx, void **, 4);
    if (base == NULL) {
        return;
    }
    idx = arg0 - 1;
    MI_CpuFill8((void *)((u8 *)base + idx * 32), 0, 0x1E);
    base = M2C_FIELD(&gMbRecordRx, void **, 4);
    M2C_FIELD((u8 *)base + idx * 4, u32 *, 0x1E0) = 0;
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

s32 MultiBoot_RecordComplete(s32 arg0) {
extern M2C_UNK gMbRecordRx;
u16 i;
u32 word;
s32 count;
i=0;
count=M2C_FIELD(&gMbRecordRx,s32 *,12);
if(count>0) {
word=M2C_FIELD(M2C_FIELD(&gMbRecordRx,s32 *,4)+(arg0-1)*4,u32 *,0x1e0);
do {
if(!(word&(1u<<i)))return 0;
i++;
}while(count>i);
}
return 1;
}

void Mb_InitBootState(void) {
    M2C_UNK CpuSet(s32 *, M2C_UNK *, s32);
    s16 OS_GetLockID();
    extern M2C_UNK data_02136c98;
    extern M2C_UNK data_02136c9c;
    s32 sp0;

    sp0 = 0;
    CpuSet(&sp0, &data_02136c9c, 0x05000001);
    M2C_FIELD(&data_02136c98, s16 *, 6) = OS_GetLockID();
}

s32 func_02018c5c(void) {
    u32 func_02018c84(void);
    s32 func_02018c9c();
    if ((func_02018c9c() != 0) && (func_02018c84() == 0)) {
        return 1;
    }
    return 0;
}

u32 func_02018c84(void) {
    extern M2C_UNK data_027ffc30;
    return (u32) (M2C_FIELD(&data_027ffc30, u8 *, 5) << 0x1F) >> 0x1F;
}

#pragma opt_strength_reduction off
s32 func_02018c9c(void) {
    extern M2C_UNK data_02136c98;
    extern M2C_UNK data_027ffc30;
    void func_02018e24(M2C_UNK, void *);
    void func_02018da8(void *);
    void func_02018df0(void *);
    void func_02018e80(M2C_UNK, void *);
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
    func_02018e24(M2C_FIELD(&data_02136c98, u16 *, 6), (void *)(&buf[2]));
    func_02018da8((void *)buf);

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
    func_02018df0(buf);
    func_02018e80(M2C_FIELD(&data_02136c98, u16 *, 6), &buf[2]);
    return r4;
}
#pragma opt_strength_reduction reset
void func_02018da8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((s32) (*(u16 *)0x04000204 & 0xC) >> 2);
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((s32) (*(u16 *)0x04000204 & 0x10) >> 4);
    *(u16 *)0x04000204 = (*(u16 *)0x04000204 & ~0xC) | 0xC;
    *(u16 *)0x04000204 &= ~0x10;
}

#pragma opt_propagation off
void func_02018df0(void *arg0) {
 u32 a,b;
 a=M2C_FIELD(arg0,u32 *,0);
 b=*(volatile u16 *)0x04000204;
 b &=~0xC;
 b |=a<<2;
 *(volatile u16 *)0x04000204=b;
 a=M2C_FIELD(arg0,u32 *,4);
 b=*(volatile u16 *)0x04000204;
 b &=~0x10;
 b |=a<<4;
 *(volatile u16 *)0x04000204=b;
}
#pragma opt_propagation reset
void func_02018e24(M2C_UNK arg0,void *arg1) {
M2C_UNK OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); M2C_UNK func_02005584(M2C_UNK); M2C_UNK func_020054cc(M2C_UNK); M2C_UNK WaitByLoop(M2C_UNK);
for(;;){
M2C_FIELD(arg1,s32 *,4)=OS_DisableInterrupts();
M2C_FIELD(arg1,s32 *,0)=func_02005584(0x27fffe8)&0x40;
if(M2C_FIELD(arg1,s32 *,0)!=0)return;
if(func_020054cc(arg0)==0)return;
OS_RestoreInterrupts(M2C_FIELD(arg1,s32 *,4));
WaitByLoop(1);
}
}

void func_02018e80(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_020054c0(M2C_UNK);
    void OS_RestoreInterrupts(s32);
    if (M2C_FIELD(arg1, s32 *, 0) == 0) {
        func_020054c0(arg0);
    }
    OS_RestoreInterrupts(M2C_FIELD(arg1, s32 *, 4));
}

void func_02018ea4(M2C_UNK arg0) {
    M2C_UNK WaitByLoop(M2C_UNK);
    s32 SendFifoMessage(M2C_UNK, M2C_UNK, M2C_UNK);
    if (SendFifoMessage(0xD, arg0, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(1);
    } while (SendFifoMessage(0xD, arg0, 0) != 0);
}

void Mb_SetBootMode(s32 arg0) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 func_02018c5c(void);
    void func_02006cc0(s32, s32);
    extern M2C_UNK data_02136c98;
    s32 saved;
    saved = OS_DisableInterrupts();
    data_02136c98 = (M2C_UNK)arg0;
    if (func_02018c5c() == 0) {
        s32 r1;
        if (arg0 != 0) {
            r1 = 0x1000;
        } else {
            r1 = 0x5000;
        }
        func_02006cc0(0xf000, r1);
    }
    OS_RestoreInterrupts(saved);
}

/* Bring up DS Download Play once: initialise the boot state and the ARM7 link,
 * wait for the ARM7's channel 13 to come up, install the boot handshake
 * handler, send the boot parameters, then swap in the boot-complete handler,
 * start the multiboot task and register the channel-17 ready handler. */
void Mb_BootInit(void) {
    M2C_UNK func_02009d34();
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
    func_02009d34();
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

