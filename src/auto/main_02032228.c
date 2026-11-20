/* 36 functions from 0x02032228 to 0x02033210 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

typedef struct { u32 words[3]; } Unk032Record;

/* Fill the 12-byte NAS login key record: the local WFC profile's 64-bit id (its
 * first id, or the second when the first is unset) and a check word derived from
 * console entropy, marked as a kind-1 record. */
void InitNasLoginKey(void *record) {
    void GetConsoleEntropy(u32 *);
    void GetWfcProfileIds(void *);
    void func_02031dd4(void *, u32, u32);
    void func_02031dfc(void *, u32);
    void func_02031e94(void *, s32);
    u32 profile[5];
    u32 entropy[8];
    u32 i;
    u64 seed;

    GetConsoleEntropy(entropy);
    for (i = 1; i < 8; i++) entropy[i] ^= entropy[i - 1];
    seed = entropy[7];
    GetWfcProfileIds(profile);
    if (profile[4]) func_02031dd4(record, profile[0], profile[1]);
    else func_02031dd4(record, profile[2], profile[3]);
    func_02031dfc(record, (u32)((seed * NAS_KEY_SEED_MULT + NAS_KEY_SEED_ADD) >> 32));
    func_02031e94(record, 1);
}

s32 func_020322ec(void *a) {
void GetWfcProfileIds(void *);
u64 GetNasPlayerCode(void *);
u32 s[5];
GetWfcProfileIds(s);
if(s[4]) return *(u64 *)&s[0]==GetNasPlayerCode(a);
return *(u64 *)&s[2]==GetNasPlayerCode(a);
}

s32 func_02032358(s32 a) {
s32 GetPlayerRecordKind();
return GetPlayerRecordKind(a)==1;
}

s32 func_02032370(s32 arg0) {
    M2C_UNK func_02032358(s32);
    return func_02032358(arg0 + 0x10);
}

s32 IsPlayerRecordPresent(void) {
    s32 GetPlayerRecordKind();
    if (GetPlayerRecordKind() != 0) {
        return 1;
    }
    return 0;
}

void func_02032398(void) {
    M2C_UNK IsPlayerRecordPresent();
    IsPlayerRecordPresent();
}

void func_020323a4(void) {
    M2C_UNK InitProfileIdBlock();
    InitProfileIdBlock();
}

s32 func_020323b0(void *a) {
void func_02076794(void *,u32);
u32 func_02076860(void *,void *,u32);
u32 table[256]; u32 crc;
func_02076794(table,0xedb88320);
crc=func_02076860(table,a,0x3c);
if(crc==M2C_FIELD(a,u32 *,0x3c)) return 1;
return 0;
}

s32 func_020323f4(void *arg0) {
    if ((func_02032358(arg0 + 0x10) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x1C) > 0)) {
        return 1;
    }
    return 0;
}

s32 func_02032424(void *a) {
s32 GetPlayerRecordKind(void *);
void GetWfcProfileIds(void *);
u64 GetNasPlayerCode(void *);
u32 s[5];
if(GetPlayerRecordKind((u8 *)a+0x10)==0)return 1;
GetWfcProfileIds(s);
if(s[4]==0)return 0;
return *(u64 *)&s[0]==GetNasPlayerCode((u8 *)a+0x10);
}

void SetNasProfileKey(void *a,Unk032Record *b,s32 c) {
void func_02076794(void *,u32);
u32 func_02076860(void *,void *,u32);
u32 table[256];
*(Unk032Record *)((u8 *)a+0x10)=*b;
M2C_FIELD(a,s32 *,0x1c)=c;
func_02076794(table,0xedb88320);
M2C_FIELD(a,u32 *,0x3c)=func_02076860(table,a,0x3c);
M2C_FIELD(a,u32 *,0x20)|=1;
}

void func_020324e4(void) {
    M2C_UNK func_020324f0();
    func_020324f0();
}

s32 func_020324f0(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x20) & 1) == 1) {
        return 1;
    }
    return 0;
}

void func_02032508(void) {
    M2C_UNK func_02032514();
    func_02032514();
}

s32 func_02032514(void *a) {
void func_02076794(void *,u32);
u32 func_02076860(void *,void *,u32);
u32 table[256];
M2C_FIELD(a,u32 *,0x20)&=~1;
func_02076794(table,0xedb88320);
M2C_FIELD(a,u32 *,0x3c)=func_02076860(table,a,0x3c);
}

u64 func_02032558(void *a) {
u64 GetPlayerCodeValue(void *);
if(GetPlayerRecordKind(a)!=2)return 0;
return GetPlayerCodeValue(a);
}

/* Resolve the GameSpy profile id behind a match player record: -1 while the
 * record's profile is still unresolved, 0 when it has no player or its player
 * code does not check out against the local game id, otherwise the profile id. */
s32 GetPlayerRecordId(void *localInfo,void *record) {
u64 GetPlayerCodeValue(void *);
s32 GetProfileRecordId(void *);
s32 IsPlayerCodeValid(u64,s32);
s32 GetPlayerCodeId(u64,s32);
u64 code;
switch(GetPlayerRecordKind(record)) {
case PLAYER_RECORD_KIND_CODE: code=GetPlayerCodeValue(record);if(!IsPlayerCodeValid(code,M2C_FIELD(localInfo,s32 *,PROFILE_ID_BLOCK_GAME_ID)))return 0; return GetPlayerCodeId(code,M2C_FIELD(localInfo,s32 *,PROFILE_ID_BLOCK_GAME_ID));
case PLAYER_RECORD_KIND_PROFILE:return GetProfileRecordId(record);
case PLAYER_RECORD_KIND_UNRESOLVED:return -1;
default:return 0;
}
}

u64 func_02032604(void *a) {
u64 func_02031f14(s32,s32);
s32 x=M2C_FIELD(a,s32 *,0x1c); u64 r=0;
if(x)r=func_02031f14(x,M2C_FIELD(a,s32 *,0x24));
return r;
}

void func_02032634(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02031e04(M2C_UNK, M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg0, 0, 0xC);
    func_02031e04(arg0, arg1, arg2);
    func_02031e94(arg0, 2);
}

void func_02032670(void *a,Unk032Record *b) {
M2C_UNK MI_CpuFill8();
M2C_UNK func_02031e0c(s32,s32);
M2C_UNK func_02031e94();
MI_CpuFill8(b,0,12);
if(func_02032370((s32)a)!=0) {
func_02031e0c((s32)b,M2C_FIELD(a,s32 *,0x1c));
func_02031e94(b,3);
} else *b=*(Unk032Record *)((u8 *)a+4);
}

void AssignPlayerRecordId(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02031e0c(M2C_UNK, M2C_UNK);
    M2C_UNK func_02031e94(M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg0, 0, 0xC);
    func_02031e0c(arg0, arg1);
    func_02031e94(arg0, 3);
}

void FormatPlayerNasId(void *a,s32 b,s32 c) {
void FormatNasId(s32,s32,s32);
FormatNasId(b,M2C_FIELD(a,s32 *,0x24),c);
}

/* Compares two NAS session/profile records (Unk032Record).  Records of
 * different kinds never match; keyed records compare their whole key, joined
 * records their profile id, and gpi records their encoded gpi user id. */
s32 PlayerRecordsEqual(void *a,void *b){
s32 GetPlayerRecordKind(void *); s32 GetProfileRecordId(void *); u64 GetNasPlayerCode(void *); s32 GetNasRecordCheckWord(void *); u64 GetPlayerCodeValue(void *);
s32 kind=GetPlayerRecordKind(a);
if(kind!=GetPlayerRecordKind(b))return 0;
if(kind==3)return GetProfileRecordId(a)==GetProfileRecordId(b);
if(kind==1){if(GetNasPlayerCode(a)==GetNasPlayerCode(b) && GetNasRecordCheckWord(a)==GetNasRecordCheckWord(b))return 1;return 0;}
if(kind==2)return GetPlayerCodeValue(a)==GetPlayerCodeValue(b);
return 0;
}

/* Fill a 33-byte text buffer with the id of the player record `record` of the
 * match session `session`: a record whose profile is still unresolved has no text,
 * a player code is written as the two words of its text, and a known profile is
 * formatted together with the session's local profile id.  A record of a player
 * who already joined the match is only marked as joined. */
s32 FormatPlayerRecordId(s32 session, s32 record) {
    s32 IsPlayerRecordJoined(s32);
    u64 GetPlayerCodeValue(void *);
    void func_02032004(void *, u32, u32);
    void FormatNasId(s32, s32, s32);
    u8 text[33];
    u64 code;

    if (GetPlayerRecordKind((void *) record) == PLAYER_RECORD_KIND_PROFILE) {
        IsPlayerRecordJoined(record);
        return;
    }
    if (GetPlayerRecordKind((void *) record) == PLAYER_RECORD_KIND_CODE) {
        code = GetPlayerCodeValue((void *) record);
        func_02032004(text + 21, (u32) code, (u32) (code >> 32));
        return;
    }
    if (GetPlayerRecordKind((void *) record) == PLAYER_RECORD_KIND_UNRESOLVED) {
        FormatNasId(record, M2C_FIELD(session, s32 *, 0x24), (s32) text);
    }
}

void func_0203287c(s32 arg0) {
    M2C_UNK FormatPlayerRecordId(s32, s32);
    FormatPlayerRecordId(arg0, arg0 + 4);
    FormatPlayerRecordId(arg0, arg0 + 0x10);
}

void func_0203289c(s32 arg0) {
    extern s32 gNasServer;
    gNasServer = arg0;
}

/* Create the NAS client's connection block for a login request. Fails with 2 if
 * a connection is already open or its allocation fails; otherwise allocates and
 * zeroes NAS_CONNECTION_SIZE bytes with the request's allocator, remembers the
 * network handle, copies the request descriptor in, resets the status block to
 * NAS_STATUS_IDLE, runs the first connect step (its result goes to
 * NAS_CONN_RESULT) and spawns the task that drives the rest. */
s32 CreateNasConnection(NasRequest *request,s32 handle){
M2C_UNK MI_CpuFill8(M2C_UNK,M2C_UNK,M2C_UNK);
s32 NasConnect(s32);
void NasStartTask(void);
extern M2C_UNK gNasConnection,gAllocTagDwcAuth;
void *p;
void *(*alloc)(void *,s32);
alloc=M2C_FIELD(request,void *(**)(void *,s32),0x40);
if(M2C_FIELD(&gNasConnection,void **,8))return 2;
M2C_FIELD(&gNasConnection,void **,8)=alloc(&gAllocTagDwcAuth,NAS_CONNECTION_SIZE);
if(!M2C_FIELD(&gNasConnection,void **,8))return 2;
MI_CpuFill8((s32)M2C_FIELD(&gNasConnection,void **,8),0,NAS_CONNECTION_SIZE);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_HANDLE)=handle;
M2C_FIELD(&gNasConnection,s32 *,0)=0;
MI_CpuFill8((s32)(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_STATUS),0,NAS_CONN_STATUS_SIZE);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_STATUS)=NAS_STATUS_IDLE;
p=M2C_FIELD(&gNasConnection,void **,8);
M2C_FIELD(p,NasRequest *,NAS_CONN_REQUEST)=*request;
M2C_FIELD(p,u16 *,0x11fe)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8 *,0x120b)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_RESULT)=NasConnect(1);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_RESULT))return M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_RESULT);
M2C_FIELD(&gNasConnection,s32 *,4)=0;
NasStartTask();
return 0;
}

/* Starts the task that drives a NAS connection: resets the connection's mutex and
 * abort flag, and unless the previous task is still running, creates the task
 * that runs NasConnectTask on the connection block's stack and wakes it. */
void NasStartTask(void) {
M2C_UNK InitMutex(void *); M2C_UNK TaskCreate(void *,void (*)(void),void *,void *,s32,s32);
s32 TaskIsFinished(void *); M2C_UNK TaskWake(void *); void NasConnectTask(void);
extern M2C_UNK gNasConnection; extern M2C_UNK gNasTaskOwner;
InitMutex(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_MUTEX);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_ABORT)=0;
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_TASK_ID)!=0 && TaskIsFinished(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_TASK)==0)return;
TaskCreate(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_TASK,NasConnectTask,&gNasTaskOwner,M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_STACK_TOP,NAS_CONN_STACK_SIZE,NAS_CONN_TASK_PRIORITY);
TaskWake(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_TASK);
}

/* Ask a running NAS connection to stop: set its abort flag under the connection
 * mutex, abort the HTTP client it is using, and wait for its task to finish. */
void NasAbort(void) {
M2C_UNK LockMutex(void *); M2C_UNK UnlockMutex(void *); M2C_UNK HttpClientAbort(void *); M2C_UNK OS_JoinThread(void *);
extern M2C_UNK gNasConnection;
if(!M2C_FIELD(&gNasConnection,void **,8))return;
LockMutex(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_MUTEX);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_ABORT)=1;
UnlockMutex(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_MUTEX);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_HANDLE))HttpClientAbort(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_HANDLE));
if(!M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,NAS_CONN_TASK_ID))return;
OS_JoinThread(M2C_FIELD(&gNasConnection,void **,8)+NAS_CONN_TASK);
}

void func_02032b10(void) {
M2C_UNK HttpClientCleanup(s32); extern M2C_UNK gNasConnection; extern M2C_UNK data_020fb34c;
void (*callback)(void *,void *,s32);
if(!M2C_FIELD(&gNasConnection,void **,8))return;
callback=M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void (**)(void *,void *,s32),0x1210);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1314))HttpClientCleanup(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1314));
callback(&data_020fb34c,M2C_FIELD(&gNasConnection,void **,8),0);
M2C_FIELD(&gNasConnection,void **,8)=0;
}

void func_02032b68(void) {
    M2C_UNK OS_JoinThread(void *);
    extern M2C_UNK gNasConnection;
    if (M2C_FIELD(M2C_FIELD(&gNasConnection, void **, 8), s32 *, 0x1384) == 0) {
        return;
    }
    OS_JoinThread(M2C_FIELD(&gNasConnection, void **, 8) + 0x1318);
}

s32 func_02032b98(void) {
M2C_UNK LockMutex(void *); M2C_UNK UnlockMutex(void *);
extern M2C_UNK gNasConnection;
s32 result;
if (!M2C_FIELD(&gNasConnection,void **,8)) return 22;
LockMutex(M2C_FIELD(&gNasConnection,void **,8)+0x13d8);
result=M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004);
UnlockMutex(M2C_FIELD(&gNasConnection,void **,8)+0x13d8);
return result;
}

/* Copies the NAS connection's result block (its head word is the NAS result
 * status) out to `result`, or zeroes it when no connection is open, and
 * normalizes that head word: a word outside the NAS status range becomes
 * NAS_STATUS_UNKNOWN, and a failure code is handed back negated. */
void Nas_GetResult(void *result) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gNasConnection;
    s32 code;

    if (M2C_FIELD(&gNasConnection, void **, 8) == 0) {
        MI_CpuFill8(result, 0, NAS_CONN_STATUS_SIZE);
    }
    MI_CpuCopy8((u8 *)M2C_FIELD(&gNasConnection, void **, 8) + NAS_CONN_STATUS, result, NAS_CONN_STATUS_SIZE);
    code = M2C_FIELD(result, s32 *, 0);
    if (code < NAS_STATUS_BASE || code >= NAS_STATUS_LIMIT) {
        M2C_FIELD(result, s32 *, 0) = NAS_STATUS_UNKNOWN;
    }
    code = M2C_FIELD(result, s32 *, 0);
    if (code >= NAS_STATUS_ERROR_MIN) {
        M2C_FIELD(result, s32 *, 0) = -code;
    }
}

s32 NasConnect(s32 arg0){
extern M2C_UNK gNasServer,data_020fb35c,gNasConnection,data_0213d120,gSocketManager;
s32 StringCompare(void *,void *);s32 HttpClientInit(void *,void *);void GetWfcProfile(void *);s32 func_020334d8(void *,void *,void *);s32 HttpAppendConnectionHeaders(void *);s32 GetThreadPriority(s32);void HttpClientStartTask(void *,s32);
if(StringCompare(M2C_FIELD(&gNasServer,void **,0),&data_020fb35c))M2C_FIELD(&gNasServer,s32 *,20)=1;
{ void *p=M2C_FIELD(&gNasConnection,void **,8);
M2C_FIELD(&gNasServer,s32 *,12)=M2C_FIELD(p,s32 *,0x120c);
M2C_FIELD(&gNasServer,s32 *,16)=M2C_FIELD(p,s32 *,0x1210);
if(HttpClientInit(M2C_FIELD(p,void **,0x1314),(const void *)&gNasServer))return 4;
}
if(arg0==1)GetWfcProfile(&data_0213d120);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004)=func_020334d8(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),(u8 *)M2C_FIELD(&gNasConnection,void **,8)+0x1200,(u8 *)M2C_FIELD(&gNasConnection,void **,8)+0x11cc);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004))return 4;
if(HttpAppendConnectionHeaders(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314)))return 4;
HttpClientStartTask(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),GetThreadPriority(M2C_FIELD(&gSocketManager,s32 *,4))-1);
return 0;
}

/* Task body for the Nintendo WFC authentication server (NAS) connection: drive the
   HTTP connect step, wait up to 5 s for it, then close and retry until the server
   answers or the retry budget is spent. */
void NasConnectTask(void) {
extern M2C_UNK gNasConnection;
M2C_UNK OS_JoinThread(void *);
M2C_UNK LockMutex(void *);
M2C_UNK UnlockMutex(void *);
u64 GetSystemTick(void);
M2C_UNK SleepMilliseconds(M2C_UNK);
u64 U64Divide(u64,u64);
M2C_UNK func_0203367c(M2C_UNK);
M2C_UNK Nas_UpdateRequest(void);
M2C_UNK HttpClientCleanup(M2C_UNK);
M2C_UNK NasConnect(M2C_UNK);

M2C_UNK retryCount = 0;
M2C_UNK reinit = 0;
u64 startTick;
u64 elapsedTicks;
u64 elapsedMs;
void *conn;
void *ctx;
void *stream;
void *conn2;
void *streamCtx;
M2C_UNK streamState;
M2C_UNK step;
M2C_UNK result;
u64 nowTick;
u64 nowTick2;
u64 elapsedMs2;

for (;;) {
    conn = M2C_FIELD(&gNasConnection, void **, 8);
    ctx = (u8 *)conn + 0x1000;
    stream = *(void **)((u8 *)ctx + 0x314);
    if (*(M2C_UNK *)((u8 *)stream + 0x1000 + 0xba4) != 0) {
        OS_JoinThread((u8 *)stream + 0x338 + 0x1800);
    }

    conn = M2C_FIELD(&gNasConnection, void **, 8);
    ctx = (u8 *)conn + 0x1000;
    stream = *(void **)((u8 *)ctx + 0x314);
    if (*(M2C_UNK *)((u8 *)stream + 0x1000 + 0x20) != 8) {
        conn2 = M2C_FIELD(&gNasConnection, void **, 8);
        *(M2C_UNK *)((u8 *)conn2 + 0x1008) = 0x4e84;
        conn2 = M2C_FIELD(&gNasConnection, void **, 8);
        streamCtx = *(void **)((u8 *)conn2 + 0x1000 + 0x314);
        streamCtx = (u8 *)streamCtx + 0x1000;
        streamState = *(M2C_UNK *)((u8 *)streamCtx + 0x20);
        if (streamState == 7) {
            func_0203367c(0x14);
            return;
        }
        if (retryCount > 2) {
            if (streamState == 2) { func_0203367c(9); return; }
            if (streamState == 3) { func_0203367c(0xb); return; }
            func_0203367c(0xd);
            return;
        }
        retryCount = retryCount + 1;
        reinit = 1;
    } else {
        step = Nas_UpdateRequest();
        switch(step) {
        case 0x15: func_0203367c(0x15); return;
        case 0x10:
            if(retryCount>2){func_0203367c(0x10);return;}
            retryCount++;reinit=0;break;
        case 0x11:func_0203367c(step);return;
        default:
            if(retryCount>=2){func_0203367c(step);return;}
            retryCount++;reinit=1;break;
        }
    }

    startTick = GetSystemTick();
    nowTick = GetSystemTick();
    elapsedTicks = nowTick - startTick;
    elapsedMs = U64Divide(elapsedTicks << 6, (u64)0x82ea);
    if (elapsedMs < 0x1388ULL) {
        for (;;) {
            conn = M2C_FIELD(&gNasConnection, void **, 8);
            LockMutex((u8 *)conn + 0x13d8);
            conn = M2C_FIELD(&gNasConnection, void **, 8);
            if (*(M2C_UNK *)((u8 *)conn + 0x13f0) == 1) {
                *(M2C_UNK *)((u8 *)conn + 0x1008) = 0x4e84;
                conn = M2C_FIELD(&gNasConnection, void **, 8);
                UnlockMutex((u8 *)conn + 0x13d8);
                func_0203367c(0x14);
                return;
            }
            UnlockMutex((u8 *)conn + 0x13d8);
            SleepMilliseconds(0x1388);
            nowTick2 = GetSystemTick();
            elapsedTicks = nowTick2 - startTick;
            elapsedMs2 = U64Divide(elapsedTicks << 6, (u64)0x82ea);
            if (elapsedMs2 >= 0x1388ULL) break;
        }
    }

    conn = M2C_FIELD(&gNasConnection, void **, 8);
    ctx = (u8 *)conn + 0x1000;
    stream = *(void **)((u8 *)ctx + 0x314);
    HttpClientCleanup((M2C_UNK)stream);

    conn = M2C_FIELD(&gNasConnection, void **, 8);
    LockMutex((u8 *)conn + 0x13d8);
    result = NasConnect(reinit);
    conn2 = M2C_FIELD(&gNasConnection, void **, 8);
    *(M2C_UNK *)((u8 *)conn2 + 0x1000 + 4) = result;
    conn2 = M2C_FIELD(&gNasConnection, void **, 8);
    if (*(M2C_UNK *)((u8 *)conn2 + 0x1000 + 4) != 0) {
        *(M2C_UNK *)((u8 *)conn2 + 0x1008) = 0x4e84;
        conn2 = M2C_FIELD(&gNasConnection, void **, 8);
        UnlockMutex((u8 *)conn2 + 0x13d8);
        return;
    }
    UnlockMutex((u8 *)conn2 + 0x13d8);
}
}

/* One step of the Nintendo WFC authentication server (NAS) HTTP request: depending on the
 * session state (0x4e00 + the NAS status code) it builds/sends the request or allocates the
 * receive buffer, returning the next step status to NasConnectTask. */
s32 Nas_UpdateRequest(void) {
    extern M2C_UNK gNasConnection, gAllocTagBmWork, gFreeTagBmWork, data_0213d120;
    s32 ParseHttpResponse(u32, u32, void *);
    s32 func_02033210(void);
    s32 func_020470dc(void *, void *);
    void func_02047098(void *);
    void func_0204712c(void *);

    u8 *work = *(u8 **)((u8 *)&gNasConnection + 8);
    void *(*alloc)(void *, s32) = *(void *(**)(void *, s32))(work + 0x1000 + 0x20c);
    void (*freefn)(void *, void *, s32) = *(void (**)(void *, void *, s32))(work + 0x1000 + 0x210);

    if (ParseHttpResponse(*(u32 *)(work + 0x1000 + 0x314), 0, work + 0x1000) != 1) {
        *(s32 *)(*(u8 **)((u8 *)&gNasConnection + 8) + 0x1000 + 8) = 0x4e84;
        return 14;
    }
    if (func_02033210() != 0) {
        return 14;
    }

    {
        s32 state = *(s32 *)(*(u8 **)((u8 *)&gNasConnection + 8) + 0x1000 + 8);
        if (state < 0x4e84) {
            if (state == 0x4e22) {
                void *buffer = alloc((void *)&gAllocTagBmWork, 0x71f);
                if (buffer == 0) {
                    *(s32 *)(*(u8 **)((u8 *)&gNasConnection + 8) + 0x1000 + 8) = 0x4e84;
                    return 2;
                }
                if (func_020470dc(&data_0213d120, (void *)(((u32)buffer + 0x1f) & ~0x1fu)) != 1) {
                    freefn((void *)&gFreeTagBmWork, buffer, 0);
                    *(s32 *)(*(u8 **)((u8 *)&gNasConnection + 8) + 0x1000 + 8) = 0x4e84;
                    return 15;
                }
                freefn((void *)&gFreeTagBmWork, buffer, 0);
            }
            return 21;
        }
        else {
            switch (state) {
            case 0x4e88: {
                func_0204712c(&data_0213d120);
                *(s32 *)(*(u8 **)((u8 *)&gNasConnection + 8) + 0x1000 + 8) = 0x4e88;
                return 16;
            }
            case 0x4e8c: {
                void *buffer = alloc((void *)&gAllocTagBmWork, 0x700);
                if (buffer == 0) {
                    *(s32 *)(*(u8 **)((u8 *)&gNasConnection + 8) + 0x1000 + 8) = 0x4e8c;
                    return 17;
                }
                func_02047098((void *)(((u32)buffer + 0x1f) & ~0x1fu));
                freefn((void *)&gFreeTagBmWork, buffer, 0);
                *(s32 *)(*(u8 **)((u8 *)&gNasConnection + 8) + 0x1000 + 8) = 0x4e8c;
                return 17;
            }
            }
        }
        return 18;
    }
}

