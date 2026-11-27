/* The network-stack socket layer (main_0201F89C..main_02020738).  A socket
 * object holds a raw connection at +0x64; the raw connection keeps the records
 * that have arrived but not been read yet in a singly linked queue.  The
 * data-arrival callback SocketQueueReceivedData appends a record and wakes the reader;
 * SocketRecv (was func_02020220) removes one. */
#ifndef NET_SOCKET_H
#define NET_SOCKET_H

/* A socket operation is a small request record the caller fills in and hands to
 * the socket's task (func_0201f1d0 allocates one, SocketSubmitRecvTask/SocketSubmitSendTask/
 * SocketSubmitTaskAndWait post it, the task calls the callback with the record).  Its
 * fixed part is: +0x00 callback the task runs, +0x04 the socket, +0x08 the
 * task's message queue, +0x0C the socket's state and +0x0D nonzero when the
 * caller waits for the result; +0x10 onwards are the callback's own arguments.
 * SocketListen shows the shape: it passes the receive port at +0x10 and the two
 * out-pointers at +0x14/+0x18 to its task half SocketListenTask. */

/* Socket object fields. */
#define SOCK_RAW        0x64 /* void *raw connection holding the receive queue */
/* SOCK_BLOCKING is 1 while the socket may block: a receive waits for its data and
 * a socket task waits for its result.  fcntl(F_SETFL) with O_NONBLOCK clears it,
 * after which receives only try to lock the connection.  (The transport kind TCP /
 * UDP / ICMP is SOCK_TRANSPORT in tcp_socket.h, a different field.) */
#define SOCK_BLOCKING       0x72 /* s8: 1 = blocking I/O, 0 = non-blocking */
#define SOCK_BLOCKING_ON    1    /* the blocking value of SOCK_BLOCKING */

/* Commands and flag of the fcntl-like socket control call (SocketFcntl):
 * F_GETFL returns the socket's status flags, F_SETFL sets them from the value
 * passed, and O_NONBLOCK (bit 4 of those flags) means the socket is
 * non-blocking, i.e. SOCK_BLOCKING is clear. */
#define F_GETFL    3
#define F_SETFL    4
#define O_NONBLOCK 4
/* The network task's state object (gNetTaskState, set up by NetworkInitStack in
 * main_0201E944): the flags word at +0x08 records the connection setup, and the
 * +0x1C callback applies a pre-supplied configuration.
 * NET_TASK_FLAG_READY is set by NetTask_MarkReady (the setup callback used when
 * the configuration was already applied). */
#define NET_TASK_FLAGS      0x08 /* s32 flag word */
#define NET_TASK_FLAG_READY 0x02 /* the setup callback has applied the network configuration */

#define SOCK_FLAGS      0x70 /* s16: bit 0 set once the socket is initialised */
#define SOCK_FLAG_READY 0x0001
#define SOCK_FLAG_BUSY  0x0002 /* a task is running on the socket (or a read is in progress) */
#define SOCK_FLAG_DONE  0x0004 /* the outstanding operation finished, its result is at SOCK_STATUS */
#define SOCK_FLAG_ERROR 0x0008 /* the socket failed or was torn down */
#define SOCK_FLAG_TIMEOUT 0x0040 /* the last receive timed out */
#define SOCK_FLAG_CLOSING 0x0010 /* a close is under way (set by SocketClose) */
#define SOCK_FLAG_CLOSED  0x0020 /* the close task finished tearing the socket down */

#define SOCK_STATUS           0x6c /* s32 operation result, reported once SOCK_FLAG_DONE */

/* A connect request (SocketConnect, the ghiConnect path): the peer port and IPv4
 * address the socket's raw connection is pointed at.  While an operation is in
 * progress (SOCK_FLAG_BUSY) the call reports its state instead of starting a new
 * one.  The raw send path also reads these as the packet tag and fallback address. */
#define SOCK_CONNECT_PORT     0x76 /* u16 peer port of a connect request (packet tag of a raw send) */
#define SOCK_CONNECT_ADDR     0x78 /* s32 peer IPv4 address of a connect request (fallback address of a raw send) */
#define SOCK_NO_SOCKET  (-49) /* no socket object could be allocated for the config */
#define SOCK_CONNECT_FAILED   (-76) /* the connect attempt failed */

/* SocketConnect's task arguments (a socket task record, +0x10 onwards). */
#define CONNECT_TASK_LOCAL_PORT 0x10 /* u16 local port bound to the connection */
#define CONNECT_TASK_PEER_PORT  0x12 /* u16 peer port to connect to */
#define CONNECT_TASK_PEER_ADDR  0x14 /* s32 peer IPv4 address, host order */

/* SocketListen's task arguments: the local port to listen on and the two
 * out-pointers the task reports the peer endpoint through. */
#define LISTEN_TASK_LOCAL_PORT    0x10 /* u16 receive port the socket listens on */
#define LISTEN_TASK_PEER_PORT_PTR 0x14 /* u16 *out: peer port of the connection */
#define LISTEN_TASK_PEER_ADDR_PTR 0x18 /* s32 *out: peer IPv4 address of the connection */

/* SocketStartRecvTask's task arguments (the receive task reads them back): the
 * buffer to receive into, its length and the peer-endpoint out-pointers. */
#define RECV_TASK_BUF       0x10 /* s32 destination buffer */
#define RECV_TASK_LEN       0x14 /* u32 bytes to receive */
#define RECV_TASK_PEER_PORT 0x18 /* u16 *out: peer port of the received data */
#define RECV_TASK_PEER_ADDR 0x1C /* s32 *out: peer IPv4 address of the received data */

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

/* The well-known UDP port of a DNS server. */
#define DNS_SERVER_PORT 53

/* The two IPv4 DNS servers of gDnsServerAddresses, in query order. */
#define DNS_SERVER_PRIMARY   0x00 /* s32 primary server address */
#define DNS_SERVER_SECONDARY 0x04 /* s32 secondary server address */

/* Raw connection receive queue. */
#define CONN_RECV_TAIL   0x100 /* void *newest queued record */
#define CONN_RECV_HEAD   0x104 /* void *oldest queued record */
#define CONN_RECV_COUNT  0x108 /* u16 payload bytes queued */
#define CONN_RECV_LIMIT  0x10a /* u16 queue capacity in bytes */
#define CONN_RECV_THREAD 0x10c /* OSThreadQueue the reader sleeps on */
#define CONN_RECV_HOLD   0xfe  /* s8 nonzero while a caller peeks, so recv keeps the record */
#define CONN_RECV_PENDING 0xf8 /* s32 received bytes waiting to be consumed (ConsumeConnectionReceivedData) */
#define CONN_RECV_RELEASE_AT 0xfc /* u16 pending-byte count at which the receive window is released */

/* A socket also holds a second raw connection at +0x68, used for sending.  Its
 * outgoing packet goes in a buffer described by {size at SOCK_TX_SIZE, pointer
 * at SOCK_TX_BUF}; only the bytes past the link/IP/transport header are payload. */
#define SOCK_STATE    0x73 /* s8 socket state: 0/4 = duplex, 1/2 = one-directional */
#define SOCK_TX_CONN  0x68 /* void *raw send connection that outgoing data is queued on */
#define SOCK_TX_SIZE  0x48 /* s32 bytes in the outgoing packet buffer */
#define SOCK_TX_BUF   0x4c /* u8 *outgoing packet buffer */
#define SOCK_TX_HDR_STREAM 0x36 /* link + IPv4 + TCP header in front of a stream payload */
#define SOCK_TX_HDR_DGRAM  0x2a /* link + IPv4 + UDP header in front of a datagram payload */

#define SOCK_SEND_WAIT_FOR_SPACE 0x01 /* Sleep when the send ring has too little room. */

/* Receive flags handed to the socket's receive entry; bit 1 is looked at by
 * SocketRecvLocked, bit 2 while the call is being set up. */
#define SOCK_RECV_PEEK     0x02 /* report the record without dequeuing it */
#define SOCK_RECV_NONBLOCK 0x04 /* try-lock the socket's mutex and do not wait for data */

/* The mutex every receive and send of a connection runs under. */
#define CONN_MUTEX         0xE0

/* Send-side raw connection (socket + SOCK_TX_CONN): a single-producer ring the
 * send task drains.  It is empty when the write and read positions are equal. */#define SEND_RING_SIZE  0xf8 /* u32 ring capacity in bytes */
#define SEND_RING_BUF   0xfc /* u8 *ring data */
#define SEND_RING_WRITE 0x100 /* u16 position the producer writes at */
#define SEND_RING_READ  0x102 /* u16 position the consumer reads at */
#define SEND_RING_WAIT  0x104 /* OSThreadQueue producers sleep on when the ring is full */
#define SEND_RING_OWNER 0x10c /* void *socket that owns this connection */

/* A queued send: the socket layer allocates one when a send is posted and the
 * send task drains it.  The bytes to send may wrap in the send ring, so the
 * record describes them as two (pointer, length) pieces.  It also carries the
 * ring position the queueing ended at and the header fields the task puts in
 * front of the data. */
typedef struct SendRequest {
    u8  filler_00[0x10];
    s32 firstPtr;   /* +0x10 start of the first piece in the send ring */
    s32 firstLen;   /* +0x14 bytes left in the first piece */
    s32 secondPtr;  /* +0x18 start of the wrapped piece, 0 when there is none */
    s32 secondLen;  /* +0x1C bytes left in the wrapped piece */
    u16 position;   /* +0x20 send-ring write position the queueing ended at */
    u16 reserved22; /* +0x22 unused */
    u16 port;       /* +0x24 local port the data goes out from */
    u16 tag;        /* +0x26 packet tag */
    s32 fallback;   /* +0x28 address to send to when there is no connection */
} SendRequest;

/* The socket object's link in the socket layer's open/closed lists
 * (gActiveSocketList / gClosedSocketList). */
#define SOCK_LIST_NEXT  0x7c /* void *next socket in the list */

/* A socket result meaning the socket layer is still tearing sockets down. */
#define SOCK_BUSY (-0x1A)

/* Result a caller waiting on a queued task is given when its connection is torn
 * down before the task could run (ConnectionAbort). */
#define SOCK_TASK_ABORTED (-11)

/* One queued received record: a 0xC-byte header followed by its payload. */
#define REC_NEXT 0x00 /* void *next record, NULL at the tail */
#define REC_LEN  0x04 /* u16 payload bytes */
#define REC_PORT 0x06 /* u16 peer port */
#define REC_ADDR 0x08 /* s32 peer IPv4 address, host order */
#define REC_DATA 0x0c /* u8 payload */

/* The game's network heap interface (gNetAllocator), installed at network init;
 * the alloc/free slots and the socket-task count are used so far. */
#define NET_ALLOC_ALLOC 0x18 /* void *(*)(s32 size) */
#define NET_ALLOC_FREE  0x1c /* void (*)(void *block) */
#define NET_ALLOC_TASKS 0x20 /* s32 socket task slots the network task pool holds */

/* The socket task pool (gSocketTaskPool, main_0201E944): one block from the net
 * allocator holding the free-task message queue (gSocketTaskQueue, which sits
 * immediately at +0x04) followed by the task slots themselves.  A slot is taken
 * by receiving it from the queue (ReceiveSocketTaskSlot) and returned by posting it back
 * (SocketFreeTask), so the queue holds every slot that is currently idle. */
#define TASKPOOL_BLOCK 0x00 /* void *the allocated block */
#define TASKPOOL_SLOTS 0x18 /* s32 slots the pool was created with (the queue's msgCount) */
#define TASKPOOL_FREE  0x20 /* s32 slots idle in the queue (its usedCount) */

/* One queued socket task (SocketAllocTask builds it from the task pool and
 * SocketQueueTask posts it to a raw connection's queue); the socket task thread
 * calls TASK_FUNC with TASK_SOCKET and forwards TASK_RESULT to the waiter. */
#define TASK_FUNC   0x00 /* void *(*)(void *) the task's function */
#define TASK_SOCKET 0x04 /* void *socket the task works on */
#define TASK_NOTIFY 0x08 /* void *message queue the task's result is sent to, 0 when no caller waits */
#define TASK_STATE  0x0C /* s8 socket state copied from the socket (SOCK_STATE) */
#define TASK_WAIT   0x0D /* s8: 1 when the caller blocks waiting for the task's result */
#define TASK_BYTES  0x2C /* bytes per queued socket task slot */

/* Receive-side drop counters. */
#define RECV_STAT_NO_MEMORY  0x00 /* s32 records dropped because the allocator failed */
#define RECV_STAT_QUEUE_FULL 0x04 /* s32 records dropped because the queue was full */

/* Socket call results. */
#define SOCK_ERROR       (-28) /* the socket is unregistered, not initialised or in the wrong state */
#define SOCK_NOT_READY   (-39) /* the socket's ready flag is clear */
#define SOCK_WOULD_BLOCK (-6)  /* nothing queued and the caller asked not to wait */
#define SOCK_ALREADY     (-7)  /* an operation is already in progress on the socket */
#define SOCK_NO_MEMORY  (-33) /* no task record could be allocated for the operation */
#define SOCK_ABORTED     (-56) /* the socket was closed or torn down while waiting */
#define SOCK_MESSAGE_TOO_LONG (-35) /* a send is larger than the packet buffer allows */
#define SOCK_TASK_QUEUE_FULL (-42) /* a raw connection's task queue was full, so the task was not queued */

/* A DNS lookup runs over a temporary raw connection whose buffers come from one
 * allocation: a receive buffer and, behind it, the pending-datagram buffer. */
#define DNS_LOOKUP_BLOCK_BYTES   0xFD0 /* bytes of the block LookupHostAddress allocates */
#define DNS_LOOKUP_RX_BYTES      0xB68 /* CONN_IN_WINDOW of that connection */
#define DNS_LOOKUP_PENDING_BYTES 0x466 /* CONN_RX_MAX (pending-datagram buffer) of it */

/* gDnsQueryState (main_02047B84): the service-availability DNS lookup some callers
 * address as an s32 array.  Its first word is the query state; network code only
 * starts a connect while no lookup is in flight. */
#define DNS_QUERY_STATE  0x00 /* s32 */
#define DNS_QUERY_IDLE   1    /* no lookup in flight: its result is unknown or expired */
#define DNS_QUERY_SOCKET      0x04 /* s32 socket the query is sent on, -1 until created */
#define DNS_QUERY_PACKET_LEN  0x50 /* s32 bytes of the query packet to send */
#define DNS_QUERY_SENT        0x54 /* u32 GetSystemTickMilliseconds() of the last send */
#define DNS_QUERY_RETRIES     0x58 /* s32 times the query was resent */

/* The socket manager (gSocketManager): a list of socket objects; each object
 * links the socket the network stack sees at +0xA4.  The word at +0x04 is the
 * thread that is currently running, shared with the scheduler/mutex code. */
#define SOCKMGR_RUNNING_THREAD 0x04 /* Thread *: the thread the scheduler is running */
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
#define CONN_PENDING_TX_BUF 0x5C /* s32 address of the send data still queued for the connection */
#define CONN_PENDING_TX_LEN 0x60 /* u32 bytes queued there, 0 when nothing is pending */

/* CONN_STATE values. */
#define CONN_STATE_CLOSED      0
#define CONN_STATE_LISTEN      1
#define CONN_STATE_SYN_SENT    2
#define CONN_STATE_SYN_RCVD    3
#define CONN_STATE_ESTABLISHED 4
#define CONN_STATE_RAW         10 /* a raw (connectionless) connection is open: no
                                   * handshake, and buffered receive data is dropped */
/* Transport kinds of a socket (the SOCK_TRANSPORT byte of tcp_socket.h). */
enum {
    SOCK_KIND_TCP  = 1,
    SOCK_KIND_UDP  = 10,
    SOCK_KIND_ICMP = 11
};

/* SOCK_STATE values: which directions the socket has open.  A receive-only
 * socket reads the record queue SocketQueueReceivedData fills; the duplex states
 * read the connection's receive window instead (see SocketPoll). */
enum {
    SOCK_STATE_IDLE      = 0, /* nothing open yet */
    SOCK_STATE_RECV_ONLY = 1,
    SOCK_STATE_SEND_ONLY = 2,
    SOCK_STATE_CONNECTED = 4  /* both directions open */
};

/* A socket config template (gTcpSocketConfig / gUdpSocketConfig):
 * SocketCreateFromConfig copies one into the socket object it allocates.  A zero
 * receive or send byte size disables that direction; each direction also has a
 * task record describing its thread stack and message queue. */
typedef struct SocketConfigTask {
    u16 stackBytes;   /* +0x00 thread stack bytes */
    u8  priority;     /* +0x02 thread priority */
    u8  messageCount; /* +0x03 messages in its queue, four bytes each */
} SocketConfigTask;

/* A receive or transmit worker starts with its message queue at offset 0. */
#define SOCKET_WORKER_THREAD 0x20
#define SOCKET_WORKER_MUTEX  0xE0
typedef struct SocketConfigTemplate {
    u8  state;          /* +0x00 SOCK_STATE */
    u8  blocking;       /* +0x01 SOCK_BLOCKING_ON */
    u16 rxBytes;        /* +0x02 receive-buffer bytes, 0 = no receive side */
    u16 unknown04;      /* +0x04 */
    u16 txBytes;        /* +0x06 outgoing packet-buffer bytes, 0 = no send side */
    u16 rxPendingBytes; /* +0x08 pending-datagram buffer bytes */
    u16 txBytes2;       /* +0x0A second send-buffer bytes */
    u16 txRingBytes;    /* +0x0C send-ring bytes */
    u16 unknown0E;      /* +0x0E */
    SocketConfigTask rxTask; /* +0x10 */
    SocketConfigTask txTask; /* +0x14 */
} SocketConfigTemplate;

/* Arguments of SocketCreate, the BSD socket() equivalent: the stream type builds
 * the socket from gTcpSocketConfig, every other type from gUdpSocketConfig.  The
 * stack only speaks IPv4 and the templates fix the buffering, so the address
 * family (2 = AF_INET) and protocol (0) arguments are ignored. */
#define SOCK_TYPE_STREAM 1 /* stream (TCP) socket */
#define SOCK_TYPE_DGRAM  2 /* datagram (UDP) socket */

#endif
