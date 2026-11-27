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
    s32 RestartLinkHostSession();
    s32 TeardownLinkAndQueueSetup();
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
        if (RestartLinkHostSession() != 0) return;
        CloseLinkChannel();
        return;
    case 1:
        if (TeardownLinkAndQueueSetup() != 0) return;
        CloseLinkChannel();
        return;
    }
}

/* Create the single-card link's departure object, owned by `owner`: its class
 * script recovers the link session (RestartLinkSession) and then waits for the
 * phase that lets the overlay close. */
void CreateLinkDepartureObject(void *owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gLinkDepartureClass;
    CreateSpriteObject(&gLinkDepartureClass, owner);
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

/* Spawn the link-end object under `owner`: its class script ends the link session
 * (EndLinkSession) and then waits for the link phase that lets the overlay close. */
void CreateLinkEndObject(M2C_UNK owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gLinkEndClass;
    CreateSpriteObject(&gLinkEndClass, owner);
}

/* Create the single-card link's leave object, owned by `owner`: its class script
 * first spawns the departure object (which recovers the link session) and then
 * the link-end object (which ends the session and waits for the link phase). */
void CreateLinkLeaveObject(void *owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gLinkLeaveClass;
    CreateSpriteObject(&gLinkLeaveClass, owner);
}

s32 GetLinkLocalPlayerId(void) {
    s32 WFC_GetLocalPlayerIndex();
    return WFC_GetLocalPlayerIndex() & 0xFF;
}

u8 GetLinkLocalPlayerSlot(void) {
    extern M2C_UNK gLinkState;
    return M2C_FIELD(&gLinkState, u8 *, 0x157);
}

void GetLinkConnectedPlayerCount(void) {
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

/* Whether this console is the link's host: outside an established game every
 * console counts as host; in an in-game link only player 0 does. */
s32 IsLinkHost(void) {
    s32 GetLinkLocalPlayerId();
    if ((GetLinkPhase() != LINK_PHASE_ACTIVE) && (GetLinkPhase() != LINK_PHASE_INGAME)) {
        return 1;
    }
    if (GetLinkLocalPlayerId() == 0) {
        return 1;
    }
    return 0;
}

/* Whether this console is a guest of the link: only during an established game,
 * and only when it is not player 0 (the host). */
s32 IsLinkGuest(void) {
    if ((GetLinkPhase() != LINK_PHASE_ACTIVE) && (GetLinkPhase() != LINK_PHASE_INGAME)) {
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

/* Whether the link's start record was acknowledged while the link is in game
 * (LINK_PHASE_ACTIVE or LINK_PHASE_INGAME): `state` + 0x38 is the start record
 * the acknowledgement check looks at. */
s32 IsLinkStartAcknowledgedInGame(s32 state) {
    s32 IsLinkStartAcknowledged(s32);

    if ((GetLinkPhase() != LINK_PHASE_ACTIVE) && (GetLinkPhase() != LINK_PHASE_INGAME)) {
        return 0;
    }
    return IsLinkStartAcknowledged(state + 0x38);
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

/* Fill the player-announcement request record: set this console's player-slot bit,
 * record whether the announcement went out, and install the record as the link
 * state's in-flight announcement (LINK_STATE_ANNOUNCE_REQUEST). */
M2C_UNK SubmitPlayerAnnounceRequest(s32 record) {
    s32 AnnounceLinkPlayer();
    extern M2C_UNK gLinkState;
    M2C_FIELD(record, u16 *, LINK_REQUEST_PLAYERS) = 1 << GetLinkLocalPlayerId();
    M2C_FIELD(record, u8 *, LINK_REQUEST_SENT) = AnnounceLinkPlayer();
    M2C_FIELD(&gLinkState, void **, LINK_STATE_ANNOUNCE_REQUEST) = (void *)record;
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
    M2C_UNK SubmitPlayerAnnounceRequest(s32);
    SubmitPlayerAnnounceRequest(arg0 + 0x34);
}

void func_ov009_0222578c(s32 arg0) {
    M2C_UNK IsPlayerAnnouncePending(s32);
    IsPlayerAnnouncePending(arg0 + 0x34);
}

void func_ov009_0222579c(s32 arg0) {
    void func_ov009_02225768(s32);
    func_ov009_02225768(arg0 + 0x34);
}

/* Create the link player-announce object owned by `owner` and install its
 * vtable at offset 0. */
void SpawnLinkPlayerAnnounce(M2C_UNK owner) {
    extern M2C_UNK gLinkPlayerAnnounceVtbl;
    extern M2C_UNK gLinkPlayerAnnounceClass;
    M2C_UNK **announce;

    announce = CreateSpriteObject(&gLinkPlayerAnnounceClass, owner);
    if (announce != NULL) {
        *announce = &gLinkPlayerAnnounceVtbl;
    }
}

/* Clear the connected-players request record, install it as the link state's
 * in-flight request (LINK_STATE_CONNECT_REQUEST) and send the request. */
M2C_UNK SubmitConnectRequest(s32 request) {
    M2C_UNK RequestConnectedPlayers();
    extern M2C_UNK gLinkState;

    M2C_FIELD(request, u8 *, LINK_REQUEST_SENT) = 0;
    M2C_FIELD(request, u16 *, LINK_REQUEST_PLAYERS) = 0;
    M2C_FIELD(&gLinkState, s32 *, LINK_STATE_CONNECT_REQUEST) = request;
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
    M2C_UNK SubmitConnectRequest(s32);
    SubmitConnectRequest(arg0 + 0x34);
}

void func_ov009_02225888(s32 arg0) {
    M2C_UNK IsConnectRequestPending(s32);
    IsConnectRequestPending(arg0 + 0x34);
}

void func_ov009_02225898(s32 arg0) {
    void func_ov009_02225864();
    func_ov009_02225864(arg0 + 0x34);
}

/* Create the link connect-request node owned by `owner` and install its vtable at
 * offset 0. */
void SpawnLinkConnectRequest(M2C_UNK owner) {
    extern M2C_UNK gLinkConnectRequestVtbl;
    extern M2C_UNK gLinkConnectRequestClass;
    M2C_UNK **request;

    request = CreateSpriteObject(&gLinkConnectRequestClass, owner);
    if (request != NULL) {
        *request = &gLinkConnectRequestVtbl;
    }
}

/* Local counterpart of the online overlay's WFC match query: clear `nameCount`
 * bytes of the search's result buffer and its count word, then report the query
 * as running (1). */
s32 RequestLocalWfcMatch(s32 names, s32 nameCount, s32 type, s32 flagsOut, s32 countOut) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    MI_CpuFill8(flagsOut, 0, nameCount);
    *(s32 *)countOut = 0;
    return 1;
}

s32 func_ov009_022258f8(void) {
    return 0;
}

/* Step of the local match-request node: start the match query with the search
 * parameters the node was created with. */
void Ov009_RequestWfcMatch(void *request) {
    M2C_UNK RequestLocalWfcMatch(s32, s32, s32, s32, s32);
    RequestLocalWfcMatch(M2C_FIELD(request, s32 *, MATCH_REQUEST_NAMES), M2C_FIELD(request, s32 *, MATCH_REQUEST_NAME_COUNT), M2C_FIELD(request, s32 *, MATCH_REQUEST_TYPE), M2C_FIELD(request, s32 *, MATCH_REQUEST_TIMEOUT), M2C_FIELD(request, s32 *, MATCH_REQUEST_FLAGS));
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

/* Step of the player-announce sprite during an active game: it keeps running
 * while this console's player announcement (its mask at object +0x34) has not
 * been answered by every connected player.  Outside phases 4 and 5 it is done. */
s32 IsLinkAnnounceIncompleteInGame(s32 sprite) {
    s32 IsLinkAnnounceIncomplete(s32);
    if ((GetLinkPhase() != LINK_PHASE_ACTIVE) && (GetLinkPhase() != LINK_PHASE_INGAME)) {
        return 0;
    }
    return IsLinkAnnounceIncomplete(sprite + 0x34);
}

void func_ov009_02225b34(s32 arg0) {
    void func_ov009_02225ae0(s32);
    func_ov009_02225ae0(arg0 + 0x34);
}

void func_ov009_02225b44(void *arg0) {
    M2C_UNK CreateLocalBattleSaveSprite(s32);
    CreateLocalBattleSaveSprite(M2C_FIELD(arg0, s32 *, 0x18));
}

/* Create the in-game player-info announcer owned by `owner` and install its vtable
 * at offset 0. */
void SpawnLinkPlayerInfoAnnounce(M2C_UNK owner) {
    extern M2C_UNK gLinkPlayerInfoAnnounceVtbl;
    extern M2C_UNK gLinkPlayerInfoAnnounceClass;
    M2C_UNK **announce;

    announce = CreateSpriteObject(&gLinkPlayerInfoAnnounceClass, owner);
    if (announce != NULL) {
        *announce = &gLinkPlayerInfoAnnounceVtbl;
    }
}

void func_ov009_02225b7c(void) {

}

s32 func_ov009_02225b80(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Reset the link's packet sender: free the packet still queued for the transfer
 * being split and clear the slot.  Returns the sender. */
void *ResetLinkSender(void *sender) {
    void FreeLinkPacket(void *packet);

    if (M2C_FIELD(sender, void **, LINK_SENDER_PACKET) != NULL) {
        FreeLinkPacket(M2C_FIELD(sender, void **, LINK_SENDER_PACKET));
        M2C_FIELD(sender, s32 *, LINK_SENDER_PACKET) = 0;
    }
    return sender;
}

/* Destructor of the link's packet sender: free the packet still queued for the
 * transfer being split (LINK_SENDER_PACKET) and release the object itself. */
void *DestroyLinkSender(void *sender) {
    if (M2C_FIELD(sender, s32 *, LINK_SENDER_PACKET) != 0) {
        FreeLinkPacket();
        M2C_FIELD(sender, s32 *, LINK_SENDER_PACKET) = 0;
    }
    MemFree(sender);
    return sender;
}

/* Reset the link's packet receiver: destroy its four per-channel receive-assembly
 * slots (each frees the packet it was piecing together), then return the object. */
s32 ResetLinkReceiver(s32 receiver) {
    M2C_UNK DestroyArray(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK FreeLinkReceiveSlot;
    DestroyArray(receiver + LINK_RECEIVER_CHANNELS, LINK_RECEIVER_COUNT, LINK_RECEIVER_STRIDE, &FreeLinkReceiveSlot);
    return receiver;
}

/* Destructor of the link's packet receiver: destroy its four per-channel
 * receive-assembly slots (each frees the packet it was piecing together) and
 * release the object itself. */
s32 DestroyLinkReceiver(s32 receiver) {
    M2C_UNK DestroyArray(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK FreeLinkReceiveSlot;
    DestroyArray(receiver + LINK_RECEIVER_CHANNELS, LINK_RECEIVER_COUNT, LINK_RECEIVER_STRIDE, &FreeLinkReceiveSlot);
    MemFree(receiver);
    return receiver;
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

/* Link-phase predicate for waiting on a target phase: the first argument is unused
 * (a callback self pointer).  Returns nonzero while the link's current phase
 * differs from `expectedPhase`, but 0 for the terminal ERROR and ABORTED phases so
 * a failed link is never read as the phase having changed. */
s32 func_ov009_02225ce0(s32 arg0, s32 expectedPhase) {
    s32 GetLinkPhase();
    switch (GetLinkPhase()) {
    case LINK_PHASE_ERROR:
    case LINK_PHASE_ABORTED:
        return 0;
    default:
        return expectedPhase != GetLinkPhase();
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

/* Create the overlay's link-result sprite: a sprite of gLinkResultSpriteClass
 * owned by `owner` whose class step reports the link's outcome to `callback`
 * (HandleLinkResult) with the owner handed back. */
void CreateLinkResultSprite(s32 callback, s32 owner) {
    void *CreateSpriteFromClass(void *, s32);
    extern M2C_UNK gLinkResultSpriteClass, gLinkResultSpriteVtbl;
    void *sprite;

    sprite = CreateSpriteFromClass(&gLinkResultSpriteClass, owner);
    if (sprite != NULL) {
        M2C_FIELD(sprite, void **, DS3D_SPRITE_CLASS) = &gLinkResultSpriteVtbl;
        M2C_FIELD(sprite, s32 *, LINK_RESULT_CALLBACK) = callback;
    }
}

/* Delete the overlay's live link-result sprite, if one exists. */
void DeleteLinkResultSprite(void) {
    M2C_UNK DeleteSpriteObject();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gLinkResultSpriteClass;

    if (FindObjectByClass(&gLinkResultSpriteClass) == 0) {
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
    DeleteLinkResultSprite();
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

/* Link-status screen update: during the ready phase, allow the map-confirm prompt
 * and show the sub-screen link indicator; in any other phase, disable the prompt and
 * remove the indicator. */
void SyncSubScreenLinkIndicator(void) {
    M2C_UNK CreateSubScreenLinkIndicator();
    M2C_UNK DeleteSubScreenLinkIndicator();
    M2C_UNK EnableMapConfirm();
    s32 GetLinkPhase();
    if (GetLinkPhase() == LINK_PHASE_READY) {
        EnableMapConfirm();
        CreateSubScreenLinkIndicator();
        return;
    }
    DisableMapConfirm();
    DeleteSubScreenLinkIndicator();
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

/* Link-mode match-name label: once the link has left the idle phase, create the
 * label sprite that shows the opponent's match name; while it is still idle,
 * only enable the map-confirm prompt.  The online variant's x/y are unused here. */
void CreateLinkMatchNameLabel(s32 unusedX, u16 unusedY, void *owner) {
    void *CreateSpriteForOwner(void *, void *);
    s32 GetLinkPhase(void);
    M2C_UNK EnableMapConfirm(void);
    extern M2C_UNK gLinkMatchNameLabelClass;

    if (GetLinkPhase() == LINK_PHASE_IDLE) {
        EnableMapConfirm();
        return;
    }
    CreateSpriteForOwner(&gLinkMatchNameLabelClass, owner);
}

