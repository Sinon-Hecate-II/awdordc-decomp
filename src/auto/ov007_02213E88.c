/* 30 functions from 0x02213E88 to 0x02214E24 (ov007), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; u8 pad[13]; } MapUnit145F8;
typedef struct { u8 pad[11]; u8 kind : 4; u8 flags : 4; } MapEntry14718;

void func_ov007_02213e88(void *cursor) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    extern void *data_02101e84;
    s32 new_dir;
    s32 prev_x;
    s32 prev_y;
    s32 prev_dir;
    s32 can_right;
    s32 can_left;
    s32 can_down;
    s32 can_up;
    u16 state_flags;
    void *right_obj;
    void *left_obj;
    void *down_obj;
    void *up_obj;
    void *right_child;
    void *left_child;
    void *down_child;
    void *up_child;
    void *right_obj_reload;
    void *left_obj_reload;
    void *down_obj_reload;
    void *up_obj_reload;

    prev_x = M2C_FIELD(cursor, s32 *, 0x34);
    state_flags = M2C_FIELD(data_02101e84, u16 *, 0);
    prev_y = M2C_FIELD(cursor, s32 *, 0x38);
    prev_dir = M2C_FIELD(cursor, s32 *, 0x3C);
    if (state_flags & 1) {
        func_0208fe30(0x1000D);
        func_01ffa8c4(cursor, 1);
        return;
    }
    if (state_flags & 2) {
        func_0208fe30(0x1000F);
        func_01ffa8c4(cursor, 2);
        return;
    }
    right_obj = M2C_FIELD(cursor, void **, 0x40);
    can_right = 1;
    right_child = M2C_FIELD(right_obj, void **, 0x64);
    if ((M2C_FIELD(right_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(right_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(right_child, s8 *, 0xC) != 1))) {
        can_right = 0;
    }
    if (can_right & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 0;
        M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) + 1);
    }
    left_obj = M2C_FIELD(cursor, void **, 0x44);
    can_left = 1;
    left_child = M2C_FIELD(left_obj, void **, 0x64);
    if ((M2C_FIELD(left_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(left_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(left_child, s8 *, 0xC) != 1))) {
        can_left = 0;
    }
    if (can_left & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 0;
        M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) - 1);
    }
    down_obj = M2C_FIELD(cursor, void **, 0x48);
    can_down = 1;
    down_child = M2C_FIELD(down_obj, void **, 0x64);
    if ((M2C_FIELD(down_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(down_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(down_child, s8 *, 0xC) != 1))) {
        can_down = 0;
    }
    if (can_down & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 1;
        M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) + 1);
    }
    up_obj = M2C_FIELD(cursor, void **, 0x4C);
    can_up = 1;
    up_child = M2C_FIELD(up_obj, void **, 0x64);
    if ((M2C_FIELD(up_child, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(up_obj, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(up_child, s8 *, 0xC) != 1))) {
        can_up = 0;
    }
    if (can_up & 0xFF) {
        M2C_FIELD(cursor, s32 *, 0x3C) = 1;
        M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) - 1);
    }
    new_dir = M2C_FIELD(cursor, s32 *, 0x3C);
    switch (new_dir) {                            /* irregular */
    case 0:
        if (M2C_FIELD(data_02101e84, u16 *, 2) & 0x40) {
            M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) + 1);
        }
        if (M2C_FIELD(data_02101e84, u16 *, 2) & 0x80) {
            M2C_FIELD(cursor, s32 *, 0x34) = (s32) (M2C_FIELD(cursor, s32 *, 0x34) - 1);
        }
        if (M2C_FIELD(data_02101e84, u16 *, 0) & 0x10) {
            M2C_FIELD(cursor, s32 *, 0x3C) = 1;
        }
        break;
    case 1:
        if (M2C_FIELD(data_02101e84, u16 *, 2) & 0x40) {
            M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) + 1);
        }
        if (M2C_FIELD(data_02101e84, u16 *, 2) & 0x80) {
            M2C_FIELD(cursor, s32 *, 0x38) = (s32) (M2C_FIELD(cursor, s32 *, 0x38) - 1);
        }
        if (M2C_FIELD(data_02101e84, u16 *, 0) & 0x20) {
            M2C_FIELD(cursor, s32 *, 0x3C) = 0;
        }
        break;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) <= 5) {
        M2C_FIELD(cursor, s32 *, 0x34) = 5;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) <= 5) {
        M2C_FIELD(cursor, s32 *, 0x38) = 5;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) >= 0x1E) {
        M2C_FIELD(cursor, s32 *, 0x34) = 0x1E;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) >= 0x1E) {
        M2C_FIELD(cursor, s32 *, 0x38) = 0x1E;
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) > prev_x) {
        right_obj_reload = M2C_FIELD(cursor, void **, 0x40);
        if ((s32) M2C_FIELD(right_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(right_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(right_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(right_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(right_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x34) < prev_x) {
        left_obj_reload = M2C_FIELD(cursor, void **, 0x44);
        if ((s32) M2C_FIELD(left_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(left_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(left_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(left_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(left_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) > prev_y) {
        down_obj_reload = M2C_FIELD(cursor, void **, 0x48);
        if ((s32) M2C_FIELD(down_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(down_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(down_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(down_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(down_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((s32) M2C_FIELD(cursor, s32 *, 0x38) < prev_y) {
        up_obj_reload = M2C_FIELD(cursor, void **, 0x4C);
        if ((s32) M2C_FIELD(up_obj_reload, s8 *, 0x5A) >= 0) {
            M2C_FIELD(up_obj_reload, s32 *, 0x40) = (s32) ((M2C_FIELD(up_obj_reload, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(up_obj_reload, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(up_obj_reload, s8 *, 0x5A) = 0xC;
        }
    }
    if ((M2C_FIELD(cursor, s32 *, 0x34) == prev_x) && (M2C_FIELD(cursor, s32 *, 0x38) == prev_y)) {

    } else {
        func_0208fe30(0x10011);
    }
    if (M2C_FIELD(cursor, s32 *, 0x3C) == prev_dir) {
        return;
    }
    func_0208fe30(0x10010);
}

void func_ov007_022142bc(void *arg0) {
    M2C_UNK func_ov007_0221352c(s32, s32);
    func_ov007_0221352c(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_ov007_022142d4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f890;
    func_01ffa3dc(&data_ov007_0221f890, 7);
}

void func_ov007_022142ec(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020c0adc();
    M2C_UNK func_020cfd28();
    extern void *gCur3DSpriteEngine;
    func_020c0adc();
    func_020c0784();
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    func_020cfd28();
    func_ov007_022142d4();
}

void func_ov007_02214324(M2C_UNK arg0) {
    M2C_UNK func_ov007_0221f270(s32, M2C_UNK);
    extern s32 *gCurrentMap;
    func_ov007_0221f270(*gCurrentMap + 0x5120, arg0);
    func_ov007_022121d4(1);
}

void func_ov007_02214354(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020cfd28();
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_0221f820;
    func_020c0784();
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    func_020cfd28();
    func_01ffa3dc(&data_ov007_0221f820, 7);
}

void func_ov007_02214394(void) {
    M2C_UNK func_020885fc();
    M2C_UNK func_020c002c(M2C_UNK);
    func_020885fc();
    func_020c002c(0);
}

void func_ov007_022143a8(void) {
    M2C_UNK func_ov003_022059d0();
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    func_ov003_022059d0();
    func_ov007_022121d4(1);
}

void func_ov007_022143bc(void) {
    M2C_UNK func_020bfebc(M2C_UNK);
    M2C_UNK func_02088624();
    extern u16 data_02168f14;
    if (func_020d4810() != 0) {
        data_02168f14 = (u16) (data_02168f14 | 0x40);
        func_020bfebc(0);
    }
    func_02088624();
}

void func_ov007_022143f0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f9a8;
    func_020c0784();
    func_01ffa3dc(&data_ov007_0221f9a8, 7);
}

void func_ov007_0221440c(void) {
    M2C_UNK func_020bfa80(M2C_UNK);
    func_020bfa80(0);
    func_020c002c(0);
    func_ov007_022121d4(1);
}

void func_ov007_0221442c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f918;
    func_020c0784();
    func_01ffa3dc(&data_ov007_0221f918, 7);
}

u8 func_ov007_02214448(void) {
    extern u16 data_02168f14;
    u8 var_r0;

    if (((u32) (data_02168f14 << 0x19) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov007_0221446c(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020cfd28();
    M2C_UNK func_02086720(M2C_UNK);
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_0221f780;
    func_020c0784();
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    func_020cfd28();
    if (func_ov007_022121c4() != 0) {
        func_02086720(0x46000006);
    } else {
        func_02086720(0x46000005);
    }
    func_01ffa3dc(&data_ov007_0221f780, 7);
}

void func_ov007_022144d4(void) {
    M2C_UNK func_020c0784();
    func_020c0784();
}

void func_ov007_022144e0(void) {
    M2C_UNK func_020c0784();
    func_020c0784();
}

void func_ov007_022144ec(void) {
    M2C_UNK func_020c0748(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov007_0221fc20;
    func_020c0748(&data_ov007_0221fc20, 0x50, 0x18, 0x50);
}

void func_ov007_0221450c(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) (M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_02214544(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x1);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_02214580(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x8);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_022145bc(void) {
    M2C_UNK func_ov007_022121d4(M2C_UNK);
    M2C_UNK func_020c0784();
    extern s32 *gCurrentMap;
    M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) = (u8) ((M2C_FIELD(M2C_FIELD((void *) *gCurrentMap, void **, 0x52D0), u8 *, 0xB) & ~0xF) | 0x6);
    func_ov007_022121d4(1);
    func_020c0784();
}

void func_ov007_022145f8(void) {
extern s32 *gCurrentMap;extern u16 data_ov000_021aeef4[];
s32 func_020a7310(void *);
s32 i; MapUnit145F8 *p;
p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
if(p->flags==3)p->flags=0;
else {
for(i=data_ov000_021aeef4[func_020a7310(p)]+1;i<data_ov000_021aeef4[func_020a7310(M2C_FIELD(*gCurrentMap,void **,0x52d0))]+51;i++){
p=(MapUnit145F8 *)((u8 *)*gCurrentMap+0x59a4)+i;
if(p->kind)p->flags=0;
}
((MapUnit145F8 *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->flags=3;
}
func_ov007_022121d4(1);func_020c0784();
}

void func_ov007_0221470c(void) {
    M2C_UNK func_020c0784();
    func_020c0784();
}

/* Spawn an object on the map tile (x,y) if that tile is non-empty,
   returning 1 on success and 0 when the tile has no entry. */
s32 func_ov007_02214718(s32 x, s32 y) {
    void func_020c7470(s32, s32, s32 *);
    s32 func_020c0748(s32 *, s32, s32, s32);
    extern s32 *gCurrentMap;
    extern u8 data_ov007_0221fb30[];
    u8 *base;
    u32 index;
    s32 coords[3];
    void *obj;
    base = (u8 *)*gCurrentMap;
    index = base[x + M2C_FIELD(base + y * 2, u16 *, 0x3758)];
    if (index == 0) return 0;
    M2C_FIELD(base, void **, 0x52D0) = base + 0x59A4 + index * 14;
    func_020c7470(x, y, coords);
    obj = (void *)func_020c0748((s32 *)data_ov007_0221fb30, coords[0], coords[1], 0x30);
    switch (((MapEntry14718 *)M2C_FIELD((void *)*gCurrentMap, void **, 0x52D0))->kind) {
    case 0: M2C_FIELD(obj, u8 *, 0x4E) = 0; break;
    case 1: M2C_FIELD(obj, u8 *, 0x4E) = 1; break;
    case 8: M2C_FIELD(obj, u8 *, 0x4E) = 2; break;
    case 6: M2C_FIELD(obj, u8 *, 0x4E) = 3; break;
    }
    return 1;
}

void func_ov007_02214814(s32 arg0, s32 arg1) {
    M2C_UNK func_020a68d4();
    M2C_UNK func_020d216c();
    M2C_UNK func_020d1f2c();
    M2C_UNK func_020ceffc();
    M2C_UNK func_ov007_02217a5c();
    M2C_UNK func_020cf2c8();
    extern s32 *gCurrentMap;
    func_020a68d4();
    func_020d216c();
    func_020d1f2c();
    M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5144) = (u16) arg0;
    M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5146) = (u16) arg1;
    func_020ceffc();
    func_ov007_02217a5c();
    func_020cf2c8();
}

#pragma optimization_level 4
#pragma opt_strength_reduction off
void func_ov007_02214864(s32 arg0) {
    M2C_UNK func_020a68d4();
    M2C_UNK func_020d216c();
    M2C_UNK func_020d1f2c();
    M2C_UNK func_020ceffc();
    M2C_UNK func_020cf2c8();
    void func_ov007_02214814(s32, s32);
    extern s32 *gCurrentMap;

    if (arg0 < 0) {
        func_ov007_02214814(*(u16 *) ((u8 *) *gCurrentMap + 0x5144), *(u16 *) ((u8 *) *gCurrentMap + 0x5146));
        return;
    }
    func_020a68d4();
    func_020d216c();
    func_020d1f2c();
    func_020ceffc();
    {
        s32 x;
        s32 y;
        for (y = 0; y < *(u16 *) ((u8 *) *gCurrentMap + 0x5146); y++) {

            for (x = 0; x < *(u16 *) ((u8 *) *gCurrentMap + 0x5144); x++) {
                switch (arg0) {
                case 8:
                    *(u16 *) ((u8 *) *gCurrentMap + (*(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + x) * 2 + 0xa10) = 3;
                    *(u8 *) ((u8 *) *gCurrentMap + x + *(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + 0x1420) = 8;
                    break;
                case 1:
                    *(u16 *) ((u8 *) *gCurrentMap + (*(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + x) * 2 + 0xa10) = 1;
                    *(u8 *) ((u8 *) *gCurrentMap + x + *(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + 0x1420) = 1;
                    break;
                case 4:
                    *(u16 *) ((u8 *) *gCurrentMap + (*(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + x) * 2 + 0xa10) = 0x20;
                    *(u8 *) ((u8 *) *gCurrentMap + x + *(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + 0x1420) = 4;
                    break;
                case 3:
                    *(u16 *) ((u8 *) *gCurrentMap + (*(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + x) * 2 + 0xa10) = 0x21;
                    *(u8*) ((u8 *) *gCurrentMap + x + *(u16 *) ((u8 *) *gCurrentMap + y * 2 + 0x3758) + 0x1420) = 3;
                    break;
                default:
                    break;
                }
            }
        }
    }
    func_020cf2c8();
}

void func_ov007_02214a6c(s32 arg0, s32 arg1) {
    M2C_UNK func_020c79ec(void);
    M2C_UNK func_020c79f8(void);
    M2C_UNK func_020c7a08(void);
    M2C_UNK func_020c879c(M2C_UNK);
    M2C_UNK func_020a68d4(void);
    M2C_UNK func_020d216c(void);
    M2C_UNK func_020d1f2c(void);
    M2C_UNK func_020ceffc(void);
    M2C_UNK func_0207f460(void);
    void *func_020a660c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov007_0221b688(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cf2c8(void);
    extern s32 *gCurrentMap;

    s32 width = arg0;
    s32 height = arg1;
    void *r4v;
    void *r5;
    void *r6;
    s32 y;
    s32 x;
    void *map;
    M2C_UNK val;
    s32 w2, h2;
    u32 linear;
    u16 rowOffset, idx;
    M2C_UNK dword;
    s32 maskA, maskB, maskC;
    s32 bits;
    u8 old;
    void *ptr;
    s32 u;

    r4v = func_020c79ec();
    r5 = (void *)func_020c79f8();
    r6 = (void *)func_020c7a08();
    func_020c879c(r4v);

    map = (void *)*gCurrentMap;
    *(u16 *)((u8 *)map + 0x5144) = (u16)width;
    *(u16 *)((u8 *)map + 0x5146) = (u16)height;

    func_020a68d4();
    func_020d216c();
    func_020d1f2c();
    func_020ceffc();

    map = (void *)*gCurrentMap;
    for (y = 0; y < *(u16 *)((u8 *)map + 0x5146); y++) {
        s32 xdim = *(u16 *)((u8 *)map + 0x5144);
        for (x = 0; x < xdim; x++) {
            map = (void *)*gCurrentMap;
            rowOffset = *(u16 *)((u8 *)map + y * 2 + 0x3758);
            idx = (u16)(x + rowOffset);
            *(u16 *)((u8 *)map + idx * 2 + 0x0A10) = 3;
            map = (void *)*gCurrentMap;
            rowOffset = *(u16 *)((u8 *)map + y * 2 + 0x3758);
            idx = (u16)(x + rowOffset);
            *(u8 *)((u8 *)map + idx + 0x1420) = 8;
        }
    }

    map = (void *)*gCurrentMap;
    w2 = *(u8 *)((u8 *)r6 + 0x04);
    h2 = *(u8 *)((u8 *)r6 + 0x05);
    for (y = 0; y < *(u16 *)((u8 *)map + 0x5146); y++) {
        s32 xdim = *(u16 *)((u8 *)map + 0x5144);
        for (x = 0; x < xdim; x++) {
            if (x >= w2 || y >= h2) continue;
            map = (void *)*gCurrentMap;
            linear = (u32)(y * w2 + x);
            val = *(M2C_UNK *)((u8 *)r5 + linear);
            rowOffset = *(u16 *)((u8 *)map + y * 2 + 0x3758);
            idx = (u16)(x + rowOffset);
            *(u8 *)((u8 *)map + idx + 0x1420) = (u8)val;
            val = func_0207f460();
            *(u16 *)((u8 *)map + idx * 2 + 0x0A10) = (u16)val;
        }
    }

    y = 0;
    r5 = (void *)((u8 *)r6 + 0x384);
    val = *(M2C_UNK *)((u8 *)r6 + 0x2F);
    for (y = 0; y < (s32)val; y++) {
        dword = *(M2C_UNK *)r5;
        maskA = (s32)(((u32)dword << 27) >> 27);
        maskB = (s32)(((u32)dword << 22) >> 27);
        maskC = (s32)(((u32)dword << 17) >> 27);
        if (width <= maskA) { r5 = (void *)((u8 *)r5 + 4); continue; }
        if (maskB >= height) { r5 = (void *)((u8 *)r5 + 4); continue; }
        ptr = func_020a660c(maskA, maskB, maskC);
        if (ptr != 0) {
            bits = (s32)(((u32)dword << 10) >> 28);
            old = *(u8 *)((u8 *)ptr + 0x0B);
            old = (u8)((old & ~0x0F) | (bits & 0x0F));
            *(u8 *)((u8 *)ptr + 0x0B) = old;
        }
        r5 = (void *)((u8 *)r5 + 4);
    }

    if (width > 0) {
        u = height - 1;
        for (x = 0; x < width; x++) {
            func_ov007_0221b688(x, u);
        }
    }
    if (height > 0) {
        u = width - 1;
        for (y = 0; y < height; y++) {
            func_ov007_0221b688(u, y);
        }
    }

    func_020cf2c8();
}

s32 Map_MinDistanceThreshold(s32 arg0) {
    M2C_UNK func_0207ca08(M2C_UNK);
    M2C_UNK func_0207c8ec(M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    void *temp_r0;
    s32 var_r1;
    s32 var_r0;
    s32 var_r5;

    temp_r0 = (void *) *gCurrentMap;
    var_r1 = (s32) (M2C_FIELD(temp_r0, u16 *, 0x5146) << 8);
    var_r0 = (s32) (M2C_FIELD(temp_r0, u16 *, 0x5144) << 8);
    var_r5 = func_0207ca08((s32) (var_r1 * var_r0));
    return func_0207c8ec((s32) (arg0 * var_r5), func_0207ca08(0x3840000));
}

void func_ov007_02214d88(void) {
    M2C_UNK Map_MinDistanceThreshold();
    M2C_UNK RandomIntRange();
    RandomIntRange();
    Map_MinDistanceThreshold();
}

s32 func_ov007_02214d98(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK RandomIntRange(M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    s32 var_r4;
    s32 var_r0;

    var_r4 = 0;
loop:
    var_r4++;
    if (var_r4 > 0x64) {
        return 0;
    }
    var_r0 = RandomIntRange(arg0, arg1);
    if (var_r0 < 0) {
        goto loop;
    }
    switch (arg2) {
    case 0:
        if (var_r0 >= M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5144)) {
            goto loop;
        }
        return var_r0;
    case 1:
        if (var_r0 >= M2C_FIELD((void *) *gCurrentMap, u16 *, 0x5146)) {
            goto loop;
        }
        return var_r0;
    default:
        return var_r0;
    }
}

