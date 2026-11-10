/* 7 functions from 0x02175310 to 0x02175FB0 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 value : 6; } UnitKind75310;
typedef struct { u32 value : 8; } UnitByte75310;
typedef struct { s16 v[10]; } Tiles75a20;
typedef struct { s16 v[6]; } TeamTiles75a20;
extern const Tiles75a20 data_ov000_021ae2b2;

/* Initializes a unit entry's nested battle state from a character template and stat table. */
#pragma push
#pragma optimization_level 4
void func_ov000_02175310(void *arg0, void *arg1) {
    extern s32 *gCurrentMap;
    void *self = arg0;
    void *p = arg1;
    s32 low6;
    s32 c, c2, tmp;
    void *state;

    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x8) = func_020a735c(p);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x50) = func_020a7310(p);
    c = func_020a7310(p);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x0) = (s32)M2C_FIELD((c * 0x8C) + *gCurrentMap, u8 *, 0x67CD);
    if (func_020a7cfc(p) != 0) {
        c2 = func_020a7310(p);
        M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0xC) = (s32)((UnitByte75310 *)((c2 * 0x8C) + *gCurrentMap + 0x6810))->value;
    } else {
        M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0xC) = -1;
    }
    c = func_020d0468(M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x50), M2C_FIELD(p, u8 *, 1), M2C_FIELD(p, u8 *, 2));
    if (c != -1) M2C_FIELD(M2C_FIELD(self, void **, 0x10), u8 *, 0x49) = 1;
    else M2C_FIELD(M2C_FIELD(self, void **, 0x10), u8 *, 0x49) = 0;

    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x10) = func_020a789c(p);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x14) = func_020a78ac(p);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x18) = func_020a78c4(p);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x1C) = func_020a78d4(p);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x20) = func_020a25d8(p, M2C_FIELD(p, u8 *, 1), M2C_FIELD(p, u8 *, 2));
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x24) = func_020a2608(p, M2C_FIELD(p, u8 *, 1), M2C_FIELD(p, u8 *, 2));
    low6 = ((UnitKind75310 *)p)->value;
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x28) = func_020a7b24((s32)low6);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x2C) = func_020a2698(p, M2C_FIELD(p, u8 *, 1), M2C_FIELD(p, u8 *, 2));
    low6 = ((UnitKind75310 *)p)->value;
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x30) = func_020a7bf8((s32)low6);
    low6 = ((UnitKind75310 *)p)->value;
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x34) = func_020a7bec((s32)low6);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x38) = func_020a26c8(p, M2C_FIELD(p, u8 *, 1), M2C_FIELD(p, u8 *, 2));
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x3C) = func_020a78ec(p);
    low6 = ((UnitKind75310 *)p)->value;
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x40) = func_020a7b0c((s32)low6);
    tmp = func_020a26f8(p, M2C_FIELD(p, u8 *, 1), M2C_FIELD(p, u8 *, 2));
    c2 = func_020a7848(p, M2C_FIELD(p, u8 *, 1), M2C_FIELD(p, u8 *, 2));
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x44) = tmp + c2;
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x4C) = func_020a788c(p);
    low6 = ((UnitKind75310 *)p)->value;
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x54) = func_020a7c98((s32)low6);

    tmp = func_020a334c(func_020a7310(p));
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s8 *, 0x48) = (s8)tmp;
    c = M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x50);
    M2C_FIELD(M2C_FIELD(self, void **, 0x10), s32 *, 0x60) = (s32)M2C_FIELD((c * 0x8C) + *gCurrentMap, u8 *, 0x67C1);
    low6 = ((UnitKind75310 *)p)->value;
    func_ov000_02176af8(self, (s32)low6);
    if (M2C_FIELD(self, s32 *, 4) == 0) {
        M2C_FIELD(self, s32 *, 4) = 1;
    }
}
#pragma pop
void func_ov000_021755b4(void *entry, s32 templateIndex, s32 statIndex) {
    s32 func_020a7b0c(s32);
    s32 func_020a7b24(s32);
    s32 func_020a7bec(s32);
    s32 func_020a7bf8(s32);
    s32 func_020a7c50(s32);
    s32 func_020a7c68(s32);
    s32 func_020a7c98(s32);
    M2C_UNK func_ov000_02176af8(void *, s32);
    extern s32 *gCurrentMap;
    void *state;

    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 8) = statIndex;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x50) = templateIndex;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0) = (s32) M2C_FIELD(((templateIndex * 0x8C) + *gCurrentMap), u8 *, 0x67CD);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0xC) = -1;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s8 *, 0x49) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x10) = func_020a7c68(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x14) = func_020a7c68(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x18) = func_020a7c50(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x1C) = func_020a7c50(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x20) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x24) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x28) = func_020a7b24(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x30) = func_020a7bf8(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x34) = func_020a7bec(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x40) = func_020a7b0c(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x44) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x4C) = 0x63;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x54) = func_020a7c98(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s8 *, 0x48) = 0;
    state = M2C_FIELD(entry, void **, 0x10);
    M2C_FIELD(state, s32 *, 0x60) = (s32) M2C_FIELD(((M2C_FIELD(state, s32 *, 0x50) * 0x8C) + *gCurrentMap), u8 *, 0x67C1);
    func_ov000_02176af8(entry, statIndex);
    if (M2C_FIELD(entry, s32 *, 4) == 0) {
        M2C_FIELD(entry, s32 *, 4) = 1;
    }
}

void func_ov000_02175740(void *arg0) {
    M2C_UNK func_01ff85b8(s32, s32, s32);
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    M2C_UNK func_02080860(s32, s32, s32, u16, s32);
    M2C_UNK func_020808dc(s32, s32, s32, s32);
    u32 func_ov000_02175074();
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021ae2d0;
    extern M2C_UNK data_ov000_021c2158;
    extern M2C_UNK data_ov000_021c23ec;
    extern M2C_UNK data_ov000_021c2680;
    extern M2C_UNK data_ov000_021c2918;
    extern M2C_UNK data_ov000_021c2bb0;
    extern M2C_UNK data_ov000_021c2e50;
    void *saved;
    s32 gfx;
    M2C_UNK *gfxTable;

    gfx = M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x28);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    switch (func_ov000_02175074()) {
    case 0:
        gfxTable = &data_ov000_021c2e50;
        break;
    case 1:
        gfxTable = &data_ov000_021c2bb0;
        break;
    case 2:
        gfxTable = &data_ov000_021c2680;
        break;
    case 3:
        gfxTable = &data_ov000_021c23ec;
        break;
    case 4:
        gfxTable = &data_ov000_021c2918;
        break;
    case 5:
        gfxTable = &data_ov000_021c2158;
        break;
    default:
        gfxTable = &data_ov000_021c2e50;
        break;
    }
    func_0207c780(gfxTable, gfx);
    func_01ff85b8(gfx, 0x800, 0x180);
    func_020808dc(gfx, 0x20, 0x18, 0xB);
    if (M2C_FIELD(&data_ov000_021ae2d0, u32 *, M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 8) * 0xC) == 1) {
        func_02080860(gfx + 0x220, 4, 1, 0x304, 0xB);
        func_02080860(gfx + 0x260, 4, 1, 0x324, 0xB);
    }
    gCur3DSpriteEngine = saved;
}

void func_ov000_02175878(void *arg0) {
    void func_01ff9e44(void *, s32, s32);
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    void func_0209b26c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, u16);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    extern u8 data_ov000_021ae2a0[];
    extern u8 *data_ov000_021dec34[][4];
    extern s32 data_ov000_021debc8[];
    u8 local[6];
    u8 flag;
    u8 idx;
    void *saved;
    s32 color;
    s32 base;

    local[0] = data_ov000_021ae2a0[0];
    local[1] = data_ov000_021ae2a0[1];
    local[2] = data_ov000_021ae2a0[2];
    local[3] = data_ov000_021ae2a0[3];
    local[4] = data_ov000_021ae2a0[4];
    local[5] = data_ov000_021ae2a0[5];
    idx = (u8)(local[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x60)] << 5);
    color = M2C_FIELD(arg0, s32 *, 0) ? 0xA3 : 0x103;
    flag = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0) != 0;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    base = M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0)) {
        base += 0x20;
    } else {
        base += 0xA40;
    }
    func_0207c780((M2C_UNK *)data_ov000_021dec34[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 4)][flag + 2], base);
    func_01ff9e44(data_ov000_021dec34[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 4)][flag] + idx, 0x180, 0x20);
    func_0209b26c(2, 0xD, 1, data_ov000_021debc8[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 4)], 0xF000, color);
    gCur3DSpriteEngine = saved;
}

void func_ov000_021759b8(s32 *arg0) {
    M2C_UNK func_02080860(s32, s32, s32, u16, s32);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *saved;
    s32 base;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    base = M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x24);
    func_02080860(base + 0xC6, 9, 9, (u16)(*arg0 ? 0x52 : 1), 0xC);
    gCur3DSpriteEngine = saved;
}

void func_ov000_02175ed8(void *arg0) {
    M2C_UNK func_02007ef4(s32, s32);
    s32 func_020e3438(M2C_UNK);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    extern s16 data_ov000_021deb46[];
    void *temp_r4;
    s16 temp_r6;
    s32 source;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    temp_r6 = data_ov000_021deb46[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x4)];
    if (temp_r6 != -1) {
        source=func_020e3438(3);
        func_02007ef4(source + temp_r6 * 0x4E0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2880);
    }
    source=func_020e3438(4);
    func_02007ef4(source + 0x1C0 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), volatile s32 *, 0x58), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2D60);
    source=func_020e3438(4);
    func_02007ef4(source + 0x1C0 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), volatile s32 *, 0x5C), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2F20);
    gCur3DSpriteEngine = temp_r4;
}
#pragma opt_strength_reduction off
/* Draws the per-unit status panel of the map info window: picks the graphics set
 * for the window's current mode, uploads the gauge tiles, then draws the stat
 * bar and number, the unit-type icon and the team-coloured tiles for `entry`. */
void Ov000Info_DrawUnitPanel(void *entry){
M2C_UNK func_0207c780(M2C_UNK *,s32); M2C_UNK func_02080860(s32,s32,s32,u16,s32); s32 func_020e34bc(s32); void func_020e35cc(s32); void func_01ff9ce8(s32); u32 func_ov000_02175074();
extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineSub;
extern M2C_UNK data_ov000_021c2e50,data_ov000_021c2bb0,data_ov000_021c2680,data_ov000_021c23ec,data_ov000_021c2918,data_ov000_021c2158;
extern u16 data_ov000_021deb10[]; extern u8 data_ov000_021ae2a0[]; extern s8 data_ov000_021dede4[];
Tiles75a20 first; TeamTiles75a20 second; void *saved; u16 tile; s32 temp; s32 i,base; s16 index; s32 gfx,step; M2C_UNK *table;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
gfx=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28);
tile=(u16)(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x3c)*3+0x280);base=gfx+0x520;
temp=func_020e34bc(0x800);index=(s16)(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x50)-1);
func_01ff9ce8(0);
switch(func_ov000_02175074()){case 0:table=&data_ov000_021c2e50;break;case 1:table=&data_ov000_021c2bb0;break;case 2:table=&data_ov000_021c2680;break;case 3:table=&data_ov000_021c23ec;break;case 4:table=&data_ov000_021c2918;break;case 5:table=&data_ov000_021c2158;break;default:table=&data_ov000_021c2e50;break;}
func_0207c780(table,temp);func_02080a14(base,16,2,temp+0x520);
for(i=0,step=0;i<2;i++,step+=32)func_01ff85b8(base+step*2,32,384);
func_020808dc(base,16,2,11);func_020e35cc(temp);
if(M2C_FIELD(M2C_FIELD(entry,void **,16),u8 *,0x48)){
if(M2C_FIELD(entry,s32 *,8)<40)func_02080860(base,10,2,0x2e0,11);
func_02098844(0,26,20,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),data_ov000_021deb10[index],(u16)index,0);
}else if(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,12)>=0){
if(M2C_FIELD(entry,s32 *,8)<40)func_02080860(base,10,2,0x2c0,11);
func_02098844(0,26,20,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),data_ov000_021deb10[index],(u16)index,0);
}else if(M2C_FIELD(M2C_FIELD(entry,void **,16),u8 *,0x49)){
if(M2C_FIELD(entry,s32 *,8)<40)func_02080860(base,10,2,0x2a0,11);
func_02098844(0,26,20,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),data_ov000_021deb10[index],(u16)index,0);
}else func_020809c0(base,16,2);
if(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x3c))func_02080860(gfx+32,3,1,tile,11);
if(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,32)>0){
if(M2C_FIELD(entry,s32 *,8)<40){func_02080860(gfx+38,3,1,0x28c,11);func_02080860(gfx+44,2,1,0x292,11);}else func_02080860(gfx+38,3,1,0x28c,11);}
if(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,36)>0){
if(M2C_FIELD(entry,s32 *,8)<40){func_02080860(gfx+48,3,1,0x28f,11);func_02080860(gfx+54,2,1,0x292,11);}else func_02080860(gfx+48,3,1,0x28f,11);}
first=data_ov000_021ae2b2;
func_02080860(gfx+0x308,4,1,(u16)(first.v[M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x54)]*4+0x260),11);
second=*(TeamTiles75a20 *)(data_ov000_021ae2a0+6);
func_02080860(gfx+0x314,4,1,(u16)(second.v[data_ov000_021dede4[M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,4)]]*4+0x240),11);
gCur3DSpriteEngine=saved;
}
#pragma opt_strength_reduction reset
