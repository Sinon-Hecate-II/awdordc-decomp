/* 12 functions from 0x020411DC to 0x020420A0 (main), found by ds-decomp. */
#include "common.h"
void *GetConnection();
void CloseGt2Connection(void);

void func_020411dc(s32 arg0){
extern s32 sEmptyString;extern u8 gConnectionMgr[];
s32 SetConnectionState(s32);void Qr2_StateChanged(s32);void SendConnectionPacket(s8,s32);u64 GetSystemTick(void);void TryConnectToPeer(s32,s32,s32);u32 GetConnectedPlayerMask(s32);void ReconnectUnlessServing(void);s32 SendConnectionCommand();s32 ReportConnectionCommandResult(void);void func_02042ad0(void);void SetGpiStatus(s32,void *,s32);s32 GetSessionPlayerSlot(s32);void TeardownConnectionSession(void);void DestroyServerBrowser(s32);void func_0203bd0c(void);void ReportGpiSessionStatus(void);s32 ReportConnectionStatusResult(void);void ResetSessionList(s32);
s32 n=3,update=0; s32 values[5];s32 b,c;u8 *a,*d,*e,*f,*g,*h;s32 i;
switch(arg0){
case 0:
a=GetConnection();if(M2C_FIELD(a,u8*,420)<M2C_FIELD(GetConnection(),u8*,13)-1){
SetConnectionState(13);
a=GetConnection();values[0]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1)*4,s32*,244);
values[1]=M2C_FIELD(GetConnection(),u8*,420)+1;
a=GetConnection();values[2]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1),u8*,720);
a=GetConnection();values[3]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1)*4,s32*,36);
a=GetConnection();values[4]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1)*2,u16*,164);n=5;
}else{
M2C_FIELD(GetConnection(),u8*,23)=0;M2C_FIELD(GetConnection(),s32*,32)=0;Qr2_StateChanged(M2C_FIELD(GetConnection(),s32*,16));
if(M2C_FIELD(GetConnection(),u8*,21)==0)SetConnectionState(n);else if(M2C_FIELD(GetConnection(),u8*,21)==1)SetConnectionState(4);else SetConnectionState(10);
M2C_FIELD(GetConnection(),u8*,420)=0;
a=0;if(M2C_FIELD(GetConnection(),u8*,21)==2)goto complete;
a=GetConnection();if(M2C_FIELD(a,u8*,13)==M2C_FIELD(GetConnection(),u8*,22)){
complete:
if(M2C_FIELD(GetConnection(),u8*,21)==2){a=GetConnection();d=GetConnection();M2C_FIELD(a,s32*,524)=M2C_FIELD(d+M2C_FIELD(GetConnection(),u8*,13)*4,s32*,244);}else{M2C_FIELD(GetConnection(),s32*,524)=0;a=GetConnection();M2C_FIELD(a,s32*,244)=M2C_FIELD(GetConnection(),s32*,512);}
SetConnectionState(16);M2C_FIELD(GetConnection(),s32*,468)=0;for(i=1;i<=M2C_FIELD(GetConnection(),u8*,13);i++)((void (*)(u32,s32))SendConnectionPacket)(M2C_FIELD((u8 *)GetConnection()+i,u8*,720),2);
}else{
values[0]=0;values[1]=M2C_FIELD(GetConnection(),u8*,13);a=GetConnection();values[2]=M2C_FIELD(a+M2C_FIELD(GetConnection(),u8*,13),u8*,720);
if(M2C_FIELD(GetConnection(),u8*,21)==0){M2C_FIELD(GetConnection(),s32*,232)=2;a=GetConnection();M2C_FIELD(a,u64*,236)=GetSystemTick();}
else if(M2C_FIELD(GetConnection(),u8*,21)==1){TryConnectToPeer(1,0,0);if(M2C_FIELD(GetConnection(),u8*,422)==0&&M2C_FIELD(GetConnection(),u8*,13)>=2){a=GetConnection();b=GetConnectedPlayerMask(0);d=GetConnection();if(M2C_FIELD(a,u32*,476)!=(b&~(1<<M2C_FIELD(d+M2C_FIELD(GetConnection(),u8*,13),u8*,720)))){ReconnectUnlessServing();break;}}}
}
if(M2C_FIELD(GetConnection(),u8*,21)!=2)update=1;
}
if(M2C_FIELD(GetConnection(),s32*,416)!=16){a=GetConnection();d=GetConnection();e=GetConnection();f=GetConnection();g=GetConnection();h=GetConnection();
SendConnectionCommand(8,M2C_FIELD(a+M2C_FIELD(d,u8*,13)*4,s32*,244),M2C_FIELD(e+M2C_FIELD(f,u8*,13)*4,s32*,36),M2C_FIELD(g+M2C_FIELD(h,u8*,13)*2,u16*,164),values,n);
if(ReportConnectionCommandResult())return;M2C_FIELD(GetConnection(),u8*,973)=0;}break;
case 1:SetConnectionState(1);if(M2C_FIELD(GetConnection(),u8*,21)==3){a=GetConnection();d=GetConnection();M2C_FIELD(a,s32*,524)=M2C_FIELD(d+M2C_FIELD(GetConnection(),u8*,13)*4,s32*,244);}update=1;break;
case 2:SetConnectionState(1);if(M2C_FIELD(GetConnection(),u8*,21)==0||M2C_FIELD(GetConnection(),u8*,21)==1){M2C_FIELD(GetConnection(),u8*,23)=1;a=GetConnection();M2C_FIELD(a,s32*,32)=M2C_FIELD(GetConnection(),s32*,512);}
func_02042ad0();if(M2C_FIELD(GetConnection(),u8*,13)>1){a=GetConnection();d=GetConnection();e=GetConnection();f=GetConnection();g=GetConnection();SendConnectionCommand(9,M2C_FIELD(a,s32*,244),M2C_FIELD(d,s32*,36),M2C_FIELD(e,u16*,164),f+244+(M2C_FIELD(g,u8*,13)-1)*4,1);if(ReportConnectionCommandResult())return;}break;
case 3:SetConnectionState(1);func_02042ad0();M2C_FIELD(GetConnection(),s32*,524)=0;update=1;break;
case 4:if(M2C_FIELD(GetConnection(),u8*,21)!=2)SetGpiStatus(2,&sEmptyString,0);
b=M2C_FIELD(GetConnection(),s32*,524)==0;a=GetConnection();c=GetSessionPlayerSlot(M2C_FIELD(GetConnection(),s32*,524));d=GetConnection();
((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(a,void **,1124))(0,0,b,0,c,M2C_FIELD(d,s32*,1128));
if(M2C_FIELD(GetConnection(),u8*,21)==0||M2C_FIELD(GetConnection(),u8*,21)==1){TeardownConnectionSession();}else{
if(M2C_FIELD(GetConnection(),s32*,228)!=0){DestroyServerBrowser(M2C_FIELD(GetConnection(),s32*,228));M2C_FIELD(GetConnection(),s32*,228)=0;}
func_0203bd0c();if(M2C_FIELD(GetConnection(),u8*,21)==2){ReportGpiSessionStatus();if(ReportConnectionStatusResult())return;if(gConnectionMgr[28]==1)gConnectionMgr[29]=1;SetConnectionState(10);}else SetConnectionState(1);M2C_FIELD(GetConnection(),s32*,524)=0;
}M2C_FIELD(GetConnection(),u8*,425)=0;break;
}
if(update&&M2C_FIELD(GetConnection(),u8*,21)!=3)ResetSessionList(M2C_FIELD(GetConnection(),s32*,228));
}

/* True when every player id in the list is a member of the connection.  While a
 * flagged join is settling (session state 4, then 1) the test passes, because
 * the peer list is not final yet. */
s32 AreAllConnectionMembers(s32 *playerIds,u32 count) {
 s32 IsConnectionMember();
 u32 i;
 if(M2C_FIELD(GetConnection(),u8*,CONN_SESSION_JOIN_FLAG)!=0 && M2C_FIELD(GetConnection(),s32*,CONN_SESSION_STATE)==4)return 1;
 for(i=0;i<count;i++) {
 if(!IsConnectionMember(playerIds[i]))return 0;
 if(M2C_FIELD(GetConnection(),u8*,CONN_SESSION_JOIN_FLAG)!=0 && M2C_FIELD(GetConnection(),s32*,CONN_SESSION_STATE)==1)return 1;
 }return 1;
}

/* Tear down the online connection: forget the matchmaking target, announce that
   our slot is leaving when a peer session is running, release the NAT
   negotiation session and finally close the connection. */
void DisconnectConnection(void) {
    void *GetConnection(void);
    void CloseConnection(void);
    s32 SendMatchAddress(void);
    M2C_UNK GT2NotifyConnectionClosed(s32);
    void NatNeg_ReleasePeer(s32);
    s32 CancelJoinRequest(M2C_UNK);
    s32 ReportConnectionCommandResult(void);

    M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_TARGET_ID) = 0;
    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 2) {
        CloseConnection();
        return;
    }
    M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_BUSY) = 1;
    if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 3) {
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_BUSY) = 1;
        if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT) != 0) {
            GT2NotifyConnectionClosed(*M2C_FIELD(GetConnection(), s32 **, CONN_SESSION_GT2_SOCKET));
        } else {
            CancelJoinRequest(M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_PEER_IDS));
            if (((s32 (*)())ReportConnectionCommandResult)() != 0) return;
        }
        CloseConnection();
        return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 4 ||
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 5 ||
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 6 ||
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 7 ||
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 0xb ||
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 0xc) {
        if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_JOIN_PEER) != 0) {
            CancelJoinRequest(M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_PEER_IDS));
            if (((s32 (*)())ReportConnectionCommandResult)() != 0) return;
        }
        SendMatchAddress();
        if (((s32 (*)())ReportConnectionCommandResult)() != 0) return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_NATNEG) != 0) {
        NatNeg_ReleasePeer(M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_NATNEG));
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_NATNEG) = 0;
    }
    if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT) != 0) {
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_BUSY) = 1;
        GT2NotifyConnectionClosed(*M2C_FIELD(GetConnection(), s32 **, CONN_SESSION_GT2_SOCKET));
    }
    CloseConnection();
}

/* Close the online connection: reset the GPI status and the session, then tell
   the registered match event callback that we stopped serving or joining, and
   clear the connection-change flag. */
void CloseConnection(void) {
 extern s32 sEmptyString;
 s32 ReportConnectionStatusResult(); s32 GetSessionPlayerSlot(s32); void TeardownConnectionSession(void);
 s32 hadPeer,targetCleared,targetSlot; void *conn;
 SetGpiStatus(1,&sEmptyString,0);
 if(ReportConnectionStatusResult())return;
 TeardownConnectionSession();
 if(M2C_FIELD(GetConnection(),s32*,CONN_SESSION_TARGET_ID)!=0)hadPeer=1; else hadPeer=M2C_FIELD(GetConnection(),u8*,CONN_SESSION_MODE)==2;
 targetCleared=M2C_FIELD(GetConnection(),s32*,CONN_SESSION_TARGET_ID)==0;
 conn=GetConnection();
 targetSlot=GetSessionPlayerSlot(M2C_FIELD(GetConnection(),s32*,CONN_SESSION_TARGET_ID));
 ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(conn,void**,CONN_SESSION_EVENT_CALLBACK))(0,1,targetCleared,hadPeer,targetSlot,M2C_FIELD(GetConnection(),s32*,CONN_SESSION_EVENT_DATA));
 M2C_FIELD(GetConnection(),u8*,CONN_SESSION_BUSY)=0;
}

/* Announce this connection's match address to the peer (connection command 12)
 * once it is valid and differs from the address reported to the master, then
 * clear the pending state.  Returns the command's result. */
s32 SendMatchAddress(void) {
s32 SendConnectionCommand();
s32 result=0;
s32 scratch=0;
void *connA,*connB,*connC,*connD;
if(M2C_FIELD(GetConnection(),u8*,CONN_SESSION_ADDRESS_VALID)!=0 && M2C_FIELD(GetConnection(),s32*,CONN_SESSION_MATCH_ADDRESS)!=0) {
connA=GetConnection();
if(M2C_FIELD(connA,s32*,CONN_SESSION_MATCH_ADDRESS)!=M2C_FIELD(GetConnection(),s32*,CONN_SESSION_QR2_PARAM)) {
connA=GetConnection();
connB=GetConnection();
connC=GetConnection();
connD=GetConnection();
result=SendConnectionCommand(12,M2C_FIELD(connA,s32*,CONN_SESSION_MATCH_ADDRESS),M2C_FIELD((u8*)connB+4*(M2C_FIELD(connC,u8*,CONN_SESSION_PLAYER_COUNT)+1),s32*,CONN_SESSION_PEER_DATA),M2C_FIELD((u8*)connD+2*(M2C_FIELD(GetConnection(),u8*,CONN_SESSION_PLAYER_COUNT)+1),u16*,CONN_SESSION_PEER_DATA_PORT),&scratch,1);
M2C_FIELD(GetConnection(),u8*,CONN_SESSION_ADDRESS_VALID)=0;
M2C_FIELD(GetConnection(),s32*,CONN_SESSION_MATCH_ADDRESS)=0;
}
}
return result;
}

/* Handle a connection state refresh: if the active mode is 2/3, invoke the mode callback; if mode 0, run the next connection step; if mode 1 with refresh requested, start a contextual action. */
void RefreshConnection(s32 refresh) {
    s32 GetSessionPlayerSlot(); s32 ReportMatchmakingResult();
    s32 b,c; void *p;
    if(refresh==0){CloseConnection();return;}
    ResetConnection();
    if(M2C_FIELD(GetConnection(),u8*,0x15)==2 || M2C_FIELD(GetConnection(),u8*,0x15)==3) {
        b=M2C_FIELD(GetConnection(),s32*,0x20c)==0;
        p=GetConnection();
        c=GetSessionPlayerSlot(M2C_FIELD(GetConnection(),s32*,0x20c));
        ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(p,void**,0x464))(0,1,b,0,c,M2C_FIELD(GetConnection(),s32*,0x468));
    } else if(M2C_FIELD(GetConnection(),u8*,0x15)==0) {
        if(refresh==1){SendMatchmakingParameter(0);if(ReportMatchmakingResult())return;}
    } else if(M2C_FIELD(GetConnection(),u8*,0x15)==1 && refresh==1)TryConnectToPeer(0,0,0);
}

/* Unless the session is serving a match (mode 2/3), drop the GT2 connection and
 * refresh the connection with a new connect attempt. */
void ReconnectUnlessServing(void) {
    if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == CONN_MODE_SERVE) return;
    if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == CONN_MODE_SERVE_NO_RETRY) return;
    CloseGt2Connection();
    RefreshConnection(1);
}

/* Starts the matchmaking step after a finished connection attempt: clears the
 * reported match address and teardown flag, then sends the matchmaking parameter
 * (mode 0) or the join request for our own player id (mode 1) and returns what
 * its error report gave; with no player id yet, restarts the connection chain
 * instead.  Returns 0 unless a send error was reported. */
s32 StartMatchmaking(void) {
    s32 SendMatchmakingParameter();
    s32 ReportMatchmakingResult();
    s32 SendJoinRequest();
    s32 ReportConnectionCommandResult();
    s32 result;

    M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_ADDRESS_VALID) = 0;
    M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_MATCH_ADDRESS) = 0;
    M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TEARDOWN) = 0;
    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_SELF_ID) != 0) {
        if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 0) {
            SetConnectionState(3);
            result = SendMatchmakingParameter(0);
            /* The error report takes the code left in r0 by the send above. */
            if (ReportMatchmakingResult()) return result;
        } else if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 1) {
            SetConnectionState(4);
            result = SendJoinRequest(M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_SELF_ID), 0);
            if (ReportConnectionCommandResult()) return result;
        }
    } else {
        RefreshConnection(1);
    }
    return 0;
}

/* Force-close the connection of `playerId`: record it as the connection target,
 * then close its live GT2 connection when one is registered, or drop the player
 * from the peer list otherwise.  Returns 1 when a connection was closed. */
s32 ClosePeerConnection(s32 playerId) {
    s32 *FindPlayerConnectionSlot();
    s32 *connectionSlot;
    M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_TARGET_ID) = playerId;
    connectionSlot = FindPlayerConnectionSlot(playerId, M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT) + 1);
    if (connectionSlot != 0) {
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TEARDOWN) = 2;
        GT2FailConnectionAttempt(*connectionSlot);
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TEARDOWN) = 0;
        return 1;
    }
    RemovePlayerFromConnection(playerId, M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT) + 1);
    return 0;
}

/* Close the connection's GT2 transport: flag the session teardown, fail the
 * connections held in the GT2 socket's connection table and clear the flag. */
void CloseGt2Connection(void) {
    void *GetConnection();
    M2C_UNK GT2NotifyConnectionClosed(s32);

    M2C_FIELD(GetConnection(), s8 *, CONN_SESSION_TEARDOWN) = 2;
    GT2NotifyConnectionClosed(*M2C_FIELD(GetConnection(), s32 **, CONN_SESSION_GT2_SOCKET));
    M2C_FIELD(GetConnection(), s8 *, CONN_SESSION_TEARDOWN) = 0;
}

/* Keep only the connected peers whose slot is in `mask`: send the updated peer
 * list to each kept peer, then disconnect the peers that were left out.
 * Returns 0 when a send fails. */
s32 PruneConnectionPeers(u32 mask) {
s32 SendConnectionCommand(); s32 ReportConnectionCommandResult(); s32 FindPeerSlot(); s32 DisconnectPeerSlot();
s32 dropPeers[32],keepPeers[32]; s32 dropCount=0,keepCount=0; register s32 i; s32 slot;
for(i=1;i<=M2C_FIELD(GetConnection(),u8*,CONN_SESSION_PLAYER_COUNT);i++){
if(mask & (1<<M2C_FIELD((u8*)GetConnection()+i,u8*,CONN_SESSION_PEER_SLOTS))){
keepPeers[keepCount]=M2C_FIELD((u8*)GetConnection()+((u32)i<<2),s32*,CONN_SESSION_PEER_IDS);keepCount++;
}else {dropPeers[dropCount]=M2C_FIELD((u8*)GetConnection()+((u32)i<<2),s32*,CONN_SESSION_PEER_IDS);dropCount++;}
}
for(i=0;i<keepCount;i++){
SendConnectionCommand(16,keepPeers[i],0,0,dropPeers,dropCount);
if(ReportConnectionCommandResult())return 0;
}
M2C_FIELD(GetConnection(),u8*,CONN_SESSION_TEARDOWN)=2;
for(i=0;i<dropCount;i++){slot=FindPeerSlot(dropPeers[i],0);if(slot!=255)DisconnectPeerSlot(slot);}
M2C_FIELD(GetConnection(),u8*,CONN_SESSION_TEARDOWN)=0;
return 1;
}

/* Prepare and send a 4-byte notification packet (type 2 or 3) about a player slot, then timestamp the connection state. */
void SendConnectionPacket(s8 arg0, s32 arg1) {
    u64 GetSystemTick(void);
    void SendTransfer(s32, s8, void *, s32);
    u8 buf[4];
    u8 i;
    void *p;
    switch (arg1) {
    case 2:
        p = GetConnection();
        if (arg0 == M2C_FIELD((u8 *)p + M2C_FIELD(GetConnection(), u8 *, 0xd), u8 *, 0x2d0))
            buf[0] = 1;
        else
            buf[0] = 0;
        for (i = 1; i <= M2C_FIELD(GetConnection(), u8 *, 0xd); i++) {
            if (arg0 == M2C_FIELD((u8 *)GetConnection() + i, u8 *, 0x2d0)) {
                buf[1] = i;
                buf[2] = arg0;
                break;
            }
        }
        break;
    case 3:
        buf[0] = M2C_FIELD(GetConnection(), u16 *, 0x1b0);
        buf[1] = (s32)M2C_FIELD(GetConnection(), u16 *, 0x1b0) >> 8;
        break;
    }
    SendTransfer(arg1, arg0, buf, 4);
    p = GetConnection();
    M2C_FIELD(p, u64 *, 0x1e0) = GetSystemTick();
}

