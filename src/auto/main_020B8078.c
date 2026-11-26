/* 20 functions from 0x020B8078 to 0x020B8CCC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "menu_list.h"

extern M2C_UNK gMenuListRowSlotDef;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineMain;
extern u8 data_02129114[12];
extern u8 data_02129120[16];
extern u8 data_02129130[16];
extern u8 data_02129140[16];

/* Spawns the end-of-battle "map clear" transition for the relevant side: picks the
 * winning, losing or drawn variant, positions the sprite and wires its fade
 * callbacks, then loads the army-specific mapclear0..3 sprite file. */
void SpawnMapClearEffect(void *arg0){
extern void **gCurrentMap;
M2C_UNK SetFileDirectory(M2C_UNK *);
M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
s32 GetScreenFlag(M2C_UNK);
void *CreateMapClearWinObject(M2C_UNK);
void *CreateMapClearLoseObject(M2C_UNK);
void *CreateMapClearDrawObject(M2C_UNK);
s32 DidPlayerWin(void);
s32 DidPlayerLose(void);
s32 IsBattleDraw(void);
s32 GetWinningPlayer(void);
s32 GetLosingPlayer(void);
extern M2C_UNK data_0212906c;
extern M2C_UNK data_02129074;
extern M2C_UNK data_02129084;
extern M2C_UNK data_02129094;
extern M2C_UNK data_021290a4;
extern M2C_UNK func_020b7c4c;
extern M2C_UNK func_020b7c5c;
extern M2C_UNK Reset3DSpriteBankSplit;
register void *effect asm("r4");
register u8 player asm("r5");
u8 armyIndex;
effect=NULL;
player=(u8)M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER);
if(GetScreenFlag(3)==1)return;
if(DidPlayerWin()!=0){
effect=CreateMapClearWinObject(arg0);
player=(u8)GetWinningPlayer();
}else if(DidPlayerLose()!=0){
effect=CreateMapClearLoseObject(arg0);
player=(u8)GetLosingPlayer();
}else if(IsBattleDraw()!=0){
effect=CreateMapClearDrawObject(arg0);
}
if(effect==NULL)return;
M2C_FIELD(effect,s32 *,0x34)=0x80;
M2C_FIELD(effect,s32 *,0x38)=0x60;
M2C_FIELD(effect,s32 *,0x3C)=0;
M2C_FIELD(effect,s32 *,0x44)=(s32)(M2C_FIELD(effect,s32 *,0x44)|0x300000);
M2C_FIELD(effect,M2C_UNK **,0x68)=&func_020b7c4c;
M2C_FIELD(effect,M2C_UNK **,0x6C)=&func_020b7c5c;
M2C_FIELD(effect,M2C_UNK **,0x70)=&Reset3DSpriteBankSplit;
SetFileDirectory(&data_0212906c);
armyIndex=M2C_FIELD((u8 *)*gCurrentMap+player*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_INDEX_OFF);
switch(armyIndex){
case 1:
LoadFileToSpriteBuffer(&data_02129074,0x360,0x20);
return;
case 2:
LoadFileToSpriteBuffer(&data_02129084,0x360,0x20);
return;
case 3:
LoadFileToSpriteBuffer(&data_02129094,0x360,0x20);
return;
case 4:
LoadFileToSpriteBuffer(&data_021290a4,0x360,0x20);
return;
}
return;
}

void func_020b8208(void *arg0) {
s16 *p=(s16 *)arg0;
p[42]=0; p[41]=4;
}

/* Per-frame callback of the map-clear effect that ramps its blend the other way
   from UpdateMapClearFade: it steps the frame counter, sets the 3D sprite bank's
   blend level along the 0 -> 4 easing curve with priority 3 and the attribute
   mode bits cleared, then removes the effect once the duration is over. */
void UpdateMapClearFadeIn(void *effect) {
    M2C_UNK DeleteSpriteObject(void *);
    s8 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s16, s32);
    M2C_UNK Reset3DSpriteBankState();
    extern void *g3DSpriteBankMain;
    s8 blend;

    M2C_FIELD(effect, s16 *, 0x54) = (s16) (M2C_FIELD(effect, s16 *, 0x54) + 1);
    blend = EaseInterpolate(0, 0, 4, M2C_FIELD(effect, s16 *, 0x54), (s32) M2C_FIELD(effect, s16 *, 0x52));
    Reset3DSpriteBankState();
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) ((M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0xC0) | 0xC0);
    M2C_FIELD(g3DSpriteBankMain, s8 *, DS3D_BANK_BLEND) = blend;
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) ((M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~1) | 1);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~2);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~4);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~8);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x10);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x100);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x200);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x400);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x800);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x1000);
    if ((s32) M2C_FIELD(effect, s16 *, 0x54) < (s32) M2C_FIELD(effect, s16 *, 0x52)) {
        return;
    }
    DeleteSpriteObject(effect);
}

void func_020b8338(void *arg0) {
s16 *p=(s16 *)arg0;
p[42]=0; p[41]=2;
}

/* Per-frame callback of the map-clear effect: step its frame counter, set the 3D
   sprite bank's blend level along the 4 -> 0 easing curve with priority 3 and the
   attribute mode bits cleared, then remove the effect once the duration is over. */
void UpdateMapClearFade(void *effect) {
    M2C_UNK DeleteSpriteObject(void *);
    s8 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s16, s32);
    M2C_UNK Reset3DSpriteBankState();
    extern void *g3DSpriteBankMain;
    s8 blend;

    M2C_FIELD(effect, s16 *, 0x54) = (s16) (M2C_FIELD(effect, s16 *, 0x54) + 1);
    blend = EaseInterpolate(0, 4, 0, M2C_FIELD(effect, s16 *, 0x54), (s32) M2C_FIELD(effect, s16 *, 0x52));
    Reset3DSpriteBankState();
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) ((M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0xC0) | 0xC0);
    M2C_FIELD(g3DSpriteBankMain, s8 *, DS3D_BANK_BLEND) = blend;
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) ((M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~1) | 1);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~2);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~4);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~8);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x10);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x100);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x200);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x400);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x800);
    M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, DS3D_BANK_OAMATTR) & ~0x1000);
    if ((s32) M2C_FIELD(effect, s16 *, 0x54) < (s32) M2C_FIELD(effect, s16 *, 0x52)) {
        return;
    }
    Reset3DSpriteBankState();
    DeleteSpriteObject(effect);
}

/* True when the menu list's row `row` cannot be picked: either its per-row flag
 * is set or the whole list carries the unavailable mark (both draw it greyed). */
u8 IsListRowUnavailable(M2C_UNK row) {
    void *GetMenuList(void);
    s32 IsListRowFlagSet(M2C_UNK);
    void *list;
    list = GetMenuList();
    return (IsListRowFlagSet(row) != 0) || (M2C_FIELD(list, u8 *, MENU_LIST_ROW_MARK) != 0);
}

void DrawListRowsAtOffset(s32 arg0, s32 arg1) {
    void DrawTilemapNumber(s32, s32, void *, s32, s32, s32);
    u8 IsListRowUnavailable(s32);
    M2C_UNK DrawLocalizedTextLine(M2C_UNK, s16, M2C_UNK, s32, s32, s32, s32);
    extern M2C_UNK data_02127c0c;
    extern s32 gListRowDrawOffset;
    extern void *g3DSpriteEngineMain;
    extern void *data_027e01d8;
    s32 var_r5;
    u16 var_r4;
    void *temp_r6;

    if (IsListRowUnavailable(arg1) == 0) {
        var_r5 = 0x4100002E;
        var_r4 = 3;
    } else {
        var_r4 = 0;
        var_r5 = *(&data_02127c0c + (arg1 * 8));
    }
    temp_r6 = data_027e01d8;
    data_027e01d8 = g3DSpriteEngineMain;
    DrawTilemapNumber(3, (s16) (arg0 + 5), M2C_FIELD(data_027e01d8, s32 *, 0x24), arg1 + 1, 0, (s32) var_r4);
    DrawLocalizedTextLine(6, (s16) (arg0 + 5), 1, var_r5, 0, (s32) var_r4, (s32) (u16) gListRowDrawOffset);
    data_027e01d8 = temp_r6;
    gListRowDrawOffset += 0x24;
}

/* Redraw the six visible menu-list rows at pixel `offset` of the scroll: clear
 * the row block, draw the rows (seven of them, two rows apart, for an odd
 * offset), then clear the two scroll strips an odd offset leaves empty. */
void RedrawListRows(s32 offset) {
    M2C_UNK ClearTileRect(s32, M2C_UNK, M2C_UNK);
    void DrawListRowsAtOffset(s32, s32);
    extern s32 gListRowDrawOffset;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;
    s32 var_r7_2;
    void *savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    gListRowDrawOffset = 0x124;
    ClearTileRect(M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x24) + 0x140, 0x20, 0xC);
    if (offset & 1) {
        var_r5 = 0;
        var_r6 = offset >> 1;
        var_r7 = -1;
        do {
            DrawListRowsAtOffset(var_r7, var_r6);
            var_r5 += 1;
            var_r6 += 1;
            var_r7 += 2;
        } while (var_r5 < 7);
        ClearTileRect(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x100, 0x19, 1);
        ClearTileRect(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x440, 0x19, 1);
    } else {
        var_r7_2 = 0;
        var_r6_2 = 0;
        var_r5_2 = offset >> 1;
        do {
            DrawListRowsAtOffset(var_r6_2, var_r5_2);
            var_r7_2 += 1;
            var_r5_2 += 1;
            var_r6_2 += 2;
        } while (var_r7_2 < 6);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    gCur3DSpriteEngine = savedEngine;
}

s32 ScrollListUp(void *arg0) {
    s16 n = M2C_FIELD(arg0, s16 *, 0x40);

    if (n != 0) {
        M2C_FIELD(arg0, s16 *, 0x40) = n - 1;
        return 1;
    }
    return 0;
}
#pragma optimization_level 4
/* Scroll the menu list up one page: move the first visible row back by a page,
 * clamped at the first row, and return how far it moved (0 when already at the top). */
s16 PageListUp(void *list) {
    s16 old = M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW);
    M2C_FIELD(list, volatile s16 *, MENU_LIST_FIRST_ROW) = old - MENU_LIST_VISIBLE_ROWS;
    if (M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW) < 0) {
        M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW) = 0;
    }
    return M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW) - old;
}

/* Scroll the menu list's window down one row while a row still follows it:
 * advance the first visible row and report 1, or report 0 at the end of the
 * list (the window's last row, firstRow + MENU_LIST_VISIBLE_ROWS - 1, is the
 * list's last row). */
s32 ScrollListDown(void *list) {
    s16 firstRow = M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW);

    if (firstRow + MENU_LIST_VISIBLE_ROWS >= M2C_FIELD(list, s16 *, MENU_LIST_ROW_COUNT)) goto done;
    M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW)++;
    return 1;
done:
    return 0;
}

/* Page the list down: move the window's first visible row down by
 * MENU_LIST_VISIBLE_ROWS, clamped so the window still holds a full page, and
 * return by how many rows the window actually moved. */
s16 PageListDown(void *list) {
    s16 old = M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW);
    s32 max;

    M2C_FIELD(list, volatile s16 *, MENU_LIST_FIRST_ROW) = old + MENU_LIST_VISIBLE_ROWS;
    max = M2C_FIELD(list, volatile s16 *, MENU_LIST_ROW_COUNT) - MENU_LIST_VISIBLE_ROWS;
    if (M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW) > max) M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW) = max;
    return M2C_FIELD(list, s16 *, MENU_LIST_FIRST_ROW) - old;
}

/* Dismiss the scrollable menu list: play the menu back sound, resume the list's
 * sprite animation, hide the sprite slots it had enabled and close them. */
M2C_UNK CloseMenuList(void) {
    void *GetMenuList(void);
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK HideEnabledSpriteSlots();
    M2C_UNK CloseAllActiveSpriteSlots();
    void *list;

    list = GetMenuList();
    PlaySoundEffect(0x10018);
    Sprite_ResumeAnimation(list);
    HideEnabledSpriteSlots();
    CloseAllActiveSpriteSlots();
}

void func_020b876c(void) {
    M2C_UNK CloseMenuList();
    CloseMenuList();
}

void func_020b8778(void) {
    M2C_UNK CloseMenuList();
    M2C_UNK CancelScreenTransition();
    CancelScreenTransition();
    CloseMenuList();
}

/* Key handler for the scrollable menu list: up/down move the selected row and
 * scroll the window, a held up/down at either end wraps to the other end, and
 * left/right page the list by six rows.  The focused row is written back to the
 * list and its sprite slot is focused. */
void HandleListCursorInput(u8 *selection){void *GetMenuList(void);s32 FindSpriteSlotById(s32);void FocusSpriteSlotById(s32);extern u16 *gKeyState;void *list=GetMenuList();s32 maxFirstRow=M2C_FIELD(list,s16 *,MENU_LIST_ROW_COUNT)-MENU_LIST_VISIBLE_ROWS;s32 row=*selection;s32 firstRow=M2C_FIELD(list,s16 *,MENU_LIST_FIRST_ROW);if(maxFirstRow<0)maxFirstRow=0;
if(firstRow==0&&row==0){if(gKeyState[KEY_HELD]&KEY_UP){M2C_FIELD(list,s16 *,MENU_LIST_FIRST_ROW)=maxFirstRow;row=5;goto done;}}
else if(gKeyState[KEY_PRESSED]&KEY_UP){if(row>=2)row--;else if(!ScrollListUp(list)&&row>0)row--;goto done;}
if(firstRow==maxFirstRow&&row==5){if(gKeyState[KEY_HELD]&KEY_DOWN){row=0;M2C_FIELD(list,s16 *,MENU_LIST_FIRST_ROW)=row;goto done;}}
else if(gKeyState[KEY_PRESSED]&KEY_DOWN){if(row<4){if(FindSpriteSlotById(row+1))row++;}else if(!ScrollListDown(list)){if(FindSpriteSlotById(row+1))row++;}goto done;}
if(gKeyState[KEY_PRESSED]&KEY_LEFT){row-=PageListUp(list)+6;if(row<0)row=0;RedrawListRows(M2C_FIELD(list,s16 *,MENU_LIST_SCROLL_OFFSET));}
else if(gKeyState[KEY_PRESSED]&KEY_RIGHT){row+=6-PageListDown(list);if(row>=6)row=5;RedrawListRows(M2C_FIELD(list,s16 *,MENU_LIST_SCROLL_OFFSET));}
done:if(row!=*selection)FocusSpriteSlotById(row);M2C_FIELD(list,s16 *,MENU_LIST_ROW)=row;}

void func_020b88f8(u8 *arg0) {
    void *GetMenuList(void);
    M2C_FIELD(GetMenuList(), s16 *, 0x3a) = *arg0;
}

/* Creates the six row sprite slots of the scrollable menu list, stacked
 * MENU_LIST_ROW_SLOT_STEP pixels apart from y MENU_LIST_ROW_SLOT_Y, and focuses
 * the first row. */
void CreateMenuListRowSlots(void) {
    void *GetMenuList(void);
    s32 row;
    s32 y;

    GetMenuList();
    row = 0;
    y = MENU_LIST_ROW_SLOT_Y;
    do {
        AddSpriteSlot(MENU_LIST_ROW_SLOT_X, y, &gMenuListRowSlotDef, row);
        row++;
        y += MENU_LIST_ROW_SLOT_STEP;
    } while (row < MENU_LIST_VISIBLE_ROWS);
    SelectSpriteSlot(0);
}

#pragma optimization_level 2
/* Returns the active instance registered under gMenuListClass. */
void *GetMenuList(void) {
    void *FindObjectByClass();
    extern M2C_UNK gMenuListClass;
    return FindObjectByClass(&gMenuListClass);
}

/* Initializes the shop menu and its UI elements */
void func_020b8970(void *arg0) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    void Clear3DSpriteLayer(s32);
    void AddTileRectPalette(void *, s32, s32, s32);
    void LoadDecompressedFileTo(void *, void *);
    void SpriteCellListSetCellRect(void *, s32, s32, s32, s32, s32);
    void Set3DSpriteSlideTargetAndStart(void *, s32, s32, s32, s32);
    void Show3DSpriteSlide(void *);
    void Load3DSpritePattern(void *, s32, s32, s32);
    void ResetTextTiles(s32);
    void DrawTextToTilemap(s32, s32, void *, s32, s32, s32);
    void DrawTilemapNumber(s32, s32, void *, s32, s32, s32);
    s32 func_020a8b78(void);
    s32 GetUnitSpriteWidth(void *);
    s32 GetUnitSpriteHeight(void *);
    s32 GetUiColor(s32);
    u8 IsListRowUnavailable(s32);
    void RedrawListRows(s32);
    void CreateMenuListRowSlots(void);
    void CreateMenuUnitSprite(void *);
    s32 IsFreePlayBattleMode(void);
    void CreateMenuTextSprite(void *, s32, s32, s32, s32, s32, s32, void *, s32);
    void *GetLocalizedFileName(void *);
    void *temp_r4;
    void *temp_r5;
    s16 temp_r6;
    s16 temp_r7;
    s32 temp_r9;
    s32 temp_r10;
    s32 var_r5;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    ResetTextTiles(0);
    M2C_FIELD(arg0, u8 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x3a) = 0;
    M2C_FIELD(arg0, s16 *, 0x42) = 0x2e;
    M2C_FIELD(arg0, s16 *, 0x3e) = 0;
    M2C_FIELD(arg0, s16 *, 0x40) = 0;
    M2C_FIELD(arg0, s16 *, 0x44) = 0;
    M2C_FIELD(arg0, s16 *, 0x3c) = 0;
    M2C_FIELD(arg0, s16 *, 0x46) = 0;
    if (IsFreePlayBattleMode() != 0) {
        M2C_FIELD(arg0, u8 *, 0x34) = 1;
    }
    var_r5 = 0;
    if (M2C_FIELD(arg0, s16 *, 0x42) > 0) {
        do {
            if (IsListRowUnavailable(var_r5) != 0) {
                M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 1);
            }
            var_r5++;
        } while (var_r5 < M2C_FIELD(arg0, s16 *, 0x42));
    }
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3a) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    SetFileDirectory((M2C_UNK *) data_02129114);
    LoadDecompressedFileTo(GetLocalizedFileName(data_02129120), M2C_FIELD(g3DSpriteEngineMain, void **, 0x14));
    LoadDecompressedFileTo(GetLocalizedFileName(data_02129130), M2C_FIELD(gCur3DSpriteEngine, void **, 0x28));
    LoadFileToSpriteBuffer((M2C_UNK *) data_02129140, 0xc0, 0x20);
    AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, void **, 0x28), 0x20, 0x18, 6);
    CreateMenuTextSprite((u8 *) arg0 + 0x48, 0x5e, 0x8b, 0xa, 0x39c, 3, -1, arg0, 1);
    CreateMenuTextSprite((u8 *) arg0 + 0x4c, 0x82, 0x8b, 0xb, 0x3a4, 3, -1, arg0, 0);
    CreateMenuTextSprite((u8 *) arg0 + 0x50, 0xc0, 0xa0, 0, 0x3ac, 3, 1, arg0, 0);
    temp_r5 = M2C_FIELD(arg0, void **, 0x50);
    Set3DSpriteSlideTargetAndStart(temp_r5, 0xc0, 0xa0, 0x100, 0xa0);
    if ((u8) (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0)) {
        temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r9 = GetUnitSpriteWidth(temp_r5);
        temp_r10 = GetUnitSpriteHeight(temp_r5);
        SpriteCellListSetCellRect(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7, temp_r6, (u16) temp_r9, (u16) temp_r10);
    }
    Show3DSpriteSlide(M2C_FIELD(arg0, void **, 0x50));
    CreateMenuUnitSprite(arg0);
    Load3DSpritePattern((void *) 0x6b80, 0xb, GetUiColor(0xc), 2);
    DrawTilemapNumber(0x1b, 3, M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), M2C_FIELD(arg0, s16 *, 0x44), 0, 0);
    DrawTextToTilemap(0x1c, 3, M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), func_020a8b78(), 0, 0);
    DrawTilemapNumber(0x1e, 3, M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), M2C_FIELD(arg0, s16 *, 0x42), 0, 0);
    RedrawListRows(M2C_FIELD(arg0, s16 *, 0x3e));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    CreateMenuListRowSlots();
    gCur3DSpriteEngine = temp_r4;
}

#pragma optimization_level 4
