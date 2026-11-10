/* 2 functions from 0x0219B3C8 to 0x0219B848 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
void func_ov000_0219b3c8(void) {
    void FloodFillUnitRange(s32, s32, s32, s32, s32);
    s32 GetUnitMoveRange(s32, s32);
    void func_ov000_0219c508(void *, s32);
    s32 func_020d27ec(s32, u8);
    s32 func_ov000_021a91d0(s32);
    s32 ManhattanDistance(s16, s16, s16, s16);
    extern void **gCurrentMap;

    void *map;
    void *data;
    u8 *rec;
    s32 sp4;
    register s32 r7, r9, maxDist, r10;
    s16 mapFieldSigned;
    u8 rec_x, rec_y;
    u16 rowVal;
    u8 cellByte;
    s8 *terrainRow;

    data = *gCurrentMap;

    rec = (u8 *)data + 0x6c60;

    sp4 = GetUnitMoveRange(*(u16 *)((u8 *)*gCurrentMap + 0x52a4), 1);

    maxDist = GetUnitMoveRange(*(u16 *)((u8 *)*gCurrentMap + 0x52a4), 2);

    func_ov000_0219c508((u8 *)*gCurrentMap + 0x3250, 0);

    rec -= 6;
    for (;;) {
    rec += 6;
    if (*rec == 0xff) return;
    data = *gCurrentMap;

    mapFieldSigned = *(s16 *)((u8 *)data + 0x52a8);
    rec_x = rec[1];
    rec_y = rec[2];

    rowVal = *(u16 *)((u8 *)data + rec_y * 2 + 0x3758);
    cellByte = *(u8 *)((u8 *)data + rec_x + rowVal + 0x1420);

    if (func_020d27ec(mapFieldSigned, cellByte) == 1) {
        continue;
    }

    FloodFillUnitRange(rec[1], rec[2], 1, sp4, 0);
    data=*gCurrentMap;

    rec_x = rec[1];
    rec_y = rec[2];

    rowVal = *(u16 *)((u8 *)data + rec_y * 2 + 0x3758);
    cellByte = *(u8 *)((u8 *)data + rec_x + rowVal + 0x1420);

    r7 = (func_ov000_021a91d0(cellByte) == 1) ? 8 : 1;

    for (r9 = 0; r9 < *(u16 *)((u8 *)*gCurrentMap + 0x5146); r9++) {
        for (r10 = 0; r10 < *(u16 *)((u8 *)*gCurrentMap + 0x5144); r10++) {
            if ((*(s8 **)((u8 *)*gCurrentMap + r9 * 4 + 0x52e8))[r10] < 0) {
                continue;
            }
            {
                u16 rv = *(u16 *)((u8 *)*gCurrentMap + r9 * 2 + 0x3758);
                s8 *cell = (s8 *)((u8 *)*gCurrentMap + r10 + rv + 0x3250);
                *cell = (s8)(*cell | 0x80);
            }
            if (ManhattanDistance((s16)rec[1], (s16)rec[2], (s16)r10, (s16)r9) <= maxDist) {
            {
                u16 rv = *(u16 *)((u8 *)*gCurrentMap + r9 * 2 + 0x3758);
                s8 *cell = (s8 *)((u8 *)*gCurrentMap + r10 + rv + 0x3250);
                *cell = (s8)(*cell | 0x40);
            }
            }
            {
                u16 rv = *(u16 *)((u8 *)*gCurrentMap + r9 * 2 + 0x3758);
                s32 low = M2C_FIELD((u8 *)*gCurrentMap+r10+rv,u8 *,0x3250)&0x3f;
                if (r7 + low >= 63) {
                    M2C_FIELD((u8 *)*gCurrentMap+r10+rv,s8 *,0x3250) |= 63;
                } else {
                    M2C_FIELD((u8 *)*gCurrentMap+r10+rv,s8 *,0x3250) += r7;
                }
            }
        }
    }
}
}
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
/* Chooses the unit a transport (unit kind 19) at (x, y) should pick up: the
 * farthest idle unit it can carry that stands in the area flooded on the AI
 * range layer (a mech, kind 2, is only taken within two tiles). Returns the
 * unit id, or 0 when there is no candidate. */
s32 SelectTransportTarget(s32 actX, s32 actY) {
 void SelectMapLayer(void *); void FloodFillUnitRange(s32,s32,s32,s32,s32);void func_01ffb9c4(s32);
 s32 CanKindAttack(s32,s32); s32 ManhattanDistance(s16,s16,s16,s16);
 extern u8 gAiRangeLayer[],gUnitKindStats[],gMovementCostTable[];
 extern u16 gPlayerUnitIdBase[];
 extern void **gCurrentMap;
 s32 x=actX,y=actY; u16 best=0; s16 result=0; s32 i; void *map; s8 *costs;
 SelectMapLayer(gAiRangeLayer);
 map=*gCurrentMap;
 /* kind 1's movement type selects the infantry cost row */
 costs=M2C_FIELD(gMovementCostTable,s8 **,0x64)+gUnitKindStats[0x82]*32;
 FloodFillUnitRange(x,y,1,3-costs[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&31],1);
 func_01ffb9c4(0x6f);
 SelectMapLayer((u8 *)*gCurrentMap+MAP_CELL_ORDER);
 for(i=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+0x33;i++) {
 u8 *unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+i*MAP_UNIT_STRIDE;
 u32 kind=(u32)(unit[MAP_UNIT_KIND]<<26)>>26;
 if(kind==0)continue;
 if(!CanKindAttack(19,kind))continue;
 if(((u32)(unit[MAP_UNIT_AI_STATE]<<28)>>28)!=0)continue;
 if(((s8 *)gAiRangeLayer)[unit[MAP_UNIT_Y]*M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)+unit[MAP_UNIT_X]]<0)continue;
 if(((u32)(unit[MAP_UNIT_KIND]<<26)>>26)==2 && ManhattanDistance(x,y,unit[MAP_UNIT_X],unit[MAP_UNIT_Y])>2)continue;
 if(best>ManhattanDistance(x,y,unit[MAP_UNIT_X],unit[MAP_UNIT_Y]))continue;
 best=ManhattanDistance(x,y,unit[MAP_UNIT_X],unit[MAP_UNIT_Y]);result=i;
 }return result;
}
