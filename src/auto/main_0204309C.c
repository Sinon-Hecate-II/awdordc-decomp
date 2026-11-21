/* 18 functions from 0x0204309C to 0x02043E10 (main), found by ds-decomp. */
#include "common.h"
#include "net_session.h"
#include "qr2.h"
#include "sb_serverlist.h"

/* Report a QR2 operation's result to whichever online subsystem owns the
 * session (NAS login, matchmaking or the live session), each with its own
 * detail offset, and pass the result back. */
s32 ReportQr2Error(u32 result){
s32 GetNetSessionState(void);
u32 detail,code;
if(result==0)return 0;
switch(result){
case 1:code=6;detail=code-56;break;
case 2:code=6;detail=code-66;break;
case 3:code=6;detail=code-36;break;
case 4:code=6;detail=code-86;break;
case 5:code=6;detail=code-26;break;
}
switch(GetNetSessionState()){
case NET_STATE_LOGIN:ReportNasLoginError(code,detail-0xfa00);break;
case NET_STATE_MATCHMAKING:ReportMatchSessionError(code,detail+0xfffedef0);break;
case NET_STATE_SESSION:ReportConnectionError(code,detail+0xfffeb7e0);break;
default:SetNetError(code,detail+0xfffe90d0);break;
}
return result;
}

s32 ReportPeerConnectResult(s32 a,s32 unused,s32 off) {
s32 code=a;
if(a==0)return 0;
switch(a){
case 1:code=9;off=code-10;break;
case 2:code=6;off=code-56;break;
case 3:code=6;off=code-36;break;
}
ReportConnectionError(code,off+0xfffeb010);
return a;
}

#pragma opt_propagation off
s32 func_020431e0(s32 a) {
s32 code;
if(a==0)return 0;
switch(a){
case 1:return 1;
case 2:return 2;
default:code=6;break;
}
if(code)ReportConnectionError(code,0xfffeb007);
return a;
}
#pragma opt_propagation reset
/* Reports a GameSpy GT2 result: turns the result code into a network error class
 * and WFC error detail and hands them to the connection error path.  A result of
 * 0 (success) or 2/5 (nothing to report) returns without reporting.  Returns the
 * result code. */
u32 ReportGt2ConnectResult(u32 result,u32 unused,u32 detail) {
u32 ret=result;
u32 errCode;
errCode=ret;
if(ret==0)return 0;
switch(ret){
case 1:errCode=9;detail=errCode-10;break;
case 2:case 5:errCode=0;detail=errCode;ret=errCode;break;
case 3:errCode=6;detail=errCode-16;break;
case 4:errCode=6;detail=errCode-36;break;
case 6:errCode=6;detail=errCode-76;break;
case 7:errCode=6;detail=errCode-86;break;
}
if(errCode)ReportConnectionError(errCode,detail+0xfffeac28);
return ret;
}

#pragma opt_propagation off
/* Server-browser callback: on a browsed-server event it arms the browse deadline
 * (a server was added, or an unknown event), and once the browser disconnects it
 * acts on the list collected for the match-making state: it drops unusable
 * records, then for a host or a searching client evaluates, prunes and picks
 * sessions, joins the chosen host or arms the retry timer for a later scan. */
void HandleServerListEvent(s32 list, s32 event, s32 server) {
    void *GetConnection(void);
    s32 SBServerListGetCount();
    s32 SBServerListGetServer();
    void SBServerListRemoveServer();
    s32 GetBrowsedServerPid();
    s32 SBServerGetIp();
    s32 SBServerGetPort();
    s32 SetConnectionState();
    void func_020436d8();
    s32 EvaluateMatchmakingSessions();
    s32 SelectMatchmakingSession();
    s32 SBServerGetIntValue();
    u64 GetSystemTick(void);
    void DisconnectAllPeers();
    s32 ReportConnectionCommandResult();
    void SendJoinRequest();
    void func_02040dc8();
    void TryConnectToPeer();
    s32 func_0203ecb0();
    void SendMatchmakingParameter();
    void ReportMatchmakingResult();
    s32 ReportPeerConnectResult();

    extern M2C_UNK gConnectionMgr;
    extern char sDwcKeyPid[];

    void *conn;
    s32 index;
    s32 count;
    s32 state;
    void *browsed;
    s32 browsedIp;
    s32 browsedPort;
    s32 browsedPid;

    s32 depth = M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_BROWSER_DEPTH);
    M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_BROWSER_DEPTH) = depth + 1;

    switch (event) {
    case SB_LIST_EVENT_SERVER_ADDED:
        func_020436d8(server);
        conn = GetConnection();
        M2C_FIELD(conn, u64 *, CONN_SESSION_BROWSE_DEADLINE) = GetSystemTick() + CONN_BROWSE_TIMEOUT_TICKS;
        break;
    case SB_LIST_EVENT_DISCONNECTED:
        conn = GetConnection();
        index = 0;
        M2C_FIELD(conn, s32 *, CONN_SESSION_BROWSE_DEADLINE) = 0;
        M2C_FIELD(conn, s32 *, CONN_SESSION_BROWSE_DEADLINE + 4) = 0;

        count = SBServerListGetCount(list);
        while (index < count) {
            browsed = (void *)SBServerListGetServer(list, index);
            /* The record is still in r0 here, so the check reads it as its argument. */
            if (GetBrowsedServerPid() == 0) {
                SBServerListRemoveServer(list, browsed);
                index--;
            }
            index++;
            count = SBServerListGetCount(list);
        }

        conn = GetConnection();
        state = M2C_FIELD(conn, s32 *, CONN_SESSION_STATE);

        switch (state) {
        case CONN_STATE_HOST_WAITING:
            index = 0;
            count = SBServerListGetCount(list);
            while (index < count) {
                browsed = (void *)SBServerListGetServer(list, index);
                if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_PUBLIC_IP) != 0) {
                    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_PUBLIC_IP) == SBServerGetIp(browsed)) {
                        if (M2C_FIELD(GetConnection(), u16 *, CONN_SESSION_PUBLIC_PORT) != 0) {
                            if (M2C_FIELD(GetConnection(), u16 *, CONN_SESSION_PUBLIC_PORT) == SBServerGetPort(browsed)) {
                                goto host_target_found;
                            }
                        }
                    }
                }
                index++;
                count = SBServerListGetCount(list);
            }
host_target_found:
            count = SBServerListGetCount(list);
            if (index < count) {
                SetConnectionState(CONN_STATE_SEARCHING);
                conn = GetConnection();
                M2C_FIELD(conn, s32 *, CONN_SESSION_JOIN_PEER) = 0;
                conn = GetConnection();
                SendMatchmakingParameter(M2C_FIELD(conn, u32 *, CONN_SESSION_JOIN_PEER));
                ReportMatchmakingResult();
            } else {
                conn = GetConnection();
                M2C_FIELD(conn, s32 *, CONN_SESSION_BROWSE_RETRY) = 2;
                conn = GetConnection();
                M2C_FIELD(conn, u64 *, CONN_SESSION_BROWSE_RETRY_TICK) = GetSystemTick();
            }
            break;
        case CONN_STATE_SEARCHING:
            EvaluateMatchmakingSessions(1);
            SelectMatchmakingSession();
            if (SBServerListGetCount(list) != 0) {
                SendJoinRequest(0, 0);
                if (ReportConnectionCommandResult() != 0) goto cleanup;
                SetConnectionState(CONN_STATE_JOINING);
                M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_BROWSE_RETRY) = 0;
                goto cleanup;
            }
            conn = GetConnection();
            M2C_FIELD(conn, s32 *, CONN_SESSION_BROWSE_RETRY) = 2;
            conn = GetConnection();
            M2C_FIELD(conn, u64 *, CONN_SESSION_BROWSE_RETRY_TICK) = GetSystemTick();
            break;
        case CONN_STATE_JOINED:
            if (SBServerListGetCount(list) != 0) {
                s32 first = 0;
                do {
                    browsed = (void *)SBServerListGetServer(list, first);
                    browsedIp = SBServerGetIp(browsed);
                    conn = GetConnection();
                    if (browsedIp == M2C_FIELD(conn, s32 *, CONN_SESSION_TARGET_ADDRESS)) {
                        browsedPort = SBServerGetPort(browsed);
                        conn = GetConnection();
                        if (browsedPort == (s32)M2C_FIELD(conn, u16 *, CONN_SESSION_TARGET_PORT)) break;
                    }
                    SBServerListRemoveServer(list, browsed);
                } while (SBServerListGetCount(list) != 0);
            }

            count = SBServerListGetCount(list);
            if (count != 0) {
                browsed = (void *)SBServerListGetServer(list, 0);
                browsedPid = SBServerGetIntValue(browsed, sDwcKeyPid, 0);
                if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 1 && browsedPid == M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_PEER_IDS)) {
                    if (EvaluateMatchmakingSessions(0) != 0) {
                        conn = GetConnection();
                        if (M2C_FIELD(conn, u8 *, CONN_SESSION_PLAYER_COUNT) != 0) {
                            DisconnectAllPeers();
                            if (ReportConnectionCommandResult() == 0) goto use_server;
                            goto cleanup;
                        }
                    } else {
                        conn = GetConnection();
                        func_02040dc8((void *)M2C_FIELD(conn, s32 *, CONN_SESSION_PEER_IDS));
                        if (ReportConnectionCommandResult() != 0) goto cleanup;
                        SetConnectionState(CONN_STATE_JOINING);
                        conn = GetConnection();
                        TryConnectToPeer(0, 0, M2C_FIELD(conn, s32 *, CONN_SESSION_PEER_IDS));
                        if (ReportConnectionCommandResult() != 0) goto cleanup;
                        goto cleanup;
                    }
                }
use_server:
                SetConnectionState(CONN_STATE_CONNECTING);
                browsed = (void *)SBServerListGetServer(list, 0);
                ReportPeerConnectResult(func_0203ecb0(0, 0, (s32)browsed));
                goto cleanup;
            }
            conn = GetConnection();
            M2C_FIELD(conn, s32 *, CONN_SESSION_BROWSE_RETRY) = 2;
            conn = GetConnection();
            M2C_FIELD(conn, u64 *, CONN_SESSION_BROWSE_RETRY_TICK) = GetSystemTick();
            break;
        default:
            conn = GetConnection();
            M2C_FIELD(conn, u64 *, CONN_SESSION_BROWSE_DEADLINE) = GetSystemTick() + CONN_BROWSE_TIMEOUT_TICKS;
            break;
        }
        break;
    case SB_LIST_EVENT_QUERY_ERROR:
        break;
    }

cleanup:
    depth = M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_BROWSER_DEPTH);
    M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_BROWSER_DEPTH) = depth - 1;
}
#pragma opt_propagation reset
void func_020436d8(void) {

}

#pragma opt_strength_reduction off
/* Score the browsed matchmaking sessions: drop sessions whose host pid is one of
 * our own players (unless in mode 1), run each remaining session through the
 * matchmaking weight callback, drop non-positive scores, store dwc_eval (random
 * tie-breaker in the low byte, score in the upper bits) and optionally sort the
 * list by dwc_eval. Returns 0 when the callback removed every session. */
s32 EvaluateMatchmakingSessions(s32 sort) {
 void *GetConnection(void);s32 SBServerListGetCount(s32);s32 SBServerListGetServer(s32,s32);s32 SBServerGetIntValue(void *,void *,s32);s32 gpiPlayerSetInt(void *,void *,s32);s32 SBServerListSort(s32,s32,void *,s32);s32 RandomBelow(s32);void SBServerListRemoveServer(s32,void *);
 extern char sDwcKeyPid[],sDwcKeyEval[];
 s32 removed=0; s32 isLocal,score;void *session; s32 pid; s32 i=0; s32 slot;void *server;
 for(;i<SBServerListGetCount(M2C_FIELD(GetConnection(),s32 *,0xe4));i++) {
 server=(void *)SBServerListGetServer(M2C_FIELD(GetConnection(),s32 *,0xe4),i);
 if(M2C_FIELD(GetConnection(),u8 *,0x15)==0) {
 pid=SBServerGetIntValue(server,sDwcKeyPid,0);isLocal=0;
 for(slot=1;slot<=M2C_FIELD(GetConnection(),u8 *,0xd);slot++) {
 if(pid==M2C_FIELD((u8 *)GetConnection()+slot*4,s32 *,0xf4)) {
 SBServerListRemoveServer(M2C_FIELD(GetConnection(),s32 *,0xe4),server);i--;isLocal=1;break;
 }}
 if(isLocal)continue;
 }
 if(M2C_FIELD(GetConnection(),s32 *,0x474)) {
 session=GetConnection();
 score=M2C_FIELD(session,s32 (**)(s32,s32),0x474)(i,M2C_FIELD(GetConnection(),s32 *,0x478));
 if(score>0) {if(score>0x7fffff)score=0x7fffff;gpiPlayerSetInt(server,sDwcKeyEval,RandomBelow(256)|(score<<8));}
 else {SBServerListRemoveServer(M2C_FIELD(GetConnection(),s32 *,0xe4),server);i--;removed=1;}
 }else gpiPlayerSetInt(server,sDwcKeyEval,RandomBelow(128));
 }
 if(sort && SBServerListGetCount(M2C_FIELD(GetConnection(),s32 *,0xe4))!=0)SBServerListSort(M2C_FIELD(GetConnection(),s32 *,0xe4),0,sDwcKeyEval,0);
 if(removed && SBServerListGetCount(M2C_FIELD(GetConnection(),s32 *,0xe4))==0)return 0;
 return 1;
}
/* Pick one of the browsed matchmaking sessions and promote it to the front of
   the list: the highest dwc_eval is found, then one session is chosen at random
   weighted towards the top of the sorted list (gMatchmakingSessionWeights) and
   given an eval one above the previous best before the list is re-sorted. */
s32 SelectMatchmakingSession(void) {
    void *GetConnection(void);
    s32 SBServerListGetCount(s32);
    s32 SBServerListGetServer(s32, s32);
    s32 SBServerGetIntValue(void *, void *, s32);
    s32 gpiPlayerSetInt(void *, void *, s32);
    s32 SBServerListSort(s32, s32, void *, s32);
    s32 RandomBelow(s32);
    s32 RuntimeIntDivMod(s32, s32);
    extern s32 gMatchmakingSessionWeights[];
    extern char sDwcKeyEval[];
    u32 roll;
    s32 maxScore = 0;
    s32 weightTotal = 0;
    s32 count;
    s32 i;
    s32 cumulative[6];
    s32 prev;
    s32 eval;
    s32 scaled;

    count = SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4));
    if (count <= 1) return count;
    i = 0;
    while (i < SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4))) {
        eval = SBServerGetIntValue((void *)SBServerListGetServer(*(s32 *)((u8 *)GetConnection() + 0xE4), i), sDwcKeyEval, -1);
        if (eval > maxScore) maxScore = eval;
        weightTotal += gMatchmakingSessionWeights[i];
        i++;
    }
    roll = RandomBelow(100);
    i = 0;
    while (i < SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4))) {
        if (i == SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4)) - 1) break;
        prev = (i > 0) ? cumulative[i - 1] : 0;
        scaled = RuntimeIntDivMod(gMatchmakingSessionWeights[i] * 100, weightTotal);
        cumulative[i] = scaled + prev;
        if (roll < (u32)cumulative[i]) break;
        i++;
    }
    if (maxScore < 0x7FFFFFFF) maxScore++;
    gpiPlayerSetInt((void *)SBServerListGetServer(*(s32 *)((u8 *)GetConnection() + 0xE4), i), sDwcKeyEval, maxScore);
    return SBServerListSort(*(s32 *)((u8 *)GetConnection() + 0xE4), 0, sDwcKeyEval, 0);
}

/* GameSpy QR2 append-key callback: append the value of game key `key` to the
 * query buffer `query`.  The low keys report a field of the current connection;
 * keys QR2_GAMEKEY_TABLE_BASE and up look the key up in the session player table
 * and append its string or integer value. */
void Qr2AppendGameKey(s32 key, void *query) {
    void *GetConnection(void);
    void Qr2AppendInt(void *, s32);
    void Qr2AppendString(void *, void *);
    extern u8 gSessionPlayers[];
    extern u8 gSessionPlayerIsString[];
    extern void *gSessionPlayerValue[];
    void *conn;
    s32 index;
    s32 offset;

    switch (key) {
    case QR2_GAMEKEY_CONN_14:
        conn = GetConnection();
        Qr2AppendInt(query, ((u8 *)conn)[0x14]);
        return;
    case QR2_GAMEKEY_CONN_16:
        conn = GetConnection();
        Qr2AppendInt(query, ((u8 *)conn)[0x16]);
        return;
    case QR2_GAMEKEY_QR2_PARAM:
        conn = GetConnection();
        Qr2AppendInt(query, *(s32 *)((char *)conn + CONN_SESSION_QR2_PARAM));
        return;
    case QR2_GAMEKEY_MODE:
        conn = GetConnection();
        Qr2AppendInt(query, ((u8 *)conn)[CONN_SESSION_MODE]);
        return;
    case QR2_GAMEKEY_MATCH_ADDR:
        conn = GetConnection();
        Qr2AppendInt(query, *(s32 *)((char *)conn + CONN_SESSION_MATCH_ADDRESS));
        return;
    case QR2_GAMEKEY_CONST_3:
        Qr2AppendInt(query, 3);
        return;
    case QR2_GAMEKEY_CONST_1:
        Qr2AppendInt(query, 1);
        return;
    }
    index = key - QR2_GAMEKEY_TABLE_BASE;
    if (index < 0) return;
    if (index >= QR2_PLAYER_COUNT) return;
    offset = index * QR2_PLAYER_STRIDE;
    if (gSessionPlayers[offset] == 0) return;
    if (gSessionPlayerIsString[offset] != 0) {
        Qr2AppendString(query, *(void **)((char *)gSessionPlayerValue + offset));
    } else {
        Qr2AppendInt(query, **(s32 **)((char *)gSessionPlayerValue + offset));
    }
}

void Qr2AppendIndex1Noop(void) {

}

void Qr2AppendIndex2Noop(void) {

}

/* QR2 collect-keys callback: for the plain (mode 0) state query, list the
 * connection's own game keys followed by the key of every live session player;
 * the indexed queries (modes 1 and 2) report no keys at all. */
void Qr2CollectKeys(s32 mode, u8 *keyList) {
    extern u8 gSessionPlayers[];
    s32 i;
    u8 *player;

    switch (mode) {
    case 0:
        break;
    case 1:
    case 2:
    default:
        return;
    }
    Qr2AppendKeyId(keyList, QR2_GAMEKEY_CONN_14);
    Qr2AppendKeyId(keyList, QR2_GAMEKEY_CONN_16);
    Qr2AppendKeyId(keyList, QR2_GAMEKEY_QR2_PARAM);
    Qr2AppendKeyId(keyList, QR2_GAMEKEY_MODE);
    Qr2AppendKeyId(keyList, QR2_GAMEKEY_MATCH_ADDR);
    Qr2AppendKeyId(keyList, QR2_GAMEKEY_CONST_3);
    Qr2AppendKeyId(keyList, QR2_GAMEKEY_CONST_1);
    player = gSessionPlayers;
    for (i = 0; i < QR2_PLAYER_COUNT; i++, player += QR2_PLAYER_STRIDE)
        if (*player) Qr2AppendKeyId(keyList, *player);
}

s32 Qr2RepeatCountNone(void) {
    return 0;
}

void Qr2ReportErrorCallback(void) {
    M2C_UNK ReportQr2Error();
    ReportQr2Error();
}

void Qr2OnPublicAddress(s32 arg0, s16 arg1) {
    void *GetConnection();
    M2C_FIELD(GetConnection(), s32 *, 0x1C) = arg0;
    M2C_FIELD(GetConnection(), s16 *, 0x1A) = arg1;
}

/* QR2 target notice: while the session is between states 1, 6 and 11, remember
 * which connect target the QR2 master reported (counting repeated notices for
 * the same target), drop the pending join's tick, open a peer connect for that
 * target and, unless reporting the error failed, mark the connection's last
 * command as none. */
void Qr2OnStateChanged(s32 target){
void *GetConnection();M2C_UNK SetConnectionState(M2C_UNK);s32 ReportPeerConnectResult();s32 func_0203ecb0();
void *conn; s32 zero;
conn=GetConnection();
if(M2C_FIELD(conn,s32 *,CONN_SESSION_STATE)==1)SetConnectionState(6);else{conn=GetConnection();if(M2C_FIELD(conn,s32 *,CONN_SESSION_STATE)!=6){conn=GetConnection();if(M2C_FIELD(conn,s32 *,CONN_SESSION_STATE)!=11)return;}}
conn=GetConnection();if(target==M2C_FIELD(conn,s32 *,CONN_SESSION_CONNECT_TARGET)){conn=GetConnection();M2C_FIELD(conn,u8 *,CONN_SESSION_TARGET_NOTICES)=(u8)(M2C_FIELD(conn,u8 *,CONN_SESSION_TARGET_NOTICES)+1);}else{conn=GetConnection();M2C_FIELD(conn,s8 *,CONN_SESSION_TARGET_NOTICES)=0;conn=GetConnection();M2C_FIELD(conn,s32 *,CONN_SESSION_CONNECT_TARGET)=target;}
conn=GetConnection();zero=0;
M2C_FIELD(conn,s32 *,CONN_SESSION_JOIN_TICK)=zero;M2C_FIELD(conn,s32 *,CONN_SESSION_JOIN_TICK+4)=zero;
func_0203ecb0(1,target,zero);
if(ReportPeerConnectResult()!=0)return;conn=GetConnection();M2C_FIELD(conn,u8 *,CONN_SESSION_LAST_COMMAND)=0xFF;
}

/* Validate and dispatch binary QR2 matchmaking commands while the session permits them. */
void Qr2OnReceiveState(s32 packetAddress, u32 packetBytes) {
    s32 GetNetSessionState(void);
    void *GetConnection(void);
    void MI_CpuCopy8(void *, void *, s32);
    s32 StringCompareN(void *, void *, s32);
    s32 HandleConnectionCommand(s32, u32, u32, u32, void *, s32);
    extern u8 sQr2MatchCommandMagic[];
    u8 header[QR2_MATCH_HEADER_SIZE];
    u8 payload[QR2_MATCH_PAYLOAD_MAX];
    u32 processedBytes = 0;

    if (GetNetSessionState() != NET_STATE_STARTING) {
        if (GetNetSessionState() != 6) return;
        if (((u8 *)GetConnection())[CONN_SESSION_MODE] != 2) {
            if (((u8 *)GetConnection())[CONN_SESSION_MODE] != 3) return;
        }
    }
    if (packetBytes < QR2_MATCH_HEADER_SIZE) return;

    for (;;) {
        MI_CpuCopy8((void *)packetAddress, header, QR2_MATCH_HEADER_SIZE);
        if (StringCompareN(header, sQr2MatchCommandMagic, 4) != 0) return;
        if (((Qr2MatchCommandHeader *)header)->version != QR2_MATCH_VERSION) return;
        MI_CpuCopy8((void *)(packetAddress + QR2_MATCH_HEADER_SIZE), payload, ((Qr2MatchCommandHeader *)header)->payloadBytes);
        if (HandleConnectionCommand(((Qr2MatchCommandHeader *)header)->command,
            ((Qr2MatchCommandHeader *)header)->profileId,
            ((Qr2MatchCommandHeader *)header)->address,
            ((Qr2MatchCommandHeader *)header)->port, payload,
            ((Qr2MatchCommandHeader *)header)->payloadBytes >> 2) == 0) return;
        processedBytes += ((Qr2MatchCommandHeader *)header)->payloadBytes + QR2_MATCH_HEADER_SIZE;
        if (processedBytes + QR2_MATCH_HEADER_SIZE > packetBytes) return;
    }
}

void func_02043e0c(void) {

}

