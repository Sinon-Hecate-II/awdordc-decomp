/* 30 functions from 0x02213E88 to 0x02214E24 (ov007), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u8 pad[11]; u8 kind : 4; u8 flags : 4; } MapEntry14718;

void func_ov007_02213e88(void *cursor) {
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    extern void *gKeyState;
    s32 new_dir;
    s32 prev_x;
    s32 prev_y;
    s32 prev_dir;
    s32 can_right;
    s32 can_left;
    s32 can_down;
    s32 can_up;
    u16 state_flags;
    void *right_obj;
    void *left_obj;
    void *down_obj;
    void *up_obj;
    void *right_child;
    void *left_child;
    void *down_child;
    void *up_child;
    void *right_obj_reload;
    void *left_obj_reload;
    void *down_obj_reload;
    void *up_obj_reload;

    prev_x = M2C_FIELD(cursor, s32 *, 0x34);
    state_flags = M2C_FIELD(gKeyState, u16 *, 0);
    prev_y = M2C_FIELD(cursor, s32 *, 0x38);
    prev_dir = M2C_FIELD(cursor, s32 *, 0x3C);
    if (state_flags & 1) {
        PlaySoundEffect(0x1000D);
        SetSpriteAnimation(cursor, 1);
        return;
    }
    if (state_flags & 2) {
        PlaySoundEffect(0x1000F);
        SetSpriteAnimation(cursor, 2);
        return;
    }
    right_obj = M2C_FIELD(cursor, void **, 0x40);
    can_right = 1;
    right_child = M2C_FIELD(right_obj, void **, 0x64);
    if ((M2C_FIELD(right_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(right_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(right_child, s8 *, 0xC) != 1))) {
        can_right = 0;
    }
    if (can_right & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 0;
        M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) + 1);
    }
    left_obj = M2C_FIELD(cursor, void **, 0x44);
    can_left = 1;
    left_child = M2C_FIELD(left_obj, void **, 0x64);
    if ((M2C_FIELD(left_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(left_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(left_child, s8 *, 0xC) != 1))) {
        can_left = 0;
    }
    if (can_left & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 0;
        M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) - 1);
    }
    down_obj = M2C_FIELD(cursor, void **, 0x48);
    can_down = 1;
    down_child = M2C_FIELD(down_obj, void **, 0x64);
    if ((M2C_FIELD(down_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(down_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(down_child, s8 *, 0xC) != 1))) {
        can_down = 0;
    }
    if (can_down & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 1;
        M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) + 1);
    }
    up_obj = M2C_FIELD(cursor, void **, 0x4C);
    can_up = 1;
    up_child = M2C_FIELD(up_obj, void **, 0x64);
    if ((M2C_FIELD(up_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(up_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(up_child, s8 *, 0xC) != 1))) {
        can_up = 0;
    }
    if (can_up & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 1;
        M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) - 1);
    }
    new_dir = M2C_FIELD(cursor, s32 *, 0x3C);
    switch (new_dir) {                            /* irregular */
    case 0:
        if (M2C_FIELD(gKeyState, u16 *, 2) & 0x40) {
            M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) + 1);
        }
        if (M2C_FIELD(gKeyState, u16 *, 2) & 0x80) {
            M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) - 1);
        }
        if (M2C_FIELD(gKeyState, u16 *, 0) & 0x10) {
            M2C_FIELD(cursor, s32 *, 0x3C) = 1;
        }
        break;
    case 1:
        if (M2C_FIELD(gKeyState, u16 *, 2) & 0x40) {
            M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) + 1);
        }
        if (M2C_FIELD(gKeyState, u16 *, 2) & 0x80) {
            M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) - 1);
        }
        if (M2C_FIELD(gKeyState, u16 *, 0) & 0x20) {
            M2C_FIELD(cursor, s32 *, 0x3C) = 0;
        }
        break;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) <= 5) {
        M2C_FIELD(cursor, s32 *, 0x34) = 5;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) <= 5) {
        M2C_FIELD(cursor, s32 *, 0x38) = 5;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) >= 0x1E) {
        M2C_FIELD(cursor, s32 *, 0x34) = 0x1E;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) >= 0x1E) {
        M2C_FIELD(cursor, s32 *, 0x38) = 0x1E;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) > prev_x) {
        right_obj_reload = M2C_FIELD(cursor, void **, 0x40);
        if ((s32) M2C_FIELD(right_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(right_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(right_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(right_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(right_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) < prev_x) {
        left_obj_reload = M2C_FIELD(cursor, void **, 0x44);
        if ((s32) M2C_FIELD(left_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(left_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(left_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(left_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(left_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) > prev_y) {
        down_obj_reload = M2C_FIELD(cursor, void **, 0x48);
        if ((s32) M2C_FIELD(down_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(down_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(down_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(down_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(down_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) < prev_y) {
        up_obj_reload = M2C_FIELD(cursor, void **, 0x4C);
        if ((s32) M2C_FIELD(up_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(up_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(up_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(up_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(up_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((M2C_FIELD(cursor, s32 *, 0x34) == prev_x) && (M2C_FIELD(cursor, s32 *, 0x38) == prev_y)) {

    } else {
        PlaySoundEffect(0x10011);
    }
    if (M2C_FIELD(cursor, s32 *, 0x3C) == prev_dir) {
        return;
    }
    PlaySoundEffect(0x10010);
}

void func_ov007_022142bc(void *arg0) {
    M2C_UNK func_ov007_0221352c(s32, s32);
    func_ov007_0221352c(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_ov007_022142d4(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f890;
    CreateSpriteFromClass(&data_ov007_0221f890, 7);
}

void func_ov007_022142ec(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK PushCarriedUnitMenuState();
    M2C_UNK RefreshMapView();
    extern void *gCur3DSpriteEngine;
    PushCarriedUnitMenuState();
    DeleteMapMenuSprites();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    RefreshMapView();
    func_ov007_022142d4();
}

void func_ov007_02214324(M2C_UNK arg0) {
    M2C_UNK CreateMapEditList(s32, M2C_UNK);
    extern s32 *gCurrentMap;
    CreateMapEditList(*gCurrentMap + 0x5120, arg0);
    MapEditor_SetMapModified(1);
}

void func_ov007_02214354(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK RefreshMapView();
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_0221f820;
    DeleteMapMenuSprites();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    RefreshMapView();
    CreateSpriteFromClass(&data_ov007_0221f820, 7);
}

void func_ov007_02214394(void) {
    M2C_UNK func_020885fc();
    M2C_UNK MapSettings_Apply(M2C_UNK);
    func_020885fc();
    MapSettings_Apply(0);
}

void func_ov007_022143a8(void) {
    M2C_UNK func_ov003_022059d0();
    M2C_UNK MapEditor_SetMapModified(M2C_UNK);
    func_ov003_022059d0();
    MapEditor_SetMapModified(1);
}

void func_ov007_022143bc(void) {
    M2C_UNK MapSettings_Capture(M2C_UNK);
    M2C_UNK func_02088624();
    extern u16 gMapConfig;
    if (IsMapConfirmEnabled() != 0) {
        gMapConfig = (u16) (gMapConfig | 0x40);
        MapSettings_Capture(0);
    }
    func_02088624();
}

void func_ov007_022143f0(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f9a8;
    DeleteMapMenuSprites();
    CreateSpriteFromClass(&data_ov007_0221f9a8, 7);
}

void func_ov007_0221440c(void) {
    M2C_UNK MapSettings_SetDefaults(M2C_UNK);
    MapSettings_SetDefaults(0);
    MapSettings_Apply(0);
    MapEditor_SetMapModified(1);
}

void func_ov007_0221442c(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f918;
    DeleteMapMenuSprites();
    CreateSpriteFromClass(&data_ov007_0221f918, 7);
}

u8 func_ov007_02214448(void) {
    extern u16 gMapConfig;
    u8 var_r0;

    if (((u32) (gMapConfig << 0x19) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Opens the map editor's menu: hides the current menu sprites, clears the editor's
   sprite layer and refreshes the map view, then labels it with whether the map has
   unsaved changes and creates the menu. */
void OpenMapEditorMenu(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK RefreshMapView();
    M2C_UNK SetUiMessageText(M2C_UNK);
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gMapEditorMenuClass;

    DeleteMapMenuSprites();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    RefreshMapView();
    if (MapEditor_IsMapModified() != 0) {
        SetUiMessageText(0x46000006);
    } else {
        SetUiMessageText(0x46000005);
    }
    CreateSpriteFromClass(&gMapEditorMenuClass, 7);
}

void func_ov007_022144d4(void) {
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
}

void func_ov007_022144e0(void) {
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
}

void func_ov007_022144ec(void) {
    M2C_UNK CreateMenuAt(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov007_0221fc20;
    CreateMenuAt(&data_ov007_0221fc20, 0x50, 0x18, 0x50);
}

void func_ov007_0221450c(void) {
    M2C_UNK MapEditor_SetMapModified(M2C_UNK);
    M2C_UNK DeleteMapMenuSprites();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) (M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF);
    MapEditor_SetMapModified(1);
    DeleteMapMenuSprites();
}

void func_ov007_02214544(void) {
    M2C_UNK MapEditor_SetMapModified(M2C_UNK);
    M2C_UNK DeleteMapMenuSprites();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x1);
    MapEditor_SetMapModified(1);
    DeleteMapMenuSprites();
}

void func_ov007_02214580(void) {
    M2C_UNK MapEditor_SetMapModified(M2C_UNK);
    M2C_UNK DeleteMapMenuSprites();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x8);
    MapEditor_SetMapModified(1);
    DeleteMapMenuSprites();
}

void func_ov007_022145bc(void) {
    M2C_UNK MapEditor_SetMapModified(M2C_UNK);
    M2C_UNK DeleteMapMenuSprites();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x6);
    MapEditor_SetMapModified(1);
    DeleteMapMenuSprites();
}

/* Marks the unit under the cursor: the marker is the unit's owner bits (value 3).
 * Clears it from the other units of that unit's player group and sets it on this
 * one; if this unit is already marked, just clears it.  Refreshes the editor's
 * unit palette and plays the feedback sound afterwards. */
void MapEditor_MarkCursorUnit(void) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 GetUnitOwner(void *);
    s32 i;
    BattleMapUnitHead *unit;

    unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    if (unit->owner == 3) {
        unit->owner = 0;
    } else {
        for (i = gPlayerUnitIdBase[GetUnitOwner(unit)] + 1;
             i < gPlayerUnitIdBase[GetUnitOwner(M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT))] + MAP_UNIT_GROUP_SCAN;
             i++) {
            unit = (BattleMapUnitHead *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS) + i;
            if (unit->kind) unit->owner = 0;
        }
        ((BattleMapUnitHead *)M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT))->owner = 3;
    }
    MapEditor_SetMapModified(1);
    DeleteMapMenuSprites();
}

void func_ov007_0221470c(void) {
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
}

/* Spawn an object on the map tile (x,y) if that tile is non-empty,
   returning 1 on success and 0 when the tile has no entry. */
s32 func_ov007_02214718(s32 x, s32 y) {
    void GetMapCursorScreenPosition(s32, s32, s32 *);
    s32 CreateMenuAt(s32 *, s32, s32, s32);
    extern s32 *gCurrentMap;
    extern u8 data_ov007_0221fb30[];
    u8 *base;
    u32 index;
    s32 coords[3];
    void *obj;
    base = (u8 *)*gCurrentMap;
    index = base[x + M2C_FIELD(base + y * 2, u16 *, 0x3758)];
    if (index == 0) return 0;
    M2C_FIELD(base, void **, 0x52D0) = base + 0x59A4 + index * 14;
    GetMapCursorScreenPosition(x, y, coords);
    obj = (void *)CreateMenuAt((s32 *)data_ov007_0221fb30, coords[0], coords[1], 0x30);
    switch (((MapEntry14718 *)M2C_FIELD((void *)*gCurrentMap, void **, 0x52D0))->kind) {
    case 0: M2C_FIELD(obj, u8 *, 0x4E) = 0; break;
    case 1: M2C_FIELD(obj, u8 *, 0x4E) = 1; break;
    case 8: M2C_FIELD(obj, u8 *, 0x4E) = 2; break;
    case 6: M2C_FIELD(obj, u8 *, 0x4E) = 3; break;
    }
    return 1;
}

/* Resize the current map to `width` x `height` cells: reset the units and players,
 * store the new size, then rebuild the row offsets and the generated map content. */
void ResizeMap(s32 width, s32 height) {
    M2C_UNK ResetMapUnits();
    M2C_UNK InitPlayerStates();
    M2C_UNK func_020d1f2c();
    M2C_UNK BuildMapRowOffsets();
    M2C_UNK func_ov007_02217a5c();
    M2C_UNK func_020cf2c8();
    extern s32 *gCurrentMap;
    ResetMapUnits();
    InitPlayerStates();
    func_020d1f2c();
    M2C_FIELD((void *) *gCurrentMap, u16 *, MAP_WIDTH) = (u16) width;
    M2C_FIELD((void *) *gCurrentMap, u16 *, MAP_HEIGHT) = (u16) height;
    BuildMapRowOffsets();
    func_ov007_02217a5c();
    func_020cf2c8();
}

#pragma optimization_level 4
#pragma opt_strength_reduction off
/* Paints every map cell with a map-editor terrain preset (8, 1, 4 or 3) after
 * resetting the map's units, players and row offsets; a negative preset just
 * rebuilds the map at its current size and leaves the terrain as it is. */
void FillMapTerrain(s32 preset) {
    M2C_UNK ResetMapUnits();
    M2C_UNK InitPlayerStates();
    M2C_UNK func_020d1f2c();
    M2C_UNK BuildMapRowOffsets();
    M2C_UNK func_020cf2c8();
    void ResizeMap(s32, s32);
    extern s32 *gCurrentMap;

    if (preset < 0) {
        ResizeMap(M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH), M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT));
        return;
    }
    ResetMapUnits();
    InitPlayerStates();
    func_020d1f2c();
    BuildMapRowOffsets();
    {
        s32 x;
        s32 y;
        for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT); y++) {

            for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH); x++) {
                switch (preset) {
                case 8:
                    M2C_FIELD(*gCurrentMap + (M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + x) * 2, u16 *, MAP_CELL_TILE_ID) = 3;
                    M2C_FIELD(M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + (*gCurrentMap + x), u8 *, MAP_CELL_TERRAIN) = 8;
                    break;
                case 1:
                    M2C_FIELD(*gCurrentMap + (M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + x) * 2, u16 *, MAP_CELL_TILE_ID) = 1;
                    M2C_FIELD(M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + (*gCurrentMap + x), u8 *, MAP_CELL_TERRAIN) = 1;
                    break;
                case 4:
                    M2C_FIELD(*gCurrentMap + (M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + x) * 2, u16 *, MAP_CELL_TILE_ID) = 0x20;
                    M2C_FIELD(M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + (*gCurrentMap + x), u8 *, MAP_CELL_TERRAIN) = 4;
                    break;
                case 3:
                    M2C_FIELD(*gCurrentMap + (M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + x) * 2, u16 *, MAP_CELL_TILE_ID) = 0x21;
                    M2C_FIELD(M2C_FIELD(*gCurrentMap + y * 2, u16 *, MAP_ROW_OFFSETS) + (*gCurrentMap + x), u8 *, MAP_CELL_TERRAIN) = 3;
                    break;
                default:
                    break;
                }
            }
        }
    }
    func_020cf2c8();
}
/* Rebuilds the map at the requested size from the map editor's serialized
 * export: fills the default terrain, copies the exported terrain grid and the
 * packed unit entries back onto the map, then fills the bottom row and right
 * column with the default terrain. */
void LoadMapFromExport(s32 arg0, s32 arg1) {
    M2C_UNK GetMapRecordBuffer(void);
    M2C_UNK GetMapRecordTerrain(void);
    M2C_UNK GetMapRecordHeader(void);
    M2C_UNK func_020c879c(M2C_UNK);
    M2C_UNK ResetMapUnits(void);
    M2C_UNK InitPlayerStates(void);
    M2C_UNK func_020d1f2c(void);
    M2C_UNK BuildMapRowOffsets(void);
    s32 TerrainByteToTileId(u8);
    void *CreateMapUnit(s16, s16, s16, s32);
    void Map_RefreshCellTile(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cf2c8(void);
    extern s32 *gCurrentMap;

    void *exportBlock;
    void *blockData;
    void *blockHeader;
    s32 mapX,copyX,mapY,objIndex,copyY;
    void *map;
    s32 terrain;
    s32 objEntry;
    s32 objX,objY,objParam,objKind;
    s32 objState;
    u8 oldState;
    void *obj;
    s32 lastY,lastX;
    s32 width=arg0,height=arg1;
    exportBlock = GetMapRecordBuffer();
    blockData = (void *)GetMapRecordTerrain();
    blockHeader = (void *)GetMapRecordHeader();
    func_020c879c(exportBlock);

    M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)=width;
    M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT)=height;
    ResetMapUnits();
    InitPlayerStates();
    func_020d1f2c();
    BuildMapRowOffsets();
    for(mapY=0;mapY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);mapY++) {
        for(mapX=0;mapX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);mapX++) {
            M2C_FIELD(*gCurrentMap+2*(mapX+M2C_FIELD(*gCurrentMap+2*mapY,u16 *,MAP_ROW_OFFSETS)),u16 *,MAP_CELL_TILE_ID)=3;
            M2C_FIELD(M2C_FIELD(*gCurrentMap+2*mapY,u16 *,MAP_ROW_OFFSETS)+(*gCurrentMap+mapX),u8 *,0x1420)=8;
        }
    }
    for(copyY=0;copyY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);copyY++) {
        for(copyX=0;copyX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);copyX++) {
            if(copyX<M2C_FIELD(blockHeader,u8 *,4)&&copyY<M2C_FIELD(blockHeader,u8 *,5)) {
                terrain=M2C_FIELD(blockData+copyX,u8 *,copyY*M2C_FIELD(blockHeader,u8 *,4));
                M2C_FIELD(M2C_FIELD(*gCurrentMap+2*copyY,u16 *,MAP_ROW_OFFSETS)+(*gCurrentMap+copyX),u8 *,0x1420)=terrain;
                map=(void *)*gCurrentMap;
                M2C_FIELD(map+2*(copyX+M2C_FIELD(map+2*copyY,u16 *,MAP_ROW_OFFSETS)),u16 *,MAP_CELL_TILE_ID)=TerrainByteToTileId(terrain);
            }
        }
    }
    objIndex=0;
    if((s32)M2C_FIELD(blockHeader,u8 *,0x2f)>objIndex) {
    blockData=(u8 *)blockData+0x384;
    do {
        objEntry=M2C_FIELD(blockData,u32 *,0);
        objX=(u32)(objEntry<<27)>>27;
        objY=(u32)(objEntry<<22)>>27;
        objParam=(u32)(objEntry<<17)>>27;
        objKind=(u32)(objEntry<<14)>>29;
        if(width>objX&&objY<height) {
            obj=CreateMapUnit(objX,objY,objParam,objKind);
            if(obj) {
                objState=(u8)((M2C_FIELD(blockData,u32 *,0)<<10)>>28);
                oldState=M2C_FIELD(obj,u8 *,11);
                M2C_FIELD(obj,u8 *,11)=(oldState&~15)|(objState&15);
            }
        }
        objIndex++;
        blockData=(u8 *)blockData+4;
    } while(objIndex<M2C_FIELD(blockHeader,u8 *,0x2f));
    }
    mapX=0;
    if (width > 0) {
        lastY = height - 1;
        do {
            Map_RefreshCellTile(mapX, lastY);
            mapX++;
        } while(mapX<width);
    }
    mapY=0;
    if (height > 0) {
        lastX = width - 1;
        do {
            Map_RefreshCellTile(lastX, mapY);
            mapY++;
        } while(mapY<height);
    }

    func_020cf2c8();
}

/* Scale a Manhattan-distance threshold for the current map: `baseDistance` cells
 * on the 30x30 reference map become baseDistance * sqrt(width * height) / 30,
 * with the cell counts in 8.8 fixed point and the hardware square root. */
s32 Map_MinDistanceThreshold(s32 baseDistance) {
    s32 HardwareSquareRoot(s32);
    s32 Divide(s32, s32);
    extern s32 *gCurrentMap;
    void *map;
    s32 heightFixed;
    s32 widthFixed;
    s32 mapSize;

    map = (void *) *gCurrentMap;
    heightFixed = (s32) (M2C_FIELD(map, u16 *, MAP_HEIGHT) << 8);
    widthFixed = (s32) (M2C_FIELD(map, u16 *, MAP_WIDTH) << 8);
    mapSize = HardwareSquareRoot((s32) (heightFixed * widthFixed));
    return Divide((s32) (baseDistance * mapSize), HardwareSquareRoot(MAP_DISTANCE_REFERENCE_AREA_FIXED8));
}

void Map_RandomScaledValue(void) {
    M2C_UNK Map_MinDistanceThreshold();
    M2C_UNK RandomIntRange();
    RandomIntRange();
    Map_MinDistanceThreshold();
}

/* Pick a random coordinate in [min, max] that lies inside the map's width (axis
 * 0) or height (axis 1); retries up to 100 times and gives up with 0 when none
 * was found.  Any other axis returns the raw random value. */
s32 RandomCoordInRange(s32 min, s32 max, s32 axis) {
    M2C_UNK RandomIntRange(M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    s32 tries;
    s32 value;

    tries = 0;
loop:
    tries++;
    if (tries > 0x64) {
        return 0;
    }
    value = RandomIntRange(min, max);
    if (value < 0) {
        goto loop;
    }
    switch (axis) {
    case 0:
        if (value >= M2C_FIELD((void *) *gCurrentMap, u16 *, MAP_WIDTH)) {
            goto loop;
        }
        return value;
    case 1:
        if (value >= M2C_FIELD((void *) *gCurrentMap, u16 *, MAP_HEIGHT)) {
            goto loop;
        }
        return value;
    default:
        return value;
    }
}

