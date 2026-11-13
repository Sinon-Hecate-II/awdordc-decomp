/* 16 functions from 0x020CE738 to 0x020CF69C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
extern u8 gTilesetDir[],sTilesetDoomPnl[],sTilesetCliffPnl[],sTilesetRuinPnl[],sTilesetFlowerPnl[],sTilesetUraPnl[],sTilesetOwlPnl[],sTilesetNormalPnl[];

#pragma opt_strength_reduction off
/* Rebuild the danger-zone bitmaps: mark every unit's threat range and, for
 * each owned property tile, its (team-coloured) influence range. */
void MarkThreatRanges(void) {
s32 func_020cd728(void);void MarkUnitThreatRange(void *);s32 IsPlayerPresent(s32);
s32 GetTerrainThreatRadius(s32,s32);void MarkThreatBitmap(s16,s16,s16,u32,u8,u8);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern s8 gTerrainPropertyFlags[];
s32 tile;s32 owner,x,y,terrainKind; s32 unitId,player,playerUnitId,unitOffset,playerOffset;u8 *unit;void *map;s16 radius;
if(func_020cd728()){
for(unitId=1,unitOffset=14;unitId<256;unitId++,unitOffset+=14){
unit=(u8 *)*gCurrentMap+0x59A4+unitOffset;
if(((u32)(unit[0]<<26)>>26)!=0)MarkUnitThreatRange(unit);
}
}else{
for(player=1,playerOffset=140;player<5;player++,playerOffset+=140){
if(IsPlayerPresent(player) && M2C_FIELD((u8 *)*gCurrentMap+playerOffset,u8 *,0x67C3)!=0){
playerUnitId=gPlayerUnitIdBase[player]+1;
if(playerUnitId<gPlayerUnitIdBase[player]+51){
unitOffset=playerUnitId*14;
do {
unit=(u8 *)*gCurrentMap+0x59A4+unitOffset;
if(((u32)(unit[0]<<26)>>26)!=0)MarkUnitThreatRange(unit);
playerUnitId++;unitOffset+=14;
}while(playerUnitId<gPlayerUnitIdBase[player]+51);
}
}
}
}
map=*gCurrentMap;
for(y=0;y<M2C_FIELD(map,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(map,u16 *,0x5144);x++,map=*gCurrentMap){
tile=M2C_FIELD(M2C_FIELD(map+y*2,u16 *,0x3758)+(map+x),u8 *,0x1420);
terrainKind=tile&31;
if(gTerrainPropertyFlags[terrainKind] && (owner=(tile&0xE0)>>5)!=0){
radius=GetTerrainThreatRadius(tile,M2C_FIELD(map,u8 *,0x5158));
MarkThreatBitmap((s16)x,(s16)y,radius,M2C_FIELD((u8 *)*gCurrentMap+owner*140,u8 *,0x67C3),(u8)owner,1);
}
if(terrainKind==26){
radius=GetTerrainThreatRadius(tile,M2C_FIELD(*gCurrentMap,u8 *,0x5158));
MarkThreatBitmap((s16)x,(s16)y,radius,3,0,1);
}
}
}
}
#pragma opt_strength_reduction reset
void func_020ce9a0(void) {
extern void **gCurrentMap;
void func_020cd7bc(u8,u8); void func_020cd754(u8);void MarkThreatRanges(void);
void *p=*gCurrentMap;
if(M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67c3)==3)
func_020cd7bc(M2C_FIELD(p,u16 *,0x52b8),M2C_FIELD(p,u16 *,0x52ba));
else func_020cd754(M2C_FIELD(p,u16 *,0x52ba));
p=*gCurrentMap;
if(M2C_FIELD(p,u8 *,0x5156)!=0 || M2C_FIELD(p,u8 *,0x5158)==2)MarkThreatRanges();
}

void func_020cea28(void){
s32 IsPlayerActive(s32);
s32 IsSameTeam(u16,s32);
s32 func_020a600c(u16);
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 player,i,id;u8 *unit;
for(player=1;player<5;player++){
if(IsPlayerActive(player)){
for(i=gPlayerUnitIdBase[player]+1;i<gPlayerUnitIdBase[player]+0x33;i++){
unit=(u8*)*gCurrentMap+0x59a4+i*14;
if(((u32)(unit[0]<<26)>>26)!=0){
M2C_FIELD(unit,u16*,4)&=~0xc0;
if(!IsSameTeam(M2C_FIELD(*gCurrentMap,u16*,0x52a4),player)&&(M2C_FIELD(unit,u16*,4)&0x20)){
if(!unit)id=0;else id=((s32)unit-(s32)((u8*)*gCurrentMap+0x59a4))/14;
if(func_020a600c((u16)id))M2C_FIELD(unit,u16*,4)|=0x40;
}
}
}
}
}
}

/* Resets the battle map to its initial state: clears the cursor-target and view
 * fields, the view-zoom record, the per-player flags and the map header, resets
 * the map units and the current player/mode/turn, then clears the display
 * buffers. */
void ResetBattleMap(void) {
    extern void **gCurrentMap;
    void func_020cbdbc(void);
    void func_0207ce28(void *);
    void func_020d4754(void);
    void func_020d47b0(void);
    void ResetMapUnits(void);
    void func_020a45cc(void);
    void MI_CpuFill32(s32, void *, s32);
    void func_0207688c(void);
    extern u16 data_02156e4c;
    s32 i;

    *(u16 *)((u8 *)*gCurrentMap + MAP_CURSOR_TARGET_X) = 0;
    *(u16 *)((u8 *)*gCurrentMap + MAP_CURSOR_TARGET_Y) = 0;
    *(u16 *)((u8 *)*gCurrentMap + 0x52c6) = 0;
    *(u16 *)((u8 *)*gCurrentMap + 0x52c8) = 0;
    func_020cbdbc();

    *(u16 *)((u8 *)*gCurrentMap + MAP_VIEW_X) = 0;
    *(u16 *)((u8 *)*gCurrentMap + MAP_VIEW_Y) = 0;
    *(u16 *)((u8 *)*gCurrentMap + 0x514c) = 0;
    *(u16 *)((u8 *)*gCurrentMap + 0x514e) = 0;
    *(u16 *)((u8 *)*gCurrentMap + MAP_VIEW_CELL_X) = 0;
    *(u16 *)((u8 *)*gCurrentMap + MAP_VIEW_CELL_Y) = 0;
    *(u8 *)((u8 *)*gCurrentMap + 0x5154) = 0;
    for (i = 0; i < 4; i++) {
        *(u8 *)((u8 *)*gCurrentMap + 0x515c + i) = 0;
    }

    func_0207ce28((u8 *)*gCurrentMap + MAP_VIEW_ZOOM);

    *(u8 *)((u8 *)*gCurrentMap + 0x52ae) = 0;
    *(u8 *)((u8 *)*gCurrentMap + 0x52af) = 0;

    func_020d4754();
    func_020d47b0();

    data_02156e4c = 0;
    *(u16 *)((u8 *)*gCurrentMap + 0x52b0) = 4;
    *(u16 *)((u8 *)*gCurrentMap + MAP_MODE) = 0;
    *(u16 *)((u8 *)*gCurrentMap + MAP_CURRENT_PLAYER) = 0;
    *(u16 *)((u8 *)*gCurrentMap + 0x52a2) = 1;

    ResetMapUnits();
    func_020a45cc();

    MI_CpuFill32(0, *gCurrentMap, 0x5120);

    func_0207688c();
}

void func_020ced08(void) {
    extern void **gCurrentMap;
    extern s8 gTerrainPropertyFlags[];
    extern u16 data_ov000_021aeee8[];
    void func_020cf2c8(void);
    s32 IsPlayerPresent(s32);
    void func_0207ab84(s32, s32, u8);
    register u8 tile;
    register s32 i;
    register s32 offset;
    register u8 xc;
    register u8 yc;
    register s32 found;
    s32 counter;

    func_020cf2c8();
    counter = 0;
    found = 0;
    offset = 0;
    do {
        void *p = *gCurrentMap;
        tile = ((u8 *)p)[offset + 0x6C60];
        xc = ((u8 *)p)[offset + 0x6C61];
        yc = ((u8 *)p)[offset + 0x6C62];
        if (tile == 0xFF) {
            return;
        }
        if (gTerrainPropertyFlags[tile & 0x1F] != 0) {
            u16 *rowTable = (u16 *)((u8 *)p + 0x3758);
            u16 row = rowTable[yc];
            u8 posTile = ((u8 *)p + xc)[row + 0x1420];
            if ((posTile & 0xE0) != 0) {
                found = 0;
                for (i = 1; i < 5; i++) {
                    if (IsPlayerPresent(i) != 0) {
                        void *p2 = *gCurrentMap;
                        u16 *rt2 = (u16 *)((u8 *)p2 + 0x3758);
                        u16 row2 = rt2[yc];
                        u8 pos2 = ((u8 *)p2 + xc)[row2 + 0x1420];
                        u16 tabval = data_ov000_021aeee8[i];
                        if (tabval == (pos2 & 0xE0)) {
                            found = 1;
                            break;
                        }
                    }
                }
                if (found == 0) {
                    if (tile == 0x0F) {
                        void *p3 = *gCurrentMap;
                        u16 *rt3 = (u16 *)((u8 *)p3 + 0x3758);
                        u16 row3 = rt3[yc];
                        ((u8 *)p3 + xc)[row3 + 0x1420] = 0x10;
                        p3 = *gCurrentMap;
                        rt3 = (u16 *)((u8 *)p3 + 0x3758);
                        row3 = rt3[yc];
                        *((u16 *)((u8 *)p3 + (xc + row3) * 2 + 0xA10)) = 0x1C2;
                    } else {
                        void *p4 = *gCurrentMap;
                        u16 *rt4 = (u16 *)((u8 *)p4 + 0x3758);
                        u16 row4 = rt4[yc];
                        ((u8 *)p4 + xc)[row4 + 0x1420] = tile;
                        func_0207ab84(xc, yc, 0);
                    }
                }
            }
        }
        offset += 6;
        counter++;
    } while (counter < 99);
}

void func_020ceea8(void) {
    M2C_UNK func_020a15f8();
    M2C_UNK func_020a4d58();
    void func_020ced08(void);
    M2C_UNK func_020d1b80();
    M2C_UNK func_020d1f2c();
    M2C_UNK InitPlayerStates();
    InitPlayerStates();
    func_020d1f2c();
    func_020d1b80();
    func_020ced08();
    func_020a4d58();
    func_020a15f8();
}

/* Load the current map's terrain tileset: when its tileset kind differs from the one
 * loaded, decompress that kind's ds2map_<kind>.pnl palette onto the map's tile table
 * and switch the terrain tile lookup over to it. */
void LoadMapTileset(void) {
extern void **gCurrentMap;
s32 GetTerrainTileset(void);void SetFileDirectory(void*);void LoadDecompressedFileTo(void*,void*);void SetTerrainTileset(u8);
u8 *p=(u8*)*gCurrentMap+MAP_NAME;
s32 loadedTileset=GetTerrainTileset();
if(loadedTileset==p[MAP_TILESET-MAP_NAME])return;
p=(u8*)*gCurrentMap+0xa60;
SetFileDirectory(gTilesetDir);
switch(M2C_FIELD(*gCurrentMap,u8*,MAP_TILESET)){
case 4:LoadDecompressedFileTo(sTilesetDoomPnl,p+0x6000);break;
case 5:LoadDecompressedFileTo(sTilesetCliffPnl,p+0x6000);break;
case 6:LoadDecompressedFileTo(sTilesetRuinPnl,p+0x6000);break;
case 7:LoadDecompressedFileTo(sTilesetFlowerPnl,p+0x6000);break;
case 8:LoadDecompressedFileTo(sTilesetUraPnl,p+0x6000);break;
case 9:LoadDecompressedFileTo(sTilesetOwlPnl,p+0x6000);break;
default:LoadDecompressedFileTo(sTilesetNormalPnl,p+0x6000);break;
}
SetTerrainTileset(M2C_FIELD(*gCurrentMap,u8*,MAP_TILESET));
}

#pragma opt_strength_reduction off
void BuildMapRowOffsets(void) { extern void **gCurrentMap; s32 i; for(i=0;i<M2C_FIELD(*gCurrentMap,u16 *,0x5146);i++) M2C_FIELD((u8 *)*gCurrentMap+i*2,u16 *,0x3758)=i*M2C_FIELD(*gCurrentMap,u16 *,0x5144); }
#pragma opt_strength_reduction reset
void LoadPlayerArmies(M2C_UNK arg0) {
    M2C_UNK SetPlayerIdForSlot(s32, s32);
    s32 func_020a8a4c(M2C_UNK, s32);
    s32 var_r5;

    var_r5 = 0;
    do {
        if (var_r5 == 0) {
            SetPlayerIdForSlot(var_r5, 0);
        } else {
            SetPlayerIdForSlot(var_r5, func_020a8a4c(arg0, var_r5));
        }
        var_r5 += 1;
    } while (var_r5 < 5);
}

#pragma opt_strength_reduction off
/* Load a map by id into gCurrentMap: copy its name, size and player count,
 * translate the decoded tile ids into cell tiles and terrain kinds, and set
 * each player's army.  Campaign maps (0xE1..0x1A8) come from a full record. */
void LoadBattleMap(s32 id)
{
  void *GetMapRecordBuffer(void);
  s32 func_020846a4(void);
  s32 LoadMapRecord(s32, s32);
  void ApplyMapRecord(s32);
  void LoadMapTileData(u16);
  u32 GetMapPlayerCount(u16);
  void *GetMapName(u16);
  void *StringCopy(void *, const void *);
  void BuildMapRowOffsets(void);
  void LoadPlayerArmies(s32);
  void FreeMapTileData(void);
  extern void **gCurrentMap;
  extern u8 *gMapData;
  void *record;
  u8 *dest;
  u8 *new_var;
  s32 x;
  s32 y;
  u16 row;
  u16 tileId;
  u8 look;
  M2C_FIELD(*gCurrentMap, u16 *, MAP_ID) = (u16) id;
  if ((id >= MAP_ID_CAMPAIGN_FIRST) && (id < MAP_ID_CAMPAIGN_END))
  {
    record = GetMapRecordBuffer();
    if (func_020846a4() == 0)
    {
      LoadMapRecord(id, (s32) record);
    }
    ApplyMapRecord((s32) record);
    return;
  }
  LoadMapTileData(id);
  *((u16 *) (((u8 *) (*gCurrentMap)) + MAP_WIDTH)) = (u16) gMapData[MAPDATA_WIDTH];
  *((u16 *) (((u8 *) (*gCurrentMap)) + MAP_HEIGHT)) = (u16) gMapData[MAPDATA_HEIGHT];
  dest = ((u8 *) (*gCurrentMap)) + MAP_NAME;
  dest[MAP_PLAYER_COUNT - MAP_NAME] = (u8) GetMapPlayerCount(id);
  dest = ((u8 *) (*gCurrentMap)) + 0x120;
  new_var = dest + 0x5000;
  StringCopy(new_var, GetMapName(id));
  BuildMapRowOffsets();
  LoadPlayerArmies(id);
  for (y = 0; y < (*((u16 *) (((u8 *) (*gCurrentMap)) + MAP_HEIGHT))); y++)
  {
    for (x = 0; x < (*((u16 *) (((u8 *) (*gCurrentMap)) + MAP_WIDTH))); x++)
    {
      u8 *map = *gCurrentMap;
      row = *((u16 *) ((map + MAP_ROW_OFFSETS) + (y * 2)));
      tileId = ((u16 *) gMapData)[(x + row) + 1];
      look = map[MAP_TILE_TERRAIN + tileId];
      *((u16 *) ((map + MAP_CELL_TILE_ID) + ((x + row) * 2))) = tileId;
      map = *gCurrentMap;
      row = *((u16 *) ((map + MAP_ROW_OFFSETS) + (y * 2)));
      map[(MAP_CELL_TERRAIN + x) + row] = look;
    }

  }

  FreeMapTileData();
}
#pragma opt_strength_reduction reset
void func_020cf278(s32 arg0) {
s32 MapData_GetTileset(s32); void LoadMapTileset(void);
extern void **gCurrentMap;
u8 old=M2C_FIELD(*gCurrentMap,u8 *,0x5157);
M2C_FIELD(*gCurrentMap,u8 *,0x5157)=MapData_GetTileset(arg0);
LoadMapTileset();
M2C_FIELD(*gCurrentMap,u8 *,0x5157)=old;
}

void func_020cf2c8(void) {
    extern void **gCurrentMap;
    extern s8 gTerrainPropertyFlags[];
    void SelectMapLayer(void *);
    void FillMapLayer(s32);
    s32 count;
    s32 i;
    s32 x;
    s32 y;
    s32 k;
    s32 a;
    s32 tile; void *base; u32 row;

    count = 0;
    SelectMapLayer((u8 *)*gCurrentMap + 0x1928);
    FillMapLayer(-1);
    for (i = 0; i < 5; i++)
        M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67bc) = 0;
    for (y = 0; y < (s32)M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
        for (x = 0; x < (s32)M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
            base = *gCurrentMap;
            row = M2C_FIELD((u8 *)base + (y << 1), u16 *, 0x3758);
            tile = M2C_FIELD(row + ((u8 *)base + x), u8 *, 0x1420);
            k = tile & 0x1f;
            a = gTerrainPropertyFlags[k];
            if (a != 0 && k != 0x14 && k != 0x15)
                M2C_FIELD((u8 *)*gCurrentMap + ((tile & 0xe0) >> 5) * 0x8c, u8 *, 0x67bc) += 1;
            if (a != 0 || k == 0x18) {
                M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD((u8 *)*gCurrentMap + (y << 1), u16 *, 0x3758) + x, u8 *, 0x1928) = (u8)count;
                M2C_FIELD((u8 *)*gCurrentMap + count * 6, u8 *, 0x6c60) = (u8)k;
                M2C_FIELD((u8 *)*gCurrentMap + count * 6, u8 *, 0x6c61) = (u8)x;
                M2C_FIELD((u8 *)*gCurrentMap + count * 6, u8 *, 0x6c62) = (u8)y;
                M2C_FIELD((u8 *)*gCurrentMap + count * 6, u8 *, 0x6c63) = 0;
                count++;
            }
        }
    }
    M2C_FIELD((u8 *)*gCurrentMap + count * 6, u8 *, 0x6c60) = 0xff;
}

void func_020cf498(s16 arg0, s16 arg1) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = arg0;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = arg1;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C6) = (s16) (arg0 * 0x10);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C8) = (s16) (arg1 * 0x10);
}

/* Advance the smoothed cursor position stored in the game state toward (targetX, targetY):
   snap to the target if farther than 16 pixels, otherwise step 4 pixels closer. */
void func_020cf4f0(s16 targetX, s16 targetY, s32 unusedArg2, s16 *outX, s16 *outY) {
    extern void **gCurrentMap;
    void *state = *gCurrentMap;
    u16 *cursor = (u16 *)((u8 *)state + 0x52C6);
    u16 curX = cursor[0];
    s32 dx = targetX - curX;
    u16 curY = cursor[1];
    s32 dy;
    s16 newX;
    s16 newY;

    if ((dx < 0 ? -dx : dx) > 0x10 || (dy = targetY - curY, (dy < 0 ? -dy : dy)) > 0x10) {
        curX = targetX;
        curY = targetY;
    } else {
        if ((dx < 0 ? -dx : dx) > 0) curX += (dx > 0 ? 1 : (dx < 0 ? -1 : 0)) * 4;
        if ((dy < 0 ? -dy : dy) > 0) curY += (dy > 0 ? 1 : (dy < 0 ? -1 : 0)) * 4;
    }
    newX = curX;
    newY = curY;
    cursor[0] = newX;
    cursor[1] = newY;
    *outX = newX;
    *outY = newY;
}

void MoveMapCursorToTarget(s32 arg0) {
    void func_020cf4f0(s16, s16, s32, s16 *, s16 *);
    extern void **gCurrentMap;
    s16 sp6;
    s16 sp4;
    void (*cb)(s16, s16, s32);
    void *p = (void *)*gCurrentMap;
    s16 *pp = (s16 *)((u8 *)p + 0x52C2);
    func_020cf4f0((s16)(pp[0] * 16), (s16)(pp[1] * 16), arg0, &sp6, &sp4);
    cb = M2C_FIELD((void *)gCurrentMap[1], void (**)(s16, s16, s32), 8);
    if (cb != NULL) {
        cb(sp6, sp4, arg0);
    }
}

void func_020cf674(s32 arg0,s32 arg1,s32 arg2) {
extern void **gCurrentMap;
void (*callback)(s32,s32,s32);
callback=M2C_FIELD(gCurrentMap[1],void (**)(s32,s32,s32),8);
if(!callback)return;
callback(arg0,arg1,arg2);
}

