/* 16 functions from 0x020D5430 to 0x020D6398 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

/* MAP_MODE 8 handler: after a tile was selected, play the cursor sound and step
 * the cursor toward it; once the input that selected it is released, hide the
 * touch cursor, centre the view on the selected tile and return to normal cursor
 * mode. */
void UpdateMapSelectionCursor(void) {
 extern void *gCurrentMap;
 UpdateMapCursorByDirectionAndTouch(0x1001a);func_0207a7a4(1,4);MapCursor_StepTowardTarget(1);
 if(!GetMapSelectionKeyAction())return;
 if(!GetMapSelectionTouchAction())return;
 HideTouchCursor();DeleteAllUnitMoveObjects();RefreshMapView();func_0207a768();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,MAP_MODE)=MAP_MODE_CURSOR;
}

void func_020d549c(void) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK CreateMapViewSprite();
    PlaySoundEffect(0x10017);
    CreateMapViewSprite();
}

void func_020d54b4(void) {

}

/* Battle-map input mode 10 (cursor settling): keep the cursor and map view
 * moving, and once the cursor is idle, the B key is released and the stylus is
 * not being dragged, reset the 3D sprite bank and return to cursor mode. */
void UpdateMapCursorSettle(void) {
    extern void *gCurrentMap;
    UpdateMapCursorInput();
    func_0207a7a4(1, 8);
    if (!IsMapCursorIdle()) return;
    if (!GetMapSettleKeyAction()) return;
    if (!GetMapSettleTouchAction()) return;
    Reset3DSpriteBankState();
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = MAP_MODE_CURSOR;
}

/* Empty-tile pick: run the map view's empty-tile callback (if installed), then
 * put the battle map into cursor-settling mode so the cursor glides onto the
 * picked tile before normal cursor input resumes. */
void StartEmptyTileSettle(void) {
    extern void *gCurrentMap;
    M2C_UNK (*callback)();

    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, MAP_VIEW_PTR), M2C_UNK (**)(), MAPVIEW_EMPTY_TILE_CB);
    if (callback != NULL) {
        callback();
    }
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = MAP_MODE_CURSOR_SETTLE;
}

#pragma opt_common_subs off
/* Rebuild the battle-map range overlay for the unit under the cursor at (x, y):
 * its movement range computed for that unit's owner, and its attack range,
 * leaving the cursor tile itself blocked off. */
void ShowCursorUnitRanges(s32 x, s32 y) {
    extern void *gCurrentMap;
    M2C_UNK CanUnitAttackDirectly();
    M2C_UNK CanUnitAttackIndirectly();
    M2C_UNK SelectMapLayer();
    M2C_UNK BuildUnitMoveRangeBlockingUnits();
    void MarkUnitMoveRangeCells(s32);
    M2C_UNK IsMobileIndirectUnitKind();
    void MarkUnitAttackRangeCells(void *);
    M2C_UNK FillMapLayer();
    void MarkUnitAttackRing(s32, s32, BattleMapUnitHead *);
    u8 *map;
    BattleMapUnitHead *unit;
    s32 showMoveRange, showAttackRange;

    showMoveRange = CanUnitAttackDirectly(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    showAttackRange = CanUnitAttackIndirectly(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_CELL_ORDER);
    if (showMoveRange) {
        map = M2C_FIELD(gCurrentMap, u8 **, 0);
        M2C_FIELD(map, u16 *, MAP_ACTIVE_PLAYER) = (M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID) >> 6) + 1;
        BuildUnitMoveRangeBlockingUnits(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_ACTIVE_PLAYER) =
            M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_CURRENT_PLAYER);
        map = M2C_FIELD(gCurrentMap, u8 **, 0);
        if (M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER) != 0) {
            M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] = -1;
        } else {
            M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] = 0;
        }
        MarkUnitMoveRangeCells(64);
        M2C_FIELD(M2C_FIELD(gCurrentMap, u8 **, 0) + y * 4, s8 **, MAP_GRID)[x] = -1;
    }
    if (!showAttackRange) return;
    if (IsMobileIndirectUnitKind(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), BattleMapUnitHead **, MAP_CURSOR_UNIT)->kind)) {
        map = M2C_FIELD(gCurrentMap, u8 **, 0);
        M2C_FIELD(map, u16 *, MAP_ACTIVE_PLAYER) = (M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID) >> 6) + 1;
        BuildUnitMoveRangeBlockingUnits(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_ACTIVE_PLAYER) =
            M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_CURRENT_PLAYER);
        map = M2C_FIELD(gCurrentMap, u8 **, 0);
        if (M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER) != 0) {
            M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] = -1;
        } else {
            M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x] = 0;
        }
        MarkUnitAttackRangeCells(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
        M2C_FIELD(M2C_FIELD(gCurrentMap, u8 **, 0) + y * 4, s8 **, MAP_GRID)[x] = -1;
        return;
    }
    if (!showMoveRange) FillMapLayer(-1);
    unit = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), BattleMapUnitHead **, MAP_CURSOR_UNIT);
    MarkUnitAttackRing(unit->x, unit->y, unit);
    if (!showMoveRange) return;
    if (x != 0) M2C_FIELD(M2C_FIELD(gCurrentMap, u8 **, 0) + y * 4, s8 **, MAP_GRID)[x - 1] = 0;
    map = M2C_FIELD(gCurrentMap, u8 **, 0);
    if (x < M2C_FIELD(map, u16 *, MAP_WIDTH) - 1)
        M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x + 1] = 0;
    if (y != 0) M2C_FIELD(M2C_FIELD(gCurrentMap, u8 **, 0) + (y - 1) * 4, s8 **, MAP_GRID)[x] = 0;
    map = M2C_FIELD(gCurrentMap, u8 **, 0);
    if (y < M2C_FIELD(map, u16 *, MAP_HEIGHT) - 1)
        M2C_FIELD(map + (y + 1) * 4, s8 **, MAP_GRID)[x] = 0;
}
#pragma opt_common_subs reset
/* Battle-map grid pass: mark every cell of the shared target list (gTargetList, as
 * walked by GetTargetPosition) as holding a unit in MAP_GRID, so the cursor code
 * draws it as an occupied target. */
void MarkTargetCellsInGrid(void) {
 void *GetTargetPosition(s32);
 extern void *gCurrentMap;
 s32 i=0;
 for(;i<GetTargetCount();i++) {
 MapTargetEntry *entry=GetTargetPosition(i);
 void *base=M2C_FIELD(gCurrentMap,void **,0);
 u8 **rows=(u8 **)((u8 *)base+MAP_GRID);
 rows[entry->y][entry->x]=MAP_GRID_HOLDS_UNIT;
 }
}

/* Handles a press on the battle-map tile the cursor is aimed at (B button / touch release):
 * if a map command entry covers the tile, activate it; otherwise make the unit on the tile the
 * cursor unit and show it, playing the invalid sound when there is nothing selectable there. */
s32 SelectCursorTarget(s32 x, s32 y) {
    void *FindMapOrderAtTile(s32, s32);
    extern void *gCurrentMap;
    void *entry;
    s32 a, b;
    M2C_UNK (*cb)();

    entry = FindMapOrderAtTile(x, y);
    if (entry) {
        SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_CELL_ORDER);
        FillMapLayer(-1);
        if (DrawOrderTargetArea(entry, 64, 1)) {
            cb = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), M2C_UNK (**)(), 52);
            if (cb) cb();
            goto finish;
        }
    }
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_UNIT_ID) =
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, x + M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + y * 2, u16 *, MAP_ROW_OFFSETS));
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT) =
        (u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_UNIT_RECORDS + M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_UNIT_ID) * MAP_UNIT_STRIDE;
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_CARRIER) = 0;
    if (M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, x + M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + y * 2, u16 *, MAP_ROW_OFFSETS)) == 0) {
        StartEmptyTileSettle();
        return 1;
    }
    a = CanUnitAttackDirectly(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    b = CanUnitAttackIndirectly(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    if (a == 0 && b == 0) {
        PlaySoundEffect(0x1001d);
        return 0;
    }
    SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_CELL_ORDER);
    CreateUnitMoveForUnit(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    cb = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), M2C_UNK (**)(), 52);
    if (cb) cb();
    RefreshMapView();
    ShowCursorUnitRanges(x, y);
finish:
    SetMapCursorVisible(1);
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_MODE) = 8;
    PlaySoundEffect(0x1001c);
    return 1;
}

/* Handle confirming the tile under the battle-map cursor: if it is a valid move
   destination finish the move (optionally playing the terrain effect); if it is empty,
   holds a spent unit or a global lock is set, reject it (consumeInvalid decides whether
   the press is swallowed); otherwise select the unit there and open its action menu. */
s32 ConfirmCursorTile(u8 x,u8 y,s32 playMoveEffect,s32 consumeInvalid,u8 menuMode){
extern void *gCurrentMap; extern M2C_UNK data_0211fbc4; extern u16 gMapConfig;
M2C_UNK (*cb)();
ClearHeldDirections();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,MAP_CURSOR_UNIT_ID)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,MAP_ROW_OFFSETS));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,MAP_CURSOR_UNIT)=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+MAP_UNIT_RECORDS+M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,MAP_CURSOR_UNIT_ID)*14;

M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,MAP_CURSOR_CARRIER)=0;
if(IsOwnedProductionSite(x,y)) { if(playMoveEffect)OpenProductionMenu(x,y); return 1; }
if (M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,MAP_ROW_OFFSETS)) == 0 || HasUnitActed(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,MAP_CURSOR_UNIT)) != 0 || ((u32)(gMapConfig<<22)>>31)) { if(!consumeInvalid)return 0; OpenBattleMenu();return 1; }
RunUnitSelectedEvent(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,MAP_CURSOR_UNIT));
CreateUnitMoveForUnit(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,MAP_CURSOR_UNIT));
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),56);if(cb)cb();
RefreshMapView();
ShowCursorUnitRanges(x,y);
func_0209fb70();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,MAP_ACTIVE_PLAYER)=(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,MAP_CURSOR_UNIT_ID)>>6)+1;
SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap,void **,0)+MAP_CELL_ORDER);
BuildUnitMoveRangeBlockingUnits(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,MAP_CURSOR_UNIT));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,MAP_ACTIVE_PLAYER)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,MAP_CURRENT_PLAYER);
MarkTargetCellsInGrid();
SetMapCursorVisible(0);CreateCursorCellBurst(7);
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,MAP_MODE)=2;
StartUnitMovePath(menuMode);
CreateSpriteFromClass(&data_0211fbc4,6);
PlaySoundEffect(0x1001c);
DrawUnitInfoPanel(2);
if(IsPlayerHuman(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,MAP_CURRENT_PLAYER)))AddRecordValue(21,1);
return 1;
}

/* Select the unit carried by `transport` (cargoSlot 0 = first cargo, 1 = next in
 * the carry chain) and open its action menu, remembering the transport in
 * MAP_CURSOR_CARRIER; menuMode is passed to the map's menu handler. */
void SelectCarriedUnit(u8 *transport, s32 cargoSlot, s32 menuMode) {
    extern void *gCurrentMap;
    extern M2C_UNK data_0211fbc4;
    s32 carrier;
    M2C_UNK (*cb)();
    void *unit;

    ClearHeldDirections();
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_UNIT_ID) = (transport + cargoSlot)[MAP_UNIT_CARRIED];
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT) = (u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_UNIT_RECORDS + M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_UNIT_ID) * MAP_UNIT_STRIDE;
    carrier = transport ? ((s32)transport - (s32)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_CARRIER) = carrier;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT), u16 *, MAP_UNIT_FLAGS) &= ~8;
    RunUnitSelectedEvent(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    CreateUnitMoveForUnit(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    cb = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), M2C_UNK (**)(), 56); if (cb) cb();
    RefreshMapView();
    unit = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT);
    ShowCursorUnitRanges(M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y));
    func_0209fb70();
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_ACTIVE_PLAYER) = (M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_UNIT_ID) >> 6) + 1;
    SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_CELL_ORDER);
    BuildUnitMoveRangeBlockingUnits(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT));
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_ACTIVE_PLAYER) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_CURRENT_PLAYER);
    MarkTargetCellsInGrid();
    SetMapCursorVisible(0); CreateCursorCellBurst(7);
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_MODE) = 2;
    StartUnitMovePath(menuMode);
    CreateSpriteFromClass(&data_0211fbc4, 6);
    PlaySoundEffect(0x1001c);
}

/* Move the battle-map cursor to tile (x,y): reject the move if the tile is out of
   range or unreachable, otherwise set the path start, the destination and the
   cursor state (4 = move, 5 = onto a unit), then redraw. */
void MoveCursorTo(s32 x, s32 y) {
    M2C_UNK PlaySoundEffect();
    M2C_UNK CanMoveCursorTo(s32, s32);
    M2C_UNK func_0207a768();
    M2C_UNK ChooseAttackPosition();
    M2C_UNK SetMapCommandPending();
    M2C_UNK UpdateUnitMovePathForCursor();
    M2C_UNK ClearMapCommandPending();
    M2C_UNK BuildMovePathDirections();
    M2C_UNK func_01ffb3d0();
    M2C_UNK CreateTargetSelectionSprite();
    extern void *gCurrentMap;
    extern u8 data_02168f24;
    s32 occupied;

    occupied = 0;
    {
        u8 unitId = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_UNIT_ID);
        u16 owner = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_CURSOR_OWNER);
        if (owner != (unitId & 0xc0)) {
            PlaySoundEffect(0x1001d);
            return;
        }
    }
    {
        u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
        s8 cell = (s8)grid[y][x];
        if (cell > 0x6e) {
            occupied = 1;
        } else {
            if (CanMoveCursorTo(x, y) == 0) {
                PlaySoundEffect(0x1001d);
                return;
            }
        }
    }
    func_0207a768();
    {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_PATH_X) = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT), u8 *, 1);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_X) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_PATH_X);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_PATH_Y) = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT), u8 *, 2);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_Y) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_PATH_Y);
    }
    if (occupied != 0) {
        ChooseAttackPosition(x, y, (u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_CURSOR_X);
        SetMapCommandPending();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_X) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_Y) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y);
        UpdateUnitMovePathForCursor();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_X) = (s16)x;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_Y) = (s16)y;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = 5;
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X) = (s16)x;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y) = (s16)y;
        ClearMapCommandPending();
        UpdateUnitMovePathForCursor();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = 4;
    }
    if (M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_X) != M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X) ||
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_Y) != M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y)) {
        BuildMovePathDirections();
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_PATH) = 4;
    }
    if (occupied != 0) {
        func_01ffb3d0(-1);
        {
            u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
            s16 cy = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y);
            s16 cx = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X);
            grid[cy][cx] = 1;
        }
        {
            u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
            grid[y][x] = 1;
        }
        CreateTargetSelectionSprite();
        {
            void (*fp)() = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(), 0x3c);
            if (fp != NULL) {
                fp();
            }
        }
    } else {
        func_01ffb3d0(-1);
        {
            u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
            s16 cy = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y);
            s16 cx = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X);
            grid[cy][cx] = 1;
        }
    }
    data_02168f24 = 0;
    return;
}

/* Aim the cursor at its own tile, open the map action menu there and switch to the
 * map-target input mode (MAP_MODE_TARGET_CURSOR) that runs that menu. */
void OpenMapActionMenuAtCursor(void) {
    extern void *gCurrentMap;
    void *map = M2C_FIELD(gCurrentMap, void **, 0);
    SetMapCursorTargetTile(M2C_FIELD(map, s16 *, MAP_CURSOR_X), M2C_FIELD(map, s16 *, MAP_CURSOR_Y));
    OpenMapActionMenu();
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = MAP_MODE_TARGET_CURSOR;
}

void func_020d61f0(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    M2C_UNK DeleteAllUnitMoveObjects();
    extern M2C_UNK data_0211fbc4;
    DeleteSpriteObjectsOfClass(&data_0211fbc4);
    DeleteAllUnitMoveObjects();
}

void UpdateMapCommandReplay(void);
/* MAP_MODE 5 update handler (the cursor settled on a tile): on a non-target tile
 * it re-opens the map action menu when the cursor moved, restores the idle cursor,
 * selects the transport's carried unit, or confirms the tile; on a unit-target tile
 * it starts the AI's attack decision. */
void UpdateMapTargetCursor(void) {
    extern void *gCurrentMap;
    extern u8 data_02168f24;

    if (IsMapCommandPending() == 0) {
        if (CountHeldDirections() != 0) {
            ReleaseHeldDirection();
            OpenMapActionMenuAtCursor();
            return;
        }
        func_020d61f0();
        RefreshMapView();
        if (data_02168f24 != 0) {
            DeleteAllUnitMoveObjects();
            M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = 0;
            return;
        }
        {
            void *map = M2C_FIELD(gCurrentMap, void **, 0);
            u8 carrierId;
            carrierId = M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER);
            if (carrierId != 0) {
                void *transport = (u8 *)map + MAP_UNIT_RECORDS + carrierId * MAP_UNIT_STRIDE;
                u8 cursorUnitId = M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID);
                u8 firstCargo = ((u8 *)transport)[MAP_UNIT_CARRIED];
                u8 cargoSlot = (cursorUnitId != firstCargo) ? 1 : 0;
                SelectCarriedUnit(transport, cargoSlot, 1);
                return;
            }
            {
                void *unit = M2C_FIELD(map, void **, MAP_CURSOR_UNIT);
                ConfirmCursorTile(((u8 *)unit)[MAP_UNIT_X], ((u8 *)unit)[MAP_UNIT_Y], 1, 1, 1);
                return;
            }
        }
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = 6;
        SetAiCommandPhase(3);
        func_ov000_0219c7d8(0);
        UpdateMapCommandReplay();
        return;
    }
}

/* MAP_MODE 6 handler (the command just queued at the cursor is replaying): once
 * the cursor is idle, step the replay, and when it is done (the command phase is
 * back to picking an action) return the map to normal cursor mode. */
void UpdateMapCommandReplay(void) {
    extern void *gCurrentMap;

    if (!IsMapCursorIdle()) return;
    ProcessAiCommandStep();
    if (GetAiCommandPhase() != AI_COMMAND_PHASE_PICK_ACTION) return;
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = MAP_MODE_CURSOR;
}

/* MAP_MODE 7 handler: snap the cursor's move target back to its own tile, mark the
 * map command state and refresh the unit under the cursor, then resume the normal
 * cursor mode. */
void UpdateMapCursorReturn(void) {
    extern void *gCurrentMap;
    void *map = M2C_FIELD(gCurrentMap, void **, 0);
    SetMapCursorTargetTile(M2C_FIELD(map, s16 *, MAP_CURSOR_X), M2C_FIELD(map, s16 *, MAP_CURSOR_Y));
    SetMapCommandPending();
    BattleUpdateUnitCursor();
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = MAP_MODE_CURSOR;
}

