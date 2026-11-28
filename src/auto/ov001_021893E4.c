/* 27 functions from 0x021893E4 to 0x0218A384 (ov001), found by ds-decomp. */
#include "common.h"
#include "fs.h"
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
#define PROFILE_LOCAL_BYTE 0xA92 /* u8: id this console advertises in the data-sharing connect entry */
#define PROFILE_SEND_ENTRY 0xAB0 /* void *: the outgoing data-sharing entry being built */
#define PROFILE_BUFFER_SIZE 0x100 /* bytes of each of the state's two cleared buffers (the outgoing entry and the entry area) */
#define PROFILE_LINK_TICKS 0xA94 /* s32: link ticks, a list move every other one */
#define PROFILE_CURSOR_MARK 0x202 /* u16 cursor id pushed to the connected players */
#define PROFILE_ROW_COUNT  0x24   /* rows in a profile list round */
#define PROFILE_ID_ROW     0x10   /* entry id: the row is selected */
#define PROFILE_ID_CONNECT 0xBC   /* entry id: wait for a connection */
#define PROFILE_ID_JOIN    0xBD   /* entry id: the joining player said yes */
/* The ov001 DWC utility state: the archive of
 * "rom:/dwc/utility.bin" and the lock id it takes the card ROM lock with. */
#define UTILITY_LOCK_ID    0xE4   /* u16 OS lock id CARD_LockRom/CARD_UnlockRom take */
#define UTILITY_FILE_QUEUE 0x84   /* s32 ring queue (OV001_QUEUE_*, 0x20 entries) of the file-buffer slots Ov001_LoadFile takes and Ov001_FreeFile returns */
/* One allocated run of 8-byte sprite object entries in a pool: the run's list
 * links, the address of its first entry (+0x08) and its entry count (+0x0C). */
typedef struct Ov001SpriteBlock { struct Ov001SpriteBlock *prev; struct Ov001SpriteBlock *next; s32 start; u8 size; u8 pad[3]; } Ov001SpriteBlock;
/* The ov001 sprite-object pools (gOv001SpritePools): each pool recycles 0x10-byte
 * sprite objects through freeObjs and keeps the blocks it has handed out in an
 * address-ordered list bookended by the head/tail sentinels. */
typedef struct Ov001SpritePool { u8 slots[0x200]; Ov001SpriteBlock head; Ov001SpriteBlock tail; s32 list; s32 freeObjs; } Ov001SpritePool;
#define OV001_SPRITE_POOL_COUNT 2
#define OV001_SPRITE_POOLS ((Ov001SpritePool *)gOv001SpritePools)

/* Advances the download-play (single-card) setup from the multiboot link status:
 * starts the profile transfer, waits for the connected players or drops them when a
 * link test fails, and moves the profile screen state to the matching next step. */
void Ov001_UpdateLinkState(void) {
    s32 Ov001_GetLinkStatus(void);
    s32 Ov001_GetLinkInfo(s32);
    void Ov001_StartMultibootProgramTransfer(M2C_UNK, M2C_UNK);
    s32 Ov001_AreJoinedPlayersReady(void);
    void func_ov001_02187454(void);
    void Ov001_CloseFailedLink(void);
    s32 Ov001_GetWhStatus(void);
    s32 Ov001_EndLink(void);
    extern void *gOv001ProfileState;

    s32 status = Ov001_GetLinkStatus();
    switch (status) {
    case 1: {
        void *state = gOv001ProfileState;
        Ov001_StartMultibootProgramTransfer((u8 *)state + PROFILE_FILE,
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
        s32 ready = Ov001_AreJoinedPlayersReady();
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
        Ov001_CloseFailedLink();
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 0x1;
        return;
    }
    case 0: {
        switch(Ov001_GetWhStatus()){
        case 1:Ov001_EndLink();return;
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

/* Profile setup state 7: reset the profile-sharing buffers, install the
 * child-indicate callback that collects the children's profile entries, and move
 * on to the profile list states (8..10). */
void Ov001_EnterProfileListSharing(void) {
    M2C_UNK Ov001_InitProfileSharing(void);
    void Ov001_SetChildIndicateCallback(s32);
    extern s32 Ov001_StoreLinkPlayerRecord(s32);
    extern void *gOv001ProfileState;

    Ov001_InitProfileSharing();
    Ov001_SetChildIndicateCallback((s32) &Ov001_StoreLinkPlayerRecord);
    M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 8;
}

/* Updates the profile / download-play setup screen while it is in one of its list states: it
 * feeds the profile entries to the underlying multiboot task and, when the list has settled,
 * turns the current input code into the next screen state. */
void Ov001_UpdateProfileTask(void) {
    s32 Ov001_GetWhStatus(void);
    void func_ov001_021888a8(s32, u16, u16, s32);
    void Ov001_StepProfileSharing(s32, s32, void *);
    void Ov001_UpdateProfileLink(void);
    u16 Ov001_ReadInputCode(void);
    extern void *gOv001ProfileState;

    s32 step = Ov001_GetWhStatus();
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
        Ov001_StepProfileSharing(0, row, entry);
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

/* Profile setup state 11: the profile has been obtained, so move the screen on
 * to the state whose handler saves it and reports the result. */
void Ov001_EnterProfileObtained(void) {
    extern void *gOv001ProfileState;
    M2C_FIELD(gOv001ProfileState, s8 *, PROFILE_STATE) = 0xC;
}

/* Finish the download-play link teardown: when the multiboot task is running
 * (step 1), end the link and return to the initial setup state so the exit
 * result is processed; otherwise do nothing and report 0. */
s32 Ov001_FinishLinkTeardown(void) {
    s32 Ov001_GetWhStatus(void);
    s32 Ov001_EndLink(void);
    extern void *gOv001ProfileState;

    if (Ov001_GetWhStatus() != 1) {
        return 0;
    }
    Ov001_EndLink();
    M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 1;
    return 1;
}

/* WH data-sharing callback: look up the connected link player whose six-byte
 * link address sits at +0xA of `userInfo` and remember that player's link record
 * in the profile block's per-player pointer table (0xAA0 + (player - 1) * 4).
 * Returns 0 when no connected player matches. */
s32 Ov001_StoreLinkPlayerRecord(s32 userInfo) {
    s32 Ov001_FindLinkPlayerByAddress(s32);
    s32 Ov001_GetLinkPlayerRecord(s32);
    extern void *gOv001ProfileState;
    s32 player;

    player = Ov001_FindLinkPlayerByAddress(userInfo + 0xA);
    if (player == 0) {
        return 0;
    }
    M2C_FIELD((u8 *) gOv001ProfileState + (player - 1) * 4, s32 *, 0xAA0) = Ov001_GetLinkPlayerRecord(player);
    return 1;
}

/* Reset the profile-sharing state: clear the outgoing entry and the received-entry
 * area, then point the outgoing entry at the state's own first buffer. */
M2C_UNK Ov001_InitProfileSharing(void) {
 extern void *gOv001ProfileState; void MI_CpuFill8(void*,s32,s32); void *state;
 MI_CpuFill8((u8*)gOv001ProfileState+PROFILE_ENTRY_BASE,0,PROFILE_BUFFER_SIZE);
 MI_CpuFill8(gOv001ProfileState,0,PROFILE_BUFFER_SIZE);
 state=gOv001ProfileState;
 M2C_FIELD(state,void**,PROFILE_SEND_ENTRY)=state;
 return (s32)state;
}

/* One step of the download-play profile data sharing: while the link is up send
 * the selected profile entry (id, row, 0x40-byte payload) to the children, else
 * count frames and advertise this console's connect id; once the exchange step
 * reports progress, collect the children's entries into this console's two profile
 * slots, or leave the list when not both children replied. */
void Ov001_StepProfileSharing(s32 entryId, s32 row, void *entry) {
    M2C_UNK Ov001_GetWhStatus(void);
    M2C_UNK DWCi_MOV_WH_StepDataSharing(void *);
    M2C_UNK Ov001_GetConnectedChildren(void);
    M2C_UNK Ov001_GetPlayerData(s32);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void *gOv001ProfileState;
    u16 i;

    if (M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_LINKED) == 1) {
        *(u16 *)M2C_FIELD(gOv001ProfileState, void **, PROFILE_SEND_ENTRY) = (u16)entryId;
        *(u16 *)((u8 *)M2C_FIELD(gOv001ProfileState, void **, PROFILE_SEND_ENTRY) + 2) = (u16)row;
        MI_CpuCopy8(entry, (u8 *)M2C_FIELD(gOv001ProfileState, void **, PROFILE_SEND_ENTRY) + 4, 0x40);
    } else {
        M2C_FIELD(gOv001ProfileState, u32 *, PROFILE_LIST_TIMER) += 1;
        *(u16 *)M2C_FIELD(gOv001ProfileState, void **, PROFILE_SEND_ENTRY) = PROFILE_ID_CONNECT;
        ((u8 *)M2C_FIELD(gOv001ProfileState, void **, PROFILE_SEND_ENTRY))[4] = M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_LOCAL_BYTE);
    }

    if (Ov001_GetWhStatus() != 5) {
        return;
    }
    if (DWCi_MOV_WH_StepDataSharing(gOv001ProfileState) == 0) {
        M2C_FIELD(gOv001ProfileState, u32 *, PROFILE_LIST_TIMER) += 4;
        return;
    }
    if (M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_LINKED) == 0) {
        M2C_FIELD(gOv001ProfileState, u32 *, PROFILE_LIST_TIMER) += 1;
    } else {
        M2C_FIELD(gOv001ProfileState, u32 *, PROFILE_LIST_TIMER) = 0;
        if (Ov001_GetConnectedChildren() != 3) {
            M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 0x1b;
            return;
        }
    }

    for (i = 0; i < 2; i = (u16)(i + 1)) {
        void *src = Ov001_GetPlayerData(i);
        if (src != 0) {
            MI_CpuCopy8(src, (u8 *)gOv001ProfileState + PROFILE_ENTRY_BASE + i * PROFILE_ENTRY_SIZE, PROFILE_ENTRY_SIZE);
            M2C_FIELD((u8 *)gOv001ProfileState + i * 4, s32 *, PROFILE_ENTRY_VALID) = 1;
        } else {
            M2C_FIELD((u8 *)gOv001ProfileState + i * 4, s32 *, PROFILE_ENTRY_VALID) = 0;
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
/* Reads the command the other console sent in its profile entry: the id word at
 * the start of the second received entry, right after the first 0x44-byte one. */
u16 Ov001_ReadInputCode(void) {
    extern void *gOv001ProfileState;
    u8 *state = gOv001ProfileState;
    return M2C_FIELD(state + PROFILE_ENTRY_BASE, u16 *, PROFILE_ENTRY_SIZE);
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
    void InitArchive(void *);
    s32 RegisterArchiveName(void *, void *, s32);
    void SetArchiveCallback(void *, s32, s32);
    s32 ConfigureArchiveLayout(void *, s32, s32, s32, s32, s32, void *, void *);
    s32 LoadArchiveIndex(void *, s32, s32);
    s32 Ov001_QueueCreateFromRange(s32, s32, s32);
    void StringFormatUnbounded(void *, void *, ...);
    void SetFileDirectory(void *);
    extern void *gOv001UtilityState;
    extern char data_ov001_02191794[];
    extern char data_ov001_0218fd04[];
    extern char data_ov001_021917ac[];
    s32 Ov001_UtilityArchiveCommand(s32, s32);
    s32 Ov001_UtilityArchiveRead(void *, M2C_UNK, s32,s32);
    s32 func_ov001_02189dc0(void);

    u8 request[0x48];
    u8 dirName[0x80];
    u32 hi[2],lo[2];
    s32 fileSize;
    void *data;
    s32 dataSize;

    gOv001UtilityState = (void *)Ov001_Alloc(0xE8, 4);
    InitFileRequest(request);
    if (!OpenFileRequest(request, data_ov001_02191794)) {
        SystemHalt();
    }
    M2C_FIELD(gOv001UtilityState, u16 *, 0xE4) = (u16)OS_GetLockID();
    fileSize = *(s32 *)(request + 0x24);
    FileRead(request, hi, 8);
    FileRead(request, lo, 8);
    CloseFileRequest(request);
    InitArchive((u8 *)gOv001UtilityState + 0x88);
    if (!RegisterArchiveName((u8 *)gOv001UtilityState + 0x88, data_ov001_0218fd04, 3)) {
        SystemHalt();
    }
    SetArchiveCallback((u8 *)gOv001UtilityState + 0x88, (s32)Ov001_UtilityArchiveCommand, 0x602);
    if (!ConfigureArchiveLayout((u8 *)gOv001UtilityState + 0x88, fileSize, lo[0], lo[1], hi[0], hi[1], (void *)Ov001_UtilityArchiveRead, (void *)func_ov001_02189dc0)) {
        SystemHalt();
    }
    dataSize = LoadArchiveIndex((u8 *)gOv001UtilityState + 0x88, 0, 0);
    data = (void *)Ov001_Alloc(dataSize, 4);
    *(void **)gOv001UtilityState = data;
    LoadArchiveIndex((u8 *)gOv001UtilityState + 0x88, (s32)*(void **)gOv001UtilityState, dataSize);
    M2C_FIELD(gOv001UtilityState, s32 *, 0x84) = (s32)Ov001_QueueCreateFromRange(0x20, (s32)((u8 *)gOv001UtilityState + 4), 4);
    StringFormatUnbounded(dirName, data_ov001_021917ac, data_ov001_0218fd04);
    SetFileDirectory(dirName);
}

void func_ov001_02189c80(void) {
extern void *data_ov001_021917b4[2];
extern void *data_ov001_02193e2c;
void func_0200bc5c(void *);
void func_0200b510(void *);
void CloseArchiveFile(void *);
void func_0200b238(void *);
void func_020055f4(u16);
void func_ov001_0218b71c(void *);
func_0200bc5c(data_ov001_021917b4);
func_0200b510((u8 *)data_ov001_02193e2c+0x88);
CloseArchiveFile((u8 *)data_ov001_02193e2c+0x88);
func_0200b238((u8 *)data_ov001_02193e2c+0x88);
func_020055f4(M2C_FIELD(data_ov001_02193e2c,u16 *,0xe4));
M2C_FIELD(data_ov001_02193e2c,u16 *,0xe4)=0;
func_ov001_0218b71c(data_ov001_02193e2c);
M2C_FIELD(data_ov001_02193e2c,u32 *,0)=0;
func_ov001_0218b71c((void *)0x02193e2c);
}

/* Card-archive command callback of the ov001 DWC utility archive: locks the card
 * ROM while a transfer request is in flight and unlocks it when the archive goes
 * idle; its own event 1 is acknowledged as handled (4) and any other command
 * returns 8 to the generic file command handler. */
s32 Ov001_UtilityArchiveCommand(s32 request, s32 command) {
    void CARD_LockRom(u16);
    void CARD_UnlockRom(u16);
    extern void *gOv001UtilityState;

    switch (command) {
    case FS_EVENT_REQUEST:
        CARD_LockRom(M2C_FIELD(gOv001UtilityState, u16 *, UTILITY_LOCK_ID));
        return 0;
    case FS_EVENT_IDLE:
        CARD_UnlockRom(M2C_FIELD(gOv001UtilityState, u16 *, UTILITY_LOCK_ID));
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}

void Ov001_UtilityArchiveReadDone(M2C_UNK arg0);

/* The ov001 utility archive's read procedure: start an asynchronous card read of
 * `length` bytes from `offset`, relative to the archive image, into `buffer`, and
 * report the request as still in progress (6) until the done callback runs. */
s32 Ov001_UtilityArchiveRead(void *archive, s32 buffer, s32 offset, s32 length) {
    void StartCardArchiveRead(s32, s32, s32, s32, s32, void *, s32);
    StartCardArchiveRead(-1, offset + M2C_FIELD(archive, s32 *, 0x28), buffer, length, (s32)Ov001_UtilityArchiveReadDone, archive, 1);
    return 6;
}

/* Completion callback of an ov001 utility-archive read: report the transfer as
 * successful to the file's operation completion. */
void Ov001_UtilityArchiveReadDone(M2C_UNK file) {
    M2C_UNK FileOperationCompleted(M2C_UNK, M2C_UNK);
    FileOperationCompleted(file, 0);
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
extern void *gOv001UtilityState;
extern s32 gOv001CompressedFileSuffix;
void *raw;
u32 request[18];
u32 size;
s32 align;
void *out;
Ov001_QueuePop(M2C_FIELD(gOv001UtilityState, s32 *, 0x84));
InitFileRequest(request); if (!OpenFileRequest(request, path)) SystemHalt();
size = request[10] - request[9]; if (outSize) *outSize = size;
if (Ov001_FileHasSuffix(path, (s32)&gOv001CompressedFileSuffix, 2)) align = -4; else align = alignment;
raw = (void *)Ov001_Alloc(size, align);
FileRead(request, raw, size); CloseFileRequest(request);
if (align > 0) return raw;
size = *(u32 *)raw >> 8; if (outSize) *outSize = size;
out = (void *)Ov001_Alloc(size, alignment); Ov001_DecompressBuffer(raw, out); Ov001_FreeAlloc(&raw); return out;
}

/* Release a file buffer handed out by Ov001_LoadFile: free the block on the ov001
 * heap (which clears the pointer) and return its slot to the utility state's file
 * ring queue.  Declared variadic, as the original is, to keep its stack frame. */
void Ov001_FreeFile(s32 block, ...) {
    M2C_UNK Ov001_QueuePush(s32, void *);
    void Ov001_FreeAlloc(void *);
    extern void *gOv001UtilityState;

    Ov001_FreeAlloc(&block);
    Ov001_QueuePush(M2C_FIELD(gOv001UtilityState, s32 *, UTILITY_FILE_QUEUE), (void *)block);
}

/* Returns nonzero when the string `name` ends in the last `suffixLen` bytes of
 * `suffix` (both strings must be at least that long): the two tails are compared
 * byte for byte.  Used to spot the ".l" compressed-file suffix. */
s32 Ov001_FileHasSuffix(void *name, s32 suffix, s32 suffixLen) {
    s32 StringLength(void *);
    s32 ByteCompareN(void *, void *, s32);
    s32 nameLen;
    s32 suffixLength;

    nameLen = StringLength(name);
    suffixLength = StringLength(suffix);
    if (nameLen < suffixLen || suffixLength < suffixLen) {
        return 0;
    }
    if (ByteCompareN(name + (nameLen - suffixLen), suffix + (suffixLength - suffixLen), suffixLen) == 0) {
        return 1;
    }
    return 0;
}

/* Initializes the two ov001 sprite-object pools: allocates the pool array and,
 * for each pool, wires up its free-object queue and its allocation list, seeding
 * the list with the head and tail sentinels that bound the pool's 0x200-byte
 * block region in the sprite arena. */
void Ov001_InitSpritePools(void) {
    s32 Ov001_QueueCreateFromRange(s32, s32, s32);
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
        OV001_SPRITE_POOLS[i].freeObjs = Ov001_QueueCreateFromRange(0x20, (s32)&OV001_SPRITE_POOLS[i], 0x10);
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
void func_ov001_0218a01c(void) { void Ov001_QueueDestroy(s32); void Ov001_FreeAlloc(void *); void Ov001_ListDestroy(s32); extern s32 gOv001SpritePools; s32 i,offset; i=0;offset=0;do{Ov001_ListDestroy(M2C_FIELD(gOv001SpritePools+offset,s32*,0x220));Ov001_QueueDestroy(M2C_FIELD(gOv001SpritePools+offset,s32*,0x224));i++;offset+=0x228;}while(i<2);Ov001_FreeAlloc(&gOv001SpritePools); }
#pragma opt_propagation reset
/* Give a free sprite object of pool `pool` the first run of `size` 8-byte entry
 * slots that fits in its arena, searching from the low addresses when `fromHead`
 * is set and from the high ones otherwise; the object is linked into the pool's
 * address-ordered list.  A run that fits nowhere aborts the program.  Returns
 * the object, ready for its layout to be loaded. */
void *Ov001_AllocSpriteBlock(s32 pool, s32 size, s32 fromHead) {
    s32 Ov001_QueuePop(s32);
    s32 OS_DisableIrqMask(s32);
    void OS_EnableIrqMask(s32);
    void SystemHalt(void);
    void Ov001_ListInsertBefore(void *, void *);
    extern s32 gOv001SpritePools;

    Ov001SpriteBlock *block;
    Ov001SpriteBlock *cursor;
    s32 irqMask;

    block = (Ov001SpriteBlock *)Ov001_QueuePop(OV001_SPRITE_POOLS[pool].freeObjs);
    irqMask = OS_DisableIrqMask(1);
    if (fromHead) {
        cursor = &OV001_SPRITE_POOLS[pool].head;
        while (cursor != &OV001_SPRITE_POOLS[pool].tail) {
            Ov001SpriteBlock *next = cursor->next;
            u32 start = cursor->start + cursor->size * 8;
            if (start + size * 8 <= (u32)next->start) {
                block->start = start;
                Ov001_ListInsertBefore(next, block);
                break;
            }
            cursor = next;
        }
        if (cursor == &OV001_SPRITE_POOLS[pool].tail) {
            SystemHalt();
        }
    } else {
        cursor = &OV001_SPRITE_POOLS[pool].tail;
        while (cursor != &OV001_SPRITE_POOLS[pool].head) {
            Ov001SpriteBlock *prev = cursor->prev;
            u32 start = cursor->start - size * 8;
            if (start >= (u32)(prev->start + prev->size * 8)) {
                block->start = start;
                Ov001_ListInsertBefore(cursor, block);
                break;
            }
            cursor = prev;
        }
        if (cursor == &OV001_SPRITE_POOLS[pool].head) {
            SystemHalt();
        }
    }
    OS_EnableIrqMask(irqMask);
    block->size = size;
    return block;
}

/* Hides every OAM entry of a sprite-object block, unlinks the block from its
 * sprite pool's allocation list and returns it to that pool's queue of free
 * objects. */
void Ov001_DestroySprite(Ov001SpriteBlock *block) {
    s32 Ov001_QueuePush(s32, void *);
    void Ov001_ListRemove(void *);
    extern s32 gOv001SpritePools;
    u8 *entry;
    s32 i;
    s32 pool;

    pool = 0;
    i = 0;
    entry = (u8 *)block->start;
    if ((s32)block->size > 0) {
        do {
            i += 1;
            M2C_FIELD(entry, u32 *, 0) = (M2C_FIELD(entry, u32 *, 0) & SPRITE_ENTRY_ATTR_MASK) | SPRITE_ENTRY_HIDDEN;
            entry += 8;
        } while (i < (s32)block->size);
    }
    Ov001_ListRemove(block);
    if ((u32)block >= (u32)&OV001_SPRITE_POOLS[1]) {
        pool = 1;
    }
    Ov001_QueuePush(M2C_FIELD((pool * 0x228) + gOv001SpritePools, s32 *, 0x224), block);
}

s32 Ov001_GetSpriteObjEntry(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 8) + (arg1 * 8);
}

u8 Ov001_GetSpriteEntryCount(void *arg0) {
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
/* Set the OAM draw mode and palette bank of a sprite object's entries: entry
 * `index` alone when it is not negative, otherwise every entry of the object. */
void Ov001_SetSpriteAttrs(void *obj, s32 index, u32 objMode, u32 palette) {
 u8 *entries=M2C_FIELD(obj,u8**,8);
 s32 i;
 if(index>=0) {
  M2C_FIELD(entries+index*8,u32*,0)=(M2C_FIELD(entries+index*8,u32*,0)&~SPRITE_ENTRY_OBJ_MODE_MASK)|(objMode<<SPRITE_ENTRY_OBJ_MODE_SHIFT);
  M2C_FIELD(entries+index*8,u16*,4)=(M2C_FIELD(entries+index*8,u16*,4)&~SPRITE_ENTRY_PALETTE_MASK)|(palette<<SPRITE_ENTRY_PALETTE_SHIFT);
 } else {
  for(i=0;i<M2C_FIELD(obj,u8*,12);i++) {
   M2C_FIELD(entries+i*8,u32*,0)=(M2C_FIELD(entries+i*8,u32*,0)&~SPRITE_ENTRY_OBJ_MODE_MASK)|(objMode<<SPRITE_ENTRY_OBJ_MODE_SHIFT);
   M2C_FIELD(entries+i*8,u16*,4)=(M2C_FIELD(entries+i*8,u16*,4)&~SPRITE_ENTRY_PALETTE_MASK)|(palette<<SPRITE_ENTRY_PALETTE_SHIFT);
  }
 }
}
#pragma pop
