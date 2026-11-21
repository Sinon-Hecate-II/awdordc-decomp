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

u16 func_0201d04c(void) {
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

s32 NetStackRandom(void) {
    extern M2C_UNK gNetStack;
    u64 mult;
    u64 val;
    u64 add;
    u64 res;

    mult = M2C_FIELD(&gNetStack, u64 *, 0x70);
    val = M2C_FIELD(&gNetStack, u64 *, 0x68);
    add = M2C_FIELD(&gNetStack, u64 *, 0x78);
    res = mult * val + add;
    M2C_FIELD(&gNetStack, u64 *, 0x68) = res;
    return (s32)(res >> 32);
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

void SetConnectionEndpoint(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK gSocketManager;
    extern M2C_UNK gNetStack;
    u16 func_0201d04c(void);
    M2C_UNK *inner;
    M2C_UNK *q;
    s32 temp;
    inner = (M2C_UNK *)M2C_FIELD(&gSocketManager, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    if (arg2 == 0x7F000001) {
        temp = M2C_FIELD(&gNetStack, s32 *, 0x50);
    } else {
        temp = arg2;
    }
    M2C_FIELD(q, u16 *, 0x1A) = (u16)arg1;
    M2C_FIELD(q, u16 *, 0x18) = M2C_FIELD(q, u16 *, 0x1A);
    M2C_FIELD(q, s32 *, 0x20) = temp;
    M2C_FIELD(q, s32 *, 0x1C) = temp;
    if (arg0 != 0) {
        M2C_FIELD(q, s16 *, 0x0A) = (s16)arg0;
        return;
    }
    M2C_FIELD(q, s16 *, 0x0A) = func_0201d04c();
}

void ResetCurrentConnection(void) {
    extern M2C_UNK gSocketManager;
    M2C_UNK *inner;
    M2C_UNK *q;
    inner = (M2C_UNK *)M2C_FIELD(&gSocketManager, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    M2C_FIELD(q, void **, 0) = (void *)inner;
    M2C_FIELD(q, u8 *, 8) = 0;
    M2C_FIELD(q, s32 *, 0x44) = 0;
    M2C_FIELD(q, s32 *, 0x60) = 0;
    M2C_FIELD(q, s32 *, 0x38) = 0;
}

void func_0201d224(void) {
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

void func_0201d25c(void *arg0) {
    M2C_UNK OS_SleepThread(M2C_UNK);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 NetStackRandom();
    s32 temp_r0;
    s32 temp_r4;

    temp_r0 = NetStackRandom();
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x30) = temp_r0;
    M2C_FIELD(arg0, s8 *, 8) = 1;
    temp_r4 = OS_DisableInterrupts();
    M2C_FIELD(arg0, s32 *, 4) = 1;
    OS_SleepThread(0);
    OS_RestoreInterrupts(temp_r4);
}

void SocketSetReceiveCallback(s32 arg0) {
    extern M2C_UNK gSocketManager;
    void *x = M2C_FIELD(&gSocketManager, void **, 4);
    s32 *q = M2C_FIELD(x, s32 **, 0xa4);
    if (q != 0) {
        M2C_FIELD(q, s32 *, 0x38) = arg0;
    }
}

void func_0201d2b8(void) {
    void func_02024b24(void);
    void func_0201d25c(void *);
    extern M2C_UNK gSocketManager;
    void *p = (void *) M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
    if (p == 0) {
        return;
    }
    if (*((u8 *) p + 9) != 0) {
        func_02024b24();
    } else {
        func_0201d25c(p);
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

s32 ConnectTransport(void){extern M2C_UNK gSocketManager;s32 func_02024c60(void*);void *p;p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);if(p){if(M2C_FIELD(p,u8*,9))return func_02024c60(p);return TcpConnect(p);}return 1;}

s32 func_0201d3e4(u16 *arg0,u32 *arg1) {
extern M2C_UNK gSocketManager;
void *p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);
if(p!=0&&(M2C_FIELD(p,u8*,8)==4||M2C_FIELD(p,u8*,8)==10)){
if(arg0!=0)*arg0=M2C_FIELD(p,u16*,0x18);
if(arg1!=0)*arg1=M2C_FIELD(p,u32*,0x14);
return M2C_FIELD(p,s32*,0x1c);
}
return 0;
}

void func_0201d434(void *arg0) {
    M2C_UNK TaskYield();
    M2C_UNK TcpSendAck(void *, M2C_UNK);
    M2C_UNK TcpSendFinAck(void *, M2C_UNK);
    u8 temp_r1;

    TaskYield();
    temp_r1 = M2C_FIELD(arg0, u8 *, 8);
    if ((u32) (u8) (temp_r1 + 0xFD) <= 1U) {
        TcpSendFinAck(arg0, 0x19);
        M2C_FIELD(arg0, u8 *, 8) = 7U;
        return;
    }
    if (temp_r1 == 0) {
        return;
    }
    TcpSendAck(arg0, 0x1A);
}

void func_0201d484(void) {
void TlsSendCloseNotify(void *);
void func_0201d434(void *);
extern M2C_UNK gSocketManager;
void *p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);
if(p==0)return;
if(M2C_FIELD(p,u8*,9)!=0)TlsSendCloseNotify(p);
func_0201d434(p);
}

void WaitForTlsCloseNotify(void) {
    extern M2C_UNK gSocketManager, gNetStack;
    void func_02025150(void *);
    M2C_UNK func_0201a238();
    u64 GetSystemTick(void);
    void *socketManagerEntry = M2C_FIELD(&gSocketManager, void **, 4);
    void *rawConnection = M2C_FIELD(socketManagerEntry, void **, NETSTACK_SOCKET_RAW_CONNECTION);
    s32 startTick;

    /* Wait briefly for a TLS close alert to drain, then close the transport. */
    if (!rawConnection) return;
    if (M2C_FIELD(rawConnection, u8 *, SOCK_TLS_ACTIVE)) {
        func_02025150(rawConnection);
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

s32 func_0201d548(s32 *arg0, void *arg1) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_SleepThread(M2C_UNK);
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 var_r6;
    s32 temp_r7;

    temp_r7 = OS_DisableInterrupts();
    var_r6 = M2C_FIELD(arg1, s32 *, 0x44);
    while (var_r6 == 0) {
        M2C_FIELD(arg1, s32 *, 4) = 3;
        OS_SleepThread(0);
        var_r6 = M2C_FIELD(arg1, s32 *, 0x44);
    }
    OS_RestoreInterrupts(temp_r7);
    *arg0 = var_r6;
    return M2C_FIELD(arg1, s32 *, 0x40);
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

s32 func_0201d618(s32 *arg0) {
    s32 func_0201d548(s32 *, void *);
    s32 PeekReceivedData(u32 *, M2C_UNK);
    s32 TlsPeekReceivedData(s32 *, void *);
    extern M2C_UNK gSocketManager;
    void *inner;
    void *q;
    u8 v;

    inner = M2C_FIELD(&gSocketManager, void **, 0x4);
    q = M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) goto fail;
    v = (u8)(((u8 *)q)[8] + 0xF6);
    if (v <= 1) {
        return func_0201d548(arg0, q);
    }
    if (((u8 *)q)[9] != 0) {
        return TlsPeekReceivedData(arg0, q);
    }
    return PeekReceivedData((u32 *)arg0, (M2C_UNK)q);

fail:
    *arg0 = 0;
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

void func_0201d70c(u32 arg0) {
void func_02024d8c(u32,void *);
void ConsumeReceivedData(u32,void *);
extern M2C_UNK gSocketManager;
void *p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);
if(p==0)return;
if(M2C_FIELD(p,u8*,9)!=0)func_02024d8c(arg0,p);
else ConsumeReceivedData(arg0,p);
}

s32 func_0201d744(M2C_UNK data, s32 length, M2C_UNK socket, s32 probe) {
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

void func_0201d808(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_0201d744(M2C_UNK, s32, s32, s32);
    if ((func_0201d744(arg0, arg1, arg4, arg5) != 0) && (arg3 != 0)) {
        func_0201d744(arg2, arg3, arg4, 0);
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
    func_0201d808(ptr1, left1, ptr2, left2, sock, waited);
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

