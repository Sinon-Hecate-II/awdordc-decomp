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


/* Event record passed to a WH task callback (HandleChildIndicate and friends). */
#define WH_EVENT_STATUS   0x02 /* u16 nonzero = the step failed with this code */
#define WH_EVENT_COMMAND  0x04 /* u16 command reported by a parent/child task */
#define WH_EVENT_INDICATE 0x08 /* u16 connect/disconnect indication kind */
#define WH_EVENT_CHILD_ID 0x10 /* u16 child index, a bit position in the child bitmap */

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

#endif
