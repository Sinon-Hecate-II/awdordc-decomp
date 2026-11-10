/* 14 functions from 0x020CD8A8 to 0x020CE738 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

#pragma push
#pragma opt_propagation off
/* At the start of a turn, decide which side (team) each player fights for
 * (PLAYER_SIDE_OFF). All sides are cleared first; the active player's side comes
 * from gSideByControlKind looked up by its control kind (a CPU is team A, a human
 * team A with the human flag), and its same-army allies inherit it. Once the
 * remaining humans all share one team the other armies get the opposite side.
 * Finally the two team slots (MAP_TEAM_A_PLAYER / MAP_TEAM_B_PLAYER) are reset to
 * players 0 and 1, the players whose army lists the two teams share. */
void SetupPlayerTeams(void) {
    s32 GetPlayerRelation(u16, u16);
    s32 PlayerHasHumanAlly(s32);
    void SetAllyTeamColor(s32, s32);
    s32 HumansShareOneTeam(s32);
    s32 IsPlayerActive(s32);
    s32 IsPlayerHuman(s32);
    extern u16 gSideByControlKind[];
    extern void **gCurrentMap;
    s32 opposingColor;
    s32 activeRecord;
    s32 k;
    s32 otherIndex;
    s32 clearSlot;
    s32 slotOffset;
    u16 opponent;
    s32 m;
    s32 teammate;
    s32 nextIndex;
    u16 activeIndex;
    u16 activePlayer;
    u16 activeIndex2;

    u16 teamColor;
    u16 scanSlot;
    void *mapFinal;
    void *mapActive;
    void *mapLast;
    void *mapStore;

    clearSlot = 1;
    slotOffset = MAP_PLAYER_STRIDE;
    M2C_FIELD(*gCurrentMap, s8 *, PLAYER_SIDE_OFF) = 0;
    do {
        clearSlot += 1;
        M2C_FIELD((*gCurrentMap + slotOffset), s8 *, PLAYER_SIDE_OFF) = 0;
        slotOffset += MAP_PLAYER_STRIDE;
    } while (clearSlot < 5);
    mapActive = *gCurrentMap;
    teamColor = gSideByControlKind[M2C_FIELD(((M2C_FIELD(mapActive, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE) + (s32) mapActive), u8 *, PLAYER_CONTROL_OFF)];
    if ((teamColor == 1) && (PlayerHasHumanAlly(M2C_FIELD(mapActive,u16 *,MAP_CURRENT_PLAYER)) != 0)) {
        teamColor |= 2;
    }
    mapStore = *gCurrentMap;
    activeIndex=M2C_FIELD(mapStore,u16 *,MAP_CURRENT_PLAYER);
    M2C_FIELD(((activeIndex * MAP_PLAYER_STRIDE) + (s32) mapStore), s8 *, PLAYER_SIDE_OFF) = (s8) teamColor;
    SetAllyTeamColor(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), teamColor);
    if (HumansShareOneTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) != 0) {
        opposingColor = teamColor ^ 3;
        k = 1;
        do {
            activePlayer = M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER);
            otherIndex = activePlayer + k;
            if (otherIndex >= 5) {
                otherIndex -= 4;
            }
            opponent = (u16) otherIndex;
            if ((GetPlayerRelation(activePlayer, opponent) == 1) && (IsPlayerHuman(opponent) != 0)) {
                nextIndex = opponent + 1;
                M2C_FIELD(((opponent * MAP_PLAYER_STRIDE) + (s32) *gCurrentMap), u8 *, PLAYER_SIDE_OFF) = (u8) opposingColor;
                m = 1;
                do {
                    teammate = nextIndex;
                    if (nextIndex >= 5) {
                        teammate = nextIndex - 4;
                    }
                    if (GetPlayerRelation(opponent, (u16) teammate) == 2) {
                        M2C_FIELD(((teammate * MAP_PLAYER_STRIDE) + (s32) *gCurrentMap), u8 *, PLAYER_SIDE_OFF) = (u8) opposingColor;
                    }
                    m += 1;
                    nextIndex += 1;
                } while (m < 4);
            }
            k += 1;
        } while (k < 4);
    }
    scanSlot = 1;
loop_19:
    if (scanSlot == 5) {
        mapLast = *gCurrentMap;
        activeRecord = (M2C_FIELD(mapLast, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE) + (s32) (mapLast + MAP_PLAYER_STATES);
        M2C_FIELD(activeRecord, u8 *, PLAYER_REC_SIDE) = (u8) (M2C_FIELD(activeRecord, u8 *, PLAYER_REC_SIDE) | 2);
        mapFinal = *gCurrentMap;
        activeIndex2 = M2C_FIELD(mapFinal, u16 *, MAP_CURRENT_PLAYER);
        SetAllyTeamColor(activeIndex2, M2C_FIELD(((activeIndex2 * MAP_PLAYER_STRIDE) + (s32) mapFinal), u8 *, PLAYER_SIDE_OFF));
    } else if (((IsPlayerActive(scanSlot) == 0) || (IsPlayerHuman(scanSlot) == 0)) && ((IsPlayerActive(scanSlot) == 0) || !(M2C_FIELD(((scanSlot * MAP_PLAYER_STRIDE) + (s32) *gCurrentMap), u8 *, PLAYER_SIDE_OFF) & 2))) {
        scanSlot += 1;
        if ((u32) scanSlot < 6U) {
            goto loop_19;
        }
    }
    M2C_FIELD(*gCurrentMap, s16 *, MAP_TEAM_A_PLAYER) = 0;
    M2C_FIELD(*gCurrentMap, s16 *, MAP_TEAM_B_PLAYER) = 1;
}
#pragma pop
void SetAllyTeamColor(s32 a, s32 b) {
    s32 GetPlayerRelation(u16, u16);
    extern void **gCurrentMap;
    s32 i;
    s32 j;
    u16 id;
    u8 v;
    i = 1;
    id = (u16)a;
    v = (u8)b;
    do {
        j = a + i;
        if (j >= 5) j -= 4;
        if (GetPlayerRelation(id, (u16)j) == 2) {
            M2C_FIELD(*gCurrentMap + j * 140, u8 *, 0x67c3) = v;
        }
        i++;
    } while (i < 4);
}
#pragma scheduling reset
s32 HumansShareOneTeam(s32 a){s32 IsPlayerActive(s32);s32 IsPlayerHuman(s32);extern void **gCurrentMap;s32 count;u8 team;s32 i,off,own;u8 v;s32 p,q;if(IsPlayerHuman(a))return 0;off=140;own=a*140;team=0;count=0;i=1;do{if(IsPlayerActive(i)&&i!=a){if(count==0){if(IsPlayerHuman(i)){p=(s32)*gCurrentMap;v=M2C_FIELD(p+off,u8 *,0x67ca);if(v!=M2C_FIELD(own+p,u8 *,0x67ca)){team=v;count++;}}}else if(IsPlayerHuman(i)){q=(s32)*gCurrentMap;v=M2C_FIELD(q+off,u8 *,0x67ca);if(team!=v&&v!=M2C_FIELD(own+q,u8 *,0x67ca))return 0;}}i++;off+=140;}while(i<5);return 1;}

#pragma opt_strength_reduction off
void func_020cdcc4(s32 a,s32 b,s16 r,s32 v){
extern void **gCurrentMap;s32 func_020a4828(s32,s32);void func_020d1690(s32,s32,void *);s32 func_020d27a4(s32,s32);void func_020d166c(s32,s32,void *);
s32 neg,y,d,x;s32 id;void *p;
for(d=(s16)-r,y=(s16)(b-r);y<=b+r;y=(s16)(y+1),d=(s16)(d+1)){
if(y<0||y>=M2C_FIELD(*gCurrentMap,u16 *,0x5146))continue;
for(x=(s16)(a-r+(d<0?-d:d)),neg=-d;x<=a+r-(d<0?neg:d);x=(s16)(x+1)){
if(x<0||x>=M2C_FIELD(*gCurrentMap,u16 *,0x5144))continue;
id=func_020a4828(x,y);
if(id){p=*gCurrentMap;func_020d1690(M2C_FIELD(p,u8 *,0x52d4),id,p+0x52dc);
if(M2C_FIELD(*gCurrentMap,s16 *,0x6ed6))M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x]=(s8)v;
}else{
p=*gCurrentMap;
id=M2C_FIELD(p+x+M2C_FIELD(p+y*2,u16 *,0x3758),u8 *,0);
if(id&&func_020d27a4(M2C_FIELD(p,u8 *,0x52d4),id)!=1){
p=*gCurrentMap;func_020d166c(M2C_FIELD(p,u8 *,0x52d4),id,p+0x52dc);
if(M2C_FIELD(*gCurrentMap,s16 *,0x6ed6))M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x]=(s8)v;
}
}
}}
}
#pragma opt_strength_reduction reset
void func_020cdeac(s32 a,s32 b,u8 *p) {
s32 func_020a76d4(u8 *);
extern u8 gUnitMinAttackRange,data_ov000_021b5c09;s32 off;
func_020cdcc4(a,b,(s16)func_020a76d4(p),0);
off=((u32)(*p<<26)>>26)*112;
if(*(&data_ov000_021b5c09+off)==1)return;
func_020cdcc4(a,b,(s16)(*(&gUnitMinAttackRange+off)-1),-1);
}

void func_020cdf30(s32 x,s32 y,s32 f) {
extern void **gCurrentMap;
if(f&4)M2C_FIELD(*gCurrentMap+y*4,u8 **,0x52e8)[x-1]=0;
if(f&8)M2C_FIELD(*gCurrentMap+y*4,u8 **,0x52e8)[x+1]=0;
if(f&1)M2C_FIELD(*gCurrentMap+(y-1)*4,u8 **,0x52e8)[x]=0;
if(f&2)M2C_FIELD(*gCurrentMap+(y+1)*4,u8 **,0x52e8)[x]=0;
}

// Clears the walkable-flag (sets to 0) of each in-bounds neighbor of (x,y) that the given unit can enter.
void func_020cdfec(s32 unit, s32 x, s32 y) {
    s32 func_020ba448(s32, s32, s32);
    extern void **gCurrentMap;
    if (func_020ba448(unit, x, y - 1)) {
        M2C_FIELD(*gCurrentMap + (y - 1) * 4, u8 **, 0x52e8)[x] = 0;
    }
    if (func_020ba448(unit, x - 1, y)) {
        M2C_FIELD(*gCurrentMap + y * 4, u8 **, 0x52e8)[x - 1] = 0;
    }
    if (func_020ba448(unit, x, y + 1)) {
        M2C_FIELD(*gCurrentMap + (y + 1) * 4, u8 **, 0x52e8)[x] = 0;
    }
    if (func_020ba448(unit, x + 1, y)) {
        M2C_FIELD(*gCurrentMap + y * 4, u8 **, 0x52e8)[x + 1] = 0;
    }
}

s32 func_020ce0ec(s32 a,s32 b) {
s32 IsSameTeam(s32,s32);
extern s8 data_ov000_021b5540[],gTerrainPropertyFlags[];
s32 i=b&31,v;
if(data_ov000_021b5540[i])return 1;
if(gTerrainPropertyFlags[i]){v=(b&224)>>5;if(!v)return 1;if(!IsSameTeam(v,a))return 1;}
return 0;
}

#pragma push
#pragma opt_common_subs off
void MarkThreatCells(s32 a,s32 b,s32 c,u8 d,s32 e,s32 f) {
s32 func_020ce0ec(s32,s32);
s32 func_020a8528(s32);
extern void **gCurrentMap;
extern s8 data_ov000_021b5680[];
s32 offset;
s32 rowdist;
s16 x,y,dy;
s32 xmin,xmax,ymax,negdist;
u32 index;
u8 *map;
u8 *bitmap;
u8 unit;
s32 distance; s32 row; s32 absrow;
if(c==0){
map=*gCurrentMap;
bitmap=map+0x5160+d*0xa1;
index=a+M2C_FIELD(map+b*2,u16 *,0x3758);
bitmap[index>>3]|=1<<(index&7);
return;
}
dy=-c;
y=b-c;
ymax=b+c;
if(y>ymax)return;
offset=d*0xa1;
xmin=a-c;
xmax=a+c;
do {
if(y<0||y>=M2C_FIELD(*gCurrentMap,u16 *,0x5146))goto nextrow;
x=xmin+(dy<0?-dy:dy);
rowdist=y-b;
negdist=-rowdist;
for(;x<=xmax-(dy<0?-dy:dy);x=(s16)(x+1)){
if(x<0||x>=M2C_FIELD(*gCurrentMap,u16 *,0x5144))continue;
map=*gCurrentMap;
row=M2C_FIELD(map+y*2,u16 *,0x3758);
index=x+row;
if((u8)(M2C_FIELD(offset+map+(index>>3),u8 *,0x5160)&(1<<(index&7))))continue;
if(f!=2){
absrow=rowdist<0?negdist:rowdist;
distance=x-a;if(distance<0)distance=-distance;
if(distance+absrow<=1){
if(f!=1)goto mark;
if(!func_020ce0ec(e,M2C_FIELD(row+(map+x),u8 *,0x1420)))goto mark;
}
map=*gCurrentMap;
unit=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x508);
if(unit==0)continue;
if(!func_020a8528((u32)(M2C_FIELD(map+unit*14,u8 *,0x59a4)<<26)>>26))continue;
map=*gCurrentMap;
if(data_ov000_021b5680[M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420)&31])continue;
}
mark:
map=*gCurrentMap;
index=x+M2C_FIELD(map+y*2,u16 *,0x3758);
bitmap=map+offset+(index>>3);
M2C_FIELD(bitmap,u8 *,0x5160)|=1<<(index&7);
}
nextrow:
y=(s16)(y+1);dy=(s16)(dy+1);
}while(y<=ymax);
}
#pragma pop
void MarkThreatBitmap(M2C_UNK a,M2C_UNK b,M2C_UNK c,u32 d,u8 e,u8 f){void MarkThreatCells(M2C_UNK,M2C_UNK,M2C_UNK,u8,s32,s32);extern void **gCurrentMap;switch(d){case 1:MarkThreatCells(a,b,c,(u8)M2C_FIELD(*gCurrentMap,u16 *,0x52b8),e,f);return;case 3:MarkThreatCells(a,b,c,(u8)M2C_FIELD(*gCurrentMap,u16 *,0x52b8),e,f);case 2:MarkThreatCells(a,b,c,(u8)M2C_FIELD(*gCurrentMap,u16 *,0x52ba),e,f);case 0:default:break;}}

void func_020ce508(void *p,s32 x,s32 y) {
s32 GetUnitOwner(void *),func_020a33c4(s32),func_020a27f8(s32,s32),func_020a7824(void *,s32,s32);
extern void **gCurrentMap;
s32 player=GetUnitOwner(p);
s32 flag;
s32 allowed;
s32 value;
if(((u32)(M2C_FIELD(p,u8 *,0)<<26)>>26)==0)return;
if((M2C_FIELD(p,u16 *,4)&2)&&!(M2C_FIELD(p,u16 *,4)&4))return;
flag=0;allowed=0;
if(((u32)(M2C_FIELD(*gCurrentMap+player*140,s32 *,0x6810)<<24)>>24)==3) {if(func_020a33c4(player))allowed=1;}
if(allowed) {if(func_020a27f8((u32)(M2C_FIELD(p,u8 *,0)<<26)>>26,player))flag=2;}
value=func_020a7824(p,x,y);
MarkThreatBitmap((s16)x,(s16)y,(s16)value,M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67c3),(u8)player,(u8)flag);
}

void MarkUnitThreatRange(void *arg0) {
    void func_020ce508(void *, s32, s32);
    func_020ce508(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

void func_020ce630(s16 a, s16 b, s8 *c) {
void func_020ce508(void *, s32, s32);
extern void **gCurrentMap;
s16 x=a,y=b; s8 *p=c;
for (;;) {
switch (*p++ + 1) {
case 1: x--; break;
case 2: x++; break;
case 4: y--; break;
case 3: y++; break;
case 0: case 5: case 11: return;
default: break;
}
func_020ce508(M2C_FIELD(*gCurrentMap, void **, 0x52d0),x,y);
}
}

s32 GetTerrainThreatRadius(s32 a,s32 b) {
extern s8 gTerrainPropertyFlags[];
if(b==2)return 0;b=a&31;if(b==26)return 5;if(b==23)return 5;return gTerrainPropertyFlags[b]?2:0;
}

