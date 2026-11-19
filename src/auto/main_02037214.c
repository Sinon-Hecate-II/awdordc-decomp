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
s32 func_0203739c(char *src, u32 len, char *dest, u32 maxDest) {
    u32 i;
    s32 required;
    u32 j;
    char vals[4];
    char *out;
    u32 written;

    if (len & 3u) {
        return -1;
    }
    required = 0;
    for (i = 0u; i < len; i++) {
        if ((s8)src[i] != (s8)0x2a) {
            required = required + 6;
        }
    }
    required = required / 8;
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
    written = 0u;
    while (written < (u32)required) {
        for (j = 0u; j < 4u; j++) {
            s8 c;
            s8 v;
            c = (s8)src[j];
            if (c >= (s8)0x41 && c <= (s8)0x5a) {
                v = (s8)(c - (s8)0x41);
            } else if (c >= (s8)0x61 && c <= (s8)0x7a) {
                v = (s8)(c - (s8)0x47);
            } else if (c >= (s8)0x30 && c <= (s8)0x39) {
                v = (s8)(c + (s8)0x4);
            } else if (c == (s8)0x2e) {
                v = (s8)0x3e;
            } else if (c == (s8)0x2d) {
                v = (s8)0x3f;
            } else {
                v = (s8)0;
            }
            vals[j] = (char)v;
        }
        src = src + 4;
        out[0] = (char)(((s8)vals[0] << 2) | ((s8)vals[1] >> 4));
        written = (u32)(out + 1 - dest);
        if (written >= (u32)required) {
            break;
        }
        out[1] = (char)(((s8)vals[1] << 4) | ((s8)vals[2] >> 2));
        written = (u32)(out + 2 - dest);
        if (written >= (u32)required) {
            break;
        }
        out[2] = (char)(((s8)vals[2] << 6) | ((s8)vals[3]));
        out = out + 3;
        written = (u32)(out - dest);
    }
    return (s32)written;
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

s32 func_02037650(s32 arg0) {
    return arg0 - 0x20;
}

void *func_02037658(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0x4457434D;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return arg0 + 0x20;
}

s32 func_02037670(s32 arg0) {
    s32 *p;
    s32 dummy;
    p = (s32 *)func_02037650(arg0);
    (void)dummy;
    return p[1];
}

void func_02037680(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213d1d4;
    M2C_FIELD(&data_0213d1d4, s32 *, 4) = arg0;
    M2C_FIELD(&data_0213d1d4, s32 *, 0) = arg1;
}

void HeapAlloc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020376a4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020376a4(arg0, arg1, 0x20);
}

M2C_UNK func_020376a4(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    extern M2C_UNK data_0213d1d4;
    void *temp_r0;
    temp_r0 = M2C_FIELD(&data_0213d1d4, void *(**)(M2C_UNK, s32, M2C_UNK), 4)(arg0, arg1 + 0x20, arg2);
    if (temp_r0 == NULL) {
        return 0;
    }
    return (s32)func_02037658(temp_r0, arg1);
}

void HeapFree(M2C_UNK a, M2C_UNK b, M2C_UNK c) {
    extern M2C_UNK data_0213d1d4;
    if (b == 0) {
        return;
    }
    M2C_FIELD(&data_0213d1d4, void (**)(s32, s32, s32), 0)(
        a, func_02037650(b), c);
}

M2C_UNK func_02037714(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02037728(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 dummy = 0;
    (void)dummy;
    return func_02037728(arg0, arg1, arg2, arg3, 0x20);
}

M2C_UNK func_02037728(M2C_UNK a,M2C_UNK b,M2C_UNK unused,M2C_UNK size,s32 align){
void MI_CpuCopy8(void *,void *,u32);
s32 p; u32 n;
p=func_020376a4(a,size,align);
if(!p)return 0;
if(b){
unused=func_02037670(b);
if((u32)unused<=(u32)size)size=unused;
MI_CpuCopy8(b,p,size);
HeapFree(a,b,unused);
}
return p;
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

void func_02037994(void) {
    extern void *gWfcConnection;
    s32 Wfc_ProcessStep(void);
    s32 Wfc_GetLinkState(void);
    s32 dummy = 0;
    (void)dummy;
    if (!gWfcConnection) return;
    if (M2C_FIELD(gWfcConnection, u16 *, 4) == 2) {
        M2C_FIELD(gWfcConnection, s32 *, 0) = Wfc_ProcessStep();
        return;
    }
    if (M2C_FIELD(gWfcConnection, u16 *, 4) == 4 && M2C_FIELD(gWfcConnection, u16 *, 6) != 0) {
        if (Wfc_GetLinkState() != 9) {
            M2C_FIELD(gWfcConnection, u16 *, 6) = 0;
            M2C_FIELD(gWfcConnection, u16 *, 4) = 6;
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

s32 func_02037b1c(void) {
    extern void *gWfcConnection;
    s32 Wfc_EndSession(void);
    s32 dummy = 0;
    (void)dummy;
    if (!gWfcConnection) return 1;
    if (M2C_FIELD(gWfcConnection, u16 *, 4) == 8) return 0;
    if (M2C_FIELD(gWfcConnection, u16 *, 4) == 1) {
        gWfcConnection = 0;
        return 1;
    }
    M2C_FIELD(gWfcConnection, u16 *, 4) = 5;
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
    u32 func_0202f248(void);
    void func_02037994(void);
    void func_02037abc(void);
    void SetNetError(s32, s32);
    s32 func_02037b8c(void);
    u32 var_r2;
    s32 dummy;
    (void)dummy;

    func_02037994();
    if (func_02037b8c() != 0) {
        var_r2 = func_0202f248();
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

s32 func_02037c1c(void) {
    u32 UpdateWfcHttpConnection(void);
    u32 func_0202f248(void);
    void SetNetError(s32, s32);
    u32 n;
    s32 dummy;
    (void)dummy;

    switch (UpdateWfcHttpConnection()) {
    case 0: return 1;
    case 1: return 2;
    case 2:
    case 3:
        n = func_0202f248();
        if (n > 99) {
            n = 99;
        }
        SetNetError(8, 0xffff2cac - n);
        return 3;
    case 4: return 0;
    default: return 3;
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
void GetMacAddress(void *); u64 GetSystemTick(void);
u64 seed,v;
if(data_0213d1e0[0]==0&&data_0213d1e0[1]==0&&data_0213d1e0[2]==0){
GetMacAddress(&seed);
seed=((seed>>24)&0xffffffULL)|(GetSystemTick()<<24);
data_0213d1e0[0]=seed;
data_0213d1e0[1]=0x5d588b656c078965ULL;
data_0213d1e0[2]=0x269ec3;
}
data_0213d1e0[0]=data_0213d1e0[1]*data_0213d1e0[0]+data_0213d1e0[2];
v=data_0213d1e0[0]>>32;
if(max==0)return v;
return (v*max)>>32;
}

s32 Utf16StringLength(u16 *a){s32 i=0;if(*a){do{i++;}while(a[i]);}return i;}

