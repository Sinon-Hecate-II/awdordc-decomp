/* 21 functions from 0x02009EB0 to 0x0200AE9C (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
static inline u32 LowerChar(u32 c) { c-=0x41; if(c<=25) return c+0x61;return c+0x41; }
typedef struct { u32 a,b,c; } UnkA3Block;
typedef struct { UnkA3Block block; u32 kind, length; u8 name[128]; } PathEntry;
/* Post a message to the ARM7 over the IPC FIFO: `tag` picks the handler that
 * gets it, `payload` is its data word and `reply` marks a reply to a request.
 * Interrupts are off while the send register is written.  Returns 0 when the
 * message was posted, -1 when the FIFO reported an error (its send side is
 * cleared, the caller may retry) and -2 when the send FIFO is still full. */
s32 SendFifoMessage(u32 tag, u32 payload, u32 reply) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    FifoMessage message;
    s32 irqState;

    message.tag = tag;
    message.reply = reply;
    message.payload = payload;
    if (*(volatile u16 *)REG_IPC_FIFO_CR & IPC_FIFO_ERROR) {
        *(volatile u16 *)REG_IPC_FIFO_CR |= IPC_FIFO_CLEAR;
        return -1;
    }
    irqState = OS_DisableInterrupts();
    if (*(volatile u16 *)REG_IPC_FIFO_CR & IPC_FIFO_SEND_FULL) {
        OS_RestoreInterrupts(irqState);
        return -2;
    }
    *(volatile u32 *)REG_IPC_FIFO_SEND = *(u32 *)&message;
    OS_RestoreInterrupts(irqState);
    return 0;
}

/* IPC FIFO receive interrupt handler: drains the messages the ARM7 has sent.  A
 * FIFO error is acknowledged and the drain retried, an empty receive FIFO ends
 * the handler, and every message goes to the handler registered for its tag.  A
 * request no one handles is acknowledged by posting it back with the reply bit set. */
void FifoReceiveHandler(void) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    extern void (*gFifoMessageHandlers[])(u32, u32, u32);
    FifoMessage v;
    s32 result, key;
    u32 tag;
    void (*cb)(u32, u32, u32);
    for (;;) {
        if (*(volatile u16 *)REG_IPC_FIFO_CR & IPC_FIFO_ERROR) {
            *(volatile u16 *)REG_IPC_FIFO_CR |= IPC_FIFO_CLEAR;
            result = -3;
        } else {
            key = OS_DisableInterrupts();
            if (*(volatile u16 *)REG_IPC_FIFO_CR & IPC_FIFO_RECV_EMPTY) {
                OS_RestoreInterrupts(key);
                result = -4;
            } else {
                *(u32 *)&v = *(volatile u32 *)REG_IPC_FIFO_RECV;
                OS_RestoreInterrupts(key);
                result = 0;
            }
        }
        if (result == -4) return;
        if (result == -3) continue;
        tag = v.tag;
        if (!tag) continue;
        cb = gFifoMessageHandlers[tag];
        if (cb) cb(tag, v.payload, v.reply);
        else if (!v.reply) {
            v.reply = 1;
            if (*(volatile u16 *)REG_IPC_FIFO_CR & IPC_FIFO_ERROR) {
                *(volatile u16 *)REG_IPC_FIFO_CR |= IPC_FIFO_CLEAR;
                continue;
            }
            key = OS_DisableInterrupts();
            if (*(volatile u16 *)REG_IPC_FIFO_CR & IPC_FIFO_SEND_FULL) {
                OS_RestoreInterrupts(key);
                continue;
            }
            *(volatile u32 *)REG_IPC_FIFO_SEND = *(u32 *)&v;
            OS_RestoreInterrupts(key);
        }
    }
}

/* Finish a file request: unlink it from its file's pending FIFO, clear every
 * state bit it was given, store the command result and wake the caller waiting
 * on its thread queue.  Interrupts stay off across the whole update so the FIFO
 * and the caller's queue change atomically. */
void CompleteFileRequest(void *p, s32 result) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    s32 OS_WakeupThread(void *);
    s32 key;
    FSFileRequest *request = (FSFileRequest *)p;
    FSFileRequest *prev, *next;

    key = OS_DisableInterrupts();
    prev = request->prev;
    next = request->next;
    if (prev) prev->next = next;
    if (next) next->prev = prev;
    request->prev = 0;
    request->next = 0;
    request->flags &= ~FS_REQ_STATE_MASK;
    request->result = result;
    OS_WakeupThread((u8 *)request + FS_REQ_QUEUE);
    OS_RestoreInterrupts(key);
}

/* Run one file command of a request: when the file's callback is armed for the
 * command it runs first (reporting 8 falls back to the default handler), then the
 * default per-command handler runs; a command still in progress (6) makes a
 * caller that waits sleep on the file's operation queue, and the finished result
 * is either handed back to the request or delivered through CompleteFileRequest. */
s32 ExecuteFileCommand(void *request, s32 command) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    extern s32 (*gFileCommandHandlers[])(void *);
    void CompleteFileRequest(void *, s32);

    s32 result;
    void *file = M2C_FIELD(request, void **, FS_REQ_FILE);
    u32 eventMask = (u32)1 << command;
    s32 callerWaits = 1;
    s32 blocking;
    s32 waitsForResult;
    s32 zero = 0;
    s32 one = 1;

    if (!(M2C_FIELD(request, s32 *, FS_REQ_FLAGS) & FS_REQ_COMPLETED)) {
        callerWaits = 0;
    }
    if (callerWaits) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = M2C_FIELD(file, s32 *, FS_FILE_STATE) | FS_FILE_OP_BLOCKING;
    } else {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = M2C_FIELD(file, s32 *, FS_FILE_STATE) | FS_FILE_OP_NONBLOCKING;
    }
    if (M2C_FIELD(file, u32 *, FS_FILE_EVENTS) & eventMask) {
        s32 (*cb)(void *, s32) = M2C_FIELD(file, s32 (**)(void *, s32), FS_FILE_CALLBACK);
        result = cb(request, command);
        switch (result) {
        case 0:
        case 1:
        case 4:
            M2C_FIELD(request, s32 *, FS_REQ_RESULT) = result;
            break;
        case 8:
            M2C_FIELD(file, u32 *, FS_FILE_EVENTS) = M2C_FIELD(file, u32 *, FS_FILE_EVENTS) & ~eventMask;
            result = 7;
            break;
        }
    } else {
        result = 7;
    }
    if (result == 7) {
        result = gFileCommandHandlers[command](request);
    }
    if (result == 6) {
        waitsForResult = (M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) & FS_REQ_COMPLETED) ? 1 : 0;
        if (waitsForResult != 0) {
            command = OS_DisableInterrupts();
            blocking = (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_OP_BLOCKING) ? 1 : 0;
            if (blocking != 0) {
                do {
                    OS_SleepThread((u8 *)file + FS_FILE_OP_QUEUE);
                    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_OP_BLOCKING) {
                        blocking = one;
                    } else {
                        blocking = zero;
                    }
                } while (blocking != 0);
            }
            result = M2C_FIELD(request, s32 *, FS_REQ_RESULT);
            OS_RestoreInterrupts(command);
            goto done;
        } else {
            goto done;
        }
    }
    waitsForResult = (M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) & FS_REQ_COMPLETED) ? 1 : 0;
    if (waitsForResult == 0) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_OP_NONBLOCKING;
        CompleteFileRequest(request, result);
    } else {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_OP_BLOCKING;
        M2C_FIELD(request, s32 *, FS_REQ_RESULT) = result;
    }
done:
    return result;
}

/* Compare two fixed-length names case-insensitively: fold ASCII upper-case letters
 * to lower case, then return the difference of the first differing bytes, or 0 when
 * the names are equal. */
s32 CompareNamesNoCase(u8 *nameA, u8 *nameB, u32 length) {
    u32 i, x, y;
    for (i = 0; i < length; i++) {
        x = nameA[i] - 'A';
        y = nameB[i] - 'A';
        if (x <= 'Z' - 'A') x += 'a' - 'A';
        if (y <= 'Z' - 'A') y += 'a' - 'A';
        if (x != y) return x - y;
    }
    return 0;
}

/* Read length bytes through a stream position: arm the file's request event,
 * run its active read proc at the stream's current offset, and if the proc says
 * the read is asynchronous wait until the queued request has finished. The
 * read's result is returned and the position advances by length bytes. */
s32 FileStreamRead(void *stream, void *buffer, s32 length) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_SleepThread(void *);
    M2C_UNK OS_RestoreInterrupts(s32);
    void *file;
    s32 result;
    u32 pending;
    unsigned long waiting;
    s32 key;

    file = M2C_FIELD(stream, void **, 0);
    M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) | FS_EVENT_REQUEST_MASK);
    result = M2C_FIELD(file, s32 (**)(void *, void *, s32, s32), 0x50)(file, buffer, M2C_FIELD(stream, s32 *, 4), length);
    switch (result) {                               /* irregular */
    case 0:
    case 1:
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_EVENT_REQUEST_MASK);
        break;
    case 6:
        key = OS_DisableInterrupts();
        if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_EVENT_REQUEST_MASK) {
            pending = 1;
        } else {
            pending = 0;
        }
        if (pending != 0) {
            do {
                OS_SleepThread((u8 *)file + 0xC);
                if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_EVENT_REQUEST_MASK) {
                    waiting = 1;
                } else {
                    waiting = 0;
                }
            } while (waiting != 0);
        }
        OS_RestoreInterrupts(key);
        result = M2C_FIELD(M2C_FIELD(file, void **, FS_FILE_REQUESTS), s32 *, FS_REQ_RESULT);
        break;
    }
    M2C_FIELD(stream, s32 *, 4) = (s32) (M2C_FIELD(stream, s32 *, 4) + length);
    return result;
}

void StartDirectoryRead(void *arg0, s32 arg1) {
    M2C_UNK ExecuteFileCommand(void *, M2C_UNK);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) | 4);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = arg1;
    ExecuteFileCommand(arg0, 2);
}

void func_0200a380(void *p){
s32 a,b,c;void *q;
a=M2C_FIELD(p,s32 *,0x2c);b=M2C_FIELD(p,s32 *,0x38);
q=M2C_FIELD(p,void **,8);c=M2C_FIELD(p,s32 *,0x30);
M2C_FIELD(p,s32 *,0x2c)=a+b;
M2C_FIELD(q,void (**)(void *,s32,s32,s32),0x48)(q,c,a,b);
}

void func_0200a3ac(void *p){
s32 a,b,c;void *q;
a=M2C_FIELD(p,s32 *,0x2c);b=M2C_FIELD(p,s32 *,0x38);
q=M2C_FIELD(p,void **,8);c=M2C_FIELD(p,s32 *,0x30);
M2C_FIELD(p,s32 *,0x2c)=a+b;
M2C_FIELD(q,void (**)(void *,s32,s32,s32),0x4c)(q,c,a,b);
}

/* FS directory command (2): reads the FNT main-table record of the directory
 * named by the request's directory block, caches that block as the walk's
 * resolved directory and, while its name subtable is still unknown, records the
 * first file id and the subtable's offset.  The record's parent directory index
 * is kept for a later ".." step.  Returns the read's result, 0 on success. */
s32 ReadDirectoryRecord(void *request) {
    FSArchive *archive = M2C_FIELD(request, FSArchive **, 8);
    FSDirectoryBlock *block = (FSDirectoryBlock *)((u8 *)request + FS_REQ_DIR_BLOCK);
    FSDirectoryTableEntry record;
    FSStreamPos pos;
    s32 result;

    pos.file = archive;
    pos.offset = archive->fntPos + (block->index << 3);
    result = FileStreamRead(&pos, &record, sizeof(record));
    if (!result) {
        *(FSDirectoryBlock *)((u8 *)request + FS_REQ_DIR_RESOLVED) = *block;
        if (!block->firstFileId && !block->nameOffset) {
            M2C_FIELD(request, u16 *, FS_REQ_DIR_INDEX) = record.firstFileId;
            M2C_FIELD(request, u32 *, FS_REQ_DIR_OFFSET) = archive->fntPos + record.nameOffset;
        }
        M2C_FIELD(request, u32 *, FS_REQ_DIR_PARENT) = record.parentIndex & 0xfff;
    }
    return result;
}

/* Read the next directory entry from the request's stream into the entry at
 * request+0x30: a header byte packs the name length and a flag, then the name
 * (or a skip), then either a two-byte id or the next short entry index.
 * Nonzero means the directory is exhausted. */
s32 ReadDirectoryEntry(void *request){
PathEntry *entry=M2C_FIELD(request,PathEntry **,0x30);
FSStreamPos pos;u8 header;u16 extra;s32 r;
pos.file=M2C_FIELD(request,void **,8);pos.offset=M2C_FIELD(request,u32 *,0x28);
r=FileStreamRead(&pos,(M2C_UNK)&header,1);if(r)return r;
entry->length=header&127;
entry->kind=(header>>7)&1;
if(!entry->length)return 1;
if(!M2C_FIELD(request,u32 *,FS_REQ_DIR_SKIP)){
r=FileStreamRead(&pos,(M2C_UNK)entry->name,entry->length);if(r)return r;
entry->name[entry->length]=0;
}else pos.offset+=entry->length;
if(entry->kind){
r=FileStreamRead(&pos,(M2C_UNK)&extra,2);if(r)return r;
M2C_FIELD(entry,u32 *,0)=M2C_FIELD(request,u32 *,8);
M2C_FIELD(entry,u16 *,4)=extra&0xfff;
M2C_FIELD(entry,u16 *,6)=0;M2C_FIELD(entry,u32 *,8)=0;
}else{
M2C_FIELD(entry,u32 *,0)=M2C_FIELD(request,u32 *,8);
M2C_FIELD(entry,u32 *,4)=M2C_FIELD(request,u16 *,FS_REQ_DIR_INDEX);
M2C_FIELD(request,u16 *,FS_REQ_DIR_INDEX)+=1;
}
M2C_FIELD(request,u32 *,FS_REQ_DIR_OFFSET)=pos.offset;return r;
}

/* Resolves the path at request+0x3c one component at a time (handling "." and
 * "..") against the directory listing and stores the matching file or
 * directory entry at request+0x44; wantDirectory asks for a directory. */
s32 ResolvePathEntry(void *request) {
    s32 ExecuteFileCommand(void *, s32);
    void StartDirectoryRead(void *, s32);
    s32 CompareNamesNoCase(u8 *, u8 *, u32);
    u8 *path = M2C_FIELD(request, u8 **, 0x3c);
    s32 wantDirectory = M2C_FIELD(request, s32 *, 0x40);
    s32 isNameChar, firstChar, kind, nameLength;
    PathEntry entry;

    ExecuteFileCommand(request, 2);
    firstChar = *path;
    while (firstChar != 0) {
        nameLength = 0;
        {
            s32 one = 1, zero = 0;
            goto scan;
        next:
            nameLength++;
        scan:
            kind = path[nameLength];
            isNameChar = zero;
            if (kind != 0 && kind != 47 && kind != 92) isNameChar = one;
            if (isNameChar) goto next;
        }
        if (kind != 0 || wantDirectory != 0) kind = 1;
        if (nameLength == 0) return 1;
        if (firstChar == 46) {
            if (nameLength == 1) { path++; goto advance; }
            if ((nameLength == 2) & (path[1] == 46)) {
                if (M2C_FIELD(request, u16 *, 0x24) != 0)
                    StartDirectoryRead(request, M2C_FIELD(request, s32 *, 0x2c));
                path += 2; goto advance;
            }
        }
        if (nameLength > 127) return 1;
        M2C_FIELD(request, void **, 0x30) = &entry;
        M2C_FIELD(request, u32 *, 0x34) = 0;
        for (;;) {
            if (ExecuteFileCommand(request, 3) != 0) return 1;
            if (kind == entry.kind && nameLength == entry.length &&
                CompareNamesNoCase(path, entry.name, nameLength) == 0) break;
        }
        if (kind) {
            *(UnkA3Block *)((u8 *)request + 0x30) = entry.block;
            path += nameLength;
            ExecuteFileCommand(request, 2);
        } else {
            u32 *fileIdOut;
            if (wantDirectory) return 1;
            fileIdOut = *(u32 * volatile *)((u8 *)request + 0x44);
            {
                u32 b, a;
                a = *(volatile u32 *)&entry.block.a;
                b = *(volatile u32 *)&entry.block.b;
                *(volatile u32 *)&fileIdOut[0] = a;
                fileIdOut[1] = b;
            }
            return 0;
        }
    advance:
        path += (*path != 0);
        firstChar = *path;
    }
    if (!wantDirectory) return 1;
    *(UnkA3Block *)M2C_FIELD(request, void **, 0x44) =
        *(UnkA3Block *)((u8 *)request + 0x20);
    return 0;
}

extern u8 gPathSeparator[];
#pragma opt_propagation off
/* Nitro FS path command (5): writes the full "device:/dir/.../name" path of the
 * file id (or directory id, FS_REQ_DIRECTORY) the request names into the request's
 * output buffer.  It finds the directory holding the file, measures the path,
 * writes the archive's device name, ":/" and then the directory chain and file
 * name from the end of the buffer.  Returns 0 when the path was written (or no
 * buffer was given), 1 when the entry was not found or the buffer is too small. */
s32 BuildFilePath(FSFileRequest *request) {
    M2C_UNK InitFileRequest(M2C_UNK *);
    FSArchive *archive = request->file;
    PathEntry entry;
    FSFileRequest dir;
    u32 fileId, i, count, directory;
    u32 remaining, prefix, nameLength;
    u8 *out;
    u32 isDirectory;
    InitFileRequest((M2C_UNK *)&dir);
    dir.file = request->file;
    isDirectory = (request->flags & FS_REQ_DIRECTORY) ? 1 : 0;
    if (isDirectory != 0) {
        directory = M2C_FIELD(request, u16 *, FS_REQ_PATH_DIRECTORY);
        fileId = FS_NO_ENTRY_ID;
        goto foundDirectory;
    } else {
        fileId = M2C_FIELD(request, u32 *, FS_REQ_PATH_FILE_ID);
        if (M2C_FIELD(request, u16 *, FS_REQ_PATH_LENGTH)) {
            directory = M2C_FIELD(request, u16 *, FS_REQ_PATH_DIR);
            goto foundDirectory;
        } else {
            i = 0;
            count = i;
            directory = FS_NO_ENTRY_ID;
            do {
                StartDirectoryRead(&dir, i);
                if (i == 0) count = M2C_FIELD(&dir, u32 *, 0x2c);
                M2C_FIELD(&dir, PathEntry **, 0x30) = &entry;
                M2C_FIELD(&dir, u32 *, FS_REQ_DIR_SKIP) = 1;
                while (ExecuteFileCommand(&dir, 3) == 0) {
                    if (entry.kind == 0 && entry.block.b == fileId) {
                        directory = M2C_FIELD(&dir, u16 *, 0x24);
                        break;
                    }
                }
                if (directory != FS_NO_ENTRY_ID) goto foundDirectory;
            } while (++i < count);
        }
    }
foundDirectory:
    if (directory == FS_NO_ENTRY_ID) {
        M2C_FIELD(request, u16 *, FS_REQ_PATH_LENGTH) = 0;
        return 1;
    }
    if (!M2C_FIELD(request, u16 *, FS_REQ_PATH_LENGTH)) {
        u32 id, parent, pathLength;
        pathLength = 0;
        id = archive->id;
        if (id <= 0xff) pathLength += 1;
        else if (id <= 0xff00) pathLength += 2;
        else pathLength += 3;
        pathLength += 2;
        if (fileId != FS_NO_ENTRY_ID) pathLength += entry.length;
        parent = directory;
        if (parent != 0) {
            StartDirectoryRead(&dir, parent);
            do {
                StartDirectoryRead(&dir, M2C_FIELD(&dir, u32 *, 0x2c));
                M2C_FIELD(&dir, PathEntry **, 0x30) = &entry;
                M2C_FIELD(&dir, u32 *, FS_REQ_DIR_SKIP) = 1;
                while (ExecuteFileCommand(&dir, 3) == 0) {
                    if (entry.kind && M2C_FIELD(&entry, u16 *, 4) == parent) {
                        pathLength += entry.length + 1;
                        break;
                    }
                }
                parent = M2C_FIELD(&dir, u16 *, 0x24);
            } while (parent != 0);
        }
        M2C_FIELD(request, u16 *, FS_REQ_PATH_LENGTH) = pathLength + 1;
        M2C_FIELD(request, u16 *, FS_REQ_PATH_DIR) = directory;
    }
    out = M2C_FIELD(request, u8 **, FS_REQ_PATH_OUT);
    if (out == 0) return 0;
    remaining = M2C_FIELD(request, u16 *, FS_REQ_PATH_LENGTH);
    if (M2C_FIELD(request, u32 *, FS_REQ_PATH_CAPACITY) < remaining) return 1;
    prefix = 0;
    {
        u32 id = archive->id;
        if (id <= 0xff) nameLength = 1;
        else if (id <= 0xff00) nameLength = 2;
        else nameLength = 3;
    }
    MI_CpuCopy8((M2C_UNK)archive, (M2C_UNK)out, nameLength);
    MI_CpuCopy8((M2C_UNK)gPathSeparator, (M2C_UNK)(out + (prefix + nameLength)), 2);
    StartDirectoryRead(&dir, directory);
    if (fileId != FS_NO_ENTRY_ID) {
        M2C_FIELD(&dir, PathEntry **, 0x30) = &entry;
        M2C_FIELD(&dir, u32 *, FS_REQ_DIR_SKIP) = 0;
        while (ExecuteFileCommand(&dir, 3) == 0) {
            if (entry.kind == 0 && entry.block.b == fileId) break;
        }
        nameLength = entry.length + 1;
        MI_CpuCopy8((M2C_UNK)entry.name, (M2C_UNK)(out + remaining - nameLength), nameLength);
        remaining -= nameLength;
    } else {
        (out + remaining)[-1] = 0;
        remaining--;
    }
    if (directory != 0) {
        do {
            StartDirectoryRead(&dir, M2C_FIELD(&dir, u32 *, 0x2c));
            M2C_FIELD(&dir, PathEntry **, 0x30) = &entry;
            M2C_FIELD(&dir, u32 *, FS_REQ_DIR_SKIP) = 0;
            out[remaining - 1] = '/';
            remaining--;
            while (ExecuteFileCommand(&dir, 3) == 0) {
                if (entry.kind && M2C_FIELD(&entry, u16 *, 4) == directory) {
                    nameLength = entry.length;
                    MI_CpuCopy8((M2C_UNK)entry.name, (M2C_UNK)(out + remaining - nameLength), nameLength);
                    remaining -= nameLength;
                    break;
                }
            }
            directory = M2C_FIELD(&dir, u16 *, 0x24);
        } while (directory != 0);
    }
    return 0;
}
#pragma opt_propagation reset
/* File command 6: open the file whose id the request names by reading its FAT
 * record from the archive, store the file's data range and hand over to command
 * 7, which installs the range in the request.  Returns 1 when the id points past
 * the archive's FAT. */
s32 OpenFileById(void *request) {
    FSArchive *archive = M2C_FIELD(request, FSArchive **, FS_REQ_FILE);
    u32 id = M2C_FIELD(request, u32 *, FS_REQ_OPEN_END);
    u32 offset = id << 3;
    FSFileRange range;
    FSStreamPos pos;
    s32 result;

    if (offset >= (u32) archive->fatSize) return 1;
    pos.file = archive;
    pos.offset = archive->fatPos + offset;
    result = FileStreamRead(&pos, &range, sizeof(range));
    if (result) return result;
    M2C_FIELD(request, u32 *, FS_REQ_OPEN_START) = range.start;
    M2C_FIELD(request, u32 *, FS_REQ_OPEN_END) = range.end;
    M2C_FIELD(request, u32 *, FS_REQ_OPEN_ID) = id;
    return ExecuteFileCommand(request, 7);
}

s32 func_0200abac(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    return 0;
}

s32 func_0200abd4(void) {
    return 0;
}

#pragma opt_propagation off
/* Pack the first up-to-three characters of an archive name into a 32-bit archive
 * id, lowercasing ASCII letters; a NUL character ends the name early. */
u32 PackArchiveName(u8 *name, s32 length) {
    u32 id = 0;
    s32 i, shift;
    u32 ch;
    if (length <= 3) {
        i = 0;
        if (length > 0) {
            shift = 0;
            do {
                ch = name[i];
                if (!ch) break;
                ch = ch - 'A';
                if (ch <= 25) ch += 'a';
                else ch += 'A';
                id |= ch << shift;
                i++;
                shift += 8;
            } while (i < length);
        }
    }
    return id;
}
#pragma opt_propagation reset
s32 ReadArchiveImage(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    M2C_UNK MI_CpuCopy8(s32, M2C_UNK, M2C_UNK);
    MI_CpuCopy8(M2C_FIELD(arg0, s32 *, 0x28) + arg2, arg1, arg3);
    return 0;
}

s32 WriteArchiveImage(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    MI_CpuCopy8(arg1, M2C_FIELD(arg0, s32 *, 0x28) + arg2, arg3);
    return 0;
}

s32 ReadArchiveMemory(s32 a,s32 b,s32 c,s32 d){MI_CpuCopy8(c,b,d);return 0;}

#pragma opt_common_subs off
/* Picks the next pending request of a file after an operation finishes: drops
 * the queue when the file is being cancelled, otherwise arms the idle callback,
 * notifies the caller's callback and returns the request that has to run (or
 * wakes the request that is already waiting and returns NULL). */
M2C_UNK *GetNextFileRequest(void *file) {
    M2C_UNK OS_WakeupThread(void *);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    void CompleteFileRequest(void *, s32);
    M2C_UNK InitFileRequest(M2C_UNK *);
    s32 irq;
    s32 irq2;
    M2C_UNK *request;
    M2C_UNK *pending;
    M2C_UNK *next;
    s32 cancelling;
    s32 aborting;
    s32 busy;
    s32 notifyPending;
    s32 completed;
    s32 notifyPending2;
    s32 aborting2;
    s32 queued;
    s32 notifyNow;
    u8 idleRequest[0x48];

    irq = OS_DisableInterrupts();
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_CANCELLING) {
        cancelling = 1;
    } else {
        cancelling = 0;
    }
    if (cancelling != 0) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_CANCELLING);
        pending = M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS);
        if (pending != NULL) {
            do {
                next = M2C_FIELD(pending, M2C_UNK **, 4);
                if (M2C_FIELD(pending, s32 *, FS_REQ_FLAGS) & FS_REQ_QUEUED) {
                    queued = 1;
                } else {
                    queued = 0;
                }
                if (queued != 0) {
                    if (M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS) == pending) {
                        M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS) = next;
                    }
                    CompleteFileRequest(pending, 3);
                    if (next == NULL) {
                        next = M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS);
                    }
                }
                pending = next;
            } while (next != NULL);
        }
    }
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_ABORTING) {
        aborting = 1;
    } else {
        aborting = 0;
    }
    if (aborting == 0) {
        if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_BUSY) {
            busy = 1;
        } else {
            busy = 0;
        }
        if (busy == 0) {
            request = M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS);
            if (request != NULL) {
                if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_NOTIFY_PENDING) {
                    notifyPending = 1;
                } else {
                    notifyPending = 0;
                }
                if (notifyPending == 0) {
                    notifyNow = 1;
                } else {
                    notifyNow = 0;
                }
                if (notifyNow != 0) {
                    M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) | FS_FILE_NOTIFY_PENDING);
                }
                OS_RestoreInterrupts(irq);
                if ((notifyNow != 0) && (M2C_FIELD(file, s32 *, FS_FILE_EVENTS) & FS_EVENT_REQUEST_MASK)) {
                    M2C_FIELD(file, M2C_UNK (**)(M2C_UNK *, M2C_UNK), FS_FILE_CALLBACK)(request, FS_EVENT_REQUEST);
                }
                irq2 = OS_DisableInterrupts();
                M2C_FIELD(request, s32 *, FS_REQ_FLAGS) = (s32) (M2C_FIELD(request, s32 *, FS_REQ_FLAGS) | FS_REQ_NOTIFIED);
                if (*(volatile s32 *)((s8 *)request + FS_REQ_FLAGS) & FS_REQ_COMPLETED) {
                    completed = 1;
                } else {
                    completed = 0;
                }
                if (completed != 0) {
                    OS_WakeupThread((u8 *)request + FS_REQ_QUEUE);
                    OS_RestoreInterrupts(irq2);
                    return NULL;
                }
                OS_RestoreInterrupts(irq2);
                return request;
            }
        }
        goto block_41;
    }
block_41:
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_NOTIFY_PENDING) {
        notifyPending2 = 1;
    } else {
        notifyPending2 = 0;
    }
    if (notifyPending2 != 0) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_NOTIFY_PENDING);
        if (M2C_FIELD(file, s32 *, FS_FILE_EVENTS) & FS_EVENT_IDLE_MASK) {
            InitFileRequest(idleRequest);
            M2C_FIELD(idleRequest, void **, FS_REQ_FILE) = file;
            M2C_FIELD(file, M2C_UNK (**)(M2C_UNK *, M2C_UNK), FS_FILE_CALLBACK)(idleRequest, FS_EVENT_IDLE);
        }
    }
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_ABORTING) {
        aborting2 = 1;
    } else {
        aborting2 = 0;
    }
    if (aborting2 != 0) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) ((M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_ABORTING) | FS_FILE_BUSY);
        OS_WakeupThread(file + FS_FILE_WAIT_QUEUE);
    }
    OS_RestoreInterrupts(irq);
    return NULL;
}
#pragma opt_common_subs reset
