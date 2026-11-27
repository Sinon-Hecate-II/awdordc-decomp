/* 62 functions from 0x02081400 to 0x02082340 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "gx.h"

typedef struct DS3DSpritePreset {
    u8 mode;
    u8 mainScreenEnabled;
    u8 firstLayer : 4;
    u8 secondLayer : 4;
    u8 mainScreenLayer;
} DS3DSpritePreset;

typedef struct DS3DSpritePresetFlags {
    u16 mode : 3;
    u16 reserved : 9;
    u16 firstLayer : 1;
    u16 secondLayer : 2;
    u16 reservedTop : 1;
} DS3DSpritePresetFlags;

typedef struct DS3DSpritePresetFlagRef {
    DS3DSpritePresetFlags *flags;
} DS3DSpritePresetFlagRef;

/* Load the file at `path` and copy its first `size` bytes into the main OBJ
 * extended palette at byte `offset`, then free the loaded buffer. */
void LoadFileToObjExtPalette(s32 path, s32 paletteOffset, s32 size) {
    M2C_UNK CopyMainOBJExtPalette(s32, s32, s32);
    s32 data;

    data = LoadFileToBuffer(path, 0);
    DC_FlushRange(data, size);
    CopyMainOBJExtPalette(data, paletteOffset, size);
    HeapFreeBlock(data);
}

/* Load the file at `path`, flush it, and queue a copy of its first `size` bytes
 * into the main OBJ extended palette at byte `paletteOffset`; the loaded buffer
 * is freed once the queued copy has run. */
void QueueFileToObjExtPalette(s32 path, s32 paletteOffset, s32 size) {
    M2C_UNK DC_FlushRange(s32, M2C_UNK);
    M2C_UNK QueueMainOBJExtPaletteCopy(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 LoadFileToBuffer(M2C_UNK, M2C_UNK);
    s32 data;

    data = LoadFileToBuffer(path, 0);
    DC_FlushRange(data, size);
    QueueMainOBJExtPaletteCopy(data, paletteOffset, size, 1);
}

void LoadFileAndDrawTilemapBlock(M2C_UNK path, M2C_UNK tilemap, M2C_UNK tileOffset, M2C_UNK palette) {
    M2C_UNK DrawTilemapBlock(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 fileBuffer;

    /* Load the raw tilemap block, draw it into the destination tilemap, and release the temporary buffer. */
    fileBuffer = LoadFileToBuffer(path, 0);
    DrawTilemapBlock(fileBuffer, tilemap, tileOffset, palette);
    HeapFreeBlock(fileBuffer);
}

/* Load the decompressed file at `path` into a buffer and draw it as a tile block
 * into `tilemap`, using `tileBase` and `palette`, then free the buffer. */
void LoadDecompressedFileAndDrawTilemapBlock(s32 path, M2C_UNK tilemap, M2C_UNK tileBase, M2C_UNK palette) {
    s32 data;

    data = LoadDecompressedFile(path, 0);
    DrawTilemapBlock(data, tilemap, tileBase, palette);
    HeapFreeBlock(data);
}

/* Open the NARC archive at `path`: load the archive file into the shared buffer
 * and initialise the archive handle under the name "ARC".  Returns 1 when the
 * archive is open, 0 when it could not be. */
u8 OpenNarcArchive(M2C_UNK path) {
    s32 InitNarcArchive(M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK gNarcArchiveName;
    extern s32 gNarcFileData;
    extern M2C_UNK gNarcArchive;
    u8 opened;
    gNarcFileData = LoadFileToBuffer(path, 0);
    if (InitNarcArchive(&gNarcArchive, &gNarcArchiveName, gNarcFileData) != 0) {
        opened = 1;
    } else {
        opened = 0;
    }
    return opened;
}

/* Close the NARC archive opened by OpenNarcArchive: release the archive handle
 * and free the image buffer it was loaded into.  Does nothing when there is no
 * open archive. */
void CloseNarcArchive(void) {
    M2C_UNK CloseArchive(M2C_UNK *);
    extern s32 gNarcFileData;
    extern M2C_UNK gNarcArchive;

    if (gNarcFileData == 0) {
        return;
    }
    CloseArchive(&gNarcArchive);
    HeapFreeBlock(gNarcFileData);
    gNarcFileData = 0;
}

void func_02081568(void) {
    M2C_UNK GetFileSize();
    M2C_UNK BuildNarcPath();
    BuildNarcPath();
    GetFileSize();
}

/* Load the NARC member at `memberPath` into `dest` and return the number of bytes
 * loaded (0 after halting the system when the member cannot be read). */
s32 LoadNarcFileRaw(void *memberPath, void *dest) {
    return LoadFileToAddress(BuildNarcPath(memberPath), dest);
}

/* Decompress the NARC member at `memberPath` into `dest` and return what
 * LoadDecompressedFileTo returns (the decompressed size, or 0 when it fails). */
s32 LoadNarcFileDecompressed(void *memberPath, void *dest) {
    return LoadDecompressedFileTo(BuildNarcPath(memberPath), dest);
}

/* Decompress the NARC member at `memberPath` into a newly allocated persistent
 * buffer and return it. */
s32 LoadNarcMemberToBuffer(void *memberPath) {
    s32 BuildNarcPath(M2C_UNK);
    s32 LoadDecompressedFile(s32, M2C_UNK);
    return LoadDecompressedFile(BuildNarcPath((M2C_UNK)memberPath), 1);
}

/* Allocate `size` bytes and load the NARC member at `memberPath` into them,
 * returning the buffer (0 when the member cannot be read). */
s32 LoadNarcFileToNewBuffer(void *memberPath, void *size) {
    return LoadFileToNewBuffer(BuildNarcPath(memberPath), size);
}

/* Copy `size` bytes at `offset` of the NARC member `memberPath` into `dest`.
 * Returns what ReadFileSection returns: 0 after halting the system when the
 * member cannot be read, 1 on success. */
void LoadNarcFileSection(M2C_UNK memberPath, M2C_UNK dest, M2C_UNK offset, M2C_UNK size) {
    s32 BuildNarcPath(M2C_UNK);
    void ReadFileSection(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    ReadFileSection(BuildNarcPath(memberPath), dest, offset, size);
}

/* Load the NARC member at `memberPath` into the 3D sprite engine's palette
 * buffer at byte `paletteOffset`, `size` bytes long. */
void LoadNarcFileToSpriteBuffer(M2C_UNK memberPath, M2C_UNK paletteOffset, M2C_UNK size) {
    s32 BuildNarcPath(M2C_UNK);
    M2C_UNK LoadFileToSpriteBuffer(s32, M2C_UNK, M2C_UNK);
    LoadFileToSpriteBuffer(BuildNarcPath(memberPath), paletteOffset, size);
}

/* Load the NARC member at `memberPath` into the main or sub engine's BG extended
 * palette (`paletteSlot`), at byte `offset`, `size` bytes long. */
void LoadNarcFileToBGExtPltt(M2C_UNK memberPath, M2C_UNK paletteSlot, M2C_UNK offset, M2C_UNK size) {
    s32 BuildNarcPath(M2C_UNK);
    void LoadFileToBGExtPltt(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    LoadFileToBGExtPltt(BuildNarcPath(memberPath), paletteSlot, offset, size);
}

/* Queue a copy of the NARC member at `memberPath` into the main or sub engine's
 * BG extended palette (`paletteSlot`) at byte `offset`, `size` bytes long; the copy
 * runs on the next palette upload. */
void QueueNarcFileToBGExtPltt(M2C_UNK memberPath, M2C_UNK paletteSlot, M2C_UNK offset, M2C_UNK size) {
    s32 BuildNarcPath(M2C_UNK);
    void QueueFileToBGExtPltt(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    QueueFileToBGExtPltt(BuildNarcPath(memberPath), paletteSlot, offset, size);
}

/* Load the NARC member at `memberPath` into the main OBJ extended palette at
 * byte `paletteOffset`, `size` bytes long. */
void LoadNarcFileToObjExtPalette(M2C_UNK memberPath, M2C_UNK paletteOffset, M2C_UNK size) {
    s32 BuildNarcPath(M2C_UNK);
    void LoadFileToObjExtPalette(M2C_UNK, M2C_UNK, M2C_UNK);
    LoadFileToObjExtPalette(BuildNarcPath(memberPath), paletteOffset, size);
}

/* Decompress the NARC member at `memberPath` and upload it into the texture bank
 * at `destOffset`; returns the decompressed size in bytes. */
s32 LoadNarcFileToTextureBank(void *memberPath, void *destOffset) {
    return LoadFileToTextureBank(BuildNarcPath(memberPath), destOffset);
}

/* Load the NARC member at `memberPath` and draw it as a tile block into
 * `tilemap` at tile `tileOffset` with `palette`. */
void LoadNarcFileAndDrawTilemapBlock(M2C_UNK memberPath, M2C_UNK tilemap, M2C_UNK tileOffset, M2C_UNK palette) {
    s32 BuildNarcPath(M2C_UNK);
    void LoadFileAndDrawTilemapBlock(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    LoadFileAndDrawTilemapBlock(BuildNarcPath(memberPath), tilemap, tileOffset, palette);
}

/* Load the decompressed NARC member at `memberPath` and draw it as a tilemap
 * block into `tilemap`, using `tileBase` and `palette`. */
void LoadNarcFileDecompressedAndDrawTilemapBlock(M2C_UNK memberPath, M2C_UNK tilemap, M2C_UNK tileBase, M2C_UNK palette) {
    s32 BuildNarcPath(M2C_UNK);
    void LoadDecompressedFileAndDrawTilemapBlock(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    LoadDecompressedFileAndDrawTilemapBlock(BuildNarcPath(memberPath), tilemap, tileBase, palette);
}

/* Build a NARC member path in the shared 64-byte path buffer: the "ARC:/" archive
 * prefix followed by `memberPath`.  Returns the buffer. */
s32 BuildNarcPath(M2C_UNK memberPath) {
    M2C_UNK StringCopy(M2C_UNK *, M2C_UNK *);
    M2C_UNK StringAppend(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gNarcPathPrefix;
    extern M2C_UNK gNarcPathBuffer;
    StringCopy(&gNarcPathBuffer, &gNarcPathPrefix);
    StringAppend(&gNarcPathBuffer, memberPath);
    return (s32)&gNarcPathBuffer;
}

/* Clear the key and touch input state at startup: zero every key mask, seed the
 * two-frames-ago mask so releasing Start/Select/L/R is detected, restore the
 * auto-repeat delays, and clear the input-block counters and flags. */
void ResetKeyState(void) {
    extern M2C_UNK gKeyState;
    extern M2C_UNK gInputBlockState;

    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->prevHeld = 0;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->held = 0;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->pressed = 0;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeat = 0;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeat2 = 0;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->prevHeld2 = KEY_L | KEY_R | KEY_START | KEY_SELECT;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeatDelay = 16;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeatRate = 10;
    M2C_FIELD(&gInputBlockState, u8 *, 4) = 0;
    M2C_FIELD(&gInputBlockState, u8 *, 0) = 0;
    M2C_FIELD(&gInputBlockState, u8 *, 2) = 0;
    M2C_FIELD(&gInputBlockState, u8 *, 3) = 0;
    M2C_FIELD(&gInputBlockState, u8 *, 1) = 0;
}

/* Soft reset (L+R+START+SELECT): turn both displays off, flush and synchronise
 * the data cache, then reset the system, passing on the reset parameter so the
 * boot code can tell this boot came from a reset. */
void RebootConsole(void) {
    M2C_UNK GX_TurnOffDisplay();
    M2C_UNK DC_FlushAll();
    M2C_UNK DC_Sync();
    M2C_UNK ResetSystem(s32);

    GX_TurnOffDisplay();
    REG_DISPCNT_SUB &= ~DISPCNT_DISPLAY_MODE_GRAPHICS;
    DC_FlushAll();
    DC_Sync();
    ResetSystem(*(s32 *)SHARED_RESET_PARAMETER + 1);
}

/* Soft reset: reboot the console when L+R+START+SELECT is held, was not
 * already held two frames ago, is freshly pressed, input is not locked and
 * the game is not in a link or Wi-Fi session. */
void CheckSoftResetCombo(void) {
    extern M2C_UNK gKeyState;
    extern M2C_UNK gInputBlockState;
    s32 IsSoftResetAllowed(void);
    u16 held = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);

    if (held != KEY_RESET_COMBO) return;
    if (held == M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 10)) return;
    if (!(M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 0) & KEY_RESET_COMBO)) return;
    if (M2C_FIELD(&gInputBlockState, s8 *, 4) <= 0 && M2C_FIELD(&gInputBlockState, s8 *, 0) <= 0) {
        if (M2C_FIELD(&gInputBlockState, u8 *, 1) != 0) return;
        if (IsSoftResetAllowed() == 0) return;
        RebootConsole();
    }
}

void func_0208184c(void) {
    extern M2C_UNK gKeyState;
    extern M2C_UNK gInputBlockState;
    void CheckSoftResetCombo(void);
    u16 v, a, b;
    s32 v6, v8;
    u32 tmp;

    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 8) =
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);

    if (M2C_FIELD(&gInputBlockState, u8 *, 1) != 0) {
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6) = 0;
    } else {
        tmp = *(u16 *)0x4000130 | *(u16 *)0x027fffa8;
        tmp = (tmp ^ 0x2fff) & 0x2fff;
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6) = (u16)tmp;
    }

    v = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);
    if (v & 0x20) {
        if (v & 0x10) {
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6) = v & ~0x30;
        }
    }

    v = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);
    if (v & 0x40) {
        if (v & 0x80) {
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6) = v & ~0xc0;
        }
    }

    a = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);
    b = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 8);
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 0) = a & (a ^ b);
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 2) =
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 0);
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 4) =
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 0);

    v6 = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);
    if (v6 != 0) {
        v8 = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 8);
        if (v6 == v8) {
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 12) =
                M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 12) - 1;
            if (M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 12) == 0) {
                M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 2) =
                    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);
                M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 12) = 4;
                M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 13) =
                    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 13) - 1;
                if (M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 13) == 0) {
                    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 4) =
                        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);
                    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 13) = 4;
                }
            } else {
                M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 12) = 0x10;
                M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u8 *, 13) = 0x0a;
                CheckSoftResetCombo();
            }
        }
    }

    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 10) =
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 0), u16 *, 6);
}

/* Inject a virtual key mask (the touch-screen button a menu sprite stands for)
 * into this frame's key state: unless injected presses are blocked, OR it into
 * the newly-pressed, both auto-repeat and held masks so the game reads it as a
 * real button press. */
void InjectKeyPress(s32 keys) {
    extern M2C_UNK gKeyState;
    extern M2C_UNK gInputBlockState;

    if (((InputBlockState *)&gInputBlockState)->keyInjectBlocked != 0) return;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->pressed |= keys;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeat |= keys;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeat2 |= keys;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->held |= keys;
}

#pragma scheduling off
void func_02081a48(void){
extern M2C_UNK data_02101e84;
void TP_Init(void);s32 TP_GetFirmwareCalibration(u16 *);void SetTouchCalibration(u16 *);
u16 a[4];TP_Init();if(!TP_GetFirmwareCalibration(a)){a[0]=0x390;a[1]=0x55f;a[2]=0xd52;a[3]=0x113a;SetTouchCalibration(a);}
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x12)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x13)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x14)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x15)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x16)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x10)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x11)=16;
}
#pragma scheduling reset
/* Samples the touch screen for this frame and updates the tracked touch state:
 * current and start position, the movement bounds, the hold and repeat timers,
 * and the started/pressed/tap/released flags the game reads. */
void UpdateTouchInput(void) {
    extern M2C_UNK gKeyState;
    extern M2C_UNK gInputBlockState;
    void func_0200d778(void);
    s32 TP_ReadTouchSample(u16 *);
    void CalibrateTouchSample(u16 *, u16 *);
    u8 sample[0x10];

    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_STARTED) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_PRESSED) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_TAP) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_RELEASED) = 0;

    if (M2C_FIELD(&gInputBlockState, u8 *, 1) != 0) {
        return;
    }
    func_0200d778();
    if (TP_ReadTouchSample((u16 *)(sample + 8)) != 0) {
        *(u16 *)(sample + 6) = 3;
    } else {
    CalibrateTouchSample((u16 *)sample, (u16 *)(sample + 8));
    }
    if (*(u16 *)(sample + 6) != 0) {
        goto invalid;
    }

    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_CUR_X) = *(u16 *)(sample + 0);
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_CUR_Y) = *(u16 *)(sample + 2);

    if (M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_ACTIVE) == 0) {
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_STARTED) = 1;
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_START_X) = *(u16 *)(sample + 0);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_START_Y) = *(u16 *)(sample + 2);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_X) = *(u16 *)(sample + 0);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_X) = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_X);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_Y) = *(u16 *)(sample + 2);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_Y) = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_Y);
    }
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_ACTIVE) = (u8)1;

        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_X) = *(u16 *)(sample + 0) < M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_X) ? *(u16 *)(sample + 0) : M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_X);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_X) = *(u16 *)(sample + 0) > M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_X) ? *(u16 *)(sample + 0) : M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_X);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_Y) = *(u16 *)(sample + 2) < M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_Y) ? *(u16 *)(sample + 2) : M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MIN_Y);
        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_Y) = *(u16 *)(sample + 2) > M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_Y) ? *(u16 *)(sample + 2) : M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u16 *, TOUCH_MAX_Y);

        if (M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_HOLD_FRAMES) < 0xff) {
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_HOLD_FRAMES) += 1;
        }

        M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_REPEAT_TIMER) -= 1;
        if (M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_REPEAT_TIMER) != 0) {
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_PRESSED) = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_STARTED);
            return;
        } else {
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_PRESSED) = M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_ACTIVE);
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_REPEAT_TIMER) = 4;
            return;
        }
invalid:
        if (M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_ACTIVE) == 1) {
            M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_RELEASED) = 1;
            if (M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_HOLD_FRAMES) <= 4) {
                M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_TAP) = 1;
            }
        }
reset_tail:
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_ACTIVE) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_HOLD_FRAMES) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_REPEAT_TIMER) = 0x10;
    return;
}

/* Try to switch the LCD back on: returns 1 while the power service refuses the
 * request (the caller should retry) and 0 once the display is enabled. */
u8 TryEnableLcd(void) {
    s32 SetLcdEnabled(M2C_UNK);
    u8 retry;

    if (SetLcdEnabled(1) == 0) {
        retry = 1;
    } else {
        retry = 0;
    }
    return retry;
}

/* Create the sleep screen's sprite object (class gSleepScreenSpriteClass) on the
 * default sprite layer. */
void CreateSleepScreenSprites(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gSleepScreenSpriteClass;
    CreateSpriteFromClass(&gSleepScreenSpriteClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Tear down the sleep screen: delete its sprite objects and switch the LCD off. */
void DeleteSleepScreenSprites(void) {
    extern M2C_UNK gSleepScreenSpriteClass;
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    M2C_UNK SetLcdEnabled(s32);

    DeleteSpriteObjectsOfClass(&gSleepScreenSpriteClass);
    SetLcdEnabled(0);
}

/* Put the display to sleep: turn the display off, switch the sub engine's display
 * mode from graphics to off, delete the sleep screen's sprites and shut the LCD
 * down, then disable input until the display wakes again. */
void EnterDisplaySleep(void) {
    extern M2C_UNK gInputBlockState;

    GX_TurnOffDisplay();
    REG_DISPCNT_SUB &= ~DISPCNT_DISPLAY_MODE_GRAPHICS;
    DeleteSleepScreenSprites();
    ((InputBlockState *)&gInputBlockState)->inputDisabled = 1;
}

/* Wake the display: recreate its sprite objects and turn it back on, restore the
 * graphics display mode, then clear the input-disabled flag EnterDisplaySleep set. */
void ExitDisplaySleep(void) {
extern M2C_UNK gInputBlockState;
CreateSleepScreenSprites(); GX_TurnOnDisplay();
REG_DISPCNT_SUB |= DISPCNT_DISPLAY_MODE_GRAPHICS;
RestartVoiceChatCooldown();
((InputBlockState *)&gInputBlockState)->inputDisabled = 0;
}

/* Whether the sleep screen should be shown: only when no input-lock countdown is
 * running and the shared lid word reports the console closed. */
u8 ShouldShowSleepScreen(void) {
    extern M2C_UNK gInputBlockState;
    u8 result;

    if (((InputBlockState *)&gInputBlockState)->inputLockFrames > 0) return 0;
    if (((s32) (*(u16 *) SHARED_LID_WORD & SHARED_LID_CLOSED) >> 15) != 0) result = 1;
    else result = 0;
    return result;
}

/* TRUE while the console's lid is closed (bit SHARED_LID_CLOSED of the shared
 * work area's lid word), i.e. the game should go to sleep. */
u8 IsSleepRequested(void) {
    u8 sleepRequested;

    if (((s32) (*(u16 *)SHARED_LID_WORD & SHARED_LID_CLOSED) >> 0xF) != 0) {
        sleepRequested = 1;
    } else {
        sleepRequested = 0;
    }
    return sleepRequested;
}

/* Per-frame screen-off handling for a screen's object: clear the object's
 * display-off flag, then set it and put the display to sleep when a screen-off
 * was requested or a soft reset is not permitted (func_02084824 is
 * IsSoftResetAllowed, and a link or Wi-Fi session denies it, where a real sleep
 * would drop the connection). */
void SuspendDisplayIfRequested(void *screen) {
    extern M2C_UNK gInputBlockState;
    M2C_FIELD(screen, u16 *, 0x56) = 0;
    if (func_02084824() == 0) {
        M2C_FIELD(screen, u16 *, 0x56) = 1;
        EnterDisplaySleep();
    }
    if (((InputBlockState *)&gInputBlockState)->suspendRequested != 0) {
        M2C_FIELD(screen, u16 *, 0x56) = 1;
        EnterDisplaySleep();
    }
}

/* One step of the sleep screen: unless the sleep/lid flag says the console is on
 * its way down, restart the screen's animation; then, when the screen is not yet
 * marked asleep, run the ARM7 sleep handshake (it returns once the console wakes)
 * and restart the animation again. */
void UpdateSleepScreen(void *screen) {
    M2C_UNK Sprite_ResumeAnimationRepeat(void *);
    M2C_UNK func_0200e920(M2C_UNK, M2C_UNK, M2C_UNK);
    if (IsSleepRequested() == 0) {
        Sprite_ResumeAnimationRepeat(screen);
    }
    if (M2C_FIELD(screen, s16 *, DS3D_SPRITE_SLEEP_FLAG) != 0) {
        return;
    }
    func_0200e920(0xC, 0, 0);
    Sprite_ResumeAnimationRepeat(screen);
}

/* Wake the mic test screen: leave display sleep if this screen had put the
 * console to sleep, then start (or continue) the microphone measurement. */
void ResumeMicTestScreen(void *screen) {
    M2C_UNK StartMicTestMeasurement();
    if (M2C_FIELD(screen, s16 *, DS3D_SPRITE_SLEEP_FLAG) != 0) {
        ExitDisplaySleep();
    }
    StartMicTestMeasurement();
}

/* While the lid is closed and no input lock is running, bring up the sleep
 * screen's sprite (class gSleepRequestSpriteClass) owned by object 3. */
void CreateSleepRequestSprite(void) {
    u8 ShouldShowSleepScreen(void);
    extern M2C_UNK gSleepRequestSpriteClass;
    if (ShouldShowSleepScreen() == 0) {
        return;
    }
    CreateSpriteFromClass(&gSleepRequestSpriteClass, 3);
}

/* Add one frame to the second input-lock countdown (the halt screen keeps input
 * locked by adding a frame every iteration) and return the input-block state. */
s8 *IncrementInputLockFrames2(void) {
    extern M2C_UNK gInputBlockState;
    InputBlockState *state = (InputBlockState *)&gInputBlockState;

    state->inputLockFrames2++;
    return (s8 *)state;
}

/* Add one frame to the main input lock countdown, which makes input be ignored
 * for one more frame. */
s8 *IncrementInputLockFrames(void) {
    extern M2C_UNK gInputBlockState;
    volatile s8 *state = (s8 *)&gInputBlockState;
    state[0]++;
    return (s8 *)state;
}

/* Ends one frame of the input lock. */
void DecrementInputLockFrames(void) {
    extern M2C_UNK gInputBlockState;

    ((InputBlockState *)&gInputBlockState)->inputLockFrames =
        ((InputBlockState *)&gInputBlockState)->inputLockFrames - 1;
}

/* Block InjectKeyPress from injecting virtual key presses (used while the
 * input-block notice sprite is up). */
void BlockKeyInjection(void) {
    extern M2C_UNK gInputBlockState;
    ((InputBlockState *)&gInputBlockState)->keyInjectBlocked = 1;
}

void func_02081f64(void) {
extern M2C_UNK gInputBlockState;
M2C_FIELD(&gInputBlockState,u8 *,3) = 0;
}

/* Override this frame's input: make KEY_B appear newly pressed, auto-repeating
 * and held, and clear the touch flags. */
void ForceKeyBInput(void) {
    extern M2C_UNK gKeyState;

    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->pressed = KEY_B;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeat = KEY_B;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->repeat2 = KEY_B;
    ((KeyState *)M2C_FIELD(&gKeyState, void **, 0))->held = KEY_B;

    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_STARTED) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_PRESSED) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_ACTIVE) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_TAP) = 0;
    M2C_FIELD(M2C_FIELD(&gKeyState, void **, 4), u8 *, TOUCH_RELEASED) = 0;
}

/* Create the input-block notice sprite (class gInputBlockSpriteClass), owned by object 3:
 * its class constructors block injected key presses and force a B press. */
void CreateInputBlockSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, s32);
    extern M2C_UNK gInputBlockSpriteClass;

    CreateSpriteFromClass(&gInputBlockSpriteClass, 3);
}

/* Remove the input-block notice sprite, releasing the key-press block it holds. */
void DeleteInputBlockSprite(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gInputBlockSpriteClass;
    DeleteSpriteObjectsOfClass(&gInputBlockSpriteClass);
}

void func_02082000(void){extern M2C_UNK gInputBlockState;M2C_FIELD(&gInputBlockState,u8 *,2)=1;}

void ClearScreenOffRequest(void){extern M2C_UNK gInputBlockState;M2C_FIELD(&gInputBlockState,u8 *,2)=0;}

void MemAlloc(void) {
    M2C_UNK HeapAllocBlock();
    HeapAllocBlock();
}

void MemAllocArray(void) {
    HeapAllocBlock();
}

void MemFree(void) {
    M2C_UNK HeapFreeBlock();
    HeapFreeBlock();
}

void MemFreeArray(void) {
    HeapFreeBlock();
}

void func_02082058(void) {
    M2C_UNK GetSystemUserProfile(u8 *);
    extern u8 data_0214c1b8;
    GetSystemUserProfile(&data_0214c1b8);
}

M2C_UNK *GetLocalPlayerName(void) {
    extern M2C_UNK data_0214c1bc;
    return &data_0214c1bc;
}

u8 func_02082078(void) {
    extern u8 data_0214c1b8;
    return data_0214c1b8;
}

u16 GetLocalPlayerNameLength(void){extern u8 data_0214c1b8;return M2C_FIELD(&data_0214c1b8,u16 *,0x1a);}

/* Point one 3D sprite layer at a VRAM bank: store that bank's VRAM address for the
 * layer and record the bank number in bits 2..5 of the layer's packed tile word. */
void Set3DSpriteLayerBank(u32 layer, u32 bank) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    u8 onMain;
    u32 vramBase;
    u32 index;
    void *engine;
    u32 bits;
    u16 *tile;
    u32 old;

    if (gCur3DSpriteEngine == g3DSpriteEngineMain) onMain = 1; else onMain = 0;
    if (onMain == 1) vramBase = DS3D_VRAM_MAIN; else vramBase = DS3D_VRAM_SUB;
    M2C_FIELD((u8 *)gCur3DSpriteEngine + layer * 4, u32 *, DS3D_ENGINE_LAYER_VRAM) =
        vramBase + DS3D_VRAM_BANK(bank);
    engine = gCur3DSpriteEngine;
    index = layer * 2;
    tile = (u16 *)((u8 *)M2C_FIELD(engine, void **, 0) + DS3D_BANK_LAYER_TILES);
    bits = bank << 28; /* only its low 4 bits survive, into bits 2..5 */
    old = *(u16 *)((u8 *)tile + index);
    *(u16 *)((u8 *)tile + index) =
        (old & ~DS3D_TILE_BANK_MASK) | (bits >> 26);
}

/* Point one 3D sprite layer at a palette: store the palette index in bits 8..12 of
 * the layer's packed tile word (DS3D_BANK_LAYER_TILES). */
void Set3DSpriteLayerPalette(u32 layer, u32 palette) {
    extern void *gCur3DSpriteEngine;
    u32 index = layer * 2;
    void *engine = gCur3DSpriteEngine;
    u32 bits = palette << 27; /* only its low 5 bits survive, into bits 8..12 */
    u16 *tile = (u16 *)((u8 *)M2C_FIELD(engine, void **, 0) + DS3D_BANK_LAYER_TILES);
    u32 old = M2C_FIELD(tile, u16 *, index);
    M2C_FIELD(tile, u16 *, index) = (old & ~DS3D_TILE_PALETTE_MASK) | (bits >> 19);
}

/* Point one 3D sprite layer at a tile size class: store the size in bits 14..15 of
 * the layer's packed tile word (DS3D_BANK_LAYER_TILES). */
void Set3DSpriteLayerSize(s32 layer, u32 size) {
    extern void *gCur3DSpriteEngine;
    u32 index = layer * 2;
    void *engine = gCur3DSpriteEngine;
    u32 bits = size << 30; /* only its low 2 bits survive, into bits 14..15 */
    u16 *tile = (u16 *)((u8 *)M2C_FIELD(engine, void **, 0) + DS3D_BANK_LAYER_TILES);
    u32 old = M2C_FIELD(tile, u16 *, index);
    M2C_FIELD(tile, u16 *, index) = (old & ~DS3D_TILE_SIZE_MASK) | (bits >> 16);
}

#pragma optimization_level 2
#pragma opt_propagation off
void Configure3DSpriteLayout(u8 *presetData)
{
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteBankMain;
    void Reset3DSpriteLayers(void);
    void Reset3DSpriteCorners(void);
    void Configure3DSpriteLayer(s32, void *);
    DS3DSpritePreset *config = (DS3DSpritePreset *)presetData;
    DS3DSpritePresetFlagRef mode, a, b;
    u16 *bank;
    u8 isMain;
    s32 layer;

    Reset3DSpriteLayers();
    Reset3DSpriteCorners();

    mode = *(DS3DSpritePresetFlagRef *)gCur3DSpriteEngine;
    *(u16 *)mode.flags = (*(u16 *)mode.flags & ~7) | (config->mode & 7);
    a = *(DS3DSpritePresetFlagRef *)gCur3DSpriteEngine;
    *(u16 *)a.flags = (*(u16 *)a.flags & ~0x1000) | ((u32)config->firstLayer << 31 >> 19);
    b = *(DS3DSpritePresetFlagRef *)gCur3DSpriteEngine;
    *(u16 *)b.flags = (*(u16 *)b.flags & ~0x6000) | ((u32)config->secondLayer << 30 >> 17);

    isMain = (gCur3DSpriteEngine == g3DSpriteEngineMain);
    if (isMain == 1) {
        bank = (u16 *)g3DSpriteBankMain;
        bank[0] = (bank[0] & ~8) | (((u32)config->mainScreenEnabled << 31) >> 28);
        bank = (u16 *)g3DSpriteBankMain;
        bank[1] = (bank[1] & ~7) | (config->mainScreenLayer & 7);
        bank = (u16 *)g3DSpriteBankMain;
        bank[1] &= ~0x38;
    }

    presetData += 4;
    layer = 0;
    do {
        Configure3DSpriteLayer((u8)layer, presetData);
        ++layer;
        presetData += 2;
    } while (layer < 4);
}
#pragma opt_propagation reset
#pragma optimization_level 4
/* Point the current screen's 3D sprite engine at its four layer tile buffers
 * (the main screen's or the sub screen's), then apply layout `preset` to it. */
M2C_UNK Apply3DSpriteLayout(M2C_UNK *preset) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern u8 g3DSpriteLayerTilesMain[];
    extern u8 g3DSpriteLayerTilesSub[];
    void Configure3DSpriteLayout(u8 *);
    u8 *layerTiles;
    u8 isMain;
    s32 layer;

    if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
        isMain = 1;
    } else {
        isMain = 0;
    }
    if (isMain == 1) {
        layerTiles = g3DSpriteLayerTilesMain;
    } else {
        layerTiles = g3DSpriteLayerTilesSub;
    }

    for (layer = 0; layer < 4; layer++) {
        ((u8 **)gCur3DSpriteEngine)[8 + layer] = layerTiles + layer * 0x1000;
    }

    Configure3DSpriteLayout((u8 *)preset);
}

/* Apply the fixed display layout preset to the current 3D sprite engine: the
 * plain layer mapping screens use when they reset their sprite engine. */
void Apply3DSpriteDisplayConfig(void) {
    M2C_UNK Apply3DSpriteLayout(M2C_UNK *);
    extern M2C_UNK g3DSpriteLayoutDisplay;
    Apply3DSpriteLayout(&g3DSpriteLayoutDisplay);
}

