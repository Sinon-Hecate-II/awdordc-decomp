/* 17 functions from 0x02028038 to 0x02028EF4 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
typedef struct CallbackArgs_0202810c { s16 a,b; s32 c,d,e; } CallbackArgs_0202810c;
typedef struct State_02028038 { u8 pad[0x260]; s32 state; u32 bits; u8 pad268[0x14]; void (*callback)(CallbackArgs_0202810c *); } State_02028038;

#pragma opt_common_subs off
/* Returns the first player slot (1..13) whose bit in WFC_SESSION_STATUS is free,
 * scanning at most one round of the WFC_PLAYER_SLOT_COUNT slots from `startSlot`,
 * and falls back to the slot that round ends on when every slot is taken. */
u16 WFC_FindFreePlayerSlot(s32 startSlot){
extern void *gWfcSession;
s32 i,slot,bits,rem;void *p=gWfcSession;
i=0;slot=startSlot;bits=M2C_FIELD(p,u32*,WFC_SESSION_STATUS);do{rem=slot%WFC_PLAYER_SLOT_COUNT;if(bits&(1<<(rem+1)))break;i++;slot++;}while(i<WFC_PLAYER_SLOT_COUNT);
rem=(startSlot+i)%WFC_PLAYER_SLOT_COUNT;return rem+1;
}
#pragma opt_common_subs on
/* Deliver the session's pending substep to its event callback: take the substep
 * from WFC_SESSION_SUBSTATE, clear it and hand it, with the event's arguments,
 * to WFC_CallEventHandler (the callback the session installed). */
void WFC_DispatchEvent(M2C_UNK result, M2C_UNK data, M2C_UNK value, s32 tag) {
    void WFC_CallEventHandler(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern void *gWfcSession;
    s16 substate;

    substate = M2C_FIELD(gWfcSession, s16 *, WFC_SESSION_SUBSTATE);
    M2C_FIELD(gWfcSession, s16 *, WFC_SESSION_SUBSTATE) = 0;
    WFC_CallEventHandler(substate, result, data, value, tag);
}

void WFC_CallEventHandler(s16 a,s32 b,s32 c,s32 d,s32 e){
extern void *gWfcSession;
CallbackArgs_0202810c args;
void (**callback)(CallbackArgs_0202810c *) = &((State_02028038 *)((u8 *)gWfcSession + 0x2000))->callback;
if((*callback)==0)return;
args.a=a;args.c=c;args.d=d;args.e=e;args.b=b;
(*callback)(&args);
}

#pragma opt_common_subs off
/* Set the WFC session's connection state: leaving state 9 stops the session's
 * timer, entering state 9 (re)starts it with WFC_StateTimerCallback, and state
 * 11 is final - no later state is stored.  Runs with interrupts held off. */
void WFC_SetState(s32 state) {
    void WFC_StateTimerCallback(void);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void CancelTimer(void *);
    void ScheduleTimer(void *, s32, s32, void (*)(void), s32);
    extern void *gWfcSession;
    s32 irq = OS_DisableInterrupts();
    if (M2C_FIELD(gWfcSession, s32 *, 0x2260) == 9 && state != 9)
        CancelTimer((u8 *)gWfcSession + 0x22cc);
    if (M2C_FIELD(gWfcSession, s32 *, 0x2260) != 11)
        M2C_FIELD(gWfcSession, s32 *, 0x2260) = state;
    if (state == 9)
        ScheduleTimer((u8 *)gWfcSession + 0x22cc, 0x22f5341, 0, WFC_StateTimerCallback, 0);
    OS_RestoreInterrupts(irq);
}
#pragma opt_common_subs on
/* Restarts the one-shot state timer while the session is waiting for its peer. */
M2C_UNK WFC_RearmStateTimer(void) {
    void WFC_StateTimerCallback(void);
    extern void *gWfcSession;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void CancelTimer(void *);
    void ScheduleTimer(void *, s32, s32, void (*)(void), s32);
    s32 interruptState = OS_DisableInterrupts();

    CancelTimer((u8 *)gWfcSession + WFC_SESSION_TIMER);
    if (M2C_FIELD(gWfcSession, s32 *, WFC_SESSION_STATE) == WFC_SESSION_STATE_LINKING)
        ScheduleTimer((u8 *)gWfcSession + WFC_SESSION_TIMER,
            WFC_STATE_TIMER_PERIOD, 0, WFC_StateTimerCallback, 0);
    OS_RestoreInterrupts(interruptState);
}

void WFC_StateTimerCallback(void) {
    M2C_UNK WFC_RearmStateTimer();
    M2C_UNK WFC_SendConnDataRequest();
    WFC_SendConnDataRequest();
    WFC_RearmStateTimer();
}

u32 func_0202827c(u32 a){s32 __cntlzw(u32);u32 n=0;s32 bit;for(;;){bit=31-__cntlzw(a);if(bit<0)return n;a&=~(1U<<bit);n++;}}

s32 func_020282a8(u32 arg0) {
    return __builtin_clz(arg0);
}

#pragma optimization_level 2
/* Finishes the WFC session: raises its abort flag so later calls do nothing, and
   unless the session step task is still running, moves it to the final error
   state and reports WFC error event 7 (code 0x610). */
void WFC_Finish(void){
 extern void *gWfcSession;
 void func_02028ef4(void);
 s32 WFC_SendCommand1(void (*)(void));
 u8 *p=(u8 *)gWfcSession;
 p += WFC_SESSION_PLAYER_BLOCK;
 if(p[WFC_SESSION_BLOCK_ABORT])return;
 p[WFC_SESSION_BLOCK_ABORT]=1;
 if(WFC_SendCommand1(func_02028ef4)==2)return;
 WFC_SetState(WFC_SESSION_STATE_ERROR);
 WFC_DispatchEvent(7,0,0,0x610);
}
#pragma optimization_level reset
/* Handle the WFC peer-status event (index 8, kind 0x16, channel 0x25): when it
 * arrives while the session is in state 8 or matchmaking, the link is up; when
 * the session is already linking or linked, finish it. */
void WFC_ProcessPeerStatusEvent(u16 *event){
extern void *gWfcSession;
if(event[1]!=8||event[2]!=0x16||event[3]!=0x25)return;
switch(M2C_FIELD(gWfcSession,s32 *,WFC_SESSION_STATE)){
case 8:WFC_SetState(WFC_SESSION_STATE_LINKED);return;
case WFC_SESSION_STATE_LINKING:
case WFC_SESSION_STATE_LINKED:WFC_Finish();return;
case WFC_SESSION_STATE_MATCHMAKING:WFC_SetState(WFC_SESSION_STATE_LINKED);return;
}}

#pragma opt_propagation off
/* Completion callback for the WFC connection operations: dispatches on the
 * result kind and the operation id, runs the matching continuation, then
 * advances the session state machine and reports the outcome. */
void WFC_OperationCallback(u16 *msg) {
s32 WFC_ShutdownCommandChannel(void);s32 WFC_SendCommand4(void *);s32 WFC_SendCommand5(void *);s32 WFC_SubmitParentMode(void *,s32);s32 WFC_SubmitMatchSettings(void *,s32,s32,void *);s32 WFC_SendConnectionData(void *,void *,s32,s32,u16);void func_0202899c(const u16 *);extern void *gWfcSession;
s32 result=20;
switch(msg[1]){
case 0:
switch(msg[0]){
case 3:result=WFC_SendCommand5(WFC_OperationCallback);break;
case 4: {s32 n=WFC_ShutdownCommandChannel();switch(n){case 0: {WFC_SetState(1);WFC_DispatchEvent(0,0,0,0x663);return;}case 4:default:WFC_SetState(11);WFC_DispatchEvent(7,0,0,0x66c);return;}}
case 5:WFC_SetState(3);WFC_DispatchEvent(0,0,0,0x673);return;
case 6:result=WFC_SendCommand4(WFC_OperationCallback);break;
case 29:result=WFC_SubmitParentMode(WFC_OperationCallback,0);break;
case 25:{u8 *session=gWfcSession;result=WFC_SubmitMatchSettings(WFC_OperationCallback,session[0x2250],session[0x2251],session+0x2200);break;}
case 39:{u8 *session=gWfcSession;u32 statusBits=M2C_FIELD(session,u32 *,0x2264);u16 bothSet=(statusBits&0xc0000)==0xc0000;result=WFC_SendConnectionData(func_0202899c,session+0x2140,0,(statusBits&0x30000)!=0x30000,bothSet);break;}
}
switch(result){case 2:return;case 3:break;case 8:WFC_SetState(12);{u8 *session=gWfcSession;WFC_DispatchEvent(1,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6af);}return;}
WFC_SetState(11);{u8 *session=gWfcSession;WFC_DispatchEvent(7,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6b8);}return;
case 1:WFC_SetState(12);{u8 *session=gWfcSession;WFC_DispatchEvent(1,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6de);}return;
case 2:case 3:case 4:default:WFC_SetState(11);{u8 *session=gWfcSession;WFC_DispatchEvent(7,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6e8);}return;
}}
#pragma opt_propagation on
/* Handle a message from the WFC socket: advance the connection state machine and report the result. */
void WFC_ProcessCallback(u16 *msg){
extern void *gWfcSession;
void DC_InvalidateRange(s32,s32); void WFC_StorePlayerRecord(s32,u16); u64 U32DivideRem(s32,s32); s32 WFC_SendRequestPacket(void *,void *);s32 WFC_SendCommand11(void *);void WFC_ProcessSendCallback(u16 *);
s32 result=20,i,n;u32 bits;
switch(msg[1]){
case 0:
if(M2C_FIELD(gWfcSession,s32 *,0x2260)==5){WFC_SetState(6);WFC_DispatchEvent(0,0,0,0x704);}
switch(M2C_FIELD(gWfcSession,s32 *,0x2260)){
case 6:
M2C_FIELD(gWfcSession,u16 *,0x2280)=7;
if(msg[4]==5){DC_InvalidateRange(M2C_FIELD(gWfcSession,s32 *,0x2288),M2C_FIELD(gWfcSession,u16 *,0x228c));
for(i=0;i<msg[7];i++){WFC_StorePlayerRecord(((s32 *)msg)[i+4],msg[i+40]);WFC_CallEventHandler(7,0,((s32 *)msg)[i+4],(s32)msg,0x71a);}}
bits=M2C_FIELD(gWfcSession,u32 *,0x2264);
if((bits&0xc00000)==0xc00000){n=func_0202827c(bits&0x3ffe);if(n){s32 v=M2C_FIELD(gWfcSession,s32 *,0x2284);if((u32)(U32DivideRem(v,n)>>32)==0)WFC_CallEventHandler(8,0,v,0,0x728);}}
M2C_FIELD(gWfcSession,u16 *,0x228e)=(1<<WFC_FindFreePlayerSlot((u16)(32-func_020282a8(msg[5]))))>>1;
DC_InvalidateRange(M2C_FIELD(gWfcSession,s32 *,0x2288),M2C_FIELD(gWfcSession,u16 *,0x228c));
M2C_FIELD(gWfcSession,s32 *,0x2284)++;
result=WFC_SendRequestPacket(WFC_ProcessCallback,(u8 *)gWfcSession+0x2288);break;
case 7:result=WFC_SendCommand11(WFC_ProcessSendCallback);break;
case 13:WFC_Finish();return;
}
if(result==2)return;
if(result!=3&&result==8){WFC_SetState(12);WFC_DispatchEvent(1,0,0,0x753);return;}
WFC_SetState(11);WFC_DispatchEvent(7,0,0,0x75c);return;
case 1:WFC_Finish();return;
case 2:case 3:case 4:default:WFC_SetState(11);WFC_DispatchEvent(7,0,0,0x76d);return;
}}

/* Completion callback of the WFC operation started by the session's send step:
 * result 0 leaves the session ready for the next connection, result 1 means the
 * operation was dropped and finishes the session, and any other result raises the
 * WFC error event. */
void WFC_ProcessSendCallback(u16 *reply){
    switch(reply[WFC_REPLY_RESULT]){
    case 0:
        WFC_SetState(WFC_SESSION_STATE_READY);
        WFC_DispatchEvent(0,0,0,0x783);
        return;
    case 1:
        WFC_Finish();
        return;
    case 2:
    case 3:
    case 4:
    default:
        WFC_SetState(WFC_SESSION_STATE_ERROR);
        WFC_DispatchEvent(7,0,0,0x793);
        return;
    }
}

#pragma opt_strength_reduction off
void func_0202899c(const u16 *p){
extern void *gWfcSession;
void WFC_ProcessSendDataCallback(u16 *);s32 WFC_SendDataBuffer(void (*)(u16 *),void *,s32);
s32 result;
switch(p[1]){
case 0:
switch(p[4]){
case 6:goto done;
case 26:goto done;
case 8:case 9: {
void **g=&gWfcSession;
void *base=*g;
switch(M2C_FIELD(base,s32 *,0x2260)){
case 10:M2C_FIELD(base,u16 *,0x2282)=0;
case 8:WFC_SetState(12);return;
case 9:M2C_FIELD(base,u16 *,0x2282)=0;

case 12:M2C_FIELD(*g,u16 *,0x2280)=6;WFC_Finish();return;
default:goto done;}
}
case 7:
if(M2C_FIELD(gWfcSession,s32 *,0x2260)==12){WFC_SetState(8);WFC_Finish();return;}
if(p[5]>=1&&p[5]<=0x7d7){
M2C_FIELD(gWfcSession,u16 *,0x2282)=p[5];
result=WFC_SendDataBuffer(WFC_ProcessSendDataCallback,(u8 *)gWfcSession+0x1500,0x620);
switch(result){case 2:return;case 3:break;case 8:WFC_SetState(12);WFC_DispatchEvent(1,(s32)((u8 *)gWfcSession+0x2140),0,0x7ed);return;
}
WFC_SetState(11);WFC_DispatchEvent(7,(s32)((u8 *)gWfcSession+0x2140),0,0x7f6);return;
}
WFC_Finish();return;
default:WFC_SetState(11);WFC_DispatchEvent(7,(s32)((u8 *)gWfcSession+0x2140),p[4],0x804);return;
}
case 1:M2C_FIELD(gWfcSession,u16 *,0x22f8)=p[7];WFC_SetState(8);
case 6:case 11:case 12:WFC_Finish();return;
case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:
default:WFC_SetState(11);WFC_DispatchEvent(7,(s32)((u8 *)gWfcSession+0x2140),0,0x81b);return;
}
done:return;
}
#pragma opt_strength_reduction reset
/* Completion callback of the WFC send started in WFC_ProcessLinkCallback (the
 * player's packet to peer 0).  On success it finishes the session when it is
 * already connected, otherwise it clears the link error, resumes the connection
 * step and reports the connection data as an event; a dropped operation finishes
 * the session and any other result raises the WFC error event. */
void WFC_ProcessLinkSendCallback(u16 *msg) {
    extern void *gWfcSession;
    switch (msg[1]) {
    case 0:
        if (M2C_FIELD(gWfcSession, s32 *, WFC_SESSION_STATE) == 0xc) {
            WFC_SetState(0xa);
            WFC_Finish();
            return;
        }
        M2C_FIELD(gWfcSession, u16 *, WFC_SESSION_ERROR) = 0;
        WFC_SetState(3);
        WFC_DispatchEvent(0, (u8 *)gWfcSession + WFC_SESSION_CONN_DATA, 0, 0x83d);
        return;
    case 1:
    case 3:
        WFC_SetState(0xa);
        WFC_Finish();
        return;
    case 2:
    case 4:
    default:
        WFC_SetState(0xb);
        WFC_DispatchEvent(7, (u8 *)gWfcSession + WFC_SESSION_CONN_DATA, 0, 0x84f);
        return;
    }
}

/* Completion callback of the session's 0x620-byte data send (WFC_SendDataBuffer in
 * func_0202899c).  A successful completion (p[1] == 0) dispatches on the operation
 * p[2]: a link status (0xe) finishes the session when the link is already up,
 * otherwise moves it to the linking state and reports the connection data; a
 * command completion (0xf) invalidates and processes the received block; anything
 * else, or any failed completion, raises the WFC error event. */
void WFC_ProcessSendDataCallback(u16 *p) {
    extern void *gWfcSession;
    void WFC_SetState(s32);
    void WFC_DispatchEvent(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void WFC_Finish(void);
    void func_02029bd0(M2C_UNK);
    void DC_InvalidateRange(M2C_UNK, M2C_UNK);
    void func_020296e0(M2C_UNK);

    switch (p[1]) {
    case 0:
        switch (p[2]) {
        case 0xe:
            if (M2C_FIELD(gWfcSession, s32 *, WFC_SESSION_STATE) == WFC_SESSION_STATE_LINKED) {
                WFC_SetState(0x8);
                WFC_Finish();
                return;
            }
            WFC_SetState(WFC_SESSION_STATE_LINKING);
            WFC_DispatchEvent(0, (u8 *)gWfcSession + WFC_SESSION_CONN_DATA, 0, 0x872);
            return;
        case 0xf:
            func_02029bd0((*(u16 *)((u8 *)*(void **)((u8 *)p + 8) + 0xe) >> 8) & 0xff);
            DC_InvalidateRange(*(void **)((u8 *)p + 8), 0x620);
            func_020296e0(*(void **)((u8 *)p + 8));
            return;
        default:
            WFC_SetState(WFC_SESSION_STATE_ERROR);
            WFC_DispatchEvent(7, (u8 *)gWfcSession + WFC_SESSION_CONN_DATA, p[2], 0x881);
            return;
        }
    case 4:
    default:
        WFC_SetState(WFC_SESSION_STATE_ERROR);
        WFC_DispatchEvent(7, (u8 *)gWfcSession + WFC_SESSION_CONN_DATA, 0, 0x88c);
        return;
    }
}

void WFC_ProcessLinkSendCallback(u16 *);
/* Completion callback for the DWC receive operation started in the session's
 * link step: on arrival it either finishes the session (state 12) or sends this
 * player's packet to peer 0 (completion handled by WFC_ProcessLinkSendCallback).  A dropped
 * operation finishes the session, and a failure raises the network error. */
void WFC_ProcessLinkCallback(u16 *p) {
extern void *gWfcSession;
switch(p[1]){
case 0:
if(M2C_FIELD(gWfcSession,s32 *,WFC_SESSION_STATE)==12){WFC_SetState(10);WFC_Finish();return;}
switch(func_0201280c(WFC_ProcessLinkSendCallback,0)){
case 2:return;
case 8:WFC_SetState(12);WFC_DispatchEvent(1,(u8 *)gWfcSession+WFC_SESSION_CONN_DATA,0,0x8b4);return;
case 3:WFC_SetState(10);WFC_Finish();return;
default:WFC_SetState(11);WFC_DispatchEvent(7,(u8 *)gWfcSession+WFC_SESSION_CONN_DATA,0,0x8c0);return;
}
case 1:case 3:WFC_SetState(10);WFC_Finish();return;
case 2:case 4:default:WFC_SetState(11);WFC_DispatchEvent(7,(u8 *)gWfcSession+WFC_SESSION_CONN_DATA,0,0x8d3);return;
}
}

