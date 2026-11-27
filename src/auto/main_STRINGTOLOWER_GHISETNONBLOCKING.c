/* 53 functions from 0x02048B74 to 0x02049AB8 (main), found by ds-decomp. */
#include "common.h"
#include "net_socket.h"

typedef struct { u8 bytes[8]; } UnkSocketAddress;

/* GameSpy hashtable.c TableNew2: allocates a table of nBuckets bucket vectors
   (each an empty vector of elemSize-byte elements) and stores the caller's hash
   and comparison callbacks.  Table layout: +0x00 buckets, +0x04 count,
   +0x08 userData, +0x0C hashFn, +0x10 compFn. */

#pragma push
#pragma optimization_level 2
#pragma opt_if_conversion off

#pragma pop

/* Polls a single fd for readability/priority/error; sets output flags accordingly. */

/* ghi: switch a socket between blocking and non-blocking I/O; a nonzero
 * `blocking` clears O_NONBLOCK, zero sets it, and 1 is returned when the new
 * flags were applied. */
s32 ghiSetNonBlocking(s32 socket, s32 blocking) {
    s32 SocketFcntl(M2C_UNK, M2C_UNK, s32);
    s32 flags;
    s32 newFlags;

    flags = SocketFcntl(socket, F_GETFL, 0);
    if (blocking != 0) {
        newFlags = flags & ~O_NONBLOCK;
    } else {
        newFlags = flags | O_NONBLOCK;
    }
    if (SocketFcntl(socket, F_SETFL, newFlags) == 0) {
        return 1;
    }
    return 0;
}

/* GameSpy ghi: set `socket`'s receive-buffer size to `size` (SO_RCVBUF) through
 * the DS set-socket-option entry; returns 1 when that call does not fail. */
s32 ghiSetRecvBufferSize(s32 socket,s32 size,...) {
void ghiSetSockOpt(void);
void *optval = &size;
return ((s32 (*)(s32,s32,s32,void *,s32))ghiSetSockOpt)(socket,GHI_SOL_SOCKET,GHI_SO_RCVBUF,optval,sizeof(s32))!=-1;
}

/* GameSpy ghi: set `socket`'s send-buffer size to `size` (SO_SNDBUF) through
 * the DS set-socket-option entry; returns 1 when that call does not fail. */
s32 ghiSetSendBufferSize(s32 socket,s32 size,...) {
void ghiSetSockOpt(void);
void *optval = &size;
return ((s32 (*)(s32,s32,s32,void *,s32))ghiSetSockOpt)(socket,GHI_SOL_SOCKET,GHI_SO_SNDBUF,optval,sizeof(s32))!=-1;
}

/* GameSpy ghi: reads socket `socket`'s receive-buffer size and returns it, or -1
 * when the option lookup fails. */
s32 ghiGetRecvBufferSize(int socket){
s32 ghiGetSockOpt(int,int,int,int,s32 *);
s32 value;
s32 size=4;
if(ghiGetSockOpt(socket,GHI_SOL_SOCKET,GHI_SO_RCVBUF,(int)&value,&size)==-1)return -1;
return value;
}

/* GameSpy ghi: reads socket `socket`'s send-buffer size and returns it, or -1
 * when the option lookup fails. */
s32 ghiGetSendBufferSize(int socket){
s32 ghiGetSockOpt(int,int,int,int,s32 *);
s32 value;
s32 size=4;
if(ghiGetSockOpt(socket,GHI_SOL_SOCKET,GHI_SO_SNDBUF,(int)&value,&size)==-1)return -1;
return value;
}

s32 PollOneFd(s32 fd, s32 *readable, s32 pri, s32 err) {
    s32 PollSockets(void *, u32, s64);
    PollFd p;
    s32 r;

    p.events = 0;
    p.fd = fd;
    if (readable) p.events |= 1;
    if (pri) p.events |= 8;
    p.revents = 0;
    r = PollSockets(&p, 1, 0);
    if (r < 0) return -1;
    if (readable) {
        if (r > 0 && (p.revents & 0x41)) *readable = 1;
        else *readable = 0;
    }
    if (pri) {
        if (r > 0 && (p.revents & 8)) *(s32 *)pri = 1;
        else *(s32 *)pri = 0;
    }
    if (err) {
        if (r > 0 && (p.revents & 0x20)) *(s32 *)err = 1;
        else *(s32 *)err = 0;
    }
    return r;
}

/* GameSpy ghi: report whether socket `socket` has data waiting to be received. */
s32 ghiSocketCanRecv(s32 socket) {
    s32 canRecv;

    canRecv = 0;
    if (PollOneFd(socket, &canRecv, 0, 0) == 1) {
        return canRecv;
    }
    return 0;
}

/* GameSpy ghi: report whether socket `socket` can be written to (poll's
 * write-ready event); 0 when it cannot. */
s32 ghiSocketCanSend(s32 socket) {
    s32 canSend;

    canSend = 0;
    if (PollOneFd(socket, 0, &canSend, 0) == 1) {
        return canSend;
    }
    return 0;
}

void *GetLocalHostAddresses(void){extern M2C_UNK gGhiSocketState;extern M2C_UNK data_020fce1c,data_0213dc8c,data_0213dc78,data_0213dc68;
M2C_FIELD(&gGhiSocketState,void **,8)=&data_020fce1c;
M2C_FIELD(&gGhiSocketState,void **,12)=(void *)0x0213dc60;
M2C_FIELD(&gGhiSocketState,u16 *,16)=2;
M2C_FIELD(&gGhiSocketState,u16 *,18)=0;
M2C_FIELD(&gGhiSocketState,void **,20)=&data_0213dc8c;
M2C_FIELD(&gGhiSocketState,s32 *,24)=0;
IpToBytes(GetLocalIpAddress(&gGhiSocketState),&data_0213dc78);
if(!M2C_FIELD(&gGhiSocketState,s32 *,24))return 0;
M2C_FIELD(&gGhiSocketState,void **,44)=&data_0213dc78;
M2C_FIELD(&gGhiSocketState,u16 *,18)=4;
M2C_FIELD(&gGhiSocketState,s32 *,48)=0;
return &data_0213dc68;}

/* Check whether an IPv4 address (stored in network byte order at *addr) is a
 * private LAN address: 10/8, 172.16/12 or 192.168/16. */
s32 IsPrivateIpAddress(u32 *addr) {
    u32 x = *addr;
    u32 y = ((x << 24) & 0xff000000) | (((x << 8) & 0xff0000) | (((x >> 24) & 0xff) | ((x >> 8) & 0xff00)));
    int first = (y >> 24) & 255;
    int second = (y >> 16) & 255;
    if (first == 10) return 1;
    if (first == 172 && second >= 16 && second <= 31) return 1;
    if (first == 192 && second == 168) return 1;
    return 0;
}

/* GameSpy ghi: store the failed socket result `result` as the stack's last socket
 * error (ghiGetLastSocketError reports it) and return the fallback `error`; a
 * non-negative result is returned unchanged. */
s32 ghiRecordSocketError(s32 result, s32 error) {
    extern M2C_UNK gGhiSocketState;

    if (result < 0) {
        M2C_FIELD(&gGhiSocketState, s32 *, GHI_STATE_LAST_ERROR) = result;
        result = error;
    }
    return result;
}

/* GameSpy ghi socket(): create a socket for `domain` (AF_INET), `type`
 * (SOCK_STREAM/SOCK_DGRAM) and `protocol` through the DS socket layer, record a
 * failure as the last socket error and return the socket (or -1). */
void ghiSocket(s32 domain, s32 type, s32 protocol) {
    s32 SocketCreate(s32, s32, s32);
    ghiRecordSocketError(SocketCreate(domain, type, protocol), -1);
}

/* GameSpy ghi close(): close socket `socket` through the NitroSDK wrapper,
 * record a failure as the stack's last socket error and return the result, or
 * -1 when the close failed. */
s32 ghiCloseSocket(s32 socket) {
    s32 SocketCloseVeneer(s32);

    return ghiRecordSocketError(SocketCloseVeneer(socket), -1);
}

/* GameSpy ghi socket shutdown: shut `socket` down for `how` (SHUT_RD, SHUT_WR or
 * SHUT_RDWR) through the SDK's SocketShutdown veneer, recording a failure as the
 * last socket error and returning its result (or -1). */
void ghiSocketShutdown(s32 socket, s32 how) {
    s32 SocketShutdownVeneer(s32, s32);
    ghiRecordSocketError(SocketShutdownVeneer(socket, how), -1);
}

/* ghiBind: binds `socket` to `address`, whose length byte is replaced with the
 * caller's `length`; a zero port binds nothing and returns 0.  A failed bind
 * returns -1 after recording the socket error. */
s32 ghiBind(int socket,UnkSocketAddress *address,u8 length){
s32 SocketBindAddress(int,UnkSocketAddress *);
UnkSocketAddress addr;
if(*(u16 *)(address->bytes+2)==0)return 0;
addr=*address;
addr.bytes[0]=length;
return ghiRecordSocketError(SocketBindAddress(socket,&addr),-1);
}

/* ghiConnect: connects `socket` to `address`, whose length byte is replaced with
 * the caller's `length`.  A failed connect returns -1 after recording the socket
 * error. */
s32 ghiConnect(int socket, UnkSocketAddress *address, u8 length) {
    s32 SocketConnectAddress(int, UnkSocketAddress *);
    UnkSocketAddress addr = *address;
    addr.bytes[0] = length;
    return ghiRecordSocketError(SocketConnectAddress(socket, &addr), -1);
}

/* GameSpy ghi listen(): check listening socket `socket` for an incoming
 * connection through the NitroSDK wrapper, record a failure as the stack's last
 * socket error and return the result, or -1 when the check failed. */
s32 ghiListen(s32 socket) {
    s32 SocketCheckReadyVeneer(s32);

    return ghiRecordSocketError(SocketCheckReadyVeneer(socket), -1);
}

/* GameSpy ghi accept: accept a connection on `socket` and report the peer in
 * `address`; the caller's address length (in `*addressLength`) is copied into the
 * address's length byte before the call and read back into it afterwards, as the
 * SDK's accept does.  A failed accept is recorded as the socket error. */
void ghiAccept(M2C_UNK socket, u8 *address, s32 *addressLength) {
    s32 SocketAccept(M2C_UNK);
    M2C_UNK ghiRecordSocketError(s32, M2C_UNK);
    s32 acceptedSocket;

    *address = (u8) *addressLength;
    acceptedSocket = SocketAccept(socket);
    *addressLength = (s32) *address;
    ghiRecordSocketError(acceptedSocket, -1);
}

/* ghi recv: receive up to `length` bytes from `socket` into `data` with `flags`
 * through the DS socket layer, record a failure as the stack's last socket error
 * and return the number of bytes received, or -1 when the receive failed. */
s32 ghiRecv(s32 socket, void *data, s32 length, s32 flags) {
    s32 SocketRecvFlags(s32, void *, s32, s32);
    M2C_UNK ghiRecordSocketError(s32, M2C_UNK);

    return ghiRecordSocketError(SocketRecvFlags(socket, data, length, flags), -1);
}

/* ghi recvfrom: receive up to `len` bytes from `socket` into `buf` with `flags`
 * and report the sender in `address`.  As the SDK does, the caller's address
 * length (in `*addressLength`) is copied into the address's length byte before
 * the call and read back into it afterwards. */
void ghiRecvFrom(s32 socket, void *buf, s32 len, s32 flags, UnkSocketAddress *address, s32 *addressLength) {
    s32 SocketRecvFromAddress(s32, void *, s32, s32, UnkSocketAddress *);
    s32 result;

    address->bytes[0] = (u8) *addressLength;
    result = SocketRecvFromAddress(socket, buf, len, flags, address);
    *addressLength = (s32) address->bytes[0];
    ghiRecordSocketError(result, -1);
}

/* ghi send: send up to `length` bytes of `data` on `socket` with `flags`
 * through the DS socket layer, record a failure as the stack's last socket error
 * and return the number of bytes sent, or -1 when the send failed. */
s32 ghiSend(s32 socket, const void *data, s32 length, s32 flags) {
    s32 SocketSendFlags(s32, const void *, s32, s32);
    M2C_UNK ghiRecordSocketError(s32, M2C_UNK);

    return ghiRecordSocketError(SocketSendFlags(socket, data, length, flags), -1);
}

s32 ghiSendTo(int a,int b,int c,int d,UnkSocketAddress *e,int f) {
s32 func_020216cc(int,int,int,int,UnkSocketAddress *);
UnkSocketAddress addr; addr=*(UnkSocketAddress const *)e;
addr.bytes[0]=f;
return ghiRecordSocketError(func_020216cc(a,b,c,d,&addr),-1);
}

/* GameSpy ghi getsockopt: the DS socket layer has no option lookup, so clear
 * the caller's `length`-byte value buffer and report success (0). */
s32 ghiGetSockOpt(s32 socket, s32 level, s32 option, s32 value, s32 *length) {
    M2C_UNK MI_CpuFill8(s32, s32, s32);
    MI_CpuFill8(value, 0, *length);
    return ghiRecordSocketError(0, -1);
}

/* GameSpy ghi setsockopt stub: the DS socket layer cannot set socket options, so
 * this always reports success (0), whatever the caller's socket and option are. */
void ghiSetSockOpt(void) {
    ghiRecordSocketError(0, -1);
}

/* ghi getsockname: fill `address` with `socket`'s local address. As the SDK
 * does, the caller's address length is copied into the address's length byte
 * before the call and read back into `*addressLength` afterwards. */
void ghiGetSockName(s32 socket, UnkSocketAddress *address, s32 *addressLength) {
    s32 SocketGetSockName(s32);
    M2C_UNK ghiRecordSocketError(s32, M2C_UNK);
    s32 result;

    address->bytes[0] = (u8) *addressLength;
    result = SocketGetSockName(socket);
    *addressLength = (s32) address->bytes[0];
    ghiRecordSocketError(result, -1);
}

/* ghi inet_addr: resolve host name `hostname` to a network-order IPv4
 * address (the order the rest of the stack uses), or -1 when it does not
 * resolve at all. */
s32 ghiInetAddr(s32 hostname) {
    M2C_UNK ghiResolveInetAddr(s32, u32 *);
    u32 address;

    if (ghiResolveInetAddr(hostname, &address) == 0) {
        return -1;
    }
    return address;
}

s32 ghiGetLastSocketError(void) {
    extern M2C_UNK gGhiSocketState;
    return M2C_FIELD(&gGhiSocketState, s32 *, 4);
}

/* GameSpy nonport.c time(): assert the system tick is available, then return the
 * tick count scaled to the millisecond time base the peer protocol deadlines use. */
void gpiGetTime(int *out) {
    int IsSystemTickInitialized(void);
    unsigned long long GetSystemTick(void);
    unsigned long long U64Divide(unsigned long long, unsigned long long);
    extern char sAssertTickAvailable[], sNonportFileName[], sTimeName[];
    unsigned int timeMs;

    if (IsSystemTickInitialized() != 1) AssertFailed(sAssertTickAvailable, sNonportFileName, sTimeName, 0x667);
    timeMs = U64Divide(GetSystemTick() << 6, 0x1ff6210);
    if (out) *out = timeMs;
}

s32 AdvanceRandomState(s32 x) {
u32 lo=(u32)x<<16;
u32 hi=(u32)x>>16;
u32 a=hi*16807;
u32 v=(lo>>16)*16807+((a<<17)>>1);
if(v>0x7fffffffU)v=(v&0x7fffffffU)+1;
v+=a>>15;
if(v>0x7fffffffU)v=(v&0x7fffffffU)+1;
return v;
}

/* Advance the game's random state and return its new value. */
s32 NextRandom(void) {
    extern s32 gRandomState;
    s32 AdvanceRandomState(s32);
    return gRandomState = AdvanceRandomState(gRandomState);
}

/* Seed the game's random state (gRandomState, which NextRandom advances) with
 * `seed`; 0 falls back to 1, and the sign bit is dropped because the state is
 * kept as 31 bits. */
void SeedRandom(s32 seed) {
    extern s32 gRandomState;

    gRandomState = seed ? (seed & ~0x80000000) : 1;
}

/* Random number in [min, max): advance the game's random state and fold the new
 * value into the range, or return `min` for an empty range. */
s32 RandomRange(s32 min, s32 max) {
    s32 range;
    s32 result;

    range = max - min;
    if (range == 0) return min;
    result = NextRandom();
    result %= range;
    return result + min;
}

/* Pack up to `count` bytes of `src` into the four base64 digit values of
 * `dst`: the group's bytes are read into a 3-byte buffer (padded with zeros
 * when fewer are given) and split into 6-bit groups, most significant first.
 * Base64Encode turns the digits into the alphabet's characters. */
void Base64PackGroup(signed char *src, unsigned char *dst, int count) {
    unsigned char group[3];
    int i;

    for (i = 0; i < count; i++) group[i] = src[i];
    for (; i < 3; i++) group[i] = 0;
    dst[0] = group[0] >> 2;
    dst[1] = ((group[0] & 3) << 4) | (group[1] >> 4);
    dst[2] = ((group[1] & 15) << 2) | (group[2] >> 6);
    dst[3] = group[2] & 63;
}
