#ifndef GT2_H
#define GT2_H

/* Fields of the GameSpy GT2 connection and its owning socket. */
#define GT2_CONNECTION_IP          0x00 /* s32 remote IPv4 address */
#define GT2_CONNECTION_PORT        0x04 /* u16 remote port */
#define GT2_CONNECTION_SOCKET      0x08 /* void *owning socket */
#define GT2_CONNECTION_SEND_BUFFER 0x50 /* u8 *ring buffer keeping sent command bytes until the peer acknowledges them */
#define GT2_CONNECTION_ACK_QUEUE   0x60 /* Vector *of sent commands awaiting the peer's acknowledgement, sorted by sequence */
#define GT2_CONNECTION_STATE       0x0C /* s32 handshake/connection state */
#define GT2_CONNECTION_RESPONSE    0x68 /* 32-byte expected challenge response */
#define GT2_CONNECTION_SEND_SEQUENCE 0x64 /* u16 sequence number the next sent command carries */
#define GT2_CONNECTION_START_TIME  0x8C /* s32 connection start time in milliseconds */
#define GT2_CONNECTION_DATA        0x38 /* void *data to send with our handshake message */
#define GT2_CONNECTION_DATA_LEN    0x3C /* s32 length of GT2_CONNECTION_DATA */
#define GT2_CONNECTION_MESSAGE_CALLBACKS 0x98 /* Vector of per-message callbacks (func_0205a424) */
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
enum {
    GT2_STATE_AWAIT_CONNECT_ACCEPT = 0, /* client sent its challenge, waiting for CONNECT_ACCEPT */
    GT2_STATE_AWAIT_SERVER_ACCEPT = 1,  /* client sent its response, waiting for ACCEPT */
    GT2_STATE_AWAIT_CLIENT_RESPONSE = 3,
    GT2_STATE_AWAIT_ACCEPT = 4,
    GT2_STATE_CONNECTED = 5,            /* both sides accepted the handshake; data flows */
    GT2_STATE_PEER_CLOSED = 6,          /* the peer's closed command arrived, waiting for our side to finish */
    GT2_STATE_CLOSED = 7,               /* connection torn down */
    GT2_RESPONSE_SIZE = 32,
    GT2_CONNECT_ACCEPT_SIZE = 64        /* challenge response + the server's challenge */
};
/* A GT2 byte buffer: the connection keeps one for received bytes and one for
 * sent bytes.  data holds size bytes, of which pos are used. */
#define GT2_CONNECTION_RECV_BUFFER 0x44 /* Gt2Buffer holding received command bytes */
typedef struct Gt2Buffer {
    u8  *data; /* +0x00 bytes */
    s32  size; /* +0x04 capacity in bytes */
    s32  pos;  /* +0x08 bytes currently used */
} Gt2Buffer;

/* One entry of GT2_CONNECTION_ACK_QUEUE: where the command's bytes sit in
 * GT2_CONNECTION_SEND_BUFFER, the sequence it was sent with and when it was
 * last sent. */
#define GT2_SENT_COMMAND_SEQUENCE 0x08 /* u16 sequence of a queued sent command */
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
