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

#endif
