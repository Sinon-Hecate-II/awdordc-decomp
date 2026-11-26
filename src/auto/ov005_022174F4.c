/* 9 functions from 0x022174F4 to 0x02218008 (ov005), found by ds-decomp. */
#include "common.h"
#include "ov005_menu.h"
#include "sound.h"
#include "sound.h"
extern void *gOv005MenuState, *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
extern u8 gSpriteDesc64x8[];
#define STATE gOv005MenuState
#define ENGINE M2C_FIELD(gCur3DSpriteEngine,void**,0)
#define SIZE ((u32)(M2C_FIELD(ENGINE,u16*,0)<<17)>>30)
#define ATTR(tile,pal) ((u16)(((tile)>>SIZE & 0x3ff)|(pal)))

/* Draws the face graphic of the CO the detail list is currently on (BASE_INDEX) into
 * the sub screen's 3D sprite layer: the face texture and palette are loaded and its
 * tile map filled in, or the face tile is cleared when that CO is still locked. */
void Ov005RefreshEntryFace(void) {
extern void *gOv005MenuState, *gCur3DSpriteEngine, *g3DSpriteEngineSub;
s32 coId = M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_BASE_INDEX);
void *saved = gCur3DSpriteEngine;
gCur3DSpriteEngine = g3DSpriteEngineSub;
if (IsCoUnlocked(M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_BASE_INDEX))) {
MI_CpuFill32(0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xc), 0x40);
LoadFaceTexture(coId, 8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xc) + 0x40);
LoadFacePalette(coId, 8, 2, 0, 0);
FillFaceTileMap(8, 12, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 1, 0, 0);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
SetOv005FileDirectory();
} else {
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20) + 0x18, 0x14, 0x18);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
}
gCur3DSpriteEngine = saved;
}

/* Refreshes the entry label of the detail list's CO (BASE_INDEX) in the main
 * screen's 3D sprite layer: the CO's face graphics and palette are loaded, or
 * the label's graphics are cleared while that CO is still locked. */
void Ov005RefreshEntryLabel(void) {
extern void *gOv005MenuState,*gCur3DSpriteEngine,*g3DSpriteEngineMain;
s32 coId=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX);
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
if(IsCoUnlocked(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX)))
LoadFaceTextureAndPalette(coId,OV005_LABEL_VRAM_OFFSET,OV005_LABEL_PALETTE);
else MI_CpuFill32(0,M2C_FIELD(g3DSpriteEngineMain,s32 *,0x1c)+OV005_LABEL_VRAM_OFFSET,OV005_LABEL_CLEAR_SIZE);
gCur3DSpriteEngine=saved;
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SCROLL_VEL)=-1;
}

#pragma opt_strength_reduction off
void func_ov005_022176a0(void){
s32 IsCoUnlocked(s32);void AddSprite(u16,u16,u16,void*,s32);
void AddFaceSpriteTile(s32,s16,s16,u16,s32,s32);void AddFaceSprite(s16,s16,u16,s32);
void Set3DSpriteSlideTargetAndStart(void*,s32,s32,s32,s32);u32 GetUnitSpriteWidth(void*);u32 GetUnitSpriteHeight(void*);
void SpriteCellListSetCellRect(void*,s32,s16,s16,u16,u16);void Ov005RefreshNameGraphic(void);
s32 EaseInterpolate(s32,s32,s32,s32,s32);
s32 i; s16 x,y;void *saved;
M2C_FIELD(STATE,s16*,0x16)+=M2C_FIELD(STATE,s16*,0x18);
if(M2C_FIELD(STATE,s16*,0x16)<0)M2C_FIELD(STATE,s16*,0x16)=0;
if(M2C_FIELD(STATE,s16*,0x16)>12)M2C_FIELD(STATE,s16*,0x16)=12;
{ void *saved=gCur3DSpriteEngine; s32 tile=0x49c;
for(i=0;i<12;tile+=24,i++){
x=M2C_FIELD(STATE,s16*,8)+((i%4)*50+30);y=(i/4)*18+87;
gCur3DSpriteEngine=g3DSpriteEngineMain;
AddSprite((u16)((x+2)&511),(u8)(y+1),ATTR(0x40c,0x7800),gSpriteDesc64x8,0);
AddSprite((u16)((x+2)&511),(u8)(y+9),ATTR(0x414,0x7800),gSpriteDesc64x8,0);
if(IsCoUnlocked(i+1))AddFaceSpriteTile(0,x,y,(u16)(((i<<12)&0xffff)|0x400|((tile)>>SIZE&0x3ff)),0,0);
gCur3DSpriteEngine=saved;
}
}
{s32 delta; s16 px; void *p; i=0;delta=14;
for(;i<4;i++,delta+=60){
px=M2C_FIELD(STATE,s16*,10)+delta;
p=M2C_FIELD(STATE+i*4,void**,0x2c);
Set3DSpriteSlideTargetAndStart(p,px,90,px,90);
if((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)){s16 y=M2C_FIELD(p,s16*,0x52);s16 x=M2C_FIELD(p,s16*,0x50);u32 w=GetUnitSpriteWidth(p);SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));}
M2C_FIELD(p,s16*,0x34)=px;M2C_FIELD(p,s16*,0x36)=90;
if((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)){s16 y=M2C_FIELD(p,s16*,0x52);s16 x=M2C_FIELD(p,s16*,0x50);u32 w=GetUnitSpriteWidth(p);SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));}
}
}
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
if(IsCoUnlocked(M2C_FIELD(STATE,s16*,14)+1))AddFaceSprite(98,32,ATTR(0x41c,0x6000),0);
gCur3DSpriteEngine=g3DSpriteEngineSub;
if(M2C_FIELD(STATE,s16*,0x16)<=0)Ov005RefreshNameGraphic();
{
s16 pos=EaseInterpolate(4,-240,8,M2C_FIELD(STATE,s16*,0x16),12);
u32 left=pos&511; u32 right;
AddSprite((u16)left,24,ATTR(320,0x6000),gSpriteDesc64x8,0);
right=(pos+64)&511;
AddSprite((u16)right,24,ATTR(328,0x6000),gSpriteDesc64x8,0);
AddSprite((u16)left,32,ATTR(336,0x6000),gSpriteDesc64x8,0);
AddSprite((u16)right,32,ATTR(344,0x6000),gSpriteDesc64x8,0);
AddSprite((u16)left,40,ATTR(352,0x6000),gSpriteDesc64x8,0);
AddSprite((u16)right,40,ATTR(360,0x6000),gSpriteDesc64x8,0);
AddSprite((u16)left,48,ATTR(368,0x6000),gSpriteDesc64x8,0);
AddSprite((u16)right,48,ATTR(376,0x6000),gSpriteDesc64x8,0);
}
gCur3DSpriteEngine=saved;
if(M2C_FIELD(STATE,s16*,0x16)<=0){M2C_FIELD(STATE,s16*,0x18)=1;Ov005RefreshEntryFace();}
if(M2C_FIELD(STATE,s16*,0x16)>=12&&M2C_FIELD(STATE,s16*,0x18)==1)M2C_FIELD(STATE,s16*,0x18)=0;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
{s32 offset=EaseInterpolate(4,-240,0,M2C_FIELD(STATE,s16*,0x16),12);M2C_FIELD(ENGINE,s16*,0x38)=offset;}
M2C_FIELD(ENGINE,s16*,0x40)=0;
gCur3DSpriteEngine=saved;
}
#pragma opt_strength_reduction reset
/* D-pad input on the page-0 CO grid (twelve COs in rows of four): move the
 * selection kept in *selection up/down a whole row or left/right one slot,
 * wrapping at both ends, focus the newly selected slot and record it as the
 * menu's index, with the detail list based on the CO after it. */
void Ov005MoveCoListSelection(u8 *selection) {
extern void *gKeyState,*gOv005MenuState;
u32 old=*selection; u16 keys=M2C_FIELD(gKeyState,u16 *,2*KEY_PRESSED);s32 value=old;
if(keys&KEY_UP)value=old-OV005_MENU_CO_COLUMNS;
else if(keys&KEY_DOWN)value=old+OV005_MENU_CO_COLUMNS;
else if(keys&KEY_LEFT)value=old-1;
else if(keys&KEY_RIGHT)value=old+1;
if(value<0)value+=OV005_MENU_CO_COUNT;
if(value>OV005_MENU_CO_COUNT-1)value-=OV005_MENU_CO_COUNT;
if(value!=old)FocusSpriteSlotById(value);
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_INDEX)=value;
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX)=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_INDEX)+1;
}

/* Select the page-0 CO grid slot that `selection` records: set the menu's list
 * index to it and the detail list's base index to the CO after it, then play the
 * menu-select sound. */
void Ov005SelectCoSlot(u8 *selection) {
    M2C_UNK PlaySoundEffect(s32);
    extern void *gOv005MenuState;
    M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_INDEX) = (s16) *selection;
    M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_BASE_INDEX) = (s16) (M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_INDEX) + 1);
    PlaySoundEffect(SOUND_MENU_SELECT);
}

/* Left/right input on the detail row's four entries: step the selection kept in
 * *selection by one, wrapping at either end (the wrap also happens while the
 * key stays held at the edge), then focus the entry's sprite slot and update
 * the entries' highlight frames. */
void Ov005MoveDetailSelection(u8 *selection) {
extern void *gKeyState;
u16 pressed;s32 old; s32 value;
old=*selection;pressed=M2C_FIELD(gKeyState,u16 *,2);value=old;
if(pressed&KEY_LEFT) {if(old<=0) {if(M2C_FIELD(gKeyState,u16 *,KEY_HELD)&KEY_LEFT)value=old-1;}else value=old-1;}
else if(pressed&KEY_RIGHT) {if(old>=OV005_MENU_DETAIL_COUNT-1) {if(M2C_FIELD(gKeyState,u16 *,KEY_HELD)&KEY_RIGHT)value=old+1;}else value=old+1;}
if(value<0)value=OV005_MENU_DETAIL_COUNT-1;
if(value>OV005_MENU_DETAIL_COUNT-1)value=0;
if(value!=old)FocusSpriteSlotById(value);
Ov005SetDetailSelection(value);
}

/* Apply a newly highlighted entry of the detail row: store it as the menu's
 * selection, highlight its sprite, remember the CO's mode with it, reload the
 * CO's face palettes and play the menu-select sound. */
void Ov005ApplyDetailSelection(u8 *selection) {
extern void *gOv005MenuState;
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION)=*selection;
Ov005SetDetailSelection(*selection);
SetCoSavedMode(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX),M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION));
Ov005LoadEntryFacePalettes(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX));
PlaySoundEffect(SOUND_MENU_SELECT);
}

/* Creates the twelve page-0 CO grid slot sprites, one per CO: four slots to a
   row, the grid starting at (X0, Y0) with each slot a STEP_X/STEP_Y step apart. */
void Ov005AddCoGridSprites(void) {
    M2C_UNK AddSpriteSlot(s32, s32, M2C_UNK *, s32);
    extern M2C_UNK gOv005CoGridSlotDef;
    s32 i = 0;
    do {
        AddSpriteSlot((i % OV005_MENU_CO_COLUMNS) * OV005_CO_GRID_STEP_X + OV005_CO_GRID_X0,
                      (i / OV005_MENU_CO_COLUMNS) * OV005_CO_GRID_STEP_Y + OV005_CO_GRID_Y0,
                      &gOv005CoGridSlotDef, i);
        i++;
    } while (i < OV005_MENU_CO_COUNT);
}

/* Create the four slot sprites of the detail row, one per entry, laid out left to
 * right at the row's position. */
void Ov005AddDetailSprites(void) {
    M2C_UNK AddSpriteSlot(s32, s32, M2C_UNK *, s32);
    extern M2C_UNK gOv005DetailRowSlotDef;
    s32 entry;
    s32 x;

    entry = 0;
    x = OV005_DETAIL_ROW_X0;
    do {
        AddSpriteSlot(x, OV005_DETAIL_ROW_Y, &gOv005DetailRowSlotDef, entry);
        entry += 1;
        x += OV005_DETAIL_ROW_STEP;
    } while (entry < OV005_MENU_DETAIL_COUNT);
}

