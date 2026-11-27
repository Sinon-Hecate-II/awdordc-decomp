/* 44 functions from 0x0216CCE0 to 0x0216DBDC (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_room.h"
#include "ov001_wh.h"
#include "wfc.h"
extern M2C_UNK gWhConnTaskState;

#pragma thumb on
/* Swap the two halves of the `size`-byte buffer `data` in place: stage the second
 * half, then the first half, in the equally sized scratch buffer `swapBuffer`, and
 * copy the staged buffer back over `data`. */
void Ov001_SwapHalves(s32 data, s32 size, s32 swapBuffer) {
    void Ov001MemCopy(s32, s32, s32);
    s32 half = size / 2;
    Ov001MemCopy(swapBuffer, data + half, half);
    Ov001MemCopy(swapBuffer + half, data, half);
    Ov001MemCopy(data, swapBuffer, size);
}
/* Allocate `size` bytes from the room protocol's installed allocator hook
 * (data_ov001_021925e0[0], the one Ov001_AllocHook calls); a non-positive size
 * allocates nothing and returns 0.  The first argument is ignored. */
s32 Ov001_AllocRoomBuffer(s32 unused, s32 size) {
    extern s32 (*data_ov001_021925e0)(s32);
    if (size > 0) return data_ov001_021925e0(size);
    return 0;
}

void func_ov001_0216cd28(s32 arg0, s32 arg1) {
    extern void (*data_ov001_021925ec)(s32);
    data_ov001_021925ec(arg1);
}

/* Bring the ov001 network stack up with three endpoint addresses: the addresses
   are byte-swapped into the config's three address words and applied by
   func_02021a90, then the routine blocks until the console has a local IP
   address.  Returns 0 once it does, or -1 when the stack fails to start. */
s32 WhInitNetwork(s32 address0, s32 address1, s32 address2) {
    s32 Ov001SwapEndian32(s32);
    s32 func_02021a90(void *);
    void SleepMilliseconds();
    extern s32 gLocalIpAddress;
    extern M2C_UNK gWhNetConfig;
    extern M2C_UNK gWhNetInitParams;
    M2C_FIELD(&gWhNetConfig, s32 *, 0x18) = Ov001SwapEndian32(address0);
    M2C_FIELD(&gWhNetConfig, s32 *, 0x1c) = Ov001SwapEndian32(address1);
    M2C_FIELD(&gWhNetConfig, s32 *, 0x20) = Ov001SwapEndian32(address2);
    if (func_02021a90(&gWhNetInitParams) < 0) return -1;
    while (gLocalIpAddress == 0) SleepMilliseconds(100);
    return 0;
}

/* Shut the network stack down, then wait for the connection task's link-status
 * message: returns 0 when it arrived, -1 when the shutdown failed or no link
 * status came. */
s32 WhConnTaskShutdown(void) {
    s32 ghiShutdown();
    s32 WhConnTaskReceiveLinkStatus();
    if (ghiShutdown() < 0) return -1;
    return -(WhConnTaskReceiveLinkStatus() != 0);
}

/* Compare up to maxLength bytes, returning the first unsigned-byte difference or zero. */
s32 Ov001CompareBytes(u8 *left, u8 *right, s32 maxLength) {
    s32 result = 0;
    while (maxLength-- > 0 && (result = *left - *right) == 0) {
        left++;
        right++;
    }
    return result;
}

void Ov001MemCopy(s32 arg0, s32 arg1, s32 arg2) {
 void MI_CpuCopy8(s32, s32, s32);
 MI_CpuCopy8(arg1, arg0, arg2);
}

void Ov001MemClear(s32 arg0, s32 arg1) {
 void MI_CpuFill8(s32, u8);
 MI_CpuFill8(arg0, (u8)arg1);
}

void func_ov001_0216cdf0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 *arg5) {
 void SocketRecvFromAddress(s32, s32, s32, s32, u8 *);
 *arg4 = *arg5;
 SocketRecvFromAddress(arg0, arg1, arg2, arg3, arg4);
}

void func_ov001_0216ce04(M2C_UNK arg0, s32 *arg1, M2C_UNK arg2, M2C_UNK arg3, s32 *arg4) {
    M2C_UNK PollSockets(s32 *, s32, u64);
    u64 func_020720d0(s64, s64);
    s32 sp0;
    s32 sp4;
    u64 temp = 0;

    sp0 = arg1[0];
    sp4 = arg1[1];
    temp += func_020720d0(arg4[0], 0x1FF6210) >> 6;
    temp += func_020720d0(arg4[1], 0x1FF6210) >> 6;
    PollSockets(&sp0, 1, temp);
}

void Ov001_SendToAddress(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 *arg4, s32 arg5) {
    M2C_UNK func_020216cc(s32, s32, s32, s32, s8 *);
    *arg4 = (s8) arg5;
    func_020216cc(arg0, arg1, arg2, arg3, arg4);
}

void func_ov001_0216ce68(void) {

}

#pragma thumb on
void func_ov001_0216ce6c(void) {
    void SocketCreate(void);
    SocketCreate();
}

void func_ov001_0216ce74(M2C_UNK arg0, void *arg1, u8 arg2) {
    void SocketBindAddress(M2C_UNK, void *);
    M2C_FIELD(arg1, u8 *, 0) = arg2;
    SocketBindAddress(arg0, arg1);
}

void func_ov001_0216ce80(void) {
    void func_0202175c(void);
    func_0202175c();
}

/* Reverse the byte order of a 32-bit value (big-endian <-> little-endian). */
s32 Ov001SwapEndian32(s32 value) {
    u32 x = (u32) value;
    return ((x << 0x18) & 0xFF000000) | (((x << 8) & 0xFF0000) | ((u8) (x >> 0x18) | ((x >> 8) & 0xFF00)));
}

u16 Ov001SwapEndian16Alt(s32 arg0) {
    return (u16) ((u8) (arg0 >> 8) | (0xFF00 & (arg0 << 8)));
}

/* Reverse the byte order of a 32-bit value (big-endian to little-endian). */
s32 Ov001SwapEndian32Alt(s32 value) {
    u32 x = (u32) value;
    return ((x << 0x18) & 0xFF000000) | (((x << 8) & 0xFF0000) | ((u8) (x >> 0x18) | ((x >> 8) & 0xFF00)));
}

u16 Ov001SwapEndian16(s32 arg0) {
    return (u16) ((u8) (arg0 >> 8) | (0xFF00 & (arg0 << 8)));
}

s32 Ov001StringLength(s8 *arg0) {
    s32 var_r2;

    var_r2 = 0;
    if (*arg0 != 0) {
        do {
            var_r2 += 1;
        } while (*(arg0 + var_r2) != 0);
    }
    return var_r2;
}

#pragma thumb on
/* Return a fresh 16-bit random value for the room protocol: seed the room's
 * random sequence once from the real-time clock, then step it and take its
 * middle bits scaled to 0..0x7FFE. */
u16 Ov001GetRandomSeed(void) {
    s32 GetRtcTime(void *);
    extern s32 gRoomState;
    u32 rtcTime[3];
    u32 seed;
    u32 next;

    if (M2C_FIELD(&gRoomState, s32 *, OV001_ROOM_RANDOM_READY) == 0) {
        seed = 0;
        ((void (*)(void *, s32, s32))Ov001MemClear)(rtcTime, 0, 12);
        if (GetRtcTime(rtcTime) == 0) {
            seed += rtcTime[0] << 10;
            seed += rtcTime[1] << 3;
            seed += rtcTime[2];
        }
        M2C_FIELD(&gRoomState, u32 *, OV001_ROOM_RANDOM_STATE) = seed;
        M2C_FIELD(&gRoomState, u32 *, OV001_ROOM_RANDOM_MUL) = OV001_ROOM_RANDOM_MULTIPLIER;
        M2C_FIELD(&gRoomState, u32 *, OV001_ROOM_RANDOM_ADD) = OV001_ROOM_RANDOM_INCREMENT;
        M2C_FIELD(&gRoomState, s32 *, OV001_ROOM_RANDOM_READY) = 1;
    }
    next = M2C_FIELD(&gRoomState, u32 *, OV001_ROOM_RANDOM_MUL) * M2C_FIELD(&gRoomState, u32 *, OV001_ROOM_RANDOM_STATE) + M2C_FIELD(&gRoomState, u32 *, OV001_ROOM_RANDOM_ADD);
    M2C_FIELD(&gRoomState, u32 *, OV001_ROOM_RANDOM_STATE) = next;
    return ((next >> 16) * 0x7FFF) >> 16;
}
void func_ov001_0216cf8c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}

void func_ov001_0216cf98(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0) = arg0;
    M2C_FIELD(arg1, s16 *, 4) = 1;
}

/* Fill a WFC connection record's code from a length-prefixed room code: clear
 * the record's 32-byte code area, store the code length (at code[0]) and copy
 * the code text that follows it. */
void Ov001_SetConnectionCode(s32 *code, void *record) {
    void FillU16(s32, void *, s32);
    FillU16(0, record + WFC_RECORD_CODE, WFC_RECORD_CODE_BYTES);
    M2C_FIELD(record, u16 *, WFC_RECORD_CODE_LEN) = *code;
    MI_CpuCopy8((s32)(code + 1), (s32)(record + WFC_RECORD_CODE), M2C_FIELD(record, u16 *, WFC_RECORD_CODE_LEN));
}

#pragma thumb on
void func_ov001_0216d050(s32 *arg0, M2C_UNK arg1, s32 arg2) {
    void func_ov001_0216cfa0(M2C_UNK, void *);
    *arg0 = arg2;
    func_ov001_0216cfa0(arg1, arg0 + 1);
}
#pragma thumb on

void func_ov001_0216d060(s32 arg0) {
 void OS_SendMessage(void *, s32, s32);
 extern s32 gWhConnTaskQueue;
 OS_SendMessage(&gWhConnTaskQueue, arg0, 0);
}

void func_ov001_0216d074(s32 arg0) {
 void OS_SendMessage(void *, s32, s32);
 extern s32 gWhConnTaskQueue;
 OS_SendMessage(&gWhConnTaskQueue, arg0, 0);
}

/* After WhConnTaskProcessLinkStep reports that a WFC link step was queued, wait
 * for the connection task's next message and report success (0) only when it is
 * the link-status notification.  Returns -1 when no step was queued or the
 * message is another event. */
s32 WhConnTaskReceiveLinkStatus(void) {
    s32 OS_ReceiveMessage(void *, s32 *, s32);
    extern s32 gWhConnTaskQueue;
    s32 message;
    s32 result = -1;
    s32 keepPolling;
    if (WhConnTaskProcessLinkStep()) {
        do {
            OS_ReceiveMessage(&gWhConnTaskQueue, &message, 1);
            if (message == WH_MSG_LINK_STATUS) {
                keepPolling = 0;
                result = keepPolling;
            } else {
                keepPolling = 0;
            }
        } while (keepPolling != 0);
    }
    return result;
}

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma thumb on
s32 func_ov001_0216d394(void *arg0,s32 *arg1){
 s32 OS_ReceiveMessage(void *,s32 *,s32);void InitTimer(void *);void ScheduleTimer(void *,s32,s32,void *,s32);void CancelTimer(void *);
 void MI_CpuFill8(s32,u8);void WFC_ClearPlayerList(void);
 s32 func_ov001_0216d8e4(s32,void *,s32,s32);
 extern s32 gWhConnTaskQueue,gWhConnRecord,data_ov001_021926e0;
 u32 timer[11];s32 msg;s32 result,tries,bound,i,active,flags,ready;u8 *packet;s32 offset;u16 *rx; void *p;
 active=1;p=arg0;result=active-2;ready=0;
 if(M2C_FIELD(p,s32 *,0x24)==0)flags=0x80000;
 else if(M2C_FIELD(p,s32 *,0x24)==1)flags=0xc0000;
 flags|=0x30000;
 ((void (*)(s32,s32,s32))MI_CpuFill8)((s32)&data_ov001_021926e0,0,96);
 if(M2C_FIELD(p,s32 *,40)==5)M2C_FIELD(&data_ov001_021926e0,u8 *,0)=1;
 else if(M2C_FIELD(p,s32 *,40)==13)M2C_FIELD(&data_ov001_021926e0,u8 *,0)=2;
 else if(M2C_FIELD(p,s32 *,40)==16)M2C_FIELD(&data_ov001_021926e0,u8 *,0)=3;
 else return -1;
 packet=(u8 *)&data_ov001_021926e0;
 packet[1]=ready;
 MI_CpuCopy8((s32)((u8 *)p+44),(s32)&packet[2+20*ready],M2C_FIELD(p,s32 *,40));
 WFC_ClearPlayerList();
 if(func_ov001_0216d8e4(0,(u8 *)p+4,M2C_FIELD(p,s32 *,0),0x30bffe)){
 tries=0;InitTimer(timer);ScheduleTimer(timer,0x3fec42,0,(void *)func_ov001_0216d074,18);
 goto test;
 do {
 OS_ReceiveMessage(&gWhConnTaskQueue,&msg,1);
 switch(msg){
 case 19:goto bottom;
 case 18:if(ready)goto test;
 active=0;
 bottom:continue;
 case 5:if(ready)break;
 CancelTimer(timer);
 if(Ov001_CopyPlayerRecords((s32)&gWhConnRecord,1)!=1){active=0;break;}
 Ov001_SetConnectionCode(p,&gWhConnRecord);
 i=0;bound=*(u16 *)((s32)&gWhConnRecord + 10);for(;i<bound;i++){}
 if(!WhConnTaskStartConnection((s32)&gWhConnRecord,(s32)&data_ov001_021926e0,flags)){active=0;break;}
 ready=1;break;
 case 10:
 Ov001_SetConnectionCode(p,&gWhConnRecord);
 if(!WhConnTaskStartConnection((s32)&gWhConnRecord,(s32)&data_ov001_021926e0,flags))active=0;
 break;
 case 12:active=0;result=0;break;
 case 13:
 if(++tries<3){if(!WhConnTaskStartConnection((s32)&gWhConnRecord,(s32)&data_ov001_021926e0,flags))active=0;}else active=0;
 break;
 case 4:case 8:break;
 default:active=0;break;
 } next:; test:; }while(active);
 CancelTimer(timer);
 while(OS_ReceiveMessage(&gWhConnTaskQueue,&msg,0)==1){}
 }
 func_ov001_0216d050(arg1,(s32)&gWhConnRecord,result==0);
 return result;
}
#pragma pop
void func_ov001_0216d564(void) {
    void SleepMilliseconds(void);
    SleepMilliseconds();
}

s32 func_ov001_0216d56c(s32 a){extern s32 (*data_ov001_021925e0)(s32);void (*f)(s32)=M2C_FIELD(&data_ov001_021925e0,void (**)(s32),4);if(f)f(a);return 0;}

/* Lock the WFC player list and copy up to maxRecords of its 0xC0-byte
 * connection records into dest, then unlock it.  Returns the total number of
 * players in the list. */
s32 Ov001_CopyPlayerRecords(s32 dest, s32 maxRecords) {
    M2C_UNK MIi_CpuCopy32(s32, s32, M2C_UNK);
    s32 WFC_GetPlayerListCount();
    M2C_UNK WFC_SetDataLock(M2C_UNK);
    s32 WFC_GetPlayerRecordByIndex(u16);
    s32 count;
    s32 index;
    s32 destPtr;

    destPtr = dest;
    WFC_SetDataLock(1);
    count = WFC_GetPlayerListCount();
    if (count > 0) {
        index = 0;
        if (count > 0) {
loop_2:
            if (index < maxRecords) {
                MIi_CpuCopy32(WFC_GetPlayerRecordByIndex((u16) index), destPtr, 0xC0);
                index += 1;
                destPtr += 0xC0;
                if (index < count) {
                    goto loop_2;
                }
            }
        }
    }
    WFC_SetDataLock(0);
    return count;
}

/* If the WH connection task is waiting on the WFC connect/match process, poll it
 * under an interrupt lock; once it queues a step, move the task to the next phase
 * and report that a step was started. */
s32 WhConnTaskProcessConnectStep(void) {
    s32 interruptState = OS_DisableInterrupts();
    if (M2C_FIELD(&gWhConnTaskState, s32 *, WH_TASK_PHASE) == 5 && WFC_ProcessConnectOrMatch(0, 0, 0) == 3) {
        M2C_FIELD(&gWhConnTaskState, s32 *, WH_TASK_PHASE) = 4;
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    OS_RestoreInterrupts(interruptState);
    return 0;
}

/* If the WH connection task is in the link phase and its WFC link step was
 * queued, move the task on to the queued-step phase and report that a step was
 * started.  Runs under an interrupt lock. */
s32 WhConnTaskProcessLinkStep(void) {
    s32 interruptState = OS_DisableInterrupts();

    if (M2C_FIELD(&gWhConnTaskState, s32 *, WH_TASK_PHASE) == WH_PHASE_LINK &&
        WFC_ProcessLinkStep() == WH_WFC_STEP_QUEUED) {
        M2C_FIELD(&gWhConnTaskState, s32 *, WH_TASK_PHASE) = WH_PHASE_WFC_STEP_QUEUED;
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    OS_RestoreInterrupts(interruptState);
    return 0;
}

/* WH connection-task start step: while the connection phase is ready to connect,
 * start the wireless (WM) step; otherwise advance the task's current connection
 * state.  On success the phase moves to 2, so the started step is not begun
 * again, and 1 is returned; 0 while it still has to be retried. */
s32 WhConnTaskBeginConnection(void) {
    s32 interruptState = OS_DisableInterrupts();

    if (M2C_FIELD(&gWhConnTaskState, s32 *, WH_TASK_PHASE) == WH_PHASE_READY_TO_CONNECT) {
        if (WFC_StartWirelessStep() != WH_WFC_STEP_QUEUED) {
            OS_RestoreInterrupts(interruptState);
            return 0;
        }
        M2C_FIELD(&gWhConnTaskState, s32 *, WH_TASK_PHASE) = WH_PHASE_STEP_QUEUED;
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    if (WhConnTaskAdvance() == 1) {
        M2C_FIELD(&gWhConnTaskState, s32 *, WH_TASK_PHASE) = WH_PHASE_STEP_QUEUED;
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    OS_RestoreInterrupts(interruptState);
    return 0;
}

/* Stage the host descriptor and connection settings for the WH connection task,
 * then queue the connection or the prerequisite step it waits for: 1 once a step
 * is queued, 0 while it has to be retried. */
s32 WhConnTaskStartConnection(s32 hostDescriptor,s32 settings,s32 connectionFlags){
s32 interruptState=OS_DisableInterrupts();
M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_CONNECT_FLAGS)=connectionFlags;
if(settings)MI_CpuCopy8(settings,M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_SETTINGS),WH_TASK_SETTINGS_BYTES);
else MI_CpuFill8(M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_SETTINGS),0,WH_TASK_SETTINGS_BYTES);
MIi_CpuCopy32(hostDescriptor,M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_BSS_DESC),WH_BSS_DESC_BYTES);
if(WhConnTaskAdvance()==1){M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_PHASE)=WH_PHASE_CONNECT_PENDING;OS_RestoreInterrupts(interruptState);return 1;}
if(M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_PHASE)==WH_PHASE_READY_TO_CONNECT && WFC_StartConnection(M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_BSS_DESC),M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_SETTINGS),M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_CONNECT_FLAGS))==WH_WFC_STEP_QUEUED){M2C_FIELD(&gWhConnTaskState,s32 *,WH_TASK_PHASE)=WH_PHASE_CONNECT_PENDING;OS_RestoreInterrupts(interruptState);return 1;}
OS_RestoreInterrupts(interruptState);return 0;
}

