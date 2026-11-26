/* 30 functions from 0x022222D0 to 0x02223290 (ov009), found by ds-decomp. */
#include "common.h"
#include "ov009_link.h"
#include "wfc.h"

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


/* Sends the local player's player-info reply to one peer channel: link message 15,
 * the 12-byte player record (when one is present) followed by the local player's
 * NUL-padded name. */
void SendLinkPlayerInfo(s32 channel) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(s32, void *, s32);
    s32 GetLocalPlayerName();
    s32 GetLocalPlayerNameLength();
    s32 CopyLocalPlayerRecord(void *);
    M2C_UNK QueueHostLinkPacket(M2C_UNK, void *, M2C_UNK, s32);
    u8 packet[LINK_PLAYER_INFO_SIZE];
    void *name;
    if (CopyLocalPlayerRecord(packet) == 0) return;
    MI_CpuFill8(packet + LINK_PLAYER_NAME_OFFSET, 0, LINK_PLAYER_NAME_SIZE);
    name = (void *)GetLocalPlayerName();
    MI_CpuCopy8((s32)name, packet + LINK_PLAYER_NAME_OFFSET, GetLocalPlayerNameLength() * 2);
    QueueHostLinkPacket(LINK_MSG_PLAYER_INFO_REPLY, packet, LINK_PLAYER_INFO_SIZE, (u16)(1 << channel));
}

#pragma scheduling off
s32 func_ov009_02222348(s32 arg0) {
M2C_UNK MI_CpuCopy8(s32,void *,s32);
s32 ByteCompareN(s32,void *,s32);
extern M2C_UNK gLinkPeerSlots, data_ov009_02226d80, data_ov009_02226d84;
s32 freeIndex; s32 i; u8 *p; s32 offset; s32 equal;
freeIndex=-1;i=0;p=(u8 *)&gLinkPeerSlots;
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
MI_CpuCopy8(arg0,(u8 *)&gLinkPeerSlots+offset,0xc0);
*(u16 *)((u8 *)&data_ov009_02226d80 + offset) = 480;
*(s32 *)((u8 *)&data_ov009_02226d84 + offset) = (equal = 1);
return equal;
}
#pragma scheduling on
s32 func_ov009_02222428(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC4);
}

void LinkRngSeed(s32 arg0) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, s32 *, 0x5C) = arg0;
}

/* Advance the link overlay's pseudo-random generator one step and return the new
 * state: state = ((4*state + 2) * (4*state + 3)) >> 2. */
u32 LinkRngNext(void) {
    extern M2C_UNK gLinkState;
    s32 temp = M2C_FIELD(&gLinkState, s32 *, LINK_STATE_RANDOM) * 4 + 2;
    return M2C_FIELD(&gLinkState, u32 *, LINK_STATE_RANDOM) = (u32)(temp * (temp + 1)) >> 2;
}

/* Empty a pending-send queue with interrupts held off: unlink and free every
 * queued packet (its 16-byte header plus its payload), then reset the queue. */
void ClearLinkSendQueue(void *queue) {
    M2C_UNK FreeLinkBlock(void *, s32);
    volatile u32 saved;
    u32 previous;
    void *packet;

    previous = *(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = 0;
    packet = M2C_FIELD(queue, void **, LINK_SEND_QUEUE_HEAD);
    saved = previous;
    while (packet != 0) {
        M2C_FIELD(queue, void **, LINK_SEND_QUEUE_HEAD) = M2C_FIELD(packet, void **, LINK_SEND_NEXT);
        FreeLinkBlock(packet, M2C_FIELD(packet, s32 *, LINK_SEND_LENGTH) + 16);
        packet = M2C_FIELD(queue, void **, LINK_SEND_QUEUE_HEAD);
    }
    M2C_FIELD(queue, s32 *, LINK_SEND_QUEUE_TAIL) = 0;
    M2C_FIELD(queue, s32 *, LINK_SEND_QUEUE_HEAD) = 0;
    M2C_FIELD(queue, s32 *, LINK_SEND_QUEUE_COUNT) = 0;
    (void)*(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = saved;
}

#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_propagation off
extern "C" void ResetLinkQueues(void) {
 s32 FreeLinkBlock(void *,s32);
 extern s32 gLinkState;
 extern s32 data_ov009_02226980;
 extern s32 data_ov009_022269b0;
 extern s32 gLinkDownloadHeader;
 extern Ov009CallbackFn gLinkSession[];
 void *node;
 Ov009CallbackFn a,b;
 s32 bytes;
 {
 Ov009InterruptGuard guard;
 node=M2C_FIELD(&gLinkState,void **,0x64);
 if(node) do {
 M2C_FIELD(&gLinkState,void **,0x64)=M2C_FIELD(node,void **,0);
 FreeLinkBlock(node,M2C_FIELD(node,s32 *,12)+16);
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
 ov009Apply((u8 *)&data_ov009_022269b0, (u8 *)&gLinkDownloadHeader, 48, Ov009Functor(b));
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

/* Signal a link event code: record it in the link state and hand it to the result
 * handler, unless the link already failed or was aborted. */
void SignalLinkEvent(code)
s32 code;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == LINK_PHASE_ERROR) return;
    if (GetLinkPhase() == LINK_PHASE_ABORTED) return;
    state = &gLinkState;
    M2C_FIELD(state, s32 *, LINK_STATE_RESULT_CODE) = code;
    if (M2C_FIELD(state, void (**)(s32, s32), LINK_STATE_RESULT_HANDLER) == NULL) return;
    M2C_FIELD(state, void (**)(s32, s32), LINK_STATE_RESULT_HANDLER)(code, 0);
}

/* Start the link overlay's WFC command channel: move to the pending phase and
 * queue its start command, whose completion HandleLinkStartResult takes.  A
 * failed queue signals the link error and aborts the session. */
s32 StartLinkCommandChannel(void) {
    s32 WFC_StartCommandChannel(M2C_UNK *, M2C_UNK *, M2C_UNK);
    void SignalLinkError();
    extern M2C_UNK gLinkCommandChannelWork;
    extern M2C_UNK HandleLinkStartResult;
    SetLinkPhase(LINK_PHASE_PENDING);
    if (WFC_StartCommandChannel(&gLinkCommandChannelWork, &HandleLinkStartResult, 2) == 2 /* WFC_CMD_OK */) {
        return 1;
    }
    SignalLinkError();
    SetLinkPhase(LINK_PHASE_ABORTED);
    return 0;
}

/* Signal a link error code: record it in the link state and hand it to the result
 * handler, unless the link already failed or was aborted. */
void SignalLinkError(errorCode)
s32 errorCode;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == LINK_PHASE_ERROR) return;
    if (GetLinkPhase() == LINK_PHASE_ABORTED) return;
    state=&gLinkState;
    M2C_FIELD(state,s32 *,LINK_STATE_RESULT_CODE)=errorCode;
    if (M2C_FIELD(state,void (**)(s32,s32),LINK_STATE_RESULT_HANDLER)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),LINK_STATE_RESULT_HANDLER)(errorCode,0);
}

/* Completion callback of the WFC command that prepares the link channel: a reported
 * failure aborts the link; otherwise it installs the overlay's general WFC event
 * handler, resets the per-slot link-result flags and moves the link to the ready
 * phase. */
void HandleLinkStartResult(void *event) {
    s32 WFC_SetGeneralHandler(M2C_UNK *);
    M2C_UNK SetLinkResultFlagMask(M2C_UNK);
    void HandleLinkWfcEvent(void *);
    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) != 0) {
        SignalLinkEvent();
        SetLinkPhase(LINK_PHASE_ABORTED);
        return;
    }
    if (WFC_SetGeneralHandler((M2C_UNK *)HandleLinkWfcEvent) != 0) {
        SignalLinkEvent(M2C_FIELD(event, u16 *, LINK_EVENT_STATE));
        SetLinkPhase(LINK_PHASE_ABORTED);
        return;
    }
    SetLinkResultFlagMask(0);
    SetLinkPhase(LINK_PHASE_READY);
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

/* Signal a link result code: record it in the link state and hand it to the
 * result handler, unless the link already failed or was aborted. */
void SignalLinkResult(s32 result) {
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == LINK_PHASE_ERROR) return;
    if (GetLinkPhase() == LINK_PHASE_ABORTED) return;
    state = &gLinkState;
    M2C_FIELD(state, s32 *, LINK_STATE_RESULT_CODE) = result;
    if (M2C_FIELD(state, void (**)(s32, s32), LINK_STATE_RESULT_HANDLER) == NULL) return;
    M2C_FIELD(state, void (**)(s32, s32), LINK_STATE_RESULT_HANDLER)(result, 0);
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

/* Ask the ARM7 to measure `channel` so the player on it announces itself to the
 * link; the scan's answer goes to `callback` (HandleLinkAnnounceEvent). */
void RequestLinkPlayerAnnounce(M2C_UNK callback, M2C_UNK channel) {
    M2C_UNK WFC_MeasureChannel(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    WFC_MeasureChannel(callback, WFC_SCAN_CCA_MODE, WFC_SCAN_ED_THRESHOLD, channel, WFC_SCAN_MEASURE_TIME);
}

s32 __clz(u32);
s32 __cntlz(u32);
s32 _CountLeadingZeros(u32);
s32 __builtin_clz(u32);
#pragma intrinsic(__builtin_clz)
s16 PickRandomSetBit(s32 arg0) {
u32 CountBits();u32 LinkRngNext();s32 __builtin_clz(u32);
s16 result=0;u32 temp=CountBits();s32 n;u16 count;s32 i;
if(temp==1){n=0x20-__builtin_clz(~arg0&(arg0-1));result=n+1;}
else if(temp>1U){
count=(temp*(LinkRngNext()&255))>>8;
i=result;goto test;
loop: {if((arg0&(1<<i))!=0 && count--==0){result=i+1;goto done;}i++;}
test:if(i<16)goto loop;
}
done:return result;
}
/* Start the overlay's DS Download Play session: move the link to the pending
 * phase and queue the start request, whose completion HandleLinkDownloadPlayResult
 * takes.  A failed queue signals the link error and aborts the session. */
s32 StartLinkDownloadPlay(void) {
    s32 WFC_StartDownloadPlay(M2C_UNK *, M2C_UNK *);
    void SignalLinkError();
    extern M2C_UNK gLinkDownloadHeader;
    extern M2C_UNK HandleLinkDownloadPlayResult;
    SetLinkPhase(LINK_PHASE_PENDING);
    if (WFC_StartDownloadPlay(&HandleLinkDownloadPlayResult, &gLinkDownloadHeader) == 2 /* WFC_CMD_OK */) return 1;
    SignalLinkError();
    SetLinkPhase(LINK_PHASE_ERROR);
    return 0;
}

/* Completion callback of the DS Download Play start (WFC_StartDownloadPlay): a
 * nonzero result signals the link event and moves the link to its error phase;
 * otherwise the child-indication task is queued, and if that fails the link is
 * put into the error phase too (StartLinkChildIndicate already signalled it). */
void HandleLinkDownloadPlayResult(void *result) {
    s32 StartLinkChildIndicate();
    if (M2C_FIELD(result, u16 *, LINK_WFC_EVENT_RESULT) != 0) {
        SignalLinkEvent();
        SetLinkPhase(LINK_PHASE_ERROR);
        return;
    }
    if (StartLinkChildIndicate() != 0) {
        return;
    }
    SetLinkPhase(LINK_PHASE_ERROR);
}

/* Queue the Download Play child-indication task, whose callback HandleLinkChildIndicate
 * reports child connect/disconnect events: a task that fails to queue aborts the link,
 * otherwise this console marks itself connected and clears the handled link results.  A
 * link already up (phase 4 or 5) needs nothing. */
s32 StartLinkChildIndicate(void) {
    s32 func_02012474(void (*)(void *));
    M2C_UNK SetConnectedPlayers(s32);
    M2C_UNK ClearLinkEventFlags();
    void SignalLinkError();
    void HandleLinkChildIndicate(void *);
    s32 phase = GetLinkPhase();
    switch (phase) {
    case LINK_PHASE_ACTIVE:
    case LINK_PHASE_INGAME: return 1;
    default:
        if (func_02012474(&HandleLinkChildIndicate) != LINK_TASK_QUEUED) {
            SignalLinkError();
            return 0;
        }
        SetConnectedPlayers(1);
        ClearLinkEventFlags();
        return 1;
    }
}

#pragma opt_common_subs off
#pragma opt_propagation off
void HandleLinkChildIndicate(void *event) {
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
s32 MultiBoot_StartLinkTask(void (*)(void *),M2C_UNK *,u16,M2C_UNK *,u16,s32);
extern M2C_UNK gLinkState,gLinkTransferData,gLinkTransferExtra;
s32 phase=GetLinkPhase();switch(phase){case 4:case 5:return 1;default:break;}
if(WFC_SetChannelHandler(4,HandleLinkChannelEvent,0)!=0) {SignalLinkError();return 0;}
if(WFC_SetChannelHandler(12,HandleLinkChannelEvent,0)!=0) {SignalLinkError();return 0;}
M2C_FIELD(&gLinkState,u8 *,0)=0;
SetLinkPhase(4);
if(MultiBoot_StartLinkTask(HandleLinkConnectTaskEvent,&gLinkTransferData,(u16)M2C_FIELD(&gLinkState,u32 *,0x34),&gLinkTransferExtra,(u16)M2C_FIELD(&gLinkState,u32 *,0x14),1)==2)return 1;
SignalLinkError();return 0;
}

/* Report a connection error or announce the local player when the link comes up. */
void HandleLinkConnectTaskEvent(void *event) {
    s8 GetLinkLocalPlayerId();
    extern M2C_UNK gLinkState;
    u16 status = ((LinkCompletionEvent *)event)->status;
    if (status != 0) {
        SignalLinkEvent(status);
        SetLinkPhase(LINK_PHASE_ERROR);
        return;
    }
    switch (((LinkCompletionEvent *)event)->command) {
    case LINK_TASK_CMD_DATA_DONE:
        SetLinkPhase(LINK_PHASE_ACTIVE);
        M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) =
            M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) | LINK_STATE_FLAG_LINKED;
        M2C_FIELD(&gLinkState, u8 *, LINK_STATE_LOCAL_PLAYER) = GetLinkLocalPlayerId();
        AnnounceLinkPlayer();
        return;
    case 11:
        return;
    case 12:
        return;
    case 13:
        return;
    default:
        return;
    }
}

#pragma scheduling off
s32 func_ov009_02222f84(void) {
s32 func_02011d58(void); s32 func_02011e98(void); s32 Mb_SendMatchProfile(void *,void *);
extern M2C_UNK data_ov009_022268e0; extern M2C_UNK gLinkConnectionData; extern M2C_UNK data_ov009_02226960; extern M2C_UNK func_ov009_02223078;
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
M2C_FIELD(&data_ov009_022268e0,void **,0x80)=&gLinkConnectionData;
result=Mb_SendMatchProfile(&func_ov009_02223078,&data_ov009_02226960);
if(result==2) return 1;
func_ov009_022227d4(result);
return 0;
}
#pragma scheduling reset
/* Per-frame per-peer-slot callback: count the slot's frames-left timer down and
 * release the slot when it runs out. */
void UpdateLinkPeerSlotTimer(void *slot) {
    M2C_FIELD(slot, s16 *, LINK_PEER_SLOT_TIMER) = (s16) (M2C_FIELD(slot, s16 *, LINK_PEER_SLOT_TIMER) - 1);
    if ((s32) M2C_FIELD(slot, s16 *, LINK_PEER_SLOT_TIMER) <= 0) {
        M2C_FIELD(slot, s32 *, LINK_PEER_SLOT_IN_USE) = 0;
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
    s32 SendLinkStepCommand(void);
    void DC_InvalidateRange(void *, s32);
    s32 IsConnectionDataValid(void *);
    s32 func_ov009_02222f84(void);
    s32 func_ov009_02222348(s32);
    extern Ov009CallbackFn gLinkSession[];
    extern M2C_UNK gLinkPeerSlots;
    extern M2C_UNK gLinkConnectionExtraData;
    extern M2C_UNK gLinkConnectionData;
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
    r7 = (u8 *)&gLinkPeerSlots;
    r5 = (u8 *)&gLinkConnectionExtraData;
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
        if (SendLinkStepCommand() != 0) return;
        SetLinkPhase(8);
        return;
    }

    t8 = M2C_FIELD(arg0, u16 *, 8);
    if(t8==3 || t8==4) goto done;
    if (t8 == 5) {
        DC_InvalidateRange(&gLinkConnectionData, 0xc0);
        if (M2C_FIELD(&gLinkState, s32 *, 0x30) != 0 &&
            IsConnectionDataValid(&gLinkConnectionData) != 0) {
            cb = M2C_FIELD(&gLinkState, void (**)(void *), 0x4c);
            if (cb != 0) cb(&gLinkConnectionData);
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
                        func_ov009_02222348((s32)&gLinkConnectionData);
                        cb2 = M2C_FIELD(&gLinkState, void (**)(void *), 0x4c);
                        if (cb2 != 0) cb2(&gLinkConnectionData);
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
/* Queue the link's WFC link-step command (command 11), whose completion
 * HandleLinkStepResult takes; returns 1 once queued, or signals the link error
 * and returns 0. */
s32 SendLinkStepCommand(void) {
    s32 WFC_SendCommand11(void (*)(void *));
    void HandleLinkStepResult(void *);
    if (WFC_SendCommand11(HandleLinkStepResult) == LINK_TASK_QUEUED) return 1;
    SignalLinkError();
    return 0;
}

/* Completion handler of the link step command: a nonzero task state is passed on
 * as the link event, otherwise the link moves on to the READY phase so the next
 * setup step can start. */
void HandleLinkStepResult(void *event) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    void SignalLinkEvent(s32);
    u16 state;

    state = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
    if (state != 0) {
        SignalLinkEvent(state);
        return;
    }
    SetLinkPhase(LINK_PHASE_READY);
}

