/* 19 functions from 0x0203D910 to 0x0203E908 (main), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma opt_common_subs off
void func_0203d910(s32 a, s32 b)
{
    s32 GetConnection(void);
    M2C_UNK func_02040e1c(M2C_UNK);
    s32 func_0200567c(void *, s32, void *, s32);
    s32 func_0205d4d8(s32, s32, s32);
    s32 func_0205adcc(s32, s32, s32, void *, s32, s32, s32, s32);
    void func_02043230(void);
    void func_0203dc38(s32, s32);
    s32 FindFreePlayerSlot(void);
    s32 *GetPlayerConnectionSlot(s32);
    u8 *GetPlayerPeer(s32);
    void func_0205b058(s32, void *);
    M2C_UNK func_020411dc(M2C_UNK);

    extern M2C_UNK data_020fc908;

    char buf[12];
    s32 x, y, z, w, t, i, j;
    s32 r;
    s32 slot;
    s32 *out;
    u8 *p;

    if (!GetConnection())
        return;

    if (M2C_FIELD(GetConnection(), s32 *, 0x1a0) != 7 &&
        M2C_FIELD(GetConnection(), s32 *, 0x1a0) != 12)
        return;

    if (b != 0) {
        if (b == 5)
            return;

        if (b == 6) {
            M2C_FIELD(GetConnection(), u8 *, 0xc)++;

            if (M2C_FIELD(GetConnection(), u8 *, 0xc) > 5) {
                M2C_FIELD(GetConnection(), u8 *, 0xc) = 0;

                x = GetConnection();

                func_02040e1c(
                    M2C_FIELD(
                        x + M2C_FIELD(GetConnection(), u8 *, 0x14) * 4,
                        s32 *,
                        0xf4
                    )
                );
                return;
            }

            func_0200567c(
                buf,
                12,
                &data_020fc908,
                M2C_FIELD(GetConnection(), s32 *, 0x200)
            );

            x = GetConnection();
            y = GetConnection();
            z = GetConnection();
            w = GetConnection();
            t = GetConnection();

            /* Experimental scheduling change */
            i = (s32)M2C_FIELD(z, u8 *, 0x14);
            j = (s32)M2C_FIELD(t, u8 *, 0x14);

            r = func_0205d4d8(
                M2C_FIELD(y + i * 4, s32 *, 0x210),
                M2C_FIELD(w + j * 2, u16 *, 0x290),
                0
            );

            r = func_0205adcc(
                *M2C_FIELD(x, s32 **, 4),
                0,
                r,
                buf,
                -1,
                5000,
                M2C_FIELD(GetConnection(), s32 *, 8),
                0
            );

            if (r == 1) {
                func_02043230();
                return;
            }

            if (r == 0)
                return;

            x = GetConnection();

            if (func_02040e1c(
                    M2C_FIELD(
                        x + M2C_FIELD(GetConnection(), u8 *, 0x14) * 4,
                        s32 *,
                        0xf4
                    )
                ) == 0)
                return;

            return;
        }

        x = GetConnection();

        if (func_02040e1c(
                M2C_FIELD(
                    x + (M2C_FIELD(GetConnection(), u8 *, 0xd) + 1) * 4,
                    s32 *,
                    0xf4
                )
            ) == 0)
            return;

    } else {
        slot = FindFreePlayerSlot();

        if (slot == -1) {
            func_0203dc38(6, 0xfffeabc4);
            return;
        }

        out = GetPlayerConnectionSlot(slot);
        p = GetPlayerPeer(slot);

        *out = a;

        M2C_FIELD(GetConnection(), u8 *, 0xd)++;

        p[0] = slot;
        M2C_FIELD(p, u16 *, 2) = 0;
        M2C_FIELD(p, s32 *, 4) = 0;

        x = GetConnection();

        p[1] = M2C_FIELD(
            x + M2C_FIELD(GetConnection(), u8 *, 0xd),
            u8 *,
            0x2d0
        );

        func_0205b058(a, p);

        if (M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 12) {
            func_020411dc(0);
            return;
        }

        func_020411dc(1);
        return;
    }
}
#pragma pop
void func_0203db94(s32 arg0,s32 arg1,u8 *arg2) {
 s32 func_0203f3c0(void *,u8 *,s32); s32 func_0206abd8(void *,s32,s32);
 void func_0203f45c(s32,s32,s32,s32,s32 *,s32);
 char buf[16]; s32 values[128]; s32 i;
 for(i=0;i<128;i++) {
 if(func_0203f3c0(buf,arg2+1,i)==-1) break;
 values[i]=func_0206abd8(buf,0,10);
 }
 func_0203f45c(arg2[0],arg1,0,0,values,i);
}

void func_0203dc18(void) {
 M2C_FIELD(GetConnection(),u8 *,0x3cc)=255;
 M2C_FIELD(GetConnection(),u8 *,0x3cd)=0;
}

void func_0203dc38(s32 arg0,s32 arg1) {
 extern s32 sEmptyString;
 s32 func_0203aeb4(); void func_02041e44(); void SetNetError(s32,s32); s32 SetGpiStatus(s32,s32 *,s32); void func_0203e9b0();
 s32 a,b,c; void *p;
 if(GetConnection()==0 || arg0==0) return;
 func_02041e44(); SetNetError(arg0,arg1); SetGpiStatus(1,&sEmptyString,0);
 a=M2C_FIELD(GetConnection(),u8 *,0x15)==2;
 b=M2C_FIELD(GetConnection(),s32 *,0x20c)==0;
 p=GetConnection();
 c=func_0203aeb4(M2C_FIELD(GetConnection(),s32 *,0x20c));
 ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(p,void **,0x464))(arg0,0,b,a,c,M2C_FIELD(GetConnection(),s32 *,0x468));
 func_0203e9b0();
}

void func_0203dcf4(void) {
    M2C_UNK func_0205ea70(s32);
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 2) {
        return;
    }
    M2C_FIELD(GetConnection(), s8 *, 0x14) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x16) = 0;
    func_0205ea70(M2C_FIELD(GetConnection(), s32 *, 0x10));
}

/* Receive handler for the connection handshake packets (types 2..4), the
 * counterpart of SendConnectionPacket.  Type 2 (join) records the peer's player
 * slot and answers with type 3; type 3 (ready) collects the peers' ready mask
 * and, once every connected player is ready, tells them type 4 and moves the
 * connection to its running state; type 4 (start) advances the joiner. */
void ReceiveConnectionPacket(u8 fromPlayer, s32 packetType, void *payload) {
    M2C_UNK func_020411dc(M2C_UNK);
    M2C_UNK SendConnectionPacket(u8, M2C_UNK);
    s32 GetConnectedPlayerMask(M2C_UNK);
    M2C_UNK SetConnectionState(M2C_UNK);
    s32 readyValue;
    s32 connectedMask;
    s32 i;
    u8 slot;
    void *session;
    void *session2;
    void *session3;

    switch (packetType) {
    case 2:
        if (M2C_FIELD(GetConnection(), s32 *, 0x1A0) == 1) {
            if (M2C_FIELD(payload, u8 *, 0) == 1) {
                M2C_FIELD(GetConnection(), s32 *, 0x20C) = 0;
            }
            slot = M2C_FIELD(payload, u8 *, 1);
            session = GetConnection();
            M2C_FIELD((session + slot), u8 *, 0x2D0) = (u8) M2C_FIELD(payload, u8 *, 2);
            session2 = GetConnection();
            M2C_FIELD((session2 + (slot * 4)), s32 *, 0xF4) = (s32) M2C_FIELD(GetConnection(), s32 *, 0x200);
            if ((M2C_FIELD(GetConnection(), u8 *, 0x15) == 0) || (M2C_FIELD(GetConnection(), u8 *, 0x15) == 1)) {
                session3 = GetConnection();
                M2C_FIELD(session3, u8 *, 0x16) = (u8) M2C_FIELD(GetConnection(), u8 *, 0xD);
            }
            M2C_FIELD(GetConnection(), s8 *, 0x1AD) = 0;
            SetConnectionState(9);
        }
        SendConnectionPacket(fromPlayer, 3);
        return;
    case 3:
        if (M2C_FIELD(GetConnection(), s32 *, 0x1A0) == 0x10) {
            session = GetConnection();
            M2C_FIELD(session, s32 *, 0x1D4) = (s32) (M2C_FIELD(session, s32 *, 0x1D4) | (1 << fromPlayer));
            readyValue = M2C_FIELD(payload, u8 *, 0) | (M2C_FIELD(payload, u8 *, 1) << 8);
            if (readyValue > (s32) M2C_FIELD(GetConnection(), u16 *, 0x1B0)) {
                M2C_FIELD(GetConnection(), s16 *, 0x1B0) = (s16) readyValue;
            }
            connectedMask = GetConnectedPlayerMask(0);
            if (connectedMask != M2C_FIELD(GetConnection(), s32 *, 0x1D4)) {
                return;
            }
            i = 1;
            if ((s32) M2C_FIELD(GetConnection(), u8 *, 0xD) >= 1) {
                do {
                    session = GetConnection();
                    SendConnectionPacket(M2C_FIELD((session + i), u8 *, 0x2D0), 4);
                    i += 1;
                } while (i <= (s32) M2C_FIELD(GetConnection(), u8 *, 0xD));
            }
            SetConnectionState(0x11);
            return;
        }
        SendConnectionPacket(fromPlayer, 4);
        return;
    case 4:
        if (M2C_FIELD(GetConnection(), s32 *, 0x1A0) != 9) {
            return;
        }
        func_020411dc(4);
        return;
    }
}

/* Handles deferred battle/action state transitions after the active phase check. */
s32 func_0203dee8(s32 command, s32 parameter) {
u64 GetSystemTick(void); s32 func_02038f6c(void);
M2C_UNK SetConnectionState(s32); void func_02041be0(s32); void func_02041d14(void); void func_0205afec(s32); void func_0205df50(s32);
void *state;
if(func_02038f6c()!=5)return 0;
if(M2C_FIELD(GetConnection(),u8 *,21)==2)return 1;
if(command){func_0203dc38(command,parameter+0xfffec780);return 1;}
M2C_FIELD(GetConnection(),u8 *,0x2d0)=0;
if(M2C_FIELD(GetConnection(),u8 *,0x1a9)==1 || M2C_FIELD(GetConnection(),u8 *,0x1a8)==1 || M2C_FIELD(GetConnection(),u8 *,0x1a8)==2)return 1;
if(M2C_FIELD(GetConnection(),s32 *,0x19c)){
func_0205df50(M2C_FIELD(GetConnection(),s32 *,0x19c));M2C_FIELD(GetConnection(),s32 *,0x19c)=0;}
if(M2C_FIELD(GetConnection(),u8 *,13)){
if(!M2C_FIELD(GetConnection(),u8 *,0x1a8)){M2C_FIELD(GetConnection(),u8 *,0x1a8)=3;func_0205afec(*M2C_FIELD(GetConnection(),s32 **,4));}
}else if(M2C_FIELD(GetConnection(),u8 *,21)==3)func_0203dc38(6,0xfffec5d2);
else if(M2C_FIELD(GetConnection(),s32 *,0x208))func_02041d14();
else if(M2C_FIELD(GetConnection(),s32 *,0x1a0)==1){SetConnectionState(18);state=(void *)GetConnection();M2C_FIELD(state,u64 *,0x1f0)=GetSystemTick();}
else func_02041be0(1);
return 1;
}

void func_0203e064(M2C_UNK arg0) {
    M2C_UNK func_02040e1c(M2C_UNK);
    if (M2C_FIELD(GetConnection(), u8 *, 0x1A8) == 2) {
        return;
    }
    func_02040e1c(arg0);
}

#pragma opt_strength_reduction off
s32 func_0203e088(s32 arg0,s32 arg1) { s32 RemoveConnectionPeer(s32,s32); s32 i; if(GetConnection()==0)return 0; for(i=0;i<arg1;i++){ if(arg0==M2C_FIELD(GetConnection()+i*4,s32 *,0xf4)){RemoveConnectionPeer(i,arg1);return 1;}} return 0; }
#pragma opt_strength_reduction reset
/* Removes the peer at peer slot index `slotIndex` from the connection's per-peer tables
 * (player id + port, peer id, IPv4 address + port, and player slot): clears the
 * player's presence bit, shifts the later entries down, clears the last entry and
 * recomputes the active player count.  Returns the removed peer's connection id. */
s32 RemoveConnectionPeer(s32 slotIndex, s32 peerCount) {
    s32 GetConnection(void); void UpdateConnectedPlayerCount(void);
    s32 slot, count, removedPeerId;
    void *sessionA, *sessionB;
    void *connA, *connB, *dstBase, *srcBase;
    u8 playerSlot, nextPlayerSlot;
    s32 i, shiftCount, nextIndex, curIndex, lastIndex;
    void *srcPos, *dstPos;
    slot = slotIndex;
    count = peerCount;
    if (GetConnection() == 0) return 0;
    removedPeerId = *(s32 *)((u8 *)GetConnection() + slot * 4 + CONN_SESSION_PEER_IDS);
    sessionA = GetConnection();
    sessionB = GetConnection();
    playerSlot = *(u8 *)((u8 *)sessionB + slot + CONN_SESSION_PEER_SLOTS);
    *(s32 *)((u8 *)sessionA + CONN_SESSION_PLAYER_MASK) &= ~(1 << playerSlot);
    UpdateConnectedPlayerCount();
    if (slot < count - 1) {
        shiftCount = count - slot - 1;
        i = 0;
        if (shiftCount > 0) {
            do {
                curIndex = slot + i;
                nextIndex = curIndex + 1;
                connA = GetConnection();
                connB = GetConnection();
                *(s32 *)((u8 *)connA + curIndex * 4 + CONN_SESSION_PEER_DATA) = *(s32 *)((u8 *)connB + nextIndex * 4 + CONN_SESSION_PEER_DATA);
                connA = GetConnection();
                connB = GetConnection();
                *(u16 *)((u8 *)connA + curIndex * 2 + CONN_SESSION_PEER_DATA_PORT) = *(u16 *)((u8 *)connB + nextIndex * 2 + CONN_SESSION_PEER_DATA_PORT);
                connA = GetConnection();
                connB = GetConnection();
                *(s32 *)((u8 *)connA + curIndex * 4 + CONN_SESSION_PEER_IDS) = *(s32 *)((u8 *)connB + nextIndex * 4 + CONN_SESSION_PEER_IDS);
                connA = GetConnection();
                connB = GetConnection();
                *(s32 *)((u8 *)connA + curIndex * 4 + CONN_SESSION_PEER_IPS) = *(s32 *)((u8 *)connB + nextIndex * 4 + CONN_SESSION_PEER_IPS);
                connA = GetConnection();
                connB = GetConnection();
                *(u16 *)((u8 *)connA + curIndex * 2 + CONN_SESSION_PEER_PORTS) = *(u16 *)((u8 *)connB + nextIndex * 2 + CONN_SESSION_PEER_PORTS);
                dstBase = GetConnection();
                srcBase = GetConnection();
                srcPos = (void *)((s32)slot + (s32)srcBase);
                nextPlayerSlot = *(u8 *)(i + (s32)srcPos + CONN_SESSION_PEER_SLOTS + 1);
                dstPos = (void *)((s32)slot + (s32)dstBase);
                *(u8 *)(i + (s32)dstPos + CONN_SESSION_PEER_SLOTS) = nextPlayerSlot;
                i++;
            } while (i < shiftCount);
        }
    }
    if (count > 0) {
        lastIndex = count - 1;
        connB = GetConnection();
        *(s32 *)((u8 *)connB + lastIndex * 4 + CONN_SESSION_PEER_DATA) = 0;
        connB = GetConnection();
        *(u16 *)((u8 *)connB + lastIndex * 2 + CONN_SESSION_PEER_DATA_PORT) = 0;
        connB = GetConnection();
        *(s32 *)((u8 *)connB + lastIndex * 4 + CONN_SESSION_PEER_IDS) = 0;
        connB = GetConnection();
        *(s32 *)((u8 *)connB + lastIndex * 4 + CONN_SESSION_PEER_IPS) = 0;
        connB = GetConnection();
        *(u16 *)((u8 *)connB + lastIndex * 2 + CONN_SESSION_PEER_PORTS) = 0;
        connB = GetConnection();
        *(u8 *)((u8 *)connB + lastIndex + CONN_SESSION_PEER_SLOTS) = 0;
    }
    return removedPeerId;
}

s32 func_0203e2a4(void) { if(GetConnection()==0)return 0; return M2C_FIELD(GetConnection(),u8 *,0xd); }

s32 func_0203e2c4(void) { if(GetConnection()==0)return 0; return M2C_FIELD(GetConnection(),u8 *,0xe); }

void UpdateConnectedPlayerCount(void) {
 s32 n=-1; s32 i;
 for(i=0;i<32;i++) { if(M2C_FIELD(GetConnection(),s32 *,0x2f0) & (1<<i)) n++; }
 if(n==-1) { M2C_FIELD(GetConnection(),u8 *,0xe)=0; return; }
 M2C_FIELD(GetConnection(),u8 *,0xe)=n;
}

s32 func_0203e338(s32 *arg0) { if(GetConnection()==0)return 0; *arg0=GetConnection()+0x2d0; return M2C_FIELD(GetConnection(),u8 *,0xd)+1; }

s32 func_0203e36c(u8 **a){extern u8 data_0213daf4[];s32 GetConnection(void);s32 i;u8 *p;void *q;
if(!GetConnection())return 0;
MI_CpuFill8(data_0213daf4,0,32);
i=0;if(i<=M2C_FIELD(GetConnection(),u8 *,14)){p=data_0213daf4;do{
q=(void *)GetConnection();
if(!(M2C_FIELD(q,u32 *,0x2f0)&(1<<M2C_FIELD((u8 *)GetConnection()+i,u8 *,0x2d0))))break;
*p++=M2C_FIELD((u8 *)GetConnection()+i,u8 *,0x2d0);
i++;}while(i<=M2C_FIELD(GetConnection(),u8 *,14));}
*a=data_0213daf4;return M2C_FIELD(GetConnection(),u8 *,14)+1;
}

s32 func_0203e410(void){
M2C_UNK func_0200567c(void *,s32,void *,s32);M2C_UNK func_02037d78(void *,void *,void *,s32);M2C_UNK func_02037db0(void *,void *,void *,s32);s32 SetGpiStatus(s32,s32 *,s32);
extern M2C_UNK data_020fc908,gKeyVER,data_020fc950,data_020fc954;
u8 sp20[12];s32 sp0[8];
if(M2C_FIELD(GetConnection(),u8 *,21)!=2)return 0;
func_0200567c(sp20,12,&data_020fc908,M2C_FIELD(GetConnection(),u8 *,22)+1);
func_02037d78(&data_020fc950,sp20,sp0,47);
func_0200567c(sp20,12,&data_020fc908,M2C_FIELD(GetConnection(),u8 *,13)+1);
func_02037db0(&data_020fc954,sp20,sp0,47);
func_0200567c(sp20,12,&data_020fc908,3);
func_02037db0(&gKeyVER,sp20,sp0,47);
return SetGpiStatus(6,sp0,0);
}

void func_0203e4e0(void) {
    M2C_UNK HeapFree(M2C_UNK, s32, M2C_UNK);
    M2C_UNK ClearSessionPlayers();
    M2C_UNK SetActiveConnection(M2C_UNK);
    extern M2C_UNK gConnectionMgr;
    SetActiveConnection(0);
    if (M2C_FIELD(&gConnectionMgr, s32 *, 8) != 0) {
        HeapFree(4, M2C_FIELD(&gConnectionMgr, s32 *, 8), 0);
        M2C_FIELD(&gConnectionMgr, s32 *, 8) = 0;
    }
    ClearSessionPlayers();
    if (M2C_FIELD(&gConnectionMgr, s32 *, 0) != 0) {
        HeapFree(4, M2C_FIELD(&gConnectionMgr, s32 *, 0), 0);
        M2C_FIELD(&gConnectionMgr, s32 *, 0) = 0;
    }
    M2C_FIELD(&gConnectionMgr, s8 *, 0x1C) = 0;
    M2C_FIELD(&gConnectionMgr, s8 *, 0x1D) = 0;
}

s32 func_0203e558(void) {
    s32 GetConnection();
    if (GetConnection() == 0) {
        return 1;
    }
    return 0;
}

/* Reset matchmaking context: mode 2 preserves a session, copying byte 0xD to 0x14 and
   selecting state 0x01 (mode 3) or 0x0A (mode 2); mode 1 keeps mode but selects state
   0x03 (mode 0) or 0x04 (mode 1); mode 0 clears mode callbacks too. */
void ResetConnection(s32 resetMode) {
    M2C_UNK FillU16(M2C_UNK, s32, M2C_UNK);
    M2C_UNK CpuFill(M2C_UNK, s32, M2C_UNK);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    s16 RandomBelow(M2C_UNK);
    M2C_UNK SetConnectionState(M2C_UNK);
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r4;
    void *temp_r5;

    M2C_FIELD(GetConnection(), s8 *, 0xC) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x17C) = 0;
    temp_r5 = GetConnection();
    M2C_FIELD(temp_r5, s16 *, 0x17E) = RandomBelow(0x10000);
    M2C_FIELD(GetConnection(), s32 *, 0x180) = 0;
    temp_r0 = GetConnection();
    M2C_FIELD(temp_r0, s32 *, 0x184) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x188) = 0;
    temp_r0_2 = GetConnection();
    M2C_FIELD(temp_r0_2, s32 *, 0x18C) = 0;
    M2C_FIELD(temp_r0_2, s32 *, 0x190) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1A4) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1A9) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1AA) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1AB) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1AC) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1A7) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1A8) = 0;
    M2C_FIELD(GetConnection(), s16 *, 0x1B2) = 0;
    M2C_FIELD(GetConnection(), s16 *, 0x1B4) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x1B8) = 0;
    temp_r0_3 = GetConnection();
    M2C_FIELD(temp_r0_3, s32 *, 0x1E0) = 0;
    M2C_FIELD(temp_r0_3, s32 *, 0x1E4) = 0;
    temp_r0_4 = GetConnection();
    M2C_FIELD(temp_r0_4, s32 *, 0x1F0) = 0;
    M2C_FIELD(temp_r0_4, s32 *, 0x1F4) = 0;
    CpuFill(0, GetConnection() + 0x3CC, 0x98);
    if (resetMode == 2) {
        temp_r4 = GetConnection();
        M2C_FIELD(temp_r4, u8 *, 0x14) = (u8) M2C_FIELD(GetConnection(), u8 *, 0xD);
        if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 3) {
            SetConnectionState(1);
            return;
        }
        if (M2C_FIELD(GetConnection(), u8 *, 0x15) != 2) {
            return;
        }
        SetConnectionState(0xA);
        return;
    }
    M2C_FIELD(GetConnection(), s8 *, 0xD) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0xE) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x14) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x17) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x20) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0xE8) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1A5) = 0;
    M2C_FIELD(GetConnection(), s16 *, 0x1B0) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x1BC) = 0;
    temp_r0_5 = GetConnection();
    M2C_FIELD(temp_r0_5, s32 *, 0x1C0) = 0;
    M2C_FIELD(temp_r0_5, s32 *, 0x1C4) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x1C8) = 0;
    temp_r0_6 = GetConnection();
    M2C_FIELD(temp_r0_6, s32 *, 0x1CC) = 0;
    M2C_FIELD(temp_r0_6, s32 *, 0x1D0) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x1D4) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x204) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x208) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x2F0) = 0;
    CpuFill(0, GetConnection() + 0x24, 0x80);
    FillU16(0, GetConnection() + 0xA4, 0x40);
    CpuFill(0, GetConnection() + 0xF4, 0x80);
    CpuFill(0, GetConnection() + 0x194, 0xC);
    CpuFill(0, GetConnection() + 0x210, 0x80);
    FillU16(0, GetConnection() + 0x290, 0x40);
    MI_CpuFill8(GetConnection() + 0x2D0, 0, 0x20);
    CpuFill(0, GetConnection() + 0x348, 0x84);
    if (resetMode == 1) {
        if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 0) {
            SetConnectionState(3);
            return;
        }
        if (M2C_FIELD(GetConnection(), u8 *, 0x15) != 1) {
            return;
        }
        SetConnectionState(4);
        return;
    }
    M2C_FIELD(GetConnection(), s8 *, 0x15) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x16) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x18) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x20C) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1A6) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1AE) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x1AD) = 0;
    temp_r0_7 = GetConnection();
    M2C_FIELD(temp_r0_7, s32 *, 0x1F8) = 0;
    M2C_FIELD(temp_r0_7, s32 *, 0x1FC) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x46C) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x470) = 0;
}

