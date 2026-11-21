#ifndef ONLINE_LINK_H
#define ONLINE_LINK_H
#include "common.h"

/* Timer fields in the online link controller used by TickOnlinePeerKeepAlive. */
#define ONLINE_HEARTBEAT_FRAMES 0x34 /* s32 frames since the last heartbeat */
#define ONLINE_PEER_IDLE_FRAMES 0x38 /* s32[4] frames since each peer's last packet */
#define ONLINE_PEER_COUNT 4
#define ONLINE_PACKET_HEARTBEAT 1
#define ONLINE_HEARTBEAT_INTERVAL_MS 4000
#define ONLINE_PEER_TIMEOUT_NUMERATOR 1800000
#define ONLINE_MILLISECONDS_PER_SECOND 1000
#define ONLINE_TICK_RATE_FX12 0x3C000 /* 60 updates per second, 20.12 fixed point */
#define ONLINE_MS_PER_SECOND_FX12 0x3E8000

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

#endif
