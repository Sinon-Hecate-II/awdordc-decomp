/* 11 functions from 0x0204C7FC to 0x0204D5C0 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"
static inline void clear_socket_address(void *p) { s32 *v = p; v[0] = 0; v[1] = 0; }
static inline s32 char_outside(s32 c) { s32 bad=1; if(c>=0) { if(c<128)bad=0; } return bad; }
static inline s32 char_space(s32 c) { extern u16 gCharClassTable[]; return char_outside(c) ? 0 : (gCharClassTable[c] & 256); }

/* Open the request's socket, make it non-blocking, connect to the resolved
   server address and poll until the connection completes (or fails). */
void ghiDoConnect(GHIConnection *connection) {
    s32 ghiSetNonBlocking(s32, s32);
    M2C_UNK ghiSetRecvBufferSize(s32, s32);
    s32 ghiSocket(s32, s32, s32);
    s32 ghiConnect(s32, void *, s32);
    s32 ghiGetLastSocketError(s32);
    s32 PollOneFd(s32, s32 *, s32, s32);
    M2C_UNK InvokeRequestCallback(void *, s32, s32);
    extern s32 data_020fd010;
    extern s32 gHttpServerOverride;
    extern u16 gHttpPortOverride;
    GhiSocketAddress addr;
    s32 ready;
    s32 error;
    s32 temp_r0;
    s32 connected;
    u16 t2, t3;

    if (connection->socket == -1) {
        temp_r0 = ghiSocket(2, 1, 0);
        connection->socket = temp_r0;
        if (temp_r0 == -1) {
            connection->completed = 1;
            connection->result = 5;
            connection->lastSocketError = ghiGetLastSocketError(connection->socket);
            return;
        }
        if (ghiSetNonBlocking(temp_r0, 0) == 0) {
            connection->completed = 1;
            connection->result = 5;
            connection->lastSocketError = ghiGetLastSocketError(connection->socket);
            return;
        }
        if (connection->throttle != 0) {
            ghiSetRecvBufferSize(connection->socket, data_020fd010);
        }
        clear_socket_address(&addr);
        addr.family = 2;
        if (connection->serverOverride != 0) {
            t2 = connection->portOverride;
            addr.port = (u8)((s32)t2 >> 8) | ((t2 << 8) & 0xFF00);
        } else if (gHttpServerOverride != 0) {
            addr.port = (u8)((s32)gHttpPortOverride >> 8) | ((gHttpPortOverride << 8) & 0xFF00);
        } else {
            t3 = connection->port;
            addr.port = (u8)((s32)t3 >> 8) | ((t3 << 8) & 0xFF00);
        }
        addr.addr = connection->addr;
        if (ghiConnect(connection->socket, &addr, 8) == -1) {
            temp_r0 = ghiGetLastSocketError(connection->socket);
            if (temp_r0 != -6 && temp_r0 != -26 && temp_r0 != -76) {
                connection->completed = 1;
                connection->result = 6;
                connection->lastSocketError = temp_r0;
                return;
            }
        }
    }
    connected = (PollOneFd(connection->socket, (s32 *)0, &ready, &error) > 0) ? 1 : 0;
    if (connected == -1 || error != 0) {
        connection->completed = 1;
        connection->result = 6;
        if (connected != 0) {
            return;
        }
        connection->lastSocketError = ghiGetLastSocketError(connection->socket);
        return;
    }
    if (ready == 0) {
        return;
    }
    connection->state = 2;
    InvokeRequestCallback(connection, 0, 0);
}

void func_0204ca4c(void *a){
s32 StringCompareN(void *,void *,s32);M2C_UNK InvokeRequestCallback(void *,s32,s32);s32 SendBufferedData(void *);void ResetBuffer(void *);M2C_UNK func_0204a740(void *,void *,s32 *);
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK data_020fd88c,gGhttpAssertZero,gGhttpProcessFileName,data_020fd804;
u8 buf[1024];s32 size;
if(!M2C_FIELD(a,s32 *,0x168)){
if(!StringCompareN(M2C_FIELD(a,void **,0x14),&data_020fd88c,8)){
M2C_FIELD(a,s32 *,0xfc)=1;M2C_FIELD(a,s32 *,0x38)=17;return;
}
M2C_FIELD(a,s32 *,0x10)=3;InvokeRequestCallback(a,0,0);return;
}
if(M2C_FIELD(a,s32 *,0x170)){M2C_FIELD(a,s32 *,0x10)=3;InvokeRequestCallback(a,0,0);return;}
if(!M2C_FIELD(a,s32 *,0x16c)&& M2C_FIELD(a,s32 (**)(void *,void *),0x174)(a,(u8 *)a+0x164)==3){
AssertFailed(&gGhttpAssertZero,&gGhttpProcessFileName,&data_020fd804,0x146);return;
}
if(M2C_FIELD(a,s32 *,0x60)>=M2C_FIELD(a,s32 *,0x5c))goto done;
if(!SendBufferedData(a))return;
if(M2C_FIELD(a,s32 *,0x60)<M2C_FIELD(a,s32 *,0x5c))return;
ResetBuffer((u8 *)a+0x50);
done:size=1024;func_0204a740(a,buf,&size);
}

#pragma push
#pragma opt_common_subs off
/* Build the HTTP request line and headers (Host, User-Agent, Connection, Content-Length/
   Content-Type for POST) into the request's send buffer, then flush it to the socket and
   advance the request to its "sent" state. */
void ghiSendRequest(void *request) {
  s32 ghiAppendDataToBuffer(void *, void *, s32);
  s32 AppendHttpHeader(M2C_UNK, M2C_UNK *, M2C_UNK *);
  M2C_UNK AppendChar(s32, s32);
  void AppendInt(s32, s32);
  s32 SendBufferedData(void *);
  void ResetBuffer(void *);
  M2C_UNK *GetContentType(void *);
  M2C_UNK InvokeRequestCallback(void *, s32, s32);
  u8 *StringFind(s32, M2C_UNK *);
  M2C_UNK StringFormat(void *, void *, s32);
  extern M2C_UNK sHttpMethodPost, sHttpMethodHead, sHttpMethodGet, sHttpVersion;
  extern M2C_UNK sHeaderHost, sHeaderHostColon, sHeaderUserAgent, sHttpCrlf;
  extern M2C_UNK sGameSpyUserAgent, sHeaderConnection, sConnectionKeepAlive, sConnectionClose;
  extern M2C_UNK sFormatInt, sHeaderContentLength, sHeaderContentType;
  extern s32 gHttpServerOverride;
  u8 *sendBuf;
  u8 lenText[16];
  if (M2C_FIELD(request, s32 *, 0x5c) == 0) {
    sendBuf = (u8 *)request + 0x50;
    ghiAppendDataToBuffer(sendBuf,
      M2C_FIELD(request, s32 *, 0x13c) ? (void *)&sHttpMethodPost :
        (M2C_FIELD(request, s32 *, 0xc) == 3 ? (void *)&sHttpMethodHead : (void *)&sHttpMethodGet), 0);
    if (M2C_FIELD(request, s32 *, 0x15c) || gHttpServerOverride)
      ghiAppendDataToBuffer(sendBuf, (void *)M2C_FIELD(request, s32 *, 0x14), 0);
    else
      ghiAppendDataToBuffer(sendBuf, (void *)M2C_FIELD(request, s32 *, 0x24), 0);
    ghiAppendDataToBuffer(sendBuf, &sHttpVersion, 0);
    if (M2C_FIELD(request, u16 *, 0x20) == 0x50)
      AppendHttpHeader((M2C_UNK)sendBuf, &sHeaderHost, (M2C_UNK *)M2C_FIELD(request, s32 *, 0x18));
    else {
      ghiAppendDataToBuffer(sendBuf, &sHeaderHostColon, 0);
      ghiAppendDataToBuffer(sendBuf, (void *)M2C_FIELD(request, s32 *, 0x18), 0);
    AppendChar((s32)sendBuf, 0x3a);
    AppendInt((s32)sendBuf, M2C_FIELD(request, u16 *, 0x20));
    ghiAppendDataToBuffer(sendBuf, &sHttpCrlf, 2);
    }
    if (!M2C_FIELD(request, s32 *, 0x28) ||
        !StringFind(M2C_FIELD(request, s32 *, 0x28), &sHeaderUserAgent))
      AppendHttpHeader((M2C_UNK)sendBuf, &sHeaderUserAgent, &sGameSpyUserAgent);
    if (M2C_FIELD(request, s32 *, 0x34))
      AppendHttpHeader((M2C_UNK)sendBuf, &sHeaderConnection, &sConnectionKeepAlive);
    else
      AppendHttpHeader((M2C_UNK)sendBuf, &sHeaderConnection, &sConnectionClose);
    if (M2C_FIELD(request, s32 *, 0x13c)) {
      StringFormat(lenText, &sFormatInt, M2C_FIELD(request, s32 *, 0x14c));
      AppendHttpHeader((M2C_UNK)sendBuf, &sHeaderContentLength, (M2C_UNK *)lenText);
    AppendHttpHeader((M2C_UNK)sendBuf, &sHeaderContentType, (M2C_UNK *)GetContentType(request));
    }
    if (M2C_FIELD(request, s32 *, 0x28))
      ghiAppendDataToBuffer(sendBuf, (void *)M2C_FIELD(request, s32 *, 0x28), 0);
    ghiAppendDataToBuffer(sendBuf, &sHttpCrlf, 2);
    if (sendBuf != (u8 *)request + 0x50)
      ghiAppendDataToBuffer((u8 *)request + 0x50, (void *)M2C_FIELD(sendBuf, s32 *, 4), M2C_FIELD(sendBuf, s32 *, 0xc));
  }
  if (SendBufferedData(request) == 0) return;
  if (M2C_FIELD(request, s32 *, 0x60) < M2C_FIELD(request, s32 *, 0x5c)) return;
  ResetBuffer((u8 *)request + 0x50);
  if(M2C_FIELD(request, s32 *, 0x13c)) M2C_FIELD(request, s32 *, 0x10)=4; else M2C_FIELD(request, s32 *, 0x10)=5;
  InvokeRequestCallback(request, 0, 0);
}
#pragma pop
void func_0204ce20(void *arg0) {
    M2C_UNK func_0204a594(void *);
    M2C_UNK func_0204bc64(void *);
    s32 ghiPostDoPosting(void *);
 extern M2C_UNK gGhttpProcessFileName;
 M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
    extern M2C_UNK data_020fd7d0;
    extern M2C_UNK data_020fd93c;
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(arg0, s32 *, 0x148);
    temp_r0 = ghiPostDoPosting(arg0);
    if (temp_r0 == 0) {
        if ((M2C_FIELD(arg0, s32 *, 0xFC) != 0) && (M2C_FIELD(arg0, s32 *, 0x38) != 0)) {

        } else {
            AssertFailed(&data_020fd93c, &gGhttpProcessFileName, &data_020fd7d0, 0x200);
        }
        func_0204bc64(arg0);
        return;
    }
    if (temp_r5 != M2C_FIELD(arg0, s32 *, 0x148)) {
        func_0204a594(arg0);
    }
    if (temp_r0 != 1) {
        return;
    }
    func_0204bc64(arg0);
    M2C_FIELD(arg0, s32 *, 0x10) = 5;
    InvokeRequestCallback(arg0, 0, 0);
}

void func_0204ceb8(void *arg0) {
    s32 PollOneFd(s32, s32 *, M2C_UNK, M2C_UNK);
    s32 ghiGetLastSocketError(s32);
    M2C_UNK InvokeRequestCallback(void *, M2C_UNK, M2C_UNK);
    s32 sp0;

    if (PollOneFd(M2C_FIELD(arg0, s32 *, 0x48), &sp0, 0, 0) == -1) {
        M2C_FIELD(arg0, s32 *, 0xFC) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 5;
        M2C_FIELD(arg0, s32 *, 0x4C) = ghiGetLastSocketError(M2C_FIELD(arg0, s32 *, 0x48));
        return;
    }
    if (sp0 == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = 6;
    InvokeRequestCallback(arg0, 0, 0);
}

s32 func_0204cf38(void *a){
extern M2C_UNK gGhttpAssertConnection,gGhttpProcessFileName,data_020fd7e0,data_020fd968,data_020fd988;
extern u16 gCharClassTable[];
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
s32 StringScanf(void *,M2C_UNK *,...);
s32 major,minor,status,pos,n,ch;
if(!a)AssertFailed(&gGhttpAssertConnection,&gGhttpProcessFileName,&data_020fd7e0,590);
if(M2C_FIELD(a,s32 *,128)<=0)AssertFailed(&data_020fd968,&gGhttpProcessFileName,&data_020fd7e0,591);
n=StringScanf(M2C_FIELD(a,void **,120),&data_020fd988,&major,&minor,&status,&pos);
while((ch=M2C_FIELD(M2C_FIELD(a,void **,120),s8 *,pos))!=0 && char_space(ch))pos++;
if(n!=3 || major<1 || status<100 || status>=600){
M2C_FIELD(a,s32 *,252)=1;M2C_FIELD(a,s32 *,56)=7;return 0;
}
M2C_FIELD(a,s32 *,228)=major;M2C_FIELD(a,s32 *,232)=minor;M2C_FIELD(a,s32 *,236)=status;M2C_FIELD(a,s32 *,240)=pos;return 1;
}

void func_0204d084(void *a){
s32 func_0204a740(void *,void *,s32 *);s32 ghiAppendDataToBuffer();s32 func_0204cf38(void *);
s32 ghiGetLastSocketError(s32);u8 *StringFind(s32,M2C_UNK *);
extern M2C_UNK sHttpCrlf;
u8 buf[1024];s32 len=1024; s32 n,off;u8 *p;
n=func_0204a740(a,buf,&len);
if(n==3)return;
if(n==1 && M2C_FIELD(a,s32 *,132)==M2C_FIELD(a,s32 *,128))return;
if(n==0 && !ghiAppendDataToBuffer((u8 *)a+116,buf,len))return;
p=StringFind(M2C_FIELD(a,s32 *,120),&sHttpCrlf);
if(p){
*p=0;off=p-M2C_FIELD(a,u8 **,120);
M2C_FIELD(a,s32 *,248)=off+1;
if(!func_0204cf38(a))return;
M2C_FIELD(a,s32 *,132)=off+2;
M2C_FIELD(a,s32 *,16)=7;
InvokeRequestCallback(a,0,0);return;
}
if(n!=2)return;
M2C_FIELD(a,s32 *,252)=1;
M2C_FIELD(a,s32 *,56)=7;
M2C_FIELD(a,s32 *,76)=ghiGetLastSocketError(M2C_FIELD(a,s32 *,72));
}

s32 ghiDeliverFileData(void *arg0,s32 arg1,s32 arg2) {
 s32 ghiAppendDataToBuffer();
 M2C_UNK InvokeRequestCallback(void *,s32,s32);
 s32 a=0,b=0;
 s32 c=M2C_FIELD(arg0,s32 *,0x100)+arg2;
 M2C_FIELD(arg0,s32 *,0x100)=c;
 if(c==M2C_FIELD(arg0,s32 *,0x104)||M2C_FIELD(arg0,s32 *,0x130)) M2C_FIELD(arg0,s32 *,0xFC)=1;
 if(M2C_FIELD(arg0,s32 *,0xC)==0) {
 if(!ghiAppendDataToBuffer(arg0+0xBC)) return 0;
 a=M2C_FIELD(arg0,s32 *,0xC0); b=M2C_FIELD(arg0,s32 *,0xC8);
 } else if(M2C_FIELD(arg0,s32 *,0xC)==1) {
 if(arg2) { M2C_FIELD(arg0,s32 *,0xFC)=1; M2C_FIELD(arg0,s32 *,0x38)=13; return 0; }
 a=arg1;b=arg2;
 } else if(M2C_FIELD(arg0,s32 *,0xC)==2) {a=arg1;b=arg2;}
 InvokeRequestCallback(arg0,a,b); return 1;
}

s32 ghiParseChunkSize(void *arg0) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    s32 StringScanf(void *, M2C_UNK *, ...);
    extern M2C_UNK gGhiParseChunkSizeName;
    extern M2C_UNK gGhttpProcessFileName;
    extern M2C_UNK gGhttpAssertLen;
    extern M2C_UNK gGhttpFormatHex;
    s32 sp0;

    if (M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        AssertFailed(&gGhttpAssertLen, &gGhttpProcessFileName, &gGhiParseChunkSizeName, 0x321);
    }
    if (StringScanf(arg0 + 0x114, &gGhttpFormatHex, &sp0) != 1) {
        return -1;
    }
    return sp0;
}

void ghiAppendToChunkHeaderBuffer(void *p,void *src,s32 n) {
extern M2C_UNK gGhttpAssertConnection,gGhttpProcessFileName,gGhiAppendToChunkHeaderBufferName,gGhttpAssertData,data_020fd9a8;
s32 left;
if(!p)AssertFailed(&gGhttpAssertConnection,&gGhttpProcessFileName,&gGhiAppendToChunkHeaderBufferName,0x333);
if(!src)AssertFailed(&gGhttpAssertData,&gGhttpProcessFileName,&gGhiAppendToChunkHeaderBufferName,0x334);
if(n<0)AssertFailed(&data_020fd9a8,&gGhttpProcessFileName,&gGhiAppendToChunkHeaderBufferName,0x335);
if(!n)return;
if(M2C_FIELD(p,s32 *,0x120)>=10)return;
left=10-M2C_FIELD(p,s32 *,0x120);
if(left>=n)left=n;
MemCopy((u8 *)p+0x114+M2C_FIELD(p,s32 *,0x120),src,left);
M2C_FIELD(p,s32 *,0x120)+=left;
*((u8 *)p+M2C_FIELD(p,s32 *,0x120)+0x114)=0;
}

/* Decode the body of a chunked HTTP response: accumulate each chunk-size line,
   deliver that many body bytes through the request's data callback, skip the
   line after each chunk, and complete the request on the zero-size chunk.  A
   request without chunked encoding passes its bytes straight through. */
s32 ghiProcessIncomingFileData(void *p, void *src, s32 n) {
    s8 *StringFindChar(s8 *, s32);
    void ghiAppendToChunkHeaderBuffer(void *, void *, s32);
    s32 ghiParseChunkSize(void *);
    s32 ghiDeliverFileData(void *, s32, s32);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK gGhttpAssertConnection, gGhttpProcessFileName, gGhiProcessIncomingFileDataName,
        gGhttpAssertData, gGhttpAssertLenPositive, gGhttpAssertZero;

    u8 *q;
    s32 left;
    s32 state;

    if (!p) AssertFailed(&gGhttpAssertConnection, &gGhttpProcessFileName, &gGhiProcessIncomingFileDataName, 0x35d);
    if (!src) AssertFailed(&gGhttpAssertData, &gGhttpProcessFileName, &gGhiProcessIncomingFileDataName, 0x35e);
    if (n <= 0) AssertFailed(&gGhttpAssertLenPositive, &gGhttpProcessFileName, &gGhiProcessIncomingFileDataName, 0x35f);
    if (!((GHIConnection *)p)->chunked) goto tail;

    q = (u8 *)src;
    left = n;

    while (left > 0) {
        state = ((GHIConnection *)p)->chunkState;
        if (state == GHI_CHUNK_SIZE) {
            s8 *found = StringFindChar((s8 *)q, 10);
            if (found) {
                ghiAppendToChunkHeaderBuffer(p, q, (s32)(found - (s8 *)q));
                left -= (s32)((u8 *)(found + 1) - q);
                q = (u8 *)(found + 1);
                {
                    s32 val = ghiParseChunkSize(p);
                    ((GHIConnection *)p)->chunkBytesLeft = val;
                    if (val == -1) {
                        ((GHIConnection *)p)->completed = 1;
                        ((GHIConnection *)p)->result = 7;
                        return 0;
                    }
                    if (val == 0) ((GHIConnection *)p)->chunkState = GHI_CHUNK_DONE;
                    else ((GHIConnection *)p)->chunkState = GHI_CHUNK_DATA;
                }
            } else {
                ghiAppendToChunkHeaderBuffer(p, q, left);
                return 1;
            }
        } else if (state == GHI_CHUNK_DATA) {
            s32 t = ((GHIConnection *)p)->chunkBytesLeft;
            if (t >= left) t = left;
            if (!ghiDeliverFileData(p, (s32)q, t)) return 0;
            q += t;
            ((GHIConnection *)p)->chunkBytesLeft = ((GHIConnection *)p)->chunkBytesLeft - t;
            left -= t;
            if (((GHIConnection *)p)->chunkBytesLeft == 0) ((GHIConnection *)p)->chunkState = GHI_CHUNK_TRAILER;
        } else if (state == GHI_CHUNK_TRAILER) {
            s8 *found = StringFindChar((s8 *)q, 10);
            if (!found) return 1;
            ((GHIConnection *)p)->chunkHeader[0] = 0;
            ((GHIConnection *)p)->chunkHeaderLen = 0;
            {
                s32 seg = (s32)((u8 *)(found + 1) - q);
                ((GHIConnection *)p)->chunkBytesLeft = 0;
                q = (u8 *)(found + 1);
                ((GHIConnection *)p)->chunkState = GHI_CHUNK_SIZE;
                left -= seg;
            }
        } else if (state == GHI_CHUNK_DONE) {
            ((GHIConnection *)p)->completed = 1;
            return 1;
        } else {
            AssertFailed(&gGhttpAssertZero, &gGhttpProcessFileName, &gGhiProcessIncomingFileDataName, 0x3e3);
            return 0;
        }
    }
    return 1;

tail:
    return ghiDeliverFileData(p, (s32)src, n);
}

