/* 13 functions from 0x02014B34 to 0x02015AA0 (main), found by ds-decomp. */
#include "common.h"
typedef struct RomHeader_020152c8 { u8 unk_0[0x80]; u32 offset; } RomHeader_020152c8;
/* One program image while it is being loaded: where it starts in the
 * program's address space, its size, and the source/destination buffers
 * biased by -start so that (buffer + image address) is the real address. */
typedef struct MbImageRegion_02015248 { u32 start; u32 source; u32 dest; u32 size; } MbImageRegion_02015248;
#define MB_PROGRAM_ADDR 0x027ffe00      /* the ROM program area the multiboot library reads from */
#define MB_PROGRAM_HEADER_SIZE 0x60     /* program header at the start of a multiboot program image */
#define MB_MIN_PROGRAM_SIZE 0x10000     /* smallest program image the loader accepts */
static inline u32 FilePosition_020152c8(void *file) { return M2C_FIELD(file,u32 *,0x2c)-M2C_FIELD(file,u32 *,0x24); }


/* Select units by state into priority groups, then dispatch the matching network action. */

/* Size in bytes of the download-play program image: read the 0x60-byte
 * program header from the request's current file position (or from the ROM
 * program area when the caller passes no request), seek back, and add the two
 * image block sizes that follow the header to the fixed header content.  The
 * result is never below 64 KiB. */
u32 Mb_GetProgramSize(void *file) {
 s32 FileRead(void *,s32,s32);
 void FileSeek(void *,s32,s32);
 void *header;
 u32 size;
 u32 headerBuffer[24];
 s32 origin;
 header = NULL;
 size = 0;
 if (file != NULL) {
     origin = M2C_FIELD(file, s32 *, 0x2c) - M2C_FIELD(file, s32 *, 0x24);
     if ((u32)FileRead(file, (s32)headerBuffer, MB_PROGRAM_HEADER_SIZE) >= (u32)MB_PROGRAM_HEADER_SIZE) {
         header = headerBuffer;
     }
     FileSeek(file, origin, 0);
 } else {
     header = (void *)MB_PROGRAM_ADDR;
 }
 if (header != NULL) {
     size = M2C_FIELD(header, s32 *, 0x2c) + 0x268 + M2C_FIELD(header, s32 *, 0x3c);
     if (size < (u32)MB_MIN_PROGRAM_SIZE) {
         size = MB_MIN_PROGRAM_SIZE;
     }
 }
 return size;
}

void AutoloadCallback(void);
#pragma opt_strength_reduction off
#pragma opt_common_subs off
s32 Mb_LoadProgramImage(void *arg0,void *arg1,s32 arg2){
 s32 FileRead(void *,s32,s32);void FileSeek(void *,s32,s32);void InitFileRequest();s32 FindArchive();void OpenFileDirect();M2C_UNK MI_CpuCopy8(s32,s32,s32);void Mb_InitLoadQueue();void Mb_AddImageBlock();void CloseFileRequest();void Mb_FillOrCopyImageRange(void *,u32,u32,s32);void DC_FlushRange();
 extern u8 data_020f554c[];extern u32 *data_020f5548;
 u8 file[0x48];u32 info[4];s32 result,owned;u32 size;u32 left;void *p,*header,*table;u32 base,readBase,origin,n; s32 i;u32 *ranges;
 size=arg2;result=0;
 if(size>=0x164){
 left=size;p=arg1;owned=0;header=0;table=0;p+=0x160;left-=0x160;
 if(arg0){
 origin=M2C_FIELD(arg0,u32 *,0x2c)-M2C_FIELD(arg0,u32 *,0x24);
 if(FileRead(arg0,(s32)arg1,0x160)<0x160)left=0;
 base=M2C_FIELD(arg1,u32 *,0x80);if(!base)base=0x1000000;
 }else{
 base=((RomHeader_020152c8 *)0x027ffe00)->offset;if(!base)base=0x1000000;owned=1;
 InitFileRequest(file);
 n=FindArchive(data_020f554c,3);
 OpenFileDirect(file,n,0,base+0x88,-1);
 arg0=file;origin=M2C_FIELD(arg0,u32 *,0x2c)-M2C_FIELD(arg0,u32 *,0x24);
 MI_CpuCopy8(0x027ffe00,(s32)arg1,0x160);
 M2C_FIELD(arg1,u32 *,0x60)|=0x406000;
 }
 if(left<0x88)left=0;
 else{FileSeek(arg0,origin+base,0);FileRead(arg0,(s32)p,0x88);p+=0x88;left-=0x88;}
 if(left>=0x70){
 header=p;Mb_InitLoadQueue(p);
 p+=0x70;left-=0x70;Mb_AddImageBlock(header,0,0x160,arg1,3);
 n=M2C_FIELD(arg0,u32 *,8);
 for(i=0;i<3&&M2C_FIELD(n,s8 *,i)!=0;i++);
 MI_CpuCopy8(n,(s32)header+0x10,i);M2C_FIELD(header,u32 *,0x14)=i;
 }else left=0;
 if(left<0x10)left=0;
 else{
 M2C_FIELD(p,u32 *,0)=0;
 M2C_FIELD(p,u32 *,4)=M2C_FIELD(arg1,u32 *,0x20)+(origin+M2C_FIELD(arg0,u32 *,0x24));
 M2C_FIELD(p,u32 *,8)=M2C_FIELD(arg1,u32 *,0x30)+(origin+M2C_FIELD(arg0,u32 *,0x24));
 table=p;p+=0x10;left-=0x10;
 }
 if(left>=M2C_FIELD(arg1,u32 *,0x2c)+M2C_FIELD(arg1,u32 *,0x3c)){
 readBase=M2C_FIELD(arg0,u32 *,0x24);
 FileSeek(arg0,M2C_FIELD(table,u32 *,4)-readBase,0);
 FileRead(arg0,(s32)p,M2C_FIELD(arg1,u32 *,0x2c));
 Mb_AddImageBlock(header,M2C_FIELD(table,u32 *,4),M2C_FIELD(arg1,u32 *,0x2c),p,3);
 left=M2C_FIELD(arg1,u32 *,0x2c);
 FileSeek(arg0,M2C_FIELD(table,u32 *,8)-readBase,0);
 FileRead(arg0,(s32)p+left,M2C_FIELD(arg1,u32 *,0x3c));
 Mb_AddImageBlock(header,M2C_FIELD(table,u32 *,8),M2C_FIELD(arg1,u32 *,0x3c),p+left,3);
 result=1;
 }else if(left>=0xcc00){
 left=M2C_FIELD(arg0,u32 *,0x24);base=M2C_FIELD(table,u32 *,4);
 FileSeek(arg0,base-left,0);FileRead(arg0,(s32)p,0x4400);
 Mb_AddImageBlock(header,base,0x4400,p,3);
 FileSeek(arg0,base+0x4400-left,0);FileRead(arg0,(s32)p+0x4400,0x4400);
 Mb_AddImageBlock(header,base+0x4400,0x4400,p+0x4400,2);
 FileSeek(arg0,base+0x8800-left,0);FileRead(arg0,(s32)p+0x8800,0x4400);
 Mb_AddImageBlock(header,base+0x8800,0x4400,p+0x8800,2);result=1;
 }
 FileSeek(arg0,origin,0);
 if(owned){
 CloseFileRequest(file);
 if(result){
 info[0]=M2C_FIELD(arg1,u32 *,0x20);info[1]=M2C_FIELD(arg1,u32 *,0x28)-M2C_FIELD(arg1,u32 *,0x20);info[2]=M2C_FIELD(header,u32 *,0x48)-M2C_FIELD(arg1,u32 *,0x20);info[3]=size;
 ranges=data_020f5548;
 Mb_FillOrCopyImageRange(info,0x4000,0x8000,1);
 while(ranges[1]){Mb_FillOrCopyImageRange(info,ranges[0],ranges[0]+ranges[1],0);ranges+=2;}
 n=(u32)AutoloadCallback-M2C_FIELD(arg1,u32 *,0x28);M2C_FIELD(M2C_FIELD(header,void **,0x48),u32 *,n)=0xe12fff1e;
 }
 }
 if(result)DC_FlushRange(arg1,size);
 }
 return result;
}
/* Fill or copy one range of a program image being loaded: clip the requested
 * [start, end) address range to the image's own range (region->start ..
 * region->start + region->size) and to the loader's 0x4000..0x8000 window,
 * then clear the destination (clear != 0) or copy the source into it. */
void Mb_FillOrCopyImageRange(void *arg0, u32 start, u32 end, s32 clear) {
    MbImageRegion_02015248 *region = arg0;
    s32 MI_CpuFill8(s32, s32, s32);
    s32 MI_CpuCopy8(s32, s32, s32);
    u32 imageStart = region->start;
    u32 imageEnd;

    if (start < 0x4000U) {
        start = 0x4000;
    }
    if (end > 0x8000U) {
        end = 0x8000;
    }
    imageEnd = imageStart + region->size;
    if (start < imageStart) {
        start = imageStart;
    }
    if (end > imageEnd) {
        end = imageEnd;
    }
    if (start >= end) {
        return;
    }
    if (clear != 0) {
        MI_CpuFill8(region->dest + start, 0, end - start);
        return;
    }
    MI_CpuCopy8(region->source + start, region->dest + start, end - start);
}

#pragma push
#pragma scheduling off
s32 Mb_RegisterProgram(s32 arg0, s32 arg1) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    void Mb_BuildProgramRecord(void *, void *);
    s32 Mb_BuildChunkIndex(void *, void *);
    M2C_UNK func_02015f94(void *, s32, void *);
    M2C_UNK DownloadQueueFile(void *);
    s32 MultiBoot_IsLinkStarted();
    M2C_UNK Mb_StartWorkerTask(void *, M2C_UNK);
    s32 Mb_IsTaskCreated();
    M2C_UNK MbWorker_ClearJob(void *);
    extern u8 data_02131184;
    extern void *gMbWork;
    u8 var_r4;
    u8 var_r6;
    s32 temp_r2;
    s32 temp_r5;
    s32 temp_r6;
    void *temp_r9; s32 sequence;

    var_r4 = 0xFF;
    temp_r5 = OS_DisableInterrupts();
    if (MultiBoot_IsLinkStarted() == 0) {
        OS_RestoreInterrupts(temp_r5);
        return 0;
    }
    if ((s32) (M2C_FIELD(gMbWork, u8 *, 0x1524) + 1) > 0x10) {
        OS_RestoreInterrupts(temp_r5);
        return 0;
    }
    var_r6 = 0;
loop_5:
    temp_r2 = (var_r6 * 0x5D4) + (s32) gMbWork;
    if (M2C_FIELD(temp_r2, s32 *, 0x1D40) == arg0) {
        OS_RestoreInterrupts(temp_r5);
        return 0;
    }
    if (M2C_FIELD(temp_r2, u8 *, 0x1D52) == 0) {
        var_r4 = var_r6;
        goto block_10;
    }
    var_r6 += 1;
    if ((u32) var_r6 >= 0x10U) {
block_10:
        if (var_r6 == 0x10) {
            OS_RestoreInterrupts(temp_r5);
            return 0;
        }
        temp_r6 = var_r4 * 0x5D4;
        M2C_FIELD((gMbWork + temp_r6), s32 *, 0x1D40) = arg0;
        temp_r9 = gMbWork + 0x1788 + temp_r6;
        Mb_BuildProgramRecord(temp_r9, arg1);
        MI_CpuCopy8(arg0 + 0x1C, temp_r9 + 0xC4, 0x20);
        if (Mb_BuildChunkIndex(gMbWork + 0x1D2C + temp_r6, temp_r9) == 0) {
            OS_RestoreInterrupts(temp_r5);
            return 0;
        }
        func_02015f94(gMbWork + 0x186C + temp_r6, arg0, gMbWork + 0x1300);
        M2C_FIELD((gMbWork + temp_r6), u8 *, 0x1D21) = var_r4;
        DownloadQueueFile(gMbWork + 0x186C + temp_r6);
        sequence=data_02131184;
        M2C_FIELD((gMbWork + temp_r6), u8 *, 0x1D1F) = sequence;
        M2C_FIELD((gMbWork + temp_r6), s16 *, 0x1D4E) = 1;
        M2C_FIELD((gMbWork + temp_r6), s32 *, 0x1D44) = arg1;
        M2C_FIELD((gMbWork + temp_r6), s32 *, 0x1D54) = (s32) (arg1 + 0x1E8);
        M2C_FIELD((gMbWork + temp_r6), s32 *, 0x1D58) = (s32) (arg1 + 0x258);
        data_02131184 = sequence+1;
        if ((M2C_FIELD(M2C_FIELD((gMbWork + temp_r6), void **, 0x1D54), s32 *, 0x6C) != 0) && (Mb_IsTaskCreated() == 0)) {
            MbWorker_ClearJob(gMbWork + 0x7CE0);
            Mb_StartWorkerTask(gMbWork + 0x74E0, 0x800);
        }
        M2C_FIELD((gMbWork + temp_r6), s8 *, 0x1D52) = 1;
        M2C_FIELD(gMbWork, u8 *, 0x1524) = (u8) (M2C_FIELD(gMbWork, u8 *, 0x1524) + 1);
        OS_RestoreInterrupts(temp_r5);
        return 1;
    }
    goto loop_5;
}
#pragma pop
/* Build a member's program record from a program header: copy the two header
 * offsets, describe each of the three image chunks (header, code, extra block)
 * into its descriptor, allocating the extra block from the shared download pool,
 * then copy the program's 0x88-byte chunk table. */
void Mb_BuildProgramRecord(void *record, void *header) {
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    void Mb_DescribeChunk(void *, void *, void *, s32 *);
    extern u8 sMbChunkKinds[];
    s32 pool;
    u8 *kind;
    MbMemoryDescriptor *out;
    s32 i;

    pool = 0x022C0000;
    kind = sMbChunkKinds;
    M2C_FIELD(record, s32 *, 0) = M2C_FIELD(header, s32 *, 0x24);
    out = (MbMemoryDescriptor *)((u8 *)record + 12);
    M2C_FIELD(record, s32 *, 4) = M2C_FIELD(header, s32 *, 0x34);
    i = 0;
    do {
        Mb_DescribeChunk(header, kind, out, &pool);
        i++;
        out++;
        kind += 4;
    } while (i < 3);
    MI_CpuCopy8((s32)header + 0x160, (s32)record + 0x3C, 0x88);
}
