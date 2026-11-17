/* UI nodes of ov000: the army info window and the small icon animations its
 * destructor frees. */
#ifndef OV000_UI_H
#define OV000_UI_H
#include "common.h"

/* A UI node's vtable: +0x00 destroys the node, +0x04 destroys and frees it.  The
 * node keeps it in its first word. */
typedef struct UiNodeVTable {
    void *destroy;     /* +0x00 */
    void *destroyFree; /* +0x04 */
} UiNodeVTable;

/* The army info window built by BuildArmyInfoWindow (ov000_0216B898): the player
 * whose turn it is plus the sub-nodes its destructor tears down. */
#define ARMY_INFO_PANEL 0x40 /* void *stat panel, destroyed through its own vtable */
#define ARMY_INFO_ICONS 0x44 /* void *[7] icon animations, four bytes apart */
#define ARMY_INFO_ICON_COUNT 7

/* Per-frame animation state of the window, set by its update method in
 * ov000_0216B898, which the window's draw code reads. */
#define ARMY_INFO_FRAME    0x34 /* u16 frame counter of the open animation */
#define ARMY_INFO_SHOWN    0x36 /* u8 nonzero while the window is on screen */
#define ARMY_INFO_DETAILED 0x3D /* u8 nonzero for the detailed layout */

/* The army/CO info window state (gArmyInfoState, 0x24 bytes, built by
 * func_ov000_0216e178): per listed player a record index (+0x00), a CO face id
 * (+0x04) and an army colour (+0x08), then the selection and face animation. */
#define ARMY_INFO_COUNT     0x0C /* u8 players listed in the window */
#define ARMY_INFO_SELECTED  0x0D /* u8 index of the selected player */
#define ARMY_INFO_FACE_SUB  0x0E /* u8 selected player's CO face id on the sub screen, 0 = none */
#define ARMY_INFO_FACE_MAIN 0x0F /* u8 selected player's CO face id drawn on the main screen */
#define ARMY_INFO_FACE_PAGE 0x11 /* u8 alternate face page (0/1), toggled per redraw */
#define ARMY_INFO_SLIDE     0x12 /* s16 slide-in offset, 0..12 */

/* One icon animation: its frame table and the two animation templates it was
 * built from. */
typedef struct ArmyInfoIcon {
    void *frames; /* +0x00 frame table, freed with the icon */
    void *animA;  /* +0x04 */
    void *animB;  /* +0x08 */
    s16   unk0C;  /* +0x0C */
    s8    unk0E;  /* +0x0E */
    s8    unk0F;  /* +0x0F */
} ArmyInfoIcon; /* 0x10 bytes */
#endif
