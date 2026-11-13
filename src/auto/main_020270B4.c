/* 16 functions from 0x020270B4 to 0x02028038 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
extern s32 gSession;
void WFC_FillRequest(s32, void *, s32);
s32 OS_DisableInterrupts(void);
void OS_RestoreInterrupts(s32);
void WFC_SetState(s32);

void func_02028018(void);
s32 func_020270b4(void *p,u32 size) {
s32 s=OS_DisableInterrupts();
if(gSession){OS_RestoreInterrupts(s);return 1;}
if(!p){OS_RestoreInterrupts(s);return 1;}
if((u32)p&31){OS_RestoreInterrupts(s);return 1;}
if(size<0x2300){OS_RestoreInterrupts(s);return 6;}
gSession=(s32)p;
M2C_FIELD(p,s32 *,0x2260)=1;
M2C_FIELD((void *)gSession,u16 *,0x2280)=0;
M2C_FIELD((void *)gSession,u16 *,0x2268)=0;
M2C_FIELD((void *)gSession,u8 *,0x226a)=0;
M2C_FIELD((void *)gSession,u8 *,0x226b)=0;
M2C_FIELD((void *)gSession,u16 *,0x2282)=0;
M2C_FIELD((void *)gSession,u16 *,0x22f8)=0;
func_02028018();func_020296a0();
if(!func_02006f8c())func_02006f14();
if(!func_02007180())func_02007140();
func_02007190((void *)(gSession+0x22cc));
OS_RestoreInterrupts(s);return 0;
}

s32 func_020271cc(void){s32 s=OS_DisableInterrupts(); void *p=(void *)gSession; if(!p){OS_RestoreInterrupts(s);return 1;} if(M2C_FIELD(p,s32 *,0x2260)!=1){OS_RestoreInterrupts(s);return 1;} gSession=0;OS_RestoreInterrupts(s);return 0;}

/* One step of the WFC session's connection startup: queues the send request,
 * verifies the wireless link and starts hosting/joining with the operation
 * callback installed. Returns the shared step status (3 = still running). */
s32 WFC_ConnectStep(void *request, s32 callback) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void WFC_SetRequest(void *, s32);
    void WFC_SetState(s32);
    s32 func_02011034(s32, s32);
    s32 func_020119dc(s32);
    s32 func_020120f8(void *);
    u16 func_02011d58(void);
    s32 func_02011244(void);
    void func_0202830c(void);
    void WFC_OperationCallback(void);
    extern s32 gSession;
    s32 irq = OS_DisableInterrupts();
    void *session = (void *)gSession;

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
    switch (func_02011034(gSession, (u16)M2C_FIELD((void *)gSession, u32 *, WFC_SESSION_REQUEST))) {
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
    if (func_02011d58() == 0) {
        if (func_02011244() != 0) {
            WFC_SetState(11);
            OS_RestoreInterrupts(irq);
            return 7;
        }
        OS_RestoreInterrupts(irq);
        return 5;
    }
    if (func_020119dc((s32)func_0202830c) != 0) {
        WFC_SetState(11);
        OS_RestoreInterrupts(irq);
        return 7;
    }
    switch (func_020120f8((void *)WFC_OperationCallback)) {
    case 2:
        WFC_SetState(2);
        M2C_FIELD((void *)gSession, u16 *, WFC_SESSION_SUBSTATE) = 1;
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
s32 func_02027428(void) {
    s32 s = OS_DisableInterrupts();
    void *p = (void *)gSession;
    s32 v;
    s32 r;

    if (p == 0) {
        OS_RestoreInterrupts(s);
        return 1;
    }
    v = M2C_FIELD(p, s32 *, 0x2260);
    switch (v) {
    case 1:
        OS_RestoreInterrupts(s);
        return 1;
    case 3:
        r = func_020121d8((M2C_UNK)WFC_OperationCallback);
        switch (r) {
        case 2:
            WFC_SetState(4);
            M2C_FIELD((void *)gSession, u16 *, 0x2280) = 2;
            OS_RestoreInterrupts(s);
            return 3;
        case 8:
            OS_RestoreInterrupts(s);
            return 4;
        case 3:
        default:
            WFC_SetState(0xB);
            OS_RestoreInterrupts(s);
            return 7;
        }
    case 4:
        OS_RestoreInterrupts(s);
        return 2;
    default:
        OS_RestoreInterrupts(s);
        return 0;
    }
}

void func_02027518(s32 a,s32 b){s32 func_020276b0(void); s32 WFC_SubmitMatchRequest(); if(a==0 || b==0)func_020276b0();else WFC_SubmitMatchRequest();}

void WFC_ProcessCallback(void);
/* Fills the local player's match request from the friend code, name and status
 * bits and submits it: in the connected state it flushes the request buffer and
 * sends the packet, while in the waiting states it only stages the request.
 * Returns the shared WFC progress code (3 = sent, 1 = wrong session state,
 * 4/7 = send result). */
s32 WFC_SubmitMatchRequest(s32 friendCode,s32 playerName,s32 statusBits){
s32 s=OS_DisableInterrupts();void *p=(void *)gSession;
if(!p){OS_RestoreInterrupts(s);return 1;}
switch(M2C_FIELD(p,s32 *,WFC_SESSION_STATE)){
case 5:WFC_FillRequest(friendCode,playerName,statusBits);OS_RestoreInterrupts(s);return 2;
case 6:WFC_FillRequest(friendCode,playerName,statusBits);OS_RestoreInterrupts(s);return 0;
default:OS_RestoreInterrupts(s);return 1;
case 3:break;
}
WFC_FillRequest(friendCode,playerName,statusBits);
DC_InvalidateRange(M2C_FIELD((void *)gSession,s32 *,WFC_SESSION_PACKET_BUFFER),M2C_FIELD((void *)gSession,u16 *,WFC_SESSION_PACKET_SIZE));
M2C_FIELD((void *)gSession,s32 *,WFC_SESSION_SEND_COUNT)++;
switch(WFC_SendRequestPacket((M2C_UNK)WFC_ProcessCallback,gSession+WFC_SESSION_PACKET)){
case 2:WFC_SetState(5);M2C_FIELD((void *)gSession,u16 *,WFC_SESSION_SUBSTATE)=3;break;
case 8:OS_RestoreInterrupts(s);return 4;
case 3:default:WFC_SetState(11);OS_RestoreInterrupts(s);return 7;
}
OS_RestoreInterrupts(s);return 3;
}

s32 func_020276b0(void) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void WFC_SetState(s32); extern M2C_UNK gSession;
s32 r=OS_DisableInterrupts();
if(M2C_FIELD(&gSession,M2C_UNK *,0)==0){OS_RestoreInterrupts(r);return 1;}
switch(M2C_FIELD(M2C_FIELD(&gSession,M2C_UNK *,0),s32 *,0x2260)){
case 6: WFC_SetState(7);M2C_FIELD(M2C_FIELD(&gSession,M2C_UNK *,0),u16 *,0x2280)=4;break;
case 7:OS_RestoreInterrupts(r);return 2;
case 3:OS_RestoreInterrupts(r);return 0;
default:OS_RestoreInterrupts(r);return 1;
}
OS_RestoreInterrupts(r);return 3;
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
    s32 func_02013d4c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16);
    s32 irq = OS_DisableInterrupts();
    void *session = (void *)gSession;
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
            M2C_FIELD((void *)gSession, u8 *, WFC_SESSION_MODE) = M2C_FIELD(settings, u8 *, 0);
            M2C_FIELD((void *)gSession, u8 *, WFC_SESSION_SUBMODE) = M2C_FIELD(settings, u8 *, 1);
            if (M2C_FIELD((void *)gSession, u8 *, WFC_SESSION_MODE) == 0) {
                MI_CpuFill8((void *)((char *)gSession + WFC_SESSION_NAME), 0, WFC_SESSION_NAME_LEN);
            } else {
                MI_CpuCopy8((void *)((char *)settings + 2), (void *)((char *)gSession + WFC_SESSION_NAME), WFC_SESSION_NAME_LEN);
            }
        } else {
            MI_CpuFill8((void *)((char *)gSession + WFC_SESSION_NAME), 0, 0x52);
        }
        MI_CpuCopy8(connData, (void *)((char *)gSession + WFC_SESSION_CONN_DATA), 0xc0);
        {
            u16 status = M2C_FIELD((void *)gSession, u16 *, WFC_SESSION_CONN_FLAGS);
            status |= 3;
            M2C_FIELD((void *)gSession, u16 *, WFC_SESSION_CONN_STATUS) = status;
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
            s32 result = func_02013d4c((M2C_UNK)WFC_OperationCallback, (M2C_UNK)0xffff, 0x50, 0xffff, (u16)0xffff);
            switch (result) {
            case 2:
                WFC_SetState(8);
                M2C_FIELD((void *)gSession, u16 *, WFC_SESSION_SUBSTATE) = 5;
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

void func_02028dd8(void);
s32 func_02027958(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void WFC_SetState(s32);
    s32 func_02012f40(void *);
    void func_02028dd8(void);
    s32 s;
    void *p;
    s32 r;

    s = OS_DisableInterrupts();
    p = (void *)gSession;
    if (p == 0) {
        OS_RestoreInterrupts(s);
        return 1;
    }
    switch (M2C_FIELD(p, s32 *, 0x2260)) {
    case 10:
        OS_RestoreInterrupts(s);
        return 2;
    case 3:
        OS_RestoreInterrupts(s);
        return 0;
    default:
        OS_RestoreInterrupts(s);
        return 1;
    case 9:
        if (M2C_FIELD(p, u8 *, 0x226b) == 1) {
            WFC_SetState(10);
            M2C_FIELD((void *)gSession, u16 *, 0x2280) = 6;
        } else {
            r = func_02012f40((void *)func_02028dd8);
            switch (r) {
            case 2:
                WFC_SetState(10);
                M2C_FIELD((void *)gSession, u16 *, 0x2280) = 6;
                break;
            case 8:
                OS_RestoreInterrupts(s);
                return 4;
            case 3:
            default:
                WFC_SetState(11);
                OS_RestoreInterrupts(s);
                return 7;
            }
        }
        break;
    }
    OS_RestoreInterrupts(s);
    return 3;
}

/* One step of the WFC session while it waits for the DWC link: reads the link
 * state, starts hosting or joining, and moves the session to the next state
 * (or to the error/finished state on failure). */
s32 WFC_ProcessLinkState(void){
u16 *func_02011910(void);
M2C_UNK DC_InvalidateRange();
s32 func_02011244(void);
s32 func_02012158(void *);
s32 func_020121d8(M2C_UNK);
s32 func_02012274(void *);
void WFC_OperationCallback(void);
void func_02028ef4(void);
s32 irq=OS_DisableInterrupts();
void *session=(void *)gSession;
u16 *linkState;
s32 result;
if(!session){OS_RestoreInterrupts(irq);return 1;}
switch(M2C_FIELD(session,s32 *,WFC_SESSION_STATE)){
case 13:OS_RestoreInterrupts(irq);return 2;
case 1:OS_RestoreInterrupts(irq);return 0;
case 6:
WFC_SetState(13);M2C_FIELD((void *)gSession,u16 *,WFC_SESSION_SUBSTATE)=9;
OS_RestoreInterrupts(irq);return 3;
case 3:case 9:case 12:break;
default:OS_RestoreInterrupts(irq);return 1;
}
if(M2C_FIELD(session,u8 *,WFC_SESSION_ABORT)==1){
WFC_SetState(13);M2C_FIELD((void *)gSession,u16 *,WFC_SESSION_SUBSTATE)=9;
}else{
linkState=func_02011910();
DC_InvalidateRange(linkState,2);
switch(*linkState){
case 0:
if((result=func_02011244())==0){
WFC_SetState(1);M2C_FIELD((void *)gSession,u16 *,WFC_SESSION_SUBSTATE)=0;
OS_RestoreInterrupts(irq);return 0;
}
break;
case 1:result=func_02012158(WFC_OperationCallback);break;
case 2:result=func_020121d8((M2C_UNK)WFC_OperationCallback);break;
default:M2C_FIELD((void *)gSession,u8 *,WFC_SESSION_ABORT)=1;
result=func_02012274(func_02028ef4);
break;
}
switch(result){
case 2:WFC_SetState(13);M2C_FIELD((void *)gSession,u16 *,WFC_SESSION_SUBSTATE)=9;break;
case 8:OS_RestoreInterrupts(irq);return 4;
case 3:default:WFC_SetState(11);OS_RestoreInterrupts(irq);return 7;
}
}
OS_RestoreInterrupts(irq);return 3;
}

s32 Wfc_GetLinkState(void){s32 s=OS_DisableInterrupts();s32 r=0;void *p=(void *)gSession;if(p)r=M2C_FIELD(p,s32 *,0x2260);OS_RestoreInterrupts(s);return r;}

u32 WFC_SetStatusBits(u32 v){
u32 old; s32 s=OS_DisableInterrupts();u32 mask=0;void *p=(void *)gSession;
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
    extern s32 gSession;
    return gSession;
}

void MI_CpuFill8(void *, u32, u32);
void WFC_SetRequest(void *a, s32 b) {
    void MI_CpuFill8(void *, u32, u32);
    if (a == 0) {
        M2C_FIELD((void *)gSession, s32 *, 0x226c) = 3;
        M2C_FIELD((void *)gSession, s32 *, 0x2270) = 0;
        M2C_FIELD((void *)gSession, s32 *, 0x2274) = 0;
        M2C_FIELD((void *)gSession, s32 *, 0x2278) = 0;
        return;
    }
    M2C_FIELD((void *)gSession, u32 *, 0x226c) = M2C_FIELD(a, u32 *, 0) & 3;
    if (((4 - (M2C_FIELD(a, u32 *, 4) & 3)) & 3) + 12 > M2C_FIELD(a, u32 *, 8)) {
        M2C_FIELD((void *)gSession, u32 *, 0x2270) = 0;
        M2C_FIELD((void *)gSession, u32 *, 0x2274) = 0;
    } else {
        M2C_FIELD((void *)gSession, u32 *, 0x2270) = (M2C_FIELD(a, u32 *, 4) + 3) & ~3;
        M2C_FIELD((void *)gSession, u32 *, 0x2274) = M2C_FIELD(a, u32 *, 8) - ((4 - (M2C_FIELD(a, u32 *, 4) & 3)) & 3);
    }
    MI_CpuFill8((void *)M2C_FIELD((void *)gSession, u32 *, 0x2270), 0, M2C_FIELD((void *)gSession, u32 *, 0x2274));
    M2C_FIELD((void *)gSession, u32 *, 0x2278) = M2C_FIELD(a, u32 *, 12);
    M2C_FIELD((void *)gSession, u32 *, 0x227c) = b;
}

void WFC_FillRequest(s32 a, void *b, s32 c) {
    u32 WFC_SetStatusBits(u32);
    u16 func_02028038(s32);
    u16 func_02011e98(void);
    void MI_CpuCopy8(void *, void *, u32);
    extern s32 gSession;
    extern u8 data_020ea758[];
    extern u8 data_020ea760[];
    u8 *r4 = (u8 *)b;
    u16 tmp;
    WFC_SetStatusBits((u32)c);
    M2C_FIELD((void *)gSession, void **, 0x2288) = (void *)((s32)gSession + 0x1500);
    M2C_FIELD((void *)gSession, u16 *, 0x228c) = 0x400;
    tmp = func_02028038(0);
    M2C_FIELD((void *)gSession, u16 *, 0x228e) = (u16)(((s32)1 << tmp) >> 1);
    if (M2C_FIELD((void *)gSession, u16 *, 0x2268) == 0) {
        u16 v = func_02011e98();
        M2C_FIELD((void *)gSession, u16 *, 0x2290) = v;
        {
            u32 x = M2C_FIELD((void *)gSession, u32 *, 0x2264);
            M2C_FIELD((void *)gSession, u16 *, 0x2298) = (x & 0x300000) != 0x300000 ? 1 : 0;
        }
    }
    if (a == 0) {
        MI_CpuCopy8((void *)data_020ea758, (void *)((u8 *)gSession + 0x2292), 6);
    } else {
        MI_CpuCopy8((void *)a, (void *)((u8 *)gSession + 0x2292), 6);
    }
    if (b == 0 || b == data_020ea760) {
        MI_CpuCopy8((void *)data_020ea760, (void *)((u8 *)gSession + 0x229c), 0x20);
        M2C_FIELD((void *)gSession, u16 *, 0x229a) = 0;
    } else {
        s32 i;
        MI_CpuCopy8((void *)b, (void *)((u8 *)gSession + 0x229c), 0x20);
        i = 0;
        do {
            if (*r4 == 0) break;
            i++;
            r4++;
        } while (i < 0x20);
        M2C_FIELD((void *)gSession, u16 *, 0x229a) = (u16)i;
    }
    M2C_FIELD((void *)gSession, u32 *, 0x2284) = 0;
}

void func_02028018(void){M2C_FIELD((void *)gSession,u32 *,0x2264)=0xaaa082;}

