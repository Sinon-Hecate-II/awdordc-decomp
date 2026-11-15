/* The ov001 Wi-Fi ("WH") connection overlay (Nintendo's DWC middleware): a
 * connection task reports events to the overlay's callbacks, and the callbacks
 * drive the WH status machine kept in gWhWork (+4 is the connection object).
 * Status names below are the strings the overlay logs (DWCi_MOV_WH_SYSSTATE_*). */
#ifndef OV001_WH_H
#define OV001_WH_H

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

#endif
