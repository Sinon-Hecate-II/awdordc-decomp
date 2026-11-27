/* 12 functions from 0x020B34F8 to 0x020B4264 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "battle_map.h"
#include "sprite_grid.h"
#include "sound.h"
extern void **gCurrentMap;
extern u16 gOptionBits[];
extern u8 gMapConfig[];
extern u8 *gMapData;
typedef struct { u8 a[33],b;u16 c,d,e; s16 f,g,h,i;u16 j,k;u8 l,m,n,o,p,q,r,s;u8 t[2],u[2];u8 v[322]; } SettingsB3C;
typedef struct {u16 a;u8 b,c;u16 d,e;u32 f,g;} HeaderB3C;
typedef struct {u32 a,b,c,d;u8 e[10];u16 f;u8 g[4];u16 h,i;s8 j;u8 k,l,m,n,o,p,q,r,s,t,u,v,w,z;u8 aa[27],bb[27];u32 cc,dd;u32 ee[4];u32 ff,gg;} PlayerB3C;
typedef struct {u8 a,b,c;u16 d,e,f;u8 g,h;u8 i[2];} UnitB3C;
typedef struct {u8 a,b;u16 c;u8 d,e;s8 f,g;} RecordB3C;
typedef struct {u8 a[33];} Bytes33B3C;
typedef struct {u8 a[322];} Bytes322B3C;
typedef struct {u8 a[27];} Bytes27B3C;
typedef struct {u8 a[2];} Bytes2B3C;
typedef struct {u32 a[4];} Words4B3C;

/* Pages the sprite grid up (towards the first item) by one screenful: moves the
 * cursor and the scroll position back by up to SPRITE_GRID_ROWS rows and starts
 * the scroll's pixel animation.  Returns 1 when the animation was started, 0 when
 * it was already running or nothing moved. */
u8 ScrollSpriteGridPageUp(void *grid) {
    s32 Divide();
    M2C_UNK PlaySoundEffect(s32);
    s32 active, i, factor, delta;
    s16 oldScroll, count;
    u8 cols, result;
    s32 itemsPerPage;

    if (M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    if (active & 0xFF) {
        return 0U;
    }
    cols = M2C_FIELD(grid, u8 *, SPRITE_GRID_COLUMNS);
    itemsPerPage = M2C_FIELD(grid, u8 *, SPRITE_GRID_ROWS);
    count = Divide(M2C_FIELD(grid, s16 *, SPRITE_GRID_ITEM_COUNT) + cols - 1, cols);
    count = (oldScroll = M2C_FIELD(grid, volatile s16 *, SPRITE_GRID_SCROLL), itemsPerPage >= count ? count : itemsPerPage);
    for (i = 0; i < count; i++) {
        if (M2C_FIELD(grid, s16 *, SPRITE_GRID_SCROLL) != 0) {
            M2C_FIELD(grid, s16 *, SPRITE_GRID_SCROLL) -= 1;
        }
        if (M2C_FIELD(grid, s16 *, SPRITE_GRID_SELECTED) - cols >= 0) {
            M2C_FIELD(grid, s16 *, SPRITE_GRID_SELECTED) -= cols;
        }
    }
    if (oldScroll != M2C_FIELD(grid, s16 *, SPRITE_GRID_SCROLL)) {
        PlaySoundEffect(0x10019);
    }
    delta = M2C_FIELD(grid, s16 *, SPRITE_GRID_SCROLL);
    factor = M2C_FIELD(grid, u8 *, SPRITE_GRID_CELL_HEIGHT);
    delta -= oldScroll;
    M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = (s16)(delta * factor);
    if (M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

#pragma opt_propagation off
/* Keyboard handler of a sprite grid: with several columns, left/right move the
 * cursor one item (wrapping to the row's end when held), otherwise they page the
 * grid a screenful; up/down move it a row (paging to the ends when held) and
 * scroll the grid to keep the cursor visible, setting the animation offset.
 * Plays the cursor-move sound when the selection or the scroll position moved. */
void HandleSpriteGridKeyInput(void *grid) {
s32 Divide(s32,s32);
s32 Modulo(s32,s32);
u8 ScrollSpriteGridPageDown(void *);
M2C_UNK PlaySoundEffect(s32);
extern u16 *gKeyState;

s32 held,pressed;
s32 columns;
s16 column,row,oldSelected;
s16 oldScroll,pages,itemCount;
s32 visibleRows;
s32 rowItems,active,delta,cellHeight;
columns=M2C_FIELD(grid,u8 *,SPRITE_GRID_COLUMNS);
itemCount=M2C_FIELD(grid,s16 *,SPRITE_GRID_ITEM_COUNT);
visibleRows=M2C_FIELD(grid,u8 *,SPRITE_GRID_ROWS);
pages=Divide(itemCount+columns-1,columns);
if(visibleRows>=pages)visibleRows=pages;
visibleRows=(s16)visibleRows;
column=Modulo(M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED),columns);
row=Divide(M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED),columns);
held=gKeyState[0];pressed=gKeyState[1];
oldScroll=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);
oldSelected=M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED);
if(columns>1){
rowItems=itemCount-row*columns;if(rowItems>columns)rowItems=columns;
if(pressed&KEY_LEFT){
if(column>0)M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)--;
else if(pressed==held)M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)+=rowItems-1;
}else if(pressed&KEY_RIGHT){
if(column<rowItems-1)M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)++;
else if(pressed==held)M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)-=rowItems-1;
}
}else{
if(pressed&KEY_LEFT){if(ScrollSpriteGridPageUp(grid))return;}
else if(pressed&KEY_RIGHT){if(ScrollSpriteGridPageDown(grid))return;}
}
active=M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)!=0;
if(!(active&255)){
if(pressed&KEY_UP){
if(row==0){
if(pressed==held){
M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)+=(pages-1)*columns;
rowItems=pages-visibleRows;if(rowItems<=0)rowItems=0;
M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)=rowItems;
rowItems=M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED);
if(rowItems>itemCount-1)rowItems=itemCount-1;
M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)=rowItems;
}
}else{
M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)-=columns;
rowItems=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);
if((s16)Divide(M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED),columns)-rowItems<=0){
if(rowItems>0)M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)--;
delta=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);cellHeight=M2C_FIELD(grid,u8 *,SPRITE_GRID_CELL_HEIGHT);delta-=oldScroll;
M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)=delta*cellHeight;
}
}
}else if(pressed&KEY_DOWN){
if(row==pages-1){
if(pressed==held){M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)-=(pages-1)*columns;M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)=0;}
}else{
M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)+=columns;
rowItems=M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED);
if(rowItems>itemCount-1)rowItems=itemCount-1;
M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)=rowItems;
row=Divide(M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED),columns);
rowItems=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);
if(row-rowItems>=visibleRows-1){
if(rowItems<pages-visibleRows)M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)=rowItems+1;
delta=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);cellHeight=M2C_FIELD(grid,u8 *,SPRITE_GRID_CELL_HEIGHT);delta-=oldScroll;
M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)=delta*cellHeight;
}
}
}
}
if(oldScroll!=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)||oldSelected!=M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED))PlaySoundEffect(0x10019);
}
#pragma opt_propagation off
/* Touch handler of the sprite grid: when no scroll animation is running and the
 * touch hit a cell of the visible page (its hit id is below rows*columns), it
 * selects the item that cell shows, scrolling the grid to it, and plays the menu
 * select sound when the selection or the scroll position moved. */
void HandleSpriteGridTouch(s32 grid) {
M2C_UNK ScrollSpriteGridToItem(s32,s16);
M2C_UNK PlaySoundEffect(s32);
u8 columns,rows; s8 hitId; s16 scroll,selected,pageItems,newItem;
if ((u8)(M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)!=0)) return;
columns=M2C_FIELD(grid,u8 *,SPRITE_GRID_COLUMNS);
rows=M2C_FIELD(grid,u8 *,SPRITE_GRID_ROWS);
hitId=M2C_FIELD(grid,s8 *,SPRITE_GRID_CELLS+SPRITE_CELL_LIST_HIT_ID);
scroll=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);
pageItems=(s16)(rows*columns);
selected=M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED);
if(hitId<0) return;
if(pageItems<=hitId) return;
newItem=(s16)(columns*scroll+hitId);
if(newItem!=selected)ScrollSpriteGridToItem(grid,newItem);
if(scroll==M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL) && selected==M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED))return;
PlaySoundEffect(SOUND_MENU_SELECT);
}
#pragma opt_propagation reset
/* Returns whether tile column x is currently visible in the camera viewport. */
u8 func_020b3960(void *camera, int x) {
int Divide(int,int);
u8 visibleTiles, tileSize; s16 total, scroll, tile; int tileCount;
visibleTiles=M2C_FIELD(camera,u8*,4); tileSize=M2C_FIELD(camera,u8*,5); total=M2C_FIELD(camera,s16*,10);
tileCount=(s16)Divide(total+tileSize-1,tileSize);
if(x<0 || total<=x)return 0;
scroll=M2C_FIELD(camera,s16*,12);
tile=Divide(x,tileSize);
if(tileCount>visibleTiles)tileCount=visibleTiles;
total=tileCount;
if(M2C_FIELD(camera,s16*,18)>0) {scroll-= (s16)Divide(M2C_FIELD(camera,s16*,18)+(M2C_FIELD(camera,u8*,7)-1),M2C_FIELD(camera,u8*,7)); total++;}
else if(M2C_FIELD(camera,s16*,18)<0) {scroll-=(s16)Divide(M2C_FIELD(camera,s16*,18),M2C_FIELD(camera,u8*,7)); total++;}
return scroll<=tile && tile<scroll+total;
}

/* Per-frame update of a sprite grid widget: eases its animated scroll offset
 * back to zero, updates the touch state of its embedded cell list (at +0x18),
 * then applies the keys and the touch to the grid's cursor. */
void UpdateSpriteGrid(void *grid) {
    M2C_UNK SpriteCellListUpdateTouch(M2C_UNK);
    M2C_UNK UpdateSpriteGridPixelOffset();

    UpdateSpriteGridPixelOffset();
    SpriteCellListUpdateTouch((u8 *) grid + SPRITE_GRID_CELLS);
    HandleSpriteGridKeyInput(grid);
    HandleSpriteGridTouch(grid);
}

/* Eases the sprite grid's cursor toward the selected cell: the cell's screen
 * position is its column (selected % columns) and its row relative to the scroll
 * (selected / columns - scroll), times the cell size, plus the grid's base origin.
 * The cursor is snapped onto the target once at most a pixel away, and otherwise
 * moved half the remaining distance; its initial position (both coordinates
 * -32768) snaps on the first update. */
void UpdateSpriteGridCursor(void *grid) {
s32 Divide();
s32 Modulo(s32,s32);
s16 cellWidth,cellHeight; s16 targetX,targetY,scroll,cursorX; s16 rowDelta; s32 dx,dy;
cellWidth=M2C_FIELD(grid,u8 *,SPRITE_GRID_CELL_WIDTH); cellHeight=M2C_FIELD(grid,u8 *,SPRITE_GRID_CELL_HEIGHT);
targetX=Modulo(M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED),M2C_FIELD(grid,u8 *,SPRITE_GRID_COLUMNS));
scroll=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);
rowDelta=Divide(M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED),M2C_FIELD(grid,u8 *,SPRITE_GRID_COLUMNS))-scroll;
targetX=(s16)(M2C_FIELD(grid,s16 *,SPRITE_GRID_BASE_X)+targetX*cellWidth);
targetY=(s16)(M2C_FIELD(grid,s16 *,SPRITE_GRID_BASE_Y)+rowDelta*cellHeight);
cursorX=M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_X);
if ((cursorX==-32768 && M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_Y)==-32768) || (((dx=cursorX-targetX)<0?-dx:dx)<=1 && ((dy=M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_Y)-targetY)<0?-dy:dy)<=1)) {
M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_X)=targetX; M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_Y)=targetY;
} else {
M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_X)=(targetX+cursorX+1)>>1;
M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_Y)=(targetY+M2C_FIELD(grid,s16 *,SPRITE_GRID_CURSOR_Y)+1)>>1;
}
}

/* Destroy a sprite grid widget: release the cell block it allocated and the
 * widget itself. */
void *DestroySpriteGrid(void *grid) {
    M2C_UNK MemFree(void *);
    HeapFreeBlock(M2C_FIELD(grid, s32 *, SPRITE_GRID_CELLS + SPRITE_CELL_LIST_CELLS));
    MemFree(grid);
    return grid;
}

void *func_020b3b6c(void *arg0) {
    M2C_UNK HeapFreeBlock(s32);
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x2C));
    return arg0;
}

/* Finishes a battle: stamps the battle record's date, stores the result in the
 * record unless that record type does it itself, marks the next maps of a
 * preset-player (campaign) map - the four map ids listed for it plus the map
 * itself - as available in the map list, and writes the save block. */
void FinishBattleAndSave(void) {
    M2C_UNK StartBattleRecord();
    s32 GetCurrentSaveType();
    s32 SaveTypeHasNoSlot(s32);
    M2C_UNK GetSaveSlot(M2C_UNK, s32);
    M2C_UNK SaveGameSettings();
    u16 GetMapFollowupMapId(u16, s32);
    s32 IsCampaignBattleRules();
    M2C_UNK StoreSaveSlotProgress();
    extern void **gCurrentMap;
    s32 recordType;
    s32 slot;
    u16 relatedMap;

    recordType = GetCurrentSaveType();
    if (recordType != 0) {
        StartBattleRecord();
        if (SaveTypeHasNoSlot(recordType) == 0) {
            GetSaveSlot(0, recordType);
            StoreSaveSlotProgress();
        }
    }
    if (IsCampaignBattleRules() != 0) {
        slot = 0;
        do {
            relatedMap = GetMapFollowupMapId(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), slot);
            if (relatedMap != 0) {
                SetMapListFlag(relatedMap, 1);
            }
            slot += 1;
        } while (slot < 4);
        SetMapListFlag(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), 1);
    }
    SaveGameSettings();
}

/* Spawn the battle-end sequence sprite (gBattleEndSequenceClass) as a child of
 * `parent`: it holds the map view, writes the save and releases the hold. */
void SpawnBattleEndSequence(M2C_UNK parent) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gBattleEndSequenceClass;
    CreateSpriteObject(&gBattleEndSequenceClass, parent);
}

void func_020b3c44(void) {

}

#pragma opt_strength_reduction off
void func_020b3c48(void *p) {
void LoadMapTileData(s32);void FreeMapTileData(void);void EncodeTerrainHitPoints(void *);
u8 *map,*src;void *dst; s32 n,x,y,i,j,unitStart,saveStart,off;u16 tile,old;
src=(u8 *)*gCurrentMap+0x52c2;
M2C_FIELD(p,s16*,0x18)=M2C_FIELD(src,s16*,0);
M2C_FIELD(p,s16*,0x1a)=M2C_FIELD(src,s16*,2);
M2C_FIELD(p,u16*,0x16)=M2C_FIELD(*gCurrentMap,u16*,0x52a2);
M2C_FIELD(p,u16*,0x14)=M2C_FIELD(*gCurrentMap,u16*,0x52a4);
M2C_FIELD(p,u8*,0x125b)=((u32)gOptionBits[3]<<22)>>29;
src=(u8 *)*gCurrentMap+0x5120;dst=(u8 *)p+0x2c;
M2C_FIELD(dst,Bytes33B3C*,0)=M2C_FIELD(src,Bytes33B3C*,0);
M2C_FIELD(dst,u8*,33)=M2C_FIELD(src,u8*,33);
M2C_FIELD(dst,u16*,34)=M2C_FIELD(src,u16*,34);
M2C_FIELD(dst,u16*,36)=M2C_FIELD(src,u16*,36);
M2C_FIELD(dst,u16*,38)=M2C_FIELD(src,u16*,38);
M2C_FIELD(dst,s16*,40)=M2C_FIELD(src,s16*,40);
M2C_FIELD(dst,s16*,42)=M2C_FIELD(src,s16*,42);
M2C_FIELD(dst,s16*,44)=M2C_FIELD(src,s16*,44);
M2C_FIELD(dst,s16*,46)=M2C_FIELD(src,s16*,46);
M2C_FIELD(dst,u16*,48)=M2C_FIELD(src,u16*,48);
M2C_FIELD(dst,u16*,50)=M2C_FIELD(src,u16*,50);
M2C_FIELD(dst,u8*,52)=M2C_FIELD(src,u8*,52);
M2C_FIELD(dst,u8*,53)=M2C_FIELD(src,u8*,53);
M2C_FIELD(dst,u8*,54)=M2C_FIELD(src,u8*,54);
M2C_FIELD(dst,u8*,55)=M2C_FIELD(src,u8*,55);
M2C_FIELD(dst,u8*,56)=M2C_FIELD(src,u8*,56);
M2C_FIELD(dst,u8*,57)=M2C_FIELD(src,u8*,57);
M2C_FIELD(dst,u8*,58)=M2C_FIELD(src,u8*,58);
M2C_FIELD(dst,u8*,59)=M2C_FIELD(src,u8*,59);
M2C_FIELD(dst,Bytes2B3C*,60)=M2C_FIELD(src,Bytes2B3C*,60);
M2C_FIELD(dst,Bytes2B3C*,62)=M2C_FIELD(src,Bytes2B3C*,62);
M2C_FIELD(dst,Bytes322B3C*,64)=M2C_FIELD(src,Bytes322B3C*,64);

src=gMapConfig;dst=(u8 *)p+0x1c;
M2C_FIELD(dst,u16*,0)=M2C_FIELD(src,u16*,0);
M2C_FIELD(dst,u8*,2)=M2C_FIELD(src,u8*,2);
M2C_FIELD(dst,u8*,3)=M2C_FIELD(src,u8*,3);
M2C_FIELD(dst,u16*,4)=M2C_FIELD(src,u16*,4);
M2C_FIELD(dst,u16*,6)=M2C_FIELD(src,u16*,6);
M2C_FIELD(dst,u32*,8)=M2C_FIELD(src,u32*,8);
M2C_FIELD(dst,u32*,12)=M2C_FIELD(src,u32*,12);

LoadMapTileData(M2C_FIELD(*gCurrentMap,u16*,0x5142));
n=0;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
map=*gCurrentMap;
i=x+M2C_FIELD(map+y*2,u16*,0x3758);
tile=M2C_FIELD(map+i*2,u16*,0xa10);
old=M2C_FIELD(gMapData+i*2,u16*,2);
if(tile!=old && (M2C_FIELD(map+old,u8*,0x6a60)&31)!=27){
M2C_FIELD((u8 *)p+n*4,u16*,0xf0a)=tile;
M2C_FIELD((u8 *)p+n*4,u8*,0xf08)=x;
M2C_FIELD((u8 *)p+n*4,u8*,0xf09)=y;n++;
}
}
}
if(n<99)M2C_FIELD((u8 *)p+n*4,u16*,0xf0a)=0xffff;
FreeMapTileData();
dst=p;
for(i=0;i<4;i++){
src=(u8 *)*gCurrentMap+0x67a4+(i+1)*140;
M2C_FIELD(dst,u32*,432)=M2C_FIELD(src,u32*,0);
M2C_FIELD(dst,u32*,436)=M2C_FIELD(src,u32*,4);
M2C_FIELD(dst,u32*,440)=M2C_FIELD(src,u32*,8);
M2C_FIELD(dst,u32*,444)=M2C_FIELD(src,u32*,12);
M2C_FIELD(dst,u8*,448)=M2C_FIELD(src,u8*,16);
M2C_FIELD(dst,u8*,449)=M2C_FIELD(src,u8*,17);
M2C_FIELD(dst,u8*,450)=M2C_FIELD(src,u8*,18);
M2C_FIELD(dst,u8*,451)=M2C_FIELD(src,u8*,19);
M2C_FIELD(dst,u8*,452)=M2C_FIELD(src,u8*,20);
M2C_FIELD(dst,u8*,453)=M2C_FIELD(src,u8*,21);
M2C_FIELD(dst,u8*,454)=M2C_FIELD(src,u8*,22);
M2C_FIELD(dst,u8*,455)=M2C_FIELD(src,u8*,23);
M2C_FIELD(dst,u8*,456)=M2C_FIELD(src,u8*,24);
M2C_FIELD(dst,u8*,457)=M2C_FIELD(src,u8*,25);
M2C_FIELD(dst,u16*,458)=M2C_FIELD(src,u16*,26);
M2C_FIELD(dst,u8*,460)=M2C_FIELD(src,u8*,28);
M2C_FIELD(dst,u8*,461)=M2C_FIELD(src,u8*,29);
M2C_FIELD(dst,u8*,462)=M2C_FIELD(src,u8*,30);
M2C_FIELD(dst,u8*,463)=M2C_FIELD(src,u8*,31);
M2C_FIELD(dst,u16*,464)=M2C_FIELD(src,u16*,32);
M2C_FIELD(dst,u16*,466)=M2C_FIELD(src,u16*,34);
M2C_FIELD(dst,s8*,468)=M2C_FIELD(src,s8*,36);
M2C_FIELD(dst,u8*,469)=M2C_FIELD(src,u8*,37);
M2C_FIELD(dst,u8*,470)=M2C_FIELD(src,u8*,38);
M2C_FIELD(dst,u8*,471)=M2C_FIELD(src,u8*,39);
M2C_FIELD(dst,u8*,472)=M2C_FIELD(src,u8*,40);
M2C_FIELD(dst,u8*,473)=M2C_FIELD(src,u8*,41);
M2C_FIELD(dst,u8*,474)=M2C_FIELD(src,u8*,42);
M2C_FIELD(dst,u8*,475)=M2C_FIELD(src,u8*,43);
M2C_FIELD(dst,u8*,476)=M2C_FIELD(src,u8*,44);
M2C_FIELD(dst,u8*,477)=M2C_FIELD(src,u8*,45);
M2C_FIELD(dst,u8*,478)=M2C_FIELD(src,u8*,46);
M2C_FIELD(dst,u8*,479)=M2C_FIELD(src,u8*,47);
M2C_FIELD(dst,u8*,480)=M2C_FIELD(src,u8*,48);
M2C_FIELD(dst,u8*,481)=M2C_FIELD(src,u8*,49);
M2C_FIELD(dst,u8*,482)=M2C_FIELD(src,u8*,50);
M2C_FIELD(dst,Bytes27B3C*,483)=M2C_FIELD(src,Bytes27B3C*,51);
M2C_FIELD(dst,Bytes27B3C*,510)=M2C_FIELD(src,Bytes27B3C*,78);
{u32 a=M2C_FIELD(src,u32*,108),b=M2C_FIELD(src,u32*,112);M2C_FIELD(dst,u32*,540)=a;M2C_FIELD(dst,u32*,544)=b;}
M2C_FIELD(dst,Words4B3C*,548)=M2C_FIELD(src,Words4B3C*,116);
M2C_FIELD(dst,u32*,564)=M2C_FIELD(src,u32*,132);
M2C_FIELD(dst,u32*,568)=M2C_FIELD(src,u32*,136);
dst+=140;

}
saveStart=unitStart=0;
for(i=0;i<4;i++){
dst=(u8 *)p+saveStart*14;
for(j=0;j<51;j++){
src=(u8 *)*gCurrentMap+0x59a4+(j+unitStart)*14;
M2C_FIELD(dst,u8*,992)=M2C_FIELD(src,u8*,0);
M2C_FIELD(dst,u8*,993)=M2C_FIELD(src,u8*,1);
M2C_FIELD(dst,u8*,994)=M2C_FIELD(src,u8*,2);
M2C_FIELD(dst,u16*,996)=M2C_FIELD(src,u16*,4);
M2C_FIELD(dst,u16*,998)=M2C_FIELD(src,u16*,6);
M2C_FIELD(dst,u16*,1000)=M2C_FIELD(src,u16*,8);
M2C_FIELD(dst,u8*,1002)=M2C_FIELD(src,u8*,10);
M2C_FIELD(dst,u8*,1003)=M2C_FIELD(src,u8*,11);
M2C_FIELD(dst,Bytes2B3C*,1004)=M2C_FIELD(src,Bytes2B3C*,12);
dst+=14;
}
unitStart+=64;saveStart+=51;
}
i=0;
for(off=0;i<32;i++){
src=(u8 *)*gCurrentMap+0x58a4+off;dst=(u8 *)p+i*8;
M2C_FIELD(dst,u8*,4244)=M2C_FIELD(src,u8*,0);
M2C_FIELD(dst,u8*,4245)=M2C_FIELD(src,u8*,1);
M2C_FIELD(dst,u16*,4246)=M2C_FIELD(src,u16*,2);
M2C_FIELD(dst,u8*,4248)=M2C_FIELD(src,u8*,4);
M2C_FIELD(dst,u8*,4249)=M2C_FIELD(src,u8*,5);
M2C_FIELD(dst,s8*,4250)=M2C_FIELD(src,s8*,6);
M2C_FIELD(dst,s8*,4251)=M2C_FIELD(src,s8*,7);
off+=8;
}
EncodeTerrainHitPoints((u8 *)p+0x1194);
}
