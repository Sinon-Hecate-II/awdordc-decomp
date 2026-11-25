/* 28 functions from 0x0200FC58 to 0x02010C14 (main), found by ds-decomp. */
#include "common.h"

static inline s32 SaveDevice_IsMultiboot(void)
{
    return *(volatile u16 *)0x027FFC40 == 2;
}


#pragma optimization_level 2
void func_0200fc58(void) {
    extern void *gSaveDeviceState;
    extern void *data_0212fd80;
    extern u32 data_02130400[];
    void MI_CpuFill32(M2C_UNK, M2C_UNK, M2C_UNK);
    void DC_FlushRange(void *, u32);
    void MI_CpuCopy8(void *, void *, u32);
    void TaskCreate(void *, void *, s32, u8 *, u32, s32);
    void TaskWake(void *);
    void SetFifoMessageHandler(s32, void *);
    void func_0200fd90(s32);
    void SaveDevice_ThreadMain(void);
    void func_02010c90(s32, s32, s32);

    volatile u8 *base = (volatile u8 *) &gSaveDeviceState;
    void *buffer = &data_0212fd80;

    *(volatile s32 *)(base + 8) = -3;
    *(volatile s32 *)(base + 0xC) = 0;
    *(volatile s32 *)(base + 0x18) = 0;
    *(void *volatile *)(base + 0x0) = buffer;

    MI_CpuFill32(0, buffer, 0x60);
    DC_FlushRange(&data_0212fd80, 0x60);

    *(volatile s32 *)(base + 0x118) = -1;
    *(volatile s32 *)(base + 0x11C) = -1;

    if (!SaveDevice_IsMultiboot()) {
        MI_CpuCopy8((void *)0x27ffe00, (void *)((u8 *)0x27ffe00 - 0x380), 0x160);
    }
    {
        s32 zero = 0;
        *(volatile s32 *)(base + 0x108) = 4;
        *(volatile s32 *)(base + 0x14) = zero;
        *(volatile s32 *)(base + 0x10) = zero;
        *(volatile s32 *)(base + 0x110) = zero;
        *(volatile s32 *)(base + 0x10C) = zero;
        TaskCreate(base + 0x44, (void *)SaveDevice_ThreadMain, 0,
                      (u8 *)data_02130400, 0x400,
                      *(volatile s32 *)(base + 0x108));
        TaskWake(base + 0x44);
    }

    SetFifoMessageHandler(0xB, (void *)func_02010c90);

    if (SaveDevice_IsMultiboot()) {
        return;
    }
    func_0200fd90(1);
}
#pragma optimization_level reset
s32 func_0200fd68(void) {
    extern s32 data_0212fd60;
    return data_0212fd60;
}

void func_0200fd78(void) {
    M2C_UNK SystemHalt();
    if (func_0200fd68() != 0) {
        return;
    }
    SystemHalt();
}

void func_0200fd90(s32 arg0) {
    extern s32 data_0212fd60;
    data_0212fd60 = arg0;
}

#pragma optimization_level 2
/* Waits for the running backup transfer: sleeps on the device's thread queue
 * while the busy flag is set, then reports whether the ARM7 answered successfully
 * (the response's first word is 0). */
s32 SaveDevice_WaitForTransfer(void) {
    extern void *gSaveDeviceState;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_SleepThread(void *);
    void *device = &gSaveDeviceState;
    s32 state = OS_DisableInterrupts();

    while (M2C_FIELD(device, volatile u32 *, SAVE_DEVICE_FLAGS) & SAVE_DEVICE_FLAG_BUSY) {
        OS_SleepThread((u8 *)device + SAVE_DEVICE_THREAD_QUEUE);
    }
    OS_RestoreInterrupts(state);
    return *M2C_FIELD(device, s32 **, SAVE_DEVICE_RESPONSE) == 0;
}
#pragma optimization_level reset
s32 func_0200fdec(void) {
 extern void *gSaveDeviceState;
 return (M2C_FIELD(&gSaveDeviceState, u32 *, 0x114) & 4) == 0;
}

s32 SaveDevice_IsReady(void) {
 extern void *gSaveDeviceState;
 return M2C_FIELD(&gSaveDeviceState,u32 *,0x114) != 0;
}

void CARD_LockRom(M2C_UNK arg0) {
    M2C_UNK func_0200551c(M2C_UNK);
    func_0200fb48(arg0, 1);
    func_0200551c(arg0);
}

void CARD_UnlockRom(M2C_UNK arg0) {
    M2C_UNK func_02005538();
    M2C_UNK func_0200fbcc(M2C_UNK, M2C_UNK);
    func_02005538();
    func_0200fbcc(arg0, 1);
}

void CARD_LockBackup(M2C_UNK arg0) {
    M2C_UNK func_0200fb48(M2C_UNK, M2C_UNK);
    func_0200fb48(arg0, 2);
}

void CARD_UnlockBackup(M2C_UNK arg0) {
 s32 func_02010590(void); void func_02010584(void);
 M2C_UNK func_0200fbcc(M2C_UNK, M2C_UNK);
 if (func_02010590() == 0) { func_02010584(); }
 func_0200fbcc(arg0, 2);
}

#pragma opt_common_subs off
void func_0200fe94(s32 value){
extern void *gSaveDeviceState;void MI_CpuFill8(void *,s32,s32);
u8 *p=gSaveDeviceState;u32 bit; s32 kind;
MI_CpuFill8(p+0x18,0,0x48);
M2C_FIELD(p,s32 *,4)=value;M2C_FIELD(p,u32 *,0x4c)=0x3f;
if(value==0)return;
bit=1<<((value>>8)&255);kind=value&255;
M2C_FIELD(p,u32 *,0x18)=bit;p[0x48]=255;
if(kind==1){
switch(bit){
case 0x200:M2C_FIELD(p,s32 *,0x20)=16;M2C_FIELD(p,s32 *,0x24)=1;M2C_FIELD(p,s32 *,0x28)=5;p[0x48]=240;break;
case 0x2000:M2C_FIELD(p,s32 *,0x20)=32;M2C_FIELD(p,s32 *,0x24)=2;M2C_FIELD(p,s32 *,0x28)=5;p[0x48]=0;break;
case 0x10000:M2C_FIELD(p,s32 *,0x20)=128;M2C_FIELD(p,s32 *,0x24)=2;M2C_FIELD(p,s32 *,0x28)=10;p[0x48]=0;break;
default:goto fail;}
M2C_FIELD(p,s32 *,0x1c)=M2C_FIELD(p,s32 *,0x20);M2C_FIELD(p,u32 *,0x4c)|=0x340;return;
}else if(kind==2){
switch(bit){
case 0x40000:case 0x80000:case 0x100000:
M2C_FIELD(p,s32 *,0x2c)=25;M2C_FIELD(p,s32 *,0x30)=300;M2C_FIELD(p,s32 *,0x44)=300;M2C_FIELD(p,s32 *,0x3c)=5000;M2C_FIELD(p,u32 *,0x4c)|=0x480;break;
case 0x200000:
M2C_FIELD(p,s32 *,0x2c)=23;M2C_FIELD(p,s32 *,0x30)=300;{s32 delay=500;M2C_FIELD(p,s32 *,0x3c)=delay;}M2C_FIELD(p,s32 *,0x34)=(M2C_FIELD(p,s32 *,0x40)=5000)*2;M2C_FIELD(p,s32 *,0x38)=60000;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x1480;break;
case 0x400000:
M2C_FIELD(p,s32 *,0x3c)=600;M2C_FIELD(p,s32 *,0x40)=3000;M2C_FIELD(p,s32 *,0x34)=23000;M2C_FIELD(p,s32 *,0x38)=800000;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x1000;break;
case 0x800000:
M2C_FIELD(p,s32 *,0x3c)=1000;M2C_FIELD(p,s32 *,0x40)=3000;M2C_FIELD(p,s32 *,0x34)=68000;M2C_FIELD(p,s32 *,0x38)=160000;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x1000;break;
default:goto fail;
}
M2C_FIELD(p,s32 *,0x1c)=0x10000;M2C_FIELD(p,s32 *,0x20)=256;M2C_FIELD(p,s32 *,0x24)=3;M2C_FIELD(p,s32 *,0x28)=5;M2C_FIELD(p,u32 *,0x4c)|=0xb40;return;
}else if(kind==3){if(bit==0x2000||bit==0x8000){M2C_FIELD(p,u32 *,0x20)=bit;M2C_FIELD(p,u32 *,0x1c)=bit;M2C_FIELD(p,s32 *,0x24)=2;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x340;return;}}
fail:M2C_FIELD(p,s32 *,0x18)=M2C_FIELD(p,s32 *,4)=0;M2C_FIELD(gSaveDeviceState,s32 *,0)=3;
}
#pragma push
#pragma optimization_level 3
/* Task body of the chunked memory transfer: moves the task's remaining bytes between its source
 * and destination in chunks (through a bounce buffer for reads), then wakes the waiting thread
 * and calls the completion callback. */
void RunTransferTask(void *arg0) {
    void func_02000b9c(s32);
    void OS_WakeupThread(void *);
    void DC_InvalidateRange(void *, s32);
    void TaskWake(void *);
    void DC_FlushRange(void *, u32);
    void DC_Sync();
    s32 OS_DisableInterrupts();
    void OS_RestoreInterrupts(s32);
    void MI_CpuCopy8(void *, void *, u32);
    s32 func_02010438(void);
    void func_02010d14(void *, s32, s32);
    register u32 irq;
    s32 callbackArg;
    M2C_UNK (*callback)(s32);
    register u32 mode, chunk;
    register void *buffer;
    register s32 type;
    register u32 count;
    register s32 retries;

    u32 left;


    type = M2C_FIELD(arg0, s32 *, 0x2C);
    mode = M2C_FIELD(arg0, u32 *, 0x34);
    retries = M2C_FIELD(arg0, s32 *, 0x30);
    chunk = 0x100;
    func_02000b9c(0x02000BC4);
    if (type == 0xB) {
        chunk = func_02010438();
    }
    buffer = arg0 + 0x120;
loop_3:
    count = M2C_FIELD(arg0, volatile u32 *, 0x24);
    if (chunk < count) {
        count = chunk;
    }
    M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), u32 *, 0x14) = count;
    if (M2C_FIELD(arg0, volatile s32 *, 0x114) & 0x40) {
        M2C_FIELD(arg0, volatile s32 *, 0x114) &= ~0x40;
        M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), s32 *, 0) = 7;
        goto done;
    }
    {
        switch (mode) {
        default:
            break;
        case 0:
            DC_InvalidateRange(buffer, count);
            M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), void **, 0xC) = (void *) M2C_FIELD((u32)arg0, void **, 0x1C);
            M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), void **, 0x10) = buffer;
            break;
        case 1:
        case 2:
            MI_CpuCopy8(M2C_FIELD(arg0, void **, 0x1C), buffer, count);
            DC_FlushRange(buffer, count);
            DC_Sync();
            M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), void **, 0xC) = buffer;
            M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), void **, 0x10) = (void *) M2C_FIELD(arg0, void *volatile *, 0x20);
            break;
        case 3:
            M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), void **, 0xC) = (void *) M2C_FIELD(arg0, void **, 0x1C);
            M2C_FIELD(M2C_FIELD(arg0, void *volatile *, 0), void **, 0x10) = (void *) M2C_FIELD(arg0, void **, 0x20);
            break;
        }
        if (!((s32 (*)(void *, s32, s32))func_02010d14)(arg0, type, retries)) goto done;
        if (mode == 2) {
            if (!((s32 (*)(void *, s32, s32))func_02010d14)(arg0, 9, 1)) goto done;
        } else if (mode == 0) {
            MI_CpuCopy8(buffer, M2C_FIELD(arg0, void **, 0x20), count);
        }
        M2C_FIELD(arg0, void *volatile *, 0x1C) = (u8 *)M2C_FIELD(arg0, void *volatile *, 0x1C) + count;
        M2C_FIELD(arg0, void *volatile *, 0x20) = (u8 *)M2C_FIELD(arg0, void *volatile *, 0x20) + count;
        left = M2C_FIELD(arg0, volatile u32 *, 0x24) - count;
        M2C_FIELD(arg0, volatile u32 *, 0x24) = left;
        if (left) goto loop_3;
    }
done:
    callback = M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x38);
    callbackArg = M2C_FIELD(arg0, s32 *, 0x3C);
    irq = OS_DisableInterrupts();
    M2C_FIELD(arg0, s32 *, 0x114) = (s32) (M2C_FIELD(arg0, s32 *, 0x114) & ~0x4C);
    OS_WakeupThread(arg0 + 0x10C);
    if (M2C_FIELD(arg0, s32 *, 0x114) & 0x10) {
        TaskWake(arg0 + 0x44);
    }
    OS_RestoreInterrupts(irq);
    if (callback == NULL) {
        return;
    }
    callback(callbackArg);
}
#pragma pop
s32 SaveDevice_Transfer(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    extern void *gSaveDeviceState;
    extern M2C_UNK gSocketManager;
    void func_02000b9c(s32);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_SleepThread(void *);
    void func_0200fb0c(void *);
    void RunTransferTask(void *);
    void *p = &gSaveDeviceState;
    s32 state;
    s32 a6, a7, a8, a5;

    func_02000b9c(0x2000bc4);
    state = OS_DisableInterrupts();
    while (M2C_FIELD(p, u32 *, 0x114) & 0x4) {
        OS_SleepThread((u8 *)p + 0x10c);
    }
    M2C_FIELD(p, u32 *, 0x114) |= 4;
    M2C_FIELD(p, s32 *, 0x38) = arg3;
    M2C_FIELD(p, s32 *, 0x3c) = arg4;
    OS_RestoreInterrupts(state);
    a6 = arg6;
    a7 = arg7;
    a8 = arg8;
    a5 = arg5;
    M2C_FIELD(p, s32 *, 0x1c) = arg0;
    M2C_FIELD(p, s32 *, 0x20) = arg1;
    M2C_FIELD(p, s32 *, 0x24) = arg2;
    M2C_FIELD(p, s32 *, 0x2c) = a6;
    M2C_FIELD(p, s32 *, 0x30) = a7;
    M2C_FIELD(p, s32 *, 0x34) = a8;
    if (a5 != 0) {
        func_0200fb0c((void *)RunTransferTask);
        return 1;
    }
    M2C_FIELD(&gSaveDeviceState, u32 *, 0x104) = M2C_FIELD(&gSocketManager, u32 *, 0x4);
    RunTransferTask(p);
    return *M2C_FIELD(p, s32 **, 0) == 0;
}
#pragma scheduling reset
s32 SaveDevice_GetState(void) {
    extern void *gSaveDeviceState;
    return M2C_FIELD(gSaveDeviceState, s32 *, 4);
}

s32 func_02010438(void) {
    extern void *gSaveDeviceState;
    return M2C_FIELD(gSaveDeviceState, s32 *, 0x1C);
}

#pragma opt_common_subs off
#pragma opt_copy_propagation off
s32 SaveDevice_Configure(s32 arg0) {
extern void *gSaveDeviceState;extern M2C_UNK gSocketManager;
void func_02000b9c(s32);s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void OS_SleepThread(void *);void OS_WakeupThread(void *);void TaskWake(void *);void func_0200fe94(s32);void func_02010d14(void *,s32,s32);M2C_UNK SystemHalt();
void *p=&gSaveDeviceState; u32 state,state2;s32 value;void (*callback)(s32);
func_02000b9c(0x2000bc4);
if(arg0==0)SystemHalt();
func_0200fd78();
state=OS_DisableInterrupts();
while(M2C_FIELD(p,u32 *,0x114)&4)OS_SleepThread(p+0x10c);
{
    u32 flags=M2C_FIELD(p,u32 *,0x114);
    M2C_FIELD(p,u32 *,0x114)=4 | flags;
    M2C_FIELD(p,s32 *,0x38)=0;
    M2C_FIELD(p,s32 *,0x3c)=0;
}
OS_RestoreInterrupts(state);
func_0200fe94(arg0);
M2C_FIELD(&gSaveDeviceState,s32 *,0x104)=M2C_FIELD(&gSocketManager,s32 *,4);
func_02010d14(p,2,1);
M2C_FIELD(*(void **)p,s32 *,0xc)=0;
M2C_FIELD(*(void **)p,void **,0x10)=p+0x120;
M2C_FIELD(*(void **)p,s32 *,0x14)=1;
func_02010d14(p,6,1);
callback=M2C_FIELD(p,void (**)(s32),0x38);value=M2C_FIELD(p,s32 *,0x3c);
state2=OS_DisableInterrupts();
M2C_FIELD(p,u32 *,0x114)&=~0x4c;
OS_WakeupThread(p+0x10c);
if(M2C_FIELD(p,u32 *,0x114)&0x10)TaskWake(p+0x44);
OS_RestoreInterrupts(state2);
if(callback)callback(value);
return **(s32 **)p==0;
}
#pragma opt_copy_propagation reset
#pragma opt_common_subs reset
void func_02010584(void) {
    M2C_UNK SaveDevice_WaitForTransfer();
    SaveDevice_WaitForTransfer();
}

s32 func_02010590(void) {
    M2C_UNK func_0200fdec();
    return func_0200fdec();
}

#pragma optimization_level 3
s32 SaveDevice_TransferChunk(void *arg0){
extern void *gSaveDeviceState; void MI_CpuCopy8(void *,void *,u32);
void *p=&gSaveDeviceState; u32 base=M2C_FIELD(p,volatile u32*,0x1c)&~0x1ff;
if(base==M2C_FIELD(arg0,u32*,8)){
u32 offset=M2C_FIELD(p,volatile u32*,0x1c)-base;u32 size=0x200-offset;s32 a,b,c;
if(size>M2C_FIELD(p,u32*,0x24))size=M2C_FIELD(p,u32*,0x24);
MI_CpuCopy8((u8*)arg0+0x20+offset,M2C_FIELD(p,void**,0x20),size);
a=M2C_FIELD(p,volatile s32*,0x1c)+(s32)size;b=M2C_FIELD(p,volatile s32*,0x20)+(s32)size;c=M2C_FIELD(p,volatile s32*,0x24)-(s32)size;
M2C_FIELD(p,u32*,0x1c)=a;M2C_FIELD(p,u32*,0x20)=b;M2C_FIELD(p,u32*,0x24)=c;
}return M2C_FIELD(p,volatile u32*,0x24)!=0;
}
#pragma optimization_level 4
/* Loads a raw card command into the command registers once the card is idle:
   byte 0 gets the transfer mode, then the opcode (in the top byte of `command`)
   and the four address bytes are written big-endian, the address split across
   `command`'s low bits and `address`.  The caller starts the transfer by writing
   CARD_REG_ROMCTRL. */
void CARD_SetCommand(u32 command, u32 address) {
    volatile u8 *regs = (volatile u8 *)CARD_REG_COMMAND;
    while (*(volatile u32 *)CARD_REG_ROMCTRL & 0x80000000) {}
    regs[0] = CARD_COMMAND_MODE;
    regs[7] = command >> 24;
    regs[8] = command >> 16;
    regs[9] = command >> 8;
    regs[10] = command;
    regs[11] = address >> 24;
    regs[12] = address >> 16;
    regs[13] = address >> 8;
    regs[14] = address;
}

#pragma opt_propagation off
/* Starts the DMA read of the next 512-byte backup-chip block: arms the
 * transfer's DMA channel to pull the block from the card data port into the
 * destination, queues the block's command, then starts it through ROM control. */
void SaveDevice_StartTransferDma(void)
{
  extern void *gSaveDeviceState;
  extern u32 gSaveDeviceCommand[];
  void func_02008538(u32, void *, u32, u32);
  u32 *state;
  u32 *command = gSaveDeviceCommand;
  state = (u32 *) (&gSaveDeviceState);
  func_02008538(state[SAVE_DEVICE_DMA_CHANNEL / 4], (void *) 0x04100010, state[SAVE_DEVICE_DEST / 4], 512);
  CARD_SetCommand((state[SAVE_DEVICE_ADDRESS / 4] >> 8) | 0xB7000000, state[SAVE_DEVICE_ADDRESS / 4] << 24);
  *((volatile u32 *) 0x040001A4) = command[1];
}
#pragma opt_propagation on
void func_020106dc(void) {
    s32 DmaStopChannel(s32);
    void OS_DisableIrqMask(s32);
    void OS_SetIrqMask(s32);
    s32 SaveDevice_ReadChipId(void);
    void SaveDevice_CheckChipId(s32);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_WakeupThread(void *);
    void TaskWake(void *);
    void SaveDevice_StartTransferDma(void);
    extern void *gSaveDeviceState;
    s32 a;
    s32 c;
    s32 b;
    s32 flag;
    s32 r;
    s32 r5;
    s32 r6;
    s32 state;
    void *q;
    void *p;

    DmaStopChannel(M2C_FIELD(&gSaveDeviceState, s32 *, 0x28));
    q = &gSaveDeviceState;
    a = M2C_FIELD(q, s32 *, 0x24);
    b = M2C_FIELD(q, s32 *, 0x1c) + 0x200;
    c = M2C_FIELD(q, s32 *, 0x20) + 0x200;
    a = a - 0x200;
    M2C_FIELD(q, s32 *, 0x24) = a;
    if (a != 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    M2C_FIELD(q, s32 *, 0x1c) = b;
    M2C_FIELD(q, s32 *, 0x20) = c;
    if (flag) goto fail;
    OS_DisableIrqMask(0x80000);
    OS_SetIrqMask(0x80000);
    p = &gSaveDeviceState;
    r = SaveDevice_ReadChipId();
    SaveDevice_CheckChipId(r);
    M2C_FIELD(M2C_FIELD(p, s32 **, 0), s32 *, 0) = 0;
    r5 = M2C_FIELD(p, s32 *, 0x38);
    r6 = M2C_FIELD(p, s32 *, 0x3c);
    state = OS_DisableInterrupts();
    M2C_FIELD(p, u32 *, 0x114) = M2C_FIELD(p, u32 *, 0x114) & ~0x4c;
    OS_WakeupThread((u8 *)p + 0x10c);
    if (M2C_FIELD(p, u32 *, 0x114) & 0x10) {
        TaskWake((u8 *)p + 0x44);
    }
    OS_RestoreInterrupts(state);
    if (r5 != 0) {
        ((void (*)(s32))r5)(r6);
    }
    return;
fail:
    SaveDevice_StartTransferDma();
}

s32 func_020107ac(void *command) {
    extern void *data_020f553c, *gSaveDeviceState;
    void func_01ff8000(void);
    u32 func_02006c8c(void);
    void IC_InvalidateRange(u32, u32);
    void func_02006810(void);
    void DC_Sync(void);
    void DC_FlushAll(void);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_SetIrqHandler(u32, void (*)(void));
    void OS_SetIrqMask(s32);
    void OS_EnableIrqMask(u32);
    void DC_CleanRange(void *, u32);
    void DC_InvalidateRange(void *, s32);
    void *state = &gSaveDeviceState;
    u32 length;
    s32 started;
    s32 alignedTransfer, validRange, validMode;
    u32 dest, misalignment;
    u32 dtcm, end, irq;
    s32 invalidRange, overlapsItcm;

    started = 0;
    dest = M2C_FIELD(state, u32 *, 0x20);
    alignedTransfer = 0;
    validRange = 0;
    validMode = 0;
    misalignment = dest & 31;
    length = M2C_FIELD(state, u32 *, 0x24);

    if (misalignment == 0 && M2C_FIELD(state, u32 *, 0x28) <= 3) validMode = 1;
    if (validMode) {
        dtcm = func_02006c8c();
        invalidRange = 1;
        overlapsItcm = 0;
        end = dest + length;
        if (end > (u32)func_01ff8000) overlapsItcm = (dest < 0x02000000) ? invalidRange : 0;
        if (!overlapsItcm && (dtcm >= end || dtcm + 0x4000 <= dest)) invalidRange = 0;
        if (!invalidRange) validRange = 1;
    }
    if (validRange && ((M2C_FIELD(state, u32 *, 0x1c) | length) & 511) == 0) alignedTransfer = 1;
    if (alignedTransfer && length != 0) started = 1;
    M2C_FIELD(command, u32 *, 4) = (M2C_FIELD(data_020f553c, u32 *, 0x60) & ~0x07000000) | 0xa1000000;

    if (started) {
        irq = OS_DisableInterrupts();
        if (length < M2C_FIELD(state, u32 *, 0x118)) IC_InvalidateRange(dest, length);
        else func_02006810();
        if (length < M2C_FIELD(state, u32 *, 0x11c)) {
            if (misalignment != 0) {
                dest -= misalignment;
                DC_CleanRange((void *)dest, 32);
                DC_CleanRange((void *)(dest + length), 32);
                length += 32;
            }
            DC_InvalidateRange((void *)dest, length);
            DC_Sync();
        } else {
            DC_FlushAll();
        }
        OS_SetIrqHandler(0x80000, func_020106dc);
        OS_SetIrqMask(0x80000);
        OS_EnableIrqMask(0x80000);
        OS_RestoreInterrupts(irq);
        SaveDevice_StartTransferDma();
    }
    return started;
}

void SaveDevice_TransferRom(void *arg0) {
    void CARD_SetCommand(u32, u32);
    s32 SaveDevice_TransferChunk(void *);
    extern void *gSaveDeviceState;
    void *state = &gSaveDeviceState;
    u32 *dst;
    u32 address, aligned;
    register u32 remaining;
    register u32 status, index, bytes;
    u32 value;
    volatile u32 *control = (volatile u32 *)0x040001A4;
    volatile u32 *fifo = (volatile u32 *)0x04100010;

    do {
retry:
        address = M2C_FIELD(state, u32 *, 0x1c);
        aligned = address & ~0x1ff;
        if (aligned == address && ((u32)(dst = M2C_FIELD(state, u32 **, 0x20)) & 3) == 0 &&
            M2C_FIELD(state, u32 *, 0x24) >= 0x200) {
            /* Transfer directly into the destination. */
        } else {
            M2C_FIELD(arg0, u32 *, 0x8) = aligned;
            dst = (u32 *)((u8 *)arg0 + 0x20);
        }

        CARD_SetCommand((aligned >> 8) | 0xB7000000, aligned << 24);
        index = 0;
        bytes = 0;
        *control = M2C_FIELD(arg0, u32 *, 0x4);
        do {
            status = *control;
            if (status & 0x00800000) {
                value = *fifo;
                if (bytes < 0x200) {
                    dst[index] = value;
                    bytes += 4;
                    index++;
                }
            }
        } while (status & 0x80000000);
        if (dst == M2C_FIELD(state, u32 **, 0x20)) {
            void *device = &gSaveDeviceState;
            M2C_FIELD(device, u32 *, 0x1c) += 0x200;
            M2C_FIELD(device, u32 *, 0x20) += 0x200;
            remaining = M2C_FIELD(device, u32 *, 0x24) - 0x200;
            M2C_FIELD(device, u32 *, 0x24) = remaining;
            if (remaining == 0) return;
            goto retry;
        }
    } while (SaveDevice_TransferChunk(arg0));
}

#pragma opt_propagation off
s32 SaveDevice_ReadChipId(void) {
    extern void *data_020f553c;
    u32 control;
    register u32 mask;

    CARD_SetCommand(0xB8000000, 0);
    mask = sizeof(u32) * 2048;
    control = M2C_FIELD(data_020f553c, volatile u32 *, 0x60);
    control &= ~0x07000000;
    control |= 0xA7000000;
    *(volatile u32 *)0x040001A4 = control & -mask;
    while (!(*(volatile u32 *)0x040001A4 & 0x800000)) {
    }
    return *(volatile s32 *)0x04100010;
}
#pragma opt_propagation on
/* Finishes a backup transfer in the calling thread: drains what is left of the
 * data through the device's bounce buffer one chunk at a time, reads the save
 * chip's ID and checks it, then clears the transfer flags, wakes the threads
 * asleep on the transfer and calls its completion callback. */
void SaveDevice_FinishTransfer(void) {
    s32 SaveDevice_TransferChunk(void *);
    s32 SaveDevice_ReadChipId(void);
    void SaveDevice_CheckChipId(s32);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_WakeupThread(void *);
    void TaskWake(void *);
    extern u32 gSaveDeviceCommand[];
    extern void *gSaveDeviceState;

    void *command = &gSaveDeviceCommand[0];
    void *device;
    s32 pending;
    s32 callback;
    s32 callbackArg;
    s32 state;

    pending = SaveDevice_TransferChunk(command);
    if (pending != 0) {
        void (*chunkHandler)(void *) = M2C_FIELD(command, void (**)(void *), 0);
        chunkHandler(command);
    }
    device = &gSaveDeviceState;
    pending = SaveDevice_ReadChipId();
    SaveDevice_CheckChipId(pending);
    M2C_FIELD(M2C_FIELD(device, s32 **, SAVE_DEVICE_RESPONSE), s32 *, 0) = 0;
    callback = M2C_FIELD(device, s32 *, SAVE_DEVICE_CALLBACK);
    callbackArg = M2C_FIELD(device, s32 *, SAVE_DEVICE_CALLBACK_ARG);
    state = OS_DisableInterrupts();
    M2C_FIELD(device, u32 *, SAVE_DEVICE_FLAGS) =
        M2C_FIELD(device, u32 *, SAVE_DEVICE_FLAGS) &
        ~(SAVE_DEVICE_FLAG_BUSY | SAVE_DEVICE_FLAG_ASYNC | SAVE_DEVICE_FLAG_CHUNK);
    OS_WakeupThread((u8 *)device + SAVE_DEVICE_THREAD_QUEUE);
    if (M2C_FIELD(device, u32 *, SAVE_DEVICE_FLAGS) & SAVE_DEVICE_FLAG_TASK_WAITING) {
        TaskWake((u8 *)device + SAVE_DEVICE_TASK);
    }
    OS_RestoreInterrupts(state);
    if (callback != 0) {
        ((void (*)(s32))callback)(callbackArg);
    }
}

void StartCardArchiveRead(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, s32 arg6) {
    extern u32 data_02130420[];
    extern void *data_0212fde0;
    extern u32 data_02130400[];
    extern M2C_UNK data_0212dca4;
    void func_0200fd78(void);
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02005da4(void *);
    s32 func_02007ca4(s32);
    s32 func_020107ac(void *);
    void func_02010c78(void);
    void func_0200fb0c(void *);
    void func_02010a84(void);

    void *r4 = data_02130420;
    void *r5 = &data_0212fde0;
    u32 r10 = arg0;
    s32 r9 = arg1;
    s32 r8 = arg2;
    s32 r7 = arg3;
    s32 state;
    s32 r;

    func_0200fd78();
    state = func_0200751c();
    goto test;
loop:
    func_02005da4((u8 *)r5 + 0x10c);
test:
    if (M2C_FIELD(r5, volatile u32 *, 0x114) & 4) goto loop;
    {
        volatile u32 *_fp = (volatile u32 *)((u8 *)r5 + 0x114);
        u32 _v = *_fp;
        *_fp = _v | 4;
    }
    M2C_FIELD(r5, s32 *, 0x38) = arg4;
    M2C_FIELD(r5, void **, 0x3c) = arg5;
    func_02007530(state);
    {
        u32 *_dp = data_02130400;
        M2C_FIELD(r5, u32 *, 0x28) = r10;
        {
            u32 _dv = _dp[0];
            M2C_FIELD(r5, u32 *, 0x20) = r8;
            M2C_FIELD(r5, u32 *, 0x1c) = r9 + _dv;
        }
    }
    M2C_FIELD(r5, u32 *, 0x24) = r7;
    if (r10 <= 3) {
        func_02007ca4(r10);
    }
    r = func_020107ac(r4);
    if (r != 0) {
        if (arg6 != 0) {
            return;
        }
        func_02010c78();
        return;
    }
    if (arg6 != 0) {
        func_0200fb0c((void *)func_02010a84);
        return;
    }
    M2C_FIELD(r5, u32 *, 0x104) = M2C_FIELD(&data_0212dca4, u32 *, 4);
    func_02010a84();
}

