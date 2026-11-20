/* 24 functions from 0x02039EFC to 0x0203AEB4 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
typedef struct { u32 words[3]; } Record3A;
typedef struct { u32 words[8]; } Record39;

void NasConnectionResultCallback(M2C_UNK a,Record39 *b){
extern M2C_UNK gNasLogin,data_020fc8a8,NasLoginInfoCallback;
s32 SetGpiStatus(s32,s32,void *);s32 ReportNasError(void);s32 OpenGameSpySocket(void);s32 StartQr2Reporting(s32);
void ReportNasLoginError(s32,s32);M2C_UNK gpiGetInfo(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32);
void *p;
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,48)=0;
if(b->words[0]==0){
p=M2C_FIELD(&gNasLogin,void **,4);
M2C_FIELD(p,Record39 *,0x260)=*b;
if(M2C_FIELD(p,s32 *,4)==2){
if(M2C_FIELD(M2C_FIELD(p,void **,28),u32 *,28)==b->words[1]){
M2C_FIELD(p,s32 *,4)=5;
SetGpiStatus(1,(s32)&data_020fc8a8,0);
if(ReportNasError())return;
p=M2C_FIELD(&gNasLogin,void **,4);
M2C_FIELD(p,void (**)(s32,u32,s32),20)(0,b->words[1],M2C_FIELD(p,s32 *,24));
if(OpenGameSpySocket())return;
if(StartQr2Reporting(b->words[1]))return;
}else ReportNasLoginError(6,-60000);
}else if(M2C_FIELD(p,s32 *,4)==3){
gpiGetInfo(a,b->words[1],0,0,&NasLoginInfoCallback,0);
if(ReportNasError())return;
}
}else ReportNasError();
}

void NasLoginRequestCallback(M2C_UNK arg0, M2C_UNK arg1) {
    void StartNasGpiConnection(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK);
    void NasConnectionResultCallback(M2C_UNK, Record39 *);
    StartNasGpiConnection(arg0, arg1, (M2C_UNK *)&NasConnectionResultCallback, 2);
}

/* Start the gpi connection that carries the NAS login: keep the account name and
 * password in the login context, stamp the attempt's tick and arm its 60-second
 * timeout, then open the raw gpi connection on the context's handle with the given
 * completion callback.  When that succeeds the login moves to nextState. */
void StartNasGpiConnection(M2C_UNK name,M2C_UNK password,M2C_UNK *callback,M2C_UNK nextState) {
extern M2C_UNK gNasLogin;
void StringCopy(void *,M2C_UNK);
u64 GetSystemTick(void);
void gpiStartConnectionRaw(s32,void *,void *,s32,s32,M2C_UNK *,s32);
s32 ReportNasError(void);
void *context;
StringCopy((u8 *)M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT)+NAS_LOGIN_NAME,name);
StringCopy((u8 *)M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT)+NAS_LOGIN_PASSWORD,password);
context=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);
M2C_FIELD(context,u64 *,NAS_LOGIN_GPI_TICK)=GetSystemTick();
M2C_FIELD(context,s32 *,NAS_LOGIN_GPI_PENDING)=1;
context=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);
gpiStartConnectionRaw(M2C_FIELD(context,s32 *,0),(u8 *)context+NAS_LOGIN_NAME,(u8 *)context+NAS_LOGIN_PASSWORD,1,0,callback,0);
if(ReportNasError()) return; M2C_FIELD(M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT),s32 *,NAS_LOGIN_STATE)=nextState;
}

/* Starts an online/NAS request for source `b`, remembering the completion callback `a`.
 * Builds the 72-byte request descriptor (the request name, the payload name at +0x34 and
 * the alloc/free callbacks at +0x40/+0x44), allocates the NAS connection block and hands
 * the descriptor to CreateNasConnection. */
void StartNasRequest(void *a,s32 b){
extern M2C_UNK gNasLogin;
u64 GetSystemTick(void); s32 func_02032370(void *); s32 func_02032358(void *); s32 func_020322ec(void *); void InitNasLoginKey(void *); void FormatNasId(void *,s32,void *); void func_02031dfc(void *,u32); s32 Utf16StringLength(s32); void MI_CpuCopy8(s32,void *,s32);void StringCopy(void *,M2C_UNK); s32 func_020376a4(s32,s32,s32); void HeapAlloc(void);void HeapFree(M2C_UNK,M2C_UNK,M2C_UNK);void CreateNasConnection(void *,s32);void MI_CpuFill8(void *,s32,s32);
u8 buf[72];void *p; s32 n;
MI_CpuFill8(buf,0,72);M2C_FIELD(&gNasLogin,void **,8)=a;M2C_FIELD(&gNasLogin,s32 *,0)=b;
if(func_02032370(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),void **,28))){
p=M2C_FIELD(&gNasLogin,void **,4);FormatNasId(M2C_FIELD(p,u8 **,28)+16,M2C_FIELD(M2C_FIELD(p,void **,28),s32 *,36),(u8 *)p+0x248);
}else{
if(!func_02032358((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x3c)){
if(func_020322ec(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),u8 **,28)+4)){
p=M2C_FIELD(&gNasLogin,void **,4);M2C_FIELD(p,Record3A *,0x3c)=M2C_FIELD(M2C_FIELD(p,void **,28),Record3A *,4);
}else InitNasLoginKey((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x3c);
}else{
u64 t=GetSystemTick();func_02031dfc((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x3c,(u32)((t*0x5d588b656c078965ULL+0x269ec3)>>32));
}
p=M2C_FIELD(&gNasLogin,void **,4);FormatNasId((u8 *)p+0x3c,M2C_FIELD(p,s32 *,12),(u8 *)p+0x248);
}
n=Utf16StringLength(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,16));
MI_CpuCopy8(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,16),buf,n*2+2);
StringCopy(buf+0x34,(s32)((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x251));
M2C_FIELD(buf,u32 *,64)=(u32)HeapAlloc;M2C_FIELD(buf,u32 *,68)=(u32)HeapFree;n=func_020376a4(0,0x1c14,4);
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,36)=n;
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),u64 *,40)=GetSystemTick();
CreateNasConnection(buf,n);
}

#pragma opt_strength_reduction off
void func_0203a2b4(void) {
    extern M2C_UNK gNasLogin;
    s32 func_02032b98(void);
    void Nas_GetResult(void *);
    void func_02032b10(void);
    u64 GetSystemTick(void);
    u64 U64Divide(u64, u64);
    void StringCopy(void *, M2C_UNK);
    void HeapFree(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02032370(void *);
    void StartNasGpiConnection(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK);
    void MI_CpuFill8(void *, s32, s32);
    s32 Utf16StringLength(s32);
    void MI_CpuCopy8(s32, void *, s32);
    void CreateNasConnection(void *, M2C_UNK);
    void ReportNasLoginError(s32, s32);
    void HeapAlloc(void);
    void NasConnectionResultCallback(M2C_UNK, Record39 *);

    u8 buf[0x3D0];
    s32 n, r;
    void *context;
    u64 now, stored, diff, q;

    r = func_02032b98();
    if (r == 0x15) {
        Nas_GetResult(buf + 0x20C);
        StringCopy((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x48, (M2C_UNK)(buf + 0x200 + 0x56));
        StringCopy((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x148, (M2C_UNK)(buf + 0x300 + 0x83));
        func_02032b10();
        HeapFree(0, M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24), 0);
        M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24) = 0;
        if (func_02032370(M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), void **, 0x1C))) {
            M2C_FIELD(&gNasLogin, void (**)(void *, void *, s32), 8)(
                (void *)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x48),
                (void *)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x148),
                M2C_FIELD(&gNasLogin,s32 *,0));
        } else {
            StartNasGpiConnection(
                (M2C_UNK)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x48),
                (M2C_UNK)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x148),
                (M2C_UNK *)NasConnectionResultCallback,
                3);
        }
    } else {
        r = func_02032b98();
        if (r == 0) {
            return;
        }
        now = GetSystemTick();
        stored = M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), u64 *, 0x28);
        diff = now - stored;
        q = U64Divide(diff << 6, 0x82EAULL);
        if (q > 0x2710ULL) {
            Nas_GetResult(buf + 0x48);
            func_02032b10();
            HeapFree(0, M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24), 0);
            M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24) = 0;
            ReportNasLoginError(2, *(s32 *)(buf + 0x48));
        } else {
            func_02032b10();
            MI_CpuFill8(buf, 0, 0x48);
            n = Utf16StringLength(M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 0x10));
            MI_CpuCopy8(M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 0x10), buf, n * 2 + 2);
            StringCopy(buf + 0x34, (M2C_UNK)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x251));
            *(M2C_UNK *)(buf + 0x40) = (M2C_UNK)HeapAlloc;
            context = M2C_FIELD(&gNasLogin,void **,4);
            *(M2C_UNK *)(buf + 0x44) = (M2C_UNK)HeapFree;
            CreateNasConnection(buf, M2C_FIELD(context, M2C_UNK *, 0x24));
        }
    }
}
#pragma opt_strength_reduction reset
/* Completion callback for the gpi profile fetch of the NAS login.  In state 3
 * it stores the login id in the profile's last-name field and fetches the
 * profile again; in state 4 it verifies the fetched id, records the login key
 * in the session profile and continues the login (state 2).  An id that is
 * already set belongs to an earlier login, so the connection is dropped and
 * the NAS request restarted. */
void NasLoginInfoCallback(s32 conn,void *info) {
extern M2C_UNK gNasLogin;
void FormatNasId(void *,s32,void *); M2C_UNK gpiGetInfo(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32); void gpiSetInfoString(s32,s32,void *); s32 ReportNasError(void); void gpiCloseConnection(s32); void StartNasRequest(void *,s32); s32 StringCompare(s32,M2C_UNK *); void SetNasProfileKey(void *,void *,s32);
u8 nasId[21],expectedId[21],keyText[21]; void *ctx;
if(M2C_FIELD(info,s32 *,0))return;
ctx=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);
if(M2C_FIELD(ctx,s32 *,NAS_LOGIN_STATE)==NAS_STATE_GET_PROFILE){
if(M2C_FIELD(info,s8 *,GPI_INFO_LASTNAME)==0){
FormatNasId(M2C_FIELD(ctx,u8 **,NAS_LOGIN_SESSION)+4,M2C_FIELD(ctx,s32 *,NAS_LOGIN_KEY_TYPE),nasId);
gpiSetInfoString(conn,GPI_INFO_FIELD_LASTNAME,nasId);if(ReportNasError())return;
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT),s32 *,NAS_LOGIN_STATE)=NAS_STATE_VERIFY_PROFILE;
gpiGetInfo(conn,M2C_FIELD(info,s32 *,GPI_INFO_PROFILE_ID),0,0,(M2C_UNK *)NasLoginInfoCallback,0);if(ReportNasError())return;
}else{
gpiCloseConnection(conn);StartNasRequest((void *)NasLoginRequestCallback,0);
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT),s32 *,NAS_LOGIN_STATE)=NAS_STATE_REQUESTING;
}
}else if(M2C_FIELD(ctx,s32 *,NAS_LOGIN_STATE)==NAS_STATE_VERIFY_PROFILE){
FormatNasId(M2C_FIELD(ctx,u8 **,NAS_LOGIN_SESSION)+4,M2C_FIELD(ctx,s32 *,NAS_LOGIN_KEY_TYPE),expectedId);
if(StringCompare((s32)((u8 *)info+GPI_INFO_LASTNAME),(M2C_UNK *)expectedId)==0){
ctx=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);FormatNasId((u8 *)ctx+NAS_LOGIN_KEY,M2C_FIELD(ctx,s32 *,NAS_LOGIN_KEY_TYPE),keyText);
ctx=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);SetNasProfileKey(M2C_FIELD(ctx,void **,NAS_LOGIN_SESSION),(u8 *)ctx+NAS_LOGIN_KEY,M2C_FIELD(info,s32 *,GPI_INFO_PROFILE_ID));
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT),s32 *,NAS_LOGIN_STATE)=NAS_STATE_CONNECTED;
((void (*)(s32,Record39 *,s32))NasConnectionResultCallback)(conn,(Record39 *)((u8 *)M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT)+NAS_LOGIN_CONNECT_RESULT),0);
}else{gpiGetInfo(conn,M2C_FIELD(info,s32 *,GPI_INFO_PROFILE_ID),0,0,(M2C_UNK *)NasLoginInfoCallback,0);if(ReportNasError())return;}
}
}

s32 IsNasLoginDone(void) {
    extern M2C_UNK gNasLogin;
    if ((M2C_FIELD(&gNasLogin, void **, 4) != NULL) && (M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 4) == 5)) {
        return 1;
    }
    return 0;
}

void GetMatchPlayerRecordInfo(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK GetMatchPlayerInfo(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    GetMatchPlayerInfo(arg0, 0, 0, arg1);
}

/* Fetches the local player's match record (by `matchId`) and, when the record
 * is valid, extracts the buddy's SCM and SCN key values into `scmOut`/`scnOut`
 * and copies the player's display name into `nameOut`.  Returns the record's
 * status (0 when there is no record). */
s32 GetMatchPlayerInfo(M2C_UNK matchId,M2C_UNK scmOut,M2C_UNK scnOut,M2C_UNK nameOut) {
extern u8 gBuddyKeySCM[],gBuddyKeySCN[];
s32 FetchMatchPlayerInfo(M2C_UNK,void *);
s32 ExtractKeyValue(void *,void *,void *,s32);
s32 strtoul(void *,void *,s32);
void StringCopy(void *,M2C_UNK);
MatchPlayerInfo info;u32 keyValue;
if(FetchMatchPlayerInfo(matchId,&info)){
if(info.status==6){
if(scmOut){if(ExtractKeyValue(gBuddyKeySCM,&keyValue,info.fields,47)<=0)*(u8 *)scmOut=0;else *(u8 *)scmOut=strtoul(&keyValue,0,10);}
if(scnOut){if(ExtractKeyValue(gBuddyKeySCN,&keyValue,info.fields,47)<=0)*(u8 *)scnOut=0;else *(u8 *)scnOut=strtoul(&keyValue,0,10);}
}else{if(scmOut)*(u8 *)scmOut=0;if(scnOut)*(u8 *)scnOut=0;}
if(nameOut)StringCopy((void *)nameOut,(M2C_UNK)info.name);
return (u8)info.status;
}
if(scmOut)*(u8 *)scmOut=0;if(scnOut)*(u8 *)scnOut=0;return 0;
}

/* Reads the match player record of `matchId` and decodes its base64-encoded name
 * into `name` through the base64 decoder DecodeBase64Url, reporting the decoded
 * byte count in `nameLength` (-1 when there is no record).  The record's player
 * and connected counts are reported through `playerCount`/`connectedCount`.
 * Returns the record's status, 6 when the player was found. */
s32 GetMatchPlayerName(s32 matchId, u8 *playerCount, u8 *connectedCount, char *name, s32 *nameLength) {
    s32 GetMatchPlayerInfo(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 StringLength(void *);
    s32 DecodeBase64Url(void *, s32, s32, s32);
    u8 encoded[256];
    s32 status;
    s32 length;

    status = GetMatchPlayerInfo(matchId, playerCount, connectedCount, (s32)encoded);
    if (!status) {
        *nameLength = -1;
        return status;
    }
    *nameLength = DecodeBase64Url(encoded, StringLength(encoded), 0, 0);
    if (!name || (length = *nameLength) == -1) return status;
    DecodeBase64Url(encoded, StringLength(encoded), name, length);
    return status;
}

/* Publishes the length-byte player status block data as the match session's
 * GameSpy location string: base64-encodes it and sets the cached GPI status with
 * the encoded text. Does nothing without a match session or a finished NAS login.
 * Returns 1 when the status was accepted, 0 otherwise. */
s32 PublishPlayerStatusLocation(s32 data,s32 length) {
extern M2C_UNK gMatchSessionMgr;
s32 Base64EncodeUrl(s32,s32,void *,s32);
s32 SetGpiStatus(s32,s32,void *);
u8 buf[256];s32 n;
if(!M2C_FIELD(&gMatchSessionMgr,void **,8)||!IsNasLoginDone())return 0;
n=Base64EncodeUrl(data,length,buf,255);
if(n==-1)return 0;
buf[n]=0;
return SetGpiStatus(-1,0,buf)==0;
}

s32 func_0203a8dc(void) {
extern M2C_UNK gMatchSessionMgr;
void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(p && (u8)(M2C_FIELD(p,u8 *,0x1e)+255)<=1)return 0;
return 1;
}

/* Empties the 12-byte player record `record` of the online match: while the match
 * session is up and the record resolves to a player (which needs the local
 * profile), that player's GameSpy buddy profile is deleted first so the match
 * connection does not keep the profile of a player who is leaving.  The record
 * ends up empty either way. */
void ReleasePlayerRecord(void *record) {
    extern M2C_UNK gMatchSessionMgr;
    s32 GetLocalPlayerInfo(void);
    s32 GetPlayerRecordId(s32, void *);
    s32 HasBuddyProfile(s32, s32);
    void DeleteBuddyProfile(s32, s32);
    void MI_CpuFill8(void *, s32, s32);
    s32 profileId;

    if (!M2C_FIELD(&gMatchSessionMgr, void **, 8) || !IsNasLoginDone() || !GetLocalPlayerInfo()) goto clear;
    profileId = GetPlayerRecordId(GetLocalPlayerInfo(), record);
    if (!profileId || profileId == -1) goto clear;
    if (HasBuddyProfile(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), s32 *, MATCH_SESSION_CONNECTION), profileId))
        DeleteBuddyProfile(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), s32 *, MATCH_SESSION_CONNECTION), profileId);
clear:
    MI_CpuFill8(record, 0, MATCH_SESSION_PLAYER_SIZE);
}

s32 func_0203a9a4(s32 a,s32 b) {
extern M2C_UNK gMatchSessionMgr;
if(!M2C_FIELD(&gMatchSessionMgr,void **,8))return 0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0x44)=a;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0x48)=b;
return 1;
}

void DecodeNasBase64(void) {
    M2C_UNK DecodeBase64Url();
    DecodeBase64Url();
}

/* Start a match session: register the session object a in gMatchSessionMgr and
   fill its fields (state 0, id b, the e/d settings, the byte flags at 0x1C..0x1F,
   the record c at 0x28); every other field is cleared. */
void StartMatchSession(void *a,s32 b,s32 c,s32 d,s32 e) {
 extern M2C_UNK gMatchSessionMgr;
 void *p;
 M2C_FIELD(&gMatchSessionMgr,void**,8)=a;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,0)=0;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,4)=b;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,8)=0;
 p=M2C_FIELD(&gMatchSessionMgr,void**,8);
 M2C_FIELD(p,s32*,12)=0;M2C_FIELD(p,s32*,16)=0;M2C_FIELD(p,s32*,20)=e;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,24)=d;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,28)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,29)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,30)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,31)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,32)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,36)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,40)=c;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,44)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,48)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,52)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,56)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,60)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,64)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,68)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,72)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,76)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,80)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,84)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,88)=0;
}

/* Advance the registered communication session by one step. */
void func_0203aabc(void) {
extern M2C_UNK gMatchSessionMgr;
s32 HasNetError(void *); s32 MatchSession_Think(void); s32 func_0203bcf8(s32); s32 func_02058c84(void);
void gpiInfoReadSocket(void); void gpiInfoCloseSocket(void); void SyncSessionPlayerConnections(s32,s32); void func_0203b3c4(void);
void *ctx,*child; u32 status;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(!ctx)return;
if(HasNetError(ctx))return;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(!M2C_FIELD(ctx,s32 *,0x18)){
child=M2C_FIELD(ctx,void **,4);
if(child && M2C_FIELD(child,s32 *,0))MatchSession_Think();
return;
}
if(func_0203bcf8(M2C_FIELD(ctx,s32 *,0x18)) || func_02058c84()){
M2C_FIELD(&gMatchSessionMgr,s32 *,0)=1;
M2C_FIELD(&gMatchSessionMgr,s32 *,12)=0;
gpiInfoReadSocket();
M2C_FIELD(&gMatchSessionMgr,s32 *,0)=0;
if(M2C_FIELD(&gMatchSessionMgr,s32 *,12)==1){
M2C_FIELD(&gMatchSessionMgr,s32 *,12)=0;gpiInfoCloseSocket();
}}
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
child=M2C_FIELD(ctx,void **,4);
if(child && M2C_FIELD(child,s32 *,0)){
if(MatchSession_Think())return;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(!M2C_FIELD(ctx,s32 *,0))return;
if(M2C_FIELD(ctx,s32 *,0x18) && (status=M2C_FIELD(ctx,u8 *,0x1e))!=3){
if(M2C_FIELD(ctx,u32 *,8)>7){
if(status<=1)SyncSessionPlayerConnections(M2C_FIELD(ctx,s32 *,0x18),M2C_FIELD(ctx,s32 *,0x14));
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(M2C_FIELD(ctx,u8 *,0x1c)>=M2C_FIELD(ctx,s32 *,0x14)){
M2C_FIELD(ctx,u8 *,0x1e)=3;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
M2C_FIELD(ctx,u8 *,0x1f)++;
}
}}}
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(M2C_FIELD(ctx,u8 *,0x1f)<2)return;
M2C_FIELD(ctx,u8 *,0x1f)=0;
func_0203b3c4();
}

/* Start the match session's play phase: store its four callbacks and their data
   values, clear the player cursor, dirty flag and match step, mark the session
   running and take its first step - a second one too when the session has no
   player list yet. (The two leading pointers are not used here.) */
void MatchSession_Start(s32 unused0, s32 unused1, s32 eventCallback, s32 eventData,
                        s32 infoCallback, s32 infoData, s32 statsCallback, s32 statsData) {
extern M2C_UNK gMatchSessionMgr;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_EVENT_CB)=eventCallback;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_EVENT_DATA)=eventData;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_INFO_CB)=infoCallback;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_INFO_DATA)=infoData;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_STATS_CB)=statsCallback;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_STATS_DATA)=statsData;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_DIRTY)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_STATE)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_STEP)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_CURSOR)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_STATUS)=1;
{void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);if(!M2C_FIELD(p,s32 *,MATCH_SESSION_PLAYERS))M2C_FIELD(p,u8 *,MATCH_SESSION_STEP)++;}
{void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);M2C_FIELD(p,u8 *,MATCH_SESSION_STEP)++;}
}

void func_0203accc(s32 a,s32 b) {
extern M2C_UNK gMatchSessionMgr;void SetNetError(s32,s32);void func_0203b128(void);
void *p;
if(!M2C_FIELD(&gMatchSessionMgr,void **,8)||!a)return;
SetNetError(a,b);
p=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(M2C_FIELD(p,s32 *,0)!=0 && M2C_FIELD(p,s32 *,0)!=2) M2C_FIELD(p,void (**)(s32,u8,s32),44)(a,M2C_FIELD(p,u8 *,29),M2C_FIELD(p,s32 *,48));
func_0203b128();
}

void func_0203ad24(M2C_UNK a,void *b) {
extern M2C_UNK gMatchSessionMgr;
extern M2C_UNK func_0203b9a8;
M2C_UNK gpiGetInfo(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32);
if(!M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,0x18))return;
gpiGetInfo(a,M2C_FIELD(b,s32 *,0),0,0,&func_0203b9a8,0);
}

s32 func_0203ad70(M2C_UNK arg0, void *arg1) {
    M2C_UNK gpiGetInfo(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK *, s32);
    s32 StringCompare(s32, M2C_UNK *);
    extern M2C_UNK data_020fc8b4;
    extern M2C_UNK HandleGpiPlayerInfo;
    if (StringCompare(M2C_FIELD(arg1, s32 *, 8), &data_020fc8b4) != 0) {
        return 0;
    }
    gpiGetInfo(arg0, M2C_FIELD(arg1, s32 *, 0), 0, 0, &HandleGpiPlayerInfo, 0);
    return 1;
}

/* Kind-2 match-session message handler: when the session has an info callback, map
 * the request's target id to a player slot, fetch that buddy's GameSpy status and
 * pass it (with the status word from the filled record) to the callback. */
void MatchSession_ReportBuddyStatus(s32 conn,void *request) {
extern M2C_UNK gMatchSessionMgr;
s32 GetSessionPlayerSlot(s32);
void gpGetBuddyStatus(s32,s32,void *);
u32 out[66]; u32 buf[66];s32 slot;void *session;
if(!M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_INFO_CB))return;
slot=GetSessionPlayerSlot(M2C_FIELD(request,s32 *,0));
if(slot==-1)return;
gpGetBuddyStatus(conn,M2C_FIELD(request,s32 *,8),buf);
session=M2C_FIELD(&gMatchSessionMgr,void **,8);
M2C_FIELD(session,void (**)(s32,u32,void *,s32),MATCH_SESSION_INFO_CB)(slot,buf[1]&255,out,M2C_FIELD(session,s32 *,MATCH_SESSION_INFO_DATA));
}

s32 func_0203ae50(void) {
    extern M2C_UNK gMatchSessionMgr;
    if (M2C_FIELD(&gMatchSessionMgr, void **, 8) != NULL) {
        return M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), s32 *, 0x14);
    }
    return 0;
}

s32 GetSessionPlayerId(s32 a) {
extern M2C_UNK gMatchSessionMgr;
s32 GetLocalPlayerInfo(void);
s32 GetPlayerRecordId(s32,void *);
void *p,*v;
p=M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,0x18);
if(!p)return 0;
v=(void *)GetPlayerRecordId(GetLocalPlayerInfo(),(u8 *)p+a*12);
if(v==0||v==(void *)-1)return 0;
return (s32)v;
}

