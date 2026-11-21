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
#define FS_REQ_DIR_RESOLVED 0x20 /* 12-byte directory entry the walk has resolved so far */
#define FS_REQ_PATH      0x3C /* u8 * rest of the path to resolve */
#define FS_REQ_WANT_DIR  0x40 /* s32 nonzero when the path must name a directory */
#define FS_REQ_OUT       0x44 /* void * receives the resolved directory or file entry */

/* Fields of a path request (the command that writes the full "device:/dir/name"
 * path of a file or directory into a caller buffer). */
#define FS_REQ_PATH_FILE_ID   0x20 /* u32 file id whose path is wanted (FS_REQ_DIRECTORY clear) */
#define FS_REQ_PATH_DIRECTORY 0x24 /* u16 directory id whose path is wanted (FS_REQ_DIRECTORY set) */
#define FS_REQ_PATH_OUT       0x30 /* u8 * buffer the path is written into */
#define FS_REQ_PATH_CAPACITY  0x34 /* u32 bytes available at FS_REQ_PATH_OUT */
#define FS_REQ_PATH_LENGTH    0x38 /* u16 computed path length, 0 until resolved */
#define FS_REQ_PATH_DIR       0x3a /* u16 directory the file was found in */
#define FS_NO_ENTRY_ID        0x10000 /* no file/directory id */

/* The byte window of an open file a request reads from: the first and one-past-
 * the-last byte positions, set when the file is opened, and the current stream
 * position.  Until then +0x24/+0x28 hold the directory-command scratch fields
 * above. */
#define FS_REQ_RANGE_START 0x24 /* s32 file offset the window starts at */
#define FS_REQ_RANGE_END   0x28 /* s32 file offset one past the window */
#define FS_REQ_RANGE_POS   0x2C /* s32 current stream position in the window */

/* After OpenFileRequest, an open request holds the data range of the file it
 * opened: the two words give the file's size as END - START. */
#define FS_REQ_FILE_START 0x24 /* u32 offset of the file's first byte */
#define FS_REQ_FILE_END   0x28 /* u32 offset just past the file's last byte */

/* Scratch fields the directory-read command (3) keeps in the request (it shares
 * the +0x28 word with FS_REQ_FILE_END). */
#define FS_REQ_DIR_INDEX  0x26 /* u16 id the next short entry gets */
#define FS_REQ_DIR_OFFSET 0x28 /* u32 stream offset of the next entry */
#define FS_REQ_DIR_PARENT 0x2C /* u32 index of the current directory's parent in the FNT main table, 0 for the root */
#define FS_REQ_DIR_SKIP   0x34 /* s32 nonzero to skip the entry's name */

/* Scratch fields of the open-by-id command (6) and the open-range command (7) it
 * chains to: the data range the file's FAT record gives. */
#define FS_REQ_OPEN_START 0x30 /* u32 archive offset of the file's first byte */
#define FS_REQ_OPEN_END   0x34 /* u32 offset one past its last byte, or the file id for command 6 */
#define FS_REQ_OPEN_ID    0x38 /* u32 entry id of the opened file */

/* Request flags at FSFileRequest::flags. */
#define FS_REQ_ACTIVE    0x00000001 /* submitted and not yet finished by the worker */
#define FS_REQ_QUEUED    0x00000002 /* still queued, dropped by a cancel */
#define FS_REQ_COMPLETED 0x00000004 /* wake the caller waiting at +0x18 */
#define FS_REQ_NOTIFIED  0x00000040 /* the file callback has seen this request */
#define FS_REQ_DIRECTORY 0x00000020 /* the request names a directory rather than a file */

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
#define FS_FILE_OP_NONBLOCKING 0x00000100 /* a command is in flight for a request whose caller does not wait:
                                           * the async-completion callback finishes the request */
#define FS_FILE_OP_BLOCKING    0x00000200 /* a command is in flight for a request whose caller waits on
                                           * FS_FILE_OP_QUEUE: the async-completion callback wakes it */

/* The thread queue a blocking request sleeps on (FSFile +0x0C) until the
 * file's asynchronous operation completes. */
#define FS_FILE_OP_QUEUE       0x0C

/* Callback events and their FS_FILE_EVENTS bits. */
#define FS_EVENT_REQUEST           9
#define FS_EVENT_REQUEST_MASK 0x200
#define FS_EVENT_IDLE             10
#define FS_EVENT_IDLE_MASK    0x400

/* The header LoadFileHeader fills for one file of a game data archive: the file
 * entry index, the buffer its data is read into and the sizes of the data and
 * of the zeroed BSS part that follows it, then the range of initializer
 * callbacks CompleteFileLoad runs once the data is in place. */
typedef struct FSFileHeader {
    u32  index;              /* +0x00 file entry index in the archive */
    void *data;              /* +0x04 buffer the file data is read into */
    u32  dataSize;           /* +0x08 bytes of data */
    u32  bssSize;            /* +0x0C bytes of BSS zeroed after the data */
    void **initCallbacks;    /* +0x10 first initializer FinishFileLoad runs */
    void **initCallbacksEnd; /* +0x14 end of the initializer list */
    u32  archiveSize;        /* +0x18 size of the archive range the file lives in */
    u32  flags;              /* +0x1C top byte: 1 flush the data, 2 verify its HMAC */
    u32  archive;            /* +0x20 archive the file comes from */
    u32  fileOffset;         /* +0x24 offset of the data in the archive file */
    u32  fileSize;           /* +0x28 size of the data in the archive file */
} FSFileHeader;              /* 0x2C bytes */

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
    s32 id;            /* +0x00 id the archive is registered under (its packed name) */
    struct FSArchive *next; /* +0x04 next open archive, NULL at the end */
    struct FSArchive *prev; /* +0x08 previous open archive, NULL at the start */
    u8 pad0C[0x10];    /* +0x0C */
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

/* The archives the game has open, in the order they were opened
 * (gOpenArchives).  The first archive added also becomes the last one, and its
 * insertion clears the three bookkeeping fields after the links. */
typedef struct FSArchiveList {
    FSArchive *first; /* +0x00 first open archive, NULL when none is open */
    FSArchive *last;  /* +0x04 last open archive */
    u16 unk08;        /* +0x08 */
    u16 unk0A;        /* +0x0A */
    s32 unk0C;        /* +0x0C */
} FSArchiveList;

/* The card archive's device work area: the OS lock id the archive takes the
 * card ROM lock with, and the card device its transfers run on (-1 for the
 * default). */
typedef struct FSCardArchiveWork {
    s32 lockId; /* +0x00 OS_GetLockID() id passed to CARD_LockRom/CARD_UnlockRom */
    s32 device; /* +0x04 card device index for the transfer, -1 for the default */
} FSCardArchiveWork; /* 8 bytes */

/* FSArchive::state bits. */
#define FS_ARCHIVE_NAMED      1 /* registered under a name */
#define FS_ARCHIVE_LAYOUT     2 /* FAT/FNT layout set by ConfigureArchiveLayout */
#define FS_ARCHIVE_IN_MEMORY  4 /* index tables loaded into memory */

/* A byte position in an open file's stream. FileStreamRead reads from it and
 * advances the offset by the number of bytes read. */
typedef struct FSStreamPos {
    void *file;   /* +0x00 the FSFile to read from */
    s32   offset; /* +0x04 byte offset of the next read */
} FSStreamPos;

/* One 8-byte record of the FNT (file name table) main table: where a
 * directory's name subtable starts, the id of its first file entry and its
 * parent directory's index.  The directory commands walk the table by index. */
typedef struct FSDirectoryTableEntry {
    u32 nameOffset;  /* +0x00 offset of the directory's name subtable in the FNT */
    u16 firstFileId; /* +0x04 id of the directory's first file entry */
    u16 parentIndex; /* +0x06 parent directory's index in the main table, 0 for the root */
} FSDirectoryTableEntry; /* 8 bytes */

/* One 8-byte record of an archive's FAT: the byte offsets of the file's data in
 * the archive, first byte and one past the last. */
typedef struct FSFileRange {
    u32 start; /* +0x00 */
    u32 end;   /* +0x04 */
} FSFileRange; /* 8 bytes */

/* The 12 bytes the directory commands keep at FS_REQ_DIR_BLOCK: the archive the
 * current directory belongs to and, once its table record has been read, the
 * directory's index and the start of its name subtable. */
typedef struct FSDirectoryBlock {
    void *file;      /* +0x00 archive the directory belongs to */
    u16 index;       /* +0x04 directory's index in the FNT main table */
    u16 firstFileId; /* +0x06 id of the directory's first file entry */
    u32 nameOffset;  /* +0x08 offset of the directory's name subtable in the FNT */
} FSDirectoryBlock;  /* 12 bytes */

#endif
