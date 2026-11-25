/* 47 functions from 0x02227D34 to 0x02228D1C (ov010), found by ds-decomp. */
#include "common.h"
#include "online_link.h"
#include "wfc.h"
M2C_UNK func_ov010_02226a88();
M2C_UNK ClearOnlineEventFlags();
#pragma cplusplus on
class Ov010Callback { public: void run(); };
typedef void (Ov010Callback::*Ov010CallbackFn)();
#pragma cplusplus off

/* NAS callback for a player record received by the ov010 online session:
 * base64-decode the message into a player record, store its name and option
 * bytes in the battle save block's slot `slot`, then pass the message on to
 * the session's installed record callback. */
void func_ov010_02227d34(s32 slot, void *data, char *text, s32 size) {
    void InitOnlinePlayerRecord(void *);
    s32 StringLength(char *);
    s32 DecodeNasBase64(char *, s32, void *, s32);
    void *GetBattleSaveBlock(void);
    void CopyU16(void *, void *, s32);
    extern M2C_UNK gOv010OnlineSession;
    char record[0x6c];
    s32 length;
    void *saveBlock;
    s32 offset;
    char *slotRecord;
    void (*callback)(s32, void *, char *, s32);

    if (text != 0 && *text != 0) {
        InitOnlinePlayerRecord(record);
        length = StringLength(text);
        if (DecodeNasBase64(text, length, record, 0x6c) == 0x6c) {
            saveBlock = GetBattleSaveBlock();
            offset = slot * 0x28;
            CopyU16(record, (char *)saveBlock + SAVE_RECORDS_OFFSET + offset, 0x18);
            slotRecord = (char *)saveBlock + offset;
            /* the record's option bytes, at record +0x20 */
            slotRecord[0x2f4] = (signed char)record[0x24];
            slotRecord[0x2f5] = (signed char)record[0x25];
            slotRecord[0x2f6] = (signed char)record[0x26];
        }
    }

    callback = *(void (**)(s32, void *, char *, s32))((char *)&gOv010OnlineSession + 4);
    if (callback != 0) {
        callback(slot, data, text, size);
    }
}

/* Start callback of the ov010 online session's WFC match query: raise the
 * matchmaking flag once matchmaking has begun, unless a net error is pending
 * (then the session is already failing and must not look live). */
void Ov010Online_OnMatchmakingStarted(void) {
    void SetOnlineSessionFlag(M2C_UNK);
    s32 GetNetErrorCode();
    s32 netError;

    if (GetNetErrorCode() != 0) {
        netError = 1;
    } else {
        netError = 0;
    }
    if (netError != 0) {
        return;
    }
    SetOnlineSessionFlag(OV010_FLAG_MATCHMAKING);
}

/* Starts the ov010 online session: does nothing if it is already running,
 * otherwise raises the running flag, stores the owner id and installs the
 * transfer and frame callbacks; if a NAS error is pending, hands it to the
 * installed error handler. */
void Ov010Online_StartSession(s32 owner, s32 arg1) {
    s32 GetNetErrorCode(void);
    s32 PublishPlayerStatusLocation(void *, s32);
    s32 Transfer_SetStartCallback(s32);
    s32 Transfer_SetEndCallback(s32);
    s32 SetNetPeerCallback(s32, s32);
    s32 SetMatchSessionSlotCallback(s32, s32);
    s32 StartMatchMaking(s32, s32, s32, s32, s32, s32, s32);
    s32 GetLastNasError(void);
    void func_ov010_02227934(void);
    void func_ov010_02227954(void);
    void Ov010Online_OnPeerConnectionLost(void);
    void func_ov010_02227c3c(void);
    void func_ov010_02227c5c(void);
    void Ov010Online_OnMatchmakingStarted(void);
    void func_ov010_02227d34(s32, void *, char *, s32);
    extern M2C_UNK gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;

    s32 var_r0;
 u32 flags;

    if (GetNetErrorCode() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        return;
    }

    flags = M2C_FIELD(&gOv010OnlineSession, u8 *, 0xfa);
 M2C_FIELD(&gOv010OnlineSession, u8 *, 0xfa) = flags | 1;
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0xfc) = arg1;
    PublishPlayerStatusLocation(&gLocalPlayerStatus, 0x6c);

    Transfer_SetStartCallback((s32)func_ov010_02227934);
    Transfer_SetEndCallback((s32)func_ov010_02227954);
    SetNetPeerCallback((s32)Ov010Online_OnPeerConnectionLost, 0);
    SetMatchSessionSlotCallback((s32)func_ov010_02227c3c, 0);

    StartMatchMaking(0, (s32)Ov010Online_OnMatchmakingStarted, 0, (s32)func_ov010_02227d34, 0,
                   (s32)func_ov010_02227c5c, 0);

    if (GetLastNasError() != 2) {
        return;
    }

    if (M2C_FIELD(&gOv010OnlineSession, s32 *, 0x40) == 0) {
        return;
    }

    {
        s32 code = GetLastNasError();
        void (*handler)(s32) = M2C_FIELD(&gOv010OnlineSession, void (**)(s32), 0x40);
        handler(code);
    }
}

/* Assigns a receive buffer to each connected peer, skipping the local player. */
void Ov010Online_SetupPeerReceiveBuffers(void) {
    s32 GetActiveConnectionList(u8 **);
    s32 GetOnlineTransportPlayerId(void);
    s32 SetTransferReceiveBuffer(u32, void *, s32);
    extern M2C_UNK gOv010OnlineSession;
    u8 *playerIds;
    s32 playerCount = GetActiveConnectionList(&playerIds);
    s32 i;
    u32 playerId;
    u32 bufferIndex;

    for (i = 0; i < playerCount; i++) {
        playerId = playerIds[i];
        if (playerId != GetOnlineTransportPlayerId()) {
            if (playerId < (u32)GetOnlineTransportPlayerId())
                bufferIndex = playerId;
            else
                bufferIndex = playerId - 1;

            SetTransferReceiveBuffer(playerId,
                M2C_FIELD(&gOv010OnlineSession, u8 **, OV010_SESSION_PEER_RX_BUFFERS) +
                    bufferIndex * OV010_PEER_RX_BUFFER_SIZE,
                OV010_PEER_RX_BUFFER_SIZE);
        }
    }
}

void SetOnlinePlayerRecord(s32 arg0, M2C_UNK arg1) {
    M2C_UNK MI_CpuCopy8(M2C_UNK, s32);
    extern M2C_UNK gOv010PlayerRecords;
    MI_CpuCopy8(arg1, (arg0 * 0x6C) + (s32) &gOv010PlayerRecords);
}

/* Host/join match event callback: with no network error and the event not
 * aborted, mark the session running, record the local transport player id, copy
 * the local player status and start the transfer lists; otherwise mark the
 * start failed.  The event is then passed to the running match's callback. */
void Ov010Online_OnHostJoinEvent(s32 error, s32 aborted, s32 data) {
    s32 GetNetErrorCode(void);
    void SetOnlineSessionFlag(s32);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    s32 GetOnlineTransportPlayerId(void);
    s32 PublishPlayerStatusLocation(void *, s32);
    void Ov010Online_SetupPeerReceiveBuffers(void);
    s32 PublishLocalPlayerStatus(void);
    extern M2C_UNK gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;
    s32 netError;
    void (*cb)(s32, s32, s32);
    netError = GetNetErrorCode();
    netError = (netError != 0);
    if (netError == 0) {
        if (aborted == 0) {
            SetOnlineSessionFlag(OV010_FLAG_RUNNING);
            M2C_FIELD(&gOv010OnlineSession, u8 *, OV010_SESSION_LOCAL_ID) = GetOnlineTransportPlayerId();
            PublishPlayerStatusLocation(&gLocalPlayerStatus, 0x6c);
            Ov010Online_SetupPeerReceiveBuffers();
            PublishLocalPlayerStatus();
        } else {
            SetOnlineSessionFlag(OV010_FLAG_FAILED);
        }
    } else {
        SetOnlineSessionFlag(OV010_FLAG_FAILED);
        Ov010Online_ClearStepFlag(OV010_FLAG_RUNNING);
    }
    cb = M2C_FIELD(&gOv010OnlineSession, void (**)(s32, s32, s32), OV010_SESSION_CALLBACK);
    if (cb == 0) return;
    cb(error, aborted, data);
}

/* Score a browsed matchmaking session: 1 plus the score the online session's
 * own score callback gives for session `index` (0 when none is installed), so
 * the connection layer's session filter keeps it unless the app scores it -1. */
s32 Ov010Online_ScoreMatch(s32 index, s32 callbackArg) {
    extern M2C_UNK gOv010OnlineSession;
    s32 score = 1;
    s32 (*scoreCallback)(s32, s32) = M2C_FIELD(&gOv010OnlineSession, s32 (**)(s32, s32), OV010_SESSION_SCORE_CALLBACK);

    if (scoreCallback) {
        score += scoreCallback(index, callbackArg);
    }
    return score;
}

/* Handles the online session's start of a battle: lets the installed start
 * callback run the setup (waiting for the other player, or recording the local
 * player id and status before the first transfer), then forwards the start to
 * the session's registered callback. */
void func_ov010_0222807c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 GetNetErrorCode(void);
    void SetOnlineSessionFlag(s32);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    s32 GetOnlineTransportPlayerId(void);
    s32 PublishPlayerStatusLocation(void *, s32);
    void Ov010Online_SetupPeerReceiveBuffers(void);
    s32 PublishLocalPlayerStatus(void);
    extern M2C_UNK gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;

    s32 t;

    t = GetNetErrorCode();
    t = (t != 0);

    if (t == 0) {
        if (arg1 == 0) {
            SetOnlineSessionFlag(3);
            M2C_FIELD(&gOv010OnlineSession, u8 *, 0xfb) =
                (u8)GetOnlineTransportPlayerId();
            PublishPlayerStatusLocation(&gLocalPlayerStatus, 0x6c);
            Ov010Online_SetupPeerReceiveBuffers();
            PublishLocalPlayerStatus();
            goto callback_call;
        }

        if (arg2 == 0 && arg3 == 0) {
            goto callback_call;
        }

        SetOnlineSessionFlag(4);
        Ov010Online_ClearStepFlag(3);
        goto callback_call;
    }

    SetOnlineSessionFlag(4);
    Ov010Online_ClearStepFlag(3);

callback_call:
    if (M2C_FIELD(
            &gOv010OnlineSession,
            void (* volatile *)(s32, s32, s32, s32, s32, s32),
            0x8
        ) == 0) {
        return;
    }

    M2C_FIELD(
        &gOv010OnlineSession,
        void (* volatile *)(s32, s32, s32, s32, s32, s32),
        0x8
    )(arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_ov010_0222815c(s32 a,s32 b) {
 extern M2C_UNK gOv010OnlineSession;
 void (*cb)(s32,s32)=M2C_FIELD(&gOv010OnlineSession,void (**)(s32,s32),0x44);
 if(!cb)return; cb(a,b);
}

void Ov010Online_MatchStartNoop(void) {

}

/* Brings up the ov010 online session: returns 0 when the session is already
 * running (mode 0 raised); otherwise checks the NAS player status in a temporary
 * 0x700-byte buffer, and unless that status is 3 frees it and allocates the
 * session's 0x10e0-byte work block, invalidates it, plays the online start sound
 * (0x5b9) and clears the session's callbacks so the session starts fresh.  The
 * status is returned (3 = not available here). */
s32 func_ov010_02228180(void) {
    M2C_UNK IsOnlineSessionFlagSet(M2C_UNK);
    M2C_UNK func_ov010_022268f4(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov010_FreeBlock(M2C_UNK, s32, s32);
    s32 CheckSaveAndWfcProfile(M2C_UNK);
    void func_02037680(s32, s32);
    M2C_UNK DC_InvalidateRange(M2C_UNK, s32);
    M2C_UNK func_ov010_02226a88();
    s32 func_02044658(u16);
    M2C_UNK ClearOnlineEventFlags();
    void func_ov010_02228280(M2C_UNK);
    extern M2C_UNK gOv010OnlineSession;
    M2C_UNK statusBuffer;
    M2C_UNK workBlock;
    s32 status;

    if (IsOnlineSessionFlagSet(0) != 0) {
        return 0;
    }
    statusBuffer = func_ov010_022268f4(0, 0x700, 0x20);
    status = CheckSaveAndWfcProfile(statusBuffer);
    Ov010_FreeBlock(0, statusBuffer, 0x700);
    if (status != 3) {
        func_02037680((s32)func_ov010_022268f4, (s32)Ov010_FreeBlock);
        workBlock = func_ov010_022268f4(0, 0x10e0, 0x20);
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x3c) = workBlock;
        DC_InvalidateRange(workBlock, 0x10e0);
        func_ov010_02226a88();
        func_02044658(0x5b9);
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x40) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x38) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x4c) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x2c) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x34) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x10) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x14) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x4) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x20) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0xc) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x8) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x44) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x58) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x1c) = 0;
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x50) = 0;
        ClearOnlineEventFlags();
        func_ov010_02228280(0);
    }
    return status;
}

void Ov010Online_ResetStepFlags(void) {
    extern M2C_UNK gOv010OnlineSession;
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x54) = 0;
}

void func_ov010_02228280(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x54) = 1 << arg0;
}

void SetOnlineSessionFlag(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    M2C_FIELD(&gOv010OnlineSession, s32 *, (unsigned)0x54) =
        (M2C_FIELD(&gOv010OnlineSession, s32 *, 0x54) | (1 << arg0));
}

s32 IsOnlineSessionFlagSet(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 var_r2 = 1;
    if (!(M2C_FIELD(&gOv010OnlineSession, s32 *, 0x54) & (1 << arg0))) {
        var_r2 = 0;
    }
    return var_r2;
}

M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 v;
    v = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x54);
    v = v & (-1 ^ (1 << arg0));
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x54) = v;
    return v;
}

s32 GetNetErrorCode(void) {
    void func_ov010_02228314();
    s32 out[2];
    func_ov010_02228314(&out[1], &out[0]);
}

void func_ov010_02228314(void) {
    M2C_UNK GetNetError();
    GetNetError();
}

void func_ov010_02228320(void) {
    M2C_UNK ClearNetError();
    ClearNetError();
}

#pragma optimize_ifs off
s32 func_ov010_0222832c(s32 arg0, s32 arg1) {
    s32 var_r0;
    s32 var_r1;

    var_r0 = arg0;
    switch(arg1) { case 0: case 1: case 2: var_r1=0; break; default: var_r1=1; break; }
    if (var_r0 < 0) {
        var_r0 = 0 - var_r0;
    }
    if ((var_r0 == 0x4E85) || ((var_r0 >= 0x59D8) && (var_r0 <= 0x5DBF))) {
        return 0x42000007;
    }
    if (var_r0 == 0x4E8C) {
        return 0x42000008;
    }
    if (var_r0 == 0x4E8E) {
        return 0x42000009;
    }
    if ((var_r0 >= 0xC800) && (var_r0 <= 0xC863)) {
        return 0x4200000A;
    }
    if ((var_r0 >= 0xC350) && (var_r0 <= 0xC3B3)) {
        return 0x4200000B;
    }
    if (var_r0 == 0xC79F) {
        return 0x4200000D;
    }
    if (((var_r0 >= 0xC738) && (var_r0 <= 0xC79B)) || ((var_r0 >= 0xC79C) && (var_r0 <= 0xC7FF)) || ((var_r0 >= 0xC864) && (var_r0 <= 0xC8C7))) {
        return 0x4200000C;
    }
    if (((var_r0 >= 0xCB20) && (var_r0 <= 0xCB23)) || ((var_r0 >= 0xCB84) && (var_r0 <= 0xCB87)) || ((var_r0 >= 0xCBE8) && (var_r0 <= 0xCBEB))) {
        return 0x4200000E;
    }
    if (var_r0 == 0x13A2E) {
        return 0x4200000F;
    }
    if (((var_r0 >= 0x4E20) && (var_r0 <= 0x5207)) || ((var_r0 >= 0xCB20) && (var_r0 <= 0xCB83)) || ((var_r0 >= 0xCB84) && (var_r0 <= 0xCBE7)) || ((var_r0 >= 0xCBE8) && (var_r0 <= 0xCC4B)) || ((var_r0 >= 0xCC4C) && (var_r0 <= 0xCCAF)) || ((var_r0 >= 0xCF08) && (var_r0 <= 0xCF6B)) || ((var_r0 >= 0xCF6C) && (var_r0 <= 0xCFCF)) || ((var_r0 >= 0xCFD0) && (var_r0 <= 0xD033))) {
        return 0x42000006;
    }
    if ((var_r1 == 0) && (var_r0 >= 0x7918) && (var_r0 <= 0x7CFF)) {
        return 0x42000011;
    }
    if (var_r1 != 0) {
        return 0x42000010;
    }
    return 0x42000012;
}
#pragma optimize_ifs reset
/* Start the ov010 online session's WFC connection: the session is no longer
 * connected, so clear the connected flag, tear the old session blocks down, create
 * the 12-byte connection object and start WFC on the production NAS server. */
void Ov010Online_StartWfcConnection(void) {
    M2C_UNK func_0203783c(M2C_UNK *);
    M2C_UNK SetNasServerEnvironment(M2C_UNK);
    M2C_UNK Wfc_StartConnection();
    M2C_UNK func_ov010_02226a88();
    extern M2C_UNK gOv010WfcConnection;

    Ov010Online_ClearStepFlag(OV010_FLAG_CONNECTED);
    func_ov010_02226a88();
    func_0203783c(&gOv010WfcConnection);
    SetNasServerEnvironment(NAS_SERVER_PROD);
    Wfc_StartConnection();
}

/* WFC connection start step: while there is no connection object to poll yet,
 * drive the connection update and keep waiting (return 1); once polling can
 * start, mark the online session connected and return 0. */
s32 Ov010Online_WaitForConnection(void) {
    s32 Wfc_PollConnecting();
    M2C_UNK Wfc_UpdateConnection();
    if (Wfc_PollConnecting() != 0) {
        SetOnlineSessionFlag(OV010_FLAG_CONNECTED);
        return 0;
    }
    Wfc_UpdateConnection();
    return 1;
}

M2C_UNK func_ov010_0222866c(M2C_UNK arg0) {
    M2C_UNK func_02037c10(M2C_UNK);
    return func_02037c10(arg0);
}

/* Step the matchmaking HTTP request: return 1 while it is still running, else
 * store the outcome in *outSuccess (1 = matched, 0 = failed) and return 0.
 * The step codes are the WFC_HTTP_STEP_* values PollWfcMatchmakingHttp returns. */
s32 Ov010Online_PollMatchmaking(M2C_UNK *outSuccess) {
    M2C_UNK PollWfcMatchmakingHttp(void);
    s32 running;
    u32 step;

    running = 1;
    step = PollWfcMatchmakingHttp();
    switch (step) {
    case 0: /* WFC_HTTP_STEP_NONE */
        running = 0;
        break;
    case 1: /* WFC_HTTP_STEP_RUNNING */
        break;
    case 2: /* WFC_HTTP_STEP_DONE */
        M2C_FIELD(outSuccess, s32 *, 0) = 1;
        running = 0;
        break;
    case 3: /* WFC_HTTP_STEP_FAILED */
        M2C_FIELD(outSuccess, s32 *, 0) = 0;
        running = 0;
        break;
    default:
        break;
    }
    return running;
}

void func_ov010_022286cc(void *arg0) {
    M2C_UNK func_ov010_0222866c(M2C_UNK);
    M2C_UNK DeleteSpriteObject(void *);
    if (func_ov010_0222866c(M2C_FIELD(arg0, s32 *, 0x34)) != 0) {
        return;
    }
    DeleteSpriteObject(arg0);
}

void func_ov010_022286f0(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    s32 Ov010Online_PollMatchmaking(M2C_UNK *);
    if (Ov010Online_PollMatchmaking(M2C_FIELD(arg0, s32 *, 0x38)) != 0) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

void func_ov010_02228714(void) {
    M2C_UNK Wfc_PollSessionEnd();
    Wfc_PollSessionEnd();
}

/* Poll the WFC session for its end: once it has ended, clear the session's
 * connected flag.  Returns 1 while the session is still up, 0 once it ended. */
s32 Ov010Online_PollSessionEnd(void) {
    s32 ended;

    ended = Wfc_PollSessionEnd();
    if (ended != 0) {
        Ov010Online_ClearStepFlag(OV010_FLAG_CONNECTED);
    }
    if (ended == 0) {
        return 1;
    }
    return 0;
}

void func_ov010_02228748(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov010_0222c1b8;
    CreateSpriteObject(&data_ov010_0222c1b8, arg0);
}

#pragma push
#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
extern "C" void Ov010Online_InitSession(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j) {
    extern M2C_UNK data_ov010_0222c3fc;
    extern M2C_UNK data_ov010_0222f1dc;
    extern M2C_UNK data_ov010_0222c3f0;
    extern M2C_UNK gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;
    extern M2C_UNK data_ov010_0222efec;
    extern M2C_UNK data_ov010_0222c128;
    extern M2C_UNK gOv010PlayerRecords;
    extern M2C_UNK gOv010SessionStateClass;
    extern M2C_UNK data_ov010_0222c3bc;
    extern M2C_UNK gOv010ConnectionClass;
    extern M2C_UNK data_ov010_0222c3a8;
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    void func_ov010_0222791c(M2C_UNK);
    void *GetProfileSaveBlock(void);
    void *GetBattleSaveBlock(void);
    M2C_UNK func_ov010_02228b20(M2C_UNK);
    M2C_UNK func_ov010_02228b38(M2C_UNK);
    M2C_UNK func_ov010_02228b68(M2C_UNK);
    M2C_UNK func_ov010_02228b80(M2C_UNK);
    M2C_UNK func_ov010_02228b98(M2C_UNK);
    M2C_UNK func_ov010_02228bb0(M2C_UNK);
    void func_ov010_02229498(M2C_UNK);
    void func_ov010_022294b0(M2C_UNK);
    void SetOnlineMessageHandler(M2C_UNK);
    s32 GetEarnedRecordTierTotal(void);
    s32 GetRecordRank(void);
    s32 GetFavouriteRecordGroup(void);
    s32 GetFavouriteRecordIndex(void);
    void *CreateSpriteFromClass(void *, s32);
    void MI_CpuFill8(void *, s32, s32);
    void InitNetSession(void *, void *, s32, void *, void *, s32, s32, void *, s32);
    void StartNetLogin(void *, s32, void *, s32);
    void ConstructArray(void *, s32, s32, void *, void *);


    void *GetLocalPlayerName(void);
    void func_ov010_022269dc(void *, void *);
    void MI_CpuFill32(s32, void *, s32);
    void func_ov010_02228a38(void *);
    void *FreePacketAssemblySlot(void *);
    extern M2C_UNK gOv010PacketAssemblyClass, data_ov010_0222c3d0;
    void *r4;
    void *obj;
    void *state;
    u8 *p;
    Ov010CallbackFn cc, aa, bb;
    volatile Ov010CallbackFn dd;
    Ov010Online_ClearStepFlag(2);
    func_ov010_0222791c(a);
    func_ov010_02226a88();
    r4=GetProfileSaveBlock();
    obj=GetBattleSaveBlock();
    InitNetSession(&data_ov010_0222f1dc,(u8 *)r4+4,0x2b96,&data_ov010_0222c3f0,&data_ov010_0222c3fc,0,0,(u8 *)obj+4,60);
    func_ov010_02228b20(b);
    func_ov010_02228b38(c);
    func_ov010_02228b68(d);
    func_ov010_02228b80(e);
    func_ov010_02228b98(f);
    func_ov010_02228bb0(g);
    func_ov010_02229498(h);
    func_ov010_022294b0(i);
    SetOnlineMessageHandler(j);
    ClearOnlineEventFlags();
    state=&gOv010OnlineSession;
    M2C_FIELD(state,s32 *,0x18)=0;
    M2C_FIELD(state,s32 *,0x24)=0;
    MI_CpuFill8(&gLocalPlayerStatus,0,0x1a);
    M2C_FIELD(&gOv010OnlineSession,s8 *,0xfa)=0;
    M2C_FIELD(&gOv010OnlineSession,s8 *,0xfb)=-1;
    M2C_FIELD(&gOv010OnlineSession,s32 *,0xfc)=-1;
    M2C_FIELD(&gOv010OnlineSession,s32 *,0x100)=0x5dc000;
    M2C_FIELD(&gOv010OnlineSession,s8 *,0x104)=-1;
    M2C_FIELD(&gOv010OnlineSession,s8 *,0x105)=-2;
    M2C_FIELD(&gOv010OnlineSession,s8 *,0x106)=-2;
    M2C_FIELD(&gOv010OnlineSession,s8 *,0x107)=-1;
    M2C_FIELD(&gOv010OnlineSession,s8 *,0x108)=-1;
    MI_CpuFill8(&data_ov010_0222efec,0,0x40);
    aa=*(Ov010CallbackFn *)&data_ov010_0222c128;
    bb=aa;
    cc=bb;
    for(p=(u8 *)&gOv010PlayerRecords;p!=(u8 *)&data_ov010_0222f1dc;p+=0x6c) {
        (((Ov010Callback *)p)->*cc)();
    }
    dd=cc;
    func_ov010_022269dc(&gLocalPlayerStatus,GetLocalPlayerName());
    GetEarnedRecordTierTotal();
    M2C_FIELD(&gOv010OnlineSession,u8 *,0x104)=GetRecordRank();
    M2C_FIELD(&gOv010OnlineSession,u8 *,0x105)=GetFavouriteRecordGroup();
    M2C_FIELD(&gOv010OnlineSession,u8 *,0x106)=GetFavouriteRecordIndex();
    M2C_FIELD(&gOv010OnlineSession,s32 *,0x100)=M2C_FIELD(r4,s32 *,0x54);
    StartNetLogin(&gLocalPlayerStatus,0,(void *)Ov010Online_StartSession,0);
    obj=CreateSpriteFromClass(&gOv010SessionStateClass,3);
    if(obj) {
        M2C_FIELD(obj,void **,0)=&data_ov010_0222c3bc;
        M2C_FIELD(obj,s32 *,0x34)=0;
        MI_CpuFill32(0,(u8 *)obj+0x38,0x10);
    }
    obj=CreateSpriteFromClass(&gOv010ConnectionClass,3);
    if(obj) {
        M2C_FIELD(obj,void **,0)=&data_ov010_0222c3a8;
        M2C_FIELD(obj,s32 *,0x34)=0;
        M2C_FIELD(obj,s32 *,0x38)=0;
        M2C_FIELD(obj,s32 *,0x3c)=0;
        M2C_FIELD(obj,s32 *,0x40)=0;
        M2C_FIELD(obj,u16 *,0x44)=0;
    }
    obj=CreateSpriteFromClass(&gOv010PacketAssemblyClass,3);
    if(obj) {
        M2C_FIELD(obj,void **,0)=&data_ov010_0222c3d0;
        ConstructArray((u8 *)obj+0x34,4,8,(void *)func_ov010_02228a38,(void *)FreePacketAssemblySlot);
    }
}
#pragma pop
void func_ov010_02228a38(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

/* Clear one per-peer packet-assembly slot: free the packet it was assembling
 * (OV010_ASSEMBLY_SLOT_PACKET) and clear the slot.  Returns the slot. */
void *FreePacketAssemblySlot(void *slot) {
    void Ov010Online_FreePacket(void *);

    if (M2C_FIELD(slot, void **, OV010_ASSEMBLY_SLOT_PACKET) != NULL) {
        Ov010Online_FreePacket(M2C_FIELD(slot, void **, OV010_ASSEMBLY_SLOT_PACKET));
        M2C_FIELD(slot, void **, OV010_ASSEMBLY_SLOT_PACKET) = NULL;
    }
    return slot;
}

/* Tear down the ov010 online session: delete its state, connection and packet
 * reassembly screen objects, close the global net session, then clear the
 * session's callbacks and per-peer state (each setter below resets one field)
 * and leave the in-match step. */
void Ov010Online_EndSession(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK);
    void TeardownNetSession(void);
    void func_ov010_0222791c(M2C_UNK);
    s32 func_ov010_02228b20(M2C_UNK);
    s32 func_ov010_02228b38(M2C_UNK);
    s32 Ov010_SetVoiceChatCallback(M2C_UNK);
    s32 func_ov010_02228b68(M2C_UNK);
    s32 func_ov010_02228b80(M2C_UNK);
    s32 func_ov010_02228b98(M2C_UNK);
    s32 func_ov010_02228bb0(M2C_UNK);
    void func_ov010_02229438(M2C_UNK);
    void func_ov010_02229450(M2C_UNK);
    void func_ov010_02229468(M2C_UNK);
    void func_ov010_02229480(M2C_UNK);
    void func_ov010_02229498(M2C_UNK);
    void func_ov010_022294b0(M2C_UNK);
    void SetOnlineMessageHandler(M2C_UNK);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    extern M2C_UNK gOv010SessionStateClass;
    extern M2C_UNK gOv010ConnectionClass;
    extern M2C_UNK gOv010PacketAssemblyClass;
    DeleteSpriteObjectsOfClass(&gOv010SessionStateClass);
    DeleteSpriteObjectsOfClass(&gOv010ConnectionClass);
    DeleteSpriteObjectsOfClass(&gOv010PacketAssemblyClass);
    TeardownNetSession();
    func_ov010_0222791c(0);
    func_ov010_02228b20(0);
    func_ov010_02228b38(0);
    Ov010_SetVoiceChatCallback(0);
    func_ov010_02228b68(0);
    func_ov010_02228b80(0);
    func_ov010_02228b98(0);
    func_ov010_02228bb0(0);
    func_ov010_02229438(0);
    func_ov010_02229450(0);
    func_ov010_02229468(0);
    func_ov010_02229480(0);
    func_ov010_02229498(0);
    func_ov010_022294b0(0);
    SetOnlineMessageHandler(0);
    Ov010Online_ClearStepFlag(2);
}

s32 func_ov010_02228b20(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x38);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x38) = arg0;
    return temp_r2;
}

s32 func_ov010_02228b38(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x4C);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x4C) = arg0;
    return temp_r2;
}

s32 Ov010_SetVoiceChatCallback(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 old = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x2c);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x2c) = arg0;
    return old;
}

s32 func_ov010_02228b68(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x34);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x34) = arg0;
    return temp_r2;
}

s32 func_ov010_02228b80(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x10);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x10) = arg0;
    return temp_r2;
}

s32 func_ov010_02228b98(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x14);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x14) = arg0;
    return temp_r2;
}

s32 func_ov010_02228bb0(s32 arg0) {
    extern M2C_UNK gOv010OnlineSession;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x4);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x4) = arg0;
    return temp_r2;
}

void func_ov010_02228bc8(void) {
    M2C_UNK LeaveNetMatch();
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    LeaveNetMatch();
    Ov010Online_ClearStepFlag(3);
}

/* One per-frame step of the ov010 online transfer sprite: while a packet is
 * still queued, or any remote peer's send slot is busy, the sprite's animation
 * is held on its current frame; once the link is idle it resumes.
 * (1 - 2) is -1, which drops the local player's own bit from the peer mask. */
void Ov010Online_AdvanceTransferSprite(void *sprite) {
    s32 CanStartSend(u8);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    s32 GetNetErrorCode();
    s32 Ov010Online_IsSendQueueEmpty();
    s32 GetOnlineTransportPlayerId();
    s32 GetOnlinePeerMask();
    s32 peerMask;
    s32 netError;
    u16 remotePeers;
    s32 player;
    s32 one;

    if (IsOnlineSessionFlagSet(OV010_FLAG_RUNNING) == 0) goto end;
    if (GetNetErrorCode() != 0) {
        netError = 1;
    } else {
        netError = 0;
    }
    if (netError != 0) goto end;
    if (IsOnlineSessionFlagSet(OV010_FLAG_ERROR) != 0) goto end;
    if (Ov010Online_IsSendQueueEmpty() == 0) {
        return;
    }
    peerMask = GetOnlinePeerMask();
    one = 1;
    remotePeers = (u16)(peerMask & ((one - 2) ^ (one << GetOnlineTransportPlayerId())));
    if (remotePeers == 0) goto end;
    player = 0;
    one = 1;
loop:
    if ((remotePeers & (one << player)) && (CanStartSend((u8)player) == 0)) {
        return;
    }
    player = player + 1;
    if (player < 4) goto loop;
end:
    Sprite_ResumeAnimation(sprite);
}

/* Leave the online match: tell every peer the local player is departing, then
 * create the departure sprite (owned by `owner`) that tears the session down. */
void CreateOnlineDepartureObject(M2C_UNK owner) {
    M2C_UNK QueueOnlineLinkPacket(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK gOnlineDepartureSpriteClass;
    QueueOnlineLinkPacket(ONLINE_PACKET_DEPARTURE, 0, 0, 0xFFFF);
    CreateSpriteObject(&gOnlineDepartureSpriteClass, owner);
}

void func_ov010_02228cbc(void) {
    M2C_UNK DisconnectPeerSlot();
    DisconnectPeerSlot();
}

void func_ov010_02228cc8(void) {
    M2C_UNK func_02037bb8();
    func_02037bb8();
}

void func_ov010_02228cd4(void) {
      void Ov010Online_EndSession();
  func_ov010_02228320();
    Ov010Online_EndSession();
}

/* Tear down the online session's own work: flush its queued packets and reset
 * its objects, hand the session's work block back to the allocator, and clear
 * the session's step flags. */
void Ov010Online_FreeWorkBlock(void) {
    M2C_UNK func_ov010_02226a88();
    M2C_UNK Ov010_FreeBlock(M2C_UNK, s32, s32);
    void Ov010Online_ResetStepFlags(void);
    extern M2C_UNK gOv010OnlineSession;
    func_ov010_02226a88();
    Ov010_FreeBlock(0, M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_WORK_BLOCK), OV010_SESSION_WORK_SIZE);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_WORK_BLOCK) = 0;
    Ov010Online_ResetStepFlags();
}

