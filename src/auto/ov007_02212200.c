/* 6 functions from 0x02212200 to 0x02213150 (ov007), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
void func_ov007_02212200(M2C_UNK arg0) {
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    void Hide3DSprite(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK InitUnitSprite(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(s32);
    u32 GetUnitSpriteWidth(void *);
    u32 GetUnitSpriteHeight(void *);
    M2C_UNK func_020ab150(void *, M2C_UNK);
    void *func_020ab1c4(M2C_UNK);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_02221a50[];
    void *savedEngine = gCur3DSpriteEngine;
    M2C_UNK *sprites;
    s32 i;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    LoadSpriteResource(0, 2, 0x47, M2C_FIELD(g3DSpriteEngineMain, u8 **, 0x30) + 0x260);

    data_ov007_02221a50[0] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[0], 19, 0x150, 3, 0);
    {
        s16 y, x;
        void *sprite = (void *)data_ov007_02221a50[0];
        func_02088e84(sprite, 224, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            u32 width, height;
            y = M2C_FIELD(sprite, s16 *, 0x52);
            x = M2C_FIELD(sprite, s16 *, 0x50);
            width = GetUnitSpriteWidth(sprite);
            height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[0], 8);

    data_ov007_02221a50[1] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[1], 6, 0x160, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[1];
        func_02088e84(sprite, 192, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[1], 256);

    data_ov007_02221a50[2] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[2], 20, 0x170, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[2];
        func_02088e84(sprite, 160, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[2], 4);

    data_ov007_02221a50[3] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[3], 53, 0x180, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[3];
        func_02088e84(sprite, 0, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[3], 1);
    M2C_FIELD((void *)data_ov007_02221a50[3], s8 *, 0x5a) = -1;

    data_ov007_02221a50[4] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[4], 54, 0x190, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[4];
        func_02088e84(sprite, 32, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[4], 2);
    M2C_FIELD((void *)data_ov007_02221a50[4], s8 *, 0x5a) = -1;

    data_ov007_02221a50[5] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[5], 55, 0x1a0, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[5];
        func_02088e84(sprite, 64, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[5], 1024);
    M2C_FIELD((void *)data_ov007_02221a50[5], s8 *, 0x5a) = -1;

    data_ov007_02221a50[6] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[6], 56, 0x1b0, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[6];
        func_02088e84(sprite, 96, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[6], 2048);
    M2C_FIELD((void *)data_ov007_02221a50[6], s8 *, 0x5a) = -1;

    data_ov007_02221a50[7] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[7], 57, 0x1c0, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[7];
        func_02088e84(sprite, 128, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[7], 512);

    data_ov007_02221a50[8] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[8], 58, 0x1d0, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[8];
        func_02088e84(sprite, 0, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[8], 1);
    M2C_FIELD((void *)data_ov007_02221a50[8], s8 *, 0x5a) = -1;

    data_ov007_02221a50[9] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[9], 59, 0x1e0, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[9];
        func_02088e84(sprite, 32, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[9], 2);
    M2C_FIELD((void *)data_ov007_02221a50[9], s8 *, 0x5a) = -1;

    data_ov007_02221a50[10] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[10], 60, 0x1f0, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[10];
        func_02088e84(sprite, 64, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[10], 1024);
    M2C_FIELD((void *)data_ov007_02221a50[10], s8 *, 0x5a) = -1;

    data_ov007_02221a50[11] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[11], 61, 0x200, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[11];
        func_02088e84(sprite, 96, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[11], 2048);
    M2C_FIELD((void *)data_ov007_02221a50[11], s8 *, 0x5a) = -1;

    data_ov007_02221a50[12] = (M2C_UNK)func_020ab1c4(arg0);
    InitUnitSprite((void *)data_ov007_02221a50[12], 62, 0x210, 3, 0);
    {
        void *sprite = (void *)data_ov007_02221a50[12];
        func_02088e84(sprite, 128, 0x9e, 0x100, 0x9e);
        if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0)) {
            s16 y = M2C_FIELD(sprite, s16 *, 0x52);
            s16 x = M2C_FIELD(sprite, s16 *, 0x50);
            u32 width = GetUnitSpriteWidth(sprite);
            u32 height = GetUnitSpriteHeight(sprite);
            func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        }
    }
    func_020ab150((void *)data_ov007_02221a50[12], 512);

    sprites = data_ov007_02221a50;
    i = 0;
    do {
        Hide3DSprite((void *)sprites[i]);
        func_020aad18(sprites[i]);
    } while (++i < 13);
    gCur3DSpriteEngine = savedEngine;
}
#pragma opt_strength_reduction on
void func_ov007_02212cbc(void) {
    M2C_UNK func_020ab200();
    func_020ab200();
}

void func_ov007_02212cc8(M2C_UNK arg0) {
    M2C_UNK SetSpriteAnimation(M2C_UNK, M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    s32 func_020d46e8(void);
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
    if (func_020d46e8() == 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
}

void func_ov007_02212da0(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f6e8;
    CreateSpriteFromClass(&data_ov007_0221f6e8, 7);
}

void func_ov007_02212db8(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_ov007_0221f6e8;
    DeleteSpriteObjectsOfClass(&data_ov007_0221f6e8);
}

M2C_UNK func_ov007_02212dcc(void) {
    M2C_UNK GetMapEditorMode(void);
    M2C_UNK GetMapEditorTool(void);
    extern M2C_UNK data_ov007_02221a50[];
    typedef struct { unsigned char value:4; } LowBits8;

    M2C_UNK r = GetMapEditorMode();

    if (r != 0) {
        if (r != 1) {
            return r;
        }

        {
            void *p = (void *)data_ov007_02221a50[3];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }
        {
            void *p = (void *)data_ov007_02221a50[4];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }
        {
            void *p = (void *)data_ov007_02221a50[5];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }
        {
            void *p = (void *)data_ov007_02221a50[6];
            u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
        }

        switch (GetMapEditorTool()) {
        case 0: {
            void *p = (void *)data_ov007_02221a50[3];
            u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
            u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
            return;
        }
        case 1: {
            void *p = (void *)data_ov007_02221a50[4];
            u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
            u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
            return;
        }
        case 2: {
            void *p = (void *)data_ov007_02221a50[5];
            u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
            u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
            u32 f = *(u32 *)((u8 *)p + 0x40);
            f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
            *(u32 *)((u8 *)p + 0x40) = f;
            return;
        }
        case 3: {
            void *p = (void *)data_ov007_02221a50[6];
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
        void *p = (void *)data_ov007_02221a50[8];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }
    {
        void *p = (void *)data_ov007_02221a50[9];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }
    {
        void *p = (void *)data_ov007_02221a50[10];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }
    {
        void *p = (void *)data_ov007_02221a50[11];
        u16 b = (u16)(((unsigned int)M2C_FIELD(p, LowBits8 *, 0x59).value << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
    }

    switch (GetMapEditorTool()) {
    case 0: {
        void *p = (void *)data_ov007_02221a50[8];
        u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
        u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
        return;
    }
    case 1: {
        void *p = (void *)data_ov007_02221a50[9];
        u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
        u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
        return;
    }
    case 2: {
        void *p = (void *)data_ov007_02221a50[10];
        u8 b8 = M2C_FIELD(p, LowBits8 *, 0x59).value;
        u16 b = (u16)(((unsigned int)(b8 + 1) << 16) >> 16);
        u32 f = *(u32 *)((u8 *)p + 0x40);
        f = (f & ~0x3fc0000U) | (((u32)b << 24) >> 6);
        *(u32 *)((u8 *)p + 0x40) = f;
        return;
    }
    case 3: {
        void *p = (void *)data_ov007_02221a50[11];
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

