/* 46 functions from 0x020852F4 to 0x02086208 (main), found by ds-decomp. */
#include "common.h"

/* The link-status indicator sprite CreateLinkStatusSprite makes: it is drawn
 * either on the main 3D sprite engine or on whichever engine is current. */
typedef struct {
    u8  pad[0x34];
    s32 x;          /* +0x34 screen x */
    s32 y;          /* +0x38 screen y */
    u16 tile;       /* +0x3C tile index in the link-status sheet */
    u16 palette;    /* +0x3E palette row */
    u8  mainEngine; /* +0x40 nonzero: draw on the main engine */
    u8  unk41;      /* +0x41 cleared with mainEngine */
} LinkStatusSprite;

/* The link player-data listener objects of this file: each one is registered as
 * the link layer's message handler, remembers the handler that was installed
 * before it and forwards every message it does not handle on to it, and collects
 * each player's data block (one session data block per player) as it arrives. */
#define LINK_PLAYER_DATA_PREV_HANDLER 0x34 /* s32 (*)(u32, void *): previous message handler */
#define LINK_PLAYER_DATA_PTRS         0x38 /* void **: one data block per player */
#define LINK_PLAYER_OWN_DATA          0x3C /* void *: the block sent for this player */
#define LINK_PLAYER_DATA_SIZE         0x40 /* s32: bytes in one player's block */
#define LINK_PLAYER_DATA_RECEIVED     0x44 /* u16: bit of each player whose block has arrived */

/* Link messages it handles: one player's data block, then the acknowledgement
 * that the block arrived. */
#define LINK_MSG_PLAYER_DATA     0x86
#define LINK_MSG_PLAYER_DATA_ACK 0x87

/* A whole data block carried by one link message (payload at message +0xC). */
#define LINK_MSG_BLOCK           0x85
#define LINK_BLOCK_RECEIVED      0x38 /* u8: set once the block has been copied */
#define LINK_BLOCK_SENDER_DATA   0x34 /* void *: the whole block the sender broadcasts */
#define LINK_BLOCK_SENDER_SIZE   0x38 /* s32: bytes in the block */

static inline u16 StatusX(void *p) { return M2C_FIELD(p,s16 *,0x34)&511; }
static inline u8 StatusY(void *p) { return M2C_FIELD(p,s16 *,0x36); }
static inline u16 StatusTile(u16 state) {
 extern u16 **gCur3DSpriteEngine;
 return 1023&((s32)(state*4+32)>>((u32)(**gCur3DSpriteEngine<<17)>>30));
}
static inline u8 IsSpriteReady(void *p) { return M2C_FIELD(p,s16 *,0x4e)==0; }
static inline void DrawStatusIcon(s16 x,s16 y,u16 state) {
 extern u16 **gCur3DSpriteEngine; extern M2C_UNK gSpriteDesc16x16;
 void AppendSpriteDescToOam(s32, s32, s32, u16 *);
 AppendSpriteDescToOam((u16)(x&511),(u8)y,(u16)(1023&((s32)(state*4+32)>>((u32)(**gCur3DSpriteEngine<<17)>>30))),(u16 *)&gSpriteDesc16x16);
}

/* A small value interpolator (see UpdateSpriteAnimation/GetSpriteAnimValue). */
typedef struct SpriteAnim {
    u8  mode;       /* +0x00 interpolation curve */
    u8  done;       /* +0x01 nonzero: stop advancing */
    u16 current;    /* +0x02 frames elapsed */
    u16 start;      /* +0x04 value current is reset to */
    u16 step;       /* +0x06 frames added per update */
    s16 base;       /* +0x08 */
    s16 amplitude;  /* +0x0A */
    s16 duration;   /* +0x0C frames of the fade */
    s16 from;       /* +0x0E start value */
    s16 to;         /* +0x10 end value */
} SpriteAnim;

/* Push-to-talk voice-chat widget. */
typedef struct VoiceChatWidget {
    u8  filler_00[0x34];
    s16 x;               /* +0x34 */
    s16 y;               /* +0x36 */
    s32 enabled;         /* +0x38 nonzero while the widget is shown */
    s32 initialized;     /* +0x3C set on the first update */
    s32 lastVoice;       /* +0x40 last voice-data-ready value seen */
    u8  filler_44[4];
    s32 talkHeld;        /* +0x48 Y button was held last update */
    u8  filler_4c[2];
    s16 refreshTimer;    /* +0x4E cooldown before the fade may be re-targeted */
    SpriteAnim *anim;    /* +0x50 volume fade */
} VoiceChatWidget;

/* Show the link-status indicator sprite on the main screen: switch it to the main
 * engine, clear its sub-screen flag and load the scene-panel graphics it draws
 * with. */
void ShowLinkStatusSpriteOnMainScreen(void) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK LoadScenePanelGraphicsOnBothEngines(void *);
    extern M2C_UNK gLinkStatusSpriteClass;
    LinkStatusSprite *sprite;

    sprite = FindObjectByClass(&gLinkStatusSpriteClass);
    if (!sprite) return;
    sprite->mainEngine = 1;
    sprite->unk41 = 0;
    LoadScenePanelGraphicsOnBothEngines(sprite);
}

/* Hide the link-status indicator sprite: clear its main-engine flag and the
 * companion byte ShowLinkStatusSpriteOnMainScreen keeps in step with it. */
void HideLinkStatusSprite(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gLinkStatusSpriteClass;
    LinkStatusSprite *sprite;

    sprite = FindObjectByClass(&gLinkStatusSpriteClass);
    if (sprite != NULL) {
        sprite->mainEngine = 0;
        sprite->unk41 = 0;
    }
}

/* Broadcast a link command packet of `size` bytes from `command`: the message
 * type carries the local player's slot (LINK_MSG_COMMAND_BASE + slot), which the
 * receiver turns back into the command source's queue index. */
void SendLinkCommand(void *command, s32 size) {
    s32 GetLocalPlayerSlot();
    Link_BroadcastMessage((u8)(GetLocalPlayerSlot() + LINK_MSG_COMMAND_BASE), command, size);
}

/* Pop the oldest message of one link command queue into buf.  Returns 1 when a
 * message was copied, 0 when the queue was empty. */
u8 PopLinkCommand(s32 queue, void *buf) {
    s32 PopLinkQueueEntry(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK gLinkCommandQueues;
    u8 popped;

    if (PopLinkQueueEntry((LINK_COMMAND_QUEUE_STRIDE * queue) + (s32) &gLinkCommandQueues, (M2C_UNK) buf, 0) != 0) {
        popped = 1;
    } else {
        popped = 0;
    }
    return popped;
}

/* Queue an incoming command using the source encoded in its message type. */
s32 Link_HandleCommandMessage(s32 sender, void *messageData) {
    s32 MI_CpuCopy8();
    s32 QueueReceivedLinkCommand(u8, void *, s32);
    LinkReceivedMessage *message = messageData;
    u8 command[32];

    switch (message->type - LINK_MSG_COMMAND_BASE) {
    case 0:
    case 1:
    case 2:
    case LINK_COMMAND_QUEUE_COUNT - 1:
        command[0] = message->type;
        command[1] = 1;
        MI_CpuCopy8(message->payload, command + 2, message->payloadSize);
        QueueReceivedLinkCommand((u8)(command[0] - LINK_MSG_COMMAND_BASE), command, message->payloadSize + 2);
        break;
    }
    return 1;
}

void Link_InstallCommandHandler(void) {
    M2C_UNK Link_SetMessageHandler(M2C_UNK *);
    s32 Link_HandleCommandMessage(M2C_UNK, void *);
    Link_SetMessageHandler((M2C_UNK *)&Link_HandleCommandMessage);
}

void func_02085428(M2C_UNK arg0) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    Link_CreateStartRequest(0x50544453, arg0);
}

/* First update of a link data-block sender: broadcast its stored block to the
 * other players and go back to the sprite's regular animation. */
void BroadcastLinkBlock(void *sender) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    Link_BroadcastMessage(LINK_MSG_BLOCK, M2C_FIELD(sender, s32 *, LINK_BLOCK_SENDER_DATA), M2C_FIELD(sender, s32 *, LINK_BLOCK_SENDER_SIZE));
    Sprite_ResumeAnimation(sender);
}

void func_02085464(M2C_UNK arg0) {
    Link_CreateStartRequest(0x50524453, arg0);
}

/* Create the link task that sends one whole data block to the other players: it
 * remembers the block (`blockData`, `blockSize`) and broadcasts it as a
 * LINK_MSG_BLOCK message on its first update. */
void CreateLinkBlockSender(s32 blockData, s32 blockSize, M2C_UNK owner) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gLinkBlockSenderClass, gLinkBlockSenderVtbl;
    void *sender;

    sender = CreateSpriteForOwner(&gLinkBlockSenderClass, owner);
    if (sender == NULL) {
        return;
    }
    M2C_FIELD(sender, M2C_UNK **, 0) = &gLinkBlockSenderVtbl;
    M2C_FIELD(sender, s32 *, LINK_BLOCK_SENDER_DATA) = blockData;
    M2C_FIELD(sender, s32 *, LINK_BLOCK_SENDER_SIZE) = blockSize;
}

void func_020854b8(M2C_UNK arg0) {
    Link_CreateStartRequest(0x50544453, arg0);
}

/* Resume the data-block receiver's (waiting) animation once its block has
 * arrived, or straight away when the network session reports a problem. */
void ResumeBlockReceiverAnimation(void *receiver) {
    s32 IsSessionInError();
    s32 GetOverlayEventFlags();
    if ((IsSessionInError() != 0) || (GetOverlayEventFlags() != 0)) {
        Sprite_ResumeAnimation(receiver);
        return;
    }
    if (M2C_FIELD(receiver, u8 *, LINK_BLOCK_RECEIVED) == 0) {
        return;
    }
    Sprite_ResumeAnimation(receiver);
}

void func_02085514(M2C_UNK arg0) {
    Link_CreateStartRequest(0x50524453, arg0);
}

/* Handles the link messages that carry a whole data block: a LINK_MSG_BLOCK
 * message copies its payload (message + 0xC) into the receiver object's block
 * buffer and marks the block as received; anything else goes to the handler
 * installed before this one.  Returns 1 unless a forwarded handler says
 * otherwise. */
s32 Link_HandleBlockMessage(u32 sender, void *message) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK MI_CpuCopy8();
    extern M2C_UNK gLinkBlockReceiverClass;
    s32 (*forward)(u32, void *);
    s32 result;
    void *receiver;

    receiver = FindObjectByClass(&gLinkBlockReceiverClass);
    result = 1;
    if (receiver != NULL) {
        if (M2C_FIELD(message, u8 *, 4) == LINK_MSG_BLOCK) {
            MI_CpuCopy8((u8 *)message + 0xC, M2C_FIELD(receiver, void **, LINK_PLAYER_OWN_DATA), M2C_FIELD(receiver, s32 *, LINK_PLAYER_DATA_SIZE));
            M2C_FIELD(receiver, u8 *, LINK_BLOCK_RECEIVED) = 1;
        } else {
            forward = M2C_FIELD(receiver, s32 (**)(u32, void *), LINK_PLAYER_DATA_PREV_HANDLER);
            if (forward != NULL) result = forward(sender, message);
        }
    }
    return result;
}

/* Create the link listener that transfers one whole data block: take over the
 * link layer's message handler (remembering the previous one), point at the block
 * buffer and its size, and clear the block-received flag. */
void CreateLinkBlockReceiver(s32 blockData, s32 blockSize, s32 owner) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gLinkBlockReceiverClass, gLinkBlockReceiverVtbl;
    void *receiver;

    receiver = CreateSpriteForOwner(&gLinkBlockReceiverClass, owner);
    if (!receiver) return;
    M2C_FIELD(receiver, void **, 0) = &gLinkBlockReceiverVtbl;
    M2C_FIELD(receiver, s32 *, LINK_PLAYER_DATA_PREV_HANDLER) = Link_SetMessageHandler((M2C_UNK *)&Link_HandleBlockMessage);
    M2C_FIELD(receiver, u8 *, LINK_BLOCK_RECEIVED) = 0;
    M2C_FIELD(receiver, s32 *, LINK_PLAYER_OWN_DATA) = blockData;
    M2C_FIELD(receiver, s32 *, LINK_PLAYER_DATA_SIZE) = blockSize;
}

void func_020855f0(M2C_UNK arg0) {
    Link_CreateStartRequest(0x50544353, arg0);
}

/* True while a connected player's data block has not arrived yet; false once every
 * ready player's block is in, or once the session reports an error. */
u8 IsPlayerDataIncomplete(void *listener) {
    s32 GetSessionPlayerMask(void);
    s32 IsSessionInError(void);
    s32 readyMask, receivedMask;
    s32 incomplete;

    readyMask = GetSessionPlayerMask();
    receivedMask = GetSessionPlayerMask();
    incomplete = readyMask != (M2C_FIELD(listener, u16 *, LINK_PLAYER_DATA_RECEIVED) & receivedMask);
    if (IsSessionInError()) incomplete = 0;
    return (u8)incomplete;
}

void func_02085644(void *arg0) {
    M2C_UNK Link_BroadcastMessage(M2C_UNK, s32, s32);
    Link_BroadcastMessage(0x86, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
}

void func_0208565c(M2C_UNK arg0) {
    Link_CreateStartRequest(0x50524353, arg0);
}

/* Handles the link messages that carry the players' data blocks: a
 * LINK_MSG_PLAYER_DATA message copies its payload (message + 0xC) into the
 * buffer of the player its header names (message + 5, low nibble) and answers
 * with LINK_MSG_PLAYER_DATA_ACK for that player; a LINK_MSG_PLAYER_DATA_ACK
 * marks the block as arrived.  Anything else goes to the handler installed
 * before this one.  Returns 1 unless a forwarded handler says otherwise. */
s32 Link_HandlePlayerDataMessage(u32 arg0, void *message) {
    void *FindObjectByClass(M2C_UNK *);
    void Link_SendMessage(s32, s32, s32, u16);
    extern M2C_UNK gLinkPlayerDataClass;
    void *listener;
    s32 result;
    s32 (*forward)(u32, void *);

    listener = FindObjectByClass(&gLinkPlayerDataClass);
    result = 1;
    if (listener) {
        arg0 = (u32)(M2C_FIELD(message, u8 *, 5) << 28) >> 28;
        switch (M2C_FIELD(message, u8 *, 4)) {
        case LINK_MSG_PLAYER_DATA:
            MI_CpuCopy8((u8 *)message + 12,
                        M2C_FIELD(M2C_FIELD(listener, void **, LINK_PLAYER_DATA_PTRS), void **, arg0 * 4),
                        M2C_FIELD(listener, s32 *, LINK_PLAYER_DATA_SIZE));
            Link_SendMessage(LINK_MSG_PLAYER_DATA_ACK, 0, 0, (u16)(result << arg0));
            break;
        case LINK_MSG_PLAYER_DATA_ACK:
            M2C_FIELD(listener, u16 *, LINK_PLAYER_DATA_RECEIVED) |= result << arg0;
            break;
        default:
            forward = M2C_FIELD(listener, s32 (**)(u32, void *), LINK_PLAYER_DATA_PREV_HANDLER);
            if (forward) result = forward(arg0, message);
            break;
        }
    }
    return result;
}

/* Creates the link listener that gathers the players' data blocks: it takes over
 * the link layer's message handler (remembering the previous one), keeps the
 * per-player block pointers, this player's own block and the size of one block,
 * and marks this player's block as already received. */
void CreateLinkPlayerDataListener(void **playerDataPtrs, void *ownData, s32 dataSize, void *owner) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    s32 GetLocalPlayerIdForOverlay(void);
    extern M2C_UNK gLinkPlayerDataClass, gLinkPlayerDataVtbl;
    void *p = CreateSpriteForOwner(&gLinkPlayerDataClass, owner);
    if (!p) return;
    M2C_FIELD(p, void **, 0) = &gLinkPlayerDataVtbl;
    M2C_FIELD(p, s32 *, LINK_PLAYER_DATA_PREV_HANDLER) = Link_SetMessageHandler((M2C_UNK *)&Link_HandlePlayerDataMessage);
    M2C_FIELD(p, void **, LINK_PLAYER_DATA_PTRS) = playerDataPtrs;
    M2C_FIELD(p, void **, LINK_PLAYER_OWN_DATA) = ownData;
    M2C_FIELD(p, s32 *, LINK_PLAYER_DATA_SIZE) = dataSize;
    M2C_FIELD(p, u16 *, LINK_PLAYER_DATA_RECEIVED) = 1 << GetLocalPlayerIdForOverlay();
}

#pragma push
#pragma opt_propagation off
#pragma opt_strength_reduction off
void func_02085788(s32 arg0) {
    M2C_UNK MemSet(M2C_UNK *, u8, s32);
    s32 GetActiveOverlay();
    s32 GetPlayerArmyId(s32);
    M2C_UNK CreateLocalProfileSaveSprite(s32);
    M2C_UNK CreateLocalBattleSaveSprite(s32);
    void *GetBattleSlotRecord();
    s32 FindBattleSaveSlotByProfileId(s32);
    M2C_UNK ConvergeSyncedPositions(M2C_UNK, s32 *, s32 *);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    s8 GetOnlineTransportPlayerId();
    s32 GetOnlinePeerMask();
    void *GetLocalPlayerStatus();
    void *GetOnlinePlayerRecord(u8);
    extern s32 data_021020b8;
    extern M2C_UNK data_02157634;
    extern M2C_UNK data_02157638;
    s32 sp8;
    s32 sp4;
    volatile s32 sp0;
    s32 temp_r0_5;
    s32 temp_r10;
    s32 temp_r4;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 var_r2;
    s32 var_r2_2;
    s8 temp_r0_2;
    s8 temp_r8;
    u8 var_r7;
    u8 var_r9;
    u8 *out;
    void *temp_r0;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_6;
    void *temp_r5;

    sp0 = arg0;
    M2C_FIELD(&data_02157634, s8 *, 0) = 0;
    if (GetActiveOverlay() != 2) {
        return;
    }
    temp_r0 = GetLocalPlayerStatus();
    if (M2C_FIELD(temp_r0, s8 *, 0x28) != 0) {
        return;
    }
    if (IsOnlineSessionFlagSet(3) == 0) {
        return;
    }
    temp_r10 = GetOnlinePeerMask();
    M2C_FIELD(&data_02157634, s8 *, 1) = GetOnlineTransportPlayerId();
    temp_r0_2 = M2C_FIELD(temp_r0, s8 *, 0x27);
    switch (temp_r0_2) {                            /* irregular */
    case 0:
        temp_r5 = GetProfileSaveBlock();
        var_r7 = 0;
loop_10:
        if ((var_r7 != GetOnlineTransportPlayerId()) && (temp_r10 & (1 << var_r7)) && (temp_r0_3 = GetOnlinePlayerRecord(var_r7), (temp_r0_3 != NULL))) {
            M2C_FIELD(&data_02157634, u8 *, 4) = var_r7;
            temp_r6 = M2C_FIELD(temp_r0, s32 *, 0x20);
            sp8 = temp_r6;
            temp_r4 = M2C_FIELD(temp_r0_3, s32 *, 0x20);
            sp4 = temp_r4;
            M2C_FIELD(&data_02157634, s32 *, 8) = temp_r6;
            M2C_FIELD(&data_02157634, s32 *, 0xC) = temp_r4;
            ConvergeSyncedPositions(1, &sp8, &sp4);
            var_r2 = sp8;
            if (var_r2 > 0x01388000) {
                var_r2 = 0x01388000;
            } else if (var_r2 < -0x01388000) {
                var_r2 = -0x01388000;
            }
            M2C_FIELD(temp_r5, s32 *, 0x50) = (s32) M2C_FIELD(temp_r5, s32 *, 0x54);
            M2C_FIELD(temp_r5, s32 *, 0x54) = var_r2;
            M2C_FIELD(temp_r5, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r5, s32 *, 0x44) + 1);
            M2C_FIELD(&data_02157634, s8 *, 0) = 1;
        } else {
            var_r7 += 1;
            if ((u32) var_r7 >= 4U) {

            } else {
                goto loop_10;
            }
        }
        break;
    case 1:
        var_r2_2 = 8;
        var_r2_2 -= 4;
        if (var_r2_2 < 0) {
            var_r2_2 = 0;
        }
        MemSet(&data_02157638, (u8) (s8) data_021020b8, var_r2_2);
        out=(u8 *)&data_02157634;
        temp_r8 = GetOnlineTransportPlayerId();
        var_r9 = 0;
        do {
            if ((var_r9 != GetOnlineTransportPlayerId()) && (temp_r10 & (1 << var_r9))) {
                temp_r6_2 = GetPlayerArmyId(temp_r8 + 1);
                if (temp_r6_2 != GetPlayerArmyId(var_r9 + 1)) {
                    temp_r0_4 = GetOnlinePlayerRecord(var_r9);
                    if (temp_r0_4 != NULL) {
                        temp_r0_5 = FindBattleSaveSlotByProfileId(M2C_FIELD(temp_r0_4, s32 *, 0x1C));
                        if (temp_r0_5 >= 0) {
                            M2C_FIELD((out + var_r9), s8 *, 4) = (s8) temp_r0_5;
                            temp_r0_6 = GetBattleSlotRecord();
                            M2C_FIELD(temp_r0_6, u16 *, 0x1A) = (u16) (M2C_FIELD(temp_r0_6, u16 *, 0x1A) + 1);
                            M2C_FIELD(&data_02157634, s8 *, 0) = 1;
                        }
                    }
                }
            }
            var_r9 += 1;
        } while ((u32) var_r9 < 4U);
        break;
    }
    CreateLocalProfileSaveSprite(sp0);
    CreateLocalBattleSaveSprite(sp0);
}
#pragma push
#pragma opt_scheduling off
void func_020859b4(M2C_UNK arg0) {
    s32 GetActiveOverlay();
    M2C_UNK CreateLocalProfileSaveSprite(M2C_UNK);
    M2C_UNK CreateLocalBattleSaveSprite(M2C_UNK);
    void *GetBattleSlotRecord();
    M2C_UNK ConvergeSyncedPositions(M2C_UNK, s32 *, s32 *);
    u32 GetPlayerResultAgainst(s32, s32);
    void *GetLocalPlayerStatus();
    extern M2C_UNK data_02157634;
    s32 coords[2];
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    s8 temp_r1;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u8 temp_r7;
    u8 var_r8;
    void *temp_r0;
    void *temp_r5;
    void *temp_r6;
    u8 *values;

    if (GetActiveOverlay() != 2) {
        return;
    }
    temp_r0 = GetLocalPlayerStatus();
    if (M2C_FIELD(temp_r0, s8 *, 0x28) != 0) {
        return;
    }
    if (M2C_FIELD(&data_02157634, u8 *, 0) == 0) {
        return;
    }
    temp_r1 = M2C_FIELD(temp_r0, s8 *, 0x27);
    switch (temp_r1) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_r6 = GetProfileSaveBlock();
        values=(u8 *)&data_02157634;
        coords[0]=M2C_FIELD(values,s32 *,12);coords[1]=M2C_FIELD(values,s32 *,8);
        temp_r0_2 = GetPlayerResultAgainst(values[1] + 1, values[4] + 1);
        switch (temp_r0_2) {                        /* switch 2 */
        case 2:                                     /* switch 2 */
            break;
        default:                                    /* switch 2 */
            break;
        case 0:                                     /* switch 2 */
            var_r2 = coords[1];
            if (var_r2 > 0x01388000) {
                var_r2 = 0x01388000;
            } else if (var_r2 < -0x01388000) {
                var_r2 = -0x01388000;
            }
            M2C_FIELD(temp_r6, s32 *, 0x50) = (s32) M2C_FIELD(temp_r6, s32 *, 0x54);
            M2C_FIELD(temp_r6, s32 *, 0x54) = var_r2;
            M2C_FIELD(temp_r6, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x44) - 1);
            M2C_FIELD(temp_r0, s32 *, 0x20) = coords[1];
            break;
        case 1:                                     /* switch 2 */
            ConvergeSyncedPositions(0, &coords[1], &coords[0]);
            var_r2_2 = coords[1];
            if (var_r2_2 > 0x01388000) {
                var_r2_2 = 0x01388000;
            } else if (var_r2_2 < -0x01388000) {
                var_r2_2 = -0x01388000;
            }
            M2C_FIELD(temp_r6, s32 *, 0x50) = (s32) M2C_FIELD(temp_r6, s32 *, 0x54);
            M2C_FIELD(temp_r6, s32 *, 0x54) = var_r2_2;
            M2C_FIELD(temp_r6, s32 *, 0x48) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x48) + 1);
            M2C_FIELD(temp_r0, s32 *, 0x20) = coords[1];
            break;
        case 3:                                     /* switch 2 */
            ConvergeSyncedPositions(2, &coords[1], &coords[0]);
            var_r2_3 = coords[1];
            if (var_r2_3 > 0x01388000) {
                var_r2_3 = 0x01388000;
            } else if (var_r2_3 < -0x01388000) {
                var_r2_3 = -0x01388000;
            }
            M2C_FIELD(temp_r6, s32 *, 0x50) = (s32) M2C_FIELD(temp_r6, s32 *, 0x54);
            M2C_FIELD(temp_r6, s32 *, 0x54) = var_r2_3;
            M2C_FIELD(temp_r6, s32 *, 0x4C) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x4C) + 1);
            M2C_FIELD(temp_r0, s32 *, 0x20) = coords[1];
            break;
        }
        break;
    case 1:                                         /* switch 1 */
        temp_r7 = M2C_FIELD(&data_02157634, u8 *, 1);
        var_r8 = 0;
        do {
            if ((s32) M2C_FIELD(((u8 *)&data_02157634 + var_r8), s8 *, 4) >= 0) {
                temp_r5 = GetBattleSlotRecord();
                temp_r0_3 = GetPlayerResultAgainst(temp_r7 + 1, var_r8 + 1);
                switch (temp_r0_3) {                /* switch 3 */
                case 2:                             /* switch 3 */
                    break;
                default:                            /* switch 3 */
                    break;
                case 0:                             /* switch 3 */
                    M2C_FIELD(temp_r5, u16 *, 0x1A) = (u16) (M2C_FIELD(temp_r5, u16 *, 0x1A) - 1);
                    break;
                case 1:                             /* switch 3 */
                    M2C_FIELD(temp_r5, u16 *, 0x1C) = (u16) (M2C_FIELD(temp_r5, u16 *, 0x1C) + 1);
                    break;
                case 3:                             /* switch 3 */
                    M2C_FIELD(temp_r5, u16 *, 0x1E) = (u16) (M2C_FIELD(temp_r5, u16 *, 0x1E) + 1);
                    break;
                }
            }
            var_r8 += 1;
        } while ((u32) var_r8 < 4U);
        break;
    }
    M2C_FIELD(&data_02157634, u8 *, 0) = 0U;
    CreateLocalProfileSaveSprite(arg0);
    CreateLocalBattleSaveSprite(arg0);
}
#pragma pop
void SaveProfileSyncTime(void) {
    M2C_UNK GetServerDateTime(s32);
    GetServerDateTime(GetProfileSaveBlock() + 0x58);
}

s32 GetProfileSyncTime(void) {
    s32 GetProfileSaveBlock();
    return GetProfileSaveBlock() + 0x58;
}

void StoreGetRequestServerTime(void) {
    GetServerDateTime(GetProfileSaveBlock() + 0x74);
}

s32 GetGetRequestServerTime(void) {
    return GetProfileSaveBlock() + 0x74;
}

/* Empty every link command queue (one FIFO of incoming commands per command
 * source). */
void ClearLinkCommandQueues(void) {
    void ClearLinkCommandQueue(void *);
    extern M2C_UNK gLinkCommandQueues;
    s32 i;
    u8 *queue;

    queue = (u8 *)&gLinkCommandQueues;
    i = 0;
    do {
        ClearLinkCommandQueue(queue);
        ++i;
        queue += LINK_COMMAND_QUEUE_STRIDE;
    } while (i < LINK_COMMAND_QUEUE_COUNT);
}

/* Queue a received command message on the queue of its source, skipping the
 * message's type/flag header so only its payload is copied. */
s32 QueueReceivedLinkCommand(u8 source, void *message, s32 messageSize) {
    s32 AppendLinkCommand(void *, s32, u16, s16);
    extern M2C_UNK gLinkCommandQueues;
    AppendLinkCommand((u8 *)&gLinkCommandQueues + LINK_COMMAND_QUEUE_STRIDE * source, (s32)((u8 *)message + LINK_COMMAND_HEADER_SIZE), (u16)(messageSize - LINK_COMMAND_HEADER_SIZE), 0);
}

void func_02085ca8(void) {

}

/* Deleting destructor of the link player-data listener: restore the link layer's
 * previous message handler and free the listener.  (LinkPlayerData_Destroy is the
 * non-freeing twin.) */
void *LinkPlayerData_Delete(void *listener) {
    M2C_UNK MemFree(void *);
    extern M2C_UNK gLinkPlayerDataVtbl;
    M2C_FIELD(listener, M2C_UNK **, 0) = &gLinkPlayerDataVtbl;
    Link_SetMessageHandler(M2C_FIELD(listener, s32 *, LINK_PLAYER_DATA_PREV_HANDLER));
    MemFree(listener);
    return listener;
}

/* Non-freeing destructor of the link player-data listener: put the base vtable
 * back and restore the link layer's previous message handler, then hand the
 * listener back.  (LinkPlayerData_Delete is the deleting twin.) */
void *LinkPlayerData_Destroy(void *listener) {
    extern M2C_UNK gLinkPlayerDataVtbl;
    M2C_FIELD(listener, M2C_UNK **, 0) = &gLinkPlayerDataVtbl;
    Link_SetMessageHandler(M2C_FIELD(listener, s32 *, LINK_PLAYER_DATA_PREV_HANDLER));
    return listener;
}

/* Deleting destructor of the link block receiver: restore the base vtable,
 * uninstall its link message handler (putting back the one it replaced) and free
 * the receiver.  (LinkBlockReceiver_Destroy is the non-deleting twin.) */
void *LinkBlockReceiver_Delete(void *receiver) {
    M2C_UNK MemFree(void *);
    extern M2C_UNK gLinkBlockReceiverVtbl;

    M2C_FIELD(receiver, M2C_UNK **, 0) = &gLinkBlockReceiverVtbl;
    Link_SetMessageHandler(M2C_FIELD(receiver, s32 *, 0x34));
    MemFree(receiver);
    return receiver;
}

/* Non-freeing destructor of the link block receiver: put the base vtable back,
 * uninstall its link message handler (putting back the one it replaced) and hand
 * the receiver back.  (LinkBlockReceiver_Delete is the deleting twin.) */
void *LinkBlockReceiver_Destroy(void *receiver) {
    extern M2C_UNK gLinkBlockReceiverVtbl;

    M2C_FIELD(receiver, M2C_UNK **, 0) = &gLinkBlockReceiverVtbl;
    Link_SetMessageHandler(M2C_FIELD(receiver, s32 *, LINK_PLAYER_DATA_PREV_HANDLER));
    return receiver;
}

s32 func_02085d4c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_02085d60(void) {

}

s32 func_02085d64(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_02085d78(void) {

}

void func_02085d7c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

/* Append a copy of a command's data (with its extra s16) as a new entry on a
 * link command queue's tail; returns 0 when the entry could not be allocated. */
s32 AppendLinkCommand(void *queue, M2C_UNK data, u16 size, s16 unk22) {
    M2C_UNK MI_CpuCopy8();
    void *HeapAllocBlock(M2C_UNK);
    LinkCommandEntry *entry;
    LinkCommandEntry *tail;

    entry = HeapAllocBlock(sizeof(LinkCommandEntry));
    if (entry == NULL) {
        return 0;
    }
    MI_CpuCopy8(data, entry, size);
    entry->payloadSize = size;
    entry->unk_22 = unk22;
    entry->next = NULL;
    tail = ((LinkCommandQueue *) queue)->tail;
    if (tail == NULL) {
        ((LinkCommandQueue *) queue)->tail = entry;
        ((LinkCommandQueue *) queue)->head = entry;
    } else {
        tail->next = entry;
        ((LinkCommandQueue *) queue)->tail = entry;
    }
    return 1;
}

/* Remove the queue head, copy its payload to the caller, optionally return its extra value, and free the entry. */
s32 PopLinkQueueEntry(s32 queue, s32 destination, s32 extraValue) {
    void HeapFreeBlock(void *);
    s32 entryLength;
    void *entry;

    entry = M2C_FIELD(queue, void **, 0);
    if (entry == NULL) return 0;
    entryLength = M2C_FIELD(entry, u16 *, 0x20);
    if (extraValue) M2C_FIELD(extraValue, u16 *, 0) = M2C_FIELD(entry, u16 *, 0x22);
    MI_CpuCopy8(entry, destination, entryLength);
    M2C_FIELD(queue, void **, 0) = M2C_FIELD(entry, void **, 0x24);
    if (M2C_FIELD(queue, void **, 0) == NULL) M2C_FIELD(queue, s32 *, 4) = 0;
    HeapFreeBlock(entry);
    return entryLength;
}

/* Empty one link command queue: free every queued entry and reset its head and
 * tail to empty. */
void ClearLinkCommandQueue(void *queue) {
    void HeapFreeBlock(void *);
    LinkCommandQueue *q = queue;
    LinkCommandEntry *entry;

    while ((entry = q->head) != NULL) {
        q->head = entry->next;
        HeapFreeBlock(entry);
    }
    q->tail = NULL;
    q->head = NULL;
}

void func_02085e8c(void *arg0) {
    M2C_UNK Ov010_InitVoiceChat();
    if (M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        return;
    }
    Ov010_InitVoiceChat();
}

void func_02085ea4(void *arg0) {
    M2C_UNK Ov010_ShutdownVoiceChat();
    if (M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        return;
    }
    Ov010_ShutdownVoiceChat();
}

#pragma optimization_level 3
void func_02085ebc(void *arg0) {
 s32 IsWfcLinkActive(); s32 func_ov002_021e1624(); s32 func_ov010_02225d8c(); s32 func_ov010_02225d9c();
 extern M2C_UNK gSpriteDesc16x16; extern u16 **g3DSpriteEngineMain; extern u16 **gCur3DSpriteEngine;
 s32 flag; u16 **saved; u16 v; u16 state=3;
 if(IsWfcLinkActive() && M2C_FIELD(arg0,s32 *,0x38) && M2C_FIELD(arg0,s32 *,0x3c)){
 if(IsSpriteReady(arg0)){
 if(func_ov010_02225d8c()){
 v=func_ov010_02225d9c()?2:1; state=v;
 }else state=0;
 }}
 if(M2C_FIELD(arg0,u8 *,0x4c)){
 if(!func_ov002_021e1624())return;
 saved=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
 {
 DrawStatusIcon(M2C_FIELD(arg0,s16 *,0x34), M2C_FIELD(arg0,s16 *,0x36), state);
 }
 gCur3DSpriteEngine=saved; return;
 }
 {
 DrawStatusIcon(M2C_FIELD(arg0,s16 *,0x34), M2C_FIELD(arg0,s16 *,0x36), state);
 }
}
#pragma optimization_level reset
/* Push-to-talk voice chat: while Y is held the voice stream runs; incoming voice
 * ducks the game's channel-2 volume to 0x20, and it fades back to 0x7F when the
 * voice stops.  This updates the button state and drives the widget's fade. */
void UpdateVoiceChatWidget(VoiceChatWidget *obj) {
    M2C_UNK SetMusicVolumeLevel(M2C_UNK, s32);
    M2C_UNK SetSoundEffectVolumeLevel(M2C_UNK, s32);
    s16 func_02090698(M2C_UNK);
    M2C_UNK UpdateSpriteAnimation(void *);
    s32 GetSpriteAnimValue(void *);
    s32 IsVoiceDataReady();
    M2C_UNK EnableVoiceStream();
    M2C_UNK DisableVoiceStream();
    M2C_UNK TickVoiceStream();
    extern void *gKeyState;
    s16 timer;
    u8 ready;
    SpriteAnim *anim;
    s16 volume;

    if (obj->enabled == 0) {
        return;
    }
    if (obj->initialized == 0) {
        obj->initialized = 1;
    }
    timer = obj->refreshTimer;
    if ((s32) timer > 0) {
        obj->refreshTimer = (s16) (timer - 1);
    }
    if (obj->refreshTimer == 0) {
        ready = 1;
    } else {
        ready = 0;
    }
    TickVoiceStream();
    if (IsVoiceDataReady() != 0) {
        if (obj->talkHeld == 0 && obj->lastVoice != IsVoiceDataReady()) {
            volume = func_02090698(2); anim = obj->anim; anim->from = volume;
            anim->to = 0x20;
            anim->duration = 8;
            anim->current = (u16) anim->start;
            obj->lastVoice = IsVoiceDataReady();
        }
    } else if (obj->talkHeld == 0 && obj->lastVoice != IsVoiceDataReady()) {
        volume = func_02090698(2); anim = obj->anim; anim->from = volume;
        anim->to = 0x7F;
        anim->duration = 8;
        anim->current = (u16) anim->start;
        obj->lastVoice = IsVoiceDataReady();
    }
    if (ready && obj->talkHeld == 0 && (((KeyState *)gKeyState)->held & KEY_Y)) {
        if (obj->lastVoice == 0) {
            volume = func_02090698(2); anim = obj->anim; anim->from = volume;
            anim->to = 0x20;
            anim->duration = 8;
            anim->current = (u16) anim->start;
        }
        EnableVoiceStream();
        obj->talkHeld = 1;
    } else if (obj->talkHeld != 0 && !(((KeyState *)gKeyState)->held & KEY_Y)) {
        if (obj->lastVoice == 0) {
            volume = func_02090698(2); anim = obj->anim; anim->from = volume;
            anim->to = 0x7F;
            anim->duration = 8;
            anim->current = (u16) anim->start;
        }
        DisableVoiceStream();
        obj->talkHeld = 0;
    }
    UpdateSpriteAnimation(obj->anim);
    SetMusicVolumeLevel(2, GetSpriteAnimValue(obj->anim));
    SetSoundEffectVolumeLevel(2, GetSpriteAnimValue(obj->anim));
}

