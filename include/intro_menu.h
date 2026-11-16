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

#define INTRO_MENU_TEXTURE_STRIDE 0x200
#define INTRO_MENU_INITIAL_FRAME 5

/* Position fields of the animated sprite object owned by each entry. */
#define ANIMATED_SPRITE_X 0x34
#define ANIMATED_SPRITE_Y 0x38
#define ANIMATED_SPRITE_Z 0x3C

#endif
