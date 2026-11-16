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

#endif
