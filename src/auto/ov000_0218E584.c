/* 7 functions from 0x0218E584 to 0x0218F468 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0218edd8(void) {
    M2C_UNK func_ov000_0218dda4();
    M2C_UNK func_ov000_0218e340();
    M2C_UNK func_ov000_0218e9ac();
    M2C_UNK func_ov000_0218e584();
    s32 func_ov000_021a93a8(void *, u8, u8);
    s32 func_ov000_021a98a8(u32);
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    void *temp_r0;
    void *temp_r1;
    temp_r0 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (func_ov000_021a93a8(temp_r0, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2)) == 0) {
        func_ov000_0218e340();
    }
    temp_r1 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(temp_r1, u16 *, 8) << 0x12) >> 0x1E) == 0) return;
    if (func_ov000_021a98a8((u32)(M2C_FIELD(temp_r1, u8 *, 0) << 0x1A) >> 0x1A) != 0) func_ov000_0218dda4();
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8)(M2C_FIELD(data_ov000_021df580, u8 *, 7) | 2);
    switch ((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u16 *, 8) << 0x12) >> 0x1E) {
    case 1: func_ov000_0218e9ac(); break;
    case 2: func_ov000_0218e584(); break;
    }
}

void func_ov000_0218eea8(void) {
    M2C_UNK func_ov000_0218dda4();
    M2C_UNK func_ov000_0218e340();
    M2C_UNK func_ov000_0218e9ac();
    s32 func_ov000_021a93a8(void *, u8, u8);
    s32 func_ov000_021a98a8(u32);
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    void *temp_r0;
    void *temp_r1;

    temp_r0 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (func_ov000_021a93a8(temp_r0, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2)) == 0) {
        func_ov000_0218e340();
    }
    temp_r1 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32) (M2C_FIELD(temp_r1, u16 *, 8) << 0x12) >> 0x1E) != 1) {
        return;
    }
    if (func_ov000_021a98a8((u32) (M2C_FIELD(temp_r1, u8 *, 0) << 0x1A) >> 0x1A) != 0) {
        func_ov000_0218dda4();
    }
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8) (M2C_FIELD(data_ov000_021df580, u8 *, 7) | 2);
    func_ov000_0218e9ac();
}

void func_ov000_0218ef40(void) {
    s32 func_020ba510(s32, s32);
    s32 func_ov000_02177f24(s32, s32, s16 *);
    void func_ov000_02199d74(u32, u32, u32, u32, u32);
    void func_01ffc328(void *);
    void func_01ffb9c4(s8);
    extern void **gCurrentMap;

    s8 *rowPtr;
    void *bestEntity = 0;
    s16 foundX = (s16)((s32)bestEntity - 1);
    s16 foundY = foundX;
    s32 bestHealth = 0x64;
    s32 x = 0;
    s32 y = 0;
    void *entity;
    s16 buf[2];
    u16 rowOff;
    u8 byteVal;
    u8 kind;
    u16 f8;
    u8 health;
    s32 okay;

    func_01ffc328(*(void **)((u8 *)(*gCurrentMap) + 0x52D0));
    func_01ffb9c4(0x6f);

    if ((s32)*(u16 *)((u8 *)(*gCurrentMap) + 0x5146) <= 0) goto outer_done;
outer_top:
    y = (s32)y; // no-op to keep
    // keep y variable; outer loop sets later
    x = 0;
    if ((s32)*(u16 *)((u8 *)(*gCurrentMap) + 0x5144) <= 0) goto width_done;
inner_top:
    rowPtr = *(s8 **)((void **)((u8 *)(*gCurrentMap) + 0x52E8) + y);
    if (rowPtr[x] < 0) goto next_cell;
    rowOff = *(u16 *)((u8 *)(*gCurrentMap) + 0x3758 + y * 2);
    byteVal = *((u8 *)(*gCurrentMap) + rowOff + x);
    entity = (void *)((u8 *)(*gCurrentMap) + 0x59A4 + byteVal * 14);
    kind = *((u8 *)entity) & 0x3F;
    if (kind == 0) goto next_cell;
    if (entity == *(void **)((u8 *)(*gCurrentMap) + 0x52D0)) goto next_cell;
    okay = func_020ba510(x, y);
    if (okay == 0) goto next_cell;
    f8 = *(u16 *)((u8 *)entity + 8);
    if (((f8 << 18) >> 30) != 1) goto next_cell;
    health = *((u8 *)entity + 10);
    if (bestHealth < (health & 0x7F)) goto next_cell;
    okay = func_ov000_02177f24(x, y, buf);
    if (okay == 0) goto next_cell;
    foundX = buf[0];
    foundY = buf[1];
    bestEntity = entity;
    bestHealth = health & 0x7F;
next_cell:
    x++;
    if (x < *(s32 *)((u8 *)(*gCurrentMap) + 0x5144)) goto inner_top;
width_done:
    y++;
    if (y < *(s32 *)((u8 *)(*gCurrentMap) + 0x5146)) goto outer_top;
outer_done:
    if (foundX == -1) return;
    {
        u16 tmp = *(u16 *)((u8 *)bestEntity + 8);
        tmp &= (u16)~0x3000;
        *(u16 *)((u8 *)bestEntity + 8) = tmp;
        func_ov000_02199d74(foundX, foundY, 6, 0, 0);
    }
}

void func_ov000_0218f37c(void) {
extern void **gCurrentMap;
s32 func_ov000_021a98a8(u32);
s32 func_ov000_021a8b78(void *);
void func_ov000_0217c3a4(void);
void func_ov000_02199d74(u32,u32,u32,u32,u32);
u8 *p;
u8 *base;
u8 *q;
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
if(!func_ov000_021a98a8((u32)(p[0]<<26)>>26))return;
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
if(!((u32)(M2C_FIELD(p,u16 *,6)<<16)>>27))return;
if(func_ov000_021a8b78(p)>=2) {
base=*gCurrentMap;
p=M2C_FIELD(base,u8 **,0x52d0);
q=base+0x6c60+6*M2C_FIELD(base+(p[1]+M2C_FIELD(base+2*p[2],u16 *,0x3758)),s8 *,0x1928);
q[3]++;
}
func_ov000_0217c3a4();
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
func_ov000_02199d74(p[1],p[2],3,0,0);
}

