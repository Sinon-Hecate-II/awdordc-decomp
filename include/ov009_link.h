/* The ov009 single-card (Download Play) link overlay.  A multiboot task reports
 * events to a callback; the callback drives the link state machine in gLinkState
 * and the per-player slots in gLinkPlayers. */
#ifndef OV009_LINK_H
#define OV009_LINK_H

#include "ds3dsprite.h"

/* Active network overlay, as GetActiveOverlay (main_02084304) reports it. */
#define NET_OVERLAY_NONE   0 /* no link or online session running */
#define NET_OVERLAY_LINK   1 /* ov009 single-card (Download Play) link */
#define NET_OVERLAY_ONLINE 2 /* ov010 online (Nintendo WFC) session */

/* Resource indices of the two network overlays in gResourceLoaded/gResourceFileIds. */
#define NET_RESOURCE_LINK   9  /* ov009 link overlay */
#define NET_RESOURCE_ONLINE 10 /* ov010 online overlay */

/* Event record passed to the registered link task callback. */
#define LINK_EVENT_STATE   0x02 /* u16 phase/status reported by the task */
#define LINK_EVENT_COMMAND 0x08 /* u16 command reported by the task */
#define LINK_EVENT_VALUE   0x0a /* u16 command argument */

/* Event record of a link completion task started with MultiBoot_StartLinkTask: like the
 * callback above it carries the status at +0x02, but its command word is at +0x04. */
typedef struct LinkCompletionEvent {
    u16 unk_00;
    u16 status;
    u16 command;
} LinkCompletionEvent;

#define LINK_TASK_EVENT_COMMAND 0x04 /* u16 command reported by a completion task */
#define LINK_TASK_CMD_DATA_DONE 10   /* the task's data step finished; the link is up */

/* gLinkState +0x00: u8 reference count of the users that have the link's event
 * notifications installed.  AddLinkEventListener bumps it and installs the
 * handler on the first user; RemoveLinkEventListener drops it and takes the
 * handler down with the last one. */
#define LINK_STATE_LISTENER_COUNT 0x00

/* gLinkState +0x0C: the result code most recently signalled, and +0x2C the
 * handler that is told about it (result code, 0). */
#define LINK_STATE_RESULT_CODE    0x0C /* s32 result code last signalled */
#define LINK_STATE_RESULT_HANDLER 0x2C /* void (*)(s32 result, s32 unused) */

/* gLinkState link-setup flags and the console's own player slot. */
#define LINK_STATE_FLAGS        0x156 /* u8: link setup flags */
#define LINK_STATE_FLAG_LINKED  0x01  /* the link is up: set when a task reports its data step */
#define LINK_STATE_LOCAL_PLAYER 0x157 /* u8: this console's player slot */

/* gLinkState +0x02: u16 slot of the player picked for the link match; a random
 * bit of LINK_STATE_PLAYER_MASK (PickLinkPlayerSlot picks and stores it). */
#define LINK_STATE_SELECTED_PLAYER 0x02

/* gLinkState +0x14 and +0x34: byte lengths of the two link transfer buffers. */
#define LINK_STATE_EXTRA_LEN    0x14 /* s32: bytes of gLinkTransferExtra */
#define LINK_STATE_TRANSFER_LEN 0x34 /* s32: bytes of gLinkTransferData */

/* The download-play data block SubmitLinkDownloadData hands to WFC. */
#define LINK_STATE_DOWNLOAD_DATA 0x100 /* void *: the payload block to send */
#define LINK_STATE_DOWNLOAD_CODE 0x108 /* s32: send code (transfer id) handed to WFC */
#define LINK_STATE_FLAG_DOWNLOAD 0x02  /* LINK_STATE_FLAGS bit: the block uses the download transfer */

/* Fields of gLinkDownloadHeader, the header block sent with that payload. */
#define LINK_DOWNLOAD_LENGTH   0x04 /* u16: bytes of the payload block */
#define LINK_DOWNLOAD_SEQUENCE 0x0C /* u16: sequence word sent with the block */

/* The Download Play connection request's extra-data block, gLinkConnectionExtraData
 * (32 bytes of .bss): its first LINK_CONNECTION_NAME_SIZE bytes hold the local
 * player's name, NUL-padded. */
#define LINK_CONNECTION_NAME_SIZE 0x18 /* bytes of name in the extra-data block */

/* General WFC event packet fields the link overlay's callback reads (the
 * WFC_CMD_GENERAL_EVENT packet, also handed to the per-channel callbacks). */
#define LINK_WFC_EVENT_RESULT 0x02 /* u16 result; LINK_WFC_RESULT_FATAL halts the game */
#define LINK_WFC_EVENT_KIND   0x04 /* u16 event kind */
#define LINK_WFC_RESULT_FATAL 8    /* unrecoverable link error */
#define LINK_WFC_KIND_HOST_READY 0x10 /* the Download Play host is serving: reset the retry count */

/* Phases of the link state machine (gLinkState +0x10). */
enum {
    LINK_PHASE_IDLE    = 0,
    LINK_PHASE_READY   = 1, /* a setup command finished; the next step may start */
    LINK_PHASE_REQUEST = 2, /* a link request arrived; its data is being prepared */
    LINK_PHASE_PENDING = 3, /* a WFC command is in flight; its completion advances the phase */
    LINK_PHASE_ACTIVE  = 4, /* link established; the menu treats 4/5 as in-game */
    LINK_PHASE_INGAME  = 5, /* second in-game phase; every check accepts 4 or 5 */
    LINK_PHASE_FOUND   = 6, /* the player announcement finished; the local player is picked next */
    LINK_PHASE_RESULT  = 7, /* showing the result/status screen */
    LINK_PHASE_ERROR   = 8,
    LINK_PHASE_ABORTED = 9
};

/* A peer asks the host (player slot 0) how many players are connected; the
 * host answers with the connected-player mask. */
#define LINK_MSG_CONNECT_REQUEST 5
#define LINK_MSG_CONNECT_REPLY   6

/* A console's announce of its own player record (LINK_PLAYER_ANNOUNCE_SIZE bytes,
 * the record kept in gLinkLocalPlayerInfo) and the reply that carries the
 * answering console's record. */
#define LINK_MSG_PLAYER_ANNOUNCE       11
#define LINK_MSG_PLAYER_ANNOUNCE_REPLY 12
#define LINK_PLAYER_ANNOUNCE_SIZE      0x60

/* Result code signalled when a link step completes. */
#define LINK_EVENT_COMPLETE 0x15

/* The link's packet sender object class, created with the live link actor and
 * freed with it: it splits a queued packet into channel transfers and keeps
 * track of which peers still have one outstanding. */
#define LINK_SENDER_OFFSET      0x34 /* s32 payload bytes already put into the transfer */
#define LINK_SENDER_PACKET      0x38 /* void *queued packet being split into transfers */
#define LINK_SENDER_TRANSFER    0x3C /* void *transfer packet (12-byte header) handed to WFC */
#define LINK_SENDER_LENGTH      0x40 /* s32 bytes of that transfer packet */
#define LINK_SENDER_PEERS       0x44 /* u16 bit per player slot the transfer is addressed to */
#define LINK_SENDER_OUTSTANDING 0x46 /* u16 bit per player slot whose transfer has not completed */

/* The link's packet receiver object class, created with the live link actor and
 * freed with it: at +0x34 it keeps one receive-assembly slot per link channel
 * (LINK_RECEIVER_*), filled from the incoming packet fragments and drained by the
 * object's class update (func_ov009_02221ae8). */
#define LINK_RECEIVER_CHANNELS 0x34 /* first of 4 per-channel slots */
#define LINK_RECEIVER_COUNT    4    /* receive-assembly slots (one per link channel) */
#define LINK_RECEIVER_STRIDE   0x08 /* bytes per channel slot */
#define LINK_RECEIVER_OFFSET   0x00 /* s32 bytes of the packet assembled so far */
#define LINK_RECEIVER_PACKET   0x04 /* void *packet being assembled, NULL when idle */

/* Fields of the send-completion record the WFC channel library hands the completion
 * callback registered through SendLinkChannelData. */
#define LINK_SEND_EVENT_RESULT  0x02 /* u16 WFC result of the transfer */
#define LINK_SEND_EVENT_CHANNEL 0x0A /* u16 channel the transfer ran on (4 or 12) */
#define LINK_SEND_EVENT_PEERS   0x0E /* u16 bit per player slot whose transfer is still outstanding */
#define LINK_SEND_EVENT_INDEX   0x10 /* u16 word handed to the packet handler with the packet */
#define LINK_SEND_EVENT_DATA    0x14 /* void *packet the completed transfer carried, 0 when none */
#define LINK_SEND_EVENT_LENGTH  0x18 /* u16 bytes of that packet */
#define LINK_SEND_EVENT_COMPLETION 0x20 /* void (*)(void *): the completion registered with the send (HandleLinkSendComplete) */
#define LINK_SEND_RESULT_DONE   0xF  /* done result that clears the outstanding mask on the end channel */
#define LINK_SEND_END_CHANNEL   4    /* the channel whose done result clears the outstanding mask */

/* Live link actor instance (gLinkActorClass). */
#define LINK_ACTOR_RETRY     0x34 /* s16 retry counter */
#define LINK_ACTOR_MAX_RETRY 5    /* give up after this many retries */

/* Link message that announces a player: the 12-byte player record, then a
 * 26-byte name area (UTF-16, NUL-padded) in a 40-byte packet. */
#define LINK_MSG_PLAYER_INFO    13
/* Link message 15: a peer's reply to a player-info announce; it carries the same
 * 12-byte record plus 26-byte name payload as LINK_MSG_PLAYER_INFO. */
#define LINK_MSG_PLAYER_INFO_REPLY 15
#define LINK_PLAYER_INFO_SIZE   40
#define LINK_PLAYER_RECORD_SIZE 12
#define LINK_PLAYER_NAME_OFFSET 12
#define LINK_PLAYER_NAME_SIZE   26

/* A gLinkPlayers slot: one per player slot, 0x60 bytes. */
#define LINK_PLAYER_SLOT_STRIDE 0x60 /* bytes between gLinkPlayers slots */
#define LINK_PLAYER_FLAGS  0x16 /* u8: bit 0 set while the slot holds a connected player */
#define LINK_PLAYER_CONNECTED 0x01 /* LINK_PLAYER_FLAGS bit: the slot's player is connected */
#define LINK_PLAYER_ID    0x17 /* s8: the player id the slot plays as, -1 when unset */
#define LINK_PLAYER_RANK       0x18 /* s8: rank index used to load the player's rank icon, -1 when unset */
#define LINK_PLAYER_FAV_GROUP  0x19 /* s8: favourite CO/group index, -2 when unset */
#define LINK_PLAYER_FAV_RECORD 0x1A /* s8: favourite CO record index, -2 when unset */
#define LINK_PLAYER_SLOT_RECORD 0x20 /* start of a slot's trailing 0x40-byte player record */

/* The link's per-peer connection-data slots (gLinkPeerSlots): four 0xC8-byte slots,
 * each holding the 0xC0-byte block a peer sent, a validity timer and an in-use
 * flag.  A slot carries a usable unit record once its block holds enough transfer
 * data and the record type word says it is a unit. */
#define LINK_PEER_SLOT_COUNT   4
#define LINK_PEER_SLOT_STRIDE  0xC8
#define LINK_PEER_DATA_LENGTH  0x3C /* u16 in the block: bytes of transfer data, 0 when empty */
#define LINK_PEER_DATA_TYPE    0x40 /* u16 in the block: LINK_PEER_TYPE_UNIT for a unit record */
#define LINK_PEER_SLOT_TIMER   0xC0 /* s16: frames left before the slot is released */
#define LINK_PEER_SLOT_IN_USE  0xC4 /* s32: nonzero while the slot holds a peer */
#define LINK_PEER_MIN_DATA     0x10 /* fewest bytes of transfer data a unit record needs */
#define LINK_PEER_TYPE_UNIT    1    /* LINK_PEER_DATA_TYPE of a unit record */

/* gLinkState +0x28: u16 * mask of the player announcement in flight; the actor
 * stores its own bit there until every connected peer has answered. */
#define LINK_STATE_ANNOUNCE 0x28
/* gLinkState +0x04: u16 bit (player slot - 1) of every player the announcement
 * found, and +0x0A the value those answers report: an answer that reports a lower
 * value than the stored one starts the mask over, an equal one adds its bit. */
#define LINK_STATE_PLAYER_MASK  0x04
#define LINK_STATE_ANNOUNCE_KEY 0x0A

/* gLinkState +0x48: record of the match being started (see LINK_START_RECORD_*),
 * an 8-byte packet the host sends to the peers. */
#define LINK_STATE_START_RECORD 0x48
#define LINK_START_RECORD_ID    0x00 /* s32: match id both sides compare */
#define LINK_START_RECORD_ACKS  0x04 /* u16: one bit per player that acknowledged the start */

/* Link message ids whose 8-byte payload is the start record. */
#define LINK_MSG_START_REQUEST 2 /* the host asks the peers to start the match */
#define LINK_MSG_START_ACK     3 /* a peer acknowledges a start request */

/* Return code of the announcer when no further player slot is left to ask. */
#define LINK_ANNOUNCE_DONE 0x19

/* A link request record a state-machine step hands out and later polls: the
 * sender sets sent once the request has been queued and the replies build up one
 * bit per player slot in players.  gLinkState +0x20 holds the player
 * announcement's record while it is in flight, +0x24 the connected-players
 * request's. */
typedef struct LinkRequestRecord {
    u8 sent;     /* +0x00 nonzero once the request was queued */
    u8 pad01;
    u16 players; /* +0x02 bit per player slot the request is about */
} LinkRequestRecord;

#define LINK_STATE_ANNOUNCE_REQUEST 0x20 /* LinkRequestRecord *: player announcement in flight */
#define LINK_STATE_CONNECT_REQUEST  0x24 /* LinkRequestRecord *: connected-players request */
#define LINK_REQUEST_SENT    0x00 /* u8: nonzero once the request was queued */
#define LINK_REQUEST_PLAYERS 0x02 /* u16: bit per player slot the request found */
/* WFC commands whose task returned 2 are queued and still running. */
#define LINK_TASK_QUEUED 2
/* gLinkState +0x50: s32 bit per player slot whose link result has been handled. */
#define LINK_STATE_RESULT_FLAGS 0x50
 /* gLinkState +0x3C: handler the overlay's general WFC events are forwarded to. */
 #define LINK_STATE_EVENT_HANDLER 0x3C
 /* gLinkState +0x60: handler the overlay hands a link packet to; set through a
  * setter that returns the previous handler and called with the packet and two
  * words describing it (its length and the addressed player mask). */
 #define LINK_STATE_PACKET_HANDLER 0x60

/* gLinkState +0x64: head of the overlay's pending-send queue.  Packets are linked
 * through +0x00, the tail is at +0x68 and the count at +0x6C; a queued packet
 * names its channel at +0x08, and +0x0C is its payload length, after the 16-byte
 * header. */
#define LINK_STATE_SEND_QUEUE 0x64
#define LINK_STATE_SEND_TAIL  0x68
#define LINK_STATE_SEND_COUNT 0x6C
/* Offsets inside a send-queue object (a pointer to its head is what the queue
 * helpers take): the head and tail link packets through LINK_SEND_NEXT. */
#define LINK_SEND_QUEUE_HEAD  0x00 /* void *first queued packet */
#define LINK_SEND_QUEUE_TAIL  0x04 /* void *last queued packet */
#define LINK_SEND_QUEUE_COUNT 0x08 /* s32 packets queued */
#define LINK_SEND_NEXT    0x00 /* void *next packet in the queue */
#define LINK_SEND_CHANNEL 0x08 /* u8 channel the packet is sent on */
#define LINK_SEND_LENGTH  0x0C /* u32 payload length in bytes */

/* The 12-byte link packet header WriteLinkPacketHeader writes (at +4 of a queued
 * packet node; its payload follows at +0x0C). */
#define LINK_PACKET_MAGIC      0x00 /* u32: tag LINK_PACKET_TAG */
#define LINK_PACKET_TAG        0x5F574C4D /* s32 "MLW_": marks a link packet */
#define LINK_PACKET_TYPE       0x04 /* u8: message id (LINK_MSG_*) */
#define LINK_PACKET_FLAGS      0x05 /* u8: two 4-bit flags; low nibble, then high nibble */
#define LINK_PACKET_RECIPIENTS 0x06 /* u16: bit per player slot the packet is addressed to */
#define LINK_PACKET_LENGTH     0x08 /* u32: payload byte count */
#define LINK_PACKET_PAYLOAD    0x0C /* payload bytes copied in behind the header */

/* The link overlay's status-text layer (generic text-layer fields at 0x34..0x36
 * are in ds3dsprite.h): it shows a localized message while the link result is
 * on screen. */
#define LINK_LAYER_TEXT_KEY 0x38 /* s32 localized-text key shown by the layer */
#define LINK_LAYER_STYLE    0x3C /* s32 style word handed to the text renderer */
#define LINK_LAYER_STATUS   0x40 /* s32 link status/result code; 0 hides the layer */
#define LINK_STATUS_TEXT       0x4400000A /* localized text key of the link status message */
#define LINK_STATUS_TEXT_CODE8 0x4400000B /* localized text key shown instead when the status code is 8 */

/* The ov009 object whose status labels CreateLinkStatusLabels creates (its generic
 * text-layer fields at 0x34..0x36 are in ds3dsprite.h): it keeps the link status
 * code its status label reports, 0 while there is nothing to show. */
#define LINK_LABEL_HOST_STATUS 0x38 /* s32: link status code of the label host */

/* The link-result sprite (gLinkResultSpriteClass): it waits for the link to fail
 * and then reports the outcome to the callback it was created with. */
#define LINK_RESULT_CALLBACK 0x34 /* void (*)(s32 result, void *owner): told the link's outcome */

#endif
