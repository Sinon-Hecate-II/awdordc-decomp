/* 24 functions from 0x021743F0 to 0x02175310 (ov000), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

typedef Ov000InfoMenu Ov000MenuState;
typedef struct { u16 pad[3]; u16 low:15, flag:1; } Ov000Flags;

/* Per-frame update of the map info window: follows the map cursor, blinks it,
 * opens the terrain or unit-statistics panel for the cell under the cursor and
 * runs the panel's state machine. */
void Ov000_InfoWindow_Update(Ov000MenuState *menu) {
extern void **gCurrentMap; extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineSub; extern Ov000MenuState *gOv000InfoWindow; extern u8 gProductionMenuScreenClass[];
int GetMapInputState(void); int FindObjectByClass(void *); s32 GetCellTerrainId(s32,s32);
void Ov000_InfoWindow_SetUnitFlags(void *); void Ov000_InfoWindow_ClearUnitFlags(void *); void Ov000_InfoWindow_ShowTerrain(void *,s32); void Ov000_InfoWindow_OpenCell(void *,s32,s32);
void Ov000_InfoPanel_Refresh(void *); void func_ov000_02172654(void *); void func_ov000_02172648(void *); void Ov000_StatsWindow_Reset(void *); void func_ov000_02175234(void *); void func_ov000_02175230();
s32 x=M2C_FIELD(*gCurrentMap,s16 *,0x52c2), y=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
void *saved=gCur3DSpriteEngine; s32 mode;
gCur3DSpriteEngine=g3DSpriteEngineSub;
Ov000_InfoWindow_SetUnitFlags(menu);
mode=GetMapInputState();
switch(mode) {
case 2:
if(menu->prevMode!=GetMapInputState())menu->trigger=1;
if(menu->trigger){
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|16;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|32;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|64;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|128;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|256;}
if(menu->pendingState!=OV000_INFO_NO_TERRAIN)menu->pendingState=OV000_INFO_NO_TERRAIN;
Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow,-1); menu->hasUnit=0;
}
menu->cursorX=x; menu->cursorY=y;
menu->pressed=0; menu->trigger=0; break;
case 0: case 1:
if(menu->prevMode!=GetMapInputState())menu->trigger=1;
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|16;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|32;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|64;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|128;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|256;}
if(x!=menu->cursorX||y!=menu->cursorY){
menu->animFrame=0; menu->cursorX=x; menu->cursorY=y;
}
if(menu->animFrame>=0){
if(menu->animFrame<4)menu->animFrame++;
else {M2C_FIELD(menu,u8 *,0x1a)=255; menu->trigger=1;}
}
{u8 confirm=FindObjectByClass(gProductionMenuScreenClass)!=0;
if(menu->pressed&&!confirm)menu->trigger=1;
menu->pressed=confirm;
}
if(menu->trigger){
void *unit=0; s32 terrain;
menu->trigger=0;
if(menu->pressed)menu->pendingState=OV000_INFO_UNIT_STATS;
else {
void *map=*gCurrentMap; u32 cell=x+((u16 *)((u8 *)map+0x3758))[y];
void *occupant=(u8 *)map+0x59a4+((u8 *)map)[cell]*14;
if((u8)(M2C_FIELD((u8 *)map+(cell>>3),u8 *,0x5201)&(1<<(cell&7)))){
if(occupant==0 || ((u32)(M2C_FIELD(occupant,u8 *,0)<<26)>>26)==0){
void *selected=M2C_FIELD(map,void **,0x52d0);
if(selected && M2C_FIELD(selected,u8 *,1)==x && M2C_FIELD(selected,u8 *,2)==y)occupant=selected;
}
if(occupant && ((u32)(M2C_FIELD(occupant,u8 *,0)<<26)>>26)==0)unit=0; else unit=occupant;
}
terrain=GetCellTerrainId(x,y);
if(unit){menu->hasUnit=1;Ov000_InfoWindow_OpenCell(gOv000InfoWindow,(s32)unit,terrain);}
else {menu->hasUnit=0;Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow,terrain);}
}
}break;
}
Ov000_InfoWindow_ClearUnitFlags(menu); menu->prevMode=GetMapInputState();
switch(menu->state){
case 1:
if(menu->pendingState!=0&&menu->pendingState!=1){menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;}break;
case 2:
M2C_FIELD(menu->panel,u8 *,0x15)=0;
if(menu->refresh){menu->refresh=0;Ov000_InfoPanel_Refresh(menu->panel);}
func_ov000_02172654(menu->panel);
if(menu->pendingState){
if(menu->pendingState==OV000_INFO_NO_TERRAIN){menu->state=menu->pendingState;menu->pendingState=0;M2C_FIELD(menu->panel,s32 *,4)=1;}
else if(menu->pendingState==OV000_INFO_UNIT_STATS){menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;func_ov000_02172648(menu->panel);M2C_FIELD(menu->statsWindow,s32 *,0)=M2C_FIELD(menu->panel,s32 *,0)&255;}
}break;
case 3:
M2C_FIELD(menu->panel,u8 *,0x15)=1;
if(menu->refresh){menu->refresh=0;Ov000_InfoPanel_Refresh(menu->panel);}
func_ov000_02172654(menu->panel);
if(menu->pendingState){
if(menu->pendingState==OV000_INFO_TERRAIN){menu->state=menu->pendingState;menu->pendingState=0;M2C_FIELD(menu->panel,s32 *,4)=1;}
else if(menu->pendingState==OV000_INFO_UNIT_STATS){menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;func_ov000_02172648(menu->panel);M2C_FIELD(menu->statsWindow,s32 *,0)=M2C_FIELD(menu->panel,s32 *,0)&255;}
}break;
case 4:
if(menu->refresh){menu->refresh=0;Ov000_StatsWindow_Reset(menu->statsWindow);}
func_ov000_02175234(menu->statsWindow);
if(menu->pendingState!=0&&menu->pendingState!=OV000_INFO_UNIT_STATS){
menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;
func_ov000_02175230(menu->statsWindow);M2C_FIELD(menu->panel,s32 *,0)=M2C_FIELD(menu->statsWindow,s32 *,0)&255;
}break;
}
gCur3DSpriteEngine=saved;
}

/* Flag both info panels as showing a unit when the cell under the map cursor
 * holds one. */
void Ov000_InfoWindow_SetUnitFlags(void *arg0) {
    Ov000InfoMenu *menu = (Ov000InfoMenu *)arg0;

    if (menu->hasUnit == 0) {
        return;
    }
    M2C_FIELD(menu->panel, s8 *, OV000_INFO_PANEL_HAS_UNIT) = 1;
    ((Ov000StatsWindow *)menu->statsWindow)->hasUnit = 1;
}

/* Clear both info panels' "showing a unit" flags when the cursor cell no longer
 * holds a unit (the inverse of Ov000_InfoWindow_SetUnitFlags). */
void Ov000_InfoWindow_ClearUnitFlags(void *arg0) {
    Ov000InfoMenu *menu = (Ov000InfoMenu *)arg0;

    if (menu->hasUnit != 0) {
        return;
    }
    M2C_FIELD(menu->panel, s8 *, OV000_INFO_PANEL_HAS_UNIT) = 0;
    ((Ov000StatsWindow *)menu->statsWindow)->hasUnit = 0;
}

/* Open the info window's panel for the cell under the map cursor: with no unit
 * there (or bit 0x8000 of the game settings forcing the terrain panel) show the
 * terrain description, otherwise fill the unit panel and switch to the stats
 * state. */
void Ov000_InfoWindow_OpenCell(void *menuPtr, s32 unit, s32 terrainId) {
    void Ov000_InfoWindow_ShowTerrain(void *, s32);
    void FillUnitInfo(void *, void *);
    extern Ov000Flags gOptionBits;
    extern Ov000InfoMenu *gOv000InfoWindow;
    Ov000InfoMenu *menu = (Ov000InfoMenu *)menuPtr;
    if (unit == 0) {
        Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow, terrainId);
        return;
    }
    if (((u32)(M2C_FIELD(&gOptionBits, u16 *, 6) << 16) >> 31) == 1) {
        Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow, terrainId);
        return;
    }
    FillUnitInfo(menu->statsWindow, (void *)unit);
    menu->pendingState = OV000_INFO_UNIT_STATS;
}

/* Fill the info window's unit-statistics panel with the stats of a player's
 * unit kind (the production preview) and request the statistics panel. */
void Ov000_InfoWindow_ShowUnitStats(Ov000InfoMenu *menu, s32 player, s32 unitKind) {
    void FillUnitKindInfo(void *, s32, s32);
    FillUnitKindInfo(menu->statsWindow, player, unitKind);
    menu->pendingState = OV000_INFO_UNIT_STATS;
}

/* Show the terrain panel for `terrainId`, or ask for the panel with nothing
 * selected when `terrainId` is -1: store the terrain in the panel's record block
 * and have the update loop switch to the terrain panel, or back to the empty one. */
void Ov000_InfoWindow_ShowTerrain(void *menuPtr, s32 terrainId) {
    void Ov000_InfoPanel_SetTerrain(void *, s32);
    Ov000InfoMenu *menu = (Ov000InfoMenu *)menuPtr;

    if (terrainId == -1) {
        menu->pendingState = OV000_INFO_NO_TERRAIN;
        return;
    }
    Ov000_InfoPanel_SetTerrain(menu->panel, terrainId);
    menu->pendingState = OV000_INFO_TERRAIN;
}

/* Confirm action of the map info window: toggles the panel under the cursor
 * between the terrain description and the statistics of the unit standing on
 * the cell (bit 0x8000 of the global flags forces the terrain panel). */
void Ov000_InfoWindow_TogglePanel(void *menu) {
extern void **gCurrentMap;
extern Ov000Flags gOptionBits;
extern Ov000MenuState *gOv000InfoWindow;
s32 GetCellTerrainId(s32,s32);
void *unit;
void *map=*gCurrentMap;
s32 cellX=M2C_FIELD(map,s16 *,0x52c2);
s32 cellY=M2C_FIELD(map,s16 *,0x52c4);
u32 cell=cellX+((u16 *)((u8 *)map+0x3758))[cellY];
unit=(u8 *)map+0x59a4+((u8 *)map)[cell]*14;
if(!(u8)(M2C_FIELD((u8 *)map+(cell>>3),u8 *,0x5201)&(1<<(cell&7)))) unit=0;
else {
if(unit==0 || ((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0){
void *selectedUnit=M2C_FIELD(map,void **,0x52d0);
if(selectedUnit!=0 && M2C_FIELD(selectedUnit,u8 *,1)==cellX && M2C_FIELD(selectedUnit,u8 *,2)==cellY)unit=selectedUnit;
}
if(unit && ((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0)unit=0;
}
cell=GetCellTerrainId(cellX,cellY);
switch(M2C_FIELD(menu,s32 *,8)){
case 2: case 3: {
u16 flags=M2C_FIELD(&gOptionBits,u16 *,6);
void *window=gOv000InfoWindow;
M2C_FIELD(&gOptionBits,u16 *,6)=flags & ~0x8000;
Ov000_InfoWindow_OpenCell(window,(s32)unit,cell);
break; }
case 4: {
u16 flags=M2C_FIELD(&gOptionBits,u16 *,6);
void *window=gOv000InfoWindow;
M2C_FIELD(&gOptionBits,u16 *,6)=flags | 0x8000;
Ov000_InfoWindow_ShowTerrain(window,cell);
break; }
}
}

/* Load the graphics of the currently open ov000 map info window. */
void Ov000_InfoWindow_LoadGlobalAssets(void) {
    M2C_UNK Ov000_InfoWindow_LoadAssets(void *);
    extern Ov000MenuState *gOv000InfoWindow;
    Ov000_InfoWindow_LoadAssets(gOv000InfoWindow);
}

void func_ov000_02174c00(void) {
    M2C_UNK DeleteWallpaperSpritesOnAllEngines();
    DeleteWallpaperSpritesOnAllEngines();
}

/* Whether the ov000 map info window currently exists: it is created when the
 * map screen sets up and freed when the screen closes. */
u8 Ov000_InfoWindow_Exists(void) {
    extern Ov000InfoMenu *gOv000InfoWindow;

    if (gOv000InfoWindow != 0) {
        return 1;
    }
    return 0;
}

/* Create the ov000 map info window: allocate its Ov000InfoMenu, initialize its
 * panels and language, store it in gOv000InfoWindow and create its sprite. */
void Ov000_InfoWindow_Create(void) {
    s32 *MemAlloc(M2C_UNK);
    void *Ov000_InfoWindow_Init(void *);
    M2C_UNK CreateSpriteFromClass(void *, s32);
    extern M2C_UNK gOv000InfoWindowSpriteClass;
    extern Ov000InfoMenu *gOv000InfoWindow;
    void *menu;
    menu = MemAlloc(0x20);
    if (menu != 0) {
        menu = Ov000_InfoWindow_Init(menu);
    }
    gOv000InfoWindow = menu;
    CreateSpriteFromClass(&gOv000InfoWindowSpriteClass, OV000_INFO_SPRITE_LAYER);
}

/* Per-frame tick of the ov000 map info window: update it while one is open. */
void Ov000_InfoWindow_Tick(void) {
    void Ov000_InfoWindow_Update(Ov000MenuState *);
    extern Ov000MenuState *gOv000InfoWindow;
    if (Ov000_InfoWindow_Exists() == 0) return;
    Ov000_InfoWindow_Update(gOv000InfoWindow);
}

/* Tear down the ov000 map info window: free its two panels and the window
 * itself, forget it, and delete the info window's and the map view's sprites.
 * Does nothing when no window is open. */
void Ov000_InfoWindow_Destroy(void) {
    void func_ov000_021743ec(void *);
    void Ov000_InfoWindow_FreePanels(void *);
    M2C_UNK MemFree(s32);
    void DeleteSpriteObjectsOfClass(void *);
    void RemoveMapViewSprites(void);
    extern Ov000InfoMenu *gOv000InfoWindow;
    extern M2C_UNK gOv000InfoWindowSpriteClass;
    void *window;
    if (Ov000_InfoWindow_Exists() == 0) return;
    func_ov000_021743ec(gOv000InfoWindow);
    window = gOv000InfoWindow;
    if (window != 0) {
        Ov000_InfoWindow_FreePanels(window);
        MemFree((s32)window);
    }
    gOv000InfoWindow = 0;
    DeleteSpriteObjectsOfClass(&gOv000InfoWindowSpriteClass);
    RemoveMapViewSprites();
}

/* Ask the open map info window to re-read the cell under the cursor on its next
 * update; does nothing when no window is open. */
void Ov000_InfoWindow_RequestCellRefresh(void) {
    extern Ov000InfoMenu *gOv000InfoWindow;
    if (Ov000_InfoWindow_Exists() == 0) return;
    gOv000InfoWindow->trigger = 1;
}

/* Show a production preview in the map info window: ask the window to re-read
 * the cell under the cursor and fill its stats panel with the given player's
 * unit kind. */
void Ov000_InfoWindow_ShowProductionUnit(s32 player, s32 unitKind) {
    extern Ov000MenuState *gOv000InfoWindow;
    if (Ov000_InfoWindow_Exists() == 0) return;
    gOv000InfoWindow->trigger = 1;
    Ov000_InfoWindow_ShowUnitStats(gOv000InfoWindow, player, unitKind);
}

/* Whether the X (cancel) key can act on the info window: only when the window
 * is open and its panel is showing a unit. */
s32 Ov000_InfoWindow_CanCancel(void) {
    extern Ov000MenuState *gOv000InfoWindow;
    s32 result;

    if (Ov000_InfoWindow_Exists() != 0) {
        result = gOv000InfoWindow->hasUnit;
    } else {
        result = 0;
    }
    return result;
}

/* X-key handler of the map info window: with the window open, toggle its panel
 * between the terrain description and the unit statistics and report the key as
 * handled; with no window open, do nothing and report 0. */
s32 Ov000_InfoWindow_Cancel(void) {
    void Ov000_InfoWindow_TogglePanel(void *);
    extern Ov000MenuState *gOv000InfoWindow;

    if (Ov000_InfoWindow_Exists() == 0) return 0;
    Ov000_InfoWindow_TogglePanel(gOv000InfoWindow);
    return 1;
}

void func_ov000_02174da4(s32 x, s32 y) {
    extern u16 gTurnTimeConfig[];
    extern void **gCurrentMap;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern u32 gTimerColonTiles[];
    extern u32 gTimerDigitTiles[];
    s32 HardDiv(s32, s32);
    void AddSprite(u16, u16, u16, void *, s32);

    s32 total, minutes, centis, palette, separator;
    void *map;
    void *savedSpriteEngine;

    total = gTurnTimeConfig[2];
    if (total == 0) return;

    map = *gCurrentMap;
    {
        void *player = (u8 *)map + M2C_FIELD(map, u16 *, 0x52a4) * 140;
        s32 elapsed = M2C_FIELD(player, s32 *, 0x682c);
        if (!elapsed) return;
        total -= elapsed;
    }

    if (total < 0) total = 0;

    minutes = HardDiv(total, 60);
    centis = HardDiv((total % 60) * 100, 60);

    palette = 8;
    separator = 180;
    if (total < 600) {
        palette = 10;
        separator = 181;
    }

    savedSpriteEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    AddSprite(x, y, ((182 >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30)) & 1023) | 0x6000, gTimerColonTiles, 1);
    AddSprite(x + 72, y, ((centis % 10 + 140) & 1023) | ((palette & 15) << 12), gTimerDigitTiles, 1);

    centis = HardDiv(centis, 10);
    AddSprite(x + 64, y, ((centis % 10 + 140) & 1023) | ((palette & 15) << 12), gTimerDigitTiles, 1);
    AddSprite(x + 56, y, ((separator >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30)) & 1023) | 0x6000, gTimerDigitTiles, 1);

    x += 48;
    do {
        AddSprite(x, y, ((minutes % 10 + 140) & 1023) | ((palette & 15) << 12), gTimerDigitTiles, 1);
        minutes = HardDiv(minutes, 10);
        x -= 8;
    } while (minutes != 0);

    gCur3DSpriteEngine = savedSpriteEngine;
}

s32 GetInfoWindowLanguage(void) {
    extern Ov000MenuState *gOv000InfoWindow;
    return M2C_FIELD(gOv000InfoWindow, s32 *, 0x1C);
}

/* Initialize the 0x14-byte sub-object stored at entry+0x10 (allocating it
 * and its 0x104-byte descriptor) and clear the leading fields of entry. */
void *Ov000_StatsWindow_Create(void *entry) {
    s32 *MemAlloc(M2C_UNK);
    s32 *alloc;

    M2C_FIELD(entry, s32 *, 0) = 0;
    M2C_FIELD(entry, s32 *, 4) = 0;
    M2C_FIELD(entry, s32 *, 8) = 0;
    M2C_FIELD(entry, s8 *, 0xC) = 0;
    alloc = MemAlloc(0x104);
    M2C_FIELD(entry, s32 **, 0x10) = alloc;
    *alloc = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x18) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x1C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x20) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x24) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x28) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x34) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x30) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x44) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xC) = -1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 4) = 1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x58) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x5C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x48) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x49) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x50) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x4C) = 0x63;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x54) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x60) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xFC) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x100) = 0;
    return entry;
}

/* Free the unit-statistics window's panel descriptor (the 0x104-byte block at
 * +0x10) and return the window; the window object itself is left to the caller. */
void *Ov000_StatsWindow_FreePanel(void *window) {
    M2C_UNK MemFree(s32);

    MemFree((s32)((Ov000StatsWindow *)window)->panel);
    return window;
}

/* Reset the unit-statistics window: clear the sub engine's three layers, mark
 * layer 1 dirty, zero layer 1's quad offsets, then restart the window's redraw
 * in mode 2 with its blink counter cleared. */
void Ov000_StatsWindow_Reset(void *arg0) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    Clear3DSpriteLayer(2);
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER1);
    DS3D_BANK(gCur3DSpriteEngine)->corner[1] = 0;
    DS3D_BANK(gCur3DSpriteEngine)->corner[5] = 0;
    ((Ov000StatsWindow *)arg0)->drawMode = 2;
    ((Ov000StatsWindow *)arg0)->blinkFrame = 0;
    gCur3DSpriteEngine = savedEngine;
}

void func_ov000_02175230(void) {

}

void func_ov000_02175234(void *arg0){
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    void *saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 16), s32 *, 8) <= 0) {
        return;
    }

    switch (M2C_FIELD(arg0, s32 *, 4)) {
        case 1:
            ClearTileRect(M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), 32, 32);
            Ov000_StatsWindow_RedrawPanelTheme(arg0);
            Ov000Info_DrawFullPanel(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 2:
            Ov000_StatsWindow_RedrawPanelTheme(arg0);
            Ov000Info_DrawFullPanel(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 0:
            M2C_FIELD(arg0, s32 *, 8)++;
            if (M2C_FIELD(arg0, s32 *, 8) >= 80) {
                M2C_FIELD(arg0, s32 *, 8) = 0;
            }
            if (M2C_FIELD(arg0, s32 *, 8) == 0 || M2C_FIELD(arg0, s32 *, 8) == 40) {
                Ov000Info_DrawBlinkPanel(arg0);
            }
            break;
    }

    func_ov000_02175fb0(arg0);
    gCur3DSpriteEngine = saved;
}

