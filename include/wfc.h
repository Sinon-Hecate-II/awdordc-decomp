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

/* The local WFC profile GetWfcProfile unpacks from the packed 14-byte blob
 * gWfcProfileCode (the firmware's Wi-Fi user info for this game) into the
 * 20-byte record the game passes around.  GetWfcProfileIds copies its two ids
 * and reports a nonzero friend code as the record's flag word. */
#define WFC_PROFILE_FRIEND_CODE 0x00 /* u64: the console's 12-digit friend code, 0 when no profile exists */
#define WFC_PROFILE_CODE        0x08 /* u64: the profile code BuildWfcProfile generates from the seed */
#define WFC_PROFILE_ID          0x10 /* u16: profile id, 0..999 */
#define WFC_PROFILE_SEED        0x12 /* u16: seed the profile code was generated from */
#define WFC_PROFILE_SIZE        0x14 /* bytes of the unpacked record */
#define WFC_PROFILE_ID_BITS     43   /* both ids are 43 bits wide in the packed blob */
#define WFC_PROFILE_ID_MASK     0x7ffffffffffULL /* the bits of an id the blob keeps */
#define WFC_PROFILE_CODE_SHIFT  3    /* the profile code starts 3 bits into its 6-byte window */
#define WFC_PROFILE_ID_SHIFT    6    /* the id starts 6 bits into its 2-byte window */
#define WFC_PROFILE_ID10_MASK   0x3ff /* ten bits of id */

/* The packed blob is cut into symbols at its five-byte boundary: gWfcProfileCode
 * holds its first five bytes, data_0213db39 the sixth, data_0213db3a the seventh
 * to tenth, data_0213db3e the tenth and eleventh, and data_0213db40 its last two
 * (the seed). */

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

/* The reply packet a WFC_SendRequestPacket callback receives, addressed as u16
 * words: the command of the request it answers, its result and the request's
 * operation word. */
#define WFC_REPLY_COMMAND 0 /* u16: WFC_REQUEST_COMMAND for a request reply, WFC_CMD_SHUTDOWN for a link teardown event */
#define WFC_REPLY_RESULT  1 /* u16: nonzero when the request failed */
#define WFC_REPLY_OP      4 /* u16: WFC_REQUEST_OP_* operation the server answered */

#define WFC_REQUEST_COMMAND 0x26 /* command id of the request packet WFC_SendRequestPacket sends */

/* WFC_REPLY_OP values the ov001 lobby expects. */
#define WFC_REQUEST_OP_NEXT         4 /* the request was accepted: send the next one */
#define WFC_REQUEST_OP_PROFILE_LIST 5 /* the server's profile list: build or merge the player roster, then poll again */

/* The WFC connection object (gWfcConnection, 12 bytes): the WFC library's step
 * handle and the state machine main_02037214 drives it through. */
#define WFC_CONN_STEP       0x00 /* s32 Wfc_ProcessStep handle, 0 before the first step */
#define WFC_CONN_STATE      0x04 /* u16 one of WFC_CONN_* */
#define WFC_CONN_LINK_READY 0x06 /* u16 set when the link came up, cleared once settled */
#define WFC_CONN_MODE       0x08 /* u16 mode handed to WFC_Init */
#define WFC_CONN_SUBMODE    0x0A /* u16 sub-mode handed to WFC_Init */

/* WFC_CONN_STATE values; GetNetConnectionStatus updates the field each poll. */
enum {
    WFC_CONN_IDLE      = 1, /* created; WFC_Init has not run yet */
    WFC_CONN_RUNNING   = 2, /* WFC_Init done; Wfc_ProcessStep drives the session */
    WFC_CONN_CONNECTED = 4, /* the session reports the link up */
    WFC_CONN_READY     = 6, /* the link settled: the game may use the connection */
    WFC_CONN_FAILED    = 7, /* WFC error, reported as network error 5 */
    WFC_CONN_FATAL     = 8  /* fatal WFC error, reported as network error 9 */
};

/* Parameters handed to WFC_Init (12 bytes): the work-block allocator callbacks
 * the library keeps for the session, then the connection settings. The ov001
 * setup keeps a filled-in template of this block in its read-only data and only
 * patches the player count. */
typedef struct WfcInitParams {
    void *(*allocate)(s32 tag, s32 size);              /* +0x00 work-block allocator */
    void (*freeBlock)(s32 tag, void *block, s32 size); /* +0x04 work-block deallocator */
    u8 mode;        /* +0x08 WFC_CONN_MODE, 0..3 */
    u8 submode;     /* +0x09 WFC_CONN_SUBMODE, 0..3 */
    u8 playerCount; /* +0x0A number of players, 1..4 */
    u8 unk0B;       /* +0x0B 2 bits in the WFC configuration, 0 here */
} WfcInitParams; /* 12 bytes */

/* Session object (gWfcSession) fields used by the WFC state machine in
 * main_020270B4. The values stored in the state field are the ones passed to
 * WFC_SetState (1..13); 11 is the error state and 13 the finished state. */
#define WFC_SESSION_STATE    0x2260 /* s32 connection state, one of WFC_SESSION_STATE_* */

/* Values WFC_SetState stores in WFC_SESSION_STATE (it accepts 1..13; 11 is the
 * error state and 13 the finished state - no later state is stored after them). */
enum {
    WFC_SESSION_STATE_NONE       = 0,  /* no session: what Wfc_GetLinkState reports when gWfcSession is NULL */
    WFC_SESSION_STATE_STARTED    = 1,  /* session allocated, not connected yet */
WFC_SESSION_STATE_WIRELESS   = 4,  /* the wireless start command was queued and is running */
    WFC_SESSION_STATE_READY      = 3,  /* connected and idle: the next connection may start */
    WFC_SESSION_STATE_CONNECTING = 6,  /* a match was found and the connection is opening */
    WFC_SESSION_STATE_LINKING    = 9,  /* waiting for the link to the other player */
    WFC_SESSION_STATE_ERROR      = 11, /* the connection failed; final */
    WFC_SESSION_STATE_LINKED     = 12, /* the link is up and its first packets are exchanged */
    WFC_SESSION_STATE_DONE       = 13  /* the link is complete; final */
};
#define WFC_SESSION_STATUS   0x2264 /* u32 status bits, set by WFC_SetStatusBits */
/* A match tracks WFC_PLAYER_SLOT_COUNT player slots in bits 1..13 of
 * WFC_SESSION_STATUS: slot n owns bit n, and a set bit means the slot is taken. */
#define WFC_PLAYER_SLOT_COUNT 13
#define WFC_SESSION_DATA_LOCK 0x226A /* u8 nonzero while incoming player records are discarded */
#define WFC_SESSION_ABORT    0x226B /* u8 link failed / session has to shut down */
#define WFC_SESSION_REQUEST  0x226C /* u32 queued send request: kind in the low 2 bits, buffer at +0x2270/+0x2274, field at +0x2278, callback at +0x227C */
#define WFC_SESSION_SUBSTATE 0x2280 /* u16 substep reported with the state */
#define WFC_SESSION_ERROR    0x2282 /* u16 error code of the last link request */
#define WFC_SESSION_TIMER    0x22CC /* timer list the state steps are scheduled through */
#define WFC_STATE_TIMER_PERIOD 0x22f5341 /* system ticks between runs of the state-9 timer */
#define WFC_SESSION_RESULT   0x22F8 /* u16 result value of the last link request */
#define WFC_SESSION_SEND_BUFFER 0xF00 /* byte buffer the sender fills before sending */

/* The session's player-record list: a header followed by fixed 0xD0-byte nodes
 * in a buffer of capacity bytes (session +0x2270/+0x2274, also addressed as
 * +0x2000+0x270/+0x274). Nodes form a doubly linked list ordered least to most
 * recently updated (WFC_TouchPlayerNode moves a node to the tail); a node's
 * +0x10 holds a 0xC0-byte connection-data record whose first word is the
 * player id, +4 the id the list is searched by. */
#define WFC_PLAYER_LIST_HEADER_SIZE 0xC  /* header bytes before the node array */
#define WFC_SESSION_PLAYER_BLOCK 0x2000 /* the WFC code addresses the list buffer from session + 0x2000 */
#define WFC_PLAYER_LIST_BLOCK_OFFSET (WFC_SESSION_PLAYER_LIST - WFC_SESSION_PLAYER_BLOCK)     /* 0x270: void *list buffer */
#define WFC_PLAYER_LIST_CAP_OFFSET   (WFC_SESSION_PLAYER_LIST_CAP - WFC_SESSION_PLAYER_BLOCK) /* 0x274: u32 capacity */
#define WFC_PLAYER_LIST_COUNT       0x00 /* s32: number of nodes ever inserted */
#define WFC_PLAYER_LIST_HEAD        0x04 /* oldest node (list head), NULL when empty */
#define WFC_PLAYER_LIST_TAIL        0x08 /* newest node (list tail), NULL when empty */
#define WFC_SESSION_PLAYER_LIST     0x2270 /* void *: player-list buffer (header + nodes) */
#define WFC_SESSION_PLAYER_LIST_CAP 0x2274 /* u32: capacity of that buffer in bytes */
#define WFC_PLAYER_NODE_SIZE        0xD0 /* bytes per player-record node */
#define WFC_PLAYER_NODE_IN_USE      0x00 /* u8: 1 while the slot is taken */
#define WFC_PLAYER_NODE_SLOT        0x02 /* u16: WFC player slot the record belongs to */
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

/* The WFC command channel to the ARM7 firmware (main_02010C14): the library
 * keeps WFC_CMD_BLOCK_COUNT 0x100-byte command blocks in gWfcFreeBufferQueue,
 * the queue of blocks the firmware is not using. WFC_SendCommand takes a block
 * from it, writes the command id and its arguments into it and sends the
 * block's address over the command FIFO; the firmware sets the block's free bit
 * again when it is done with it, and WFC_AllocBuffer only hands out blocks whose
 * bit is set (a busy block goes back to the queue). */
#define WFC_CMD_FIFO_TAG    10     /* IPC FIFO tag of the command channel */
#define WFC_CMD_BLOCK_SIZE  0x100  /* bytes per command block */
#define WFC_CMD_BLOCK_COUNT 10     /* blocks in the channel's ring */
#define WFC_CMD_BLOCK_FREE  0x8000 /* bit 15 of a block's first u16: the firmware is done with it */

/* Results of the command API; a caller retries when it gets NO_BUFFER. */
#define WFC_CMD_OK         2 /* the command was posted, its completion arrives as an event */
#define WFC_CMD_NO_BUFFER  8 /* no free block, or the FIFO refused the message */

/* The WFC command channel's global state (gWfcChannelState).  The ARM9 allocates
 * one work area, splits it into buffers and keeps their pointers in the info block
 * the state points at (+WFC_CMD_STATE_INFO).  The firmware writes command packets
 * into the packet buffer and the connection data into the data block; the FIFO
 * handler reads them and dispatches to the callbacks. */
#define WFC_CMD_STATE_READY  0x00 /* u16 1 once the channel is initialized */
#define WFC_CMD_STATE_INFO   0x04 /* void *the info block below */
#define WFC_CMD_STATE_EVENT  0x50 /* the event packet (WFC_EVENT_*), 0x44 bytes */

/* Fields of the info block (WFC_CMD_STATE_INFO). */
#define WFC_CMD_INFO_BUFFER0 0x00  /* void *first buffer of the work area */
#define WFC_CMD_INFO_DATA    0x04  /* void *0x800-byte connection-data block the firmware fills */
#define WFC_CMD_INFO_LINK_STATE 0x00 /* u16 link state at the start of that block (WFC_LINK_STATE) */
#define WFC_CMD_INFO_BUFFER1 0x0c  /* void *0x100-byte buffer */
#define WFC_CMD_INFO_PACKET  0x10  /* void *0x100-byte command packet the firmware wrote */
#define WFC_CMD_INFO_MODE    0x14  /* u16 mode of the channel */
#define WFC_CMD_INFO_DATA_CACHED 0x16 /* u16 nonzero once the data block has been read */
#define WFC_CMD_INFO_CALLBACK 0xc8 /* void (*)(void *): general event callback */
#define WFC_CMD_INFO_CHANNELS 0xcc /* void (*[16])(void *): per-channel callbacks */
#define WFC_CMD_INFO_VALUES  0x10c /* s32[16]: per-channel argument values */
#define WFC_CMD_INFO_AID_MASK 0x14c /* u32 bitmask of the connected players' aids */
#define WFC_CMD_INFO_LOCAL_AID 0x150 /* u16 the local player's aid */

/* Fields of the event packet (WFC_CMD_STATE_EVENT) that the command handler fills
 * before it hands the packet to the callbacks. */
#define WFC_EVENT_COMMAND   0x00 /* u16 command id (WFC_CMD_CHANNEL_EVENT) */
#define WFC_EVENT_INDEX     0x02 /* u16 */
#define WFC_EVENT_KIND      0x04 /* u16 event kind */
#define WFC_EVENT_CHANNEL   0x06 /* u16 channel the event belongs to */
#define WFC_EVENT_RESERVED08 0x08 /* u32 zeroed */
#define WFC_EVENT_RESERVED0C 0x0c /* u32 zeroed */
#define WFC_EVENT_RESERVED10 0x10 /* u16 zeroed */
#define WFC_EVENT_AID       0x12 /* u16 the affected player's aid */
#define WFC_EVENT_MAC       0x14 /* u8[6] the peer's MAC address */
#define WFC_EVENT_SENTINEL  0x1a /* u16 0xffff */
#define WFC_EVENT_VALUE     0x1c /* u32 per-channel argument value */
#define WFC_EVENT_LOCAL_AID 0x20 /* u16 the local player's aid */
#define WFC_EVENT_AID_MASK  0x22 /* u16 bitmask of the connected players' aids */
#define WFC_EVENT_PAYLOAD   0x24 /* u8[0x18] event payload the handler copies or zero-fills */
#define WFC_EVENT_PAYLOAD_SIZE 0x18
#define WFC_EVENT_REASON    0x3c /* u16 reason reported with the event */
#define WFC_EVENT_FIRST     0x40 /* u16 first value of the peer/local aid pair */
#define WFC_EVENT_SECOND    0x42 /* u16 second value of the pair */

/* Command ids the WFC command channel carries in the packet's first u16.  Ids at
 * or above WFC_CMD_EVENT_BASE are asynchronous events, the lower ones report the
 * completion of a posted command. */
#define WFC_CMD_EVENT_BASE   0x2c
#define WFC_CMD_SHUTDOWN     2    /* the channel is being shut down */
#define WFC_CMD_PEER_STATUS  8    /* a peer's connection status (mac +0xa, aid +0x10, reason +0x12, payload +0x14) */
#define WFC_CMD_SELF_STATUS  0xc  /* the local connection status (aid +0xa, reason +0xc, mac +0x10) */
#define WFC_CMD_LINK_STATUS  0xe  /* link-status notification */
#define WFC_CMD_GENERAL_EVENT 0x80 /* asynchronous event for the general callback (reason +2, 0x13 halts) */
#define WFC_CMD_COMMAND_REPLY 0x81 /* reply to a posted command: becomes 0xf and runs the callback at +0x1c */
#define WFC_CMD_CHANNEL_EVENT 0x82 /* per-channel event: runs the channel's callback after filling the packet */

/* Event kinds carried in WFC_EVENT_KIND. */
#define WFC_EVENT_JOINED 7    /* a player joined: set its aid bit in WFC_CMD_INFO_AID_MASK */
#define WFC_EVENT_LEFT   9    /* a player left: clear its aid bit */
#define WFC_EVENT_OTHER  0x1a /* another roster change the handler reports as-is */

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
#define WFC_FRIEND_SLOTS_SIZE  0x348  /* bytes of the whole slot area */
#define WFC_FRIEND_SLOT_COUNT  20
#define WFC_FRIEND_SLOT_STRIDE 0x2A
#define WFC_FRIEND_REQUEST     0x1648 /* request packet handed to WFC_SendRequestPacket */
#define WFC_FRIEND_REPLY       0x168C /* reply block the channel data is copied into; its +0 u16 state */
#define WFC_FRIEND_CLOSING     0x1E5C /* u8 set when the roster stops taking replies (link ending) */
#define WFC_REPLY_DONE         2      /* WFC_FRIEND_REPLY state once the reply has arrived */

/* The friend-roster request packet at WFC_FRIEND_REQUEST (0x44 bytes): the
 * buffer the server's reply is read into, then the server-side defaults from
 * gFriendRosterRequestDefaults with the local console id filled in. */
typedef struct WfcFriendRosterRequest {
    u8 *reply;      /* +0x00 buffer the server's reply is read into */
    u32 unk04;      /* +0x04 0x3FFF0400 */
    u16 localId;    /* +0x08 local console id */
    u16 unk0A;      /* +0x0A 0xFFFF */
    u32 unk0C;      /* +0x0C 0xFFFFFFFF */
    u32 unk10[13];  /* +0x10 zeroed defaults */
} WfcFriendRosterRequest; /* 0x44 bytes */

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
#define OV001_MSG_CONNECTING         0x31 /* "connecting" panel of the ov001 WFC connect screens */

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
#define SERVER_TIME_SPAN_SECONDS 3155760000LL /* one RTC century, 100 * 365.25 days */
#define SERVER_TIME_SPAN_LAST    3155759999LL /* last second before that wrap */

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
#define NAS_LOGIN_NAME           0x48 /* char[256] account name the NAS login returns */
#define NAS_LOGIN_PASSWORD       0x148 /* char[256] account password it returns */
#define NAS_LOGIN_GPI_PENDING    0x30 /* s32 nonzero while a gpi connection attempt runs; times out after 60 s */
#define NAS_LOGIN_GPI_TICK       0x34 /* u64 GetSystemTick the attempt started at */

/* Text form of a 12-byte NAS key/player record (FormatNasId): NAS_ID_TEXT_SIZE
 * bytes of "<player code in base 32><4 key-kind bytes><check word in base 32>",
 * i.e. 9 + 4 + 7 characters plus the terminator. */
#define NAS_ID_TEXT_SIZE      21 /* bytes in the rendered id, terminator included */
#define NAS_ID_CODE_BITS      43 /* player code: high 11 bits of word0 plus word1 */
#define NAS_ID_CHECK_BITS     32 /* check word, the record's word2 */
#define NAS_ID_KEY_TYPE_BYTES 4  /* key kind inserted as four characters */

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
 * carries the outcome, the status block the caller copies out,
 * the request descriptor, the network handle the HTTP runs on and the task that
 * drives it. */
#define NAS_CONNECTION_SIZE  0x13F4
#define NAS_CONN_STACK       0x0000 /* stack the connection task runs on */
#define NAS_CONN_STACK_SIZE  0x1000 /* bytes of that stack */
#define NAS_CONN_STACK_TOP   0x1000 /* top of the stack (the status block starts there) */
#define NAS_CONN_RESULT      0x1004 /* s32 outcome of the connection attempt */
#define NAS_CONN_STATUS      0x1008 /* s32 head of the status block */
#define NAS_CONN_STATUS_SIZE 0x1C4  /* bytes of the status block shared with the caller */
#define NAS_CONN_REQUEST     0x11CC /* NasRequest descriptor copied from the caller */
#define NAS_CONN_HANDLE      0x1314 /* void *network handle the HTTP runs on */
#define NAS_CONN_TASK        0x1318 /* task that drives the connection */
#define NAS_CONN_TASK_ID     0x1384 /* s32 id TaskCreate gave that task, 0 before it exists */
#define NAS_CONN_TASK_PRIORITY 16   /* priority the connection task runs at */
#define NAS_CONN_MUTEX       0x13D8 /* mutex guarding the connection */
#define NAS_CONN_ABORT       0x13F0 /* s32 set to 1 to drop the attempt at the task's next step */

/* The WFC network-check context's worker thread and stack. */
#define WFC_NET_CHECK_STACK          0x1000 /* worker stack and task argument block */
#define WFC_NET_CHECK_STACK_SIZE     0x1000 /* worker stack size in bytes */
#define WFC_NET_CHECK_TASK           0x111C /* thread object used by the HTTP worker */
#define WFC_NET_CHECK_TASK_ID        0x1188 /* s32 TaskCreate id, zero before creation */
#define WFC_NET_CHECK_TASK_PRIORITY  0x10   /* priority used for the worker */

/* Status the connection reports at NAS_CONN_STATUS: 0x4E20 (NAS_STATUS_BASE)
 * plus the NAS result code.  Codes below NAS_STATUS_ERROR_MIN report a step of
 * the connection and stay positive; NAS_STATUS_ERROR_MIN and up are failures and
 * Nas_GetResult hands them back negated.  A word outside NAS_STATUS_BASE ..
 * NAS_STATUS_LIMIT is replaced with NAS_STATUS_UNKNOWN. */
#define NAS_STATUS_IDLE 0x4E84 /* first failure code: the connection did nothing */
#define NAS_STATUS_BASE 0x4E20 /* 20000 */
#define NAS_STATUS_LIMIT 0x7530 /* 30000, one past the highest valid code */
#define NAS_STATUS_ERROR_MIN NAS_STATUS_IDLE
#define NAS_STATUS_UNKNOWN 0x5206 /* 20000 + 998: an unclassified failure */

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
#define WFC_STATE_CONN_MODE    0xD0A /* u8 WFC connection mode (WfcInitParams::mode), sent as the connect request's kind */
#define WFC_STATE_SELECT_MODE  0xC0  /* selection-mode bits of WFC_STATE_FLAGS */
/* List modes (low nibble of WFC_STATE_FLAGS): which built-in connection entry
 * the friend list adds beside the save-slot codes.  0 adds them all. */
enum {
    WFC_LIST_MODE_ALL         = 0,
    WFC_LIST_MODE_USB_AP      = 4, /* Nintendo Wi-Fi USB Connector access point, code "NWCUSBAP" */
    WFC_LIST_MODE_SHARED_AP   = 5, /* shared access point, encoded "NDWCSHAP" code */
    WFC_LIST_MODE_FREESPOT    = 6,
    WFC_LIST_MODE_WAYPORT2    = 7,
    WFC_LIST_MODE_NINTENDOWFC = 8
};
/* Friend ids of those built-in connection entries. */
enum {
    WFC_FRIEND_ID_USB_AP      = 6,
    WFC_FRIEND_ID_SHARED_AP   = 7,
    WFC_FRIEND_ID_FREESPOT    = 8,
    WFC_FRIEND_ID_WAYPORT2    = 9,
    WFC_FRIEND_ID_NINTENDOWFC = 10
};
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
#define WFC_ENTRY_TABLE_SIZE   0x144 /* bytes of the nine-row friend-list table cleared before a rebuild */
#define WFC_ENTRY_FLAGS        0x00 /* u8: bits 4..7 mark the rows of a selection */
#define WFC_ENTRY_MARK         0x10 /* mark bit: the high nibble is 1 on a marked row */
#define WFC_ENTRY_ID           0x01 /* u8 friend id returned to the caller */
#define WFC_ENTRY_CODE_LEN     0x03 /* u8 length of the row's code */
#define WFC_ENTRY_CODE         0x04 /* u8[] code bytes */

/* Sources Wfc_BuildFriendEntries rebuilds the friend-list rows from. */
enum {
    WFC_ENTRY_SOURCE_SAVE_SLOTS = 0, /* the friend codes of the three save slots */
    WFC_ENTRY_SOURCE_RECORDS    = 1, /* the connected friend records */
    WFC_ENTRY_SOURCE_FREESPOT   = 2  /* the FREESPOT configuration */
};

#define WFC_STATE_CONN_FLAGS   0xD0B /* u8: bits 2-3 connection status, bits 4-5 mode, high nibble attempts */
#define WFC_STATE_FRIEND_MASK  0xD16 /* u16: one bit per friend id taking part in the friend connection */
#define WFC_FRIEND_ID_COUNT    13    /* friend ids: bits 0..12 of WFC_STATE_FRIEND_MASK */
#define WFC_FRIEND_CODE_WAIT_MS 300  /* state 3 waits this long for a code before trying the next friend id */
#define WFC_STATE_CONN_EVENT   0xD14 /* u8 outcome of the friend connection: 1 cancelled, 2/3/4 results */
#define WFC_STATE_CONN_RETRY   0xD15 /* u8 friend-connection attempts made, wraps at 3 */
#define WFC_STATE_LINK_RETURN  0xD0E /* u8 session state to resume after the link step */
#define WFC_STATE_RECORD_RESULT 0x444 /* u8 per friend record, stride 4: the record's connection result */
#define WFC_STATE_RECORD_ID     0x445 /* u8 per friend record, stride 4: friend id the record resolved to */
#define WFC_STATE_RECORD_SCORE  0x446 /* u8 per friend record, stride 4: connection score, higher first */
#define WFC_STATE_RECORD_FLAGS  0x447 /* u8 per friend record, stride 4: bit 7 marks the record as sent */
#define WFC_STATE_RECORD_SENT       0x80 /* bit of WFC_STATE_RECORD_FLAGS: the record was sent for the friend id below */
#define WFC_STATE_RECORD_FRIEND_ID  0x7F /* low bits of WFC_STATE_RECORD_FLAGS: friend id the result was recorded for */
#define WFC_MIN_CONNECT_SCORE   20    /* lowest record score a friend connection is started for */
#define WFC_STATE_TIMER        0xCB0 /* u64 tick the friend connection started at */
#define WFC_ADDRESS_WAIT_SECONDS 10   /* seconds a connection step waits for a local IP address */
#define WFC_STATE_CMD_BUFFER   0xCB8 /* outgoing command/settings block built by func_020300e8 (0x52 bytes) */

#define WFC_STATE_RECORDS      0x470 /* friend records, WFC_RECORD_STRIDE bytes each */
#define WFC_RECORD_STRIDE      0xC0
#define WFC_RECORD_CODE_LEN    0x0A /* u16 length of the record's code */
#define WFC_RECORD_CODE        0x0C /* u8[] code bytes */
#define WFC_RECORD_FLAGS       0x2C /* u16 just after a 32-byte code: WFC_RECORD_FLAG_CONNECTION marks a built-in connection code */
#define WFC_RECORD_FLAG_CONNECTION 0x10 /* bit 4 of WFC_RECORD_FLAGS */
#define WFC_RECORD_CODE_ALT    0x04 /* u8[] the record's other code, compared for duplicate friends */
#define WFC_RECORD_FRIEND_ID  0x36 /* u16 friend id the record belongs to, plus one (0 = none) */
#define WFC_RECORD_CODE_OFF  0x3C /* u8[] code bytes sent for the record */

#define WFC_CODE_LEN_FRIEND    0x20 /* 32-byte friend code */
#define WFC_CODE_LEN_FREESPOT  0x08 /* 8-byte FREESPOT code */

/* An incoming friend message from the peer: the friend code it carries starts
 * at WFC_MSG_CODE and is WFC_MSG_CODE_LEN bytes long. */
#define WFC_MSG_CODE_LEN 0x0A /* u16 code length in bytes */
#define WFC_MSG_CODE     0x0C /* u8[] code bytes */

/* The message the step callback of the WFC connect step (Wfc_HandleConnectMessage,
 * main_0202F37C) receives from the WFC engine: a connection-status notification
 * carrying an outcome, or the peer's friend message (the layout above) at
 * WFC_MSG_PEER. */
#define WFC_MSG_TYPE          0x00 /* s16 WFC_MSG_TYPE_* */
#define WFC_MSG_TYPE_STATUS   5    /* a connection-status notification */
#define WFC_MSG_TYPE_FRIEND   7    /* the peer's friend message follows */
#define WFC_MSG_HAS_RESULT    0x02 /* u16 nonzero when the status message reports an outcome */
#define WFC_MSG_PEER          0x04 /* void *the peer's friend message of a WFC_MSG_TYPE_FRIEND */
#define WFC_MSG_RESULT        0x08 /* s32 outcome of a status message, WFC_RESULT_* */

/* Outcome codes WFC_MSG_RESULT carries; Wfc_HandleConnectMessage stores the matching
 * WFC_CONN_EVENT_* as the friend connection's event, and the connection's update then
 * keeps the record's result or retries. */
#define WFC_RESULT_CANCELLED 13 /* the connection was cancelled */
#define WFC_RESULT_REPORTED  15 /* the peer reported the connection's result */
#define WFC_RESULT_FINISHED  17 /* the connection finished (WFC_STEP_DONE) */

/* WFC_STATE_CONN_EVENT values. */
#define WFC_CONN_EVENT_CANCELLED 1 /* the connection was cancelled */
#define WFC_CONN_EVENT_REPORTED  2 /* a result was reported for the record */
#define WFC_CONN_EVENT_FINISHED  3 /* the connection finished */
#define WFC_CONN_EVENT_OTHER     4 /* any other outcome: the connection is retried */

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
