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

/* ov001 map-select list screen: the object pointed at by gMapSelectState+4.
 * It holds two rows of label sprites and a table of 42-byte map entries. */
#define MAPSELECT_ENTRIES       0x00 /* void *: map entry table */
#define MAPSELECT_ENTRY_SIZE    42   /* bytes per map entry */
#define MAPSELECT_ENTRY_FLAG    0x28 /* u8 per entry: selects the preview path */
#define MAPSELECT_ROW_OBJS_A    0x10 /* void *[MAPSELECT_ROWS] row labels */
#define MAPSELECT_ROW_OBJS_B    0x24 /* void *[MAPSELECT_ROWS] map names */
#define MAPSELECT_ROWS          5    /* rows shown at once */
#define MAPSELECT_COUNT         0x51 /* u8 number of maps in the list */
#define MAPSELECT_INDEX         0x52 /* u8 selected row */
#define MAPSELECT_CHOSEN        0x54 /* u8 a map has been chosen */

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
    s32 unk1C;           /* +0x1C */
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

/* DS key bits, as stored in the KeyState masks. */
enum {
    KEY_A = 0x0001, KEY_B = 0x0002, KEY_SELECT = 0x0004, KEY_START = 0x0008,
    KEY_RIGHT = 0x0010, KEY_LEFT = 0x0020, KEY_UP = 0x0040, KEY_DOWN = 0x0080,
    KEY_R = 0x0100, KEY_L = 0x0200, KEY_X = 0x0400, KEY_Y = 0x0800
};

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

/* GameSpy gpi receive buffer (the connection field at +0x1DC): storage, the
 * allocated size and the number of bytes currently held. */
typedef struct GPIBuffer {
    void *data; /* +0x00 storage */
    s32   size; /* +0x04 allocated bytes */
    s32   len;  /* +0x08 bytes used */
} GPIBuffer;

/* Connection session states (the state at GetConnection()->0x1A0) used while
 * the peers agree on their player slots and synchronise. */
enum {
    CONN_STATE_SYNC_PREPARE  = 8,  /* preparing the session with a peer */
    CONN_STATE_WAIT_SLOT     = 9,  /* own player slot is being accepted */
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
#define CONN_SESSION_PLAYER_COUNT 0x0D  /* u8  number of connected peers */
#define CONN_SESSION_PEER_IDS     0xF4  /* s32 peer ids, 4 bytes per slot */
#define CONN_SESSION_SYNC_ACKS    0x1D8 /* u32 bitmask of peers that answered */
#define CONN_SESSION_SYNC_SENT    0x1E8 /* u64 time the last sync notice was sent */
#define CONN_SESSION_SYNC_EXCESS  0x1B2 /* u16 worst overrun of the sync deadline */
#define CONN_SESSION_SYNC_RETRY   0x1AC /* u8 retry counter for the sync-measure notices */
#define CONN_SESSION_PEER_SLOTS   0x2D0 /* u8 slot id per connected peer, indexed from 1 */

/* Fields of the online-match session context (the pointer held at
 * data_0213d38c + 8). */
#define MATCH_SESSION_STATUS       0x00 /* s32 0 idle, 1 running, 2 finished */
#define MATCH_SESSION_PLAYER_COUNT 0x14 /* s32 number of players */
#define MATCH_SESSION_PLAYERS      0x18 /* array of 12-byte player records */
#define MATCH_SESSION_PLAYER_SIZE  12
#define MATCH_SESSION_CURSOR       0x1C /* u8 player being processed */
#define MATCH_SESSION_DIRTY        0x1D /* u8 player list changed */
#define MATCH_SESSION_STATE        0x1E /* u8 match-setup step */

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

/* Non-printing characters the on-screen keyboard produces. */
enum {
    KBD_KEY_DELETE = 0x80,
    KBD_KEY_CANCEL = 0x82,
    KBD_KEY_OK     = 0x83
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

/* Work area of the movement flood fill (gMoveSearchState).  It starts with a
 * 32-entry terrain cost table, then the search limits, then two ping-pong
 * queues of 4-byte nodes (x, y, direction, accumulated cost). */
typedef struct MoveSearchNode {
    u8 x;      /* +0x00 */
    u8 y;      /* +0x01 */
    u8 dir;    /* +0x02 direction taken to reach the tile, 1 = start */
    u8 cost;   /* +0x03 accumulated movement cost */
} MoveSearchNode; /* 4 bytes */

#define MOVE_SEARCH_TERRAIN_COST 0x00 /* s8[32] movement cost per terrain kind */
#define MOVE_SEARCH_COST_LIMIT   0x20 /* s16 accumulated-cost limit */
#define MOVE_SEARCH_MOVE_RANGE   0x22 /* s16 unit move range (movement points) */
#define MOVE_SEARCH_WIDTH        0x24 /* u8 map width, filled by SelectMapLayer */
#define MOVE_SEARCH_HEIGHT       0x25 /* u8 map height, filled by SelectMapLayer */
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

/* One decoded multiplayer room-setup record in ov001 (gRoomTeamA/B and
 * gRoomRecord5/6), filled by the packet decoders in ov001_0216BD08.c. */
typedef struct Ov001PlayerRecord {
    u32  unk00;       /* +0x00 */
    s32  length;      /* +0x04: bytes used by each name/text */
    char text[40];    /* +0x08: team name or extra text */
    char name[4][64]; /* +0x30: up to four player names */
} Ov001PlayerRecord;  /* 0x130 bytes */

#endif

