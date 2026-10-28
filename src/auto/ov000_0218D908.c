/* 4 functions from 0x0218D908 to 0x0218E584 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct {u8 pad[0x58];u16 row;} ScanRow;
static inline u16 ScanHeight(void *p){return M2C_FIELD(p,u16 *,0x5146);}

M2C_UNK func_ov000_0218d908(void) {
    return 0;
}

void func_ov000_0218dda4(void) {
    M2C_UNK func_01ffc328(s32);
    M2C_UNK func_ov000_02199d74(s16, s16, M2C_UNK, u8, s32);
    s32 func_ov000_021aa820(s16 *, u16, M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
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
    void **owner;
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
    func_ov000_02199d74((s16) var_r4, (s16) var_r5, 0x13, (u8) pos[0], (s32) (u8) pos[1]);
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

s32 func_ov000_0218e340(void) { return 0; }

