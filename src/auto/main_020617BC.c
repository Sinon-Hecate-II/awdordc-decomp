/* 33 functions from 0x020617BC to 0x02062770 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"
#include "sb_serverlist.h"
typedef struct Addr617BC { u8 len, family; u16 port; u32 addr; } Addr617BC;
typedef struct Bytes617BC { u8 b[4]; } Bytes617BC;
typedef struct Pair617BC { u8 b[2]; } Pair617BC;
#pragma push
#pragma opt_propagation off
static inline void CopyHeaderBytes617BC(u8 *dst,u8 *src) {
u8 hi=src[1],lo=src[0];dst[1]=hi;dst[0]=lo;
}
#pragma pop
static inline void CopyPair617BC(u8 *d,u8 *s) { *(Pair617BC *)d=*(Pair617BC *)s; }
static inline void Copy617BC(u8 *d,u8 *s) { *(Bytes617BC *)d=*(Bytes617BC *)s; }
extern u8 sSbAssertInterned[];
extern u8 sSbFileName[];
extern u8 sSbReleaseStrName[];
extern void *sSbQueryErrorPrefix;
extern s32 sSbNoServer[2];

/* Server-list sort callback for an integer key: compare the two servers' values of
 * the list's sort key, negated when the list sorts ascending. */
s32 SBServerListCompareInt(s32 *serverA, s32 *serverB) {
    s32 SBServerGetIntValue(s32, s32, M2C_UNK);
    extern void *gSBServerListSorting;
    s32 valueA;
    s32 valueB;
    s32 result;

    valueA = *serverA;
    valueB = *serverB;
    valueA = SBServerGetIntValue(valueA, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), 0);
    result = valueA - SBServerGetIntValue(valueB, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), 0);
    if (M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_DESC) == 0) {
        result = -result;
    }
    return result;
}

/* Server-list sort callback for a floating-point key: compare the two servers'
 * values of the sort key as doubles and return the sign of their quotient
 * (which stands in for the difference), inverted when the list sorts
 * ascending. */
s32 SBServerListCompareFloat(s32 *serverA, s32 *serverB) {
    double SBServerGetFloatValue(void *, s32, double);
    double func_02070b70(double, double);
    extern void *gSBServerListSorting;
    double valueA;
    double valueB;
    double diff;
    s32 server;
    s32 result;

    server = *serverB;
    valueA = SBServerGetFloatValue((void *) *serverA, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), 0.0);
    valueB = SBServerGetFloatValue((void *) server, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), 0.0);
    diff = func_02070b70(valueA, valueB);
    if (M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_DESC) == 0) {
        diff = func_02070b70(0.0, diff);
    }
    if ((float)diff > 0.0f) return 1;
    return -((float)diff < 0.0f);
}

/* Server-list sort callback for a string key: compare the two servers' values of
 * the list's sort key, negated when the list sorts ascending. */
s32 SBServerListCompareString(s32 *serverA, s32 *serverB) {
    s32 SBServerGetStringValue(s32, s32, M2C_UNK *);
    s32 StringCompare(s32, s32);
    extern void *gSBServerListSorting;
    extern M2C_UNK sSbEmptyString;
    s32 valueA;
    s32 result;

    valueA = SBServerGetStringValue(*serverA, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), &sSbEmptyString);
    result = StringCompare(valueA, SBServerGetStringValue(*serverB, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), &sSbEmptyString));
    if (M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_DESC) == 0) {
        result = -result;
    }
    return result;
}

/* Case-insensitive server-list sort callback for a string key: compare the two
 * servers' values of the list's sort key, negated when the list sorts ascending. */
s32 SBServerListCompareStringNoCase(s32 *serverA, s32 *serverB) {
    s32 SBServerGetStringValue(s32, s32, M2C_UNK *);
    s32 StringCompareNoCase(s32, s32);
    extern void *gSBServerListSorting;
    extern M2C_UNK sSbEmptyString;
    s32 valueA;
    s32 result;

    valueA = SBServerGetStringValue(*serverA, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), &sSbEmptyString);
    result = StringCompareNoCase(valueA, SBServerGetStringValue(*serverB, M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_FIELD), &sSbEmptyString));
    if (M2C_FIELD(gSBServerListSorting, s32 *, SB_SLIST_SORT_DESC) == 0) {
        result = -result;
    }
    return result;
}

/* Sorts the server list's servers by key `field` with the comparator for
 * `sortKind`, recording the key and direction on the list so the comparator can
 * read them back, then sorting the servers vector. */
void SBServerListSortServers(void *list, s32 descending, s32 field, u32 sortKind) {
    s32 SBServerListCompareFloat(s32 *, s32 *);
    s32 SBServerListCompareStringNoCase(s32 *, s32 *);
    M2C_UNK Vector_Sort(s32, s32 (*)(s32 *, s32 *));
    extern void *gSBServerListSorting;
    s32 (*compare)(s32 *, s32 *);

    switch (sortKind) {
    case SB_SORT_INT: compare = SBServerListCompareInt; break;
    case SB_SORT_FLOAT: compare = SBServerListCompareFloat; break;
    case SB_SORT_STRING: compare = SBServerListCompareString; break;
    case SB_SORT_STRING_NOCASE: compare = SBServerListCompareStringNoCase; break;
    default: compare = SBServerListCompareStringNoCase; break;
    }
    M2C_FIELD(list, s32 *, SB_SLIST_SORT_FIELD) = field;
    M2C_FIELD(list, s32 *, SB_SLIST_SORT_DESC) = descending;
    gSBServerListSorting = list;
    Vector_Sort(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS), compare);
}

/* Add `server` to the list's server vector and report it to the application
 * through the list's callback (SB_LIST_EVENT_SERVER_ADDED). */
void SBServerListAddServer(void *list, s32 server) {
    M2C_UNK Vector_Append(s32, s32 *);

    Vector_Append(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS), &server);
    M2C_FIELD(list, M2C_UNK (**)(void *, s32, s32, s32), SB_SLIST_CALLBACK)(list, SB_LIST_EVENT_SERVER_ADDED, server, M2C_FIELD(list, s32 *, SB_SLIST_INSTANCE));
}

/* Index in `list`'s server vector of the entry holding `server`, or -1 when the
   list does not contain it. */
s32 SBServerListFindByServer(void *list, s32 server) {
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem();
    s32 count;
    s32 i;

    count = Vector_GetCount(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS));
    for (i = 0; i < count; i++) {
        if (server == *Vector_GetItem(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS), i)) return i;
    }
    return -1;
}

/* Index in `list` of the server whose address and network-order port both match,
 * or -1 when no server does. */
s32 SBServerListFindByAddress(void *list,s32 ip,s32 port){s32 Vector_GetCount(s32);s32 *Vector_GetItem();s32 SBServerGetIp(s32);s32 SBServerGetPortNBO(s32);s32 count,server,i;count=Vector_GetCount(M2C_FIELD(list,s32 *,SB_SLIST_SERVERS));for(i=0;i<count;i++){server=*Vector_GetItem(M2C_FIELD(list,s32 *,SB_SLIST_SERVERS),i);if(ip==SBServerGetIp(server)&&port==SBServerGetPortNBO(server))return i;}return -1;}

void SBServerListRetireServer(void *a,s32 b){void func_02060cbc(s32,s32);s32 p=M2C_FIELD(a,s32 *,0x5d0);if(!p)func_02060cbc(b,0);else func_02060cbc(b,p);M2C_FIELD(a,s32 *,0x5d0)=b;}

/* Remove the server at `index` from the list's server vector: report the removal
 * through the list's callback, drop the entry from the vector, then chain the
 * server onto the list's removed-server list. */
void SBServerListRemoveServerAt(void *list, s32 index) {
    s32 *Vector_GetItem();
    void Vector_RemoveItem(s32, s32);
    s32 server = *Vector_GetItem(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS), index);
    M2C_FIELD(list, M2C_UNK (**)(void *, s32, s32, s32), SB_SLIST_CALLBACK)(list, SB_LIST_EVENT_SERVER_REMOVED, server, M2C_FIELD(list, s32 *, SB_SLIST_INSTANCE));
    Vector_RemoveItem(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS), index);
    SBServerListRetireServer(list, server);
}

#pragma scheduling off
/* Number of servers found so far: the length of the list's server vector. */
s32 SBServerListGetServerCount(void *list) {
    s32 Vector_GetCount(s32);
    return Vector_GetCount(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS));
}
#pragma scheduling reset
s32 SBServerListGetServerAt(void *arg0) {
    s32 *Vector_GetItem(s32);
    return *Vector_GetItem(M2C_FIELD(arg0, s32 *, 4));
}

/* Free every server the list removed earlier, then empty the list's removed-server
 * chain. */
void SBServerListFreeRemovedServers(void *list) {
    M2C_UNK SBServerFree(s32 *);
    s32 SBServerGetNext(s32);
    s32 server;
    s32 current;

    server = M2C_FIELD(list, s32 *, SB_SLIST_FREE_SERVERS);
    if (server == 0) {
        return;
    }
    current = server;
    if (server != 0) {
        do {
            server = SBServerGetNext(server);
            SBServerFree(&current);
            current = server;
        } while (server != 0);
    }
    M2C_FIELD(list, s32 *, SB_SLIST_FREE_SERVERS) = 0;
}

/* Retire each server in the list, clear the server vector, then free the removed-server chain. */
s32 SBServerListClearRemovedServers(void *serverList) {
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem();
    void func_02048b74(s32);
    s32 i;
    s32 serverCount;

    serverCount = Vector_GetCount(M2C_FIELD(serverList, s32 *, SB_SLIST_SERVERS));
    for (i = 0; i < serverCount; i++) {
        SBServerListRetireServer(serverList, *Vector_GetItem(M2C_FIELD(serverList, s32 *, SB_SLIST_SERVERS), i));
    }
    func_02048b74(M2C_FIELD(serverList, s32 *, SB_SLIST_SERVERS));
    SBServerListFreeRemovedServers(serverList);
}

void func_02061c8c(void *arg0) {
    s32 Vector_New(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_FIELD(arg0, s32 *, 4) = Vector_New(4, 0x64, 0);
    M2C_FIELD(arg0, s32 *, 0x5D0) = 0;
}

/* Intern `string` in `owner`'s string table: return the existing canonical copy,
 * bumping its reference count, or add a duplicate with one reference. */
s32 StringIntern(s32 owner,s32 string) {
s32 GetStringInternTable(s32);
s32 *TableLookup(s32,s32 *);
s32 gpiStringDup(s32);
void TableEnter(s32,s32 *);
InternedString entry; InternedString *record;
entry.string=(char *)string;
record=(InternedString *)TableLookup(GetStringInternTable(owner),(s32 *)&entry);
if(record){record->refCount++;return (s32)record->string;}
entry.string=(char *)gpiStringDup(string);entry.refCount=1;
TableEnter(GetStringInternTable(owner),(s32 *)&entry);
return (s32)entry.string;
}

/* Release one reference to an interned string: look the string up in the intern
 * table, drop its reference count and, once that reaches zero, remove the entry
 * (which frees the interned duplicate).  A string that was never interned trips
 * an assert. */
void StringInternRelease(void *a, s32 string) {
    s32 GetStringInternTable(s32);
    s32 *TableLookup(s32, s32 *);
    void TableRemove(s32, s32 *);
    void AssertFailed(void *, void *, void *, s32);
    s32 key[2];
    s32 *record;

    key[0] = string;
    record = TableLookup(GetStringInternTable((s32)a), key);
    if (!record) AssertFailed(sSbAssertInterned, sSbFileName, sSbReleaseStrName, 0xf4);
    if (!record) return;
    if (--record[1]) return;
    TableRemove(GetStringInternTable((s32)a), key);
}

s32 BoundedStringLength(s8 *a,s32 b){s32 i;for(i=0;i<b;i++){if(!a[i])return i+1;}return -1;}

/* GameSpy SBServerListInit: initialise a server-list object with its game name,
   secret key and version strings plus the callback and instance, and clear the
   query state.  Does nothing when `force` is clear and the DNS/network layer is
   not ready, so a list is only created while networking is up. */
void SBServerListInit(void *list,void *gameName,void *secretKey,void *gameVersion,s32 queryPort,s32 force,s32 callback,s32 instance){
extern u8 sSbAssertSlistNotNull[],sSbServerListInitName[],sSbAssertCallbackNotNull[];extern s32 gDnsQueryState[];extern M2C_UNK sSbEmptyString;
void AssertFailed(void*,void*,void*,s32);s32 GetStringInternTable(s32);void StringCopy(void*,void*);void SBServerListSetError(void*,void*);s32 GetSystemTickMilliseconds(void);void SetRandSeed(s32);void func_0204926c(void);
if(!list)AssertFailed(sSbAssertSlistNotNull,sSbFileName,sSbServerListInitName,0x11c);
if(!force && gDnsQueryState[0]!=1)return;
M2C_FIELD(list,s32*,SB_SLIST_STATE)=SB_SLIST_STATE_IDLE;func_02061c8c(list);GetStringInternTable((s32)list);
StringCopy((u8*)list+SB_SLIST_GAMENAME,gameName);StringCopy((u8*)list+SB_SLIST_SECRETKEY,secretKey);StringCopy((u8*)list+SB_SLIST_GAMEVERSION,gameVersion);
M2C_FIELD(list,s32*,SB_SLIST_CALLBACK)=callback;M2C_FIELD(list,s32*,0x48c)=0;
if(!callback)AssertFailed(sSbAssertCallbackNotNull,sSbFileName,sSbServerListInitName,0x132);
M2C_FIELD(list,s32*,SB_SLIST_INSTANCE)=instance;M2C_FIELD(list,void**,SB_SLIST_SORT_FIELD)=&sSbEmptyString;
M2C_FIELD(list,s32*,0x4a0)=0;M2C_FIELD(list,s32*,SB_SLIST_SOCKET)=-1;
M2C_FIELD(list,s32*,0x7c)=0;M2C_FIELD(list,s32*,0x80)=0;M2C_FIELD(list,s32*,8)=0;
M2C_FIELD(list,s32*,0x484)=-1;M2C_FIELD(list,s32*,0x480)=0;
M2C_FIELD(list,s32*,0x4a4)=0;M2C_FIELD(list,s32*,SB_SLIST_QUERY_PORT)=queryPort;
SBServerListSetError(list,&sSbEmptyString);M2C_FIELD(list,s32*,0x5cc)=0;
SetRandSeed(GetSystemTickMilliseconds());func_0204926c();
}

/* Check the master server's reply sitting in the list's receive buffer: when it
 * starts with "Query Error: " the text after the prefix becomes the list's error
 * message and the query-error event is reported.  Either way the disconnect event
 * follows and the list is disconnected. */
s32 SBServerListCheckQueryError(void *list) {
    s32 StringLength(M2C_UNK *);
    s32 StringCompareN(void *, void *, u32);
    void SBServerListSetError(void *, void *);
    s32 SBServerListDisconnect(void *);
    s32 length;
    void *prefix;
    void *buffer;
    void *start;

    length = M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH);
    if (length > 0) {
        prefix = sSbQueryErrorPrefix;
        if ((u32)length > (u32)StringLength(prefix)) {
            buffer = M2C_FIELD(list, void **, SB_SLIST_RECV_BUFFER);
            start = sSbQueryErrorPrefix;
            if (!StringCompareN(buffer, start, StringLength(start))) {
                SBServerListSetError(list, (u8 *)buffer + StringLength(prefix));
                M2C_FIELD(list, M2C_UNK (**)(void *, s32, s32, s32), SB_SLIST_CALLBACK)(list, SB_LIST_EVENT_QUERY_ERROR, sSbNoServer[0], M2C_FIELD(list, s32 *, SB_SLIST_INSTANCE));
            }
        }
    }
    M2C_FIELD(list, M2C_UNK (**)(void *, s32, s32, s32), SB_SLIST_CALLBACK)(list, SB_LIST_EVENT_DISCONNECTED, sSbNoServer[0], M2C_FIELD(list, s32 *, SB_SLIST_INSTANCE));
    SBServerListDisconnect(list);
}

s32 StringHashMod(void *arg0, s32 arg1) {
    extern volatile u8 data_020eac40[128];
    s64 U32DivideRem(s32, s32);
    s8 *p = (s8 *)arg0;
    s8 c;
    s32 h = 0;
    while ((c = *p) != 0) {
        h = 0x9CCF9319 * h + (c >= 0 && c < 0x80 ? data_020eac40[c] : c);
        p++;
    }
    return (s32)((U32DivideRem(h, arg1)) >> 32);
}

#pragma push
#pragma opt_propagation off
/* Open the server list's connection to the Nintendo WFC master server: build
 * the master host name from the list's game name (or use the host override),
 * resolve it, create the list's socket if needed and connect to the master
 * port.  Returns 0 on success, or 1..3 for a failed socket, host lookup or
 * connect. */
s32 SBServerListOpenConnection(void *list) {
    s32 StringHashMod(void *, s32);
    void StringCopy(void *, void *);
    void StringFormat(void *, void *, ...);
    s32 ghiInetAddr(void *);
    void *ghiResolveHostname(void *);
    s32 ghiSocket(s32, s32, s32);
    s32 ghiConnect(s32, void *, s32);
    s32 ghiCloseSocket(s32);
    extern void *gSBServerListSorting;
    extern u8 sSbMasterHostFormat[];
    u8 hostName[128];
    GhiSocketAddress addr;
    s32 masterIndex, fd;
    GhiHostEntry *host;

    masterIndex = StringHashMod((u8 *)list + SB_SLIST_GAMENAME, SB_MASTER_COUNT);
    if (M2C_FIELD(&gSBServerListSorting, void **, SB_SLIST_HOST_OVERRIDE))
        StringCopy(hostName, M2C_FIELD(&gSBServerListSorting, void **, SB_SLIST_HOST_OVERRIDE));
    else
        StringFormat(hostName, sSbMasterHostFormat, (u8 *)list + SB_SLIST_GAMENAME, masterIndex);
    addr.family = 2; /* AF_INET */
    addr.port = SB_MASTER_PORT_NBO;
    addr.addr = ghiInetAddr(hostName);
    if (addr.addr == -1) {
        host = ghiResolveHostname(hostName);
        if (!host) return 2;
        {
            u8 *dst = (u8 *)&addr.addr;
            u8 *src = *host->hostent;
            *(Bytes617BC *)dst = *(Bytes617BC *)src;
        }
    }
    fd = M2C_FIELD(list, s32 *, SB_SLIST_SOCKET);
    if (fd == -1) {
        fd = ghiSocket(2, 1, 0); /* AF_INET, SOCK_STREAM, 0 */
        M2C_FIELD(list, s32 *, SB_SLIST_SOCKET) = fd;
        if (fd == -1) return 1;
    }
    if (ghiConnect(fd, &addr, 8) == 0) return 0;
    ghiCloseSocket(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET));
    M2C_FIELD(list, s32 *, SB_SLIST_SOCKET) = -1;
    return 3;
}
#pragma pop
/* Append the NUL-terminated `string` (or the shared empty string when it is NULL)
 * to the packet buffer at `*cursor`, then advance the cursor and the packet
 * length in `*length` by the bytes copied, the terminator included. */
void AppendString(s32 *cursor, M2C_UNK *string, s32 *length) {
    M2C_UNK MemCopy(s32, M2C_UNK *, s32);
    s32 StringLength(M2C_UNK *);
    extern M2C_UNK sSbEmptyString;
    M2C_UNK *text;
    s32 size;

    text = string;
    if (text == NULL) {
        text = &sSbEmptyString;
    }
    size = StringLength(text) + 1;
    MemCopy(*cursor, text, size);
    *length += size;
    *cursor += size;
}

void AppendByte(s8 **arg0, s8 arg1, s32 *arg2) {
    **arg0 = arg1;
    *arg2 += 1;
    *arg0 += 1;
}

/* Appends `value` to the packet buffer at `*cursor` in big-endian byte order
 * (most significant byte first), then advances the cursor and adds 4 to the
 * packet length in *length.  The variadic tail is how its callers pass the
 * remaining packet arguments. */
void AppendInt32BE(u8 **cursor, s32 value, s32 *length, ...) {
    u8 *out = *cursor;
    const u8 *in = (const u8 *)&value;
    *(Pair617BC *)out = *(const Pair617BC *)in;
    *(Pair617BC *)(out + 2) = *(const Pair617BC *)(in + 2);
    *length += 4;
    *cursor += 4;
}

void AppendBytes(s32 *a,M2C_UNK *b,s32 c,s32 *d) {
M2C_UNK MemCopy(s32,M2C_UNK *,s32);
MemCopy(*a,b,c);*d+=c;*a+=c;
}

/* Fill the 8-byte QR2 session key at +0x74 of the server list with printable
 * random characters, each shifted by one when its parity does not fit the running
 * parity of what was generated so far (the master server checks it). */
void GenerateSessionKey(void *arg0) {
 s32 Rand(void);
 s32 i, parity; s8 *p; s32 prev,cur;
 *(s8 *)((u8 *)arg0+0x74)=Rand()%93+33;   /* '!'..'}' */
 parity=0;
 i=1; do {
 p=(s8 *)((u32)arg0+i);
 prev=p[0x73]; cur=*((s8 *)arg0+0x74);
 { s32 below,over; if(prev<cur)below=1;else below=0; if(cur<79)over=1;else over=0; parity=(cur&1)^(parity^((i^prev)&1)); parity^=over; parity^=below; }
 p[0x74]=Rand()%93+33;
 if ((parity && !(p[0x74]&1)) || (!parity && (p[0x74]&1)==1)) p[0x74]++;
 i++; }while(i<8);
}

/* Send length bytes of data on the list's master-server socket.  When the send
 * fails, disconnect, reconnect and redo the query before one more attempt;
 * returns 3 when the send keeps failing, 0 on success. */
s32 SBServerListSendToMaster(void *list, void *data, s32 length) {
    s32 ghiSend(s32, s32, s32, s32);
    M2C_UNK SBServerListCheckQueryError(void *);
    s32 SBServerListConnectAndQuery(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 err;
    s32 sent;
    s32 retries;

    retries = 1;
loop_1:
    retries -= 1;
    sent = ghiSend(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET), data, length, 0);
    if ((sent <= 0) && (retries >= 0)) {
        SBServerListDisconnect(list);
        err = SBServerListConnectAndQuery(list, 0, 0, 2, 0);
        if (err != 0) {
            SBServerListCheckQueryError(list);
            return err;
        }
        if (retries < 0) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    if (sent <= 0) {
        return 3;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
/* Connect a server list to the QR2 master server and send the initial query packet:
   protocol header, game id, host names, session key, requested fields, filter, query
   flags and (for flag 0x80) the maximum server count; allocate the receive buffer. */
s32 SBServerListConnectAndQuery(void *slist, M2C_UNK filter, M2C_UNK fields, M2C_UNK queryFlags, s32 maxServers) {
extern u8 data_0210017c[],data_02100100[];extern M2C_UNK sSbEmptyString;
void AssertFailed(void*,void*,void*,s32);s32 StringLength(M2C_UNK*);s32 ghiSend(s32,s32,s32,s32);s32 gpiMalloc(s32);
u8 packet[768];s32 length;u8 *out;u16 beLength;u8 *lenBytes,*packetBytes;s32 err;
if(M2C_FIELD(slist,s32*,0)!=1)AssertFailed(data_0210017c,sSbFileName,data_02100100,0x20a);
if(!filter)filter=(s32)&sSbEmptyString;if(!fields)fields=(s32)&sSbEmptyString;
if((u32)StringLength((M2C_UNK*)filter)>256)return 6;if((u32)StringLength((M2C_UNK*)fields)>256)return 6;
err=SBServerListOpenConnection(slist);if(err)return err;
M2C_FIELD(slist,s32*,0x5c4)=queryFlags;GenerateSessionKey(slist);
length=2;out=packet+2;
AppendByte((s8**)&out,0,&length);AppendByte((s8**)&out,1,&length);AppendByte((s8**)&out,3,&length);
AppendInt32BE(&out,M2C_FIELD(slist,s32*,0x4b8),&length);
AppendString((s32*)&out,(M2C_UNK*)((u8*)slist+12),&length);AppendString((s32*)&out,(M2C_UNK*)((u8*)slist+48),&length);
AppendBytes((s32*)&out,(M2C_UNK*)((u8*)slist+0x74),8,&length);
AppendString((s32*)&out,(M2C_UNK*)fields,&length);AppendString((s32*)&out,(M2C_UNK*)filter,&length);
AppendInt32BE(&out,((u32)queryFlags<<24&0xff000000)|(((u32)queryFlags<<8&0xff0000)|(((u32)queryFlags>>24&255)|((u32)queryFlags>>8&0xff00))),&length);
if(M2C_FIELD(slist,s32*,0x5c4)&8)AppendInt32BE(&out,M2C_FIELD(slist,s32*,0x4a4),&length);
if(M2C_FIELD(slist,s32*,0x5c4)&128)AppendInt32BE(&out,maxServers,&length);
lenBytes=(u8 *)&beLength;
beLength=(((u16)length>>8)&255)|(((u16)length<<8)&0xff00);
packetBytes=packet;*((Pair617BC *)packetBytes)=*((Pair617BC *)lenBytes);
if(ghiSend(M2C_FIELD(slist,s32*,0x4b0),(s32)packetBytes,length,0)<=0){SBServerListDisconnect(slist);return 3;}
M2C_FIELD(slist,s32*,0)=3;M2C_FIELD(slist,s32*,0x5c8)=0;
if(!M2C_FIELD(slist,s32*,0x7c)){M2C_FIELD(slist,s32*,0x7c)=gpiMalloc(4096);if(!M2C_FIELD(slist,s32*,0x7c))return 5;M2C_FIELD(slist,s32*,0x80)=0;}
return 0;
}
#pragma pop
/* Release every interned key name the reply parser stored in the list's
 * SB_SLIST_KEY_NAMES array, then reset the count. */
void SBServerListFreeKeyNames(void *list) {
    void StringInternRelease(void *, s32);
    s32 i;

    for (i = 0; i < M2C_FIELD(list, s32 *, SB_SLIST_KEY_NAME_COUNT); i++)
        StringInternRelease(list, ((s32 *)((u8 *)list + SB_SLIST_KEY_NAMES))[i]);
    M2C_FIELD(list, s32 *, SB_SLIST_KEY_NAME_COUNT) = 0;
}

/* Free the list's key schema (SB_SLIST_KEY_LIST): release the interned name of
 * every SBServerListKey entry, free the schema vector and clear the pointer. */
void SBServerListFreeKeyList(void *list) {
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem();
    void StringInternRelease(void *, s32);
    s32 Vector_Free();
    s32 i;
    s32 schema = M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST);
    if (!schema) return;
    for (i = 0; i < Vector_GetCount(M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST)); i++)
        StringInternRelease(list, *Vector_GetItem(M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST), i));
    Vector_Free(M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST));
    M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST) = 0;
}

/* GameSpy SBServerListDisconnect: free the reply buffer and the interned key
 * names, close the master socket, return the list to its idle state and release
 * the key schema. */
s32 SBServerListDisconnect(void *list) {
    s32 gpiFree(); s32 ghiCloseSocket();
    if (M2C_FIELD(list, s32 *, SB_SLIST_RECV_BUFFER)) gpiFree(M2C_FIELD(list, s32 *, SB_SLIST_RECV_BUFFER));
    M2C_FIELD(list, s32 *, SB_SLIST_RECV_BUFFER) = 0;
    M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH) = 0;
    if (M2C_FIELD(list, s32 *, SB_SLIST_SOCKET) != -1) ghiCloseSocket(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET));
    M2C_FIELD(list, s32 *, SB_SLIST_SOCKET) = -1;
    M2C_FIELD(list, s32 *, SB_SLIST_STATE) = SB_SLIST_STATE_IDLE;
    SBServerListFreeKeyList(list);
    M2C_FIELD(list, s32 *, SB_SLIST_PENDING_KEY_COUNT) = -1;
    SBServerListFreeKeyNames(list);
}

/* GameSpy SBServerListClear: tear the list down for reuse - disconnect it,
 * drop the servers retired from the vector, release the shared string-intern
 * table once it is empty, then free the servers vector. */
void SBServerListClear(void *list) {
    M2C_UNK Vector_Free();
    M2C_UNK FreeStringInternTableIfEmpty(void *);
    M2C_UNK SBServerListClearRemovedServers(void *);
    M2C_UNK SBServerListDisconnect();
    SBServerListDisconnect();
    SBServerListClearRemovedServers(list);
    FreeStringInternTableIfEmpty(list);
    if (M2C_FIELD(list, s32 *, SB_SLIST_SERVERS) != 0) {
        Vector_Free();
    }
    M2C_FIELD(list, s32 *, SB_SLIST_SERVERS) = 0;
}

