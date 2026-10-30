/* 3 functions from 0x0203CB38 to 0x0203D910 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 a, b; u16 c; s32 d; } UnkPacket;
extern u8 data_020ff88c[8];
extern char data_020fc920[12];
extern char data_020fc92c[12];
extern char data_020fc938[24];
void func_02007e54(int, void *, int);
void *func_02044268(void);
void func_0205e510(void *, int, void *);
void func_0205f83c(int, void *, int, void *);
int func_0206527c(void *, void *, int);

void func_0203cb38(void *arg0) { }

s32 func_0203d5d4(s32 unused, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    UnkPacket packet;
    u8 c;
    if (!arg4 || !arg3) return 0;
    func_02007e54(0,&packet,8);
    packet.b=2;
    packet.c=(u8)(arg2>>8)|((arg2<<8)&0xff00);
    packet.d=arg1;
    c=arg3[0];
    if ((c==0xfe && arg3[1]==0xfd)||c==0x5c) {
        if (M2C_FIELD(func_02044268(),s32 *,0x10))
            func_0205f83c(M2C_FIELD(func_02044268(),s32 *,0x10),arg3,arg4,&packet);
    } else if (!func_0206527c(arg3,data_020ff88c,6)) {
        func_0205e510(arg3,arg4,&packet);
    } else {
        if(c==0xfe) return 0;
        return 0;
    }
    return 1;
}

void func_0203d6c8(s32 unused, s32 connectionArg, s32 remoteAddressArg, s32 remotePortArg, s32 latency, u8 *requestMessage) {
    void *func_02044268(void);
    s32 func_020390d4(void);
    void func_0205adc0(s32, void *, s32);
    void func_0203dc38(s32, s32);
    void func_0203dc18(void);
    void *func_02039130(s32);
    void *func_020391a8(s32);
    s32 func_0205adb4(s32, s32);
    s32 func_0206abd8(void *, s32, s32);
    void func_0205b058(void *, s32);
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
    matchState = func_02044268();
    if (matchState == 0) goto reject_state;
    matchState = func_02044268();
    if (M2C_FIELD(matchState, s32 *, 0x1a0) != 7) goto reject_state;
    matchState = func_02044268();
    if (M2C_FIELD(matchState, u8 *, 0x1a9) != 0) goto reject_state;
    goto find_slot;

reject_state:
    func_0205adc0(connection, data_020fc920, -1);
    return;

find_slot:
    connectionSlot = func_020390d4();
    if (connectionSlot == -1) {
        func_0205adc0(connection, data_020fc92c, -1);
        func_0203dc38(6, (s32)0xfffeabc4);
        return;
    }
    entry = func_02044268();
    matchState = func_02044268();
    peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
    if (remoteAddress != *(s32 *)((u8 *)entry + (peerIndex << 2) + 0x210)) goto check_profile;
    entry = func_02044268();
    matchState = func_02044268();
    peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
    if (remotePort != *(u16 *)((u8 *)entry + (peerIndex << 1) + 0x200 + 0x90)) goto check_profile;
    goto accept_connection;

check_profile:
    if (requestMessage[0] != 0) {
        profileId = func_0206abd8(requestMessage, 0, 10);
        profileState = func_02044268();
        matchState = func_02044268();
        peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
        if (profileId == *(s32 *)((u8 *)profileState + (peerIndex << 2) + 0xf4)) {
            entry = func_02044268();
            matchState = func_02044268();
            peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
            *(s32 *)((u8 *)entry + (peerIndex << 2) + 0x210) = remoteAddress;
            entry = func_02044268();
            matchState = func_02044268();
            peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
            *(u16 *)((u8 *)entry + (peerIndex << 1) + 0x200 + 0x90) = (u16)remotePort;
            goto accept_connection;
        }
    }
    func_0205adc0(connection, data_020fc938, -1);
    return;

accept_connection:
    matchState = func_02044268();
    M2C_FIELD(matchState, s32 *, 0x18c) = 0;
    M2C_FIELD(matchState, s32 *, 0x190) = 0;
    matchState = func_02044268();
    if (func_0205adb4(connection, M2C_FIELD(matchState, s32 *, 0x08)) == 0) {
        func_0203dc38(6, (s32)0xfffec5e6);
        return;
    }
    func_0203dc18();
    matchState = func_02044268();
    peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
    if (peerIndex == 0) {
        s32 halfLatency = latency >> 1;
        if (halfLatency >= 0xffff) halfLatency = 0xffff;
        matchState = func_02044268();
        *(u16 *)((u8 *)matchState + 0x100 + 0xb0) = (u16)halfLatency;
    }
    {
        void *connectionEntry = func_02039130(connectionSlot);
        void *peerMetadata;
        peerMetadata = func_020391a8(connectionSlot);
        *(u32 *)connectionEntry = (u32)connection;
        entry = peerMetadata;
        matchState = func_02044268();
        peerIndex = M2C_FIELD(matchState, u8 *, 0x0d);
        M2C_FIELD(matchState, u8 *, 0x0d) = (u8)(peerIndex + 1);
        *(u8 *)entry = (u8)connectionSlot;
        matchState = func_02044268();
        {
            void *countState = func_02044268();
            s32 peerCount = M2C_FIELD(countState, u8 *, 0x0d);
            void *peerState = (void *)((u8 *)matchState + (peerCount - 1));
            u8 peerId = *(u8 *)((u8 *)peerState + 0x2d0);
            *(u8 *)((u8 *)entry + 1) = peerId;
        }
        *(u16 *)((u8 *)entry + 2) = 0;
        *(s32 *)((u8 *)entry + 4) = 0;
    }
    func_0205b058((void *)connection, (s32)entry);
    func_020411dc(2);
    return;
}

