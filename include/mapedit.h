/* The map editor (ov007) entry list and the softkey bar of the bottom screen.
 *
 * The softkey bar comes in three regional variants - US, EU and JP - each with its own
 * layout table and its own "softkey_xx.sc" graphics.  A button cycles through them.
 */
#ifndef MAPEDIT_H
#define MAPEDIT_H

enum {
    SOFTKEY_MODE_US = 0x64,
    SOFTKEY_MODE_EU = 0x65,
    SOFTKEY_MODE_JP = 0x66,
    SOFTKEY_DELETE = 0x67,
    SOFTKEY_ACCENT = 0x68,
    SOFTKEY_CANCEL = 0x69,
    SOFTKEY_CONFIRM = 0x6A
};

/* The widget the map editor's entry list is made of; the input handler works on it.
 * Read and written with M2C_FIELD(); the offsets below are the ones the code uses. */
typedef struct MapEditList {
    void *layout;      /* +0x34 softkey layout table of the current region */
    void *label;       /* +0x38 the label of the selected entry */
    s8   selected;     /* +0x3C index of the selected entry */
    s16  scrollPos;    /* +0x3E current scroll position of the list */
    s16  scrollTarget; /* +0x40 the position the list is scrolling to */
    void *panel;       /* +0x44 the panel the list is drawn in */
} MapEditList;

/* Offsets of the list widget object the MapEditList members above sit in, from
 * the object's base (+0x00 holds the widget's vtable). */
#define MAP_EDIT_LIST_LAYOUT        0x34 /* void *: softkey layout table of the current region */
#define MAP_EDIT_LIST_LABEL         0x38 /* void *: the label of the selected entry */
#define MAP_EDIT_LIST_SELECTED      0x3C /* s8: index of the selected entry */
#define MAP_EDIT_LIST_SCROLL_POS    0x3E /* s16: current scroll position of the list */
#define MAP_EDIT_LIST_SCROLL_TARGET 0x40 /* s16: the position the list is scrolling to */
#define MAP_EDIT_LIST_PANEL         0x44 /* void *: the panel the list is drawn in */

#endif
