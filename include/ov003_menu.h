/* The ov003 unit-list menu object and its row entries (the cursor/command
 * panels that pick a unit or a command). */
#ifndef OV003_MENU_H
#define OV003_MENU_H

#define OV003_MENU_HELP_PANEL 0x58 /* Ov003HelpPanel * in the menu object */

enum {
    OV003_HELP_PANEL_HIDE_STEP = 6,
    OV003_HELP_PANEL_SHOW_STEP = -4
};

typedef struct Ov003HelpPanel {
    u8 showLabels;
    u8 slideFrame;
    s16 y;
    s16 targetY;
    s16 stepY;
    u8 labelCount;
    u8 unk_09[3];
    const void *labels[4];
} Ov003HelpPanel;

#define MENU_ACTION        0x34 /* u8 animation/action timer value */
#define MENU_FLAGS         0x38 /* u8 MENU_FLAG_* */
#define MENU_SELECTION     0x3C /* u8 *selection context: slots and current mode */
#define MENU_ROWS          0x48 /* row entry array, MENU_ROW_STRIDE bytes each */
#define MENU_SELECTED_UNIT 0x5C /* void ** selected unit, or 0 */

#define MENU_FLAG_PENDING  0x02 /* an action is queued for the next update */
#define MENU_FLAG_ANIM     0x08 /* a row animation is running */
#define MENU_FLAG_MODE     0x10 /* the mode byte in MENU_MODE has been set */
#define MENU_FLAG_SPLIT_SELECT 0x80 /* set while the split-row unit selection is active (mode 0) */

#define MENU_MODE          0x36 /* u8: MENU_MODE_FIRST/SECOND, the idle value 0xFF, or MENU_MODE_SHIFTed modes */
#define MENU_MODE_SHIFT    4    /* RequestMenuMode stores the mode shifted left by this (bytes 0x36..0x37) */
#define MENU_MODE_FIRST    1    /* modes 1 and 2 confirm the menu instead of running its action */
#define MENU_MODE_SECOND   2
#define MENU_SELECT_MODE   0x35 /* u8 nonzero once the mode was applied to the rows */
#define MENU_ROW_VALUE     0x10 /* u8 *selection context: the row's current value */
#define MENU_ROW_COUNT     0x0F /* u8 *selection context: number of rows */
#define MENU_MODE_IDLE     0xFF /* MENU_MODE value that means no mode switch is pending */

/* The option counters of the unit-list menu object: three OptionCounters whose
 * values are packed into the game settings word.  Ov003_StepOptionCounter0 steps the
 * first, Ov003_StepOptionCounter1 the second and func_ov003_0220ba70 the third. */
#define MENU_OPTION_COUNTERS 0x40 /* OptionCounter[3] in the menu object */
#define MENU_OPTION_STRIDE   0x18 /* sizeof(OptionCounter) */

#define MENU_ROW_STRIDE    0x24
#define MENU_ROW_DESC      0x00 /* pointer to the row's MENU_DESC_* descriptor */
#define MENU_ROW_ANIM_A    0x18 /* animations shown for an unselected row */
#define MENU_ROW_ANIM_B    0x1C
#define MENU_ROW_ANIM_C    0x20 /* shown for the selected row */

#define MENU_SELECTION_MODE 0x0F /* u8 current selection mode, indexes MENU_SELECTION_SLOTS */
#define MENU_SELECTION_SLOTS 0x00 /* u8[] row index selected in each mode */

/* MENU_SELECTION_MODE values: the layout the selection context is in.  Mode 8 is
 * the unit list whose rows 2, 3 and 4 are the three split option rows (rows 0/1
 * form a pair); the drawing code (ov003_0220856C.c) and the split-row predicate
 * pick those rows out. */
#define MENU_SELECT_MODE_SPLIT_ROWS 8

/* The three split option rows (2, 3 and 4) of the split-row unit list, the rows
 * the split-option-row predicate picks out. */
#define MENU_SPLIT_ROW_FIRST 2
#define MENU_SPLIT_ROW_LAST  4

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

/* The ov003 setup screen's options object, kept by the scene at +0x44 (class
 * data_ov003_02210764): the eight option counters, the child objects and sprites
 * that draw them, the sprite of the value being previewed and the link packet
 * the option values are shared through. */
typedef struct Ov003OptionsObject {
    void *vtable;             /* +0x00 class data_ov003_02210764 */
    u8 field04;               /* +0x04 */
    u8 field05;               /* +0x05 */
    u8 field06;               /* +0x06 */
    u8 pad07;
    OptionCounter options[8]; /* +0x08 the eight option rows */
    void *rows[8];            /* +0xC8 child object drawing each option */
    void *sprites[9];         /* +0xE8 sprite handles */
    void *preview;            /* +0x10C sprite of the unit being previewed */
    u32 packet[9];            /* +0x110 0x24-byte link packet of the option values */
} Ov003OptionsObject;

#endif
