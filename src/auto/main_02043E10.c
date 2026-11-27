/* 35 functions from 0x02043E10 to 0x02044E04 (main), found by ds-decomp. */
#include "common.h"
void MI_CpuCopy8(void *,void *,s32);
s32 GetConnection(void);
void SetConnectionState(s32);

/* Peer socket-connect callback: event 0 (re)starts the connect to the peer
   described by addr (address at +4, port at +2) and gives it a session slot; a
   nonzero event is the connect's error or timeout code.  On success the session
   advances (AdvancePeerConnection); otherwise the attempt is retried while its retry
   budget lasts, and the peer is dropped when it fails.  attempt is the
   connection's in-flight connect record. */
void OnPeerConnect(s32 event, s32 socketHandle, PeerAddress *addr, ConnAttempt *attempt)
{
    M2C_UNK AdvancePeerConnection(M2C_UNK);
    s32 StringFormatN(void *, s32, void *, s32);
    s32 gt2AddressToString(s32, s32, s32);
    s32 func_0205adcc(s32, s32, s32, void *, s32, s32, s32, s32);
    void ReportGt2ConnectResult(void);
    s32 ReportPeerConnectError(s32);
    s32 RestartConnection(s32);
    s32 StartPeerConnect(void *);
    s32 ReportPeerConnectResult();
    u64 GetSystemTick(void);
    extern M2C_UNK data_020fc908;

    u8 buf[12];
    void *sessionA;
    void *sessionB;
    void *sessionC;
    s32 kind;
    s32 res;
    s32 slot;
    u16 port;

    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) != 6 && M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) != 0xB) {
        return;
    }
    if (attempt == 0) {
        return;
    }
    if (event == 0) {
        attempt->natNeg = 0;
        M2C_FIELD(GetConnection(), u8 *, 0x14)++;
        slot = M2C_FIELD(GetConnection(), u8 *, 0x14);
        if (attempt->isJoin != 0) {
            M2C_FIELD(GetConnection() + slot * 4, s32 *, CONN_SESSION_PEER_IPS) = addr->address;
            port = addr->port;
            M2C_FIELD(GetConnection() + slot * 2, u16 *, CONN_SESSION_PEER_PORTS) = (u16)((u8)((s32)port >> 8) | ((port << 8) & 0xFF00));
            M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TARGET_NOTICES) = 0;
            M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_CONNECT_TARGET) = 0;
            sessionA = GetConnection();
            M2C_FIELD(sessionA, s32 *, CONN_SESSION_JOIN_TICK) = 0;
            M2C_FIELD(sessionA, s32 *, 0x188) = 0;
            if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == 0xB) {
                SetConnectionState(0xC);
            } else {
                SetConnectionState(7);
            }
            M2C_FIELD(GetConnection(), u8 *, 0xC) = 0;
            StringFormatN(buf, 12, &data_020fc908, M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_QR2_PARAM));
            sessionA = GetConnection();
            sessionB = GetConnection();
            sessionC = GetConnection();
            res = gt2AddressToString(M2C_FIELD(sessionB + slot * 4, s32 *, CONN_SESSION_PEER_IPS), M2C_FIELD(sessionC + slot * 2, u16 *, CONN_SESSION_PEER_PORTS), 0);
            res = func_0205adcc(*M2C_FIELD(sessionA, s32 **, 4), 0, res, buf, -1, 5000, M2C_FIELD(GetConnection(), s32 *, 8), 0);
            if (res == 1) {
                ReportGt2ConnectResult();
                return;
            }
            if (res == 0) {
                return;
            }
            if (AdvancePeerConnection(M2C_FIELD(GetConnection() + slot * 4, s32 *, CONN_SESSION_PEER_IDS)) == 0) {
                return;
            }
            return;
        } else {
            if (addr != 0) {
                res = slot - 1;
                M2C_FIELD(GetConnection() + res * 4, s32 *, CONN_SESSION_PEER_IPS) = addr->address;
                port = addr->port;
                M2C_FIELD(GetConnection() + res * 2, u16 *, CONN_SESSION_PEER_PORTS) = (u16)((u8)((s32)port >> 8) | ((port << 8) & 0xFF00));
            }
            sessionA = GetConnection();
            M2C_FIELD(sessionA, u64 *, CONN_SESSION_CONNECT_TICK) = GetSystemTick();
            SetConnectionState(7);
            return;
        }
    } else {
        if (attempt->natNeg == 0) {
            return;
        }
        kind = ReportPeerConnectError(event);
        if (kind != 2 && kind != 1) {
            return;
        }
        if (attempt->isJoin == 0) {
            if (kind == 1 || (kind == 2 && attempt->retries >= 1)) {
                attempt->natNeg = 0;
                if (CheckPeerConnectRetryLimit(0) == 0) {
                    return;
                }
                sessionA = GetConnection();
                sessionB = GetConnection();
                if (RestartConnection(M2C_FIELD(sessionA + M2C_FIELD(sessionB, u8 *, CONN_SESSION_PLAYER_COUNT) * 4, s32 *, CONN_SESSION_PEER_IDS)) == 0) {
                    return;
                }
                return;
            } else {
                attempt->retries++;
                StartPeerConnect(attempt);
                if (ReportPeerConnectResult() == 0) {
                    return;
                }
                return;
            }
        } else {
            sessionA = GetConnection();
            M2C_FIELD(sessionA, u64 *, CONN_SESSION_JOIN_TICK) = GetSystemTick();
            if (kind != 1) {
                if (kind != 2) {
                    return;
                }
                if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TARGET_NOTICES) < 1) {
                    return;
                }
            }
        }
        attempt->natNeg = 0;
        if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 3 || M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == 2) {
            if (CheckPeerConnectRetryLimit(1) == 0) {
                return;
            }
        } else {
            if (CheckPeerConnectRetryLimit(0) == 0) {
                return;
            }
        }
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_TARGET_NOTICES) = 0;
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_CONNECT_TARGET) = 0;
        sessionA = GetConnection();
        M2C_FIELD(sessionA, s32 *, CONN_SESSION_JOIN_TICK) = 0;
        M2C_FIELD(sessionA, s32 *, 0x188) = 0;
        sessionA = GetConnection();
        sessionB = GetConnection();
        if (AdvancePeerConnection(M2C_FIELD(sessionA + (M2C_FIELD(sessionB, u8 *, CONN_SESSION_PLAYER_COUNT) + 1) * 4, s32 *, CONN_SESSION_PEER_IDS)) == 0) {
            return;
        }
        return;
    }
}

/* Count a failed peer connect and report the error when the session cannot retry. */
s32 CheckPeerConnectRetryLimit(s32 skipRetryCheck) {
    void ReportConnectionError(s32, s32);
    void *session;

    if (skipRetryCheck != 0) {
        return 1;
    }
    if (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) != CONN_MODE_SERVE_NO_RETRY) {
        session = GetConnection();
        M2C_FIELD(session, u8 *, CONN_SESSION_CONNECT_ATTEMPTS) =
            (u8)(M2C_FIELD(session, u8 *, CONN_SESSION_CONNECT_ATTEMPTS) + 1);
    }
    if ((M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) == CONN_MODE_SERVE_NO_RETRY) ||
        ((u32)M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_CONNECT_ATTEMPTS) >= CONN_PEER_CONNECT_LIMIT)) {
        ReportConnectionError(CONN_ERROR_MATCH_FAILED, CONN_DETAIL_PEER_CONNECT_FAILED);
        return 0;
    }
    return 1;
}

void SetActiveConnection(s32 arg0) {
    extern M2C_UNK gConnectionMgr;
    M2C_FIELD(&gConnectionMgr, s32 *, 4) = arg0;
}

s32 GetConnection(void) {
    extern M2C_UNK gConnectionMgr;
    return M2C_FIELD(&gConnectionMgr, s32 *, 4);
}

void SetConnectionState(s32 arg0) {
 extern M2C_UNK gConnectionMgr;
 M2C_FIELD(M2C_FIELD(&gConnectionMgr, void **, 4), s32 *, 0x1A0) = arg0;
}

void CanStartSend(M2C_UNK arg0) {
    M2C_UNK CanStartTransfer(M2C_UNK, M2C_UNK);
    CanStartTransfer(arg0, 1);
}

/* Returns whether a transfer of `kind` can start on `channel` now: no network
 * error, the player's connection present (and active when the caller needs it),
 * no transfer already sending on the channel, and enough room in the link's
 * send space for the transfer's first bytes. */
s32 CanStartTransfer(s32 channel, s32 kind) {
    s32 HasNetError();
    s32 IsConnectionActive(s32);
    s32 HasPlayerConnection(s32);
    s32 GetTransferStartSpace(s32);
    s32 IsTransferSending(s32);
    s32 sendSpace;

    if ((HasNetError() != 0) || ((kind == 1) && (IsConnectionActive(channel) == 0)) || (HasPlayerConnection(channel) == 0)) {
        return 0;
    }
    if (IsTransferSending(channel) == 1) {
        return 0;
    }
    sendSpace = GetSendSpace(channel);
    if (sendSpace >= GetTransferStartSpace(kind)) {
        return 1;
    }
    return 0;
}

/* Start a kind-1 data transfer of `size` bytes from `buffer` to peer `channel`
 * (the transfer slot index of the player the data goes to). */
s32 SendTransferToPeer(s32 channel, void *buffer, s32 size) {
    M2C_UNK SendTransfer(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return SendTransfer(1, channel, (s32)buffer, size);
}

/* Start sending `size` bytes from `buffer` to `channel` as a transfer of `kind`:
 * queue the outgoing buffer in the connection's slot, send the 8-byte header
 * and as much of the payload as the link has room for. */
s32 SendTransfer(s32 kind,s32 channel,s32 buffer,s32 size) {
extern s32 gTransferManager;
void *GetTransferSlot(s32);
void BuildTransferHeader(void *,s16,s32);
void SendConnectionData(s32,s32,s32,s32);
TransferSlot *slot;
s32 chunk, total;
u32 header[2];
void (*callback)(s32,s32);
slot=GetTransferSlot(channel);
if(!CanStartTransfer(channel,kind)) return 0;
slot->sending=1;
slot->outData=buffer;
slot->outSent=0;
slot->outSize=size;
((void (*)(void *,s32,s32))BuildTransferHeader)(header,kind,size);
SendConnectionData(channel,(s32)header,8,1);
chunk=((TransferManager *)gTransferManager)->chunkSize;
if(size<=chunk)chunk=size;
if(chunk>GetSendSpace(channel))return 1;
SendConnectionData(channel,buffer,chunk,1);
slot->outSent+=chunk;
total=slot->outSize;
if(slot->outSent==total) {
slot->sending=0;
slot->outData=0;
slot->outSent=0;
slot->outSize=0;
callback=((TransferManager *)gTransferManager)->onSent;
if(callback && kind==1) callback(total,channel);
}
return 1;
}

/* Start a transfer of `size` bytes from `data` to every player whose identity
 * bit is set in `playerMask`, skipping the local player.  A player the transfer
 * is refused for is cleared from the mask.  Returns the players it started for. */
s32 SendTransferToPlayers(s32 playerMask, M2C_UNK data, M2C_UNK size) {
    s32 playerBit;
    s32 mask;
    u8 playerId;

    mask = playerMask;
    playerId = 0;
    do {
        if (playerId != 0) playerBit = 1 << playerId;
        else playerBit = 1;
        if ((mask & playerBit) && (playerId != GetLocalPlayerId()) && (SendTransferToPeer(playerId, data, size) == 0)) mask &= ~playerBit;
        playerId += 1;
    } while ((u32)playerId < TRANSFER_SLOT_COUNT);
    return mask;
}

/* Send raw data straight to one player's connection (no transfer slot): refused
 * on a network error, on an inactive connection, or when the size exceeds the
 * transfer manager's per-frame chunk.  The manager's onSent callback then
 * reports the completed send. */
s32 SendDataToPlayer(u8 playerId, M2C_UNK data, M2C_UNK size) {
    s32 HasNetError(void);
    s32 IsConnectionActive(M2C_UNK);
    void SendConnectionData(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 gTransferManager;
    void (*callback)(s32, s32);
    if (HasNetError() != 0) return 0;
    if (IsConnectionActive(playerId) == 0) return 0;
    if (size > ((TransferManager *)gTransferManager)->chunkSize) return 0;
    SendConnectionData(playerId, data, size, 0);
    callback = ((TransferManager *)gTransferManager)->onSent;
    if (callback != NULL) callback(size, playerId);
    return 1;
}

/* Send `data` of `size` bytes to every player whose identity bit is set in
 * `playerMask`, skipping the local player.  A player the send is refused for
 * (network error, inactive connection, or more than one frame's chunk) is
 * cleared from the mask.  Returns the players the data was accepted for. */
s32 SendDataToPlayers(s32 playerMask, M2C_UNK data, M2C_UNK size) {
    s32 SendDataToPlayer(u8, M2C_UNK, M2C_UNK);
    s32 playerBit;
    s32 mask;
    u8 playerId;

    mask = playerMask;
    playerId = 0;
    do {
        if (playerId != 0) {
            playerBit = 1 << playerId;
        } else {
            playerBit = 1;
        }
        if ((mask & playerBit) && (playerId != GetLocalPlayerId()) && (SendDataToPlayer(playerId, data, size) == 0)) {
            mask &= ~playerBit;
        }
        playerId += 1;
    } while ((u32) playerId < TRANSFER_SLOT_COUNT);
    return mask;
}

/* Point player `playerId`'s transfer slot at `buffer` for the next inbound
 * transfer of `size` bytes; refused while that slot is already receiving. */
s32 SetTransferReceiveBuffer(s32 playerId, void *buffer, s32 size) {
    extern s32 gTransferManager;
    void *GetTransferSlot(s32);
    TransferSlot *slot;

    slot = GetTransferSlot(playerId);
    if (GetTransferState(playerId) == 2) return 0;
    slot->inData = buffer;
    slot->inSize = size;
    slot->state = 1;
    slot->inReceived = 0;
    slot->inExpected = 0;
    return 1;
}

/* Set the transfer manager's send-done callback: it is called with the number
 * of bytes sent and the channel once a transfer is fully queued.  Returns 0 when
 * there is no transfer manager. */
s32 Transfer_SetSentCallback(s32 callback) {
    extern s32 gTransferManager;

    if (!gTransferManager) return 0;
    ((TransferManager *)gTransferManager)->onSent = (void (*)(s32, s32)) callback;
    return 1;
}

/* Install the callback run with (player id, buffer, size) once an incoming
 * transfer completes; returns 0 when no transfer manager exists. */
s32 Transfer_SetReceiveCallback(void (*callback)(s32, void *, s32)) {
    extern s32 gTransferManager;
    if (!gTransferManager) return 0;
    ((TransferManager *)gTransferManager)->onReceived = callback;
    return 1;
}

/* Set how many bytes of a transfer the manager sends per frame; returns 0 when
 * no transfer manager exists. */
s32 Transfer_SetChunkSize(u16 chunkSize) {
    extern s32 gTransferManager;
    if (!gTransferManager) return 0;
    ((TransferManager *)gTransferManager)->chunkSize = chunkSize;
    return 1;
}

/* Build the 8-byte header at `header` that opens a transfer of `size` bytes
 * of `kind`: the payload size, the transfer kind and the magic tag. */
void BuildTransferHeader(void *header, s16 kind, s32 size) {
    void StringCopyPad(void *, void *, s32);
    extern s32 gTransferMagic;

    StringCopyPad((u8 *)header + TRANSFER_HEADER_MAGIC, &gTransferMagic, 2);
    *(s16 *)((u8 *)header + TRANSFER_HEADER_KIND) = kind;
    *(s32 *)((u8 *)header + TRANSFER_HEADER_SIZE) = size;
}

/* Decode an 8-byte transfer header: return its kind when the trailing magic tag
 * matches gTransferMagic, or 0 when the header is not a transfer header. */
u16 GetTransferPacketKind(void *header) {
    void MI_CpuCopy8(void *, void *, s32);
    s32 ByteCompareN(void *, void *, s32);
    extern M2C_UNK gTransferMagic;
    u16 buf[4];
    MI_CpuCopy8(header, buf, 8);
    if (ByteCompareN(&buf[3], &gTransferMagic, 2) == 0) return buf[2];
    return 0;
}

/* Free send-space, in bytes, a transfer of `kind` needs before it may start: one
 * 8-byte transfer header for a data transfer (kind 1), or the header plus a
 * 4-byte payload for the control kinds 2..4. */
s32 GetTransferStartSpace(s32 kind) {
    switch (kind) {
    case 2:
    case 3:
    case 4:
        return 12;
    default:
        return 8;
    }
}

/* Point gTransferManager at `manager`, clear every slot and callback and set the
 * default number of bytes sent per frame. */
void InitTransferManager(void *manager) {
    extern s32 gTransferManager;
    void MI_CpuFill8(s32, s32, s32);
    gTransferManager = (s32) manager;
    MI_CpuFill8((s32) manager, 0, 0x614);
    M2C_FIELD(gTransferManager, u16 *, 0x610) = 0x5b9;
}

/* A transfer packet arrived for peer connection `channel`: a reliable packet is
   run through the transfer protocol (TransferReceivePacket), an unreliable one
   is copied straight into the slot's preset receive buffer
   (TransferReceiveBuffer).  Ignored with no transfer manager or an empty packet. */
void HandleTransferReceive(s32 channel, s32 data, s32 size, s32 reliable) {
    extern s32 gTransferManager;
    void TransferReceivePacket(s32, s32, s32);
    void TransferReceiveBuffer(s32, s32, s32);
    if (!gTransferManager) return;
    if (!data || !size) return;
    if (reliable) TransferReceivePacket(channel, data, size);
    else TransferReceiveBuffer(channel, data, size);
}

/* Forward a connection error code to the transfer manager's onError callback,
 * together with the player id of the connection it came from. */
void ReportTransferError(s32 connection, s32 errorCode)
{
    extern s32 gTransferManager;
    s32 GetConnectionPlayerId(s32);
    s32 playerId;

    if (!((TransferManager *)gTransferManager)->onError) return;
    playerId = GetConnectionPlayerId(connection);
    ((TransferManager *)gTransferManager)->onError(errorCode, playerId);
}

/* Per-frame poll of the transfer slots: time out idle connections and send the
 * next chunk of each outgoing buffer whose destination has room. */
void UpdateTransferSlots(void) {
extern s32 gTransferManager;
s32 GetActiveConnectionList(u8 **);s32 IsConnectionActive(s32);void *GetTransferSlot(s32);
u64 GetSystemTick(void);u64 U64Divide(u64,u64);
s32 GetLocalPlayerId(void);s32 IsTransferSending(s32);s32 GetSendSpace();
void SendConnectionData(s32,s32,s32,s32);
u8 *list; s32 connectionCount,index,playerId; void *p; void *q; s32 chunk; s32 total; u64 now;
if(!gTransferManager)return;
connectionCount=GetActiveConnectionList(&list);
for(index=0;index<connectionCount;index++){
playerId=list[index];
if(IsConnectionActive(playerId)){
p=GetTransferSlot(playerId);
if(((TransferManager *)gTransferManager)->onTimeout && ((TransferSlot *)p)->timeoutMs){
now=GetSystemTick();
if((u32)U64Divide((now-((TransferSlot *)p)->lastTick)<<6,TICKS_TO_MS_DIVISOR)>((TransferSlot *)p)->timeoutMs){
((TransferManager *)gTransferManager)->onTimeout(playerId);
((TransferSlot *)p)->lastTick=now;
}}
}
if(playerId!=GetLocalPlayerId() && IsTransferSending(playerId)==1){
q=GetTransferSlot(playerId);
chunk=((TransferManager *)gTransferManager)->chunkSize;
if(((TransferSlot *)q)->outSize-((TransferSlot *)q)->outSent<=chunk)chunk=((TransferSlot *)q)->outSize-((TransferSlot *)q)->outSent;
if(GetSendSpace(playerId)>=chunk){
SendConnectionData(playerId,((TransferSlot *)q)->outData+((TransferSlot *)q)->outSent,chunk,1);
((TransferSlot *)q)->outSent+=chunk;
total=((TransferSlot *)q)->outSize;
if(((TransferSlot *)q)->outSent==total){
((TransferSlot *)q)->sending=0;((TransferSlot *)q)->outData=0;
((TransferSlot *)q)->outSent=0;((TransferSlot *)q)->outSize=0;
if(((TransferManager *)gTransferManager)->onSent)((TransferManager *)gTransferManager)->onSent(total,playerId);
}}}
}
}

/* Resets one player's transfer slot after the player dropped: clears the
 * progress of both directions, stops sending, clears the transfer kind and puts
 * a transfer that was still active back to its idle state. */
void ResetTransferSlot(s32 playerId) {
    extern s32 gTransferManager;
    if (!gTransferManager) return;
    ((TransferSlot *)(gTransferManager + playerId * 0x30))->outSent = 0;
    ((TransferSlot *)(gTransferManager + playerId * 0x30))->inReceived = 0;
    ((TransferSlot *)(gTransferManager + playerId * 0x30))->outSize = 0;
    ((TransferSlot *)(gTransferManager + playerId * 0x30))->inExpected = 0;
    ((TransferSlot *)(gTransferManager + playerId * 0x30))->sending = 0;
    if (((u8 *)(gTransferManager + 0x1d))[playerId * 0x30]) ((u8 *)(gTransferManager + 0x1d))[playerId * 0x30] = 1; /* state */
    ((TransferSlot *)(gTransferManager + playerId * 0x30))->kind = 0;
}

void func_020449dc(void) {
    extern s32 gTransferManager;
    gTransferManager = 0;
}

/* Returns the transfer slot for `playerId`. */
void *GetTransferSlot(s32 playerId) {
    extern s32 gTransferManager;

    return &((TransferManager *)gTransferManager)->slots[playerId];
}

/* Whether player `playerId`'s transfer slot has an outgoing transfer in
 * progress. */
s32 IsTransferSending(s32 playerId) {
    extern s32 gTransferManager;
    return ((TransferSlot *) (gTransferManager + playerId * 0x30))->sending;
}

/* Returns the transfer state of slot `playerId` (a TRANSFER_STATE_* value). */
s32 GetTransferState(s32 playerId) {
    extern s32 gTransferManager;
    return ((TransferSlot *) (gTransferManager + playerId * 0x30))->state;
}

/* Send `size` bytes of `data` to player `playerId`'s GameSpy connection,
 * reliable or not (falls through gt2Send with a null connection when the player
 * has no connection). */
void SendConnectionData(s32 playerId, s32 data, s32 size, s32 reliable) {
    s32 FindPlayerConnection(s32);
    void gt2Send(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    gt2Send(FindPlayerConnection(playerId), data, size, reliable);
}

/* Handle an inbound transfer request for slot `a`: dispatch by the slot's state. */
void TransferReceivePacket(s32 a, s32 b, s32 c) {
    extern s32 gTransferManager;
    s32 GetConnectionPlayerId(s32);
    s32 GetTransferState(s32);
    u16 GetTransferPacketKind(void *);
    void DispatchConnectionNotice(M2C_UNK, M2C_UNK);
    void func_02044bf8(s32, s32, s32);
    void TransferReceiveData(s32, void *, s32);
    void SetNetError(s32, s32);

    s32 id = GetConnectionPlayerId(a);
    u32 kind;

    switch (GetTransferState(id)) {
    case 0:
        kind = GetTransferPacketKind((void *)b);
        if (kind < 2) return;
        if (kind > 4) return;
        func_02044bf8(id, b, c);
        break;
    case 1:
        func_02044bf8(id, b, c);
        break;
    case 2:
        TransferReceiveData(id, (void *)b, c);
        break;
    case 3:
        ((void (*)(s32, s32, s32))DispatchConnectionNotice)(id, b, c);
        break;
    case 4:
        M2C_FIELD(gTransferManager + id * 0x30, u8 *, 0x1d) = 1;
        M2C_FIELD(gTransferManager + id * 0x30, s32 *, 0x10) = 0;
        M2C_FIELD(gTransferManager + id * 0x30, s32 *, 0x18) = 0;
        break;
    default:
        SetNetError(6, 0xfffe82b6);
        break;
    }
}

/* Deliver one whole inbound transfer buffer for the connection's slot: copy size
 * bytes into the slot's inbound buffer, report the completed buffer through the
 * manager's onReceived, and restart the slot's idle timer when it has one. */
void TransferReceiveBuffer(s32 channel,s32 data,s32 size){
extern s32 gTransferManager;s32 GetConnectionPlayerId(s32);void MI_CpuCopy8(void *,void *,s32);u64 GetSystemTick(void);
TransferSlot *slot;s32 slotId;void (*callback)(s32,void *,s32);
slotId=GetConnectionPlayerId(channel);
slot=(TransferSlot *)(gTransferManager+slotId*0x30);
if(!slot->inData)return;
if(slot->inSize<size)return;
MI_CpuCopy8((void *)data,slot->inData,size);
callback=((TransferManager *)gTransferManager)->onReceived;
if(callback)callback(slotId,slot->inData,size);
if(!((TransferManager *)gTransferManager)->onTimeout||!slot->timeoutMs)return;
slot->lastTick=GetSystemTick();
}

void func_02044bf8(s32 a,s32 b,s32 c) {
extern s32 gTransferManager;
void *p; s32 v; u8 buf[8];
p=(u8 *)gTransferManager+a*0x30;
M2C_FIELD(p,u8 *,0x1e)=GetTransferState(a);
v=GetTransferPacketKind(b);
switch(v){
case 1:
if(c!=8)return;
MI_CpuCopy8(b,buf,8);
M2C_FIELD(p,s32 *,0x18)=*(s32 *)buf;
M2C_FIELD(p,s32 *,0x10)=0;
if(!M2C_FIELD(p,s32 *,4))goto state3;
if(M2C_FIELD(p,s32 *,8)>=M2C_FIELD(p,s32 *,0x18)) M2C_FIELD(p,u8 *,0x1d)=2;
else goto state4;
break;
state4: M2C_FIELD(p,u8 *,0x1d)=4;
break;
case 2:case 3:case 4:
state3: M2C_FIELD(p,u8 *,0x1d)=3;break;
}
M2C_FIELD(p,u16 *,0x22)=v;
}

/* Append one inbound chunk of an incoming transfer to its slot's buffer; when
 * the expected byte count arrives, flag the transfer done, reset the slot and
 * call the manager's onReceived. Any activity restarts the slot's idle timer. */
void TransferReceiveData(s32 id, void *data, s32 size) {
extern s32 gTransferManager; s32 GetTransferState(s32); void MI_CpuCopy8(void *,void *,s32);void SetNetError(s32,s32);u64 GetSystemTick(void);
void *p;void (*cb)(s32,void *,s32);s32 pos,len;
p=(void *)(gTransferManager+id*0x30);
if(GetTransferState(id)==2){
pos=M2C_FIELD(p,s32 *,0x10);
if(pos+size>M2C_FIELD(p,s32 *,8)){SetNetError(6,0xfffe82ac);return;}
MI_CpuCopy8(data,M2C_FIELD(p,u8 **,4)+pos,size);
}
M2C_FIELD(p,s32 *,0x10)+=size;
len=M2C_FIELD(p,s32 *,0x18);
if(M2C_FIELD(p,s32 *,0x10)==len){
M2C_FIELD(p,u8 *,0x1d)=1;M2C_FIELD(p,s32 *,0x10)=0;M2C_FIELD(p,s32 *,0x18)=0;
cb=M2C_FIELD(gTransferManager,void (**)(s32,void *,s32),0x604);
if(cb)cb(id,M2C_FIELD(p,void **,4),len);
}
if(!M2C_FIELD(gTransferManager,s32 *,0x608)||!M2C_FIELD(p,s32 *,0x2c))return;
M2C_FIELD(p,u64 *,0x24)=GetSystemTick();
}

/* An inbound transfer turned out to be a connection notice (slot claim, sync
 * status or sync done): restore the slot's state from before the transfer and
 * hand the packet to the connection handshake handler ReceiveConnectionPacket. */
void DispatchConnectionNotice(s32 playerId, s32 packet) {
    M2C_UNK ReceiveConnectionPacket(s32, u16, s32);
    void *GetTransferSlot(s32);
    TransferSlot *slot;
    u16 kind;

    slot = GetTransferSlot(playerId);
    slot->state = (u8) slot->prevState;
    kind = slot->kind;
    if ((kind != CONN_NOTICE_PLAYER_SLOT) && (kind != CONN_NOTICE_SYNC_STATUS) && (kind != CONN_NOTICE_SYNC_DONE)) {
        return;
    }
    ReceiveConnectionPacket(playerId, kind, packet);
}

/* Room left for a transfer chunk in playerId's GT2 send buffer: the buffer's
 * free space less TRANSFER_SEND_MARGIN, reported as 0 when that would be
 * negative. */
s32 GetSendSpace(s32 playerId) {
    s32 FindPlayerConnection(s32);
    s32 gti2GetConnectionSendFreeSpace(void *);
    s32 space;

    space = gti2GetConnectionSendFreeSpace((void *)FindPlayerConnection(playerId)) + TRANSFER_SEND_MARGIN;
    if (space <= 0) {
        space = 0;
    }
    return space;
}

