/* 4 functions from 0x0217E798 to 0x0217F754 (ov000), found by ds-decomp. */
#include "common.h"
static inline s32 mapWidth(void) { extern void **gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x5144); }
static inline s32 mapHeight(void) { extern void **gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x5146); }
static inline s32 tileMin(s32 a,s32 b) { if(b<a)a=b;return a; }
static inline s32 tileMax(s32 a,s32 b) { if(a<b)a=b;return a; }
static inline s32 tileDistance(s32 x,s32 y,s32 xx,s32 yy) { s32 sum=0; if(x-xx>0)sum+=x-xx;else sum+=xx-x; if(y-yy>0)sum+=y-yy;else sum+=yy-y; return sum; }

/* Ticks a unit state: handles 0x40 pending-swap, early-outs on 0x80/0x100 flags, dispatches cases 2/9. */
void func_ov000_0217e798(M2C_UNK arg0, M2C_UNK arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    M2C_UNK func_ov000_0217e8c4(M2C_UNK, M2C_UNK, u8 *, u8 *, u8 *);
    M2C_UNK func_ov000_0217f754(M2C_UNK, M2C_UNK, u8 *, u8 *);
    M2C_UNK func_ov000_02180268(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    u16 temp_r1_2;
    u8 temp_r0;
    u8 temp_r1;
    u8 temp_r2;
    void *temp_r3;

    if (M2C_FIELD(data_ov000_021df580, u16 *, 8) & 0x40) {
        temp_r3 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
        temp_r2 = M2C_FIELD(temp_r3, u8 *, 0xC);
        M2C_FIELD(temp_r3, u8 *, 0xC) = (u8) M2C_FIELD(temp_r3, u8 *, 0xD);
        M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xD) = temp_r2;
        if (*arg2 == 8) {
            temp_r1 = *arg3;
            *arg3 = *arg4;
            *arg4 = temp_r1;
        }
        M2C_FIELD(data_ov000_021df580, u16 *, 8) = (u16) (M2C_FIELD(data_ov000_021df580, u16 *, 8) & ~0x40);
    }
    temp_r1_2 = M2C_FIELD(data_ov000_021df580, u16 *, 8);
    if (temp_r1_2 & 0x80) {
        return;
    }
    if (temp_r1_2 & 0x100) {
        *arg2 = 0xE;
        return;
    }
    temp_r0 = *arg2;
    switch (temp_r0) {                              /* irregular */
    case 2:
        if (!(temp_r1_2 & 1)) {
            func_ov000_0217f754(arg0, arg1, arg2, arg3);
        }
        break;
    case 9:
        func_ov000_02180268(arg0, arg1);
        break;
    }
    func_ov000_0217e8c4(arg0, arg1, arg2, arg3, arg4);
}

int func_ov000_0217e8c4(int arg0, int arg1, unsigned char *arg2, unsigned char *arg3, unsigned char *arg4) { return 0; }

s32 func_ov000_0217f318(s16 x,s16 y) {
extern void **data_027e0058;
s32 func_020d27a4();s32 func_ov000_021a93ec();s32 func_ov000_02176e28();
s32 result,best,minx,miny,maxx,maxy; register s32 xx,yy; s32 d,unit,score;void *p;s16 pos[2];
result=0;best=0;minx=x-1;if(minx<0)minx=0;
p=*data_027e0058; miny=y-1;if(miny<0)miny=0;
maxx=M2C_FIELD(p,u16*,0x5144)-1;
maxy=M2C_FIELD(p,u16*,0x5146)-1;
if(x+1<maxx)maxx=x+1;if(y+1<maxy)maxy=y+1;
for(yy=miny;yy<=maxy;yy++)for(xx=minx;xx<=maxx;xx++){
d=tileDistance(x,y,xx,yy);
if(d<1 || d>1)continue;
p=*data_027e0058;
unit=M2C_FIELD((u8*)p+xx+M2C_FIELD((u8*)p+((u32)yy<<1),u16*,0x3758),u8*,0);
if(unit==0)continue;
if(func_020d27a4(M2C_FIELD(p,u8*,0x52d4),unit)==1)continue;
if(!func_ov000_021a93ec((s16)xx,(s16)yy))continue;
pos[0]=x;pos[1]=y;
score=func_ov000_02176e28(unit|0x20000,pos);
if(best<score){result=unit;best=score;}
}
return result;
}

M2C_UNK func_ov000_0217f494(s32 x, s32 y) {
    extern void **gCurrentMap;
    extern M2C_UNK data_ov000_021b5bfc;
    s32 func_020a76d4(void *);
    s32 func_020d27a4(s32, s32);
    s32 func_ov000_021a93ec(s32, s32);
    M2C_UNK func_ov000_02176e28(M2C_UNK, void *);
    void *map;
    void *base;
    u8 *sel;
    s32 minX, minY, maxX, maxY;
    s32 xx, yy;
    s32 result = 0;
    s32 best = 0;
    s32 range;
    s32 minAllowed;
    s16 pos[2];

    map = *gCurrentMap;
    base = *(void **)map;
    sel = (u8 *)*(void **)((u8 *)base + 0x5000 + 0x2d0);

    minX = x - func_020a76d4((u8 *)base + 0x5000 + 0x2d0);
    if (minX < 0) minX = 0;

    minY = y - func_020a76d4((u8 *)base + 0x5000 + 0x2d0);
    if (minY < 0) minY = 0;

    range = func_020a76d4((u8 *)base + 0x5000 + 0x2d0);
    maxX = (s32)M2C_FIELD(base, u16 *, 0x5144) - 1;
    if (x + range < maxX + 1 ? 0 : 0, x + range < (s32)M2C_FIELD(base, u16 *, 0x5144)) {
        /* placeholder */
    }
    if (x + range < (s32)M2C_FIELD(base, u16 *, 0x5144)) maxX = x + range;

    range = func_020a76d4((u8 *)base + 0x5000 + 0x2d0);
    maxY = (s32)M2C_FIELD(base, u16 *, 0x5146) - 1;
    if (y + range < (s32)M2C_FIELD(base, u16 *, 0x5146)) maxY = y + range;

    minAllowed = *((u8 *)&data_ov000_021b5bfc + ((sel[0] & 0x3F) * 0x70) + 0x0C);

    pos[0] = (s16)x;
    pos[1] = (s16)y;

    for (yy = minY; yy <= maxY; yy++) {
        for (xx = minX; xx <= maxX; xx++) {
            s32 distX, distY, dist;
            u8 cand;
            u8 prop;
            s32 score;
            u16 rowOff;

            distX = x - xx;
            if (distX <= 0) distX = xx - x;
            distY = y - yy;
            if (distY <= 0) distY = yy - y;
            dist = distX + distY;

            if (dist < minAllowed) continue;
            if (dist > func_020a76d4((u8 *)base + 0x5000 + 0x2d0)) continue;

            rowOff = *(u16 *)((u8 *)base + (yy * 2) + 0x3758);
            cand = *((u8 *)base + xx + rowOff);
            if (cand == 0) continue;

            prop = *((u8 *)base + 0x52D4);
            if (func_020d27a4(prop, cand) == 1) continue;

            if (!func_ov000_021a93ec(xx, yy)) continue;

            score = func_ov000_02176e28((M2C_UNK)(cand | 0x20000), pos);
            if (best < score) {
                result = (M2C_UNK)cand;
                best = score;
            }
        }
    }

    return (M2C_UNK)result;
}

