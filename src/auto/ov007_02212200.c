/* 6 functions from 0x02212200 to 0x02213150 (ov007), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
void func_ov007_02212200(M2C_UNK arg0) {
    M2C_UNK SpriteCellListSetCellRect(void *, M2C_UNK, s16, s16, s32, s32);
    void Hide3DSprite(void *);
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK InitUnitSprite(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(s32);
    u32 GetUnitSpriteWidth(void *);
    u32 GetUnitSpriteHeight(void *);
    M2C_UNK CreateUnitSpriteButtonTask(void *, M2C_UNK);
    void *CreateUnitSprite(M2C_UNK);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gMapEditorButtonSprites[];
    void *savedEngine = gCur3DSpriteEngine;
    M2C_UNK *sprites;
    s32 i;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    LoadSpriteResource(0, 2, 0x47, M2C_FIELD(g3DSpriteEngineMain, u8 **, 0x30) + 0x260);

    gMapEditorButtonSprites[0] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[0], 19, 0x150, 3, 0);
    {
        s16 y, x;
        void *sprite = (void *)gMapEditorButtonSprites[0];
        Set3DSpriteSlideTargetAndStart(sprite, 224, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            u32 width, height;
            y = M2C_FIELD(sprite, s16 *, 0x52);
            x = M2C_FIELD(sprite, s16 *, 0x50);
            width = GetUnitSpriteWidth(sprite);
            height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[0], 8);

    gMapEditorButtonSprites[1] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[1], 6, 0x160, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[1];
        Set3DSpriteSlideTargetAndStart(sprite, 192, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[1], 256);

    gMapEditorButtonSprites[2] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[2], 20, 0x170, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[2];
        Set3DSpriteSlideTargetAndStart(sprite, 160, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[2], 4);

    gMapEditorButtonSprites[3] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[3], 53, 0x180, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[3];
        Set3DSpriteSlideTargetAndStart(sprite, 0, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[3], 1);
    M2C_FIELD((void *)gMapEditorButtonSprites[3], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[4] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[4], 54, 0x190, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[4];
        Set3DSpriteSlideTargetAndStart(sprite, 32, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[4], 2);
    M2C_FIELD((void *)gMapEditorButtonSprites[4], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[5] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[5], 55, 0x1a0, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[5];
        Set3DSpriteSlideTargetAndStart(sprite, 64, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[5], 1024);
    M2C_FIELD((void *)gMapEditorButtonSprites[5], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[6] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[6], 56, 0x1b0, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[6];
        Set3DSpriteSlideTargetAndStart(sprite, 96, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[6], 2048);
    M2C_FIELD((void *)gMapEditorButtonSprites[6], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[7] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[7], 57, 0x1c0, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[7];
        Set3DSpriteSlideTargetAndStart(sprite, 128, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[7], 512);

    gMapEditorButtonSprites[8] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[8], 58, 0x1d0, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[8];
        Set3DSpriteSlideTargetAndStart(sprite, 0, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[8], 1);
    M2C_FIELD((void *)gMapEditorButtonSprites[8], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[9] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[9], 59, 0x1e0, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[9];
        Set3DSpriteSlideTargetAndStart(sprite, 32, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[9], 2);
    M2C_FIELD((void *)gMapEditorButtonSprites[9], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[10] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[10], 60, 0x1f0, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[10];
        Set3DSpriteSlideTargetAndStart(sprite, 64, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[10], 1024);
    M2C_FIELD((void *)gMapEditorButtonSprites[10], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[11] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[11], 61, 0x200, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[11];
        Set3DSpriteSlideTargetAndStart(sprite, 96, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[11], 2048);
    M2C_FIELD((void *)gMapEditorButtonSprites[11], s8 *, 0x5a) = -1;

    gMapEditorButtonSprites[12] = (M2C_UNK)CreateUnitSprite(arg0);
    InitUnitSprite((void *)gMapEditorButtonSprites[12], 62, 0x210, 3, 0);
    {
        void *sprite = (void *)gMapEditorButtonSprites[12];
        Set3DSpriteSlideTargetAndStart(sprite, 128, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            SpriteCellListSetCellRect(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    CreateUnitSpriteButtonTask((void *)gMapEditorButtonSprites[12], 512);

    sprites = gMapEditorButtonSprites;
    i = 0;
    do {
        Hide3DSprite((void *)sprites[i]);
        func_020aad18(sprites[i]);
    } while (++i < 13);
    gCur3DSpriteEngine = savedEngine;
}
#pragma opt_strength_reduction on
void func_ov007_02212cbc(void) {
    M2C_UNK DeleteUnitSprites();
    DeleteUnitSprites();
}

void func_ov007_02212cc8(M2C_UNK arg0) {
    M2C_UNK GotoSpriteAnimationLabel(M2C_UNK, M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    s32 GetMapViewHoldCount(void);
    M2C_UNK SetMapEditorTool(s32);
    s32 GetMapEditorTool(void);
    M2C_UNK func_ov007_02212dcc(void);
    extern u16 *gKeyState;
    s32 initialTimer;

    initialTimer = GetMapEditorTool();
    if (*gKeyState & 1) {
        SetMapEditorTool(0);
    }
    if (*gKeyState & 2) {
        SetMapEditorTool(1);
    }
    if (*gKeyState & 0x400) {
        SetMapEditorTool(2);
    }
    if (*gKeyState & 0x800) {
        SetMapEditorTool(3);
    }
    if (*gKeyState & 0xC0B) {
        func_ov007_02212dcc();
    }
    if (initialTimer != GetMapEditorTool()) {
        PlaySoundEffect(0x10011);
    }
    if (GetMapViewHoldCount() == 0) {
        return;
    }
    GotoSpriteAnimationLabel(arg0, 1);
}

/* Spawn the map editor's palette button screen, whose class builds and animates
 * the button sprites. */
void MapEditor_SpawnButtonScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMapEditorButtonScreenClass;
    CreateSpriteFromClass(&gMapEditorButtonScreenClass, 7);
}

void func_ov007_02212db8(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gMapEditorButtonScreenClass;
    DeleteSpriteObjectsOfClass(&gMapEditorButtonScreenClass);
}

M2C_UNK func_ov007_02212dcc(void) {
    M2C_UNK GetMapEditorMode(void);
    M2C_UNK GetMapEditorTool(void);
    extern M2C_UNK gMapEditorButtonSprites[];
    typedef struct { unsigned char value:4; } LowBits8;

    M2C_UNK r = GetMapEditorMode();

    if (r != 0) {
        if (r != 1) {
            return r;
        }

        {
            void *p = (void *)gMapEditorButtonSprites[3];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }
        {
            void *p = (void *)gMapEditorButtonSprites[4];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }
        {
            void *p = (void *)gMapEditorButtonSprites[5];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }
        {
            void *p = (void *)gMapEditorButtonSprites[6];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }

        switch (GetMapEditorTool()) {
        case 0: {
            void *p = (void *)gMapEditorButtonSprites[3];
            u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
            u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
            return;
        }
        case 1: {
            void *p = (void *)gMapEditorButtonSprites[4];
            u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
            u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
            return;
        }
        case 2: {
            void *p = (void *)gMapEditorButtonSprites[5];
            u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
            u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
            return;
        }
        case 3: {
            void *p = (void *)gMapEditorButtonSprites[6];
            u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
            u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
            return;
        }
        default:
            return;
        }
    }

    {
        void *p = (void *)gMapEditorButtonSprites[8];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }
    {
        void *p = (void *)gMapEditorButtonSprites[9];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }
    {
        void *p = (void *)gMapEditorButtonSprites[10];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }
    {
        void *p = (void *)gMapEditorButtonSprites[11];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }

    switch (GetMapEditorTool()) {
    case 0: {
        void *p = (void *)gMapEditorButtonSprites[8];
        u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
        u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
        return;
    }
    case 1: {
        void *p = (void *)gMapEditorButtonSprites[9];
        u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
        u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
        return;
    }
    case 2: {
        void *p = (void *)gMapEditorButtonSprites[10];
        u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
        u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
        return;
    }
    case 3: {
        void *p = (void *)gMapEditorButtonSprites[11];
        u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
        u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
        return;
    }
    default:
        return;
    }

    return;
}

