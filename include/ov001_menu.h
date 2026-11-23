/* The ov001 Wi-Fi option menu (gOv001MenuLayout): the loaded layout resource
 * followed by the handles of the five option rows.  The row tables hold five
 * entries per menu variant, the variant being picked by the caller. */
#ifndef OV001_MENU_H
#define OV001_MENU_H

/* BG1 highlight tilemaps begin with the Wi-Fi and AP screen layouts. */
enum {
    OV001_HIGHLIGHT_LAYOUT_WIFI = 0,
    OV001_HIGHLIGHT_LAYOUT_AP = 1,
    OV001_HIGHLIGHT_TILEMAP_BYTES = 192,
    OV001_HIGHLIGHT_TILEMAP_ALIGNMENT = 4
};

#define OV001_MENU_ROWS       5    /* option rows the menu shows */
#define OV001_MENU_HANDLES    7    /* s32 handles: the rows, then the slide task and a flag */
#define OV001_MENU_TASK_SLOT  5    /* index of the slide task handle */
#define OV001_MENU_FILE       0x00 /* void *: loaded menu layout resource */
#define OV001_MENU_LAYOUT_SIZE 0x600 /* bytes of the loaded layout resource */
#define OV001_MENU_SPRITES    0x04 /* s32 *: OV001_MENU_HANDLES sprite handles */

/* The ov001 region-column menu (gOv001RegionMenu): a vertical column of sprites
 * for the region the player is choosing, opened by a fade and a slide from the
 * bottom of the screen. */
#define OV001_REGION_SPRITE_TOP    0x00 /* s32 handle of the column's first sprite */
#define OV001_REGION_SPRITE_BOTTOM 0x04 /* s32 handle of the second sprite, 8 pixels below */
#define OV001_REGION_ITEM_SPRITES  0x08 /* s32 item sprite handles, 4 bytes each */
#define OV001_REGION_TEXT_PANEL    0x10 /* s32 text panel showing the region's text */
#define OV001_REGION_TASK          0x14 /* s32 id of the task animating or reading the menu */
#define OV001_REGION_TIMER         0x18 /* u16 frames the empty region's menu stays up */
#define OV001_REGION_BLEND         0x1A /* s8 blend level the fade step animates */
#define OV001_REGION_SELECTED      0x1B /* s8 selected item: -1 none, -2 before input starts */
#define OV001_REGION_INDEX         0x1C /* u8 region the menu shows, index into the region tables */
#define OV001_REGION_FADE_STEP     0x1D /* u8 fade step counter */
#define OV001_REGION_FADE_OUT      0x1E /* u8 nonzero: fade the menu out before closing it */

/* The region with no items just waits before closing instead of taking input. */
#define OV001_REGION_EMPTY 5

/* Frames an empty region's menu stays up before it closes. */
#define OV001_REGION_EMPTY_TIMEOUT 120U

/* Pixels a frame the column slides up when its menu opens. */
#define OV001_REGION_OPEN_STEP 12

/* Blend level (OV001_REGION_BLEND) the region menu's open fade steps down to and
 * its close fade steps back up from; a negative BLDY fades through the backdrop. */
#define OV001_REGION_FADE_LEVEL (-12)

/* The small ov001 message box (Ov001_ShowMessageBox): a text panel with the
 * message drawn in this rectangle, in palette row 2, then closed again. */
#define OV001_MESSAGE_BOX_X      13  /* pixels from the panel's left */
#define OV001_MESSAGE_BOX_Y      40  /* pixels from the panel's top */
#define OV001_MESSAGE_BOX_WIDTH  230 /* pixels */
#define OV001_MESSAGE_BOX_HEIGHT 112 /* pixels */
#define OV001_MESSAGE_BOX_COLOR  2   /* text palette row */

/* gOv001RegionYs holds two u16 per region; the first is the y the region's open
 * column rests at, read at region * OV001_REGION_Y_STRIDE. */
#define OV001_REGION_Y_STRIDE 2

/* The shared icon row starts off the bottom edge of the screen, rises four
 * pixels a frame, and stops at its resting y once it has slid in. */
#define OV001_ICON_ROW_HIDDEN_Y 192 /* y the row waits at below the screen */
#define OV001_ICON_ROW_REST_Y   168 /* y the row rests at once in view */
#define OV001_ICON_ROW_STEP     4   /* pixels the row moves each frame */
#define OV001_ICON_ROW_INTRO_FRAMES 4 /* frames the row counts out before it takes input */

#endif
