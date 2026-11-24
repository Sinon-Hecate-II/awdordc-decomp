/* 39 functions from 0x020A1944 to 0x020A28F4 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u16 id:8; u16 index:4; u16 mode:4; } SaveInitEntry;

s32 GetRatingRank(s32 arg0) {
    if (arg0 < 0xC8) {
        return 1;
    }
    if (arg0 < 0xFA) {
        return 2;
    }
    if (arg0 < 0x12C) {
        return 3;
    }
    return 4;
}

/* Fills the battle-results block after a battle ends: stores the winning player
 * and their speed, power and technique ratings, their total and its rank, then
 * rebuilds the win/lose/draw player lists and the per-player property
 * statistics, and clears the block's reveal flags. */
void BattleResults_ComputeRatings(void) {
    s32 GetWinningPlayer(void);
    s32 GetSpeedRating(s32);
    s32 GetPowerRating(s32);
    s32 GetTechniqueRating(s32);
    s32 GetTotalRating(s32);
    void BattleResults_BuildPlayerLists(void);
    void BattleResults_ComputePlayerStats(void);
    extern M2C_UNK gBattleResults;
    s32 bit, flags, clearMask;

    M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_WINNER) = GetWinningPlayer();
    M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_SPEED) = GetSpeedRating(M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_WINNER));
    M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_POWER) = GetPowerRating(M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_WINNER));
    M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_TECHNIQUE) = GetTechniqueRating(M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_WINNER));
    M2C_FIELD(&gBattleResults, u16 *, BATTLE_RESULTS_TOTAL) = GetTotalRating(M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_WINNER));
    M2C_FIELD(&gBattleResults, u8 *, BATTLE_RESULTS_RANK) = GetRatingRank(M2C_FIELD(&gBattleResults, u16 *, BATTLE_RESULTS_TOTAL));
    BattleResults_BuildPlayerLists();
    BattleResults_ComputePlayerStats();
    bit = 0; flags = M2C_FIELD(&gBattleResults, s32 *, BATTLE_RESULTS_FLAGS);
    do { clearMask = -1 ^ (1 << bit); bit++; flags &= clearMask; } while (bit < 15);
    M2C_FIELD(&gBattleResults, s32 *, BATTLE_RESULTS_FLAGS) = flags;
}

#pragma peephole off
void BattleResults_BuildPlayerLists(void) {
    extern M2C_UNK gBattleResults;
    u8 *ctr;
    u8 *arr;
    s32 j;
    s32 i;
    u8 *p;

    p = (u8 *)&gBattleResults;
    for (i = 0; i < 4; i++, p++) {
        p[0] = 0;
        p[4] = 0;
        p[8] = 0;
    }
    ctr = (u8 *)&gBattleResults;
    arr = (u8 *)&gBattleResults;
    ctr[12] = 0;
    ctr[13] = 0;
    ctr[14] = 0;
    for (j = 1; j < 5; j++) {
        if (!IsPlayerPresent(j)) continue;
        switch (GetPlayerResult(j)) {
        case 1: {
            u8 idx = ctr[12];
            ctr[12] = idx + 1;
            arr[idx] = j;
            break;
        }
        case 2: {
            u8 idx = ctr[13];
            ctr[13] = idx + 1;
            arr[idx + 4] = j;
            break;
        }
        case 3: {
            u8 idx = ctr[14];
            ctr[14] = idx + 1;
            arr[idx + 8] = j;
            break;
        }
        default:
            break;
        }
    }
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void BattleResults_ComputePlayerStats(void){
extern s32 *gCurrentMap;extern u8 gCoPlayerSlots[],gCoState[];
s32 i,j,offset;register s32 y=0;u8 *out;u8 *base;s32 x;void **map2;u8 *rec,*attr; s32 cell,terrain;void **map;
out=gCoPlayerSlots;map=(void **)gCurrentMap;
for(j=1,offset=0x8c;j<5;j++,offset+=0x8c,out+=12){
M2C_FIELD(out,u16 *,12)=(u32)(M2C_FIELD((u8 *)*map+offset,s32 *,0x6810)<<24)>>24;
out[23]=M2C_FIELD((u8 *)*map+offset,u8 *,0x67c1);
for(i=0;i<8;i++)out[14+i]=0;
out[22]=0;
}
{map2=(void **)gCurrentMap;
for(y=0;y<M2C_FIELD(*map2,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD((base=*map2),u16 *,0x5144);x++){
cell=base[x+M2C_FIELD(base+y*2,u16 *,0x3758)+0x508];
if(cell){
rec=gCoState+(cell>>6)*12;
rec[34]++;
attr=(u8 *)*map2+0x59a4+cell*14;
if(attr[12])rec[34]++;
if(attr[13])rec[34]++;
}
base=*map2;
terrain=base[x+M2C_FIELD(base+y*2,u16 *,0x3758)+0x1420];
switch(terrain&31){case 16:{u8 *p=gCoState+(terrain>>5)*12;p[14]++;break;}
case 17:{u8 *p=gCoState+(terrain>>5)*12;p[15]++;break;}
case 18:{u8 *p=gCoState+(terrain>>5)*12;p[16]++;break;}
case 19:{u8 *p=gCoState+(terrain>>5)*12;p[17]++;break;}
case 20:{u8 *p=gCoState+(terrain>>5)*12;p[20]++;break;}
case 21:{u8 *p=gCoState+(terrain>>5)*12;p[21]++;break;}
case 22:{u8 *p=gCoState+(terrain>>5)*12;p[18]++;break;}
case 23:{u8 *p=gCoState+(terrain>>5)*12;p[19]++;break;}}
}
}}
}
#pragma pop
s32 GetTotalRating(s32 arg0) {
    extern M2C_UNK gBattleResults;
    s32 var_r0;

    var_r0 = M2C_FIELD(&gBattleResults, u8 *, 0x12) + (M2C_FIELD(&gBattleResults, u8 *, 0x10) + M2C_FIELD(&gBattleResults, u8 *, 0x11));
    if (var_r0 >= 0x3E8) {
        var_r0 = 0x3E7;
    }
    return var_r0;
}

/* The battle-results speed rating (0..150) for a player: 100 plus one point per
   percent of the map's turn limit still unused, or 100 minus a third of that per
   percent of the limit overshot, clamped to 0..150.  Returns 0 when the player is
   not active or the map sets no turn limit. */
s32 GetSpeedRating(s32 player) {
 s32 MapData_GetTurnLimit(u16); s32 IsPlayerActive(s32); s32 Divide(s32,s32);
 extern s32 *gCurrentMap;
 s32 base, result, difference;
 u16 current;
 base = MapData_GetTurnLimit(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
 if (IsPlayerActive(player) == 0) return 0;
 if (base == 0) return 0;
 current = M2C_FIELD(*gCurrentMap, u16 *, MAP_TURN);
 difference = base - current;
 if (difference < 0) difference = -difference;
 if (current <= base) result = Divide(difference * 100, base) + 100;
 else result = 100 - Divide(difference * 100, base * 3);
 if (result < 0) result = 0;
 if (result > 150) result = 150;
 return result;
}

/* The power battle rating (0..150) for a winning player: 100 plus twice the
 * average damage per attack. In the team mode (gMapConfig mode 0) the figures
 * of every player on the same army are summed, otherwise only the player's own
 * record is used. */
s32 GetPowerRating(s32 player) {
    extern s32 *gCurrentMap;
    extern u16 gMapConfig;
    s32 IsPlayerActive(s32);
    s32 func_0207c9c8(s32, s32);
    s32 damageDealt, attacks, battles, i, result;
    void *p, *q;

    if (!IsPlayerActive(player)) return 0;
    if ((u32)(gMapConfig << 29) >> 29 == 0) {
        damageDealt = 0;
        attacks = 0;
        battles = 0;
        for (i = 1, p = (u8 *)*gCurrentMap + MAP_PLAYER_STRIDE; i < 5; p = (u8 *)p + MAP_PLAYER_STRIDE, i++) {
            if (!M2C_FIELD(p, u8 *, PLAYER_CONTROL_OFF)) continue;
            q = (u8 *)*gCurrentMap + i * MAP_PLAYER_STRIDE;
            {
                u32 team = M2C_FIELD((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE, u8 *, PLAYER_ARMY_OFF);
                if (team != M2C_FIELD(q, u8 *, PLAYER_ARMY_OFF)) continue;
            }
            if (damageDealt + M2C_FIELD(q, s32 *, PLAYER_DAMAGE_DEALT_OFF) >= 0xfffffff || attacks + M2C_FIELD(q, s32 *, PLAYER_ATTACK_COUNT_OFF) >= 0xfffffff) continue;
            damageDealt += M2C_FIELD(q, s32 *, PLAYER_DAMAGE_DEALT_OFF);
            attacks += M2C_FIELD(q, s32 *, PLAYER_ATTACK_COUNT_OFF);
            battles += M2C_FIELD(q, s32 *, PLAYER_BATTLE_COUNT_OFF);
        }
    } else {
        p = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
        damageDealt = M2C_FIELD(p, s32 *, PLAYER_REC_DAMAGE_DEALT);
        attacks = M2C_FIELD(p, s32 *, PLAYER_REC_ATTACK_COUNT);
        battles = M2C_FIELD(p, s32 *, PLAYER_REC_BATTLE_COUNT);
    }
    if (!attacks) return 0;
    result = func_0207c9c8((battles * 100 + damageDealt) * 2, attacks) - 100;
    if (result >= 100) result = ((result - 100) >> 1) + 100;
    if (result < 0) result = 0;
    if (result > 150) result = 150;
    return result;
}

s32 GetTechniqueRating(s32 player) {
    extern s32 *gCurrentMap;
    extern s8 gProductionSiteTerrain[];
    s32 IsPlayerActive(s32); u32 CountPlayerUnitsBuilt(s32);u32 CountPlayerUnitsLost(s32);
    s32 Divide(s32,s32);
    u32 own,enemy,other,buildings,extra,delta;
    s32 i,offset,playerOffset,clear,x,y,result;
    void *q; register void *base;
    if(!IsPlayerActive(player))return 0;
    playerOffset=player*140;
    own=0;enemy=0;extra=0;other=0;buildings=0;
    for(i=1,offset=140;i<5;i++,offset+=140) {
        base=(void *)*gCurrentMap;q=(u8 *)base+offset;
        if(M2C_FIELD(q,u8 *,0x67c2)) {
            if(M2C_FIELD((u8 *)(playerOffset+(u32)base),u8 *,0x67ca)==M2C_FIELD(q,u8 *,0x67ca)) {
                own+=CountPlayerUnitsBuilt(i);
                extra+=CountPlayerUnitsLost(i);
                q=(u8 *)*gCurrentMap+offset;
                buildings+=M2C_FIELD(q,u16 *,0x67c6);
                other+=M2C_FIELD(q,u16 *,0x67c4);
            } else enemy+=CountPlayerUnitsBuilt(i);
        }
    }
    base=(void *)*gCurrentMap;
    clear=1;
    for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
        register u8 *row;
        for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
            row=(u8 *)base+M2C_FIELD(base,u16 *,0x3758+y*2)+x;
            if(gProductionSiteTerrain[M2C_FIELD(row,u8 *,0x1420)&31]!=0)clear=0;
        }
    }
    delta=clear;
    if(clear){if(own>enemy)delta=own-enemy;else delta=0;}
    if(own+extra==0)return 0;
    other=enemy-(other+buildings);
    other=enemy-other;
    result=Divide(((other+delta)*500)>>2,own+extra);
    if(result>=100)result=((result-100)>>1)+100;
    if(result<0)result=0;
    if(result>150)result=150;
    return result;
}

/* Fill the four player slots (MapSettings.players) of a map-settings record, the
 * current one when NULL, with the CO, army and team of the four players, after
 * resetting the rest of the record to its defaults.  A link session keeps the
 * slots the other consoles sent, and a map that sets no player control mode
 * (IsCampaignBattleRules) keeps the saved slots. */
void MapSettings_SavePlayers(u16 *settings) {
    s32 IsLinkSessionActive(void); s32 IsCampaignBattleRules(void);
    u16 *GetMapSettings(void); void MapSettings_SetDefaults(u16 *); void MapSettings_Capture(u16 *);
    s32 GetPlayerCoId(s32); s32 GetPlayerArmyId(s32); s32 GetPlayerTeam(s32);
    u16 *p;
    s32 i;
    u16 value;
    p = settings;
    if (p == 0) p = GetMapSettings();
    if (IsLinkSessionActive() != 0) return;
    if (IsCampaignBattleRules() != 0) return;
    MapSettings_SetDefaults(p);
    MapSettings_Capture(p);
    i = 0;
    do {
        *p = (*p & ~MAP_SETTINGS_PLAYER_CO) | (u8)(u16)GetPlayerCoId(i + 1);
        *p = (*p & ~MAP_SETTINGS_PLAYER_ARMY) | ((u32)((u16)GetPlayerArmyId(i + 1) << 28) >> 20);
        value = GetPlayerTeam(i + 1); i++;
        *p = (*p & ~MAP_SETTINGS_PLAYER_TEAM) | ((u32)(value << 28) >> 16);
        p++;
    } while (i < 4);
}

/* Applies a map-settings block (the current one when NULL) to the per-player
 * tables: each of the four slots gets the saved CO id if that CO is unlocked,
 * its army id and team.  In a link session the slots take the default COs and
 * their own slot number, all on the same team. */
void ApplyMapSettingsToPlayers(u16 *settings) {
u16 *GetMapSettings(void);
s32 IsCampaignBattleRules(void);
void MapSettings_Apply(u16 *);
s32 IsLinkSessionActive(void);
u32 IsCoUnlocked(s32);
void SetPlayerCoId(s32,s32);
void SetPlayerArmyId(s32,s32);
void SetPlayerTeam(s32,s32);
extern M2C_UNK gDefaultPlayerCoIds;
u16 *entries;
s32 i;
u16 rawEntry;
s32 savedCoId;
s32 coId;
s32 armyId;
s32 team;
s32 idx;
s32 slot;
if(settings==0){
entries=GetMapSettings(); settings=entries;
}
entries=settings;
if(IsCampaignBattleRules()!=0) return;
MapSettings_Apply(entries);
for(idx=1;idx<5;idx++){
SetPlayerCoId(idx,0);
SetPlayerArmyId(idx,idx);
SetPlayerTeam(idx,0);
}
entries=settings; i=0;
do {
rawEntry=*entries; coId=0; slot=i+1;
savedCoId=((SaveInitEntry *)entries)->id;
armyId=((SaveInitEntry *)entries)->index;
team=((SaveInitEntry *)entries)->mode;
if(IsCoUnlocked(savedCoId)) coId=((SaveInitEntry *)entries)->id;
if(IsLinkSessionActive()){
coId=M2C_FIELD(&gDefaultPlayerCoIds,u8 *,slot); armyId=slot; team=0;
}
SetPlayerCoId(slot,coId);
SetPlayerArmyId(slot,armyId);
SetPlayerTeam(slot,team);
i++;entries++;
}while(i<4);
}

s32 GetPlayerCoId(s32 arg0) {
    extern M2C_UNK data_0215c386;
    return M2C_FIELD(&data_0215c386, u8 *, arg0);
}

void SetPlayerCoId(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0215c386;
    M2C_FIELD(&data_0215c386, s8 *, arg0) = arg1;
}

void SetPlayerIdForSlot(s32 arg0, s8 arg1) {
    extern M2C_UNK data_0215c381;
    M2C_FIELD(&data_0215c381, s8 *, arg0) = arg1;
}

void SetPlayerArmyId(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0215c38b;
    M2C_FIELD(&data_0215c38b, s8 *, arg0) = arg1;
}

void func_020a233c(s32 arg0, s8 arg1) {
    extern M2C_UNK data_0215c390;
    M2C_FIELD(&data_0215c390, s8 *, arg0) = arg1;
}

void func_020a234c(s32 arg0, s16 arg1) {
 extern M2C_UNK data_0215c396;
 M2C_FIELD(&data_0215c396, s16 *, arg0 * 2) = arg1;
}

u8 GetPlayerIdForSlot(s32 arg0) {
    extern M2C_UNK data_0215c381;
    return M2C_FIELD(&data_0215c381, u8 *, arg0);
}

s32 GetPlayerArmyId(s32 arg0) {
    extern M2C_UNK data_0215c38b;
    return M2C_FIELD(&data_0215c38b, u8 *, arg0);
}

u8 GetPlayerOwnerGroup(s32 arg0) {
    extern M2C_UNK data_0215c390;
    return M2C_FIELD(&data_0215c390, u8 *, arg0);
}

u16 func_020a2390(s32 arg0) {
 extern M2C_UNK data_0215c396;
 return M2C_FIELD(&data_0215c396, u16 *, arg0 * 2);
}

void SetPlayerTeam(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0215c37c;
    M2C_FIELD(&data_0215c37c, s8 *, arg0) = arg1;
}

s32 GetPlayerTeam(s32 arg0) {
    extern M2C_UNK data_0215c37c;
    return M2C_FIELD(&data_0215c37c, u8 *, arg0);
}

/* Resets the per-turn combat fields of every active player - the flat terrain
 * defense bonus and the army movement-cost row beside it - then recounts the
 * players' derived data. */
void ResetPlayerTurnBonuses(void) {
    s32 IsPlayerActive(s32);
    M2C_UNK func_020d2470();
    extern s32 *gCurrentMap;
    s32 player;
    s32 playerOffset;

    player = 1;
    playerOffset = MAP_PLAYER_STRIDE;
    do {
        if (IsPlayerActive(player) != 0) {
            M2C_FIELD(*gCurrentMap + playerOffset, s8 *, MAP_PLAYER_STATES + PLAYER_REC_MOVE_COST_ROW) = 0;
            M2C_FIELD(*gCurrentMap + playerOffset, s8 *, MAP_PLAYER_STATES + PLAYER_REC_DEFENSE_BONUS) = 0;
        }
        player++;
        playerOffset += MAP_PLAYER_STRIDE;
    } while (player < MAX_PLAYERS);
    func_020d2470();
}

#pragma opt_propagation off
/* Builds the stat block `out` for the battle-map unit `unit` standing at tile
 * (x, y).  It starts empty and then applies the bonuses of the commander that
 * owns the unit, which count only for unit kinds the commander may deploy; a
 * unit that cannot attack loses its attack stat.  Returns 0 for an off-map
 * tile, 1 otherwise. */
s32 BuildUnitStatBlock(void *out, void *unit, s32 x, s32 y) {
    s32 GetUnitOwner(void *);
    u8 *GetPlayerSelectedUnit(s32);
    s32 GetPlayerCommanderId(s32);
    s32 GetMoveRangeCommanderId(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 GetUnitKindMaxAttackRange(s32);
    extern CommanderBonus gCommanderBonusTable[];
    UnitStatBlock *stats = (UnitStatBlock *)out;
    s32 owner;
    u32 kind;
    s32 commander;

    stats->stat[0] = 0;
    stats->stat[1] = 0;
    stats->stat[2] = 0;
    stats->stat[3] = 0;
    stats->stat[4] = 0;
    stats->stat[5] = 0;
    stats->stat[6] = 0;
    stats->value8 = 0;
    stats->valueA = 0;

    if (x < 0 || y < 0) { return 0; }

    owner = GetUnitOwner(unit);
    if (GetPlayerSelectedUnit(owner) == (u8 *)unit) {
        commander = GetPlayerCommanderId(owner);
    } else {
        commander = GetMoveRangeCommanderId(owner, x, y);
    }

    kind = M2C_FIELD(unit, u8 *, 0x0) << 26;
kind = kind >> 26;
    if (commander != -1) {

    stats->value8 = stats->value8 + 10;
    stats->valueA = stats->valueA + 10;

    {
        CommanderBonus *bonus = &gCommanderBonusTable[commander];
        if (bonus->canDeploy[kind] != 0) {
            stats->stat[0] = stats->stat[0] + bonus->base.stat[0];
            stats->stat[1] = stats->stat[1] + bonus->base.stat[1];
            stats->stat[2] = stats->stat[2] + bonus->base.stat[2];
            stats->stat[3] = stats->stat[3] + bonus->base.stat[3];
            stats->stat[4] = stats->stat[4] + bonus->base.stat[4];
            stats->stat[5] = stats->stat[5] + bonus->base.stat[5];
            stats->stat[6] = stats->stat[6] + bonus->base.stat[6];
            stats->value8 = stats->value8 + bonus->base.value8;
            stats->valueA = stats->valueA + bonus->base.valueA;
        }
    }

    if (GetUnitKindMaxAttackRange(kind) == 0) {
        stats->value8 = 0;
    }
    if (GetUnitKindMaxAttackRange(kind) < 2) {
        stats->stat[6] = 0;
    }
    }
    return 1;
}
#pragma opt_propagation reset
s32 func_020a25bc(s32 arg0, s32 arg1) {
 extern M2C_UNK data_0211fbf8;
 return arg1 + M2C_FIELD(&data_0211fbf8, s8 *, arg0 * 0x48);
}

s32 func_020a25d8(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s16 *, 8);
}

s32 func_020a2608(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s16 *, 10);
}

s32 GetUnitCaptureBonus(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 3);
}

s32 func_020a2668(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 4);
}

s32 GetUnitMoveBonus(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 2);
}

s32 func_020a26c8(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 6);
}

s32 func_020a26f8(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 5);
}

s32 func_020a2728(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 0);
}

s32 func_020a2758(s32 arg0, s32 arg1, s32 arg2) {
 s32 BuildUnitStatBlock(void *, void *, s32, s32);
 u32 data[3];
 BuildUnitStatBlock(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 1);
}

s8 func_020a2788(s32 arg0, s32 arg1) {
 extern M2C_UNK data_0211fc18;
 return *(s8 *)(arg1 + (arg0 * 0x48 + (s32)&data_0211fc18));
}

s8 func_020a27a0(s32 arg0, s32 arg1) {
 extern M2C_UNK gCoZoneKindEnabled;
 return *(s8 *)(arg1 + (arg0 * 0x48 + (s32)&gCoZoneKindEnabled));
}

/* Index of `commander`'s CO-zone bonus record in the given power state (0 = CO
 * zone off, 1 = CO power active): (commander - 1) * 2 + powerActive.  Returns -1
 * when the map is not in army mode (MAPCONFIG_ARMY_MODE) or the commander is
 * unset. */
s32 GetCoZoneBonusIndex(s32 commander, s32 powerActive) {
    extern u16 gMapConfig;
    s32 power;

    if (((u32) (gMapConfig << 0x12) >> 0x1F) == 0) {
        return -1;
    }
    if (commander == 0) {
        return -1;
    }
    if (powerActive != 0) {
        power = 1;
    } else {
        power = 0;
    }
    return power + ((commander - 1) * 2);
}

/* Whether the CO zone of `commander` boosts unit kind `kind`: the kind is
 * covered only when the commander has a zone-bonus record and that record's
 * per-kind flag is set. */
u8 IsUnitKindInCoZone(s32 kind,s32 commander) {
extern s32 *gCurrentMap;
extern M2C_UNK gCoZoneKindEnabled;
s32 row;
u8 covered;
row=GetCoZoneBonusIndex(((u32)(M2C_FIELD(*gCurrentMap+commander*MAP_PLAYER_STRIDE,s32 *,PLAYER_REC_SPRITE+MAP_PLAYER_STATES)<<24)>>24),0);
if(row==-1)return 0;
if(*(s8 *)(kind+(row*CO_ZONE_RECORD_STRIDE+(s32)&gCoZoneKindEnabled)))covered=1;
else covered=0;
return covered;
}

/* Attack bonus the CO zone of `commander` gives unit kind `kind`: only kinds
 * the commander's zone covers and kinds that can attack at all receive it. */
s32 GetCoZoneAttackBonus(s32 kind, s32 commander, s32 powerActive) {
    extern s32 *gCurrentMap;
    extern M2C_UNK gCoZoneKindEnabled;
    extern s16 gCoZoneAttackPct;
    s32 GetUnitKindMaxAttackRange(s32);
    s32 row;
    s32 result;

    row = GetCoZoneBonusIndex(((u32)(M2C_FIELD(*gCurrentMap + commander * MAP_PLAYER_STRIDE, s32 *, PLAYER_REC_SPRITE + MAP_PLAYER_STATES) << 24) >> 24), powerActive);
    if (row == -1) return 0;
    row *= CO_ZONE_RECORD_STRIDE;
    if (!*(s8 *)(kind + ((s32)&gCoZoneKindEnabled + row))) return 0;
    if (GetUnitKindMaxAttackRange(kind) == 0) result = 0;
    else result = M2C_FIELD(&gCoZoneAttackPct, s16 *, row);
    return result;
}

