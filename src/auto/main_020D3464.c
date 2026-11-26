/* 30 functions from 0x020D3464 to 0x020D4430 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

/* Per-frame turn-timer step of the battle-map state machine, run from the state
   dispatcher. While the map has a turn time limit it counts the current player's
   elapsed turn frames in the states that advance a turn; once the limit is
   reached it ends the turn (returns 1), and beeps once a second during the last
   ten seconds. */
s32 UpdateTurnTimer(void) {
    void IncrementCounter(void *);
    void func_02081fd4(void);
    void PlaySoundEffect(s32);
    extern M2C_UNK gMapData;
    extern void **gCurrentMap;

    if (M2C_FIELD(&gMapData, u16 *, MAPDATA_TURN_TIME) == 0) {
        return 0;
    }

    {
        void *base = *gCurrentMap;
        s32 step = (s32)M2C_FIELD(base, u16 *, MAP_STATE) - 13;

        switch (step) {
        case 0:
        case 7: {
            u16 player = M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER);
            {
                u8 *rec = (u8 *)base + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
                IncrementCounter(rec + PLAYER_REC_TURN_TIME);
            }
            {
                u16 limit = M2C_FIELD(&gMapData, u16 *, MAPDATA_TURN_TIME);
                void *b = *gCurrentMap;
                u16 p2 = M2C_FIELD(b, u16 *, MAP_CURRENT_PLAYER);
                u32 *elapsed = (u32 *)((u8 *)b + p2 * MAP_PLAYER_STRIDE + PLAYER_TURN_TIME_OFF);
                s32 remaining = (s32)limit - (s32)*elapsed;
                if (remaining <= 0) {
                    func_02081fd4();
                    b = *gCurrentMap;
                    M2C_FIELD(b, u16 *, MAP_STATE) = 21;
                    return 1;
                }
                if (remaining > 600) {
                    break;
                }
                if (remaining % 60 != 0) {
                    break;
                }
                PlaySoundEffect(0x126);
                break;
            }
        }
        case 10:
        case 11:
        case 12:
        case 13: {
            u16 player = M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER);
            {
                u8 *rec = (u8 *)base + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
                IncrementCounter(rec + PLAYER_REC_TURN_TIME);
            }
            break;
        }
        case 6: {
            u16 player = M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER);
            {
                u8 *rec = (u8 *)base + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
                IncrementCounter(rec + PLAYER_REC_TURN_TIME);
            }
            break;
        }
        default:
            break;
        }
    }

    return 0;
}

/* End-turn step: wait until the map's input mode has finished, then clear the
 * sprites of the map's notice class, create the turn-end transition effect and
 * move on to the end-player-turn step. */
void StartEndTurn(void) {
    M2C_UNK UpdateMapMode();
    M2C_UNK func_02081fec();
    M2C_UNK func_020b7bbc();
    extern void **gCurrentMap;
    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_MODE) != 0) {
        UpdateMapMode();
        return;
    }
    func_02081fec();
    func_020b7bbc();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_STATE) = MAP_STATE_END_TURN_STEP;
}

/* End the current player's turn and, in a link/online battle, tell the other
 * players that the turn is over. */
void EndPlayerTurnStep(void) {
    M2C_UNK SendTurnEndPacket();
    M2C_UNK EndPlayerTurn();
    extern M2C_UNK gMapData;
    EndPlayerTurn();
    if (M2C_FIELD(&gMapData, u8 *, MAPDATA_LINK_BATTLE) == 0) {
        return;
    }
    SendTurnEndPacket();
}

s32 HandleOverlayResult(void) {
 M2C_UNK IsAiCommandTaskRunning();
 M2C_UNK GetActiveOverlay();
 M2C_UNK GetLinkPhase();
 void SetLinkResultFlag(M2C_UNK);
 M2C_UNK GetNetErrorCode();
 M2C_UNK func_ov010_02228314(M2C_UNK *,M2C_UNK *);
 void SetOnlineSessionFlag(M2C_UNK);
 M2C_UNK GetOverlayEventFlags();
 void func_02081fd4(void);
 extern M2C_UNK gMapData;
 extern void **gCurrentMap;
 s32 overlayResult,eventFlags,errorCode,errorType;
 /* Poll the active UI overlay (ov009/ov010) for a finished event; while the map
    waits in state 13/14/19/20, record the result and move on to state 23/24. */
 if(M2C_FIELD(&gMapData,u8 *,4)==0) return 0;
 if(IsAiCommandTaskRunning()!=0) return 0;
 if(M2C_FIELD(&gMapData,u8 *,5)!=0 || M2C_FIELD(&gMapData,u8 *,6)!=0) return 0;
 overlayResult=0; eventFlags=0;
 switch(GetActiveOverlay()){
 case 1:
 if(GetLinkPhase()==8 || GetLinkPhase()==9){
 SetLinkResultFlag(1); overlayResult=1;
 } break;
 case 2:
 if(GetNetErrorCode()!=0 ? 1 : overlayResult){
 func_ov010_02228314(&errorCode,&errorType);
 switch(errorType){case 0: break; case 1: case 2: case 3: case 4: case 5: case 6: case 7: SetOnlineSessionFlag(6); break;}
 overlayResult=1;
 }
 break;
 }
 if(GetOverlayEventFlags()!=0) eventFlags=1;
 if(overlayResult!=0 || eventFlags!=0){
 switch(M2C_FIELD(*gCurrentMap,u16 *,0x52b0)){
 case 13: case 14: case 19: case 20:
 M2C_FIELD(&gMapData,u8 *,5)=overlayResult;
 M2C_FIELD(&gMapData,u8 *,6)=eventFlags;
 if(overlayResult!=0){
 func_02081fd4();
 M2C_FIELD(*gCurrentMap,u16 *,0x52b2)=M2C_FIELD(*gCurrentMap,u16 *,0x52b0);
 M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=23;
 } else if(eventFlags!=0){
 func_02081fd4();
 M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=24;
 }
 return 1;
 }
 }
 return 0;
}

void func_020d3830(void) {
    M2C_UNK UpdateMapMode();
    M2C_UNK IsTextLayerActive();
    M2C_UNK GetActiveOverlay();
    M2C_UNK GetLinkResultCode();
    void CreateLinkStatusLabel(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    M2C_UNK func_ov010_02228314(M2C_UNK *, M2C_UNK *);
    void CreateNetErrorSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, void *);
    void func_ov010_02228320();
    void Ov010Online_ClearStepFlag(M2C_UNK);
    M2C_UNK func_02081fec();
    extern void **gCurrentMap;
    extern M2C_UNK gMapData;

    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52B4) != 0) {
        UpdateMapMode();
        return;
    }
    if (IsTextLayerActive() != 0) {
        return;
    }
    switch (GetActiveOverlay()) {
    case 1:
        CreateLinkStatusLabel(0, 0x25c, GetLinkResultCode(), (void *)7);
        M2C_FIELD(&gMapData, u8 *, 7) = 0;
        func_02081fec();
        M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 0x19;
        break;
    case 2: {
        void **current;
        s32 result;
        s32 spare;
        s32 ret = func_ov010_02228314(&result, &spare);
        CreateNetErrorSprite(0, 0x25c, ret, result, spare, (void *)7);
        func_ov010_02228320();
        switch (spare) {
        case 0:
        case 1:
        case 2:
            Ov010Online_ClearStepFlag(6);
            current = *(void **volatile *)&gCurrentMap;
            M2C_FIELD(&gMapData, u8 *, 5) = 0;
            M2C_FIELD(*current, u16 *, 0x52B0) = M2C_FIELD(*current, u16 *, 0x52B2);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            M2C_FIELD(&gMapData, u8 *, 7) = 0;
            func_02081fec();
            M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 0x19;
            break;
        case 7:
            break;
        }
        break;
    }
    }
}

void func_020d39a4(void) {
    M2C_UNK data_ov004_0222866c(M2C_UNK);
    data_ov004_0222866c(0);
}

/* Per-frame update of the online match view-hold sprite (its class update slot):
 * for the online overlay, poll the matchmaking request; while it runs return 1 so
 * the hold keeps the map, and once it finishes store the outcome (1 = opponent
 * found) in the map data and let the hold end. */
s32 UpdateOnlineMatchViewHold(void) {
    s32 GetActiveOverlay();
    s32 Ov010Online_PollMatchmaking(s32 *);
    extern M2C_UNK gMapData;
    s32 matched;

    if (GetActiveOverlay() != 2) {
        return 0;
    }
    if (Ov010Online_PollMatchmaking(&matched) != 0) {
        return 1;
    }
    M2C_FIELD(&gMapData, u8 *, MAPDATA_MATCH_RESULT) = matched;
    return 0;
}

/* Overlay-cleanup step: start the map-view hold that follows the just-ended
 * overlay battle. For the local-wireless overlay clear the pending match result;
 * for the online overlay create the matchmaking hold sprite, which polls
 * matchmaking while it holds the map. */
void SetupMapViewHold(s32 owner) {
    M2C_UNK GetActiveOverlay();
    M2C_UNK CreateSpriteObject(M2C_UNK, M2C_UNK);
    extern M2C_UNK gMapData;
    extern M2C_UNK gOnlineMatchViewHoldClass;
    switch (GetActiveOverlay()) {                      /* irregular */
    case 1:
        M2C_FIELD(&gMapData, u8 *, MAPDATA_MATCH_RESULT) = 0;
        return;
    case 2:
        CreateSpriteObject(&gOnlineMatchViewHoldClass, owner);
        return;
    }
}

/* Battle-map state-machine step (state 24) that resumes the map after an
 * overlay event rather than a match result: once the cursor mode is back and no
 * text layer is up, clear the event sprites, advance to the result-text state
 * and create the overlay-cleanup sprite. */
void AdvanceAfterOverlayEvent(void) {
    M2C_UNK UpdateMapMode();
    M2C_UNK IsTextLayerActive();
    M2C_UNK func_02081fec();
    void CreateSpriteFromClass(void *, s32);
    extern void **gCurrentMap;
    extern char data_0212ba7c[];
    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_MODE) != 0) {
        UpdateMapMode();
        return;
    }
    if (IsTextLayerActive() != 0) {
        return;
    }
    func_02081fec();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_STATE) = 25;
    CreateSpriteFromClass(data_0212ba7c, 7);
}

#pragma optimization_level 2
/* Once the link/online session has ended or matchmaking found no opponent,
 * drop the voice-chat widgets and put the match name label on the battle map. */
void ShowMatchNameLabel(void *owner) {
 M2C_UNK DeleteVoiceChatWidgets();
 M2C_UNK CreateMatchNameLabel(M2C_UNK, M2C_UNK, M2C_UNK);
 extern M2C_UNK gMapData;
 if (M2C_FIELD(&gMapData,u8 *,MAPDATA_OVERLAY_RESULT) != 0 || M2C_FIELD(&gMapData,u8 *,MAPDATA_MATCH_RESULT) == 0) {
 DeleteVoiceChatWidgets();
 CreateMatchNameLabel(0,MAP_MATCH_LABEL_Y,owner);
 }
}
#pragma optimization_level reset
/* Overlay-cleanup step (map state 25): create the overlay-cleanup sprite and
 * move on to wrapping up the battle (MAP_STATE_FINISH). */
void CreateOverlayCleanupSprite(void) {
    void CreateSpriteFromClass(void *, s32);
    extern void **gCurrentMap;
    extern char gOverlayCleanupSpriteClass[];
    CreateSpriteFromClass(gOverlayCleanupSpriteClass, 7);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_STATE) = MAP_STATE_FINISH;
}

void func_020d3b18(void) {
    M2C_UNK BattleFinishStep();
    BattleFinishStep();
}

/* Per-frame step of the battle-map state machine: run the map view controller's
 * frame callback, give the overlay result, turn timer and busy checks a chance to
 * hold the map for this frame, then run the handler of the current MAP_STATE. */
void StepBattleMap(void) {
    M2C_UNK UpdatePlayerBattleTime();
    M2C_UNK HandleOverlayResult();
    M2C_UNK UpdateTurnTimer();
    M2C_UNK IsUiModeSwitchBusy();
    M2C_UNK GetMapViewHoldCount();
    M2C_UNK IsUnitMoveActive();
    void CheckTurnLimitStep();
    void AdvanceTurnStep();
    void BeginPlayerTurnSetup();
    void TurnStartWaitStep();
    void TurnStartSetupStep();
    void func_020d447c();
    M2C_UNK TurnBannerStep();
    void TurnIntro1Step();
    void TurnIntro2Step();
    void TurnIntro3Step();
    void TurnIntroWaitStep();
    void BeginPlayerTurn();
    M2C_UNK UpdateMapMode();
    M2C_UNK IsPlayerLocallyControlled(M2C_UNK);
    M2C_UNK UpdateAiTurn();
    void UpdateLinkAiCommand();
    void MapStateReturnStep();
    M2C_UNK BattleFinishStep();
    M2C_UNK ResumeMapInputStep();
    void StartEndTurn();
    void EndPlayerTurnStep();
    void func_020d3830();
    void AdvanceAfterOverlayEvent();
    void CreateOverlayCleanupSprite();
    void func_020d3b18();
    extern void **gCurrentMap;

    UpdatePlayerBattleTime();

    {
        void *viewController = gCurrentMap[MAPVIEW_CONTROLLER_INDEX];
        void (*frameCallback)(void) = M2C_FIELD(viewController, void (**)(void), MAPVIEW_FRAME_CB);
        if (frameCallback != 0) {
            frameCallback();
        }
    }

    if (HandleOverlayResult() != 0) return;
    if (UpdateTurnTimer() != 0) return;
    if (IsUiModeSwitchBusy() != 0) return;
    if (GetMapViewHoldCount() != 0) return;
    if (IsUnitMoveActive() != 0) return;

    {
        void **map = gCurrentMap;
        u8 *stateBlock = (u8 *)map[0] + 0x5200;
        switch (*(u16 *)(stateBlock + 0xb0)) {
        case MAP_STATE_TURN_LIMIT:
            CheckTurnLimitStep();
            return;
        case MAP_STATE_ADVANCE_TURN:
            AdvanceTurnStep();
            return;
        case MAP_STATE_BEGIN_PHASE:
            BeginPlayerTurnSetup();
            return;
        case MAP_STATE_TURN_START_WAIT:
            TurnStartWaitStep();
            return;
        case MAP_STATE_TURN_START_SETUP:
            TurnStartSetupStep();
            return;
        case MAP_STATE_TURN_START:
            func_020d447c();
            return;
        case MAP_STATE_TURN_BANNER:
            TurnBannerStep();
            return;
        case MAP_STATE_TURN_INTRO1:
            TurnIntro1Step();
            return;
        case MAP_STATE_TURN_INTRO2:
            TurnIntro2Step();
            return;
        case MAP_STATE_TURN_INTRO3:
            TurnIntro3Step();
            return;
        case MAP_STATE_TURN_INTRO_WAIT:
            TurnIntroWaitStep();
            return;
        case MAP_STATE_PLAYER_TURN:
            BeginPlayerTurn();
            return;
        case MAP_STATE_MAP_INPUT:
            UpdateMapMode();
            return;
        case MAP_STATE_AI_TURN:
            if (IsPlayerLocallyControlled(M2C_FIELD(map[0], u16 *, MAP_CURRENT_PLAYER))) { UpdateAiTurn(); return; }
            UpdateLinkAiCommand(); return;
        case MAP_STATE_LINK_TURN: UpdateLinkAiCommand(); return;
        case MAP_STATE_RETURN: MapStateReturnStep(); return;
        case MAP_STATE_BATTLE_FINISH: BattleFinishStep(); return;
        case MAP_STATE_RESUME_INPUT: ResumeMapInputStep(); return;
        case MAP_STATE_END_TURN: StartEndTurn(); return;
        case MAP_STATE_END_TURN_STEP: EndPlayerTurnStep(); return;
        case MAP_STATE_OVERLAY_RESULT: func_020d3830(); return;
        case MAP_STATE_AFTER_OVERLAY: AdvanceAfterOverlayEvent(); return;
        case MAP_STATE_OVERLAY_CLEANUP: CreateOverlayCleanupSprite(); return;
        case MAP_STATE_FINISH: func_020d3b18(); return;
        default: return;
        }
    }
}

/* Point the shared target list and the selection queue back at the default entry
 * buffer, then reload the map's tileset and the unit-name graphics. Called when
 * the game state is reset, before the map config is reset. */
void ResetMapListsAndGraphics(void) {
    M2C_UNK LoadMapTileset();
    M2C_UNK ClearNameGraphicFiles();
    M2C_UNK LoadNameGraphicFiles();
    extern void *gDefaultMapListBuffer;
    extern s32 gTargetList;
    extern s32 gSelectionQueue;

    gSelectionQueue = (s32)gDefaultMapListBuffer;
    gTargetList = (s32)gDefaultMapListBuffer;
    LoadMapTileset();
    ClearNameGraphicFiles();
    LoadNameGraphicFiles();
}

/* Reset the map, load its terrain and units, initialize player and AI state, then start the active player's phase. */
void ResetBattleMapAndBeginPhase(void) {
    M2C_UNK ResetBattleMap();
    M2C_UNK LoadMapTileset();
    M2C_UNK LoadBattleMap(M2C_UNK);
    M2C_UNK InitBattleState();
    M2C_UNK ResetPlayerTurnBonuses();
    M2C_UNK func_020cfd14();
    M2C_UNK CenterMapViewAtBattleStart();
    M2C_UNK BeginPlayerPhase();
    M2C_UNK InitPlayerTurnState();
    extern void **gCurrentMap;

    ResetBattleMap();
    LoadMapTileset();
    LoadBattleMap(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
    InitBattleState();
    ResetPlayerTurnBonuses();
    func_020cfd14();
    CenterMapViewAtBattleStart();
    BeginPlayerPhase();
    InitPlayerTurnState();
}

/* Set each player's stored map-cursor position (PLAYER_REC_CURSOR_X/Y) after a
 * map loads: the selected unit's tile, else the player's HQ, else the first live
 * unit of the player's group, else the middle of the map. */
void InitPlayerCursorPositions(void) {
    u8 *GetPlayerSelectedUnit(s32);
    s32 PlayerHasHq(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    void *map;
    u32 mapWidth;
    u32 mapHeight;
    s32 player;
    s32 cursorX;
    s32 cursorY;
    s32 playerOffset;
    s32 unitGroupBase;
    s32 unitGroupEnd;
    s32 unitId;
    void *selectedUnit;
    BattleMapUnitHead *unit;

    for (player = 1, playerOffset = MAP_PLAYER_STRIDE; player < 5; player++) {
        map = *gCurrentMap;
        mapWidth = M2C_FIELD(map, u16 *, MAP_WIDTH);
        mapHeight = M2C_FIELD(map, u16 *, MAP_HEIGHT);
        cursorX = mapWidth >> 1;
        cursorY = mapHeight >> 1;
        if (GetPlayerSelectedUnit(player) != 0) {
            selectedUnit = GetPlayerSelectedUnit(player);
            cursorX = M2C_FIELD(selectedUnit, u8 *, MAP_UNIT_X);
            cursorY = M2C_FIELD(selectedUnit, u8 *, MAP_UNIT_Y);
        } else {
            if (PlayerHasHq(player) != 0) {
                map = *gCurrentMap;
                cursorX = M2C_FIELD((u8 *)map + playerOffset, u8 *, MAP_PLAYER_STATES + PLAYER_REC_HQ_X) & 0x7F;
                cursorY = M2C_FIELD((u8 *)map + playerOffset, u8 *, MAP_PLAYER_STATES + PLAYER_REC_HQ_Y) & 0x7F;
            } else {
                unitGroupBase = gPlayerUnitIdBase[player];
                unitId = unitGroupBase + 1;
                unitGroupEnd = unitGroupBase + MAP_UNIT_GROUP_SCAN;
                if (unitId < unitGroupEnd) {
                    map = *gCurrentMap;
                    unit = (BattleMapUnitHead *)((u8 *)map + MAP_UNIT_RECORDS) + unitId;
                    do {
                        if (unit->kind != 0) {
                            cursorX = unit->x;
                            cursorY = unit->y;
                            break;
                        }
                        unit++;
                    } while (++unitId < unitGroupEnd);
                }
            }
        }
        map = *gCurrentMap;
        M2C_FIELD((u8 *)map + playerOffset, u8 *, MAP_PLAYER_STATES + PLAYER_REC_CURSOR_X) = (u8)cursorX;
        map = *gCurrentMap;
        M2C_FIELD((u8 *)map + playerOffset, u8 *, MAP_PLAYER_STATES + PLAYER_REC_CURSOR_Y) = (u8)cursorY;
        playerOffset += MAP_PLAYER_STRIDE;
    }
}

/* Property-count victory: the active player owning the most properties wins and
 * every other active player is marked defeated (reason PLAYER_DEFEAT_PROPERTIES). */
s32 ResolvePropertyCountVictory(void) {
    s32 IsPlayerActive(s32);
    void MarkPlayerDefeated(s32, s32);
    void EnterBattleEnd();
    extern void **gCurrentMap;
    s32 player;
    s32 offset;
    s32 maxProperties;
    void *map;

    maxProperties = 0;
    for (player = 1, offset = MAP_PLAYER_STRIDE; player < MAX_PLAYERS; player++, offset += MAP_PLAYER_STRIDE) {
        if (IsPlayerActive(player) != 0) {
            s32 properties;
            map = *gCurrentMap;
            properties = M2C_FIELD((u8 *)map + offset, u8 *, MAP_PLAYER_STATES + PLAYER_REC_PROPERTIES);
            if (maxProperties < properties) {
                maxProperties = properties;
            }
        }
    }
    for (player = 1, offset = MAP_PLAYER_STRIDE; player < MAX_PLAYERS; player++, offset += MAP_PLAYER_STRIDE) {
        if (IsPlayerActive(player) != 0) {
            map = *gCurrentMap;
            if (maxProperties > M2C_FIELD((u8 *)map + offset, u8 *, MAP_PLAYER_STATES + PLAYER_REC_PROPERTIES)) {
                MarkPlayerDefeated(player, PLAYER_DEFEAT_PROPERTIES);
            }
        }
    }
    EnterBattleEnd();
}

/* True when the battle's active human players are split over different armies:
 * a local (non-link) battle with fog or snow. Clears to the map's first state
 * when the current player's record flag is set. */
s32 HumanPlayersOnDifferentArmies(void) {
    M2C_UNK IsPlayerActive(s32);
    M2C_UNK IsPlayerHuman(s32);
    extern void **gCurrentMap;
    extern M2C_UNK gMapData;
    u8 army;
    s32 count;
    s32 i;
    s32 off;
    void *base;
    u16 player;
    u8 v;

    base = *gCurrentMap;
    player = M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER);
    if (M2C_FIELD((u8 *)base + player * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + 0x19) != 0) {
        M2C_FIELD(base, u16 *, MAP_STATE) = 1;
        return 0;
    }
    if (M2C_FIELD(&gMapData, u8 *, 4) != 0) {
        return 0;
    }
    base = *gCurrentMap;
    if (M2C_FIELD(base, u8 *, MAP_FOG) == 0) {
        if (M2C_FIELD(base, u8 *, MAP_WEATHER) != 2) {
            return 0;
        }
    }
    army = 0;
    count = army;
    for (i = 1, off = MAP_PLAYER_STRIDE; i < 5; i++, off += MAP_PLAYER_STRIDE) {
        if (IsPlayerActive(i) != 0) {
            if (count == 0) {
                if (IsPlayerHuman(i) != 0) {
                    base = *gCurrentMap;
                    v = M2C_FIELD((u8 *)base + off, u8 *, MAP_PLAYER_STATES + PLAYER_REC_ARMY);
                    count++;
                    army = v;
                }
            } else {
                if (IsPlayerHuman(i) != 0) {
                    base = *gCurrentMap;
                    v = M2C_FIELD((u8 *)base + off, u8 *, MAP_PLAYER_STATES + PLAYER_REC_ARMY);
                    if (army != v) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

/* True when no active player is human-controlled: a CPU-only (demo) battle.
   A local battle only counts once a skip button (A/B/Start/X/Y) is held; a
   link/online battle is checked directly. */
s32 IsCpuOnlyBattle(void) {
    M2C_UNK IsPlayerActive(s32);
    M2C_UNK IsPlayerCpu(s32);
    extern M2C_UNK gMapData;
    extern void *gKeyState;
    s32 i;

    if (M2C_FIELD(&gMapData, u8 *, MAPDATA_LINK_BATTLE) != 0) {
        for (i = 1; i < MAX_PLAYERS; i++) {
            if (IsPlayerActive(i) != 0 && IsPlayerCpu(i) == 0) {
                return 0;
            }
        }
    } else {
        if ((M2C_FIELD(gKeyState, u16 *, 0x6) & (KEY_A | KEY_B | KEY_START | KEY_X | KEY_Y)) == 0) {
            return 0;
        }
        for (i = 1; i < MAX_PLAYERS; i++) {
            if (IsPlayerActive(i) != 0 && IsPlayerCpu(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

/* End an all-CPU (demo) battle: a link/online battle has no human on this
 * console, so the property count decides the winner; a local demo just opens
 * the battle-end screen. */
void EndCpuOnlyBattle(void) {
    M2C_UNK ResolvePropertyCountVictory();
    void CreateSpriteFromClass(void *, s32);
    extern M2C_UNK gMapData;
    extern char data_0212ba3c[];
    if (M2C_FIELD(&gMapData, u8 *, MAPDATA_LINK_BATTLE) != 0) {
        ResolvePropertyCountVictory();
        return;
    }
    CreateSpriteFromClass(data_0212ba3c, 7);
}

/* Turn-limit step (map state 1): when a new day begins, end the battle on the
   map's configured day limit, the player holding the most properties winning;
   otherwise move on to advancing to the next player's turn. */
void CheckTurnLimitStep(void) {
    void ShowUiMessage(s32);
    s32 ResolvePropertyCountVictory(void);
    void ScheduleBattleEndCheck(void);
    u32 WillNextTurnStartNewDay(void);
    extern M2C_UNK gMapData;
    extern void **gCurrentMap;

    if (M2C_FIELD(&gMapData, u8 *, MAPDATA_DAY_LIMIT) != 0 && WillNextTurnStartNewDay() != 0) {
        if (M2C_FIELD(&gMapData, u8 *, MAPDATA_DAY_LIMIT) == M2C_FIELD(*gCurrentMap, u16 *, MAP_TURN)) goto same;
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) = 2;
    ScheduleBattleEndCheck();
    return;
same:
    ShowUiMessage(0xC0000347); /* "out of days" battle-end message */
    ResolvePropertyCountVictory();
}

/* Battle-map state 2: run the view controller's presentation setup, advance the
 * turn to the next active player and queue the player-phase step (state 3).
 * When human players share the console on different armies, show the turn-start
 * panel instead of revealing the map; in a CPU-only battle, end it. */
void AdvanceTurnStep(void) {
 M2C_UNK AdvancePlayerTurn(); M2C_UNK HumanPlayersOnDifferentArmies(); void CreateTurnStartPanel(); M2C_UNK IsCpuOnlyBattle(); void EndCpuOnlyBattle(); extern void **gCurrentMap;
 void (*cb)(void)=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),void(**)(void),MAPVIEW_INIT_PRESENTATION);
 if(cb) cb();
 AdvancePlayerTurn();
 M2C_FIELD(*gCurrentMap,u16*,MAP_STATE)=3;
 if(HumanPlayersOnDifferentArmies()!=0){CreateTurnStartPanel();return;}
 if(IsCpuOnlyBattle()==0)return;
 EndCpuOnlyBattle();
}

/* Run the current player's turn-start setup, refresh the map view, and advance to the turn-start wait state. */
void BeginPlayerTurnSetup(void) {
    M2C_UNK SetPlayerCoAnimationToIdle(M2C_UNK);
    M2C_UNK BeginPlayerPhase(void);
    M2C_UNK InitPlayerTurnState(void);
    M2C_UNK ResetPlayerTurnBonuses(void);
    M2C_UNK RefreshMapView(void);
    void func_020d427c(void);
    extern void **gCurrentMap;

    SetPlayerCoAnimationToIdle(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    BeginPlayerPhase();
    InitPlayerTurnState();
    ResetPlayerTurnBonuses();
    RefreshMapView();
    func_020d427c();
    M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) = MAP_STATE_TURN_START_WAIT;
}

void func_020d427c(void) {

}

/* Battle-map state MAP_STATE_TURN_INTRO1: create the turn-intro sprite, then
 * move on to the intro's second step. */
void TurnIntro1Step(void) {
    M2C_UNK func_020cbda4();
    extern void **gCurrentMap;

    func_020cbda4();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_STATE) = MAP_STATE_TURN_INTRO2;
}

/* Battle-map state MAP_STATE_TURN_INTRO2: create the turn-intro upkeep sprite
 * (it marks cargo and supply tiles and steps the view to the current player's
 * cursor), then move on to MAP_STATE_TURN_INTRO3. */
void TurnIntro2Step(void) {
    M2C_UNK func_020cbc08();
    extern void **gCurrentMap;

    func_020cbc08();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_STATE) = MAP_STATE_TURN_INTRO3;
}

/* Battle-map state MAP_STATE_TURN_INTRO3: run the turn intro's script event, then
 * wait it out (MAP_STATE_TURN_INTRO_WAIT). */
void TurnIntro3Step(void) {
    M2C_UNK RunTurnIntroEvent();
    extern void **gCurrentMap;

    RunTurnIntroEvent();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_STATE) = MAP_STATE_TURN_INTRO_WAIT;
}

/* Turn-intro wait step (MAP_STATE_TURN_INTRO_WAIT): wait while the intro's dialog
 * is still up; once it is gone, create the turn-intro sprite and move on to the
 * current player's turn. */
void TurnIntroWaitStep(void) {
    M2C_UNK IsDialogActive();
    M2C_UNK func_020a5ac8();
    extern void **gCurrentMap;

    if (IsDialogActive() != 0) {
        return;
    }
    func_020a5ac8();
    M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) = MAP_STATE_PLAYER_TURN;
}

#pragma merge_duplicate_code off
/* Battle-map state 12: start the current player's turn.  A human who may act
 * plays it (state 13); a CPU, or a human the map does not let act on their own,
 * goes to the AI turn path (state 14, restarting the AI command phase); the
 * remaining link players skip to state 19. */
void BeginPlayerTurn(void){
M2C_UNK LoadUiSpritePalette(M2C_UNK);void SetAiCommandPhase(s32);extern void **gCurrentMap;extern M2C_UNK gMapData;
u8 *map,*state;u16 player;u8 control;
LoadUiSpritePalette(3);
map=(u8*)*gCurrentMap;state=map+0x5200;
player=M2C_FIELD(state,u16*,0xa4);
control=M2C_FIELD(map+player*0x8c,u8*,PLAYER_CONTROL_OFF);
switch(control){
case PLAYER_CONTROL_NONE:break;
case PLAYER_CONTROL_HUMAN:
if((((u32)M2C_FIELD(&gMapData,u16*,12)<<22)>>31)==0){M2C_FIELD(state,u16*,0xb0)=13;return;}
M2C_FIELD(state,u16*,0xb0)=14;SetAiCommandPhase(0);return;
case PLAYER_CONTROL_CPU:M2C_FIELD(state,u16*,0xb0)=14;SetAiCommandPhase(0);return;
case 3:M2C_FIELD(state,u16*,0xb0)=19;return;
case 4:M2C_FIELD(state,u16*,0xb0)=19;return;
case 5:M2C_FIELD(state,u16*,0xb0)=19;return;
case 6:M2C_FIELD(state,u16*,0xb0)=19;return;
default:break;
}}
#pragma merge_duplicate_code reset
/* Turn-start wait step (MAP_STATE_TURN_START_WAIT): hold until the music from
 * the turn transition has faded out, then move on to the turn-start setup. */
void TurnStartWaitStep(void) {
    M2C_UNK IsMusicFadingOut();
    extern void **gCurrentMap;

    if (IsMusicFadingOut() != 0) {
        return;
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) = MAP_STATE_TURN_START_SETUP;
}

