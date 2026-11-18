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

s32 func_02006028(void *arg0) {
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

s32 OS_DisableScheduler(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gThreadManager;
    s32 state;
    s32 r;
    s32 v;
    s32 limit = -1;

    state = OS_DisableInterrupts();
    v = M2C_FIELD(&gThreadManager, s32 *, 4);
    if ((u32)v < (u32)limit) {
        r = v;
        M2C_FIELD(&gThreadManager, s32 *, 4) = v + 1;
    }
    OS_RestoreInterrupts(state);
    return r;
}

s32 OS_EnableScheduler(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gThreadManager;
    s32 state;
    s32 r;
    s32 v;

    state = OS_DisableInterrupts();
    r = 0;
    v = M2C_FIELD(&gThreadManager, s32 *, 4);
    if (v != 0) {
        r = v;
        M2C_FIELD(&gThreadManager, s32 *, 4) = v - 1;
    }
    OS_RestoreInterrupts(state);
    return r;
}

void func_02006198(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xB4) = arg1;
}

#pragma optimization_level 1
void func_020061a0(void *arg0, s32 arg1, s32 arg2) {
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

s32 OS_SendMessage(void *arg0, s32 arg1, s32 arg2) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    M2C_UNK OS_WakeupThread(void *);
    unsigned long long func_020720f0(s32, s32);
    s32 state;

    state = OS_DisableInterrupts();
    while (M2C_FIELD(arg0, s32 *, 0x14) <= M2C_FIELD(arg0, s32 *, 0x1C)) {
        if (!(arg2 & 1)) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        OS_SleepThread(arg0);
    }
    ((s32 *)M2C_FIELD(arg0, void **, 0x10))[(s32)(func_020720f0(M2C_FIELD(arg0, s32 *, 0x18) + M2C_FIELD(arg0, s32 *, 0x1C), M2C_FIELD(arg0, s32 *, 0x14)) >> 32)] = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
    OS_WakeupThread((u8 *)arg0 + 8);
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
    unsigned long long func_020720f0(s32, s32);
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
    queue->firstIndex = (s32)(func_020720f0(queue->firstIndex + 1, queue->msgCount) >> 32);
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
    unsigned long long func_020720f0(s32, s32);
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
            (s32)(func_020720f0(M2C_FIELD(queue, s32 *, 0x18) + M2C_FIELD(queue, s32 *, 0x14) - 1, M2C_FIELD(queue, s32 *, 0x14)) >> 32)
    ] = message;
    M2C_FIELD(queue, s32 *, 0x1C) = M2C_FIELD(queue, s32 *, 0x1C) + 1;
    OS_WakeupThread((u8 *)queue + 8);
    OS_RestoreInterrupts(state);
    return 1;
}

s32 OS_ReadMessage(void *arg0, s32 *arg1, s32 arg2) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    s32 state;

    state = OS_DisableInterrupts();
    while (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (!(arg2 & 1)) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        OS_SleepThread((u8 *)arg0 + 8);
    }
    if (arg1 != NULL) {
        u32 idx = M2C_FIELD(arg0, u32 *, 0x18);
        s32 *base = M2C_FIELD(arg0,s32 **,0x10);
        *arg1 = base[idx];
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

void LockMutex(void *arg0) {
    s32 OS_DisableInterrupts();
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    void func_020066f4(void *, void *);
    extern M2C_UNK gSocketManager;
    s32 state;
    void *head;
    u32 c;

    state = OS_DisableInterrupts();
    head = M2C_FIELD(&gSocketManager, void **, 0x4);
    while (1) {
        void *cur = M2C_FIELD(arg0, void **, 0x8);
        if (cur == NULL) {
            M2C_FIELD(arg0, void **, 0x8) = head;
            c = M2C_FIELD(arg0, u32 *, 0xC) + 1;
            M2C_FIELD(arg0, u32 *, 0xC) = c;
            func_020066f4(head, arg0);
            break;
        }
        if (cur == head) {
            c = M2C_FIELD(arg0, u32 *, 0xC) + 1;
            M2C_FIELD(arg0, u32 *, 0xC) = c;
            break;
        }
        M2C_FIELD(head, void **, 0x84) = arg0;
        OS_SleepThread(arg0);
        M2C_FIELD(head, void **, 0x84) = NULL;
    }
    OS_RestoreInterrupts(state);
}

void UnlockMutex(void *arg0) {
    s32 OS_DisableInterrupts();
    void OS_RestoreInterrupts(s32);
    M2C_UNK OS_WakeupThread(void *);
    void func_02006718(void *, void *);
    extern M2C_UNK gSocketManager;
    s32 state;
    void *head;
    u32 c;

    state = OS_DisableInterrupts();
    head = M2C_FIELD(&gSocketManager, void **, 0x4);
    if (M2C_FIELD(arg0, void **, 0x8) == head) {
        c = M2C_FIELD(arg0, u32 *, 0xC);
        c = c - 1;
        M2C_FIELD(arg0, u32 *, 0xC) = c;
        if (c == 0) {
            func_02006718(head, arg0);
            M2C_FIELD(arg0, void **, 0x8) = NULL;
            OS_WakeupThread(arg0);
        }
    }
    OS_RestoreInterrupts(state);
}

void func_02006644(void *arg0) {
    void *func_020057c8(void *);
    M2C_UNK OS_WakeupThread();
    void *temp_r0;

    if (M2C_FIELD(arg0, s32 *, 0x88) == 0) {
        return;
    }
    do {
        temp_r0 = func_020057c8(arg0 + 0x88);
        M2C_FIELD(temp_r0, s32 *, 0xC) = 0;
        M2C_FIELD(temp_r0, s32 *, 8) = 0;
        OS_WakeupThread();
    } while (M2C_FIELD(arg0, s32 *, 0x88) != 0);
}

s32 TryLockMutex(void *arg0) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void func_020066f4(void *, void *);
    extern M2C_UNK gSocketManager;
    void *head;
    void *cur;
    s32 state;
    s32 r6;

    state = OS_DisableInterrupts();
    head = M2C_FIELD(&gSocketManager, void **, 0x4);
    cur = M2C_FIELD(arg0, void **, 0x8);
    if (cur == NULL) {
        u32 tmp;
        M2C_FIELD(arg0, void **, 0x8) = head;
        tmp = M2C_FIELD(arg0, u32 *, 0xC) + 1;
        M2C_FIELD(arg0, u32 *, 0xC) = tmp;
        func_020066f4(head, arg0);
        r6 = 1;
    } else if (cur == head) {
        M2C_FIELD(arg0, u32 *, 0xC) = M2C_FIELD(arg0, u32 *, 0xC) + 1;
        r6 = 1;
    } else {
        r6 = 0;
    }
    OS_RestoreInterrupts(state);
    return r6;
}

void func_020066f4(void *arg0, void *arg1) {
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

void func_02006718(void *arg0, void *arg1) {
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
void func_02006838(void) { u32 saved; u32 *io; io=(u32 *)0x04000000; saved=io[0x82]; io[0x82]=(u32)io; do {} while(*(volatile u16 *)((u8 *)io+6)); io[0x82]=saved; }
#pragma opt_propagation reset
void func_02006858(void) {
    M2C_UNK func_02004fe0();
    M2C_UNK func_02005254();
    M2C_UNK func_02005288();
    M2C_UNK func_02005968();
    void func_02006838(void);
void InitArenaTable(void);
    void func_02006ce4();
    M2C_UNK func_020074c0();
    M2C_UNK func_020075b4();
    M2C_UNK func_020077cc();
    M2C_UNK func_02008bb8();
    M2C_UNK func_02009d34();
    M2C_UNK Arm7CommandInit();
    M2C_UNK func_02010c14();
    M2C_UNK Mb_BootInit();
    InitArenaTable();
    func_02009d34();
    func_02005288();
    func_020069a4();
    func_02004fe0();
    func_02005254();
    func_02006ce4();
    func_02008bb8();
    func_020074c0();
    func_020077cc();
    func_02005968();
    func_020075b4();
    Mb_BootInit();
    func_02010c14();
    Arm7CommandInit();
    func_02006838();
}

/* Fills the arena table once: the top and bottom address of each arena's memory
   range, as the current boot's memory map gives them (arena 2 stays empty). */
void InitArenaTable(void) {
    s32 func_02006a38(s32);
    void func_02006bc4(s32, s32);
    s32 GetArenaBottom(s32);
    void func_02006bd8(s32, s32);
    extern M2C_UNK data_0212defc;

    if (M2C_FIELD(&data_0212defc, s32 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0212defc, s32 *, 0) = 1;
    func_02006bc4(0, func_02006a38(0));
    func_02006bd8(0, GetArenaBottom(0));
    func_02006bd8(2, 0);
    func_02006bc4(2, 0);
    func_02006bc4(3, func_02006a38(3));
    func_02006bd8(3, GetArenaBottom(3));
    func_02006bc4(4, func_02006a38(4));
    func_02006bd8(4, GetArenaBottom(4));
    func_02006bc4(5, func_02006a38(5));
    func_02006bd8(5, GetArenaBottom(5));
    func_02006bc4(6, func_02006a38(6));
    func_02006bd8(6, GetArenaBottom(6));
}

s32 func_02006a10(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDC4);
}

s32 func_02006a24(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDA0);
}

s32 func_02006a38(s32 arg0) {
s32 func_020062bc(void); extern M2C_UNK data_0212defc,data_027e0000; extern char data_00000000[],data_00000800[];
switch(arg0) {
case 0:return 0x23e0000;
case 2: if(M2C_FIELD(&data_0212defc,s32 *,4)!=0) {if((func_020062bc()&3)==1)return 0;else goto mainram;} else return 0x2700000;
case 3:mainram:return 0x2000000;
case 4:{s32 a=(s32)&data_027e0000; s32 c; s32 e; arg0=(s32)data_00000000; c=(s32)data_00000800; e=a+0x3f80; c=e-c;
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

void func_02006bc4(s32 arg0, s32 arg1) {
    M2C_FIELD((((u32)arg0 * 4) + (s32)0x027FF000), s32 *, 0xDC4) = arg1;
}

void func_02006bd8(s32 arg0, s32 arg1) {
    M2C_FIELD(((arg0 * 4) + (unsigned)0x027FF000), s32 *, 0xDA0) = arg1;
}

s32 func_02006bec(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r2;
    s32 temp_r4;
    s32 temp;
    u32 temp_r5;

    temp_r0 = func_02006a24(arg0);
    if (temp_r0 == 0) {
        return 0;
    }
    temp_r2 = ~(arg2 - 1);
    temp_r4 = temp_r2 & ((temp_r0 + arg2) - 1);
    temp = temp_r4 + arg1;
    temp_r5 = temp_r2 & ((temp + arg2) - 1);
    if (temp_r5 > (u32)func_02006a10(arg0)) {
        return 0;
    }
    func_02006bd8(arg0, temp_r5);
    return temp_r4;
}

void func_02006c58(void) {
    extern M2C_UNK data_0212defc;
    M2C_FIELD(&data_0212defc, s32 *, 4) = 0;
}

void func_02006ce4(void) {
extern u32 data_0212df04[3];
void func_02006d54(void);
u32 v=*(u32 *)0x27ffd9c;
if(v>=0x2600000u && v<0x2800000u) data_0212df04[0]=v;
else data_0212df04[0]=0;
if(data_0212df04[0]==0) {
*(u32 *)0x27ffd9c=(u32)func_02006d54;
{u32 *base=(u32 *)0x27e3000; base[0x3f7]=(u32)func_02006d54;}
}
data_0212df04[2]=0;
}

#pragma optimization_level 4
void func_02006dd8(void) {void func_02006dec(void);void func_02006e7c(void);func_02006dec();func_02006e7c();}
void func_02006ef8(s32 arg0) {
    extern u16 data_0212dfb0;
    u16 v = data_0212dfb0;
    data_0212dfb0 = v | (1u << arg0);
}

