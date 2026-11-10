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

/* DS key bits, as stored in the KeyState masks. */
enum {
    KEY_A = 0x0001, KEY_B = 0x0002, KEY_SELECT = 0x0004, KEY_START = 0x0008,
    KEY_RIGHT = 0x0010, KEY_LEFT = 0x0020, KEY_UP = 0x0040, KEY_DOWN = 0x0080,
    KEY_R = 0x0100, KEY_L = 0x0200
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

#endif

