/* 14 functions from 0x0201DB20 to 0x0201E944 (main), found by ds-decomp. */
#include "common.h"
#include "dhcp.h"
#include "tcp_socket.h"
#include "net_socket.h"
static inline u32 NextPacketRandom(void) {
 extern M2C_UNK gNetStack;
 M2C_FIELD(&gNetStack,u64*,0x68)=M2C_FIELD(&gNetStack,u64*,0x70)*M2C_FIELD(&gNetStack,u64*,0x68)+M2C_FIELD(&gNetStack,u64*,0x78);
 return M2C_FIELD(&gNetStack,u64*,0x68)>>32;
}
static inline u16 PacketSwap(u16 x) { return (x>>8)|(x<<8); }
static inline u32 PacketRead32(const u8 *p) {
    u16 hi = (p[0] << 8) | p[1];
    u16 lo = (p[2] << 8) | p[3];
    return ((u32)hi << 16) | lo;
}
static inline s32 PacketTransactionMatches(const u16 *p, const u32 *expected) {
    u16 lo = p[1];
    u16 hi = p[0];
    u32 actual = ((u32)PacketSwap(hi) << 16) | PacketSwap(lo);
    return actual == *expected;
}
static inline void PacketPut32(u8 *p,u32 x) { *(u16*)p=PacketSwap(x>>16); *(u16*)(p+2)=PacketSwap(x); }
static inline void PacketAddress(u8 *p) { extern M2C_UNK gLocalMacAddress; void MI_CpuCopy8(s32,u8*,s32); MI_CpuCopy8((s32)&gLocalMacAddress,p,6); }

/* Send `packet` over the current socket, together with the connection's queued
 * send data when it has any: the queued bytes go first, so this call returns 0
 * while they still only partly drain (the rest is moved to the front of the
 * queue), otherwise the packet's own bytes are sent and their count returned. */
u32 SendNetPacket(s32 packet, s32 length) {
    extern M2C_UNK gSocketManager;
    M2C_UNK MemMove(s32, s32, u32);
    void *conn;
    u32 queued, used;
    conn = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
    if (conn) {
        queued = M2C_FIELD(conn, u32 *, CONN_PENDING_TX_LEN);
        if (queued) {
            used = SendSocketData(M2C_FIELD(conn, s32 *, CONN_PENDING_TX_BUF), queued, packet, length);
            queued = M2C_FIELD(conn, u32 *, CONN_PENDING_TX_LEN);
            if (used < queued) {
                MemMove(M2C_FIELD(conn, s32 *, CONN_PENDING_TX_BUF), M2C_FIELD(conn, s32 *, CONN_PENDING_TX_BUF) + used, queued - used);
                M2C_FIELD(conn, u32 *, CONN_PENDING_TX_LEN) -= used;
                return 0;
            }
            M2C_FIELD(conn, u32 *, CONN_PENDING_TX_LEN) = 0;
            return used - queued;
        }
        return SendSocketData(packet, length, 0, 0);
    }
    return 0;
}

/* Bytes waiting to be read on the current socket: for a TLS socket the TLS
 * layer's own count, otherwise the bytes in the receive buffer.  Returns 0 when
 * nothing is queued, -1 while a TCP socket is not established (a datagram socket
 * is always readable, its byte being SOCK_KIND_UDP or SOCK_KIND_ICMP). */
s32 GetSocketReceivedDataSize(void) {
    extern M2C_UNK gSocketManager;
    s32 TlsGetReceivedDataSize(void *);
    void *conn;
    s32 size;
    conn = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, SOCK_OBJECT_RAW);
    if (conn) {
        if (M2C_FIELD(conn, u8 *, SOCK_TLS_ACTIVE)) return TlsGetReceivedDataSize(conn);
        size = M2C_FIELD(conn, s32 *, CONN_RX_POS);
        if (size != 0) goto done;
        {
            u8 state = M2C_FIELD(conn, u8 *, SOCKET_STATE);
            if (state == TCP_STATE_ESTABLISHED) goto done;
            if ((u8)(state + 246) > 1) goto fail;
        }
    done:
        return size;
    fail:
        return -1;
    }
    return 0;
}

/* Flush the current raw connection's pending send queue: if it still holds
 * queued bytes, send them on their own and clear the queue. */
void FlushPendingSendData(void) {
    M2C_UNK SendSocketData(s32, s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK gSocketManager;
    s32 pending;
    void *conn;

    conn = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, SOCK_OBJECT_RAW);
    if (conn != NULL) {
        pending = M2C_FIELD(conn, s32 *, CONN_PENDING_TX_LEN);
        if (pending != 0) {
            SendSocketData(M2C_FIELD(conn, s32 *, CONN_PENDING_TX_BUF), pending, 0, 0);
            M2C_FIELD(conn, s32 *, CONN_PENDING_TX_LEN) = 0;
        }
    }
}

/* Claim the stack's local address: run the stack's upkeep callback, send two
 * gratuitous ARP announcements for NETSTACK_LOCAL_IP, then poll the link every
 * ARP_RETRY_MS until an ARP reply announcing the address arrives (which ends the
 * step with status 4) or NETSTACK_ARP_TIMEOUT ticks pass without the link
 * coming up. */
void AnnounceLocalAddress(void) {
    extern M2C_UNK gNetStack;
    void SendArpRequest(s32);
    void SleepMilliseconds(s32);
    u64 GetSystemTick(void);
    void func_0201a134(s32);
    s32 startTick;
    M2C_FIELD(&gNetStack, void (**)(void), NETSTACK_UPDATE)();
    if (!M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP)) return;
    SendArpRequest(M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP));
    SleepMilliseconds(ARP_RETRY_MS);
    SendArpRequest(M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP));
    startTick = (u32)(GetSystemTick() >> 16);
    goto check;
    loop:
    {
        if (M2C_FIELD(&gNetStack, u8 *, NETSTACK_ARP_RESOLVED)) {
            func_0201a134(4);
            return;
        }
        SleepMilliseconds(ARP_RETRY_MS);
    }
    check:
    if (!M2C_FIELD(&gNetStack, s32 (**)(void), NETSTACK_POLL)()) return;
    if ((s32)((u32)(GetSystemTick() >> 16) - startTick) < NETSTACK_ARP_TIMEOUT) goto loop;
}

void func_0201dd08(void) {
    extern M2C_UNK gNetStack;
    extern M2C_UNK gSocketManager;
    extern u8 data_02137370[];
    extern u8 data_021375b8[];
    extern u8 data_0213793c[];
    extern u8 data_021377bc[];
    extern u8 gArpCache[];
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    u64 GetSystemTick(void);
    void SleepMilliseconds(s32);
    void AnnounceLocalAddress(void);
    s32 DhcpDiscoverOffer(void);
    s32 func_0201e7ac(u32 *, s32);
    void func_0201a134(s32);
    void SetCurrentRawConnection(void *);
    void ClearCurrentRawConnection(void);
    void SendArpRequest(s32);
    void func_020251b8(u32);
    void SendDhcpRelease(void);
    void TaskWake(void *);

    s32 state;
    u32 wait;
    register s32 flag;
    register s32 count;
    u32 tick;

    M2C_FIELD(&gNetStack, u32 *, 0x44) = 0;
    MI_CpuFill8((s32)data_02137370, 0, 0x64);
    M2C_FIELD(&gNetStack, s32 *, 0x11c) = 0x180;
    M2C_FIELD(&gNetStack, void **, 0x120) = data_0213793c;
    M2C_FIELD(&gNetStack, s32 *, 0x128) = 0x180;
    M2C_FIELD(&gNetStack, void **, 0x12c) = data_021377bc;
    SetCurrentRawConnection(data_02137370);
    count = 1;
    flag = 1;
    wait = M2C_FIELD(&gNetStack, s32 *, 0xc) = 1;
    state = 0;
    for (;;) {
        SleepMilliseconds(0x3e8);
        if (M2C_FIELD(&gNetStack, u32 *, 0x44) != 0) break;
        tick = (u32)(GetSystemTick() >> 16);
        if (M2C_FIELD(&gNetStack, s32 (**)(void), 0x48)() != 0) {
            if (--wait == 0) {
                if (M2C_FIELD(&gNetStack, u32 *, 0x10) & 1) {
                    if (state == 0) {
                        AnnounceLocalAddress();
                        state = 1;
                    }
                } else {
                    switch (state) {
                    case 0:
                        if (flag) {
                            M2C_FIELD(&gNetStack, s32 *, 0xc) = 2;
                            flag = 0;
                        }
                        if (DhcpDiscoverOffer()) {
                            if (func_0201e7ac(&wait, 0)) goto connected;
                        }
                        AnnounceLocalAddress();
                        state = 3;
                        break;
                    connected:
                        state = 1;
                        break;
                    case 1:
                        if (!func_0201e7ac(&wait, 1)) {
                            if (wait < 0x3c) state = 2;
                        }
                        break;
                    case 2:
                        if (func_0201e7ac(&wait, 2)) {
                            state = 1;
                        } else if (wait < 0x3c) {
                            func_0201a134(3);
                            count = 1;
                            wait = 1;
                            state = 0;
                        }
                        break;
                    case 3:
                        break;
                    }
                }
            }
        } else {
            func_0201a134(1);
            count = 1;
            wait = 1;
            state = 0;
        }
        {
            s32 i;
            u8 *e = gArpCache;
            for (i = 0; i < 8; i++, e += 0xc) {
                if (M2C_FIELD(e, u32 *, 0) != 0) {
                    if ((s16)(tick - M2C_FIELD(e, u16 *, 0xa)) > 0x3bd) {
                        M2C_FIELD(e, u32 *, 0) = 0;
                    }
                }
            }
        }
        { s32 address = M2C_FIELD(&gNetStack, s32 *, 0x2c);
        if (address != 0) {
            if (--count == 0) {
                SendArpRequest(address);
                count = 0x69;
            }
        }
        }
        {
            void *node = M2C_FIELD(&gSocketManager, void **, 8);
            while (node) {
                u8 *obj = M2C_FIELD(node, u8 **, 0xa4);
                if (obj && M2C_FIELD(obj, u32 *, 0)) {
                    s32 kind = M2C_FIELD(obj, u8 *, 8);
                    if (kind == 3 && (s32)(tick - M2C_FIELD(obj, u32 *, 0x10)) > 0x27) {
                            M2C_FIELD(obj, u8 *, 8) = 1;
                            M2C_FIELD(obj, u16 *, 0x18) = M2C_FIELD(obj, u16 *, 0x1a);
                            M2C_FIELD(obj, u32 *, 0x1c) = M2C_FIELD(obj, u32 *, 0x20);
                    } else if (kind == 2 && (s32)(tick - M2C_FIELD(obj, u32 *, 0x10)) > 0x27) {
                            if (M2C_FIELD(obj, u32 *, 4) == 1) {
                                M2C_FIELD(obj, u8 *, 8) = 0;
                                M2C_FIELD(obj, u32 *, 4) = 0;
                                TaskWake(M2C_FIELD(obj, void **, 0));
                            }
                    } else if (kind != 4 && M2C_FIELD(obj, u32 *, 4) == 2) {
                        M2C_FIELD(obj, u32 *, 4) = 0;
                        TaskWake(M2C_FIELD(obj, void **, 0));
                    }
                }
                node = M2C_FIELD(node, void **, 0x68);
            }
        }
        {
            u8 *e;
            s32 i;
            e = data_021375b8;
            for (i = 0; i < 8; i++, e += 0x38) {
                if (M2C_FIELD(e, u16 *, 4) != 0) {
                    if ((s32)(tick - M2C_FIELD(e, u32 *, 0x2c)) > 0xef) {
                        ((void (*)(u32))M2C_FIELD(&gNetStack, u32 *, 0x40))(M2C_FIELD(e, u32 *, 0x34));
                        M2C_FIELD(e, u16 *, 4) = 0;
                    }
                }
            }
        }
        func_020251b8(tick);
        if (M2C_FIELD(&gNetStack, u32 *, 0x3c) != 0) {
            ((void (*)(void))M2C_FIELD(&gNetStack, u32 *, 0x3c))();
        }
    }
    if (!(M2C_FIELD(&gNetStack, u32 *, 0x10) & 1) && state != 3) SendDhcpRelease();
    ClearCurrentRawConnection();
}

#pragma opt_common_subs off
/* Builds a BOOTP/DHCP request packet at `packet`: a fixed header carrying a
 * fresh transaction id (also returned through `xidOut`), the local MAC address
 * as the client hardware address, and the options that follow the magic cookie
 * (message type `msgType`, client identifier, host name and the parameter
 * request list).  Returns the address just past the options. */
u8 *BuildDhcpPacket(u8 *packet, s32 msgType, s32 xidOut) {
    extern M2C_UNK gNetStack;
    extern M2C_UNK gLocalMacAddress;
    extern M2C_UNK gDhcpHostName;
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    void MI_CpuCopy8(s32, u8 *, s32);
    u32 xid;

    MI_CpuFill8((s32)packet, 0, DHCP_OFF_OPTIONS);
    *(u16 *)packet = 0x101;
    packet[DHCP_OFF_HLEN] = 6;
    xid = NextPacketRandom();
    if (xidOut) *(u32 *)xidOut = xid;
    *(u16 *)(packet + DHCP_OFF_XID) = PacketSwap(xid >> 16);
    *(u16 *)(packet + DHCP_OFF_XID + 2) = PacketSwap(xid);
    *(u16 *)(packet + DHCP_OFF_CIADDR) = PacketSwap(M2C_FIELD(&gNetStack, u32 *, NETSTACK_LOCAL_IP) >> 16);
    *(u16 *)(packet + DHCP_OFF_CIADDR + 2) = PacketSwap(M2C_FIELD(&gNetStack, u32 *, NETSTACK_LOCAL_IP));
    MI_CpuCopy8((s32)&gLocalMacAddress, packet + DHCP_OFF_CHADDR, DHCP_HWADDR_LEN);
    *(u16 *)(packet + DHCP_OFF_OPTIONS) = DHCP_MAGIC_W0;
    *(u16 *)(packet + DHCP_OFF_OPTIONS + 2) = DHCP_MAGIC_W1;
    *(u16 *)(packet + DHCP_OFF_OPTIONS + 4) = 0x0135;
    packet[0xf2] = msgType;
    packet[0xf3] = DHCP_OPT_CLIENT_ID;
    packet[0xf4] = 7;
    packet[0xf5] = 1;
    MI_CpuCopy8((s32)&gLocalMacAddress, packet + 0xf6, DHCP_HWADDR_LEN);
    packet[0xfc] = DHCP_OPT_HOSTNAME;
    packet[0xfd] = 10;
    MI_CpuCopy8((s32)&gDhcpHostName, packet + 0xfe, 10);
    packet[0x108] = DHCP_OPT_PARAM_REQ;
    packet[0x109] = 3;
    packet[0x10a] = DHCP_OPT_SUBNET;
    packet[0x10b] = DHCP_OPT_ROUTER;
    packet[0x10c] = DHCP_OPT_DNS;
    return packet + 0x10d;
}
#pragma opt_common_subs reset
/* Grow a packet that ends at `end` and is `length` bytes long to `minLength` bytes
 * with `padByte` fill, and return the packet's new end. */
s32 PadPacket(s32 padByte, u32 minLength, s32 end, u32 length) {
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    s32 extra;
    s32 newEnd;

    newEnd = end;
    if (length < minLength) {
        extra = minLength - length;
        MI_CpuFill8(newEnd, padByte, extra);
        newEnd += extra;
    }
    return newEnd;
}

#pragma opt_common_subs off
/* Builds and sends a DHCPDISCOVER (message type 1) from gDhcpPacketBuffer:
 * when the client asked for an address before (NETSTACK_REQUESTED_IP), option 50
 * asks for it again; the options end with the end marker and the packet is
 * padded to DHCP_PACKET_MIN bytes before it is sent.  Returns the transaction
 * id the request was built with. */
s32 BuildDhcpDiscover(void) {
extern M2C_UNK gNetStack; extern u8 gDhcpPacketBuffer[];
u8 *BuildDhcpPacket(u8 *,s32,s32);
u8 *p; s32 result; s32 base=(s32)gDhcpPacketBuffer;
p=BuildDhcpPacket((u8 *)base,DHCP_MSG_DISCOVER,(s32)&result);
if(M2C_FIELD(&gNetStack,u32 *,NETSTACK_REQUESTED_IP)) {
p[0]=DHCP_OPT_REQUESTED_IP; p[1]=4;
p[2]=(u16)(M2C_FIELD(&gNetStack,u32 *,NETSTACK_REQUESTED_IP)>>16)>>8;
p[3]=M2C_FIELD(&gNetStack,u32 *,NETSTACK_REQUESTED_IP)>>16;
p[4]=(u16)M2C_FIELD(&gNetStack,u32 *,NETSTACK_REQUESTED_IP)>>8;
p[5]=M2C_FIELD(&gNetStack,u32 *,NETSTACK_REQUESTED_IP);
p+=6;
}
*p++=DHCP_OPTION_END;
p=(u8 *)PadPacket(0,DHCP_PACKET_MIN,(s32)p,(s32)p-base);
SendNetPacket(base,(s32)p-base);
return result;
}
#pragma opt_common_subs off
/* Build a DHCPREQUEST (message type 3) into gDhcpPacketBuffer and send it: on
 * the first attempt (mode 0) it asks for the address in gNetStack and names the
 * server that offered it; later attempts (renew/rebind) omit both options. The
 * packet is padded to DHCP_PACKET_MIN bytes before it is sent. */
s32 BuildDhcpRequest(s32 mode) {
    extern M2C_UNK gNetStack;
    extern u8 gDhcpPacketBuffer[];
    u8 *BuildDhcpPacket(u8 *, s32, s32);
    s32 PadPacket(M2C_UNK, u32, s32, u32);
    u32 SendNetPacket(s32, s32);

    u8 *p;
    u16 addressHi;
    s32 result;
    s32 base = (s32) gDhcpPacketBuffer;

    p = BuildDhcpPacket((u8 *) base, DHCP_MSG_REQUEST, (s32) &result);
    if (mode == 0) {
        p[0] = DHCP_OPT_REQUESTED_IP; p[1] = 4;
        addressHi = M2C_FIELD(&gNetStack, u32 *, NETSTACK_REQUESTED_IP) >> 16;
        p[2] = addressHi >> 8;
        p[3] = M2C_FIELD(&gNetStack, u32 *, NETSTACK_REQUESTED_IP) >> 16;
        p[4] = (u16) M2C_FIELD(&gNetStack, u32 *, NETSTACK_REQUESTED_IP) >> 8;
        p[5] = M2C_FIELD(&gNetStack, u32 *, NETSTACK_REQUESTED_IP);
        p[6] = DHCP_OPT_SERVER_ID; p[7] = 4;
        addressHi = M2C_FIELD(&gNetStack, u32 *, NETSTACK_DHCP_SERVER) >> 16;
        p[8] = addressHi >> 8;
        p[9] = M2C_FIELD(&gNetStack, u32 *, NETSTACK_DHCP_SERVER) >> 16;
        p[10] = (u16) M2C_FIELD(&gNetStack, u32 *, NETSTACK_DHCP_SERVER) >> 8;
        p[11] = M2C_FIELD(&gNetStack, u32 *, NETSTACK_DHCP_SERVER);
        p += 12;
    }
    *p++ = DHCP_OPTION_END;
    p = (u8 *) PadPacket(0, DHCP_PACKET_MIN, (s32) p, (s32) p - base);
    SendNetPacket(base, (s32) p - base);
    return result;
}
s32 func_0201e404(s32 arg0, s32 arg1) {
    u64 GetSystemTick(void);
    s32 GetSocketReceivedDataSize(void);
    void NetStackWaitIdle(void);
    s32 PeekSocketReceivedData(s32 *);
    s32 MacAddressesDiffer(u16 *, u16 *);
    void ConsumeConnectionReceivedData(s32);
    extern M2C_UNK gNetStack;
    extern M2C_UNK gLocalMacAddress;

    s32 slots[2];
    u32 timer;
    s32 result;
    s32 limit;
    s32 len;
    u8 *endb;
    u8 *cur;
    u8 *q;
    u8 tag;
    u32 combo;
    u32 now;
    u8 flen;
    u16 t0, t1;
    u32 xid;

    slots[0] = arg0;
    limit = (arg1 + 1) * 15;
    timer = (u32)(GetSystemTick() >> 16);
    result = 0;
    goto timer_check;

top_loop:
    if (GetSocketReceivedDataSize() == 0) {
        NetStackWaitIdle();
    } else {
        q = (u8 *)PeekSocketReceivedData(&slots[1]);
        if ((u32)slots[1] <= 0xF0) goto fail;
        if (q[0] != 2) goto fail;
        if (!PacketTransactionMatches((u16 *)(q+4), (u32 *)slots)) goto fail;
        if (MacAddressesDiffer((u16 *)(q + 0x1C), (u16 *)&gLocalMacAddress) != 0) goto fail;

        combo = PacketRead32(q+0x10);
        result = 3;

        cur = q + 0xF0;
        endb = q + slots[1];
        if (q[0xEC] != 0x63 || q[0xED] != 0x82 || q[0xEE] != 0x53) goto fail;
        cur = q + 0xF0;
        if (q[0xEF] != 0x63) goto fail;


        goto option_check;
        while (1) {
            if (tag == 0) goto option_check;
            switch (tag) {
            case 0x01:
                M2C_FIELD(&gNetStack, u32 *, 0x1C) =
                    PacketRead32(cur+1);
                break;
            case 0x03:
                M2C_FIELD(&gNetStack, u32 *, 0x2C) =
                    PacketRead32(cur+1);
                break;
            case 0x06:
                if (cur[0] < 8) {
                    M2C_FIELD(&gNetStack, u32 *, 0x64) = 0;
                } else {
                    M2C_FIELD(&gNetStack, u32 *, 0x64) =
                        PacketRead32(cur+5);
                }
                M2C_FIELD(&gNetStack, u32 *, 0x60) =
                    PacketRead32(cur+1);
                break;
            case 0x33:
                M2C_FIELD(&gNetStack, u32 *, 0x4c) = PacketRead32(cur+1);
                break;
            case 0x35:
                switch (cur[1]) {
                case 2:
                    result = 1;
                    M2C_FIELD(&gNetStack, u32 *, 0x34) = combo;
                    break;
                case 5:
                    result = 2;
                    M2C_FIELD(&gNetStack, u32 *, 0x50) = combo;
                    break;
                }
                break;
            case 0x36:
                M2C_FIELD(&gNetStack, u32 *, 0x20) =
                    PacketRead32(cur+1);
                break;
            default:
                break;
            }

            flen = cur[0];
            cur += flen + 1;
        option_check:
            if (cur >= endb) goto fail;
            tag = *cur++;
            if (tag == 0xFF) goto fail;
        }
        fail:
        ConsumeConnectionReceivedData(slots[1]);
    }

timer_check:
    if (M2C_FIELD(&gNetStack, s32 (**)(void), 0x48)() == 0) goto final;
    if (result != 0) goto final;
    now = (u32)(GetSystemTick() >> 16);
    if ((s32)(now - timer) < limit) goto top_loop;

final:
    return result;
}
#pragma opt_common_subs reset
/* Fetch an address offer: open a raw connection to the DHCP server, send
 * DHCPDISCOVER up to four times (each with a fresh transaction id) and return 1
 * once an OFFER arrives, otherwise 0.  The raw connection is closed either way. */
s32 DhcpDiscoverOffer(void) {
    M2C_UNK OpenRawConnection();
    M2C_UNK SetConnectionEndpoint(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK ResetCurrentConnection();
    M2C_UNK CloseRawConnection();
    s32 BuildDhcpDiscover();
    s32 func_0201e404(s32, s32);
    s32 result;
    s32 attempt;

    ResetCurrentConnection();
    OpenRawConnection();
    SetConnectionEndpoint(DHCP_CLIENT_PORT, DHCP_SERVER_PORT, -1);
    attempt = 0;
loop_1:
    result = func_0201e404(BuildDhcpDiscover(), attempt);
    if (result != 1) {
        attempt += 1;
        if (attempt < 4) {
            goto loop_1;
        }
    }
    CloseRawConnection();
    if (result == 1) {
        return 1;
    }
    return 0;
}

/* Attempt up to four times to exchange a data packet with a peer.
 * On a peer-data match (result 2) record the peer's size info and return
 * success; otherwise halve the stored timeout and apply a mode-specific floor. */
s32 func_0201e7ac(u32 *out_size, s32 mode) {
    s32 BuildDhcpRequest(s32);
    extern M2C_UNK gNetStack;
    s32 result;
    s32 attempt;
    u32 timeout;

    ResetCurrentConnection();
    OpenRawConnection();
    if (mode == 1) {
        SetConnectionEndpoint(0x44, 0x43, M2C_FIELD(&gNetStack, s32 *, 0x20));
    } else {
        SetConnectionEndpoint(0x44, 0x43, -1);
    }
    attempt = 0;
loop_4:
    result = func_0201e404(BuildDhcpRequest(mode), attempt);
    if (result == 0) {
        attempt += 1;
        if (attempt < 4) {
            goto loop_4;
        }
    }
    CloseRawConnection();
    if (result == 2) {
        *out_size = (u32) M2C_FIELD(&gNetStack, u32 *, 0x4C) >> 1;
        M2C_FIELD(&gNetStack, u32 *, 0x38) = (u32) ((u32) (M2C_FIELD(&gNetStack, u32 *, 0x4C) * 3) >> 3);
        return 1;
    }
    timeout = (u32) M2C_FIELD(&gNetStack, u32 *, 0x38) >> 1;
    M2C_FIELD(&gNetStack, u32 *, 0x38) = timeout;
    *out_size = timeout;
    switch (mode) {                                 /* irregular */
    case 1:
        if (timeout < 0x3CU) {
            *out_size = 1;
            M2C_FIELD(&gNetStack, u32 *, 0x38) = (u32) ((u32) M2C_FIELD(&gNetStack, u32 *, 0x4C) >> 3);
        }
        break;
    case 2:
        if (timeout < 0x3CU) {
            *out_size = 1;
        }
        break;
    }
    return 0;
}

/* Send a DHCP RELEASE to the server this host took its address from: open a raw
 * connection to the DHCP server, build the release packet, end its options, pad
 * it to the minimum packet size and send it, then close the connection. */
void SendDhcpRelease(void) {
    extern M2C_UNK gNetStack;
    extern u8 gDhcpPacketBuffer[];
    u8 *BuildDhcpPacket(u8 *, s32, s32);
    s32 p;
    s32 base;

    ResetCurrentConnection();
    OpenRawConnection();
    SetConnectionEndpoint(DHCP_CLIENT_PORT, DHCP_SERVER_PORT, M2C_FIELD(&gNetStack, s32 *, NETSTACK_DHCP_SERVER));
    base = (s32)gDhcpPacketBuffer;
    p = (s32)BuildDhcpPacket((u8 *)base, DHCP_MSG_RELEASE, 0);
    M2C_FIELD(p, u8 *, 0) = DHCP_OPTION_END;
    p++;
    p = PadPacket(0, DHCP_PACKET_MIN, (s32)p, p - base);
    SendNetPacket((s32)base, p - base);
    CloseRawConnection();
}

/* Skip over a DNS name in a response: walk its length-prefixed labels and stop
 * after the two bytes of a compression pointer (top bits 11) or at the
 * terminating zero label; returns the pointer just past the name. */
u8 *DnsSkipName(u8 *p) {
    u32 len = *p++;
    while (len) {
        if ((len & 0xC0) == 0xC0) return p + 1;
        p += len;
        len = *p++;
    }
    return p;
}

