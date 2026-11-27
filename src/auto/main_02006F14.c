/* 51 functions from 0x02006F14 to 0x02007EF4 (main), found by ds-decomp. */
#include "common.h"
#include "dma.h"
#include "gx.h"
extern u32 data_0212dfbc[2];

/* The console's user profile, filled by GetSystemUserProfile from the firmware's
 * personal data: language and favourite colour, birthday, nickname and greeting. */
typedef struct SystemUserProfile {
    u8  language;      /* +0x00 firmware settings bits 0..2 */
    u8  favoriteColor; /* +0x01 firmware byte 2, bits 0..3 */
    u8  birthdayMonth; /* +0x02 firmware byte 3 */
    u8  birthdayDay;   /* +0x03 firmware byte 4 */
    u16 name[10];      /* +0x04 nickname, nameLength characters */
    u16 unknown18;     /* +0x18 zeroed */
    u16 nameLength;    /* +0x1A nickname length in characters */
    u16 message[26];   /* +0x1C greeting message, messageLength characters */
    u16 unknown50;     /* +0x50 zeroed */
    u16 messageLength; /* +0x52 greeting length in characters */
} SystemUserProfile;

/* Starts the system tick: TIMER0 is reset and left free-running with its
 * overflow interrupt enabled, whose handler (SystemTickOverflowHandler) extends
 * the 16-bit counter to the 64-bit tick SystemTickState.overflows holds. */
void InitSystemTick(void) {
    void SetSystemTickFlag(s32);
    void OS_SetIrqHandler(u32, void (*)(void));
    void OS_EnableIrqMask(u32);
    void SystemTickOverflowHandler(void);
    extern u16 gSystemTickState;
    if (M2C_FIELD(&gSystemTickState, u16 *, SYSTEM_TICK_INITIALIZED) != 0) return;
    M2C_FIELD(&gSystemTickState, u16 *, SYSTEM_TICK_INITIALIZED) = 1;
    SetSystemTickFlag(0);
    M2C_FIELD(&gSystemTickState, u64 *, SYSTEM_TICK_OVERFLOW) = 0;
    *(volatile u16 *)REG_TM0CNT = 0;
    *(volatile u16 *)REG_TM0D = 0;
    *(volatile u16 *)REG_TM0CNT = 0xC1;
    OS_SetIrqHandler(8, SystemTickOverflowHandler);
    OS_EnableIrqMask(8);
    M2C_FIELD(&gSystemTickState, s32 *, SYSTEM_TICK_RELOAD) = 0;
}

u16 IsSystemTickInitialized(void) {
    extern u16 gSystemTickState;
    return gSystemTickState;
}

#pragma opt_propagation off
void SystemTickOverflowHandler(void) {
void OS_SetTimerHandler(u32,void (*)(void),u32); extern u16 gSystemTickState;
++M2C_FIELD(&gSystemTickState,u64 *,8);
if (M2C_FIELD(&gSystemTickState,s32 *,4)) {
*(volatile u16 *)0x04000102=0;
*(volatile u16 *)0x04000100=0;
*(volatile u16 *)0x04000102=0xc1;
M2C_FIELD(&gSystemTickState,s32 *,4)=0;
}
OS_SetTimerHandler(0,SystemTickOverflowHandler,0);
}
#pragma opt_propagation reset
/* The system tick: TIMER0's free-running 16-bit counter extended to 64 bits by
 * counting its overflows.  The counter is read first, then the overflow count;
 * when TIMER0's overflow interrupt is pending and the counter had not yet
 * wrapped (its top bit is clear), one overflow is added for the wrap that just
 * happened.  Interrupts are held off around the read so the pair stays
 * consistent. */
u64 GetSystemTick(void) {
    u32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(u32);
    extern u16 gSystemTickState;
    volatile u16 counter;
    volatile u64 overflows;
    u32 irq = OS_DisableInterrupts();
    counter = *(volatile u16 *)REG_TM0D;
    overflows = M2C_FIELD(&gSystemTickState, volatile u64 *, SYSTEM_TICK_OVERFLOW) & 0x0000FFFFFFFFFFFFULL;
    if ((*(volatile u32 *)REG_IF & IRQ_TIMER0) && !(counter & TIMER0_HALF)) overflows++;
    OS_RestoreInterrupts(irq);
    return (overflows << 16) | counter;
}

u16 func_020070a4(void) {
    return *(u16 *)0x04000100;
}

#pragma opt_if_conversion off
void ArmTimerCountdown(void *arg0) {
void OS_SetTimerHandler(u32, void (*)(void), u32); s32 func_020073c0(s32); void OS_EnableIrqMask(u32);
u64 now=GetSystemTick(); s64 delta; u16 timer;
*(volatile u16 *)0x04000106=0;
delta=M2C_FIELD(arg0,s64*,0xc)-now;
OS_SetTimerHandler(1,(void(*)(void))func_020073c0,0);
timer=0;
if(delta<0)timer=0xfffe;
else if(delta<0x10000)timer=(u16)~(u32)delta;
*(volatile u16 *)0x04000104=timer;
*(volatile u16 *)0x04000106=0xc1;
OS_EnableIrqMask(0x10);
}
#pragma opt_if_conversion reset
/* Set up the OS timer queue once: mark it ready, enable the TIMER1 interrupt
 * that drives it, clear the head and tail, and leave the TIMER1 IRQ masked
 * until an armed timer re-enables it. */
void InitTimerQueue(void) {
 void SetSystemTickFlag(s32);
 M2C_UNK OS_DisableIrqMask(M2C_UNK);
 extern u16 gTimerQueue;
 if (M2C_FIELD(&gTimerQueue, u16 *, TIMER_QUEUE_READY) != 0) return;
 M2C_FIELD(&gTimerQueue, u16 *, TIMER_QUEUE_READY) = 1;
 SetSystemTickFlag(1);
 M2C_FIELD(&gTimerQueue, s32 *, TIMER_QUEUE_HEAD) = 0;
 M2C_FIELD(&gTimerQueue, s32 *, TIMER_QUEUE_TAIL) = 0;
 OS_DisableIrqMask(IRQ_TIMER1);
}

u16 func_02007180(void) {
    extern u16 gTimerQueue;
    return gTimerQueue;
}

void InitTimer(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

#pragma opt_if-conversion off
/* Insert an OS timer into gTimerQueue, sorted by its u64 deadline: a one-shot
 * timer is due at `due`, a repeating one is advanced from its last fire tick by
 * whole periods until it is due again.  The timer is linked before the first
 * node that is due later, or at the tail, and the hardware countdown is re-armed
 * when it becomes the earliest. */
void InsertTimer(void *timer, u64 due) {
    u64 GetSystemTick(void);
    void ArmTimerCountdown(void *);
    u64 U64Divide(u64, u64);
    extern u16 gTimerQueue;
    u64 now, period, deadline, periods, step;
    u64 nodeDeadline;
    void *node;
    void *next;
    void *oldTail;

    deadline = due;
    if (M2C_FIELD(timer, u64 *, TIMER_NODE_PERIOD) != 0) {
        now = GetSystemTick();
        deadline = M2C_FIELD(timer, u64 *, TIMER_NODE_LAST);
        if (deadline < now) {
            period = M2C_FIELD(timer, u64 *, TIMER_NODE_PERIOD);
            periods = U64Divide(now - deadline, period);
            step = period * (periods + 1);
            deadline += step;
        }
    }
    M2C_FIELD(timer, u64 *, TIMER_NODE_DEADLINE) = deadline;

    for (node = M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_HEAD); node != 0; node = M2C_FIELD(node, void **, TIMER_NODE_NEXT)) {
        nodeDeadline = M2C_FIELD(node, u64 *, TIMER_NODE_DEADLINE);
        if ((s64)(deadline - nodeDeadline) < 0) {
        next = M2C_FIELD(node, void **, TIMER_NODE_PREV);
        M2C_FIELD(timer, void **, TIMER_NODE_PREV) = next;
        M2C_FIELD(node, void **, TIMER_NODE_PREV) = timer;
        M2C_FIELD(timer, void **, TIMER_NODE_NEXT) = node;
        next = M2C_FIELD(timer, void **, TIMER_NODE_PREV);
        if (next != 0) {
            M2C_FIELD(next, void **, TIMER_NODE_NEXT) = timer;
        } else {
            M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_HEAD) = timer;
            ArmTimerCountdown(timer);
        }
        return;
        }
    }
    {
        M2C_FIELD(timer, void **, TIMER_NODE_NEXT) = 0;
        oldTail = M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_TAIL);
        M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_TAIL) = timer;
        M2C_FIELD(timer, void **, TIMER_NODE_PREV) = oldTail;
        if (oldTail != 0) {
            M2C_FIELD(oldTail, void **, TIMER_NODE_NEXT) = timer;
        } else {
            M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_TAIL) = timer;
            M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_HEAD) = timer;
            ArmTimerCountdown(timer);
        }
    }
}
/* Arm an OS timer node and queue it: clear its repeat period (a one-shot), store
 * its callback and argument, then insert it into the deadline-sorted timer queue
 * to fire `delay` ticks from now.  Halts when the node is NULL or already armed. */
void ScheduleTimer(void *node, u64 delay, s32 callback, volatile s32 arg) {
 M2C_UNK SystemHalt(); u32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(u32); void InsertTimer(void *, u64);
 u32 state; u64 time;
 if(node==0 || M2C_FIELD(node,s32 *,TIMER_NODE_CALLBACK)!=0)SystemHalt();
 state=OS_DisableInterrupts();
 M2C_FIELD(node,s32 *,TIMER_NODE_PERIOD)=0;
 M2C_FIELD(node,s32 *,TIMER_NODE_PERIOD+4)=0;
 M2C_FIELD(node,volatile s32 *,TIMER_NODE_CALLBACK)=callback;
 M2C_FIELD(node,s32 *,TIMER_NODE_ARG)=arg;
 time=delay+GetSystemTick();
 InsertTimer(node,time); OS_RestoreInterrupts(state);
}
#pragma opt_common_subs reset
/* Take a timer off the OS timer queue: unlink it from the deadline-sorted list
 * (+0x14 links toward the head, +0x18 toward the tail), re-arm the hardware
 * countdown for the new head, then mark it unscheduled by clearing its callback
 * and repeat period. */
void CancelTimer(void *arg0) {
 u32 OS_DisableInterrupts(void);
 void OS_RestoreInterrupts(u32);
 extern u16 gTimerQueue;
 u32 state;
 void *next;
 void *prev;
 state = OS_DisableInterrupts();
 if (M2C_FIELD(arg0,s32 *,0) == 0) {
 OS_RestoreInterrupts(state);
 return;
 }
 next = M2C_FIELD(arg0,void **,0x18);
 if (next == NULL) {
 M2C_FIELD(&gTimerQueue,void **,8) = M2C_FIELD(arg0,void **,0x14);
 } else {
 M2C_FIELD(next,void **,0x14) = M2C_FIELD(arg0,void **,0x14);
 }
 prev = M2C_FIELD(arg0,void **,0x14);
 if (prev != NULL) M2C_FIELD(prev,void **,0x18) = next;
 else {
 M2C_FIELD(&gTimerQueue,void **,4) = next;
 if (next != NULL) ArmTimerCountdown(next);
 }
 M2C_FIELD(arg0,s32 *,0) = 0;
 M2C_FIELD(arg0,s32 *,0x1C) = 0;
 M2C_FIELD(arg0,s32 *,0x20) = 0;
 OS_RestoreInterrupts(state);
}

#pragma interworking on
s32 func_020073c0(s32 arg0) {
    void TimerInterruptHandler(void);
    TimerInterruptHandler();
    return arg0;
}
#pragma scheduling on
/* TIMER1 interrupt body (reached through func_020073c0).  It stops the
 * countdown, signals the OS timer event and walks the deadline-sorted timer
 * queue from the head: when the earliest timer is not due yet it just re-arms
 * the hardware for it, otherwise it unlinks that timer, runs its callback (a
 * one-shot is marked idle first), re-queues it when it repeats, and finally
 * re-arms the countdown for the new head. */
void TimerInterruptHandler(void) {
    M2C_UNK OS_DisableIrqMask(M2C_UNK);
    u64 GetSystemTick(void);
    void ArmTimerCountdown(void *);
    void InsertTimer(void *, u64);
    extern u16 gTimerQueue;
    extern M2C_UNK gOsArea;

    void *timer;
    void *next;
    u64 now;
    u64 deadline;
    u64 period;
    u32 callback;
    u32 arg;

    *(volatile u16 *)REG_TM1CNT = 0;
    OS_DisableIrqMask(IRQ_TIMER1);
    M2C_FIELD(&gOsArea, u32 *, OS_AREA_EVENT_FLAGS) |= OS_EVENT_TIMER1;

    now = GetSystemTick();

    timer = M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_HEAD);
    if (timer == 0) return;

    deadline = M2C_FIELD(timer, u64 *, TIMER_NODE_DEADLINE);
    if (now < deadline) {
        ArmTimerCountdown(timer);
        return;
    }

    next = M2C_FIELD(timer, void **, TIMER_NODE_NEXT);
    M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_HEAD) = next;
    if (next == 0) {
        M2C_FIELD(&gTimerQueue, u32 *, TIMER_QUEUE_TAIL) = 0;
    } else {
        M2C_FIELD(next, u32 *, TIMER_NODE_PREV) = 0;
    }

    period = M2C_FIELD(timer, u64 *, TIMER_NODE_PERIOD);
    callback = M2C_FIELD(timer, u32 *, TIMER_NODE_CALLBACK);
    if (period == 0) {
        M2C_FIELD(timer, u32 *, TIMER_NODE_CALLBACK) = 0;
    }

    if (callback != 0) {
        arg = M2C_FIELD(timer, u32 *, TIMER_NODE_ARG);
        ((void (*)(u32))callback)(arg);
    }

    period = M2C_FIELD(timer, u64 *, TIMER_NODE_PERIOD);
    if (period != 0) {
        M2C_FIELD(timer, u32 *, TIMER_NODE_CALLBACK) = callback;
        InsertTimer(timer, 0);
    }

    timer = M2C_FIELD(&gTimerQueue, void **, TIMER_QUEUE_HEAD);
    if (timer != 0) {
        ArmTimerCountdown(timer);
    }
}
#pragma scheduling reset

/* One-time setup of the VCount (scanline match) interrupt module: mark it
 * initialised, clear its state block and leave the VCount interrupt masked. */
void InitVCountIrqModule(void) {
    M2C_UNK OS_DisableIrqMask(M2C_UNK);
    extern VCountIrqState gVCountIrqState;
    if (gVCountIrqState.initialized != 0) {
        return;
    }
    gVCountIrqState.initialized = 1;
    gVCountIrqState.unknown0C = 0;
    gVCountIrqState.unknown10 = 0;
    OS_DisableIrqMask(IRQ_VCOUNT);
    gVCountIrqState.unknown08 = 0;
    gVCountIrqState.unknown04 = 0;
}

s32 func_02007508(void) {
    M2C_ERROR(/* unknown instruction: msr cpsr_c, $r1 */);
    return M2C_ERROR(/* unknown instruction: mrs $r0, cpsr */) & 0x80;
}

extern void func_00000678(unsigned int);
void WaitCycles(unsigned int value)
{
    if (value >= 4)
        return func_00000678(value - 4);
}

/* Busy-wait one iteration, then block until the next VBlank interrupt. */
void WaitForVBlank(void) {
    M2C_UNK WaitByLoop(M2C_UNK);
    M2C_UNK OS_WaitIrq(M2C_UNK, M2C_UNK);

    WaitByLoop(1);
    OS_WaitIrq(1, OS_EVENT_VBLANK);
}

/* Install the ARM7 boot handshake once: initialise PXI, wait for FIFO channel 12
 * to be free and register Arm7BootAckHandler on it.  The ARM7's boot-ready reply
 * then sets ARM7_BOOT_SYNC_READY, which the console-reboot path waits on. */
void InitArm7BootSync(void) {
    M2C_UNK PXI_Init();
    M2C_UNK SetFifoMessageHandler(M2C_UNK, M2C_UNK *);
    s32 IsFifoMessageReady(M2C_UNK, M2C_UNK);
    extern M2C_UNK gArm7BootSync;
    extern M2C_UNK Arm7BootAckHandler;

    if (M2C_FIELD(&gArm7BootSync, u16 *, ARM7_BOOT_SYNC_INITIALISED) != 0) {
        return;
    }
    M2C_FIELD(&gArm7BootSync, u16 *, ARM7_BOOT_SYNC_INITIALISED) = 1U;
    PXI_Init();
    do {

    } while (IsFifoMessageReady(0xC, 1) == 0);
    SetFifoMessageHandler(0xC, &Arm7BootAckHandler);
}

/* FIFO channel-12 handler: the ARM7's boot-ready reply (command ARM7_BOOT_SYNC_REPLY)
 * sets ARM7_BOOT_SYNC_READY; any other message halts the console. */
void Arm7BootAckHandler(s32 tag,s32 message) {
M2C_UNK SystemHalt();
extern M2C_UNK gArm7BootSync;
if(((u32)((message&0x7F00)<<8)>>16)==ARM7_BOOT_SYNC_REPLY) {M2C_FIELD(&gArm7BootSync,s16 *,ARM7_BOOT_SYNC_READY)=1;return;}
SystemHalt();
}

/* Post `command` to the ARM7 boot-sync FIFO, its command bits 8..14, retrying
 * until the IPC queue accepts the message; the console reboot path sends one. */
void Arm7BootSync_SendCommand(s32 command) {
    s32 SendFifoMessage(M2C_UNK, s32, M2C_UNK);
    do {

    } while (SendFifoMessage(ARM7_BOOT_SYNC_FIFO_TAG, command << 8, 0) != 0);
}

void ResetSystem(s32 arg0) {
    M2C_UNK RebootFromCardImage();
    void OS_SetIrqEnableMask(s32);
    void OS_SetIrqMask(s32);
    s32 OS_GetLockID(void);
    void Arm7BootSync_SendCommand(s32);
    M2C_UNK SystemHalt();
    void DmaStopChannel(s32);
    u16 CARD_LockRom(u16);

    s32 isMultiboot = *(u16 *)0x027FFC40 == 2;
    if (isMultiboot) {
        s32 lockId;
        SystemHalt();
        lockId = OS_GetLockID();
        CARD_LockRom((u16)lockId);
        DmaStopChannel(0);
        DmaStopChannel(1);
        DmaStopChannel(2);
        DmaStopChannel(3);
        OS_SetIrqEnableMask(0x40000);
        OS_SetIrqMask(0xFFFFFFFF);
    }
    *(s32 *)0x027FFC20 = arg0;
    Arm7BootSync_SendCommand(0x10);
    RebootFromCardImage();
}

/* Copy the console's six-byte MAC address from the shared work area to `mac`. */
void GetMacAddress(u8 *mac) {
    M2C_UNK MI_CpuCopy8(s32, M2C_UNK, M2C_UNK);

    MI_CpuCopy8(SHARED_MAC_ADDRESS, mac, 6);
}

/* Copy the DS firmware's user settings into the game's user profile record:
 * language, favourite colour and birthday, then the nickname and personal
 * message texts with their lengths. */
void GetSystemUserProfile(UserProfile *profile) {
    void CopyU16(void *, void *, u32);
    FirmwareUserSettings *firmware = (FirmwareUserSettings *)0x027FFC80;
    profile->language = (u32)(firmware->flags << 29) >> 29;
    profile->favoriteColor = (u32)(firmware->favoriteColor << 28) >> 28;
    profile->birthMonth = firmware->birthMonth;
    profile->birthDay = firmware->birthDay;
    profile->nameLength = firmware->nameLength;
    profile->messageLength = firmware->messageLength;
    CopyU16(firmware->name, profile->name, 20);
    CopyU16(firmware->message, profile->message, 52);
    profile->pad18 = 0;
    profile->pad50 = 0;
}

#pragma intrinsic on
s32 func_020077c4(u32 arg0) {
    return __CLZ(arg0);
}
/* Forget the owner of every VRAM bank and clear the owned-bank mask, so all
 * nine banks count as free again. */
void GX_ResetBankOwners(void) {
    s32 bank = 0;
    gVramBankOwnerMask = 0;
    do {
        gVramBankOwners[bank] = 0;
        bank++;
    } while (bank < VRAM_BANK_COUNT);
}

/* Give back the banks selected in `banks` that are owned by `owner`: each one
 * loses its owner and drops out of the owned-bank mask.  The owner tables are
 * shared with the interrupt handlers, so they change with interrupts off. */
void GX_ReleaseBanksByOwner(s32 banks,s32 owner) {
 u32 OS_DisableInterrupts(void);
 void OS_RestoreInterrupts(u32);
 s32 func_020077c4(u32);
 s32 remaining;
 u32 state;
 s32 index,mask;
 state=OS_DisableInterrupts();
 remaining=banks & gVramBankOwnerMask & VRAM_BANK_MASK;

 loop:
 index=31-func_020077c4(remaining); /* highest remaining bank bit, -1 when none */
 if(index>=0) {
 mask=~(1<<index);
 remaining &= mask;
 if(owner==gVramBankOwners[index]) {gVramBankOwners[index]=0; gVramBankOwnerMask &= mask;}
 goto loop;
 }
 OS_RestoreInterrupts(state);
}

void GetConsoleEntropy(void *out_arg) {

    u8 *base;
    u32 *out;
    u16 t0;
    u64 tick;
    u16 mix;
    u8 *r;
    u32 tmp;
    u16 a, b, c, d, e;
    u8 *last;
    volatile u32 *gfxStatus = (volatile u32 *)0x04000600;

    base = (u8 *)0x027FFC00;
    t0 = *(u16 *)0x04000006;
    out = (u32 *)out_arg;

    tmp = func_020070a4();
    tmp |= (u32)t0 << 16;
    out[0] = tmp;

    mix = *(u16 *)(base + 0xF8);
    tick = *(volatile u64 *)data_0212dfbc;
    out[1] = ((u32)mix << 16) ^ (u32)tick;

    tmp = *(u32 *)(base + 0x3C) ^ ((u32)(*(volatile u64 *)data_0212dfbc >> 32) ^ *(u32 *)(base + 0xF4));
    out[2] = tmp;
    out[2] = out[2] ^ *gfxStatus;

    out[3] = *(u32 *)(base + 0x1E8);

    r = base + 0x300;
    out[4] = *(u32 *)(base + 0x1EC);
    tmp = *(u32 *)(base + 0x390);
    mix = *(u16 *)(r + 0x94);
    last = base + 0x3A8;
    out[5] = tmp ^ ((u32)mix << 16);

    a = *(u16 *)(r + 0xAA);
    b = *(u16 *)(r + 0xAC);
    out[6] = ((u32)a << 16) | (u32)b;

    c = *(volatile u16 *)((u8 *)0x04000600 - 0x4D0);
    d = *(u16 *)last;
    e = *(u16 *)(r + 0x98);
    out[7] = (u32)c | (u32)d | ((u32)e << 16);
}

s32 SystemHalt(void) {
 u32 OS_DisableInterrupts(void); void func_02007968(void);
 for (;;) { OS_DisableInterrupts(); func_02007968(); }
}

void SetWramControl(s8 arg0) {
    *(s8 *)0x04000247 = arg0;
}

/* Fills `size` bytes at `dst` with the 32-bit `value` on DMA channel `channel`,
 * waiting for the channel before and after the transfer. */
void DmaFill(s32 channel, s32 dst, u32 value, u32 size) {
    u32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(u32); void DmaStartTransferFlushed(s32,u32,s32,u32);
    volatile u32 *control; u32 state;
    if (!size) return;
    control = (volatile u32 *)DMA_CHANNEL_CTRL(channel);
    while (*control & DMA_CTRL_ENABLE) {}
    state = OS_DisableInterrupts();
    *(volatile u32 *)DMA_FILL_REG(channel) = value;
    DmaStartTransferFlushed(channel, DMA_FILL_REG(channel), dst, DMA_FILL_CTRL(size));
    OS_RestoreInterrupts(state);
    while (*control & DMA_CTRL_ENABLE) {}
}

/* 32-bit DMA copy of `size` bytes from `src` to `dst` on `channel`: validate the
 * range, wait for the channel, start the transfer, then wait for it to finish. */
void DmaCopy(s32 channel, s32 src, s32 dst, u32 size) {
    void DmaStartTransferLockedFlushed(s32, s32, s32, u32);
    void DmaValidateTransfer(s32, s32, s32, s32);
    volatile u32 *control;

    DmaValidateTransfer(channel, src, size, 0);
    if (!size) return;
    control = (volatile u32 *)DMA_CHANNEL_CTRL(channel);
    while (*control & DMA_CTRL_ENABLE) {}
    DmaStartTransferLockedFlushed(channel, src, dst, DMA_COPY_CTRL(size));
    while (*control & DMA_CTRL_ENABLE) {}
}

/* 16-bit DMA copy of `size` bytes from `src` to `dst` on `channel`: validate the
 * range, wait for the channel, start the transfer, then wait for it to finish. */
void DmaCopy16(s32 channel, s32 src, s32 dst, u32 size) {
    void DmaStartTransferLockedFlushed(s32, s32, s32, u32);
    void DmaValidateTransfer(s32, s32, s32, s32);
    volatile u32 *control;

    if (!size) return;
    DmaValidateTransfer(channel, src, size, 0);
    control = (volatile u32 *)DMA_CHANNEL_CTRL(channel);
    while (*control & DMA_CTRL_ENABLE) {}
    DmaStartTransferLockedFlushed(channel, src, dst, DMA_COPY16_CTRL(size));
    while (*control & DMA_CTRL_ENABLE) {}
}

/* Starts a fill of `size` bytes at `dst` with the 32-bit value `fillValue` on DMA
 * channel `channel`.  With a completion handler the fill runs asynchronously: the
 * handler is installed for the channel's interrupt and called with `handlerArg`
 * when the transfer ends (immediately, if there is nothing to fill). */
void DmaFillAsync(s32 channel, M2C_UNK dst, s32 fillValue, u32 size, void (*handler)(s32), s32 handlerArg) {
    void DmaWaitChannel(s32);
    void OS_SetDmaHandler(s32, s32, s32);
    u32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(u32);
    void DmaStartTransfer(s32, s32, M2C_UNK, s32);
    u32 state;

    if (size == 0) {
        if (handler == 0) {
            return;
        }
        handler(handlerArg);
        return;
    }
    DmaWaitChannel(channel);
    if (handler != 0) {
        OS_SetDmaHandler(channel, (s32)handler, handlerArg);
        state = OS_DisableInterrupts();
        *(volatile u32 *) DMA_FILL_REG(channel) = fillValue;
        DmaStartTransfer(channel, DMA_FILL_REG(channel), dst, DMA_FILL_CTRL_IRQ(size));
        OS_RestoreInterrupts(state);
        return;
    }
    state = OS_DisableInterrupts();
    *(volatile u32 *) DMA_FILL_REG(channel) = fillValue;
    DmaStartTransfer(channel, DMA_FILL_REG(channel), dst, DMA_FILL_CTRL(size));
    OS_RestoreInterrupts(state);
}

/* Start an async 32-bit DMA copy of `size` bytes from `src` to `dst` on DMA
 * channel `channel`: with a completion handler the copy runs with the channel's
 * end-of-transfer interrupt enabled and the handler is called with `handlerArg`
 * when it finishes (right away when there is nothing to copy); without one the
 * copy runs without an interrupt.  The counterpart of DmaFillAsync. */
void DmaCopyAsync(s32 channel, s32 src, s32 dst, u32 size, void (*handler)(s32), s32 handlerArg) {
    void DmaValidateTransfer(s32, s32, s32, s32);
    void DmaWaitChannel(s32);
    void OS_SetDmaHandler(s32, s32, s32);
    void DmaStartTransferLocked(s32, s32, s32, s32);
    DmaValidateTransfer(channel, src, size, 0);
    if (size == 0) {
        if (handler != 0) {
            handler(handlerArg);
        }
        return;
    }
    DmaWaitChannel(channel);
    if (handler != 0) {
        OS_SetDmaHandler(channel, (s32)handler, handlerArg);
        DmaStartTransferLocked(channel, src, dst, DMA_COPY_CTRL_IRQ(size));
        return;
    }
    DmaStartTransferLocked(channel, src, dst, DMA_COPY_CTRL(size));
}

/* Waits for DMA channel `channel` to finish (its control word's enable bit to
 * clear), then, for channel 0, resets its source, destination and control
 * registers to the idle one-word transfer.  Interrupts are held off throughout. */
void DmaWaitChannel(s32 channel) {
    u32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(u32);
    u32 state = OS_DisableInterrupts();
    while (*(volatile u32 *)DMA_CHANNEL_CTRL(channel) & DMA_CTRL_ENABLE) {}
    if (channel == 0) {
        volatile u32 *regs = (volatile u32 *)DMA_CHANNEL_BASE(channel);
        regs[0] = 0;
        regs[1] = 0;
        regs[2] = DMA_CTRL_IDLE_CH0;
    }
    OS_RestoreInterrupts(state);
}

/* Stops DMA channel `channel`: with interrupts held off, clears the transfer-mode
 * and enable bits of the channel's control word (reading it back twice to let the
 * writes settle) and, for channel 0, resets its source, destination and control
 * registers to a one-word 32-bit transfer. */
void DmaStopChannel(s32 channel) {
    u32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(u32);
    u32 state = OS_DisableInterrupts();
    volatile u16 *control = (volatile u16 *)DMA_CHANNEL_CTRL_HI(channel);
    *control = *control & ~DMA_CTRL_HI_MODE;
    *control = *control & ~DMA_CTRL_HI_ENABLE;
    (void)(*control);
    (void)(*control);
    if (channel == 0) {
        volatile u32 *regs = (volatile u32 *)DMA_CHANNEL_BASE(channel);
        regs[0] = 0;
        regs[1] = 0;
        regs[2] = 0x81400001;
    }
    OS_RestoreInterrupts(state);
}

/* Halt the console unless the other enabled DMA channels can share the transfer
 * mode `mode` being set on `channel`.  The two bit-27/bit-28 modes 0x08000000 and
 * 0x10000000 may be paired with each other; an enabled channel in any of the other
 * known modes (0x18000000 up to 0x38000000) is a conflict. */
void DmaCheckChannelConflict(s32 channel, s32 mode) {
    M2C_UNK SystemHalt();
    s32 i;
    s32 *channelCtrl;
    s32 ctrl;
    s32 otherMode;
    i = 0;
    channelCtrl = (s32 *)0x040000B8;
    do {
        if (i != channel) {
            ctrl = *channelCtrl;
            if ((ctrl & DMA_CTRL_ENABLE) && (otherMode = ctrl & DMA_CTRL_MODE, (otherMode != mode))) {
                if ((otherMode == 0x08000000) && (mode == 0x10000000)) {

                } else if ((otherMode == 0x10000000) && (mode == 0x08000000)) {

                } else if ((otherMode != 0x18000000) && (otherMode != 0x20000000) && (otherMode != 0x28000000) && (otherMode != 0x30000000) && (otherMode != 0x38000000) && (otherMode != 0x08000000) && (otherMode != 0x10000000)) {

                } else {
                    SystemHalt();
                }
            }
        }
        ++i;
        channelCtrl += 0xC / sizeof(s32);
    } while (i < 3);
}

/* Debug check for a channel-0 DMA: the source range [src, src +/= size] must lie
 * in the ARM9's DMA space (not the IO block and below DMA_REGION_LIMIT); halt the
 * console otherwise.  `srcControl` is the channel's source-address control bit. */
void DmaValidateTransfer(s32 channel, s32 src, s32 size, s32 srcControl) {
    M2C_UNK SystemHalt();
    s32 rangeEnd;
    u32 srcRegion;
    u32 endRegion;

    rangeEnd = src;
    if (channel != 0) {
        return;
    }
    srcRegion = rangeEnd & DMA_ADDR_REGION_MASK;
    switch (srcControl) {
    case DMA_SRC_DECREMENT:
        rangeEnd -= size;
        break;
    case 0x0:
        rangeEnd += size;
        break;
    }
    endRegion = rangeEnd & DMA_ADDR_REGION_MASK;
    if ((srcRegion != DMA_REGION_IO) && (srcRegion < DMA_REGION_LIMIT) && (endRegion != DMA_REGION_IO) && (endRegion < DMA_REGION_LIMIT)) {
        return;
    }
    SystemHalt();
}

void CpuFill(u32 value, s32 dest, s32 size) {
 s32 end = dest + size;
 while (dest < end) { *(u32 *)dest = value; dest += 4; }
}

