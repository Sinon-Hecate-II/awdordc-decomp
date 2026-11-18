/* 19 functions from 0x0204AA34 to 0x0204B9B8 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"

/* Find a free connection slot, growing the connection table by four slots when all
 * are in use; return the slot index, or -1 if growing the table fails. */
s32 ghiFindFreeConnection(void) {
extern M2C_UNK gGhiConnectionList,ghiAssertNumConnectionsEqLen,ghiAssertFile,ghiAssertFuncFindFreeSlot;
s32 slot, newLength, oldLength; void *slotPtr;
for(slot=0;slot<M2C_FIELD(&gGhiConnectionList,s32 *,GHI_LIST_LENGTH);slot++) {
if(M2C_FIELD(M2C_FIELD(&gGhiConnectionList,void ***,GHI_LIST_CONNECTIONS)[slot],s32 *,0)==0)return slot;
}
if(M2C_FIELD(&gGhiConnectionList,s32 *,GHI_LIST_NUM_CONNECTIONS)!=M2C_FIELD(&gGhiConnectionList,s32 *,GHI_LIST_LENGTH))
AssertFailed(&ghiAssertNumConnectionsEqLen,&ghiAssertFile,&ghiAssertFuncFindFreeSlot,0x33);
oldLength=M2C_FIELD(&gGhiConnectionList,s32 *,GHI_LIST_LENGTH);
newLength=oldLength+GHI_CONNECTION_GROW_STEP;
slotPtr=gpiRealloc(M2C_FIELD(&gGhiConnectionList,void **,GHI_LIST_CONNECTIONS),newLength*4);
if(slotPtr==NULL)return -1;
M2C_FIELD(&gGhiConnectionList,void **,GHI_LIST_CONNECTIONS)=slotPtr;
for(slot=oldLength;slot<newLength;slot++){
M2C_FIELD(&gGhiConnectionList,void ***,GHI_LIST_CONNECTIONS)[slot]=gpiMalloc(GHI_CONNECTION_SIZE);
slotPtr=M2C_FIELD(&gGhiConnectionList,void ***,GHI_LIST_CONNECTIONS)[slot];
if(slotPtr==NULL){
for(--slot;slot>=oldLength;--slot)gpiFree(M2C_FIELD(&gGhiConnectionList,void ***,GHI_LIST_CONNECTIONS)[slot]);
return -1;
}
M2C_FIELD(slotPtr,s32 *,0)=0;
}
M2C_FIELD(&gGhiConnectionList,s32 *,GHI_LIST_LENGTH)=newLength;
return oldLength;
}

#pragma push
#pragma opt_propagation off
/* Take a free connection slot (growing the table if needed), clear it, give it
   the next id and initialise its three HTTP buffers. */
GHIConnection *ghiNewConnection(void) {
extern M2C_UNK gGhiConnectionList;
M2C_UNK ghiLockMutex(); M2C_UNK ghiUnlockMutex();
s32 ghiInitBuffer(void *,void *,s32,s32);
s32 ghiFreeConnection(void *);
s32 i, ok; GHIConnection *conn;
ghiLockMutex(); i=ghiFindFreeConnection();
if(i==-1){ghiUnlockMutex();return NULL;}
conn=M2C_FIELD(&gGhiConnectionList,GHIConnection ***,4)[i];
MemSet(conn,0,0x184);
M2C_FIELD(conn,volatile s32 *,0)=1;
M2C_FIELD(conn,volatile s32 *,4)=i;
{s32 old=M2C_FIELD(&gGhiConnectionList,s32 *,8); M2C_FIELD(&gGhiConnectionList,s32 *,8)=old+1; conn->id=old;}
M2C_FIELD(conn,s32 *,12)=0;
conn->state=0;
conn->url=0;
conn->host=0;
conn->addr=0;
conn->port=0;
conn->path=0;
conn->headers=0;
M2C_FIELD(conn,s32 *,0x2c)=0;
M2C_FIELD(conn,s32 *,0x30)=0;
M2C_FIELD(conn,s32 *,0x34)=0;
conn->result=0;
M2C_FIELD(conn,s32 *,0x3c)=0;
M2C_FIELD(conn,s32 *,0x40)=0;
M2C_FIELD(conn,s32 *,0x44)=0;
conn->socket=-1;
conn->lastSocketError=0;
M2C_FIELD(conn,s32 *,0xe0)=0;
M2C_FIELD(conn,s32 *,0xe4)=0;
M2C_FIELD(conn,s32 *,0xe8)=0;
M2C_FIELD(conn,s32 *,0xec)=0;
M2C_FIELD(conn,s32 *,0xf0)=0;
M2C_FIELD(conn,s32 *,0xf4)=0;
M2C_FIELD(conn,s32 *,0xf8)=0;
conn->completed=0;
conn->bytesReceived=0;
conn->contentLength=-1;
conn->redirectURL=0;
M2C_FIELD(conn,s32 *,0x10c)=0;
conn->chunked=0;
M2C_FIELD(conn,s32 *,0x12c)=0;
conn->throttle=0;
M2C_FIELD(conn,s32 *,0x138)=0;
conn->postData=0;
conn->timeout=500;
conn->portOverride=80;
conn->serverOverride=0;
M2C_FIELD(conn,s32 *,0x164)=0;
ok=ghiInitBuffer(conn,(u8 *)conn+0x50,0x800,0x1000);
if(ok)ok=ghiInitBuffer(conn,(u8 *)conn+0x74,0x800,0x800);
if(ok)ok=ghiInitBuffer(conn,(u8 *)conn+0x98,0x800,0x400);
if(!ok){
((void (*)(void *))&ghiFreeConnection)(conn);ghiUnlockMutex();return NULL;
}
{s32 old=M2C_FIELD(&gGhiConnectionList,s32 *,0); M2C_FIELD(&gGhiConnectionList,s32 *,0)=old+1;}
ghiUnlockMutex();return conn;
}
#pragma pop
/* Release a connection slot: free the strings, buffers and socket it owns,
   run the encryptor cleanup and mark the slot free again. */
s32 ghiFreeConnection(void *connection) {
    extern M2C_UNK data_020fd0a4, ghiAssertFile, data_020fd024, data_020fd0b0, gGhiConnectionList, data_020fd0cc, data_020fd0f4;
    M2C_UNK ghiLockMutex(); M2C_UNK ghiUnlockMutex();
    M2C_UNK func_020496cc(s32, M2C_UNK); M2C_UNK func_020496b8(s32);
    void ghiFreeBuffer(void *); void func_0204bc64(void *);
    s32 func_0204b688(void *); void func_0204b690(s32 *);
    GHIConnection *conn = (GHIConnection *)connection;

    if (!connection) AssertFailed(&data_020fd0a4, &ghiAssertFile, &data_020fd024, 0xb3);
    if (conn->request < 0) AssertFailed(&data_020fd0b0, &ghiAssertFile, &data_020fd024, 0xb4);
    if (conn->request >= ((GHIConnectionList *)&gGhiConnectionList)->length) AssertFailed(&data_020fd0cc, &ghiAssertFile, &data_020fd024, 0xb5);
    if (!conn->inUse) AssertFailed(&data_020fd0f4, &ghiAssertFile, &data_020fd024, 0xb6);
    if (!connection) return 0;
    if (!conn->inUse) return 0;
    if (conn->request < 0) return 0;
    if (conn->request >= ((GHIConnectionList *)&gGhiConnectionList)->length) return 0;
    ghiLockMutex();
    gpiFree(conn->url);
    gpiFree(conn->host);
    gpiFree(conn->path);
    gpiFree(conn->headers);
    gpiFree(conn->redirectURL);
    gpiFree(conn->serverOverride);
    if (conn->socket != -1) {
        func_020496cc(conn->socket, 2);
        func_020496b8(conn->socket);
    }
    ghiFreeBuffer(&conn->buffer);
    ghiFreeBuffer(&conn->readBuffer);
    ghiFreeBuffer(&conn->decryptBuffer);
    ghiFreeBuffer(&conn->bodyBuffer);
    if (conn->postItems) func_0204bc64(conn);
    if (conn->postData && func_0204b688(conn->postData)) {
        func_0204b690(conn->postData);
        conn->postData = 0;
    }
    if (conn->encryptor) {
        if (conn->encryptorCleanup) conn->encryptorCleanup(conn, conn->encryptorState);
        conn->encryptor = 0;
    }
    {s32 *counts = &gGhiConnectionList; M2C_FIELD(conn, s32 *, 0) = 0; (*counts)--;}
    ghiUnlockMutex();
    return 1;
}

/* GameSpy ghttp (ghttpConnection.c): returns the connection holding the given
 * request index, or NULL when the index is out of range or the slot is free.
 * Asserts the index bounds, then re-checks them under the connection-list mutex. */
void *ghiRequestToConnection(s32 request) {
 extern M2C_UNK ghiAssertRequestNonNegative, ghiAssertFile, ghiAssertFuncRequestToConnection, ghiAssertRequestWithinLen, gGhiConnectionList;
 M2C_UNK ghiLockMutex(); M2C_UNK ghiUnlockMutex();
 void *conn;
 if(request<0) AssertFailed(&ghiAssertRequestNonNegative,&ghiAssertFile,&ghiAssertFuncRequestToConnection,0x101);
 if(request>=M2C_FIELD(&gGhiConnectionList,s32 *,GHI_LIST_LENGTH)) AssertFailed(&ghiAssertRequestWithinLen,&ghiAssertFile,&ghiAssertFuncRequestToConnection,0x102);
 ghiLockMutex();
 if(request<0 || request>=M2C_FIELD(&gGhiConnectionList,s32 *,GHI_LIST_LENGTH)) {ghiUnlockMutex();return NULL;}
 conn=M2C_FIELD(&gGhiConnectionList,void ***,GHI_LIST_CONNECTIONS)[request];
 if(M2C_FIELD(conn,s32 *,0)==0) conn=NULL;
 ghiUnlockMutex(); return conn;
}

void func_0204af74(M2C_UNK *arg0) {
 extern M2C_UNK gGhiConnectionList;
 M2C_UNK ghiLockMutex(); M2C_UNK ghiUnlockMutex();
 s32 i; void *p;
 if(M2C_FIELD(&gGhiConnectionList,s32 *,0)<=0) return;
 ghiLockMutex();
 for(i=0;i<M2C_FIELD(&gGhiConnectionList,s32 *,12);i++) {
 p=M2C_FIELD(&gGhiConnectionList,void ***,4)[i];
 if(M2C_FIELD(p,s32 *,0)!=0) ((void (*)(void *))arg0)(p);
 }
 ghiUnlockMutex();
}

/* Reset and release an object's resources and counters, logging if null/empty. */
void func_0204afd8(void *obj) {
    M2C_UNK func_020496b8(s32);
    M2C_UNK func_020496cc(s32, M2C_UNK);
    M2C_UNK ResetBuffer(void *);
    extern M2C_UNK data_020fd038;
    extern M2C_UNK ghiAssertFile;
    extern M2C_UNK data_020fd0a4;
    extern M2C_UNK data_020fd134;
    if (obj == NULL) {
        AssertFailed(&data_020fd0a4, &ghiAssertFile, &data_020fd038, 0x132);
    }
    if (M2C_FIELD(obj, s32 *, 0x108) == 0) {
        AssertFailed(&data_020fd134, &ghiAssertFile, &data_020fd038, 0x133);
    }
    M2C_FIELD(obj, s32 *, 0x10) = 0;
    gpiFree(M2C_FIELD(obj, s32 *, 0x14));
    M2C_FIELD(obj, s32 *, 0x14) = (s32) M2C_FIELD(obj, s32 *, 0x108);
    M2C_FIELD(obj, s32 *, 0x108) = 0;
    gpiFree(M2C_FIELD(obj, s32 *, 0x18));
    M2C_FIELD(obj, s32 *, 0x18) = 0;
    M2C_FIELD(obj, s32 *, 0x1C) = 0;
    M2C_FIELD(obj, s16 *, 0x20) = 0;
    gpiFree(M2C_FIELD(obj, s32 *, 0x24));
    M2C_FIELD(obj, s32 *, 0x24) = 0;
    func_020496cc(M2C_FIELD(obj, s32 *, 0x48), 2);
    func_020496b8(M2C_FIELD(obj, s32 *, 0x48));
    M2C_FIELD(obj, s32 *, 0x48) = -1;
    ResetBuffer(obj + 0x50);
    ResetBuffer(obj + 0x74);
    ResetBuffer(obj + 0x98);
    M2C_FIELD(obj, s32 *, 0xE4) = 0;
    M2C_FIELD(obj, s32 *, 0xE8) = 0;
    M2C_FIELD(obj, s32 *, 0xEC) = 0;
    M2C_FIELD(obj, s32 *, 0xF0) = 0;
    M2C_FIELD(obj, s32 *, 0xF4) = 0;
    M2C_FIELD(obj, s32 *, 0xF8) = 0;
    M2C_FIELD(obj, s32 *, 0x130) = 0;
    M2C_FIELD(obj, s32 *, 0x10C) = (s32) (M2C_FIELD(obj, s32 *, 0x10C) + 1);
}

void func_0204b0dc(void) {
 extern M2C_UNK gGhiConnectionList; s32 ghiFreeConnection(void *);
 void func_0204af74(M2C_UNK *);
 s32 i;
 if(M2C_FIELD(&gGhiConnectionList,void **,4)==NULL)return;
 func_0204af74((M2C_UNK *)ghiFreeConnection);
 for(i=0;i<M2C_FIELD(&gGhiConnectionList,s32 *,12);i++) gpiFree(M2C_FIELD(&gGhiConnectionList,void ***,4)[i]);
 gpiFree(M2C_FIELD(&gGhiConnectionList,void **,4));
 M2C_FIELD(&gGhiConnectionList,void **,4)=NULL;
 M2C_FIELD(&gGhiConnectionList,s32 *,12)=0;
 M2C_FIELD(&gGhiConnectionList,s32 *,0)=0;
}

/* Map a finished request's HTTP status code to a GHTTPResult: 1xx-3xx are not
 * errors, 4xx pick a specific result (the generic update error when unhandled)
 * and 5xx is a server error. */
void ghiSetResultFromStatusCode(GHIConnection *conn) {
    s32 status = conn->statusCode;

    switch (status / 100) {
    case 0: break;
    case 1: case 2: case 3: return;
    case 4:
        switch (status) {
        case 401: conn->result = GHTTP_RESULT_UNAUTHORIZED; return;
        case 403: conn->result = GHTTP_RESULT_FORBIDDEN; return;
        case 404: case 410: conn->result = GHTTP_RESULT_FILE_NOT_FOUND; return;
        default: conn->result = GHTTP_RESULT_UPDATE_ERROR; return;
        }
    case 5: conn->result = GHTTP_RESULT_SERVER_ERROR; return;
    }
}

void func_0204c738(void *);
void ghiDoConnect(void *);
void ghiProcessConnected(void *);
void ghiSendRequest(void *);
void func_0204ce20(void *);
void func_0204ceb8(void *);
void ghiReceiveStatusLine(void *);
void func_0204d5c0(void *);
void ghiReceiveFile(void *);
/* Run one tick of an async operation/state machine: validate the handle, dispatch by its kind, then settle (signal completion and release the handle) unless it is still busy. */
s32 func_0204b210(void *operation) {
    extern M2C_UNK data_020fd170, data_020fd17c, data_020fd158, data_020fd188;
    void func_0204a498(void *);
    s32 ghiFreeConnection(void *);
    s32 status;

    if (!operation) AssertFailed(&data_020fd170, &data_020fd17c, &data_020fd158, 0x5B);
    if (ghiRequestToConnection(M2C_FIELD(operation, s32 *, 4)) != operation)
        AssertFailed(&data_020fd188, &data_020fd17c, &data_020fd158, 0x5C);
    if (M2C_FIELD(operation, s32 *, 0x12C)) return 0;
    M2C_FIELD(operation, s32 *, 0x12C) = 1;
    if (M2C_FIELD(operation, s32 *, 0x10) == 0) func_0204c738(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 1) ghiDoConnect(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 2) ghiProcessConnected(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 3) ghiSendRequest(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 4) func_0204ce20(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 5) func_0204ceb8(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 6) ghiReceiveStatusLine(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 7) func_0204d5c0(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 8) ghiReceiveFile(operation);
    if (M2C_FIELD(operation, s32 *, 0x108)) func_0204afd8(operation);
    status = M2C_FIELD(operation, s32 *, 0xFC);
    if (status == 0)
        M2C_FIELD(operation, s32 *, 0x12C) = 0;
    else {
        ghiSetResultFromStatusCode(operation);
        func_0204a498(operation);
        ghiFreeConnection(operation);
    }
    return status;
}

void func_0204b378(void) {
 M2C_UNK func_0204a608(); M2C_UNK ghiLockMutex(); M2C_UNK ghiUnlockMutex();
 extern s32 gGhiRecvTimeoutMs, data_020fd010, data_0213dcbc;
 ghiLockMutex();
 if (++data_0213dcbc == 1) { func_0204a608(); data_020fd010=125; gGhiRecvTimeoutMs=250; return; }
 ghiUnlockMutex();
}

void func_0204b3cc(void) {
    M2C_UNK func_0204a60c();
    M2C_UNK ghiLockMutex();
    M2C_UNK ghiUnlockMutex();
    void func_0204b0dc();
    extern s32 gHttpServerOverride;
    extern s32 data_0213dcbc;
    s32 temp_r1;

    ghiLockMutex();
    temp_r1 = data_0213dcbc - 1;
    data_0213dcbc = temp_r1;
    if (temp_r1 == 0) {
        func_0204b0dc();
        if (gHttpServerOverride != 0) {
            gpiFree();
            gHttpServerOverride = 0;
        }
        ghiUnlockMutex();
        func_0204a60c();
        return;
    }
    ghiUnlockMutex();
}

s32 ghttpGetEx(char *url, char *headers, void *buffer, s32 bufferSize, s32 post, s32 throttle, s32 blocking, s32 progressCallback, s32 completedCallback, s32 callbackParam) {
    extern s32 data_020fd1c4, data_020fd17c, data_020fd14c, data_020fd1d4, data_020fd1e4, data_0213dcbc;
    void *gpiStringDup(char *);
    s32 ghiInitFixedBuffer(void *, void *, void *, s32);
    s32 ghiInitBuffer(void *, void *, s32, s32);
    s32 func_0204bad4(void *);
    void gpiSleep(s32);
    void *connection;
    s32 bufferInitialized;

    /* Start an HTTP download into a caller buffer or growable buffer, optionally blocking. */
    if (!url || !*url) AssertFailed(&data_020fd1c4, &data_020fd17c, &data_020fd14c, 0x128);
    if (bufferSize < 0) AssertFailed(&data_020fd1d4, &data_020fd17c, &data_020fd14c, 0x129);
    if (buffer && bufferSize == 0) AssertFailed(&data_020fd1e4, &data_020fd17c, &data_020fd14c, 0x12a);
    if (!url || !*url) return -1;
    if (bufferSize < 0) return -1;
    if (buffer && bufferSize == 0) return -1;
    if (!data_0213dcbc) func_0204b378();
    connection = ghiNewConnection();
    if (!connection) return -1;
    M2C_FIELD(connection, s32 *, 12) = 0;
    M2C_FIELD(connection, void **, 20) = gpiStringDup(url);
    if (!M2C_FIELD(connection, void **, 20)) {
        ghiFreeConnection(connection);
        return -1;
    }
    if (headers && *headers) {
        M2C_FIELD(connection, void **, 40) = gpiStringDup(headers);
        if (!M2C_FIELD(connection, void **, 40)) {
            ghiFreeConnection(connection);
            return -1;
        }
    }
    M2C_FIELD(connection, s32 *, 0x13c) = post;
    M2C_FIELD(connection, s32 *, 0x30) = blocking;
    M2C_FIELD(connection, s32 *, 0x3c) = progressCallback;
    M2C_FIELD(connection, s32 *, 0x40) = completedCallback;
    M2C_FIELD(connection, s32 *, 0x44) = callbackParam;
    M2C_FIELD(connection, s32 *, 0x134) = throttle;
    M2C_FIELD(connection, s32 *, 0xe0) = buffer != 0;
    if (M2C_FIELD(connection, s32 *, 0xe0))
        bufferInitialized = ghiInitFixedBuffer(connection, (u8 *)connection + 0xbc, buffer, bufferSize);
    else
        bufferInitialized = ghiInitBuffer(connection, (u8 *)connection + 0xbc, 0x800, 0x800);
    if (!bufferInitialized) {
        ghiFreeConnection(connection);
        return -1;
    }
    if (post && !func_0204bad4(connection)) {
        ghiFreeConnection(connection);
        return -1;
    }
    if (blocking) {
        if (!func_0204b210(connection)) do {
            gpiSleep(10);
        } while (!func_0204b210(connection));
        return 0;
    }
    return M2C_FIELD(connection, s32 *, 4);
}

void func_0204b674(void) {
    void func_0204af74(M2C_UNK *);
    s32 func_0204b210(void *);
    func_0204af74((M2C_UNK *)func_0204b210);
}

s32 func_0204b688(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x10);
}

void func_0204b690(s32 *arg0) {
    M2C_UNK gpiFree(s32 *);
    M2C_UNK Vector_Free(s32);
    Vector_Free(*arg0);
    gpiFree(arg0);
}

M2C_UNK *GetContentType(void *arg0) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020fd264;
    extern M2C_UNK sGhttpPostFile;
    extern M2C_UNK data_020fd384;
    extern M2C_UNK data_020fd38c;
    extern M2C_UNK data_020fd390;
    extern M2C_UNK data_020fd3d4;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x13C);
    if (temp_r4 == NULL) {
        AssertFailed(&data_020fd384, &sGhttpPostFile, &data_020fd264, 0x192);
    }
    if (temp_r4 == NULL) {
        return &data_020fd38c;
    }
    if (M2C_FIELD(temp_r4, s32 *, 0xC) != 0) {
        return &data_020fd390;
    }
    return &data_020fd3d4;
}

/* Byte length of a query-string POST body (a POST with no file parts): for every
 * string part its name, its value, two extra bytes per character the URL encoding
 * expands, and the '=', plus one '&' between consecutive parts. */
s32 ghiPostGetNoFilesContentLength(void *connection) {
 s32 Vector_GetCount(s32); void *Vector_GetItem(s32,s32); s32 StringLength(s32);
 extern M2C_UNK data_020fd3f8,sGhttpPostFile,data_020fd2d0;
 GHIPost *post=(GHIPost *)M2C_FIELD(connection,void **,GHI_POST_DATA); GHIPostData *part; s32 i,count,total=0;
 count=Vector_GetCount(post->items);
 if(count==0)return total;
 for(i=0;i<count;i++) {
 part=(GHIPostData *)Vector_GetItem(post->items,i);
 if(part->type!=GHIString)AssertFailed(&data_020fd3f8,&sGhttpPostFile,&data_020fd2d0,0x1b0);
 total += StringLength((s32)part->name); total += part->u.string.length; total += part->u.string.escapedChars*2; total++;
 }
 return total+(count-1);
}

/* Byte length of the multipart/form-data body of a POST that contains files:
 * the closing boundary line plus, for every part, its fixed header bytes, its
 * field and file names, and the length of its value or file contents. */
s32 ghiPostGetHasFilesContentLength(void *obj) {
    s32 StringLength(s32);
    s32 Vector_GetCount(s32);
    void *Vector_GetItem(s32, s32);
    extern M2C_UNK sGhttpPostFile;
    extern GHIPostLengths ghiPostLengthCache;
    extern u8 sMultipartBoundaryPlain[], sAssertState[], sGhiPostGetHasFilesContentLength[], sAssertZero[];
    GHIPost *post = (GHIPost *)M2C_FIELD(obj, void **, 0x13c);
    GHIPostData *part;
    s32 i, count;
    s32 total = 0;

    if (!ghiPostLengthCache.boundaryLength) {
        s32 boundaryLength = StringLength((s32)sMultipartBoundaryPlain);
        ghiPostLengthCache.boundaryLength = boundaryLength;
        ghiPostLengthCache.stringPartLength = boundaryLength + GHI_STRING_PART_OVERHEAD;
        ghiPostLengthCache.filePartLength = boundaryLength + GHI_FILE_PART_OVERHEAD;
        ghiPostLengthCache.endLength = boundaryLength + GHI_END_OVERHEAD;
    }
    count = Vector_GetCount(post->items);
    for (i = 0; i < count; i++) {
        part = (GHIPostData *)Vector_GetItem(post->items, i);
        if (part->type == GHIString) {
            total += ghiPostLengthCache.stringPartLength;
            total += StringLength((s32)part->name);
            total += part->u.string.length;
        } else if (part->type == GHIFile) {
            total += ghiPostLengthCache.filePartLength;
            total += StringLength((s32)part->name);
            total += StringLength((s32)part->u.diskFile.filename);
            total += StringLength((s32)part->u.diskFile.contentType);
            part = (GHIPostData *)Vector_GetItem(((GHIConnection *)obj)->postItems, i);
            if (!part) AssertFailed(sAssertState, &sGhttpPostFile, sGhiPostGetHasFilesContentLength, 0x1ec);
            total += ((GHIPostState *)part)->length;
        } else if (part->type == GHIFileMemory) {
            total += ghiPostLengthCache.filePartLength;
            total += StringLength((s32)part->name);
            total += StringLength((s32)part->u.memoryFile.filename);
            total += StringLength((s32)part->u.memoryFile.contentType);
            total += part->u.memoryFile.length;
        } else {
            AssertFailed(sAssertZero, &sGhttpPostFile, sGhiPostGetHasFilesContentLength, 0x1f9);
            return 0;
        }
    }
    return total + ghiPostLengthCache.endLength;
}

s32 ghiPostGetContentLength(void *arg0) {
 s32 ghiPostGetHasFilesContentLength(void *); s32 ghiPostGetNoFilesContentLength(void *);
 extern M2C_UNK data_020fd384,sGhttpPostFile,data_020fd27c;
 void *p=M2C_FIELD(arg0,void **,0x13c);
 if(p==NULL)AssertFailed(&data_020fd384,&sGhttpPostFile,&data_020fd27c,0x20c);
 if(p==NULL)return 0;
 if(M2C_FIELD(p,s32 *,12)!=0)return ghiPostGetHasFilesContentLength(arg0);
 return ghiPostGetNoFilesContentLength(arg0);
}

