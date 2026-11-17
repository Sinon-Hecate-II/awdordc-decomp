/* The scrolling list widget of the menus (list code in main_020AA93C.c,
 * main_020AB4C0.c and main_020AB884.c).  The window is anchored at an item
 * index (the first visible item) and slides a row at a time: the index is split
 * into rows and columns, and each part is scaled by its pixel size to give the
 * pixel offset of the grid's sprite.  With wrap set, a position past either end
 * jumps to the other end instead of clamping.  Only the fields the list code
 * uses are named here. */
#ifndef LIST_WIDGET_H
#define LIST_WIDGET_H

#define LIST_WIDGET_PENDING        0x04 /* u8 nonzero after the cursor moved; UpdateListScroll consumes it */
#define LIST_WIDGET_VISIBLE_ROWS   0x06 /* s16 rows of items the window shows at once */
#define LIST_WIDGET_ITEMS_PER_ROW  0x08 /* s16 items in one row of the list */
#define LIST_WIDGET_ROW_HEIGHT     0x0a /* u8 height of a row in pixels */
#define LIST_WIDGET_COLUMN_WIDTH   0x0b /* u8 width of a column in pixels */
#define LIST_WIDGET_CURSOR         0x0c /* s16 index of the selected item */
#define LIST_WIDGET_SCROLL         0x14 /* s32 index of the first visible item */
#define LIST_WIDGET_SCROLL_MAX     0x18 /* s32 highest allowed first-visible index */
#define LIST_WIDGET_SCROLL_MIN     0x1c /* s32 lowest allowed first-visible index */
#define LIST_WIDGET_WRAP           0x24 /* u8 nonzero: positions wrap around [min,max] */

#define LIST_WIDGET_PIXEL_OFFSET_X 0x2c /* s16 horizontal pixel offset of the window */
#define LIST_WIDGET_PIXEL_OFFSET_Y 0x2e /* s16 vertical pixel offset of the window */

/* The window's own slide: an x offset, the y offset the slide is heading to
 * (compared against the tween to tell when the slide has arrived) and the
 * SpriteTween at +0x30 that animates the window's vertical position. */
#define LIST_WIDGET_OFFSET_X        0x28 /* s16 window x pixel offset */
#define LIST_WIDGET_SLIDE_TARGET_Y  0x2a /* s16 y pixel offset the slide is heading to */
#define LIST_WIDGET_SCROLL_TWEEN   0x30 /* SpriteTween: animated vertical position */
#define LIST_WIDGET_SCROLL_CURRENT 0x32 /* u16 tween time */
#define LIST_WIDGET_SCROLL_START   0x34 /* u16 time the tween restarts from */
#define LIST_WIDGET_SCROLL_FRAMES  0x3c /* s16 tween length in frames */
#define LIST_WIDGET_SCROLL_FROM    0x3e /* s16 pixel offset the tween starts at */
#define LIST_WIDGET_SCROLL_TO      0x40 /* s16 pixel offset the tween ends at */

/* The two sub-lists that carry the current and column/row animation values:
 * the offset the sprite is animating from and the offset it moves to. */
#define LIST_WIDGET_ANIM_X         0x50 /* s16 column sub-list's current animation value */
#define LIST_WIDGET_TARGET_X       0x52 /* s16 column sub-list offset it animates to */
#define LIST_WIDGET_ANIM_Y         0x62 /* s16 row sub-list's current animation value */
#define LIST_WIDGET_TARGET_Y       0x64 /* s16 row sub-list offset it animates to */

#endif
