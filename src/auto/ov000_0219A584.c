/* 11 functions from 0x0219A584 to 0x0219B3C8 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
extern u8 data_ov000_021df7e4[64];
extern u8 *gAiCommandState;
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindMaxAmmo[];
extern u8 gUnitKindMaxFuel[];
extern void *gAiSettings;
extern void *gAiUnitTypeTuning;
extern const u8 gPropertyCapabilityBits[4];
extern s8 gTerrainPropertyType[];
extern u8 gUnitKindStats[];
typedef struct AiCapabilityFields { u16 all : 3; u16 own : 3; u16 enemy : 3; u16 ownProperties : 3; u16 enemyProperties : 3; u16 unused : 1; } AiCapabilityFields;
/* The AI's capability word in the command state, and the property-capability
 * bits of the map cell at (x, y) (propertyFlags holds gPropertyCapabilityBits). */
#define AI_CAP ((AiCapabilityFields *)(gAiCommandState + 10))
#define CELL_TERRAIN(x, y) ((u8 *)*gCurrentMap)[M2C_FIELD((u8 *)*gCurrentMap + ((y) << 1), u16 *, MAP_ROW_OFFSETS) + (x) + MAP_CELL_TERRAIN]
#define CELL_PROPERTY_BITS(x, y) propertyFlags[gTerrainPropertyType[CELL_TERRAIN(x, y) & MAP_TERRAIN_KIND_MASK]]

void func_ov000_0219a584(void) {
s32 func_ov000_0219a3b0(s32); s32 IsPlayerActive(s32); s32 IsSameTeam(u16,s32);
s32 i;
gAiCommandState[4]=0;
gAiCommandState[4]+=func_ov000_0219a3b0(0);
for(i=1;i<5;i++) {
if(IsPlayerActive(i) && !IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),i))
gAiCommandState[4]+=func_ov000_0219a3b0(i);
}
}

void func_ov000_0219a618(void) {
s32 IsPlayerActive(s32); s32 i,j,end;
for(i=1;i<5;i++) if(IsPlayerActive(i)) {
s32 start=gPlayerUnitIdBase[i];
for(j=start+1;j<start+0x33;j++) {
u8 *p=(u8 *)*gCurrentMap+0x59a4+j*14;
if((u32)(p[0]<<26)>>26) {
M2C_FIELD(p,u16 *,8)&=~0xc000; p[11]&=~0x20; p[10]&=~0x80;
}
}
}
}

void func_ov000_0219a6c8(void) {
s32 i=0; u8 *p=data_ov000_021df7e4; u8 zero=i;
do { i++; *p++=zero; } while(i<64);
}

void SelectAiUnitSupplyState(void *arg0) {
s32 IsUnitSelected(void); s32 func_020a8604(u32,u32); s32 Divide(s32,s32);
u32 a,b;
if ((s32)M2C_FIELD(gAiUnitTypeTuning,u8 *,4) > (s32)((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x2000; return;
}
if(IsUnitSelected() && ((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)<50) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x2000; return;
}
a=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;
if(gUnitKindMaxAmmo[a*0x70]) {
b=(u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28;
if(b==0 && func_020a8604(a,b)==0) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x1000; return;
}
}
if((u8)Divide(((u32)(M2C_FIELD(arg0,u8 *,10)<<25)>>25)*100,gUnitKindMaxFuel[((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70]) >= (u32)M2C_FIELD(gAiUnitTypeTuning,u8 *,3)) return;
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x1000;
}

void UpdateAiUnitSupplyState(void *arg0) {
s32 func_020a8604(u32,u32);
u32 a,b;
a=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;
if(gUnitKindMaxAmmo[a*0x70]) {
b=(u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28;
if(b==0 && func_020a8604(a,b)==0) return;
}
if((s32)(gUnitKindMaxFuel[((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70]>>1)<(s32)((u32)(M2C_FIELD(arg0,u8 *,10)<<25)>>25))
M2C_FIELD(arg0,u16 *,8)&=~0x3000;
}

void UpdateAiUnitRepairState(void *arg0) {
    if ((u32) ((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19) >= 0x3DU) {
        M2C_FIELD(arg0, u16 *, 8) = (u16) (M2C_FIELD(arg0, u16 *, 8) & ~0x3000);
    }
}

/* Updates the resupply and repair needs of the current player's units: each
 * unit's AI tuning record is selected from its kind, then its need state (none,
 * resupply or repair) is re-checked by the matching helper. */
void UpdateAiSupplyStates(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitId;
    u8 *unit;
    u32 kind;
    u32 state;
    u16 firstUnitId;
    void *map;
    map = *gCurrentMap;
    firstUnitId = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
    for (unitId = firstUnitId + 1; unitId < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; unitId++) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        kind = (u32)(unit[MAP_UNIT_KIND] << 26) >> 26;
        if (kind == 0) continue;
        gAiUnitTypeTuning = (void *)((u8 *)gAiSettings + 0x14 + (kind - 1) * 12);
        state = (u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_NEED_STATE) << 18) >> 30;
        switch (state) {
            case 1: UpdateAiUnitSupplyState(unit); break;
            case 2: UpdateAiUnitRepairState(unit); break;
            default: SelectAiUnitSupplyState(unit); break;
        }
    }
}

#pragma opt_strength_reduction off
/* Rebuild the AI's capability word for the current map: the property types the
 * AI team and its enemies own, then the movement capabilities (sea, air and the
 * special kinds) of every active player's units. */
void UpdateAiCapabilityFlags(void) {
    s32 IsPropertyOwnedByTeam(u16, s32, s32);
    s32 IsPlayerActive(s32);
    s32 IsCurrentPlayerUnit(s16);
    s32 IsSameTeam(u16, s32);
    u8 propertyFlags[4];
    s32 y, x, player, unitId, unitOffset;
    u8 *unit;
    u32 kind;

    propertyFlags[0] = gPropertyCapabilityBits[0];
    propertyFlags[1] = gPropertyCapabilityBits[1];
    propertyFlags[2] = gPropertyCapabilityBits[2];
    propertyFlags[3] = gPropertyCapabilityBits[3];
    AI_CAP->all = 0;
    AI_CAP->own = 0;
    AI_CAP->enemy = 0;
    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH); x++) {
            if (!IsPropertyOwnedByTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), x, y)) {
                AI_CAP->enemy |= CELL_PROPERTY_BITS(x, y);
            }
            if ((CELL_TERRAIN(x, y) & MAP_TERRAIN_OWNER_MASK) == M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_OWNER)) {
                AI_CAP->own |= CELL_PROPERTY_BITS(x, y);
            }
            AI_CAP->all |= CELL_PROPERTY_BITS(x, y);
        }
    }
    AI_CAP->ownProperties = AI_CAP->own;
    AI_CAP->enemyProperties = AI_CAP->enemy;
    for (player = 1; player < 5; player++) if (IsPlayerActive(player)) {
        unitId = gPlayerUnitIdBase[player] + 1;
        if (unitId < gPlayerUnitIdBase[player] + MAP_UNIT_GROUP_SCAN) {
            unitOffset = unitId * MAP_UNIT_STRIDE;
            do {
                unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS;
                kind = (u32)(unit[unitOffset] << 26) >> 26;
                if (kind) {
                    if (gUnitKindStats[kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_FLAGS] & UNIT_KIND_FLAGS_AIR) {
                        AI_CAP->all = (u16)(AI_CAP->all | 4);
                        if (IsCurrentPlayerUnit((s16)unitId) == 1) { AI_CAP->own = (u16)(AI_CAP->own | 4); }
                        if (!IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player)) { AI_CAP->enemy = (u16)(AI_CAP->enemy | 4); }
                        if (((u32)(unit[unitOffset] << 26) >> 26) == 21) {
                            AI_CAP->all = (u16)(AI_CAP->all | 8);
                            if (IsCurrentPlayerUnit((s16)unitId) == 1) { AI_CAP->own = (u16)(AI_CAP->own | 8); }
                            if (!IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player)) { AI_CAP->enemy = (u16)(AI_CAP->enemy | 8); }
                        }
                    }
                    else if (kind == 17) {
                        AI_CAP->all = (u16)(AI_CAP->all | 8);
                        if (IsCurrentPlayerUnit((s16)unitId) == 1) { AI_CAP->own = (u16)(AI_CAP->own | 8); }
                        if (!IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player)) { AI_CAP->enemy = (u16)(AI_CAP->enemy | 8); }
                    }
                    else if (gUnitKindStats[kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_FLAGS] & UNIT_KIND_FLAGS_SEA) {
                        AI_CAP->all = (u16)(AI_CAP->all | 2);
                        if (IsCurrentPlayerUnit((s16)unitId) == 1) { AI_CAP->own = (u16)(AI_CAP->own | 2); }
                        if (!IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player)) { AI_CAP->enemy = (u16)(AI_CAP->enemy | 2); }
                    }
                }
                unitId++;
                unitOffset += MAP_UNIT_STRIDE;
            } while (unitId < gPlayerUnitIdBase[player] + MAP_UNIT_GROUP_SCAN);
        }
    }
}
s32 ApplyStatSpread(s32 arg0, s32 arg1, s32 arg2) {
    s32 Divide(s32, M2C_UNK);
    s32 var_r0;

    var_r0 = arg0 + (Divide(arg1 * arg2, 0x64) - (arg1 >> 1));
    if (var_r0 < 1) {
        var_r0 = 1;
    }
    if (var_r0 > 0xFF) {
        var_r0 = 0xFF;
    }
    return var_r0;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Builds the AI's per-unit-type parameter records in the settings block (arg0) from
 * the unit set's base stats and its tuning block: each record gets a scaled base value
 * and two randomized cost/threat thresholds.  The spread is halved in story battles
 * (a fixed-AI player) to keep the values stable. */
void BuildAiUnitParameters(void *arg0,s32 arg1,s32 arg2){
s32 RandomIntRange(s32,s32);s32 Divide(s32,s32);s32 ApplyStatSpread(s32,s32,s32);extern void **gCurrentMap;extern u8 gAiUnitSetStats[],gAiUnitTuningSets[];
u8 *settings=arg0,*setStats;s32 roll;u8 *tuning; s32 unit;u8 *tune,*recOut;s32 midRoll;void *map;
setStats=gAiUnitSetStats+arg1*AI_SET_STRIDE;tuning=gAiUnitTuningSets+arg2*AI_TUNING_STRIDE;roll=RandomIntRange(0,100);map=*gCurrentMap;
if(M2C_FIELD(M2C_FIELD(map,u16*,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE+(s32)((u8*)map+MAP_PLAYER_STATES),u8*,PLAYER_REC_AI_MODE)==3)roll=0;else if(M2C_FIELD(M2C_FIELD(map,u16*,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE+(s32)((u8*)map+MAP_PLAYER_STATES),u8*,PLAYER_REC_AI_MODE)==1)roll=100;
recOut=settings+AI_UNIT_RECORD_STRIDE;*(s32*)settings=*(s32*)tuning;tune=tuning+AI_TUNING_RECORD;*(s32*)(settings+4)=*(s32*)(tuning+4);midRoll=roll>>1;unit=1;
settings[8]=setStats[0];settings[9]=setStats[1];settings[10]=setStats[2];settings[11]=setStats[3];settings[12]=setStats[4];settings[13]=setStats[5];settings[14]=setStats[6];settings[15]=setStats[7];settings[16]=setStats[8];settings[17]=setStats[9];settings[18]=setStats[10];settings[19]=setStats[11];
do{s32 a=M2C_FIELD((u16*)setStats+unit,u8*,10);s32 b=tune[1];recOut[8]=Divide(a*b,100);recOut[13]=M2C_FIELD((u16*)setStats+unit,u8*,11);map=*gCurrentMap;if((s32)M2C_FIELD(map,u16*,0x52a2)<10&&((u8*)map+M2C_FIELD(map,u16*,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE)[MAP_PLAYER_STATES+PLAYER_REC_AI_MODE]==2){recOut[9]=ApplyStatSpread(tune[2],tune[3],midRoll);recOut[10]=ApplyStatSpread(tune[4],tune[5],midRoll);}else{recOut[9]=ApplyStatSpread(tune[2],tune[3],roll);recOut[10]=ApplyStatSpread(tune[4],tune[5],roll);}unit++;recOut[11]=tune[6];recOut[12]=tune[7];tune+=AI_TUNING_RECORD;recOut+=AI_UNIT_RECORD_STRIDE;}while(unit<AI_UNIT_RECORDS);
}
#pragma opt_common_subs off
/* Pick and build the AI's per-unit parameter table for this battle: the map's
 * AI category and the player's army choose a unit-set template and parameter
 * block, with separate variants for story battles and human-controlled players. */
void SetupAiUnitParameters(s32 player) {
s32 GetMapAiCategory(u16);s32 IsPlayerHuman(u16);extern u16 gMapConfig;extern void **gCurrentMap;extern u8 gAiUnitSetIndex[],gAiUnitSetVariant[],gAiUnitSetTable[],gAiUnitSetTableHuman[];extern void *gAiSettings;
void *map; s32 setCategory,variantCategory;
if(GetMapAiCategory(M2C_FIELD(*gCurrentMap,u16*,0x5142))){
if((u32)(gMapConfig<<18)>>31){map=*gCurrentMap;setCategory=GetMapAiCategory(M2C_FIELD(map,u16*,0x5142));variantCategory=GetMapAiCategory(M2C_FIELD(map,u16*,0x5142));BuildAiUnitParameters(gAiSettings,gAiUnitSetIndex[setCategory*2],(gAiUnitSetTable+gAiUnitSetVariant[variantCategory*2]*15)[(u32)(M2C_FIELD(player*140+(s32)map,s32*,0x6810)<<24)>>24]);return;}
if(!(((u32)(gMapConfig<<29)>>29)&255)&&IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16*,0x52a4))==1){map=*gCurrentMap;setCategory=GetMapAiCategory(M2C_FIELD(map,u16*,0x5142));BuildAiUnitParameters(gAiSettings,gAiUnitSetIndex[setCategory*2],gAiUnitSetTableHuman[(u32)(M2C_FIELD(player*140+(s32)map,s32*,0x6810)<<24)>>24]);return;}
map=*gCurrentMap;setCategory=GetMapAiCategory(M2C_FIELD(map,u16*,0x5142));variantCategory=GetMapAiCategory(M2C_FIELD(map,u16*,0x5142));BuildAiUnitParameters(gAiSettings,gAiUnitSetIndex[setCategory*2],gAiUnitSetTable[gAiUnitSetVariant[variantCategory*2]*15]);return;
}
if((u32)(gMapConfig<<18)>>31){BuildAiUnitParameters(gAiSettings,gAiUnitSetIndex[2],(gAiUnitSetTable+gAiUnitSetIndex[3]*15)[(u32)(M2C_FIELD(player*140+(s32)*gCurrentMap,s32*,0x6810)<<24)>>24]);return;}
BuildAiUnitParameters(gAiSettings,gAiUnitSetIndex[2],gAiUnitSetTable[gAiUnitSetIndex[3]*15]);
}
#pragma opt_common_subs reset
