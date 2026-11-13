/* The scrollable menu list driven by the list code in main_020B8078.c: six rows
 * are visible at once and the selection is tracked both as the row within the
 * visible window and as the window's first row.  Only the fields the code uses
 * are named here. */
#ifndef MENU_LIST_H
#define MENU_LIST_H

#define MENU_LIST_VISIBLE_ROWS  6    /* rows the list shows at once */
#define MENU_LIST_PREV_ROW      0x36 /* s16 absolute row selected before the last move */
#define MENU_LIST_ABS_ROW       0x38 /* s16 absolute row selected */
#define MENU_LIST_ROW           0x3a /* s16 selected row within the visible window */
#define MENU_LIST_SCROLLING     0x3c /* s16 nonzero while the window is being redrawn */
#define MENU_LIST_SCROLL_OFFSET 0x3e /* s16 animated pixel offset of the window */
#define MENU_LIST_FIRST_ROW     0x40 /* s16 first visible row */
#define MENU_LIST_ROW_COUNT     0x42 /* s16 number of rows in the list */
#define MENU_LIST_REPEAT_DELAY  0x46 /* s16 frames left before a held key repeats */

#endif
