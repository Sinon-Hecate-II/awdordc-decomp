#ifndef ONLINE_LINK_H
#define ONLINE_LINK_H
#include "common.h"

/* Timer fields in the online link controller used by TickOnlinePeerKeepAlive. */
#define ONLINE_HEARTBEAT_FRAMES 0x34 /* s32 frames since the last heartbeat */
#define ONLINE_PEER_IDLE_FRAMES 0x38 /* s32[4] frames since each peer's last packet */
#define ONLINE_PEER_COUNT 4
#define ONLINE_PACKET_HEARTBEAT 1
#define ONLINE_PACKET_START_REQUEST 2 /* the host asks the peers to start the match, payload is the start record */
#define ONLINE_PACKET_START_ACK     3 /* a peer acknowledges a start request */
#define ONLINE_PACKET_PLAYER_STATUS 7 /* broadcast the sender's online player record to the peers */
#define ONLINE_PACKET_DEPARTURE     9 /* broadcast that the sender is leaving the match */
#define ONLINE_HEARTBEAT_INTERVAL_MS 4000
#define ONLINE_PEER_TIMEOUT_NUMERATOR 1800000
/* Bytes of the local player's name (GetLocalPlayerName) copied into the online
 * local-player status record by CopyPlayerNameToStatus. */
#define ONLINE_PLAYER_STATUS_NAME_SIZE 0x18
#define ONLINE_MILLISECONDS_PER_SECOND 1000
#define ONLINE_TICK_RATE_FX12 0x3C000 /* 60 updates per second, 20.12 fixed point */
#define ONLINE_MS_PER_SECOND_FX12 0x3E8000

/* Start/match flags of the ov010 online session (gOv010OnlineSession+0xFA).
 * Ov010Online_StartSession sets STARTED and stores its argument at +0xFC; the
 * match start paths raise MATCH and leaving a match clears it again. */
#define OV010_SESSION_FLAGS        0xFA /* u8: OV010_SESSION_FLAG_* bits */
#define OV010_SESSION_FLAG_STARTED 0x01 /* the session start was requested */
#define OV010_SESSION_FLAG_MATCH   0x02 /* a match is running */

/* The work block an ov010 online session allocates for itself (OV010_FLAG_STARTED)
 * and frees when it is torn down. */
#define OV010_SESSION_WORK_BLOCK 0x3C   /* void *: the session's work block */
#define OV010_SESSION_WORK_SIZE  0x10E0 /* bytes of that block */
#define OV010_SESSION_STEP_FLAGS 0x54   /* s32: OV010_FLAG_* bits (see common.h) */
#define OV010_SESSION_SCORE_CALLBACK 0x20 /* s32 (*)(s32 index, s32 arg): the app's score for a browsed matchmaking session, added to a base score of 1 */

/* The online session's outbound packet queue (gOv010OnlineSession): a singly
 * linked list of nodes {void *next; Ov010Packet packet;}, the packet's kind
 * byte at node+0x08 (Ov010Packet.kind sits at +0x04), its payload right after
 * the 16-byte header.  The tail node is kept at ONLINE_SESSION_QUEUE_TAIL and
 * ONLINE_SESSION_QUEUE_COUNT counts the queued nodes. */
#define ONLINE_SESSION_QUEUE      0x60 /* node *: first queued packet, NULL when empty */
#define ONLINE_SESSION_QUEUE_TAIL 0x64 /* node *: last queued packet, NULL when empty */
#define ONLINE_SESSION_QUEUE_COUNT 0x68 /* u32 nodes currently queued */
#define ONLINE_QUEUE_NODE_NEXT    0x00 /* node *: next queued packet */
#define ONLINE_QUEUE_NODE_KIND    0x08 /* u8: packet kind (ONLINE_PACKET_*) */
#define ONLINE_QUEUE_NODE_SIZE    0x0C /* u32: payload size of the queued packet */
#define ONLINE_QUEUE_NODE_HEADER  0x10 /* bytes of a node before its payload */

/* A bare outbound packet queue: the {head, tail, count} layout that also starts
 * at ONLINE_SESSION_QUEUE in the online session and at every per-channel receive
 * queue entry. */
#define ONLINE_QUEUE_HEAD  0x00 /* node *: first queued node, NULL when empty */
#define ONLINE_QUEUE_TAIL  0x04 /* node *: last queued node, NULL when empty */
#define ONLINE_QUEUE_COUNT 0x08 /* u32: nodes currently queued */

#ifdef ONLINE_USE_INTERRUPT_GUARD
static inline u32 ov010DisableInterrupts(void) {
    u32 previous = *(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = 0;
    return previous;
}
static inline u32 ov010RestoreInterrupts(u32 saved) {
    u32 previous = *(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = saved;
    return previous;
}
#pragma cplusplus on
class Ov010InterruptGuard {
    u32 saved;
public:
    Ov010InterruptGuard() : saved(ov010DisableInterrupts()) {}
    ~Ov010InterruptGuard() { ov010RestoreInterrupts(saved); }
};
#pragma cplusplus off
#endif

/* An online packet as queued and sent on the link: a 12-byte header followed
 * immediately by `size` payload bytes.  In a queued node the payload therefore
 * starts at ONLINE_QUEUE_NODE_HEADER (0x10), after the 4-byte link pointer.
 * The magic tags a header as valid when a raw buffer is parsed. */
#define ONLINE_PACKET_MAGIC       0x5F57464D /* 'MFW_' */
#define ONLINE_PACKET_HEADER_SIZE 0x0C       /* bytes before the payload */
typedef struct Ov010Packet {
    u32 magic;        /* +0x00: ONLINE_PACKET_MAGIC when valid */
    u8  kind;         /* +0x04: packet kind (ONLINE_PACKET_*) */
    u8  channel : 4;  /* +0x05 low nibble: target channel */
    u8  flags : 4;    /* +0x05 high nibble */
    u16 id;           /* +0x06: packet id */
    u32 size;         /* +0x08: payload byte count */
} Ov010Packet;        /* 0x0C bytes; payload follows */

#endif
