/* 1 function from 0x0203F45C to 0x02040340 (main), found by ds-decomp. */
#include "common.h"
u64 U64Divide(u64,u64);
extern u8 *gConnectionMgr;
void *GetConnection(void);u64 GetSystemTick(void);

/* Handle one command sent by a peer on the current connection: the payload's
 * first word selects the command, the rest carries its arguments (peer ids,
 * addresses, slots or a tick).  The join handshake, the matchmaking and
 * address exchange, peer sync notices and the timer query/reply update the
 * connection session and report their result through the connection callbacks. */
int HandleConnectionCommand(int command,int peerId,int a,int b,s32 *payload,int count){
int n=0,i,j;u32 packet0;u32 packet[65];u8 addressBytes[8];void *p,*q;s64 ticks;
if(!GetConnection()||!M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE))return 1;
if(GetNetSessionState()==5&&M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==1&&peerId==M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS))ResetSlotRequestRetry();
switch(command){
/* Join request (1) and join reply (11): let the peer join the session, then
 * send the reply or store the joining member's address. */
case 1:case 11:
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)){a=payload[1];b=(u16)payload[2];}
count=ConnectionHandleJoin(peerId,a,b,payload[0],command==11);
if(count==2){
M2C_FIELD(GetConnection(),s32 *,476)=0;func_0204063c(peerId,a,b);if(ReportConnectionCommandResult())return 0;
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==2&&M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_CALLBACK)){p=GetConnection();i=GetSessionPlayerSlot(peerId);M2C_FIELD(p,void (**)(s32,s32),CONN_SESSION_PEER_CALLBACK)(i,M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_CALLBACK_DATA));}
packet[0]=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SLOT);
for(n=1;n<=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SLOT);n++)packet[n]=M2C_FIELD((u8 *)GetConnection()+((u32)n)*4,s32 *,CONN_SESSION_PEER_IDS);
packet[n++]=M2C_FIELD(GetConnection(),s32 *,28);packet[n++]=M2C_FIELD(GetConnection(),u16 *,26);SetConnectionState(11);
}else if(count==3&&M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_CAPACITY)){p=GetConnection();if(M2C_FIELD(p,u8 *,CONN_SESSION_SLOT)==M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_CAPACITY)&&M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==2){packet[0]=16;n=1;}}
if(count!=255){SendConnectionCommand(count,peerId,a,b,packet,n);if(ReportConnectionCommandResult())return 0;}
break;
/* Match assignment: store our match address and the joining members'
 * addresses, start matchmaking or connect to the other peers. */
case 2:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=4||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_JOIN_PEER)!=peerId)break;
M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SELF_ID)=0;M2C_FIELD(GetConnection(),u8 *,423)=0;M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_ATTEMPT_LIMIT)=0;M2C_FIELD(GetConnection(),s32 *,444)=0;
M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_DATA)=M2C_FIELD(payload+payload[0],s32 *,4);M2C_FIELD(GetConnection(),u16 *,CONN_SESSION_PEER_DATA_PORT)=M2C_FIELD(payload+payload[0],s32 *,8);M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_TARGET_ADDRESS)=M2C_FIELD(payload+payload[0],s32 *,4);M2C_FIELD(GetConnection(),u16 *,CONN_SESSION_TARGET_PORT)=M2C_FIELD(payload+payload[0],s32 *,8);
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==1){
if(AreAllConnectionMembers(payload+1,payload[0])){if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT))StoreConnectionCommand(peerId,payload);}
else{CancelJoinRequest(peerId);if(ReportConnectionCommandResult())return 0;TryConnectToPeer(0,0,peerId);if(ReportConnectionCommandResult())return 0;break;}}
if(!M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)){
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT)){StoreConnectionCommand(peerId,payload);DisconnectAllPeers();if(ReportConnectionCommandResult())return 0;}
SetConnectionState(6);func_0203ecb0(0,0,SBServerListGetServer(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SERVER_BROWSER),0));if(ReportPeerConnectResult())return 0;
}else{SetConnectionState(5);if(ReportMatchmakingResult(SendMatchmakingParameter(peerId)))return 0;}break;
/* Start the connection to the match's peers. */
case 3:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=4||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_JOIN_PEER)!=peerId)break;
if(count>0&&payload[0]==16){ReportConnectionError(13,0);return 0;}
return StartConnection(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_JOIN_PEER));
/* Peer connect result: advance the handshake timer or keep connecting. */
case 4:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=4||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_JOIN_PEER)!=peerId)break;
p=GetConnection();M2C_FIELD(p,u64 *,CONN_SESSION_ATTEMPT_TICK)=GetSystemTick();
if((M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SELF_ID)&&M2C_FIELD(GetConnection(),u8 *,423)<16)||M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==3){
M2C_FIELD(GetConnection(),s32 *,444)=1;p=GetConnection();M2C_FIELD(p,u64 *,448)=GetSystemTick();
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)!=3){p=GetConnection();M2C_FIELD(p,u8 *,423)++;}
}else{M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SELF_ID)=0;M2C_FIELD(GetConnection(),u8 *,423)=0;
if(!M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)){SetConnectionState(3);M2C_FIELD(GetConnection(),s32 *,232)=1;p=GetConnection();M2C_FIELD(p,u64 *,236)=GetSystemTick();}
else if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==1)TryConnectToPeer(1,0,0);
}break;
/* A peer connection closed. */
case 5:
if(!M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_ADDRESS_VALID)||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_MATCH_ADDRESS)!=peerId)break;
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==2&&M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT)==1&&M2C_FIELD(GetConnection(),s32 *,248)==peerId)GT2NotifyConnectionClosed(M2C_FIELD(M2C_FIELD(GetConnection(),void * *,4),s32 *,0));
if(!func_02040e1c(peerId))return 0;break;
/* A member joined: record its player id and peer address. */
case 6:
i=payload[0];j=(u16)payload[1];
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==1)SetConnectionState(6);
else if((M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=6&&M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=11)||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_MATCH_ADDRESS)!=peerId)break;
M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_LAST_COMMAND)=255;
p=GetConnection();if(M2C_FIELD((u8 *)p+(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT)+1)*4,s32 *,CONN_SESSION_PEER_IDS)!=peerId){p=GetConnection();M2C_FIELD((u8 *)p+(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT)+1)*4,s32 *,CONN_SESSION_PEER_IDS)=peerId;}
M2C_FIELD(addressBytes,u32 *,4)=i;M2C_FIELD(addressBytes,u16 *,2)=((j>>8)&255)|((j<<8)&0xff00);
M2C_FIELD(GetConnection(),u8 *,404)=1;i=GT2SocketHandle(M2C_FIELD(M2C_FIELD(GetConnection(),void * *,4),s32 *,0));p=GetConnection();OnPeerConnect(0,i,addressBytes,(u8 *)p+404);
p=GetConnection();M2C_FIELD(p,s32 *,CONN_SESSION_CONNECT_TICK)=0;M2C_FIELD(p,s32 *,400)=0;
break;
/* A member announced its address: reply whether it is a member. */
case 7:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=1||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS)!=peerId)break;
packet0=payload[0];j=(u8)payload[1];
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==1&&!M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_JOIN_FLAG)){packet[0]=IsConnectionMember(packet0);SendConnectionCommand(32,peerId,a,b,packet,1);if(ReportConnectionCommandResult())return 0;}
p=GetConnection();i=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SLOT)+1;M2C_FIELD((u8 *)p+i*4,s32 *,CONN_SESSION_PEER_IDS)=packet0;
p=GetConnection();i=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_SLOT)+1;M2C_FIELD((u8 *)p+i,u8 *,CONN_SESSION_PEER_SLOTS)=j;
Qr2_StateChanged(M2C_FIELD(GetConnection(),s32 *,16));
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_CALLBACK)){p=GetConnection();i=GetSessionPlayerSlot(packet0);M2C_FIELD(p,void (**)(s32,s32),CONN_SESSION_PEER_CALLBACK)(i,M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_CALLBACK_DATA));}break;
/* A member's address assignment, either for the next slot or a reply echo. */
case 8:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=1||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS)!=peerId)break;
packet0=payload[0];
if(!packet0){
count=payload[1];n=payload[2];M2C_FIELD((void *)(count+(u32)GetConnection()),u8 *,CONN_SESSION_PEER_SLOTS)=n;
p=GetConnection();M2C_FIELD((u8 *)p+count*4,s32 *,CONN_SESSION_PEER_IDS)=M2C_FIELD(GetConnection(),s32 *,512);ProcessConnectionStateAction(3);
}else{
count=payload[1];n=(u8)payload[2];
if(packet0==M2C_FIELD((u8 *)GetConnection()+count*4,s32 *,CONN_SESSION_PEER_IDS)&&count==M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT)-1){
p=GetConnection();q=GetConnection();SendConnectionCommand(9,peerId,M2C_FIELD(p,s32 *,CONN_SESSION_PEER_DATA),M2C_FIELD(q,u16 *,CONN_SESSION_PEER_DATA_PORT),&packet0,1);if(ReportConnectionCommandResult())return 0;
}else{
M2C_FIELD((u8 *)GetConnection()+count*4,s32 *,CONN_SESSION_PEER_IDS)=packet0;
M2C_FIELD((void *)(count+(u32)GetConnection()),u8 *,CONN_SESSION_PEER_SLOTS)=n;
M2C_FIELD((u8 *)GetConnection()+count*4,s32 *,CONN_SESSION_PEER_DATA)=payload[3];
M2C_FIELD((u8 *)GetConnection()+count*2,u16 *,CONN_SESSION_PEER_DATA_PORT)=payload[4];
M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_TARGET_ADDRESS)=payload[3];M2C_FIELD(GetConnection(),u16 *,CONN_SESSION_TARGET_PORT)=payload[4];
SetConnectionState(5);if(ReportMatchmakingResult(SendMatchmakingParameter(packet0)))return 0;M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_ATTEMPT_LIMIT)=0;M2C_FIELD(GetConnection(),s32 *,444)=0;
}}
break;
/* A member acknowledged its address assignment. */
case 9:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=13)break;
p=GetConnection();if(payload[0]!=M2C_FIELD((u8 *)p+(M2C_FIELD(GetConnection(),u8 *,420)+1)*4,s32 *,CONN_SESSION_PEER_IDS))break;
p=GetConnection();M2C_FIELD(p,u8 *,420)++;ProcessConnectionStateAction(0);break;
/* The match begins: store the host id and disconnect the others or start matchmaking. */
case 10:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=1&&M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=18)break;
if(!M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)||AreAllConnectionMembers(payload+1,payload[0])){M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SELF_ID)=payload[1];M2C_FIELD(GetConnection(),u8 *,423)=0;}else M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SELF_ID)=0;
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT))GT2NotifyConnectionClosed(M2C_FIELD(M2C_FIELD(GetConnection(),void * *,4),s32 *,0));else if(StartMatchmaking())return 0;
break;
/* A peer asked to reconnect or restart the connection. */
case 12:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS)!=peerId)break;
if(!M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)||M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==1){if(!RestartConnection(peerId))return 0;}
else if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)==3){M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_TARGET_ID)=peerId;CloseGt2Connection();RefreshConnection(0);}
break;
/* Peer synchronization notices (prepare, ack, done). */
case 13:case 14:case 15:if(!HandlePeerSyncNotice(peerId,command,payload[0]))return 0;break;
/* Members were dropped from the match. */
case 16:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS)!=peerId)return 1;
for(a=0;a<count;a++){i=FindPeerSlot(payload[a],0);if(i!=255)DisconnectPeerSlot(i);}break;
/* Timer query: tell the peer whether the timer interval elapsed. */
case 17:p=gConnectionMgr;
if(p&&M2C_FIELD(p,u8 *,0)){ticks=GetSystemTick()-M2C_FIELD(p,u64 *,16);if(U64Divide((u64)ticks<<6,0x82ea)>=M2C_FIELD(p,u32 *,4)){packet[0]=1;goto timer_ready;}}
packet[0]=0;
timer_ready:SendConnectionCommand(18,peerId,a,b,packet,1);if(ReportConnectionCommandResult())return 0;break;
/* Timer reply: record the peer's timer state. */
case 18:
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)!=19)break;
i=FindPeerSlot(peerId,0);if(i==255)break;
M2C_FIELD(gConnectionMgr,u32 *,8)|=1<<i;if(payload[0])M2C_FIELD(gConnectionMgr,u32 *,12)|=1<<i;break;
/* The peer reported a fatal connection error. */
case 19:ReportConnectionError(12,0);return 0;
/* Member status request: answer with our match address or flag the peer. */
case 32:
if(M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_MODE)!=1||M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_JOIN_FLAG))break;
for(n=1;n<=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT);n++){
if(M2C_FIELD((u8 *)GetConnection()+((u32)n)*4,s32 *,CONN_SESSION_PEER_IDS)==peerId){
if(!payload[0]){
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==11||M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_STATE)==12){SendMatchAddress();if(ReportConnectionCommandResult())return 0;}
if(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_NATNEG)){NatNeg_ReleasePeer(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_NATNEG));M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_NATNEG)=0;}
ReconnectUnlessServing();
}else{p=GetConnection();i=FindPeerSlot(peerId,0);M2C_FIELD(p,u32 *,476)|=1<<i;}
goto done;
}}
break;
/* Peer list query and its reply. */
case 64:
for(n=1;n<=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_PLAYER_COUNT);n++){
if(M2C_FIELD((u8 *)GetConnection()+((u32)n)*4,s32 *,CONN_SESSION_PEER_IDS)==peerId){n=0;SendConnectionCommand(65,peerId,a,b,0,0);if(ReportConnectionCommandResult())return 0;break;}
}break;
case 65:break;
default:break;
}
done:return 1;
}
