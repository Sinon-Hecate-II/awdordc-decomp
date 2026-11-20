/* 39 functions from 0x020CBACC to 0x020CC9C8 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"
static inline s32 visibleCB(void *p,s32 x,s32 y) {
u32 n;
if (M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*140,u8 *,0x67c3)&2)return 1;
n=x+M2C_FIELD((u8 *)p+y*2,u16 *,0x3758);
return (u8)(M2C_FIELD((u8 *)p+(n>>3),u8 *,0x5201)&(1<<(n&7)))!=0;
}

typedef struct { u8 kind:6; u8 flags:2; } UnkCBUnit;

typedef struct { u8 unk_0 : 6; u8 unk_6 : 2; } Unk020cbc88;

/* Stepping overlay task, the supply-marking variant: scan the current player's units
   from the saved index and find the first one worth marking - a transport (kind 21/23)
   whose cargo has a cost or a value, or a unit a friendly supply unit can refill -
   highlight its tile and save the next index; at the end of the list retire the task. */
void MarkSupplyUnitTiles(void *state){extern void **gCurrentMap;s32 func_020c98b4(void *);s32 MarkTransportCargo(void *);s32 CanBeSupplied(void *);s32 func_020cb6a4(void *);M2C_UNK Sprite_ResumeAnimation(void *);
u16 i;void *p,*q;u32 k;
if(func_020c98b4(state))return;
for(i=M2C_FIELD(state,u16 *,0x50);i<51;i++){
p=*gCurrentMap;q=(u8 *)p+0x59a4+(M2C_FIELD(p,u16 *,0x52a8)+i)*14;
k=((UnkCBUnit *)q)->kind;if(!k)continue;if(M2C_FIELD(q,u16 *,4)&8)continue;
if(k==23||k==21){if(MarkTransportCargo(q)){M2C_FIELD(state,u16 *,0x50)=i+1;break;}}
if(CanBeSupplied(q)&&func_020cb6a4(q)){M2C_FIELD(state,u16 *,0x50)=i+1;break;}
}if(i==51)Sprite_ResumeAnimation(state);
}

void func_020cbbac(void) {
 extern void **gCurrentMap;
 void *p;
 void *q;
 if (!func_020d0590(M2C_FIELD(*gCurrentMap,u16 *,0x52A4))) return;
 p=*gCurrentMap;
 q=(u8 *)p+0x67A4+M2C_FIELD(p,u16 *,0x52A4)*0x8C;
 StepMapViewToTile(M2C_FIELD(q,u8 *,0x2D),M2C_FIELD(q,u8 *,0x2E));
}

void func_020cbc08(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b534;
    CreateSpriteFromClass(&data_0212b534, 7);
}

#pragma opt_common_subs off
void func_020cbc20(void *arg0) {
 extern void **gCurrentMap;
 void *p=M2C_FIELD(arg0,void **,0x34);
 s32 n;
 func_020b5594(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),5,arg0);
 if (!p) n=0;
 else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;
 DestroyUnit(n);
 RefreshMapView();
}
#pragma opt_common_subs reset
void func_020cbc88(void *arg0) {
 void *CreateSpriteObject(M2C_UNK *);
 extern M2C_UNK data_0212b22c;
 if (((Unk020cbc88 *)arg0)->unk_0==0) return;
 if (M2C_FIELD(arg0,u16 *,4)&8) return;
 M2C_FIELD(CreateSpriteObject(&data_0212b22c),void **,0x34)=arg0;
}

void func_020cbcc0(void *arg0) {
    M2C_UNK func_0207b784(s32);
    func_0207b784(M2C_FIELD(arg0, s32 *, 0x34));
}

void func_020cbcd0(void *arg0) {
    M2C_UNK func_020b576c(s32);
    func_020b576c(M2C_FIELD(arg0, s32 *, 0x34));
}

void CreateFuelCrashEffect(s32 arg0) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK gFuelCrashSpriteClass;
    M2C_FIELD(CreateSpriteObject(&gFuelCrashSpriteClass), s32 *, 0x34) = arg0;
}

void func_020cbcfc(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
}

/* Start-of-turn fuel pass, one unit per frame: charge the turn fuel of each
 * unit of the current player from the saved slot; the first air or sea unit
 * left without fuel pans the view to it and starts its crash (the unit is
 * destroyed when that animation ends). Once every slot has been visited the
 * task finishes. */
void CrashFuelStarvedUnits(void *task) {
extern void **gCurrentMap;
s32 ChargeUnitTurnFuel(void *);
M2C_UNK Sprite_ResumeAnimation(void *);
while (M2C_FIELD(task, s16 *, 0x6c) < MAP_UNIT_GROUP_SCAN) {
    u8 *units = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS;
    BattleMapUnitHead *unit = (BattleMapUnitHead *)(units + (M2C_FIELD(task, s16 *, 0x6c) + M2C_FIELD(*gCurrentMap, u16 *, MAP_UNIT_GROUP_BASE)) * MAP_UNIT_STRIDE);
    if (unit->kind && ChargeUnitTurnFuel(unit)) {
        ((void (*)(void *, void *))CreateFuelCrashEffect)(unit, task);
        return;
    }
    M2C_FIELD(task, s16 *, 0x6c)++;
}
if (M2C_FIELD(task, s16 *, 0x6c) >= MAP_UNIT_GROUP_SCAN) Sprite_ResumeAnimation(task);
}

void func_020cbda4(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b25c;
    CreateSpriteFromClass(&data_0212b25c, 7);
}

/* Pack the target cursor tile into the cached cell coordinates, reset display flags, and refresh display mode. */
void RefreshMapCursorCellCache(void) {
    extern void **gCurrentMap;
    void UpdateCursorCellDisplayMode(void);
    void *map;

    map = *gCurrentMap;
    M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) =
        (M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) & ~MAP_CURSOR_CELL_COORD_MASK) |
        ((u32)(M2C_FIELD(map, u16 *, MAP_CURSOR_TARGET_X) << 25) >> 23);
    map = *gCurrentMap;
    M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) =
        (M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) & ~MAP_CURSOR_CELL_COORD_Y_MASK) |
        ((u32)(M2C_FIELD(map, u16 *, MAP_CURSOR_TARGET_Y) << 25) >> 16);
    M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_CELL_DISPLAY_MODE) = 0;
    M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_CELL_CACHE) &= ~MAP_CURSOR_CELL_FLAGS_MASK;
    UpdateCursorCellDisplayMode();
}

/* Spawn the ripple effect on the tile under the map cursor when that tile is
 * visible and on screen: mode 0 uses the "ripple_in" sprite, mode 1 the
 * "ripple_out" sprite, each with its own placement sound. */
void SpawnRippleEffect(M2C_UNK unused, M2C_UNK mode) {
extern void **gCurrentMap;
extern u8 sRippleInName[],sRippleOutName[];
void *CreateAnimatedMapSprite(void *,s32,s32,s32,s32,s32,s32);
s32 func_020d0548(s32,s32);
void *map=*gCurrentMap,*sprite; s32 x=M2C_FIELD(map,s16 *,0x52dc),y=M2C_FIELD(map,s16 *,0x52de); if(!visibleCB(map,x,y))return;
if(!func_020d0548(x,y))return;
switch(mode){
case 0:
sprite=CreateAnimatedMapSprite(sRippleInName,x,y,0,0,0,7);
M2C_FIELD(sprite,u32 *,0x44)=(M2C_FIELD(sprite,u32 *,0x44)&~0x3000000)|0x2000000;
PlaySoundAtTile(0x84,x,y);break;
case 1:
sprite=CreateAnimatedMapSprite(sRippleOutName,x,y,0,0,0,7);
M2C_FIELD(sprite,u32 *,0x44)=(M2C_FIELD(sprite,u32 *,0x44)&~0x3000000)|0x2000000;
PlaySoundAtTile(0x85,x,y);break;
}
}

void SpawnRippleIn(M2C_UNK arg0) {
    void SpawnRippleEffect(M2C_UNK, M2C_UNK);
    SpawnRippleEffect(arg0, 0);
}

void SpawnRippleOut(M2C_UNK arg0) {
    void SpawnRippleEffect(M2C_UNK, M2C_UNK);
    SpawnRippleEffect(arg0, 1);
}

void func_020cbfb4(void) {
    M2C_UNK SetUiMessageText(s32);
    s32 IsCampaignBattleRules();
    if (IsCampaignBattleRules() != 0) {
        SetUiMessageText(0xC000032F);
        return;
    }
    SetUiMessageText(0xC0000328);
}

void func_020cbfe4(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b5f4;
    CreateSpriteFromClass(&data_0212b5f4, 7);
}

void func_020cbffc(void) {
 extern void **gCurrentMap;
 SetPlayerGaveUp(M2C_FIELD(*gCurrentMap,u16 *,0x52A4),1);
 func_020ca484();
}

void func_020cc028(void) {
    M2C_UNK AwardVictoryToPlayer(u16, M2C_UNK);
    extern void **gCurrentMap;
    AwardVictoryToPlayer(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), 8);
}

void func_020cc050(void) {
extern void **gCurrentMap;
SetPlayerGaveUp(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),1);
SetBattleCommand(17,0,0,0);
}

void func_020cc08c(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b4ec;
    CreateSpriteFromClass(&data_0212b4ec, 7);
}

/* Sets up the map-view screen: resets the map view, saves the scroll position on
 * the task and starts its fade, draws the map preview and its name, centres the
 * sprite quad and enters map-view mode. */
void InitMapView(MapViewTask *p){
extern void **gCurrentMap;
extern void *gCur3DSpriteEngine;
s32 RefreshMapView(void);
void DrawMapPreview(s32,s32,s32,s32);
void SetFrameRect(s32,s32,s32,s32);
void Reset3DSpriteEngineState(void);
void Reset3DSpriteBankState(void);
void LoadScenePanelPalette(s32);
s32 GetMapName(s32);
void DrawTextLine(s32,s32,s32,s32,s32,s32);
s32 x,y;
RefreshMapView();
p->fadeTimer=0;
p->viewX=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X);
p->viewY=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y);
p->unk3A=0;
DrawMapPreview((s32)((DS3DSpriteEngine *)gCur3DSpriteEngine)->layerVram[1],(s32)((DS3DSpriteEngine *)gCur3DSpriteEngine)->layerTiles[1],1,2);
((DS3DSpriteEngine *)gCur3DSpriteEngine)->layerDirty|=2;
y=-((192-(M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT)<<2))>>1);
x=-((256-(M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)<<2))>>1);
((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->corner[1]=x;
((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->corner[5]=y;
SetFrameRect((256-(M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)<<2))>>1,(192-(M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT)<<2))>>1,0x35c,11);
Reset3DSpriteEngineState();
Reset3DSpriteBankState();
LoadScenePanelPalette(0);
((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->corner[2]=0;
((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->corner[6]=0;
DrawTextLine(1,0,2,GetMapName(M2C_FIELD(*gCurrentMap,u16 *,MAP_ID)),0,16);
M2C_FIELD(*gCurrentMap,s16 *,MAP_MODE)=9;
}

/* Advance the map fade-in one frame: bump the fade timer at +0x34, copy half
 * its value into the 3D sprite bank's blend byte, clear every layer bit and set
 * the map view's, then finish the task once the timer reaches 12. */
void MapFadeInStep(u8 *fade) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    extern void *gCur3DSpriteEngine;
    u16 *volatile oamC0;
    u16 *volatile oam1;
    u16 *volatile oam2;
    u16 *volatile oam4;
    u16 *volatile oam8;
    u16 *volatile oam10;
    u16 *volatile oam100;
    u16 *volatile oam200;
    u16 *volatile oam400;
    u16 *volatile oam800;
    u16 *volatile oam1000;
    s32 value;
    u8 brightness;

    (*(s16 *)(fade + 0x34))++;
    value = *(s16 *)(fade + 0x34);
    brightness = value >> 1;
    oamC0 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oamC0 = (*oamC0 & ~0xc0) | 0xc0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsAbove = 0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsBelow = 0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->filler_53 = brightness;
    oam1 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1 = (*oam1 & ~1) | 1;
    oam2 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam2 = *oam2 & ~2;
    oam4 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam4 = *oam4 & ~4;
    oam8 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam8 = *oam8 & ~8;
    oam10 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam10 = *oam10 | 0x10;
    oam100 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam100 = *oam100 & ~0x100;
    oam200 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam200 = *oam200 & ~0x200;
    oam400 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam400 = *oam400 & ~0x400;
    oam800 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam800 = *oam800 & ~0x800;
    oam1000 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1000 = *oam1000 & ~0x1000;
    if (*(s16 *)(fade + 0x34) < 12) return;
    Sprite_ResumeAnimation(fade);
}

void func_020cc430(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_020cf80c();
    extern u16 *gKeyState;
    func_020cf80c();
    func_0207a7a4(1, 8);
    if (IsMapCursorIdle() != 0) {
        if (!(*gKeyState & 0xB)) {
            return;
        }
        PlaySoundEffect(0x10018);
        Sprite_ResumeAnimation(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x3A) = 1;
}

void func_020cc490(void *arg0) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK func_020c127c();
    M2C_UNK RefreshMapView();
    extern void *gCur3DSpriteEngine;
    RefreshMapView();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    Clear3DSpriteLayer(3);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    func_020c127c();
    M2C_FIELD(arg0, s16 *, 0x34) = 6;
}

void func_020cc504(void *a) {
extern void *gCur3DSpriteEngine;M2C_UNK Sprite_ResumeAnimation(void *);
u16 *volatile p; s32 n;
M2C_FIELD(a,s16 *,0x34)--;
n=M2C_FIELD(a,s16 *,0x34);
p=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12);
*p=(*p&~0xc0)|0xc0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=n;
if(!M2C_FIELD(a,s16 *,0x34))Sprite_ResumeAnimation(a);
}

/* Closing step of the battle map-view task: when the view is being closed,
 * recentre the battle cursor's target on the middle of the shown map view, then
 * reset the 3D sprite bank and map layer state and return the map to mode 0. */
void CloseMapViewStep(void *a) {
    extern void **gCurrentMap;
    u32 GetMapViewWidth(void);u32 GetMapViewHeight(void);
    MapViewTask *task = (MapViewTask *)a;
    void *p;
    if (task->unk3A) {
        p = (u8 *)*gCurrentMap + 0x5120;   /* +0x28 is MAP_VIEW_X */
        M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_TARGET_X) = (GetMapViewWidth() >> 1) + (M2C_FIELD(p, s16 *, 0x28) >> 4);
        p = (u8 *)*gCurrentMap + 0x5120;   /* +0x2a is MAP_VIEW_Y */
        M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_TARGET_Y) = (GetMapViewHeight() >> 1) + (M2C_FIELD(p, s16 *, 0x2a) >> 4);
        RefreshMapCursorCellCache();
    }
    Reset3DSpriteBankState();
    func_020c0a88();
    M2C_FIELD(*gCurrentMap, u16 *, MAP_MODE) = 0;
}

void func_020cc62c(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b664;
    CreateSpriteFromClass(&data_0212b664, 7);
}

void func_020cc644(void *arg0) {
    M2C_UNK MapView_SetCursorPosition(s16, s16, M2C_UNK);
    MapView_SetCursorPosition((s16) (M2C_FIELD(arg0, s32 *, 0x38) * 0x10), (s16) (M2C_FIELD(arg0, s32 *, 0x3C) * 0x10), 2);
}

void CreateTargetCursor(s32 a,s32 b) {
extern M2C_UNK data_0212b1dc;s32 FindObjectByClass(M2C_UNK *);M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);void *p;
if(FindObjectByClass(&data_0212b1dc))return;
p=(void *)CreateSpriteFromClass(&data_0212b1dc,7);
M2C_FIELD(p,s32 *,0x38)=a;M2C_FIELD(p,s32 *,0x3c)=b;
}

void CancelMapCursorAnimation(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_0212b1dc;
    DeleteSpriteObjectsOfClass(&data_0212b1dc);
}

/* Confirms the action on the battle map's current target: an empty cell queues a
 * move command (kind 4) with the unit id, a cell holding a unit queues an attack
 * command (kind 5) with the tile; a human player's cursor distance to the target
 * then records one or two cursor-movement stats. */
void SubmitCursorTarget(void){
extern s32 gMapCursorOptionValue;extern void **gCurrentMap;
s32 func_020d46cc(void);void func_020d46ac(void);void OpenMapActionMenu(void);void func_020d468c(void);
void *GetTargetPosition(void);s32 IsPlayerHuman(u16);void AddRecordValue(s32,s32);
MapTargetEntry *target; s32 distance;
if(gMapCursorOptionValue<0){if(func_020d46cc())func_020d46ac();else OpenMapActionMenu();return;}
target=(MapTargetEntry *)GetTargetPosition();
if(target->value==0){
func_020d468c();
SetBattleCommand(4,M2C_FIELD(*gCurrentMap,u8 *,MAP_CURSOR_UNIT_ID),target->id&255,0);
}else{
func_020d468c();
SetBattleCommand(5,M2C_FIELD(*gCurrentMap,u8 *,MAP_CURSOR_UNIT_ID),target->x&255,target->y&255);
}
if(!IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))return;
distance=(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_X)-target->x)+(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_Y)-target->y);
if(distance<0)distance=-distance;
if(distance==0)return;
if(distance==1)AddRecordValue(7,1);else AddRecordValue(8,1);
}

void func_020cc7e0(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b294;
    CreateSpriteFromClass(&data_0212b294, 7);
}

s32 func_020cc7f8(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_0211f8fc;
    extern M2C_UNK data_0211f984;
    if ((FindObjectByClass(&data_0211f984) != 0) || (FindObjectByClass(&data_0211f8fc) != 0)) {
        return 1;
    }
    return 0;
}

void func_020cc834(void) {
    M2C_UNK func_0207a768();
    func_0207a768();
}

#pragma push
#pragma scheduling off
void func_020cc840(void *a) {
extern void **data_027e0058;
void *p; s32 x,y;
func_01ffb554((u8 *)*data_027e0058+0x1e30);func_01ffb3d0(-1);
p=*data_027e0058;
func_020cdfec(M2C_FIELD(p,s32 *,0x52d0),M2C_FIELD(p,volatile s16 *,0x52dc),M2C_FIELD(p,volatile s16 *,0x52de));
SetMapCursorVisible(0);
p=*data_027e0058;
x=M2C_FIELD(p,volatile s16 *,0x52dc);y=M2C_FIELD(p,volatile s16 *,0x52de);
M2C_FIELD(a,s16 *,0x6c)=GetAdjacentAllyDirections(M2C_FIELD(p,volatile s32 *,0x52d0),x,y);
M2C_FIELD(a,s16 *,0x6e)=3;
M2C_FIELD(a,s16 *,0x6e)=NextMapCursorOption(3,M2C_FIELD(a,s16 *,0x6c));
}
#pragma pop
/* One frame of the adjacent-ally selection: step the option within the direction
 * mask the object offers and store it back, then act on the key: confirm marks the
 * chosen neighbour with an ally marker and resumes the object's animation, cancel
 * deletes the object and puts the cursor target back where it was. */
void UpdateAdjacentAllySelection(void *option) {
    M2C_UNK UpdateMapCursorOption(s32 *, M2C_UNK);
    M2C_UNK DeleteSpriteObject(void *);
    void func_020d472c(void);
    void OpenMapActionMenu(void);
    M2C_UNK CreateAdjacentAllyMarker(s32);
    M2C_UNK Sprite_ResumeAnimation(void *);
    extern void **gCurrentMap;
    s32 selected;
    s32 action;
    s32 mask;

    mask = M2C_FIELD(option, s16 *, MAP_OPTION_DIR_MASK);
    selected = M2C_FIELD(option, s16 *, MAP_OPTION_SELECTED);
    action = UpdateMapCursorOption(&selected, mask);
    M2C_FIELD(option, s16 *, MAP_OPTION_SELECTED) = (s16)selected;
    if (action & 0x20) {
        DeleteSpriteObject(option);
        func_020d472c();
        OpenMapActionMenu();
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_X);
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_Y);
        return;
    }
    if (action & 0x10) {
        CreateAdjacentAllyMarker(M2C_FIELD(option, s16 *, MAP_OPTION_SELECTED));
        Sprite_ResumeAnimation(option);
    }
}

void func_020cc974(void) {
void func_020d468c(void);void func_020d472c(void);void BattleUpdateUnitCursor(void);extern void **gCurrentMap;
func_020d468c();func_020d472c();M2C_FIELD(*gCurrentMap,u16 *,0x52b4)=0;BattleUpdateUnitCursor();
}

s32 func_020cc9a4(void) {
    M2C_UNK func_0207a7a4(M2C_UNK, M2C_UNK);
    s32 IsMapCursorIdle();
    if (IsMapCursorIdle() != 0) {
        return 0;
    }
    func_0207a7a4(0, 4);
    return 1;
}

