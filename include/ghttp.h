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
        s32 lastSocketError;  /* +0x4C: saved errno of the last socket call */
    GHIBuffer buffer;      /* +0x50: request/response scratch buffer */
    u8   pad74[0x88];
    s32 completed;        /* +0xFC: nonzero once the request has finished */
    s32 bytesReceived;    /* +0x100: body bytes delivered so far */
    s32 contentLength;    /* +0x104: expected body length, 0 when unknown */
    u8   pad108[0x08];
    s32 chunked;          /* +0x110: body uses chunked transfer encoding */
    u8   chunkHeader[0x0C];/* +0x114: text of the current chunk-size line */
    s32 chunkHeaderLen;   /* +0x120: bytes in chunkHeader */
    s32 chunkBytesLeft;   /* +0x124: bytes left in the current chunk */
    s32 chunkState;       /* +0x128: GHI_CHUNK_* decoder state */
    s32 pad12C;
    s32 skipTransfer;     /* +0x130: discard the body instead of delivering it */
    s32 throttle;         /* +0x134: throttle the transfer with a small recv buffer */
    u8   pad138[0x04];
    void *postData;       /* +0x13C: GHIPost source whose body is being uploaded */
    void *postItems;      /* +0x140: working copy of the source's item list */
    s32  postIndex;       /* +0x144: item currently being written */
    s32  postOffset;      /* +0x148: body bytes written so far */
    s32  postLength;      /* +0x14C: total body length (Content-Length) */
    u8   pad150[0x0C];
    char *serverOverride; /* +0x15C: connect here instead of the URL host */
    u16  portOverride;    /* +0x160: port used with serverOverride */
} GHIConnection;

/* Offsets of the POST upload state inside GHIConnection, for code that still
 * addresses the connection as a byte buffer. */
#define GHI_RESULT        0x38  /* GHIConnection.result */
#define GHI_BUFFER_LEN    0x5c  /* GHIConnection.buffer.len */
#define GHI_BUFFER_POS    0x60  /* GHIConnection.buffer.pos */
#define GHI_COMPLETED     0xfc  /* GHIConnection.completed */
#define GHI_POST_DATA     0x13c /* GHIConnection.postData */
#define GHI_POST_ITEMS    0x140 /* GHIConnection.postItems */
#define GHI_POST_INDEX    0x144 /* GHIConnection.postIndex */
#define GHI_POST_OFFSET   0x148 /* GHIConnection.postOffset */
#define GHI_POST_LENGTH   0x14c /* GHIConnection.postLength */

/* States of the chunked-transfer decoder (GHIConnection.chunkState). */
enum {
    GHI_CHUNK_SIZE    = 0, /* reading the chunk-size line */
    GHI_CHUNK_DATA    = 1, /* reading the current chunk's data */
    GHI_CHUNK_TRAILER = 2, /* skipping the line after a chunk */
    GHI_CHUNK_DONE    = 3  /* last chunk seen; body complete */
};

/* Status of the game's high-level web request API (gWebTransaction).
 * status: 0 idle, 1 registered/ready, 2 put sent, 3 get sent, 4 sync sent,
 * 5 complete, 6 failed. */
typedef struct WebRequest {
    s32 status;   /* +0x00 */
    s32 sourceId; /* +0x04 id of the record the request is about */
} WebRequest;

/* Kind of a multipart/form-data part (GHIPostData.type), from ghttpPost.c. */
enum {
    GHIString = 0,      /* name=value string */
    GHIFile = 1,        /* file read from disk */
    GHIFileMemory = 2   /* file held in memory */
};

/* One part of a multipart/form-data request. */
typedef struct GHIPostData {
    s32 type;            /* +0x00 GHIString, GHIFile or GHIFileMemory */
    char *name;          /* +0x04 form field name */
    union {
        struct {
            char *value; /* +0x08 string sent as the value */
            s32 length;  /* +0x0C its length */
            s32 urlEncode; /* +0x10 append URL-encoded as a query parameter */
        } string;
        struct {
            void *file;  /* +0x08 open file handle */
            char *filename;    /* +0x0C filename shown in the part header */
            char *contentType; /* +0x10 MIME type */
        } diskFile;
        struct {
            void *data;  /* +0x08 in-memory contents */
            s32 length;  /* +0x0C their length */
            char *filename;    /* +0x10 filename shown in the part header */
            char *contentType; /* +0x14 MIME type */
        } memoryFile;
    } u;
} GHIPostData;

/* Progress of one part being posted (the "state" of the ghiPost*DoPosting helpers). */
typedef struct GHIPostState {
    GHIPostData *data; /* +0x00 part being posted */
    s32 pos;           /* +0x04 bytes of it sent, -1 before the part header is written */
} GHIPostState;

#endif
