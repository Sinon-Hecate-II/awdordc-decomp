/* 41 functions from 0x0200DD40 to 0x0200ED40 (main), found by ds-decomp. */
#include "common.h"
static inline u8 flagsDD(u32 mode,u32 enabled) { return enabled?(u8)(mode|16):(u8)mode; }

/* A transfer request handed to StartArm7Transfer: the type selects the ARM7
 * transfer mode, then the 32-byte-aligned source and destination, the byte size
 * (at least 1024) and a flag; user1/user2 are handed back to the completion
 * callback registered in gArm7Transfer. */
typedef struct Arm7TransferDesc {
    u32 type;  /* +0x00 transfer type (0..5) */
    u32 src;   /* +0x04 source address, a multiple of 32 */
    u32 dst;   /* +0x08 destination address, a multiple of 32 */
    u32 size;  /* +0x0C byte count, at least 1024 */
    u32 flag;  /* +0x10 nonzero to set bit 16 of the mode word */
    u32 user1; /* +0x14 value passed to the callback */
    u32 user2; /* +0x18 callback argument */
} Arm7TransferDesc;

/* Initialises the ARM7 IPC transfer service: marks it started, clears its busy
 * flag and completion callback, waits for its FIFO channel and installs the
 * transfer reply handler. */
void Arm7TransferInit(void) {
    M2C_UNK PXI_Init();
    M2C_UNK SetFifoMessageHandler(M2C_UNK, M2C_UNK *);
    s32 IsFifoMessageReady(M2C_UNK, M2C_UNK);
    extern M2C_UNK gArm7TransferState;
    void Arm7TransferFifoHandler(s32,u32,s32);
    if (M2C_FIELD(&gArm7TransferState, u16 *, 0) != 0) return;
    M2C_FIELD(&gArm7TransferState, u16 *, 0) = 1;
    M2C_FIELD(&gArm7TransferState, s32 *, 4) = 0;
    M2C_FIELD(&gArm7TransferState, s32 *, 8) = 0;
    PXI_Init();
    do {} while (IsFifoMessageReady(9, 1) == 0);
    *(s32 *)0x027FFF90 = 0;
    SetFifoMessageHandler(9, (M2C_UNK *)&Arm7TransferFifoHandler);
}

/* Validate an ARM7 transfer descriptor and start it: the type picks the transfer
 * mode, the flag sets bit 4 of the mode byte, and user1/user2 are kept for the
 * progress callback.  cb(user) reports the result when the transfer finishes.
 * Returns 0 started, 1 already busy, 2 malformed descriptor, 3 rejected. */
s32 Arm7TransferStart(M2C_UNK a, void (*cb)(s32), s32 user) {
    extern M2C_UNK gArm7TransferState;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 Arm7TransferSubmit(u32, u32, u32, u32);
    Arm7TransferDesc *desc = (Arm7TransferDesc *)a;
    u32 mode;
    u32 flags;
    s32 state;
    if (desc->src & 31) return 2;
    if (desc->dst & 31) return 2;
    if (!desc->dst) return 2;
    if (desc->size < 1024) return 2;
    switch (desc->type) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: mode = 3; break;
    case 4: mode = 5; break;
    case 5: mode = 7; break;
    default: return 2;
    }
    flags = desc->flag ? (u8)(mode | 16) : (u8)mode;
    flags = (u8)flags;
    state = OS_DisableInterrupts();
    if (M2C_FIELD(&gArm7TransferState, s32 *, 4)) {
        OS_RestoreInterrupts(state);
        return 1;
    }
    M2C_FIELD(&gArm7TransferState, s32 *, 4) = 1;
    OS_RestoreInterrupts(state);
    M2C_FIELD(&gArm7TransferState, void (**)(s32), 8) = cb;
    M2C_FIELD(&gArm7TransferState, s32 *, 12) = user;
    M2C_FIELD(&gArm7TransferState, u32 *, 20) = desc->user1;
    M2C_FIELD(&gArm7TransferState, u32 *, 24) = desc->user2;
    if (Arm7TransferSubmit(desc->src, desc->dst, desc->size, flags)) return 0;
    return 3;
}

s32 func_0200dedc(M2C_UNK arg0) {
    s32 Arm7TransferStart(M2C_UNK, void (*)(s32), s32);
    void func_0200e20c(s32);
    s32 func_0200e21c(void);
    extern M2C_UNK gArm7TransferState;
    s32 result;
    result = Arm7TransferStart(arg0, func_0200e20c, 0);
    M2C_FIELD(&gArm7TransferState, s32 *, 0x10) = result;
    if (result == 0) func_0200e21c();
    return M2C_FIELD(&gArm7TransferState, s32 *, 0x10);
}

/* End the ARM7 transfer service's current operation: take the busy flag, remember
 * the completion callback and its argument, then post the transfer-end command.
 * Returns 1 when a transfer is already pending, 0 once ended, 3 if the command
 * could not be sent. */
s32 Arm7TransferEnd(s32 callback, s32 user) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 Arm7TransferSendStopCommand(void);
    extern M2C_UNK gArm7TransferState;
    s32 interruptState;
    interruptState = OS_DisableInterrupts();
    if (M2C_FIELD(&gArm7TransferState, s32 *, ARM7_XFER_STATE_BUSY) != 0) {
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    M2C_FIELD(&gArm7TransferState, s32 *, ARM7_XFER_STATE_BUSY) = 1;
    OS_RestoreInterrupts(interruptState);
    M2C_FIELD(&gArm7TransferState, s32 *, ARM7_XFER_STATE_CALLBACK) = callback;
    M2C_FIELD(&gArm7TransferState, s32 *, ARM7_XFER_STATE_USER) = user;
    if (Arm7TransferSendStopCommand() != 0) return 0;
    return 3;
}

s32 func_0200df70(void) {
    void func_0200e20c(s32);
    s32 func_0200e21c(void);
    extern M2C_UNK gArm7TransferState;
    s32 result;
    result = Arm7TransferEnd((s32)func_0200e20c, 0);
    M2C_FIELD(&gArm7TransferState, s32 *, 0x10) = result;
    if (result == 0) func_0200e21c();
    return M2C_FIELD(&gArm7TransferState, s32 *, 0x10);
}

s32 func_0200dfa8(void) {
    return *(s32 *)0x027FFF90;
}

#pragma scheduling off
void Arm7TransferFifoHandler(s32 a,u32 b,s32 c){
extern M2C_UNK gArm7TransferState;
void (*cb)(s32,s32);u32 cmd;u32 low;s32 result;
if(c){
if(M2C_FIELD(&gArm7TransferState,s32 *,4))M2C_FIELD(&gArm7TransferState,s32 *,4)=0;
cb=M2C_FIELD(&gArm7TransferState,void (**)(s32,s32),8);
if(cb){M2C_FIELD(&gArm7TransferState,s32 *,8)=0;cb(6,M2C_FIELD(&gArm7TransferState,s32 *,12));}
}
low=b&0xff; cmd=(b&0x7f00)>>8;
switch(low){case 0:result=0;break;case 1:result=4;break;case 2:result=2;break;case 3:result=5;break;case 4:result=1;break;default:result=6;break;}
if(cmd==81){
cb=M2C_FIELD(&gArm7TransferState,void (**)(s32,s32),20);
if(cb)cb(result,M2C_FIELD(&gArm7TransferState,s32 *,24));
return;
}
if(cmd==64 && M2C_FIELD(&gArm7TransferState,u16 **,28)) *M2C_FIELD(&gArm7TransferState,u16 **,28)=*(volatile u16 *)0x027fff94;
if(M2C_FIELD(&gArm7TransferState,s32 *,4))M2C_FIELD(&gArm7TransferState,s32 *,4)=0;
cb=M2C_FIELD(&gArm7TransferState,void (**)(s32,s32),8);
if(cb){M2C_FIELD(&gArm7TransferState,s32 *,8)=0;cb(result,M2C_FIELD(&gArm7TransferState,s32 *,12));}
}
#pragma scheduling on
/* Post an ARM7 transfer request on the IPC FIFO: the transfer flags word, then
 * the source, destination and byte size as high/low 16-bit halves.  Each word
 * must be accepted by the FIFO; the last one marks the end of the request.
 * Returns 1 when all seven words went out, 0 when the FIFO rejected one. */
s32 Arm7TransferSubmit(u32 src, u32 dst, u32 size, u32 flags) {
    if (SendFifoMessage(ARM7_XFER_FIFO_TAG, flags | 0x02004100, 0) < 0) {
        return 0;
    }
    if (SendFifoMessage(ARM7_XFER_FIFO_TAG, (src >> 16) | ARM7_XFER_WORD(1), 0) < 0) {
        return 0;
    }
    if (SendFifoMessage(ARM7_XFER_FIFO_TAG, (u16)src | ARM7_XFER_WORD(2), 0) < 0) {
        return 0;
    }
    if (SendFifoMessage(ARM7_XFER_FIFO_TAG, (dst >> 16) | ARM7_XFER_WORD(3), 0) < 0) {
        return 0;
    }
    if (SendFifoMessage(ARM7_XFER_FIFO_TAG, (u16)dst | ARM7_XFER_WORD(4), 0) < 0) {
        return 0;
    }
    if (SendFifoMessage(ARM7_XFER_FIFO_TAG, (size >> 16) | ARM7_XFER_WORD(5), 0) < 0) {
        return 0;
    }
    if (SendFifoMessage(ARM7_XFER_FIFO_TAG, ARM7_XFER_WORD(6) | ARM7_XFER_LAST_WORD | (u16)size, 0) >= 0) {
        return 1;
    }
    return 0;
}

s32 Arm7TransferSendStopCommand(void) {
    s32 SendFifoMessage(M2C_UNK, s32, M2C_UNK);
    if (SendFifoMessage(9, 0x03004200, 0) >= 0) {
        return 1;
    }
    return 0;
}

void func_0200e20c(s32 arg0) {
    extern M2C_UNK gArm7TransferState;
    M2C_FIELD(&gArm7TransferState, s32 *, 0x10) = arg0;
}

s32 func_0200e21c(void) {
    extern s32 data_0212fcb0;
    s32 status;
    do {
        status = *(volatile s32 *)&data_0212fcb0;
    } while (status == 1);
    return status;
}

s32 Arm7CommandAcquire(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gArm7CommandState;
    s32 state = OS_DisableInterrupts();
    if (M2C_FIELD(&gArm7CommandState, s32 *, 0x18) != 0) {
        OS_RestoreInterrupts(state);
        return 0;
    }
    M2C_FIELD(&gArm7CommandState, s32 *, 0x18) = 1;
    OS_RestoreInterrupts(state);
    return 1;
}

void func_0200e270(void) {
    s32 func_02007574();
    M2C_UNK FifoReceiveHandler();
    extern M2C_UNK gArm7CommandState;
    extern s32 data_0212fce4;
    s32 *status=&data_0212fce4;
    if(M2C_FIELD(&gArm7CommandState,s32 *,0x18)==0) return;
    do {
        if(func_02007574()==0x80) FifoReceiveHandler();
    } while(*status!=0);
}

void func_0200e2b0(s32 arg0, s32 *arg1) {
    *arg1 = arg0;
}

void Arm7FinishCommand(s32 arg0) {
    extern M2C_UNK gArm7CommandState;
    s32 busy;
    void (*callback)(s32,s32);
    s32 value;
    busy=M2C_FIELD(&gArm7CommandState,s32 *,0x18);
    callback=M2C_FIELD(&gArm7CommandState,void (**)(s32,s32),0x1C);
    value=M2C_FIELD(&gArm7CommandState,s32 *,0x20);
    if(busy!=0) M2C_FIELD(&gArm7CommandState,s32 *,0x18)=0;
    if(callback==NULL) return;
    M2C_FIELD(&gArm7CommandState,void (**)(s32,s32),0x1C)=NULL;
    callback(arg0,value);
}

/* Bring the ARM7 command service up once: start the ARM7 link, wait for the
 * IPC FIFO handler tag, install the reply handler, clear the five pending reply
 * slots, create the reply mutex and record the current frame as the last LCD
 * power-off. */
void Arm7CommandInit(void) {
    M2C_UNK InitMutex(M2C_UNK *);
    M2C_UNK PXI_Init();
    M2C_UNK SetFifoMessageHandler(M2C_UNK, M2C_UNK *);
    s32 IsFifoMessageReady(M2C_UNK,M2C_UNK);
    extern M2C_UNK gArm7CommandState;
    extern M2C_UNK gArm7CommandMutex;
    extern M2C_UNK gArm7CommandReplySlots;
    extern M2C_UNK Arm7CommandReply;
    s32 i;
    if(M2C_FIELD(&gArm7CommandState,u16 *,ARM7_CMD_INIT)!=0) return;
    M2C_FIELD(&gArm7CommandState,u16 *,ARM7_CMD_INIT)=1;
    M2C_FIELD(&gArm7CommandState,s32 *,ARM7_CMD_BUSY)=0;
    M2C_FIELD(&gArm7CommandState,s32 *,ARM7_CMD_CALLBACK)=0;
    PXI_Init();
    do {} while(IsFifoMessageReady(ARM7_CMD_FIFO_TAG,1)==0);
    SetFifoMessageHandler(ARM7_CMD_FIFO_TAG,&Arm7CommandReply);
    for(i=0;i<ARM7_CMD_REPLY_COUNT;i++) ((u16 (*)[4])&gArm7CommandReplySlots)[i][0]=0;
    InitMutex(&gArm7CommandMutex);
    M2C_FIELD(&gArm7CommandState,s32 *,POWER_SERVICE_LAST_OFF)=*(s32 *)SHARED_FRAME_COUNTER;
}

/* Arm7CommandReply: the ARM7 command service's FIFO handler (tag 8) for one reply
   word — a command in bits 8..14 and a value in bits 0..7.  Commands 0x70..0x74
   store the value into the matching reply slot (gArm7CommandReplySlots/data_0212fd10: a
   u16 "written" flag and a u16 *destination per slot), 0x60/0x62 set the
   service's done flags and 0x67 stores it through the caller's pointer; the
   pending command is then finished with that value.  A non-zero error finishes
   it as error 2 without touching anything. */
void Arm7CommandReply(s32 tag, u32 word, s32 error) {
extern M2C_UNK data_0212fd10; extern M2C_UNK gArm7CommandReplySlots; extern M2C_UNK gArm7CommandState;
u32 command; u16 value; u16 *dest;
if(error!=0) { Arm7FinishCommand(2); return; }
command=(u16)((word & 0x7F00)>>8);
value=word&0xFF;
if(command>=0x70 && command<=0x74) {
command-=0x70;
dest=((u16 *(*)[2])&data_0212fd10)[command][0];
value=(u8)value;
if(dest) *dest=value;
((u16 (*)[4])&gArm7CommandReplySlots)[command][0]=1;
value=0;
} else if(command==0x60) M2C_FIELD(&gArm7CommandState,s32 *,4)=1;
else if(command==0x62) M2C_FIELD(&gArm7CommandState,s32 *,8)=1;
else if(command==0x67) {
s32 *p=M2C_FIELD(&gArm7CommandState,s32 **,0x24);
if(p) *p=value;
value=0;
}
Arm7FinishCommand(value);
}

/* Put the ARM7 side of the console to sleep: take the command service, ask the
 * ARM7 to prepare for a power-down (command 0x60) and wait for its answer, clear
 * the acknowledgement flags and switch the LCD off, then send the sleep command
 * 0x61 with the caller's flags and wake word.  Returns 1 when another command is
 * already outstanding, 0 once the ARM7 has been told to sleep. */
s32 Arm7EnterSleepMode(s32 flags, s32 wakeWord) {
    void Arm7SendCommand(s32);
    extern M2C_UNK gArm7CommandState;
    M2C_UNK SetLcdPower(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    if (Arm7CommandAcquire() == 0) return 1;
    M2C_FIELD(&gArm7CommandState, volatile s32 *, ARM7_CMD_DONE_NOTIFY) = 0;
    Arm7SendCommand(0x03006000);
    do {
    } while (M2C_FIELD(&gArm7CommandState, volatile s32 *, ARM7_CMD_DONE_NOTIFY) == 0);
    M2C_FIELD(&gArm7CommandState, volatile s32 *, ARM7_CMD_DONE_NOTIFY) = 0;
    M2C_FIELD(&gArm7CommandState, volatile s32 *, ARM7_CMD_DONE_SLEEP) = 0;
    SetLcdPower(0, 2, 0, 1);
    Arm7SendCommand((u8)flags | 0x02006100);
    Arm7SendCommand(0x01010000 | (u16)wakeWord);
    return 0;
}

/* Send the ARM7 its power-state command (0x63): bits 16..23 of powerArg form the
 * command's argument byte and its low 16 bits the argument word, with callback
 * and user remembered for the reply.  Returns 1 when a command is already
 * outstanding, 0 once it has been sent. */
s32 Arm7SetPowerState(u32 powerArg, s32 callback, s32 user) {
    void Arm7SendCommand(s32);
    extern M2C_UNK gArm7CommandState;
    if (Arm7CommandAcquire() == 0) return 1;
    M2C_FIELD(&gArm7CommandState, s32 *, ARM7_CMD_CALLBACK) = callback;
    M2C_FIELD(&gArm7CommandState, s32 *, ARM7_CMD_USER) = user;
    Arm7SendCommand(ARM7_CMD_WORD(ARM7_CMD_SET_POWER, powerArg >> 16));
    Arm7SendCommand(ARM7_CMD_ARG_WORD(powerArg));
    return 0;
}

#pragma scheduling off
s32 func_0200e558(s32 arg0, s32 arg1, void (*arg2)(s32, s32 *), s32 *arg3) {
    void Arm7SendCommand(s32);
    extern M2C_UNK gArm7CommandState;
    extern M2C_UNK gArm7CommandReplySlots;
    extern M2C_UNK data_0212fd10;
    if (Arm7CommandAcquire() == 0) return 1;
    M2C_FIELD(&gArm7CommandState, void (**)(s32, s32 *), 0x1C) = arg2;
    M2C_FIELD(&gArm7CommandState, s32 **, 0x20) = arg3;
    ((u16 (*)[4])&gArm7CommandReplySlots)[arg0][0] = 0;
    *(s32 *)((u8 *)&data_0212fd10 + arg0 * 8) = arg1;
    Arm7SendCommand((u8)arg0 | 0x03006500);
    return 0;
}
#pragma scheduling reset
s32 Arm7GetValueWait(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0200e270(void);
    s32 func_0200e558(M2C_UNK, M2C_UNK, void (*)(s32, s32 *), s32 *);
    s32 sp0;
    s32 result;
    result = func_0200e558(arg0, arg1, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

/* Send the ARM7 a sound-amplifier parameter (command 0x64): the selector byte
 * picks the parameter and the 16-bit value its new setting, with the reply
 * callback and user remembered for when the ARM7 answers.  Returns 1 when a
 * command is already outstanding, 0 once it has been sent. */
s32 Arm7SetAmpParam(s32 param, M2C_UNK value, void (*callback)(s32, s32 *), s32 *user) {
    void Arm7SendCommand(s32);
    extern M2C_UNK gArm7CommandState;
    if (Arm7CommandAcquire() == 0) return 1;
    M2C_FIELD(&gArm7CommandState, void (**)(s32, s32 *), ARM7_CMD_CALLBACK) = callback;
    M2C_FIELD(&gArm7CommandState, s32 **, ARM7_CMD_USER) = user;
    Arm7SendCommand(ARM7_CMD_WORD(ARM7_CMD_SET_AMP, param));
    Arm7SendCommand(ARM7_CMD_ARG_WORD(value));
    return 0;
}

s32 func_0200e64c(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0200e270(void);
    s32 Arm7SetAmpParam(M2C_UNK, M2C_UNK, void (*)(s32, s32 *), s32 *);
    s32 sp0;
    s32 result;
    result = Arm7SetAmpParam(arg0, arg1, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

s32 SendPowerCommand(s32 arg0, void (*arg1)(s32, s32 *), s32 *arg2) {
    s32 Arm7SetPowerState();
    s32 var_r0;

    switch (arg0) {                                 /* irregular */
    case 1:
        var_r0 = 1;
        break;
    case 3:
        var_r0 = 2;
        break;
    case 2:
        var_r0 = 3;
        break;
    default:
        var_r0 = 0;
        break;
    }
    if (var_r0 == 0) {
        return 0xFFFF;
    }
    return Arm7SetPowerState();
}

s32 SendPowerCommandWait(s32 arg0) {
    void func_0200e270(void);
    s32 sp0;
    s32 result;
    result = SendPowerCommand(arg0, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

/* Switch the backlight of a screen (0 main, 1 sub, 2 both) on (enabled = 1) or
 * off (enabled = 0) by sending the matching ARM7 power state; callback receives
 * the reply and user.  Returns ARM7_POWER_INVALID for an unknown combination. */
s32 Arm7SetBacklight(M2C_UNK screen, M2C_UNK enabled, void (*callback)(s32, s32 *), s32 *user) {
    s32 powerState;

    powerState = 0;
    if (screen == 0) {
        if (enabled == 1) powerState = 6;
        if (enabled == 0) powerState = 7;
    } else if (screen == 1) {
        if (enabled == 1) powerState = 4;
        if (enabled == 0) powerState = 5;
    } else if (screen == 2) {
        if (enabled == 1) powerState = 8;
        if (enabled == 0) powerState = 9;
    }
    if (powerState == 0) {
        return ARM7_POWER_INVALID;
    }
    return Arm7SetPowerState(powerState, (M2C_UNK)callback, (s32)user);
}

s32 Arm7SetBacklightWait(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0200e270(void);
    s32 Arm7SetBacklight(M2C_UNK, M2C_UNK, void (*)(s32, s32 *), s32 *);
    s32 sp0;
    s32 result;
    result = Arm7SetBacklight(arg0, arg1, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

/* Bring the display back up after the power service switched it off: give the
 * hardware time to settle, restore each screen's backlight state from the ARM7's
 * power flags, enable the LCD (the service refuses a re-enable within seven
 * frames of switching it off, so retry after a delay), then send ARM7 power
 * command 0x0E; its reply is handed to callback together with user. */
void WakeDisplay(s32 callback, s32 user) {
    void WaitCycles(M2C_UNK);
    s32 IsLcdEnabled(void);

    M2C_UNK Arm7SetBacklightWait(M2C_UNK, M2C_UNK);
    s32 SetLcdEnabled(s32);
    s32 Arm7SetPowerState(u32, s32, s32);
    s32 backlight0Off;
    s32 backlight1Off;

    WaitCycles(LCD_WAKE_DELAY_CYCLES);
    if (IsLcdEnabled() != 1) {
        ReadPowerFlags(&backlight0Off, &backlight1Off);
        if (backlight0Off != 0) {
            Arm7SetBacklightWait(0, 0);
        }
        if (backlight1Off != 0) {
            Arm7SetBacklightWait(1, 0);
        }
        while (SetLcdEnabled(1) == 0) {
            WaitCycles(LCD_WAKE_DELAY_CYCLES);
        }
    }
    Arm7SetPowerState(0xE, callback, user);
}

s32 WakeDisplayWait(void) {
s32 sp0,result;
result=((s32 (*)(s32,s32))WakeDisplay)((s32)func_0200e2b0,(s32)&sp0);
if(result)return result;
func_0200e270();return sp0;
}

void func_0200e868(s32 a) {
func_0200e64c(2,(u16)a);
}

void func_0200e880(s32 a) {
func_0200e64c(3,(u16)a);
}

/* Reads the ARM7's power-flags word and reports the two backlight-off bits:
   bit 3 into *backlight0Off (main screen) and bit 2 into *backlight1Off (sub
   screen).  Returns the command's result. */
s32 ReadPowerFlags(s32 *backlight0Off, s32 *backlight1Off) {
    u16 value;
    s32 result;
    result = Arm7GetValueWait(0, &value);
    if (result) return result;
    if (backlight0Off) *backlight0Off = (value & 8) ? 1 : 0;
    if (backlight1Off) *backlight1Off = (value & 4) ? 1 : 0;
    return result;
}

void Arm7SendCommand(M2C_UNK arg0) {
    do {

    } while (SendFifoMessage(8, arg0, 0) != 0);
}

#pragma push
#pragma optimization_level 3
void func_0200e920(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(M2C_UNK);
    M2C_UNK OS_DisableIrqMask(M2C_UNK);
    M2C_UNK OS_SetIrqEnableMask(M2C_UNK);
    void func_0200ede8(M2C_UNK);
    M2C_UNK func_02018c9c(void);
    M2C_UNK IsLcdEnabled(void);
    s32 ReadPowerFlags(s32 *, s32 *);
    s32 Arm7SetBacklightWait(M2C_UNK, M2C_UNK);
    M2C_UNK Arm7EnterSleepMode(M2C_UNK, M2C_UNK);
    void func_02007968(void);
    M2C_UNK SetLcdPower(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 SendPowerCommandWait(s32);
    void WaitCycles(M2C_UNK);
    s32 WakeDisplayWait(void);
    extern M2C_UNK gArm7CommandState;

    M2C_UNK r10 = arg0;
    M2C_UNK r9 = arg1;
    M2C_UNK r11 = arg2;
    volatile u16 *hw208 = (volatile u16 *)0x4000208;
    u16 r8;

    M2C_UNK r5;
    M2C_UNK r6;

    u32 r7;
    volatile u32 *p4m;
    volatile u32 *p4m1;
    volatile M2C_UNK *p27 = (volatile M2C_UNK *)0x27ffc3c;
    M2C_UNK spc;
    s32 sp14,sp10;
    volatile s32 sp12,sp8,sp4,sp0;
    M2C_UNK r4 = 0;

    func_0200ede8(M2C_FIELD(&gArm7CommandState, M2C_UNK *, 0xC));

    r8 = *hw208;
    *hw208 = 0;

    sp8 = OS_DisableInterrupts();
    sp4 = OS_DisableIrqMask(0x3fffff);
    OS_SetIrqEnableMask(0x40000);
    OS_RestoreInterrupts(sp8);

    {
        M2C_UNK tmp = *hw208;
        (void)tmp;
    }
    *hw208 = 1;

    if (r10 & 0x8) {
        volatile u16 *w = (volatile u16 *)0x27ffc40;
        M2C_UNK v = *w;
        if (v == 0x2) r10 &= ~0x8;
    }
    if (r10 & 0x10) {
        if (func_02018c9c() == 0) r10 &= ~0x10;
    }

    p4m = (volatile u32 *)0x4000000;
    p4m1 = (volatile u32 *)0x4001000;
    r5 = *p4m;
    r6 = *p4m1;
    sp0 = IsLcdEnabled();
    ReadPowerFlags(&sp14, &sp10);
    Arm7SetBacklightWait(2, 0);

    sp12 = *p27;
    while(*p27 == sp12) {}
    sp12 = *p27;
    *p4m &= ~0x30000;
    *p4m1 &= ~0x10000;
    while(sp12 == *p27) {}
    sp12 = *p27;
    while(sp12 == *p27) {}

    r7 = (u16)(r10 | (sp14 << 5) | (sp10 << 6));
    r9 = (u16)(r9 | r11);

    if (Arm7EnterSleepMode(r7, r9) == 0) {
        func_02007968();
    }

    if (r10 & 0x8) {
        volatile M2C_UNK *w2 = (volatile M2C_UNK *)0x4000214;
        M2C_UNK v2 = *w2;
        if (v2 & 0x100000) r4 = 1;
    }

    if (r4 == 0) {
        if (sp0 == 1) {
            SetLcdPower(1, 1, 1, 1);
        } else {
            SendPowerCommandWait(1); 
        }

    *p4m = r5;
    *p4m1 = r6;
    WaitCycles(0x708100);
    }
    OS_DisableInterrupts();
    OS_SetIrqEnableMask(sp4);
    OS_RestoreInterrupts(sp8);

    {u16 tmp=*hw208; *hw208=r8;}
    if(r4 != 0) WakeDisplayWait();

    func_0200ede8(M2C_FIELD(&gArm7CommandState, M2C_UNK *, 0x14));

    (void)r8;
    (void)hw208;
    return;
}
#pragma pop
/* Power the LCD on or off.  Switching it off stores the shared frame counter so
 * that an immediate re-enable (a bouncing lid or power button) is ignored for
 * seven frames, and either way the given power state is handed to the ARM7
 * driver, waiting for its reply when wait is set.  Returns 0 when the re-enable
 * was debounced, 1 otherwise. */
s32 SetLcdPower(s32 on, s32 arm7State, s32 force, s32 wait) {
    extern M2C_UNK gArm7CommandState;

    switch (on) {
    case 1:
        if (force == 0 && (u32)(*(volatile u32 *)SHARED_FRAME_COUNTER - M2C_FIELD(&gArm7CommandState, u32 *, POWER_SERVICE_LAST_OFF)) <= 7) return 0;
        if (arm7State != 0) {
            if (wait != 0) SendPowerCommandWait(arm7State);
            else SendPowerCommand(arm7State, 0, 0);
        }
        *(volatile u16 *)REG_POWCNT1 |= POWCNT1_LCD_ENABLE;
        break;
    case 0:
        *(volatile u16 *)REG_POWCNT1 &= ~POWCNT1_LCD_ENABLE;
        M2C_FIELD(&gArm7CommandState, u32 *, POWER_SERVICE_LAST_OFF) = *(volatile u32 *)SHARED_FRAME_COUNTER;
        if (arm7State != 0) {
            if (wait != 0) SendPowerCommandWait(arm7State);
            else SendPowerCommand(arm7State, 0, 0);
        }
        break;
    }
    return 1;
}

s32 SetLcdEnabled(s32 arg0) {
    M2C_UNK SetLcdPower(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 != 1) {
        var_r0 = 0;
    }
    SetLcdPower(var_r0, 0, 0, 1);
}

s32 IsLcdEnabled(void) {
    if (*(u16 *)0x04000304 & 1) {
        return 1;
    }
    return 0;
}

s32 func_0200ec60(s32 arg0, void (*arg1)(s32, s32 *), s32 *arg2) {
 s32 Arm7CommandAcquire();
 void Arm7SendCommand(s32);
 extern M2C_UNK gArm7CommandState;
 if (Arm7CommandAcquire() == 0) return 1;
 M2C_FIELD(&gArm7CommandState, void (**)(s32,s32 *), 0x1C) = arg1;
 M2C_FIELD(&gArm7CommandState, s32 **, 0x20) = arg2;
 Arm7SendCommand((u8)arg0 | 0x03006600);
 return 0;
}

s32 func_0200eca8(s32 arg0) {
    void func_0200e270(void);
    s32 sp0;
    s32 result;
    result = func_0200ec60(arg0, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

s32 func_0200ecd0(s32 arg0, s32 arg1, s32 arg2) {
    s32 Arm7CommandAcquire();
    extern M2C_UNK gArm7CommandState;
    if (Arm7CommandAcquire() == 0) {
        return 1;
    }
    M2C_FIELD(&gArm7CommandState, s32 *, 0x1C) = arg1;
    M2C_FIELD(&gArm7CommandState, s32 *, 0x20) = arg2;
    M2C_FIELD(&gArm7CommandState, s32 *, 0x24) = arg0;
    Arm7SendCommand(0x03006700);
    return 0;
}

s32 func_0200ed18(s32 arg0) {
    s32 sp0;
    s32 result;
    result = func_0200ecd0(arg0, (s32)func_0200e2b0, (s32)&sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

