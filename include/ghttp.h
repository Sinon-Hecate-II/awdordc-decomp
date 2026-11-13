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
    s32  inUse;            /* +0x00: nonzero while this slot holds a request */
    s32  request;          /* +0x04: index of this connection in gGhiConnectionList */
    s32  id;               /* +0x08: unique id handed out when the slot was taken */
    s32  pad0C;
    s32  state;            /* +0x10: GHTTPState */
    char *url;             /* +0x14: URL the caller asked for */
    char *host;            /* +0x18: host name from that URL */
    u32  addr;             /* +0x1C: resolved IPv4 address, host order */
    u16  port;             /* +0x20: port from the URL */
    u16  pad22;
    char *path;            /* +0x24: request path sent on the request line */
    char *headers;         /* +0x28: extra headers supplied by the caller */
    u8   pad2C[0x0C];
    s32  result;           /* +0x38: GHTTPResult of a failed request */
    u8   pad3C[0x0C];
    s32  socket;           /* +0x48: SOCKET, -1 until created */
        s32 lastSocketError;  /* +0x4C: saved errno of the last socket call */
    GHIBuffer buffer;         /* +0x50: request line/header buffer */
    GHIBuffer readBuffer;     /* +0x74: body bytes read from the socket */
    GHIBuffer decryptBuffer;  /* +0x98: body bytes the encryptor works on */
    GHIBuffer bodyBuffer;     /* +0xBC: caller body buffer, or growable when none */
    u8   padE0[0x04];
    s32  httpMajor;       /* +0xE4: major HTTP version from the status line */
    s32  httpMinor;       /* +0xE8: minor HTTP version from the status line */
    s32  statusCode;      /* +0xEC: HTTP status code */
    s32  statusLinePos;   /* +0xF0: status-line offset the parse stopped at */
    s32  padF4;           /* +0xF4 */
    s32  statusLineLength;/* +0xF8: bytes of the status line including its CR */
    s32 completed;        /* +0xFC: nonzero once the request has finished */
    s32 bytesReceived;    /* +0x100: body bytes delivered so far */
    s32 contentLength;    /* +0x104: expected body length, 0 when unknown */
    char *redirectURL;    /* +0x108: URL to fetch after a redirect */
    s32 pad10C;
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
    u8   pad150[0x08];
    s32  timeout;         /* +0x158: transfer timeout in milliseconds */
    char *serverOverride; /* +0x15C: connect here instead of the URL host */
    u16  portOverride;    /* +0x160: port used with serverOverride */
    u16  pad162;
    u8   encryptorState[0x08]; /* +0x164: opaque state passed to the encryptor callbacks */
    void *encryptor;      /* +0x16C: non-NULL while an encryptor is installed */
    s32  encryptorFlag;   /* +0x170 */
    s32  (*encryptorProcess)(void *connection, void *state); /* +0x174 */
    void (*encryptorCleanup)(void *connection, void *state); /* +0x178 */
    u8   pad17C[0x08];
} GHIConnection;

/* The global table of connection slots; the original kept its four members as
 * separate globals (ghiNumConnections, ghiConnections, ...) laid out in order. */
typedef struct GHIConnectionList {
    s32 numConnections;          /* +0x00: slots in use */
    GHIConnection **connections; /* +0x04: slot array */
    s32 nextId;                  /* +0x08: next connection id */
    s32 length;                  /* +0x0C: number of slots allocated */
} GHIConnectionList;

/* Offsets of the POST upload state inside GHIConnection, for code that still
 * addresses the connection as a byte buffer. */
#define GHI_RESULT        0x38  /* GHIConnection.result */
#define GHI_URL           0x14  /* GHIConnection.url */
#define GHI_HOST          0x18  /* GHIConnection.host */
#define GHI_PORT          0x20  /* GHIConnection.port */
#define GHI_PATH          0x24  /* GHIConnection.path */
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
    void *file;        /* +0x08 open file handle for a GHIFile part */
    s32 length;        /* +0x0C total bytes this part contributes */
} GHIPostState;

/* The POST source a connection uploads: its part list plus the two posting
 * options that are copied into the connection when the upload is prepared. */
typedef struct GHIPost {
    s32 items;   /* +0x00 Vector of GHIPostData* parts */
    s32 unk04;   /* +0x04 copied to GHIConnection.unk150 */
    s32 unk08;   /* +0x08 copied to GHIConnection.unk154 */
    s32 hasFiles;/* +0x0C nonzero: multipart/form-data, else a query string */
} GHIPost;

/* Fixed byte counts of a multipart/form-data body, measured once from the
 * boundary length.  The per-part values cover the part header and its CRLFs. */
typedef struct GHIPostLengths {
    s32 endLength;        /* +0x00 bytes of the closing boundary line */
    s32 stringPartLength; /* +0x04 fixed bytes around one string part */
    s32 boundaryLength;   /* +0x08 strlen of the bare boundary; 0 until computed */
    s32 filePartLength;   /* +0x0C fixed bytes around one file part */
} GHIPostLengths;

/* Extra bytes each kind of multipart body piece adds to the bare boundary:
 * a string part, a file part, and the closing "--boundary--" line. */
#define GHI_STRING_PART_OVERHEAD 47
#define GHI_FILE_PART_OVERHEAD   76
#define GHI_END_OVERHEAD          4

/* One in-flight high-level web request, the node HttpRequestStart (main_02044E04) puts in
 * gHttpRequestList. The caller's callbacks and data occupy the first four words; the body
 * buffer, the ghttp result and the list link follow. */
typedef struct WebRequestNode {
    s32 userData;                                    /* +0x00 value passed back to the callbacks */
    void (*onComplete)(s32, s32, s32, s32);          /* +0x04 (received, total, result, userData) */
    void (*onProgress)(s32, s32, s32, s32, s32, s32);/* +0x08 ghttp progress callback */
    s32 reuseConnection;                             /* +0x0c nonzero to keep the connection afterwards */
    void *buffer;                                    /* +0x10 body buffer, 0 when the caller supplied none */
    s32 result;                                      /* +0x14 ghttp result */
    struct WebRequestNode *next;                     /* +0x18 next request in the list */
} WebRequestNode;    /* 0x1c bytes */

#define HTTP_REQUEST_NODE_SIZE 0x1c

#endif
