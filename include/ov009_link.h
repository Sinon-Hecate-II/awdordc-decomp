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
    LINK_PHASE_RESULT  = 7, /* showing the result/status screen */
    LINK_PHASE_ERROR   = 8,
    LINK_PHASE_ABORTED = 9
};

/* Result code signalled when a link step completes. */
#define LINK_EVENT_COMPLETE 0x15

/* Live link actor instance (gLinkActorClass). */
#define LINK_ACTOR_RETRY     0x34 /* s16 retry counter */
#define LINK_ACTOR_MAX_RETRY 5    /* give up after this many retries */

#endif
