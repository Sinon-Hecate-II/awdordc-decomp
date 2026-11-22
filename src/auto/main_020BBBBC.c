/* 19 functions from 0x020BBBBC to 0x020BCB94 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline s16 BC454Direction(s16 *p,s32 dir) { return p[dir*2]; }

void CreateAttackTargetEffect(s16 targetX, s16 targetY, s32 sourceX, s32 sourceY, s32 owner) {
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    s32 IsPlayerHuman(u16);
    extern s32 *gCurrentMap;
    extern M2C_UNK data_0212b00c;
    void *effect;

    /* Count human attack actions, then create the target marker and aim its effect at the selected tile. */
    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) != 0) {
        AddRecordValue(0xD, 1);
    }
    effect = CreateSpriteForOwner(&data_0212b00c, owner);
    M2C_FIELD(effect, s16 *, 0x6C) = targetX;
    M2C_FIELD(effect, s16 *, 0x6E) = targetY;
    M2C_FIELD(effect, s32 *, 0x34) = sourceX;
    M2C_FIELD(effect, s32 *, 0x38) = sourceY;
    M2C_FIELD(effect, s16 *, 0x52) = 0x1E;
}

void func_020bbc2c(M2C_UNK arg0) {
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    M2C_UNK func_020a348c(M2C_UNK);
    M2C_UNK RefreshMapView();
    s32 IsPlayerHuman(u16);
    extern s32 *gCurrentMap;

    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        AddRecordValue(6, 1);
    }
    func_020a348c(arg0);
    RefreshMapView();
}

/* Unit-move task start: build the straight path from the task's unit to the
 * task's target tile, begin its move sprite, then move the unit record along the
 * path and mark the move-range tiles the path crosses. */
void StartUnitMoveToTile(void *task) {
    M2C_UNK BuildMovePath(M2C_UNK *, s32, s32, M2C_UNK *);
    M2C_UNK MarkUnitMovePath(M2C_UNK *, s16 *, s16 *, M2C_UNK *);
    M2C_UNK ApplyMovePath(M2C_UNK *, M2C_UNK *);
    M2C_UNK CreateUnitMoveForUnit(M2C_UNK *);
    M2C_UNK BeginUnitMove(M2C_UNK *);
    s16 from[2];
    s16 to[2];
    M2C_UNK path[5];
    M2C_UNK *unit;

    unit = M2C_FIELD(task, M2C_UNK **, 0x54);
    BuildMovePath(unit, M2C_FIELD(task, s32 *, 0x34), M2C_FIELD(task, s32 *, 0x38), path);
    CreateUnitMoveForUnit(unit);
    BeginUnitMove(path);
    from[0] = M2C_FIELD(unit, u8 *, 1);
    from[1] = M2C_FIELD(unit, u8 *, 2);
    ApplyMovePath(unit, path);
    to[0] = M2C_FIELD(unit, u8 *, 1);
    to[1] = M2C_FIELD(unit, u8 *, 2);
    MarkUnitMovePath(unit, from, to, path);
}

/* Create the marker sprite for the adjacent unit the map-cursor option in
 * direction `dir` points at: place it at the cursor cell offset by that direction
 * and attach the unit standing on the target cell. */
void CreateAdjacentAllyMarker(s32 dir) {
 void *CreateSpriteFromClass(M2C_UNK *,s32);
 extern s32 *gCurrentMap;
 extern s16 gAdjacentCellOffsets[];
 extern M2C_UNK gAdjacentAllyMarkerClass;
 s32 base=*gCurrentMap;
 s32 dx=gAdjacentCellOffsets[dir*2];
 s32 dy=gAdjacentCellOffsets[dir*2+1];
 s32 x=M2C_FIELD(base,s16 *,MAP_CURSOR_X)+dx;
 s32 y=M2C_FIELD(base,s16 *,MAP_CURSOR_Y)+dy;
 s32 row=M2C_FIELD(base+y*2,u16 *,MAP_ROW_OFFSETS);
 u8 id=M2C_FIELD(base+(x+row),u8 *,MAP_CELL_UNIT_ID);
 void *unit=(void *)(base+MAP_UNIT_RECORDS+(s16)id*(s16)MAP_UNIT_STRIDE);
 void *marker;
 if(!unit)return;
 marker=CreateSpriteFromClass(&gAdjacentAllyMarkerClass,7);
 M2C_FIELD(marker,s32 *,0x34)=dx*2;
 M2C_FIELD(marker,s32 *,0x38)=dy*2;
 M2C_FIELD(marker,void **,0x54)=unit;
}

void func_020bbd8c(void) {
    M2C_UNK func_020cab8c();
    func_020cab8c();
}

/* AI ammo action: create the action's effect sprite (func_020c79c4 takes the
 * caller's target x/y from its registers), then spend one point of the cursor
 * unit's ammo, counting a record entry when a human player is acting. */
void AiDecrementUnitAmmo(void) {
    extern s32 *gCurrentMap;
    BattleMapUnit *unit;
    u16 ammo,left;
    func_020c79c4();
    unit=M2C_FIELD(*gCurrentMap,BattleMapUnit **,MAP_CURSOR_UNIT);
    ammo=M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO);
    left=(u16)(((u32)(ammo<<21)>>28)+65535);
    M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO)=(ammo&~MAP_UNIT_AMMO_MASK)|((left&15)<<MAP_UNIT_AMMO_SHIFT);
    if(IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))AddRecordValue(36,1);
}

/* Begin acting with the cursor unit: show its tile's action effect, make it the
 * current player's selected unit, pay the unit's action cost, and count one
 * record entry when a human player is acting. */
void BeginUnitAction(void) {
    void func_020c98d8(u8, u8, s32);
    void SetPlayerSelectedUnit(u16, void *);
    s32 GetUnitActionCost(u16, u32);
    void PayPlayerFunds(u16, s32);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    void *unit;

    unit = M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    func_020c98d8(M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y), 3);
    SetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT));
    PayPlayerFunds(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), GetUnitActionCost(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), (u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26));
    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) AddRecordValue(27, 1);
}

/* AI command 22: produce a kind-17 unit on the cursor unit's tile, chain it as
   that unit's cargo, spend one ammo and update the cursor style for the army of
   the unit's owner. */
void AiProduceCargoUnit(void) {
    void *ProduceUnit(u8,u8,s32);
    void func_020c98d8(u8,u8,s32);
    extern s32 *gCurrentMap;
    BattleMapUnit *produced;
    BattleMapUnit *cursor;
    s32 cargoIndex;
    u16 hpWord;
    u32 ammo;

    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    produced = (BattleMapUnit *)ProduceUnit(cursor->x, cursor->y, 17);
    produced->flags |= 10;
    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    if (cursor->firstCarried == 0) {
        cargoIndex = produced ? ((s32)produced - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
        cursor->firstCarried = cargoIndex;
    } else {
        cargoIndex = produced ? ((s32)produced - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
        cursor->nextCarried = cargoIndex;
    }
    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    cursor->flags |= 16;
    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    hpWord = M2C_FIELD(cursor, u16 *, MAP_UNIT_HEALTH);
    ammo = (u32)(hpWord << 21) >> 28;
    if (ammo) {
        ammo = (u16)(ammo + 65535);
        M2C_FIELD(cursor, u16 *, MAP_UNIT_HEALTH) = (hpWord & ~0x780) | ((ammo & 15) << 7);
    }
    cargoIndex = produced ? ((s32)produced - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
    switch (M2C_FIELD(*gCurrentMap + ((cargoIndex >> 6) + 1) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_ARMY_INDEX)) {
    case 1:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 4);
        break;
    case 2:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 5);
        break;
    case 3:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 6);
        break;
    case 4:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 7);
        break;
    }
}

void func_020bc0e0(void) {
    extern s32 *gCurrentMap;
    s32 GetUnitCaptureRate(void *, s32, s32);
    void ClearCursorUnitCapture(void);
    void func_020baaac(void);
    s32 IsPlayerHuman();
    s32 AddRecordValue(s32, s32);
    s32 func_020cd5d8(void);
    void CreateBattleEffect(s32, s32, s32, s32, u8, u8);
    void func_020c32b0(s32, s32);
    void func_020cf2c8(void);
    void CompletePropertyCapture(s32, s32);
#define CURSOR_UNIT(map) M2C_FIELD((map), u8 **, MAP_CURSOR_UNIT)
#define CURSOR_X(map) M2C_FIELD((map), s16 *, MAP_CURSOR_X)
#define CURSOR_Y(map) M2C_FIELD((map), s16 *, MAP_CURSOR_Y)
#define CURSOR_INDEX(map) (CURSOR_X(map) + M2C_FIELD((map) + CURSOR_Y(map)*2, u16 *, MAP_ROW_OFFSETS))
#define CAPTURE(word) (((u32)(word) << 16) >> 27)
    u8 *map, *unit, *terrains;
    s32 points, unitId, cell, visible, replacement;
    u16 captureAmmo;
    u8 terrain;

    map = (u8 *)*gCurrentMap;
    points = GetUnitCaptureRate(CURSOR_UNIT(map), CURSOR_X(map), CURSOR_Y(map));
    map = (u8 *)*gCurrentMap;
    terrain = M2C_FIELD(map + CURSOR_INDEX(map), u8 *, MAP_CELL_TERRAIN);
    unit = CURSOR_UNIT(map);
    unitId = unit ? (s32)(unit - (map + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
    ClearCursorUnitCapture();
    func_020baaac();
    map = (u8 *)*gCurrentMap;
    points += CAPTURE(M2C_FIELD(CURSOR_UNIT(map), u16 *, MAP_UNIT_CAPTURE));
    if (points >= MAP_UNIT_CAPTURE_COMPLETE)
        points = MAP_UNIT_CAPTURE_COMPLETE;
    if (points == MAP_UNIT_CAPTURE_COMPLETE && IsPlayerHuman(M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)))
        AddRecordValue(0x23, 1);

    map = (u8 *)*gCurrentMap;
    if (map[MAP_FOG] || map[MAP_WEATHER] == 2) {
        u16 player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
        s16 y = CURSOR_Y(map);
        u8 side = M2C_FIELD(map + player*MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_SIDE);
        s16 x = CURSOR_X(map);
        visible = 1;
        if (!(side & 2)) {
            cell = x + M2C_FIELD(map + y*2, u16 *, MAP_ROW_OFFSETS);
            if (!(u8)(M2C_FIELD(map + ((u32)cell >> 3), u8 *, MAP_CELL_BITMAP) & (visible << (cell & 7))))
                visible = 0;
        }
        if (!visible)
            goto updateCapture;
    }
    if (func_020cd5d8()) {
        replacement = (terrain & MAP_TERRAIN_KIND_MASK) == 9 ? 21 : 20;
        map = (u8 *)*gCurrentMap;
        CreateBattleEffect((u8)M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER), replacement & MAP_TERRAIN_KIND_MASK, 0,
            M2C_FIELD(map + (((unitId & 0xc0) >> 6) + 1)*MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_PROPERTY_ARMY),
            (u8)CAPTURE(M2C_FIELD(CURSOR_UNIT(map), u16 *, MAP_UNIT_CAPTURE)), (u8)points);
    } else if (points >= MAP_UNIT_CAPTURE_COMPLETE) {
        func_020c32b0(((unitId & 0xc0) >> 6) + 1, terrain & MAP_TERRAIN_KIND_MASK);
    }

updateCapture:
    unit = CURSOR_UNIT((u8 *)*gCurrentMap);
    M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) = (M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) & ~0xf800)
        | (((u32)(u16)points << 27) >> 16);
    unit = CURSOR_UNIT((u8 *)*gCurrentMap);
    captureAmmo = M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE);
    if (CAPTURE(captureAmmo) < MAP_UNIT_CAPTURE_COMPLETE)
        return;
    M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) = captureAmmo & ~0xf800;
    unit = CURSOR_UNIT((u8 *)*gCurrentMap);
    captureAmmo = M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO);
    M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO) = (captureAmmo & ~0x780)
        | (((u32)(u16)((((u32)captureAmmo << 21) >> 28) + 0xffff) << 28) >> 21);

    map = (u8 *)*gCurrentMap;
    cell = CURSOR_INDEX(map);
    terrains = map + MAP_CELL_TERRAIN;
    if ((terrains[cell] & MAP_TERRAIN_KIND_MASK) == 9) {
        terrains[cell] = 21;
        map = (u8 *)*gCurrentMap;
        M2C_FIELD(map + CURSOR_INDEX(map)*2, u16 *, MAP_CELL_TILE_ID) = 0x199;
    } else {
        terrains[cell] = 20;
        map = (u8 *)*gCurrentMap;
        M2C_FIELD(map + CURSOR_INDEX(map)*2, u16 *, MAP_CELL_TILE_ID) = 0x179;
    }
    func_020cf2c8();
    map = (u8 *)*gCurrentMap;
    CompletePropertyCapture(CURSOR_X(map), CURSOR_Y(map));
#undef CAPTURE
#undef CURSOR_INDEX
#undef CURSOR_Y
#undef CURSOR_X
#undef CURSOR_UNIT
}

#pragma push
#pragma opt_strength_reduction off
/* Auto-repeat handler for the map cursor: takes the held D-pad direction, pins
 * the cursor target cell to the matching edge of the visible window, clamps it
 * to the map and then steps it one cell along the direction. */
void MoveMapCursorWithKeys(void) {
s32 GetMapViewWidth(void); s32 GetMapViewHeight(void); void ClampCursorToMap(void);
extern s32 *gCurrentMap; extern void *gKeyState; extern s16 gDirectionStepX; extern s16 gDirectionStepY;
s32 dir=(M2C_FIELD(gKeyState,u16 *,6)>>4)&15;
s32 viewW=GetMapViewWidth(), viewH=GetMapViewHeight(), n;
if(M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)<viewW)viewW=M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);
if(M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT)<viewH)viewH=M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);
if(((s16 (*)[2])&gDirectionStepX)[dir][0]<0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X)>>4)+1;
if(((s16 (*)[2])&gDirectionStepX)[dir][0]>0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=(viewW-2)+(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X)>>4);
if(((s16 (*)[2])&gDirectionStepY)[dir][0]<0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y)>>4)+1;
if(((s16 (*)[2])&gDirectionStepY)[dir][0]>0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=(viewH-2)+(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y)>>4);
ClampCursorToMap();
n=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)+((s16 (*)[2])&gDirectionStepX)[dir][0];
if(n>=0 && n<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH))M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=n;
n=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)+((s16 (*)[2])&gDirectionStepY)[dir][0];
if(n>=0 && n<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT))M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=n;
}
#pragma pop
void func_020bc610(void *arg0) {
    void PlaySoundEffect(void *);
    extern void *gKeyState;
    extern s32 *data_027e0058;
    extern s16 gDirectionStepX;
    extern s16 gDirectionStepY;
    s32 raw;
    s32 dir;
    void *p;
    s32 n;
    raw = (s32)M2C_FIELD(gKeyState, u16 *, 4);
    dir = (raw >> 4) & 15;
    p = (void *)*data_027e0058;
    n = M2C_FIELD(p, s16 *, 0x52c2) + ((volatile s16 (*)[2])&gDirectionStepX)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, 0x5144)) {
        M2C_FIELD(p, s16 *, 0x52c2) = n;
        if (((volatile s16 (*)[2])&gDirectionStepX)[dir][0] != 0) PlaySoundEffect(arg0);
    }
    p = (void *)*data_027e0058;
    n = M2C_FIELD(p, s16 *, 0x52c4) + ((volatile s16 (*)[2])&gDirectionStepY)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, 0x5146)) {
        M2C_FIELD(p, s16 *, 0x52c4) = n;
        if (((volatile s16 (*)[2])&gDirectionStepY)[dir][0] != 0) PlaySoundEffect(arg0);
    }
}

s32 IsCellEnterable(s32 a,s32 b) {
 extern s32 *gCurrentMap;
 s32 p=*gCurrentMap;
 s32 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),s8 *,0x1e30);
 if(v>=0 && v<=110)return 1;
 return 0;
}

u8 IsCellOccupied(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_r2;
    u8 var_r0;

    temp_r2 = *gCurrentMap;
    if ((s32) M2C_FIELD((temp_r2 + (arg0 + M2C_FIELD((temp_r2 + (arg1 * 2)), u16 *, 0x3758))), s8 *, 0x1E30) > 0x6E) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

#pragma opt_strength_reduction off
/* Auto-repeat cursor move: step the aimed tile one cell along the held D-pad
 * direction and play the move sound. On a frame without a fresh key press the
 * step is refused when it would leave enterable terrain for blocked terrain, or
 * leave a unit for a cell that holds none. */
void MoveMapCursorByDirection(void *arg0) {
    void PlaySoundEffect(void *);
    extern void *gKeyState;
    extern s32 *gCurrentMap;
    extern s16 gDirectionStepX, gDirectionStepY;
    s32 dir;
    u16 keys;
    s16 x, y;
    void *p;
    s32 n;

    dir = (M2C_FIELD(gKeyState, volatile u16 *, 4) >> 4) & 15;
    keys = M2C_FIELD(gKeyState, u16 *, 0);
    p = (void *)*gCurrentMap;
    x = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X) + ((s16 (*)[2])&gDirectionStepX)[dir][0];
    y = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y) + ((s16 (*)[2])&gDirectionStepY)[dir][0];
    if (!keys) {
        if (IsCellEnterable(M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y)) && !IsCellEnterable(x, y)) {
            if (!IsCellOccupied(x, y)) return;
        }
        p = (void *)*gCurrentMap;
        if (IsCellOccupied(M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y))) {
            if (!IsCellOccupied(x, y)) return;
        }
    }
    p = (void *)*gCurrentMap;
    n = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X) + ((s16 (*)[2])&gDirectionStepX)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, MAP_WIDTH)) {
        M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X) = n;
        if (((s16 (*)[2])&gDirectionStepX)[dir][0]) PlaySoundEffect(arg0);
    }
    p = (void *)*gCurrentMap;
    n = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y) + ((s16 (*)[2])&gDirectionStepY)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, MAP_HEIGHT)) {
        M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y) = n;
        if (((s16 (*)[2])&gDirectionStepY)[dir][0]) PlaySoundEffect(arg0);
    }
}
#pragma opt_strength_reduction reset
s32 func_020bc910(void) {
    void func_020d549c(void *);
    void func_020c752c(void);
    void CreateMapMenu(void);
    void HandleUiCancel(void);
    void *func_020d2e3c(u16);
    void PlaySoundEffect(void *);
    s32 StepMapViewToTile(u8, u8);
    s32 ConfirmCursorTile(s16, s16, s32, s32, u8);
    void SelectCursorTarget(s32, s32);

    extern s32 *gCurrentMap;
    extern void *gKeyState;

    s32 *map = *gCurrentMap;
    void *entry;
    s32 y, x;
    u16 flags = M2C_FIELD(gKeyState, u16 *, 0);

    x = M2C_FIELD(map, s16 *, 0x52C2);
    y = M2C_FIELD(map, s16 *, 0x52C4);

    if (flags & 0x8) {
        func_020d549c((char *)map + 0x5200);
        return 1;
    }
    if (flags & 0x4) {
        func_020c752c();
        return 1;
    }
    if (flags & 0x100) {
        CreateMapMenu();
        return 1;
    }
    if (flags & 0x400) {
        HandleUiCancel();
        return 0;
    }
    if (flags & 0x200) {
        u16 w = M2C_FIELD(map, u16 *, 0x52A4);
        entry = func_020d2e3c(w);
        if (entry != 0) {
            PlaySoundEffect((void *)0x1001A);
            return StepMapViewToTile(*(u8 *)((char *)entry + 1), *(u8 *)((char *)entry + 2));
        }
    }

    {
        u16 infoFlags = M2C_FIELD(gKeyState, u16 *, 0);
        if (infoFlags & 0x1) {
            s32 res = ConfirmCursorTile((s16)x, (s16)y, 1, 1, 0);
            if (res != 0) {
                return 1;
            }
        }
        if (!(M2C_FIELD(gKeyState, u16 *, 0) & 0x2)) {
            return 0;
        }
    }
    {
        s32 *map2 = *gCurrentMap;
        s16 xx = M2C_FIELD(map2, s16 *, 0x52C2);
        s16 yy = M2C_FIELD(map2, s16 *, 0x52C4);
        SelectCursorTarget(xx, yy);
    }
    return 1;
}

/* Button input for the battle-map aiming cursor: A confirms, B cancels, R opens
 * the map menu and X closes the cursor; an A press also clears the pending
 * touch-confirm flag, as the button overrides a stylus confirm. */
s32 GetAimCursorKeyAction(void) {
    extern void *gKeyState;
    extern u8 gTouchConfirmFlag;
    u16 pressed = M2C_FIELD(gKeyState, u16 *, 0);

    if (pressed & KEY_A) {
        gTouchConfirmFlag = 0;
        return MAP_ACTION_CONFIRM;
    }
    if (pressed & KEY_B) return MAP_ACTION_CANCEL;
    if (pressed & KEY_R) return MAP_ACTION_MENU;
    if (pressed & KEY_X) return MAP_ACTION_CLOSE;
    return 0;
}

s32 func_020bcac0(void) {
    extern void *gKeyState;
    if (M2C_FIELD(gKeyState, u16 *, 0) & 2) {
        return 0x20;
    }
    if (M2C_FIELD(gKeyState, u16 *, 6) & 2) {
        return 0;
    }
    return 0x20;
}

s32 func_020bcaf0(void) {
    extern void *gKeyState;
    u16 temp_r0;

    temp_r0 = M2C_FIELD(gKeyState, u16 *, 0);
    if (temp_r0 & 1) {
        return 0x10;
    }
    if (temp_r0 & 2) {
        return 0x20;
    }
    if (temp_r0 & 0x100) {
        return 0x100;
    }
    if (temp_r0 & 0x400) {
        return 0x40;
    }
    return 0;
}

/* Step a menu's selection index with the D-pad's auto-repeat: right/down picks
 * the next entry, left/up the previous, wrapping around the `count` entries. */
void MoveSelectionWithKeys(s32 *selection, s32 count) {
extern void *gKeyState;
if(((KeyState *)gKeyState)->repeat&(KEY_RIGHT|KEY_DOWN)) {
(*selection)++;
if(*selection==count) *selection=0;
}
if(((KeyState *)gKeyState)->repeat&(KEY_LEFT|KEY_UP)) {
if(*selection<=0) *selection=count;
(*selection)--;
}
}

