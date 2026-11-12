/* 36 functions from 0x02032228 to 0x02033210 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u32 words[3]; } Unk032Record;
typedef struct { u32 words[18]; } Unk032Callbacks;

void func_02032228(void *arg0) {
void func_02007888(u32 *); void func_020472cc(void *); void func_02031dd4(void *,u32,u32); void func_02031dfc(void *,u32); void func_02031e94(void *,s32);
u32 b[5]; u32 a[8]; u32 i; u64 seed;
func_02007888(a);
for(i=1;i<8;i++)a[i]^=a[i-1];
seed=a[7];
func_020472cc(b);
if(b[4])func_02031dd4(arg0,b[0],b[1]);else func_02031dd4(arg0,b[2],b[3]);
func_02031dfc(arg0,(u32)((seed*0x5d588b656c078965ULL+0x269ec3)>>32));
func_02031e94(arg0,1);
}

s32 func_020322ec(void *a) {
void func_020472cc(void *);
u64 func_02031d90(void *);
u32 s[5];
func_020472cc(s);
if(s[4]) return *(u64 *)&s[0]==func_02031d90(a);
return *(u64 *)&s[2]==func_02031d90(a);
}

s32 func_02032358(s32 a) {
s32 func_02031e28();
return func_02031e28(a)==1;
}

s32 func_02032370(s32 arg0) {
    M2C_UNK func_02032358(s32);
    return func_02032358(arg0 + 0x10);
}

s32 func_02032380(void) {
    s32 func_02031e28();
    if (func_02031e28() != 0) {
        return 1;
    }
    return 0;
}

void func_02032398(void) {
    M2C_UNK func_02032380();
    func_02032380();
}

void func_020323a4(void) {
    M2C_UNK func_020321ac();
    func_020321ac();
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
s32 func_02031e28(void *);
void func_020472cc(void *);
u64 func_02031d90(void *);
u32 s[5];
if(func_02031e28((u8 *)a+0x10)==0)return 1;
func_020472cc(s);
if(s[4]==0)return 0;
return *(u64 *)&s[0]==func_02031d90((u8 *)a+0x10);
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
u64 func_02031db8(void *);
if(func_02031e28(a)!=2)return 0;
return func_02031db8(a);
}

s32 GetPlayerRecordId(void *a,void *b) {
u64 func_02031db8(void *);
s32 func_02031dcc(void *);
s32 func_02031f74(u64,s32);
s32 func_02031fe4(u64,s32);
u64 v;
switch(func_02031e28(b)) {
case 2: v=func_02031db8(b);if(!func_02031f74(v,M2C_FIELD(a,s32 *,0x24)))return 0; return func_02031fe4(v,M2C_FIELD(a,s32 *,0x24));
case 3:return func_02031dcc(b);
case 1:return -1;
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

s32 func_02032710(void *a,void *b){
s32 func_02031e28(void *); s32 func_02031dcc(void *); u64 func_02031d90(void *); s32 func_02031db0(void *); u64 func_02031db8(void *);
s32 type=func_02031e28(a);
if(type!=func_02031e28(b))return 0;
if(type==3)return func_02031dcc(a)==func_02031dcc(b);
if(type==1){if(func_02031d90(a)==func_02031d90(b) && func_02031db0(a)==func_02031db0(b))return 1;return 0;}
if(type==2)return func_02031db8(a)==func_02031db8(b);
return 0;
}

s32 func_020327f4(s32 a,s32 b) {
void IsPlayerRecordJoined();
u64 func_02031db8(void *);
void func_02032004(void *,u32,u32);
void FormatNasId(s32,s32,s32);
u8 buf[33];u64 v;
if(func_02031e28(b)==3) {IsPlayerRecordJoined(b);return;}
if(func_02031e28(b)==2) {v=func_02031db8((void *)b);func_02032004(buf+21,(u32)v,(u32)(v>>32));return;}
if(func_02031e28(b)==1)FormatNasId(b,M2C_FIELD(a,s32 *,0x24),(s32)buf);
}

void func_0203287c(s32 arg0) {
    M2C_UNK func_020327f4(s32, s32);
    func_020327f4(arg0, arg0 + 4);
    func_020327f4(arg0, arg0 + 0x10);
}

void func_0203289c(s32 arg0) {
    extern s32 gNasServer;
    gNasServer = arg0;
}

s32 func_020328ac(Unk032Callbacks *arg,s32 value){
M2C_UNK MI_CpuFill8(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_02032c74(s32);
void func_020329d0(void);
extern M2C_UNK gNasConnection,data_020fb33c;
void *p;
void *(*alloc)(void *,s32);
alloc=M2C_FIELD(arg,void *(**)(void *,s32),0x40);
if(M2C_FIELD(&gNasConnection,void **,8))return 2;
M2C_FIELD(&gNasConnection,void **,8)=alloc(&data_020fb33c,0x13f4);
if(!M2C_FIELD(&gNasConnection,void **,8))return 2;
MI_CpuFill8((s32)M2C_FIELD(&gNasConnection,void **,8),0,0x13f4);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1314)=value;
M2C_FIELD(&gNasConnection,s32 *,0)=0;
MI_CpuFill8((s32)(M2C_FIELD(&gNasConnection,void **,8)+0x1008),0,0x1c4);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1008)=0x4e84;
p=M2C_FIELD(&gNasConnection,void **,8);
M2C_FIELD(p,Unk032Callbacks *,0x11cc)=*arg;
M2C_FIELD(p,u16 *,0x11fe)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8 *,0x120b)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004)=func_02032c74(1);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004))return M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004);
M2C_FIELD(&gNasConnection,s32 *,4)=0;
func_020329d0();
return 0;
}

void func_020329d0(void) {
M2C_UNK InitMutex(void *); M2C_UNK func_02005ac0(void *,void (*)(void),void *,void *,s32,s32);
s32 func_02005d90(void *); M2C_UNK TaskWake(void *); void NasConnectTask(void);
extern M2C_UNK gNasConnection; extern M2C_UNK data_0213d11c;
InitMutex(M2C_FIELD(&gNasConnection,void **,8)+0x13d8);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x13f0)=0;
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1384)!=0 && func_02005d90(M2C_FIELD(&gNasConnection,void **,8)+0x1318)==0)return;
func_02005ac0(M2C_FIELD(&gNasConnection,void **,8)+0x1318,NasConnectTask,&data_0213d11c,M2C_FIELD(&gNasConnection,void **,8)+0x1000,0x1000,0x10);
TaskWake(M2C_FIELD(&gNasConnection,void **,8)+0x1318);
}

void func_02032a84(void) {
M2C_UNK LockMutex(void *); M2C_UNK UnlockMutex(void *); M2C_UNK func_02033f3c(s32); M2C_UNK func_02005d60(void *);
extern M2C_UNK gNasConnection;
if(!M2C_FIELD(&gNasConnection,void **,8))return;
LockMutex(M2C_FIELD(&gNasConnection,void **,8)+0x13d8);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x13f0)=1;
UnlockMutex(M2C_FIELD(&gNasConnection,void **,8)+0x13d8);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1314))func_02033f3c(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1314));
if(!M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1384))return;
func_02005d60(M2C_FIELD(&gNasConnection,void **,8)+0x1318);
}

void func_02032b10(void) {
M2C_UNK func_02034480(s32); extern M2C_UNK gNasConnection; extern M2C_UNK data_020fb34c;
void (*callback)(void *,void *,s32);
if(!M2C_FIELD(&gNasConnection,void **,8))return;
callback=M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void (**)(void *,void *,s32),0x1210);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1314))func_02034480(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1314));
callback(&data_020fb34c,M2C_FIELD(&gNasConnection,void **,8),0);
M2C_FIELD(&gNasConnection,void **,8)=0;
}

void func_02032b68(void) {
    M2C_UNK func_02005d60(void *);
    extern M2C_UNK gNasConnection;
    if (M2C_FIELD(M2C_FIELD(&gNasConnection, void **, 8), s32 *, 0x1384) == 0) {
        return;
    }
    func_02005d60(M2C_FIELD(&gNasConnection, void **, 8) + 0x1318);
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

void func_02032be4(void *arg0) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gNasConnection;

    void *p = M2C_FIELD(&gNasConnection, void **, 8);
    if (p == 0) {
        MI_CpuFill8(arg0, 0, 0x1C4);
    }
        p = M2C_FIELD(&gNasConnection, void **, 8);
        MI_CpuCopy8((u8 *)p + 8 + 0x1000, arg0, 0x1C4);
    {
        s32 v = M2C_FIELD(arg0, s32 *, 0);
        if (v < 0x4E20 || v >= 0x7530) {
            M2C_FIELD(arg0, s32 *, 0) = 0x5206;
        }
        v = M2C_FIELD(arg0, s32 *, 0);
        if (v >= 0x4E84) {
            M2C_FIELD(arg0, s32 *, 0) = -v;
        }
    }
}

s32 func_02032c74(s32 arg0){
extern M2C_UNK gNasServer,data_020fb35c,gNasConnection,data_0213d120,gSocketManager;
s32 StringCompare(void *,void *);s32 func_02033ccc(void *,void *);void GetWfcProfile(void *);s32 func_020334d8(void *,void *,void *);s32 func_02033de8(void *);s32 func_02006028(s32);void func_02033e80(void *,s32);
if(StringCompare(M2C_FIELD(&gNasServer,void **,0),&data_020fb35c))M2C_FIELD(&gNasServer,s32 *,20)=1;
{ void *p=M2C_FIELD(&gNasConnection,void **,8);
M2C_FIELD(&gNasServer,s32 *,12)=M2C_FIELD(p,s32 *,0x120c);
M2C_FIELD(&gNasServer,s32 *,16)=M2C_FIELD(p,s32 *,0x1210);
if(func_02033ccc(M2C_FIELD(p,void **,0x1314),(const void *)&gNasServer))return 4;
}
if(arg0==1)GetWfcProfile(&data_0213d120);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004)=func_020334d8(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),(u8 *)M2C_FIELD(&gNasConnection,void **,8)+0x1200,(u8 *)M2C_FIELD(&gNasConnection,void **,8)+0x11cc);
if(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32 *,0x1004))return 4;
if(func_02033de8(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314)))return 4;
func_02033e80(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),func_02006028(M2C_FIELD(&gSocketManager,s32 *,4))-1);
return 0;
}

/* Task body for the Nintendo WFC authentication server (NAS) connection: drive the
   HTTP connect step, wait up to 5 s for it, then close and retry until the server
   answers or the retry budget is spent. */
void NasConnectTask(void) {
extern M2C_UNK gNasConnection;
M2C_UNK func_02005d60(void *);
M2C_UNK LockMutex(void *);
M2C_UNK UnlockMutex(void *);
u64 GetSystemTick(void);
M2C_UNK func_02006030(M2C_UNK);
u64 func_02072088(u64,u64);
M2C_UNK func_0203367c(M2C_UNK);
M2C_UNK Nas_UpdateRequest(void);
M2C_UNK func_02034480(M2C_UNK);
M2C_UNK func_02032c74(M2C_UNK);

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
        func_02005d60((u8 *)stream + 0x338 + 0x1800);
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
    elapsedMs = func_02072088(elapsedTicks << 6, (u64)0x82ea);
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
            func_02006030(0x1388);
            nowTick2 = GetSystemTick();
            elapsedTicks = nowTick2 - startTick;
            elapsedMs2 = func_02072088(elapsedTicks << 6, (u64)0x82ea);
            if (elapsedMs2 >= 0x1388ULL) break;
        }
    }

    conn = M2C_FIELD(&gNasConnection, void **, 8);
    ctx = (u8 *)conn + 0x1000;
    stream = *(void **)((u8 *)ctx + 0x314);
    func_02034480((M2C_UNK)stream);

    conn = M2C_FIELD(&gNasConnection, void **, 8);
    LockMutex((u8 *)conn + 0x13d8);
    result = func_02032c74(reinit);
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

