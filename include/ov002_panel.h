/* A player's status panel on the versus screen: two 0x68-byte panels that list
 * up to five stat entries, each an s16 value and a 3-bit icon index, built in
 * the order of a shuffled index table and filled only while the player is in
 * the match.  The panel code lives in ov002_021E24E8/ov002_021E3210. */
#ifndef OV002_PANEL_H
#define OV002_PANEL_H

#define PANEL_SIZE         0x68 /* bytes per player panel */
#define PANEL_STAT_TABLE   0x04 /* u8 *CO stat values: [0] base, [3..7] / [8..12] per-entry values */
#define PANEL_STAT_STATE   0x08 /* u8[5] x and y comparison state per stat: 0 below, 1 equal, 2 above */
#define PANEL_STAT_ORDER   0x17 /* u8[5] order the stat entries are built in */
#define PANEL_ENTRIES      0x22 /* PanelStat[5] stat entries */
#define PANEL_OTHER        0x60 /* void *the other player's panel */
#define PANEL_PLAYER       0x64 /* u8 player index (0 or 1) this panel belongs to */
#define PANEL_ENTRY_COUNT  0x66 /* u8 number of stat entries filled in */

#endif
