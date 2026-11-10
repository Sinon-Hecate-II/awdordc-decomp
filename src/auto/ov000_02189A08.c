/* 12 functions from 0x02189A08 to 0x0218A9AC (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u16 low:14, high:2; } SelectedUnitFlagsA520;

typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6[8];
} UnkStruct_ov000_02189A08;

void func_ov000_02189a08(void) {
    s32 func_020a33c4(s32);
    s32 func_020a7b3c(s32, s32, s32, s32, s32);
    void FloodFillUnitRange(s32, s32, u8, s32, s32);
    void SelectMapLayer(void *);
    s32 func_ov000_021a8eb0(s32, s32, s32);
    s32 func_ov000_021a9084(s32);
    void PlanMoveDestination(s32, s32);

    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    extern u8 gUnitKindStats[];

    register s32 bestX asm("r4") = -1;
    register s32 bestY asm("r5") = -1;
    register s32 bestCost asm("r6") = 0x7fff;
    register s32 score asm("r7");
    register s32 candScore asm("r10") = 0x7fff;
    s32 x, y;
    s32 candCost2, finalCost;
    s8 *costRow;
    s32 moveCost;
    u16 rowOff;
    u8 terrainByte;
    u8 terrain;
    u8 *cell;
    s8 age;
    u8 unitId;
    u8 *sel;
    u8 *sel2;
    s32 bonus;
    s32 bonus2;
    s32 visResult;
    u8 selType;
    u8 *info;
    u8 infoVal;
    u8 moveLimit;

    score = (s32)*gCurrentMap;
    bonus = func_020a33c4(*(u16 *)((u8 *)score + 0x52a4));
    score = func_020a7b3c((u32)(*(u8 *)*(void **)((u8 *)score + 0x52d0) << 26) >> 26, *(u8 *)((u8 *)data_ov000_021df580 + 0xc), *(u16 *)((u8 *)score + 0x52a4), bonus, 0);
    sel = *(u8 **)((u8 *)*gCurrentMap + 0x52d0);
    FloodFillUnitRange(sel[1], sel[2], (u8)((u32)(sel[0] << 26) >> 26), 0x6e, 0);

    if (*(u16 *)((u8 *)*gCurrentMap + 0x5146) > 0) {
        y = 0;
        do {
            x = 0;
            if (*(u16 *)((u8 *)*gCurrentMap + 0x5144) > 0) {
                do {
                    costRow = *(s8 **)((u8 *)*gCurrentMap + y * 4 + 0x52e8);
                    moveCost = costRow[x];
                    if (moveCost >= 0) {
                        rowOff = *(u16 *)((u8 *)*gCurrentMap + y * 2 + 0x3758);
                        terrainByte = *(u8 *)((u8 *)*gCurrentMap + x + rowOff + 0x1420);
                        terrain = terrainByte & 0x1f;
                        if (terrain == 0x13 || terrain == 0x15) {
                            if (*(u16 *)((u8 *)*gCurrentMap + 0x52a6) == (terrainByte & 0xe0)) {
                                visResult = func_ov000_021a8eb0(x, y, 5);
                                candScore = moveCost;
                                if (visResult == 0) candScore += 0x100;
                                if (bestCost >= candScore) {
                                    bestX = x;
                                    bestY = y;
                                    bestCost = candScore;
                                }
                            }
                        }
                    }
                    x++;
                } while (x < *(u16 *)((u8 *)*gCurrentMap + 0x5144));
            }
            y++;
        } while (y < *(u16 *)((u8 *)*gCurrentMap + 0x5146));
    }

    if (bestX == -1) {
        return;
    }

    candScore = 0x7fff;
    SelectMapLayer((u8 *)*gCurrentMap + 0x2338);
    bonus = func_020a33c4(*(u16 *)((u8 *)*gCurrentMap + 0x52a4));
    bonus2 = func_020a7b3c(7, *(u8 *)((u8 *)data_ov000_021df580 + 0xc), *(u16 *)((u8 *)*gCurrentMap + 0x52a4), bonus, 0);
    FloodFillUnitRange(bestX, bestY, 7, 0x6e, 0);
    SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);

    if (*(u16 *)((u8 *)*gCurrentMap + 0x5146) > 0) {
        y = 0;
        do {
            x = 0;
            if (*(u16 *)((u8 *)*gCurrentMap + 0x5144) > 0) {
                do {
                    costRow = *(s8 **)((u8 *)*gCurrentMap + y * 4 + 0x52e8);
                    moveCost = costRow[x];
                    if (moveCost >= 0) {
                        rowOff = *(u16 *)((u8 *)*gCurrentMap + y * 2 + 0x3758);
                        cell = (u8 *)*gCurrentMap + x + rowOff;
                        age = *(s8 *)(cell + 0x2338);
                        if (age >= 0) {
                            unitId = *cell;
                            if (unitId == 0) {
                                terrainByte = *(u8 *)(cell + 0x1420);
                                terrain = terrainByte & 0x1f;
                                if (terrain == 0x13) {
                                    sel2 = *(u8 **)((u8 *)*gCurrentMap + 0x52d0);
                                    selType = (u32)(sel2[0] << 26) >> 26;
                                    info = gUnitKindStats + selType * 0x70;
                                    infoVal = info[0x0e];
                                    moveLimit = sel2[0x0a] + 0x14;
                                    if (infoVal > moveLimit) {
                                        if (candScore >= moveCost) {
                                            bestX = x;
                                            bestY = y;
                                            candScore = moveCost;
                                        }
                                    } else {
                                        if (func_ov000_021a9084(terrainByte) != 0) {
                                            candCost2 = score + moveCost;
                                            if (candScore >= candCost2) {
                                                bestX = x;
                                                bestY = y;
                                                candScore = candCost2;
                                            }
                                        }
                                    }
                                } else {
                                    if (func_ov000_021a9084(terrainByte) != 0) {
                                        candCost2 = score + moveCost;
                                        if (candScore >= candCost2) {
                                            bestX = x;
                                            bestY = y;
                                            candScore = candCost2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    x++;
                } while (x < *(u16 *)((u8 *)*gCurrentMap + 0x5144));
            }
            y++;
        } while (y < *(u16 *)((u8 *)*gCurrentMap + 0x5146));
    }

    costRow = *(s8 **)((u8 *)*gCurrentMap + bestY * 4 + 0x52e8);
    finalCost = costRow[bestX];
    if (finalCost <= *(u8 *)((u8 *)data_ov000_021df580 + 0x05)) {
        return;
    }
    PlanMoveDestination(bestX, bestY);
}

void func_ov000_02189df4(void) {
    M2C_UNK SelectCarriedUnitAction();
    M2C_UNK func_ov000_021895bc();
    extern void **gCurrentMap;
    if (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xC) != 0) {
        SelectCarriedUnitAction();
        return;
    }
    func_ov000_021895bc();
}

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_02189e2c(void){
extern void **gCurrentMap;extern s8 data_ov000_021b54c0[];s32 func_020d27ec(u8,u8);
s32 n=0,x,y;void *base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(base+(y<<2),s8 **,0x52e8),s8 *,x)>=0){
if(data_ov000_021b54c0[M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420)&31]!=0){
if(func_020d27ec(M2C_FIELD(base,u8 *,0x52d4),M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420))==0){
if((M2C_FIELD(M2C_FIELD(*gCurrentMap+(y<<1),u16 *,0x3758)+(*gCurrentMap+x),u8 *,0x1420)&31)==15)n+=30;else n++;
}}}
base=*gCurrentMap;
}}
return n;
}

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_02189f3c(void){
extern void **gCurrentMap;extern s8 data_ov000_021b54c0[];s32 func_020d27ec(u8,u8);
s32 n=0,x,y;void *base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(base+(y<<2),s8 **,0x52e8),s8 *,x)>=0){
if(data_ov000_021b54c0[M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420)&31]!=0){
if(func_020d27ec(M2C_FIELD(base,u8 *,0x52d4),M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420))==0){
void *b=*gCurrentMap;
void *cell=(b+x)+M2C_FIELD(b+(y<<1),u16 *,0x3758);
if(M2C_FIELD(b+M2C_FIELD(cell,s8 *,0x1928)*6,u8 *,0x6c63)==0 || (M2C_FIELD(cell,u8 *,0x1420)&31)==15){
if((M2C_FIELD(cell,u8 *,0x1420)&31)==15)n+=30;else n++;
}
}}}
base=*gCurrentMap;
}}
return n;
}
#pragma pop

#pragma pop
s32 func_ov000_0218a080(u8 arg0) {
    s32 IsFootUnitKind(u32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count = 0;
    s32 i;
    u16 start = gPlayerUnitIdBase[arg0];

    for (i = start + 1; i < gPlayerUnitIdBase[arg0] + 0x33; i++) {
        UnkStruct_ov000_02189A08 *entry = &((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap + 0x59A4))[i];
        u32 type = entry->unk0;
        if (type != 0 && !(entry->unk4 & 8) && IsFootUnitKind(type) != 0 && ((s8 **)((u8 *)*gCurrentMap + 0x52E8))[entry->unk2][entry->unk1] != -1) {
            count += 1;
        }
    }
    return count;
}

/* Counts units of an enemy player whose map position is visible (-1 would mark blocked) and whose unit info has nonzero field at +0xC and bit0-2 of +0x13. */
s32 func_ov000_0218a140(u8 arg0) {
    s32 IsFootUnitKind(u32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    s32 count = 0;
    s32 i;
    u16 start = gPlayerUnitIdBase[arg0];

    for (i = start + 1; i < gPlayerUnitIdBase[arg0] + 0x33; i++) {
        UnkStruct_ov000_02189A08 *entry = &((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap + 0x59A4))[i];
        u32 type = entry->unk0;
        if (type != 0 && !(entry->unk4 & 8) && IsFootUnitKind(type) == 0) {
            u8 *info = gUnitKindStats + entry->unk0 * 0x70;
            if ((info[0x13] & 7) && info[0xc] != 0 && ((s8 **)((u8 *)*gCurrentMap + 0x52E8))[entry->unk2][entry->unk1] != -1) {
                count++;
            }
        }
    }
    return count;
}

s32 func_ov000_0218a230(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    s32 func_ov000_0218a080(u8);
    extern void **gCurrentMap;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) != 0 && IsPlayerActive(i) != 0) {
            count += func_ov000_0218a080(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

s32 func_ov000_0218a294(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    s32 func_ov000_0218a140(u8);
    extern void **gCurrentMap;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) != 0 && IsPlayerActive(i) != 0) {
            count += func_ov000_0218a140(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

s32 func_ov000_0218a2f8(void){
s32 IsPlayerActive(s32);s32 IsSameTeam(u16,s32);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 gUnitKindStats[];
s32 count=0,p,end,i;
for(p=1;p<5;p++){
if(IsPlayerActive(p)!=0 && IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),p)!=1){
u16 start=gPlayerUnitIdBase[p];
i=start+1;end=start+0x33;
for(;i<end;i++){
UnkStruct_ov000_02189A08 *entry=&((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && !(entry->unk4&8) && (gUnitKindStats[type*0x70+0x13]&7) && ((s8 **)((u8 *)*gCurrentMap+0x52e8))[entry->unk2][entry->unk1]!=-1)count++;
}}}return count;}

s32 func_ov000_0218a3fc(void){
s32 IsPlayerActive(s32);s32 IsSameTeam(u16,s32);s32 IsFootUnitKind(u32);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 gUnitKindStats[];
s32 p,i;
for(p=1;p<5;p++){
if(IsPlayerActive(p)!=0){
for(i=gPlayerUnitIdBase[p]+1;i<gPlayerUnitIdBase[p]+0x33;i++){
UnkStruct_ov000_02189A08 *entry=&((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0&&(gUnitKindStats[type*112+0x13]&7)&&((s8 **)((u8 *)*gCurrentMap+0x52e8))[entry->unk2][entry->unk1]!=-1){
if(IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),p)==0){
if(IsFootUnitKind(entry->unk0)==0)goto success;
goto next;
}else{
if(IsFootUnitKind(entry->unk0)==0)goto next;
}
success:return 1;
}
next:;
}
}}
return 0;
}

#pragma opt_propagation off
s32 IsValidMoveCell(s32 x, s32 y) {
    s32 GetUnitAttackClass(s32);
    s32 IsUnitSelected(void *);
    s32 func_ov000_02178e84(s32, s32);
    s32 func_ov000_021a9904(s32);
    s32 func_ov000_021a90a8(s32, s32, s32);
    s32 func_ov000_02178778(s32, s32);
    s32 func_ov000_021a9084(s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern u8 data_ov000_021df9bc[];
    extern u8 data_ov000_021dfc4c[];
    extern u8 *data_ov000_021df644;

    if (!GetUnitAttackClass(((UnkStruct_ov000_02189A08 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unk0) && !IsUnitSelected(*(void **)((u8 *)*gCurrentMap+0x52d0))) {
u8 attr=data_ov000_021b5c0f[((UnkStruct_ov000_02189A08 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unk0*0x70];
if(attr&7) {u32 idx=y*(*(u16 *)((u8 *)*gCurrentMap+0x5144))+x;
if((u8)((1<<(idx&7)) & data_ov000_021df9bc[idx>>3])) goto valid;
}
if(attr&0x10) {u32 idx=y*(*(u16 *)((u8 *)*gCurrentMap+0x5144))+x;
if((u8)((1<<(idx&7)) & data_ov000_021dfc4c[idx>>3])) goto valid;
}
}
    {
        s32 cell; u8 *ptr; u8 *map;
        u8 limit;
        u16 rowOffset;
        map=(u8 *)*gCurrentMap; ptr=data_ov000_021df644;
        rowOffset=*(u16 *)(map+y*2+0x3758);
        cell = (s32)(map + (x + rowOffset) + 0x2000);
        limit=ptr[1];
        if (M2C_FIELD(cell,u8 *,0x840) >= limit) {
            return 0;
        }
        if (M2C_FIELD(cell,u8 *,0xd48) >= ptr[2]) {
            return 0;
        }
    }
valid:
    if (!func_ov000_02178e84(x, y)) {
        return 0;
    }
    {
u32 unitKind2=((UnkStruct_ov000_02189A08 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unk0;
if(data_ov000_021b5c0f[unitKind2*0x70]!=0x20 && func_ov000_021a9904(unitKind2)!=2) {
u8 *m=(u8 *)*gCurrentMap;
u16 rowOffset=*(u16 *)(m+y*2+0x3758);
u8 terrain=(m+(x+rowOffset)+0x1000)[0x420]&0x1f;
if(terrain==0x13 || terrain==0x15) {
if(!func_ov000_021a90a8(m[0x52d4],x,y))return 0;
}
}
}
    if (func_ov000_02178778(x, y) == 1) {
        return 0;
    }
    if((((SelectedUnitFlagsA520 *)((u8 *)*(void **)((u8 *)*gCurrentMap+0x52d0)+8))->high)==2) {
        u16 rowOffset = *(u16 *)((u8 *)*gCurrentMap + y * 2 + 0x3758);
        u8 finalByte = ((u8 *)*gCurrentMap + (x + rowOffset) + 0x1000)[0x420];
        if (func_ov000_021a9084(finalByte) != 0) {
            return 0;
        }
    }
    return 1;
}
#pragma opt_propagation reset
s32 DestinationScore(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov000_021a8a38(s32, s32, s32, s32);
    s32 ManhattanDistance(s32, s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    s32 val;
    s32 d1;
    u32 type;
    UnkStruct_ov000_02189A08 *entry;
    s32 y;
    u32 x;
    s32 end;
    s32 i;
    s32 bestOther = 0x7FFFFFFF;
    s32 bestVisible = 0x7FFFFFFF;
    s32 savedAttr;
    void *selected;
    void *map;

    map = *gCurrentMap;
    selected = M2C_FIELD(map, void **, 0x52D0);
    savedAttr = data_ov000_021b5c0f[((UnkStruct_ov000_02189A08 *)selected)->unk0 * 0x70];
    if (savedAttr & 0x7) { savedAttr = 0x7; }

    map = *gCurrentMap;
    i = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, 0x52A4)] + 1;
    end = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, 0x52A4)] + 0x33;
    if (i < end) {
        x = (s16)arg0;
        y = (s16)arg1;
        do {
            entry = &((UnkStruct_ov000_02189A08 *)((u8 *)map + 0x59A4))[i];
            type = entry->unk0;
            if (type != 0 && entry != (UnkStruct_ov000_02189A08 *)M2C_FIELD(map, void **, 0x52D0) && !(entry->unk4 & 0x8)) {
                u8 *info = gUnitKindStats + type * 0x70;
                u8 attr = info[0x13];
                if ((savedAttr & attr) && !(entry->unk4 & 0x1)) {
                    d1 = ManhattanDistance(x, y, entry->unk1, entry->unk2);
                    val = func_ov000_021a8a38(x, y, entry->unk1, entry->unk2) + (d1 << 8);
                    if (bestVisible >= val) { bestVisible = val; }
                } else {
                    d1 = ManhattanDistance(x, y, entry->unk1, entry->unk2);
                    val = func_ov000_021a8a38(x, y, entry->unk1, entry->unk2) + (d1 << 8);
                    if (bestOther >= val) { bestOther = val; }
                }
            }
            i += 1;
            map = *gCurrentMap;
            end = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, 0x52A4)] + 0x33;
        } while (i < end);
    }

    if (bestVisible != 0x7FFFFFFF) {
        return bestVisible;
    }
    if (bestOther != 0x7FFFFFFF) {
        return bestOther;
    }
    return func_ov000_021a8a38((s16)arg0, (s16)arg1, (s16)arg2, (s16)arg3);
}

