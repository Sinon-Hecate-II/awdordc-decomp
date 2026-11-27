/* 81 functions from 0x022056BC to 0x022066A8 (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_menu.h"
#include "ov003_scene.h"
#include "battle_map.h"

extern void **gCurrentMap;

typedef union ObjFlags3A {
    u8 raw;
    struct {
        u8 lo : 6;
        u8 mid : 1;
        u8 hi : 1;
    } b;
} ObjFlags3A;

typedef union ObjFlags20 {
    u8 raw;
    struct {
        u8 b0 : 1;
        u8 b1 : 4;
        u8 b2 : 3;
    } b;
} ObjFlags20;

#pragma opt_strength_reduction off
void func_ov003_022056bc(M2C_UNK arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    M2C_UNK ConstructArray(M2C_UNK **, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK **MemAlloc(M2C_UNK);
    M2C_UNK Link_SendPacket(M2C_UNK **, M2C_UNK);
    M2C_UNK ReadActivePlayerRecord(M2C_UNK, M2C_UNK **, M2C_UNK);
    M2C_UNK Link_FlushSend();
    M2C_UNK SetOv003SceneClass(M2C_UNK *);
    s32 IsSessionHostAlt();
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK data_ov003_02210544;
    extern M2C_UNK gSceneDisplayGroupVTable;
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    extern M2C_UNK InitOv003OptionValue;
    extern M2C_UNK Ov003OptionValue_Destructor;
    void *temp_r0;
    M2C_UNK **temp_r2;
    M2C_UNK **temp_r0_2;
    M2C_UNK **temp_r0_3;
    M2C_UNK **temp_r0_4;
    M2C_UNK **temp_r0_5;
    M2C_UNK **temp_r0_6;
    M2C_UNK **temp_r0_7;
    s32 var_r3;
    u8 var_r1;
    u8 var_r2;
    u8 var_r3_2;

    SetOv003SceneClass(&data_ov003_02210544);
    temp_r0 = CreateSpriteFromClass(&data_ov003_02210544, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gSceneBaseVTable;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &gSceneBaseIfaceVTable;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_022108b4;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_022108e0;
    M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x39) = 0;
    M2C_FIELD(temp_r0, ObjFlags3A *, 0x3A).b.lo = 0;
    M2C_FIELD(temp_r0, ObjFlags3A *, 0x3A).b.mid = 0;
    M2C_FIELD(temp_r0, ObjFlags3A *, 0x3A).b.hi = 0;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = NULL;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = NULL;
    M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
    temp_r0_2 = MemAlloc(0x12);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = temp_r0_2;
    temp_r0_3 = MemAlloc(0x12);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(temp_r0_3, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_3, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_3, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_3, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_3, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_3, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_3, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_3, u16 *, 2) = (u16) M2C_FIELD(temp_r0_3, u16 *, 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = temp_r0_3;
    temp_r0_4 = MemAlloc(0x48);
    if (temp_r0_4 != NULL) {
        var_r1 = 0;
        M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = NULL;
        M2C_FIELD(temp_r0_4, s32 *, 4) = 0;
        do {
            temp_r2 = &temp_r0_4[var_r1];
            M2C_FIELD(temp_r2, s32 *, 8) = 0;
            M2C_FIELD(temp_r2, s32 *, 0x28) = 0;
            var_r1 += 1;
        } while ((u32) var_r1 < 8U);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_4;
    temp_r0_5 = MemAlloc(0x34);
    if (temp_r0_5 != NULL) {
        var_r3 = 0;
        *temp_r0_5 = &gSceneDisplayGroupVTable;
        do {
            M2C_FIELD(temp_r0_5 + var_r3, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r0_5 + var_r3, s32 *, 0x24) = 0;
            var_r3 += 1;
        } while (var_r3 < 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = temp_r0_5;
    temp_r0_6 = MemAlloc(0x134);
    if (temp_r0_6 != NULL) {
        M2C_FIELD(temp_r0_6, M2C_UNK **, 0) = &data_ov003_02210764;
        M2C_FIELD(temp_r0_6, s8 *, 4) = -1;
        M2C_FIELD(temp_r0_6, s8 *, 5) = -1;
        M2C_FIELD(temp_r0_6, s8 *, 6) = 0;
        ConstructArray((M2C_UNK **) ((u8 *) temp_r0_6 + 8), 8, 0x18, &InitOv003OptionValue, &Ov003OptionValue_Destructor);
        var_r2 = 0;
        M2C_FIELD(temp_r0_6, s32 *, 0x10C) = 0;
        do {
            M2C_FIELD(temp_r0_6 + var_r2, s32 *, 0xC8) = 0;
            var_r2 += 1;
        } while ((u32) var_r2 < 8U);
        var_r3_2 = 0;
        do {
            M2C_FIELD(temp_r0_6 + var_r3_2, s32 *, 0xE8) = 0;
            var_r3_2 += 1;
        } while ((u32) var_r3_2 < 9U);
        if (IsSessionHostAlt() != 0) {
            ReadActivePlayerRecord(0, (M2C_UNK **) ((u8 *) temp_r0_6 + 0x110), 0x24);
            M2C_FIELD(temp_r0_6, s32 *, 0x110) = 0;
            Link_SendPacket((M2C_UNK **) ((u8 *) temp_r0_6 + 0x110), 0x24);
            Link_FlushSend();
        }
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = temp_r0_6;
    temp_r0_7 = MemAlloc(0x2C);
    if (temp_r0_7 != NULL) {
        M2C_FIELD(temp_r0_7, M2C_UNK **, 0) = &gHeapObjectVTable;
        M2C_FIELD(temp_r0_7, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_7, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_7, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_7, ObjFlags20 *, 0x20).b.b0 = 0;
        M2C_FIELD(temp_r0_7, ObjFlags20 *, 0x20).b.b1 = 0;
        M2C_FIELD(temp_r0_7, ObjFlags20 *, 0x20).b.b2 = 2;
        M2C_FIELD(temp_r0_7, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_7, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_7, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_7, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_7, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = temp_r0_7;
}
#pragma opt_strength_reduction off
void func_ov003_022059d0(M2C_UNK arg0) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK ConstructArray(M2C_UNK **, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK **MemAlloc(M2C_UNK);
    M2C_UNK Link_SendPacket(M2C_UNK **, M2C_UNK);
    M2C_UNK ReadActivePlayerRecord(M2C_UNK, M2C_UNK **, M2C_UNK);
    M2C_UNK Link_FlushSend();
    s32 IsSessionHostAlt();
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK data_ov003_02210544;
    extern M2C_UNK gSceneDisplayGroupVTable;
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    extern M2C_UNK InitOv003OptionValue;
    extern M2C_UNK Ov003OptionValue_Destructor;
    void *temp_r0;
    M2C_UNK **temp_r0_2;
    M2C_UNK **temp_r0_3;
    u8 var_r1;
    M2C_UNK **temp_r0_5;
    M2C_UNK **temp_r0_6;
    M2C_UNK **temp_r0_7;
    s32 var_r3;
    M2C_UNK **temp_r0_4;
    u8 var_r2;
    u8 var_r3_2;

    temp_r0 = CreateSpriteObject(&data_ov003_02210544, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gSceneBaseVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &gSceneBaseIfaceVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_022108b4;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_022108e0;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x39) = 0;
        M2C_FIELD(temp_r0, ObjFlags3A *, 0x3A).b.lo = 0;
        M2C_FIELD(temp_r0, ObjFlags3A *, 0x3A).b.mid = 0;
        M2C_FIELD(temp_r0, ObjFlags3A *, 0x3A).b.hi = 0;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        temp_r0_2 = MemAlloc(0x12);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = temp_r0_2;
        temp_r0_3 = MemAlloc(0x12);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_3, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_3, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_3, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_3, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_3, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_3, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_3, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_3, u16 *, 2) = (u16) M2C_FIELD(temp_r0_3, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = temp_r0_3;
        temp_r0_4 = MemAlloc(0x48);
        if (temp_r0_4 != NULL) {
            var_r1 = 0;
            M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = NULL;
            M2C_FIELD(temp_r0_4, s32 *, 4) = 0;
            do {
                M2C_FIELD(temp_r0_4 + var_r1, s32 *, 8) = 0;
                M2C_FIELD(temp_r0_4 + var_r1, s32 *, 0x28) = 0;
                var_r1 += 1;
            } while ((u32) var_r1 < 8U);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_4;
        temp_r0_5 = MemAlloc(0x34);
        if (temp_r0_5 != NULL) {
            var_r3 = 0;
            *temp_r0_5 = &gSceneDisplayGroupVTable;
            do {
                M2C_FIELD(temp_r0_5 + var_r3, s32 *, 0x14) = 0;
                M2C_FIELD(temp_r0_5 + var_r3, s32 *, 0x24) = 0;
                var_r3 += 1;
            } while (var_r3 < 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = temp_r0_5;
        temp_r0_6 = MemAlloc(0x134);
        if (temp_r0_6 != NULL) {
            M2C_FIELD(temp_r0_6, M2C_UNK **, 0) = &data_ov003_02210764;
            M2C_FIELD(temp_r0_6, s8 *, 4) = -1;
            M2C_FIELD(temp_r0_6, s8 *, 5) = -1;
            M2C_FIELD(temp_r0_6, s8 *, 6) = 0;
            ConstructArray((M2C_UNK **) ((u8 *) temp_r0_6 + 8), 8, 0x18, &InitOv003OptionValue, &Ov003OptionValue_Destructor);
            var_r2 = 0;
            M2C_FIELD(temp_r0_6, s32 *, 0x10C) = 0;
            do {
                M2C_FIELD(temp_r0_6 + var_r2, s32 *, 0xC8) = 0;
                var_r2 += 1;
            } while ((u32) var_r2 < 8U);
            var_r3_2 = 0;
            do {
                M2C_FIELD(temp_r0_6 + var_r3_2, s32 *, 0xE8) = 0;
                var_r3_2 += 1;
            } while ((u32) var_r3_2 < 9U);
            if (IsSessionHostAlt() != 0) {
                ReadActivePlayerRecord(0, (M2C_UNK **) ((u8 *) temp_r0_6 + 0x110), 0x24);
                M2C_FIELD(temp_r0_6, s32 *, 0x110) = 0;
                Link_SendPacket((M2C_UNK **) ((u8 *) temp_r0_6 + 0x110), 0x24);
                Link_FlushSend();
            }
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = temp_r0_6;
        temp_r0_7 = MemAlloc(0x2C);
        if (temp_r0_7 != NULL) {
            M2C_FIELD(temp_r0_7, M2C_UNK **, 0) = &gHeapObjectVTable;
            M2C_FIELD(temp_r0_7, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_7, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_7, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_7, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_7, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_7, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_7, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_7, ObjFlags20 *, 0x20).b.b0 = 0;
            M2C_FIELD(temp_r0_7, ObjFlags20 *, 0x20).b.b1 = 0;
            M2C_FIELD(temp_r0_7, ObjFlags20 *, 0x20).b.b2 = 2;
            M2C_FIELD(temp_r0_7, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_7, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_7, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_7, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_7, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = temp_r0_7;
    }
    M2C_FIELD(temp_r0, ObjFlags3A *, 0x3A).b.lo = 1;
}
/* Non-deleting destructor of a derived ov003 scene object (vtable slot 0):
 * restores both of its vtables, frees its cursor blocks (+0x3C/+0x48), its
 * sprite-handle block (+0x40: 2 + 8 + 8 handles) and its child objects
 * (+0x44/+0x50/+0x54), deletes the remaining sprites, marks the scene finished
 * and, for the wallpaper variant, deletes the wallpaper sprites.  The caller
 * still owns obj. */
void *ShutdownOv003SceneObject(void *obj) {
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK DeleteMainWallpaperSprites(void);
    M2C_UNK MemFree(void *);
    M2C_UNK SetOv003SceneState(M2C_UNK);
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    void *spriteBlock;
    void **child50;
    void **child44;
    void **child54;
    u8 i;
    s32 usesWallpaper;

    M2C_FIELD(obj, M2C_UNK **, 0) = &data_ov003_022108b4;
    M2C_FIELD(obj, M2C_UNK **, 0x34) = &data_ov003_022108e0;
    if (M2C_FIELD(obj, s32 *, 0x3C) != 0) {
        MemFree(M2C_FIELD(obj, s32 *, 0x3C));
    }
    if (M2C_FIELD(obj, s32 *, 0x48) != 0) {
        MemFree(M2C_FIELD(obj, s32 *, 0x48));
    }
    spriteBlock = M2C_FIELD(obj, void **, 0x40);
    if (spriteBlock != NULL) {
        if (M2C_FIELD(spriteBlock, s32 *, 0) != 0) {
            DeleteSpriteObject(M2C_FIELD(spriteBlock, s32 *, 0));
        }
        if (M2C_FIELD(spriteBlock, s32 *, 4) != 0) {
            DeleteSpriteObject(M2C_FIELD(spriteBlock, s32 *, 4));
        }
        i = 0;
        do {
            if (M2C_FIELD(spriteBlock + (i * 4), s32 *, 8) != 0) {
                DeleteSpriteObject(M2C_FIELD(spriteBlock + (i * 4), s32 *, 8));
            }
            if (M2C_FIELD((u8 *)spriteBlock + ((s32)i << 2), s32 *, 0x28) != 0) {
                DeleteSpriteObject(M2C_FIELD((u8 *)spriteBlock + ((s32)i << 2), s32 *, 0x28));
            }
            i += 1;
        } while (i < 8U);
        MemFree(spriteBlock);
    }
    child50 = M2C_FIELD(obj, void ***, 0x50);
    if (child50 != NULL) {
        M2C_FIELD(*child50, void (**)(void *), 4)(child50);
    }
    child44 = M2C_FIELD(obj, void ***, 0x44);
    if (child44 != NULL) {
        M2C_FIELD(*child44, void (**)(void *), 4)(child44);
    }
    child54 = M2C_FIELD(obj, void ***, 0x54);
    if (child54 != NULL) {
        M2C_FIELD(*child54, void (**)(void *), 4)(child54);
    }
    if (M2C_FIELD(obj, s32 *, 0x4C) != 0) {
        DeleteSpriteObject(M2C_FIELD(obj, s32 *, 0x4C));
    }
    if (M2C_FIELD(obj, s32 *, 0x58) != 0) {
        DeleteSpriteObject(M2C_FIELD(obj, s32 *, 0x58));
    }
    SetOv003SceneState(4);
    if (M2C_FIELD(obj, ObjFlags3A *, 0x3A).b.lo == 1) {
        usesWallpaper = 1;
    } else {
        usesWallpaper = 0;
    }
    if (usesWallpaper & 0xFF) {
        DeleteMainWallpaperSprites();
    }
    return obj;
}

/* Deleting destructor of the scene display's sprite group (the object at
 * SCENE_DISPLAY_GROUP, class gSceneDisplayGroupVTable): restore its class
 * vtable, delete its second and third runs of four sprites and free it.  The
 * first run is owned elsewhere. */
SceneDisplayGroup *DestroySceneDisplayGroup(SceneDisplayGroup *group) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DeleteAllFaceChildren();
    M2C_UNK MemFree();
    extern M2C_UNK gSceneDisplayGroupVTable;
    register s32 i;

    group->vtable = &gSceneDisplayGroupVTable;
    DeleteAllFaceChildren();
    i = 0;
    do {
        if (group->sprites[i + 4] != 0) {
            DeleteSpriteObject(group->sprites[i + 4]);
        }
        if (group->sprites[i + 8] != 0) {
            DeleteSpriteObject(group->sprites[i + 8]);
        }
        i += 1;
    } while (i < 4);
    MemFree(group);
    return group;
}

/* Deleting destructor of the ov003 options object (vtable slot 1): restores the
 * base class's vtable, destroys the eight option rows through their own
 * destructors, deletes the nine sprites it owns, destroys the option-counter
 * array at +0x08 and frees the object. */
Ov003OptionsObject *DestroyOv003OptionsObject(Ov003OptionsObject *options) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DestroyArray(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    M2C_UNK MemFree();
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK Ov003OptionValue_Destructor;
    u8 i;
    M2C_UNK *row;

    options->vtable = &data_ov003_02210764;
    i = 0;
    do {
        row = options->rows[i];
        if (row != NULL) {
            M2C_FIELD(*row, void (**)(M2C_UNK *), 0x4)(row);
        }
        i += 1;
    } while (i < 8);
    i = 0;
    do {
        if (options->sprites[i] != 0) {
            DeleteSpriteObject(options->sprites[i]);
        }
        i += 1;
    } while (i < 9);
    DestroyArray((u8 *)options + 8, 8, 0x18, &Ov003OptionValue_Destructor);
    MemFree(options);
    return options;
}

#pragma opt_common_subs off
/* Deleting destructor of an ov003 scene object (vtable slot 1): restores both
 * of its vtables, frees its cursor structs (+0x3C/+0x48), its sprite-handle
 * blocks (+0x40: 2 + 8 + 8 sprites, +0x44/+0x50/+0x54: child objects), deletes
 * the remaining sprites, marks the scene finished and frees the object. */
void *DestroyOv003SceneObject(void *obj) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DeleteMainWallpaperSprites();
    M2C_UNK MemFree();
    M2C_UNK SetOv003SceneState(M2C_UNK);
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    void *spriteBlock;
    void **child50;
    void **child44;
    void **child54;
    u8 i;
    s32 usesWallpaper;

    M2C_FIELD(obj, M2C_UNK **, 0x0) = &data_ov003_022108b4;
    M2C_FIELD(obj, M2C_UNK **, 0x34) = &data_ov003_022108e0;
    if (M2C_FIELD(obj, s32 *, 0x3C) != 0) {
        MemFree(M2C_FIELD(obj, s32 *, 0x3C));
    }
    if (M2C_FIELD(obj, s32 *, 0x48) != 0) {
        MemFree(M2C_FIELD(obj, s32 *, 0x48));
    }
    spriteBlock = M2C_FIELD(obj, void **, 0x40);
    if (spriteBlock != NULL) {
        if (M2C_FIELD(spriteBlock, s32 *, 0) != 0) {
            DeleteSpriteObject(M2C_FIELD(spriteBlock, s32 *, 0));
        }
        if (M2C_FIELD(spriteBlock, s32 *, 4) != 0) {
            DeleteSpriteObject(M2C_FIELD(spriteBlock, s32 *, 4));
        }
        i = 0;
        do {
            if (M2C_FIELD(spriteBlock + (i * 4), s32 *, 8) != 0) {
                DeleteSpriteObject(M2C_FIELD(spriteBlock + (i * 4), s32 *, 8));
            }
            if (M2C_FIELD(spriteBlock + (i * 4), s32 *, 0x28) != 0) {
                DeleteSpriteObject(M2C_FIELD(spriteBlock + (i * 4), s32 *, 0x28));
            }
            ++i;
        } while (i < 8U);
        MemFree(spriteBlock);
    }
    child50 = M2C_FIELD(obj, void ***, 0x50);
    if (child50 != NULL) {
        M2C_FIELD(*child50, void (**)(void *), 4)(child50);
    }
    child44 = M2C_FIELD(obj, void ***, 0x44);
    if (child44 != NULL) {
        M2C_FIELD(*child44, void (**)(void *), 4)(child44);
    }
    child54 = M2C_FIELD(obj, void ***, 0x54);
    if (child54 != NULL) {
        M2C_FIELD(*child54, void (**)(void *), 4)(child54);
    }
    if (M2C_FIELD(obj, s32 *, 0x4C) != 0) {
        DeleteSpriteObject(M2C_FIELD(obj, s32 *, 0x4C));
    }
    if (M2C_FIELD(obj, s32 *, 0x58) != 0) {
        DeleteSpriteObject(M2C_FIELD(obj, s32 *, 0x58));
    }
    SetOv003SceneState(4);
    if (M2C_FIELD(obj, ObjFlags3A *, 0x3A).b.lo == 1) {
        usesWallpaper = 1;
    } else {
        usesWallpaper = 0;
    }
    if (usesWallpaper & 0xFF) {
        DeleteMainWallpaperSprites();
    }
    MemFree(obj);
    return obj;
}
#pragma opt_common_subs reset
/* Non-deleting destructor of the scene display's sprite group (the object at
 * SCENE_DISPLAY_GROUP, class gSceneDisplayGroupVTable): restore its class vtable
 * and release its second and third runs of four sprites (the first run is owned
 * elsewhere); DestroySceneDisplayGroup frees the group afterwards. */
SceneDisplayGroup *SceneDisplayGroup_Destructor(SceneDisplayGroup *group) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DeleteAllFaceChildren();
    extern M2C_UNK gSceneDisplayGroupVTable;
    register s32 i;

    group->vtable = &gSceneDisplayGroupVTable;
    DeleteAllFaceChildren();
    i = 0;
    do {
        if (group->sprites[i + 4] != 0) {
            DeleteSpriteObject(group->sprites[i + 4]);
        }
        if (group->sprites[i + 8] != 0) {
            DeleteSpriteObject(group->sprites[i + 8]);
        }
        i += 1;
    } while (i < 4);
    return group;
}

/* Destructor of the ov003 options object (vtable slot 0): restore the class
 * vtable, run the destructor of each of the eight option rows, delete the nine
 * sprites the object owns and destroy the eight option counters. The object
 * itself stays allocated; the deleting destructor frees it. */
Ov003OptionsObject *Ov003OptionsObject_Destructor(Ov003OptionsObject *options) {
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK DestroyArray(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK Ov003OptionValue_Destructor;
    u8 i;
    M2C_UNK *p;

    options->vtable = &data_ov003_02210764;
    i = 0;
    do {
        p = options->rows[i];
        if (p) M2C_FIELD(*p, void (**)(void *), 4)(p);
        i++;
    } while (i < 8);
    i = 0;
    do {
        p = options->sprites[i];
        if (p) DeleteSpriteObject(p);
        i++;
    } while (i < 9);
    DestroyArray((u8 *)options + 8, 8, 0x18, &Ov003OptionValue_Destructor);
    return options;
}

s32 func_ov003_02206160(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Turn the battle config's value flag on or off from option value `enabled`
 * (gMapConfig flags bit 8, the bit saved as MAP_SETTINGS_VALUE_FLAG).  The
 * options row itself is the unused first argument. */
void SetMapConfigValueFlag(M2C_UNK unused, s32 enabled) {
    extern M2C_UNK gMapConfig;
    u16 flags;
    flags = M2C_FIELD(&gMapConfig, u16 *, 0);
    flags = (u16)((flags & ~MAPCONFIG_VALUE_FLAG) | (((u32)(u16)enabled << 31) >> 23));
    M2C_FIELD(&gMapConfig, u16 *, 0) = flags;
}

/* Whether the battle config's value flag is on: bit 8 of the gMapConfig rule
 * flags (MAPCONFIG_VALUE_FLAG), the bit MapSettings saves as its value flag. */
s32 GetMapConfigValueFlag(void) {
    extern M2C_UNK gMapConfig;

    return (s32) ((u32) (M2C_FIELD(&gMapConfig, u16 *, MAPCONFIG_FLAGS) << 23) >> 31);
}

s32 func_ov003_022061b4(void) {
    return 1;
}

s32 func_ov003_022061bc(void) {
    return 1;
}

s32 func_ov003_022061c4(void) {
    return 1;
}

s32 func_ov003_022061cc(void) {
    return 0;
}

void func_ov003_022061d4(void) {

}

s32 func_ov003_022061d8(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Set the map config's config flags from the low three bits of option value
 * `flags`: the four-choice setup setting that MapSettings saves in its rules
 * word (bits 28..30, MAP_SETTINGS_FLAGS).  The options row is the unused first
 * argument. */
void SetMapConfigFlags(M2C_UNK unused, s32 flags) {
    extern M2C_UNK gMapConfig;
    u16 v;

    v = M2C_FIELD(&gMapConfig, u16 *, MAPCONFIG_FLAGS);
    v = (u16)((v & ~MAPCONFIG_CONFIG_FLAGS) | (((u32)(u16)flags << 29) >> 26));
    M2C_FIELD(&gMapConfig, u16 *, MAPCONFIG_FLAGS) = v;
}

/* Read back the battle config's three flag bits (gMapConfig flags bits 3..5,
 * saved in MapSettings.rules bits 28..30): values 0..3 are meaningful and a
 * larger value reads as 0. */
s32 GetMapConfigFlags(void) {
    extern M2C_UNK gMapConfig;

    switch ((u8)(((u32) M2C_FIELD(&gMapConfig, u16 *, 0) << 26) >> 29)) {
    case 2: return 2;
    case 1: return 1;
    case 3: return 3;
    case 0: return 0;
    default: return 0;
    }
}

s32 func_ov003_02206270(void) {
    return 1;
}

s32 func_ov003_02206278(void) {
    return 1;
}

s32 func_ov003_02206280(void) {
    return 3;
}

s32 func_ov003_02206288(void) {
    return 0;
}

void func_ov003_02206290(void) {

}

s32 func_ov003_02206294(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov003_022062a8(s32 arg0, s16 arg1) {
    extern M2C_UNK gMapConfig;
    M2C_FIELD(&gMapConfig, s16 *, 0x6) = arg1;
}

u16 func_ov003_022062b8(void) {
    extern M2C_UNK gMapConfig;
    return M2C_FIELD(&gMapConfig, u16 *, 6);
}

s32 func_ov003_022062c8(void) {
    return 0;
}

s32 func_ov003_022062d0(void) {
    return 0x1F4;
}

s32 func_ov003_022062d8(void) {
    return 0x251C;
}

s32 func_ov003_022062e4(void) {
    return 0;
}

void func_ov003_022062ec(void) {

}

s32 func_ov003_022062f0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov003_02206304(M2C_UNK arg0, s32 arg1) {
    extern M2C_UNK gMapConfig;
    M2C_FIELD(&gMapConfig, s32 *, 0x8) = arg1;
}

s32 func_ov003_02206314(void) {
    extern M2C_UNK gMapConfig;
    return M2C_FIELD(&gMapConfig, s32 *, 8);
}

s32 func_ov003_02206324(void) {
    return 0;
}

s32 func_ov003_0220632c(void) {
    return 0x3E8;
}

s32 func_ov003_02206334(void) {
    return 0x182B8;
}

s32 func_ov003_02206340(void) {
    return 0;
}

void func_ov003_02206348(void) {

}

s32 func_ov003_0220634c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Set the battle's additional setting (gMapConfig byte 3); the default setting
 * 4 is stored as 0, which the getter maps back to 4. */
void Ov003_SetBattleSetting(s32 self, s32 setting) {
    extern s32 gMapConfig;

    if (setting == 4) setting = 0;
    ((u8 *)&gMapConfig)[MAPCONFIG_BATTLE_SETTING] = (u8)setting;
}

/* Return the battle's additional setting (gMapConfig byte 3); the stored default
 * 0 maps to setting 4. */
s32 Ov003_GetBattleSetting(void) {
    extern s32 gMapConfig;
    u8 setting = * (u8 *)((char *)&gMapConfig + MAPCONFIG_BATTLE_SETTING);
    if (setting == 0) return 4;
    return setting;
}

s32 func_ov003_02206390(void) {
    return 0;
}

s32 func_ov003_02206398(void) {
    return 1;
}

s32 func_ov003_022063a0(void) {
    return 0x63;
}

s32 func_ov003_022063a8(void) {
    return 4;
}

void func_ov003_022063b0(void) {

}

s32 func_ov003_022063b4(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Store the battle-setting tileset choice on the current map; the menu's four
 * choices map onto the tileset banks in a different order (0, 3, 1, 2). */
void SetMapTilesetOption(s32 self, u8 option) {
    extern void **gCurrentMap;
    s8 tileset;

    switch (option & 0xff) {
    case 0:
        tileset = 0;
        break;
    case 1:
        tileset = 3;
        break;
    case 2:
        tileset = 1;
        break;
    case 3:
        tileset = 2;
        break;
    default:
        tileset = 0;
        break;
    }
    M2C_FIELD(*gCurrentMap, s8 *, MAP_TILESET) = tileset;
}

/* Inverse of SetMapTilesetOption: turn the map's stored tileset bank (MAP_TILESET)
 * back into the menu's four-choice index (bank 0->0, 3->1, 1->2, 2->3). */
s32 GetMapTilesetOption(void) {
    extern void **gCurrentMap;
    u8 tileset;

    tileset = M2C_FIELD(*gCurrentMap, u8 *, MAP_TILESET);
    switch (tileset) {
    case 0:
        return 0;
    case 3:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    default:
        return 0;
    }
}

s32 func_ov003_02206484(void) {
    return 1;
}

s32 func_ov003_0220648c(void) {
    return 1;
}

s32 func_ov003_02206494(void) {
    return 3;
}

s32 func_ov003_0220649c(void) {
    return 0;
}

void func_ov003_022064a4(void) {

}

s32 func_ov003_022064a8(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Apply the weather menu option `weatherOption` to the current map: the random
 * option turns on the auto-change mode and starts clear, any other value sets
 * that weather directly.  The chosen weather also becomes the map's start and
 * reset weather. */
void ApplyWeatherOption(s32 arg0_unused, s32 weatherOption) {
    extern void **gCurrentMap;
    u16 weather;

    if (weatherOption == WEATHER_OPTION_RANDOM) {
        weather = 0;
        M2C_FIELD(*gCurrentMap, s8 *, MAP_WEATHER_MODE) = 1;
    } else {
        weather = weatherOption;
        M2C_FIELD(*gCurrentMap, s8 *, MAP_WEATHER_MODE) = 0;
    }
    M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER) = (u8) weather;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_START) = (u8) weather;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_RESET) = (u8) weather;
}

/* The battle-settings weather option: when the map's weather is fixed, the reset
 * weather it keeps going back to; when the weather changes at random, whatever the
 * menu object's own getter (its vtable slot 3) reports. */
u8 GetWeatherOption(void **self) {
    void *map = *gCurrentMap;
    if (M2C_FIELD(map, u8 *, MAP_WEATHER_MODE) != 1) {
        return M2C_FIELD(map, u8 *, MAP_WEATHER_RESET);
    }
    return M2C_FIELD(self[0], u8 (**)(void **), 0xC)(self);
}

s32 func_ov003_0220657c(void) {
    return 4;
}

s32 func_ov003_02206584(void) {
    return 1;
}

s32 func_ov003_0220658c(void) {
    return 1;
}

s32 func_ov003_02206594(void) {
    return 0;
}

void func_ov003_0220659c(void) {

}

s32 func_ov003_022065a0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Store the battle-settings fog-of-war choice on the current map: a nonzero
 * `enabled` turns fog of war on (see IsMapFogEnabled). */
void SetMapFogEnabled(s32 self, u8 enabled) {
    extern void **gCurrentMap;

    M2C_FIELD(*gCurrentMap, s8 *, MAP_FOG) = enabled;
}

/* Whether the current map has fog of war enabled (MAP_FOG). */
u8 IsMapFogEnabled(void) {
    extern void **gCurrentMap;
    return M2C_FIELD(*gCurrentMap, u8 *, MAP_FOG);
}

s32 func_ov003_022065ec(void) {
    return 1;
}

s32 func_ov003_022065f4(void) {
    return 1;
}

s32 func_ov003_022065fc(void) {
    return 1;
}

s32 func_ov003_02206604(void) {
    return 0;
}

void func_ov003_0220660c(void) {

}

/* Return 1 when value lies within the inclusive range min..max, else 0; the
 * ov003 menu screens use it to test a row or entry index against its group's
 * bounds (2..4 for the menu's middle rows). */
u8 Ov003_IsValueInRange(s32 value, s32 min, s32 max) {
    s32 inRange;

    if ((min <= value) && (value <= max)) inRange = 1;
    else inRange = 0;
    return inRange;
}

