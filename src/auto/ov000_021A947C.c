/* 29 functions from 0x021A947C to 0x021AA3FC (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline s32 unit_blocks_action(s32 unit) {
 extern void **gCurrentMap;
 s32 func_020a33c4(s32);
 if (((u32)(M2C_FIELD((u8 *)*gCurrentMap + unit*0x8c, s32 *, 0x6810)<<24)>>24)==3 && func_020a33c4(unit)) return 1;
 return 0;
}

#pragma push
#pragma opt_propagation off
/* Fog-of-war visibility test used by targeting and threat marking: tells whether a
 * unit of the given kind, belonging to the given player, standing at (x,y) is visible.
 * Units are visible with fog off, when the cell holds a friendly unit, or when an
 * orthogonal neighbour does; the unit kind and the cell's terrain can also hide it. */
s32 IsUnitVisibleAtCell(s32 player, s32 unitKind, s32 x, s32 y) {
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern u8 gUnitKindFlags[];
    extern s8 data_ov000_021b5680[];
    s32 func_020a33c4(s32);
    u8 IsCellUnitOnSameArmy(u8, s32, s32);
    s32 func_ov000_021a93b0(s32, s32, s32);

    s32 cellY = y;
    s32 cellX = x;
    s32 kind = unitKind;
    s32 side = player;
    u16 neighbours = 0;

    if (M2C_FIELD(*gCurrentMap, u8 *, 0x5156) == 0) {
        if (M2C_FIELD(gAiCommandState, u8 *, 0xD) != 2) {
            return 1;
        }
    }
        if (!func_ov000_021a93b0(side, cellX, cellY)) {
            return 1;
        }
    if (unit_blocks_action(side)) return 1;

    if (IsCellUnitOnSameArmy(side, cellX, cellY) == 1) {
        return 1;
    }

    if (gUnitKindFlags[kind * 0x70] == 0x10) {
        u16 row = M2C_FIELD((u8 *)*gCurrentMap + cellY * 2, u16 *, MAP_ROW_OFFSETS);
        u8 terrain = M2C_FIELD((u8 *)*gCurrentMap + (cellX + row), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
        if (data_ov000_021b5680[terrain] == 0) {
            return 1;
        }
    }

    if (cellX > 0) {
        neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, (s16)(cellX - 1), cellY));
    }
    if (cellY > 0) {
        neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, cellX, (s16)(cellY - 1)));
    }
    {
        u16 width = M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH);
        if (cellX < (s32)width - 1) {
            neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, (s16)(cellX + 1), cellY));
        }
    }
    {
        u16 height = M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT);
        if (cellY < (s32)height - 1) {
            neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, cellX, (s16)(cellY + 1)));
        }
    }

    return neighbours != 0;
}
#pragma pop
void GetAttackDamage(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_020a79e0(M2C_UNK, M2C_UNK, s32, u8, s32, s32, s32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    func_020a79e0(arg0, arg1, 0, M2C_FIELD(gAiCommandState, u8 *, 0xC), M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), 0, arg2);
}

void func_ov000_021a96f4(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_020a79e0(M2C_UNK, M2C_UNK, s32, u8, s32, s32, s32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    func_020a79e0(arg0, arg1, 1, M2C_FIELD(gAiCommandState, u8 *, 0xC), M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), 0, arg2);
}

s32 func_ov000_021a9740(void *arg0, M2C_UNK arg1) {
    s32 func_020a5ae0(M2C_UNK);
    s32 CalculateUnitDamage(void *, s32, M2C_UNK, M2C_UNK);
    extern u8 gUnitKindMaxAmmo;
    s32 var_r0;
    s32 var_r5;
    if ((*(&gUnitKindMaxAmmo + (((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) * 0x70)) != 0) && (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C) == 0)) {
        var_r5 = 0;
    } else {
        var_r5 = CalculateUnitDamage(arg0, func_020a5ae0(arg1), 0, 0);
    }
    var_r0 = CalculateUnitDamage(arg0, func_020a5ae0(arg1), 1, 0);
    if (var_r5 > var_r0) var_r0 = var_r5;
    return var_r0;
}

void GetUnitDamagePercent(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020a799c(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020a799c(arg0, arg1, 0);
}

void GetUnitMoveRange(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK ComputeUnitMoveRange(M2C_UNK, u8, u16, s32, s32);
    extern void **data_027e0058;
    extern void *gAiCommandState;
    ComputeUnitMoveRange(arg1, M2C_FIELD(gAiCommandState, u8 *, 0xD), M2C_FIELD(*data_027e0058, u16 *, 0x52A4), 0, 0);
}

void GetUnitMaxAttackRange(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK ComputeUnitMaxAttackRange(M2C_UNK, u8, u16, s32, s32);
    extern void **data_027e0058;
    extern void *gAiCommandState;
    ComputeUnitMaxAttackRange(arg1, M2C_FIELD(gAiCommandState, u8 *, 0xD), M2C_FIELD(*data_027e0058, u16 *, 0x52A4), 0, 0);
}

s32 func_ov000_021a9860(s32 a,s32 b) {
 extern void **data_027e0058;s32 GetTerrainPropertyFlagsAt(s32,s32);
 s32 p=(s32)*data_027e0058;
 if((M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31)==24)return 1;
 return GetTerrainPropertyFlagsAt(a,b);
}

s32 IsFootUnitKind(s32 a) {
 switch(a){case 1:case 2:case 3:return 1;default:return 0;}
}

s32 IsCaptureKind(s32 a) {
 switch(a){case 1:case 2:return 1;default:return 0;}
}

s32 GetUnitAttackClass(s32 arg0) {
    s32 GetUnitKindMaxAttackRange(void);
    s32 temp_r0;

    (void)arg0;
    temp_r0 = GetUnitKindMaxAttackRange();
    if (temp_r0 > 1) {
        return 1;
    }
    if (temp_r0 == 1) {
        return 0;
    }
    return 2;
}

s32 func_ov000_021a9904(s32 arg0) {
    s32 temp_r0;

    temp_r0 = GetUnitKindMaxAttackRange();
    if (arg0 == 0x19) {
        return 2;
    }
    if (temp_r0 > 1) {
        return 1;
    }
    if (temp_r0 == 1) {
        return 0;
    }
    return 2;
}

s32 CanKindAttack(s32 a,s32 b) {
 extern u8 data_ov000_021b5c5e[];extern u8 data_ov000_021b5c5d[];
 u8 *p=&data_ov000_021b5c5e[b*0x70];
 return p[data_ov000_021b5c5d[a*0x70]];
}

u8 CanUnitAttackKind(u8 *arg0,s32 arg1) {
extern u8 gUnitKindCargoCount[];
u32 a=(u32)(*arg0<<26)>>26; u8 result;
if(!gUnitKindCargoCount[a*0x70]) return 0;
if(!CanKindAttack(a,arg1)) return 0;
if(M2C_FIELD(arg0+(gUnitKindCargoCount[((u32)(*arg0<<26)>>26)*0x70]-1),u8 *,12)==0) result=1;else result=0;
return result;
}

s32 func_ov000_021a99dc(u8 *arg0) {
 if(GetUnitAttackClass((u32)(*arg0<<26)>>26)==2 || ((u32)(*arg0<<26)>>26)==25) {
 if(arg0[12]==0) return 1;
 }
 return 0;
}

/* Returns 1 if the unit's terrain unit table permits passing through the given map cell. */
u8 CanUnitKindStandAt(s32 unitKind, s32 mapX, s32 mapY) {
    extern void **gCurrentMap;
    extern u8 gUnitKindStats[];
    extern u8 gMovementTypeTable[];
    extern s8 data_ov000_021b54a0[];
    extern u8 gMovementCostTable[];
    void *map = *gCurrentMap;
    s32 terrain = M2C_FIELD(map + (mapX + M2C_FIELD(map + mapY * 2, u16 *, 0x3758)), u8 *, 0x1420) & 31;
    switch (unitKind) {
    case 13:
    case 19:
        return M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gUnitKindStats[0x82] * 32, s8 *, terrain) != -1;
    case 24:
    case 25:
        if (data_ov000_021b54a0[terrain] == 0) {
            return 0;
        }
        if (M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gUnitKindStats[0x82] * 32, s8 *, terrain) == -1) {
            return 0;
        }
        return M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gMovementTypeTable[unitKind * 112] * 32, s8 *, terrain) != -1;
    case 21:
    case 23:
        return M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gMovementTypeTable[unitKind * 112] * 32, s8 *, terrain) != -1;
    default:
        return 0;
    }
}

u8 func_ov000_021a9b84(void) {
 extern void **gCurrentMap;
 s32 func_020a8a14(u16,u16);
 u8 result;
 if(!(func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&1)) result=1; else result=0;
 return result;
}

s32 func_ov000_021a9bc0(void *arg0) {
 extern void **gCurrentMap;
 s32 IsSameTeam(u16,s32);
 u32 owner=(u32)(M2C_FIELD(arg0,u8 *,5)<<29);
 s32 i;
 if(M2C_FIELD(arg0,u8 *,4)==0)return 0;
 for(i=1;i<5;i++){
 if(IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52A4),i)!=0 && i==(owner>>29))return 0;
 }
 return 1;
}

s32 HasEnemyPlayer(void) {
 extern void **gCurrentMap;
 s32 IsPlayerActive(s32);
 s32 IsSameTeam(u16,s32);
 s32 func_020d243c(s32);
 s32 i=1;
loop:
 if(IsPlayerActive(i)!=0 && IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52A4),i)==0 && func_020d243c(i)==1)return 1;
 i++;
 if(i>=5)return 0;
 goto loop;
}

s32 func_ov000_021a9c90(s32 x,s32 y) {
 extern void **data_027e0058; extern void *gAiCommandState;
 s32 count=0,i,xmin=x-1,d,v; register s32 ymin,xmax,ymax;
 if(xmin<0)xmin=0;
 ymin=y-1;
 if(ymin<0)ymin=0;
 xmax=M2C_FIELD(*data_027e0058,u16 *,0x5144)-1;
 if(x+1<xmax)xmax=x+1;
 ymax=M2C_FIELD(*data_027e0058,u16 *,0x5146)-1;
 if(y+1<ymax)ymax=y+1;
 for(;ymin<=ymax;ymin++)for(i=xmin;i<=xmax;i++){
 d=0; if(x-i>0)d+=x-i;else d+=i-x; if(y-ymin>0)d+=y-ymin;else d+=ymin-y;
 if(d<1||d>1)continue;
 v=M2C_FIELD(((s8 **)((u8 *)*data_027e0058+0x52e8))[ymin],s8 *,i);
 if(v>=0 && v<=M2C_FIELD(gAiCommandState,u8 *,5))count++;
 }
 return count;
}

u8 IsAllyUnitAtCell(u32 arg0,s32 arg1) {
 extern void **gCurrentMap;
 s32 func_020a600c(u16);
 void *base=*gCurrentMap;
 u32 index=arg0+M2C_FIELD(base+arg1*2,u16 *,0x3758);
 s32 id;
 if((u8)(M2C_FIELD(base+(index>>3),u8 *,0x5160)&(1<<(index&7)))==0)return 0;
 id=M2C_FIELD(base+index,u8 *,0);
 if(id!=0)return func_020a600c((u16)(id & 0xFFFF))!=0;
 return 0;
}

u32 CellMoveScore(s32 x,s32 y,s32 a,s32 b){
extern void **gCurrentMap;
extern u8 data_ov000_021e0a58[],gUnitKindFlags[],data_ov000_021dfb04[],gAiRangeBitmap[],data_ov000_021dfa60[],data_ov000_021dfba8[];
void *base=*gCurrentMap;
u32 row=M2C_FIELD(base+y*2,u16 *,0x3758);
u8 *cell=(u8 *)base+(x+row);
s32 d=M2C_FIELD(cell,u8 *,0x2d48);
void *unit=M2C_FIELD(base,void **,0x52d0);
s32 unitByte=M2C_FIELD(unit,u8 *,0);s32 kind=(u32)(unitByte<<26)>>26;
s32 width=M2C_FIELD(base,u16 *,0x5144);u32 index=y*width+x;
u8 flags=gUnitKindFlags[kind*112];
u32 result=(data_ov000_021e0a58[index]+((a*M2C_FIELD(cell,u8 *,0x2840)+b*d)<<8))<<2;
if(flags&7){
s32 first=(u8)(data_ov000_021dfb04[index>>3]&(1<<(index&7)))==0?1:0;
s32 second=(u8)((1<<(index&7))&gAiRangeBitmap[index>>3])!=0?0:2;
result|=second|first;
}
if(flags&16){
s32 first=(u8)(data_ov000_021dfa60[index>>3]&(1<<(index&7)))==0?1:0;
s32 second=(u8)((1<<(index&7))&data_ov000_021dfba8[index>>3])!=0?0:2;
result|=second|first;
}
return result;
}

/* Returns the id of the best unit the current player can still be ordered to
 * move: the highest-valued unit that has not acted, is at full health, is not
 * the unit already selected, and passes the terrain, commander and cost checks.
 * Returns 0 when there is none. */
s32 FindBestSelectableUnit(void) {
 extern void **gCurrentMap; extern u16 gMapConfig; extern u16 gPlayerUnitIdBase[]; extern s32 (**gAiSettings)(s32,s32);
 s32 GetPlayerCommanderId(u16); s32 func_020a3150(u16); void *GetPlayerSelectedUnit(u16); s32 IsUnitSelected(void *); s32 func_020cf908(s32,s32,s32,s32); s32 func_020a2788(s32,s32); s32 func_020d2d50(s32,s32); s32 func_020a7bbc(s32); s32 func_ov000_021aa2c4(s32,s32);
 s32 commander; u8 *best; s32 id; u8 *unit; s32 offset;
 GetPlayerCommanderId(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER));
 best=0;
 if(((u32)(gMapConfig<<18)>>31)==0)return 0;
 if(((u32)(M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)*140,s32 *,0x6810)<<24)>>24)==0)return 0;
 if(!func_020a3150(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))return 0;
 if(GetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))return 0;
 commander=GetPlayerCommanderId(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER));
 id=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+1;
 if(id<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+51){
 offset=id*14; do {
 unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+offset;
 if(((u32)(unit[0]<<26)>>26)==0)goto next;
 if(M2C_FIELD(unit,u16 *,4)&9)continue;
 if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)!=100)continue;
 if(IsUnitSelected(unit))continue;
 if(((u32)(unit[11]<<28)>>28)==5 || ((u32)(unit[11]<<28)>>28)==6 || ((u32)(unit[11]<<28)>>28)==8)continue;
 if(!func_020cf908(unit[1],unit[2],M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),(u32)(unit[0]<<26)>>26))continue;
 if(!func_020a2788(commander,(u32)(unit[0]<<26)>>26))continue;
 {u8 *map=*gCurrentMap; s32 player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
 if(func_020d2d50(player,(u32)(unit[0]<<26)>>26)>M2C_FIELD(map+player*140,s32 *,0x67a4))continue;}
 if(*gAiSettings==0){if(func_ov000_021aa2c4(commander,(u32)(unit[0]<<26)>>26)){goto select;}goto next;}
 else {if((*gAiSettings)(commander,(u32)(unit[0]<<26)>>26))goto select;goto next;}
 select:
 if(best && func_020a7bbc((u32)(best[0]<<26)>>26)>=func_020a7bbc((u32)(unit[0]<<26)>>26))continue;
 best=unit;
 next:;
 }while((++id,offset+=14,id)<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+51);
 }
 if(best){if(!best)return 0;return ((s32)best-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/14;}
 return 0;
}

s32 func_ov000_021aa214(void) {
 extern u16 gMapConfig;
 extern void **gCurrentMap;
 s32 func_020a2be0(u16); void *GetPlayerSelectedUnit(u16);
 void *p;
 if(((u32)(gMapConfig<<18)>>31)==0)return 0;
 if(!func_020a2be0(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))return 0;
 p=GetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
 if(M2C_FIELD(p,u16 *,4)&9)return 0;
 if(!p)return 0;
 return ((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;
}

s32 func_ov000_021aa2c4(s32 a,s32 b) {
 s32 func_020a27a0(s32,s32); s32 func_020a25bc(s32,s32);
 if(!func_020a27a0(a,b))return 0;
 if(func_020a27a0(a,9)||func_020a27a0(a,14)){
 if(func_020a25bc(a,0)<=1){if(b!=9 && b!=14 && b!=16)return 0;}
 else {if(b!=9 && b!=8 && b!=7 && b!=14 && b!=16)return 0;}
 }else {if(b!=26 && b!=11 && b!=20)return 0;}
 return 1;
}

s32 func_ov000_021aa370(s32 arg0,s32 arg1) {
 if(arg1!=9 && arg1!=8 && arg1!=7 && arg1!=14 && arg1!=16 && arg1!=26 && arg1!=11)return 0;
 return 1;
}

s32 func_ov000_021aa398(s32 arg0, s32 arg1) {
 if(arg1!=9 && arg1!=8 && arg1!=14 && arg1!=16 && arg1!=26 && arg1!=11) return 0;
 return 1;
}

u8 func_ov000_021aa3bc(void) {
    extern void **gCurrentMap;
    u8 var_r0;

    if ((u32) ((u32) (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u16 *, 6) << 0x19) >> 0x19) < 0x32U) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021aa3f4(void) {
    return 1;
}
