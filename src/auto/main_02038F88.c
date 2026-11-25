/* 33 functions from 0x02038F88 to 0x02039EFC (main), found by ds-decomp. */
#include "common.h"
#include "net_session.h"
#include "wfc.h"

/* Opens the GameSpy GT2 socket of the logged-in session: picks a random local
 * port, creates the socket with the session's buffer sizes and the socket-error
 * callback, then installs the connect-attempt and unrecognized-message (raw
 * GameSpy/NAT packet) callbacks.  Does nothing when the socket is already open;
 * returns the socket-open result (0 on success). */
s32 OpenGameSpySocket(void){
 extern void *gNetSession;
 s32 RandomBelow(s32);s32 gt2AddressToString(s32,u16,s32);
 s32 Gt2CreateSocket(void *,s32,s32,s32,void (*)(s32 *));
 void Gt2SocketErrorCallback(s32 *); void HandleGt2ConnectAttempt(void); void RouteIncomingGameSpyPacket(void);
 void Gt2SocketSetConnectAttempt(s32,void (*)(void));void Gt2SocketSetUnrecognizedCallback(s32,void (*)(void));
 u32 ReportGt2SocketResult();
 void *session; s32 result;u16 angle;
 if(M2C_FIELD(gNetSession,s32 *,NET_SESSION_SOCKET))return 0;
 angle=RandomBelow(0x4000)+0xc000;
 session=gNetSession;
 result=Gt2CreateSocket(gNetSession,gt2AddressToString(0,angle,0),M2C_FIELD(session,s32 *,NET_SESSION_RX_BUFFER),M2C_FIELD(session,s32 *,NET_SESSION_TX_BUFFER),Gt2SocketErrorCallback);
 if(ReportGt2SocketResult(result))return result;
 Gt2SocketSetConnectAttempt(M2C_FIELD(gNetSession,s32 *,NET_SESSION_SOCKET),HandleGt2ConnectAttempt);
 Gt2SocketSetUnrecognizedCallback(M2C_FIELD(gNetSession,s32 *,NET_SESSION_SOCKET),RouteIncomingGameSpyPacket);
 return result;
}

/* Search the game's 32 player connection slots for the one whose peer record has
 * id `peerId`, returning that connection slot, or NULL when there is no session or
 * no player matches. */
s32 FindPlayerConnection(s32 peerId) {
    void *gt2GetConnectionData();
    extern void *gNetSession;
    extern M2C_UNK gPlayerConnections;
    s32 i;
    if (gNetSession == NULL) return 0;
    for (i = 0; i < 32; i++) {
        if ((&gPlayerConnections)[i] != 0 && peerId == ((PlayerPeer *)gt2GetConnectionData((&gPlayerConnections)[i]))->peerId)
            return (&gPlayerConnections)[i];
    }
    return 0;
}

u8 GetConnectionPlayerId(void) {
    void *gt2GetConnectionData();
    return M2C_FIELD(gt2GetConnectionData(), u8 *, 1);
}

u8 GetCurrentConnectionIndex(void) {
    void *gt2GetConnectionData();
    return M2C_FIELD(gt2GetConnectionData(), u8 *, 0);
}

/* Return the first of the session's 32 player-connection slots that is empty, or
 * -1 when every slot is taken. */
s32 FindFreePlayerSlot(void) {
    extern M2C_UNK gPlayerConnections;
    s32 slot;
    for (slot = 0; slot < 32; slot++) {
        if ((&gPlayerConnections)[slot] == 0) return slot;
    }
    return -1;
}

/* Clears the session's player table: the 32 player connection slots and the 32
 * per-slot peer records. */
void ResetPlayerSlots(void) {
    void CpuFill(s32, void *, s32);
    extern M2C_UNK gPlayerConnections;
    extern M2C_UNK gPlayerPeers;
    CpuFill(0, &gPlayerConnections, 0x80);
    CpuFill(0, &gPlayerPeers, 0x100);
}

void *GetPlayerConnectionSlot(s32 arg0) {
    extern M2C_UNK gPlayerConnections;
    return &gPlayerConnections + arg0;
}

/* Returns the connection slot of the player whose GT2 socket id is `socketId`,
 * searching the first `playerCount` entries of the session's player table, or
 * NULL when no player matches. */
void *FindPlayerConnectionSlot(s32 socketId, s32 playerCount) {
    extern void *gNetSession;
    s32 FindPlayerConnection(s32);
    u8 GetCurrentConnectionIndex(void);
    void *GetPlayerConnectionSlot(s32);
    u8 index;
    for (index = 0; index < playerCount; index++) {
        if (socketId == ((u32 *)((u8 *)gNetSession + NET_SESSION_PLAYER_SOCKETS))[index]) {
            break;
        }
    }
    if (index >= playerCount) {
        return 0;
    }
    FindPlayerConnection(*((u8 *)gNetSession + NET_SESSION_PLAYER_IDS + index));
    return GetPlayerConnectionSlot(GetCurrentConnectionIndex());
}

void *GetPlayerPeer(s32 arg0) {
    extern M2C_UNK gPlayerPeers;
    return &gPlayerPeers + arg0 * 2;
}

/* Whether any of the 32 player connection slots holds a session with peer `peerId`. */
s32 HasPlayerConnection(s32 peerId) {
    void *gt2GetConnectionData(void *);
    extern M2C_UNK gPlayerConnections;
    s32 i;

    for (i = 0; i < 32; i++) {
        if ((&gPlayerConnections)[i] != 0) {
            if (((PlayerPeer *)gt2GetConnectionData((void *)(&gPlayerConnections)[i]))->peerId == peerId) {
                return 1;
            }
        }
    }
    return 0;
}

void func_02039200(void) {

}

void SetNetState(s32 arg0) {
    extern void *gNetSession;
    M2C_FIELD(gNetSession, s32 *, 0x28) = (s32) M2C_FIELD(gNetSession, s32 *, 0x24);
    M2C_FIELD(gNetSession, s32 *, 0x24) = arg0;
}

/* Remove the present peer whose slot id is slotId: find it in the connection's
 * peer slot list and drop that peer record, returning the removed peer's id
 * (0 when no present peer has that slot id). */
s32 RemovePeerBySlot(s32 slotId) {
    s32 RemoveConnectionPeer(s32,s32);
    s32 GetPeerSlotList(u8 **);
    u8 *peers,*cursor;
    s32 count,i;
    count=GetPeerSlotList(&peers);
    i=0;
    if(count>0) {
        cursor=peers;
        do {
            if(slotId==*cursor)break;
            i++;
            cursor++;
        }while(i<count);
    }
    if(i==count)return 0;
    return RemoveConnectionPeer(i,count);
}

/* Fold the `count` player ids in `playerIds` (each 0..31) into one mask with the
 * bit of every listed id set. */
u32 MaskPlayerIds(u8 *playerIds, s32 count) {
    u32 mask = 0;
    u32 i = 0;

    if (count > 0) {
        u32 bit = 1;
        do {
            mask |= bit << (u32)playerIds[i];
            i++;
        } while ((s32)i < count);
    }
    return mask;
}

/* Reports a failed network operation: translates the operation result `error`
 * into a WFC error code and detail, adjusts the detail for the current session
 * state, runs that state's handler and records the error globally.  Returns the
 * operation result. */
s32 ReportNetErrorForState(s32 error){
extern void *gNetSession;
u32 detail,errCode;
if(!error)return 0;
switch((u32)error){
case 1:errCode=9;detail=errCode-10;break;
case 2:errCode=9;detail=errCode-11;break;
case 3:errCode=6;detail=errCode-16;break;
case 4:errCode=6;detail=errCode-26;break;
}
switch(M2C_FIELD(gNetSession,u32 *,0x24)){
case 1:detail+=0xffff11b8;ReportNasLoginError(errCode,detail);break;
case 2:detail+=0xffff11b8;if(M2C_FIELD(gNetSession,s32 *,0x9c)<1)ReportNasLoginError(errCode,detail);break;
case 5:detail+=0xfffec398;ReportConnectionError(errCode,detail);break;
case 4:detail+=0xfffeeaa8;break;
default:detail+=0xfffe9c88;break;
}
ReportMatchSessionError(errCode,detail);return error;
}

/* Reports a GameSpy GT2 socket result: turns the result code into a network
 * error class and WFC error detail and hands them to the NAS login error path.
 * A result of 0 (success) or 2/5 (nothing to report) returns without reporting.
 * Returns the result code. */
u32 ReportGt2SocketResult(u32 result, u32 unused, u32 detail) {
    u32 ret = result;
    u32 errCode;
    errCode = ret;
    if (ret == 0) return 0;
    switch (ret) {
    case 1: errCode = 9; detail = errCode - 10; break;
    case 2:
    case 5: errCode = 0; detail = errCode; ret = errCode; break;
    case 3: errCode = 6; detail = errCode - 16; break;
    case 4: errCode = 6; detail = errCode - 36; break;
    case 6: errCode = 6; detail = errCode - 76; break;
    case 7: errCode = 6; detail = errCode - 86; break;
    }
    if (errCode) ReportNasLoginError(errCode, (s32)(detail + 0xFFFEFA48));
    return ret;
}

/* NAS login completion callback: on success record this console's profile id and
 * move the session into the lobby, otherwise mark it offline; then notify the
 * app's login callback with the result. */
void NasLoginResultCallback(s32 error, s32 profileId) {
    void SetNetState(s32);
    void MatchSession_ResetThinkTimer(void);
    extern void *gNetSession;
    if (error == 0) {
        M2C_FIELD(gNetSession, s32 *, NET_SESSION_LOCAL_SOCKET) = profileId;
        SetNetState(NET_STATE_READY);
        MatchSession_ResetThinkTimer();
    } else {
        SetNetState(NET_STATE_OFFLINE);
    }
    {
        void *session = gNetSession;
        void (*callback)(s32, s32, s32) = (void (*)(s32, s32, s32))M2C_FIELD(session, void **, NET_SESSION_LOGIN_CALLBACK);
        if (callback != NULL) {
            callback(error, profileId, M2C_FIELD(session, s32 *, NET_SESSION_LOGIN_DATA));
        }
    }
}

/* Hand a match-making event to the session's match callback (with its data),
 * first restoring the state the session was in before matchmaking began. */
void DispatchMatchSessionEvent(s32 event, s32 data) {
    extern void *gNetSession;
    void SetNetState(s32);
    s32 prevState = M2C_FIELD(gNetSession, s32 *, NET_SESSION_PREV_STATE);
    if (prevState != NET_STATE_MATCHMAKING) {
        SetNetState(prevState);
    }
    M2C_FIELD(gNetSession, void (**)(s32, s32, s32), NET_SESSION_MATCH_CALLBACK)(event, data, M2C_FIELD(gNetSession, s32 *, NET_SESSION_MATCH_DATA));
}

/* Match event callback installed with the connection layer: keeps the session
 * state and the connected-player mask in step with the event, then reports it to
 * the app's match callback (the wide six-argument one while the session serves the
 * match).  A clean close returns to the lobby, a start moves to the match and
 * records this console's own player id; an error only refreshes the players. */
void DispatchMatchEvent(s32 status, s32 closed, s32 targetCleared, s32 serving, M2C_UNK slot) {
    extern void *gNetSession;
    s32 ResetClientSession(void);
    void SetNetState(s32);
    u32 MaskPlayerIds(u8 *, s32);
    void UpdateConnectedPlayerCount(void);

    if (status == 0 && closed != 0) {
        if (M2C_FIELD(gNetSession, s32 *, 0x514) == 0) {
            ResetClientSession();
            SetNetState(NET_STATE_READY);
        }
        goto refreshPlayers;
    }
    if (status != 0) {
        goto refreshPlayers;
    }

    SetNetState(NET_STATE_MATCH);
    {
        void *session = gNetSession;
        s32 i;
        for (i = 0; i <= M2C_FIELD(session, volatile u8 *, NET_SESSION_LAST_PLAYER); i++) {
            if (M2C_FIELD(session, s32 *, NET_SESSION_LOCAL_SOCKET) == ((u32 *)((u8 *)session + NET_SESSION_PLAYER_SOCKETS))[i]) {
                M2C_FIELD(gNetSession, u8 *, NET_SESSION_LOCAL_PLAYER_ID) = M2C_FIELD((u8 *)gNetSession + i, u8 *, NET_SESSION_PLAYER_IDS);
                break;
            }
        }
    }

refreshPlayers:
    M2C_FIELD(gNetSession, u32 *, NET_SESSION_CONNECTED_MASK) =
        MaskPlayerIds((u8 *)gNetSession + NET_SESSION_PLAYER_IDS, M2C_FIELD(gNetSession, u8 *, NET_SESSION_LAST_PLAYER) + 1);
    UpdateConnectedPlayerCount();

    if (M2C_FIELD(gNetSession, u8 *, NET_SESSION_MODE) == 2 || M2C_FIELD(gNetSession, volatile u8 *, NET_SESSION_MODE) == 3) {
        ((void (*)(s32, s32, s32, s32, M2C_UNK, s32))M2C_FIELD(gNetSession, void **, NET_SESSION_EVENT_CALLBACK5))(
            status, closed, targetCleared, serving, slot, M2C_FIELD(gNetSession, s32 *, NET_SESSION_EVENT_DATA5));
    } else {
        ((void (*)(s32, s32, s32))M2C_FIELD(gNetSession, void **, NET_SESSION_EVENT_CALLBACK))(
            status, closed, M2C_FIELD(gNetSession, s32 *, NET_SESSION_EVENT_DATA));
    }

    if (status != 0 && gNetSession != 0) {
        if (M2C_FIELD(gNetSession, s32 *, NET_SESSION_STATE) == NET_STATE_STARTING) {
            SetNetState(NET_STATE_READY);
        }
    }
}

/* GameSpy gpi error callback (callback entry 0): the block at `error` holds the
 * result at +0, the connection's error code at +4, the connection at +8 and the
 * fatal flag at +0xC.  Report a generic network error (result 3) unless the code
 * is one of the three a routine peer/session disconnect reports. */
void HandleConnectionErrorCallback(s32 unused, void *error) {
    s32 ReportNetErrorForState(s32);
    s32 errorCode;

    errorCode = M2C_FIELD(error, s32 *, 4);
    if ((errorCode != 0x603) && (errorCode != 0x901) && (errorCode != 0xB01)) {
        ReportNetErrorForState(3);
    }
}

/* Handles the "GPCM<version>vMAT<...>" session info message: gives up on any
   other message, checks the version number is 3 and the MAT prefix, then hands
   the MAT payload to the command parser. */
void HandleGpcmMatMessage(s32 conn,void *info,s32 arg){
extern char sGpcmPrefix[],sMatPrefix[];extern void *gNetSession;
s32 HandleBuddyAddAuthorizedMessage(s32,void *,s32);u32 StringLength(const char *);s32 ByteCompareN(const void *,const void *,u32);char *StringFindChar(const char *,s32);void *StringCopyPad(void *,const void *,u32);s32 strtoul(const char *,void *,s32);
void HandleConnectionTextCommand(s32,s32,char *);
char versionText[12]={0};char *text=M2C_FIELD(info,char **,8);u32 len;
if(HandleBuddyAddAuthorizedMessage(conn,info,arg))return;
if(ByteCompareN(text,sGpcmPrefix,StringLength(sGpcmPrefix)))return;
text+=StringLength(sGpcmPrefix);
len=StringFindChar(text,'v')-text;
StringCopyPad(versionText,text,len);
if(len>10)return;
if(strtoul(versionText,0,10)!=3)return;
text+=len+1;
if(ByteCompareN(text,sMatPrefix,StringLength(sMatPrefix)))return;
if(M2C_FIELD(gNetSession,s32 *,0x24)!=5){
if(M2C_FIELD(gNetSession,s32 *,0x24)!=6)return;
if(M2C_FIELD(gNetSession,volatile u8 *,0x389)!=2&&M2C_FIELD(gNetSession,volatile u8 *,0x389)!=3)return;
}
HandleConnectionTextCommand(conn,M2C_FIELD(info,s32 *,0),text+StringLength(sMatPrefix));
}

void func_02039838(void) {
    M2C_UNK HandleTransferReceive();
    HandleTransferReceive();
}

void func_02039844(s32 arg0, s32 arg1) {
    extern void *gNetSession;
    extern M2C_UNK gPlayerConnections;
    extern u32 gEmptyString;

    s32 func_0203e558(void);
    void *gt2GetConnectionData();
    void ResetTransferSlot();
    s32 RemovePeerBySlot(s32);
    M2C_UNK func_0203dee8();
    void SetNetError(s32, s32);
    M2C_UNK ReportGpiSessionStatus();
    M2C_UNK func_0203e064();
    s32 RemoveConnectionPeer();
    M2C_UNK SetGpiStatus();
    M2C_UNK Qr2_StateChanged();
    M2C_UNK GetSessionPlayerSlot();
    M2C_UNK NatNeg_RequestShutdown();
    M2C_UNK ResetClientSession();
    void SetNetState(s32);

    s32 r8;
    s32 r10 = 0;
    s32 r5 = 0;
    s32 r6;
    u8 r4;
    s32 r7;
    s32 arg0v = arg0;
    s32 arg1v = arg1;

    if (func_0203e558() != 0) return;

    switch (arg1v) {
        case 0:
        case 1:
            r8 = r5;
            break;
        case 2:
        case 3:
            r8 = 6;
            r6 = (s32)0xffffe250;
            break;
        case 4:
            r6 = (s32)0xffffe24f;
            r8 = 9;
            break;
    }

    if (r8 == 0) {
        u8 *peer = gt2GetConnectionData(arg0v);
        if (peer == NULL) return;
        r4 = peer[1];
        {
            void *base = gNetSession;
            r7 = 1;
            if ((M2C_FIELD(base, u32 *, 0x664) & (1u << r4)) == 0) r7 = 0;
        }
        ResetTransferSlot(r4);
        {
            void *base = gNetSession;
            if ((M2C_FIELD(base, u8 *, 0x389) == (u8)2 && arg1v == 0) ||
                (M2C_FIELD(base, u8 *, 0x389) == (u8)3 && r4 == 0)) {
                r10 = 1;
            }
        }
        {
            s32 funcres = RemovePeerBySlot(r4);
            u8 idx = peer[0];
            (&gPlayerConnections)[idx] = 0;
            {
                void *base = gNetSession;
                u8 t = M2C_FIELD(base, u8 *, 0x381);
                M2C_FIELD(base, u8 *, 0x381) = (u8)(t - 1);
            }
            {
                void *base = gNetSession;
                u8 t = M2C_FIELD(base, u8 *, 0x388);
                M2C_FIELD(base, u8 *, 0x388) = (u8)(t - 1);
            }
            r5 = funcres;
            arg0v = 0;
        }
    }

    {
        void *base = gNetSession;
        if (M2C_FIELD(base, u8 *, 0x2d) == 0 &&
            M2C_FIELD(base, u32 *, 0x24) == 6 && r7 == 0) {
            u8 d389 = M2C_FIELD(base, u8 *, 0x389);
            if (d389 != 2 || r8 != 0) return;
            ReportGpiSessionStatus();
            func_0203e064(r5);
            return;
        }
    }

    if (func_0203dee8(r8, r6, r5) != 0) return;
    if (r8 != 0) {
        SetNetError(r8, (s32)(r6 + 0xfffec780));
        return;
    }

    {
        void *base = gNetSession;
        if (M2C_FIELD(base, u8 *, 0x2d) == 0) {
            if (M2C_FIELD(base, volatile u8 *, 0x389) == 2 || M2C_FIELD(base, volatile u8 *, 0x389) == 3) {
                void *b = *(void *volatile *)&gNetSession;
                u8 t = M2C_FIELD(b, u8 *, 0x381);
                s32 idx = (s32)t + 2;
                u32 val = *(u32 *)((u8 *)b + 0x468 + (s32)idx * 4);
                if (val != 0) {
                    u8 bb = *(u8 *)((u8 *)b + 0x644 + (s32)idx);
                    s32 next = t + 1;
                    M2C_FIELD((u8 *)b + next, u8 *, 0x644) = bb;
                    {
                        void *b2 = *(void *volatile *)&gNetSession;
                        u8 t3 = M2C_FIELD(b2, u8 *, 0x381);
                        RemoveConnectionPeer((s32)t3 + 1, (s32)t3 + 3);
                    }
                }
            }
        }
    }

    {
        void *base = gNetSession;
        u8 d389 = M2C_FIELD(base, u8 *, 0x389);
        if (d389 == 2) {
            if (M2C_FIELD(base, u8 *, 0x2d) == 0) {
                ReportGpiSessionStatus();
            } else {
                if (M2C_FIELD(base, u8 *, 0x381) == 0) {
                    SetGpiStatus(1, (s32)&gEmptyString, 0);
                }
            }
        } else {
            if (M2C_FIELD(base, u8 *, 0x381) == 0) {
                SetGpiStatus(1, (s32)&gEmptyString, 0);
            }
        }
    }

    {
        void *base = gNetSession;
        if (M2C_FIELD(base, volatile u8 *, 0x389) == 0 || M2C_FIELD(base, volatile u8 *, 0x389) == 1) {
            base = *(void *volatile *)&gNetSession;
            M2C_FIELD(base, u8 *, 0x38a) = M2C_FIELD(base, u8 *, 0x388);
            {
                void *base2 = gNetSession;
                Qr2_StateChanged(M2C_FIELD(base2, s32 *, 0x384));
            }
        }
    }

    {
        void *base = gNetSession;
        s32 ae;
        void (*cb)(s32, s32, s32, s32, s32, s32);
        if (M2C_FIELD(base, s32 *, 0x90) != 0 && r7 != 0) {
            if (arg1v == 0) r7 = 1; else r7 = 0;
            ae = GetSessionPlayerSlot(r5);
            cb = (void (*)(s32, s32, s32, s32, s32, s32))M2C_FIELD(gNetSession, void **, 0x90);
            cb(r8, r7, r10, r4, ae, M2C_FIELD(base, s32 *, 0x94));
        }
    }

    {
        void *base = gNetSession;
        if (M2C_FIELD(base, u8 *, 0x2d) == 0 && M2C_FIELD(base, u8 *, 0x389) == 2) {
            return;
        }
        if (M2C_FIELD(base, u8 *, 0x381) != 0) return;
        NatNeg_RequestShutdown();
        ResetClientSession();
        SetNetState(3);
        return;
    }
}

void func_02039b9c(void) {
    M2C_UNK ReportTransferError();
    ReportTransferError();
}

/* GT2 socket-error callback: on a socket error, record the socket layer's last
 * error on the session block, report the failure as a fatal WFC error and close
 * the session by clearing its GT2 socket. */
void Gt2SocketErrorCallback(s32 *gt2Socket) {
    extern void *gNetSession;
    void SetNetError(s32, s32);
    s32 GT2SocketHandle(s32 *);
    s32 ghiGetLastSocketError(void);

    (void)GT2SocketHandle(gt2Socket);
    M2C_FIELD(&gNetSession, s32 *, NET_SESSION_LAST_SOCKET_ERROR) = ghiGetLastSocketError();
    SetNetError(9, 0xfffe8515);
    M2C_FIELD(M2C_FIELD(&gNetSession, s32 *, 0), s32 *, NET_SESSION_SOCKET) = 0;
}

/* Clear the NAS login work area and install the parameters for the next request. */
void InitNasLoginContext(s32 context, s32 session, s32 gpiConnection, s32 gameId, s32 keyType,
                         s32 requestName, s32 resultCallback, s32 callbackArg) {
    extern M2C_UNK gNasLogin;
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);

    M2C_FIELD(&gNasLogin, s32 *, NAS_LOGIN_CONTEXT) = context;
    MI_CpuFill8(context, 0, NAS_LOGIN_CONTEXT_BYTES);
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->gpiConnection = gpiConnection;
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->state = NAS_STATE_IDLE;
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->gameId = gameId;
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->keyType = keyType;
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->requestName = requestName;
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->resultCallback = resultCallback;
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->callbackArg = callbackArg;
    M2C_FIELD(&gNasLogin, NasLoginParameters **, NAS_LOGIN_CONTEXT)->session = session;
}

/* Kick off the NAS login: send the request with its completion callback and
 * request kind 0, then mark the login context as awaiting the reply and clear the
 * pending gpi-connection flag. */
void StartNasLoginRequest(void) {
    void NasLoginRequestCallback(void);
    void StartNasRequest(void *, s32);
    extern M2C_UNK gNasLogin;

    StartNasRequest(NasLoginRequestCallback, 0);
    M2C_FIELD(M2C_FIELD(&gNasLogin, void **, NAS_LOGIN_CONTEXT), s32 *, NAS_LOGIN_STATE) = NAS_STATE_REQUESTING;
    M2C_FIELD(M2C_FIELD(&gNasLogin, void **, NAS_LOGIN_CONTEXT), s32 *, NAS_LOGIN_GPI_PENDING) = 0;
}

/* Tick the active online session: dispatch by its state (0 idle, 1 ?, 2-4 update
   peer, 5 idle). In 2-4, notify completion via gpiThinkConnection and, when a timeout
   (60000 units) elapses, report error 6 / -61070. */
void func_02039ca0(void) {
    extern M2C_UNK gNasLogin;
    s32 HasNetError(void);
    void func_0203a2b4(void);
    void gpiThinkConnection(void *);
    u64 GetSystemTick(void);
    u64 U64Divide(u64, u64);
    void *p;

    if (!M2C_FIELD(&gNasLogin, void **, 4)) return;
    if (HasNetError()) return;
    p = M2C_FIELD(&gNasLogin, void **, 4);
    switch (M2C_FIELD(p, u32 *, 4)) {
    case 0: break;
    case 1: func_0203a2b4(); return;
    case 2:
    case 3:
    case 4:
        p = M2C_FIELD(p, void **, 0);
        if (p && M2C_FIELD(p, s32 *, 0)) gpiThinkConnection(p);
        p = M2C_FIELD(&gNasLogin, void **, 4);
        if (!M2C_FIELD(p, s32 *, 0x30)) return;
        if (U64Divide((GetSystemTick() - M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), u64 *, 0x34)) << 6, 0x82eaULL) > 60000ULL) {
            ReportNasLoginError(6, -61070);
            M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 0x30) = 0;
        }
        return;
    case 5: break;
    default: break;
    }
}

s32 GetLocalPlayerInfo(void) {
    extern M2C_UNK gNasLogin;
    if (M2C_FIELD(&gNasLogin, void **, 4) != NULL) {
        return M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 0x1C);
    }
    return 0;
}

/* Report a failed NAS login: record the network error, hand it to the login's
 * result callback when one is installed, and reset the login state to idle.  Does
 * nothing when no login context exists or the error code is 0. */
s32 ReportNasLoginError(u32 errorCode, s32 detail) {
    extern M2C_UNK gNasLogin;
    void SetNetError(s32, s32);
    void ResetNasLoginState(void);
    void *context;
    context = (void *)M2C_FIELD(&gNasLogin, void **, NAS_LOGIN_CONTEXT);
    if (context == NULL || errorCode == 0) return;
    SetNetError(errorCode, detail);
    context = (void *)M2C_FIELD(&gNasLogin, void **, NAS_LOGIN_CONTEXT);
    if (M2C_FIELD(context, void (**)(s32, u8, s32), NAS_LOGIN_RESULT_CB) != NULL) {
        M2C_FIELD(context, void (**)(s32, u8, s32), NAS_LOGIN_RESULT_CB)(errorCode, 0, M2C_FIELD(context, s32 *, NAS_LOGIN_RESULT_ARG));
    }
    ResetNasLoginState();
}

#pragma push
#pragma opt_common_subs off
/* Tear down the NAS login: if its context still holds a connection block, abort the
 * NAS connection, release the HTTP client, free the block and clear it; then drop the
 * gNasLogin context pointer. */
void FreeNasLoginContext(void) {
    extern M2C_UNK gNasLogin;
    M2C_UNK HeapFree(s32, s32, s32);
    void NasAbort(void);
    void FreeNasConnection(void);

    if (M2C_FIELD(M2C_FIELD(&gNasLogin, s32 *, NAS_LOGIN_CONTEXT), s32 *, NAS_LOGIN_CONNECTION)) {
        NasAbort();
        FreeNasConnection();
        HeapFree(0, M2C_FIELD(M2C_FIELD(&gNasLogin, s32 *, NAS_LOGIN_CONTEXT), s32 *, NAS_LOGIN_CONNECTION), 0);
        M2C_FIELD(M2C_FIELD(&gNasLogin, s32 *, NAS_LOGIN_CONTEXT), s32 *, NAS_LOGIN_CONNECTION) = 0;
    }
    M2C_FIELD(&gNasLogin, s32 *, NAS_LOGIN_CONTEXT) = 0;
}
#pragma pop
void ResetNasLoginState(void) {
    extern M2C_UNK gNasLogin;
    M2C_UNK *p;
    p = (M2C_UNK *)M2C_FIELD(&gNasLogin, void **, 4);
    if (p == NULL) return;
    M2C_FIELD(p, s32 *, 4) = 0;
    p = (M2C_UNK *)M2C_FIELD(&gNasLogin, void **, 4);
    M2C_FIELD(p, s32 *, 0x30) = 0;
}

/* Reports a GameSpy Presence failure during NAS login and returns the original result. */
u32 ReportNasError(u32 result, u32 unused, u32 detailOffset) {
    u32 status = result;
    u32 errorCode;

    if (status == GP_NO_ERROR) return GP_NO_ERROR;

    switch (status) {
    case GP_MEMORY_ERROR:
        errorCode = 9;
        detailOffset = errorCode - 10;
        break;
    case GP_PARAMETER_ERROR:
        errorCode = 9;
        detailOffset = errorCode - 11;
        break;
    case GP_NETWORK_ERROR:
        errorCode = 6;
        detailOffset = errorCode - 16;
        break;
    case GP_SERVER_ERROR:
        errorCode = 6;
        detailOffset = errorCode - 26;
        break;
    }

    ReportNasLoginError(errorCode, detailOffset + NET_LOGIN_STATUS_DETAIL_BASE);
    return status;
}

