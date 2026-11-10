/* 7 functions from 0x020D6398 to 0x020D6E0C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { s32 v[4]; } MenuBounds;
extern const MenuBounds data_020f4e88;
extern u8 gMapConfig[16];

s32 func_020d6398(s32 x,s32 y){
extern void **gCurrentMap;
s32 func_020a85b8(s32); u8 func_020ba790(s32,s32); s32 CanUnitsJoin(void*,void*); u8 IsSameTeam(s32,s32);
u8 *base=*gCurrentMap;
s32 id=base[x+*(u16*)(base+y*2+0x3758)];
s32 cell,off,a,b,n;
u8 *table,*unit,*selected;
if(*(u16*)(base+0x52a8)!=(base[0x52d4]&0xc0))return 0;
cell=(*(s8**)(base+y*4+0x52e8))[x];
if(cell<0 || cell>110)return 0;
if(id==0)return 1;
if(id==base[0x52d6])return 0;
if(func_020ba790(x,y)==1)return 1;
base=*gCurrentMap; off=id*14;
if(CanUnitsJoin(*(u8**)(base+0x52d0),base+0x59a4+off)==1)return 1;
base=*gCurrentMap;
if(func_020a85b8((u32)((*(u8**)(base+0x52d0))[0]<<26)>>26)){
base=*gCurrentMap;table=base+0x59a4;unit=table+off;
if(unit){if(unit)n=(unit-table)/14;else n=0;b=(n>>6)+1;}else b=0;
selected=*(u8**)(base+0x52d0);
if(selected){if(selected)n=(selected-table)/14;else n=0;a=(n>>6)+1;}else a=0;
if(IsSameTeam(a,b)==0)return 1;
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

s32 func_020d66fc(s8 *arg0) {
    s32 value;
    while ((value = *arg0) != 4 && value != -1) {
        if (value == 10) return 1;
        arg0++;
    }
    return 0;
}

void func_020d672c(void) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadDecompressedFileTo(s32, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern M2C_UNK data_0212beec;
    extern M2C_UNK data_0212bef8;
    extern M2C_UNK data_0212bf08;
    extern u16 **gCur3DSpriteEngine;
    SetFileDirectory(&data_0212beec);
    LoadDecompressedFileTo(GetLocalizedFileName(&data_0212bef8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2A00);
    LoadFileToSpriteBuffer(&data_0212bf08, 0x320, 0x20);
}

/* Draws the information window for the map tile under the cursor: resolves the
 * unit (or, when the tile is empty, the cursor's selected unit), picks the panel
 * side from the sliding panel position and dispatches to the unit, carried-unit
 * or terrain panel and its frame. */
void DrawUnitInfoPanel(s32 mode) {
 extern void **gCurrentMap;
 void func_020d87d8(void); s32 GetUnitPanelKind(void *);
 void func_020d6a20(s32,s32,u32,u32); void func_020d759c(s32,s32,s32);
 void DrawCarriedUnits(s32,s32,s32,void *);void DrawUnitStatus(s32,s32,s32,void *);
 void func_020d8084(s32,s32,u32,u32,s32, void *);void DrawUnitInfoFrame(s32,s32,s32,s32);
 u32 panelVisible=(u32)(*(u16 *)gMapConfig<<21)>>31;
 MenuBounds bounds=data_020f4e88;
 u8 *unit=0; u8 *map; s16 panelY; s32 side; u32 cursorRow; s16 panelX,panelKind; u32 cursorCol,unitId;
 if(!panelVisible)return;
 func_020d87d8();map=*gCurrentMap;
 cursorRow=(u32)(*(u16 *)(map+0x52e6)<<16)>>25;
 cursorCol=(u32)(*(u16 *)(map+0x52e6)<<23)>>25;
 unitId=map[*(u16 *)(map+MAP_ROW_OFFSETS+cursorRow*2)+cursorCol];
 if(unitId)unit=map+MAP_UNIT_RECORDS+unitId*MAP_UNIT_STRIDE;
 else {u8 *p=*(u8 **)(map+MAP_CURSOR_UNIT);if(p && ((u32)(p[0]<<26)>>26) && p[1]==cursorCol && p[2]==cursorRow)unit=p;}
 panelKind=GetUnitPanelKind(unit);
 map=*gCurrentMap;panelX=*(s16 *)(map+0x52e4);
 if(panelX<=bounds.v[0]) {panelY=bounds.v[1];side=0;}else {panelY=bounds.v[3];side=1;}
 switch(mode) {case 0:func_020d6a20(2,2,*(u16 *)(map+0x52a2),gMapConfig[3]);break;case 1:func_020d759c(panelX,panelY,side);break;case 2:break;}
 switch(panelKind) {case 2:DrawCarriedUnits(panelX,panelY,side,unit);case 1:DrawUnitStatus(panelX,panelY,side,unit);case 0:func_020d8084(panelX,panelY,cursorCol,cursorRow,side,unit);break;}
 DrawUnitInfoFrame(panelX,panelY,side,panelKind);
}

void DrawDecimalNumber(s32 arg0, s32 arg1, s32 arg2) {
M2C_UNK AddSprite(u16,u16,u16,M2C_UNK *,s32);
extern M2C_UNK gSpriteDesc8x8;extern u16 **gCur3DSpriteEngine;
do {
AddSprite((u16)(arg0&511),(u16)(arg1&255),(u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine<<17)>>30))&1023)|0x9000)+((((arg2%10)*2) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine<<17)>>30))&1023)),&gSpriteDesc8x8,8);
arg0-=8;arg2/=10;
}while(arg2);
}

void func_020d6a20(s32 a, s32 b, u32 c, u32 d) {
    s32 GetLanguage(void);
    (void)a; (void)b; (void)c; (void)d;
    if (GetLanguage() != 0) {
        return;
    }
    return;
}

