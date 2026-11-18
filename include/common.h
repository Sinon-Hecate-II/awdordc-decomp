/* Basic types for this decompilation (CodeWarrior for DS conventions). Agents add structs and prototypes here or
 * in new headers next to it. */
#ifndef COMMON_H
#define COMMON_H

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Word-at-a-time C string helpers (StringCompare, StringCopy): a little-endian word
 * holds a NUL byte when (word + STRING_ZERO_BIAS) & ~word & STRING_ZERO_MASK is set. */
#define STRING_ZERO_BIAS 0xfefefeffu /* the word minus 0x01010101 */
#define STRING_ZERO_MASK 0x80808080u /* the top bit of every byte */


/* What machine drafts (m2c) use for what they can't tell yet: autopilot tries them as they are. */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
typedef struct { s32 fd; s16 events; s16 revents; } PollFd;

/* PollFd event bits: what the caller asks for in events and SocketPoll reports
 * in revents. */
#define POLL_FD_READ     0x01 /* data can be read */
#define POLL_FD_PRIORITY 0x08 /* out-of-band (priority) data */
#define POLL_FD_ERROR    0x20 /* the socket failed or timed out */
#define POLL_FD_WRITE    0x40 /* data can be written */
#define POLL_FD_INVALID  0x80 /* the socket is not registered */
#define POLL_FD_ALWAYS   0xE0 /* error, writable and invalid are reported even when not asked for */

/* A GameSpy (gsi) recursive mutex, 24 bytes. The mutex remembers the thread
 * object that holds it and how many times that thread took it. */
typedef struct GsiMutex {
    u32 unused00;       /* +0x00 */
    u32 unused04;       /* +0x04 */
    void *owner;        /* +0x08: thread object holding the mutex, NULL when free */
    s32 count;          /* +0x0C: nesting depth for the owner */
    u32 unused10;       /* +0x10 */
    s32 waiters;        /* +0x14 */
} GsiMutex;             /* 0x18 */

/* A 16-bit pixel rectangle (position and size) handed to the sprite widget code. */
typedef struct WidgetRect {
    u16 x, y, w, h;
} WidgetRect;

/* TCP segment header on the wire (all multi-byte fields big-endian). */
typedef struct TcpSegment {
    u16 srcPort;    /* +0x00 */
    u16 dstPort;    /* +0x02 */
    u32 seq;        /* +0x04 */
    u32 ack;        /* +0x08 */
    u8 dataOffset;  /* +0x0C: header length in 32-bit words in the high nibble */
    u8 flags;       /* +0x0D: TCP_FLAG_* */
    u16 window;     /* +0x0E */
    u16 checksum;   /* +0x10 */
    u16 urgent;     /* +0x12 */
} TcpSegment;

/* UDP datagram header on the wire (all multi-byte fields big-endian). */
typedef struct UdpDatagram {
    u16 srcPort;    /* +0x00 */
    u16 dstPort;    /* +0x02 */
    u16 length;     /* +0x04 */
    u16 checksum;   /* +0x06 */
} UdpDatagram;

/* IP header fields used by the transport layer (two u16 each, big-endian). */
#define IP_HEADER_SRC_ADDR 0x0C /* source address */
#define IP_HEADER_DST_ADDR 0x10 /* destination address */

/* Socket control block, the object at a socket-list node's +0xA4. */
#define SOCKET_OWNER      0x00 /* s32 nonzero while the socket is in use */
#define SOCKET_TASK_STATE 0x04 /* s32 state of the task waiting on the socket */
#define SOCKET_STATE      0x08 /* u8 socket state, TCP_STATE_* or SOCKET_STATE_* */
#define SOCKET_STATE_TICK 0x10 /* u32 tick (GetSystemTick >> 16) the current state was entered */
#define SOCKET_LOCAL_PORT 0x0A /* u16 local port, host order */
#define SOCKET_LOCAL_ADDR 0x14 /* u32 local address */
#define SOCKET_PEER_PORT  0x18 /* u16 peer port, 0 until a peer is bound */
#define SOCKET_PEER_ADDR  0x1C /* u32 peer address, 0 or -1 until a peer is bound */
#define SOCKET_DATA_CB    0x38 /* s32 (*)(void *, u32, void *) receive callback */
#define SOCKET_RX_CAP     0x3C /* u32 receive buffer capacity */
#define SOCKET_RX_BUFFER  0x40 /* void *receive buffer */
#define SOCKET_RX_LENGTH  0x44 /* u32 bytes currently in the receive buffer */

/* Socket states that are not TCP states (SOCKET_STATE). */
enum {
    SOCKET_STATE_UDP_LISTEN = 10,   /* unbound UDP socket waiting for a peer */
    SOCKET_STATE_UDP_CONNECTED = 11 /* UDP socket with its peer address set */
};

#define IP_PROTO_TCP 6 /* IPv4 protocol number of a TCP segment */

/* TCP control flags (TcpSegment.flags, also used as the event kind). */
enum {
    TCP_FLAG_FIN = 0x01,
    TCP_FLAG_SYN = 0x02,
    TCP_FLAG_RST = 0x04,
    TCP_FLAG_PSH = 0x08,
    TCP_FLAG_ACK = 0x10,
    TCP_FLAG_URG = 0x20
};

/* State of a TCP connection (byte at +0x08 of the connection). */
enum TcpState {
    TCP_STATE_CLOSED = 0,
    TCP_STATE_SYN_SENT = 2,
    TCP_STATE_SYN_RCVD = 3,
    TCP_STATE_ESTABLISHED = 4,
    TCP_STATE_LAST_ACK = 6,
    TCP_STATE_FIN_WAIT1 = 7,
    TCP_STATE_FIN_WAIT2 = 8,
    TCP_STATE_TIME_WAIT = 9
};

/* Fields of the connection/socket object TcpSendSegment builds a segment from
 * (and TcpSendReset assembles a reset in).  The ports and destination address
 * are stored in host order; the sequence and acknowledgement numbers are the
 * raw 32-bit values that go on the wire. */
#define TCP_CONN_ACK_NUM  0x24 /* u32 acknowledgement number to send */
#define TCP_CONN_SEND_SEQ 0x28 /* u32 next send sequence number */

/* Description of a hash used by Hmac for keyed hashing (HMAC): the digest and
 * block sizes, the hash state it works on and its three entry points.  The
 * game's SHA1 one is gSha1HashDescriptor. */
typedef struct HashDescriptor {
    u32 digestSize;                            /* +0x00 digest bytes written by final() */
    u32 blockSize;                             /* +0x04 HMAC block size in bytes */
    void *context;                             /* +0x08 hash state passed to the callbacks */
    u8 *digest;                                /* +0x0C scratch for the inner digest */
    void (*init)(void *);                      /* +0x10 */
    void (*update)(void *, const void *, s32); /* +0x14 */
    void (*final)(void *, void *);             /* +0x18 */
} HashDescriptor;

/* SHA1 state worked on by Sha1Init, Sha1Update and SHA1_Finalize (main_0200BDA4). */
typedef struct Sha1Context {
    u32 state[5];      /* +0x00 A, B, C, D, E */
    u32 bitCountLo;    /* +0x14 low word of the processed bit count */
    u32 bitCountHi;    /* +0x18 high word of the processed bit count */
    u32 bufferBytes;   /* +0x1C bytes waiting in block */
    u8  block[0x40];   /* +0x20 message block being filled */
} Sha1Context; /* 0x60 bytes */

/* Compact SHA1 context of the reference implementation in main_020251B8
 * (SHA1_Init, SHA1_Update, SHA1_Final) that the TLS code hashes with. Unlike
 * Sha1Context above it stores no buffered-byte count: the offset in the block
 * is the low word of the bit count modulo 64. */
typedef struct TlsSha1Context {
    u32 state[5];    /* +0x00 A, B, C, D, E */
    u32 bitCountHi;  /* +0x14 high word of the processed bit count */
    u32 bitCountLo;  /* +0x18 low word of the processed bit count */
    u8 block[0x40];  /* +0x1C message block being filled */
} TlsSha1Context; /* 0x5C bytes */

/* A fixed-point decimal number used by the software-float and BigNum layer (the
 * calculator, damage and gauge code): a sign, a binary exponent, the number of
 * digits in use and the digits themselves, each a byte 0..9, most significant
 * first.  Several source files declared their own copy of this layout
 * (DecimalBD, Decimal38) before it lived here. */
typedef struct DecimalNumber {
    s8  sign;       /* +0x00 0 = positive, nonzero = negative */
    u8  pad;        /* +0x01 */
    s16 exponent;   /* +0x02 */
    u8  length;     /* +0x04 number of digits in use (0..32) */
    u8  digits[33]; /* +0x05 the digits, most significant first */
} DecimalNumber;    /* 0x26 bytes */

/* TLS connection (the channel object the TLS record code passes around).  The
 * hash and RC4 states are embedded; the key fields point into the channel's key
 * block, and each direction's sequence number is an 8-byte big-endian counter. */
enum {
    TLS_HASH_MD5  = 4, /* TLS_HASH_ALGORITHM: 16-byte MAC */
    TLS_HASH_SHA1 = 5  /* TLS_HASH_ALGORITHM: 20-byte MAC */
};

#define TLS_HASH_ALGORITHM 0x32  /* u16, TLS_HASH_MD5 or TLS_HASH_SHA1 */
#define TLS_MAC_KEY_OUT    0xbc  /* void * key of the outgoing record MAC */
#define TLS_RC4_KEY_OUT    0xc0  /* void * key of the outgoing RC4 state */
#define TLS_RC4_OUT        0xc8  /* RC4 state of outgoing records */
#define TLS_SEQ_OUT        0x1cc /* u8[8] outgoing sequence number, hashed in the MAC */
#define TLS_MAC_KEY_IN     0x1d4 /* void * key of the incoming record MAC */
#define TLS_RC4_KEY_IN     0x1d8 /* void * key of the incoming RC4 state */
#define TLS_RC4_IN         0x1e0 /* RC4 state of incoming records */
#define TLS_SEQ_IN         0x2e4 /* u8[8] incoming sequence number, hashed in the MAC */
#define TLS_SHA1_CTX       0x348 /* SHA1 context of the record being handled */
#define TLS_MD5_CTX        0x3fc /* MD5 context of the record being handled */
#define TLS_STATE          0x455 /* u8 TLS record/handshake state */
#define TLS_HMAC_IPAD      0x36  /* inner HMAC pad byte */
#define TLS_HMAC_OPAD      0x5c  /* outer HMAC pad byte */
#define TLS_MD5_PAD_SIZE   0x30  /* bytes of inner/outer pad the MD5 Finished digest hashes */
#define TLS_SHA1_PAD_SIZE  0x28  /* bytes of inner/outer pad the SHA1 Finished digest hashes */
#define TLS_MASTER_SECRET  0x00  /* u8[48] the session's master secret */
#define TLS_RANDOM_A       0x34  /* u8[32] one handshake random */
#define TLS_RANDOM_B       0x54  /* u8[32] the other handshake random */
#define TLS_KEY_BLOCK      0x74  /* per-direction MAC secrets and RC4 keys derived by TlsInitRecordKeys */
#define TLS_SESSION_CACHED 0x30  /* u8 nonzero when a cached session was restored for the peer */
#define TLS_SESSION_RESUMED 0x31 /* u8 nonzero when the server resumed the cached session */
#define TLS_SESSION_ID     0x74  /* u8[32] session id echoed in a ClientHello; the key block reuses it later */
#define TLS_SERVER_SIDE    0x454 /* u8 nonzero when this endpoint uses the server-side role */
#define TLS_CLIENT_CERT_REQUESTED 0x5ac /* u8 set once a CertificateRequest was received */
#define TLS_PENDING_RECORD 0x824 /* void * record buffer being reassembled */
#define TLS_PENDING_SIZE   0x828 /* u32 total size of that record */
#define TLS_PENDING_READ   0x82c /* s32 bytes of it read so far */
#define TLS_PENDING_KEEP   0x456 /* u8 keep the reassembled record for the caller */
#define TLS_STATE_SERVER_HELLO_DONE 4 /* TLS_STATE value: the peer sent ServerHelloDone */
#define TLS_STATE_FINISHED  6     /* TLS_STATE value: the peer's Finished digest verified */
#define TLS_MD5_CTX_SIZE    0x58  /* bytes of a saved MD5 transcript context */
#define TLS_SHA1_CTX_SIZE   0x5C  /* bytes of a saved SHA1 transcript context */
#define TLS_MD5_FINISHED_SIZE  16 /* bytes of a Finished MD5 digest */
#define TLS_SHA1_FINISHED_SIZE 20 /* bytes of a Finished SHA1 digest */
#define TLS_STATE_DONE     8     /* TLS_STATE value meaning the handshake completed */
#define TLS_STATE_ERROR    9     /* TLS_STATE value meaning the handshake failed */
#define TLS_RECORD_HEADER  5     /* bytes of a TLS record header */
#define TLS_MAX_RECORD     0x4800 /* largest accepted record body */

/* TLS record content types (the first byte of a record). */
enum {
    TLS_CONTENT_CHANGE_CIPHER_SPEC = 20,
    TLS_CONTENT_HANDSHAKE          = 22,
    TLS_CONTENT_APPLICATION_DATA   = 23
};

/* Application data is split across records no larger than this; each record
 * needs TLS_APP_RECORD_OVERHEAD extra bytes for its header and SHA1 MAC. */
#define TLS_APP_CHUNK_MAX       0xB4F
#define TLS_APP_RECORD_OVERHEAD 0x19

/* TLS handshake message type of the Finished message. */
#define TLS_HANDSHAKE_FINISHED 20

/* Contexts of the handshake transcript (the running MD5/SHA1 hash of the
 * handshake messages). TLS_MD5_CTX/TLS_SHA1_CTX above are the separate scratch
 * contexts a record MAC is computed in. */
#define TLS_TRANSCRIPT_MD5  0x3a4
#define TLS_TRANSCRIPT_SHA1 0x2ec

/* ov003 map-list menu entity: the mode nibble selects the map screen, and the
 * selected map id is read either from the paged list or from MAP_ID below. */
#define MENU_ENTITY_MODE      0x3b /* u8 low nibble: menu kind */
#define MENU_ENTITY_MAP_ID    0x3c /* u16 selected map id for non-list menus */
#define MENU_ENTITY_MAP_LIST  0x44 /* paged table of u16 map ids */
#define MENU_ENTITY_CURSOR    0x4c /* list cursor object, +0x14 selected row */
#define MENU_ENTITY_PAGER     0x5c /* paging object, +4 page index */
#define MENU_MAP_PAGE_SIZE    0x200 /* bytes per map-list page */
#define MENU_MAP_ENTRY_OFFSET 0x2e /* u16 map id per row within a page */

/* ov003 map-select screen: six preview rows of three animations each. */
typedef struct MapSelectRow {
    u8 pad[0x18];
    void *anim0;   /* +0x18 */
    void *anim1;   /* +0x1C */
    void *anim2;   /* +0x20 */
} MapSelectRow;    /* 0x24 bytes */

typedef struct MapSelectScreen {
    void *vtable;          /* +0x00 */
    u8 pad04[0x30];
    u8 unk34;              /* +0x34 */
    u8 unk35;              /* +0x35 */
    u8 flags36;            /* +0x36: high nibble selects the palette variant */
    u8 unk37;              /* +0x37 */
    u8 flags38;            /* +0x38 */
    u8 colorIndex;         /* +0x39 */
    u8 colorValue;         /* +0x3A */
    u8 pad3B;              /* +0x3B */
    void *palette;         /* +0x3C */
    void *bounds;          /* +0x40 */
    void *handle;          /* +0x44 */
    MapSelectRow *rows;    /* +0x48: 6 rows */
    void *animPair;        /* +0x4C: object with two animations at +0x18/+0x1C */
    void *sprite50;        /* +0x50 */
    void *sprite54;        /* +0x54 */
    void *obj58;           /* +0x58 */
    void *obj5C;           /* +0x5C: owns a buffer at +0x14 */
    void *obj60;           /* +0x60: polymorphic, vtable[1] is its destructor */
    void *obj64;           /* +0x64: polymorphic, vtable[1] is its destructor */
    void **buffers68;      /* +0x68: 6 buffers */
} MapSelectScreen;

/* Label state of the ov003 map-select screen (DrawMapSelectLabel). */
#define MAP_SELECT_KIND         0x0F /* byte in the descriptor at +0x3C that picks the label kind */
#define MAP_SELECT_ENTRY_ID     0x08 /* u16 entry id in the pager's current page object */
#define MAP_SELECT_ROW_ID_BASE  11   /* entry ids start this far above the row index */
#define MAP_SELECT_ROW_STRIDE   0x24 /* bytes per preview row in the +0x48 array */
#define MAP_SELECT_ROW_TEXT_KEY 0x0C /* s32 localized-text key in the object a row points at */
#define MAP_SELECT_BLINK        0x04 /* flags38 bit toggled on every label redraw */

/* The ov003 map-grid menu (the 0x3C-byte polymorphic object the map-select
 * handler holds at +0x48): eleven button sprites -- ids 0..4 in the top row,
 * 5..9 in the bottom row and 10 the wide button -- plus the entry ids its
 * per-frame update latches.  Ov003_UpdateMapGridButtons animates the buttons
 * every frame and records the button that reports a click (MAPGRID_CLICKED) and
 * the one showing its pressed frame (MAPGRID_PRESSED); the handler then moves
 * the map preview onto the pressed button.  func_ov003_021e1530 sets up the
 * selected entry: MAPGRID_CURSOR is its sprite object, MAPGRID_ID the entry id,
 * MAPGRID_COLUMN/ROW its grid position. */
#define MAPGRID_CLICKED   0x04 /* s8: button clicked this frame, -1 = none */
#define MAPGRID_PRESSED   0x05 /* s8: button showing its pressed frame, -1 = none */
#define MAPGRID_ID        0x06 /* u8: selected entry id (0..10) */
#define MAPGRID_COLUMN    0x07 /* u8: id % 5 */
#define MAPGRID_ROW       0x08 /* u8: id / 5 */
#define MAPGRID_COUNT     0x0B /* u8: number of visible map buttons */
#define MAPGRID_BUTTONS   0x0C /* void *[11]: the button sprites */
#define MAPGRID_BUTTON_STRIDE 4
#define MAPGRID_CURSOR    0x38 /* void *: sprite object of the selected entry */

/* The ov003 waypoint/segment list (the object the panel holds at +0x6C): 26 slot
 * sprites, each with its own owner.  Ov003_UpdateWaypointSlotButtons animates
 * every slot each frame and latches the slot that reports a click
 * (WAYPOINT_LIST_CLICKED) and the one showing its pressed frame
 * (WAYPOINT_LIST_PRESSED). */
#define WAYPOINT_LIST_COUNT   0x04 /* u8: number of slots in use */
#define WAYPOINT_LIST_CLICKED 0x05 /* s8: slot clicked this frame, -1 = none */
#define WAYPOINT_LIST_PRESSED 0x06 /* s8: slot showing its pressed frame, -1 = none */
#define WAYPOINT_LIST_SELECTED 0x07 /* u8: currently selected slot */
#define WAYPOINT_LIST_IDS     0x74 /* u8[4]: player id of each slot, 0xFF = no player yet */
#define WAYPOINT_LIST_SLOTS   0x78 /* void *[26]: the slot sprites */
#define WAYPOINT_LIST_SLOT_COUNT 26
#define WAYPOINT_LIST_UNIT    0xE0 /* void *: unit sprite of the selected slot */

/* The waypoint panel object's own children: the four player-select sprite
 * objects, the sprite group (12 slot sprites at +0x14 with a player label each at
 * +0x44, a trailing label at +0x74, the main sprite at +0x78 and one ready flag
 * per slot at +0x7C) and the WAYPOINT_LIST_* waypoint list above. */
#define WAYPOINT_PANEL_SELECT_SPRITES 0x64 /* void *[4]: player-select sprite objects */
#define WAYPOINT_PANEL_GROUP          0x68 /* the sprite group */
#define WAYPOINT_PANEL_LIST           0x6C /* the waypoint list */
#define WAYPOINT_GROUP_READY          0x7C /* u8[4]: that slot's player record has arrived */

/* The ov003 setup menu (the object the setup screen holds at +0x44): nine entry
 * sprites -- the eight option rows plus a ninth button -- each with its own
 * owner, plus the entry widget the selection currently points at.  The per-frame
 * update animates every slot and latches the entry that reports a click
 * (SETUP_MENU_CLICKED) and the one showing its pressed frame (SETUP_MENU_PRESSED);
 * +6 is the selected entry, also read from SETUP_MENU_CURRENT's sprite id. */
#define SETUP_MENU_CLICKED    0x04 /* s8: entry clicked this frame, -1 = none */
#define SETUP_MENU_PRESSED    0x05 /* s8: entry showing its pressed frame, -1 = none */
#define SETUP_MENU_SELECTED   0x06 /* u8: currently selected entry (0..7) */
#define SETUP_MENU_CELLS      0xC8 /* void *[8]: the option-row widgets */
#define SETUP_MENU_SLOTS      0xE8 /* void *[9]: the entry sprites */
#define SETUP_MENU_SLOT_COUNT 9
#define SETUP_MENU_CURRENT    0x10C /* void *: sprite of the selected entry */

/* Per-row animation targets of a MapSelectRow (the tween fields in front of its
 * three animation pointers). Ov003_ApplyRowSelectionAnimations stores the first
 * value on the selected row and the second on every other row; the matching
 * current fields follow the target as the tween runs. */
#define MAP_SELECT_ROW_ANIM_VALUE   0x0E /* u16 main tween target (0x100 selected, 0xCD idle) */
#define MAP_SELECT_ROW_ANIM_AUX     0x10 /* u8 auxiliary animation value (16 selected, 8 idle) */
#define MAP_SELECT_ROW_ANIM_STEP    0x12 /* s8 step tween target (1 selected, 0 idle) */
#define MAP_SELECT_ROW_ANIM_LEVEL   0x14 /* s8 level tween target (2 selected, 5 idle) */
#define MAP_SELECT_ROW_ANIM_MODE    0x15 /* s8 row animation mode (3 selected, 1 idle) */

/* ov003 map-info screen: the unit-category count grid filled by
 * func_020c1878 (5 player bands of 12 unit categories, the grid starting at
 * +4 of the block) and the text sprite that prints one category's total. */
#define OV003_UNIT_COUNT_GRID 0x68 /* u8 *: 5x12 per-category unit counts, grid at +4 */
#define OV003_UNIT_COUNT_TEXT 0x50 /* void *: text sprite for a category's total */

/* ov003 map-preview panel: the unit-category count block (its grid starts at
 * +0x1C and holds one 12-byte record per player band) and the text sprite that
 * prints one category's total. */
#define OV003_PREVIEW_UNIT_GRID 0x5C /* u8 *: per-category unit counts, grid at +0x1C */
#define OV003_PREVIEW_UNIT_TEXT 0x54 /* void *: text sprite for a category's count */

/* ov001 map-select list screen: the object pointed at by gMapSelectState+4.
 * It holds two rows of label sprites and a table of 42-byte map entries. */
#define MAPSELECT_ENTRIES       0x00 /* void *: map entry table */
#define MAPSELECT_ENTRY_SIZE    42   /* bytes per map entry */
#define MAPSELECT_ENTRY_NAME_ID 0x26 /* u16 per entry: index of the map's name tile */
#define MAPSELECT_ENTRY_FLAG    0x28 /* u8 per entry: selects the preview path */
#define MAPSELECT_LABEL_TILES   0x42 /* u16[]: tile of a row label sprite, indexed by the entry's MAPSELECT_ENTRY_FLAG */
#define MAPSELECT_NAME_TILES    0x48 /* u16[]: tile of a row name sprite, indexed by the entry's MAPSELECT_ENTRY_NAME_ID */
#define MAPSELECT_ROW_OBJS_A    0x10 /* void *[MAPSELECT_ROWS] row labels */
#define MAPSELECT_ROW_OBJS_B    0x24 /* void *[MAPSELECT_ROWS] map names */
#define MAPSELECT_ROWS          5    /* rows shown at once */
#define MAPSELECT_ROW_UNITS     0x1c /* scroll units of one list row */
#define MAPSELECT_COUNT         0x51 /* u8 number of maps in the list */
#define MAPSELECT_INDEX         0x52 /* u8 selected row */
#define MAPSELECT_CHOSEN        0x54 /* u8 a map has been chosen */
#define MAPSELECT_TEXT_PANEL    0x0C /* void *: panel the row names are drawn into */
#define MAPSELECT_SCROLL_ANIM   0x38 /* s32 token of the running list-scroll animation */
#define MAPSELECT_TASK          0x3C /* s32 handle of the row-scroll task */
#define MAPSELECT_MAX_SCROLL    0x40 /* u16 scroll position of the last row */
#define MAPSELECT_LAST_ROW      0x53 /* u8 the bar's handle travel in pixels (MAPSELECT_HANDLE_TRAVEL_*) */
#define MAPSELECT_BUMP_LATCH    0x59 /* u8 set once the no-move sound played for a held key */
#define MAPSELECT_SCROLL_DIRTY  0x56 /* u8 set when the list moved: refresh the BG scroll registers */
#define MAPSELECT_ROW_BASE_Y    0x36 /* y of the first visible row with the list at scroll 0 */
#define MAPSELECT_ROW_LABEL_X   0xB3 /* x of a row's label sprite */
#define MAPSELECT_ROW_NAME_X    0xD2 /* x of a row's map-name sprite */

/* The map-select list's scroll bar: the handle size (index into the bar's sprite
 * table, so the longer it is the fewer maps fit), the travel of each handle and
 * the bar's track on the screen. A list of MAPSELECT_NO_SCROLL_MAX maps or fewer
 * does not scroll and gets no bar. */
#define MAPSELECT_NO_SCROLL_MAX    4  /* maps that fit without scrolling */
#define MAPSELECT_SHORT_HANDLE_MAX 8  /* up to this many maps the bar uses the short handle */
#define MAPSELECT_HANDLE_NONE      0  /* no bar at all */
#define MAPSELECT_HANDLE_SHORT     1
#define MAPSELECT_HANDLE_LONG      2
#define MAPSELECT_HANDLE_TRAVEL_SHORT 0x1F /* MAPSELECT_LAST_ROW value of the short handle */
#define MAPSELECT_HANDLE_TRAVEL_LONG  0x37 /* MAPSELECT_LAST_ROW value of the long handle */
#define MAPSELECT_SCROLLBAR_TRACK  0x55 /* track length in pixels */
#define MAPSELECT_SCROLLBAR_X      0xEC /* x of the bar on the list screen */
#define MAPSELECT_SCROLLBAR_Y      0x3F /* y of the bar */

/* The fields of gMapSelectState in front of that object. */
#define MAPSELECT_STATE_CURSOR  0x00 /* u8 highlighted row (0..4) */
#define MAPSELECT_STATE_SCROLL  0x02 /* u16 list scroll position, 0x1c units per row */
#define MAPSELECT_STATE_OBJ     0x04 /* void *: the map-list object (MAPSELECT_*) */

/* The ov001 two-option Wi-Fi menu (gOv001WifiMenuSelection): the option the player
 * has selected and the explanation text loaded for the screen. Its options open
 * the access-point list or the options menu. */
#define OV001_WIFI_MENU_CHOICE      0x00 /* u8 selected option (OV001_WIFI_MENU_*) */
#define OV001_WIFI_MENU_TEXT        0x04 /* s32 loaded explanation text file */
#define OV001_WIFI_MENU_ACCESS_POINT 0   /* open the access-point list */
#define OV001_WIFI_MENU_OPTIONS      1   /* open the options menu */

/* The in-memory game settings block. The word at +0x128 is stamped with this
 * magic once the defaults have been filled in; code that reads the settings
 * re-initialises them when the magic is missing. */
#define GAME_SETTINGS_MAGIC 0x20070810

/* NitroSDK NARC archive header and block tags. A block holds its tag at +0 and
 * its byte size at +4; the header's u16 at +0x0C is the offset of the block
 * list and the u16 at +0x0E is the block count. */
#define NARC_MAGIC       0x4352414E /* "NARC" at +0x00 */
#define NARC_BYTE_ORDER  0xFFFE     /* u16 at +0x04 */
#define NARC_VERSION     0x0100     /* u16 at +0x06 */
#define NARC_BLOCK_FAT   0x46415442 /* "BTAF": file allocation table */
#define NARC_BLOCK_FNT   0x464E5442 /* "BTNF": file name table */
#define NARC_BLOCK_IMAGE 0x46494D47 /* "GMIF": file image data */

/* ov005 record/history menu: one scrolling list per tab (global gHistoryMenu). */
typedef struct HistoryMenuTab {
    s16 animPos;    /* +0x00: current scroll offset */
    s16 cursor;     /* +0x02: first visible row */
    s16 animating;  /* +0x04: scroll animation in progress */
    s16 selectable; /* +0x06: number of selectable rows */
    s16 count;      /* +0x08: number of rows */
} HistoryMenuTab;   /* 0xA bytes */

typedef struct HistoryMenu {
    u8 unk00;           /* +0x00 */
    s8 tab;             /* +0x01: active tab (0..2) */
    u8 selected;        /* +0x02: selected row */
    u8 pad03[0xD];
    HistoryMenuTab tabs[3]; /* +0x10 */
    u8 unk2E[0x12];
    u8 medals[8];        /* +0x40: medals earned, one flag each (drawn on the records screen) */
    void *sprite48;     /* +0x48 */
    void *sprite4C;     /* +0x4C */
    void *sprite50;     /* +0x50 */
    void *sprite54;     /* +0x54 */
    void *sprite58;     /* +0x58: list-up arrow */
    void *sprite5C;     /* +0x5C: list-down arrow */
    void *sprite60;     /* +0x60 */
} HistoryMenu;          /* 0x64 bytes */

/* ov005 records/achievements screen: the object at gRecordsMenuState+8.
 * Three tabs (tab) each list one record group; the list scrolls six rows at a
 * time and a row is only selectable when its enabled[] flag is set. */
/* Run-time exception frames used by the C++ code in src/auto/main_020739F8.c.
 * The handler's data block is self-describing: 1-byte opcodes (low 5 bits) with
 * an operand flag; FindExceptionEntryTarget walks the block to find where the
 * handler for the frame that faulted starts. */
#define JS_KIND_BIGENDIAN 0x80 /* data block: integers are big-endian and the opcodes are 5 bits wide */
#define JS_KIND_IMMEDIATE 0x40 /* operand flag tested by some handlers: take the value at the frame instead of memory */
#define JS_KIND_ID4       0x20 /* operand flag: something with function ids (bit checked by handlers 4, 6..11) */
#define JS_OP_MASK        0x1F /* opcode bits of a data byte */

/* Frame context: the first 7 words are a copy of the faulted frame's sticky
 * fields, tail[0..20] the spilled registers r4..r11 too. */
typedef struct JsFrameContext {
    s32 f0, f1, f2, f3, f4, f5, f6;
    s32 tail[21];
} JsFrameContext;

typedef struct JsRecord {           /* a frame's record: copy of the context plus the handler location */
    s32 f0, f1, f2, f3, f4, f5, f6;
    s32 tail[21];
    u8 *entry;
} JsRecord;

typedef struct JsRecordRef {
    s32 result;                     /* +0x00 nonzero while the record is in use */
    s32 handler;                    /* +0x04 handler of the record */
    void *unused;                   /* +0x08 */
    u8 *data;                       /* +0x0C the record's data block */
} JsRecordRef;

typedef struct JsResume {
    u8 *data;                       /* +0x00 the record's data block */
    s32 opcode;                     /* +0x04 opcode that resumes the handler */
} JsResume;

/* One entry of the unit kind table (gUnitKindTable, 0x70 = UNIT_KIND_STATS_SIZE
 * bytes per kind): the kind's name, movement and combat numbers.  The in-use and
 * not-yet-named fields are kept as raw bytes. */
#define UNIT_KIND_STATS_NAME     0x00 /* char[?]: the kind's name */
#define UNIT_KIND_STATS_FUEL_COST 0x56 /* s8 *: per-terrain fuel cost table, 0x20 terrain entries */
#define UNIT_KIND_STATS_LOSE_FUEL 0x5C /* u8 per kind: terrain (MAP_TERRAIN_PLAIN-based) kinds the unit loses fuel on */
#define UNIT_KIND_STATS_LOSE_FUEL2 0x5D /* u8 per kind: a second kind the unit loses fuel on */

typedef struct RecordsScreen {
    u16 flags;           /* +0x00 */
    s16 fadeCursor;      /* +0x02: position in fadeList, -1 before the first step */
    s16 fadeCount;       /* +0x04: number of entries in fadeList */
    s16 fadeList[1];     /* +0x06: record order walked by RecordsMenu_AdvanceFadeRecord */
    u8  pad08[0x7E];     /* +0x08 */
    s16 fadeTop;         /* +0x86: fade-out timer of the main screen */
    s16 fadeBottom;      /* +0x88: fade-out timer of the sub screen */
    s8  actionMode;      /* +0x8A: mode argument of the pending action */
    u8  pad8B;
    s16 lastHighlight;   /* +0x8C: highlighted record the cursor last moved from */
    s16 highlighted;     /* +0x8E: highlighted record, -1 when none */
    s16 pending;         /* +0x90: record a pending action applies to, -1 when none */
    s16 tab;             /* +0x92: record group shown (0..2) */
    s16 cursorRow;       /* +0x94: cursor row inside the visible window */
    s16 scrollGoal;      /* +0x96: scroll position the list is animating to */
    s16 scroll;          /* +0x98: top visible row */
    s16 count;           /* +0x9A: number of records */
    s16 selectable;      /* +0x9C: number of enabled records */
    s16 stepAnim;        /* +0x9E: one scroll step is being animated */
    s16 actionTimer;     /* +0xA0: countdown before a pending action runs */
    u8  enabled[0x40];   /* +0xA2: per-record enabled flag */
    s16 listCursor;      /* +0xE2: cursor into the shuffled enabled list */
    s16 listCount;       /* +0xE4: number of entries in that list */
    s16 list[1];         /* +0xE6: shuffled record indices */
} RecordsScreen;

/* One entry of the records/achievements table (gRecordTable): 3 groups of 39
 * entries of 0x30 bytes.  The entry names the thing a record counts and the
 * value thresholds for its three tiers. */
typedef struct RecordDefinition {
    u32 present;        /* +0x00 nonzero while the entry is in use */
    u16 id;             /* +0x04 id of the unit/event the record counts */
    u16 pad06;
    u32 bronze;         /* +0x08 tier 1 threshold */
    u32 silver;         /* +0x0C tier 2 threshold */
    u32 gold;           /* +0x10 tier 3 threshold */
    u8 pad14[0x1C];
} RecordDefinition;     /* 0x30 bytes */

/* Panels of the ov000 map info window (the box that follows the map cursor). */
enum {
    OV000_INFO_IDLE = 1,        /* no panel shown */
    OV000_INFO_TERRAIN = 2,     /* terrain / unit info panel */
    OV000_INFO_NO_TERRAIN = 3,  /* info panel with nothing selected */
    OV000_INFO_UNIT_STATS = 4   /* detailed unit statistics panel */
};

/* State of the ov000 map info window, one instance in ov000. */
typedef struct Ov000InfoMenu {
    void *statsWindow;   /* +0x00: unit statistics panel object */
    void *panel;         /* +0x04: terrain / unit info panel controller */
    s32 state;           /* +0x08: panel currently shown, OV000_INFO_* */
    s32 pendingState;    /* +0x0C: panel requested this frame */
    u8 refresh;          /* +0x10: panel content must be rebuilt */
    u8 trigger;          /* +0x11: re-read the cell under the cursor */
    u8 pressed;          /* +0x12: confirm button state last frame */
    u8 hasUnit;          /* +0x13: cursor cell holds a unit */
    s8 prevMode;         /* +0x14: map interaction mode last frame */
    s16 cursorX;         /* +0x16: cell under the cursor */
    s16 cursorY;         /* +0x18 */
    s8 animFrame;        /* +0x1A: cursor blink timer, -1 = not blinking */
    s32 language;        /* +0x1C: LANGUAGE_* the window was created with; picks its frame graphics */
} Ov000InfoMenu;
#endif

/* Current key input state; the global gKeyState points at one of these. */
typedef struct KeyState {
    u16 pressed;     /* +0x00: keys newly pressed this frame */
    u16 repeat;      /* +0x02: keys auto-repeating while held */
    u16 repeat2;     /* +0x04: second auto-repeat tier */
    u16 held;        /* +0x06: keys held now */
    u16 prevHeld;    /* +0x08: keys held on the previous frame */
    u16 prevHeld2;   /* +0x0A: keys held two frames ago (release detection) */
    u8 repeatDelay;  /* +0x0C: auto-repeat delay counter */
    u8 repeatRate;   /* +0x0D: auto-repeat rate counter */
} KeyState;

/* A scalar tween evaluated by GetSpriteAnimValue and advanced by
 * UpdateSpriteAnimation (the anim script runner fills it in). */
typedef struct SpriteTween {
    u8  mode;       /* +0x00: interpolation curve, SPRITE_TWEEN_* */
    u8  done;       /* +0x01 nonzero: stop advancing */
    u16 current;    /* +0x02 frames elapsed */
    u16 start;      /* +0x04 value current is reset to */
    u16 step;       /* +0x06 frames added per update */
    s16 base;       /* +0x08 constant offset added to the curve */
    s16 amplitude;  /* +0x0A curve amplitude */
    s16 duration;   /* +0x0C frames of the fade */
    s16 from;       /* +0x0E start value */
    s16 to;         /* +0x10 end value */
} SpriteTween;

enum {
    SPRITE_TWEEN_SINE = 0,     /* base + amplitude * sin(current) */
    SPRITE_TWEEN_LINEAR = 1,   /* from -> to, linear */
    SPRITE_TWEEN_CONSTANT = 2, /* from * amplitude, current ignored */
    SPRITE_TWEEN_EASE_IN = 3,  /* from -> to, quadratic ease-in */
    SPRITE_TWEEN_EASE_OUT = 4  /* from -> to, quadratic ease-out */
};

/* Streaming voice state (the ov010 gStreamVoiceState object).  The voice reads from
 * two sample buffers that the stream callback refills. */
#define STREAM_VOICE_ACTIVE          0x04 /* s32 voice started */
#define STREAM_VOICE_FLIP            0x08 /* s32 which buffer is being filled */
#define STREAM_VOICE_BUFFER1         0x0C /* first sample buffer */
#define STREAM_VOICE_BUFFER2         0x1C /* second sample buffer */
#define STREAM_VOICE_BUFFER2_SIZE    0x14 /* bytes allocated for the second buffer */
#define STREAM_VOICE_BUFFER1_SIZE    0x18 /* bytes allocated for the first buffer */
#define STREAM_VOICE_PAUSED          0x10 /* s32 voice paused */

/* Touch-screen tracking state, reached through *(gKeyState + 4). */
#define TOUCH_CUR_X        0x00 /* u16 current touch x */
#define TOUCH_CUR_Y        0x02 /* u16 current touch y */
#define TOUCH_START_X      0x04 /* u16 x where the touch began */
#define TOUCH_START_Y      0x06 /* u16 y where the touch began */
#define TOUCH_MIN_X        0x08 /* u16 leftmost x reached */
#define TOUCH_MIN_Y        0x0A /* u16 topmost y reached */
#define TOUCH_MAX_X        0x0C /* u16 rightmost x reached */
#define TOUCH_MAX_Y        0x0E /* u16 bottommost y reached */
#define TOUCH_HOLD_FRAMES  0x10 /* u8 frames the touch has been held, capped at 0xff */
#define TOUCH_REPEAT_TIMER 0x11 /* u8 frames left before the next repeat */
#define TOUCH_ACTIVE       0x12 /* u8 touch currently down */
#define TOUCH_PRESSED      0x13 /* u8 press or repeat delivered this frame */
#define TOUCH_STARTED      0x14 /* u8 touch began this frame */
#define TOUCH_TAP          0x15 /* u8 touch was a short tap */
#define TOUCH_RELEASED     0x16 /* u8 touch ended this frame */
#define TOUCH_DRAG_FRAMES  20   /* TOUCH_HOLD_FRAMES value at which a hold becomes a drag */

/* Press state of a sprite-button slot (GetSpriteSlotState/SetSpriteSlotState). */
enum {
    SPRITE_SLOT_IDLE    = 0, /* not touched */
    SPRITE_SLOT_PRESSED = 1, /* touch down inside the slot, waiting for release */
    SPRITE_SLOT_DRAGGED = 2  /* held past TOUCH_DRAG_FRAMES */
};

/* The CO "occupation" cut-in effect object used by main_020C1F58.  It shares
 * the battle-effect header layout (vtable at +0, timers at +0x34) but its
 * pointers at +0x40/+0x4C hold CO data and a palette instead. */
typedef struct OccupationEffect {
    u8   pad00[0x34];
    u8   frame;      /* +0x34: animation frame counter */
    u8   active;     /* +0x35: cut-in is running */
    u8   variant;    /* +0x36: portrait variant */
    u8   startFrame; /* +0x37: frame at which the portrait starts */
    u8   endFrame;   /* +0x38: frame at which the cut-in ends */
    u8   progress;   /* +0x39: portrait rows revealed / voices played */
    u8   pad3A[2];
    void *sprite;    /* +0x3C: panel sprite object */
    u8   *co;        /* +0x40: CO data: [0] id, [1] asset, [3] face, [5] rows */
    u16  *spriteA;   /* +0x44: sprite effect object (special variant) */
    u16  *spriteB;   /* +0x48: sprite effect object (normal) */
    void *palette;   /* +0x4C: palette object */
    u8   flags;      /* +0x50: bit0/bit1 toggles, bits 2..7 selected state */
} OccupationEffect;

/* The battle-start "break" cut-in effect state (built by the main_020C3D34
 * create function): the diagonal-line banner with the CO's name and face.  The two band offsets are the left and right halves' positions, the
 * window fields the bank split that the banner slides through, and rows the cell
 * rows each half draws. */
typedef struct BreakCutIn {
    s32 frame;         /* +0x00 frames the cut-in has run; its step phases are keyed on it */
    s32 holdTimer;     /* +0x04 timer of the hold step; the cut-in ends at 64 */
    s16 co;            /* +0x08 army/CO id whose face, palette and name are shown */
    s16 offsetX;       /* +0x0A band x offset, wraps at 256 (bank corner x) */
    s16 offsetY;       /* +0x0C band y offset, wraps at 256 (bank corner y) */
    u8  filler_0E[2];
    s32 scale;         /* +0x10 fixed-point zoom of the band's tile grid */
    s16 windowRight;   /* +0x14 split window 0 right bound (bank window0H[0]) */
    s16 windowBottom;  /* +0x16 split window 0 bottom bound (bank window0V[0]) */
    s16 windowLeft;    /* +0x18 split window 0 left bound (bank window0H[1]) */
    s16 windowTop;     /* +0x1A split window 0 top bound (bank window0V[1]) */
    s16 bandLeftX;     /* +0x1C x of the left half's first sprite */
    s16 bandLeftY;     /* +0x1E y of the left half's first sprite */
    s16 bandRightX;    /* +0x20 x of the right half's first sprite */
    s16 bandRightY;    /* +0x22 y of the right half's first sprite */
    s16 rows;          /* +0x24 cell rows each half draws (bank rowsAbove/rowsBelow) */
} BreakCutIn;

/* DS key bits, as stored in the KeyState masks. */
enum {
    KEY_A = 0x0001, KEY_B = 0x0002, KEY_SELECT = 0x0004, KEY_START = 0x0008,
    KEY_RIGHT = 0x0010, KEY_LEFT = 0x0020, KEY_UP = 0x0040, KEY_DOWN = 0x0080,
    KEY_R = 0x0100, KEY_L = 0x0200, KEY_X = 0x0400, KEY_Y = 0x0800
};

/* Entries of the KeyState masks (gKeyState). */
#define KEY_HELD    0 /* u16 keys held this frame */
#define KEY_PRESSED 1 /* u16 keys newly pressed this frame */

/* The unit-production menu's state object (gProductionMenuState): the mask of unit-kind
 * capability flags the selected base may build, the number of entries listed, then the
 * entries themselves as 2-byte {kind, unaffordable} pairs (gProductionMenuState+0x08). */
typedef struct ProductionMenuState {
    s32 kindMask;    /* +0x00 mask of buildable unit-kind capability flags */
    s32 count;       /* +0x04 number of entries in the buffer */
    u8  entries[1];  /* +0x08 first of the {u8 kind; u8 unaffordable;} entries */
} ProductionMenuState;

#define PRODUCTION_MENU_KIND_MASK 0x00 /* s32 ProductionMenuState.kindMask */

/* Build masks stored in ProductionMenuState.kindMask: a unit kind is listed when
 * its capability flags (UNIT_KIND_STATS_FLAGS) share a bit with the mask. */
#define PRODUCTION_BUILD_GROUND 0x07 /* ground kinds, built at the ground facilities */
#define PRODUCTION_BUILD_AIR    0x10 /* air kinds, built at an airport */
#define PRODUCTION_BUILD_NAVAL  0x20 /* naval kinds, built at a port */

/* The per-kind row object the production menu creates (func_020b953c): the unit
 * kind it will build, and the frame counter of the funds line's count-up. */
#define PRODUCTION_ROW_KIND     0x5C /* s32 unit kind the row is about */
#define PRODUCTION_ROW_FRAME    0x6C /* s16 frames elapsed */
#define PRODUCTION_ROW_DURATION 0x6E /* s16 frames the count-up takes */

/* ov000 unit-list menu object (singleton returned by GetScrollList). */
typedef struct ScrollList {
    u8 pad00[0x34];
    s16 tab;          /* +0x34: selected tab (0..3) */
    s16 reverse;      /* +0x36: reverse sort order toggle (0/1) */
    s16 animPos;      /* +0x38: animated scroll offset (eased toward scrollPos*2) */
    s16 scrollPos;    /* +0x3A: first visible row */
    s16 count;        /* +0x3C: number of rows */
    s16 animating;    /* +0x3E: scroll animation in progress */
    s16 selectedId;   /* +0x40: unit id shown by the info panel */
    void *spriteUp;   /* +0x44: list-up arrow sprite */
    void *spriteDown; /* +0x48: list-down arrow sprite */
} ScrollList;

/* The unit-list menu's row list (gUnitListRows): the list's pixel scroll value
 * followed by the buffer of unit slots to show, which ScrollListRebuild sorts. */
#define UNIT_LIST_ROW_CAPACITY 64 /* slots in the row list buffer (bytes) */

/* Geometry of the unit list's clickable buttons: one highlight sprite per visible
 * row, 16 px apart and starting at y 39, 4 px in from the left; the four tab buttons
 * sit across the top and carry the slot ids 251 (tab 0) down to 248 (tab 3). */
#define SCROLL_LIST_VISIBLE_ROWS 6
#define SCROLL_LIST_ROW_X        4
#define SCROLL_LIST_ROW_Y        39
#define SCROLL_LIST_ROW_STEP     16
#define SCROLL_LIST_TAB_ID(tab)  (251 - (tab))

/* Flags byte of a gpi player record (player + 0x15): which optional parts follow. */
enum {
    GPI_REC_FLAG_ID     = 0x02, /* a 4-byte id follows */
    GPI_REC_FLAG_VALUE  = 0x08, /* a 4-byte value follows */
    GPI_REC_FLAG_SKIP   = 0x10, /* a 2-byte field follows and is skipped here */
    GPI_REC_FLAG_PORT   = 0x20, /* a big-endian 2-byte port follows (else the context default) */
    GPI_REC_FLAG_FIELDS = 0x40, /* typed key/value fields follow, per the context schema */
    GPI_REC_FLAG_KEYS   = 0x80  /* raw zero-terminated key/value pairs follow */
};

/* Type of a field in a gpi record schema (entry[1]). */
enum {
    GPI_FIELD_STRING = 0, /* zero-terminated string */
    GPI_FIELD_BYTE   = 1,
    GPI_FIELD_PORT   = 2  /* big-endian 16-bit */
};

/* Bits of a gpi player's state byte (player + 0x14). */
enum {
    GPI_PLAYER_STATE_FIELDS = 1, /* a fields section has been applied */
    GPI_PLAYER_STATE_KEYS   = 2  /* a key/value section has been applied */
};

/* State of a gpi peer connection (peer->state at +0x00). */
enum {
    GPI_PEER_STATE_CREATED     = 100, /* allocated, no challenge answered yet */
    GPI_PEER_STATE_CHALLENGED  = 101, /* challenge sent, awaiting the answer */
    GPI_PEER_STATE_PROGRESSING = 102, /* authentication reply built, socket being opened */
    GPI_PEER_STATE_CONNECTING  = 103, /* socket opened, awaiting the TCP connect */
    GPI_PEER_STATE_WAITING     = 104, /* waiting for the peer's \auth\ reply */
    GPI_PEER_STATE_CONNECTED   = 105, /* ready: relay game data messages */
    GPI_PEER_STATE_ERROR       = 106  /* failed; the peer is torn down */
};

/* Message kinds carried in a gpi message's \m\ field. */
enum {
    GPI_MSG_PLAYER_INFO     = 1,   /* player id/name announcement */
    GPI_MSG_CHALLENGE       = 102, /* challenge request */
    GPI_MSG_CHALLENGE_REPLY = 103, /* answer to a challenge request */
    GPI_MSG_GAME_DATA_FIRST = 200,
    GPI_MSG_GAME_DATA_LAST  = 208
};

/* GameSpy gpi receive buffer (the connection field at +0x1DC, and a peer's
 * message buffer at peer + 0x18): storage, the allocated size, the number of
 * bytes currently held and, for a peer buffer, the read position of the next
 * message. */
/* Appending strings grows storage by at least this many bytes, plus a terminator. */
#define GPI_BUFFER_GROWTH 0x800

typedef struct GPIBuffer {
    void *data; /* +0x00 storage */
    s32   size; /* +0x04 allocated bytes */
    s32   len;  /* +0x08 bytes used */
    s32   pos;  /* +0x0C read position of the next message (peer buffers only) */
} GPIBuffer;

/* GameSpy gpi send buffer (the peer field at +0x28): storage, its allocated
 * size, the number of bytes queued and the offset of the first byte that has
 * not been sent yet. */
typedef struct GPISendBuffer {
    void *data; /* +0x00 storage */
    s32   size; /* +0x04 allocated bytes */
    s32   len;  /* +0x08 bytes queued */
    s32   pos;  /* +0x0C offset of the first unsent byte */
} GPISendBuffer;

/* A queued GameSpy gpi callback (gpiCallback.c).  gpiCallCallback invokes
 * callback.callback(connection, arg, callback.param) and then frees arg
 * according to type. */
typedef struct GPICallbackData {
    struct {
        void (*callback)(void *connection, void *arg, void *param); /* +0x00 */
        void *param;                                                 /* +0x04 */
    } callback;
    void *arg;                    /* +0x08 typed data handed to the callback */
    s32   type;                   /* +0x0C GPI_CALLBACK_* */
    s32   operationId;            /* +0x10 id of the operation that queued it */
    struct GPICallbackData *next; /* +0x14 next queued callback */
} GPICallbackData;

/* GPICallbackData.type: the layout of its arg and what gpiCallCallback frees
 * after the callback has run. */
enum {
    GPI_CALLBACK_ERROR         = 1, /* arg is one block; run whatever the operation */
    GPI_CALLBACK_PLAYER_INFO   = 2, /* arg->name at +0x08 is an owned string */
    GPI_CALLBACK_INFO_LISTS    = 3, /* arg owns the two string lists at +0x3C/+0x40 */
    GPI_CALLBACK_INFO_RECORDS  = 4, /* arg owns the record array at +0x0C */
    GPI_CALLBACK_OWNED_POINTER = 7, /* arg owns the pointer at +0x10 */
    GPI_CALLBACK_RECORD_LIST   = 8, /* arg owns the record array at +0x08 */
    GPI_CALLBACK_STRING_LIST   = 9  /* arg owns the array of strings at +0x08 */
};

/* Callback data with an owned string at +0x08 (GPI_CALLBACK_PLAYER_INFO). */
typedef struct GpiPlayerInfoData {
    s32   id;    /* +0x00 */
    s32   time;  /* +0x04 */
    char *name;  /* +0x08 released after the callback */
} GpiPlayerInfoData;

/* Callback data with two owned string lists (GPI_CALLBACK_INFO_LISTS). */
typedef struct GpiInfoListsData {
    u8     pad00[0x38];
    s32    count;   /* +0x38 entries in each list */
    char **names;   /* +0x3C owned list of allocated names */
    char **values;  /* +0x40 owned list of allocated values */
} GpiInfoListsData;

/* Callback data owning one record array at +0x0C (GPI_CALLBACK_INFO_RECORDS). */
typedef struct GpiInfoRecordsData {
    u8   pad00[0x0C];
    void *records; /* +0x0C owned record array */
} GpiInfoRecordsData;

/* Callback data owning the pointer at +0x10 (GPI_CALLBACK_OWNED_POINTER). */
typedef struct GpiOwnedPointerData {
    u8   pad00[0x10];
    void *pointer; /* +0x10 released after the callback when set */
} GpiOwnedPointerData;

/* Callback data owning one record array at +0x08 (GPI_CALLBACK_RECORD_LIST). */
typedef struct GpiRecordListData {
    s32  unknown00; /* +0x00 */
    s32  count;     /* +0x04 number of records */
    void *records;  /* +0x08 owned record array */
} GpiRecordListData;

/* Callback data owning an array of strings (GPI_CALLBACK_STRING_LIST). */
typedef struct GpiStringListData {
    s32    unknown00; /* +0x00 */
    s32    count;     /* +0x04 number of strings */
    char **strings;   /* +0x08 owned array of allocated strings */
} GpiStringListData;

/* Public gpi operations return empty success results in simulation mode. */
#define GPI_CONN_SIMULATION 0x108 /* s32 nonzero bypasses network operations */
#define GPI_CONN_STATE 0x1D8 /* s32 connection state */
#define GPI_STATE_DISCONNECTED 4
#define GPI_INFO_RESULT_WORDS 129 /* 0x204-byte profile-info callback record */
#define GPI_SEARCH_RESULT_WORDS 4 /* s32 words in a search callback record */
#define GPI_SEARCH_MORE 0x601 /* search status: more result pages follow (0x600 when complete) */

/* Server-message fields in the GameSpy gpi connection. */
#define GPI_CONN_SESSION_KEY 0x198 /* s32 server-issued session key */
#define GPI_CONN_OUTPUT_BUFFER 0x1F4 /* server command send buffer */
#define GPI_MESSAGE_COPY_SIZE 0xDAD /* bounded message copy, including terminator */
#define GPI_MESSAGE_STACK_SIZE 0xDB0 /* aligned temporary message storage */

/* Pending profile updates: AppendUpdateProField/AppendUpdateUiField accumulate
 * fields here and gpiFlushUpdateBuffers moves them to the outgoing buffer. */
#define GPI_CONN_UPDATE_PRO_BUFFER 0x440 /* GPIBuffer: accumulated "updatepro" fields */
#define GPI_CONN_UPDATE_PRO_LEN    0x448 /* s32: bytes pending in it (the buffer's len) */
#define GPI_CONN_UPDATE_UI_BUFFER  0x450 /* GPIBuffer: accumulated "updateui" fields */
#define GPI_CONN_UPDATE_UI_LEN     0x458 /* s32: bytes pending in it (the buffer's len) */

/* A gpi connection's error state and callback queue. */
#define GPI_CONN_ERROR_CALLBACK 0x1A4 /* s32 registered error callback function */
#define GPI_CONN_ERROR_DATA     0x1A8 /* s32 parameter passed to it */
#define GPI_CONN_ERROR_CODE     0x418 /* s32 code last stored by gpiSetError */
#define GPI_CONN_ERROR_FATAL    0x41C /* s32 nonzero once a fatal error was reported */
#define GPI_CONN_CACHED_STATUS  0x214 /* s32 status last handed to gpiSetStatusInfo, -1 when none yet */
#define GPI_CONN_STATUS_STRING  0x218 /* s8[0x100] cached status string */
#define GPI_CONN_LOCATION_STRING 0x318 /* s8[0x100] cached location string */
#define GPI_CONN_CALLBACK_HEAD  0x438 /* GPICallbackData *first queued callback */
#define GPI_CONN_CALLBACK_TAIL  0x43C /* GPICallbackData *last queued callback */
#define GPI_CONN_OPERATIONS     0x424 /* GPIOperation *first pending operation */
#define GPI_CONN_NEXT_OPERATION_ID 0x20C /* s32 next operation id handed out (starts at 2) */

/* A queued gpi operation (0x24 bytes), a node of the connection's pending
 * operation list.  gpiAddOperation allocates one and prepends it; the stepping
 * code walks the list, stores the result and turns it into a callback. */
typedef struct GPIOperation {
    s32 type;          /* +0x00 operation kind */
    void *data;        /* +0x04 profile, peer or search the operation works on */
    s32 blocking;      /* +0x08 nonzero when the operation must finish before returning */
    s32 callback;      /* +0x0C completion callback */
    s32 callbackParam; /* +0x10 the callback's parameter */
    s32 state;         /* +0x14 operation state */
    s32 id;            /* +0x18 id of the operation */
    s32 result;        /* +0x1C result stored when it completes */
    struct GPIOperation *next; /* +0x20 next pending operation */
} GPIOperation; /* 0x24 bytes */

/* Fatal flag passed to gpiCallErrorCallback. */
enum {
    GP_NON_FATAL = 0, /* the connection stays usable */
    GP_FATAL     = 1  /* the connection is finished */
};

/* Result code of an operation that did not fail. */
#define GP_NO_ERROR 0

/* Connection session states (the state at GetConnection()->0x1A0) used while
 * the peers agree on their player slots and synchronise. */
enum {
    CONN_STATE_SYNC_PREPARE  = 8,  /* preparing the session with a peer */
    CONN_STATE_WAIT_SLOT     = 9,  /* own player slot is being accepted */
    CONN_STATE_MATCH         = 10, /* the session's match has started; match traffic is live */
    CONN_STATE_SYNC_MEASURE  = 14, /* peers report in; the round trip is being measured */
    CONN_STATE_SYNC_DONE     = 15, /* every connected peer has acknowledged the sync */
    CONN_STATE_WAIT_SYNC_ACK = 16, /* waiting for every peer to acknowledge the sync */
    CONN_STATE_WAIT_SYNC_RTT = 17  /* waiting out the measured latency before completing */
};

/* Peer synchronization notices carried in a connection packet's type field. */
enum {
    PEER_SYNC_PREPARE = 13, /* peer asks us to prepare the session */
    PEER_SYNC_ACK     = 14, /* peer is ready; measure the round trip */
    PEER_SYNC_DONE    = 15  /* the peer's synchronization is complete */
};

/* Connection session fields (in the context returned by GetConnection()) used
 * by the synchronization handshake. */
#define CONN_SESSION_STATE        0x1A0 /* s32 state, one of CONN_STATE_* */
#define CONN_SESSION_SLOT         0x14  /* u8 peer slots in use: the slot arrays are indexed 1..this */
#define CONN_SESSION_PLAYER_COUNT 0x0D  /* u8  number of connected peers */
#define CONN_SESSION_PEER_IDS     0xF4  /* s32 peer ids, 4 bytes per slot */
#define CONN_SESSION_SYNC_ACKS    0x1D8 /* u32 bitmask of peers that answered */
#define CONN_SESSION_SYNC_SENT    0x1E8 /* u64 time the last sync notice was sent */
#define CONN_SESSION_SYNC_EXCESS  0x1B2 /* u16 worst overrun of the sync deadline */
#define CONN_SESSION_SYNC_RETRY   0x1AC /* u8 retry counter for the sync-measure notices */
#define CONN_SESSION_PEER_SLOTS   0x2D0 /* u8 slot id per connected peer, indexed from 1 */
#define CONN_SESSION_PEER_DATA    0x24  /* s32 per slot: peer player id exchanged in connection packets */
#define CONN_SESSION_PEER_DATA_PORT 0xA4 /* u16 per slot: peer port exchanged in connection packets */
#define CONN_SESSION_PEER_IPS     0x210 /* s32 per slot: peer IPv4 address */
#define CONN_SESSION_PEER_PORTS   0x290 /* u16 per slot: peer port */
#define CONN_SESSION_PLAYER_MASK  0x2F0 /* u32 bitmask of player slots that are present */
#define CONN_SESSION_MODE         0x15  /* u8 connection mode (0/1 joining, 2/3 serving) */
#define CONN_SESSION_BUSY         0x1A9 /* u8 nonzero while a connection change is in progress */
#define CONN_SESSION_TEARDOWN     0x1A8 /* u8 nonzero while peers are being removed or the session torn down */
#define CONN_SESSION_NATNEG       0x19C /* s32 NAT negotiation session to free on teardown, 0 when none */
#define CONN_SESSION_JOIN_PEER    0x204 /* s32 player id a join request is outstanding to, 0 when none */
#define CONN_SESSION_TARGET_ID    0x20C /* s32 player id of the matchmaking target, 0 when none */
#define CONN_SESSION_MATCH_ADDRESS 0x20 /* s32 address reported for the match (usually our QR2 parameter at 0x200) */
#define CONN_SESSION_ADDRESS_VALID 0x17 /* u8 nonzero once MATCH_ADDRESS may be announced to the peer */
#define CONN_SESSION_SERVER_BROWSER 0xE4 /* s32 GameSpy server-browser/QR2 object built by func_020613dc */
#define CONN_SESSION_EVENT_CALLBACK     0x464 /* s32 match event callback: (status, closed, targetCleared, serving, slot, data) */
#define CONN_SESSION_EVENT_DATA         0x468 /* s32 data passed to EVENT_CALLBACK */
#define CONN_SESSION_PEER_CALLBACK      0x46C /* s32 callback (slot, data) run when a peer joins while serving */
#define CONN_SESSION_PEER_CALLBACK_DATA 0x470 /* s32 data passed to PEER_CALLBACK */
#define CONN_SESSION_SCORE_CALLBACK     0x474 /* s32 callback (index, data) scoring browsed sessions */
#define CONN_SESSION_SCORE_CALLBACK_DATA 0x478 /* s32 data passed to SCORE_CALLBACK */
#define CONN_SESSION_TARGET_NOTICES  0x17C /* u8 QR2 state notices seen from the connect target */
#define CONN_SESSION_CONNECT_TARGET  0x180 /* s32 peer id the outstanding connect targets */
#define CONN_SESSION_JOIN_TICK       0x184 /* u64 time the outstanding join was opened */
#define CONN_SESSION_CONNECT_TICK    0x18C /* u64 time the outgoing socket connect was started */
#define CONN_SESSION_SELF_ID         0x208 /* s32 own player id, 0 before the master answered */
#define CONN_SESSION_ATTEMPT_TICK    0x1CC /* u64 tick the current connect attempt started */
#define CONN_SESSION_ATTEMPT_LIMIT   0x1C8 /* s32 time limit of the attempt, 0 when it has none */
#define CONN_SESSION_CAPACITY        0x16  /* u8 session capacity (SCM) minus 1, fixed when the match starts */
#define CONN_SESSION_MATCH_START_PENDING  0x1AE /* u8 nonzero while a match start waits for CONN_STATE_MATCH */
#define CONN_SESSION_MATCH_START_CALLBACK 0x47C /* s32 callback (data) run when the deferred match start happens */
#define CONN_SESSION_MATCH_START_DATA     0x480 /* s32 data passed to it */
#define CONN_SESSION_LAST_COMMAND        0x3CC /* u8 connection command last handled, 0xFF when none */
#define CONN_SESSION_LAST_COMMAND_TRIES  0x3CD /* u8 times the last command has been repeated */

/* The in-flight peer-connect record at GetConnection()+0x194 (0xC bytes): what
 * the socket connect is for and how often it has been retried.  Its last word
 * overlaps CONN_SESSION_NATNEG. */
typedef struct ConnAttempt {
    u8  isJoin;  /* +0x00 nonzero when the attempt is a join */
    u8  retries; /* +0x01 connect retries so far */
    u16 port;    /* +0x02 peer port */
    s32 address; /* +0x04 peer IPv4 address */
    s32 natNeg;  /* +0x08 NAT negotiation session reused by the connect, 0 when none */
} ConnAttempt;

/* A peer address handed to a connect: the IPv4 address at +4 and the port at +2. */
typedef struct PeerAddress {
    u16 unk00;   /* +0x00 */
    u16 port;    /* +0x02 */
    s32 address; /* +0x04 */
} PeerAddress;

/* Connection session fields used while GameSpy QR2 server reporting runs. */
#define CONN_SESSION_GT2_SOCKET   0x04  /* GameSpy GT2 socket wrapper (handle at +0, local port at +8) */
/* GameSpy GTI2 transport session field used by the message handler. */
#define GT2_RECV_SEQUENCE         0x66  /* u16 sequence number the next incoming command must carry */
#define CONN_SESSION_QR2_RECORD   0x10  /* void *GameSpy QR2 connection record (see qr2.h) */
#define CONN_SESSION_PUBLIC_PORT  0x1A  /* u16 port the master reported for this client */
#define CONN_SESSION_PUBLIC_IP    0x1C  /* s32 IPv4 address the master reported for this client */
#define CONN_SESSION_QR2_PARAM    0x200 /* s32 matchmaking parameter reported to the master */
#define CONN_SESSION_GAME_NAME    0x2F4 /* s32 game name string given to QR2 */
#define CONN_SESSION_PLAYER_NAME  0x2F8 /* s32 player name string given to QR2 */

/* Fields of the online-match session context (the pointer held at
 * gMatchSessionMgr + 8). */
#define MATCH_SESSION_STATUS       0x00 /* s32 0 idle, 1 running, 2 finished */
#define MATCH_SESSION_CONNECTION   0x04 /* void *GameSpy gpi connection handle of the match session */
#define MATCH_SESSION_PLAYER_COUNT 0x14 /* s32 number of players */
#define MATCH_SESSION_PLAYERS      0x18 /* array of 12-byte player records */
#define MATCH_SESSION_PLAYER_SIZE  12
#define MATCH_SESSION_CURSOR       0x1C /* u8 player being processed */
#define MATCH_SESSION_DIRTY        0x1D /* u8 player list changed */
#define MATCH_SESSION_STATE        0x1E /* u8 match-setup step */
#define MATCH_SESSION_STEP         0x1F /* u8 pass counter: the session finishes when it reaches 2 */
#define MATCH_SESSION_EVENT_CB     0x2C /* void (*)(s32 error, u8 dirty, s32 data): session finished or failed */
#define MATCH_SESSION_EVENT_DATA   0x30 /* s32 data passed to EVENT_CB */
#define MATCH_SESSION_INFO_CB      0x34 /* void (*)(s32 slot, s32 value, void *out, s32 data): asks for a player's info */
#define MATCH_SESSION_INFO_DATA    0x38 /* s32 data passed to INFO_CB */
#define MATCH_SESSION_STATS_CB     0x3C /* void (*)(s32 slot, s32 otherSlot, s32 data): folds one player's battle stats into another */
#define MATCH_SESSION_STATS_DATA   0x40 /* s32 data passed to STATS_CB */

/* Multiboot (DS Download Play) boot state (gMbBootState, 0x20 bytes). */
typedef struct MbBootState {
    s32 paramsSent;  /* +0x00 nonzero once Mb_SendBootParams has run */
    s32 remoteReady; /* +0x04 cleared when the ARM7 reports that it is ready */
    s32 initialised; /* +0x08 nonzero once Mb_BootInit has run */
    s32 complete;    /* +0x0C nonzero once the ARM7's boot-complete message was handled */
    s32 unk10;       /* +0x10 */
    s32 unk14;       /* +0x14 */
    s32 (*onComplete)(void); /* +0x18 optional callback run by Mb_BootCompleteHandler */
    s32 unk1C;       /* +0x1C */
} MbBootState;

/* The multiboot match work area (gMbWork = gMbState.work, 0x7D00 bytes): the
 * buffer commands are serialized into, the per-player slot states and the 16
 * records of players grouped together for one battle. */
#define MB_WORK_SIZE        0x7D00 /* bytes cleared when the match state is torn down */
#define MB_CMD_BUFFER       0x0000 /* outgoing command record, written by SerializeCommand */
#define MB_PLAYER_STATE     0x14E4 /* s32 per-player state, 4 bytes each, indexed from 1 */
#define MB_PLAYER_STATE_GROUPED 5 /* the player has joined a group; the group's battle can start */
#define MB_PLAYER_GROUP     0x1525 /* s8 per-player group id, 1 byte each, indexed from 1 */
#define MB_GROUP_STARTED    0x1524 /* u8 nonzero once the players have been grouped */
#define MB_GROUPS           0x1788 /* 16 group records, MB_GROUP_STRIDE bytes each */
#define MB_GROUP_STRIDE     0x5D4
#define MB_GROUP_UNIT_DATA  0x0000 /* 0xE4-byte unit roster sent when the group's battle starts */
#define MB_GROUP_UNIT_COUNT 0x5C4  /* u16 players/units in the group */
#define MB_GROUP_ACTIVE     0x5CA  /* u8 nonzero while the group record is in use */
#define MB_GROUP_PENDING    0x5AA  /* u16 record-relative: per-player pending bitmask */
#define MB_GROUP_ACKED      0x5AC  /* u16 record-relative: per-player done bitmask */
#define MB_GROUP_CHUNK_CURSOR 0x5C0 /* u16 record-relative: chunk transfer the group is sending */
#define MB_GROUP_CHUNK_GOAL   0x5C2 /* u16 record-relative: newest chunk a member asked for; the cursor advances to it */
#define MB_PLAYER_FORFEIT   0x1526 /* s8 per-player 1-byte flag, -1 = gave up, indexed from 1 */
#define MB_BLOCK_SIZE       0x1318 /* u32 bytes carried by one transfer block, at this work-area offset */

/* Address windows a download chunk may occupy, chosen by the chunk kind kept in
 * sMbChunkKinds (2 = the fixed header window, 0 = main RAM below 0x022C0000,
 * 1 = the rest of main RAM or the 0x037F8000 window). Kinds 0 and 1 may not
 * reach the last 0x1800 bytes of main RAM. */
#define MB_WINDOW_HEADER_START 0x027FFE00 /* header chunk window, MB_WINDOW_HEADER_SIZE bytes */
#define MB_WINDOW_HEADER_SIZE  0x160
#define MB_WINDOW_HEADER_END   0x027FFF60 /* one past the header chunk window */
#define MB_WINDOW_RAM_START    0x02000000 /* start of main RAM */
#define MB_WINDOW_RAM_LOW_END  0x022C0000 /* end of the first main RAM window */
#define MB_WINDOW_RAM_END      0x02300000 /* end of the main RAM the low window may be extended into */
#define MB_WINDOW_RAM_HIGH_END 0x023FE800 /* end of the main RAM a tail block may reach */
#define MB_WINDOW_EXT_START    0x037F8000 /* start of the second address window */
#define MB_WINDOW_EXT_END      0x0380F000 /* one past the second address window */

/* One multiboot member's chunk transfer: the next block to send, where it goes in
 * the member's memory and which program chunk it belongs to. */
typedef struct MbChunkTransfer {
    u32 dest;   /* +0x00 destination address in the member's memory */
    u32 size;   /* +0x04 bytes to send from that block on */
    u32 source; /* +0x08 offset of the block in the download image */
    u8  chunk;  /* +0x0C chunk index (low byte of the word the sender reads) */
} MbChunkTransfer;

/* Assembly of the per-player info records received during multiboot match setup:
 * each 30-byte record (player id, info block, group) is sent in command-7 packets
 * carrying numbered fragments, and reassembled into one slot per player. */
#define MB_RECORD_SIZE      0x1E  /* bytes in a finished player record */
#define MB_RECORD_SLOT      0x20  /* bytes per player slot in the assembly buffer */
#define MB_RECORD_MASK      0x1E0 /* byte offset of the per-player received-fragment bitmasks */
typedef struct MbRecordRx {
    u32 unk00;         /* +0x00 never read */
    u8 *buffer;        /* +0x04 player slots, MB_RECORD_SLOT bytes each */
    s32 fragmentSize;  /* +0x08 payload bytes carried by one fragment */
    s32 fragmentCount; /* +0x0C fragments that make up a full record */
    s32 recordSize;    /* +0x10 bytes per record */
} MbRecordRx;
/* The receive state itself is declared `extern M2C_UNK gMbRecordRx;` locally by
 * each user; access its fields through this. */
#define MB_RECORD_RX ((MbRecordRx *)&gMbRecordRx)

/* A GPI player-info result (the buffer handed to a gpiGetInfo callback). */
#define GPI_INFO_STATUS    0x00 /* s32 0 = ok, nonzero = error/status */
#define GPI_INFO_PLAYER_ID 0x04 /* s32 player/profile id */
#define GPI_INFO_NAS_ID    0x8E /* char[] NAS id as text */

/* States of the WFC match-making session (gNetSession + 0x24). */
enum {
    NET_STATE_OFFLINE  = 0, /* session has not logged in */
    NET_STATE_CHECKING_SERVICE = 1, /* checking service availability before login */
    NET_STATE_READY    = 3, /* idle in the lobby: a match can be started */
    NET_STATE_STARTING = 5, /* a match is being set up */
    NET_STATE_MATCH    = 6  /* the match is running */
};

/* Global network error record (gNetError): the error code and its parameter.
 * Code 9 is fatal: it is never overwritten nor cleared. */
typedef struct NetError {
    s32 code;   /* +0x00 0 = no error */
    s32 detail; /* +0x04 error parameter */
} NetError;

/* Step flags of the ov010 online session (gOv010OnlineSession+0x54): their bit
 * index is what SetOnlineSessionFlag/IsOnlineSessionFlagSet take. */
#define OV010_FLAG_STARTED 0 /* the session's work block is allocated */
#define OV010_FLAG_RUNNING 3 /* the online session is running (cleared when it stops or its start fails) */
#define OV010_FLAG_FAILED  4 /* the session start failed or the session stopped */
#define OV010_FLAG_ERROR   6 /* a network error has been handed to the UI, so it is not reported again */

/* A match player's info record (0x210 bytes), filled by gpGetBuddyStatus from
 * the GameSpy buddy list (gp.c's GPBuddyStatus). The key/value string holds the
 * player's fields, e.g. "SCM=1/SCN=2/". */
typedef struct MatchPlayerInfo {
    s32 profileId;     /* +0x00 the buddy's GameSpy profile id */
    s32 status;        /* +0x04 6 = a valid player record */
    u8  fields[0x100]; /* +0x08 key/value status string */
    u8  name[0x100];   /* +0x108 location/display name */
    u32 ipAddr;        /* +0x208 advertised IPv4 address */
    s32 port;          /* +0x20C advertised port */
} MatchPlayerInfo;     /* 0x210 bytes */

/* A GameSpy buddy-list record (keyed by profile id) and its details: the
 * buddy's position in the list, presence status, two owned strings and the
 * advertised address. Built by gpiBuddy.c, read by gpGetBuddyStatus. */
typedef struct GpiBuddyStatusDetails {
    s32  index;          /* +0x00 position in the buddy list */
    s32  status;         /* +0x04 presence status */
    s8  *statusString;   /* +0x08 owned key/value status string */
    s8  *locationString; /* +0x0C owned location string */
    u32  ipAddr;         /* +0x10 advertised IPv4 address */
    s32  port;           /* +0x14 advertised port */
} GpiBuddyStatusDetails;

typedef struct GpiBuddyStatus {
    s32 profileId;                  /* +0x00 the buddy's profile id (the table key) */
    s32 unk04;                      /* +0x04 */
    GpiBuddyStatusDetails *details; /* +0x08 presence and address, NULL once released */
    void *cachedInfo;               /* +0x0C cached profile info (GPI_INFO_RESULT_WORDS words) */
    s8  *signature;                 /* +0x10 owned status signature */
    s32  useCount;                  /* +0x14 operations still holding the record */
    s8  *unk18;                     /* +0x18 owned string */
} GpiBuddyStatus;

/* GpiBuddyStatus field offsets, for the code that reaches the record through a
 * raw pointer. */
#define GPI_BUDDY_DETAILS     0x08
#define GPI_BUDDY_CACHED_INFO 0x0C
#define GPI_BUDDY_SIGNATURE   0x10
#define GPI_BUDDY_USE_COUNT   0x14
#define GPI_BUDDY_UNK18       0x18

/* GpiBuddyStatusDetails field offsets (the two owned strings). */
#define GPI_BUDDY_STATUS_STRING   0x08
#define GPI_BUDDY_LOCATION_STRING 0x0C

/* While set, a released buddy-status record keeps its presence details instead
 * of dropping them, so the details alone can keep the record in the table. */
#define GPI_CONN_KEEP_BUDDY_DETAILS 0x104

/* The voice-chat ("VCHT") option menu entity (main_020E0194): the option row
 * that starts selected and the widget sprites the setup creates. */
#define VCHT_MENU_SELECTED_ROW 0x3C /* s32 id of the row the toggle starts on */
#define VCHT_MENU_FLAGS        0x48 /* u16: VCHT_FLAG_* */
#define VCHT_MENU_TOGGLE0      0x50 /* void *first toggle-option widget */
#define VCHT_MENU_TOGGLE1      0x58 /* void *second toggle-option widget */
#define VCHT_MENU_LABEL        0x64 /* void *the option's label text */
#define VCHT_MENU_ANIM         0x68 /* void *the option's animation widget */

/* VCHT_MENU_FLAGS bits. */
#define VCHT_FLAG_CONFIRMED 0x0008 /* the option was confirmed; the update waits on it */
#define VCHT_FLAG_BUILDING  0x0020 /* the menu was just built; the next update clears it */
#define VCHT_FLAG_OVERLAY   0x1000 /* the link overlay event the shared update records */

/* The local player's link status (GetLocalPlayerStatus): its option bits. */
#define LOCAL_STATUS_OPTIONS    0x1A /* u8 option bits the link menus edit */
#define LOCAL_OPTION_VOICE_CHAT 0x04 /* voice chat is on */

/* Per-slot peer record (gPlayerPeers[slot], 8 bytes): the connection slot the
 * player came in on and the peer id assigned to it in the match. */
typedef struct PlayerPeer {
    u8  slot;   /* +0x00 connection slot */
    u8  peerId; /* +0x01 peer id within the match */
    u16 unk02;  /* +0x02 */
    s32 unk04;  /* +0x04 */
} PlayerPeer;   /* 8 bytes */

/* Sprite state of the ov001 menu screen's region selector: one object plus two
 * rows of three item sprites. column remembers which column the selection came
 * from so the wide bar (region 3) can return to it. */
typedef struct Ov001MenuSprites {
    void *obj;        /* +0x00 */
    void *top[3];     /* +0x04 top-row item sprites */
    void *middle[3];  /* +0x10 middle-row item sprites */
    u8   column;      /* +0x1C last column of the two rows */
    u8   mode;        /* +0x1D 1 = item chosen, 2 = cancel */
} Ov001MenuSprites;

/* The ov001 menu screen's selection state (gOv001MenuRegion): the selected
 * region (0..6, the touch rectangles are at data_ov001_0218fa02) and its
 * sprite state. */
typedef struct Ov001MenuRegion {
    u8 index;             /* +0x00 selected region */
    u8 pad01[3];
    Ov001MenuSprites *sprites; /* +0x04 */
} Ov001MenuRegion;

/* Directions passed to Ov001_MoveMenuRegion. */
enum {
    OV001_DIR_LEFT  = 0,
    OV001_DIR_UP    = 1,
    OV001_DIR_RIGHT = 2,
    OV001_DIR_DOWN  = 3
};

/* The ov001 save data (gSaveData, 0x6f8 bytes): four 0x100-byte save slots from
 * +0 and the working copy of the current slot at +0x400.  Name data lives at the
 * same slot-relative offsets the StorePlayerName helper uses on the working slot. */
 #define SAVE_PLAYER_NAMES   0x480 /* four 16-byte player-name fields in the working slot */
 #define SAVE_NAME_SIZE      0x10  /* bytes per stored name */
 #define SAVE_NAME_TEXT_MAX  0x20  /* longest name text accepted (hex or raw) */
 #define SAVE_NAME_FLAGS     0x4e6 /* u8: low 2 bits name-length class, high bits flags */
 #define SAVE_NAME_MODE_MASK 0x03  /* name-length class (0, 5, 13 or 16 bytes) */
 #define SAVE_NAME_RAW       0x04  /* name was copied raw instead of hex-decoded */
 #define SAVE_NAME_FLAGS_MASK 0xfc /* remaining flag bits */

 /* The rest of the working save slot (gSaveData + SAVE_WORK_SLOT).  The slot's
  * own fields are at these offsets; +0x4f0..+0x4ff exist only in the working
  * copy, the card slot stores a bit count of the code there instead. */
 #define SAVE_WORK_SLOT      0x400 /* the 0x100-byte working copy of the current slot */
 #define SAVE_MAP_NAME       0x440 /* u8[32]: the saved match's map name text */
 #define SAVE_PLAYER_CODES   0x4c0 /* four 4-byte dotted values, one per player */
 #define SAVE_CODE_BITS      0x4d0 /* u8: set-bit count of the slot's code */
 #define SAVE_CO_NAMES       0x4d1 /* four 5-byte CO-name fields */
 #define SAVE_SLOT_STATUS    0x4e7 /* u8: slot status (1/2 written, 0xFF erased) */
 #define SAVE_CODE           0x4f0 /* 4-byte dotted map/verification code (working copy only) */
 #define SAVE_SLOT_INDEX     0x4f4 /* u8: physical slot the working copy belongs to */
 #define SAVE_EXTRA_EMPTY_A  0x4f5 /* u8: the +0xc0/+0xc4 codes are absent (cleared on commit) */
 #define SAVE_EXTRA_EMPTY_B  0x4f6 /* u8: the +0xc8/+0xcc codes are absent (cleared on commit) */
#define SAVE_SLOT_SIZE         0x100 /* bytes per physical save slot image */
#define SAVE_SLOT_STATUS_REL   0xE7  /* slot-relative SAVE_SLOT_STATUS: 1/2 written, 0xFF erased */
#define SAVE_SLOT_PROFILE_CODE_SIZE 14 /* bytes of the local Wi-Fi profile code stored at SAVE_SLOT_CODE */
#define SAVE_SLOT_PLAYER_CODES 0xC0 /* offset within one 0x100-byte slot image of the player-code fields */
#define SAVE_SLOT_CODE_BITS    0xD0 /* offset within one slot image of the SAVE_CODE_BITS byte */
#define SAVE_SLOT_CODE         0xF0 /* offset within one slot image of the SAVE_CODE word (working copy only) */
#define SAVE_SLOT_INDEX_REL    0xF4 /* offset within one slot image of SAVE_SLOT_INDEX */
#define SAVE_SLOT_EMPTY_A      0xF5 /* offset within one slot image of SAVE_EXTRA_EMPTY_A */
#define SAVE_SLOT_EMPTY_B      0xF6 /* offset within one slot image of SAVE_EXTRA_EMPTY_B */

 /* The link-match setup sent before a saved battle (the 0xE8-byte state that
  * Ov001_CopyLinkMatchSetup copies out of the receive buffer): the map name, the
  * name-length class shared by the four player names, and the name texts. */
 #define MATCH_SETUP_MAP_NAME   0x00 /* u8[32]: map name text */
 #define MATCH_SETUP_NAME_CLASS 0x20 /* s32: 1 = 5, 2 = 13, 3 = 16 bytes per name */
 #define MATCH_SETUP_NAMES      0x28 /* u8[4][32]: player name texts */

/* The card battle-save block (SAVE_BLOCK_SIZE bytes): a magic word, then 60
 * 12-byte slot summaries and 60 40-byte slot records.  The save manager scans
 * SAVE_RECORD_STRIDE-byte directory records to find the newest one of a type. */
#define SAVE_BLOCK_MAGIC        0x07090600 /* first word of an initialised save block */
#define SAVE_BLOCK_SIZE         0xC34      /* bytes of a complete battle save */

/* The local player's profile save block (the object main_020C3D34's
 * func_020c4acc returns): the save magic, a 0x40-byte profile-id block and then
 * the profile's own fields. */
#define PROFILE_ID_BLOCK      0x04 /* 0x40-byte profile-id block (func_020321ac) */
#define PROFILE_ID_BLOCK_SIZE 0x40
#define SAVE_SLOT_COUNT         60         /* slot summaries/records in a block */
#define SAVE_SLOT_SUMMARY_SIZE  12         /* bytes per slot summary */
#define SAVE_SLOT_RECORD_SIZE   0x28       /* bytes per slot record */
#define SAVE_SUMMARIES_OFFSET   4          /* first slot summary */
#define SAVE_RECORDS_OFFSET     0x2d4      /* first slot record */
#define SAVE_RECORD_STRIDE      0x28       /* bytes per save-directory record */
#define SAVE_RECORD_ID          0          /* u16 slot id inside a directory record */
#define SAVE_RECORD_TYPE        2          /* u8 save type inside a directory record */
#define SAVE_RECORD_TIME        4          /* u32 timestamp inside a directory record */
#define SAVE_TYPE_PLAYER        2          /* player/profile save */
#define SAVE_TYPE_BATTLE        3          /* battle save */
#define SAVE_TYPE_CAMPAIGN_MAP  9          /* campaign map index 0; record type = 9 + map index */

/* A battle save record: eight bytes kept per save slot (slots 5..8, see
 * GetBattleSaveRecord) describing the last battle fought there. */
#define BATTLE_RECORD_SIZE  0x08 /* bytes per battle save record */
#define BATTLE_RECORD_MAP   0x00 /* u16: map id the battle was fought on, 0 when the slot is empty */
#define BATTLE_RECORD_DAYS  0x02 /* u16: days the battle lasted (gCurrentMap +0x52a2, capped at 999) */
#define BATTLE_RECORD_DATE  0x04 /* u32: local date/time, year:8 month:6 day:6 hour:6 minute:6 */

/* Save-chip configuration the save manager asks the device for before it reads
 * the archive: the chip kind in the low byte and the size/variant bit index in
 * bits 8..15 (0x1202 = kind 2, bit 18).  The device must report state 2 after. */
#define SAVE_DEVICE_CONFIG      0x1202
#define SAVE_DEVICE_STATE_READY 2      /* SaveDevice_GetState result once configured */

/* Kinds of 4-byte connection notice sent by SendConnectionPacket(kind, slot). */
enum {
    CONN_NOTICE_PLAYER_SLOT = 2, /* claim a player slot (last-player flag, slot, id) */
    CONN_NOTICE_SYNC_STATUS = 3, /* report own slot and measured latency */
    CONN_NOTICE_SYNC_DONE   = 4  /* the sync is finished */
};

/* Frame table of one map info window icon: the animation the icon plays. */
typedef struct MapInfoIconFrames {
    s8 first;        /* +0x00 first tile */
    u8 unk01;        /* +0x01 */
    u16 start;       /* +0x02 */
    u16 end;         /* +0x04 */
    s16 unk06;       /* +0x06 */
    s16 unk08;       /* +0x08 */
    s16 unk0A;       /* +0x0A */
    s16 unk0C;       /* +0x0C */
    s16 unk0E;       /* +0x0E */
    s16 unk10;       /* +0x10 */
} MapInfoIconFrames; /* 0x12 bytes */

/* One icon of the map info window (an icon animation object). */
typedef struct MapInfoIcon {
    MapInfoIconFrames *frames; /* +0x00 */
    void *anim;                /* +0x04 animation descriptor */
    void *vtable;              /* +0x08 */
    s16 frame;                 /* +0x0C current frame */
    u8 unk0E;                  /* +0x0E */
    u8 unk0F;                  /* +0x0F */
} MapInfoIcon;                 /* 0x10 bytes */

/* ov000 map info window: a UI node describing the army of the player whose
 * turn it is, with a unit-stat panel and seven icon animations. */
typedef struct MapInfoWindow {
    void *vtable;          /* +0x00 */
    u8 pad04[0x30];
    s16 timer;             /* +0x34 frame timer */
    u8 visible;            /* +0x36 */
    u8 pad37;              /* +0x37 */
    s16 scroll;            /* +0x38 scroll position (see func_ov000_0216b898) */
    u8 player;             /* +0x3A player the window describes */
    u8 armyState;          /* +0x3B that player's army state */
    s8 colorIndex;         /* +0x3C armour colour index, 0-based */
    u8 detailed;           /* +0x3D draw the detailed layout */
    s16 animTime;          /* +0x3E */
    void *panel;           /* +0x40 unit-stat panel */
    MapInfoIcon *icons[7]; /* +0x44..+0x5C icon animations */
} MapInfoWindow;

/* ov010 wireless-link voice channel state: three 0x94-byte records, one per
 * channel, in the ov010 link channel table. A channel pulls packets from a
 * queue and plays them back against a smoothed clock. */
typedef struct LinkChannelState {
    u32 clock;        /* +0x00 smoothed playback clock */
    u8 pad04[4];
    s32 backlog;      /* +0x08 packets left when a pull found nothing */
    u8 pad0c[8];
    s32 skipped;      /* +0x14 packets skipped over a sequence gap */
    u8 pad18[8];
    s32 played;       /* +0x20 packets played while catching up */
    u8 pad24[4];
    u32 lastTime;     /* +0x28 time the last packet was pulled */
    u32 smoothTime;   /* +0x2C smoothed time */
    u8 pad30[4];
    s32 index;        /* +0x34 queue index of this channel */
    s32 id;           /* +0x38 channel id this state belongs to */
    void *current;    /* +0x3C packet currently being played */
    u8 pad40[0x18];
    u32 lastSeq;      /* +0x58 sequence number of the last packet */
    u8 pad5c[0x14];
    s32 hold;         /* +0x70 packets still to hold back */
} LinkChannelState;   /* 0x94 bytes */

#define LINK_CHANNEL_STRIDE 0x94
#define LINK_CHANNEL_COUNT  3

/* Fields of a link packet buffer while it sits in a channel's packet queue (the
 * Link_* queue helpers): the doubly-linked list links and the ordering key. */
#define LINK_PACKET_PREV 0x04 /* void *previous packet in the queue */
#define LINK_PACKET_NEXT 0x08 /* void *next packet in the queue */
#define LINK_PACKET_KEY  0x18 /* u32 ordering key the queue is kept sorted by */

/* ov007 map editor text entry. The widget keeps a glyph layout table of three
 * blocks of MAPEDIT_GLYPH_COUNT entries: the base glyphs, then their voiced
 * (dakuten) and semi-voiced (handakuten) forms. The line being edited is
 * MAPEDIT_LINE_LENGTH glyph slots long. */
#define MAPEDIT_TEXT_LAYOUT       0x34  /* u32 **glyph layout: 3 blocks of 75 */
#define MAPEDIT_TEXT_INDEX        0x3c  /* s8 cursor into the current line */
#define MAPEDIT_LINE_LENGTH       17    /* u32 glyphs in gMapEditObjectList */
#define MAPEDIT_GLYPH_COUNT       75    /* entries per layout block */
#define MAPEDIT_DAKUTEN_VARIANTS  0x12c /* byte offset of the voiced block */
#define MAPEDIT_HANDAKUTEN_VARIANTS 0x258 /* byte offset of the semi-voiced block */

/* One cell template of the map editor's glyph keyboard: the offset and size a
 * cell gets plus the fields copied into its sprite slot, and the handlers run
 * for it.  The glyph layout uses one template per key. */
typedef struct EditorCellDesc {
    s16 offsetX;     /* +0x00 added to the cell's x */
    s16 offsetY;     /* +0x02 added to the cell's y */
    s16 width;       /* +0x04 sprite width, also the per-column x step */
    s16 height;      /* +0x06 sprite height, also the per-row y step */
    s16 unk08;       /* +0x08 */
    s16 unk0A;       /* +0x0A */
    s16 unk0C;       /* +0x0C */
    s16 unk0E;       /* +0x0E */
    void *handler10; /* +0x10 */
    void *handler14; /* +0x14 */
    void *handler18; /* +0x18 */
    void *handler1C; /* +0x1C */
    void *handler20; /* +0x20 */
    void *handler24; /* +0x24 */
} EditorCellDesc;    /* 0x28 bytes */

/* One field of an RSA key: a big-endian byte string and its length. */
typedef struct RsaKeyPart {
    s32 length;    /* +0x00 number of bytes in bytes[] */
    u8 *bytes;     /* +0x04 big-endian value */
} RsaKeyPart;

/* RSA key in CRT form, used by the TLS handshake code. The fields are the modulus n, the primes
 * p and q, the private exponents dP = d mod (p-1) and dQ = d mod (q-1), and qInv = q^-1 mod p. */
typedef struct RsaCrtKey {
    RsaKeyPart modulus; /* +0x00 n */
    RsaKeyPart p;       /* +0x08 */
    RsaKeyPart q;       /* +0x10 */
    RsaKeyPart dP;      /* +0x18 */
    RsaKeyPart dQ;      /* +0x20 */
    RsaKeyPart qInv;    /* +0x28 */
} RsaCrtKey;

/* Length of the decrypted RSA block (the TLS premaster secret). */
#define RSA_PREMASTER_LEN 0x30

/* Named RSA public key from the TLS handshake's key list (see func_02022128): the peer's
 * ServerKeyExchange carries the name that selects one, and a signature is verified by
 * exponentiating it with exponent modulo modulus. */
typedef struct NamedRsaKey {
    char *name;         /* +0x00 name sent with the handshake */
    s32 modulusLength;  /* +0x04 bytes in modulus[] */
    u8 *modulus;        /* +0x08 n, big-endian */
    s32 exponentLength; /* +0x0c bytes in exponent[] */
    u8 *exponent;       /* +0x10 e, big-endian */
} NamedRsaKey;

/* TLS handshake fields used by the signature verification. */
#define TLS_DIGEST        0x468 /* u8[] hash of the handshake message that was signed */
#define TLS_DIGEST_LEN    0x47c /* s32 bytes written to TLS_DIGEST */
#define TLS_SIGNATURE     0x5a4 /* u8 * signature bytes of the handshake message */
#define TLS_SIGNATURE_LEN 0x5a8 /* s32 bytes in TLS_SIGNATURE */
#define TLS_CERT_SIGNATURE_ALGORITHM 0x458 /* s32 OID index of the certificate's signature algorithm: 3 md5WithRSA, 4 sha1WithRSA */
#define TLS_CERT_KEY_ALGORITHM 0x45c /* s32 OID index of the certificate's public key algorithm, -1 when none was parsed */
#define TLS_SIGNED_MESSAGE_START 0x460 /* u8 * first handshake message the certificate's signature covers */
#define TLS_SIGNED_MESSAGE_END 0x464 /* u8 * end of those handshake messages */
#define TLS_ISSUER_NAME    0x5b0 /* char[] name of the key that signed the certificate */
#define TLS_CERT_DATE_VALID 0x5af /* u8 nonzero while the certificate's date range contains the console's date */

/* What the certificate check reports (the low bits; 0 = the chain checks out). */
#define TLS_CERT_CHECK_DATE        0x8000 /* the certificate is not valid at the console's date */
#define TLS_CERT_CHECK_NO_SIGNATURE 1     /* the issuer's key is unknown */
#define TLS_CERT_CHECK_BAD_SIGNATURE 2    /* the signature does not verify */
#define TLS_CERT_CHECK_UNSUPPORTED  3     /* the digest algorithm is not supported */
#define TLS_CERT_CHECK_NO_KEY       4     /* the certificate carries no RSA key algorithm */

/* On-screen keyboard of the ov001 name-entry screen; gOv001MenuState points at one.  The 47
 * character keys of a page are followed by two page toggles, space, delete and the two actions. */
typedef struct Ov001KeyboardState {
    u8 pad00[0x11C];
    u8 key;          /* +0x11C character/action produced by the last press, 0xFF = none */
    u8 page;         /* +0x11D layout shown: 0 lowercase, 1 symbols, 2 uppercase */
    s8 touchKey;     /* +0x11E key under the stylus, -1 = none */
    u8 pad11F;
    s8 prevKey;      /* +0x120 key the cursor came from */
    s8 selectedKey;  /* +0x121 highlighted key, 0..52 */
    u8 deleteRepeat; /* +0x122 auto-repeat counter of the delete key */
    u8 canDelete;    /* +0x123 delete key enabled (text not empty) */
    u8 canAdd;       /* +0x124 character keys enabled (text not full) */
    u8 deleteBuzzed; /* +0x125 invalid-delete buzz already played while B is held */
} Ov001KeyboardState;

/* The two-bar icon row shared by the ov001 screens (gOv001IconRow): each page
 * id picks the pair of wide bar sprites that slide in; tapping a bar selects it
 * for a moment before the row restores itself. */
typedef struct Ov001IconRow {
    void *bars[2];    /* +0x00 the two option bar sprites */
    void *backdrop;   /* +0x08 wide background bar sprite */
    s32 introTimer;   /* +0x0C timer staging the slide-in */
    s32 selectTimer;  /* +0x10 timer that ends a touch selection */
    u16 introDelay;   /* +0x14 frames of the intro still to run */
    s8 selected;      /* +0x16 selected bar, -1 none, -2 not ready */
    u8 page;          /* +0x17 page id, indexes the icon-row tables */
    u8 inputLocked;   /* +0x18 nonzero: the row is moving, touch is ignored */
    u8 active;        /* +0x19 nonzero once the row is in use */
} Ov001IconRow;

/* Wi-Fi connection indicator of an ov001 screen (gOv001WfcIcon): a single
 * sprite that shows one of the four status layouts of its style and is
 * relaid out each frame from the WFC connection state. */
typedef struct Ov001WfcIcon {
    void *sprite; /* +0x00 sprite object showing the icon */
    s32 task;     /* +0x04 update task, 0 when none */
    s8 style;     /* +0x08 icon style, indexes gOv001WfcIconLayouts */
} Ov001WfcIcon;   /* 0x0C bytes */

/* Blend control registers the ov001 screen fades write: the main engine's and
 * the sub engine's BLDCNT, with BLDY at +4. */
#define GX_BLDCNT_MAIN 0x04000050
#define GX_BLDCNT_SUB  0x04001050

/* Window range registers of the main engine; the sub engine's sit at +0x1000.
 * WIN0 and WIN1 each have a horizontal and a vertical range, packed as high
 * byte = first edge, low byte = second edge. */
#define GX_WIN0H_MAIN 0x04000040
#define GX_WIN0V_MAIN 0x04000042
#define GX_WIN1H_MAIN 0x04000044
#define GX_WIN1V_MAIN 0x04000046
#define GX_WIN0H_SUB  0x04001040
#define GX_WIN0V_SUB  0x04001042
#define GX_WIN1H_SUB  0x04001044
#define GX_WIN1V_SUB  0x04001046

/* The ov001 screen-fade system (gOv001FadeStates points at two Ov001Fade, the
 * sub engine's then the main engine's). A fade task maps frames 0..duration to a
 * BLDY blend value; gOv001FadeTable holds the four fade modes as three parallel
 * arrays. A negative blend value makes GX_SetBlendY fade through the backdrop. */
#define OV001_FADE_MODE_COUNT  4
#define OV001_FADE_END_BLEND   0x0 /* s8[end] BLDY value once the fade completes */
#define OV001_FADE_FLAGS       0x4 /* u8[end] OV001_FADE_* direction flags */
#define OV001_FADE_START_BLEND 0x8 /* s8[end] BLDY value the fade starts from */

/* A fade mode's flags (gOv001FadeTable + OV001_FADE_FLAGS + mode). */
enum {
    OV001_FADE_INVERT = 0x01, /* value = 16 - ramp, so 16 fades down to 0 */
    OV001_FADE_NEGATE = 0x10  /* value = -value, fading through the backdrop */
};

/* One running screen fade (Ov001FadeStates::sub / ::main). */
typedef struct Ov001Fade {
    s32 task;      /* +0x00 task created for the fade, 0 when idle */
    s16 counter;   /* +0x04 frames elapsed */
    u16 duration;  /* +0x06 frames the fade runs */
    u8  mode;      /* +0x08 index into gOv001FadeTable, 0..3 */
    u8  active;    /* +0x09 nonzero while the fade runs */
    u8  pad0A[2];  /* +0x0A */
} Ov001Fade;       /* 0x0C bytes */

typedef struct Ov001FadeStates {
    Ov001Fade sub;  /* +0x00 fades the sub engine (GX_BLDCNT_SUB) */
    Ov001Fade main; /* +0x0C fades the main engine (GX_BLDCNT_MAIN) */
} Ov001FadeStates; /* 0x18 bytes */

/* State of the ov001 name-entry screen (gNameEntryState): its entered text and
 * the position word of its cursor sprite. */
#define NAME_ENTRY_PANEL   0x00 /* text panel that draws the entered text */
#define NAME_ENTRY_CURSOR  0x04 /* s32 * cursor sprite's position/attribute word */
#define NAME_ENTRY_TEXT    0x08 /* u8[33] entered text, NUL-terminated */
#define NAME_ENTRY_MAX_LENGTH 32 /* u8 characters that fit in NAME_ENTRY_TEXT (plus its NUL) */
#define NAME_ENTRY_LENGTH  0x29 /* u8 number of characters entered */
#define NAME_ENTRY_RESULT  0x2a /* u8 result: 0 cancelled, 1 accepted, 2 rejected */
#define NAME_ENTRY_CURSOR_MASK 0xC1FFFCFF /* cursor attribute bits a cancelled entry clears */

/* The name-entry screen's configuration (gOv001NameEntryConfig), one entry per
 * entry mode: the message panel shown while typing, the message shown once the
 * name is accepted, and the handler that stores it. */
#define NAME_ENTRY_CONFIG_MESSAGE_PANEL 0x00 /* u8[2] message panel id per mode */
#define NAME_ENTRY_CONFIG_RESULT_MESSAGE 0x08 /* s32[2] message id shown on acceptance, per mode */
#define NAME_ENTRY_CONFIG_ACCEPT        0x10 /* void (*[2])(u8 *text) stores the accepted name */

/* State of the ov001 friend-code entry screen (gOv001FriendCodeState): the four
 * 3-digit groups of the code being entered, the group being edited and the
 * result of the region menu that asks which saved code the entry replaces. */
#define CODE_ENTRY_PANEL       0x00 /* text panel that draws the code */
#define CODE_ENTRY_CURSOR      0x04 /* s32 * cursor sprite's position/attribute word */
#define CODE_ENTRY_TEXT        0x08 /* u8[12] four 3-character groups of the code */
#define CODE_ENTRY_GROUPS      4    /* groups in CODE_ENTRY_TEXT */
#define CODE_ENTRY_GROUP_SIZE  3    /* characters per group */
#define CODE_ENTRY_GROUP       0x14 /* u8 group being edited, 0..3 */
#define CODE_ENTRY_RESULT      0x15 /* u8 result: 0 cancelled, 1 accepted, 2 rejected */

/* Cursor sprite attribute bits a cancelled code entry clears. */
#define CODE_ENTRY_CURSOR_MASK 0xC1FFFCFF

/* Non-printing characters the on-screen keyboard produces. */
enum {
    KBD_KEY_DELETE = 0x80,
    KBD_KEY_CANCEL = 0x82,
    KBD_KEY_OK     = 0x83,
    KBD_KEY_SPACE  = 0xE01D /* glyph id the space key produces */
};

/* On-screen keyboard key layout: 47 character keys, then space and delete,
 * then the two bottom action keys. */
#define KBD_CHAR_KEY_COUNT 0x2F /* character keys on a page */
#define KBD_DELETE_INDEX   0x32 /* index of the delete key */
#define KBD_ACTION_KEY_BASE 0x33 /* index of the first bottom action key */

/* Delete-key auto-repeat: repeat after this many frames, dropping the counter
 * by this much per repeat. */
#define KBD_DELETE_REPEAT_DELAY 0x28
#define KBD_DELETE_REPEAT_STEP  7

/* A menu sprite object, as animated by MenuSpriteUpdate.  The current frame is
 * held in bits 18..25 of the word at +0x40, the base frame in the low nibble at
 * +0x59 and +0x5a is the press timer (negative while the press animation is
 * done). +0x64 points at the object that owns the sprite. */
#define MENU_SPRITE_FRAME 0x40 /* u32 frame bits */
#define MENU_SPRITE_BASE  0x59 /* u8 low nibble: base frame */
#define MENU_SPRITE_TIMER 0x5a /* s8 press timer, -1 = idle */
#define MENU_SPRITE_OWNER 0x64 /* owner/controller object */

/* Position and slide-animation fields of the 3D sprite actor animated by
 * UpdateSpriteSlide: a current position, a slide origin and target, and a state
 * byte that also holds the visible bit and the fade mode. */
#define SPRITE_ACTOR_X           0x34 /* s16 current x */
#define SPRITE_ACTOR_Y           0x36 /* s16 current y */
#define SPRITE_ACTOR_STATE       0x48 /* u8: bit 0 visible, bits 4-5 fade mode, bits 6-7 slide mode */
#define SPRITE_ACTOR_SLIDE_TIMER 0x4c /* u8 frames since the slide started */
#define SPRITE_ACTOR_SLIDE_DELAY 0x4d /* u8 frames still to wait before sliding */
#define SPRITE_ACTOR_SLIDE_LEN   0x4e /* u8 slide length in frames */
#define SPRITE_ACTOR_SLIDE_BACK_LEN 0x4f /* u8 length of the reverse slide */
#define SPRITE_ACTOR_TARGET_X    0x50 /* s16 slide destination x */
#define SPRITE_ACTOR_TARGET_Y    0x52 /* s16 slide destination y */
#define SPRITE_ACTOR_START_X     0x54 /* s16 slide origin x */
#define SPRITE_ACTOR_START_Y     0x56 /* s16 slide origin y */
#define SPRITE_ACTOR_SPLIT       0x40 /* u32 bits 26..31: row where the cell grid is split in halves (16 = whole sprite) */
#define SPRITE_ACTOR_PRIORITY    0x49 /* u8 OBJ priority passed to AddSprite */
#define SPRITE_ACTOR_TILE_ROW    0x3e /* u16 texture row the actor draws */
#define SPRITE_ACTOR_TEXT_WIDTH  0x58 /* s16 width in pixels of the text the actor drew */

/* A scene panel: a 3D sprite actor whose two halves (the sprite sources at
 * +0x60 and +0x64) show a pair of CO faces.  The face sprites themselves are its
 * two children (reached through Get3DSpriteChild). */
#define SCENE_PANEL_FLIP       0x58 /* u8 nonzero: swap the two face children */
#define SCENE_PANEL_FACE_STATE 0x59 /* u8 face display state (0 none, 5..10 the pose layouts) */
#define SCENE_PANEL_LAYOUT     0x5a /* u8 face layout index */
#define SCENE_PANEL_MOTION     0x5b /* u8 motion variant: 1 offsets x, 2 offsets y */
#define SCENE_PANEL_MOTION_X   0x5c /* s16 x the motion offset applies to */
#define SCENE_PANEL_MOTION_Y   0x5e /* s16 y the motion offset applies to */
#define SCENE_PANEL_HALF0      0x60 /* void *sprite source of the first half */
#define SCENE_PANEL_HALF1      0x64 /* void *sprite source of the second half */

/* Slide mode (SPRITE_ACTOR_STATE bits 6-7). */
enum {
    SPRITE_SLIDE_NONE    = 0,
    SPRITE_SLIDE_FORWARD = 1, /* slide from the origin to the target */
    SPRITE_SLIDE_SHOW    = 2, /* the same, showing the sprite when it starts */
    SPRITE_SLIDE_REVERSE = 3  /* slide back to the origin, hiding the sprite when it arrives */
};

/* Work area of the movement flood fill (gMoveSearchState).  It starts with a
 * 32-entry terrain cost table, then the search limits, then two ping-pong
 * queues of 4-byte nodes (x, y, direction, accumulated cost). */
typedef struct MoveSearchNode {
    u8 x;      /* +0x00 */
    u8 y;      /* +0x01 */
    u8 dir;    /* +0x02 direction taken to reach the tile, 1 = start */
    u8 cost;   /* +0x03 accumulated movement cost */
} MoveSearchNode; /* 4 bytes */

/* MoveSearchNode::dir: the move that reached the tile. Expansion skips the
 * reverse of the direction it arrived by; the seed expands all four. */
enum {
    MOVE_SEARCH_DIR_START = 1,
    MOVE_SEARCH_DIR_UP    = 2,
    MOVE_SEARCH_DIR_DOWN  = 3,
    MOVE_SEARCH_DIR_LEFT  = 4,
    MOVE_SEARCH_DIR_RIGHT = 5
};

/* The low bits of MOVE_SEARCH_MOVE_RANGE double as this flood fill's behaviour
 * flags, read by func_01ffb114 (which units and terrains may be passed). */

#define MOVE_SEARCH_TERRAIN_COST 0x00 /* s8[32] movement cost per terrain kind */
#define MOVE_SEARCH_COST_LIMIT   0x20 /* s16 accumulated-cost limit */
#define MOVE_SEARCH_MOVE_RANGE   0x22 /* s16 unit move range (movement points) */
#define MOVE_SEARCH_WIDTH        0x24 /* u8 map width, filled by SelectMapLayer */
#define MOVE_SEARCH_HEIGHT       0x25 /* u8 map height, filled by SelectMapLayer */
#define MOVE_SEARCH_MOVEMENT_TYPE 0x26 /* u8 movement type the search is for */
#define MOVE_SEARCH_QUEUE_A      0x28 /* MoveSearchNode[349] */
#define MOVE_SEARCH_QUEUE_B      0x5A0 /* MoveSearchNode[349] */
#define MOVE_SEARCH_QUEUE_MAX    349

/* The pending move path of the unit under the cursor (gUnitMovePath): up to 12
 * steps on the cell grid, step 0 being the unit's own tile.  An s8 length of 0
 * means the path is empty; the entries are indexed together. */
#define UNIT_PATH_CURSOR_X  0x34 /* s8 cell x the path was last drawn from */
#define UNIT_PATH_CURSOR_Y  0x35 /* s8 cell y */
#define UNIT_PATH_X         0x36 /* s8[12] tile x of each step */
#define UNIT_PATH_Y         0x42 /* s8[12] tile y of each step */
#define UNIT_PATH_STEP_COST 0x4e /* s8[12] movement cost left at each step */
#define UNIT_PATH_START_COST 0x5a /* s8 movement cost at the unit's tile */
#define UNIT_PATH_LENGTH    0x5b /* s8 index of the last step, 0 = empty */
#define UNIT_PATH_MAX_STEPS 12

/* Direction codes of a movement path (gUnitMovePath / MAP_CURSOR_PATH), one byte per
 * grid step.  MOVE_DIR_STOP and MOVE_DIR_NONE end the list; MOVE_DIR_ATTACK replaces
 * the step that would enter an enemy unit. */
#define MOVE_DIR_LEFT   0
#define MOVE_DIR_RIGHT  1
#define MOVE_DIR_DOWN   2
#define MOVE_DIR_UP     3
#define MOVE_DIR_STOP   4
#define MOVE_DIR_ATTACK 10
#define MOVE_DIR_NONE   (-1)

/* Flag byte at +0x20 of the friend-code entry's sub-panels. */
typedef struct FriendCodeFlags {
    u8 active:1;
    u8 mode:4;
    u8 kind:3;
} FriendCodeFlags;

/* One of the two 0x2C-byte sub-panels of the friend-code entry screen. It is a
 * bare heap object whose only method is the MemFree destructor of
 * gHeapObjectVTable; the fields are the ones its drawing code reads. */
typedef struct FriendCodeSubPanel {
    void *vtable;        /* +0x00 gHeapObjectVTable */
    u8 unk04;            /* +0x04 */
    u8 pad05[0x0D];
    s16 unk12;           /* +0x12 */
    u8 unk14;            /* +0x14 */
    u8 unk15;            /* +0x15 */
    u8 unk16;            /* +0x16 */
    u8 unk17;            /* +0x17 */
    u8 unk18;            /* +0x18 */
    u8 pad19[7];
    FriendCodeFlags flags; /* +0x20 */
    u8 unk21;            /* +0x21 */
    u8 pad22[2];
    s32 unk24;           /* +0x24 */
    u8 unk28;            /* +0x28 */
    u8 unk29;            /* +0x29 */
    u8 pad2A[2];
} FriendCodeSubPanel;    /* 0x2C bytes */

/* The friend-code entry screen node built by FriendCodeEntry_Create: a scene
 * node with six sprite objects, two sub-panels, a 0x12-byte animation frame
 * table (laid out like MapInfoIconFrames) and a sprite-grid widget. */
typedef struct FriendCodeEntry {
    void *vtable;        /* +0x00 gFriendCodeEntryVTable */
    u8 pad04[0x30];
    u8 unk34;            /* +0x34 */
    u8 pad35[7];
    void *sprites;       /* +0x3C block of six sprite objects */
    void *panelTop;      /* +0x40 FriendCodeSubPanel */
    void *panelBottom;   /* +0x44 FriendCodeSubPanel */
    void *anim;          /* +0x48 animation frame table (0x12 bytes) */
    void *grid;          /* +0x4C sprite-grid widget */
} FriendCodeEntry;

/* Key ids of the friend-code entry keypad. The ten digit keys are ids 0-9,
 * laid out three per row (7 8 9 / 4 5 6 / 1 2 3 / 0); the remaining keys
 * follow. */
#define FRIEND_CODE_KEYPAD_COLUMNS 3
#define FRIEND_CODE_KEYPAD_CLEAR   10 /* 'C': erase the whole code */
#define FRIEND_CODE_KEYPAD_DELETE  11 /* 'B': erase the last entered digit */
#define FRIEND_CODE_KEYPAD_CANCEL  12 /* 'N': leave the code unchanged */
#define FRIEND_CODE_KEYPAD_CONFIRM 13 /* 'Y': submit the code */

/* A friend code has this many digits; gFriendCodeInput holds them plus a NUL. */
#define FRIEND_CODE_LENGTH 12
/* Digit cursor (0..FRIEND_CODE_LENGTH) of the friend-code entry state, the object
 * the keypad handlers reach through the keypad event's +0x10 pointer. */
#define FRIEND_CODE_CURSOR 0x38

/* ov007 map generator's 30-column scratch marker grid (gMapMarkerGrid). */
#define MAP_MARKER_STRIDE 30
#define MAP_MARKER_RESERVED 1 /* cell reserved by the map border or a structure */
#define MAP_MARKER_PATH 2     /* cell covered by a generated path */
#define MAP_POINT_NONE 0xFF   /* MapPoint x value meaning the point is unset */

/* Styles for DrawFrameBorder. */
enum {
    FRAME_BORDER_INSIDE = 1,  /* frame drawn on the rectangle's own edge */
    FRAME_BORDER_OUTSIDE = 2  /* frame drawn one pixel outside the rectangle */
};

/* The animated highlight frame (DrawFrameBorderPulse): over each half period of
 * FRAME_BORDER_PULSE_STEPS eased steps, one step every other frame, the border
 * grows outward by FRAME_BORDER_PULSE_RANGE pixels and returns. */
#define FRAME_BORDER_PULSE_RANGE 2
#define FRAME_BORDER_PULSE_STEPS 8
#define FRAME_BORDER_PULSE_MASK  0x0F /* steps in a full period, both halves */

/* Window-frame tile ids stamped into a 32-column tile map by the frame-tile
 * drawer (the tiles of the frame tileset loaded for the window). A tile cell holds the
 * tile id in the low 10 bits plus the flip bits and the palette in bits 12-15. */
#define FRAME_TILE_CORNER     1    /* outer corner; the other three are mirrored */
#define FRAME_TILE_EDGE_H     2    /* horizontal (top/bottom) edge */
#define FRAME_TILE_EDGE_V     3    /* vertical (left/right) edge */
#define FRAME_TILE_STRIPE     4    /* striped style: shaded interior row */
#define FRAME_TILE_FILL       5    /* interior fill */
#define FRAME_TILE_EDGE_H_ALT 6    /* striped style: shaded top edge */
#define FRAME_TILE_FLIP_H     0x400 /* mirror the tile horizontally */
#define FRAME_TILE_FLIP_V     0x800 /* mirror the tile vertically */

/* The UI bar gradient (DrawUiGradient): the gradient strip at this offset of the
 * engine's texture area, with its end colours written to this OBJ palette slot. */
#define UI_GRADIENT_TILE    0x1400
#define UI_GRADIENT_PALETTE 1

/* DrawUiGradientPulse walks the far end of that gradient from one UI colour to
 * another and back over UI_GRADIENT_PULSE_FRAMES frames, half per direction. */
#define UI_GRADIENT_PULSE_FRAMES 0x20
#define UI_GRADIENT_PULSE_HALF   0x10

/* Display mode of a 3D sprite engine: bits 2..3 of its first halfword. */
#define SPRITE_ENGINE_MODE(engine) (((u32)(*(u16 *)M2C_FIELD((engine), void **, 0)) << 17) >> 30)

/* Parsed GameSpy GPI profile-info reply, built by gpiProcessGetInfo (gpiInfo.c)
 * from the \nick\, \email\, \firstname\ ... fields of the server response. */
typedef struct GpiInfoResponse {
    char *nick;           /* +0x00: \nick\ */
    char *uniqueNick;     /* +0x04: \uniquenick\ */
    char *email;          /* +0x08: \email\ */
    char *firstName;      /* +0x0C: \firstname\ */
    char *lastName;       /* +0x10: \lastname\ */
    char *homepage;       /* +0x14: \homepage\ */
    s32   icqUin;         /* +0x18: \icquin\ */
    char  zipCode[11];    /* +0x1C: \zipcode\ */
    char  countryCode[3]; /* +0x27: \countrycode\ */
    u8    pad2A[2];
    s32   longitude;      /* +0x2C: \lon\ */
    s32   latitude;       /* +0x30: \lat\ */
    char  location[128];  /* +0x34: \loc\ */
    s32   birthYear;      /* +0xB4: \birthday\ */
    s32   birthMonth;     /* +0xB8 */
    s32   birthDay;       /* +0xBC */
    s32   sex;            /* +0xC0: \sex\ */
    s32   pmask;          /* +0xC4: \pmask\ */
    char *aim;            /* +0xC8: \aim\ */
    s32   pic;            /* +0xCC: \pic\ */
    s32   occupation;     /* +0xD0: \occ\ */
    s32   industry;       /* +0xD4: \ind\ */
    s32   income;         /* +0xD8: \inc\ */
    s32   marital;        /* +0xDC: \mar\ */
    s32   children;       /* +0xE0: \chc\ */
    s32   i1;             /* +0xE4: \i1\ */
    s32   o1;             /* +0xE8: \o1\ */
    s32   conn;           /* +0xEC: \conn\ */
} GpiInfoResponse;

/* Flat info record handed to the game's gpiInfo callback (gpiInfo.c).  The
 * first two words are the result code and profile id, filled in by the caller. */
typedef struct GpiInfoRecord {
    s32  result;          /* +0x000 set by the caller */
    s32  profileId;       /* +0x004 */
    char nick[31];        /* +0x008 */
    char uniqueNick[21];  /* +0x027 */
    char email[51];       /* +0x03C */
    char firstName[31];   /* +0x06F */
    char lastName[31];    /* +0x08E */
    char homepage[76];    /* +0x0AD */
    u8   padF9[3];
    s32  icqUin;          /* +0x0FC */
    char zipCode[11];     /* +0x100 */
    char countryCode[3];  /* +0x10B */
    u8   pad10E[2];
    s32  longitude;       /* +0x110 */
    s32  latitude;        /* +0x114 */
    char location[128];   /* +0x118 */
    s32  birthYear;       /* +0x198 */
    s32  birthMonth;      /* +0x19C */
    s32  birthDay;        /* +0x1A0 */
    s32  sex;             /* +0x1A4 */
    s32  pmask;           /* +0x1A8 */
    char aim[51];         /* +0x1AC */
    u8   pad1DF;
    s32  pic;             /* +0x1E0 */
    s32  occupation;      /* +0x1E4 */
    s32  industry;        /* +0x1E8 */
    s32  income;          /* +0x1EC */
    s32  marital;         /* +0x1F0 */
    s32  children;        /* +0x1F4 */
    s32  i1;              /* +0x1F8 */
    s32  o1;              /* +0x1FC */
    s32  conn;            /* +0x200 */
} GpiInfoRecord;          /* 0x204 bytes */

/* A GameSpy gpi profile search request (gpiSearch.c): the criteria the search
 * entry point copies out of its arguments plus the socket and buffers set up. */
typedef struct GpiSearchRequest {
    s32    type;           /* +0x00: search type */
    s32    socket;         /* +0x04: SOCKET, -1 until created */
    void  *recvBuffer;     /* +0x08: received-data buffer */
    s32    recvBufferSize; /* +0x0C: its size (0x1000) */
    u8     pad10[0x08];
    void  *buffer;         /* +0x18: 0x1001-byte working buffer */
    s32    bufferSize;     /* +0x1C: its size (0x1000) */
    u8     pad20[0x08];
    char   nick[31];       /* +0x28 */
    char   uniquenick[21]; /* +0x47 */
    char   email[51];      /* +0x5C */
    char   firstname[31];  /* +0x8F */
    char   lastname[31];   /* +0xAE */
    u8     padCD[0x63];
    s32    icq;            /* +0x130 */
    s32    countrycode;    /* +0x134 */
    s32    pad138;
    s32    pad13C;         /* +0x13C */
    s32    pad140;         /* +0x140 */
} GpiSearchRequest;        /* 0x144 bytes */

/* One decoded multiplayer room-setup record in ov001 (gRoomTeamA/B and
 * gRoomRecord5/6), filled by the packet decoders in ov001_0216BD08.c. */
typedef struct Ov001PlayerRecord {
    u32  unk00;       /* +0x00 */
    s32  length;      /* +0x04: bytes used by each name/text */
    char text[40];    /* +0x08: team name or extra text */
    char name[4][64]; /* +0x30: up to four player names */
} Ov001PlayerRecord;  /* 0x130 bytes */

/* ov001 cooperative task system (gOv001Tasks): OV001_TASK_GROUP_COUNT groups,
 * each with a node pool, a message queue and a priority-ordered list of
 * pending callbacks bookended by two sentinel nodes. */
#define OV001_TASK_GROUP_COUNT 2

typedef struct Ov001ListNode {
    struct Ov001ListNode *prev; /* +0x00 */
    struct Ov001ListNode *next; /* +0x04 */
} Ov001ListNode;                /* 0x08 bytes: a list anchor */

typedef struct Ov001TaskList {
    Ov001ListNode head;         /* +0x00: head.next is the first node */
    Ov001ListNode tail;         /* +0x08: tail.prev is the last node */
} Ov001TaskList;                /* 0x10 bytes */

/* One scheduled callback; also the type of the sentinel nodes embedded in
 * every Ov001Task. */
typedef struct Ov001TaskNode {
    struct Ov001TaskNode *prev;     /* +0x00 */
    struct Ov001TaskNode *next;     /* +0x04 */
    void (*callback)(void *, s32);  /* +0x08 */
    s32  arg;                       /* +0x0C */
    u8   priority;                  /* +0x10: lower runs first */
    u8   ownsArg;                   /* +0x11: arg is an owned buffer, freed with the node */
    u8   pad12[2];
} Ov001TaskNode;                    /* 0x14 bytes */

/* One task group: nodes are recycled through freeNodes, queued messages wait
 * in pendingNodes, and pending callbacks sit in list in priority order. */
typedef struct Ov001Task {
    s32            freeNodes;    /* +0x00: queue of unused nodes */
    s32            pendingNodes; /* +0x04: queue of nodes waiting to run */
    Ov001TaskList *list;         /* +0x08: pending callbacks, head/tail sentinels below */
    Ov001TaskNode  head;         /* +0x0C: sentinel, priority 0 */
    Ov001TaskNode  tail;         /* +0x20: sentinel, priority 0xFF */
    s32            nodeCount;    /* +0x34: nodes in the pool */
    u8             enabled;      /* +0x38: nonzero while the group dispatches */
    u8             pad39[3];
    Ov001TaskNode *pool;         /* +0x3C: nodeCount nodes of this size */
} Ov001Task;                     /* 0x40 bytes */

/* Multiplayer data-transfer manager (the pointer at gTransferManager): one
 * 0x30-byte slot per player connection, each used to trickle one outgoing
 * buffer and gather one incoming buffer over several frames. */
typedef struct TransferSlot {
    s32  outData;       /* +0x00: outgoing buffer being sent */
    void *inData;       /* +0x04: incoming buffer */
    s32  inSize;        /* +0x08: capacity of inData */
    s32  outSent;       /* +0x0C: bytes of outData already sent */
    s32  inReceived;    /* +0x10: bytes of inData already received */
    s32  outSize;       /* +0x14: size of outData */
    s32  inExpected;    /* +0x18: total bytes expected to arrive */
    u8   sending;       /* +0x1C: an outgoing transfer is in progress */
    u8   state;         /* +0x1D: transfer state */
    u8   prevState;     /* +0x1E: state restored when the transfer ends */
    u8   pad1F[3];
    u16  kind;          /* +0x22: transfer kind (1..4) */
    u64  lastTick;      /* +0x24: GetSystemTick() of the last send */
    u32  timeoutMs;     /* +0x2C: idle timeout in milliseconds */
} TransferSlot;         /* 0x30 bytes */

#define TRANSFER_SLOT_COUNT    32    /* identity bits, one slot each */
#define TRANSFER_DEFAULT_CHUNK 0x5B9 /* default bytes sent per frame */
#define TICKS_TO_MS_DIVISOR    0x82EA /* ((GetSystemTick delta) << 6) / this = ms */

typedef struct TransferManager {
    TransferSlot slots[TRANSFER_SLOT_COUNT];          /* +0x000 */
    void (*onSent)(s32 size, s32 id);                 /* +0x600: outgoing transfer done */
    void (*onReceived)(s32 id, void *buf, s32 size);  /* +0x604: incoming buffer complete */
    void (*onTimeout)(s32 id);                        /* +0x608: idle timeout elapsed */
    void (*onError)(s32 id, s32 error);               /* +0x60C */
    u16  chunkSize;                                   /* +0x610: bytes sent per frame */
    u8   pad612[2];
} TransferManager;      /* 0x614 bytes */

/* ov010 voice-chat link protocol: one context per peer exchange plus the
 * handshake state of the exchange currently being served. */
#define VOICE_LINK_CONTEXT_MAX 8 /* exchange contexts a voice-chat link keeps */

/* The link's packet allocator (VoiceLink_InitPacketPool and friends): a free list of
 * fixed-size packet buffers carved out of the caller's VoiceLinkConfig.packetPool. */
#define LINK_PACKET_SIZE     0x478 /* bytes in one link packet buffer */
#define LINK_PACKET_POOL_MIN 4     /* fewest packets the pool may hold */
#define LINK_PACKET_POOL_MAX 0x48  /* most packets the pool may hold */

typedef struct LinkPacketPool {
    s32   intrState; /* +0x00: saved interrupt state around a list change */
    void *freeList;  /* +0x04: head of the free list */
    void *base;      /* +0x08: start of the pool's buffer */
} LinkPacketPool;

typedef struct VoiceLinkContext {
    s32 valid;                       /* +0x00: nonzero while the context is in use */
    u8  peerId;                      /* +0x04: player id of the peer */
    u8  packetPeerId;                /* +0x05: peer id of the packet being answered */
    u8  pad06[2];
    u32 peerMask;                    /* +0x08: peers this exchange covers */
    s32 step;                        /* +0x0C: row of the protocol sequence table */
    u32 pad10;                       /* +0x10 */
    struct VoiceLinkContext *next;   /* +0x14: free/active list link */
} VoiceLinkContext;                  /* 0x18 bytes */

/* What starts a voice-chat link (VoiceLink_Init): the caller's context and
 * packet pools plus the connection kind and the link layer's callback. */
typedef struct VoiceLinkConfig {
    VoiceLinkContext *contextPool; /* +0x00: VOICE_LINK_CONTEXT_MAX contexts, 0x18 bytes each */
    u32 contextCount;              /* +0x04: contexts in the pool (1..VOICE_LINK_CONTEXT_MAX) */
    s32 kind;                      /* +0x08: connection kind (1..3) */
    u8  localId;                   /* +0x0C: local player id (below 0x20) */
    u8  pad0D[3];
    void *packetPool;              /* +0x10: packet buffers, 0x478 bytes each */
    u32 packetPoolSize;            /* +0x14: size of the packet pool in bytes */
    void *callback;                /* +0x18: link layer's packet callback */
    void *callbackArg;             /* +0x1C: argument for that callback */
} VoiceLinkConfig;                 /* 0x20 bytes */

typedef struct VoiceLinkState {
    s32 unk00;                       /* +0x00 */
    u32 peerMask;                    /* +0x04: connected peers, one bit each */
    u64 lastActivity;                /* +0x08: GetSystemTick() of the last exchange */
    VoiceLinkContext *freeList;      /* +0x10: idle contexts */
    VoiceLinkContext *activeList;    /* +0x14: contexts in use */
    u64 (*getTick)(void);            /* +0x18 */
    u32 randMul;                     /* +0x1C */
    u32 randAdd;                     /* +0x20 */
    u8  pad24[0x18];
    s32 sessionState;                /* +0x3C: 0 idle, 2 exchange active */
    u8  peerId;                      /* +0x40: peer being served */
    u8  peerFlag;                    /* +0x41 */
    u8  pad42[2];
    u32 peerMask2;                   /* +0x44 */
    s32 substate;                    /* +0x48 */
} VoiceLinkState;

/* The link layer's shared configuration block, gLinkConfig, which the voice-chat
 * code reads beside its own state.  In mode 2 the link talks through the single
 * shared gVoiceLinkContext: VoiceLink_FindContext returns it for every peer and
 * no per-peer context is allocated. */
#define LINK_CONFIG_LOCAL_ID  0x00 /* u8 local player id */
#define LINK_CONFIG_PEER_ID   0x01 /* u8 player id of the peer the link talks to */
#define LINK_CONFIG_NOTIFY    0x04 /* void (*)(u8 peer, s32 event, s32 *context, s32 arg) */
#define LINK_CONFIG_NOTIFY_ARG 0x08 /* s32 argument handed to the notify callback */
#define LINK_CONFIG_CONTROL   0x0C /* s32 nonzero: 0xFF control packets go to the control handler, else the peer handler */
#define LINK_CONFIG_MODE      0x10 /* s32 link mode; 2 = single shared context */

/* LINK_CONFIG_NOTIFY event codes. */
#define LINK_NOTIFY_TIMEOUT 9 /* the active exchange was idle for too long and was dropped */

typedef struct LinkConfig {
    u8  localId;    /* +0x00 */
    u8  peerId;     /* +0x01 */
    u8  pad02[2];
    void (*notify)(u8 peer, s32 event, s32 *context, s32 arg); /* +0x04 */
    s32 notifyArg;  /* +0x08 */
    s32 control;    /* +0x0C */
    s32 mode;       /* +0x10 */
    s32 pad14;      /* +0x14 */
} LinkConfig;       /* 0x18 bytes */

/* Header of a voice-chat link packet (magic 0x5F564354). */
typedef struct VoiceLinkPacket {
    u32 magic;      /* +0x00: 0x5F564354 */
    u8  kind;       /* +0x04: packet kind, 0/0xFF are control packets */
    u8  headerSize; /* +0x05: 16 */
    u8  subtype;    /* +0x06: handshake step within the kind */
    u8  pad07;
    u8  sender;     /* +0x08: player id that sent the packet */
    u8  target;     /* +0x09: player id it is for */
    u8  flag;       /* +0x0A */
    u8  peerId;     /* +0x0B */
    u32 sequence;   /* +0x0C */
} VoiceLinkPacket;  /* 0x10 bytes */

/* Result of serving one voice-chat link packet: the reply type to send back
 * (0 = no reply) and the context the reply belongs to. */
typedef struct VoiceLinkReply {
    s32 type;                  /* +0x00 reply packet type, 0 = no reply */
    VoiceLinkContext *context; /* +0x04 exchange the reply belongs to */
} VoiceLinkReply;

/* ov001 bitmap-font text subsystem (ov001_02169020.c / ov001_02169E3C.c).
 * Ov001TextState is what the text-drawing entry points take; Ov001Font wraps a
 * parsed NFTR resource; Ov001FontResource is the data Ov001Font.resource points
 * at, with the metrics and the section lists the glyph lookups walk. */
#define OV001_TEXT_ALIGN_CENTER 0x400 /* DrawTextMultiline: centre each line in the block width */
#define OV001_TEXT_ALIGN_RIGHT  0x800 /* DrawTextMultiline: right-align each line in the block width */

/* Anchor flags of the ov001 text-block placement: the horizontal flags move the
 * block along the text direction, the vertical ones across it. */
#define OV001_TEXT_ANCHOR_VCENTER 0x02 /* centre the block across the text direction */
#define OV001_TEXT_ANCHOR_VBOTTOM 0x04 /* put the block's bottom edge at the anchor */
#define OV001_TEXT_ANCHOR_HCENTER 0x10 /* centre the block along the text direction */
#define OV001_TEXT_ANCHOR_HORIZ_BLOCK 0x80  /* unknown anchor flag used by the textured-text draw path */
#define OV001_TEXT_VALIGN_BOTTOM 0x100      /* DrawVerticallyAnchoredText: put the block's end at the anchor */
#define OV001_TEXT_ANCHOR_HRIGHT  0x20 /* put the block's trailing edge at the anchor */

typedef struct Ov001FontResource {
    u8   unk00;         /* +0x00 */
    s8   lineHeight;    /* +0x01: pixels a line advances */
    u16  defaultChar;   /* +0x02: glyph index used for characters not in the font */
    u8   pad04[4];
    u8  *glyphRunTable; /* +0x08: per-glyph rotation/run records */
    void *cwdhList;     /* +0x0C: first CWDH width record (GetFontGlyphMetric) */
    void *cmapList;     /* +0x10: first CMAP record (GetFontGlyphIndex) */
} Ov001FontResource;

typedef struct Ov001Font {
    Ov001FontResource *resource;    /* +0x00 */
    s32 (*decodeChar)(s32 *cursor); /* +0x04: decode the next character of a text stream */
} Ov001Font;

/* One glyph's width record (a CWDH entry, returned by GetFontGlyphMetric). */
typedef struct Ov001GlyphMetric {
    s8  left;    /* +0x00 pixels the glyph starts left of the pen */
    u8  width;   /* +0x01 pixels the glyph covers */
    s8  advance; /* +0x02 pixels the pen advances */
} Ov001GlyphMetric;

/* The pair a glyph draw hands to the panel's ops: the glyph's width record and
 * its bitmap data inside the font's glyph run table. */
typedef struct Ov001Glyph {
    Ov001GlyphMetric *metric; /* +0x00 */
    u8 *bitmap;               /* +0x04 */
} Ov001Glyph;

/* The drawing operations a text panel points at with Ov001TextPanel::ops. */
typedef struct Ov001TextOps {
    s32 (*drawGlyph)(void *panel, Ov001Font *font, s32 x, s32 y, s32 color, Ov001Glyph *glyph); /* +0x00 */
    void (*unk04)(void *panel, s32 arg); /* +0x04 second operation (TextPanel_ClearText) */
} Ov001TextOps;

/* A text panel: the bitmap surface (CreateTextPanel) text is drawn into.
 * CreatePooledTextPanel hands out 0x30-byte panels from the context's queue and
 * fills in the size and tile fields; the fixed full-screen panels reuse +0x2C
 * as their refresh task handle and leave width/height unused. */
typedef struct Ov001TextPanel {
    u8 pad00[0x14];
    Ov001TextOps *ops; /* +0x14 drawing operations */
    void *self;        /* +0x18 the panel object itself, target of text drawing */
    Ov001Font *font;   /* +0x1C font/glyph set decoding the panel's text */
    s32 unk20;         /* +0x20 */
    s32 unk24;         /* +0x24 */
    void *tiles;       /* +0x28 allocated tile range (queued panels) or heap tile buffer (fixed panels) */
    u16 tileCount;     /* +0x2C tiles allocated in the range (queued panels) */
    u8  width;         /* +0x2E panel width in tiles */
    u8  height;        /* +0x2F panel height in tiles */
} Ov001TextPanel;      /* queued panels are 0x30 bytes */

/* The map action popup object (the repair/refill/level-up sprite created by
 * func_020c98d8): it briefly zooms from double size down to normal while drawing
 * its 3D sprite, then waits out a timer (or a button press) and deletes itself. */
#define MAP_ACTION_X       0x34 /* s32 pixel x of the popup */
#define MAP_ACTION_Y       0x38 /* s32 pixel y of the popup */
#define MAP_ACTION_TILE_X  0x3c /* s32 tile x the action happens on */
#define MAP_ACTION_TILE_Y  0x40 /* s32 tile y the action happens on */
#define MAP_ACTION_MODE    0x44 /* s32 PlayMapActionSound mode (0..2, sounds 0x81/0xE4) */
#define MAP_ACTION_FRAME   0x48 /* s32 sprite animation frame */
#define MAP_ACTION_TIMER   0x4c /* s32 frames left before the popup may end, -1 while zooming */
#define MAP_ACTION_SCALE   0x50 /* s32 zoom in 8.8 fixed point, eases from 0x200 to 0x100 */
#define MAP_ACTION_SPRITE  0x54 /* void *3D sprite the popup draws */
#define MAP_ACTION_HOLD    0x1e /* frames the popup stays at normal size before it may end */

/* The ov001 text/sprite context (gOv001TextContext, a 0x680-byte allocation). */
#define OV001_CTX_FONTS       0x00  /* Ov001Font[2]: the parsed font sets */
#define OV001_CTX_PANEL_QUEUE 0x670 /* ring queue of the 32 text-panel objects CreatePooledTextPanel hands out */

typedef struct Ov001TextState {
    void       *panel;         /* +0x00: text panel whose ops blit one glyph */
    Ov001Font  *font;          /* +0x04 */
    s32         letterSpacing; /* +0x08: extra pixels added after each glyph */
    s32         lineSpacing;   /* +0x0C: extra pixels between lines */
} Ov001TextState;              /* 0x10 bytes */

typedef struct Ov001RangeNode {
    struct Ov001RangeNode *prev; /* +0x00 */
    struct Ov001RangeNode *next; /* +0x04 */
    u16 start;                   /* +0x08 first word of the range */
    u16 size;                    /* +0x0A length in words */
} Ov001RangeNode;

typedef struct Ov001TilePool {
    u8 nodes[0x180];     /* +0x000 storage of the 32 range nodes the queue hands out */
    Ov001RangeNode head; /* +0x180 sentinel before the first used range */
    Ov001RangeNode tail; /* +0x18C sentinel after the last used range */
    s32 usedList;        /* +0x198 list of the ranges in use (head and tail are its sentinels) */
    s32 freeNodes;       /* +0x19C queue of the unused range nodes */
} Ov001TilePool;         /* 0x1A0 bytes */

#define OV001_TILE_POOL_COUNT      2
#define OV001_TILE_POOL_STRIDE     0x1A0 /* bytes per pool */
#define OV001_TILE_POOL_NODE_COUNT 32 /* range nodes available per pool (0x180 bytes / 12) */
#define OV001_TILE_POOL_HEAD       0x180 /* Ov001RangeNode: sentinel before the first used range */
#define OV001_TILE_POOL_TAIL       0x18C /* Ov001RangeNode: sentinel after the last used range */
#define OV001_TILE_POOL_HEAD_START 0x188 /* u16 head.start: first range word in use */
#define OV001_TILE_POOL_TAIL_START 0x194 /* u16 tail.start: one past the last free range word */
#define OV001_TILE_POOL_USED_LIST  0x198 /* s32 list of the ranges in use */
#define OV001_TILE_POOL_FREE_NODES 0x19C /* s32 queue of the free range nodes */
#define OV001_TILE_POOL_FREE_START 0x300 /* first free range word of a fresh pool */
#define OV001_TILE_POOL_FREE_END   0x400 /* one past its last free range word */

/* The Nintendo WFC web request state (gWebRequestState), used by the put.asp and
 * get.asp request builders in main_02046D38/main_02047B84.  The request text is
 * formatted into a heap buffer at WEB_REQ_BUFFER and its body is base64-encoded
 * in place by EncodeWfcRequestBody. */
#define WEB_REQ_PHASE        0x04 /* s32 request state-machine step */
#define WEB_REQ_RESULT       0x08 /* s32 ghttp result of the last request */
#define WEB_REQ_READY        0x0C /* s32 nonzero once the request API may be used */
#define WEB_REQ_PRNG_MUL     0x44 /* s32 LCG multiplier for the body obfuscation */
#define WEB_REQ_PRNG_ADD     0x48 /* s32 LCG increment */
#define WEB_REQ_PRNG_MOD     0x4C /* s32 LCG modulus */
#define WEB_REQ_CHECK_KEY    0x50 /* u32 key XORed into the body's byte-sum checksum */
#define WEB_REQ_BUFFER       0x54 /* char * formatted request buffer */
#define WEB_REQ_HASH_POS     0x58 /* char * position of the hash in the buffer */
#define WEB_REQ_DATA_POS     0x5C /* char * position where the base64 body starts */
#define WEB_REQ_PAYLOAD      0x60 /* void * payload of the last request */
#define WEB_REQ_PAYLOAD_SIZE 0x64 /* s32 its size in bytes */

/* ov007 CO-power panel object (returned by GetPanelObject).  The panel keeps a
 * flag per graphic variant and three values that the opening/closing animation
 * eases between 0 and 256; the rest of the object is a set of sprite handles. */
#define OV007_PANEL_VARIANT_A 0x34 /* u8: first panel variant in use */
#define OV007_PANEL_VARIANT_B 0x35 /* u8: second panel variant in use */
#define OV007_PANEL_ANIM0     0x3c /* u16: first eased value, 0..256 */
#define OV007_PANEL_ANIM1     0x3e /* u16: second eased value, 0..256 */
#define OV007_PANEL_ANIM2     0x40 /* u16: split-region eased value, 0..256 */
#define OV007_PANEL_ANIM_FRAME 0x54 /* s16: frame counter of a panel animation driver object */
#define OV007_PANEL_ROW0      0x44 /* void *first of the panel's three row sprite actors */
#define OV007_PANEL_ROW1      0x48 /* void *second row sprite actor */
#define OV007_PANEL_ROW2      0x4c /* void *third row sprite actor */
#define OV007_PANEL_SPRITE_A  0x50 /* void *one of the panel's two sprites */
#define OV007_PANEL_SPRITE_B  0x54 /* void *the panel's other sprite */

/* A number/text sprite. DrawTextSprite (main_020A94FC) draws it as a row of glyph
 * sprites and SetTextSpriteValue (main_020A86F8) fills in its numeric form. */
#define TEXT_SPRITE_TYPE    0x04 /* u8: 0 = number sprite, 1 = text sprite */
#define TEXT_SPRITE_X       0x08 /* s16: screen x of the first glyph */
#define TEXT_SPRITE_COUNT   0x0A /* u8: number of digit glyphs to draw */
#define TEXT_SPRITE_DIGITS  0x0B /* u8[6]: digit glyph indices, least significant first */
#define TEXT_SPRITE_VALUE   0x1C /* s32: numeric value, clamped to +/-999999 */

/* The ov011 opening-sequence state object, advanced by the ov011_02223CB8 code. */
#define INTRO_TIMER     0x34 /* u16 frames spent in the current state */
#define INTRO_SUBSTATE  0x36 /* u8 sub-state flag */
#define INTRO_ANIM      0x37 /* u8 sprite animation currently playing */
#define INTRO_STATE     0x38 /* u8 1 = opening, 2 = title, 3 = stage sequence */
#define INTRO_STAGE     0x39 /* u8 index into gIntroStateDurations */
#define INTRO_MODE      0x3C /* s32 presentation mode; 2 selects the alternate path */

/* ARM7/ARM9 IPC FIFO: the message word and the status register the game's FIFO
 * code (main_02008EF0, main_02009EB0) polls.  A word carries the index of the
 * handler that receives it, a payload, and a request/reply bit. */
#define REG_IPC_FIFO_CR   0x04000184 /* u16 control/status */
#define REG_IPC_FIFO_SEND 0x04000188 /* u32 write the next outgoing message */
#define REG_IPC_FIFO_RECV 0x04100000 /* u32 read the next incoming message */
#define IPC_FIFO_SEND_FULL  0x0002 /* send FIFO full, no message can be posted */
#define IPC_FIFO_RECV_EMPTY 0x0100 /* no message waiting in the receive FIFO */
#define IPC_FIFO_ERROR      0x4000 /* FIFO error; write IPC_FIFO_CLEAR to recover */
#define IPC_FIFO_CLEAR      0xc000 /* clear the error and re-enable the FIFO */

typedef struct FifoMessage {
    u32 tag:5;      /* bit 0: handler index, 0 when there is no message */
    u32 reply:1;    /* bit 5: 0 = request, 1 = reply */
    u32 payload:26; /* bits 6..31: message data */
} FifoMessage;

/* An ARM7 transfer request is posted on the IPC FIFO as seven words: first the
 * transfer flags (with the fixed bits 0x02004100), then the source,
 * destination and byte size, each as a high and a low 16-bit half.  A word
 * carries its command index at bits 16..22, and the last word also sets bit 24. */
#define ARM7_XFER_FIFO_TAG 9   /* IPC FIFO handler tag of the ARM7 transfer service */
#define ARM7_XFER_WORD(n)  ((u32)(n) << 16) /* command index of a request word */
#define ARM7_XFER_LAST_WORD 0x01000000      /* set on the last word of a request */

/* The ARM7 command service's state object (gArm7CommandState, at 0x0212FCCC).
 * The service talks to the ARM7 power/sound driver through the FIFO and
 * remembers when the LCD was last switched off, so that an immediate re-enable
 * (a bouncing lid or power button) can be debounced. */
#define POWER_SERVICE_LAST_OFF 0x10 /* u32: shared frame counter at the last LCD power-off */

/* POWCNT1, whose bit 0 enables the LCD. */
#define REG_POWCNT1        0x04000304 /* u16 */
#define POWCNT1_LCD_ENABLE 0x0001

/* Delay, in CPU cycles, between attempts to bring the LCD back up: the power
 * service refuses to re-enable it within seven frames of switching it off. */
#define LCD_WAKE_DELAY_CYCLES 0x996A00

/* Frame counter the engine keeps in the shared work area (incremented once per
 * frame, used for parity and short timeouts). */
#define SHARED_FRAME_COUNTER 0x027FFC3C /* volatile u32 */

/* A touch rectangle as the touch API's hit tests take it: the box's two
 * corners, left/top first, each as u16 at these offsets. */
#define RECT_LEFT   0x0 /* u16 x of the left edge */
#define RECT_TOP    0x2 /* u16 y of the top edge */
#define RECT_RIGHT  0x4 /* u16 x of the right edge */
#define RECT_BOTTOM 0x6 /* u16 y of the bottom edge */

/* The ov001 map-list screen's state (gMapListState): the list's pixel scroll
 * position and a pointer to the screen's 0x48-byte object.  That object holds
 * the loaded background tilemaps, the text panel the info rows are drawn in,
 * the seven row/selection sprite slots at +0x18 and, after them, the scroll
 * bar, task handles and button flags. */
#define OV001_MAP_LIST_SCROLL     0x04 /* u16: scroll position in pixels */
#define OV001_MAP_LIST_STATE      0x00 /* u8: screen state index: the list row's screen, or a sub-screen */
#define OV001_MAP_LIST_ROW        0x02 /* u8: selected row within the visible rows */
#define OV001_MAP_LIST_OBJECT     0x08 /* void *: the screen's 0x48-byte object */
#define OV001_MAP_LIST_ROW_HEIGHT 29   /* pixels of one list row; five are visible */
#define OV001_MAP_LIST_BG_TILEMAP 0x08 /* object: s32 loaded list-background tilemap */
#define OV001_MAP_LIST_TEXT_PANEL 0x14 /* object: s32 text panel for the info rows */

/* The ov001 friend-roster screen's vertical scroll bar (gOv001Scrollbar, a
 * 0x20-byte object built by Ov001_CreateScrollBar): a sprite whose touch
 * rectangles are hit-tested for dragging (handle), paging (track) and the two
 * arrow caps. */
#define OV001_SCROLLBAR_SPRITE     0x00 /* M2C_UNK layout handle of the bar sprite */
#define OV001_SCROLLBAR_TASK       0x0c /* s32 id of the task driving the bar */
#define OV001_SCROLLBAR_X          0x10 /* u16 x of the track */
#define OV001_SCROLLBAR_Y          0x12 /* u16 y of the track */
#define OV001_SCROLLBAR_W          0x14 /* u16 width of the bar, 12 */
#define OV001_SCROLLBAR_H          0x16 /* u16 y the track starts at for touch input */
#define OV001_SCROLLBAR_DRAG_OFFSET 0x18 /* u8 handle offset when the drag started */
#define OV001_SCROLLBAR_TRACK      0x19 /* u8 track length in pixels */
#define OV001_SCROLLBAR_HANDLE_POS 0x1a /* u8 current handle offset in pixels */
#define OV001_SCROLLBAR_KIND       0x1b /* u8 sprite kind: index of the handle length */
#define OV001_SCROLLBAR_STATE      0x1c /* u8 0 idle, 1 dragging, 2/3 bar scroll */
#define OV001_SCROLLBAR_EVENT      0x1d /* u8 event code the update task reports */
#define OV001_SCROLLBAR_BLOCKED    0x1e /* u8 nonzero while the task must leave it alone */

/* Parts of the scroll bar a touch rectangle can describe, in hit-test order. */
enum {
    OV001_SCROLLBAR_PART_HANDLE = 1, /* the draggable handle */
    OV001_SCROLLBAR_PART_UP     = 2, /* the cap just above the track */
    OV001_SCROLLBAR_PART_DOWN   = 3, /* the cap just below the track */
    OV001_SCROLLBAR_PART_TRACK  = 4  /* the track itself, page by a touch */
};

/* Stream locking shared by ReadFileData, GetFilePosition and SetFilePosition.
 * gStreamMutexes holds one GsiMutex per stream class; the running thread object
 * (gSocketManager+0x04) carries its id at +0x6C, which gStreamLockOwner records
 * while it holds the mutex and gStreamLockDepth counts its reentrant nesting. */
#define STREAM_LOCK_STDIN  2    /* gStreamMutexes index for stdin */
#define STREAM_LOCK_STDOUT 3    /* ... for stdout */
#define STREAM_LOCK_STDERR 4    /* ... for stderr */
#define STREAM_LOCK_FILE   5    /* ... for every other stream */
#define STREAM_THREAD_ID   0x6C /* s32 thread id inside the running thread object */

/* The console's menu language (gLanguage, read by GetLanguage).  The localized
 * file name built by GetLocalizedFileName takes the matching gFileNameFormat*
 * prefix; 0 means no language is set yet and the plain name is used. */
enum {
    LANGUAGE_UNSET   = 0,
    LANGUAGE_ENGLISH = 1, /* e_ prefix */
    LANGUAGE_FRENCH  = 2, /* f_ prefix */
    LANGUAGE_GERMAN  = 3, /* d_ prefix */
    LANGUAGE_ITALIAN = 4, /* i_ prefix */
    LANGUAGE_SPANISH = 5  /* s_ prefix */
};

/* One thread of the cooperative scheduler.  gThreadManager (a void * with
 * gSocketManager straight after it) holds the running thread at
 * THREAD_MANAGER_CURRENT and the ready list, kept in priority order and chained
 * through Thread::next, at THREAD_MANAGER_READY. */
#define THREAD_MANAGER_CURRENT 0x28 /* Thread *: the thread that is running */
#define THREAD_MANAGER_READY   0x2c /* Thread *: first thread of the ready list */

typedef struct Thread {
    u8 pad00[0x64];
    s32 state;           /* +0x64 0 waiting, 1 ready to run, 2 finished */
    struct Thread *next; /* +0x68 next thread of the ready list */
    u32 id;              /* +0x6c creation id */
    s32 priority;        /* +0x70 run priority; equal priorities round-robin */
} Thread;

/* The CO roster state (gCoState): +0x04 a u8, +0x08 the s32 bitset of the COs
 * the player has unlocked (bit i = CO i). */
#define CO_STATE_UNLOCKED 0x08

/* A Q12 fixed-point 4x3 matrix as the matrix library (main_02001068) stores it:
 * three rows of three rotation/scale coefficients, row-major, then the
 * translation row.  NitroSDK calls this type MtxFx43. */
#define MTX43_ROT     0  /* s32[9] rotation/scale coefficients */
#define MTX43_TRANS   9  /* s32[3] translation */
#define MTX_FX_SHIFT  12 /* fractional bits of a matrix coefficient */

/* NitroSDK thread and message queues (os_thread.c, os_message.c).  An
 * OSMessageQueue is a fixed ring of 32-bit messages, usually pointers, that
 * threads hand to each other; a thread queue lists the threads asleep on it. */
typedef struct OSThreadQueue {
    void *head; /* +0x00 first thread waiting on the queue, NULL when empty */
    void *tail; /* +0x04 last thread waiting on the queue */
} OSThreadQueue; /* 8 bytes */

typedef struct OSMessageQueue {
    OSThreadQueue sendQueue;    /* +0x00 threads asleep because the queue is full */
    OSThreadQueue receiveQueue; /* +0x08 threads asleep because the queue is empty */
    s32 *msgArray;              /* +0x10 message slots */
    s32 msgCount;               /* +0x14 number of slots */
    s32 firstIndex;             /* +0x18 slot holding the oldest message */
    s32 usedCount;              /* +0x1C messages queued */
} OSMessageQueue; /* 0x20 bytes */

/* Flags of OS_SendMessage, OS_JamMessage, OS_ReceiveMessage and OS_ReadMessage:
 * bit 0 set makes the call sleep until the queue can take or give a message. */
enum {
    OS_MESSAGE_NOBLOCK = 0,
    OS_MESSAGE_BLOCK   = 1
};

#endif

