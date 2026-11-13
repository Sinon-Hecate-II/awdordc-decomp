/* The network-stack socket layer (main_0201F89C..main_02020738).  A socket
 * object holds a raw connection at +0x64; the raw connection keeps the records
 * that have arrived but not been read yet in a singly linked queue.  The
 * data-arrival callback func_02020364 appends a record and wakes the reader;
 * SocketRecv (was func_02020220) removes one. */
#ifndef NET_SOCKET_H
#define NET_SOCKET_H

/* Socket object fields. */
#define SOCK_RAW        0x64 /* void *raw connection holding the receive queue */
#define SOCK_FLAGS      0x70 /* s16: bit 0 set once the socket is initialised */
#define SOCK_FLAG_READY 0x0001

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
 * send task drains.  It is empty when the write and read positions are equal. */
#define SEND_RING_SIZE  0xf8 /* u32 ring capacity in bytes */
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

/* SocketRecv results. */
#define SOCK_WOULD_BLOCK (-6)  /* nothing queued and the caller asked not to wait */
#define SOCK_ABORTED     (-56) /* the socket was closed or torn down while waiting */

#endif
