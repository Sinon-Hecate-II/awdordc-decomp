/* 22 functions from 0x02171774 to 0x02172754 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_02171774(s32 arg0) {
    (void)arg0;
}

void func_ov000_02171a68(void) {
}

void func_ov000_021723bc(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    func_0208fe30(0x10018);
}

void func_ov000_02172408(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *data_02101e84;
    if (!(*data_02101e84 & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_0217242c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8d18;
    func_01ffa3dc(&data_ov000_021b8d18, 7);
}

void func_ov000_02172444(void) {

}

void func_ov000_02172448(void) {

}

M2C_UNK *func_ov000_0217244c(void) {
    extern M2C_UNK data_ov000_021df5ec;
    return &data_ov000_021df5ec;
}

s32 func_ov000_02172458(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add1c[];
    return M2C_FIELD(data_ov000_021add1c, s32 *, arg1 << 5);
}

s32 func_ov000_02172468(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add20[];
    return M2C_FIELD(data_ov000_021add20, s32 *, arg1 << 5);
}

s32 func_ov000_02172478(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add24[];
    return M2C_FIELD(data_ov000_021add24, s32 *, arg1 << 5);
}

s32 func_ov000_02172488(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add28[];
    return M2C_FIELD(data_ov000_021add28, s32 *, arg1 << 5);
}

s32 func_ov000_02172498(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add2c[];
    return M2C_FIELD(data_ov000_021add2c, s32 *, arg1 << 5);
}

s32 func_ov000_021724a8(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add30[];
    return M2C_FIELD(data_ov000_021add30, s32 *, arg1 << 5);
}

s16 func_ov000_021724b8(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add34[];
    return M2C_FIELD(data_ov000_021add34, s16 *, arg1 << 5);
}

s32 func_ov000_021724cc(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add38[];
    return M2C_FIELD(data_ov000_021add38, s32 *, arg1 << 5);
}

#pragma opt_strength_reduction off
void *func_ov000_021724dc(void *arg0) {
void *func_02082028(s32);
register s32 i,j,k; register void *p,*q; void *t;
M2C_FIELD(arg0,s32 *,0)=0; M2C_FIELD(arg0,s32 *,4)=0;
M2C_FIELD(arg0,s32 *,12)=0; M2C_FIELD(arg0,s32 *,16)=0; M2C_FIELD(arg0,u8 *,20)=0;
p=func_02082028(0x11c);
if(p){
M2C_FIELD(p,s32 *,0)=1; M2C_FIELD(p,s32 *,4)=0; i=0; M2C_FIELD(p,s32 *,8)=0;
q=(u8*)p+0x3c;
do {
M2C_FIELD(q,s32 *,0)=0; M2C_FIELD(q,s32 *,4)=0; M2C_FIELD(q,s32 *,8)=0; M2C_FIELD(q,s32 *,12)=0;
M2C_FIELD(q,s32 *,0x28)=1; M2C_FIELD(q,s32 *,0x2c)=0;
M2C_FIELD(q,u8 *,0x30)=0; M2C_FIELD(q,u8 *,0x31)=0; M2C_FIELD(q,u8 *,0x33)=0;
j=0; M2C_FIELD(q,u8 *,0x34)=0;
inner: t=(u8*)q+(j<<2); j++; M2C_FIELD(t,s32 *,0x10)=i; if(j<6) goto inner;
q=(u8*)q+0x38;
}while((u32)q<(u32)((u8*)p+0x11c));
loop1:t=(u8*)p+(i<<2);i++;M2C_FIELD(t,s32 *,12)=9;if(i<4)goto loop1;
k=0;loop2:t=(u8*)p+(k<<2);k++;M2C_FIELD(t,s32 *,0x1c)=0;if(k<8)goto loop2;
}
M2C_FIELD(arg0,void **,0x18)=p;func_ov000_02172754(arg0);return arg0;
}
#pragma opt_strength_reduction reset

void *func_ov000_021725c8(void *arg0) {
    M2C_UNK func_02082040(s32);
    func_02082040(M2C_FIELD(arg0, s32 *, 0x18));
    return arg0;
}

void func_ov000_021725e0(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    func_01ff9ce8(0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(arg0, s32 *, 4) = 2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02172648(void) {
    M2C_UNK func_020c127c();
    func_020c127c();
}

/* Update an entry's state machine: handle pending states, refresh data, re-evaluate readiness. */
void func_ov000_02172654(void *entry) {
    extern void *data_027e00c4;
    switch (M2C_FIELD(entry, s32 *, 4)) {
    case 0:
        break;
    case 1:
        func_020c127c(entry);
        func_020809c0(M2C_FIELD(data_027e00c4, void **, 0x24), 32, 32);
        func_ov000_02173290(entry);
        func_ov000_021732c0(entry);
        M2C_FIELD(entry, s32 *, 8) = 0;
        M2C_FIELD(entry, s32 *, 12) = 0;
        M2C_FIELD(entry, s32 *, 4) = 0;
        break;
    case 2:
        func_ov000_02173290(entry);
        func_ov000_021732c0(entry);
        M2C_FIELD(entry, s32 *, 8) = 0;
        M2C_FIELD(entry, s32 *, 12) = 0;
        M2C_FIELD(entry, s32 *, 4) = 0;
        break;
    }
    func_ov000_02173468(entry);
    if (!func_ov000_02172468(func_ov000_0217244c(), *M2C_FIELD(entry, s32 **, 0x18))
        && !M2C_FIELD(entry, u8 *, 0x15)) {
        func_ov000_02172dc0(entry);
    }
    func_ov000_02172e90(entry);
    if (func_ov000_02172754(entry)) {
        M2C_FIELD(entry, s32 *, 4) = 1;
    }
}

void func_ov000_0217272c(void *arg0, s32 arg1) {
    M2C_UNK func_ov000_02172754(void *);
    *M2C_FIELD(arg0, s32 **, 0x18) = arg1;
    func_ov000_02172754(arg0);
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        M2C_FIELD(arg0, s32 *, 4) = 1;
    }
}

