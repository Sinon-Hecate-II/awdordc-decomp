/* 11 functions from 0x0219A584 to 0x0219B3C8 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
extern u8 data_ov000_021df7e4[64];
extern u8 *gAiCommandState;
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 data_ov000_021b5c05[];
extern u8 data_ov000_021b5c0a[];
extern void *gAiSettings;
extern void *gAiUnitTypeTuning;

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

void func_ov000_0219a6ec(void *arg0) {
s32 IsUnitSelected(void); s32 func_020a8604(u32,u32); s32 Divide(s32,s32);
u32 a,b;
if ((s32)M2C_FIELD(gAiUnitTypeTuning,u8 *,4) > (s32)((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x2000; return;
}
if(IsUnitSelected() && ((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)<50) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x2000; return;
}
a=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;
if(data_ov000_021b5c05[a*0x70]) {
b=(u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28;
if(b==0 && func_020a8604(a,b)==0) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x1000; return;
}
}
if((u8)Divide(((u32)(M2C_FIELD(arg0,u8 *,10)<<25)>>25)*100,data_ov000_021b5c0a[((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70]) >= (u32)M2C_FIELD(gAiUnitTypeTuning,u8 *,3)) return;
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x1000;
}

void func_ov000_0219a818(void *arg0) {
s32 func_020a8604(u32,u32);
u32 a,b;
a=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;
if(data_ov000_021b5c05[a*0x70]) {
b=(u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28;
if(b==0 && func_020a8604(a,b)==0) return;
}
if((s32)(data_ov000_021b5c0a[((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70]>>1)<(s32)((u32)(M2C_FIELD(arg0,u8 *,10)<<25)>>25))
M2C_FIELD(arg0,u16 *,8)&=~0x3000;
}

void func_ov000_0219a8a4(void *arg0) {
    if ((u32) ((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19) >= 0x3DU) {
        M2C_FIELD(arg0, u16 *, 8) = (u16) (M2C_FIELD(arg0, u16 *, 8) & ~0x3000);
    }
}

void func_ov000_0219a8c4(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 i;
    u8 *e;
    u32 type;
    u32 state;
    u16 start;
    void *base;
    base = *gCurrentMap;
    start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52a4)];
    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)] + 0x33; i++) {
        e = (u8 *)*gCurrentMap + 0x59a4 + i * 14;
        type = (u32)(e[0] << 26) >> 26;
        if (type == 0) continue;
        gAiUnitTypeTuning = (void *)((u8 *)gAiSettings + 0x14 + (type - 1) * 12);
        state = (u32)(M2C_FIELD(e, u16 *, 8) << 18) >> 30;
        switch (state) {
            case 1: func_ov000_0219a818(e); break;
            case 2: func_ov000_0219a8a4(e); break;
            default: func_ov000_0219a6ec(e); break;
        }
    }
}

void func_ov000_0219a9b0(void) {
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
