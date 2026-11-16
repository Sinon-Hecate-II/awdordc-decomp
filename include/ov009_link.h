/* The ov009 single-card (Download Play) link overlay.  A multiboot task reports
 * events to a callback; the callback drives the link state machine in gLinkState
 * and the per-player slots in gLinkPlayers. */
#ifndef OV009_LINK_H
#define OV009_LINK_H

/* Event record passed to the registered link task callback. */
#define LINK_EVENT_STATE   0x02 /* u16 phase/status reported by the task */
#define LINK_EVENT_COMMAND 0x08 /* u16 command reported by the task */
#define LINK_EVENT_VALUE   0x0a /* u16 command argument */

/* Phases of the link state machine (gLinkState +0x10). */
enum {
    LINK_PHASE_IDLE    = 0,
    LINK_PHASE_ACTIVE  = 4, /* link established; the menu treats 4/5 as in-game */
    LINK_PHASE_INGAME  = 5, /* second in-game phase; every check accepts 4 or 5 */
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

/* gLinkState +0x28: u16 * mask of the player announcement in flight; the actor
 * stores its own bit there until every connected peer has answered. */
#define LINK_STATE_ANNOUNCE 0x28

#endif
