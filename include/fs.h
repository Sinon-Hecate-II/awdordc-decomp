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

#endif
