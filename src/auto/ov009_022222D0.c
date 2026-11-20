/* 30 functions from 0x022222D0 to 0x02223290 (ov009), found by ds-decomp. */
#include "common.h"
#include "ov009_link.h"

typedef struct LinkPlayerRemoval {
    s32 status;
    s32 disconnected;
    s32 kicked;
    u8 player;
    u8 padding[3];
} LinkPlayerRemoval;

extern const LinkPlayerRemoval data_ov009_022262f4, data_ov009_02226304;

static inline u32 ov009DisableInterrupts(void) {
    u32 previous = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    return previous;
}
static inline u32 ov009RestoreInterrupts(u32 saved) {
    u32 previous = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = saved;
    return previous;
}
#pragma cplusplus on
class Ov009InterruptGuard {
    u32 saved;
public:
    Ov009InterruptGuard() : saved(ov009DisableInterrupts()) {}
    ~Ov009InterruptGuard() { ov009RestoreInterrupts(saved); }
};
class Ov009Callback { public: void run(); };
typedef void (Ov009Callback::*Ov009CallbackFn)();
struct Ov009Functor {
 Ov009CallbackFn fn;
 explicit Ov009Functor(Ov009CallbackFn p):fn(p) {}
 Ov009Functor(const Ov009Functor& other):fn(other.fn) {}
 void operator()(u8 *p) const { (((Ov009Callback *)p)->*fn)(); }
};
static inline void ov009Apply(u8 *first,u8 *end,s32 size,Ov009Functor fn) {
 if(size) do { fn(first); first+=12; } while(first!=end);
}
#pragma push
#pragma optimization_level 1
static inline void ov009CallRange(u8 *first,s32 size,Ov009CallbackFn fn) {
 if(size) { u8 *end=first+size; do { (((Ov009Callback *)first)->*fn)(); first+=12; } while(first!=end); }
}
#pragma pop
#pragma cplusplus off


void func_ov009_022222d0(s32 arg0) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(s32, void *, s32);
    s32 GetLocalPlayerName();
    s32 GetLocalPlayerNameLength();
    s32 CopyLocalPlayerRecord(void *);
    M2C_UNK QueueHostLinkPacket(M2C_UNK, void *, M2C_UNK, s32);
    u8 spC[0x1C];
    u8 sp0[0xC];
    s32 temp_r4;
    if (CopyLocalPlayerRecord(sp0) == 0) return;
    MI_CpuFill8(spC,0,0x1A);
    temp_r4=GetLocalPlayerName();
    MI_CpuCopy8(temp_r4,spC,GetLocalPlayerNameLength()*2);
    QueueHostLinkPacket(0xF,sp0,0x28,(u16)(1<<arg0));
}

#pragma scheduling off
s32 func_ov009_02222348(s32 arg0) {
M2C_UNK MI_CpuCopy8(s32,void *,s32);
s32 ByteCompareN(s32,void *,s32);
extern M2C_UNK data_ov009_02226cc0, data_ov009_02226d80, data_ov009_02226d84;
s32 freeIndex; s32 i; u8 *p; s32 offset; s32 equal;
freeIndex=-1;i=0;p=(u8 *)&data_ov009_02226cc0;
do {
if(M2C_FIELD(p,s32*,0xc4)==0) { if(freeIndex<0)freeIndex=i; }
else {
if(ByteCompareN(arg0+4,p+4,6)==0) equal=1; else equal=0;
if(equal) {
MI_CpuCopy8(arg0,p,0xc0);
M2C_FIELD(p,u16*,0xc0)=0x1e0;
M2C_FIELD(p,s32*,0xc4)=1;
return 1;
}
}
i++;p+=0xc8;
}while(i<4);
if(freeIndex<0)return 0;
offset=freeIndex*0xc8;
MI_CpuCopy8(arg0,(u8 *)&data_ov009_02226cc0+offset,0xc0);
{
void *base = &data_ov009_02226d80;
*(u16 *)((char *)base + offset) = 0x1e0;
base = &data_ov009_02226d84;
*(s32 *)((char *)base + offset) = 1;
}
return 1;
}
#pragma scheduling on
s32 func_ov009_02222428(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC4);
}

void func_ov009_02222430(s32 arg0) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, s32 *, 0x5C) = arg0;
}

u32 func_ov009_02222440(void) {
    extern M2C_UNK gLinkState;
    s32 temp=M2C_FIELD(&gLinkState,s32 *,0x5C)*4+2;
    return M2C_FIELD(&gLinkState,u32 *,0x5C)=(u32)(temp*(temp+1))>>2;
}

void func_ov009_02222468(void *a) {
M2C_UNK func_ov009_02221338(void *,s32);
volatile u32 saved; u32 temp; void *p;
temp=*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=0;
p=M2C_FIELD(a,void **,0); saved=temp;
while(p!=0) {M2C_FIELD(a,void **,0)=M2C_FIELD(p,void **,0);func_ov009_02221338(p,M2C_FIELD(p,s32 *,12)+16);p=M2C_FIELD(a,void **,0);}
M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,8)=0;
(void)*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=saved;
}

#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_propagation off
extern "C" void ResetLinkQueues(void) {
 s32 func_ov009_02221338(void *,s32);
 extern s32 gLinkState;
 extern s32 data_ov009_02226980;
 extern s32 data_ov009_022269b0;
 extern s32 data_ov009_022269e0;
 extern Ov009CallbackFn gLinkSession[];
 void *node;
 Ov009CallbackFn a,b;
 s32 bytes;
 {
 Ov009InterruptGuard guard;
 node=M2C_FIELD(&gLinkState,void **,0x64);
 if(node) do {
 M2C_FIELD(&gLinkState,void **,0x64)=M2C_FIELD(node,void **,0);
 func_ov009_02221338(node,M2C_FIELD(node,s32 *,12)+16);
 node=M2C_FIELD(&gLinkState,void **,0x64);
 } while(node);
 M2C_FIELD(&gLinkState,s32 *,0x68)=0;
 M2C_FIELD(&gLinkState,s32 *,0x64)=0;
 M2C_FIELD(&gLinkState,s32 *,0x6c)=0;
 }
 bytes = 48;
 a=gLinkSession[1];
 ov009Apply((u8 *)&data_ov009_02226980, (u8 *)&data_ov009_022269b0, bytes, Ov009Functor(a));
 bytes = 48;
 b=gLinkSession[2];
 ov009Apply((u8 *)&data_ov009_022269b0, (u8 *)&data_ov009_022269e0, 48, Ov009Functor(b));
}
#pragma opt_propagation reset
#pragma optimization_level 4
#pragma cplusplus off

#pragma cplusplus on
/* Whether a packet for `channel` is waiting in the overlay's pending-send queue.
 * Interrupts are held off while the queue is walked because the link interrupt
 * may unlink packets from it. */
extern "C" s32 IsLinkPacketQueued(s32 channel) {
    extern M2C_UNK gLinkState;
    Ov009InterruptGuard guard;
    void *packet = M2C_FIELD(&gLinkState, void **, LINK_STATE_SEND_QUEUE);

    while (packet) {
        if (channel == M2C_FIELD(packet, u8 *, LINK_SEND_CHANNEL)) return 1;
        packet = M2C_FIELD(packet, void **, LINK_SEND_NEXT);
    }
    return 0;
}
#pragma cplusplus off
/* General WFC event callback of the link overlay: a fatal result halts the
 * console, the Download Play host-ready event clears the link actor's retry
 * count, and every event is then forwarded to the installed event handler. */
void HandleLinkWfcEvent(void *event) {
    void SignalLinkEvent();
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gLinkActorClass;
    extern M2C_UNK gLinkState;
    void *actor;
    if(M2C_FIELD(event,u16 *,LINK_WFC_EVENT_RESULT)==LINK_WFC_RESULT_FATAL) {
        SignalLinkEvent();
        SetLinkPhase(LINK_PHASE_ERROR);
        SystemHalt();
    }
    switch((u32)(M2C_FIELD(event,u16 *,LINK_WFC_EVENT_KIND)-LINK_WFC_KIND_HOST_READY)) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: break;
    default: break;
    case 0:
        actor=FindObjectByClass(&gLinkActorClass);
        if(actor!=NULL) M2C_FIELD(actor,u16 *,LINK_ACTOR_RETRY)=0;
        break;
    }
    if(M2C_FIELD(&gLinkState,void (**)(void *),LINK_STATE_EVENT_HANDLER)==NULL) return;
    M2C_FIELD(&gLinkState,void (**)(void *),LINK_STATE_EVENT_HANDLER)(event);
}

void SignalLinkEvent(arg0)
s32 arg0;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == 8) return;
    if (GetLinkPhase() == 9) return;
    state=&gLinkState;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

s32 func_ov009_02222790(void) {
    s32 func_02012218(M2C_UNK *, M2C_UNK *, M2C_UNK);
    void SignalLinkError();
    extern M2C_UNK data_ov009_022277a0;
    extern M2C_UNK func_ov009_0222281c;
    SetLinkPhase(3);
    if (func_02012218(&data_ov009_022277a0, &func_ov009_0222281c, 2) == 2) {
        return 1;
    }
    SignalLinkError();
    SetLinkPhase(9);
    return 0;
}

void SignalLinkError(arg0)
s32 arg0;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == 8) return;
    if (GetLinkPhase() == 9) return;
    state=&gLinkState;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

void func_ov009_0222281c(void *arg0) {
    s32 func_020119dc(M2C_UNK *);
    M2C_UNK func_ov009_022244d4(M2C_UNK);
    void HandleLinkWfcEvent(void *);
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        SetLinkPhase(9);
        return;
    }
    if (func_020119dc((M2C_UNK *)HandleLinkWfcEvent) != 0) {
        SignalLinkEvent(M2C_FIELD(arg0, u16 *, 2));
        SetLinkPhase(9);
        return;
    }
    func_ov009_022244d4(0);
    SetLinkPhase(1);
}

/* Ask the next player slot to announce itself: queue the player-announcement
 * command (0x11) for the first slot at or after `firstSlot` that the WFC player
 * mask holds, and let HandleLinkAnnounceEvent take the slot's answer (its result
 * reaches the caller).  A mask that is not ready (0x8000) fails with code 3, and
 * an empty mask reports result 0x17 and ends the announcement: both it and
 * running past slot 16 end with LINK_ANNOUNCE_DONE. */
s32 AnnounceNextLinkPlayer(u16 firstSlot) {
    s32 WFC_GetPlayerMask();
    void SignalLinkResult();
    void RequestLinkPlayerAnnounce(M2C_UNK, M2C_UNK);
    void HandleLinkAnnounceEvent(void *);
    s32 mask = WFC_GetPlayerMask();

    if (mask == 0x8000) {
        SignalLinkError(3);
        SetLinkPhase(LINK_PHASE_ERROR);
        return 3;
    }
    if (mask == 0) {
        SignalLinkResult(0x17);
        SetLinkPhase(LINK_PHASE_ERROR);
        return LINK_ANNOUNCE_DONE;
    }
    while (!(mask & (1 << (firstSlot - 1)))) {
        if ((u32) firstSlot++ >= 0x10) return LINK_ANNOUNCE_DONE;
    }
    RequestLinkPlayerAnnounce((M2C_UNK) &HandleLinkAnnounceEvent, firstSlot);
}

void SignalLinkResult(arg0)
s32 arg0;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == 8) return;
    if (GetLinkPhase() == 9) return;
    state=&gLinkState;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

/* Handles the answer to one player-announcement command: the answering player's
 * slot joins the mask of players found so far (the answers that share the lowest
 * reported value), then the next slot is announced; once no slot is left the
 * link moves on to choosing the local player. */
void HandleLinkAnnounceEvent(void *event) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    void SignalLinkEvent();
    s32 AnnounceNextLinkPlayer(u16);
    extern M2C_UNK gLinkState;
    u16 state;
    u16 answerKey;
    u16 foundKey;
    u16 playerSlot;
    s32 result;

    state = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
    if (state != 0) {
        SignalLinkEvent(state);
        SetLinkPhase(LINK_PHASE_ERROR);
        return;
    }
    answerKey = M2C_FIELD(event, u16 *, LINK_EVENT_VALUE);
    foundKey = M2C_FIELD(&gLinkState, u16 *, LINK_STATE_ANNOUNCE_KEY);
    playerSlot = M2C_FIELD(event, u16 *, LINK_EVENT_COMMAND);
    if (foundKey > answerKey) {
        M2C_FIELD(&gLinkState, u16 *, LINK_STATE_ANNOUNCE_KEY) = answerKey;
        M2C_FIELD(&gLinkState, u16 *, LINK_STATE_PLAYER_MASK) = (u16) (1 << (playerSlot - 1));
    } else if (foundKey == answerKey) {
        M2C_FIELD(&gLinkState, u16 *, LINK_STATE_PLAYER_MASK) = (u16) (M2C_FIELD(&gLinkState, u16 *, LINK_STATE_PLAYER_MASK) | (1 << (playerSlot - 1)));
    }
    result = AnnounceNextLinkPlayer((u16) (playerSlot + 1));
    if (result == LINK_ANNOUNCE_DONE) {
        SetLinkPhase(LINK_PHASE_FOUND);
        return;
    }
    if (result == LINK_TASK_QUEUED) return;
    SetLinkPhase(LINK_PHASE_ERROR);
}

void RequestLinkPlayerAnnounce(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02013dac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02013dac(arg0, 3, 0x11, arg1, 0x1E);
}

s32 __clz(u32);
s32 __cntlz(u32);
s32 _CountLeadingZeros(u32);
s32 __builtin_clz(u32);
#pragma intrinsic(__builtin_clz)
s16 func_ov009_02222a20(s32 arg0) {
u32 CountBits();u32 func_ov009_02222440();s32 __builtin_clz(u32);
s16 result=0;u32 temp=CountBits();s32 n;u16 count;s32 i;
if(temp==1){n=0x20-__builtin_clz(~arg0&(arg0-1));result=n+1;}
else if(temp>1U){
count=(temp*(func_ov009_02222440()&255))>>8;
i=result;goto test;
loop: {if((arg0&(1<<i))!=0 && count--==0){result=i+1;goto done;}i++;}
test:if(i<16)goto loop;
}
done:return result;
}
s32 func_ov009_02222ac4(void) {
    s32 WFC_StartDownloadPlay(M2C_UNK *, M2C_UNK *);
    void SignalLinkError();
    extern M2C_UNK data_ov009_022269e0;
    extern M2C_UNK func_ov009_02222b04;
    SetLinkPhase(3);
    if (WFC_StartDownloadPlay(&func_ov009_02222b04, &data_ov009_022269e0) == 2) return 1;
    SignalLinkError();
    SetLinkPhase(8);
    return 0;
}

void func_ov009_02222b04(void *arg0) {
    s32 func_ov009_02222b3c();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        SetLinkPhase(8);
        return;
    }
    if (func_ov009_02222b3c() != 0) {
        return;
    }
    SetLinkPhase(8);
}

s32 func_ov009_02222b3c(void) {
    s32 func_02012474(M2C_UNK *);
    M2C_UNK SetConnectedPlayers(s32);
    M2C_UNK func_ov009_02225480();
    void SignalLinkError();
    extern M2C_UNK func_ov009_02222b8c;
    s32 state = GetLinkPhase();
    switch (state) {
    case 4:
    case 5: return 1;
    default:
        if (func_02012474(&func_ov009_02222b8c) != 2) {
            SignalLinkError();
            return 0;
        }
        SetConnectedPlayers(1);
        func_ov009_02225480();
        return 1;
    }
}

#pragma opt_common_subs off
#pragma opt_propagation off
void func_ov009_02222b8c(void *event) {
    s32 StartLinkSession(void);
    void SignalLinkEvent(s32);
    void SignalLinkError();
    s32 func_0201280c(s32, s32);
    M2C_UNK QueueHostLinkPacket(M2C_UNK, void *, M2C_UNK, s32);
    void ClearPlayerActive(s32, s32, s32, s32, s32);
    void AnnounceLinkPlayer(void);
    extern M2C_UNK gLinkState;
    extern Ov009CallbackFn gLinkSession[];
    u16 status = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
    s32 one;
    if (status != 0) {
        SignalLinkEvent(status);
        SetLinkPhase(LINK_PHASE_ERROR);
        return;
    }
    switch (M2C_FIELD(event, u16 *, LINK_EVENT_COMMAND)) {
    case 7:
        if (M2C_FIELD(&gLinkState, s32 (**)(void *), 0x58) &&
            !M2C_FIELD(&gLinkState, s32 (**)(void *), 0x58)(event) &&
            func_0201280c(0, M2C_FIELD(event, u16 *, 0x10)) != LINK_TASK_QUEUED) {
            SignalLinkError();
            SetLinkPhase(LINK_PHASE_ERROR);
            return;
        }
        one = 1;
        M2C_FIELD(&gLinkSession, u16 *, 0) |= one << M2C_FIELD(event, u16 *, 0x10);
        QueueHostLinkPacket(7, gLinkSession, 2, 0x10000 - one);
        M2C_FIELD(&gLinkState, u8 *, 0x15b)++;
        AnnounceLinkPlayer();
        return;
    case 9:
        {
            LinkPlayerRemoval notice;
            one = 1;
            M2C_FIELD(&gLinkSession, u16 *, 0) &= (one - 2) ^ (one << M2C_FIELD(event, u16 *, 0x10));
            QueueHostLinkPacket(7, gLinkSession, 2, 0x10000 - one);
            M2C_FIELD(&gLinkState, u8 *, 0x15b)--;
            AnnounceLinkPlayer();
            ClearPlayerActive(M2C_FIELD(event, u16 *, LINK_EVENT_STATE), 1, 0, (u8)M2C_FIELD(event, u16 *, 0x10), 0);
            notice = data_ov009_022262f4;
            notice.status = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
            notice.player = M2C_FIELD(event, u16 *, 0x10);
            QueueHostLinkPacket(4, &notice, sizeof(notice), 0xffff);
            return;
        }
    case 0x1a:
        {
            LinkPlayerRemoval notice;
            one = 1;
            M2C_FIELD(&gLinkSession, u16 *, 0) &= (one - 2) ^ (one << M2C_FIELD(event, u16 *, 0x10));
            QueueHostLinkPacket(7, gLinkSession, 2, 0x10000 - one);
            M2C_FIELD(&gLinkState, u8 *, 0x15b)--;
            AnnounceLinkPlayer();
            ClearPlayerActive(M2C_FIELD(event, u16 *, LINK_EVENT_STATE), 0, 1, (u8)M2C_FIELD(event, u16 *, 0x10), 0);
            notice = data_ov009_02226304;
            notice.status = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
            notice.player = M2C_FIELD(event, u16 *, 0x10);
            QueueHostLinkPacket(4, &notice, sizeof(notice), 0xffff);
            return;
        }
    case 0:
        if (!StartLinkSession()) SetLinkPhase(LINK_PHASE_ERROR);
        return;
    case 2:
    default:
        return;
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
/* Starts the single-card link session: does nothing while a link is already
 * up (phases 4/5), otherwise registers the event handler on tasks 4 and 12,
 * enters phase 4 and starts the connect task; a failure signals a link error. */
s32 StartLinkSession(void) {
void HandleLinkChannelEvent(void *); void HandleLinkConnectTaskEvent(void *);
s32 GetLinkPhase(void); M2C_UNK SetLinkPhase(s32);
s32 WFC_SetChannelHandler(s32,void (*)(void *),s32);
s32 func_02012b08(void (*)(void *),M2C_UNK *,u16,M2C_UNK *,u16,s32);
extern M2C_UNK gLinkState,gLinkTransferData,gLinkTransferExtra;
s32 phase=GetLinkPhase();switch(phase){case 4:case 5:return 1;default:break;}
if(WFC_SetChannelHandler(4,HandleLinkChannelEvent,0)!=0) {SignalLinkError();return 0;}
if(WFC_SetChannelHandler(12,HandleLinkChannelEvent,0)!=0) {SignalLinkError();return 0;}
M2C_FIELD(&gLinkState,u8 *,0)=0;
SetLinkPhase(4);
if(func_02012b08(HandleLinkConnectTaskEvent,&gLinkTransferData,(u16)M2C_FIELD(&gLinkState,u32 *,0x34),&gLinkTransferExtra,(u16)M2C_FIELD(&gLinkState,u32 *,0x14),1)==2)return 1;
SignalLinkError();return 0;
}

void HandleLinkConnectTaskEvent(void *arg0) {
 s8 GetLinkLocalPlayerId();
 extern M2C_UNK gLinkState;
 u16 state = M2C_FIELD(arg0,u16 *,2);
 if(state != 0) {
 SignalLinkEvent(state);
 SetLinkPhase(8);
 return;
 }
 switch(M2C_FIELD(arg0,u16 *,4)) {
 case 10:
 SetLinkPhase(4);
 M2C_FIELD(&gLinkState,u8 *,0x156) = M2C_FIELD(&gLinkState,u8 *,0x156) | 1;
 M2C_FIELD(&gLinkState,u8 *,0x157) = GetLinkLocalPlayerId();
 AnnounceLinkPlayer();
 return;
 case 11: return;
 case 12: return;
 case 13: return;
 default: return;
 }
}

#pragma scheduling off
s32 func_ov009_02222f84(void) {
s32 func_02011d58(void); s32 func_02011e98(void); s32 func_020124c4(void *,void *);
extern M2C_UNK data_ov009_022268e0; extern M2C_UNK data_ov009_02226a80; extern M2C_UNK data_ov009_02226960; extern M2C_UNK func_ov009_02223078;
s32 mask; s32 result;
mask=func_02011d58();
if(mask==0x8000) {func_ov009_022227d4(3);return 0;}
if(mask==0) {func_ov009_02222910(0x17);return 0;}
if(M2C_FIELD(&data_ov009_022268e0,u16 *,6)==0) {
do {
M2C_FIELD(&data_ov009_022268e0,u16 *,0x84)++;
if(M2C_FIELD(&data_ov009_022268e0,u16 *,0x84)>14) M2C_FIELD(&data_ov009_022268e0,u16 *,0x84)=1;
}while(!(mask&(1<<(M2C_FIELD(&data_ov009_022268e0,u16 *,0x84)-1))));
} else M2C_FIELD(&data_ov009_022268e0,u16 *,0x84)=M2C_FIELD(&data_ov009_022268e0,u16 *,6);
M2C_FIELD(&data_ov009_022268e0,u16 *,0x86)=func_02011e98();
M2C_FIELD(&data_ov009_022268e0,void **,0x80)=&data_ov009_02226a80;
result=func_020124c4(&func_ov009_02223078,&data_ov009_02226960);
if(result==2) return 1;
func_ov009_022227d4(result);
return 0;
}
#pragma scheduling reset
void func_ov009_0222304c(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (M2C_FIELD(arg0, s16 *, 0xC0) - 1);
    if ((s32) M2C_FIELD(arg0, s16 *, 0xC0) <= 0) {
        M2C_FIELD(arg0, s32 *, 0xC4) = 0;
    }
}

void func_ov009_0222306c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC4) = 0;
}

#pragma scheduling off
void func_ov009_02223078(void *arg0) {
    void SignalLinkEvent(s32);
    M2C_UNK SetLinkPhase(M2C_UNK);
    s32 GetLinkPhase(void);
    s32 func_ov009_02223244(void);
    void DC_InvalidateRange(void *, s32);
    s32 IsConnectionDataValid(void *);
    s32 func_ov009_02222f84(void);
    s32 func_ov009_02222348(s32);
    extern Ov009CallbackFn gLinkSession[];
    extern M2C_UNK data_ov009_02226cc0;
    extern M2C_UNK data_ov009_02226fe0;
    extern M2C_UNK data_ov009_02226a80;
    extern M2C_UNK gLinkState;

    s32 buf[8];
    u8 *r5;
    s32 *r6 = buf;
    s32 x;
    u8 *r7;
    void *elem;
    void **tbl;
    void (*fn)(void *);
    u16 arg2v;
    u16 t8;
    s32 res;
    u16 v36;
    u32 cond;
    u16 v38;
    u32 rhs;
    u8 bb;
    void (*cb)(void *);
    void (*cb2)(void *);

    {
        s32 a = M2C_FIELD(&gLinkSession, u32 *, 0x18);
        s32 b = M2C_FIELD(&gLinkSession, u32 *, 0x1c);
        r6[3] = b;
        r6[2] = a;
        r6[4] = a;
        r6[5] = b;
        r6[0] = a;
        r6[1] = b;
    }
    r7 = (u8 *)&data_ov009_02226cc0;
    r5 = (u8 *)&data_ov009_02226fe0;
    goto test;
loop: {
        x = (s32)r6[1];
        elem = (void *)(r7 + (x >> 1));
        if (!(x & 1)) {
            fn = (void (*)(void *))r6[0];
        } else {
        tbl = *(void **)elem;
        fn = *(void (**)(void *))((u8 *)tbl+(s32)r6[0]);
        }
        fn(elem);
        r7 += 0xc8;
    }
test:
    if(r7 != r5) goto loop;

    arg2v = M2C_FIELD(arg0, u16 *, 2);
    buf[6] = buf[0];
    buf[7] = buf[1];

    if (arg2v != 0) {
        SignalLinkEvent(arg2v);
        SetLinkPhase(8);
        return;
    }

    if (GetLinkPhase() != 2) {
        if (func_ov009_02223244() != 0) return;
        SetLinkPhase(8);
        return;
    }

    t8 = M2C_FIELD(arg0, u16 *, 8);
    if(t8==3 || t8==4) goto done;
    if (t8 == 5) {
        DC_InvalidateRange(&data_ov009_02226a80, 0xc0);
        if (M2C_FIELD(&gLinkState, s32 *, 0x30) != 0 &&
            IsConnectionDataValid(&data_ov009_02226a80) != 0) {
            cb = M2C_FIELD(&gLinkState, void (**)(void *), 0x4c);
            if (cb != 0) cb(&data_ov009_02226a80);
        } else {
            v36 = M2C_FIELD(arg0, u16 *, 0x36);
            cond = 0;
            if (v36 >= 0x10) {
                v38 = M2C_FIELD(arg0, u16 *, 0x38);
                cond = (v38 == 1);
            }
            if (cond) {
                rhs = M2C_FIELD(&gLinkState, u32 *, 0x108);
                if (M2C_FIELD(arg0, u32 *, 0x3c) == rhs) {
                    bb = M2C_FIELD(arg0, u8 *, 0x43);
                    if ((bb & 1) && !(bb & 2)) {
                        func_ov009_02222348((s32)&data_ov009_02226a80);
                        cb2 = M2C_FIELD(&gLinkState, void (**)(void *), 0x4c);
                        if (cb2 != 0) cb2(&data_ov009_02226a80);
                    }
                }
            }
        }
    }

done:
    res = func_ov009_02222f84();
    if (res != 0) return;
    SetLinkPhase(8);
}
#pragma scheduling reset
s32 func_ov009_02223244(void) {
    s32 func_02012700(void (*)(void *));
    void func_ov009_0222326c(void *);
    if (func_02012700(func_ov009_0222326c) == 2) return 1;
    SignalLinkError();
    return 0;
}

void func_ov009_0222326c(void *arg0) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    void SignalLinkEvent();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        return;
    }
    SetLinkPhase(1);
}

