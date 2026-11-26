/* 37 functions from 0x02187590 to 0x0218851C (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
#include "ov001_link.h"
#include "wfc.h"

#pragma merge_duplicate_code off
/* Callback the multiboot command layer runs for the ov001 Download Play link.
 * Each event moves the child's bit between the link header's stage bitmaps as it
 * joins, reports its info block or leaves, and fills the child's work-block
 * record.  On teardown the pending multiboot requests are dropped; a status event
 * either fails the link or is ignored.  Events are MB_EVENT_* ids; packet is the
 * event's record (a join request or a status word) or NULL. */
void Ov001_HandleLinkEvent(s32 player, u32 event, const u8 *packet) {
    extern s16 *gOv001LinkWork;
    u16 Ov001_GetLinkStatus(void);
    void Ov001_SetLinkStatus(s16);
    s32 Ov001_GetPlayerStage(s32);
    void Ov001_TryStartTransfer(void);
    void Ov001_HandleChildPhase1(s32);
    void Ov001_HandleChildPhase0(s32);
    void Ov001_CompletePlayerLeave(s32);
    void *MultiBoot_GetPlayerInfo(s32);
    void *OS_DisableInterrupts();
    void OS_RestoreInterrupts(void *);
    s32 MI_CpuCopy8(void *, void *, s32);
    void SystemHalt(void);
    u16 *header;
    u8 *address;
    s32 offset;
    void *interrupts;
    void *child;
    u16 clearMask;
    u16 status;

    switch (event) {
    case MB_EVENT_JOIN:
        if (Ov001_GetLinkStatus() != 2) return;
        header = (u16 *)gOv001LinkWork;
        interrupts = OS_DisableInterrupts();
        header[OV001_LINK_JOINED / 2] |= 1 << player;
        OS_RestoreInterrupts(interrupts);
        offset = (player - 1) * OV001_LINK_RECORD_SIZE;
        address = (u8 *)gOv001LinkWork + OV001_LINK_RECORDS + OV001_LINK_RECORD_ADDRESS + offset;
        address[0] = packet[0xa];
        address[1] = packet[0xb];
        address[2] = packet[0xc];
        address[3] = packet[0xd];
        address[4] = packet[0xe];
        address[5] = packet[0xf];
        M2C_FIELD((u8 *)gOv001LinkWork + OV001_LINK_RECORDS + offset, u16 *, OV001_LINK_RECORD_ID) = player;
        return;
    case MB_EVENT_LEAVE:
        if (Ov001_GetPlayerStage(player) == 6) return;
        clearMask = ~(1 << player);
        interrupts = OS_DisableInterrupts();
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_PENDING) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_ANSWERED) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED_COPY) &= clearMask;
        OS_RestoreInterrupts(interrupts);
        Ov001_TryStartTransfer();
        return;
    case MB_EVENT_PLAYER_DATA:
        if (Ov001_GetLinkStatus() != 2) {
            Ov001_HandleChildPhase0(player);
            return;
        }
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) |= 1 << player;
        Ov001_HandleChildPhase1(player);
        child = MultiBoot_GetPlayerInfo(player);
        if (child == NULL) return;
        MI_CpuCopy8(child, (u8 *)gOv001LinkWork + OV001_LINK_RECORDS + (player - 1) * OV001_LINK_RECORD_SIZE, OV001_LINK_RECORD_INFO_SIZE);
        return;
    case MB_EVENT_GROUP_LEAVE:
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) &= ~(1 << player);
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_PENDING) |= 1 << player;
        if (Ov001_GetLinkStatus() == 3) Ov001_CompletePlayerLeave(player);
        return;
    case MB_EVENT_CHUNK_ACK:
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_ANSWERED) &= ~(1 << player);
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) |= 1 << player;
        return;
    case MB_EVENT_KICK:
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) &= ~(1 << player);
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED_COPY) |= 1 << player;
        Ov001_TryStartTransfer();
        return;
    case MB_EVENT_TEARDOWN: {
        u8 *tail;
        void *request;
        if (Ov001_GetLinkStatus() == 4) Ov001_SetLinkStatus(5);
        else Ov001_SetLinkStatus(0);
        /* drop the pending multiboot program (+0x144) and transfer (+0x140) requests */
        tail = (u8 *)gOv001LinkWork;
        tail += 0x1b000;
        request = M2C_FIELD(tail, void **, 0x144);
        if (request != NULL)
            M2C_FIELD(tail, void **, 0x144) = NULL;
        tail = (u8 *)gOv001LinkWork;
        tail += 0x1b000;
        request = M2C_FIELD(tail, void **, 0x140);
        if (request != NULL)
            M2C_FIELD(tail, void **, 0x140) = NULL;
        return;
    }
    case MB_EVENT_STATUS:
        status = *(const u16 *)packet;
        switch (status) {
        case 1:
        case 2:
        case 9:
            Ov001_SetLinkStatus(7);
            return;
        case 8:
        default:
            return;
        }
    case 1: break;
    case MB_EVENT_GROUP_REJECT: break;
    case MB_EVENT_GROUP_JOIN: break;
    case MB_EVENT_GROUP_DATA: break;
    case MB_EVENT_CHUNK_SENT: break;
    case MB_EVENT_ROSTER_DONE: break;
    default:
        SystemHalt();
        break;
    }
}
#pragma merge_duplicate_code reset
void Ov001_SetLinkStatus(s16 arg0) {
    extern s16 *gOv001LinkWork;
    *gOv001LinkWork = arg0;
}

u16 Ov001_GetLinkStatus(void) {
    extern s16 *gOv001LinkWork;
    return *(u16 *)gOv001LinkWork;
}

#pragma common_subs off
u16 Ov001_GetLinkInfo(s32 arg0) {
extern s16 *gOv001LinkWork;extern u16 *data_ov001_02190c68[];
s16 *q=gOv001LinkWork;u16 **table=data_ov001_02190c68;
table[0]=(u16*)(q+1);table[1]=(u16*)(q+2);table[2]=(u16*)(q+3);
table[3]=(u16*)(q+4);table[4]=(u16*)(q+5);table[5]=(u16*)(q+6);
return *(u16 *)M2C_FIELD(data_ov001_02190c68,s32 *,arg0*4);
}
#pragma scheduling off
/* Which stage of the Download Play link the player is in: 0 when the player is in
 * no stage word at all, else the first link-header bitmap (joined, kicked, kick
 * pending, kick answered, ready, joined copy) that has the player's bit.  The
 * header is copied under an interrupt lock and then tested from the copy. */
s32 Ov001_GetPlayerStage(s32 player) {
    void *OS_DisableInterrupts(s32);
    void OS_RestoreInterrupts(void *);
    s32 MI_CpuCopy8(void *, void *, s32);
    extern s16 *gOv001LinkWork;
    u16 header[7];
    s16 *gp;
    u16 mask;
    void *interrupts;
    interrupts = OS_DisableInterrupts(player);
    gp = gOv001LinkWork;
    mask = 1 << player;
    if (!((u16)gp[OV001_LINK_JOINED / 2] & mask)) {
        OS_RestoreInterrupts(interrupts);
        return OV001_STAGE_NONE;
    }
    MI_CpuCopy8(gOv001LinkWork, header, sizeof header);
    OS_RestoreInterrupts(interrupts);
    if (header[OV001_LINK_KICKED / 2] & mask) return OV001_STAGE_KICKED;
    if (header[OV001_LINK_KICK_PENDING / 2] & mask) return OV001_STAGE_KICK_PENDING;
    if (header[OV001_LINK_KICK_ANSWERED / 2] & mask) return OV001_STAGE_KICK_ANSWERED;
    if (header[OV001_LINK_READY / 2] & mask) return OV001_STAGE_READY;
    if (header[OV001_LINK_JOINED_COPY / 2] & mask) return OV001_STAGE_END;
    return OV001_STAGE_JOINED;
}
#pragma scheduling reset
/* Record of link player `player` (its OV001_LINK_RECORD_* fields), player 1
 * first, or 0 when that player is not in the link. */
s32 Ov001_GetLinkPlayerRecord(s32 player) {
extern s16 *gOv001LinkWork;
if(((u16)gOv001LinkWork[OV001_LINK_JOINED/2] & (1<<player)) !=0) {
return (player-1)*OV001_LINK_RECORD_SIZE+(s32)((u8 *)gOv001LinkWork+OV001_LINK_RECORDS);
}
return 0;
}

u16 Ov001_FindLinkPlayerByAddress(u8 *arg0) {
    extern s16 *gOv001LinkWork;
    u8 *base;
    u16 i;
    s32 offset;
    u8 *entry;
    i = 1;
    base = (u8 *)gOv001LinkWork + 0x24;
    do {
        if ((u16)gOv001LinkWork[1] & (1 << i)) {
            offset = (i - 1) * 0x1E;
            entry = base + offset;
            if (arg0[0] == entry[0] && arg0[1] == entry[1] && arg0[2] == entry[2] && arg0[3] == entry[3] && arg0[4] == entry[4] && arg0[5] == entry[5]) {
                return M2C_FIELD((u8 *)gOv001LinkWork + offset, u16 *, 0x2A);
            }
        }
        i++;
    } while ((u32)i < 2);
    return 0;
}

/* Bind a WH connection object to the overlay's work block and reset its link
 * status and its callback slots (the user-info callback among them), so a reused
 * connection starts empty. */
void Ov001_SetWhConnection(void *connection) {
    extern M2C_UNK gWhWork;
    M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION) = connection;
    M2C_FIELD(connection, s32 *, WH_LINK_STATUS) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION), s32 *, 0x13A8) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION), s32 *, WH_CONN_USER_INFO_CB) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION), s32 *, 0x13B0) = 0;
}

/* SetWhStatus: record the connection's new WH status, logging the change as
 * "old -> new" through the work block's log callback when one is installed.
 * The old status name is logged before the status is stored, the new one after. */
void SetWhStatus(s32 status) {
    extern M2C_UNK gWhWork;
    extern const char *gWhStatusNames[];
    extern M2C_UNK gWhStatusArrowFormat;
    extern M2C_UNK gWhStatusLineFormat;
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG) != NULL) {
        M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)(WH_LOG_STATUS, &gWhStatusArrowFormat, gWhStatusNames[M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, WH_LINK_STATUS)]);
    }
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, WH_LINK_STATUS) = status;
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG) == NULL) return;
    M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)(WH_LOG_STATUS, &gWhStatusLineFormat, gWhStatusNames[M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, WH_LINK_STATUS)]);
}

/* Record the code of a failed WH step on the connection object, unless the
 * connection already is in the parent-start or error state (the failure was
 * reported then, so the code is dropped).  Most steps report no code and call
 * this with no argument. */
s32 SetWhError(code)
s32 code;
{
    extern M2C_UNK gWhWork;
    void *connection = M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION);

    if ((u32)(M2C_FIELD(connection, s32 *, WH_LINK_STATUS) - WH_STATUS_PARENT_START) > 1)
        M2C_FIELD(connection, s32 *, WH_CONN_ERROR) = code;
}

/* Start the Download Play session; return 1 if WFC queued the asynchronous start, otherwise record an error and fail the connection. */
s32 Ov001_StartDownloadPlayConnection(void) {
    s32 WFC_StartDownloadPlay(void *, void *);
    void Ov001_HandleDownloadPlayStartResult(void *);
    extern M2C_UNK gWhWork;

    SetWhStatus(WH_STATUS_BUSY);
    if (WFC_StartDownloadPlay((void *)Ov001_HandleDownloadPlayStartResult,
                              M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION)) == 2) {
        return 1;
    }
    SetWhError();
    SetWhStatus(WH_STATUS_PARENT_START);
    return 0;
}

/* Completion callback of the download-play start request: when it reported an
 * error, record it and fail the connection; otherwise submit the player's user
 * info if the connection has a user-info callback, then start listening for child
 * indications. A failed follow-up step also fails the connection. */
void Ov001_HandleDownloadPlayStartResult(void *event) {
s32 Ov001_SubmitUserInfo();
s32 Ov001_StartChildIndicate();
extern M2C_UNK gWhWork;
if (M2C_FIELD(event,u16 *,WH_EVENT_STATUS)) {
SetWhError(M2C_FIELD(event,u16 *,WH_EVENT_STATUS));
SetWhStatus(WH_STATUS_PARENT_START); return;
}
if (M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,WH_CONN_USER_INFO_CB)) {
if (Ov001_SubmitUserInfo()) return;
SetWhStatus(WH_STATUS_PARENT_START); return;
}
if (Ov001_StartChildIndicate()) return;
SetWhStatus(WH_STATUS_PARENT_START);
}

/* Submit the player's user info: let the connection's WH_CONN_USER_INFO_CB fill
 * the user-info block and report the WFC user type, hand both to
 * WFC_SubmitUserInfo (which continues asynchronously through
 * Ov001_HandleUserInfoResult), and fail the connection when the submit does not
 * start (result 2). */
s32 Ov001_SubmitUserInfo(void) {
extern M2C_UNK gWhWork;
void Ov001_HandleUserInfoResult(void *);
s32 WFC_SubmitUserInfo(void *,s32,void *);
void *connection;
s32 userType;
SetWhStatus(WH_STATUS_BUSY);
connection=M2C_FIELD(&gWhWork,void **,WH_WORK_CONNECTION);
userType=M2C_FIELD(connection,s32 (**)(void *,void *),WH_CONN_USER_INFO_CB)((u8 *)connection+WH_CONN_USER_INFO,connection);
if(WFC_SubmitUserInfo((void *)Ov001_HandleUserInfoResult,userType,(u8 *)M2C_FIELD(&gWhWork,void **,WH_WORK_CONNECTION)+WH_CONN_USER_INFO)==2) return 1;
SetWhError(); SetWhStatus(WH_STATUS_PARENT_START); return 0;
}

/* Completion callback of WFC_SubmitUserInfo for the ov001 Download Play link:
 * on a reported step error, record it and put the connection back to the
 * parent-start state; otherwise queue the child-indication task, failing the
 * connection the same way if that step does not start. */
void Ov001_HandleUserInfoResult(void *event) {
    s32 Ov001_StartChildIndicate();
    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhError();
        SetWhStatus(WH_STATUS_PARENT_START);
        return;
    }
    if (Ov001_StartChildIndicate() != 0) {
        return;
    }
    SetWhStatus(WH_STATUS_PARENT_START);
}

/* Queue the DWC child-indication task that delivers child connect/disconnect
   events: unless the connection already reached the connected/data/key-sharing
   statuses, start the task (and fail the connection on error) and reset the child
   state, leaving only this console's bit in the connected-child bitmap. */
s32 Ov001_StartChildIndicate(void) {
extern M2C_UNK gWhWork;
extern M2C_UNK HandleChildIndicate;
s32 func_02012474(void *);
if((u32)(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,WH_LINK_STATUS)-4)<=2) return 1;
if(func_02012474(&HandleChildIndicate)!=2) {SetWhError();return 0;}
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,0x50)=0;
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,WH_CHILD_CONNECTED)=1;
return 1;
}

#pragma push
#pragma opt_propagation off
/* Callback for the DWC child-connection indications: marks or clears the child's
   bit in the connection bitmap as it connects (kind 7) or disconnects (kind 9),
   handling the transport's request callback on connect and advancing the state on
   the other indication kinds. */
void HandleChildIndicate(void *event) {
extern M2C_UNK gWhWork;
extern M2C_UNK data_ov001_0219159c,data_ov001_021915c8,data_ov001_021915f4;
s32 SetWhError();
s32 func_0201280c(void (*)(void *),s32);
register s32 childId;
u16 childMask;
register void (*logCallback)();
register s32 indicateKind;
s32 error;
childId=M2C_FIELD(event,u16 *,0x10);
childMask=(u16)(1U<<childId);
error=M2C_FIELD(event,u16 *,2);
if(error){
((s32 (*)(s32))SetWhError)(error);SetWhStatus(9);return;
}
indicateKind=M2C_FIELD(event,u16 *,8);
switch(indicateKind){
case 7:
logCallback=M2C_FIELD(&gWhWork,void (**)(),0);
if(logCallback)logCallback(0x8000000,&data_ov001_0219159c,childId);
if(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 (**)(void *),0x4c)&& !M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 (**)(void *),0x4c)(event)){
error=func_0201280c(0,M2C_FIELD(event,u16 *,0x10));
if(error==2)return;
SetWhError();SetWhStatus(9);return;
}
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,0x52)|=childMask;
break;
case 9:
logCallback=M2C_FIELD(&gWhWork,void (**)(),0);
if(logCallback)logCallback(0x8000000,&data_ov001_021915c8,childId);
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,0x52)&=~childMask;
break;
case 0:
if(Ov001_StartParent()==0)SetWhStatus(9);
break;
case 2:break;
default:
logCallback=M2C_FIELD(&gWhWork,void (**)(),0);
if(logCallback)((void (*)(s32,void *,s32))logCallback)(0x8000000,&data_ov001_021915f4,indicateKind);
break;
}
}
#pragma pop
/* WH connect step: start the parent task that makes this console the parent of
 * the group.  Returns 1 when the connection already passed this point or the
 * task was queued, 0 when it could not be started (the error is recorded). */
s32 Ov001_StartParent(void) {
    extern M2C_UNK gWhWork;
    extern M2C_UNK HandleParentStartResult;
    s32 MultiBoot_StartLinkTask(void *, void *, u16, void *, u16, s32);
    void *connection;

    if ((u32)(M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, WH_LINK_STATUS) - 4) <= 2) return 1;
    SetWhStatus(WH_STATUS_CONNECTED);
    connection = M2C_FIELD(&gWhWork, void **, 4);
    /* the task carries two buffers of the connection object: +0x1060 of length
     * +0x12A4 and +0xF80 of length +0x12A0 */
    if (MultiBoot_StartLinkTask(&HandleParentStartResult, (u8 *)connection + 0x1060, (u16)M2C_FIELD(connection, s32 *, 0x12A4), (u8 *)connection + 0xF80, (u16)M2C_FIELD(connection, s32 *, 0x12A0), 1) == 2) return 1;
    SetWhError();
    return 0;
}

/* Completion callback of the WH parent-start task begun by the connect step:
 * on success it advances the connection to key sharing (status CONNECTED) or
 * data sharing, on failure it records the error and moves to the failure
 * status.  Command 10 is the parent task's completion; the other commands are
 * only logged. */
void HandleParentStartResult(void *event) {
    s32 SetWhError();
    void SetWhStatus(s32);
    s32 Ov001_StartKeySharing(void);
    s32 WFC_OpenChannel(void *, s32, s32, s32, s32);
    extern M2C_UNK gWhWork;
    extern M2C_UNK data_ov001_02191614;
    extern M2C_UNK data_ov001_021915f4;
    void *connection;
    s32 error;
    u16 command;

    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhError(M2C_FIELD(event, u16 *, WH_EVENT_STATUS));
        SetWhStatus(WH_STATUS_PARENT_START);
        return;
    }
    command = M2C_FIELD(event, u16 *, WH_EVENT_COMMAND);
    switch (command) {
    case 10:
        connection = M2C_FIELD(&gWhWork, void **, 4);
        if (M2C_FIELD(connection, s32 *, 0x44) == 2) {
            if (M2C_FIELD(connection, s32 *, 0x40) == WH_STATUS_CONNECTED) {
                if (Ov001_StartKeySharing() != 0) return;
                if (M2C_FIELD(&gWhWork, void (**)(s32, void *), 0) != 0) {
                    M2C_FIELD(&gWhWork, void (**)(s32, void *), 0)(0x08000000, &data_ov001_02191614);
                }
                SetWhStatus(WH_STATUS_PARENT_START);
                return;
            }
            if (M2C_FIELD(connection, s32 *, 0x40) == WH_STATUS_KEYSHARING) return;
        } else if (M2C_FIELD(connection, s32 *, 0x44) == 4) {
            error = WFC_OpenChannel((u8 *)connection + 0x13E0, 13, 7, 0x44, 1);
            if (error != 0) {
                SetWhError(error);
                SetWhStatus(WH_STATUS_PARENT_START);
                return;
            }
            SetWhStatus(WH_STATUS_DATASHARING);
            return;
        }
        SetWhStatus(WH_STATUS_CONNECTED);
        return;
    case 11:
        break;
    case 12:
    case 13:
    default:
        if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0) != 0) {
            M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0)(0x08000000, &data_ov001_021915f4, command);
        }
        return;
    }
}

/* Start the WH key-sharing step: mark the connection as key-sharing and open the
   key-sharing channel to every peer.  Returns 1 when the open was queued, 0 when
   it failed (the error code is recorded for the status machine). */
s32 Ov001_StartKeySharing(void){
    extern M2C_UNK gWhWork;
    s32 WFC_StartChannel(void *, s32);
    SetWhStatus(WH_STATUS_KEYSHARING);
    if (WFC_StartChannel((u8 *)M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION) + WH_KEY_CHANNEL, WH_KEY_CHANNEL_INDEX) == 2) return 1;
    SetWhError();
    return 0;
}

/* Close the WH key-sharing channel while tearing the session down: return 1 when
 * the close was queued (result 2), otherwise raise the WH error and return 0. */
s32 Ov001_CloseKeySharingChannel(void) {
    extern M2C_UNK gWhWork;
    s32 WFC_CloseChannelThunk(void *);
    if (WFC_CloseChannelThunk((u8 *)M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION) + WH_KEY_CHANNEL) == 2) return 1;
    SetWhError();
    return 0;
}

/* Reset the WH session this console hosts (a Download Play parent): mark the
 * connection busy and tear the link down.  Its completion,
 * DWCi_MOV_WH_StateInEndParent, sends the reset command and returns the
 * connection to idle; returns 0 when the teardown cannot be queued. */
s32 Ov001_ResetWhHostSession(void) {
    s32 WFC_SendTeardownCommand(M2C_UNK *);
    extern M2C_UNK DWCi_MOV_WH_StateInEndParent;
    SetWhStatus(WH_STATUS_BUSY);
    if (WFC_SendTeardownCommand(&DWCi_MOV_WH_StateInEndParent) == 2) {
        return 1;
    }
    SetWhError();
    return 0;
}

/* Teardown-completion callback for the end-parent WH state: a nonzero event status
   records the error, an unfinished teardown poll just waits, and once the teardown
   is done the failure is logged and the state machine advances. */
void DWCi_MOV_WH_StateInEndParent(void *event) {
    extern M2C_UNK gWhWork;
    extern M2C_UNK sWhLogEndParentFailed;
    M2C_UNK Ov001_AbortWhSession();
    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS)) {
        SetWhError();
        Ov001_AbortWhSession();
        return;
    }
    if (Ov001_SendWhResetCommand()) return;
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *), WH_WORK_LOG)) {
        M2C_FIELD(&gWhWork, void (**)(s32, void *), WH_WORK_LOG)(WH_LOG_STATUS, &sWhLogEndParentFailed);
    }
    Ov001_AbortWhSession();
}

/* Queue the WH connection's WFC reset command (WFC command 9), whose completion
 * goes to Ov001_HandleWhResetResult; returns 1 once queued, or records the WH
 * error and returns 0. */
s32 Ov001_SendWhResetCommand(void) {
    s32 WFC_SendCommand9(void (*)(void *));
    void Ov001_HandleWhResetResult(void *);
    if (WFC_SendCommand9(Ov001_HandleWhResetResult) == 2) return 1;
    SetWhError();
    return 0;
}

/* Completion callback of Ov001_SendWhResetCommand's WFC reset command: a reported
 * step error fails the connection, otherwise the reset worked and the connection
 * goes idle. */
void Ov001_HandleWhResetResult(void *event) {
    void SetWhStatus(M2C_UNK);
    M2C_UNK SetWhError();
    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhError();
        return;
    }
    SetWhStatus(WH_STATUS_IDLE);
}

/* End the WH connection's key-sharing step: only while the connection is in the
 * key-sharing status, mark it busy and stop the key-sharing channel; returns 1
 * when the stop was queued, 0 when it failed. */
s32 Ov001_EndKeySharing(void) {
    extern M2C_UNK gWhWork;
    s32 WFC_CloseChannelThunk(void *);
    if (M2C_FIELD(M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION), s32 *, WH_LINK_STATUS) != WH_STATUS_KEYSHARING) return 0;
    SetWhStatus(WH_STATUS_BUSY);
    if (WFC_CloseChannelThunk((u8 *)M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION) + WH_KEY_CHANNEL) == 2) return 1;
    SetWhError();
    return 0;
}

/* Tear the WH connection's current step down and queue the setup again: mark
 * the connection busy and send the WFC teardown command (its completion,
 * Ov001_HandleTeardownResult, queues the next setup command).  Returns 1 when
 * the command was queued, 0 when it failed. */
s32 Ov001_TeardownAndQueueSetup(void) {
    extern M2C_UNK Ov001_HandleTeardownResult;
    SetWhStatus(WH_STATUS_BUSY);
    if (WFC_SendTeardownCommand(&Ov001_HandleTeardownResult) == 2) {
        return 1;
    }
    SetWhError();
    return 0;
}

/* Completion handler of the WH teardown command (WFC command 0x10): on a reported
 * step error record it and advance the state machine; otherwise queue the next
 * setup command and, when that cannot be queued, put the connection into its
 * failure state. */
void Ov001_HandleTeardownResult(void *event) {
    s32 QueueWhSetupCommand();
    M2C_UNK func_ov001_02188b20();
    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhError();
        func_ov001_02188b20();
        return;
    }
    if (QueueWhSetupCommand() != 0) {
        return;
    }
    SetWhStatus(WH_STATUS_PARENT_START);
}

/* Queue the WH connection's next setup command, a WFC command whose completion
 * callback FinishWhSetupCommand continues the state machine: the connection is
 * marked busy; when the command cannot be queued the WH error is raised and the
 * next step runs.  Returns 1 once the command is queued, 0 on failure. */
s32 QueueWhSetupCommand(void) {
    s32 func_0201280c(void (*)(void *), s32);
    void FinishWhSetupCommand(void *);
    M2C_UNK Ov001_AbortWhSession();
    SetWhStatus(WH_STATUS_BUSY);
    if (func_0201280c(FinishWhSetupCommand, 0) == 2) return 1;
    SetWhError();
    Ov001_AbortWhSession();
    return 0;
}

/* Completion callback of the WH setup command: a failed step records the WH error
 * and leaves the connection where it is, otherwise the connection becomes idle. */
void FinishWhSetupCommand(void *event) {
    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhError();
        return;
    }
    SetWhStatus(WH_STATUS_IDLE);
}

/* Mark the WH connection busy and queue the WFC stop command; FinishWhStopCommand
 * handles its completion.  Returns 1 once the command is queued, 0 (with the WH
 * error recorded) when it cannot be sent. */
s32 QueueWhStopCommand(void) {
    s32 WFC_SendCommand1(M2C_UNK *);
    extern M2C_UNK FinishWhStopCommand;
    SetWhStatus(WH_STATUS_BUSY);
    if (WFC_SendCommand1(&FinishWhStopCommand) == WFC_CMD_OK) {
        return 1;
    }
    SetWhError();
    return 0;
}

/* Completion callback of the WH stop command: when the command reported an
 * error, record the error code and fail the connection (the parent-start
 * status); otherwise the connection returns to idle. */
void FinishWhStopCommand(void *event) {
    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhStatus(WH_STATUS_PARENT_START);
        SetWhError(M2C_FIELD(event, u16 *, WH_EVENT_STATUS));
        return;
    }
    SetWhStatus(WH_STATUS_IDLE);
}

/* Completion callback of the ov001 WH end-link command: an event carrying a
 * failed status leaves the connection in WH_STATUS_ERROR, a clean one stops it. */
void Ov001_HandleEndLinkResult(void *event) {
    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhStatus(WH_STATUS_ERROR);
        return;
    }
    SetWhStatus(WH_STATUS_STOP);
}

void func_ov001_0218836c(s32 arg0) {
    extern M2C_UNK gWhWork;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 8) = arg0;
}

u16 Ov001_GetConnectedChildren(void) {
extern M2C_UNK gWhWork;
return M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x52);
}

s32 Ov001_GetTaskStep(void) {
extern M2C_UNK gWhWork;
return M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x40);
}

s32 WhStartChildScan(void) {
    void GetMacAddress(u8 *);
    void SetWhStatus(s32);
    u16 ScanNextChild(u16);
    s32 SetWhError(s32);
    extern M2C_UNK gWhWork;
    u16 buf[3];
    u16 rv;
    u32 seed;
    const u32 *tick = (const u32 *)0x027ffc3c;

    GetMacAddress((u8 *)buf);
    seed = *tick;
    seed += buf[0];
    seed += buf[1];
    seed += buf[2];
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u32 *, 0x58) = seed;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x58) =
        M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x58) * 0x10dcd + 0x39 + 0x3000;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x5c) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x5e) = 0x65;
    SetWhStatus(3);
    rv = ScanNextChild(1);
    if (rv == 0x18) {
        SetWhError(0x18);
        SetWhStatus(9);
        return 0;
    }
    if (rv == 2) {
        return 1;
    }
    SetWhError(rv);
    SetWhStatus(9);
    return 0;
}

/* Scan the children of the wireless link from `firstChild` on: queue the channel
 * scan of the next child present in WFC_GetPlayerMask and return its result. A
 * not-ready mask (0x8000) fails with error 3, an empty mask with error 0x16, and
 * running past child 16 reports WH_SCAN_DONE. */
u16 ScanNextChild(u16 firstChild) {
    s32 WFC_GetPlayerMask();
    s32 RequestChildChannelScan(void *, u16);
    extern M2C_UNK HandleChildScanResult;
    s32 playerMask = WFC_GetPlayerMask();

    if (playerMask == 0x8000) { SetWhError(3); SetWhStatus(9); return 3; }
    if (playerMask == 0) { SetWhError(0x16); SetWhStatus(9); return WH_SCAN_DONE; }
    while (!(playerMask & (1 << (firstChild - 1)))) {
        firstChild++;
        if ((u32)firstChild > 0x10) return WH_SCAN_DONE;
    }
    return (u16)RequestChildChannelScan(&HandleChildScanResult, firstChild);
}

