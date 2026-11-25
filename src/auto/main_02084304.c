/* 58 functions from 0x02084304 to 0x020852F4 (main), found by ds-decomp. */
#include "common.h"
#include "ov009_link.h"
#include "battle_map.h"
#include "ov000_ai.h"

typedef struct {u8 pad[0x1e];u8 value;u8 rest[0x6d];} PlayerEntry;
typedef struct {u8 pad[0x67a4];PlayerEntry entries[5];} PlayerTable;
extern void **gCurrentMap;
extern u16 gLinkAiCommandStage;
extern u8 gAiCommand[];
extern u8 gBattleCommand[];
extern u8 data_02156e5c[];

/* Dispatcher of the battle state's replay of another console's battle commands
 * (battle states 14 and 19, main_020D3464.c): idle waits for a command, busy
 * carries one out. */
void UpdateLinkAiCommand(void) {
    void BeginLinkAiCommand(void);
    void RunLinkAiCommand(void);

    switch (gLinkAiCommandStage) {                  /* irregular */
    case AI_COMMAND_STAGE_IDLE:
        BeginLinkAiCommand();
        return;
    case AI_COMMAND_STAGE_BUSY:
        RunLinkAiCommand();
        return;
    }
}

/* True when a battle command record holds a command kind the game knows
 * (AI_COMMAND_KIND 1..0x18). */
s32 IsAiCommandKindValid(u8 *command) {
    u8 kind;

    kind = M2C_FIELD(command, u8 *, AI_COMMAND_KIND);
    if ((kind == 0) || ((u32) kind >= (u32) AI_COMMAND_KIND_LIMIT)) {
        return 0;
    }
    return 1;
}

/* Stage 0 of the battle state's replay of commands broadcast by another console
 * (AI_COMMAND_STAGE_IDLE): take the next command meant for the current player
 * off its queue and start carrying it out.  A CPU player's commands arrive on
 * queue 0, a link player's on the queue of their control kind (3..6 -> 0..3). */
void BeginLinkAiCommand(void) {
    void UpdateLocalPlayerInput(void);
    s32 PopLinkCommand(u8, u8 *);
    s32 IsAiCommandKindValid(u8 *);
    void SetAiCommandPhase(s32);
    void func_ov000_0219c7d8(s32);
    u8 control;
    u8 queue;
    void **map;
    u8 *players;

    UpdateLocalPlayerInput();
    map = gCurrentMap;
    players = (u8 *)*map + MAP_PLAYER_STATES;
    players += M2C_FIELD(*map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE;
    control = M2C_FIELD(players, u8 *, PLAYER_REC_CTRL);
    if (control == PLAYER_CONTROL_CPU) {
        queue = 0;
    } else {
        queue = control - 3;
    }
    if (PopLinkCommand(queue, gAiCommand) != 1) {
        return;
    }
    if (IsAiCommandKindValid(gAiCommand) != 1) {
        return;
    }
    SetAiCommandPhase(AI_COMMAND_PHASE_ACT);
    func_ov000_0219c7d8(0); /* the new phase starts at its first step */
    gLinkAiCommandStage = AI_COMMAND_STAGE_BUSY;
}

/* Stage 1 of the battle state's replay (AI_COMMAND_STAGE_BUSY): step the command
 * popped by BeginLinkAiCommand while the map cursor is idle, and go back to
 * waiting for the next command once the AI picks its next action. */
void RunLinkAiCommand(void) {
    void UpdateLocalPlayerInput(void);
    u8 IsMapCursorIdle(void);
    s32 ProcessAiCommandStep(void);
    u8 GetAiCommandPhase(void);

    UpdateLocalPlayerInput();
    if (!IsMapCursorIdle()) {
        return;
    }
    ProcessAiCommandStep();
    if (GetAiCommandPhase() == AI_COMMAND_PHASE_PICK_ACTION) {
        gLinkAiCommandStage = AI_COMMAND_STAGE_IDLE;
    }
}

/* Let the local player keep working the map cursor and scrolling the view while
 * a link AI command is being replayed.  A CPU player takes no input, so its
 * turn only steps the command. */
void UpdateLocalPlayerInput(void) {
    void func_0207a7a4(s32, s32);
    void UpdateMapCursorInput(void);
    void *map;

    map = *gCurrentMap;
    if (M2C_FIELD((M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE) + map, u8 *, PLAYER_CONTROL_OFF) == PLAYER_CONTROL_CPU) {
        return;
    }
    UpdateMapCursorInput();
    func_0207a7a4(1, 4);
}

/* Pack a cursor path's twelve step bytes (MAP_CURSOR_PATH, one MOVE_DIR code per
 * byte) into the 6-byte command path gCommandPath, two 4-bit codes per byte.  The
 * inverse of UnpackCommandPath. */
void PackCommandPath(u8 *steps, u8 *packed) {
    s32 i = 0, j = 0;
    do {
        packed[i] = ((u32) (steps[j] << 28) >> 24) | (steps[j + 1] & 0xF);
        j += 2;
        i++;
    } while (i < 6);
}

/* Unpack the 6-byte compact command path (two 4-bit MOVE_DIR codes per byte, a
 * 0xF nibble for a missing step) into the map's 12-byte cursor path `dest`. */
void UnpackCommandPath(u8 *packed, u8 *dest) {
    s32 i = 0, j = 0, dir;
    do {
        dir = (packed[i] >> 4) & 0xF;
        if (dir == COMMAND_PATH_NONE) dest[j] = MOVE_DIR_NONE;
        else dest[j] = dir;
        dir = packed[i] & 0xF;
        if (dir == COMMAND_PATH_NONE) dest[j + 1] = MOVE_DIR_NONE;
        else dest[j + 1] = dir;
        i++;
        j += 2;
    } while (i < 6);
}

#pragma opt_common_subs off
void SendTurnEndPacket(void) {
void SendLinkCommand(void *, s32);
void **p; u8 *dst; u32 i;
u8 *packet=(u8 *)&gLinkAiCommandStage;
packet[4]=12;p=gCurrentMap;
packet[10]=M2C_FIELD(*p,u8 *,0x515a);
i=0;dst=gBattleCommand;
do{dst[12]=M2C_FIELD((u8 *)*p+i,u8 *,0x515c);i++;dst++;}while((s32)i<4);
SendLinkCommand(gBattleCommand,20);
}
#pragma opt_common_subs reset
void SendBattleCommandPacket(s32 a,s32 b,s32 c,s32 d){void SendLinkCommand(void *,s32);u8 *q=(u8 *)&gLinkAiCommandStage;void **p=gCurrentMap;u32 v; u32 x;q[4]=a;x=M2C_FIELD(*p,s16 *,0x52dc);v=M2C_FIELD(gAiCommand,s32 *,8);q[6]=x;q[7]=M2C_FIELD(*p,s16 *,0x52de);q[8]=M2C_FIELD(*p,s16 *,0x52d8);q[9]=M2C_FIELD(*p,s16 *,0x52da);q[5]=b;*(s32 *)(q+12)=v;q[10]=c;q[11]=d;q[22]=gAiCommand[18];PackCommandPath((u8 *)*p+0x5388,data_02156e5c);SendLinkCommand(gBattleCommand,20);}

/* Which network overlay is loaded, as the link-mode value its callers switch on:
 * NET_OVERLAY_LINK when the single-card link overlay's resource is loaded,
 * NET_OVERLAY_ONLINE when the online one is, else NET_OVERLAY_NONE. */
s32 GetLinkMode(void) {
    s32 IsResourceLoaded(M2C_UNK);

    if (IsResourceLoaded(NET_RESOURCE_LINK) != 0) {
        return NET_OVERLAY_LINK;
    }
    if (IsResourceLoaded(NET_RESOURCE_ONLINE) != 0) {
        return NET_OVERLAY_ONLINE;
    }
    return NET_OVERLAY_NONE;
}

/* Which network overlay is running, as the battle code asks for it: NET_OVERLAY_LINK
 * for the ov009 single-card (Download Play) link once its phase has come up,
 * NET_OVERLAY_ONLINE for the ov010 online (WFC) session once its flag is set, else
 * NET_OVERLAY_NONE.  Each counts only while its overlay resource is loaded. */
s32 GetActiveOverlay(void){s32 IsResourceLoaded(s32);s32 GetLinkPhase(void);s32 IsOnlineSessionFlagSet(s32);s32 linkUp;if(IsResourceLoaded(NET_RESOURCE_LINK)){if(GetLinkPhase())linkUp=1;else linkUp=0;if(linkUp)return NET_OVERLAY_LINK;}else if(IsResourceLoaded(NET_RESOURCE_ONLINE)&&IsOnlineSessionFlagSet(0))return NET_OVERLAY_ONLINE;return NET_OVERLAY_NONE;}

/* True when a network session is currently active: a single-card link once its
 * phase has come up, or an online (WFC) session once its flag is set. */
s32 IsLinkSessionActive(void) {
    s32 GetLinkPhase();
    s32 overlay;
    s32 active;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        if (GetLinkPhase() != 0) {
            active = 1;
        } else {
            active = 0;
        }
        return active;
    case NET_OVERLAY_ONLINE:
        return IsOnlineSessionFlagSet(0);
    default:
        return 0;
    }
}

/* Return the active network session's link status level, used to pick the link
 * signal sprite: the Download Play link's status value, or the online (WFC)
 * session's signal grade; 0 when no session is running. */
s32 GetLinkStatusLevel(void) {
    s32 func_ov009_02224158();
    s32 func_ov010_02228cc8();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        return func_ov009_02224158();
    case NET_OVERLAY_ONLINE:
        return func_ov010_02228cc8();
    default:
        return 0;
    }
}

/* True when the active network session has failed: a single-card link whose
 * phase is LINK_PHASE_ERROR or LINK_PHASE_ABORTED, or an online session with a
 * nonzero network error code. */
s32 IsSessionInError(void) {
    s32 GetNetErrorCode();
    s32 overlay;
    s32 result;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        if ((GetLinkPhase() == LINK_PHASE_ERROR) || (GetLinkPhase() == LINK_PHASE_ABORTED)) {
            return 1;
        }
        return 0;
    case NET_OVERLAY_ONLINE:
        if (GetNetErrorCode() != 0) {
            result = 1;
        } else {
            result = 0;
        }
        return result;
    default:
        return 0;
    }
}

/* True when the active network session's result has already been dealt with: the
 * link has marked its result flag, or the online session's error has been shown. */
s32 IsSessionResultHandled(void) {
    s32 IsLinkResultFlagSet(M2C_UNK);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return IsLinkResultFlagSet(1);
    case NET_OVERLAY_ONLINE:
        return IsOnlineSessionFlagSet(OV010_FLAG_ERROR);
    default:
        return 0;
    }
}

#pragma opt_common_subs off
s32 IsWfcLinkActive(void) {
    s32 WFC_GetConnectionData(u16 *);
    extern u16 gWfcConnectionData;
    s32 var_r0;

    if (WFC_GetConnectionData(&gWfcConnectionData) == 0) {
        if (gWfcConnectionData != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 0;
}
#pragma opt_common_subs reset
/* True when the player may soft reset: always outside a network overlay, and
 * inside one only while no WFC connection is up. */
s32 IsSoftResetAllowed(void) {
    s32 overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
    case NET_OVERLAY_ONLINE:
        return IsWfcLinkActive() == 0;
    default:
        return 1;
    }
}

void func_02084824(void) {
    M2C_UNK IsSoftResetAllowed();
    IsSoftResetAllowed();
}

/* True when the online (WFC) overlay is running and this console hosted the
 * match through matchmaking, rather than serving or joining one: the local
 * player's record's host state byte (ONLINE_PLAYER_SLOT_HOST) is zero. */
s32 IsOnlineMatchmakingHost(void){void *GetLocalPlayerStatus(void);if(GetActiveOverlay()==2 && M2C_FIELD(GetLocalPlayerStatus(),s8 *,ONLINE_PLAYER_SLOT_HOST)==0)return 1;return 0;}

/* True when the local console hosts the active network session: the Download Play
 * link host, or player 0 of the online (WFC) session; 0 when there is no session. */
s32 IsLocalSessionHost(void) {
    s32 IsLinkHost();
    s32 IsOnlineSessionHost();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        return IsLinkHost();
    case NET_OVERLAY_ONLINE:
        return IsOnlineSessionHost();
    default:
        return 0;
    }
}

/* True when the local console is a guest (not the host) of the active network
 * session: the Download Play link guest, or a non-zero player of the online (WFC)
 * session; 0 when there is no session. */
s32 IsLocalSessionGuest(void) {
    s32 IsLinkGuest();
    s32 IsOnlineGuest();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        return IsLinkGuest();
    case NET_OVERLAY_ONLINE:
        return IsOnlineGuest();
    default:
        return 0;
    }
}

/* This console's player index in the active network session: the single-card
 * link's local player index or the online (WFC) session's transport player id;
 * 0 when offline. */
s32 GetLocalPlayerIdForOverlay(void) {
    s32 GetLinkLocalPlayerId();
    s32 GetOnlineTransportPlayerId();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        return GetLinkLocalPlayerId();
    case NET_OVERLAY_ONLINE:
        return GetOnlineTransportPlayerId();
    default:
        return 0;
    }
}

/* Bit mask of the players connected to the active network session: the
 * single-card link's connected-player bits, or the online (WFC) session's peer
 * mask; 0 when there is no session. */
s32 GetSessionPlayerMask(void) {
    s32 GetConnectedPlayers();
    s32 GetOnlinePeerMask();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        return GetConnectedPlayers();
    case NET_OVERLAY_ONLINE:
        return GetOnlinePeerMask();
    default:
        return 0;
    }
}

/* This console's player slot in the active network session (0 when offline):
 * the single-card link's or the online session's own slot byte. */
s32 GetLocalPlayerSlot(void) {
    s32 GetLinkLocalPlayerSlot(void);
    s32 GetOnlineLocalPlayerSlot(void);

    switch (GetActiveOverlay()) {
    case NET_OVERLAY_LINK:
        return (s8)GetLinkLocalPlayerSlot();
    case NET_OVERLAY_ONLINE:
        return (s8)GetOnlineLocalPlayerSlot();
    default:
        return 0;
    }
}

/* Bit mask of the player ids of every connected player: from the link
 * overlay's player slots, or from the online session's player records. */
u16 GetActivePlayerMask(void) {
    s32 bit;
    u16 mask;
    u8 player;
    u8 onlinePlayer;
    void *linkPlayer;
    void *onlineRecord;

    bit = 0;
    mask = 0;
    switch (GetActiveOverlay()) {
    case 1:
        player = 0;
        bit = 1;
        do {
            linkPlayer = GetActiveLinkPlayerSlot(player);
            if (linkPlayer != NULL) {
                mask = (u16)(mask | ((u32) bit << M2C_FIELD(linkPlayer, s8 *, LINK_PLAYER_ID)));
            }
            player += 1;
        } while ((u32) player < 4U);
        break;
    case 2:
        onlinePlayer = 0;
        bit = 1;
        do {
            onlineRecord = GetOnlinePlayerRecord(onlinePlayer);
            if (onlineRecord != NULL) {
                mask = (u16)(mask | ((u32) bit << M2C_FIELD(onlineRecord, s8 *, ONLINE_PLAYER_ID)));
            }
            onlinePlayer += 1;
        } while ((u32) onlinePlayer < 4U);
        break;
    }
    return mask;
}

/* Number of players in the active network session: the single-card link's
 * connected-player bit count, or the online (WFC) session's player count; 0 when
 * offline. */
s32 GetSessionPlayerCount(void) {
    s32 GetLinkConnectedPlayerCount();
    s32 GetConnectedPlayerCount();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        return GetLinkConnectedPlayerCount();
    case NET_OVERLAY_ONLINE:
        return GetConnectedPlayerCount();
    default:
        return 0;
    }
}

/* Clear the per-player event bits the active network session has raised (a
 * player joining or leaving, for example) so each is only handled once. */
void ClearOverlayEventFlags(void) {
    M2C_UNK ClearLinkEventFlags();
    M2C_UNK ClearOnlineEventFlags();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        ClearLinkEventFlags();
        return;
    case NET_OVERLAY_ONLINE:
        ClearOnlineEventFlags();
        return;
    }
}

/* Per-player event bits raised by the active network session (bit n = the event
 * reported for player n+1, e.g. a player leaving); 0 when offline. */
s32 GetOverlayEventFlags(void) {
    s32 GetLinkEventFlags();
    s32 GetOnlineEventFlags();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        return GetLinkEventFlags();
    case NET_OVERLAY_ONLINE:
        return GetOnlineEventFlags();
    default:
        return 0;
    }
}

s32 IsOverlayEventSet(s32 a){s32 v,r;v=GetOverlayEventFlags();r=1;if(!(v&(1<<a)))r=0;return r;}

/* The player record of `player` in the active network session: the single-card
 * link's player slot, or the online session's player record, or NULL when no
 * session overlay is running. */
s32 GetActivePlayerRecord(s32 player) {
    s32 GetActiveLinkPlayerSlot(M2C_UNK);
    s32 GetOnlinePlayerRecord(M2C_UNK);
    s32 overlay;
    s32 record;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        record = GetActiveLinkPlayerSlot(player);
        if (record != 0) {
            return record;
        }
    case NET_OVERLAY_ONLINE:
        record = GetOnlinePlayerRecord(player);
        if (record != 0) {
            return record;
        }
    default:
        return 0;
    }
}

/* The rank of player `player` (the index used to load the player's rank icon),
 * read from the link overlay's player slot or, online, from the online player
 * record; -1 when the player is not found. */
s8 GetPlayerRank(M2C_UNK player) {
    s32 overlay;
    void *onlineRecord;
    void *linkPlayer;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case 1:
        linkPlayer = GetActiveLinkPlayerSlot(player);
        if (linkPlayer != NULL) {
            return M2C_FIELD(linkPlayer, s8 *, LINK_PLAYER_RANK);
        }
    case 2:
        onlineRecord = GetOnlinePlayerRecord(player);
        if (onlineRecord != NULL) {
            return M2C_FIELD(onlineRecord, s8 *, ONLINE_PLAYER_SLOT_RANK);
        }
    default:
        return -1;
    }
}

/* The favourite CO/group index of player `player`, read from the link overlay's
 * player slot or, online, from the online player record; -2 when the player is
 * not found. */
s8 GetPlayerFavouriteGroup(M2C_UNK player) {
    s32 overlay;
    void *onlineRecord;
    void *linkPlayer;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case 1:
        linkPlayer = GetActiveLinkPlayerSlot(player);
        if (linkPlayer != NULL) {
            return M2C_FIELD(linkPlayer, s8 *, LINK_PLAYER_FAV_GROUP);
        }
    case 2:
        onlineRecord = GetOnlinePlayerRecord(player);
        if (onlineRecord != NULL) {
            return M2C_FIELD(onlineRecord, s8 *, ONLINE_PLAYER_SLOT_FAV_GROUP);
        }
    default:
        return -2;
    }
}

/* The favourite CO/record index of player `player`, read from the link overlay's
 * player slot or, online, from the online player record; -2 when the player is
 * not found. */
s8 GetPlayerFavouriteRecord(M2C_UNK player) {
    s32 overlay;
    void *onlineRecord;
    void *linkPlayer;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case 1:
        linkPlayer = GetActiveLinkPlayerSlot(player);
        if (linkPlayer != NULL) {
            return M2C_FIELD(linkPlayer, s8 *, LINK_PLAYER_FAV_RECORD);
        }
    case 2:
        onlineRecord = GetOnlinePlayerRecord(player);
        if (onlineRecord != NULL) {
            return M2C_FIELD(onlineRecord, s8 *, ONLINE_PLAYER_SLOT_FAV_RECORD);
        }
    default:
        return -2;
    }
}

/* Send one link message to every player (recipient mask 0xFFFF): through the
 * single-card link overlay when it is active, or through the online overlay.
 * Arguments are the per-overlay queue helpers' message id, payload pointer and
 * payload size.  Returns the overlay's result, or 0 while neither session runs. */
s32 Link_BroadcastMessage(M2C_UNK message, M2C_UNK payload, M2C_UNK payloadSize) {
    s32 QueueHostLinkPacket(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 QueueOnlineLinkPacket(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return QueueHostLinkPacket(message, payload, payloadSize, 0xFFFF);
    case NET_OVERLAY_ONLINE:
        return QueueOnlineLinkPacket(message, payload, payloadSize, 0xFFFF);
    default:
        return 0;
    }
}

/* Send one link message to the players named by `recipients` (a bit per player
 * slot): through the single-card link overlay when it is active, or through the
 * online overlay.  Parameter meanings match the per-overlay queue helpers:
 * message id, payload pointer, payload size and recipient mask.  Returns the
 * overlay's result, or 0 while neither session is running. */
s32 Link_SendMessage(M2C_UNK message, M2C_UNK payload, M2C_UNK payloadSize, M2C_UNK recipients) {
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return QueueHostLinkPacket(message, payload, payloadSize, recipients);
    case NET_OVERLAY_ONLINE:
        return QueueOnlineLinkPacket(message, payload, payloadSize, recipients);
    default:
        return 0;
    }
}

/* Create the departure object of the network overlay currently running: the
 * single-card link's or the online session's sprite that tears the session down
 * when a match is left. */
void CreateSessionDepartureObject(M2C_UNK owner) {
    M2C_UNK CreateLinkDepartureObject(M2C_UNK);
    M2C_UNK CreateOnlineDepartureObject(M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        CreateLinkDepartureObject(owner);
        return;
    case NET_OVERLAY_ONLINE:
        CreateOnlineDepartureObject(owner);
        return;
    }
}

s32 GetOnlineLocalPlayerId(void){void *GetLocalPlayerStatus(void);s32 v=-1;if(GetActiveOverlay()==2)v=M2C_FIELD(GetLocalPlayerStatus(),s32 *,0x1c);return v;}

void SetOnlineLocalPlayerId(s32 arg0) {
    s32 GetActiveOverlay();
    void *GetLocalPlayerStatus();
    if (GetActiveOverlay() != 2) {
        return;
    }
    M2C_FIELD(GetLocalPlayerStatus(), s32 *, 0x1C) = arg0;
}

/* Copy the local player's record into `buffer`, which `length` bytes, through
 * whichever network overlay is running: the single-card link's copy or the
 * online session's, or 0 when neither session is up. */
s32 Link_ReceivePacket(M2C_UNK buffer, M2C_UNK length) {
    s32 CopyLinkLocalPlayerRecord(M2C_UNK, M2C_UNK);
    s32 CopyOnlineLocalPlayerRecord(M2C_UNK, M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return CopyLinkLocalPlayerRecord(buffer, length);
    case NET_OVERLAY_ONLINE:
        return CopyOnlineLocalPlayerRecord(buffer, length);
    default:
        return 0;
    }
}

/* Hand a buffer of `size` bytes (`src`) to the active network overlay, which
 * stages it as this console's local-player record to be sent to the others. */
void Link_SendPacket(M2C_UNK src, M2C_UNK size) {
    M2C_UNK StageLinkLocalPlayerRecord(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov010_02229a74(M2C_UNK, M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        StageLinkLocalPlayerRecord(src, size);
        return;
    case NET_OVERLAY_ONLINE:
        func_ov010_02229a74(src, size);
        return;
    }
}

/* Copy the active network session's player record into `buffer`, through the
 * running overlay's implementation (single-card link or online); returns `buffer`,
 * or 0 when neither session is up. */
s32 ReadActivePlayerRecord(M2C_UNK unused, M2C_UNK buffer, M2C_UNK length) {
    s32 CopyActiveLinkPlayerRecord(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 CopyActiveOnlinePlayerRecord(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return CopyActiveLinkPlayerRecord(unused, buffer, length);
    case NET_OVERLAY_ONLINE:
        return CopyActiveOnlinePlayerRecord(unused, buffer, length);
    default:
        return 0;
    }
}

/* The network record of the connected player `playerId` in the running network
 * session: the single-card link's record or the online session's, or 0 when
 * neither session is up. */
s32 GetNetworkPlayerRecord(M2C_UNK playerId) {
    s32 GetActiveLinkPlayerRecord(M2C_UNK);
    s32 GetActiveOnlinePlayerRecord(M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return GetActiveLinkPlayerRecord(playerId);
    case NET_OVERLAY_ONLINE:
        return GetActiveOnlinePlayerRecord(playerId);
    default:
        return 0;
    }
}

void GetLocalNetworkPlayerRecord(void) {
    M2C_UNK GetNetworkPlayerRecord(M2C_UNK);
    GetNetworkPlayerRecord(0);
}

/* Send what the active network session owes: in a single-card link announce
 * this player, in an online match publish the local player's status.  With no
 * session loaded there is nothing to send. */
void Link_FlushSend(void) {
    M2C_UNK AnnounceLinkPlayer();
    M2C_UNK PublishLocalPlayerStatus();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        AnnounceLinkPlayer();
        return;
    case NET_OVERLAY_ONLINE:
        PublishLocalPlayerStatus();
        return;
    }
}

/* Create the link match start-request node tagged with `matchId` and owned by
 * `owner`, dispatching to the active link overlay: local wireless (1) or online
 * Wi-Fi (2). */
s32 Link_CreateStartRequest(M2C_UNK matchId, M2C_UNK owner) {
    s32 CreateLinkStartRequest(M2C_UNK, M2C_UNK);
    s32 Ov010Online_CreateStartRequest(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return CreateLinkStartRequest(matchId, owner);
    case 2:
        return Ov010Online_CreateStartRequest(matchId, owner);
    default:
        return 0;
    }
}

/* Spawn the player-announce sprite under `owner` through whichever network
 * overlay is running (single-card link or online), or return 0 when neither is
 * up. */
s32 SpawnPlayerAnnounce(M2C_UNK owner) {
    s32 SpawnLinkPlayerAnnounce(M2C_UNK);
    s32 SpawnOnlinePlayerAnnounce(M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return SpawnLinkPlayerAnnounce(owner);
    case NET_OVERLAY_ONLINE:
        return SpawnOnlinePlayerAnnounce(owner);
    default:
        return 0;
    }
}

/* Create the match-request node that asks the active link overlay (local
 * wireless or Wi-Fi) to search for a game hosted with `nameCount` names, the
 * given game type and timeout, writing the search's flags and match count into
 * the caller's buffers. */
s32 Link_CreateMatchRequest(M2C_UNK names, M2C_UNK nameCount, M2C_UNK type, M2C_UNK timeout, s32 flags, s32 owner) {
    s32 CreateLocalMatchRequest(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 CreateOnlineMatchRequest(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case 1:
        return CreateLocalMatchRequest(names, nameCount, type, timeout, flags, owner);
    case 2:
        return CreateOnlineMatchRequest(names, nameCount, type, timeout, flags, owner);
    default:
        return 0;
    }
}

/* Install `handler` as the running network overlay's link message handler and
 * return the one it replaced (0 when neither overlay is up). */
s32 Link_SetMessageHandler(M2C_UNK handler) {
    s32 SetLinkMessageHandler(M2C_UNK);
    s32 SetOnlineMessageHandler(M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        return SetLinkMessageHandler(handler);
    case NET_OVERLAY_ONLINE:
        return SetOnlineMessageHandler(handler);
    default:
        return 0;
    }
}

/* Clear the link command queues, then create the local player's name label for
 * the active link provider: an ov009 label on a single-card link (link mode 1),
 * an ov010 label on a Nintendo WFC session (link mode 2). */
void CreateLocalPlayerNameLabel(M2C_UNK x, M2C_UNK y, M2C_UNK owner) {
    M2C_UNK ClearLinkCommandQueues();
    M2C_UNK CreateLinkNameLabel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK CreateOnlineNameLabel(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 linkMode;

    ClearLinkCommandQueues();
    linkMode = GetLinkMode();
    switch (linkMode) {
    case NET_OVERLAY_LINK:
        CreateLinkNameLabel(x, y, owner);
        return;
    case NET_OVERLAY_ONLINE:
        CreateOnlineNameLabel(x, y, owner);
        return;
    }
}

/* Create the name label shown for the local player during a match, through the
 * running overlay's implementation (the single-card link overlay's or the online
 * overlay's). */
void CreateMatchNameLabel(M2C_UNK x, M2C_UNK y, M2C_UNK owner) {
    M2C_UNK CreateLinkMatchNameLabel(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK CreateOnlineMatchNameLabel(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {
    case NET_OVERLAY_LINK:
        CreateLinkMatchNameLabel(x, y, owner);
        return;
    case NET_OVERLAY_ONLINE:
        CreateOnlineMatchNameLabel(x, y, owner);
        return;
    }
}

/* Spawn the player-announce refresher sprite under `owner` through whichever
 * network overlay is running (single-card link or online): the sprite's per-frame
 * update re-announces the local player when its published record changed. */
void SpawnPlayerAnnounceRefresher(M2C_UNK owner) {
    M2C_UNK SpawnLinkPlayerAnnounceRefresher(M2C_UNK);
    M2C_UNK SpawnOnlinePlayerAnnounceRefresher(M2C_UNK);
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        SpawnLinkPlayerAnnounceRefresher(owner);
        return;
    case NET_OVERLAY_ONLINE:
        SpawnOnlinePlayerAnnounceRefresher(owner);
        return;
    }
}

/* Delete the player-announce refresher sprites of whichever network overlay is
 * running: the single-card link's or the online session's. */
void Link_DeleteAnnounceRefreshers(void) {
    M2C_UNK DeleteLinkAnnounceRefreshers();
    M2C_UNK DeleteOnlineAnnounceRefreshers();
    s32 overlay;

    overlay = GetActiveOverlay();
    switch (overlay) {                              /* irregular */
    case NET_OVERLAY_LINK:
        DeleteLinkAnnounceRefreshers();
        return;
    case NET_OVERLAY_ONLINE:
        DeleteOnlineAnnounceRefreshers();
        return;
    }
}

void func_02085108(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x40) = 0;
    M2C_FIELD(arg0, s8 *, 0x41) = 0;
}

#pragma optimization_level 3
void func_02085118(void *p){
s32 func_ov002_021e1624(void);
void AppendSpriteDescToOam(s32,s32,s32,u16 *);
extern s32 gCur3DSpriteEngine;
extern s32 g3DSpriteEngineMain;
extern u8 gSpriteDesc16x16[];
typedef struct { u8 prefix[0x34]; s32 x, y; u16 tile, palette; u8 mainEngine; } SpriteState;
SpriteState *sprite = p;
s32 n; s32 saved;
if(!IsWfcLinkActive())return;
n=GetLinkStatusLevel();
if(sprite->mainEngine){
if(!func_ov002_021e1624())return;
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
{
 u16 *header = M2C_FIELD(gCur3DSpriteEngine,u16 **,0);
 s32 start = sprite->tile;
 u32 mode = *header;
 u32 palette = sprite->palette;
 s32 x = sprite->x;
 s32 y = sprite->y;
 s32 attr = ((palette << 28) >> 16) | (((n * 4 + start) >> ((mode << 17) >> 30)) & 1023);
 AppendSpriteDescToOam((u16)(x & 511), (u8)y, (u16)attr, (u16 *)gSpriteDesc16x16);
}
gCur3DSpriteEngine=saved;
}else{
{
 u16 *header = M2C_FIELD(gCur3DSpriteEngine,u16 **,0);
 s32 start = sprite->tile;
 u32 mode = *header;
 u32 palette = sprite->palette;
 s32 x = sprite->x;
 s32 y = sprite->y;
 s32 attr = ((palette << 28) >> 16) | (((n * 4 + start) >> ((mode << 17) >> 30)) & 1023);
 AppendSpriteDescToOam((u16)(x & 511), (u8)y, (u16)attr, (u16 *)gSpriteDesc16x16);
}
}
}
#pragma optimization_level reset
/* Create the link-status indicator sprite at (x, y) with the given tile and palette.
 * On a Download Play link (link mode 1) the tile is shifted by 0x10 to the variant the
 * sprite sheet uses there.  The link mode (or the shifted tile) is returned. */
s32 CreateLinkStatusSprite(s32 x, s32 y, s32 tile, s32 palette) {
    void *CreateSpriteFromClass(void *, s32);
    extern M2C_UNK gLinkStatusSpriteClass;
    s32 linkMode;
    void *sprite = CreateSpriteFromClass(&gLinkStatusSpriteClass, 7);
    M2C_FIELD(sprite, s32 *, 0x34) = x;
    M2C_FIELD(sprite, s32 *, 0x38) = y;
    M2C_FIELD(sprite, u16 *, 0x3c) = tile;
    M2C_FIELD(sprite, u16 *, 0x3e) = palette;
    linkMode = GetLinkMode();
    switch (linkMode) {
    case 1:
        linkMode = M2C_FIELD(sprite, u16 *, 0x3c) + 0x10;
        M2C_FIELD(sprite, u16 *, 0x3c) = linkMode;
        break;
    case 2:
    default:
        break;
    }
    return linkMode;
}

void CreateLinkStatusSpriteAt(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK CreateLinkStatusSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return (void)CreateLinkStatusSprite(arg0, arg1, 0, 0);
}

/* Put the small session-status indicator on the sub (top) screen: make the sub
 * 3D sprite engine current, spawn the indicator sprite at the top-right corner
 * and restore the engine that was current. */
void CreateSubScreenLinkIndicator(void) {
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    CreateLinkStatusSpriteAt(0xEF, 1);
    gCur3DSpriteEngine = savedEngine;
}

void func_020852e0(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gLinkStatusSpriteClass;
    DeleteSpriteObjectsOfClass(&gLinkStatusSpriteClass);
}

