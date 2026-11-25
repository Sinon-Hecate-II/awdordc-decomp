/* 12 functions from 0x022141CC to 0x02215168 (ov005), found by ds-decomp. */
#include "common.h"
#include "sound.h"
static inline void *SwitchEngine1425c(void *p){extern void *gCur3DSpriteEngine;void *old=gCur3DSpriteEngine;gCur3DSpriteEngine=p;return old;}
static inline s32 Mul1425c(s32 a,s32 b){return ((s64)a*b+2048)>>12;}
typedef struct {s16 vals[8];} ShakeList1425c;
typedef struct {u16 pad:13,shift:2,last:1;} Mode1425c;
extern void *g3DSpriteEngineSub;
extern u8 data_02101f0c[],gSpriteDesc8x8[],data_ov005_02220486[];
extern s16 data_ov005_02220048[8],data_ov005_02220484,gSinCosTable[];
#define RECORDS_SCREEN ((RecordsScreen *)M2C_FIELD(&gRecordsMenuState, void **, 8))

/* Move the records list's top visible row down one, stopping when only the last
 * full page (six rows) would remain; plays the select sound when it moves. */
s32 RecordsMenu_ScrollDown(void) {
    extern M2C_UNK gRecordsMenuState;
    s16 scroll = RECORDS_SCREEN->scroll;
    s32 next = scroll + 6;
    if (next >= RECORDS_SCREEN->count) return 0;
    RECORDS_SCREEN->scroll++;
    PlaySoundEffect(SOUND_MENU_SELECT);
    return 1;
}

/* Page the records list down by one screen: move its top visible row down six,
 * stop at the last full page, and return how many rows it actually moved. */
s16 RecordsMenu_PageDown(void) {
    extern M2C_UNK gRecordsMenuState;
    s16 oldScroll;
    s32 maxScroll;

    oldScroll = RECORDS_SCREEN->scroll;
    RECORDS_SCREEN->scroll = (s16) (oldScroll + 6);
    maxScroll = RECORDS_SCREEN->count - 6;
    if ((s32) RECORDS_SCREEN->scroll > maxScroll) {
        RECORDS_SCREEN->scroll = (s16) maxScroll;
    }
    return (s16) (RECORDS_SCREEN->scroll - oldScroll);
}

void func_ov005_0221425c(void){
s32 FX_Div(s32,s32);void DrawFrameBorder(s16,s16,s16,s16,u16,s32,s32);void AddSprite(s32,u16,u16,void *,s32);
s32 EaseInterpolate(s32,s32,s32,s16,s32);s32 Divide(s32,s32);void SetSpriteQuad(s32,s16,s16,s16,s16);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern M2C_UNK gRecordsMenuState;
s32 h,fy,fx;void *saved=gCur3DSpriteEngine;void *engine=g3DSpriteEngineMain;u8 *p; s32 a,b,c,d,x,y,t,u,v,w,n,z; ShakeList1425c list;
p=M2C_FIELD(&gRecordsMenuState,u8 **,8);
gCur3DSpriteEngine=engine;
if(M2C_FIELD(p,u16 *,0)&1){
fy=M2C_FIELD(p,s16 *,0x9a)<<12;fx=M2C_FIELD(p,s16 *,0x98)<<12;
h=(s64)(FX_Div(0x60000,fy)) * 0x6000LL +0x800 >>12;
z=Mul1425c(FX_Div(0x60000-h,fy-0x6000),fx);
a=h>>12;if(a>96)a=96;else if(a<1)a=1;
DrawFrameBorder(248,(z>>12)+25,2,a,(u16)(((0x140>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),0,2);
}
gCur3DSpriteEngine=g3DSpriteEngineSub;
AddSprite(120,176,(u16)(((0x140>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),data_02101f0c,0);
AddSprite(184,176,(u16)(((0x148>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),data_02101f0c,0);
AddSprite(248,176,(u16)(((0x150>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),gSpriteDesc8x8,0);
AddSprite(120,184,(u16)(((0x151>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),data_02101f0c,0);
AddSprite(184,184,(u16)(((0x159>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),data_02101f0c,0);
AddSprite(248,184,(u16)(((0x161>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),gSpriteDesc8x8,0);
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=-1){
list=*(ShakeList1425c *)data_ov005_02220048;
if(M2C_FIELD(&gRecordsMenuState,s16 *,0)==0){
M2C_FIELD(&gRecordsMenuState,s16 *,0)=6;
M2C_FIELD(&gRecordsMenuState,s16 *,6)=data_ov005_02220484;
{s32 index=M2C_FIELD(&gRecordsMenuState,s16 *,4);M2C_FIELD(&gRecordsMenuState,s16 *,2)=list.vals[index];M2C_FIELD(&gRecordsMenuState,s16 *,4)=index+1;}
if(M2C_FIELD(&gRecordsMenuState,s16 *,4)>=8)M2C_FIELD(&gRecordsMenuState,s16 *,4)=0;
}
M2C_FIELD(&gRecordsMenuState,s16 *,0)--;
data_ov005_02220484=EaseInterpolate(0,M2C_FIELD(&gRecordsMenuState,s16 *,2),M2C_FIELD(&gRecordsMenuState,s16 *,6),M2C_FIELD(&gRecordsMenuState,s16 *,0),6);
n=data_ov005_02220484;
a=((n<0?-n:n)>=2?n:n>2?2:n<-2?-2:n);y=gSinCosTable[1];b=((n<0?-n:n)>=2?n:n>2?2:n<-2?-2:n);x=gSinCosTable[0];c=((n<0?-n:n)>=2?n:n>2?2:n<-2?-2:n);d=((n<0?-n:n)>=2?n:n>2?2:n<-2?-2:n);
t=Divide(y<<4,d);u=Divide((-x)<<4,c);v=Divide(x<<4,b);w=Divide(y<<4,a);SetSpriteQuad(0,t,u,v,w);
AddSprite(204,0,(u16)(((0x162>>((*(Mode1425c **)gCur3DSpriteEngine)->shift))&1023)|0x6000),data_ov005_02220486,0);
}
gCur3DSpriteEngine=saved;
}

/* Draw one row of the records list: the row number, its colour bar (greyed out
 * when the record is locked and highlighted when it is the cursor's record) and
 * the 2x2 icon that marks a completed record. */
void RecordsMenu_DrawRow(s32 row,s32 record) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain; extern M2C_UNK gRecordsMenuState;
s32 RecordsMenu_IsRecordAvailable(s32); void *RecordsMenu_GetRecord(s32);
void DrawTilemapNumber(s32,s16,void *,s32,s32,s32);
void DrawLocalizedTextLine(s32,s16,s32,u32,s32,s32,u16);
void FillTileRect(void *,s32,s32,u16,s32);
s32 mode; u32 color; s32 barTile; void *saved; u16 iconTile;
barTile=(row+1)*50+0x134;saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
if(RecordsMenu_IsRecordAvailable(record)) {
color=M2C_FIELD(RecordsMenu_GetRecord(record),u32 *,4);
if(RECORDS_SCREEN->highlighted==record)mode=9;else mode=0;
} else {color=0x43000000; mode=3;}
DrawTilemapNumber(3,(s16)(row+3),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),record+1,0x2000,mode);
DrawLocalizedTextLine(5,(s16)(row+3),1,color,0x2000,mode,(u16)barTile);
iconTile=RECORDS_SCREEN->enabled[record]?0x124:0x128;
FillTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x38+(row+3)*64,2,2,iconTile,0);
gCur3DSpriteEngine=saved;
}

/* Redraw the records screen's list: clear the 32x12 cell area, draw the visible
 * rows (seven when the scroll position is half a row off, six otherwise), then
 * redraw the selectable and total counters at the bottom. */
void RecordsMenu_DrawList(s32 scroll) {
void ClearTileRect(void *,s32,s32);void DrawTilemapNumber(s32,s16,void *,s32,s32,s32);void DrawTextToTilemap(s32,s16,void *,s32,s32,s32);s32 func_020a8b78(void);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern M2C_UNK gRecordsMenuState;
s32 drawn,recordEven,recordOdd,rowEven,rowOdd,drawnEven;void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
ClearTileRect((u8 *)M2C_FIELD(g3DSpriteEngineMain,void **,0x24)+0xc0,0x20,12);
if(scroll&1){
drawn=0;recordOdd=scroll>>1;rowOdd=-1;
do{RecordsMenu_DrawRow(rowOdd,recordOdd);drawn++;recordOdd++;rowOdd+=2;}while(drawn<7);
ClearTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x80,32,1);
ClearTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x3c0,32,1);
}else{
drawnEven=0;rowEven=0;recordEven=scroll>>1;
do{RecordsMenu_DrawRow(rowEven,recordEven);drawnEven++;recordEven++;rowEven+=2;}while(drawnEven<6);
}
DrawTilemapNumber(27,1,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),((RecordsScreen *)M2C_FIELD(&gRecordsMenuState,void **,8))->selectable,0x2000,0);
DrawTextToTilemap(28,1,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b78(),0x2000,0);
DrawTilemapNumber(30,1,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),((RecordsScreen *)M2C_FIELD(&gRecordsMenuState,void **,8))->count,0x2000,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved;
}

/* Advance the records screen's fade list cursor and start the main and/or sub screen
 * fade when the record it moves to has a different background id than the previous
 * one.  Does nothing while a fade or a menu action is running. */
void RecordsMenu_AdvanceFadeRecord(s32 enabled) {
    extern M2C_UNK gRecordsMenuState;
    extern s16 gRecordMainBgId[], gRecordSubBgId[];
    RecordsScreen *screen;
    s32 previous, current;
    s16 *list;

    if (!enabled) return;
    screen = M2C_FIELD(&gRecordsMenuState, RecordsScreen **, 8);
    if (screen->fadeTop != 0 || screen->fadeBottom != 0) return;
    if (screen->fadeCount <= 0) return;
    previous = screen->fadeCursor;
    list = screen->fadeList;
    screen->fadeCursor = previous + 1;
    screen = M2C_FIELD(&gRecordsMenuState, RecordsScreen **, 8);
    if (screen->fadeCursor >= screen->fadeCount) screen->fadeCursor = 0;
    screen = M2C_FIELD(&gRecordsMenuState, RecordsScreen **, 8);
    current = screen->fadeCursor;
    if (previous == -1) {
        if (gRecordMainBgId[list[current] * 2] != -1) screen->fadeTop = 16;
    } else if (gRecordMainBgId[list[previous] * 2] != gRecordMainBgId[list[current] * 2]) {
        screen->fadeTop = 16;
    }
    if (gRecordSubBgId[list[previous] * 2] != gRecordSubBgId[list[current] * 2])
        ((RecordsScreen *)M2C_FIELD(&gRecordsMenuState, RecordsScreen **, 8))->fadeBottom = 16;
}

void func_ov005_02214b98(void) {
extern void *gCur3DSpriteEngine,*data_027e00c8;
extern M2C_UNK data_ov005_02221304,data_ov005_02220658,data_ov005_02220670,data_ov005_02220688,data_ov005_022206a0,data_ov005_022206b8;
extern s16 data_ov005_02220572[];
void func_020814e4(void *);void func_02081590(void *,s32);void func_020816a4(void *,s32,s32,s32);void func_0208161c(void *,s32,s32,s32);
void func_02081528(void);void func_0200bc5c(void *);void func_ov005_022140e4(void);
void *func_020ad460(s32);void *BuildMapBackgroundCgName(s32);void *BuildMapBackgroundScName(s32);void *BuildMapBackgroundClName(s32);
void *saved=(unsigned short)gCur3DSpriteEngine; void *engine=*(void *volatile *)&data_027e00c8; void *p=M2C_FIELD(&data_ov005_02221304,void **,8);s32 id;
gCur3DSpriteEngine=engine;
if(M2C_FIELD(p,s16 *,2)==-1 || (id=data_ov005_02220572[M2C_FIELD((u8 *)p+M2C_FIELD(p,s16 *,2)*2,s16 *,6)*2])==-1) {
func_020814e4(&data_ov005_02220658);
func_02081590(&data_ov005_02220670,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x18));
func_020816a4(&data_ov005_02220688,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c),0,0);
func_0208161c(&data_ov005_022206a0,3,0,0x200);func_02081528();
} else {
func_0200bc5c(&data_ov005_022206b8);
func_020814e4(func_020ad460(id));
func_02081590(BuildMapBackgroundCgName(id),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x18));
func_02081590(BuildMapBackgroundScName(id),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c));
func_0208161c(BuildMapBackgroundClName(id),3,0,0x200);func_02081528();
func_ov005_022140e4();
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
gCur3DSpriteEngine=saved;
}

#pragma schedule off
void func_ov005_02214cdc(void) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern M2C_UNK gRecordsMenuState, data_ov005_022206c0, data_ov005_022206d8, data_ov005_022206ec, data_ov005_02220700, data_ov005_02220714;
    extern s16 gRecordSubBgId[];
    void OpenNarcArchive(void *);
    void LoadNarcFileDecompressed(void *, s32);
    void func_020816a4(void *, s32, s32, s32);
    void func_0208161c(void *, s32, s32, s32);
    void SetFileDirectory(void *);
    void *BuildMapBackgroundNarcName(s32);
    void *BuildMapBackgroundCgName(s32);
    void *BuildMapBackgroundScName(s32);
    void *BuildMapBackgroundClName(s32);
    void *saved = gCur3DSpriteEngine;
    void *engine = *(void *volatile *)&g3DSpriteEngineSub;
    void *p;
    s16 selected;
    s32 none;
    p = M2C_FIELD(&gRecordsMenuState, void **, 8);
    *(void *volatile *)&gCur3DSpriteEngine = engine;
    selected = M2C_FIELD(p, s16 *, 2);
    none = -1;
    if ((u16)selected == (u16)none) {
        OpenNarcArchive(&data_ov005_022206c0);
        LoadNarcFileDecompressed(&data_ov005_022206d8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
        func_020816a4(&data_ov005_022206ec, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0, 0);
        func_0208161c(&data_ov005_02220700, 3, 0, 512);
        CloseNarcArchive();
    } else {
        s32 id = gRecordSubBgId[M2C_FIELD(p + selected * 2, s16 *, 6) * 2];
        SetFileDirectory(&data_ov005_02220714);
        OpenNarcArchive(BuildMapBackgroundNarcName(id));
        LoadNarcFileDecompressed(BuildMapBackgroundCgName(id), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
        LoadNarcFileDecompressed(BuildMapBackgroundScName(id), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
        func_0208161c(BuildMapBackgroundClName(id), 3, 0, 512);
        CloseNarcArchive();
        func_ov005_022140e4();
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
    gCur3DSpriteEngine = saved;
}
#pragma schedule on
/* Rebuilds the records screen's shuffled list of available records: collects the
   indices of every available, enabled record, shuffles them, and, when firstRecord
   is not -1, moves that record to the front; then resets the list cursor. */
void RecordsMenu_ShuffleList(s32 firstRecord) {
extern M2C_UNK gRecordsMenuState;
s32 RecordsMenu_IsRecordAvailable(s32); s32 RandomIntRange(s32,s32);
s32 i; s16 slotA,slotB,tmp;
RECORDS_SCREEN->listCount=0;
for(i=0;i<RECORDS_SCREEN->count;i++){
if(RecordsMenu_IsRecordAvailable(i)&&RECORDS_SCREEN->enabled[i]==1){
RECORDS_SCREEN->list[RECORDS_SCREEN->listCount]=i;
RECORDS_SCREEN->listCount++;
}}
for(i=0;i<RECORDS_SCREEN->listCount*2;i++){
slotA=RandomIntRange(0,RECORDS_SCREEN->listCount-1);
slotB=RandomIntRange(0,RECORDS_SCREEN->listCount-1);
tmp=RECORDS_SCREEN->list[slotA];
RECORDS_SCREEN->list[slotA]=RECORDS_SCREEN->list[slotB];
RECORDS_SCREEN->list[slotB]=tmp;
}
if(firstRecord!=-1)for(i=0;i<RECORDS_SCREEN->listCount;i++){
s16 v=RECORDS_SCREEN->list[i];
if(firstRecord==v){void *p=M2C_FIELD(&gRecordsMenuState,void *volatile *,8);tmp=M2C_FIELD(p,s16 *,0xe6);M2C_FIELD(p,s16 *,0xe6)=v;RECORDS_SCREEN->list[i]=tmp;}
}
RECORDS_SCREEN->listCursor=0;
}

/* Select records-list entry `record`: play its track, mark it highlighted and arm
 * the pending action's delay (tab 0 has none), then redraw the list. */
void RecordsMenu_SelectRecord(s32 record) {
void *RecordsMenu_GetRecord(s32);
extern M2C_UNK gRecordsMenuState;
StartMusicTrack(((RecordTrack *)RecordsMenu_GetRecord(record))->trackId);
RECORDS_SCREEN->highlighted=record;
if(RECORDS_SCREEN->tab==0)
RECORDS_SCREEN->actionTimer=-1;
else RECORDS_SCREEN->actionTimer=((RecordTrack *)RecordsMenu_GetRecord(record))->length+RECORDS_ACTION_DELAY;
RecordsMenu_DrawList(RECORDS_SCREEN->scrollGoal);
}

/* Records tab 2 (the sorted list): picking a record selects it, or, when it is the
 * selected one already, toggles it off.  Tabs 0 and 1 only select it.  Selecting
 * reshuffles the enabled-record list so the record comes first, and then starts the
 * pending action on it. */
void RecordsMenu_HandlePick(s32 record) {
s32 RecordsMenu_IsRecordAvailable(s32);
void RecordsMenu_BeginAction(s32,s32);
extern M2C_UNK gRecordsMenuState;
switch(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)) {
case 0: case 1:
if(RecordsMenu_IsRecordAvailable(record))RecordsMenu_BeginAction(record,1);
break;
case 2:
if(RecordsMenu_IsRecordAvailable(record)&&M2C_FIELD((char *)M2C_FIELD(&gRecordsMenuState,void **,8)+record,u8 *,0xa2)==1) {
RecordsMenu_ShuffleList(record);
RecordsMenu_BeginAction(M2C_FIELD((s16 *)M2C_FIELD(&gRecordsMenuState,void **,8)+M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xe2),s16 *,0xe6),1);
} else if(RecordsMenu_IsRecordAvailable(record)&&M2C_FIELD((char *)M2C_FIELD(&gRecordsMenuState,void **,8)+record,u8 *,0xa2)==0) {
RecordsMenu_ShuffleList(-1);
M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xe2)=-1;
RecordsMenu_BeginAction(record,1);
}
break;
}
}

/* Records screen D-pad up.  On tab 0 (the full list) move the highlight one
 * record up, skipping locked records and wrapping back to the current highlight
 * at the top of the table; tabs 1 and 2 step their enabled-only and shuffled
 * lists instead. */
void RecordsMenu_SelectPrevious(s16 record) {
 s32 RecordsMenu_IsRecordAvailable(s32);
 void RecordsMenu_BeginAction(s32,s32);
 void RecordsMenu_SelectPreviousEnabled(s16);
 void RecordsMenu_SelectPreviousInList(s16);
 extern M2C_UNK gRecordsMenuState;
 switch (RECORDS_SCREEN->tab) {
 case 0:
 RECORDS_SCREEN->highlighted = record;
 do {
 record--;
 if (record == -1) {
 record = RECORDS_SCREEN->highlighted;
 break;
 }
 } while (!RecordsMenu_IsRecordAvailable(record));
 RecordsMenu_BeginAction(record, 1); break;
 case 1: RecordsMenu_SelectPreviousEnabled(record); break;
 case 2: RecordsMenu_SelectPreviousInList(record); break;
 }
}

