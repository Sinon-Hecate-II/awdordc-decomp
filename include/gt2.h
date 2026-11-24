#ifndef GT2_H
#define GT2_H

/* Fields of the GameSpy GT2 connection and its owning socket. */
#define GT2_CONNECTION_IP          0x00 /* s32 remote IPv4 address */
#define GT2_CONNECTION_PORT        0x04 /* u16 remote port */
#define GT2_CONNECTION_SOCKET      0x08 /* void *owning socket */
#define GT2_SOCKET_HANDLE          0x00 /* s32 OS socket handle, -1 before it is created */
#define GT2_CONNECTION_SEND_BUFFER 0x50 /* u8 *ring buffer keeping sent command bytes until the peer acknowledges them */
#define GT2_SEND_BUFFER_LEN        0x58 /* s32 bytes used in GT2_CONNECTION_SEND_BUFFER (its Gt2Buffer.len) */
#define GT2_CONNECTION_PENDING_QUEUE 0x5C /* Vector *of received commands buffered until their sequence is due, sorted by sequence */
/* One entry of GT2_CONNECTION_PENDING_QUEUE: where the command's bytes sit in the
 * receive buffer, its command id and its sequence number. */
typedef struct Gt2PendingCommand {
    s32 offset;   /* +0x00 offset in GT2_CONNECTION_RECV_BUFFER */
    s32 size;     /* +0x04 byte length */
    s32 kind;     /* +0x08 command id */
    u16 sequence; /* +0x0C sequence number */
} Gt2PendingCommand;
#define GT2_CONNECTION_ACK_QUEUE   0x60 /* Vector *of sent commands awaiting the peer's acknowledgement, sorted by sequence */
#define GT2_CONNECTION_STATE       0x0C /* s32 handshake/connection state */
#define GT2_CONNECTION_INITIATOR   0x10 /* s32 nonzero for a connection this side opened (the client), 0 for one the peer opened and the server accepted */
#define GT2_CONNECTION_CLOSE_PENDING 0x14 /* s32 set when a connection closed while still awaiting the server's accept; the accept step then refuses it and clears the flag */
#define GT2_CONNECTION_LAST_RECEIVE 0x1C /* u32 tick of the last command received, set to the creation time at first */
#define GT2_CONNECTION_TIMEOUT     0x20 /* u32 silence limit in ms while this connection handshakes, 0 to use GT2_CONNECT_TIMEOUT */
#define GT2_CONNECTION_RESPONSE    0x68 /* 32-byte expected challenge response */
#define GT2_CONNECTION_SEND_SEQUENCE 0x64 /* u16 sequence number the next sent command carries */
#define GT2_CONNECTION_LAST_SENT   0x88 /* s32 tick of the last successful raw send */
#define GT2_CONNECTION_START_TIME  0x8C /* s32 connection start time in milliseconds, set when a handshake command was sent */
/* Set when received data still owes the peer an acknowledgement, and the tick it
 * was set at (Gt2NoteDataReceived).  After GT2_ACK_DELAY ms the delayed
 * acknowledgement (control message 100) is sent and the flag cleared; sending any
 * command also carries the receive sequence and clears it. */
#define GT2_CONNECTION_ACK_PENDING 0x90 /* s32 pending-acknowledgement flag */
#define GT2_CONNECTION_ACK_TIME    0x94 /* u32 tick the flag was set at */
#define GT2_ACK_DELAY              100  /* ms of silence before the delayed acknowledgement */
#define GT2_CONNECTION_DATA        0x38 /* void *data to send with our handshake message */
#define GT2_CONNECTION_DATA_LEN    0x3C /* s32 length of GT2_CONNECTION_DATA */
#define GT2_CONNECTION_SEND_FILTERS 0x98 /* Vector of send filters (gti2SendFilterCallback) */
#define GT2_CONNECTION_MESSAGE_CALLBACKS GT2_CONNECTION_SEND_FILTERS
#define GT2_CONNECTION_FILTERS     0x9C /* Vector of receive filters (gti2ReceiveFilterCallback) */
/* The connection's callback for the current event (0x28, or 0x2C with a message
 * pointer) and the two counters that nest around calling it: one on the
 * connection (+0x24) and one on its socket (+0x1C), so the socket can be
 * destroyed once the outermost callback returns. */
#define GT2_CONNECTION_CALLBACK    0x28 /* void (*)(connection, event type, data, length) */
#define GT2_CONNECTION_CALLBACK_MSG 0x2C /* void (*)(connection, message, length, unk) */
#define GT2_CONNECTION_CALLBACK_CLOSED 0x30 /* void (*)(connection, close reason) */
#define GT2_CONNECTION_CALLBACK_PING   0x34 /* void (*)(connection, ping time in milliseconds) */
#define GT2_CONNECTION_CALLBACKS   0x24 /* s32 connection callbacks running */
#define GT2_SOCKET_CALLBACKS       0x1C /* s32 callbacks running on the socket */
#define GT2_SOCKET_DIRTY           0x14 /* s32 set when the socket was asked to be freed */
#define GT2_SOCKET_CONNECT_ATTEMPT 0x20 /* callback for incoming connections */
#define GT2_SOCKET_CONNECTION_TABLE 0x0C /* HashTable *of the connections keyed by remote address/port */
#define GT2_SOCKET_CONNECTIONS      0x10 /* Vector *of the connections the socket owns */
#define GT2_SOCKET_ERROR_CALLBACK  0x24 /* void (*)(socket): socket error callback the socket was created with */
/* A connection accepted by the server may stay silent for this long while its
 * handshake is in progress before GT2 gives up on it. */
#define GT2_CONNECT_TIMEOUT 60000

enum {
    GT2_STATE_AWAIT_CONNECT_ACCEPT = 0, /* client sent its challenge, waiting for CONNECT_ACCEPT */
    GT2_STATE_AWAIT_SERVER_ACCEPT = 1,  /* client sent its response, waiting for ACCEPT */
    GT2_STATE_AWAIT_CLIENT_CONNECT = 2, /* server accepted a socket, waiting for the client's CONNECT */
    GT2_STATE_AWAIT_CLIENT_RESPONSE = 3,
    GT2_STATE_AWAIT_ACCEPT = 4,
    GT2_STATE_CONNECTED = 5,            /* both sides accepted the handshake; data flows */
    GT2_STATE_PEER_CLOSED = 6,          /* the peer's closed command arrived, waiting for our side to finish */
    GT2_STATE_CLOSED = 7,               /* connection torn down */
    GT2_RESPONSE_SIZE = 32,
    GT2_CONNECT_ACCEPT_SIZE = 64        /* challenge response + the server's challenge */
};
/* Bytes of a CONNECT command: its 7-byte command header plus the client's
 * 32-byte challenge (the size gti2BeginCommand is given for it). */
#define GT2_CONNECT_SIZE (7 + GT2_RESPONSE_SIZE)
/* Bytes every GT2 command starts with: the magic string, the command id and the
 * sent and received sequence numbers. */
#define GT2_COMMAND_HEADER_SIZE 7
/* Challenge/response bytes are printable characters '!'..'}' (GTI2_CHALLENGE_BASE
 * plus 0..GTI2_CHALLENGE_RANGE-1); the response's rolling weight advances by
 * GTI2_RESPONSE_STEP at every position. */
#define GTI2_CHALLENGE_BASE  33
#define GTI2_CHALLENGE_RANGE 93
#define GTI2_RESPONSE_STEP   0x4647
/* Command ids of the short GT2 messages: the byte after the magic string. */
enum {
    GTI2_DATA             = 0, /* application data command (dispatched to gti2HandleDataCommand) */
    GTI2_CONNECT          = 1, /* client -> server challenge */
    GTI2_CONNECT_ACCEPT   = 2, /* server: response plus its own challenge */
    GTI2_CLIENT_RESPONSE  = 3, /* client: response to the server's challenge plus data */
    GTI2_ACCEPT           = 4, /* connection accepted, no payload */
    GTI2_CLOSE            = 5, /* close request with a reason string */
    GTI2_CLOSED           = 6, /* close acknowledgement, no payload */
    GTI2_PING             = 7  /* empty ping; its sequence acknowledgement answers it */
};
/* Command ids of the long GT2 messages (gti2HandleLargeMessage).  They are the
 * other encoding of a control message a peer uses for an unreachable socket, and
 * the ones the short enum above cannot express. */
#define GTI2_LARGE_CLOSED 104 /* closed notification a socket sends a peer it has no connection for */
/* Event types a connection reports through GT2_CONNECTION_CALLBACK. */
enum {
    GT2_EVENT_CONNECTED = 0, /* the handshake finished and data can flow */
    GT2_EVENT_CLOSED    = 2, /* the peer closed the connection, its reason follows */
    GT2_EVENT_TIMEOUT   = 6  /* the handshake timed out */
};

/* A GT2 byte buffer: the connection keeps one for received bytes and one for
 * sent bytes.  data holds size bytes, of which len are used. */
#define GT2_CONNECTION_RECV_BUFFER 0x44 /* Gt2Buffer holding received command bytes */
typedef struct Gt2Buffer {
    u8  *data; /* +0x00 bytes */
    s32  size; /* +0x04 capacity in bytes */
    s32  len;  /* +0x08 bytes currently used */
} Gt2Buffer;

/* One entry of GT2_CONNECTION_ACK_QUEUE: where the command's bytes sit in
 * GT2_CONNECTION_SEND_BUFFER, the sequence it was sent with and when it was
 * last sent. */
#define GT2_SENT_COMMAND_SEQUENCE    0x08 /* u16 sequence of a queued sent command */
#define GT2_SENT_COMMAND_LAST_SENT   0x0C /* s32 tick the command was last sent at */
/* A sent command the peer has not acknowledged for this many ms is resent. */
#define GT2_RESEND_TIMEOUT 1000
typedef struct Gt2SentCommand {
    s32 offset;   /* +0x00 offset in GT2_CONNECTION_SEND_BUFFER */
    s32 size;     /* +0x04 byte length */
    u16 sequence; /* +0x08 sequence number */
    u16 pad;      /* +0x0A */
    s32 lastSent; /* +0x0C tick it was last sent at */
} Gt2SentCommand;

/* The four callbacks a connection reports events through, stored as a block at
 * GT2_CONNECTION_CALLBACK (0x28) .. GT2_CONNECTION_CALLBACK_PING (0x34). */
typedef struct GT2ConnectionCallbacks {
    void (*connected)(void *connection, s32 event, s32 data, s32 length); /* +0x00 */
    void (*message)(void *connection, s32 message, s32 length, s32 param); /* +0x04 */
    void (*closed)(void *connection, s32 reason);                          /* +0x08 */
    void (*ping)(void *connection, s32 ping);                              /* +0x0C */
} GT2ConnectionCallbacks;

#endif
