/* Connection to the Nintendo WFC match-making server used by the HTTP client
 * in main_020362D4. The object is 0x48 bytes and is pointed at by field 0x10
 * of the WFC network manager. */
#ifndef WFC_H
#define WFC_H

typedef struct WfcHttpConnection {
    s32 socket;          /* +0x00 socket, -1 until created */
    u8  addrLen;         /* +0x04 socket address length */
    u8  addrFamily;      /* +0x05 AF_INET */
    u16 port;            /* +0x06 port, network byte order */
    u32 addr;            /* +0x08 IPv4 address, network byte order */
    u8  pad0C[8];        /* +0x0C */
    u8  response[0x20];  /* +0x14 response header being read */
    s32 received;        /* +0x34 bytes of the header received so far */
    s32 state;           /* +0x38 connection state, one of WFC_HTTP_* */
    s32 result;          /* +0x3C result/error of the connection */
    u64 deadline;        /* +0x40 time after which the attempt is dropped */
} WfcHttpConnection;     /* 0x48 bytes */

/* WfcHttpConnection::state */
enum {
    WFC_HTTP_IDLE       = 0,
    WFC_HTTP_CONNECTING = 1, /* waiting for the non-blocking connect */
    WFC_HTTP_RECEIVING  = 2, /* reading the response header */
    WFC_HTTP_DONE       = 3  /* finished, result holds the outcome */
};

#define WFC_HTTP_PORT 80 /* the client talks HTTP */

/* Session object (gSession) fields used by the WFC state machine in
 * main_020270B4. The values stored in the state field are the ones passed to
 * WFC_SetState (1..13); 11 is the error state and 13 the finished state. */
#define WFC_SESSION_STATE    0x2260 /* s32 connection state */
#define WFC_SESSION_ABORT    0x226B /* u8 link failed / session has to shut down */
#define WFC_SESSION_REQUEST  0x226C /* u32 queued send request: kind in the low 2 bits, buffer at +0x2270/+0x2274, field at +0x2278, callback at +0x227C */
#define WFC_SESSION_SUBSTATE 0x2280 /* u16 substep reported with the state */

/* The local player's connection data (0xC0 bytes). It is filled from the
 * connection-setup screen, copied into the session when a match is started,
 * reported to the event handlers and sent to the server. Two flag words live
 * inside that record, at +0x2E (source bits) and +0x30 (status bits). */
#define WFC_SESSION_CONN_DATA   0x2140
#define WFC_SESSION_CONN_FLAGS  0x216E /* u16 read when the record is stored */
#define WFC_SESSION_CONN_STATUS 0x2170 /* u16, OR'ed with 3 when stored */

/* Match settings copied from the connection-setup screen: a u8 mode (0..3),
 * a u8 sub-mode (0..3) and a 0x50-byte display name. */
#define WFC_SESSION_MODE     0x2250 /* u8, 0..3 */
#define WFC_SESSION_SUBMODE  0x2251 /* u8, 0..3 */
#define WFC_SESSION_NAME     0x2200 /* 0x50-byte display name */
#define WFC_SESSION_NAME_LEN 0x50

/* The game's own match session object (gWfcMatchSession, 0x1d28 bytes): an HTTP
 * client object in its first WFC_MATCH_HTTP_SIZE bytes, then the match tail filled
 * by CreateWfcMatch and read by ProcessWfcMatchResponse. */
#define WFC_MATCH_HTTP_SIZE    0x1c14 /* size of the embedded HTTP client object */
#define WFC_MATCH_ACTIVE       0x1c14 /* s32 1 while the match request is active */
#define WFC_MATCH_URL          0x1c18 /* char[256] request path built from gNasServer */
#define WFC_MATCH_READY        0x1ba4 /* s32 set once the request has completed */
#define WFC_MATCH_FLAGS        0x1d1c /* u8 * per-player flag output (one byte each) */
#define WFC_MATCH_FLAG_COUNT   0x1d20 /* s32 * count of flagged players output */
#define WFC_MATCH_PLAYER_COUNT 0x1d24 /* s32 number of players the request asked about */

/* Layout of the RFC-1123 Date header the server sends:
 * "Www, DD Mmm YYYY hh:mm:ss GMT" (29 characters, field boundaries below). */
#define HTTP_DATE_DAY_SPACE   7  /* ' ' before the day-of-month */
#define HTTP_DATE_MONTH_SPACE 11 /* ' ' before the month name */
#define HTTP_DATE_YEAR_SPACE  16 /* ' ' before the year */
#define HTTP_DATE_HOUR_COLON  19 /* ':' after the hour */
#define HTTP_DATE_MIN_COLON   22 /* ':' after the minute */
#define HTTP_DATE_TZ_SPACE    25 /* ' ' before the time-zone name */

/* Fields of the server-time sync record (gServerTimeSync). The local and
 * offset fields are 64-bit second counts; they share the record's storage. */
#define SERVER_TIME_VALID  0x00 /* s32 1 once a Date header has been parsed */
#define SERVER_TIME_NOW    0x04 /* s64 local clock when the header arrived */
#define SERVER_TIME_OFFSET 0x0C /* s64 local clock minus server time */

#endif
