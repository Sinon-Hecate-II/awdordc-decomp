/* 17 functions from 0x020C9B9C to 0x020CAB8C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "sound.h"

/* A selection menu (sprite object type 7): the highlighted entry and how many
   entries the menu has. */
typedef struct SelectionMenu {
    u8 pad00[0x6C];
    s16 selection;  /* +0x6C: highlighted entry */
    s16 count;      /* +0x6E: number of entries */
    s16 progress;   /* +0x70: animation/step counter */
} SelectionMenu;

/* The player-defeat presentation sprite (class gPlayerDefeatClass): the
   player being defeated, the victory-rule flag that defeated them, and the
   slot of their unit group the presentation has reached. */
typedef struct PlayerDefeatSprite {
    u8 pad00[0x6C];
    s16 player;   /* +0x6C player being defeated */
    s16 reason;   /* +0x6E PLAYER_DEFEAT_* flag that removed them */
    s16 unitSlot; /* +0x70 next slot of the player's unit group to handle */
} PlayerDefeatSprite;
static inline s32 RangeLeft(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52dc)-range;
}
static inline s32 RangeTop(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52de)-range;
}
static inline s32 RangeRight(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52dc)+range;
}
static inline s32 RangeRightLimit(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
s32 sum=M2C_FIELD(p,s16 *,0x52dc)+range;
s32 limit=M2C_FIELD(p,u16 *,0x5144)-1;
if(sum<limit)return RangeRight();
return limit;
}
static inline s32 RangeBottomLimit(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
s32 sum=M2C_FIELD(p,s16 *,0x52de)+range;
s32 limit=M2C_FIELD(p,u16 *,0x5146)-1;
if(sum<limit){
range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
return M2C_FIELD(*gCurrentMap,s16 *,0x52de)+range;
}
return limit;
}
static inline s32 RangeBottom(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52de)+range;
}

#pragma push
#pragma opt_propagation off
#pragma opt_strength_reduction off
void func_020c9b9c(void *arg0) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeee8[];
extern s8 gTerrainPropertyFlags[];
void SetPropertyOwnerTile(s32,s32,u8); void RebuildPropertyTile(s32,s32,s32);
void func_020cf2c8(void);void RefreshMapView(void);void func_020d2470(void);
u32 player; u16 i; u8 x,y; s32 kind,unit; u8 *map,*p,*rec,*tile;u32 old; u16 *rows; s32 row;
if(M2C_FIELD(arg0,s16 *,0x6e)!=2) player=0;
else {
map=(u8 *)*gCurrentMap;
p=map+0x67a4+M2C_FIELD(arg0,s16 *,0x6c)*0x8c;
tile=map+0x1420;
rows=(u16 *)(map+0x3758);
row=rows[p[0x2c]&127];
unit=(p[0x2b]&127)+row;
old=tile[unit];tile[unit]=data_ov000_021aeee8[M2C_FIELD(arg0,s16 *,0x6c)]|15;

map=(u8 *)*gCurrentMap;
p=map+0x67a4+M2C_FIELD(arg0,s16 *,0x6c)*0x8c;
player=(u32)((old&0xe0)<<11)>>16;
SetPropertyOwnerTile(p[0x2b]&127,p[0x2c]&127,(u8)data_ov000_021aeee8[M2C_FIELD(arg0,s16 *,0x6c)]);
func_020cf2c8();
}
for(i=0;i<99;i++){
map=(u8 *)*gCurrentMap;
rec=map+i*6;
kind=M2C_FIELD(rec,u8 *,0x6c60);x=M2C_FIELD(rec,u8 *,0x6c61);y=M2C_FIELD(rec,u8 *,0x6c62);
if(kind==255)break;
kind&=31;
if(gTerrainPropertyFlags[kind]){
p=map+x+M2C_FIELD(map+y*2,u16 *,0x3758);
if(data_ov000_021aeee8[M2C_FIELD(arg0,s16 *,0x6c)]==(M2C_FIELD(p,u8 *,0x1420)&0xe0)){
if(player && (unit=*p)!=0){
if(M2C_FIELD(map+(unit>>6)*0x8c,u8 *,0x6856)==M2C_FIELD(map+player*0x8c,u8 *,0x67ca)){
p=map+0x59a4+unit*14;
M2C_FIELD(p,u16 *,6)&=~0xf800;
}
}
switch(kind){case 15:
map=(u8 *)*gCurrentMap;
M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420)=data_ov000_021aeee8[player]|16;
RebuildPropertyTile(x,y,0);
SetPropertyOwnerTile(x,y,(u8)data_ov000_021aeee8[player]);
break;
default:
map=(u8 *)*gCurrentMap;
M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420)=kind|data_ov000_021aeee8[player];
SetPropertyOwnerTile(x,y,(u8)data_ov000_021aeee8[player]);
}
}
}
}
RefreshMapView();func_020cf2c8();func_020d2470();
M2C_FIELD(arg0,s16 *,0x70)=1;
}
#pragma pop
/* Removes the remaining units of a defeated player one per frame: each frame
   spawns a removal effect for the next slot of the player's unit group and
   moves the slot on; a player who was defeated because they had no units left
   is skipped, and once every slot has been visited the presentation resumes. */
void RemoveDefeatedPlayerUnits(PlayerDefeatSprite *sprite) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK CreateUnitRemovalEffect(void *, void *);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s16 slot;

    if (sprite->reason & (PLAYER_DEFEAT_NO_UNITS | PLAYER_DEFEAT_HUMAN)) {
        Sprite_ResumeAnimation(sprite);
        return;
    }
    while ((slot = sprite->unitSlot) < MAP_UNIT_GROUP_SCAN) {
        CreateUnitRemovalEffect((u8 *)*gCurrentMap + MAP_UNIT_RECORDS +
                                (slot + gPlayerUnitIdBase[sprite->player]) * MAP_UNIT_STRIDE, sprite);
        sprite->unitSlot += 1;
        return;
    }
    Sprite_ResumeAnimation(sprite);
}

void CreatePlayerDefeatSprite(u16 arg0, u16 arg1) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gPlayerDefeatClass;
    void *temp_r0;

    temp_r0 = CreateSpriteFromClass(&gPlayerDefeatClass, 7);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x6E) = arg1;
}

/* Mark `player` as defeated from the current turn by `reason` (the victory-rule
 * flag that removed them): the player record gets the turn and the reason, so
 * IsPlayerActive reports them out, and the battle-record counters are updated
 * for the human players involved. */
void MarkPlayerDefeated(s32 player, s32 reason) {
    M2C_UNK AddRecordValue(s32, s32);
    s32 IsPlayerHuman(s32);
    extern void **gCurrentMap;
    void *map;
    s32 recordOffset;
    s32 currentPlayer;

    map = *gCurrentMap;
    recordOffset = player * MAP_PLAYER_STRIDE;
    M2C_FIELD((u8 *)map + recordOffset, u16 *, MAP_PLAYER_STATES + PLAYER_REC_DEFEAT_TURN) = M2C_FIELD(map, u16 *, MAP_TURN);
    M2C_FIELD((u8 *)*gCurrentMap + recordOffset, s8 *, MAP_PLAYER_STATES + PLAYER_REC_DEFEAT_REASON) = reason;
    if (IsPlayerHuman(player) != 0) AddRecordValue(0x18, 1);
    currentPlayer = M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER);
    if (currentPlayer == player) return;
    if (IsPlayerHuman(currentPlayer) == 0) return;
    if (reason & 0x11) AddRecordValue(0x17, 1);
    if (!(reason & 2)) return;
    AddRecordValue(0x16, 1);
}

void ShowArmyDefeatMessage(s32 arg0) {
    typedef struct { s32 entries[4]; } Table;
    M2C_UNK ShowUiMessage(s32);
    extern void **gCurrentMap;
    extern Table gArmyDefeatMessageIds;
    Table sp0;
    sp0 = gArmyDefeatMessageIds;
    ShowUiMessage(sp0.entries[M2C_FIELD((u8 *)*gCurrentMap + arg0 * 0x8C, u8 *, 0x67C1) - 1]);
}

/* Starts the defeat presentation of `player`, who was removed for `reason` (a
 * PLAYER_DEFEAT_* victory-rule flag): shows the army's defeat message, creates
 * the presentation sprite and records the defeat, ends the turn when the
 * defeated player was the current one, and on a lost HQ schedules the battle-end
 * check. */
void StartPlayerDefeat(s32 player, s32 reason) {
    void ScheduleBattleEndCheck(void);
    void func_020a3498(void);
    void EndPlayerTurn(void);
    extern void **gCurrentMap;
    ShowArmyDefeatMessage(player);
    CreatePlayerDefeatSprite((u16)player, (u16)reason);
    MarkPlayerDefeated(player, reason);
    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) == player) {
        func_020a3498();
        EndPlayerTurn();
    }
    if (reason != PLAYER_DEFEAT_LOST) return;
    ScheduleBattleEndCheck();
}

/* Starts the defeat sequence for every active player a victory rule has removed:
   by giving up (or a team-mate being defeated first), by being a human player
   left without units and properties, by being left without units and properties,
   or by having the lost flag set. */
void StartPlayerDefeatSequences(void) {
    void StartPlayerDefeat(s32, s32);
    s32 IsPlayerActive(s16);
    s32 HasActivePlayerGivenUp(s16);
    s32 IsHumanPlayerStillFighting(s16);
    s32 IsPlayerStillFighting(s16);
    s32 IsPlayerHqIntact(s16);
    s16 player;
    player = 1;
    do {
        if (IsPlayerActive(player) != 0) {
            if (HasActivePlayerGivenUp(player) != 0) StartPlayerDefeat(player, PLAYER_DEFEAT_GAVE_UP);
            else if (IsHumanPlayerStillFighting(player) == 0) StartPlayerDefeat(player, PLAYER_DEFEAT_HUMAN);
            else if (IsPlayerStillFighting(player) == 0) StartPlayerDefeat(player, PLAYER_DEFEAT_NO_UNITS);
            else if (IsPlayerHqIntact(player) == 0) StartPlayerDefeat(player, PLAYER_DEFEAT_LOST);
        }
        player += 1;
    } while (player < 5);
}

/* Records the defeat of every active player a victory rule has removed: by
   giving up (or a team-mate being defeated first), by being a human player left
   without units and properties, by being left without units and properties, or
   by having the lost flag set.  Unlike StartPlayerDefeatSequences this records
   the defeat without starting the defeat presentation. */
void RecordDefeatedPlayers(void) {
    void MarkPlayerDefeated(s32, s32);
    s32 IsPlayerActive(s16);
    s32 HasActivePlayerGivenUp(s16);
    s32 IsHumanPlayerStillFighting(s16);
    s32 IsPlayerStillFighting(s16);
    s32 IsPlayerHqIntact(s16);
    s16 player;
    player = 1;
    do {
        if (IsPlayerActive(player) != 0) {
            if (HasActivePlayerGivenUp(player) != 0) MarkPlayerDefeated(player, PLAYER_DEFEAT_GAVE_UP);
            else if (IsHumanPlayerStillFighting(player) == 0) MarkPlayerDefeated(player, PLAYER_DEFEAT_HUMAN);
            else if (IsPlayerStillFighting(player) == 0) MarkPlayerDefeated(player, PLAYER_DEFEAT_NO_UNITS);
            else if (IsPlayerHqIntact(player) == 0) MarkPlayerDefeated(player, PLAYER_DEFEAT_LOST);
        }
        player += 1;
    } while (player < 5);
}

/* Returns the first player (1..4) whose property count has reached the map's
   property-count victory limit, or 0 when there is no limit or nobody has. */
s32 FindPlayerReachedPropertyLimit(void) {
    extern u8 gMapConfig[];
    extern void **gCurrentMap;
    u8 player;
    if (gMapConfig[MAPCONFIG_PROPERTY_LIMIT] == 0) return 0;
    player = 1;
    do {
        if ((u32)M2C_FIELD((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_PROPERTIES) >= (u32)gMapConfig[MAPCONFIG_PROPERTY_LIMIT]) return player;
        player += 1;
    } while (player < 5U);
    return 0;
}

s32 func_020ca1ec(void) {
extern void **gCurrentMap;
s32 i,j,mism; u8 buf[5]; u8 *cur; s32 offset; void **maps; s32 inner;
for(i=1;i<5;i++){buf[i]=0;if(IsPlayerActive(i)&&!HasActivePlayerGivenUp(i)&&IsHumanPlayerStillFighting(i)&&IsPlayerStillFighting(i)&&IsPlayerHqIntact(i))buf[i]=1;}
if(M2C_FIELD(*gCurrentMap,u8 *,0x5155)&4){
 for(i=1;i<5;i++){if(buf[i]){for(j=1;j<5;j++){if(i!=j&&IsPlayerActive(j)&&IsSameTeam(i,j)&&!buf[j]){buf[i]=0;SetPlayerGaveUp(i,1);}}}}
}
if(M2C_FIELD(*gCurrentMap,u8 *,0x5155)&16){
 for(i=1;i<5;i++){if(buf[i]){for(j=1;j<5;j++){if(i!=j&&IsPlayerHuman(j)&&IsSameTeam(i,j)&&!buf[j]){buf[i]=0;SetPlayerGaveUp(i,1);}}}}
}
maps=gCurrentMap; cur=buf+1; i=1; offset=140; do {if(*cur){mism=0;for(j=1,inner=140;j<5;j++,inner+=140){if(i==j)continue; if(!buf[j])continue; if(M2C_FIELD((u8 *)*maps+offset,u8 *,0x67ca)!=M2C_FIELD((u8 *)*maps+inner,u8 *,0x67ca))mism++;}if(mism==0)return 1;}cur++;offset+=140;}while(++i<5);
return 0;
}

void ScheduleBattleEndCheck(void) {
    extern void **gCurrentMap;
    u16 temp_r2;
    void *temp_r0;

    temp_r0 = *gCurrentMap;
    temp_r2 = M2C_FIELD(temp_r0, u16 *, 0x52B0);
    if (temp_r2 == 0x10) {
        return;
    }
    M2C_FIELD(temp_r0, u16 *, 0x52B2) = temp_r2;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 0x10;
}

void func_020ca4c0(void) {
    M2C_UNK AwardVictoryToPlayer(s32, M2C_UNK);
    M2C_UNK EnterBattleEnd();
    void StartPlayerDefeatSequences();
    void RecordDefeatedPlayers();
    s32 FindPlayerReachedPropertyLimit();
    s32 func_020ca1ec();
    s32 temp_r0;

    if (func_020ca1ec() != 0) {
        RecordDefeatedPlayers();
        EnterBattleEnd();
        return;
    }
    temp_r0 = FindPlayerReachedPropertyLimit();
    if (temp_r0 != 0) {
        AwardVictoryToPlayer(temp_r0, 0x20);
        return;
    }
    StartPlayerDefeatSequences();
}

/* Opens the target-selection dialog on its first entry: select entry 0 and take
   the number of entries from the battle map's target list, then aim the map
   cursor at the selected target's cell so the packed cursor cell and its HUD
   panel catch up, put the cursor back where the dialog was opened, and play the
   selection sound. */
void InitTargetSelectionMenu(void *dialog) {
    void *GetTargetPosition(s16);
    s16 GetTargetCount(void);
    void RefreshMapCursorCellCache(void);
    void PlaySoundEffect(s32);
    extern void **gCurrentMap;
    s16 savedX;
    s16 savedY;
    MapTargetEntry *target;
    void *map;

    ((SelectionMenu *)dialog)->selection = 0;
    ((SelectionMenu *)dialog)->count = GetTargetCount();
    map = *gCurrentMap;
    savedX = M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X);
    savedY = M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y);
    target = (MapTargetEntry *)GetTargetPosition(((SelectionMenu *)dialog)->selection);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X) = target->x;
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y) = target->y;
    RefreshMapCursorCellCache();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X) = savedX;
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y) = savedY;
    PlaySoundEffect(SOUND_MENU_SELECT);
}

/* Per-frame update of the target-list selection menu: read the confirm, cancel
   and menu keys plus the touch state, then move the map cursor to the selected
   entry or close the menu. */
void UpdateUnitSelectionMenu(void *dialog) {
    M2C_UNK func_020be010(void);
    s32 IsMapViewScrolling(void);
    s32 func_020cccb8(void);
    s32 GetKeyActionFlags(void);
    s32 GetTouchActionFlags(s16);
    s32 func_020d46cc(void);
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK StepMapViewToTile(s16, s16);
    void *GetTargetPosition(s16);
    M2C_UNK CreateTargetCursor(s16, s16);
    s32 CreateMapMenu(void);
    void HandleUiCancel(void);
    void MoveSelectionWithKeys(void *, s16);
    void UpdateSelectionFromTouch(void *, s16);
    void PlaySoundEffect(s32);
    void MapCursor_StepTowardTarget(s32);
    void DrawUnitInfoPanel(s32);
    M2C_UNK func_020cf828(M2C_UNK);
    M2C_UNK func_0207a7a4(s32, s32);
    M2C_UNK StepMapCursorAndNotify(s32, s32);
    extern void **gCurrentMap;
    extern s32 gMapCursorOptionValue;

    s32 saved = ((SelectionMenu *)dialog)->selection;
    s32 flags = 0;
    s16 count = ((SelectionMenu *)dialog)->count;
    s32 merged;
    s32 oldval;
    void *target;

    if (count > 1) {
        func_020be010();
    }
    if (IsMapViewScrolling() != 0) return;
    if (func_020cccb8() != 0) return;

    flags |= GetKeyActionFlags();
    merged = flags | GetTouchActionFlags(count);

    if (merged & 0x20) {
        if (!func_020d46cc()) {
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
        }
        gMapCursorOptionValue = -1;
        DeleteSpriteObject(dialog);
        StepMapViewToTile(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                      M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
        return;
    }
    if (merged & 0x10) {
        void *target;
        gMapCursorOptionValue = ((SelectionMenu *)dialog)->selection;
        target = GetTargetPosition(((SelectionMenu *)dialog)->selection);
        CreateTargetCursor(M2C_FIELD(target, s16 *, 0x4), M2C_FIELD(target, s16 *, 0x6));
        DeleteSpriteObject(dialog);
        return;
    }
    if (merged & 0x100) {
        CreateMapMenu();
        return;
    }
    if (merged & 0x40) {
        HandleUiCancel();
    }
    oldval = saved;
    MoveSelectionWithKeys(&saved, count);
    UpdateSelectionFromTouch(&saved, count);
    if (oldval != saved) {
        PlaySoundEffect(0x10019);
    }
    ((SelectionMenu *)dialog)->selection = (s16)saved;
    target = GetTargetPosition(((SelectionMenu *)dialog)->selection);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(target, s16 *, 0x4);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(target, s16 *, 0x6);
    StepMapViewToTile(M2C_FIELD(target, s16 *, 0x4), M2C_FIELD(target, s16 *, 0x6));
    if (IsMapViewScrolling() != 0) return;
    MapCursor_StepTowardTarget(2);
    DrawUnitInfoPanel(1);
}

void func_020ca77c(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b1fc;
    CreateSpriteObject(&data_0212b1fc, arg0);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void func_020ca794(void *arg0) {
extern void **gCurrentMap;
void func_0209f8c0(void);void FillMapLayer(s32);s32 func_020a7714(void *);void func_0209f8f8(s32,s32,s32,s32);s16 GetTargetCount(void);void PlaySoundEffect(s32);
s32 y1,x0,x1,dist,v,x,y; void *p; s32 range; void *centre;
M2C_FIELD(arg0,s16*,0x6c)=0;
func_0209f8c0();FillMapLayer(-1);
p=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
if(M2C_FIELD(p,s16 *,0x52dc)-range<0)x0=0;
else {p=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));x0=M2C_FIELD(p,s16 *,0x52dc)-range;}
centre=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
if(M2C_FIELD(centre,s16 *,0x52de)-range<0)y=0;
else {p=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));y=M2C_FIELD(p,s16 *,0x52de)-range;}
x1=RangeRightLimit();
y1=RangeBottomLimit();
for(;y<=y1;y++){for(x=x0;x<=x1;x++){
p=*gCurrentMap;
v=M2C_FIELD(p,s16*,0x52dc)-x;if(v<=0)v=x-M2C_FIELD(p,s16*,0x52dc);dist=0;dist+=v;
v=M2C_FIELD(p,s16*,0x52de)-y;if(v<=0)v=y-M2C_FIELD(p,s16*,0x52de);dist=dist+v;
if(dist<0)continue; if(dist<=func_020a7714(M2C_FIELD(p,void **,0x52d0))){
func_0209f8f8(x,y,0,0);
M2C_FIELD((u8*)*gCurrentMap+y*4,u8 **,0x52e8)[x]=1;
}
}}
M2C_FIELD(arg0,s16*,0x6e)=GetTargetCount();
PlaySoundEffect(0x10019);
M2C_FIELD(*gCurrentMap,s16*,0x52c2)=M2C_FIELD(*gCurrentMap,s16*,0x52dc);
M2C_FIELD(*gCurrentMap,s16*,0x52c4)=M2C_FIELD(*gCurrentMap,s16*,0x52de);
}
#pragma pop
/* Handles a confirmation-style selection menu: moves the cursor, opens detail view on confirm, or signals cancel. */
void func_020caa34(void *dialog) {
    M2C_UNK func_020bdfdc(void);
    s32 IsMapCursorIdle(void);
    s32 GetMapCursorKeyAction(void);
    s32 GetMapCursorTouchAction(void);
    M2C_UNK StepMapViewToTile(s16, s16);
    M2C_UNK Sprite_ResumeAnimation(void *);
    s32 func_0209f944(s16, s16);
    M2C_UNK func_020d468c(void);
    M2C_UNK CreateTargetCursor(s16, s16);
    M2C_UNK SetBattleCommand(s32, u8, u8, u8);
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK CreateMapMenu(void);
    M2C_UNK func_020cf828(M2C_UNK);
    M2C_UNK func_0207a7a4(s32, s32);
    M2C_UNK StepMapCursorAndNotify(s32, s32);
    extern void **gCurrentMap;
    extern s32 gMapCursorOptionValue;

    s32 flags = 0;

    func_020bdfdc();
    if (IsMapCursorIdle() != 0) {
        flags |= GetMapCursorKeyAction();
        flags |= GetMapCursorTouchAction();
        if (flags & 0x20) {
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
            gMapCursorOptionValue = -1;
            StepMapViewToTile(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                          M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
            Sprite_ResumeAnimation(dialog);
            return;
        }
        if (flags & 0x10) {
            if (func_0209f944(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                               M2C_FIELD(*gCurrentMap, s16 *, 0x52C4)) != 0) {
                func_020d468c();
                CreateTargetCursor(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                              M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
                SetBattleCommand(0x15,
                    M2C_FIELD(*gCurrentMap, u8 *, 0x52D4),
                    (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                    (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
                DeleteSpriteObject(dialog);
                return;
            }
        }
        if (flags & 0x100) {
            CreateMapMenu();
            return;
        }
    }
    func_020cf828(0x1001a);
    func_0207a7a4(1, 4);
    StepMapCursorAndNotify(2, 10);
}

