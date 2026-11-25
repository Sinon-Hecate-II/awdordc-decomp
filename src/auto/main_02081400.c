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

s32 LoadNarcFileRaw(void *arg0, void *arg1) {
    return LoadFileToAddress(BuildNarcPath(arg0), arg1);
}

s32 LoadNarcFileDecompressed(void *arg0, void *arg1) {
    return LoadDecompressedFileTo(BuildNarcPath(arg0), arg1);
}

void LoadNarcMemberToBuffer(void) {
    M2C_UNK LoadDecompressedFile(s32, M2C_UNK);
    LoadDecompressedFile(BuildNarcPath(), 1);
}

s32 func_020815bc(void *arg0, void *arg1) {
    return LoadFileToNewBuffer(BuildNarcPath(arg0), arg1);
}

void func_020815d4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 BuildNarcPath(M2C_UNK);
 void ReadFileSection(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 ReadFileSection(BuildNarcPath(arg0), arg1, arg2, arg3);
}

void LoadNarcFileToSpriteBuffer(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 BuildNarcPath(M2C_UNK);
    M2C_UNK LoadFileToSpriteBuffer(s32, M2C_UNK, M2C_UNK);
    LoadFileToSpriteBuffer(BuildNarcPath(arg0), arg1, arg2);
}

void func_0208161c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 BuildNarcPath(M2C_UNK);
 void LoadFileToBGExtPltt(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 LoadFileToBGExtPltt(BuildNarcPath(arg0), arg1, arg2, arg3);
}

void LoadNarcLayerPalette(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 BuildNarcPath(M2C_UNK);
 void QueueFileToBGExtPltt(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 QueueFileToBGExtPltt(BuildNarcPath(arg0), arg1, arg2, arg3);
}

void func_0208166c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 BuildNarcPath(M2C_UNK);
 void LoadFileToObjExtPalette(M2C_UNK, M2C_UNK, M2C_UNK);
 LoadFileToObjExtPalette(BuildNarcPath(arg0),arg1,arg2);
}

s32 func_0208168c(void *arg0, void *arg1) {
    return LoadFileToTextureBank(BuildNarcPath(arg0), arg1);
}

void func_020816a4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 BuildNarcPath(M2C_UNK);
 void LoadFileAndDrawTilemapBlock(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 LoadFileAndDrawTilemapBlock(BuildNarcPath(arg0), arg1, arg2, arg3);
}

void LoadNarcFileToBuffer(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 BuildNarcPath(M2C_UNK);
 void LoadDecompressedFileAndDrawTilemapBlock(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 LoadDecompressedFileAndDrawTilemapBlock(BuildNarcPath(arg0), arg1, arg2, arg3);
}

s32 BuildNarcPath(M2C_UNK arg0) {
    M2C_UNK StringCopy(M2C_UNK *, M2C_UNK *);
    M2C_UNK StringAppend(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02101e7c;
    extern M2C_UNK data_0214c14c;
    StringCopy(&data_0214c14c, &data_02101e7c);
    StringAppend(&data_0214c14c, arg0);
    return (s32)&data_0214c14c;
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

u8 func_02081d18(void) {
    s32 SetLcdEnabled(M2C_UNK);
    u8 var_r0;

    if (SetLcdEnabled(1) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02081d38(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02101e8c;
    CreateSpriteFromClass(&data_02101e8c, 7);
}

void func_02081d50(void){extern M2C_UNK data_02101e8c;M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);M2C_UNK SetLcdEnabled(s32);DeleteSpriteObjectsOfClass(&data_02101e8c);SetLcdEnabled(0);}

void EnterDisplaySleep(void){extern M2C_UNK gInputBlockState;GX_TurnOffDisplay();*(volatile u32 *)0x4001000 &=~0x10000;func_02081d50();M2C_FIELD(&gInputBlockState,u8 *,1)=1;}

void func_02081da0(void) {
extern M2C_UNK gInputBlockState;
func_02081d38(); GX_TurnOnDisplay();
*(s32 *)0x04001000 |= 0x10000;
func_020863f0();
M2C_FIELD(&gInputBlockState,u8 *,1) = 0;
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

u8 IsSleepRequested(void) {
    u8 var_r0;

    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
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

void func_02081ec8(void *arg0) {
    void func_02081da0(void);
    M2C_UNK StartMicTestMeasurement();
    if (M2C_FIELD(arg0, s16 *, 0x56) != 0) {
        func_02081da0();
    }
    StartMicTestMeasurement();
}

void func_02081ee4(void) {
    u8 ShouldShowSleepScreen(void);
    extern M2C_UNK data_02101eac;
    if (ShouldShowSleepScreen() == 0) {
        return;
    }
    CreateSpriteFromClass(&data_02101eac, 3);
}

s8 *func_02081f08(void) { extern M2C_UNK gInputBlockState; volatile s8 *p=(s8 *)&gInputBlockState; p[4]++; return (s8 *)p; }

s8 *func_02081f20(void) { extern M2C_UNK gInputBlockState; volatile s8 *p=(s8 *)&gInputBlockState; p[0]++; return (s8 *)p; }

void func_02081f38(void){extern M2C_UNK gInputBlockState;M2C_FIELD(&gInputBlockState,s8 *,0)=M2C_FIELD(&gInputBlockState,s8 *,0)-1;}

void func_02081f50(void) {
    extern M2C_UNK gInputBlockState;
    M2C_FIELD(&gInputBlockState, s8 *, 3) = 1;
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

void func_02081fd4(void){extern M2C_UNK data_02101edc;M2C_UNK CreateSpriteFromClass(M2C_UNK *,s32);CreateSpriteFromClass(&data_02101edc,3);}

void func_02081fec(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02101edc;
    DeleteSpriteObjectsOfClass(&data_02101edc);
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

void Set3DSpriteLayerPalette(u32 arg0,u32 arg1) {
extern void *gCur3DSpriteEngine;
u32 index=arg0*2;
void *engine=gCur3DSpriteEngine;
u32 bits=arg1<<27;
u16 *p=(u16 *)((u8 *)M2C_FIELD(engine,void **,0)+6);
u32 old=M2C_FIELD(p,u16 *,index);
M2C_FIELD(p,u16 *,index)=(old&~0x1f00)|(bits>>19);
}

void SetLayerSize(s32 arg0, u32 arg1) {
    extern void *gCur3DSpriteEngine;
    u32 index = arg0 * 2;
    void *engine = gCur3DSpriteEngine;
    u32 bits = arg1 << 30;
    u16 *p = (u16 *)((u8 *)M2C_FIELD(engine, void **, 0) + 6);
    u32 old = M2C_FIELD(p, u16 *, index);
    M2C_FIELD(p, u16 *, index) = (old & ~0xc000) | (bits >> 16);
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

void Apply3DSpriteDisplayConfig(void) {
    M2C_UNK Apply3DSpriteLayout(M2C_UNK *);
    extern M2C_UNK data_02101fb4;
    Apply3DSpriteLayout(&data_02101fb4);
}

