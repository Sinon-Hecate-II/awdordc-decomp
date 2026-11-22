/* 42 functions from 0x020C6CF8 to 0x020C7CD0 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u32 value:8; u32 rest:24; } Bits020a8c10;

void func_020c6cf8(void) {
    M2C_UNK func_020d468c();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;
    func_020d468c();
    DeleteMapMenuSprites();
    SetBattleCommand(0xA, M2C_FIELD(*gCurrentMap, u8 *, 0x52D4), 0, 0);
}

void func_020c6d30(void) {
    M2C_UNK func_020d468c();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;
    func_020d468c();
    DeleteMapMenuSprites();
    SetBattleCommand(0xB, M2C_FIELD(*gCurrentMap, u8 *, 0x52D4), 0, 0);
}

/* Attack command: clear the map layer, mark the cursor unit's cell and attack
 * range, open the target-selection sprite and close the action menu. */
void StartAttackTargetSelection(void) {
    extern void **gCurrentMap;
    void *map;
    void (*callback)(void);

    FillMapLayer(-1);
    map = *gCurrentMap;
    M2C_FIELD((u8 *)map + M2C_FIELD(map, s16 *, MAP_CURSOR_Y) * 4, u8 **, MAP_GRID)[M2C_FIELD(map, s16 *, MAP_CURSOR_X)] = 1;
    map = *gCurrentMap;
    MarkUnitAttackRange(M2C_FIELD(map, s16 *, MAP_CURSOR_X), M2C_FIELD(map, s16 *, MAP_CURSOR_Y), M2C_FIELD(map, s32 *, MAP_CURSOR_UNIT));
    CreateTargetSelectionSprite();
    DeleteMapMenuSprites();
    callback = M2C_FIELD(gCurrentMap[1], void (**)(void), 0x3C);
    if (callback == NULL) return;
    callback();
}

void func_020c6dec(void) {
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK func_020bbd8c();
    func_020bbd8c();
    DeleteMapMenuSprites();
}

/* Returns 0 when the current player may select the unit under the cursor: the
 * cursor must have just moved onto it, its tile, the map rules, the player's
 * army and commander must all allow it, and the player must be able to afford
 * it; otherwise returns 2. Human counterpart of FindBestSelectableUnit. */
s32 CanSelectCursorUnit(void) {
extern void **gCurrentMap; extern u16 gMapConfig;
s32 IsUnitSelected(void *);s32 func_020cf908(s32,s32,s32,s32);
s32 GetMapPlayerFlags(s32,s32);s32 GetPlayerSelectedUnit(s32);s32 func_020a3150(s32);
s32 func_020a88e8(s32);s32 GetPlayerCommanderId(s32);s32 func_020a735c(void *);
s32 func_020a2788(s32,s32);s32 GetUnitActionCost(s32,s32);
u8 *map; s32 value; s32 unitKind; s32 player;
if(((u32)(gMapConfig<<18)>>31)==0)return 2;
map=*gCurrentMap;
if(M2C_FIELD(map,s16 *,MAP_CURSOR_X)!=M2C_FIELD(map,s16 *,MAP_CURSOR_OLD_X) || M2C_FIELD(map,s16 *,MAP_CURSOR_Y)!=M2C_FIELD(map,s16 *,MAP_CURSOR_OLD_Y))return 2;
if(IsUnitSelected(M2C_FIELD(map,void **,MAP_CURSOR_UNIT)))return 2;
map=*gCurrentMap;
if(!func_020cf908(M2C_FIELD(map,s16 *,MAP_CURSOR_X),M2C_FIELD(map,s16 *,MAP_CURSOR_Y),M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER),(u32)(M2C_FIELD(M2C_FIELD(map,void **,MAP_CURSOR_UNIT),u8 *,0)<<26)>>26))return 2;
map=*gCurrentMap;
if(GetMapPlayerFlags(M2C_FIELD(map,u16 *,MAP_ID),M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER))&64)return 2;
map=*gCurrentMap;player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
if(M2C_FIELD(map+player*MAP_PLAYER_STRIDE,Bits020a8c10 *,MAP_PLAYER_STATES+PLAYER_REC_SPRITE).value==0)return 2;
if(GetPlayerSelectedUnit(player))return 2;
if(!func_020a3150(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))return 2;
if(func_020a88e8(M2C_FIELD(*gCurrentMap,u16 *,MAP_ID)))return 2;
value=GetPlayerCommanderId(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER));
unitKind=func_020a735c(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT));
if(!func_020a2788(value,unitKind))return 2;
map=*gCurrentMap;player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
value=GetUnitActionCost(player,(u32)(M2C_FIELD(M2C_FIELD(map,void **,MAP_CURSOR_UNIT),u8 *,0)<<26)>>26);
return value>M2C_FIELD(map+player*MAP_PLAYER_STRIDE,s32 *,MAP_PLAYER_STATES)?2:0;
}

void func_020c6ffc(void) {
    M2C_UNK func_020d468c();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;
    func_020d468c();
    DeleteMapMenuSprites();
    SetBattleCommand(0x16, M2C_FIELD(*gCurrentMap, u8 *, 0x52D4), 0, 0);
}

/* Availability check for activating the current player's CO power: returns 0 when
 * no unit sits under the cursor, the cursor unit is the player's selected unit and
 * that player's CO power meter is full; otherwise returns 2. */
s32 CanActivateCoPower(void) {
    s32 IsPlayerCoPowerReady(u16);
    s32 GetPlayerSelectedUnit();
    M2C_UNK GetUnitOwner(s32);
    extern void **gCurrentMap;
    void *map;

    map = *gCurrentMap;
    if (((u8 *)map)[M2C_FIELD(map, s16 *, MAP_CURSOR_X) + M2C_FIELD((u8 *)map + M2C_FIELD(map, s16 *, MAP_CURSOR_Y) * 2, u16 *, MAP_ROW_OFFSETS)] != 0) {
        return 2;
    }
    GetUnitOwner(M2C_FIELD(map, s32 *, MAP_CURSOR_UNIT));
    if ((M2C_FIELD(map, s32 *, MAP_CURSOR_UNIT) == GetPlayerSelectedUnit()) && (IsPlayerCoPowerReady(M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)) != 0)) {
        return 0;
    }
    return 2;
}

void func_020c70b4(void) {
    M2C_UNK func_020d468c();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;
    func_020d468c();
    DeleteMapMenuSprites();
    SetBattleCommand(0xE, M2C_FIELD(*gCurrentMap, u8 *, 0x52D4), 0, 0);
}

/* Availability check for the kind-13 unit (the Rig) command that builds a
 * temporary airfield on the tile under the cursor: the acting unit must be a
 * kind-13 transport that still has ammo, the cursor tile must be plain ground
 * with no friendly unit the acting unit could join or load, and the map's hidden
 * terrain must still be saveable.  Returns 0 when the command may be issued and
 * 2 when it may not.  Its twin CanBuildTemporaryPort is the same check for a
 * shoal tile. */
s32 CanBuildTemporaryAirfield(void){
 extern void **gCurrentMap;s32 CanJoinUnitAtCursor(void);s32 CanLoadUnitAtCursor(void);s32 CanSaveHiddenTerrainMap(void);
 u8 *map;
 if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u8 *,0)<<26)>>26)!=13)return 2;
 if(!CanJoinUnitAtCursor())return 2;
 if(!CanLoadUnitAtCursor())return 2;
 map=*gCurrentMap;
 if((M2C_FIELD(map+(M2C_FIELD(map,s16 *,MAP_CURSOR_X)+M2C_FIELD(map+M2C_FIELD(map,s16 *,MAP_CURSOR_Y)*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK)!=MAP_TERRAIN_PLAIN)return 2;
 if(((u32)(M2C_FIELD(M2C_FIELD(map,void **,MAP_CURSOR_UNIT),u16 *,MAP_UNIT_AMMO)<<21)>>28)==0)return 2;
 if(CanSaveHiddenTerrainMap())return 0;return 2;
}

/* Availability check for a cursor-unit command: the cursor unit must be kind 13,
 * the tile under the cursor must hold a same-kind unit it can combine with and be
 * enterable by the selected unit, the tile's terrain must be kind 9, the unit must
 * still have ammo and the map must still be saveable.  Returns 0 when the command
 * may be issued and 2 when it may not. */
s32 CanBuildTemporaryPort(void) {
    s32 CanJoinUnitAtCursor(void);
    s32 CanLoadUnitAtCursor(void);
    s32 CanSaveHiddenTerrainMap(void);
    extern void **gCurrentMap;
    void *map;
    s32 x, y;
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, 0) << 26) >> 26) != 13) return 2;
    if (!CanJoinUnitAtCursor()) return 2;
    if (!CanLoadUnitAtCursor()) return 2;
    map = *gCurrentMap;
    y = M2C_FIELD(map, s16 *, MAP_CURSOR_Y);
    x = M2C_FIELD(map, s16 *, MAP_CURSOR_X);
    if ((M2C_FIELD((char *)map + (x + M2C_FIELD((char *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK) != 9) return 2;
    if (((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u16 *, MAP_UNIT_AMMO) << 21) >> 28) == 0) return 2;
    return CanSaveHiddenTerrainMap() != 0 ? 0 : 2;
}

void func_020c727c(void) {
 M2C_UNK func_020d468c(); M2C_UNK DeleteMapMenuSprites(); M2C_UNK SetBattleCommand(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); DeleteMapMenuSprites();
 SetBattleCommand(0x18,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

/* Draw the icon of the first unit loaded in the unit under the cursor: copy the
 * carried unit's kind icon, in the colour variant of the army that owns it, to
 * sprite tile 0x23c and set that entry and its palette up.  Nothing to do when
 * the unit carries nothing. */
void DrawFirstCarriedUnitIcon(void) {
 s32 GetUnitIconTiles(s32,s32); s32 GetArmyPalette(s32);
 void QueueMemoryCopy(s32,void *,s32,s32); void CopyToObjPaletteShadow(s32,s32,s32); void SetCarriedUnitIconSprite(s32,s32,s32,s32,s32);
 extern void **gCurrentMap; extern void *gCur3DSpriteEngine;
 u8 *base; u8 *player; s32 carriedId; s32 tiles; s32 armyIndex;
 base = *gCurrentMap;
 carriedId = M2C_FIELD(M2C_FIELD(base,void **,MAP_CURSOR_UNIT),u8 *,MAP_UNIT_CARRIED);
 if(carriedId == 0) return;
 player = base + MAP_PLAYER_STATES + ((carriedId >> 6)+1)*MAP_PLAYER_STRIDE;
 tiles = M2C_FIELD(base + carriedId*MAP_UNIT_STRIDE,u8 *,MAP_UNIT_RECORDS);
 armyIndex = player[PLAYER_REC_ARMY_INDEX];
 tiles = GetUnitIconTiles((u32)(tiles << 26) >> 26,player[PLAYER_REC_SPRITE_STATE]);
 QueueMemoryCopy(tiles,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x4780,0x80,0);
 CopyToObjPaletteShadow(GetArmyPalette(armyIndex),0x340,0x20);
 SetCarriedUnitIconSprite(0,0x23c,10,2,2);
}

/* Draw the icon of the second unit loaded in the unit under the cursor: copy the
 * carried unit's kind icon, in the colour variant of the army that owns it, to
 * sprite tile 0x240 and set that entry and its palette up.  Nothing to do when
 * the unit carries no second unit. */
void DrawSecondCarriedUnitIcon(void) {
 s32 GetUnitIconTiles(s32,s32); s32 GetArmyPalette(s32);
 void QueueMemoryCopy(s32,void *,s32,s32); void CopyToObjPaletteShadow(s32,s32,s32); void SetCarriedUnitIconSprite(s32,s32,s32,s32,s32);
 extern void **gCurrentMap; extern void *gCur3DSpriteEngine;
 u8 *base; u8 *player; s32 carriedId; s32 tiles; s32 armyIndex;
 base = *gCurrentMap;
 carriedId = M2C_FIELD(M2C_FIELD(base,void **,MAP_CURSOR_UNIT),u8 *,MAP_UNIT_NEXT_CARRIED);
 if(carriedId == 0) return;
 player = base + MAP_PLAYER_STATES + ((carriedId >> 6)+1)*MAP_PLAYER_STRIDE;
 tiles = M2C_FIELD(base + carriedId*MAP_UNIT_STRIDE,u8 *,MAP_UNIT_RECORDS);
 armyIndex = player[PLAYER_REC_ARMY_INDEX];
 tiles = GetUnitIconTiles((u32)(tiles << 26) >> 26,player[PLAYER_REC_SPRITE_STATE]);
 QueueMemoryCopy(tiles,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x4800,0x80,0);
 CopyToObjPaletteShadow(GetArmyPalette(armyIndex),0x340,0x20);
 SetCarriedUnitIconSprite(1,0x240,10,2,2);
}

s32 func_020c7438(s32 arg0) {
    u32 temp_r0;

    temp_r0 = 0x20 - arg0;
    return ((s32) (temp_r0 + (temp_r0 >> 0x1F)) >> 1) * 8;
}

s32 func_020c744c(void) {
    return 0x10;
}

s32 ClampInt(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r2;

    var_r2 = arg2;
    if (arg0 < arg1) {
        return arg1;
    }
    if (arg0 <= var_r2) {
        var_r2 = arg0;
    }
    return var_r2;
}

/* Screen position for the cursor sprite over the targeted map tile: project the
 * tile to screen space, then centre the cursor on the cell (or keep it inside the
 * visible area when the battle help panel covers part of the screen). */
void GetMapCursorScreenPosition(s32 tileX, s32 tileY, s32 *screenPos) {
    s32 GetViewZoom(void *);
    void MapTileToScreen(s32, s32, s32 *);
    extern void **gCurrentMap;
    extern u8 gBattleHelpPanel[];
    s32 cellSize;

    if (GetViewZoom((u8 *)*gCurrentMap + 0x6ef8) <= 0) cellSize = 16; else cellSize = 24;
    MapTileToScreen(tileX, tileY, screenPos);
    if (gBattleHelpPanel[MAP_HELP_SHOWN]) { screenPos[0] -= 24; screenPos[0] = ClampInt(screenPos[0], 0, 128); return; }
    if (screenPos[0] < 160) screenPos[0] += cellSize / 2; else screenPos[0] -= cellSize / 2 + 48;
    screenPos[1] -= cellSize / 2;
}

void func_020c752c(void) {
    M2C_UNK CreateMenuAt(M2C_UNK *, s32, s32, M2C_UNK);
    M2C_UNK func_020c0a88();
    extern M2C_UNK data_0212a8b4;
    s32 temp_r4;

    func_020994e0(0);
    func_020c0a88();
    temp_r4 = func_020c7438(0xC);
    CreateMenuAt(&data_0212a8b4, temp_r4, func_020c744c(), 0x50);
}

void func_020c7568(void) {
    M2C_UNK func_020994e0(M2C_UNK);
    M2C_UNK PopCarriedUnitMenuState();
    func_020994e0(0);
    PopCarriedUnitMenuState();
}

void func_020c757c(void) {
 M2C_UNK func_020c0634(M2C_UNK *,s32,s32,u16,s32); s32 func_020c0b9c(); extern M2C_UNK data_0212a774;
 s32 x,y;
 func_020994e0(0); func_020c0a88(); x=func_020c7438(8); y=func_020c744c();
 func_020c0634(&data_0212a774,x,y,(u16)func_020c0b9c(),0x50);
}

/* Opens the map cursor's action menu: clears the text tiles, lays the menu out at
 * the screen position of the tile the cursor is aimed at, clears the map layer,
 * then marks the cursor's cell in the map grid. */
void OpenMapActionMenu(void) {
    extern void **gCurrentMap;
    extern M2C_UNK gMapActionMenuEntries;
    M2C_UNK CreateMenuAt(M2C_UNK *, s32, s32, M2C_UNK);
    s32 screenPos[3];
    void *map;

    func_020994e0(0);
    map = *gCurrentMap;
    GetMapCursorScreenPosition(M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y), screenPos);
    CreateMenuAt(&gMapActionMenuEntries, screenPos[0], screenPos[1], 0x30);
    FillMapLayer(-1);
    map = *gCurrentMap;
    M2C_FIELD((u8 *)map + M2C_FIELD(map, s16 *, MAP_CURSOR_Y) * 4, u8 **, MAP_GRID)[M2C_FIELD(map, s16 *, MAP_CURSOR_X)] = 1;
}

void func_020c7654(void) {
    extern void **gCurrentMap;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = *gCurrentMap;
    M2C_FIELD(temp_r0, s16 *, 0x52C2) = (s16) M2C_FIELD(temp_r0, s16 *, 0x52DC);
    temp_r0_2 = *gCurrentMap;
    M2C_FIELD(temp_r0_2, s16 *, 0x52C4) = (s16) M2C_FIELD(temp_r0_2, s16 *, 0x52DE);
}

/* One frame of map-cursor input: A confirms the current target (spawns the
 * target cursor and fires map event 19), B cancels the target back to the
 * cursor tile, START opens the map menu and X runs the mode-specific action;
 * with no action key the cursor keeps moving and the view keeps panning.
 * Input is ignored while a dialog is up or the view is auto-scrolling. */
void HandleMapCursorInput(void *a) {
extern void **gCurrentMap;
s32 IsDialogActive(void *); s32 IsMapCursorIdle(void); s32 GetMapCursorKeyAction(void); s32 GetMapCursorTouchAction(void);
M2C_UNK func_020d468c(); M2C_UNK SetBattleCommand(s32,u8,s32,s32);
M2C_UNK StepMapViewToTile(s16,s16);
u32 flags=0;
if(IsDialogActive(a))return;
func_020bdfdc();
if(IsMapCursorIdle()){
flags|=GetMapCursorKeyAction();flags|=GetMapCursorTouchAction();
if(flags&16){
func_020d468c();
CreateTargetCursor(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X),M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y));
SetBattleCommand(19,M2C_FIELD(*gCurrentMap,u8 *,MAP_CURSOR_UNIT_ID),(u8)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X),(u8)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y));
Sprite_ResumeAnimation(a);return;}
if(flags&32){
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_X);
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_Y);
StepMapViewToTile(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X),M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y));
SetSpriteAnimation(a,0);Sprite_ResumeAnimation(a);return;}
if(flags&256){CreateMapMenu();return;}
if(flags&64){HandleUiCancel();return;}
}
func_020cf828(0x1001a);func_0207a7a4(1,4);StepMapCursorAndNotify(2,10);
}

void func_020c77d4(void *arg0) {
    M2C_UNK StepMapViewToTile(s16, s16);
    StepMapViewToTile(M2C_FIELD(arg0, s16 *, 0x6C), M2C_FIELD(arg0, s16 *, 0x6E));
}

void func_020c77ec(void *arg0) {
    M2C_UNK PanMapViewToTile(s32, s32);
    PanMapViewToTile(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020c7804(void *arg0) {
    M2C_UNK func_020b5f3c(s16, s16, void *);
    M2C_UNK func_020b5f74(s16, s16);
    func_020b5f3c(M2C_FIELD(arg0, s16 *, 0x6C), M2C_FIELD(arg0, s16 *, 0x6E), arg0);
    func_020b5f74(M2C_FIELD(arg0, s16 *, 0x6C), M2C_FIELD(arg0, s16 *, 0x6E));
}

void func_020c782c(void *arg0) {
    M2C_UNK CreateMissileNMarker(s32, s32, M2C_UNK, u16, void *);
    CreateMissileNMarker(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 2, M2C_FIELD(arg0, u16 *, 0x52), arg0);
}

void func_020c7850(void *arg0) {
    M2C_UNK CreateMissileEMarker(s32, s32, s32, u16, void *);
    CreateMissileEMarker(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x64), M2C_FIELD(arg0, u16 *, 0x52), arg0);
}

void func_020c7874(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212ae54;
    void *temp_r0;
    temp_r0 = CreateSpriteForOwner(&data_0212ae54, arg4);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x64) = arg2;
    M2C_FIELD(temp_r0, s16 *, 0x52) = arg3;
}

void func_020c78ac(void *arg0) {
    PanMapViewToTile(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020c78c4(void *arg0) {
    M2C_UNK CreateMissileBMarker(s32, s32, s32, u16, void *);
    CreateMissileBMarker(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x64), M2C_FIELD(arg0, u16 *, 0x52), arg0);
}

void CreateScriptMarkerSprite(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212aeec;
    void *temp_r0;
    temp_r0 = CreateSpriteForOwner(&data_0212aeec, arg4);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x64) = arg2;
    M2C_FIELD(temp_r0, s16 *, 0x52) = arg3;
}

/* State step of the flare-shot sprite: when the unit under the cursor is visible
 * to the current player, drop the unit flare on it (owned by parent) and let it
 * pan the map view onto the unit.  Team B sees every unit; for a team A player
 * the unit's cell must be set in the map's visibility bitmap. */
void DropFlareOnCursorUnitIfVisible(void *parent) {
    void CreateUnitFlareSprite(void *, void *);
    extern void **gCurrentMap;
    u8 *map;
    BattleMapUnit *unit;
    s32 y;
    u32 x;
    s32 side;
    u32 cell;
    s32 visible;

    map = *gCurrentMap;
    unit = M2C_FIELD(map, BattleMapUnit **, MAP_CURSOR_UNIT);
    side = M2C_FIELD(map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, PLAYER_SIDE_OFF);
    y = unit->y;
    x = unit->x;
    if (side & SIDE_TEAM_B) visible = 1;
    else {
        cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
        visible = 1;
        if ((u8)(M2C_FIELD(map + (cell >> 3), u8 *, MAP_CELL_BITMAP) & (1 << (cell & 7))) == 0) visible = 0;
    }
    if (visible == 0) return;
    CreateUnitFlareSprite(unit, parent);
}

void func_020c79ac(void *arg0) { void func_020b67e0(s32,s32,void *); func_020b67e0(M2C_FIELD(arg0,s32 *,0x34),M2C_FIELD(arg0,s32 *,0x38),arg0); }

void func_020c79c4(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212ae9c;
    void *temp_r0;

    temp_r0 = CreateSpriteForOwner(&data_0212ae9c, arg2);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
}

s32 GetMapRecordBuffer(void) {
    s32 GetSaveRecordBuffer();
    return GetSaveRecordBuffer();
}

s32 GetMapRecordTerrain(void) {
    return GetMapRecordBuffer() + 0x54;
}

s32 GetMapRecordHeader(void) {
    return GetMapRecordBuffer();
}

s32 GetMapRecordBufferStamp(void) {
    return GetMapRecordHeader() + 0x40;
}

s32 ComputeMapRecordChecksum(s32 arg0) {
    M2C_UNK Crc16(s32, s32);
    return Crc16(arg0 + 0x54, 0x6A4);
}

/* Validate a saved map record's header before loading it: the name must be
 * terminated, the magic and dimensions sane, the player, property and unit
 * counts in range, every player id a valid slot, and the stored CRC must match
 * the record's terrain and unit data. */
u8 IsValidMapRecord(void *p) {
s32 StringHasTerminator(void *,s32);
s32 ComputeMapRecordChecksum(s32);
s32 i;u16 checksum;
if(!StringHasTerminator(p+6,0x21))return 0;
if(((MapRecordHeader *)p)->magic!=MAP_RECORD_MAGIC)return 0;
if(((MapRecordHeader *)p)->width<5 || ((MapRecordHeader *)p)->height<5 || ((MapRecordHeader *)p)->width>30 || ((MapRecordHeader *)p)->height>30)return 0;
if(((MapRecordHeader *)p)->unitCount>200)return 0;
switch(((MapRecordHeader *)p)->playerCount){case 0:case 1:case 2:case 3:case 4:case 255:break;default:return 0;}
for(i=0;i<5;i++){
switch(M2C_FIELD(p+i,u8 *,0x28)){case 0:case 1:case 2:case 3:case 4:break;default:return 0;}
}
checksum=M2C_FIELD(p,u16 *,MAP_RECORD_CHECKSUM);
return (u8)(checksum==ComputeMapRecordChecksum((s32)p));
}

/* Packs a runtime map record into its compact saved form: copies the shared
   header and terrain cells, then moves the packed unit entries from
   MAP_RECORD_UNITS down to MAP_RECORD_SAVE_UNITS.  The source may be the
   destination, so a temporary copy of the runtime record is taken first in
   that case. */
void PackMapRecord(void *arg0, void *arg1) {
    void *HeapAllocBlock(s32);
    void MI_CpuCopy32(void *, void *, s32);
    void MI_CpuFill32(M2C_UNK, void *, M2C_UNK);
    void HeapFreeBlock(void *);
    struct MapRecordSettings { s32 a[4]; };
    struct MapRecordStamp { s32 a[5]; };
    struct PlayerIdPair { u8 a; u8 b; };
    u32 n;
    u8 *dp;
    u8 *sp;
    u8 *src;
    u8 *dst;
    s32 i;

    src = arg0;
    if (arg0 == arg1) {
        src = HeapAllocBlock(MAP_RECORD_SIZE);
        MI_CpuCopy32(arg0, src, MAP_RECORD_SIZE);
    }
    dst = arg1;
    MI_CpuFill32(0, dst, MAP_RECORD_SAVE_SIZE);
    ((MapRecordHeader *)dst)->magic = ((MapRecordHeader *)src)->magic;
    ((MapRecordHeader *)dst)->width = ((MapRecordHeader *)src)->width;
    ((MapRecordHeader *)dst)->height = ((MapRecordHeader *)src)->height;
    sp = src + 6;
    dp = dst + 6;
    n = 16;
    do {
        u8 c0 = sp[0];
        u8 c1 = sp[1];
        sp += 2;
        dp[0] = c0;
        dp[1] = c1;
        dp += 2;
    } while (--n);
    dp[0] = sp[0];
    ((MapRecordHeader *)dst)->playerCount = ((MapRecordHeader *)src)->playerCount;
    *(struct PlayerIdPair *)(dst + 0x28) = *(struct PlayerIdPair *)(src + 0x28);
    *(struct PlayerIdPair *)(dst + 0x2A) = *(struct PlayerIdPair *)(src + 0x2A);
    ((MapRecordHeader *)dst)->playerIds[4] = ((MapRecordHeader *)src)->playerIds[4];
    ((MapRecordHeader *)dst)->propertyCount = ((MapRecordHeader *)src)->propertyCount;
    ((MapRecordHeader *)dst)->unitsPerPlayer = ((MapRecordHeader *)src)->unitsPerPlayer;
    ((MapRecordHeader *)dst)->unitCount = ((MapRecordHeader *)src)->unitCount;
    *(struct MapRecordSettings *)(dst + 0x30) = *(struct MapRecordSettings *)(src + 0x30);
    sp = src + 0x40;
    {
        struct MapRecordStamp *srcStamp = (struct MapRecordStamp *)sp;
        struct MapRecordStamp *dstStamp = (struct MapRecordStamp *)(dst + 0x40);
        *dstStamp = *srcStamp;
    }
    i = 0;
    for (; i < (s32)((MapRecordHeader *)src)->width * (s32)((MapRecordHeader *)src)->height; i++)
        dst[0x54 + i] = src[0x54 + i];
    i = 0;
    for (; i < ((MapRecordHeader *)src)->unitCount; i++)
        ((s32 *)dst)[i + MAP_RECORD_SAVE_UNITS / 4] = ((s32 *)src)[i + MAP_RECORD_UNITS / 4];
    if (arg0 == arg1)
        HeapFreeBlock(src);
}

