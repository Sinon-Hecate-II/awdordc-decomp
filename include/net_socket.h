/* The network-stack socket layer (main_0201F89C..main_02020738).  A socket
 * object holds a raw connection at +0x64; the raw connection keeps the records
 * that have arrived but not been read yet in a singly linked queue.  The
 * data-arrival callback SocketQueueReceivedData appends a record and wakes the reader;
 * SocketRecv (was func_02020220) removes one. */
#ifndef NET_SOCKET_H
#define NET_SOCKET_H

/* Socket object fields. */
#define SOCK_RAW        0x64 /* void *raw connection holding the receive queue */
#define SOCK_KIND       0x72 /* s8: SOCK_KIND_TCP (1) for TCP sockets */
#define SOCK_FLAGS      0x70 /* s16: bit 0 set once the socket is initialised */
#define SOCK_FLAG_READY 0x0001
#define SOCK_FLAG_BUSY  0x0002 /* a task is running on the socket (or a read is in progress) */
#define SOCK_FLAG_DONE  0x0004 /* the outstanding operation finished, its result is at SOCK_STATUS */
#define SOCK_FLAG_ERROR 0x0008 /* the socket failed or was torn down */
#define SOCK_FLAG_TIMEOUT 0x0040 /* the last receive timed out */

/* A receive timeout request (SocketSetReceiveTimeout): while a read is in
 * progress (SOCK_FLAG_BUSY) the function reports instead of starting a new one. */
#define SOCK_RECV_TIMEOUT     0x6c /* s32 peer receive timeout, used when SOCK_FLAG_TIMEOUT */
#define SOCK_TIMEOUT          0x76 /* s16 timeout asked for */
#define SOCK_TIMEOUT_RESULT   0x78 /* s32 timeout result the pending operation is given */
#define SOCK_STATUS           0x6c /* s32 operation result, reported once SOCK_FLAG_DONE */

/* The socket's own local port (SOCK_RECV_PORT) and the port the transport layer
 * bound it to (SOCK_LINK_PORT, the low-level socket's local port); the first
 * received record fills SOCK_RECV_PORT in.  SOCK_PEER_* is the peer of the
 * record just queued, staged at SOCK_NEXT_PEER_* until the record is built. */
#define SOCK_RECV_PORT      0x74 /* u16 local port the socket receives on */
#define SOCK_LINK_PORT      0x0a /* u16 local port the transport bound the socket to */
#define SOCK_PEER_PORT      0x18 /* u16 port the queued record came from */
#define SOCK_PEER_ADDR      0x1c /* s32 IPv4 address the queued record came from */
#define SOCK_NEXT_PEER_PORT 0x1a /* u16 staged peer port */
#define SOCK_NEXT_PEER_ADDR 0x20 /* s32 staged peer IPv4 address */

/* Raw connection receive queue. */
#define CONN_RECV_TAIL   0x100 /* void *newest queued record */
#define CONN_RECV_HEAD   0x104 /* void *oldest queued record */
#define CONN_RECV_COUNT  0x108 /* u16 payload bytes queued */
#define CONN_RECV_LIMIT  0x10a /* u16 queue capacity in bytes */
#define CONN_RECV_THREAD 0x10c /* OSThreadQueue the reader sleeps on */
#define CONN_RECV_HOLD   0xfe  /* s8 nonzero while a caller peeks, so recv keeps the record */

/* A socket also holds a second raw connection at +0x68, used for sending.  Its
 * outgoing packet goes in a buffer described by {size at SOCK_TX_SIZE, pointer
 * at SOCK_TX_BUF}; only the bytes past the link/IP/transport header are payload. */
#define SOCK_STATE    0x73 /* s8 socket state: 0/4 = duplex, 1/2 = one-directional */
#define SOCK_TX_CONN  0x68 /* void *raw send connection that outgoing data is queued on */
#define SOCK_TX_SIZE  0x48 /* s32 bytes in the outgoing packet buffer */
#define SOCK_TX_BUF   0x4c /* u8 *outgoing packet buffer */
#define SOCK_TX_HDR_STREAM 0x36 /* link + IPv4 + TCP header in front of a stream payload */
#define SOCK_TX_HDR_DGRAM  0x2a /* link + IPv4 + UDP header in front of a datagram payload */

/* Send-side raw connection (socket + SOCK_TX_CONN): a single-producer ring the
 * send task drains.  It is empty when the write and read positions are equal. */#define SEND_RING_SIZE  0xf8 /* u32 ring capacity in bytes */
#define SEND_RING_BUF   0xfc /* u8 *ring data */
#define SEND_RING_WRITE 0x100 /* u16 position the producer writes at */
#define SEND_RING_READ  0x102 /* u16 position the consumer reads at */
#define SEND_RING_WAIT  0x104 /* OSThreadQueue producers sleep on when the ring is full */
#define SEND_RING_OWNER 0x10c /* void *socket that owns this connection */

/* One queued received record: a 0xC-byte header followed by its payload. */
#define REC_NEXT 0x00 /* void *next record, NULL at the tail */
#define REC_LEN  0x04 /* u16 payload bytes */
#define REC_PORT 0x06 /* u16 peer port */
#define REC_ADDR 0x08 /* s32 peer IPv4 address, host order */
#define REC_DATA 0x0c /* u8 payload */

/* The game's network heap interface (gNetAllocator), installed at network init;
 * only the alloc/free slots are used so far. */
#define NET_ALLOC_ALLOC 0x18 /* void *(*)(s32 size) */
#define NET_ALLOC_FREE  0x1c /* void (*)(void *block) */

/* Receive-side drop counters. */
#define RECV_STAT_NO_MEMORY  0x00 /* s32 records dropped because the allocator failed */
#define RECV_STAT_QUEUE_FULL 0x04 /* s32 records dropped because the queue was full */

/* SocketRecv results. */
#define SOCK_WOULD_BLOCK (-6)  /* nothing queued and the caller asked not to wait */
#define SOCK_ABORTED     (-56) /* the socket was closed or torn down while waiting */

/* The socket manager (gSocketManager): a list of socket objects; each object
 * links the socket the network stack sees at +0xA4. */
#define SOCKMGR_SOCKETS    0x08 /* void *first socket object */
#define SOCK_OBJECT_RAW    0xA4 /* void *the socket the network stack works on */
#define SOCK_OBJECT_NEXT   0x68 /* void *next socket object in the manager's list */

/* The raw connection a TCP socket owns (the +0xA4 pointer of a TCP socket):
 * its public id, the task using it, the state machine and the receive window.
 * The receive buffer is the raw connection's incoming packet buffer. */
#define CONN_ID            0x00 /* s32 public socket id (the handle the game passes around) */
#define CONN_TASK_ID       0x04 /* s32 socket task's id, woken when the data arrives */
#define CONN_STATE         0x08 /* u8 CONN_STATE_* */
#define CONN_LOCAL_PORT    0x0A /* u16 local TCP port */
#define CONN_REMOTE_PORT   0x18 /* u16 remote TCP port */
#define CONN_REMOTE_IP     0x1C /* u32 remote IPv4 address, host order */
#define CONN_SEQUENCE      0x24 /* u32 sequence number expected next */
#define CONN_IN_WINDOW     0x3C /* u32 receive buffer capacity */
#define CONN_RX_BUFFER     0x40 /* u8 *receive buffer */
#define CONN_RX_POS        0x44 /* u32 bytes in the receive buffer */
#define CONN_RX_PENDING_LEN 0x44 /* u32 length of the pending ICMP datagram (in CONN_RX_BUFFER);
                                  * kept 0 while none is pending, so the received payload is
                                  * discarded when 0 */
#define CONN_RX_MAX        0x48 /* u32 receive buffer size */
#define CONN_RX_PENDING    0x68 /* u32 bytes of the pending ICMP datagram, 0 when none */
#define CONN_RX_PENDING_BUF 0x4C /* u8 *buffer the pending datagram is copied into */

/* CONN_STATE values. */
#define CONN_STATE_CLOSED      0
#define CONN_STATE_LISTEN      1
#define CONN_STATE_SYN_SENT    2
#define CONN_STATE_SYN_RCVD    3
#define CONN_STATE_ESTABLISHED 4

enum {
    SOCK_KIND_TCP  = 1,
    SOCK_KIND_UDP  = 10,
    SOCK_KIND_ICMP = 11
};

#endif
