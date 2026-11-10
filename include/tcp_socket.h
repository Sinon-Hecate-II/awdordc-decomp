/* Fields of the TCP socket object used by TcpSendData in main_0201CB4C, and
 * the network-stack callback that says whether the link is up. */
#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#define TCP_SOCK_STATE   0x08 /* u8 connection state, 4 = established */
#define TCP_SOCK_SENDPOS 0x28 /* u32 bytes queued into the send buffer */
#define TCP_SOCK_ACKFLAG 0x2C /* u16 set when the peer acknowledges */
#define TCP_SOCK_SENTPOS 0x30 /* u32 bytes handed to the link */
#define TCP_SOCK_RESULT  0x34 /* s32 result of the last operation */

/* Network stack state (gNetStack) callbacks. */
#define NETSTACK_POLL 0x48 /* s32 (*poll)(void): nonzero while the link is up */

/* gNetStack single-producer/single-consumer packet ring.  The producer appends
 * a record at NETSTACK_RING_WRITE (a u16 length followed by the packet data) and
 * must stay ahead of the consumer position; the consumer advances through the
 * ring the same way.  A record never wraps: it is only started if it fits. */
#define NETSTACK_RING_WRITE 0x28 /* u32 byte offset where the next record is written */
#define NETSTACK_RING_READ  0x30 /* u32 byte offset of the next record to read */
#define NETSTACK_RING_BUF   0x58 /* u8 *ring buffer */
#define NETSTACK_RING_SIZE  0x5c /* u32 ring buffer size in bytes */
#define NETSTACK_MAX_PACKET 0x5e4 /* largest record the ring accepts */

/* More gNetStack fields used by the IPv4 sender in main_0201AE0C. */
#define NETSTACK_IP_ID    0x06 /* u16 IPv4 identification counter, bumped per packet */
#define NETSTACK_LOCAL_IP 0x50 /* u32 local IPv4 address, host order */

/* IPv4 fragmentation: at most 1480 payload bytes per fragment, the fragment
 * offset counts 8-byte units, and the more-fragments flag is 0x2000. */
#define IP_MAX_FRAGMENT_PAYLOAD 1480
#define IP_FRAGMENT_UNIT        8
#define IP_FLAG_MOREFRAGMENTS   0x2000

#endif
