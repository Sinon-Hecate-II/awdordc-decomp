/* 14 functions from 0x02199614 to 0x0219A584 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_unit_entry.h"
typedef struct { u16 value:7; } Field7;

/* Builds the influence (threat) field of one player's units.  For each unit
 * that can act it computes an influence strength and either adds it to the
 * eligible map cells' field at map+0x2840 or lets func_ov000_02197a8c apply
 * the unit's area of effect.  MAP_ACTIVE_PLAYER names the player processed. */
void BuildPlayerInfluence(u8 player) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 func_ov000_021973f8(s32);
s32 func_ov000_02197434(s32,s32);
s32 func_ov000_02197470(s32,s32,s32);
s32 func_ov000_021974bc(s32,s32,void*);
s32 func_ov000_0219763c(s32,void*,s32);
void func_ov000_02197a8c(void*,s32,s32,s32,s32,s32,s32);
s32 func_020a85dc(s32);
s32 GetUnitAttackClass(s32);
s32 GetUnitMoveRange(s32,s32);
s32 FloodFillUnitRange(s32,s32,s32,s32,s32);
void func_01ffb9c4(s32);
s32 tileX,tileY;
s32 unitId,influence;
UnkStruct_ov000_021A860C *unit;
u8 *map,*cell;
s32 owner,id,amount;
if(!func_ov000_021973f8(21))return;
M2C_FIELD(*gCurrentMap,u16 *,MAP_ACTIVE_PLAYER)=player;
for(unitId=gPlayerUnitIdBase[player]+1;unitId<gPlayerUnitIdBase[player]+51;unitId++){
map=(u8 *)*gCurrentMap;
unit=(UnkStruct_ov000_021A860C *)(map+MAP_UNIT_RECORDS+unitId*14);
if(!unit->unk0)continue;
if(M2C_FIELD(unit,u16 *,4)&8){
s32 unitY=((u8 *)unit)[2];s32 unitX=((u8 *)unit)[1];s32 row=M2C_FIELD(map+unitY*2,u16 *,MAP_ROW_OFFSETS);
id=M2C_FIELD(map+unitX+row,u8 *,0x508);
if(!func_020a85dc(((UnkStruct_ov000_021A860C *)(map+id*14+MAP_UNIT_RECORDS))->unk0))continue;
}
influence=func_ov000_02197434(unit->unk0,21);
if(influence<25)continue;
influence=func_ov000_02197470(influence,0,unit->unk0_6);
influence=func_ov000_021974bc(influence,0,unit);
influence=func_ov000_0219763c(influence,unit,unit->unk6);
if(!GetUnitAttackClass(unit->unk0)){
if(unit){if(!unit)id=0;else id=unit-(UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS);owner=(id>>6)+1;}else owner=0;
owner=GetUnitMoveRange(owner,unit->unk0);
FloodFillUnitRange(((u8 *)unit)[1],((u8 *)unit)[2],unit->unk0,owner,1);
func_01ffb9c4(111);
for(tileY=0;tileY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);tileY++){
for(tileX=0;tileX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);tileX++){
map=(u8 *)*gCurrentMap;
if(((s8 **)(map+0x52e8))[tileY][tileX]>=0){
cell=map+tileX+((u16 *)map)[tileY+0x1bac];
amount=influence+((u8 *)(cell+0x2000))[0x840];
if(amount>=255)amount=255;
M2C_FIELD(cell,u8 *,0x2840)=amount;
}
}
}
}else func_ov000_02197a8c(unit,influence,21,100,0,1,0);
}
}

void func_ov000_021998f0(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void BuildPlayerInfluence(u8);
    extern s32 *gCurrentMap;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*gCurrentMap, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (IsPlayerActive(i) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0) {
            BuildPlayerInfluence(i);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

void func_ov000_0219997c(void) {
s32 func_0207c2f0(void);
s32 Modulo(s32, s32);
s32 func_02072b04(void *);
s32 func_ov000_021a89a4(void *);
extern s32 *gCurrentMap;
extern u8 *data_ov000_021df658;
extern u8 *data_ov000_021df580;
extern u8 *gAiSettings;
extern u8 *data_ov000_021df644;
extern u8 gAiCommand[];
extern M2C_UNK data_ov000_021df604;
extern void (*data_ov000_021df654)(void);

u8 state;
u8 *cont;
u8 *base;
u8 *up;
u8 kind;
u8 tile;
u8 s;
u8 ux, uy;
s16 x, y;
u16 row;
s32 tmp;

state = *data_ov000_021df658;
if (state == 0) {
    data_ov000_021df580[0] = 1;
    return;
}
if (state == 0x40) {
    gAiCommand[0x13] = 0;
} else {
    cont = (u8 *)*gCurrentMap;
    base = *(u8 **)cont;
    base[0x52d4] = state;
    up = base + 0x59a4 + base[0x52d4] * 14;
    *(u8 **)(base + 0x52d0) = up;
    data_ov000_021df644 = gAiSettings + 0x14 + 0xc * (((u8)up[0] & 0x3f) - 1);
    base[0x52d6] = 0;

    if (!(*(u16 *)(up + 4) & 0x1)) {
        kind = (u8)(up[0] & 0x3f);
        if (kind == 0) {
            data_ov000_021df658++;
            return;
        }
    }
    up = *(u8 **)(base + 0x52d0);
    if (*(u16 *)(up + 4) & 0x8) {
        *(u16 *)(up + 4) &= ~0x8;
        uy = up[2];
        ux = up[1];
        row = *(u16 *)(base + uy * 2 + 0x3758);
        tile = base[ux + row];
        base[0x52d6] = tile;
    }

    up = *(u8 **)(base + 0x52d0);
    x = up[1];
    *(s16 *)(base + 0x52e0) = x;
    *(s16 *)(base + 0x52d8) = x;
    y = up[2];
    *(s16 *)(base + 0x52e2) = y;
    *(s16 *)(base + 0x52da) = y;
    data_ov000_021df580[7] = (u8)(data_ov000_021df580[7] & ~1);
    data_ov000_021df580[7] = (u8)(data_ov000_021df580[7] & ~2);
    *(u16 *)(data_ov000_021df580 + 8) = 0;
    gAiCommand[0] = 0;
    gAiCommand[0x13] = 0;
    gAiCommand[6] = 0;
    {
        u8 *up2 = *(u8 **)(base + 0x52d0);
        u8 uuy = up2[2];
        u8 uux = up2[1];
        u16 rrow = *(u16 *)(base + uuy * 2 + 0x3758);
        base[uux + rrow] = 0;
    }
    tmp = func_0207c2f0();
    tmp = Modulo(tmp, 0x64);
    data_ov000_021df580[3] = (u8)tmp;
    up = *(u8 **)(base + 0x52d0);
    data_ov000_021df580[5] = (u8)func_ov000_021a89a4(up);
}

if (func_02072b04(&data_ov000_021df604) == 0) {
    data_ov000_021df654();
}
if (gAiCommand[0x13] != 0) {
    data_ov000_021df658++;
    data_ov000_021df580[0] = 3;
    return;
}
cont = (u8 *)*gCurrentMap;
base = *(u8 **)cont;
state = *data_ov000_021df658;
if (state != 0x40) {
    if (base[0x52d6] != 0) {
        up = *(u8 **)(base + 0x52d0);
        *(u16 *)(up + 4) |= 0x8;
        base[0x52d6] = 0;
    } else {
        up = *(u8 **)(base + 0x52d0);
        s = base[0x52d4];
        uy = up[2];
        ux = up[1];
        row = *(u16 *)(base + uy * 2 + 0x3758);
        base[ux + row] = s;
    }
}
data_ov000_021df658++;
return;
}

#pragma opt_lifetimes off
void func_ov000_02199ce0(void) {
void func_02085348(void *,s32);
extern u8 gAiCommand[];
extern u8 data_02156e50[];
s32 i;
u8 *s;
u8 *d;
s=gAiCommand;
d=data_02156e50;
d[0]=s[0]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[1]=s[1];
*(s32 *)(d+8)=*(s32 *)(s+8);
d[6]=s[6]; d[7]=s[7]; d[0x12]=s[0x12];
for(i=0;i<6;i++,s++,d++) d[12]=s[12];
func_02085348(data_02156e50,0x14);
}
#pragma opt_lifetimes reset
void SetMapCursor(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    void func_ov000_0217e798(M2C_UNK, M2C_UNK, u8 *, u8 *, u8 *);
    void func_ov000_0217d3b8(s32);
    M2C_UNK func_02072b10(M2C_UNK *, M2C_UNK);
    void BuildUnitMoveRange(void *);
    void func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    s32 func_02084464(void *, void *);
    s32 func_0207c2e0(void);
    s32 func_020a641c(s32, s32);
    void func_ov000_02199ce0(void);
    extern s32 *gCurrentMap;
    extern M2C_UNK data_ov000_021df604;
    extern u8 data_ov000_021df7dc[];
    extern u8 gAiCommand[];
    extern u8 data_02168f0c[];

    u8 *unit;
    s32 result;
    u8 *state;

    func_ov000_0217e798(arg0, arg1, &arg2, &arg3, &arg4);

    func_ov000_0217d3b8(arg2);

    unit = *(u8 **)((u8 *)*gCurrentMap + 0x52D0);

    if (unit[1] == arg0 && unit[2] == arg1 &&
        (arg2 == 2 || ((u8 *)*gCurrentMap)[0x52D6] != 0)) {

        unit[0xA] |= 0x80;
        func_02072b10(&data_ov000_021df604, 1);
        BuildUnitMoveRange(unit);
    }
        func_01ffc4b8(arg0, arg1, (s32)(((u8 *)*gCurrentMap) + 0x5388));
        func_02084464(((u8 *)*gCurrentMap) + 0x5388, data_ov000_021df7dc);

        gAiCommand[1] = ((u8 *)*gCurrentMap)[0x52D4];

        *(s32 *)(gAiCommand + 8) = func_0207c2e0();

        gAiCommand[4] = (u8)*((s16 *)(((u8 *)*gCurrentMap) + 0x52D8));
        gAiCommand[5] = (u8)*((s16 *)(((u8 *)*gCurrentMap) + 0x52DA));
        gAiCommand[2] = (u8)arg0;
        gAiCommand[3] = (u8)arg1;
        gAiCommand[0] = arg2;
        gAiCommand[6] = arg3;
        gAiCommand[7] = arg4;

        result=func_020a641c((s32)*(u8 **)((u8 *)*gCurrentMap+0x52d0),((u8 *)*gCurrentMap)[0x52d5]);
        state=gAiCommand;
        unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
        ((volatile u8 *)state)[0x12] = ((u32)(unit[10]<<25)>>25)-result;
        ((volatile u8 *)state)[0x13] = 1;

    if (*(volatile u8 *)data_02168f0c != 0) {
        func_ov000_02199ce0();
    }
    func_02072b10(&data_ov000_021df604, 1);
}

void func_ov000_02199f38(void) {
    M2C_UNK func_02072b10(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021df604;
    func_02072b10(&data_ov000_021df604, 1);
}

void func_ov000_02199f50(s32 a, s32 b, s32 c, s32 d) {
    s32 func_02084464(void *, void *);
    s32 func_0207c2e0(void);
    s32 func_020a641c(s32, s32);
    void func_02084568(s32, s32, s32, s32);
    extern s32 *gCurrentMap;
    extern u8 data_ov000_021df7dc[];
    extern u8 gAiCommand[];
    extern u8 data_02168f0c[];
    func_02084464((u8 *)*gCurrentMap + 0x5388, data_ov000_021df7dc);
    gAiCommand[1] = (u8)b;
    *(s32 *)(gAiCommand + 8) = func_0207c2e0();
    gAiCommand[0] = (u8)a;
    gAiCommand[2] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52dc);
    gAiCommand[3] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52de);
    gAiCommand[4] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52d8);
    gAiCommand[5] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52da);
    gAiCommand[6] = (u8)c;
    gAiCommand[7] = (u8)d;
    if (*(s32 *)((u8 *)*gCurrentMap + 0x52d0) != 0) {
        s32 _r = func_020a641c(*(s32 *)((u8 *)*gCurrentMap + 0x52d0),
                                (u8)*((u8 *)*gCurrentMap + 0x52d5));
        volatile u8 *_u = (volatile u8 *)*(s32 *)((u8 *)*gCurrentMap + 0x52d0);
        gAiCommand[0x12] = (((u32)_u[0xa] << 25) >> 25) - _r;
    }
    if (data_02168f0c[0] != 0) {
        func_02084568(a, b, c, d);
    }
}

void func_ov000_0219a064(void) {
extern s32 *gCurrentMap;
extern u8 gAiCommand[];
u8 *p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);

if(!p || !((Field7 *)(p+6))->value) return;

if(gAiCommand[0]==4) p[11]|=0x40;
else if(gAiCommand[2]!=gAiCommand[4] || gAiCommand[3]!=gAiCommand[5]) p[11]&=~0x40;
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_0219a0e0(void) {
extern s32 *gCurrentMap;
s32 IsCellUnitOnSameArmy(s32,s16,s16);
s32 x,y;u32 idx;u8 *base=(u8 *)*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
idx=x+M2C_FIELD(base+y*2,u16 *,0x3758);
if((u8)(M2C_FIELD(base+(idx>>3),u8 *,0x5160)&(1<<(idx&7)))&&
M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+(base+x),u8 *,0)!=0){
if(IsCellUnitOnSameArmy((u8)M2C_FIELD(base,u16 *,0x52a4),x,y)==0){
base=(u8 *)*gCurrentMap;
M2C_FIELD(base+0x59a4+M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+(base+x),u8 *,0)*14,u8 *,0xb)|=0x40;
}
}
base=(u8 *)*gCurrentMap;
}
}
}
void func_ov000_0219a1f4(void) {
    void func_020c93cc(void);
    void SetupAiUnitParameters(u16);
    void func_ov000_0219a9b0(void);
    void func_ov000_0219a370(void);
    void func_ov000_0219a418(void);
    void func_ov000_0219a618(void);
    void func_ov000_0219a6c8(void);
    void func_ov000_0219a584(void);
    void func_ov000_0219c444(void);
    void func_ov000_02181c88(void);
    void func_ov000_0219a350(void);
    void func_ov000_0219a8c4(void);
    s32 func_ov000_021a9b84(void);
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 *data_ov000_021df580;

    {
        u8 *map = *(u8 **)gCurrentMap;
        u16 val = *(u16 *)(map + 0x52a4);
        map[0x52d4] = (u8)gPlayerUnitIdBase[val];
    }
    {
        u8 *map = *(u8 **)gCurrentMap;
        *(u8 **)(map + 0x52d0) = map + 0x59a4 + map[0x52d4] * 0xe;
    }
    func_020c93cc();
    data_ov000_021df580[0xc] = (*(u8 **)gCurrentMap)[0x5158];
    if ((*(u8 **)gCurrentMap)[0x5159] == 1) {
        data_ov000_021df580[0xd] = 0;
    } else {
        data_ov000_021df580[0xd] = (*(u8 **)gCurrentMap)[0x5158];
    }
    SetupAiUnitParameters(*(u16 *)(*(u8 **)gCurrentMap + 0x52a4));
    func_ov000_0219a9b0();
    func_ov000_0219a370();
    func_ov000_0219a418();
    func_ov000_0219a618();
    func_ov000_0219a6c8();
    func_ov000_0219a584();
    func_ov000_0219c444();
    func_ov000_02181c88();
    func_ov000_0219a350();
    func_ov000_0219a8c4();
    if (func_ov000_021a9b84() == 1) {
        data_ov000_021df580[0x7] |= 0x04;
    } else {
        data_ov000_021df580[0x7] &= ~0x04;
    }
    data_ov000_021df580[0x7] |= 0x08;
    data_ov000_021df580[0x2] = 0;
    data_ov000_021df580[0x1] = 0;
    data_ov000_021df580[0x0] = 1;
}

#pragma pop
void func_ov000_0219a350(void) {
    extern void *gAiState;
    M2C_FIELD(gAiState, s8 *, 2) = 0;
    M2C_FIELD(gAiState, s8 *, 3) = 0;
}

void func_ov000_0219a370(void) {
    extern s32 *gCurrentMap;
    s32 var_r1;
    void *var_r2;

    var_r1 = 0;
    var_r2 = *gCurrentMap + 0x6C60;
    do {
        M2C_FIELD(var_r2, s8 *, 3) = 0;
        M2C_FIELD(var_r2, s8 *, 4) = 0;
        var_r1 += 1;
        M2C_FIELD(var_r2, s8 *, 5) = 0;
        var_r2 += 6;
    } while (var_r1 < 0x63);
}

s32 func_ov000_0219a3b0(s32 n) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)*gCurrentMap+0x67a4+n*0x8c;
s32 sum=0;
sum+=p[0x11]; sum+=p[0x10]; sum+=p[0x12]; sum+=p[0x13]; sum+=p[0x14]; sum+=p[0x15]; sum+=p[0x16]; sum+=p[0x17];
return sum+1;
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_0219a418(void) {
void SelectMapLayer(s32);
void FillMapLayer(s32);
M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
extern s32 *gCurrentMap;
extern u8 *data_ov000_021df580;
s32 count=0;
u8 *p;
s32 x,y;
u8 *base;
SelectMapLayer((s32)*gCurrentMap+0x2338);
FillMapLayer(count);
SelectMapLayer((s32)*gCurrentMap+0x1e30);
base=(u8 *)*gCurrentMap;
for(p=base+0x6c60;*p!=0xff;p+=6){
if(M2C_FIELD(base+M2C_FIELD(p,u8 *,1)+M2C_FIELD(base+M2C_FIELD(p,u8 *,2)*2,u16 *,0x3758),s8 *,0x2338)==0){
FloodFillUnitRange(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),1,0x6e,0);
base=(u8 *)*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(M2C_FIELD(base+y*4,s8 **,0x52e8)[x]>=0){
M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16 *,0x3758),u8 *,0x2338)=1;
}
base=(u8 *)*gCurrentMap;
}
}
count++;
}
}
M2C_FIELD(data_ov000_021df580,u8 *,6)=count;
}
#pragma pop
