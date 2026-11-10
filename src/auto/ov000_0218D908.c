/* 4 functions from 0x0218D908 to 0x0218E584 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct {u8 pad[0x58];u16 row;} ScanRow;
static inline s32 ScanUnitIndex(u8 *unit,u8 *map){if(unit==0)return 0;return (s32)(unit-(map+0x59a4))/14;}
static inline s32 ScanAdjacentCount(u8 *unit){
extern void **gCurrentMap;s32 ex,ey,xmin,ymin,xmax,ymax,nx,ny,d,count=0;s32 zero=0;void **owner;u8 *map,*other;u32 index;
ex=unit[1];ey=unit[2];xmin=ex-1;if(xmin<0)xmin=0;ymin=ey-1;if(ymin<0)ymin=0;
owner=gCurrentMap;map=*owner;
xmax=M2C_FIELD(map,u16 *,0x5144)-1;if(ex+1<xmax)xmax=ex+1;
ymax=M2C_FIELD(map,u16 *,0x5146)-1;if(ey+1<ymax)ymax=ey+1;
for(ny=ymin;ny<=ymax;ny++)for(nx=xmin;nx<=xmax;nx++){
d=zero;if(ex-nx>0)d+=ex-nx;else d+=nx-ex;if(ey-ny>0)d+=ey-ny;else d+=ny-ey;
if(d<1||d>1)continue;
map=*owner;if(M2C_FIELD(M2C_FIELD(map+ny*4,s8 **,0x52e8),s8 *,nx)<0)continue;
index=M2C_FIELD(map+M2C_FIELD(map+ny*2,u16 *,0x3758)+nx,u8 *,0);
other=map+0x59a4+index*14;
if(((u32)(other[0]<<26)>>26)!=0&&(M2C_FIELD(other,u16 *,4)&1))continue;
count++;
}return count;
}
static inline u16 ScanHeight(void *p){return M2C_FIELD(p,u16 *,0x5146);}

#pragma opt_strength_reduction off
/* Chooses a reachable recovery destination, preferring a suitable transport or a low-score tile. */
void func_ov000_0218d908(void) {
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    extern u8 *data_ov000_021df644;
    extern u8 data_ov000_021b5bfc[], data_ov000_021dfcf0[];
    s32 func_ov000_0218d40c(void);
    M2C_UNK func_01ffc328(s32);
    s32 func_ov000_021a9934(s32, s32);
    s32 func_ov000_021a8fc0(s16);
    s32 func_ov000_021a995c(void *, s32);
    s32 func_ov000_021a9214(void *, s32, s32);
    s32 func_ov000_021a93a8(void *, s32, s32);
    s32 func_ov000_021a9d8c(s16, s16);
    s32 func_ov000_02178778(s16, s16);
    s32 func_ov000_02178e84(s16, s16);
    s32 CellMoveScore(s32, s32, s32, s32);
    void func_ov000_0217c3a4(void);
    M2C_UNK SetMapCursor(s16, s16, M2C_UNK, u8, s32);
    s32 bestX = -1, bestY = -1, bestScore = 0x7fffffff, bestCost = 0x7fff, useTransport = 0;
    u8 *unit;
    s32 y, x;
    void *map;
    s32 score, moveCost;

    if (!func_ov000_0218d40c()) return;
    func_01ffc328(M2C_FIELD(*gCurrentMap, s32 *, 0x52d0));
    y = 0;
    map = *gCurrentMap;
    while (y < M2C_FIELD(map, u16 *, 0x5146)) {
        x = 0;
        if (x < M2C_FIELD(map, u16 *, 0x5144)) {
            do {
                s8 *costRow = M2C_FIELD((u8 *)map + y * 4, s8 **, 0x52e8);
                u16 flags;
                if (costRow[x] < 0) goto nextTile;
                flags = M2C_FIELD(data_ov000_021df580, u16 *, 8);
                if (flags & 1) {
                    if (M2C_FIELD((u8 *)map + x + M2C_FIELD((u8 *)map + y * 2, u16 *, 0x3758), s8 *, 0x2338) < 0) {
                        costRow[x] = -1;
                        goto nextTile;
                    }
                }
                if (!(flags & 0x101) && func_ov000_021a9934(21, (u32)(M2C_FIELD(M2C_FIELD(map, void **, 0x52d0), u8 *, 0) << 26) >> 26)) {
                    map = *gCurrentMap;
                    unit = (u8 *)map + 0x59a4 + (s16)M2C_FIELD((u8 *)map + x + M2C_FIELD((u8 *)map + y * 2, u16 *, 0x3758), u8 *, 0) * 14;
                    if (unit && func_ov000_021a8fc0((s16)(unit ? (unit - ((u8 *)map + 0x59a4)) / 14 : 0)) && ((u32)(unit[0] << 26) >> 26) == 21 && func_ov000_021a995c(unit, (u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0) << 26) >> 26)) {
                        if (useTransport && M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52e8)[x] > bestCost) goto nextTile;
                        bestX = x;
                        bestY = y;
                        bestCost = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52e8)[x];
                        bestScore = 0;
                        useTransport = 1;
                        goto nextTile;
                    }
                }
                if (!func_ov000_021a9214(M2C_FIELD(*gCurrentMap, void **, 0x52d0), x, y) && !func_ov000_021a93a8(M2C_FIELD(*gCurrentMap, void **, 0x52d0), x, y)) goto nextTile;
                if (func_ov000_021a9d8c((s16)x, (s16)y)) goto nextTile;
                if (func_ov000_02178778((s16)x, (s16)y) == 1) goto nextTile;
                if (!func_ov000_02178e84((s16)x, (s16)y)) goto nextTile;
                map = *gCurrentMap;
                if (M2C_FIELD((u8 *)map + x + M2C_FIELD((u8 *)map + y * 2, u16 *, 0x3758), u8 *, 0x2d48) >= data_ov000_021df644[2]) goto nextTile;
                if (data_ov000_021b5bfc[((u32)(M2C_FIELD(M2C_FIELD(map, void **, 0x52d0), u8 *, 0) << 26) >> 26) * 112 + 19] & 7) {
                    u32 tileIndex = y * M2C_FIELD(map, u16 *, 0x5144) + x;
                    u32 bit = tileIndex & 7;
                    if (!(u8)((1 << bit) & data_ov000_021dfcf0[tileIndex >> 3])) goto nextTile;
                }
                score = CellMoveScore(x, y, 1, 2);
                moveCost = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52e8)[x];
                if (score > bestScore) goto nextTile;
                if (score == bestScore && moveCost > bestCost) goto nextTile;
                bestScore = score;
                bestCost = moveCost;
                bestX = x;
                bestY = y;
                useTransport = 0;
nextTile:
                x++;
                map = *gCurrentMap;
            } while (x < M2C_FIELD(map, u16 *, 0x5144));
        }
        y++;
    }
    if (bestX == -1) return;
    {
        u8 *state = data_ov000_021df580;
        u16 flags = M2C_FIELD(state, u16 *, 8);
        if (flags & 1) {
            unit = M2C_FIELD(map, u8 **, 0x52d0);
            if (bestX == unit[1] && bestY == unit[2]) {
                M2C_FIELD(state, u16 *, 8) = flags | 2;
                return;
            }
        }
    }
    func_ov000_0217c3a4();
    if (useTransport) SetMapCursor((s16)bestX, (s16)bestY, 7, 0, 0);
    else SetMapCursor((s16)bestX, (s16)bestY, 2, 0, 0);
}
#pragma opt_strength_reduction reset
void func_ov000_0218dda4(void) {
    M2C_UNK func_01ffc328(s32);
    M2C_UNK SetMapCursor(s16, s16, M2C_UNK, u8, s32);
    s32 func_ov000_021aa820(s16 *, u16, M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    void **owner;
    s16 pos[2];
    s32 var_r3;
    s32 var_r2;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s8 *temp_r8;
    s8 *var_lr;
    s8 temp_r0_2;
    u16 temp_ip;
    void *temp_r7;
    void *temp_r0;

    var_r5 = -1;
    var_r4 = -1;
    var_r6 = -1;
    func_01ffc328(M2C_FIELD(*gCurrentMap, s32 *, 0x52D0));
    var_r3 = 0;
    owner=gCurrentMap;
    temp_r7 = *owner;
    if ((s32) M2C_FIELD(temp_r7, u16 *, 0x5146) > 0) {
        temp_ip = M2C_FIELD(temp_r7, u16 *, 0x5144);
        do {
            var_r2 = 0;
            if ((s32) temp_ip > 0) {
                temp_r8 = M2C_FIELD((temp_r7 + ((u32)var_r3 << 2)), s8 **, 0x52E8);
                var_lr = temp_r8;
                do {
                    if ((s32) *var_lr >= 0) {
                        temp_r0 = temp_r7 + ((ScanRow *)(temp_r7 + ((u32)var_r3 << 1) + 0x3700))->row + var_r2;
                        if (((M2C_FIELD(temp_r0, u8 *, 0x1420) & 0x1F) == 0x18) && (M2C_FIELD(temp_r0, u8 *, 0) == 0)) {
                            temp_r0_2 = *(temp_r8 + var_r2);
                            if ((s32) temp_r0_2 > var_r6) {
                                var_r4 = var_r2;
                                var_r5 = var_r3;
                                var_r6 = (s32) temp_r0_2;
                            }
                        }
                    }
                    var_r2 += 1;
                    var_lr += 1;
                } while (var_r2 < (s32) temp_ip);
            }
            var_r3 += 1;
        } while (var_r3 < (s32) ScanHeight(temp_r7));
    }
    if (var_r6 == -1) {
        return;
    }
    pos[0] = (s16) var_r4;
    pos[1] = (s16) var_r5;
    if (func_ov000_021aa820(pos, M2C_FIELD(*owner, u16 *, 0x52A4), 1, 0) != 1) {
        return;
    }
    SetMapCursor((s16) var_r4, (s16) var_r5, 0x13, (u8) pos[0], (s32) (u8) pos[1]);
}

#pragma opt_strength_reduction off
void func_ov000_0218df00(void){
#pragma opt_strength_reduction off

M2C_UNK func_01ffc328(s32);void func_01ffb9c4(s8);s32 func_ov000_021a98e4(s32);s32 func_020d27a4(s32,s32);s32 func_ov000_021a93ec(s16,s16);s32 func_ov000_02177f24(s32,s32,s16 *);s32 func_ov000_02176e28(s32,void *);s32 func_ov000_0217a0a8(void *);s32 SetMapCursor(s16,s16,s32,u8,s32);
extern void **gCurrentMap;extern void *data_ov000_021df580;
s32 bestY,bestX,bestScore,score,temp,y,x; s32 count,index;u8 *map,*unit,*selected;s16 position[2];
bestY=-1;bestScore=0;bestX=-1;temp=0;
map=*gCurrentMap;selected=M2C_FIELD(map,u8 **,0x52d0);
if(func_ov000_021a98e4((u32)(selected[0]<<26)>>26))return;
func_01ffc328(M2C_FIELD(*gCurrentMap,s32 *,0x52d0));func_01ffb9c4(111);
map=*gCurrentMap;
for(y=0;y<M2C_FIELD(map,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(map,u16 *,0x5144);){
if(M2C_FIELD(M2C_FIELD(map+y*4,s8 **,0x52e8),s8 *,x)<0)goto next_cell;
index=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
unit=map+0x59a4+(s16)index*(s16)14;
if(((u32)(unit[0]<<26)>>26)==0)goto next_cell;
if(func_020d27a4(M2C_FIELD(map,u8 *,0x52d4),unit?(s32)(unit-(map+0x59a4))/14:0)==1)goto next_cell;
if(!func_ov000_021a93ec(x,y))goto next_cell;
if(!func_ov000_02177f24(x,y,position))goto next_cell;
map=*gCurrentMap;index=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
score=func_ov000_02176e28(index|0x10000,position);
if(!score||score<bestScore)goto next_cell;
if(func_ov000_0217a0a8(unit)==1){count=ScanAdjacentCount(unit);if(count<=1)goto next_cell;}
bestScore=score;bestY=position[0];bestX=position[1];map=*gCurrentMap;
temp=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
next_cell:x++;map=*gCurrentMap;
}
}
if(!bestScore)return;
M2C_FIELD(data_ov000_021df580,u8 *,7)&=~2;
map=*gCurrentMap;selected=M2C_FIELD(map,u8 **,0x52d0);M2C_FIELD(selected,u16 *,8)&=~0x3000;
SetMapCursor((s16)bestY,(s16)bestX,4,(u8)temp,0);

#pragma opt_strength_reduction reset
}

#pragma push
#pragma opt_propagation off
void func_ov000_0218e340(void) {
extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
M2C_UNK func_01ffc328(s32); s32 func_020a7074(void *,void *); s32 func_ov000_021a93a8(void *,s32,s32); s32 func_020a7cfc(void *); s32 func_ov000_021a98a8(s32); void func_ov000_0218dda4(void); M2C_UNK SetMapCursor(s16,s16,s32,u8,s32);
s32 x=-1,y=-1,best=0,i; u8 *unit; s32 offset; void *map; u8 *active; s32 hp,other,score;
map=*gCurrentMap; active=M2C_FIELD(map,u8 **,0x52d0);
if (((u32)(M2C_FIELD(active,u16 *,6)<<25)>>25)>50) return;
if(active[12])return;
func_01ffc328((s32)active);
map=*gCurrentMap;
i=gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+1;
if(i<gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+51){
offset=i*14;
do {
unit=(u8 *)((s32)map+0x59a4)+offset;
if(!((u32)(unit[0]<<26)>>26))goto next;
if(M2C_FIELD((u8 *)map+unit[2]*4,s8 **,0x52e8)[unit[1]]<0)goto next;
active=M2C_FIELD(map,u8 **,0x52d0);
if(active==unit)goto next;
if(M2C_FIELD(unit,u16 *,4)&8)goto next;
if(!func_020a7074(active,unit))goto next;
if(func_ov000_021a93a8(unit,unit[1],unit[2])==1)goto next;
if(func_020a7cfc(M2C_FIELD(*gCurrentMap,void **,0x52d0))){
hp=(u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25;
other=(u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25;
score=other+hp; if(score<=130)goto evaluate;
goto next;
}else{
hp=(u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25;
other=(u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25;
score=other+hp; if(score>110)goto next;
}
evaluate:
if(score>100)score=300-other+hp;
if(score>=best){x=unit[1];y=unit[2];best=score;}
next:
i++;offset+=14;map=*gCurrentMap;
}while(i<gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+51);
}
if(x==-1)return;
if(func_ov000_021a98a8((u32)(M2C_FIELD(M2C_FIELD(map,void **,0x52d0),u8 *,0)<<26)>>26))func_ov000_0218dda4();
active=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
M2C_FIELD(active,u16 *,8)&=~0x3000;
SetMapCursor((s16)x,(s16)y,9,0,0);
}
#pragma pop
