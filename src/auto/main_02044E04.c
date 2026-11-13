/* 24 functions from 0x02044E04 to 0x02045D94 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"
typedef struct { u32 words[4]; } CallbackRecord;

s32 func_02044e04(void) {
    M2C_UNK func_0204b378();
    extern M2C_UNK gHttpRequestList;
    func_0204b378();
    M2C_FIELD(&gHttpRequestList, s32 *, 4) = (s32) (M2C_FIELD(&gHttpRequestList, s32 *, 4) + 1);
    return 1;
}

s32 func_02044e28(void){extern M2C_UNK gHttpRequestList;void func_0204b3cc(void);void HttpRequestFreeAll(void);s32 n;if(M2C_FIELD(&gHttpRequestList,s32 *,4)<=0)return 1;func_0204b3cc();n=M2C_FIELD(&gHttpRequestList,s32 *,4)-1;M2C_FIELD(&gHttpRequestList,s32 *,4)=n;if(n==0)HttpRequestFreeAll();return 1;}

s32 func_02044e68(void) {
    s32 HasNetError();
    M2C_UNK func_0204b674();
    if (HasNetError() != 0) {
        return 0;
    }
    func_0204b674();
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
void HttpProgressCallback(s32 unused,s32 a,s32 b,s32 c,s32 d,s32 e,void *p){
void (*cb)(s32,s32,s32,s32,s32,s32)=M2C_FIELD(p,void (**)(s32,s32,s32,s32,s32,s32),8);
if(!cb)return;cb(a,b,c,d,e,M2C_FIELD(p,s32 *,0));
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

void HttpGetStart(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_UNK HttpRequestStart(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    HttpRequestStart(arg0, arg1, arg2, 0, arg3, arg4, arg5);
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

void *HttpRequestAlloc(CallbackRecord *src){void *HeapAlloc(s32,s32);extern M2C_UNK gHttpRequestList;void *p=HeapAlloc(4,28);if(!p)return 0;*(CallbackRecord *)p=*src;M2C_FIELD(p,s32 *,24)=0;M2C_FIELD(p,s32 *,16)=0;if(!M2C_FIELD(&gHttpRequestList,void **,0)){M2C_FIELD(&gHttpRequestList,void **,0)=p;return p;}else{M2C_FIELD(p,void **,24)=M2C_FIELD(&gHttpRequestList,void **,0);M2C_FIELD(&gHttpRequestList,void **,0)=p;}return p;}

void HttpRequestFree(void *a) {
 extern M2C_UNK gHttpRequestList; void HeapFree(s32,s32,s32);
 void *p=M2C_FIELD(&gHttpRequestList,void **,0),*q,*n;
 if(!p)return;
 if(p==a){n=M2C_FIELD(p,void **,24);HeapFree(4,(s32)p,0);M2C_FIELD(&gHttpRequestList,void **,0)=n;return;}
 q=M2C_FIELD(p,void **,24);
 while(q) {
 if(q!=a)p=q;
 else {n=M2C_FIELD(p,void **,24);M2C_FIELD(p,void **,24)=M2C_FIELD(n,void **,24);HeapFree(4,(s32)n,0);return;}
 q=M2C_FIELD(q,void **,24);
 }
}

void HttpRequestFreeAll(void) {
 extern M2C_UNK gHttpRequestList;void HeapFree(s32,s32,s32);
 void *p=M2C_FIELD(&gHttpRequestList,void **,0),*q;
 while(p){q=p;p=M2C_FIELD(p,void **,24);if(M2C_FIELD(q,s32 *,16))HeapFree(4,M2C_FIELD(q,s32 *,16),0);HeapFree(4,(s32)q,0);}
 M2C_FIELD(&gHttpRequestList,void **,0)=0;
}

s32 func_020453e4(s32 *a) {
 s32 HasNetError();s32 *func_02047928(s32 *);extern s32 gWebTransaction;
 s32 x; s32 *p;
 if(HasNetError())return 1;
 if(gWebTransaction!=5)return 16;
 p=func_02047928(&x);if(!x)return 17;
 a[0]=x;a[1]=*p++;a[2]=(s32)p;return 0;
}

/* Validates a NAS web request: checks the network state and the request context,
 * copies the 20-byte key and the four request words out of the request string,
 * builds the stored request descriptor, records the context's source id, and
 * selects the GameSpy endpoint for the configured NAS server. Returns 0 on
 * success, otherwise a nonzero error code. */
s32 RegisterWebRequest(s32 requestStr, s32 context) {
    s32 HasNetError(void);
    s32 func_020323b0(void *);
    s32 func_020323f4(void *);
    u32 StringLength(void *);
    void *func_02068d18(void *, void *, s32);
    s32 func_0206abd8(void *, s32, s32);
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
    if (func_020323b0((void *)context) == 0 || func_020323f4((void *)context) == 0) {
        return 6;
    }
    if (StringLength((void *)requestStr) >= 0x54u) {
        return 4;
    }
    func_02068d18(key, (void *)requestStr, 0x14);
    key[0x14] = 0;
    param0 = func_0206abd8(func_02068d18(parseBuf, (void *)(requestStr + 0x14), 8), 0, 0x10);
    param1 = func_0206abd8(func_02068d18(parseBuf, (void *)(requestStr + 0x1c), 8), 0, 0x10);
    param2 = func_0206abd8(func_02068d18(parseBuf, (void *)(requestStr + 0x24), 8), 0, 0x10);
    param3 = func_0206abd8(func_02068d18(parseBuf, (void *)(requestStr + 0x2c), 8), 0, 0x10);
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

s32 func_02045620(void){void func_020478b8(void);extern s32 gWebTransaction;func_020478b8();return gWebTransaction=0;}

s32 func_0204563c(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4) {
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
    if (arg0 > 0x3e8u || arg4 > 0x2fcu) {
        return 2;
    }
    if (arg3 == 0 && arg4 != 0) {
        return 2;
    }
    r = BuildWebPutRequest((s32)arg0, M2C_FIELD(&gWebTransaction, s32 *, 4), arg1, arg2, arg3, (s32)arg4);
    if (r == 2) goto L8;
    if (r != 3) goto Ldata;
    goto L9;
L8:
    return 8;
L9:
    return 9;
Ldata:
    gWebTransaction = 2;
    return 0;
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

s32 func_02045934(s32 a, s32 b, u32 c, s32 d) {
    s32 HasNetError();
    s32 func_02047dd4(s32, u32, s32, s32);
    extern s32 gWebTransaction;
    if (HasNetError() != 0) return 1;
    if (gWebTransaction != 1 && gWebTransaction != 5) return 10;
    if (c > 1000) return 2;
    if (a < 0 || a >= 9) return 2;
    if (b < 0) return 2;
    {
        s32 r = func_02047dd4(a, c, b, d);
        switch (r) {
            case 3:
                return 11;
            case 2:
                return 12;
            default:
                gWebTransaction = 4;
                return 0;
        }
    }
}

s32 func_020459ec(void) {
    s32 HasNetError();
    s32 func_020477ac();
    extern s32 gWebTransaction;
    if (HasNetError()) return 1;
    if (gWebTransaction != 2 && gWebTransaction != 3 && gWebTransaction != 4) return 14;
    switch (func_020477ac()) {
        case 1:
            gWebTransaction = 6;
            break;
        case 0:
            gWebTransaction = 6;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        case 8:
            gWebTransaction = 5;
            break;
    }
    return 0;
}

s32 func_02045a88(void) {
    extern s32 gWebTransaction;
    return gWebTransaction;
}

s32 HasNetError(void);
s32 func_02045a98(s32 a, s32 b) {
    s32 buf[3];
    s32 *pVar1;
    s32 iVar2;
    s32 *pVar3;
    s32 uVar4;
    s32 *pVar5;
    
    if (HasNetError() != 0) {
        return 1;
    }
    if (func_020453e4(buf) != 0) {
        return 1;
    }
    iVar2 = buf[1];
    if ((u32)iVar2 < 8) {
        switch (iVar2) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return 15;
        case 1:
            break;
        }
    }
    if (a == 0) {
        return 2;
    }
    pVar3 = (s32 *)buf[2];
    if (pVar3 == NULL || a >= *pVar3) {
        return 2;
    }
    pVar5 = pVar3 + 2;
    if (b != 0) {
        do {
            uVar4 = pVar5[5];
            pVar5 = (s32 *)((char *)(pVar5 + 6) + uVar4);
            b--;
        } while (b != 0);
    }
    uVar4 = pVar5[5];
    pVar1 = (s32 *)((char *)(pVar5 + 6) + uVar4);
    pVar5 = (s32 *)buf[0];
    if ((char *)pVar1 - (char *)pVar5 > *(s32 *)((char *)pVar3 + (int)pVar5)) {
        return 2;
    }
    pVar1 = (s32 *)buf[5]; // placeholder to match remaining stores
    return 0;
}

s32 func_02045ba0(s32 *a) {
    s32 HasNetError();
    s32 func_020453e4(s32 *);
    s32 x[3], r;
    if (HasNetError()) return 1;
    r = func_020453e4(x); if (r) return r;
    if (!a) return 2;
    switch (x[1]) {
        case 0:
            return 15;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        default:
            *a = *(s32 *)x[2];
            return 0;
    }
}

s32 func_02045c34(s32 *a) {
 s32 HasNetError(); s32 func_020453e4(s32 *);
 s32 x[3],r;
 if(HasNetError())return 1;
 r=func_020453e4(x);if(r)return r;
 if(!a)return 2;
 *a=M2C_FIELD(x[2],s32 *,4);return 0;
}

s32 func_02045c90(M2C_UNK arg0) {
    s32 func_020465c4(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213db28;
    if (func_020465c4(M2C_FIELD(&data_0213db28, s32 *, 8), 0x300, arg0) != 0) {
        return 1;
    }
    return 0;
}

void GetWfcProfile(void *arg0) {
    void MI_CpuCopy8(void *, void *, u32);
    extern M2C_UNK data_0213db34;
    extern M2C_UNK data_0213db39;
    extern M2C_UNK data_0213db3e;
    extern M2C_UNK data_0213db40;
    u32 *p = (u32 *)arg0;
    u32 a, b, c, d, mask;

    MI_CpuCopy8(&data_0213db34, arg0, 6);
    mask = 0x7FF;
    a = p[0];
    d = mask - 0x800;
    b = p[1];
    c = a & d;
    p[0] = c;
    mask = b & mask;
    p[1] = mask;

    MI_CpuCopy8(&data_0213db39, (char *)arg0 + 8, 6);
    a = p[2];
    b = p[3];
    a = a >> 3;
    a = a | (b << 29);
    p[2] = a;
    d = b >> 3;
    p[3] = d;

    mask = 0x7FF;
    a = p[2];
    c = mask - 0x800;
    c = a & c;
    p[2] = c;
    mask = mask & d;
    p[3] = mask;

    MI_CpuCopy8(&data_0213db3e, (char *)arg0 + 0x10, 2);
    a = *(u16 *)((char *)arg0 + 0x10);
    d = 0x3FF;
    a = (s32)a >> 6;
    *(u16 *)((char *)arg0 + 0x10) = (u16)a;
    a = *(u16 *)((char *)arg0 + 0x10);
    d = a & d;
    *(u16 *)((char *)arg0 + 0x10) = (u16)d;

    MI_CpuCopy8(&data_0213db40, (char *)arg0 + 0x12, 2);
}

