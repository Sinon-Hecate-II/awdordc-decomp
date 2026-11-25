/* 23 functions from 0x020D166C to 0x020D2470 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u8 kind:6, flags:2; } UnitKindD1690;
typedef struct { u16 hp:7, flags:9; } UnitHpD1690;
static inline u8 PlayerStatusIndex(void *p) { return M2C_FIELD(p,s32 *,0x6810); }

void func_020d166c(s32 a, s32 b) {
    void RunBattle(s16, s16);
    if (!b) return;
    RunBattle((s16)a, (s16)b);
}

#pragma opt_strength_reduction off
void func_020d1690(s32 arg0, s32 arg1, void *arg2) {
    extern void **gCurrentMap;
    s32 GetDamageTargetIndex(s32);
    s32 CanUnitUsePrimaryWeapon(void *);
    s32 GetKindWeaponDamagePercent(s32, s32, s32);
    s32 CalculateUnitDamage(void *, s32, s32, s32);
    void InitBattleUnit(void *, s16);
    s32 Divide(s32, s32);
    s32 func_ov000_0216b154(s32);
    void ApplyBattleDamage(void *, s32, s32);

    s32 r4 = 0, r5 = 0, r6 = 0;
    u8 *unit = (u8 *)*gCurrentMap + 0x59a4 + arg0 * 14;
    u8 saved1 = unit[1];
    u8 saved2 = unit[2];
    s32 low7, d4, prod;
    u32 f6;
    u8 *m;
    s16 cc;

    if (arg2 != NULL) {
        unit[1] = (u8)*(s16 *)arg2;
        unit[2] = (u8)*((s16 *)arg2 + 1);
        InitBattleUnit((u8 *)*gCurrentMap + 0x6eb8, (s16)arg0);
    }
        if (CanUnitUsePrimaryWeapon(unit)) {
            r4 = CalculateUnitDamage(unit, GetDamageTargetIndex(arg1), 0, 0);
        } else {
            r6 = GetKindWeaponDamagePercent(((UnitKindD1690 *)unit)->kind, arg1, 1);
            if (r6) {
                r5 = CalculateUnitDamage(unit, GetDamageTargetIndex(arg1), 1, 0);
            }
        }

    if (r4 <= r5) {
        if (r6) {
            m = (u8 *)*gCurrentMap + 0x6e00;
            *(s16 *)(m + 0xd6) = 2;
            *(s16 *)((u8 *)*gCurrentMap + 0x6ed0) = r5;
        }
    } else {
        m = (u8 *)*gCurrentMap + 0x6e00;
        *(s16 *)(m + 0xd6) = 1;
        *(s16 *)((u8 *)*gCurrentMap + 0x6ed0) = r4;
        *(s16 *)((u8 *)*gCurrentMap + 0x6ec8) -= 1;
    }

    ApplyBattleDamage((u8 *)*gCurrentMap + 0x6eb8, 0, 0);

    {
        void *o = *(void **)((u8 *)*gCurrentMap + 0x6eb8);
        f6 = ((UnitHpD1690 *)((u8 *)o+6))->hp;
    }
    if (f6 == 0) {
        low7 = 0;
    } else {
        low7 = Divide(f6 - 1, 10) + 1;
    }
    m = (u8 *)*gCurrentMap;
    d4 = *(s16 *)(m + 0x6ed4);
    prod = Divide(d4 * low7, 10);
    *(s16 *)(m + 0x6ecc) = (s16)prod;
    *(s16 *)((u8 *)*gCurrentMap + 0x6ed4) = *(s16 *)((u8 *)*gCurrentMap + 0x6ecc);

    if (func_ov000_0216b154(arg1)) {
        cc = *(s16 *)((u8 *)*gCurrentMap + 0x6ecc);
        if (cc > 0) {
            *(s16 *)((u8 *)*gCurrentMap + 0x6ecc) = 1;
            *(s16 *)((u8 *)*gCurrentMap + 0x6ed4) = *(s16 *)((u8 *)*gCurrentMap + 0x6ecc);
        }
    }

    unit[1] = saved1;
    unit[2] = saved2;
}
#pragma opt_strength_reduction reset
s32 GetDefenderBonus(s32 *arg0) {
    M2C_UNK GetUnitOwner(s32);
    GetUnitOwner(*arg0);
    return 0;
}

/* Credit `player` with one more enemy unit destroyed: bump the player record's
 * saturating destroyed-enemy total (the battle code also passes the destroyed
 * unit's kind, which this counter does not use). */
void AddPlayerUnitDestroyed(s32 player) {
    extern void **gCurrentMap;
    u8 *record = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
    if ((u32)M2C_FIELD(record, u16 *, PLAYER_REC_UNITS_DESTROYED) < 0xffff) M2C_FIELD(record, u16 *, PLAYER_REC_UNITS_DESTROYED)++;
}

/* Whether player `player` is still in the battle: their record must have control
 * (not PLAYER_CONTROL_NONE) and no defeat turn yet. */
s32 IsPlayerActive(s32 player){extern void **gCurrentMap;u8 result;u8 *p=(u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE;if(!p[PLAYER_REC_CTRL])return 0;if(M2C_FIELD(p,u16 *,PLAYER_REC_DEFEAT_TURN)==0)result=1;else result=0;return result;}

/* Whether player `player` takes part in the battle: its record has a control
 * kind other than PLAYER_CONTROL_NONE. */
u8 IsPlayerPresent(s32 player) {
    extern void **gCurrentMap;
    return ((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE)[PLAYER_CONTROL_OFF] != PLAYER_CONTROL_NONE;
}

/* Whether player `player` is controlled by a human. */
s32 IsPlayerHuman(s32 player) {
    extern void **gCurrentMap;
    return (u8)(((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE)[PLAYER_CONTROL_OFF] == PLAYER_CONTROL_HUMAN);
}

/* Whether player `player` is a computer-controlled player. */
u8 IsPlayerCpu(s32 player){extern void **gCurrentMap;return ((u8 *)*gCurrentMap+player*MAP_PLAYER_STRIDE)[PLAYER_CONTROL_OFF]==PLAYER_CONTROL_CPU;}

/* Whether this console controls player `playerId`: every player in a
 * single-player battle (not a link battle), any human player in a link battle,
 * and a CPU player when this console is the link session's host (it runs the
 * AI for the CPU players on its side). */
s32 IsPlayerLocallyControlled(s32 playerId) {
    s32 IsLocalSessionHost();
    extern M2C_UNK gMapData;

    if (M2C_FIELD(&gMapData, u8 *, MAPDATA_LINK_BATTLE) == 0) return 1;
    if (IsPlayerHuman(playerId)) return 1;
    if (IsLocalSessionHost() && IsPlayerCpu(playerId)) return 1;
    return 0;
}

u8 IsPlayerArmyVariantSet(void) {
    s32 GetPlayerArmyVariantIfSet();
    u8 var_r0;

    if (GetPlayerArmyVariantIfSet() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Return 1 when the turn after the current player's begins a new day.  It scans
 * for the next active player (1..MAX_PLAYERS-1, wrapping) past the current one;
 * when that scan passes the end of the roster the turn order starts over, so the
 * next player's index is below the current one. */
u8 WillNextTurnStartNewDay(void) {
    extern void **gCurrentMap;
    u16 nextPlayer = M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER);
    do { nextPlayer++; if (nextPlayer == MAX_PLAYERS) nextPlayer = 1; } while (!IsPlayerActive(nextPlayer));
    return nextPlayer < M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER);
}

/* Whether any player slot from 1 to MAX_PLAYERS-1 holds a human player still in
 * the battle; the turn/record code uses it to tell a human turn from a CPU-only one. */
s32 HasActiveHumanPlayer(void) {
    s32 IsPlayerActive(s32);
    s32 found;
    s32 player;

    player = 1;
    found = 0;
    do {
        if ((IsPlayerActive(player) != 0) && (IsPlayerHuman(player) != 0)) {
            found = 1;
        }
        player += 1;
    } while (player < MAX_PLAYERS);
    return found;
}

/* Whether any human player slot (1..MAX_PLAYERS-1) has given up the battle. */
s32 HasHumanPlayerGivenUp(void) {
    s32 IsPlayerHuman(s32);
    s32 HasPlayerGivenUp(s32);
    s32 player;

    player = 1;
loop_1:
    if ((IsPlayerHuman(player) != 0) && (HasPlayerGivenUp(player) != 0)) {
        return 1;
    }
    player += 1;
    if (player >= MAX_PLAYERS) {
        return 0;
    }
    goto loop_1;
}

/* End of turn: move the current-player marker on to the next player still in
 * the battle, rolling the map turn over when it wraps past player 4 (counting
 * the turn in the records when a human is playing), then reset the new current
 * player's turn timer. */
void AdvancePlayerTurn(void) {
    void AdvanceMapTurn(void);
    void AddRecordValue(s32, s32);
    extern void **gCurrentMap;
    s32 humanTurn = HasActiveHumanPlayer();
    s32 player1 = 1;
    u8 *p;

    do {
        M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)++;
        if (M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) == 5) {
            AdvanceMapTurn();
            M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) = player1;
            if (humanTurn) AddRecordValue(player1, player1);
        }
    } while (!IsPlayerActive(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)));

    p = *gCurrentMap;
    M2C_FIELD(p + M2C_FIELD(p, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + PLAYER_REC_TURN_TIME) = 0;
}

void func_020d1c38(void) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C0) = 0;
}

/* Set up the new current player's phase: point the view at that player, set the
 * owner bits and unit-group base, make it the active player, split the players
 * into teams, then clear its team's sight bitmap and rebuild the map's cell
 * units and unit visibility. */
void BeginPlayerPhase(void){
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];
void SetupPlayerTeams(void);void FillTeamSightBitmap(s32);void func_020d0270(void);void RefreshUnitVisibility(void);
M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_OWNER)=M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)<<5;
M2C_FIELD(*gCurrentMap,u16 *,MAP_UNIT_GROUP_BASE)=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)];
M2C_FIELD(*gCurrentMap,u16 *,MAP_ACTIVE_PLAYER)=M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER);
SetupPlayerTeams();FillTeamSightBitmap((u8)M2C_FIELD(*gCurrentMap,u16 *,MAP_TEAM_A_PLAYER));func_020d0270();RefreshUnitVisibility();
}

/* Start the current player's turn: rewind the unit-slot allocation cursor, reset
 * the player's unit-sprite state, re-enable picking units while none is selected,
 * pay out the income of the properties the player owns, put the map cursor back on
 * the tile the player left it on and reload the player's palettes. */
void InitPlayerTurnState(void) {
    extern void **gCurrentMap;
    void func_020d2d80(s32);  /* clears the player's unit-sprite state bits 8..9 */
    void func_020d2d60(s32);  /* re-enables selection while the player has none */
    void PayPlayerIncome(s32);
    s32 IsPlayerCursorOwner(s32);   /* nonzero when the map cursor belongs to the player */
    void SetMapCursorTargetTile(s16, s16);
    void LoadPlayerPalettes(void);
    u8 *p; /* the player's record at MAP_PLAYER_STATES */

    M2C_FIELD(*gCurrentMap, u16 *, MAP_UNIT_SLOT_CURSOR) = 0;
    func_020d2d80(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    func_020d2d60(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    PayPlayerIncome(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    if (IsPlayerCursorOwner(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) {
        p = *gCurrentMap;
        p = p + MAP_PLAYER_STATES + M2C_FIELD(p, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE;
        SetMapCursorTargetTile(p[PLAYER_REC_CURSOR_X], p[PLAYER_REC_CURSOR_Y]);
    }
    LoadPlayerPalettes();
}

/* Load the palettes a player's turn draws with: UI palette row 3 and the current
 * player's army colour palette. */
void LoadPlayerPalettes(void) {
    void LoadUiSpritePalette(s32);
    void LoadPlayerArmyPalette(s32);
    extern void **gCurrentMap;
    LoadUiSpritePalette(3);
    LoadPlayerArmyPalette(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
}

/* Updates, for each of the four playable slots (i = 1..4), the cached display state (idle/busy flags etc.) that drives sprite selection for that slot. */
void func_020d1dc8(void) {
    extern void **gCurrentMap;
    extern u8 gMovementCostTable[];
    s32 IsCampaignBattleRules(void);
    s32 func_020a8ae0(u16, s32);
    s32 IsMapEditorMode(void);
    s32 i;
    s32 state, flag, other;
    i = 1;
    do {
        state = 0;
        flag = state;
        other = state;
        if (IsCampaignBattleRules()) state = func_020a8ae0(M2C_FIELD(*gCurrentMap, u16 *, 0x5142), i);
        if (state == 0) state = gMovementCostTable[((u32)(M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, s32 *, 0x6810) << 24) >> 24) * 0x9c + 0x23];
        if (IsMapEditorMode()) state = i;
        switch (state) {
        case 1:
        case 3:
            flag = 0;
            break;
        case 2:
        case 4:
        case 5:
            flag = 1;
            break;
        }
        switch (M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67ca)) {
        case 1:
        case 3:
            other = 1;
            break;
        case 2:
        case 4:
            other = 0;
            break;
        }
        M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67cb) = state;
        M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67cd) = flag;
        M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67cc) = other;
        if (IsMapEditorMode()) M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67c3) = 2;
        i++;
    } while (i < 5);
}

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
void InitMapPlayers(void) {
    extern void **gCurrentMap;
    extern M2C_UNK gMapData;
    s32 func_020cfb94(void);
    s32 SetPlayerTeam(s32, s32);
    s32 GetPlayerTeam(s32, s32);
    s32 GetPlayerIdForSlot(s32);
    s32 SetPlayerRecordArmyId(s32, s32);
    s32 GetPlayerCoId(s32);
    s32 func_020a2390(s32);
    void SetCoPowerMeterPoints(s32, s32);
    s32 GetPlayerArmyId(s32);
    s32 GetPlayerOwnerGroup(s32);
    s32 IsCampaignBattleRules(void);
    void func_020d2168(void);
    void func_020d1dc8(void);
    s32 AddPlayerUnitKind(s32, s32);


    {
        s32 r5 = 4 - func_020cfb94();
        if (r5 >= 1) {
            do {
                SetPlayerTeam(5 - r5, 0);
                r5--;
            } while (r5 >= 1);
        }
    }

    {
        u8 *p = (u8 *)*gCurrentMap + 0x67a4;
        p[0xaa] = (u8)GetPlayerTeam(1, (s32)*gCurrentMap + 0x3a4);
        p = (u8 *)*gCurrentMap + 0x67a4;
        p[0x136] = (u8)GetPlayerTeam(2, (s32)*gCurrentMap + 0x3a4);
        p = (u8 *)*gCurrentMap + 0x67a4;
        p[0x1c2] = (u8)GetPlayerTeam(3, (s32)*gCurrentMap + 0x3a4);
        p = (u8 *)*gCurrentMap + 0x67a4;
        p[0x24e] = (u8)GetPlayerTeam(4, (s32)*gCurrentMap + 0x3a4);
    }

    {
        s32 r8;
        s32 r9;
        r8 = 1;
        r9 = 0x8c;
        for (; r8 < 5; r8++, r9 += 0x8c) {
            u8 *r10 = (u8 *)*gCurrentMap + 0x67a4 + r9;

            r10[0x1d] = (u8)GetPlayerIdForSlot(r8);

            if (((u8 *)*gCurrentMap)[r9 + 0x67c2] == 0) {
                SetPlayerRecordArmyId(r8, 0);
            } else {
                SetPlayerRecordArmyId(r8, GetPlayerCoId(r8));
            }

            SetCoPowerMeterPoints(r8, func_020a2390(r8));

            r10 = (u8 *)*gCurrentMap + 0x67a4 + r9;
            r10[0x26] = (u8)GetPlayerArmyId(r8);

            r10 = (u8 *)*gCurrentMap + 0x67a4 + r9;
            r10[0x32] = (u8)GetPlayerOwnerGroup(r8);

            if (IsCampaignBattleRules() != 0) {
                ((u8 *)*gCurrentMap)[r9 + 0x67ce] = 2;
            } else {
                u16 val = M2C_FIELD(&gMapData, u16 *, 0xc);
                ((u8 *)*gCurrentMap)[r9 + 0x67ce] = (u8)(((u32)val << 26) >> 29);
            }
        }
    }

    func_020d2168();
    func_020d1dc8();

    {
        u32 val = M2C_FIELD(&gMapData, u16 *, 0xc);
        if (((u32)(val << 18) >> 31) == 0) {
            val &= -4097;
            M2C_FIELD(&gMapData, u16 *, 0xc) = (u16)val;
        }
    }

    {
        s32 r4;
        u8 *units;
        s32 low6;
        s32 r5v;
        r5v = 1;
        r4 = 0xe;
        for (; r5v < 256; r5v++, r4 += 0xe) {
            units = (u8 *)((s32)*gCurrentMap + 0x59a4);
            low6 = ((u32)(units[r4] << 26)) >> 26;
            if (low6 != 0) {
                AddPlayerUnitKind((r5v >> 6) + 1, low6);
            }
        }
    }

    return;
}
#pragma pop
void func_020d2168(void) {

}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_strength_reduction off
/* Initializes the per-player state of players 1..4 for a battle: starting
 * funds (from the match settings), flags, commander meter, selected unit and
 * the per-unit-kind counters, then builds the derived per-player data. */
void InitPlayerStates(void){
extern void **gCurrentMap;extern M2C_UNK gMapData;
void SetPlayerArmyVariant(s32,s32);void SetPlayerSpriteSet(s32,s32);void SetPlayerSpriteAuxBits(s32,s32);void SetCoPowerMeterPoints(s32,s32);void SetPlayerSelectedUnit(s32,s32);void SetPlayerGaveUp(s32,u8);void SetPlayerLost(s32,s32);void func_020d2d60(s32);void func_020d33c4(void);
s32 playerOffset; s32 player;
s32 unitKind;player=1;playerOffset=140;
do{
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x67a4)=M2C_FIELD(&gMapData,s32*,20);
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x67a8)=0;
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x67b0)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67bc)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67bd)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67c0)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u16*,0x67be)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u16*,0x67c4)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u16*,0x67c6)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67c1)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67c2)=0;
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67c3)=0;
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x6818)=0;
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x681c)=0;
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x6820)=0;
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x6824)=0;
M2C_FIELD((*gCurrentMap+0x67a4)+playerOffset,u32*,0x6c)&=~255;
SetPlayerArmyVariant(player,0);SetPlayerSpriteSet(player,0);SetPlayerSpriteAuxBits(player,0);
M2C_FIELD((*gCurrentMap+0x67a4)+playerOffset,u32*,0x6c)&=~0x3c000;
SetCoPowerMeterPoints(player,0);SetPlayerSelectedUnit(player,0);
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67ca)=player;M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67cb)=0;
SetPlayerGaveUp(player,0);SetPlayerLost(player,0);
M2C_FIELD((*gCurrentMap+playerOffset),u8*,0x67d5)=0;
unitKind=0;do{M2C_FIELD((void *)(unitKind+((s32)playerOffset+(s32)*gCurrentMap)),u8*,0x67d7)=0;M2C_FIELD((void *)(unitKind+((s32)playerOffset+(s32)*gCurrentMap)),u8*,0x67f2)=0;unitKind++;}while(unitKind<27);
func_020d2d60(player);
M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x6828)=0;M2C_FIELD((*gCurrentMap+playerOffset),s32*,0x682c)=0;
player++;playerOffset+=140;
}while(player<5);func_020d33c4();
}
#pragma pop
/* Whether player `player` still has a headquarters: the record's HQ tile x byte
 * marks "no HQ" with bit 7, so the player has one while that bit is clear. */
s32 PlayerHasHq(s32 player) {
    extern void **gCurrentMap;
    return (u8)((((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE)[PLAYER_HQ_X_OFF] & 0x80) == 0);
}

