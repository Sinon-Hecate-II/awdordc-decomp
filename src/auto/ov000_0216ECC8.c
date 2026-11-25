/* 12 functions from 0x0216ECC8 to 0x0216FC60 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_unit_entry.h"
#include "sound.h"
typedef struct {u16 hp:7;u16 ammo:4;u16 flags:5;} DisplayHealth;
typedef struct {u8 fuel:7;u8 flag:1;} DisplayFuel;
extern void **gCurrentMap;
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern s32 gUnitListRows;
extern u32 gUnitKindStats[];
extern u8 gUnitKindMaxFuel[],gUnitKindMaxAmmo[],gUnitKindInfiniteAmmo[];
int func_020a8b9c(void);int func_020a8b90(void);int func_020a8bb4(void);int func_020a8ba8(void);int func_020a8b78(void);int func_020a8b84(void);
void DrawTilemapNumber(s16,s16,void *,int,int,int);
void DrawTextToTilemap(s16,s16,void *,int,int,int);
void WriteUnitKindTileQuad(void *,u16,u16,int,u16,u8,u8);
void DrawLocalizedTextLine(s16,s16,int,u32,int,int,u16);
int Divide(int,int);int GetLocalizedText(u32);int MeasureStringWidth(int);
void DrawLocalizedTextToTilemap(s16,s16,void *,u32,int,int);

/* Switch gCur3DSpriteEngine to g3DSpriteEngineMain and rebuild its display lists; bit 0 of mode selects one of two layouts. */
void ScrollListRebuild(s32 mode,s32 reverse){
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern s8 data_ov000_021aab79[];
extern M2C_UNK gUnitListRows;
extern u32 gUnitKindStats[];
void *HeapAllocBlock(s32);void HeapFreeBlock(void *);
void MI_CpuCopy8(void *,void *,s32);s32 Divide(s32,s32);
s32 n=0,i,j,k,l,out,t,v,h,idx,z;
u8 *tmp=HeapAllocBlock(64),*p,*q,*map,*attr;
s8 *order=data_ov000_021aab79;
for(t=1;t<27;t++,order++){
for(i=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51;i++){
map=*gCurrentMap;p=map+0x59a4+i*14;
v=(u32)(p[0]<<26)>>26;
if(v && v==*order)((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[n++]=i-M2C_FIELD(map,u16 *,0x52a8);
}}
((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[n]=0;
out=0;
switch(mode){
case 0:MI_CpuCopy8(M2C_FIELD(&gUnitListRows,u8 **,4),tmp,64);break;
case 1:
for(h=10;h>0;h--)for(i=0;i<n;i++){
map=*gCurrentMap;idx=((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[i]+M2C_FIELD(map,u16 *,0x52a8);
v=(u32)(M2C_FIELD(map+idx*14,u16 *,0x59aa)<<25)>>25;
if(v==0)v=0;else v=Divide(v-1,10)+1;
if(h==v)tmp[out++]=((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[i];
}break;
case 2:
for(h=99;h>=0;h--)for(i=0;i<n;i++){
map=*gCurrentMap;z=((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[i];idx=M2C_FIELD(map,u16 *,0x52a8)+z;
if(h==((u32)(map[0x59ae + idx*14]<<25)>>25))tmp[out++]=z;
}break;
case 3:
for(h=10;h>=-1;h--)for(i=0;i<n;i++){
map=*gCurrentMap;z=((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[i];idx=M2C_FIELD(map,u16 *,0x52a8)+z;p=map+0x59a4+idx*14;
attr=(u8 *)gUnitKindStats+((u32)(p[0]<<26)>>26)*112;
if(attr[9])v=(u32)(M2C_FIELD(p,u16 *,6)<<21)>>28;
else {v=-1;if(attr[15])v=10;}
if(v==h)tmp[out++]=z;
}break;
}
if(reverse){
for(i=0;i<n;i++)((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[i]=tmp[n-1-i];
MI_CpuCopy8(M2C_FIELD(&gUnitListRows,u8 **,4),tmp,64);
}
out=0;
for(i=0;i<n;i++){
z=tmp[i];
if(z){
map=*gCurrentMap;p=map+0x59a4+(M2C_FIELD(map,u16 *,0x52a8)+z)*14;
if(!(M2C_FIELD(p,u16 *,4)&8)){
((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[out++]=z;tmp[i]=0;
if(M2C_FIELD(p,u16 *,4)&16){
for(j=0;j<2;j++){
z=p[12+j];
if(z){
map=*gCurrentMap;idx=z-M2C_FIELD(map,u16 *,0x52a8);
for(k=0;k<n;k++){
if(idx==tmp[k]){
z=M2C_FIELD(map,u16 *,0x52a8)+idx;q=map+0x59a4+z*14;
((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[out++]=tmp[k];tmp[k]=0;
if(M2C_FIELD(q,u16 *,4)&16){
for(l=0;l<2;l++){
z=q[12+l];
if(z){
idx=z-M2C_FIELD(*gCurrentMap,u16 *,0x52a8);
for(v=0;v<n;v++){
if(idx==tmp[v]){((u8 *)M2C_FIELD(&gUnitListRows,u8 **,4))[out++]=tmp[v];tmp[v]=0;break;}
}
}
}}
break;
}
}
}
}
}
}
}
}
HeapFreeBlock(tmp);
}

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_0216f1b4(s32 arg0) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
register s32 offset;
u8 *base,*arr;
s32 limit,j;
register u8 *c2;
s32 i;
u8 *cell;
base=*gCurrentMap;
arr=base+0x59a4;
offset=*(u16 *)(base+0x52a8);
if (!(*(u16 *)(arr+(offset+arg0)*14+4)&8)) return 0;
i=gPlayerUnitIdBase[*(u16 *)(base+0x52a4)]+1;
if(i >= gPlayerUnitIdBase[*(u16 *)((u8 *)*gCurrentMap+0x52a4)]+0x33) goto done;
cell=arr+i*14;
do {
if (((u32)(cell[0]<<26)>>26)==0) goto next;
base=*gCurrentMap;
offset=*(u16 *)(base+0x52a8);
if(arg0==cell[12]-offset){
if(cell[13]==0) goto second;
if(!(*(u16 *)(cell+4)&8)) return 1;
arg0=i-offset;
limit=gPlayerUnitIdBase[*(u16 *)(base+0x52a4)];
j=limit+1;
if(j<limit+0x33){
c2=base+0x59a4+j*14;
do {

if(((u32)(c2[0]<<26)>>26)!=0){
if(arg0==c2[13]-offset)return 5;
if(arg0==c2[12]-offset)return c2[13]==0?5:3;
}
j++;c2+=14;
}while(j<limit+0x33);
}
}else if(arg0==cell[13]-offset){
if(!(*(u16 *)(cell+4)&8))return 2;
second:
arg0=i-offset;
limit=gPlayerUnitIdBase[*(u16 *)(base+0x52a4)];
j=limit+1;
if(j<limit+0x33){
c2=base+0x59a4+j*14;
do {

if(((u32)(c2[0]<<26)>>26)!=0){
if(arg0==c2[13]-offset)return 6;
if(arg0==c2[12]-offset)return c2[13]==0?6:4;
}
j++;c2+=14;
}while(j<limit+0x33);
}
}
next:
i++;cell+=14;
}while(i<gPlayerUnitIdBase[*(u16 *)((u8 *)*gCurrentMap+0x52a4)]+0x33);
done:
return 0;
}
#pragma pop
void func_ov000_0216f3d0(s32 row,s32 index){
 UnkStruct_ov000_021A860C *u;
 void *saved;
 int base;
 int shift;
 u8 *m;
 int id,offset,icon,health;
 gUnitListRows=0x1c4+(row+1)*24;
 id=((u8 *)((u32 *)&gUnitListRows)[1])[index];if(id==0)return;
 saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
 m=*gCurrentMap;base=*(u16 *)(m+0x52a8);
 u=(void *)(m+0x59a4+(base+id)*14);
 if(*(u16 *)((u8 *)u+4)&8)base=256;
 else if(*(u16 *)((u8 *)u+4)&1)base=256;
 shift=0;
 switch(func_ov000_0216f1b4(id)){
 case 1:icon=func_020a8b9c();offset=1;break;
 case 2:icon=func_020a8b90();offset=1;break;
 case 3:icon=func_020a8bb4();offset=2;break;
 case 4:icon=func_020a8ba8();offset=2;break;
 case 5:icon=func_020a8b9c();offset=2;shift=1;break;
 case 6:icon=func_020a8b90();offset=2;shift=1;break;
 default:icon=0;offset=0;break;
 }
 DrawTilemapNumber(3,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),index+1,0,0);
 if(icon)DrawTextToTilemap((s16)(shift+5),(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),icon,0,0);
 WriteUnitKindTileQuad(M2C_FIELD(gCur3DSpriteEngine,void **,0x24),(u16)(offset+5),(u16)(row+5),u->unk0,(u16)base,u->unkC[0],(u8)((DisplayHealth *)((u8 *)u+6))->flags);
 DrawLocalizedTextLine(9,(s16)(row+5),1,*(u32 *)((u8 *)gUnitKindStats+u->unk0*112),0,0,(u16)gUnitListRows);
 health=u->unk6;if(health==0)health=0;else health=Divide(health-1,10)+1;
 DrawTilemapNumber(18,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),health,0,0);
 DrawTilemapNumber(21,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),((DisplayFuel *)((u8 *)u+10))->fuel,0,0);
 DrawTextToTilemap(22,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b78(),0,0);
 DrawTilemapNumber(24,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),gUnitKindMaxFuel[u->unk0*112],0,0);
 if(!gUnitKindMaxAmmo[u->unk0*112]){
 if(gUnitKindInfiniteAmmo[u->unk0*112])DrawTextToTilemap(27,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b84(),0,0);
 else DrawLocalizedTextToTilemap((s16)(28-(MeasureStringWidth(GetLocalizedText(0xc000007f))>>4)),(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),0xc000007f,0,0);
 }else{
 DrawTilemapNumber(27,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),((DisplayHealth *)((u8 *)u+6))->ammo,0,0);
 DrawTextToTilemap(28,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b78(),0,0);
 DrawTilemapNumber(29,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),gUnitKindMaxAmmo[u->unk0*112],0,0);
 }
 gCur3DSpriteEngine=saved;
}
void ScrollListDrawRows(s32 mode) {
    M2C_UNK ClearTileRect(s32, M2C_UNK, M2C_UNK);
    void func_ov000_0216f3d0(s32, s32);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;
    s32 var_r7_2;
    void *savedPtr;

    savedPtr = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    ClearTileRect(M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x24) + 0x140, 0x20, 0xC);
    if (mode & 1) {
        var_r6 = 0;
        var_r5 = mode >> 1;
        var_r7 = -1;
        do {
            func_ov000_0216f3d0(var_r7, var_r5);
            var_r6 += 1;
            var_r5 += 1;
            var_r7 += 2;
        } while (var_r6 < 7);
        ClearTileRect(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x100, 0x20, 1);
        ClearTileRect(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x440, 0x20, 1);
    } else {
        var_r7_2 = 0;
        var_r6_2 = 0;
        var_r5_2 = mode >> 1;
        do {
            func_ov000_0216f3d0(var_r6_2, var_r5_2);
            var_r7_2 += 1;
            var_r5_2 += 1;
            var_r6_2 += 2;
        } while (var_r7_2 < 6);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    gCur3DSpriteEngine = savedPtr;
}

/* Load the sprite sheet of the unit list's selected sort tab: open the
 * unitlist.narc archive under /info/unitlist, load that tab's .sc screen data
 * into the main 3D sprite engine and mark its graphics dirty. */
void ScrollListDrawTabs(ScrollList *list) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern M2C_UNK sUnitListDir, sUnitListNarcFile, sUnitListUnitScFile, sUnitListHpScFile, sUnitListFuelScFile, sUnitListBulletScFile;
    s32 GetLocalizedFileName(void *);
    void LoadNarcFileDecompressed(s32, s32);
    void AddTileRectPalette(s32, s32, s32, s32);
    void *saved = gCur3DSpriteEngine;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    SetFileDirectory(&sUnitListDir);
    GetLocalizedFileName(&sUnitListNarcFile);
    OpenNarcArchive();
    switch (list->tab) {
    case 0: LoadNarcFileDecompressed(GetLocalizedFileName(&sUnitListUnitScFile), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28)); break;
    case 1: LoadNarcFileDecompressed(GetLocalizedFileName(&sUnitListHpScFile), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28)); break;
    case 2: LoadNarcFileDecompressed(GetLocalizedFileName(&sUnitListFuelScFile), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28)); break;
    case 3: LoadNarcFileDecompressed(GetLocalizedFileName(&sUnitListBulletScFile), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28)); break;
    }
    CloseNarcArchive();
    AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 32, 24, 6);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    gCur3DSpriteEngine = saved;
}

/* Scroll the unit list up one row, unless it is already showing the first row;
 * the move plays the menu-selection sound. */
s32 ScrollListScrollUp(void *arg0) {
    ScrollList *list = arg0;
    s16 scrollPos;

    scrollPos = list->scrollPos;
    if (scrollPos == 0) {
        return 0;
    }
    list->scrollPos = (s16) (scrollPos - 1);
    PlaySoundEffect(SOUND_MENU_SELECT);
    return 1;
}

/* Page the unit list up one screenful, stopping at the first row; returns how
 * many rows it moved (negative). */
s16 ScrollListPageUp(ScrollList *list) {
    s16 old = list->scrollPos;
    list->scrollPos = old - SCROLL_LIST_VISIBLE_ROWS;
    if (list->scrollPos < 0) list->scrollPos = 0;
    return list->scrollPos - old;
}

/* Scroll the unit list down one row, unless the last row is already on screen;
 * the move plays the selection sound. */
s32 ScrollListScrollDown(ScrollList *list) {
    s16 scrollPos = list->scrollPos;
    s32 next = scrollPos + SCROLL_LIST_VISIBLE_ROWS;

    if (next >= list->count) {
        return 0;
    }
    list->scrollPos++;
    PlaySoundEffect(SOUND_MENU_SELECT);
    return 1;
}

/* Page the unit list down one screenful, stopping at the last page; returns how
 * many rows it moved. */
s16 ScrollListPageDown(ScrollList *list) {
    s16 old = list->scrollPos;
    s32 max;

    list->scrollPos = old + SCROLL_LIST_VISIBLE_ROWS;
    max = list->count - SCROLL_LIST_VISIBLE_ROWS;
    if (list->scrollPos > max) list->scrollPos = (s16)max;
    return list->scrollPos - old;
}

/* Step the map view to the tile of the unit the list's info panel shows (nothing
 * to do while no unit is selected). */
void ScrollListStepToSelectedUnit(ScrollList *list) {
    M2C_UNK StepMapViewToTile(u8, u8);
    extern void **gCurrentMap;
    s16 selectedId;
    s32 record;
    void *map;

    selectedId = list->selectedId;
    if (selectedId == 0) {
        return;
    }
    map = *gCurrentMap;
    record = ((M2C_FIELD(map, u16 *, MAP_UNIT_GROUP_BASE) + selectedId) * MAP_UNIT_STRIDE) + (s32) (map + MAP_UNIT_RECORDS);
    StepMapViewToTile(M2C_FIELD(record, u8 *, MAP_UNIT_X), M2C_FIELD(record, u8 *, MAP_UNIT_Y));
}

/* Confirm the unit list's highlighted row: store the unit id of that row's slot as
 * the list's info-panel selection, play the confirm sound and resume the list. */
void ScrollListConfirm(u8 *selectedRow) {
    extern M2C_UNK gUnitListRows;
    ScrollList *list;

    list = (ScrollList *)GetScrollList();
    list->selectedId = M2C_FIELD(&gUnitListRows, u8 **, UNIT_LIST_ROWS_PTR)[list->scrollPos + *selectedRow];
    PlaySoundEffect(0x10016);
    Sprite_ResumeAnimation(list);
    HideEnabledSpriteSlots();
    CloseAllActiveSpriteSlots();
}

/* Cancel out of the unit list: play the back sound, resume the list's sprite
 * animation and hide the sprite slots the list had enabled. */
void ScrollListCancel(void) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK HideEnabledSpriteSlots();
    M2C_UNK CloseAllActiveSpriteSlots();
    ScrollList *list;

    list = (ScrollList *)GetScrollList();
    PlaySoundEffect(SOUND_MENU_BACK);
    Sprite_ResumeAnimation(list);
    HideEnabledSpriteSlots();
    CloseAllActiveSpriteSlots();
}
