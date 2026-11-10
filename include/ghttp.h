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

/* Socket address passed to the NitroSDK-style socket wrappers: length byte,
 * family byte, big-endian port, IPv4 address in network byte order. */
typedef struct GhiSocketAddress {
    u8  len;      /* +0x00 */
    u8  family;   /* +0x01: AF_INET = 2 */
    u16 port;     /* +0x02 */
    u32 addr;     /* +0x04 */
} GhiSocketAddress;

/* GameSpy ghttp's per-request connection state machine.  Only the fields the
 * game's matched code touches so far are named; the rest is padding. */
typedef struct GHIConnection {
    u8   pad00[0x10];
    s32  state;            /* +0x10: GHTTPState */
    u8   pad14[0x08];
    u32  addr;             /* +0x1C: resolved IPv4 address, host order */
    u16  port;             /* +0x20: port from the URL */
    u16  pad22;
    u8   pad24[0x14];
    s32  result;           /* +0x38: GHTTPResult of a failed request */
    u8   pad3C[0x0C];
    s32  socket;           /* +0x48: SOCKET, -1 until created */
    s32  lastSocketError;  /* +0x4C: saved errno of the last socket call */
    u8   pad50[0xAC];
    s32  completed;        /* +0xFC: nonzero once the request has finished */
    u8   pad100[0x34];
    s32  throttle;         /* +0x134: throttle the transfer with a small recv buffer */
    u8   pad138[0x24];
    char *serverOverride;  /* +0x15C: connect here instead of the URL host */
    u16  portOverride;     /* +0x160: port used with serverOverride */
} GHIConnection;

#endif
