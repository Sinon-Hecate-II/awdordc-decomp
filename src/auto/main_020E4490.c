/* 22 functions from 0x020E4490 to 0x020E5080 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"
#include "hw_div.h"

typedef struct {
    u16 unused : 4;
    u16 slot : 3;
} SaveSlotBits;

typedef struct { u32 words[64]; } SaveProgressWords;
typedef struct { u8 bytes[8]; } SaveProgressFlags;

typedef struct { u8 pixels[32]; } Unk020ETile;
typedef struct { u8 count; u8 pad[3]; s32 ptr; } Unk02168Fec;
u16 *LowerBoundU16(u16 *,u16 *,u16 *,u32);
extern s32 gMicTestIpc;

#pragma opt_common_subs off
void func_020e4490(void) {
    M2C_UNK func_020e4378();
    M2C_UNK func_02082058();
    M2C_UNK ResetKeyState();
    M2C_UNK func_02081a48();
    M2C_UNK func_02082d08();
    M2C_UNK func_02082b78();
    M2C_UNK func_02082cb4();
    M2C_UNK func_02082078();
    M2C_UNK SetLanguage();
    M2C_UNK Reset3DSpriteOam();
    M2C_UNK func_0208232c();
    M2C_UNK Reset3DSpriteListsOnBothEngines();
    M2C_UNK InitGameHeap();
    M2C_UNK LoadCardArchiveIndexToHeap();
    M2C_UNK InitResourceSystem();
    M2C_UNK func_02086574();
    M2C_UNK InitSound();
    M2C_UNK Init3DSpritePool();
    M2C_UNK InstallVBlankHandler();
    M2C_UNK RTC_Init();
    M2C_UNK SeedRandomFromRtc();
    M2C_UNK SaveManager_Start();
    void ResetGameState(void);
    M2C_UNK func_020e349c();
    extern s32 data_027e15bc;
    extern s32 gVBlankCount;
    extern u8 gFramePending;
    extern u8 gSpriteUpdateBusy;
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    s32 temp_r7;
    s32 var_r8;

    data_027e15bc = 0;
    gVBlankCount = 0;
    gFramePending = 0;
    gSpriteUpdateBusy = 0;
    func_020e4378();
    func_02082058();
    ResetKeyState();
    func_02081a48();
    func_02082d08();
    func_02082b78();
    func_02082cb4();
    func_02082078();
    SetLanguage();
    temp_r7 = gCur3DSpriteEngine;
    var_r8 = 0;
    do {
        if (var_r8 == 0) {
            gCur3DSpriteEngine = data_027e00c8;
        } else {
            gCur3DSpriteEngine = data_027e00c4;
        }
        Reset3DSpriteOam();
        func_0208232c();
        var_r8 += 1;
    } while (var_r8 < 2);
    gCur3DSpriteEngine = temp_r7;
    Reset3DSpriteListsOnBothEngines();
    InitGameHeap();
    LoadCardArchiveIndexToHeap();
    InitResourceSystem();
    func_02086574();
    InitSound();
    Init3DSpritePool();
    InstallVBlankHandler();
    RTC_Init();
    SeedRandomFromRtc();
    SaveManager_Start();
    ResetGameState();
    func_020e349c();
}
#pragma opt_common_subs reset
void func_020e4570(void) {
    M2C_UNK GX_TurnOnDisplay();
    M2C_UNK func_02007598();
    func_02007598();
    GX_TurnOnDisplay();
    *(s32 *)0x04001000 |= 0x10000;
}

/* NNS/NitroSDK main loop body, run once per frame by main(): wait for the game
 * frame to be ready, run the input, sound and 3D-sprite updates for every
 * sprite layer, then let the pending frame callback (VBlank) run. */
void NitroMain(void) {
extern u8 gFramePending;
extern s32 gFrameCounter;
extern void (*data_02168fe8)(void);
void func_0208f4d8(void);
void func_0208184c(void);
void UpdateTouchInput(void);
void func_02090390(void);
void func_02081ee4(void);
void func_02091bf4(void);
void UpdateSpriteSlots(void);
void DrawSpriteSlots(void);
void func_0209db48(void);
void SoundEngineUpdateTimers(void);
void GetSpriteLayerHead(int);
void Update3DSpriteObject(void);
void OS_WaitIrq(int,int);
if (!gFramePending) return;
data_02168fe8=0;
func_0208f4d8();
gFrameCounter++;
func_0208184c(); UpdateTouchInput(); func_02090390(); func_02081ee4();
GetSpriteLayerHead(3);Update3DSpriteObject();
GetSpriteLayerHead(4);Update3DSpriteObject();
GetSpriteLayerHead(5);Update3DSpriteObject();
GetSpriteLayerHead(6);Update3DSpriteObject();
GetSpriteLayerHead(7);Update3DSpriteObject();
GetSpriteLayerHead(8);Update3DSpriteObject();
func_02091bf4();UpdateSpriteSlots();DrawSpriteSlots();
GetSpriteLayerHead(9);Update3DSpriteObject();
GetSpriteLayerHead(10);Update3DSpriteObject();
func_0209db48();
if(data_02168fe8) data_02168fe8();
gFramePending=0;
SoundEngineUpdateTimers();
OS_WaitIrq(1,1);
}

/* VBlank interrupt handler.  It saves the hardware divide/square-root registers
 * (a division may be in progress), ticks the VBlank counter, marks the sprite
 * update busy and walks the 3D sprite layers: layer 1 every VBlank, and layers
 * 0/2 plus the bank, VRAM and OAM uploads only when the main loop has already
 * taken the previous frame; otherwise it only blanks the OAM entries the last
 * upload added (ClearLast3DSpriteOamEntries).  It then signals the VBlank
 * event, restores the math registers and waits for the divider to finish. */
void VBlankHandler(void) {
    void Upload3DSpriteOam(void);
    void ClearLast3DSpriteOamEntries(void);
    M2C_UNK Apply3DSpriteBanks();
    void Update3DSpriteVram(void);
    void GetSpriteLayerHead(int);
    void Update3DSpriteObject(void);
    void func_0200d248(void *);
    void func_0200d288(void *);
    extern int gOsArea;
    extern unsigned char gFramePending;
    extern unsigned char gSpriteUpdateBusy;
    extern int gVBlankCount;
    int savedMathState[7];

    volatile int *vblankCount = &gVBlankCount;
    func_0200d248(savedMathState);
    (*(volatile unsigned char *)&gSpriteUpdateBusy) = 1;
    ++*vblankCount;
    if ((*(volatile unsigned char *)&gFramePending) == 0) {
        GetSpriteLayerHead(0);
        Update3DSpriteObject();
    }
    GetSpriteLayerHead(1);
    Update3DSpriteObject();
    if ((*(volatile unsigned char *)&gFramePending) == 0) {
        GetSpriteLayerHead(2);
        Update3DSpriteObject();
        Apply3DSpriteBanks();
        Update3DSpriteVram();
        Upload3DSpriteOam();
        (*(volatile unsigned char *)&gFramePending) = 1;
    } else {
        ClearLast3DSpriteOamEntries();
    }
    (*(volatile unsigned char *)&gSpriteUpdateBusy) = 0;
    M2C_FIELD(&gOsArea, s32 *, OS_AREA_EVENT_FLAGS) = (M2C_FIELD(&gOsArea, s32 *, OS_AREA_EVENT_FLAGS) | OS_EVENT_VBLANK);
    func_0200d288(savedMathState);
    while (REG_DIVCNT & DIVCNT_BUSY) {
    }
}

/* Resets everything a fresh game session needs before the title screen: the
 * default settings and dialog state, the sprite slot and text tables, the
 * campaign map headers, and both 3D sprite engines (each is put back into
 * graphics display mode and its bank flushed to the hardware).  Afterwards the
 * map's buffers, graphics files and config are set up again. */
void ResetGameState(void) {
    M2C_UNK Apply3DSpriteBanks();
    M2C_UNK ResetCurrentMapBlocks();
    M2C_UNK ResetTextLabelSlots();
    M2C_UNK ResetTextState();
    M2C_UNK ResetDialogUI();
    M2C_UNK func_020960b4();
    M2C_UNK ResetMapConfig();
    M2C_UNK ResetScreenStates();
    M2C_UNK ApplyScreenMode(M2C_UNK);
    M2C_UNK ResetSpriteSlots();
    M2C_UNK InitDefaultGameSettings();
    M2C_UNK ClearCampaignMapHeaders();
    M2C_UNK ResetMapListsAndGraphics();
    M2C_UNK ClearUnitMoveSlots();
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 savedEngine;
    s32 engine;
    s32 screen;

    InitDefaultGameSettings();
    ResetDialogUI();
    ResetSpriteSlots();
    ResetTextState();
    ResetTextLabelSlots();
    ClearCampaignMapHeaders();
    ResetScreenStates();
    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        ApplyScreenMode(DS3D_DISPLAY_GRAPHICS);
        Apply3DSpriteBanks();
        screen += 1;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
    ResetCurrentMapBlocks();
    ResetMapListsAndGraphics();
    ResetMapConfig();
    ClearUnitMoveSlots();
    func_020960b4();
}

void func_020e47f8(void) {
    void ClearSaveRecordHeader(s32);
    s32 var_r4;

    var_r4 = 0;
    do {
        ClearSaveRecordHeader(var_r4);
        var_r4 += 1;
    } while (var_r4 < 3);
}

/* Clear the 8-byte header (the save-slot summary) of save record `record`. */
void ClearSaveRecordHeader(s32 record) {
extern u8 data_0215dba4[];
u32 *header=(u32 *)(data_0215dba4+record*0x118);
header[0]&=~15;
header[0]&=~240;
header[1]&=0xffff0000;
header[1]=(u16)header[1];
header[0]&=~0xff00;
header[0]&=~0xff0000;
header[0]&=~0xff000000;
}

#pragma peephole off
void StoreSaveSlotProgress(s32 arg0) {
    extern M2C_UNK gOptionBits;
    extern M2C_UNK gSaveSlotSummary;
    extern void **gCurrentMap;
    extern u8 data_0215dba4[];
    extern u8 data_0215dbac[];
    extern M2C_UNK gMapProgressRecords;
    extern u8 data_0215dcac[];
    extern M2C_UNK gEventFlagsHigh;
    extern u8 data_0215dcb4[];
    extern M2C_UNK gEventValues;

    SaveSlotBits *slot = (SaveSlotBits *)((u8 *)&gOptionBits + 6);
    u32 *summary = (u32 *)&gSaveSlotSummary;
    u16 slotFlags = *(u16 *)slot;
    u32 word = summary[0];
    void ***mapBase = &gCurrentMap;
    void **map;
    u32 location;
    s32 count;
    s32 offset;
    u32 *dest;

    *(u16 *)slot = (((u32)(u16)arg0 << 29) >> 25) | (slotFlags & ~0x70);
    word = (word & ~0xf) | (arg0 & 0xf);
    summary[0] = word;

    map = *mapBase;
    location = summary[1];
    location = (location & 0xffff0000) | (u16)(M2C_FIELD(map[0], u16 *, MAP_ID) - 0xa1);
    summary[1] = location;
    {
        u16 turn = M2C_FIELD(map[0], u16 *, MAP_TURN);
        count = (u32)(word << 16) >> 24;
        summary[1] = ((u32)turn << 16) | (u16)location;
    }

    if (count < 0xff)
        count++;
    word = summary[0];
    word = (word & ~0xff00) | (((u32)count << 24) >> 16);
    summary[0] = word;
    offset = arg0 * 0x118;
    dest = (u32 *)(data_0215dba4 + offset);
    dest[0] = word;
    dest[1] = summary[1];
    *(SaveProgressWords *)(data_0215dbac + offset) = *(SaveProgressWords *)&gMapProgressRecords;
    *(SaveProgressFlags *)(data_0215dcac + offset) = *(SaveProgressFlags *)&gEventFlagsHigh;
    *(SaveProgressFlags *)(data_0215dcb4 + offset) = *(SaveProgressFlags *)&gEventValues;
}
#pragma peephole reset
void func_020e49ec(void) {
    M2C_UNK SetEventFlag(s32, M2C_UNK);
    M2C_UNK ResetMapProgress();
    s32 var_r5;

    ResetMapProgress();
    var_r5 = 0x60;
    do {
        SetEventFlag(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0xA0);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction off
/* Loads save slot `slot` from the newest campaign save record and copies its
 * fields into the live progress globals: the slot summary, the per-map progress
 * records, the high event flags and value bytes, and the three map-slot entries. */
void LoadSaveSlotProgress(s32 slot)
{
  s32 GetSaveRecordBuffer(void);
  s32 LoadNewestSaveRecord(s32, s32);
  extern M2C_UNK gSaveSlotSummary;
  extern M2C_UNK gMapProgressRecords;
  extern M2C_UNK gEventFlagsHigh;
  extern M2C_UNK gEventValues;
  extern M2C_UNK gOptionBits;
  s32 saveBuffer;
  s32 offset;
  s32 *slotRecord;
  s32 i;
  saveBuffer = GetSaveRecordBuffer();
  if (LoadNewestSaveRecord(4, saveBuffer) == 0)
  {
    return;
  }
  offset = slot * 0x118;
  slotRecord = (s32 *) (saveBuffer + offset);
  {
    u32 word0 = ((volatile u32 *) slotRecord)[0x284 / 4];
    u32 word1 = ((volatile u32 *) slotRecord)[0x288 / 4];
    ((volatile u32 *) (&gSaveSlotSummary))[0] = word0;
    ((volatile u32 *) (&gSaveSlotSummary))[1] = word1;
  }
  *((SaveProgressWords *) (&gMapProgressRecords)) = *((SaveProgressWords *) (((u8 *) slotRecord) + 0x28c));
  *((SaveProgressFlags *) (&gEventFlagsHigh)) = *((SaveProgressFlags *) (((u8 *) (saveBuffer + offset)) + 0x38c));
  *((SaveProgressFlags *) (&gEventValues)) = *((SaveProgressFlags *) (((u8 *) (saveBuffer + offset)) + 0x394));
  for (i = 0; i < 3; i++)
  {
    u8 *entry = ((u8 *) saveBuffer) + (i * 8);
    u16 first = *((u16 *) (entry + 0xcc));
    *((u16 *) ((((u8 *) (&gOptionBits)) + (i * 8)) + 0x34)) = first;
    *((u16 *) ((((u8 *) (&gOptionBits)) + (i * 8)) + 0x36)) = *((u16 *) (entry + 0xce));
    *((s32 *) ((((u8 *) (&gOptionBits)) + (i * 8)) + 0x38)) = *((s32 *) (entry + 0xd0));
  }
}
#pragma pop
void func_020e4b24(void) {

}

u8 func_020e4b28(s32 a){extern u8 data_0215dba4[];return ((u32)(M2C_FIELD(data_0215dba4,u32 *,a*0x118)<<16)>>24)!=0;}

/* True on the campaign's final battle (story map MAP_ID_STORY_FINAL) while the
 * battle runs in the default mode (the low three bits of gMapConfig clear). */
s32 IsFinalCampaignMap(void) {
    extern u16 gMapConfig;
    extern void **gCurrentMap;
    if (!(((u32) (gMapConfig << 0x1D) >> 0x1D) & 0xFF) && (M2C_FIELD(*gCurrentMap, u16 *, MAP_ID) == MAP_ID_STORY_FINAL)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
s32 func_020e4b9c(u16 key,...){extern u16 data_0212da1c;extern u16 data_020f4eb4[];volatile u8 a=0;volatile u8 b=0;u16 *p=LowerBoundU16(data_020f4eb4,data_020f4eb4+data_0212da1c,&key,*(u32 *)&b);if(*p!=key)return 0;return p-data_020f4eb4;}
#pragma pop
/* Binary-search the sorted u16 table [first, last) for the first element not less
 * than *key (std::lower_bound); `unused` is a spare fourth argument. */
u16 *LowerBoundU16(u16 *first, u16 *last, u16 *key, u32 unused) {
    s32 count = last - first;

    while (count > 0) {
        s32 half = count / 2;
        u16 *mid = first + half;
        if (*mid < *key) {
            half++;
            first = mid + 1;
            count -= half;
        } else {
            count = half;
        }
    }
    return first;
}
#pragma opt_propagation reset
/* Acquire the shared username font: count the acquire and load the font on the
 * first one, so every user shares a single decompressed copy. */
void AcquireUsernameFont(void) {
    s32 LoadDecompressedFile(M2C_UNK *, M2C_UNK);
    extern M2C_UNK sUsernameFontPath;
    extern M2C_UNK gUsernameFontCache;
    u8 refCount;

    refCount = ((UsernameFontCache *) &gUsernameFontCache)->refCount;
    ((UsernameFontCache *) &gUsernameFontCache)->refCount = (u8) (refCount + 1);
    if (refCount != 0) {
        return;
    }
    ((UsernameFontCache *) &gUsernameFontCache)->glyphs = (void *) LoadDecompressedFile(&sUsernameFontPath, 1);
}

/* Release one acquire of the shared username font; the last release frees the
 * decompressed glyphs and leaves the cache empty. */
void ReleaseUsernameFont(void) {
    M2C_UNK HeapFreeBlock(s32);
    extern M2C_UNK gUsernameFontCache;
    u32 refCount;

    refCount = ((UsernameFontCache *) &gUsernameFontCache)->refCount - 1;
    ((UsernameFontCache *) &gUsernameFontCache)->refCount = (u8) refCount;
    if (refCount & 0xFF) {
        return;
    }
    HeapFreeBlock((s32) ((UsernameFontCache *) &gUsernameFontCache)->glyphs);
    ((UsernameFontCache *) &gUsernameFontCache)->glyphs = 0;
}

void DrawGlyphString(u16 *keys,u32 dst,u32 map,u32 pal,u16 x,u16 y,u32 tileArg) {M2C_UNK MI_CpuCopy32();extern M2C_UNK gUsernameFontCache;u16 *p;u32 bits;u32 i;u32 next,next2,cur;u32 source;if(!*keys)return;bits=pal<<28;{u32 offset=y<<5;p=(u16 *)(map+((x+offset)*2));}i=0;do {s32 index=func_020e4b9c(*keys);source=M2C_FIELD(&gUsernameFontCache,u32 *,4)+index*128;MI_CpuCopy32(source,dst+((tileArg&0x7ffffffU)<<5),128);next=(tileArg+1)|(bits>>16);next2=(tileArg+2)|(bits>>16);cur=tileArg|(bits>>16);p[i]=cur;p[i+1]=next;p[i+32]=next2;p[i+33]=(tileArg+3)|(bits>>16);keys++;tileArg+=4;i+=2;}while(*keys);}

/* Advance and confirm a menu button: update its sprite, and when its owner
 * reports a click (or the button's alternate frame is enabled while the owner is
 * pressed), or A is pressed, play the click sound, step the sprite to the pressed
 * frame with a fresh press timer and resume the owning object's animation. */
void ConfirmMenuButton(void *menu) {
    void Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK MenuSpriteUpdate(void *);
    extern u16 *gKeyState;

    register u16 keys;
    register void *sprite;
    register void *owner;
    s8 ownerState;
    u8 clicked;
    void *button;

    MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x38));
    keys = *gKeyState;
    sprite = M2C_FIELD(menu, void **, 0x38);
    owner = M2C_FIELD(sprite, void **, MENU_SPRITE_OWNER);
    ownerState = M2C_FIELD(owner, s8 *, 0xb);
    clicked = 1;
    if (ownerState != 1) {
        if (((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1b) >> 0x1f) != 0) {
            ownerState = M2C_FIELD(owner, s8 *, 0xc);
            if (ownerState == 1) goto accept;
        }
        clicked = 0;
    }
accept:
    if (!(clicked & 0xff) && !(keys & 0x2)) {
        return;
    }
    PlaySoundEffect(0x1000f);
    button = M2C_FIELD(menu, void **, 0x38);
    if ((s32) M2C_FIELD(button, s8 *, MENU_SPRITE_TIMER) >= 0) {
        M2C_FIELD(button, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(button, s32 *, MENU_SPRITE_FRAME) & ~MENU_SPRITE_FRAME_MASK) | ((u32) ((u16) (((u32) (M2C_FIELD(button, u8 *, MENU_SPRITE_BASE) << 0x1c) >> 0x1c) + 1) << 0x18) >> 6));
        M2C_FIELD(button, s8 *, MENU_SPRITE_TIMER) = 0xc;
    }
    Sprite_ResumeAnimation(menu);
}

#pragma scheduling off
/* Tick the mic test's measurement timer: decrement it (not below zero) and, when
 * it reaches zero, end the running measurement by clearing its flag and setting
 * the "measurement requested" flag.  Returns 1 once the window ended, else 0. */
s32 TickMicTestTimer(MicTestScreen *screen) {
    s16 count = M2C_FIELD(screen, s16 *, 0x3e);
    s32 expired;
    if (count > 0) M2C_FIELD(screen, s16 *, 0x3e) = count - 1;
    if (M2C_FIELD(screen, s16 *, 0x3e) == 0) expired = 1; else expired = 0;
    if (!(expired & 255)) return 0;
    M2C_FIELD(screen, u8 *, 0x3c) &= ~MIC_TEST_FLAG_RUNNING;
    M2C_FIELD(screen, u8 *, 0x3c) |= MIC_TEST_FLAG_START;
    return 1;
}
#pragma scheduling reset
void func_020e4e8c(void *arg0) {
    M2C_UNK Arm7TransferStartWait(M2C_UNK *);
    extern M2C_UNK data_02168ff8;
    Arm7TransferStartWait(&data_02168ff8);
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) (M2C_FIELD(arg0, u8 *, 0x3C) | 2);
}

#pragma scheduling off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_020e4eb0(void *arg0) {
    void DC_InvalidateRange(void *, s32);
    s32 Divide(s32, s32);
    void AddSprite(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 gMicTestIpc;
    extern u8 gSpriteDesc32x32[];

    u8 cond;
    u8 idx;
    s32 nidx;
    u8 *r3p;
    u8 *r2p;
    s32 saved;
    u8 *arr;
    u8 b;
    u32 i;
    u32 maxv;
    u8 t;
    s32 tier;
    u32 sum;
    u8 *p;
    s32 divres;
    register s32 mask;
    register s32 *enginePtr;
    register s32 kind, scale, r8v, r9v, r10, fullmask;
    u16 a0;
    u16 **eng;
    u16 *base;
    u32 sh;
    u16 arg2;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    cond = (*(volatile s16 *)((char *)arg0 + 0x3e) == 0);
    if (!cond) goto skip_all;

    arr = (u8 *)gMicTestIpc;
    DC_InvalidateRange(arr, 0x20);

    maxv = 0;
    i = 0;
    do {
        b = arr[i];
        if (b >= 0x15 && b <= 0xea) {
            t = b;
            if (b < 0x80) {
                t = (u8)(0x100 - b);
            }
            if (maxv < t) {
                maxv = t;
            }
        }
        i = i + 1;
    } while (i < 0x20);

    if (maxv > 0xd0) tier = 4;
    else if (maxv > 0xbb) tier = 3;
    else if (maxv > 0xa3) tier = 2;
    else if (maxv > 0x8d) tier = 1;
    else tier = 0;

    idx = ((u8 *)arg0)[0x40];
    r3p = (u8 *)arg0 + 0x41;
    r2p = (u8 *)arg0 + 0x4b;
    ((u8 *)arg0 + idx)[0x41] = (u8)tier;

    idx = ((u8 *)arg0)[0x40];
    nidx = idx + 1;
    if ((u8)(((u8 *)arg0)[0x40] = nidx) >= 0x0a) {
        ((u8 *)arg0)[0x40] = 0;
    }

    sum = 0;
    p = r3p;
    if (p != r2p) {
        do {
            sum += *p;
            p++;
        } while (p != r2p);
    }

    divres = Divide(sum, 10);
    r10 = divres;
    if (r10 > 3) {
        r10 = 3;
    } else if (r10 < 0) {
        r10 = 0;
    }

    r8v = 0x50;
    r9v = 0;
    if (r10 > 0) {
        fullmask = 0x3ff;
        enginePtr = &gCur3DSpriteEngine;
        scale = 0x140;
        mask = fullmask - 0x200;
        kind = 0x11;
        do {
            eng = (u16 **)*enginePtr;
            a0 = (u16)(r8v & mask);
            base = eng[0];
            sh = ((u32)base[0] << 17) >> 30;
            arg2 = (u16)((fullmask & (scale >> sh)) | 0x6000);
            AddSprite(a0, 0x28, arg2, (s32)gSpriteDesc32x32, kind);

            r9v = (r9v + 1) & 0xff;
            r8v = (s16)(r8v + 0x20);
        } while (r9v < r10);
    }

skip_all:
    gCur3DSpriteEngine = saved;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma scheduling reset
