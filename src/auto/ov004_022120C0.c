/* 5 functions from 0x022120C0 to 0x02212918 (ov004), found by ds-decomp. */
#include "common.h"

typedef struct Overlay004TileTable {
    u16 entries[6];
} Overlay004TileTable;

typedef struct Overlay004ScreenFlags {
    u16 low : 4;
    u16 layer0 : 1;
    u16 layer1 : 1;
    u16 layer2 : 1;
    u16 layer3 : 1;
    u16 layer4 : 1;
    u16 high : 7;
} Overlay004ScreenFlags;

static inline void SetOverlay004Layer0(Overlay004ScreenFlags *flags) { flags->layer0 = 0; }
static inline void SetOverlay004Layer1(Overlay004ScreenFlags *flags) { flags->layer1 = 0; }
static inline void SetOverlay004Layer2(Overlay004ScreenFlags *flags) { flags->layer2 = 0; }
static inline void SetOverlay004Layer3(Overlay004ScreenFlags *flags) { flags->layer3 = 1; }
static inline void SetOverlay004Layer4(Overlay004ScreenFlags *flags) { flags->layer4 = 0; }
static inline s32 SpriteTile124(s32 tile) { extern s32 gCur3DSpriteEngine; return (tile >> ((u32)(*(u16 *)*(void **)gCur3DSpriteEngine <<17)>>30))&1023; }

#pragma opt_propagation off
void func_ov004_022120c0(void *arg0) {
    M2C_UNK Apply3DSpriteLayout();
    M2C_UNK SetFileDirectory();
    M2C_UNK LoadDecompressedFileTo();
    M2C_UNK LoadFileToBGExtPltt();
    M2C_UNK LoadFileToSpriteBuffer();
    M2C_UNK MI_CpuCopy32();
    M2C_UNK StringFormat();
    M2C_UNK OpenNarcArchive();
    M2C_UNK GetLocalizedFileName();
    M2C_UNK LoadNarcFileDecompressed();
    M2C_UNK OffsetTileIndices();
    M2C_UNK CloseNarcArchive();
    M2C_UNK ApplyScreenMode(s32);
    M2C_UNK CreatePaletteFadeSprite();
    M2C_UNK FillPaletteFadeFrom();
    M2C_UNK CapturePaletteFadeTarget();
    M2C_UNK StartPaletteFadeIn();
    M2C_UNK func_020a8a84();
    M2C_UNK Ov004_PlayStageBattleMusic();

    extern const Overlay004TileTable data_ov004_02218bb8;
    extern M2C_UNK data_ov004_02218df8;
    extern M2C_UNK data_ov004_02218e04;
    extern M2C_UNK data_ov004_02218e0c;
    extern M2C_UNK data_ov004_02218e14;
    extern M2C_UNK data_ov004_02218e1c;
    extern M2C_UNK data_ov004_02218e24;
    extern M2C_UNK data_ov004_02218e34;
    extern M2C_UNK data_ov004_02218e44;
    extern M2C_UNK data_ov004_02218e4c;
    extern M2C_UNK data_ov004_02218e5c;
    extern M2C_UNK data_ov004_02218e64;
    extern M2C_UNK data_ov004_02218e70;
    extern s32 gCurrentMap;
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;

    
    u8 *bp;
    s32 i;

    Overlay004TileTable tmp;
    u8 buf[0x20];
    s32 oldEngine;
    s32 e;
    s32 map;
    s32 inner;
    u16 v;
    u8 res;

    tmp = data_ov004_02218bb8;

    map = gCurrentMap;
    inner = *(s32 *)map;
    inner = inner + 0x5100;
    v = *(u16 *)(inner + 0x42);
    res = (u8)func_020a8a84(v);
    *((u8 *)arg0 + 0x3a) = res;

    oldEngine = gCur3DSpriteEngine;
    bp = buf;

    i = 0;
    do {
        if (i == 0) {
            e = g3DSpriteEngineMain;
        } else {
            e = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = e;
        if (e == g3DSpriteEngineSub) {
            Apply3DSpriteLayout(&tmp);
            SetFileDirectory(&data_ov004_02218df8);
            LoadDecompressedFileTo(&data_ov004_02218e04, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
            LoadDecompressedFileTo(&data_ov004_02218e0c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2c));
            LoadFileToBGExtPltt(&data_ov004_02218e14, 3, 0, 0x200);
            LoadFileToSpriteBuffer(&data_ov004_02218e1c, 0, 0x20);
            MI_CpuCopy32(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x20, 0x20);
            StringFormat(bp, &data_ov004_02218e24, *((u8 *)arg0 + 0x3a));
            OpenNarcArchive(bp);
            StringFormat(bp, &data_ov004_02218e34, *((u8 *)arg0 + 0x3a));
            LoadNarcFileDecompressed(GetLocalizedFileName(bp), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10) + 0x20);
            LoadDecompressedFileTo(&data_ov004_02218e44, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x100, 1);
            StringFormat(bp, &data_ov004_02218e4c, *((u8 *)arg0 + 0x3a));
            LoadNarcFileDecompressed(GetLocalizedFileName(bp), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14) + 0x20);
            LoadDecompressedFileTo(&data_ov004_02218e5c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
            OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 0x100, 0x1001);
            CloseNarcArchive();
            LoadDecompressedFileTo(GetLocalizedFileName(&data_ov004_02218e64), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c));
            LoadFileToSpriteBuffer(&data_ov004_02218e70, 0x200, 0x20);

            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x01;
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x02;
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x04;
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x08;

            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x38) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x40) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x3a) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x42) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x3c) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x44) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x3e) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x46) = 0;

            SetOverlay004Layer0(*(Overlay004ScreenFlags **)gCur3DSpriteEngine);
            SetOverlay004Layer1(*(Overlay004ScreenFlags **)gCur3DSpriteEngine);
            SetOverlay004Layer2(*(Overlay004ScreenFlags **)gCur3DSpriteEngine);
            SetOverlay004Layer3(*(Overlay004ScreenFlags **)gCur3DSpriteEngine);
            SetOverlay004Layer4(*(Overlay004ScreenFlags **)gCur3DSpriteEngine);

            ApplyScreenMode(0);

            M2C_FIELD(arg0, void **, 0x40) = (void *)CreatePaletteFadeSprite(arg0);
            M2C_FIELD((void *)M2C_FIELD(arg0, void **, 0x40), u8 *, 0x34) = 0;
            FillPaletteFadeFrom(M2C_FIELD(arg0, void **, 0x40), 0);
            CapturePaletteFadeTarget(M2C_FIELD(arg0, void **, 0x40), 0);
            StartPaletteFadeIn(M2C_FIELD(arg0, void **, 0x40), 0);

            M2C_FIELD(arg0, void **, 0x44) = (void *)CreatePaletteFadeSprite(arg0);
            M2C_FIELD((void *)M2C_FIELD(arg0, void **, 0x44), u8 *, 0x34) = 1;
            FillPaletteFadeFrom(M2C_FIELD(arg0, void **, 0x44), 0);
            CapturePaletteFadeTarget(M2C_FIELD(arg0, void **, 0x44), 1);
            StartPaletteFadeIn(M2C_FIELD(arg0, void **, 0x44), 0);
        }
        ++i;
    } while (i < 2);

    gCur3DSpriteEngine = oldEngine;

    M2C_FIELD(arg0, u16 *, 0x34) = 0;
    M2C_FIELD(arg0, u16 *, 0x36) = 0;
    M2C_FIELD(arg0, u8 *, 0x3b) = 0;
    M2C_FIELD(arg0, u8 *, 0x3c) = 0;
    M2C_FIELD(arg0, u8 *, 0x3d) = 0;
    M2C_FIELD(arg0, u16 *, 0x38) = 0;

    Ov004_PlayStageBattleMusic(arg0);
}
#pragma opt_propagation reset
/* Draws the two-digit day counter at (x, y): two 32x16 icon tiles from
 * gSpriteDesc32x16, then the tens and ones digits (tiles 22..31) from
 * gSpriteDesc8x16, all shifted up by tileBase. */
void func_ov004_022124e0(s32 x,s32 y,s32 tileBase,s32 value) {
void AddSprite(u16,u16,u16,void *,s32);extern s32 gCur3DSpriteEngine;extern M2C_UNK gSpriteDesc32x16,gSpriteDesc8x16;
AddSprite((u16)x,(u16)y,(u16)(tileBase+SpriteTile124(14)),&gSpriteDesc32x16,11);
AddSprite((u16)(x+32),(u16)y,(u16)(tileBase+SpriteTile124(18)),&gSpriteDesc32x16,11);
AddSprite((u16)(x+64),(u16)y,(u16)(tileBase+SpriteTile124(value/10+22)),&gSpriteDesc8x16,11);
AddSprite((u16)(x+72),(u16)y,(u16)(tileBase+SpriteTile124(value%10+22)),&gSpriteDesc8x16,11);
}

/* Draws a horizontal bar of six 32x16 tiles at (x, y): tiles [0,4,8] then the
 * mirrored [8,4,0] (the right half flagged with 0x1000 and shifted back), so a
 * bar is the top or bottom edge of the opening window frame. */
void DrawWindowFrameBar(s32 x, s32 y, s32 tileBase)
{
  void AddSprite(u16, u16, u16, void *, s32);
  extern M2C_UNK gSpriteDesc32x16;
  AddSprite((u16) x, (u16) y, (u16) tileBase, &gSpriteDesc32x16, 11);
  AddSprite((u16) (x + 32), (u16) y, (u16) (tileBase + SpriteTile124(4)), &gSpriteDesc32x16, 11);
  AddSprite((u16) (x + 64), (u16) y, (u16) (tileBase + SpriteTile124(8)), &gSpriteDesc32x16, 11);
  AddSprite((u16)((x + 96) | 4096), (u16) y, (u16) (tileBase + SpriteTile124(8)), &gSpriteDesc32x16, 11);
  AddSprite((u16) ((x + 128) | 4096), (u16) y, (u16) (tileBase + SpriteTile124(4)), &gSpriteDesc32x16, 11);
  x = (x+160)|4096;
  AddSprite((u16)x,(u16)y,(u16)tileBase,&gSpriteDesc32x16,11);
}

/* Reset the sprite bank state of the sub 3D engine (Reset3DSpriteBankState acts
 * on whatever gCur3DSpriteEngine points at), then restore the engine that was
 * current.  The loop visits both engines but only the sub engine is reset. */
void ResetSub3DSpriteBankState(void) {
    M2C_UNK Reset3DSpriteBankState();
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 savedEngine;
    s32 engine;
    s32 i;

    savedEngine = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        if (engine == g3DSpriteEngineSub) {
            Reset3DSpriteBankState();
        }
        i += 1;
    } while (i < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Per-frame wait: once a button or the touch screen is pressed, or after 900
 * frames, resume the object's sprite animation. */
void WaitForInputOrTimeout(void *state) {
    M2C_UNK Sprite_ResumeAnimation();
    extern u16 *gKeyState;
    extern void *gTouchState;
    u16 frames;

    if ((*gKeyState & 0xC0B) || (M2C_FIELD(gTouchState, u8 *, 0x14) != 0)) {
        Sprite_ResumeAnimation();
        return;
    }
    frames = M2C_FIELD(state, u16 *, 0x38);
    if ((u32) frames < 0x384U) {
        M2C_FIELD(state, u16 *, 0x38) = (u16) (frames + 1);
        return;
    }
    Sprite_ResumeAnimation();
}

