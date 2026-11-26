/* 24 functions from 0x02044E04 to 0x02045D94 (main), found by ds-decomp. */
#include "common.h"

/* One player record in a web response, as GetWebResponsePlayer copies it out:
 * 0x18 bytes of header (five leading words, then the payload size), followed in
 * the response by dataSize bytes of payload.  When the record is returned, its
 * data pointer is filled in with the address of that payload. */
typedef struct WebResponsePlayer {
    u32 unk[5];          /* +0x00 leading record words */
    u32 dataSize;        /* +0x14 bytes of payload that follow the record */
    u8 *data;            /* payload address inside the response */
} WebResponsePlayer;
#include "wfc.h"
#include "ghttp.h"
typedef struct { u32 words[4]; } CallbackRecord;

/* Open the web request module: start the ghttp library and count this caller as
 * one of the request list's openers (EndWebRequest closes it again). */
s32 BeginWebRequest(void) {
    M2C_UNK ghttpInit();
    extern M2C_UNK gHttpRequestList;
    ghttpInit();
    M2C_FIELD(&gHttpRequestList, s32 *, HTTP_REQUEST_LIST_OPEN_COUNT) = (s32) (M2C_FIELD(&gHttpRequestList, s32 *, HTTP_REQUEST_LIST_OPEN_COUNT) + 1);
    return 1;
}

/* Close one web request: release the ghttp library user and drop the request
 * list's open count, freeing every request node left once the last caller has
 * closed the list. Returns 1 even when there was nothing to close. */
s32 EndWebRequest(void) {
    extern M2C_UNK gHttpRequestList;
    void ghttpCleanup(void);
    void HttpRequestFreeAll(void);
    s32 remaining;

    if (M2C_FIELD(&gHttpRequestList, s32 *, HTTP_REQUEST_LIST_OPEN_COUNT) <= 0) return 1;
    ghttpCleanup();
    remaining = M2C_FIELD(&gHttpRequestList, s32 *, HTTP_REQUEST_LIST_OPEN_COUNT) - 1;
    M2C_FIELD(&gHttpRequestList, s32 *, HTTP_REQUEST_LIST_OPEN_COUNT) = remaining;
    if (remaining == 0) HttpRequestFreeAll();
    return 1;
}

/* Advance the ghttp web-request connections one step: refuse when the network
 * has an error, otherwise pump every live connection and report success. */
s32 PumpWebRequest(void) {
    s32 HasNetError();
    void ghiPumpConnections();
    if (HasNetError() != 0) {
        return 0;
    }
    ghiPumpConnections();
    return 1;
}

#pragma opt_instruction_scheduling off
s32 HttpCompletedCallback(s32 unused,s32 a,s32 b,s32 c,void *arg){
void HeapFree(s32,s32,s32);s32 SetHttpError(s32);void HttpRequestFree(void *);
u32 base=(u32)arg;
s32 flag; s32 result;void (*cb)(s32,s32,s32,s32);void *p=arg;s32 x;
cb=M2C_FIELD(p,void (**)(s32,s32,s32,s32),4);
flag=M2C_FIELD(p,volatile s32 *,12);
if(cb){if(a==0)cb(b,c,a,M2C_FIELD(p,s32 *,0));else{SetHttpError(a);cb(0,0,a,M2C_FIELD(p,s32 *,0));}}
if(a!=0||flag==1){x=M2C_FIELD(p,s32 *,16);if(x==0)flag=1;else HeapFree(4,x,0);}
result=flag!=0;HttpRequestFree((void*)base);return result;
}
#pragma opt_instruction_scheduling reset
/* ghttp progress callback for a web request node: pass the ghttp progress
 * arguments (minus the request index) on to the node's progress callback, with
 * the node's user data as the last argument. */
void HttpProgressCallback(s32 unused,s32 state,s32 buffer,s32 bufferLen,s32 bytesReceived,s32 contentLength,void *p){
WebRequestNode *node=(WebRequestNode *)p;
void (*cb)(s32,s32,s32,s32,s32,s32)=node->onProgress;
if(!cb)return;cb(state,buffer,bufferLen,bytesReceived,contentLength,node->userData);
}

/* Start an asynchronous ghttp request through the game's request list: fetch url with an
 * optional POST source, a body buffer of bufferSize bytes and the caller's progress/completion
 * callbacks. Returns the ghttp request id, or a negative error reported through onComplete. */
s32 HttpRequestStart(s32 url, s32 bufferSize, s32 reuseConnection, s32 post,
                     s32 onProgress, s32 onComplete, s32 userData) {
    s32 HasNetError(void);
    void *HeapAlloc(s32, s32);
    void HeapFree(s32, s32, s32);
    s32 SetHttpError(s32);
    void *HttpRequestAlloc(CallbackRecord *);
    void HttpRequestFree(void *);
    s32 ghttpGetEx(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

    CallbackRecord rec;
    void *buf;
    void *node;
    s32 result;
    s32 old;

    buf = 0;
    if (HasNetError() != 0) {
        return -8;
    }

    rec.words[0] = (u32)userData;
    rec.words[1] = (u32)onComplete;
    rec.words[2] = (u32)onProgress;
    rec.words[3] = (u32)reuseConnection;

    node = HttpRequestAlloc(&rec);
    if (node == 0) {
        SetHttpError(-5);
        ((void (*)(s32, s32, s32, s32))onComplete)((s32)buf, (s32)buf, -5, userData);
        return -5;
    }

    if (bufferSize > 0) {
        buf = HeapAlloc(4, bufferSize);
        if (buf == 0) {
            SetHttpError(-5);
            ((void (*)(s32, s32, s32, s32))onComplete)(0, 0, -5, userData);
            HttpRequestFree(node);
            return -5;
        }
        *(s32 *)((char *)node + 0x10) = (s32)buf;
    }

    if (post != 0) {
        result = ghttpGetEx(url, 0, (s32)buf, bufferSize,
                            *(s32 *)post, 0, 0,
                            (s32)HttpProgressCallback,
                            (s32)HttpCompletedCallback,
                            (s32)node);
    } else {
        result = ghttpGetEx(url, 0, (s32)buf, bufferSize,
                            0, 0, 0,
                            (s32)HttpProgressCallback,
                            (s32)HttpCompletedCallback,
                            (s32)node);
    }

    if (result < 0) {
        SetHttpError(result);
        ((void (*)(s32, s32, s32, s32))onComplete)(0, 0, result, userData);
        old = *(s32 *)((char *)node + 0x10);
        if (old != 0) {
            HeapFree(4, old, 0);
        }
        HttpRequestFree(node);
    }

    *(s32 *)((char *)node + 0x14) = result;
    return result;
}

/* Start an asynchronous HTTP GET: HttpRequestStart with the POST source forced to 0
 * (the URL, buffer size, connection reuse and callbacks pass straight through). */
s32 HttpGetStart(s32 url, s32 bufferSize, s32 reuseConnection, s32 onProgress, s32 onComplete, s32 userData) {
    s32 HttpRequestStart(s32, s32, s32, s32, s32, s32, s32);
    HttpRequestStart(url, bufferSize, reuseConnection, 0, onProgress, onComplete, userData);
}

/* Maps a ghttp result code (0 = success) to the game's network error pair
 * (kind, detail): the detail starts from the base network error value and is
 * shifted by a per-code offset, then the pair is recorded with SetNetError.
 * Returns the result unchanged. */
s32 SetHttpError(s32 result) {
M2C_UNK SetNetError(M2C_UNK,s32);
s32 errorKind=7,errorCode=0xfffe8130;
if(!result)return 0;
switch((u32)(result+7)){
case 0:errorCode-=0x320;break;
case 1:errorCode+=(u32)0xfffffcd6;break;
case 2:errorCode-=0x348;break;
case 3:case 4:case 5:errorCode-=0x334;break;
case 6:errorCode+=(u32)0xfffffcc2;break;
case 8:case 26:errorCode-=1;errorKind=9;break;
case 9:errorCode-=0x348;break;
case 10:errorCode+=(u32)0xfffffcae;break;
case 11:errorCode-=0x1e;break;
case 12:errorCode-=0x32;break;
case 13:case 18:case 19:errorCode-=0x14;break;
case 14:errorCode-=0x35c;break;
case 15:case 16:case 17:errorCode+=(u32)0xfffffc9a;break;
case 20:case 21:errorCode-=0x370;break;
case 22:errorCode+=(u32)0xfffffc86;break;
case 23:errorCode-=0x384;break;
case 24:errorCode+=(u32)0xfffffc72;break;
}
SetNetError(errorKind,errorCode);return result;
}

/* Allocate a request node, copy the caller's callbacks and data into it, clear
 * its buffer, result and link and push it onto gHttpRequestList.  Returns the
 * node, or 0 when the heap is exhausted. */
void *HttpRequestAlloc(CallbackRecord *src) {
    void *HeapAlloc(s32, s32);
    extern M2C_UNK gHttpRequestList;
    WebRequestNode *node = HeapAlloc(4, HTTP_REQUEST_NODE_SIZE);
    if (!node) return 0;
    *(CallbackRecord *)node = *src;
    node->next = 0;
    node->buffer = 0;
    if (!M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0)) {
        M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0) = node;
        return node;
    } else {
        node->next = M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0);
        M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0) = node;
    }
    return node;
}

/* Unlink request node `node` from gHttpRequestList and free it. */
void HttpRequestFree(void *node) {
    extern M2C_UNK gHttpRequestList;
    void HeapFree(s32, s32, s32);
    WebRequestNode *head = M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0);
    WebRequestNode *cur;
    WebRequestNode *doomed;

    if (!head) return;
    if (head == (WebRequestNode *)node) {
        doomed = head->next;
        HeapFree(4, (s32)head, 0);
        M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0) = doomed;
        return;
    }
    cur = head->next;
    while (cur) {
        if (cur != (WebRequestNode *)node) {
            head = cur;
        } else {
            doomed = head->next;
            head->next = doomed->next;
            HeapFree(4, (s32)doomed, 0);
            return;
        }
        cur = cur->next;
    }
}

/* Free every request node left in gHttpRequestList, each one's body buffer
 * first, and leave the list empty. */
void HttpRequestFreeAll(void) {
    extern M2C_UNK gHttpRequestList;
    void HeapFree(s32, s32, s32);
    WebRequestNode *node = M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0);
    WebRequestNode *doomed;

    while (node) {
        doomed = node;
        node = doomed->next;
        if (doomed->buffer) HeapFree(4, (s32)doomed->buffer, 0);
        HeapFree(4, (s32)doomed, 0);
    }
    M2C_FIELD(&gHttpRequestList, WebRequestNode **, 0) = 0;
}

/* Reads the size, server status and record pointer from a completed web response. */
s32 GetWebResponseHeader(s32 *header) {
    s32 HasNetError(void);
    s32 *GetWebResponseBody(s32 *);
    extern s32 gWebTransaction;
    s32 bodySize;
    s32 *body;

    if (HasNetError()) return WEB_RESPONSE_NETWORK_ERROR;
    if (gWebTransaction != WEB_TXN_COMPLETE) return WEB_RESPONSE_NOT_COMPLETE;
    body = GetWebResponseBody(&bodySize);
    if (!bodySize) return WEB_RESPONSE_EMPTY;

    header[WEB_RESPONSE_SIZE] = bodySize;
    header[WEB_RESPONSE_STATUS] = *body++;
    header[WEB_RESPONSE_RECORDS] = (s32)body;
    return 0;
}

/* Validates a NAS web request: checks the network state and the request context,
 * copies the 20-byte key and the four request words out of the request string,
 * builds the stored request descriptor, records the context's source id, and
 * selects the GameSpy endpoint for the configured NAS server. Returns 0 on
 * success, otherwise a nonzero error code. */
s32 RegisterWebRequest(s32 requestStr, s32 context) {
    s32 HasNetError(void);
    s32 VerifyProfileIdBlockCrc(void *);
    s32 HasResolvedNasProfileKey(void *);
    u32 StringLength(void *);
    void *StringCopyPad(void *, void *, s32);
    s32 strtoul(void *, s32, s32);
    s32 func_0204800c(void *, void *, s32, s32, s32, s32);
    s32 StringCompare(void *, void *);
    void func_02047750(s32);
    extern M2C_UNK gWebTransaction;
    extern void *gNasServer;
    extern M2C_UNK gNasProdUrl;

    u8 key[0x15];
    u8 parseBuf[9] = {0};
    s32 param0, param1, param2, param3;

    if (HasNetError() != 0) {
        return 1;
    }
    if (M2C_FIELD(&gWebTransaction, s32 *, 0) != 0) {
        return 3;
    }
    if (VerifyProfileIdBlockCrc((void *)context) == 0 || HasResolvedNasProfileKey((void *)context) == 0) {
        return 6;
    }
    if (StringLength((void *)requestStr) >= 0x54u) {
        return 4;
    }
    StringCopyPad(key, (void *)requestStr, 0x14);
    key[0x14] = 0;
    param0 = strtoul(StringCopyPad(parseBuf, (void *)(requestStr + 0x14), 8), 0, 0x10);
    param1 = strtoul(StringCopyPad(parseBuf, (void *)(requestStr + 0x1c), 8), 0, 0x10);
    param2 = strtoul(StringCopyPad(parseBuf, (void *)(requestStr + 0x24), 8), 0, 0x10);
    param3 = strtoul(StringCopyPad(parseBuf, (void *)(requestStr + 0x2c), 8), 0, 0x10);
    if (func_0204800c((void *)(requestStr + 0x34), key, param0, param1, param2, param3) == 0) {
        return 5;
    }
    M2C_FIELD(&gWebTransaction, s32 *, 4) = M2C_FIELD((void *)context, s32 *, 0x1c);
    if (StringCompare(M2C_FIELD(&gNasServer, void **, 0), (void *)&gNasProdUrl) == 0) {
        func_02047750(1);
    } else {
        func_02047750(0);
    }
    M2C_FIELD(&gWebTransaction, s32 *, 0) = 1;
    return 0;
}

s32 FinishWebRequest(void){void ResetWebRequest(void);extern s32 gWebTransaction;ResetWebRequest();return gWebTransaction=0;}

/* Validate and send a put.asp web request: the record count and payload size
 * must be in range (a payload needs a size), then the put request is built and
 * queued. Returns 0 once sent, otherwise a web error code (8/9 build failures). */
s32 SendWebPutRequest(u32 recordCount, s32 arg1, s32 arg2, s32 payload, u32 payloadSize) {
    s32 HasNetError();
    s32 BuildWebPutRequest(s32, s32, s32, s32, s32, s32);
    extern s32 gWebTransaction;
    s32 r;
    if (HasNetError() != 0) {
        return 1;
    }
    if (gWebTransaction != 1 && gWebTransaction != 5) {
        return 7;
    }
    if (recordCount > 0x3e8u || payloadSize > 0x2fcu) {
        return 2;
    }
    if (payload == 0 && payloadSize != 0) {
        return 2;
    }
    r = BuildWebPutRequest((s32)recordCount, M2C_FIELD(&gWebTransaction, s32 *, 4), arg1, arg2, payload, (s32)payloadSize);
    switch(r) {
    case 3: return 8;
    case 2: return 9;
    default: gWebTransaction=2; return 0;
    }
}

/* Validate and send a get.asp web request: the payload's size, flag and count
   must be in range for the request kind, then build and enqueue the request. */
s32 SendWebGetRequest(s32 kind, u32 playerId, s32 field2, void *payload) {
    s32 HasNetError(void);
    s32 BuildWebGetRequest(s32, u32, s32, s32, void *);
    extern M2C_UNK gWebTransaction;
    s32 result;

    if (HasNetError()) return 1;
    if (M2C_FIELD(&gWebTransaction, s32 *, 0) != 1 && M2C_FIELD(&gWebTransaction, s32 *, 0) != 5) return 10;
    if (playerId > 1000 || !payload) return 2;
    switch (kind) {
    case 0:
        if (M2C_FIELD(payload, s32 *, 0) != 8) return 2;
        if (M2C_FIELD(payload, s32 *, 4) != 0 && M2C_FIELD(payload, s32 *, 4) != 1) return 2;
        break;
    case 1:
        if (M2C_FIELD(payload, s32 *, 0) != 12) return 2;
        if (M2C_FIELD(payload, s32 *, 4) != 0 && M2C_FIELD(payload, s32 *, 4) != 1) return 2;
        if (M2C_FIELD(payload, u32 *, 8) > 30 || M2C_FIELD(payload, u32 *, 8) <= 0) return 2;
        break;
    case 2:
    case 4:
    case 5:
        if (M2C_FIELD(payload, s32 *, 0) != 12) return 2;
        if (M2C_FIELD(payload, s32 *, 4) != 0 && M2C_FIELD(payload, s32 *, 4) != 1) return 2;
        if (M2C_FIELD(payload, u32 *, 8) > 30 || M2C_FIELD(payload, u32 *, 8) <= 1) return 2;
        break;
    case 3:
        if (M2C_FIELD(payload, s32 *, 0) != 268) return 2;
        if (M2C_FIELD(payload, s32 *, 4) != 0 && M2C_FIELD(payload, s32 *, 4) != 1) return 2;
        if (M2C_FIELD(payload, u32 *, 8) > 65 || M2C_FIELD(payload, u32 *, 8) <= 1) return 2;
        break;
    case 6:
        if (M2C_FIELD(payload, s32 *, 0) != 16) return 2;
        if (M2C_FIELD(payload, s32 *, 4) != 0 && M2C_FIELD(payload, s32 *, 4) != 1) return 2;
        if (M2C_FIELD(payload, u32 *, 8) > 30 || M2C_FIELD(payload, u32 *, 8) <= 0) return 2;
        if (M2C_FIELD(payload, u32 *, 16) > 0x7fffffff || M2C_FIELD(payload, u32 *, 16) == 0) return 2;
        break;
    }
    result = BuildWebGetRequest(kind, playerId, M2C_FIELD(&gWebTransaction, s32 *, 4), field2, payload);
    switch (result) {
    case 3:
        return 11;
    case 2:
        return 12;
    default:
        M2C_FIELD(&gWebTransaction, s32 *, 0) = 3;
        return 0;
    }
}

/* Queue a sync.asp web request once the web request API is ready (registered
 * or complete) and the record parameters are in range. Marks the transaction
 * "sync sent", or returns a web request status code. */
s32 SendWebSyncRequest(s32 kind, s32 playerId, u32 recordCount, s32 payload) {
    s32 HasNetError();
    s32 BuildWebSyncRequest(s32, u32, s32, s32);
    extern s32 gWebTransaction;
    s32 buildResult;

    if (HasNetError() != 0) return 1;
    if (gWebTransaction != 1 && gWebTransaction != 5) return 10;
    if (recordCount > 1000) return 2;
    if (kind < 0 || kind >= 9) return 2;
    if (playerId < 0) return 2;
    buildResult = BuildWebSyncRequest(kind, recordCount, playerId, payload);
    switch (buildResult) {
        case 3:
            return 11;
        case 2:
            return 12;
        default:
            gWebTransaction = 4;
            return 0;
    }
}

/* Poll the request behind the active web transaction: the transaction fails when
 * the request state falls back to idle/ready and completes when the request is
 * done.  Returns 1 on a network error, 14 when no put/get/sync request is active,
 * otherwise 0. */
s32 PollWebTransaction(void) {
    s32 HasNetError();
    s32 StepWebRequest();
    extern s32 gWebTransaction;
    if (HasNetError()) return 1;
    if (gWebTransaction != WEB_TXN_PUT_SENT && gWebTransaction != WEB_TXN_GET_SENT && gWebTransaction != WEB_TXN_SYNC_SENT) return 14;
    switch (StepWebRequest()) {
        case 1:
            gWebTransaction = WEB_TXN_FAILED;
            break;
        case 0:
            gWebTransaction = WEB_TXN_FAILED;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        case 8:
            gWebTransaction = WEB_TXN_COMPLETE;
            break;
    }
    return 0;
}

s32 GetWebTransactionStatus(void) {
    extern s32 gWebTransaction;
    return gWebTransaction;
}

s32 HasNetError(void);
/* Copy the web response's player record at `index` into *player: return 1 on a
 * network error or the response header's error, 2 when there is no output
 * pointer or the record is out of range, WEB_STATUS_NO_DATA when the reply
 * carries no player data, otherwise 0.  The returned record's data pointer
 * addresses its payload inside the response. */
s32 GetWebResponsePlayer(WebResponsePlayer *player, u32 index)
{
    s32 header[3];
    s32 error;
    u8 *records;
    u8 *payload;
    WebResponsePlayer *record;

    if (HasNetError()) return 1;
    error = GetWebResponseHeader(header);
    if (error) return error;
    switch (header[WEB_RESPONSE_STATUS]) {
    case 0:
        return WEB_STATUS_NO_DATA;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        break;
    }

    if (!player) return 2;
    records = (u8 *)header[WEB_RESPONSE_RECORDS];
    if (index >= *(u32 *)records) return 2;
    record = (WebResponsePlayer *)(records + 8);
    while (index--) {
        record = (WebResponsePlayer *)((u8 *)record + 0x18 + record->dataSize);
    }
    payload = (u8 *)record + 0x18;
    if (payload + record->dataSize > records + header[WEB_RESPONSE_SIZE]) return 2;
    *player = *record;
    player->data = payload;
    return 0;
}

/* Read the number of player records in the current web response: return 1 on a
 * network error, the response header's error, 2 when there is no output pointer,
 * WEB_STATUS_NO_DATA when the server's reply has no player data, otherwise store
 * the record count through `total` and return 0. */
s32 GetWebResponsePlayerTotal(s32 *total) {
    s32 HasNetError(void);
    s32 GetWebResponseHeader(s32 *);
    s32 info[3], error;

    if (HasNetError()) return 1;
    error = GetWebResponseHeader(info);
    if (error) return error;
    if (!total) return 2;
    switch (info[WEB_RESPONSE_STATUS]) {
        case 0:
            return WEB_STATUS_NO_DATA;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        default:
            *total = *(s32 *)info[WEB_RESPONSE_RECORDS];
            return 0;
    }
}

/* Read the number of players online on the server from the current web response:
 * on success store it through `online` and return 0, else return 1 on a network
 * error, the response header's error, or 2 when there is no output pointer. */
s32 GetWebResponseOnlinePlayerCount(s32 *online) {
 s32 HasNetError(void); s32 GetWebResponseHeader(s32 *);
 s32 header[3], error;
 if (HasNetError()) return WEB_RESPONSE_NETWORK_ERROR;
 error = GetWebResponseHeader(header);
 if (error) return error;
 if (!online) return 2;
 *online = ((s32 *)header[WEB_RESPONSE_RECORDS])[WEB_RESPONSE_ONLINE];
 return 0;
}

/* Read the three player save-slot images that hold the friend codes from the save
 * area over the FIFO into `slots` (the front of the WFC friends block), which is
 * WFC_SAVE_SLOT_COUNT images of WFC_STATE_SLOT_STRIDE bytes.  Returns 1 when the
 * read succeeded. */
s32 FifoReadWfcSaveSlots(void *slots) {
    s32 FifoReadBlock(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK gFifoBlockTransfer;
    if (FifoReadBlock(M2C_FIELD(&gFifoBlockTransfer, s32 *, FIFO_XFER_ADDRESS),
                      WFC_SAVE_SLOT_COUNT * WFC_STATE_SLOT_STRIDE, slots) != 0) {
        return 1;
    }
    return 0;
}

/* Unpacks the local WFC profile from the packed firmware blob into the 20-byte
 * record the game passes around: the 43-bit friend code, the generated 43-bit
 * profile code, the 10-bit profile id and the 16-bit seed the code came from. */
void GetWfcProfile(void *profile) {
    void MI_CpuCopy8(void *, void *, u32);
    extern M2C_UNK gWfcProfileCode;
    extern M2C_UNK data_0213db39;
    extern M2C_UNK data_0213db3e;
    extern M2C_UNK data_0213db40;
    u64 *ids = (u64 *)profile;
    u16 *idAndSeed = (u16 *)((u8 *)profile + WFC_PROFILE_ID);

    MI_CpuCopy8(&gWfcProfileCode, &ids[0], 6);
    ids[0] &= WFC_PROFILE_ID_MASK;
    MI_CpuCopy8(&data_0213db39, &ids[1], 6);
    ids[1] >>= WFC_PROFILE_CODE_SHIFT;
    ids[1] &= WFC_PROFILE_ID_MASK;
    MI_CpuCopy8(&data_0213db3e, idAndSeed, 2);
    *idAndSeed >>= WFC_PROFILE_ID_SHIFT;
    *idAndSeed &= WFC_PROFILE_ID10_MASK;
    MI_CpuCopy8(&data_0213db40, idAndSeed + 1, 2);
}

