/* 23 functions from 0x020CAB8C to 0x020CBACC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
/* A map unit record. tail[4] and tail[5] (offsets 12,13) hold the indices of
 * the units a transport is carrying; the number of slots is the unit kind's
 * cargo count (gUnitKindCargoCount[kind]). */
typedef struct UnitCB9 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 hp; u8 tail[6]; } UnitCB9;
typedef struct UnitHealthCB { u8 pad[6]; u16 health:7; u16 flags:9; } UnitHealthCB;
extern u8 gMapCursorDirs[][4];

void func_020cab8c(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b4a4;
    CreateSpriteFromClass(&data_0212b4a4, 7);
}

#pragma optimization_level 4
/* Find the enabled cursor direction that points to the given tile. */
s32 FindMapCursorOptionAt(s32 tileX, s32 tileY, s32 optionMask) {
    extern void **gCurrentMap;
    s32 direction = 0;
    void *map;

    do {
        if (optionMask & gMapCursorDirs[direction][MAP_CURSOR_DIR_MASK]) {
            map = *gCurrentMap;
            if (tileX == M2C_FIELD(map, s16 *, MAP_CURSOR_X) + (s8)gMapCursorDirs[direction][MAP_CURSOR_DIR_DX]
                && tileY == M2C_FIELD(map, s16 *, MAP_CURSOR_Y) + (s8)gMapCursorDirs[direction][MAP_CURSOR_DIR_DY]) {
                return direction;
            }
        }
        direction++;
    } while (direction < MAP_CURSOR_OPTION_COUNT);
    return -1;
}
/* Return the cursor option after `option` (wrapping through the four
 * MAP_CURSOR_OPTION_* slots) whose MAP_DIR_* bit is set in `optionMask`. */
s32 NextMapCursorOption(s32 option, s32 optionMask) {
    do {
        option = (option + 1) & 3;
    } while (!(optionMask & gMapCursorDirs[option][MAP_CURSOR_DIR_MASK]));
    return option;
}

/* Step the map cursor's selected option one direction back (wrapping around the
 * four directions) to the previous one the option mask allows. */
s32 PrevMapCursorOption(s32 selected, s32 optionMask) {
    do {
        selected = (selected - 1) & (MAP_CURSOR_OPTION_COUNT - 1);
    } while (!(optionMask & gMapCursorDirs[selected][MAP_CURSOR_DIR_MASK]));
    return selected;
}

/* Starts choosing the direction to drop one of the transport's carried units:
 * computes the directions the carried unit could be dropped into from the
 * cursor tile, selects the cursor layer, clears the old option cells and hides
 * the unit cursor, then arms the direction mask and steps the chosen option to
 * the first available direction.  MAP_OPTION_CARGO_SLOT picks which carried
 * unit the drop acts on. */
void BeginCargoDrop(void *option) {
    M2C_UNK FillMapLayer(M2C_UNK);
    M2C_UNK SelectMapLayer(void *);
    M2C_UNK SetMapCursorVisible(M2C_UNK);
    s32 GetUnitMoveDirections(s16, s16, u8);
    M2C_UNK ClearMapCursorOptionCells(s16, s16, s32);
    extern void **gCurrentMap;
    s32 mask;
    void *map;

    map = *gCurrentMap;
    mask = GetUnitMoveDirections(
        M2C_FIELD(map, s16 *, MAP_CURSOR_X),
        M2C_FIELD(map, s16 *, MAP_CURSOR_Y),
        M2C_FIELD((M2C_FIELD(map, s32 *, MAP_CURSOR_UNIT) + M2C_FIELD(option, s16 *, MAP_OPTION_CARGO_SLOT)), u8 *, MAP_UNIT_FIRST_CARRIED));
    SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
    FillMapLayer(-1);
    map = *gCurrentMap;
    ClearMapCursorOptionCells(M2C_FIELD(map, s16 *, MAP_CURSOR_X), M2C_FIELD(map, s16 *, MAP_CURSOR_Y), mask);
    SetMapCursorVisible(0);
    M2C_FIELD(option, s16 *, MAP_OPTION_DIR_MASK) = mask;
    M2C_FIELD(option, s16 *, MAP_OPTION_SELECTED) = MAP_CURSOR_OPTION_LEFT;
    M2C_FIELD(option, s16 *, MAP_OPTION_SELECTED) = NextMapCursorOption(M2C_FIELD(option, s16 *, MAP_OPTION_SELECTED), mask);
}

void func_020cad00(s32 arg0) {
    M2C_UNK PlaySoundAtTile(M2C_UNK);
    if ((arg0 != 1) && (arg0 != 2)) {
        return;
    }
    PlaySoundAtTile(0x7C);
}

/* One frame of the map's directional cursor: cycle the selected option among
 * the available ones (right/down steps forward, left/up back), move the target
 * cursor onto that option's neighbour tile, and return the confirm (0x10) or
 * cancel (0x20) key action. */
s32 UpdateMapCursorOption(s32 *option, s32 optionMask) {
    s32 GetCursorCycleKey(void);
    s32 NextMapCursorOption(s32, s32);
    s32 PrevMapCursorOption(s32, s32);
    void func_020bda88(s32 *, s32);
    void PlaySoundEffect(s32);
    void MapCursor_StepTowardTarget(s32);
    s32 GetKeyActionFlags(void);
    s32 GetMapCursorOptionTouchAction(s32);
    extern void **gCurrentMap;
    extern s8 gMapCursorDirDX[];
    extern s8 gMapCursorDirDY[];
    s32 selected;
    s32 previous;
    s32 keys;
    void *map;

    selected = *option;
    previous = *option;
    keys = GetCursorCycleKey();
    if (keys & 8) {
        selected = NextMapCursorOption(selected, optionMask);
    }
    if (keys & 4) {
        selected = PrevMapCursorOption(selected, optionMask);
    }
    func_020bda88(&selected, optionMask);
    if (selected != previous) {
        *option = selected;
        PlaySoundEffect(0x1001A);
    }
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X) = (s16)(M2C_FIELD(map, s16 *, MAP_CURSOR_X) + gMapCursorDirDX[selected * 4]);
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y) = (s16)(M2C_FIELD(map, s16 *, MAP_CURSOR_Y) + gMapCursorDirDY[selected * 4]);
    MapCursor_StepTowardTarget(1);
    keys = GetKeyActionFlags();
    keys = keys | GetMapCursorOptionTouchAction(optionMask);
    if (keys & 0x20) {
        return 0x20;
    }
    if (keys & 0x10) {
        return 0x10;
    }
    return 0;
}

void func_020cae2c(void *p){
extern void **gCurrentMap; extern s32 gMapCursorOptionValue;
M2C_UNK ReleaseMapViewHold();M2C_UNK OpenMapActionMenu();void DeleteSpriteObject(void *);void Sprite_ResumeAnimation(void *);void SetHeldDirection(u8,u8);
s32 mask=M2C_FIELD(p,s16 *,0x6c); s32 a=M2C_FIELD(p,s16 *,0x6e),flags; s16 selector; s32 index;u8 *units;void *map;u8 *unit;
flags=UpdateMapCursorOption(&a,mask);
M2C_FIELD(p,s16 *,0x6e)=a;
if(flags&32){
ReleaseMapViewHold();OpenMapActionMenu();
map=*gCurrentMap;M2C_FIELD(map,s16 *,0x52c2)=M2C_FIELD(map,s16 *,0x52d8);
map=*gCurrentMap;M2C_FIELD(map,s16 *,0x52c4)=M2C_FIELD(map,s16 *,0x52da);
DeleteSpriteObject(p);return;
}
if((flags&16)==0)return;
gMapCursorOptionValue=M2C_FIELD(p,s16 *,0x6e);
map=*gCurrentMap;selector=M2C_FIELD(p,s16 *,0x70);
unit=(u8*)M2C_FIELD(map,void **,0x52d0)+selector;
units=(u8*)map+0x59a4;
index=(s32)unit[12]*14;
SetHeldDirection((u8)selector,(u8)(M2C_FIELD(p,s16 *,0x6e)+1));
map=*gCurrentMap;
((void(*)(s32,s32,s32))func_020cad00)(((u32)(units[index]<<26)>>26),M2C_FIELD(map,s16 *,0x52dc),M2C_FIELD(map,s16 *,0x52de));
Sprite_ResumeAnimation(p);
}

/* Confirms the cursor's attack option: when neither attack target is available it
 * snaps the target cursor back onto the cursor tile and re-arms the option; otherwise
 * it issues battle command 8 (attack) with the direction chosen for each target. */
void ConfirmAttackCommand(void *option) {
    M2C_UNK ReleaseMapViewHold();
    s32 CanConfirmFirstCargoDrop();
    s32 CanConfirmSecondCargoDrop();
    M2C_UNK OpenMapActionMenu();
    M2C_UNK func_020c9580(u8);
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteDirectionMarkerSprites();
    u8 ResolveHeldDirection(s16, s16, s32);
    M2C_UNK SetBattleCommand(s32, u8, u8, u8);
    extern void **gCurrentMap;
    void *map;
    s32 dir0, dir1;

    ReleaseMapViewHold();
    if ((CanConfirmFirstCargoDrop() == 0) || (CanConfirmSecondCargoDrop() == 0)) {
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X);
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y);
        func_020c9580((u8) M2C_FIELD(option, s16 *, 0x70));
        OpenMapActionMenu();
        return;
    }
    SetMapCommandPending();
    DeleteDirectionMarkerSprites();
    map = *gCurrentMap;
    dir0 = ResolveHeldDirection(M2C_FIELD(map, s16 *, MAP_CURSOR_X), M2C_FIELD(map, s16 *, MAP_CURSOR_Y), 0);
    dir1 = ResolveHeldDirection(M2C_FIELD(map, s16 *, MAP_CURSOR_X), M2C_FIELD(map, s16 *, MAP_CURSOR_Y), 1);
    SetBattleCommand(8, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), (u8) dir0, (u8) dir1);
}

void func_020cb00c(void) {
    M2C_UNK func_0207a768();
    func_0207a768();
}

/* Spawn the map's directional option cursor on the default layer and record which
 * carried-unit slot its confirm acts on. */
void CreateMapCursorOption(s16 cargoSlot) {
    extern M2C_UNK gMapCursorOptionClass;
    M2C_FIELD(CreateSpriteFromClass(&gMapCursorOptionClass, 7), s16 *, MAP_OPTION_CARGO_SLOT) = cargoSlot;
}

/* Refills a unit's ammo one point at a time up to its kind's maximum, accumulating
   the cost of each point and returning the total.  When pay is set each point is
   paid for out of the current player's funds (stopping when they run short); when it
   is clear the per-point value is just the unit's health bracket. */
s32 RefillUnitAmmo(void *unit,s32 pay){
s32 Divide(s32,s32); M2C_UNK PayPlayerFunds(s32,u16);
extern void **gCurrentMap; extern u16 data_ov000_021b5c02[];extern M2C_UNK gUnitKindStats;
u8 *tab;s32 total=0;u16 cost;u32 health=(u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_HEALTH)<<25);u16 ammoWord,player;void *map;
if(pay){health >>=25;cost=*(u16 *)((u8 *)data_ov000_021b5c02+((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)*UNIT_KIND_STATS_SIZE)*(health?Divide(health-1,10)+1:total);
}else {health >>=25;cost=health?Divide(health-1,10)+1:total;}
tab=(u8 *)&gUnitKindStats;
loop:
if(((u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO)<<21)>>28)!=tab[((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_AMMO]){
if(pay){map=*gCurrentMap;player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);if(M2C_FIELD((u8*)map+player*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF)>=(s32)cost){PayPlayerFunds(player,cost);goto update;}}
else{update:ammoWord=M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO);total+=cost;M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO)=(ammoWord&~0x780)|((u32)((u16)(((u32)(ammoWord<<21)>>28)+1)<<28)>>21);goto loop;}}
return total;}

/* Refill a unit's fuel one point at a time until it reaches its kind's
   maximum, returning the fuel added.  Each point costs the owning player an
   amount that grows with the unit's health (one per ten HP); when pay is set
   the refill stops as soon as the player cannot afford the next unit of fuel. */
s32 RefillUnitFuel(void *unit, s32 pay) {
    s32 Divide(s32, M2C_UNK);
    M2C_UNK PayPlayerFunds(s32, u16);
    extern void **gCurrentMap;
    extern M2C_UNK gUnitKindStats;
    u8 *tab;
    s32 total;
    u32 health;
    u16 cost;
    u16 player;
    u8 fuel;
    void *map;

    total = 0;
    health = (u32) (M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 0x19) >> 0x19;
    cost = health ? (Divide(health - 1, 0xA) + 1) : total;
    tab = (u8 *) &gUnitKindStats;
loop_4:
    if (((u32) (M2C_FIELD(unit, u8 *, MAP_UNIT_FUEL) << 0x19) >> 0x19) != tab[((u32) (M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 0x1A) >> 0x1A) * 0x70 + UNIT_KIND_STATS_FUEL]) {
        if (pay != 0) {
            map = *gCurrentMap;
            player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
            if ((s32) M2C_FIELD(((player * 0x8C) + (s32) map), s32 *, PLAYER_FUNDS_OFF) >= (s32) cost) {
                PayPlayerFunds(player, cost);
                goto block_8;
            }
        } else {
block_8:
            fuel = M2C_FIELD(unit, u8 *, MAP_UNIT_FUEL);
            total += cost;
            M2C_FIELD(unit, u8 *, MAP_UNIT_FUEL) = (u8) ((fuel & ~0x7F) | ((u8) (((u32) (fuel << 0x19) >> 0x19) + 1) & 0x7F));
            goto loop_4;
        }
    }
    return total;
}

#pragma opt_common_subs on
/* Add up to `levels` veteran levels to a unit, each worth 10 points of health
 * and capped at level 10 (100 points). When charge is set each level costs the
 * owning player the unit kind's cost; the total charged is returned. */
s32 LevelUpUnit(void *unit,s32 levels,s32 charge){
s32 GetUnitOwner(void);
s32 GetUnitBuildCost(s32,u32);
s32 Divide(s32,s32);
M2C_UNK PayPlayerFunds(s32,u16);
extern void **gCurrentMap;
s32 owner,totalCost,health,level,ownerOffset;u16 cost,attr;
owner=GetUnitOwner();totalCost=0;
cost=GetUnitBuildCost(owner,(u32)(M2C_FIELD(unit,u8*,0)<<26)>>26);
if(levels){ownerOffset=owner*140;
do{
health=((UnitHealthCB*)unit)->health;
if(!health)level=0;else level=Divide(health-1,10)+1;
if(level==10)break;
if(charge){
if(M2C_FIELD(ownerOffset+(s32)*gCurrentMap,s32*,0x67a4)<(s32)cost)break;
PayPlayerFunds(owner,cost);totalCost+=cost;
}
attr=M2C_FIELD(unit,u16*,6);
M2C_FIELD(unit,u16*,6)=(attr&~127)|((u16)(((u32)(attr<<25)>>25)+10)&127);
if(((UnitHealthCB*)unit)->health>100)((UnitHealthCB*)unit)->health=100;
}while(--levels);
}
health=((UnitHealthCB*)unit)->health;
if(!health)level=0;else level=Divide(health-1,10)+1;
((UnitHealthCB*)unit)->health=(u16)(level*10);
return totalCost;
}
/* Returns true when the cell (x, y) has a visible unit id belonging to the
 * current player's unit group and that unit is a supply unit (rig or carrier).
 * The id read at the cell indexes MAP_UNIT_RECORDS. */
s32 IsAllySupplyUnitAtCell(s32 x,s32 y){extern void **gCurrentMap;s32 IsSupplyUnitKind(void *);u8 *base=*gCurrentMap;u8 *units=base+MAP_UNIT_RECORDS;u8 *unit=units+(s16)base[x+((u16 *)(base+MAP_ROW_OFFSETS))[y]]*MAP_UNIT_STRIDE;s32 unitId=unit?(unit-units)/MAP_UNIT_STRIDE:0;if(M2C_FIELD(base,u16 *,MAP_UNIT_GROUP_BASE)==(unitId&MAP_UNIT_OWNER_MASK) && IsSupplyUnitKind(unit))return 1;return 0;}

/* Whether unit `unit` can be supplied where it stands: its kind must be
 * supplyable and one of its four orthogonal neighbours inside the map must hold
 * a friendly supply unit. */
s32 CanBeSupplied(u8 *unit) {
    extern u8 gUnitKindSupplyFlag[];
    extern void **gCurrentMap;
    if (!gUnitKindSupplyFlag[((u32)(unit[MAP_UNIT_KIND] << 26) >> 26) * UNIT_KIND_STATS_SIZE]) return 0;
    if (unit[MAP_UNIT_X] && IsAllySupplyUnitAtCell((s16)(unit[MAP_UNIT_X] - 1), unit[MAP_UNIT_Y])) return 1;
    if (unit[MAP_UNIT_Y] && IsAllySupplyUnitAtCell(unit[MAP_UNIT_X], (s16)(unit[MAP_UNIT_Y] - 1))) return 1;
    if (unit[MAP_UNIT_X] < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) - 1 && IsAllySupplyUnitAtCell((s16)(unit[MAP_UNIT_X] + 1), unit[MAP_UNIT_Y])) return 1;
    if (unit[MAP_UNIT_Y] < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT) - 1 && IsAllySupplyUnitAtCell(unit[MAP_UNIT_X], (s16)(unit[MAP_UNIT_Y] + 1))) return 1;
    return 0;
}

#pragma opt_propagation off
/* Mark a transport unit's cargo on the map: for every carried unit (its index
 * kept in the record's last two bytes) add the cargo's cost and health value to
 * the running totals, and for a kind-21 transport also total the funds of
 * levelling that cargo up. Highlight the tile with mode 1 when the cargo has
 * value, mode 2 when it only has cost, and nothing when it is empty. */
s32 MarkTransportCargo(u8 *unit){
u8 func_020c98d8(u8,u8,s32);s32 func_020a7558(void *);s32 LevelUpUnit(void *,s32,s32);
extern void **gCurrentMap;extern M2C_UNK gUnitKindStats;extern u8 gUnitKindCargoCount[];
u8 cargo;u8 *records;u8 slot;u8 *cursor;u8 cargoIndex;s32 cost; s32 value;cost=0;value=0;slot=0;
if((u32)slot<(u32)gUnitKindCargoCount[((u32)(unit[0]<<26)>>26)*112]){
do{cursor=unit+slot;cargoIndex=cursor[12];if(cargoIndex){
cost+=RefillUnitAmmo((u8 *)*gCurrentMap+0x59a4+cargoIndex*14,0);
cost+=RefillUnitFuel((u8 *)*gCurrentMap+0x59a4+cursor[12]*14,0);
if(((u32)(unit[0]<<26)>>26)==21){cargo=cursor[12];records=(u8 *)*gCurrentMap+0x59a4;value+=LevelUpUnit(records+cargo*14,func_020a7558(unit),1);}
}slot++;}while(slot<((u8 *)&gUnitKindStats)[((u32)(unit[0]<<26)>>26)*112+0x60]);}
if(value)return func_020c98d8(unit[1],unit[2],1);
if(!cost)return 0;
return func_020c98d8(unit[1],unit[2],2);
}
#pragma opt_propagation reset
/* Refills a supplied unit: tops up its ammo (unless its kind can supply itself)
 * and its fuel, then marks its tile with the refill marker when anything was
 * added.  Returns whether anything was refilled. */
u8 RefillSuppliedUnit(void *unit) {
s32 UnitKindCanSupply(u32);
u8 func_020c98d8(u8,u8,s32);
s32 RefillUnitAmmo(void *,s32);
s32 RefillUnitFuel(void *,s32);
s32 added=0;
if(UnitKindCanSupply((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)==0) added+=RefillUnitAmmo(unit,0);
added+=RefillUnitFuel(unit,0);
if(added==0) return added;
return func_020c98d8(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y),2);
}

#pragma opt_instruction_scheduling off
/* Scans the four tiles around the map cursor and builds the MAP_DIR_* mask of
 * the directions that hold a unit this one can supply, then restarts the
 * option's direction scan. */
void FindSupplyTargetDirections(void *option) {
    s32 IsSupplyTargetAt(s32, s32);
    extern s32 gMapCursorOptionValue;
    extern void **gCurrentMap;
    extern u8 gMapCursorDirs[][4];
    u16 i = 0;
    gMapCursorOptionValue = 0;
    do {
        void *map = *gCurrentMap;
        s32 found = IsSupplyTargetAt(M2C_FIELD(map, s16 *, MAP_CURSOR_X) + (s8) gMapCursorDirs[i][2], M2C_FIELD(map, s16 *, MAP_CURSOR_Y) + (s8) gMapCursorDirs[i][3]);
        {
            u32 mask = gMapCursorDirs[i][0];
            gMapCursorOptionValue = (u32) gMapCursorOptionValue | mask * (u32) found;
        }
        i++;
    } while (i < 4);
    M2C_FIELD(option, s16 *, 0x34) = 0;
}
#pragma opt_instruction_scheduling reset
void func_020cb78c(void *arg0){
void DeleteSpriteObject(void *);void BattleUpdateUnitCursor(void);s32 IsMapActionEffectActive(void);M2C_UNK SetMapCommandPending();M2C_UNK SetBattleCommand(s32,u8,u8,u8);
extern s32 gMapCursorOptionValue;extern void **gCurrentMap;
s32 offset; s16 i;u8 *m;u8 *q;void *p;
if(IsMapActionEffectActive())return;
loop:
i=M2C_FIELD(arg0,s16 *,0x34);
if(i>=4){
if(!M2C_FIELD(arg0,s16 *,0x36)){
p=*gCurrentMap;M2C_FIELD(p,s16 *,0x52c2)=M2C_FIELD(p,s16 *,0x52dc);
p=*gCurrentMap;M2C_FIELD(p,s16 *,0x52c4)=M2C_FIELD(p,s16 *,0x52de);}
DeleteSpriteObject(arg0);BattleUpdateUnitCursor();
if(!M2C_FIELD(arg0,s16 *,0x36))SetBattleCommand(6,M2C_FIELD(*gCurrentMap,u8 *,0x52d4),0,0);
SetMapCommandPending();
return;
}
offset = i * 4;
if (gMapCursorOptionValue & ((u8 *)gMapCursorDirs)[offset]) {
    m = *gCurrentMap;
    q = (u8 *)gMapCursorDirs + offset;
{
    s32 row = M2C_FIELD(m, s16 *, 0x52de) + (s8)q[3];
    u8 *mapColumn = m + M2C_FIELD(m, s16 *, 0x52dc);
    u16 rowOffset = M2C_FIELD(m + row * 2, u16 *, 0x3758);
    u8 unitId = M2C_FIELD(rowOffset + ((s8)q[2] + mapColumn), u8 *, 0x508);
    RefillSuppliedUnit((m + 0x59a4) + 14 * unitId);
}
M2C_FIELD(arg0,s16 *,0x34)++;
}else{M2C_FIELD(arg0,s16 *,0x34)++;}goto loop;
}

/* Open the supply overlay: create its animated sprite from the overlay script
 * (which takes the map-view hold, scans the tiles around the cursor for units
 * that can be resupplied, refills them, then releases the hold).  `complete`
 * says whether finishing the overlay also completes the supply action. */
void CreateSupplyOverlay(s32 complete) {
    extern M2C_UNK gSupplyOverlayScript;
    void *overlay = CreateSpriteFromClass(&gSupplyOverlayScript, 7);

    if (complete) {
        M2C_FIELD(overlay, s16 *, SUPPLY_OVERLAY_COMPLETE) = 0;
    } else {
        M2C_FIELD(overlay, s16 *, SUPPLY_OVERLAY_COMPLETE) = 1;
    }
}

void func_020cb8f8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x50) = 1;
}

/* Stepping overlay task: from the saved cursor it scans the current player's units
 * and finds the next one worth marking - a unit whose terrain allows its kind and
 * whose cargo has a cost or a value. It highlights that unit's tile (mode 1 when the
 * cargo has value, 2 when only cost) and saves the next cursor; at the end of the
 * unit list the task retires itself. */
u8 func_020c98d8(u8, u8, s32);
void Sprite_ResumeAnimation(void *);
void MarkUnitCargoTiles(void *state){
extern void **gCurrentMap;extern M2C_UNK gUnitKindStats;
u16 i; s32 a,b; UnitCB9 *unit; s32 n;u8 *map;
if(IsMapActionEffectActive(state))return;
for(i=M2C_FIELD(state,u16 *,0x50);i<51;i++){
map=*gCurrentMap;
unit=(UnitCB9 *)(map+MAP_UNIT_RECORDS+(M2C_FIELD(map,u16 *,0x52a8)+i)*MAP_UNIT_STRIDE);
if(!unit->kind || (unit->flags&8))continue;
a=0;b=0;
if(IsPropertyOwnedByTeam(M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER),unit->x,unit->y)){
s32 kind=unit->kind; s32 x; s32 y; s32 terrain; s8 *table;
map=*gCurrentMap; x=unit->x;y=unit->y;
terrain=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_TERRAIN)&31;
table=M2C_FIELD((u8 *)&gUnitKindStats+kind*112,s8 **,0x58);
if(table[terrain]){
if(!UnitKindCanSupply(kind)){
a+=RefillUnitAmmo(unit,0);
}
a+=RefillUnitFuel(unit,0);
b+=LevelUpUnit(unit,func_020a7558(unit),1);
}
}
n=GetUnitVeteranLevelBonus(unit,unit->x,unit->y);
if(n)b+=LevelUpUnit(unit,n,1);
if(a||b){
if(b)func_020c98d8(unit->x,unit->y,1);
else func_020c98d8(unit->x,unit->y,2);
M2C_FIELD(state,u16 *,0x50)=i+1;
break;
}
}
if(i==51)Sprite_ResumeAnimation(state);
}

