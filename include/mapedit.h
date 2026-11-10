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
    SOFTKEY_MODE_JP = 0x66
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

#endif
