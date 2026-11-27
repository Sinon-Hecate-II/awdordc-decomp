/* The map editor's state block, its palette-panel object and its cached unit
 * counts: the current palette page, the terrain and unit brushes, the player
 * and unit counts and the modified flag.  The editor's accessors live in
 * ov007_02211200. */
#ifndef OV007_MAP_EDITOR_H
#define OV007_MAP_EDITOR_H

#define MAP_EDITOR_MODE          0x00 /* u8 0 = terrain palette page, 1 = unit palette page */
#define MAP_EDITOR_TERRAIN_OWNER 0x01 /* u8 owner (bits 5..7) the terrain brush paints */
#define MAP_EDITOR_PLAYER_COUNT  0x02 /* u8 players in use (assigned to team 1) */
#define MAP_EDITOR_TEAM_MIN_PLAYERS 2 /* players in use needed for the map to have a team (MapEditor_PlayerHasTeam(-1)) */
#define MAP_EDITOR_TERRAIN_KIND  0x03 /* u8 terrain kind (bits 0..4) the terrain brush paints */
#define MAP_EDITOR_PROPERTY_COUNT 0x04 /* u8 total owned properties on the map (sum of the per-owner property grid) */
#define MAP_EDITOR_MODIFIED      0x05 /* u8 nonzero once the map was edited */
#define MAP_EDITOR_UNIT_FLAGS    0x06 /* u8 low 4 bits of the placed unit's record byte 0x0b */
#define MAP_EDITOR_UNIT_OWNER    0x07 /* u8 1-based owner the unit brush places */
#define MAP_EDITOR_UNIT_KIND     0x08 /* u8 unit kind the unit brush places */
#define MAP_EDITOR_TOOL          0x09 /* u8 the active editor tool (MAP_EDITOR_TOOL_*) */

/* The tool the editor applies to the cursor's cell (MAP_EDITOR_TOOL). */
enum {
    MAP_EDITOR_TOOL_PAINT  = 0, /* unit page: place the unit brush; terrain page: paint with the terrain brush */
    MAP_EDITOR_TOOL_PICK   = 1, /* copy the cell's unit/terrain into the brush */
    MAP_EDITOR_TOOL_ERASE  = 2, /* clear the cell's unit or terrain */
    MAP_EDITOR_TOOL_SELECT = 3  /* unit page: open the cell's menu; terrain page: paint the cell's region */
};

/* Page the palette shows (MAP_EDITOR_MODE). */
enum {
    MAP_EDITOR_PAGE_TERRAIN = 0,
    MAP_EDITOR_PAGE_UNIT    = 1
};

/* The editor scene object's one-frame input latch: set while the editor opens or
 * is suspended by a map menu; while set the update ignores keys that were already
 * held and clears the latch on the first fresh press. */
#define MAP_EDITOR_INPUT_LATCH   0x34 /* u8 */

/* The palette-panel object (the ov007 panel object GetPanelObject returns): the
 * palette page it shows and, in two parallel arrays indexed by that page, the
 * palette entry and the owner/colour the cursor points at.  Picking an entry
 * arms it (MAP_EDITOR_PANEL_PENDING); closing the panel applies it. */
#define MAP_EDITOR_PANEL_CLOSE   0x35 /* u8 nonzero to hide/close the panel */
#define MAP_EDITOR_PANEL_PENDING 0x36 /* u8 nonzero once the cursor picked a palette entry */
#define MAP_EDITOR_PANEL_PAGE    0x37 /* u8 palette page the panel shows (MAP_EDITOR_MODE) */
#define MAP_EDITOR_PANEL_OWNER   0x38 /* s8[2] owner/colour index per page */
#define MAP_EDITOR_OWNER_NEUTRAL 4    /* terrain-page owner index that paints neutral ground: an HQ entry (MAP_TERRAIN_HQ) cannot be picked for it */
#define MAP_EDITOR_OWNER_COLOR_COUNT 5 /* owner/colour slots: the four army colours plus neutral */
#define MAP_EDITOR_PANEL_ENTRY   0x3A /* s8[2] selected palette entry index per page */
#define MAP_EDITOR_PALETTE_ENTRY_SIZE 5 /* bytes per palette entry record (kind, x, y, and two sprite fields) */

/* The palette panel's two list objects (each a MenuList007 built by
 * MapEditor_RebuildPaletteLists): the page's entry grid and the page markers row. */
#define MAP_EDITOR_PANEL_ENTRY_LIST  0x58 /* MenuList007 *the palette page's entry grid */
#define MAP_EDITOR_PANEL_MARKER_LIST 0x5C /* MenuList007 *the page markers row */

/* The map editor's fill dialog (a 3D sprite from gMapEditorFillDialogClass):
 * MapEditor_OpenFillDialog stores the preset FillMapTerrain should paint with,
 * and confirming the dialog (MapEditor_ApplyFillPreset, the class's +0x3C
 * callback) applies it. */
#define MAP_EDITOR_FILL_PRESET 0x5C /* s32 FillMapTerrain preset (-1 clears the map) */

/* The map editor's resize panel (a 3D sprite that shows and edits the map size):
 * the width and height the player has entered, drawn as the panel's two numbers
 * and used when the dialog is confirmed to start the deferred resize. */
#define MAP_EDITOR_RESIZE_WIDTH  0x34 /* s32 map width */
#define MAP_EDITOR_RESIZE_HEIGHT 0x38 /* s32 map height */

/* Prompt texts (SetUiMessageText ids) of the fill menu's entries. */
#define MAP_EDITOR_FILL_SEA              8 /* FillMapTerrain preset: every cell becomes sea (MAP_TILE_SEA on terrain kind 8) */
#define MAP_EDITOR_FILL_MESSAGE_SEA      0x46000000
#define MAP_EDITOR_FILL_MESSAGE_PLAIN    0x46000001
#define MAP_EDITOR_FILL_MESSAGE_WOODS    0x46000002
#define MAP_EDITOR_FILL_MESSAGE_MOUNTAIN 0x46000003
#define MAP_EDITOR_FILL_MESSAGE_CLEAR    0x46000004

/* The editor's unit-count table: 5 player rows of 12 unit categories of units
 * on the map.  A second table caches one unit total per player. */
#define MAP_EDITOR_UNIT_ROWS     5
#define MAP_EDITOR_UNIT_STRIDE   12

/* First OBJ palette shadow row (0x20 bytes each) the four players' army-colour
 * palettes are copied into, one row per player, when the editor refreshes. */
#define MAP_EDITOR_PLAYER_PALETTE_ROW 0x15

/* Tile of the sub engine's texture the map name is rasterised at: the byte
 * offset given to RenderTextToTiles is this tile times 0x20. */
#define MAP_EDITOR_MAP_NAME_TILE 0x1CC

#endif
