/* 2 functions from 0x0219B3C8 to 0x0219B848 (ov000), found by ds-decomp. */
#include "common.h"

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
void func_ov000_0219b3c8(void) {
    void func_01ffada0(s32, s32, s32, s32, s32);
    s32 func_ov000_021a97e0(s32, s32);
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

    sp4 = func_ov000_021a97e0(*(u16 *)((u8 *)*gCurrentMap + 0x52a4), 1);

    maxDist = func_ov000_021a97e0(*(u16 *)((u8 *)*gCurrentMap + 0x52a4), 2);

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

    func_01ffada0(rec[1], rec[2], 1, sp4, 0);
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
s32 func_ov000_0219b648(s32 arg0,s32 arg1) {
 void func_01ffb554(void *); void func_01ffada0(s32,s32,s32,s32,s32);void func_01ffb9c4(s32);
 s32 func_ov000_021a9934(s32,s32); s32 ManhattanDistance(s16,s16,s16,s16);
 extern u8 data_ov000_021e0f60[],data_ov000_021b5bfc[],gMovementCostTable[];
 extern u16 gPlayerUnitIdBase[];
 extern void **gCurrentMap;
 s32 x=arg0,y=arg1; u16 best=0; s16 result=0; s32 i; void *map; s8 *costs;
 func_01ffb554(data_ov000_021e0f60);
 map=*gCurrentMap;
 costs=M2C_FIELD(gMovementCostTable,s8 **,0x64)+data_ov000_021b5bfc[0x82]*32;
 func_01ffada0(x,y,1,3-costs[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,0x3758)),u8 *,0x1420)&31],1);
 func_01ffb9c4(0x6f);
 func_01ffb554((u8 *)*gCurrentMap+0x1e30);
 for(i=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
 u8 *unit=(u8 *)*gCurrentMap+0x59a4+i*14;
 u32 kind=(u32)(unit[0]<<26)>>26;
 if(kind==0)continue;
 if(!func_ov000_021a9934(19,kind))continue;
 if(((u32)(unit[11]<<28)>>28)!=0)continue;
 if(((s8 *)data_ov000_021e0f60)[unit[2]*M2C_FIELD(*gCurrentMap,u16 *,0x5144)+unit[1]]<0)continue;
 if(((u32)(unit[0]<<26)>>26)==2 && ManhattanDistance(x,y,unit[1],unit[2])>2)continue;
 if(best>ManhattanDistance(x,y,unit[1],unit[2]))continue;
 best=ManhattanDistance(x,y,unit[1],unit[2]);result=i;
 }return result;
}
