/* 19 functions from 0x0203D910 to 0x0203E908 (main), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma opt_common_subs off
void func_0203d910(s32 a, s32 b)
{
    s32 GetConnection(void);
    M2C_UNK func_02040e1c(M2C_UNK);
    s32 StringFormatN(void *, s32, void *, s32);
    s32 gt2AddressToString(s32, s32, s32);
    s32 func_0205adcc(s32, s32, s32, void *, s32, s32, s32, s32);
    void ReportGt2ConnectResult(void);
    void ReportConnectionError(s32, s32);
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

            StringFormatN(
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

            r = gt2AddressToString(
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
                ReportGt2ConnectResult();
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
            ReportConnectionError(6, 0xfffeabc4);
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
/* Decode the command byte and slash-separated decimal arguments in a MAT message. */
void HandleConnectionTextCommand(s32 unusedConnection, s32 peerId, u8 *message) {
    s32 ExtractSlashField(u8 *, u8 *, s32);
    u32 strtoul(const char *, char **, s32);
    s32 HandleConnectionCommand(s32, s32, s32, s32, s32 *, s32);
    enum { MAX_COMMAND_ARGUMENTS = 128, ARGUMENT_TEXT_SIZE = 16 };
    char field[ARGUMENT_TEXT_SIZE];
    s32 arguments[MAX_COMMAND_ARGUMENTS];
    s32 argumentCount;

    for (argumentCount = 0; argumentCount < MAX_COMMAND_ARGUMENTS; argumentCount++) {
        if (ExtractSlashField((u8 *)field, message + 1, argumentCount) == -1) {
            break;
        }
        arguments[argumentCount] = strtoul(field, 0, 10);
    }
    HandleConnectionCommand(message[0], peerId, 0, 0, arguments, argumentCount);
}

void func_0203dc18(void) {
 M2C_FIELD(GetConnection(),u8 *,0x3cc)=255;
 M2C_FIELD(GetConnection(),u8 *,0x3cd)=0;
}

/* Report a match-making error to the game's connection-event callback - with
 * whether this side was serving and whether the connect target is already
 * cleared, plus the target's player slot - and tear the session down. */
void ReportConnectionError(s32 errorCode, s32 errorDetail) {
    extern s32 sEmptyString;
    s32 GetSessionPlayerSlot();
    void CloseGt2Connection();
    void SetNetError(s32, s32);
    s32 SetGpiStatus(s32, s32 *, s32);
    void TeardownConnectionSession();
    s32 serving, targetCleared, slot;
    void *connection;

    if (GetConnection() == 0 || errorCode == 0) return;
    CloseGt2Connection();
    SetNetError(errorCode, errorDetail);
    SetGpiStatus(1, &sEmptyString, 0);
    serving = M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 2;
    targetCleared = M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_TARGET_ID) == 0;
    connection = GetConnection();
    slot = GetSessionPlayerSlot(M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_TARGET_ID));
    ((void (*)(s32, s32, s32, s32, s32, s32))M2C_FIELD(connection, void **, CONN_SESSION_EVENT_CALLBACK))(errorCode, 0, targetCleared, serving, slot, M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_EVENT_DATA));
    TeardownConnectionSession();
}

void func_0203dcf4(void) {
    M2C_UNK Qr2_StateChanged(s32);
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 2) {
        return;
    }
    M2C_FIELD(GetConnection(), s8 *, 0x14) = 0;
    M2C_FIELD(GetConnection(), s8 *, 0x16) = 0;
    Qr2_StateChanged(M2C_FIELD(GetConnection(), s32 *, 0x10));
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
u64 GetSystemTick(void); s32 GetNetSessionState(void);
M2C_UNK SetConnectionState(s32); void func_02041be0(s32); void StartMatchmaking(void); void GT2NotifyConnectionClosed(s32); void NatNeg_ReleasePeer(s32);
void *state;
if(GetNetSessionState()!=5)return 0;
if(M2C_FIELD(GetConnection(),u8 *,21)==2)return 1;
if(command){ReportConnectionError(command,parameter+0xfffec780);return 1;}
M2C_FIELD(GetConnection(),u8 *,0x2d0)=0;
if(M2C_FIELD(GetConnection(),u8 *,0x1a9)==1 || M2C_FIELD(GetConnection(),u8 *,0x1a8)==1 || M2C_FIELD(GetConnection(),u8 *,0x1a8)==2)return 1;
if(M2C_FIELD(GetConnection(),s32 *,0x19c)){
NatNeg_ReleasePeer(M2C_FIELD(GetConnection(),s32 *,0x19c));M2C_FIELD(GetConnection(),s32 *,0x19c)=0;}
if(M2C_FIELD(GetConnection(),u8 *,13)){
if(!M2C_FIELD(GetConnection(),u8 *,0x1a8)){M2C_FIELD(GetConnection(),u8 *,0x1a8)=3;GT2NotifyConnectionClosed(*M2C_FIELD(GetConnection(),s32 **,4));}
}else if(M2C_FIELD(GetConnection(),u8 *,21)==3)ReportConnectionError(6,0xfffec5d2);
else if(M2C_FIELD(GetConnection(),s32 *,0x208))StartMatchmaking();
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
/* Removes the connection peer whose id is `playerId`: finds its slot among the
 * first `slotCount` peer-id slots and shifts the rest of the session down over
 * it.  Returns 1 when the peer was found, 0 otherwise. */
s32 RemovePlayerFromConnection(s32 playerId,s32 slotCount) { s32 RemoveConnectionPeer(s32,s32); s32 i; if(GetConnection()==0)return 0; for(i=0;i<slotCount;i++){ if(playerId==M2C_FIELD(GetConnection()+i*4,s32 *,CONN_SESSION_PEER_IDS)){RemoveConnectionPeer(i,slotCount);return 1;}} return 0; }
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

s32 GetPeerSlotList(s32 *arg0) { if(GetConnection()==0)return 0; *arg0=GetConnection()+0x2d0; return M2C_FIELD(GetConnection(),u8 *,0xd)+1; }

/* Copies the slot ids of the session's present players (those whose bit is set in
 * CONN_SESSION_PLAYER_MASK) into gActivePlayerSlots, up to the first absent one,
 * and returns how many were written (0 when there is no connection); *slots is
 * left pointing at the buffer. */
s32 GetActivePlayerSlots(u8 **slots){extern u8 gActivePlayerSlots[];s32 GetConnection(void);s32 slot;u8 *out;void *q;
if(!GetConnection())return 0;
MI_CpuFill8(gActivePlayerSlots,0,32);
slot=0;if(slot<=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_ACTIVE_MAX)){out=gActivePlayerSlots;do{
q=(void *)GetConnection();
if(!(M2C_FIELD(q,u32 *,CONN_SESSION_PLAYER_MASK)&(1<<M2C_FIELD((u8 *)GetConnection()+slot,u8 *,CONN_SESSION_PEER_SLOTS))))break;
*out++=M2C_FIELD((u8 *)GetConnection()+slot,u8 *,CONN_SESSION_PEER_SLOTS);
slot++;}while(slot<=M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_ACTIVE_MAX));}
*slots=gActivePlayerSlots;return M2C_FIELD(GetConnection(),u8 *,CONN_SESSION_ACTIVE_MAX)+1;
}

/* Report the connected session's match type and player count to the master as
 * gpi status 6: "/SCM/<match type>/SCN/<player count>/VER/3".  Only a fully
 * connected session (mode 2) reports anything. */
s32 ReportGpiSessionStatus(void){
M2C_UNK StringFormatN(void *,s32,void *,s32);M2C_UNK FormatKeyValue(void *,void *,void *,s32);M2C_UNK AppendKeyValue(void *,void *,void *,s32);s32 SetGpiStatus(s32,s32 *,s32);
extern M2C_UNK data_020fc908,gKeyVER,gKeyStatusSCM,gKeyStatusSCN;
u8 valueText[12];s32 statusText[8];
if(M2C_FIELD(GetConnection(),u8 *,21)!=2)return 0;
StringFormatN(valueText,12,&data_020fc908,M2C_FIELD(GetConnection(),u8 *,22)+1);
FormatKeyValue(&gKeyStatusSCM,valueText,statusText,47);
StringFormatN(valueText,12,&data_020fc908,M2C_FIELD(GetConnection(),u8 *,13)+1);
AppendKeyValue(&gKeyStatusSCN,valueText,statusText,47);
StringFormatN(valueText,12,&data_020fc908,3);
AppendKeyValue(&gKeyVER,valueText,statusText,47);
return SetGpiStatus(6,statusText,0);
}

/* Shut the connection manager down: drop the active connection, free the
 * manager's matchmaking-message and player-list buffers, clear the cached
 * session players and forget whether a match was started and has finished. */
void ShutdownConnection(void) {
    M2C_UNK HeapFree(M2C_UNK, s32, M2C_UNK);
    M2C_UNK ClearSessionPlayers();
    M2C_UNK SetActiveConnection(M2C_UNK);
    extern M2C_UNK gConnectionMgr;

    SetActiveConnection(0);
    if (M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_MATCH_MESSAGE) != 0) {
        HeapFree(4, M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_MATCH_MESSAGE), 0);
        M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_MATCH_MESSAGE) = 0;
    }
    ClearSessionPlayers();
    if (M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_PLAYER_LIST) != 0) {
        HeapFree(4, M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_PLAYER_LIST), 0);
        M2C_FIELD(&gConnectionMgr, s32 *, CONN_MGR_PLAYER_LIST) = 0;
    }
    M2C_FIELD(&gConnectionMgr, s8 *, CONN_MGR_MATCH_STARTED) = 0;
    M2C_FIELD(&gConnectionMgr, s8 *, CONN_MGR_MATCH_FINISHED) = 0;
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

