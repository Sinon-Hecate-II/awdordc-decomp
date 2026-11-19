/* 33 functions from 0x02010C14 to 0x02011BB0 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

void func_02010c14(void){extern u8 gSaveDeviceState[],data_02130400[];M2C_UNK *func_02010c84(void);void func_0200fc58();void func_02010e68();u8 *p=gSaveDeviceState;u8 *q;s32 zero,minus,one;if(M2C_FIELD(p,s32 *,276))return;q=data_02130400;zero=0;minus=zero-1;one=1;M2C_FIELD(p,s32 *,276)=one;M2C_FIELD(p,s32 *,36)=zero;M2C_FIELD(p,s32 *,32)=zero;M2C_FIELD(p,s32 *,28)=zero;M2C_FIELD(p,s32 *,40)=minus;M2C_FIELD(p,s32 *,56)=zero;M2C_FIELD(p,s32 *,60)=zero;M2C_FIELD(q,s32 *,0)=zero;func_0200fc58();M2C_FIELD(data_02130400,s32 *,32)=(s32)func_02010c84();func_02010e68();}

void func_02010c78(void) {
    M2C_UNK func_0200fda0();
    func_0200fda0();
}

M2C_UNK *func_02010c84(void) {
    extern M2C_UNK func_02010938;
    return &func_02010938;
}

void func_02010c90(s32 a,s32 b,s32 c){extern u8 gSaveDeviceState[];void TaskWake(s32);s32 v;if(a!=11)return;if(!c)return;v=M2C_FIELD(gSaveDeviceState,s32 *,260);M2C_FIELD(gSaveDeviceState,s32 *,276)&=~32;TaskWake(v);}

void func_02010cc4(void){extern u8 gSaveDeviceState[];s32 OS_DisableInterrupts();M2C_UNK OS_RestoreInterrupts(s32);void OS_SleepThread(s32);s32 zero=0;u8 *p=gSaveDeviceState;s32 a;for(;;){a=OS_DisableInterrupts();while(!(M2C_FIELD(p,s32 *,276)&8))OS_SleepThread(zero);OS_RestoreInterrupts(a);M2C_FIELD(p,void (**)(void *),64)(p);}}

/* Sends a packet over the device, retrying while the device reports "busy/again" (status 4). */
s32 func_02010d14(void *dev, s32 *packet, s32 retries) {
void OS_SleepThread(s32);
void DC_FlushRange(s32 *, s32);
void DC_InvalidateRange(s32 *, s32);
void func_02006804(void);
void WaitCycles(s32);
s32 IsFifoMessageReady(s32, s32);
s32 SendFifoMessage(s32, s32, s32);
s32 OS_DisableInterrupts(void);
M2C_UNK OS_RestoreInterrupts(s32);
s32 count;
s32 *pkt;
s32 status;
s32 savedIrq;
count = retries;
if (!(M2C_FIELD(dev, volatile s32 *, 0x114) & 2)) {
M2C_FIELD(dev, volatile s32 *, 0x114) = M2C_FIELD(dev, volatile s32 *, 0x114) | 2;
if (IsFifoMessageReady(11, 1) == 0) {
do { WaitCycles(100); } while (IsFifoMessageReady(11, 1) == 0);
}
func_02010d14(dev, 0, 1);
}
DC_FlushRange(M2C_FIELD(dev, s32 **, 0), 96);
func_02006804();
again:
M2C_FIELD(dev, s32 **, 4) = packet;
M2C_FIELD(dev, volatile s32 *, 0x114) = M2C_FIELD(dev, volatile s32 *, 0x114) | 32;
do { } while (SendFifoMessage(11, (s32)packet, 1) < 0);
if (!packet) {
pkt = M2C_FIELD(dev, s32 **, 0);
do { } while (SendFifoMessage(11, (s32)pkt, 1) < 0);
}
savedIrq = OS_DisableInterrupts();
while (M2C_FIELD(dev, volatile s32 *, 0x114) & 32) OS_SleepThread(0);
OS_RestoreInterrupts(savedIrq);
DC_InvalidateRange(M2C_FIELD(dev, s32 **, 0), 96);
status = *M2C_FIELD(dev, s32 **, 0);
if (status == 4 && --count > 0) goto again;
if (status == 0) return 1;
return 0;
}

void func_02010e68(void) { void func_02009d34(void); void SetFifoMessageHandler(s32,void (*)(s32,s32)); void func_02010e94(s32,s32); extern M2C_UNK data_02130640; func_02009d34();SetFifoMessageHandler(14,func_02010e94);M2C_FIELD(&data_02130640,s32 *,4)=0; }

void func_02010e94(s32 a,s32 b) { void ShutdownSystem(void); void SystemHalt(void); extern M2C_UNK data_02130640; s32 result;
if((b&63)==17) {if(M2C_FIELD(&data_02130640,s32 *,0))return;result=1;M2C_FIELD(&data_02130640,s32 *,0)=result;
if(M2C_FIELD(&data_02130640,s32 (**)(),4))result=M2C_FIELD(&data_02130640,s32 (**)(),4)();
if(!result)return;
ShutdownSystem();return;}SystemHalt();
}

s32 func_02010ee8(void) {
    extern s32 data_02130640;
    return data_02130640;
}

/* Final shutdown path: stop all four DMA channels and, while the lid is
 * closed, wait for the display to come back up.  If that succeeded, notify the
 * ARM7 over the system FIFO, then halt the CPU. */
void ShutdownSystem(void) {
void DmaStopChannel(s32); s32 WakeDisplayWait(void); void WaitCycles(s32); void SendFifoMessageWait(M2C_UNK,M2C_UNK); void SystemHalt(void);
s32 canNotify=1; s32 result;
DmaStopChannel(0);DmaStopChannel(1);DmaStopChannel(2);DmaStopChannel(3);
if((*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED)>>15) {
result=WakeDisplayWait();while(result==4){WaitCycles(DISPLAY_WAKE_RETRY_CYCLES);result=WakeDisplayWait();}
if(result==0)canNotify=0;
}
if(canNotify)SendFifoMessageWait(1,1);
SystemHalt();
}

void SaveDevice_CheckChipId(s32 arg0) {
s32 OS_DisableInterrupts(); M2C_UNK OS_RestoreInterrupts(s32);
volatile s32 sp0; s32 *p; s32 saved;
if(*(u16 *)0x027FFC10==0)p=(s32 *)0x027FF800;else p=(s32 *)0x027FFC00;
sp0=*p;if(arg0==sp0)return;
saved=OS_DisableInterrupts();((void (*)(s32,s32,s32))func_02010e94)(14,17,0);OS_RestoreInterrupts(saved);
}

void SendFifoMessageWait(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK WaitByLoop(M2C_UNK);
    s32 SendFifoMessage(M2C_UNK, M2C_UNK, M2C_UNK);
    if (SendFifoMessage(0xE, arg0, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(arg1);
    } while (SendFifoMessage(0xE, arg0, 0) != 0);
}

s32 func_02011034(s32 a,s32 b) {
s32 func_02011060(s32,s32,s32);extern M2C_UNK gWfcChannelState;
s32 result=func_02011060(a,b,0xF00);
if(result!=0)return result;
M2C_FIELD(M2C_FIELD(&gWfcChannelState,void **,4),u16 *,0x16)=0;
return result;
}

#pragma push
#pragma optimization_level 2
#pragma opt_strength_reduction off
#pragma scheduling off
s32 func_02011060(s32 arg0, s32 arg1, s32 arg2) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    void func_02009d34();
    s32 IsFifoMessageReady(s32, s32);
    void DC_InvalidateRange();
    void DmaFill();
    void func_020118f4(void);
    void OS_InitMessageQueue();
    void DC_CleanRange();
    s32 OS_SendMessage();
    void SetFifoMessageHandler();
    void WFC_CommandHandler(u32, void *, u32);
    extern M2C_UNK gWfcChannelState;
    extern M2C_UNK gWfcFreeBufferQueue;
    extern M2C_UNK data_02130688;
    extern M2C_UNK data_02130700;
    void *p;
    s32 i;
 s32 j;
 s32 saved;
    u8 *buf;
    saved = OS_DisableInterrupts();
    if (M2C_FIELD(&gWfcChannelState, u16 *, 0) != 0) {
        OS_RestoreInterrupts(saved);
        return 3;
    }
    if (arg0 == 0) {
        OS_RestoreInterrupts(saved);
        return 6;
    }
    if ((u32)arg1 > 3) {
        OS_RestoreInterrupts(saved);
        return 6;
    }
    if (arg0 & 0x1f) {
        OS_RestoreInterrupts(saved);
        return 6;
    }
    func_02009d34();
    if (IsFifoMessageReady(10, 1) == 0) {
        OS_RestoreInterrupts(saved);
        return 4;
    }
    DC_InvalidateRange(arg0, arg2);
    DmaFill(arg1, arg0, 0, arg2);
    p = (void *)arg0;
    M2C_FIELD(&gWfcChannelState, void **, 4) = p;
    M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 0) = arg0 + 0x200;
    M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 4) = M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 0) + 0x300;
    M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 0xc) = M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 4) + 0x800;
    M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 0x10) = M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 0xc) + 0x100;
    func_020118f4();
    M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), u16 *, 0x14) = (u16)arg1;
    M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), s32 *, 0x14c) = 0;
    M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, 4), u16 *, 0x150) = 0;
    for (i = 0; i < 0x10; i++) {
        ((s32 *)((u8 *)M2C_FIELD(&gWfcChannelState, void **, 4) + 0xcc))[i] = 0;
        ((s32 *)((u8 *)M2C_FIELD(&gWfcChannelState, void **, 4) + 0x10c))[i] = 0;
    }
    OS_InitMessageQueue(&gWfcFreeBufferQueue, &data_02130688, 10);
    buf = (u8 *)&data_02130700;
    for (j = 0; j < 10; j++) {
        *(u16 *)(buf + j * 256) = 0x8000;
        DC_CleanRange(buf + j * 256, 2);
        OS_SendMessage(&gWfcFreeBufferQueue, buf + j * 256, 1);
    }
    SetFifoMessageHandler(10, WFC_CommandHandler);
    M2C_FIELD(&gWfcChannelState, u16 *, 0) = 1;
    OS_RestoreInterrupts(saved);
    return 0;
}
#pragma pop
s32 WFC_ShutdownCommandChannel(void) {
s32 OS_DisableInterrupts();M2C_UNK OS_RestoreInterrupts(s32);s32 WFC_CheckChannelState(s32,...);void func_020118f4(void);extern M2C_UNK gWfcChannelState;
s32 saved=OS_DisableInterrupts();s32 result;
if(WFC_CheckReady()!=0){OS_RestoreInterrupts(saved);return 3;}
result=WFC_CheckChannelState(1,0);if(result!=0)return result;
func_020118f4();SetFifoMessageHandler(10,0);
M2C_FIELD(&gWfcChannelState,s32 *,4)=0;M2C_FIELD(&gWfcChannelState,u16 *,0)=0;
OS_RestoreInterrupts(saved);return 0;
}

void WFC_SetChannelParam(s32 a,s32 b){extern M2C_UNK gWfcChannelState;M2C_FIELD(M2C_FIELD(&gWfcChannelState,s32 *,4)+a*4,s32 *,24)=b;}

u16 *WFC_AllocBuffer(void) {
    s32 OS_ReceiveMessage(M2C_UNK *, u16 **, M2C_UNK);
    M2C_UNK OS_JamMessage(M2C_UNK *, u16 *, M2C_UNK);
    extern M2C_UNK gWfcFreeBufferQueue;
    u16 *sp0;

    if (OS_ReceiveMessage(&gWfcFreeBufferQueue, &sp0, 0) == 0) {
        return NULL;
    }
    DC_InvalidateRange(sp0, 2);
    if (*sp0 & 0x8000) {
        return sp0;
    }
    OS_JamMessage(&gWfcFreeBufferQueue, sp0, 1);
    return NULL;
}

/* Posts a command and its `count` 32-bit arguments to the ARM7 firmware in one of
 * the channel's command blocks; the arguments follow `count` in the varargs list.
 * The block goes back to the free pool once the FIFO has taken it. */
s32 WFC_SendCommand(u16 command, u16 argCount, ...) {
    extern M2C_UNK gWfcFreeBufferQueue;
    s32 SendFifoMessage();
    s32 OS_SendMessage();
    void DC_CleanRange();
    s32 *args;
    s32 i;
    s32 result;
    s32 count;
    u16 *block;

    block = WFC_AllocBuffer();
    if (!block) return WFC_CMD_NO_BUFFER;
    *block = command;
    count = argCount;
    args = (s32 *)((u32)&argCount & ~3) + 1;
    for (i = 0; i < count; i++) {
        args++;
        ((s32 *)block)[i + 1] = args[-1];
    }
    DC_CleanRange(block, WFC_CMD_BLOCK_SIZE);
    result = SendFifoMessage(WFC_CMD_FIFO_TAG, block, 0);
    OS_SendMessage(&gWfcFreeBufferQueue, block, OS_MESSAGE_BLOCK);
    return result < 0 ? WFC_CMD_NO_BUFFER : WFC_CMD_OK;
}

s32 WFC_SendCommandPacket(void *a,s32 b) {
extern M2C_UNK gWfcFreeBufferQueue;s32 SendFifoMessage();s32 OS_SendMessage();void DC_CleanRange();void MI_CpuCopy8();
u16 *p=WFC_AllocBuffer();s32 r;if(!p)return 8;MI_CpuCopy8(a,p,b);DC_CleanRange(p,b);r=SendFifoMessage(10,p,0);OS_SendMessage(&gWfcFreeBufferQueue,p,1);return r<0?8:2;
}

s32 WFC_GetInfoBlock(void) {
    extern M2C_UNK gWfcChannelState;
    return M2C_FIELD(&gWfcChannelState, s32 *, 4);
}

s32 WFC_CheckReady(void) { extern M2C_UNK gWfcChannelState; if(M2C_FIELD(&gWfcChannelState,u16 *,0))return 0;return 3; }

s32 func_0201146c(void) {
extern M2C_UNK gWfcChannelState;s32 r=WFC_CheckReady();if(r)return r;
DC_InvalidateRange(M2C_FIELD(M2C_FIELD(&gWfcChannelState,void **,4),void **,4),2);
return M2C_FIELD(M2C_FIELD(M2C_FIELD(&gWfcChannelState,void **,4),void **,4),u16 *,0)<=1U?3:0;
}

/* Verify the WFC command channel is ready and that the link's current state is
 * one of the `expectedCount` states passed as variable arguments.  Returns 0
 * when one matches, otherwise the channel-not-ready result (3). */
s32 WFC_CheckChannelState(s32 expectedCount, ...) {
    extern M2C_UNK gWfcChannelState;
    s32 result = WFC_CheckReady();
    s32 *args;
    u16 state;
    if (result) return result;
    DC_InvalidateRange(M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, WFC_CMD_STATE_INFO), void **, WFC_CMD_INFO_DATA), sizeof(u16));
    state = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gWfcChannelState, void **, WFC_CMD_STATE_INFO), void **, WFC_CMD_INFO_DATA), u16 *, WFC_CMD_INFO_LINK_STATE);
    args = (s32 *)((u32)&expectedCount & ~3) + 1;
    result = 3;
    while (expectedCount) {
        args++;
        if (args[-1] == state) result = 0;
        expectedCount--;
    }
    return result;
}

/* WFC command-channel FIFO handler: the ARM7 firmware posts a command packet,
 * and this dispatches it to the general event callback, the per-channel
 * callbacks and the connection-status path, rebuilding the connection event
 * packet (gWfcChannelState + WFC_CMD_STATE_EVENT) those callbacks read. */
void WFC_CommandHandler(u32 fifoTag, void *packet, u32 error) {
    void SystemHalt(void);
    void func_020118f4(void);
    void DC_CleanRange();
    extern M2C_UNK gWfcChannelState, gWfcEventPacket, gWfcEventMac, gWfcEventPayload;
    void *info = M2C_FIELD(&gWfcChannelState, void **, WFC_CMD_STATE_INFO);
    u32 command;
    u16 event, aid, localAid, reason, second;
    void *mac, *extra;
    u16 first, channel;
    void *entry;
    void (*callback)(void *);
    (void)fifoTag;
    if (error) return;
    DC_InvalidateRange(M2C_FIELD(info, void **, WFC_CMD_INFO_PACKET), WFC_CMD_BLOCK_SIZE);
    if (!M2C_FIELD(info, u16 *, WFC_CMD_INFO_DATA_CACHED))
        DC_InvalidateRange(M2C_FIELD(info, void **, WFC_CMD_INFO_DATA), 0x800);
    if (packet != M2C_FIELD(info, void **, WFC_CMD_INFO_PACKET))
        DC_InvalidateRange(packet, WFC_CMD_BLOCK_SIZE);
    command = M2C_FIELD(packet, u16 *, 0);
    if (command >= WFC_CMD_EVENT_BASE) {
        if (command == WFC_CMD_GENERAL_EVENT) {
            if (M2C_FIELD(packet, u16 *, 2) == 0x13) SystemHalt();
            callback = M2C_FIELD(info, void (**)(void *), WFC_CMD_INFO_CALLBACK);
            if (callback) callback(packet);
        } else if (command == WFC_CMD_CHANNEL_EVENT) {
            channel = M2C_FIELD(packet, u16 *, 6);
            if (M2C_FIELD(info + channel * 4, void (**)(void *), WFC_CMD_INFO_CHANNELS)) {
                M2C_FIELD(packet, u32 *, 0x1c) = M2C_FIELD(info + channel * 4, u32 *, WFC_CMD_INFO_VALUES);
                M2C_FIELD(packet, u16 *, 0x22) = M2C_FIELD(info, u32 *, WFC_CMD_INFO_AID_MASK);
                DC_InvalidateRange(M2C_FIELD(packet, void **, 8), M2C_FIELD(M2C_FIELD(info, void **, WFC_CMD_INFO_DATA), u16 *, 0x72));
                M2C_FIELD(info + M2C_FIELD(packet, u16 *, 6) * 4, void (**)(void *), WFC_CMD_INFO_CHANNELS)(packet);
            }
        } else if (command == WFC_CMD_COMMAND_REPLY) {
            M2C_FIELD(packet, u16 *, 0) = 0xf;
            callback = M2C_FIELD(packet, void (**)(void *), 0x1c);
            if (callback) callback(packet);
        }
    } else {
        if (command == WFC_CMD_LINK_STATUS && (u16)(M2C_FIELD(packet, u16 *, 4) + 0xfff5) <= 1 &&
            M2C_FIELD(packet, u16 *, 2) == 0) {
            DC_InvalidateRange(M2C_FIELD(packet, void **, 8), M2C_FIELD(M2C_FIELD(info, void **, WFC_CMD_INFO_DATA), u16 *, 0x72));
        }
        command = M2C_FIELD(packet, u16 *, 0);
        if (command == WFC_CMD_SHUTDOWN && M2C_FIELD(packet, u16 *, 2) == 0) {
            entry = info + command * 4;
            callback = M2C_FIELD(entry, void (**)(void *), 0x18);
            WFC_ShutdownCommandChannel();
            if (callback) callback(packet);
            return;
        }
        entry = info + command * 4;
        callback = M2C_FIELD(entry, void (**)(void *), 0x18);
        if (callback) {
            callback(packet);
            if (!M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_READY)) return;
        }
        command = M2C_FIELD(packet, u16 *, 0);
        if (command == WFC_CMD_PEER_STATUS || command == WFC_CMD_SELF_STATUS) {
            if (command == WFC_CMD_PEER_STATUS) {
                mac = packet + 0xa;
                event = M2C_FIELD(packet, u16 *, 8);
                aid = M2C_FIELD(packet, u16 *, 0x10);
                reason = M2C_FIELD(packet, u16 *, 0x12);
                extra = packet + 0x14;
                localAid = 0;
                first = M2C_FIELD(packet, u16 *, 0x2c);
                second = M2C_FIELD(packet, u16 *, 0x2e);
            } else if (command == WFC_CMD_SELF_STATUS) {
                event = M2C_FIELD(packet, u16 *, 8);
                localAid = M2C_FIELD(packet, u16 *, 0xa);
                reason = M2C_FIELD(packet, u16 *, 0xc);
                aid = 0;
                extra = NULL;
                mac = packet + 0x10;
                first = M2C_FIELD(packet, u16 *, 0x16);
                second = M2C_FIELD(packet, u16 *, 0x18);
            }
            if (event == WFC_EVENT_JOINED || event == WFC_EVENT_LEFT || event == WFC_EVENT_OTHER) {
                if (event == WFC_EVENT_JOINED) M2C_FIELD(info, u32 *, WFC_CMD_INFO_AID_MASK) |= 1U << aid;
                else M2C_FIELD(info, u32 *, WFC_CMD_INFO_AID_MASK) &= ~(1U << aid);
                M2C_FIELD(info, u16 *, WFC_CMD_INFO_LOCAL_AID) = localAid;
                MI_CpuFill8(&gWfcEventPacket, 0, 0x44);
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_COMMAND) = WFC_CMD_CHANNEL_EVENT;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_INDEX) = 0;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_KIND) = event;
                M2C_FIELD(&gWfcChannelState, u32 *, WFC_CMD_STATE_EVENT + WFC_EVENT_RESERVED08) = 0;
                M2C_FIELD(&gWfcChannelState, u32 *, WFC_CMD_STATE_EVENT + WFC_EVENT_RESERVED0C) = 0;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_RESERVED10) = 0;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_AID) = aid;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_LOCAL_AID) = localAid;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_AID_MASK) = M2C_FIELD(info, u32 *, WFC_CMD_INFO_AID_MASK);
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_SENTINEL) = 0xffff;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_REASON) = reason;
                MI_CpuCopy8(mac, &gWfcEventMac, 6);
                if (extra) CopyU16(extra, &gWfcEventPayload, 0x18);
                else FillU16(0, &gWfcEventPayload, 0x18);
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_FIRST) = localAid == 0 ? first : second;
                M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_SECOND) = localAid == 0 ? second : first;
                for (channel = 0; channel < 16; ++channel) {
                    M2C_FIELD(&gWfcChannelState, u16 *, WFC_CMD_STATE_EVENT + WFC_EVENT_CHANNEL) = channel;
                    entry = info + channel * 4;
                    if (M2C_FIELD(entry, void (**)(void *), WFC_CMD_INFO_CHANNELS)) {
                        M2C_FIELD(&gWfcChannelState, u32 *, WFC_CMD_STATE_EVENT + WFC_EVENT_VALUE) = M2C_FIELD(entry, u32 *, WFC_CMD_INFO_VALUES);
                        M2C_FIELD(entry, void (**)(void *), WFC_CMD_INFO_CHANNELS)(&gWfcEventPacket);
                    }
                }
            }
        }
    }
    DC_InvalidateRange(M2C_FIELD(info, void **, WFC_CMD_INFO_PACKET), WFC_CMD_BLOCK_SIZE);
    func_020118f4();
    if (packet != M2C_FIELD(info, void **, WFC_CMD_INFO_PACKET)) {
        M2C_FIELD(packet, u16 *, 0) |= WFC_CMD_BLOCK_FREE;
        DC_CleanRange(packet, WFC_CMD_BLOCK_SIZE);
    }
}

void func_020118f4(void) {
    u16 temp_r0;

    temp_r0 = *(u16 *)0x027FFF96;
    if (temp_r0 & 1) {
        *(u16 *)0x027FFF96 = temp_r0 & ~1;
    }
}

s32 func_02011910(void) {
extern M2C_UNK gWfcChannelState;
if(WFC_CheckReady()!=0)return 0;
return M2C_FIELD(M2C_FIELD(&gWfcChannelState,void **,4),s32 *,4);
}

s32 WFC_GetLocalPlayerIndex(void) {
extern M2C_UNK gWfcChannelState;s32 s=OS_DisableInterrupts();s32 r;void *p=M2C_FIELD(&gWfcChannelState,void **,4);if(p)r=M2C_FIELD(p,u16 *,0x150);else r=0;OS_RestoreInterrupts(s);return r;
}

u16 func_02011964(void) { s32 OS_DisableInterrupts(void); M2C_UNK OS_RestoreInterrupts(s32); extern M2C_UNK gWfcChannelState;s32 s=OS_DisableInterrupts();s32 r;void *p=M2C_FIELD(&gWfcChannelState,void **,4);if(p)r=M2C_FIELD(p,s32 *,0x14c);else r=0;OS_RestoreInterrupts(s);return r;}

s32 func_02011994(void) {s32 OS_DisableInterrupts(void); M2C_UNK OS_RestoreInterrupts(s32);M2C_UNK DC_InvalidateRange();extern M2C_UNK gWfcChannelState;s32 r;void *p;s32 s;s=OS_DisableInterrupts();p=M2C_FIELD(&gWfcChannelState,void **,4);if(!p)r=0;else {p=M2C_FIELD(p,void **,4);DC_InvalidateRange(p+0x86,2);r=M2C_FIELD(p,u16 *,0x86);}OS_RestoreInterrupts(s);return r;}

s32 func_020119dc(s32 arg0) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 WFC_CheckReady();
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = OS_DisableInterrupts();
    temp_r0 = WFC_CheckReady();
    if (temp_r0 != 0) {
        OS_RestoreInterrupts(temp_r5);
        return temp_r0;
    }
    M2C_FIELD(WFC_GetInfoBlock(), s32 *, 0xC8) = arg0;
    OS_RestoreInterrupts(temp_r5);
    return 0;
}

/* Registers a callback and passes it some data under critical section. */
s32 WFC_SetChannelHandler(s32 arg0, void (*callback)(void *), s32 arg2) {
    u8 buf[0x44];
    s32 result;
    s32 irq;
    void *p;

    if (callback) {
        MI_CpuFill8(buf, 0, 0x44);
        M2C_FIELD(buf, u16 *, 0) = 0x82;
        M2C_FIELD(buf, u16 *, 2) = 0;
        M2C_FIELD(buf, u16 *, 4) = 0x19;
        M2C_FIELD(buf, u16 *, 6) = arg0;
        M2C_FIELD(buf, u32 *, 8) = 0;
        M2C_FIELD(buf, u32 *, 12) = 0;
        M2C_FIELD(buf, u16 *, 16) = 0;
        M2C_FIELD(buf, u16 *, 26) = 0xffff;
        M2C_FIELD(buf, u32 *, 28) = arg2;
        M2C_FIELD(buf, u16 *, 18) = 0;
        GetMacAddress(buf + 20);
    }
    irq = OS_DisableInterrupts();
    result = WFC_CheckReady();
    if (result) {
        OS_RestoreInterrupts(irq);
        return result;
    }
    p = (u8 *)WFC_GetInfoBlock() + arg0 * 4;
    M2C_FIELD(p, void (**)(void *), 0xcc) = callback;
    M2C_FIELD(p, s32 *, 0x10c) = arg2;
    if (callback) {
        M2C_FIELD(buf, u16 *, 34) = (void *)func_02011964();
        M2C_FIELD(buf, u16 *, 32) = (void *)WFC_GetLocalPlayerIndex();
        callback(buf);
    }
    OS_RestoreInterrupts(irq);
    return 0;
}

s32 func_02011af8(s32 arg0) {
    M2C_UNK DC_InvalidateRange(s32, M2C_UNK);
    M2C_UNK MI_CpuCopy32(s32, s32, M2C_UNK);
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = WFC_GetInfoBlock();
    temp_r0 = WFC_CheckReady();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (arg0 == 0) {
        return 6;
    }
    DC_InvalidateRange(M2C_FIELD(temp_r4, s32 *, 4), 0x7D0);
    MI_CpuCopy32(M2C_FIELD(temp_r4, s32 *, 4), arg0, 0x7D0);
    return 0;
}

s32 func_02011b44(void) {
    s32 WFC_CheckChannelState(s32,...);
    void *temp_r1;
    void *temp_r4;

    temp_r4 = WFC_GetInfoBlock();
    if (WFC_CheckChannelState(2, 7, 8) != 0) {
        return 0;
    }
    DC_InvalidateRange(M2C_FIELD(temp_r4, void **, 4) + 0xC, 4);
    temp_r1 = M2C_FIELD(temp_r4, void **, 4);
    if (M2C_FIELD(temp_r1, s32 *, 0xC) == 1) {
        return 0;
    }
    DC_InvalidateRange(temp_r1 + 0x3C, 4);
    return (M2C_FIELD(M2C_FIELD(temp_r4, void **, 4), u16 *, 0x3C) + 0x1F) & ~0x1F;
}

