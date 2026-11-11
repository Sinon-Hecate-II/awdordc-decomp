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

/* NAS (Nintendo Authentication Server) login, driven by gNasLogin.  The global
 * holds the pending request's kind, the current context and the completion
 * callback; the context's state walks the NAS_STATE_* values below. */
#define NAS_LOGIN_REQUEST_KIND 0x00 /* s32 kind handed to the completion callback */
#define NAS_LOGIN_CONTEXT      0x04 /* void *current 0x280-byte login context */
#define NAS_LOGIN_DONE_CB      0x08 /* void (*)(char *name, char *pass, s32 kind) */

/* Fields of the login context (NAS_LOGIN_CONTEXT). */
#define NAS_LOGIN_STATE          0x04 /* s32 state, one of NAS_STATE_* */
#define NAS_LOGIN_KEY_TYPE       0x0C /* s32 key passed to FormatNasId */
#define NAS_LOGIN_SESSION        0x1C /* void *local session/profile record */
#define NAS_LOGIN_KEY            0x3C /* 12-byte profile key record */
#define NAS_LOGIN_CONNECT_RESULT 0x260 /* connection result record */

/* Login context state (NAS_LOGIN_STATE). */
enum {
    NAS_STATE_IDLE           = 0, /* no login in progress */
    NAS_STATE_REQUESTING     = 1, /* NAS request sent, waiting for the reply */
    NAS_STATE_CONNECTED      = 2, /* gpi connection established */
    NAS_STATE_GET_PROFILE    = 3, /* profile info requested from the server */
    NAS_STATE_VERIFY_PROFILE = 4, /* profile info returned, verify the stored id */
    NAS_STATE_DONE           = 5  /* logged in */
};

/* GpiInfoRecord fields used by the NAS login (the record is 0x204 bytes). */
#define GPI_INFO_PROFILE_ID     0x004 /* s32 profile id echo */
#define GPI_INFO_LASTNAME       0x08E /* char[31], also carries the game's id */
#define GPI_INFO_FIELD_LASTNAME 0x705 /* gpiSetInfoString: 0x700 + field 5, \lastname\ */

/* Friend roster kept in the WFC manager state (func_0202f48c(16)): a list of
 * 0x24-byte rows built from the 0xC0-byte friend records, plus the small state
 * used while the player picks one. */
#define WFC_STATE_FLAGS        0xD0C /* u8: low nibble list mode, bits 6..7 friend selection mode */
#define WFC_STATE_SELECT_MODE  0xC0  /* selection-mode bits of WFC_STATE_FLAGS */
#define WFC_STATE_RESULT_ID    0xD0D /* u8 friend id the selection resolves to */
#define WFC_STATE_ENTRY_COUNT  0xD10 /* u8 number of friend-list rows */
#define WFC_STATE_RECORD_INDEX 0xD13 /* u8 index of the selected friend record */

#define WFC_STATE_ENTRIES      0x300 /* friend-list rows, WFC_ENTRY_STRIDE bytes each */
#define WFC_ENTRY_STRIDE       0x24
#define WFC_ENTRY_FLAGS        0x00 /* u8: bits 4..7 mark the rows of a selection */
#define WFC_ENTRY_MARK         0x10 /* mark bit: the high nibble is 1 on a marked row */
#define WFC_ENTRY_ID           0x01 /* u8 friend id returned to the caller */
#define WFC_ENTRY_CODE_LEN     0x03 /* u8 length of the row's code */
#define WFC_ENTRY_CODE         0x04 /* u8[] code bytes */

#define WFC_STATE_RECORDS      0x470 /* friend records, WFC_RECORD_STRIDE bytes each */
#define WFC_RECORD_STRIDE      0xC0
#define WFC_RECORD_CODE_LEN    0x0A /* u16 length of the record's code */
#define WFC_RECORD_CODE        0x0C /* u8[] code bytes */

#define WFC_CODE_LEN_FRIEND    0x20 /* 32-byte friend code */
#define WFC_CODE_LEN_FREESPOT  0x08 /* 8-byte FREESPOT code */

#endif
