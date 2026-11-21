#ifndef INTRO_MENU_H
#define INTRO_MENU_H
#include "common.h"

/* Entry object built by the overlay 011 intro menu. */
typedef struct MenuEntry011 {
    u8 unknown00[0x34];
    u8 count;          /* +0x34 number of menu entries */
    u8 index;          /* +0x35 entry index and palette slot */
    u8 slideSpeed;     /* +0x36 slide-frame increment per update */
    u8 unknown37;
    s16 posX;          /* +0x38 */
    s16 posY;          /* +0x3A */
    s16 slideFromX;    /* +0x3C */
    s16 slideFromY;    /* +0x3E */
    s16 slideToX;      /* +0x40 */
    s16 slideToY;      /* +0x42 */
    s32 age;           /* +0x44 updates since creation */
    s32 slideTimer;    /* +0x48 current interpolation frame */
    void *sprite;      /* +0x4C animated sprite object */
    s32 labelId;       /* +0x50 localized text id */
    const char *name;  /* +0x54 base name of the .tex/.ctx files */
    s16 textWidth;     /* +0x58 rendered label width */
} MenuEntry011;

/* One step of the intro-menu script gIntroMenuTable: type INTRO_MENU_STEP_LABEL
   shows labelId on the menu object and goes on, type INTRO_MENU_STEP_ENTRY adds
   the menu entry called `name` with label entryLabelId, type 0 ends the script. */
enum {
    INTRO_MENU_STEP_END   = 0,
    INTRO_MENU_STEP_LABEL = 1,
    INTRO_MENU_STEP_ENTRY = 2
};

typedef struct IntroMenuStep {
    s32 type;          /* +0x00 INTRO_MENU_STEP_* */
    s32 labelId;       /* +0x04 label the menu shows for this step */
    s32 entryLabelId;  /* +0x08 label of this step's entry, when it has one */
    const char *name;  /* +0x0C base name of the entry's .tex/.ctx files */
} IntroMenuStep; /* 0x10 bytes */

/* Intro-menu object: a 3D sprite (engine class data_ov011_02228a78) that walks
   the gIntroMenuTable script, keeps up to three entry sprites and draws the
   selected entry's label.  Vtable words: destroy, destroy-and-free, no-op. */
typedef struct IntroMenu011 {
    M2C_UNK *vtable;           /* +0x00 */
    u8 unknown04[0x30];        /* +0x04 3D sprite state */
    u8 flags;                  /* +0x34 INTRO_MENU_* flag and phase bits */
    u8 entryCount;             /* +0x35 low nibble: number of entry sprites */
    u8 slideSpeed;             /* +0x36 slide-frame increment per update */
    u8 fadeTimer;              /* +0x37 */
    u8 appearTimer;            /* +0x38 */
    u8 unknown39;              /* +0x39 */
    s16 timer;                 /* +0x3A frames the menu has been shown */
    u8 unknown3C[4];           /* +0x3C */
    void *entries[3];          /* +0x40 the entry sprites */
    IntroMenuStep *step;       /* +0x4C cursor into gIntroMenuTable */
    s32 labelId;               /* +0x50 label currently shown */
} IntroMenu011;

/* Menu object flags at IntroMenu011.flags. */
#define INTRO_MENU_FLAG_ACTIVE 0x02 /* set while the menu is shown */
#define INTRO_MENU_PHASE_MASK  0xF0 /* bits 4-7: phase of the current step */
#define INTRO_MENU_COUNT_MASK  0x0F /* low nibble of entryCount */

#define INTRO_MENU_TEXTURE_STRIDE 0x200
#define INTRO_MENU_INITIAL_FRAME 5
#define INTRO_MENU_ENTRY_TOUCH_RADIUS 18
#define INTRO_MENU_ENTRY_FAST_SLIDE 2

/* Position fields of the animated sprite object owned by each entry. */
#define ANIMATED_SPRITE_X 0x34
#define ANIMATED_SPRITE_Y 0x38
#define ANIMATED_SPRITE_Z 0x3C

#endif
