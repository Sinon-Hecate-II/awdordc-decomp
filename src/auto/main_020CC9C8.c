/* 31 functions from 0x020CC9C8 to 0x020CD8A8 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"


/* Starts a zoom-in or zoom-out of the map view: picks the new zoom level and
 * the view size it gives, clamps the view scroll so the cursor stays visible,
 * and initialises the transition object (start/end zoom and scroll, 16-frame
 * timer) that Func_020ccbc0 then animates. */
void BeginMapZoom(void *transition) {
 extern s32 *gCurrentMap;s32 GetViewZoom(s32);s32 GetViewHeightForZoom(s32);s32 GetViewWidthForZoom(s32);void PlaySoundEffect(s32);
 s32 oldHeight,oldWidth,newHeight,newWidth,x,y,width,height,map,dx,dy;
 if(GetViewZoom(*gCurrentMap+MAP_VIEW_ZOOM)==0) {M2C_FIELD(transition,s32 *,0x5c)=0;M2C_FIELD(transition,s32 *,0x60)=128;PlaySoundEffect(0x1001e);}
 else {M2C_FIELD(transition,s32 *,0x5c)=128;M2C_FIELD(transition,s32 *,0x60)=0;PlaySoundEffect(0x1001f);}
 oldHeight=GetViewHeightForZoom(M2C_FIELD(transition,s32 *,0x5c));oldWidth=GetViewWidthForZoom(M2C_FIELD(transition,s32 *,0x5c));
 newHeight=GetViewHeightForZoom(M2C_FIELD(transition,s32 *,0x60));newWidth=GetViewWidthForZoom(M2C_FIELD(transition,s32 *,0x60));
 map=*gCurrentMap;x=M2C_FIELD(map,s16 *,MAP_VIEW_X);y=M2C_FIELD(map,s16 *,MAP_VIEW_Y);
 dx=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_X)-(x>>4);dy=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_Y)-(y>>4);
 M2C_FIELD(transition,s16 *,0x6c)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X);
 M2C_FIELD(transition,s16 *,0x6e)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X);
 M2C_FIELD(transition,s16 *,0x70)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y);
 M2C_FIELD(transition,s16 *,0x72)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y);
 if(dx>=newWidth-2) {
 map=*gCurrentMap;width=M2C_FIELD(map,u16 *,MAP_WIDTH);
 x=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_X);if(x<width-3)width=x+3;
 M2C_FIELD(transition,s16 *,0x6e)=(width-newWidth)<<4;
 }
 if(dy>=newHeight-2) {
 map=*gCurrentMap;height=M2C_FIELD(map,u16 *,MAP_HEIGHT);
 y=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_Y);if(y<height-3)height=y+3;
 M2C_FIELD(transition,s16 *,0x72)=(height-newHeight)<<4;
 }
 if(oldWidth<newWidth) {
 width=M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);
 if(width<newWidth+(M2C_FIELD(transition,s16 *,0x6e)>>4))M2C_FIELD(transition,s16 *,0x6e)=(width-newWidth)<<4;
 }
 if(oldHeight<newHeight) {
 height=M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);
 if(height<newHeight+(M2C_FIELD(transition,s16 *,0x72)>>4))M2C_FIELD(transition,s16 *,0x72)=(height-newHeight)<<4;
 }
 M2C_FIELD(transition,s32 *,0x64)=0;M2C_FIELD(transition,s32 *,0x68)=15;
}

/* One frame of the map-view zoom animation BeginMapZoom set up: advance the
 * frame counter, ease the zoom level (transition+0x5c..0x60) and the view
 * scroll (transition+0x6c/0x6e = x, +0x70/0x72 = y, from..to) towards their
 * targets and, once the last frame is reached, run the transition's end
 * callback. */
void StepMapZoom(void *transition) {
    extern s32 *gCurrentMap;
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void SetViewZoom(s32, s32);
    void Sprite_ResumeAnimation(void *);
    s32 view;

    M2C_FIELD(transition, s32 *, 0x64)++;
    SetViewZoom(*gCurrentMap + 0x6ef8, EaseInterpolate(4, M2C_FIELD(transition, s32 *, 0x5c), M2C_FIELD(transition, s32 *, 0x60), M2C_FIELD(transition, s32 *, 0x64), M2C_FIELD(transition, s32 *, 0x68)));
    view = *gCurrentMap + 0x5120;
    M2C_FIELD(view, s16 *, 0x28) = EaseInterpolate(4, M2C_FIELD(transition, s16 *, 0x6c), M2C_FIELD(transition, s16 *, 0x6e), M2C_FIELD(transition, s32 *, 0x64), M2C_FIELD(transition, s32 *, 0x68));
    view = *gCurrentMap + 0x5120;
    M2C_FIELD(view, s16 *, 0x2a) = EaseInterpolate(4, M2C_FIELD(transition, s16 *, 0x70), M2C_FIELD(transition, s16 *, 0x72), M2C_FIELD(transition, s32 *, 0x64), M2C_FIELD(transition, s32 *, 0x68));
    if (M2C_FIELD(transition, s32 *, 0x64) == M2C_FIELD(transition, s32 *, 0x68)) Sprite_ResumeAnimation(transition);
}

void func_020ccc94(void) {
    M2C_UNK UpdateCursorCellDisplayMode();
    UpdateCursorCellDisplayMode();
}

/* Spawn the map menu's zoom-control sprite on the default sprite layer. */
void CreateMapMenu(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMapZoomClass;
    CreateSpriteFromClass(&gMapZoomClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Nonzero while the map-view zoom transition is running (an object of the map
 * zoom sprite class exists). */
u8 IsMapZoomRunning(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gMapZoomClass;
    u8 running;

    if (FindObjectByClass(&gMapZoomClass) != 0) {
        running = 1;
    } else {
        running = 0;
    }
    return running;
}

#pragma opt_strength_reduction off
/* Counts the map's destroyed stone/pipe tiles and hidden-terrain cells: with 99
 * or more of them the map's hidden terrain is gone, so it must not be saved. */
s32 CanSaveHiddenTerrainMap(void) {
extern s32 *gCurrentMap;
s32 IsPropertyTerrainKind(s32);
s32 hidden=0,x,y,map=*gCurrentMap;
for(y=0;y<M2C_FIELD(map,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(map,u16 *,0x5144);x++){
if(IsPropertyTerrainKind(M2C_FIELD(M2C_FIELD(map+(y<<1),u16 *,0x3758)+(map+x),u8 *,0x1420)&31) || M2C_FIELD(M2C_FIELD(*gCurrentMap+(y<<1),u16 *,0x3758)+(*gCurrentMap+x),u8 *,0x539c))hidden++;
map=*gCurrentMap;
}
}
if(hidden>=99)return 0;return 1;
}
#pragma opt_strength_reduction reset
/* Tell the link peers the battle has ended: post a match start request tagged
 * with the battle-end match id ('GMED'), owned by `owner`. */
void SendBattleEndStartRequest(s32 owner) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    Link_CreateStartRequest(MATCH_ID_GMED, owner);
}

/* Once the battle has ended, spawn the battle-end request object under `owner`:
 * its script sends the link start request that tells the peers the battle is
 * over.  Does nothing while the battle is still running. */
void SpawnBattleEndRequest(s32 owner) {
    void CreateSpriteObject(void *, s32);
    extern u8 gBattleEndState;
    extern M2C_UNK gBattleEndRequestClass;
    if (gBattleEndState == 0) return;
    CreateSpriteObject(&gBattleEndRequestClass, owner);
}

/* Battle-results screen entry for results sprite `sprite`: compute the battle's
 * win ratings, record its outcome, then play the sprite's defeat animation when
 * the player lost a campaign battle, its normal one otherwise. */
void ShowBattleResultsScreen(s32 sprite) {
    void BattleResults_ComputeRatings(void);
    void func_0209c8d4(void);
    void GotoSpriteAnimationLabel(s32, s32);
    u8 IsCampaignBattleRules(void);
    u8 DidPlayerLose(void);
    BattleResults_ComputeRatings();
    func_0209c8d4();
    if (IsCampaignBattleRules() && DidPlayerLose()) {
        GotoSpriteAnimationLabel(sprite, 1);
    } else {
        GotoSpriteAnimationLabel(sprite, 0);
    }
}

/* Creates the battle-finish sequence object: its script holds the map view,
 * runs the map-clear effect, shows the results screen, saves and sends the
 * battle-end request before releasing the hold. */
void CreateBattleFinishSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gBattleFinishSpriteClass;
    CreateSpriteFromClass(&gBattleFinishSpriteClass, 7);
}

/* Returns a player's battle outcome (BATTLE_RESULT_*): handles the link-battle
 * end conditions from the battle-end state first, otherwise counts the players
 * still active and compares armies to decide win/lose/draw. */
s32 GetPlayerResult(s32 player) {
extern s32 *gCurrentMap; extern u8 gBattleEndState;
s32 IsPlayerPresent(s32);s32 IsPlayerHuman(s32);s32 IsPlayerActive(s32);s32 GetLinkMode(void);s32 IsOverlayEventSet(s32);
s32 totalCount=0, activeCount=0,inactiveCount=0;u8 army=M2C_FIELD((u8*)*gCurrentMap+player*MAP_PLAYER_STRIDE,u8*,PLAYER_ARMY_OFF);s32 active,i,off;
if(!IsPlayerPresent(player))return BATTLE_RESULT_NONE;
if((&gBattleEndState)[BATTLE_END_ENDED]){
active=1;for(i=1;i<5;i++)if(IsPlayerHuman(i))active=i;
if(GetLinkMode()==1){if((&gBattleEndState)[BATTLE_END_FLAG1])return BATTLE_RESULT_DRAW;if((&gBattleEndState)[BATTLE_END_FLAG2])return BATTLE_RESULT_DRAW;}
if(GetLinkMode()==2){
if(active==player){
if((&gBattleEndState)[BATTLE_END_FLAG1])return BATTLE_RESULT_LOSE;
if((&gBattleEndState)[BATTLE_END_FLAG2]){
if(!(&gBattleEndState)[BATTLE_END_FLAG3])return BATTLE_RESULT_LOSE;
{s32 other,otherStep;for(other=1,otherStep=MAP_PLAYER_STRIDE;other<5;other++,otherStep+=MAP_PLAYER_STRIDE)if(IsPlayerPresent(other)&&IsOverlayEventSet(other-1)){if(army==M2C_FIELD((u8*)*gCurrentMap+otherStep,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_LOSE;}
}return BATTLE_RESULT_WIN;
}
}else{
if((&gBattleEndState)[BATTLE_END_FLAG1]){if(army!=M2C_FIELD((u8*)*gCurrentMap+active*MAP_PLAYER_STRIDE,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_WIN;return BATTLE_RESULT_LOSE;}
if((&gBattleEndState)[BATTLE_END_FLAG2]){
if(!(&gBattleEndState)[BATTLE_END_FLAG3]){if(army!=M2C_FIELD((u8*)*gCurrentMap+active*MAP_PLAYER_STRIDE,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_WIN;return BATTLE_RESULT_LOSE;}
if(IsOverlayEventSet(player-1))return BATTLE_RESULT_LOSE;
{s32 other,otherStep;for(other=1,otherStep=MAP_PLAYER_STRIDE;other<5;other++,otherStep+=MAP_PLAYER_STRIDE)if(IsPlayerPresent(other)&&IsOverlayEventSet(other-1)){if(army==M2C_FIELD((u8*)*gCurrentMap+otherStep,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_LOSE;}
}return BATTLE_RESULT_WIN;
}
}
}
}
for(i=1;i<5;i++)if(IsPlayerPresent(i)){if(IsPlayerActive(i))activeCount++;else inactiveCount++;totalCount++;}
if(activeCount==totalCount)return BATTLE_RESULT_DRAW;if(inactiveCount==totalCount)return BATTLE_RESULT_DRAW;
{s32 other,otherStep;for(other=1,otherStep=MAP_PLAYER_STRIDE;other<5;other++,otherStep+=MAP_PLAYER_STRIDE)if(IsPlayerPresent(other)&&IsPlayerActive(other)){if(army==M2C_FIELD((u8*)*gCurrentMap+otherStep,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_WIN;}
}return BATTLE_RESULT_LOSE;
}

/* A player's battle result as seen against another player: BATTLE_RESULT_NONE
 * unless both players are present, different, and on opposing armies. */
s32 GetPlayerResultAgainst(s32 player, s32 other) {
    extern s32 *gCurrentMap;
    s32 players;
    if (!IsPlayerPresent(player)) return BATTLE_RESULT_NONE;
    if (!IsPlayerPresent(other)) return BATTLE_RESULT_NONE;
    if (player == other) return BATTLE_RESULT_NONE;
    players = *gCurrentMap + MAP_PLAYER_STATES;
    if (M2C_FIELD(player * MAP_PLAYER_STRIDE + players, u8 *, PLAYER_REC_ARMY) == M2C_FIELD(other * MAP_PLAYER_STRIDE + players, u8 *, PLAYER_REC_ARMY)) return BATTLE_RESULT_NONE;
    return GetPlayerResult(player);
}

/* Whether the battle is won: a win by any human player decides it; otherwise a
 * human player who lost (a defeat condition was hit) decides it was not won; and
 * failing both, a win by any player still in the battle (an AI, say) counts. */
s32 DidPlayerWin(void) {
    s32 IsPlayerHuman(s32);
    s32 human;
    s32 human2;
    s32 player;

    human = 1;
loop_1:
    if ((IsPlayerHuman(human) != 0) && (GetPlayerResult(human) == BATTLE_RESULT_WIN)) {
        return 1;
    }
    human += 1;
    if (human >= MAX_PLAYERS) {
        human2 = 1;
loop_6:
        if ((IsPlayerHuman(human2) != 0) && (GetPlayerResult(human2) == BATTLE_RESULT_LOSE)) {
            return 0;
        }
        human2 += 1;
        if (human2 >= MAX_PLAYERS) {
            player = 1;
loop_11:
            if ((IsPlayerPresent(player) != 0) && (GetPlayerResult(player) == BATTLE_RESULT_WIN)) {
                return 1;
            }
            player += 1;
            if (player >= MAX_PLAYERS) {
                return 0;
            }
            goto loop_11;
        }
        goto loop_6;
    }
    goto loop_1;
}

/* Whether the player's side lost the battle: the battle is not a draw and was
 * not won. */
u8 DidPlayerLose(void) {
    s32 IsBattleDraw();
    s32 DidPlayerWin();
    u8 lost;

    if (IsBattleDraw() != 0) {
        return 0U;
    }
    if (DidPlayerWin() == 0) {
        lost = 1;
    } else {
        lost = 0;
    }
    return lost;
}

/* Whether the battle ended in a draw: true as soon as any player 1..4 is
 * present and their battle result is BATTLE_RESULT_DRAW. */
s32 IsBattleDraw(void) {
    s32 GetPlayerResult(s32);
    s32 IsPlayerPresent(s32);
    s32 player;

    player = 1;
loop_1:
    if ((IsPlayerPresent(player) != 0) && (GetPlayerResult(player) == BATTLE_RESULT_DRAW)) {
        return 1;
    }
    player += 1;
    if (player >= 5) {
        return 0;
    }
    goto loop_1;
}

/* The player who won the battle: the map's current player while the battle is
 * still running, otherwise the first human player (then the first present
 * player) whose result is a win; 0 when nobody won. */
s32 GetWinningPlayer(void) {
    extern u8 gBattleEndState;
    extern s32 *gCurrentMap;
    s32 player;

    if (!gBattleEndState && GetPlayerResult(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) == BATTLE_RESULT_WIN) return M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER);
    for (player = 1; player < MAX_PLAYERS; player++) if (IsPlayerHuman(player) && GetPlayerResult(player) == BATTLE_RESULT_WIN) return player;
    for (player = 1; player < MAX_PLAYERS; player++) if (IsPlayerPresent(player) && GetPlayerResult(player) == BATTLE_RESULT_WIN) return player;
    return BATTLE_RESULT_NONE;
}

/* Returns the id of the player who lost the battle (0 when nobody did): the
 * current player while the battle is still running, then the first human player
 * and then the first present player whose result is BATTLE_RESULT_LOSE. */
s32 GetLosingPlayer(void){
extern u8 gBattleEndState;extern s32 *gCurrentMap;s32 i;
if(!gBattleEndState && GetPlayerResult(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER))==BATTLE_RESULT_LOSE)return M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER);
for(i=1;i<5;i++)if(IsPlayerHuman(i) && GetPlayerResult(i)==BATTLE_RESULT_LOSE)return i;
for(i=1;i<5;i++)if(IsPlayerPresent(i) && GetPlayerResult(i)==BATTLE_RESULT_LOSE)return i;
return 0;
}

void func_020cd544(s32);
void StartCampaignFromSlot(s32 a){
extern u16 gMapConfig;extern s32 *data_027e0058;extern M2C_UNK data_0212b804;extern u32 gSaveSlotSummary[];u32 v;
EnsureResource4Loaded();if(CampaignSaveSlotInUse(a)){func_020cd544(a);return;}
ResetCampaignProgress();gSaveSlotSummary[0]=(gSaveSlotSummary[0]&~15)|(a&15);
v=gSaveSlotSummary[0]&~240;*(volatile u32 *)gSaveSlotSummary=v;
gMapConfig &= ~7;
v&=~0xff0000;
v&=~0xff00;
gSaveSlotSummary[1]=(u16)(gSaveSlotSummary[1]&0xffff0000);
gSaveSlotSummary[0]=v&~0xff000000;
M2C_FIELD(*data_027e0058,u16 *,0x5142)=161;SetMapListFlag(161,1);CreateSpriteFromClass(&data_0212b804,7);
}

/* Starts a battle over the chosen map: reads the map kind, clears the map
 * config's mode bits, sets the map up, and either opens the field or (with no
 * unit data) spawns the placeholder menu object. */
void func_020cd544(s32 mapKind) {
    extern u16 gMapConfig;
    extern M2C_UNK gCampaignMapScreenClass;
    s32 GetSaveType(s32, s32);
    s32 IsUnitAvailable(s32);
    u8 kind;
    EnsureResource4Loaded();
    kind = GetSaveType(0, mapKind);
    gMapConfig &= ~7;
    LoadSaveSlotProgress(mapKind);
    if (IsUnitAvailable(kind)) {
        CreateSavedBattleView(kind);
    } else {
        CreateSpriteFromClass(&gCampaignMapScreenClass, 7);
    }
}

/* Leave the battle and open the campaign-map screen: reset the map config's
 * mode bits to the campaign mode and create the campaign-map scene object. */
void OpenCampaignMapScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gCampaignMapScreenClass;
    extern u16 gMapConfig;

    gMapConfig &= ~MAPCONFIG_MODE_MASK;
    CreateSpriteFromClass(&gCampaignMapScreenClass, 7);
}

/* True unless the options turn battle animations off. */
s32 func_020cd5d8(void) {
    extern M2C_UNK gOptionBits;
    switch ((u32)(M2C_FIELD(&gOptionBits, u16 *, 6) << 20) >> 30) {
    case 0: return 1;
    case 1: return 1;
    default: return 0;
    }
}

/* True while captures may start: always on in free battles, and in a campaign
 * battle only when the current player is human. */
s32 func_020cd614(void) {
    extern M2C_UNK gOptionBits;
    extern s32 *gCurrentMap;
    s32 IsPlayerHuman(s32);
    switch ((u32)(M2C_FIELD(&gOptionBits, u16 *, 6) << 18) >> 30) {
    case 0: return 1;
    case 1:
        if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4))) return 1;
    }
    return 0;
}

/* True while the battle animations run at a fast speed: the two high codes of
 * their 2-bit setting field in the game options count as fast. */
s32 IsFastAnimation(void) {
    extern M2C_UNK gOptionBits;

    switch ((u32)(M2C_FIELD(&gOptionBits, u16 *, GAME_OPTIONS_HALFWORD) << 20) >> 30) {
    case GAME_OPTION_ANIMATION_FASTEST: return 1;
    case GAME_OPTION_ANIMATION_FAST: return 1;
    }
    return 0;
}

/* Whether the battlefield grid overlay is on: bit 14 of the packed game options
 * is clear while the grid is drawn over the terrain. */
u8 IsMapGridEnabled(void) {
    extern M2C_UNK gOptionBits;
    u8 enabled;

    if (((u32) (M2C_FIELD(&gOptionBits, u16 *, GAME_OPTIONS_HALFWORD) << 0x11) >> 0x1F) == 0) {
        enabled = 1;
    } else {
        enabled = 0;
    }
    return enabled;
}

/* Whether the battle uses the campaign's rules: the map's battle-mode bits
 * (the low bits of MAPDATA_RULES) are MAPDATA_MODE_CAMPAIGN, which is 0. */
u8 IsCampaignBattleRules(void) {
    extern M2C_UNK gMapData;
    u8 value;

    if (!(((u32) (M2C_FIELD(&gMapData, u16 *, MAPDATA_RULES) << 0x1D) >> 0x1D) & 0xFF)) {
        value = 1;
    } else {
        value = 0;
    }
    return value;
}

/* Whether the battle is a free-play (non-campaign) battle: the map's rules
 * carry free play in their battle-mode bits. */
u8 IsFreePlayBattleMode(void) {
    extern M2C_UNK gMapData;
    u8 value;

    if ((u8)((u32)(M2C_FIELD(&gMapData, u16 *, MAPDATA_RULES) << 29) >> 29) == MAPDATA_MODE_FREE_PLAY) value = 1;
    else value = 0;
    return value;
}

/* Whether the map configuration is in mode 2, the map editor's mode (the mode
 * bits of the map configuration word, which EnterMapEditorScreen sets to 2). */
u8 IsMapEditorMode(void) {
    extern M2C_UNK gMapData;
    u8 value;

    if ((u8)((u32)(M2C_FIELD(&gMapData, u16 *, MAPDATA_RULES) << 29) >> 29) == MAPDATA_MODE_MAP_EDITOR) value = 1;
    else value = 0;
    return value;
}

#pragma push
#pragma opt_common_subs off
/* Fills a team's cell-sight bitmap with every cell visible when the map has no
 * fog and no snow, and clears it otherwise: the team sees the whole map or
 * nothing. */
void FillTeamSightBitmap(s32 team) {
    extern s32 *gCurrentMap;
    void MI_CpuFill8(s32, s32, s32);
    s32 map = *gCurrentMap;

    if (M2C_FIELD(map, u8 *, MAP_FOG) == 0 && M2C_FIELD(map, u8 *, MAP_WEATHER) != MAP_WEATHER_SNOW) {
        MI_CpuFill8(map + MAP_CELL_BITMAP_TEAM_A + MAP_CELL_BITMAP_SIZE * team, 255, MAP_CELL_BITMAP_SIZE);
    } else {
        MI_CpuFill8(map + MAP_CELL_BITMAP_TEAM_A + MAP_CELL_BITMAP_SIZE * team, 0, MAP_CELL_BITMAP_SIZE);
    }
}
#pragma pop
/* Copy one team's cell-sight bitmap over the other team's: the bitmap of team slot
 * `fromTeam` into the one of slot `toTeam` (the two bitmaps sit back to back at
 * MAP_CELL_BITMAP_TEAM_A = 0x5160), so both teams share the same view. */
void CopyTeamSightBitmap(s32 fromTeam, s32 toTeam) {
 extern s32 *gCurrentMap;
 void MI_CpuCopy8(s32,s32);
 s32 base=*gCurrentMap+0x160;
 s32 size=MAP_CELL_BITMAP_SIZE;
 base=base+0x5000;
 MI_CpuCopy8(size*fromTeam+base,size*toTeam+base);
}

/* How `player` relates to `other`: PLAYER_RELATION_NONE if `other` is not in the
 * battle, ENEMY when the two players' armies (nations) differ, ALLY when they
 * match. */
s32 GetPlayerRelation(s32 player, s32 other) {
    extern s32 *gCurrentMap;
    s32 players;

    if (IsPlayerPresent(other) == 0) {
        return PLAYER_RELATION_NONE;
    }
    players = *gCurrentMap + MAP_PLAYER_STATES;
    if (M2C_FIELD(((player * MAP_PLAYER_STRIDE) + players), u8 *, PLAYER_REC_ARMY) != M2C_FIELD(((other * MAP_PLAYER_STRIDE) + players), u8 *, PLAYER_REC_ARMY)) {
        return PLAYER_RELATION_ENEMY;
    }
    return PLAYER_RELATION_ALLY;
}

/* True when a human player is on the given player's side (any of the other
 * three players is both an ally and human). */
s32 PlayerHasHumanAlly(s32 player) {
 s32 i, v, n;
 n = player + 1;
 i = 1;
 do {
 v = n;
 if (n >= 5) v = n - 4;
 if (GetPlayerRelation(player, (u16)v) == 2 && IsPlayerHuman(v) != 0) return 1;
 i++;
 n++;
 } while(i < 4);
 return 0;
}

