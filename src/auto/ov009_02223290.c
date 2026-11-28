/* 52 functions from 0x02223290 to 0x02224284 (ov009), found by ds-decomp. */
#include "common.h"
#include "ov009_link.h"
#include "wfc_channel.h"

/* Submit the Download Play connection data unless the link is already active. */
s32 StartDownloadPlayLinkConnection(void) {
    s32 WFC_SendConnectionData(s32, u16 *, void *, s32, u16);
    s32 SetConnectedPlayers(s32);
    s32 ClearLinkEventFlags();
    void HandleLinkTaskEvent(void *);
    extern s32 gLinkConnectionData, gLinkConnectionExtraData;
    s32 phase = GetLinkPhase();
    s32 result;

    switch (phase) {
    case LINK_PHASE_ACTIVE:
    case LINK_PHASE_INGAME:
        return 1;
    default:
        SetLinkPhase(LINK_PHASE_PENDING);
        result = WFC_SendConnectionData((s32)HandleLinkTaskEvent, (u16 *)&gLinkConnectionData, &gLinkConnectionExtraData, 1, 0);
        if (result != LINK_TASK_QUEUED) {
            SignalLinkError(result);
            return 0;
        }
        SetConnectedPlayers(1);
        ClearLinkEventFlags();
        return 1;
    }
}

/* Handle an event from the Download Play link task: report a dropped link,
 * retry a timing-out player through the link actor, or start the transfer. */
void HandleLinkTaskEvent(void *event) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK SignalLinkResult(M2C_UNK);
    s32 StartLinkTransfer();
    void ClearPlayerActive(s32,s32,s32,s32,s32);
    M2C_UNK SetConnectedPlayers(M2C_UNK);
    extern M2C_UNK gLinkActorClass;
    s32 retryCount;
    u16 state;
    u16 command;
    void *actor;

    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) != 0) {
        SignalLinkEvent();
        state = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
        switch (state) {
        case 12:
            SetLinkPhase(LINK_PHASE_RESULT);
            return;
        case 11:
            SetLinkPhase(LINK_PHASE_RESULT);
            return;
        case 1:
            SetLinkPhase(LINK_PHASE_RESULT);
            return;
        default:
            SetLinkPhase(LINK_PHASE_ERROR);
            return;
        }
    } else {
        command = M2C_FIELD(event, u16 *, LINK_EVENT_COMMAND);
        switch ((s32) command) {
        case 8:
            /* A player timed out: retry through the link actor a few times. */
            actor = FindObjectByClass(&gLinkActorClass);
            if (actor == NULL) {
                retryCount = 0;
            } else {
                M2C_FIELD(actor, s16 *, LINK_ACTOR_RETRY) = (s16) (M2C_FIELD(actor, s16 *, LINK_ACTOR_RETRY) + 1);
                retryCount = M2C_FIELD(actor, s16 *, LINK_ACTOR_RETRY);
            }
            if ((s32) retryCount < LINK_ACTOR_MAX_RETRY) {
                return;
            }
            SignalLinkResult(LINK_EVENT_COMPLETE);
            SetConnectedPlayers(0);
            ClearPlayerActive(M2C_FIELD(event, u16 *, LINK_EVENT_STATE), 0, 1, 0U, 0);
            SetLinkPhase(LINK_PHASE_RESULT);
            return;
        case 7:
            /* Start the transfer; fall back to the error phase if it fails. */
            SetLinkPhase(LINK_PHASE_ACTIVE);
            if (StartLinkTransfer() != 0) {
                return;
            }
            SetLinkPhase(LINK_PHASE_ERROR);
            return;
        case 9:
            SignalLinkResult(LINK_EVENT_COMPLETE);
            SetConnectedPlayers(0);
            ClearPlayerActive(M2C_FIELD(event, u16 *, LINK_EVENT_STATE), 0, 1, (u8) M2C_FIELD(event, u16 *, LINK_EVENT_VALUE), 0);
            SetLinkPhase(LINK_PHASE_RESULT);
            return;
        case 26:
            SetConnectedPlayers(0);
            ClearPlayerActive(M2C_FIELD(event, u16 *, LINK_EVENT_STATE), 1, 0, (u8) M2C_FIELD(event, u16 *, LINK_EVENT_VALUE), 0);
            return;
        default:
            SetLinkPhase(LINK_PHASE_ERROR);
            /* fallthrough */
        case 6:
            return;
        }
    }
}

/* StartLinkTransfer: registers the link event handler on WFC channels 4 and 12,
   then starts the download-play transfer (WFC command 14) of the two link
   buffers, whose lengths are held in gLinkState at +0x34 and +0x14.  Returns 1
   once the transfer is queued, or signals a link error and returns 0. */
s32 StartLinkTransfer(void) {
void HandleLinkChannelEvent(void *); void HandleLinkTransferTaskEvent(void *);
s32 WFC_SetChannelHandler(s32,void (*)(void *),s32);
s32 MultiBoot_StartLinkTask(void (*)(void *),M2C_UNK *,u16,M2C_UNK *,u16,s32);
extern M2C_UNK gLinkState,gLinkTransferData,gLinkTransferExtra;
if(WFC_SetChannelHandler(4,HandleLinkChannelEvent,0)!=0) {SignalLinkError();return 0;}
if(WFC_SetChannelHandler(12,HandleLinkChannelEvent,0)!=0) {SignalLinkError();return 0;}
M2C_FIELD(&gLinkState,u8 *,0)=0;
if(MultiBoot_StartLinkTask(HandleLinkTransferTaskEvent,&gLinkTransferData,(u16)M2C_FIELD(&gLinkState,u32 *,0x34),&gLinkTransferExtra,(u16)M2C_FIELD(&gLinkState,u32 *,0x14),1)==2)return 1;
SignalLinkError();return 0;
}

/* Completion callback of the Download Play transfer task that StartLinkTransfer
 * starts: a failed status signals the link error and moves to the error phase, and
 * the task's data-done command (LINK_TASK_CMD_DATA_DONE) marks the link up - it
 * enters the active phase, records this console's player slot, tells the peers
 * about itself and announces the local player again.  The benign statuses 9, 13
 * and 15 and the progress commands 11..13 are ignored. */
void HandleLinkTransferTaskEvent(void *event) {
    M2C_UNK QueueHostLinkPacket(s32,s32,s32,s32);
    s8 GetLinkLocalPlayerId();
    extern M2C_UNK gLinkState;
    u16 state = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
    if (state != 0) {
        switch (state) {
        case 9: return;
        case 13: return;
        case 15: return;
        }
        SignalLinkEvent(state);
        SetLinkPhase(LINK_PHASE_ERROR);
        return;
    }
    switch (M2C_FIELD(event, u16 *, LINK_TASK_EVENT_COMMAND)) {
    case LINK_TASK_CMD_DATA_DONE:
        SetLinkPhase(LINK_PHASE_ACTIVE);
        QueueHostLinkPacket(5,0,0,1);
        M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) = M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) | LINK_STATE_FLAG_LINKED;
        M2C_FIELD(&gLinkState, u8 *, LINK_STATE_LOCAL_PLAYER) = GetLinkLocalPlayerId();
        AnnounceLinkPlayer();
        return;
    case 11: return;
    case 12: return;
    case 13: return;
    default: return;
    }
}

/* Queues one link packet for the players in `playerMask` on a WFC channel
 * (4 or 12), flushing the shared extra transfer buffer first.  Returns 1 when
 * the send was queued; otherwise returns 0, signalling a link error unless the
 * channel was simply not ready (result 7). */
s32 SendLinkChannelData(s32 channel, s32 playerMask, void *packet, s32 length, M2C_UNK completion) {
    M2C_UNK DC_FlushRange(M2C_UNK *, s32);
    s32 WFC_SendChannelData(M2C_UNK *,s32,s32,s32,s32,s32,s32);
    extern M2C_UNK gLinkState, gLinkTransferExtra, HandleLinkChannelSendResult;
    s32 result;
    DC_FlushRange(&gLinkTransferExtra, M2C_FIELD(&gLinkState,s32 *,LINK_STATE_EXTRA_LEN));
    result = WFC_SendChannelData(&HandleLinkChannelSendResult,completion,packet,length,playerMask,channel,2);
    if (result != 2) {
        if (result != 7) SignalLinkError();
        return 0;
    }
    return 1;
}

/* WFC completion of a link channel send: a transfer that ended or was dropped
 * by the library (result 0 or 15) goes on to the completion registered with the
 * send, any other result signals the link event. */
void HandleLinkChannelSendResult(void *completion) {
    M2C_UNK (*callback)(void *);
    u16 state = M2C_FIELD(completion, u16 *, LINK_SEND_EVENT_RESULT);
    if (state != 0 && state != LINK_SEND_RESULT_DONE) {
        SignalLinkEvent(state);
        return;
    }
    callback = M2C_FIELD(completion, M2C_UNK (**)(void *), LINK_SEND_EVENT_COMPLETION);
    if (callback == NULL) return;
    callback(completion);
}

/* Hand link packet `packet` to the overlay's registered packet handler, after
 * copying its 12-byte packet header (which reads the header back into memory).
 * Nothing happens when no handler is installed. */
void DispatchLinkPacket(s32 packet, u16 arg1, u16 arg2) {
    M2C_UNK MI_CpuCopy8(s32,s32,M2C_UNK);
    extern M2C_UNK gLinkState;
    u8 packetHeader[12];
    MI_CpuCopy8(packet, (s32)packetHeader, 12);
    if (M2C_FIELD(&gLinkState, M2C_UNK (**)(s32,u16,u16), LINK_STATE_PACKET_HANDLER) == NULL) return;
    M2C_FIELD(&gLinkState, M2C_UNK (**)(s32,u16,u16), LINK_STATE_PACKET_HANDLER)(packet, arg1, arg2);
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
s32 HandleLinkChannelCommand(u16 arg0,u8 arg1,s32 arg2,u16 arg3) {
void *FindObjectByClass(M2C_UNK *);
M2C_UNK MI_CpuCopy8(s32,s32,s32);
s32 IsLinkHost(void);
u16 GetConnectedPlayers(void);
s8 GetLinkLocalPlayerId(void);
void func_ov009_02224fec(s32,s32,s32,s32,u32,s32);
void *func_ov009_0222132c(u32,s32);
M2C_UNK MI_CpuFill8(void *,s32,s32);
void WriteLinkPacketHeader(void *,u8,u8,u8,s32,u32,u16);
extern M2C_UNK gLinkActorClass,gLinkState,data_ov009_02226980,data_ov009_022269b0;
u8 buffer[12]; void *task; u8 *p;s32 mask;u8 type;u32 size;u16 all;
M2C_UNK (*callback)(u8,s32,u16);
if(arg0==21){
MI_CpuCopy8(arg2,(s32)buffer,12);
p=buffer;
if(M2C_FIELD(p,u32 *,0)==0x5f574c4d){
mask=(u32)(p[5]<<28)>>28;
task=FindObjectByClass(&gLinkActorClass);
if(task) M2C_FIELD(task+mask*4,s32 *,0x3c)=0;
if(IsLinkHost()){
mask=(u16)(M2C_FIELD(p,u16 *,6)^0);mask=(u16)(mask&(-1^(1<<arg1)));
mask=GetConnectedPlayers()&mask;
mask = (u16)(mask & (-1^(1<<GetLinkLocalPlayerId())));
if(mask)func_ov009_02224fec(p[4],(u32)(p[5]<<28)>>28,(u32)(p[5]<<24)>>28,M2C_FIELD(p,u32 *,8)?arg2+12:0,M2C_FIELD(p,u32 *,8),mask);
}
all=M2C_FIELD(p,u16 *,6);
if((all&(1<<GetLinkLocalPlayerId())) && (type=p[4])!=0 && type!=1){
size=M2C_FIELD(p,u32 *,8);
if(type<16){s32 low=(u32)(p[5]<<28)>>28;s32 high=(u32)(p[5]<<24)>>28;
u32 irq=*(volatile u16 *)0x04000208; void *list;void *node; s32 payload;payload=size?arg2+12:0;
*(volatile u16 *)0x04000208=0;
list=(u8 *)&data_ov009_02226980+low*12;
node=func_ov009_0222132c(size+16,32);
if(node==0){u16 old=*(volatile u16 *)0x04000208;*(volatile u16 *)0x04000208=irq;}
else{
MI_CpuFill8(node,0,16);
WriteLinkPacketHeader(node+4,type,low,high,payload,size,all);
if(M2C_FIELD(list,void **,4)==0){M2C_FIELD(list,void **,4)=node;M2C_FIELD(list,void **,0)=node;}
else{M2C_FIELD(M2C_FIELD(list,void **,4),void **,0)=node;M2C_FIELD(list,void **,4)=node;}
M2C_FIELD(list,s32 *,8)++;
{u16 old=*(volatile u16 *)0x04000208;*(volatile u16 *)0x04000208=irq;}
}}else{s32 low=(u32)(p[5]<<28)>>28;s32 high=(u32)(p[5]<<24)>>28;
u32 irq=*(volatile u16 *)0x04000208; void *list;void *node; s32 payload;payload=size?arg2+12:0;
*(volatile u16 *)0x04000208=0;
list=(u8 *)&data_ov009_022269b0+low*12;
node=func_ov009_0222132c(size+16,32);
if(node==0){u16 old=*(volatile u16 *)0x04000208;*(volatile u16 *)0x04000208=irq;}
else{
MI_CpuFill8(node,0,16);
WriteLinkPacketHeader(node+4,type,low,high,payload,size,all);
if(M2C_FIELD(list,void **,4)==0){M2C_FIELD(list,void **,4)=node;M2C_FIELD(list,void **,0)=node;}
else{M2C_FIELD(M2C_FIELD(list,void **,4),void **,0)=node;M2C_FIELD(list,void **,4)=node;}
M2C_FIELD(list,s32 *,8)++;
{u16 old=*(volatile u16 *)0x04000208;*(volatile u16 *)0x04000208=irq;}
}}
}
}}
callback=M2C_FIELD(&gLinkState,M2C_UNK (**)(u8,s32,u16),0x40);
if(callback)callback(arg1,arg2,arg3);
}
#pragma pop
void func_ov009_02223a24(void) {
    M2C_UNK RestartLinkSession();
    RestartLinkSession();
}

void ClearPlayerActive(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4){
extern M2C_UNK gLinkState,gLinkPlayers;
s8 *entry=(s8*)&gLinkPlayers+arg3*0x60;
u8 flags=M2C_FIELD(entry,u8*,0x16);
u16 mask=M2C_FIELD(&gLinkState,u16*,8);
M2C_UNK (*callback)(s32,s32,s32,s32,s32);
flags = flags & ~1;
mask = mask | (1 << arg3);
M2C_FIELD(entry,u8*,0x16)=flags;
M2C_FIELD(&gLinkState,u16*,8)=mask;
callback=M2C_FIELD(&gLinkState,M2C_UNK (**)(s32,s32,s32,s32,s32),0x1c);
if(callback==NULL)return;
callback(arg0,arg1,arg2,arg3,arg4);
}

/* Deliver the packet a completed link channel transfer carried to the link's
 * registered packet handler: a failed result only signals the link event, and a
 * completion with no payload does nothing. */
void DeliverLinkSendResult(void *completion) {
    void DispatchLinkPacket(s32, u16, u16);
    s32 packet;

    if (M2C_FIELD(completion, u16 *, LINK_SEND_EVENT_RESULT) != 0) {
        SignalLinkEvent();
        return;
    }
    packet = M2C_FIELD(completion, s32 *, LINK_SEND_EVENT_DATA);
    if (packet == 0) {
        return;
    }
    DispatchLinkPacket(packet, M2C_FIELD(completion, u16 *, LINK_SEND_EVENT_LENGTH), M2C_FIELD(completion, u16 *, LINK_SEND_EVENT_INDEX));
}

/* Callback of the Download Play link channels 4 and 12: a failed event reports
 * the link error, otherwise the received-data command 21 (with its payload and
 * length) and command 9 (with no payload) go to the link command handler, while
 * the completion commands 7, 25 and 26 are ignored. */
void HandleLinkChannelEvent(void *event) {
 M2C_UNK HandleLinkChannelCommand(u16,u8,s32,u16);
 u16 command;
 if(M2C_FIELD(event,u16 *,WFC_EVENT_RESULT)!=0) { SignalLinkEvent(M2C_FIELD(event,u16 *,WFC_EVENT_RESULT)); return; }
 command=M2C_FIELD(event,u16 *,WFC_EVENT_COMMAND);
 switch((s32)command) {
 case 7: return; case 25: case 26: return;
 case 21: HandleLinkChannelCommand(command,(u8)M2C_FIELD(event,u16 *,WFC_EVENT_BIT),M2C_FIELD(event,s32 *,WFC_EVENT_DATA),M2C_FIELD(event,u16 *,WFC_EVENT_LENGTH)); return;
 case 9: HandleLinkChannelCommand(command,(u8)M2C_FIELD(event,u16 *,WFC_EVENT_BIT),0,0); return;
 }
}

/* Restart the link session this console hosts: tear the Download Play link down
 * and reset its channel, so the session can start over.  The teardown's
 * completion (HandleLinkHostTeardown) closes the channel when a step fails;
 * returns 0 when the teardown itself cannot be queued. */
s32 RestartLinkHostSession(void) {
    s32 WFC_SendTeardownCommand(M2C_UNK *);
    extern M2C_UNK HandleLinkHostTeardown;
    SetLinkPhase(LINK_PHASE_PENDING);
    if (WFC_SendTeardownCommand(&HandleLinkHostTeardown) == LINK_TASK_QUEUED) {
        return 1;
    }
    SignalLinkError();
    return 0;
}

/* Completion of the host session's teardown command: a reported failure signals
 * the link event and closes the channel; otherwise the link's channel is reset
 * (returning it to the ready phase), and closing it is the fallback when that
 * reset cannot be queued. */
void HandleLinkHostTeardown(void *event) {
    s32 SendLinkResetCommand();
    M2C_UNK CloseLinkChannel();
    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) != 0) {
        SignalLinkEvent();
        CloseLinkChannel();
        return;
    }
    if (SendLinkResetCommand() != 0) {
        return;
    }
    CloseLinkChannel();
}

/* Queue the link's WFC reset command (WFC command 9), whose completion goes to
 * HandleLinkResetResult; returns 1 once queued, or signals the link error and
 * returns 0. */
s32 SendLinkResetCommand(void) {
    s32 WFC_SendCommand9(void (*)(void *));
    void HandleLinkResetResult(void *);
    if (WFC_SendCommand9(HandleLinkResetResult) == LINK_TASK_QUEUED) return 1;
    SignalLinkError();
    return 0;
}

/* Completion handler of the link reset command: a nonzero task state is passed on
 * as the pending link event, otherwise the link moves on to the READY phase so the
 * next setup step can start. */
void HandleLinkResetResult(void *event) {
    s32 SetLinkPhase(M2C_UNK);
    M2C_UNK SignalLinkEvent();
    u16 state;

    state = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
    if (state != 0) {
        SignalLinkEvent(state);
        return;
    }
    SetLinkPhase(LINK_PHASE_READY);
}

/* Tear the link's session down before it is set up again: put the link in
 * LINK_PHASE_PENDING and post the WFC teardown command, whose completion
 * HandleTeardownSetupResult picks up.  Returns 1 once the command is queued
 * (WFC_CMD_OK, 2); a failure signals the link error and returns 0. */
s32 TeardownLinkAndQueueSetup(void) {
    s32 WFC_SendTeardownCommand(M2C_UNK *);
    extern M2C_UNK HandleTeardownSetupResult;

    SetLinkPhase(LINK_PHASE_PENDING);
    if (WFC_SendTeardownCommand(&HandleTeardownSetupResult) == 2) {
        return 1;
    }
    SignalLinkError();
    return 0;
}

/* Completion of the WFC teardown command posted by TeardownLinkAndQueueSetup: a
 * failed teardown (a nonzero status) signals the link event and restarts the
 * session, a good one queues the link's next setup command. */
void HandleTeardownSetupResult(void *result) {
    s32 QueueLinkSetupCommand(void);

    if (M2C_FIELD(result, u16 *, LINK_EVENT_STATE) != 0) {
        SignalLinkEvent();
        RestartLinkSession();
        return;
    }
    if (QueueLinkSetupCommand() != 0) {
        return;
    }
}

/* Queue the link's next setup command, a WFC command whose completion callback
 * FinishLinkSetupCommand continues the state machine: the link is marked pending
 * first; when the command cannot be queued the link error is signalled and the
 * channel closed.  Returns 1 once the command is queued, 0 on failure. */
s32 QueueLinkSetupCommand(void) {
    s32 func_0201280c(void (*)(void *), s32);
    void FinishLinkSetupCommand(void *);
    M2C_UNK CloseLinkChannel();
    SetLinkPhase(LINK_PHASE_PENDING);
    if (func_0201280c(FinishLinkSetupCommand, 0) == 2) return 1;
    SignalLinkError();
    CloseLinkChannel();
    return 0;
}

/* Completion of the link's setup command: a failed status (a nonzero task
 * state) raises the pending link event, otherwise the link moves on to the
 * READY phase. */
void FinishLinkSetupCommand(void *event) {
    s32 SetLinkPhase(M2C_UNK);
    M2C_UNK SignalLinkEvent();
    u16 state;

    state = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
    if (state != 0) {
        SignalLinkEvent(state);
        return;
    }
    SetLinkPhase(LINK_PHASE_READY);
}

/* Completion callback of the link-end task: a failed status aborts the link,
 * otherwise the link returns to idle. */
void HandleLinkEndTaskEvent(void *event) {
    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) != 0) {
        SetLinkPhase(LINK_PHASE_ABORTED);
        return;
    }
    SetLinkPhase(LINK_PHASE_IDLE);
}

/* Queue the WFC stop command that ends the link session: mark the link pending
 * first, and signal the link error when the command cannot be queued.  Returns 1
 * once the command is queued, 0 on failure. */
s32 SendLinkStopCommand(void) {
    s32 WFC_SendCommand1(M2C_UNK *);
    extern M2C_UNK FinishLinkStopCommand;
    SetLinkPhase(LINK_PHASE_PENDING);
    if (WFC_SendCommand1(&FinishLinkStopCommand) == LINK_TASK_QUEUED) {
        return 1;
    }
    SignalLinkError();
    return 0;
}

/* Completion of the WFC stop command queued by SendLinkStopCommand: a failed
 * stop signals the link event and moves the link to the error phase; a successful
 * one makes the link ready for the next setup step. */
void FinishLinkStopCommand(void *event) {
    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) != 0) {
        SignalLinkEvent();
        SetLinkPhase(LINK_PHASE_ERROR);
        return;
    }
    SetLinkPhase(LINK_PHASE_READY);
}

#pragma opt_common_subs off
/* Set or clear the link's download-transfer mode (LINK_STATE_FLAG_DOWNLOAD) and
 * hand the resulting flag to the WFC link command; a command result other than
 * 2 or 3 signals a link error.  Returns 1 when the command was queued. */
s32 SetLinkDownloadMode(s32 download) {
    extern M2C_UNK gLinkState, HandleLinkDownloadModeEvent;
    s32 WFC_SubmitDownloadMode(M2C_UNK *, s32);
    s32 result;
    u8 flags;
    if (download) {
        flags = M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS);
        flags |= LINK_STATE_FLAG_DOWNLOAD;
        M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) = flags;
    } else {
        flags = M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS);
        flags &= ~LINK_STATE_FLAG_DOWNLOAD;
        M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) = flags;
    }
    result = WFC_SubmitDownloadMode(&HandleLinkDownloadModeEvent, M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) & LINK_STATE_FLAG_DOWNLOAD);
    switch (result) {
    case 2:
    case 3:
        break;
    default:
        SignalLinkError();
        return 0;
    }
    return 1;
}
#pragma opt_common_subs reset
/* Completion of the WFC download-mode command submitted by SetLinkDownloadMode:
 * a nonzero task status is passed on as the link event and moves the link to
 * the error phase. */
void HandleLinkDownloadModeEvent(void *event) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    M2C_UNK SignalLinkEvent();
    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) == 0) {
        return;
    }
    SignalLinkEvent();
    SetLinkPhase(LINK_PHASE_ERROR);
}

/* Submit the link's download-play data block: send the payload with the transfer
 * code, the header's sequence word and the download flag; WFC results 2 and 3
 * mean the request was queued. */
s32 SubmitLinkDownloadData(void) {
 extern M2C_UNK gLinkState,gLinkDownloadHeader,HandleLinkDownloadDataEvent;
 s32 WFC_SubmitDownloadData(M2C_UNK *,s32,u16,s32,u16,u8);
 s32 result;
 result=WFC_SubmitDownloadData(&HandleLinkDownloadDataEvent,M2C_FIELD(&gLinkState,s32 *,LINK_STATE_DOWNLOAD_DATA),M2C_FIELD(&gLinkDownloadHeader,u16 *,LINK_DOWNLOAD_LENGTH),M2C_FIELD(&gLinkState,s32 *,LINK_STATE_DOWNLOAD_CODE),M2C_FIELD(&gLinkDownloadHeader,u16 *,LINK_DOWNLOAD_SEQUENCE),(u8)((M2C_FIELD(&gLinkState,u8 *,LINK_STATE_FLAGS)&LINK_STATE_FLAG_DOWNLOAD)!=0));
 switch(result) {case LINK_TASK_QUEUED: case 3: break; default: SignalLinkError();return 0;} return 1;
}

/* Download Play data event: a status other than 0 or 1 means the transfer
 * failed, so signal it and move on to the error phase. */
void HandleLinkDownloadDataEvent(void *event) {
    u16 status;

    status = M2C_FIELD(event, u16 *, LINK_EVENT_STATE);
    if ((status != 0) && (status != 1)) {
        SignalLinkEvent();
        SetLinkPhase(LINK_PHASE_ERROR);
    }
}

/* Add a user of the link's event notifications: bump the listener count at
 * gLinkState+0 and, when it is the first user, install the handler
 * HandleLinkEventsAdded through WFC command 0x23 (mode 0).  Returns 1 once the
 * listener is installed, or signals a link error and returns 0. */
s32 AddLinkEventListener(void) {
    extern M2C_UNK gLinkState, HandleLinkEventsAdded;
    s32 WFC_SetLinkEvents(M2C_UNK *, s32);
    u8 old = M2C_FIELD(&gLinkState, u8 *, LINK_STATE_LISTENER_COUNT);
    M2C_FIELD(&gLinkState, u8 *, LINK_STATE_LISTENER_COUNT) = old + 1;
    if (old != 0) return 1;
    if (WFC_SetLinkEvents(&HandleLinkEventsAdded, 0) == LINK_TASK_QUEUED) return 1;
    SignalLinkError();
    return 0;
}

/* Completion of the WFC event-notification install command (command 0x23, mode 0)
 * queued by AddLinkEventListener: a nonzero task status is passed on as the link
 * event and moves the link to the error phase. */
void HandleLinkEventsAdded(void *event) {
    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) == 0) {
        return;
    }
    SignalLinkEvent();
    SetLinkPhase(LINK_PHASE_ERROR);
}

/* Drop one user of the link's event notifications: decrement the listener count
 * and, with the last user gone, uninstall the handler through WFC command 0x23
 * (mode 1).  Returns 1 while listeners remain or once it is uninstalled, or
 * signals a link error and returns 0 when the command is not queued. */
s32 RemoveLinkEventListener(void) {
    extern M2C_UNK gLinkState, HandleLinkEventsRemoved;
    s32 WFC_SetLinkEvents(M2C_UNK *, s32);
    u8 old = M2C_FIELD(&gLinkState, u8 *, LINK_STATE_LISTENER_COUNT);
    M2C_FIELD(&gLinkState, u8 *, LINK_STATE_LISTENER_COUNT) = old - 1;
    if (M2C_FIELD(&gLinkState, u8 *, LINK_STATE_LISTENER_COUNT) != 0) return 1;
    if (WFC_SetLinkEvents(&HandleLinkEventsRemoved, 1) == LINK_TASK_QUEUED) return 1;
    SignalLinkError();
    return 0;
}

/* Completion of the WFC event-notification uninstall command (command 0x23, mode 1)
 * queued by RemoveLinkEventListener: a nonzero task status is passed on as the link
 * event and moves the link to the error phase. */
void HandleLinkEventsRemoved(void *event) {
    if (M2C_FIELD(event, u16 *, LINK_EVENT_STATE) == 0) {
        return;
    }
    SignalLinkEvent();
    SetLinkPhase(LINK_PHASE_ERROR);
}

void SetLinkDownloadCode(s32 a) { extern M2C_UNK gLinkState; M2C_FIELD(&gLinkState,s32 *,0x108)=a; }

/* Store the local player's name in the Download Play connection request's
 * extra-data block: copy at most LINK_CONNECTION_NAME_SIZE bytes and zero the
 * remainder of the name area. */
void SetLinkPlayerName(s32 name,u32 length){
 M2C_UNK MI_CpuCopy8(s32,s32,M2C_UNK);
 M2C_UNK MI_CpuFill8(void*,M2C_UNK,s32);
 extern M2C_UNK gLinkConnectionExtraData;
 if(length>LINK_CONNECTION_NAME_SIZE)length=LINK_CONNECTION_NAME_SIZE;
 MI_CpuCopy8(name,(s32)&gLinkConnectionExtraData,length);
 MI_CpuFill8((u8*)&gLinkConnectionExtraData+length,0,LINK_CONNECTION_NAME_SIZE-length);
}

/* Stage a buffer as this console's local-player record: copy it into the payload
 * area of gLinkLocalPlayerInfo, point the link's download-play data at that block
 * and set the transfer header's length to the full announce record size. */
void StageLinkLocalPlayerRecord(s32 src, s32 size) {
    void CopyLinkPlayerRecordPayload(void*, s32, s32);
    extern M2C_UNK gLinkLocalPlayerInfo, gLinkState, gLinkDownloadHeader;

    CopyLinkPlayerRecordPayload(&gLinkLocalPlayerInfo, src, size);
    M2C_FIELD(&gLinkState, void **, LINK_STATE_DOWNLOAD_DATA) = &gLinkLocalPlayerInfo;
    M2C_FIELD(&gLinkDownloadHeader, u16 *, LINK_DOWNLOAD_LENGTH) = LINK_PLAYER_ANNOUNCE_SIZE;
}

/* Announce this console's player record to the link: the host first publishes its
 * record as the download data, then, once the link is up, the local player's
 * record is stored in its slot and broadcast as LINK_MSG_PLAYER_ANNOUNCE. */
s32 AnnounceLinkPlayer(void){
 s32 IsLinkHost(void);
 s32 PublishLinkPlayerRecord(void);
 s32 GetLinkPhase(void);
 s8 GetLinkLocalPlayerId(void);
 void SetLinkPlayerRecord(s32,void*);
 M2C_UNK QueueHostLinkPacket(s32,s32,s32,s32);
 extern M2C_UNK gLinkLocalPlayerInfo;
 if(IsLinkHost()){if(!PublishLinkPlayerRecord())return 0;}
 if(GetLinkPhase()==LINK_PHASE_ACTIVE || GetLinkPhase()==LINK_PHASE_INGAME){
 SetLinkPlayerRecord(GetLinkLocalPlayerId(),&gLinkLocalPlayerInfo);
 QueueHostLinkPacket(LINK_MSG_PLAYER_ANNOUNCE,(s32)&gLinkLocalPlayerInfo,LINK_PLAYER_ANNOUNCE_SIZE,0xffff);
 }return 1;
}

/* While this console is a guest in an active link, ask the host (player slot 0)
 * for the connected-player mask again. */
void RequestConnectedPlayers(void) {
    s32 GetLinkPhase();
    M2C_UNK QueueHostLinkPacket(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 IsLinkGuest();

    if ((GetLinkPhase() != LINK_PHASE_ACTIVE) && (GetLinkPhase() != LINK_PHASE_INGAME)) {
        return;
    }
    if (IsLinkGuest() == 0) {
        return;
    }
    QueueHostLinkPacket(LINK_MSG_CONNECT_REQUEST, 0, 0, 1);
}

M2C_UNK *GetLinkLocalPlayerInfo(void) {
    extern M2C_UNK gLinkLocalPlayerInfo;
    return &gLinkLocalPlayerInfo;
}

/* Return player slot `player`'s record when the link lists it as connected and its
 * slot flag still says it holds a player, otherwise NULL. */
s32 GetActiveLinkPlayerSlot(s32 player) {
    u16 GetConnectedPlayers(void);
    extern M2C_UNK gLinkPlayers;
    s32 slot;
    if (!(GetConnectedPlayers() & (1 << player))) return 0;
    slot = (s32)&gLinkPlayers + player * LINK_PLAYER_SLOT_STRIDE;
    if (!(M2C_FIELD(slot, u8 *, LINK_PLAYER_FLAGS) & LINK_PLAYER_CONNECTED)) slot = 0;
    return slot;
}

/* The gLinkPlayers slot belonging to player `player`. */
s32 GetLinkPlayerSlot(s32 player) {
    extern M2C_UNK gLinkPlayers;
    return (LINK_PLAYER_SLOT_STRIDE * player) + (s32) &gLinkPlayers;
}

/* Copy the local link player's record (the LINK_PLAYER_SLOT_RECORD bytes of the
 * local announce block) into `dest` for `length` bytes.  Returns `dest`, or 0 when
 * there is no local player info. */
s32 CopyLinkLocalPlayerRecord(s32 dest, M2C_UNK length) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    s32 localInfo;

    localInfo = GetLinkLocalPlayerInfo();
    if (localInfo == 0) {
        return 0;
    }
    MI_CpuCopy8(localInfo + LINK_PLAYER_SLOT_RECORD, dest, length);
    return dest;
}

/* The 0x40-byte player record of the connected player in link slot `player`,
 * or NULL when that slot has no connected player. */
s32 GetActiveLinkPlayerRecord(s32 player) {
    s32 GetActiveLinkPlayerSlot(s32);
    s32 slot;

    slot = GetActiveLinkPlayerSlot(player);
    if (slot != 0)
        return slot + LINK_PLAYER_SLOT_RECORD;
    return 0;
}

/* Copy the LINK_PLAYER_SLOT_RECORD bytes of an active player's link record into
 * `dest` for `length` bytes; `dest` is returned, or 0 when the player slot is not
 * active. */
s32 CopyActiveLinkPlayerRecord(s32 player, s32 dest, s32 length) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    s32 slot = GetActiveLinkPlayerSlot(player);

    if (!slot) return 0;
    MI_CpuCopy8(slot + LINK_PLAYER_SLOT_RECORD, dest, length);
    return dest;
}

/* Set the handler the overlay's general WFC events are forwarded to
 * (LINK_STATE_EVENT_HANDLER) and return the previous one. */
s32 SetLinkEventHandler(s32 handler) {
    extern M2C_UNK gLinkState;
    s32 previous = M2C_FIELD(&gLinkState, s32 *, LINK_STATE_EVENT_HANDLER);

    M2C_FIELD(&gLinkState, s32 *, LINK_STATE_EVENT_HANDLER) = handler;
    return previous;
}

void func_ov009_02224158(void) {
    M2C_UNK WFC_GetLinkStatusValue();
    WFC_GetLinkStatusValue();
}

M2C_UNK SetConnectedPlayers(s32 a) {extern u16 gLinkSession; gLinkSession=a;}

u16 GetConnectedPlayers(void) {
    extern u16 gLinkSession;
    return gLinkSession;
}

/* Write the link state machine's phase (LINK_PHASE_*) without the side effects
 * SetLinkPhase runs before and after it. */
void SetLinkPhaseRaw(s32 phase) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, s32 *, LINK_STATE_PHASE) = phase;
}

s32 GetLinkPhase(void) {
    extern M2C_UNK gLinkState;
    return M2C_FIELD(&gLinkState, s32 *, 0x10);
}

s32 GetLinkRequestKind(void){extern M2C_UNK gLinkState;return M2C_FIELD(&gLinkState,s32*,0x38);}

s32 GetLinkResultCode(void){extern M2C_UNK gLinkState;return M2C_FIELD(&gLinkState,s32*,12);}

/* Install `handler` as the link's result handler (LINK_STATE_RESULT_HANDLER)
 * and return the handler it replaces. */
s32 SetLinkResultHandler(s32 handler) {
    extern M2C_UNK gLinkState;
    s32 old = M2C_FIELD(&gLinkState, s32 *, LINK_STATE_RESULT_HANDLER);
    M2C_FIELD(&gLinkState, s32 *, LINK_STATE_RESULT_HANDLER) = handler;
    return old;
}

s32 func_ov009_022241dc(void) {
 void func_02007724(void *); void LinkRngSeed(u32); s32 AnnounceNextLinkPlayer(s32);
 extern M2C_UNK data_ov009_022268e0;
 u16 mac[3]; s32 result;
 func_02007724(mac);
 LinkRngSeed(*(u32 *)0x027FFC3C+mac[0]+mac[1]+mac[2]);
 M2C_FIELD(&data_ov009_022268e0,u16 *,2)=0;
 M2C_FIELD(&data_ov009_022268e0,u16 *,10)=101;
 func_ov009_02221320(3);
 result=AnnounceNextLinkPlayer(1);
 if(result==25) {func_ov009_022227d4();func_ov009_02221320(8);return 0;}
 if(result==2) return 1;
 func_ov009_022227d4();func_ov009_02221320(8);return 0;
}

