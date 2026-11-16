#ifndef GT2_H
#define GT2_H

/* Fields of the GameSpy GT2 connection and its owning socket. */
#define GT2_CONNECTION_IP          0x00 /* s32 remote IPv4 address */
#define GT2_CONNECTION_PORT        0x04 /* u16 remote port */
#define GT2_CONNECTION_SOCKET      0x08 /* void *owning socket */
#define GT2_CONNECTION_STATE       0x0C /* s32 handshake/connection state */
#define GT2_CONNECTION_RESPONSE    0x68 /* 32-byte expected challenge response */
#define GT2_CONNECTION_START_TIME  0x8C /* s32 connection start time in milliseconds */
/* The connection's callback for the current event (0x28, or 0x2C with a message
 * pointer) and the two counters that nest around calling it: one on the
 * connection (+0x24) and one on its socket (+0x1C), so the socket can be
 * destroyed once the outermost callback returns. */
#define GT2_CONNECTION_CALLBACK    0x28 /* void (*)(connection, event type, data, length) */
#define GT2_CONNECTION_CALLBACK_MSG 0x2C /* void (*)(connection, message, length, unk) */
#define GT2_CONNECTION_CALLBACKS   0x24 /* s32 connection callbacks running */
#define GT2_SOCKET_CALLBACKS       0x1C /* s32 callbacks running on the socket */
#define GT2_SOCKET_DIRTY           0x14 /* s32 set when the socket was asked to be freed */
#define GT2_SOCKET_CONNECT_ATTEMPT 0x20 /* callback for incoming connections */
enum {
    GT2_STATE_AWAIT_CLIENT_RESPONSE = 3,
    GT2_STATE_AWAIT_ACCEPT = 4,
    GT2_RESPONSE_SIZE = 32
};
#endif
