/* 16 functions from 0x020420A0 to 0x0204309C (main), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
/* Per-frame handler for the connection states that wait on the other peers:
 * state 9 (own player slot being accepted), 16 (sync acknowledgements) and 17
 * (measured latency). It repeats the notices every 6 s and advances or tears
 * down the session once everyone has answered; returns 0 when a send fails. */
s32 UpdateConnectionSyncWait(void) {
 void *GetConnection(void);
 u64 GetSystemTick(void);
 u64 func_02072088(u64,u64);
 s32 func_02038f6c(void);
 s32 func_02041038(s32);
 void SendConnectionPacket(s32,s32);
 s32 func_02041e74(s32);
 void func_02041e44(void);
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
 elapsed=func_02072088((now-M2C_FIELD(GetConnection(),u64 *,0x1e0))<<6,0x82eaULL);
 } else return 1;
 switch(M2C_FIELD(GetConnection(),s32 *,0x1a0)){
 case CONN_STATE_WAIT_SLOT:
 if(elapsed>6000ULL){
 if(func_02038f6c()==5 && M2C_FIELD(GetConnection(),u8 *,0x1ad)>=5){
 if(func_02041038(M2C_FIELD(GetConnection(),s32 *,0xf4))==0) return 0;
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
 func_02041e44();
 func_02041be0(1);
 } else {
 if(func_02041e74(M2C_FIELD(GetConnection(),s32 *,0x1d4))==0) return 0;
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
s32 SendPeerSyncNotice(s32 a,s32 b){void *GetConnection(void);u64 GetSystemTick(void);void func_0203f058(s32,s32,s32,s32,s32 *,s32);s32 func_0204084c(void);s32 v,k;if(b==13){v=M2C_FIELD(GetConnection(),s32 *,0x20c);k=1;}else k=0;func_0203f058(b,a,0,0,&v,k);if(func_0204084c())return 0;{void *p=GetConnection();M2C_FIELD(p,u64 *,0x1e8)=GetSystemTick();}return 1;}

/* Handle a peer's synchronization notice: a prepare request opens the session,
 * an acknowledgement records the peer and its round-trip overrun, and once every
 * connected peer has answered the sync is completed and announced. Returns 0 if
 * a notice could not be sent. */
s32 HandlePeerSyncNotice(s32 peerId,s32 notice,s32 value) {
void *GetConnection(void);
s32 func_02038f6c(void);
void SetConnectionState(s32);
void func_02041dd4(s32);
s32 SendPeerSyncNotice(s32,s32);
u64 GetSystemTick(void);
u64 func_02072088(u64,u64);
u8 func_02042a08(s32,s32);
s32 GetConnectedPlayerMask(s32);
void func_02041be0(s32);
u64 now,excess;
s32 idx,connectedPeers,i;
if(func_02038f6c()!=6)return 1;
switch(notice){
case PEER_SYNC_PREPARE:
if(M2C_FIELD(GetConnection(),s32*,CONN_SESSION_STATE)!=CONN_STATE_SYNC_PREPARE){SetConnectionState(CONN_STATE_SYNC_PREPARE);func_02041dd4(value);}
if(SendPeerSyncNotice(peerId,PEER_SYNC_ACK)==0)return 0;
break;
case PEER_SYNC_ACK:
if(M2C_FIELD(GetConnection(),s32*,CONN_SESSION_STATE)==CONN_STATE_SYNC_MEASURE){
now=GetSystemTick();
if((func_02072088((now-M2C_FIELD(GetConnection(),u64*,CONN_SESSION_SYNC_SENT))<<6,0x82eaULL)>>1)>300ULL){
excess=(func_02072088((now-M2C_FIELD(GetConnection(),u64*,CONN_SESSION_SYNC_SENT))<<6,0x82eaULL)>>1)-300ULL;
if(excess>M2C_FIELD(GetConnection(),u16*,CONN_SESSION_SYNC_EXCESS))M2C_FIELD(GetConnection(),u16*,CONN_SESSION_SYNC_EXCESS)=excess;
}
idx=func_02042a08(peerId,0);
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
 u64 func_02072088(u64,u64);
 s32 SendPeerSyncNotice(s32,s32);
 s32 func_02041e74(s32);
 void func_02041be0(s32);
 u64 now,elapsed;
 s32 i;
 void *conn;
 if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==CONN_STATE_SYNC_PREPARE ||
 M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==CONN_STATE_SYNC_MEASURE ||
 M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==CONN_STATE_SYNC_DONE) {
 now=GetSystemTick();
 elapsed=func_02072088((now-M2C_FIELD(GetConnection(),u64 *,CONN_SESSION_SYNC_SENT))<<6,0x82eaULL);
 } else return 1;
 switch(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)){
 case CONN_STATE_SYNC_PREPARE:
 if(elapsed>6000 && SendPeerSyncNotice(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS),PEER_SYNC_ACK)==0) return 0;
 break;
 case CONN_STATE_SYNC_MEASURE:
 if(elapsed>6000){
 M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SYNC_RETRY)++;
 if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SYNC_RETRY)>5){
 if(func_02041e74(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SYNC_ACKS))==0) return 0;
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

void func_020427f4(void){extern u8 gSessionPlayers[];void func_020376d8(s32,s32,s32);void func_02007e54(s32,void *,s32);s32 i=0;u8 *p=gSessionPlayers;do{if(M2C_FIELD(p,s32 *,4))func_020376d8(4,M2C_FIELD(p,s32 *,4),0);i++;p+=12;}while(i<154);func_02007e54(0,gSessionPlayers,0x738);}

u8 func_0204284c(void){void *GetConnection(void);u8 i=0;s32 j;do{for(j=0;j<=M2C_FIELD(GetConnection(),u8 *,20);j++){if(i==M2C_FIELD((u8 *)GetConnection()+j,u8 *,0x2d0))break;}if(j>M2C_FIELD(GetConnection(),u8 *,20))break;i++;}while(i<32);return i;}

s32 IsConnectionMember(s32 a){void *GetConnection(void);s32 GetSessionPlayerId(u8);s32 i,v;if(!M2C_FIELD(GetConnection(),s32 *,0x2fc))return 0;for(i=0;i<M2C_FIELD(GetConnection(),s32 *,0x344);i++){v=GetSessionPlayerId(M2C_FIELD((u8 *)GetConnection()+i,u8 *,0x304));if(v>0&&v==a)return 1;}return 0;}

s32 func_0204292c(void *arg0) {
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

u8 func_02042a08(s32 a,s32 b){void *GetConnection(void);s32 i=b==0?1:0;if(i<=M2C_FIELD(GetConnection(),u8 *,13)){do{void *p=GetConnection();if(a==M2C_FIELD((u8 *)p+((u32)i*4),s32 *,0xf4))return M2C_FIELD((u8 *)GetConnection()+i,u8 *,0x2d0);i++;}while(i<=M2C_FIELD(GetConnection(),u8 *,13));}return 255;}

s32 GetConnectedPlayerMask(s32 arg0) {
    void *GetConnection();
    s32 var_r5;
    s32 var_r6;
    u8 temp_r0;

    var_r5 = 0;
    if (arg0 != 0) {
        return M2C_FIELD(GetConnection(), s32 *, 0x2F0) & ~1;
    }
    var_r6 = 1;
    if ((s32) M2C_FIELD(GetConnection(), u8 *, 0xD) >= 1) {
        do {
            temp_r0 = M2C_FIELD((GetConnection() + var_r6), u8 *, 0x2D0);
            var_r6 += 1;
            var_r5 |= 1 << temp_r0;
        } while (var_r6 <= (s32) M2C_FIELD(GetConnection(), u8 *, 0xD));
    }
    return var_r5;
}

void func_02042ad0(void){void *GetConnection(void);u64 GetSystemTick(void);void *p;M2C_FIELD(GetConnection(),u8 *,0x1ad)=0;p=GetConnection();M2C_FIELD(p,u64 *,0x1f8)=GetSystemTick();}

void ResetConnectionSync(s32 a){u64 GetSystemTick(void);extern void *gConnectionMgr;u64 t;if(!gConnectionMgr||!M2C_FIELD(gConnectionMgr,u8 *,0))return;M2C_FIELD(gConnectionMgr,s32 *,8)=0;M2C_FIELD(gConnectionMgr,s32 *,12)=0;M2C_FIELD(gConnectionMgr,u8 *,2)=0;t=GetSystemTick();M2C_FIELD(gConnectionMgr,u64 *,24)=t;if(a)return;t=GetSystemTick();M2C_FIELD(gConnectionMgr,u64 *,16)=t;}

#pragma push
#pragma opt_strength_reduction off
/* Per-frame connection sync: waits until every peer's player data has arrived,
 * retransmits the sync packet on timeout, and advances the session to the
 * ready state (19) once all players agree. */
void UpdateConnectionSync(void) {
u64 GetSystemTick(void);
u64 func_02072088(u64,u64);
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
elapsed=func_02072088((GetSystemTick()-M2C_FIELD(mgr,u64*,24))<<6,0x82ea);
if(elapsed<(u64)(s64)(n*6000)) return;
if((u32)n>5) {ResetConnectionSync(1);func_02041e44();func_02041be0(1);return;}
for(i=1;i<=M2C_FIELD(GetConnection(),u8*,13);i++) {
if(!(M2C_FIELD(gConnectionMgr,u32*,8)&(1<<M2C_FIELD(GetConnection()+i,u8*,0x2d0)))) {
connA=GetConnection(); connB=GetConnection(); conn=GetConnection();
func_0203f058(17,M2C_FIELD(connA+i*4,s32*,0xf4),M2C_FIELD(connB+i*4,s32*,0x24),M2C_FIELD(conn+i*2,u16*,0xa4),0,0);
if(func_0204084c()) return;
}}
M2C_FIELD(gConnectionMgr,u8*,2)++; return;
}
if(M2C_FIELD(GetConnection(),s32*,0x1a0)!=4 && M2C_FIELD(GetConnection(),s32*,0x1a0)!=3) return;
mgr=gConnectionMgr;
if(M2C_FIELD(GetConnection(),u8*,13)<M2C_FIELD(mgr,u8*,1)-1) return;
if(!M2C_FIELD(mgr,u8*,2)) {
mgr=gConnectionMgr;
if(func_02072088((GetSystemTick()-M2C_FIELD(mgr,u64*,16))<<6,0x82ea)>=M2C_FIELD(mgr,u32*,4)) goto send;
}
if(!M2C_FIELD(mgr,u8*,2)) return;
mgr=gConnectionMgr;
if(((GetSystemTick()-M2C_FIELD(mgr,u64*,24))<<6)/0x82ea<(M2C_FIELD(mgr,u32*,4)>>2)) return;
send:
if(M2C_FIELD(GetConnection(),s32*,0x204)) {
func_02040dc8(M2C_FIELD(GetConnection(),s32*,0x204)); if(func_0204084c()) return;
}
SetConnectionState(19);
for(i=1;i<=M2C_FIELD(GetConnection(),u8*,13);i++) {
connA=GetConnection();connB=GetConnection();conn=GetConnection();
func_0203f058(17,M2C_FIELD(connA+i*4,s32*,0xf4),M2C_FIELD(connB+i*4,s32*,0x24),M2C_FIELD(conn+i*2,u16*,0xa4),0,0);
if(func_0204084c()) return;
}
mgr=gConnectionMgr;M2C_FIELD(mgr,u64*,24)=GetSystemTick();M2C_FIELD(mgr,u8*,2)=1;
}
#pragma pop
u32 func_02042f94(u32 a,u32 unused,u32 off){u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=9;off=code-10;break;case 2:code=9;off=code-11;break;case 3:code=6;off=code-16;break;case 4:code=6;off=code-26;break;}func_0203dc38(code,off+0xfffec398);return ret;}

u32 func_02043008(u32 a,u32 unused,u32 off){u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=6;off=code-56;break;case 2:code=6;off=code-36;break;case 3:code=6;off=code-26;break;case 4:code=6;off=code-46;break;case 5:code=9;off=code-10;break;case 6:code=9;off=code-11;break;}func_0203dc38(code,off+0xfffeb3f8);return ret;}

