/* 84 functions from 0x0222525C to 0x02226214 (ov009), found by ds-decomp. */
#include "common.h"
#include "ov009_link.h"

/* Close the download-play link: delete the link's live objects (the link actor,
 * the packet sender and the packet receiver), then post the WFC stop command.
 * When the command cannot be queued the link goes to the aborted phase. */
void CloseLinkChannel(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    M2C_UNK SetLinkPhase(M2C_UNK);
    s32 SendLinkStopCommand();
    extern M2C_UNK gLinkActorClass;
    extern M2C_UNK gLinkReceiverClass;
    extern M2C_UNK gLinkSenderClass;
    DeleteSpriteObjectsOfClass(&gLinkActorClass);
    DeleteSpriteObjectsOfClass(&gLinkSenderClass);
    DeleteSpriteObjectsOfClass(&gLinkReceiverClass);
    if (SendLinkStopCommand() != 0) {
        return;
    }
    SetLinkPhase(LINK_PHASE_ABORTED);
}

/* Recovers the download-play link once it breaks or its in-game session ends:
 * delete the in-game sprites, return the state machine to PENDING and re-submit
 * the channel request of the kind the session started with.  In the request
 * phase it only advances the state machine, and in any other phase it closes
 * the channel. */
void RestartLinkSession(void) {
    s32 GetLinkPhase();
    s32 GetLinkRequestKind();
    s32 AdvanceLinkRequestToPending();
    s32 func_ov009_02223b5c();
    s32 func_ov009_02223c08();
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    M2C_UNK SetLinkPhase(M2C_UNK);
    extern M2C_UNK gLinkActorClass, gLinkSenderClass, gLinkReceiverClass;
    s32 phase = GetLinkPhase();
    if (phase == LINK_PHASE_READY) return;
    if (phase == LINK_PHASE_REQUEST) {
        if (AdvanceLinkRequestToPending() != 0) return;
        CloseLinkChannel();
        return;
    }
    if (phase != LINK_PHASE_INGAME && phase != LINK_PHASE_ACTIVE) {
        CloseLinkChannel();
        return;
    }
    SetLinkPhase(LINK_PHASE_PENDING);
    DeleteSpriteObjectsOfClass(&gLinkActorClass);
    DeleteSpriteObjectsOfClass(&gLinkSenderClass);
    DeleteSpriteObjectsOfClass(&gLinkReceiverClass);
    switch (GetLinkRequestKind()) {
    case 0:
        if (func_ov009_02223b5c() != 0) return;
        CloseLinkChannel();
        return;
    case 1:
        if (func_ov009_02223c08() != 0) return;
        CloseLinkChannel();
        return;
    }
}

void CreateLinkDepartureObject(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov009_02226440;
    CreateSpriteObject(&data_ov009_02226440, arg0);
}

/* Ends the single-card link session: flushes the packet queues, deletes the
 * link's live sprites, drops both WFC channel event handlers and asks Wi-Fi to
 * close the link.  Returns 1 once the close command is queued, 0 after a link
 * error. */
s32 EndLinkSession(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    M2C_UNK SetLinkPhase(M2C_UNK);
    M2C_UNK ResetLinkQueues();
    M2C_UNK SignalLinkError();
    M2C_UNK ClearLinkResultFlags();
    s32 WFC_SetChannelHandler(s32, s32, s32);
    s32 WFC_EndLink(void *);
    void HandleLinkEndTaskEvent(void);
    extern M2C_UNK gLinkActorClass, gLinkSenderClass, gLinkReceiverClass;
    SetLinkPhase(LINK_PHASE_READY);
    ResetLinkQueues();
    DeleteSpriteObjectsOfClass(&gLinkActorClass);
    DeleteSpriteObjectsOfClass(&gLinkSenderClass);
    DeleteSpriteObjectsOfClass(&gLinkReceiverClass);
    if (WFC_SetChannelHandler(0xC, 0, 0) != 0) {
        SignalLinkError();
        SetLinkPhase(LINK_PHASE_ERROR);
        return 0;
    }
    if (WFC_SetChannelHandler(4, 0, 0) != 0) {
        SignalLinkError();
        SetLinkPhase(LINK_PHASE_ERROR);
        return 0;
    }
    if (WFC_EndLink(&HandleLinkEndTaskEvent) != 2) {
        SignalLinkError();
        SetLinkPhase(LINK_PHASE_ERROR);
        return 0;
    }
    ClearLinkResultFlags();
    return 1;
}

void func_ov009_02225420(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov009_02226468;
    CreateSpriteObject(&data_ov009_02226468, arg0);
}

void func_ov009_02225438(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov009_02226490;
    CreateSpriteObject(&data_ov009_02226490, arg0);
}

s32 GetLinkLocalPlayerId(void) {
    s32 WFC_GetLocalPlayerIndex();
    return WFC_GetLocalPlayerIndex() & 0xFF;
}

u8 GetLinkLocalPlayerSlot(void) {
    extern M2C_UNK gLinkState;
    return M2C_FIELD(&gLinkState, u8 *, 0x157);
}

void func_ov009_02225470(void) {
    M2C_UNK CountBits();
    M2C_UNK GetConnectedPlayers();
    GetConnectedPlayers();
    CountBits();
}

void ClearLinkEventFlags(void) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, s16 *, 8) = 0;
}

u16 GetLinkEventFlags(void) {
    extern M2C_UNK gLinkState;
    return M2C_FIELD(&gLinkState, u16 *, 8);
}

s32 IsLinkHost(void) {
    s32 GetLinkLocalPlayerId();
    if ((GetLinkPhase() != 4) && (GetLinkPhase() != 5)) {
        return 1;
    }
    if (GetLinkLocalPlayerId() == 0) {
        return 1;
    }
    return 0;
}

s32 IsLinkGuest(void) {
    if ((GetLinkPhase() != 4) && (GetLinkPhase() != 5)) {
        return 0;
    }
    if (GetLinkLocalPlayerId() != 0) {
        return 1;
    }
    return 0;
}

/* Begin the link match-start handshake: fill the start record with the match id
 * and this console's acknowledgement bit, install it in the link state and, when
 * this console is the link host, send the start request to the peers. */
M2C_UNK SubmitLinkStartRecord(void *record, s32 matchId) {
    M2C_UNK QueueHostLinkPacket(s32, void *, s32, s32);
    extern M2C_UNK gLinkState;
    M2C_FIELD(record, s32 *, LINK_START_RECORD_ID) = matchId;
    M2C_FIELD(record, u16 *, LINK_START_RECORD_ACKS) = 1 << GetLinkLocalPlayerId();
    M2C_FIELD(&gLinkState, void **, LINK_STATE_START_RECORD) = record;
    if (IsLinkHost() == 0) return;
    QueueHostLinkPacket(LINK_MSG_START_REQUEST, M2C_FIELD(&gLinkState, void **, LINK_STATE_START_RECORD), 8, 0xFFFF);
}

/* Reports whether every connected player has acknowledged this console's
 * match-start request: the request record must be there and its ack mask must
 * cover all connected players, the link must not have failed and this console
 * must be connected as player 0.  While that is false, the link host re-sends
 * the start request.  The caller's argument is not used by the original. */
s32 IsLinkStartAcknowledged(s32 arg0) {
    s32 GetConnectedPlayers();
    s32 GetLinkPhase();
    M2C_UNK QueueHostLinkPacket(s32, void *, s32, s32);
    extern M2C_UNK gLinkState;
    s32 connected;
    s32 acknowledged;
    connected = GetConnectedPlayers();
    acknowledged = 0;
    if (M2C_FIELD(&gLinkState, void **, LINK_STATE_START_RECORD) != NULL &&
        connected != (connected & M2C_FIELD(M2C_FIELD(&gLinkState, void **, LINK_STATE_START_RECORD), u16 *, LINK_START_RECORD_ACKS))) acknowledged = 1;
    if (GetLinkPhase() == LINK_PHASE_ERROR || GetLinkPhase() == LINK_PHASE_ABORTED) acknowledged = 0;
    if (!(connected & 1)) acknowledged = 0;
    if (acknowledged == 0 && IsLinkHost() != 0)
        QueueHostLinkPacket(LINK_MSG_START_ACK, M2C_FIELD(&gLinkState, void **, LINK_STATE_START_RECORD), 8, 0xFFFF);
    return acknowledged;
}

void func_ov009_022255ec() {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, void **, 0x48) = NULL;
}

void func_ov009_02225600(void *arg0) {
    M2C_UNK SubmitLinkStartRecord(void *, s32);
    SubmitLinkStartRecord(arg0 + 0x38, M2C_FIELD(arg0, s32 *, 0x34));
}

s32 func_ov009_02225614(s32 arg0) {
    s32 IsLinkStartAcknowledged(s32);
    if ((GetLinkPhase() != 4) && (GetLinkPhase() != 5)) {
        return 0;
    }
    return IsLinkStartAcknowledged(arg0 + 0x38);
}

void func_ov009_02225644(s32 arg0) {
    void func_ov009_022255ec();
    func_ov009_022255ec(arg0 + 0x38);
}

/* Create the link match-start request node (class gLinkStartRequestClass) owned by
 * `owner` and tagged with `matchId`, but only while the link is in an active game
 * phase.  Installs the node's vtable and returns it, or NULL on failure. */
void *CreateLinkStartRequest(s32 matchId, M2C_UNK owner) {
    extern M2C_UNK gLinkStartRequestClass;
    extern M2C_UNK gLinkStartRequestVtbl;
    s32 GetLinkPhase();
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    void *node;

    if ((GetLinkPhase() != LINK_PHASE_ACTIVE) && (GetLinkPhase() != LINK_PHASE_INGAME)) {
        return NULL;
    }
    node = CreateSpriteObject(&gLinkStartRequestClass, owner);
    if (node != NULL) {
        M2C_FIELD(node, M2C_UNK **, 0) = &gLinkStartRequestVtbl;
        M2C_FIELD(node, s32 *, 0x34) = matchId;
    }
    return node;
}

M2C_UNK func_ov009_022256a4(s32 arg0) {
    s32 AnnounceLinkPlayer();
    extern M2C_UNK gLinkState;
    M2C_FIELD(arg0, u16 *, 2) = 1 << GetLinkLocalPlayerId();
    M2C_FIELD(arg0, u8 *, 0) = AnnounceLinkPlayer();
    M2C_FIELD(&gLinkState, s32 *, 0x20) = arg0;
}

/* Whether the player announcement this console started is still waiting for
 * replies: it counts as pending only during an active game, once the announcement
 * went out, while some connected player slot has not answered it yet. */
s32 IsPlayerAnnouncePending(s32 actor) {
    s32 GetConnectedPlayers();
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    s32 connected, mask, pending;
    if (M2C_FIELD(&gLinkState, void * volatile *, LINK_STATE_ANNOUNCE_REQUEST) != NULL &&
        (connected = GetConnectedPlayers(), mask = GetConnectedPlayers(),
         connected != (M2C_FIELD(M2C_FIELD(&gLinkState, void **, LINK_STATE_ANNOUNCE_REQUEST), u16 *, LINK_REQUEST_PLAYERS) & mask))) pending = 1;
    else pending = 0;
    if (M2C_FIELD(M2C_FIELD(&gLinkState, void **, LINK_STATE_ANNOUNCE_REQUEST), u8 *, LINK_REQUEST_SENT) == 0) pending = 0;
    if (GetLinkPhase() != LINK_PHASE_ACTIVE && GetLinkPhase() != LINK_PHASE_INGAME) pending = 0;
    if (GetLinkPhase() == LINK_PHASE_ERROR || GetLinkPhase() == LINK_PHASE_ABORTED) pending = 0;
    return pending;
}

void func_ov009_02225768(s32 arg0) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, void **, 0x20) = NULL;
}

void func_ov009_0222577c(s32 arg0) {
    M2C_UNK func_ov009_022256a4(s32);
    func_ov009_022256a4(arg0 + 0x34);
}

void func_ov009_0222578c(s32 arg0) {
    M2C_UNK IsPlayerAnnouncePending(s32);
    IsPlayerAnnouncePending(arg0 + 0x34);
}

void func_ov009_0222579c(s32 arg0) {
    void func_ov009_02225768(s32);
    func_ov009_02225768(arg0 + 0x34);
}

void SpawnLinkPlayerAnnounce(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_022266ec;
    extern M2C_UNK data_ov009_02226588;
    M2C_UNK **temp_r0;

    temp_r0 = CreateSpriteObject(&data_ov009_02226588, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_022266ec;
    }
}

M2C_UNK func_ov009_022257d4(s32 arg0) {
    M2C_UNK RequestConnectedPlayers();
    extern M2C_UNK gLinkState;
    M2C_FIELD(arg0, u8 *, 0) = 0;
    M2C_FIELD(arg0, u16 *, 2) = 0;
    M2C_FIELD(&gLinkState, s32 *, 0x24) = arg0;
    return RequestConnectedPlayers();
}

/* Whether this console's connected-players request is still waiting: the request
 * slot must hold a record that has been sent, the link must be in an active
 * phase (4 or 5) and this console must not be the host; the error and abort
 * phases always stop it waiting.  The actor argument is unused. */
s32 IsConnectRequestPending(s32 actor) {
    extern M2C_UNK gLinkState;
    s32 pending = 0;
    if (M2C_FIELD(&gLinkState, void **, LINK_STATE_CONNECT_REQUEST) != NULL &&
        M2C_FIELD(M2C_FIELD(&gLinkState, void **, LINK_STATE_CONNECT_REQUEST), u8 *, LINK_REQUEST_SENT) != 0) pending = 1;
    if (GetLinkPhase() != LINK_PHASE_ACTIVE && GetLinkPhase() != LINK_PHASE_INGAME) pending = 0;
    if (IsLinkHost() != 0) pending = 0;
    if (GetLinkPhase() == LINK_PHASE_ERROR || GetLinkPhase() == LINK_PHASE_ABORTED) pending = 0;
    return pending;
}

void func_ov009_02225864() {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, void **, 0x24) = NULL;
}

void func_ov009_02225878(s32 arg0) {
    M2C_UNK func_ov009_022257d4(s32);
    func_ov009_022257d4(arg0 + 0x34);
}

void func_ov009_02225888(s32 arg0) {
    M2C_UNK IsConnectRequestPending(s32);
    IsConnectRequestPending(arg0 + 0x34);
}

void func_ov009_02225898(s32 arg0) {
    void func_ov009_02225864();
    func_ov009_02225864(arg0 + 0x34);
}

void func_ov009_022258a8(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_022266d8;
    extern M2C_UNK data_ov009_022265c0;
    M2C_UNK **temp_r0;

    temp_r0 = CreateSpriteObject(&data_ov009_022265c0, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_022266d8;
    }
}

s32 func_ov009_022258d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg3, 0, arg1);
    *(s32 *)arg4 = 0;
    return 1;
}

s32 func_ov009_022258f8(void) {
    return 0;
}

void func_ov009_02225900(void *arg0) {
    M2C_UNK func_ov009_022258d0(s32, s32, s32, s32, s32);
    func_ov009_022258d0(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), M2C_FIELD(arg0, s32 *, 0x44));
}

void func_ov009_02225928(void) {
    M2C_UNK func_ov009_022258f8();
    func_ov009_022258f8();
}

void func_ov009_02225934(void) {

}

/* Creates the local-wireless match-request node: a sprite object of
 * gLocalMatchRequestClass, owned by `owner`, whose search parameters (name table,
 * name count, game type, timeout and flags) are copied into the request fields the
 * node's step reads back.  The online overlay's CreateOnlineMatchRequest builds the
 * same node over gOnlineMatchRequestClass. */
void CreateLocalMatchRequest(s32 names, s32 nameCount, s32 type, s32 timeout, s32 flags, s32 owner) {
    extern M2C_UNK gLocalMatchRequestClass;
    extern M2C_UNK gLocalMatchRequestVtbl;
    void *request;

    request = CreateSpriteObject(&gLocalMatchRequestClass, owner);
    if (request == NULL) {
        return;
    }
    M2C_FIELD(request, M2C_UNK **, 0) = &gLocalMatchRequestVtbl;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_NAMES) = names;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_NAME_COUNT) = nameCount;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_TYPE) = type;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_TIMEOUT) = timeout;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_FLAGS) = flags;
}

/* Broadcasts the local player's record and name to the other connected peers
 * (link message 13), keeping the local player's bit in the actor's mask while
 * the announcement is in flight; outside the in-game phases it only resets
 * that mask. */
void BroadcastLinkPlayerInfo(void *maskPtr) {
    s32 CopyLocalPlayerRecord(void *);
    s32 MI_CpuFill8(s32, s32, s32);
    s32 GetLocalPlayerName();
    s32 GetLocalPlayerNameLength(void);
    void MI_CpuCopy8(void *, void *, s32);
    M2C_UNK QueueHostLinkPacket(s32, void *, s32, s32);
    extern M2C_UNK gLinkState;
    u8 packet[LINK_PLAYER_INFO_SIZE];
    u16 peers;
    void *name;
    if (GetLinkPhase()!=LINK_PHASE_ACTIVE && GetLinkPhase()!=LINK_PHASE_INGAME) {
        M2C_FIELD(maskPtr, u16 *, 0)=1<<GetLinkLocalPlayerId();
        M2C_FIELD(&gLinkState, void **, LINK_STATE_ANNOUNCE)=NULL;
        return;
    }
    if(CopyLocalPlayerRecord(packet)) {
        M2C_FIELD(maskPtr, u16 *, 0)=1<<GetLinkLocalPlayerId();
        M2C_FIELD(&gLinkState, void **, LINK_STATE_ANNOUNCE)=(void *)maskPtr;
        peers=0xFFFF;
        peers &= (-1 ^ (1U<<GetLinkLocalPlayerId()));
        if(!peers) return;
        MI_CpuFill8((s32)(packet+LINK_PLAYER_NAME_OFFSET),0,LINK_PLAYER_NAME_SIZE);
        name=(void *)GetLocalPlayerName();
        MI_CpuCopy8(name,packet+LINK_PLAYER_NAME_OFFSET,GetLocalPlayerNameLength()*2);
        QueueHostLinkPacket(LINK_MSG_PLAYER_INFO,packet,LINK_PLAYER_INFO_SIZE,peers);
    } else {
        M2C_FIELD(maskPtr, u16 *, 0)=1<<GetLinkLocalPlayerId();
        M2C_FIELD(&gLinkState, void **, LINK_STATE_ANNOUNCE)=NULL;
    }
}

/* Whether this console's player-info announcement is still incomplete: true while
 * an announce mask is registered in the link state and it does not yet cover every
 * connected player.  The caller's argument is not used. */
s32 IsLinkAnnounceIncomplete(s32 unused) {
    s32 GetConnectedPlayers();
    extern M2C_UNK gLinkState;
    s32 connected, connectedMask;

    if (M2C_FIELD(&gLinkState, void **, LINK_STATE_ANNOUNCE) != NULL) {
        connected = GetConnectedPlayers();
        connectedMask = GetConnectedPlayers();
        if (connected != (*M2C_FIELD(&gLinkState, u16 **, LINK_STATE_ANNOUNCE) & connectedMask)) return 1;
    }
    return 0;
}

void func_ov009_02225ae0(s32 arg0) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, void **, 0x28) = NULL;
}

void func_ov009_02225af4(s32 arg0) {

    BroadcastLinkPlayerInfo(arg0 + 0x34);
}

s32 func_ov009_02225b04(s32 arg0) {
    s32 IsLinkAnnounceIncomplete(s32);
    if ((GetLinkPhase() != 4) && (GetLinkPhase() != 5)) {
        return 0;
    }
    return IsLinkAnnounceIncomplete(arg0 + 0x34);
}

void func_ov009_02225b34(s32 arg0) {
    void func_ov009_02225ae0(s32);
    func_ov009_02225ae0(arg0 + 0x34);
}

void func_ov009_02225b44(void *arg0) {
    M2C_UNK CreateLocalBattleSaveSprite(s32);
    CreateLocalBattleSaveSprite(M2C_FIELD(arg0, s32 *, 0x18));
}

void func_ov009_02225b54(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_0222669c;
    extern M2C_UNK data_ov009_022265f8;
    M2C_UNK **temp_r0;

    temp_r0 = CreateSpriteObject(&data_ov009_022265f8, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_0222669c;
    }
}

void func_ov009_02225b7c(void) {

}

s32 func_ov009_02225b80(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void *func_ov009_02225b94(void *arg0) {
    M2C_UNK FreeLinkPacket();
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        FreeLinkPacket();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    return arg0;
}

void *func_ov009_02225bbc(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        FreeLinkPacket();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    MemFree(arg0);
    return arg0;
}

s32 func_ov009_02225bec(s32 arg0) {
    M2C_UNK DestroyArray(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov009_0222497c;
    DestroyArray(arg0 + 0x34, 4, 8, &func_ov009_0222497c);
    return arg0;
}

s32 func_ov009_02225c14(s32 arg0) {
    M2C_UNK DestroyArray(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov009_0222497c;
    DestroyArray(arg0 + 0x34, 4, 8, &func_ov009_0222497c);
    MemFree(arg0);
    return arg0;
}

void func_ov009_02225c44(void) {

}

s32 func_ov009_02225c48(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov009_02225c5c(void) {

}

s32 func_ov009_02225c60(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov009_02225c74(void) {

}

s32 func_ov009_02225c78(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov009_02225c8c(void) {

}

s32 func_ov009_02225c90(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov009_02225ca4(void) {

}

s32 func_ov009_02225ca8(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov009_02225cbc(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC4) = 0;
}

void func_ov009_02225ccc(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

s32 func_ov009_02225ce0(s32 arg0, s32 arg1) {
    s32 GetLinkPhase();
    switch (GetLinkPhase()) {
    case 8:
    case 9:
        return 0;
    default:
        return arg1 != GetLinkPhase();
    }
}

void func_ov009_02225d14(void) {
    M2C_UNK DetachSpriteFromParent();
    DetachSpriteFromParent();
}

/* Link's error/abort outcome: on the ERROR or ABORTED phase, show the link status
 * message once (bit 1 of the result flags) and hand the link result code plus the
 * object's stored value to the completion callback at +0x34. */
void HandleLinkErrorResult(void *object) {
    M2C_UNK GetLocalizedText(s32);
    s32 GetLinkResultCode();
    M2C_UNK SetLinkResultFlag(M2C_UNK);
    s32 IsLinkResultFlagSet(M2C_UNK);
    M2C_UNK (*callback)(s32, s32);
    s32 resultCode;

    if ((GetLinkPhase() != LINK_PHASE_ERROR) && (GetLinkPhase() != LINK_PHASE_ABORTED)) {
        return;
    }
    resultCode = GetLinkResultCode();
    if (IsLinkResultFlagSet(1) != 0) {
        return;
    }
    GetLocalizedText(LINK_STATUS_TEXT);
    SetLinkResultFlag(1);
    callback = M2C_FIELD(object, M2C_UNK (**)(s32, s32), 0x34);
    if (callback == NULL) {
        return;
    }
    callback(resultCode, M2C_FIELD(object, s32 *, 0x18));
}

void func_ov009_02225d88(s32 arg0) {
    void *CreateSpriteFromClass(void *);
    extern M2C_UNK data_ov009_02226874, data_ov009_02226750;
    void *temp_r0;
    temp_r0 = CreateSpriteFromClass(&data_ov009_02226874);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, void **, 0) = &data_ov009_02226750;
        M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    }
}

void func_ov009_02225db4(void) {
    M2C_UNK DeleteSpriteObject();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov009_02226874;
    if (FindObjectByClass(&data_ov009_02226874) == 0) {
        return;
    }
    DeleteSpriteObject();
}

/* Start the split-screen fade on each screen whose earlier split transition has
 * finished: bits 1 and 2 of the sprite's flags mark the main and sub screens
 * that are waiting for it, and each fade starts once GetScreenFlag says that
 * screen's transition is no longer running. */
void StartLinkSplitFades(void *sprite) {
    s32 GetScreenFlag(M2C_UNK);
    M2C_UNK StartScreenFadeChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(sprite, u8 *, 0x34) & 1) && (GetScreenFlag(0) == 0)) {
        StartScreenFadeChildren(2, 8, 0, sprite);
    }
    if (!(M2C_FIELD(sprite, u8 *, 0x34) & 2)) {
        return;
    }
    if (GetScreenFlag(1) != 0) {
        return;
    }
    StartScreenFadeChildren(2, 8, 1, sprite);
}

/* Redraws a link status-text layer: looks up its localized text and style,
 * (re)creates the text on each display bank the layer selects, and drops the
 * stale level. */
void RefreshLinkMessageText(void *layer) {
    s32 FindTextLayer();
    M2C_UNK StartWindowClose();
    M2C_UNK RenderTextLayer(void *, u8, s32, s32);
    void *CreateTextLayer(void *);
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain, gCur3DSpriteEngine;
    void *created;
    u32 styleByte;
    s32 style;
    s32 text;
    s32 i;
    s32 savedBank;
    u32 bank;
    s8 engine;

    if (M2C_FIELD(layer, s32 *, LINK_LAYER_STATUS) == 0) return;
    if (FindTextLayer()) StartWindowClose();
    text = GetLocalizedText(M2C_FIELD(layer, s32 *, LINK_LAYER_TEXT_KEY));
    style = M2C_FIELD(layer, s32 *, LINK_LAYER_STYLE);
    savedBank = gCur3DSpriteEngine; i = 0; styleByte = style;
    do {
        if (i == 0) bank = g3DSpriteEngineMain; else bank = g3DSpriteEngineSub;
        gCur3DSpriteEngine = bank; engine = M2C_FIELD(layer, s8 *, TEXT_LAYER_ENGINE);
        if (engine == 0 && bank != g3DSpriteEngineMain) continue;
        if (engine == 1 && bank != g3DSpriteEngineSub) continue;
        if (engine == 3 && bank != savedBank) continue;
        created = CreateTextLayer(layer);
        RenderTextLayer(created, styleByte, M2C_FIELD(layer, u16 *, TEXT_LAYER_VALUE) << 5, text);
        M2C_FIELD(created, s32 *, 0x58) |= 0x1400;
        if (style == 0) M2C_FIELD(created, s32 *, 0x58) |= 0x800;
    } while (++i < 2);
    gCur3DSpriteEngine = savedBank;
    func_ov009_02225db4();
}

void func_ov009_02225f44(void) {

}

/* Create the split-screen transition on each screen whose transition flag is
 * currently set, and set that screen's bit (1 main, 2 sub) in the sprite's
 * flags so StartLinkSplitFades knows to start its split fade once the
 * transition has finished. */
void StartLinkSplitTransitions(void *sprite) {
    M2C_UNK CreateScreenTransitionChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (GetScreenFlag(0) == 1) {
        CreateScreenTransitionChildren(2, 8, 0, sprite);
        M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 1);
    }
    if (GetScreenFlag(1) != 1) {
        return;
    }
    CreateScreenTransitionChildren(2, 8, 1, sprite);
    M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 2);
}

/* Creates the link overlay's status-text label for `owner`: it shows the
 * general link status message, or the status-8 variant, on the requested
 * display engine at the given text value.  Does nothing for status 0. */
M2C_UNK CreateLinkStatusLabel(s8 engine, u16 textValue, s32 status, void *owner) {
    void *CreateSpriteForOwner(void *, void *);
    extern M2C_UNK gLinkStatusLabelClass, gLinkStatusLabelVTable;
    void *label;
    if (status == 0) return;
    label = CreateSpriteForOwner(&gLinkStatusLabelClass, owner);
    if (label == NULL) return;
    M2C_FIELD(label, void **, 0) = &gLinkStatusLabelVTable;
    M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) = 0;
    M2C_FIELD(label, s8 *, TEXT_LAYER_ENGINE) = engine;
    M2C_FIELD(label, u16 *, TEXT_LAYER_VALUE) = textValue;
    M2C_FIELD(label, s32 *, LINK_LAYER_STATUS) = status;
    if (status == 8) {
        M2C_FIELD(label, s32 *, LINK_LAYER_TEXT_KEY) = LINK_STATUS_TEXT_CODE8;
        M2C_FIELD(label, s32 *, LINK_LAYER_STYLE) = 0;
        return;
    }
    M2C_FIELD(label, s32 *, LINK_LAYER_TEXT_KEY) = LINK_STATUS_TEXT;
    M2C_FIELD(label, s32 *, LINK_LAYER_STYLE) = 2;
}

/* Link-status screen update: start the split-screen fade on each screen whose
 * earlier split transition has finished.  Bits 1 and 2 of the sprite's flags
 * mark the main and sub screens that are waiting for the fade. */
void StartLinkStatusSplitFades(void *sprite) {
    if ((M2C_FIELD(sprite, u8 *, 0x34) & 1) && (GetScreenFlag(0) == 0)) {
        StartScreenFadeChildren(2, 8, 0, sprite);
    }
    if (!(M2C_FIELD(sprite, u8 *, 0x34) & 2)) {
        return;
    }
    if (GetScreenFlag(1) != 0) {
        return;
    }
    StartScreenFadeChildren(2, 8, 1, sprite);
}

/* Create the status labels of the ov009 link-status host object: its status label
 * (drawn on the host's engine at the host's text value) and its match-name label.
 * Nothing is created while the host has no status code. */
void CreateLinkStatusLabels(void *host) {
    M2C_UNK CreateLinkStatusLabel(s8, u16, s32, void *);
    void CreateLinkMatchNameLabel(M2C_UNK, u16, void *);
    s32 status;

    status = M2C_FIELD(host, s32 *, LINK_LABEL_HOST_STATUS);
    if (status == 0) {
        return;
    }
    CreateLinkStatusLabel(M2C_FIELD(host, s8 *, TEXT_LAYER_ENGINE), M2C_FIELD(host, u16 *, TEXT_LAYER_VALUE), status, host);
    CreateLinkMatchNameLabel(-1, M2C_FIELD(host, u16 *, TEXT_LAYER_VALUE), host);
}

void func_ov009_022260d8(void) {

}

/* Link-status screen update: create the split-screen transition on each screen
 * whose transition flag is set, and set that screen's bit (1 main, 2 sub) in the
 * sprite's flags so StartLinkStatusSplitFades starts its fade afterwards. */
void StartLinkStatusSplitTransitions(void *sprite) {
    if (GetScreenFlag(0) == 1) {
        CreateScreenTransitionChildren(2, 8, 0, sprite);
        M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 1);
    }
    if (GetScreenFlag(1) != 1) {
        return;
    }
    CreateScreenTransitionChildren(2, 8, 1, sprite);
    M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 2);
}

void func_ov009_02226148(void) {
    M2C_UNK DisableMapConfirm();
    DisableMapConfirm();
}

void func_ov009_02226154(void) {
    M2C_UNK CreateSubScreenLinkIndicator();
    M2C_UNK func_020852e0();
    M2C_UNK EnableMapConfirm();
    s32 GetLinkPhase();
    if (GetLinkPhase() == 1) {
        EnableMapConfirm();
        CreateSubScreenLinkIndicator();
        return;
    }
    DisableMapConfirm();
    func_020852e0();
}

/* Link-mode player name label: while the link is idle, announce the local player's
 * name over the download-play link and create the label sprite; once a link is
 * under way, only enable the map-confirm prompt.  The online variant's x/y are
 * unused here. */
void CreateLinkNameLabel(s32 unusedX, s32 unusedY, void *owner) {
    void *CreateSpriteForOwner(void *, void *);
    s32 GetLocalPlayerName();
    M2C_UNK ClearLinkCommandQueues();
    M2C_UNK SetLinkDownloadCode(s32);
    M2C_UNK SetLinkPlayerName(s32, M2C_UNK);
    s32 func_ov009_022242c8();
    M2C_UNK ClearLinkResultFlag(M2C_UNK);
    M2C_UNK func_ov009_0222454c();
    extern M2C_UNK gLinkNameLabelClass;
    if (GetLinkPhase() != LINK_PHASE_IDLE) {
        EnableMapConfirm();
        return;
    }
    DisableMapConfirm();
    ClearLinkResultFlag(1);
    if (func_ov009_022242c8() == 0) return;
    func_ov009_0222454c();
    SetLinkDownloadCode(0x654);
    SetLinkPlayerName(GetLocalPlayerName(), 0x14);
    ClearLinkCommandQueues();
    CreateSpriteForOwner(&gLinkNameLabelClass, owner);
}

void CreateLinkMatchNameLabel(M2C_UNK arg0, u16 arg1, void *arg2) {
    s32 GetLinkPhase(void);
    M2C_UNK EnableMapConfirm(void);
    void *CreateSpriteForOwner(void *, void *);
    extern M2C_UNK gLinkMatchNameLabelClass;
    if (GetLinkPhase() == 0) {
        EnableMapConfirm();
        return;
    }
    CreateSpriteForOwner(&gLinkMatchNameLabelClass, arg2);
}

