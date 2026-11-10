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

#endif
