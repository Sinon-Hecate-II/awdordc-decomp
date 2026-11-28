/* 35 functions from 0x0200AE9C to 0x0200BDA4 (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
/* The archives the game has open, in the order they were opened. */
extern FSArchiveList gArchiveList;
/* A 12-byte directory record (FSDirectoryBlock) as the path commands pass it. */
typedef struct { u32 words[3]; } Unk032Record;
typedef struct FileLink { struct FileLink *prev,*next; } FileLink;
static inline void UnlinkFileRequest(FileLink *a) {
FileLink *p=a->prev,*n=a->next;
if(p)p->next=n;if(n)n->prev=p;
}
static inline void MoveFileRequest(FileLink *a, FileLink *head) {
FileLink *n; FileLink *p; p=a->prev;n=a->next;
if(p)p->next=n;if(n)n->prev=p;
{ FileLink *next=head->next;while(next){head=next;next=next->next;} }
head->next=a;a->prev=head;a->next=0;
}
static inline void AppendFileRequest(FileLink *head,FileLink *a) {
FileLink *next=head->next;
while(next){head=next;next=next->next;}
head->next=a;a->prev=head;a->next=0;
}
/* The source of a file-range request: words[0] is the archive to read from and
 * words[1] the id of the file to open in it (the pair the path resolver and
 * BuildFileRange fill in). */
typedef struct { u32 words[2]; } Unk02BDFileRange;

static inline s32 TestRequestFlag(void *a,s32 mask) { return (M2C_FIELD(a,volatile s32 *,12)&mask)?1:0; }
static inline s32 TestFileFlag(void *a, s32 mask) {
 s32 result;
 if(M2C_FIELD(a,volatile s32 *,0x1c)&mask) result=1;
 else result=0;
 return result;
}

/* Run the queued file requests of `request`'s file one after another: mark each
 * request notified by the file callback, wake its waiter if it was already
 * completed, and run its command.  Stop when a command is still in progress
 * (result 6), otherwise continue with the file's next request. */
M2C_UNK ProcessFileRequests(FSFileRequest *request) {
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(s32);
    void OS_WakeupThread(void *);
    s32 ExecuteFileCommand(void *, s32);
    s32 GetNextFileRequest(s32);
    s32 file = M2C_FIELD(request, s32 *, FS_REQ_FILE), key;
    if (!request) return;
    do {
        key = OS_DisableInterrupts();
        M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) |= FS_REQ_NOTIFIED;
        if ((M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) & FS_REQ_COMPLETED) ? 1 : 0) {
            OS_WakeupThread((u8 *)request + FS_REQ_QUEUE);
            OS_RestoreInterrupts(key);
            return;
        }
        M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) |= 8;
        OS_RestoreInterrupts(key);
        if (ExecuteFileCommand(request, M2C_FIELD(request, s32 *, FS_REQ_COMMAND)) == 6) return;
        request = (FSFileRequest *)GetNextFileRequest(file);
    } while (request);
}

/* Run the request's command, complete the request with the result and, when its
 * file still has pending requests, process the next one.  Returns 1 when the
 * command succeeded (result 0), else 0. */
s32 FinishFileRequest(void *request) {
    M2C_UNK CompleteFileRequest(void *, s32);
    s32 ExecuteFileCommand(void *, s32);
    s32 GetNextFileRequest(s32);
    M2C_UNK ProcessFileRequests();
    CompleteFileRequest(request, ExecuteFileCommand(request, M2C_FIELD(request, s32 *, FS_REQ_COMMAND)));
    if (GetNextFileRequest(M2C_FIELD(request, s32 *, FS_REQ_FILE)) != 0) {
        ProcessFileRequests();
    }
    if (M2C_FIELD(request, s32 *, FS_REQ_RESULT) == 0) {
        return 1;
    }
    return 0;
}

/* Queue a request on its file for command; if the file is idle, start its worker
 * (running the request inline), otherwise a blocking request waits for the
 * worker to finish. Returns 1 while a blocking request continues. */
s32 SubmitFileRequest(void *req,s32 command) {
s32 OS_DisableInterrupts(void); M2C_UNK OS_RestoreInterrupts(s32);M2C_UNK CompleteFileRequest(void *,s32);void OS_SleepThread(void *);
register void *file; register s32 key; register void *request=req; register u32 cmdMask;
file=M2C_FIELD(req,void **,8);cmdMask=1<<command;
M2C_FIELD(req,s32 *,16)=command;M2C_FIELD(req,s32 *,20)=2;M2C_FIELD(req,volatile s32 *,12)|=1;
key=OS_DisableInterrupts();
if(M2C_FIELD(file,s32 *,28)&128){CompleteFileRequest(req,3);OS_RestoreInterrupts(key);return 0;}
if(cmdMask&0x1fc)M2C_FIELD(req,volatile s32 *,12)|=4;
MoveFileRequest(req,(FileLink *)((u8 *)file+32));
if(!TestFileFlag(file,8)&&!TestFileFlag(file,16)){
M2C_FIELD(file,s32 *,28)|=16;OS_RestoreInterrupts(key);
if(M2C_FIELD(file,s32 *,88)&512) M2C_FIELD(file,void (**)(void *,s32),84)(req,9);
{ s32 key2=OS_DisableInterrupts();M2C_FIELD(req,volatile s32 *,12)|=64;
if(!TestRequestFlag(req,4)){OS_RestoreInterrupts(key2);ProcessFileRequests(req);return 1;}
OS_RestoreInterrupts(key2);}
}else{
if(!TestRequestFlag(req,4)){OS_RestoreInterrupts(key);return 1;}
do{OS_SleepThread((u8 *)req+24);}while(!(M2C_FIELD(req,volatile s32 *,12)&64));
OS_RestoreInterrupts(key);
}
return FinishFileRequest(req);
}

/* Reset an archive handle: zero the whole 0x5C-byte handle and then clear the
 * four work words at +0x0C..+0x18 again. */
void InitArchive(FSArchive *archive) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    MI_CpuFill8((void *)archive, 0, 0x5C);
    archive->unk10 = 0;
    archive->unk0C = 0;
    archive->unk18 = 0;
    archive->unk14 = 0;
}

/* Find the open archive registered under the packed form of `name`/`length`,
 * returning it or NULL when no open archive has that name. */
s32 FindArchive(s32 name, s32 length) {
    s32 PackArchiveName(s32, s32);
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 id, key;
    FSArchive *archive;

    id = PackArchiveName(name, length);
    key = OS_DisableInterrupts();
    archive = gArchiveList.first;
    while (archive && archive->id != id)
        archive = archive->next;
    OS_RestoreInterrupts(key);
    return (s32)archive;
}

/* Add an archive to the open-archive list under its packed name, unless an
 * archive with that name is already open. Returns 1 if the archive was added. */
s32 RegisterArchiveName(FSArchive *archive, M2C_UNK name, M2C_UNK length) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 PackArchiveName(M2C_UNK, M2C_UNK);
    s32 FindArchive(M2C_UNK, M2C_UNK);
    s32 irq;
    s32 registered;
    FSArchive *next;
    FSArchive *last;

    registered = 0;
    irq = OS_DisableInterrupts();
    if (FindArchive(name, length) == 0) {
        last = gArchiveList.first;
        if (last == NULL) {
            gArchiveList.first = archive;
            gArchiveList.last = archive;
            gArchiveList.unk0C = 0;
            gArchiveList.unk0A = 0;
            gArchiveList.unk08 = 0;
        } else {
            next = last->next;
            if (next != NULL) {
                do {
                    last = next;
                    next = next->next;
                } while (next != NULL);
            }
            last->next = archive;
            archive->prev = last;
        }
        archive->id = PackArchiveName(name, length);
        registered = 1;
        archive->state = (s32) (archive->state | FS_ARCHIVE_NAMED);
    }
    OS_RestoreInterrupts(irq);
    return registered;
}

/* Release an archive's name registration: unlink it from gArchiveList, clear
 * its packed-name id and links, and drop its FS_ARCHIVE_NAMED bit. */
void ReleaseArchiveName(FSArchive *archive) {
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 key;
    FSArchive *link;

    if (!archive->id) return;
    key = OS_DisableInterrupts();
    link = archive->next;
    if (link) link->prev = archive->prev;
    link = archive->prev;
    if (link) link->next = archive->next;
    archive->id = 0;
    archive->prev = 0;
    archive->next = 0;
    archive->state &= ~FS_ARCHIVE_NAMED;
    if (gArchiveList.last == archive) {
        gArchiveList.last = gArchiveList.first;
        gArchiveList.unk0C = 0;
        gArchiveList.unk0A = 0;
        gArchiveList.unk08 = 0;
    }
    OS_RestoreInterrupts(key);
}

/* Give an archive its FAT/FNT layout: record the archive image and the byte
 * position and size of the file allocation table (FAT) and file name table
 * (FNT), install the callbacks that read and write the archive (defaulting to
 * the in-memory image callbacks when none is given) and mark the layout as set.
 * Always returns 1. */
s32 ConfigureArchiveLayout(FSArchive *archive, void *image, s32 fatPos, s32 fatSize, s32 fntPos, s32 fntSize, void *readProc, void *writeProc) {
    extern M2C_UNK ReadArchiveImage,WriteArchiveImage;
    void *read, *write;
    archive->image = image;
    archive->fatSize = fatSize;
    archive->fatPos = archive->fatBase = fatPos;
    archive->fntSize = fntSize;
    archive->fntPos = archive->fntBase = fntPos;
    read = readProc;
    if (!read) read = &ReadArchiveImage;
    archive->readProc = read;
    write = writeProc;
    if (!write) write = &WriteArchiveImage;
    archive->writeProc = write;
    archive->proc = archive->readProc;
    archive->pool = 0;
    archive->state |= FS_ARCHIVE_LAYOUT;
    return 1;
}

s32 CloseArchiveFile(void *a) {
 s32 OS_DisableInterrupts(void);
 s32 OS_RestoreInterrupts(s32);
 s32 BeginFileOperation(void *);
 M2C_UNK EndFileOperation(void *);
 s32 CompleteFileRequest(void *,s32);
 s32 irq;void *p; s32 flag;void *next; s32 r;
 irq=OS_DisableInterrupts();
 flag=TestFileFlag(a,2);
 if(flag!=0){
 r=BeginFileOperation(a);
 M2C_FIELD(a,s32 *,0x1c)|=128;
 p=M2C_FIELD(a,void **,0x24);
 while(p){next=M2C_FIELD(p,void **,4);CompleteFileRequest(p,3);p=next;}
 M2C_FIELD(a,void **,0x24)=0;
 if(r)EndFileOperation(a);
 M2C_FIELD(a,s32 *,0x28)=0;M2C_FIELD(a,s32 *,0x2c)=0;
 M2C_FIELD(a,s32 *,0x30)=0;M2C_FIELD(a,s32 *,0x34)=0;
 M2C_FIELD(a,s32 *,0x38)=0;M2C_FIELD(a,s32 *,0x40)=0;M2C_FIELD(a,s32 *,0x3c)=0;
 M2C_FIELD(a,s32 *,0x1c)&=~0xa2;
 }
 OS_RestoreInterrupts(irq);return 1;
}

/* Load an archive's FAT and FNT index tables from their positions in the file
 * into `memory`, 32-byte aligned, FAT first then FNT. `required` is the aligned
 * total both tables need; if it does not fit in `size` nothing is read and the
 * caller only learns the size. On success the archive's table positions become
 * those in the pool and its reads switch to the memory-backed read proc. */
u32 LoadArchiveIndex(FSArchive *archive,u32 memory,u32 size){
extern M2C_UNK ReadArchiveMemory;
void InitFileRequest(void *);
s32 OpenFileDirect(void *,s32,s32,s32,s32);
s32 FileRead(s32,s32,s32);
s32 CloseFileRequest(void *);
M2C_UNK MI_CpuFill8(void *,M2C_UNK,M2C_UNK);
FSFileRequest request;u32 required,p;
required=(archive->fatSize+archive->fntSize+63)&~31;
if(required<=size){
p=(memory+31)&~31;
InitFileRequest(&request);
if(OpenFileDirect(&request,(s32)archive,archive->fatPos,archive->fatPos+archive->fatSize,-1)){
if(FileRead((s32)&request,p,archive->fatSize)<0)MI_CpuFill8((void*)p,0,archive->fatSize);
CloseFileRequest(&request);
}
archive->fatPos=p;
p+=archive->fatSize;
if(OpenFileDirect(&request,(s32)archive,archive->fntPos,archive->fntPos+archive->fntSize,-1)){
if(FileRead((s32)&request,p,archive->fntSize)<0)MI_CpuFill8((void*)p,0,archive->fntSize);
CloseFileRequest(&request);
}
archive->fntPos=p;
archive->pool=(void *)memory;
archive->proc=&ReadArchiveMemory;
archive->state|=FS_ARCHIVE_IN_MEMORY;
}
return required;
}

/* Release an archive's in-memory FAT/FNT index tables: clear the in-memory
 * flag, hand the pool that held the tables back to the caller (and clear it),
 * and restore the table positions and read callback the archive had before
 * LoadArchiveIndex moved them into the pool. */
s32 UnloadArchiveIndex(FSArchive *archive) {
    s32 BeginFileOperation();
    s32 EndFileOperation(void *);
    s32 busy, flag, pool = 0;

    flag = TestFileFlag(archive, FS_ARCHIVE_LAYOUT);
    if (flag != 0) {
        busy = BeginFileOperation(archive);
        flag = TestFileFlag(archive, FS_ARCHIVE_IN_MEMORY);
        if (flag != 0) {
            archive->state &= ~FS_ARCHIVE_IN_MEMORY;
            pool = (s32)archive->pool;
            archive->pool = 0;
            archive->fatPos = archive->fatBase;
            archive->fntPos = archive->fntBase;
            archive->proc = archive->readProc;
        }
        if (busy) EndFileOperation(archive);
    }
    return pool;
}

/* Claim a file for an operation: report whether it was free and, when it was,
 * mark it busy - first waiting out an armed idle-notification callback, which
 * sets the busy bit itself (FS_FILE_ABORTING) once it has run. */
s32 BeginFileOperation(void *file) {
    void OS_SleepThread(void *);
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 notifyPending, state, irq = OS_DisableInterrupts();
    s32 wasFree = ((M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) & FS_FILE_BUSY) ? 1 : 0) == 0;
    if (wasFree) {
        notifyPending = (M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) & FS_FILE_NOTIFY_PENDING) ? 1 : 0;
        state = M2C_FIELD(file, volatile s32 *, FS_FILE_STATE);
        if (notifyPending) {
            M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) = state | FS_FILE_ABORTING;
            do {
                OS_SleepThread((u8 *)file + FS_FILE_WAIT_QUEUE);
            } while ((M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) & FS_FILE_ABORTING) ? 1 : 0);
        } else M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) = state | FS_FILE_BUSY;
    }
    OS_RestoreInterrupts(irq);
    return wasFree;
}

/* Finish a file operation on `file`: if it was busy, clear the busy bit, take the
 * next queued request and run it.  Returns 1 when the file was already free. */
s32 EndFileOperation(void *file) {
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 next = 0, key, wasFree;
    key = OS_DisableInterrupts();
    wasFree = ((M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_BUSY) ? 1 : 0) == 0;
    if (!wasFree) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) &= ~FS_FILE_BUSY;
        next = GetNextFileRequest((s32)file);
    }
    OS_RestoreInterrupts(key);
    if (next) ProcessFileRequests((void *)next);
    return wasFree;
}

/* Install `archive`'s command callback and the events it is armed for, keeping
 * the pair consistent: no events clears the callback, no callback clears the
 * events. */
void SetArchiveCallback(FSArchive *archive, void *callback, u32 events) {
    if (events == 0) {
        callback = 0;
    } else if (callback == 0) {
        events = 0;
    }
    archive->callback = callback;
    archive->events = events;
}

/* Completion callback of a file's asynchronous command (the card/ROM read task
 * runs it with `result`).  A non-blocking request is finished through
 * CompleteFileRequest and the file's next request is started; a blocking one
 * has the result stored and wakes the caller waiting on FS_FILE_OP_QUEUE. */
M2C_UNK FileOperationCompleted(M2C_UNK file, s32 result) {
    M2C_UNK CompleteFileRequest(void *, s32);
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(s32);
    void OS_WakeupThread(void *);
    s32 key, request;

    if ((M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) & FS_FILE_OP_NONBLOCKING) ? 1 : 0) {
        key = M2C_FIELD(file, volatile s32 *, FS_FILE_STATE);
        request = M2C_FIELD(file, s32 *, FS_FILE_REQUESTS);
        M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) = key & ~FS_FILE_OP_NONBLOCKING;
        CompleteFileRequest((void *)request, result);
        request = GetNextFileRequest(file);
        if (request) ProcessFileRequests((void *)request);
        return;
    }
    request = M2C_FIELD(file, s32 *, FS_FILE_REQUESTS);
    key = OS_DisableInterrupts();
    M2C_FIELD(request, s32 *, FS_REQ_RESULT) = result;
    M2C_FIELD(file, volatile s32 *, FS_FILE_STATE) &= ~FS_FILE_OP_BLOCKING;
    OS_WakeupThread((void *)(file + FS_FILE_OP_QUEUE));
    OS_RestoreInterrupts(key);
}

/* Mount the game's "rom" card archive the first time it is needed; every later
 * call does nothing.  `device` is the card device to open (-1 for the default). */
void InitCardArchiveOnce(s32 device) {
    void InitCardArchive(s32);
    extern s32 gCardArchiveInitialized;
    if (gCardArchiveInitialized) return;
    gCardArchiveInitialized = 1;
    InitCardArchive(device);
}

/* Clear a file request to its starting state: no FIFO links, file or flags, an
 * empty wait queue, and no command (FS_COMMAND_NONE) until one is submitted. */
void InitFileRequest(void *request) {
    M2C_FIELD(request, s32 *, 0) = 0;
    M2C_FIELD(request, s32 *, 4) = 0;
    M2C_FIELD(request, s32 *, FS_REQ_QUEUE + 4) = 0;
    M2C_FIELD(request, s32 *, FS_REQ_QUEUE) = 0;
    M2C_FIELD(request, s32 *, FS_REQ_FILE) = 0;
    M2C_FIELD(request, s32 *, FS_REQ_COMMAND) = FS_COMMAND_NONE;
    M2C_FIELD(request, s32 *, FS_REQ_FLAGS) = 0;
}

/* Submits a path-resolution request (file command 4): fills in the directory
 * record the path starts from (the current directory, or the device named
 * "name:"), stores the rest of the path and the caller's output slot and lets
 * the filesystem queue resolve it. */
s32 SubmitPathRequest(void *request,s32 pathArg,s32 out,s32 outDir) {
extern Unk032Record gFileCurrentDirectory;
s32 SubmitFileRequest(void *,s32);
u8 *path=(u8 *)pathArg;Unk032Record rec; s32 i,flag;void *file;
if(*path=='/'||*path=='\\'){
M2C_FIELD(&rec,u16 *,4)=0;
rec.words[0]=gFileCurrentDirectory.words[0];rec.words[2]=0;M2C_FIELD(&rec,u16 *,6)=0;path++;
}else{
rec=gFileCurrentDirectory;
for(i=0;i<=3;i++){
u8 ch=path[i];
if(ch==0||ch=='/'||ch=='\\')break;
if(ch==':'){
file=(void *)FindArchive((s32)path,i);if(!file)return 0;
flag=TestFileFlag(file,2);if(flag==0)return 0;
rec.words[0]=(u32)file;rec.words[2]=0;M2C_FIELD(&rec,u16 *,6)=0;M2C_FIELD(&rec,u16 *,4)=0;
path+=i+1;if(*path=='/'||*path=='\\')path++;break;
}
}
}
M2C_FIELD(request,u32 *,FS_REQ_FILE)=rec.words[0];M2C_FIELD(request,u8 **,FS_REQ_PATH)=path;
M2C_FIELD(request,Unk032Record *,FS_REQ_DIR_BLOCK)=rec;
if(outDir!=0){M2C_FIELD(request,s32 *,FS_REQ_WANT_DIR)=1;M2C_FIELD(request,s32 *,FS_REQ_OUT)=outDir;}
else{M2C_FIELD(request,s32 *,FS_REQ_WANT_DIR)=0;M2C_FIELD(request,s32 *,FS_REQ_OUT)=out;}
return SubmitFileRequest(request,4);
}

M2C_UNK func_0200b8e0(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d) {
    s32 WaitForFileRequest(void *);
    void *self = (void *)a;
    s32 old = M2C_FIELD(self, s32 *, 0x2c);
    s32 limit = M2C_FIELD(self, s32 *, 0x28) - old;
    s32 n = (s32)c;
    M2C_FIELD(self, M2C_UNK *, 0x30) = b;
    if (n > limit) n = limit;
    if (n < 0) n = 0;
    M2C_FIELD(self, M2C_UNK *, 0x34) = c;
    M2C_FIELD(self, s32 *, 0x38) = n;
    if (!d) M2C_FIELD(self, volatile s32 *, 0xc) |= 4;
    SubmitFileRequest(self, 0);
    if (!d) {
        if (WaitForFileRequest(self)) n = M2C_FIELD(self, s32 *, 0x2c) - old;
        else n = -1;
    }
    return n;
}

/* Resolve `path` to the archive and file-id pair `range` with a temporary
 * path-resolution request; returns 1 when the path was resolved. */
s32 ResolveFileRangeFromPath(Unk02BDFileRange *range, const char *path) {
    s32 SubmitPathRequest(void *, s32, s32, s32);
    FSFileRequest request;
    InitFileRequest(&request);
    return SubmitPathRequest(&request, (s32)path, (s32)range, 0) != 0;
}

/* Open the archive range [start, end) of file id `fileId` directly on `request`
   (open-range command): fill in the request's file and open fields, submit it,
   and on success mark the request as an open file rather than a directory. */
s32 OpenFileDirect(void *request, s32 archive, s32 start, s32 end, s32 fileId) {
    M2C_FIELD(request, s32 *, FS_REQ_FILE) = archive;
    M2C_FIELD(request, s32 *, FS_REQ_OPEN_ID) = fileId;
    M2C_FIELD(request, s32 *, FS_REQ_OPEN_START) = start;
    M2C_FIELD(request, s32 *, FS_REQ_OPEN_END) = end;
    if (SubmitFileRequest(request, FS_COMMAND_OPEN_RANGE) == 0) {
        return 0;
    }
    M2C_FIELD(request, s32 *, FS_REQ_FLAGS) = (s32) ((M2C_FIELD(request, s32 *, FS_REQ_FLAGS) | FS_REQ_OPEN) & ~FS_REQ_DIRECTORY);
    return 1;
}

/* Open the file `range` names (the archive it lives in and its id in that
 * archive's FAT) on request `request`: fill the request's file and open-by-id
 * fields, submit the open-by-id command and mark the request open.  Returns 0
 * when there is no archive or the command could not be started. */
s32 OpenFileRange(s32 request,Unk02BDFileRange range){if(!range.words[0])return 0;M2C_FIELD(request,u32 *,FS_REQ_FILE)=range.words[0];M2C_FIELD(request,u32 *,FS_REQ_OPEN_START)=range.words[0];M2C_FIELD(request,u32 *,FS_REQ_OPEN_END)=M2C_FIELD(&range,volatile u32 *,4);if(!SubmitFileRequest((void *)request,6))return 0;M2C_FIELD(request,s32 *,FS_REQ_FLAGS)=(M2C_FIELD(request,s32 *,FS_REQ_FLAGS)|16)&~FS_REQ_DIRECTORY;return 1;}

/* Opens the file named by `path` on `request`: resolve the path into the file's
 * archive and id, then open that file range on the request. */
s32 OpenFileRequest(s32 request,s32 path){
s32 OpenFileRange(s32,Unk02BDFileRange);
Unk02BDFileRange range;
if(ResolveFileRangeFromPath(&range,path)&&OpenFileRange(request,range))return 1;
return 0;
}

/* Close the file the request holds open: submit the close command, then clear the
 * request's file and command and drop its open/directory state.  Returns 1 when
 * the command was submitted, 0 otherwise. */
s32 CloseFileRequest(void *request) {
    s32 SubmitFileRequest(void *, M2C_UNK);
    if (SubmitFileRequest(request, FS_COMMAND_CLOSE) == 0) {
        return 0;
    }
    M2C_FIELD(request, s32 *, FS_REQ_FILE) = 0;
    M2C_FIELD(request, s32 *, FS_REQ_COMMAND) = FS_COMMAND_NONE;
    M2C_FIELD(request, s32 *, FS_REQ_FLAGS) = (s32) (M2C_FIELD(request, s32 *, FS_REQ_FLAGS) & ~(FS_REQ_OPEN | FS_REQ_DIRECTORY));
    return 1;
}

/* Wait for a submitted file request to finish: mark it completed if the worker
 * has not, wait for the worker to acknowledge, then run the request to
 * completion. Returns whether the request succeeded (result 0). */
s32 WaitForFileRequest(void *request) {
    void OS_SleepThread(void *);
    s32 FinishFileRequest(void *);
    s32 completed = 0;
    s32 key = OS_DisableInterrupts();
    if ((M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) & FS_REQ_ACTIVE) ? 1 : 0) {
        completed = !(M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) & (FS_REQ_COMPLETED | FS_REQ_NOTIFIED));
        if (completed) {
            M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) |= FS_REQ_COMPLETED;
            do {
                OS_SleepThread((u8 *)request + FS_REQ_QUEUE);
            } while (!(M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) & FS_REQ_NOTIFIED));
        } else {
            do {
                OS_SleepThread((u8 *)request + FS_REQ_QUEUE);
            } while ((M2C_FIELD(request, volatile s32 *, FS_REQ_FLAGS) & FS_REQ_ACTIVE) ? 1 : 0);
        }
    }
    OS_RestoreInterrupts(key);
    if (completed) return FinishFileRequest(request);
    return M2C_FIELD(request, s32 *, FS_REQ_RESULT) == 0;
}

/* Cancels a file request: while it is still active, mark it so the file's
 * request processor drops it, and mark the file it runs on as cancelling. */
void CancelFileRequest(FSFileRequest *request){
s32 key=OS_DisableInterrupts();
void *file;
if((M2C_FIELD(request,volatile s32 *,FS_REQ_FLAGS)&FS_REQ_ACTIVE)?1:0){
M2C_FIELD(request,volatile s32 *,FS_REQ_FLAGS)|=FS_REQ_QUEUED;
file=M2C_FIELD(request,void **,FS_REQ_FILE);
M2C_FIELD(file,s32 *,FS_FILE_STATE)|=FS_FILE_CANCELLING;
}
OS_RestoreInterrupts(key);
}

/* Read up to `size` bytes from the open file `request` into `buffer`, waiting
 * for the read to finish.  Returns the number of bytes read, or -1 on failure. */
s32 FileRead(s32 request, s32 buffer, s32 size) {
    M2C_UNK func_0200b8e0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return func_0200b8e0(request, buffer, size, 0);
}

/* Move the file request's read window to `offset`, relative to the window start
 * (origin 0), the current position (1) or the window end (2).  The new position is
 * clamped to the window and stored as the stream position; 0 for an unknown origin. */
s32 FileSeek(void *request, s32 offset, s32 origin) {
    s32 limit;

    switch (origin) {
    case 0: offset += M2C_FIELD(request, volatile s32 *, FS_REQ_RANGE_START); break;
    case 1: offset += M2C_FIELD(request, volatile s32 *, FS_REQ_RANGE_POS); break;
    case 2: offset += M2C_FIELD(request, volatile s32 *, FS_REQ_RANGE_END); break;
    default: return 0;
    }
    limit = M2C_FIELD(request, volatile s32 *, FS_REQ_RANGE_START);
    if (offset < limit) offset = limit;
    limit = M2C_FIELD(request, volatile s32 *, FS_REQ_RANGE_END);
    if (offset > limit) offset = limit;
    M2C_FIELD(request, s32 *, FS_REQ_RANGE_POS) = offset;
    return 1;
}

/* Resolve `path` as a directory and make it the filesystem's current directory:
 * true when the path resolved to a directory, false otherwise. */
s32 SetFileDirectory(s32 path) {
    extern Unk032Record gFileCurrentDirectory;
    u8 request[0x48];
    Unk032Record dir;

    InitFileRequest(request);
    if (!SubmitPathRequest(request, path, 0, (s32) &dir)) return 0;
    gFileCurrentDirectory = dir;
    return 1;
}

/* Completion callback of an asynchronous card archive read on `request`: report
 * the read as failed (result 5) when the system is shutting down, or as
 * successful (result 0) otherwise, to the file's operation completion. */
void CardArchiveReadDone(M2C_UNK request) {
    M2C_UNK FileOperationCompleted(M2C_UNK, M2C_UNK);
    s32 System_IsShuttingDown();
    M2C_UNK result;

    if (System_IsShuttingDown() != 0) {
        result = 5;
    } else {
        result = 0;
    }
    FileOperationCompleted(request, result);
}

/* The card archive's read procedure: start an asynchronous card transfer of
 * `length` bytes at `offset` into `buffer` for the request `file`, and report the
 * read as still in progress (6) so the caller waits for its completion callback. */
s32 ReadCardArchiveBlock(void *file,void *buffer,s32 offset,s32 length){void StartCardArchiveRead(s32,s32,s32,s32,s32,void *,s32);extern FSCardArchiveWork gCardArchiveWork;StartCardArchiveRead(gCardArchiveWork.device,offset,buffer,length,(s32)CardArchiveReadDone,file,1);return 6;}

s32 func_0200bd20(void) {
    return 1;
}

/* Command callback of the card archive, installed for its request and idle
 * events: locks the card ROM while a transfer request is in flight, unlocks it
 * when the archive goes idle, and reports its own event 1 as handled (0/4).  Any
 * other command returns 8, letting the generic file command handler take it. */
s32 CardArchiveCommand(void *request, s32 command) {
    void CARD_LockRom(u16);
    void CARD_UnlockRom(u16);
    extern FSCardArchiveWork gCardArchiveWork;
    switch (command) {
    case FS_EVENT_REQUEST:
        CARD_LockRom((u16)gCardArchiveWork.lockId);
        return 0;
    case FS_EVENT_IDLE:
        CARD_UnlockRom((u16)gCardArchiveWork.lockId);
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}

s32 func_0200bd94(void) {
    return 1;
}

s32 func_0200bd9c(void) {
    return 4;
}

