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
    u8 func_ov000_0219c7b0(void);

    UpdateLocalPlayerInput();
    if (!IsMapCursorIdle()) {
        return;
    }
    ProcessAiCommandStep();
    if (func_ov000_0219c7b0() == AI_COMMAND_PHASE_PICK_ACTION) {
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

void UnpackCursorPath(u8 *a,u8 *b){s32 i=0,j=0;do{b[i]=((u32)(a[j]<<28)>>24)|(a[j+1]&15);j+=2;i++;}while(i<6);}

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
void func_020844f8(void) {
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
void SendBattleCommandPacket(s32 a,s32 b,s32 c,s32 d){void SendLinkCommand(void *,s32);u8 *q=(u8 *)&gLinkAiCommandStage;void **p=gCurrentMap;u32 v; u32 x;q[4]=a;x=M2C_FIELD(*p,s16 *,0x52dc);v=M2C_FIELD(gAiCommand,s32 *,8);q[6]=x;q[7]=M2C_FIELD(*p,s16 *,0x52de);q[8]=M2C_FIELD(*p,s16 *,0x52d8);q[9]=M2C_FIELD(*p,s16 *,0x52da);q[5]=b;*(s32 *)(q+12)=v;q[10]=c;q[11]=d;q[22]=gAiCommand[18];UnpackCursorPath((u8 *)*p+0x5388,data_02156e5c);SendLinkCommand(gBattleCommand,20);}

s32 GetLinkMode(void) {
    s32 IsResourceLoaded(M2C_UNK);
    if (IsResourceLoaded(9) != 0) {
        return 1;
    }
    if (IsResourceLoaded(0xA) != 0) {
        return 2;
    }
    return 0;
}

/* Which network overlay is running, as the battle code asks for it: NET_OVERLAY_LINK
 * for the ov009 single-card (Download Play) link once its phase has come up,
 * NET_OVERLAY_ONLINE for the ov010 online (WFC) session once its flag is set, else
 * NET_OVERLAY_NONE.  Each counts only while its overlay resource is loaded. */
s32 GetActiveOverlay(void){s32 IsResourceLoaded(s32);s32 GetLinkPhase(void);s32 IsOnlineSessionFlagSet(s32);s32 linkUp;if(IsResourceLoaded(NET_RESOURCE_LINK)){if(GetLinkPhase())linkUp=1;else linkUp=0;if(linkUp)return NET_OVERLAY_LINK;}else if(IsResourceLoaded(NET_RESOURCE_ONLINE)&&IsOnlineSessionFlagSet(0))return NET_OVERLAY_ONLINE;return NET_OVERLAY_NONE;}

s32 IsLinkSessionActive(void) {
    s32 GetLinkPhase();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        if (GetLinkPhase() != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    case 2:
        return IsOnlineSessionFlagSet(0);
    default:
        return 0;
    }
}

s32 func_020846e8(void) {
    s32 func_ov009_02224158();
    s32 func_ov010_02228cc8();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224158();
    case 2:
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

s32 func_0208477c(void) {
    s32 IsLinkResultFlagSet(M2C_UNK);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return IsLinkResultFlagSet(1);
    case 2:
        return IsOnlineSessionFlagSet(6);
    default:
        return 0;
    }
}

#pragma opt_common_subs off
s32 func_020847b8(void) {
    s32 func_02011af8(u16 *);
    extern u16 data_02156e64;
    s32 var_r0;

    if (func_02011af8(&data_02156e64) == 0) {
        if (data_02156e64 != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 0;
}
#pragma opt_common_subs reset
s32 IsSoftResetAllowed(void){s32 a=GetActiveOverlay();switch(a){case 1:case 2:return func_020847b8()==0;default:return 1;}}

void func_02084824(void) {
    M2C_UNK IsSoftResetAllowed();
    IsSoftResetAllowed();
}

s32 func_02084830(void){void *GetLocalPlayerStatus(void);if(GetActiveOverlay()==2 && M2C_FIELD(GetLocalPlayerStatus(),s8 *,0x27)==0)return 1;return 0;}

s32 IsLocalSessionHost(void) {
    s32 IsLinkHost();
    s32 IsOnlineSessionHost();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return IsLinkHost();
    case 2:
        return IsOnlineSessionHost();
    default:
        return 0;
    }
}

s32 func_02084890(void) {
    s32 func_ov009_022254d8();
    s32 func_ov010_02229bf4();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022254d8();
    case 2:
        return func_ov010_02229bf4();
    default:
        return 0;
    }
}

s32 GetLocalPlayerIdForOverlay(void) {
    s32 GetLinkLocalPlayerId();
    s32 GetOnlineTransportPlayerId();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return GetLinkLocalPlayerId();
    case 2:
        return GetOnlineTransportPlayerId();
    default:
        return 0;
    }
}

s32 GetReadyPlayerMask(void) {
    s32 GetConnectedPlayers();
    s32 GetOnlinePeerMask();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return GetConnectedPlayers();
    case 2:
        return GetOnlinePeerMask();
    default:
        return 0;
    }
}

s32 GetLocalPlayerSlot(void){s32 func_ov009_02225460(void);s32 func_ov010_02229a14(void);switch(GetActiveOverlay()){case 1:return (s8)func_ov009_02225460();case 2:return (s8)func_ov010_02229a14();default:return 0;}}

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

s32 GetSessionPlayerCount(void) {
    s32 func_ov009_02225470();
    s32 GetConnectedPlayerCount();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02225470();
    case 2:
        return GetConnectedPlayerCount();
    default:
        return 0;
    }
}

void ResetPlayerMask(void) {
    M2C_UNK ClearLinkEventFlags();
    M2C_UNK func_ov010_02229a50();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        ClearLinkEventFlags();
        return;
    case 2:
        func_ov010_02229a50();
        return;
    }
}

s32 GetOverlayEventFlags(void) {
    s32 GetLinkEventFlags();
    s32 func_ov010_02229a64();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return GetLinkEventFlags();
    case 2:
        return func_ov010_02229a64();
    default:
        return 0;
    }
}

s32 IsOverlayEventSet(s32 a){s32 v,r;v=GetOverlayEventFlags();r=1;if(!(v&(1<<a)))r=0;return r;}

s32 func_02084ac0(M2C_UNK arg0) {
    s32 GetActiveLinkPlayerSlot(M2C_UNK);
    s32 GetOnlinePlayerRecord(M2C_UNK);
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    temp_r0_3 = GetActiveOverlay();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = GetActiveLinkPlayerSlot(arg0);
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
    case 2:
        temp_r0 = GetOnlinePlayerRecord(arg0);
        if (temp_r0 != 0) {
            return temp_r0;
        }
    default:
        return 0;
    }
}

s8 func_02084b08(M2C_UNK arg0) {
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0_3 = GetActiveOverlay();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = GetActiveLinkPlayerSlot(arg0);
        if (temp_r0_2 != NULL) {
            return M2C_FIELD(temp_r0_2, s8 *, 0x18);
        }
    case 2:
        temp_r0 = GetOnlinePlayerRecord(arg0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, s8 *, 0x24);
        }
    default:
        return -1;
    }
}

s8 func_02084b58(M2C_UNK arg0) {
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0_3 = GetActiveOverlay();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = GetActiveLinkPlayerSlot(arg0);
        if (temp_r0_2 != NULL) {
            return M2C_FIELD(temp_r0_2, s8 *, 0x19);
        }
    case 2:
        temp_r0 = GetOnlinePlayerRecord(arg0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, s8 *, 0x25);
        }
    default:
        return -2;
    }
}

s8 func_02084ba8(M2C_UNK arg0) {
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0_3 = GetActiveOverlay();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = GetActiveLinkPlayerSlot(arg0);
        if (temp_r0_2 != NULL) {
            return M2C_FIELD(temp_r0_2, s8 *, 0x1A);
        }
    case 2:
        temp_r0 = GetOnlinePlayerRecord(arg0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, s8 *, 0x26);
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

void func_02084cc0(M2C_UNK arg0) {
    M2C_UNK func_ov009_02225348(M2C_UNK);
    M2C_UNK func_ov010_02228c88(M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02225348(arg0);
        return;
    case 2:
        func_ov010_02228c88(arg0);
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

s32 Link_ReceivePacket(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_ov009_022240c0(M2C_UNK, M2C_UNK);
    s32 func_ov010_02229b5c(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022240c0(arg0, arg1);
    case 2:
        return func_ov010_02229b5c(arg0, arg1);
    default:
        return 0;
    }
}

void Link_SendPacket(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_ov009_02223f7c(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov010_02229a74(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02223f7c(arg0, arg1);
        return;
    case 2:
        func_ov010_02229a74(arg0, arg1);
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

s32 GetNetworkPlayerRecord(M2C_UNK arg0) {
    s32 func_ov009_022240f4(M2C_UNK);
    s32 func_ov010_02229b90(M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022240f4(arg0);
    case 2:
        return func_ov010_02229b90(arg0);
    default:
        return 0;
    }
}

void GetLocalNetworkPlayerRecord(void) {
    M2C_UNK GetNetworkPlayerRecord(M2C_UNK);
    GetNetworkPlayerRecord(0);
}

void Link_FlushSend(void) {
    M2C_UNK AnnounceLinkPlayer();
    M2C_UNK PublishLocalPlayerStatus();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        AnnounceLinkPlayer();
        return;
    case 2:
        PublishLocalPlayerStatus();
        return;
    }
}

s32 func_02084ea0(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_ov009_02225654(M2C_UNK, M2C_UNK);
    s32 func_ov010_02229d54(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02225654(arg0, arg1);
    case 2:
        return func_ov010_02229d54(arg0, arg1);
    default:
        return 0;
    }
}

s32 func_02084eec(M2C_UNK arg0) {
    s32 SpawnLinkPlayerAnnounce(M2C_UNK);
    s32 func_ov010_02229eb4(M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return SpawnLinkPlayerAnnounce(arg0);
    case 2:
        return func_ov010_02229eb4(arg0);
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

s32 Link_SetMessageHandler(M2C_UNK arg0) {
    s32 func_ov009_02224c1c(M2C_UNK);
    s32 func_ov010_022294c8(M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224c1c(arg0);
    case 2:
        return func_ov010_022294c8(arg0);
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

void func_02085054(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_ov009_022261e4(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK CreateOnlineMatchNameLabel(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_022261e4(arg0, arg1, arg2);
        return;
    case 2:
        CreateOnlineMatchNameLabel(arg0, arg1, arg2);
        return;
    }
}

void func_020850a4(M2C_UNK arg0) {
    M2C_UNK func_ov009_02226268(M2C_UNK);
    M2C_UNK func_ov010_0222bb64(M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02226268(arg0);
        return;
    case 2:
        func_ov010_0222bb64(arg0);
        return;
    }
}

void func_020850dc(void) {
    M2C_UNK func_ov009_02226290();
    M2C_UNK func_ov010_0222bb8c();
    s32 temp_r0;

    temp_r0 = GetActiveOverlay();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02226290();
        return;
    case 2:
        func_ov010_0222bb8c();
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
if(!func_020847b8())return;
n=func_020846e8();
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

void func_02085294(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK CreateLinkStatusSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return (void)CreateLinkStatusSprite(arg0, arg1, 0, 0);
}

void CreateSubScreenLinkIndicator(void) {
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_02085294(0xEF, 1);
    gCur3DSpriteEngine = temp_r4;
}

void func_020852e0(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gLinkStatusSpriteClass;
    DeleteSpriteObjectsOfClass(&gLinkStatusSpriteClass);
}

