/* 3 functions from 0x0218A9AC to 0x0218B0D8 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; } UnitKind0218;
extern void **gCurrentMap;
extern void *data_ov000_021df580;
extern void (*data_ov000_021df654)(void);
void func_ov000_0217c3a4(void);
void func_ov000_0218d040(int);
void func_ov000_0218d908(void);
void func_ov000_02198c08(void);
void SetMapCursor(int, int, int, int, int);

#pragma opt_strength_reduction off
void func_ov000_0218ae58(void) {
    s32 func_ov000_021a9740(void *, s32);
    void func_01ffada0(s32, s32, u8, s32, s32);
    void func_01ffb9c4(s8);
    s32 func_020a47e0(s32, s32);
    s32 func_ov000_021a9bc0(void);
    s32 func_ov000_0217aa2c(s32, s32);
    s32 func_ov000_02179e48(void *);
    s32 func_ov000_0217e6bc(s32, s32);
    void PlanMoveDestination(s32, s32);

    extern void **gCurrentMap;
    extern void *data_ov000_021df580;

    register s32 best asm("r7") = 0x7fff;
    s16 cand[2];
    s32 x;
    s32 y;

    {
        void *unit;
        unit = *(void **)(((u8 *)*gCurrentMap) + 0x52d0);
        if (func_ov000_021a9740(unit, 1) < 10) return;

        unit = *(void **)(((u8 *)*gCurrentMap) + 0x52d0);
        func_01ffada0(
            ((u8 *)unit)[1],
            ((u8 *)unit)[2],
            ((UnitKind0218 *)unit)->kind,
            0x6e,
            1);
        func_01ffb9c4(0x6f);
    }

    for (y = 0; y < *(u16 *)((u8 *)*gCurrentMap + 0x5146); y++) {
        for (x = 0; x < *(u16 *)((u8 *)*gCurrentMap + 0x5144); x++) {
            s8 *row;
            s8 cell;
            u16 rowOff;
            u8 flags;

            row = *(s8 **)(((u8 *)*gCurrentMap) + 0x52e8 + y * 4);
            cell = row[x];
            if (cell < 0) continue;

            rowOff = *(u16 *)((u8 *)*gCurrentMap + 0x3758 + y * 2);
            flags = *(u8 *)((u8 *)*gCurrentMap + x + rowOff + 0x539c);

            if ((flags & 0x7f) != 0) {
                if ((((u32)((u8 *)data_ov000_021df580)[7]) << 29 >> 31)) goto evaluate;
                goto next;
            }
            if (!func_020a47e0(x, y)) goto next;
            if (!func_ov000_021a9bc0()) goto next;
evaluate:
            {
                s32 score = func_ov000_0217aa2c(x, y);
                if (score < best) {
                    best = score;
                    cand[0] = (s16)x;
                    cand[1] = (s16)y;
                }
            }
next:;
        }
    }

    if (best == 0x7fff) return;

    if (!func_ov000_02179e48(cand)) return;
    if (!func_ov000_0217e6bc(cand[0], cand[1])) return;
    PlanMoveDestination(cand[0], cand[1]);
    return;
}
#pragma opt_strength_reduction reset
void func_ov000_0218b02c(void) {
    u16 flags;
    u8 *p;
    if (*(u8 *)((u8 *)*gCurrentMap + 0x52d6)) return;
    *(u16 *)((u8 *)data_ov000_021df580 + 8) |= 0x10;
    func_ov000_0218d908();
    func_ov000_0218d040(1);
    flags = *(u16 *)((u8 *)data_ov000_021df580 + 8);
    if (!(flags & 0x20)) {
        *(u16 *)((u8 *)data_ov000_021df580 + 8) = flags | 0x20;
        func_ov000_02198c08();
        data_ov000_021df654();
    }
    func_ov000_0217c3a4();
    p = *(u8 **)((u8 *)*gCurrentMap + 0x52d0);
    SetMapCursor(p[1], p[2], 2, 0, 0);
}
#pragma opt_strength_reduction off
/* Scans the map for the reachable cell that best approaches (targetX,targetY).
 * Unit kind 22 also gets a second, preferred destination; a cursor marker is
 * placed on each chosen cell. */
void PlanMoveDestination(s32 targetX,s32 targetY) {
void SelectMapLayer(void *);
void func_01ffada0(s32,s32,u8,s32,s32);
void func_01ffc328(void *);
s32 IsValidMoveCell(s16,s16);
s32 func_ov000_021a8be8(s16,s16,s32);
s32 func_ov000_021a9d8c(s16,s16);
s32 CellMoveScore(s32,s32,s32,s32);
s32 func_ov000_021a90a8(u8,s16,s16);
s32 DestinationScore(s32,s32,s32,s32);
s32 bestX,bestY,specialX,specialY,bestD,specialD;
s32 bestC,bestV,specialC,x,specialV,score,y,cost,cellCost;u8 *unit;
bestX=-1;bestY=0;bestV=0x7fffffff;specialX=bestX;specialY=bestY;bestD=bestY;specialD=bestY;specialV=0x7fffffff;
SelectMapLayer((u8 *)*gCurrentMap+0x2338);
func_01ffada0(targetX,targetY,((UnitKind0218 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->kind,110,0);
unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+unit[2]*4))[unit[1]]<0) (*(s8 **)((u8 *)*gCurrentMap+0x52e8+unit[2]*4))[unit[1]]=110;
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);
func_01ffc328(*(void **)((u8 *)*gCurrentMap+0x52d0));
unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if(!IsValidMoveCell(unit[1],unit[2]) ||
(((UnitKind0218 *)*(u8 **)((u8 *)*gCurrentMap+0x52d0))->kind==22 &&
func_ov000_021a8be8((*(u8 **)((u8 *)*gCurrentMap+0x52d0))[1],(*(u8 **)((u8 *)*gCurrentMap+0x52d0))[2],1))) bestC=32767;
else {unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);bestC=*(s8 *)((u8 *)*gCurrentMap+(unit[1]+*(u16 *)((u8 *)*gCurrentMap+0x3758+unit[2]*2))+0x2338);}
specialC=bestC;
for(y=0;y<*(u16 *)((u8 *)*gCurrentMap+0x5146);y++){
for(x=0;x<*(u16 *)((u8 *)*gCurrentMap+0x5144);x++){
if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x]<0)continue;
if(*(u8 *)((u8 *)*gCurrentMap+0x52d6)) {
unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if(x==unit[1] && y==unit[2])goto valid;
}
if(func_ov000_021a9d8c((s16)x,(s16)y))continue;
valid:
if(!IsValidMoveCell((s16)x,(s16)y))continue;
score=CellMoveScore(x,y,1,2);
if(((UnitKind0218 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->kind==22 &&
*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338)<=specialC &&
func_ov000_021a90a8(*(u8 *)((u8 *)*gCurrentMap+0x52d4),(s16)x,(s16)y)!=1 &&
func_ov000_021a8be8((s16)x,(s16)y,1)!=1) {
cost=DestinationScore(x,y,targetX,targetY);
cellCost=*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338);
if(specialC!=cellCost || (score<=specialV && (score!=specialV || cost<=specialD))) {specialC=cellCost;specialD=cost;specialX=x;specialY=y;specialV=score;}
}
if(*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338)>bestC)continue;
cost=DestinationScore(x,y,targetX,targetY);
cellCost=*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338);
if(bestC!=cellCost || (score<=bestV && (score!=bestV || cost<=bestD))) {bestC=cellCost;bestV=score;bestD=cost;bestX=x;bestY=y;}
}}
if(specialX>-1)SetMapCursor((s16)specialX,(s16)specialY,2,0,0);
if(bestX>-1)SetMapCursor((s16)bestX,(s16)bestY,2,0,0);
}
#pragma opt_strength_reduction reset
