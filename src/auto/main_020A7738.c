/* 71 functions from 0x020A7738 to 0x020A86F8 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline s32 A8240InBounds(s32 x, s32 y) {
extern void **gCurrentMap;
if (x>=0 && y>=0 && x<M2C_FIELD(*gCurrentMap,u16 *,0x5144) && y<M2C_FIELD(*gCurrentMap,u16 *,0x5146)) return 1;
return 0;
}
typedef struct { u8 values[27]; } UnkA866cTable;
extern const UnkA866cTable data_020f3c04;

/* Score of a unit that moves from its own tile to (a,b): the power of its kind, the
 * player's terrain effect and the terrain penalty of the destination.  A player
 * without a terrain category (weather-type 2) only gets the destination penalty. */
s32 GetUnitMoveScore(s32 arg0,s32 a,s32 b,u8 mode) {
M2C_UNK GetUnitOwner(); u8 GetUnitKindByte0(s32); s32 func_020a26f8(void *,u8,u8);
extern void **gCurrentMap;
u8 *p=(u8 *)arg0;
s32 power,terrain,result,player;
GetUnitOwner(p);
power=GetUnitKindByte0((u32)(p[0]<<26)>>26);
terrain=func_020a26f8(p,p[1],p[2]);
result=GetUnitTerrainPenalty(p,a,b);
result+=power+terrain;
if(p){if(!p)player=0;else player=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;player=(player>>6)+1;}else player=0;
if (((u32)(M2C_FIELD((u8 *)*gCurrentMap+player*0x8c,s32 *,0x6810)<<24)>>24)!=10 && mode==2) result=terrain+1;
if(result<1)result=1;
return result;
}

/* GetUnitMoveScore with the weather as the terrain-effect mode. */
void GetUnitMoveScoreWeather(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK GetUnitMoveScore(M2C_UNK, M2C_UNK, M2C_UNK, u8);
    extern void **gCurrentMap;
    GetUnitMoveScore(arg0, arg1, arg2, M2C_FIELD(*gCurrentMap, u8 *, 0x5158));
}

/* Damage-free move penalty of entering the destination terrain: infantry and mech
 * (kinds 1 and 2) lose 3 points when the destination takes their movement type 4. */
s32 GetUnitTerrainPenalty(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 func_020d04ec(M2C_UNK, M2C_UNK, M2C_UNK);
 s32 penalty;
 u32 kind;
 penalty = 0;
 if (func_020d04ec(arg1, arg2, 4) != 0) {
  kind = (u32)(*arg0 << 26) >> 26;
  switch (kind) {
  case 1:
  case 2: penalty += 3; break;
  }
 }
 return penalty;
}

u32 func_020a788c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
}

u32 func_020a789c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C;
}

void func_020a78ac(u8 *arg0) {
    M2C_UNK func_020a7c68(u32);
    func_020a7c68((u32) (*arg0 << 0x1A) >> 0x1A);
}

u32 func_020a78c4(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19;
}

void func_020a78d4(u8 *arg0) {
    M2C_UNK func_020a7c50(u32);
    func_020a7c50((u32) (*arg0 << 0x1A) >> 0x1A);
}

u32 func_020a78ec(u8 *arg0) {
    return (u32) (*arg0 << 0x18) >> 0x1E;
}

s32 func_020a78fc(void *arg0) {
    s32 func_020a2728(void *, u8, u8);
    return func_020a2728(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2)) + 0xA;
}

s32 func_020a7914(void *arg0) {
 s32 func_020a2758(void *, u8, u8);
 s32 result = 0;
 result += func_020a2758(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
 return result;
}

s32 GetWeaponDamagePercent(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
 s32 func_020a72fc(s32, s32);
 extern u8 data_ov000_021b5c13[];
 s32 var_r1;
 var_r1 = arg1;
 if (arg3 != 0) var_r1 = func_020a72fc(var_r1, (u8)arg3);
 return *(var_r1 + (data_ov000_021b5c13 + arg0 * 0x70 + (arg2 << 5)));
}

u8 func_020a796c(s32 arg0, s32 arg1, s32 arg2) {
 s32 GetDamageTargetIndex(s32);
 extern u8 data_ov000_021b5c13[];
 return *(GetDamageTargetIndex(arg1) + (data_ov000_021b5c13 + arg0 * 0x70 + (arg2 << 5)));
}

s32 func_020a799c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 GetWeaponDamagePercent(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r4;

    var_r4 = GetWeaponDamagePercent(arg0, arg1, 0, arg2);
    temp_r0 = GetWeaponDamagePercent(arg0, arg1, 1, arg2);
    if (var_r4 <= temp_r0) {
        var_r4 = temp_r0;
    }
    return var_r4;
}

/* Estimate the damage a unit kind deals: the higher of its two weapons' damage
 * percentages, scaled by 100 + the kind's damage bonus, never below 1.  Returns
 * 0 when neither weapon can damage the target. */
s32 GetEstimatedDamage(s32 kind, s32 row, s32 altRow, s32 weather, s32 player, s32 bonusType, u8 applyBonus) {
 s32 Divide(s32, s32);
 s32 GetKindDamageBonus(s32, s32, s32, s32, u8);
 register s32 temp_r0;
 s32 damage;
 s32 base;
 s32 percent;
 percent = GetWeaponDamagePercent(kind, row, 0, altRow);
 temp_r0 = GetWeaponDamagePercent(kind, row, 1, altRow);
 base = 100;
 if (percent <= temp_r0) percent = temp_r0;
 if ((int)percent == 0) return 0;
 temp_r0 = GetKindDamageBonus(kind, weather, player, bonusType, applyBonus);
 base += temp_r0;
 damage = Divide(percent * base, 100);
 if (damage <= 1) damage = 1;
 return damage;
}
/* Percentage bonus a unit kind's damage estimate gets: the owner's attack
 * properties (5 percent each), the sandstorm penalty that every army but the
 * weather-immune one takes, and the army's CO-zone attack bonus for the kind. */
s32 GetKindDamageBonus(s32 kind, s32 weather, s32 player, s32 bonusType, u8 applyBonus) {
    u8 func_020a8560();
    s32 GetPlayerAttackPropertyBonus(s32);
    s32 GetCoZoneAttackBonus(s32, s32, s32);
    extern void **gCurrentMap;
    s32 bonus = 0;

    if (func_020a8560(kind) != 0) return bonus;
    bonus += GetPlayerAttackPropertyBonus(player);
    if (((u32)(M2C_FIELD((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + ARMY_REC_ARMY_ID) << 24) >> 24) != ARMY_WEATHER_IMMUNE && weather == WEATHER_SANDSTORM) bonus -= 30;
    if (applyBonus != 0 || bonusType != 0) bonus += GetCoZoneAttackBonus(kind, player, bonusType);
    return bonus;
}

/* Byte 0 of a unit kind entry: the kind's first stat byte (gUnitKindTable). */
u8 GetUnitKindByte0(s32 arg0) {
 extern u8 gUnitKindTable[];
 return gUnitKindTable[arg0 * 0x70];
}

u8 GetUnitKindMoveRange(s32 arg0) {
 extern u8 data_ov000_021b5c04[];
 return data_ov000_021b5c04[arg0 * 0x70];
}

s32 ComputeUnitMoveRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
 s32 func_020a296c(s32, s32, s32);
 extern u8 data_ov000_021b5c04[];
 extern void **gCurrentMap;
 s32 var_r4;
 var_r4 = data_ov000_021b5c04[arg0 * 0x70];
 if (arg3 != 0 || arg4 != 0) var_r4 += func_020a296c(arg0, arg2, arg3);
 if ((u32)(M2C_FIELD((u8 *)*gCurrentMap + arg2 * 0x8c, s32 *, 0x6810) << 24) >> 24 != 10 && arg1 == 1) var_r4--;
 return var_r4;
}

u16 func_020a7bbc(s32 arg0) {
 extern u8 data_ov000_021b5c00[];
 return *(u16 *)(data_ov000_021b5c00 + arg0 * 0x70);
}

u8 GetUnitKindMaxAttackRange(s32 arg0) {
 extern u8 data_ov000_021b5c09[];
 return data_ov000_021b5c09[arg0 * 0x70];
}

void func_020a7bec(void) {
    u8 GetUnitKindMaxAttackRange();
    GetUnitKindMaxAttackRange();
}

u8 func_020a7bf8(s32 arg0) {
 extern u8 gUnitMinAttackRange[];
 return gUnitMinAttackRange[arg0 * 0x70];
}

s32 ComputeUnitMaxAttackRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
 s32 GetCoZoneRangeBonus(s32, s32, s32);
 extern u8 data_ov000_021b5c09[];
 s32 var_r4;
 var_r4 = data_ov000_021b5c09[arg0 * 0x70];
 if (arg3 != 0 || arg4 != 0) var_r4 += GetCoZoneRangeBonus(arg0, arg2, arg3);
 return var_r4;
}

s32 func_020a7c50(u32 arg0) {
 extern u8 gUnitKindMaxFuel[];
 return gUnitKindMaxFuel[arg0 * 0x70];
}

s32 func_020a7c68(u32 arg0) {
 extern u8 gUnitKindMaxAmmo[];
 return gUnitKindMaxAmmo[arg0 * 0x70];
}

s32 func_020a7c80(arg0)
s32 arg0;
{
 extern u8 data_ov000_021b5c0c[];
 return data_ov000_021b5c0c[arg0 * 0x70];
}

u8 func_020a7c98(s32 arg0) {
 extern u8 gMovementTypeTable[];
 return gMovementTypeTable[arg0 * 0x70];
}

u8 HasUnitActed(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 UnitHasFacing(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x10) >> 0x1B) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 UnitHasCargo(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0xC) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsUnitSelected(s32 arg0) {
    s32 GetPlayerSelectedUnit();
    M2C_UNK GetUnitOwner();
    u8 var_r0;

    GetUnitOwner();
    if (arg0 == GetPlayerSelectedUnit()) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d20(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsUnitSubmerged(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x20) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsUnitMarkedForRepair(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x100) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d68(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x80) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d80(void *arg0) {
 s32 temp_r0;
 s32 var_r0;
 temp_r0 = func_020a7c50((u32)(M2C_FIELD(arg0, u8 *, 0) << 26) >> 26);
 if (temp_r0 > 0 && (temp_r0 >> 1) >= (s32)((u32)(M2C_FIELD(arg0, u8 *, 10) << 25) >> 25)) var_r0 = 1;
 else var_r0 = 0;
 return var_r0;
}

u8 func_020a7dc4(void *arg0) {
 s32 temp_r0;
 s32 var_r0;
 temp_r0 = func_020a7c68((u32)(M2C_FIELD(arg0, u8 *, 0) << 26) >> 26);
 if (temp_r0 > 0 && (temp_r0 >> 1) >= (s32)((u32)(M2C_FIELD(arg0, u16 *, 6) << 21) >> 28)) var_r0 = 1;
 else var_r0 = 0;
 return var_r0;
}

u8 IsSupplyUnitKind(u8 *p){extern u8 data_ov000_021b5c65[];u8 r;if(data_ov000_021b5c65[((u32)(*p<<26)>>26)*0x70])r=1;else r=0;return r;}

/* If `unit` is the unit its player has selected, drops that selection: the
 * selected-unit slot is cleared and, when `clearState` is set, the selection
 * state is cleared too; a human player's selection is counted in the records. */
void ClearPlayerSelectedUnit(s32 unit,s32 clearState){
s32 func_020a3550(s32,s32);void func_020a3128(s32);s32 IsPlayerHuman(s32);void AddRecordValue(s32,s32);
extern void **gCurrentMap;
s32 player;u8 *map,*record;
if(!unit)return;
if(!unit)player=0;else player=(unit-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;
player=(player>>6)+1;
map=(u8 *)*gCurrentMap;
record=map+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE;
if(!((u32)(*(s32 *)(record+PLAYER_REC_SPRITE)<<24)>>24))return;
if(unit!=(s32)(map+MAP_UNIT_RECORDS+record[PLAYER_REC_SELECTED_UNIT]*MAP_UNIT_STRIDE))return;
record[PLAYER_REC_SELECTED_UNIT]=0;
if(clearState){
func_020a3550(player,0);func_020a3128(player);
}
if(!IsPlayerHuman(player))return;
AddRecordValue(28,1);
}

void func_020a7f18(void *p,u32 a){u16 v=M2C_FIELD(p,u16 *,6); a=(u16)a; M2C_FIELD(p,u16 *,6)=(v&~0xf800)|((a<<27)>>16);}

u32 func_020a7f38(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x10) >> 0x1B;
}

void func_020a7f48(void *unit,s32 x,s32 y,s32 mode) {
extern void **data_027e0058;
void InitAreaScan(void *,s32,s32,s32,s32,s32);s32 NextAreaTile(void *);
u8 func_020a8478(s32,s32);u8 func_020a80fc(s32,s32);u8 func_020a8164(s32,s32);void func_020a7f18(void *,u32);
s32 iter[8];void *map;void *base; s32 idx;
map=*data_027e0058;
InitAreaScan(iter,mode,x,y,M2C_FIELD(map,u16 *,0x5144),M2C_FIELD(map,u16 *,0x5146));
for(;;){
if(!NextAreaTile(iter))return;
if(func_020a8478(iter[4],iter[5])){
map=*data_027e0058;
idx=M2C_FIELD(M2C_FIELD(map+2*iter[5],u16 *,0x3758)+(map+iter[4]),u8 *,0x508);
base=map+0x59a4;
if(!func_020a80fc((s32)unit,(s32)(base+idx*14)))goto done;
func_020a7f18(base+idx*14,1);
if(func_020a8164((s32)unit,(s32)(base+idx*14)))func_020a7f18(unit,1);
}
}
done:;
}

#pragma push
#pragma peephole on
void func_020a8050(void *p,s16 *xy,s32 unused,s8 *dir){void func_020a7f48(void *,s32,s32,s32);s32 x=xy[0],y=xy[1];func_020a7f48(p,x,y,1);for(;;){switch(*dir++){case 0:x--;break;case 1:x++;break;case 3:y--;break;case 2:y++;break;case -1:case 4:case 10:return;}func_020a7f48(p,x,y,1);}}
#pragma pop
u8 func_020a80fc(s32 arg0, s32 arg1) {
    s32 temp_r4;
    u8 var_r0;

    if ((arg1 == 0) || (func_020a81c8(arg1) == 0)) {
        return 0U;
    }
    if (arg0 == 0) {
        return 1U;
    }
    temp_r4 = GetUnitOwner(arg0);
    if (IsSameTeam(temp_r4, GetUnitOwner(arg1)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a8164(s32 arg0, s32 arg1) {
    s32 IsSameTeam(s32, s32);
    s32 temp_r4;
    u8 var_r0;

    if ((arg0 == 0) || (func_020a81c8() == 0)) {
        return 0U;
    }
    if (arg1 == 0) {
        return 0U;
    }
    temp_r4 = GetUnitOwner(arg0);
    if (IsSameTeam(temp_r4, GetUnitOwner(arg1)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020a81c8(void) {
    return 0;
}

u8 func_020a81d0(M2C_UNK arg0) {
    u8 var_r0;

    if (func_020a81c8() == 0) {
        return 0U;
    }
    if (func_020a7f38(arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a8204(void *arg0) {
    s32 func_020a8630(u32);
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C) == 0) {
        return 0U;
    }
    if (func_020a8630((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Builds the MOVE_DIR_* step list that slides a unit from its current tile by
 * (dx, dy) tiles, horizontally first and then vertically, stopping at the map
 * edge or at an occupied cell.  The list ends with MOVE_DIR_NONE. */
void BuildMovePath(u8 *unit, s32 dx, s32 dy, u8 *out) {
extern void **gCurrentMap;
s32 y; s32 x; s32 step; s32 n;
x=unit[1];y=unit[2];
n=dx<0?-dx:dx; step=dx>0?1:-(dx<0);
while(n>0){
x+=step;
if(!A8240InBounds(x,y))break;
if(M2C_FIELD((u8 *)*gCurrentMap+x+M2C_FIELD((u8 *)*gCurrentMap+((u32)y<<1),u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_UNIT_ID)!=0)break;
n--; if(step>0)*out++=MOVE_DIR_RIGHT; if(step<0)*out++=MOVE_DIR_LEFT;
}
n=dy<0?-dy:dy; step=dy>0?1:-(dy<0);
while(n>0){
y+=step;
if(!A8240InBounds(x,y))break;
if(M2C_FIELD((u8 *)(x+(u32)*gCurrentMap)+M2C_FIELD((u8 *)*gCurrentMap+((u32)y<<1),u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_UNIT_ID)!=0)break;
n--; if(step>0)*out++=MOVE_DIR_DOWN; if(step<0)*out++=MOVE_DIR_UP;
}
*(s8 *)out=MOVE_DIR_NONE;
}

#pragma optimize_for_size on
void func_020a83e4(u8 *p,s8 *dir){do{switch(*dir++){case 9:dir++;break;case -1:case 4:return;case 0:p[1]--;break;case 1:p[1]++;break;case 3:p[2]--;break;case 2:p[2]++;break;case 10:default:break;}}while(1);}
#pragma optimize_for_size reset
void func_020a8474(void) {

}

u8 func_020a8478(s32 a,s32 b){extern void **gCurrentMap;void *p=*gCurrentMap;return M2C_FIELD((u8 *)p+(a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758)),u8 *,0x508)!=0;}

u8 IsCellUnitEmpty(s32 a,s32 b){extern void **gCurrentMap;void *p=*gCurrentMap;return M2C_FIELD((u8 *)p+(a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758)),u8 *,0x508)==0;}

u8 func_020a84f0(void) {
    s32 func_020a7c80();
    u8 var_r0;

    if (func_020a7c80() == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a850c(void) {
    u8 var_r0;

    if (func_020a7c80() == 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020a8528(void *a){u8 func_020a84f0();u8 func_020a850c();s32 v;if(func_020a84f0(a)||func_020a850c(a))v=1;else v=0;return (u8)v;}

u8 func_020a8560(void) {
    u8 var_r0;

    if (func_020a7c80() == 6) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020a857c(void *p){s32 func_020a8528(void *);u8 func_020a8560();if(!p)return 0;if(func_020a8528(p)||func_020a8560(p))return 1;return 0;}

s32 func_020a85b8(void) {
    return 0;
}

s32 func_020a85c0(void) {
    return 0;
}

u8 IsMobileIndirectUnitKind(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x14) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsCarrierUnitKind(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x15) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsUnitKindCarrier(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x15) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 UnitKindCanSupply(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 13:
        return 1;
    case 21:
        return 1;
    default:
        return 0;
    }
}

s32 func_020a8630(u32 a){switch(a){case 5:return 1;case 13:return 1;case 21:return 1;default:return 0;}}

u8 func_020a866c(u32 a){UnkA866cTable t=data_020f3c04;return t.values[a];}

s32 func_020a86bc(void) {
    return 0;
}

s32 func_020a86c4(s32 a,s32 b){extern s8 data_ov000_021b5520[];extern u8 gMapConfig[];s32 v=0;if(data_ov000_021b5520[b&31])v+=M2C_FIELD(gMapConfig,u16 *,6);return v;}

s32 func_020a86f0(void) {
    return 1;
}

