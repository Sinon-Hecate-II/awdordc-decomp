/* GameSpy QR2 (Query & Reporting 2) state record and query buffer, as used by
 * Qr2_SendState in main_0205F83C and the keep-alive code in main_0205E95C.
 * The query is a NUL-ended string plus its length kept after the buffer. */
#ifndef QR2_H
#define QR2_H

#define QR2_QUERY_SIZE   0x800 /* bytes of key/value text in the query buffer */
#define QR2_QUERY_COUNT  0x800 /* s32 length written at the end of the buffer */

/* Fields of the QR2 connection record. */
#define QR2_SOCKET        0x00  /* s32 UDP socket */
#define QR2_GAMENAME      0x04  /* char[] game name reported to the master */
#define QR2_LOCAL_IP      0x84  /* u8[4] local IPv4 address */
#define QR2_PUBLIC_VALID  0xA8  /* s32 public address/port are known */
#define QR2_LAST_SENT     0xAC  /* s32 tick of the last state query */
#define QR2_LAST_POLL     0xB0  /* s32 tick of the last keep-alive */
#define QR2_STATE_DIRTY   0xB4  /* s32 state changed since the last update */
#define QR2_LOCAL_PORT    0xC0  /* s32 local port */
#define QR2_NATNEG        0xC8  /* s32 NAT negotiation enabled */
#define QR2_REQUEST_ID    0xCC  /* u8[8] request id */
#define QR2_PUBLIC_IP     0x104 /* s32 public IPv4 address */
#define QR2_PUBLIC_PORT   0x108 /* u16 public port */

/* The state value that only terminates the query (no trailing keep-alive). */
#define QR2_STATE_FINAL   2

/* Callbacks of the QR2 connection record, called with the record's context. */
#define QR2_CB_APPEND_KEY    0x88 /* void (*)(s32 key, void *query, void *ctx) */
#define QR2_CB_APPEND_IDX1   0x8C /* void (*)(s32 key, s32 index, void *query, void *ctx) */
#define QR2_CB_APPEND_IDX2   0x90 /* void (*)(s32 key, s32 index, void *query, void *ctx) */
#define QR2_CB_COLLECT_KEYS  0x94 /* void (*)(s32 mode, u8 *keyList, void *ctx) */
#define QR2_CB_REPEAT_COUNT  0x98 /* s32 (*)(s32 mode, void *ctx) */
#define QR2_CTX              0x10C /* void *context passed to every callback */

/* A query collects at most this many key ids before appending them. */
#define QR2_KEY_LIST_SIZE 256

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

#endif
