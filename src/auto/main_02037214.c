/* 39 functions from 0x02037214 to 0x0203804C (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
static inline void seed371(u64 *seed) {
extern u64 data_0213d1e0[];
data_0213d1e0[0]=*seed;
data_0213d1e0[1]=0x5d588b656c078965ULL;
data_0213d1e0[2]=0x269ec3;
}
static inline u32 next371(void) {
extern u64 data_0213d1e0[];
data_0213d1e0[0]=data_0213d1e0[1]*data_0213d1e0[0]+data_0213d1e0[2];
return data_0213d1e0[0]>>32;
}

/* Returns the current state code, exposing its param through outParam and a derived type through outType. */
#pragma opt_propagation off
s32 Base64EncodeUrl(void *arg0,u32 arg1,s8 *arg2,u32 arg3){
 extern s8 *gBase64AlphabetUrl;
 void MI_CpuFill8(void *,s32,s32);
 void MI_CpuCopy8(void *,void *,u32);
 u32 extra,total;
 s32 count;
 u8 *src=arg0,*end;
 s8 *dst;
 s32 n,bits;
 u8 buf[3];
 s32 a,b,c;
 extra=arg1%3 ? 4:0;
 total=extra+(arg1/3)*4;
 if(!arg2)return total;
 if(arg3<total)return -1;
 end=src+arg1;
 dst=arg2;
 while(src!=end){
 n=end-src;
 bits=n*8;
 count=bits/6+(bits%6!=0);
 if(n>=3)n=3;
 MI_CpuFill8(buf,0,3);
 MI_CpuCopy8(src,buf,n);
 dst[0]=gBase64AlphabetUrl[buf[0]>>2];
 if(count<2)c=42;else {a=buf[0];b=buf[1];c=gBase64AlphabetUrl[((a<<4)&63)|(b>>4)];}dst[1]=c;
 if(count<3)c=42;else {a=buf[1];b=buf[2];c=gBase64AlphabetUrl[((a<<2)&63)|(b>>6)];}dst[2]=c;
 if(count<4)c=42;else {a=buf[2];c=gBase64AlphabetUrl[a&63];}
 src+=n;dst[3]=c;dst+=4;
 }
 return dst-arg2;
}
#pragma opt_propagation reset
/* Decode the base64 text `src` (len bytes, a multiple of four) into bytes at
 * dest (at most maxDest of them).  The text uses the URL-safe alphabet, with '.'
 * as value 62 and '-' as 63, and '*' as a filler that stands for no bits; a
 * filler is skipped when sizing the output, which is the number of six-bit groups
 * divided by eight and, when dest is NULL, is all this returns.  Returns the
 * number of bytes written. */
s32 DecodeBase64Url(char *src, u32 len, char *dest, u32 maxDest) {
    s32 bitCount;
    s32 required;
    u32 i;
    char *value;
    s32 j;
    char vals[4];
    char *out;
    s32 written;

    if (len & 3u) {
        return -1;
    }
    bitCount = 0;
    for (i = 0u; i < len; i++) {
        if ((s8)src[i] != '*') {
            bitCount += 6;
        }
    }
    required = bitCount / 8;
    if (dest == (char *)0) {
        return required;
    }
    if (maxDest < (u32)required) {
        return -1;
    }
    if (len == 0u) {
        dest[0] = 0;
        return 0;
    }
    out = dest;
    do {
        j = 0;
        value = vals;
        do {
            s8 c = src[j];
            if (c >= 'A' && c <= 'Z') {
                *value = c - 'A';
            } else if (c >= 'a' && c <= 'z') {
                *value = c - 'a' + 26;
            } else if (c >= '0' && c <= '9') {
                *value = c - '0' + 52;
            } else if (c == '.') {
                *value = 62;
            } else if (c == '-') {
                *value = 63;
            } else {
                *value = 0;
            }
            j++;
            value++;
        } while (j < 4);
        out[0] = (vals[0] << 2) | (vals[1] >> 4);
        src += 4;
        written = out + 1 - dest;
        if (written >= required) {
            break;
        }
        out[1] = (vals[1] << 4) | (vals[2] >> 2);
        written = out + 2 - dest;
        if (written >= required) {
            break;
        }
        out[2] = (vals[2] << 6) | vals[3];
        out += 3;
        written = out - dest;
    } while (written < required);
    return written;
}

s32 GetNetError(s32 *outParam, s32 *outType) {
    extern M2C_UNK gNetError;
    if (outParam != (s32 *)0) {
        *outParam = M2C_FIELD(&gNetError, s32 *, 4);
    }
    if (outType != (s32 *)0) {
        switch (M2C_FIELD(&gNetError, s32 *, 0)) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 8:
            *outType = 6;
            break;
        case 6:
            *outType = 3;
            break;
        case 7:
            *outType = 4;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            *outType = 1;
            break;
        case 1:
        case 9:
            *outType = 7;
            break;
        case 14:
            *outType = 5;
            break;
        case 15:
        case 17:
        case 19:
            *outType = 6;
            break;
        case 16:
        case 18:
            *outType = 2;
            break;
        default:
            *outType = 0;
            break;
        }
    }
    return M2C_FIELD(&gNetError, s32 *, 0);
}

void ClearNetError(void) {
    extern M2C_UNK gNetError;
    if (M2C_FIELD(&gNetError, s32 *, 0) != 9) {
        M2C_FIELD(&gNetError, s32 *, 0) = 0;
        M2C_FIELD(&gNetError, s32 *, 4) = 0;
    }
}

s32 HasNetError(void) {
    extern s32 gNetError;
    if (gNetError != 0) {
        return 1;
    }
    return 0;
}

void SetNetError(s32 arg0, s32 arg1) {
    extern M2C_UNK gNetError;
    if (M2C_FIELD(&gNetError, s32 *, 0) != 9) {
        M2C_FIELD(&gNetError, s32 *, 0) = arg0;
        M2C_FIELD(&gNetError, s32 *, 4) = arg1;
    }
}

s32 GetHeapBlockHeader(s32 arg0) {
    return arg0 - 0x20;
}

void *InitHeapBlock(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0x4457434D;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return arg0 + 0x20;
}

s32 GetHeapBlockSize(s32 arg0) {
    s32 *p;
    s32 dummy;
    p = (s32 *)GetHeapBlockHeader(arg0);
    (void)dummy;
    return p[1];
}

void func_02037680(s32 arg0, s32 arg1) {
    extern M2C_UNK gHeapCallbacks;
    M2C_FIELD(&gHeapCallbacks, s32 *, 4) = arg0;
    M2C_FIELD(&gHeapCallbacks, s32 *, 0) = arg1;
}

void HeapAlloc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK HeapAllocAligned(M2C_UNK, M2C_UNK, M2C_UNK);
    HeapAllocAligned(arg0, arg1, 0x20);
}

M2C_UNK HeapAllocAligned(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    extern M2C_UNK gHeapCallbacks;
    void *temp_r0;
    temp_r0 = M2C_FIELD(&gHeapCallbacks, void *(**)(M2C_UNK, s32, M2C_UNK), 4)(arg0, arg1 + 0x20, arg2);
    if (temp_r0 == NULL) {
        return 0;
    }
    return (s32)InitHeapBlock(temp_r0, arg1);
}

void HeapFree(M2C_UNK a, M2C_UNK b, M2C_UNK c) {
    extern M2C_UNK gHeapCallbacks;
    if (b == 0) {
        return;
    }
    M2C_FIELD(&gHeapCallbacks, void (**)(s32, s32, s32), 0)(
        a, GetHeapBlockHeader(b), c);
}

M2C_UNK func_02037714(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK HeapReallocAligned(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 dummy = 0;
    (void)dummy;
    return HeapReallocAligned(arg0, arg1, arg2, arg3, 0x20);
}

/* Reallocate a heap block: allocate a new aligned block of size bytes, copy the old
 * block's contents up to the smaller of the two sizes, free the old block and
 * return the new one, or 0 when the allocation failed. */
M2C_UNK HeapReallocAligned(M2C_UNK heap, M2C_UNK block, M2C_UNK oldSize, M2C_UNK size, s32 align) {
    void MI_CpuCopy8(void *, void *, u32);
    s32 newBlock;

    newBlock = HeapAllocAligned(heap, size, align);
    if (!newBlock) return 0;
    if (block) {
        oldSize = GetHeapBlockSize(block);
        if ((u32)oldSize <= (u32)size) size = oldSize;
        MI_CpuCopy8(block, newBlock, size);
        HeapFree(heap, block, oldSize);
    }
    return newBlock;
}

void gpiMalloc(M2C_UNK arg0) {
    HeapAlloc(5, arg0);
}

void gpiRealloc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02037714(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02037714(5, arg0, arg1, arg1);
}

void gpiFree(M2C_UNK arg0) {
    void HeapFree(M2C_UNK, M2C_UNK, M2C_UNK);
    HeapFree(5, arg0, 0);
}

M2C_UNK func_020377dc(M2C_UNK a,M2C_UNK b,M2C_UNK unused,M2C_UNK d){
 extern void *gWfcConnection;
 void func_02037854(s32);
 void MI_CpuFill8(void *,s32,s32);void func_020220a8(s32);
 if(gWfcConnection)return;
 MI_CpuFill8(a,0,12);
 M2C_FIELD(a,u16 *,8)=b;M2C_FIELD(a,u16 *,10)=1;M2C_FIELD(a,u16 *,4)=1;M2C_FIELD(a,u16 *,6)=0;
 gWfcConnection=(void *)a;func_02037854(0);func_020220a8(d);
}

void func_0203783c(M2C_UNK arg0) {
    M2C_UNK func_020377dc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020377dc(arg0, 3, 1, 0x14);
}

void func_02037854(s32 arg0) {
    M2C_UNK func_0203289c(M2C_UNK *);
    extern M2C_UNK data_020fc818;
    extern M2C_UNK data_020fc840;
    extern M2C_UNK data_020fc864;
    switch (arg0) {                                 /* irregular */
    case 0:
        func_0203289c(&data_020fc818);
        return;
    case 1:
        func_0203289c(&data_020fc840);
        return;
    case 2:
        func_0203289c(&data_020fc864);
        return;
    }
}

/* Start the WFC library on the connection created by func_020377dc: build the
 * WFC_Init parameters from the connection's mode and sub-mode, hand the library
 * the game's work-block allocators and move the connection to RUNNING. A
 * failed WFC_Init is reported as network error -6; starting without a
 * connection object reports -4. */
void Wfc_StartConnection(void) {
    extern void *gWfcConnection;
    void MI_CpuFill8(void *, s32, s32);
    s32 WFC_Init(void *);
    void SetNetError(s32, s32);
    WfcInitParams params;

    if (gWfcConnection) {
        if (M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) != WFC_CONN_IDLE) return;
        MI_CpuFill8(&params, 0, sizeof(params));
        params.mode = M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_MODE);
        params.submode = M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_SUBMODE);
        params.allocate = (void *(*)(s32, s32))HeapAlloc;
        params.freeBlock = (void (*)(s32, void *, s32))HeapFree;
        M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) = WFC_CONN_RUNNING;
        if (!WFC_Init(&params)) {
            SetNetError(9, -6);
        }
    } else {
        SetNetError(9, -4);
    }
}

s32 func_02037954(void) {
    extern void *gWfcConnection;
    s32 GetNetConnectionStatus(void);
    s32 dummy = 0;
    (void)dummy;
    if (!gWfcConnection) {
        return 0;
    }
    if (!M2C_FIELD(gWfcConnection, s32 *, 0)) {
        return 0;
    }
    M2C_FIELD(gWfcConnection, u16 *, 4) = 3;
    GetNetConnectionStatus();
    return 1;
}

/* Drive the library while connecting and mark the connection ready once linking ends. */
void Wfc_UpdateConnection(void) {
    extern void *gWfcConnection;
    s32 Wfc_ProcessStep(void);
    s32 Wfc_GetLinkState(void);
    s32 dummy = 0;
    (void)dummy;

    if (!gWfcConnection) return;
    if (M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) == WFC_CONN_RUNNING) {
        M2C_FIELD(gWfcConnection, s32 *, WFC_CONN_STEP) = Wfc_ProcessStep();
        return;
    }
    if (M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) == WFC_CONN_CONNECTED
        && M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_LINK_READY) != 0) {
        if (Wfc_GetLinkState() != WFC_SESSION_STATE_LINKING) {
            M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_LINK_READY) = 0;
            M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) = WFC_CONN_READY;
        }
    }
}

/* Poll the WFC connection and advance its state: leave an idle connection
 * alone, then record the link as connecting, connected or ready, or record a
 * failed/fatal WFC error in the global network error record and stop. */
s32 GetNetConnectionStatus(void) {
    extern void *gWfcConnection;
    s32 GetWfcSessionProgress(void);
    void SetNetError(s32, s32);
    s32 state;
    s32 dummy = 0;
    (void)dummy;
    if (!gWfcConnection) return 0;
    state = M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE);
    if (state == WFC_CONN_IDLE) return state;
    state = GetWfcSessionProgress();
    if (state == 5) {
        M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) = WFC_CONN_CONNECTED;
        M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_LINK_READY) = 1;
        return WFC_CONN_CONNECTED;
    }
    if (state < 0) {
        if (state >= -10) {
            SetNetError(9, state - 700);
            M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) = WFC_CONN_FATAL;
            return WFC_CONN_FATAL;
        }
        SetNetError(5, state);
        M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) = WFC_CONN_FAILED;
        return WFC_CONN_FAILED;
    }
    return WFC_CONN_RUNNING;
}

void func_02037abc(void) {
extern void *gWfcConnection;s32 Wfc_EndSession(void);void SleepMilliseconds(s32);
if(!gWfcConnection)return;
if(M2C_FIELD(gWfcConnection,u16 *,4)==1){gWfcConnection=0;return;}
while(!Wfc_EndSession())SleepMilliseconds(10);
gWfcConnection=0;
}

/* Poll the shutdown of the WFC session: a connection that never started is
 * dropped at once, a fatally failed one keeps its object for the error report,
 * and any other is marked as closing while its session is ended.  Returns 1 once
 * the connection object has been dropped. */
s32 Wfc_PollSessionEnd(void) {
    extern void *gWfcConnection;
    s32 Wfc_EndSession(void);
    s32 dummy = 0;
    (void)dummy;
    if (!gWfcConnection) return 1;
    if (M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) == WFC_CONN_FATAL) return 0;
    if (M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) == WFC_CONN_IDLE) {
        gWfcConnection = 0;
        return 1;
    }
    M2C_FIELD(gWfcConnection, u16 *, WFC_CONN_STATE) = WFC_CONN_CLOSING;
    if (!Wfc_EndSession()) return 0;
    gWfcConnection = 0;
    return 1;
}

s32 func_02037b8c(void) {
    extern void *gWfcConnection;
    if ((gWfcConnection != NULL) && (M2C_FIELD(gWfcConnection, u16 *, 4) == 6)) {
        return 1;
    }
    return 0;
}

void func_02037bb8(void) {
    M2C_UNK func_02029ad8();
    func_02029ad8();
}

s32 func_02037bc4(void) {
    u32 GetWfcFriendSlot(void);
    void Wfc_UpdateConnection(void);
    void func_02037abc(void);
    void SetNetError(s32, s32);
    s32 func_02037b8c(void);
    u32 var_r2;
    s32 dummy;
    (void)dummy;

    Wfc_UpdateConnection();
    if (func_02037b8c() != 0) {
        var_r2 = GetWfcFriendSlot();
        if (var_r2 > 0x63U) {
            var_r2 = 0x63;
        }
        SetNetError(8, 0xFFFF2D10 - var_r2);
        func_02037abc();
        return 1;
    }
    return 0;
}

void func_02037c10(void) {
    M2C_UNK OpenWfcHttpConnection();
    OpenWfcHttpConnection();
}

/* Poll the WFC matchmaking HTTP connection: report RUNNING while it is still
 * opening or reading, DONE once the server has answered, NONE when there is no
 * connection, and FAILED (recording network error 8 as 0xffff2cac minus the
 * connecting friend slot) when it fails. */
s32 PollWfcMatchmakingHttp(void) {
    u32 UpdateWfcHttpConnection(void);
    u32 GetWfcFriendSlot(void);
    void SetNetError(s32, s32);
    u32 friendSlot;
    s32 dummy;
    (void)dummy;

    switch (UpdateWfcHttpConnection()) {
    case WFC_HTTP_RESULT_PENDING: return WFC_HTTP_STEP_RUNNING;
    case WFC_HTTP_RESULT_OK: return WFC_HTTP_STEP_DONE;
    case WFC_HTTP_RESULT_ERROR:
    case WFC_HTTP_RESULT_CONNECT:
        friendSlot = GetWfcFriendSlot();
        if (friendSlot > 99) {
            friendSlot = 99;
        }
        SetNetError(8, 0xffff2cac - friendSlot);
        return WFC_HTTP_STEP_FAILED;
    case WFC_HTTP_RESULT_NONE: return WFC_HTTP_STEP_NONE;
    default: return WFC_HTTP_STEP_FAILED;
    }
}

s32 GetLastNasError(void) {
    extern s32 gNasConnection;
    return gNasConnection;
}

/* Fills `date` (year, month, day, ...) and `time` (hour, minute, second) with the
 * server clock, corrected for the local clock's offset.  Returns 0 when the server
 * time is unknown or is more than one RTC century away from the local clock. */
s32 GetServerTime(s32 *date, s32 *time) {
    extern s32 gServerTimeSync;
    extern s64 gServerTimeNow, gServerTimeOffset;
    s32 GetLocalTime(void *, void *);
    s64 MakeTime(void *, void *);
    void RtcSecondsToDateTime(void *, s32 *, s64);
    s64 serverTime, elapsed;
    if (!gServerTimeSync) return 0;
    if (GetLocalTime(date, time)) return 0;
    serverTime = MakeTime(date, time);
    if (serverTime == -1) return 0;
    /* A date before the local clock means the RTC wrapped into the next century. */
    if (serverTime < gServerTimeNow) serverTime += SERVER_TIME_SPAN_SECONDS;
    elapsed = serverTime - gServerTimeOffset;
    if (elapsed < 0 || elapsed > SERVER_TIME_SPAN_LAST) return 0;
    RtcSecondsToDateTime((void *)date, time, elapsed);
    return 1;
}

M2C_UNK FormatKeyValue(s32 a,s32 b,s32 c,s32 d){
 M2C_UNK StringFormatN(s32,s32,void *,...);M2C_UNK StringLength(s32);extern M2C_UNK data_020fc884;
 StringFormatN(c,0x1000,&data_020fc884,d,a,d,b);StringLength(c);
}

void AppendKeyValue(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK FormatKeyValue(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK StringLength(M2C_UNK);
    s32 StringFindChar(M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 dummy = 0;
    (void)dummy;
    temp_r0 = StringFindChar(arg2, 0);
    FormatKeyValue(arg0, arg1, temp_r0, arg3);
    StringLength(arg2);
}

/* Extract the value of "key=value" from a string made of separator-delimited
 * tokens: find the token that starts with key and equals it (up to the
 * separator), copy the text between the next two separators into out
 * (NUL-terminated) and return its length, or -1 when the key is not there. */
s32 ExtractKeyValue(s8 *key, s8 *out, s8 *text, s32 separator) {
    s8 *p;
    s8 *q;
    s32 len;

    if (!out) return -1;
    p = StringFindChar(text, separator);
    if (!p) return -1;
    for (;;) {
        len = StringLength(key);
        if (StringCompareN((u8 *)(p + 1), (u8 *)key, len) != 0) goto next;
        len = StringLength(key);
        if (separator == *(s8 *)(len + (s32)p + 1)) goto extract;
    next:
        q = StringFindChar(p + 1, separator);
        if (!q) return -1;
        p = StringFindChar(q + 1, separator);
        if (!p) return -1;
    }
extract:
    p = StringFindChar(p + 1, separator);
    if (!p) return -1;
    q = StringFindChar(p + 1, separator);
    if (q) len = q - (p + 1); else len = StringLength(p + 1);
    StringCopyPad(out, p + 1, len);
    out[len] = 0;
    return len;
}

u32 RandomBelow(u32 max) {
extern u64 data_0213d1e0[];
void *memcpy(void *, const void *, unsigned int);
void GetMacAddress(void *); u64 GetSystemTick(void);
u64 seed,v;
if(data_0213d1e0[0]==0&&data_0213d1e0[1]==0&&data_0213d1e0[2]==0){
GetMacAddress(&seed);
seed=((seed>>24)&0xffffffULL)|(GetSystemTick()<<24);
memcpy(data_0213d1e0, &seed, sizeof(seed));
data_0213d1e0[1]=0x5d588b656c078965ULL;
data_0213d1e0[2]=0x269ec3;
}
data_0213d1e0[0]=data_0213d1e0[1]*data_0213d1e0[0]+data_0213d1e0[2];
if(max==0)return data_0213d1e0[0]>>32;
v=data_0213d1e0[0]>>32;
return (v*(u64)max)>>32;
}

s32 Utf16StringLength(u16 *a){s32 i=0;if(*a){do{i++;}while(a[i]);}return i;}

