/* Selection/unit panels shared by the ov003 menu code. Offsets are the ones the
 * panel object's code actually uses; most of the struct stays unknown. */
#ifndef PANEL_H
#define PANEL_H

typedef struct PanelRowState {
    s8 filler_0[4];
    s8 row;              /* +0x04 row the cursor sits on (clamped against hi/lo) */
    s8 filler_5[3];
    s8 hi;               /* +0x08 highest row */
    s8 filler_9[3];
    s8 lo;               /* +0x0C lowest row */
    s8 filler_d[3];
    u8 wrap;             /* +0x10 nonzero: rows wrap around */
} PanelRowState;

typedef struct PanelItem {
    u8 filler_0[0xC];
    s16 value;           /* +0x0C */
    s8 filler_e[6];
    s16 col;             /* +0x14 column the cursor sits in */
} PanelItem;

typedef struct PanelSprite {
    void *vtable;        /* +0x00 */
    u8 filler_4[0x3C];
    u32 color;           /* +0x40 packed BGR colour */
    u8 filler_44[0x15];
    u8 colorStep;        /* +0x59 fade step */
    s8 timer;            /* +0x5A >=0 while fading, then latched */
    u8 filler_5b[0x16];
} PanelSprite;

typedef struct Panel {
    void *vtable;        /* +0x00 */
    u8 filler_4[0x30];
    u8 stateFlag;        /* +0x34 */
    u8 filler_35[3];
    u8 mode;             /* +0x38 */
    u8 filler_39[2];
    u8 modeBits;         /* +0x3B current panel mode (bits 0-2) */
    u8 cellId;           /* +0x3C selected cell id (modes without a grid) */
    u8 filler_3d;
    u8 modeChangeFlag;   /* +0x3E bits0-2: pending mode, bit6: refresh */
    void *items;         /* +0x40 */
    u8 filler_44[8];     /* +0x44 .. +0x4B two 5-slot 0xffff lock tables */
    u8 *categoryCells;   /* +0x48 panel grid: 12 cells x 13 category columns */
    void *cursor;        /* +0x4C PanelItem */
    void *rowState;      /* +0x5C PanelRowState */
    u8 filler_60[8];
    void *sprite;        /* +0x68 PanelSprite */
    void *spriteList;    /* +0x6C */
} Panel;

#endif
