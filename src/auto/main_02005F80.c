/* 61 functions from 0x02005F80 to 0x02006F14 (main), found by ds-decomp. */
#include "common.h"

typedef struct QueueFields {
    u32 wait[4];
    void **buffer;
    s32 capacity;
    s32 first;
    s32 count;
} QueueFields;

/* Change a ready thread's run priority: unlink it, store the new priority and
 * re-insert it into the priority-ordered ready list, then reschedule.  Returns
 * 0 when the thread is not in the ready list or is the idle thread, 1 otherwise. */
s32 SetThreadPriority(Thread *thread,s32 priority) {
M2C_UNK InsertReadyThread(void *); M2C_UNK RescheduleThreads(); s32 OS_DisableInterrupts(); void OS_RestoreInterrupts(s32); extern M2C_UNK gThreadManager; extern Thread gIdleThread;
Thread *cur; Thread *prev; s32 state;
cur=M2C_FIELD(&gThreadManager,Thread **,THREAD_MANAGER_READY);prev=0;state=OS_DisableInterrupts();
while(cur!=0 && cur!=thread){prev=cur;cur=cur->next;}
if(cur==0 || cur==&gIdleThread){OS_RestoreInterrupts(state);return 0;}
if(cur->priority!=priority){
if(prev==0){M2C_FIELD(&gThreadManager,Thread **,THREAD_MANAGER_READY)=thread->next;}else{prev->next=thread->next;}
thread->priority=priority;InsertReadyThread(thread);RescheduleThreads();}
OS_RestoreInterrupts(state);return 1;
}

s32 GetThreadPriority(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70);
}

/* Put the running thread to sleep for at least `milliseconds`: arm a one-shot
 * timer whose callback wakes the thread, then sleep until it fires. */
void SleepMilliseconds(s32 milliseconds) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void InitTimer(void *);
    void ScheduleTimer(void *, u64, void (*)(void **), void **);
    M2C_UNK OS_SleepThread(void *);
    extern M2C_UNK gThreadManager;
    extern void SleepTimerCallback(void **);
    register s32 savedMs = milliseconds;
    s32 timer[11];
    void *thread;
    s32 state;
    u64 delay;

    InitTimer(timer);
    thread = M2C_FIELD(M2C_FIELD(&gThreadManager, void **, 8), void **, 0);
    state = OS_DisableInterrupts();
    delay = ((u64)(u32)savedMs * 0x82EAULL) >> 6;
    M2C_FIELD(thread, void **, THREAD_WAKE_TIMER) = timer;
    ScheduleTimer(timer, delay, SleepTimerCallback, &thread);
    while (thread != NULL) {
        OS_SleepThread(NULL);
    }
    OS_RestoreInterrupts(state);
}

void SleepTimerCallback(void **arg0) {
    M2C_UNK TaskWake(void *);
    void *temp_r2;

    temp_r2 = *arg0;
    *arg0 = NULL;
    M2C_FIELD(temp_r2, s32 *, 0xB0) = 0;
    TaskWake(temp_r2);
}

s32 func_020060f8(s32 arg0) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gThreadManager;
    s32 state;
    s32 temp;

    state = OS_DisableInterrupts();
    temp = M2C_FIELD(&gThreadManager, s32 *, 0x30);
    M2C_FIELD(&gThreadManager, s32 *, 0x30) = arg0;
    OS_RestoreInterrupts(state);
    return temp;
}

void func_02006120(void)
{
  s32 func_02007508(void);
  M2C_UNK func_02007968(void);
  func_02007508();
  for (;;)
  {
    func_02007968();
  }

}

/* Disable the cooperative scheduler: step its thread-lock count up (unless it is
 * already at its maximum, -1) under an interrupt lock, and return the count
 * before the change (0 when the scheduler was enabled). */
s32 OS_DisableScheduler(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gThreadManager;
    s32 intrMode;
    s32 previous;
    s32 lock;
    s32 maxLock = -1;

    intrMode = OS_DisableInterrupts();
    lock = M2C_FIELD(&gThreadManager, s32 *, THREAD_MANAGER_LOCK);
    if ((u32)lock < (u32)maxLock) {
        previous = lock;
        M2C_FIELD(&gThreadManager, s32 *, THREAD_MANAGER_LOCK) = lock + 1;
    }
    OS_RestoreInterrupts(intrMode);
    return previous;
}

/* Let the cooperative scheduler run again: under an interrupt lock, decrement
 * its disable count and return the count before the change (0 when it was
 * already enabled). */
s32 OS_EnableScheduler(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gThreadManager;
    s32 state;
    s32 previous;
    s32 lock;

    state = OS_DisableInterrupts();
    previous = 0;
    lock = M2C_FIELD(&gThreadManager, s32 *, THREAD_MANAGER_LOCK);
    if (lock != 0) {
        previous = lock;
        M2C_FIELD(&gThreadManager, s32 *, THREAD_MANAGER_LOCK) = lock - 1;
    }
    OS_RestoreInterrupts(state);
    return previous;
}

void func_02006198(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xB4) = arg1;
}

#pragma optimization_level 1
void InitThreadContext(void *arg0, s32 arg1, s32 arg2) {
arg1+=4;
M2C_FIELD(arg0,s32 *,0x40)=arg1;
M2C_FIELD(arg0,s32 *,0x44)=arg2;
arg2-=0x40;
if(!(arg2&4))goto aligned;
arg2-=4;
aligned:
M2C_FIELD(arg0,s32 *,0x38)=arg2;
arg1 &= 1;
if(arg1)goto thumb_state;
arg1=0x1f;goto state_done;
thumb_state: arg1=0x3f;
state_done:
M2C_FIELD(arg0,s32 *,0)=arg1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
}
#pragma optimization_level reset
s32 func_020062b4(void) {
    return 0;
}

s32 func_020062bc(void) {
    extern s32 data_020f5218;
    s32 v = 0x82000001;
    data_020f5218 = v;
    return v;
}

void OS_InitMessageQueue(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg2;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

/* Send a message to a thread message queue: with OS_MESSAGE_BLOCK it sleeps on
 * the queue while it is full, then stores the message at firstIndex + usedCount
 * (wrapped over the slot count), counts it and wakes a thread waiting to
 * receive.  Returns 0 when a non-blocking call finds the queue full, 1 once the
 * message is queued. */
s32 OS_SendMessage(OSMessageQueue *queue, s32 message, s32 flags) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    M2C_UNK OS_WakeupThread(void *);
    unsigned long long RuntimeIntDivMod(s32, s32);
    s32 state;

    state = OS_DisableInterrupts();
    while (queue->msgCount <= queue->usedCount) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        OS_SleepThread(&queue->sendQueue);
    }
    queue->msgArray[(s32)(RuntimeIntDivMod(queue->firstIndex + queue->usedCount, queue->msgCount) >> 32)] = message;
    queue->usedCount = queue->usedCount + 1;
    OS_WakeupThread(&queue->receiveQueue);
    OS_RestoreInterrupts(state);
    return 1;
}

/* Takes one message from a thread message queue: with OS_MESSAGE_BLOCK it waits
 * for the queue to fill, then copies out the oldest message, advances firstIndex
 * modulo the slot count, drops usedCount and wakes a sender.  Returns 0 when a
 * non-blocking call finds the queue empty, 1 when a message was taken. */
s32 OS_ReceiveMessage(OSMessageQueue *queue, s32 *msg, s32 flags) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    M2C_UNK OS_WakeupThread(void *);
    unsigned long long RuntimeIntDivMod(s32, s32);
    s32 state;

    state = OS_DisableInterrupts();
    while (queue->usedCount == 0) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        OS_SleepThread((u8 *)queue + 8);
    }
    if (msg != NULL) {
        *msg = queue->msgArray[queue->firstIndex];
    }
    queue->firstIndex = (s32)(RuntimeIntDivMod(queue->firstIndex + 1, queue->msgCount) >> 32);
    queue->usedCount = queue->usedCount - 1;
    OS_WakeupThread(queue);
    OS_RestoreInterrupts(state);
    return 1;
}

/* Put a message at the front of a message queue: wait for a free slot when the
 * flags allow blocking, step firstIndex one place back (wrapping), store the
 * message there, and wake a thread waiting on the receive queue. */
s32 OS_JamMessage(void *queue, s32 message, s32 flags) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    M2C_UNK OS_WakeupThread(void *);
    unsigned long long RuntimeIntDivMod(s32, s32);
    s32 state;

    state = OS_DisableInterrupts();
    while (M2C_FIELD(queue, s32 *, 0x14) <= M2C_FIELD(queue, s32 *, 0x1C)) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        OS_SleepThread(queue);
    }
    ((s32 *)M2C_FIELD(queue, void **, 0x10))[
        M2C_FIELD(queue, s32 *, 0x18) =
            (s32)(RuntimeIntDivMod(M2C_FIELD(queue, s32 *, 0x18) + M2C_FIELD(queue, s32 *, 0x14) - 1, M2C_FIELD(queue, s32 *, 0x14)) >> 32)
    ] = message;
    M2C_FIELD(queue, s32 *, 0x1C) = M2C_FIELD(queue, s32 *, 0x1C) + 1;
    OS_WakeupThread((u8 *)queue + 8);
    OS_RestoreInterrupts(state);
    return 1;
}

/* Read the message at the head of a thread message queue without removing it:
 * with OS_MESSAGE_BLOCK it sleeps on the queue's receive list until one arrives.
 * Returns 0 when a non-blocking call finds the queue empty, 1 otherwise. */
s32 OS_ReadMessage(OSMessageQueue *queue, s32 *msg, s32 flags) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    s32 state;

    state = OS_DisableInterrupts();
    while (queue->usedCount == 0) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        OS_SleepThread(&queue->receiveQueue);
    }
    if (msg != NULL) {
        u32 idx = queue->firstIndex;
        s32 *base = queue->msgArray;
        *msg = base[idx];
    }
    OS_RestoreInterrupts(state);
    return 1;
}

void InitMutex(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}

/* Lock an OSMutex for the running thread: claim a free mutex, count the lock when
 * the running thread already holds it (re-entrant), or sleep on it until the
 * holder releases it. */
void LockMutex(void *mutex) {
    s32 OS_DisableInterrupts();
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    void AppendThreadMutex(void *, void *);
    extern M2C_UNK gSocketManager;
    s32 irq;
    void *thread;
    u32 count;

    irq = OS_DisableInterrupts();
    thread = M2C_FIELD(&gSocketManager, void **, 0x4); /* the running thread */
    while (1) {
        void *holder = M2C_FIELD(mutex, void **, OSMUTEX_OWNER);
        if (holder == NULL) {
            M2C_FIELD(mutex, void **, OSMUTEX_OWNER) = thread;
            count = M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) + 1;
            M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) = count;
            AppendThreadMutex(thread, mutex);
            break;
        }
        if (holder == thread) {
            count = M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) + 1;
            M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) = count;
            break;
        }
        M2C_FIELD(thread, void **, THREAD_WAIT_MUTEX) = mutex;
        OS_SleepThread(mutex);
        M2C_FIELD(thread, void **, THREAD_WAIT_MUTEX) = NULL;
    }
    OS_RestoreInterrupts(irq);
}

/* Release an OS mutex held by the running thread: count its nested locks down and,
 * on the last one, unlink the mutex from the thread and wake the threads sleeping
 * on it. */
void UnlockMutex(void *mutex) {
    s32 OS_DisableInterrupts();
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_WakeupThread(void *);
    void RemoveThreadMutex(void *, void *);
    extern M2C_UNK gSocketManager;
    s32 irq;
    void *thread;
    u32 count;

    irq = OS_DisableInterrupts();
    thread = M2C_FIELD(&gSocketManager, void **, 0x4); /* the running thread */
    if (M2C_FIELD(mutex, void **, OSMUTEX_OWNER) == thread) {
        count = M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT);
        count = count - 1;
        M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) = count;
        if (count == 0) {
            RemoveThreadMutex(thread, mutex);
            M2C_FIELD(mutex, void **, OSMUTEX_OWNER) = NULL;
            OS_WakeupThread(mutex);
        }
    }
    OS_RestoreInterrupts(irq);
}

/* Release every mutex a terminating thread still holds: take each one off the
 * thread's locked-mutex list, clear its owner and lock count, and wake the
 * threads waiting on it. */
void ReleaseThreadMutexes(Thread *thread) {
    void *PopThreadMutex(void *);
    M2C_UNK OS_WakeupThread();
    void *mutex;

    if (M2C_FIELD(thread, s32 *, THREAD_MUTEX_LIST_HEAD) == 0) {
        return;
    }
    do {
        mutex = PopThreadMutex((u8 *)thread + THREAD_MUTEX_LIST_HEAD);
        M2C_FIELD(mutex, s32 *, OSMUTEX_COUNT) = 0;
        M2C_FIELD(mutex, void **, OSMUTEX_OWNER) = 0;
        OS_WakeupThread(mutex);
    } while (M2C_FIELD(thread, s32 *, THREAD_MUTEX_LIST_HEAD) != 0);
}

/* Try to take an OS mutex for the running thread without blocking: take it when
 * free, count another lock when the running thread already holds it, and return
 * 0 when someone else owns it. */
s32 TryLockMutex(void *mutex) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void AppendThreadMutex(void *, void *);
    extern M2C_UNK gSocketManager;
    void *thread;
    void *owner;
    s32 irq;
    s32 locked;

    irq = OS_DisableInterrupts();
    thread = M2C_FIELD(&gSocketManager, void **, 0x4); /* the running thread */
    owner = M2C_FIELD(mutex, void **, OSMUTEX_OWNER);
    if (owner == NULL) {
        u32 count;
        M2C_FIELD(mutex, void **, OSMUTEX_OWNER) = thread;
        count = M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) + 1;
        M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) = count;
        AppendThreadMutex(thread, mutex);
        locked = 1;
    } else if (owner == thread) {
        M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) = M2C_FIELD(mutex, u32 *, OSMUTEX_COUNT) + 1;
        locked = 1;
    } else {
        locked = 0;
    }
    OS_RestoreInterrupts(irq);
    return locked;
}

void AppendThreadMutex(void *arg0, void *arg1) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0x8C);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, void **, 0x88) = arg1;
    } else {
        M2C_FIELD(temp_r2, void **, 0x10) = arg1;
    }
    M2C_FIELD(arg1, void **, 0x14) = temp_r2;
    M2C_FIELD(arg1, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, void **, 0x8C) = arg1;
}

void RemoveThreadMutex(void *arg0, void *arg1) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 0x10);
    temp_r1 = M2C_FIELD(arg1, void **, 0x14);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, void **, 0x8C) = temp_r1;
    } else {
        M2C_FIELD(temp_r2, void **, 0x14) = temp_r1;
    }
    if (temp_r1 == NULL) {
        M2C_FIELD(arg0, void **, 0x88) = temp_r2;
        return;
    }
    M2C_FIELD(temp_r1, void **, 0x10) = temp_r2;
}

#pragma opt_propagation off
void WaitForVBlankStart(void) { u32 saved; u32 *io; io=(u32 *)0x04000000; saved=io[0x82]; io[0x82]=(u32)io; do {} while(*(volatile u16 *)((u8 *)io+6)); io[0x82]=saved; }
#pragma opt_propagation reset
/* Bring up the system services and drivers the game runs on: the memory arenas,
 * the ARM7/IPC links, the exception handler, sound and DMA, the OS timer and
 * thread manager, the VRAM bank table, the save device, multiboot and the ARM7
 * command channel, finishing with a VBlank-synchronised interrupt restore. */
void InitSystemServices(void) {
    M2C_UNK func_02004fe0();
    M2C_UNK func_02005254();
    M2C_UNK func_02005288();
    M2C_UNK func_02005968();
    void WaitForVBlankStart(void);
    void InitArenaTable(void);
    void InstallExceptionHandler();
    M2C_UNK InitVCountIrqModule();
    M2C_UNK InitArm7BootSync();
    M2C_UNK GX_ResetBankOwners();
    M2C_UNK func_02008bb8();
    M2C_UNK PXI_Init();
    M2C_UNK Arm7CommandInit();
    M2C_UNK SaveDevice_Init();
    M2C_UNK Mb_BootInit();
    InitArenaTable();
    PXI_Init();
    func_02005288();
    func_020069a4();
    func_02004fe0();
    func_02005254();
    InstallExceptionHandler();
    func_02008bb8();
    InitVCountIrqModule();
    GX_ResetBankOwners();
    func_02005968();
    InitArm7BootSync();
    Mb_BootInit();
    SaveDevice_Init();
    Arm7CommandInit();
    WaitForVBlankStart();
}

/* Fills the arena table once: the top and bottom address of each arena's memory
   range, as the current boot's memory map gives them (arena 2 stays empty). */
void InitArenaTable(void) {
    s32 func_02006a38(s32);
    void SetArenaHi(s32, s32);
    s32 GetArenaBottom(s32);
    void SetArenaLo(s32, s32);
    extern M2C_UNK data_0212defc;

    if (M2C_FIELD(&data_0212defc, s32 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0212defc, s32 *, 0) = 1;
    SetArenaHi(0, func_02006a38(0));
    SetArenaLo(0, GetArenaBottom(0));
    SetArenaLo(2, 0);
    SetArenaHi(2, 0);
    SetArenaHi(3, func_02006a38(3));
    SetArenaLo(3, GetArenaBottom(3));
    SetArenaHi(4, func_02006a38(4));
    SetArenaLo(4, GetArenaBottom(4));
    SetArenaHi(5, func_02006a38(5));
    SetArenaLo(5, GetArenaBottom(5));
    SetArenaHi(6, func_02006a38(6));
    SetArenaLo(6, GetArenaBottom(6));
}

s32 GetArenaHi(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDC4);
}

s32 GetArenaLo(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDA0);
}

s32 func_02006a38(s32 arg0) {
s32 func_020062bc(void); extern M2C_UNK data_0212defc,gOsArea; extern char data_00000000[],data_00000800[];
switch(arg0) {
case 0:return 0x23e0000;
case 2: if(M2C_FIELD(&data_0212defc,s32 *,4)!=0) {if((func_020062bc()&3)==1)return 0;else goto mainram;} else return 0x2700000;
case 3:mainram:return 0x2000000;
case 4:{s32 a=(s32)&gOsArea; s32 c; s32 e; arg0=(s32)data_00000000; c=(s32)data_00000800; e=a+0x3f80; c=e-c;
if(arg0==0){if((u32)a<0x27e15e0U)a=0x27e15e0;return a;} if(arg0<0)return 0x27e15e0-arg0;return c-arg0;}
case 5:return 0x27ff680;case 6:return 0x37f8000;default:return 0;
}}

/* Return the bottom address of a heap arena's memory range; arena 1 has none,
 * and arena 2's range depends on the boot's extended-memory flag and on the
 * console type. */
s32 GetArenaBottom(s32 arena) {
    s32 func_020062bc(void);
    extern M2C_UNK data_0212defc;

    switch (arena) {
    case 0:
        return 0x0223c840;
    case 2:
        if (M2C_FIELD(&data_0212defc, s32 *, 4) == 0) {
            goto empty;
        }
        if ((func_020062bc() & 0x3) != 1) {
            goto extended;
        }
empty:
        return 0;
extended:
        return 0x023e0000;
    case 3:
        return 0x01ffc780;
    case 4:
        return 0x027e15e0;
    case 5:
        return 0x027ff000;
    case 6:
        return 0x037f8000;
    case 1:
    default:
        return 0;
    }
}

void SetArenaHi(s32 arg0, s32 arg1) {
    M2C_FIELD((((u32)arg0 * 4) + (s32)0x027FF000), s32 *, 0xDC4) = arg1;
}

void SetArenaLo(s32 arg0, s32 arg1) {
    M2C_FIELD(((arg0 * 4) + (unsigned)0x027FF000), s32 *, 0xDA0) = arg1;
}

/* Allocate size bytes with the given alignment from an arena: align the arena's
 * low bound up, align the end of the block up too, and fail when that end would
 * pass the arena's high bound.  Returns the aligned block address. */
s32 AllocFromArena(s32 arena, s32 size, s32 alignment) {
    s32 lo;
    s32 alignMask;
    s32 start;
    s32 end;
    u32 alignedEnd;

    lo = GetArenaLo(arena);
    if (lo == 0) {
        return 0;
    }
    alignMask = ~(alignment - 1);
    start = alignMask & ((lo + alignment) - 1);
    end = start + size;
    alignedEnd = alignMask & ((end + alignment) - 1);
    if (alignedEnd > (u32)GetArenaHi(arena)) {
        return 0;
    }
    SetArenaLo(arena, alignedEnd);
    return start;
}

void func_02006c58(void) {
    extern M2C_UNK data_0212defc;
    M2C_FIELD(&data_0212defc, s32 *, 4) = 0;
}

/* Install the module's exception handler at start-up: remember any handler the
 * loader left in the main-RAM exception vector so the new handler can chain to
 * it, and when the vector holds none, write this module's exception entry there
 * and into the OS work area's vector.  The handler state's third word is then
 * cleared. */
void InstallExceptionHandler(void) {
extern u32 gExceptionHandlerState[3];
void func_02006d54(void);
u32 leftHandler=*(u32 *)0x27ffd9c;
if(leftHandler>=0x2600000u && leftHandler<0x2800000u) gExceptionHandlerState[0]=leftHandler;
else gExceptionHandlerState[0]=0;
if(gExceptionHandlerState[0]==0) {
*(u32 *)0x27ffd9c=(u32)func_02006d54;
{u32 *osArea=(u32 *)0x27e3000; osArea[0x3f7]=(u32)func_02006d54;}
}
gExceptionHandlerState[2]=0;
}

#pragma optimization_level 4
void func_02006dd8(void) {void func_02006dec(void);void func_02006e7c(void);func_02006dec();func_02006e7c();}
void func_02006ef8(s32 arg0) {
    extern u16 data_0212dfb0;
    u16 v = data_0212dfb0;
    data_0212dfb0 = v | (1u << arg0);
}

