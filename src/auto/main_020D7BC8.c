/* 37 functions from 0x020D7BC8 to 0x020D8BB4 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline u16 TerrainSpriteY(s32 y) { return (u16)y; }
/* The OBJ boundary value, bits 13..14 of the current sprite bank's flags word
 * (DS3D_BANK_OBJ_BOUNDARY_MASK >> 13): the shift the terrain and unit sprites
 * scale their tile numbers by. */
#define DS3D_BOUNDARY_SHIFT ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)

#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Draws a unit's status panel at (x,y): kind icon, health bars, ammo, attack and
 * movement icons plus the owning player's colour strip. */
void DrawUnitStatus(s32 x,s32 y,s32 side,void *unit) {
extern void **gCurrentMap;
extern void *gCur3DSpriteEngine;
extern u8 gSpriteDesc8x8[],gSpriteDesc32x16[],gSpriteDesc16x16[];
s32 GetUnitKind(void *);
s32 GetUnitHealthBarCount(void *);
s32 func_ov000_0216cd2c(void *);
s32 GetUnitAmmo(void *);
s32 func_ov000_0216cd4c(s32);
s32 GetUnitIconTiles(s32,s32);
s32 GetArmyPalette(s32);
void QueueMemoryCopy(s32,s32,s32,s32);
void CopyToObjPaletteShadow(s32,s32,s32);
s32 func_020a8604(s32);
s32 func_020a7c68(s32);
void DrawDecimalNumber(s32,s32,s32);
void AddSprite(u16,u16,u16,void *,s32);
s32 unitKind=GetUnitKind(unit);
s32 colorIndex,variantIndex,screenY;
s32 unitId;
u8 *playerData;
if(unit==0)unitId=0;else unitId=((s32)unit-(s32)((u8 *)*gCurrentMap+0x59a4))/14;
playerData=(u8 *)*gCurrentMap+0x67a4+((unitId>>6)+1)*140;
colorIndex=playerData[0x1d];variantIndex=playerData[0x29];
screenY=(y+16)&255;
AddSprite((u16)((x+23)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (22 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+39)&511,screenY,GetUnitHealthBarCount(unit));
AddSprite((u16)((x+47)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (24 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+63)&511,screenY,func_ov000_0216cd2c(unit));
if(func_020a8604((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)) {
AddSprite((u16)((x+71)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (58 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}else{
AddSprite((u16)((x+71)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (26 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}
if(func_020a7c68((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0) {
AddSprite((u16)((x+79)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (20 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}else{
DrawDecimalNumber((x+79)&511,screenY,GetUnitAmmo(unit));
}
QueueMemoryCopy(func_ov000_0216cd4c(unitKind),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x4480,256,0);
AddSprite((u16)((x+20)&511),(u16)((y+2)&255),(u16)((0x3ff & (0x224 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x9000),gSpriteDesc32x16,8);
CopyToObjPaletteShadow(GetArmyPalette(colorIndex),0x300,32);
QueueMemoryCopy(GetUnitIconTiles(unitKind,variantIndex),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x4300,128,0);
AddSprite((u16)((x+4)&511),(u16)((y+4)&255),(u16)((0x3ff & (0x218 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x8000),gSpriteDesc16x16,9);
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Draws the terrain panel of the map's unit-info window for the tile at
 * (tx,ty), positioned at screen (x,y): the terrain's defense stars, the
 * capture points left on a property (or the HP left of a destructible
 * terrain), and the terrain's tile graphics and owner-army palette. */
void DrawTerrainStatus(s32 x,s32 y,s32 tx,s32 ty,s32 side,void *unit) {
extern void **gCurrentMap;extern void *gCur3DSpriteEngine;
extern u8 gSpriteDesc32x8[],gSpriteDesc16x16[],gSpriteDesc8x8[],data_02101f1c[],gSpriteDesc16x32[];extern s8 gTerrainPropertyFlags[];
s32 GetCellTerrainKind(s32,s32);s32 GetCellTerrainId(s32,s32);s32 GetCellPropertyArmy(s32,s32);s32 GetCellTerrainDefense(s32,s32);
void *FindMapFeatureAtTile(s32,s32);s32 GetTerrainTileBase(s32);s32 GetTerrainTileData(s32);s32 GetTerrainPalette(s32,s32);
s32 value; u8 screenY; s32 terrainId,armyVariant,defense;void *feature;void *map;u32 cellIndex;s32 terrainKind;
terrainKind=GetCellTerrainKind(tx,ty);terrainId=GetCellTerrainId(tx,ty);armyVariant=GetCellPropertyArmy(tx,ty);defense=GetCellTerrainDefense(tx,ty);screenY=y+40;
AddSprite((u16)((x+23)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> DS3D_BOUNDARY_SHIFT)) | 0x9000) + (0x3ff & (defense*6+64 >> DS3D_BOUNDARY_SHIFT))),gSpriteDesc32x8,8);
if(gTerrainPropertyFlags[terrainKind&31]){
value=20;if(unit)value-=((u32)(M2C_FIELD(unit,u16*,6)<<16)>>27);
AddSprite((u16)((x+56)&511),(u16)((y+32)&255),(u16)(((0x3ff & (0x150 >> DS3D_BOUNDARY_SHIFT)) | 0x9000) + (0x3ff & (28 >> DS3D_BOUNDARY_SHIFT))),gSpriteDesc16x16,8);
DrawDecimalNumber((x+78)&511,screenY,value);
}else{
value=0;feature=FindMapFeatureAtTile(tx,ty);if(feature)value=M2C_FIELD(feature,u8*,4);
map=*gCurrentMap;
{s32 hp=M2C_FIELD((u8*)map+(tx+M2C_FIELD((u8*)map+ty*2,u16*,MAP_ROW_OFFSETS)),u8*,MAP_CELL_TERRAIN_HP)&127;if(hp)value=hp;}
if(value){
AddSprite((u16)((x+60)&511),TerrainSpriteY(screenY),(u16)(((0x3ff & (0x150 >> DS3D_BOUNDARY_SHIFT)) | 0x9000) + (0x3ff & (22 >> DS3D_BOUNDARY_SHIFT))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+78)&511,screenY,value);
}}
QueueMemoryCopy(GetTerrainTileBase(terrainId),M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x4580,512,0);
AddSprite((u16)((x+20)&511),(u16)((y+26)&255),(u16)((0x3ff&(0x22c>>DS3D_BOUNDARY_SHIFT))+0x9000),data_02101f1c,8);
map=*gCurrentMap;cellIndex=tx+M2C_FIELD((u8*)map+ty*2,u16*,MAP_ROW_OFFSETS);
if(!((u8)(M2C_FIELD((u8*)map+(cellIndex>>3),u8*,MAP_CELL_BITMAP)&(1<<(cellIndex&7)))))if(terrainKind!=MAP_TERRAIN_HQ)armyVariant=0;
QueueMemoryCopy(GetTerrainTileData(terrainId),M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x4200,256,0);
CopyToObjPaletteShadow(GetTerrainPalette(terrainId,armyVariant),0x2e0,32);
AddSprite((u16)((x+4)&511),(u16)((y+12)&255),(u16)((0x3ff&(0x210>>DS3D_BOUNDARY_SHIFT))+0x7000),gSpriteDesc16x32,8);
}
#pragma pop
/* Classifies the unit-info panel a map unit needs: 0 for no unit (the terrain
   panel), 2 when the unit is a transport whose carried units are shown, and 1 for
   an ordinary unit's status panel. */
s32 GetUnitPanelKind(void *unit) {
    s32 Map_ShowsCargoForUnit(u32, u16, u8);
    extern void **gCurrentMap;
    s32 unitId;
    if (unit == NULL) return 0;
    if (unit == NULL) unitId = 0;
    else unitId = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
    if (Map_ShowsCargoForUnit((u32)(M2C_FIELD(unit,u8 *,0) << 26) >> 26, M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER), (u8)((unitId >> 6)+1)) != 0) return 2;
    if ((M2C_FIELD(unit,u8 *,MAP_UNIT_FIRST_CARRIED) | M2C_FIELD(unit,u8 *,MAP_UNIT_NEXT_CARRIED)) != 0) return 2;
    return 1;
}

void func_020d8540(void) {
    extern void **gCurrentMap;
    void *temp_r0;
    temp_r0 = *gCurrentMap;
    M2C_FIELD(temp_r0,u16 *,0x52E6) = (M2C_FIELD(temp_r0,u16 *,0x52E6) & ~0x1FC) | ((u32)(M2C_FIELD(temp_r0,u16 *,0x52C2) << 25) >> 23);
    temp_r0 = *gCurrentMap;
    M2C_FIELD(temp_r0,u16 *,0x52E6) = (M2C_FIELD(temp_r0,u16 *,0x52E6) & ~0xFE00) | ((u32)(M2C_FIELD(temp_r0,u16 *,0x52C4) << 25) >> 16);
}

void func_020d8594(void) {
    /* Ease the camera height towards its target (168), using the hardware divider. */
    extern void **gCurrentMap;
    s32 Divide(s32, s32);
    void *mapData;
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) <= 0) {
        M2C_FIELD(mapData, u16 *, 0x52E6) = (M2C_FIELD(mapData, u16 *, 0x52E6) & ~3) | 1;
        mapData = *gCurrentMap;
        if (M2C_FIELD(mapData, s16 *, 0x52E4) <= -99) M2C_FIELD(mapData, s16 *, 0x52E4) = 262;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4) + 100, 2);
    }
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) > 168) {
        if (M2C_FIELD(mapData, s16 *, 0x52E4) <= 169) M2C_FIELD(mapData, s16 *, 0x52E4) = 168;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4) - 168, 2);
        func_020d8540();
    }
    if (M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) == 168) func_020d8540();
}

void func_020d867c(void) {
    /* Ease the camera height across the 0/268 wrap boundary, using the hardware divider. */
    extern void **gCurrentMap;
    s32 Divide(s32, s32);
    void *mapData;
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) >= 168) {
        M2C_FIELD(mapData, u16 *, 0x52E6) = (M2C_FIELD(mapData, u16 *, 0x52E6) & ~3);
        mapData = *gCurrentMap;
        if (M2C_FIELD(mapData, s16 *, 0x52E4) >= 267) M2C_FIELD(mapData, s16 *, 0x52E4) = -94;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4) - 268, 2);
    }
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) < 0) {
        if (M2C_FIELD(mapData, s16 *, 0x52E4) >= -1) M2C_FIELD(mapData, s16 *, 0x52E4) = 0;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4), 2);
        func_020d8540();
    }
    if (M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) == 0) func_020d8540();
}

s32 func_020d8764(void) {
    void MapTileToScreen(s16,s16,s32 *);
    extern void **gCurrentMap;
    s32 sp0[3];
    void *temp_r0 = *gCurrentMap;
    MapTileToScreen(M2C_FIELD(temp_r0,s16 *,0x52C2),M2C_FIELD(temp_r0,s16 *,0x52C4),sp0);
    if (sp0[1] > 128) return sp0[0] < 128 ? 1 : 0;
    return (u32)(M2C_FIELD(*gCurrentMap,u16 *,0x52E6) << 30) >> 30;
}

void func_020d87d8(void) {
    void func_020d8594();
    void func_020d867c(void);
    s32 func_020d8764();
    s32 temp_r0;

    temp_r0 = func_020d8764();
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_020d867c();
        return;
    case 1:
        func_020d8594();
        return;
    }
}

void func_020d8804(void) {
    extern void **gCurrentMap;
    s32 temp_r0;

    temp_r0 = func_020d8764();
    switch (temp_r0) {                              /* irregular */
    case 0:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) = 0;
        return;
    case 1:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) = 0xA8;
        return;
    }
}

void func_020d885c(s32 arg0) {
    extern s32 data_02168f28;
    data_02168f28 = arg0;
}

s32 func_020d886c(void) {
    extern s32 data_02168f28;
    return data_02168f28;
}

void func_020d887c(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212c058;
    CreateSpriteFromClass(&data_0212c058, 7);
}

M2C_UNK func_020d8894(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bfe8;
    CreateSpriteFromClass(&data_0212bfe8, 7);
}

void func_020d88ac(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212c020;
    CreateSpriteFromClass(&data_0212c020, 7);
}

M2C_UNK func_020d88c4(void) {
 M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212bfb8;
 gMapConfig=(gMapConfig&~7)|4;
 CreateSpriteFromClass(&data_0212bfb8,7);
}

void func_020d88f4(void) {
    M2C_UNK func_020d895c();
    M2C_UNK func_020d8cc4();
    func_020d8cc4();
    func_020d895c();
}

void func_020d8904(void) {
    M2C_UNK func_020d895c();
    M2C_UNK func_020d8cc4();
    func_020d8cc4();
    func_020d895c();
}

void func_020d8914(void) {
    M2C_UNK func_0209f87c();
    M2C_UNK ApplyMapSettingsToPlayers(M2C_UNK);
    func_0209f87c();
    ApplyMapSettingsToPlayers(0);
}

void func_020d8928(void) {
    s32 IsLinkSessionActive();
    extern M2C_UNK gBattleEndState;
    if (IsLinkSessionActive() == 0) {
        return;
    }
    M2C_FIELD(&gBattleEndState, s8 *, 0) = 1;
    M2C_FIELD(&gBattleEndState, s8 *, 1) = 0;
    M2C_FIELD(&gBattleEndState, s8 *, 2) = 0;
    M2C_FIELD(&gBattleEndState, s8 *, 3) = 1;
}

M2C_UNK func_020d895c(void) {
 M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c1a0;
 gMapConfig=(gMapConfig&~7)|1;
 CreateSpriteFromClass(&data_0212c1a0,7);
}

void func_020d898c(void) {
    M2C_UNK func_020d4ac8(M2C_UNK);
    extern M2C_UNK data_02168f2c;
    if (M2C_FIELD(&data_02168f2c, s8 *, 8) != 0) {
        func_020d4ac8(8);
        return;
    }
    func_020d895c();
}

M2C_UNK func_020d89b8(void) {
 M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c098;
 gMapConfig=(gMapConfig&~7)|2;
 CreateSpriteFromClass(&data_0212c098,7);
}

void func_020d89e8(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf38;
    CreateSpriteFromClass(&data_0212bf38, 7);
}

void func_020d8a00(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf78;
    CreateSpriteFromClass(&data_0212bf78, 7);
}

void func_020d8a18(void) {
    M2C_UNK func_020cd480(M2C_UNK);
    func_020cd480(0);
}

void func_020d8a28(void) {
    func_020cd480(1);
}

void func_020d8a38(void) {
    func_020cd480(2);
}

void func_020d8a48(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf58;
    CreateSpriteFromClass(&data_0212bf58, 7);
}

u8 func_020d8a60(void) {
    extern u16 gMapConfig;
    u8 var_r0;

    if ((u8) ((u32) (gMapConfig << 0x1D) >> 0x1D) == 7) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK func_020d8a8c(void) {
 M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c0d8;
 gMapConfig=(gMapConfig&~7)|6;
 CreateSpriteFromClass(&data_0212c0d8,7);
}

void func_020d8abc(void) {
    M2C_UNK func_020d8a8c();
    func_020d8a8c();
}

void func_020d8ac8(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf98;
    CreateSpriteFromClass(&data_0212bf98, 7);
}

M2C_UNK func_020d8ae0(void) {
 M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c0d8;
 gMapConfig=(gMapConfig&~7)|7;
 CreateSpriteFromClass(&data_0212c0d8,7);
}

void func_020d8b10(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf18;
    CreateSpriteFromClass(&data_0212bf18, 7);
}

void func_020d8b28(void) {
    M2C_UNK func_020d8894();
    func_020d8894();
}

void func_020d8b34(void) {
 extern M2C_UNK data_0212c260; extern M2C_UNK data_0212c264; extern M2C_UNK data_0215d9b8;
 s32 func_020d886c();
 void (*callback)(void);
 u16 value;
 callback=M2C_FIELD((u8 *)&data_0212c260+func_020d886c()*8,void (**)(void),0);
 value=M2C_FIELD((u8 *)&data_0212c264+func_020d886c()*8,u32 *,0);
 M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~15)|(value&15);
 callback();
}

s32 func_020d8b84(s32 arg0) {
    s32 func_020be120();
    M2C_UNK LoadNewestSaveRecord(M2C_UNK, s32);
    func_020be120();
    if (arg0 != 1) {
        return 1;
    }
    LoadNewestSaveRecord(8, func_020be120());
    return 1;
}

