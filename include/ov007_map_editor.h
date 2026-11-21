/* The map editor's state block, its palette-panel object and its cached unit
 * counts: the current palette page, the terrain and unit brushes, the player
 * and unit counts and the modified flag.  The editor's accessors live in
 * ov007_02211200. */
#ifndef OV007_MAP_EDITOR_H
#define OV007_MAP_EDITOR_H

#define MAP_EDITOR_MODE          0x00 /* u8 0 = terrain palette page, 1 = unit palette page */
#define MAP_EDITOR_TERRAIN_OWNER 0x01 /* u8 owner (bits 5..7) the terrain brush paints */
#define MAP_EDITOR_PLAYER_COUNT  0x02 /* u8 players in use (assigned to team 1) */
#define MAP_EDITOR_TERRAIN_KIND  0x03 /* u8 terrain kind (bits 0..4) the terrain brush paints */
#define MAP_EDITOR_UNIT_COUNT    0x04 /* u8 units placed on the map */
#define MAP_EDITOR_MODIFIED      0x05 /* u8 nonzero once the map was edited */
#define MAP_EDITOR_UNIT_FLAGS    0x06 /* u8 low 4 bits of the placed unit's record byte 0x0b */
#define MAP_EDITOR_UNIT_OWNER    0x07 /* u8 1-based owner the unit brush places */
#define MAP_EDITOR_UNIT_KIND     0x08 /* u8 unit kind the unit brush places */
#define MAP_EDITOR_TOOL          0x09 /* u8 the active editor tool (0..3) */

/* The palette-panel object (the ov007 panel object GetPanelObject returns): the
 * palette page it shows and, in two parallel arrays indexed by that page, the
 * palette entry and the owner/colour the cursor points at.  Picking an entry
 * arms it (MAP_EDITOR_PANEL_PENDING); closing the panel applies it. */
#define MAP_EDITOR_PANEL_CLOSE   0x35 /* u8 nonzero to hide/close the panel */
#define MAP_EDITOR_PANEL_PENDING 0x36 /* u8 nonzero once the cursor picked a palette entry */
#define MAP_EDITOR_PANEL_PAGE    0x37 /* u8 palette page the panel shows (MAP_EDITOR_MODE) */
#define MAP_EDITOR_PANEL_OWNER   0x38 /* s8[2] owner/colour index per page */
#define MAP_EDITOR_PANEL_ENTRY   0x3A /* s8[2] selected palette entry index per page */

/* The palette panel's two list objects (each a MenuList007 built by
 * func_ov007_0221863c): the page's entry grid and the page markers row. */
#define MAP_EDITOR_PANEL_ENTRY_LIST  0x58 /* MenuList007 *the palette page's entry grid */
#define MAP_EDITOR_PANEL_MARKER_LIST 0x5C /* MenuList007 *the page markers row */

/* The editor's unit-count table: 5 player rows of 12 unit categories of units
 * on the map.  A second table caches one unit total per player. */
#define MAP_EDITOR_UNIT_ROWS     5
#define MAP_EDITOR_UNIT_STRIDE   12

/* First OBJ palette shadow row (0x20 bytes each) the four players' army-colour
 * palettes are copied into, one row per player, when the editor refreshes. */
#define MAP_EDITOR_PLAYER_PALETTE_ROW 0x15

#endif
