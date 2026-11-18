/* The ov009 single-card (Download Play) link overlay.  A multiboot task reports
 * events to a callback; the callback drives the link state machine in gLinkState
 * and the per-player slots in gLinkPlayers. */
#ifndef OV009_LINK_H
#define OV009_LINK_H

#include "ds3dsprite.h"

/* Event record passed to the registered link task callback. */
#define LINK_EVENT_STATE   0x02 /* u16 phase/status reported by the task */
#define LINK_EVENT_COMMAND 0x08 /* u16 command reported by the task */
#define LINK_EVENT_VALUE   0x0a /* u16 command argument */

/* Event record of a link completion task started with func_02012b08: like the
 * callback above it carries the status at +0x02, but its command word is at +0x04. */
#define LINK_TASK_EVENT_COMMAND 0x04 /* u16 command reported by a completion task */
#define LINK_TASK_CMD_DATA_DONE 10   /* the task's data step finished; the link is up */

/* gLinkState link-setup flags and the console's own player slot. */
#define LINK_STATE_FLAGS        0x156 /* u8: link setup flags */
#define LINK_STATE_FLAG_LINKED  0x01  /* the link is up: set when a task reports its data step */
#define LINK_STATE_LOCAL_PLAYER 0x157 /* u8: this console's player slot */

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

/* Result code signalled when a link step completes. */
#define LINK_EVENT_COMPLETE 0x15

/* Live link actor instance (gLinkActorClass). */
#define LINK_ACTOR_RETRY     0x34 /* s16 retry counter */
#define LINK_ACTOR_MAX_RETRY 5    /* give up after this many retries */

/* Link message that announces a player: the 12-byte player record, then a
 * 26-byte name area (UTF-16, NUL-padded) in a 40-byte packet. */
#define LINK_MSG_PLAYER_INFO    13
#define LINK_PLAYER_INFO_SIZE   40
#define LINK_PLAYER_RECORD_SIZE 12
#define LINK_PLAYER_NAME_OFFSET 12
#define LINK_PLAYER_NAME_SIZE   26

/* A gLinkPlayers slot: one per player slot, 0x60 bytes. */
#define LINK_PLAYER_FLAGS 0x16 /* u8: bit 0 set while the slot holds a connected player */
#define LINK_PLAYER_ID    0x17 /* s8: the player id the slot plays as, -1 when unset */

/* gLinkState +0x28: u16 * mask of the player announcement in flight; the actor
 * stores its own bit there until every connected peer has answered. */
#define LINK_STATE_ANNOUNCE 0x28
/* gLinkState +0x04: u16 bit (player slot - 1) of every player the announcement
 * found, and +0x0A the value those answers report: an answer that reports a lower
 * value than the stored one starts the mask over, an equal one adds its bit. */
#define LINK_STATE_PLAYER_MASK  0x04
#define LINK_STATE_ANNOUNCE_KEY 0x0A

/* Return code of the announcer when no further player slot is left to ask. */
#define LINK_ANNOUNCE_DONE 0x19
/* WFC commands whose task returned 2 are queued and still running. */
#define LINK_TASK_QUEUED 2
/* gLinkState +0x50: s32 bit per player slot whose link result has been handled. */
#define LINK_STATE_RESULT_FLAGS 0x50

/* The link overlay's status-text layer (generic text-layer fields at 0x34..0x36
 * are in ds3dsprite.h): it shows a localized message while the link result is
 * on screen. */
#define LINK_LAYER_TEXT_KEY 0x38 /* s32 localized-text key shown by the layer */
#define LINK_LAYER_STYLE    0x3C /* s32 style word handed to the text renderer */
#define LINK_LAYER_STATUS   0x40 /* s32 link status/result code; 0 hides the layer */

#endif
