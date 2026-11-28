/* 24 functions from 0x02015AA0 to 0x02016934 (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
typedef struct RangePair { u32 address; u32 size; } RangePair;
typedef struct MemoryDescriptor {u32 dest;u32 source;u32 size;u32 flags;} MemoryDescriptor;
typedef struct PacketBits { u8 low:2; u8 high:6; } PacketBits;
typedef struct PacketSource165 { u8 pad[0x358]; u8 field358,pad359; u16 field35a,field35c; } PacketSource165;

/* Builds a MemoryDescriptor describing a resource chunk: validates that src lies in a valid memory range, then either describes it in place (case 0) or copies it into the pool (case 1); case 2 is a fixed loader region. */
void Mb_DescribeChunk(void *srcInfo, s32 *kind, MemoryDescriptor *out, u32 *pool) {
    s32 SystemHalt(void);
    s32 bad, copy;
    s32 start;
    u32 size, end;
    switch (*kind) {
    case 0:
        start = M2C_FIELD(srcInfo, u32 *, 0x28);
        if ((u32)start >= 0x2000000 && (u32)start < 0x22c0000) {
            size = M2C_FIELD(srcInfo, u32 *, 0x2c);
            if (start + size <= 0x22c0000) {
                M2C_FIELD(out, u32 *, 8) = size;
                start = M2C_FIELD(srcInfo, u32 *, 0x28);
                M2C_FIELD(out, u32 *, 4) = start;
                M2C_FIELD(out, u32 *, 0) = start;
                M2C_FIELD(out, u32 *, 12) &= ~1;
                return;
            }
        }
        SystemHalt();
        return;
    case 1:
        start = M2C_FIELD(srcInfo, u32 *, 0x38);
        size = M2C_FIELD(srcInfo, u32 *, 0x3c);
        bad = 0;
        copy = 0;
        end = start + size;
        if ((u32)start >= 0x2000000 && (u32)start < 0x23fe800) {
            if (end > 0x2300000) {
                if (end < 0x23fe800 && size <= 0x40000) copy = 1;
                else bad = 1;
            }
        } else if ((u32)start >= 0x37f8000 && (u32)start < 0x380f000) {
            if (end <= 0x380f000) copy = 1;
            else bad = 1;
        } else bad = 1;
        if (bad == 1) SystemHalt();
        M2C_FIELD(out, u32 *, 8) = M2C_FIELD(srcInfo, u32 *, 0x3c);
        M2C_FIELD(out, u32 *, 4) = M2C_FIELD(srcInfo, u32 *, 0x38);
        if (copy == 0) M2C_FIELD(out, u32 *, 0) = M2C_FIELD(out, u32 *, 4);
        else {
            M2C_FIELD(out, u32 *, 0) = *pool;
            *pool += M2C_FIELD(out, u32 *, 8);
        }
        M2C_FIELD(out, u32 *, 12) = (M2C_FIELD(out, u32 *, 12) & ~1) | 1;
        return;
    case 2:
        start = 0x27ffe00;
        size = 0x160;
        out->size = size;
        out->source = start;
        out->dest = start;
        M2C_FIELD(out, u32 *, 12) &= ~1;
        return;
    }
}

/* Build a multiboot program's chunk index: three u32 byte offsets followed by
 * three u16 cumulative block counts (the last doubling as the total at +0x12),
 * derived from the program descriptor's three 16-byte chunk entries.  Returns 0
 * if the descriptor is null or a chunk's source range is invalid. */
s32 Mb_BuildChunkIndex(void *chunkIndex,void *program) {
extern void *gMbWork;
u32 U32DivideRem(u32,u32);
s32 Mb_ValidateChunkRange(u32,u32,u32);
void *chunks;u16 *blockOffsets=chunkIndex+12;u32 byteOffset=0;u8 i;
if(!program)return 0;
for(i=0;i<3;i++){((u32 *)chunkIndex)[i]=byteOffset;byteOffset+=M2C_FIELD(program+i*16,u32 *,0x14);}
blockOffsets[0]=0;chunks=program+12;
for(i=0;i<3;i++){void *chunk=chunks+i*16;u32 blockSize=M2C_FIELD(gMbWork,u32 *,0x1318);u32 size=M2C_FIELD(chunk,u32 *,8);u16 end=blockOffsets[i]+(u16)U32DivideRem(size+blockSize-1,blockSize);
if(!Mb_ValidateChunkRange(i,M2C_FIELD(chunk,u32 *,4),size))return 0;
if(i<2)blockOffsets[i+1]=end;else M2C_FIELD(chunkIndex,u16 *,0x12)=end;
}return 1;
}

/* Fill the transfer descriptor for multiboot download `block`: find the chunk the
 * block falls in, then give its destination address, the bytes left from there
 * (at most one block) and its offset in the download image.  Returns 0 when the
 * block index is past the end of the chunk index. */
s32 Mb_GetChunkTransfer(MbChunkTransfer *xfer,void *chunkIndex,u32 block,void *chunks) {
 extern void *gMbWork;
 s8 i;u32 offset;void *entry;
 if(block>=M2C_FIELD(chunkIndex,u16 *,0x12))return 0;
 i=2;
loop:
 if(block>=((u16 *)(chunkIndex+0xC))[i])goto found;
 i--;
 if(i>=0)goto loop;
found:
 if(i<0)return 0;
 offset=block-((u16 *)(chunkIndex+0xC))[i];
 offset=offset*M2C_FIELD(gMbWork,u32 *,MB_BLOCK_SIZE);
 entry=chunks+0xC+i*16;
 xfer->size=M2C_FIELD(entry,u32 *,8)-offset;
 if(xfer->size>M2C_FIELD(gMbWork,u32 *,MB_BLOCK_SIZE))xfer->size=M2C_FIELD(gMbWork,u32 *,MB_BLOCK_SIZE);
 xfer->source=offset+M2C_FIELD(chunkIndex+i*4,u32 *,0);
 xfer->dest=offset+M2C_FIELD(entry,u32 *,0);
 xfer->chunk=i;return 1;
}

/* Whether a download chunk of `size` bytes at `addr` fits the memory window its
   kind allows: a kind-2 chunk only the fixed header window, a kind-0 chunk only
   the first main RAM window, a kind-1 chunk the rest of main RAM or all of it. */
s32 Mb_ValidateChunkWindow(s32 chunk,u32 addr,u32 size) {
 extern const u32 sMbChunkKinds[];
 switch(sMbChunkKinds[chunk]){
 case 2:if(addr>=MB_WINDOW_HEADER_START && addr+size<=MB_WINDOW_HEADER_END)return 1;break;
 case 0:if(addr>=MB_WINDOW_RAM_START && addr+size<=MB_WINDOW_RAM_LOW_END)return 1;break;
 case 1:if(addr>=MB_WINDOW_RAM_LOW_END && addr+size<=MB_WINDOW_RAM_END)return 1;
 if(addr>=MB_WINDOW_RAM_START && addr+size<=MB_WINDOW_RAM_END)return 1;break;
 default:return 0;
 }return 0;
}

/* Validate a multiboot download chunk of `size` bytes at `addr`: sMbChunkKinds
 * gives the chunk's memory kind and the range must fit that kind's address
 * window (kinds 0 and 2 have fixed windows; kind 1 may sit in main RAM, crossing
 * 0x02300000 only for a small block, or in the 0x037F8000 region).  Returns 1
 * when the range is valid. */
s32 Mb_ValidateChunkRange(u32 chunk, u32 addr, u32 size) {
    extern const u32 sMbChunkKinds[];
    u32 end;
    switch (sMbChunkKinds[chunk]) {
    case 0:
    case 2:
        return Mb_ValidateChunkWindow(chunk, addr, size);
    case 1:
        if (addr >= 0x02000000 && addr < 0x023FE800) {
            end = addr + size;
            if (addr < 0x02300000 && end > 0x02300000) return 0;
            if (end <= 0x02300000) return 1;
            if (end < 0x023FE800 && size <= 0x40000) return 1;
            return 0;
        }
        if (addr >= 0x037F8000 && addr < 0x0380F000) {
            return addr + size <= 0x0380F000 ? 1 : 0;
        }
        break;
    default:
        return 0;
    }
    return 0;
}

void SendMatchPacket(s32 packetLength, M2C_UNK playerMask, M2C_UNK packetBuffer) {
    M2C_UNK DC_FlushRange(M2C_UNK, s32);
    M2C_UNK DC_Sync();
    M2C_UNK Mb_SendMatchPacket(M2C_UNK, s32, M2C_UNK);

    /* Flush the packet data from the CPU cache before sending it to the multiboot link. */
    DC_FlushRange(packetBuffer, (packetLength + 0x1F) & ~0x1F);
    DC_Sync();
    Mb_SendMatchPacket(packetBuffer, packetLength, playerMask);
}

/* 16-bit one's-complement checksum (RFC 1071) over `bytes` bytes of native-order
 * 16-bit words: sum the words, fold the carries twice and return the complement.
 * Used for the download-play packet's checksum field. */
u16 Mb_Checksum16(u16 *words, s32 bytes) {
    u32 sum = 0;
    s32 n = bytes >> 1;
    u32 folded;
    if (n > 0) do { u16 v = *words++; n--; sum += v; } while (n > 0);
    folded = (sum >> 16) + (u16)sum;
    return (folded + (folded >> 16)) ^ 0xFFFF;
}

/* Initialize an entry's 0x4C0-byte work buffer from a source descriptor: zero it, load two optional resources, and copy fixed fields. */
void func_02015f94(void *dest, void *src, s32 extra) {
    M2C_UNK FillU16(M2C_UNK, void *, M2C_UNK);
    M2C_UNK CopyU16(s32, void *, u16);
    M2C_UNK MI_CpuFill32(M2C_UNK, void *, M2C_UNK);
    s32 LoadEntryResource(s32, void *, M2C_UNK);

    s32 hasSecond;
    s32 hasFirst;

    FillU16(0, dest, 0x4C0);
    M2C_FIELD(dest, s8 *, 0x4B2) = 0;
    if (LoadEntryResource(M2C_FIELD(src, s32 *, 0xC), dest, 1) == 0) {
        hasFirst = 1;
    } else {
        hasFirst = 0;
    }
    if (LoadEntryResource(M2C_FIELD(src, s32 *, 0x10), dest, 0) == 0) {
        hasSecond = 1;
    } else {
        hasSecond = 0;
    }
    if ((hasFirst | hasSecond) != 0) {
        M2C_FIELD(dest, s8 *, 0x4B2) = 1;
        MI_CpuFill32(0, dest, 0x220);
    }
    M2C_FIELD(dest, s32 *, 0x4B8) = (s32) M2C_FIELD(src, s32 *, 0x14);
    if (extra != 0) {
        CopyU16(extra, dest + 0x220, 0x16U);
    }
    M2C_FIELD(dest, u8 *, 0x236) = (u8) M2C_FIELD(src, u8 *, 0x18);
    CopyU16(M2C_FIELD(src, s32 *, 4), dest + 0x238, (u16) (Mb_Utf16StringLength(M2C_FIELD(src, s32 *, 4)) * 2));
    CopyU16(M2C_FIELD(src, s32 *, 8), dest + 0x298, 0xC0U);
    M2C_FIELD(dest, s8 *, 0x358) = 1;
    M2C_FIELD(dest, s16 *, 0x35A) = 1;
    M2C_FIELD(dest, s16 *, 0x4B0) = 1;
}

/* Read one of an entry's two fixed-size resource files into its work buffer: the
 * large resource is 0x200 bytes at the buffer's +0x20, the small one 0x20 bytes at
 * its start.  Returns 1 once the file was read, 0 when there is no path, the file
 * cannot be opened or its size is not the expected one. */
s32 LoadEntryResource(s32 path,void *buffer,s32 large) {
void InitFileRequest(void *);s32 OpenFileRequest(void *,s32);
void CloseFileRequest(void *);void FileRead(void *,void *,s32);
u32 req[18];s32 size=large?0x200:0x20;
if(large)buffer+=0x20;
if(!path)return 0;
InitFileRequest(req);
if(!OpenFileRequest(req,path))return 0;
if(size!=M2C_FIELD(req,u32 *,FS_REQ_FILE_END)-M2C_FIELD(req,u32 *,FS_REQ_FILE_START)) {CloseFileRequest(req);return 0;}
FileRead(req,buffer,size);CloseFileRequest(req);return 1;
}

/* Load the roster a download file is sent with: copy the 15 players' info blocks
 * into the file record, set the player count and the mask of players to send it
 * to (bit 0 is the sender), and bump the file's step counter. */
void DownloadFileSetRoster(void *fileInfo, void *playerInfo, u32 pendingMask, u16 readyMask) {
    s32 i;
    u8 count = 1;
    CopyU16(playerInfo, (u8 *)fileInfo + DL_FILE_PLAYER_INFO, DL_FILE_PLAYER_SLOTS * MB_PLAYER_INFO_SIZE);
    for (i = 0; i < DL_FILE_PLAYER_SLOTS; i++)
        if (pendingMask & (2 << i)) count++;
    M2C_FIELD(fileInfo, u8 *, DL_FILE_PLAYER_COUNT) = count;
    M2C_FIELD(fileInfo, u16 *, DL_FILE_PLAYER_MASK) = pendingMask | 1;
    M2C_FIELD(fileInfo, u16 *, DL_FILE_READY_MASK) = readyMask;
    M2C_FIELD(fileInfo, u8 *, DL_FILE_STEP)++;
}

#pragma dont_inline on
/* Length in code units of the UTF-16 string at `text`: walk it until the
 * terminating 0 unit (the terminator itself is not counted). */
s32 Mb_Utf16StringLength(u16 *text) {
    s32 length = 0;
    u16 c;

    c = *text;
    text++;
    if (c) do {
        c = *text;
        text++;
        length++;
    } while (c);
    return length;
}
#pragma dont_inline reset

/* Append a download file to the tail of the DS Download Play send queue. */
void DownloadQueueFile(void *file) {
    extern M2C_UNK gDownloadSendState;
    void *queued = M2C_FIELD(&gDownloadSendState, void **, DL_QUEUE);
    void *next;

    if (!queued) M2C_FIELD(&gDownloadSendState, void **, DL_QUEUE) = file;
    else {
        while ((next = M2C_FIELD(queued, void **, DL_FILE_NEXT)) != 0) queued = next;
        M2C_FIELD(queued, void **, DL_FILE_NEXT) = file;
    }
    M2C_FIELD(file, void **, DL_FILE_NEXT) = 0;
}

/* Reset the DS Download Play sender: drop the queued and current downloads,
 * restart the send state machine at its first step, clear the progress callback
 * and the packet progress of the file that was being sent. */
void DownloadResetSender(void) {
void DownloadResetProgress(void);
extern M2C_UNK gDownloadSendState;
M2C_FIELD(&gDownloadSendState,s32 *,DL_QUEUE)=0;
M2C_FIELD(&gDownloadSendState,s32 *,DL_CURRENT)=0;
M2C_FIELD(&gDownloadSendState,u8 *,DL_STATE)=DL_STATE_START;
M2C_FIELD(&gDownloadSendState,s32 *,DL_CALLBACK)=0;
DownloadResetProgress();
}

/* Clear the progress of the file being downloaded, so the file started next sends
 * its chunk packets from the beginning: per-file progress, file index, chunk
 * packet index and count, and the packet sequence number all go back to zero. */
void DownloadResetProgress(void) {
    extern M2C_UNK gDownloadSendState;
    M2C_FIELD(&gDownloadSendState, u8 *, DL_PROGRESS) = 0;
    M2C_FIELD(&gDownloadSendState, u8 *, DL_FILE_INDEX) = 0;
    M2C_FIELD(&gDownloadSendState, u8 *, DL_CHUNK_INDEX) = 0;
    M2C_FIELD(&gDownloadSendState, u8 *, DL_CHUNK_COUNT) = 0;
    M2C_FIELD(&gDownloadSendState, u8 *, DL_SEQUENCE) = 0;
}

/* One step of the DS Download Play sender's state machine: start the next queued
 * file, submit its 0x62-byte chunk packets, then its roster/unit packets; it
 * returns once nothing can be sent or a packet has been handed to WFC. */
void DownloadSendStep(s32 sendCode, s32 sequence, s32 flags) {
    extern M2C_UNK gDownloadSendState;
    s32 DownloadStartNextFile(void);
    void DownloadBeginPacket(void);
    void DownloadSendChunkPacket(s32, s32, s32);
    void DownloadBeginRoster(void);
    void DownloadSendRosterPacket(s32, s32, s32);
    for (;;) switch (M2C_FIELD(&gDownloadSendState, u8 *, DL_STATE)) {
    case DL_STATE_IDLE:
    case DL_STATE_START:
        if (DownloadStartNextFile() == 0) return;
        break;
    case DL_STATE_BEGIN_PACKET:
        DownloadBeginPacket();
        break;
    case DL_STATE_SEND_CHUNK:
        DownloadSendChunkPacket(sendCode, sequence, flags);
        return;
    case DL_STATE_FILE_DONE:
        DownloadBeginRoster();
        break;
    case DL_STATE_SEND_ROSTER:
        DownloadSendRosterPacket(sendCode, sequence, flags);
        return;
    case DL_STATE_WAIT:
    default:
        break;
    }
}

/* Start the next queued download file (or send the idle packet when the queue is
 * empty): advance to the following file, reset its packet progress and move the
 * send state machine into the sending step. */
s32 DownloadStartNextFile(void) {
 extern M2C_UNK gDownloadSendState;extern M2C_UNK gDownloadPacket;
 s32 GetDownloadSendCode(void);s32 Mb_GetDownloadSequence(void);
 void WFC_SubmitDownloadData(s32,void *,s32,s32,s32,s32);
 void DownloadResetProgress(void);
 void *file;
 if(M2C_FIELD(&gDownloadSendState,void **,DL_QUEUE)==0){
 s32 sendCode=GetDownloadSendCode();
 WFC_SubmitDownloadData(0,&gDownloadPacket,0x70,sendCode,Mb_GetDownloadSequence(),8);return 0;
 }
 file=M2C_FIELD(&gDownloadSendState,void **,DL_CURRENT);
 if(file!=0 && M2C_FIELD(file,void **,DL_FILE_NEXT)!=0)file=M2C_FIELD(file,void **,DL_FILE_NEXT);
 else file=M2C_FIELD(&gDownloadSendState,void * volatile *,DL_QUEUE);
 M2C_FIELD(&gDownloadSendState,void **,DL_CURRENT)=file;
 DownloadResetProgress();
 M2C_FIELD(&gDownloadSendState,u8 *,DL_FILE_INDEX)=M2C_FIELD(M2C_FIELD(&gDownloadSendState,void **,DL_CURRENT),u8 *,DL_FILE_STEP);
 M2C_FIELD(&gDownloadSendState,u8 *,DL_STATE)=2;
 return 1;
}

/* Chooses the next batch of chunk packets for the file being downloaded: a file
 * without loaded resources sends its header from the record's start (nine
 * packets), one with resources sends the resource region (four packets); then the
 * sender advances to the chunk-sending step. */
void DownloadBeginPacket(void) {
 extern M2C_UNK gDownloadSendState;
 void *file;
 if(M2C_FIELD(&gDownloadSendState,u8 *,DL_STATE)!=DL_STATE_BEGIN_PACKET)return;
 file=M2C_FIELD(&gDownloadSendState,void **,DL_CURRENT);
 if(M2C_FIELD(file,u8 *,DL_FILE_HAS_RESOURCES)==0){
 M2C_FIELD(&gDownloadSendState,u8 *,DL_CHUNK_COUNT)=9;
 M2C_FIELD(&gDownloadSendState,void **,DL_CHUNK_SOURCE)=file;
 }else{
 M2C_FIELD(&gDownloadSendState,u8 *,DL_CHUNK_COUNT)=4;
 M2C_FIELD(&gDownloadSendState,void **,DL_CHUNK_SOURCE)=file+DL_FILE_RESOURCES;
 }
 M2C_FIELD(&gDownloadSendState,u8 *,DL_STATE)=DL_STATE_SEND_CHUNK;
}

#pragma opt_propagation off
void DownloadSendChunkPacket(s32 a,s32 b,s32 c) {
extern M2C_UNK gDownloadSendState;
extern M2C_UNK data_021311ee;
extern M2C_UNK data_021311e8;
extern M2C_UNK gDownloadPacket;
s32 FillU16(s32,void *,s32);
s32 CopyU16();
u16 Mb_Checksum16(u16 *,s32);
void WFC_SubmitDownloadData(s32,void *,s32,s32,s32,s32);
register void *p=M2C_FIELD(&gDownloadSendState,void **,0x1c);
u32 end=(u32)p+0x358;
register u32 src=M2C_FIELD(&gDownloadSendState,u32 *,0x20);
u32 n;
if(src+0x62<=end)M2C_FIELD(&gDownloadSendState,u8 *,0x4c)=0x62;
else {n=end-src;M2C_FIELD(&gDownloadSendState,u8 *,0x4c)=n;FillU16(0,(u8 *)&data_021311ee+(u8)n,0x62-(u8)n);}
CopyU16(M2C_FIELD(&gDownloadSendState,s32 *,0x20),&data_021311ee,M2C_FIELD(&gDownloadSendState,u8 *,0x4c));
M2C_FIELD(&gDownloadSendState,u8 *,0x4a)=M2C_FIELD(&gDownloadSendState,u8 *,0x27);
M2C_FIELD(&gDownloadSendState,u8 *,0x4b)=M2C_FIELD(&gDownloadSendState,u8 *,0x28);
p=M2C_FIELD(&gDownloadSendState,void **,0x1c);
((PacketBits *)((u8 *)&gDownloadSendState+0x44))->low=M2C_FIELD(p,u8 *,0x4b2);
M2C_FIELD(&gDownloadSendState,u8 *,0x45)=M2C_FIELD(p,u8 *,0x4b3);
M2C_FIELD(&gDownloadSendState,u8 *,0x46)=M2C_FIELD(&gDownloadSendState,u8 *,0x26);
M2C_FIELD(&gDownloadSendState,u32 *,0x40)=M2C_FIELD(p,u32 *,0x4b8);
((PacketBits *)((u8 *)&gDownloadSendState+0x44))->high=M2C_FIELD(p,u8 *,0x4b5);
M2C_FIELD(&gDownloadSendState,u8 *,0x47)=M2C_FIELD(&gDownloadSendState,u8 *,0x29)++;
M2C_FIELD(&gDownloadSendState,u16 *,0x48)=0;
M2C_FIELD(&gDownloadSendState,u16 *,0x48)=Mb_Checksum16((u16 *)&data_021311e8,0x68);
if((u8)++M2C_FIELD(&gDownloadSendState,u8 *,0x27)>=M2C_FIELD(&gDownloadSendState,u8 *,0x28))M2C_FIELD(&gDownloadSendState,u8 *,0x24)=4;
else M2C_FIELD(&gDownloadSendState,volatile u32 *,0x20)+=0x62;
WFC_SubmitDownloadData(0,&gDownloadPacket,0x70,a,b,(u8)(c|3));
}
#pragma opt_propagation reset
/* The current file's chunk phase is over: mark the sender as already having
 * received its roster packets, reload the roster step from the file's step
 * counter, and move the sender into the roster state. */
void DownloadBeginRoster(void) {
    extern M2C_UNK gDownloadSendState;
    M2C_FIELD(M2C_FIELD(&gDownloadSendState, void **, DL_CURRENT), u16 *, DL_FILE_ROSTER_SENT) = 1;
    M2C_FIELD(&gDownloadSendState, u8 *, DL_FILE_INDEX) = M2C_FIELD(M2C_FIELD(&gDownloadSendState, void **, DL_CURRENT), u8 *, DL_FILE_STEP);
    M2C_FIELD(&gDownloadSendState, u8 *, DL_STATE) = DL_STATE_SEND_ROSTER;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_lifetimes off
void DownloadSendRosterPacket(s32 a,s32 b,s32 c) {
extern M2C_UNK gDownloadSendState,data_02131248,data_021311f0,data_021311e8,gDownloadPacket;
s32 FillU16(s32,void *,s32);s32 CopyU16();
u16 Mb_Checksum16(u16 *,s32);
void WFC_SubmitDownloadData(s32,void *,s32,s32,s32,s32);
void *p,*header,*state; u8 *dest; register s32 i;u32 count;u16 mask;void (*callback)(u32);
p=M2C_FIELD(&gDownloadSendState,void **,0x1c);
if(M2C_FIELD(&gDownloadSendState,u8 *,0x26)!=M2C_FIELD(p,u8 *,0x4b4))DownloadBeginRoster();
state=&gDownloadSendState;
((PacketBits *)((u8 *)state+0x44))->low=2;
p=M2C_FIELD(state,void **,0x1c); header=(u8 *)p+0x300;
M2C_FIELD(state,u8 *,0x45)=M2C_FIELD(p,u8 *,0x4b3);
M2C_FIELD(state,u8 *,0x46)=M2C_FIELD(state,u8 *,0x26);
M2C_FIELD(state,u32 *,0x40)=M2C_FIELD(p,u32 *,0x4b8);
((PacketBits *)((u8 *)state+0x44))->high=M2C_FIELD(p,u8 *,0x4b5);
M2C_FIELD(state,u8 *,0x47)=M2C_FIELD(state,u8 *,0x29)++;
M2C_FIELD(state,u8 *,0x4a)=M2C_FIELD(p,u8 *,0x358);
M2C_FIELD(state,u16 *,0x4c)=M2C_FIELD(header,u16 *,0x5a);
M2C_FIELD(state,u16 *,0x4e)=M2C_FIELD(header,u16 *,0x5c);
if(!M2C_FIELD(state,s32 *,0x10)){
callback=M2C_FIELD(state,void (**)(u32),0x14);
if(callback)callback(M2C_FIELD(p,u32 *,0x4b8));
}
i=0;dest=(u8 *)&data_02131248;p=M2C_FIELD(&gDownloadSendState,void **,0x1c); goto checkCopy;
copyLoop: dest[i]=M2C_FIELD((u32)p+i,u8 *,0x4a8); i++;
checkCopy: if(i<8)goto copyLoop;
FillU16(0,&data_021311f0,0x58);
p=M2C_FIELD(&gDownloadSendState,void **,0x1c);
count=0;
mask=M2C_FIELD(p,u16 *,0x4b0)^M2C_FIELD(p,u16 *,0x35a);
i=0;goto checkEntries;entriesLoop: {
if(!(mask&(2<<i)))goto nextEntry;
CopyU16((u8 *)M2C_FIELD(&gDownloadSendState,void **,0x1c)+0x35e + i*22,(u8 *)&data_021311f0+count*22,22);
count++;
M2C_FIELD(M2C_FIELD(&gDownloadSendState,void **,0x1c),u16 *,0x4b0)|=2<<i;
if(count==4)goto entriesDone;
}
nextEntry:i++;
checkEntries:if(i<15)goto entriesLoop;
entriesDone:
if(count<4)M2C_FIELD(&data_021311f0,u8 *,count*22)&=~0xf0;
M2C_FIELD(&gDownloadSendState,u16 *,0x48)=0;
M2C_FIELD(&gDownloadSendState,u16 *,0x48)=Mb_Checksum16((u16 *)&data_021311e8,0x68);
p=M2C_FIELD(&gDownloadSendState,void **,0x1c);
if(M2C_FIELD(p,u16 *,0x4b0)==M2C_FIELD(p,u16 *,0x35a))M2C_FIELD(&gDownloadSendState,u8 *,0x24)=1;
WFC_SubmitDownloadData(0,&gDownloadPacket,0x70,a,b,(u8)(c|3));
if(M2C_FIELD(&gDownloadSendState,s32 *,0x10)==1){
callback=M2C_FIELD(&gDownloadSendState,void (**)(u32),0x14);
if(callback)callback(M2C_FIELD(M2C_FIELD(&gDownloadSendState,void **,0x1c),u32 *,0x4b8));
}
}
#pragma pop
/* Advance the match profile to the next player present in the WFC player mask:
 * scan the 16 slots cyclically from the profile's current slot, skipping it, and
 * store the first present slot.  Returns 0 when the mask has no player at all. */
s32 Mb_SelectNextPlayer(MbMatchProfile *profile) {
s32 WFC_GetPlayerMask();s32 playerMask;u16 scanned,currentSlot,slot;
playerMask=WFC_GetPlayerMask();if(!playerMask)return 0;
currentSlot=profile->playerSlot;scanned=0;slot=currentSlot;
do {
if((playerMask&(1<<(slot-1))) && currentSlot!=slot) {
profile->playerSlot=slot;break;
}
scanned++;slot=slot==16?1:slot+1;
}while(scanned<16);
return 1;
}

/* Whether the multiboot link can run its match-data exchange: the exchange is
 * under way, no send is still pending, the link is not shutting down and at
 * least one player is still in it. */
s32 Mb_LinkExchangeReady(void) {
    extern M2C_UNK gMbState;
    s32 ready;
    s32 notClosing;
    s32 exchangeStarted;

    ready = 0;
    exchangeStarted = 0;
    notClosing = 0;
    if ((M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u16 *, MB_LINK_EXCHANGE) == 1) && (M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u8 *, MB_LINK_SEND_PENDING) == 0)) {
        exchangeStarted = 1;
    }
    if ((exchangeStarted != 0) && (M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u16 *, MB_LINK_CLOSING) == 0)) {
        notClosing = 1;
    }
    if ((notClosing != 0) && (M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u16 *, MB_LINK_PLAYERS) != 0)) {
        ready = 1;
    }
    return ready;
}

/* Start the multiboot link's connect step: install Mb_HandleWfcEvent as the WFC
 * general handler and submit the connect request built from gMbParam, reporting
 * each result back through Mb_ReportPacketResult (message 0x80, then 0x1D). */
void Mb_StartConnect(void) {
    s32 WFC_SetGeneralHandler(M2C_UNK *);
    s32 WFC_SubmitConnectRequest(M2C_UNK *, u16, u16, u16, s32);
    M2C_UNK Mb_ReportPacketResult(M2C_UNK, s32);
    extern M2C_UNK gMbParam;
    extern M2C_UNK Mb_HandleWfcEvent;
    Mb_ReportPacketResult(0x80, WFC_SetGeneralHandler(&Mb_HandleWfcEvent));
    Mb_ReportPacketResult(0x1D, WFC_SubmitConnectRequest(&Mb_HandleWfcEvent, M2C_FIELD(&gMbParam, u16 *, 6), M2C_FIELD(&gMbParam, u16 *, 2), M2C_FIELD(&gMbParam, u16 *, 0), (s32) M2C_FIELD(&gMbParam, u16 *, 4)));
}

/* Finish cancelling the download-play link: mark the link as no longer started and
 * the download block as free, then report the cancel (event 17) to the game's link
 * callback so it tears the match state down. */
void Mb_CancelLink(s32 event) {
    extern M2C_UNK gMbState;
    void (*callback)(s32, s32);

    M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u8 *, MB_LINK_STARTED) = 0;
    M2C_FIELD(M2C_FIELD(&gMbState, void **, 12), u16 *, MB_DOWNLOAD_SET_UP) = 0;
    callback = M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), void (**)(s32, s32), MB_CTX_CALLBACK);
    if (callback) callback(MB_LINK_EVENT_CANCEL, event);
}

