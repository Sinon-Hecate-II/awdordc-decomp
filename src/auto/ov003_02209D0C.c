/* 7 functions from 0x02209D0C to 0x0220ACCC (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_0220a5fc(void *arg0, s32 arg1) {
M2C_UNK func_0200bc5c(M2C_UNK *);
M2C_UNK func_0207c780(s32,s32);
s32 func_02080e30(s32,s32);
s32 func_020e3218(s32);
M2C_UNK func_020e35cc(s32);
extern void *data_027e00c4;
extern M2C_UNK data_ov003_0220f240, data_ov003_0221118c, data_ov003_0221119c;
s32 temp_r0;
func_0200bc5c(&data_ov003_0221118c);
temp_r0=func_02080e30(func_020e3218((s32)&data_ov003_0221119c),1);
func_0207c780(temp_r0+M2C_FIELD(&data_ov003_0220f240,s32 *,arg1*16),M2C_FIELD(data_027e00c4,s32 *,0x14));
func_020e35cc(temp_r0);
}

void func_ov003_0220a658(void *arg0, s32 arg1) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004cf0();
    M2C_UNK func_0207c780(s32, s32);
    s32 func_02080e30(s32, s32);
    s32 func_020e3218(s32);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_ov003_0220f244;
    s32 temp_r4;
    temp_r4 = func_02080e30(func_020e3218(M2C_FIELD(&data_ov003_0220f244, s32 *, arg1 * 0x10)), 1);
    func_02004b54();
    func_0207c780(temp_r4, 0x06800000);
    func_02004cf0();
    func_020e35cc(temp_r4);
}

void func_ov003_0220a698(void *arg0, s8 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), s8 *, 0x11) = arg1;
    M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) & ~1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s8 *, 1) = 1;
}

void func_ov003_0220ac58(void *arg0) {
void *p=M2C_FIELD(arg0,void **,0x58);
s16 current=M2C_FIELD(p,s16 *,2);
s16 step;
s16 target;
if(current==M2C_FIELD(p,s16 *,4)) return;
M2C_FIELD(p,s16 *,2)=current+M2C_FIELD(p,s16 *,6);
p=M2C_FIELD(arg0,void **,0x58);
step=M2C_FIELD(p,s16 *,6);
if((step==6 && (target=M2C_FIELD(p,s16 *,4),M2C_FIELD(p,s16 *,2)>target)) || (step==-4 && (target=M2C_FIELD(p,s16 *,4),M2C_FIELD(p,s16 *,2)<target))) M2C_FIELD(p,s16 *,2)=target;
p=M2C_FIELD(arg0,void **,0x58);
M2C_FIELD(p,u8 *,1)+=1;
}

