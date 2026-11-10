/* 4 functions from 0x0217D86C to 0x0217E798 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6, flags:2; u8 x,y,pad; u16 status; u16 hp:7, other:4, cargo:5; u16 tx:6, ty:6, top:4; u8 a; u8 ammo:4, b:4; u8 c,d; } Unit7DE;
typedef struct { u8 x,y,type,z,cost,other; u8 rest[6]; } Candidate7DE;
typedef struct { u8 kind:6; u8 flags:2; u8 x,y; u8 rest[11]; } Unit7DC;

#pragma opt_strength_reduction off
#pragma opt_lifetimes off
s32 func_ov000_0217d86c(void) {
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    extern u8 data_ov000_021b5c0f[];
    s32 GetUnitAttackClass(void);
    s32 func_ov000_021a9014(s32);
    s32 IsCurrentPlayerUnit(s16);
    s32 IsFootUnitKind(s32);
    void FloodFillUnitRange(s32,s32,s32,s32,s32);

    s32 varc;
    s32 var8 = 0;
    s32 var4 = 0;
    u8 *urec;
    s32 occ;
    u16 stflags;
    void *unit;
    s32 count;
    s32 count2;
    s32 count3;
    u16 height;
    u16 width;
    s32 y;
    s32 x;
    signed char *rowp;
    u16 rowoff;
    u8 tile;
    u16 team;
    u16 f8;
    u32 ukind;
    u32 skind;
    s32 funcRes;

    if (!(( (u32)(M2C_FIELD(data_ov000_021df580, u16 *, 0xa) << 20) >> 29) & 1)) return var8;
    if (!(( (u32)(M2C_FIELD(data_ov000_021df580, u16 *, 0xa) << 26) >> 29) & 4)) return var8;

    unit = M2C_FIELD(*gCurrentMap, void **, 0x52d0);
    if (!(data_ov000_021b5c0f[((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0) << 26) >> 26) * 0x70] & 7)) return var8;
    if (GetUnitAttackClass() != 0) return 0;
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) << 24) >> 31)) return 0;

    FloodFillUnitRange(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 1), M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 2), 7, 0x6e, 0);

    count = 0;
    count2 = 0;
    count3 = 0;
    varc = 0;

    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
            rowp = M2C_FIELD((u8 *)*gCurrentMap + y * 4, signed char **, 0x52e8);
            if (rowp[x] < 0) continue;
            rowoff = M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758);
            tile = M2C_FIELD((u8 *)*gCurrentMap + x + rowoff, u8 *, 0x1420);
            if (func_ov000_021a9014(tile)) {
                tile = M2C_FIELD((u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x1420);
            team = M2C_FIELD(*gCurrentMap, u16 *, 0x52a6);
            if (team != (tile & 0xe0)) continue;
            if ((tile & 0x1f) == 0x11) var4 = 1;
            }
            count++;
            occ = M2C_FIELD((u8 *)*gCurrentMap + x, u8 *, M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758));
            if (occ != 0) {
                if (IsCurrentPlayerUnit((s16)occ) != 0) {
                    urec = (u8 *)*gCurrentMap + 0x59a4 + (s32)occ * 14;
                    f8 = M2C_FIELD(urec, u16 *, 8);
                    if (((u32)(f8 << 16) >> 30) == 2) varc++;
                    if ((u32)(M2C_FIELD(urec, u8 *, 0xb) << 24) >> 31) {
                        count3++;
                        ukind = (((u32)(M2C_FIELD(urec, u8 *, 0) << 26)) >> 26);
                        if (IsFootUnitKind(ukind) != 0) count2++;
                        if (((u32)(M2C_FIELD(urec, u8 *, 0) << 26) >> 26) == 6) var8 = 1;
                    }
                }
            }
        }
    }

    if (count == 0) return 0;
    if (var8 == 0) {
        skind = (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0) << 26)) >> 26);
        if (skind == 6) {
            M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) |= 0x80;
            return 1;
        }
    }
    if (var4 != 0 && varc < 3) return 0;
    skind = (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0) << 26)) >> 26);
    funcRes = IsFootUnitKind(skind);
    if (funcRes != 0) {
        if (count <= 3) { if (count2 == 0) M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) |= 0x80; }
        else if (count2 <= 1) M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) |= 0x80;
    } else {
        if (count <= 3) { if (count3 == 0) M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) |= 0x80; }
        else if (count <= 6) { if ((count3-count2) == 0) M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) |= 0x80; }
        else if ((count3-count2) <= 1) M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) |= 0x80;
    }
    return (u8)(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xb) << 24) >> 31) != 0);
}
#pragma opt_strength_reduction reset
#pragma opt_lifetimes reset
s32 func_ov000_0217dcd0(void){
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
void SelectMapLayer(void *);
s32 func_ov000_02179be0(void);
void FloodFillUnitRange(s32,s32,s32,s32,s32);
void func_01ffb9c4(s8);
s32 IsPlayerActive(s32);
s32 IsSameTeam(u16,s32);
u8 *unit;
s32 p,end,i;
u32 kind;
if(((u32)(**(u8 **)((u8 *)*gCurrentMap+0x52d0)<<26)>>26)!=23)return 0;
SelectMapLayer((u8 *)*gCurrentMap+0x2338);
unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
FloodFillUnitRange(unit[1],unit[2],((Unit7DC *)unit)->kind,func_ov000_02179be0(),1);
func_01ffb9c4(0x6f);
for(p=1;p<5;p++){
if(!IsPlayerActive(p))continue;
if(IsSameTeam(*(u16 *)((u8 *)*gCurrentMap+0x52a4),p)==1)continue;
i=gPlayerUnitIdBase[p]+1;end=gPlayerUnitIdBase[p]+0x33;
for(;i<end;i++){
Unit7DC *entry=&((Unit7DC *)((u8 *)*gCurrentMap+0x59a4))[i];
kind=entry->kind;
if(kind && kind==22 && (*(s8 **)((u8 *)*gCurrentMap+0x52e8+entry->y*4))[entry->x]>=0){
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);return 1;
}
}}
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);return 0;
}

#pragma opt_strength_reduction on
#pragma opt_lifetimes off
s32 func_ov000_0217de64(s32 x,s32 y,s32 kind,s32 extra,s16 *result) {
extern void **gCurrentMap;
extern Candidate7DE gAiTargetCandidates[];
extern s8 data_ov000_021b5500[],gAiRangeLayer[],data_ov000_021b55a0[];
extern u16 gPlayerUnitIdBase[];
extern u8 data_ov000_021dee00[],data_ov000_021dee04[];
void SelectMapLayer(void *);
void FloodFillUnitRange(s32,s32,s32,s32,s32);
s32 IsPlayerActive(s32);
s32 IsSameTeam(u16,s32);
s32 func_020d27ec(s16,u8);
s32 IsFootUnitKind(s32);
s32 func_ov000_021a9a28(s32);
s32 func_ov000_021a8d7c(s32,s32,s32);
void func_ov000_0217a59c(s32,s32,s32,s32);
s32 rowY=y;
u8 *entry;
Candidate7DE *best,*cur,*out=gAiTargetCandidates;
s32 count=0,p,i,j,n,diff,delta,score;
Unit7DE *unit;
u8 *wanted,*types,*cell;
if(func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&4)return 0;
if(((Unit7DE *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->hp<=60)return 0;
for(entry=(u8 *)*gCurrentMap+0x6c60;entry[0]!=255;entry+=6){
if(entry[0]==15){
if(func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&2)continue;
if(func_020d27ec(M2C_FIELD(*gCurrentMap,s16 *,0x52a8),M2C_FIELD((u8 *)*gCurrentMap+(entry[1])+M2C_FIELD((u8 *)*gCurrentMap+(entry[2]*2),u16 *,0x3758),u8 *,0x1420))==0)goto terrain;
goto next;
}else if(!data_ov000_021b5500[entry[0]])continue;
terrain:;
if(M2C_FIELD((u8 *)*gCurrentMap+(entry[1])+M2C_FIELD((u8 *)*gCurrentMap+(entry[2]*2),u16 *,0x3758),u8 *,0x1420)&0xe0)continue;
if(func_ov000_021a8d7c(entry[1],entry[2],5))continue;
for(p=1;p<5;p++){
if(!IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),p)||!IsPlayerActive(p)||M2C_FIELD((u8 *)*gCurrentMap+p*140,u8 *,0x67c2)!=2)continue;
for(i=gPlayerUnitIdBase[p]+1;i<gPlayerUnitIdBase[p]+51;i++){
unit=(Unit7DE *)((u8*)*gCurrentMap+0x59a4+i*14);
if(!unit->kind||!IsFootUnitKind(unit->kind))continue;
if(unit->x==entry[1]&&unit->y==entry[2]){if(unit->cargo)goto next;}
if(unit->hp>60&&unit->tx==entry[1]&&unit->ty==entry[2])goto next;
if(!unit->ammo||unit->tx==63)continue;
SelectMapLayer(gAiRangeLayer);
FloodFillUnitRange(unit->tx,unit->ty,1,3,0);
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);
if(gAiRangeLayer[entry[1]+entry[2]*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]>=0)goto next;
}}
out->x=entry[1];out->y=entry[2];out->type=data_ov000_021b5500[entry[0]];out->z=0;out->other=255;out->cost=255;
func_ov000_0217a59c(entry[1],entry[2],kind,110);
score=M2C_FIELD((u8 *)*gCurrentMap+(x)+M2C_FIELD((u8*)*gCurrentMap+(rowY*2),u16 *,0x3758),s8 *,0x2338);
if(score<0)goto next;
out->cost=score;
if(kind==19)out->cost++;
if(extra)out->cost++;
wanted=data_ov000_021dee00;types=data_ov000_021dee04;
for(j=0;j<4;wanted++,types++,j++){
func_ov000_0217a59c(entry[1],entry[2],*wanted,110);
for(cur=(Candidate7DE *)((u8 *)*gCurrentMap+0x6c60);cur->x!=255;cur=(Candidate7DE *)((u8 *)cur+6)){
u8 *e=(u8 *)cur;
if(data_ov000_021b55a0[e[0]]!=*types)continue;
cell=(u8 *)*gCurrentMap+e[1]+M2C_FIELD((u8 *)*gCurrentMap+(e[2]*2),u16 *,0x3758);
score=M2C_FIELD(cell,u8 *,0x1420)&0xe0;
if(score==0||score==M2C_FIELD(*gCurrentMap,u16 *,0x52a6))continue;
score=M2C_FIELD(cell,s8 *,0x2338);
if(score>=0){n=score+1;if(out->other>=n)out->other=n;}
}
for(p=1;p<5;p++){
if(!IsPlayerActive(p)||p==M2C_FIELD(*gCurrentMap,u16 *,0x52a4))continue;
for(i=gPlayerUnitIdBase[p]+1;i<gPlayerUnitIdBase[p]+51;i++){
unit=(Unit7DE *)((u8 *)*gCurrentMap+0x59a4+i*14);
if(!unit->kind||unit->kind!=*wanted)continue;
score=M2C_FIELD((u8 *)*gCurrentMap+(unit->x)+M2C_FIELD((u8 *)*gCurrentMap+(unit->y*2),u16 *,0x3758),s8 *,0x2338);
if(score<0||(unit->status&8))continue;
if(unit->kind==19){
if(!unit->c&&func_ov000_021a9a28(19))continue;
score=M2C_FIELD((u8 *)*gCurrentMap+(unit->x)+M2C_FIELD((u8 *)*gCurrentMap+(unit->y*2),u16 *,0x3758),s8 *,0x2338)+1;
if(out->other>=score)out->other=score;
}else if(out->other>=score)out->other=score;
}}
}
count++;out++;
next:;
}
if(!count)return 0;
best=0;score=255;
for(i=0,cur=gAiTargetCandidates;i<count;i++,cur++){
if(cur->type>=4)continue;
if(best){
delta=cur->cost-cur->other;
if(score<(delta<0?-delta:delta))continue;
if(delta<0)delta=-delta;
if(score==delta){
if(best->type<cur->type)continue;
if(best->type==cur->type&&best->cost<=cur->cost)continue;
}}
best=cur;delta=cur->cost-cur->other;score=delta<0?-delta:delta;
}
if(!best){
for(i=0,cur=gAiTargetCandidates;i<count;i++,cur++){
if(cur->type<4)continue;
if(best){
delta=cur->cost-cur->other;
if(score<(delta<0?-delta:delta))continue;
if(delta<0)delta=-delta;
if(score==delta){
if(best->type<cur->type)continue;
if(best->type==cur->type&&best->cost<=cur->cost)continue;
}}
best=cur;delta=cur->cost-cur->other;score=delta<0?-delta:delta;
}}
if(!best)return 0;
result[0]=best->x;result[1]=best->y;
return 1;
}
#pragma opt_strength_reduction reset
#pragma opt_lifetimes reset
u8 func_ov000_0217e6bc(s32 arg0,s32 arg1){
s32 ManhattanDistance(u8,u8,s16,s16);extern void **gCurrentMap;extern void *data_ov000_021df580;
u32 base;void **unit,*world,*entry;u8 result;
base=(u32)*gCurrentMap+0x5000;
if(M2C_FIELD(base,u8 *,0x2d6)!=0)goto active;return 1;active:;
unit=M2C_FIELD(base,void **,0x2d0);
if(((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)!=17)return 1;
if(ManhattanDistance(M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2),(s16)arg0,(s16)arg1)<=(s32)(M2C_FIELD(data_ov000_021df580,u8 *,5)*2))return 1;
world=*gCurrentMap;entry=(u8 *)world+0x59a4+M2C_FIELD((u8 *)world+0x5000,u8 *,0x2d6)*14;
if(((u32)(M2C_FIELD(entry,u16 *,6)<<25)>>25)<=30)return 1;
if(((u32)(M2C_FIELD(entry,u8 *,10)<<25)>>25)<=10)result=1;else result=0;
return result;
}
