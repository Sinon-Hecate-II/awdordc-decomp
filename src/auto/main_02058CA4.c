/* 28 functions from 0x02058CA4 to 0x02059BBC (main), found by ds-decomp. */
#include "common.h"
#include "net_session.h"
typedef struct ByteBlock16 { u8 bytes[16]; } ByteBlock16;
static const s8 gGpiInfoXorKey[] = "ameSpy3D";

#pragma opt_common_subs off
/* Reads whatever the gpi info socket has pending into the module's receive
 * buffer (growing it as needed), then splits the buffer on \final\ and
 * dispatches each complete message; the unprocessed remainder is moved to the
 * front. Returns 0 when the connection is unusable, 1 otherwise. */
s32 gpiInfoReadSocket(void) {
extern M2C_UNK gGpiInfoState,gGpiInfoSocket;
void *gpiRealloc(void *,s32);s32 ghiRecv(s32,void *,s32,s32);
void gpiInfoCloseSocket(void);s32 gpiInfoProcessRecvData(s8 *,s32);void MemMove(void *,void *,s32);
s32 received,used,capacity;void *socketRef,*state;
if(M2C_FIELD(&gGpiInfoSocket,s32 *,0)==-1)return 0;
if(M2C_FIELD(&gGpiInfoState,s32 *,16)!=5)return 0;
if(SocketHasPendingData(M2C_FIELD(&gGpiInfoSocket,s32 *,0)))do{state=&gGpiInfoState;socketRef=&gGpiInfoSocket;
if(M2C_FIELD(state,s32 *,44)-M2C_FIELD(state,s32 *,0)<128){
capacity=M2C_FIELD(state,s32 *,44);if(capacity<256)M2C_FIELD(state,s32 *,44)=256;else M2C_FIELD(state,s32 *,44)=capacity*2;
M2C_FIELD(state,void **,12)=gpiRealloc(M2C_FIELD(state,void **,12),M2C_FIELD(state,s32 *,44)+1);
if(!M2C_FIELD(state,void **,12))return 0;
}
used=M2C_FIELD(state,s32 *,0);
received=ghiRecv(M2C_FIELD(socketRef,s32 *,0),M2C_FIELD(state,u8 **,12)+used,M2C_FIELD(state,s32 *,44)-used,0);
if(received<=0){gpiInfoCloseSocket();return 0;}
M2C_FIELD(state,s32 *,0)+=received;
M2C_FIELD(state,u8 **,12)[M2C_FIELD(state,s32 *,0)]=0;
used=gpiInfoProcessRecvData(M2C_FIELD(state,s8 **,12),M2C_FIELD(state,s32 *,0));
if(used==M2C_FIELD(state,s32 *,0))M2C_FIELD(state,s32 *,0)=0;
else{MemMove(M2C_FIELD(state,void **,12),M2C_FIELD(state,u8 **,12)+used,M2C_FIELD(state,s32 *,0)-used);M2C_FIELD(state,s32 *,0)-=used;}
}while(SocketHasPendingData(M2C_FIELD(socketRef,s32 *,0)));
if(M2C_FIELD(&gGpiInfoSocket,s32 *,0)==-1)return 0;else return 1;
}
#pragma opt_common_subs reset
void gpiXorInfoMessage(s8 *arg0, s32 arg1) {
    extern M2C_UNK gGpiInfoSocket;
    s32 i;
    s8 *p;
    p = M2C_FIELD(&gGpiInfoSocket, s8 **, 8);
    for (i = 0; i < arg1; i++) {
        arg0[i] ^= *p;
        if (*++p == 0) p = M2C_FIELD(&gGpiInfoSocket, s8 **, 8);
    }
}

/* GameSpy gpi info string helper: find the field `key` in the server's
 * \key\value\ response, copy the value up to the next delimiter into one of the
 * two scratch banks (alternating so two results stay valid at once) and return
 * it, or NULL when the response has no such field. */
M2C_UNK *gpiGetInfoField(void *info, s8 *key) {
    s8 *StringAppend(s8 *, s8 *);
    s8 *StringFind(s8 *, s8 *);
    s32 StringLength(s8 *);
    extern const u8 gGpiEmptyField[];
    extern s8 gGpiFieldDelimiter[];
    extern M2C_UNK gGpiInfoState;
    extern u8 gGpiProfileScratch[];
    s8 field[0x100];
    u32 count;
    s8 *dst;
    const u8 *src;
    s8 *str;
    s8 *base;
    s8 *p;
    s32 n;
    s32 bank;

    src = gGpiEmptyField;
    dst = field;
    count = 0x80;
    do { u8 a = src[0]; u8 b = src[1]; src += 2; dst[0] = a; dst[1] = b; dst += 2; count -= 1; } while (count != 0);
    bank = M2C_FIELD(&gGpiInfoState, volatile s32 *, GPI_INFO_SCRATCH_BANK);
    bank ^= 1;
    M2C_FIELD(&gGpiInfoState, volatile s32 *, GPI_INFO_SCRATCH_BANK) = bank;
    StringAppend(field, key);
    StringAppend(field, gGpiFieldDelimiter);
    p = StringFind((s8 *)info, field);
    if (p == 0) return 0;
    n = StringLength(field);
    str = p + n;
    base = (s8 *)gGpiProfileScratch + (M2C_FIELD(&gGpiInfoState, volatile s32 *, GPI_INFO_SCRATCH_BANK) << 8);
    dst = base;
    while (*str != 0 && *str != GPI_FIELD_DELIMITER) *dst++ = *str++;
    *dst = 0;
    return (M2C_UNK *)base;
}

M2C_UNK *gpiGetInfoFieldOrEmpty(void *arg0, M2C_UNK *arg1) {
    M2C_UNK *gpiGetInfoField();
    extern M2C_UNK gGpiEmptyValue;
    M2C_UNK *var_r0;

    var_r0 = gpiGetInfoField();
    if (var_r0 == NULL) {
        var_r0 = &gGpiEmptyValue;
    }
    return var_r0;
}

s32 SocketHasPendingData(s32 a) {
    s32 ghiSocketCanRecv(s32);
    return ghiSocketCanRecv(a);
}

/* Find the "\final\" terminator of a GameSpy gpi info message in a buffer of
   `size` bytes: return a pointer to its first backslash, or NULL when the
   buffer holds no terminator. */
s8 *gpiFindInfoMessageTerminator(s8 *buffer, s32 size) {
    s32 limit = size - 6;
    s8 *p = buffer;
    while (p - buffer < limit) {
        if (p[0] == GPI_FIELD_DELIMITER && p[1] == 'f' && p[2] == 'i' && p[3] == 'n' && p[4] == 'a' && p[5] == 'l' && p[6] == GPI_FIELD_DELIMITER) return p;
        p++;
    }
    return NULL;
}

/* Index of the first GPI profile record whose type, id and pid all match the
 * given values, or -1 when there is no profile list or no such record. */
s32 gpiFindProfileRecord(s32 profileType, s32 profileId, s32 pid) {
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem();
    extern M2C_UNK gGpiInfoState;
    s32 i;
    s32 *record;

    if (M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES) == 0) return -1;
    for (i = 0; i < Vector_GetCount(M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES)); i++) {
        record = Vector_GetItem(M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES), i);
        if (M2C_FIELD(record, s32 *, GPI_PROFILE_TYPE) == profileType && M2C_FIELD(record, s32 *, GPI_PROFILE_ID) == profileId && M2C_FIELD(record, s32 *, GPI_PROFILE_PID) == pid) return i;
    }
    return -1;
}

/* Handle the server's reply to a \pauthr\ auth request: look the player's status
 * record up by pid, remember the reply's auth result on it and report it (with the
 * reply's optional \errmsg\ text) to the record's callback. */
void gpiHandleAuthReply(void *reply) {
    s32 ParseInt(M2C_UNK);
    s32 *Vector_GetItem(s32, s32);
    M2C_UNK gpiReportProfileUpdate(s32, s32, s32, s32, s32);
    extern M2C_UNK gGpiKeyAuthResult;
    extern M2C_UNK gGpiKeyLid;
    extern M2C_UNK gGpiKeyErrorMsg;
    extern M2C_UNK gGpiInfoState;
    s32 success;
    s32 profileIndex;
    s32 pid;
    s32 authResult;
    s32 errorMessage;

    authResult = ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeyAuthResult));
    pid = ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeyLid));
    errorMessage = gpiGetInfoFieldOrEmpty(reply, &gGpiKeyErrorMsg);
    profileIndex = gpiFindProfileRecord(GPI_PROFILE_STATUS, pid, 0);
    if (profileIndex == -1) {
        return;
    }
    M2C_FIELD(Vector_GetItem(M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES), profileIndex), s32 *, GPI_PROFILE_PID) = authResult;
    if (authResult > 0) {
        success = 1;
    } else {
        success = 0;
    }
    gpiReportProfileUpdate(profileIndex, success, 0, errorMessage, 0);
}

/* Handle the server's reply to a \getpidr\ request: find the buddy profile
 * record named by the reply's \lid\, store the reply's profile number on it and
 * report whether that number is positive to the record's callback. */
void gpiHandleGetPidReply(void *reply) {
    s32 ParseInt(M2C_UNK);
    s32 *Vector_GetItem(s32, s32);
    M2C_UNK gpiReportProfileUpdate(s32, s32, s32, s32, s32);
    extern M2C_UNK gGpiKeyGetPidr;
    extern M2C_UNK gGpiKeyLid;
    extern M2C_UNK gGpiInfoState;
    s32 success;
    s32 profileIndex;
    s32 pid;

    pid = ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeyGetPidr));
    profileIndex = gpiFindProfileRecord(GPI_PROFILE_BUDDY, ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeyLid)), 0);
    if (profileIndex == -1) {
        return;
    }
    M2C_FIELD(Vector_GetItem(M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES), profileIndex), s32 *, GPI_PROFILE_PID) = pid;
    if (pid > 0) {
        success = 1;
    } else {
        success = 0;
    }
    gpiReportProfileUpdate(profileIndex, success, 0, 0, 0);
}

/* Handle the server's reply to a \getpdr\ profile-data request: find the
   player's auth-profile record, and report back its result and modified flag,
   with the optional \data\ payload and its length (0 when the reply has none). */
void gpiHandleGetProfileReply(void *arg0) {
s32 ParseInt(M2C_UNK);s8 *StringFind(s8 *,s8 *);s32 gpiFindProfileRecord(s32,s32,s32);M2C_UNK gpiReportProfileUpdate(s32,s32,s32,s32,s32);M2C_UNK *gpiGetInfoFieldOrEmpty(void *,M2C_UNK *);
extern M2C_UNK gGpiKeyGetPdr,gGpiKeyLid,gGpiKeyPid,gGpiKeyModified,gGpiKeyLength,gGpiKeyData,gGpiEmptyValue;
s32 profileIndex; s32 textLength,secret,pid,p1,status; s8 *p,*text;
secret=ParseInt(gpiGetInfoFieldOrEmpty(arg0,&gGpiKeyGetPdr));
pid=ParseInt(gpiGetInfoFieldOrEmpty(arg0,&gGpiKeyLid));
p1=ParseInt(gpiGetInfoFieldOrEmpty(arg0,&gGpiKeyPid));
status=ParseInt(gpiGetInfoFieldOrEmpty(arg0,&gGpiKeyModified));
profileIndex=gpiFindProfileRecord(1,pid,p1);
if(profileIndex==-1)return;
textLength=ParseInt(gpiGetInfoFieldOrEmpty(arg0,&gGpiKeyLength));
p=StringFind(arg0,(s8 *)&gGpiKeyData);
if(!p){text=(s8 *)&gGpiEmptyValue;textLength=0;}else text=p+6;
gpiReportProfileUpdate(profileIndex,secret,status,(s32)text,textLength);
}

/* Handle the server's reply to a \setpdr\ profile-data update: find the info
 * profile record the reply names with its \lid\ and \pid\ fields, then report
 * the request's result and modified flag to the record's callback. */
void gpiHandleSetProfileReply(void *reply) {
    s32 ParseInt(M2C_UNK);
    M2C_UNK gpiReportProfileUpdate(s32, s32, s32, s32, s32);
    extern M2C_UNK gGpiKeySetPdr;
    extern M2C_UNK gGpiKeyPid;
    extern M2C_UNK gGpiKeyLid;
    extern M2C_UNK gGpiKeyModified;
    s32 profileIndex;
    s32 lid;
    s32 modified;
    s32 pid;
    s32 result;

    result = ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeySetPdr));
    pid = ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeyPid));
    lid = ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeyLid));
    modified = ParseInt(gpiGetInfoFieldOrEmpty(reply, &gGpiKeyModified));
    profileIndex = gpiFindProfileRecord(GPI_PROFILE_INFO, lid, pid);
    if (profileIndex == -1) {
        return;
    }
    gpiReportProfileUpdate(profileIndex, result, modified, 0, 0);
}

/* Handle one complete \final\-terminated gpi info message: terminate its text and
 * hand it to the parser for its command (\pauthr\, \getpidr\, \getpdr\, \setpdr\). */
void func_020592d8(s8 *arg0, s32 arg1) {
    s32 StringCompareN(void *, void *, s32);
    void gpiHandleAuthReply();
    void gpiHandleGetPidReply();
    void gpiHandleGetProfileReply();
    void gpiHandleSetProfileReply();
    extern u8 data_020ff4f4[];
    extern u8 data_020ff500[];
    extern u8 data_020ff50c[];
    extern u8 data_020ff518[];

    arg0[arg1] = 0;
    if (StringCompareN(arg0, data_020ff4f4, 8) == 0) { gpiHandleAuthReply(arg0, arg1); return; }
    if (StringCompareN(arg0, data_020ff500, 9) == 0) { gpiHandleGetPidReply(arg0, arg1); return; }
    if (StringCompareN(arg0, data_020ff500, 9) == 0) { gpiHandleGetPidReply(arg0, arg1); return; }
    if (StringCompareN(arg0, data_020ff50c, 8) == 0) { gpiHandleGetProfileReply(arg0, arg1); return; }
    if (StringCompareN(arg0, data_020ff518, 8) != 0) return;
    gpiHandleSetProfileReply(arg0, arg1);
}

/* Decrypt and dispatch complete \final\-terminated GameSpy info messages, preserving any incomplete tail. */
s32 gpiInfoProcessRecvData(s8 *buffer, s32 bytesAvailable) {
    void gpiInfoDispatchMessage(s8 *, s32);
    extern M2C_UNK gGpiInfoSocket;
    s8 *messageEnd;
    s32 originalLength;
    s32 messageLength;

    originalLength = bytesAvailable;
    messageEnd = gpiFindInfoMessageTerminator(buffer, bytesAvailable);
    while (bytesAvailable > 0 && messageEnd != NULL) {
        messageLength = messageEnd - buffer;
        M2C_FIELD(&gGpiInfoSocket, M2C_UNK **, 8) = (void *)&gGpiInfoXorKey;
        gpiXorInfoMessage(buffer, messageLength);
        gpiInfoDispatchMessage(buffer, messageLength);
        bytesAvailable -= messageLength + 7;
        buffer = messageEnd + 7;
        if (bytesAvailable > 0) messageEnd = gpiFindInfoMessageTerminator(buffer, bytesAvailable);
    }
    return originalLength - bytesAvailable;
}

/* Report a server update for profile record `profileIndex` (type and status
 * from the reply, plus the command's own arguments) to its registered
 * callback, then drop the record from the profile list. */
s32 gpiReportProfileUpdate(s32 profileIndex, s32 status, s32 secret, s32 text, s32 flags) {
    s32 Vector_GetCount(s32);
    s32 *Vector_GetItem(s32, s32);
    void Vector_RemoveItem(s32 *, s32);
    extern M2C_UNK gGpiInfoState;
    s32 *profile;
    s32 *callback;

    if (profileIndex < 0) {
    }
    else if (profileIndex < Vector_GetCount(M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES))) {
        profile = Vector_GetItem(M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES), profileIndex);
        callback = M2C_FIELD(profile, s32 *, GPI_PROFILE_CALLBACK);
        if (callback != NULL) {
            s32 type = M2C_FIELD(profile, s32 *, GPI_PROFILE_TYPE);
            switch (type) {
                case GPI_PROFILE_STATUS:
                    ((void (*)(s32, s32, s32, s32, s32))callback)(
                        M2C_FIELD(profile, s32 *, GPI_PROFILE_ID), M2C_FIELD(profile, s32 *, GPI_PROFILE_PID),
                        status, text, M2C_FIELD(profile, s32 *, GPI_PROFILE_ONLINE));
                    break;
                case GPI_PROFILE_AUTH:
                    ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, s32))callback)(
                        M2C_FIELD(profile, s32 *, GPI_PROFILE_ID), M2C_FIELD(profile, s32 *, GPI_PROFILE_PID),
                        M2C_FIELD(profile, s32 *, GPI_PROFILE_NAME), M2C_FIELD(profile, s32 *, GPI_PROFILE_NAME_PAD),
                        status, secret, text, flags, M2C_FIELD(profile, s32 *, GPI_PROFILE_ONLINE));
                    break;
                case GPI_PROFILE_INFO:
                    ((void (*)(s32, s32, s32, s32, s32, s32, s32))callback)(
                        M2C_FIELD(profile, s32 *, GPI_PROFILE_ID), M2C_FIELD(profile, s32 *, GPI_PROFILE_PID),
                        M2C_FIELD(profile, s32 *, GPI_PROFILE_NAME), M2C_FIELD(profile, s32 *, GPI_PROFILE_NAME_PAD),
                        status, secret, M2C_FIELD(profile, s32 *, GPI_PROFILE_ONLINE));
                    break;
                case GPI_PROFILE_BUDDY:
                    ((void (*)(s32, s32, s32, s32))callback)(
                        M2C_FIELD(profile, s32 *, GPI_PROFILE_ID), M2C_FIELD(profile, s32 *, GPI_PROFILE_PID),
                        status, M2C_FIELD(profile, s32 *, GPI_PROFILE_ONLINE));
                    break;
                default:
                    break;
            }
        }
        Vector_RemoveItem(M2C_FIELD(&gGpiInfoState, s32 *, GPI_INFO_PROFILES), profileIndex);
    }
}

#pragma opt_common_subs on
void gpiInfoFreeProfiles(void) {
    s32 Vector_GetCount(s32); void Vector_Free(s32); void gpiXorInfoMessage(s8 *, s32); M2C_UNK gpiReportProfileUpdate(s32,s32,s32,s32,s32);
    extern M2C_UNK gGpiInfoState, data_020ff498, gGpiInfoSocket;
    extern const u8 data_020ea9ac[];
    ByteBlock16 buf1, buf0; s32 i;
    if (!M2C_FIELD(&gGpiInfoState,s32 *,4)) return;
    i=Vector_GetCount(M2C_FIELD(&gGpiInfoState,s32 *,4))-1;
    if(i>=0) {
        buf0=*(const ByteBlock16 *)data_020ea9ac;
        do {
            buf1=buf0;
            M2C_FIELD(&gGpiInfoSocket,M2C_UNK **,8)=&data_020ff498;
            gpiXorInfoMessage((s8 *)&buf1,15);
            gpiReportProfileUpdate(i,0,0,(s32)&buf1,0);
        } while(--i>=0);
    }
    Vector_Free(M2C_FIELD(&gGpiInfoState,s32 *,4));
    M2C_FIELD(&gGpiInfoState,s32 *,4)=0;
}
#pragma opt_common_subs off
s32 func_02059640(void *arg0, s32 arg1) {
    s32 *Vector_GetItem(s32, s32);
    extern M2C_UNK gGpiInfoState;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = M2C_FIELD(&gGpiInfoState, void **, 0x28);
    }
    if (var_r0 == NULL) {
        return arg1;
    }
    return *Vector_GetItem(M2C_FIELD(var_r0, s32 *, 0x20), arg1);
}

s32 gpiGetPlayerId(void *arg0, s32 arg1) {
 s32 *Vector_GetItem(s32, s32);
 extern M2C_UNK gGpiInfoState;
 void *var_r0;
 var_r0 = arg0;
 if (var_r0 == NULL) var_r0 = M2C_FIELD(&gGpiInfoState, void **, 0x28);
 if (var_r0 == NULL) return arg1;
 return *Vector_GetItem(M2C_FIELD(var_r0, s32 *, 0x1c), arg1);
}

/* Read the integer value the gpi key/value store holds under `key`, creating the
 * entry as an int with `value` when no such key exists yet, and return it.
 * `gpi` overrides the logged-in session's store; `lookup` finds an existing
 * entry and returns NULL when the key is absent. */
s32 gpiGetOrCreateInt(void *gpi, void *key, M2C_UNK lookup, M2C_UNK value, s32 unused) {
 s32 *BucketNew(s32, void *, s32, M2C_UNK *);
 extern M2C_UNK gGpiInfoState;
 s32 *result;
 void *object = gpi;
 if (object == NULL) object = M2C_FIELD(&gGpiInfoState, void **, GPI_INFO_SESSION);
 if (object == NULL) result = (s32 *)&value;
 else {
 result = ((s32 *(*)(s32, void *, M2C_UNK *))lookup)(M2C_FIELD(object, s32 *, GPI_SESSION_STORE), key, (s32 *)&value);
 if (result == NULL) result = BucketNew(M2C_FIELD(object, s32 *, GPI_SESSION_STORE), key, GPI_BUCKET_INT, (s32 *)&value);
 }
 return *result;
}

/* Read the double value the gpi key/value store holds under `key`, creating the
 * entry as a double with `value` when no such key exists yet, and return it.
 * `gpi` overrides the logged-in session's store; `lookup` finds an existing
 * entry and returns NULL when the key is absent. */
s64 gpiGetOrCreateDouble(void *gpi, void *key, M2C_UNK lookup, s64 value, s32 unused) {
 s32 *BucketNew(s32, void *, s32, M2C_UNK *);
 extern M2C_UNK gGpiInfoState;
 s32 *result;
 void *object = gpi;
 if (object == NULL) object = M2C_FIELD(&gGpiInfoState, void **, GPI_INFO_SESSION);
 if (object == NULL) result = (s32 *)&value;
 else {
 result = ((s32 *(*)(s32, void *, M2C_UNK *))lookup)(M2C_FIELD(object, s32 *, GPI_SESSION_STORE), key, (s32 *)&value);
 if (result == NULL) result = BucketNew(M2C_FIELD(object, s32 *, GPI_SESSION_STORE), key, GPI_BUCKET_DOUBLE, (s32 *)&value);
 }
 return *(s64 *)result;
}

s32 func_02059778(void *arg0, void *arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    s32 *BucketNew(s32, void *, s32, M2C_UNK *);
    extern M2C_UNK gGpiInfoState;
    s32 result;
    void *obj = arg0;
    if (obj == NULL) obj = M2C_FIELD(&gGpiInfoState, void **, 0x28);
    if (obj == NULL) return arg3;
    result = ((s32 (*)(s32, void *, M2C_UNK))arg2)(M2C_FIELD(obj, s32 *, 0xc), arg1, arg3);
    if (result != 0) return result;
    return (s32)BucketNew(M2C_FIELD(obj, s32 *, 0xc), arg1, 2, (M2C_UNK *)arg3);
}

void func_020597d4(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK gpiGetOrCreateInt(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK StringFormat(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff524;
    char sp4[64];
    StringFormat(sp4, &data_020ff524, arg1, func_02059640(arg0, arg4));
    gpiGetOrCreateInt(arg0, sp4, arg2, arg3, arg4);
}

void func_02059830(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s64 arg3, s32 arg4) {
    s64 gpiGetOrCreateDouble(void *, void *, M2C_UNK, s64, s32);
    M2C_UNK StringFormat(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff524;
    char sp8[64];
    StringFormat(sp8, &data_020ff524, arg1, func_02059640(arg0, arg4));
    gpiGetOrCreateDouble(arg0, sp8, arg2, arg3, arg4);
}

void func_02059890(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_02059778(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK StringFormat(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff524;
    char sp4[64];
    StringFormat(sp4, &data_020ff524, arg1, func_02059640(arg0, arg4));
    func_02059778(arg0, sp4, arg2, arg3, arg4);
}

void func_020598ec(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK gpiGetOrCreateInt(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK StringFormat(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK gGpiPlayerKeyFormat;
    char sp4[64];
    StringFormat(sp4, &gGpiPlayerKeyFormat, arg1, gpiGetPlayerId(arg0, arg4));
    gpiGetOrCreateInt(arg0, sp4, arg2, arg3, arg4);
}

void gpiSetPlayerDouble(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s64 arg3, s32 arg4) {
    s64 gpiGetOrCreateDouble(void *, void *, M2C_UNK, s64, s32);
    M2C_UNK StringFormat(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK gGpiPlayerKeyFormat;
    char sp8[64];
    StringFormat(sp8, &gGpiPlayerKeyFormat, arg1, gpiGetPlayerId(arg0, arg4));
    gpiGetOrCreateDouble(arg0, sp8, arg2, arg3, arg4);
}

void func_020599a8(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_02059778(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK StringFormat(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK gGpiPlayerKeyFormat;
    char sp4[64];
    StringFormat(sp4, &gGpiPlayerKeyFormat, arg1, gpiGetPlayerId(arg0, arg4));
    func_02059778(arg0, sp4, arg2, arg3, arg4);
}

s32 gti2CheckChallenge(u8 *arg0) {
s32 var_lr; s32 var_r4; u32 var_r8; u32 var_r9; register u8 *temp_r7; u8 temp_r5; s32 firstBit; u8 temp_r10;
temp_r5=*arg0; firstBit=temp_r5&1; var_lr=0; var_r4=1;
loop_1:
temp_r7=arg0+var_r4; temp_r10=M2C_FIELD(temp_r7,u8 *,-1);
if((u32)temp_r10<(u32)temp_r5) var_r8=1; else var_r8=0;
if((u32)temp_r5<0x4FU) var_r9=1; else var_r9=0;
var_lr=(((firstBit ^ (var_lr ^ ((var_r4 ^ temp_r10)&1))) ^ var_r9) ^ var_r8);
if(var_lr!=0 && !(M2C_FIELD(temp_r7,u8 *,0)&1)) goto fail;
if(var_lr==0 && (M2C_FIELD(temp_r7,u8 *,0)&1)==1) { fail: return 0; }
if(++var_r4<32) goto loop_1;
return 1;
}

/* Fills `buffer` with a 32-character GameSpy GT2 auth challenge: printable
 * random characters whose least-significant bit satisfies a running parity, so
 * that the matching challenge check accepts the string. */
u8 *gti2GetChallenge(u8 *buffer) {
 M2C_UNK AssertFailed();
 s32 Rand(void);
 void GetTickCountMs(void);
 void SetRandSeed(void);
 extern M2C_UNK gGt2GetChallengeName;
 extern M2C_UNK gGt2AssertBuffer;
 extern M2C_UNK gGt2AuthFileName;
 s32 i; u32 parity; u8 *cur; u32 prev,first;
 if (buffer == NULL) AssertFailed(&gGt2AssertBuffer, &gGt2AuthFileName, &gGt2GetChallengeName, 0x2b);
 GetTickCountMs();
 SetRandSeed();
 buffer[0] = Rand() % 93 + 33;
 parity = 0;
 i = 1; do {
  cur = buffer + i;
  prev = cur[-1]; first = buffer[0];
  { u32 prevLtFirst,firstLtO; if(prev<first)prevLtFirst=1;else prevLtFirst=0; if(first<79)firstLtO=1;else firstLtO=0; parity=(first&1)^(parity^((i^prev)&1)); parity^=firstLtO; parity^=prevLtFirst; }
  cur[0] = Rand() % 93 + 33;
  if ((parity && !(cur[0]&1)) || (!parity && (cur[0]&1)==1)) cur[0]++;
  i++; } while(i<0x20);
 return buffer;
}

