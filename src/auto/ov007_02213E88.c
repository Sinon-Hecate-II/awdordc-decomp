/* 30 functions from 0x02213E88 to 0x02214E24 (ov007), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u8 kind:6; u8 flags:2; u8 pad[13]; } MapUnit145F8;
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
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f890;
    func_01ffa3dc(&data_ov007_0221f890, 7);
}

void func_ov007_022142ec(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK func_020c0adc();
    M2C_UNK RefreshMapView();
    extern void *gCur3DSpriteEngine;
    func_020c0adc();
    func_020c0784();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    RefreshMapView();
    func_ov007_022142d4();
}

void func_ov007_02214324(M2C_UNK arg0) {
    M2C_UNK CreateMapEditList(s32, M2C_UNK);
    extern s32 *gCurrentMap;
    CreateMapEditList(*gCurrentMap + 0x5120, arg0);
    func_ov007_022121d4(1);
}

void func_ov007_02214354(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK RefreshMapView();
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_0221f820;
    func_020c0784();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    RefreshMapView();
    func_01ffa3dc(&data_ov007_0221f820, 7);
}

void func_ov007_02214394(void) {
    M2C_UNK func_020885fc();
    M2C_UNK MapSettings_Apply(M2C_UNK);
    func_020885fc();
    MapSettings_Apply(0);
}

void func_ov007_022143a8(void) {
    M2C_UNK func_ov003_022059d0();
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    func_ov003_022059d0();
    func_ov007_022121d4(1);
}

void func_ov007_022143bc(void) {
    M2C_UNK MapSettings_Capture(M2C_UNK);
    M2C_UNK func_02088624();
    extern u16 gMapConfig;
    if (func_020d4810() != 0) {
        gMapConfig = (u16) (gMapConfig | 0x40);
        MapSettings_Capture(0);
    }
    func_02088624();
}

void func_ov007_022143f0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f9a8;
    func_020c0784();
    func_01ffa3dc(&data_ov007_0221f9a8, 7);
}

void func_ov007_0221440c(void) {
    M2C_UNK func_020bfa80(M2C_UNK);
    func_020bfa80(0);
    MapSettings_Apply(0);
    func_ov007_022121d4(1);
}

void func_ov007_0221442c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f918;
    func_020c0784();
    func_01ffa3dc(&data_ov007_0221f918, 7);
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

void func_ov007_0221446c(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK RefreshMapView();
    M2C_UNK func_02086720(M2C_UNK);
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_0221f780;
    func_020c0784();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    RefreshMapView();
    if (func_ov007_022121c4() != 0) {
        func_02086720(0x46000006);
    } else {
        func_02086720(0x46000005);
    }
    func_01ffa3dc(&data_ov007_0221f780, 7);
}

void func_ov007_022144d4(void) {
    M2C_UNK func_020c0784();
    func_020c0784();
}

void func_ov007_022144e0(void) {
    M2C_UNK func_020c0784();
    func_020c0784();
}

void func_ov007_022144ec(void) {
    M2C_UNK func_020c0748(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov007_0221fc20;
    func_020c0748(&data_ov007_0221fc20, 0x50, 0x18, 0x50);
}

void func_ov007_0221450c(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) (M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_02214544(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x1);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_02214580(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x8);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_022145bc(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x6);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_022145f8(void) {
extern s32 *gCurrentMap;extern u16 gPlayerUnitIdBase[];
s32 GetUnitOwner(void *);
s32 i; MapUnit145F8 *p;
p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
if(p->flags==3)p->flags=0;
else {
for(i=gPlayerUnitIdBase[GetUnitOwner(p)]+1;i<gPlayerUnitIdBase[GetUnitOwner(M2C_FIELD(*gCurrentMap,void **,0x52d0))]+51;i++){
p=(MapUnit145F8 *)((u8 *)*gCurrentMap+0x59a4)+i;
if(p->kind)p->flags=0;
}
((MapUnit145F8 *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->flags=3;
}
func_ov007_022121d4(1);func_020c0784();
}

void func_ov007_0221470c(void) {
    M2C_UNK func_020c0784();
    func_020c0784();
}

/* Spawn an object on the map tile (x,y) if that tile is non-empty,
   returning 1 on success and 0 when the tile has no entry. */
s32 func_ov007_02214718(s32 x, s32 y) {
    void func_020c7470(s32, s32, s32 *);
    s32 func_020c0748(s32 *, s32, s32, s32);
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
    func_020c7470(x, y, coords);
    obj = (void *)func_020c0748((s32 *)data_ov007_0221fb30, coords[0], coords[1], 0x30);
    switch (((MapEntry14718 *)M2C_FIELD((void *)*gCurrentMap, void **, 0x52D0))->kind) {
    case 0: M2C_FIELD(obj, u8 *, 0x4E) = 0; break;
    case 1: M2C_FIELD(obj, u8 *, 0x4E) = 1; break;
    case 8: M2C_FIELD(obj, u8 *, 0x4E) = 2; break;
    case 6: M2C_FIELD(obj, u8 *, 0x4E) = 3; break;
    }
    return 1;
}

void ResizeMap(s32 arg0, s32 arg1) {
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
    M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5144) = (u16) arg0;
    M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5146) = (u16) arg1;
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
    M2C_UNK func_020c79f8(void);
    M2C_UNK func_020c7a08(void);
    M2C_UNK func_020c879c(M2C_UNK);
    M2C_UNK ResetMapUnits(void);
    M2C_UNK InitPlayerStates(void);
    M2C_UNK func_020d1f2c(void);
    M2C_UNK BuildMapRowOffsets(void);
    s32 func_0207f460(u8);
    void *func_020a660c(s16, s16, s16, s32);
    void func_ov007_0221b688(M2C_UNK, M2C_UNK);
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
    blockData = (void *)func_020c79f8();
    blockHeader = (void *)func_020c7a08();
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
                M2C_FIELD(map+2*(copyX+M2C_FIELD(map+2*copyY,u16 *,MAP_ROW_OFFSETS)),u16 *,MAP_CELL_TILE_ID)=func_0207f460(terrain);
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
            obj=func_020a660c(objX,objY,objParam,objKind);
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
            func_ov007_0221b688(mapX, lastY);
            mapX++;
        } while(mapX<width);
    }
    mapY=0;
    if (height > 0) {
        lastX = width - 1;
        do {
            func_ov007_0221b688(lastX, mapY);
            mapY++;
        } while(mapY<height);
    }

    func_020cf2c8();
}

s32 Map_MinDistanceThreshold(s32 arg0) {
    M2C_UNK func_0207ca08(M2C_UNK);
    M2C_UNK Divide(M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    void *temp_r0;
    s32 var_r1;
    s32 var_r0;
    s32 var_r5;

    temp_r0 = (void *) *gCurrentMap;
    var_r1 = (s32) (M2C_FIELD(temp_r0, u16 *, 0x5146) << 8);
    var_r0 = (s32) (M2C_FIELD(temp_r0, u16 *, 0x5144) << 8);
    var_r5 = func_0207ca08((s32) (var_r1 * var_r0));
    return Divide((s32) (arg0 * var_r5), func_0207ca08(0x3840000));
}

void Map_RandomScaledValue(void) {
    M2C_UNK Map_MinDistanceThreshold();
    M2C_UNK RandomIntRange();
    RandomIntRange();
    Map_MinDistanceThreshold();
}

s32 RandomCoordInRange(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK RandomIntRange(M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    s32 var_r4;
    s32 var_r0;

    var_r4 = 0;
loop:
    var_r4++;
    if (var_r4 > 0x64) {
        return 0;
    }
    var_r0 = RandomIntRange(arg0, arg1);
    if (var_r0 < 0) {
        goto loop;
    }
    switch (arg2) {
    case 0:
        if (var_r0 >= M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5144)) {
            goto loop;
        }
        return var_r0;
    case 1:
        if (var_r0 >= M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5146)) {
            goto loop;
        }
        return var_r0;
    default:
        return var_r0;
    }
}

