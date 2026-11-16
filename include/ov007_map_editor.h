/* The map editor's state block and its cached unit counts: the current palette
 * page, the terrain and unit brushes, the player and unit counts and the
 * modified flag.  The editor's accessors live in ov007_02211200. */
#ifndef OV007_MAP_EDITOR_H
#define OV007_MAP_EDITOR_H

#define MAP_EDITOR_MODE          0x00 /* u8 0 = terrain palette page, 1 = unit palette page */
#define MAP_EDITOR_TERRAIN_KIND  0x01 /* u8 terrain kind the brush paints */
#define MAP_EDITOR_PLAYER_COUNT  0x02 /* u8 players in use (assigned to team 1) */
#define MAP_EDITOR_TERRAIN_OWNER 0x03 /* u8 owner the terrain brush paints */
#define MAP_EDITOR_UNIT_COUNT    0x04 /* u8 units placed on the map */
#define MAP_EDITOR_MODIFIED      0x05 /* u8 nonzero once the map was edited */
#define MAP_EDITOR_UNIT_KIND     0x06 /* u8 unit kind the unit brush places */
#define MAP_EDITOR_UNIT_OWNER    0x07 /* u8 1-based owner the unit brush places */
#define MAP_EDITOR_UNIT_FLAGS    0x08 /* u8 low 4 bits of the placed unit's record byte 0x0b */
#define MAP_EDITOR_COLOR         0x09 /* u8 player colour index 0..3 */

/* The editor's unit-count table: 5 player rows of 12 unit categories of units
 * on the map.  A second table caches one unit total per player. */
#define MAP_EDITOR_UNIT_ROWS     5
#define MAP_EDITOR_UNIT_STRIDE   12

#endif
