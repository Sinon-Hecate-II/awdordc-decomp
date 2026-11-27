/* 39 functions from 0x020CBACC to 0x020CC9C8 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"
#include "map_effect.h"
#include "ov000_ai.h"
static inline s32 visibleCB(void *p,s32 x,s32 y) {
u32 n;
if (M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*140,u8 *,0x67c3)&2)return 1;
n=x+M2C_FIELD((u8 *)p+y*2,u16 *,0x3758);
return (u8)(M2C_FIELD((u8 *)p+(n>>3),u8 *,0x5201)&(1<<(n&7)))!=0;
}

typedef struct { u8 kind:6; u8 flags:2; } UnkCBUnit;

typedef struct { u8 unk_0 : 6; u8 unk_6 : 2; } Unk020cbc88;

/* The target-cursor sprite (class gTargetCursorClass): the map tile it was
   opened on, kept so its update can place the map-view cursor there. */
typedef struct TargetCursor {
    u8  pad00[0x38];
    s32 tileX; /* +0x38 target map tile x */
    s32 tileY; /* +0x3C target map tile y */
} TargetCursor;

/* Stepping overlay task, the supply-marking variant: scan the current player's units
   from the saved index and find the first one worth marking - a transport (kind 21/23)
   whose cargo has a cost or a value, or a unit a friendly supply unit can refill -
   highlight its tile and save the next index; at the end of the list retire the task. */
void MarkSupplyUnitTiles(void *state){extern void **gCurrentMap;s32 IsMapActionEffectActive(void *);s32 MarkTransportCargo(void *);s32 CanBeSupplied(void *);s32 RefillSuppliedUnit(void *);M2C_UNK Sprite_ResumeAnimation(void *);
u16 i;void *p,*q;u32 k;
if(IsMapActionEffectActive(state))return;
for(i=M2C_FIELD(state,u16 *,0x50);i<51;i++){
p=*gCurrentMap;q=(u8 *)p+0x59a4+(M2C_FIELD(p,u16 *,0x52a8)+i)*14;
k=((UnkCBUnit *)q)->kind;if(!k)continue;if(M2C_FIELD(q,u16 *,4)&8)continue;
if(k==23||k==21){if(MarkTransportCargo(q)){M2C_FIELD(state,u16 *,0x50)=i+1;break;}}
if(CanBeSupplied(q)&&RefillSuppliedUnit(q)){M2C_FIELD(state,u16 *,0x50)=i+1;break;}
}if(i==51)Sprite_ResumeAnimation(state);
}

/* Return the map view to the tile the current player left its cursor on, but only
 * when that player's cursor belongs to the local human team. */
void StepMapViewToCurrentPlayerCursor(void) {
 extern void **gCurrentMap;
 void *map;
 void *player;
 if (!IsPlayerCursorOwner(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER))) return;
 map=*gCurrentMap;
 player=(u8 *)map+MAP_PLAYER_STATES+M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE;
 StepMapViewToTile(M2C_FIELD(player,u8 *,PLAYER_REC_CURSOR_X),M2C_FIELD(player,u8 *,PLAYER_REC_CURSOR_Y));
}

/* Start the turn intro's upkeep sprite on layer 7: its script holds the map view,
 * marks the units that a supply unit refuels or upgrades, pans the view to the
 * current player's cursor and refreshes the map. */
void CreateTurnIntroUpkeepSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTurnIntroUpkeepScript;
    CreateSpriteFromClass(&gTurnIntroUpkeepScript, 7);
}

#pragma opt_common_subs off
/* Unit-removal effect: play a type-5 explosion on the unit's tile, then destroy
 * the unit and refresh the map. */
void UnitRemovalEffect_Start(void *effect) {
 extern void **gCurrentMap;
 M2C_UNK CreateExplosionEffect(s32,s32,s32,s32);
 void DestroyUnit(s32);
 s32 RefreshMapView(void);
 void *unit=M2C_FIELD(effect,void **,0x34);
 s32 unitIndex;
 CreateExplosionEffect(M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2),5,effect);
 if (!unit) unitIndex=0;
 else unitIndex=((s32)unit-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;
 DestroyUnit(unitIndex);
 RefreshMapView();
}
#pragma opt_common_subs reset
/* Play a unit's removal explosion: skip empty unit slots (kind 0) and units
 * loaded in a transport, otherwise create the unit-removal sprite object and
 * attach the unit to it. */
void CreateUnitRemovalEffect(void *unit) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK gUnitRemovalSpriteClass;

    if (((UnkCBUnit *) unit)->kind == 0) return;
    if (M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) & UNIT_FLAG_LOADED) return;
    M2C_FIELD(CreateSpriteObject(&gUnitRemovalSpriteClass), void **, 0x34) = unit;
}

void FuelCrashEffect_StepMapViewToUnit(void *arg0) {
    M2C_UNK SpriteState_StepMapViewToTile(s32);
    SpriteState_StepMapViewToTile(M2C_FIELD(arg0, s32 *, 0x34));
}

void FuelCrashEffect_ExplodeUnit(void *arg0) {
    M2C_UNK ExplodeUnit(s32);
    ExplodeUnit(M2C_FIELD(arg0, s32 *, 0x34));
}

/* Create the fuel-crash effect for `unit`: its sprite pans the map view to the
 * unit's tile and then explodes it.  `task` is the map-action task that spotted
 * the crash. */
void CreateFuelCrashEffect(void *unit, void *task) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK gFuelCrashSpriteClass;

    ((FuelCrashEffect *)CreateSpriteObject(&gFuelCrashSpriteClass))->unit = unit;
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

/* Spawn the scripted sprite that runs the turn-intro upkeep and battle-end checks. */
void CreateTurnIntroSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTurnIntroSpriteClass;
    CreateSpriteFromClass(&gTurnIntroSpriteClass, 7);
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
s32 IsWithinScreenBounds(s32,s32);
void *map=*gCurrentMap,*sprite; s32 x=M2C_FIELD(map,s16 *,0x52dc),y=M2C_FIELD(map,s16 *,0x52de); if(!visibleCB(map,x,y))return;
if(!IsWithinScreenBounds(x,y))return;
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

/* Set the rules message the battle map screen shows: campaign battles show
 * their own message, every other battle the standard one. */
void SetBattleRulesMessage(void) {
    void SetUiMessageText(s32);
    s32 IsCampaignBattleRules(void);

    if (IsCampaignBattleRules() != 0) {
        SetUiMessageText(TEXT_ID_BATTLE_RULES_CAMPAIGN);
        return;
    }
    SetUiMessageText(TEXT_ID_BATTLE_RULES);
}

void func_020cbfe4(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b5f4;
    CreateSpriteFromClass(&data_0212b5f4, 7);
}

/* Mark the battle's current player as having given up, then schedule the check
 * that ends the battle once only one player is left (AI command 18's handler). */
void GiveUpCurrentPlayerAndScheduleBattleEnd(void) {
 extern void **gCurrentMap;
 SetPlayerGaveUp(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),1);
 ScheduleBattleEndCheck();
}

/* AI command 19's handler: award the battle to the current player because the
 * opponent gave up. */
void AwardVictoryToCurrentPlayerForGiveUp(void) {
    M2C_UNK AwardVictoryToPlayer(u16, M2C_UNK);
    extern void **gCurrentMap;
    AwardVictoryToPlayer(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), PLAYER_DEFEAT_GAVE_UP);
}

/* Mark the current player as having given up, then queue battle command 17,
 * which destroys the unit under the map cursor. */
void GiveUpCurrentPlayerAndDestroyUnit(void) {
extern void **gCurrentMap;
SetPlayerGaveUp(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),1);
SetBattleCommand(AI_COMMAND_DESTROY_UNIT,0,0,0);
}

/* Spawn the give-up script in layer 7: it takes a hold on the map view, waits
 * for the player to confirm, then makes the current player give up, destroys
 * the unit under the cursor and schedules the battle-end check. */
void CreateGiveUpScript(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gGiveUpScript;
    CreateSpriteFromClass(&gGiveUpScript, 7);
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

/* The map view's interactive step: keep the cursor driven by input and the map
 * view scrolling at speed 8; once the cursor settles, a confirm or cancel key
 * plays the close sound and finishes the task, otherwise note that the view must
 * recentre the cursor when it closes. */
void MapViewCursorStep(MapViewTask *task) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK UpdateMapCursorInput();
    extern u16 *gKeyState;

    UpdateMapCursorInput();
    func_0207a7a4(1, 8);
    if (IsMapCursorIdle() != 0) {
        if (!(*gKeyState & (KEY_A | KEY_B | KEY_START))) {
            return;
        }
        PlaySoundEffect(0x10018);
        Sprite_ResumeAnimation(task);
        return;
    }
    task->unk3A = 1;
}

/* First step of hiding the map view: redraw the battle map, blank the map-view
 * sprite layers (marking each dirty so the engine uploads it empty), delete the
 * map view's preview panel sprites, then fade out over six frames. */
void BeginMapViewClose(MapViewTask *task) {
    extern void *gCur3DSpriteEngine;

    RefreshMapView();
    Clear3DSpriteLayer(1);
    ((DS3DSpriteEngine *)gCur3DSpriteEngine)->layerDirty |= 2;
    Clear3DSpriteLayer(2);
    ((DS3DSpriteEngine *)gCur3DSpriteEngine)->layerDirty |= 4;
    Clear3DSpriteLayer(3);
    ((DS3DSpriteEngine *)gCur3DSpriteEngine)->layerDirty |= 8;
    RemoveMapViewSprites();
    task->fadeTimer = 6;
}

/* One frame of the battle map fade-out: count the fade timer down, set the 3D
 * sprite bank to top priority with no split rows and the remaining count as its
 * blend level, then resume the task's animation when the timer runs out. */
void MapFadeOutStep(MapViewTask *task) {
    extern void *gCur3DSpriteEngine;
    M2C_UNK Sprite_ResumeAnimation(void *);
    u16 *volatile p;
    s32 frames;

    task->fadeTimer--;
    frames = task->fadeTimer;
    p = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *p = (*p & ~0xC0) | 0xC0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsAbove = 0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsBelow = 0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->filler_53 = (u8)frames;
    if (!task->fadeTimer) Sprite_ResumeAnimation(task);
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
    LoadUiGraphics();
    M2C_FIELD(*gCurrentMap, u16 *, MAP_MODE) = 0;
}

/* Spawn the scripted sprite that opens and controls the map-view screen. */
void CreateMapViewSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMapViewSpriteClass;

    CreateSpriteFromClass(&gMapViewSpriteClass, 7);
}

/* Target-cursor update: place the map-view cursor on the tile the target cursor
   sprite was opened on. */
void TargetCursor_PlaceCursor(TargetCursor *cursor) {
    M2C_UNK MapView_SetCursorPosition(s16, s16, M2C_UNK);
    MapView_SetCursorPosition((s16)(cursor->tileX * 0x10), (s16)(cursor->tileY * 0x10), MAP_CURSOR_KIND_TARGET);
}

/* Create the target cursor sprite on the target tile (x, y), unless one is
 * already on screen; the sprite keeps the tile it was opened on at +0x38/+0x3C. */
void CreateTargetCursor(s32 x, s32 y) {
    extern M2C_UNK gTargetCursorClass;
    s32 FindObjectByClass(M2C_UNK *);
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *cursor;

    if (FindObjectByClass(&gTargetCursorClass)) return;
    cursor = (void *)CreateSpriteFromClass(&gTargetCursorClass, 7);
    M2C_FIELD(cursor, s32 *, 0x38) = x;
    M2C_FIELD(cursor, s32 *, 0x3c) = y;
}

void CancelMapCursorAnimation(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gTargetCursorClass;
    DeleteSpriteObjectsOfClass(&gTargetCursorClass);
}

/* Confirms the action on the battle map's current target: an empty cell queues a
 * move command (kind 4) with the unit id, a cell holding a unit queues an attack
 * command (kind 5) with the tile; a human player's cursor distance to the target
 * then records one or two cursor-movement stats. */
void SubmitCursorTarget(void){
extern s32 gMapCursorOptionValue;extern void **gCurrentMap;
s32 IsMapCommandPending(void);void ClearMapCommandPending(void);void OpenMapActionMenu(void);void SetMapCommandPending(void);
void *GetTargetPosition(void);s32 IsPlayerHuman(u16);void AddRecordValue(s32,s32);
MapTargetEntry *target; s32 distance;
if(gMapCursorOptionValue<0){if(IsMapCommandPending())ClearMapCommandPending();else OpenMapActionMenu();return;}
target=(MapTargetEntry *)GetTargetPosition();
if(target->value==0){
SetMapCommandPending();
SetBattleCommand(4,M2C_FIELD(*gCurrentMap,u8 *,MAP_CURSOR_UNIT_ID),target->id&255,0);
}else{
SetMapCommandPending();
SetBattleCommand(5,M2C_FIELD(*gCurrentMap,u8 *,MAP_CURSOR_UNIT_ID),target->x&255,target->y&255);
}
if(!IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))return;
distance=(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_X)-target->x)+(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_Y)-target->y);
if(distance<0)distance=-distance;
if(distance==0)return;
if(distance==1)AddRecordValue(7,1);else AddRecordValue(8,1);
}

/* Spawn the attack-target-selection script in layer 7: it holds the map view,
 * builds the list of targets in range, opens the target-selection menu and
 * submits the chosen target. */
void CreateTargetSelectionSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTargetSelectionScript;
    CreateSpriteFromClass(&gTargetSelectionScript, 7);
}

/* Whether a battle preview is on screen: either the full battle animation or
 * the quick map battle has a live sprite object. */
s32 IsBattlePreviewActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gBattlePreviewMapDef;
    extern M2C_UNK gBattlePreviewFullDef;
    if ((FindObjectByClass(&gBattlePreviewFullDef) != 0) || (FindObjectByClass(&gBattlePreviewMapDef) != 0)) {
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
    void ReleaseMapViewHold(void);
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
        ReleaseMapViewHold();
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

/* Return the map to its normal cursor after a map-menu action: mark the command
 * pending, release the map-view hold, reset the input mode to the cursor and
 * refresh the unit under the cursor. */
void ResumeMapCursorAfterCommand(void) {
    void SetMapCommandPending(void);
    void ReleaseMapViewHold(void);
    void BattleUpdateUnitCursor(void);
    extern void **gCurrentMap;

    SetMapCommandPending();
    ReleaseMapViewHold();
    M2C_FIELD(*gCurrentMap, u16 *, MAP_MODE) = MAP_MODE_CURSOR;
    BattleUpdateUnitCursor();
}

/* If the map cursor's scroll is still running, advance it by 4 pixels and return
 * 1; return 0 once the view has settled. */
s32 StepMapViewScrollIfMoving(void) {
    M2C_UNK func_0207a7a4(M2C_UNK, M2C_UNK);
    s32 IsMapCursorIdle();

    if (IsMapCursorIdle() != 0) {
        return 0;
    }
    func_0207a7a4(0, 4);
    return 1;
}

