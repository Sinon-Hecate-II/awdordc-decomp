/* 30 functions from 0x0205CB68 to 0x0205DA30 (main), found by ds-decomp. */
#include "common.h"
#include "gt2.h"
#include "natneg.h"
#include "ghttp.h"
struct BytePair_0205 { u8 v[2]; };
struct Packet_0205 { u8 a,b; u16 c; s32 d; };
struct SocketInit_0205 { u16 port; s32 len; s32 addr; struct Packet_0205 pkt; };

#pragma push
#pragma opt_global_reg off
/* Send a bare "connection closed" control message - the two magic bytes and the
 * long-form closed id - to a peer the socket has no connection for, so it drops
 * whatever it thinks it has. */
s32 gti2SendClosedOnSocket(s32 socket, s32 address, s32 port) {
    s32 gti2SocketSend(void *, s32, s32, void *, s32);
    extern u8 gGt2Magic[];
    u8 buffer[3];
    struct BytePair_0205 *magic = (struct BytePair_0205 *)buffer;

    const struct BytePair_0205 *header = (const struct BytePair_0205 *)gGt2Magic;
    u8 first = header->v[0], second = header->v[1];
    buffer[2] = GTI2_LARGE_CLOSED;
    magic->v[0] = first;
    magic->v[1] = second;
    return gti2SocketSend((void *)socket, address, port, magic, 3) != 0;
}
#pragma pop
/* Resend one queued sent command the peer has not acknowledged: write the
 * current receive sequence into the command's bytes, send them raw and record
 * the send time.  When the command was our CONNECT_ACCEPT, restart the
 * connection's start-time clock.  Returns 0 when the send fails. */
s32 gti2ResendPendingCommand(void *connection, Gt2SentCommand *command) {
    void Gt2WriteShort(void *, s32, u16);
    s32 gti2SendRaw(void *, void *, s32);
    Gt2WriteShort(M2C_FIELD(connection, void **, GT2_CONNECTION_SEND_BUFFER), command->offset + 5,
                  M2C_FIELD(connection, u16 *, GT2_RECV_SEQUENCE));
    if (!gti2SendRaw(connection, M2C_FIELD(connection, u8 **, GT2_CONNECTION_SEND_BUFFER) + command->offset, command->size)) return 0;
    command->lastSent = M2C_FIELD(connection, s32 *, GT2_CONNECTION_LAST_SENT);
    if (M2C_FIELD(connection, u8 **, GT2_CONNECTION_SEND_BUFFER)[command->offset + 2] == GTI2_CONNECT_ACCEPT)
        M2C_FIELD(connection, s32 *, GT2_CONNECTION_START_TIME) = M2C_FIELD(connection, s32 *, GT2_CONNECTION_LAST_SENT);
    return 1;
}

/* Forward an outgoing GT2 message to the reliable or the unreliable sender. */
void gti2Send(void *connection, const u8 *message, s32 length, s32 reliable) {
    s32 gti2SendReliableMessage(void *, const u8 *, s32);
    s32 gti2SendUnreliable(void *, const u8 *, s32);
    if (reliable) {
        gti2SendReliableMessage(connection, message, length);
        return;
    }
    gti2SendUnreliable(connection, message, length);
}

/* Hash a connection-table key (remote address and port) into a bucket of the
 * socket's connection table: (address * port) modulo the bucket count. */
s32 HashConnectionLookup(void **key, s32 bucketCount) {
    GT2ConnectionLookup *lookup = *key;
    s64 U32DivideRem(s32, s32);
    return (s32)(U32DivideRem(M2C_FIELD(lookup, s32 *, GT2_CONNECTION_IP) * (s32)M2C_FIELD(lookup, u16 *, GT2_CONNECTION_PORT), bucketCount) >> 32);
}

/* Compare two connection-table keys (GT2ConnectionLookup) for the socket's
 * connection hash: by remote address, then by remote port.  Returns 0 when they
 * name the same peer, like a strcmp difference otherwise. */
s32 CompareConnectionLookups(void **a, void **b) {
GT2ConnectionLookup *key=*a,*other=*b; s32 otherAddress=M2C_FIELD(other,s32 *,0),address=M2C_FIELD(key,s32 *,0);
if(address!=otherAddress)return address-otherAddress;
return (s16)(M2C_FIELD(key,u16 *,GT2_CONNECTION_PORT)-M2C_FIELD(other,u16 *,GT2_CONNECTION_PORT));
}

/* Element destructor of a GT2 socket's connection vector: free the connection
 * pointer the element holds. */
void gti2FreeConnectionElement(s32 *element) {
    M2C_UNK gti2FreeConnection(s32);
    gti2FreeConnection(*element);
}

/* Find this socket's connection to a remote address and port, or 0 when it has
 * none.  The socket's table is keyed by a pointer to the address/port pair. */
s32 gti2FindConnection(void *socket, s32 address, s32 port) {
    s32 *TableLookup(s32, void *);
    s32 keyStorage[40]; /* the key, plus the spare stack the original build keeps */
    void *keyPtr;
    s32 *connection;

    keyStorage[0] = address;
    M2C_FIELD(keyStorage, s16 *, 4) = port;
    keyPtr = keyStorage;
    connection = TableLookup(M2C_FIELD(socket, s32 *, GT2_SOCKET_CONNECTION_TABLE), &keyPtr);
    if (connection) return *connection;
    return 0;
}

#pragma push
#pragma scheduling off
s32 gti2CreateSocket(void **a, char *b, s32 c, s32 d, s32 e) {
void func_0204926c(void);
s32 gt2StringToAddress(char *,s32 *,u16 *);
M2C_UNK gpiMalloc(s32);
void MemSet(void *,s32,s32);
s32 TableNew2(s32,s32,s32,void *,void *,s32);
s32 Vector_New(s32,s32,void (*)(void *));
s32 gpiFree(void *);
M2C_UNK TableFree(s32);
s32 Vector_Free(s32);
s32 ghiSocket(s32,s32,s32);
s32 ghiBind(s32,void *,s32);
M2C_UNK ghiCloseSocket(s32);
s32 ghiGetSockName(s32,void *,s32 *);
u16 port;
s32 addr;
s32 len;
void *p;
s32 swapped;
func_0204926c();
if(d==0)d=0x10000;
if(c==0)c=0x10000;
if(!gt2StringToAddress(b,&addr,&port))return 4;
p=(void *)gpiMalloc(0x44);
if(!p)return 1;
MemSet(p,0,0x44);
M2C_FIELD(p,s32 *,0)=-1;
M2C_FIELD(p,s32 *,0x3c)=d;
M2C_FIELD(p,s32 *,0x38)=c;
M2C_FIELD(p,s32 *,0x24)=e;
M2C_FIELD(p,s32 *,0xc)=TableNew2(4,0x20,2,HashConnectionLookup,CompareConnectionLookups,0);
if(!M2C_FIELD(p,s32 *,0xc)){gpiFree(p);return 1;}
M2C_FIELD(p,s32 *,0x10)=Vector_New(4,4,(void (*)(void *))gti2FreeConnectionElement);
if(!M2C_FIELD(p,s32 *,0x10)){TableFree(M2C_FIELD(p,s32 *,0xc));gpiFree(p);return 1;}
M2C_FIELD(p,s32 *,0)=ghiSocket(2,2,0);
if(M2C_FIELD(p,s32 *,0)==-1){TableFree(M2C_FIELD(p,s32 *,0xc));Vector_Free(M2C_FIELD(p,s32 *,0x10));gpiFree(p);return 3;}
swapped=((port>>8)&0xff)|((port<<8)&0xff00);
{ struct Packet_0205 pkt={0};
pkt.b=2;
pkt.d=addr;
pkt.c=swapped;
if(ghiBind(M2C_FIELD(p,s32 *,0),&pkt,8)==-1){
ghiCloseSocket(M2C_FIELD(p,s32 *,0));TableFree(M2C_FIELD(p,s32 *,0xc));Vector_Free(M2C_FIELD(p,s32 *,0x10));gpiFree(p);return 3;
}
len=8;ghiGetSockName(M2C_FIELD(p,s32 *,0),&pkt,&len);
M2C_FIELD(p,s32 *,4)=pkt.d;
M2C_FIELD(p,u16 *,8)=((pkt.c>>8)&0xff)|((pkt.c<<8)&0xff00);
*a=p;return 0;
}
}
#pragma pop
/* Free a GT2 socket: defer the free while one of its callbacks is running (the
 * outermost callback frees it), otherwise close its OS handle and free its
 * connection table, its connection vector and the socket itself. */
void gti2FreeSocket(void *socket) {
M2C_UNK gpiFree(void *);M2C_UNK TableFree(s32);M2C_UNK func_02049270();M2C_UNK ghiCloseSocket(s32);
if(M2C_FIELD(socket,s32 *,GT2_SOCKET_CALLBACKS)!=0){M2C_FIELD(socket,s32 *,GT2_SOCKET_DIRTY)=1;return;}
ghiCloseSocket(M2C_FIELD(socket,s32 *,GT2_SOCKET_HANDLE));TableFree(M2C_FIELD(socket,s32 *,GT2_SOCKET_CONNECTION_TABLE));Vector_Free(M2C_FIELD(socket,s32 *,GT2_SOCKET_CONNECTIONS));gpiFree(socket);func_02049270();
}

void gti2SocketSetConnectAttempt(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
}

/* Allocates a GT2 connection object (gti2CreateConnection zeroes and fills it). */
void *gti2AllocateConnection(void) {
    M2C_UNK gpiMalloc(M2C_UNK);
    return (void *)gpiMalloc(GT2_CONNECTION_SIZE);
}

/* Create a GT2 connection for remote address/port on the given owner (socket
 * or parent connection): reject it if one is already registered, otherwise
 * allocate and initialise it, create its two buffers and its hash tables, add
 * it to the owner's table and hand it back through connOut. Returns 0 on
 * success, 5 if the connection already exists and 1 on allocation failure. */
s32 gti2CreateConnection(void *owner, s32 connOut, s32 address, s16 port) {
    s32 gti2FindConnection(void *, s32, s32);
    void *gti2AllocateConnection(void);
    void MemSet(void *, s32, s32);
    s32 GetSystemTickMilliseconds(void);
    s32 gti2AllocateBuffer(void *, s32);
    s32 Vector_New(s32, s32, void (*)(void *));
    void TableEnter(void *, void **);
    s32 gpiFree(void *);
    s32 Vector_Free(s32);

    void *conn = 0;
    s32 timestamp;
    s32 result;

    if (((s32 (*)(void *, s32, s16, s32))gti2FindConnection)(owner, address, (s16)port, 0) != 0) {
        return 5;
    }

    conn = gti2AllocateConnection();
    if (conn == 0) {
        goto fail;
    }

    MemSet(conn, 0, 0xA0);
    *(s32 *)conn = address;
    *(u16 *)((u8 *)conn + 4) = (u16)port;
    *(void **)((u8 *)conn + 8) = owner;
    timestamp = GetSystemTickMilliseconds();
    *(s32 *)((u8 *)conn + 0x1C) = timestamp;
    *(s32 *)((u8 *)conn + 0x88) = *(s32 *)((u8 *)conn + 0x1C);
    *(u16 *)((u8 *)conn + 0x64) = 0;
    *(u16 *)((u8 *)conn + 0x66) = 0;

    /* receive and send buffers sized from the owner's limits */
    if (gti2AllocateBuffer((u8 *)conn + 0x44, *(s32 *)((u8 *)owner + 0x3C)) == 0) {
        goto fail;
    }
    if (gti2AllocateBuffer((u8 *)conn + 0x50, *(s32 *)((u8 *)owner + 0x38)) == 0) {
        goto fail;
    }

    result = Vector_New(0x10, 0x40, 0);
    *(s32 *)((u8 *)conn + 0x5C) = result;
    if (*(s32 *)((u8 *)conn + 0x5C) == 0) {
        goto fail;
    }

    result = Vector_New(0x10, 0x40, 0);
    *(s32 *)((u8 *)conn + 0x60) = result;
    if (*(s32 *)((u8 *)conn + 0x60) == 0) {
        goto fail;
    }

    result = Vector_New(0x4, 0x2, 0);
    *(s32 *)((u8 *)conn + 0x98) = result;
    if (*(s32 *)((u8 *)conn + 0x98) == 0) {
        goto fail;
    }

    result = Vector_New(0x4, 0x2, 0);
    *(s32 *)((u8 *)conn + 0x9C) = result;
    if (*(s32 *)((u8 *)conn + 0x9C) == 0) {
        goto fail;
    }

    TableEnter(*(void **)((u8 *)owner + 0xC), &conn);
    result = gti2FindConnection(owner, address, (s16)port);
    *(s32 *)connOut = result;
    if (result != 0) {
        return 0;
    }

fail:
    if (conn == 0) {
        goto done;
    }

    gpiFree(*(void **)((u8 *)conn + 0x44));
    gpiFree(*(void **)((u8 *)conn + 0x50));

    result = *(s32 *)((u8 *)conn + 0x5C);
    if (result != 0) {
        Vector_Free(result);
    }
    result = *(s32 *)((u8 *)conn + 0x60);
    if (result != 0) {
        Vector_Free(result);
    }
    result = *(s32 *)((u8 *)conn + 0x98);
    if (result != 0) {
        Vector_Free(result);
    }
    result = *(s32 *)((u8 *)conn + 0x9C);
    if (result != 0) {
        Vector_Free(result);
    }

    gpiFree(conn);

done:
    return 1;

}

#pragma scheduling off
/* Remove a GT2 connection from the structures tracking it on its owning socket:
 * a closed connection is dropped from the socket's connection vector, any other
 * from its address/port table.  Does nothing while a close is pending or a
 * callback is still running on the connection. */
void gti2RemoveConnection(s32 conn)
{
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem(s32, s32);
    void Vector_RemoveItem(s32, s32);
    void TableRemove(s32, void *);
    if (M2C_FIELD((void *)conn, s32 *, GT2_CONNECTION_CLOSE_PENDING) || M2C_FIELD((void *)conn, s32 *, GT2_CONNECTION_CALLBACKS)) {
        return;
    }
    if (M2C_FIELD((void *)conn, s32 *, GT2_CONNECTION_STATE) == GT2_STATE_CLOSED) {
        s32 count = Vector_GetCount(M2C_FIELD(M2C_FIELD((void *)conn, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECTIONS));
        s32 i = 0;
        if (count <= 0) return;
        do {
            if (conn == *Vector_GetItem(M2C_FIELD(M2C_FIELD((void *)conn, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECTIONS), i)) {
                Vector_RemoveItem(M2C_FIELD(M2C_FIELD((void *)conn, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECTIONS), i);
                return;
            }
            i++;
        } while (i < count);
        return;
    } else {
        TableRemove(M2C_FIELD(M2C_FIELD((void *)conn, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECTION_TABLE), &conn);
    }
    return;
}
#pragma scheduling reset
s32 gti2SocketSend(void *p, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    void gti2NormalizeMessage(M2C_UNK **, s32 *);
    s32 ghiSocketCanSend(s32);
    s32 ghiSendTo(s32, s32, s32, s32, void *, s32);
    s32 ghiGetLastSocketError(s32);
    s32 func_0205c244(void *, s32, s32);
    void gti2SocketError(void *);
    s32 gti2FindConnection(void *, s32, s32);
    s32 gti2DumpCallback(void *, void *, s32, s32, s32, s32, s32, s32);


    s32 res;

    gti2NormalizeMessage((M2C_UNK **)&arg3, &arg4);

    if (ghiSocketCanSend(*(s32 *)p) == 0) {
        return 1;
    }

    {
    struct Packet_0205 pkt={0};
    pkt.c = (u16)(((arg2 >> 8) & 0xff) | ((arg2 << 8) & 0xff00));
    pkt.b = 2;
    pkt.d = arg1;

    res = ghiSendTo(*(s32 *)p, (s32)arg3, arg4, 0, &pkt, 8);
    if (res == -1) {
        s32 r = ghiGetLastSocketError(*(s32 *)p);
        if (r == -15) {
            s32 c = func_0205c244(p, arg1, arg2);
            if (c != 0) {
                goto success;
            }
            return 0;
        }
        if (r == -42 || r == -6) {
            return 1;
        }
        if (r == -35) {
            goto success;
        }
        gti2SocketError(p);
        return 0;
    }

    if (*(s32 *)((u8 *)p + 0x28) == 0) {
        goto success;
    }

    {
        void *cca = (void *)gti2FindConnection(p, arg1, arg2);
        s32 t = gti2DumpCallback(p, cca, arg1, arg2, 0, (s32)arg3, arg4, 1);
        if (t == 0) {
            return 0;
        }
    }

success:
    return 1;
    }
}

/* Advance a connection's timers and retries, then remove it once closed and no callbacks remain. */
s32 gti2ThinkAndReapConnection(void **connectionArg, void **nowArg) {
    void *connection = *connectionArg;
    void *now = *nowArg;

    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) != GT2_STATE_CLOSED) {
        if (!gti2ThinkConnection(connection, now)) return 0;
    }
    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) == GT2_STATE_CLOSED &&
        M2C_FIELD(connection, s32 *, GT2_CONNECTION_CLOSE_PENDING) == 0 &&
        M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) == 0) {
        gti2RemoveConnection((s32)connection);
    }
    return 1;
}

/* Advance every connection the socket owns: walk its connection table with the
 * current tick, letting gti2ThinkAndReapConnection run each one's timers and
 * retries and reap the connections that closed.  Returns 1 on success, 0 when
 * the table walk was interrupted. */
s32 gti2ThinkSocketConnections(void *socket) {
    s32 TableMapSafe2(s32, s32 (*)(void **,void **), s32 *);
    s32 GetSystemTickMilliseconds();
    s32 gti2ThinkAndReapConnection(void **,void **);
    s32 now;

    now = GetSystemTickMilliseconds();
    if (TableMapSafe2(M2C_FIELD(socket, s32 *, GT2_SOCKET_CONNECTION_TABLE), &gti2ThinkAndReapConnection, &now) == 0) {
        return 1;
    }
    return 0;
}

/* Remove every connection of the socket that has been closed: walk the socket's
 * closed-connection vector from the end and remove each connection from it. */
void gti2RemoveClosedConnections(void *socket) {
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem(s32, s32);
    s32 index;

    index = Vector_GetCount(M2C_FIELD(socket, s32 *, GT2_SOCKET_CONNECTIONS)) - 1;
    if (index < 0) {
        return;
    }
    do {
        gti2RemoveConnection(*Vector_GetItem(M2C_FIELD(socket, s32 *, GT2_SOCKET_CONNECTIONS), index));
        index -= 1;
    } while (index >= 0);
}

/* Fail a GT2 socket once, when a raw send or receive hit an unrecoverable
 * error: fail every connection the socket owns through the closed notification,
 * run the socket's error callback (which may free it) and free the socket if the
 * callback left it in place. */
void gti2SocketError(void *socket) {
    void GT2NotifyConnectionClosed(void *);
    s32 gti2SocketErrorCallback(void *);

    if (M2C_FIELD(socket, s32 *, GT2_SOCKET_ERROR)) return;
    M2C_FIELD(socket, s32 *, GT2_SOCKET_ERROR) = 1;
    GT2NotifyConnectionClosed(socket);
    if (!gti2SocketErrorCallback(socket)) return;
    gti2FreeSocket(socket);
}

/* GameSpy GT2 gt2AddressToString: format an IPv4 address and/or a port as
   "ip:port", "ip" or ":port" into buf, or into the next of the two rotating
   static buffers when buf is 0, and return the buffer used. */
char *gt2AddressToString(s32 ip, s32 port, char *buf) {
    s32 IpToString(s32);
    s32 StringFormat(char *, const char *, ...);
    extern s32 gGt2AddressStringIndex;
    extern char gGt2AddressStringBuffers[], sGt2AddressAndPortFormat[], sGt2AddressFormat[], sGt2PortFormat[];
    volatile s32 saved;
    if (!buf) {
        gGt2AddressStringIndex ^= 1;
        buf = gGt2AddressStringBuffers + gGt2AddressStringIndex * 22;
    }
    if (ip) {
        saved = ip;
        if (port) StringFormat(buf, sGt2AddressAndPortFormat, IpToString(ip), port);
        else StringFormat(buf, sGt2AddressFormat, IpToString(ip));
    } else {
        if (!port) *buf = 0;
        else StringFormat(buf, sGt2PortFormat, port);
    }
    return buf;
}

#pragma opt_common_subs off
/* GameSpy GT2 gt2StringToAddress: split "host:port" into a 32-bit IPv4 address
   (resolving the host when it is not a dotted quad) and a 16-bit port.  Returns
   1 when the string was parsed, 0 otherwise. */
s32 gt2StringToAddress(char *string, s32 *ipOut, u16 *portOut) {
    char *StringFindChar(char *, s32);
    M2C_UNK AssertFailed(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void MemCopy(void *, const void *, s32);
    s32 ParseInt(char *);
    s32 ghiInetAddr(void *);
    void *ghiResolveHostname(void *);
    extern u16 gCharClassTable[];
    extern char sAssertLenHostLenMax[];
    extern char sGt2UtilityFile[];
    extern char sGt2StringToAddressFunc[];
    char hostBuf[0x104];
    char *host;
    s32 *ip;
    u16 *port;
    s32 portValue;
    s32 ipValue;

    host = string;
    ip = ipOut;
    port = portOut;
    if (host == 0 || *host == 0) { ipValue = 0; portValue = ipValue; } else {
        char *colon = StringFindChar(host, ':');
        portValue = (s32)colon;
        if (colon == 0) { portValue = 0; } else {
            if (colon == host) { host = 0; ipValue = 0; } else {
                s32 len = (s32)colon - (s32)host;
                if (len >= 0x100) {
                    AssertFailed((M2C_UNK)sAssertLenHostLenMax, (M2C_UNK)sGt2UtilityFile, (M2C_UNK)sGt2StringToAddressFunc, 0x81);
                }
                    MemCopy(hostBuf, host, len);
                    host = hostBuf;
                    hostBuf[len] = 0;
            }
                {
                    char *p = colon + 1;
                    signed char ch = *p;
                    while (ch != 0) {
                        s32 digit = (ch < 0 || ch >= 0x80) ? 0 : gCharClassTable[ch] & 8;
                        if (digit == 0) return 0;
                        p++;
                        ch = *p;
                    }
                }
            {
                s32 value = ParseInt((char *)(portValue + 1));
                if (value < 0 || value > 0xffff) {
                    return 0;
                }
                portValue = (u16)value;
            }
        }
        if (host != 0) {
            ipValue = ghiInetAddr(host);
            if (ipValue == -1) {
                void *hostent = ghiResolveHostname(host);
                if (hostent == 0) {
                    return 0;
                }
                {
                    void *addrList = *(void **)((char *)hostent + 0xc);
                    void *addr = *(void **)((char *)addrList + 0);
                    ipValue = *(s32 *)((char *)addr + 0);
                }
            }
        }
    }
    if (ip != 0) {
        *ip = ipValue;
    }
    if (port != 0) {
        *port = (u16)portValue;
    }
    return 1;
}
#pragma opt_common_subs reset
/* GameSpy GT2's gti2NormalizeMessage: fill a message passed as a null pointer in
 * with the shared empty message, and a length of -1 with the message's byte
 * length including its terminator; any other length is left alone. */
void gti2NormalizeMessage(M2C_UNK **message, s32 *length) {
    s32 StringLength(M2C_UNK *);
    extern M2C_UNK sGt2EmptyMessage;
    M2C_UNK *text;

    text = *message;
    if (text == NULL) {
        *message = &sGt2EmptyMessage;
        *length = 0;
        return;
    }
    if (*length != -1) {
        return;
    }
    *length = StringLength(text) + 1;
}

/* Find the NAT-negotiation peer record with the given address in the manager's
 * peer vector, or NULL when no peer has it. */
void *FindNatNegPeer(s32 address) {
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem(s32, s32);
    extern M2C_UNK gNatNegManager;
    s32 i;
    s32 *peer;

    if (!M2C_FIELD(&gNatNegManager, s32 *, NATNEG_PEERS)) return 0;
    for (i = 0; i < Vector_GetCount(M2C_FIELD(&gNatNegManager, s32 *, NATNEG_PEERS)); i++) {
        peer = Vector_GetItem(M2C_FIELD(&gNatNegManager, s32 *, NATNEG_PEERS), i);
        if (M2C_FIELD(peer, s32 *, NATNEG_PEER_ADDRESS) == address) return peer;
    }
    return 0;
}

/* The peer vector's element destructor: close the peer's socket, mark the handle
 * invalid and put the record's state at DONE so it cannot be reused. */
void NatNeg_DestroyPeer(void *peer) {
    s32 ghiCloseSocket(s32);
    if (M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET) != -1) ghiCloseSocket(M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET));
    M2C_FIELD(peer, s32 *, NATNEG_PEER_SOCKET) = -1;
    M2C_FIELD(peer, s32 *, NATNEG_PEER_STATE) = NATNEG_STATE_DONE;
}

s32 *NatNeg_NewPeer(void) {
extern M2C_UNK data_0213e144;
s32 Vector_New(s32,s32,void (*)(void *));
s32 func_02048688(s32); s32 *func_02048690(s32,s32);
s32 handle=M2C_FIELD(&data_0213e144,s32 *,16); s32 data[16]={0};
if(!handle)M2C_FIELD(&data_0213e144,s32 *,16)=Vector_New(64,4,NatNeg_DestroyPeer);
Vector_Append(M2C_FIELD(&data_0213e144,s32 *,16),data);
return func_02048690(M2C_FIELD(&data_0213e144,s32 *,16),func_02048688(M2C_FIELD(&data_0213e144,s32 *,16))-1);
}

/* Removes a peer from the NAT-negotiation manager's peer list. */
void NatNeg_FreePeer(s32 *peer) {
extern M2C_UNK gNatNegManager;
s32 Vector_GetCount(s32); s32 *Vector_GetItem(s32,s32);
s32 index=0;
for(;index<Vector_GetCount(M2C_FIELD(&gNatNegManager,s32 *,NATNEG_PEERS));index++) {
if(peer==Vector_GetItem(M2C_FIELD(&gNatNegManager,s32 *,NATNEG_PEERS),index)) {
Vector_RemoveAt(M2C_FIELD(&gNatNegManager,s32 *,NATNEG_PEERS),index);return;
}
}
}

/* Shut the NAT-negotiation manager down: free the vector holding the peer
 * records and clear the manager's peer handle.  Nothing happens while no peer
 * vector exists. */
void NatNeg_Shutdown(void) {
    M2C_UNK Vector_Free();
    extern M2C_UNK gNatNegManager;

    if (M2C_FIELD(&gNatNegManager, s32 *, NATNEG_PEERS) == 0) {
        return;
    }
    Vector_Free();
    M2C_FIELD(&gNatNegManager, s32 *, NATNEG_PEERS) = 0;
}

/* TRUE when `packet` starts with the GameSpy NAT-negotiation magic bytes. */
s32 IsNatNegPacket(M2C_UNK packet) {
    s32 ByteCompareN(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern u8 gNatNegMagic[];
    if (ByteCompareN(packet, gNatNegMagic, NATNEG_MAGIC_LEN) == 0) {
        return 1;
    }
    return 0;
}

#pragma scheduling off
void func_0205d944(s32 a,s32 b,s32 c,s32 d,s32 e) {
s32 ghiSendTo(s32,s32,s32,s32,void *,s32);
struct Packet_0205 p;
p.d=b;
c=((c>>8)&255)|((c<<8)&0xff00);
p.c=c;p.b=2;
ghiSendTo(a,d,e,0,&p,8);
}
#pragma scheduling reset
/* Return the first private LAN address (10/8, 172.16/12 or 192.168/16) among the
 * console's local interface addresses, skipping the loopback address 127.0.0.1;
 * when none is private, the last non-loopback address, or 0 when there is none. */
s32 GetPreferredLocalIp(void) {
    void *GetLocalHostAddresses(void);
    s32 i;
    void *address;
    void *hostent;
    s32 result = 0;

    hostent = GetLocalHostAddresses();
    if (!hostent) return result;
    for (i = 0; ; i++) {
        address = M2C_FIELD(hostent, void ***, 12)[i];
        if (!address) break;
        if (M2C_FIELD((s32)address, s32 *, 0) != IP_LOOPBACK_NET) {
            result = M2C_FIELD(address, s32 *, 0);
            if (IsPrivateIpAddress(address)) return result;
        }
    }
    return result;
}

/* The local port the socket is bound to, in network byte order: read from the
 * socket's name record, or 0 when that fails. */
u16 GetSocketLocalPort(s32 socket) {
    s32 ghiGetSockName(s32, void *, s32 *);
    GhiSocketAddress address;
    s32 size = 8;
    if (ghiGetSockName(socket, &address, &size) == -1) return 0;
    return address.port;
}

