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
void func_ov000_02199d74(int, int, int, int, int);

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
    void func_ov000_0218a9ac(s32, s32);

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
    func_ov000_0218a9ac(cand[0], cand[1]);
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
    func_ov000_02199d74(p[1], p[2], 2, 0, 0);
}
#pragma opt_strength_reduction off
void func_ov000_0218a9ac(s32 arg0,s32 arg1) {
void func_01ffb554(void *);
void func_01ffada0(s32,s32,u8,s32,s32);
void func_01ffc328(void *);
s32 func_ov000_0218a520(s16,s16);
s32 func_ov000_021a8be8(s16,s16,s32);
s32 func_ov000_021a9d8c(s16,s16);
s32 func_ov000_021a9e08(s32,s32,s32,s32);
s32 func_ov000_021a90a8(u8,s16,s16);
s32 func_ov000_0218a798(s32,s32,s32,s32);
s32 bx,by,ax,ay,bd,ad;
s32 bc,bv,ac,x,av,v,y,d,c;u8 *u;
bx=-1;by=0;bv=0x7fffffff;ax=bx;ay=by;bd=by;ad=by;av=0x7fffffff;
func_01ffb554((u8 *)*gCurrentMap+0x2338);
func_01ffada0(arg0,arg1,((UnitKind0218 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->kind,110,0);
u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+u[2]*4))[u[1]]<0) (*(s8 **)((u8 *)*gCurrentMap+0x52e8+u[2]*4))[u[1]]=110;
func_01ffb554((u8 *)*gCurrentMap+0x1e30);
func_01ffc328(*(void **)((u8 *)*gCurrentMap+0x52d0));
u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if(!func_ov000_0218a520(u[1],u[2]) ||
(((UnitKind0218 *)*(u8 **)((u8 *)*gCurrentMap+0x52d0))->kind==22 &&
func_ov000_021a8be8((*(u8 **)((u8 *)*gCurrentMap+0x52d0))[1],(*(u8 **)((u8 *)*gCurrentMap+0x52d0))[2],1))) bc=32767;
else {u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);bc=*(s8 *)((u8 *)*gCurrentMap+(u[1]+*(u16 *)((u8 *)*gCurrentMap+0x3758+u[2]*2))+0x2338);}
ac=bc;
for(y=0;y<*(u16 *)((u8 *)*gCurrentMap+0x5146);y++){
for(x=0;x<*(u16 *)((u8 *)*gCurrentMap+0x5144);x++){
if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x]<0)continue;
if(*(u8 *)((u8 *)*gCurrentMap+0x52d6)) {
u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if(x==u[1] && y==u[2])goto valid;
}
if(func_ov000_021a9d8c((s16)x,(s16)y))continue;
valid:
if(!func_ov000_0218a520((s16)x,(s16)y))continue;
v=func_ov000_021a9e08(x,y,1,2);
if(((UnitKind0218 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->kind==22 &&
*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338)<=ac &&
func_ov000_021a90a8(*(u8 *)((u8 *)*gCurrentMap+0x52d4),(s16)x,(s16)y)!=1 &&
func_ov000_021a8be8((s16)x,(s16)y,1)!=1) {
d=func_ov000_0218a798(x,y,arg0,arg1);
c=*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338);
if(ac!=c || (v<=av && (v!=av || d<=ad))) {ac=c;ad=d;ax=x;ay=y;av=v;}
}
if(*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338)>bc)continue;
d=func_ov000_0218a798(x,y,arg0,arg1);
c=*(s8 *)((u8 *)*gCurrentMap+x+*(u16 *)((u8 *)*gCurrentMap+0x3758+y*2)+0x2338);
if(bc!=c || (v<=bv && (v!=bv || d<=bd))) {bc=c;bv=v;bd=d;bx=x;by=y;}
}}
if(ax>-1)func_ov000_02199d74((s16)ax,(s16)ay,2,0,0);
if(bx>-1)func_ov000_02199d74((s16)bx,(s16)by,2,0,0);
}
#pragma opt_strength_reduction reset
