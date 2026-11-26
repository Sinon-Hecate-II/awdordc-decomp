/* 24 functions from 0x020553C4 to 0x020562D0 (main), found by ds-decomp. */
#include "common.h"
static inline s32 *Init55550(s32 *p) {s32 addr=(s32)p;M2C_FIELD(addr,s32 *,16)=0;M2C_FIELD(addr,s32 *,0)=0;M2C_FIELD(addr,s32 *,4)=0;M2C_FIELD(addr,s32 *,8)=0;M2C_FIELD(addr,s32 *,12)=0;M2C_FIELD(addr,s32 *,20)=0;return p;}
typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;
/* The GpiConnection fields around the buddy-status table (the full struct is
 * GpiConnection in main_0204E408.c). */
typedef struct GpiConnectionHead {
    u8 pad[0x428];
    HashTable *buddyTable; /* +0x428 table of GpiBuddyStatus keyed by profile id */
    s32 unk42c;            /* +0x42C records created */
    s32 buddyCount;        /* +0x430 buddies handed out, the index bound in gpGetBuddyStatus */
} GpiConnectionHead;
typedef struct { u8 bytes[8]; } UnkSocketAddress;

/* The search key gpiGetBuddyStatusByIndex hands to its buddy-table walk: the
 * buddy-list index looked for and the record that carries it. */
typedef struct BuddyIndexSearch {
    s32 index;    /* +0x00 buddy-list index looked for */
    void *buddy;  /* +0x04 the matching GpiBuddyStatus, NULL when none */
} BuddyIndexSearch;
static inline void InitSocketAddress(s32 *p) { s32 addr=(s32)p; M2C_FIELD(addr,s32 *,0)=0; M2C_FIELD(addr,s32 *,4)=0; }

/* Starts the TCP connection to a gpi peer: looks the peer's address record up
 * by profile id, opens a non-blocking stream socket, fills in the socket
 * address (IPv4 address and port) from the record, and connects.  On failure it
 * reports the error and returns 3 (1 when the error came from the connect); on
 * success the peer moves to GPI_PEER_STATE_CONNECTING and it returns 0. */
s32 gpiPeerBeginConnect(M2C_UNK connection, void *peer) {
    s32 ghiSetNonBlocking(s32, M2C_UNK);
    s32 ghiSocket(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 ghiConnect(s32, UnkSocketAddress *, u8);
    s32 ghiGetLastSocketError(s32);
    void gpiCallErrorCallback(void *, s32, s32);
    M2C_UNK gpiSetSocketBuffers(s32);
    void gpiSetError(void **, s32, M2C_UNK);
    s32 gpiSetErrorString(M2C_UNK, M2C_UNK *);
    extern M2C_UNK gGpiErrorConnectPeer;
    extern M2C_UNK gGpiErrorCreateSocket;
    extern M2C_UNK gGpiErrorSetNonBlocking;
    extern M2C_UNK gGpiErrorConnectSocket;
    s32 socketAddress[2];
    s32 peerRecord;
    s32 *record;

    if (gpiFindBuddyStatus(connection, M2C_FIELD(peer, s32 *, 0xc), &peerRecord) == 0) {
        gpiSetErrorString(connection, &gGpiErrorConnectPeer);
        return 3;
    }
    M2C_FIELD(peer, s32 *, 0x8) = ghiSocket(2, 1, 0);
    if (M2C_FIELD(peer, s32 *, 0x8) == -1) {
        gpiSetError(connection, 5, &gGpiErrorCreateSocket);
        gpiCallErrorCallback(connection, 3, 0);
        return 3;
    }
    if (ghiSetNonBlocking(M2C_FIELD(peer, s32 *, 0x8), 0) == 0) {
        gpiSetError(connection, 5, &gGpiErrorSetNonBlocking);
        gpiCallErrorCallback(connection, 3, 0);
        return 3;
    }
    gpiSetSocketBuffers(M2C_FIELD(peer, s32 *, 0x8));
    InitSocketAddress(socketAddress);
    *((u8 *)socketAddress + 1) = 2;
    record = (s32 *)peerRecord;
    socketAddress[1] = M2C_FIELD(M2C_FIELD(record, void **, 8), s32 *, 0x10);
    *((s16 *)socketAddress + 1) = (s16) M2C_FIELD(M2C_FIELD(record, void **, 8), s32 *, 0x14);
    if (ghiConnect(M2C_FIELD(peer, s32 *, 0x8), (UnkSocketAddress *)socketAddress, 8) == -1) {
        s32 socketError = ghiGetLastSocketError(M2C_FIELD(peer, s32 *, 0x8));
        if ((socketError != -6) && (socketError != -0x1a) && (socketError != -0x4c)) {
            gpiSetError(connection, 5, &gGpiErrorConnectSocket);
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
    }
    M2C_FIELD(peer, s32 *, 0x0) = GPI_PEER_STATE_CONNECTING;
    return 0;
}

#pragma opt_dead_code off
/* Builds a gpiPeer "\\m\\<id>\\len\\<len>\\msg\\\n<message>" record into a buffer
 * and queues it on the peer's message vector, then arms the peer's send timeout. */
s32 gpiPeerAddMessage(s32 connection,void *peer,s32 id,s32 message) {
s32 StringLength(s32 *);s32 gpiAppendStringField();s32 gpiAppendIntField();s32 gpiAppendStringToBufferLen();s32 gpiAppendChar();s32 gpiGetTime(s32);
extern s32 data_020fec7c,sGpiPeerSourceFile,data_020fead4,data_020fed34,gGpiMsgTag,gGpiLenTag,gGpiMsgBodyTag;
s32 buffer[6];s32 len,result;
if(!peer)AssertFailed(&data_020fec7c,&sGpiPeerSourceFile,&data_020fead4,0x340);
if(!message)AssertFailed(&data_020fed34,&sGpiPeerSourceFile,&data_020fead4,0x341);
len=StringLength((s32 *)message);
Init55550(buffer);buffer[4]=id;
result=gpiAppendStringField(connection,buffer,&gGpiMsgTag);if(result)return result;
result=gpiAppendIntField(connection,buffer,id);if(result)return result;
result=gpiAppendStringField(connection,buffer,&gGpiLenTag);if(result)return result;
result=gpiAppendIntField(connection,buffer,len);if(result)return result;
result=gpiAppendStringField(connection,buffer,&gGpiMsgBodyTag);if(result)return result;
buffer[5]=buffer[2];
result=gpiAppendStringToBufferLen(connection,buffer,message,len);if(result)return result;
result=gpiAppendChar(connection,buffer,0);if(result)return result;
Vector_Append(M2C_FIELD(peer,s32 *,0x38),buffer);
M2C_FIELD(peer,s32 *,16)=gpiGetTime(0)+300;
return 0;
}
/* Send the gpi transfer-start header "\\m\\<type>\\xfer\\<id> <u> <u>",
 * carrying the request type and its three values, and return the send result. */
s32 gpiPeerStartTransferMessage(s32 connection, s32 peer, s32 type, s32 *values) {
M2C_UNK gpiSendString(s32,s32,void *);
M2C_UNK AssertFailed(void *,void *,void *,s32);
M2C_UNK StringFormat(void *,void *,...);
extern M2C_UNK gGpiAssertTransferId,sGpiPeerSourceFile,gGpiPeerStartTransferMessageName,gGpiTransferHeaderFormat;
u8 header[64];s32 second,first,third;
first=values[0];second=values[1];third=values[2];
if(!values)AssertFailed(&gGpiAssertTransferId,&sGpiPeerSourceFile,&gGpiPeerStartTransferMessageName,0x376);
StringFormat(header,&gGpiTransferHeaderFormat,type,first,second,third);
return gpiSendString(connection,peer,header);
}

/* Queues a gpi message to a peer: sends the "\len\<n>\msg\\n" header (the
 * length being the string's when -1 is passed, an empty string when none), the
 * message bytes themselves and the terminating NUL, then sets the peer's
 * deadline to 300 ticks from now.  Returns a nonzero error code on failure. */
s32 gpiSendFramedMessage(M2C_UNK connection, void *peer, M2C_UNK *message, s32 length) {
s32 gpiGetTime(M2C_UNK);
s32 gpiSendOrBufferSingleChar(M2C_UNK,void *,M2C_UNK);
s32 gpiSendOrBufferStringLen(M2C_UNK,void *,M2C_UNK *,s32);
s32 gpiSendString(s32,s32,void *);
M2C_UNK AssertFailed(void *,void *,void *,s32);
M2C_UNK StringFormat(void *,void *,...);
s32 StringLength(M2C_UNK *);
extern M2C_UNK data_020feb04,sGpiPeerSourceFile,data_020fec7c,gGpiMessageHeaderFormat,data_020fed78;
M2C_UNK header[8];s32 result;
if(!peer)AssertFailed(&data_020fec7c,&sGpiPeerSourceFile,&data_020feb04,0x389);
if(!message)message=&data_020fed78;
if(length==-1)length=StringLength(message);
StringFormat(header,&gGpiMessageHeaderFormat,length);
result=gpiSendString(connection,peer,header);if(result)return result;
result=gpiSendOrBufferStringLen(connection,peer,message,length);if(result)return result;
result=gpiSendOrBufferSingleChar(connection,peer,0);if(result)return result;
M2C_FIELD(peer,s32 *,0x10)=gpiGetTime(0)+0x12c;
return 0;
}

s32 HashBuddyProfileId(s32 *arg0) {
unsigned long long RuntimeIntDivMod(s32);
return (s32)(RuntimeIntDivMod(*arg0)>>32);
}

s32 CompareBuddyProfileId(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

/* Release callback of the buddy table: free a GpiBuddyStatus record's presence
 * details, cached profile info and owned strings, then clear their pointers. */
void FreeGpiBuddyStatus(GpiBuddyStatus *status) {
    M2C_UNK gpiFree(void *);
    M2C_UNK gpiFreeInfo(void *);
    GpiBuddyStatusDetails *details;

    details = status->details;
    if (details != NULL) {
        gpiFree(details->statusString);
        status->details->statusString = NULL;
        gpiFree(status->details->locationString);
        status->details->locationString = NULL;
        gpiFree(status->details);
        status->details = NULL;
    }
    gpiFreeInfo(status);
    gpiFree(status->signature);
    status->signature = NULL;
    gpiFree(status->unk18);
    status->unk18 = NULL;
}

/* Creates the connection's buddy-status table: a hashtable of GpiBuddyStatus
 * records keyed by profile id, with HashBuddyProfileId/CompareBuddyProfileId as
 * its callbacks and FreeGpiBuddyStatus as the record release callback.  Clears
 * the buddy counters and returns 1 when the table was created, 0 on failure. */
s32 gpiCreateBuddyTable(void **connection) {
s32 TableNewDefault();
GpiConnectionHead *gpi=*connection;
gpi->buddyCount=0;gpi->unk42c=0;
gpi->buddyTable=TableNewDefault(sizeof(GpiBuddyStatus),4,HashBuddyProfileId,CompareBuddyProfileId,FreeGpiBuddyStatus);
return gpi->buddyTable!=0;
}

/* Handles a GameSpy GPI '\npr\' (new player) packet: after the shared header
   check it reads the \profileid\ field and, if the player callback is set, queues
   it with the profile id; the packet is otherwise ignored. */
s32 gpiProcessNewPlayer(void **connection,void *request,s32 command) {
s32 gpiProcessErrorReply(void **,s32,s32);void gpiSetError(void **,s32,s32);s32 gpiSetErrorString(s32,s32 *);
s32 StringCompareN(s32,void *,s32);void gpiCallErrorCallback(void *,s32,s32);void *gpiMalloc(s32);s32 gpiAddCallback(void *,Unk02050838Pair,s32 *,void *,s32);void gpiRemoveOperation(void **,void *);
s32 gpiValueForKey(s32,void *,void *,s32);s32 ParseInt(void *);
extern M2C_UNK gGpiNewPlayerTag,gGpiMsgUnexpectedData,gGpiProfileIdKey,gGpiNewPlayerMsgOutOfMemory;
char idText[16];Unk02050838Pair callback;s32 *data;s32 result;s32 profileId;
if(gpiProcessErrorReply(connection,command,1))return 4;
if(StringCompareN(command,&gGpiNewPlayerTag,5)){gpiSetError(connection,1,(s32)&gGpiMsgUnexpectedData);gpiCallErrorCallback(connection,3,1);return 3;}
if(!gpiValueForKey(command,&gGpiProfileIdKey,idText,16)){gpiSetError(connection,1,(s32)&gGpiMsgUnexpectedData);gpiCallErrorCallback(connection,3,1);return 3;}
profileId=ParseInt(idText);
callback=*(Unk02050838Pair *)((u8 *)request+12);
if(callback.unk_0){data=gpiMalloc(8);if(!data){gpiSetErrorString((s32)connection,(s32 *)&gGpiNewPlayerMsgOutOfMemory);return 1;}data[1]=profileId;data[0]=0;result=gpiAddCallback(connection,callback,data,request,0);if(result)return result;}
gpiRemoveOperation(connection,request);return 0;
}

/* Get the buddy status record of player `playerId`, creating an empty (zeroed)
   record in the connection's buddy table when there is none yet.  Returns 1 when
   the record exists afterwards, 0 for an invalid id. */
s32 func_02055aa0(void **connection, s32 playerId) {
    M2C_UNK TableEnter(s32,s32 *);
    M2C_UNK AssertFailed();
    extern M2C_UNK data_020fed8c;
    extern M2C_UNK data_020fedf4;
    extern M2C_UNK data_020fedfc;
    s32 key[7];
    s32 record;
    void *gpi;

    gpi = *connection;
    if (playerId <= 0) {
        AssertFailed(&data_020fedf4, &data_020fedfc, &data_020fed8c, 0x2B5);
    }
    if (playerId <= 0) {
        return 0;
    }
    if (gpiFindBuddyStatus(connection, playerId, &record) != 0) {
        return record;
    }
    M2C_FIELD((s32)key, s32 *, 0) = 0;
    M2C_FIELD((s32)key, s32 *, 4) = 0;
    M2C_FIELD((s32)key, s32 *, 0xC) = 0;
    M2C_FIELD((s32)key, s32 *, 0x10) = 0;
    M2C_FIELD((s32)key, s32 *, 0x14) = 0;
    M2C_FIELD((s32)key, s32 *, 0x18) = 0;
    key[0] = playerId;
    M2C_FIELD((s32)key, s32 *, 8) = 0;
    key[1] = 0;
    key[3] = 0;
    key[4] = 0;
    key[6] = 0;
    key[5] = 0;
    TableEnter(M2C_FIELD(gpi, s32 *, 0x428),key);
    M2C_FIELD(gpi, s32 *, 0x42C) = (s32) (M2C_FIELD(gpi, s32 *, 0x42C) + 1);
    if (gpiFindBuddyStatus(connection, playerId, &record) != 0) {
        return record;
    }
    return 0;
}

/* GameSpy gpi: look up the buddy-status record for `profileId` in the
 * connection's buddy table; store it in *buddyOut and return whether it exists. */
s32 gpiFindBuddyStatus(void **connection,s32 profileId,s32 *buddyOut) {
s32 TableLookup(s32,void *);
s32 key[7];s32 record;GpiConnectionHead *gpi=*connection;
key[0]=profileId;
record=TableLookup((s32)gpi->buddyTable,key);
if(buddyOut)*buddyOut=record;
return record!=0;
}

/* Remove the buddy-status record of player `profileId` from the connection's
 * buddy table, freeing it; does nothing when the connection has no such record. */
void gpiRemoveBuddyStatus(void **connection, s32 profileId) {
    s32 gpiFindBuddyStatus(void **, s32, s32 *);
    s32 record;
    GpiConnectionHead *gpi;

    gpi = *connection;
    if (gpiFindBuddyStatus(connection, profileId, &record) == 0) {
        return;
    }
    TableRemove(gpi->buddyTable, record);
}

void gpiFreeBuddyList(void **arg0) {
    M2C_UNK TableRemove(s32);
    TableRemove(M2C_FIELD(*arg0, s32 *, 0x428));
}

/* Table-walk callback of gpiFindBuddyByNickEmail: when this buddy record has a
   cached profile whose nick and email equal the search's two keys, store the
   record in the search's result slot, set its found flag, and stop the walk
   (return 0); otherwise let the walk continue (return 1). */
s32 gpiMatchBuddyNickEmail(s32 connection, void *entry, void *search) {
    s32 StringCompare(s32, s32);
    GpiInfoResponse *info = M2C_FIELD(entry, GpiInfoResponse **, 0xc);
    if (info != NULL
        && StringCompare(M2C_FIELD(search, s32 *, 0), (s32)info->nick) == 0
        && StringCompare(M2C_FIELD(search, s32 *, 4), (s32)info->email) == 0) {
        *M2C_FIELD(search, void ***, 8) = entry;
        M2C_FIELD(search, s32 *, 12) = 1;
        return 0;
    }
    return 1;
}

/* Find the connection's buddy whose cached profile has the given nick and email:
 * walk the buddy table with the matching predicate and clear `result` when no
 * record matched.  Always returns 0; the found record (or 0) comes back through
 * `result`. */
s32 gpiFindBuddyByNickEmail(void **connection, s32 nick, s32 email, s32 *result) {
    s32 gpiWalkBuddyTable(void **, s32 (*)(s32, void *, void *), void *);
    s32 search[4];
    search[0] = nick;
    search[1] = email;
    search[3] = 0;
    search[2] = (s32) result;
    gpiWalkBuddyTable(connection, gpiMatchBuddyNickEmail, search);
    if (!search[3]) *result = 0;
    return 0;
}

/* TableMapSafe2 callback of gpiWalkBuddyTable: hand the buddy record `buddy` to
 * the walk's callback as (connection, buddy, userData), where `walk` holds the
 * connection at +0, the callback at +4 and its user data at +8. */
void gpiWalkBuddyTableCallback(M2C_UNK buddy, void *walk) {
    M2C_FIELD(walk, M2C_UNK (**)(s32, M2C_UNK, s32), 4)(M2C_FIELD(walk, s32 *, 0), buddy, M2C_FIELD(walk, s32 *, 8));
}

/* Run `callback` over every buddy-status record of the connection's buddy
 * table; returns 1 when the callback accepted one of them, 0 when none was
 * accepted. */
s32 gpiWalkBuddyTable(void **connection,s32 (*callback)(s32,void *,void *),void *userData) {
s32 TableMapSafe2(s32,void (*)(s32,void *),void *);
s32 data[3];
GpiConnectionHead *gpi=*connection;
data[1]=(s32)callback;data[2]=(s32)userData;data[0]=(s32)connection;
return TableMapSafe2((s32)gpi->buddyTable,gpiWalkBuddyTableCallback,data)==0;
}

/* Table-walk predicate of gpiGetBuddyStatusByIndex: accept the buddy record
 * whose presence details carry the searched list index (store the record in the
 * search key and stop the walk with 0); every other record is skipped (1). */
s32 gpiMatchBuddyIndex(s32 connection, void *entry, void *key) {
    GpiBuddyStatus *buddy = (GpiBuddyStatus *) entry;
    BuddyIndexSearch *search = (BuddyIndexSearch *) key;
    GpiBuddyStatusDetails *details;

    details = buddy->details;
    if (details != NULL && search->index == details->index) {
        search->buddy = buddy;
        return 0;
    }
    return 1;
}

/* Return the record of the connection's buddy whose list index is `index`,
 * or NULL when the buddy table has no buddy with that index. */
void *gpiGetBuddyStatusByIndex(void **connection, s32 index) {
    s32 search[2];
    search[0] = index;
    search[1] = 0;
    gpiWalkBuddyTable(connection, gpiMatchBuddyIndex, search);
    return (void *)search[1];
}

/* Whether a gpi peer record holds no live connection state: its player id,
 * socket, receive buffer and handshake deadline are all clear. */
s32 gpiPeerConnectionDone(void *peer) {
    if ((peer != NULL)
        && (M2C_FIELD(peer, s32 *, GPI_PEER_PLAYER_ID) == 0)
        && (M2C_FIELD(peer, s32 *, GPI_PEER_SOCKET) == 0)
        && (M2C_FIELD(peer, s32 *, GPI_PEER_RX_BUFFER) == 0)
        && (M2C_FIELD(peer, s32 *, GPI_PEER_DEADLINE) == 0)) {
        return 1;
    }
    return 0;
}

/* Connects to the GameSpy profile search manager: allocates the search's
 * receive buffer, opens a TCP socket, resolves gpsp.gs.nintendowifi.net and
 * starts a non-blocking connect to it on port 0x74CD (0xcd74 in network byte
 * order). */
s32 gpiStartProfileSearch(void **connection, void *search) {
    void *gpiMalloc(s32);
    s32 ghiSocket(s32, s32, s32);
    s32 ghiSetNonBlocking(s32, s32);
    void *ghiResolveHostname(void *);
    s32 ghiConnect(s32, UnkSocketAddress *, u8);
    s32 ghiGetLastSocketError(s32);
    s32 gpiSetErrorString(M2C_UNK, M2C_UNK *);
    void gpiSetError(void **, s32, M2C_UNK);
    void gpiCallErrorCallback(void *, s32, s32);
    M2C_UNK AssertFailed(void *, void *, void *, s32);
    extern M2C_UNK gGpiSearchMsgOutOfMemory, gGpiSearchMsgCreateSocket, gGpiSearchMsgSetNonBlocking, gGpiSearchManagerHostname, gGpiSearchMsgResolveManager, gGpiSearchAssertSinAddr, gGpiSearchSourceFile, gGpiStartProfileSearchName, gGpiSearchMsgConnect;
    void *searchData = M2C_FIELD(search, void **, 4), *resolved;
    s32 addr[2];
    s32 error;
    M2C_FIELD(searchData, s32 *, 12) = 4096;
    M2C_FIELD(searchData, void **, 8) = gpiMalloc(4097);
    if (!M2C_FIELD(searchData, void **, 8)) { gpiSetErrorString(connection, &gGpiSearchMsgOutOfMemory); return 1; }
    M2C_FIELD(searchData, s32 *, 4) = ghiSocket(2, 1, 0);
    if (M2C_FIELD(searchData, s32 *, 4) == -1) { gpiSetError(connection, 5, &gGpiSearchMsgCreateSocket); gpiCallErrorCallback(connection, 3, 1); return 3; }
    if (!ghiSetNonBlocking(M2C_FIELD(searchData, s32 *, 4), 0)) { gpiSetError(connection, 5, &gGpiSearchMsgSetNonBlocking); gpiCallErrorCallback(connection, 3, 1); return 3; }
    resolved = ghiResolveHostname(&gGpiSearchManagerHostname);
    if (!resolved) { gpiSetError(connection, 5, &gGpiSearchMsgResolveManager); gpiCallErrorCallback(connection, 3, 1); return 3; }
    InitSocketAddress(addr);
    ((u8 *)addr)[1] = 2;
    addr[1] = **M2C_FIELD(resolved, s32 ***, 12);
    if (!addr[1]) AssertFailed(&gGpiSearchAssertSinAddr, &gGpiSearchSourceFile, &gGpiStartProfileSearchName, 89);
    ((u16 *)addr)[1] = 0xcd74;
    if (ghiConnect(M2C_FIELD(searchData, s32 *, 4), (UnkSocketAddress *)addr, 8) == -1) {
        error = ghiGetLastSocketError(M2C_FIELD(searchData, s32 *, 4));
        if (error != -6 && error != -26 && error != -76) { gpiSetError(connection, 5, &gGpiSearchMsgConnect); gpiCallErrorCallback(connection, 3, 1); return 3; }
    }
    M2C_FIELD(search, s32 *, 20) = 1;
    return 0;
}

s32 gpiCreateSearchData(M2C_UNK arg0, void **arg1, s32 arg2) {
void *gpiMalloc(M2C_UNK); M2C_UNK gpiSetErrorString(M2C_UNK,M2C_UNK *); M2C_UNK MemSet(void *,M2C_UNK,M2C_UNK); extern M2C_UNK gGpiSearchMsgOutOfMemory;
void *p,*buf; s32 n;
p=gpiMalloc(0x144);
if(!p){gpiSetErrorString(arg0,&gGpiSearchMsgOutOfMemory);return 1;}
MemSet(p,0,0x144);
M2C_FIELD(p,s32 *,0)=arg2;
M2C_FIELD(p,s32 *,4)=-1;
M2C_FIELD(p,s32 *,8)=0;
M2C_FIELD(p,s32 *,0x10)=0;
M2C_FIELD(p,s32 *,0x14)=0;
M2C_FIELD(p,s32 *,0xc)=0;
M2C_FIELD(p,s32 *,0x20)=0;
M2C_FIELD(p,volatile s32 *,0x24)=0;
n=0x1000;
M2C_FIELD(p,s32 *,0x1c)=n;
buf=gpiMalloc(n+1);
M2C_FIELD(p,void **,0x18)=buf;
if(!buf){gpiSetErrorString(arg0,&gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(p,s32 *,0x13c)=0; M2C_FIELD(p,s32 *,0x140)=0; *arg1=p; return 0;
}

/* Queues a profile search on the connection (bumping its pending-search count),
 * opens the search manager connection, and, for a blocking call, waits for the
 * search to complete.  Returns the operation's error code, 0 on success. */
s32 gpiStartSearch(void **connection, GpiSearchRequest *search, s32 blocking, s32 callback, s32 callbackParam) {
    s32 gpiThink(void **, s32);
    s32 gpiAddOperation(void **, s32, GpiSearchRequest *, void **, s32, s32, s32);
    s32 gpiStartProfileSearch(void **, void *);
    GPIOperation *operation;
    s32 result;
    s32 result2;
    s32 result3;
    void *gpi;

    gpi = *connection;
    M2C_FIELD(gpi, s32 *, GPI_CONN_SEARCH_COUNT) = (s32) (M2C_FIELD(gpi, s32 *, GPI_CONN_SEARCH_COUNT) + 1);
    result3 = gpiAddOperation(connection, GPI_OP_SEARCH, search, (void **)&operation, blocking, callback, callbackParam);
    if (result3 != 0) {
        return result3;
    }
    result2 = gpiStartProfileSearch(connection, operation);
    if (result2 != 0) {
        return result2;
    }
    if (operation->blocking != 0) {
        result = gpiThink(connection, operation->id);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

s32 gpiSearchProfiles(void **connection,s8 *nick,s8 *uniquenick,s8 *email,s8 *firstname,s8 *lastname,s32 icq,s32 countrycode,s32 flags,s32 callback,s32 callbackParam) {
M2C_UNK StringToLower(void *);s32 gpiCreateSearchData(M2C_UNK,void **,M2C_UNK);M2C_UNK StringCopyN(void *,s8 *,M2C_UNK);M2C_UNK gpiSetErrorString(M2C_UNK,M2C_UNK *);
extern M2C_UNK gGpiSearchMsgNoCriteria;
GpiSearchRequest *searchData;s32 r;
/* Start a gpi profile search with the given criteria (at least one of nick,
   unique nick, email, first name, last name or icq must be supplied). */
if(nick && *nick)goto ready;
if(email && *email)goto ready;
if(firstname && *firstname)goto ready;
if(lastname && *lastname)goto ready;
if(icq==0){if(uniquenick && *uniquenick)goto ready;gpiSetErrorString(connection,&gGpiSearchMsgNoCriteria);return 2;}
ready:
r=gpiCreateSearchData(connection,(void **)&searchData,1);if(r)return r;
if(!nick)searchData->nick[0]=0;else StringCopyN(searchData->nick,nick,31);
if(!uniquenick)searchData->uniquenick[0]=0;else StringCopyN(searchData->uniquenick,uniquenick,21);
if(!email)searchData->email[0]=0;else StringCopyN(searchData->email,email,51);
StringToLower(searchData->email);
if(!firstname)searchData->firstname[0]=0;else StringCopyN(searchData->firstname,firstname,31);
if(!lastname)searchData->lastname[0]=0;else StringCopyN(searchData->lastname,lastname,31);
searchData->icq=icq;
if(countrycode<0)countrycode=0;
searchData->countrycode=countrycode;
r=gpiStartSearch(connection,searchData,flags,callback,callbackParam);if(r==0)r=0;return r;
}

