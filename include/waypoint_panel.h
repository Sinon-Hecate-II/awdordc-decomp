#ifndef WAYPOINT_PANEL_H
#define WAYPOINT_PANEL_H

/* Waypoint panel state is packed in the high nibble of panel byte 0x39. */
enum { WAYPOINT_PANEL_IDLE = 0, WAYPOINT_PANEL_MENU_OFFSET = 0x6c };

/* Fields of the waypoint panel object, the setup screen's player and waypoint
 * selector.  Its flag byte packs the panel state in the high nibble
 * (WAYPOINT_PANEL_IDLE and the animation states), the layout in bits 2-3 and
 * the link flag in bit 0. */
#define WAYPOINT_PANEL_FLAGS        0x39 /* u8: packed panel flags */
#define WAYPOINT_PANEL_TEXT_ENABLED 0x3A /* u8 bit 0: the description text is shown */
#define WAYPOINT_PANEL_LAYOUT_MASK  0x0C /* bits 2-3 hold a WAYPOINT_PANEL_LAYOUT_* value */
#define WAYPOINT_PANEL_TEXT         0x54 /* void *: description text sprite */
#define WAYPOINT_PANEL_CURSOR       0x58 /* void *: target-cell cursor sprite */
#define WAYPOINT_PANEL_MARKER       0x5C /* void *: sprite marking the selected slot */
#define WAYPOINT_PANEL_STRIP_A      0x48 /* SpriteTween *: background strip, 0 wide / -0x100 compact */
#define WAYPOINT_PANEL_STRIP_B      0x50 /* SpriteTween *: background strip, 0x100 wide / 0 compact */
#define WAYPOINT_PANEL_STRIP_C      0x4C /* SpriteTween *: sliding bar, 0xC0 wide / 0x5E compact */

/* Layout of the waypoint panel, bits 2-3 of WAYPOINT_PANEL_FLAGS. */
enum {
    WAYPOINT_PANEL_LAYOUT_WIDE = 0,    /* all four player columns, strips spread out */
    WAYPOINT_PANEL_LAYOUT_COMPACT = 1  /* player columns hidden, strips slid left */
};

/* Description text keys chosen for the group the selected slot belongs to by
 * the waypoint panel's mode update (the slot index is the unit sprite's +0x2E). */
#define WAYPOINT_TEXT_SLOTS_0_TO_3    0x47000011
#define WAYPOINT_TEXT_SLOTS_4_TO_7    0x47000012
#define WAYPOINT_TEXT_SLOTS_8_TO_20   0x47000011
#define WAYPOINT_TEXT_SLOTS_21_TO_24  0x47000010
#define WAYPOINT_TEXT_CONFIRM_WIDE    0x47000016
#define WAYPOINT_TEXT_CONFIRM_COMPACT 0x47000017

/* A waypoint-panel CO option: 0..11 pick the CO ids 1..12, 12 is the random
 * choice (CO id 0), and any other option has no CO. */
#define WAYPOINT_OPTION_RANDOM 12
#define WAYPOINT_CO_NONE       255
/* Action 27 selects the current player slot rather than an option cell. */
enum { WAYPOINT_ACTION_CURRENT_SLOT = 27 };

/* First slot of each of the five groups of the waypoint list (see
 * WaypointSlotGroup): 0-3, 4-7, 8-20, 21-24 and 25. */
enum {
    WAYPOINT_GROUP_0_FIRST = 0,
    WAYPOINT_GROUP_1_FIRST = 4,
    WAYPOINT_GROUP_2_FIRST = 8,
    WAYPOINT_GROUP_3_FIRST = 21,
    WAYPOINT_GROUP_4_FIRST = 25
};

#endif
