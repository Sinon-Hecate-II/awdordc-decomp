/* 17 functions from 0x020D068C to 0x020D166C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 bytes[14]; } D068CUnit;
extern s32 *gCurrentMap;
static inline s32 D068CIndex(void *p) { s32 n; if(p) n=((s32)p-(*gCurrentMap+0x59a4))/14; else n=0; return n; }
static inline s32 D068COwner(void *p) { if(p) return (D068CIndex(p)>>6)+1; return 0; }
typedef struct { unsigned char value:6; } D068CBits;
typedef struct { u8 kind:6;u8 team:2; } D11F4Bits;
static inline void D11F4Set(void *p,u8 team){((D11F4Bits *)p)->team=team;}
void RollDamageVariance(M2C_UNK);
static inline u32 D068CLow(void *p) { return M2C_FIELD(p,D068CBits*,0).value; }
static inline u32 D068CFlag(void *p) { return M2C_FIELD(p,u16*,4)&32; }
s32 CalculateUnitDamage();
static inline s32 D068CCall(M2C_UNK a,void *p,s32 c) {
 u32 low,flag;
 flag=D068CFlag(p); low=D068CLow(p);
 return CalculateUnitDamage(a,low,c,flag);
}
static inline void D068CApply(void *p) {
 if(M2C_FIELD(p,s16*,0x14)==0)return;
 M2C_FIELD(p,s16*,0x14)+=((s32 (*)(M2C_UNK))RollDamageVariance)(M2C_FIELD(p,M2C_UNK*,0));
}
void RollDamageVariance(M2C_UNK);
void AddDamageVariance(void *,s32);

void InitBattleUnit(void *p,s16 index) {
s32 GetTerrainDefenseScore(); s32 func_020a3518();
void *q,*m; register s32 stride=14;
q=(void *)*gCurrentMap+0x59a4+index*stride;
M2C_FIELD(p,void **,0)=q;
m=(void *)*gCurrentMap;
M2C_FIELD(p,s16 *,4)=M2C_FIELD(m+(M2C_FIELD(q,u8 *,1)+M2C_FIELD(m+M2C_FIELD(q,u8 *,2)*2,u16 *,0x3758)),u8 *,0x1420)&31;
M2C_FIELD(p,s16 *,6)=GetTerrainDefenseScore(D068COwner(M2C_FIELD(p,void **,0)),D068CLow(M2C_FIELD(p,void **,0)),M2C_FIELD(p,s16 *,4));
M2C_FIELD(p,s16 *,8)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<25)>>25;
M2C_FIELD(p,s16 *,10)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<21)>>28;
M2C_FIELD(p,s16 *,12)=func_020a3518(D068COwner(M2C_FIELD(p,void **,0)));
M2C_FIELD(p,s16 *,14)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<25)>>25;
M2C_FIELD(p,s16 *,16)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<21)>>28;
M2C_FIELD(p,s16 *,18)=func_020a3518(D068COwner(M2C_FIELD(p,void **,0)));
M2C_FIELD(p,s16 *,30)=0;M2C_FIELD(p,s16 *,24)=0;M2C_FIELD(p,s16 *,26)=0;
}

#pragma opt_propagation off
/* Resolves one side's strike in a battle: picks the best usable weapon for the
 * range (secondary when it can hit, otherwise primary while it has ammo),
 * computes the damage against the opponent's kind and records the chosen weapon
 * and its damage on the participant.  Returns without a strike if none can hit. */
void ResolveUnitAttack(BattleUnit *a, BattleMapUnit **b, s32 distance, s32 isAggressor) {
    s32 GetUnitAttackRangeMax(void *);
    s32 GetWeaponDamagePercent();
    s32 GetUnitAttackPower();
    extern u8 gUnitKindStats[];
    register u16 primaryDamage = 0;
    register u16 secondaryDamage;
    register s16 secondaryPercent;
    register u8 *stats = gUnitKindStats + ((D068CBits *)a->unit)->value * UNIT_KIND_STATS_SIZE;
    secondaryDamage = 0;
    secondaryPercent = 0;
    a->attackPower = GetUnitAttackPower(a->unit);
    if (distance == 1) {
        void *target = *b;
        u32 attackerKind, targetKind, targetFlags;
        attackerKind = D068CLow(a->unit);
        targetKind = D068CLow(target);
        targetFlags = D068CFlag(target);
        secondaryPercent = GetWeaponDamagePercent(attackerKind, targetKind, 1, targetFlags);
        if (secondaryPercent) {
            void *target = *b;
            u8 targetByte = M2C_FIELD(target, u8 *, 0);
            u32 shifted = (u32)targetByte << 26;
            u32 targetFlags = D068CFlag(target);
            u32 targetKind = shifted >> 26;
            secondaryDamage = (u16)CalculateUnitDamage(a->unit, targetKind, 1, targetFlags);
        }
        if (stats[UNIT_KIND_STATS_MIN_RANGE] == 1) {
            void *attackerUnit = a->unit;
            if ((u32)(M2C_FIELD(attackerUnit, u16 *, 6) << 21) >> 28) {
                void *target = *b;
                u8 targetByte = M2C_FIELD(target, u8 *, 0);
                u32 shifted = (u32)targetByte << 26;
                u32 targetFlags = D068CFlag(target);
                u32 targetKind = shifted >> 26;
                primaryDamage = (u16)CalculateUnitDamage(attackerUnit, targetKind, 0, targetFlags);
            }
        }
    } else if (stats[UNIT_KIND_STATS_MIN_RANGE] <= distance && distance <= GetUnitAttackRangeMax(a->unit)) {
        void *attackerUnit = a->unit;
        if (((u32)(M2C_FIELD(attackerUnit, u16 *, 6) << 21) >> 28) && isAggressor == 1) {
            void *target = *b;
            u8 targetByte = M2C_FIELD(target, u8 *, 0);
            u32 shifted = (u32)targetByte << 26;
            u32 targetFlags = D068CFlag(target);
            u32 targetKind = shifted >> 26;
            primaryDamage = (u16)CalculateUnitDamage(attackerUnit, targetKind, 0, targetFlags);
        }
    }
    if (primaryDamage <= secondaryDamage) {
        if (!secondaryPercent) return;
        a->weapon = BATTLE_WEAPON_SECONDARY;
        a->weaponDamage = secondaryDamage;
        return;
    }
    a->weapon = BATTLE_WEAPON_PRIMARY;
    a->weaponDamage = primaryDamage;
    a->ammo -= 1;
}
#pragma opt_propagation reset
s32 func_020d0a08(M2C_UNK arg0,void *arg1) {
s32 func_020a8204();
s32 CalculateUnitDamage();
u16 temp_r0,var_r6;
var_r6=0;
if(func_020a8204(arg0)!=0)var_r6=CalculateUnitDamage(arg0,(s32)D068CLow(arg1),0,(s32)D068CFlag(arg1));
temp_r0=CalculateUnitDamage(arg0,(s32)D068CLow(arg1),1,(s32)D068CFlag(arg1));
return var_r6!=0 || temp_r0!=0;
}
#pragma opt_common_subs reset
s32 func_020d0a88(u8 *arg0,M2C_UNK arg1) {
 s32 GetDamageTargetIndex();
 s32 func_020a796c();
 s32 func_020a8204();
 s32 CalculateUnitDamage();
 u16 temp_r0,var_r4;
 var_r4=0;
 if(func_020a8204()!=0)var_r4=CalculateUnitDamage(arg0,GetDamageTargetIndex(arg1),0,0);
 temp_r0=func_020a796c((u32)(*arg0<<26)>>26,arg1,1);
 return var_r4!=0 || temp_r0!=0;
}

/* Applies one battle side's chosen weapon damage: scale its attack power by the
   unit's health level, copy the weapon damage into the damage total, add the
   defender's bonus percentage and the random variance, then clamp it to zero. */
void ApplyBattleDamage(BattleUnit *side, s32 isDefender, M2C_UNK addVariance) {
    s32 GetDefenderBonus(void *);
    s32 healthLevel, percent;
    u32 health;

    percent = 100;
    health = (u32)(M2C_FIELD(side->unit, u16 *, 6) << 25) >> 25;
    if (health == 0) healthLevel = 0; else healthLevel = Divide(health - 1, 10) + 1;
    side->attackPower = side->attackPower + Divide(side->attackBase * healthLevel, 10);
    side->damage = side->weaponDamage;
    if (isDefender == 1) percent += GetDefenderBonus(side);
    side->damage = Divide(side->damage * percent, 100);
    side->unk1C = side->damage;
    AddDamageVariance(side, addVariance);
    if (side->damage < 0) side->damage = 0;
}

#pragma opt_cond_exec off
void AddDamageVariance(void *p,s32 a) { extern u8 gMapData[]; if(((u32)M2C_FIELD(gMapData,u16*,12)<<20)>>31)return; switch(a){case 0:return;default:break;} if(M2C_FIELD(p,volatile s16*,0x14)==0)return; {s32 t=((s32 (*)(M2C_UNK))RollDamageVariance)(M2C_FIELD(p,M2C_UNK*,0)); M2C_FIELD(p,s16*,0x14)=M2C_FIELD(p,s16*,0x14)+t;} }
#pragma opt_cond_exec reset
void RollDamageVariance(M2C_UNK arg0) {
    M2C_UNK RandomIntRange(s32, s32);
    s32 func_020a78fc();
    s32 func_020a7914(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_020a78fc();
    RandomIntRange(func_020a7914(arg0), temp_r4);
}

/* Settle one side's counter hit on the other battle participant: scale the
 * source's recorded damage by its health level, express it against the target's
 * attack power (capped at 999) and drop the target's health by the source's share. */
void ApplyCounterHit(void *target, void *source) {
    u32 health = (u32) (M2C_FIELD(M2C_FIELD(source, void **, 0), u16 *, 6) << 25) >> 25;
    s32 level;
    if (health == 0) level = 0; else level = Divide(health - 1, 10) + 1;
    M2C_FIELD(source, s16 *, 0x1c) = Divide(M2C_FIELD(source, s16 *, 0x1c) * level, 10);
    if (M2C_FIELD(target, s16 *, 0x16) == 0) level = 999;
    else level = Divide(M2C_FIELD(source, s16 *, 0x1c) * 100, M2C_FIELD(target, s16 *, 0x16));
    M2C_FIELD(source, s16 *, 0x1c) = level;
    if (M2C_FIELD(source, s16 *, 0x1c) >= 999) M2C_FIELD(source, s16 *, 0x1c) = 999;
    if (M2C_FIELD(target, s16 *, 0x16) == 0) level = 999;
    else level = Divide(M2C_FIELD(source, s16 *, 0x14) * 100, M2C_FIELD(target, s16 *, 0x16));
    M2C_FIELD(target, s16 *, 0x1a) = level;
    M2C_FIELD(target, s16 *, 0xe) = ((u32) (M2C_FIELD(M2C_FIELD(target, void **, 0), u16 *, 6) << 25) >> 25) - M2C_FIELD(target, s16 *, 0x1a);
}

/* Applies the two damage totals of a round in which the first side strikes and
 * the other counters: scale the striker's damage by its health level and settle
 * its hit, then scale the other side's damage by the health it has left after
 * that hit and settle its counter. */
void ApplyCounterDamage(BattleUnit *striker, BattleUnit *counter) {
    s16 counterHealth;
    s32 strikerLevel;
    s32 counterLevel;
    u32 health;

    health = (u32) (M2C_FIELD(striker->unit, u16 *, 6) << 25) >> 25;
    if (health == 0) {
        strikerLevel = 0;
    } else {
        strikerLevel = Divide(health - 1, 10) + 1;
    }
    striker->damage = Divide(striker->damage * strikerLevel, 10);
    ApplyCounterHit(counter, striker);
    counterHealth = counter->health;
    if ((s32) counterHealth < 0) {
        counterHealth = 0;
    }
    if (counterHealth == 0) {
        counterLevel = 0;
    } else {
        counterLevel = Divide(counterHealth - 1, 10) + 1;
    }
    counter->damage = Divide(counter->damage * counterLevel, 10);
    ApplyCounterHit(striker, counter);
}

void ResolveBattleTie(void *arg0, void *arg1) {
    s16 temp_r2;
    s16 temp_r3;

    temp_r3 = M2C_FIELD(arg0, s16 *, 0xE);
    if ((s32) temp_r3 <= 0) {
        temp_r2 = M2C_FIELD(arg1, s16 *, 0xE);
        if ((s32) temp_r2 <= 0) {
            if ((s32) temp_r3 < (s32) temp_r2) {
                M2C_FIELD(arg1, s16 *, 0xE) = 1;
                M2C_FIELD(arg0, s16 *, 0xE) = 0;
                return;
            }
            M2C_FIELD(arg0, s16 *, 0xE) = 1;
            M2C_FIELD(arg1, s16 *, 0xE) = 0;
            return;
        }
    }
    if ((s32) temp_r3 < 0) {
        M2C_FIELD(arg0, s16 *, 0xE) = 0;
    }
    if ((s32) M2C_FIELD(arg1, s16 *, 0xE) < 0) {
        M2C_FIELD(arg1, s16 *, 0xE) = 0;
    }
}

s32 GetDamageBonus(void) {
    return 0;
}

/* Moves the attacker onto `destination`, then resolves one exchange of blows
 * between it and the defender: loads both battle participants, measures their
 * distance, works out and applies each side's damage (counter included), picks
 * the survivor, and finally puts the attacker back where it stood. */
void RunBattle(s16 attacker,s16 defender,s16 *destination) {
 s32 GetDamageBonus();
 register u8 oldX,oldY; register s32 dist;
 oldX=M2C_FIELD(*gCurrentMap+MAP_UNIT_RECORDS+attacker*MAP_UNIT_STRIDE,u8 *,1);
 M2C_FIELD(*gCurrentMap+MAP_UNIT_RECORDS+attacker*MAP_UNIT_STRIDE,u8 *,1)=destination[0];
 oldY=M2C_FIELD(*gCurrentMap+MAP_UNIT_RECORDS+attacker*MAP_UNIT_STRIDE,u8 *,2);
 M2C_FIELD(*gCurrentMap+MAP_UNIT_RECORDS+attacker*MAP_UNIT_STRIDE,u8 *,2)=destination[1];
 InitBattleUnit((void *)(*gCurrentMap+MAP_BATTLE_ATTACKER),attacker);
 InitBattleUnit((void *)(*gCurrentMap+MAP_BATTLE_DEFENDER),defender);
 dist=ManhattanDistance(M2C_FIELD(M2C_FIELD(*gCurrentMap+MAP_BATTLE_ATTACKER,void **,0),u8 *,1),M2C_FIELD(M2C_FIELD(*gCurrentMap+MAP_BATTLE_ATTACKER,void **,0),u8 *,2),M2C_FIELD(M2C_FIELD(*gCurrentMap+MAP_BATTLE_DEFENDER,void **,0),u8 *,1),M2C_FIELD(M2C_FIELD(*gCurrentMap+MAP_BATTLE_DEFENDER,void **,0),u8 *,2));
 ((void (*)(void *,void **,s16,s32))ResolveUnitAttack)((void *)(*gCurrentMap+MAP_BATTLE_ATTACKER),(void **)(*gCurrentMap+MAP_BATTLE_DEFENDER),dist,1);
 ((void (*)(void *,void **,s16,s32))ResolveUnitAttack)((void *)(*gCurrentMap+MAP_BATTLE_DEFENDER),(void **)(*gCurrentMap+MAP_BATTLE_ATTACKER),dist,0);
 ApplyBattleDamage((void *)(*gCurrentMap+MAP_BATTLE_ATTACKER),0,1);
 ApplyBattleDamage((void *)(*gCurrentMap+MAP_BATTLE_DEFENDER),1,1);
 if(GetDamageBonus((u8)D068COwner(M2C_FIELD(*gCurrentMap+MAP_BATTLE_DEFENDER,void **,0)))==1)
  ApplyCounterDamage((void *)(*gCurrentMap+MAP_BATTLE_DEFENDER),(void *)(*gCurrentMap+MAP_BATTLE_ATTACKER));
 else
  ApplyCounterDamage((void *)(*gCurrentMap+MAP_BATTLE_ATTACKER),(void *)(*gCurrentMap+MAP_BATTLE_DEFENDER));
 ResolveBattleTie((void *)(*gCurrentMap+MAP_BATTLE_ATTACKER),(void *)(*gCurrentMap+MAP_BATTLE_DEFENDER));
 M2C_FIELD(*gCurrentMap+attacker*MAP_UNIT_STRIDE,u8 *,0x59a5)=oldX;
 M2C_FIELD(*gCurrentMap+attacker*MAP_UNIT_STRIDE,u8 *,0x59a6)=oldY;
}

void func_020d1034(void *arg0) {
    s32 Divide(s32, M2C_UNK);
    M2C_UNK AddPlayerUnitValue(void *, s32);
    s16 temp_r0;
    s32 var_r1;
    s32 var_r5;
    u32 temp_r0_2;

    temp_r0 = M2C_FIELD(arg0, s16 *, 0xE);
    if (temp_r0 == 0) {
        var_r5 = 0;
    } else {
        var_r5 = Divide(temp_r0 - 1, 0xA) + 1;
    }
    temp_r0_2 = (u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 *, 6) << 0x19) >> 0x19;
    if (temp_r0_2 == 0) {
        var_r1 = 0;
    } else {
        var_r1 = Divide(temp_r0_2 - 1, 0xA) + 1;
    }
    AddPlayerUnitValue(M2C_FIELD(arg0, void **, 0), var_r1 - var_r5);
}

/* Writes a battle participant's displayed HP and ammo back to its unit record,
 * then picks how the unit reacts: at 0 HP it plays the collapse animation; when
 * the other side still has HP and animations are on it counters, using the
 * merge/counter pose (7) against transports (kinds 1-3) and the plain counter
 * pose (6) otherwise. */
void func_020d1094(s32 participant, s32 opponent) {
    void func_020b576c(void *);
    s32 func_020cd614(void);
    s32 func_020cd5d8(void);
    void func_020b5594(s32, s32, s32, s32);
    void *unit = M2C_FIELD(participant, void **, 0);
    s32 kind;

    M2C_FIELD(unit, u16 *, 6) = (M2C_FIELD(unit, u16 *, 6) & ~127) | (M2C_FIELD(participant, u16 *, 14) & 127);
    M2C_FIELD(unit, u16 *, 6) = (M2C_FIELD(unit, u16 *, 6) & ~0x780) | ((u32)(M2C_FIELD(participant, u16 *, 16) << 28) >> 21);
    if (M2C_FIELD(participant, s16 *, 14) <= 0) {
        func_020b576c(unit);
        return;
    }
    if (!opponent) return;
    if (func_020cd614()) return;
    if (M2C_FIELD(participant, s16 *, 8) - M2C_FIELD(participant, s16 *, 14) == 0) return;
    if (M2C_FIELD(opponent, s16 *, 14) <= 0) return;
    if (!func_020cd5d8()) return;
    kind = D068CLow(M2C_FIELD(opponent, void **, 0));
    if (kind == 1) goto counter;
    if (kind == 2) goto counter;
    if (kind == 3) goto counter;
    goto plain;
counter:
    func_020b5594(M2C_FIELD(unit, u8 *, 1), M2C_FIELD(unit, u8 *, 2), 7, 7);
    return;
plain:
    func_020b5594(M2C_FIELD(unit, u8 *, 1), M2C_FIELD(unit, u8 *, 2), 6, 7);
}

/* Records the destruction of a unit for the records screen: adds one to the
   per-kind destroyed-unit counter (kind + RECORD_UNIT_KIND_BASE) and recurses
   into the units this one was carrying. */
void RecordDestroyedUnit(u8 *unit) {
extern s32 *gCurrentMap;
AddRecordValue(((u32)(unit[MAP_UNIT_KIND]<<26)>>26)+RECORD_UNIT_KIND_BASE,1);
if(unit[MAP_UNIT_FIRST_CARRIED])RecordDestroyedUnit((u8 *)(*gCurrentMap+MAP_UNIT_RECORDS)+unit[MAP_UNIT_FIRST_CARRIED]*MAP_UNIT_STRIDE);
if(unit[MAP_UNIT_NEXT_CARRIED])RecordDestroyedUnit((u8 *)(*gCurrentMap+MAP_UNIT_RECORDS)+unit[MAP_UNIT_NEXT_CARRIED]*MAP_UNIT_STRIDE);
}

/* Resolves a fight after damage has been applied to both battle participants:
 * for each side that dropped to 0 HP it credits the opponent and notifies the
 * unit's owner, then writes back the surviving HP and runs the destruction
 * effect, and finally plays the impact sound if a side's HP changed. */
void ApplyBattleResult(void){
extern u8 gMapData[];
void func_020d18fc(s32,s32);s32 IsPlayerHuman(s32);s32 GetCoPowerMeterCost(s32,s32);M2C_UNK PlaySoundEffect(s32);
void *unit,*record;
if(M2C_FIELD(*gCurrentMap,s16*,0x6ec6)<=0){
if((u32)(M2C_FIELD(gMapData,u16*,12)<<23)>>31){
unit=M2C_FIELD(*gCurrentMap,void**,0x6ed8);
if(((D11F4Bits *)unit)->team<3)D11F4Set(unit,((D11F4Bits *)unit)->team+1);
}
record=(void*)(*gCurrentMap+0x6eb8);
func_020d18fc(D068COwner(M2C_FIELD(*gCurrentMap,void**,0x6ed8)),D068CLow(M2C_FIELD(record,void**,0)));
if(IsPlayerHuman(D068COwner(M2C_FIELD(*gCurrentMap,void**,0x6ed8)))==1)RecordDestroyedUnit(M2C_FIELD(*gCurrentMap,u8**,0x6eb8));
}
if(M2C_FIELD(*gCurrentMap,s16*,0x6ee6)<=0){
if((u32)(M2C_FIELD(gMapData,u16*,12)<<23)>>31){
unit=M2C_FIELD(*gCurrentMap,void**,0x6eb8);
if(((D11F4Bits *)unit)->team<3)D11F4Set(unit,((D11F4Bits *)unit)->team+1);
}
record=(void*)(*gCurrentMap+0x6ed8);
func_020d18fc(D068COwner(M2C_FIELD(*gCurrentMap,void**,0x6eb8)),D068CLow(M2C_FIELD(record,void**,0)));
if(IsPlayerHuman(D068COwner(M2C_FIELD(*gCurrentMap,void**,0x6eb8)))==1)RecordDestroyedUnit(M2C_FIELD(*gCurrentMap,u8**,0x6ed8));
}
((void (*)())func_020d1034)(*gCurrentMap+0x6eb8,*gCurrentMap+0x6ed8);
((void (*)())func_020d1034)(*gCurrentMap+0x6ed8,*gCurrentMap+0x6eb8);
((void (*)())func_020d1094)(*gCurrentMap+0x6eb8,*gCurrentMap+0x6ed8);
((void (*)())func_020d1094)(*gCurrentMap+0x6ed8,*gCurrentMap+0x6eb8);
if(M2C_FIELD(*gCurrentMap,s16*,0x6ec4)!=M2C_FIELD(*gCurrentMap,s16*,0x6eca)){
record=(void*)(*gCurrentMap+0x6eb8);
if(M2C_FIELD(record,s16*,18)==GetCoPowerMeterCost(D068COwner(M2C_FIELD(*gCurrentMap,void**,0x6eb8)),2))goto sound;
}
if(M2C_FIELD(*gCurrentMap,s16*,0x6ee4)==M2C_FIELD(*gCurrentMap,s16*,0x6eea))return;
record=(void*)(*gCurrentMap+0x6ed8);
if(M2C_FIELD(record,s16*,18)!=GetCoPowerMeterCost(D068COwner(M2C_FIELD(*gCurrentMap,void**,0x6ed8)),2))return;
sound:PlaySoundEffect(0x115);
}

void func_020d1644(void) {

    extern s32 *gCurrentMap;
    func_020d1094(*gCurrentMap + 0x6EB8, 0);
}

