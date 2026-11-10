/* 19 functions from 0x021A58C8 to 0x021A686C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u8 pad[3]; u8 used:1; u8 rest:7; } Candidate1F14;
typedef struct { u8 x,y; u8 unk[10]; } UnkA66Entry;

#pragma opt_strength_reduction off
/* Folds the reachable cells of every type-22 indirect unit of `player` into the
 * map's score layer, keeping the lowest distance per cell; a unit is skipped when
 * one of the acting player's healthy type-23 units already stands in its reach. */
void MarkPlayerIndirectThreat(u8 player) {
    void FloodFillUnitRange(s32, s32, s32, s32, s32);
    s32 IsCurrentPlayerUnit(u8);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 id, x, y, v, unitOffset;
    s32 x2, y2;
    u8 *tile;
    s32 oldValue;
    void *base;
    u8 *unit;

    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = player;
    id = gPlayerUnitIdBase[player] + 1;
    if (id >= gPlayerUnitIdBase[player] + 51) return;
    unitOffset = id * MAP_UNIT_STRIDE;
    do {
        base = *gCurrentMap;
        unit = (u8 *)(base + MAP_UNIT_RECORDS) + unitOffset;
        if (((u32)(unit[0] << 26) >> 26) == 0) goto next;
        if (((u32)(unit[0] << 26) >> 26) != 22) goto next;
        if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) <= 20) goto next;
        FloodFillUnitRange(unit[1], unit[2], 23, 110, 32);
        base = *gCurrentMap;
        for (y = 0; y < M2C_FIELD(base, u16 *, MAP_HEIGHT); y++) {
            for (x = 0; x < M2C_FIELD(base, u16 *, MAP_WIDTH); x++, base = *gCurrentMap) {
                if (M2C_FIELD(base + y * 4, s8 **, MAP_GRID)[x] < 0) continue;
                if (!IsCurrentPlayerUnit(M2C_FIELD(M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS) + (base + x), u8 *, MAP_CELL_UNIT_ID))) continue;
                base = *gCurrentMap;
                unit = (u8 *)(base + MAP_UNIT_RECORDS) + M2C_FIELD(M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS) + (base + x), u8 *, 0) * MAP_UNIT_STRIDE;
                if (((u32)(unit[0] << 26) >> 26) != 23) continue;
                if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) >= 40) goto next;
            }
        }
        for (y2 = 0; y2 < M2C_FIELD(base, u16 *, MAP_HEIGHT); y2++) {
            for (x2 = 0; x2 < M2C_FIELD(base, u16 *, MAP_WIDTH); x2++, base = *gCurrentMap) {
                v = M2C_FIELD(base + y2 * 4, s8 **, MAP_GRID)[x2];
                if (v < 0) continue;
                tile = (u8 *)(base + x2 + M2C_FIELD(base + y2 * 2, u16 *, MAP_ROW_OFFSETS));
                oldValue = M2C_FIELD(tile, s8 *, MAP_CELL_SCORE);
                if (v <= oldValue) M2C_FIELD(tile + 0x2000, s8 *, 0x338) = v;
            }
        }
    next:;
        id++;
        unitOffset += MAP_UNIT_STRIDE;
    } while (id < gPlayerUnitIdBase[player] + 51);
}
#pragma opt_strength_reduction reset
void func_ov000_021a5b28(void) {
    void FillMapLayer(s32);
    void SelectMapLayer(void *);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void MarkPlayerIndirectThreat(u8);
    extern void **gCurrentMap;
    u16 saved;
    s32 i;
    void *base;
    base = *gCurrentMap;
    saved = M2C_FIELD(base, u16 *, 0x52B6);
    SelectMapLayer(base + 0x2338);
    FillMapLayer(0x7F);
    SelectMapLayer(*gCurrentMap + 0x1E30);
    for (i = 1; i < 5; i++) {
        if (IsPlayerActive(i) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0)
            MarkPlayerIndirectThreat(i);
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

#pragma opt_strength_reduction off
void func_ov000_021a5bd4(u8 arg0) {
    void FloodFillUnitRange(s32,s32,s32,s32,s32);
    void MI_CpuFill8(void*,s32,s32);
    s32 IsUnitOnCurrentTeam(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gAiRangeLayer[];
    void *base;
    u8 *unit, *tile;
    s8 *p;
    s32 id, unitOffset, count;
    s32 x, y, x2, y2;
    s32 index;
    s32 v, old;
    M2C_FIELD(*gCurrentMap,u16*,0x52B6)=arg0;
    id=gPlayerUnitIdBase[arg0]+1;
    if(id>=gPlayerUnitIdBase[arg0]+51)return;
    unitOffset=id*14;
    do {
        unit=(u8 *)(*gCurrentMap+0x59A4)+unitOffset;
        if(((u32)(unit[0]<<26)>>26)==0)goto next;
        if(((u32)(unit[0]<<26)>>26)!=20 && ((u32)(unit[0]<<26)>>26)!=21)goto next;
        if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)<=20)goto next;
        FloodFillUnitRange(unit[1],unit[2],22,110,32);
        count=0;
        MI_CpuFill8(gAiRangeLayer,0x7F,0x508);
        for(y=0,base=*gCurrentMap;y<M2C_FIELD(base,u16 *,0x5146);y++){
            for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++,base=*gCurrentMap){
                if(M2C_FIELD(base+y*4,s8 **,0x52E8)[x]<0)continue;
                unit=(u8 *)(base+0x59A4)+M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16 *,0x3758),u8 *,0)*14;
                index=unit?((s32)(unit-(u8 *)(base+0x59A4)))/14:0;
                if(IsUnitOnCurrentTeam(index)==0){
                    if(((u32)(unit[0]<<26)>>26)!=20 && ((u32)(unit[0]<<26)>>26)!=21)continue;
                    if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)<=20)continue;
                    count++;
                    base=*gCurrentMap;
                    for(y2=0;y2<M2C_FIELD(base,u16 *,0x5146);y2++){
                        p=(s8 *)gAiRangeLayer;
                        for(x2=0;x2<M2C_FIELD(base,u16 *,0x5144);x2++,base=*gCurrentMap,p++){
                            v=M2C_FIELD(base+y2*4,s8 **,0x52E8)[x2];
                            if(v<0)continue;
                            if(v<M2C_FIELD(p,s8 *,y2*M2C_FIELD(base,u16 *,0x5144)))
                                M2C_FIELD(p,s8 *,y2*M2C_FIELD(base,u16 *,0x5144))=v;
                        }
                    }
                } else {
                    if(((u32)(unit[0]<<26)>>26)!=22)continue;
                    if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)>=60)goto next;
                }
            }
        }
        if(count<1)goto next;
        for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
            p=(s8 *)gAiRangeLayer;
            for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++,base=*gCurrentMap,p++){
                v=M2C_FIELD(p,s8 *,y*M2C_FIELD(base,u16 *,0x5144));
                tile=(u8 *)(base+x+M2C_FIELD(base+y*2,u16 *,0x3758));
                old=M2C_FIELD(tile,s8 *,0x2338);
                if(v<old)M2C_FIELD(tile+0x2000,s8 *,0x338)=v;
            }
        }
        next:;
        id++;unitOffset+=14;
    } while(id<gPlayerUnitIdBase[arg0]+51);
}
#pragma opt_strength_reduction reset
void func_ov000_021a5f50(void) {
    void FillMapLayer(s32);
    void SelectMapLayer(void *);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void func_ov000_021a5bd4(u8);
    extern void **gCurrentMap;
    u16 saved;
    s32 i;
    void *base;
    base = *gCurrentMap;
    saved = M2C_FIELD(base, u16 *, 0x52B6);
    SelectMapLayer(base + 0x2338);
    FillMapLayer(0x7F);
    SelectMapLayer(*gCurrentMap + 0x1E30);
    for (i = 1; i < 5; i++) {
        if (IsPlayerActive(i) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0)
            func_ov000_021a5bd4(i);
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

s32 func_ov000_021a5ffc(s32 arg0) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates;
u8 *p;
s32 i;
p = (u8 *)&gAiTargetCandidates;
for (i=0; i<*gAiState; i++,p+=12) {
if ((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) return i;
}
return -1;
}

s32 func_ov000_021a605c(s32 arg0) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates;
u8 *p;
s32 i;
s32 best;
s32 result;
u8 value;
best=0;
result=-1;
p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12) {
if ((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) {
value=p[6];
if(best < (s32)value) {best=value;result=i;}
}
}
return result;
}

s32 func_ov000_021a60d4(s32 arg0) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates;
u8 *p;
s32 i;
s32 best;
s32 result;
u8 value;
best=0x7FFF;
result=-1;
p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12) {
if ((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) {
value=p[8];
if(best > (s32)value) {best=value;result=i;}
}
}
return result;
}

s32 FindAiTargetByCost(s32 arg0) { extern u8 *gAiState; extern M2C_UNK gAiTargetCandidates; 
u8 *p; s32 i; s32 best; s32 result; u8 value;
best=0x7fff; result=-1; p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12) { if((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) { value=p[9]; if(best > (s32)value) {best=value;result=i;} } } return result; }

s32 func_ov000_021a61cc(s32 arg0) { extern u8 *gAiState; extern M2C_UNK gAiTargetCandidates; extern M2C_UNK gAiTargetGroups;
u8 *p; s32 i; s32 best; s32 result; u8 value;
best=0x7fff; result=-1; p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12) { if((u32)p[3]<0xFCU && ((u8 *)&gAiTargetGroups)[(s8)p[4]*8+2] && (arg0==4 || p[2]==arg0)) { value=p[9]; if(best > (s32)value) {best=value;result=i;} } } return result; }

s32 func_ov000_021a6264(s32 arg0) {
extern u8 *gAiState; extern M2C_UNK gAiTargetCandidates;
u8 *p; s32 i,best,result,flag; u8 a,b; s32 n;
best=0x7fff; result=best-0x8000; flag=0; i=0; n=*gAiState; p=(u8 *)&gAiTargetCandidates;
if(n>0) { for(;i<*gAiState;i++,p+=12) { if((u32)p[3]<0xfcU && (arg0==4 || p[2]==arg0)) {
a=p[9]; if(best>=a) { b=p[10]; if(!(best==b && flag==1)) {best=b;result=i;if((u32)b>=(u32)a) flag=1;else flag=0;} }
} } }return result; }

s32 func_ov000_021a6310(s32 a) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates,gAiTargetGroups;
u8 *p; s32 i,best,result,value;
best=0x7fff;result=-1;p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12){
if((u32)p[3]<0xfcU && (a==4 || p[2]==a)){
value=p[7];
if(p[2]==1 && (((u32)((u8 *)&gAiTargetGroups)[(s8)p[4]*8+3]<<29)>>31))value+=255;
if(best>value){best=value;result=i;}
}
}
return result;
}

s32 func_ov000_021a63b8(s32 a,s32 b) {
extern u8 *gAiState;extern M2C_UNK gAiTargetCandidates;
u8 *p; s32 i,best,result;u8 value;
best=0x7fff;result=-1;p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12){
if((u32)p[3]<0xfcU && (a==4 || p[2]==a) && (s8)p[4]==b){
value=p[7];if(best>value){best=value;result=i;}
}}
return result;
}

s32 func_ov000_021a6440(s32 a,s32 b) {
extern u8 *gAiState;extern M2C_UNK gAiTargetCandidates;
u8 *p; s32 i,best,result;u8 value;
best=0;result=-1;p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12){
if((u32)p[3]<0xfcU && (a==4 || p[2]==a) && (s8)p[4]==b){
value=p[6];if(best<value){best=value;result=i;}
}}
return result;
}

s32 func_ov000_021a64c4(void) { extern u8 *gAiState; extern M2C_UNK gAiTargetCandidates; 
u8 *p; s32 i; s32 best; s32 result; s8 value;
best=0; result=-1; p=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,p+=12) { if((u32)p[3]<0xFCU ) { value=(s8)p[5]; if(best < (s32)value) {best=value;result=i;} } } return result; }

#pragma opt_lifetimes off
s32 func_ov000_021a6528(s32 arg0) {
void func_ov000_021a01c0(void); s32 func_ov000_021a6440(s32,s32);
extern u8 *gAiState; extern M2C_UNK gAiTargetGroups;
u8 *p; s32 result; s32 i; s32 r; s32 best;
p=(u8 *)&gAiTargetGroups; best=0; func_ov000_021a01c0();
for(;;) { result=-1; for(i=0;i<(s32)gAiState[1];i++,p+=8) { if(p[1]!=255 && best<(s32)p[0]) { best=p[0];result=i; } } if(result==-1)return -1; r=func_ov000_021a6440(arg0,result); if(r!=-1)return r; p[1]=255; }
}
#pragma opt_lifetimes reset
s32 func_ov000_021a65c4(s32 arg0, s32 arg1) {
    extern u8 *gAiState;
    extern M2C_UNK gAiTargetCandidates;
    u8 *p;
    s32 i;
    s32 best;
    s32 result;
    u8 value;
    best = 0x7fff;
    result = -1;
    p = (u8 *)&gAiTargetCandidates;
    for (i = 0; i < *gAiState; i++, p += 12) {
        if ((u32)p[3] < 0xFCU && (arg0 == 4 || p[2] == arg0) && (s8)p[4] == arg1) {
            value = p[8];
            if (best > (s32)value) {
                best = value;
                result = i;
            }
        }
    }
    return result;
}

s32 func_ov000_021a664c(void) {
void func_ov000_021a01c0(void); s32 func_ov000_021a65c4(s32,s32);
extern u8 *gAiState; extern M2C_UNK gAiTargetGroups;
s32 result; s32 i; s32 r; u8 *p;
p=(u8 *)&gAiTargetGroups; func_ov000_021a01c0();
for(;;) { result=-1; for(i=0;i<(s32)gAiState[1];i++,p+=8) { if(p[1]!=255 && ((Candidate1F14 *)p)->used==0) {result=i;break;} } if(result==-1)return -1; r=func_ov000_021a65c4(1,result); if(r!=-1)return r; p[1]=255; }
}

#pragma optimization_level 3
s32 func_ov000_021a66e8(void) {
void func_ov000_021a01c0(void);
extern M2C_UNK gAiTargetGroups,gAiTargetCandidates;extern u8 *gAiState;extern void **data_027e0058;
u8 *p=(u8 *)&gAiTargetGroups; s32 found,i,r;u8 *entry;void *map;
func_ov000_021a01c0();
for(;;){
found=-1;
for(i=0;i<gAiState[1];i++,p+=8){
if(p[1]!=255 && ((u32)(p[3]<<30)>>31)){found=i;break;}
}
if(found==-1)return -1;
r=func_ov000_021a6440(1,found);
if(r!=-1)r=func_ov000_021a63b8(1,found);
if(r==-1)break;
entry=(u8 *)&gAiTargetCandidates+r*12;map=*data_027e0058;
map=map+entry[0]+M2C_FIELD(map+entry[1]*2,u16 *,0x3758)+0x2000;
if(M2C_FIELD(map,u8 *,0x840)<50 && M2C_FIELD(map,u8 *,0xd48)<50)return r;
p[1]=255;
}
return r;
}
#pragma optimization_level 4
s32 func_ov000_021a67f0(s32 a) {
extern u8 *gAiState;
s32 func_ov000_021a6528(s32);s32 func_ov000_021a6310(s32);
s32 r=-1;
if(gAiState[1]>=2)r=func_ov000_021a6528(a);
if(r==-1)r=func_ov000_021a605c(a);
if(r==-1)r=func_ov000_021a6310(a);
if(r==-1)r=func_ov000_021a5ffc(a);
return r;
}

