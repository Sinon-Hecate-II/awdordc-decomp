/* 24 functions from 0x0205F83C to 0x0206080C (main), found by ds-decomp. */
#include "common.h"
#include "qr2.h"
#include "sb_serverlist.h"
typedef struct { u8 v[4]; } PacketBytes4;
typedef struct { u8 header[3]; PacketBytes4 id; u8 rest[249]; } Packet256;
typedef struct { u8 v[13]; } PacketBytes13;
typedef struct { u8 v[8]; } PacketBytes8;

typedef struct {
    u8 data[QR2_QUERY_SIZE];
    s32 length;
} Qr2Reply;
extern PacketBytes13 data_02100014;
extern PacketBytes8 data_02100024;

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
/* Handle one QR2 datagram, from the master server or relayed from another
 * player: ';' console text goes to the ASCII callback, a '\' request is
 * answered with the final query, and the binary 0xFE 0xFD packets are
 * dispatched on their type byte.  Types 0 and 1 answer a peer's query with our
 * player record / state string, 2 is a ping echoed back as type 5, 4 hands a
 * master error to the error callback and 6 is a message relayed from another
 * player, echoed back as type 7 and delivered once.  Every reply goes back to
 * the master server's address as one datagram. */
void Qr2_HandlePacket(void *qr2, void *packet, s32 length, void *address)
{
    extern void *gQr2Connection;
    M2C_UNK Qr2InitQuery(void *, s32, void *);
    void Qr2AppendPlayerRecord(void *, void *, u8 *, s32);
    void Qr2_ParsePublicAddress(void *, void *);
    void Qr2_AppendStateString(void *, void *, s8 *, s32);
    void Qr2_AppendFinalQuery(void *, void *);
    void Qr2_HandlePeerPacket(void *, void *, s32);
    s32 Qr2_RememberRequest(void *, s32);
    M2C_UNK ghiSendTo(s32, void *, s32, s32, void *, s32);
    void MemCopy(void *, const void *, u32);
    void (*asciiCallback)(void *, s32, void *);
    s8 *bytes = packet;
    s8 *requestId;
    s8 *payload;
    s8 type;
    s32 i;
    Qr2Reply reply;

    reply.length = 0;
    if (qr2 == NULL)
        qr2 = gQr2Connection;
    if (bytes[0] == ';') {
        asciiCallback = M2C_FIELD(qr2, void (**)(void *, s32, void *), QR2_CB_ASCII);
        if (asciiCallback)
            asciiCallback(bytes, length, address);
        return;
    }
    if (bytes[0] == '\\') {
        Qr2_AppendFinalQuery(qr2, &reply);
        ghiSendTo(M2C_FIELD(qr2, s32 *, QR2_SOCKET), &reply,
                  reply.length, 0, address, 8);
        return;
    }
    if (length < QR2_HEADER_SIZE || (u8)bytes[0] != QR2_MAGIC_1 || (u8)bytes[1] != QR2_MAGIC_2)
        return;
    requestId = bytes + 3;
    if (M2C_FIELD(qr2, s32 *, QR2_ERROR_REPORTED) > 0)
        M2C_FIELD(qr2, s32 *, QR2_ERROR_REPORTED) = 0;
    type = bytes[2];
    payload = bytes + QR2_HEADER_SIZE;
    length -= QR2_HEADER_SIZE;
    Qr2InitQuery(reply.data, type, (PacketBytes4 *)requestId);

    switch (type) {
    case QR2_TYPE_QUERY:
        Qr2AppendPlayerRecord(qr2, &reply, (u8 *)payload, length);
        break;
    case QR2_TYPE_STATE:
        if (length >= 13 && M2C_FIELD(qr2, void **, QR2_CB_PUBLIC_ADDRESS))
            Qr2_ParsePublicAddress(qr2, payload + length - 13);
        Qr2_AppendStateString(qr2, &reply, payload, length);
        break;
    case QR2_TYPE_PING:
        if (length > QR2_MAX_PING)
            length = QR2_MAX_PING;
        reply.data[0] = QR2_TYPE_PING_ACK;
        MemCopy(reply.data + reply.length, payload, length);
        reply.length += length;
        break;
    case QR2_TYPE_ERROR:
        if (M2C_FIELD(qr2, s32 *, QR2_ERROR_REPORTED) == -1)
            return;
        /* Only an error addressed to this client (its id in the request id) is ours. */
        i = 0;
        do {
            if (requestId[i] != M2C_FIELD((u8 *)qr2 + i, s8 *, QR2_LOCAL_IP))
                return;
        } while (++i < 4);
        if (length < 2)
            return;
        M2C_FIELD(qr2, s32 *, QR2_ERROR_REPORTED) = -1;
        M2C_FIELD(qr2, void (**)(s32, s8 *, void *), QR2_CB_REPORT_ERROR)(
            payload[0], payload + 1, M2C_FIELD(qr2, void **, QR2_CTX));
        return;
    case QR2_TYPE_PEER:
        i = 0;
        do {
            if (requestId[i] != M2C_FIELD((u8 *)qr2 + i, s8 *, QR2_LOCAL_IP))
                return;
        } while (++i < 4);
        if (length < 4)
            return;
        reply.data[0] = QR2_TYPE_PEER_ACK;
        /* Echo the 4-byte id of the message after the reply header. */
        {
            u8 *output = reply.data;
            const u8 *input = (const u8 *)payload;
            s32 pos = reply.length;
            u8 first = input[0];
            u8 second = input[1];
            output[pos] = first;
            output += pos;
            output[1] = second;
            first = input[2];
            second = input[3];
            output[2] = first;
            output[3] = second;
        }
        reply.length += 4;
        /* The same four bytes are the message's id: deliver only the first copy. */
        {
            u8 *token = (u8 *)&i;
            const u8 *input = (const u8 *)payload;
            u8 first = input[0];
            u8 second = input[1];
            token[0] = first;
            token[1] = second;
            first = input[2];
            second = input[3];
            token[2] = first;
            token[3] = second;
        }
        if (!Qr2_RememberRequest(qr2, i))
            Qr2_HandlePeerPacket(qr2, payload + 4, length - 4);
        break;
    case QR2_TYPE_PEER_ACK:
    case QR2_TYPE_KEEPALIVE:
    default:
        return;
    }
    ghiSendTo(M2C_FIELD(qr2, s32 *, QR2_SOCKET), &reply,
              reply.length, 0, address, 8);
}
#pragma pop
/* Keep the master's NAT mapping alive: send it a minimal type-8 query carrying
 * our client id, then restamp the poll time so the next keep-alive is due 20s later. */
void Qr2_SendKeepAlive(void *qr2) {
    s32 GetSystemTickMilliseconds(void);
    M2C_UNK ghiSendTo(s32, void *, s32, s32, void *, s32);
    M2C_UNK Qr2InitQuery(void *, s32, void *);
    Qr2Reply query;
    query.length = 0;
    Qr2InitQuery(query.data, QR2_TYPE_KEEPALIVE, (u8 *)qr2 + QR2_LOCAL_IP);
    ghiSendTo(M2C_FIELD(qr2, s32 *, QR2_SOCKET), query.data, query.length, 0, (u8 *)qr2 + QR2_REQUEST_ID, 8);
    M2C_FIELD(qr2, s32 *, QR2_LAST_POLL) = GetSystemTickMilliseconds();
}

/* Builds and sends the GameSpy QR2 state query: the local addresses and port,
 * the NAT-negotiation flag, the new state (when it changed), the game name and,
 * once known, the public address and port. Restamps the keep-alive times. */
void Qr2_SendState(void *qr2, s32 state) {
    s32 IpToString(s32);
    s32 GetSystemTickMilliseconds(void);
    M2C_UNK ghiSendTo(s32, void *, s32, s32, void *, s32);
    M2C_UNK Qr2AppendInt(void *, s32);
    M2C_UNK Qr2AppendString(void *, void *);
    M2C_UNK Qr2InitQuery(void *, s32, void *);
    M2C_UNK Qr2AppendPlayerFields(void *, void *, s32, s32, s32, s32, s32, s32);
    M2C_UNK StringFormat(void *, void *, s32, ...);
    extern s32 gLocalIpCount;
    extern s32 gLocalIps[];
    extern M2C_UNK gQr2KeyLocalIpFmt;
    extern M2C_UNK gQr2KeyLocalPort;
    extern M2C_UNK gQr2KeyNatNeg;
    extern M2C_UNK gQr2NatNegOn;
    extern M2C_UNK gQr2NatNegOff;
    extern M2C_UNK gQr2KeyStateChanged;
    extern M2C_UNK gQr2KeyGameName;
    extern M2C_UNK gQr2KeyPublicIp;
    extern M2C_UNK gQr2KeyPublicPort;
    char tempKey[0x14];
    char query[0x804];
    M2C_UNK *natNegValue;
    s32 tick;
    s32 used;
    s32 index;

    M2C_FIELD(query, s32 *, QR2_QUERY_COUNT) = 0;
    Qr2InitQuery(query, 3, (char *)qr2 + QR2_LOCAL_IP);
    index = 0;
    if (gLocalIpCount > 0) {
        do {
            StringFormat(tempKey, &gQr2KeyLocalIpFmt, index);
            Qr2AppendString(query, tempKey);
            Qr2AppendString(query, (M2C_UNK *)IpToString(gLocalIps[index]));
            index += 1;
        } while (index < gLocalIpCount);
    }
    Qr2AppendString(query, &gQr2KeyLocalPort);
    Qr2AppendInt(query, M2C_FIELD(qr2, s32 *, QR2_LOCAL_PORT));
    Qr2AppendString(query, &gQr2KeyNatNeg);
    if (M2C_FIELD(qr2, s32 *, QR2_NATNEG) != 0) {
        natNegValue = &gQr2NatNegOn;
    } else {
        natNegValue = &gQr2NatNegOff;
    }
    Qr2AppendString(query, natNegValue);
    if (state != 0) {
        Qr2AppendString(query, &gQr2KeyStateChanged);
        Qr2AppendInt(query, state);
    }
    Qr2AppendString(query, &gQr2KeyGameName);
    Qr2AppendString(query, (char *)qr2 + QR2_GAMENAME);
    if (M2C_FIELD(qr2, s32 *, QR2_CB_PUBLIC_ADDRESS) != 0) {
        Qr2AppendString(query, &gQr2KeyPublicIp);
        Qr2AppendInt(query, M2C_FIELD(qr2, s32 *, QR2_PUBLIC_IP));
        Qr2AppendString(query, &gQr2KeyPublicPort);
        Qr2AppendInt(query, (s32)M2C_FIELD(qr2, u16 *, QR2_PUBLIC_PORT));
    }
    if (state != QR2_STATE_FINAL) {
        Qr2AppendPlayerFields(qr2, query, 0xFF, 0, 0xFF, 0, 0xFF, 0);
    } else {
        used = M2C_FIELD(query, s32 *, QR2_QUERY_COUNT);
        if ((QR2_QUERY_SIZE - used) >= 1) {
            M2C_FIELD(query, s32 *, QR2_QUERY_COUNT) = used + 1;
            query[used] = 0;
        }
    }
    ghiSendTo(M2C_FIELD(qr2, s32 *, QR2_SOCKET), query, M2C_FIELD(query, s32 *, QR2_QUERY_COUNT), 0, (char *)qr2 + QR2_REQUEST_ID, 8);
    tick = GetSystemTickMilliseconds();
    M2C_FIELD(qr2, s32 *, QR2_LAST_SENT) = tick;
    M2C_FIELD(qr2, s32 *, QR2_LAST_POLL) = tick;
    if (state != 0) {
        M2C_FIELD(qr2, s32 *, QR2_STATE_DIRTY) = 0;
    }
}

/* Register the name pointer for QR2 game key `keyId`; ids from
 * QR2_GAMEKEY_QR2_PARAM up to QR2_GAMEKEY_TABLE_END (inclusive) are accepted,
 * anything else is ignored. */
void Qr2_SetKeyName(s32 keyId, s32 name) {
    extern s32 gQr2KeyNames[];
    if (keyId < QR2_GAMEKEY_QR2_PARAM || keyId > QR2_GAMEKEY_TABLE_END) return;
    gQr2KeyNames[keyId] = name;
}

/* One step of the GameSpy stream cipher's key setup (gs_crypt_init_step): mixes a
 * key byte into the running value and returns a permutation index derived from
 * it, retrying while the index is above `i`. */
u8 GsCryptInitStep(u8 *sbox,u32 i,u8 *key,u32 keyLen,u8 *value,u32 *pos){
 u32 count;u32 mask;u32 result;
 if(i==0)return 0;
 count=0;mask=1;
 while(mask<i)mask=mask*2+1;
 do {
 u32 keyIndex=(*pos)++;
 *value=sbox[*value]+key[keyIndex];
 if(*pos>=keyLen){*pos=0;*value+=keyLen;}
 count++;
 result=mask & *value;
 if(count>11)result%=i;
 }while(result>i);
 return result;
}

/* Fill the GameSpy cipher state with its fixed default schedule: the permutation
 * counted down from 255 and the five step bytes 1, 3, 5, 7 and 11. */
void GsCryptInitDefault(u8 *state) {
    s32 i, j;
    GsCryptState *crypt = (GsCryptState *)state;
    crypt->a = 1; crypt->b = 3; crypt->c = 5; crypt->d = 7; crypt->e = 11;
    for (i = 0, j = 255; i < 256; i++, j--) crypt->sbox[i] = j;
}

/* Initialise the GameSpy stream cipher's state from a key: fill the 256-byte
 * permutation with 0..255, shuffle it with the key's bytes and seed the five
 * step bytes after it; a key of no bytes uses the fixed default state. */
void GsCryptInit(u8 *sbox, u8 *key, u32 keyLen) {
    s32 i;
    u32 pos;
    u8 value;
    u8 j;
    u8 temp;
    if (keyLen < 1) { GsCryptInitDefault(sbox); return; }
    for (i = 0; i < 256; i++) sbox[i] = i;
    pos = 0; value = 0;
    for (i = 255; i >= 0; i--) {
        j = GsCryptInitStep(sbox, i, key, keyLen, &value, &pos);
        temp = sbox[i]; sbox[i] = sbox[j]; sbox[j] = temp;
    }
    sbox[256] = sbox[1]; sbox[257] = sbox[3]; sbox[258] = sbox[5]; sbox[259] = sbox[7]; sbox[260] = sbox[value];
    value = 0; pos = 0;
}

/* Advance the GameSpy stream cipher by one byte: shuffle four permutation entries
 * using the step counters, then XOR the data byte with two permutation lookups
 * and return the cipher byte, remembering both bytes for the next step. */
u8 GsCryptByte(void *cipher, u8 data) {
    GsCryptState *state = (GsCryptState *)cipher;
    u8 swap;
    u8 pos;

    pos = state->a++;
    state->b += state->sbox[pos];
    swap = state->sbox[state->e];
    state->sbox[state->e] = state->sbox[state->b];
    state->sbox[state->b] = state->sbox[state->d];
    state->sbox[state->d] = state->sbox[state->a];
    state->sbox[state->a] = swap;
    state->c += state->sbox[swap];
    state->d = data ^ state->sbox[(u8)(state->sbox[state->c] + state->sbox[state->a])] ^ state->sbox[state->sbox[(u8)(state->sbox[state->d] + state->sbox[state->e] + state->sbox[state->b])]];
    state->e = data;
    return state->d;
}

/* Crypt `length` bytes of `data` in place with the GameSpy stream cipher, one byte at a time. */
void GsCryptData(void *cipher, u8 *data, s32 length) {
    u8 GsCryptByte(void *, u8);
    s32 i;
    for (i = 0; i < length; i++) data[i] = GsCryptByte(cipher, data[i]);
}

/* Append a server record to the tail of a query queue: link it after the old
 * tail, make it the new tail, clear its link and bump the count (setting the
 * head too when the queue was empty). */
void QueryQueue_Append(void *queuePtr, void *serverPtr) {
    QueryQueue *queue = (QueryQueue *)queuePtr;
    GpiPlayer *server = (GpiPlayer *)serverPtr;
    GpiPlayer *oldTail;

    oldTail = queue->tail;
    if (oldTail != NULL) {
        oldTail->next = server;
    }
    queue->tail = server;
    server->next = NULL;
    if (queue->head == NULL) {
        queue->head = server;
    }
    queue->count = (s32)(queue->count + 1);
}

/* Insert a server record at the head of a query queue: link it in front of the
 * old head, make it the tail too when the queue was empty, and bump the count. */
void QueryQueue_PushFront(void *queuePtr, void *serverPtr) {
    QueryQueue *queue = (QueryQueue *)queuePtr;
    GpiPlayer *server = (GpiPlayer *)serverPtr;

    server->next = queue->head;
    queue->head = server;
    if (queue->tail == NULL) {
        queue->tail = server;
    }
    queue->count = (s32)(queue->count + 1);
}

/* Take the head server record off a query queue: advance the head to its link,
 * clear the tail when that empties the queue and decrement the count; returns
 * the removed record, or NULL when the queue was empty. */
void *QueryQueue_Pop(void *queuePtr) {
    QueryQueue *queue = (QueryQueue *)queuePtr;
    GpiPlayer *entry;
    GpiPlayer *next;

    entry = queue->head;
    if (entry != NULL) {
        next = entry->next;
        queue->head = next;
        if (next == NULL) {
            queue->tail = NULL;
        }
        queue->count = (s32)(queue->count - 1);
    }
    return entry;
}

/* Take `request` off a server-browser query queue (a GpiPlayer chain through
 * GpiPlayer.next): unlink it from its neighbours, fix up the head and tail when
 * it was either end, and decrement the count.  Returns 1 when it was queued. */
s32 Qr2Query_RemoveRequest(void *queuePtr, void *requestPtr) {
    QueryQueue *queue = queuePtr;
    GpiPlayer *request = requestPtr;
    GpiPlayer *entry = queue->head;
    GpiPlayer *prev = NULL;

    while (entry) {
        if (entry == request) {
            if (prev)
                prev->next = entry->next;
            if (queue->head == entry)
                queue->head = entry->next;
            if (queue->tail == entry)
                queue->tail = prev;
            queue->count--;
            return 1;
        }
        prev = entry;
        entry = entry->next;
    }
    return 0;
}

/* Empty a query queue: forget its first and last records and its count. */
void QueryQueue_Reset(void *queuePtr) {
    QueryQueue *queue = queuePtr;

    queue->tail = NULL;
    queue->head = NULL;
    queue->count = 0;
}

#pragma opt_propagation off
void Qr2Query_SendQuery(void *a,void *b,s32 unused){
s32 GetSystemTickMilliseconds(void);
M2C_UNK ghiSendTo(s32,void *,s32,s32,void *,s32);
u8 buf[256]; u8 addr[8]; s32 n,i,j; u8 *dst;
QueryQueue_Append(a+8,b); M2C_FIELD(b,s32 *,28)=GetSystemTickMilliseconds();
addr[1]=2;
if(M2C_FIELD(b,u8 *,20)&32)return;
if(M2C_FIELD(a,s32 *,0)==1){
buf[0]=254;buf[1]=253;i=0;buf[2]=i;
dst=buf+3;*(PacketBytes4 *)dst=*(PacketBytes4 *)(b+28);
if(M2C_FIELD(b,u8 *,20)&4){
buf[7]=M2C_FIELD(a,s32 *,64);
j=M2C_FIELD(a,s32 *,64);
if(j>0){dst=buf;do{u8 value=M2C_FIELD(a+i,u8 *,44);i++;dst[8]=value;j=M2C_FIELD(a,s32 *,64);dst++;}while(j>i);}
buf[j+8]=0;buf[M2C_FIELD(a,s32 *,64)+9]=0;
n=M2C_FIELD(a,s32 *,64)+10;
}else{buf[7]=255;buf[8]=255;buf[9]=255;n=10;}
}else { dst=buf; if(M2C_FIELD(b,u8 *,20)&4){*(PacketBytes13 *)dst=data_02100014;n=13;}
else{*(PacketBytes8 *)dst=data_02100024;n=8;} }
if(M2C_FIELD(b,s32 *,0)==M2C_FIELD(a,s32 *,40)&&(M2C_FIELD(b,u8 *,21)&2)){
*(s32 *)(addr+4)=M2C_FIELD(b,s32 *,8);*(u16 *)(addr+2)=M2C_FIELD(b,u16 *,12);
}else{*(s32 *)(addr+4)=M2C_FIELD(b,s32 *,0);*(u16 *)(addr+2)=M2C_FIELD(b,u16 *,4);}
ghiSendTo(M2C_FIELD(a,s32 *,32),buf,n,0,addr,8);
}
#pragma opt_propagation reset
void func_02060398(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_UNK func_0204926c();
    s32 func_020496a4(M2C_UNK, M2C_UNK);
    extern s32 data_0213db84;
    if ((arg3 == 0) && (data_0213db84 != 1)) {
        return;
    }
    func_0204926c();
    M2C_FIELD(arg0, s32 *, 0) = arg2;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = arg4;
    M2C_FIELD(arg0, s32 *, 0x48) = arg5;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = func_020496a4(2, 2);
    QueryQueue_Reset(arg0 + 0x14);
    QueryQueue_Reset(arg0 + 8);
}
#pragma opt_common_subs reset
void func_0206040c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x28) = arg1;
}

/* Empty both query queues of a server-browser list: the detail queries still
 * awaiting a reply and the ones that have not been sent yet. */
void Qr2Query_ResetQueues(void *list) {
    QueryQueue_Reset((u8 *)list + SB_LIST_WAITING);
    QueryQueue_Reset((u8 *)list + SB_LIST_REQUESTS);
}

/* Tear down the server browser's QR2 query socket: close it, mark it invalid and
 * empty the in-flight and waiting query queues. */
void Qr2Query_CloseSocket(void *list) {
    M2C_UNK ghiCloseSocket(s32);
    ghiCloseSocket(M2C_FIELD(list, s32 *, SB_LIST_QUERY_SOCKET));
    M2C_FIELD(list, s32 *, SB_LIST_QUERY_SOCKET) = -1;
    QueryQueue_Reset((u8 *)list + SB_LIST_WAITING);
    QueryQueue_Reset((u8 *)list + SB_LIST_REQUESTS);
}

/* Start a detail query for one server of the list: clear the record's query state
 * and set the kind of query asked for (GPI_PLAYER_QUERY_KEYS, or
 * GPI_PLAYER_QUERY_INFO when `queryKind` is 1; 2 asks for no query at all).  The
 * query is sent right away while fewer than SB_LIST_QUERY_LIMIT are in flight,
 * otherwise the record waits in the list's query queue, at its front when
 * `priority` is set. */
void Qr2Query_StartServerQuery(void *list, GpiPlayer *server, s32 priority, s32 queryKind) {
    void Qr2Query_SendQuery(void *, void *, s32);
    server->state = (u8)(server->state & 0xC3);
    if (queryKind == 0) server->state = (u8)(server->state | GPI_PLAYER_QUERY_KEYS);
    else if (queryKind == 1) server->state = (u8)(server->state | GPI_PLAYER_QUERY_INFO);
    else if (queryKind == 2) return;
    if (M2C_FIELD(list, s32 *, SB_LIST_PENDING) < M2C_FIELD(list, s32 *, SB_LIST_QUERY_LIMIT)) Qr2Query_SendQuery(list, server, priority);
    else if (priority) QueryQueue_PushFront((u8 *)list + SB_LIST_WAITING, server);
    else QueryQueue_Append((u8 *)list + SB_LIST_WAITING, server);
}

/* Dispatch each chunk of a typed message to its handlers found via a table, or fall back to a direct handler. */
void func_020604d8(void *owner, void *entry, s8 *payload, s32 length) {
    s32 GetSystemTickMilliseconds(void);
    void gpiPlayerSetString(void *, s32, void *);
    void func_02060e10(void *, void *, s32);
    s32 BoundedStringLength(void *, s32);
    extern s32 gQr2KeyNames[];
    s32 chunkLen;
    s32 index;

    if (*payload != 0) {
        return;
    }
    payload += 5;
    length -= 5;
    if (M2C_FIELD(entry, u8 *, 0x14) & 4) {
        index = 0;
        while (index < M2C_FIELD(owner, s32 *, 0x40)) {
            chunkLen = BoundedStringLength(payload, length);
            if (chunkLen < 0) {
                break;
            }
            gpiPlayerSetString(entry, gQr2KeyNames[M2C_FIELD(owner + index, u8 *, 0x2C)], payload);
            index++;
            payload += chunkLen;
            length -= chunkLen;
        }
        M2C_FIELD(entry, u8 *, 0x14) |= 0x41;
    } else {
        func_02060e10(entry, payload, length);
        M2C_FIELD(entry, u8 *, 0x14) |= 0x43;
    }
    M2C_FIELD(entry, u8 *, 0x14) &= 0xF3;
    M2C_FIELD(entry, s32 *, 0x1C) = GetSystemTickMilliseconds() - M2C_FIELD(entry, s32 *, 0x1C);
    Qr2Query_RemoveRequest((u8 *)owner + 8, entry);
    M2C_FIELD(owner, void (**)(void *, s32, void *, s32), 0x44)(owner, 0, entry, M2C_FIELD(owner, s32 *, 0x48));
}

/* Handles the text reply to one pending server query, a game server's
 * "\key\value..." answer: parses the fields into the server record and, when the
 * reply carries the \fin marker, marks the record complete, turns its send stamp
 * into the round-trip time, takes it off the pending list and reports the
 * finished query to the browser through its query callback. */
void Qr2Query_HandleTextReply(void *list, void *server, void *reply, s32 unused) {
    s32 GetSystemTickMilliseconds(void);
    M2C_UNK Qr2Query_RemoveRequest(void *, void *);
    M2C_UNK Qr2Query_ParseTextFields(void *, M2C_UNK);
    s32 StringFind(M2C_UNK, M2C_UNK *);
    extern M2C_UNK gQr2FinalMarker;
    GpiPlayer *player = server;
    s32 complete;
    u8 state;

    if (StringFind(reply, &gQr2FinalMarker) != 0) {
        complete = 1;
    } else {
        complete = 0;
    }
    Qr2Query_ParseTextFields(server, reply);
    if (complete == 0) {
        return;
    }
    state = player->state;
    if (state & GPI_PLAYER_QUERY_KEYS) {
        player->state = state | (GPI_PLAYER_STATE_COMPLETE | GPI_PLAYER_STATE_FIELDS);
    } else {
        player->state = state | (GPI_PLAYER_STATE_COMPLETE | GPI_PLAYER_STATE_KEYS);
    }
    player->state &= GPI_PLAYER_QUERY_CLEAR;
    player->ping = GetSystemTickMilliseconds() - player->ping;
    Qr2Query_RemoveRequest((u8 *)list + SB_LIST_REQUESTS, server);
    M2C_FIELD(list, M2C_UNK (**)(void *, M2C_UNK, void *, s32), SB_LIST_ON_QUERY_DONE)(
        list, 0, server, M2C_FIELD(list, s32 *, SB_LIST_QUERY_DATA));
}

s32 func_02060670(void *a,void *b,void *c,s32 d) {
    return 1;
}

#pragma peephole off
void func_02060678(void *p,s32 mode){
s32 ghiSocketCanRecv(s32);s32 ghiRecvFrom(s32,void *,s32,s32,void *,s32 *);
s8 buf[2048];u8 addr[8];s32 alen=8;s32 n;void *q; s32 sock;u32 peer,ip;
sock=mode?M2C_FIELD(p,s32 *,0x24):M2C_FIELD(p,s32 *,0x20);
while(ghiSocketCanRecv(sock)){
n=ghiRecvFrom(sock,buf,2047,0,addr,&alen);if(n==-1)return;buf[n]=0;
for(q=M2C_FIELD(p,void **,8);q;q=M2C_FIELD(q,void **,0x20)){
if(mode&&(M2C_FIELD(q,u8 *,0x15)&8)&&M2C_FIELD(q,u32 *,0x10)==M2C_FIELD(addr,u32 *,4))goto found;
ip=M2C_FIELD(addr,u32 *,4);peer=M2C_FIELD(q,u32 *,0);
if(peer==ip){if(M2C_FIELD(q,u16 *,4)==M2C_FIELD(addr,u16 *,2))goto found;else goto check_mode;}else goto check_mode;
check_mode: if(mode)goto found;
if(peer==M2C_FIELD(p,u32 *,0x28)&&(M2C_FIELD(q,u8 *,0x15)&2)&&M2C_FIELD(q,u32 *,8)==ip&&M2C_FIELD(q,u16 *,12)==M2C_FIELD(addr,u16 *,2))goto found;
continue;
found:
if(mode){if(!func_02060670(p,q,buf,n))continue;break;}
else{if(M2C_FIELD(p,s32 *,0)==1)func_020604d8(p,q,buf,n);else Qr2Query_HandleTextReply(p,q,buf,n);break;}
}
}
}
#pragma peephole reset
