/* 21 functions from 0x020B8CCC to 0x020B9C8C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
typedef struct { u8 value; u8 flag; } Unk020BChoice;
typedef struct UiB8ccc {u8 pad[0x40];u32 a:18;u32 tile:8;u32 b:6;u8 pad44[0x15];u8 mode:4;u8 active:1;u8 c:3;u8 reset;u8 pad5b[9];s8 *state;} UiB8ccc;

static inline s32 MulUiB8ccc(s32 a,s32 b){return ((s64)a*b+0x800)>>12;}
static inline u8 IsUiB8ccc(UiB8ccc *p){return p->state[11]==1 || (p->active && p->state[12]==1);}

#pragma optimization_level 2
void func_020b8ccc(void *a){
s32 IsListRowUnavailable(s32);void RedrawListRows(s32);s32 GetUiMode(void);s32 GetScreenTransitionType(void);s32 CanStartScreenTransition(void);void StartShortScreenTransition(s32);void SetUiMode(s32,s32);M2C_UNK PlaySoundEffect(s32);void func_020b876c(void);void func_020b8778(void);void MenuSpriteUpdate(void *);void ScrollListUp(void *);void ScrollListDown(void *);s32 FX_Div(s32,s32);void DrawFrameBorder(s32,s16,s32,s16,u16,s32,s32);
extern u16 *gKeyState;extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
s16 step; void *old;s32 size,h,pos,v,t,pal;UiB8ccc *p;
if(M2C_FIELD(a,s16*,0x3c)==0){
t=M2C_FIELD(a,s16*,0x40)*2;v=M2C_FIELD(a,s16*,0x3e);
if(v!=t){h=t-v;if(h<0)h=-h;step=h>>1;if(step==0)step=1;if(v>t)M2C_FIELD(a,s16*,0x3e)-=step;else M2C_FIELD(a,s16*,0x3e)+=step;M2C_FIELD(a,s16*,0x3c)=1;RedrawListRows(M2C_FIELD(a,s16*,0x3e));}
}else M2C_FIELD(a,s16*,0x3c)=0;
if(M2C_FIELD(a,s16*,0x46)==0){
if(IsListRowUnavailable(M2C_FIELD(a,s16*,0x38))){
if(GetUiMode()==2){
if(M2C_FIELD(a,s16*,0x38)!=GetScreenTransitionType() && CanStartScreenTransition() && IsListRowUnavailable(M2C_FIELD(a,s16*,0x38)))StartShortScreenTransition(M2C_FIELD(a,s16*,0x38));
}else SetUiMode(2,M2C_FIELD(a,s16*,0x38));
}
}else M2C_FIELD(a,s16*,0x46)--;
M2C_FIELD(a,s16*,0x36)=M2C_FIELD(a,s16*,0x38);
M2C_FIELD(a,s16*,0x38)=M2C_FIELD(a,s16*,0x40)+M2C_FIELD(a,s16*,0x3a);
if(M2C_FIELD(a,s16*,0x36)!=M2C_FIELD(a,s16*,0x38)){M2C_FIELD(a,s16*,0x46)=4;PlaySoundEffect(0x10019);}
p=M2C_FIELD(a,UiB8ccc**,0x48);if(M2C_FIELD(a,s16*,0x40)==0)p->tile=(u16)(p->mode+2);else p->tile=(u16)p->mode;p->reset=0;
p=M2C_FIELD(a,UiB8ccc**,0x4c);if(M2C_FIELD(a,s16*,0x40)==M2C_FIELD(a,s16*,0x42)-6)p->tile=(u16)(p->mode+2);else p->tile=(u16)p->mode;p->reset=0;
if(*gKeyState&1){func_020b876c();return;}if(*gKeyState&2){func_020b8778();return;}
MenuSpriteUpdate(M2C_FIELD(a,void**,0x48));MenuSpriteUpdate(M2C_FIELD(a,void**,0x4c));MenuSpriteUpdate(M2C_FIELD(a,void**,0x50));
if(IsUiB8ccc(M2C_FIELD(a,UiB8ccc**,0x48)))ScrollListUp(a);
if(IsUiB8ccc(M2C_FIELD(a,UiB8ccc**,0x4c)))ScrollListDown(a);
if(IsUiB8ccc(M2C_FIELD(a,UiB8ccc**,0x50))){func_020b876c();return;}
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
h=M2C_FIELD(a,s16*,0x42)<<12;pos=M2C_FIELD(a,s16*,0x40)<<12;
size=((s64)FX_Div(0x62000,h)*0x6000+0x800)>>12;
v=MulUiB8ccc(FX_Div(0x62000-size,h-0x6000),pos);
t=size>>12;if(t>98)t=98;else if(t<1)t=1;
pal=0x35c;
DrawFrameBorder(248,(v>>12)+40,2,t,((pal+0xa3)&(pal>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30)))|0xb000,0,2);
gCur3DSpriteEngine=old;
}
#pragma optimization_level 4
/* Close the current sub-screen and return to the map: switch to the main 3D
 * sprite engine, clear its two overlay layers, mark them dirty, redraw the map
 * view and release the map's overlay, then restore the previous engine. */
void ReturnToMapView(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK, s32);
    void RefreshMapView();
    void ReleaseMapViewHold();
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    void *old = gCur3DSpriteEngine;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    ((M2C_UNK (*)())Clear3DSpriteLayer)(1);
    ((M2C_UNK (*)())Clear3DSpriteLayer)(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER1;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
    RefreshMapView();
    ReleaseMapViewHold();
    gCur3DSpriteEngine = old;
}

/* Create the scrollable menu list (gMenuListClass) owned by `owner`; owner 0
 * asks for the default owner, 7 (the screen the menus are created under). */
void CreateMenuList(s32 owner) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, s32);
    extern M2C_UNK gMenuListClass;

    if (owner == 0) {
        CreateSpriteFromClass(&gMenuListClass, 7);
        return;
    }
    CreateSpriteFromClass(&gMenuListClass, owner);
}

#pragma optimization_level 2
#pragma opt_common_subs off
void DrawFundsCostRow(s32 x,s32 y,s32 a,s32 b,s32 c){
void ClearTileRect(void *,s32,s32);s32 GetDigitCount(s32);void DrawTilemapNumber(s32,s32,s32,s32,u16,u16);void DrawTilemapSymbol(s16,s16,void *,s32,s32,u16);extern void *gCur3DSpriteEngine;
s32 pos,base=x; s32 color=0;
if(c<0)color=3;
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,u8 **,36)+x*2+y*64,32,2);
pos=x+4;DrawTilemapNumber((s16)(pos+(GetDigitCount(a)-1)),(s16)y,M2C_FIELD(gCur3DSpriteEngine,s32 *,36),a,0,0);
pos=base+11;if(b<0){DrawTilemapSymbol(pos,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),45,0,0);if(b<0)b=-b;}else{DrawTilemapSymbol(pos,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),43,0,0);}
a=base+14;DrawTilemapNumber((s16)(a+(GetDigitCount(b)-1)),(s16)y,M2C_FIELD(gCur3DSpriteEngine,s32 *,36),b,0,0);
DrawTilemapSymbol(base+20,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),61,0,0);
base+=23;
if(c<0){DrawTilemapSymbol(base++,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),45,0,color);if(c<0)c=-c;}
DrawTilemapNumber((s16)(base+(GetDigitCount(c)-1)),(s16)y,M2C_FIELD(gCur3DSpriteEngine,s32 *,36),c,0,color);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;
}
#pragma opt_common_subs reset
#pragma optimization_level 4
/* Start the production row's funds count-up: reset its elapsed-frame counter, set
 * the count-up to run for 8 frames, play the unit-arrival sound at the map cursor's
 * target tile, and in fast-animation mode remove the row straight away instead of
 * animating the count-up. */
void ProductionMenu_StartCountUp(void *row) {
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK PlaySoundAtTile(s32, s16, s16);
    s32 IsFastAnimation();
    extern void **gCurrentMap;
    void *map;

    M2C_FIELD(row, s16 *, PRODUCTION_ROW_FRAME) = 0;
    M2C_FIELD(row, s16 *, PRODUCTION_ROW_DURATION) = 8;
    map = *gCurrentMap;
    PlaySoundAtTile(0x111, M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y));
    if (IsFastAnimation() == 0) {
        return;
    }
    DeleteSpriteObject(row);
}

/* Advance the production menu's funds count-up by one frame: ease the displayed
 * funds from the player's current funds down to what is left after the row's
 * unit cost, redraw the funds line with it, tick a sound every fourth frame, and
 * once the count-up is over hand the row object on to the sprite state. */
void UpdateProductionFundsRow(void *row) {s32 GetUnitBuildCostTimes10(s32,s32);s32 EaseInterpolate(s32,s32,s32,s32,s32);void DrawFundsCostRow(s32,s32,s32,s32,s32);M2C_UNK PlaySoundEffect(s32);void Sprite_ResumeAnimation(void *);extern void **gCurrentMap;
s32 frame,duration,funds,cost,remaining,kind,player;void *map;
kind=M2C_FIELD(row,s32 *,PRODUCTION_ROW_KIND);M2C_FIELD(row,s16 *,PRODUCTION_ROW_FRAME)++;map=*gCurrentMap;frame=M2C_FIELD(row,s16 *,PRODUCTION_ROW_FRAME);duration=M2C_FIELD(row,s16 *,PRODUCTION_ROW_DURATION);
player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);funds=M2C_FIELD((u8 *)map+player*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF);
cost=GetUnitBuildCostTimes10(player,kind);remaining=funds-cost;
DrawFundsCostRow(0,1,EaseInterpolate(0,funds,remaining,frame,duration),-cost,remaining);
if((frame&3)==1)PlaySoundEffect(0x10023);if(frame<duration)return;Sprite_ResumeAnimation(row);
}

/* Confirm a row of the unit-production menu: build the row's kind on the tile
 * the cursor is aimed at, move the cursor onto it, record the build command for
 * the link peer, run the map's unit-built event (14) and hand the map back to
 * normal cursor input. */
void ProductionMenu_ConfirmBuild(void *row) {
    s32 ProduceUnit(s32, s32, s32);
    void SetBattleCommand(s32, u8, s32, s32);
    void RunUnitEvent(s32, s32);
    extern void **gCurrentMap;
    s32 kind = M2C_FIELD(row, s32 *, PRODUCTION_ROW_KIND);
    s32 unit;
    void *map = *gCurrentMap;

    unit = ProduceUnit(M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y), kind);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y);
    SetBattleCommand(1, kind, 0, 0);
    RunUnitEvent(14, unit);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_MODE) = MAP_MODE_CURSOR;
}

void CreateProductionMenuRow(s32 arg0, s32 arg1) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK data_02129178;
    M2C_FIELD(CreateSpriteObject(&data_02129178), s32 *, 0x5C) = arg0;
}

/* Draws the selected unit's cost and projected balance, then updates the unit info panel. */
void DrawProductionUnitPreview(u8 unitKind) {
    s32 GetUnitBuildCostTimes10(s32, s32);
    void DrawFundsCostRow(s32, s32, s32, s32, s32);
    void Ov000_InfoWindow_ShowProductionUnit(s32, s32);
    extern void **gCurrentMap;
    void *map = *gCurrentMap;
    s32 player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
    s32 funds = M2C_FIELD((u8 *)map + player * MAP_PLAYER_STRIDE, s32 *, PLAYER_FUNDS_OFF);
    s32 cost = GetUnitBuildCostTimes10(player, unitKind);

    DrawFundsCostRow(0, 1, funds, -cost, funds - cost);
    Ov000_InfoWindow_ShowProductionUnit(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), unitKind);
}

void ProductionMenu_HandleInput(u8 *selection) {
extern u16 *gKeyState;
extern s32 gProductionMenuState;
void FocusSpriteSlotById(s32),InvokeConfirmCallback(void *),InvokeCancelCallback(void);
/* D-pad handler for the unit-production menu: moves the selected entry within the
 * grid of buildable kinds (7 rows, wrapping top/bottom at the ends, left/right onto
 * the other column), clamps it to the entry count, focuses its sprite slot, then
 * confirms (A) or cancels (B). */
u16 *keyState=gKeyState;
s32 sel=*selection;
u32 pressed=keyState[KEY_PRESSED];
s32 count;
if(pressed&KEY_UP) {
if(sel==0||sel==7) {if(pressed==keyState[KEY_HELD]) {sel+=6;count=M2C_FIELD(&gProductionMenuState,s32 *,4)-1;if(sel>=count)sel=count;}}
else sel--;
}
if(pressed&KEY_DOWN) {
if(sel==6||sel==13||sel==M2C_FIELD(&gProductionMenuState,s32 *,4)-1) {if(pressed==keyState[KEY_HELD]) {sel-=6;if(sel<0)sel=0;}}
else sel++;
}
count=M2C_FIELD(&gProductionMenuState,s32 *,4);
if(count>7) {
if((pressed&KEY_LEFT)&&sel>=7)sel-=7;
if((pressed&KEY_RIGHT)&&sel<7)sel+=7;
count--;if(sel>=count)sel=count;
}
FocusSpriteSlotById(sel);
if(gKeyState[KEY_HELD]&KEY_A) {InvokeConfirmCallback(selection);return;}
if(gKeyState[KEY_HELD]&KEY_B)InvokeCancelCallback();
}

/* Confirms the selected row of the unit-production menu: a kind the player cannot
 * afford only plays the error sound, and otherwise the per-kind cost row is opened
 * on the menu screen while a unit record is free; either refusal shows a message
 * instead. The sprite slots are cleared and the screen finished afterwards. */
void ProductionMenu_ConfirmSelection(u8 *selection) {
    s32 FindFreeUnitRecord(s32);
    M2C_UNK PlaySoundEffect(s32);
    void func_02096b6c(u32);
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK HideAllSpriteSlots();
    M2C_UNK ResumeAnimationOfSpriteClass(M2C_UNK *);
    void CreateProductionMenuRow(s32, s32);
    extern void **gCurrentMap;
    extern u8 gProductionChoices[];
    extern u8 gProductionChoicesUnaffordable[];
    extern M2C_UNK gProductionMenuScreenClass;
    u8 index = *selection;

    if (gProductionChoicesUnaffordable[index * 2] == 1) {
        PlaySoundEffect(0x1001d);
        return;
    }
    if (!FindFreeUnitRecord(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) {
        PlaySoundEffect(0x1001d);
        func_02096b6c(0xc0000332);
    } else {
        void *screen = FindObjectByClass(&gProductionMenuScreenClass);
        CreateProductionMenuRow(gProductionChoices[index * 2], (s32)screen);
    }
    HideAllSpriteSlots();
    ResumeAnimationOfSpriteClass(&gProductionMenuScreenClass);
}

void func_020b9778(void) {
    M2C_UNK ResumeAnimationOfSpriteClass(M2C_UNK *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK HideAllSpriteSlots();
    extern M2C_UNK gProductionMenuScreenClass;
    PlaySoundEffect(0x10018);
    HideAllSpriteSlots();
    ResumeAnimationOfSpriteClass(&gProductionMenuScreenClass);
}

void func_020b979c(u8 *a) {
    void DrawProductionUnitPreview(u8);
    M2C_UNK PlaySoundEffect(s32);
    extern u8 gProductionChoices[];
    DrawProductionUnitPreview(gProductionChoices[*a * 2]);
    PlaySoundEffect(0x10019);
}

/* Open the unit-production menu on the property tile at (x, y): pick the build
 * mask from the tile's terrain kind (the ground facilities offer the ground
 * kinds, an airport the air kinds and a port the naval kinds), rebuild the
 * menu's entry list from that mask and create the production menu screen. */
void OpenProductionMenu(s32 x, s32 y) {
    void BuildProductionMenuEntries(s8 mask);
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, s32);
    extern void **gCurrentMap;
    extern M2C_UNK gProductionMenuState;
    extern M2C_UNK gProductionMenuScreenClass;
    u8 *map = *gCurrentMap;
    u32 terrain = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
    switch (terrain) {
    case MAP_TERRAIN_PROPERTY_FIRST:     /* headquarters */
    case MAP_TERRAIN_PROPERTY_FIRST + 1: /* city */
    case MAP_TERRAIN_PROPERTY_FIRST + 2: /* base */
        M2C_FIELD(&gProductionMenuState, s32 *, PRODUCTION_MENU_KIND_MASK) = PRODUCTION_BUILD_GROUND;
        break;
    case MAP_TERRAIN_PROPERTY_FIRST + 3: /* airport */
        M2C_FIELD(&gProductionMenuState, s32 *, PRODUCTION_MENU_KIND_MASK) = PRODUCTION_BUILD_AIR;
        break;
    case MAP_TERRAIN_PROPERTY_FIRST + 4: /* port */
        M2C_FIELD(&gProductionMenuState, s32 *, PRODUCTION_MENU_KIND_MASK) = PRODUCTION_BUILD_NAVAL;
        break;
    }
    BuildProductionMenuEntries((s8)M2C_FIELD(&gProductionMenuState, s32 *, PRODUCTION_MENU_KIND_MASK));
    CreateSpriteFromClass(&gProductionMenuScreenClass, 7);
}

#pragma push
#pragma opt_common_subs off
void BuildProductionMenuEntries(s8 mask) {
    s32 CanBuildUnitKind(s32, s32);
    s32 GetUnitBuildCostTimes10(s32, s32);
    extern s8 data_ov000_021aab94[];
    extern u8 gUnitKindStats[];
    extern u8 gProductionChoices[];
    extern M2C_UNK gProductionMenuState;
    extern void **gCurrentMap;

    s8 *table = data_ov000_021aab94;
    u8 *attrs = gUnitKindStats;
    u8 i = 0;
    u8 count = 0;
    if (table[0] != -1) {
        u8 *buf = gProductionChoices;
        do {
            u8 kind = (u8)table[i];
            if (mask & attrs[kind * 0x70 + 0x13]) {
                if (CanBuildUnitKind(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), kind) != 0) {
                    void *g2 = *gCurrentMap;
                    u16 idx = M2C_FIELD(g2, u16 *, 0x52a4);
                    s32 base = GetUnitBuildCostTimes10(idx, kind);
                    s32 total = *(s32 *)((u8 *)g2 + idx * 0x8c + 0x67a4);
                    if (total < base)
                        buf[count * 2 + 1] = 1;
                    else
                        buf[count * 2 + 1] = 0;
                    buf[count * 2] = kind;
                    count++;
                }
            }
            i++;
        } while (table[i] != -1);
    }
    M2C_FIELD(&gProductionMenuState, s32 *, 4) = count;
    gProductionChoices[count * 2] = 0;
}
#pragma pop
/* Wipe the current 3D-sprite engine's terrain layer (layer 1) tile buffer and
 * mark that layer dirty so the engine uploads it again.  The layer's buffer
 * pointer is passed along as well; Clear3DSpriteLayer only uses the layer
 * number and looks the buffer up itself. */
void ClearTerrainLayerTiles(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK, s32);
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(1, M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_LAYER_TILES + 4));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) =
        (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER1);
}

#pragma opt_common_subs off
void DrawProductionMenuColumnEntries(s32 arg0,s32 arg1,s32 arg2) {
M2C_UNK DrawLocalizedTextToTilemap(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,u16);
void DrawTilemapNumber(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,u16);
M2C_UNK WriteUnitKindTileQuad(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,u8,u8);
M2C_UNK GetUnitBuildCostTimes10(M2C_UNK,M2C_UNK);
extern u8 gProductionChoices[],gUnitKindStats[];
extern void *gCur3DSpriteEngine; extern void **gCurrentMap;
s32 left; s32 right; s32 x;
s32 y=arg1+1;
u8 *ptr=gProductionChoices+arg2*2;
u16 mode, color; s32 row; u16 i;

s32 value; u32 kind;
right=(s16)(arg0+14); left=(u16)(arg0+1); x=(s16)(arg0+3);
i=0; do {
kind=ptr[i*2]; if(!kind)break;
if(*(i*2+ptr+1)){mode=3;color=256;}else{mode=0;color=M2C_FIELD(*gCurrentMap,u16*,0x52a8);}
row=y+i*2;
DrawLocalizedTextToTilemap(x,(s16)row,M2C_FIELD(gCur3DSpriteEngine,s32*,0x24),M2C_FIELD(gUnitKindStats,s32*,kind*112),0,mode);
value=GetUnitBuildCostTimes10(M2C_FIELD(*gCurrentMap,u16*,0x52a4),ptr[i*2]);
DrawTilemapNumber(right,(s16)row,M2C_FIELD(gCur3DSpriteEngine,s32*,0x24),value,0,mode);
WriteUnitKindTileQuad(M2C_FIELD(gCur3DSpriteEngine,s32*,0x24),left,(u16)row,ptr[i*2],color,0,0);
i++; } while(i<7);
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x3a)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x42)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x3c)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x44)=0;
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
}
#pragma opt_instruction_scheduling off
void AddProductionMenuColumnSprites(s32 a,s32 b,s32 c) {
M2C_UNK AddSpriteSlot(s32,s32,M2C_UNK *,s32);
extern u8 gProductionChoices[];extern M2C_UNK data_02129150;
s32 i; s32 y; register s32 x;
Unk020BChoice *p;
x=a+1; x<<=3;
b++; y=b<<3;
p=(Unk020BChoice *)gProductionChoices;
i=0;
do {
if(p[c+i].value==0)return;
AddSpriteSlot(x,y,&data_02129150,c+i);
i++;y+=16;
}while(i<7);
}
#pragma opt_instruction_scheduling reset
/* Draw one column of the unit-production menu: the bordered window at (x, y)
 * and then the column's rows, starting at entry `first`. */
void DrawProductionMenuColumn(s32 x, s32 y, s32 first) {
    void DrawProductionMenuColumnEntries(s32, s32, s32);
    M2C_UNK DrawWindowFrame(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);

    DrawWindowFrame(x, y, 16, 16, 1);
    DrawProductionMenuColumnEntries(x, y, first);
}

/* Lay out the sprite slots for the unit-production menu's entries: one column of
   7 when the list fits on a single page, otherwise two columns split across the
   page, then focus the first slot. */
void CreateProductionMenuSprites(void) {
    void AddProductionMenuColumnSprites(s32, s32, s32);
    void SelectSpriteSlot(s32);
    extern M2C_UNK gProductionMenuState;
    if (M2C_FIELD(&gProductionMenuState, s32 *, PRODUCTION_MENU_COUNT) <= PRODUCTION_MENU_PAGE_ENTRIES) AddProductionMenuColumnSprites(8, 4, 0);
    else {
        AddProductionMenuColumnSprites(0, 4, 0);
        AddProductionMenuColumnSprites(16, 4, 7);
    }
    SelectSpriteSlot(0);
}

/* Draw the unit-production menu's windowed columns: a single column when the
 * list fits on one page, otherwise two columns split across the page. */
void DrawProductionMenuColumns(void) {
    void DrawProductionMenuColumn(s32, s32, s32);
    extern M2C_UNK gProductionMenuState;

    if (M2C_FIELD(&gProductionMenuState, s32 *, PRODUCTION_MENU_COUNT) <= PRODUCTION_MENU_PAGE_ENTRIES) {
        DrawProductionMenuColumn(8, 4, 0);
        return;
    }
    DrawProductionMenuColumn(0, 4, 0);
    DrawProductionMenuColumn(16, 4, 7);
}

