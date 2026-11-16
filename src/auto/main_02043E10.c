/* 35 functions from 0x02043E10 to 0x02044E04 (main), found by ds-decomp. */
#include "common.h"
void MI_CpuCopy8(void *,void *,s32);
s32 GetConnection(void);
void SetConnectionState(s32);

/* Peer socket-connect callback: event 0 (re)starts the connect to the peer
   described by addr (address at +4, port at +2) and gives it a session slot; a
   nonzero event is the connect's error or timeout code.  On success the session
   advances (func_02040e1c); otherwise the attempt is retried while its retry
   budget lasts, and the peer is dropped when it fails.  attempt is the
   connection's in-flight connect record. */
void OnPeerConnect(s32 event, s32 socketHandle, PeerAddress *addr, ConnAttempt *attempt)
{
    M2C_UNK func_02040e1c(M2C_UNK);
    s32 func_0200567c(void *, s32, void *, s32);
    s32 func_0205d4d8(s32, s32, s32);
    s32 func_0205adcc(s32, s32, s32, void *, s32, s32, s32, s32);
    void func_02043230(void);
    s32 func_020431e0(s32);
    s32 func_02041038(s32);
    s32 func_0203ef9c(void *);
    s32 func_02043184();
    u64 GetSystemTick(void);
    extern M2C_UNK data_020fc908;

    u8 buf[12];
    void *sessionA;
    void *sessionB;
    void *sessionC;
    s32 kind;
    s32 res;
    s32 slot;
    u16 port;

    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) != 6 && M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) != 0xB) {
        return;
    }
    if (attempt == 0) {
        return;
    }
    if (event == 0) {
        attempt->natNeg = 0;
        M2C_FIELD(GetConnection(), u8 *, 0x14)++;
        slot = M2C_FIELD(GetConnection(), u8 *, 0x14);
        if (attempt->isJoin != 0) {
            M2C_FIELD(GetConnection() + slot * 4, s32 *, CONN_SESSION_PEER_IPS) = addr->address;
            port = addr->port;
            M2C_FIELD(GetConnection() + slot * 2, u16 *, CONN_SESSION_PEER_PORTS) = (u16)((u8)((s32)port >> 8) | ((port << 8) & 0xFF00));
            M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TARGET_NOTICES) = 0;
            M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_CONNECT_TARGET) = 0;
            sessionA = GetConnection();
            M2C_FIELD(sessionA, s32 *, CONN_SESSION_JOIN_TICK) = 0;
            M2C_FIELD(sessionA, s32 *, 0x188) = 0;
            if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 0xB) {
                SetConnectionState(0xC);
            } else {
                SetConnectionState(7);
            }
            M2C_FIELD(GetConnection(), u8 *, 0xC) = 0;
            func_0200567c(buf, 12, &data_020fc908, M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_QR2_PARAM));
            sessionA = GetConnection();
            sessionB = GetConnection();
            sessionC = GetConnection();
            res = func_0205d4d8(M2C_FIELD(sessionB + slot * 4, s32 *, CONN_SESSION_PEER_IPS), M2C_FIELD(sessionC + slot * 2, u16 *, CONN_SESSION_PEER_PORTS), 0);
            res = func_0205adcc(*M2C_FIELD(sessionA, s32 **, 4), 0, res, buf, -1, 5000, M2C_FIELD(GetConnection(), s32 *, 8), 0);
            if (res == 1) {
                func_02043230();
                return;
            }
            if (res == 0) {
                return;
            }
            if (func_02040e1c(M2C_FIELD(GetConnection() + slot * 4, s32 *, CONN_SESSION_PEER_IDS)) == 0) {
                return;
            }
            return;
        } else {
            if (addr != 0) {
                res = slot - 1;
                M2C_FIELD(GetConnection() + res * 4, s32 *, CONN_SESSION_PEER_IPS) = addr->address;
                port = addr->port;
                M2C_FIELD(GetConnection() + res * 2, u16 *, CONN_SESSION_PEER_PORTS) = (u16)((u8)((s32)port >> 8) | ((port << 8) & 0xFF00));
            }
            sessionA = GetConnection();
            M2C_FIELD(sessionA, u64 *, CONN_SESSION_CONNECT_TICK) = GetSystemTick();
            SetConnectionState(7);
            return;
        }
    } else {
        if (attempt->natNeg == 0) {
            return;
        }
        kind = func_020431e0(event);
        if (kind != 2 && kind != 1) {
            return;
        }
        if (attempt->isJoin == 0) {
            if (kind == 1 || (kind == 2 && attempt->retries >= 1)) {
                attempt->natNeg = 0;
                if (func_020441e8(0) == 0) {
                    return;
                }
                sessionA = GetConnection();
                sessionB = GetConnection();
                if (func_02041038(M2C_FIELD(sessionA + M2C_FIELD(sessionB, u8 *, CONN_SESSION_PLAYER_COUNT) * 4, s32 *, CONN_SESSION_PEER_IDS)) == 0) {
                    return;
                }
                return;
            } else {
                attempt->retries++;
                func_0203ef9c(attempt);
                if (func_02043184() == 0) {
                    return;
                }
                return;
            }
        } else {
            sessionA = GetConnection();
            M2C_FIELD(sessionA, u64 *, CONN_SESSION_JOIN_TICK) = GetSystemTick();
            if (kind != 1) {
                if (kind != 2) {
                    return;
                }
                if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TARGET_NOTICES) < 1) {
                    return;
                }
            }
        }
        attempt->natNeg = 0;
        if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 3 || M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 2) {
            if (func_020441e8(1) == 0) {
                return;
            }
        } else {
            if (func_020441e8(0) == 0) {
                return;
            }
        }
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TARGET_NOTICES) = 0;
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_CONNECT_TARGET) = 0;
        sessionA = GetConnection();
        M2C_FIELD(sessionA, s32 *, CONN_SESSION_JOIN_TICK) = 0;
        M2C_FIELD(sessionA, s32 *, 0x188) = 0;
        sessionA = GetConnection();
        sessionB = GetConnection();
        if (func_02040e1c(M2C_FIELD(sessionA + (M2C_FIELD(sessionB, u8 *, CONN_SESSION_PLAYER_COUNT) + 1) * 4, s32 *, CONN_SESSION_PEER_IDS)) == 0) {
            return;
        }
        return;
    }
}

s32 func_020441e8(s32 arg0) {
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    void *temp_r0;

    if (arg0 != 0) {
        return 1;
    }
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) != 3) {
        temp_r0 = GetConnection();
        M2C_FIELD(temp_r0, u8 *, 0x17D) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x17D) + 1);
    }
    if ((M2C_FIELD(GetConnection(), u8 *, 0x15) == 3) || ((u32) M2C_FIELD(GetConnection(), u8 *, 0x17D) >= 5U)) {
        func_0203dc38(6, 0xFFFEAE6C);
        return 0;
    }
    return 1;
}

void SetActiveConnection(s32 arg0) {
    extern M2C_UNK gConnectionMgr;
    M2C_FIELD(&gConnectionMgr, s32 *, 4) = arg0;
}

s32 GetConnection(void) {
    extern M2C_UNK gConnectionMgr;
    return M2C_FIELD(&gConnectionMgr, s32 *, 4);
}

void SetConnectionState(s32 arg0) {
 extern M2C_UNK gConnectionMgr;
 M2C_FIELD(M2C_FIELD(&gConnectionMgr, void **, 4), s32 *, 0x1A0) = arg0;
}

void func_0204428c(M2C_UNK arg0) {
    M2C_UNK CanStartTransfer(M2C_UNK, M2C_UNK);
    CanStartTransfer(arg0, 1);
}

s32 CanStartTransfer(M2C_UNK arg0, s32 arg1) {
    s32 HasNetError();
    s32 IsConnectionActive(M2C_UNK);
    s32 func_020391b8(M2C_UNK);
    s32 func_020446e8(s32);
    s32 IsTransferSending(M2C_UNK);
    s32 temp_r4;

    if ((HasNetError() != 0) || ((arg1 == 1) && (IsConnectionActive(arg0) == 0)) || (func_020391b8(arg0) == 0)) {
        return 0;
    }
    if (IsTransferSending(arg0) == 1) {
        return 0;
    }
    temp_r4 = GetSendSpace(arg0);
    if (temp_r4 >= func_020446e8(arg1)) {
        return 1;
    }
    return 0;
}

s32 func_0204431c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK SendTransfer(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return SendTransfer(1, arg0, arg1, arg2);
}

/* Start sending `size` bytes from `buffer` to `channel` as a transfer of `kind`:
 * queue the outgoing buffer in the connection's slot, send the 8-byte header
 * and as much of the payload as the link has room for. */
s32 SendTransfer(s32 kind,s32 channel,s32 buffer,s32 size) {
extern s32 gTransferManager;
void *GetTransferSlot(s32);
void BuildTransferHeader(void *,s16,s32);
void SendConnectionData(s32,s32,s32,s32);
TransferSlot *slot;
s32 chunk, total;
u32 header[2];
void (*callback)(s32,s32);
slot=GetTransferSlot(channel);
if(!CanStartTransfer(channel,kind)) return 0;
slot->sending=1;
slot->outData=buffer;
slot->outSent=0;
slot->outSize=size;
((void (*)(void *,s32,s32))BuildTransferHeader)(header,kind,size);
SendConnectionData(channel,(s32)header,8,1);
chunk=((TransferManager *)gTransferManager)->chunkSize;
if(size<=chunk)chunk=size;
if(chunk>GetSendSpace(channel))return 1;
SendConnectionData(channel,buffer,chunk,1);
slot->outSent+=chunk;
total=slot->outSize;
if(slot->outSent==total) {
slot->sending=0;
slot->outData=0;
slot->outSent=0;
slot->outSize=0;
callback=((TransferManager *)gTransferManager)->onSent;
if(callback && kind==1) callback(total,channel);
}
return 1;
}

s32 func_0204445c(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 var_r10;
 s32 var_r6;
 u8 var_r9;
 var_r6 = arg0;
 var_r9 = 0;
 do {
  if (var_r9 != 0) var_r10 = 1 << var_r9;
  else var_r10 = 1;
  if ((var_r6 & var_r10) && (var_r9 != GetLocalPlayerId()) && (func_0204431c(var_r9, arg1, arg2) == 0)) var_r6 &= ~var_r10;
  var_r9 += 1;
 } while ((u32)var_r9 < 0x20U);
 return var_r6;
}

s32 func_020444cc(u8 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 HasNetError(void);
 s32 IsConnectionActive(M2C_UNK);
 void SendConnectionData(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
 extern s32 gTransferManager;
 void (*callback)(s32, M2C_UNK);
 if (HasNetError() != 0) return 0;
 if (IsConnectionActive(arg0) == 0) return 0;
 if (arg2 > M2C_FIELD(gTransferManager, u16 *, 0x610)) return 0;
 SendConnectionData(arg0, arg1, arg2, 0);
 callback = M2C_FIELD(gTransferManager, void (**)(s32, M2C_UNK), 0x600);
 if (callback != NULL) callback(arg2, arg0);
 return 1;
}

s32 func_0204455c(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_020444cc(u8, M2C_UNK, M2C_UNK);
    s32 var_r10;
    s32 var_r6;
    u8 var_r9;

    var_r6 = arg0;
    var_r9 = 0;
    do {
        if (var_r9 != 0) {
            var_r10 = 1 << var_r9;
        } else {
            var_r10 = 1;
        }
        if ((var_r6 & var_r10) && (var_r9 != GetLocalPlayerId()) && (func_020444cc(var_r9, arg1, arg2) == 0)) {
            var_r6 &= ~var_r10;
        }
        var_r9 += 1;
    } while ((u32) var_r9 < 0x20U);
    return var_r6;
}

s32 func_020445cc(s32 a,s32 b,s32 c){void *GetTransferSlot();void *p=GetTransferSlot(a);if(func_02044a24(a)==2)return 0;M2C_FIELD(p,s32 *,4)=b;M2C_FIELD(p,s32 *,8)=c;M2C_FIELD(p,u8 *,0x1d)=1;M2C_FIELD(p,s32 *,0x10)=0;M2C_FIELD(p,s32 *,0x18)=0;return 1;}

s32 func_02044618(s32 a){extern s32 gTransferManager;if(!gTransferManager)return 0;M2C_FIELD(gTransferManager,s32 *,0x600)=a;return 1;}

s32 func_02044638(s32 a){extern s32 gTransferManager;if(!gTransferManager)return 0;M2C_FIELD(gTransferManager,s32 *,0x604)=a;return 1;}

s32 func_02044658(u16 a){extern s32 gTransferManager;if(!gTransferManager)return 0;M2C_FIELD(gTransferManager,u16 *,0x610)=a;return 1;}

void BuildTransferHeader(void *arg0, s16 arg1, s32 arg2) {
    M2C_UNK func_02068d18(s32, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTransferMagic;
    func_02068d18(arg0 + 6, &gTransferMagic, 2);
    M2C_FIELD(arg0, s16 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0) = arg2;
}

u16 func_020446ac(void *a){void MI_CpuCopy8(void *,void *,s32);s32 ByteCompareN(void *,void *,s32);extern M2C_UNK gTransferMagic;u16 buf[4];MI_CpuCopy8(a,buf,8);if(ByteCompareN(&buf[3],&gTransferMagic,2)==0)return buf[2];return 0;}

s32 func_020446e8(s32 a){switch(a){case 2:case 3:case 4:return 12;default:return 8;}}

void func_02044708(s32 a){extern s32 gTransferManager;void MI_CpuFill8(s32,s32,s32);gTransferManager=a;MI_CpuFill8(a,0,0x614);M2C_FIELD(gTransferManager,u16 *,0x610)=0x5b9;}

void func_02044744(s32 a,s32 b,s32 c,s32 d){extern s32 gTransferManager;void func_02044a68(s32,s32,s32);void func_02044b5c(s32,s32,s32);if(!gTransferManager)return;if(!b||!c)return;if(d)func_02044a68(a,b,c);else func_02044b5c(a,b,c);}

void func_02044780(s32 a,s32 b){extern s32 gTransferManager;s32 func_020390b4(s32);s32 c;if(!M2C_FIELD(gTransferManager,s32 *,0x60c))return;c=func_020390b4(a);M2C_FIELD(gTransferManager,void (**)(s32,s32),0x60c)(b,c);}

/* Per-frame poll of the transfer slots: time out idle connections and send the
 * next chunk of each outgoing buffer whose destination has room. */
void UpdateTransferSlots(void) {
extern s32 gTransferManager;
s32 GetActiveConnectionList(u8 **);s32 IsConnectionActive(s32);void *GetTransferSlot(s32);
u64 GetSystemTick(void);u64 func_02072088(u64,u64);
s32 GetLocalPlayerId(void);s32 IsTransferSending(s32);s32 GetSendSpace();
void SendConnectionData(s32,s32,s32,s32);
u8 *list; s32 connectionCount,index,playerId; void *p; void *q; s32 chunk; s32 total; u64 now;
if(!gTransferManager)return;
connectionCount=GetActiveConnectionList(&list);
for(index=0;index<connectionCount;index++){
playerId=list[index];
if(IsConnectionActive(playerId)){
p=GetTransferSlot(playerId);
if(((TransferManager *)gTransferManager)->onTimeout && ((TransferSlot *)p)->timeoutMs){
now=GetSystemTick();
if((u32)func_02072088((now-((TransferSlot *)p)->lastTick)<<6,TICKS_TO_MS_DIVISOR)>((TransferSlot *)p)->timeoutMs){
((TransferManager *)gTransferManager)->onTimeout(playerId);
((TransferSlot *)p)->lastTick=now;
}}
}
if(playerId!=GetLocalPlayerId() && IsTransferSending(playerId)==1){
q=GetTransferSlot(playerId);
chunk=((TransferManager *)gTransferManager)->chunkSize;
if(((TransferSlot *)q)->outSize-((TransferSlot *)q)->outSent<=chunk)chunk=((TransferSlot *)q)->outSize-((TransferSlot *)q)->outSent;
if(GetSendSpace(playerId)>=chunk){
SendConnectionData(playerId,((TransferSlot *)q)->outData+((TransferSlot *)q)->outSent,chunk,1);
((TransferSlot *)q)->outSent+=chunk;
total=((TransferSlot *)q)->outSize;
if(((TransferSlot *)q)->outSent==total){
((TransferSlot *)q)->sending=0;((TransferSlot *)q)->outData=0;
((TransferSlot *)q)->outSent=0;((TransferSlot *)q)->outSize=0;
if(((TransferManager *)gTransferManager)->onSent)((TransferManager *)gTransferManager)->onSent(total,playerId);
}}}
}
}

void func_02044954(s32 a){extern s32 gTransferManager;if(!gTransferManager)return;M2C_FIELD(gTransferManager+a*0x30,s32 *,0xc)=0;M2C_FIELD(gTransferManager+a*0x30,s32 *,0x10)=0;M2C_FIELD(gTransferManager+a*0x30,s32 *,0x14)=0;M2C_FIELD(gTransferManager+a*0x30,s32 *,0x18)=0;M2C_FIELD(gTransferManager+a*0x30,u8 *,0x1c)=0;if(((u8 *)(gTransferManager+0x1d))[a*0x30])((u8 *)(gTransferManager+0x1d))[a*0x30]=1;M2C_FIELD(gTransferManager+a*0x30,u16 *,0x22)=0;}

void func_020449dc(void) {
    extern s32 gTransferManager;
    gTransferManager = 0;
}

void *GetTransferSlot(s32 a){extern s32 gTransferManager;return (void *)(gTransferManager+0x30*a);}

s32 IsTransferSending(s32 a){extern s32 gTransferManager;return M2C_FIELD(gTransferManager+0x30*a,u8 *,0x1c);}

s32 func_02044a24(s32 a){extern s32 gTransferManager;return M2C_FIELD(gTransferManager+0x30*a,u8 *,0x1d);}

void SendConnectionData(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 FindPlayerConnection(M2C_UNK);
 void func_0205af48(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 func_0205af48(FindPlayerConnection(arg0), arg1, arg2, arg3);
}

/* Handle an inbound transfer request for slot `a`: dispatch by the slot's state. */
void func_02044a68(s32 a, s32 b, s32 c) {
    extern s32 gTransferManager;
    s32 func_020390b4(s32);
    s32 func_02044a24(s32);
    u16 func_020446ac(void *);
    void func_02044da4(M2C_UNK, M2C_UNK);
    void func_02044bf8(s32, s32, s32);
    void func_02044cc0(s32, void *, s32);
    void SetNetError(s32, s32);

    s32 id = func_020390b4(a);
    u32 kind;

    switch (func_02044a24(id)) {
    case 0:
        kind = func_020446ac((void *)b);
        if (kind < 2) return;
        if (kind > 4) return;
        func_02044bf8(id, b, c);
        break;
    case 1:
        func_02044bf8(id, b, c);
        break;
    case 2:
        func_02044cc0(id, (void *)b, c);
        break;
    case 3:
        ((void (*)(s32, s32, s32))func_02044da4)(id, b, c);
        break;
    case 4:
        M2C_FIELD(gTransferManager + id * 0x30, u8 *, 0x1d) = 1;
        M2C_FIELD(gTransferManager + id * 0x30, s32 *, 0x10) = 0;
        M2C_FIELD(gTransferManager + id * 0x30, s32 *, 0x18) = 0;
        break;
    default:
        SetNetError(6, 0xfffe82b6);
        break;
    }
}

void func_02044b5c(s32 a,s32 b,s32 c){extern s32 gTransferManager;s32 func_020390b4(s32);void MI_CpuCopy8(void *,void *,s32);u64 GetSystemTick(void);s32 i;void *p;void *q;void (*cb)(s32,void *,s32);i=func_020390b4(a);p=(void *)(gTransferManager+i*0x30);q=M2C_FIELD(p,void **,4);if(!q)return;if(M2C_FIELD(p,s32 *,8)<c)return;MI_CpuCopy8((void *)b,q,c);cb=M2C_FIELD(gTransferManager,void (**)(s32,void *,s32),0x604);if(cb)cb(i,M2C_FIELD(p,void **,4),c);if(!M2C_FIELD(gTransferManager,s32 *,0x608)||!M2C_FIELD(p,s32 *,0x2c))return;M2C_FIELD(p,u64 *,0x24)=GetSystemTick();}

void func_02044bf8(s32 a,s32 b,s32 c) {
extern s32 gTransferManager;
void *p; s32 v; u8 buf[8];
p=(u8 *)gTransferManager+a*0x30;
M2C_FIELD(p,u8 *,0x1e)=func_02044a24(a);
v=func_020446ac(b);
switch(v){
case 1:
if(c!=8)return;
MI_CpuCopy8(b,buf,8);
M2C_FIELD(p,s32 *,0x18)=*(s32 *)buf;
M2C_FIELD(p,s32 *,0x10)=0;
if(!M2C_FIELD(p,s32 *,4))goto state3;
if(M2C_FIELD(p,s32 *,8)>=M2C_FIELD(p,s32 *,0x18)) M2C_FIELD(p,u8 *,0x1d)=2;
else goto state4;
break;
state4: M2C_FIELD(p,u8 *,0x1d)=4;
break;
case 2:case 3:case 4:
state3: M2C_FIELD(p,u8 *,0x1d)=3;break;
}
M2C_FIELD(p,u16 *,0x22)=v;
}

void func_02044cc0(s32 a,void *b,s32 c){
extern s32 gTransferManager; s32 func_02044a24(s32); void MI_CpuCopy8(void *,void *,s32);void SetNetError(s32,s32);u64 GetSystemTick(void);
void *p;void (*cb)(s32,void *,s32);s32 pos,len;
p=(void *)(gTransferManager+a*0x30);
if(func_02044a24(a)==2){
pos=M2C_FIELD(p,s32 *,0x10);
if(pos+c>M2C_FIELD(p,s32 *,8)){SetNetError(6,0xfffe82ac);return;}
MI_CpuCopy8(b,M2C_FIELD(p,u8 **,4)+pos,c);
}
M2C_FIELD(p,s32 *,0x10)+=c;
len=M2C_FIELD(p,s32 *,0x18);
if(M2C_FIELD(p,s32 *,0x10)==len){
M2C_FIELD(p,u8 *,0x1d)=1;M2C_FIELD(p,s32 *,0x10)=0;M2C_FIELD(p,s32 *,0x18)=0;
cb=M2C_FIELD(gTransferManager,void (**)(s32,void *,s32),0x604);
if(cb)cb(a,M2C_FIELD(p,void **,4),len);
}
if(!M2C_FIELD(gTransferManager,s32 *,0x608)||!M2C_FIELD(p,s32 *,0x2c))return;
M2C_FIELD(p,u64 *,0x24)=GetSystemTick();
}

void func_02044da4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK ReceiveConnectionPacket(M2C_UNK, u16, M2C_UNK);
    void *GetTransferSlot();
    u16 temp_r1;
    void *temp_r0;

    temp_r0 = GetTransferSlot();
    M2C_FIELD(temp_r0, u8 *, 0x1D) = (u8) M2C_FIELD(temp_r0, u8 *, 0x1E);
    temp_r1 = M2C_FIELD(temp_r0, u16 *, 0x22);
    if ((temp_r1 != 2) && (temp_r1 != 3) && (temp_r1 != 4)) {
        return;
    }
    ReceiveConnectionPacket(arg0, temp_r1, arg1);
}

s32 GetSendSpace(void) {
    M2C_UNK FindPlayerConnection();
    s32 func_0205b038();
    s32 var_r0;

    FindPlayerConnection();
    var_r0 = func_0205b038() + 0xFFFFFDF9;
    if (var_r0 <= 0) {
        var_r0 = 0;
    }
    return var_r0;
}

