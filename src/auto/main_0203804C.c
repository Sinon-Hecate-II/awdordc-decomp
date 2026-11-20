/* 18 functions from 0x0203804C to 0x02038F88 (main), found by ds-decomp. */
#include "common.h"
#include "net_session.h"

/* Initialize the global WFC session object: install the state callbacks, set up its transport,
   upload and connection sub-objects from the NAS config, and copy the game name and password
   into their global buffers. */
void InitNetSession(void *session,void *config,s32 gameId,char *gameName,char *gamePassword,s32 rxBufSize,s32 txBufSize,s32 userData,s32 timeout){
extern void *gNetSession;
extern u8 gSessionGameName[];
extern u8 gSessionGamePassword[];
void ClearNetError(void);
void ResetPlayerSlots(void);
void func_0203d910(void);
void func_02039838(void);
void func_02039844(void);
void func_02039b9c(void);
void func_02039478(void);
void InitNasLoginContext(void *,void *,void *,s32,s32,void *,void *,s32);
void StartMatchSession(void *,void *,void *,s32,s32);
void InitConnection(void *,void *,void *,void *,void *,void *,s32,s32);
void func_02044708(void *);
u32 len;
gNetSession=session;
ClearNetError();
M2C_FIELD(gNetSession,s32 *,0)=0;
M2C_FIELD(gNetSession,s32 *,4)=(s32)func_0203d910;
M2C_FIELD(gNetSession,s32 *,8)=(s32)func_02039838;
M2C_FIELD(gNetSession,s32 *,12)=(s32)func_02039844;
M2C_FIELD(gNetSession,s32 *,16)=(s32)func_02039b9c;
M2C_FIELD(gNetSession,s32 *,20)=rxBufSize?rxBufSize:0x2000;
M2C_FIELD(gNetSession,s32 *,24)=txBufSize?txBufSize:0x2000;
M2C_FIELD(gNetSession,s32 *,28)=0;
M2C_FIELD(gNetSession,s32 *,32)=(s32)config;
M2C_FIELD(gNetSession,s32 *,36)=0;
M2C_FIELD(gNetSession,s32 *,40)=0;
M2C_FIELD(gNetSession,u8 *,44)=0;
M2C_FIELD(gNetSession,u8 *,45)=0;
M2C_FIELD(gNetSession,s32 *,100)=0;
M2C_FIELD(gNetSession,s32 *,104)=(s32)gSessionGameName;
M2C_FIELD(gNetSession,s32 *,108)=(s32)gSessionGamePassword;
M2C_FIELD(gNetSession,s32 *,112)=0;M2C_FIELD(gNetSession,s32 *,116)=0;M2C_FIELD(gNetSession,s32 *,120)=0;M2C_FIELD(gNetSession,s32 *,124)=0;M2C_FIELD(gNetSession,s32 *,128)=0;M2C_FIELD(gNetSession,s32 *,132)=0;M2C_FIELD(gNetSession,s32 *,136)=0;M2C_FIELD(gNetSession,s32 *,140)=0;M2C_FIELD(gNetSession,s32 *,144)=0;M2C_FIELD(gNetSession,s32 *,148)=0;
ResetPlayerSlots();
InitNasLoginContext((u8 *)gNetSession+0x98,config,(u8 *)gNetSession+0x1c,gameId,M2C_FIELD(config,s32 *,0x24),(u8 *)gNetSession+0x2e,func_02039478,0);
StartMatchSession((u8 *)gNetSession+0x318,(u8 *)gNetSession+0x1c,(u8 *)gNetSession+0x2e,userData,timeout);
InitConnection((u8 *)gNetSession+0x374,(u8 *)gNetSession+0x1c,gNetSession,(u8 *)gNetSession+4,gSessionGameName,gSessionGamePassword,userData,timeout);
func_02044708((u8 *)gNetSession+0x7f8);
if((u32)StringLength(gameName)>=0x100)len=255;else len=StringLength(gameName);
MI_CpuCopy8(gameName,gSessionGameName,len);
gSessionGameName[len]=0;
if((u32)StringLength(gamePassword)>=0x100)len=255;else len=StringLength(gamePassword);
MI_CpuCopy8(gamePassword,gSessionGamePassword,len);
gSessionGamePassword[len]=0;
}

void TeardownNetSession(void) {
    extern void *gNetSession;
    void Qr2_DestroyConnection(void *resource);
    void DestroyServerBrowser(void *resource);
    void func_0203bd0c(void);
    void gpiInfoCloseSocket(void);
    s32 func_0204db84(void *channel, s32 a, s32 b, s32 c);
    void func_0204db50(void *channel);
    void func_0204db34(void *channel);
    void func_02039e04(void);
    void func_0203b088(void);
    void func_0203e4e0(void);
    void func_020449dc(void);
    void func_0205ad60(void *resource);

    if (!gNetSession) return;
    if (M2C_FIELD(gNetSession, void **, 0x384)) {
        Qr2_DestroyConnection(M2C_FIELD(gNetSession, void **, 0x384));
        M2C_FIELD(gNetSession, void **, 0x384) = 0;
    }
    M2C_FIELD(gNetSession, u8 *, 0x38C) = 0;
    if (M2C_FIELD(gNetSession, void **, 0x458)) {
        DestroyServerBrowser(M2C_FIELD(gNetSession, void **, 0x458));
        M2C_FIELD(gNetSession, void **, 0x458) = 0;
    }
    func_0203bd0c();
    gpiInfoCloseSocket();
    if (M2C_FIELD(gNetSession, s32 *, 0x1C)) {
        func_0204db84(gNetSession + 0x1C, 0, 0, 0);
        func_0204db84(gNetSession + 0x1C, 3, 0, 0);
        func_0204db84(gNetSession + 0x1C, 1, 0, 0);
        func_0204db84(gNetSession + 0x1C, 2, 0, 0);
        func_0204db50(gNetSession + 0x1C);
        func_0204db34(gNetSession + 0x1C);
        M2C_FIELD(gNetSession, s32 *, 0x1C) = 0;
    }
    func_02039e04();
    func_0203b088();
    func_0203e4e0();
    func_020449dc();
    if (M2C_FIELD(gNetSession, void **, 0)) {
        func_0205ad60(M2C_FIELD(gNetSession, void **, 0));
        M2C_FIELD(gNetSession, void **, 0) = 0;
    }
    gNetSession = 0;
}

/* Advances the online connection state, installs callbacks after the availability check, and releases deferred network resources. */
void TickNetSession(void) {
    extern void *gNetSession;
    extern M2C_UNK func_02039698;
    extern M2C_UNK HandleGpcmMatMessage;
    extern M2C_UNK func_0203ad24;
    extern M2C_UNK MatchSession_ReportBuddyStatus;
    s32 func_02037bc4(void);
    void func_02039200(void);
    s32 HasNetError(void);
    s32 func_0204837c(void);
    s32 ReportNetErrorForState(s32);
    void SetNetState(s32);
    void func_02039c68(void);
    void func_02039ca0(void);
    void ReportNasLoginError(s32, s32);
    void func_0203aabc(void);
    void func_0203cb38(s32);
    void UpdateTransferSlots(void);
    s32 func_0204db04(s32, s32, s32);
    s32 func_0204db84(void *, s32, s32, s32);
    void Qr2_DestroyConnection(void *);

    if (func_02037bc4()) func_02039200();
    if (!gNetSession || M2C_FIELD(gNetSession, s32 *, 0x24) == 0) return;
    if (HasNetError() != 0) return;
    switch (M2C_FIELD(gNetSession, s32 *, 0x24)) {
    case 1:
        switch (func_0204837c()) {
        case 1:
            if (ReportNetErrorForState(func_0204db04((s32)gNetSession + 0x1c, M2C_FIELD(gNetSession, s32 *, 0xa0), 0))) return;
            if (ReportNetErrorForState(func_0204db84((u8 *)gNetSession + 0x1c, 0, (s32)&func_02039698, 0))) return;
            if (ReportNetErrorForState(func_0204db84((u8 *)gNetSession + 0x1c, 3, (s32)&HandleGpcmMatMessage, 0))) return;
            if (ReportNetErrorForState(func_0204db84((u8 *)gNetSession + 0x1c, 1, (s32)&func_0203ad24, 0))) return;
            if (ReportNetErrorForState(func_0204db84((u8 *)gNetSession + 0x1c, 2, (s32)&MatchSession_ReportBuddyStatus, 0))) return;
            SetNetState(2);
            func_02039c68();
            break;
        case 2:
            ReportNasLoginError(3, -0x4e8e);
            return;
        case 3:
            ReportNasLoginError(4, -0x4e85);
            return;
        }
        break;
    case 2:
        func_02039ca0();
        break;
    case 3:
    case 4:
        func_0203aabc();
        func_0203cb38(0);
        break;
    case 5:
        func_0203cb38(1);
        func_0203aabc();
        break;
    case 6:
        UpdateTransferSlots();
        func_0203aabc();
        if (M2C_FIELD(gNetSession, volatile u8 *, 0x389) == 2 || M2C_FIELD(gNetSession, volatile u8 *, 0x389) == 3) func_0203cb38(1);
        else if (M2C_FIELD(gNetSession, s32 *, 0) != 0) func_0203cb38(0);
        break;
    }
    if (M2C_FIELD(gNetSession, u8 *, 0x38c) == 1) {
        if (M2C_FIELD(gNetSession, s32 *, 0x384) != 0) {
            Qr2_DestroyConnection(M2C_FIELD(gNetSession, s32 *, 0x384));
            M2C_FIELD(gNetSession, s32 *, 0x384) = 0;
        }
        M2C_FIELD(gNetSession, u8 *, 0x38c) = 0;
    }
}

/* Start asynchronous login with a bounded UTF-16 name and a completion callback. */
s32 StartNetLogin(u16 *playerName, s32 unused, s32 loginCallback, s32 callbackData) {
    extern void *gNetSession;
    s32 HasNetError(void);
    u32 Utf16StringLength(u16 *);
    void FillU16(s32, void *, s32);
    void CopyU16(void *, void *, s32);
    s32 GetNetConnectionStatus(void);
    void ReportNasLoginError(s32, s32);
    void SetNetState(s32);
    void InitServiceAvailabilityQuery(s32);
    u32 nameLength;

    if (!playerName) return 0;
    if (HasNetError() || M2C_FIELD(gNetSession, s32 *, NET_SESSION_STATE) != NET_STATE_OFFLINE) return 0;
    M2C_FIELD(gNetSession, s32 *, NET_SESSION_LOGIN_CALLBACK) = loginCallback;
    M2C_FIELD(gNetSession, s32 *, NET_SESSION_LOGIN_DATA) = callbackData;
    if (!playerName || !*playerName) nameLength = 0;
    else {
        FillU16(0, (u8 *)gNetSession + NET_SESSION_LOGIN_NAME, NET_LOGIN_NAME_BYTES);
        if (Utf16StringLength(playerName) > NET_LOGIN_NAME_MAX) nameLength = NET_LOGIN_NAME_MAX;
        else nameLength = Utf16StringLength(playerName);
        CopyU16(playerName, (u8 *)gNetSession + NET_SESSION_LOGIN_NAME, nameLength * 2);
    }
    M2C_FIELD((u8 *)gNetSession + nameLength * 2, u16 *, NET_SESSION_LOGIN_NAME) = 0;
    if (GetNetConnectionStatus() != NET_CONNECTION_CONNECTED) {
        ReportNasLoginError(2, NET_LOGIN_ERROR_CONNECTION);
        return 1;
    }
    SetNetState(NET_STATE_CHECKING_SERVICE);
    InitServiceAvailabilityQuery(M2C_FIELD(gNetSession, s32 *, NET_SESSION_GAME_NAME));
    return 1;
}

/* Starts the WFC match-making session, but only from an allowed state (the session
 * must not be offline, logging in or already matchmaking): stores the app's match
 * event callback and its data, switches the session to NET_STATE_MATCHMAKING, then
 * starts the match session with the info and stats callbacks.  Returns 0 when the
 * session is in no state that allows it. */
s32 StartMatchMaking(s32 unused,s32 matchCallback,s32 matchData,s32 infoCallback,s32 infoData,s32 statsCallback,s32 statsData){
s32 HasNetError(void);void SetNetState(s32);
void MatchSession_Start(void *,void *,void *,s32,s32,s32,s32,s32);
extern M2C_UNK DispatchMatchSessionEvent;extern void *gNetSession;s32 state;
if(HasNetError() || (state=M2C_FIELD(gNetSession,s32 *,NET_SESSION_STATE))<NET_STATE_READY || state==NET_STATE_MATCHMAKING)return 0;
M2C_FIELD(gNetSession,s32 *,NET_SESSION_MATCH_CALLBACK)=matchCallback;
M2C_FIELD(gNetSession,s32 *,NET_SESSION_MATCH_DATA)=matchData;
SetNetState(NET_STATE_MATCHMAKING);
MatchSession_Start(gNetSession+224,gNetSession+480,&DispatchMatchSessionEvent,0,infoCallback,infoData,statsCallback,statsData);
return 1;
}

/* Hosts a Wi-Fi match: only from the idle lobby state, clears the player slots,
 * stores the app's match event callback and its data, moves the session to the
 * starting state and hands hosting over to the connection layer.  Returns 0 when
 * the session is in no state that allows it. */
s32 StartHostingMatch(s32 matchType,s32 playerList,s32 eventCallback,s32 eventData,s32 resultCallback,s32 resultData){s32 HasNetError(void);void ResetPlayerSlots(void);void SetNetState(s32);void StartHostMatch(s32,s32,void *,s32,s32,s32);extern M2C_UNK DispatchMatchEvent;extern void *gNetSession;if(HasNetError() || M2C_FIELD(gNetSession,s32 *,NET_SESSION_STATE)!=NET_STATE_READY)return 0;ResetPlayerSlots();M2C_FIELD(gNetSession,s32 *,NET_SESSION_EVENT_CALLBACK)=eventCallback;M2C_FIELD(gNetSession,s32 *,NET_SESSION_EVENT_DATA)=eventData;SetNetState(NET_STATE_STARTING);StartHostMatch((u8)(matchType-1),playerList,&DispatchMatchEvent,0,resultCallback,resultData);return 1;}

/* Prepares the online session to join a match (it must be idle in the lobby),
   stores the event callback, and starts the join: with the supplied player list
   if there is one, otherwise with a shuffled list of every player slot. */
s32 func_020388d8(s32 playerList, s32 listLength, s32 matchType, s32 flag, s32 eventCallback, s32 eventData, s32 resultCallback, s32 resultData) {
    s32 HasNetError(void); void ResetPlayerSlots(void); void SetNetState(s32);
    s32 func_0203ae50(void); u32 RandomBelow(u32);
    void StartJoinMatch(s32,s32,u8,s32,void *,s32,s32,s32);
    extern void *gNetSession; extern M2C_UNK DispatchMatchEvent;
    u8 shuffledSlots[64]; u8 slotPool[64];
    if (HasNetError() != 0 || M2C_FIELD(gNetSession,s32 *,0x24) != NET_STATE_READY) return 0;
    ResetPlayerSlots();
    M2C_FIELD(gNetSession,s32 *,0x80)=eventCallback;
    M2C_FIELD(gNetSession,s32 *,0x84)=eventData;
    SetNetState(NET_STATE_STARTING);
    if(playerList != 0) {
        StartJoinMatch(playerList,listLength,(u8)(matchType-1),flag,&DispatchMatchEvent,0,resultCallback,resultData);
    } else {
        u32 pick; u8 *shift; s32 slot, out;
        listLength=0; slot=listLength;
        while(slot<func_0203ae50()) { slotPool[slot]=(u8)slot; slot=(slot+1)&255; }
        out=0;
        while(out<func_0203ae50()) {
            pick=RandomBelow(func_0203ae50()-out);
            shuffledSlots[out]=slotPool[pick]; shift=&slotPool[pick]; listLength++;
            while(pick<func_0203ae50()-out-1) { *shift=shift[1]; shift++; pick++; }
            out=(out+1)&255;
        }
        StartJoinMatch((s32)shuffledSlots,listLength,(u8)(matchType-1),flag,&DispatchMatchEvent,0,resultCallback,resultData);
    }
    return 1;
}

/* Serves a match to other consoles: from the idle lobby, clears the player
 * slots, installs the wide (6-argument) match event callback and its data, makes
 * this console player 0, moves the session to the starting state and hands the
 * session to the connection layer with the peer callback and its data.
 * Returns 0 when the session is in no state that allows it. */
s32 StartServingMatchSession(s32 matchType, s32 eventCallback, s32 eventData, s32 peerCallback, s32 peerCallbackData) {
    s32 HasNetError(void);
    void ResetPlayerSlots(void);
    void SetNetState(s32);
    void StartServingMatch(s32, void *, s32, s32, s32);
    extern M2C_UNK DispatchMatchEvent;
    extern void *gNetSession;

    if (HasNetError() || M2C_FIELD(gNetSession, s32 *, NET_SESSION_STATE) != NET_STATE_READY) return 0;
    ResetPlayerSlots();
    M2C_FIELD(gNetSession, s32 *, NET_SESSION_EVENT_CALLBACK5) = eventCallback;
    M2C_FIELD(gNetSession, s32 *, NET_SESSION_EVENT_DATA5) = eventData;
    M2C_FIELD(gNetSession, u8 *, NET_SESSION_LOCAL_PLAYER_ID) = 0;
    SetNetState(NET_STATE_STARTING);
    StartServingMatch((u8)(matchType - 1), &DispatchMatchEvent, 0, peerCallback, peerCallbackData);
    return 1;
}

/* Looks up the local player's match record, verifies its SCM and SCN fields,
   then either starts the online match or reports the failure through the
   event callback and the global network error record. */
s32 StartMatch(s32 playerSlot, s32 eventCallback, s32 eventData, s32 mode, s32 matchData) {
    s32 HasNetError(void);
    void ResetPlayerSlots(void);
    void SetNetState(s32);
    s32 GetSessionPlayerId(s32);
    s32 HasBuddyProfile(void **, s32);
    s32 func_0204e2f4(void **, s32, s32 *);
    s32 gpGetBuddyStatus(void **, s32, void *);
    s32 ExtractKeyValue(s8 *, s8 *, s8 *, s32);
    s32 strtoul(s8 *, s32, s32);
    void StartMatchWithPlayer(s32, M2C_UNK, M2C_UNK, s32, s32);
    void SetNetError(s32, s32);
    void SetGpiStatus(s32, void *, s32);
    extern void *gNetSession;
    extern M2C_UNK gKeySCM;
    extern M2C_UNK gKeySCN;
    extern M2C_UNK gEmptyString;
    extern M2C_UNK DispatchMatchEvent;

    s32 status = mode;
    MatchPlayerInfo player;
    s32 playerIndex = -1;
    u8 valueText;
    u8 scmValue;
    u8 scnValue;
    s32 playerId;

    if (HasNetError() != 0 || M2C_FIELD(gNetSession, s32 *, 0x24) != NET_STATE_READY) return 0;

    ResetPlayerSlots();
    M2C_FIELD(gNetSession, s32 *, 0x88) = eventCallback;
    M2C_FIELD(gNetSession, s32 *, 0x8C) = eventData;
    SetNetState(NET_STATE_STARTING);

    playerId = GetSessionPlayerId(playerSlot);
    if (playerId == 0 || HasBuddyProfile((void **)((char *)gNetSession + 0x1C), playerId) == 0) {
        status = 0x0B;
        goto tail;
    }

    func_0204e2f4((void **)((char *)gNetSession + 0x1C), playerId, &playerIndex);
    gpGetBuddyStatus((void **)((char *)gNetSession + 0x1C), playerIndex, &player);

    if (player.status != 6) {
        status = 0x0B;
        goto tail;
    }

    valueText = 0x30;
    ExtractKeyValue(&gKeySCM, (s8 *)&valueText, (s8 *)player.fields, 0x2F);
    scmValue = (u8)strtoul((s8 *)&valueText, 0, 10);

    ExtractKeyValue(&gKeySCN, (s8 *)&valueText, (s8 *)player.fields, 0x2F);
    scnValue = (u8)strtoul((s8 *)&valueText, 0, 10);
    if (scnValue == scmValue) {
        status = 0x0D;
        goto tail;
    }

    StartMatchWithPlayer(playerId, &DispatchMatchEvent, 0, status, matchData);
    return 1;

tail:
    SetNetError(status, 0);
    {
        void *session = gNetSession;
        void *notify = *(void **)((char *)session + 0x88);
        ((void (*)(s32, s32, s32, s32, s32, s32))notify)(status, 0, 1, 0, 0, *(s32 *)((char *)session + 0x8C));
    }
    if (gNetSession != 0) {
        if (M2C_FIELD(gNetSession, s32 *, 0x24) == NET_STATE_STARTING) {
            SetNetState(NET_STATE_READY);
            SetGpiStatus(1, &gEmptyString, 0);
        }
    }
    return 1;
}

s32 func_02038d14(s32 a,s32 b){extern void *gNetSession;if(!gNetSession)return 0;M2C_FIELD(gNetSession,s32 *,144)=a;M2C_FIELD(gNetSession,s32 *,148)=b;return 1;}

/* Leaves the online match and returns the session to the lobby.  With no other
   player left in the session, reset the GameSpy status and close the connection
   manager at once; with players still in it, announce that the GT2 connection
   was closed so their disconnect handling brings the session down.  The
   announcement flag keeps those handlers from reporting it as an error.
   Returns -1 when no match is being set up or running. */
s32 LeaveNetMatch(void) {
    extern void *gNetSession;
    extern M2C_UNK gEmptyString;
    s32 HasNetError(void);
    void SetGpiStatus(s32, void *, s32);
    void func_0203bd0c(void);
    void SetNetState(s32);
    void GT2NotifyConnectionClosed(void *);
    s32 state;

    if (!gNetSession || HasNetError() ||
        ((state = M2C_FIELD(gNetSession, s32 *, NET_SESSION_STATE)) != NET_STATE_STARTING && state != NET_STATE_MATCH))
        return -1;
    if (M2C_FIELD(gNetSession, u8 *, NET_SESSION_LAST_PLAYER) == 0) {
        SetGpiStatus(1, &gEmptyString, 0);
        func_0203bd0c();
        SetNetState(NET_STATE_READY);
        return 1;
    }
    M2C_FIELD(gNetSession, u8 *, NET_SESSION_ANNOUNCING_CLOSE) = 1;
    GT2NotifyConnectionClosed(M2C_FIELD(gNetSession, void **, NET_SESSION_SOCKET));
    M2C_FIELD(gNetSession, u8 *, NET_SESSION_ANNOUNCING_CLOSE) = 0;
    return 0;
}

s32 DisconnectPeerSlot(s32 a){extern void *gNetSession;s32 HasNetError(void);void *FindPlayerConnection(s32);void GT2FailConnectionAttempt(void *);s32 state;void *p;if(!gNetSession || HasNetError() || ((state=M2C_FIELD(gNetSession,s32 *,0x24))!=5 && state!=6))return -1;p=FindPlayerConnection(a);if(!p)return -2;GT2FailConnectionAttempt(p);return 0;}

s32 func_02038e4c(void){extern void *gNetSession;s32 func_0203e2c4(void);s32 func_0203e2a4(void);if(!gNetSession)return 0;if(M2C_FIELD(gNetSession,volatile u8 *,0x389)==2 || M2C_FIELD(gNetSession,volatile u8 *,0x389)==3)return func_0203e2c4()+1;return func_0203e2a4()+1;}

u8 GetLocalPlayerId(void) {
    extern void *gNetSession;
    if (gNetSession != NULL) {
        return M2C_FIELD(gNetSession, u8 *, 0x2C);
    }
    return 0U;
}

s32 GetActiveConnectionList(s32 *a){extern void *gNetSession;s32 GetActivePlayerSlots(s32 *);s32 func_0203e338(s32 *);if(!gNetSession)return 0;*a=(s32)(gNetSession+0x644);if(M2C_FIELD(gNetSession,volatile u8 *,0x389)==2 || M2C_FIELD(gNetSession,volatile u8 *,0x389)==3)return GetActivePlayerSlots(a);return func_0203e338(a);}

s32 func_02038f00(void){extern void *gNetSession;s32 GetActiveConnectionList(s32 *);s32 func_02039284(s32,s32);s32 a,b;if(!gNetSession)return 0;b=GetActiveConnectionList(&a);return func_02039284(a,b);}

s32 IsConnectionActive(s32 a){extern void *gNetSession;s32 HasPlayerConnection(s32);if(!gNetSession)return 0;if(!(M2C_FIELD(gNetSession,u32 *,0x664)&(1<<a)))return 0;return HasPlayerConnection(a);}

s32 GetNetSessionState(void) {
    extern void *gNetSession;
    if (gNetSession != NULL) {
        return M2C_FIELD(gNetSession, s32 *, 0x24);
    }
    return 0;
}

