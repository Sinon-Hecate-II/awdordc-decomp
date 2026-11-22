/* 20 functions from 0x0205DA30 to 0x0205E95C (main), found by ds-decomp. */
#include "common.h"
#include "natneg.h"
#include "qr2.h"
#include "net_socket.h"

typedef struct { u8 bytes[6]; } NetworkAddress6;
typedef struct { NetworkAddress6 address; u8 type,length; u32 ip; u8 reserved,value,flag,addr[4],port[2]; char name[64]; } NetworkHandshakePacket;
typedef struct { u8 bytes[20]; } NetworkPacket20Bytes;
typedef struct { NetworkAddress6 address; u8 type, length; u32 ip, value; u16 port; u8 flag, mode; } NetworkPacket20;
typedef struct { u8 bytes[21]; } NetworkPacket21Bytes;
typedef struct { NetworkAddress6 address; u8 type, length; u32 ip; u8 reserved, value; u8 tail[7]; } NetworkPacket21;
extern NetworkAddress6 gNatNegMagic;

#pragma opt_propagation off
/* Build and send a NAT-negotiation connect-pong packet (kind 7) to the peer: the
 * six magic bytes, the packet type, the peer's address, its remote address and
 * byte-swapped port and its flag/mode bytes. The peer's deadline is pushed out
 * by 700 ms, its retry budget is set to 12 and its second flag is set when the
 * first one is. The register-bound locals reproduce the original allocation. */
void NatNeg_SendConnectPong(void *peer) {
    void func_0205d944(s32, s32, u16, void *, s32);
    s32 GetSystemTickMilliseconds(void);
    extern NetworkAddress6 gNatNegMagic;
    u8 packet[0x14];

    register u8 *pr1 asm("r1") = (u8 *)&gNatNegMagic;
    register s32 vr2 asm("r2");
    register u8 vr7 asm("r7");
    register u8 vr6 asm("r6");
    register u8 *vr8 asm("r8") = packet;
    register u8 vr5 asm("r5");
    register u8 vlr asm("lr");
    register u8 vr12 asm("r12");
    register u8 vr3 asm("r3");
    register void *vr4 asm("r4");

    vr7 = pr1[0];
    vr6 = pr1[1];
    vr5 = pr1[2];
    vlr = pr1[3];
    vr12 = pr1[4];
    vr3 = pr1[5];
    vr4 = peer;

    *vr8 = vr7;
    vr8[1] = vr6;
    vr8[2] = vr5;
    vr8[3] = vlr;
    vr8[4] = vr12;
    vr2 = 2;
    pr1 = (u8 *)7;
    packet[6] = (u8)vr2;
    packet[7] = (u8)pr1;
    vr8[5] = vr3;

    {
        u32 ip = M2C_FIELD(vr4, u32 *, NATNEG_PEER_ADDRESS);
        *(u32 *)(packet + 8) =
            ((ip >> 24) & 0xFFU) |
            ((ip >> 8) & 0xFF00U) |
            ((ip << 8) & 0xFF0000U) |
            ((ip << 24) & 0xFF000000U);
    }
    *(u32 *)(packet + 12) = M2C_FIELD(vr4, u32 *, NATNEG_PEER_REMOTE_IP);
    {
        u16 port = M2C_FIELD(vr4, u16 *, NATNEG_PEER_REMOTE_PORT);
        *(u16 *)(packet + 16) = (u16)((((s32)port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
    }
    packet[18] = M2C_FIELD(vr4, u8 *, NATNEG_PEER_FLAG32);
    packet[19] = (M2C_FIELD(vr4, s32 *, NATNEG_PEER_STATE) != 2) ? 1 : 0;

    {
        s32 val = M2C_FIELD(vr4, s32 *, NATNEG_PEER_SOCKET2);
        if (val == -1) {
            val = M2C_FIELD(vr4, s32 *, NATNEG_PEER_SOCKET);
        }
        func_0205d944(val, M2C_FIELD(vr4, s32 *, NATNEG_PEER_REMOTE_IP), M2C_FIELD(vr4, u16 *, NATNEG_PEER_REMOTE_PORT), packet, 0x14);
    }
    M2C_FIELD(vr4, s32 *, NATNEG_PEER_DEADLINE) = GetSystemTickMilliseconds() + 0x2BC;
    M2C_FIELD(vr4, s32 *, NATNEG_PEER_MAX_RETRIES) = 0xC;
    if (M2C_FIELD(vr4, u8 *, NATNEG_PEER_FLAG32) != 0) {
        M2C_FIELD(vr4, s8 *, NATNEG_PEER_FLAG33) = 1;
    }
}
#pragma opt_propagation reset
s32 func_0205dd98(M2C_UNK arg0) {
    void *ghiResolveHostname(M2C_UNK);
    s32 ghiInetAddr();
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0_2 = ghiInetAddr();
    if (temp_r0_2 != -1) {
        return temp_r0_2;
    }
    temp_r0 = ghiResolveHostname(arg0);
    if (temp_r0 == NULL) {
        return 0;
    }
    return **M2C_FIELD(temp_r0, s32 ***, 0xC);
}

s32 NatNeg_ResolveServerAddress(void *arg0, s32 arg1) {
 M2C_UNK func_020675bc(void *,s32,void *,void *,s32);
 extern M2C_UNK data_020ff894, gServiceNameBuffer;
 u8 buffer[0x80];
 if (arg0 == NULL) {
 func_020675bc(buffer,0x80,&data_020ff894,&gServiceNameBuffer,arg1);
 arg0=buffer;
 }
 return func_0205dd98((M2C_UNK)arg0);
}

/* Resolve the addresses of the two NAT-negotiation servers: look up each
 * server's host name, falling back to the built-in natneg1/natneg2 host names
 * when the manager has none.  Returns 1 once both are resolved, 0 when either
 * lookup failed. */
s32 NatNeg_ResolveServers(void) {
    extern M2C_UNK gNatNegManager, sNatNeg1HostName, sNatNeg2HostName;
    s32 NatNeg_ResolveServerAddress(void *, s32);

    if (M2C_FIELD(&gNatNegManager, s32 *, NATNEG_IP1) == 0)
        M2C_FIELD(&gNatNegManager, s32 *, NATNEG_IP1) = NatNeg_ResolveServerAddress(M2C_FIELD(&gNatNegManager, void **, NATNEG_HOST1), (s32)&sNatNeg1HostName);
    if (M2C_FIELD(&gNatNegManager, s32 *, NATNEG_IP2) == 0)
        M2C_FIELD(&gNatNegManager, s32 *, NATNEG_IP2) = NatNeg_ResolveServerAddress(M2C_FIELD(&gNatNegManager, void **, NATNEG_HOST2), (s32)&sNatNeg2HostName);
    if (M2C_FIELD(&gNatNegManager, s32 *, NATNEG_IP1) == 0 || M2C_FIELD(&gNatNegManager, s32 *, NATNEG_IP2) == 0) return 0;
    return 1;
}

#pragma scheduling off
extern void NatNeg_FreePeer(s32 *);
/* Start NAT negotiation for one peer: allocate its record, keep the socket the
 * reports go through, the peer address, the join flag and the three callbacks,
 * open the peer's own UDP socket and send the initial requests.  Returns 0 when
 * started, 1 when no peer record is free, 2 when the service-availability lookup
 * is not idle or the socket cannot be opened, and 3 while the NATNEG server names
 * are still being resolved (the caller retries). */
s32 NatNeg_BeginNegotiation(s32 reportSocket, s32 peerAddress, s32 isJoin, s32 event, s32 send, s32 data) {
    s32 ghiSocket(s32, s32, s32);
    void *NatNeg_NewPeer();
    void NatNeg_SendInitRequests(void *);
    s32 NatNeg_ResolveServers();
    extern s32 gDnsQueryState;
    void *peer;

    if (gDnsQueryState != DNS_QUERY_IDLE) {
        return 2;
    }
    if (NatNeg_ResolveServers() == 0) {
        return 3;
    }
    peer = NatNeg_NewPeer();
    if (peer == NULL) {
        return 1;
    }
    M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET2) = reportSocket;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_VALUE) = isJoin;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_ADDRESS) = peerAddress;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_EVENT) = event;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_SEND) = send;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_SEND_DATA) = data;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET) = ghiSocket(2, 2, 0);
    M2C_FIELD(peer, s32 *, NATNEG_PEER_RETRIES) = 0;
    M2C_FIELD(peer, s8 *, NATNEG_PEER_FLAG32) = 0;
    M2C_FIELD(peer, s8 *, NATNEG_PEER_FLAG33) = 0;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_REMOTE_IP) = 0;
    M2C_FIELD(peer, u16 *, NATNEG_PEER_REMOTE_PORT) = 0;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_MAX_RETRIES) = 0;
    if (M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET) == -1) {
        NatNeg_FreePeer(peer);
        return 2;
    }
    NatNeg_SendInitRequests(peer);
    return 0;
}
#pragma scheduling reset
void NatNeg_ReleasePeer(void) {
 void *FindNatNegPeer(void);
 void ghiCloseSocket(s32);
 void *p=FindNatNegPeer();
 if(p==NULL)return;
 if(M2C_FIELD(p,s32 *,0)!=-1) ghiCloseSocket(M2C_FIELD(p,s32 *,0));
 M2C_FIELD(p,s32 *,0)=-1;
 M2C_FIELD(p,s32 *,16)=4;
}

/* Polls one NAT-negotiation peer: drains its socket, retries the current step
   when the deadline passes, and releases the peer on completion or timeout. */
void UpdateNatNegPeer(void *peer) {
s32 ghiSocketCanRecv(s32); s32 ghiRecvFrom(s32,void *,s32,s32,void *,s32 *); void HandleNatNegPacket(u8 *,s32,M2C_UNK); s32 GetSystemTickMilliseconds(void); void NatNeg_SendInitRequests(); void NatNeg_SendConnectPong(void *);
extern u8 gNatNegRecvBuffer[];
u8 address[8]; s32 size=8; u8 reply[8]; s32 n;
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_DONE){NatNeg_FreePeer(peer);return;}
if(-1!=M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)){
do {
if(!ghiSocketCanRecv(M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)))break;
n=ghiRecvFrom(M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET),gNatNegRecvBuffer,512,0,address,&size);
if(n==-1)break;
HandleNatNegPacket(gNatNegRecvBuffer,n,(M2C_UNK)address);
} while(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)!=NATNEG_STATE_DONE && M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)!=-1);
}
if((M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_START || M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_CONNECT) && (u32)GetSystemTickMilliseconds()>M2C_FIELD(peer,u32 *,NATNEG_PEER_DEADLINE)){
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_RETRIES)>M2C_FIELD(peer,s32 *,NATNEG_PEER_MAX_RETRIES)){
M2C_FIELD(peer,M2C_UNK (**)(s32,s32,void *,s32),NATNEG_PEER_SEND)(2,-1,0,M2C_FIELD(peer,s32 *,NATNEG_PEER_SEND_DATA));
((void (*)(s32))NatNeg_ReleasePeer)(M2C_FIELD(peer,s32 *,NATNEG_PEER_ADDRESS));
}else{
M2C_FIELD(peer,s32 *,NATNEG_PEER_RETRIES)++;
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_START)((void (*)(void *))NatNeg_SendInitRequests)(peer);else NatNeg_SendConnectPong(peer);
}
}
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_REPORT && (u32)GetSystemTickMilliseconds()>M2C_FIELD(peer,u32 *,NATNEG_PEER_DEADLINE)){
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET2)==-1){
u16 port;
reply[1]=2;
port=M2C_FIELD(peer,u16 *,NATNEG_PEER_REMOTE_PORT);
*(u16 *)(reply+2)=((port>>8)&255)|((port<<8)&0xff00);
*(u32 *)(reply+4)=M2C_FIELD(peer,u32 *,NATNEG_PEER_REMOTE_IP);
M2C_FIELD(peer,M2C_UNK (**)(s32,s32,void *,s32),NATNEG_PEER_SEND)(0,M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET),reply,M2C_FIELD(peer,s32 *,NATNEG_PEER_SEND_DATA));
M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)=-1;
}
((void (*)(s32))NatNeg_ReleasePeer)(M2C_FIELD(peer,s32 *,NATNEG_PEER_ADDRESS));
}
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_ACKED && (u32)GetSystemTickMilliseconds()>M2C_FIELD(peer,u32 *,NATNEG_PEER_DEADLINE)){
M2C_FIELD(peer,M2C_UNK (**)(s32,s32,void *,s32),NATNEG_PEER_SEND)(1,-1,0,M2C_FIELD(peer,s32 *,NATNEG_PEER_SEND_DATA));
((void (*)(s32))NatNeg_ReleasePeer)(M2C_FIELD(peer,s32 *,NATNEG_PEER_ADDRESS));
}
}

void func_0205e178(void) {
    s32 Vector_GetCount();
    M2C_UNK Vector_GetItem(s32, s32);
    void UpdateNatNegPeer();
    extern M2C_UNK gNatNegManager;
    s32 var_r5;

    if (M2C_FIELD(&gNatNegManager, s32 *, 0x10) == 0) {
        return;
    }
    var_r5 = Vector_GetCount() - 1;
    if (var_r5 < 0) {
        return;
    }
    do {
        Vector_GetItem(M2C_FIELD(&gNatNegManager, s32 *, 0x10), var_r5);
        UpdateNatNegPeer();
        var_r5 -= 1;
    } while (var_r5 >= 0);
}

#pragma scheduling off
/* Answers a connect ping: builds a 21-byte connect ack (kind 6) holding the magic
 * bytes, the peer's address as its cookie and the low byte of its echoed value,
 * and sends it to the address the ping came from. */
M2C_UNK NatNeg_SendConnectAck(void *peer, M2C_UNK fromAddress) {
 void func_0205d944(s32,s32,u16,void *,s32);
 u8 packet[24];
 u8 *header=(u8 *)((NetworkAddress6 *)packet);
 const u8 *magic=(const u8 *)&gNatNegMagic;
 u8 m0,m1,m2,m3,m4,m5;
 u16 port;
 u32 ip;
 m0=magic[0];
 m1=magic[1];
 m2=magic[2];
 m3=magic[3];
 m4=magic[4];
 m5=magic[5];
 packet[NATNEG_PKT_VERSION]=NATNEG_PROTOCOL_VERSION;
 header[0]=m0;
 header[1]=m1;
 header[2]=m2;
 header[3]=m3;
 header[4]=m4;
 header[5]=m5;
 packet[NATNEG_PKT_KIND]=NATNEG_KIND_CONNECT_ACK;
 packet[NATNEG_PKT_ACK_VALUE]=M2C_FIELD(peer,s32 *,NATNEG_PEER_VALUE);
 ip=M2C_FIELD(peer,u32 *,NATNEG_PEER_ADDRESS);
 *(u32 *)(packet+NATNEG_PKT_PEER_ADDR)=((ip<<24)&0xff000000)|(((ip<<8)&0xff0000)|((u8)(ip>>24)|((ip>>8)&0xff00)));
 port=M2C_FIELD(fromAddress,u16 *,NATNEG_ADDR_PORT);
 func_0205d944(M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET),M2C_FIELD(fromAddress,s32 *,NATNEG_ADDR_IP),(u16)((u8)((s32)port>>8)|((port<<8)&0xff00)),packet,NATNEG_PKT_ACK_LEN);
 (void)packet;
}
#pragma scheduling reset
/* Handle a CONNECT_PING from another peer: when the sender is still in its connect
 * step (packet mode 0) answer it with a connect ack; then, unless the peer itself
 * has already moved past its connect step, either report the packet's mode as send
 * kind 1..3 and release the peer, or take the sender's address and port as the
 * peer's remote ones, clear the retries, move to the connect step and answer with
 * a connect pong. */
void NatNeg_HandleConnectPing(void *peer, void *packet, void *fromAddress) {
    void NatNeg_SendConnectPong(void *);
    void NatNeg_ReleasePeer(void);
    M2C_UNK NatNeg_SendConnectAck(void *, M2C_UNK);
    s32 kind;
    u16 port;
    u8 mode;
    if (M2C_FIELD(packet, u8 *, NATNEG_PKT_MODE) == 0) NatNeg_SendConnectAck(peer, (M2C_UNK)fromAddress);
    if (M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) >= NATNEG_STATE_CONNECT) return;
    mode = M2C_FIELD(packet, u8 *, NATNEG_PKT_MODE);
    if (mode) {
        kind = 3; if (mode == 1) kind = 1; else if (mode == 2) kind = 2;
        M2C_FIELD(peer, M2C_UNK (**)(s32, s32, s32, s32), NATNEG_PEER_SEND)(kind, -1, 0, M2C_FIELD(peer, s32 *, NATNEG_PEER_SEND_DATA));
        ((void (*)(s32))NatNeg_ReleasePeer)(M2C_FIELD(peer, s32 *, NATNEG_PEER_ADDRESS)); return;
    }
    M2C_FIELD(peer, s32 *, NATNEG_PEER_REMOTE_IP) = M2C_FIELD(packet, s32 *, NATNEG_PKT_PEER_IP);
    port = M2C_FIELD(packet, u16 *, NATNEG_PKT_PEER_PORT);
    M2C_FIELD(peer, s16 *, NATNEG_PEER_REMOTE_PORT) = (s16)(((u8)(port >> 8)) | ((port << 8) & 0xFF00));
    M2C_FIELD(peer, s32 *, NATNEG_PEER_RETRIES) = 0;
    M2C_FIELD(peer, M2C_UNK (**)(s32, s32), NATNEG_PEER_EVENT)(M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) = NATNEG_STATE_CONNECT, M2C_FIELD(peer, s32 *, NATNEG_PEER_SEND_DATA));
    NatNeg_SendConnectPong(peer);
}

/* NatNeg_HandleConnectPong: handles a CONNECT_PONG packet from a peer — records
   the packet's source address and port as the peer's remote address, then either
   re-sends a pong or, in the connect step, moves on to the report step and tells
   the send callback. */
void NatNeg_HandleConnectPong(void *peer, void *packet, void *fromAddress) {
    s32 GetSystemTickMilliseconds();
    void NatNeg_SendConnectPong(void *);
    s32 socket2;
    u16 port;

    if ((s32) M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) < NATNEG_STATE_CONNECT) {
        return;
    }
    M2C_FIELD(peer, s32 *, NATNEG_PEER_REMOTE_IP) = (s32) M2C_FIELD(fromAddress, s32 *, 4);
    port = M2C_FIELD(fromAddress, u16 *, 2);
    M2C_FIELD(peer, s16 *, NATNEG_PEER_REMOTE_PORT) = (s16) ((u8) ((s32) port >> 8) | ((port << 8) & 0xFF00));
    M2C_FIELD(peer, s8 *, NATNEG_PEER_FLAG32) = 1;
    if (M2C_FIELD(packet, u8 *, NATNEG_PKT_FLAG) == 0) {
        NatNeg_SendConnectPong(peer);
        return;
    }
    if (M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) == NATNEG_STATE_CONNECT) {
        if (M2C_FIELD(peer, u8 *, NATNEG_PEER_FLAG33) == 0) {
            NatNeg_SendConnectPong(peer);
        }
        M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) = NATNEG_STATE_REPORT;
        M2C_FIELD(peer, s32 *, NATNEG_PEER_DEADLINE) = (s32) (GetSystemTickMilliseconds() + 0x1388);
        socket2 = M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET2);
        if (socket2 == -1) {
            return;
        }
        M2C_FIELD(peer, M2C_UNK (**)(M2C_UNK, s32, void *, s32), NATNEG_PEER_SEND)(0, socket2, fromAddress, M2C_FIELD(peer, s32 *, NATNEG_PEER_SEND_DATA));
        return;
    }
    if (M2C_FIELD(packet, u8 *, NATNEG_PKT_MODE) != 0) {
        return;
    }
    NatNeg_SendConnectPong(peer);
}

/* Handles the two partner packets of the NAT negotiation: an INIT_ACK (kind 1)
   records which of the partner's three responses arrived, and once all of them
   have the peer moves on to its connect step (state 1, a 10 s deadline and an
   event 1 report); an ERT_TEST (kind 2) is answered by turning the packet into
   an ERT_ACK (kind 3) and sending it back to the peer's address and port. */
void NatNeg_HandleInitAndErt(void *peer, void *packet, void *fromAddress) {
    s32 GetSystemTickMilliseconds(void);
    void func_0205d944(s32, s32, u16, void *, s32);
    u8 kind;

    kind = M2C_FIELD(packet, u8 *, 7);
    switch (kind) {
        case NATNEG_KIND_INIT_ACK: {
            u8 response = M2C_FIELD(packet, u8 *, 0xC);
            if ((u32)response > 2U) {
                break;
            }
            M2C_FIELD((void *)((u8 *)peer + (response * 4)), s32 *, NATNEG_PEER_GOT0) = 1;
            if (M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) != 0) {
                break;
            }
            if (M2C_FIELD(peer, s32 *, NATNEG_PEER_GOT1) == 0) {
                break;
            }
            if (M2C_FIELD(peer, s32 *, NATNEG_PEER_GOT2) == 0) {
                break;
            }
            if (M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET2) != -1) {
                if (M2C_FIELD(peer, s32 *, NATNEG_PEER_GOT0) == 0) {
                    break;
                }
            }
            M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) = NATNEG_STATE_ACKED;
            M2C_FIELD(peer, s32 *, NATNEG_PEER_DEADLINE) = GetSystemTickMilliseconds() + 0x2710;
            M2C_FIELD(peer, void (**)(s32, s32), NATNEG_PEER_EVENT)(
                M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE), M2C_FIELD(peer, s32 *, NATNEG_PEER_SEND_DATA));
            break;
        }
        case NATNEG_KIND_ERT_TEST: {
            u16 port;
            u16 swapped;

            M2C_FIELD(packet, u8 *, 7) = NATNEG_KIND_ERT_ACK;
            port = M2C_FIELD(fromAddress, u16 *, 2);
            swapped = (u16)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
            func_0205d944(M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET), M2C_FIELD(fromAddress, s32 *, 4),
                          swapped, packet, 0x15);
            break;
        }
        default:
            break;
    }
}

/* Dispatches one received NAT-negotiation packet: checks the magic, copies the
   packet into a local 20- or 21-byte buffer according to its kind, looks the peer
   up by the (byte-swapped) source address and hands it to that kind's handler. */
void HandleNatNegPacket(u8 *packet,s32 length,M2C_UNK fromAddress) {
s32 IsNatNegPacket(M2C_UNK);
void *FindNatNegPeer(void);
u32 buf20[5];
u32 buf21[6];
s32 kind;
u32 sourceIp;
void *peer;
if(!IsNatNegPacket((M2C_UNK)packet))return;
kind=packet[7];
if(kind==NATNEG_KIND_CONNECT_PING||kind==NATNEG_KIND_CONNECT_PONG){
if(length<20)return;
*(NetworkPacket20Bytes *)buf20=*(NetworkPacket20Bytes *)packet;
sourceIp=*(u32 *)((u8 *)buf20+8);
peer=((void *(*)(u32))FindNatNegPeer)(((sourceIp>>24)&255)|((sourceIp>>8)&0xff00)|((sourceIp<<8)&0xff0000)|((sourceIp<<24)&0xff000000));
if(!peer)return;
if(kind==NATNEG_KIND_CONNECT_PING)NatNeg_HandleConnectPing(peer,&buf20,fromAddress);
else NatNeg_HandleConnectPong(peer,&buf20,fromAddress);
}else{
if(length<21)return;
*(NetworkPacket21Bytes *)buf21=*(NetworkPacket21Bytes *)packet;
sourceIp=*(u32 *)((u8 *)buf21+8);
peer=((void *(*)(u32))FindNatNegPeer)(((sourceIp>>24)&255)|((sourceIp>>8)&0xff00)|((sourceIp<<8)&0xff0000)|((sourceIp<<24)&0xff000000));
if(!peer)return;
NatNeg_HandleInitAndErt(peer,&buf21,fromAddress);
}
}

#pragma push
#pragma opt_strength_reduction off
/* Creates and fills a GameSpy QR2 connection record: allocates a 0x110-byte
 * record (or uses the static default when outConnection is NULL), stores the
 * socket, game/player names, local port, state callbacks and NAT-negotiation
 * flag, seeds the random local address bytes, refreshes the local IP list and
 * resolves the master server for the record's request id. Returns 0, or 3 when
 * the master server cannot be resolved. */
s32 Qr2_CreateConnection(u8 **outConnection, s32 socket, s32 localPort, s32 gameName, s32 playerName, s32 reportToMaster, s32 natNeg, s32 appendKeyCb, s32 appendIdx1Cb, s32 appendIdx2Cb, s32 collectKeysCb, s32 repeatCountCb, s32 eventCb, s32 context) {
    u8 *gpiMalloc(M2C_UNK);
    M2C_UNK GetSystemTickMilliseconds();
    M2C_UNK RefreshLocalIps();
    s32 ResolveHostAddress(s8 *, s32, void *, M2C_UNK);
    M2C_UNK StringFormat(s8 *, M2C_UNK *, s32);
    s32 Rand();
    M2C_UNK SetRandSeed();
    M2C_UNK StringCopy(void *, s32);
    extern M2C_UNK gQr2DefaultConnection;
    extern M2C_UNK gMasterHostFormat;
    extern s32 gLocalIpCount;
    extern s8 gMasterHostOverride;
    s8 hostBuf[64];
    u8 *temp_r0;

    s32 result;
    s32 clearIndex;
    s32 byteIndex;
    u8 *qr2;
    s8 *hostName;
    s8 hostOverride;
    s32 rnd;
    void *temp_r0_3;
    void *cellPtr;

    if (outConnection == NULL) {
        qr2 = (u8 *)&gQr2DefaultConnection;
    } else {
        qr2 = *outConnection = gpiMalloc(0x110);
    }
    GetSystemTickMilliseconds();
    SetRandSeed();
    StringCopy(qr2 + QR2_GAMENAME, gameName);
    StringCopy(qr2 + 0x44, playerName);
    M2C_FIELD(qr2, s32 *, QR2_LOCAL_PORT) = localPort;
    byteIndex = 0;
    M2C_FIELD(qr2, s32 *, QR2_LAST_SENT) = 0;
    M2C_FIELD(qr2, s32 *, QR2_LAST_POLL) = 0;
    M2C_FIELD(qr2, s32 *, QR2_SOCKET) = socket;
    M2C_FIELD(qr2, s32 *, 0xB8) = 1;
    M2C_FIELD(qr2, s32 *, QR2_CTX) = context;
    M2C_FIELD(qr2, s32 *, QR2_CB_APPEND_KEY) = appendKeyCb;
    M2C_FIELD(qr2, s32 *, QR2_CB_APPEND_IDX1) = appendIdx1Cb;
    M2C_FIELD(qr2, s32 *, QR2_CB_APPEND_IDX2) = appendIdx2Cb;
    M2C_FIELD(qr2, s32 *, QR2_CB_COLLECT_KEYS) = collectKeysCb;
    M2C_FIELD(qr2, s32 *, QR2_CB_REPEAT_COUNT) = repeatCountCb;
    M2C_FIELD(qr2, s32 *, 0x9C) = eventCb;
    M2C_FIELD(qr2, s32 *, 0xA0) = 0;
    M2C_FIELD(qr2, s32 *, 0xA4) = 0;
    M2C_FIELD(qr2, s32 *, 0xD4) = 0;
    M2C_FIELD(qr2, s32 *, 0xBC) = reportToMaster;
    M2C_FIELD(qr2, s32 *, 0xC4) = 0;
    M2C_FIELD(qr2, s32 *, QR2_NATNEG) = natNeg;
    M2C_FIELD(qr2, s32 *, QR2_PUBLIC_IP) = 0;
    M2C_FIELD(qr2, s16 *, QR2_PUBLIC_PORT) = 0;
    M2C_FIELD(qr2, s32 *, QR2_CB_PUBLIC_ADDRESS) = 0;
    M2C_FIELD(qr2, s32 *, QR2_STATE_DIRTY) = 0;
    do {
        rnd = Rand();
        cellPtr = qr2 + byteIndex;
        byteIndex += 1;
        M2C_FIELD(cellPtr, s8 *, QR2_LOCAL_IP) = rnd % 255;
    } while (byteIndex < 4);
    clearIndex = 0;
    do {
        ((s32 *)qr2)[clearIndex+54] = -1;
        clearIndex += 1;
    } while (clearIndex < 0xA);
    M2C_FIELD(qr2, s32 *, 0x100) = 0;
    if (gLocalIpCount == 0) {
        RefreshLocalIps();
    }
    if (reportToMaster != 0) {
        hostOverride = gMasterHostOverride;
        if (hostOverride == 0) {
            StringFormat(hostBuf, &gMasterHostFormat, gameName);
        }
        if (hostOverride != 0) {
            hostName = &gMasterHostOverride;
        } else {
            hostName = hostBuf;
        }
        result = ResolveHostAddress(hostName, 0x6CFC, qr2 + QR2_REQUEST_ID, 0);
    } else {
        result = 1;
    }
    if (result == 0) {
        return 3;
    }
    return 0;
}
#pragma pop
void func_0205e834(void *arg0, s32 arg1) {
    extern void *gQr2Connection;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = gQr2Connection;
    }
    M2C_FIELD(var_r0, s32 *, 0xA0) = arg1;
}

void func_0205e84c(void *arg0, s32 arg1) {
    extern void *gQr2Connection;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = gQr2Connection;
    }
    M2C_FIELD(var_r0, s32 *, 0xA4) = arg1;
}

void func_0205e864(void *arg0, s32 arg1) {
 extern void *gQr2Connection;
 if (arg0 == NULL) arg0 = gQr2Connection;
 M2C_FIELD(arg0,s32 *,0xA8)=arg1;
}

void Qr2_Think(void *p) {
 extern void *gQr2Connection;
 void func_0205e95c(void *);
 void Qr2_ReadPackets(void *);
 if(p==NULL)p=gQr2Connection;
 if(M2C_FIELD(p,s32 *,0xbc))func_0205e95c(p);
 Qr2_ReadPackets(p);
}

/* Drain the QR2 socket: while it has data, receive one reply from the master into
   gQr2RecvBuffer, NUL-terminate it and hand it to Qr2_HandlePacket. The record only
   reads replies while its +0xC4 field is set. */
void Qr2_ReadPackets(void *qr2) {
    s32 ghiSocketCanRecv(s32);
    s32 ghiRecvFrom(s32, void *, s32, s32, void *, s32 *);
    void Qr2_HandlePacket(void *, void *, s32, void *);
    extern u8 gQr2RecvBuffer[];
    u8 fromAddress[8];
    s32 fromLength = 8;
    s32 length;

    if (M2C_FIELD(qr2, s32 *, 0xC4) == 0) return;
    if (ghiSocketCanRecv(M2C_FIELD(qr2, s32 *, QR2_SOCKET)) == 0) return;
    do {
        length = ghiRecvFrom(M2C_FIELD(qr2, s32 *, QR2_SOCKET), gQr2RecvBuffer, QR2_RECV_MAX, 0, fromAddress, &fromLength);
        if (length != -1) {
            gQr2RecvBuffer[length] = 0;
            Qr2_HandlePacket(qr2, gQr2RecvBuffer, length, fromAddress);
        }
    } while (ghiSocketCanRecv(M2C_FIELD(qr2, s32 *, QR2_SOCKET)) != 0);
}
#pragma push
#pragma opt_propagation off
#pragma scheduling on
void NatNeg_SendInitRequests(void *arg0) {
s32 GetPreferredLocalIp(void); s32 func_0205d9fc(s32); s32 GetSystemTickMilliseconds(void);
void func_0205d944(s32,s32,u16,void *,s32);
s32 StringCopy(void *,s32); s32 StringLength(void *);
extern M2C_UNK gServiceNameBuffer,gNatNegManager;
union { NetworkHandshakePacket header; u8 bytes[88]; } packet; NetworkHandshakePacket *p=&packet.header; u8 *buf=packet.bytes;
u32 ip,a,b,c,d;
s32 len,sock,pa,pb;
u16 port;
{
u8 a0=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[0],a1=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[1],a2=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[2],a3=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[3],a4=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[4],a5=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[5];
p->address.bytes[0]=a0;p->address.bytes[1]=a1;p->address.bytes[2]=a2;p->address.bytes[3]=a3;p->address.bytes[4]=a4;p->address.bytes[5]=a5;
p->length=0;
}
p->type=2;
p->value=M2C_FIELD(arg0,s32 *,12);
ip=M2C_FIELD(arg0,u32 *,8);
p->ip=((ip>>24)&255)|((ip>>8)&0xff00)|((ip<<8)&0xff0000)|((ip<<24)&0xff000000);
p->flag=M2C_FIELD(arg0,s32 *,4)!=(s32)(p->length-1);
a=GetPreferredLocalIp();b=GetPreferredLocalIp();c=GetPreferredLocalIp();d=GetPreferredLocalIp();
ip=((c>>24)&255)|((d>>8)&0xff00)|((b<<8)&0xff0000)|((a<<24)&0xff000000);
packet.bytes[15]=ip>>24;packet.bytes[16]=ip>>16;packet.bytes[17]=ip>>8;packet.bytes[18]=ip;
packet.bytes[19]=0;packet.bytes[20]=0;
StringCopy(packet.bytes+21,(s32)&gServiceNameBuffer);
len=StringLength(&gServiceNameBuffer)+22;
if(p->flag && M2C_FIELD(arg0,s32 *,20)==0){
buf[12]=0;func_0205d944(M2C_FIELD(arg0,s32 *,4),M2C_FIELD(&gNatNegManager,s32 *,12),0x6cfd,buf,len);
}
if(M2C_FIELD(arg0,s32 *,24)==0){
buf[12]=1;func_0205d944(M2C_FIELD(arg0,s32 *,0),M2C_FIELD(&gNatNegManager,s32 *,12),0x6cfd,buf,len);
}
sock=p->flag?M2C_FIELD(arg0,s32 *,4):M2C_FIELD(arg0,s32 *,0);
pa=func_0205d9fc(p->flag?M2C_FIELD(arg0,s32 *,4):M2C_FIELD(arg0,s32 *,0));
pb=func_0205d9fc(sock);
port=((pa>>8)&255)|((pb<<8)&0xff00);
packet.bytes[20]=port;packet.bytes[19]=port>>8;
if(M2C_FIELD(arg0,s32 *,28)==0){
buf[12]=2;func_0205d944(M2C_FIELD(arg0,s32 *,0),M2C_FIELD(&gNatNegManager,s32 *,8),0x6cfd,buf,len);
}
M2C_FIELD(arg0,s32 *,40)=GetSystemTickMilliseconds()+500;
M2C_FIELD(arg0,s32 *,36)=30;

}
#pragma pop
