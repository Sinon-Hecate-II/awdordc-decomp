/* The ov001 Wi-Fi ("WH") connection overlay (Nintendo's DWC middleware): a
 * connection task reports events to the overlay's callbacks, and the callbacks
 * drive the WH status machine kept in gWhWork (+4 is the connection object).
 * Status names below are the strings the overlay logs (DWCi_MOV_WH_SYSSTATE_*). */
#ifndef OV001_WH_H
#define OV001_WH_H

/* Device-name record embedded at +2 in the wireless setup request. */
typedef struct Ov001DeviceNameRecord {
    u8 kind;
    u8 pad;
    u16 size;
    char text[256];
} Ov001DeviceNameRecord;

#define OV001_DEVICE_NAME_KIND 0x50
#define OV001_SETUP_MODE       0x000
#define OV001_SETUP_NAME       0x002
#define OV001_SETUP_OPTION0    0x106 /* s16: option meanings not recovered */
#define OV001_SETUP_OPTION1    0x108
#define OV001_SETUP_OPTION2    0x10A
#define OV001_SETUP_OPTION3    0x10C
#define OV001_SETUP_OPTION4    0x10E
#define OV001_SETUP_MAC        0x110 /* six-byte console MAC address */
#define OV001_SETUP_STATUS     0x116 /* u8: result of the last setup attempt (0 = ok, 0xF = failed) */
#define OV001_SETUP_PACKET     0x117 /* the 0x154-byte room setup packet (see BuildRoomSetupPacket) */

/* The wireless setup state (gOv001WirelessSetup): a flag set once the local
 * player's connection is accepted, then the 0x26C-byte setup request buffer
 * whose layout starts with the setup header above. */
typedef struct Ov001WirelessSetup {
    u8 connected;
    u8 pad[3];
    u8 *request;
} Ov001WirelessSetup;

/* Results of one wireless setup poll. */
enum {
    OV001_SETUP_PENDING = 0, /* not connected yet; poll again next frame */
    OV001_SETUP_JOINED  = 1, /* the local player's connection was accepted */
    OV001_SETUP_FAILED  = 2  /* the connection attempt failed */
};


/* Event record passed to a WH task callback (HandleChildIndicate and friends). */
#define WH_EVENT_STATUS   0x02 /* u16 nonzero = the step failed with this code */
#define WH_EVENT_COMMAND  0x04 /* u16 command reported by a parent/child task */
#define WH_EVENT_INDICATE 0x08 /* u16 connect/disconnect indication kind */
#define WH_EVENT_CHILD_ID 0x10 /* u16 child index, a bit position in the child bitmap */

/* gWhState holds the work buffers for starting a WFC connection. */
#define WH_STATE_CONNECT_SETTINGS 0x28 /* Buffer for optional connection settings. */
#define WH_STATE_PHASE            0x2C
#define WH_STATE_BSS_DESC         0x4C /* Buffer for the selected host descriptor. */
#define WH_STATE_CONNECT_FLAGS    0x58
#define WH_PHASE_READY_TO_CONNECT 3
#define WH_PHASE_CONNECT_PENDING  8
#define WH_CONNECT_SETTINGS_BYTES 0x60
#define WH_BSS_DESC_BYTES         0xC0
#define WH_WFC_STEP_QUEUED        3

/* The allocator/cleanup callbacks the overlay installs before a WH session runs
 * (see Ov001_OpenOptionPage and func_ov001_021711e0), and the connection
 * context they serve: the allocator builds it, the cleanup runs once the
 * connection attempt is over. */
#define WH_STATE_ALLOC     0x04 /* void *(*)(s32 bytes): allocates a WH session buffer */
#define WH_STATE_CLEANUP   0x0C /* void (*)(void *context): the overlay's cleanup callback */
#define WH_STATE_CONTEXT   0x54 /* void *connection context, 0 when none was allocated */

/* The WH connection task's smaller state object (0x28 bytes): like gWhState it
 * stages a connection, but it keeps its buffers by pointer. */
#define WH_TASK_CONNECT_PARAMS  0x08 /* void *connection parameters handed to WFC_ConnectStep */
#define WH_TASK_CONNECT_FLAGS   0x0C /* s32 flags passed to WFC_StartConnection */
#define WH_TASK_PHASE           0x18 /* s32 one of WH_PHASE_* */
#define WH_TASK_BSS_DESC        0x20 /* void *0xC0-byte host descriptor buffer */
#define WH_TASK_SETTINGS        0x24 /* void *0x50-byte connection settings buffer */
#define WH_TASK_SETTINGS_BYTES  0x50

/* Fields of gWhWork: the log callback the overlay reports through, then the
 * connection object at +4 (WH_LINK_STATUS and friends). */
#define WH_WORK_LOG    0x00 /* void (*)(u32 level, const char *text, s32 value): WH logging hook, 0 when none */
#define WH_WORK_CONNECTION 0x04 /* void * the WH connection object (fields below, WH_LINK_STATUS and friends) */
#define WH_LOG_STATUS 0x08000000 /* log level of a WH status change */

/* Connection object fields (gWhWork+4). */
#define WH_DS_CHANNEL   0x13e0 /* channel state object the data-sharing exchange runs on (see wfc_channel.h) */
#define WH_DS_PLAYERS   0x1c00 /* u16 player mask, u16 known mask, then the players' 0x200-byte data blocks */
#define WH_LINK_STATUS  0x40 /* s32: WH_STATUS_* */
#define WH_CONN_USER_INFO_CB 0x13AC /* s32 (*)(void *userInfo, void *connection): fills the user-info block and returns the WFC user type */
#define WH_CONN_USER_INFO    0x13C0 /* user-info block handed to WFC_SubmitUserInfo */
#define WH_CHILD_PICKED 0x5c /* u16: child picked, one-based, 0 = none */
#define WH_CHILD_CONNECTED 0x52 /* u16: one bit per connected child, bit 0 = this console */
#define WH_CHILD_BITS   0x60 /* u16: one bit per child still wanted */
#define WH_CHILD_RATIO  0x5e /* u16: best (lowest) ratio a child scan reported so far, 101 = none */
#define WH_CHILD_RATIO_NONE 0x65 /* no child reported a ratio yet */

/* The per-channel report a child scan hands back to its callback. */
#define WH_CHANNEL_STATUS 0x02 /* u16 nonzero = the channel failed with this code */
#define WH_CHANNEL_INDEX  0x08 /* u16 one-based channel (child) index */
#define WH_CHANNEL_RATIO  0x0a /* u16 the channel's ratio, lower is better */
#define WH_RANDOM_SEED  0x58 /* u32: xorshift/LCG state for picking a child */
#define WH_RANDOM_MUL   0x10dcd /* seed multiplier of the game's LCG */
#define WH_RANDOM_ADD   0x3039 /* seed increment of the game's LCG */

/* Results of one data-sharing channel step. */
enum {
    WH_DS_STEP_PROGRESS   = 0, /* a slot was exchanged; the caller processes it */
    WH_DS_STEP_FAILED     = 1, /* the exchange failed; SetWhError carries the code */
    WH_DS_STEP_NO_DATASET = 5, /* the peer had no data set ready */
    WH_DS_STEP_NO_CHILD   = 7  /* the parent has no child to share with */
};

/* Results of the per-child channel scan (ScanNextChild). */
#define WH_SCAN_QUEUED 2    /* the scan command of the child was queued; its report arrives through the callback */
#define WH_SCAN_DONE   0x18 /* no further child to scan (or the channel check reported the same code) */

/* Connection object status field (+0x40). */
enum {
    WH_STATUS_STOP           = 0,
    WH_STATUS_IDLE           = 1,
    WH_STATUS_SCANNING       = 2,
    WH_STATUS_BUSY           = 3,
    WH_STATUS_CONNECTED      = 4,
    WH_STATUS_DATASHARING    = 5,
    WH_STATUS_KEYSHARING     = 6,
    WH_STATUS_MEASURECHAN    = 7,
    WH_STATUS_CONNECT_FAILED = 8,
    WH_STATUS_PARENT_START   = 9 /* WM_STATECODE_PARENT_START, used as the failure state */
};

/* The ov001 Wi-Fi menu's option rows (gOv001OptionMenuState.selected). */
enum {
    OV001_OPTION_MAC_ADDRESS = 0, /* show the console's MAC address and profile code */
    OV001_OPTION_WFC_SETTINGS = 1, /* configure the Nintendo WFC profile */
    OV001_OPTION_ERASE_WFC    = 2  /* erase the saved WFC profile */
};
#define OV001_OPTION_COUNT 3

/* The ov001 wireless (multi-card) setup screen's state (gOv001WirelessState). */
#define OV001_WIRELESS_CONNECTED 0x00 /* u8: set once the local player's connection was accepted */
#define OV001_WIRELESS_TIMER     0x02 /* u16: counts up to OV001_WIRELESS_TIMEOUT before the screen moves on */
#define OV001_WIRELESS_TASK      0x04 /* s32: id of the connection task to cancel */
#define OV001_WIRELESS_TIMEOUT   0x438 /* frames the setup screen waits for the connection (1080) */

/* The ov001 Wi-Fi settings screen's two-choice message popup (gOv001MessageState). */
#define OV001_MESSAGE_SHOWN  0x00 /* u8: nonzero while the popup is on screen */
#define OV001_MESSAGE_OPTION 0x01 /* u8: the option the player picked (0 = the first one) */

/* What the ov001 option menu's icon row reports: the shared row has a back icon
 * and a confirm icon, and the menu latches a touch or key press as one of them
 * (see Ov001_GetIconRowSelection). */
enum {
    OV001_CHOICE_BACK    = 0, /* leave the option menu for the Wi-Fi menu */
    OV001_CHOICE_CONFIRM = 1  /* accept the highlighted option */
};

/* The WH user-data packet.  gWhPacket holds an 8-byte prefix - a big-endian
 * u16 count of the tagged-field bytes that follow, then six zero bytes - and
 * then the fields; gWhPacketInfo[0] points at the first of them.  A field has
 * a big-endian u16 tag and byte length, its payload, then zero padding to a
 * multiple of 8 bytes.  WhPacket_Wrap copies the block after a 6-byte header
 * (u16 type, u16 payload bytes, u16 zero) and appends a big-endian u16
 * checksum over header and payload. */
#define WH_PACKET_FIELDS 0x08 /* bytes from gWhPacket to its first field */
#define WH_PACKET_HEADER 0x06 /* outer header bytes before the payload */
#define WH_PACKET_TYPE   0x00 /* u16 big-endian type, at the start of the header */
#define WH_PACKET_LENGTH 0x02 /* u16 big-endian payload byte count */
/* Packet words are big-endian: the high byte is stored first. */
#define WH_READ_BE16(value) ((u16)((u8)((s32)(value) >> 8) | (0xff00 & ((value) << 8))))

/* The WH packet/settings block at gWhPacketInfo: +0x00 points at the first
 * field of gWhPacket, +0x08 is the packet buffer size, +0x0C the matchmaking
 * deadline in WhGetTime units and +0x10 a caller-supplied setting. */
#define WH_PACKET_INFO_FIELDS 0x00
#define WH_PACKET_INFO_SIZE   0x08
#define WH_PACKET_INFO_DEADLINE 0x0c
#define WH_PACKET_INFO_SETTING  0x10

/* Sound ids handed to Ov001_PlaySound. */
enum {
    OV001_SOUND_CONFIRM = 6, /* an action was accepted */
    OV001_SOUND_CANCEL  = 7, /* the screen is being left without an action */
    OV001_SOUND_MOVE    = 8, /* the cursor moved to another row */
    OV001_SOUND_ERROR   = 9, /* the action is not possible */
    OV001_SOUND_SAVED   = 0x10, /* a profile or save operation completed */
    OV001_SOUND_FAILED  = 0x12  /* a profile action failed or was cancelled */
};

/* Outcome of the ov001 WFC profile screen, kept in gOv001ProfileScreenResult for
 * the screen that follows it to show. */
enum {
    OV001_PROFILE_NO_CHANGE = 0, /* left without changing the profile */
    OV001_PROFILE_SAVED     = 1, /* the obtained WFC profile was written to the save slots */
    OV001_PROFILE_OTHER     = 2  /* the profile action ended another way */
};

#endif
