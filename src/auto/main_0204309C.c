/* 18 functions from 0x0204309C to 0x02043E10 (main), found by ds-decomp. */
#include "common.h"
#include "qr2.h"

s32 ReportQr2Error(u32 ret){
s32 func_02038f6c(void);
u32 off,code;
if(ret==0)return 0;
switch(ret){
case 1:code=6;off=code-56;break;
case 2:code=6;off=code-66;break;
case 3:code=6;off=code-36;break;
case 4:code=6;off=code-86;break;
case 5:code=6;off=code-26;break;
}
switch(func_02038f6c()){
case 2:func_02039db4(code,off-0xfa00);break;
case 4:func_0203accc(code,off+0xfffedef0);break;
case 5:func_0203dc38(code,off+0xfffeb7e0);break;
default:SetNetError(code,off+0xfffe90d0);break;
}
return ret;
}

s32 func_02043184(s32 a,s32 unused,s32 off) {
s32 code=a;
if(a==0)return 0;
switch(a){
case 1:code=9;off=code-10;break;
case 2:code=6;off=code-56;break;
case 3:code=6;off=code-36;break;
}
func_0203dc38(code,off+0xfffeb010);
return a;
}

#pragma opt_propagation off
s32 func_020431e0(s32 a) {
s32 code;
if(a==0)return 0;
switch(a){
case 1:return 1;
case 2:return 2;
default:code=6;break;
}
if(code)func_0203dc38(code,0xfffeb007);
return a;
}
#pragma opt_propagation reset
u32 func_02043230(u32 a,u32 unused,u32 off) {
u32 ret=a;
u32 code;
code=ret;
if(ret==0)return 0;
switch(ret){
case 1:code=9;off=code-10;break;
case 2:case 5:code=0;off=code;ret=code;break;
case 3:code=6;off=code-16;break;
case 4:code=6;off=code-36;break;
case 6:code=6;off=code-76;break;
case 7:code=6;off=code-86;break;
}
if(code)func_0203dc38(code,off+0xfffeac28);
return ret;
}

void func_020432d4(s32 arg0, s32 arg1, s32 arg2) {
    void *GetConnection(void);
    s32 SBServerListGetCount();
    s32 SBServerListGetServer();
    void SBServerListRemoveServer();
    s32 func_0204292c();
    s32 SBServerGetIp();
    s32 SBServerGetPort();
    s32 SetConnectionState();
    void func_020436d8();
    s32 EvaluateMatchmakingSessions();
    s32 SelectMatchmakingSession();
    s32 SBServerGetIntValue();
    u64 GetSystemTick(void);
    void func_020410f8();
    s32 func_0204084c();
    void SendJoinRequest();
    void func_02040dc8();
    void TryConnectToPeer();
    s32 func_0203ecb0();
    void SendMatchmakingParameter();
    void func_02043008();
    s32 func_02043184();

    extern M2C_UNK gConnectionMgr;
    extern char sDwcKeyPid[];

    void *ctx;
    s32 i;
    s32 count;
    s32 status;
    void *unit;
    s32 kind1;
    s32 kind2;
    s32 key;

    M2C_FIELD(&gConnectionMgr, s32 *, 0x18)++;

    switch (arg1) {
    case 0:
        func_020436d8(arg2);
        ctx = GetConnection();
        M2C_FIELD(ctx, u64 *, 0x174) = GetSystemTick() + 0xefb5f7;
        break;
    case 4:
        ctx = GetConnection();
        i = 0;
        M2C_FIELD(ctx, s32 *, 0x174) = 0;
        M2C_FIELD(ctx, s32 *, 0x178) = 0;

        count = SBServerListGetCount(arg0);
        while (i < count) {
            unit = (void *)SBServerListGetServer(arg0, i);
            if (func_0204292c() == 0) {
                SBServerListRemoveServer(arg0, unit);
                i--;
            }
            i++;
            count = SBServerListGetCount(arg0);
        }

        ctx = GetConnection();
        status = M2C_FIELD(ctx, s32 *, 0x1a0);

        switch (status) {
        case 2:
            i = 0;
            count = SBServerListGetCount(arg0);
            while (i < count) {
                unit = (void *)SBServerListGetServer(arg0, i);
                if (M2C_FIELD(GetConnection(), s32 *, 0x1c) != 0) {
                    if (M2C_FIELD(GetConnection(), s32 *, 0x1c) == SBServerGetIp(unit)) {
                        if (M2C_FIELD(GetConnection(), u16 *, 0x1a) != 0) {
                            if (M2C_FIELD(GetConnection(), u16 *, 0x1a) == SBServerGetPort(unit)) {
                                goto status2_done;
                            }
                        }
                    }
                }
                i++;
                count = SBServerListGetCount(arg0);
            }
status2_done:
            count = SBServerListGetCount(arg0);
            if (i < count) {
                SetConnectionState(3);
                ctx = GetConnection();
                M2C_FIELD(ctx, s32 *, 0x204) = 0;
                ctx = GetConnection();
                SendMatchmakingParameter(M2C_FIELD(ctx, u32 *, 0x204));
                func_02043008();
            } else {
                ctx = GetConnection();
                M2C_FIELD(ctx, s32 *, 0xe8) = 2;
                ctx = GetConnection();
                M2C_FIELD(ctx, u64 *, 0xec) = GetSystemTick();
            }
            break;
        case 3:
            ctx = GetConnection();
            M2C_FIELD(ctx, s32 *, 0xe8) = 2;
            ctx = GetConnection();
            M2C_FIELD(ctx, u64 *, 0xec) = GetSystemTick();
            break;
        case 5:
            EvaluateMatchmakingSessions(1);
            SelectMatchmakingSession();

            while (1) {
                count = SBServerListGetCount(arg0);
                if (count == 0) break;
                unit = (void *)SBServerListGetServer(arg0, 0);
                kind1 = SBServerGetIp(unit);
                ctx = GetConnection();
                if (kind1 != M2C_FIELD(ctx, s32 *, 0x1b8)) {
                    SBServerListRemoveServer(arg0, unit);
                    continue;
                }
                kind2 = SBServerGetPort(unit);
                ctx = GetConnection();
                if (kind2 == (s32)M2C_FIELD(ctx, u16 *, 0x1b4)) {
                    break;
                }
                SBServerListRemoveServer(arg0, unit);
            }

            count = SBServerListGetCount(arg0);
            if (count == 0) {
                ctx = GetConnection();
                M2C_FIELD(ctx, s32 *, 0xe8) = 2;
                ctx = GetConnection();
                M2C_FIELD(ctx, u64 *, 0xec) = GetSystemTick();
            } else {
                unit = (void *)SBServerListGetServer(arg0, 0);
                key = SBServerGetIntValue(unit, sDwcKeyPid, 0);
                if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 1 && key == M2C_FIELD(GetConnection(), s32 *, 0xf4)) {
                    if (EvaluateMatchmakingSessions(0) != 0) {
                        ctx = GetConnection();
                        if (M2C_FIELD(ctx, u8 *, 0x0d) != 0) {
                            func_020410f8();
                            if (func_0204084c() != 0) goto cleanup;
                        }
                    } else {
                        ctx = GetConnection();
                        func_02040dc8((void *)M2C_FIELD(ctx, s32 *, 0xf4));
                        if (func_0204084c() != 0) goto cleanup;
                        SetConnectionState(4);
                        ctx = GetConnection();
                        TryConnectToPeer(0, 0, M2C_FIELD(ctx, s32 *, 0xf4));
                        if (func_0204084c() != 0) goto cleanup;
                        goto cleanup;
                    }
                }
                SetConnectionState(6);
                unit = (void *)SBServerListGetServer(arg0, 0);
                func_0203ecb0(0, 0, (s32)unit);
                func_02043184(0, 0, 0);
                goto cleanup;
            }
            break;
        default:
            ctx = GetConnection();
            M2C_FIELD(ctx, u64 *, 0x174) = GetSystemTick() + 0xefb5f7;
            break;
        }
        break;
    case 5:
        break;
    }

cleanup:
    M2C_FIELD(&gConnectionMgr, s32 *, 0x18)--;
    return;
}

void func_020436d8(void) {

}

#pragma opt_strength_reduction off
/* Score the browsed matchmaking sessions: drop sessions whose host pid is one of
 * our own players (unless in mode 1), run each remaining session through the
 * matchmaking weight callback, drop non-positive scores, store dwc_eval (random
 * tie-breaker in the low byte, score in the upper bits) and optionally sort the
 * list by dwc_eval. Returns 0 when the callback removed every session. */
s32 EvaluateMatchmakingSessions(s32 sort) {
 void *GetConnection(void);s32 SBServerListGetCount(s32);s32 SBServerListGetServer(s32,s32);s32 SBServerGetIntValue(void *,void *,s32);s32 gpiPlayerSetInt(void *,void *,s32);s32 SBServerListSort(s32,s32,void *,s32);s32 RandomBelow(s32);void SBServerListRemoveServer(s32,void *);
 extern char sDwcKeyPid[],sDwcKeyEval[];
 s32 removed=0; s32 isLocal,score;void *session; s32 pid; s32 i=0; s32 slot;void *server;
 for(;i<SBServerListGetCount(M2C_FIELD(GetConnection(),s32 *,0xe4));i++) {
 server=(void *)SBServerListGetServer(M2C_FIELD(GetConnection(),s32 *,0xe4),i);
 if(M2C_FIELD(GetConnection(),u8 *,0x15)==0) {
 pid=SBServerGetIntValue(server,sDwcKeyPid,0);isLocal=0;
 for(slot=1;slot<=M2C_FIELD(GetConnection(),u8 *,0xd);slot++) {
 if(pid==M2C_FIELD((u8 *)GetConnection()+slot*4,s32 *,0xf4)) {
 SBServerListRemoveServer(M2C_FIELD(GetConnection(),s32 *,0xe4),server);i--;isLocal=1;break;
 }}
 if(isLocal)continue;
 }
 if(M2C_FIELD(GetConnection(),s32 *,0x474)) {
 session=GetConnection();
 score=M2C_FIELD(session,s32 (**)(s32,s32),0x474)(i,M2C_FIELD(GetConnection(),s32 *,0x478));
 if(score>0) {if(score>0x7fffff)score=0x7fffff;gpiPlayerSetInt(server,sDwcKeyEval,RandomBelow(256)|(score<<8));}
 else {SBServerListRemoveServer(M2C_FIELD(GetConnection(),s32 *,0xe4),server);i--;removed=1;}
 }else gpiPlayerSetInt(server,sDwcKeyEval,RandomBelow(128));
 }
 if(sort && SBServerListGetCount(M2C_FIELD(GetConnection(),s32 *,0xe4))!=0)SBServerListSort(M2C_FIELD(GetConnection(),s32 *,0xe4),0,sDwcKeyEval,0);
 if(removed && SBServerListGetCount(M2C_FIELD(GetConnection(),s32 *,0xe4))==0)return 0;
 return 1;
}
/* Pick one of the browsed matchmaking sessions and promote it to the front of
   the list: the highest dwc_eval is found, then one session is chosen at random
   weighted towards the top of the sorted list (gMatchmakingSessionWeights) and
   given an eval one above the previous best before the list is re-sorted. */
s32 SelectMatchmakingSession(void) {
    void *GetConnection(void);
    s32 SBServerListGetCount(s32);
    s32 SBServerListGetServer(s32, s32);
    s32 SBServerGetIntValue(void *, void *, s32);
    s32 gpiPlayerSetInt(void *, void *, s32);
    s32 SBServerListSort(s32, s32, void *, s32);
    s32 RandomBelow(s32);
    s32 func_020720f0(s32, s32);
    extern s32 gMatchmakingSessionWeights[];
    extern char sDwcKeyEval[];
    u32 roll;
    s32 maxScore = 0;
    s32 weightTotal = 0;
    s32 count;
    s32 i;
    s32 cumulative[6];
    s32 prev;
    s32 eval;
    s32 scaled;

    count = SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4));
    if (count <= 1) return count;
    i = 0;
    while (i < SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4))) {
        eval = SBServerGetIntValue((void *)SBServerListGetServer(*(s32 *)((u8 *)GetConnection() + 0xE4), i), sDwcKeyEval, -1);
        if (eval > maxScore) maxScore = eval;
        weightTotal += gMatchmakingSessionWeights[i];
        i++;
    }
    roll = RandomBelow(100);
    i = 0;
    while (i < SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4))) {
        if (i == SBServerListGetCount(*(s32 *)((u8 *)GetConnection() + 0xE4)) - 1) break;
        prev = (i > 0) ? cumulative[i - 1] : 0;
        scaled = func_020720f0(gMatchmakingSessionWeights[i] * 100, weightTotal);
        cumulative[i] = scaled + prev;
        if (roll < (u32)cumulative[i]) break;
        i++;
    }
    if (maxScore < 0x7FFFFFFF) maxScore++;
    gpiPlayerSetInt((void *)SBServerListGetServer(*(s32 *)((u8 *)GetConnection() + 0xE4), i), sDwcKeyEval, maxScore);
    return SBServerListSort(*(s32 *)((u8 *)GetConnection() + 0xE4), 0, sDwcKeyEval, 0);
}

/* GameSpy QR2 append-key callback: append the value of game key `key` to the
 * query buffer `query`.  The low keys report a field of the current connection;
 * keys QR2_GAMEKEY_TABLE_BASE and up look the key up in the session player table
 * and append its string or integer value. */
void Qr2AppendGameKey(s32 key, void *query) {
    void *GetConnection(void);
    void Qr2AppendInt(void *, s32);
    void Qr2AppendString(void *, void *);
    extern u8 gSessionPlayers[];
    extern u8 gSessionPlayerIsString[];
    extern void *gSessionPlayerValue[];
    void *conn;
    s32 index;
    s32 offset;

    switch (key) {
    case QR2_GAMEKEY_CONN_14:
        conn = GetConnection();
        Qr2AppendInt(query, ((u8 *)conn)[0x14]);
        return;
    case QR2_GAMEKEY_CONN_16:
        conn = GetConnection();
        Qr2AppendInt(query, ((u8 *)conn)[0x16]);
        return;
    case QR2_GAMEKEY_QR2_PARAM:
        conn = GetConnection();
        Qr2AppendInt(query, *(s32 *)((char *)conn + CONN_SESSION_QR2_PARAM));
        return;
    case QR2_GAMEKEY_MODE:
        conn = GetConnection();
        Qr2AppendInt(query, ((u8 *)conn)[CONN_SESSION_MODE]);
        return;
    case QR2_GAMEKEY_MATCH_ADDR:
        conn = GetConnection();
        Qr2AppendInt(query, *(s32 *)((char *)conn + CONN_SESSION_MATCH_ADDRESS));
        return;
    case QR2_GAMEKEY_CONST_3:
        Qr2AppendInt(query, 3);
        return;
    case QR2_GAMEKEY_CONST_1:
        Qr2AppendInt(query, 1);
        return;
    }
    index = key - QR2_GAMEKEY_TABLE_BASE;
    if (index < 0) return;
    if (index >= QR2_PLAYER_COUNT) return;
    offset = index * QR2_PLAYER_STRIDE;
    if (gSessionPlayers[offset] == 0) return;
    if (gSessionPlayerIsString[offset] != 0) {
        Qr2AppendString(query, *(void **)((char *)gSessionPlayerValue + offset));
    } else {
        Qr2AppendInt(query, **(s32 **)((char *)gSessionPlayerValue + offset));
    }
}

void Qr2AppendIndex1Noop(void) {

}

void Qr2AppendIndex2Noop(void) {

}

void Qr2CollectKeys(s32 a,s32 b) {
extern u8 gSessionPlayers[];
s32 i;u8 *p;
switch(a){case 0:break;case 1:case 2:default:return;}
func_0205eb50(b,8);
func_0205eb50(b,10);
func_0205eb50(b,50);
func_0205eb50(b,51);
func_0205eb50(b,52);
func_0205eb50(b,53);
func_0205eb50(b,54);
p=gSessionPlayers;
for(i=0;i<154;i++,p+=12)if(*p)func_0205eb50(b,*p);
}

s32 Qr2RepeatCountNone(void) {
    return 0;
}

void Qr2ReportErrorCallback(void) {
    M2C_UNK ReportQr2Error();
    ReportQr2Error();
}

void Qr2OnPublicAddress(s32 arg0, s16 arg1) {
    void *GetConnection();
    M2C_FIELD(GetConnection(), s32 *, 0x1C) = arg0;
    M2C_FIELD(GetConnection(), s16 *, 0x1A) = arg1;
}

void Qr2OnStateChanged(s32 arg0){
void *GetConnection();M2C_UNK SetConnectionState(M2C_UNK);s32 func_02043184();s32 func_0203ecb0();
void *p; s32 zero;
p=GetConnection();
if(M2C_FIELD(p,s32 *,0x1a0)==1)SetConnectionState(6);else{p=GetConnection();if(M2C_FIELD(p,s32 *,0x1a0)!=6){p=GetConnection();if(M2C_FIELD(p,s32 *,0x1a0)!=11)return;}}
p=GetConnection();if(arg0==M2C_FIELD(p,s32 *,0x180)){p=GetConnection();M2C_FIELD(p,u8 *,0x17c)=(u8)(M2C_FIELD(p,u8 *,0x17c)+1);}else{p=GetConnection();M2C_FIELD(p,s8 *,0x17c)=0;p=GetConnection();M2C_FIELD(p,s32 *,0x180)=arg0;}
p=GetConnection();zero=0;
M2C_FIELD(p,s32 *,0x184)=zero;M2C_FIELD(p,s32 *,0x188)=zero;
func_0203ecb0(1,arg0,zero);
if(func_02043184()!=0)return;p=GetConnection();M2C_FIELD(p,u8 *,0x3cc)=255;
}

void Qr2OnReceiveState(s32 arg0, u32 arg1) {
    s32 func_02038f6c(void);
    void *GetConnection(void);
    void MI_CpuCopy8(void *, void *, s32);
    s32 StringCompareN(void *, void *, s32);
    s32 func_0203f45c(s32, u32, u32, u32, void *, s32);
    extern u8 data_020fca00[];
    u8 record[20];
    u8 buf[128];
    u32 acc = 0;

    if (func_02038f6c() != 5) {
        if (func_02038f6c() != 6) return;
        if (((u8 *)GetConnection())[0x15] != 2) {
            if (((u8 *)GetConnection())[0x15] != 3) return;
        }
    }
    if (arg1 < 0x14) return;

    for (;;) {
        MI_CpuCopy8((void *)arg0, record, 0x14);
        if (StringCompareN(record, data_020fca00, 4) != 0) return;
        if (*(u32 *)(record + 4) != 3) return;
        MI_CpuCopy8((void *)(arg0 + 0x14), buf, record[9]);
        if (func_0203f45c(record[8], *(u32 *)(record + 16), *(u32 *)(record + 12), *(u16 *)(record + 10), buf, record[9] >> 2) == 0) return;
        acc += record[9] + 0x14;
        if (acc + 0x14 > arg1) return;
    }
}

void func_02043e0c(void) {

}

