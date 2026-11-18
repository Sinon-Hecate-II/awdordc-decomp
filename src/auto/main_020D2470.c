/* 48 functions from 0x020D2470 to 0x020D3464 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u8 kind:6; u8 flags:2; } SelectionKind;
typedef struct { SelectionKind kind; u8 pad[3]; u16 flags; u8 tail[8]; } SelectionUnit;

#pragma optimization_level 3
void func_020d2470(void) {
    extern s32 *gCurrentMap;
    s32 func_020a86c4(s32, s32);
    u8 *p;
    u8 *rec;
    s32 i;
    s32 off;
    s32 y;
    s32 x;
    u8 byte;
    s32 idx;

    i = 0;
    off = 0;
    y = 0;
    do {
        i++;
        *(s32 *)((u8 *)*gCurrentMap + off + 0x67ac) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b4) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b5) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b6) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b7) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b8) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b9) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67ba) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67bb) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67cf) |= 0x80;
        off += 0x8c;
    } while (i < 5);

    p = (u8 *)*gCurrentMap;
    if ((s32)M2C_FIELD(p, u16 *, 0x5146) <= 0) {
        return;
    }
    do {
        x = 0;
        if ((s32)M2C_FIELD(p, u16 *, 0x5144) > 0) {
            do {
                byte = *(u8 *)(p + M2C_FIELD(p + y * 2, u16 *, 0x3758) + x + 0x1420);
                if (byte & 0xe0) {
                    idx = (byte & 0xe0) >> 5;
                    rec = (u8 *)(p + 0x67a4 + idx * 0x8c);
                    switch (byte & 0x1f) {
                    case 15:
                        *(s32 *)(rec + 8) += func_020a86c4(idx, byte & 0x1f);
                        rec[0x2b] = x;
                        rec[0x2c] = y;
                        break;
                    case 17:
                        *(s32 *)(rec + 8) += func_020a86c4(idx, byte & 0x1f);
                        rec[0x10]++;
                        break;
                    case 16:
                        *(s32 *)(rec + 8) += func_020a86c4(idx, byte & 0x1f);
                        rec[0x11]++;
                        break;
                    case 22:
                        *(s32 *)(rec + 8) += func_020a86c4(idx, byte & 0x1f);
                        rec[0x14]++;
                        break;
                    case 23:
                        *(s32 *)(rec + 8) += func_020a86c4(idx, byte & 0x1f);
                        rec[0x15]++;
                        break;
                    case 18:
                        *(s32 *)(rec + 8) += func_020a86c4(idx, byte & 0x1f);
                        rec[0x12]++;
                        break;
                    case 19:
                        *(s32 *)(rec + 8) += func_020a86c4(idx, byte & 0x1f);
                        rec[0x13]++;
                        break;
                    case 20:
                        rec[0x16]++;
                        break;
                    case 21:
                        rec[0x17]++;
                        break;
                    }
                }
                p = (u8 *)*gCurrentMap;
                x++;
            } while (x < (s32)M2C_FIELD(p, u16 *, 0x5144));
        }
        y++;
    } while (y < (s32)M2C_FIELD(p, u16 *, 0x5146));
}
#pragma optimization_level reset
u8 IsSameTeam(s32 a, s32 b) {
    extern s32 *gCurrentMap;
    s32 base;
    s32 work;
    u8 *p1;
    u8 *p2;
    base = *gCurrentMap + 0x3A4;
    work = base + 0x6400;
    p1 = (u8 *)(work + a * 0x8C);
    p2 = (u8 *)(work + b * 0x8C);
    return p1[0x26] == p2[0x26];
}

u8 func_020d277c(s32 arg0, s32 arg1) {
    u8 IsSameTeam(s32, s32);
    s32 GetUnitOwner(s32);
    s32 temp_r4;

    temp_r4 = GetUnitOwner(arg0);
    return IsSameTeam(temp_r4, GetUnitOwner(arg1));
}

void func_020d27a4(s32 arg0, s32 arg1) {
    u8 IsSameTeam(s32, s32);
    IsSameTeam((arg0 >> 6) + 1, (arg1 >> 6) + 1);
}

u8 IsUnitOnCurrentTeam(s32 arg0) {
    extern s32 *gCurrentMap;
    u8 IsSameTeam(s32, s32);
    return IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), (arg0 >> 6) + 1);
}

s32 IsTerrainOnUnitTeam(s32 arg0, s32 arg1) {
    s32 temp = arg0 >> 6;
    if ((arg1 >> 5) == 0) {
        return 0;
    }
    return IsSameTeam(temp + 1, arg1 >> 5);
}

s32 IsPropertyOwnedByTeam(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 *gCurrentMap;
    u8 IsSameTeam(s32, s32);
    s32 p;
    u16 val;
    u8 byte;
    s32 pos;

    p = *gCurrentMap;
    val = *(u16 *)(p + arg2 * 2 + 0x3758);
    pos = arg1 + val;
    byte = *(u8 *)(p + pos + 0x1420);
    if ((byte >> 5) == 0) {
        return 0;
    }
    return IsSameTeam(arg0, byte >> 5);
}

s32 Map_ShowsCargoForUnit(s32 arg0,s32 arg1,s32 arg2) {
extern s32 *gCurrentMap;
extern u8 gUnitKindCargoCount[];
void *base=*gCurrentMap;
if(M2C_FIELD(base,u8 *,0x5156)!=0 || M2C_FIELD(base,u8 *,0x5158)==2) {
if(!(M2C_FIELD((u8 *)base+arg2*0x8c,u8 *,0x67c3)&2)) {
if(gUnitKindCargoCount[arg0*0x70]!=0) return 1;
}
}
return 0;
}

/* After a player is defeated, give every other player of an army that still has
 * an active player back their turn: clear the defeat turn of any player sharing
 * an active player's army. */
void RestorePlayersOfActiveArmies(void) {
    extern s32 *gCurrentMap;
    s32 IsPlayerActive(s32);
    s32 j, joff, ioff, i;
    u8 *self, *other, *base;

    i = 1;
    ioff = MAP_PLAYER_STRIDE;
    do {
        if (IsPlayerActive(i)) {
            j = 1;
            joff = MAP_PLAYER_STRIDE;
            do {
                if (j != i) {
                    base = (u8 *)*gCurrentMap;
                    other = base + joff;
                    if (other[MAP_PLAYER_STATES + PLAYER_REC_CTRL]) {
                        self = base + ioff;
                        if (other[MAP_PLAYER_STATES + PLAYER_REC_ARMY] == self[MAP_PLAYER_STATES + PLAYER_REC_ARMY]) {
                            *(u16 *)(other + MAP_PLAYER_STATES + PLAYER_REC_DEFEAT_TURN) = 0;
                        }
                    }
                }
                j++;
                joff += MAP_PLAYER_STRIDE;
            } while (j < MAX_PLAYERS);
        }
        i++;
        ioff += MAP_PLAYER_STRIDE;
    } while (i < MAX_PLAYERS);
}

void func_020d2958(void) {
    extern s32 *gCurrentMap;
    s32 IsPlayerPresent(s32);
    s32 i = 1;
    s32 off = 0x8C;

    do {
        if (IsPlayerPresent(i) != 0) {
            M2C_FIELD(*gCurrentMap + off, u16 *, 0x67BE) = 0;
        }
        i++;
        off += 0x8C;
    } while (i < 5);
}

s32 IsPlayerRouted(M2C_UNK arg0) {
 s32 func_020d2a00(M2C_UNK); s32 func_020d2a6c(M2C_UNK); s32 func_020d303c(M2C_UNK);
 if (!IsPlayerActive()) return 1;
 if (func_020d2a00(arg0)) {
 if (func_020d303c(arg0)) return 1;
 if (func_020d2a6c(arg0)) return 1;
 }
 return 0;
}

s32 func_020d2a00(s32 arg0) {
    extern u16 gPlayerUnitIdBase[];
    extern s32 *gCurrentMap;
    s32 end;
    s32 i;

    i = gPlayerUnitIdBase[arg0] + 1;
    end = gPlayerUnitIdBase[arg0] + 0x33;
    if (i < end) {
        u8 *p = (u8 *)*gCurrentMap + 0x59A4 + i * 14;
        do {
            if (((u32)(*p << 26) >> 26) != 0) {
                return 0;
            }
            i++;
            p += 14;
        } while (i < end);
    }
    return 1;
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_020d2a6c(s32 arg0) {
extern s32 *gCurrentMap;extern s8 data_ov000_021b5580[];
s32 y=0;u8 *dims; s32 x,width;u8 *p;s32 byte;u8 *base=(u8*)*gCurrentMap; dims=base+0x5100;
if(y<M2C_FIELD(dims,u16 *,0x46)){
width=M2C_FIELD(dims,u16 *,0x44);{s32 zero=0;
do {
x=zero;
if(x<width){
p=base+M2C_FIELD(base+(y<<1),u16 *,0x3758);
do {
byte=M2C_FIELD(p,u8 *,0x1420);
if(arg0==((byte&0xe0)>>5) && data_ov000_021b5580[byte&31]!=0)return 0;
x++;p++;
}while(x<width);
}
y++;
}while(y<M2C_FIELD(base,u16 *,0x5146));
}
}return 1;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
/* Pay `cost` out of a player's funds: count it in the human player's battle
 * records, subtract it from the player's funds and add it to the cumulative
 * funds-spent stat (capped at PLAYER_FUNDS_SPENT_MAX). */
void PayPlayerFunds(s32 player,s32 cost) {
extern s32 *gCurrentMap; s32 IsPlayerHuman(s32); void AddRecordFunds(s32,s32);
if(IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))AddRecordFunds(11,cost);
*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE))-=cost;
*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE)+1)+=cost;
if(*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE)+1)>PLAYER_FUNDS_SPENT_MAX)
*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE)+1)=PLAYER_FUNDS_SPENT_MAX;
}

void func_020d2bc0(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 off;
    s32 *base;
    s32 *p;

    off = arg0 * 0x8C;
    base = *gCurrentMap;
    p = (s32 *)((u8 *)base + 0x67A4 + off);
    *p += arg1;
    base = *gCurrentMap;
    p = (s32 *)((u8 *)base + 0x67A4 + off);
    if (*p > 0xF423F) {
        *p = 0xF423F;
    }
}

#pragma push
#pragma opt_propagation off
s32 GetPlayerCommanderId(s32 arg0) {
    extern s32 *gCurrentMap;
    s32 func_020a27b8(s32, s32);
    struct PlayerRec { u8 pad[0x6c]; u32 id:8; u32 unk:2; u32 flag:2; } *rec;

    rec = (struct PlayerRec *)(*gCurrentMap + 0x3a4 + 0x6400 + arg0 * 0x8c);
    return func_020a27b8(rec->id, rec->flag);
}
#pragma pop
s32 func_020d2c58(s32 arg0) {
 extern M2C_UNK gMapData;
 s32 func_020a334c(s32);s32 GetCoPowerMeterCost(s32,s32);s32 func_020a3518(s32);
 s32 r5; s32 count=0;
 if((((u32)M2C_FIELD(&gMapData,u16 *,12)<<19)>>31)==0)return 0;
 if(func_020a334c(arg0))return 0;
 if(!GetCoPowerMeterCost(arg0,2))return 0;
 r5=func_020a3518(arg0);if(r5>=GetCoPowerMeterCost(arg0,1))count++;
 r5=func_020a3518(arg0);if(r5>=GetCoPowerMeterCost(arg0,2))count++;
 return count;
}

void func_020d2cf0(M2C_UNK arg0) {
    M2C_UNK func_020a25bc(s32, s32);
    s32 GetPlayerCommanderId();
    s32 func_020d2c58(M2C_UNK);
    s32 temp_r4;

    temp_r4 = GetPlayerCommanderId();
    func_020a25bc(temp_r4, func_020d2c58(arg0));
}

s32 GetUnitBuildCost(arg0, arg1)
    u16 arg0;
    s32 arg1;
{
    s32 func_020a7bbc(s32);
    s32 Divide(s32, s32);
    s32 t;

    t = func_020a7bbc(arg1);
    return Divide(t * 0x64, 0x64);
}

s32 GetUnitBuildCostTimes10(void) {
    return GetUnitBuildCost() * 0xA;
}

s32 GetUnitActionCost(void) {
    s32 GetUnitBuildCost();
    return GetUnitBuildCost() * 5;
}

void func_020d2d60(M2C_UNK arg0) {
    s32 func_020a32a8();
    M2C_UNK func_020a3100(M2C_UNK);
    if (func_020a32a8() != 0) {
        return;
    }
    func_020a3100(arg0);
}

void func_020d2d80(M2C_UNK arg0) {
    M2C_UNK func_020a33f0(M2C_UNK, M2C_UNK);
    func_020a33f0(arg0, 0);
}

void PayPlayerIncome(s32 arg0) {
    extern s32 *gCurrentMap;
    void func_020d2bc0(s32, s32);
    s32 base = *gCurrentMap;
    s32 v = M2C_FIELD(base, u16 *, 0x52A2);

    if (v <= 0) {
        return;
    }
    func_020d2bc0(arg0, M2C_FIELD(base + arg0 * 0x8C, s32 *, 0x6000 + 0x7AC));
}

s32 FindFreeUnitRecord(s32 arg0) {
    extern u16 gPlayerUnitIdBase[];
    extern s32 *gCurrentMap;
    s32 val;
    s32 end;
    s32 i;
    u8 *base;
    u8 *p;

    val = gPlayerUnitIdBase[arg0];
    i = val + 1;
    end = val + 0x33;
    if (i < end) {
        base = (u8 *)*gCurrentMap + 0x59A4;
        p = base + i * 14;
        do {
            if (((u32)(*p << 26) >> 26) == 0) {
                return (s32)(base + i * 14);
            }
            i++;
            p += 14;
        } while (i < end);
    }
    return 0;
}

#pragma opt_common_subs on
void *func_020d2e3c(u16 arg0) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
register s32 start;
u32 teamOffset;
s32 *map;
u32 offset;
u8 *base;
u32 team;
s16 *current;
u16 x;
SelectionUnit *units;
map=gCurrentMap;
base=(u8 *)*map;
team=gPlayerUnitIdBase[arg0];
start=*(s16 *)(base+0x52c0)+1;
current=(s16 *)(base+0x52c0);
x=start;
if(x<51) {
teamOffset=team*14;
units=(SelectionUnit *)(base+0x59a4);
do {
offset=(x+team)*14;
if (((SelectionKind *)((u8 *)units+offset))->kind &&
!(M2C_FIELD((u8 *)((u32)base+teamOffset)+x*14,u16 *,0x59a8)&1)) {
*current=x;
base=(u8 *)*gCurrentMap;
current=(s16 *)(base+0x52c0);
if(*(s16 *)(base+0x52c0)>=50) *current=0;
return (u8 *)*gCurrentMap+0x59a4+offset;
}
} while(++x<51);
}
x=1;
if(start>1) {
base=(u8 *)*map;
units=(SelectionUnit *)(base+0x59a4);
do {
offset=(x+team)*14;
if (((SelectionKind *)((u8 *)units+offset))->kind &&
!(M2C_FIELD(base+team*14+x*14,u16 *,0x59a8)&1)) {
*current=x;
base=(u8 *)*gCurrentMap;
current=(s16 *)(base+0x52c0);
if(*(s16 *)(base+0x52c0)>=50) *current=0;
return (u8 *)*gCurrentMap+0x59a4+offset;
}
} while (++x < *(s16 *)(base+0x52c0)+1);
}
return 0;
}
#pragma opt_common_subs reset
u8 func_020d2ff0(s32 arg0) {
    extern s32 *gCurrentMap;
    return M2C_FIELD(((arg0 * 0x8C) + *gCurrentMap), u8 *, 0x67D5);
}

u8 func_020d3014(s32 a, s32 b) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)(a*0x8c+*gCurrentMap);
p+=b;
return p[0x67d7];
}

s32 func_020d303c(s32 arg0) {
    extern s32 *gCurrentMap;
    s32 i;
    s32 acc;
    u8 *p;

    acc = 0;
    i = acc;
    p = (u8 *)*gCurrentMap + arg0 * 0x8C;
    do {
        acc += p[0x67D7];
        p++;
        i++;
    } while (i < 0x1B);
    return acc;
}

u8 func_020d3080(s32 a,s32 b) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)(a*0x8c+*gCurrentMap);
p+=b;
return p[0x67f2];
}

s32 func_020d30a8(s32 a) {
extern s32 *gCurrentMap;
s32 i;
s32 sum;
u8 *p;
sum=0;
p=(u8 *)(a*0x8c+*gCurrentMap);
for(i=0;i<27;i++,p++)sum+=M2C_FIELD(p,u8 *,0x67f2);
return sum;
}

void func_020d30ec(s32 a) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
if((u32)p[0x31]<255)p[0x31]++;
}

s32 DecrementPlayerUnitCount(s32 a) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
s32 v=p[0x31];
if(v!=0){v--;p[0x31]=v;}
return v;
}

void func_020d3154(s32 a,s32 b) {
extern s32 *gCurrentMap;
u8 *p;
func_020d30ec(a);
p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
p+=0x33;
if(p[b]!=255)p[b]++;
}

void func_020d319c(s32 a,s32 b) {
extern s32 *gCurrentMap;
u8 *p;
DecrementPlayerUnitCount(a);
p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
p+=0x4e;
if(p[b]!=255)p[b]++;
}

void func_020d31e4(void) {
    M2C_UNK DecrementPlayerUnitCount();
    DecrementPlayerUnitCount();
}

void SetPlayerGaveUp(s32 a, u8 b) {
extern s32 *gCurrentMap;
M2C_FIELD(a*0x8c+*gCurrentMap,u8 *,0x67d3)=b;
}

u8 HasPlayerGivenUp(s32 a){extern s32 *gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x67d3]!=0;}

u8 HasActivePlayerGivenUp(M2C_UNK arg0) {
    u8 var_r0;

    if (IsPlayerActive() == 0) {
        return 0U;
    }
    if (HasPlayerGivenUp(arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void SetPlayerLost(s32 a,u8 b) {
extern s32 *gCurrentMap;
M2C_FIELD(a*0x8c+*gCurrentMap,u8 *,0x67d4)=b;
}

u8 HasPlayerLost(s32 a){extern s32 *gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x67d4]!=0;}

u8 IsPlayerHqIntact(s32 a){
extern s32 *gCurrentMap;u8 result;
if(!(((u8 *)*gCurrentMap)[0x5155]&2))return 1;
if(IsPlayerActive(a)==0)return 0;
if(HasPlayerLost(a)==0)result=1;else result=0;
return result;
}

u8 IsPlayerStillFighting(s32 a){
extern s32 *gCurrentMap;u8 result;
if(!(((u8 *)*gCurrentMap)[0x5155]&1))return 1;
if(IsPlayerRouted(a)==0)result=1;else result=0;
return result;
}

u8 IsHumanPlayerStillFighting(s32 a){
extern s32 *gCurrentMap; s32 IsPlayerHuman(s32); u8 result;
if(IsPlayerHuman(a)==0)return 1;
if(!(((u8 *)*gCurrentMap)[0x5155]&16))return 1;
if(IsPlayerRouted(a)==0)result=1;else result=0;
return result;
}

void func_020d33c4(void) {
    extern M2C_UNK gMapData;
    M2C_FIELD(&gMapData, s32 *, 8) = 0;
}

void func_020d33d8(void) {
    extern M2C_UNK gMapData;
    M2C_FIELD(&gMapData, s32 *, 8) = 1;
}

void func_020d33ec(void) {
    extern M2C_UNK gMapData;
    M2C_FIELD(&gMapData, s32 *, 8) = 0;
}

void func_020d3400(void){
extern M2C_UNK gMapData; extern s32 *gCurrentMap;
s32 IsTouchInputDisabled(void); s32 IsBattleEffectActive(void); void IncrementCounter(void *);
u8 *p; s32 q;
if(M2C_FIELD(&gMapData,s32 *,8)==0)return;
if(IsTouchInputDisabled()!=0)return;
if(IsBattleEffectActive()!=0)return;
p=(u8 *)*gCurrentMap;
q=(s32)p+0x67a4+M2C_FIELD(p,u16 *,0x52a4)*0x8c;
IncrementCounter((u8 *)q+0x84);
}

