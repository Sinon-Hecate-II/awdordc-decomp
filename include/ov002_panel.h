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

/* Effect node (ov002 effect system), 0x88 bytes; built by Ov002_AddEffectNode
 * and animated by func_ov002_021e2aa8. */
#define FX_NODE_RESOURCE    0x00 /* void *resource/particle the node draws */
#define FX_NODE_ID          0x04 /* s32 resource id */
#define FX_NODE_CHILD       0x08 /* void *first child node */
#define FX_NODE_NEXT        0x0C /* void *next sibling node */
#define FX_NODE_GRAPHIC_X   0x28 /* s32 graphic offset copied from the template's FX_TEMPLATE_X/Y */
#define FX_NODE_GRAPHIC_Y   0x2C
#define FX_NODE_X           0x3C /* s16 translation, whole pixels */
#define FX_NODE_Y           0x3E
#define FX_NODE_Z           0x40
#define FX_NODE_SPEED       0x42 /* u16 speed used to fold the node's scale into the drawing */
#define FX_NODE_TABLE_INDEX 0x47 /* u8 row in the CO's effect tables */
#define FX_NODE_COLOUR_BLEND 0x4B /* u8 colour blend copied from the template */
#define FX_NODE_COLOUR      0x4C /* u8 */
#define FX_NODE_ACTIVE      0x50 /* u8 animated flag */
#define FX_NODE_FLAG_51     0x51 /* u8 */
#define FX_NODE_PALETTE     0x53 /* u8 palette/effect bank */
#define FX_NODE_X_FIXED     0x54 /* s32 position and velocity in 8.8 pixels */
#define FX_NODE_Y_FIXED     0x58
#define FX_NODE_VX          0x5C /* s32 per-tick velocity */
#define FX_NODE_VY          0x60
#define FX_NODE_AX          0x64 /* s32 per-tick acceleration */
#define FX_NODE_AY          0x68
#define FX_NODE_LIFETIME    0x6C /* s32 ticks left, -1 = finished */
#define FX_NODE_DURATION    0x70 /* s32 */
#define FX_NODE_TARGET      0x74 /* s32 */
#define FX_NODE_SCALE       0x78 /* u16 current scale in 8.8 */
#define FX_NODE_SCALE_FROM  0x7A /* s16 */
#define FX_NODE_SCALE_TO    0x7C /* s16 */
#define FX_NODE_SCALE_STEP  0x7E /* s16 */
#define FX_NODE_SCREEN_X    0x80 /* s16 screen drift, added to the position scaled by FX_NODE_SCREEN_S */
#define FX_NODE_SCREEN_Y    0x82
#define FX_NODE_SCREEN_S    0x84 /* u16 */
#define FX_NODE_MODE_86     0x86 /* u16: nonzero = move while scaling (set by SetEffectNodeTransform) */

/* Node offsets inside the template the caller passes to Ov002_AddEffectNode. */
#define FX_TEMPLATE_SOURCE_ID   0x04 /* s32 resource id */
#define FX_TEMPLATE_CHILD       0x08 /* void *child nodes */
#define FX_TEMPLATE_NEXT        0x0C
#define FX_TEMPLATE_X           0x1C /* s32 x copied to the node's */
#define FX_TEMPLATE_Y           0x24 /* s32 y */
#define FX_TEMPLATE_SHAPE       0x38 /* u16 */
#define FX_TEMPLATE_KIND        0x3A /* u8 */
#define FX_TEMPLATE_TABLE_INDEX 0x47 /* u8 row in the CO's effect tables */
#define FX_TEMPLATE_COLOUR_BLEND 0x4B /* u8 */
#define FX_TEMPLATE_ACTIVE      0x50 /* u8 */
#define FX_TEMPLATE_FLAG_51     0x51 /* u8 */
#define FX_TEMPLATE_PALETTE     0x53 /* u8 */

#endif
