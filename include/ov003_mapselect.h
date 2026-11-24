/* The ov003 link map-select screen: each side of a link battle picks up to
 * MAP_PICK_SLOTS maps out of the map list, and one map can only be picked by
 * one side.  Both sides' picks live in one record, the block the screen objects
 * hold at +0x44 (the pick helpers take that block +4, so their two lists are
 * +4 and +0xE from their argument).
 */
#ifndef OV003_MAPSELECT_H
#define OV003_MAPSELECT_H

#include "common.h"
#include "ds3dsprite.h"

#define MAP_PICK_SLOTS 5      /* maps one side may pick */
#define MAP_PICK_EMPTY 0xFFFF /* an empty slot of a side's pick list */
#define MAP_PICK_NOT_FOUND 0xFF /* FindMapPick result when the map is not picked */

/* gOv003SceneState+0: whether the map-select screen may confirm its chosen map
 * (GetMapConfirmState, ApplyMapConfirmState). */
#define MAP_CONFIRM_UNSET    0
#define MAP_CONFIRM_ENABLED  1
#define MAP_CONFIRM_DISABLED 2

/* gOv003SceneState+4: the slide the scene was entered with (set by the battle
 * scene start and the link map-transfer start); the scene entry offset helper
 * turns it into the offset the scene's sprites start from. */
#define SCENE_ENTRY_STATE 0x04 /* u8, one of SCENE_ENTRY_* */
#define SCENE_ENTRY_NONE  0    /* the scene does not slide */
#define SCENE_ENTRY_RIGHT 1    /* the scene slides in from +0x100 */
#define SCENE_ENTRY_LEFT  2    /* the scene slides in from -0x100 */

/* A scene sprite definition (one screen object keeps it at +0x3C): the engine
 * it is drawn on and the sprite sheet tiles and palette its 3D sprite loads.
 * The scene's 3D sprite is built from it. */
typedef struct SceneSpriteDef {
    u8  targetScreen; /* +0x00 DS3D_TARGET_* engine the sprite is drawn on */
    u8  bank;         /* +0x01 sprite bank slot the tiles and palette load into */
    u8  unknown02;    /* +0x02 */
    u8  unknown03;    /* +0x03 */
    u32 tile;         /* +0x04 tile index in the sprite sheet */
    u8  palette;      /* +0x08 palette index in the sprite sheet */
} SceneSpriteDef;

typedef struct MapPickLists {
    u8  unknown0[8];   /* +0x00 */
    u16 first[5];      /* +0x08 maps the first side picked, MAP_PICK_NONE = empty */
    u16 second[5];     /* +0x12 maps the second side picked, MAP_PICK_NONE = empty */
} MapPickLists;

/* The shared 6-byte scene layer descriptor (gSceneConfig+4), also the block
 * a map-select entry keeps at +0x38: which screens show a wallpaper and on which
 * sprite layer and palette. */
#define SCENE_LAYER_MAIN_ON      0 /* u8: nonzero to set up the main screen */
#define SCENE_LAYER_MAIN_LAYER   1 /* u8: main-screen wallpaper sprite layer */
#define SCENE_LAYER_MAIN_PALETTE 2 /* u8: main-screen wallpaper palette */
#define SCENE_LAYER_SUB_ON       3 /* u8: nonzero to set up the sub screen */
#define SCENE_LAYER_SUB_LAYER    4 /* u8: sub-screen wallpaper sprite layer */
#define SCENE_LAYER_SUB_PALETTE  5 /* u8: sub-screen wallpaper palette */

/* The scene's shared config (gSceneConfig, 16 bytes): what the scene builds its
 * 3D sprite from, the layer descriptor it applies, and the layout preset each
 * 2D engine was last given. */
#define SCENE_CONFIG_DEFINITION  0x00 /* SceneSpriteDef *the scene's 3D sprite is built from */
#define SCENE_CONFIG_LAYERS      0x04 /* u8 *its 6-byte layer descriptor (SCENE_LAYER_*) */
#define SCENE_CONFIG_MAIN_LAYOUT 0x08 /* DS3DSpriteLayoutConfig *applied on the main engine */
#define SCENE_CONFIG_SUB_LAYOUT  0x0C /* the preset applied on the sub engine */

/* The scene's per-engine BG-layer override table (gSceneLayerOverrides):
 * [engine][layer], nonzero forcing that layer on for the scene.  The main 2D
 * engine is row 0 and the sub engine row 1; each row has the four layers
 * ApplySceneLayerVisibility shows.  It starts zeroed at each scene entry. */
#define SCENE_ENGINE_MAIN  0 /* row of gSceneLayerOverrides used by the main engine */
#define SCENE_ENGINE_SUB   1 /* row used by the sub engine */
#define SCENE_ENGINE_COUNT 2 /* rows in gSceneLayerOverrides */
#define SCENE_LAYER_COUNT  4 /* layers in each row of gSceneLayerOverrides */
extern s32 gSceneLayerOverrides[SCENE_ENGINE_COUNT][SCENE_LAYER_COUNT];

#endif
