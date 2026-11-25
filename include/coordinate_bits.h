#ifndef COORDINATE_BITS_H
#define COORDINATE_BITS_H
/* The size bits of a 3D sprite actor's +0x40 word: bits 0..8 are the width and
 * bits 9..17 the height (the values Sync3DSpriteToTarget copies into the frame
 * actor's rectangle). */
typedef struct { unsigned int width:9; unsigned int height:9; unsigned int rest:14; } SpriteActorSizeBits;
/* Move a 3D sprite actor to (x, y) and give it the size width x height. */
static inline void SetSpriteActorRect(void *p,s16 x,s16 y,s32 width,s32 height) {
 M2C_FIELD(p,s16*,0x34)=x; M2C_FIELD(p,s16*,0x36)=y;
 M2C_FIELD(p,SpriteActorSizeBits*,0x40).width=width; M2C_FIELD(p,SpriteActorSizeBits*,0x40).height=height;
}
#endif
