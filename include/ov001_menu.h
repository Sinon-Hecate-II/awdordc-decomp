/* The ov001 Wi-Fi option menu (gOv001MenuLayout): the loaded layout resource
 * followed by the handles of the five option rows.  The row tables hold five
 * entries per menu variant, the variant being picked by the caller. */
#ifndef OV001_MENU_H
#define OV001_MENU_H

#define OV001_MENU_ROWS       5    /* option rows the menu shows */
#define OV001_MENU_HANDLES    7    /* s32 handles: the rows, then the slide task and a flag */
#define OV001_MENU_TASK_SLOT  5    /* index of the slide task handle */
#define OV001_MENU_FILE       0x00 /* void *: loaded menu layout resource */
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

/* Pixels a frame the column slides up when its menu opens. */
#define OV001_REGION_OPEN_STEP 12

/* gOv001RegionYs holds two u16 per region; the first is the y the region's open
 * column rests at, read at region * OV001_REGION_Y_STRIDE. */
#define OV001_REGION_Y_STRIDE 2

#endif
