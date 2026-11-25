/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"

typedef struct { s32 x; u32 y; } Position;

extern Ov001WirelessSetup gOv001WirelessSetup;

/* Leave the ov001 local-wireless setup screen: step the WH connection task
 * once, and when this screen's connection was accepted, save the room setup
 * packet into the save data.  Finally release the wireless work buffer. */
void Ov001_FinishWirelessSetup(s32 wasConnected) {
    void func_ov001_0216d14c(void);
    void Ov001_SaveRoomSetupPacket(u8 *);
    extern M2C_UNK gOv001WirelessWork;
    func_ov001_0216d14c();
    if (wasConnected != 0) {
        if ((gOv001WirelessSetup.request[OV001_SETUP_STATUS] == 0) && (gOv001WirelessSetup.connected == 1)) {
            Ov001_SaveRoomSetupPacket(gOv001WirelessSetup.request + OV001_SETUP_PACKET);
        }
    }
    Ov001_FreeAlloc(&gOv001WirelessWork);
}

/* One frame of the wireless setup screen's connection attempt: run the setup
 * exchange and report whether the local player's connection was accepted (1),
 * is still pending (0) or has failed (2). */
s32 Ov001_UpdateWirelessSetup(void) {
    s32 func_ov001_0216ad74(void *);
    if (func_ov001_0216ad74(gOv001WirelessSetup.request) == 0) {
        gOv001WirelessSetup.connected = 1;
        return OV001_SETUP_JOINED;
    }
    {
        u8 status = gOv001WirelessSetup.request[OV001_SETUP_STATUS];
        if (status == 1) goto still_pending;
        if ((u8)(status + 0xFD) > 2) goto failed;
    still_pending:
        return OV001_SETUP_PENDING;
    failed:
        return OV001_SETUP_FAILED;
    }
}

void Ov001_AllocWirelessWork(M2C_UNK arg0) {
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    Ov001_Alloc(arg0, 0x20);
}

void Ov001_FreeWirelessWork(void) {
    M2C_UNK Ov001_FreeHeapBlock();
    Ov001_FreeHeapBlock();
}

/* Run the ov001 front end (title and menu screens) on the caller's work buffer
 * `work` for screen mode `mode` with screen options `options`: store them in the
 * screen state, then initialise the core devices, the display and the sound
 * engine, and call the screen step callback once per frame until the exit flag is
 * set.  Returns -1 when the screen mode and options are not valid, 0 after the
 * overlay's shutdown routine has run. */
s32 Ov001_RunFrontEnd(M2C_UNK work, s32 mode, s32 options) {
    void Ov001_InitScreen(void);
    s32 Ov001_InitScreenMode(s32, s32);
    void Ov001_InitCore(void);
    void Ov001_SetupDisplay(void);
    void Ov001_InitSound(void);
    void Ov001_SetStepCallback(s32);
    void Ov001_UpdateInput(void);
    void Ov001_UpdateTaskGroup(s32);
    void Ov001_UpdateLidState(void);
    void Ov001_UpdateArm7Value(void);
    void func_02007598(void);
    void Ov001_ShutdownCore(void);
    extern u8 gOv001ScreenState;

    M2C_FIELD(&gOv001ScreenState, M2C_UNK *, OV001_SCREEN_WORK) = work;
    if (!Ov001_InitScreenMode(mode, options)) return -1;
    M2C_FIELD(&gOv001ScreenState, u8 *, OV001_SCREEN_EXIT) = 0;
    Ov001_InitCore();
    Ov001_SetupDisplay();
    Ov001_InitSound();
    Ov001_SetStepCallback((s32)Ov001_InitScreen);
    do {
        Ov001_UpdateInput();
        M2C_FIELD(&gOv001ScreenState, void (**)(void), OV001_SCREEN_STEP)();
        Ov001_UpdateTaskGroup(0);
        Ov001_UpdateLidState();
        Ov001_UpdateArm7Value();
        func_02007598();
    } while (!M2C_FIELD(&gOv001ScreenState, u8 *, OV001_SCREEN_EXIT));
    Ov001_ShutdownCore();
    return 0;
}

#pragma scheduling off
s32 Ov001_InitScreenMode(s32 arg0,s32 arg1){
extern u8 gOv001ScreenState;
M2C_FIELD(&gOv001ScreenState,u8 *,0)=arg0;
M2C_FIELD(&gOv001ScreenState,s32 *,8)=arg1;
if(arg0<0||arg0>6)return 0;
if(arg0==1){if(((u32)arg1>>4)&~2U)return 0;}
arg1=M2C_FIELD(&gOv001ScreenState,s32 *,8);
{u32 nibble=(u32)(arg1<<28); nibble>>=28; if(nibble>1U)return 0;}
if(arg0!=0){if(((u32)arg1>>4)&1)return 0;}
if(arg0==0){if(!(((u32)M2C_FIELD(&gOv001ScreenState,volatile s32 *,8)>>4)&1))return 0;}
return 1;
}
#pragma scheduling reset
/* Bring overlay 001 up: stop interrupts and the sub display, halt if a core
 * device fails to initialise, reset the display and the vblank IRQ, then
 * initialise the ov001 subsystems (tasks, fades, sound, streaming) and run the
 * save-block initialiser on a temporary 0x700-byte scratch buffer. */
void Ov001_InitCore(void) {
extern u8 gOv001ScreenState;
M2C_UNK GX_TurnOffDisplay(); M2C_UNK IsSystemTickInitialized(); M2C_UNK func_02007180(); M2C_UNK SystemHalt(); void GX_SetVBlankIrq(s32); M2C_UNK func_020022d8(); M2C_UNK InitCardArchiveOnce(); M2C_UNK TP_Init(); M2C_UNK RTC_Init(); M2C_UNK GxReleaseAllBankGrants(); M2C_UNK Ov001_InitExpHeap(); M2C_UNK Ov001_InstallVBlankHandler(); M2C_UNK Ov001_InitTasks(); M2C_UNK func_ov001_02189ad0(); M2C_UNK Ov001_StartInput(); M2C_UNK Ov001_InitFades(); M2C_UNK Ov001_Alloc(M2C_UNK,M2C_UNK); M2C_UNK VerifySaveBlock();
M2C_UNK scratch;
*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=0;
GX_TurnOffDisplay(0);*(volatile u32 *)0x4001000&=~0x10000;
if(!IsSystemTickInitialized())SystemHalt();if(!func_02007180())SystemHalt();GX_SetVBlankIrq(0);func_020022d8();InitCardArchiveOnce(-1);TP_Init();GX_TurnOffDisplay(RTC_Init());*(volatile u32 *)0x4001000&=~0x10000;
GxReleaseAllBankGrants();Ov001_InitExpHeap(M2C_FIELD(&gOv001ScreenState,M2C_UNK *,4));Ov001_InstallVBlankHandler();Ov001_InitTasks();func_ov001_02189ad0();Ov001_StartInput();Ov001_InitFades();scratch=Ov001_Alloc(0x700,0x20);VerifySaveBlock();Ov001_FreeAlloc(&scratch);
}

/* Initialise the display for overlay 001: allocate VRAM banks for the
 * background, reset and configure the background control/scroll registers of
 * both the main and sub engines, set up alpha blending and master brightness,
 * then turn the main display on. */
void Ov001_SetupDisplay(void) {
    void GX_SetVBlankIrq(s32);
    void GX_SetBankForBG(s32);
    void GX_SetBankForOBJ(s32);
    void GX_ConfigureDisplay(s32, s32, s32);
    void GX_SetMasterBrightness(void *, s32);
    void GX_SetBlendControl(s32, s32, s32);
    void GX_SetBankForSubBG(s32);
    void GX_SetBankForSubOBJ(s32);
    void GX_SetSubBgMode(s32);
    void Ov001_CreateTextContext(void);
    void Ov001_InitSpriteObjs(void);
    void Ov001_InitTilePools(void);
    void Ov001_InitSpritePools(void);
    void GX_TurnOnDisplay(void);

    GX_SetVBlankIrq(0);
    GX_SetBankForBG(1);
    GX_SetBankForOBJ(2);
    GX_ConfigureDisplay(1, 0, 0);

    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x1f00);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xe000);
    GX_SetMasterBrightness((void *)0x0400006C, 0);

    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & 0xffcfffef) | 0x10 | 0x200000;
    *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & ~0x40);
    *(volatile u16 *)0x0400000a = (*(volatile u16 *)0x0400000a & ~0x40);
    *(volatile u16 *)0x0400000c = (*(volatile u16 *)0x0400000c & ~0x40);
    *(volatile u16 *)0x0400000e = (*(volatile u16 *)0x0400000e & ~0x40);
    *(volatile u32 *)0x04000010 = 0;
    *(volatile u32 *)0x04000014 = 0;
    *(volatile u32 *)0x04000018 = 0;
    *(volatile u32 *)0x0400001c = 0;
    GX_SetBlendControl(0x04000050, 0x3f, 0x10);
    GX_SetBankForSubBG(0x80);
    GX_SetBankForSubOBJ(0x100);
    GX_SetSubBgMode(0);

    {
        volatile u32 *display = (volatile u32 *)0x04001000;
        u32 value;
        value = *display;
        *display = value & ~0x1f00;
        value = *display;
        *display = value & ~0xe000;
        GX_SetMasterBrightness((u8 *)display + 0x6c, 0);
    }


    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & 0xffcfffef) | 0x10;
    *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & ~0x40);
    *(volatile u16 *)0x0400100a = (*(volatile u16 *)0x0400100a & ~0x40);
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & ~0x40);
    *(volatile u16 *)0x0400100e = (*(volatile u16 *)0x0400100e & ~0x40);
    *(volatile u32 *)0x04001010 = 0;
    *(volatile u32 *)0x04001014 = 0;
    *(volatile u32 *)0x04001018 = 0;
    *(volatile u32 *)0x0400101c = 0;
    GX_SetBlendControl(0x04001050, 0x3f, 0x10);

    *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & 0x43) | 0xc00;
    *(volatile u16 *)0x0400000a = (*(volatile u16 *)0x0400000a & 0x43) | 0x108 | 0xc00;
    *(volatile u16 *)0x0400000c = (*(volatile u16 *)0x0400000c & 0x43) | 0xe10;
    *(volatile u16 *)0x0400000e = (*(volatile u16 *)0x0400000e & 0x43) | 0xf10;
    *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & 0x43) | 0xc00;
    *(volatile u16 *)0x0400100a = (*(volatile u16 *)0x0400100a & 0x43) | 0xd00;
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & 0x43) | 0xe00;
    *(volatile u16 *)0x0400100e = (*(volatile u16 *)0x0400100e & 0x43) | 0xf00;

    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x38000000);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x7000000);
    *(volatile u16 *)0x04000304 = (*(volatile u16 *)0x04000304 & ~0x8000);

    Ov001_CreateTextContext();
    Ov001_InitSpriteObjs();
    Ov001_InitTilePools();
    Ov001_InitSpritePools();
    GX_TurnOnDisplay();

    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 | 0x10000);
    GX_SetVBlankIrq(1);
}

/* Tear down overlay 001, the counterpart of Ov001_InitCore: stop the sub
 * display, the input and the vblank handler, then release the subsystems the
 * overlay brought up (its tasks, sprite and tile pools, fades, sound and
 * streaming) and finally the heap. */
void Ov001_ShutdownCore(void) {
    M2C_UNK GX_TurnOffDisplay();
    M2C_UNK func_ov001_02184ff8();
    M2C_UNK func_ov001_02189c80();
    M2C_UNK func_ov001_0218a01c();
    M2C_UNK Ov001_FreeFades();
    M2C_UNK Ov001_FreeTextContext();
    M2C_UNK func_ov001_0218b688();
    M2C_UNK Ov001_StopInput();
    M2C_UNK Ov001_RemoveVBlankHandler();
    M2C_UNK Ov001_FreeSpriteObjs();
    M2C_UNK func_ov001_0218c4c0();
    M2C_UNK func_ov001_0218c668();
    M2C_UNK Ov001_FreeTasks();
    GX_TurnOffDisplay();
    *(s32 *)0x04001000 &= ~0x10000;
    func_ov001_0218c668();
    Ov001_StopInput();
    Ov001_RemoveVBlankHandler();
    func_ov001_02184ff8();
    func_ov001_0218a01c();
    Ov001_FreeSpriteObjs();
    Ov001_FreeTextContext();
    Ov001_FreeFades();
    func_ov001_02189c80();
    Ov001_FreeTasks();
    func_ov001_0218b688();
    func_ov001_0218c4c0();
}

void Ov001_SetStepCallback(s32 arg0) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0xc) = arg0;
}

void Ov001_SetNextScreenMode(s32 arg0, s32 arg1) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x10) = arg0;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x14) = arg1;
}

void Ov001_GetNextScreenMode(s32 *arg0, s32 *arg1) {
    extern u8 gOv001ScreenState;
    if (arg0 != 0) {
        *arg0 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x10);
    }
    if (arg1 != 0) {
        *arg1 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x14);
    }
}

void Ov001_SetNameEntryMode(s32 arg0, s32 arg1) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x18) = arg0;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x1c) = arg1;
}

void Ov001_GetNameEntryMode(s32 *arg0, s32 *arg1) {
    extern u8 gOv001ScreenState;
    if (arg0 != 0) {
        *arg0 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x18);
    }
    if (arg1 != 0) {
        *arg1 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x1c);
    }
}

u8 Ov001_GetLanguage(void) {
    extern u8 gOv001ScreenState;
    return gOv001ScreenState;
}

s32 Ov001_GetScreenLayout(void) {
    extern u8 gOv001ScreenState;
    typedef struct { u32 a, b; unsigned val : 4; } S;
    return ((S *)&gOv001ScreenState)->val;
}

s32 Ov001_HasOptionFlag(s32 arg0) {
    extern u8 gOv001ScreenState;
    if (arg0 & ((u32)M2C_FIELD(&gOv001ScreenState, s32 *, 8) >> 4)) {
        return 1;
    }
    return 0;
}

void Ov001_RequestScreenExit(void) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, u8 *, 1) = 1;
}

/* The id this console advertises in its download-play data-sharing connect
 * entry: '1' plus the console language, except English without screen option 1
 * ('7') and Korean ('8'). */
s32 Ov001_GetConnectEntryId(void) {
    extern u8 gOv001ScreenState;
    u8 language = gOv001ScreenState;
    if (language == LANGUAGE_KOREAN) {
        return 0x38;
    }
    if (language == LANGUAGE_ENGLISH) {
        if (!(( ((u32)M2C_FIELD(&gOv001ScreenState, s32 *, OV001_SCREEN_OPTIONS)) >> 4) & 2)) {
            return 0x37;
        }
    }
    return (language + 0x31) & 0xFF;
}

/* Allocate the message archive pool and fill its free queue with the pool's eight
 * 12-byte archive records, keeping the queue at the end of the pool. */
void Ov001_InitMessageArchiveQueue(void) {
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_QueueCreateFromRange(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gOv001MessageArchiveFreeList;
    M2C_UNK pool;
    M2C_UNK queue;

    pool = Ov001_Alloc(MESSAGE_ARCHIVE_POOL_SIZE, 0x4);
    gOv001MessageArchiveFreeList = pool;
    queue = Ov001_QueueCreateFromRange(MESSAGE_ARCHIVE_COUNT, pool, MESSAGE_ARCHIVE_SIZE);
    M2C_FIELD((void *)gOv001MessageArchiveFreeList, M2C_UNK *, MESSAGE_POOL_QUEUE) = queue;
}

void Ov001_FreeMessageArchiveQueue(void) {
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK gOv001MessageArchiveFreeList;
    Ov001_FreeAlloc(&gOv001MessageArchiveFreeList);
}

/* Load the message file at `path` and fill one archive record from the pool with
 * it: the file image, the per-message offset table and the base its offsets are
 * relative to, so Ov001_GetMessageText can address the texts. Returns the record;
 * Ov001_ReleaseMessageArchive hands it back. */
M2C_UNK Ov001_LoadMessageArchive(M2C_UNK path) {
    M2C_UNK Ov001_QueuePop(M2C_UNK);
    M2C_UNK Ov001_LoadFile(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gOv001MessageArchiveFreeList;
    M2C_UNK archive;
    M2C_UNK size;
    M2C_UNK file;
    M2C_UNK bank;
    M2C_UNK textOffset;

    archive = Ov001_QueuePop(M2C_FIELD(gOv001MessageArchiveFreeList, M2C_UNK *, MESSAGE_POOL_QUEUE));
    file = Ov001_LoadFile(path, &size, 4);
    bank = file + MESSAGE_FILE_HEADER;
    M2C_FIELD(archive, M2C_UNK *, MESSAGE_ARCHIVE_FILE) = file;
    M2C_FIELD(archive, M2C_UNK *, MESSAGE_ARCHIVE_OFFSETS) = bank + MESSAGE_BANK_OFFSETS_OFF;
    textOffset = M2C_FIELD(bank, M2C_UNK *, MESSAGE_BANK_TEXTS_OFF);
    M2C_FIELD(archive, M2C_UNK *, MESSAGE_ARCHIVE_TEXTS) = bank + textOffset + MESSAGE_BANK_TEXTS_BIAS;
    return archive;
}

/* Release the message archive record `archive` handed out by
 * Ov001_LoadMessageArchive: free its loaded file image and push the record back
 * onto the pool's free queue so the next load can hand it out again. */
void Ov001_ReleaseMessageArchive(M2C_UNK archive) {
    M2C_UNK Ov001_FreeFile(M2C_UNK);
    M2C_UNK Ov001_QueuePush(M2C_UNK, M2C_UNK);
    extern M2C_UNK gOv001MessageArchiveFreeList;

    Ov001_FreeFile(M2C_FIELD((void *)archive, M2C_UNK *, MESSAGE_ARCHIVE_FILE));
    Ov001_QueuePush(M2C_FIELD((void *)gOv001MessageArchiveFreeList, M2C_UNK *, MESSAGE_POOL_QUEUE), archive);
}

s32 Ov001_GetMessageText(M2C_UNK arg0, u32 arg1) {
    void **p = (void **)arg0;
    arg1 = (arg1 << 16) >> 16;
    return ((s32 *)p[0])[(u32)arg1] + (s32)p[1];
}
