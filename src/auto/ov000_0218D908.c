/* 4 functions from 0x0218D908 to 0x0218E584 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct {u8 pad[0x58];u16 row;} ScanRow;
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
    s32 func_ov000_021a9e08(s32, s32, s32, s32);
    void func_ov000_0217c3a4(void);
    M2C_UNK func_ov000_02199d74(s16, s16, M2C_UNK, u8, s32);
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
                score = func_ov000_021a9e08(x, y, 1, 2);
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
    if (useTransport) func_ov000_02199d74((s16)bestX, (s16)bestY, 7, 0, 0);
    else func_ov000_02199d74((s16)bestX, (s16)bestY, 2, 0, 0);
}
#pragma opt_strength_reduction reset
void func_ov000_0218dda4(void) {
 M2C_UNK func_01ffc328(s32); M2C_UNK func_ov000_02199d74(s16,s16,M2C_UNK,u8,s32); s32 func_ov000_021aa820(s16*,u16,M2C_UNK,M2C_UNK); extern void **gCurrentMap;
 s16 pos[2]; s32 y,x,bx,by,best; s8 *row,*p; s8 c; u16 width; void **owner; void *base,*cell;
 by=-1; bx=-1; best=-1;
 func_01ffc328(M2C_FIELD(*gCurrentMap,s32*,0x52d0));
 y=0; owner=gCurrentMap; base=*owner;
 if(y<M2C_FIELD(base,u16*,0x5146)) {
 width=M2C_FIELD(base,u16*,0x5144);
 do { x=0; if(x<width) {
 row=M2C_FIELD(base+((u32)y<<2),s8**,0x52e8); p=row;
 do {if(*p>=0) {cell=base+((ScanRow*)(base+((u32)y<<1)+0x3700))->row+x;
 if((M2C_FIELD(cell,u8*,0x1420)&31)==24 && M2C_FIELD(cell,u8*,0)==0) {c=row[x]; if(c>best){bx=x;by=y;best=c;}}}
 x++; p++;
 }while(x<width);}
 y++;
 }while(y<((ScanRow*)(base+0x50ee))->row);}
 if(best==-1)return;
 pos[0]=bx;pos[1]=by;
 if(func_ov000_021aa820(pos,M2C_FIELD(*owner,u16*,0x52a4),1,0)!=1)return;
 func_ov000_02199d74((s16)bx,(s16)by,19,(u8)pos[0],(u8)pos[1]);
}

void func_ov000_0218df00(void) {
    M2C_UNK func_01ffc328(M2C_UNK);
    void func_01ffb9c4(s8);
    s32 func_ov000_021a98e4(s32);
    s32 func_020d27a4(s32, s32);
    s32 func_ov000_021a93ec(s32, s32);
    s32 func_ov000_02177f24(s32, s32, s16 *);
    M2C_UNK func_ov000_02176e28(M2C_UNK, void *);
    s32 func_ov000_0217a0a8(void *);
    M2C_UNK func_ov000_02199d74(s16, s16, M2C_UNK, u8, s32);
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;

    s32 bestY = -1;
    s32 bestScore = 0;
    s32 bestX = -1;
    s32 temp = 0;
    s16 buf[2];
    void *base;
    u8 *selected;
    u8 kindSel;
    s32 height, width;
    s32 y, x;
    u8 *rowPtr;
    u16 rowOffY;
    u8 byteVal;
    void *entity;
    u8 kind;
    M2C_UNK pathScore;
    s32 count;
    s32 ex, ey;
    s32 xStart, yStart, xEnd, yEnd;
    s32 nx, ny;
    s32 dx, dy;
    u8 *p580;
    u8 r4b;
    void *mapPtr;
    void *root;
    u8 *sel;
    u16 sel8;

    base = *(void **)*gCurrentMap;
    selected = *(u8 **)((u8 *)base + 0x5000 + 0x2D0);
    kindSel = (u8)(((u32)(selected[0] << 26)) >> 26);
    if (func_ov000_021a98e4((s32)kindSel) != 0) {
        return;
    }
    func_01ffc328(M2C_FIELD(*gCurrentMap, s32 *, 0x52D0));
    func_01ffb9c4(0x6f);

    base = *(void **)*gCurrentMap;
    height = *(u16 *)((u8 *)base + 0x5146);
    if (height <= 0) {
        goto func_done;
    }
    width = *(u16 *)((u8 *)base + 0x5144);
    y = 0;
outer_top:
    if (y >= height) {
        goto func_done;
    }
    x = 0;
    if (width <= 0) {
        goto width_done;
    }
inner_top:
    if (x >= width) {
        goto width_done;
    }
    rowPtr = ((u8 **)((u8 *)base + 0x52E8))[y];
    if (rowPtr[x] < 0) {
        goto next_cell;
    }
    rowOffY = *(u16 *)((u8 *)base + (y << 1) + 0x3758);
    byteVal = *((u8 *)base + (s32)rowOffY + x);
    entity = (void *)((u8 *)base + 0x59A4 + (s32)byteVal * 14);
    kind = ((u8 *)entity)[0] & 0x3F;
    if (kind == 0) {
        goto next_cell;
    }
    if (func_020d27a4((s32)*((u8 *)base + 0x52D4), (s32)byteVal) == 1) {
        goto next_cell;
    }
    if (!func_ov000_021a93ec(x, y)) {
        goto next_cell;
    }
    if (!func_ov000_02177f24(x, y, buf)) {
        goto next_cell;
    }
    pathScore = func_ov000_02176e28((M2C_UNK)((s32)byteVal | 0x10000), buf);
    if (pathScore == 0) {
        goto next_cell;
    }
    if (pathScore < bestScore) {
        goto next_cell;
    }
    count = 0;
    if (func_ov000_0217a0a8(entity) == 1) {
        ex = ((u8 *)entity)[1];
        ey = ((u8 *)entity)[2];

        xStart = ex - 1;
        if (xStart < 0) {
            xStart = 0;
        }
        yStart = ey - 1;
        if (yStart < 0) {
            yStart = 0;
        }
        xEnd = ex + 1;
        if (xEnd > width - 1) {
            xEnd = width - 1;
        }
        yEnd = ey + 1;
        if (yEnd > height - 1) {
            yEnd = height - 1;
        }

        for (ny = yStart; ny <= yEnd; ny++) {
            for (nx = xStart; nx <= xEnd; nx++) {
                dx = ex - nx;
                if (dx < 0) {
                    dx = nx - ex;
                }
                dy = ey - ny;
                if (dy < 0) {
                    dy = ny - ey;
                }
                if (dx + dy != 1) {
                    continue;
                }
                rowPtr = ((u8 **)((u8 *)base + 0x52E8))[ny];
                if (rowPtr[nx] < 0) {
                    continue;
                }
                {
                    u16 nrowOff = *(u16 *)((u8 *)base + (ny << 1) + 0x3758);
                    u8 nbyte = *((u8 *)base + (s32)nrowOff + nx);
                    void *nent = (void *)((u8 *)base + 0x59A4 + (s32)nbyte * 14);
                    u8 nkind = ((u8 *)nent)[0] & 0x3F;
                    if (nkind == 0) {
                        continue;
                    }
                    if ((M2C_FIELD(nent, u16 *, 4) & 1) != 0) {
                        continue;
                    }
                }
                count++;
            }
        }
    }
    if (count <= 1) {
        goto next_cell;
    }

    bestScore = (s32)pathScore;
    bestY = buf[0];
    bestX = buf[1];
    temp = (s32)byteVal;

next_cell:
    x++;
    goto inner_top;
width_done:
    y++;
    goto outer_top;
func_done:
    if (bestScore == 0) {
        return;
    }
    p580 = *(u8 **)data_ov000_021df580;
    r4b = p580[7];
    p580[7] = (u8)(r4b & ~2);
    mapPtr = *(void **)*gCurrentMap;
    root = *(void **)mapPtr;
    sel = *(u8 **)((u8 *)root + 0x5000 + 0x2D0);
    sel8 = *(u16 *)(sel + 8);
    sel8 = (u16)(sel8 & ~0x3000);
    *(u16 *)(sel + 8) = sel8;
    func_ov000_02199d74((s16)bestY, (s16)bestX, (M2C_UNK)4, (u8)(temp & 0xFF), 0);
}

s32 func_ov000_0218e340(void) {
    int dummy_unused = 0;
    (void)dummy_unused;
    return 0;
}

