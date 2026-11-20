/* The ov003 link map-select screen: each side of a link battle picks up to
 * MAP_PICK_SLOTS maps out of the map list, and one map can only be picked by
 * one side.  Both sides' picks live in one record, the block the screen objects
 * hold at +0x44 (the pick helpers take that block +4, so their two lists are
 * +4 and +0xE from their argument).
 */
#ifndef OV003_MAPSELECT_H
#define OV003_MAPSELECT_H

#include "common.h"

#define MAP_PICK_SLOTS 5      /* maps one side may pick */
#define MAP_PICK_EMPTY 0xFFFF /* an empty slot of a side's pick list */
#define MAP_PICK_NOT_FOUND 0xFF /* FindMapPick result when the map is not picked */

/* gOv003SceneState+0: whether the map-select screen may confirm its chosen map
 * (GetMapConfirmState, ApplyMapConfirmState). */
#define MAP_CONFIRM_UNSET    0
#define MAP_CONFIRM_ENABLED  1
#define MAP_CONFIRM_DISABLED 2

typedef struct MapPickLists {
    u8  unknown0[8];   /* +0x00 */
    u16 first[5];      /* +0x08 maps the first side picked, MAP_PICK_NONE = empty */
    u16 second[5];     /* +0x12 maps the second side picked, MAP_PICK_NONE = empty */
} MapPickLists;

#endif
