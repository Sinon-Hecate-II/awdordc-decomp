/* 56 functions from 0x02004FF8 to 0x02005F80 (main), found by ds-decomp. */
#include "common.h"
static inline u8 *stack_end_02005968(void) {
extern M2C_UNK gOsArea;
extern char data_00000800[];
return (u8 *)&gOsArea+0x3f80-(s32)data_00000800;
}
static inline u8 *stack_start_02005968(void) {
extern char data_00000000[];
s32 size=(s32)data_00000000;
u8 *p;
if(size<=0)p=(u8 *)0x027e15e0;
else p=stack_end_02005968();
return p-size;
}

/* Install each selected IRQ handler in the OS table or its shared DMA/timer channel record. */
void OS_SetIrqHandler(u32 irqMask, s32 handler) {
    extern M2C_UNK gDmaTimerIrqHandlers;
    extern M2C_UNK gOsArea;
    s32 irqIndex;
    s32 *channelEntry;

    irqIndex = 0;
    do {
        if (irqMask & 1) {
            channelEntry = NULL;
            if (irqIndex >= IRQ_NUMBER_DMA0 && irqIndex <= IRQ_NUMBER_DMA3) {
                channelEntry = (s32 *)((s8 *)&gDmaTimerIrqHandlers + (irqIndex - IRQ_NUMBER_DMA0) * sizeof(IrqHandler));
            } else if (irqIndex >= IRQ_NUMBER_TIMER0 && irqIndex <= IRQ_NUMBER_TIMER3) {
                channelEntry = (s32 *)((s8 *)&gDmaTimerIrqHandlers + (irqIndex + 1) * sizeof(IrqHandler));
            } else {
                ((s32 *)&gOsArea)[irqIndex] = handler;
            }
            if (channelEntry != NULL) {
                channelEntry[0] = handler;
                channelEntry[2] = 0;
                channelEntry[1] = 1;
            }
        }
        irqIndex++;
        irqMask >>= 1;
    } while (irqIndex < IRQ_COUNT);
}

/* Return the handler registered for the lowest IRQ set in mask (IRQ n is bit n),
 * or 0 when the mask names no IRQ.  The timers and DMA channels keep their
 * handlers in the gDmaTimerIrqHandlers entries, every other IRQ straight in the
 * OS area's handler table. */
s32 OS_GetIrqHandler(u32 mask) {
    extern M2C_UNK gDmaTimerIrqHandlers;
    extern s32 gOsArea;
    s32 irq;
    s32 *handler;
    handler = &gOsArea;
    irq = 0;
    do {
        if (mask & 1) {
            if (irq >= IRQ_NUMBER_DMA0 && irq <= IRQ_NUMBER_DMA3) {
                return M2C_FIELD(&gDmaTimerIrqHandlers, s32 *, (irq - IRQ_NUMBER_DMA0) * sizeof(IrqHandler));
            }
            if (irq >= IRQ_NUMBER_TIMER0 && irq <= IRQ_NUMBER_TIMER3) {
                return M2C_FIELD(&gDmaTimerIrqHandlers, s32 *, (IRQ_HANDLER_DMA_COUNT + irq - IRQ_NUMBER_TIMER0) * sizeof(IrqHandler));
            }
            return *handler;
        }
        irq++;
        mask >>= 1;
        handler++;
    } while (irq < IRQ_COUNT);
    return 0;
}

#pragma scheduling on
void OS_SetDmaHandler(s32 arg0, s32 arg1, s32 arg2) {
    s32 OS_EnableIrqMask(s32);
    extern M2C_UNK gDmaTimerIrqHandlers;
    extern M2C_UNK data_0212dc20;
    extern M2C_UNK data_0212dc24;
    s32 shift;
    s32 offset;
    offset = arg0 * 12;
    shift = arg0 + 8;
    M2C_FIELD(&gDmaTimerIrqHandlers, s32 *, offset) = arg1;
    M2C_FIELD(&data_0212dc24, s32 *, offset) = arg2;
    M2C_FIELD(&data_0212dc20, s32 *, offset) = OS_EnableIrqMask(1 << shift) & (1 << shift);
}
#pragma optimization_level 2
void func_02005154(s32 arg0, s32 arg1, s32 arg2) {
 s32 OS_EnableIrqMask(s32);
 extern M2C_UNK data_0212dc4c, data_0212dc50, data_0212dc54;
 s32 offset = arg0 * 12;
 M2C_FIELD(&data_0212dc4c, volatile s32 *, offset) = arg1;
 M2C_FIELD(&data_0212dc54, volatile s32 *, offset) = arg2;
 OS_EnableIrqMask(1 << (arg0 + 3));
 M2C_FIELD(&data_0212dc50, s32 *, offset) = 1;
}
#pragma optimization_level reset
s32 OS_SetIrqEnableMask(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000210;
    *(volatile s32 *)0x04000210 = arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

s32 OS_EnableIrqMask(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000210;
    *(volatile s32 *)0x04000210 = old | arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

s32 OS_DisableIrqMask(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000210;
    *(volatile s32 *)0x04000210 = old & ~arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

s32 OS_SetIrqMask(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000214;
    *(volatile s32 *)0x04000214 = arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

#pragma opt_propagation off
void func_02005254(void) {
    extern M2C_UNK gOsArea;
    s32 off = 0x800;
    M2C_FIELD(&gOsArea, s32 *, 0x3F7C) = 0xFDDB597D;
    *(s32 *)((u8 *)&gOsArea + 0x3F80 - off) = 0x7BF9DD5B;
}
#pragma opt_propagation reset
void func_02005288(void) {
extern s32 data_0212dc7c;
void WaitByLoop(s32); void func_020053a0(s32,s32,s32);void func_02005424(s32,s32,s32);void CpuFill(s32,void *,s32);
volatile u8 *p=(volatile u8 *)0x027ffff0;
if(data_0212dc7c)return;
*(volatile s32 *)p=0;
*(s32 *)&data_0212dc7c=1;
func_020053a0(0x7e,0x027ffff0,0);
while(*(volatile u16 *)(p+6))WaitByLoop(0x400);
*(volatile s32 *)0x027fffb0=-1;
*(volatile s32 *)0x027fffb4=0xffff0000;
CpuFill(0,(void *)0x027fffc0,0x28);
*(volatile u16 *)0x04000204|=0x800;
*(volatile u16 *)0x04000204|=0x80;
func_02005424(0x7e,0x027ffff0,0);
func_020053a0(0x7f,0x027ffff0,0);
}

/* Block until the lock word at `lockAddress` is taken for `lockId`: retry
 * OSi_DoLockByWord, spinning on WaitByLoop while the word is already taken.
 * `onLock` runs when the lock is acquired and `maskFiq` selects the interrupt
 * mask the take runs under. */
M2C_UNK OS_LockByWord(M2C_UNK lockId, M2C_UNK lockAddress, M2C_UNK onLock, M2C_UNK maskFiq) {
    void WaitByLoop(s32);
    M2C_UNK OSi_DoLockByWord(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

    if (OSi_DoLockByWord(lockId, lockAddress, onLock, maskFiq) <= 0) return;
    do {
        WaitByLoop(0x400);
    } while (OSi_DoLockByWord(lockId, lockAddress, onLock, maskFiq) > 0);
}

void func_020053a0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK OS_LockByWord(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    OS_LockByWord(arg0, arg1, arg2, 0);
}

/* Release a lock word owned by lockId, running the optional cleanup with interrupts masked. */
s32 OSi_DoUnlockByWord(s32 lockId, s32 lockAddress, s32 onUnlock, s32 maskFiq) {
    s32 OS_DisableInterrupts();
    s32 OS_DisableInterrupts_IrqAndFiq();
    s32 OS_RestoreInterrupts_IrqAndFiq(s32);
    s32 OS_RestoreInterrupts(s32);
    s32 interruptState;

    if (lockId != ((OSLockWord *)lockAddress)->ownerId) {
        return OS_UNLOCK_NOT_OWNER;
    }
    if (maskFiq != 0) {
        interruptState = OS_DisableInterrupts_IrqAndFiq();
    } else {
        interruptState = OS_DisableInterrupts();
    }
    ((OSLockWord *)lockAddress)->ownerId = 0;
    if (onUnlock != 0) {
        ((void (*)(void))onUnlock)();
    }
    ((OSLockWord *)lockAddress)->lockFlag = 0;
    if (maskFiq != 0) {
        OS_RestoreInterrupts_IrqAndFiq(interruptState);
    } else {
        OS_RestoreInterrupts(interruptState);
    }
    return 0;
}

void func_02005424(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK OSi_DoUnlockByWord(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    OSi_DoUnlockByWord(arg0, arg1, arg2, 0);
}

/* Take the lock word at `lockAddress` for `lockId`: mask interrupts, atomically swap
 * the word, and when it was free store the owner id and run the onLock callback.
 * Returns 0 when the lock was taken, otherwise the word that was already there. */
s32 OSi_DoLockByWord(s32 lockId, s32 lockAddress, M2C_UNK onLock, s32 maskFiq) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_DisableInterrupts_IrqAndFiq();
    M2C_UNK OS_RestoreInterrupts_IrqAndFiq(M2C_UNK);
    M2C_UNK OS_RestoreInterrupts(M2C_UNK);
    s32 func_020081c8(M2C_UNK, M2C_UNK);
    s32 interruptState;
    s32 result;

    if (maskFiq != 0) {
        interruptState = OS_DisableInterrupts_IrqAndFiq();
    } else {
        interruptState = OS_DisableInterrupts();
    }
    result = func_020081c8(lockId, lockAddress);
    if (result == 0) {
        if (onLock != 0) ((void (*)(void))onLock)();
        ((OSLockWord *)lockAddress)->ownerId = lockId;
    }
    if (maskFiq != 0) {
        OS_RestoreInterrupts_IrqAndFiq(interruptState);
    } else {
        OS_RestoreInterrupts(interruptState);
    }
    return result;
}

void func_020054a0(M2C_UNK arg0) {
    M2C_UNK OSi_DoUnlockByWord(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02005504(void);
    OSi_DoUnlockByWord(arg0, 0x027FFFE8, (M2C_UNK)func_02005504, 1);
}

void OSi_UnlockWord(M2C_UNK arg0) {
    void func_020054a0(M2C_UNK);
    func_020054a0(arg0);
}

void OSi_TryLockWord(M2C_UNK arg0) {
    M2C_UNK OSi_DoLockByWord(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020054ec(void);
    OSi_DoLockByWord(arg0, 0x027FFFE8, (M2C_UNK)func_020054ec, 1);
}

void func_020054ec(void) {
    *(u16 *)0x04000204 &= ~0x80;
}

void func_02005504(void) {
    *(u16 *)0x04000204 |= 0x80;
}

void func_0200551c(M2C_UNK arg0) {
    void func_02005554(void);
    func_020053a0(arg0, 0x027FFFE0, (M2C_UNK)func_02005554);
}

void func_02005538(M2C_UNK arg0) {
    void func_0200556c(void);
    func_02005424(arg0, 0x027FFFE0, (M2C_UNK)func_0200556c);
}

void func_02005554(void) {
    *(u16 *)0x04000204 &= ~0x800;
}

void func_0200556c(void) {
    *(u16 *)0x04000204 |= 0x800;
}

u16 OSi_GetLockOwnerId(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 4);
}

int __clz(unsigned int);
#pragma intrinsic(__clz)
s32 OS_GetLockID(void){
u32 *p=(u32*)0x027fffb0;
u32 n=__builtin_arm_clz(*p);
s32 result=64;
if(n==32){p++;n=__builtin_arm_clz(*p);if(n==32)return -3;result=96;}
result+=n;*p=*p & ~(0x80000000U>>n);return result;
}
void OS_ReleaseLockID(s32 a){u32 *p=(u32 *)0x027fffb0;u32 mask;if(a>=96)p++;if(a>=96)a-=96;else a-=64;mask=0x80000000U>>a;*p|=mask;}
#pragma optimization_level reset
void func_0200563c(s32 arg0, s32 arg1, ...) {
    void func_02005664();
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    func_02005664(arg0, arg1, args);
}

void func_02005664(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    void func_020056a4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020056a4(arg0, (M2C_UNK)0x7fffffff, arg1, arg2);
}

void StringFormatN(s32 arg0, s32 arg1, s32 arg2, ...) {
    void func_020056a4();
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_020056a4(arg0, arg1, arg2, args);

}

void func_020056a4() {
    M2C_UNK func_020195e8();
    func_020195e8();
}

s32 func_020056b0(void){
extern s32 gThreadManager;return ++M2C_FIELD(&gThreadManager,s32 *,32);
}

/* Insert `thread` into `queue` in run-priority order, keeping the queue's head
 * and tail and the thread's queue links consistent; a thread that is already in
 * the queue is left where it is. */
void OS_EnqueueThread(OSThreadQueue *queue,Thread *thread) {
    Thread *p=queue->head;
    Thread *prev;
    while(p!=NULL && (u32)p->priority<=(u32)thread->priority){
        if(p==thread)return;
        p=p->queueNext;
    }
    if(p==NULL){
        prev=queue->tail;
        if(prev==NULL)queue->head=thread;else prev->queueNext=thread;
        thread->queuePrev=prev;thread->queueNext=NULL;queue->tail=thread;
    }else{
        prev=p->queuePrev;
        if(prev==NULL)queue->head=thread;else prev->queueNext=thread;
        thread->queuePrev=prev;thread->queueNext=p;p->queuePrev=thread;
    }
}

void *DequeueThread(void *arg0) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if (temp_r2 != NULL) {
        temp_r1 = M2C_FIELD(temp_r2, void **, 0x80);
        M2C_FIELD(arg0, void **, 0) = temp_r1;
        if (temp_r1 != NULL) {
            M2C_FIELD(temp_r1, s32 *, 0x7C) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 4) = 0;
            M2C_FIELD(temp_r2, s32 *, 0x78) = 0;
        }
    }
    return temp_r2;
}

/* Remove `thread` from the wait queue `queue`, fixing the queue's head and tail
 * and its neighbours' links. Returns the thread, or NULL when it was not in the
 * queue. */
void *UnlinkThreadFromQueue(OSThreadQueue *queue, Thread *thread) {
    Thread *p, *next, *head;
    head = queue->head;
    p = head;
    while (p) {
        next = p->queueNext;
        if (p == thread) {
            Thread *prev = p->queuePrev;
            if (head == p) queue->head = next; else prev->queueNext = next;
            if (queue->tail == p) queue->tail = prev; else next->queuePrev = prev;
            break;
        }
        p = next;
    }
    return p;
}

void *func_020057c8(void *arg0) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if (temp_r2 != NULL) {
        temp_r1 = M2C_FIELD(temp_r2, void **, 0x10);
        M2C_FIELD(arg0, void **, 0) = temp_r1;
        if (temp_r1 != NULL) {
            M2C_FIELD(temp_r1, s32 *, 0x14) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 4) = 0;
        }
    }
    return temp_r2;
}

/* Insert `thread` into the ready list (THREAD_MANAGER_READY), keeping it ordered by
 * Thread::priority and chaining through Thread::next. */
void InsertReadyThread(Thread *thread) {
    extern M2C_UNK gThreadManager;
    Thread *p, *prev, *head;
    prev = 0;
    head = M2C_FIELD(&gThreadManager, Thread **, THREAD_MANAGER_READY);
    p = head;
    while (p && (u32)p->priority < (u32)thread->priority) {
        prev = p;
        p = p->next;
    }
    if (!prev) {
        thread->next = head;
        M2C_FIELD(&gThreadManager, Thread **, THREAD_MANAGER_READY) = thread;
    } else {
        thread->next = prev->next;
        prev->next = thread;
    }
}

void RemoveReadyThread(void *a) {
extern M2C_UNK gThreadManager;
void *prev=0,*p=M2C_FIELD(&gThreadManager,void **,0x2c);
while(p && p!=a){prev=p;p=M2C_FIELD(p,void **,0x68);}
if(!prev){M2C_FIELD(&gThreadManager,void **,0x2c)=M2C_FIELD(a,void **,0x68);}else{M2C_FIELD(prev,void **,0x68)=M2C_FIELD(a,void **,0x68);}
}

/* RescheduleThreads: the scheduler's switch point — pick the next runnable thread
   and switch to it after running the two thread-switch callbacks, unless the
   current thread must keep running.  Switching is deferred (gSocketManager+0 set)
   when scheduling is disabled or the CPU is in an interrupt mode (0x12 = IRQ). */
void RescheduleThreads(void) {
extern M2C_UNK gThreadManager;
extern M2C_UNK gSocketManager;
s32 GetProcessorMode(void); void *FindNextReadyThread(void); s32 func_02006224(void *); void SwitchThreadContext(s32);
void *manager; void *current,*next; void (*cb)(void *,void *);
if(M2C_FIELD(&gThreadManager,s32 *,4))return;
manager=&gSocketManager;
if(M2C_FIELD(&gThreadManager,u16 *,0x26) || GetProcessorMode()==18){M2C_FIELD(manager,u16 *,0)=1;return;}
current=M2C_FIELD(M2C_FIELD(&gThreadManager,void **,8),void **,0);
next=FindNextReadyThread();
if(current==next || next==0)return;
if(M2C_FIELD(current,s32 *,0x64)!=2 && func_02006224(current))return;
cb=M2C_FIELD(&gThreadManager,void (**)(void *,void *),0);if(cb)cb(current,next);
cb=M2C_FIELD(manager,void (**)(void *,void *),12);if(cb)cb(current,next);
M2C_FIELD(&gThreadManager,void **,0x28)=next;
SwitchThreadContext((s32)next);
}

#pragma scheduling off
void func_02005968(void) {
extern M2C_UNK data_0212dc80,data_0212dca8,data_0212dd74,data_027e0000,data_0212dca4,data_0212dcb4,data_0212defc;
extern char data_00000000[],data_00000800[]; void func_02006120(void);
void func_02005ac0(void *,void *,s32,u8 *,u32,s32);
s32 size;u8 *end,*start;
if(M2C_FIELD(&data_0212dc80,s32 *,12))return;
M2C_FIELD(&data_0212dc80,s32 *,12)=1;
M2C_FIELD(&data_0212dc80,void **,8)=&data_0212dca8;
M2C_FIELD(&data_0212dc80,s32 *,356)=16;
M2C_FIELD(&data_0212dc80,s32 *,352)=0;
M2C_FIELD(&data_0212dc80,s32 *,344)=1;
M2C_FIELD(&data_0212dc80,s32 *,348)=0;
M2C_FIELD(&data_0212dc80,s32 *,360)=0;
M2C_FIELD(&data_0212dc80,void **,44)=&data_0212dd74;
M2C_FIELD(&data_0212dc80,void **,40)=&data_0212dd74;
size=(s32)data_00000000;
if(size<=0)start=(u8 *)0x027e15e0;else start=(u8 *)&data_027e0000+0x3f80-(s32)data_00000800;
start-=size;
end=(u8 *)&data_027e0000+0x3f80-(s32)data_00000800;
M2C_FIELD(&data_0212dc80,void **,392)=end;
M2C_FIELD(&data_0212dc80,void **,388)=start;
M2C_FIELD(&data_0212dc80,s32 *,396)=0;
*(u32 *)(end-4)=0xfddb597d;
*M2C_FIELD(&data_0212dc80,u32 **,388)=0x7bf9dd5b;
M2C_FIELD(&data_0212dc80,s32 *,404)=0;
M2C_FIELD(&data_0212dc80,s32 *,400)=0;
M2C_FIELD(&data_0212dc80,u16 *,36)=0;
M2C_FIELD(&data_0212dc80,u16 *,38)=0;
*(void **)0x027fffa0=&data_0212dca4;
func_020060f8(0);
func_02005ac0(&data_0212dcb4,func_02006120,0,(u8 *)&data_0212defc,200,31);
M2C_FIELD(&data_0212dc80,s32 *,164)=32;
M2C_FIELD(&data_0212dc80,s32 *,152)=1;
}
#pragma scheduling reset
s32 func_02005ab0(void) {
    extern s32 data_0212dc8c;
    return data_0212dc8c;
}

/* Initializes a managed memory-block object (obj) backed by buffer (buf) of (bufLen) bytes, with priority (priority) and callback (callback); registers it in the global block list. */
void TaskCreate(void *obj,void *callback,s32 owner,u8 *buf,u32 bufLen,s32 priority) {
s32 OS_DisableInterrupts(void); s32 OS_RestoreInterrupts(s32);
void InitThreadContext(); void func_02006198();
void CpuFill(s32,void *,s32); void func_02005bbc(void);
s32 state; s32 id; u8 *base;
state=OS_DisableInterrupts();
id=func_020056b0();
M2C_FIELD(obj,s32 *,0x70)=priority;
M2C_FIELD(obj,s32 *,0x6c)=id;
M2C_FIELD(obj,s32 *,0x74)=M2C_FIELD(obj,s32 *,0x64)=0;
InsertReadyThread(obj);
M2C_FIELD(obj,u8 **,0x94)=buf;
base=buf-bufLen;
M2C_FIELD(obj,u8 **,0x90)=base;
M2C_FIELD(obj,s32 *,0x98)=0;
*(u32 *)(M2C_FIELD(obj,u8 **,0x94)-4)=0xFDDB597D;
*M2C_FIELD(obj,u32 **,0x90)=0x7BF9DD5B;
M2C_FIELD(obj,s32 *,0x9c)=M2C_FIELD(obj,s32 *,0xa0)=0;
InitThreadContext(obj,callback,buf-4);
M2C_FIELD(obj,s32 *,4)=owner;
M2C_FIELD(obj,void (**)(void),0x3c)=func_02005bbc;
CpuFill(0,base+4,bufLen-8);
M2C_FIELD(obj,s32 *,0x8c)=M2C_FIELD(obj,s32 *,0x88)=M2C_FIELD(obj,s32 *,0x84)=0;
func_02006198(obj,0);
M2C_FIELD(obj,s32 *,0x78)=0;
M2C_FIELD(obj,s32 *,0x80)=0;
M2C_FIELD(obj,s32 *,0x7c)=0;
CpuFill(0,(u8 *)obj+0xa4,12);
M2C_FIELD(obj,s32 *,0xb0)=0;
OS_RestoreInterrupts(state);
}

void func_02005bbc(void) {
    M2C_UNK TaskExit(s32, M2C_UNK);
    extern M2C_UNK gThreadManager;
    OS_DisableInterrupts();
    TaskExit(M2C_FIELD(&gThreadManager, s32 *, 0x28), 0);
}

/* End task `thread` with exit `status`: once the scheduler is up, point the
 * thread's context at TaskExitThread, mark it ready and switch to it so the exit
 * runs on its own stack; before that, run the exit path directly. */
M2C_UNK TaskExit(s32 thread,s32 status){
extern s32 gThreadManager;
void TaskExitThread(s32);
void InitThreadContext();
void SwitchThreadContext(s32);
if(M2C_FIELD(&gThreadManager,s32 *,28)){
InitThreadContext(thread,TaskExitThread);
M2C_FIELD(thread,s32 *,4)=status;
M2C_FIELD(thread,s32 *,0)|=128;
M2C_FIELD(thread,s32 *,0x64)=THREAD_STATE_READY;
SwitchThreadContext(thread);
}else TaskExitThread(status);
}

void TaskExitThread(s32 a){
extern s32 gThreadManager;
void TerminateCurrentThread(void);
void *p=*M2C_FIELD(&gThreadManager,void ***,8);
void (*cb)(s32)=M2C_FIELD(p,void (**)(s32),0xB4);
if(cb){M2C_FIELD(p,void (**)(s32),0xB4)=NULL;cb(a);
OS_DisableInterrupts();}TerminateCurrentThread();
}

/* Terminate the running thread: stop the scheduler, release the mutexes it still
 * holds, unlink it from its wait and ready queues, wake every thread joining it,
 * then let the scheduler run again and halt on the next reschedule. */
void TerminateCurrentThread(void){
extern s32 gThreadManager;
void OS_DisableScheduler(void);
void ReleaseThreadMutexes(void *);
void RemoveReadyThread(void *);
void OS_WakeupThread(void *);
void OS_EnableScheduler(void);
void SystemHalt(void);
void OS_Reschedule(void);
void *thread=*M2C_FIELD(&gThreadManager,void ***,8);
OS_DisableScheduler();ReleaseThreadMutexes(thread);
if(M2C_FIELD(thread,void **,0x78)){UnlinkThreadFromQueue(M2C_FIELD(thread,void **,0x78),thread);}RemoveReadyThread(thread);
M2C_FIELD(thread,s32 *,0x64)=THREAD_STATE_FINISHED;
OS_WakeupThread(thread+THREAD_JOIN_QUEUE);OS_EnableScheduler();OS_Reschedule();SystemHalt();
}

/* Terminate `thread` from outside: if it is the thread that is running, take
 * the halt path instead.  Otherwise stop the scheduler, hand the CPU to another
 * thread, release the mutexes it holds and unlink it from the queue it was
 * sleeping on, cancel the timer that would have woken it, mark it finished and
 * wake every thread that is joining it. */
void TerminateThread(void *thread) {
    void CancelThreadWakeTimer(void *);
    void OS_Reschedule(void);
    extern s32 gThreadManager;
    s32 irqState = OS_DisableInterrupts();
    if (M2C_FIELD(&gThreadManager, void **, THREAD_MANAGER_CURRENT) == thread) TerminateCurrentThread();
    OS_DisableScheduler(); ReleaseThreadMutexes(thread); CancelThreadWakeTimer(thread);
    if (M2C_FIELD(thread, void **, 120)) { UnlinkThreadFromQueue(M2C_FIELD(thread, void **, 120), thread); } RemoveReadyThread(thread);
    M2C_FIELD(thread, s32 *, 100) = 2;
    OS_WakeupThread((u8 *)thread + THREAD_JOIN_QUEUE); OS_EnableScheduler(); OS_RestoreInterrupts(irqState); OS_Reschedule();
}

void CancelThreadWakeTimer(void *arg0) {
    M2C_UNK CancelTimer();
    if (M2C_FIELD(arg0, s32 *, 0xB0) == 0) {
        return;
    }
    CancelTimer();
}

void OS_JoinThread(void *arg0) {
    M2C_UNK OS_SleepThread(void *);
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    if (M2C_FIELD(arg0, s32 *, 0x64) != 2) {
        OS_SleepThread(arg0 + 0x9C);
    }
    OS_RestoreInterrupts(temp_r4);
}

s32 TaskIsFinished(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x64) == 2) {
        return 1;
    }
    return 0;
}

/* Put the running thread to sleep: with interrupts masked, enqueue it on `queue`
 * (or on no queue when it is NULL), mark it waiting and reschedule. */
M2C_UNK OS_SleepThread(void *queue) {
    extern M2C_UNK gThreadManager;
    s32 irq = OS_DisableInterrupts();
    Thread *current = M2C_FIELD(M2C_FIELD(&gThreadManager, void **, THREAD_MANAGER_RUNNING), Thread **, 0);
    if (queue) {
        current->waitQueue = queue;
        OS_EnqueueThread(queue, current);
    }
    current->state = THREAD_STATE_WAITING;
    RescheduleThreads();
    OS_RestoreInterrupts(irq);
}

/* Wake every thread asleep on the queue with interrupts disabled: pop each one,
 * mark it ready and clear its queue links, then reschedule. */
M2C_UNK OS_WakeupThread(void *a) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    void *DequeueThread(void *);
    OSThreadQueue *queue = (OSThreadQueue *)a;
    s32 irq = OS_DisableInterrupts();
    if (queue->head != NULL) {
        while (queue->head != NULL) {
            Thread *thread = (Thread *)DequeueThread(a);
            thread->state = THREAD_STATE_READY;
            thread->waitQueue = NULL;
            thread->queueNext = NULL;
            thread->queuePrev = NULL;
        }
        queue->tail = NULL;
        queue->head = NULL;
        RescheduleThreads();
    }
    OS_RestoreInterrupts(irq);
}

void TaskWake(void *arg0) {
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    M2C_FIELD(arg0, s32 *, 0x64) = 1;
    RescheduleThreads();
    OS_RestoreInterrupts(temp_r4);
}

void *FindNextReadyThread(void) {
extern M2C_UNK gThreadManager;
void *p = M2C_FIELD(&gThreadManager, void **, 0x2c);
while (p && M2C_FIELD(p, s32 *, 0x64) != 1) p = M2C_FIELD(p, void **, 0x68);
return p;
}

void OS_Reschedule(void) {

    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    RescheduleThreads();
    OS_RestoreInterrupts(temp_r4);
}

/* Round-robin between the ready threads of the running thread's priority: the
 * running thread is moved behind the last thread of that priority in the ready
 * list and the scheduler is run again.  Does nothing when it is the only thread
 * at its priority. */
void TaskYield(void) {
    extern M2C_UNK gThreadManager;
    Thread *previous = 0, *lastPeer = 0; s32 peerCount = 0;
    s32 irq;
    Thread *current = M2C_FIELD(&gThreadManager, Thread **, THREAD_MANAGER_CURRENT);
    Thread *thread, *before;
    irq = OS_DisableInterrupts();
    thread = M2C_FIELD(&gThreadManager, Thread **, THREAD_MANAGER_READY); before = 0;
    while (thread) {
        if (thread == current) previous = before;
        if (current->priority == thread->priority) { lastPeer = thread; peerCount++; }
        before = thread; thread = thread->next;
    }
    if (peerCount <= 1 || lastPeer == current) { OS_RestoreInterrupts(irq); return; }
    if (!previous) M2C_FIELD(&gThreadManager, Thread **, THREAD_MANAGER_READY) = current->next;
    else previous->next = current->next;
    current->next = lastPeer->next; lastPeer->next = current;
    RescheduleThreads(); OS_RestoreInterrupts(irq);
}

