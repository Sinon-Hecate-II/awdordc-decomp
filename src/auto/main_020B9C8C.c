/* 24 functions from 0x020B9C8C to 0x020BAC24 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
static inline s32 DistanceBAAE0(s32 x,s32 y,s32 xx,s32 yy) { s32 d=0; if(x-xx>0)d+=x-xx;else d+=xx-x; if(y-yy>0)d+=y-yy;else d+=yy-y; return d; }
typedef struct { u8 pad0[0x508]; u8 cells[0x3250]; u16 rows[0x40]; u8 pad37d8[0x196c]; u16 width,height; u8 pad5148[0x85c]; u8 units[256][14]; } MapBAAE0;

/* Load the unit-production menu over the current battle map: run the map/screen
 * setup, reset the sprite bank's split corners, pull the menu's graphics
 * (menu_seisan) from its archive into the sprite engine's texture, tile-buffer
 * and palette areas, lay out the unit list and refresh the screen object. */
void LoadProductionMenuScreen(u8 *screen) {
 void func_020994e0(s32); void LoadScenePanelGraphicsOnBothEngines(void); void func_020c0a88(void);
 void RefreshMapView(void); void SetFileDirectory(void *);
 M2C_UNK GetLocalizedFileName(void *); void OpenNarcArchive(void);
 void LoadNarcFileDecompressed(M2C_UNK,M2C_UNK); void LoadNarcFileToSpriteBuffer(M2C_UNK,s32,s32); void CloseNarcArchive(void);
 void AddToU16Array(M2C_UNK,s32,s32); void func_020b9bec(void); void func_020b9c40(void);
 void PlaySoundEffect(s32); void DrawProductionUnitPreview(u8); void CreateMenuUnitSprite(void *);
 extern void **gCurrentMap; extern void *gCur3DSpriteEngine;
 extern M2C_UNK sProductionMenuDir; extern M2C_UNK sProductionMenuNarcName;
 extern M2C_UNK sProductionMenuCgName; extern M2C_UNK sProductionMenuScName; extern M2C_UNK sProductionMenuClName;
 extern u8 gProductionMenuState[];
 void (*mapCallback)(void);
 func_020994e0(0);
 LoadScenePanelGraphicsOnBothEngines();
 func_020c0a88();
 mapCallback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x54);
 if(mapCallback)mapCallback();
 RefreshMapView();
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=0;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=0;
 M2C_FIELD(screen,u16 *,0x34)=0;
 M2C_FIELD(screen,u16 *,0x36)=0;
 SetFileDirectory(&sProductionMenuDir);
 GetLocalizedFileName(&sProductionMenuNarcName);
 OpenNarcArchive();
 LoadNarcFileDecompressed(GetLocalizedFileName(&sProductionMenuCgName),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x14)+0x2480);
 LoadNarcFileDecompressed(GetLocalizedFileName(&sProductionMenuScName),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28));
 LoadNarcFileToSpriteBuffer(GetLocalizedFileName(&sProductionMenuClName),0xc0,0x20);
 CloseNarcArchive();
 AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28),0x100,0x6124);
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 func_020b9bec(); func_020b9c40();
 PlaySoundEffect(0x10017);
 DrawProductionUnitPreview(gProductionMenuState[8]);
 CreateMenuUnitSprite(screen);
}

void func_020b9dc8(void) {

}

void func_020b9dcc(void) {
 void func_020b9978(void); void Clear3DSpriteLayer(s32); void func_0207a668(void); void func_020b2268(void);
 extern void **gCurrentMap;
 extern void *gCur3DSpriteEngine;
 void (*callback)(void);
 func_020b9978();
 Clear3DSpriteLayer(2);
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),4);
 if(callback) callback();
 func_0207a668(); func_020b2268();
}

s32 CanBuildUnitKind(s32 arg0, s32 arg1) {
 s32 func_020b9e70(s32,s32); s32 func_020b9ec0(s32,s32);
 extern M2C_UNK gMapConfig;
 if(M2C_FIELD(&gMapConfig,u32 *,12)&(1<<(u8)arg1)) return 0;
 switch((u8)((u32)(M2C_FIELD(&gMapConfig,u16 *,0)<<29)>>29)) {
 case 0: return func_020b9ec0(arg0,arg1);
 case 1: default: return func_020b9e70(arg0,arg1);
 }
}

s32 func_020b9e70(s32 arg0,s32 arg1) {
 s32 func_020a7bbc(s32);
 extern M2C_UNK data_ov000_021aab78;
 if(M2C_FIELD(&data_ov000_021aab78,s8 *,arg1)==-1) return 0;
 if(func_020a7bbc(arg1)==0) return 0;
 switch(arg1) { case 17: return 0; default: return 1; }
}

/* Report whether facility type `facility` is available on the current map in
 * mode 0: reject it if the per-facility table (data_ov000_021aab78) marks it
 * invalid (-1) or its attribute word (data_ov000_021b5c00[type*0x70]) is zero;
 * otherwise each facility type is blocked on the special maps whose id lies in
 * [0xa1, limit] (larger limits cover more facilities). */
s32 func_020b9ec0(s32 unit, s32 facility) {
    s32 func_020a7bbc(s32);
    s32 func_ov004_02213820(void);
    extern M2C_UNK data_ov000_021aab78;
    extern void **gCurrentMap;
    u16 mapId;
    (void)unit;
    if (M2C_FIELD(&data_ov000_021aab78, s8 *, facility) == -1) return 0;
    if (func_020a7bbc(facility) == 0) return 0;
    switch (facility) {
    case 17:
        return 0;
    default:
        switch (facility) {
        case 8:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xaa) return 0;
            break;
        case 9:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xae) return 0;
            break;
        case 26:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa5) return 0;
            if (mapId == 0xa5 && func_ov004_02213820() == 0) return 0;
            break;
        case 6: case 11: case 12:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa6) return 0;
            break;
        case 18: case 19:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa7) return 0;
            break;
        case 13: case 14: case 15: case 16:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xa8) return 0;
            break;
        case 24: case 25:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xaa) return 0;
            break;
        case 20: case 22: case 23:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xab) return 0;
            break;
        case 21:
            mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
            if (mapId >= 0xa1 && mapId <= 0xac) return 0;
            break;
        }
        return 1;
    }
}

#pragma opt_common_subs off
/* Report whether a unit of kind `kind` may enter tile (x, y): the tile must be
 * on the map and hold no unit (the one a fogged viewer can see, or the real one
 * when useVisibleUnits is 0), and the kind's movement-cost row must allow the
 * tile's terrain. */
s32 CanUnitKindEnterTile(s32 x,s32 y,s32 kind,s32 useVisibleUnits) {
extern void **gCurrentMap;
extern u8 gMovementTypeTable[];
extern M2C_UNK gMovementCostTable;
u8 *p; s32 cell;
if(x<0 || y<0)goto fail;
p=*gCurrentMap;
if(x>=M2C_FIELD(p,u16 *,MAP_WIDTH)||y>=M2C_FIELD(p,u16 *,MAP_HEIGHT))goto fail;
goto valid;
fail:return 0;
valid:
if(useVisibleUnits){
cell=x+M2C_FIELD(p+y*2,u16 *,MAP_ROW_OFFSETS);
if(M2C_FIELD(p+cell,u8 *,MAP_CELL_VISIBLE_UNIT))return 0;
}else{
cell=x+M2C_FIELD(p+y*2,u16 *,MAP_ROW_OFFSETS);
if(M2C_FIELD(p+cell,u8 *,MAP_CELL_UNIT_ID))return 0;
}
if(M2C_FIELD((s8 *)M2C_FIELD(&gMovementCostTable,void **,0x64)+gMovementTypeTable[kind*UNIT_KIND_STATS_SIZE]*32,s8 *,M2C_FIELD(p+cell,u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK)<0)return 0;
return 1;
}

/* Neighbour-tile mask for the unit in record `unitId` at (x, y): set each of the
 * four directions' bit when the cell is free for the unit's kind and the player
 * is not already holding that direction. */
s32 GetUnitMoveDirections(s32 x, s32 y, s32 unitId) {
    extern void **gCurrentMap;
    s32 GetHeldMapDirections(void);
    s32 off;
    u8 *base;
    s8 mask = 0;
    if (!unitId) return mask;
    base = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS;
    off = unitId * MAP_UNIT_STRIDE;
    if (!(GetHeldMapDirections() & MAP_DIR_LEFT) && CanUnitKindEnterTile(x - 1, y, (u32)(base[off] << 26) >> 26, 1) == 1) mask |= MAP_DIR_LEFT;
    if (!(GetHeldMapDirections() & MAP_DIR_RIGHT) && CanUnitKindEnterTile(x + 1, y, (u32)(base[off] << 26) >> 26, 1) == 1) mask |= MAP_DIR_RIGHT;
    if (!(GetHeldMapDirections() & MAP_DIR_UP) && CanUnitKindEnterTile(x, y - 1, (u32)(base[off] << 26) >> 26, 1) == 1) mask |= MAP_DIR_UP;
    if (!(GetHeldMapDirections() & MAP_DIR_DOWN) && CanUnitKindEnterTile(x, y + 1, (u32)(base[off] << 26) >> 26, 1) == 1) mask |= MAP_DIR_DOWN;
    return mask;
}

#pragma opt_common_subs reset
/* Direction mask (MAP_DIR_*) of the neighbours of (x, y) that hold a unit on the
 * same team as `unit`: a friendly unit sets its side's bit, anything else leaves
 * it clear. */
s8 GetAdjacentAllyDirections(s32 unit, s32 x, s32 y) {
    s32 IsFriendlyUnitAt(s32, s32, s32);
    s8 mask = 0;

    if (IsFriendlyUnitAt(unit, x - 1, y) == 1) mask |= MAP_DIR_LEFT;
    if (IsFriendlyUnitAt(unit, x + 1, y) == 1) mask |= MAP_DIR_RIGHT;
    if (IsFriendlyUnitAt(unit, x, y - 1) == 1) mask |= MAP_DIR_UP;
    if (IsFriendlyUnitAt(unit, x, y + 1) == 1) mask |= MAP_DIR_DOWN;
    return mask;
}

/* Whether `unit` can attack a direct (range 1) target right now: its kind has a
 * weapon that needs no ammo, or it still has ammo and its maximum range is 1. */
u8 CanUnitAttackDirectly(void *unit) {
 extern u8 gUnitKindInfiniteAmmo[];
 s32 GetUnitAttackRangeMax();
 u8 var_r0;
 if (gUnitKindInfiniteAmmo[((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)*UNIT_KIND_STATS_SIZE] == 1) return 1;
 if(GetUnitAttackRangeMax(unit)!=1)return 0;
 if(((u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO)<<21)>>28)!=0)var_r0=1;else var_r0=0;
 return var_r0;
}

u8 func_020ba414(void *arg0) {
    s32 GetUnitAttackRangeMax();
    u8 var_r0;

    if (GetUnitAttackRangeMax() < 2) {
        return 0U;
    }
    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Report whether the tile (x, y) holds a unit the viewing side can see that is
 * on the same team as `unit`: the tile must be on the map and occupied, and its
 * unit record must belong to the same owner. */
s32 IsFriendlyUnitAt(s32 unit, s32 x, s32 y) {
    extern void **gCurrentMap;
    s32 IsCellUnitEmpty(s32, s32);
    s32 func_020a81c8(void *);
    s32 func_020d277c(s32, void *);
    u8 *map, *base;
    s32 offset;
    u8 result;
    if (x < 0 || y < 0) goto fail;
    map = *gCurrentMap;
    if (x >= M2C_FIELD(map, u16 *, MAP_WIDTH) || y >= M2C_FIELD(map, u16 *, MAP_HEIGHT)) goto fail;
    goto valid;
fail:
    return 0;
valid:
    if (IsCellUnitEmpty(x, y)) return 0;
    map = *gCurrentMap;
    base = map + MAP_UNIT_RECORDS;
    offset = (s16)map[x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)] * (s16)MAP_UNIT_STRIDE;
    if (!func_020a81c8(base + offset)) return 0;
    if (func_020d277c(unit, base + offset)) result = 1; else result = 0;
    return result;
}

/* True when the cell (x, y) holds a unit of the cursor's owner, other than the
 * selected unit, that still needs resupply: its kind may be resupplied and it is
 * low on ammo (transports only count fuel) or on fuel. */
s32 IsSupplyTargetAt(s32 x, s32 y) {
    extern void **gCurrentMap;
    extern u8 gUnitKindSupplyFlag[], gUnitKindMaxAmmo[], gUnitKindMaxFuel[];
    s32 UnitKindCanSupply(s32);
    u8 *map, *unit;
    s32 unitId;

    if (x < 0 || y < 0) goto fail;
    map = *gCurrentMap;
    if (x >= M2C_FIELD(map, u16 *, MAP_WIDTH) || y >= M2C_FIELD(map, u16 *, MAP_HEIGHT)) goto fail;
    goto valid;
fail:
    return 0;
valid:
    unitId = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_UNIT_ID);
    if (!unitId) return 0;
    if ((unitId & 0xC0) != M2C_FIELD(map, u16 *, MAP_CURSOR_OWNER)) return 0;
    unit = map + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
    if (unit == M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT)) return 0;
    if (!gUnitKindSupplyFlag[((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26) * UNIT_KIND_STATS_SIZE]) return 0;
    if (UnitKindCanSupply((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26) || gUnitKindMaxAmmo[((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26) * UNIT_KIND_STATS_SIZE] == ((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO) << 21) >> 28)) {
        if (gUnitKindMaxFuel[((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26) * UNIT_KIND_STATS_SIZE] == ((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_FUEL) << 25) >> 25)) return 0;
    }
    return 1;
}

/* Check whether the unit carried in slot `slot` may be dropped at tile (x, y): the
 * carried kind must have a legal direction there, and the tile must be allowed for a
 * carrier of movement type 7 and enterable by the carried unit's own movement type. */
s32 CanDropCarriedUnit(s32 arg0,s32 x,s32 y,s32 slot){
extern void **gCurrentMap;extern u8 gMovementTypeTable[];extern s8 gUnitProductionTerrain[];extern M2C_UNK gMovementCostTable;
s32 GetUnitMoveDirections(s32,s32,s32);
u8 *carrier=(u8 *)arg0,*map,*cargoUnit,*cargoIds=carrier+12;s32 kind,tile;s16 n;
if(!GetUnitMoveDirections(x,y,cargoIds[slot]))return 0;
map=*gCurrentMap;
cargoUnit=map+MAP_UNIT_RECORDS+(s16)cargoIds[slot]*(s16)MAP_UNIT_STRIDE;
if(gMovementTypeTable[((u32)(carrier[0]<<26)>>26)*UNIT_KIND_STATS_SIZE]==7){
if(!gUnitProductionTerrain[M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK])return 0;
}
if(M2C_FIELD((s8 *)M2C_FIELD(&gMovementCostTable,void **,0x64)+gMovementTypeTable[((u32)(cargoUnit[0]<<26)>>26)*UNIT_KIND_STATS_SIZE]*32,s8 *,M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK)==-1)return 0;
return 1;
}

void CanDropFirstCarriedUnit(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK CanDropCarriedUnit(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    CanDropCarriedUnit(arg0, arg1, arg2, 0);
}

void CanDropSecondCarriedUnit(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    CanDropCarriedUnit(arg0, arg1, arg2, 1);
}

u8 func_020ba790(s32 x,s32 y){
extern void **gCurrentMap;extern u8 gMovementTypeTable[];extern s8 gUnitProductionTerrain[];extern M2C_UNK gMovementCostTable;
s32 CanUnitLoadKind(void *,s32);
u8 *base=*gCurrentMap,*units=base+0x59a4;s32 offset,kind,tile;u8 *selected;u8 id;
id=base[x+M2C_FIELD(base+y*2,u16 *,0x3758)];offset=(s16)id*(s16)14;
if(!id)return 0;
if((id&0xc0)!=(M2C_FIELD(base,u8 *,0x52d4)&0xc0))return 0;
if(!CanUnitLoadKind(units+offset,(u32)(M2C_FIELD(M2C_FIELD(base,u8 **,0x52d0),u8 *,0)<<26)>>26))return 0;
base=*gCurrentMap;selected=M2C_FIELD(base,u8 **,0x52d0);
if(selected[1]==x&&selected[2]==y)return 0;
kind=gMovementTypeTable[((u32)(units[offset]<<26)>>26)*112];
if(kind==7){if(!gUnitProductionTerrain[M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),u8 *,0x1420)&31])return 0;}
tile=M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),u8 *,0x1420)&31;
if(M2C_FIELD((s8 *)M2C_FIELD(&gMovementCostTable,void **,0x64)+kind*32,s8 *,tile)==-1)return 0;
return M2C_FIELD((s8 *)M2C_FIELD(&gMovementCostTable,void **,0x64)+gMovementTypeTable[((u32)(selected[0]<<26)>>26)*112]*32,s8 *,tile)!=-1;
}

/* Property flags of the terrain kind at cell (x, y): 0 when the cell's owner
 * bits put it on the cursor unit's team (an own property is not a capture
 * target), otherwise its entry in gTerrainPropertyFlags (1 for the capturable
 * property kinds). */
s32 GetTerrainPropertyFlagsAt(s32 x, s32 y) {
    extern void **gCurrentMap;
    extern u8 gTerrainPropertyFlags[];
    s32 IsTerrainOnUnitTeam(s32, s32);
    s32 map = (s32)*gCurrentMap;
    u8 terrain = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN);
    if (IsTerrainOnUnitTeam(M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID), terrain)) return 0;
    return gTerrainPropertyFlags[terrain & MAP_TERRAIN_KIND_MASK];
}

/* Report whether the unit standing at (x, y) can be selected: the cell must be
 * on the map, hold a unit, and that unit must belong to the player the view
 * belongs to (MAP_CURRENT_PLAYER) and not have acted yet (UNIT_FLAG_ACTED clear). */
u8 IsSelectableUnitAt(s32 x,s32 y) {
 extern void **gCurrentMap;
 u8 *map; s32 unitId; u8 result;
 if(x<0||y<0)goto fail;
 map=*gCurrentMap;
 if(x>=M2C_FIELD(map,u16 *,MAP_WIDTH)||y>=M2C_FIELD(map,u16 *,MAP_HEIGHT))goto fail;
 goto valid;
 fail:return 0;
 valid:unitId=map[x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)];
 if(!unitId)return 0;
 if((unitId>>MAP_UNIT_OWNER_SHIFT)+1!=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER))return 0;
 if(M2C_FIELD(map+unitId*MAP_UNIT_STRIDE,u16 *,MAP_UNIT_RECORDS+MAP_UNIT_FLAGS)&UNIT_FLAG_ACTED)result=0;else result=1;
 return result;
}

#pragma opt_if-conversion off
s32 IsMissileSiloCell(s32 a,s32 b) {
 extern void **data_027e0058;
 s32 p=(s32)*data_027e0058;
 switch(M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31){case MAP_TERRAIN_SILO:return 1;default:return 0;}
}
#pragma opt_if-conversion on
void ClearCursorUnitCapture(void) {
 extern void **gCurrentMap;
 void *p=*gCurrentMap;
 void *q;
 if(M2C_FIELD(p,s16 *,0x52d8)==M2C_FIELD(p,s16 *,0x52dc) && M2C_FIELD(p,s16 *,0x52da)==M2C_FIELD(p,s16 *,0x52de))return;
 q=M2C_FIELD(p,void **,0x52d0);
 M2C_FIELD(q,u16 *,6)&=~0xf800;
}

void func_020baaac(void) {
 extern void **gCurrentMap;
 void *p;
 p=*gCurrentMap;
 M2C_FIELD(p,s16 *,0x52d8)=M2C_FIELD(p,s16 *,0x52dc);
 p=*gCurrentMap;
 M2C_FIELD(p,s16 *,0x52da)=M2C_FIELD(p,s16 *,0x52de);
}

void func_020baae0(s16 x,s16 y) {
extern void **gCurrentMap;
MapBAAE0 *p; s32 d; s32 xx; s32 right; s32 yy; s32 bottom; s32 left=x-1; s32 top; u8 *unit;
if(left<0)left=0;
top=y-1;p=*gCurrentMap;if(top<0)top=0;
right=p->width-1 < x+1 ? p->width-1 : x+1;
bottom=p->height-1 < y+1 ? p->height-1 : y+1;
for(yy=top;yy<=bottom;yy++)for(xx=left;xx<=right;xx++){
d=DistanceBAAE0(x,y,xx,yy);
if(d<1 || d>1)continue;
p=*gCurrentMap;
unit=p->units[p->cells[xx+p->rows[yy]]];
if(((u32)(unit[0]<<26)>>26) && (M2C_FIELD(unit,u16 *,4)&32))M2C_FIELD(unit,u16 *,4)|=64;
}
}

void RevealUnitsAroundCursor(void) {
    void func_020baae0(s16, s16);
    extern void **gCurrentMap;
    void *temp_r0;

    temp_r0 = *gCurrentMap;
    func_020baae0(M2C_FIELD(temp_r0, s16 *, 0x52DC), M2C_FIELD(temp_r0, s16 *, 0x52DE));
}

