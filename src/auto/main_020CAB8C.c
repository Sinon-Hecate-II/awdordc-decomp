/* 23 functions from 0x020CAB8C to 0x020CBACC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
/* A map unit record. tail[4] and tail[5] (offsets 12,13) hold the indices of
 * the units a transport is carrying; the number of slots is the unit kind's
 * cargo count (gUnitKindCargoCount[kind]). */
typedef struct UnitCB9 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 hp; u8 tail[6]; } UnitCB9;
typedef struct UnitHealthCB { u8 pad[6]; u16 health:7; u16 flags:9; } UnitHealthCB;
extern u8 data_0212b1b8[][4];

void func_020cab8c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b4a4;
    func_01ffa3dc(&data_0212b4a4, 7);
}

#pragma optimization_level 4
s32 func_020caba4(s32 a,s32 b,s32 c){
 extern void **gCurrentMap;
 s32 i=0;void *p;
 do{
 if(c&data_0212b1b8[i][0]){
 p=*gCurrentMap;
 if(a==M2C_FIELD(p,s16 *,0x52dc)+(s8)data_0212b1b8[i][2] && b==M2C_FIELD(p,s16 *,0x52de)+(s8)data_0212b1b8[i][3])return i;
 } i++;
 }while(i<4);return -1;
}
s32 func_020cac1c(s32 a,s32 b){do{a=(a+1)&3;}while(!(b&data_0212b1b8[a][0]));return a;}

s32 func_020cac3c(s32 a,s32 b){do{a=(a-1)&3;}while(!(b&data_0212b1b8[a][0]));return a;}

void func_020cac5c(void *arg0) {
 M2C_UNK FillMapLayer(M2C_UNK); M2C_UNK SelectMapLayer(void *); M2C_UNK func_0207a748(M2C_UNK);
 s32 func_020ba1fc(s16,s16,u8); M2C_UNK func_020cdf30(s16,s16,s32);
 extern void **gCurrentMap;
 s32 n;void *p;
 p=*gCurrentMap;
 n=func_020ba1fc(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),M2C_FIELD((M2C_FIELD(p,s32 *,0x52d0)+M2C_FIELD(arg0,s16 *,0x70)),u8 *,0xc));
 SelectMapLayer((u8 *)*gCurrentMap+0x1e30);FillMapLayer(-1);
 p=*gCurrentMap;func_020cdf30(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),n);func_0207a748(0);
 M2C_FIELD(arg0,s16 *,0x6c)=n;M2C_FIELD(arg0,s16 *,0x6e)=3;
 M2C_FIELD(arg0,s16 *,0x6e)=func_020cac1c(M2C_FIELD(arg0,s16 *,0x6e),n);
}

void func_020cad00(s32 arg0) {
    M2C_UNK PlaySoundAtTile(M2C_UNK);
    if ((arg0 != 1) && (arg0 != 2)) {
        return;
    }
    PlaySoundAtTile(0x7C);
}

s32 func_020cad1c(s32 *arg0, s32 arg1) {
    s32 func_020bcbd8(void);
    s32 func_020cac1c(s32, s32);
    s32 func_020cac3c(s32, s32);
    void func_020bda88(s32 *, s32);
    void PlaySoundEffect(s32);
    void MoveMapCursorToTarget(s32);
    s32 GetKeyActionFlags(void);
    s32 func_020bdbf4(s32);
    extern void **gCurrentMap;
    extern s8 data_0212b1ba[];
    extern s8 data_0212b1bb[];
    s32 sp0;
    s32 old;
    s32 result_r6;
    void *map;

    sp0 = *arg0;
    old = *arg0;
    result_r6 = func_020bcbd8();
    if (result_r6 & 8) {
        sp0 = func_020cac1c(sp0, arg1);
    }
    if (result_r6 & 4) {
        sp0 = func_020cac3c(sp0, arg1);
    }
    func_020bda88(&sp0, arg1);
    if (sp0 != old) {
        *arg0 = sp0;
        PlaySoundEffect(0x1001A);
    }
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, 0x52C2) = (s16)(M2C_FIELD(map, s16 *, 0x52DC) + data_0212b1ba[sp0 * 4]);
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, 0x52C4) = (s16)(M2C_FIELD(map, s16 *, 0x52DE) + data_0212b1bb[sp0 * 4]);
    MoveMapCursorToTarget(1);
    result_r6 = GetKeyActionFlags();
    result_r6 = result_r6 | func_020bdbf4(arg1);
    if (result_r6 & 0x20) {
        return 0x20;
    }
    if (result_r6 & 0x10) {
        return 0x10;
    }
    return 0;
}

void func_020cae2c(void *p){
extern void **gCurrentMap; extern s32 data_0215be0c;
M2C_UNK func_020d472c();M2C_UNK func_020c75cc();void DeleteSpriteObject(void *);void func_01ffa6fc(void *);void func_020c93fc(u8,u8);
s32 mask=M2C_FIELD(p,s16 *,0x6c); s32 a=M2C_FIELD(p,s16 *,0x6e),flags; s16 selector; s32 index;u8 *units;void *map;u8 *unit;
flags=func_020cad1c(&a,mask);
M2C_FIELD(p,s16 *,0x6e)=a;
if(flags&32){
func_020d472c();func_020c75cc();
map=*gCurrentMap;M2C_FIELD(map,s16 *,0x52c2)=M2C_FIELD(map,s16 *,0x52d8);
map=*gCurrentMap;M2C_FIELD(map,s16 *,0x52c4)=M2C_FIELD(map,s16 *,0x52da);
DeleteSpriteObject(p);return;
}
if((flags&16)==0)return;
data_0215be0c=M2C_FIELD(p,s16 *,0x6e);
map=*gCurrentMap;selector=M2C_FIELD(p,s16 *,0x70);
unit=(u8*)M2C_FIELD(map,void **,0x52d0)+selector;
units=(u8*)map+0x59a4;
index=(s32)unit[12]*14;
func_020c93fc((u8)selector,(u8)(M2C_FIELD(p,s16 *,0x6e)+1));
map=*gCurrentMap;
((void(*)(s32,s32,s32))func_020cad00)(((u32)(units[index]<<26)>>26),M2C_FIELD(map,s16 *,0x52dc),M2C_FIELD(map,s16 *,0x52de));
func_01ffa6fc(p);
}

void func_020caf3c(void *arg0) {
    M2C_UNK func_020d472c();
    s32 func_020c6384();
    s32 func_020c6414();
    M2C_UNK func_020c75cc();
    M2C_UNK func_020c9580(u8);
    M2C_UNK func_020d468c();
    M2C_UNK func_020a15e4();
    u8 func_020c9440(s16, s16, s32);
    M2C_UNK func_ov000_02199f50(s32, u8, u8, u8);
    extern void **gCurrentMap;
    void *base;
    s32 a, b;

    func_020d472c();
    if ((func_020c6384() == 0) || (func_020c6414() == 0)) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
        func_020c9580((u8) M2C_FIELD(arg0, s16 *, 0x70));
        func_020c75cc();
        return;
    }
    func_020d468c();
    func_020a15e4();
    base = *gCurrentMap;
    a = func_020c9440(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), 0);
    b = func_020c9440(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), 1);
    func_ov000_02199f50(8, M2C_FIELD(*gCurrentMap, u8 *, 0x52D4), (u8) a, (u8) b);
}

void func_020cb00c(void) {
    M2C_UNK func_0207a768();
    func_0207a768();
}

void func_020cb018(s16 arg0) {
    extern M2C_UNK data_0212b374;
    M2C_FIELD(func_01ffa3dc(&data_0212b374, 7), s16 *, 0x70) = arg0;
}

/* Refills a unit's ammo one point at a time up to its kind's maximum, accumulating
   the cost of each point and returning the total.  When pay is set each point is
   paid for out of the current player's funds (stopping when they run short); when it
   is clear the per-point value is just the unit's health bracket. */
s32 RefillUnitAmmo(void *unit,s32 pay){
s32 Divide(s32,s32); M2C_UNK func_020d2b10(s32,u16);
extern void **gCurrentMap; extern u16 data_ov000_021b5c02[];extern M2C_UNK gUnitKindStats;
u8 *tab;s32 total=0;u16 cost;u32 health=(u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_HEALTH)<<25);u16 ammoWord,player;void *map;
if(pay){health >>=25;cost=*(u16 *)((u8 *)data_ov000_021b5c02+((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)*UNIT_KIND_STATS_SIZE)*(health?Divide(health-1,10)+1:total);
}else {health >>=25;cost=health?Divide(health-1,10)+1:total;}
tab=(u8 *)&gUnitKindStats;
loop:
if(((u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO)<<21)>>28)!=tab[((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_AMMO]){
if(pay){map=*gCurrentMap;player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);if(M2C_FIELD((u8*)map+player*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF)>=(s32)cost){func_020d2b10(player,cost);goto update;}}
else{update:ammoWord=M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO);total+=cost;M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO)=(ammoWord&~0x780)|((u32)((u16)(((u32)(ammoWord<<21)>>28)+1)<<28)>>21);goto loop;}}
return total;}

s32 RefillUnitFuel(void *arg0, s32 arg1) {
    s32 Divide(s32, M2C_UNK);
    M2C_UNK func_020d2b10(s32, u16);
    extern void **gCurrentMap;
    extern M2C_UNK gUnitKindStats;
    u8 *tab;
    s32 var_r7;
    u32 temp_r0;
    u16 temp_r8;
    u16 temp_r0_2;
    u8 temp_r1_2;
    void *temp_r1;

    var_r7 = 0;
    temp_r0 = (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
    temp_r8 = temp_r0 ? (Divide(temp_r0 - 1, 0xA) + 1) : var_r7;
    tab = (u8 *) &gUnitKindStats;
loop_4:
    if (((u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19) != tab[((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) * 0x70 + 0xE]) {
        if (arg1 != 0) {
            temp_r1 = *gCurrentMap;
            temp_r0_2 = M2C_FIELD(temp_r1, u16 *, 0x52A4);
            if ((s32) M2C_FIELD(((temp_r0_2 * 0x8C) + (s32) temp_r1), s32 *, 0x67A4) >= (s32) temp_r8) {
                func_020d2b10(temp_r0_2, temp_r8);
                goto block_8;
            }
        } else {
block_8:
            temp_r1_2 = M2C_FIELD(arg0, u8 *, 0xA);
            var_r7 += temp_r8;
            M2C_FIELD(arg0, u8 *, 0xA) = (u8) ((temp_r1_2 & ~0x7F) | ((u8) (((u32) (temp_r1_2 << 0x19) >> 0x19) + 1) & 0x7F));
            goto loop_4;
        }
    }
    return var_r7;
}

#pragma opt_common_subs on
/* Add up to `levels` veteran levels to a unit, each worth 10 points of health
 * and capped at level 10 (100 points). When charge is set each level costs the
 * owning player the unit kind's cost; the total charged is returned. */
s32 LevelUpUnit(void *unit,s32 levels,s32 charge){
s32 GetUnitOwner(void);
s32 func_020d2d18(s32,u32);
s32 Divide(s32,s32);
M2C_UNK func_020d2b10(s32,u16);
extern void **gCurrentMap;
s32 owner,totalCost,health,level,ownerOffset;u16 cost,attr;
owner=GetUnitOwner();totalCost=0;
cost=func_020d2d18(owner,(u32)(M2C_FIELD(unit,u8*,0)<<26)>>26);
if(levels){ownerOffset=owner*140;
do{
health=((UnitHealthCB*)unit)->health;
if(!health)level=0;else level=Divide(health-1,10)+1;
if(level==10)break;
if(charge){
if(M2C_FIELD(ownerOffset+(s32)*gCurrentMap,s32*,0x67a4)<(s32)cost)break;
func_020d2b10(owner,cost);totalCost+=cost;
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
s32 func_020cb3a4(s32 a,s32 b){extern void **gCurrentMap;s32 func_020a7e08(void *);u8 *base=*gCurrentMap;u8 *start=base+0x59a4;u8 *p=start+(s16)base[a+((u16 *)(base+0x3758))[b]]*14;s32 index=p?(p-start)/14:0;if(M2C_FIELD(base,u16 *,0x52a8)==(index&0xc0) && func_020a7e08(p))return 1;return 0;}

s32 func_020cb430(u8 *p) {
extern u8 gUnitKindSupplyFlag[];
extern void **gCurrentMap;
if (!gUnitKindSupplyFlag[((u32)(p[0]<<26)>>26)*112]) return 0;
if(p[1] && func_020cb3a4((s16)(p[1]-1),p[2]))return 1;
if(p[2] && func_020cb3a4(p[1],(s16)(p[2]-1)))return 1;
if(p[1]<M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1 && func_020cb3a4((s16)(p[1]+1),p[2]))return 1;
if(p[2]<M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1 && func_020cb3a4(p[1],(s16)(p[2]+1)))return 1;
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
u8 func_020cb6a4(void *arg0) {
s32 func_020a8604(u32);
u8 func_020c98d8(u8,u8,s32);
s32 RefillUnitAmmo(void *,s32);
s32 RefillUnitFuel(void *,s32);
s32 n=0;
if(func_020a8604((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)==0) n+=RefillUnitAmmo(arg0,0);
n+=RefillUnitFuel(arg0,0);
if(n==0) return n;
return func_020c98d8(M2C_FIELD(arg0,u8 *,1),M2C_FIELD(arg0,u8 *,2),2);
}

#pragma opt_instruction_scheduling off
void func_020cb704(void *a) {
s32 IsSupplyTargetAt(s32,s32); extern s32 data_0215be0c; extern void **gCurrentMap; extern u8 data_0212b1b8[][4];
u16 i=0; data_0215be0c=0;
do {
void *p=*gCurrentMap;
s32 n=IsSupplyTargetAt(M2C_FIELD(p,s16*,0x52dc)+(s8)data_0212b1b8[i][2],M2C_FIELD(p,s16*,0x52de)+(s8)data_0212b1b8[i][3]);
{u32 mask=data_0212b1b8[i][0]; data_0215be0c = (u32)data_0215be0c | mask*(u32)n;} i++;
}while(i<4);
M2C_FIELD(a,s16*,0x34)=0;
}
#pragma opt_instruction_scheduling reset
void func_020cb78c(void *arg0){
void DeleteSpriteObject(void *);void BattleUpdateUnitCursor(void);s32 func_020c98b4(void);M2C_UNK func_020d468c();M2C_UNK func_ov000_02199f50(s32,u8,u8,u8);
extern s32 data_0215be0c;extern void **gCurrentMap;
s16 i;u8 *m;u8 *q;void *p;
if(func_020c98b4())return;
loop:
i=M2C_FIELD(arg0,s16 *,0x34);
if(i>=4){
if(!M2C_FIELD(arg0,s16 *,0x36)){
p=*gCurrentMap;M2C_FIELD(p,s16 *,0x52c2)=M2C_FIELD(p,s16 *,0x52dc);
p=*gCurrentMap;M2C_FIELD(p,s16 *,0x52c4)=M2C_FIELD(p,s16 *,0x52de);}
DeleteSpriteObject(arg0);BattleUpdateUnitCursor();
if(!M2C_FIELD(arg0,s16 *,0x36))func_ov000_02199f50(6,M2C_FIELD(*gCurrentMap,u8 *,0x52d4),0,0);
func_020d468c();
return;
}
if(data_0215be0c&data_0212b1b8[i][0]){
m=*gCurrentMap;q=(u8 *)data_0212b1b8+i*4;
func_020cb6a4(M2C_FIELD((M2C_FIELD(m+2*(M2C_FIELD(m,s16 *,0x52de)+M2C_FIELD(q,s8 *,3)),u16 *,0x3758)+(M2C_FIELD(q,s8 *,2)+(s32)(m+M2C_FIELD(m,s16 *,0x52dc)))),u8 *,0x508)*14+(m+0x59a4));
M2C_FIELD(arg0,s16 *,0x34)++;
}else{M2C_FIELD(arg0,s16 *,0x34)++;}goto loop;
}

void func_020cb8cc(s32 a) {
extern M2C_UNK data_0212b3ac;
void *p=func_01ffa3dc(&data_0212b3ac,7);
if(a) M2C_FIELD(p,s16 *,0x36)=0;
else M2C_FIELD(p,s16 *,0x36)=1;
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
void func_01ffa6fc(void *);
void MarkUnitCargoTiles(void *state){
extern void **gCurrentMap;extern M2C_UNK gUnitKindStats;
u16 i; s32 a,b; UnitCB9 *unit; s32 n;u8 *map;
if(func_020c98b4(state))return;
for(i=M2C_FIELD(state,u16 *,0x50);i<51;i++){
map=*gCurrentMap;
unit=(UnitCB9 *)(map+MAP_UNIT_RECORDS+(M2C_FIELD(map,u16 *,0x52a8)+i)*MAP_UNIT_STRIDE);
if(!unit->kind || (unit->flags&8))continue;
a=0;b=0;
if(func_020d280c(M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER),unit->x,unit->y)){
s32 kind=unit->kind; s32 x; s32 y; s32 terrain; s8 *table;
map=*gCurrentMap; x=unit->x;y=unit->y;
terrain=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_TERRAIN)&31;
table=M2C_FIELD((u8 *)&gUnitKindStats+kind*112,s8 **,0x58);
if(table[terrain]){
if(!func_020a8604(kind)){
a+=RefillUnitAmmo(unit,0);
}
a+=RefillUnitFuel(unit,0);
b+=LevelUpUnit(unit,func_020a7558(unit),1);
}
}
n=func_020a2668(unit,unit->x,unit->y);
if(n)b+=LevelUpUnit(unit,n,1);
if(a||b){
if(b)func_020c98d8(unit->x,unit->y,1);
else func_020c98d8(unit->x,unit->y,2);
M2C_FIELD(state,u16 *,0x50)=i+1;
break;
}
}
if(i==51)func_01ffa6fc(state);
}

