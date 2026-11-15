/* Layout of the NitroSDK filesystem objects used by the FS code in
 * main_02009EB0 and main_0200AE9C. A file keeps a FIFO of pending requests at
 * FS_FILE_REQUESTS; each request carries a command and its result, and the
 * file's callback is told when a request starts and when the queue drains. */
#ifndef FS_H
#define FS_H

typedef struct FSFileRequest FSFileRequest;
struct FSFileRequest {
    FSFileRequest *prev;   /* +0x00 */
    FSFileRequest *next;   /* +0x04 next request in the FIFO */
    void *file;            /* +0x08 file the request runs on */
    u32 flags;             /* +0x0C FS_REQ_* */
    s32 command;           /* +0x10 command id */
    s32 result;            /* +0x14 result of the last command */
    u8 queue[8];           /* +0x18 OSThreadQueue the caller waits on */
    u8 pad20[0x28];
};                         /* 0x48 bytes */

/* Request field offsets, for code that walks the FIFO through M2C_FIELD. */
#define FS_REQ_FILE    0x08 /* FSFile *the request runs on */
#define FS_REQ_FLAGS   0x0C /* u32 FS_REQ_* */
#define FS_REQ_COMMAND 0x10 /* s32 command id */
#define FS_REQ_RESULT  0x14 /* s32 result of the last command */
#define FS_REQ_QUEUE   0x18 /* OSThreadQueue the caller waits on */
#define FS_REQ_DIR_BLOCK 0x30 /* 12-byte directory entry the path resolves from */
#define FS_REQ_PATH      0x3C /* u8 * rest of the path to resolve */
#define FS_REQ_WANT_DIR  0x40 /* s32 nonzero when the path must name a directory */
#define FS_REQ_OUT       0x44 /* void * receives the resolved directory or file entry */

/* Scratch fields the directory-read command (3) keeps in the request. */
#define FS_REQ_DIR_INDEX  0x26 /* u16 index handed to the next short entry */
#define FS_REQ_DIR_OFFSET 0x28 /* u32 stream offset of the next entry */
#define FS_REQ_DIR_SKIP   0x34 /* s32 nonzero to skip the entry's name */

/* Request flags at FSFileRequest::flags. */
#define FS_REQ_QUEUED    0x00000002 /* still queued, dropped by a cancel */
#define FS_REQ_COMPLETED 0x00000004 /* wake the caller waiting at +0x18 */
#define FS_REQ_NOTIFIED  0x00000040 /* the file callback has seen this request */

/* The parts of the filesystem object (FSFile) the queue code touches. */
#define FS_FILE_WAIT_QUEUE 0x14 /* OSThreadQueue woken when the file drains */
#define FS_FILE_STATE      0x1C /* u32 state bits FS_FILE_STATE_* */
#define FS_FILE_REQUESTS   0x24 /* FSFileRequest *head of the pending FIFO */
#define FS_FILE_CALLBACK   0x54 /* void (*callback)(void *context, s32 event) */
#define FS_FILE_EVENTS     0x58 /* u32 events the callback is armed for */

/* File state bits at FS_FILE_STATE. */
#define FS_FILE_BUSY           0x00000008
#define FS_FILE_NOTIFY_PENDING 0x00000010 /* idle callback armed, not yet run */
#define FS_FILE_CANCELLING     0x00000020 /* drop the queued requests */
#define FS_FILE_ABORTING       0x00000040 /* finish up and wake the idle queue */

/* Callback events and their FS_FILE_EVENTS bits. */
#define FS_EVENT_REQUEST           9
#define FS_EVENT_REQUEST_MASK 0x200
#define FS_EVENT_IDLE             10
#define FS_EVENT_IDLE_MASK    0x400

/* A resource archive (the game's data pack).  The 0x30-byte file header names
 * three sections by file offset and byte size; LoadResourceArchive reads them
 * into a memory pool and records the loaded pointers at +0x84..+0x8C. */
typedef struct ResourceArchive {
    u8 pad00[0x10];
    s32 extraOffset;    /* +0x10 optional section: file offset */
    s32 extraSize;      /* +0x14 optional section: byte size */
    s32 objectOffset;   /* +0x18 object table section: file offset */
    s32 objectSize;     /* +0x1C object table section: byte size */
    s32 dataOffset;     /* +0x20 data section: file offset */
    s32 dataSize;       /* +0x24 data section: byte size */
    u8 pad28[0x0C];     /* +0x28 */
    u8 request[0x48];   /* +0x34 FSFileRequest used to read the sections */
    u8 pad7C[0x08];     /* +0x7C */
    void *dataBlock;    /* +0x84 loaded data section */
    void *extraBlock;   /* +0x88 loaded optional section */
    void *objectBlock;  /* +0x8C loaded object table section */
} ResourceArchive;

/* A file archive handle (the game's main data pack and the overlay archives).
 * The handle keeps the archive image in memory (+0x28) and the two index tables
 * the file lookups walk - the file allocation table (FAT) and the file name
 * table (FNT) - each as a byte position (+0x2C/+0x34) and byte size pair
 * (+0x30/+0x38). Loading the index moves both tables off the file into a memory
 * pool (+0x44, +0x2C/+0x34 become their addresses there) and switches the
 * handle's read callback (+0x50) to a plain memory copy. */
typedef struct FSArchive {
    u8 pad00[0x1C];
    u32 state;         /* +0x1C FS_ARCHIVE_* bits */
    u8 pad20[0x08];    /* +0x20 */
    void *image;       /* +0x28 archive image base in memory */
    s32 fatPos;        /* +0x2C FAT byte position (file offset, then pool) */
    s32 fatSize;       /* +0x30 FAT byte size */
    s32 fntPos;        /* +0x34 FNT byte position (file offset, then pool) */
    s32 fntSize;       /* +0x38 FNT byte size */
    s32 fatBase;       /* +0x3C FAT base position */
    s32 fntBase;       /* +0x40 FNT base position */
    void *pool;        /* +0x44 pool the index tables were loaded into */
    void *readProc;    /* +0x48 default read callback */
    void *writeProc;   /* +0x4C default write callback */
    void *proc;        /* +0x50 active read callback */
} FSArchive;

/* FSArchive::state bits. */
#define FS_ARCHIVE_NAMED      1 /* registered under a name */
#define FS_ARCHIVE_LAYOUT     2 /* FAT/FNT layout set by SetArchiveLayout */
#define FS_ARCHIVE_IN_MEMORY  4 /* index tables loaded into memory */

/* A byte position in an open file's stream. FileStreamRead reads from it and
 * advances the offset by the number of bytes read. */
typedef struct FSStreamPos {
    void *file;   /* +0x00 the FSFile to read from */
    s32   offset; /* +0x04 byte offset of the next read */
} FSStreamPos;

#endif
