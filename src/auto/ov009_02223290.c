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
    extern M2C_UNK gLinkState, gLinkTransferExtra, func_ov009_022236c0;
    s32 result;
    DC_FlushRange(&gLinkTransferExtra, M2C_FIELD(&gLinkState,s32 *,LINK_STATE_EXTRA_LEN));
    result = WFC_SendChannelData(&func_ov009_022236c0,completion,packet,length,playerMask,channel,2);
    if (result != 2) {
        if (result != 7) SignalLinkError();
        return 0;
    }
    return 1;
}

void func_ov009_022236c0(void *arg0) {
    M2C_UNK (*callback)(void *);
    u16 state = M2C_FIELD(arg0, u16 *, 2);
    if (state != 0 && state != 15) {
        SignalLinkEvent(state);
        return;
    }
    callback = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x20);
    if (callback == NULL) return;
    callback(arg0);
}

void func_ov009_022236f4(s32 arg0,u16 arg1,u16 arg2) {
M2C_UNK MI_CpuCopy8(s32,s32,M2C_UNK);
extern M2C_UNK gLinkState;
u8 buffer[12];
MI_CpuCopy8(arg0,(s32)buffer,12);
if(M2C_FIELD(&gLinkState,M2C_UNK (**)(s32,u16,u16),0x60)==NULL)return;
M2C_FIELD(&gLinkState,M2C_UNK (**)(s32,u16,u16),0x60)(arg0,arg1,arg2);
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

void func_ov009_02223a90(void *arg0) {
    void func_ov009_022236f4(s32, u16, u16);
    s32 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x14);
    if (temp_r0 == 0) {
        return;
    }
    func_ov009_022236f4(temp_r0, M2C_FIELD(arg0, u16 *, 0x18), M2C_FIELD(arg0, u16 *, 0x10));
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

s32 func_ov009_02223b5c(void) {
    s32 WFC_SendTeardownCommand(M2C_UNK *);
    extern M2C_UNK func_ov009_02223b8c;
    SetLinkPhase(3);
    if (WFC_SendTeardownCommand(&func_ov009_02223b8c) == 2) {
        return 1;
    }
    SignalLinkError();
    return 0;
}

void func_ov009_02223b8c(void *arg0) {
    s32 func_ov009_02223bbc();
    M2C_UNK CloseLinkChannel();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        CloseLinkChannel();
        return;
    }
    if (func_ov009_02223bbc() != 0) {
        return;
    }
    CloseLinkChannel();
}

s32 func_ov009_02223bbc(void) {
    s32 func_02012484(void (*)(void *));
    void func_ov009_02223be4(void *);
    if (func_02012484(func_ov009_02223be4) == 2) return 1;
    SignalLinkError();
    return 0;
}

void func_ov009_02223be4(void *arg0) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    M2C_UNK SignalLinkEvent();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        return;
    }
    SetLinkPhase(1);
}

s32 func_ov009_02223c08(void) {
    s32 WFC_SendTeardownCommand(M2C_UNK *);
    extern M2C_UNK func_ov009_02223c38;
    SetLinkPhase(3);
    if (WFC_SendTeardownCommand(&func_ov009_02223c38) == 2) {
        return 1;
    }
    SignalLinkError();
    return 0;
}

void func_ov009_02223c38(void *arg0) {
 s32 func_ov009_02223c60(void); M2C_UNK RestartLinkSession();
 if(M2C_FIELD(arg0,u16 *,2)!=0) {SignalLinkEvent();RestartLinkSession();return;}
 if(func_ov009_02223c60()!=0) return;
}

s32 func_ov009_02223c60(void) {
    s32 func_0201280c(void (*)(void *), s32);
    void func_ov009_02223c98(void *);
    M2C_UNK CloseLinkChannel();
    SetLinkPhase(3);
    if (func_0201280c(func_ov009_02223c98, 0) == 2) return 1;
    SignalLinkError();
    CloseLinkChannel();
    return 0;
}

void func_ov009_02223c98(void *arg0) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    M2C_UNK SignalLinkEvent();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        return;
    }
    SetLinkPhase(1);
}

void HandleLinkEndTaskEvent(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SetLinkPhase(9);
        return;
    }
    SetLinkPhase(0);
}

s32 func_ov009_02223ce4(void) {
    s32 func_02012274(M2C_UNK *);
    extern M2C_UNK func_ov009_02223d14;
    SetLinkPhase(3);
    if (func_02012274(&func_ov009_02223d14) == 2) {
        return 1;
    }
    SignalLinkError();
    return 0;
}

void func_ov009_02223d14(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        SetLinkPhase(8);
        return;
    }
    SetLinkPhase(1);
}

#pragma opt_common_subs off
/* Set or clear the link's download-transfer mode (LINK_STATE_FLAG_DOWNLOAD) and
 * hand the resulting flag to the WFC link command; a command result other than
 * 2 or 3 signals a link error.  Returns 1 when the command was queued. */
s32 SetLinkDownloadMode(s32 download) {
    extern M2C_UNK gLinkState, HandleLinkDownloadModeEvent;
    s32 func_02013e24(M2C_UNK *, s32);
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
    result = func_02013e24(&HandleLinkDownloadModeEvent, M2C_FIELD(&gLinkState, u8 *, LINK_STATE_FLAGS) & LINK_STATE_FLAG_DOWNLOAD);
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
void HandleLinkDownloadModeEvent(void *arg0) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    M2C_UNK SignalLinkEvent();
    if (M2C_FIELD(arg0, u16 *, 2) == 0) {
        return;
    }
    SignalLinkEvent();
    SetLinkPhase(8);
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

void HandleLinkDownloadDataEvent(void *arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 2);
    if ((temp_r0 != 0) && (temp_r0 != 1)) {
        SignalLinkEvent();
        SetLinkPhase(8);
    }
}

s32 func_ov009_02223e5c(void) {
 extern M2C_UNK gLinkState,func_ov009_02223ea8;
 s32 func_02012be4(M2C_UNK *,s32);
 u8 old=M2C_FIELD(&gLinkState,u8 *,0);
 M2C_FIELD(&gLinkState,u8 *,0)=old+1;
 if(old!=0) return 1;
 if(func_02012be4(&func_ov009_02223ea8,0)==2) return 1;
 SignalLinkError();return 0;
}

void func_ov009_02223ea8(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) == 0) {
        return;
    }
    SignalLinkEvent();
    SetLinkPhase(8);
}

s32 func_ov009_02223ec8(void) {
 extern M2C_UNK gLinkState,func_ov009_02223f14;
 s32 func_02012be4(M2C_UNK *,s32);
 u8 value=M2C_FIELD(&gLinkState,u8 *,0)-1;
 M2C_FIELD(&gLinkState,u8 *,0)=value;
 if(M2C_FIELD(&gLinkState,u8 *,0)!=0) return 1;
 if(func_02012be4(&func_ov009_02223f14,1)==2) return 1;
 SignalLinkError();return 0;
}

void func_ov009_02223f14(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) == 0) {
        return;
    }
    SignalLinkEvent();
    SetLinkPhase(8);
}

void SetLinkDownloadCode(s32 a) { extern M2C_UNK gLinkState; M2C_FIELD(&gLinkState,s32 *,0x108)=a; }

void SetLinkPlayerName(s32 src,u32 size){
 M2C_UNK MI_CpuCopy8(s32,s32,M2C_UNK);
 M2C_UNK MI_CpuFill8(void*,M2C_UNK,s32);
 extern M2C_UNK gLinkConnectionExtraData;
 if(size>24)size=24;
 MI_CpuCopy8(src,(s32)&gLinkConnectionExtraData,size);
 MI_CpuFill8((u8*)&gLinkConnectionExtraData+size,0,24-size);
}

void func_ov009_02223f7c(s32 a,s32 b){
 void func_ov009_0222140c(void*,s32,s32);
 extern M2C_UNK gLinkLocalPlayerInfo,gLinkState,gLinkDownloadHeader;
 func_ov009_0222140c(&gLinkLocalPlayerInfo,a,b);
 M2C_FIELD(&gLinkState,void**,0x100)=&gLinkLocalPlayerInfo;
 M2C_FIELD(&gLinkDownloadHeader,u16*,4)=0x60;
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

void func_ov009_02224024(void) {
    s32 GetLinkPhase();
    M2C_UNK QueueHostLinkPacket(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_ov009_022254d8();
    if ((GetLinkPhase() != 4) && (GetLinkPhase() != 5)) {
        return;
    }
    if (func_ov009_022254d8() == 0) {
        return;
    }
    QueueHostLinkPacket(5, 0, 0, 1);
}

M2C_UNK *GetLinkLocalPlayerInfo(void) {
    extern M2C_UNK gLinkLocalPlayerInfo;
    return &gLinkLocalPlayerInfo;
}

s32 GetActiveLinkPlayerSlot(s32 a){
 u16 GetConnectedPlayers(void);
 extern M2C_UNK gLinkPlayers;
 s32 p;
 if(!(GetConnectedPlayers()&(1<<a)))return 0;
 p=(s32)&gLinkPlayers+a*0x60;
 if(!(M2C_FIELD(p,u8*,0x16)&1))p=0;
 return p;
}

s32 GetLinkPlayerSlot(s32 arg0) {
    extern M2C_UNK gLinkPlayers;
    return (0x60 * arg0) + (s32) &gLinkPlayers;
}

s32 func_ov009_022240c0(s32 arg0, M2C_UNK arg1) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetLinkLocalPlayerInfo();
    if (temp_r0 == 0) {
        return 0;
    }
    MI_CpuCopy8(temp_r0 + 0x20, arg0, arg1);
    return arg0;
}

s32 func_ov009_022240f4(void) {
    s32 GetActiveLinkPlayerSlot();
    s32 temp_r0;

    temp_r0 = GetActiveLinkPlayerSlot();
    if (temp_r0 != 0) {
        return temp_r0 + 0x20;
    }
    return 0;
}

s32 CopyActiveLinkPlayerRecord(s32 a,s32 b,s32 c){
 s32 p=GetActiveLinkPlayerSlot(a);
 if(!p)return 0;
 MI_CpuCopy8(p+0x20,b,c);
 return b;
}

s32 func_ov009_02224140(s32 a){
 extern M2C_UNK gLinkState;
 s32 old=M2C_FIELD(&gLinkState,s32*,0x3c);
 M2C_FIELD(&gLinkState,s32*,0x3c)=a;
 return old;
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

void SetLinkPhaseRaw(s32 arg0) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, s32 *, 0x10) = arg0;
}

s32 GetLinkPhase(void) {
    extern M2C_UNK gLinkState;
    return M2C_FIELD(&gLinkState, s32 *, 0x10);
}

s32 GetLinkRequestKind(void){extern M2C_UNK gLinkState;return M2C_FIELD(&gLinkState,s32*,0x38);}

s32 GetLinkResultCode(void){extern M2C_UNK gLinkState;return M2C_FIELD(&gLinkState,s32*,12);}

s32 func_ov009_022241c4(s32 arg0) {
    extern M2C_UNK gLinkState;
    s32 old = M2C_FIELD(&gLinkState, s32 *, 0x2c);
    M2C_FIELD(&gLinkState, s32 *, 0x2c) = arg0;
    return old;
}

s32 func_ov009_022241dc(void) {
 void func_02007724(void *); void func_ov009_02222430(u32); s32 AnnounceNextLinkPlayer(s32);
 extern M2C_UNK data_ov009_022268e0;
 u16 mac[3]; s32 result;
 func_02007724(mac);
 func_ov009_02222430(*(u32 *)0x027FFC3C+mac[0]+mac[1]+mac[2]);
 M2C_FIELD(&data_ov009_022268e0,u16 *,2)=0;
 M2C_FIELD(&data_ov009_022268e0,u16 *,10)=101;
 func_ov009_02221320(3);
 result=AnnounceNextLinkPlayer(1);
 if(result==25) {func_ov009_022227d4();func_ov009_02221320(8);return 0;}
 if(result==2) return 1;
 func_ov009_022227d4();func_ov009_02221320(8);return 0;
}

