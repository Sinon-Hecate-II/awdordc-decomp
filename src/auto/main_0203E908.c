/* 10 functions from 0x0203E908 to 0x0203F45C (main), found by ds-decomp. */
#include "common.h"
#include "qr2.h"
void *GetConnection(void);
typedef struct PacketTag5 { u8 a, b, c, d, e; } PacketTag5;
typedef struct SendPacket { u8 tag[4]; s32 kind; s8 command; u8 length; u16 id; s32 value; s32 state; u32 payload[32]; } SendPacket;
typedef M2C_UNK (*fmt_fn_t)(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32, M2C_UNK);


/* Start a new match-making session: reset the connection, store its mode,
 * capacity, event callback and event data, clear the connect-attempt state, then
 * register the five DWC match-making query key names the session reports. */
void BeginMatchmakingSession(u8 mode, u8 capacity, s32 eventCallback, s32 eventData) {
    void ResetConnection(s32);
    void *GetConnection(void);
    void Qr2_SetKeyName(s32, s8 *);
    extern M2C_UNK sDwcKeyPid;
    extern M2C_UNK sDwcKeyMType;
    extern M2C_UNK sDwcKeyMResv;
    extern M2C_UNK sDwcKeyMVer;
    extern M2C_UNK sDwcKeyEval;
    ResetConnection(0);
    M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) = mode;
    M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_CAPACITY) = capacity;
    M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_EVENT_CALLBACK) = eventCallback;
    M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_EVENT_DATA) = eventData;
    M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_CONNECT_ATTEMPTS) = 0;
    M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PEER_SLOTS) = 0;
    Qr2_SetKeyName(QR2_GAMEKEY_QR2_PARAM, (s8 *)&sDwcKeyPid);
    Qr2_SetKeyName(QR2_GAMEKEY_MODE, (s8 *)&sDwcKeyMType);
    Qr2_SetKeyName(QR2_GAMEKEY_MATCH_ADDR, (s8 *)&sDwcKeyMResv);
    Qr2_SetKeyName(QR2_GAMEKEY_CONST_3, (s8 *)&sDwcKeyMVer);
    Qr2_SetKeyName(QR2_GAMEKEY_CONST_1, (s8 *)&sDwcKeyEval);
}

/* Tear the match-making connection session down: free the session's GameSpy
 * server browser (now, or through the think loop when a browser callback is
 * running), run the deferred-connection teardown, reset the connection state,
 * free the session's saved data buffer and drop the session players, then mark
 * the session closed. */
void TeardownConnectionSession(void) {
    M2C_UNK HeapFree(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_0203bd0c();
    M2C_UNK ClearSessionPlayers();
    void *GetConnection();
    M2C_UNK SetConnectionState(M2C_UNK);
    M2C_UNK DestroyServerBrowser(s32);
    extern M2C_UNK gConnectionMgr;
    if (GetConnection() == NULL) {
        return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_SERVER_BROWSER) != 0) {
        if (M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_BROWSER_DEPTH) != 0) {
            M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_BROWSER_FREE) = 1;
        } else {
            DestroyServerBrowser(M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_SERVER_BROWSER));
            M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_SERVER_BROWSER) = 0;
        }
    }
    func_0203bd0c();
    SetConnectionState(0);
    if (M2C_FIELD(&gConnectionMgr, s32 *, 8) != 0) {
        HeapFree(4, M2C_FIELD(&gConnectionMgr, s32 *, 8), 0);
        M2C_FIELD(&gConnectionMgr, s32 *, 8) = 0;
    }
    ClearSessionPlayers();
    M2C_FIELD(GetConnection(), s8 *, CONN_SESSION_CLOSED) = 1;
}

/* Announces a match-making parameter (a "key = value" text built from the
 * connection state) to the match-making server and the session's players: the
 * recipients are the fixed system connection ids plus every occupied session
 * player slot. Retries the send up to five times; when it cannot be sent it
 * arms the connection's retry deadline. */
s32 SendMatchmakingParameter(s32 value) {
    void FormatMatchmakingMessage(M2C_UNK,s32,s32,s32);
    M2C_UNK StringFormatN();
    void ResetSessionList(s32);
    s32 SendToPlayerList(s32,s32,s32,void *,s32,void *,s32);
    u64 GetSystemTick(void);
    extern M2C_UNK gSessionPlayers,gConnectionMgr,sDwcFormatAnd,sDwcFormatParam,sDwcKeyPid;
    char message[256];
    u8 playerIds[161];
    s32 count=7,i,result;
    u8 *player,*out;
    void *p,*q,*r;
    s32 a,b,c;
    playerIds[0]=8;playerIds[1]=10;playerIds[2]=50;playerIds[3]=51;playerIds[4]=52;playerIds[5]=53;playerIds[6]=54;
    if(M2C_FIELD(GetConnection(),u8 *,0x15)==0 || M2C_FIELD(GetConnection(),u8 *,0x15)==1) {
        player=(u8 *)&gSessionPlayers;out=playerIds+7;
        for(i=0;i<154;i++,player+=12) {
            u8 v=*player;
            if(v!=0){*out++=v;count++;}
        }
    }
    switch(M2C_FIELD(GetConnection(),u32 *,0x1a0)) {
    case 3:
        if(M2C_FIELD(GetConnection(),s32 *,0x208)==0){
            p=GetConnection();q=GetConnection();
            r=GetConnection();
            a=M2C_FIELD(p,volatile s32 *,0x200);b=M2C_FIELD(q,volatile u8 *,0x16);c=M2C_FIELD(r,volatile u8 *,0x15);
            FormatMatchmakingMessage((s32)message,a,b,c);
            value=M2C_FIELD(&gConnectionMgr,s32 *,8);
            if(value!=0)StringFormatN(message,256,&sDwcFormatAnd,message,value);
            break;
        }
        value=M2C_FIELD(GetConnection(),s32 *,0x208);
    case 2:case 4:case 5:
        StringFormatN(message,256,&sDwcFormatParam,&sDwcKeyPid,value);
        M2C_FIELD(GetConnection(),s32 *,0x204)=value;
        break;
    default:break;
    }
    ResetSessionList(M2C_FIELD(GetConnection(),s32 *,0xe4));
    for(i=0;i<5;i++){
        result=SendToPlayerList(M2C_FIELD(GetConnection(),s32 *,0xe4),1,0,playerIds,count,message,6);
        if(result==0)break;
        if(result!=2)break;
    }
    if(result==0){
        p=GetConnection();
        M2C_FIELD(p,u64 *,0x174)=GetSystemTick()+0xefb5f7;
    }
    return result;
}

void FormatMatchmakingMessage(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK StringFormatN(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, M2C_UNK *, s32, s32, s32, M2C_UNK *, s32, M2C_UNK *, M2C_UNK *);
    extern M2C_UNK sDwcKeyPid;
    extern M2C_UNK sDwcKeyMType;
    extern M2C_UNK sDwcKeyMResv;
    extern M2C_UNK sDwcKeyMVer;
    extern M2C_UNK sDwcFormatMismatch;
    StringFormatN(arg0, 0x100, &sDwcFormatMismatch, &sDwcKeyMVer, 3, &sDwcKeyPid, arg1, arg2, arg2, &sDwcKeyMType, arg3, &sDwcKeyMResv, &sDwcKeyPid);
}

s32 func_0203ecb0(s32 mode, s32 sessionId, s32 data) {
    s32 func_02060c78(void *);
    s32 SBServerGetIp(s32 *);
    s32 func_020617b4(void *);
    s32 func_02060c90(void *);
    u16 func_02060c98(void *);
    s32 func_020218bc(void);
    u16 SBServerGetPort(void *);
    u32 RandomBelow(u32);
    u16 GT2SocketPort(void *);
    s32 GT2SocketHandle(s32);
    s32 SendConnectionCommand(u8, s32, s32, u16, s32 *, s32);
    s32 StartPeerConnect(void *);
    void OnPeerConnect(s32,s32,s32,void *);
    s32 index, deferred, result;
    u8 *session;
    s32 tempData[2];
    s32 value;
    u32 low;

    session = GetConnection();
    index = session[0x14];
    result = 0;

    if (mode == 0) {
        u8 *s = GetConnection();
        u16 high = M2C_FIELD(GetConnection(), u16 *, 0x17e);
        low = M2C_FIELD(s, u32 *, 0x200);
        low = (u16)low;
        sessionId = ((u32)high << 16) | low;
        if (func_02060c78((void *)data)) {
            value = SBServerGetIp((s32 *)data);
            if (value != func_020617b4(M2C_FIELD(GetConnection(), void **, 0xe4))) {
                deferred = 1;
            } else {
                s = GetConnection();
                M2C_FIELD(s + index * 4, s32 *, 0x210) = func_02060c90((void *)data);
                s = GetConnection();
                M2C_FIELD(s + index * 2, u16 *, 0x290) = func_02060c98((void *)data);
                deferred = result;
            }
        } else {
            u32 key = (u16)func_020218bc();
            if ((u16)key == 0xa8c0 || ((key & 255) == 0xac && (key & 0xff00) >= 0x1000 && (key & 0xff00) <= 0x1f00) || (key & 255) == 10) {
                deferred = 1;
            } else {
                s = GetConnection();
                M2C_FIELD(s + index * 4, s32 *, 0x210) = SBServerGetIp((s32 *)data);
                s = GetConnection();
                M2C_FIELD(s + index * 2, u16 *, 0x290) = SBServerGetPort((void *)data);
                deferred = 0;
            }
        }
        if (deferred) {
            s = GetConnection();
            M2C_FIELD(s, u16 *, 0x17e) = RandomBelow(0x10000);
            M2C_FIELD(GetConnection(), s32 *, 0x19c) = sessionId;
        } else {
            s32 first;
            u16 second;
            tempData[0] = func_020218bc();
            tempData[1] = GT2SocketPort(*(void **)M2C_FIELD(GetConnection(), void **, 4));
            s = GetConnection();
            first = SBServerGetIp((s32 *)data);
            second = SBServerGetPort((void *)data);
            value = SendConnectionCommand(6, M2C_FIELD(s + index * 4, s32 *, 0xf4), first, second, tempData, 2);
            M2C_FIELD(GetConnection(), u8 *, 0x3cd) = 0;
            if (value) {
                return 2;
            }
            M2C_FIELD(GetConnection(), s32 *, 0x19c) = 0;
        }
        M2C_FIELD(GetConnection(), u8 *, 0x194) = 0;
        M2C_FIELD(GetConnection(), u8 *, 0x195) = 0;
        s = GetConnection();
        M2C_FIELD(s, u16 *, 0x196) = SBServerGetPort((void *)data);
        s = GetConnection();
        M2C_FIELD(s, s32 *, 0x198) = SBServerGetIp((s32 *)data);
    } else {
        M2C_FIELD(GetConnection(), u8 *, 0x194) = 1;
        M2C_FIELD(GetConnection(), u8 *, 0x195) = result;
        M2C_FIELD(GetConnection(), u16 *, 0x196) = result;
        M2C_FIELD(GetConnection(), s32 *, 0x198) = result;
        M2C_FIELD(GetConnection(), s32 *, 0x19c) = sessionId;
        deferred = 1;
    }
    if (deferred) {
        result = StartPeerConnect((u8 *)GetConnection() + 0x194);
    } else {
        value = GT2SocketHandle(*M2C_FIELD(GetConnection(), s32 **, 4));
        OnPeerConnect(0, value, 0, (u8 *)GetConnection() + 0x194);
        session = GetConnection();
        M2C_FIELD(session, s32 *, 0x18c) = 0;
        M2C_FIELD(session, s32 *, 0x190) = 0;
    }
    return result;
}

/* Send the socket connect described by the connection's in-flight attempt.  A join
 * attempt uses the address the master gave it; any other attempt first tells the
 * QR2 server browser the peer's address, port and NAT-negotiation session.
 * Retries the send up to five times while the NAT-negotiation helpers the
 * transport needs are not ready yet (3). */
s32 StartPeerConnect(void *arg0) {
    ConnAttempt *attempt = (ConnAttempt *)arg0;
    s32 ReportMatchmakingResult();
    s32 GT2SocketHandle(s32);
    s32 gt2AddressToString(s32, M2C_UNK, M2C_UNK);
    s32 NatNeg_BeginNegotiation(s32, s32, u8, M2C_UNK *, M2C_UNK *, void *);
    M2C_UNK func_02061690(s32, s32, u16, s32);
    extern M2C_UNK func_02043e0c;
    void OnPeerConnect(s32,s32,s32,void *);
    s32 result;
    s32 retries;
    void *connection;

    if (attempt->isJoin == 0) {
        connection = GetConnection();
        func_02061690(M2C_FIELD(connection, s32 *, CONN_SESSION_SERVER_BROWSER), gt2AddressToString(attempt->address, 0, 0), attempt->port, attempt->natNeg);
        if (ReportMatchmakingResult() != 0) {
            return 2;
        }
    }
    retries = 0;
loop_4:
    result = NatNeg_BeginNegotiation(GT2SocketHandle(*M2C_FIELD(GetConnection(), s32 **, CONN_SESSION_GT2_SOCKET)), attempt->natNeg, attempt->isJoin, &func_02043e0c, (M2C_UNK *)&OnPeerConnect, attempt);
    if (result == 0) {
        return result;
    }
    if (result != 3) {
        return result;
    }
    retries += 1;
    if (retries >= 5) {
        return result;
    }
    goto loop_4;
}

/* Send a connection command: build its payload from the value list and either
   hand it to the binary packet path (func_0203f20c) or format it as a text
   message and pass it to the connection's send callback; for commands 2, 6, 8
   and 9 record the command, peer, port, payload and time so it can be resent. */
s32 SendConnectionCommand(u8 command, s32 peerId, s32 address, u16 port, s32 *values, s32 count) {
    void SendConnectionTextCommand(M2C_UNK,s32,M2C_UNK,u8 *);
    s32 func_0203f20c(s32,s32,s32,s32,s32);
    void MIi_CpuCopy32(s32,void *,s32);
    M2C_UNK StringFormatN();
    void MI_CpuCopy8(u8 *,u8 *,u32);
    u64 GetSystemTick(void);
    extern M2C_UNK data_020fc908, data_020fc9fc;
    u8 message[0x200];
    u8 valueText[0x10];
    s32 length=0, i, partLength, result;
    void *conn;
    if (M2C_FIELD(GetConnection(),u8 *,0x15) == 0 ||
        ( (M2C_FIELD(GetConnection(),u8 *,0x15) == 3 ||
        M2C_FIELD(GetConnection(),u8 *,0x1a6) != 0) && command == 6)) {
        result=func_0203f20c(command,address,port,(s32)values,count);
    } else {
        if (values != 0 && count != 0) {
            length=StringFormatN(message,0x200,&data_020fc908,values[0]);
            for(i=1;i<count;i++){
                partLength=StringFormatN(valueText,0x10,&data_020fc9fc,values[i]);
                MI_CpuCopy8(valueText,message+length,partLength);
                length+=partLength;
            }
        }
        message[length]=0;
        result=((s32 (*)())SendConnectionTextCommand)(M2C_FIELD(GetConnection(),s32 *,0),command,peerId,message);
    }
    if(command==2 || command==6 || (u8)(command+0xf8)<=1) {
        M2C_FIELD(GetConnection(),u8 *,0x3cc)=command;
        M2C_FIELD(GetConnection(),u16 *,0x3ce)=port;
        M2C_FIELD(GetConnection(),s32 *,0x3d0)=address;
        M2C_FIELD(GetConnection(),s32 *,0x454)=peerId;
        M2C_FIELD(GetConnection(),s32 *,0x458)=count;
        conn=GetConnection();
        M2C_FIELD(conn,u64 *,0x45c)=GetSystemTick();
        if(values!=0 && count!=0)MIi_CpuCopy32((s32)values,(u8 *)GetConnection()+0x3d4,count*4);
    }
    return result;
}

s32 func_0203f20c(s32 command, s32 dest, s32 mode, s32 payload, s32 count) {
    void MIi_CpuCopy32(s32, void *, s32);
    void *GetConnection(void);
    s32 gt2AddressToString(s32, s32, s32);
    s32 func_02061638(s32, s32, s32, void *, s32);
    extern PacketTag5 sQr2MatchCommandMagic;
    SendPacket packet;
    u8 e, d, c, b, a;
    u8 *tag;
    s32 i, result;
    void *context;
    if (payload != 0 && count != 0) {
        MIi_CpuCopy32(payload, packet.payload, count * 4);
    } else {
        count = 0;
    }
    count *= 4;
    tag = (u8 *)&packet;
    e = sQr2MatchCommandMagic.e;
    a = sQr2MatchCommandMagic.a;
    b = sQr2MatchCommandMagic.b;
    c = sQr2MatchCommandMagic.c;
    d = sQr2MatchCommandMagic.d;
    tag[4] = e;
    tag[0] = a;
    tag[1] = b;
    tag[2] = c;
    tag[3] = d;
    packet.kind = 3;
    packet.command = command;
    packet.length = count;
    packet.id = M2C_FIELD(GetConnection(), u16 *, 0x1a);
    packet.value = M2C_FIELD(GetConnection(), s32 *, 0x1c);
    packet.state = M2C_FIELD(GetConnection(), s32 *, 0x200);
    for (i = 0; i < 5; i++) {
        context = GetConnection();
        result = func_02061638(M2C_FIELD(context, s32 *, 0xe4), gt2AddressToString(dest, 0, 0), mode, tag, packet.length + 20);
        if (result == 0) {
            return result;
        }
        if (result != 2) {
            return result;
        }
    }
    return result;
}

#pragma opt_common_subs off
#pragma opt_instruction_scheduling off
/* Text form of a connection command (the binary form is func_0203f20c): build the
 * peer message header from the tag, the protocol version and the kind, insert the
 * command byte and append the message text, then queue the message for the peer. */
void SendConnectionTextCommand(M2C_UNK gpi,s32 command,M2C_UNK peerId,u8 *text) {
M2C_UNK StringFormatN(); s32 StringLength(u8*); void MI_CpuCopy8(u8*,u8*,u32); void gpiSendTextToPlayer(M2C_UNK,M2C_UNK,M2C_UNK);
extern M2C_UNK sGpcmMessageFormat,sGpcmMessageTag,sGpcmMessageKind;
char message[512]; s32 headerLength; u8 *append;
headerLength=StringFormatN((M2C_UNK)message,512,(M2C_UNK)&sGpcmMessageFormat,(M2C_UNK)&sGpcmMessageTag,3,(M2C_UNK)&sGpcmMessageKind);
message[headerLength]=command; append=(u8*)(message+1);append[headerLength]=0;append+=headerLength;
if(text){s32 textLength=StringLength(text);MI_CpuCopy8(text,append,textLength);append[textLength]=0;}
gpiSendTextToPlayer(gpi,peerId,(M2C_UNK)message);
}
#pragma opt_instruction_scheduling reset
#pragma opt_common_subs reset
/* Copy the `index`-th '/'-separated field of `text` into `dest`, terminate it and
 * return its length; -1 when that field does not exist or is empty. */
s32 ExtractSlashField(u8 *dest, u8 *text, s32 index) {
    s8 *StringFindChar(s8 *, s32);
    void MI_CpuCopy8(u8 *, u8 *, u32);
    u8 *field = text;
    u8 *end = (u8 *)StringFindChar((s8 *)text, 0);
    s32 count = 0;
    if (index > 0) {
        s8 *slash;
        do {
            slash = StringFindChar((s8 *)field, '/');
            if (slash == 0) {
                return -1;
            }
            count += 1;
            field = (u8 *)slash + 1;
        } while (count < index);
    }
    {
        u8 *fieldEnd = (u8 *)StringFindChar((s8 *)field, '/');
        if (fieldEnd == 0) {
            fieldEnd = end;
        }
        if (field == fieldEnd) {
            return -1;
        }
        {
            s32 length = (s32)(fieldEnd - field);
            MI_CpuCopy8(field, dest, length);
            dest[length] = 0;
            return length;
        }
    }
}

