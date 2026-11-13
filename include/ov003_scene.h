/* A polymorphic ov003 scene object: a vtable at +0, a second interface vtable
 * at +0x34, then the children, buffers and sprite-handle arrays it owns. */
#ifndef OV003_SCENE_H
#define OV003_SCENE_H

typedef struct Ov003Object {
    void *vtable;        /* +0x00 */
    u8  filler_04[0x30];
    void *iface;         /* +0x34 second vtable */
    u8  field38;         /* +0x38 */
    u8  field39;         /* +0x39 */
    u8  flags3A;         /* +0x3A u8 flags: low 6 bits a state, bit 6, bit 7 */
    u8  field3B;         /* +0x3B */
    void *cursor3C;      /* +0x3C block freed by the destructors */
    void *sprites40;     /* +0x40 block of 2 + 8 + 8 sprite handles */
    void *child44;       /* +0x44 child object */
    u8  filler_48[4];
    void *child4C;       /* +0x4C child object */
    void *child50;       /* +0x50 child object */
    void *child54;       /* +0x54 child object */
    void *buffer58;      /* +0x58 buffer */
    void *child5C;       /* +0x5C child object */
    void *child60;       /* +0x60 child object */
    void *buffer64;      /* +0x64 buffer */
    void *sprites68;     /* +0x68 array of 10 sprite handles */
    void *sprites6C;     /* +0x6C array of 2 sprite handles */
    void *sub70;         /* +0x70 sub-object with a resource handle at +0x14 */
} Ov003Object;

#endif
