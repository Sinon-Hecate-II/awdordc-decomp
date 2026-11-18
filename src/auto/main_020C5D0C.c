/* 54 functions from 0x020C5D0C to 0x020C6CF8 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1[5];
    u16 unk6 : 7;
    u16 unk6_7 : 4;
    u16 unk6_11 : 5;
    u8 unk8[3];
    u8 unkB : 4;
    u8 unkB_4 : 4;
    u8 unkC[2];
} UnkStruct_020C5D0C;

s32 func_020c5d0c(void) {
    s32 func_020cd6d4();
    extern u8 gBattleEndState;
    if ((gBattleEndState == 0) && (func_020cd6d4() != 0)) {
        return 0;
    }
    return 2;
}

s32 func_020c5d3c(void) {
    s32 func_020cd6fc();
    extern u8 gBattleEndState;
    if ((gBattleEndState == 0) && (func_020cd6fc() != 0)) {
        return 0;
    }
    return 2;
}

u8 func_020c5d6c(void) {
    s32 IsUnitAvailable();
    M2C_UNK func_020befd8();
    extern u8 gBattleEndState;
    u8 var_r0;

    if (gBattleEndState != 0) {
        return 2;
    }
    func_020befd8();
    if (IsUnitAvailable() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020c5da4(void) {
    M2C_UNK func_ov000_0216aaf4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_0216aaf4();
}

void func_020c5db4(void) {
    M2C_UNK func_ov000_02171214();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_02171214();
}

void func_020c5dc4(void) {
    M2C_UNK func_020b9140(M2C_UNK);
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    func_020b9140(0);
}

void func_020c5de0(void) {
    extern void **gCurrentMap;
    func_020c0784();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B4) = 3;
}

s32 func_020c5e08(void) {
    s32 func_020cd6d4();
    s32 func_ov000_0216b104();
    if ((func_020cd6d4() != 0) && (func_ov000_0216b104() != 0)) {
        return 0;
    }
    return 2;
}

s32 func_020c5e30(void) {
    s32 func_020a8afc(u16);
    extern void **gCurrentMap;

    if (func_020a8afc(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) != 0) {
        return 0;
    }
    return 2;
}

/* Whether any player taking part in the battle has an army (nation) assigned:
 * returns 0 when one does, 2 when none does, the map's rule bit 1 blocks it or
 * the battle has already ended. */
s32 AnyPlayerHasArmy(void) {
    struct bits8 {
        u32 value : 8;
    };
    s32 func_020a88e8(u16);
    s32 IsPlayerPresent(s32);
    extern u8 gBattleEndState;
    extern void **gCurrentMap;
    s32 player;
    s32 playerOffset;
    u32 armyId;

    if (func_020a88e8(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID)) != 0) {
        return 2;
    }
    if (gBattleEndState != 0) {
        return 2;
    }
    player = 1;
    playerOffset = MAP_PLAYER_STRIDE;
    do {
        if (IsPlayerPresent(player) != 0) {
            armyId = ((struct bits8 *) ((s8 *) *gCurrentMap + playerOffset + (MAP_PLAYER_STATES + PLAYER_REC_SPRITE)))->value;
            if (armyId != 0) {
                return 0;
            }
        }
        player += 1;
        playerOffset += MAP_PLAYER_STRIDE;
    } while (player < 5);
    return 2;
}

/* Whether the current player's own unit group is empty: 1 when every record of
 * the group (ids gPlayerUnitIdBase[player]+1 .. +0x32) is unoccupied, 0 when at
 * least one unit is left.  Unlike IsCurrentPlayerOutOfUnits this ignores the
 * map-data rule that can suppress the rout test. */
s32 CurrentPlayerHasNoUnits(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count = 0;
    s32 i;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];

    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
        UnkStruct_020C5D0C *entry = &((UnkStruct_020C5D0C *)((u8 *)base + MAP_UNIT_RECORDS))[i];
        if (entry->unk0 != 0) { count += 1; }
    }
    if (count == 0) { return 1; }
    return 0;
}

s32 func_020c5f94(void) {
    s32 func_020c5cd4();
    s32 CurrentPlayerHasNoUnits();
    if (func_020c5cd4() == 2) {
        return 2;
    }
    return CurrentPlayerHasNoUnits();
}

/* Whether the current player has no units left: 1 when none of the player's
 * unit-group records is occupied, 0 when at least one is. Returns 2 up front
 * when the map data's +4 flag bit 3 is set. */
s32 IsCurrentPlayerOutOfUnits(void) {
    s32 func_020a8910(u16);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count = 0;
    s32 i;
    void *base;
    u16 start;

    if (func_020a8910(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID)) != 0) {
        return 2;
    }
    base = *gCurrentMap;
    start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];
    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
        UnkStruct_020C5D0C *entry = &((UnkStruct_020C5D0C *)((u8 *)base + MAP_UNIT_RECORDS))[i];
        if (entry->unk0 != 0) { count += 1; }
    }
    if (count == 0) { return 1; }
    return 0;
}

s32 func_020c606c(void) {
    s32 IsCurrentPlayerOutOfUnits();
    if (func_020c5cd4() == 2) {
        return 2;
    }
    return IsCurrentPlayerOutOfUnits();
}

s32 func_020c6088(void) {
    extern void **gCurrentMap;
    void *base = *gCurrentMap;
    s16 a = M2C_FIELD(base, s16 *, 0x52DE);
    s16 b = M2C_FIELD(base, s16 *, 0x52DC);
    u16 c = M2C_FIELD((u8 *)base + a * 2, u16 *, 0x3758);
    if (M2C_FIELD(base, u8 *, b + c) == 0) { return 0; }
    return 2;
}

s32 CanJoinUnitAtCursor(void) {
    s32 CanUnitsJoin(s32, s32);
    extern void **gCurrentMap;
    void *base = *gCurrentMap;
    s16 a = M2C_FIELD(base, s16 *, 0x52DE);
    s16 b = M2C_FIELD(base, s16 *, 0x52DC);
    u16 c = M2C_FIELD((u8 *)base + a * 2, u16 *, 0x3758);
    u8 d = M2C_FIELD(base, u8 *, b + c);

    if (d == 0) {
        return 2;
    }
    if (CanUnitsJoin(M2C_FIELD(base, s32 *, 0x52D0), (s8 *)base + 0x59A4 + d * 0xE) == 0) {
        return 2;
    }
    return 0;
}

s32 CanLoadUnitAtCursor(void) {
    s32 func_020ba790(s16, s16);
    extern void **gCurrentMap;
    void *base = *gCurrentMap;
    s16 a = M2C_FIELD(base, s16 *, 0x52DC);
    s16 b = M2C_FIELD(base, s16 *, 0x52DE);

    if (func_020ba790(a, b) == 1) {
        return 0;
    }
    return 2;
}

s32 func_020c6384(void) {
 s32 GetHeldDirection(s32); s32 IsCarrierUnitKind(s32); s32 func_020ba770(void *,s32,s32);
 extern void **gCurrentMap;
 void *base;
 if(GetHeldDirection(0)!=0)return 2;
 if(CanLoadUnitAtCursor()==0)return 2;
 if(IsCarrierUnitKind(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->unk0)!=0)return 2;
 base=*gCurrentMap;
 if(func_020ba770(M2C_FIELD(base,void **,0x52D0),M2C_FIELD(base,s16 *,0x52DC),M2C_FIELD(base,s16 *,0x52DE))!=0)return 0;
 return 2;
}

s32 func_020c6414(void) {
 s32 GetHeldDirection(s32); s32 IsCarrierUnitKind(s32); s32 func_020ba780(void *,s32,s32);
 extern void **gCurrentMap;
 void *base;
 if(GetHeldDirection(1)!=0)return 2;
 if(CanLoadUnitAtCursor()==0)return 2;
 if(IsCarrierUnitKind(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->unk0)!=0)return 2;
 base=*gCurrentMap;
 if(func_020ba780(M2C_FIELD(base,void **,0x52D0),M2C_FIELD(base,s16 *,0x52DC),M2C_FIELD(base,s16 *,0x52DE))!=0)return 0;
 return 2;
}

/* Whether the carrier under the cursor may drop the unit in its first cargo
   slot: the unit must be a carrier that has not moved this turn, the slot must
   hold a unit that has not acted yet, and the cursor must still be on the
   carrier.  Returns 0 when the action is available, 2 when it is not. */
s32 CanDropFirstCargo(void) {
    s32 IsCarrierUnitKind(s32);
    extern void **gCurrentMap;
    void *base;
    u32 cargoId;

    if (CanLoadUnitAtCursor() == 0) return 2;
    if (IsCarrierUnitKind(((BattleMapUnitHead *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT))->kind) == 0) return 2;
    base = *gCurrentMap;
    cargoId = M2C_FIELD(M2C_FIELD(base, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_FIRST_CARRIED);
    if (cargoId == 0) return 2;
    if (M2C_FIELD((u8 *)base + cargoId * MAP_UNIT_STRIDE, u16 *, MAP_UNIT_RECORDS + MAP_UNIT_FLAGS) & UNIT_FLAG_ACTED) return 2;
    if (M2C_FIELD(base, s16 *, MAP_CURSOR_X) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_X) || M2C_FIELD(base, s16 *, MAP_CURSOR_Y) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_Y)) return 2;
    return 0;
}

/* Whether the carrier under the cursor may drop the unit in its second cargo
   slot: the unit must be a carrier that has not moved this turn, the slot must
   hold a unit that has not acted yet, and the cursor must still be on the
   carrier.  Returns 0 when the action is available, 2 when it is not. */
s32 CanDropSecondCargo(void) {
    s32 IsCarrierUnitKind(s32);
    extern void **gCurrentMap;
    void *base;
    u32 cargoId;

    if (CanLoadUnitAtCursor() == 0) return 2;
    if (IsCarrierUnitKind(((BattleMapUnitHead *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT))->kind) == 0) return 2;
    base = *gCurrentMap;
    cargoId = M2C_FIELD(M2C_FIELD(base, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED);
    if (cargoId == 0) return 2;
    if (M2C_FIELD((u8 *)base + cargoId * MAP_UNIT_STRIDE, u16 *, MAP_UNIT_RECORDS + MAP_UNIT_FLAGS) & UNIT_FLAG_ACTED) return 2;
    if (M2C_FIELD(base, s16 *, MAP_CURSOR_X) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_X) || M2C_FIELD(base, s16 *, MAP_CURSOR_Y) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_Y)) return 2;
    return 0;
}

/* Whether the unit under the cursor may deploy a unit: the unit must be a carrier
   that has not moved and has no second carried unit, must have ammo if its kind
   uses any, and its player must be able to afford the deployed unit's cost and
   have a free unit record.  Returns 0 when the action is available, 2 when not. */
s32 CanCarrierDeployUnit(void){
extern void **gCurrentMap;
extern u8 gUnitKindMaxAmmo[];
void *map; UnkStruct_020C5D0C *unit; u16 player;
if(IsUnitKindCarrier(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))->unk0)==0)return 2;
map=*gCurrentMap;
unit=M2C_FIELD(map,UnkStruct_020C5D0C **,MAP_CURSOR_UNIT);
if(M2C_FIELD(unit,u8 *,13))return 2;
if(M2C_FIELD(map,s16 *,MAP_CURSOR_X)!=M2C_FIELD(map,s16 *,MAP_CURSOR_OLD_X)||M2C_FIELD(map,s16 *,MAP_CURSOR_Y)!=M2C_FIELD(map,s16 *,MAP_CURSOR_OLD_Y))return 2;
if(gUnitKindMaxAmmo[unit->unk0*0x70] && unit->unk6_7==0)return 2;
player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
if(GetUnitBuildCostTimes10(player,17)>M2C_FIELD(map+player*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF))return 2;
if(FindFreeUnitRecord(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER))==0)return 2;
return 0;
}

/* Whether the unit under the cursor can resupply: the map must not be in the mode
 * that blocks the action, joining and loading must be unavailable, the cursor unit
 * must be a supply kind, and at least one adjacent friendly unit must need
 * resupply.  Returns 0 when the action is available, 2 when it is not. */
s32 CanSupplyAtCursor(void) {
 extern void **gCurrentMap;
 s32 IsSupplyUnitKind(void *); s32 FillMapLayer(s32); s32 ClearAdjacentMoveDirs(s32,s32); s32 CollectSupplyTargets(s32);
 void *base;
 if(M2C_FIELD(*gCurrentMap,u16 *,MAP_MODE)==7)return 2;
 if(CanJoinUnitAtCursor()==0)return 2;
 if(CanLoadUnitAtCursor()==0)return 2;
 if(IsSupplyUnitKind(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))==0)return 2;
 FillMapLayer(-1);
 base=*gCurrentMap;
 if(CollectSupplyTargets(ClearAdjacentMoveDirs(M2C_FIELD(base,s16 *,MAP_CURSOR_X),M2C_FIELD(base,s16 *,MAP_CURSOR_Y)))!=0)return 0;
 return 2;
}

s32 func_020c67bc(void) {
 extern void **gCurrentMap;
 if(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u16 *,4)&0x20)return 2;
 if(CanJoinUnitAtCursor()==0)return 2;
 if(CanLoadUnitAtCursor()==0)return 2;
 return 0;
}

s32 func_020c6134(void) {
    s32 CanJoinUnitAtCursor();
    s32 CanLoadUnitAtCursor();
    M2C_UNK FillMapLayer(s32);
    s32 func_0209fd2c();
    extern void **gCurrentMap;
    void *base;
    s16 a;
    s16 b;

    if (CanJoinUnitAtCursor() == 0) {
        return 2;
    }
    if (CanLoadUnitAtCursor() == 0) {
        return 2;
    }
    FillMapLayer(-1);
    base = *gCurrentMap;
    a = M2C_FIELD(base, s16 *, 0x52DE);
    b = M2C_FIELD(base, s16 *, 0x52DC);
    M2C_FIELD(M2C_FIELD((s8 *)base + a * 4, u8 **, 0x52E8), u8 *, b) = 0;
    if (func_0209fd2c() != 0) {
        return 0;
    }
    return 2;
}

s32 func_020c61a4(void) {
    s32 CanJoinUnitAtCursor();
    s32 CanLoadUnitAtCursor();
    M2C_UNK FillMapLayer(s32);
    s32 func_0209ff34();
    extern void **gCurrentMap;
    void *base;
    s16 a;
    s16 b;

    if (CanJoinUnitAtCursor() == 0) {
        return 2;
    }
    if (CanLoadUnitAtCursor() == 0) {
        return 2;
    }
    FillMapLayer(-1);
    base = *gCurrentMap;
    a = M2C_FIELD(base, s16 *, 0x52DE);
    b = M2C_FIELD(base, s16 *, 0x52DC);
    M2C_FIELD(M2C_FIELD((s8 *)base + a * 4, u8 **, 0x52E8), u8 *, b) = 0;
    if (func_0209ff34() != 0) {
        return 0;
    }
    return 2;
}

/* Returns 0 on success, 2 if the attempted move/attack is blocked. */
s32 func_020c6214(void) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c09[], gUnitMinAttackRange[];
    s32 GetHeldDirection(s32);
    s32 IsMobileIndirectUnitKind(s32);
    s32 func_0209f990(void);
    s32 FillMapLayer(s32);
    void func_01ffc368(s32, s32, void *);
    void *base;
    s32 x, y;

    if (GetHeldDirection(0) != 0 || GetHeldDirection(1) != 0) {
        return 2;
    }
    base = *gCurrentMap;
    y = M2C_FIELD(base, s16 *, 0x52DE);
    x = M2C_FIELD(base, s16 *, 0x52DC);
    if (M2C_FIELD(base, u8 *, x + M2C_FIELD((u8 *)base + y * 2, u16 *, 0x3758)) != 0) {
        return 2;
    }
    if (x != M2C_FIELD(base, s16 *, 0x52D8) || y != M2C_FIELD(base, s16 *, 0x52DA)) {
        s32 id = ((UnkStruct_020C5D0C *)M2C_FIELD(base, void **, 0x52D0))->unk0;
        if (data_ov000_021b5c09[id * 0x70] != 1 && IsMobileIndirectUnitKind(id) == 0) {
            return 2;
        }
    }
    if (gUnitMinAttackRange[((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap, void **, 0x52D0))->unk0 * 0x70] == 0) {
        return 2;
    }
    FillMapLayer(-1);
    base = *gCurrentMap;
    func_01ffc368(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), M2C_FIELD(base, void **, 0x52D0));
    if (func_0209f990() != 0) {
        return 0;
    }
    return 2;
}

s32 func_020c680c(void) {
    s32 func_020c67bc();
    extern void **gCurrentMap;

    switch (((UnkStruct_020C5D0C *) M2C_FIELD(*gCurrentMap, u8 **, 0x52D0))->unk0) {
    case 0x16:
        return func_020c67bc();
    }
    return 2;
}

s32 func_020c684c(void) {
 s32 CanLoadUnitAtCursor(); extern void **gCurrentMap;
 if (!CanJoinUnitAtCursor()) return 2;
 if (!CanLoadUnitAtCursor()) return 2;
 if (M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u16 *,4)&0x20) return 0;
 return 2;
}

s32 func_020c689c(void) {
    s32 func_020c684c();
    extern void **gCurrentMap;

    switch (((UnkStruct_020C5D0C *) M2C_FIELD(*gCurrentMap, u8 **, 0x52D0))->unk0) {
    case 0x16:
        return func_020c684c();
    }
    return 2;
}

s32 func_020c68dc(void) {
 extern void **gCurrentMap;
 void *base=*gCurrentMap;
 UnkStruct_020C5D0C *p;
 if (M2C_FIELD(base,u8 *,0x5156)==0 && M2C_FIELD(base,u8 *,0x5158)!=2) return 2;
 p=M2C_FIELD(base,UnkStruct_020C5D0C **,0x52D0);
 if(p->unk0!=5) return 2;
 if(M2C_FIELD(base,s16 *,0x52DC)!=M2C_FIELD(base,s16 *,0x52D8) || M2C_FIELD(base,s16 *,0x52DE)!=M2C_FIELD(base,s16 *,0x52DA)) return 2;
 if (p->unk6_7) return 0;
 return 2;
}

void func_020c6968(void) {
    M2C_UNK func_020c0adc();
    M2C_UNK func_020c757c();
    M2C_UNK func_020c0784();
    func_020c0adc();
    func_020c0784();
    func_020c757c();
}

void func_020c697c(void) {
    extern M2C_UNK data_0212a6c4;
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    CreateSpriteFromClass(&data_0212a6c4, 7);
}

void func_020c69a0(void) {
    M2C_UNK func_020d464c();
    M2C_UNK func_ov000_02171028();
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    func_ov000_02171028();
}

void func_020c69b8(void) {
    M2C_UNK func_ov000_0217242c();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_0217242c();
}

void func_020c69c8(void) {
    M2C_UNK func_ov000_02171750();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_02171750();
}

void func_020c69d8(void) {
    M2C_UNK func_020cbfe4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020cbfe4();
}

void func_020c69e8(void) {
    M2C_UNK func_020cc08c();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020cc08c();
}

void func_020c69f8(void) {
    M2C_UNK func_ov000_021707c0();
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    func_ov000_021707c0();
}

void func_020c6a10(void) {
    M2C_UNK func_020844f8();
    M2C_UNK EndPlayerTurn();
    extern u8 gBattleEndState;
    func_020c0784();
    EndPlayerTurn();
    if (gBattleEndState == 0) {
        return;
    }
    func_020844f8();
}

void func_020c6a38(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212a714;
    func_020c0784();
    CreateSpriteFromClass(&data_0212a714, 7);
}

void func_020c6a54(void) {
    M2C_UNK func_020b4cf4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020b4cf4();
}

void func_020c6a64(void) {
    M2C_UNK func_020b4d24();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020b4d24();
}

/* Confirm the pending directional action: drop the cursor UI, and when no cursor
 * direction is held send battle command 2; otherwise send command 8 with each
 * held direction resolved against the cursor tile. */
void ConfirmHeldDirectionCommand(void) {
    M2C_UNK func_020d468c();
    M2C_UNK func_020c0784();
    M2C_UNK DeleteDirectionMarkerSprites();
    s32 GetHeldDirection(s32);
    s32 ResolveHeldDirection(s32, s32, s32);
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;
    void *base;
    s32 dir0, dir1;

    func_020d468c();
    func_020c0784();
    if (!GetHeldDirection(0) && !GetHeldDirection(1)) {
        SetBattleCommand(2, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), 0, 0);
        return;
    }
    DeleteDirectionMarkerSprites();
    base = *gCurrentMap;
    dir0 = ResolveHeldDirection(M2C_FIELD(base, s16 *, MAP_CURSOR_X), M2C_FIELD(base, s16 *, MAP_CURSOR_Y), 0);
    dir1 = ResolveHeldDirection(M2C_FIELD(base, s16 *, MAP_CURSOR_X), M2C_FIELD(base, s16 *, MAP_CURSOR_Y), 1);
    SetBattleCommand(8, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), (u8)dir0, (u8)dir1);
}

void func_020c6b30(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK SetBattleCommand(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 SetBattleCommand(3,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6b68(void) {
    M2C_UNK func_020bbba4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020bbba4();
}

void func_020c6b78(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK SetBattleCommand(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 SetBattleCommand(7,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6bb0(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK SetBattleCommand(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 SetBattleCommand(9,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6be8(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK SetBattleCommand(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 SetBattleCommand(6,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6c20(void) {
    M2C_UNK func_020cb018(M2C_UNK);
    M2C_UNK func_020d4704();
    func_020cb018(0);
    func_020c0784();
    func_020d4704();
}

void func_020c6c38(void) {
    func_020cb018(1);
    func_020c0784();
    func_020d4704();
}

void func_020c6c50(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_021696d4(); M2C_UNK SelectCarriedUnit(void *,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784(); func_ov000_021696d4();
 SelectCarriedUnit(M2C_FIELD(*gCurrentMap,void **,0x52D0),0,0);
}

void func_020c6c88(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_021696d4(); M2C_UNK SelectCarriedUnit(void *,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784(); func_ov000_021696d4();
 SelectCarriedUnit(M2C_FIELD(*gCurrentMap,void **,0x52D0),1,0);
}

void func_020c6cc0(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK SetBattleCommand(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 SetBattleCommand(0x17,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

