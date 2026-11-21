/* 17 functions from 0x021A3DAC to 0x021A4A98 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
#include "battle_map.h"
#include "ov000_ai.h"
static inline void *GetCandidateMapState(void) { extern void **gCurrentMap; return *gCurrentMap; }

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 PlanUnitKind24Action(void) {
 s32 FindAiBuildTargetCandidate(s32);void ResetAiTargetCandidates(void);
 void FloodFillUnitRange(u8,u8,s32,s32,s32);s32 GetUnitMoveRange(u16,s32);void MarkAdjacentCellsForKind24(u8);
 s32 GetTerrainPropertyFlagsAt(s32,s32);s32 IsUnitOnCurrentTeam(s32);s32 IsFootUnitKind(s32);s32 IsCaptureKind(s32);
 s32 IsCurrentPlayerUnit(s16);s32 IsMidActionStep(s32);void CommitAiAction(s32);
 extern void **gCurrentMap;extern u8 gAiTargetCandidates[];extern u8 gUnitKindStats[];extern M2C_UNK gAiCommand;
 s32 other,armed,transport,flag,index,i;
 u8 *candidate;
 u8 *unit;
 s32 id,capture,y,x,combat,carrier,tile;
 s32 required;
 void *map;
 void **holder;
 for(;;){
 index=FindAiBuildTargetCandidate(3);
 if(index==-1){ResetAiTargetCandidates();return 0;}
 candidate=gAiTargetCandidates+index*12;
 FloodFillUnitRange(candidate[0],candidate[1],2,110,0);
 for(i=0;i<GetUnitMoveRange(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),24);i++)MarkAdjacentCellsForKind24((u8)(i+111));
 combat=0;capture=0;carrier=0;armed=0;y=0;other=0;transport=0;flag=0;map=GetCandidateMapState();
 for(;y<M2C_FIELD(map,u16 *,0x5146);y++){
 for(x=0;x<M2C_FIELD(map,u16 *,0x5144);){
 tile=M2C_FIELD(M2C_FIELD((u8 *)map+y*4,s8 **,0x52e8),s8 *,x);
 if(tile<0)goto nextCell;
 if(tile<=110){
 if(GetTerrainPropertyFlagsAt(x,y)==1)goto foundFlag;
 {
 map=*gCurrentMap;
 {u8 terrain=M2C_FIELD((u8 *)map+x+M2C_FIELD((u8 *)map+y*2+0x3700,u16 *,0x58),u8 *,0x1420);
 if((terrain&31)!=18||M2C_FIELD(map,u16 *,0x52a6)!=(terrain&0xe0))goto checkedFlag;}
 foundFlag:flag=1;
 checkedFlag:;
 }
 }
 map=*gCurrentMap;
 id=M2C_FIELD((u8 *)map+x+M2C_FIELD((u8 *)map+y*2+0x3700,u16 *,0x58),u8 *,0);
 if(!id)goto nextCell;
 unit=(u8 *)map+0x59a4+id*14;
 if(!IsUnitOnCurrentTeam(id)){
 if(!IsFootUnitKind(((UnkStruct_ov000_021A860C *)unit)->unk0))goto nextCell;
 if(!(M2C_FIELD(gUnitKindStats+((UnkStruct_ov000_021A860C *)unit)->unk0*112,u8 *,0x13)&7))goto nextCell;
 goto discard;
 }
 if(IsCurrentPlayerUnit((s16)id)!=1)goto nextCell;
 if(M2C_FIELD(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x)<=110) {
 if(((u32)(M2C_FIELD(unit,u16 *,8)<<16)>>30)==2){
 if(IsCaptureKind(((UnkStruct_ov000_021A860C *)unit)->unk0))capture=(s8)(capture+1);else combat=(s8)(combat+1);
 } else {
 if(IsCaptureKind(((UnkStruct_ov000_021A860C *)unit)->unk0))other=(s8)(other+1);
 else if(M2C_FIELD(gUnitKindStats+((UnkStruct_ov000_021A860C *)unit)->unk0*112,u8 *,0x13)&7)armed=(s8)(armed+1);
 }
 }
 if((((UnkStruct_ov000_021A860C *)unit)->unk0)==24&&!unit[12]&&!IsMidActionStep(((UnkStruct_ov000_021A860C *)unit)->unkB))transport=(s8)(transport+1);
 if((((UnkStruct_ov000_021A860C *)unit)->unk0)==25&&!unit[12]&&!IsMidActionStep(((UnkStruct_ov000_021A860C *)unit)->unkB))carrier=(s8)(carrier+1);
 nextCell:x++;map=*gCurrentMap;
 }
 }
 if(!flag)capture=(s8)(capture+other);
 capture=(s8)(capture-carrier*2);if(capture<0)capture=0;
 if(!(combat+armed)&&capture<=1)goto discard;
 required=transport+1;
 if(required*4>combat+capture)goto discard;
 M2C_FIELD(&gAiCommand,u8 *,6)=24;CommitAiAction(index);ResetAiTargetCandidates();return 1;
 discard: candidate[3]=253;
 }
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
/* Decide whether the AI builds a kind-24 unit now: the build flag must be set and
 * the unit affordable, an existing kind-24 action wins, and otherwise a target
 * must exist with enough ready combat units waiting for the empty kind-24 units. */
s32 TryBuildKind24Unit(void){
s32 GetUnitBuildCost(u16,s32);u8 HasAiBuildFlag(s32);s32 PlanUnitKind24Action(void);
s32 FindAiBuildTargetCandidate(s32);s32 FindAiTargetOfType(s32);u8 CountPlayerUnitsOfKind(s32);
s32 CountReadyCombatUnits(void);s32 CountReadyCaptureUnits(void);s32 CountEmptyUnitsOfKind(s32);
void CommitAiAction(s32);
extern void **gCurrentMap;extern M2C_UNK gAiCommand;
void *map;u16 playerId;s32 availableUnits,targetIndex,readyCombat,kind25Empty,kind24Empty,capacity;
if(!HasAiBuildFlag(AI_BUILD_FLAG_UNIT_24))return 0;
map=*gCurrentMap;playerId=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
if(GetUnitBuildCost(playerId,24)*10>M2C_FIELD((u8 *)map+playerId*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF))return 0;
if(PlanUnitKind24Action()==1)return 1;
targetIndex=FindAiBuildTargetCandidate(3);if(targetIndex==-1){targetIndex=FindAiTargetOfType(3);if(targetIndex==-1)return 0;}
availableUnits=CountPlayerUnitsOfKind(24);readyCombat=CountReadyCombatUnits();
if(!readyCombat){if(CountReadyCaptureUnits()<=1)return 0;}
if(availableUnits){kind24Empty=CountEmptyUnitsOfKind(24)+1;kind25Empty=CountEmptyUnitsOfKind(25);capacity=CountReadyCaptureUnits()-kind25Empty*2;if(capacity<0)capacity=0;if(readyCombat+capacity<kind24Empty*4)return 0;}
M2C_FIELD(&gAiCommand,u8 *,AI_COMMAND_UNIT)=24;CommitAiAction(targetIndex);return 1;
}

/* AI turn-plan step 10: record the AI's infantry and mech total, then try to
 * build a transport, a kind-24 unit, a kind-25 unit and a kind-13 unit, in that
 * order.  Returns 1 once one build has been committed, 0 when none was. */
u8 TryBuildSpecialistUnits(void) {
    s32 TryBuildTransport();
    s32 TryBuildUnitKind13();
    s32 TryBuildUnitKind25();
    s32 TryBuildKind24Unit();
    u8 CountPlayerUnitsOfKind(s32);
    extern void *gAiState;
    u8 built;
    u8 mechCount;

    M2C_FIELD(gAiState, u8 *, AI_STATE_INFANTRY_MECH) = CountPlayerUnitsOfKind(UNIT_KIND_INFANTRY);
    mechCount = CountPlayerUnitsOfKind(UNIT_KIND_MECH);
    M2C_FIELD(gAiState, u8 *, AI_STATE_INFANTRY_MECH) += mechCount;
    if (TryBuildTransport() == 1) {
        return 1U;
    }
    if (TryBuildKind24Unit() == 1) {
        return 1U;
    }
    if (TryBuildUnitKind25() == 1) {
        return 1U;
    }
    if (TryBuildUnitKind13() == 1) {
        built = 1;
    } else {
        built = 0;
    }
    return built;
}

u8 HasAiBuildFlag(s32 arg0) {
    extern void *gAiSettings;
    u8 var_r0;

    if (M2C_FIELD(gAiSettings, u8 *, 0x11) & arg0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 HasAiOptionalUnitBuildFlag(void) {
    extern void *gAiSettings;
    u8 var_r0;

    if (M2C_FIELD(gAiSettings, u8 *, 0x11) & 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021a43e8(s32 kind) {
    s32 IsFootUnitKind(s32);

    return IsFootUnitKind(kind) != 0 || kind == 4;
}

/* Kind-10 build rule: walk the acting player's units; for every non-foot,
 * combat-flagged kind count the direct (class 0) and indirect (class 1) ones.
 * Reject the turn's build plan when direct units outnumber indirect ones 3:1
 * (returns 0), otherwise accept (1). */
s32 IsIndirectUnitRatioOk(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    u8 *units;
    s32 direct;
    s32 indirect;
    s32 i;
    s32 idx;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)];

    direct = 0;
    indirect = 0;
    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)] + 0x33; i++) {
        units = (u8 *)base + 0x59a4;
        idx = i * 14;
        if ((u32)(units[idx] << 26) >> 26) {
            if (!func_ov000_021a43e8((u32)(units[idx] << 26) >> 26)) {
                if (gUnitKindStats[((u32)(units[idx] << 26) >> 26) * 112 + 19] & 7) {
                    if (GetUnitAttackClass((u32)(units[idx] << 26) >> 26) == 0) direct++;
                    if (GetUnitAttackClass((u32)(units[idx] << 26) >> 26) == 1) indirect++;
                }
            }
        }
        base = *gCurrentMap;
    }
    if (direct > indirect * 3) return 0;
    return 1;
}

/* Kind-26 build rule: walk the acting player's units; for every non-foot,
 * combat-flagged kind count the direct (attack class 0) and indirect (class 1)
 * ones.  Reject the turn's build plan when direct units outnumber indirect ones
 * (returns 0), otherwise accept (1). */
s32 IsSubmarineRatioOk(void) {
    s32 func_ov000_021a43e8(s32);
    s32 GetUnitAttackClass(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    s32 direct = 0;
    s32 indirect = 0;
    s32 i;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];

    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
        u8 *entry = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        if (((u32)(entry[0] << 26) >> 26) != 0 && !func_ov000_021a43e8((u32)(entry[0] << 26) >> 26)) {
            if (gUnitKindStats[((u32)(entry[0] << 26) >> 26) * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_FLAGS] & 7) {
                if (GetUnitAttackClass((u32)(entry[0] << 26) >> 26) == UNIT_ATTACK_DIRECT) direct++;
                if (GetUnitAttackClass((u32)(entry[0] << 26) >> 26) == UNIT_ATTACK_INDIRECT) indirect++;
            }
        }
    }
    if (direct > indirect) return 0;
    return 1;
}

/* Kind-11 build rule: walk the acting player's units; for every non-foot,
 * combat-flagged kind except kind 26 (submarine) count the direct (class 0)
 * and indirect (class 1) ones.  Reject the turn's build plan when direct units
 * outnumber indirect ones 2:1 (returns 0), otherwise accept (1). */
s32 IsDirectUnitRatioOk(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    s32 direct = 0;
    s32 indirect = 0;
    s32 i;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)];

    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33; i++) {
        u8 *entry = (u8 *)*gCurrentMap + 0x59a4 + i * 14;
        if (((u32)(entry[0] << 26) >> 26) != 0 && !func_ov000_021a43e8((u32)(entry[0] << 26) >> 26)) {
            if (gUnitKindStats[((u32)(entry[0] << 26) >> 26) * 112 + 19] & 7 && ((u32)(entry[0] << 26) >> 26) != 26) {
                if (GetUnitAttackClass((u32)(entry[0] << 26) >> 26) == 0) direct++;
                if (GetUnitAttackClass((u32)(entry[0] << 26) >> 26) == 1) indirect++;
            }
        }
    }
    if (direct > (indirect << 1)) return 0;
    return 1;
}

s32 func_ov000_021a4704(void) {
    s32 func_ov000_021a43e8(s32);
    s32 GetUnitAttackClass(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    u8 *entries;
    s32 count5 = 0;
    s32 count6 = 0;
    s32 count11 = 0;
    s32 count7 = 0;
    s32 count8 = 0;
    s32 i;
    s32 idx;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)];

    i = start + 1;
    if (i < (s32)(start + 0x33)) {
        idx = i * 0xE;
        entries = (u8 *)base + 0x59A4;
        do {
            if (((u32)((entries[idx]) << 0x1A) >> 0x1A) != 0) {
                if (func_ov000_021a43e8(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                    if (gUnitKindStats[((u32)((entries[idx]) << 0x1A) >> 0x1A) * 0x70 + 0x13] & 7) {
                        if (((u32)((entries[idx]) << 0x1A) >> 0x1A) == 0x1A) {
                            count11 += 1;
                        } else {
                            if (GetUnitAttackClass(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                                count5 += 1;
                            }
                            if (GetUnitAttackClass(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 1) {
                                count6 += 1;
                            }
                        }
                        if (((u32)((entries[idx]) << 0x1A) >> 0x1A) == 6) {
                            count7 += 1;
                        }
                        if (((u32)((entries[idx]) << 0x1A) >> 0x1A) == 0xC) {
                            count8 += 1;
                        }
                    }
                }
            }
            i += 1;
            idx += 0xE;
        } while (i < (s32)(gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33));
    }
    if (count7 <= (count8 << 1)) {
        return 1;
    }
    if (count6 != 0) {
        count6 += count11 >> 1;
    }
    if (count5 > (count6 << 1)) {
        return 0;
    }
    return 1;
}

s32 func_ov000_021a484c(s32 arg0, s32 arg1) {
    s32 IsIndirectUnitRatioOk();
    s32 IsSubmarineRatioOk();
    s32 IsDirectUnitRatioOk();
    s32 func_ov000_021a4704();

    switch (arg1) {
    case 10:
        return IsIndirectUnitRatioOk();
    case 26:
        return IsSubmarineRatioOk();
    case 11:
        return IsDirectUnitRatioOk();
    case 12:
        return func_ov000_021a4704();
    }
    return 1;
}

u8 func_ov000_021a48ac(s32 arg0) {
    extern u8 gAiGroupDirectUnits[];
    extern u8 gAiGroupIndirectUnits[];
    u8 var_r0;

    if (gAiGroupDirectUnits[arg0 * 8] <= gAiGroupIndirectUnits[arg0 * 8] * 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a48dc(s32 arg0) {
    extern u8 gAiGroupDirectUnits[];
    extern u8 gAiGroupIndirectUnits[];
    s32 temp_r0;
    s32 temp_r2;
    u8 var_r0;

    temp_r2 = gAiGroupDirectUnits[arg0 * 8];
    temp_r0 = gAiGroupIndirectUnits[arg0 * 8];
    if (temp_r2 <= temp_r0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021a4908(s32 arg0) {
    extern u8 gAiGroupDirectUnits[];
    extern u8 gAiGroupIndirectUnits[];
    extern u8 gAiGroupKind26Units[];
    u8 *p98;
    s32 var_r3;
    s32 temp_r1;

    var_r3 = gAiGroupIndirectUnits[arg0 * 8];
    temp_r1 = var_r3 - gAiGroupKind26Units[arg0 * 8];
    p98 = gAiGroupDirectUnits;
    if (temp_r1 != 0) {
        var_r3 = temp_r1;
    }
    if (p98[arg0 * 8] > (var_r3 << 1)) {
        return 0;
    }
    return 1;
}

#pragma opt_propagation off
s32 func_ov000_021a4944(s32 arg0) {
    extern u8 gAiGroupDirectUnits[];
    extern u8 gAiGroupIndirectUnits[];
    extern u8 gAiGroupKind26Units[];
    s32 temp_r1;
    s32 temp_r2;
    s32 var_ip;
    s32 temp_r3;

    var_ip = gAiGroupIndirectUnits[arg0 * 8];
    temp_r1 = gAiGroupKind26Units[arg0 * 8];
    temp_r2 = var_ip - temp_r1;
    temp_r3 = gAiGroupDirectUnits[arg0 * 8];
    if (temp_r2 != 0) {
        var_ip = temp_r2 + (temp_r1 >> 1);
    }
    if (temp_r3 > (var_ip << 1)) {
        return 0;
    }
    return 1;
}
#pragma opt_propagation reset
s32 func_ov000_021a4980(s32 arg0, s32 arg1) {
    u8 func_ov000_021a48ac(s32);
    u8 func_ov000_021a48dc(s32);
    s32 func_ov000_021a4908(s32);
    s32 func_ov000_021a4944(s32);

    switch (arg1) {
    case 10:
        return func_ov000_021a48ac(arg0);
    case 26:
        return func_ov000_021a48dc(arg0);
    case 11:
        return func_ov000_021a4908(arg0);
    case 12:
        return func_ov000_021a4944(arg0);
    }
    return 1;
}

/* Decide whether the AI may reserve money (AI_STATE_SHORTFALL) for a purchase it
 * cannot afford yet: nothing may be reserved already, the price must sit inside
 * the army-adjusted income window, and funds plus one income, minus the army
 * value, must cover the price. */
u8 CanReservePurchaseFunds(s32 price) {
    s32 Divide(s32, M2C_UNK);
    s32 func_020a886c(u16, M2C_UNK);
    extern void **gCurrentMap;
    extern void *gAiState;
    s32 income;
    s32 armyValue;
    s32 record;
    void *map;
    u16 player;
    u8 result;

    if (M2C_FIELD(gAiState, s32 *, AI_STATE_SHORTFALL) != 0) {
        return 0U;
    }
    armyValue = M2C_FIELD(gAiState, s32 *, AI_STATE_ARMY_VALUE);
    map = *gCurrentMap;
    player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
    record = (player * MAP_PLAYER_STRIDE) + (s32) ((u8 *) map + MAP_PLAYER_STATES);
    income = M2C_FIELD(record, s32 *, PLAYER_REC_INCOME);
    if (price <= (s32) (income - armyValue)) {
        return 0U;
    }
    if (price > (s32) ((income * 2) - armyValue)) {
        return 0U;
    }
    if ((s32) (price + Divide((func_020a886c(player, 0) + 0x64) * 0x7D0, 0x64)) < (s32) ((M2C_FIELD(record, s32 *, PLAYER_REC_FUNDS) + M2C_FIELD(record, s32 *, PLAYER_REC_INCOME)) - armyValue)) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

