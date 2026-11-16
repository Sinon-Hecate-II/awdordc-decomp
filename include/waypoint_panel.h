#ifndef WAYPOINT_PANEL_H
#define WAYPOINT_PANEL_H

/* Waypoint panel state is packed in the high nibble of panel byte 0x39. */
enum { WAYPOINT_PANEL_IDLE = 0, WAYPOINT_PANEL_MENU_OFFSET = 0x6c };
/* Action 27 selects the current player slot rather than an option cell. */
enum { WAYPOINT_ACTION_CURRENT_SLOT = 27 };

#endif
