/* 41 functions from 0x02225F60 to 0x02226D9C (ov010), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
#define ONLINE_USE_INTERRUPT_GUARD
#include "online_link.h"
#include "ghttp.h"
typedef struct Ov010MemberCall { s32 function; s32 adjustment; } Ov010MemberCall;
static inline void ov010CallMember(void *object, Ov010MemberCall *call) {
s32 adj=call->adjustment;
void *self=(u8 *)object+(adj>>1);
s32 fn;
fn=(adj&1)?*(s32 *)(*(u8 **)self+call->function):call->function;
((void (*)(void *))fn)(self);
}
static inline void ov010CallArray(u8 *first,s32 size,Ov010MemberCall call) {
Ov010MemberCall copy;
u8 *last=first+size;
copy.function=call.function;copy.adjustment=call.adjustment;
while(first!=last) { ov010CallMember(first,&copy); first+=12; }
}

/* Initializes/starts the overlay 010 subsystem: allocates its working buffers, sets callbacks and enables it. */
s32 Ov010_InitVoiceChat(void) {
    extern M2C_UNK gVoiceChatLink, data_ov010_0222ee98, data_ov010_0222ee78;
    void VoiceLink_HandleEvent();
    void func_ov010_02225f54();
    s32 GetOnlineTransportPlayerId();
    s32 func_ov010_02225cd8(s32);
    s32 func_ov010_02225640(void *);
    void Ov010_SetVoiceChatCallback();
    void func_ov010_02222c9c();
    void func_ov010_02225d00();
    void DisableVoiceStream();
    s32 func_ov010_02229bf4();
    void VoiceChat_SetCodecMode();
    s32 AllocAlignedBuffer(s32, s32);

    if (M2C_FIELD(&gVoiceChatLink, s32 *, 0) != 0) {
        return 1;
    }
    M2C_FIELD(&gVoiceChatLink, s32 *, 0) = AllocAlignedBuffer(0x6b40, 32);
    M2C_FIELD(&gVoiceChatLink, s32 *, 16) = 1;
    M2C_FIELD(&gVoiceChatLink, void **, 8) = &data_ov010_0222ee98;
    M2C_FIELD(&gVoiceChatLink, s32 *, 12) = 2;
    M2C_FIELD(&gVoiceChatLink, u8 *, 20) = (u8)GetOnlineTransportPlayerId();
    M2C_FIELD(&gVoiceChatLink, void **, 32) = VoiceLink_HandleEvent;
    M2C_FIELD(&gVoiceChatLink, s32 *, 36) = 0;
    M2C_FIELD(&gVoiceChatLink, s32 *, 24) = M2C_FIELD(&gVoiceChatLink, s32 *, 0);
    M2C_FIELD(&gVoiceChatLink, s32 *, 28) = 0x6b40;
    if (!func_ov010_02225cd8(0x6b40)) {
        return 0;
    }
    if (!func_ov010_02225640(&data_ov010_0222ee78)) {
        return 0;
    }
    Ov010_SetVoiceChatCallback(func_ov010_02225f54);
    func_ov010_02222c9c(1);
    M2C_FIELD(&gVoiceChatLink, s32 *, 4) = 0;
    func_ov010_02225d00();
    DisableVoiceStream();
    if (func_ov010_02229bf4()) {
        VoiceChat_ConnectPeer(0);
    }
    VoiceChat_SetCodecMode(1);
    return 1;
}

void TickVoiceStream(void) {
    M2C_UNK VoiceChat_Tick();
    VoiceChat_Tick();
}

/* Open the voice-chat link's exchange with `peerId`: when no context is
 * attached, create one and send its connect packet.  Returns 0 when no context
 * could be opened, 1 once one is attached. */
s32 VoiceChat_ConnectPeer(s32 peerId) {
    s32 VoiceLink_CreatePeerContext(s32);
    void VoiceLink_ReleaseContext(s32);
    s32 VoiceLink_TrySendStep(s32, s32);
    extern M2C_UNK gVoiceChatLink;
    s32 context;

    if (M2C_FIELD(&gVoiceChatLink, s32 *, VOICE_CHAT_LINK_CONTEXT) == 0) {
        context = VoiceLink_CreatePeerContext(peerId);
        if (context == 0) return 0;
        if (VoiceLink_TrySendStep(context, 0) != 0) {
            VoiceLink_ReleaseContext(context);
            return 0;
        }
        M2C_FIELD(&gVoiceChatLink, s32 *, VOICE_CHAT_LINK_CONTEXT) = context;
    }
    return 1;
}

/* Shut down the ov010 voice-chat link: stop its streamed sound and voice stream,
 * clear the online session's voice-chat callback, reset the voice-chat session,
 * then free the link's work buffer and mark the link closed. */
void Ov010_ShutdownVoiceChat(void) {
    void VoiceChat_StopStreamSound();
    void StopStreamedVoice();
    void Ov010_SetVoiceChatCallback(s32);
    void VoiceChat_ResetSession();
    void FreeBuffer();
    extern M2C_UNK gVoiceChatLink;
    VoiceChat_StopStreamSound();
    StopStreamedVoice();
    Ov010_SetVoiceChatCallback(0);
    VoiceChat_ResetSession();
    FreeBuffer((s32)((VoiceChatLink *)&gVoiceChatLink)->streamBuffer,
        (s32)((VoiceChatLink *)&gVoiceChatLink)->config.packetPoolSize);
    ((VoiceChatLink *)&gVoiceChatLink)->streamBuffer = 0;
}

s32 AllocAlignedBuffer() {
    M2C_UNK func_020e3580();
    func_020e3580();
}

void FreeBuffer(s32 arg0) {
    M2C_UNK HeapFreeBlock();
    if (arg0 == 0) {
        return;
    }
    HeapFreeBlock();
}

M2C_UNK SetWebRequestError(M2C_UNK arg0) {
    s32 GetWebRequestError(void);
    extern s32 gWebRequestError;
    GetWebRequestError();
    gWebRequestError = arg0;
}

void func_ov010_02226130(void) {
    M2C_UNK PollWebTransaction();
    PollWebTransaction();
}

/* Submit the NAS player-registration request for the local profile, create the
 * waiting indicator sprite of sOv010RegisterSpriteClass and mark online step 5.
 * Returns 1 once the request is under way (or was already submitted), 0 when it
 * failed; the status codes other than 0 and 3 are recorded as the web error. */
s32 SubmitWebRegisterRequest(void) {
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    void ClearWebRequestError(void);
    u8 *GetProfileSaveBlock();
    s32 RegisterWebRequest(M2C_UNK *, u8 *);
    M2C_UNK SetWebRequestError(M2C_UNK);
    M2C_UNK **CreateSpriteFromClass(M2C_UNK *, s32);
    void SetOnlineSessionFlag(M2C_UNK);
    extern M2C_UNK sOv010NasRegisterRequest;
    extern M2C_UNK sOv010RegisterSpriteClass;
    extern M2C_UNK sOv010RegisterSpriteVtable;
    s32 success;
    u32 status;
    M2C_UNK **slot;

    success = 1;
    if (IsOnlineSessionFlagSet(5) != 0) return 1;
    ClearWebRequestError();
    status = RegisterWebRequest(&sOv010NasRegisterRequest, GetProfileSaveBlock() + 4);
    switch (status) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        success = 0;
        break;
    case 5:
        success = 0;
        break;
    case 6:
        success = 0;
        break;
    }
    if ((status != 0) && (status != 3)) {
        SetWebRequestError(status);
    } else {
        slot = CreateSpriteFromClass(&sOv010RegisterSpriteClass, 3);
        if (slot != NULL) {
            *slot = &sOv010RegisterSpriteVtable;
        }
        SetOnlineSessionFlag(5);
    }
    return success;
}

s32 GetWebRequestError(void) {
    extern s32 gWebRequestError;
    return gWebRequestError;
}

void ClearWebRequestError(void) {
    M2C_UNK SetWebRequestError(M2C_UNK);
    SetWebRequestError(0);
}

/* Refresh the clock from the server, then send a put.asp request with the given
 * fields and record its error: returns 0 when the request failed (statuses 1, 2,
 * 7, 8 and 9), 1 once it is on its way. */
s32 SubmitWebPutRequest(s32 playerId, s32 field2, s32 field3, s32 payload, s32 payloadSize) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 GetProfileSyncTime();
    u32 SendWebPutRequest(s32, s32, s32, s32, s32);
    M2C_UNK date[4];
    M2C_UNK time[3];
    s32 result;
    u32 status;

    result = 1;
    if (GetServerTime(date, time) != 0) {
        GetElapsedSeconds(GetProfileSyncTime(), date, time);
    }
    status = SendWebPutRequest(playerId, field2, field3, payload, payloadSize);
    switch (status) {
    default: break;
    case 1: result = 0; break;
    case 7: result = 0; break;
    case 2: result = 0; break;
    case 8: result = 0; break;
    case 9: result = 0; break;
    }
    if (status != 0) {
        SetWebRequestError(status);
    }
    return result;
}

/* Poll the web transaction of a profile PUT upload: report 1 while the put is
 * still in flight (WEB_TXN_PUT_SENT); when it completes, record the server's
 * date/time as the profile's sync time.  An idle, failed or other-request
 * transaction reports 0. */
s32 CompleteWebPutRequest(void) {
    M2C_UNK SaveProfileSyncTime();
    s32 inFlight;
    u32 status;

    inFlight = 1;
    status = GetWebTransactionStatus();
    switch (status) {
    default:
        break;
    case WEB_TXN_COMPLETE:
        SaveProfileSyncTime();
        inFlight = 0;
        break;
    case WEB_TXN_FAILED:
        inFlight = 0;
        break;
    case WEB_TXN_IDLE:
    case WEB_TXN_READY:
    case WEB_TXN_GET_SENT:
    case WEB_TXN_SYNC_SENT:
        inFlight = 0;
        break;
    }
    return inFlight;
}

s32 SubmitWebPutRequestAndCreateSprite(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, void *arg5) {
    s32 CreateSpriteObject(M2C_UNK *, s32);
    s32 SubmitWebPutRequest(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern M2C_UNK data_ov010_0222c080;
    if (SubmitWebPutRequest(arg0, arg1, arg2, arg3, arg4) == 0) {
        return 0;
    }
    return CreateSpriteObject(&data_ov010_0222c080, arg5);
}

/* Whether the local profile's sync time is out of date: the server's time must be
 * known and lie at least a minute (SERVER_TIME_RESYNC_SECONDS) after the time the
 * profile was last synced. */
s32 IsProfileSyncOverdue(void) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 GetProfileSyncTime();
    M2C_UNK date[4];
    M2C_UNK time[3];
    s64 elapsed;
    s32 overdue;

    if (GetServerTime(date, time) == 0) {
        elapsed = 0;
    } else {
        elapsed = GetElapsedSeconds(GetProfileSyncTime(), date, time);
    }
    overdue = 0;
    if (elapsed >= SERVER_TIME_RESYNC_SECONDS) {
        overdue = 1;
    }
    return overdue;
}

/* Fills the request payload's kind marker for `kind`, submits it as a web GET
 * request, and records any error status. Returns 0 when the kind is unknown. */
s32 SendWebGetForKind(u32 kind,s32 playerId,s32 field2,s32 *payload){
s32 GetServerTime(M2C_UNK *,M2C_UNK *);s64 GetElapsedSeconds(s32,M2C_UNK *,M2C_UNK *);s32 GetGetRequestServerTime(void);u32 SendWebGetRequest(u32,s32,s32,s32 *);
M2C_UNK date[4];M2C_UNK time[3];s32 ok;u32 status;
ok=1;
if(GetServerTime(date,time)!=0)GetElapsedSeconds(GetGetRequestServerTime(),date,time);
switch(kind){case 0:*payload=8;break;case 1:*payload=12;break;case 2:case 4:case 5:*payload=12;break;case 3:*payload=0x10c;break;case 6:*payload=16;break;default:return 0;}
status=SendWebGetRequest(kind,playerId,field2,payload);
switch(status){default:break;case 1:ok=0;break;case 7:ok=0;break;case 2:ok=0;break;case 8:ok=0;break;case 9:ok=0;break;}
if(status!=0)SetWebRequestError(status);
return ok;
}

/* Step of the get.asp request sprite: returns 1 while the request is still on its
 * way (status GET_SENT) and 0 once it has completed or failed.  On completion it
 * records the current server date/time in the profile save block, so the elapsed
 * age of the stored snapshot can be measured before the next request. */
s32 IsWebGetRequestPending(void) {
    M2C_UNK StoreGetRequestServerTime();
    s32 pending;
    u32 status;

    pending = 1;
    status = GetWebTransactionStatus();
    switch (status) {
    default:
        break;
    case WEB_TXN_COMPLETE:
        StoreGetRequestServerTime();
        pending = 0;
        break;
    case WEB_TXN_FAILED:
        pending = 0;
        break;
    case WEB_TXN_IDLE:
    case WEB_TXN_READY:
    case WEB_TXN_PUT_SENT:
    case WEB_TXN_SYNC_SENT:
        pending = 0;
        break;
    }
    return pending;
}

s32 SubmitWebGetRequest(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 CreateSpriteObject(M2C_UNK *, s32);
    s32 SendWebGetForKind();
    extern M2C_UNK data_ov010_0222c0a0;
    if (SendWebGetForKind() == 0) return 0;
    return CreateSpriteObject(&data_ov010_0222c0a0, arg4);
}

/* Returns 1 once the server clock has run WEB_REQUEST_STALE_SECONDS past the
 * time stored when the last get.asp request was answered (the profile save's
 * +0x74 record), so the sprite waiting on that request may resume; 0 while the
 * server time is unavailable or the record is still fresh. */
s32 HasWebGetRequestTimedOut(void) {
    s32 GetServerTime(s32 *, s32 *);
    s64 GetElapsedSeconds(s32, s32 *, s32 *);
    s32 GetGetRequestServerTime();
    s32 date[4];
    s32 time[3];
    s64 elapsedSeconds;
    s32 timedOut;

    if (GetServerTime(date, time) == 0) {
        elapsedSeconds = 0;
    } else {
        elapsedSeconds = GetElapsedSeconds(GetGetRequestServerTime(), date, time);
    }
    timedOut = 0;
    if (elapsedSeconds >= WEB_REQUEST_STALE_SECONDS) {
        timedOut = 1;
    }
    return timedOut;
}

/* Refresh the clock from the server, then send a sync web request for `kind`,
 * `playerId` and `recordCount` with `payload` and record its error: returns 0
 * when the request failed (statuses 1, 2, 7, 8 and 9), 1 once it is on its way. */
s32 SubmitWebSyncRequest(s32 kind, s32 playerId, u32 recordCount, s32 payload) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 GetProfileSyncTime();
    u32 SendWebSyncRequest(s32, s32, u32, s32);
    M2C_UNK time[3];
    M2C_UNK date[4];
    s32 result;
    u32 status;

    result = 1;
    if (GetServerTime(date, time) != 0) {
        GetElapsedSeconds(GetProfileSyncTime(), date, time);
    }
    status = SendWebSyncRequest(kind, playerId, recordCount, payload);
    switch (status) {
    default: break;
    case 1: result = 0; break;
    case 7: result = 0; break;
    case 2: result = 0; break;
    case 8: result = 0; break;
    case 9: result = 0; break;
    }
    if (status != 0) {
        SetWebRequestError(status);
    }
    return result;
}

/* Poll the web transaction of a record sync request: report 1 while the sync is
 * still in flight (WEB_TXN_SYNC_SENT); when it completes, record the server's
 * date/time as the profile's sync time.  An idle, failed or other-request
 * transaction reports 0. */
s32 CompleteWebSyncRequest(void) {
    s32 inFlight;
    u32 status;

    inFlight = 1;
    status = GetWebTransactionStatus();
    switch (status) {
    default:
        break;
    case WEB_TXN_COMPLETE:
        SaveProfileSyncTime();
        inFlight = 0;
        break;
    case WEB_TXN_FAILED:
        inFlight = 0;
        break;
    case WEB_TXN_IDLE:
    case WEB_TXN_READY:
    case WEB_TXN_PUT_SENT:
    case WEB_TXN_GET_SENT:
        inFlight = 0;
        break;
    }
    return inFlight;
}

s32 SubmitWebSyncRequestAndCreateSprite(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 CreateSpriteObject(M2C_UNK *, s32);
    s32 SubmitWebSyncRequest();
    extern M2C_UNK data_ov010_0222c060;
    if (SubmitWebSyncRequest() == 0) return 0;
    return CreateSpriteObject(&data_ov010_0222c060, arg4);
}

/* Copy of IsProfileSyncOverdue used by the record-sync wait state: whether the
 * profile's sync time is out of date, that is the server's time is known and lies
 * at least a minute (SERVER_TIME_RESYNC_SECONDS) after the time of the last sync. */
s32 IsProfileSyncOverdueAlt(void) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 GetProfileSyncTime();
    M2C_UNK time[3];
    M2C_UNK date[4];
    s64 elapsed;
    s32 overdue;

    if (GetServerTime(date, time) == 0) {
        elapsed = 0;
    } else {
        elapsed = GetElapsedSeconds(GetProfileSyncTime(), date, time);
    }
    overdue = 0;
    if (elapsed >= SERVER_TIME_RESYNC_SECONDS) {
        overdue = 1;
    }
    return overdue;
}

void func_ov010_02226738(void) {
    M2C_UNK GetWebTransactionStatus();
    GetWebTransactionStatus();
}

/* Number of online players (the player records) reported by the last web
 * response; -1 when the response is not usable, and its status is then recorded
 * as the web error. */
s32 GetOnlinePlayerTotal(void) {
    s32 GetWebResponsePlayerTotal(s32 *);
    s32 total, status, result;
    result = -1;
    status = GetWebResponsePlayerTotal(&total);
    switch (status) {
    case 0: result = total; break;
    case 1: break;
    case 2: break;
    case 15: break;
    case 16: break;
    case 17: break;
    }
    if (status != 0) SetWebRequestError(status);
    return result;
}

/* Read player record `index` of the last get.asp reply into `entry`: returns 1
 * when it was read, 0 otherwise, recording any nonzero status as the web error. */
s32 Ov010_GetWebPlayerEntry(s32 index, s32 *entry) {
 s32 GetWebResponsePlayer(M2C_UNK, M2C_UNK);
 s32 status, found;
 found = 0;
 status = GetWebResponsePlayer(entry,index);
 switch(status) {
 case 0: found = 1; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(status != 0) SetWebRequestError(status);
 return found;
}

/* Read the number of players online from the current web response: return the
 * count when the read succeeds (status 0), otherwise -1, recording the read's
 * status as the web error. */
s32 GetOnlinePlayerCount(void) {
 s32 GetWebResponseOnlinePlayerCount(s32 *);
 s32 count, status, result;
 result = -1;
 status = GetWebResponseOnlinePlayerCount(&count);
 switch(status) {
 case 0: result = count; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(status != 0) SetWebRequestError(status);
 return result;
}

/* Tear down a submitted NAS player registration: if online step 5 is not
 * pending, report it done; otherwise free the pending web request, drop the
 * waiting-indicator sprite, record any teardown error and clear the step.
 * Returns 1 on success, 0 when tearing the request down failed. */
s32 FinishWebRegisterRequest(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    s32 FinishWebRequest();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    extern M2C_UNK sOv010RegisterSpriteClass;
    s32 error;
    s32 result;

    if (IsOnlineSessionFlagSet(OV010_FLAG_REGISTERING) == 0) {
        return 1;
    }
    error = FinishWebRequest();
    if (error == 0) {
        result = 1;
    } else {
        result = 0;
    }
    DeleteSpriteObjectsOfClass(&sOv010RegisterSpriteClass);
    if (error != 0) {
        SetWebRequestError(error);
    }
    Ov010Online_ClearStepFlag(OV010_FLAG_REGISTERING);
    return result;
}

void func_ov010_022268dc(void) {

}

s32 func_ov010_022268e0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_022268f4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
 M2C_UNK func_020e3580();
 func_020e3580(arg1,arg2);
}

M2C_UNK Ov010_FreeBlock(M2C_UNK arg0, s32 arg1, s32 arg2) {
 M2C_UNK HeapFreeBlock();
 if(arg1 == 0) return;
 HeapFreeBlock(arg1);
}

/* Reinitialize a 0x6C-byte online player record: clear its name area, mark it
 * not connected with no player id, default its rating to RATING_DEFAULT, set the
 * per-slot state bytes to their unset values and clear its network panel record.
 * The void-returning twin of InitOnlinePlayerRecord. */
void ResetOnlinePlayerRecord(void *record) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    MI_CpuFill8(record, 0, ONLINE_PLAYER_NAME_SIZE);
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_FLAGS) = 0;
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_ID) = -1;
    M2C_FIELD(record, s32 *, ONLINE_PLAYER_STATUS) = -1;
    M2C_FIELD(record, s32 *, ONLINE_PLAYER_RATING) = RATING_DEFAULT;
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_SLOT_STATE + 0) = -1;
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_SLOT_STATE + 1) = -2;
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_SLOT_STATE + 2) = -2;
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_SLOT_STATE + 3) = -1;
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_SLOT_STATE + 4) = -1;
    MI_CpuFill8(record + ONLINE_PLAYER_PANEL, 0, ONLINE_PLAYER_PANEL_SIZE);
}

/* Prepare a 0x6C-byte online player record for a new player: mark it not
 * connected with no player id, default its skill rating to RATING_DEFAULT, set
 * the per-slot state bytes to their unset values, and clear the name area and
 * the network panel record that follows it. */
void *InitOnlinePlayerRecord(void *record) {
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_FLAGS) = 0;
    M2C_FIELD(record, s8 *, ONLINE_PLAYER_ID) = -1;
    M2C_FIELD(record, s32 *, 0x1C) = -1;
    M2C_FIELD(record, s32 *, ONLINE_PLAYER_RATING) = RATING_DEFAULT;
    M2C_FIELD(record, s8 *, 0x24) = -1;
    M2C_FIELD(record, s8 *, 0x25) = -2;
    M2C_FIELD(record, s8 *, 0x26) = -2;
    M2C_FIELD(record, s8 *, 0x27) = -1;
    M2C_FIELD(record, s8 *, 0x28) = -1;
    MI_CpuFill8(record, 0, 0x1A);
    MI_CpuFill8(record + 0x2C, 0, 0x40);
    return record;
}

void func_ov010_022269dc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK CopyU16(M2C_UNK, M2C_UNK, M2C_UNK);
    CopyU16(arg1, arg0, 0x18);
}

void func_ov010_022269f8(s32 a,s32 b,s32 c){MI_CpuCopy8(b,a+44,c);}

/* Free every queued packet node of the outbound queue `queue`, then reset its
 * head, tail and count, with interrupts disabled so a producer cannot enqueue
 * while the list is being unlinked. */
void FreeOnlinePacketQueue(void *queue) {
    volatile u32 saved;
    u32 imeState;
    void *node;

    imeState = *(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = 0;
    node = M2C_FIELD(queue, void **, ONLINE_QUEUE_HEAD);
    saved = imeState;
    while (node != NULL) {
        M2C_FIELD(queue, void **, ONLINE_QUEUE_HEAD) = M2C_FIELD(node, void **, ONLINE_QUEUE_NODE_NEXT);
        Ov010_FreeBlock(0, (s32)node, M2C_FIELD(node, s32 *, ONLINE_QUEUE_NODE_SIZE) + ONLINE_QUEUE_NODE_HEADER);
        node = M2C_FIELD(queue, void **, ONLINE_QUEUE_HEAD);
    }
    M2C_FIELD(queue, s32 *, ONLINE_QUEUE_TAIL) = 0;
    M2C_FIELD(queue, s32 *, ONLINE_QUEUE_HEAD) = 0;
    M2C_FIELD(queue, s32 *, ONLINE_QUEUE_COUNT) = 0;
    (void)*(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = saved;
}

void func_ov010_02226a88(void) {
extern M2C_UNK gOv010OnlineSession,data_ov010_0222ef58,data_ov010_0222ef88,data_ov010_0222efb8;
extern Ov010MemberCall data_ov010_0222c128[];
volatile Ov010MemberCall firstCopy, secondCopy;
volatile u32 saved;
volatile Ov010MemberCall firstCall, secondCall;
u32 temp;void *p;
temp=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=0;
p=M2C_FIELD(&gOv010OnlineSession,void **,0x60);saved=temp;
while(p){M2C_FIELD(&gOv010OnlineSession,void **,0x60)=M2C_FIELD(p,void **,0);Ov010_FreeBlock(0,(s32)p,M2C_FIELD(p,s32 *,12)+16);p=M2C_FIELD(&gOv010OnlineSession,void **,0x60);}
M2C_FIELD(&gOv010OnlineSession,s32 *,0x64)=0;M2C_FIELD(&gOv010OnlineSession,s32 *,0x60)=0;M2C_FIELD(&gOv010OnlineSession,s32 *,0x68)=0;
(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;
{
    u8 *item = (u8 *)&data_ov010_0222ef58;
    u8 *last = (u8 *)&data_ov010_0222ef88;
    volatile Ov010MemberCall *call = &firstCall;
    s32 adjustment = data_ov010_0222c128[2].adjustment;
    s32 function = data_ov010_0222c128[2].function;
    firstCopy.adjustment = adjustment;
    firstCopy.function = function;
    call->function = function;
    call->adjustment = adjustment;
    if (item != last) do {
        u8 *object;
        adjustment = call->adjustment;
        object = item + (adjustment >> 1);
        if ((adjustment & 1) == 0) function = call->function;
        else function = *(s32 *)(*(u8 **)object + call->function);
        ((void (*)(void *))function)(object);
        item += 12;
    } while (item != last);
}
{
    u8 *item = (u8 *)&data_ov010_0222ef88;
    u8 *last = (u8 *)&data_ov010_0222efb8;
    volatile Ov010MemberCall *call = &secondCall;
    s32 adjustment = data_ov010_0222c128[1].adjustment;
    s32 function = data_ov010_0222c128[1].function;
    secondCopy.adjustment = adjustment;
    secondCopy.function = function;
    call->function = function;
    call->adjustment = adjustment;
    if (item != last) do {
        u8 *object;
        adjustment = call->adjustment;
        object = item + (adjustment >> 1);
        if ((adjustment & 1) == 0) function = call->function;
        else function = *(s32 *)(*(u8 **)object + call->function);
        ((void (*)(void *))function)(object);
        item += 12;
    } while (item != last);
}
}

#pragma cplusplus on
/* Whether a packet of the given kind (ONLINE_PACKET_*) is already waiting in
 * the online session's outbound queue. */
extern "C" s32 IsOnlinePacketKindQueued(s32 kind) {
    extern M2C_UNK gOv010OnlineSession;
    Ov010InterruptGuard guard;
    void *node = M2C_FIELD(&gOv010OnlineSession, void **, ONLINE_SESSION_QUEUE);
    while (node != NULL) {
        if (kind == M2C_FIELD(node, u8 *, ONLINE_QUEUE_NODE_KIND)) return 1;
        node = M2C_FIELD(node, void **, ONLINE_QUEUE_NODE_NEXT);
    }
    return 0;
}
#pragma cplusplus off
/* Send periodic heartbeats, disconnect silent peers, and advance the network session. */
void TickOnlinePeerKeepAlive(void *link) {
    s32 FX_Div(s32, s32);
    s32 Divide(s32, s32);
    s32 IsConnectionActive(u8);
    void TickNetSession(void);
    s32 IsOnlinePacketKindQueued(s32);
    void DisconnectOnlinePeer(u8);
    void QueueOnlinePacket(s32, void *, s32, u16);
    s32 GetOnlineTransportPlayerId(void);
    s32 GetOnlinePeerMask(void);
    s32 elapsedMs, frames, timeoutFrames, connectedPeers;
    u16 remotePeers;
    u8 peer;

    elapsedMs = FX_Div(ONLINE_MS_PER_SECOND_FX12, ONLINE_TICK_RATE_FX12);
    frames = M2C_FIELD(link, s32 *, ONLINE_HEARTBEAT_FRAMES) + 1;
    elapsedMs = (frames * elapsedMs) >> 12;
    M2C_FIELD(link, s32 *, ONLINE_HEARTBEAT_FRAMES) = frames;
    if (elapsedMs > ONLINE_HEARTBEAT_INTERVAL_MS) {
        connectedPeers = GetOnlinePeerMask();
        remotePeers = connectedPeers & (-1 ^ (1U << GetOnlineTransportPlayerId()));
        if (remotePeers && (remotePeers & GetOnlinePeerMask()) && !IsOnlinePacketKindQueued(ONLINE_PACKET_HEARTBEAT))
            QueueOnlinePacket(ONLINE_PACKET_HEARTBEAT, link + ONLINE_HEARTBEAT_FRAMES, 4, remotePeers);
        M2C_FIELD(link, s32 *, ONLINE_HEARTBEAT_FRAMES) = 0;
    }
    timeoutFrames = Divide(ONLINE_PEER_TIMEOUT_NUMERATOR, ONLINE_MILLISECONDS_PER_SECOND);
    peer = 0;
    do {
        if (IsConnectionActive(peer)) {
            {
                void *entry = link + peer * 4;
                frames = M2C_FIELD(entry, s32 *, ONLINE_PEER_IDLE_FRAMES) + 1;
                M2C_FIELD(entry, s32 *, ONLINE_PEER_IDLE_FRAMES) = frames;
            }
            if (frames > timeoutFrames) {
                DisconnectOnlinePeer(peer);
                ((s32 *)(link + ONLINE_PEER_IDLE_FRAMES))[peer] = 0;
            }
        } else
            ((s32 *)(link + ONLINE_PEER_IDLE_FRAMES))[peer] = 0;
        peer++;
    } while (peer < ONLINE_PEER_COUNT);
    TickNetSession();
}

void func_ov010_02226d74(void *arg0) {
    M2C_UNK Ov010_FreeBlock(M2C_UNK, s32, s32);
    Ov010_FreeBlock(0, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}

