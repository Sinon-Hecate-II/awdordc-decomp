/* 41 functions from 0x02225F60 to 0x02226D9C (ov010), found by ds-decomp. */
#include "common.h"
#define ONLINE_USE_INTERRUPT_GUARD
#include "online_link.h"
typedef struct Ov010MemberCall { s32 function; s32 adjustment; } Ov010MemberCall;
static inline void ov010CallMember(void *object, Ov010MemberCall *call) {
s32 adj=call->adjustment;
void *self=(u8 *)object+(adj>>1);
s32 fn;
fn=(adj&1)?*(s32 *)(*(u8 **)self+call->function):call->function;
((void (*)(void *))fn)(self);
}
static inline void ov010CallArray(u8 *first,s32 size,Ov010MemberCall call) {
Ov010MemberCall copy;
u8 *last=first+size;
copy.function=call.function;copy.adjustment=call.adjustment;
while(first!=last) { ov010CallMember(first,&copy); first+=12; }
}

/* Initializes/starts the overlay 010 subsystem: allocates its working buffers, sets callbacks and enables it. */
s32 func_ov010_02225f60(void) {
    extern M2C_UNK gVoiceChatLink, data_ov010_0222ee98, data_ov010_0222ee78;
    void VoiceLink_HandleEvent();
    void func_ov010_02225f54();
    s32 GetOnlineTransportPlayerId();
    s32 func_ov010_02225cd8(s32);
    s32 func_ov010_02225640(void *);
    void func_ov010_02228b50();
    void func_ov010_02222c9c();
    void func_ov010_02225d00();
    void DisableVoiceStream();
    s32 func_ov010_02229bf4();
    void func_ov010_02222c28();
    s32 AllocAlignedBuffer(s32, s32);

    if (M2C_FIELD(&gVoiceChatLink, s32 *, 0) != 0) {
        return 1;
    }
    M2C_FIELD(&gVoiceChatLink, s32 *, 0) = AllocAlignedBuffer(0x6b40, 32);
    M2C_FIELD(&gVoiceChatLink, s32 *, 16) = 1;
    M2C_FIELD(&gVoiceChatLink, void **, 8) = &data_ov010_0222ee98;
    M2C_FIELD(&gVoiceChatLink, s32 *, 12) = 2;
    M2C_FIELD(&gVoiceChatLink, u8 *, 20) = (u8)GetOnlineTransportPlayerId();
    M2C_FIELD(&gVoiceChatLink, void **, 32) = VoiceLink_HandleEvent;
    M2C_FIELD(&gVoiceChatLink, s32 *, 36) = 0;
    M2C_FIELD(&gVoiceChatLink, s32 *, 24) = M2C_FIELD(&gVoiceChatLink, s32 *, 0);
    M2C_FIELD(&gVoiceChatLink, s32 *, 28) = 0x6b40;
    if (!func_ov010_02225cd8(0x6b40)) {
        return 0;
    }
    if (!func_ov010_02225640(&data_ov010_0222ee78)) {
        return 0;
    }
    func_ov010_02228b50(func_ov010_02225f54);
    func_ov010_02222c9c(1);
    M2C_FIELD(&gVoiceChatLink, s32 *, 4) = 0;
    func_ov010_02225d00();
    DisableVoiceStream();
    if (func_ov010_02229bf4()) {
        func_ov010_02226060(0);
    }
    func_ov010_02222c28(1);
    return 1;
}

void TickVoiceStream(void) {
    M2C_UNK func_ov010_022257a0();
    func_ov010_022257a0();
}

s32 func_ov010_02226060(s32 arg0) {
    s32 func_ov010_02223ec8(s32);
    void VoiceLink_ReleaseContext(s32);
    s32 func_ov010_0222405c(s32, s32);
    extern M2C_UNK gVoiceChatLink;
    s32 temp_r4;
    if (M2C_FIELD(&gVoiceChatLink, s32 *, 4) == 0) {
        temp_r4 = func_ov010_02223ec8(arg0);
        if (temp_r4 == 0) return 0;
        if (func_ov010_0222405c(temp_r4, 0) != 0) {
            VoiceLink_ReleaseContext(temp_r4);
            return 0;
        }
        M2C_FIELD(&gVoiceChatLink, s32 *, 4) = temp_r4;
    }
    return 1;
}

void func_ov010_022260b8(void) {
    void func_ov010_02225d38();
    void func_ov010_02225db8();
    void func_ov010_02228b50(s32);
    void func_ov010_02225778();
    void FreeBuffer();
    extern M2C_UNK gVoiceChatLink;
    func_ov010_02225d38();
    func_ov010_02225db8();
    func_ov010_02228b50(0);
    func_ov010_02225778();
    FreeBuffer(M2C_FIELD(&gVoiceChatLink, s32 *, 0), M2C_FIELD(&gVoiceChatLink, s32 *, 0x1C));
    M2C_FIELD(&gVoiceChatLink, s32 *, 0) = 0;
}

s32 AllocAlignedBuffer() {
    M2C_UNK func_020e3580();
    func_020e3580();
}

void FreeBuffer(s32 arg0) {
    M2C_UNK HeapFreeBlock();
    if (arg0 == 0) {
        return;
    }
    HeapFreeBlock();
}

M2C_UNK SetWebRequestError(M2C_UNK arg0) {
    s32 GetWebRequestError(void);
    extern s32 gWebRequestError;
    GetWebRequestError();
    gWebRequestError = arg0;
}

void func_ov010_02226130(void) {
    M2C_UNK PollWebTransaction();
    PollWebTransaction();
}

/* Submit the NAS player-registration request for the local profile, create the
 * waiting indicator sprite of sOv010RegisterSpriteClass and mark online step 5.
 * Returns 1 once the request is under way (or was already submitted), 0 when it
 * failed; the status codes other than 0 and 3 are recorded as the web error. */
s32 SubmitWebRegisterRequest(void) {
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    void ClearWebRequestError(void);
    u8 *func_020c4acc();
    s32 RegisterWebRequest(M2C_UNK *, u8 *);
    M2C_UNK SetWebRequestError(M2C_UNK);
    M2C_UNK **CreateSpriteFromClass(M2C_UNK *, s32);
    void SetOnlineSessionFlag(M2C_UNK);
    extern M2C_UNK sOv010NasRegisterRequest;
    extern M2C_UNK sOv010RegisterSpriteClass;
    extern M2C_UNK sOv010RegisterSpriteVtable;
    s32 success;
    u32 status;
    M2C_UNK **slot;

    success = 1;
    if (IsOnlineSessionFlagSet(5) != 0) return 1;
    ClearWebRequestError();
    status = RegisterWebRequest(&sOv010NasRegisterRequest, func_020c4acc() + 4);
    switch (status) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        success = 0;
        break;
    case 5:
        success = 0;
        break;
    case 6:
        success = 0;
        break;
    }
    if ((status != 0) && (status != 3)) {
        SetWebRequestError(status);
    } else {
        slot = CreateSpriteFromClass(&sOv010RegisterSpriteClass, 3);
        if (slot != NULL) {
            *slot = &sOv010RegisterSpriteVtable;
        }
        SetOnlineSessionFlag(5);
    }
    return success;
}

s32 GetWebRequestError(void) {
    extern s32 gWebRequestError;
    return gWebRequestError;
}

void ClearWebRequestError(void) {
    M2C_UNK SetWebRequestError(M2C_UNK);
    SetWebRequestError(0);
}

/* Refresh the clock from the server, then send a put.asp request with the given
 * fields and record its error: returns 0 when the request failed (statuses 1, 2,
 * 7, 8 and 9), 1 once it is on its way. */
s32 SubmitWebPutRequest(s32 playerId, s32 field2, s32 field3, s32 payload, s32 payloadSize) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c18();
    u32 SendWebPutRequest(s32, s32, s32, s32, s32);
    M2C_UNK date[4];
    M2C_UNK time[3];
    s32 result;
    u32 status;

    result = 1;
    if (GetServerTime(date, time) != 0) {
        GetElapsedSeconds(func_02085c18(), date, time);
    }
    status = SendWebPutRequest(playerId, field2, field3, payload, payloadSize);
    switch (status) {
    default: break;
    case 1: result = 0; break;
    case 7: result = 0; break;
    case 2: result = 0; break;
    case 8: result = 0; break;
    case 9: result = 0; break;
    }
    if (status != 0) {
        SetWebRequestError(status);
    }
    return result;
}

s32 func_ov010_022262e0(void) {
    M2C_UNK func_02085c04();
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 1;
    temp_r0 = func_02045a88();
    switch (temp_r0) {
    default:
        break;
    case 5:
        func_02085c04();
        var_r4 = 0;
        break;
    case 6:
        var_r4 = 0;
        break;
    case 0:
    case 1:
    case 3:
    case 4:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

s32 func_ov010_02226334(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, void *arg5) {
    s32 CreateSpriteObject(M2C_UNK *, s32);
    s32 SubmitWebPutRequest(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern M2C_UNK data_ov010_0222c080;
    if (SubmitWebPutRequest(arg0, arg1, arg2, arg3, arg4) == 0) {
        return 0;
    }
    return CreateSpriteObject(&data_ov010_0222c080, arg5);
}

s32 func_ov010_02226364(void) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c18();
    M2C_UNK date[4];
    M2C_UNK time[3];
    s64 temp;
    s32 res;

    if (GetServerTime(date, time) == 0) {
        temp = 0;
    } else {
        temp = GetElapsedSeconds(func_02085c18(), date, time);
    }
    res = 0;
    if (temp >= 0x3C) {
        res = 1;
    }
    return res;
}

/* Fills the request payload's kind marker for `kind`, submits it as a web GET
 * request, and records any error status. Returns 0 when the kind is unknown. */
s32 SendWebGetForKind(u32 kind,s32 playerId,s32 field2,s32 *payload){
s32 GetServerTime(M2C_UNK *,M2C_UNK *);s64 GetElapsedSeconds(s32,M2C_UNK *,M2C_UNK *);s32 func_02085c3c(void);u32 SendWebGetRequest(u32,s32,s32,s32 *);
M2C_UNK date[4];M2C_UNK time[3];s32 ok;u32 status;
ok=1;
if(GetServerTime(date,time)!=0)GetElapsedSeconds(func_02085c3c(),date,time);
switch(kind){case 0:*payload=8;break;case 1:*payload=12;break;case 2:case 4:case 5:*payload=12;break;case 3:*payload=0x10c;break;case 6:*payload=16;break;default:return 0;}
status=SendWebGetRequest(kind,playerId,field2,payload);
switch(status){default:break;case 1:ok=0;break;case 7:ok=0;break;case 2:ok=0;break;case 8:ok=0;break;case 9:ok=0;break;}
if(status!=0)SetWebRequestError(status);
return ok;
}

s32 func_ov010_022264e4(void) {
    M2C_UNK func_02085c28();
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 1;
    temp_r0 = func_02045a88();
    switch (temp_r0) {
    default:
        break;
    case 5:
        func_02085c28();
        var_r4 = 0;
        break;
    case 6:
        var_r4 = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 4:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

s32 SubmitWebGetRequest(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 CreateSpriteObject(M2C_UNK *, s32);
    s32 SendWebGetForKind();
    extern M2C_UNK data_ov010_0222c0a0;
    if (SendWebGetForKind() == 0) return 0;
    return CreateSpriteObject(&data_ov010_0222c0a0, arg4);
}

s32 func_ov010_02226560(void) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c3c();
    M2C_UNK date[4];
    M2C_UNK time[3];
    s64 temp;
    s32 res;

    if (GetServerTime(date, time) == 0) {
        temp = 0;
    } else {
        temp = GetElapsedSeconds(func_02085c3c(), date, time);
    }
    res = 0;
    if (temp >= 0x3C) {
        res = 1;
    }
    return res;
}

/* Refresh the clock from the server, then send a sync web request for `kind`,
 * `playerId` and `recordCount` with `payload` and record its error: returns 0
 * when the request failed (statuses 1, 2, 7, 8 and 9), 1 once it is on its way. */
s32 SubmitWebSyncRequest(s32 kind, s32 playerId, u32 recordCount, s32 payload) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c18();
    u32 SendWebSyncRequest(s32, s32, u32, s32);
    M2C_UNK time[3];
    M2C_UNK date[4];
    s32 result;
    u32 status;

    result = 1;
    if (GetServerTime(date, time) != 0) {
        GetElapsedSeconds(func_02085c18(), date, time);
    }
    status = SendWebSyncRequest(kind, playerId, recordCount, payload);
    switch (status) {
    default: break;
    case 1: result = 0; break;
    case 7: result = 0; break;
    case 2: result = 0; break;
    case 8: result = 0; break;
    case 9: result = 0; break;
    }
    if (status != 0) {
        SetWebRequestError(status);
    }
    return result;
}

s32 func_ov010_02226670(void) {
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 1;
    temp_r0 = func_02045a88();
    switch (temp_r0) {
    default:
        break;
    case 5:
        func_02085c04();
        var_r4 = 0;
        break;
    case 6:
        var_r4 = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

s32 func_ov010_022266c4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 CreateSpriteObject(M2C_UNK *, s32);
    s32 SubmitWebSyncRequest();
    extern M2C_UNK data_ov010_0222c060;
    if (SubmitWebSyncRequest() == 0) return 0;
    return CreateSpriteObject(&data_ov010_0222c060, arg4);
}

s32 func_ov010_022266ec(void) {
    s32 GetServerTime(M2C_UNK *, M2C_UNK *);
    s64 GetElapsedSeconds(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c18();
    M2C_UNK time[3];
    M2C_UNK date[4];
    s64 temp;
    s32 res;

    if (GetServerTime(date, time) == 0) {
        temp = 0;
    } else {
        temp = GetElapsedSeconds(func_02085c18(), date, time);
    }
    res = 0;
    if (temp >= 0x3C) {
        res = 1;
    }
    return res;
}

void func_ov010_02226738(void) {
    M2C_UNK func_02045a88();
    func_02045a88();
}

s32 func_ov010_02226744(void) {
 s32 GetWebResponsePlayerTotal(s32 *);
 s32 sp0, temp_r0, var_r4;
 var_r4 = -1;
 temp_r0 = GetWebResponsePlayerTotal(&sp0);
 switch(temp_r0) {
 case 0: var_r4 = sp0; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(temp_r0 != 0) SetWebRequestError(temp_r0);
 return var_r4;
}

s32 func_ov010_022267b0(M2C_UNK arg0, M2C_UNK arg1) {
 s32 GetWebResponsePlayer(M2C_UNK, M2C_UNK);
 s32 temp_r0, var_r4;
 var_r4 = 0;
 temp_r0 = GetWebResponsePlayer(arg1,arg0);
 switch(temp_r0) {
 case 0: var_r4 = 1; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(temp_r0 != 0) SetWebRequestError(temp_r0);
 return var_r4;
}

s32 func_ov010_0222681c(void) {
 s32 func_02045c34(s32 *);
 s32 sp0, temp_r0, var_r4;
 var_r4 = -1;
 temp_r0 = func_02045c34(&sp0);
 switch(temp_r0) {
 case 0: var_r4 = sp0; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(temp_r0 != 0) SetWebRequestError(temp_r0);
 return var_r4;
}

s32 func_ov010_02226888(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    s32 func_02045620();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    extern M2C_UNK sOv010RegisterSpriteClass;
    s32 temp_r0;
    s32 var_r5;

    if (IsOnlineSessionFlagSet(5) == 0) {
        return 1;
    }
    temp_r0 = func_02045620();
    if (temp_r0 == 0) {
        var_r5 = 1;
    } else {
        var_r5 = 0;
    }
    DeleteSpriteObjectsOfClass(&sOv010RegisterSpriteClass);
    if (temp_r0 != 0) {
        SetWebRequestError(temp_r0);
    }
    Ov010Online_ClearStepFlag(5);
    return var_r5;
}

void func_ov010_022268dc(void) {

}

s32 func_ov010_022268e0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_022268f4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
 M2C_UNK func_020e3580();
 func_020e3580(arg1,arg2);
}

M2C_UNK func_ov010_02226908(M2C_UNK arg0, s32 arg1, s32 arg2) {
 M2C_UNK HeapFreeBlock();
 if(arg1 == 0) return;
 HeapFreeBlock(arg1);
}

void func_ov010_02226920(void *arg0) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg0, 0, 0x1A);
    M2C_FIELD(arg0, s8 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    M2C_FIELD(arg0, s32 *, 0x20) = 0x5DC000;
    M2C_FIELD(arg0, s8 *, 0x24) = -1;
    M2C_FIELD(arg0, s8 *, 0x25) = -2;
    M2C_FIELD(arg0, s8 *, 0x26) = -2;
    M2C_FIELD(arg0, s8 *, 0x27) = -1;
    M2C_FIELD(arg0, s8 *, 0x28) = -1;
    MI_CpuFill8(arg0 + 0x2C, 0, 0x40);
}

void *InitOnlinePlayerRecord(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    M2C_FIELD(arg0, s32 *, 0x20) = 0x5DC000;
    M2C_FIELD(arg0, s8 *, 0x24) = -1;
    M2C_FIELD(arg0, s8 *, 0x25) = -2;
    M2C_FIELD(arg0, s8 *, 0x26) = -2;
    M2C_FIELD(arg0, s8 *, 0x27) = -1;
    M2C_FIELD(arg0, s8 *, 0x28) = -1;
    MI_CpuFill8(arg0, 0, 0x1A);
    MI_CpuFill8(arg0 + 0x2C, 0, 0x40);
    return arg0;
}

void func_ov010_022269dc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK CopyU16(M2C_UNK, M2C_UNK, M2C_UNK);
    CopyU16(arg1, arg0, 0x18);
}

void func_ov010_022269f8(s32 a,s32 b,s32 c){MI_CpuCopy8(b,a+44,c);}

void func_ov010_02226a10(void *a){volatile u32 saved;u32 temp;void *p;temp=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=0;p=M2C_FIELD(a,void **,0);saved=temp;while(p!=0){M2C_FIELD(a,void **,0)=M2C_FIELD(p,void **,0);func_ov010_02226908(0,(s32)p,M2C_FIELD(p,s32 *,12)+16);p=M2C_FIELD(a,void **,0);}M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,8)=0;(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;}

void func_ov010_02226a88(void) {
extern M2C_UNK gOv010OnlineSession,data_ov010_0222ef58,data_ov010_0222ef88,data_ov010_0222efb8;
extern Ov010MemberCall data_ov010_0222c128[];
volatile u32 saved;u32 temp;void *p;
temp=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=0;
p=M2C_FIELD(&gOv010OnlineSession,void **,0x60);saved=temp;
while(p){M2C_FIELD(&gOv010OnlineSession,void **,0x60)=M2C_FIELD(p,void **,0);func_ov010_02226908(0,(s32)p,M2C_FIELD(p,s32 *,12)+16);p=M2C_FIELD(&gOv010OnlineSession,void **,0x60);}
M2C_FIELD(&gOv010OnlineSession,s32 *,0x64)=0;M2C_FIELD(&gOv010OnlineSession,s32 *,0x60)=0;M2C_FIELD(&gOv010OnlineSession,s32 *,0x68)=0;
(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;
ov010CallArray((u8 *)&data_ov010_0222ef58,48,data_ov010_0222c128[2]);
ov010CallArray((u8 *)&data_ov010_0222ef88,48,data_ov010_0222c128[1]);
}

#pragma cplusplus on
extern "C" s32 IsOnlinePacketQueued(s32 a) {
    extern M2C_UNK gOv010OnlineSession;
    Ov010InterruptGuard guard;
    void *p = M2C_FIELD(&gOv010OnlineSession, void **, 0x60);
    while (p != NULL) {
        if (a == M2C_FIELD(p, u8 *, 8)) return 1;
        p = M2C_FIELD(p, void **, 0);
    }
    return 0;
}
#pragma cplusplus off
/* Send periodic heartbeats, disconnect silent peers, and advance the network session. */
void TickOnlinePeerKeepAlive(void *link) {
    s32 FX_Div(s32, s32);
    s32 Divide(s32, s32);
    s32 IsConnectionActive(u8);
    void TickNetSession(void);
    s32 IsOnlinePacketQueued(s32);
    void DisconnectOnlinePeer(u8);
    void QueueOnlinePacket(s32, void *, s32, u16);
    s32 GetOnlineTransportPlayerId(void);
    s32 GetOnlinePeerMask(void);
    s32 elapsedMs, frames, timeoutFrames, connectedPeers;
    u16 remotePeers;
    u8 peer;

    elapsedMs = FX_Div(ONLINE_MS_PER_SECOND_FX12, ONLINE_TICK_RATE_FX12);
    frames = M2C_FIELD(link, s32 *, ONLINE_HEARTBEAT_FRAMES) + 1;
    elapsedMs = (frames * elapsedMs) >> 12;
    M2C_FIELD(link, s32 *, ONLINE_HEARTBEAT_FRAMES) = frames;
    if (elapsedMs > ONLINE_HEARTBEAT_INTERVAL_MS) {
        connectedPeers = GetOnlinePeerMask();
        remotePeers = connectedPeers & (-1 ^ (1U << GetOnlineTransportPlayerId()));
        if (remotePeers && (remotePeers & GetOnlinePeerMask()) && !IsOnlinePacketQueued(ONLINE_PACKET_HEARTBEAT))
            QueueOnlinePacket(ONLINE_PACKET_HEARTBEAT, link + ONLINE_HEARTBEAT_FRAMES, 4, remotePeers);
        M2C_FIELD(link, s32 *, ONLINE_HEARTBEAT_FRAMES) = 0;
    }
    timeoutFrames = Divide(ONLINE_PEER_TIMEOUT_NUMERATOR, ONLINE_MILLISECONDS_PER_SECOND);
    peer = 0;
    do {
        if (IsConnectionActive(peer)) {
            {
                void *entry = link + peer * 4;
                frames = M2C_FIELD(entry, s32 *, ONLINE_PEER_IDLE_FRAMES) + 1;
                M2C_FIELD(entry, s32 *, ONLINE_PEER_IDLE_FRAMES) = frames;
            }
            if (frames > timeoutFrames) {
                DisconnectOnlinePeer(peer);
                ((s32 *)(link + ONLINE_PEER_IDLE_FRAMES))[peer] = 0;
            }
        } else
            ((s32 *)(link + ONLINE_PEER_IDLE_FRAMES))[peer] = 0;
        peer++;
    } while (peer < ONLINE_PEER_COUNT);
    TickNetSession();
}

void func_ov010_02226d74(void *arg0) {
    M2C_UNK func_ov010_02226908(M2C_UNK, s32, s32);
    func_ov010_02226908(0, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}

