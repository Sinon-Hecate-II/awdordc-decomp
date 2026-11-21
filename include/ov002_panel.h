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
#define PANEL_STAT_SOURCE  0x36 /* PanelStat[5]: the player's own stat values, compared against the other panel's */
#define PANEL_STAT_DISPLAY 0x4a /* PanelStat[5]: those values rebased onto the other player and drawn as the gauge entries */
#define PANEL_GAUGES_SHOWN 0x65 /* u8 nonzero when the player's CO gauge entries are drawn (CO record byte 0x3C) */

/* One side's battle unit view on the versus screen (gUnitViews): the HP-gauge
 * animation and the character effect drawn for that player.  The two views lie
 * UNIT_VIEW_SIZE bytes apart: gUnitViews for player 0 and gUnitViewsP2 for
 * player 1. */
#define UNIT_VIEW_GAUGE_FRAME  0x00 /* u8 elapsed frame of the HP-gauge fill */
#define UNIT_VIEW_GAUGE_LENGTH 0x01 /* u8 frames the gauge fill takes */
#define UNIT_VIEW_Y            0x02 /* s8 vertical offset of the panel */
#define UNIT_VIEW_FLAGS        0x03 /* u8 NibbleFlags: low = player index, high nonzero while the gauge animates */
#define UNIT_VIEW_EXPRESSION   0x04 /* s8 character expression, -1 = none */
#define UNIT_VIEW_SHAKE        0x05 /* u8 frames of screenshake left */
#define UNIT_VIEW_COLOR        0x06 /* u16 gauge/panel colour */
#define UNIT_VIEW_SLOTS        0x08 /* void *[5]: the unit models the view draws, 4 bytes apart */
#define UNIT_VIEW_SCALE        0x1C /* u16 8.8 scale applied to the view's 3D sprite (0x100 = 1.0) */
#define UNIT_VIEW_X            0x1E /* s16 x of the gauge/effect sprite */
#define UNIT_VIEW_SPRITE_X     0x20 /* s16 x added to the sprite's 3D position */
#define UNIT_VIEW_SHAKE_X      0x22 /* s16 horizontal screenshake offset */
#define UNIT_VIEW_SHAKE_Y      0x24 /* s16 vertical screenshake offset */
#define UNIT_VIEW_SHAKE_INDEX  0x26 /* s8 index into gUnitViewShakeOffsets, -1 = no shake */
#define UNIT_VIEW_SIDE         0x27 /* u8 effect side: 0 for gUnitViews, 1 for gUnitViewsP2 */
#define UNIT_VIEW_EFFECT_ON    0x28 /* u8 nonzero while the side's CO effect is displayed */
#define UNIT_VIEW_FRAME        0x29 /* u8 frames the view has been stepping, wraps at 128 */
#define UNIT_VIEW_CO_EFFECT    0x2A /* u8 nonzero when the side shows its single zoomed CO-effect unit */
#define UNIT_VIEW_EFFECT_FRAME 0x2B /* u8 effect frame (tens of HP) handed to ReplaceSlotSound */
#define UNIT_VIEW_SIZE         0x2C

/* The battle scene's shared state (gBattleSceneState): the phase its per-frame
 * step is in, a frame counter inside that phase, the delay before it ends and
 * whether it may be ended yet. */
#define BATTLE_SCENE_FRAME     0x00 /* s32 frames elapsed in the current phase */
#define BATTLE_SCENE_END_DELAY 0x04 /* s32 frames the scene has been ending for */
#define BATTLE_SCENE_PHASE     0x08 /* u8 BATTLE_SCENE_PHASE_* */
#define BATTLE_SCENE_READY     0x09 /* u8 nonzero once the scene may be ended */
enum {
    BATTLE_SCENE_PHASE_SETUP    = 0,
    BATTLE_SCENE_PHASE_SLIDE_IN = 1, /* panels and sprites slide in over 32 frames */
    BATTLE_SCENE_PHASE_HOLD     = 2, /* hold the posed scene for 32 frames */
    BATTLE_SCENE_PHASE_EFFECTS  = 3  /* play the battle's effect script */
};

/* The versus screen's per-player data, VERSUS_DATA_STRIDE bytes per player.  The
 * fields are named as separate arrays in the game's symbols, each indexed by
 * player * VERSUS_DATA_STRIDE; gVersusPlayerHp is the HP the gauge animates to. */
#define VERSUS_DATA_STRIDE 0x18
#define VERSUS_DATA_COUNTRY 0x01 /* u8 country/army id that picks the player's screen assets */

/* Effect node (ov002 effect system), 0x88 bytes; built by Ov002_AddEffectNode
 * and animated by UpdateEffectNode. */
#define FX_NODE_RESOURCE    0x00 /* void *resource/particle the node draws */
#define FX_NODE_ID          0x04 /* s32 resource id */
#define FX_NODE_CHILD       0x08 /* void *first child node */
#define FX_NODE_NEXT        0x0C /* void *newest child link; older children follow it */
/* A node's children are a chain: the newest child is FX_NODE_CHILD and the older
 * ones hang off FX_NODE_NEXT as links of a node pointer and the next (older) link. */
#define FX_LINK_NODE        0x00 /* void *child node */
#define FX_LINK_NEXT        0x04 /* void *next, older link or NULL */
#define FX_NODE_FRAME_OFFSETS 0x10 /* s32 *table of frame offsets from the resource base */
#define FX_NODE_FRAME_DATA    0x14 /* void *current frame data */
#define FX_NODE_SCRIPT_START  0x18 /* void *first command in the selected script */
#define FX_NODE_SCRIPT_NEXT   0x1C /* void *next command */
#define FX_NODE_FRAME_COMMAND 0x20 /* void *command for the current timed frame */
#define FX_NODE_BLEND_COMMAND 0x24 /* void *active blend command */
#define FX_NODE_FRAME_TICKS   0x30 /* s32 ticks remaining in the current frame */
#define FX_NODE_SCRIPT_TICKS  0x34 /* s32 ticks elapsed since script start */
#define FX_NODE_SHAPE         0x38 /* u16 */
#define FX_NODE_KIND          0x3A /* u8 */
#define FX_NODE_SCRIPT_SCALE  0x42 /* u16 scale in 8.8 */
#define FX_NODE_STEP_X        0x44 /* s8 pixels added to X each tick */
#define FX_NODE_STEP_Y        0x45 /* s8 pixels added to Y each tick */
#define FX_NODE_SCRIPT_INDEX  0x46 /* u8 selected script */
#define FX_NODE_POLYGON_SLOT  0x4D /* u8 offset from the node's base polygon ID */
#define FX_NODE_POLYGON_ALPHA 0x4E /* u8 polygon alpha */
#define FX_SCRIPT_SCALE_ONE   0x100
#define FX_POLYGON_ALPHA_MAX  31

#define FX_NODE_GRAPHIC_X   0x28 /* s32 graphic offset copied from the template's FX_TEMPLATE_X/Y */
#define FX_NODE_GRAPHIC_Y   0x2C
#define FX_NODE_PALETTE_ALT 0x3B /* u8 palette drawn on flash phase 0 */
#define FX_NODE_X           0x3C /* s16 translation, whole pixels */
#define FX_NODE_Y           0x3E
#define FX_NODE_Z           0x40
#define FX_NODE_SPEED       0x42 /* u16 speed used to fold the node's scale into the drawing */
#define FX_NODE_TABLE_INDEX 0x47 /* u8 row in the CO's effect tables */
#define FX_NODE_FLASH_FRAMES 0x48 /* u8 flash countdown; one tick every three frames */
#define FX_NODE_FLASH_PHASE 0x49 /* u8 frame 0..2 inside the current flash tick */
#define FX_NODE_COLOUR_BLEND 0x4B /* u8 colour blend copied from the template */
#define FX_NODE_COLOUR      0x4C /* u8 */
#define FX_NODE_ACTIVE      0x50 /* u8 animated flag */
#define FX_NODE_FLAG_51     0x51 /* u8 */
#define FX_NODE_FLASH_CHILD 0x52 /* u8 nonzero: the node flashes along with its parent */
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

/* The effect node's selected script is an array of FX_SCRIPT_COMMAND_SIZE-byte
 * commands ending in an FX_SCRIPT_CMD_END opcode.  A command with a frame count
 * runs for that many ticks; one with 0 frames runs at once. */
#define FX_SCRIPT_COMMAND_SIZE 0x0C
#define FX_SCRIPT_CMD_FRAMES   0x00 /* u8 ticks the command takes, 0 = immediate */
#define FX_SCRIPT_CMD_OPCODE   0x01 /* u8 operation; 0xFF ends the script */
#define FX_SCRIPT_CMD_ARG0     0x08 /* s16 first argument */
#define FX_SCRIPT_CMD_ARG1     0x0A /* s16 second argument */
#define FX_SCRIPT_CMD_END      0xFF
#define FX_SCRIPT_OP_STOP      0x00 /* stop the script */
#define FX_SCRIPT_OP_LOOP      0x01 /* restart the script from the beginning */
#define FX_SCRIPT_OP_FINISH    0x02 /* run the node's finish callback and free it */
#define FX_SCRIPT_OP_JUMP      0x06 /* jump to the command matching ARG0 */

/* Screen bounds (whole pixels) of an effect node: one still accelerating towards
 * an edge it has passed is off-screen and gets finished by its handler. */
#define FX_CULL_LEFT   (-0xA0)
#define FX_CULL_TOP    (-0x20)
#define FX_CULL_RIGHT  0xA0
#define FX_CULL_BOTTOM 0xE0

#endif
