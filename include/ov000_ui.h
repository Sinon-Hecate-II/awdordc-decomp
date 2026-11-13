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
