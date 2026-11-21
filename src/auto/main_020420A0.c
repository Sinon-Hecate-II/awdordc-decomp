/* 16 functions from 0x020420A0 to 0x0204309C (main), found by ds-decomp. */
#include "common.h"
#include "net_session.h"

#pragma opt_strength_reduction off
/* Per-frame handler for the connection states that wait on the other peers:
 * state 9 (own player slot being accepted), 16 (sync acknowledgements) and 17
 * (measured latency). It repeats the notices every 6 s and advances or tears
 * down the session once everyone has answered; returns 0 when a send fails. */
s32 UpdateConnectionSyncWait(void) {
 void *GetConnection(void);
 u64 GetSystemTick(void);
 u64 U64Divide(u64,u64);
 s32 GetNetSessionState(void);
 s32 RestartConnection(s32);
 void SendConnectionPacket(s32,s32);
 s32 PruneConnectionPeers(s32);
 void CloseGt2Connection(void);
 void func_02041be0(s32);
 void func_020411dc(s32);
 s32 func_02040e1c(s32);
 u64 now,elapsed;
 s32 i;
 void *conn;
 if(M2C_FIELD(GetConnection(),s32 *,0x1a0)==CONN_STATE_WAIT_SLOT ||
 M2C_FIELD(GetConnection(),s32 *,0x1a0)==CONN_STATE_WAIT_SYNC_ACK ||
 M2C_FIELD(GetConnection(),s32 *,0x1a0)==CONN_STATE_WAIT_SYNC_RTT) {
 now=GetSystemTick();
 elapsed=U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x1e0))<<6,0x82eaULL);
 } else return 1;
 switch(M2C_FIELD(GetConnection(),s32 *,0x1a0)){
 case CONN_STATE_WAIT_SLOT:
 if(elapsed>6000ULL){
 if(GetNetSessionState()==5 && M2C_FIELD(GetConnection(),u8 *,0x1ad)>=5){
 if(RestartConnection(M2C_FIELD(GetConnection(),s32 *,0xf4))==0) return 0;
 } else {
 M2C_FIELD(GetConnection(),u8 *,0x1ad)++;
 SendConnectionPacket(M2C_FIELD(GetConnection(),u8 *,0x2d0),CONN_NOTICE_SYNC_STATUS);
 }
 }
 break;
 case CONN_STATE_WAIT_SYNC_ACK:
 if(elapsed>6000ULL){
 M2C_FIELD(GetConnection(),u8 *,0x1ab)++;
 if(M2C_FIELD(GetConnection(),u8 *,0x1ab)>5){
 if(M2C_FIELD(GetConnection(),u8 *,0x15)==0 || M2C_FIELD(GetConnection(),u8 *,0x15)==1){
 CloseGt2Connection();
 func_02041be0(1);
 } else {
 if(PruneConnectionPeers(M2C_FIELD(GetConnection(),s32 *,0x1d4))==0) return 0;
 if(M2C_FIELD(GetConnection(),u8 *,0xd)!=0){
 M2C_FIELD(GetConnection(),u8 *,0x1ab)=0;
 M2C_FIELD(GetConnection(),u64 *,0x1e0)=GetSystemTick();
 } else {
 if(func_02040e1c(M2C_FIELD(GetConnection(),s32 *,0x20c))==0) return 0;
 }
 }
 } else {
 for(i=1;i<=M2C_FIELD(GetConnection(),u8 *,0xd);i++){
 conn=GetConnection();
 if((M2C_FIELD(conn,u32 *,0x1d4)&(1<<M2C_FIELD((u8 *)GetConnection()+i,u8 *,0x2d0)))==0){
 SendConnectionPacket(M2C_FIELD((u8 *)GetConnection()+i,u8 *,0x2d0),CONN_NOTICE_PLAYER_SLOT);
 }
 }
 }
 }
 break;
 case CONN_STATE_WAIT_SYNC_RTT:
 if(elapsed>(u64)(s32)M2C_FIELD((u8 *)GetConnection()+0x100,u16 *,0xb0)) func_020411dc(4);
 break;
 }
 return 1;
}
#pragma opt_strength_reduction reset
/* Send a peer-synchronization notice to `peerId`; a PEER_SYNC_PREPARE notice also
 * carries the matchmaking target id as its single value.  The command's result is
 * reported and the sync-sent tick recorded; returns 0 if the report says it failed. */
s32 SendPeerSyncNotice(s32 peerId, s32 notice) {
    void *GetConnection(void);
    u64 GetSystemTick(void);
    void SendConnectionCommand(s32, s32, s32, s32, s32 *, s32);
    s32 ReportConnectionCommandResult(void);
    s32 value, count;
    if (notice == PEER_SYNC_PREPARE) {
        value = M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_TARGET_ID);
        count = 1;
    } else count = 0;
    SendConnectionCommand(notice, peerId, 0, 0, &value, count);
    if (ReportConnectionCommandResult()) return 0;
    {
        void *conn = GetConnection();
        M2C_FIELD(conn, u64 *, CONN_SESSION_SYNC_SENT) = GetSystemTick();
    }
    return 1;
}

/* Handle a peer's synchronization notice: a prepare request opens the session,
 * an acknowledgement records the peer and its round-trip overrun, and once every
 * connected peer has answered the sync is completed and announced. Returns 0 if
 * a notice could not be sent. */
s32 HandlePeerSyncNotice(s32 peerId,s32 notice,s32 value) {
void *GetConnection(void);
s32 GetNetSessionState(void);
void SetConnectionState(s32);
void ClosePeerConnection(s32);
s32 SendPeerSyncNotice(s32,s32);
u64 GetSystemTick(void);
u64 U64Divide(u64,u64);
u8 FindPeerSlot(s32,s32);
s32 GetConnectedPlayerMask(s32);
void func_02041be0(s32);
u64 now,excess;
s32 idx,connectedPeers,i;
if(GetNetSessionState()!=6)return 1;
switch(notice){
case PEER_SYNC_PREPARE:
if(M2C_FIELD(GetConnection(),s32*,CONN_SESSION_STATE)!=CONN_STATE_SYNC_PREPARE){SetConnectionState(CONN_STATE_SYNC_PREPARE);ClosePeerConnection(value);}
if(SendPeerSyncNotice(peerId,PEER_SYNC_ACK)==0)return 0;
break;
case PEER_SYNC_ACK:
if(M2C_FIELD(GetConnection(),s32*,CONN_SESSION_STATE)==CONN_STATE_SYNC_MEASURE){
now=GetSystemTick();
if((U64Divide((now-M2C_FIELD(GetConnection(),u64*,CONN_SESSION_SYNC_SENT))<<6,0x82eaULL)>>1)>300ULL){
excess=(U64Divide((now-M2C_FIELD(GetConnection(),u64*,CONN_SESSION_SYNC_SENT))<<6,0x82eaULL)>>1)-300ULL;
if(excess>M2C_FIELD(GetConnection(),u16*,CONN_SESSION_SYNC_EXCESS))M2C_FIELD(GetConnection(),u16*,CONN_SESSION_SYNC_EXCESS)=excess;
}
idx=FindPeerSlot(peerId,0);
if(idx!=255)M2C_FIELD(GetConnection(),u32*,CONN_SESSION_SYNC_ACKS)|=1U<<idx;
connectedPeers=GetConnectedPlayerMask(1);
if(connectedPeers==M2C_FIELD(GetConnection(),s32*,CONN_SESSION_SYNC_ACKS)){
for(i=1;i<=M2C_FIELD(GetConnection(),u8*,CONN_SESSION_PLAYER_COUNT);i++){
if(SendPeerSyncNotice(M2C_FIELD((u8*)GetConnection()+(u32)i*4,s32*,CONN_SESSION_PEER_IDS),PEER_SYNC_DONE)==0)return 0;
}
SetConnectionState(CONN_STATE_SYNC_DONE);
}
}else{
if(SendPeerSyncNotice(peerId,PEER_SYNC_DONE)==0)return 0;
}
break;
case PEER_SYNC_DONE:
if(M2C_FIELD(GetConnection(),s32*,CONN_SESSION_STATE)==CONN_STATE_SYNC_PREPARE)func_02041be0(2);
break;
}
return 1;
}

#pragma opt_strength_reduction off
/* Timer-driven retransmission for the connection sync handshake states: prepare
 * (8), measure the round trip (14) and complete (15). Re-sends the sync notices
 * after 6 s, retries the peer list up to five times, and reconnects when the
 * measured latency overruns the recorded maximum; returns 0 when a send fails. */
s32 UpdateConnectionSyncTimers(void) {
 void *GetConnection(void);
 u64 GetSystemTick(void);
 u64 U64Divide(u64,u64);
 s32 SendPeerSyncNotice(s32,s32);
 s32 PruneConnectionPeers(s32);
 void func_02041be0(s32);
 u64 now,elapsed;
 s32 i;
 void *conn;
 if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==CONN_STATE_SYNC_PREPARE ||
 M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==CONN_STATE_SYNC_MEASURE ||
 M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==CONN_STATE_SYNC_DONE) {
 now=GetSystemTick();
 elapsed=U64Divide((now-M2C_FIELD(GetConnection(),u64 *,CONN_SESSION_SYNC_SENT))<<6,0x82eaULL);
 } else return 1;
 switch(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)){
 case CONN_STATE_SYNC_PREPARE:
 if(elapsed>6000 && SendPeerSyncNotice(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS),PEER_SYNC_ACK)==0) return 0;
 break;
 case CONN_STATE_SYNC_MEASURE:
 if(elapsed>6000){
 M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SYNC_RETRY)++;
 if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SYNC_RETRY)>5){
 if(PruneConnectionPeers(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SYNC_ACKS))==0) return 0;
 if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT)!=0){
 M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SYNC_RETRY)=0;
 M2C_FIELD(GetConnection(),u64 *,CONN_SESSION_SYNC_SENT)=GetSystemTick();
 } else func_02041be0(2);
 } else {
 for(i=1;i<=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT);i++){
 conn=GetConnection();
 if((M2C_FIELD(conn,u32 *,CONN_SESSION_SYNC_ACKS)&(1<<M2C_FIELD((u8 *)GetConnection()+i,u8 *,CONN_SESSION_PEER_SLOTS)))==0){
 if(SendPeerSyncNotice(M2C_FIELD((u8 *)GetConnection()+i*4,s32 *,CONN_SESSION_PEER_IDS),PEER_SYNC_PREPARE)==0) return 0;
 }
 }
 }
 }
 break;
 case CONN_STATE_SYNC_DONE:
 if(elapsed>(u64)(s32)M2C_FIELD((u8 *)GetConnection()+0x100,u16 *,CONN_SESSION_SYNC_EXCESS-0x100)) func_02041be0(2);
 break;
 }
 return 1;
}
#pragma opt_strength_reduction reset
u8 func_020427b4(void){extern u8 gSessionPlayers[];u8 i=0;do{if(gSessionPlayers[i*12]==0)return i+100;i++;}while(i<154);return 0;}

void ClearSessionPlayers(void){extern u8 gSessionPlayers[];void HeapFree(s32,s32,s32);void CpuFill(s32,void *,s32);s32 i=0;u8 *p=gSessionPlayers;do{if(M2C_FIELD(p,s32 *,4))HeapFree(4,M2C_FIELD(p,s32 *,4),0);i++;p+=12;}while(i<154);CpuFill(0,gSessionPlayers,0x738);}

/* Lowest player slot id (0..31, or 32 when all are taken) that no connected peer
 * occupies in the connection's list of peer slot ids. */
u8 FindUnusedPlayerSlot(void){
void *GetConnection(void);
u8 slot=0;
s32 i;
do{
for(i=0;i<=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SLOT);i++){
if(slot==M2C_FIELD((u8 *)GetConnection()+i,u8 *,CONN_SESSION_PEER_SLOTS))break;
}
if(i>M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SLOT))break;
slot++;
}while(slot<32);
return slot;
}

/* True when `playerId` is one of this connection's match players: walks the
 * connection's player index list and compares each entry's session player id. */
s32 IsConnectionMember(s32 playerId){
void *GetConnection(void);
s32 GetSessionPlayerId(u8);
s32 i,sessionPlayerId;
if(!M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PLAYER_RECORDS))return 0;
for(i=0;i<M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PLAYER_LIST_COUNT);i++){
sessionPlayerId=GetSessionPlayerId(M2C_FIELD((u8 *)GetConnection()+i,u8 *,CONN_SESSION_PLAYER_LIST));
if(sessionPlayerId>0&&sessionPlayerId==playerId)return 1;
}
return 0;
}

s32 GetBrowsedServerPid(void *arg0) {
    s32 SBServerGetIntValue(void *, void *, s32);
    extern u8 data_020fca1c[];
    extern u8 data_020fca28[];
    extern u8 sDwcKeyMType[];
    extern u8 sDwcKeyMResv[];
    extern u8 sDwcKeyMVer[];
    extern u8 sDwcKeyPid[];
    s32 r0;

    // Checks several conditions using SBServerGetIntValue, returns 0 if any main check fails.
    r0 = SBServerGetIntValue(arg0, data_020fca1c, -1);
    if (r0 == -1) return 0;
    r0 = SBServerGetIntValue(arg0, data_020fca28, -1);
    if (r0 == -1) return 0;
    r0 = SBServerGetIntValue(arg0, sDwcKeyMType, -1);
    if (r0 == -1) return 0;
    r0 = SBServerGetIntValue(arg0, sDwcKeyMResv, -1);
    if (r0 == -1) {
        r0 = SBServerGetIntValue(arg0, sDwcKeyMResv, 0);
        if (r0 == 0) return 0;
    }
    r0 = SBServerGetIntValue(arg0, sDwcKeyMVer, -1);
    if (r0 == -1) return 0;
    r0 = SBServerGetIntValue(arg0, sDwcKeyPid, 0);
    return r0;
}

/* Slot id (an entry of CONN_SESSION_PEER_SLOTS) of the connected peer whose id is
 * `peerId`, searched from slot 1, or from slot 0 when `includeSlotZero` is set;
 * CONN_SESSION_NO_PEER_SLOT when no peer has that id. */
u8 FindPeerSlot(s32 peerId, s32 includeSlotZero) {
    void *GetConnection(void);
    s32 i = includeSlotZero == 0 ? 1 : 0;
    if (i <= M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT)) {
        do {
            void *conn = GetConnection();
            if (peerId == M2C_FIELD((u8 *)conn + (u32)i * 4, s32 *, CONN_SESSION_PEER_IDS))
                return M2C_FIELD((u8 *)GetConnection() + i, u8 *, CONN_SESSION_PEER_SLOTS);
            i++;
        } while (i <= M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT));
    }
    return CONN_SESSION_NO_PEER_SLOT;
}

/* The player slots of this session's peers as a bitmask: with `fromSessionMask`
 * set, the session's present-player mask minus the local player (slot 0);
 * otherwise one bit per connected peer, taken from each peer's assigned slot. */
s32 GetConnectedPlayerMask(s32 fromSessionMask) {
    void *GetConnection();
    s32 mask;
    s32 slot;
    u8 peerSlot;

    mask = 0;
    if (fromSessionMask != 0) {
        return M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_PLAYER_MASK) & ~1;
    }
    slot = 1;
    if ((s32) M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT) >= 1) {
        do {
            peerSlot = M2C_FIELD((GetConnection() + slot), u8 *, CONN_SESSION_PEER_SLOTS);
            slot += 1;
            mask |= 1 << peerSlot;
        } while (slot <= (s32) M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT));
    }
    return mask;
}

void func_02042ad0(void){void *GetConnection(void);u64 GetSystemTick(void);void *p;M2C_FIELD(GetConnection(),u8 *,0x1ad)=0;p=GetConnection();M2C_FIELD(p,u64 *,0x1f8)=GetSystemTick();}

/* Reset the match-sync bookkeeping: clear the peer answer masks and the retry
 * counter and stamp the last-sync time.  With keepStartTick zero (a fresh sync
 * phase) the phase start time is stamped too; when it is nonzero (a peer was
 * added or the round timed out) the original phase start is kept. */
void ResetConnectionSync(s32 keepStartTick) {
    u64 GetSystemTick(void);
    extern void *gConnectionMgr;
    u64 now;

    if (!gConnectionMgr || !M2C_FIELD(gConnectionMgr, u8 *, CONN_SYNC_ACTIVE)) {
        return;
    }
    M2C_FIELD(gConnectionMgr, u32 *, CONN_SYNC_ANSWERED) = 0;
    M2C_FIELD(gConnectionMgr, u32 *, CONN_SYNC_READY) = 0;
    M2C_FIELD(gConnectionMgr, u8 *, CONN_SYNC_RETRIES) = 0;
    now = GetSystemTick();
    M2C_FIELD(gConnectionMgr, u64 *, CONN_SYNC_SENT_TICK) = now;
    if (keepStartTick) {
        return;
    }
    now = GetSystemTick();
    M2C_FIELD(gConnectionMgr, u64 *, CONN_SYNC_START_TICK) = now;
}

#pragma push
#pragma opt_strength_reduction off
/* Per-frame connection sync: waits until every peer's player data has arrived,
 * retransmits the sync packet on timeout, and advances the session to the
 * ready state (19) once all players agree. */
void UpdateConnectionSync(void) {
u64 GetSystemTick(void);
u64 U64Divide(u64,u64);
void *GetConnection(void);
extern void *gConnectionMgr;
void *mgr,*conn,*connA,*connB;
s32 i,n;
u64 elapsed;
if(!gConnectionMgr || !M2C_FIELD(gConnectionMgr,u8*,0)) return;
if(M2C_FIELD(GetConnection(),u8*,0x15)==2) return;
if(M2C_FIELD(GetConnection(),u8*,0x15)==3) return;
if(M2C_FIELD(GetConnection(),s32*,0x1a0)==19) {
n=GetConnectedPlayerMask(0); mgr=gConnectionMgr;
if(M2C_FIELD(mgr,s32*,8)==n) {
if(M2C_FIELD(mgr,s32*,12)==n) {
conn=GetConnection(); M2C_FIELD(conn,u8*,0x16)=M2C_FIELD(GetConnection(),u8*,13);
conn=GetConnection(); M2C_FIELD(conn,u8*,0x1a4)=M2C_FIELD(GetConnection(),u8*,13)-1;
func_020411dc(0); return;
}
M2C_FIELD(mgr,u64*,24)=GetSystemTick(); M2C_FIELD(mgr,s32*,8)=0;
if(M2C_FIELD(GetConnection(),u8*,0x15)==0) {
SetConnectionState(3); M2C_FIELD(GetConnection(),s32*,0xe8)=2;
conn=GetConnection(); M2C_FIELD(conn,u64*,0xec)=GetSystemTick(); return;
}
SetConnectionState(4); TryConnectToPeer(1,0,0); return;
}
n=M2C_FIELD(mgr,u8*,2);
elapsed=U64Divide((GetSystemTick()-M2C_FIELD(mgr,u64*,24))<<6,0x82ea);
if(elapsed<(u64)(s64)(n*6000)) return;
if((u32)n>5) {ResetConnectionSync(1);CloseGt2Connection();func_02041be0(1);return;}
for(i=1;i<=M2C_FIELD(GetConnection(),u8*,13);i++) {
if(!(M2C_FIELD(gConnectionMgr,u32*,8)&(1<<M2C_FIELD(GetConnection()+i,u8*,0x2d0)))) {
connA=GetConnection(); connB=GetConnection(); conn=GetConnection();
SendConnectionCommand(17,M2C_FIELD(connA+i*4,s32*,0xf4),M2C_FIELD(connB+i*4,s32*,0x24),M2C_FIELD(conn+i*2,u16*,0xa4),0,0);
if(ReportConnectionCommandResult()) return;
}}
M2C_FIELD(gConnectionMgr,u8*,2)++; return;
}
if(M2C_FIELD(GetConnection(),s32*,0x1a0)!=4 && M2C_FIELD(GetConnection(),s32*,0x1a0)!=3) return;
mgr=gConnectionMgr;
if(M2C_FIELD(GetConnection(),u8*,13)<M2C_FIELD(mgr,u8*,1)-1) return;
if(!M2C_FIELD(mgr,u8*,2)) {
mgr=gConnectionMgr;
if(U64Divide((GetSystemTick()-M2C_FIELD(mgr,u64*,16))<<6,0x82ea)>=M2C_FIELD(mgr,u32*,4)) goto send;
}
if(!M2C_FIELD(mgr,u8*,2)) return;
mgr=gConnectionMgr;
if(((GetSystemTick()-M2C_FIELD(mgr,u64*,24))<<6)/0x82ea<(M2C_FIELD(mgr,u32*,4)>>2)) return;
send:
if(M2C_FIELD(GetConnection(),s32*,0x204)) {
func_02040dc8(M2C_FIELD(GetConnection(),s32*,0x204)); if(ReportConnectionCommandResult()) return;
}
SetConnectionState(19);
for(i=1;i<=M2C_FIELD(GetConnection(),u8*,13);i++) {
connA=GetConnection();connB=GetConnection();conn=GetConnection();
SendConnectionCommand(17,M2C_FIELD(connA+i*4,s32*,0xf4),M2C_FIELD(connB+i*4,s32*,0x24),M2C_FIELD(conn+i*2,u16*,0xa4),0,0);
if(ReportConnectionCommandResult()) return;
}
mgr=gConnectionMgr;M2C_FIELD(mgr,u64*,24)=GetSystemTick();M2C_FIELD(mgr,u8*,2)=1;
}
#pragma pop
/* Reports a failed connection status and returns the original result. */
u32 ReportConnectionStatusResult(u32 result, u32 unused, u32 detailOffset) {
    u32 status = result;
    u32 errorCode = status;

    if (status == 0) return 0;

    switch (status) {
    case 1:
        errorCode = 9;
        detailOffset = errorCode - 10;
        break;
    case 2:
        errorCode = 9;
        detailOffset = errorCode - 11;
        break;
    case 3:
        errorCode = 6;
        detailOffset = errorCode - 16;
        break;
    case 4:
        errorCode = 6;
        detailOffset = errorCode - 26;
        break;
    }

    ReportConnectionError(errorCode, detailOffset + NET_SESSION_STATUS_DETAIL_BASE);
    return status;
}

/* Reports a matchmaking-send result: maps the operation result (1..6) to a WFC
 * error class and a detail word for this call site, hands them to
 * ReportConnectionError, and returns the result unchanged.  Result 0 (success)
 * reports nothing. */
u32 ReportMatchmakingResult(u32 result,u32 unused,u32 detail){
u32 ret=result;u32 errorCode=ret;
if(ret==0)return 0;
switch(ret){
case 1:errorCode=6;detail=errorCode-56;break;
case 2:errorCode=6;detail=errorCode-36;break;
case 3:errorCode=6;detail=errorCode-26;break;
case 4:errorCode=6;detail=errorCode-46;break;
case 5:errorCode=9;detail=errorCode-10;break;
case 6:errorCode=9;detail=errorCode-11;break;
}
ReportConnectionError(errorCode,detail+0xfffeb3f8);
return ret;
}

