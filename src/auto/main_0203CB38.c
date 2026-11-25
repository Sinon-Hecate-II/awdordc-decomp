/* 3 functions from 0x0203CB38 to 0x0203D910 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 a, b; u16 c; s32 d; } UnkPacket;
extern u8 gNatNegMagic[8];
extern char data_020fc920[12];
extern char data_020fc92c[12];
extern char data_020fc938[24];
void CpuFill(int, void *, int);
void *GetConnection(void);
void HandleNatNegPacket(void *, int, void *);
void Qr2_HandlePacket(int, void *, int, void *);
int ByteCompareN(void *, void *, int);

extern u8 gConnectionMgr[];
void OnPeerConnect(s32,s32,s32,void *);
s32 SBServerListThink(s32);
s32 DestroyServerBrowser(s32);
s32 SBServerListGetStatus(s32);
void Qr2_ServiceConnection(s32);
void NatNeg_Think(void);
void NatNeg_Shutdown(void);
s32 StartMatchmaking(void);
s32 UpdateConnectionSyncWait(void);
s32 UpdateConnectionSyncTimers(void);
void UpdateConnectionSync(void);
void ReportGpiSessionStatus(void);
void func_0203cb38(void *arg0) {
    void *GetConnection(void);
    s32 HasNetError(void);
    u64 GetSystemTick(void);
    u64 U64Divide(u64, u64);
    s32 Qr2_Think(s32);
    s32 gti2SocketThink(s32);
    s32 SendJoinRequest(s32, s32);
    s32 ReportConnectionCommandResult(void);
    s32 StartConnection(s32);
    s32 RestartConnection(s32);
    s32 func_02040e1c(s32);
    s32 SendMatchmakingParameter(s32);
    s32 ReportMatchmakingResult(s32);
    s32 ReconnectUnlessServing(void);
    void func_0203dc18(void);
    void ReportConnectionError(s32, s32);
    s32 SendConnectionCommand(u8, s32, s32, u16, s32 *, s32);
    s32 GetNetSessionState(void);
    void *timerState;
    void *limitState;
    u64 now;
    u64 elapsed;
    u32 timeout;

    if (GetConnection() == 0) return;
    if (HasNetError()) return;
    if (arg0 == 0) {
        if (M2C_FIELD(GetConnection(), s32 *, 0x10))
            Qr2_Think(M2C_FIELD(GetConnection(), s32 *, 0x10));
        if (M2C_FIELD(GetConnection(), s32 *, 0x4) == 0) return;
        gti2SocketThink(M2C_FIELD(M2C_FIELD(GetConnection(), s32 *, 0x4), s32 *, 0));
        return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 0) return;
    switch (M2C_FIELD(GetConnection(), s32 *, 0x1a0)) {
    case 4:
        if (M2C_FIELD(GetConnection(), u32 *, 0x1c8) != 0) {
            now = GetSystemTick();
            timerState=GetConnection();
            limitState=GetConnection();
            if (U64Divide((now - M2C_FIELD(timerState, u64 *, 0x1cc)) << 6, 0x82ea) > M2C_FIELD(limitState, u32 *, 0x1c8)) {
                M2C_FIELD(GetConnection(), s32 *, 0x1c8) = 0;
                if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 3) {
                    M2C_FIELD(GetConnection(), u8 *, 0x1aa)++;
                    if (M2C_FIELD(GetConnection(), u8 *, 0x1aa) > 5) {
                        ReportConnectionError(6, (s32)0xfffec5d2);
                        return;
                    }
                    SendJoinRequest(M2C_FIELD(GetConnection(), s32 *, 0xf4), 0);
                    if (ReportConnectionCommandResult()) return;
                } else {
                    if (StartConnection(0) == 0) return;
                }
            }
        }
        /* fall through */
    retry_join:
        if (M2C_FIELD(GetConnection(), s32 *, 0x1bc) == 0) break;
        timeout = M2C_FIELD(GetConnection(), u8 *, 0xd) * 3000 + 3000;
        now = GetSystemTick();
        elapsed = U64Divide((now - M2C_FIELD(GetConnection(), u64 *, 0x1c0)) << 6, 0x82ea);
        if (elapsed < timeout) break;
        SendJoinRequest(M2C_FIELD(GetConnection(), s32 *, 0xf4), 0);
        if (ReportConnectionCommandResult()) return;
        break;
    case 2:
    case 3:
    case 5:
        if (M2C_FIELD(GetConnection(), s32 *, 0xe8) <= 0) break;
        if (M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 3)
            timeout = (u32)M2C_FIELD(GetConnection(), u8 *, 0xd) * 3000 + 3000;
        else if (M2C_FIELD(GetConnection(), s32 *, 0xe8) == 1)
            timeout = 1000;
        else
            timeout = 3000;
        now = GetSystemTick();
        elapsed = U64Divide((now - M2C_FIELD(GetConnection(), u64 *, 0xec)) << 6, 0x82ea);
        if (elapsed <= timeout) break;
        if (ReportMatchmakingResult(SendMatchmakingParameter(M2C_FIELD(GetConnection(), s32 *, 0x204)))) return;
        M2C_FIELD(GetConnection(), s32 *, 0xe8) = 0;
        break;
    case 7:
        if (M2C_FIELD(GetConnection(), u64 *, 0x18c)) {
            now = GetSystemTick();
            if (U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x18c))<<6,0x82ea)>25000) {
                M2C_FIELD(GetConnection(),u64 *,0x18c)=0;
                if (!RestartConnection(M2C_FIELD(GetConnection(),s32 *,0xf4))) return;
            }
            break;
        }
        if (M2C_FIELD(GetConnection(),u8 *,0x3cc)!=6) break;
        now=GetSystemTick();
        if(U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x45c))<<6,0x82ea)<=6000) break;
        M2C_FIELD(GetConnection(),u8 *,0x3cd)++;
        if(M2C_FIELD(GetConnection(),u8 *,0x3cd)>5) {
            func_0203dc18();
            if(!RestartConnection(M2C_FIELD(GetConnection(),s32 *,0xf4)))return;
        } else {
            SendConnectionCommand(6,M2C_FIELD(GetConnection(),s32 *,0x454),M2C_FIELD(GetConnection(),s32 *,0x3d0),M2C_FIELD(GetConnection(),u16 *,0x3ce),(s32 *)((u8 *)GetConnection()+0x3d4),M2C_FIELD(GetConnection(),s32 *,0x458));
            if(ReportConnectionCommandResult())return;
        }
        break;
    case 11:
        if(M2C_FIELD(GetConnection(),u8 *,0x3cc)!=2) break;
        if ((M2C_FIELD(GetConnection(),u8 *,0x15)==0 &&
            (now=GetSystemTick(),U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x45c))<<6,0x82ea)>6000)) ||
            (M2C_FIELD(GetConnection(),u8 *,0x15)!=0 &&
            (now=GetSystemTick(),U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x45c))<<6,0x82ea)>19000))) {
            func_0203dc18();
            if(!func_02040e1c(M2C_FIELD((u8 *)GetConnection()+((M2C_FIELD(GetConnection(),u8 *,0xd)+1)<<2),s32 *,0xf4))) return;
        }
        break;
    case 13:
        if(M2C_FIELD(GetConnection(),u8 *,0x3cc)!=8)break;
        now=GetSystemTick();
        if(U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x45c))<<6,0x82ea)<=30000)break;
        M2C_FIELD(GetConnection(),u8 *,0x3cd)++;
        if(M2C_FIELD(GetConnection(),u8 *,0x3cd)!=0) {
            func_0203dc18();
            if(M2C_FIELD(GetConnection(),u8 *,0x15)==2) {
                if(!func_02040e1c(M2C_FIELD((u8 *)GetConnection()+(M2C_FIELD(GetConnection(),u8 *,0xd)<<2),s32 *,0xf4)))return;
            } else ReconnectUnlessServing();
        } else {
            SendConnectionCommand(8,M2C_FIELD(GetConnection(),s32 *,0x454),M2C_FIELD(GetConnection(),s32 *,0x3d0),M2C_FIELD(GetConnection(),u16 *,0x3ce),(s32 *)((u8 *)GetConnection()+0x3d4),M2C_FIELD(GetConnection(),s32 *,0x458));
            if(ReportConnectionCommandResult())return;
        }
        break;
    case 1:
        if(GetNetSessionState()!=5)break;
        now=GetSystemTick();
        if(U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x1f8))<<6,0x82ea)<=30000)break;
        if(M2C_FIELD(GetConnection(),u8 *,0x1ad)>=5) {
            if(!RestartConnection(M2C_FIELD(GetConnection(),s32 *,0xf4)))return;
        } else {
            SendConnectionCommand(0x40,M2C_FIELD(GetConnection(),s32 *,0xf4),M2C_FIELD(GetConnection(),s32 *,0x24),M2C_FIELD(GetConnection(),u16 *,0xa4),0,0);
            if(ReportConnectionCommandResult())return;
            M2C_FIELD(GetConnection(),u8 *,0x1ad)++;
            M2C_FIELD(GetConnection(),u64 *,0x1f8)=GetSystemTick()-(u64)12567750;
        }
        break;
    default:
        break;
    }

    if(M2C_FIELD(GetConnection(),s32 *,0x1a0)==11 || M2C_FIELD(GetConnection(),s32 *,0x1a0)==6) {
        if(M2C_FIELD(GetConnection(),u64 *,0x184)) {
            now=GetSystemTick();
            if(U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x184))<<6,0x82ea)>10000)
                OnPeerConnect(1,0,0,(u8 *)GetConnection()+0x194);
        }
    }
    if(M2C_FIELD(GetConnection(),s32 *,0xe4)) {
        M2C_FIELD(gConnectionMgr,s32 *,0x18)=0;
        M2C_FIELD(gConnectionMgr,s32 *,0x14)=0;
        SBServerListThink(M2C_FIELD(GetConnection(),s32 *,0xe4));
        if(M2C_FIELD(gConnectionMgr,s32 *,0x14)) {
            DestroyServerBrowser(M2C_FIELD(GetConnection(),s32 *,0xe4));
            M2C_FIELD(GetConnection(),s32 *,0xe4)=0;
        }
        if(M2C_FIELD(GetConnection(),s32 *,0xe4) &&
           SBServerListGetStatus(M2C_FIELD(GetConnection(),s32 *,0xe4)) &&
           M2C_FIELD(GetConnection(),u64 *,0x174)) {
            now=GetSystemTick();
            if(now>M2C_FIELD(GetConnection(),u64 *,0x174))ReportConnectionError(6,0xfffeb3ee);
        }
    }
    Qr2_ServiceConnection(M2C_FIELD(GetConnection(),s32 *,0x10));
    M2C_FIELD(gConnectionMgr,s32 *,0xc)=0;
    M2C_FIELD(gConnectionMgr,s32 *,0x10)=1;
    NatNeg_Think();
    M2C_FIELD(gConnectionMgr,s32 *,0x10)=0;
    if(M2C_FIELD(gConnectionMgr,s32 *,0xc)==1) {
        M2C_FIELD(gConnectionMgr,s32 *,0xc)=0;
        NatNeg_Shutdown();
    }
    if(M2C_FIELD(GetConnection(),s32 *,4))
        gti2SocketThink(M2C_FIELD(M2C_FIELD(GetConnection(),s32 *,4),s32 *,0));
    if(M2C_FIELD(GetConnection(),s32 *,0x1a0)==18) {
        now=GetSystemTick();
        if(U64Divide((now-M2C_FIELD(GetConnection(),u64 *,0x1f0))<<6,0x82ea)>3000 && StartMatchmaking())return;
    }
    if(!UpdateConnectionSyncWait())return;
    if(!UpdateConnectionSyncTimers())return;
    UpdateConnectionSync();
    if(!M2C_FIELD(GetConnection(),u8 *,0x1ae))return;
    if(M2C_FIELD(GetConnection(),s32 *,0x1a0)!=10)return;
    M2C_FIELD(GetConnection(),u8 *,0x16)=M2C_FIELD(GetConnection(),u8 *,0xd);
    ReportGpiSessionStatus();
    M2C_FIELD(GetConnection(),u8 *,0x1ae)=0;
    if(M2C_FIELD(GetConnection(),s32 *,0x47c))
        M2C_FIELD(GetConnection(),void (**)(s32),0x47c)(M2C_FIELD(GetConnection(),s32 *,0x480));
}

/* Routes one incoming GameSpy datagram: query/QR2 packets (leading 0x5c, or the
 * 0xfe 0xfd header tail) go to the QR2 handler on the connection object, NAT-negotiation
 * packets go to HandleNatNegPacket, and anything else is dropped. The 8-byte
 * reply header carries the datagram's source port and address. */
s32 RouteIncomingGameSpyPacket(s32 unused, s32 sourceAddress, s32 sourcePort, u8 *packet, s32 length) {
    UnkPacket header;
    u8 lead;
    if (!length || !packet) return 0;
    CpuFill(0,&header,8);
    header.b=2;
    header.c=(u8)(sourcePort>>8)|((sourcePort<<8)&0xff00); /* u16 in network order */
    header.d=sourceAddress;
    lead=packet[0];
    if ((lead==0xfe && packet[1]==0xfd)||lead==0x5c) {
        if (M2C_FIELD(GetConnection(),s32 *,0x10))
            Qr2_HandlePacket(M2C_FIELD(GetConnection(),s32 *,0x10),packet,length,&header);
    } else if (!ByteCompareN(packet,gNatNegMagic,6)) {
        HandleNatNegPacket(packet,length,&header);
    } else {
        switch(lead) { case 0xfe: break; default: return 0; }
        return 0;
    }
    return 1;
}

void HandleGt2ConnectAttempt(s32 unused, s32 connectionArg, s32 remoteAddressArg, s32 remotePortArg, s32 latency, u8 *requestMessage) {
    void *GetConnection(void);
    s32 FindFreePlayerSlot(void);
    void func_0205adc0(s32, void *, s32);
    void ReportConnectionError(s32, s32);
    void func_0203dc18(void);
    void *GetPlayerConnectionSlot(s32);
    void *GetPlayerPeer(s32);
    s32 func_0205adb4(s32, s32);
    s32 strtoul(void *, s32, s32);
    void gt2SetConnectionData(void *, s32);
    void func_020411dc(s32);

    s32 connection = connectionArg;
    s32 remoteAddress = remoteAddressArg;
    s32 remotePort = remotePortArg;
    void *matchState;
    s32 connectionSlot;
    void *entry;
    void *profileState;
    s32 peerIndex;
    s32 profileId;

    /* Validate an incoming connection, then accept it and register its peer metadata. */
    (void)unused;
    matchState = GetConnection();
    if (matchState == 0) goto reject_state;
    matchState = GetConnection();
    if (M2C_FIELD(matchState, s32 *, 0x1a0) != 7) goto reject_state;
    matchState = GetConnection();
    if (M2C_FIELD(matchState, u8 *, 0x1a9) != 0) goto reject_state;
    goto find_slot;

reject_state:
    func_0205adc0(connection, data_020fc920, -1);
    return;

find_slot:
    connectionSlot = FindFreePlayerSlot();
    if (connectionSlot == -1) {
        func_0205adc0(connection, data_020fc92c, -1);
        ReportConnectionError(6, (s32)0xfffeabc4);
        return;
    }
    entry = GetConnection();
    matchState = GetConnection();
    peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
    if (remoteAddress != *(s32 *)((u8 *)entry + (peerIndex << 2) + 0x210)) goto check_profile;
    entry = GetConnection();
    matchState = GetConnection();
    peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
    if (remotePort != *(u16 *)((u8 *)entry + (peerIndex << 1) + 0x200 + 0x90)) goto check_profile;
    goto accept_connection;

check_profile:
    if (requestMessage[0] != 0) {
        profileId = strtoul(requestMessage, 0, 10);
        profileState = GetConnection();
        matchState = GetConnection();
        peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
        if (profileId == *(s32 *)((u8 *)profileState + (peerIndex << 2) + 0xf4)) {
            entry = GetConnection();
            matchState = GetConnection();
            peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
            *(s32 *)((u8 *)entry + (peerIndex << 2) + 0x210) = remoteAddress;
            entry = GetConnection();
            matchState = GetConnection();
            peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
            *(u16 *)((u8 *)entry + (peerIndex << 1) + 0x200 + 0x90) = (u16)remotePort;
            goto accept_connection;
        }
    }
    func_0205adc0(connection, data_020fc938, -1);
    return;

accept_connection:
    matchState = GetConnection();
    M2C_FIELD(matchState, s32 *, 0x18c) = 0;
    M2C_FIELD(matchState, s32 *, 0x190) = 0;
    matchState = GetConnection();
    if (func_0205adb4(connection, M2C_FIELD(matchState, s32 *, 0x08)) == 0) {
        ReportConnectionError(6, (s32)0xfffec5e6);
        return;
    }
    func_0203dc18();
    matchState = GetConnection();
    peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
    if (peerIndex == 0) {
        s32 halfLatency = latency >> 1;
        if (halfLatency >= 0xffff) halfLatency = 0xffff;
        matchState = GetConnection();
        *(u16 *)((u8 *)matchState + 0x100 + 0xb0) = (u16)halfLatency;
    }
    {
        void *connectionEntry = GetPlayerConnectionSlot(connectionSlot);
        void *peerMetadata;
        peerMetadata = GetPlayerPeer(connectionSlot);
        *(u32 *)connectionEntry = (u32)connection;
        entry = peerMetadata;
        matchState = GetConnection();
        peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
        M2C_FIELD(matchState, u8 *, 0x0d) = (u8)(peerIndex + 1);
        *(u8 *)entry = (u8)connectionSlot;
        matchState = GetConnection();
        {
            void *countState = GetConnection();
            s32 peerCount = M2C_FIELD(countState, u8 *, 0x0d);
            void *peerState = (void *)((u8 *)matchState + (peerCount - 1));
            u8 peerId = *(u8 *)((u8 *)peerState + 0x2d0);
            *(u8 *)((u8 *)entry + 1) = peerId;
        }
        *(u16 *)((u8 *)entry + 2) = 0;
        *(s32 *)((u8 *)entry + 4) = 0;
    }
    gt2SetConnectionData((void *)connection, (s32)entry);
    func_020411dc(2);
    return;
}

