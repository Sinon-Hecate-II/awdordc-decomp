/* 16 functions from 0x0201BDE0 to 0x0201CB4C (main), found by ds-decomp. */
#include "common.h"

void *TcpFindConnection(s32 a,s32 b) {
 s32 func_0201bd2c(s32,s32,void *);
 extern M2C_UNK gSocketManager;
 void *q;
 void *p=M2C_FIELD(&gSocketManager,void **,8);
 while(p) {
 q=M2C_FIELD(p,void **,0xa4);
 if(q && M2C_FIELD(q,s32 *,0) && func_0201bd2c(a,b,q))return q;
 p=M2C_FIELD(p,void **,0x68);
 }
 return NULL;
}

void func_0201be44(void *a,void *b) {
 s32 n,t;
 u8 *p;
 M2C_FIELD(b,u16 *,46)=536;
 p=(u8 *)a+20;
 t=M2C_FIELD(a,u8 *,12)&240;
 n=((s32)(t+((u32)(t>>1)>>30))>>2)-20;
 while(n--) {
 u8 c=*p++;
 if(c==0)return;
 if(c==1)continue;
 if(c==2) {u8 h=p[1],l=p[2];p+=3;n-=3;M2C_FIELD(b,u16 *,46)=l|(h<<8);}
 else {t=p[0]-1;n-=t;p+=t;}
 }
}

s32 func_0201bec8(s32 arg0) {
    s32 GetIpNextHop();
    s32 FindArpMacAddress();
    if (GetIpNextHop() == 0) {
        return 1;
    }
    return FindArpMacAddress();
}

M2C_UNK func_0201bee4(M2C_UNK a,M2C_UNK b,M2C_UNK c) {
 extern M2C_UNK gSocketManager,data_021374f8;
 if(func_0201bec8(M2C_FIELD(a,s32 *,28)) || M2C_FIELD(&gSocketManager,void **,4)!=&data_021374f8) {
 TcpSendSegment(0,0,a,b,c);return;
 }
 SendArpRequest(GetIpNextHop(M2C_FIELD(a,s32 *,28)));
}

void TcpSendAck(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0201bee4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0201bee4(arg0, 0x10, arg1);
}

void TcpSendFinAck(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0201bee4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0201bee4(arg0, 0x11, arg1);
}

/* Reply to an unacceptable TCP segment with a reset.  The reset is built in the
 * stack's global reset connection gTcpResetConn (which gTcpResetSocket and
 * gNetStack's peer address alias): its ports are the offending segment's ports
 * swapped and its destination address is the packet's source.  A segment that
 * carried ACK is answered with a bare RST whose sequence is the segment's
 * acknowledgement number; any other segment gets a RST|ACK that acknowledges
 * the segment's sequence number plus its length (plus one for SYN or FIN). */
M2C_UNK TcpSendReset(M2C_UNK ipHeader,M2C_UNK seg,s32 len,M2C_UNK arg){
extern M2C_UNK gTcpResetSocket,gTcpResetConn,gNetStack;
void MI_CpuFill8(void *,s32,s32);
u16 dstPort,srcPort,ipSrcLo,ipSrcHi,ackLo,ackHi,seqLo,seqHi; s32 ackNum;void *conn=&gTcpResetConn;
MI_CpuFill8(conn,0,100);
dstPort=M2C_FIELD(seg,u16 *,2);M2C_FIELD(&gTcpResetSocket,u16 *,78)=((s32)dstPort>>8)|(dstPort<<8);
srcPort=M2C_FIELD(seg,u16 *,0);M2C_FIELD(&gTcpResetSocket,u16 *,92)=((s32)srcPort>>8)|(srcPort<<8);
ipSrcLo=M2C_FIELD(ipHeader,u16 *,14);ipSrcHi=M2C_FIELD(ipHeader,u16 *,12);
M2C_FIELD(&gNetStack,u32 *,352)=((u16)(((s32)ipSrcHi>>8)|(ipSrcHi<<8))<<16)|(u16)(((s32)ipSrcLo>>8)|(ipSrcLo<<8));
if(M2C_FIELD(seg,u8 *,13)&16){
ackLo=M2C_FIELD(seg,u16 *,10);ackHi=M2C_FIELD(seg,u16 *,8);
M2C_FIELD(conn,u32 *,TCP_CONN_SEND_SEQ)=((u16)(((s32)ackHi>>8)|(ackHi<<8))<<16)|(u16)(((s32)ackLo>>8)|(ackLo<<8));
func_0201bee4((s32)conn,4,arg);return;
}
M2C_FIELD(conn,s32 *,TCP_CONN_SEND_SEQ)=0;
seqLo=M2C_FIELD(seg,u16 *,6);seqHi=M2C_FIELD(seg,u16 *,4);
ackNum=len+(((u16)(((s32)seqHi>>8)|(seqHi<<8))<<16)|(u16)(((s32)seqLo>>8)|(seqLo<<8)));
M2C_FIELD(conn,s32 *,TCP_CONN_ACK_NUM)=ackNum;
if(M2C_FIELD(seg,u8 *,13)&3)M2C_FIELD(conn,s32 *,TCP_CONN_ACK_NUM)=ackNum+1;
func_0201bee4((s32)conn,20,arg);
}

/* Answers an incoming segment on a connection in SYN_RCVD (a SYN segment):
 * fills the socket with its SYN_ACK state, the tick it was sent at, the peer
 * address/port and the sequence numbers (the peer's sequence plus one in
 * TCP_CONN_ACK_NUM), copies the connection's SYN options into the reply and
 * sends it as segment type 18 with no flags. */
M2C_UNK func_0201c0bc(void *ipHeader,void *seg,void *conn){
u64 GetSystemTick(void);
u16 dstPortLo,dstPortHi,srcLo,srcHi,peerLo,peerHi,seqLo,seqHi;
u64 tick;
M2C_FIELD(conn,u8 *,SOCKET_STATE)=TCP_STATE_SYN_RCVD;tick=GetSystemTick();M2C_FIELD(conn,u32 *,16)=tick>>16;
dstPortLo=M2C_FIELD(ipHeader,u16 *,18);dstPortHi=M2C_FIELD(ipHeader,u16 *,16);
M2C_FIELD(conn,u32 *,SOCKET_LOCAL_ADDR)=((u16)(((s32)dstPortHi>>8)|(dstPortHi<<8))<<16)|(u16)(((s32)dstPortLo>>8)|(dstPortLo<<8));
seqLo=M2C_FIELD(seg,u16 *,0);M2C_FIELD(conn,u16 *,SOCKET_PEER_PORT)=((s32)seqLo>>8)|(seqLo<<8);
srcLo=M2C_FIELD(ipHeader,u16 *,14);srcHi=M2C_FIELD(ipHeader,u16 *,12);
M2C_FIELD(conn,u32 *,SOCKET_PEER_ADDR)=((u16)(((s32)srcHi>>8)|(srcHi<<8))<<16)|(u16)(((s32)srcLo>>8)|(srcLo<<8));
peerLo=M2C_FIELD(seg,u16 *,6);peerHi=M2C_FIELD(seg,u16 *,4);
M2C_FIELD(conn,u32 *,TCP_CONN_ACK_NUM)=(((u16)(((s32)peerHi>>8)|(peerHi<<8))<<16)|(u16)(((s32)peerLo>>8)|(peerLo<<8)))+1;
func_0201be44(seg,conn);func_0201bee4((s32)conn,18,0);
}

s32 func_0201c1a8(s32 a,s32 b,s32 c) {
 void *p=TcpFindConnection(a,b);
 u8 v;
 if(p) {
 v=M2C_FIELD(p,u8 *,8);
 if(v==1)func_0201c0bc(a,b,p);
 else if((u8)(v+253)<=1) {M2C_FIELD(p,s32 *,40)--;func_0201c0bc(a,b,p);}
 else TcpSendReset(a,b,c,0);
 return 1;
 }
 return 0;
}

void TcpProcessSyn(void *arg0, void *arg1, s32 arg2) {
s32 func_0201bb68(s32,s32);s32 func_0201c1a8(s32,s32,s32);void *func_0201bc58();M2C_UNK func_0201c0bc();M2C_UNK TaskYield();
u16 a,b,c,d;u32 p0,p1;void *r;
a=M2C_FIELD(arg0,u16 *,0x12);b=M2C_FIELD(arg0,u16 *,0x10);c=M2C_FIELD(arg0,u16 *,0xe);d=M2C_FIELD(arg0,u16 *,0xc);
p0=((u32)(u16)((d>>8)|(d<<8))<<16)|(u16)((c>>8)|(c<<8));p1=((u32)(u16)((b>>8)|(b<<8))<<16)|(u16)((a>>8)|(a<<8));
if(!func_0201bb68(p0,p1))return;if(func_0201c1a8((s32)arg0,(s32)arg1,arg2))return;
r=func_0201bc58(arg0,arg1);if(r){func_0201c0bc(arg0,arg1,r);return;}TaskYield();r=func_0201bc58(arg0,arg1);if(r)func_0201c0bc(arg0,arg1,r);
}

/* Build a response packet from a received request and mark it ready. */
void TcpProcessSynAck(s32 a,void *b,s32 c) {
void *p=TcpFindConnection(a,(s32)b);u16 d,e,f,g,h;
if(!p || M2C_FIELD(p,u8 *,8)!=2){TcpSendReset(a,b,c,0);return;}
TaskYield();
d=M2C_FIELD(b,u16 *,6);e=M2C_FIELD(b,u16 *,4);
M2C_FIELD(p,u32 *,36)=(((u16)(((s32)e>>8)|(e<<8))<<16)|(u16)(((s32)d>>8)|(d<<8)))+1;
f=M2C_FIELD(b,u16 *,10);g=M2C_FIELD(b,u16 *,8);
M2C_FIELD(p,u32 *,48)=((u16)(((s32)g>>8)|(g<<8))<<16)|(u16)(((s32)f>>8)|(f<<8));
h=M2C_FIELD(b,u16 *,14);M2C_FIELD(p,u16 *,44)=((s32)h>>8)|(h<<8);
func_0201be44(b,p);TcpSendAck(p,0);M2C_FIELD(p,u8 *,8)=4;
if(M2C_FIELD(p,s32 *,4)==1){M2C_FIELD(p,s32 *,4)=0;TaskWake(M2C_FIELD(p,s32 *,0));}
}

/* Consume one incoming TCP segment for an established connection: track the
 * ACK number, copy the payload into the receive buffer and drive the
 * connection state machine, sending the ACK / FIN / RST it calls for. */
void TcpProcessAck(void *net, void *seg, s32 len) {
  void *TcpFindConnection(s32, s32);
  void TcpSendAck(M2C_UNK, M2C_UNK);
  void TcpSendFinAck(M2C_UNK, M2C_UNK);
  M2C_UNK TcpSendReset(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
  M2C_UNK TaskWake(M2C_UNK);
  M2C_UNK TaskYield();
  M2C_UNK OS_DisableInterrupts();
  M2C_UNK OS_RestoreInterrupts(M2C_UNK);
  M2C_UNK MI_CpuCopy8(void *, s32, u32);
  void *conn;
  u16 seqLo, seqHi, ackLo, ackHi, window;
  u8 tcpFlags;
  u32 value, space;
  s32 isComplete;

  conn = TcpFindConnection((s32)net, (s32)seg);
  if (conn == NULL) {
    TcpSendReset(net, seg, len, 0);
    return;
  }

  ackLo = M2C_FIELD(seg, u16 *, 0xa);
  ackHi = M2C_FIELD(seg, u16 *, 0x8);
  value = ((u32)(u16)(((s32)ackHi >> 8) | (ackHi << 8)) << 16) | (u16)(((s32)ackLo >> 8) | (ackLo << 8));
  tcpFlags = M2C_FIELD(seg, u8 *, 0xd);
  if ((s32)(value - M2C_FIELD(conn, u32 *, 0x30)) > 0) {
    M2C_FIELD(conn, u32 *, 0x30) = value;
  }

  seqLo = M2C_FIELD(seg, u16 *, 0x6);
  seqHi = M2C_FIELD(seg, u16 *, 0x4);
  value = ((u32)(u16)(((s32)seqHi >> 8) | (seqHi << 8)) << 16) | (u16)(((s32)seqLo >> 8) | (seqLo << 8));
  if (M2C_FIELD(conn, u8 *, 0x8) == TCP_STATE_ESTABLISHED && M2C_FIELD(conn, u32 *, 0x24) != value) {
    TcpSendAck(conn, 0);
    return;
  }

  window = M2C_FIELD(seg, u16 *, 0xe);
  M2C_FIELD(conn, u16 *, 0x2c) = (u16)(((s32)window >> 8) | (window << 8));

  switch (M2C_FIELD(conn, u8 *, 0x8)) {
  case TCP_STATE_CLOSED:
  case TCP_STATE_SYN_SENT:
    TcpSendReset(net, seg, len, 0);
    break;
  case TCP_STATE_SYN_RCVD:
    M2C_FIELD(conn, u8 *, 0x8) = TCP_STATE_ESTABLISHED;
    if (M2C_FIELD(conn, s32 *, 0x4) == 1) {
      M2C_FIELD(conn, s32 *, 0x4) = 0;
      TaskWake(M2C_FIELD(conn, s32 *, 0));
    }
    if (len == 0) break;
  case TCP_STATE_ESTABLISHED: {
    M2C_UNK irq;
    M2C_FIELD(conn, u32 *, 0x34)++;
    space = M2C_FIELD(conn, u32 *, 0x3c) - M2C_FIELD(conn, u32 *, 0x44);
    if ((u32)len > space) {
      isComplete = 0;
      len = space;
    } else {
      isComplete = 1;
    }
    if (len != 0) {
      irq = OS_DisableInterrupts();
      MI_CpuCopy8((u8 *)seg + (((u8)M2C_FIELD(seg, u8 *, 0xc) & 0xf0) / 4),
                  M2C_FIELD(conn, u32 *, 0x40) + M2C_FIELD(conn, u32 *, 0x44), (u32)len);
      M2C_FIELD(conn, u32 *, 0x44) += (u32)len;
      M2C_FIELD(conn, u32 *, 0x24) += (u32)len;
      OS_RestoreInterrupts(irq);
      if (M2C_FIELD(conn, s32 *, 0x4) == 2) {
        M2C_FIELD(conn, s32 *, 0x4) = 0;
        TaskWake(M2C_FIELD(conn, s32 *, 0));
      }
    }
    if (isComplete && (tcpFlags & TCP_FLAG_FIN)) {
      M2C_FIELD(conn, u8 *, 0x8) = TCP_STATE_LAST_ACK;
      M2C_FIELD(conn, u32 *, 0x24)++;
      TcpSendFinAck(conn, 0);
      if (len == 0 && M2C_FIELD(conn, s32 *, 0x4) == 2) {
        M2C_FIELD(conn, s32 *, 0x4) = 0;
        TaskWake(M2C_FIELD(conn, s32 *, 0));
      }
    } else if (len != 0) {
      TcpSendAck(conn, 0);
    }
    break;
  }
  case TCP_STATE_FIN_WAIT1:
  case TCP_STATE_FIN_WAIT2:
    if (tcpFlags & TCP_FLAG_FIN) {
      M2C_FIELD(conn, u32 *, 0x24) += (u32)len + 1;
      TcpSendAck(conn, 0);
      M2C_FIELD(conn, u8 *, 0x8) = TCP_STATE_CLOSED;
      if (M2C_FIELD(conn, s32 *, 0x4) == 2) {
        M2C_FIELD(conn, s32 *, 0x4) = 0;
        TaskWake(M2C_FIELD(conn, s32 *, 0));
      }
    } else {
      if (len != 0) {
        M2C_FIELD(conn, u32 *, 0x24) += (u32)len;
        TcpSendAck(conn, 0);
      }
      M2C_FIELD(conn, u8 *, 0x8) = TCP_STATE_FIN_WAIT2;
    }
    break;
  case TCP_STATE_LAST_ACK:
  case TCP_STATE_TIME_WAIT:
    M2C_FIELD(conn, u8 *, 0x8) = TCP_STATE_CLOSED;
    if (M2C_FIELD(conn, s32 *, 0x4) == 2) {
      M2C_FIELD(conn, s32 *, 0x4) = 0;
      TaskWake(M2C_FIELD(conn, s32 *, 0));
    }
    break;
  default:
    if (tcpFlags & TCP_FLAG_FIN) {
      M2C_FIELD(conn, u32 *, 0x24)++;
    }
    TcpSendAck(conn, 0);
    break;
  }
  TaskYield();
}

void TcpProcessFin(s32 arg0, s32 arg1, s32 arg2) {
    void *TcpFindConnection(s32, s32);
    void TcpSendAck(M2C_UNK, M2C_UNK);
    void TcpSendFinAck(M2C_UNK, M2C_UNK);
    M2C_UNK TcpSendReset(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK TaskWake(M2C_UNK);
    void *p;
    u8 v;
    p = TcpFindConnection(arg0, arg1);
    if (p == NULL) return;
    v = M2C_FIELD(p, u8 *, 8);
    switch (v) {
    case 7:
        M2C_FIELD(p, s32 *, 0x24)++;
        TcpSendAck(p, 0);
        M2C_FIELD(p, u8 *, 8) = 9;
        break;
    case 8:
        M2C_FIELD(p, s32 *, 0x24)++;
        TcpSendAck(p, 0);
        M2C_FIELD(p, u8 *, 8) = 0;
        if (M2C_FIELD(p, s32 *, 4) == 2) {
            M2C_FIELD(p, s32 *, 4) = 0;
            TaskWake(M2C_FIELD(p, M2C_UNK *, 0));
        }
        break;
    case 4:
        M2C_FIELD(p, s32 *, 0x24)++;
        TcpSendFinAck(p, 0);
        M2C_FIELD(p, u8 *, 8) = 6;
        break;
    default:
        TcpSendReset(arg0, arg1, arg2, 0);
        break;
    }
}

void TcpProcessReset(s32 a,s32 b) {
    M2C_UNK TaskWake(s32);
    M2C_UNK TaskYield();
    void *TcpFindConnection();
    void *temp_r0;

    temp_r0 = TcpFindConnection();
    if (temp_r0 == NULL) {
        return;
    }
    TaskYield();
    M2C_FIELD(temp_r0, s8 *, 8) = 0;
    if ((u32) (M2C_FIELD(temp_r0, s32 *, 4) - 1) > 1U) {
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 4) = 0;
    TaskWake(M2C_FIELD(temp_r0, s32 *, 0));
}

/* Dispatch one received TCP segment: verify its checksum, subtract the header
 * length from the payload length, then hand it to the handler for its flags. */
void TcpReceiveSegment(void *ipHeader,void *seg,s32 length){
s32 IsTransportChecksumBad(void *,s32,void *,s32);
void TcpProcessAck(void *,void *,s32);
s32 headerLength,kind;u8 flags;
if(IsTransportChecksumBad(seg,length,ipHeader,IP_PROTO_TCP))return;
headerLength=M2C_FIELD(seg,u8 *,12)&240;
flags=M2C_FIELD(seg,u8 *,13);
kind=flags&23;
length-=(headerLength/4);
switch(kind){
case TCP_FLAG_SYN:if(flags&(TCP_FLAG_PSH|TCP_FLAG_URG))return;TcpProcessSyn(ipHeader,seg,length);return;
case (TCP_FLAG_SYN|TCP_FLAG_ACK):if(flags&(TCP_FLAG_PSH|TCP_FLAG_URG))return;TcpProcessSynAck((s32)ipHeader,seg,length);return;
case (TCP_FLAG_FIN|TCP_FLAG_ACK):case TCP_FLAG_ACK:TcpProcessAck(ipHeader,seg,length);return;
case TCP_FLAG_FIN:TcpProcessFin((s32)ipHeader,(s32)seg,length);return;
default:if(flags&TCP_FLAG_RST){TcpProcessReset((s32)ipHeader,(s32)seg);return;}TcpSendReset(ipHeader,seg,length,0);return;
}
}

#pragma opt_common_subs off
#pragma opt_propagation off
/* Receives one UDP datagram: finds the listening socket with the matching local
 * and peer port, binds its peer address on first contact, copies the payload into
 * its receive buffer and wakes the waiting task or calls its data callback. */
void UdpReceiveDatagram(void *ipHeader, void *datagram, s32 length) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK MI_CpuCopy8(void *, s32, u32);
    s32 IsTransportChecksumBad(void *, s32, void *, M2C_UNK);
    extern M2C_UNK gSocketManager;
    s32 (*dataCallback)(s32, u32, void *);
    void *socket;
    s32 socketPeerAddr;
    s32 irq;
    u16 ipSrcLo;
    u16 udpSrcPort2;
    u16 udpSrcPort;
    u16 ipDstLo;
    u16 ipSrcHi2;
    u16 udpDstPort;
    u16 socketPeerPort;
    u16 ipDstHi;
    u16 ipSrcLo2;
    u16 ipSrcHi;
    u32 payloadLength;
    u32 rxCapacity;
    void *node;

    if ((M2C_FIELD(datagram, u16 *, 6) != 0) && (IsTransportChecksumBad(datagram, length, ipHeader, 0x11) != 0)) {
        return;
    }
    irq = OS_DisableInterrupts();
    node = M2C_FIELD(&gSocketManager, void **, 8);
    if (node != NULL) {
loop_5:
        socket = M2C_FIELD(node, void **, 0xA4);
        if ((socket != NULL) && (M2C_FIELD(socket, s32 *, SOCKET_OWNER) != 0)) {
            if ((M2C_FIELD(socket, u8 *, SOCKET_STATE) == SOCKET_STATE_UDP_LISTEN) && (udpDstPort = M2C_FIELD(datagram, u16 *, 2), (M2C_FIELD(socket, u16 *, SOCKET_LOCAL_PORT) == (u16) (((s32)udpDstPort >> 8) | (udpDstPort << 8)))) && ((socketPeerPort = M2C_FIELD(socket, u16 *, SOCKET_PEER_PORT), (socketPeerPort == 0)) || (udpSrcPort = M2C_FIELD(datagram, u16 *, 0), (socketPeerPort == (u16) (((s32)udpSrcPort >> 8) | (udpSrcPort << 8)))))) {
                socketPeerAddr = M2C_FIELD(socket, s32 *, SOCKET_PEER_ADDR);
                if ((socketPeerAddr != 0) && (socketPeerAddr != -1)) {
                    ipSrcLo = M2C_FIELD(ipHeader, u16 *, 0xE);
                    ipSrcHi = M2C_FIELD(ipHeader, u16 *, 0xC);
                    if (socketPeerAddr == (((u16)(((s32)ipSrcHi >> 8) | (ipSrcHi << 8)) << 0x10) | (u16)(((s32)ipSrcLo >> 8) | (ipSrcLo << 8)))) {
                        goto block_18;
                    }
                    goto block_30;
                }
block_18:
                ipDstHi = M2C_FIELD(ipHeader, u16 *, 0x12);
                ipDstLo = M2C_FIELD(ipHeader, u16 *, 0x10);
                M2C_FIELD(socket, s32 *, SOCKET_LOCAL_ADDR) = (s32)(((u16)(((s32)ipDstLo >> 8) | (ipDstLo << 8)) << 0x10) | (u16)(((s32)ipDstHi >> 8) | (ipDstHi << 8)));
                if (M2C_FIELD(socket, s32 *, SOCKET_PEER_ADDR) == 0) {
                    ipSrcLo2 = M2C_FIELD(ipHeader, u16 *, 0xE);
                    ipSrcHi2 = M2C_FIELD(ipHeader, u16 *, 0xC);
                    M2C_FIELD(socket, s32 *, SOCKET_PEER_ADDR) = (s32)(((u16)(((s32)ipSrcHi2 >> 8) | (ipSrcHi2 << 8)) << 0x10) | (u16)(((s32)ipSrcLo2 >> 8) | (ipSrcLo2 << 8)));
                    udpSrcPort2 = M2C_FIELD(datagram, u16 *, 0);
                    M2C_FIELD(socket, u16 *, SOCKET_PEER_PORT) = (u16)(((s32)udpSrcPort2 >> 8) | (udpSrcPort2 << 8));
                }
                if (M2C_FIELD(socket, u32 *, SOCKET_RX_LENGTH) == 0) {
                    rxCapacity = M2C_FIELD(socket, u32 *, SOCKET_RX_CAP);
                    payloadLength = length - 8;
                    if (payloadLength > rxCapacity) {
                        M2C_FIELD(socket, u32 *, SOCKET_RX_LENGTH) = rxCapacity;
                    } else {
                        M2C_FIELD(socket, u32 *, SOCKET_RX_LENGTH) = payloadLength;
                    }
                    MI_CpuCopy8(datagram + 8, M2C_FIELD(socket, s32 *, SOCKET_RX_BUFFER), M2C_FIELD(socket, u32 *, SOCKET_RX_LENGTH));
                    if (M2C_FIELD(socket, s32 *, SOCKET_TASK_STATE) == 3) {
                        M2C_FIELD(socket, s32 *, SOCKET_TASK_STATE) = 0;
                        TaskWake(M2C_FIELD(socket, s32 *, SOCKET_OWNER));
                    } else {
                        dataCallback = M2C_FIELD(socket, s32 (**)(s32, u32, void *), SOCKET_DATA_CB);
                        if (dataCallback != NULL) {
                            if (dataCallback(M2C_FIELD(socket, s32 *, SOCKET_RX_BUFFER), M2C_FIELD(socket, u32 *, SOCKET_RX_LENGTH), socket) != 0) {
                                M2C_FIELD(socket, u32 *, SOCKET_RX_LENGTH) = 0U;
                            }
                        }
                    }
                }
            } else {
                goto block_30;
            }
        } else {
block_30:
            node = M2C_FIELD(node, void **, 0x68);
            if (node != NULL) {
                goto loop_5;
            }
        }
    }
    OS_RestoreInterrupts(irq);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
