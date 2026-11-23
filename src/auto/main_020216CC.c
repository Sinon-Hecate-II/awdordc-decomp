/* 32 functions from 0x020216CC to 0x020222D8 (main), found by ds-decomp. */
#include "common.h"
#include "net_socket.h"
#include "ghttp.h"
extern M2C_UNK gHostName, gHostRecord, gHostAddressList, gHostEntry;

#pragma scheduling off
void func_020216cc(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2,s32 arg3,void *arg4) {
M2C_UNK SocketSendTo(M2C_UNK,M2C_UNK,M2C_UNK,u16,s32,s32);
s32 var_r4;u16 temp_r4;register u16 var_r5;register u32 temp_r6;
if(!arg4){var_r5=0;var_r4=0;}else {
temp_r4=M2C_FIELD(arg4,u16*,2);temp_r6=M2C_FIELD(arg4,u32*,4);
var_r5=(u8)((s32)temp_r4>>8)|((temp_r4<<8)&0xff00);
var_r4=((temp_r6<<24)&0xff000000)|(((temp_r6<<8)&0xff0000)|((u8)(temp_r6>>24)|((temp_r6>>8)&0xff00)));
}
SocketSendTo(arg0,arg1,arg2,var_r5,var_r4,arg3);
}
#pragma scheduling on
void func_02021750(void) {
    M2C_UNK SocketShutdown();
    SocketShutdown();
}

void func_0202175c(void) {
    M2C_UNK SocketClose();
    SocketClose();
}

/* Resolve `hostname` to an IPv4 address and fill in the shared host record:
 * copy the name into the name buffer, point the record's name at it, set the
 * address type (2 = AF_INET), address length (4) and address list (the address
 * followed by NULL), and store the address in network byte order.  Returns 0
 * when the name does not resolve. */
void *ghiResolveHostname(void *hostname) {
    u32 LookupHostAddress(void *);
    void MI_CpuFill8(void *, s32, s32);
    void Mb_StringCopyBounded(void *, void *, s32);
    u32 address = LookupHostAddress(hostname);
    if (!address) return 0;
    MI_CpuFill8(&gHostName, 0, 0x101);
    Mb_StringCopyBounded(&gHostName, hostname, 0x101);
    /* The host entry at +0x20 of the record: name, aliases, address type,
       address length and address list. */
    M2C_FIELD(&gHostRecord, void **, 0x20) = &gHostName;
    M2C_FIELD(&gHostRecord, u32 *, 0x24) = 0;
    M2C_FIELD(&gHostRecord, u16 *, 0x28) = 2;
    M2C_FIELD(&gHostRecord, u16 *, 0x2a) = 4;
    M2C_FIELD(&gHostRecord, void **, 0x2c) = &gHostAddressList;
    M2C_FIELD(&gHostRecord, void **, 0x18) = &gHostAddressList - 24;
    M2C_FIELD(&gHostRecord, u32 *, 0x1c) = 0;
    M2C_FIELD(&gHostRecord, u32 *, 0) = ((address << 24) & 0xFF000000) | (((address << 8) & 0xFF0000) | ((u8)(address >> 24) | ((address >> 8) & 0xFF00)));
    return &gHostEntry;
}

/* Fill `addr` with the socket's local endpoint (BSD get sock name): its
 * receive port and the console's local IPv4 address, both in network byte
 * order, with the DS address length (8) and the AF_INET family.  Returns 0,
 * or -39 when the socket is NULL. */
s32 SocketGetSockName(void *socket, GhiSocketAddress *addr) {
    u32 GetLocalIpAddress();
    u32 address;
    u32 port;
    if (!socket) return -39;
    address = GetLocalIpAddress();
    port = socket ? M2C_FIELD(socket, u16 *, SOCK_RECV_PORT) : 0;
    port = (u16)(address ? port : 0);
    addr->len = 8;
    addr->family = 2;
    addr->port = (u8)((s32)port >> 8) | ((port << 8) & 0xff00);
    addr->addr = ((address << 24) & 0xFF000000) | (((address << 8) & 0xFF0000) | ((u8)(address >> 24) | ((address >> 8) & 0xFF00)));
    return 0;
}

s32 func_020218bc(void) {
    u32 GetLocalIpAddress();
    u32 temp_r0;

    temp_r0 = GetLocalIpAddress();
    return ((temp_r0 << 0x18) & 0xFF000000) | (((temp_r0 << 8) & 0xFF0000) | ((u8) (temp_r0 >> 0x18) | ((temp_r0 >> 8) & 0xFF00)));
}

/* Set the two DNS server addresses from host-order IPv4 values: byte-swap each
 * one to network order and store it for DnsLookupAddress. */
void SetDnsServerAddressesFromHostOrder(u32 *server0, u32 *server1) {
    M2C_UNK SetDnsServerAddresses(s32, s32);
    u32 value1;
    u32 value0;

    value1 = *server1;
    value0 = *server0;
    SetDnsServerAddresses(((value0 << 0x18) & 0xFF000000) | (((value0 << 8) & 0xFF0000) | ((u8) (value0 >> 0x18) | ((value0 >> 8) & 0xFF00))), ((value1 << 0x18) & 0xFF000000) | (((value1 << 8) & 0xFF0000) | ((u8) (value1 >> 0x18) | ((value1 >> 8) & 0xFF00))));
}

void func_02021960(void) {
    M2C_UNK SocketCheckReady();
    SocketCheckReady();
}

/* Accept a connection on a listening socket: create the accepted socket and
 * report the peer's port and IPv4 address in `peer` as a GhiSocketAddress, in
 * network byte order.  Returns the new socket, or a negative socket error. */
s32 SocketAccept(void *listenSocket, GhiSocketAddress *peer) {
    s32 SocketCreateListen(void *, u16 *, u32 *);
    u32 peerAddr;
    u16 peerPort;
    s32 result = SocketCreateListen(listenSocket, &peerPort, &peerAddr);
    if (result < 0) return result;
    peer->port = ((peerPort >> 8) & 255) | ((peerPort << 8) & 0xff00);
    peer->addr = ((peerAddr >> 24) & 255) | ((peerAddr >> 8) & 0xff00) | ((peerAddr << 8) & 0xff0000) | ((peerAddr << 24) & 0xff000000);
    return result;
}

/* fcntl-style control of a socket: F_GETFL returns its status flags (O_NONBLOCK
 * set while it is non-blocking), F_SETFL sets them from `flags`.  Returns -1
 * when there is no socket, 0 otherwise. */
s32 SocketFcntl(void *socket, s32 command, s32 flags) {
    s32 result;

    if (socket == NULL) {
        return -1;
    }
    switch (command) {                                 /* irregular */
    case F_GETFL:
        if (M2C_FIELD(socket, s8 *, SOCK_BLOCKING) == SOCK_BLOCKING_ON) {
            result = 0;
        } else {
            result = O_NONBLOCK;
        }
        return result;
    case F_SETFL:
        if (flags & O_NONBLOCK) {
            M2C_FIELD(socket, s8 *, SOCK_BLOCKING) = 0;
        } else {
            M2C_FIELD(socket, s8 *, SOCK_BLOCKING) = SOCK_BLOCKING_ON;
        }
        /* fallthrough */
    default:
        return 0;
    }
}

s32 *func_02021a38(s32 a){
extern M2C_UNK gHostRecord;
s32 *p; s32 size=a+4;
p=M2C_FIELD(&gHostRecord,s32 *(**)(M2C_UNK,s32),12)(0,size);
if(p){*p=size;p++;}
return p;
}

void func_02021a64(void *arg0) {
    extern M2C_UNK gHostRecord;
    if (arg0 == NULL) {
        return;
    }
    M2C_FIELD(&gHostRecord, M2C_UNK (**)(M2C_UNK, s32, s32), 4)(0, arg0 - 4, M2C_FIELD(arg0, s32 *, -4));
}

/* Copy a (possibly network) configuration record into the shared context and
   initialise its allocator/free callbacks plus the byte-swapped endpoint fields. */
void func_02021a90(void *cfg) {
extern M2C_UNK data_02138b74;
s32 *func_02021a38(s32);
void func_02021a64(void *);
void func_0201ee58(void *);
u32 v;
M2C_FIELD(&gHostRecord,u32 *,0x40)=M2C_FIELD(cfg,u32 *,12)==1;
v=M2C_FIELD(cfg,u32 *,16);M2C_FIELD(&gHostRecord,u32 *,68)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,20);M2C_FIELD(&gHostRecord,u32 *,72)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,24);M2C_FIELD(&gHostRecord,u32 *,76)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,28);M2C_FIELD(&gHostRecord,u32 *,80)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,32);M2C_FIELD(&gHostRecord,u32 *,84)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
M2C_FIELD(&gHostRecord,s32 *(**)(s32),0x58)=func_02021a38;
M2C_FIELD(&gHostRecord,void (**)(void *),0x5c)=func_02021a64;
M2C_FIELD(&gHostRecord,u32 *,12)=M2C_FIELD(cfg,u32 *,4);
M2C_FIELD(&gHostRecord,u32 *,4)=M2C_FIELD(cfg,u32 *,8);
M2C_FIELD(&gHostRecord,u32 *,0x60)=0x40;
M2C_FIELD(&gHostRecord,u32 *,0x70)=M2C_FIELD(cfg,u32 *,0x2c);
M2C_FIELD(&gHostRecord,u32 *,0x74)=M2C_FIELD(cfg,u32 *,0x30);
func_0201ee58(&data_02138b74);
}

void func_02021c04(void) {
    M2C_UNK NetworkShutdown();
    NetworkShutdown();
}

M2C_UNK *IpToString(s32 a,...){
M2C_UNK FormatIpAddress(M2C_UNK,void *,void *,M2C_UNK);
extern M2C_UNK data_02138bac;
FormatIpAddress(2,&a,&data_02138bac,16);
return &data_02138bac;
}

/* GameSpy inet_addr helper: turn the address string `hostname` into a
 * network-order IPv4 address, stored in *address.  Returns 1 when it resolved,
 * 0 when it did not. */
s32 ghiResolveInetAddr(s32 hostname,u32 *address){
u32 DnsLookupAddressWithoutServers(s32);u32 v=DnsLookupAddressWithoutServers(hostname);
if(!v)return 0;
*address=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
return 1;
}

/* Format a network-order IPv4 address (family AF_INET, 2) as a dotted decimal
 * string into `buffer`, which must hold at least 16 bytes; returns buffer, or 0
 * when the family is not AF_INET or the buffer is too small. */
M2C_UNK FormatIpAddress(s32 family,void *address,void *buffer,s32 size){
void MI_CpuCopy8(void *,void *,u32);void IpToBytes(u32,void *);
void StringFormatN(void *,s32,void *,...);
extern M2C_UNK sIpAddressFormat;
u32 value;u8 octets[4];
if(family!=2)return 0;if((u32)size<16)return 0;
MI_CpuCopy8(address,&value,4);IpToBytes(value,octets);
StringFormatN(buffer,16,&sIpAddressFormat,octets[3],octets[2],octets[1],octets[0]);return (M2C_UNK)buffer;
}

void IpToBytes(u32 arg0, void *arg1) {
M2C_FIELD(arg1,u8 *,0)=arg0>>24;
M2C_FIELD(arg1,u8 *,1)=arg0>>16;
M2C_FIELD(arg1,u8 *,2)=arg0>>8;
M2C_FIELD(arg1,u8 *,3)=arg0;
}

/* Waits until one of the `count` sockets in `fds` is ready or `timeout` timer
 * ticks pass (-1 waits forever).  Each round polls every socket, always asking
 * for the error, writable and invalid events as well, and stores the events
 * that fired in its revents field; between rounds it sleeps for a millisecond.
 * Returns the number of sockets that were ready. */
s32 PollSockets(PollFd *fds, u32 count, s64 timeout) {
s32 SocketPoll(s32);void SleepMilliseconds(s32);
s32 limited=timeout!=-1;
PollFd *p;u32 i;s32 ready;
for(;;){
ready=0;p=fds;i=0;
if(count>i) do {
s32 wanted=p->events|POLL_FD_ALWAYS;
s32 fired=wanted&SocketPoll(p->fd);
p->revents=fired;if(fired)ready++;p++;i++;
}while(count>i);
if(ready>0)break;
if(limited && 0LL>=timeout)break;
SleepMilliseconds(1);timeout-=0x20b;
}return ready;
}

/* Restore a cached TLS session for a peer that named it by id (the session id it
 * echoed in its ClientHello): the first cache entry that is valid, was stored
 * without a peer address and carries the same id hands over its master secret,
 * and the channel is marked as resumable.  The cache is read with interrupts
 * disabled. */
void TlsRestoreSessionById(void *channel) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void MI_CpuCopy8(void *, void *, u32);
    s32 ByteCompareN(void *, void *, s32);
    extern M2C_UNK gTlsSessionCache;
    s32 i;
    s32 old;
    void *entry;

    old = OS_DisableInterrupts();
    i = 0;
    entry = &gTlsSessionCache;
    M2C_FIELD(channel, u8 *, TLS_SESSION_CACHED) = 0;
    do {
        if (M2C_FIELD(entry, u8 *, TLS_CACHE_VALID) && !M2C_FIELD(entry, u32 *, TLS_CACHE_ADDRESS) && !M2C_FIELD(entry, u16 *, TLS_CACHE_PORT) &&
            !ByteCompareN(entry, channel + TLS_SESSION_ID, TLS_RANDOM_SIZE)) {
            MI_CpuCopy8(entry + TLS_CACHE_SECRET, channel, TLS_MASTER_SECRET_SIZE);
            M2C_FIELD(channel, u8 *, TLS_SESSION_CACHED) = 1;
            break;
        }
        i++;
        entry += TLS_CACHE_ENTRY_SIZE;
    } while (i < TLS_CACHE_ENTRIES);
    OS_RestoreInterrupts(old);
}

/* Look the peer (address, port) up in the four-entry TLS session-resumption
 * cache with interrupts disabled: on a hit copy the entry's session id and
 * master secret into the channel, restamp it and mark the channel resumable. */
void TlsRestoreSession(void *channel,s32 address,s32 port) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); 
void MI_CpuCopy8(void *,void *,u32);u64 GetSystemTick(void);
extern M2C_UNK gTlsSessionCache;
s32 old=OS_DisableInterrupts();s32 i=0;void *entry=&gTlsSessionCache;
M2C_FIELD(channel,u8 *,TLS_SESSION_CACHED)=0;
do{
if(M2C_FIELD(entry,u8 *,TLS_CACHE_VALID)&&M2C_FIELD(entry,s32 *,TLS_CACHE_ADDRESS)==address&&M2C_FIELD(entry,u16 *,TLS_CACHE_PORT)==port){
MI_CpuCopy8(entry,channel+TLS_SESSION_ID,32);MI_CpuCopy8(entry+TLS_CACHE_SECRET,channel,48);
M2C_FIELD(entry,u32 *,TLS_CACHE_TICK)=GetSystemTick()>>16;
M2C_FIELD(channel,u8 *,TLS_SESSION_CACHED)=1;break;
}
i++;entry+=TLS_CACHE_ENTRY_SIZE;
}while(i<TLS_CACHE_ENTRIES);
OS_RestoreInterrupts(old);
}

void TlsStoreSession(u8 *arg0, s32 arg1, u16 arg2) {
u64 GetSystemTick(void); s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void MI_CpuCopy8(void *,void *,u32);
extern M2C_UNK gTlsSessionCache;
s32 state; u32 now; u8 *best; s32 i; u32 maxage; u8 *p; u32 age; u64 ticks; u8 valid;
u16 port; s32 addr; u8 *buffer;
state=OS_DisableInterrupts(); ticks=GetSystemTick();
port=arg2; addr=arg1; buffer=arg0;
best=(u8 *)&gTlsSessionCache; maxage=0; now=(u32)(ticks>>16);
for(i=0,p=best;i<4;i++,p+=0x5C){
valid=p[0x5A];
if(valid && addr && addr==M2C_FIELD(p,s32 *,0x54) && port && port==M2C_FIELD(p,u16 *,0x58)){best=p;break;}
if(maxage!=~0U){
if(!valid){maxage=~0U;best=p;}
else {age=now-M2C_FIELD(p,u32 *,0x50);if(age>maxage){maxage=age;best=p;}}
}
}
MI_CpuCopy8(buffer+0x74,best,0x20);
MI_CpuCopy8(buffer,best+0x20,0x30);
M2C_FIELD(best,u32 *,0x50)=now; best[0x5A]=1; M2C_FIELD(best,s32 *,0x54)=addr;M2C_FIELD(best,u16 *,0x58)=port;
OS_RestoreInterrupts(state);
}

/* Invalidate the TLS session-resumption cache entry whose session id matches the
 * channel's, so a session from an aborted handshake is not restored later.  Runs
 * with interrupts disabled. */
void TlsSessionCacheDiscard(void *channel) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 ByteCompareN(void *, void *, s32);
    extern M2C_UNK gTlsSessionCache;
    s32 i;
    s32 old;
    void *entry;
    old = OS_DisableInterrupts();
    entry = &gTlsSessionCache;
    i = 0;
    do {
        if (M2C_FIELD(entry, u8 *, TLS_CACHE_VALID) && !ByteCompareN(entry, (u8 *)channel + TLS_SESSION_ID, TLS_RANDOM_SIZE)) {
            M2C_FIELD(entry, u8 *, TLS_CACHE_VALID) = 0;
            break;
        }
        i++;
        entry = (u8 *)entry + TLS_CACHE_ENTRY_SIZE;
    } while (i < TLS_CACHE_ENTRIES);
    OS_RestoreInterrupts(old);
}

s32 GetUnixTime(void){
void GetRtcDate(void *);void GetRtcTime(void *);s32 MakeTime(void *,void *);
s32 a[4],b[3];
GetRtcDate(a);GetRtcTime(b);return MakeTime(a,b)+0x386d4380;
}

void func_020220a8(s32 arg0) {
    extern M2C_UNK gTlsCipherSuites;
    M2C_FIELD(&gTlsCipherSuites, s32 *, 4) = arg0;
}

/* Raise the running thread's run priority to the configured TLS boost priority
 * while the RSA/TLS work runs; return the priority to restore it to, or -1 when
 * no boost priority is set (THREAD_PRIORITY_MAX or more, as at boot). */
s32 BoostThreadPriority(void) {
    s32 GetThreadPriority(void *); void SetThreadPriority(s32,u32);
    extern M2C_UNK gTlsCipherSuites, gSocketManager;
    void *thread; s32 oldPriority;
    if(M2C_FIELD(&gTlsCipherSuites,u32 *,TLS_BOOST_PRIORITY)>=THREAD_PRIORITY_MAX)return -1;
    thread=M2C_FIELD(&gSocketManager,void **,SOCKMGR_RUNNING_THREAD);
    oldPriority=GetThreadPriority(thread);
    SetThreadPriority((s32)thread,M2C_FIELD(&gTlsCipherSuites,u32 *,TLS_BOOST_PRIORITY));
    return oldPriority;
}

void RestoreThreadPriority(u32 a){
void SetThreadPriority(s32,u32);
extern M2C_UNK gSocketManager;
if(a>=32)return;
SetThreadPriority(M2C_FIELD(&gSocketManager,s32 *,4),a);
}

void func_02022128(s32 arg0, s32 arg1) {
    extern M2C_UNK gSocketManager;
    void *temp_r2;
    void *temp_r2_2;

    temp_r2 = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
    if (temp_r2 != NULL) {
        temp_r2_2 = M2C_FIELD(temp_r2, void **, 0xC);
        if (temp_r2_2 != NULL) {
            M2C_FIELD(temp_r2_2, s32 *, 0x814) = arg0;
            M2C_FIELD(temp_r2_2, s32 *, 0x818) = arg1;
        }
    }
}

/* Return the key in the TLS context's key list whose name is `issuer`, or NULL
 * when no entry has that name. */
NamedRsaKey *FindNamedRsaKey(void *ctx, const char *issuer) {
    s32 StringCompare(void *, void *);
    s32 i;
    NamedRsaKey **keys;
    s32 count;
    NamedRsaKey *key;

    count = M2C_FIELD(ctx, s32 *, TLS_KEY_COUNT);
    i = 0;
    if (count > 0) {
        keys = M2C_FIELD(ctx, NamedRsaKey ***, TLS_KEY_LIST);
        do {
            key = keys[i];
            if (!StringCompare(key->name, (void *)issuer)) return key;
            i++;
        } while (i < count);
    }
    return 0;
}

/* Parse the DER length that follows an ASN.1 tag: the first byte is the length
 * when its high bit is clear, otherwise its low 7 bits are the number of
 * following bytes of a big-endian length.  Advances *p past the length and
 * returns it, or -1 when the length would not fit in 32 bits. */
u32 ParseAsn1Length(u8 **p){
u8 *q=*p;u32 v=*q++;s32 n;
if(v&ASN1_LENGTH_LONG_FORM){n=v&ASN1_LENGTH_VALUE_MASK;v=0;while(n--){if(v&0xff000000)return -1;v=*q+++(v<<8);}}
*p=q;return v;
}

/* Append `length` bytes of `name` to the comma-separated name list in `list`
 * (adding ", " first when the list is not empty), truncating the list to 255
 * bytes and terminating it with NUL. */
void AppendCommaSeparatedName(s8 *list,s8 *name,s32 length){
s8 *start=list;
if(*list){while(*++list){}if(list-start>=255)return;list[0]=',';list[1]=' ';list+=2;}
while(length-- && list-start<255)*list++=*name++;
*list=0;
}

/* Parses an ASN.1 time ("YYMMDD..." for UTCTime, "YYYYMMDD..." for
 * GeneralizedTime) into year<<16 | month<<8 | day. */
s32 ParseAsn1Time(u8 *time, s32 type) {
    s32 year;
    u32 first;
    u8 digit;
    digit = time[1];
    first = time[0] * 10 + digit - ASN1_DIGITS_ZERO;
    time += 2;
    if (type == ASN1_TIME_UTC) {
        if (first < 50) year = first + 2000;
        else year = first + 1900;
    } else {
        digit = time[1];
        year = first * 100 + (time[0] * 10 + digit - ASN1_DIGITS_ZERO);
        time += 2;
    }
    return ((time[0] * 10 + time[1] - ASN1_DIGITS_ZERO) << 8) + (year << 16) + (time[2] * 10 + time[3] - ASN1_DIGITS_ZERO);
}

