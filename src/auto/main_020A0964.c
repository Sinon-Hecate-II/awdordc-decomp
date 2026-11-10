/* 16 functions from 0x020A0964 to 0x020A1944 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

typedef struct { u8 kind : 6; u8 owner : 2; } MapUnitBits;
typedef struct { u16 unk0 : 13; u16 enabled : 1; u16 unk14 : 2; } MapRuleBits;
typedef struct { u32 value : 8; u32 rest : 24; } MapPlayerBits;

typedef struct { s8 unk0[0x36]; s8 x[12]; s8 y[12]; s8 fuel[12]; } MapPathCoords;

static inline s32 GetPathX(s8 *ctx, s32 index) { return (ctx + index)[0x36]; }
static inline s32 GetPathY(s8 *ctx, s32 index) { return (ctx + index)[0x42]; }

void func_020a0964(s32 a, s32 b, u16 *out) {
    M2C_UNK func_020a76d4(M2C_UNK);
    M2C_UNK func_020a85c8(M2C_UNK);
    M2C_UNK SelectMapLayer(M2C_UNK);
    M2C_UNK func_020a0560(void);
    M2C_UNK func_020a0360(void);
    M2C_UNK func_020a061c(void);
    M2C_UNK func_020a05d8(M2C_UNK, M2C_UNK);
    M2C_UNK func_0207c2f0(void);
    M2C_UNK func_020a0750(M2C_UNK, M2C_UNK);

    extern s32 *gCurrentMap;
    extern s32 gUnitMovePath;
    extern u8 gUnitMinAttackRange[];

    u8 *base;
    s8 *ctx;
    s8 idx;
    s8 f36, f42;
    u8 *unit;
    u8 kind;
    s32 attr;
    s32 cap;
    s32 best;
    s32 manX, manY, manhattan;
    s32 terrain;
    u16 width, height;
    u8 *rowPtr;
    s32 inner, outer;
    s32 best2;
    s32 score;

    base = (u8 *)*gCurrentMap;
    ctx = (s8 *)gUnitMovePath;
    idx = ctx[0x5b];
    ctx = ctx + idx;
    f36 = ctx[0x36];
    f42 = ctx[0x42];

    unit = *(u8 **)(base + 0x52d0);
    kind = unit[0] & 0x3F;
    attr = gUnitMinAttackRange[kind * 112];
    cap = func_020a76d4((M2C_UNK)unit);

    if (cap > 1 && func_020a85c8(kind) == 0) {
        out[0] = unit[1];
        out[1] = unit[2];
        return;
    }

    manX = f42 - b;
    if (manX < 0) manX = -manX;
    manY = f36 - a;
    if (manY < 0) manY = -manY;
    manhattan = manX + manY;
    if (manhattan >= attr && manhattan <= cap) {
        terrain = base[f36 + *(u16 *)(base + (f42 << 1) + 0x3758)];
        if (terrain == 0) {
            out[0] = f36;
            out[1] = f42;
            return;
        }
    }

    SelectMapLayer((M2C_UNK)(base + 0x2338));
    func_020a0560();

    best = 0;
    height = *(u16 *)(base + 0x5146);
    width = *(u16 *)(base + 0x5144);
    for (outer = 0; outer < (s32)height; outer++) {
        for (inner = 0; inner < (s32)width; inner++) {
            rowPtr = *(u8 **)(base + outer * 4 + 0x52e8);
            terrain = (s8)rowPtr[inner];
            if (terrain < 0) continue;
            manX = a - inner;
            if (manX < 0) manX = -manX;
            manY = b - outer;
            if (manY < 0) manY = -manY;
            manhattan = manX + manY;
            if (manhattan < attr || manhattan > cap) continue;
            score = func_020a0750(inner, outer);
            if (score == 0) continue;
            if (score > best) {
                best = score;
                out[0] = (u16)inner;
                out[1] = (u16)outer;
            } else if (score == best) {
                if (func_0207c2f0() & 1) {
                    out[0] = (u16)inner;
                    out[1] = (u16)outer;
                }
            }
        }
    }

    SelectMapLayer((M2C_UNK)(base + 0x1e30));
    if (best != 0) return;

    best2 = 0;
    height = *(u16 *)(base + 0x5146);
    width = *(u16 *)(base + 0x5144);
    for (outer = 0; outer < (s32)height; outer++) {
        for (inner = 0; inner < (s32)width; inner++) {
            rowPtr = *(u8 **)(base + outer * 4 + 0x52e8);
            terrain = (s8)rowPtr[inner];
            if (terrain < 0 || terrain > 110) continue;
            manX = a - inner;
            if (manX < 0) manX = -manX;
            if (manY < 0) manY = -manY;
            manhattan = manX + manY;
            if (manhattan < attr || manhattan > cap) continue;
            score = func_020a0750(inner, outer);
            if (score == 0) continue;
            if (score > best2) {
                best2 = score;
                out[0] = (u16)inner;
                out[1] = (u16)outer;
            } else if (score == best2) {
                if (func_0207c2f0() & 1) {
                    out[0] = (u16)inner;
                    out[1] = (u16)outer;
                }
            }
        }
    }
    return;
}

#pragma push
#pragma opt_common_subs off
void func_020a0d18(void) {
    M2C_UNK func_020a004c(M2C_UNK, M2C_UNK);
    M2C_UNK SelectMapLayer(M2C_UNK);
    M2C_UNK func_020a0560(void);
    M2C_UNK func_020a086c(M2C_UNK, M2C_UNK);
    M2C_UNK func_01ffc4b8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020a0360(void);
    M2C_UNK func_020a061c(void);
    M2C_UNK func_020a05d8(M2C_UNK, M2C_UNK);
    s32 func_020a0300(s8, s8);
    void func_020a0068(s8);
    void func_020a01c0(s8, s8);
    s32 func_020a33c4(s32);
    extern s32 *gCurrentMap;
    extern s32 gUnitMovePath;
    extern u8 data_ov000_021b5c09[];
    extern u16 gMapConfig[];
    extern u8 data_021261d0[];
    extern u8 gMovementTypeTable[];
    s32 cx, cy, dx, dy;
    s8 *ctx;
    u8 *player;
    s32 y, idx, fuel, x;
    u8 *base;
    u32 mode;
    s32 startX;
    u8 *initialBase;
    u32 kind;
    s32 rowOffset;
    s8 index;
    s32 owner, result;
    s8 *costTable;
    s32 terrain;
    u32 moveType;
    s16 sx, sy;
    initialBase = (u8 *)*gCurrentMap;
    if (*(u16 *)(initialBase + 0x52b4) != 2) return;
    ctx = (s8 *)gUnitMovePath;
    startX = *(s16 *)(initialBase + 0x52c2);
    if (ctx[0x34] == startX && ctx[0x35] == *(s16 *)(initialBase + 0x52c4)) return;
    func_020a004c((u16)startX, *(u16 *)(initialBase + 0x52c4));
    base = (u8 *)*gCurrentMap;
    y = *(s16 *)(base + 0x52c4);
    x = *(s16 *)(base + 0x52c2);
    if ((*(s8 **)(base + y * 4 + 0x52e8))[x] > 110) {
        kind = (*(MapUnitBits **)(base + 0x52d0))->kind;
        if (data_ov000_021b5c09[kind * 112] > 1) return;
        ctx = (s8 *)gUnitMovePath;
        index = ctx[0x5b];
        cy = ctx[0x42 + index];
        cx = ctx[0x36 + index];
        dy = cy - y; if (dy < 0) dy = -dy;
        dx = cx - x; if (dx < 0) dx = -dx;
        if (dx + dy == 1 && base[cx + *(u16 *)(base + cy * 2 + 0x3758)] == 0) return;
        SelectMapLayer(base + 0x2338);
        func_020a0560();
        sx = x; sy = y;
        if (func_020a086c(&sx, &sy)) {
            func_01ffc4b8(sx, sy, (u8 *)*gCurrentMap + 0x5388);
            func_020a0360();
            if (!func_020a061c()) func_020a05d8(sx, sy);
        } else {
            SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
            sx = x; sy = y;
            if (func_020a086c(&sx, &sy)) {
                SelectMapLayer((u8 *)*gCurrentMap + 0x2338);
                func_020a05d8(sx, sy);
            } else {
                SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
                return;
            }
        }
        SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
        x = sx; y = sy;
    }
    if ((*(s8 **)((u8 *)*gCurrentMap + y * 4 + 0x52e8))[x] == -1) return;
    result = func_020a0300((s8)x, (s8)y);
    if (result != -1) {
        func_020a0068((s8)(result + 1));
        ctx = (s8 *)gUnitMovePath;
        ((u8 *)*gCurrentMap)[0x52d5] = ctx[0x5a] - (ctx + ctx[0x5b])[0x4e];
        return;
    }
    base = (u8 *)*gCurrentMap;
    owner = (base[0x52d4] >> 6) + 1;
    player = base + 0x67a4 + owner * 0x8c;
    if (((MapRuleBits *)gMapConfig)->enabled == 0) mode = 0;
    else mode = ((MapPlayerBits *)(player + 0x6c))->value;
    ctx = (s8 *)gUnitMovePath;
    idx = ctx[0x5b];
    fuel = (ctx + idx)[0x4e];
    result = func_020a33c4(owner);
    kind = (*(MapUnitBits **)((u8 *)*gCurrentMap + 0x52d0))->kind;
    rowOffset = *(u16 *)(base + y * 2 + 0x3758);
    terrain = (base + (x + rowOffset))[0x1420];
    moveType = gMovementTypeTable[kind * 112];
    costTable = *(s8 **)(data_021261d0 + mode * 0x9c + result * 0x28 + player[0x25] * 4);
    if (fuel >= (costTable + moveType * 32)[terrain & 31]) {
        ctx = (s8 *)gUnitMovePath;
        dy = (ctx + idx)[0x42] - y; if (dy < 0) dy = -dy;
        dx = (ctx + idx)[0x36] - x; if (dx < 0) dx = -dx;
        if (dx + dy == 1) {
            func_020a01c0((s8)x, (s8)y);
            ctx = (s8 *)gUnitMovePath;
            ((u8 *)*gCurrentMap)[0x52d5] = ctx[0x5a] - (ctx + ctx[0x5b])[0x4e];
            return;
        }
    }
    if (fuel == 0) func_020a0068(1);
    SelectMapLayer((u8 *)*gCurrentMap + 0x2338);
    func_020a0560();
    base = (u8 *)*gCurrentMap;
    if ((*(s8 **)(base + y * 4 + 0x52e8))[x] == -1) {
        func_020a05d8(x, y);
    } else {
        func_01ffc4b8(x, y, base + 0x5388);
        func_020a0360();
        if (!func_020a061c()) func_020a05d8(x, y);
    }
    SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
}
#pragma pop
s32 UnitPath_GetIncomingDir(s32 arg0) {
    extern s32 gUnitMovePath;
    s8 temp_r0;
    s8 temp_r0_2;
    s8 temp_r1;
    s8 temp_r1_2;
    void *temp_r2;
    void *temp_r3;

    if (arg0 == 0) {
        return 0;
    }
    temp_r3 = gUnitMovePath + arg0;
    temp_r2 = gUnitMovePath + (arg0 - 1);
    temp_r1 = M2C_FIELD(temp_r3, s8 *, 0x36);
    temp_r0 = M2C_FIELD(temp_r2, s8 *, 0x36);
    if ((s32) temp_r0 < (s32) temp_r1) {
        return 3;
    }
    if ((s32) temp_r0 > (s32) temp_r1) {
        return 1;
    }
    temp_r1_2 = M2C_FIELD(temp_r3, s8 *, 0x42);
    temp_r0_2 = M2C_FIELD(temp_r2, s8 *, 0x42);
    if ((s32) temp_r0_2 < (s32) temp_r1_2) {
        return 4;
    }
    if ((s32) temp_r0_2 > (s32) temp_r1_2) {
        return 2;
    }
    return 0;
}

s32 UnitPath_GetOutgoingDir(s32 arg0) {
    extern s32 gUnitMovePath;
    void *temp_r2;
    void *temp_r3;
    s8 a, b;
    temp_r2 = gUnitMovePath;
    if (arg0 == M2C_FIELD(temp_r2, s8 *, 0x5B)) return 0;
    temp_r3 = (s32)temp_r2 + (arg0 + 1);
    temp_r2 = (s32)temp_r2 + arg0;
    b = M2C_FIELD(temp_r3, s8 *, 0x36);
    a = M2C_FIELD(temp_r2, s8 *, 0x36);
    if (a < b) return 1;
    if (a > b) return 3;
    b = M2C_FIELD(temp_r3, s8 *, 0x42);
    a = M2C_FIELD(temp_r2, s8 *, 0x42);
    if (a < b) return 2;
    if (a > b) return 4;
    return 0;
}

void func_020a12c0(void *arg0) {
    M2C_UNK func_02077480();
    func_02077480();
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void func_020a12d8(void) {
    M2C_UNK func_020774b0();
    void DrawUnitMovePath(M2C_UNK, M2C_UNK);
      func_020774b0();
      func_020a0d18();
      DrawUnitMovePath(0, 0);
  }

  void func_020a12f4(void) {
      M2C_UNK func_0207749c();
      func_0207749c();
  }

#pragma push
#pragma opt_strength_reduction off
/* Draws the pending move path of the unit under the cursor: for every path
 * step it picks the arrow tile from gPathArrowTiles by the directions of the
 * segments entering and leaving the step and draws it as a 16x16 sprite at
 * the cell's world position. Nothing is drawn for an empty path or when the
 * path belongs to a unit of another player. */
void DrawUnitMovePath(s32 arg0, s32 arg1) {
    M2C_UNK func_0207d130(M2C_UNK *, s32 *, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    s32 UnitPath_GetOutgoingDir(s32);
    s32 UnitPath_GetIncomingDir(s32);
    extern s32 *gCurrentMap;
    extern s32 gUnitMovePath;
    extern u16 gPathArrowTiles[];
    extern M2C_UNK gSpriteDesc16x16;

    register void *map;
    register s32 index;
    s8 *path;
    u8 *unit;
    s32 owner;
    s8 step;
    s32 outDir;
    s32 inDir;
    u16 arrow;
    s8 *stepPtr;
    s32 pos[3];

    path = (s8 *)gUnitMovePath;
    if (path[UNIT_PATH_LENGTH] == 0) {
        return;
    }
    map = (void *)*gCurrentMap;
    unit = *(u8 **)((u8 *)map + MAP_CURSOR_UNIT);
    if (unit != NULL) {
        index = unit ? ((s8 *)unit - ((s8 *)map + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
        owner = (index >> 6) + 1;
    } else {
        owner = 0;
    }
    if (*(u16 *)((u8 *)map + MAP_CURRENT_PLAYER) != owner) {
        return;
    }
    /* polygon attribute, then save the 3D matrix stack around the arrows */
    *(volatile s32 *)0x040004A4 = 0x1F0080;
    *(volatile s32 *)0x04000444 = 0;
    path = (s8 *)gUnitMovePath;
    step = path[UNIT_PATH_LENGTH];
    for (; step >= 0; step--) {
        outDir = UnitPath_GetOutgoingDir((u8)step);
        inDir = UnitPath_GetIncomingDir((u8)step);
        arrow = ((u16 (*)[5])gPathArrowTiles)[outDir][inDir];
        stepPtr = (s8 *)gUnitMovePath + (s32)step;
        pos[0] = (s32)stepPtr[UNIT_PATH_X] << 4;
        pos[1] = (s32)stepPtr[UNIT_PATH_Y] << 4;
        pos[2] = 0x851;
        /* nudge an arrowhead half an arrow width toward the direction it shows */
        switch ((s32)arrow - 0xC0) {
        case 2:
            pos[0] -= 4;
            break;
        case 4:
            pos[1] -= 4;
            break;
        case 6:
            pos[0] += 4;
            break;
        case 0:
            pos[1] += 4;
            break;
        default:
            break;
        }
        pos[0] = pos[0] * 0x30;
        pos[1] = pos[1] * 0x30;
        func_0207d130(&gSpriteDesc16x16, pos, 0x22F20, 0x1460, 0x30000, 0, 0, 0x80, 0x80, 0x1800, arrow);
    }
    *(volatile s32 *)0x04000448 = 1;
    return;
}
#pragma pop
void func_020a1508(void) {

}

void func_020a150c(void *arg0) {
    M2C_UNK func_0207d130(M2C_UNK *, s32 *, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    extern M2C_UNK gSpriteDesc16x16;
    s32 vec[3];
    s32 temp = M2C_FIELD(arg0, s16 *, 0x6C) * 2;
    *(volatile s32 *)0x040004A4 = 0x1F0080;
    vec[0] = (M2C_FIELD(arg0, s32 *, 0x34) << 4) * 0x30;
    vec[1] = (M2C_FIELD(arg0, s32 *, 0x38) << 4) * 0x30;
    vec[2] = 0x891;
    func_0207d130(&gSpriteDesc16x16, vec, 0x22F20, 0x1480, 0x30000, 0, 0, 0x80, 0x80, 0x1800, temp + 0x100);
}

void func_020a15b4(s32 arg0, s32 arg1, s16 arg2) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    extern M2C_UNK data_0211fb60;
    void *temp_r0;
    temp_r0 = func_01ffa3dc(&data_0211fb60, 7);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg2;
}

void func_020a15e4(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_0211fb60;
    func_01ffa9e4(&data_0211fb60);
}

#pragma opt_strength_reduction off
void func_020a15f8(void) {
    extern s32 *gCurrentMap;
    s32 x, y;
    u8 *base;
    u8 *p;
    base = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(base, u16 *, 0x5144); x++) {
            base = base + x + M2C_FIELD(base + y * 2, u16 *, 0x3758);
            p = base;
            if ((p[0x1420] & 0x1F) == 0x1C) p[0x539C] = 0xE3;
            else p[0x539C] = 0;
            base = (u8 *)*gCurrentMap;
        }
    }
}
#pragma opt_strength_reduction reset
void func_020a16a8(u8 *arg0) {
    extern s32 *gCurrentMap;
    s32 var_ip;
    u8 *var_lr;
    u8 *var_r0;
    u8 temp_r1;

    var_r0 = arg0;
    var_lr = *gCurrentMap + 0x539C;
    if (*var_r0 == 0xFF) {
        return;
    }
    do {
        temp_r1 = *var_r0;
        if (temp_r1 & 0x80) {
            var_r0 += 1;
            *var_lr = temp_r1;
            var_lr += 1;
        } else {
            var_ip = 0;
            if ((s32) temp_r1 > 0) {
                do {
                    *var_lr = 0;
                    var_lr += 1;
                    var_ip += 1;
                } while (var_ip < (s32) *var_r0);
            }
            var_r0 += 1;
        }
    } while (*var_r0 != 0xFF);
}

void func_020a1720(u8 *dst) {
extern s32 *gCurrentMap;
s32 i;
u8 count;
u8 *p;
s32 n;
void *base;
count = 0;
i = count;
base=(void *)*gCurrentMap;
n=M2C_FIELD(base,u16 *,0x5144)*M2C_FIELD(base,u16 *,0x5146);
p=(u8 *)base+0x539c;
for(;i<n;i++,p++) {
if(*p) {
if(count){*dst++=count;count=0;}
*dst++=*p;
}else {
count++;
if(count==127){*dst++=count;count=0;}
}
}
if(count)*dst++=count;
*dst=255;
}

#pragma opt_strength_reduction off
void func_020a17c0(s32 arg0, s32 arg1) {
    M2C_UNK SelectMapLayer(M2C_UNK);
    M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    s32 y;
    s32 x;
    u8 *base;

    base = (u8 *)*gCurrentMap;
    SelectMapLayer(base + 0x1E30);
    FloodFillUnitRange(arg0, arg1, 0x1D, 0x6E, 0);

    base = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, 0x5146); y++) {
        base = (u8 *)*gCurrentMap;
        for (x = 0; x < M2C_FIELD(base, u16 *, 0x5144); x++) {
            if (M2C_FIELD(M2C_FIELD(base + (y << 2), s8 **, 0x52E8), s8 *, x) >= 0) {
                u16 off = M2C_FIELD(base + (y << 1), u16 *, 0x3758);
                u8 cell = M2C_FIELD(off + (base + x), u8 *, 0x1420);
                if (((cell & 0xE0) >> 5) != 0) {
                    M2C_FIELD(base + (x + off) * 2 + 0xA00, u16 *, 0x10) = 3;
                    base = (u8 *)*gCurrentMap;
                    M2C_FIELD(M2C_FIELD(base + (y << 1),u16 *,0x3758) + (base + x), u8 *, 0x1420) = 8;
                } else {
                    if (cell == 0x1C) {
                        M2C_FIELD(base + (x + off) * 2 + 0xA00, u16 *, 0x10) = 5;
                    } else {
                        M2C_FIELD(base + (x + off) * 2 + 0xA00, u16 *, 0x10) = 4;
                    }
                    base = (u8 *)*gCurrentMap;
                    M2C_FIELD(M2C_FIELD(base + (y << 1),u16 *,0x3758) + (base + x), u8 *, 0x1420) = 1;
                }
            }
            base = (u8 *)*gCurrentMap;
        }
    }
}
#pragma opt_strength_reduction reset
