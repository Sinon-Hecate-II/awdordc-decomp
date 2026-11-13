/* 10 functions from 0x0203BE54 to 0x0203CB38 (main), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma scheduling off
s8 func_0203be54(s8 arg0, s32 arg1, s32 arg2) {
    s32 HeapAlloc(M2C_UNK, s32);
    M2C_UNK HeapFree(M2C_UNK);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s8 func_020427b4(void);
    M2C_UNK StringLength(s32);
    M2C_UNK StringCopy(M2C_UNK, s32);
    s32 StringCompare(void);
    M2C_UNK func_0205fdbc(s8, s32);
    extern u8 gSessionPlayers[];
    extern u8 gSessionPlayerIsString[];
    extern u8 data_0213d3be[];
    extern u8 data_0213d3c0[];
    extern u8 gSessionPlayerValue[];
    s32 var_r6 = arg1;
    s32 var_r5 = arg2;
    s8 var_r7 = arg0;
    s32 temp_r4;
    s32 temp_r0;

    if (var_r6 == 0 || var_r5 == 0) {
        return 0;
    }
    if ((u32) var_r7 >= 0x64U && gSessionPlayers[(var_r7 - 0x64) * 0xC] != 0) {
        s32 off = (var_r7 - 0x64) * 0xC;
        if (*((volatile s32 *)(data_0213d3c0 + off)) != 0 && StringCompare() != 0) {
            return 0;
        }
    } else {
        var_r7 = func_020427b4();
        if ((u32) var_r7 == 0) {
            return 0;
        }
    }
    temp_r4 = (var_r7 - 0x64) * 0xC;
    gSessionPlayers[temp_r4] = var_r7;
    gSessionPlayerIsString[temp_r4] = 0;
    *((u16 *)(data_0213d3be + temp_r4)) = 0;
    if (*((volatile s32 *)(data_0213d3c0 + temp_r4)) != 0) {
        HeapFree(4);
    }
    temp_r0 = HeapAlloc(4, StringLength(var_r6) + 1);
    *((volatile s32 *)(data_0213d3c0 + temp_r4)) = temp_r0;
    if (temp_r0 == 0) {
        func_0203dc38(9, 0xFFFEC77F);
        return 0;
    }
    StringCopy(temp_r0, var_r6);
    *((volatile s32 *)(gSessionPlayerValue + temp_r4)) = var_r5;
    func_0205fdbc(var_r7, *((volatile s32 *)(data_0213d3c0 + temp_r4)));
    return var_r7;
}
#pragma pop
s8 func_0203bf80(u32 arg0, s32 arg1, s32 arg2) {
    s32 HeapAlloc(M2C_UNK, s32);
    M2C_UNK HeapFree(M2C_UNK);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s8 func_020427b4(void);
    M2C_UNK StringLength(s32);
    M2C_UNK StringCopy(M2C_UNK, s32);
    s32 StringCompare(void);
    M2C_UNK func_0205fdbc(s8, s32);
    extern u8 gSessionPlayers[];
    extern u8 gSessionPlayerIsString[];
    extern u8 data_0213d3be[];
    extern u8 data_0213d3c0[];
    extern u8 gSessionPlayerValue[];
    s32 var_r6;
    s32 var_r5;
    u32 var_r7;
    s32 temp_r4;
    u8 *var_r8;
    s32 temp_r0;
    s32 temp_r3;

    var_r6 = arg1;
    var_r5 = arg2;
    var_r7 = arg0;
    if (var_r6 != 0 && var_r5 != 0) {
        if (var_r7 >= 0x64U) {
            temp_r3 = (var_r7 - 0x64) * 0xC;
            if (gSessionPlayers[temp_r3] != 0) {
                if (*((s32 *)(data_0213d3c0 + temp_r3)) != 0 && StringCompare() != 0) {
                    return 0;
                }
                goto block_11;
            }
        }
        var_r7 = (u32) func_020427b4();
        if (var_r7 == 0) {
            return 0;
        }
    block_11:
        temp_r4 = (var_r7 - 0x64) * 0xC;
        gSessionPlayers[temp_r4] = (s8) var_r7;
        gSessionPlayerIsString[temp_r4] = 1;
        *((u16 *)(data_0213d3be + temp_r4)) = 0;
        if (*((s32 *)(data_0213d3c0 + temp_r4)) != 0) {
            HeapFree(4);
        }
        temp_r0 = HeapAlloc(4, StringLength(var_r6) + 1);
        var_r8 = data_0213d3c0;
        *((s32 *)(var_r8 + temp_r4)) = temp_r0;
        if (temp_r0 == 0) {
            func_0203dc38(9, 0xFFFEC77F);
            return 0;
        }
        StringCopy(temp_r0, var_r6);
        *((s32 *)(gSessionPlayerValue + temp_r4)) = var_r5;
        func_0205fdbc((s8) var_r7, *((s32 *)(var_r8 + temp_r4)));
        return (s8) var_r7;
    }
    return 0;
}

s32 func_0203c0b0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 HasNetError();
    void *GetConnection();
    s32 SBServerGetIntValue(s32, M2C_UNK, s32);
    s32 SBServerListGetServer(s32, M2C_UNK);
    s32 temp_r0;
    s32 var_r4;

    var_r4 = arg2;
    if ((GetConnection() == NULL) || (HasNetError() != 0)) {
        return var_r4;
    }
    temp_r0 = SBServerListGetServer(M2C_FIELD(GetConnection(), s32 *, 0xE4), arg0);
    if (temp_r0 != 0) {
        var_r4 = SBServerGetIntValue(temp_r0, arg1, var_r4);
    }
    return var_r4;
}

/* Initialises the network connection object and makes it the active one: stores
   the socket, session and session data pointers plus the game name, password,
   user data and timeout, clears its state/counters/buffers, frees the cached
   session player buffers and resets the match manager flags. */
void InitConnection(s32 connection,s32 socket,s32 session,s32 sessionData,s32 gameName,s32 gamePassword,s32 userData,s32 timeout) {
void *GetConnection(void);s32 SetConnectionState(s32);
void SetActiveConnection(s32);void ClearSessionPlayers(void);void ResetConnection(s32);
void MI_CpuFill8(void *,s32,s32);
extern M2C_UNK gConnectionMgr;
void *conn;
SetActiveConnection(connection);
M2C_FIELD(GetConnection(),s32 *,0)=socket;
M2C_FIELD(GetConnection(),s32 *,4)=session;
M2C_FIELD(GetConnection(),s32 *,8)=sessionData;
M2C_FIELD(GetConnection(),s32 *,16)=0;
M2C_FIELD(GetConnection(),s32 *,28)=0;
M2C_FIELD(GetConnection(),u16 *,26)=0;
M2C_FIELD(GetConnection(),s32 *,228)=0;
SetConnectionState(0);
M2C_FIELD(GetConnection(),u8 *,15)=0;
M2C_FIELD(GetConnection(),u8 *,25)=0;
M2C_FIELD(GetConnection(),u8 *,431)=0;
M2C_FIELD(GetConnection(),u16 *,438)=0;
M2C_FIELD(GetConnection(),s32 *,476)=0;
M2C_FIELD(GetConnection(),s32 *,512)=0;
M2C_FIELD(GetConnection(),s32 *,756)=gameName;
M2C_FIELD(GetConnection(),s32 *,760)=gamePassword;
M2C_FIELD(GetConnection(),s32 *,764)=userData;
M2C_FIELD(GetConnection(),s32 *,768)=timeout;
MI_CpuFill8((u8 *)GetConnection()+0x304,0,64);
M2C_FIELD(GetConnection(),s32 *,836)=0;
M2C_FIELD(GetConnection(),s32 *,1124)=0;
M2C_FIELD(GetConnection(),s32 *,1128)=0;
M2C_FIELD(GetConnection(),s32 *,1140)=0;
M2C_FIELD(GetConnection(),s32 *,1144)=0;
M2C_FIELD(GetConnection(),s32 *,1148)=0;
M2C_FIELD(GetConnection(),s32 *,1152)=0;
conn=GetConnection();
M2C_FIELD(conn,s32 *,0x174)=0;M2C_FIELD(conn,s32 *,0x178)=0;
ClearSessionPlayers();
M2C_FIELD(&gConnectionMgr,u8 *,0x1c)=0;
M2C_FIELD(&gConnectionMgr,u8 *,0x1d)=0;
M2C_FIELD(&gConnectionMgr,u16 *,0x1e)=0;
ResetConnection(0);
}

s32 StartQr2Reporting(s32 arg0){
void *GetConnection(void);
s32 GT2SocketPort(s32);s32 GT2SocketHandle(s32);
s32 Qr2_CreateConnection(void*,s32,s32,s32,s32,s32,s32,void*,void*,void*,void*,void*,void*,s32);
extern s32 Qr2AppendGameKey,Qr2AppendIndex1Noop,Qr2AppendIndex2Noop,Qr2CollectKeys,Qr2RepeatCountNone,Qr2ReportErrorCallback,Qr2OnPublicAddress,Qr2OnStateChanged,Qr2OnReceiveState;
s32 i,result,a,b;void *p,*q;
if(M2C_FIELD(GetConnection(),s32*,16))return 0;
M2C_FIELD(GetConnection(),s32*,512)=arg0;
for(i=0;i<5;i++){
p=GetConnection();
a=GT2SocketHandle(*M2C_FIELD(GetConnection(),s32**,4));
b=GT2SocketPort(*M2C_FIELD(GetConnection(),s32**,4));
q=GetConnection();
result=Qr2_CreateConnection((u8*)p+16,a,b,M2C_FIELD(q,s32*,0x2f4),M2C_FIELD(GetConnection(),s32*,0x2f8),1,1,&Qr2AppendGameKey,&Qr2AppendIndex1Noop,&Qr2AppendIndex2Noop,&Qr2CollectKeys,&Qr2RepeatCountNone,&Qr2ReportErrorCallback,0);
if(!result)break;
Qr2_DestroyConnection(M2C_FIELD(GetConnection(),s32*,16));
M2C_FIELD(GetConnection(),s32*,16)=0;
if(result!=3 || i==4){ReportQr2Error(result);return result;}
}
M2C_FIELD(GetConnection(),s32*,28)=0;
M2C_FIELD(GetConnection(),s16*,26)=0;
func_0205e864(M2C_FIELD(GetConnection(),s32*,16),&Qr2OnPublicAddress);
func_0205e834(M2C_FIELD(GetConnection(),s32*,16),&Qr2OnStateChanged);
func_0205e84c(M2C_FIELD(GetConnection(),s32*,16),&Qr2OnReceiveState);
func_0205ea70(M2C_FIELD(GetConnection(),s32*,16));
return result;
}

/* Start hosting a Wi-Fi match: reserve the matchmaking-message buffer in the
 * connection manager, copy the player list into it, store the match type and the
 * event/result callbacks, create the peer connection and announce the match. */
void StartHostMatch(s32 matchType,s32 playerList,s32 eventCallback,s32 eventData,s32 resultCallback,s32 resultData){
void *GetConnection(void);s32 SetConnectionState(s32);
s32 BeginMatchmakingSession(s32,s32,M2C_UNK,M2C_UNK);
s32 FormatMatchmakingMessage(void*,s32,s32,s32);
s32 StringLength(s32);s32 HeapAlloc(s32,s32);
s32 func_020613dc(s32,s32,s32,s32,s32,s32,s32,M2C_UNK*,s32);
s32 func_02043008(s32);
extern M2C_UNK gConnectionMgr,sMatchMessageSuffix,sEmptyString,func_020432d4;
u8 text[256]; s32 len;void *p,*q,*r,*t; s32 value; void *state=&gConnectionMgr;
value=M2C_FIELD(state,s32*,8);
if(value){HeapFree(4,value,0);M2C_FIELD(&gConnectionMgr,s32*,8)=0;}
if(playerList){
len=FormatMatchmakingMessage(text,-1,32,3);
len=256-len-StringLength((s32)&sMatchMessageSuffix);
value=HeapAlloc(4,len);
M2C_FIELD(&gConnectionMgr,s32*,8)=value;
if(!value){func_0203dc38(9,0xfffec77f);return;}
MI_CpuCopy8(playerList,value,len);
((u8*)M2C_FIELD(&gConnectionMgr,void**,8)+len)[-1]=0;
}
BeginMatchmakingSession(0,matchType,eventCallback,eventData);
M2C_FIELD(GetConnection(),s32*,0x474)=resultCallback;
M2C_FIELD(GetConnection(),s32*,0x478)=resultData;
SetConnectionState(2);
if(!M2C_FIELD(GetConnection(),s32*,0xe4)){
t=GetConnection();q=GetConnection();r=GetConnection();
M2C_FIELD(t,s32*,0xe4)=func_020613dc(M2C_FIELD(q,s32*,0x2f4),M2C_FIELD(r,s32*,0x2f4),M2C_FIELD(GetConnection(),s32*,0x2f8),0,20,1,0,&func_020432d4,0);
}
if(!M2C_FIELD(GetConnection(),s32*,0xe4)&&func_02043008(5))return;
SetGpiStatus(3,&sEmptyString,0);
if(func_02043008(SendMatchmakingParameter(M2C_FIELD(GetConnection(),s32*,0x200))))return;
if(!M2C_FIELD(GetConnection(),s32*,16))StartQr2Reporting(M2C_FIELD(GetConnection(),s32*,512));
ResetConnectionSync(0);
}

#pragma push
#pragma scheduling off
/* Begin joining an online match: store the connection mode and player list, create the
   peer connection, register the match keys (player id/format/version) and connect. */
void StartJoinMatch(s32 playerList, s32 listLength, u8 matchType, s32 flag, s32 eventCallback, s32 eventData, s32 resultCallback, s32 resultData) {
    void *GetConnection(void);
    s32 SetConnectionState(s32);
    s32 BeginMatchmakingSession(s32, s32, M2C_UNK, M2C_UNK);
    s32 MI_CpuCopy8(M2C_UNK, void *, s32);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s32 func_02043008(s32);
    s32 func_020613dc(s32, s32, s32, s32, s32, s32, s32, M2C_UNK *, s32);
    M2C_UNK func_0200567c(void *, s32, void *, s32);
    M2C_UNK func_02037d78(void *, void *, void *, s32);
    M2C_UNK func_02037db0(void *, void *, void *, s32);
    M2C_UNK SetGpiStatus(M2C_UNK, M2C_UNK *, M2C_UNK);
    s32 func_02042f94(void);
    M2C_UNK StartQr2Reporting(s32);
    M2C_UNK TryConnectToPeer(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0204084c(void);
    M2C_UNK ResetConnectionSync(M2C_UNK);
    s32 func_0203e410(void);
    extern M2C_UNK gConnectionMgr, data_020fc908, gKeyFME, data_020fc910, data_020fc914, gKeyMDF, gKeyVER, func_020432d4;
    u8 sp34[12];
    s32 sp14[8];
    void *p, *q;

    BeginMatchmakingSession(1, matchType, eventCallback, eventData);
    *((u8 *)((p = GetConnection())) + 0x1A6) = (u8)(flag ? 1 : 0);
    q = GetConnection();
    M2C_FIELD(q, s32 *, 0x474) = resultCallback;
    q = GetConnection();
    M2C_FIELD(q, s32 *, 0x478) = resultData;
    p = GetConnection();
    MI_CpuCopy8(playerList, (u8 *)p + 0x304, listLength);
    p = GetConnection();
    M2C_FIELD(p, s32 *, 0x344) = listLength;

    if (listLength == 0) goto error;
    {
        if (listLength < (s32)matchType && flag == 0) {
            s32 *gp = M2C_FIELD(&gConnectionMgr, s32 *, 0);
            if (gp == 0 || *(u8 *)gp == 0) goto error;
            {
                if (listLength < (s32)(((u8 *)gp)[1]) - 1) {
error:
                    func_0203dc38(10, 0);
                    goto done;
                }
            }
        }
        SetConnectionState(4);
        p = GetConnection();
        if (M2C_FIELD(p, s32 *, 0xE4) == 0) {
            void *p1 = GetConnection();
            void *p2 = GetConnection();
            void *p3 = GetConnection();
            void *p4 = GetConnection();
            s32 res;
            res = func_020613dc(M2C_FIELD(p2, s32 *, 0x2F4), M2C_FIELD(p3, s32 *, 0x2F4), M2C_FIELD(p4, s32 *, 0x2F8), 0,
                                 0x14, 1, 0, &func_020432d4, 0);
            M2C_FIELD(p1, s32 *, 0xE4) = res;
        }
            p = GetConnection();
            if (M2C_FIELD(p, s32 *, 0xE4) == 0) {
                if (func_02043008(5) != 0) {
                    goto done;
                }
            }
                func_0200567c(sp34, 12, &data_020fc908, matchType);
                func_02037d78(&gKeyFME, sp34, sp14, 0x2F);
                func_02037db0(&gKeyMDF, (flag != 0) ? &data_020fc910 : &data_020fc914, sp14, 0x2F);
                func_0200567c(sp34, 12, &data_020fc908, 3);
                func_02037db0(&gKeyVER, sp34, sp14, 0x2F);
                SetGpiStatus(4, sp14, 0);
                if (func_02042f94() != 0) {
                    goto done;
                }
    }

    p = GetConnection();
    if (M2C_FIELD(p, s32 *, 0x10) != 0) {
        goto tail;
    }
    p = GetConnection();
    if (StartQr2Reporting(M2C_FIELD(p, s32 *, 0x200)) != 0) {
        goto done;
    }
tail:
    TryConnectToPeer(0, 1, 0);
    if (func_0204084c() != 0) {
        goto done;
    }
    ResetConnectionSync(0);
done:
    ;
}
#pragma pop
void func_0203c878(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_UNK StartQr2Reporting(s32);
    M2C_UNK func_0203e410();
    M2C_UNK BeginMatchmakingSession(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02042f94();
    M2C_UNK SetConnectionState(M2C_UNK);
    extern M2C_UNK gConnectionMgr;
    void *temp_r4;

    BeginMatchmakingSession(2, arg0, arg1, arg2);
    M2C_FIELD(GetConnection(), s32 *, 0x46C) = arg3;
    M2C_FIELD(GetConnection(), s32 *, 0x470) = arg4;
    temp_r4 = GetConnection();
    M2C_FIELD(temp_r4, s32 *, 0xF4) = (s32) M2C_FIELD(GetConnection(), s32 *, 0x200);
    M2C_FIELD(GetConnection(), s32 *, 0x2F0) = 1;
    M2C_FIELD(GetConnection(), s8 *, 0xE) = 0;
    M2C_FIELD(&gConnectionMgr, s8 *, 0x1D) = 0;
    SetConnectionState(0xA);
    func_0203e410();
    if (func_02042f94() != 0) {
        return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, 0x10) != 0) {
        return;
    }
    StartQr2Reporting(M2C_FIELD(GetConnection(), s32 *, 0x200));
}

/* Join the match hosted by playerId: set up connection mode 3, store the player
   and the result callback, create the QR2 server/browser, publish the
   matchmaking status and send the join request. */
void StartMatchWithPlayer(s32 playerId,M2C_UNK eventCallback,M2C_UNK eventData,s32 resultCallback,s32 resultData) {
s32 GetConnection(void);
s32 SetConnectionState(s32);
s32 BeginMatchmakingSession(s32,s32,M2C_UNK,M2C_UNK);
M2C_UNK SetGpiStatus(M2C_UNK,M2C_UNK *,M2C_UNK);
M2C_UNK func_0204084c(void);
M2C_UNK SendJoinRequest(s32,M2C_UNK);
s32 func_02043008(M2C_UNK);
s32 func_02042f94(void);
s32 StartQr2Reporting(s32);
s32 func_020613dc(s32,s32,s32,s32,s32,s32,s32,M2C_UNK *,s32);
extern M2C_UNK sEmptyString,func_020432d4;
void *p,*q,*r,*t;
BeginMatchmakingSession(3,0,eventCallback,eventData);
M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_CALLBACK)=resultCallback;
M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_CALLBACK_DATA)=resultData;
M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_ADDRESS_VALID)=1;
p=GetConnection();
M2C_FIELD(p,s32 *,CONN_SESSION_MATCH_ADDRESS)=M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_QR2_PARAM);
M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS)=playerId;
SetConnectionState(4);
if(!M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SERVER_BROWSER)){
t=GetConnection();q=GetConnection();r=GetConnection();
M2C_FIELD(t,s32 *,CONN_SESSION_SERVER_BROWSER)=func_020613dc(M2C_FIELD(q,s32 *,CONN_SESSION_GAME_NAME),M2C_FIELD(r,s32 *,CONN_SESSION_GAME_NAME),M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PLAYER_NAME),0,20,1,0,&func_020432d4,0);
}
if(!M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_SERVER_BROWSER)&&func_02043008(5))return;
SetGpiStatus(5,&sEmptyString,0);
if(func_02042f94())return;
if(!M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_QR2_RECORD)&&StartQr2Reporting(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_QR2_PARAM)))return;
SendJoinRequest(M2C_FIELD(GetConnection(),s32 *,CONN_SESSION_PEER_IDS),0);
if(func_0204084c())return;
}

void func_0203ca88(void *arg0) {
    M2C_UNK func_0205e87c();
    M2C_UNK func_0205ea70(s32);
    u32 temp_r0_2;
    u8 temp_r0;

    if (arg0 == NULL) {
        return;
    }
    func_0205e87c();
    if (M2C_FIELD(arg0, s32 *, 0xB4) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(GetConnection(), u8 *, 0x15);
    switch (temp_r0) {
    case 0:
    case 1:
        temp_r0_2 = M2C_FIELD(GetConnection(), u32 *, 0x1A0);
        switch (temp_r0_2) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 11:
            func_0205ea70(M2C_FIELD(GetConnection(), s32 *, 0x10));
            break;
        default:
            break;
        }
        break;
    case 2:
        if (M2C_FIELD(GetConnection(), u32 *, 0x1A0) == 0xB) {
            func_0205ea70(M2C_FIELD(GetConnection(), s32 *, 0x10));
        }
        break;
    }
}

