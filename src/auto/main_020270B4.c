/* 16 functions from 0x020270B4 to 0x02028038 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
extern s32 gWfcSession;
void WFC_FillRequest(s32, void *, s32);
s32 OS_DisableInterrupts(void);
void OS_RestoreInterrupts(s32);
void WFC_SetState(s32);

void WFC_InitSessionStatus(void);
/* Sets up the WFC session on a caller-provided buffer.  The buffer must be
 * 32-byte aligned and at least 0x2300 bytes long, and only one session can exist
 * at a time.  The session's state, send path, status word and timer list are
 * initialised; 0 is returned once the session is ready. */
s32 WFC_InitSession(void *buffer, u32 size) {
    s32 irq = OS_DisableInterrupts();
    if (gWfcSession) { OS_RestoreInterrupts(irq); return 1; }
    if (!buffer) { OS_RestoreInterrupts(irq); return 1; }
    if ((u32)buffer & 31) { OS_RestoreInterrupts(irq); return 1; }
    if (size < 0x2300) { OS_RestoreInterrupts(irq); return 6; }
    gWfcSession = (s32)buffer;
    M2C_FIELD(buffer, s32 *, WFC_SESSION_STATE) = 1;
    M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_SUBSTATE) = 0;
    M2C_FIELD((void *)gWfcSession, u16 *, 0x2268) = 0;
    M2C_FIELD((void *)gWfcSession, u8 *, 0x226a) = 0;
    M2C_FIELD((void *)gWfcSession, u8 *, WFC_SESSION_ABORT) = 0;
    M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_ERROR) = 0;
    M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_RESULT) = 0;
    WFC_InitSessionStatus(); WFC_InitSendState();
    if (!IsSystemTickInitialized()) InitSystemTick();
    if (!func_02007180()) func_02007140();
    InitTimer((void *)(gWfcSession + WFC_SESSION_TIMER));
    OS_RestoreInterrupts(irq); return 0;
}

/* Release the WFC session: only a session that has merely been started can be
 * dropped. Returns 0 once gWfcSession has been cleared, 1 when there is no
 * session or it is already past WFC_SESSION_STATE_STARTED. */
s32 Wfc_ReleaseSession(void) {
    s32 irq = OS_DisableInterrupts();
    void *session = (void *)gWfcSession;

    if (!session) { OS_RestoreInterrupts(irq); return 1; }
    if (M2C_FIELD(session, s32 *, WFC_SESSION_STATE) != WFC_SESSION_STATE_STARTED) {
        OS_RestoreInterrupts(irq);
        return 1;
    }
    gWfcSession = 0;
    OS_RestoreInterrupts(irq);
    return 0;
}

/* One step of the WFC session's connection startup: queues the send request,
 * verifies the wireless link and starts hosting/joining with the operation
 * callback installed. Returns the shared step status (3 = still running). */
s32 WFC_ConnectStep(void *request, s32 callback) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void WFC_SetRequest(void *, s32);
    void WFC_SetState(s32);
    s32 WFC_InitCommandChannel(s32, s32);
    s32 WFC_SetGeneralHandler(s32);
    s32 WFC_OpenLink(void *);
    u16 WFC_GetPlayerMask(void);
    s32 WFC_ShutdownCommandChannel(void);
    void WFC_ProcessPeerStatusEvent(void);
    void WFC_OperationCallback(void);
    extern s32 gWfcSession;
    s32 irq = OS_DisableInterrupts();
    void *session = (void *)gWfcSession;

    if (!session) {
        OS_RestoreInterrupts(irq);
        return 1;
    }
    switch (M2C_FIELD(session, s32 *, WFC_SESSION_STATE)) {
    case 1:
        WFC_SetRequest(request, callback);
        break;
    case 2:
        OS_RestoreInterrupts(irq);
        return 2;
    case 3:
        OS_RestoreInterrupts(irq);
        return 0;
    default:
        OS_RestoreInterrupts(irq);
        return 1;
    }
    switch (WFC_InitCommandChannel(gWfcSession, (u16)M2C_FIELD((void *)gWfcSession, u32 *, WFC_SESSION_REQUEST))) {
    case 3:
        WFC_SetState(11);
        OS_RestoreInterrupts(irq);
        return 7;
    case 4:
        OS_RestoreInterrupts(irq);
        return 5;
    case 1:
    case 2:
    case 5:
    case 6:
    default:
        WFC_SetState(11);
        OS_RestoreInterrupts(irq);
        return 7;
    case 0:
        break;
    }
    if (WFC_GetPlayerMask() == 0) {
        if (WFC_ShutdownCommandChannel() != 0) {
            WFC_SetState(11);
            OS_RestoreInterrupts(irq);
            return 7;
        }
        OS_RestoreInterrupts(irq);
        return 5;
    }
    if (WFC_SetGeneralHandler((s32)WFC_ProcessPeerStatusEvent) != 0) {
        WFC_SetState(11);
        OS_RestoreInterrupts(irq);
        return 7;
    }
    switch (WFC_OpenLink((void *)WFC_OperationCallback)) {
    case 2:
        WFC_SetState(2);
        M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_SUBSTATE) = 1;
        break;
    case 8:
        WFC_SetState(12);
        OS_RestoreInterrupts(irq);
        return 1;
    case 3:
    default:
        WFC_SetState(11);
        OS_RestoreInterrupts(irq);
        return 7;
    }
    OS_RestoreInterrupts(irq);
    return 3;
}

void WFC_OperationCallback(void);
/* Step run while the WFC session is ready: queues the wireless start command with
 * the operation callback and moves the session to WFC_SESSION_STATE_WIRELESS.
 * Returns 3 (progressed), 2 when that command is already running, 0 when the
 * session has only started, and 1 in any other state or without a session. */
s32 WFC_StartWirelessStep(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void WFC_SetState(s32);
    void WFC_OperationCallback(void);
    s32 WFC_StartWireless(M2C_UNK);
    s32 irq = OS_DisableInterrupts();
    void *session = (void *)gWfcSession;
    s32 result;

    if (session == 0) {
        OS_RestoreInterrupts(irq);
        return 1;
    }
    switch (M2C_FIELD(session, s32 *, WFC_SESSION_STATE)) {
    case WFC_SESSION_STATE_WIRELESS:
        OS_RestoreInterrupts(irq);
        return 2;
    case WFC_SESSION_STATE_STARTED:
        OS_RestoreInterrupts(irq);
        return 0;
    default:
        OS_RestoreInterrupts(irq);
        return 1;
    case WFC_SESSION_STATE_READY:
        result = WFC_StartWireless((M2C_UNK)WFC_OperationCallback);
        switch (result) {
        case 2:
            WFC_SetState(WFC_SESSION_STATE_WIRELESS);
            M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_SUBSTATE) = 2;
            break;
        case 8:
            OS_RestoreInterrupts(irq);
            return 4;
        case 3:
        default:
            WFC_SetState(WFC_SESSION_STATE_ERROR);
            OS_RestoreInterrupts(irq);
            return 7;
        }
        break;
    }
    OS_RestoreInterrupts(irq);
    return 3;
}

void WFC_ProcessConnectOrMatch(s32 a,s32 b){s32 WFC_ProcessConnectStep(void); s32 WFC_SubmitMatchRequest(); if(a==0 || b==0)WFC_ProcessConnectStep();else WFC_SubmitMatchRequest();}

void WFC_ProcessCallback(void);
/* Fills the local player's match request from the friend code, name and status
 * bits and submits it: in the connected state it flushes the request buffer and
 * sends the packet, while in the waiting states it only stages the request.
 * Returns the shared WFC progress code (3 = sent, 1 = wrong session state,
 * 4/7 = send result). */
s32 WFC_SubmitMatchRequest(s32 friendCode,s32 playerName,s32 statusBits){
s32 s=OS_DisableInterrupts();void *p=(void *)gWfcSession;
if(!p){OS_RestoreInterrupts(s);return 1;}
switch(M2C_FIELD(p,s32 *,WFC_SESSION_STATE)){
case 5:WFC_FillRequest(friendCode,playerName,statusBits);OS_RestoreInterrupts(s);return 2;
case 6:WFC_FillRequest(friendCode,playerName,statusBits);OS_RestoreInterrupts(s);return 0;
default:OS_RestoreInterrupts(s);return 1;
case 3:break;
}
WFC_FillRequest(friendCode,playerName,statusBits);
DC_InvalidateRange(M2C_FIELD((void *)gWfcSession,s32 *,WFC_SESSION_PACKET_BUFFER),M2C_FIELD((void *)gWfcSession,u16 *,WFC_SESSION_PACKET_SIZE));
M2C_FIELD((void *)gWfcSession,s32 *,WFC_SESSION_SEND_COUNT)++;
switch(WFC_SendRequestPacket((M2C_UNK)WFC_ProcessCallback,gWfcSession+WFC_SESSION_PACKET)){
case 2:WFC_SetState(5);M2C_FIELD((void *)gWfcSession,u16 *,WFC_SESSION_SUBSTATE)=3;break;
case 8:OS_RestoreInterrupts(s);return 4;
case 3:default:WFC_SetState(11);OS_RestoreInterrupts(s);return 7;
}
OS_RestoreInterrupts(s);return 3;
}

/* One step of the WFC session in its connect phase (state 6): moves the session on
 * to state 7 with substep 4 (the match is settled and the connection opens) and
 * reports 3, its "progressed" code.  Returns 2 when the session is already past
 * that phase, 0 while it is back in its ready state (3), and 1 when there is no
 * session at all or it is in none of those states. */
s32 WFC_ProcessConnectStep(void) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void WFC_SetState(s32); extern M2C_UNK gWfcSession;
s32 irq=OS_DisableInterrupts();
if(M2C_FIELD(&gWfcSession,M2C_UNK *,0)==0){OS_RestoreInterrupts(irq);return 1;}
switch(M2C_FIELD(M2C_FIELD(&gWfcSession,M2C_UNK *,0),s32 *,WFC_SESSION_STATE)){
case 6: WFC_SetState(7);M2C_FIELD(M2C_FIELD(&gWfcSession,M2C_UNK *,0),u16 *,WFC_SESSION_SUBSTATE)=4;break;
case 7:OS_RestoreInterrupts(irq);return 2;
case 3:OS_RestoreInterrupts(irq);return 0;
default:OS_RestoreInterrupts(irq);return 1;
}
OS_RestoreInterrupts(irq);return 3;
}

/* Starts the WFC connection: while the session is in the ready state, checks
 * the local player's connection data and match settings, copies them into the
 * session and sends the connection request (operation 0x1D); advances the
 * session state and returns its progress code. */
s32 WFC_StartConnection(void *connData, void *settings, s32 flags) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void MI_CpuFill8(void *, u32, u32);
    void MI_CpuCopy8(void *, void *, u32);
    u32 WFC_SetStatusBits(u32);
    void WFC_SetState(s32);
    void WFC_OperationCallback(void);
    s32 WFC_SubmitConnectRequest(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16);
    s32 irq = OS_DisableInterrupts();
    void *session = (void *)gWfcSession;
    s32 state;
    if (session == 0) {
        OS_RestoreInterrupts(irq);
        return 1;
    }
    state = M2C_FIELD(session, s32 *, WFC_SESSION_STATE);
    switch (state) {
    case 3:
        if (connData == 0) {
            OS_RestoreInterrupts(irq);
            return 1;
        }
        if (M2C_FIELD(connData, u16 *, 0x3c) != 0) {
            OS_RestoreInterrupts(irq);
            return 1;
        }
        if (settings != 0) {
            if (M2C_FIELD(settings, u8 *, 0) >= 4 || M2C_FIELD(settings, u8 *, 1) >= 4) {
                OS_RestoreInterrupts(irq);
                return 1;
            }
            M2C_FIELD((void *)gWfcSession, u8 *, WFC_SESSION_MODE) = M2C_FIELD(settings, u8 *, 0);
            M2C_FIELD((void *)gWfcSession, u8 *, WFC_SESSION_SUBMODE) = M2C_FIELD(settings, u8 *, 1);
            if (M2C_FIELD((void *)gWfcSession, u8 *, WFC_SESSION_MODE) == 0) {
                MI_CpuFill8((void *)((char *)gWfcSession + WFC_SESSION_NAME), 0, WFC_SESSION_NAME_LEN);
            } else {
                MI_CpuCopy8((void *)((char *)settings + 2), (void *)((char *)gWfcSession + WFC_SESSION_NAME), WFC_SESSION_NAME_LEN);
            }
        } else {
            MI_CpuFill8((void *)((char *)gWfcSession + WFC_SESSION_NAME), 0, 0x52);
        }
        MI_CpuCopy8(connData, (void *)((char *)gWfcSession + WFC_SESSION_CONN_DATA), 0xc0);
        {
            u16 status = M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_CONN_FLAGS);
            status |= 3;
            M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_CONN_STATUS) = status;
        }
        WFC_SetStatusBits((u32)flags);
        break;
    case 8:
        OS_RestoreInterrupts(irq);
        return 2;
    case 9:
        OS_RestoreInterrupts(irq);
        return 0;
    default:
        OS_RestoreInterrupts(irq);
        return 1;
    }        {
            s32 result = WFC_SubmitConnectRequest((M2C_UNK)WFC_OperationCallback, (M2C_UNK)0xffff, 0x50, 0xffff, (u16)0xffff);
            switch (result) {
            case 2:
                WFC_SetState(8);
                M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_SUBSTATE) = 5;
                break;
            case 8:
                OS_RestoreInterrupts(irq);
                return 4;
            case 3:
            default:
                WFC_SetState(0xb);
                OS_RestoreInterrupts(irq);
                return 7;
            }
        }
        OS_RestoreInterrupts(irq);
        return 3;

}

void WFC_ProcessLinkCallback(void);
/* One step of the WFC session while it waits to exchange packets with the other
 * player (state 9): once the session has been aborted it moves straight to the
 * connected state (10), otherwise it starts the link operation and reports the
 * outcome (3 = still running, 4 = busy, 7 = error). */
s32 WFC_ProcessLinkStep(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void WFC_SetState(s32);
    s32 WFC_SubmitLinkRequest(void *);
    void WFC_ProcessLinkCallback(void);
    s32 irq;
    void *session;
    s32 result;

    irq = OS_DisableInterrupts();
    session = (void *)gWfcSession;
    if (session == 0) {
        OS_RestoreInterrupts(irq);
        return 1;
    }
    switch (M2C_FIELD(session, s32 *, WFC_SESSION_STATE)) {
    case 10:
        OS_RestoreInterrupts(irq);
        return 2;
    case 3:
        OS_RestoreInterrupts(irq);
        return 0;
    default:
        OS_RestoreInterrupts(irq);
        return 1;
    case 9:
        if (M2C_FIELD(session, u8 *, WFC_SESSION_ABORT) == 1) {
            WFC_SetState(10);
            M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_SUBSTATE) = 6;
        } else {
            result = WFC_SubmitLinkRequest((void *)WFC_ProcessLinkCallback);
            switch (result) {
            case 2:
                WFC_SetState(10);
                M2C_FIELD((void *)gWfcSession, u16 *, WFC_SESSION_SUBSTATE) = 6;
                break;
            case 8:
                OS_RestoreInterrupts(irq);
                return 4;
            case 3:
            default:
                WFC_SetState(11);
                OS_RestoreInterrupts(irq);
                return 7;
            }
        }
        break;
    }
    OS_RestoreInterrupts(irq);
    return 3;
}

/* One step of the WFC session while it waits for the DWC link: reads the link
 * state, starts hosting or joining, and moves the session to the next state
 * (or to the error/finished state on failure). */
s32 WFC_ProcessLinkState(void){
u16 *func_02011910(void);
M2C_UNK DC_InvalidateRange();
s32 WFC_ShutdownCommandChannel(void);
s32 WFC_SendCommand4(void *);
s32 WFC_StartWireless(M2C_UNK);
s32 func_02012274(void *);
void WFC_OperationCallback(void);
void func_02028ef4(void);
s32 irq=OS_DisableInterrupts();
void *session=(void *)gWfcSession;
u16 *linkState;
s32 result;
if(!session){OS_RestoreInterrupts(irq);return 1;}
switch(M2C_FIELD(session,s32 *,WFC_SESSION_STATE)){
case 13:OS_RestoreInterrupts(irq);return 2;
case 1:OS_RestoreInterrupts(irq);return 0;
case 6:
WFC_SetState(13);M2C_FIELD((void *)gWfcSession,u16 *,WFC_SESSION_SUBSTATE)=9;
OS_RestoreInterrupts(irq);return 3;
case 3:case 9:case 12:break;
default:OS_RestoreInterrupts(irq);return 1;
}
if(M2C_FIELD(session,u8 *,WFC_SESSION_ABORT)==1){
WFC_SetState(13);M2C_FIELD((void *)gWfcSession,u16 *,WFC_SESSION_SUBSTATE)=9;
}else{
linkState=func_02011910();
DC_InvalidateRange(linkState,2);
switch(*linkState){
case 0:
if((result=WFC_ShutdownCommandChannel())==0){
WFC_SetState(1);M2C_FIELD((void *)gWfcSession,u16 *,WFC_SESSION_SUBSTATE)=0;
OS_RestoreInterrupts(irq);return 0;
}
break;
case 1:result=WFC_SendCommand4(WFC_OperationCallback);break;
case 2:result=WFC_StartWireless((M2C_UNK)WFC_OperationCallback);break;
default:M2C_FIELD((void *)gWfcSession,u8 *,WFC_SESSION_ABORT)=1;
result=func_02012274(func_02028ef4);
break;
}
switch(result){
case 2:WFC_SetState(13);M2C_FIELD((void *)gWfcSession,u16 *,WFC_SESSION_SUBSTATE)=9;break;
case 8:OS_RestoreInterrupts(irq);return 4;
case 3:default:WFC_SetState(11);OS_RestoreInterrupts(irq);return 7;
}
}
OS_RestoreInterrupts(irq);return 3;
}

s32 Wfc_GetLinkState(void){s32 s=OS_DisableInterrupts();s32 r=0;void *p=(void *)gWfcSession;if(p)r=M2C_FIELD(p,s32 *,0x2260);OS_RestoreInterrupts(s);return r;}

u32 WFC_SetStatusBits(u32 v){
u32 old; s32 s=OS_DisableInterrupts();u32 mask=0;void *p=(void *)gWfcSession;
old=M2C_FIELD(p+0x2000,volatile u32 *,0x264);
if(!p){OS_RestoreInterrupts(s);return 0;}
if(v&0x8000){mask=0x3ffe|mask;if(!(v&0x3ffe))v=0xa082|v;}
if(v&0x20000)mask|=0x10000;
if(v&0x80000)mask|=0x40000;
if(v&0x200000)mask|=0x100000;
if(v&0x800000)mask|=0x400000;
M2C_FIELD(p+0x2000,u32 *,0x264)=v|(old&~mask);
OS_RestoreInterrupts(s);return old;
}

s32 GetSession(void) {
    extern s32 gWfcSession;
    return gWfcSession;
}

void MI_CpuFill8(void *, u32, u32);
void WFC_SetRequest(void *a, s32 b) {
    void MI_CpuFill8(void *, u32, u32);
    if (a == 0) {
        M2C_FIELD((void *)gWfcSession, s32 *, 0x226c) = 3;
        M2C_FIELD((void *)gWfcSession, s32 *, 0x2270) = 0;
        M2C_FIELD((void *)gWfcSession, s32 *, 0x2274) = 0;
        M2C_FIELD((void *)gWfcSession, s32 *, 0x2278) = 0;
        return;
    }
    M2C_FIELD((void *)gWfcSession, u32 *, 0x226c) = M2C_FIELD(a, u32 *, 0) & 3;
    if (((4 - (M2C_FIELD(a, u32 *, 4) & 3)) & 3) + 12 > M2C_FIELD(a, u32 *, 8)) {
        M2C_FIELD((void *)gWfcSession, u32 *, 0x2270) = 0;
        M2C_FIELD((void *)gWfcSession, u32 *, 0x2274) = 0;
    } else {
        M2C_FIELD((void *)gWfcSession, u32 *, 0x2270) = (M2C_FIELD(a, u32 *, 4) + 3) & ~3;
        M2C_FIELD((void *)gWfcSession, u32 *, 0x2274) = M2C_FIELD(a, u32 *, 8) - ((4 - (M2C_FIELD(a, u32 *, 4) & 3)) & 3);
    }
    MI_CpuFill8((void *)M2C_FIELD((void *)gWfcSession, u32 *, 0x2270), 0, M2C_FIELD((void *)gWfcSession, u32 *, 0x2274));
    M2C_FIELD((void *)gWfcSession, u32 *, 0x2278) = M2C_FIELD(a, u32 *, 12);
    M2C_FIELD((void *)gWfcSession, u32 *, 0x227c) = b;
}

void WFC_FillRequest(s32 a, void *b, s32 c) {
    u32 WFC_SetStatusBits(u32);
    u16 WFC_FindFreePlayerSlot(s32);
    u16 GetConsoleLocalId(void);
    void MI_CpuCopy8(void *, void *, u32);
    extern s32 gWfcSession;
    extern u8 data_020ea758[];
    extern u8 data_020ea760[];
    u8 *r4 = (u8 *)b;
    u16 tmp;
    WFC_SetStatusBits((u32)c);
    M2C_FIELD((void *)gWfcSession, void **, 0x2288) = (void *)((s32)gWfcSession + 0x1500);
    M2C_FIELD((void *)gWfcSession, u16 *, 0x228c) = 0x400;
    tmp = WFC_FindFreePlayerSlot(0);
    M2C_FIELD((void *)gWfcSession, u16 *, 0x228e) = (u16)(((s32)1 << tmp) >> 1);
    if (M2C_FIELD((void *)gWfcSession, u16 *, 0x2268) == 0) {
        u16 v = GetConsoleLocalId();
        M2C_FIELD((void *)gWfcSession, u16 *, 0x2290) = v;
        {
            u32 x = M2C_FIELD((void *)gWfcSession, u32 *, 0x2264);
            M2C_FIELD((void *)gWfcSession, u16 *, 0x2298) = (x & 0x300000) != 0x300000 ? 1 : 0;
        }
    }
    if (a == 0) {
        MI_CpuCopy8((void *)data_020ea758, (void *)((u8 *)gWfcSession + 0x2292), 6);
    } else {
        MI_CpuCopy8((void *)a, (void *)((u8 *)gWfcSession + 0x2292), 6);
    }
    if (b == 0 || b == data_020ea760) {
        MI_CpuCopy8((void *)data_020ea760, (void *)((u8 *)gWfcSession + 0x229c), 0x20);
        M2C_FIELD((void *)gWfcSession, u16 *, 0x229a) = 0;
    } else {
        s32 i;
        MI_CpuCopy8((void *)b, (void *)((u8 *)gWfcSession + 0x229c), 0x20);
        i = 0;
        do {
            if (*r4 == 0) break;
            i++;
            r4++;
        } while (i < 0x20);
        M2C_FIELD((void *)gWfcSession, u16 *, 0x229a) = (u16)i;
    }
    M2C_FIELD((void *)gWfcSession, u32 *, 0x2284) = 0;
}

void WFC_InitSessionStatus(void){M2C_FIELD((void *)gWfcSession,u32 *,0x2264)=0xaaa082;}

