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
