/* 41 functions from 0x02211200 to 0x02212200 (ov007), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov007_map_editor.h"

/* Starts the map editor for the map gCurrentMap points at: resets the map and
 * player state, gives the map a name (its saved name, or a default "%s%02d"
 * built from the map slot), resets the editor palette and opens the editor scenes. */
void MapEditor_StartMap(void *editor) {
 extern void **gCurrentMap;
 extern u8 gMapNameFormat[];
 void SetMapEditorMode(s32);void SetMapEditorTool(s32);
 void SetMapEditorUnitKind(s32);void SetMapEditorUnitOwner(s32);void SetMapEditorUnitFlags(s32);void SetMapEditorTerrainKind(s32);void SetMapEditorTerrainOwner(s32);
 void RefreshMapEditor(void);void MapEditor_SetMapModified(s32);void func_ov007_022121e4(void);
 void SetMapCursorTargetTile(s16,s16);
 void *map;
 s32 text;
 s32 centerX,centerY;
 void (*callback)(void);
 ResetBattleMap();func_020d8cfc();
 M2C_FIELD(*gCurrentMap,u8*,MAP_PLAYER_COUNT)=4;
 func_020bfb74(0);ResetPlayerSetupTables();MapSettings_SetDefaults(0);
 if(!func_020c8020(M2C_FIELD(*gCurrentMap,u16*,MAP_ID))){
 map=*gCurrentMap;
 text=GetLocalizedText(0xc00002eb);
 StringFormat((u8*)map+MAP_NAME,gMapNameFormat,text,GetCampaignMapIndex(M2C_FIELD(map,u16*,MAP_ID))+1);
 }else{
 map=*gCurrentMap;
 text=GetMapName(M2C_FIELD(map,u16*,MAP_ID));
 StringCopy((u8*)map+MAP_NAME,text);
 }
 InitPlayerStates();func_020d1f2c();
 M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER)=0;
 M2C_FIELD(*gCurrentMap,u8*,0x5155)=0;
 M2C_FIELD(*gCurrentMap,u16*,0x52b0)=0;
 LoadMapTileset();LoadUiGraphicsBank(4);RefreshMapCursorCellCache();ResetMapUnits();func_020a45cc();func_020a23c4();BeginPlayerPhase();InitPlayerTurnState();
 MapEditor_LoadMapData(M2C_FIELD(*gCurrentMap,u16*,MAP_ID));func_020b1ae0();
 callback=M2C_FIELD(gCurrentMap[1],void(**)(void),0x50);
 if(callback)callback();
 func_0207ce28((u8*)*gCurrentMap+0x6ef8);func_020d4b30();
 map=*gCurrentMap;
 centerX=(u32)M2C_FIELD(map,u16*,MAP_WIDTH)>>1;
 centerY=(u32)M2C_FIELD(map,u16*,MAP_HEIGHT)>>1;
 SetMapCursorTargetTile((s16)centerX,(s16)centerY);func_0207b754(centerX,centerY);
 SetMapEditorMode(0);SetMapEditorTool(0);SetMapEditorUnitKind(1);SetMapEditorUnitOwner(1);SetMapEditorUnitFlags(0);SetMapEditorTerrainKind(1);SetMapEditorTerrainOwner(0);
 RefreshMapEditor();func_ov007_02212da0();func_ov007_02213150();func_ov007_0221ab20();MapEditor_SetMapModified(0);
 M2C_FIELD(editor,u8*,0x34)=1;
 func_ov007_022121e4();
}

void func_ov007_0221142c(M2C_UNK arg0) {
    M2C_UNK func_02086740(M2C_UNK, M2C_UNK);
    s32 func_02086a30(M2C_UNK);
    M2C_UNK func_0208999c(void *, M2C_UNK, s32);
    void *CreateTextLayer(M2C_UNK);
    void *temp_r0;

    if (func_02086a30(0x20) != 0) {
        return;
    }
    func_02086740(0x20, 1);
    temp_r0 = CreateTextLayer(arg0);
    func_0208999c(temp_r0, 2, 0x46000025);
    M2C_FIELD(temp_r0, s32 *, 0x58) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x58) & ~0x1FC00000) | 0x01000000);
}

void func_ov007_02211480(void) {
    M2C_UNK FreeUiGraphicsBank(M2C_UNK);
    M2C_UNK func_0208c748();
    M2C_UNK func_020b2178();
    M2C_UNK func_020bfbc0(M2C_UNK);
    M2C_UNK func_020d4c08();
    M2C_UNK func_ov007_02212db8();
    M2C_UNK func_ov007_0221ab38();
    FreeUiGraphicsBank(4);
    func_ov007_02212db8();
    func_020b2178();
    func_ov007_0221ab38();
    func_020d4c08();
    func_0208c748();
    func_020bfbc0(0);
}

void MapEditor_SpawnCursorSprite(M2C_UNK arg0) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f5c0;
    CreateSpriteFromClass(&data_ov007_0221f5c0, arg0);
}

/* Map editor unit brush: places the editor's selected unit kind, owner and flags
 * on cell (x, y).  On success it refreshes the map and cursor, marks the map
 * modified and plays the placement sound; a refused placement plays the error
 * sound when `playErrorSound` is set. */
void MapEditor_PlaceSelectedUnit(M2C_UNK editor, s32 x, s32 y, s32 playErrorSound) {
    s32 GetMapEditorUnitKind();
    s32 GetMapEditorUnitOwner();
    s32 GetMapEditorUnitFlags();
    s32 MapEditor_PlaceUnit(s32, s32, s32, s32, s32);
    M2C_UNK RefreshMapCellUnits();
    void RefreshMapEditor(void);
    void MapEditor_SetMapModified(s32);
    M2C_UNK SpawnSoundEffectAtTile(s32, s32, s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 result;
    s32 owner;
    s32 unitKind;
    unitKind = GetMapEditorUnitKind();
    owner = GetMapEditorUnitOwner();
    result = MapEditor_PlaceUnit(x, y, unitKind, owner, GetMapEditorUnitFlags());
    switch (result) {
    case 1:
        RefreshMapCellUnits();
        RefreshMapEditor();
        MapEditor_SetMapModified(1);
        MapEditor_SpawnCursorSprite(editor);
        SpawnSoundEffectAtTile(0x119, x, y, 1);
        return;
    case 0:
        if (playErrorSound == 0) return;
        PlaySoundEffect(0x1001D);
        return;
    }
}

/* Map editor pick tool: copies the unit standing on cell (x, y) into the editor's
 * brush (its kind, owner and state) and refreshes the palette; an empty cell plays
 * the error sound when `playErrorSound` is set. */
void MapEditor_PickUnit(M2C_UNK editor, s32 x, s32 y, s32 playErrorSound) {
    s32 MapEditor_GetUnitKindAt(s32, s32);
    s32 MapEditor_GetUnitOwnerAt(s32, s32);
    s32 MapEditor_GetUnitStateAt(s32, s32);
    void SetMapEditorUnitKind(s32);
    void SetMapEditorUnitOwner(s32);
    void SetMapEditorUnitFlags(s32);
    void RefreshMapEditor(void);
    M2C_UNK MapEditor_RefreshGraphics();
    M2C_UNK SpawnSoundEffectAtTile(s32, s32, s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 state;
    s32 owner;
    s32 unitKind;
    unitKind = MapEditor_GetUnitKindAt(x, y);
    owner = MapEditor_GetUnitOwnerAt(x, y);
    state = MapEditor_GetUnitStateAt(x, y);
    if (unitKind >= 0) {
        SetMapEditorUnitKind(unitKind);
        SetMapEditorUnitOwner(owner);
        SetMapEditorUnitFlags(state);
        RefreshMapEditor();
        MapEditor_RefreshGraphics();
        SpawnSoundEffectAtTile(0x11B, x, y, 1);
        return;
    }
    if (playErrorSound == 0) return;
    PlaySoundEffect(0x1001D);
}

/* Unit-page erase tool: destroys the unit on the cell under the cursor; on success
   refreshes the cells and editor, marks the map modified, spawns the editor's cursor
   sprite and the unit-erase explosion at the cell, otherwise plays the error sound
   when `sound` is set. */
void MapEditor_EraseUnit(M2C_UNK editor, s32 x, s32 y, s32 sound) {
    s32 MapEditor_DestroyUnitAt(s32, s32);
    M2C_UNK RefreshMapCellUnits();
    void RefreshMapEditor(void);
    void MapEditor_SetMapModified(s32);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, M2C_UNK);
    M2C_UNK SpawnSoundEffectAtTile(s32, s32, s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK gUnitEraseEffect;
    if (MapEditor_DestroyUnitAt(x, y) != 0) {
        RefreshMapCellUnits();
        RefreshMapEditor();
        MapEditor_SetMapModified(1);
        MapEditor_SpawnCursorSprite(editor);
        CreateAnimatedMapSprite(&gUnitEraseEffect, x, y, 0x50, 0, 0, editor);
        SpawnSoundEffectAtTile(0x8A, x, y, 1);
        return;
    }
    if (sound == 0) return;
    PlaySoundEffect(0x1001D);
}

void func_ov007_022116a0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK PlaySoundEffect(s32);
    s32 func_ov007_02214718(M2C_UNK, M2C_UNK);
    if (func_ov007_02214718(arg1, arg2) != 0) {
        return;
    }
    if (arg3 == 0) {
        return;
    }
    PlaySoundEffect(0x1001D);
}

/* Paint the cell at (x, y) with the map editor's current terrain brush: on
 * success mark the map modified, refresh the editor and spawn the tile's paint
 * sound effect (a different one for water and road terrain), otherwise play the
 * error sound when `sound` is set. */
void PaintMapTerrain(M2C_UNK a,s32 x,s32 y,s32 sound){
u8 GetMapEditorTerrainKind();u8 GetMapEditorTerrainOwner();s32 Map_PaintTile(s32,s32,s32,s32,s32);
M2C_UNK RefreshMapCellUnits();void RefreshMapEditor(void);void MapEditor_SetMapModified(s32);M2C_UNK SpawnSoundEffectAtTile(s32,s32,s32,s32);M2C_UNK PlaySoundEffect(s32);
s32 kind=GetMapEditorTerrainKind();s32 owner=GetMapEditorTerrainOwner();
switch(Map_PaintTile(x,y,kind,owner,1)){
case 1:RefreshMapCellUnits();RefreshMapEditor();MapEditor_SetMapModified(1);MapEditor_SpawnCursorSprite(a);
switch(kind){case 7:case 8:case 9:case 10:case 11:case 12:SpawnSoundEffectAtTile(0x11a,x,y,1);break;
default:SpawnSoundEffectAtTile(0x119,x,y,1);break;}break;
case 0:if(sound==0)return;PlaySoundEffect(0x1001d);break;
}
}

void func_ov007_022117e0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK SpawnSoundEffectAtTile(s32, M2C_UNK, M2C_UNK, s32);
    void SetMapEditorTerrainKind(s32);
    void SetMapEditorTerrainOwner(s32);
    void RefreshMapEditor(void);
    M2C_UNK MapEditor_RefreshGraphics();
    s32 Map_GetCellTerrainKind(M2C_UNK, M2C_UNK);
    s32 Map_GetCellTerrainOwner(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    s32 temp_r5;
    temp_r5 = Map_GetCellTerrainKind(arg1, arg2);
    temp_r4 = Map_GetCellTerrainOwner(arg1, arg2);
    SetMapEditorTerrainKind(temp_r5);
    SetMapEditorTerrainOwner(temp_r4);
    RefreshMapEditor();
    MapEditor_RefreshGraphics();
    SpawnSoundEffectAtTile(0x11B, arg1, arg2, 1);
}

/* Terrain-page erase tool: repaints the cell under the cursor as plain ground,
 * or wasteland where the old tile was destructible, marks the map modified and
 * spawns the editor's explosion effect; plays the error sound when the cell
 * cannot be erased and `sound` is set. */
void MapEditor_EraseTerrain(M2C_UNK editor, s32 x, s32 y, s32 sound) {
    s32 Map_IsWastelandTile(s32, s32);
    s32 Map_PaintTile(s32, s32, s32, s32, s32);
    M2C_UNK RefreshMapCellUnits();
    void RefreshMapEditor(void);
    void MapEditor_SetMapModified(s32);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, M2C_UNK);
    M2C_UNK SpawnSoundEffectAtTile(s32, s32, s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK data_ov007_0221f690;
    s32 terrain = MAP_TERRAIN_PLAIN;
    if (Map_IsWastelandTile(x, y)) terrain = MAP_TERRAIN_WASTELAND;
    if (Map_PaintTile(x, y, terrain, 0, 1) == 1) {
        RefreshMapCellUnits();
        RefreshMapEditor();
        MapEditor_SetMapModified(1);
        MapEditor_SpawnCursorSprite(editor);
        CreateAnimatedMapSprite(&data_ov007_0221f690, x, y, 0x50, 0, 0, editor);
        SpawnSoundEffectAtTile(0x8a, x, y, 1);
        return;
    }
    if (sound == 0) return;
    PlaySoundEffect(0x1001d);
}

void func_ov007_0221190c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK SpawnSoundEffectAtTile(s32, M2C_UNK, M2C_UNK, s32);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK RefreshMapView();
    u8 GetMapEditorTerrainKind(void);
    u8 GetMapEditorTerrainOwner(void);
    void RefreshMapEditor(void);
    void MapEditor_SetMapModified(s32);
    M2C_UNK MapEditor_RefreshGraphics();
    s32 Map_TryPaintTile(M2C_UNK, M2C_UNK, s32, s32);
    s32 temp_r0;
    s32 temp_r4;
    temp_r4 = GetMapEditorTerrainKind();
    temp_r0 = Map_TryPaintTile(arg1, arg2, temp_r4, GetMapEditorTerrainOwner());
    switch (temp_r0) {
    case 1:
        RefreshMapView();
        RefreshMapEditor();
        MapEditor_RefreshGraphics();
        MapEditor_SetMapModified(1);
        SpawnSoundEffectAtTile(0x11C, arg1, arg2, 1);
        return;
    case 0:
        if (arg3 == 0) return;
        PlaySoundEffect(0x1001D);
        return;
    }
}

/* Returns 0 if cell (x,y) is usable for the current action, else a nonzero status code (4/5). */
s32 func_ov007_02211990(s32 x, s32 y) {
    extern void **gCurrentMap;
    u8 GetMapEditorMode(void); u8 GetMapEditorTool(void);
    s32 GetMapEditorUnitKind(void); s32 GetMapEditorUnitOwner(void); s32 GetMapEditorUnitFlags(void);
    u8 GetMapEditorTerrainKind(void); u8 GetMapEditorTerrainOwner(void);
    s32 MapEditor_CanPlaceUnit(s32, s32, s32, s32, s32);
    s32 Map_CanPlaceTile(s32, s32, s32, s32); s32 IsDestroyedPipeTile(s32);
    s32 a, b; void *p;
    switch (GetMapEditorMode()) {
    case 1:
        switch (GetMapEditorTool()) {
        case 0:
            a = GetMapEditorUnitKind();
            b = GetMapEditorUnitOwner();
            if (!MapEditor_CanPlaceUnit(x, y, a, b, GetMapEditorUnitFlags()))
                return 5;
            break;
        case 2:
            return 4;
        case 1:
        case 3:
            p = *gCurrentMap;
            if (!M2C_FIELD(p, u8 *, x + M2C_FIELD((u8 *)p + y * 2, u16 *, 0x3758)))
                return 5;
            break;
        }
        break;
    case 0:
        switch (GetMapEditorTool()) {
        case 0:
        case 1:
            a = GetMapEditorTerrainKind();
            if (!Map_CanPlaceTile(x, y, a, GetMapEditorTerrainOwner()))
                return 5;
            break;
        case 2:
            return 4;
        case 3:
            a = GetMapEditorTerrainKind();
            if (!Map_CanPlaceTile(x, y, a, GetMapEditorTerrainOwner()))
                return 5;
            if (IsDestroyedPipeTile(GetMapEditorTerrainKind()))
                return 5;
            break;
        }
        break;
    }
    return 0;
}

void func_ov007_02211ae8(M2C_UNK arg0) {
    extern void *gKeyState;
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 func_020d46e8(void);
    s32 func_020ab240(void);
    void func_020cf828(s32);
    void func_0207a7a4(s32, s32);
    s32 func_ov007_02211990(s32, s32);
    void MoveMapCursorToTarget(s32);
    void CreateMapMenu(void);
    void func_ov007_02219418(void);
    void func_ov007_022144ec(void);
    void func_ov007_0221330c(void);
    u8 GetMapEditorMode(void);
    u8 GetMapEditorTool(void);
    void MapEditor_PlaceSelectedUnit(M2C_UNK, s32, s32, s32);
    void PaintMapTerrain(M2C_UNK, s32, s32, s32);
    void MapEditor_PickUnit(M2C_UNK, s32, s32, s32);
    void func_ov007_022117e0(M2C_UNK, M2C_UNK, M2C_UNK);
    void MapEditor_EraseUnit(M2C_UNK, s32, s32, s32);
    void MapEditor_EraseTerrain(M2C_UNK, s32, s32, s32);
    void func_ov007_022116a0(M2C_UNK, s32, s32, s32);
    void func_ov007_0221190c(M2C_UNK, s32, s32, s32);
    s32 r4;
    s32 r5;
    void *q;
    s32 r6;
    s32 r7;
    s16 val;
    s32 t;
    u8 f;
    s32 mask;
    r4 = *(u16 *)gKeyState;
    r5 = *(u16 *)((u8 *)gKeyState + 6);
    if (func_020d46e8()) {
        ((u8 *)arg0)[0x34] = 1;
        return;
    }
    q = gTouchState;
    if (((u8 *)q)[0x12]) r5 |= 1;
    if (((u8 *)q)[0x14]) r4 |= 1;
    if (((u8 *)arg0)[0x34]) {
        r5 = r4;
        if (r4) ((u8 *)arg0)[0x34] = 0;
    }
    if (!func_020ab240()) {
        func_020cf828(0x1001b);
        func_0207a7a4(1, 4);
        r6 = *(s16 *)((u8 *)*gCurrentMap + 0x52c2);
        r7 = *(s16 *)((u8 *)*gCurrentMap + 0x52c4);
        val = func_ov007_02211990(r6, r7);
        MoveMapCursorToTarget(val);
    }
    if (r4 & 0x100) { CreateMapMenu(); return; }
    if (r4 & 0x200) { func_ov007_02219418(); return; }
    if (r4 & 0x8) { func_ov007_022144ec(); return; }
    if (r4 & 0x4) { func_ov007_0221330c(); return; }
    if (!((u8 *)gTouchState)[0x12]) goto L_b4c;
    if (func_020ab240()) return;
    t = GetMapEditorTool();
    switch (t) {
    case 0:
        if (!(r5 & 1)) return;
        f = GetMapEditorMode();
        if (f == 0) goto L_c0;
        if (f != 1) return;
        MapEditor_PlaceSelectedUnit(arg0, r6, r7, r4 & 1);
        return;
    L_c0:
        PaintMapTerrain(arg0, r6, r7, r4 & 1);
        return;
    case 1:
        if (!(r4 & 1)) return;
        r4 &= 1;
        f = GetMapEditorMode();
        if (f == 0) goto L_c1;
        if (f != 1) return;
        MapEditor_PickUnit(arg0, r6, r7, r4);
        return;
    L_c1:
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK))func_ov007_022117e0)(arg0, r6, r7, r4);
        return;
    case 2:
        if (!(r5 & 1)) return;
        f = GetMapEditorMode();
        if (f == 0) goto L_c2;
        if (f != 1) return;
        MapEditor_EraseUnit(arg0, r6, r7, r4 & 1);
        return;
    L_c2:
        MapEditor_EraseTerrain(arg0, r6, r7, r4 & 1);
        return;
    case 3:
        if (!(r4 & 1)) return;
        r4 &= 1;
        f = GetMapEditorMode();
        if (f == 0) goto L_c3;
        if (f != 1) return;
        func_ov007_022116a0(arg0, r6, r7, r4);
        return;
    L_c3:
        func_ov007_0221190c(arg0, r6, r7, r4);
        return;
    }
L_b4c:
    f = GetMapEditorMode();
    if (f == 0) goto L_be4;
    if (f != 1) return;
    if (r5 & 1) { MapEditor_PlaceSelectedUnit(arg0, r6, r7, r4 & 1); return; }
    mask = r4 & 2;
    if (mask) { MapEditor_PickUnit(arg0, r6, r7, mask); return; }
    if (*(u16 *)((u8 *)gKeyState + 6) & 0x400) { MapEditor_EraseUnit(arg0, r6, r7, r4 & 0x400); return; }
    mask = r4 & 0x800;
    if (mask) { func_ov007_022116a0(arg0, r6, r7, mask); return; }
    return;
L_be4:
    if (r5 & 1) { PaintMapTerrain(arg0, r6, r7, r4 & 1); return; }
    mask = r4 & 2;
    if (mask) { func_ov007_022117e0(arg0, r6, r7); return; }
    if (r5 & 0x400) { MapEditor_EraseTerrain(arg0, r6, r7, r4 & 0x400); return; }
    mask = r4 & 0x800;
    if (mask) { func_ov007_0221190c(arg0, r6, r7, mask); return; }
}

void func_ov007_02211e6c(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f5f8;
    CreateSpriteObject(&data_ov007_0221f5f8, arg0);
}

void func_ov007_02211e84(void) {
    M2C_UNK Sprite_ResumeAnimation();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov007_0221f5f8;
    if (FindObjectByClass(&data_ov007_0221f5f8) == 0) {
        return;
    }
    Sprite_ResumeAnimation();
}

void SetMapEditorMode(s32 arg0) {
    extern u8 gMapEditorState;
    extern void **gCurrentMap;
    gMapEditorState = arg0;
    switch (arg0) {
    case 0:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52B4) = 0xA;
        return;
    case 1:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52B4) = 0;
        return;
    }
}

u8 GetMapEditorMode(void) {
    extern u8 gMapEditorState;
    return gMapEditorState;
}

void SetMapEditorTool(s32 arg0) {
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 9) = arg0;
}

u8 GetMapEditorTool(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 9);
}

s32 GetMapEditorUnitKind(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 8);
}

s32 GetMapEditorUnitOwner(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 7);
}

s32 GetMapEditorUnitFlags(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 6);
}

void SetMapEditorUnitKind(s32 arg0) {
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 8) = arg0;
}

void SetMapEditorUnitOwner(s32 arg0) {
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 7) = arg0;
}

void SetMapEditorUnitFlags(s32 arg0) {
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 6) = arg0;
}

u8 GetMapEditorTerrainKind(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 3);
}

u8 GetMapEditorTerrainOwner(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 1);
}

void SetMapEditorTerrainKind(s32 arg0) {
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 3) = arg0;
}

void SetMapEditorTerrainOwner(s32 arg0) {
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 1) = arg0;
}

void CachePlayerUnitCounts(void) {
    s8 func_020d2ff0(s32);
    extern M2C_UNK gPlayerUnitCounts;
    s32 var_r4;
    s8 *var_r5;
    s8 temp_r0;

    var_r5 = (s8 *)&gPlayerUnitCounts;
    var_r4 = 0;
    do {
        temp_r0 = func_020d2ff0(var_r4);
        var_r4 += 1;
        *var_r5 = temp_r0;
        var_r5 += 1;
    } while (var_r4 < 5);
}

s32 GetCachedPlayerUnitCount(s32 arg0) {
    extern M2C_UNK gPlayerUnitCounts;
    return M2C_FIELD(&gPlayerUnitCounts, u8 *, arg0);
}

void CountEditorUnits(void) {
    s8 func_020c1878(M2C_UNK *);
    extern M2C_UNK gEditorUnitCounts;
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 4) = func_020c1878(&gEditorUnitCounts);
}

s32 GetEditorUnitCategoryCount(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK GetUnitCategoryCount(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK gEditorUnitCounts;
    return GetUnitCategoryCount(&gEditorUnitCounts, arg0, arg1);
}

u8 func_ov007_0221204c(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 4);
}

/* Assign the map editor's players to sides: every player slot starts unassigned
 * with its own id, players that have any units (of any category) are put on team
 * 1, and the number of players on team 1 is cached in the editor state. */
void AssignPlayerTeams(void){
void SetPlayerTeam(s32,s32);void SetPlayerIdForSlot(s32,s32);s32 GetPlayerTeam(s32);s32 GetCachedPlayerUnitCount(s32);s32 GetEditorUnitCategoryCount(s32,s32);
extern u8 gMapEditorState;
s32 player;
for(player=0;player<5;player++){SetPlayerTeam(player,0);SetPlayerIdForSlot(player,player);}
for(player=1;player<5;player++){
if(GetCachedPlayerUnitCount(player)>0)SetPlayerTeam(player,1);
if(GetEditorUnitCategoryCount(2,player)>0)SetPlayerTeam(player,1);
if(GetEditorUnitCategoryCount(3,player)>0)SetPlayerTeam(player,1);
if(GetEditorUnitCategoryCount(4,player)>0)SetPlayerTeam(player,1);
}
M2C_FIELD(&gMapEditorState,u8 *,MAP_EDITOR_PLAYER_COUNT)=0;
for(player=0;player<5;player++){if(GetPlayerTeam(player)==1)M2C_FIELD(&gMapEditorState,u8 *,MAP_EDITOR_PLAYER_COUNT)++;}
}

u8 MapEditor_PlayerHasTeam(s32 arg0) {
    s32 GetPlayerTeam();
    extern u8 gMapEditorState;
    u8 var_r0;
    u8 var_r0_2;
    if (arg0 < 0) {
        if ((u32) M2C_FIELD(&gMapEditorState, u8 *, 2) >= 2U) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        return var_r0_2;
    }
    if (GetPlayerTeam(arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void RefreshMapEditor(void) {
    void CachePlayerUnitCounts(void);
    void AssignPlayerTeams(void);
    void CountEditorUnits(void);
    CachePlayerUnitCounts();
    CountEditorUnits();
    AssignPlayerTeams();
}

u8 MapEditor_IsMapModified(void) {
    extern u8 gMapEditorState;
    return M2C_FIELD(&gMapEditorState, u8 *, 5);
}

void MapEditor_SetMapModified(s32 arg0) {
    extern u8 gMapEditorState;
    M2C_FIELD(&gMapEditorState, u8 *, 5) = arg0;
}

void func_ov007_022121e4(void) {
    M2C_UNK ResetEffectSpritePool();
    M2C_UNK LoadEffectSpriteSheet(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f6a0;
    ResetEffectSpritePool();
    LoadEffectSpriteSheet(&data_ov007_0221f6a0, 0);
}

