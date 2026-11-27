/* 1 function from 0x02176E28 to 0x02177CE0 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
s32 GetUnitAttackClass(s32);s32 IsFootUnitKind(s32);s32 IsAiCombatSpecialUnitKind(s32);s32 IsCaptureTargetAt(void *,s32,s32);s32 GetUnitDamagePercent(s32,s32);s32 CountThreateningEnemies(void *);

extern void **gCurrentMap;extern u8 gUnitKindBuildCosts[],gUnitKindFlags[],gAiTargetValueTable[],gAiProductionSiteAreaBitmap[],gAiSafeDirectRangeBitmap[],gAiSafeIndirectRangeBitmap[],gAiIndirectRangeBitmap[],gAiRangeBitmap[];extern u8 *gAiUnitTypeTuning,*gAiCommandState;
void RunBattleIfTarget(s32,u16,void *);s32 IsUnitSelected(void *);s32 GetKindAttackClass(s32);s32 Divide(s32,s32);s32 GetTileDamageRating(s32,s32,void *,s32);s32 IsCellOwnedByOtherArmy();s32 WillCaptureCompleteThisTurn(void *);
static inline u8 Tile76(s32 x,s32 y,s32 offset){u8 *map=*gCurrentMap;return M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,offset);}
static inline u8 Bit76(u8 *bits,s32 x,s32 y){u32 index=x+y*M2C_FIELD(*gCurrentMap,u16 *,0x5144);return bits[index>>3]&(1<<(index&7));}


s32 IsCellOwnedByOtherArmy();
/* Score a candidate AI attack target at `position`: price the health the attacker
 * loses (its build cost times the HP the previewed strike takes off it) against
 * the health the target loses, adjust that value for the units' kinds, weapons,
 * cover, terrain and the situation flags in `targetFlags`, and return the score
 * (0 = not worth attacking, 0xFFFF = the forced target of a full-action step). */
s32 GetAiTargetScore(u32 targetFlags,u32 position){
u8 *attacker,*defender,*map; s16 *pos=(s16 *)position;s32 loss,gain,value=1,tileRating,cellIndex,attackerKind,defenderKind,unitFlags,attackerFlags,defenderFlags,score;u32 terrainKind;
RunBattleIfTarget(M2C_FIELD((*gCurrentMap),u8 *,MAP_CURSOR_UNIT_ID),(u16)targetFlags,pos);
if(!M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_WINNER))return 0;
attacker=M2C_FIELD((*gCurrentMap),u8 * *,MAP_BATTLE_ATTACKER);defender=M2C_FIELD((*gCurrentMap),u8 * *,MAP_BATTLE_DEFENDER);
if(((u32)(M2C_FIELD(M2C_FIELD((*gCurrentMap),u8 * *,MAP_CURSOR_UNIT),u8 *,MAP_UNIT_AI_STATE)<<28)>>28)==AI_STEP_FULL_ACTION && IsUnitSelected(defender))return 0xffff;
if(((u32)(attacker[0]<<26)>>26)==UNIT_KIND_UNARMED&&M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)&&GetKindAttackClass(((u32)(defender[0]<<26)>>26))==2)return 0;
if(targetFlags&AI_TARGET_FLAG_UNIT){if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_ATTACKER_UNK1A)>=10)return 0;if(!M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_ATTACKER_HEALTH))return 0;}
if(targetFlags&AI_TARGET_FLAG_CAPTURE){if(GetKindAttackClass(((u32)(defender[0]<<26)>>26))==2)return 0;if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)&&M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_UNK1A)<30)return 0;}
loss=Divide(M2C_FIELD(gUnitKindBuildCosts+((u32)(attacker[0]<<26)>>26)*UNIT_KIND_STATS_SIZE,u16 *,UNIT_KIND_STATS_COST)*((s32)((u32)(M2C_FIELD(attacker,u16 *,MAP_UNIT_HEALTH)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_ATTACKER_HEALTH)),100);
gain=Divide(M2C_FIELD(gUnitKindBuildCosts+((u32)(defender[0]<<26)>>26)*UNIT_KIND_STATS_SIZE,u16 *,UNIT_KIND_STATS_COST)*((s32)((u32)(M2C_FIELD(defender,u16 *,MAP_UNIT_HEALTH)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)),100);
if(IsUnitSelected(defender)&&!M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH))gain=M2C_FIELD(gUnitKindBuildCosts+((u32)(defender[0]<<26)>>26)*UNIT_KIND_STATS_SIZE,u16 *,UNIT_KIND_STATS_COST);
tileRating=GetTileDamageRating(pos[0],pos[1],defender,M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH));
if((u32)(M2C_FIELD(defender,u16 *,MAP_UNIT_HEALTH)<<16)>>27){
map=*gCurrentMap;cellIndex=defender[MAP_UNIT_X]+M2C_FIELD(map+defender[MAP_UNIT_Y]*2,u16 *,MAP_ROW_OFFSETS);terrainKind=M2C_FIELD(map+cellIndex,u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK;
if(terrainKind==MAP_TERRAIN_HQ){cellIndex=attacker[MAP_UNIT_X]+M2C_FIELD(map+attacker[MAP_UNIT_Y]*2,u16 *,MAP_ROW_OFFSETS);if(!IsCellOwnedByOtherArmy(M2C_FIELD(map+cellIndex,u8 *,MAP_CELL_UNIT_ID),defender[MAP_UNIT_X],defender[MAP_UNIT_Y])&&WillCaptureCompleteThisTurn(defender)==1)goto special;}
}
if(targetFlags&AI_TARGET_FLAG_FROM_BASE){if(GetKindAttackClass(((u32)(defender[0]<<26)>>26))==2)return 0;if(gain<Divide(M2C_FIELD(gAiTargetValueTable,u16 *,AI_TARGET_VALUE_BASE)*60,100))return 0;}
if(targetFlags&(AI_TARGET_FLAG_ACTOR_SELECTED|AI_TARGET_FLAG_ACTOR_KIND21)){
if(((u32)(M2C_FIELD(attacker,u16 *,MAP_UNIT_HEALTH)<<25)>>25)>=40){
if(Bit76(gAiProductionSiteAreaBitmap,pos[0],pos[1]))goto passed;
attackerKind=((u32)(attacker[0]<<26)>>26);
if((attackerKind==14||attackerKind==16)&&(((u32)(defender[0]<<26)>>26)==14||((u32)(defender[0]<<26)>>26)==15||((u32)(defender[0]<<26)>>26)==16||((u32)(defender[0]<<26)>>26)==17))goto passed;
if(attackerKind==22&&(((u32)(defender[0]<<26)>>26)==20||((u32)(defender[0]<<26)>>26)==21))goto passed;
}
map=*gCurrentMap;cellIndex=M2C_FIELD(map+pos[1]*2,u16 *,MAP_ROW_OFFSETS)+pos[0];terrainKind=M2C_FIELD(map+cellIndex,u8 *,MAP_CELL_THREAT_INDIRECT);
if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_ATTACKER_HEALTH)<=tileRating+(s32)terrainKind)return 0;
if(terrainKind>=gAiUnitTypeTuning[AI_UNIT_RECORD_THREAT_INDIRECT])return 0;
if(tileRating>=gAiUnitTypeTuning[AI_UNIT_RECORD_THREAT_DIRECT]){
unitFlags=gUnitKindFlags[((u32)(attacker[0]<<26)>>26)*UNIT_KIND_STATS_SIZE];
if((unitFlags&7)&&!Bit76(gAiSafeDirectRangeBitmap,pos[0],pos[1]))return 0;
if((unitFlags&16)&&!Bit76(gAiSafeIndirectRangeBitmap,pos[0],pos[1]))return 0;
}
}
passed:
if(((u32)(M2C_FIELD(gAiCommandState,u16 *,AI_COMMAND_STATE_MODE)<<20)>>29)&1 && (targetFlags&AI_TARGET_FLAG_MANY_HITS)){
if(GetUnitAttackClass(((u32)(defender[0]<<26)>>26))!=1||((u32)(defender[0]<<26)>>26)==26){
attackerFlags=gUnitKindFlags[((u32)(attacker[0]<<26)>>26)*UNIT_KIND_STATS_SIZE];unitFlags=attackerFlags&16;
if(unitFlags&&(gUnitKindFlags[((u32)(defender[0]<<26)>>26)*UNIT_KIND_STATS_SIZE]&7)&&!Bit76(gAiIndirectRangeBitmap,pos[0],pos[1])){if(tileRating>=gAiUnitTypeTuning[AI_UNIT_RECORD_THREAT_DIRECT])return 0;if(M2C_FIELD((u8 *)(*gCurrentMap)+(pos[0]+M2C_FIELD((u8 *)(*gCurrentMap)+pos[1]*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_THREAT_INDIRECT)>=gAiUnitTypeTuning[AI_UNIT_RECORD_THREAT_INDIRECT])return 0;}
defenderFlags=gUnitKindFlags[((u32)(defender[0]<<26)>>26)*UNIT_KIND_STATS_SIZE];
if((defenderFlags&7)&&Bit76(gAiRangeBitmap,pos[0],pos[1]))goto combat_check;
if((defenderFlags&16)&&Bit76(gAiIndirectRangeBitmap,pos[0],pos[1]))goto combat_check;
if((attackerFlags&7)&&Bit76(gAiSafeDirectRangeBitmap,pos[0],pos[1]))goto combat_check;
if(unitFlags&&Bit76(gAiSafeIndirectRangeBitmap,pos[0],pos[1]))goto combat_check;
if(tileRating>=gAiUnitTypeTuning[AI_UNIT_RECORD_THREAT_DIRECT])return 0;
if(M2C_FIELD((u8 *)(*gCurrentMap)+(pos[0]+M2C_FIELD((u8 *)(*gCurrentMap)+pos[1]*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_THREAT_INDIRECT)>=gAiUnitTypeTuning[AI_UNIT_RECORD_THREAT_INDIRECT])return 0;
}}
if((targetFlags&AI_TARGET_FLAG_CHASE_INDIRECT)&&!IsFootUnitKind(((u32)(attacker[0]<<26)>>26))&&((u32)(attacker[0]<<26)>>26)!=4){
if(GetKindAttackClass(((u32)(defender[0]<<26)>>26))==2)return 0;
if(M2C_FIELD(gAiTargetValueTable,u16 *,AI_TARGET_VALUE_CHASE)<=M2C_FIELD(gUnitKindBuildCosts+((u32)(attacker[0]<<26)>>26)*UNIT_KIND_STATS_SIZE,u16 *,UNIT_KIND_STATS_COST)){if(gain<Divide(M2C_FIELD(gAiTargetValueTable,u16 *,AI_TARGET_VALUE_CHASE)*40,100))return 0;}
else if(gain<Divide(M2C_FIELD(gAiTargetValueTable,u16 *,AI_TARGET_VALUE_BASE)*40,100))return 0;
if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)&&M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_UNK1A)<20)return 0;
if(M2C_FIELD((u8 *)(*gCurrentMap)+M2C_FIELD((*gCurrentMap),u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_REC_AI_MODE+MAP_PLAYER_STATES)==3)return 0;
}
if((targetFlags&AI_TARGET_FLAG_REACH_SUBMARINE)&&((u32)(defender[0]<<26)>>26)!=UNIT_KIND_SUBMARINE&&M2C_FIELD((u8 *)(*gCurrentMap)+M2C_FIELD((*gCurrentMap),u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_REC_AI_MODE+MAP_PLAYER_STATES)!=0){
if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)&&M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_UNK1A)<20)return 0;
if(GetKindAttackClass(((u32)(defender[0]<<26)>>26))==2&&(gUnitKindFlags[((u32)(defender[0]<<26)>>26)*UNIT_KIND_STATS_SIZE]&32))return 0;
}
combat_check:
if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)&&(s32)((u32)(M2C_FIELD(defender,u16 *,MAP_UNIT_HEALTH)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)<=10)gain>>=2;
if((s32)((u32)(M2C_FIELD(attacker,u16 *,MAP_UNIT_HEALTH)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_ATTACKER_HEALTH)>=70 && M2C_FIELD((u8 *)(*gCurrentMap)+M2C_FIELD((*gCurrentMap),u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_REC_AI_MODE+MAP_PLAYER_STATES)!=0)gain>>=2;
special:
if((IsAiCombatSpecialUnitKind(((u32)(attacker[0]<<26)>>26))&&IsAiCombatSpecialUnitKind(((u32)(defender[0]<<26)>>26)))||(((u32)(attacker[0]<<26)>>26)==15&&((u32)(defender[0]<<26)>>26)==23)||(((u32)(attacker[0]<<26)>>26)==15&&((u32)(defender[0]<<26)>>26)==6)||(((u32)(attacker[0]<<26)>>26)==23&&((u32)(defender[0]<<26)>>26)==22)){gain+=gain>>1;loss>>=1;}
attackerKind=((u32)(attacker[0]<<26)>>26);unitFlags=gUnitKindFlags[((u32)(attacker[0]<<26)>>26)*UNIT_KIND_STATS_SIZE]&7;
if(unitFlags&&((u32)(defender[0]<<26)>>26)==9){gain+=gain>>1;if(attackerKind==9)loss>>=1;}
if(unitFlags&&((u32)(defender[0]<<26)>>26)==26){gain+=gain>>1;if((u8)(attackerKind+248)<=1)loss>>=1;}
if(IsUnitSelected(defender))gain<<=1;
if(!M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)&&IsCaptureTargetAt(defender,defender[MAP_UNIT_X],defender[MAP_UNIT_Y])==1)gain+=Divide(M2C_FIELD(gUnitKindBuildCosts+((u32)(defender[0]<<26)>>26)*UNIT_KIND_STATS_SIZE,u16 *,UNIT_KIND_STATS_COST)*20,100);
if(IsFootUnitKind(((u32)(defender[0]<<26)>>26))){
if(((u32)(defender[0]<<26)>>26)==UNIT_KIND_INFANTRY)gain<<=1;else gain=(gain*3)>>1;
if((u32)(M2C_FIELD(defender,u16 *,MAP_UNIT_HEALTH)<<16)>>27){
map=*gCurrentMap;cellIndex=attacker[MAP_UNIT_X]+M2C_FIELD(map+attacker[MAP_UNIT_Y]*2,u16 *,MAP_ROW_OFFSETS);
if(IsCellOwnedByOtherArmy(M2C_FIELD(map+cellIndex,u8 *,MAP_CELL_UNIT_ID),defender[MAP_UNIT_X],defender[MAP_UNIT_Y])!=1){
map=*gCurrentMap;cellIndex=defender[MAP_UNIT_X]+M2C_FIELD(map+defender[MAP_UNIT_Y]*2,u16 *,MAP_ROW_OFFSETS);terrainKind=M2C_FIELD(map+cellIndex,u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK;
if(terrainKind==MAP_TERRAIN_HQ)value<<=3;else if(terrainKind==MAP_TERRAIN_BASE)value<<=2;else if(terrainKind==MAP_TERRAIN_AIRPORT||terrainKind==MAP_TERRAIN_PORT||terrainKind==MAP_TERRAIN_COM_TOWER)value<<=1;
if(WillCaptureCompleteThisTurn(defender)==1){
if(!M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH)&&((u32)(M2C_FIELD(defender,u16 *,MAP_UNIT_HEALTH)<<25)>>25)<50)gain=Divide(gain*50,((u32)(M2C_FIELD(defender,u16 *,MAP_UNIT_HEALTH)<<25)>>25));
value<<=1;
map=*gCurrentMap;cellIndex=defender[MAP_UNIT_X]+M2C_FIELD(map+defender[MAP_UNIT_Y]*2,u16 *,MAP_ROW_OFFSETS);
if((M2C_FIELD(map+cellIndex,u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK)==MAP_TERRAIN_HQ)value<<=1;
}
}
}
}
if(((u32)(defender[0]<<26)>>26)==21)value*=3;
else if(GetKindAttackClass(((u32)(defender[0]<<26)>>26))==2){if(!defender[MAP_UNIT_CARRIED])gain>>=2;else if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_DEFENDER_HEALTH))gain>>=1;}
else {if(GetUnitAttackClass(((u32)(defender[0]<<26)>>26))==0)value<<=1;else if(GetUnitAttackClass(((u32)(defender[0]<<26)>>26))==1)value*=3;}
if(gain*value-loss*2<0){if(GetUnitDamagePercent(((u32)(defender[0]<<26)>>26),((u32)(attacker[0]<<26)>>26))>1)goto failed;if(M2C_FIELD((*gCurrentMap),s16 *,MAP_BATTLE_ATTACKER_HEALTH))loss=0;else {failed:return 0;}}
gain+=(gain*CountThreateningEnemies(defender))>>5;
if(tileRating<=50&&!M2C_FIELD((u8 *)(*gCurrentMap)+(pos[0]+M2C_FIELD((u8 *)(*gCurrentMap)+pos[1]*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_THREAT_INDIRECT)&&!(M2C_FIELD(attacker,u16 *,MAP_UNIT_FLAGS)&32)){score=M2C_FIELD(gUnitKindBuildCosts+((u32)(defender[0]<<26)>>26)*UNIT_KIND_STATS_SIZE,u16 *,UNIT_KIND_STATS_COST);if((u32)score<800)gain+=score;else gain+=800;}
score=(gain*value-loss*2)>>3;if(score&~0xffff)score=0xffff;if(!score)score=1;return score;
}
