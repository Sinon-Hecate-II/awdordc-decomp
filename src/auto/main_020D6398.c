/* 7 functions from 0x020D6398 to 0x020D6E0C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { s32 v[4]; } MenuBounds;
extern const MenuBounds data_020f4e88;
extern u8 gMapConfig[16];

/* Whether the cursor may be moved to tile (x,y): the cursor-owner guard, the
 * reachability grid and the unit standing on the tile are checked, then the
 * attack and join rules against the unit under the cursor. */
s32 CanMoveCursorTo(s32 x,s32 y){
extern void **gCurrentMap;
s32 func_020a85b8(s32); u8 CanLoadUnitAt(s32,s32); s32 CanUnitsJoin(void*,void*); u8 IsSameTeam(s32,s32);
u8 *map=*gCurrentMap;
s32 id=map[x+*(u16*)(map+y*2+MAP_ROW_OFFSETS)];
s32 grid,off,cursorTeam,tileTeam,n;
u8 *units,*unit,*selected;
if(*(u16*)(map+MAP_CURSOR_OWNER)!=(map[MAP_CURSOR_UNIT_ID]&0xc0))return 0;
grid=(*(s8**)(map+y*4+MAP_GRID))[x];
if(grid<0 || grid>110)return 0;
if(id==0)return 1;
if(id==map[MAP_CURSOR_CARRIER])return 0;
if(CanLoadUnitAt(x,y)==1)return 1;
map=*gCurrentMap; off=id*MAP_UNIT_STRIDE;
if(CanUnitsJoin(*(u8**)(map+MAP_CURSOR_UNIT),map+MAP_UNIT_RECORDS+off)==1)return 1;
map=*gCurrentMap;
if(func_020a85b8((u32)((*(u8**)(map+MAP_CURSOR_UNIT))[0]<<26)>>26)){
map=*gCurrentMap;units=map+MAP_UNIT_RECORDS;unit=units+off;
if(unit){if(unit)n=(unit-units)/MAP_UNIT_STRIDE;else n=0;tileTeam=(n>>6)+1;}else tileTeam=0;
selected=*(u8**)(map+MAP_CURSOR_UNIT);
if(selected){if(selected)n=(selected-units)/MAP_UNIT_STRIDE;else n=0;cursorTeam=(n>>6)+1;}else cursorTeam=0;
if(IsSameTeam(cursorTeam,tileTeam)==0)return 1;
}
return 0;
}

/* Walks the movement path `path` from (startX,startY): each byte is a MOVE_DIR_*
 * step and the list ends at MOVE_DIR_STOP or MOVE_DIR_NONE.  When a step would
 * enter a unit of another army, the path is clipped at the previous tile and
 * rewritten as an attack (MOVE_DIR_ATTACK then stopCode): the cursor is moved to
 * that last free tile and the movement cost spent so far is stored.  Returns 1 when
 * an enemy blocks the path, 0 otherwise. */
s32 ResolvePathAttack(s32 startX,s32 startY,s32 unitKind,s8 *path,s32 stopCode){
extern void **gCurrentMap;extern u8 gMovementCostTable[],gUnitKindStats[];
s32 func_020a85b8(s32);
s16 prevX=startX,prevY=startY,x=prevX,y=prevY;
s32 moveCost=0,dir,unitId,terrain;
void **map;
s8 *moveCosts;u8 *cell,*base;
if(func_020a85b8(unitKind))return 0;
map=gCurrentMap;moveCosts=M2C_FIELD(gMovementCostTable,s8 **,0x64);
while((dir=*path)!=MOVE_DIR_STOP && dir!=MOVE_DIR_NONE){
switch(dir){case MOVE_DIR_LEFT:x--;break;case MOVE_DIR_RIGHT:x++;break;case MOVE_DIR_DOWN:y++;break;case MOVE_DIR_UP:y--;break;}
base=*map;cell=base+x+M2C_FIELD(base+y*2,u16 *,MAP_ROW_OFFSETS);
unitId=cell[MAP_CELL_UNIT_ID];
if(unitId && M2C_FIELD(base+(unitId>>6)*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_OFF+MAP_PLAYER_STRIDE)!=M2C_FIELD(base+M2C_FIELD(base,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_OFF)){
path[0]=MOVE_DIR_ATTACK;path[1]=stopCode;
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_X)=prevX;
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_Y)=prevY;
((u8*)*gCurrentMap)[MAP_CURSOR_DIR]=moveCost;
return 1;
}
terrain=cell[MAP_CELL_TERRAIN];
moveCost+=(moveCosts+gUnitKindStats[((u32)(M2C_FIELD(base,u8 **,MAP_CURSOR_UNIT)[0]<<26)>>26)*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_MOVETYPE]*32)[terrain&MAP_TERRAIN_KIND_MASK];
prevX=x;prevY=y;path++;
}
return 0;
}

/* Whether a movement path turns into an attack: 1 when a MOVE_DIR_ATTACK step
 * appears before the path's end (MOVE_DIR_STOP or MOVE_DIR_NONE). */
s32 MovePathIsAttack(s8 *path) {
    s32 dir;
    while ((dir = *path) != MOVE_DIR_STOP && dir != MOVE_DIR_NONE) {
        if (dir == MOVE_DIR_ATTACK) return 1;
        path++;
    }
    return 0;
}

/* Load the under_info assets of the map view's info panel: the localized character
 * graphics (under_info.cg) into the 3D sprite engine's texture at +0x2A00 and the
 * palette (under_info.cl) into the sprite palette at 0x320. */
void LoadUnderInfoGraphics(void) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadDecompressedFileTo(s32, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern u8 sUnderInfoDir[], sUnderInfoCgName[], sUnderInfoClName[];
    extern u16 **gCur3DSpriteEngine;

    SetFileDirectory(sUnderInfoDir);
    LoadDecompressedFileTo(GetLocalizedFileName(sUnderInfoCgName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2A00);
    LoadFileToSpriteBuffer(sUnderInfoClName, 0x320, 0x20);
}

/* Draws the information window for the map tile under the cursor: resolves the
 * unit (or, when the tile is empty, the cursor's selected unit), picks the panel
 * side from the sliding panel position and dispatches to the unit, carried-unit
 * or terrain panel and its frame. */
void DrawUnitInfoPanel(s32 mode) {
 extern void **gCurrentMap;
 void StepCursorCellDisplayMode(void); s32 GetUnitPanelKind(void *);
 void DrawTurnCounter(s32,s32,u32,u32); void func_020d759c(s32,s32,s32);
 void DrawCarriedUnits(s32,s32,s32,void *);void DrawUnitStatus(s32,s32,s32,void *);
 void DrawTerrainStatus(s32,s32,u32,u32,s32, void *);void DrawUnitInfoFrame(s32,s32,s32,s32);
 u32 panelVisible=(u32)(*(u16 *)gMapConfig<<21)>>31;
 MenuBounds bounds=data_020f4e88;
 u8 *unit=0; u8 *map; s16 panelY; s32 side; u32 cursorRow; s16 panelX,panelKind; u32 cursorCol,unitId;
 if(!panelVisible)return;
 StepCursorCellDisplayMode();map=*gCurrentMap;
 cursorRow=(u32)(*(u16 *)(map+0x52e6)<<16)>>25;
 cursorCol=(u32)(*(u16 *)(map+0x52e6)<<23)>>25;
 unitId=map[*(u16 *)(map+MAP_ROW_OFFSETS+cursorRow*2)+cursorCol];
 if(unitId)unit=map+MAP_UNIT_RECORDS+unitId*MAP_UNIT_STRIDE;
 else {u8 *p=*(u8 **)(map+MAP_CURSOR_UNIT);if(p && ((u32)(p[0]<<26)>>26) && p[1]==cursorCol && p[2]==cursorRow)unit=p;}
 panelKind=GetUnitPanelKind(unit);
 map=*gCurrentMap;panelX=*(s16 *)(map+0x52e4);
 if(panelX<=bounds.v[0]) {panelY=bounds.v[1];side=0;}else {panelY=bounds.v[3];side=1;}
 switch(mode) {case 0:DrawTurnCounter(2,2,*(u16 *)(map+0x52a2),gMapConfig[3]);break;case 1:func_020d759c(panelX,panelY,side);break;case 2:break;}
 switch(panelKind) {case 2:DrawCarriedUnits(panelX,panelY,side,unit);case 1:DrawUnitStatus(panelX,panelY,side,unit);case 0:DrawTerrainStatus(panelX,panelY,cursorCol,cursorRow,side,unit);break;}
 DrawUnitInfoFrame(panelX,panelY,side,panelKind);
}

/* Draw a number in decimal with the 8x8 digit sprites: one sprite per digit
 * at (x,y), moving eight pixels left for each digit, with a tile layout that
 * depends on the screen's zoom. */
void DrawDecimalNumber(s32 x, s32 y, s32 number) {
M2C_UNK AddSprite(u16,u16,u16,M2C_UNK *,s32);
extern M2C_UNK gSpriteDesc8x8;extern u16 **gCur3DSpriteEngine;
do {
AddSprite((u16)(x&511),(u16)(y&255),(u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine<<17)>>30))&1023)|0x9000)+((((number%10)*2) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine<<17)>>30))&1023)),&gSpriteDesc8x8,8);
x-=8;number/=10;
}while(number);
}

s32 GetDigitCount(s32);
s32 Divide(s32, s32);
M2C_UNK AddSprite(u16, u16, u16, M2C_UNK *, s32);
s32 GetLanguage(void);
#pragma push
#pragma opt_strength_reduction off
/* Draw the turn counter at (x,y): the "turn" label sprite, the current turn's
 * digits and, when the map has a turn limit, a slash and the limit's digits.
 * Digits are drawn right to left, with the label row moved down one line for
 * languages that need it. */
void DrawTurnCounter(s32 x, s32 y, u32 primary, u32 secondary) {
    extern u16 **gCur3DSpriteEngine;
    extern M2C_UNK gSpriteDesc32x8, gSpriteDesc8x16;
    s32 labelY;
    s32 digitY;
    s32 limit = secondary;
    s32 turn = primary;

    switch (GetLanguage()) {
    case 0:
        labelY = y + 12;
        break;
    default:
        labelY = y;
        y += 7;
        break;
    }
    AddSprite((u16)((x) & 511), (u16)(labelY & 255), (u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x9000) + (((0x36) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023)), &gSpriteDesc32x8, 8);
    if (limit != 0) {
        s32 turnDigits = GetDigitCount(turn);
        x += (turnDigits + GetDigitCount(limit)) * 8;
        digitY = y & 255;
        AddSprite((u16)((x + 8) & 511), (u16)(digitY), (u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x9000) + (((0x34) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023)), &gSpriteDesc8x16, 10);
        do {
            AddSprite((u16)((x) & 511), (u16)(digitY), (u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x9000) + (((0x20 + (limit % 10) * 2) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023)), &gSpriteDesc8x16, 10);
            x -= 8;
            limit = Divide(limit, 10);
        } while (limit != 0);
        AddSprite((u16)((x) & 511), (u16)(digitY), (u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x9000) + (((0x3e) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023)), &gSpriteDesc8x16, 10);
        x -= 8;
    } else {
        x += (GetDigitCount(turn) - 1) * 8;
        digitY = y & 255;
        AddSprite((u16)((x + 8) & 511), (u16)(digitY), (u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x9000) + (((0x34) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023)), &gSpriteDesc8x16, 10);
    }
    do {
        AddSprite((u16)((x) & 511), (u16)(digitY), (u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x9000) + (((0x20 + (turn % 10) * 2) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine << 17) >> 30)) & 1023)), &gSpriteDesc8x16, 10);
        x -= 8;
        turn = Divide(turn, 10);
    } while (turn != 0);
}
#pragma pop
