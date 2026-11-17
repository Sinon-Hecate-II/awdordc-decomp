#ifndef WAYPOINT_PANEL_H
#define WAYPOINT_PANEL_H

/* Waypoint panel state is packed in the high nibble of panel byte 0x39. */
enum { WAYPOINT_PANEL_IDLE = 0, WAYPOINT_PANEL_MENU_OFFSET = 0x6c };

/* A waypoint-panel CO option: 0..11 pick the CO ids 1..12, 12 is the random
 * choice (CO id 0), and any other option has no CO. */
#define WAYPOINT_OPTION_RANDOM 12
#define WAYPOINT_CO_NONE       255
/* Action 27 selects the current player slot rather than an option cell. */
enum { WAYPOINT_ACTION_CURRENT_SLOT = 27 };

#endif
