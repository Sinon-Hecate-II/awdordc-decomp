/* 30 functions from 0x0201CB4C to 0x0201DB20 (main), found by ds-decomp. */
#include "common.h"
#include "net_socket.h"
#include "tcp_socket.h"

#pragma scheduling off
void *IpReassemblePacket(void *packet,s32 *done){
extern u8 data_021375b8[];extern s32 gNetStack;u64 GetSystemTick(void);void MI_CpuCopy8(void *,void *,u32);
u16 id;u32 head;u8 *freeSlot=0,*slot;u32 covered;u32 offset,end,ip,finalEnd;u32 flags,len,i,count;u16 a,b,t;u32 first;
*done=0;t=M2C_FIELD(packet,u16 *,6);flags=(u16)(((s32)t>>8)|(t<<8));
if(!(flags&0x3fff))return packet;
a=M2C_FIELD(packet,u16 *,14);b=M2C_FIELD(packet,u16 *,12);first=M2C_FIELD(packet,u8 *,0);
b=(u16)(((s32)b>>8)|(b<<8));a=(u16)(((s32)a>>8)|(a<<8));head=(first<<28)>>26;ip=(b<<16)|a;
id=M2C_FIELD(packet,u16 *,4);
slot=data_021375b8;
for(i=0;i<8;i++,slot+=0x38){
count=M2C_FIELD(slot,u16 *,4);
if(count&&M2C_FIELD(slot,u32 *,0)==ip&&M2C_FIELD(slot,u16 *,6)==id)break;
if(!count&&!freeSlot)freeSlot=slot;
}
t=M2C_FIELD(packet,u16 *,2);len=(u16)(((s32)t>>8)|(t<<8))-head;
offset=flags&0x1fff;end=len+offset*8;
if(i==8){
if(!freeSlot||end>4096)return 0;
slot=freeSlot;
M2C_FIELD(freeSlot,void **,0x34)=M2C_FIELD(&gNetStack,void *(**)(u32),0x14)(head+0x100e);
if(!M2C_FIELD(freeSlot,void **,0x34))return 0;
M2C_FIELD(freeSlot,u32 *,0)=ip;M2C_FIELD(freeSlot,u16 *,6)=id;M2C_FIELD(freeSlot,u16 *,8)=0;
M2C_FIELD(freeSlot,u32 *,0x2c)=(u32)(GetSystemTick()>>16);
M2C_FIELD(freeSlot,void **,0x30)=(u8 *)M2C_FIELD(freeSlot,void **,0x34)+14+head;
MI_CpuCopy8(packet,(u8 *)M2C_FIELD(freeSlot,void **,0x34)+14,head);
}
if(M2C_FIELD(slot,u16 *,4)==8||end>4096){
void (*release)(void *)=M2C_FIELD(&gNetStack,void (**)(void *),0x40);M2C_FIELD(slot,u16 *,4)=0;release(M2C_FIELD(slot,void **,0x34));return 0;
}
count=offset+((len+7)>>3);
if(!(flags&0x2000)){M2C_FIELD(slot,u16 *,10)=end;M2C_FIELD(slot,u16 *,8)=count;}
M2C_FIELD(slot+M2C_FIELD(slot,u16 *,4)*2,u16 *,12)=offset;
M2C_FIELD(slot+M2C_FIELD(slot,u16 *,4)*2,u16 *,28)=count;
M2C_FIELD(slot,u16 *,4)++;
MI_CpuCopy8((u8 *)packet+head,(u8 *)M2C_FIELD(slot,void **,0x30)+offset*8,len);
id=M2C_FIELD(slot,u16 *,8);if(!id)return 0;
count=M2C_FIELD(slot,u16 *,4);i=covered=0;
while(i<count){u8 *p=slot+i*2;if(M2C_FIELD(p,u16 *,12)<=covered&&covered<M2C_FIELD(p,u16 *,28)){covered=M2C_FIELD(p,u16 *,28);i=0;}else i++;}
if(covered<id)return 0;
freeSlot=M2C_FIELD(slot,u8 **,0x34);
t=M2C_FIELD(slot,u16 *,10)+(M2C_FIELD(freeSlot,u8 *,14)&15)*4;
M2C_FIELD(freeSlot,u16 *,16)=((s32)t>>8)|(t<<8);
M2C_FIELD(slot,u16 *,4)=0;*done=1;return freeSlot+14;
}
#pragma scheduling on
/* Receives one IPv4 packet (ipHeader, packetLength bytes) from the link layer:
 * drops a packet whose destination is not this host, whose length or header
 * checksum is wrong, refreshes the ARP cache for the sender, reassembles the
 * fragments and hands the payload to the UDP, ICMP or TCP receive path. */
void IpReceivePacket(u8 *ipHeader, s32 packetLength) {
    s32 Checksum(u8 *, u32);
    s32 IsLocalDestinationAddress(s32);
    M2C_UNK UpdateArpCache(void *, M2C_UNK, s32);
    M2C_UNK HandleIcmpPacket(void *, u8 *, M2C_UNK);
    M2C_UNK TcpReceiveSegment(void *, void *, s32);
    M2C_UNK UdpReceiveDatagram(void *, void *, s32);
    void *IpReassemblePacket(void *, s32 *);
    extern M2C_UNK gNetStack;

    u32 destAddr;
    u32 srcAddr;

    u16 srcLow = M2C_FIELD(ipHeader, volatile u16 *, IPH_SRC_IP_LO);
    u16 srcHigh = M2C_FIELD(ipHeader, volatile u16 *, IPH_SRC_IP_HI);
    u16 dstLow = M2C_FIELD(ipHeader, volatile u16 *, IPH_DST_IP_LO);
    u16 dstHigh = M2C_FIELD(ipHeader, volatile u16 *, IPH_DST_IP_HI);

    destAddr = ((u32)(u16)((dstHigh >> 8) | (dstHigh << 8)) << 16) |
               (u16)((dstLow >> 8) | (dstLow << 8));
    srcAddr = ((u32)(u16)((srcHigh >> 8) | (srcHigh << 8)) << 16) |
              (u16)((srcLow >> 8) | (srcLow << 8));

    if (destAddr != srcAddr) {
        u16 totalLength;
        u8 versionIhl;
        u32 destAddress, sourceAddress;

        if (IsLocalDestinationAddress(destAddr) == 0) {
            return;
        }
        totalLength = M2C_FIELD(ipHeader, u16 *, IPH_TOTAL_LENGTH);
        if ((u32)packetLength < (u32)(u16)((totalLength >> 8) | (totalLength << 8))) {
            return;
        }
        versionIhl = M2C_FIELD(ipHeader, u8 *, IPH_VERSION_IHL);
        if (Checksum(ipHeader, (u32)(versionIhl << 0x1C) >> 0x1A) != CHECKSUM_VALID) {
            return;
        }
        destAddress = ((u32)(u16)((M2C_FIELD(ipHeader, u16 *, IPH_DST_IP_HI) >> 8) | (M2C_FIELD(ipHeader, u16 *, IPH_DST_IP_HI) << 8)) << 16) |
                      (u16)((M2C_FIELD(ipHeader, u16 *, IPH_DST_IP_LO) >> 8) | (M2C_FIELD(ipHeader, u16 *, IPH_DST_IP_LO) << 8));
        if (M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP) == (s32)destAddress) {
            sourceAddress = ((u32)(u16)((M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_HI) >> 8) | (M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_HI) << 8)) << 16) |
                            (u16)((M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_LO) >> 8) | (M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_LO) << 8));
            /* the sender's hardware address sits ETH_HEADER_SIZE - ETH_SRC_MAC bytes before the IPv4 header */
            UpdateArpCache(ipHeader - (ETH_HEADER_SIZE - ETH_SRC_MAC), sourceAddress, 1);
        }
    }

    {
        s32 ownBuffer;
        void *packet;
        u8 protocol;
        u16 packetTotalLength;
        u8 versionIhl;
        s32 headerSize;
        void *payload;
        s32 payloadLength;

        packet = IpReassemblePacket(ipHeader, &ownBuffer);
        if (packet == 0) {
            return;
        }
        packetTotalLength = M2C_FIELD(packet, u16 *, IPH_TOTAL_LENGTH);
        versionIhl = M2C_FIELD(packet, u8 *, IPH_VERSION_IHL);
        headerSize = (s32)((u32)(versionIhl << 0x1C) >> 0x1A);
        payload = (u8 *)packet + headerSize;
        payloadLength = (s32)(u16)((packetTotalLength >> 8) | (packetTotalLength << 8)) - headerSize;

        protocol = M2C_FIELD(packet, u8 *, IPH_PROTOCOL);
        if (protocol == IP_PROTO_UDP) {
            UdpReceiveDatagram(packet, payload, payloadLength);
        } else if (M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP) != 0) {
            if (protocol == IP_PROTO_ICMP) {
                HandleIcmpPacket(packet, (u8 *)payload, payloadLength);
            } else if (protocol == IP_PROTO_TCP) {
                TcpReceiveSegment(packet, payload, payloadLength);
            }
        }

        if (ownBuffer != 0) {
            M2C_FIELD(&gNetStack, M2C_UNK (**)(M2C_UNK), NETSTACK_FREE)((M2C_UNK)((u8 *)packet - ETH_HEADER_SIZE));
        }
    }
}

/* The network receive thread's body: take the next Ethernet frame from the
 * stack's receive ring, hand an IPv4 or ARP frame to its handler, consume the
 * record, forever. */
void NetReceiveThreadMain(void) {
    u8 *NetStackPeekFrame(u32 *);
    void IpReceivePacket(u8 *, s32);
    void HandleArpPacket(u8 *, s32);
    void NetStackConsumeFrame(void);
    u32 size;

    for (;;) {
        u8 *frame = NetStackPeekFrame(&size);
        if (size > 0x22) {
            s32 type = M2C_FIELD(frame, u16 *, ETH_TYPE);
            switch ((u16)((type >> 8) | (type << 8))) {
                case ETH_TYPE_IPV4:
                    IpReceivePacket(frame + ETH_HEADER_SIZE, size - ETH_HEADER_SIZE);
                    break;
                case ETH_TYPE_ARP:
                    HandleArpPacket(frame + ETH_HEADER_SIZE, size - ETH_HEADER_SIZE);
                    break;
            }
        }
        NetStackConsumeFrame();
    }
}

u16 AllocateLocalPort(void) {
    extern M2C_UNK gSocketManager;
    extern M2C_UNK gNetStack;

    u16 counter;
    u8 *node;
    u8 *child;
    s32 found;

    for (;;) {
        counter = M2C_FIELD(&gNetStack, u16 *, 8);
        counter = counter + 1;
        if (counter >= 0x400) {
            if (counter >= 0x1388) {
                counter = 0x400;
            }
        }
        M2C_FIELD(&gNetStack, u16 *, 8) = counter;

        node = M2C_FIELD(&gSocketManager, u8 *, 8);
        found = 0;
        if (node != 0) {
            do {
                child = M2C_FIELD(node, u8 *, 0xA4);
                if (child != 0) {
                    if (M2C_FIELD(child, s32 *, 0) != 0) {
                        if (M2C_FIELD(child, u16 *, 0xA) == counter) {
                            found = 1;
                            break;
                        }
                    }
                }
                node = M2C_FIELD(node, u8 *, 0x68);
            } while (node != 0);
        }
        if (found == 0) {
            break;
        }
    }
    return M2C_FIELD(&gNetStack, u16 *, 8);
}

/* Advance the network stack's 64-bit LCG and return the high 32 bits of the new state. */
s32 NetStackRandom(void) {
    extern M2C_UNK gNetStack;
    u64 multiplier;
    u64 state;
    u64 increment;
    u64 next;

    multiplier = M2C_FIELD(&gNetStack, u64 *, NETSTACK_RANDOM_MULT);
    state = M2C_FIELD(&gNetStack, u64 *, NETSTACK_RANDOM_STATE);
    increment = M2C_FIELD(&gNetStack, u64 *, NETSTACK_RANDOM_ADD);
    next = multiplier * state + increment;
    M2C_FIELD(&gNetStack, u64 *, NETSTACK_RANDOM_STATE) = next;
    return (s32)(next >> 32);
}

void SetCurrentRawConnection(s32 arg0) {
    extern M2C_UNK gSocketManager;
    M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0xA4) = arg0;
}

void ClearCurrentRawConnection(void) {
    extern M2C_UNK gSocketManager;
    M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0xA4) = 0;
}

void OpenRawConnection(void) {
    extern M2C_UNK gSocketManager;
    M2C_UNK *inner;
    M2C_UNK *q;
    inner = (M2C_UNK *)M2C_FIELD(&gSocketManager, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    M2C_FIELD(q, u8 *, 8) = 0xA;
    M2C_FIELD(q, s32 *, 0x44) = 0;
}

/* Point the current socket's connection at the given peer: stage the peer port
 * and address and commit them (a loopback peer takes the link's own address),
 * then set the local port, allocating a free one when the caller passes none. */
void SetConnectionEndpoint(s32 localPort, s32 peerPort, s32 peerAddr) {
    extern M2C_UNK gSocketManager;
    extern M2C_UNK gNetStack;
    u16 AllocateLocalPort(void);
    M2C_UNK *thread;
    M2C_UNK *socket;
    s32 resolvedAddr;
    thread = (M2C_UNK *)M2C_FIELD(&gSocketManager, void **, 4);
    socket = (M2C_UNK *)M2C_FIELD(thread, void **, 0xA4);
    if (socket == 0) {
        return;
    }
    if (peerAddr == IP_LOOPBACK) {
        resolvedAddr = M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP);
    } else {
        resolvedAddr = peerAddr;
    }
    M2C_FIELD(socket, u16 *, SOCKET_NEXT_PEER_PORT) = (u16)peerPort;
    M2C_FIELD(socket, u16 *, SOCKET_PEER_PORT) = M2C_FIELD(socket, u16 *, SOCKET_NEXT_PEER_PORT);
    M2C_FIELD(socket, s32 *, SOCKET_NEXT_PEER_ADDR) = resolvedAddr;
    M2C_FIELD(socket, s32 *, SOCKET_PEER_ADDR) = resolvedAddr;
    if (localPort != 0) {
        M2C_FIELD(socket, s16 *, SOCKET_LOCAL_PORT) = (s16)localPort;
        return;
    }
    M2C_FIELD(socket, s16 *, SOCKET_LOCAL_PORT) = AllocateLocalPort();
}

/* Reset the current socket's connection so it can be reused: give it back its
 * owning socket object and clear its state, receive length, pending send data and
 * data callback. */
void ResetCurrentConnection(void) {
    extern M2C_UNK gSocketManager;
    void *socketObject;
    void *connection;

    socketObject = M2C_FIELD(&gSocketManager, void **, SOCKMGR_RUNNING_THREAD);
    connection = M2C_FIELD(socketObject, void **, SOCK_OBJECT_RAW);
    if (connection == 0) {
        return;
    }
    M2C_FIELD(connection, void **, SOCKET_OWNER) = socketObject;
    M2C_FIELD(connection, u8 *, SOCKET_STATE) = TCP_STATE_CLOSED;
    M2C_FIELD(connection, s32 *, SOCKET_RX_LENGTH) = 0;
    M2C_FIELD(connection, s32 *, CONN_PENDING_TX_LEN) = 0;
    M2C_FIELD(connection, s32 *, SOCKET_DATA_CB) = 0;
}

void CloseRawConnection(void) {
    extern M2C_UNK gSocketManager;
    void *x = M2C_FIELD(&gSocketManager, void **, 4);
    s32 *q = M2C_FIELD(x, s32 **, 0xa4);
    if (q != 0) {
        *q = 0;
    }
}

void func_0201d244(void *arg0) {
    extern M2C_UNK gSocketManager;
    M2C_FIELD(arg0, void **, 0xA4) = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
}

/* Prepare a socket connection to wait for its peer: hand it a fresh random initial
 * sequence number (used as the send position too), mark it listening, then wake
 * its socket task and block until the task has taken the connection. */
void SocketStartListen(void *conn) {
    M2C_UNK OS_SleepThread(M2C_UNK);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 NetStackRandom();
    s32 sequence;
    s32 irqState;

    sequence = NetStackRandom();
    M2C_FIELD(conn, s32 *, TCP_CONN_SEND_SEQ) = sequence;
    M2C_FIELD(conn, s32 *, TCP_SOCK_SENTPOS) = sequence;
    M2C_FIELD(conn, s8 *, SOCKET_STATE) = CONN_STATE_LISTEN;
    irqState = OS_DisableInterrupts();
    M2C_FIELD(conn, s32 *, SOCKET_TASK_STATE) = 1;
    OS_SleepThread(0);
    OS_RestoreInterrupts(irqState);
}

void SocketSetReceiveCallback(s32 arg0) {
    extern M2C_UNK gSocketManager;
    void *x = M2C_FIELD(&gSocketManager, void **, 4);
    s32 *q = M2C_FIELD(x, s32 **, 0xa4);
    if (q != 0) {
        M2C_FIELD(q, s32 *, 0x38) = arg0;
    }
}

/* Start listening on the running socket object's connection: run the TLS server
 * handshake when its payload is TLS-wrapped, a plain TCP listen otherwise. */
void ListenTransport(void) {
    void func_02024b24();
    void SocketStartListen(void *);
    extern M2C_UNK gSocketManager;
    void *conn = (void *) M2C_FIELD(M2C_FIELD(&gSocketManager, void **, SOCKMGR_RUNNING_THREAD), void **, SOCK_OBJECT_RAW);
    if (conn == 0) {
        return;
    }
    if (M2C_FIELD(conn, u8 *, SOCK_TLS_ACTIVE) != 0) {
        func_02024b24(conn);
    } else {
        SocketStartListen(conn);
    }
}

/* Opens a TCP connection: pick an initial send sequence, enter SYN_SENT, note
 * the tick and send the SYN segment, then wait (under the interrupt lock) for
 * the peer to answer, retrying the handshake up to three times.  Returns 0 once
 * the connection is established, 1 when the link is down or every attempt
 * timed out. */
s32 TcpConnect(void *conn) {
    u64 GetSystemTick();
    M2C_UNK TcpTransmitSegment(void *, M2C_UNK, M2C_UNK);
    extern M2C_UNK gNetStack;
    u32 attempts;
    s32 initialSequence;
    s32 irqState;

    initialSequence = NetStackRandom();
    attempts = 0;
loop_1:
    M2C_FIELD(conn, s32 *, TCP_CONN_SEND_SEQ) = initialSequence;
    M2C_FIELD(conn, u8 *, SOCKET_STATE) = TCP_STATE_SYN_SENT;
    M2C_FIELD(conn, s32 *, SOCKET_STATE_TICK) = (s32)(GetSystemTick() >> 16);
    TcpTransmitSegment(conn, TCP_FLAG_SYN, 0x18);
    irqState = OS_DisableInterrupts();
    if ((M2C_FIELD(conn, u8 *, SOCKET_STATE) == TCP_STATE_SYN_SENT) && (M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP) != 0)) {
        M2C_FIELD(conn, s32 *, SOCKET_TASK_STATE) = 1;
        OS_SleepThread(0);
    }
    OS_RestoreInterrupts(irqState);
    if (M2C_FIELD(conn, u8 *, SOCKET_STATE) == TCP_STATE_ESTABLISHED) {
        return 0;
    }
    if ((M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP) == 0) || (++attempts >= 3U)) {
        return 1;
    }
    goto loop_1;
}

/* Connect the running socket object's socket on its own transport: TLS when the
 * socket wraps its payload in TLS records, a plain TCP connect otherwise.
 * Returns 1 when the socket object has no socket. */
s32 ConnectTransport(void){
extern M2C_UNK gSocketManager;
s32 TlsClientConnect(void*);
void *socket;
socket=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,SOCKMGR_RUNNING_THREAD),void**,SOCK_OBJECT_RAW);
if(socket){
if(M2C_FIELD(socket,u8*,SOCK_TLS_ACTIVE))return TlsClientConnect(socket);
return TcpConnect(socket);
}
return 1;
}

/* Report the endpoint of the socket's connection once its transport is up (a TCP
 * stream established or a raw connection listening): *portOut gets the peer port,
 * *localAddrOut the local address, and the peer address is returned. 0 while the
 * socket has no such connection. */
s32 GetSocketEndpoints(u16 *portOut,u32 *localAddrOut) {
extern M2C_UNK gSocketManager;
void *conn=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,SOCK_OBJECT_RAW);
if(conn!=0&&(M2C_FIELD(conn,u8*,SOCKET_STATE)==TCP_STATE_ESTABLISHED||M2C_FIELD(conn,u8*,SOCKET_STATE)==SOCKET_STATE_UDP_LISTEN)){
if(portOut!=0)*portOut=M2C_FIELD(conn,u16*,SOCKET_PEER_PORT);
if(localAddrOut!=0)*localAddrOut=M2C_FIELD(conn,u32*,SOCKET_LOCAL_ADDR);
return M2C_FIELD(conn,s32*,SOCKET_PEER_ADDR);
}
return 0;
}

/* Start closing a TCP connection: a connection in SYN_RCVD or ESTABLISHED sends
 * its FIN (with ACK) and moves to FIN_WAIT1, a closed one does nothing, and any
 * other state is answered with a bare ACK. */
void TcpCloseConnection(void *conn) {
    M2C_UNK TaskYield();
    M2C_UNK TcpSendAck(void *, M2C_UNK);
    M2C_UNK TcpSendFinAck(void *, M2C_UNK);
    u8 state;

    TaskYield();
    state = M2C_FIELD(conn, u8 *, SOCKET_STATE);
    if ((u32)(u8)(state + 0xFD) <= 1U) {
        TcpSendFinAck(conn, 0x19);
        M2C_FIELD(conn, u8 *, SOCKET_STATE) = TCP_STATE_FIN_WAIT1;
        return;
    }
    if (state == TCP_STATE_CLOSED) {
        return;
    }
    TcpSendAck(conn, 0x1A);
}

void CloseTransport(void) {
    void TlsSendCloseNotify(void *);
    void TcpCloseConnection(void *);
    extern M2C_UNK gSocketManager;
    void *transportSocket = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, SOCKMGR_RUNNING_THREAD), void **, SOCK_OBJECT_RAW);

    /* Send TLS shutdown notification when needed, then close the active TCP transport. */
    if (transportSocket == 0) {
        return;
    }
    if (M2C_FIELD(transportSocket, u8 *, SOCK_TLS_ACTIVE) != 0) {
        TlsSendCloseNotify(transportSocket);
    }
    TcpCloseConnection(transportSocket);
}

void WaitForTlsCloseNotify(void) {
    extern M2C_UNK gSocketManager, gNetStack;
    void TlsResetChannel(void *);
    M2C_UNK func_0201a238();
    u64 GetSystemTick(void);
    void *socketManagerEntry = M2C_FIELD(&gSocketManager, void **, 4);
    void *rawConnection = M2C_FIELD(socketManagerEntry, void **, NETSTACK_SOCKET_RAW_CONNECTION);
    s32 startTick;

    /* Wait briefly for a TLS close alert to drain, then close the transport. */
    if (!rawConnection) return;
    if (M2C_FIELD(rawConnection, u8 *, SOCK_TLS_ACTIVE)) {
        TlsResetChannel(rawConnection);
    }
    startTick = (u32)(GetSystemTick() >> 16);
    goto check;
loop:
    func_0201a238();
check:
    if (!M2C_FIELD(&gNetStack, s32 (**)(void), NETSTACK_POLL)() || !M2C_FIELD(rawConnection, u8 *, TCP_SOCK_STATE)) goto done;
    if ((s32)((u32)(GetSystemTick() >> 16) - startTick) < NETSTACK_TLS_CLOSE_WAIT) goto loop;
done:
    M2C_FIELD(rawConnection, u8 *, TCP_SOCK_STATE) = 0;
}

/* Waits for a datagram connection's pending datagram (an ICMP reply): reports
 * the datagram's byte length in sizeOut and returns the connection's receive
 * buffer it sits in.  Sleeps until the connection has one, first asking its
 * task to service the connection. */
s32 PeekDatagramReceivedData(s32 *sizeOut, void *connection) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_SleepThread(M2C_UNK);
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 length;
    s32 saved;

    saved = OS_DisableInterrupts();
    length = M2C_FIELD(connection, s32 *, CONN_RX_PENDING_LEN);
    while (length == 0) {
        M2C_FIELD(connection, s32 *, CONN_TASK_ID) = 3;
        OS_SleepThread(0);
        length = M2C_FIELD(connection, s32 *, CONN_RX_PENDING_LEN);
    }
    OS_RestoreInterrupts(saved);
    *sizeOut = length;
    return M2C_FIELD(connection, s32 *, CONN_RX_BUFFER);
}

/* Peek at what a raw connection has received: when it has no data and is still
 * established, ask its task for some and sleep until the data arrives (or the
 * connection closes).  Reports the byte count in sizeOut and returns the
 * receive buffer, or reports 0 and returns 0 when nothing is available. */
s32 PeekReceivedData(u32 *sizeOut, M2C_UNK connection) {
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_SleepThread(M2C_UNK);
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK TaskYield(void);
    s32 saved;
    s32 available;

    if (M2C_FIELD((void *)connection, u32 *, CONN_RX_POS) == 0 &&
        M2C_FIELD((void *)connection, u8 *, CONN_STATE) == CONN_STATE_ESTABLISHED) {
        saved = OS_DisableInterrupts();
        while (M2C_FIELD((void *)connection, u32 *, CONN_RX_POS) == 0 &&
               M2C_FIELD((void *)connection, u8 *, CONN_STATE) == CONN_STATE_ESTABLISHED) {
            M2C_FIELD((void *)connection, s32 *, CONN_TASK_ID) = 2;
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(saved);
    } else {
        TaskYield();
    }
    available = M2C_FIELD((void *)connection, u32 *, CONN_RX_POS);
    *sizeOut = (u32)available;
    if (available != 0) {
        return (s32)M2C_FIELD((void *)connection, void **, CONN_RX_BUFFER);
    }
    return 0;
}

/* Peek at the current socket's received data without consuming it: a datagram
 * (UDP/ICMP) raw connection waits for and returns its pending datagram, a TLS
 * connection returns its pending record, and anything else returns its
 * established TCP receive window.  The byte count goes to sizeOut; a socket with
 * no current connection reports sizeOut 0 and returns 0. */
s32 PeekSocketReceivedData(s32 *sizeOut) {
    s32 PeekDatagramReceivedData(s32 *, void *);
    s32 PeekReceivedData(u32 *, M2C_UNK);
    s32 TlsPeekReceivedData(s32 *, void *);
    extern M2C_UNK gSocketManager;
    void *socket;
    void *connection;
    u8 datagramState;

    socket = M2C_FIELD(&gSocketManager, void **, 0x4);
    connection = M2C_FIELD(socket, void **, SOCK_OBJECT_RAW);
    if (connection == 0) goto fail;
    /* CONN_STATE 10 (raw/UDP) or 11 (ICMP): a datagram connection */
    datagramState = (u8)(M2C_FIELD(connection, u8 *, CONN_STATE) + 0xF6);
    if (datagramState <= 1) {
        return PeekDatagramReceivedData(sizeOut, connection);
    }
    if (M2C_FIELD(connection, u8 *, SOCK_TLS_ACTIVE) != 0) {
        return TlsPeekReceivedData(sizeOut, connection);
    }
    return PeekReceivedData((u32 *)sizeOut, (M2C_UNK)connection);

fail:
    *sizeOut = 0;
    return 0;
}

void ConsumeReceivedData(u32 arg0, void *arg1) {
M2C_UNK OS_DisableInterrupts(void); M2C_UNK OS_RestoreInterrupts(M2C_UNK);
M2C_UNK MemMove(M2C_UNK,M2C_UNK); M2C_UNK TcpSendAck(void *,M2C_UNK);
u8 kind; u32 flag; u32 left; M2C_UNK irq;
irq=OS_DisableInterrupts();
left=M2C_FIELD(arg1,u32*,0x44); flag=0;
if(left==M2C_FIELD(arg1,u32*,0x3c) && arg0!=0) flag=1;
if(arg0>=left) M2C_FIELD(arg1,u32*,0x44)=0;
else {s32 base=M2C_FIELD(arg1,s32*,0x40);M2C_FIELD(arg1,u32*,0x44)=left-arg0;MemMove(base,base+arg0);}
{ M2C_UNK saved = irq; OS_RestoreInterrupts(saved); }
kind=M2C_FIELD(arg1,u8*,8);
if(kind!=0xa && kind!=0xb){
if(M2C_FIELD(arg1,u32*,0x44)!=0){if(flag==0)return;}
TcpSendAck(arg1,0x1b);
}
}

/* Consume `count` bytes of the current socket's received data: a TLS socket drops
 * them from its pending record, any other socket from its receive buffer. */
void ConsumeConnectionReceivedData(u32 count) {
    void TlsConsumeReceivedData(u32, void *);
    void ConsumeReceivedData(u32, void *);
    extern M2C_UNK gSocketManager;
    void *connection = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, SOCKMGR_RUNNING_THREAD), void **, SOCK_OBJECT_RAW);

    if (connection == 0) return;
    if (M2C_FIELD(connection, u8 *, SOCK_TLS_ACTIVE) != 0)
        TlsConsumeReceivedData(count, connection);
    else
        ConsumeReceivedData(count, connection);
}

s32 TcpSendBuffer(M2C_UNK data, s32 length, M2C_UNK socket, s32 probe) {
    extern M2C_UNK gNetStack;
    M2C_UNK TcpSendSegment(M2C_UNK, s32, M2C_UNK, s32, s32);
    M2C_UNK TaskYield(void);

    M2C_UNK sock;
    s32 probeMode;
    M2C_UNK cursor;
    u32 remaining;
    u32 segmentLength;
    u32 available;
    u32 previousResult;
    u32 budget;
    u32 currentResult;
    u16 stackLimit;
    s32 zero;

    sock = socket;
    previousResult = M2C_FIELD(sock, s32 *, TCP_SOCK_RESULT);
    probeMode = probe;
    cursor = data;
    remaining = length;
    if (probeMode != 0) {
        available = 1;
    } else {
        available = M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG);
    }
    budget = (previousResult << 1) + 4;

    /* The send path enters with nonzero length and an established socket. */
    while (remaining != 0 && M2C_FIELD(sock, u8 *, TCP_SOCK_STATE) == 4) {
        segmentLength = M2C_FIELD(sock, u16 *, 0x2E);
        stackLimit = M2C_FIELD(&gNetStack, u16 *, 0x2);
        currentResult = M2C_FIELD(sock, s32 *, TCP_SOCK_RESULT);
        if ((u32)segmentLength >= (u32)available) {
            segmentLength = available;
        }
        if ((u32)stackLimit < (u32)segmentLength) {
            segmentLength = stackLimit;
        }
        if (probeMode == 0) {
            segmentLength &= ~1;
        }
        if (remaining < (u32)segmentLength) {
            segmentLength = remaining;
        }
        budget += currentResult - previousResult;
        previousResult = currentResult;
        if (budget-- == 0) {
            segmentLength = 0;
        }
        if (segmentLength == 0) {
            break;
        }
        zero = 0;
        available = available - segmentLength;
        TcpSendSegment(cursor, segmentLength, sock, 0x18, zero);
        TaskYield();
        cursor = (M2C_UNK)((u8 *)cursor + segmentLength);
        remaining = remaining - segmentLength;
    }
    return segmentLength;
}

/* Send the first buffer through the TCP socket; when that made progress and a
 * second buffer is given, send that one too (in normal, non-probe mode). */
void TcpSendBuffers(M2C_UNK src1, s32 len1, M2C_UNK src2, s32 len2, s32 sock, s32 probe) {
    s32 TcpSendBuffer(M2C_UNK, s32, M2C_UNK, s32);
    if ((TcpSendBuffer(src1, len1, sock, probe) != 0) && (len2 != 0)) {
        TcpSendBuffer(src2, len2, sock, 0);
    }
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
/* Sends up to two buffers through the TCP socket until the link stops accepting
 * data or 0x9F ticks pass without progress; returns the number of bytes sent. */
s32 TcpSendData(s32 src1, s32 len1, s32 src2, s32 len2, void *sock) {
    u64 GetSystemTick();
    M2C_UNK func_0201a238();
    extern M2C_UNK gNetStack;
    s32 total;
    u32 lastSend;
    s32 left2;
    s32 split;
    s32 sendStart;
    s32 waitStart;
    s32 ptr1;
    u32 progress;
    s32 waited;
    u32 pollStart;
    s32 ptr2;
    u32 now1;
    u32 now2;
    s32 left1;

    ptr1 = src1;
    total = 0;
    left1 = len1;
    ptr2 = src2;
    left2 = len2;
    waited = 0;
    M2C_FIELD(sock, s32 *, TCP_SOCK_RESULT) = 0;
    lastSend = (u32)(GetSystemTick() >> 16);
    goto gate;
body:
    sendStart = M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS);
    TcpSendBuffers(ptr1, left1, ptr2, left2, sock, waited);
    pollStart = (u32)(GetSystemTick() >> 16);
loop_2:
    func_0201a238();
    if ((M2C_FIELD(&gNetStack, s32 (**)(), NETSTACK_POLL)() != 0) && (M2C_FIELD(sock, u8 *, TCP_SOCK_STATE) == 4) && (M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS) != M2C_FIELD(sock, s32 *, TCP_SOCK_SENTPOS))) {
        now1 = (u32)(GetSystemTick() >> 16);
        if ((s32)(now1 - pollStart) < 0xF) {
            if (!((waited != 0) && (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) != 0))) {
                goto loop_2;
            }
        }
    }
    progress = M2C_FIELD(sock, s32 *, TCP_SOCK_SENTPOS) - sendStart;
    if (progress > (u32)(M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS) - sendStart)) {
        progress = 0;
    }
    total += progress;
    if (progress != 0) {
        lastSend = (u32)(GetSystemTick() >> 16);
    }
    M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS) = (s32)M2C_FIELD(sock, s32 *, TCP_SOCK_SENTPOS);
    if ((M2C_FIELD(sock, u8 *, TCP_SOCK_STATE) == 4) && (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) == 0) && (progress == 0)) {
        if (waited == 0) {
            waitStart = (s32)(u32)(GetSystemTick() >> 16);
            goto check_22;
loop_22:
            func_0201a238();
            if (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) != 0) goto done_22;
check_22:
            if (M2C_FIELD(&gNetStack, s32 (**)(), NETSTACK_POLL)() != 0) {
                now2 = (u32)(GetSystemTick() >> 16);
                if ((s32)(now2 - waitStart) < 0xF) {
                    goto loop_22;
                }
            }
done_22:
            if (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) == 0) {
                waited = 1;
            }
        }
    } else {
        waited = 0;
    }
    if (progress < (u32)left1) {
        ptr1 += (s32)progress;
        left1 -= (s32)progress;
    } else {
        split = (s32)progress - left1;
        ptr1 = ptr2 + split;
        ptr2 = 0;
        left1 = left2 - split;
        left2 = 0;
    }
    goto gate;
gate:
    if ((M2C_FIELD(&gNetStack, s32 (**)(), NETSTACK_POLL)() == 0) || (left1 == 0)) {
        goto ret;
    }
    if (M2C_FIELD(sock, u8 *, TCP_SOCK_STATE) != 4) {
        goto ret;
    }
    progress = (u32)(GetSystemTick() >> 16);
    if ((s32)(progress - lastSend) >= 0x9F) {
        goto ret;
    }
    goto body;
ret:
    return total;
}
#pragma pop
/* Send up to two buffers through the current socket: a UDP (kind 10) or ICMP
 * (kind 11) socket sends each buffer as its own datagram, while a stream socket
 * (TLS or plain TCP) sends both in one call.  Returns the bytes sent, or 0 when
 * the socket or the link is unavailable. */
s32 SendSocketData(s32 src1,s32 len1,s32 src2,s32 len2){
extern M2C_UNK gSocketManager;extern M2C_UNK gNetStack;
void UdpSendSegment(s32,s32,void *);void func_0201b338(s32,s32,void *);s32 TlsSendAppData(s32,s32,s32,s32,void *);s32 TcpSendData(s32,s32,s32,s32,void *);
void *sock; s32 sent;
sock=M2C_FIELD(M2C_FIELD(&gSocketManager,void **,4),void **,0xa4);
if(sock!=0){
if(M2C_FIELD(sock,u8 *,SOCK_TRANSPORT)==10){if(len1)UdpSendSegment(src1,len1,sock);if(len2)UdpSendSegment(src2,len2,sock);sent=len1+len2;}
 else if(M2C_FIELD(sock,u8 *,SOCK_TRANSPORT)==11){if(len1)func_0201b338(src1,len1,sock);if(len2)func_0201b338(src2,len2,sock);sent=len1+len2;}
else if(M2C_FIELD(sock,u8 *,SOCK_TLS_ACTIVE))sent=TlsSendAppData(src1,len1,src2,len2,sock);
else sent=TcpSendData(src1,len1,src2,len2,sock);
if(M2C_FIELD(&gNetStack,u8 *,0)==0)return sent;
}return 0;
}

