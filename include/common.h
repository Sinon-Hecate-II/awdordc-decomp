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

#endif

