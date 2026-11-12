/* The ov003 unit-list menu object and its row entries (the cursor/command
 * panels that pick a unit or a command). */
#ifndef OV003_MENU_H
#define OV003_MENU_H

#define MENU_ACTION        0x34 /* u8 animation/action timer value */
#define MENU_FLAGS         0x38 /* u8 MENU_FLAG_* */
#define MENU_SELECTION     0x3C /* u8 *selection context: slots and current mode */
#define MENU_ROWS          0x48 /* row entry array, MENU_ROW_STRIDE bytes each */
#define MENU_SELECTED_UNIT 0x5C /* void ** selected unit, or 0 */

#define MENU_FLAG_PENDING  0x02 /* an action is queued for the next update */

#define MENU_ROW_STRIDE    0x24
#define MENU_ROW_DESC      0x00 /* pointer to the row's MENU_DESC_* descriptor */
#define MENU_ROW_ANIM_A    0x18 /* animations shown for an unselected row */
#define MENU_ROW_ANIM_B    0x1C
#define MENU_ROW_ANIM_C    0x20 /* shown for the selected row */

#define MENU_SELECTION_MODE 0x0F /* u8 current selection mode, indexes MENU_SELECTION_SLOTS */
#define MENU_SELECTION_SLOTS 0x00 /* u8[] row index selected in each mode */

/* Row descriptor header (the rest points at the row's text/unit data). */
#define MENU_DESC_TYPE   0x01 /* u8 MENU_ENTRY_* */
#define MENU_DESC_VALUE  0x02 /* u8 unit id / submenu value */

enum {
    MENU_ENTRY_UNIT    = 1, /* select the unit in the row */
    MENU_ENTRY_INFO    = 2, /* show the row's information */
    MENU_ENTRY_SUBMENU = 3  /* open the row's submenu */
};

/* A value counter inside an ov003 options-menu entry. StepCounter is handed the
 * address of the entry's flag byte; the value, maximum and minimum sit at
 * +0x04/+0x08/+0x0C from there and the wrap flag at +0x14 (callers in
 * ov003_021EBEC0.c / ov003_021ED8F0.c pass an entry + 0x14). */
typedef struct OptionCounter {
    s32 filler_00;  /* +0x00 */
    s32 value;      /* +0x04 current value */
    s32 maximum;    /* +0x08 upper bound of the range */
    s32 minimum;    /* +0x0C lower bound of the range */
    s32 filler_10;  /* +0x10 */
    u8  wrap;       /* +0x14 nonzero: wrap around [minimum,maximum], else clamp */
} OptionCounter;

#endif
