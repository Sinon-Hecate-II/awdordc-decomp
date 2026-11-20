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

void func_020d35d8(void) {
    M2C_UNK UpdateMapMode();
    M2C_UNK func_02081fec();
    M2C_UNK func_020b7bbc();
    extern void **gCurrentMap;
    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52B4) != 0) {
        UpdateMapMode();
        return;
    }
    func_02081fec();
    func_020b7bbc();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 0x16;
}

void func_020d3628(void) {
    M2C_UNK func_020844f8();
    M2C_UNK EndPlayerTurn();
    extern M2C_UNK gMapData;
    EndPlayerTurn();
    if (M2C_FIELD(&gMapData, u8 *, 4) == 0) {
        return;
    }
    func_020844f8();
}

s32 HandleOverlayResult(void) {
 M2C_UNK IsAiCommandTaskRunning();
 M2C_UNK GetActiveOverlay();
 M2C_UNK GetLinkPhase();
 void func_ov009_022244ec(M2C_UNK);
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
 func_ov009_022244ec(1); overlayResult=1;
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
    M2C_UNK func_0208b5a8();
    M2C_UNK GetActiveOverlay();
    M2C_UNK func_ov009_022241b4();
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
    if (func_0208b5a8() != 0) {
        return;
    }
    switch (GetActiveOverlay()) {
    case 1:
        CreateLinkStatusLabel(0, 0x25c, func_ov009_022241b4(), (void *)7);
        M2C_FIELD(&gMapData, u8 *, 7) = 0;
        func_02081fec();
        M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 0x19;
        break;
    case 2: {
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
            M2C_FIELD(&gMapData, u8 *, 5) = 0;
            { u16 t = M2C_FIELD(*gCurrentMap, u16 *, 0x52B2);
              M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = t; }
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

s32 func_020d39b4(void) {
    M2C_UNK GetActiveOverlay();
    M2C_UNK func_ov010_02228678(M2C_UNK *);
    extern M2C_UNK gMapData;
    s32 local;
    if (GetActiveOverlay() != 2) {
        return 0;
    }
    if (func_ov010_02228678(&local) != 0) {
        return 1;
    }
    M2C_FIELD(&gMapData, u8 *, 7) = local;
    return 0;
}

void func_020d39f4(s32 arg0) {
    M2C_UNK GetActiveOverlay();
    M2C_UNK CreateSpriteObject(M2C_UNK, M2C_UNK);
    extern M2C_UNK gMapData;
    extern M2C_UNK data_0212b9d4;
    switch (GetActiveOverlay()) {                      /* irregular */
    case 1:
        M2C_FIELD(&gMapData, u8 *, 7) = 0;
        return;
    case 2:
        CreateSpriteObject(&data_0212b9d4, arg0);
        return;
    }
}

void func_020d3a3c(void) {
    M2C_UNK UpdateMapMode();
    M2C_UNK func_0208b5a8();
    M2C_UNK func_02081fec();
    void CreateSpriteFromClass(void *, s32);
    extern void **gCurrentMap;
    extern char data_0212ba7c[];
    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52B4) != 0) {
        UpdateMapMode();
        return;
    }
    if (func_0208b5a8() != 0) {
        return;
    }
    func_02081fec();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 25;
    CreateSpriteFromClass(data_0212ba7c, 7);
}

#pragma optimization_level 2
void func_020d3aa4(void *arg0) {
 M2C_UNK func_02086330();
 M2C_UNK func_02085054(M2C_UNK, M2C_UNK, M2C_UNK);
 extern M2C_UNK gMapData;
 if (M2C_FIELD(&gMapData,u8 *,5) != 0 || M2C_FIELD(&gMapData,u8 *,7) == 0) {
 func_02086330();
 func_02085054(0,0x25c,arg0);
 }
}
#pragma optimization_level reset
void func_020d3ae4(void) {
    void CreateSpriteFromClass(void *, s32);
    extern void **gCurrentMap;
    extern char data_0212b9ac[];
    CreateSpriteFromClass(data_0212b9ac, 7);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 26;
}

void func_020d3b18(void) {
    M2C_UNK func_020d4614();
    func_020d4614();
}

void func_020d3b24(void) {
    M2C_UNK func_020d3400();
    M2C_UNK HandleOverlayResult();
    M2C_UNK UpdateTurnTimer();
    M2C_UNK IsUiModeSwitchBusy();
    M2C_UNK func_020d46e8();
    M2C_UNK func_020d4774();
    void CheckTurnLimitStep();
    void func_020d41c4();
    void func_020d422c();
    void func_020d4400();
    void func_020d4430();
    void func_020d447c();
    M2C_UNK func_020d457c();
    void func_020d4280();
    void func_020d42a8();
    void func_020d42d0();
    void func_020d42f8();
    void BeginPlayerTurn();
    M2C_UNK UpdateMapMode();
    M2C_UNK func_020d1a1c(M2C_UNK);
    M2C_UNK UpdateAiTurn();
    void UpdateLinkAiCommand();
    void func_020d45d8();
    M2C_UNK func_020d4614();
    M2C_UNK func_020d466c();
    void func_020d35d8();
    void func_020d3628();
    void func_020d3830();
    void func_020d3a3c();
    void func_020d3ae4();
    void func_020d3b18();
    extern void **gCurrentMap;

    func_020d3400();

    {
        void *ctl = M2C_FIELD(gCurrentMap, void **, 4);
        void (*cb)(void) = M2C_FIELD(ctl, void (**)(void), 0x30);
        if (cb != 0) {
            cb();
        }
    }

    if (HandleOverlayResult() != 0) return;
    if (UpdateTurnTimer() != 0) return;
    if (IsUiModeSwitchBusy() != 0) return;
    if (func_020d46e8() != 0) return;
    if (func_020d4774() != 0) return;

    {
        void *mainBase = *gCurrentMap;
        u8 *p = (u8 *)mainBase + 0x5200;
        
        
        switch (*(u16 *)(p + 0xb0)) {
        case 1:
            CheckTurnLimitStep();
            return;
        case 2:
            func_020d41c4();
            return;
        case 3:
            func_020d422c();
            return;
        case 4:
            func_020d4400();
            return;
        case 5:
            func_020d4430();
            return;
        case 6:
            func_020d447c();
            return;
        case 7:
            func_020d457c();
            return;
        case 8:
            func_020d4280();
            return;
        case 9:
            func_020d42a8();
            return;
        case 10:
            func_020d42d0();
            return;
        case 11:
            func_020d42f8();
            return;
        case 12:
            BeginPlayerTurn();
            return;
        case 13:
            UpdateMapMode();
            return;
        case 14:
            if (func_020d1a1c(*(u16 *)(p+0xa4))) { UpdateAiTurn(); return; }
            UpdateLinkAiCommand(); return;
        case 19: UpdateLinkAiCommand(); return;
        case 16: func_020d45d8(); return;
        case 18: func_020d4614(); return;
        case 20: func_020d466c(); return;
        case 21: func_020d35d8(); return;
        case 22: func_020d3628(); return;
        case 23: func_020d3830(); return;
        case 24: func_020d3a3c(); return;
        case 25: func_020d3ae4(); return;
        case 26: func_020d3b18(); return;
        default: return;
        }
    }
}

void func_020d3cec(void) {
    M2C_UNK LoadMapTileset();
    M2C_UNK ClearNameGraphicFiles();
    M2C_UNK LoadNameGraphicFiles();
    extern s32 data_0211fb58;
    extern s32 data_0215be00;
    extern s32 gSelectionQueue;
    gSelectionQueue = data_0211fb58;
    data_0215be00 = data_0211fb58;
    LoadMapTileset();
    ClearNameGraphicFiles();
    LoadNameGraphicFiles();
}

void func_020d3d24(void) {
    M2C_UNK ResetBattleMap();
    M2C_UNK LoadMapTileset();
    M2C_UNK LoadBattleMap(M2C_UNK);
    M2C_UNK func_020ceea8();
    M2C_UNK func_020a23c4();
    M2C_UNK func_020cfd14();
    M2C_UNK func_0207b6d0();
    M2C_UNK BeginPlayerPhase();
    M2C_UNK InitPlayerTurnState();
    extern void **gCurrentMap;
    ResetBattleMap();
    LoadMapTileset();
    LoadBattleMap(M2C_FIELD(*gCurrentMap, u16 *, 0x5142));
    func_020ceea8();
    func_020a23c4();
    func_020cfd14();
    func_0207b6d0();
    BeginPlayerPhase();
    InitPlayerTurnState();
}

void func_020d3d68(void) {
    u8 *GetPlayerSelectedUnit(s32);
    s32 PlayerHasHq(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    void *base;
    u16 cols;
    u16 rows;
    s32 r4;
    s32 r5;
    s32 r6;
    s32 r7;
    s32 val;
    s32 idx;
    s32 end;
    void *p;
    void *rec;
    u8 b0;

    base = *gCurrentMap;
    cols = M2C_FIELD(base, u16 *, 0x5144);
    rows = M2C_FIELD(base, u16 *, 0x5146);
    r5 = cols >> 1;
    r6 = rows >> 1;
    r7 = 0x8C;
    for (r4 = 1; r4 < 5; r4++) {
        if (GetPlayerSelectedUnit(r4) != 0) {
            p = GetPlayerSelectedUnit(r4);
            r5 = M2C_FIELD(p, u8 *, 1);
            r6 = M2C_FIELD(p, u8 *, 2);
        } else {
            if (PlayerHasHq(r4) != 0) {
                base = *gCurrentMap;
                r5 = M2C_FIELD((u8 *)base + r7, u8 *, 0x67CF) & 0x7F;
                r6 = M2C_FIELD((u8 *)base + r7, u8 *, 0x67D0) & 0x7F;
            } else {
                val = gPlayerUnitIdBase[r4];
                idx = val + 1;
                end = val + 0x33;
                for (; idx < end; idx++) {
                    base = *gCurrentMap;
                    rec = (u8 *)base + 0x59A4 + idx * 0x0E;
                    b0 = M2C_FIELD(rec, u8 *, 0);
                    b0 = (b0 << 26) >> 26;
                    if (b0 != 0) {
                        r5 = M2C_FIELD(rec, u8 *, 1);
                        r6 = M2C_FIELD(rec, u8 *, 2);
                        break;
                    }
                }
            }
        }
        base = *gCurrentMap;
        M2C_FIELD((u8 *)base + r7, u8 *, 0x67D1) = (u8)r5;
        base = *gCurrentMap;
        M2C_FIELD((u8 *)base + r7, u8 *, 0x67D2) = (u8)r6;
        r7 += 0x8C;
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

void func_020d4110(void) {
    M2C_UNK ResolvePropertyCountVictory();
    void CreateSpriteFromClass(void *, s32);
    extern M2C_UNK gMapData;
    extern char data_0212ba3c[];
    if (M2C_FIELD(&gMapData, u8 *, 4) != 0) {
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

void func_020d41c4(void) {
 M2C_UNK AdvancePlayerTurn(); M2C_UNK HumanPlayersOnDifferentArmies(); M2C_UNK func_020b78ac(); M2C_UNK IsCpuOnlyBattle(); void func_020d4110(void); extern void **gCurrentMap;
 void (*cb)(void)=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),void(**)(void),0x40);
 if(cb) cb();
 AdvancePlayerTurn();
 M2C_FIELD(*gCurrentMap,u16*,0x52B0)=3;
 if(HumanPlayersOnDifferentArmies()!=0){func_020b78ac();return;}
 if(IsCpuOnlyBattle()==0)return;
 func_020d4110();
}

void func_020d422c(void) {
    M2C_UNK func_020a3498(M2C_UNK);
    M2C_UNK BeginPlayerPhase();
    M2C_UNK InitPlayerTurnState();
    M2C_UNK func_020a23c4();
    M2C_UNK RefreshMapView();
    void func_020d427c(void);
    extern void **gCurrentMap;
    func_020a3498(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4));
    BeginPlayerPhase();
    InitPlayerTurnState();
    func_020a23c4();
    RefreshMapView();
    func_020d427c();
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 4;
}

void func_020d427c(void) {

}

void func_020d4280(void) {
    M2C_UNK func_020cbda4();
    extern void **gCurrentMap;
    func_020cbda4();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 9;
}

void func_020d42a8(void) {
    M2C_UNK func_020cbc08();
    extern void **gCurrentMap;
    func_020cbc08();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 0xa;
}

void func_020d42d0(void) {
    M2C_UNK func_ov000_0216a8a4();
    extern void **gCurrentMap;
    func_ov000_0216a8a4();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 11;
}

void func_020d42f8(void) {
    M2C_UNK IsDialogActive();
    M2C_UNK func_020a5ac8();
    extern void **gCurrentMap;
    if (IsDialogActive() != 0) {
        return;
    }
    func_020a5ac8();
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 0xc;
}

#pragma merge_duplicate_code off
/* Battle-map state 12: start the current player's turn.  A human who may act
 * plays it (state 13); a CPU, or a human the map does not let act on their own,
 * goes to the AI turn path (state 14, restarting the AI command phase); the
 * remaining link players skip to state 19. */
void BeginPlayerTurn(void){
M2C_UNK func_020c0a1c(M2C_UNK);void SetAiCommandPhase(s32);extern void **gCurrentMap;extern M2C_UNK gMapData;
u8 *map,*state;u16 player;u8 control;
func_020c0a1c(3);
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
void func_020d4400(void) {
    M2C_UNK func_0208f8a0();
    extern void **gCurrentMap;
    if (func_0208f8a0() != 0) {
        return;
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B0) = 5;
}

