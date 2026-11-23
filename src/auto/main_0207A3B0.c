/* 20 functions from 0x0207A3B0 to 0x0207B2F0 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "gx.h"
#include "sprite.h"
#include "gx.h"

#pragma push
#pragma opt_propagation off
void func_0207a3b0(u16 *a,s32 b,u16 c,u8 d,u8 e,s32 f,u16 g,u8 h,u8 i,u8 j,u8 k){
extern void *gCurrentMap;
extern const u16 data_020ebd98[];
extern const s16 data_020ebda2[];
s32 player,palette;
s32 flag;
u16 tile;
u32 mark;
u32 value;u8 *unit;
if(c==256){c=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a8);palette=0xb12e;}
else palette=data_020ebd98[(c>>6)+1];
player=(c>>6)+1;
flag=d;
if(flag)flag=1;
tile=func_020a72b0(player,b);
if(Map_ShowsCargoForUnit(b,M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a4),(u16)player))mark=0x92;
else if(flag)mark=0x86;
else if((u8)e)mark=0x8a;
else if((u16)g)mark=0x8e;
else mark=0;
if(i){if(mark!=0)mark=(u16)(mark+1);else mark=0x83;}
if(j){if(mark!=0)mark=(u16)(mark+2);else mark=0x84;}
if((u8)k)mark=0x96;
if(c==0||c==128){
value=mark;if(value==0){value=tile+3;value+=0x400;}
M2C_FIELD(a,u16 *,0)=tile+1+0x400+palette;
M2C_FIELD(a,u16 *,2)=tile+palette+0x400;
value+=palette;
M2C_FIELD(a,u16 *,0x40)=value;
unit=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+player*140;
if(!(unit[0x67c3]&2)){
if((u8)h){M2C_FIELD(a,u16 *,0x42)=palette+0x82;return;}
}
if(data_020ebda2[f]<0){M2C_FIELD(a,u16 *,0x42)=tile+2+0x400+palette;return;}
M2C_FIELD(a,u16 *,0x42)=f+0x78+palette;return;
}
value=mark?mark:tile+2;
M2C_FIELD(a,u16 *,0)=tile+palette;
M2C_FIELD(a,u16 *,2)=tile+1+palette;
M2C_FIELD(a,u16 *,0x40)=value+palette;
unit=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+player*140;
if(!(unit[0x67c3]&2)){
if((u8)h){M2C_FIELD(a,u16 *,0x42)=palette+0x82;return;}
}
if(data_020ebda2[f]<0){M2C_FIELD(a,u16 *,0x42)=tile+3+palette;return;}
M2C_FIELD(a,u16 *,0x42)=f+0x78+palette;
}
#pragma pop
/* Write the 2x2 icon tile quad of unit kind `unitKind` into the map tile buffer
 * `tileBuf` for the cell at column `column`, row `row`, in palette `palette`
 * (256 selects the base palette).  `flag` and `extraFlag` are unit display flags. */
void WriteUnitKindTileQuad(s32 tileBuf, s32 column, s32 row, M2C_UNK unitKind, u16 palette, u8 flag, u8 extraFlag) {

    func_0207a3b0(tileBuf + (column * 2) + (row << 6), unitKind, palette, flag, (s32) extraFlag, 0, 0, 0, 0, 0, 0);
}

void func_0207a668(void) {

}

/* Writes the screen-brighten overlay's 2x2 tile quad for map cell (x,y) into the
   engine's tile buffer.  The cell's position is taken relative to the view's
   top-left cell (wrapping every 16 cells); an impassable cell (negative grid
   value) is left blank, the rest get the bright tiles 0x124..0x127. */
void WriteMapTileQuad(s32 x, s32 y) {
 extern void *gCurrentMap;
 extern void *gCur3DSpriteEngine;
 void *cell;
 void *map;
 map = M2C_FIELD(gCurrentMap,void **,0);
 cell = (u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + (((u32)((x - M2C_FIELD(map,u16 *,MAP_VIEW_CELL_X)) << 28) >> 27) * 2) + (((u32)((y - M2C_FIELD(map,u16 *,MAP_VIEW_CELL_Y)) << 28) >> 22) * 2);
 if (M2C_FIELD(M2C_FIELD((u8 *)map + y*4,s8 **,MAP_GRID),s8 *,x) < 0) {
 M2C_FIELD(cell,u16 *,0)=0;
 M2C_FIELD(cell,u16 *,2)=0;
 M2C_FIELD(cell,u16 *,0x40)=0;
 M2C_FIELD(cell,u16 *,0x42)=0;
 return;
 }
 M2C_FIELD(cell,u16 *,0)=0x124;
 M2C_FIELD(cell,u16 *,2)=0x125;
 M2C_FIELD(cell,u16 *,0x40)=0x126;
 M2C_FIELD(cell,u16 *,0x42)=0x127;
}

void func_0207a710(void *arg0) {
    extern void *gCurrentMap;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), s32 *, 0x5C);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(CreateSpriteFromClass(temp_r0, arg0), s16 *, 0x6C) = (s16) M2C_FIELD(arg0, s16 *, 0x6C);
}

void SetMapCursorVisible(s16 arg0) {
    extern M2C_UNK data_02100bb0;
    M2C_FIELD(CreateSpriteFromClass(&data_02100bb0, 7), s16 *, 0x6C) = arg0;
}

void func_0207a768(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02100bb0;
    DeleteSpriteObjectsOfClass(&data_02100bb0);
}

void func_0207a77c(s32 arg0) {
 extern void *gCurrentMap;
 void (*temp_r1)(s32);
 temp_r1 = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(s32),0x2c);
 if (temp_r1 == 0) return;
 temp_r1(arg0);
}

#pragma push
#pragma opt_propagation off
void func_0207a7a4(s32 arg0, s32 arg1) {
    extern void *gCurrentMap;
    extern void *gTouchState;
    extern void *gKeyState;
    extern u8 data_02144cdc;
    extern u8 data_02100bac;

    M2C_UNK GetMapViewWidth(void);
    M2C_UNK GetMapViewHeight(void);

    s32 r5 = GetMapViewWidth();
    s32 r0v = GetMapViewHeight();
    void *r9 = gCurrentMap;
    void *r8p = gTouchState;
    s32 r12f = 0;
    u32 lr = 0;
    s32 r6f = 0;
    s32 r7f = 0;
    s32 r2v = M2C_FIELD(r8p, u16 *, 0);
    s32 r3v = M2C_FIELD(r8p, u16 *, 2);
    void *base9 = M2C_FIELD(r9, void **, 0);
    void *p5200 = (u8 *)base9 + 0x5200;
    s16 valC2 = M2C_FIELD(p5200, s16 *, 0xc2);
    s32 stack0 = valC2;
    s16 valC4 = M2C_FIELD(p5200, s16 *, 0xc4);

    if (arg0 != 0) {
        u8 b;
        void *base, *q, *base2, *q2, *base3, *q3, *base4, *q4;
        u8 st, st2, st3, st4;
        b = M2C_FIELD(r8p, u8 *, 0x12);
        if (b != 0) {
            data_02144cdc = 1;
        } else {
            void *g = gKeyState;
            u8 t = data_02100bac;
            u16 h = M2C_FIELD(g, u16 *, 0x6);
            if (h & t) {
                data_02144cdc = 0;
            }
        }
        if (data_02144cdc != 0) {
            u8 v = M2C_FIELD(r8p, u8 *, 0x12);
            if (v != 0) {
                if ((s32)r2v < 0xc) r12f = 1;
                if ((s32)r3v < 0xc) r6f = 1;
                if ((s32)r2v >= 0xf4) lr = 1;
                if ((s32)r3v >= 0xb4) r7f = 1;
            }
        } else {
            void *base5 = M2C_FIELD(r9, void **, 0);
            void *q5 = (u8 *)base5 + 0x5100;
            r2v = M2C_FIELD(q5, s16 *, 0x4a);
            r3v = M2C_FIELD(q5, s16 *, 0x48);
            r2v = valC4 - (r2v >> 4);
            r3v = stack0 - (r3v >> 4);
            if (r3v < 1) r12f = 1;
            if (r2v < 1) r6f = 1;
            if (r3v > r5 - 2) lr = 1;
            if (r2v > r0v - 2) r7f = 1;
        }
        base = M2C_FIELD(r9, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if ((st & 0x3) == 0) {
            if (r12f) { st |= 0x2; M2C_FIELD(q, u8 *, 0x154) = st; }
            if (lr) {
                base2 = gCurrentMap;
                base2 = M2C_FIELD(base2, void **, 0);
                q2 = (u8 *)base2 + 0x5000;
                st2 = M2C_FIELD(q2, u8 *, 0x154);
                st2 |= 0x1;
                M2C_FIELD(q2, u8 *, 0x154) = st2;
            }
        }
        base3 = gCurrentMap;
        base3 = M2C_FIELD(base3, void **, 0);
        q3 = (u8 *)base3 + 0x5000;
        st3 = M2C_FIELD(q3, u8 *, 0x154);
        if ((st3 & 0xc) == 0) {
            if (r6f) { st3 |= 0x4; M2C_FIELD(q3, u8 *, 0x154) = st3; }
            if (r7f) {
                base4 = gCurrentMap;
                base4 = M2C_FIELD(base4, void **, 0);
                q4 = (u8 *)base4 + 0x5000;
                st4 = M2C_FIELD(q4, u8 *, 0x154);
                st4 |= 0x8;
                M2C_FIELD(q4, u8 *, 0x154) = st4;
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        u16 a;
        s16 bb, bb2;
        s32 t;
        h = gCurrentMap;
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x1) {
            b = base;
            qp = (u8 *)b + 0x5100;
            a = M2C_FIELD(qp, u16 *, 0x44);
            bb = M2C_FIELD(qp, s16 *, 0x48);
            t = a - (bb >> 4);
            if (t <= r5) {
                st ^= 0x1;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x48) = (s16)(bb + arg1);
                h2 = gCurrentMap;
                base2 = M2C_FIELD(h2, void **, 0);
                qp2 = (u8 *)base2 + 0x5100;
                bb2 = M2C_FIELD(qp2, s16 *, 0x48);
                if ((bb2 & 0xf) == 0) {
                    q2 = (u8 *)base2 + 0x5000;
                    st2 = M2C_FIELD(q2, u8 *, 0x154);
                    st2 ^= 0x1;
                    M2C_FIELD(q2, u8 *, 0x154) = st2;
                }
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        s16 bb, bb2;
        h = gCurrentMap;
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x2) {
            b = base;
            qp = (u8 *)b + 0x5100;
            bb = M2C_FIELD(qp, s16 *, 0x48);
            if (bb <= 0) {
                st ^= 0x2;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x48) = (s16)(bb - arg1);
                h2 = gCurrentMap;
                base2 = M2C_FIELD(h2, void **, 0);
                qp2 = (u8 *)base2 + 0x5100;
                bb2 = M2C_FIELD(qp2, s16 *, 0x48);
                if ((bb2 & 0xf) == 0) {
                    q2 = (u8 *)base2 + 0x5000;
                    st2 = M2C_FIELD(q2, u8 *, 0x154);
                    st2 ^= 0x2;
                    M2C_FIELD(q2, u8 *, 0x154) = st2;
                }
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        s16 bb, bb2;
        h = gCurrentMap;
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x4) {
            b = base;
            qp = (u8 *)b + 0x5100;
            bb = M2C_FIELD(qp, s16 *, 0x4a);
            if (bb <= 0) {
                st ^= 0x4;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x4a) = (s16)(bb - arg1);
                h2 = gCurrentMap;
                base2 = M2C_FIELD(h2, void **, 0);
                qp2 = (u8 *)base2 + 0x5100;
                bb2 = M2C_FIELD(qp2, s16 *, 0x4a);
                if ((bb2 & 0xf) == 0) {
                    q2 = (u8 *)base2 + 0x5000;
                    st2 = M2C_FIELD(q2, u8 *, 0x154);
                    st2 ^= 0x4;
                    M2C_FIELD(q2, u8 *, 0x154) = st2;
                }
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        u16 a;
        s16 bb, bb2;
        s32 t;
        h = gCurrentMap;
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x8) {
            b = base;
            qp = (u8 *)b + 0x5100;
            a = M2C_FIELD(qp, u16 *, 0x46);
            bb = M2C_FIELD(qp, s16 *, 0x4a);
            t = a - (bb >> 4);
            if (t <= r0v) {
                st ^= 0x8;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x4a) = (s16)(bb + arg1);
                h2 = gCurrentMap;
                base2 = M2C_FIELD(h2, void **, 0);
                qp2 = (u8 *)base2 + 0x5100;
                bb2 = M2C_FIELD(qp2, s16 *, 0x4a);
                if ((bb2 & 0xf) == 0) {
                    q2 = (u8 *)base2 + 0x5000;
                    st2 = M2C_FIELD(q2, u8 *, 0x154);
                    st2 ^= 0x8;
                    M2C_FIELD(q2, u8 *, 0x154) = st2;
                }
            }
        }
    }

    {
        void *h, *base, *q;
        void *fp;
        void (*cb)(void);
        h = gCurrentMap;
        q = (u8 *)h + 0x4;
        fp = M2C_FIELD(q, void **, 0);
        cb = (void (*)(void))M2C_FIELD(fp, void (**)(void), 0x1c);
        if (cb != 0) {
            cb();
        }
    }
}
#pragma pop
/* Finishes a property capture at cell (x, y): give the cell's terrain the current
 * player's owner bits while keeping its terrain kind, recolour the property tile
 * for that owner and refresh the map view. */
void CompletePropertyCapture(s32 x, s32 y) {
    M2C_UNK SetPropertyOwnerTile(s32, s32, u8);
    M2C_UNK RefreshMapView(void);
    M2C_UNK func_020cf2c8(void);
    M2C_UNK func_020d2470(void);
    extern void *gCurrentMap;
    s32 index;
    s32 value;
    u8 *terrain;
    void *map;

    map = M2C_FIELD(gCurrentMap, void **, 0);
    terrain = (u8 *)map + MAP_CELL_TERRAIN;
    index = x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS);
    value = M2C_FIELD(map, u16 *, MAP_CURRENT_OWNER) + (terrain[index] & MAP_TERRAIN_KIND_MASK);
    terrain[index] = value;
    SetPropertyOwnerTile(x, y, (u8)(value & MAP_TERRAIN_OWNER_MASK));
    RefreshMapView();
    func_020cf2c8();
    func_020d2470();
}

/* Recolour the property at (x, y) for a new owner: find which row of
 * gPropertyTileIds holds the cell's current tile and give the cell that row's
 * tile for owner, whose bits are the packed MAP_TERRAIN_OWNER_MASK ones.  Returns
 * the row's first index, 0 when the cell holds no property tile. */
s32 SetPropertyOwnerTile(s32 x, s32 y, u8 owner)
{
    extern u16 gPropertyTileIds[];
    extern void *gCurrentMap;
    s32 i = 0;
    s32 rowStart;
    void *map;
    u16 tile;
    if (gPropertyTileIds[0] != MAP_PROPERTY_TILE_NONE) {
        map = M2C_FIELD(gCurrentMap, void **, 0);
        tile = M2C_FIELD((u8 *)map + 2 * (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u16 *, MAP_CELL_TILE_ID);
        do {
            u16 candidate = gPropertyTileIds[i];
            if (candidate == tile)
                break;
            ++i;
        } while (gPropertyTileIds[i] != MAP_PROPERTY_TILE_NONE);
    }
    map = M2C_FIELD(gCurrentMap, void **, 0);
    rowStart = (i / MAP_PROPERTY_TILE_OWNERS) * MAP_PROPERTY_TILE_OWNERS;
    M2C_FIELD((u8 *)map + 2 * (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u16 *, MAP_CELL_TILE_ID) =
        gPropertyTileIds[rowStart + (owner >> MAP_PROPERTY_TILE_OWNER_SHIFT)];
    return (s16)rowStart;
}

/* Rewrite a property cell's tile for a new owner: when the cell shows a
   headquarters tile (the tile table's first row), the cell is given the tile of
   the rebuilt property kind for the owner colour held in `owner`'s bits 5..7.
   Returns the table row the cell's tile belonged to (0 for a headquarters). */
s32 RebuildPropertyTile(s32 x, s32 y, s32 owner) {
    extern u16 gPropertyTileIds[];
    extern void *gCurrentMap;
    s32 i = 0;
    s32 row;
    void *map;

    if (gPropertyTileIds[0] != 0xffff) {
        map = M2C_FIELD(gCurrentMap, void **, 0);
        do {
            if (gPropertyTileIds[i] == M2C_FIELD((u8 *)map + 2 * (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u16 *, MAP_CELL_TILE_ID)) break;
            i++;
        } while (gPropertyTileIds[i] != 0xffff);
    }
    row = (i / MAP_PROPERTY_TILE_OWNERS) * MAP_PROPERTY_TILE_OWNERS;
    if (row < MAP_PROPERTY_TILE_OWNERS) {   /* row 0: a headquarters tile */
        map = M2C_FIELD(gCurrentMap, void **, 0);
        M2C_FIELD((u8 *)map + 2 * (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u16 *, MAP_CELL_TILE_ID) =
            gPropertyTileIds[row + MAP_PROPERTY_TILE_REBUILT_ROW * MAP_PROPERTY_TILE_OWNERS + (owner >> MAP_PROPERTY_TILE_OWNER_SHIFT)];
    }
    return (s16)row;
}

/* Update each active entity (1..4) according to the state nibble packed in `value`. */
void func_0207ad30(s32 value) {
    s32 IsPlayerPresent(s32);
    s32 IsPlayerArmyVariantSet(s32);
    s32 IsPlayerCoPowerReady(s32);
    extern void *gCurrentMap;

    s32 state = (value >> 2) & 15;
    s32 i;
    void (*callback)(s32, s32);

    for (i = 1; i < 5; i++) {
        if (!IsPlayerPresent(i)) {
            continue;
        }
        if (IsPlayerArmyVariantSet(i) && state >= 0) {
            callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
            if (callback) {
                callback(i, state);
            }
        } else if (IsPlayerCoPowerReady(i)) {
            switch (state) {
            case 15: {
                callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
                if (callback) {
                    callback(i, 7);
                }
                break;
            }
            default: {
                callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
                if (callback) {
                    callback(i, 0);
                }
                break;
            }
            }
        } else {
            callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
            if (callback) {
                callback(i, 0);
            }
        }
    }
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Start the cursor-cell burst: allocate one particle per cell of the grid area
 * marked with bit 0x40 (the unit's reachable cells), skipping the cursor cell
 * itself, and seed each particle at the cursor cell with a velocity towards its
 * own cell. */
void InitCursorCellBurst(void *sprite)
{
    extern void *gCurrentMap;
    void *HeapAllocBlock(s32);
    BattleMapUnit *cursorUnit = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), BattleMapUnit **, MAP_CURSOR_UNIT);
    s32 cursorX = cursorUnit->x;
    s32 cursorY = cursorUnit->y;
    s16 (*particles)[4] = HeapAllocBlock(0x660);
    s32 x, y;
    s32 originX, originY;
    M2C_FIELD(sprite, void **, SPRITE_SCATTER_POINTS) = particles;
    y = 0;
    M2C_FIELD(sprite, s16 *, SPRITE_SCATTER_COUNT) = y;
    M2C_FIELD(sprite, s16 *, SPRITE_SCATTER_FRAME) = y;
    {
        u8 *map = M2C_FIELD(gCurrentMap, u8 **, 0);
        if (M2C_FIELD(map, u16 *, MAP_HEIGHT) <= y)
            return;
        originX = cursorX * 16;
        originY = cursorY * 16;
        do {
        s32 velocityY;
        x = 0;
        if (M2C_FIELD(map, u16 *, MAP_WIDTH) <= x)
            goto nextRow;
        velocityY = (y - cursorY) * 2;
        do {
            s8 cell = M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x];
            if (cell < 0 || (x == cursorX && y == cursorY) || !(cell & 0x40))
                goto nextCell;
            particles[M2C_FIELD(sprite, s16 *, SPRITE_SCATTER_COUNT)][0] = (s16)originX;
            particles[M2C_FIELD(sprite, s16 *, SPRITE_SCATTER_COUNT)][1] = (s16)originY;
            particles[M2C_FIELD(sprite, s16 *, SPRITE_SCATTER_COUNT)][2] = (s16)((x - cursorX) * 2);
            particles[M2C_FIELD(sprite, s16 *, SPRITE_SCATTER_COUNT)][3] = (s16)velocityY;
            M2C_FIELD(sprite, s16 *, SPRITE_SCATTER_COUNT)++;
        nextCell:
            ++x;
            map = M2C_FIELD(gCurrentMap, u8 **, 0);
        } while (x < M2C_FIELD(map, u16 *, MAP_WIDTH));
    nextRow:
        ++y;
        } while (y < M2C_FIELD(map, u16 *, MAP_HEIGHT));
    }
}
#pragma pop
void FreeCursorCellBurst(void *arg0) {
    M2C_UNK HeapFreeBlock(s32);
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x54));
}

/* One frame of the cursor-cell burst transition: move every motion point by its
 * velocity, and once eight frames have run tell SetMapCursorVisible the effect is
 * over and delete the effect's sprite. */
void UpdateCursorCellBurst(void *sprite){
s16 (*points)[4]=M2C_FIELD(sprite,void **,SPRITE_SCATTER_POINTS);s16 i;
if(M2C_FIELD(sprite,s16 *,SPRITE_SCATTER_FRAME)==SPRITE_SCATTER_FRAMES){SetMapCursorVisible(1);DeleteSpriteObject(sprite);return;}
M2C_FIELD(sprite,s16 *,SPRITE_SCATTER_FRAME)++;
if(M2C_FIELD(sprite,s16 *,SPRITE_SCATTER_COUNT)>SPRITE_SCATTER_MAX)return;
SetSpritePaletteBase();
for(i=0;i<M2C_FIELD(sprite,s16 *,SPRITE_SCATTER_COUNT);i++){
points[i][0]+=points[i][2];
points[i][1]+=points[i][3];
REG_GX_POLYGON_ATTR=GX_POLYGON_DEFAULT;
}
}

void CreateCursorCellBurst(M2C_UNK arg0) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02100bd0;
    CreateSpriteFromClass(&data_02100bd0, arg0);
}

void func_0207b040(void) {
 M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
 extern M2C_UNK data_02100bd0;
 DeleteSpriteObjectsOfClass(&data_02100bd0);
 func_0207a768();
}

/* Save the pan endpoints and build a speed ramp capped at eight view units per frame. */
void InitMapScrollAnimation(MapScrollAnim *pan) {
    s32 Abs(s32);
    extern void *gCurrentMap;
    extern u8 gMapScrollSpeedRamp[];

    u16 distanceLeft;
    u16 speed;

    pan->startX = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_X);
    pan->startY = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_Y);

    pan->deltaX = (s16)(pan->targetX - M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_X));
    pan->deltaY = (s16)(pan->targetY - M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_Y));

    if (Abs(pan->deltaX) > Abs(pan->deltaY)) {
        distanceLeft = (u16)Abs(pan->deltaX);
    } else {
        distanceLeft = (u16)Abs(pan->deltaY);
    }

    pan->remaining = 0;
    speed = 1;
    for (;;) {
        s32 nextDistance = (s32)distanceLeft - (s32)speed;
        if (nextDistance < 0) {
            break;
        }
        distanceLeft = (u16)nextDistance;
        gMapScrollSpeedRamp[pan->remaining] = (u8)speed;
        if (speed < 8) {
            speed = (u16)(speed + 1);
        }
        pan->remaining = (s16)(pan->remaining + 1);
    }
    gMapScrollSpeedRamp[pan->remaining] = (u8)distanceLeft;
    pan->accum = 0;
}

/* Advances the map-scroll pan one frame: adds the current speed step to the
 * travelled distance, interpolates the view along whichever axis has the larger
 * delta, stores the new view scroll, and when the countdown reaches zero snaps
 * to the target, frees the task and runs the view's scroll-done callback. */
void StepMapScrollAnimation(void *task) {
    extern u8 gMapScrollSpeedRamp[];
    s32 Abs(s32);
    s32 RuntimeIntDivMod(s32, s32);
    M2C_UNK DeleteSpriteObject(M2C_UNK);
    extern void *gCurrentMap;
    MapScrollAnim *pan = (MapScrollAnim *)task;

    void (*cb)(void);
    s32 fixedX;
    s32 fixedY;
    s32 accum;
    s32 signMajor;

    if (Abs(pan->deltaX) > Abs(pan->deltaY)) {
        pan->accum = (u16)(pan->accum + gMapScrollSpeedRamp[pan->remaining]);
        if (pan->deltaX > 0) {
            signMajor = 1;
        } else {
            signMajor = -(pan->deltaX < 0);
        }
        accum = (s32)pan->accum * signMajor;
        fixedX = (pan->startX + accum) << 16;
        fixedY = accum * RuntimeIntDivMod(pan->deltaY << 16, pan->deltaX) + (pan->startY << 16);
    } else {
        pan->accum = (u16)(pan->accum + gMapScrollSpeedRamp[pan->remaining]);
        if (pan->deltaY > 0) {
            signMajor = 1;
        } else {
            signMajor = -(pan->deltaY < 0);
        }
        accum = (s32)pan->accum * signMajor;
        fixedX = accum * RuntimeIntDivMod(pan->deltaX << 16, pan->deltaY) + (pan->startX << 16);
        fixedY = (pan->startY + accum) << 16;
    }

    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_X) =
        fixedX / 65536;

    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_Y) =
        fixedY / 65536;

    if (pan->remaining != 0) {
        pan->remaining = (u16)(pan->remaining - 1);
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_X) = pan->targetX;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_VIEW_Y) = pan->targetY;
        DeleteSpriteObject(task);
        }
    cb = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), MAPVIEW_SCROLL_DONE);
        if (cb != NULL) {
            cb();
        }
}

