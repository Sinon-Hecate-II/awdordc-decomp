/* Per-unit-kind sprite descriptor returned by the unit-kind lookup.  The record
 * is picked from the low seven bits of a unit object's kind byte (object+0x58). */
#ifndef UNIT_SPRITE_H
#define UNIT_SPRITE_H

typedef struct UnitSpriteDef {
    u8 width;    /* +0x00 sprite width, 0 = keep the object's own tile x */
    u8 height;   /* +0x01 sprite height, 0 = keep the object's own tile y */
    u8 pad[2];
    s32 gfx;     /* +0x04 graphics/frame data pointer stored at object+0x44 */
    u32 flags;   /* +0x08 bit 4: read the other screen's key state */
} UnitSpriteDef; /* 12 bytes */

#endif
