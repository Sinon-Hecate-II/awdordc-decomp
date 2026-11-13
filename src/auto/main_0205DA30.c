/* 20 functions from 0x0205DA30 to 0x0205E95C (main), found by ds-decomp. */
#include "common.h"
#include "natneg.h"
#include "qr2.h"

typedef struct { u8 bytes[6]; } NetworkAddress6;
typedef struct { NetworkAddress6 address; u8 type,length; u32 ip; u8 reserved,value,flag,addr[4],port[2]; char name[64]; } NetworkHandshakePacket;
typedef struct { u8 bytes[20]; } NetworkPacket20Bytes;
typedef struct { NetworkAddress6 address; u8 type, length; u32 ip, value; u16 port; u8 flag, mode; } NetworkPacket20;
typedef struct { u8 bytes[21]; } NetworkPacket21Bytes;
typedef struct { NetworkAddress6 address; u8 type, length; u32 ip; u8 reserved, value; u8 tail[7]; } NetworkPacket21;
extern NetworkAddress6 gNatNegMagic;

#pragma opt_propagation off
void func_0205dc78(void *arg0) {
    void func_0205d944(s32, s32, u16, void *, s32);
    s32 GetTickCountMs(void);
    extern NetworkAddress6 gNatNegMagic;
    u8 sp04[0x14];

    register u8 *pr1 asm("r1") = (u8 *)&gNatNegMagic;
    register s32 vr2 asm("r2");
    register u8 vr7 asm("r7");
    register u8 vr6 asm("r6");
    register u8 *vr8 asm("r8") = sp04;
    register u8 vr5 asm("r5");
    register u8 vlr asm("lr");
    register u8 vr12 asm("r12");
    register u8 vr3 asm("r3");
    register void *vr4 asm("r4");

    vr7 = pr1[0];
    vr6 = pr1[1];
    vr5 = pr1[2];
    vlr = pr1[3];
    vr12 = pr1[4];
    vr3 = pr1[5];
    vr4 = arg0;

    *vr8 = vr7;
    vr8[1] = vr6;
    vr8[2] = vr5;
    vr8[3] = vlr;
    vr8[4] = vr12;
    vr2 = 2;
    pr1 = (u8 *)7;
    sp04[6] = (u8)vr2;
    sp04[7] = (u8)pr1;
    vr8[5] = vr3;

    {
        u32 ip = M2C_FIELD(vr4, u32 *, 8);
        *(u32 *)(sp04 + 8) =
            ((ip >> 24) & 0xFFU) |
            ((ip >> 8) & 0xFF00U) |
            ((ip << 8) & 0xFF0000U) |
            ((ip << 24) & 0xFF000000U);
    }
    *(u32 *)(sp04 + 12) = M2C_FIELD(vr4, u32 *, 0x2C);
    {
        u16 port = M2C_FIELD(vr4, u16 *, 0x30);
        *(u16 *)(sp04 + 16) = (u16)((((s32)port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
    }
    sp04[18] = M2C_FIELD(vr4, u8 *, 0x32);
    sp04[19] = (M2C_FIELD(vr4, s32 *, 0x10) != 2) ? 1 : 0;

    {
        s32 val = M2C_FIELD(vr4, s32 *, 4);
        if (val == -1) {
            val = M2C_FIELD(vr4, s32 *, 0);
        }
        func_0205d944(val, M2C_FIELD(vr4, s32 *, 0x2C), M2C_FIELD(vr4, u16 *, 0x30), sp04, 0x14);
    }
    M2C_FIELD(vr4, s32 *, 0x28) = GetTickCountMs() + 0x2BC;
    M2C_FIELD(vr4, s32 *, 0x24) = 0xC;
    if (M2C_FIELD(vr4, u8 *, 0x32) != 0) {
        M2C_FIELD(vr4, s8 *, 0x33) = 1;
    }
}
#pragma opt_propagation reset
s32 func_0205dd98(M2C_UNK arg0) {
    void *ghiResolveHostname(M2C_UNK);
    s32 func_020498e4();
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0_2 = func_020498e4();
    if (temp_r0_2 != -1) {
        return temp_r0_2;
    }
    temp_r0 = ghiResolveHostname(arg0);
    if (temp_r0 == NULL) {
        return 0;
    }
    return **M2C_FIELD(temp_r0, s32 ***, 0xC);
}

s32 func_0205ddd0(void *arg0, s32 arg1) {
 M2C_UNK func_020675bc(void *,s32,void *,void *,s32);
 extern M2C_UNK data_020ff894, gServiceNameBuffer;
 u8 buffer[0x80];
 if (arg0 == NULL) {
 func_020675bc(buffer,0x80,&data_020ff894,&gServiceNameBuffer,arg1);
 arg0=buffer;
 }
 return func_0205dd98((M2C_UNK)arg0);
}

s32 func_0205de10(void) {
 extern M2C_UNK gNatNegManager, data_020ff89c, data_020ff8b8;
 if (M2C_FIELD(&gNatNegManager,s32 *,12)==0)
 M2C_FIELD(&gNatNegManager,s32 *,12)=func_0205ddd0(M2C_FIELD(&gNatNegManager,void **,4),(s32)&data_020ff89c);
 if (M2C_FIELD(&gNatNegManager,s32 *,8)==0)
 M2C_FIELD(&gNatNegManager,s32 *,8)=func_0205ddd0(M2C_FIELD(&gNatNegManager,void **,0),(s32)&data_020ff8b8);
 if(M2C_FIELD(&gNatNegManager,s32 *,12)==0 || M2C_FIELD(&gNatNegManager,s32 *,8)==0) return 0;
 return 1;
}

#pragma scheduling off
s32 func_0205de88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 ghiSocket(s32, s32, s32);
    void *func_0205d7f4();
    M2C_UNK func_0205d88c();
    void func_0205da30();
    s32 func_0205de10();
    extern s32 gDnsQueryState;
    void *temp_r0;

    if (gDnsQueryState != 1) {
        return 2;
    }
    if (func_0205de10() == 0) {
        return 3;
    }
    temp_r0 = func_0205d7f4();
    if (temp_r0 == NULL) {
        return 1;
    }
    M2C_FIELD(temp_r0, s32 *, 4) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg2;
    M2C_FIELD(temp_r0, s32 *, 8) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg4;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg5;
    M2C_FIELD(temp_r0, s32 *, 0) = ghiSocket(2, 2, 0);
    M2C_FIELD(temp_r0, s32 *, 0x20) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x32) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x33) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x30) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    if (M2C_FIELD(temp_r0, s32 *, 0) == -1) {
        func_0205d88c();
        return 2;
    }
    func_0205da30();
    return 0;
}
#pragma scheduling reset
void func_0205df50(void) {
 void *FindNatNegPeer(void);
 void func_020496b8(s32);
 void *p=FindNatNegPeer();
 if(p==NULL)return;
 if(M2C_FIELD(p,s32 *,0)!=-1) func_020496b8(M2C_FIELD(p,s32 *,0));
 M2C_FIELD(p,s32 *,0)=-1;
 M2C_FIELD(p,s32 *,16)=4;
}

/* Polls one NAT-negotiation peer: drains its socket, retries the current step
   when the deadline passes, and releases the peer on completion or timeout. */
void UpdateNatNegPeer(void *peer) {
s32 func_0205d88c(); s32 func_02049534(s32); s32 func_020497e0(s32,void *,s32,s32,void *,s32 *); void HandleNatNegPacket(u8 *,s32,M2C_UNK); s32 GetTickCountMs(void); void func_0205da30(); void func_0205dc78(void *);
extern u8 gNatNegRecvBuffer[];
u8 address[8]; s32 size=8; u8 reply[8]; s32 n;
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_DONE){func_0205d88c(peer);return;}
if(-1!=M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)){
do {
if(!func_02049534(M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)))break;
n=func_020497e0(M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET),gNatNegRecvBuffer,512,0,address,&size);
if(n==-1)break;
HandleNatNegPacket(gNatNegRecvBuffer,n,(M2C_UNK)address);
} while(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)!=NATNEG_STATE_DONE && M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)!=-1);
}
if((M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_START || M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_CONNECT) && (u32)GetTickCountMs()>M2C_FIELD(peer,u32 *,NATNEG_PEER_DEADLINE)){
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_RETRIES)>M2C_FIELD(peer,s32 *,NATNEG_PEER_MAX_RETRIES)){
M2C_FIELD(peer,M2C_UNK (**)(s32,s32,void *,s32),NATNEG_PEER_SEND)(2,-1,0,M2C_FIELD(peer,s32 *,NATNEG_PEER_SEND_DATA));
((void (*)(s32))func_0205df50)(M2C_FIELD(peer,s32 *,NATNEG_PEER_ADDRESS));
}else{
M2C_FIELD(peer,s32 *,NATNEG_PEER_RETRIES)++;
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_START)((void (*)(void *))func_0205da30)(peer);else func_0205dc78(peer);
}
}
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_REPORT && (u32)GetTickCountMs()>M2C_FIELD(peer,u32 *,NATNEG_PEER_DEADLINE)){
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET2)==-1){
u16 port;
reply[1]=2;
port=M2C_FIELD(peer,u16 *,NATNEG_PEER_REMOTE_PORT);
*(u16 *)(reply+2)=((port>>8)&255)|((port<<8)&0xff00);
*(u32 *)(reply+4)=M2C_FIELD(peer,u32 *,NATNEG_PEER_REMOTE_IP);
M2C_FIELD(peer,M2C_UNK (**)(s32,s32,void *,s32),NATNEG_PEER_SEND)(0,M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET),reply,M2C_FIELD(peer,s32 *,NATNEG_PEER_SEND_DATA));
M2C_FIELD(peer,s32 *,NATNEG_PEER_SOCKET)=-1;
}
((void (*)(s32))func_0205df50)(M2C_FIELD(peer,s32 *,NATNEG_PEER_ADDRESS));
}
if(M2C_FIELD(peer,s32 *,NATNEG_PEER_STATE)==NATNEG_STATE_ACKED && (u32)GetTickCountMs()>M2C_FIELD(peer,u32 *,NATNEG_PEER_DEADLINE)){
M2C_FIELD(peer,M2C_UNK (**)(s32,s32,void *,s32),NATNEG_PEER_SEND)(1,-1,0,M2C_FIELD(peer,s32 *,NATNEG_PEER_SEND_DATA));
((void (*)(s32))func_0205df50)(M2C_FIELD(peer,s32 *,NATNEG_PEER_ADDRESS));
}
}

void func_0205e178(void) {
    s32 Vector_GetCount();
    M2C_UNK Vector_GetItem(s32, s32);
    void UpdateNatNegPeer();
    extern M2C_UNK gNatNegManager;
    s32 var_r5;

    if (M2C_FIELD(&gNatNegManager, s32 *, 0x10) == 0) {
        return;
    }
    var_r5 = Vector_GetCount() - 1;
    if (var_r5 < 0) {
        return;
    }
    do {
        Vector_GetItem(M2C_FIELD(&gNatNegManager, s32 *, 0x10), var_r5);
        UpdateNatNegPeer();
        var_r5 -= 1;
    } while (var_r5 >= 0);
}

M2C_UNK func_0205e1bc(void *arg0, M2C_UNK arg1) {
 void func_0205d944(s32,s32,u16,void *,s32);
 NetworkPacket21 packet;
 u16 port;
 u32 ip;
 packet.length=6;
 packet.address=gNatNegMagic;
 packet.type=2;
 packet.value=M2C_FIELD(arg0,s32 *,12);
 ip=M2C_FIELD(arg0,u32 *,8);
 packet.ip=((ip<<24)&0xff000000)|(((ip<<8)&0xff0000)|((u8)(ip>>24)|((ip>>8)&0xff00)));
 port=M2C_FIELD(arg1,u16 *,2);
 func_0205d944(M2C_FIELD(arg0,s32 *,0),M2C_FIELD(arg1,s32 *,4),(u16)((u8)((s32)port>>8)|((port<<8)&0xff00)),&packet,21);
 (void)packet;
}

void NatNeg_HandleConnectPing(void *arg0, void *arg1, M2C_UNK arg2) {
    void func_0205dc78(void *);
    M2C_UNK func_0205e1bc(void *, M2C_UNK);
    s32 var_r0; u16 temp_r2; u8 temp_r1;
    (void)arg2;
    if (M2C_FIELD(arg1, u8 *, 0x13) == 0) func_0205e1bc(arg0, arg2);
    if (M2C_FIELD(arg0, s32 *, 0x10) >= 2) return;
    temp_r1 = M2C_FIELD(arg1, u8 *, 0x13);
    if (temp_r1) {
        var_r0 = 3; if (temp_r1 == 1) var_r0 = 1; else if (temp_r1 == 2) var_r0 = 2;
        M2C_FIELD(arg0, M2C_UNK (**)(s32, s32, s32, s32), 0x38)(var_r0, -1, 0, M2C_FIELD(arg0, s32 *, 0x3C));
        ((void (*)(s32))func_0205df50)(M2C_FIELD(arg0, s32 *, 8)); return;
    }
    M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg1, s32 *, 0x0C);
    temp_r2 = M2C_FIELD(arg1, u16 *, 0x10);
    M2C_FIELD(arg0, s16 *, 0x30) = (s16)(((u8)(temp_r2 >> 8)) | ((temp_r2 << 8) & 0xFF00));
    M2C_FIELD(arg0, s32 *, 0x10) = 2; M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(s32, s32), 0x34)(2, M2C_FIELD(arg0, s32 *, 0x3C));
    func_0205dc78(arg0);
}

void NatNeg_HandleConnectPong(void *arg0, void *arg1, void *arg2) {
    s32 GetTickCountMs();
    void func_0205dc78(void *);
    s32 temp_r1;
    u16 temp_r3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x10) < 2) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg2, s32 *, 4);
    temp_r3 = M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(arg0, s16 *, 0x30) = (s16) ((u8) ((s32) temp_r3 >> 8) | ((temp_r3 << 8) & 0xFF00));
    M2C_FIELD(arg0, s8 *, 0x32) = 1;
    if (M2C_FIELD(arg1, u8 *, 0x12) == 0) {
        func_0205dc78(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) == 2) {
        if (M2C_FIELD(arg0, u8 *, 0x33) == 0) {
            func_0205dc78(arg0);
        }
        M2C_FIELD(arg0, s32 *, 0x10) = 3;
        M2C_FIELD(arg0, s32 *, 0x28) = (s32) (GetTickCountMs() + 0x1388);
        temp_r1 = M2C_FIELD(arg0, s32 *, 4);
        if (temp_r1 == -1) {
            return;
        }
        M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, s32, void *, s32), 0x38)(0, temp_r1, arg2, M2C_FIELD(arg0, s32 *, 0x3C));
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 0x13) != 0) {
        return;
    }
    func_0205dc78(arg0);
}

void NatNeg_HandleInitAndErt(void *arg0, void *arg1, void *arg2) {
    M2C_UNK GetTickCountMs(void);
    void func_0205d944(s32, s32, u16, void *, s32);
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg1, u8 *, 7);
    switch (temp_r1) {
        case 1: {
            u8 temp_r0 = M2C_FIELD(arg1, u8 *, 0xC);
            if ((u32)temp_r0 > 2U) {
                break;
            }
            M2C_FIELD((void *)((u8 *)arg0 + (temp_r0 * 4)), s32 *, 0x14) = 1;
            if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
                break;
            }
            if (M2C_FIELD(arg0, s32 *, 0x18) == 0) {
                break;
            }
            if (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
                break;
            }
            if (M2C_FIELD(arg0, s32 *, 4) != -1) {
                if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
                    break;
                }
            }
            M2C_FIELD(arg0, s32 *, 0x10) = 1;
            M2C_FIELD(arg0, s32 *, 0x28) = GetTickCountMs() + 0x2710;
            M2C_FIELD(arg0, void (**)(s32, s32), 0x34)(
                M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x3C));
            break;
        }
        case 2: {
            u16 port;
            u16 swapped;

            M2C_FIELD(arg1, u8 *, 7) = 3;
            port = M2C_FIELD(arg2, u16 *, 2);
            swapped = (u16)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
            func_0205d944(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg2, s32 *, 4),
                          swapped, arg1, 0x15);
            break;
        }
        default:
            break;
    }
}

/* Dispatches one received NAT-negotiation packet: checks the magic, copies the
   packet into a local 20- or 21-byte buffer according to its kind, looks the peer
   up by the (byte-swapped) source address and hands it to that kind's handler. */
void HandleNatNegPacket(u8 *packet,s32 length,M2C_UNK fromAddress) {
s32 IsNatNegPacket(M2C_UNK);
void *FindNatNegPeer(void);
u32 buf20[5];
u32 buf21[6];
s32 kind;
u32 sourceIp;
void *peer;
if(!IsNatNegPacket((M2C_UNK)packet))return;
kind=packet[7];
if(kind==NATNEG_KIND_CONNECT_PING||kind==NATNEG_KIND_CONNECT_PONG){
if(length<20)return;
*(NetworkPacket20Bytes *)buf20=*(NetworkPacket20Bytes *)packet;
sourceIp=*(u32 *)((u8 *)buf20+8);
peer=((void *(*)(u32))FindNatNegPeer)(((sourceIp>>24)&255)|((sourceIp>>8)&0xff00)|((sourceIp<<8)&0xff0000)|((sourceIp<<24)&0xff000000));
if(!peer)return;
if(kind==NATNEG_KIND_CONNECT_PING)NatNeg_HandleConnectPing(peer,&buf20,fromAddress);
else NatNeg_HandleConnectPong(peer,&buf20,fromAddress);
}else{
if(length<21)return;
*(NetworkPacket21Bytes *)buf21=*(NetworkPacket21Bytes *)packet;
sourceIp=*(u32 *)((u8 *)buf21+8);
peer=((void *(*)(u32))FindNatNegPeer)(((sourceIp>>24)&255)|((sourceIp>>8)&0xff00)|((sourceIp<<8)&0xff0000)|((sourceIp<<24)&0xff000000));
if(!peer)return;
NatNeg_HandleInitAndErt(peer,&buf21,fromAddress);
}
}

#pragma push
#pragma opt_strength_reduction off
/* Creates and fills a GameSpy QR2 connection record: allocates a 0x110-byte
 * record (or uses the static default when outConnection is NULL), stores the
 * socket, game/player names, local port, state callbacks and NAT-negotiation
 * flag, seeds the random local address bytes, refreshes the local IP list and
 * resolves the master server for the record's request id. Returns 0, or 3 when
 * the master server cannot be resolved. */
s32 Qr2_CreateConnection(u8 **outConnection, s32 socket, s32 localPort, s32 gameName, s32 playerName, s32 reportToMaster, s32 natNeg, s32 appendKeyCb, s32 appendIdx1Cb, s32 appendIdx2Cb, s32 collectKeysCb, s32 repeatCountCb, s32 eventCb, s32 context) {
    u8 *gpiMalloc(M2C_UNK);
    M2C_UNK GetTickCountMs();
    M2C_UNK RefreshLocalIps();
    s32 ResolveHostAddress(s8 *, s32, void *, M2C_UNK);
    M2C_UNK StringFormat(s8 *, M2C_UNK *, s32);
    s32 Rand();
    M2C_UNK SetRandSeed();
    M2C_UNK StringCopy(void *, s32);
    extern M2C_UNK gQr2DefaultConnection;
    extern M2C_UNK gMasterHostFormat;
    extern s32 gLocalIpCount;
    extern s8 gMasterHostOverride;
    s8 hostBuf[64];
    u8 *temp_r0;

    s32 result;
    s32 clearIndex;
    s32 byteIndex;
    u8 *qr2;
    s8 *hostName;
    s8 hostOverride;
    s32 rnd;
    void *temp_r0_3;
    void *cellPtr;

    if (outConnection == NULL) {
        qr2 = (u8 *)&gQr2DefaultConnection;
    } else {
        qr2 = *outConnection = gpiMalloc(0x110);
    }
    GetTickCountMs();
    SetRandSeed();
    StringCopy(qr2 + QR2_GAMENAME, gameName);
    StringCopy(qr2 + 0x44, playerName);
    M2C_FIELD(qr2, s32 *, QR2_LOCAL_PORT) = localPort;
    byteIndex = 0;
    M2C_FIELD(qr2, s32 *, QR2_LAST_SENT) = 0;
    M2C_FIELD(qr2, s32 *, QR2_LAST_POLL) = 0;
    M2C_FIELD(qr2, s32 *, QR2_SOCKET) = socket;
    M2C_FIELD(qr2, s32 *, 0xB8) = 1;
    M2C_FIELD(qr2, s32 *, QR2_CTX) = context;
    M2C_FIELD(qr2, s32 *, QR2_CB_APPEND_KEY) = appendKeyCb;
    M2C_FIELD(qr2, s32 *, QR2_CB_APPEND_IDX1) = appendIdx1Cb;
    M2C_FIELD(qr2, s32 *, QR2_CB_APPEND_IDX2) = appendIdx2Cb;
    M2C_FIELD(qr2, s32 *, QR2_CB_COLLECT_KEYS) = collectKeysCb;
    M2C_FIELD(qr2, s32 *, QR2_CB_REPEAT_COUNT) = repeatCountCb;
    M2C_FIELD(qr2, s32 *, 0x9C) = eventCb;
    M2C_FIELD(qr2, s32 *, 0xA0) = 0;
    M2C_FIELD(qr2, s32 *, 0xA4) = 0;
    M2C_FIELD(qr2, s32 *, 0xD4) = 0;
    M2C_FIELD(qr2, s32 *, 0xBC) = reportToMaster;
    M2C_FIELD(qr2, s32 *, 0xC4) = 0;
    M2C_FIELD(qr2, s32 *, QR2_NATNEG) = natNeg;
    M2C_FIELD(qr2, s32 *, QR2_PUBLIC_IP) = 0;
    M2C_FIELD(qr2, s16 *, QR2_PUBLIC_PORT) = 0;
    M2C_FIELD(qr2, s32 *, QR2_PUBLIC_VALID) = 0;
    M2C_FIELD(qr2, s32 *, QR2_STATE_DIRTY) = 0;
    do {
        rnd = Rand();
        cellPtr = qr2 + byteIndex;
        byteIndex += 1;
        M2C_FIELD(cellPtr, s8 *, QR2_LOCAL_IP) = rnd % 255;
    } while (byteIndex < 4);
    clearIndex = 0;
    do {
        ((s32 *)qr2)[clearIndex+54] = -1;
        clearIndex += 1;
    } while (clearIndex < 0xA);
    M2C_FIELD(qr2, s32 *, 0x100) = 0;
    if (gLocalIpCount == 0) {
        RefreshLocalIps();
    }
    if (reportToMaster != 0) {
        hostOverride = gMasterHostOverride;
        if (hostOverride == 0) {
            StringFormat(hostBuf, &gMasterHostFormat, gameName);
        }
        if (hostOverride != 0) {
            hostName = &gMasterHostOverride;
        } else {
            hostName = hostBuf;
        }
        result = ResolveHostAddress(hostName, 0x6CFC, qr2 + QR2_REQUEST_ID, 0);
    } else {
        result = 1;
    }
    if (result == 0) {
        return 3;
    }
    return 0;
}
#pragma pop
void func_0205e834(void *arg0, s32 arg1) {
    extern void *data_020ff8d4;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = data_020ff8d4;
    }
    M2C_FIELD(var_r0, s32 *, 0xA0) = arg1;
}

void func_0205e84c(void *arg0, s32 arg1) {
    extern void *data_020ff8d4;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = data_020ff8d4;
    }
    M2C_FIELD(var_r0, s32 *, 0xA4) = arg1;
}

void func_0205e864(void *arg0, s32 arg1) {
 extern void *data_020ff8d4;
 if (arg0 == NULL) arg0 = data_020ff8d4;
 M2C_FIELD(arg0,s32 *,0xA8)=arg1;
}

void func_0205e87c(void *p) {
 extern void *data_020ff8d4;
 void func_0205e95c(void *);
 void func_0205e8b0(void *);
 if(p==NULL)p=data_020ff8d4;
 if(M2C_FIELD(p,s32 *,0xbc))func_0205e95c(p);
 func_0205e8b0(p);
}

void func_0205e8b0(void *arg0) {
 s32 func_02049534(s32);
 s32 func_020497e0(s32,void *,s32,s32,void *,s32 *);
 void func_0205f83c(void *,void *,s32,void *);
 extern u8 data_0213e3b0[];
 u8 spC[8]; s32 sp8=8; s32 n;
 if(M2C_FIELD(arg0,s32 *,0xc4)==0)return;
 if(func_02049534(M2C_FIELD(arg0,s32 *,0))==0)return;
 do {
 n=func_020497e0(M2C_FIELD(arg0,s32 *,0),data_0213e3b0,255,0,spC,&sp8);
 if(n!=-1){data_0213e3b0[n]=0;func_0205f83c(arg0,data_0213e3b0,n,spC);}
 }while(func_02049534(M2C_FIELD(arg0,s32 *,0))!=0);
}
#pragma push
#pragma opt_propagation off
#pragma scheduling on
void func_0205da30(void *arg0) {
s32 func_0205d998(void); s32 func_0205d9fc(s32); s32 GetTickCountMs(void);
void func_0205d944(s32,s32,u16,void *,s32);
s32 StringCopy(void *,s32); s32 StringLength(void *);
extern M2C_UNK gServiceNameBuffer,gNatNegManager;
union { NetworkHandshakePacket header; u8 bytes[88]; } packet; NetworkHandshakePacket *p=&packet.header; u8 *buf=packet.bytes;
u32 ip,a,b,c,d;
s32 len,sock,pa,pb;
u16 port;
{
u8 a0=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[0],a1=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[1],a2=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[2],a3=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[3],a4=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[4],a5=((volatile NetworkAddress6 *)&gNatNegMagic)->bytes[5];
p->address.bytes[0]=a0;p->address.bytes[1]=a1;p->address.bytes[2]=a2;p->address.bytes[3]=a3;p->address.bytes[4]=a4;p->address.bytes[5]=a5;
p->length=0;
}
p->type=2;
p->value=M2C_FIELD(arg0,s32 *,12);
ip=M2C_FIELD(arg0,u32 *,8);
p->ip=((ip>>24)&255)|((ip>>8)&0xff00)|((ip<<8)&0xff0000)|((ip<<24)&0xff000000);
p->flag=M2C_FIELD(arg0,s32 *,4)!=(s32)(p->length-1);
a=func_0205d998();b=func_0205d998();c=func_0205d998();d=func_0205d998();
ip=((c>>24)&255)|((d>>8)&0xff00)|((b<<8)&0xff0000)|((a<<24)&0xff000000);
packet.bytes[15]=ip>>24;packet.bytes[16]=ip>>16;packet.bytes[17]=ip>>8;packet.bytes[18]=ip;
packet.bytes[19]=0;packet.bytes[20]=0;
StringCopy(packet.bytes+21,(s32)&gServiceNameBuffer);
len=StringLength(&gServiceNameBuffer)+22;
if(p->flag && M2C_FIELD(arg0,s32 *,20)==0){
buf[12]=0;func_0205d944(M2C_FIELD(arg0,s32 *,4),M2C_FIELD(&gNatNegManager,s32 *,12),0x6cfd,buf,len);
}
if(M2C_FIELD(arg0,s32 *,24)==0){
buf[12]=1;func_0205d944(M2C_FIELD(arg0,s32 *,0),M2C_FIELD(&gNatNegManager,s32 *,12),0x6cfd,buf,len);
}
sock=p->flag?M2C_FIELD(arg0,s32 *,4):M2C_FIELD(arg0,s32 *,0);
pa=func_0205d9fc(p->flag?M2C_FIELD(arg0,s32 *,4):M2C_FIELD(arg0,s32 *,0));
pb=func_0205d9fc(sock);
port=((pa>>8)&255)|((pb<<8)&0xff00);
packet.bytes[20]=port;packet.bytes[19]=port>>8;
if(M2C_FIELD(arg0,s32 *,28)==0){
buf[12]=2;func_0205d944(M2C_FIELD(arg0,s32 *,0),M2C_FIELD(&gNatNegManager,s32 *,8),0x6cfd,buf,len);
}
M2C_FIELD(arg0,s32 *,40)=GetTickCountMs()+500;
M2C_FIELD(arg0,s32 *,36)=30;

}
#pragma pop
