/* GameSpy QR2 (Query & Reporting 2) state record and query buffer, as used by
 * Qr2_SendState in main_0205F83C and the keep-alive code in main_0205E95C.
 * The query is a NUL-ended string plus its length kept after the buffer. */
#ifndef QR2_H
#define QR2_H

#define QR2_QUERY_SIZE   0x800 /* bytes of key/value text in the query buffer */
#define QR2_QUERY_COUNT  0x800 /* s32 length written at the end of the buffer */

/* The final query Qr2_AppendFinalQuery builds for the master starts at a bare '\',
 * lists the three key groups and ends with sQr2FinalQueryTrailer
 * ("final\\queryid\1.1"); its length at QR2_QUERY_COUNT excludes the NUL. */
#define QR2_KEY_MODE_PLAIN    0 /* plain key=value pairs */
#define QR2_KEY_MODE_INDEXED1 1 /* one entry per repeat, callback QR2_CB_APPEND_IDX1 */
#define QR2_KEY_MODE_INDEXED2 2 /* one entry per repeat, callback QR2_CB_APPEND_IDX2 */

/* Replies from the master are received into a 256-byte buffer: at most 255
 * datagram bytes so that the last byte can always be the terminating NUL. */
#define QR2_RECV_MAX     255

/* Layout of a binary QR2 datagram: magic, type, 4-byte request id (the client
 * id for queries, an arbitrary id for replies that comes back echoed), payload.
 * The request id is a different value from the query one in master replies. */
#define QR2_MAGIC_1      0xFE
#define QR2_MAGIC_2      0xFD
#define QR2_HEADER_SIZE  7  /* magic(2) + type(1) + request id(4) */
#define QR2_MAX_PING     32 /* payload bytes of a type 2 ping that are echoed */

/* Packet types.  5 and 7 are the replies to 2 and 6 (the same request id). */
#define QR2_TYPE_QUERY   0  /* a peer's query: player record, answered from ours */
#define QR2_TYPE_STATE   1  /* a peer's state: public address plus state string */
#define QR2_TYPE_PING    2  /* keep-alive, answered as QR2_TYPE_PING_ACK */
#define QR2_TYPE_PING_ACK 5
#define QR2_TYPE_ERROR   4  /* master error: code and message for the error callback */
#define QR2_TYPE_PEER    6  /* message relayed from another player, answered as QR2_TYPE_PEER_ACK */
#define QR2_TYPE_PEER_ACK 7
#define QR2_TYPE_RESERVED1 3 /* not handled */
#define QR2_TYPE_KEEPALIVE 8 /* client -> master keep-alive query: type plus our client id; never answered */
#define QR2_TYPE_RESERVED2 8 /* received type 8 is ignored */

/* Fields of the QR2 connection record. */
#define QR2_SOCKET        0x00  /* s32 UDP socket */
#define QR2_GAMENAME      0x04  /* char[] game name reported to the master */
#define QR2_SECRET_KEY    0x44  /* char[] secret key that ciphers the state string of a state reply */
#define QR2_STATE_STRING_MAX 65 /* longest incoming state string, its terminating NUL included */
#define QR2_LOCAL_IP      0x84  /* u8[4] random client id seeded at creation, echoed back by the master */
#define QR2_CB_PUBLIC_ADDRESS 0xA8 /* void (*)(u32 ip, u16 port, void *ctx): set to be told the public address the master sees (also makes the state report carry it) */
#define QR2_LAST_SENT     0xAC  /* s32 tick of the last state query */
#define QR2_LAST_POLL     0xB0  /* s32 tick of the last keep-alive */
#define QR2_STATE_DIRTY   0xB4  /* s32 state changed since the last update */
#define QR2_ERROR_REPORTED 0xB8 /* s32: 1 at creation, 0 once any packet has arrived, -1 once the master reported an error */
#define QR2_REPORT_TO_MASTER 0xBC /* s32: 1 while this connection reports its state to the master (the reportToMaster argument of Qr2_CreateConnection) */
#define QR2_LOCAL_PORT    0xC0  /* s32 local port */
#define QR2_RECV_BUFFER   0xC4  /* void *: receive buffer released on teardown; replies are only drained while it is set */
#define QR2_NATNEG        0xC8  /* s32 NAT negotiation enabled */
#define QR2_REQUEST_ID    0xCC  /* 8-byte socket address of the master server: the destination of every query (and the buffer the resolve fills in) */
#define QR2_CB_ASCII      0xD4  /* void (*)(const char *text, s32 length, void *address): ';' console line from the master */
#define QR2_RECENT_IDS    0xD8  /* s32[10] request ids handled recently (a ring for dropping repeats) */
#define QR2_RECENT_ID_COUNT 10  /* entries in QR2_RECENT_IDS */
#define QR2_RECENT_INDEX  0x100 /* s32 next slot in QR2_RECENT_IDS */
#define QR2_PUBLIC_IP     0x104 /* s32 public IPv4 address */
#define QR2_PUBLIC_PORT   0x108 /* u16 public port */

/* The state value that only terminates the query (no trailing keep-alive). */
#define QR2_STATE_FINAL   2
/* State value sent when the connection's state changed. */
#define QR2_STATE_CHANGED 1
/* Shortest gap between two state reports: a change inside it is only marked
 * dirty and sent with the next report. */
#define QR2_STATE_MIN_INTERVAL_MS 10000

/* Callbacks of the QR2 connection record, called with the record's context. */
#define QR2_CB_APPEND_KEY    0x88 /* void (*)(s32 key, void *query, void *ctx) */
#define QR2_CB_APPEND_IDX1   0x8C /* void (*)(s32 key, s32 index, void *query, void *ctx) */
#define QR2_CB_APPEND_IDX2   0x90 /* void (*)(s32 key, s32 index, void *query, void *ctx) */
#define QR2_CB_COLLECT_KEYS  0x94 /* void (*)(s32 mode, u8 *keyList, void *ctx) */
#define QR2_CB_REPEAT_COUNT  0x98 /* s32 (*)(s32 mode, void *ctx) */
#define QR2_CB_REPORT_ERROR  0x9C /* void (*)(s32 error, const char *message, void *ctx): the master reported an error */
#define QR2_CB_STATE_CHANGED 0xA0 /* void (*)(s32 target, void *ctx): the peer to connect to is now `target` (an IPv4 address in host order) */
#define QR2_CB_RECEIVE_STATE 0xA4 /* void (*)(const void *packet, s32 bytes, void *ctx): a raw message from another player */
#define QR2_CTX              0x10C /* void *context passed to every callback */

/* A query collects at most this many key ids before appending them. */
#define QR2_KEY_LIST_SIZE 256
#define QR2_KEY_LIST_COUNT 0x100 /* s32 number of key ids the callback appended */

/* A field-list length byte of 0xFF means "every key of the group": the list
 * itself is left out and the record's key callback supplies the ids.  0 means
 * the group has no fields at all. */
#define QR2_FIELDS_ALL    0xFF

/* Game-key ids answered by Qr2AppendGameKey.  Keys 8..52 report one connection
 * field each (the CONN_SESSION_* offsets in common.h); 53/54 report constants;
 * keys QR2_GAMEKEY_TABLE_BASE..QR2_GAMEKEY_TABLE_END-1 index the session player
 * table below. */
#define QR2_GAMEKEY_CONN_14    8   /* u8  connection +0x14 */
#define QR2_GAMEKEY_CONN_16    10  /* u8  connection +0x16 */
#define QR2_GAMEKEY_QR2_PARAM  50  /* s32 CONN_SESSION_QR2_PARAM */
#define QR2_GAMEKEY_MODE       51  /* u8  CONN_SESSION_MODE */
#define QR2_GAMEKEY_MATCH_ADDR 52  /* s32 CONN_SESSION_MATCH_ADDRESS */
#define QR2_GAMEKEY_CONST_3    53  /* the constant 3 */
#define QR2_GAMEKEY_CONST_1    54  /* the constant 1 */
#define QR2_GAMEKEY_TABLE_BASE 100 /* first session player key */
#define QR2_GAMEKEY_TABLE_END  254 /* one past the last session player key */

/* The session player table (gSessionPlayers, plus the per-field symbols the
 * decompiler split out of it): QR2_PLAYER_COUNT records of QR2_PLAYER_STRIDE
 * bytes, keyed by the game-key ids above. */
#define QR2_PLAYER_STRIDE    0x0C
#define QR2_PLAYER_COUNT     154
#define QR2_PLAYER_KEY       0x00 /* u8 key id (100..253), 0 = free */
#define QR2_PLAYER_IS_STRING 0x01 /* u8 nonzero when the value is a string */
#define QR2_PLAYER_FIELD_02  0x02 /* u16 */
#define QR2_PLAYER_STRING    0x04 /* char *heap string for the key */
#define QR2_PLAYER_VALUE     0x08 /* s32 value, or a pointer to one */

/* The GameSpy stream cipher's state, 261 bytes: a 256-byte permutation followed by
 * the five step bytes that index it.  Set up once per connection and advanced one
 * byte at a time; the same step both encrypts and decrypts (an XOR keystream). */
typedef struct GsCryptState {
    u8 sbox[256]; /* +0x00 permutation, four entries shuffled by every step */
    u8 a;         /* +0x100 counter, incremented every step */
    u8 b;         /* +0x101 index accumulated from sbox[old a] */
    u8 c;         /* +0x102 index accumulated from sbox[swapped entry] */
    u8 d;         /* +0x103 cipher byte the previous step returned */
    u8 e;         /* +0x104 data byte the previous step was given */
} GsCryptState;   /* 0x105 bytes */

/* Binary matchmaking commands received through the QR2 callback. */
typedef struct Qr2MatchCommandHeader {
    char magic[4];    /* +0x00 "SBCM" */
    u32 version;      /* +0x04 protocol version 3 */
    u8 command;       /* +0x08 command handled by HandleConnectionCommand */
    u8 payloadBytes;  /* +0x09 size of the following u32 values */
    u16 port;         /* +0x0A sender's port */
    u32 address;      /* +0x0C sender's IPv4 address */
    u32 profileId;    /* +0x10 sender's profile id */
} Qr2MatchCommandHeader;
#define QR2_MATCH_HEADER_SIZE 20
#define QR2_MATCH_VERSION 3
#define QR2_MATCH_PAYLOAD_MAX 128

#endif
