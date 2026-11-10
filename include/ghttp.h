/* GameSpy ghttp's GHIBuffer (ghttpBuffer.c) as ported in main_02049xxx.
 * The 9-word layout is fixed by the original: connection, data, size, len,
 * pos, sizeIncrement, fixed, dontFree, encrypted. */
#ifndef GHTTP_H
#define GHTTP_H

typedef struct GHIBuffer {
    void *connection;   /* +0x00 owning connection */
    u8   *data;         /* +0x04 storage */
    s32  size;          /* +0x08 allocated size */
    s32  len;           /* +0x0C bytes used */
    s32  pos;           /* +0x10 read position */
    s32  sizeIncrement; /* +0x14 grow step */
    s32  fixed;         /* +0x18 cannot grow */
    s32  dontFree;      /* +0x1C storage is not owned */
    s32  encrypted;     /* +0x20 pass writes through the connection encryptor */
} GHIBuffer;

#endif
