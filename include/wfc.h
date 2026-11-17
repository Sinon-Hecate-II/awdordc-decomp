/* Connection to the Nintendo WFC match-making server used by the HTTP client
 * in main_020362D4. The object is 0x48 bytes and is pointed at by field 0x10
 * of the WFC network manager. */
#ifndef WFC_H
#define WFC_H

/* Allocation tags also serve as ownership bits in the WFC allocation state. */
enum {
    WFC_WORK_CONTROL = 1,
    WFC_WORK_SESSION = 2,
    WFC_WORK_AUX = 4,
    WFC_WORK_CALLBACKS = 8,
    WFC_WORK_FRIENDS = 16
};
enum {
    WFC_CONTROL_SIZE = 24,
    WFC_SESSION_SIZE = 8960,
    WFC_AUX_SIZE = 88,
    WFC_CALLBACKS_SIZE = 12,
    WFC_FRIENDS_SIZE = 3352
};
typedef struct WfcAllocationState {
    void *(*allocate)(s32 tag, s32 size);
    void (*freeBlock)(s32 tag, void *block, s32 size);
    u8 ownedMask;
    u8 unk09[15];
} WfcAllocationState;

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

/* WfcHttpConnection::result */
#define WFC_HTTP_RESULT_PENDING 0 /* no outcome yet */
#define WFC_HTTP_RESULT_OK      1 /* the status line answered 200 */
#define WFC_HTTP_RESULT_ERROR   2 /* send failed, bad status line, or timed out */
#define WFC_HTTP_RESULT_CONNECT 3 /* the TCP connect failed */

#define WFC_HTTP_RESPONSE_SIZE 0x20 /* bytes of the status line being read */

/* A WFC profile record handed in a reply: its user id, the game id it belongs
 * to (GPI_PROFILE_GAME_ID, matched against the game's own), and its state. */
#define PROFILE_RECORD_USBID    0x04 /* u8[6] network user id */
#define PROFILE_RECORD_GAME_ID  0x0C /* u8[8] the game this profile plays, "NWCUSBAP" for this one */
#define PROFILE_RECORD_STATE    0x15 /* u8 bit 0: the profile is online */

/* The ov001 (WFC connection) state object behind gOv001ConnectionState, 0x1ba0
 * bytes: the game's connection callback, the request blocks sent to the WFC
 * library, the 16 known player slots and the timers of the nick exchange. */
#define OV001_CONN_CALLBACK      0x1370 /* void (*)(s32 event): the game's connection callback */
#define OV001_CONN_PROFILE       0x1374 /* profile record sent with WFC_SendRequestPacket */
#define OV001_CONN_RESPONSE      0x13B8 /* response block; its +0 state 2 = done */
#define OV001_CONN_SLOTS         0x1300 /* 16 player slots of 7 bytes: u8[6] user id, u8 known */
#define OV001_CONN_SLOT_COUNT    16
#define OV001_CONN_SLOT_STRIDE   7
#define OV001_CONN_SLOT_KNOWN    0x06 /* u8 nonzero once the slot's player is connected */
#define OV001_CONN_GAME_ID       0x1388 /* u8[8] the game id this profile list belongs to */
#define OV001_CONN_USER_COUNT    0x1391 /* u8 number of users in the reply */
#define OV001_CONN_USERS         0x1394 /* u16[?] user ids of the reply */
#define OV001_CONN_START_TICK    0x1B88 /* u64 GetSystemTick() when the connection started */
#define OV001_CONN_TIMER         0x1B90 /* s32 timer id of the nick exchange (Ov001_AddTask) */
#define OV001_CONN_FLAG          0x1B94 /* u8 lobby-quit flag: 0 connected, 1 quitting, 2 quit */
#define OV001_CONN_REQUIRED      0x1B95 /* u8 set when the profile list arrived before the game sent its own profile */
#define OV001_CONN_HAS_PROFILE   0x1B96 /* u8 nonzero once the game sent its own profile to the server */

/* Session object (gWfcSession) fields used by the WFC state machine in
 * main_020270B4. The values stored in the state field are the ones passed to
 * WFC_SetState (1..13); 11 is the error state and 13 the finished state. */
#define WFC_SESSION_STATE    0x2260 /* s32 connection state */
#define WFC_SESSION_STATUS   0x2264 /* u32 status bits, set by WFC_SetStatusBits */
#define WFC_SESSION_ABORT    0x226B /* u8 link failed / session has to shut down */
#define WFC_SESSION_REQUEST  0x226C /* u32 queued send request: kind in the low 2 bits, buffer at +0x2270/+0x2274, field at +0x2278, callback at +0x227C */
#define WFC_SESSION_SUBSTATE 0x2280 /* u16 substep reported with the state */
#define WFC_SESSION_ERROR    0x2282 /* u16 error code of the last link request */
#define WFC_SESSION_TIMER    0x22CC /* timer list the state steps are scheduled through */
#define WFC_SESSION_RESULT   0x22F8 /* u16 result value of the last link request */
#define WFC_SESSION_SEND_BUFFER 0xF00 /* byte buffer the sender fills before sending */

/* The session's player-record list: a header followed by fixed 0xD0-byte nodes
 * in a buffer of capacity bytes (session +0x2270/+0x2274, also addressed as
 * +0x2000+0x270/+0x274). Nodes form a doubly linked list ordered least to most
 * recently updated (WFC_TouchPlayerNode moves a node to the tail); a node's
 * +0x10 holds a 0xC0-byte connection-data record whose first word is the
 * player id, +4 the id the list is searched by. */
#define WFC_PLAYER_LIST_HEADER_SIZE 0xC  /* header bytes before the node array */
#define WFC_PLAYER_LIST_COUNT       0x00 /* s32: number of nodes ever inserted */
#define WFC_PLAYER_LIST_HEAD        0x04 /* oldest node (list head), NULL when empty */
#define WFC_PLAYER_LIST_TAIL        0x08 /* newest node (list tail), NULL when empty */
#define WFC_SESSION_PLAYER_LIST     0x2270 /* void *: player-list buffer (header + nodes) */
#define WFC_SESSION_PLAYER_LIST_CAP 0x2274 /* u32: capacity of that buffer in bytes */
#define WFC_PLAYER_NODE_SIZE        0xD0 /* bytes per player-record node */
#define WFC_PLAYER_NODE_IN_USE      0x00 /* u8: 1 while the slot is taken */
#define WFC_PLAYER_NODE_INDEX       0x04 /* s32: node index, assigned on first insert */
#define WFC_PLAYER_NODE_PREV        0x08 /* older neighbour, NULL at the head */
#define WFC_PLAYER_NODE_NEXT        0x0C /* newer neighbour, NULL at the tail */
#define WFC_PLAYER_NODE_RECORD      0x10 /* 0xC0-byte connection-data record */
#define WFC_PLAYER_RECORD_ID        0x04 /* s32 player id within the record */

/* The outgoing match request descriptor: the buffer the packet is built in and
 * its size come first, then the packet fields the request builder fills. */
#define WFC_SESSION_PACKET        0x2288 /* descriptor base */
#define WFC_SESSION_PACKET_BUFFER WFC_SESSION_PACKET /* void *buffer the packet is built in */
#define WFC_SESSION_PACKET_SIZE   0x228c /* u16 bytes in the buffer */
#define WFC_SESSION_SEND_COUNT    0x2284 /* s32 match requests submitted so far */

/* State of the asynchronous send path (gSendState): the sender holds gSendLock,
 * assembles the packet in the session's buffer, starts the transfer and sleeps
 * on gSendThread until the completion callback stores the result here. */
typedef struct WfcSendState {
    u8  initialized;   /* +0x00 nonzero once the path has been set up */
    u8  pad01[3];
    u32 request;       /* +0x04 */
    u32 flags;         /* +0x08 */
    u8  pad0C[0x18];
    s32 result;        /* +0x24 result of the last send, WFC_SEND_OK when done */
    void (*callback)(void *, void *, void *, u16); /* +0x28 completion hook */
} WfcSendState;

#define WFC_SEND_OK 0 /* WfcSendState::result after a successful send */

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

/* The ov001 Wi-Fi connection state (gOv001ConnectionState, 0x1ba0 bytes, allocated by
 * Ov001_ConnectToWfcServer): the roster of the players seen on the connection, the
 * status callback and the watch timer that reports the final state once. */
#define WFC_CONN_SLOTS        0x1300 /* 16 player slots, WFC_CONN_SLOT_STRIDE bytes each */
#define WFC_CONN_SLOT_COUNT   16     /* slots in WFC_CONN_SLOTS */
#define WFC_CONN_SLOT_STRIDE  7      /* bytes per slot */
#define WFC_CONN_SLOT_ID      0x00   /* 6-byte player id, all zero when the slot is free */
#define WFC_CONN_SLOT_ONLINE  0x06   /* u8 nonzero while the player is online */
#define WFC_CONN_STATUS_CB    0x1370 /* void (*)(s32 status): WFC_CONN_STATUS_* */
#define WFC_CONN_WATCH_START  0x1B88 /* u64 tick the connection watch began at */
#define WFC_CONN_WATCH_TIMER  0x1B90 /* s32 handle of the watch timer, 0 when stopped */
#define WFC_CONN_WATCH_DONE   0x1B96 /* u8 set once the watch has reported the state */
#define WFC_CONN_SLOT_DEFERRED 0x1B95 /* u8 set when a profile-list reply merged a profile before the roster was reported */

/* Status the connection watch reports (WFC_CONN_STATUS_CB argument). */
enum {
    WFC_CONN_STATUS_NONE   = 0, /* no player is on the connection */
    WFC_CONN_STATUS_ONLINE = 1, /* every present player is online */
    WFC_CONN_STATUS_MIXED  = 2  /* some present players are offline */
};

/* The friend roster the ov001 Wi-Fi screens fetch from the WFC server
 * (gWfcFriendRoster, 0x1E60 bytes, allocated by func_ov001_02183f6c): the
 * request packet plus the 20 friend slots the server's answer is parsed into. */
#define WFC_FRIEND_ROSTER_SIZE 0x1E60
#define WFC_FRIEND_SLOTS       0x1300 /* 20 slots, WFC_FRIEND_SLOT_STRIDE bytes each */
#define WFC_FRIEND_SLOT_COUNT  20
#define WFC_FRIEND_SLOT_STRIDE 0x2A

/* One friend slot of the roster; the code is all zero while the slot is free
 * (Ov001_GetFriendSlots counts the slots whose code is set). */
typedef struct WfcFriendSlot {
    u8  info[0x20]; /* +0x00 profile data copied from the server's reply */
    u8  code[6];    /* +0x20 friend code, all zero when the slot is free */
    u16 unk26;      /* +0x26 per-player value from the reply */
    u8  status;     /* +0x28 one of WFC_FRIEND_SLOT_* */
    u8  unk29;      /* +0x29 */
} WfcFriendSlot;    /* 0x2A bytes */

/* WfcFriendSlot::status */
enum {
    WFC_FRIEND_SLOT_EMPTY       = 0, /* no reply data for the slot */
    WFC_FRIEND_SLOT_PRESENT     = 1, /* friend in the roster */
    WFC_FRIEND_SLOT_UNAVAILABLE = 2  /* friend in the roster but cannot be picked */
};

/* State of the friend-list screen (gOv001FriendListState): a state byte and the
 * frame timer of the roster wait, addressed at these offsets. */
#define OV001_FRIEND_LIST_STATE 0x00 /* u8 one of OV001_FRIEND_LIST_* */
#define OV001_FRIEND_LIST_TIMER 0x02 /* u16 frames spent waiting for the roster */

enum {
    OV001_FRIEND_LIST_PENDING   = 0, /* the roster has not been checked yet */
    OV001_FRIEND_LIST_AVAILABLE = 1, /* at least one friend can be picked */
    OV001_FRIEND_LIST_EMPTY     = 2, /* no friend in the roster */
    OV001_FRIEND_LIST_ALL_BUSY  = 3  /* every friend is unavailable */
};

#define OV001_FRIEND_LIST_WAIT 300 /* frames the screen waits for the roster */

/* Message ids Ov001_ShowMessage displays for the friend roster. */
#define OV001_MSG_FRIEND_UNAVAILABLE 14
#define OV001_MSG_NO_FRIENDS         15

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

/* The key record's check word at +8 is the high half of one 64-bit LCG step over
 * a console-entropy seed; StartNasRequest uses the same generator to refresh the
 * login id from the system tick. */
#define NAS_KEY_SEED_MULT 0x5D588B656C078965ULL
#define NAS_KEY_SEED_ADD  0x269EC3
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

/* The NAS connection block (the object gNasConnection holds at field +8,
 * NAS_CONNECTION_SIZE bytes): the NASC HTTP login an online request runs,
 * allocated from the request descriptor's allocator. It
 * carries the outcome, the status block the caller copies out (Nas_GetResult),
 * the request descriptor, the network handle the HTTP runs on and the task that
 * drives it. */
#define NAS_CONNECTION_SIZE  0x13F4
#define NAS_CONN_RESULT      0x1004 /* s32 outcome of the connection attempt */
#define NAS_CONN_STATUS      0x1008 /* s32 head of the status block */
#define NAS_CONN_STATUS_SIZE 0x1C4  /* bytes of the status block shared with the caller */
#define NAS_CONN_REQUEST     0x11CC /* NasRequest descriptor copied from the caller */
#define NAS_CONN_HANDLE      0x1314 /* void *network handle the HTTP runs on */
#define NAS_CONN_TASK        0x1318 /* task that drives the connection */
#define NAS_CONN_MUTEX       0x13D8 /* mutex guarding the connection */

/* Status the connection reports at NAS_CONN_STATUS: 0x4E00 plus the NAS code. */
#define NAS_STATUS_IDLE 0x4E84

/* The request descriptor for a NAS connection (0x48 bytes).
 * StartNasRequest fills it: the UTF-16 request name, a payload name at +0x34
 * and the alloc/free pair at +0x40/+0x44 used to allocate the connection. */
typedef struct NasRequest {
    u8  name[0x32];    /* +0x00 request name, UTF-16, NUL terminated */
    u16 flags;         /* +0x32 */
    u8  payload[0x0C]; /* +0x34 payload name */
    void *alloc;       /* +0x40 allocates the connection block */
    void *free;        /* +0x44 frees it */
} NasRequest;          /* 0x48 bytes */

/* GpiInfoRecord fields used by the NAS login (the record is 0x204 bytes). */
#define GPI_INFO_PROFILE_ID     0x004 /* s32 profile id echo */
#define GPI_INFO_LASTNAME       0x08E /* char[31], also carries the game's id */
#define GPI_INFO_FIELD_LASTNAME 0x705 /* gpiSetInfoString: 0x700 + field 5, \lastname\ */

/* Friend roster kept in the WFC manager state (Wfc_GetWorkBlock(16)): a list of
 * 0x24-byte rows built from the 0xC0-byte friend records, plus the small state
 * used while the player picks one. */
#define WFC_STATE_FLAGS        0xD0C /* u8: low nibble list mode, bits 6..7 friend selection mode */
#define WFC_STATE_SELECT_MODE  0xC0  /* selection-mode bits of WFC_STATE_FLAGS */
#define WFC_STATE_RESULT_ID    0xD0D /* u8 friend id the selection resolves to */
#define WFC_STATE_WORK_INDEX   0xD0F /* u8 record/row the current friend message applies to */
#define WFC_STATE_FRIEND_ID    0xD11 /* s8 friend id being processed, -1 = none */
#define WFC_STATE_ENTRY_COUNT  0xD10 /* u8 number of friend-list rows */
#define WFC_STATE_RECORD_COUNT 0xD12 /* u8 number of friend records in use */
#define WFC_STATE_RECORD_INDEX 0xD13 /* u8 index of the selected friend record */

#define WFC_STATE_ENTRY_CODES  0x40  /* friend-code groups of a record: three 0x20-byte codes */
#define WFC_FRIEND_CODE_GROUPS 3
#define WFC_STATE_MODE_RECORDS 0xE7  /* u8 record layout: 0xFF none, 1 two codes (0x40/0x60), 0 one */

#define WFC_STATE_ENTRIES      0x300 /* friend-list rows, WFC_ENTRY_STRIDE bytes each */
#define WFC_ENTRY_STRIDE       0x24
#define WFC_ENTRY_FLAGS        0x00 /* u8: bits 4..7 mark the rows of a selection */
#define WFC_ENTRY_MARK         0x10 /* mark bit: the high nibble is 1 on a marked row */
#define WFC_ENTRY_ID           0x01 /* u8 friend id returned to the caller */
#define WFC_ENTRY_CODE_LEN     0x03 /* u8 length of the row's code */
#define WFC_ENTRY_CODE         0x04 /* u8[] code bytes */

#define WFC_STATE_CONN_FLAGS   0xD0B /* u8: bits 2-3 connection status, bits 4-5 mode, high nibble attempts */
#define WFC_STATE_FRIEND_MASK  0xD16 /* u16: one bit per friend id taking part in the friend connection */
#define WFC_STATE_CONN_EVENT   0xD14 /* u8 outcome of the friend connection: 1 cancelled, 2/3/4 results */
#define WFC_STATE_CONN_RETRY   0xD15 /* u8 friend-connection attempts made, wraps at 3 */
#define WFC_STATE_LINK_RETURN  0xD0E /* u8 session state to resume after the link step */
#define WFC_STATE_RECORD_RESULT 0x444 /* u8 per friend record, stride 4: the record's connection result */
#define WFC_STATE_RECORD_SCORE  0x446 /* u8 per friend record, stride 4: connection score, higher first */
#define WFC_STATE_RECORD_FLAGS  0x447 /* u8 per friend record, stride 4: bit 7 marks the record as sent */
#define WFC_MIN_CONNECT_SCORE   20    /* lowest record score a friend connection is started for */
#define WFC_STATE_TIMER        0xCB0 /* u64 tick the friend connection started at */
#define WFC_STATE_CMD_BUFFER   0xCB8 /* outgoing command/settings block built by func_020300e8 (0x52 bytes) */

#define WFC_STATE_RECORDS      0x470 /* friend records, WFC_RECORD_STRIDE bytes each */
#define WFC_RECORD_STRIDE      0xC0
#define WFC_RECORD_CODE_LEN    0x0A /* u16 length of the record's code */
#define WFC_RECORD_CODE        0x0C /* u8[] code bytes */
#define WFC_RECORD_COUNT_OFF 0x36 /* u16 entry count sent with the record, minus one in the message */
#define WFC_RECORD_CODE_OFF  0x3C /* u8[] code bytes sent for the record */

#define WFC_CODE_LEN_FRIEND    0x20 /* 32-byte friend code */
#define WFC_CODE_LEN_FREESPOT  0x08 /* 8-byte FREESPOT code */

/* The save-slot images the roster was built from: three 0x100-byte copies of the
 * game's save slots, each holding a 0x20-byte friend code at +0x40 and a second
 * one at +0x60 (friend id = slot, or slot + 3 for the second code). */
#define WFC_STATE_SLOTS        0x000 /* WFC_STATE_SLOT_STRIDE bytes per slot image */
#define WFC_STATE_SLOT_STRIDE  0x100
#define WFC_FRIEND_CODE_IDS    6     /* friend ids: three slots, two codes each */

/* The WFC host configuration (the WFC_WORK_AUX block, WFC_AUX_SIZE bytes): the
 * default template gWfcHostConfigDefaults filled with the player codes of the save
 * slot the selected friend code belongs to, then copied into the shared host record
 * by func_02021a90. */
#define WFC_HOST_CONFIG_NEW    0x0C /* s32 1 when the slot holds no player codes */
#define WFC_HOST_CONFIG_CODE0  0x10 /* s32 first player code */
#define WFC_HOST_CONFIG_MASK   0x14 /* s32 mask of the slot code's set-bit count */
#define WFC_HOST_CONFIG_CODE1  0x18 /* s32 second player code */
#define WFC_HOST_CONFIG_CODE2  0x1C /* s32 third player code */
#define WFC_HOST_CONFIG_CODE3  0x20 /* s32 fourth player code */

/* Session states the friend connection walks through (Wfc_StepSession, main_02030348):
 * after the connect step (2) it asks for the chosen friend's code (3), sends the
 * friend records (4) and the friend-list entries (5), collects each record's
 * result (6) and state 7 hands over to the link step (Wfc_StepLink). */
enum {
    WFC_STEP_FRIEND_CONNECT = 2,
    WFC_STEP_FRIEND_CODE    = 3,
    WFC_STEP_FRIEND_RECORDS = 4,
    WFC_STEP_FRIEND_ENTRIES = 5,
    WFC_STEP_FRIEND_RESULTS = 6,
    WFC_STEP_LINK           = 7,
    WFC_STEP_DONE           = 17 /* the friend connection has finished */
};

#endif
