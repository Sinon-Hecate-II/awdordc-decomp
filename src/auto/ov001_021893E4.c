/* 27 functions from 0x021893E4 to 0x0218A384 (ov001), found by ds-decomp. */
#include "common.h"
/* The ov001 profile / download-play setup state (gOv001ProfileState). */
#define PROFILE_STATE      0xA90 /* u8 current screen state */
#define PROFILE_PREV_STATE 0xA91 /* u8 state before the last change */
#define PROFILE_LIST_COUNT 0x200 /* u16 highlighted row of the profile list */
#define PROFILE_LIST_TIMER 0x204 /* u32 frames the list has been shown */
#define PROFILE_MAP_W      0x648 /* u16 */
#define PROFILE_MAP_H      0x64A /* u16 */
#define PROFILE_LIST_BASE  0xAA4 /* void * base of the profile list entries */
#define PROFILE_FILE       0xAB4 /* request block for the profile download */
#define PROFILE_ENTRY_BASE 0x100  /* first of two 0x44-byte slot entries (id, 0x40-byte data) */
#define PROFILE_ENTRY_SIZE 0x44   /* bytes per slot entry */
#define PROFILE_ENTRY_VALID 0x208 /* s32 per slot: its entry holds a received slot */
#define PROFILE_LINKED     0xA93 /* u8: the download-play link is connected */
#define PROFILE_LINK_TICKS 0xA94 /* s32: link ticks, a list move every other one */
#define PROFILE_CURSOR_MARK 0x202 /* u16 cursor id pushed to the connected players */
#define PROFILE_ROW_COUNT  0x24   /* rows in a profile list round */
#define PROFILE_ID_ROW     0x10   /* entry id: the row is selected */
#define PROFILE_ID_CONNECT 0xBC   /* entry id: wait for a connection */
#define PROFILE_ID_JOIN    0xBD   /* entry id: the joining player said yes */
typedef struct A070Node { struct A070Node *prev; struct A070Node *next; s32 start; u8 size; u8 pad[3]; } A070Node;
typedef struct A070Pool { u8 pad[0x200]; A070Node head; A070Node tail; s32 unk220; s32 handle; } A070Pool;
/* The ov001 sprite-object pools (gOv001SpritePools): each pool recycles 0x10-byte
 * sprite objects through freeObjs and keeps the blocks it has handed out in an
 * address-ordered list bookended by the head/tail sentinels. */
typedef struct Ov001SpritePool { u8 slots[0x200]; A070Node head; A070Node tail; s32 list; s32 freeObjs; } Ov001SpritePool;
#define OV001_SPRITE_POOL_COUNT 2
#define OV001_SPRITE_POOLS ((Ov001SpritePool *)gOv001SpritePools)

/* Advances the download-play (single-card) setup from the multiboot link status:
 * starts the profile transfer, waits for the connected players or drops them when a
 * link test fails, and moves the profile screen state to the matching next step. */
void Ov001_UpdateLinkState(void) {
    s32 Ov001_GetLinkStatus(void);
    s32 Ov001_GetLinkInfo(s32);
    void func_ov001_02186fa0(M2C_UNK, M2C_UNK);
    s32 func_ov001_021873ec(void);
    void func_ov001_02187454(void);
    void func_ov001_0218754c(void);
    s32 Ov001_GetTaskStep(void);
    s32 func_ov001_02188c28(void);
    extern void *gOv001ProfileState;

    s32 status = Ov001_GetLinkStatus();
    switch (status) {
    case 1: {
        void *state = gOv001ProfileState;
        func_ov001_02186fa0((u8 *)state + PROFILE_FILE,
            M2C_FIELD(state, u16 *, PROFILE_MAP_H));
        return;
    }
    case 2: {
        s32 info = Ov001_GetLinkInfo(2);
        if (info != 0) {
            M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 5;
            return;
        }
        if(Ov001_GetLinkInfo(3) || Ov001_GetLinkInfo(4)) {
            M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)=6;
            return;
        }
        if(M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)!=5)return;
        if(Ov001_GetLinkInfo(2))return;
        M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)=0xd;
        return;
    }
    case 3: {
        s32 ready = func_ov001_021873ec();
        if (ready != 0) {
            func_ov001_02187454();
            return;
        }
        {
            u8 state = M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE);
            if ((u8)(state + 0xfa) > 1) { /* state is neither 6 nor 7 */
                return;
            }
        }
        ready = Ov001_GetLinkInfo(3);
        if (ready != 0) {
            return;
        }
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 0x12;
        return;
    }
    case 5: {
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 0x7;
        return;
    }
    case 7: {
        func_ov001_0218754c();
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 0x1;
        return;
    }
    case 0: {
        switch(Ov001_GetTaskStep()){
        case 1:func_ov001_02188c28();return;
        case 0:
            M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)=0x1f;
            return;
        case 3:return;
        default:
            M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)=0x1f;
            return;
        }
    }
    case 4:
    case 6:
    default:
        return;
    }
}

void func_ov001_0218959c(void) {
    M2C_UNK func_ov001_02189828(void);
    void func_ov001_02188a20(s32);
    extern s32 func_ov001_021897ec(s32);
    extern void *gOv001ProfileState;
    func_ov001_02189828();
    func_ov001_02188a20((s32) &func_ov001_021897ec);
    M2C_FIELD(gOv001ProfileState, u8 *, 0xA90) = 8;
}

/* Updates the profile / download-play setup screen while it is in one of its list states: it
 * feeds the profile entries to the underlying multiboot task and, when the list has settled,
 * turns the current input code into the next screen state. */
void Ov001_UpdateProfileTask(void) {
    s32 Ov001_GetTaskStep(void);
    void func_ov001_021888a8(s32, u16, u16, s32);
    void func_ov001_0218986c(s32, s32, void *);
    void Ov001_UpdateProfileLink(void);
    u16 Ov001_ReadInputCode(void);
    extern void *gOv001ProfileState;

    s32 step = Ov001_GetTaskStep();
    switch (step) {
    case 1: {
        u16 mapWidth = *(u16 *)((u8 *)gOv001ProfileState + PROFILE_MAP_W);
        u16 mapHeight = *(u16 *)((u8 *)gOv001ProfileState + PROFILE_MAP_H);
        func_ov001_021888a8(4, (u16)(mapWidth + 1), mapHeight, mapWidth);
        break;
    }
    case 4:
    case 5:
    case 6: {
        u16 row = *(u16 *)((u8 *)gOv001ProfileState + PROFILE_LIST_COUNT);
        void *listBase = *(void **)((u8 *)gOv001ProfileState + PROFILE_LIST_BASE);
        u32 index = row % 16;
        void *entry = (u8 *)listBase + (index << 6);
        func_ov001_0218986c(0, row, entry);
        Ov001_UpdateProfileLink();
        if (*(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) == 0x1b) break;
        if (*(u32 *)((u8 *)gOv001ProfileState + PROFILE_LIST_TIMER) > 0x1e0) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x1b;
            break;
        }
        if (Ov001_ReadInputCode() == 0x10 || Ov001_ReadInputCode() == 0x20) {
            Ov001_ReadInputCode();
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0xa;
        } else if (Ov001_ReadInputCode() == 0x40) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0xb;
        } else if (Ov001_ReadInputCode() == 0xff) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x1b;
        } else if (Ov001_ReadInputCode() == 0x50) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x15;
        } else if (Ov001_ReadInputCode() == 0x60) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x18;
        } else if (Ov001_ReadInputCode() == 0x70) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x1b;
        } else if (Ov001_ReadInputCode() == 0x0) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x8;
        } else if (Ov001_ReadInputCode() == 0xbd) {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x9;
        } else {
            *(u8 *)((u8 *)gOv001ProfileState + PROFILE_STATE) = 0x1f;
        }
        break;
    }
    default:
        break;
    }
}

void func_ov001_021897a4(void) {
    extern void *gOv001ProfileState;
    M2C_FIELD(gOv001ProfileState, s8 *, 0xA90) = 0xC;
}

s32 func_ov001_021897bc(void) {
    M2C_UNK Ov001_GetTaskStep(void);
    M2C_UNK func_ov001_02188c28(void);
    extern void *gOv001ProfileState;
    if (Ov001_GetTaskStep() != 1) {
        return 0;
    }
    func_ov001_02188c28();
    M2C_FIELD(gOv001ProfileState, u8 *, 0xA90) = 1;
    return 1;
}

s32 func_ov001_021897ec(s32 arg0) {
    s32 func_ov001_02187a30(s32);
    s32 func_ov001_021879fc(s32);
    extern void *gOv001ProfileState;
    s32 temp_r0;

    temp_r0 = func_ov001_02187a30(arg0 + 0xA);
    if (temp_r0 == 0) {
        return 0;
    }
    M2C_FIELD((u8 *) gOv001ProfileState + (temp_r0 - 1) * 4, s32 *, 0xAA0) = func_ov001_021879fc(temp_r0);
    return 1;
}

M2C_UNK func_ov001_02189828(void) {
 extern void *gOv001ProfileState; void MI_CpuFill8(void*,s32,s32); void *p;
 MI_CpuFill8((u8*)gOv001ProfileState+0x100,0,0x100);
 MI_CpuFill8(gOv001ProfileState,0,0x100);
 p=gOv001ProfileState;
 M2C_FIELD(p,void**,0xAB0)=p;
 return (s32)p;
}

void func_ov001_0218986c(s32 arg0, s32 arg1, void *arg2) {
    M2C_UNK Ov001_GetTaskStep(void);
    M2C_UNK DWCi_MOV_WH_StepDataSharing(void *);
    M2C_UNK func_ov001_02188380(void);
    M2C_UNK func_ov001_02188a34(s32);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void *gOv001ProfileState;
    u16 i;

    if (*(u8 *)((u8 *)gOv001ProfileState + 0xa93) == 1) {
        *(u16 *)*(void **)((u8 *)gOv001ProfileState + 0xab0) = (u16)arg0;
        *(u16 *)((u8 *)*(void **)((u8 *)gOv001ProfileState + 0xab0) + 2) = (u16)arg1;
        MI_CpuCopy8(arg2, (u8 *)*(void **)((u8 *)gOv001ProfileState + 0xab0) + 4, 0x40);
        return;
    }

    *(u32 *)((u8 *)gOv001ProfileState + 0x204) += 1;
    *(u16 *)*(void **)((u8 *)gOv001ProfileState + 0xab0) = 0xbc;
    ((u8 *)*(void **)((u8 *)gOv001ProfileState + 0xab0))[4] = *(u8 *)((u8 *)gOv001ProfileState + 0xa92);

    if (Ov001_GetTaskStep() != 5) {
        return;
    }
    if (DWCi_MOV_WH_StepDataSharing(gOv001ProfileState) == 0) {
        *(u32 *)((u8 *)gOv001ProfileState + 0x204) += 4;
        return;
    }
    if (*(u8 *)((u8 *)gOv001ProfileState + 0xa93) == 0) {
        *(u32 *)((u8 *)gOv001ProfileState + 0x204) += 1;
    } else {
        *(u32 *)((u8 *)gOv001ProfileState + 0x204) = 0;
        if (func_ov001_02188380() != 3) {
            *(u8 *)((u8 *)gOv001ProfileState + 0xa90) = 0x1b;
            return;
        }
    }

    for (i = 0; i < 2; i = (u16)(i + 1)) {
        void *src = func_ov001_02188a34(i);
        if (src == 0) {
            *(s32 *)((u8 *)gOv001ProfileState + 0x208 + i * 4) = 0;
        } else {
            MI_CpuCopy8(src, (u8 *)gOv001ProfileState + 0x100 + i * 0x44, 0x44);
            *(s32 *)((u8 *)gOv001ProfileState + 0x208 + i * 4) = 1;
        }
    }
}

#pragma optimization_level 2
/* Advances the download-play link exchange from the player slots' reply entries:
 * while connected, counts link ticks and steps this console's list row every
 * other tick; otherwise pushes the wait-for-connection id, and starts the list
 * round (row 0, no ticks) once the joining player accepted. */
void Ov001_UpdateProfileLink(void) {
extern void *gOv001ProfileState;s32 i;u8 *p;
i=0;do {
if(M2C_FIELD((u8 *)gOv001ProfileState+i*4,s32*,PROFILE_ENTRY_VALID)){
p=(u8 *)gOv001ProfileState+PROFILE_ENTRY_BASE+i*PROFILE_ENTRY_SIZE;
if(i==1){
if(M2C_FIELD(gOv001ProfileState,u8*,PROFILE_LINKED)==1){
if(*(u16 *)p!=PROFILE_ID_ROW)return;
M2C_FIELD(gOv001ProfileState,s32*,PROFILE_LINK_TICKS)++;
if(!(M2C_FIELD(gOv001ProfileState,s32*,PROFILE_LINK_TICKS)&1)){
M2C_FIELD(gOv001ProfileState,u16*,PROFILE_LIST_COUNT)++;
if(M2C_FIELD(gOv001ProfileState,u16*,PROFILE_LIST_COUNT)>=PROFILE_ROW_COUNT)M2C_FIELD(gOv001ProfileState,u16*,PROFILE_LIST_COUNT)=0;
}
}else{
M2C_FIELD(gOv001ProfileState,u16*,PROFILE_CURSOR_MARK)=PROFILE_ID_CONNECT;
if(*(u16 *)p==PROFILE_ID_JOIN){
M2C_FIELD(gOv001ProfileState,u8*,PROFILE_LINKED)=1;
M2C_FIELD(gOv001ProfileState,u16*,PROFILE_LIST_COUNT)=0;
M2C_FIELD(gOv001ProfileState,s32*,PROFILE_LINK_TICKS)=0;
}
}
}
}
i++;
}while(i<16);
}
#pragma optimization_level 4
u16 Ov001_ReadInputCode(void) {
    extern void *gOv001ProfileState;
    void *ptr = gOv001ProfileState;
    return M2C_FIELD((u8 *)ptr + 0x100, u16 *, 0x44);
}

/* Loads the DWC utility data from "rom:/dwc/utility.bin" into the DWC utility
   state: opens the file, reads its two header words, opens the "dwc" archive
   through the registered callbacks, allocates and reads the data block, then
   sets the file directory to "dwc:/". */
void func_ov001_02189ad0(void) {
    s32 Ov001_Alloc(s32, s32);
    void InitFileRequest(void *);
    s32 OpenFileRequest(void *, void *);
    void SystemHalt(void);
    s32 OS_GetLockID(void);
    void FileRead(void *, void *, s32);
    void CloseFileRequest(void *);
    void func_0200b118(void *);
    s32 RegisterArchiveName(void *, void *, s32);
    void func_0200b6a8(void *, s32, s32);
    s32 func_0200b2bc(void *, s32, s32, s32, s32, s32, void *, void *);
    s32 LoadArchiveIndex(void *, s32, s32);
    s32 Ov001_QueueCreateFromBuffer(s32, s32, s32);
    void func_0200563c(void *, void *, ...);
    void SetFileDirectory(void *);
    extern void *data_ov001_02193e2c;
    extern char data_ov001_02191794[];
    extern char data_ov001_0218fd04[];
    extern char data_ov001_021917ac[];
    s32 func_ov001_02189d0c(s32, s32);
    s32 func_ov001_02189d70(void *, M2C_UNK, s32,s32);
    s32 func_ov001_02189dc0(void);

    u8 request[0x48];
    u8 dirName[0x80];
    u32 hi[2],lo[2];
    s32 fileSize;
    void *data;
    s32 dataSize;

    data_ov001_02193e2c = (void *)Ov001_Alloc(0xE8, 4);
    InitFileRequest(request);
    if (!OpenFileRequest(request, data_ov001_02191794)) {
        SystemHalt();
    }
    M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4) = (u16)OS_GetLockID();
    fileSize = *(s32 *)(request + 0x24);
    FileRead(request, hi, 8);
    FileRead(request, lo, 8);
    CloseFileRequest(request);
    func_0200b118((u8 *)data_ov001_02193e2c + 0x88);
    if (!RegisterArchiveName((u8 *)data_ov001_02193e2c + 0x88, data_ov001_0218fd04, 3)) {
        SystemHalt();
    }
    func_0200b6a8((u8 *)data_ov001_02193e2c + 0x88, (s32)func_ov001_02189d0c, 0x602);
    if (!func_0200b2bc((u8 *)data_ov001_02193e2c + 0x88, fileSize, lo[0], lo[1], hi[0], hi[1], (void *)func_ov001_02189d70, (void *)func_ov001_02189dc0)) {
        SystemHalt();
    }
    dataSize = LoadArchiveIndex((u8 *)data_ov001_02193e2c + 0x88, 0, 0);
    data = (void *)Ov001_Alloc(dataSize, 4);
    *(void **)data_ov001_02193e2c = data;
    LoadArchiveIndex((u8 *)data_ov001_02193e2c + 0x88, (s32)*(void **)data_ov001_02193e2c, dataSize);
    M2C_FIELD(data_ov001_02193e2c, s32 *, 0x84) = (s32)Ov001_QueueCreateFromBuffer(0x20, (s32)((u8 *)data_ov001_02193e2c + 4), 4);
    func_0200563c(dirName, data_ov001_021917ac, data_ov001_0218fd04);
    SetFileDirectory(dirName);
}

void func_ov001_02189c80(void) {
extern void *data_ov001_021917b4[2];
extern void *data_ov001_02193e2c;
void func_0200bc5c(void *);
void func_0200b510(void *);
void func_0200b32c(void *);
void func_0200b238(void *);
void OS_ReleaseLockID(u16);
void Ov001_FreeAlloc(void *);
func_0200bc5c(data_ov001_021917b4);
func_0200b510((u8 *)data_ov001_02193e2c+0x88);
func_0200b32c((u8 *)data_ov001_02193e2c+0x88);
func_0200b238((u8 *)data_ov001_02193e2c+0x88);
OS_ReleaseLockID(M2C_FIELD(data_ov001_02193e2c,u16 *,0xe4));
M2C_FIELD(data_ov001_02193e2c,u16 *,0xe4)=0;
Ov001_FreeAlloc(data_ov001_02193e2c);
M2C_FIELD(data_ov001_02193e2c,u32 *,0)=0;
Ov001_FreeAlloc((void *)0x02193e2c);
}

s32 func_ov001_02189d0c(s32 arg0, s32 arg1) {
    M2C_UNK CARD_LockRom(u16);
    M2C_UNK CARD_UnlockRom(u16);
    extern void *data_ov001_02193e2c;
    
    switch (arg1) {
    case 9:
        CARD_LockRom(M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4));
        return 0;
    case 10:
        CARD_UnlockRom(M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4));
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}

void func_ov001_02189db0(M2C_UNK arg0);

s32 func_ov001_02189d70(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
 void func_02010b1c(s32,s32,s32,s32,s32,void*,s32);
 func_02010b1c(-1,arg2+M2C_FIELD(arg0,s32*,0x28),arg1,arg3,(s32)func_ov001_02189db0,arg0,1);
 return 6;
}

void func_ov001_02189db0(M2C_UNK arg0) {
    M2C_UNK func_0200b6c8(M2C_UNK, M2C_UNK);
    func_0200b6c8(arg0, 0);
}

s32 func_ov001_02189dc0(void) {
    return 1;
}

/* Loads a file into memory: reads the whole file into a raw buffer and returns it,
 * or, for a compressed (.lz) file, allocates the decompressed buffer from the size
 * word at the head of the file and returns that, freeing the raw read.  *outSize
 * gets the size of the returned buffer; alignment is the caller's unless the buffer
 * must be freed with the compressed helper. */
void *Ov001_LoadFile(void *path, u32 *outSize, s32 alignment) {
s32 Ov001_QueuePop(s32);
void InitFileRequest(void *);
s32 OpenFileRequest(void *, void *);
void SystemHalt(void);
void FileRead(void *, void *, s32);
void CloseFileRequest(void *);
void Ov001_DecompressBuffer(void *, void *);
void Ov001_FreeAlloc(void *);
s32 Ov001_Alloc(s32, s32);
extern void *data_ov001_02193e2c;
extern s32 data_ov001_021917bc;
void *raw;
u32 request[18];
u32 size;
s32 align;
void *out;
Ov001_QueuePop(M2C_FIELD(data_ov001_02193e2c, s32 *, 0x84));
InitFileRequest(request); if (!OpenFileRequest(request, path)) SystemHalt();
size = request[10] - request[9]; if (outSize) *outSize = size;
if (Ov001_FileHasSuffix(path, (s32)&data_ov001_021917bc, 2)) align = -4; else align = alignment;
raw = (void *)Ov001_Alloc(size, align);
FileRead(request, raw, size); CloseFileRequest(request);
if (align > 0) return raw;
size = *(u32 *)raw >> 8; if (outSize) *outSize = size;
out = (void *)Ov001_Alloc(size, alignment); Ov001_DecompressBuffer(raw, out); Ov001_FreeAlloc(&raw); return out;
}

void Ov001_FreeFile(s32 arg0, ...) {
 M2C_UNK Ov001_QueuePush(s32,void*); void Ov001_FreeAlloc(void*); extern void *data_ov001_02193e2c;
 Ov001_FreeAlloc(&arg0);
 Ov001_QueuePush(M2C_FIELD(data_ov001_02193e2c,s32*,0x84),(void*)arg0);
}

s32 Ov001_FileHasSuffix(void *arg0, s32 arg1, s32 arg2) {
    s32 StringLength(void *);
    s32 ByteCompareN(void *, void *, s32);
    s32 temp_r4;
    s32 temp_r0;
    
    temp_r4 = StringLength(arg0);
    temp_r0 = StringLength(arg1);
    if (temp_r4 < arg2 || temp_r0 < arg2) {
        return 0;
    }
    if (ByteCompareN(arg0 + (temp_r4 - arg2), arg1 + (temp_r0 - arg2), arg2) == 0) {
        return 1;
    }
    return 0;
}

/* Initializes the two ov001 sprite-object pools: allocates the pool array and,
 * for each pool, wires up its free-object queue and its allocation list, seeding
 * the list with the head and tail sentinels that bound the pool's 0x200-byte
 * block region in the sprite arena. */
void Ov001_InitSpritePools(void) {
    s32 Ov001_QueueCreateFromBuffer(s32, s32, s32);
    s32 Ov001_Alloc(s32, s32);
    s32 Ov001_ListCreate(void);
    void Ov001_ListPushBack(s32, void *);
    void Ov001_ListPushFront(s32, void *);
    s32 Ov001_SpriteObjAddr(s32, s32);
    extern s32 gOv001SpritePools;
    s32 i;
    Ov001SpritePool *p;

    gOv001SpritePools = Ov001_Alloc(sizeof(Ov001SpritePool) * OV001_SPRITE_POOL_COUNT, 4);
    for (i = 0; i < OV001_SPRITE_POOL_COUNT; i++) {
        /* 0x20 free-object slots of 0x10 bytes each fill the pool's first 0x200 bytes. */
        OV001_SPRITE_POOLS[i].freeObjs = Ov001_QueueCreateFromBuffer(0x20, (s32)&OV001_SPRITE_POOLS[i], 0x10);
        OV001_SPRITE_POOLS[i].list = Ov001_ListCreate();
        OV001_SPRITE_POOLS[i].head.start = Ov001_SpriteObjAddr(i, 0x40);
        OV001_SPRITE_POOLS[i].tail.start = Ov001_SpriteObjAddr(i, 0x7f) + 8;
        p = &OV001_SPRITE_POOLS[i];
        Ov001_ListPushFront(p->list, &p->head);
        p = &OV001_SPRITE_POOLS[i];
        Ov001_ListPushBack(p->list, &p->tail);
    }
}

#pragma opt_propagation off
void func_ov001_0218a01c(void) { void func_ov001_0218a6d8(s32); void Ov001_FreeAlloc(void *); void func_ov001_0218bf30(s32); extern s32 gOv001SpritePools; s32 i,offset; i=0;offset=0;do{func_ov001_0218bf30(M2C_FIELD(gOv001SpritePools+offset,s32*,0x220));func_ov001_0218a6d8(M2C_FIELD(gOv001SpritePools+offset,s32*,0x224));i++;offset+=0x228;}while(i<2);Ov001_FreeAlloc(&gOv001SpritePools); }
#pragma opt_propagation reset
void *func_ov001_0218a070(s32 in_idx, s32 in_arg1, s32 in_arg2) {
    s32 Ov001_QueuePop(s32);
    s32 OS_DisableIrqMask(s32);
    void OS_EnableIrqMask(s32);
    void SystemHalt(void);
    void func_ov001_0218bf84(void *, void *);
    extern s32 gOv001SpritePools;
    s32 idx = in_idx;
    s32 arg1 = in_arg1;
    s32 off = idx * 0x228;
    A070Node *node;
    s32 state;
    s32 arg2 = in_arg2;
    A070Node *cur;
    A070Node *next;
    A070Node *prev;
    A070Node *bound;
    A070Node *headBound;
    s32 curEnd;
    s32 need;

    node = (A070Node *)Ov001_QueuePop(*((s32 *)(gOv001SpritePools + off + 0x224)));
    state = OS_DisableIrqMask(1);
    if (arg2 != 0) {
        bound = (A070Node *)(gOv001SpritePools + off + 0x210);
        cur = (A070Node *)(gOv001SpritePools + off + 0x200);
        if (cur != bound) {
            do {
                next = cur->next;
                curEnd = cur->start + cur->size * 8;
                need = curEnd + arg1 * 8;
                if ((u32)need <= (u32)next->start) {
                    node->start = curEnd;
                    func_ov001_0218bf84(next, node);
                    break;
                }
                cur = next;
            } while (next != bound);
        }
        if (cur == bound) {
            SystemHalt();
        }
    } else {
        bound = (A070Node *)(gOv001SpritePools + off + 0x210);
        headBound = (A070Node *)(gOv001SpritePools + off + 0x200);
        cur = bound;
        if (cur != headBound) {
            do {
                prev = cur->prev;
                curEnd = cur->start - arg1 * 8;
                need = prev->start + prev->size * 8;
                if ((u32)curEnd >= (u32)need) {
                    node->start = curEnd;
                    func_ov001_0218bf84(cur, node);
                    break;
                }
                cur = prev;
            } while (prev != headBound);
        }
        if (cur == headBound) {
            SystemHalt();
        }
    }
    OS_EnableIrqMask(state);
    node->size = (u8)arg1;
    return node;
}

void Ov001_DestroySprite(void *arg0) {
    M2C_UNK Ov001_QueuePush(s32, void *);
    M2C_UNK func_ov001_0218bf4c(void *);
    extern s32 gOv001SpritePools;
    u8 *var_r2;
    s32 var_r3;
    s32 var_r4;

    var_r4 = 0;
    var_r3 = 0;
    var_r2 = M2C_FIELD(arg0, u8 **, 8);
    if ((s32) M2C_FIELD(arg0, u8 *, 0xC) > 0) {
        do {
            var_r3 += 1;
            M2C_FIELD(var_r2, s32 *, 0) = (M2C_FIELD(var_r2, s32 *, 0) & 0xC1FFFCFF) | 0x200;
            var_r2 += 8;
        } while (var_r3 < (s32) M2C_FIELD(arg0, u8 *, 0xC));
    }
    func_ov001_0218bf4c(arg0);
    if ((u32) arg0 >= (u32) (gOv001SpritePools + 0x228)) {
        var_r4 = 1;
    }
    Ov001_QueuePush(M2C_FIELD(((var_r4 * 0x228) + gOv001SpritePools), s32 *, 0x224), arg0);
}

s32 Ov001_GetSpriteObjEntry(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 8) + (arg1 * 8);
}

u8 func_ov001_0218a258(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0xC);
}

/* Sets the draw-mode attribute bits of a sprite object's entries: `flags` is the pair
 * of entry attribute bits to write (SPRITE_ENTRY_AFFINE / SPRITE_ENTRY_HIDDEN) and
 * `matrix` the rotation-scaling matrix index, written only into affine entries.
 * Entry `index` alone is changed, or every entry of the object when index is negative. */
void Ov001_SetSpriteEntryFlags(void *obj,s32 index,s32 flags,s32 matrix){
u32 (*entries)[2]=*(u32 (**)[2])((u8 *)obj+8);
u32 value;
if(index>=0){
if(flags!=SPRITE_ENTRY_AFFINE && flags!=SPRITE_ENTRY_AFFINE_DOUBLE){value=entries[index][0]&SPRITE_ENTRY_ATTR_MASK;value|=flags;entries[index][0]=value;}
else{value=entries[index][0]&SPRITE_ENTRY_ATTR_MASK;value|=flags;value|=matrix<<SPRITE_ENTRY_MATRIX_SHIFT;entries[index][0]=value;}
}else{
for(index=0;index<M2C_FIELD(obj,u8 *,12);index++){
if(flags!=SPRITE_ENTRY_AFFINE && flags!=SPRITE_ENTRY_AFFINE_DOUBLE){value=entries[index][0]&SPRITE_ENTRY_ATTR_MASK;value|=flags;}
else {value=entries[index][0]&SPRITE_ENTRY_ATTR_MASK;value|=flags;value|=matrix<<SPRITE_ENTRY_MATRIX_SHIFT;}
entries[index][0]=value;
}
}
}

#pragma push
#pragma opt_strength_reduction off
void Ov001_SetSpriteAttrs(void *obj, s32 index, u32 a, u32 b) {
 u8 *entries=M2C_FIELD(obj,u8**,8);
 s32 i;
 if(index>=0) {
  M2C_FIELD(entries+index*8,u32*,0)=(M2C_FIELD(entries+index*8,u32*,0)&~0xc00U)|(a<<10);
  M2C_FIELD(entries+index*8,u16*,4)=(M2C_FIELD(entries+index*8,u16*,4)&~0xf000U)|(b<<12);
 } else {
  for(i=0;i<M2C_FIELD(obj,u8*,12);i++) {
   M2C_FIELD(entries+i*8,u32*,0)=(M2C_FIELD(entries+i*8,u32*,0)&~0xc00U)|(a<<10);
   M2C_FIELD(entries+i*8,u16*,4)=(M2C_FIELD(entries+i*8,u16*,4)&~0xf000U)|(b<<12);
  }
 }
}
#pragma pop
