/* 5 functions from 0x02217480 to 0x02217F5C (ov004), found by ds-decomp. */
#include "common.h"
extern u32 data_0215d8a8[];

/* Updates the zoom state: toggles between 1.0 (0x1000) and 0.5 (0x800) scale,
   recomputes the clipped target position, and clamps the source rectangle. */
void func_ov004_02217480(void *state) {
void func_01ffa8c4(void *, s32);
void *entry; s32 i, offset; void *base; u32 flags, kind; s16 x,y;
i=0;
M2C_FIELD(state,u8 *,0x36)=0;
M2C_FIELD(state,u8 *,0x35)=0;
base=M2C_FIELD(state,void **,0x5c);
offset=0;
do {
if(i<0) entry=0; else if(i>=64) entry=0; else entry=base+offset;
flags=data_0215d8a8[M2C_FIELD(entry,u8 *,7)];
kind=(flags<<3)>>29;
if((flags>>29)!=kind){
M2C_FIELD(state,u8 *,0x37)=i;
if(entry==0)return;
y=M2C_FIELD(entry,s16 *,2); x=M2C_FIELD(entry,s16 *,0);
M2C_FIELD(state,s16 *,0x48)=x;M2C_FIELD(state,s16 *,0x4a)=y;
return;
}
i++;offset+=32;
}while(i<64);
func_01ffa8c4(state,1);
}

void func_ov004_02217514(void *arg0) { (void)arg0; }

void func_ov004_02217bb8(void *state) {
    s32 func_0207c8ec(s32, M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    s32 scale;
    s32 scale2;
    s32 savedScale;

    M2C_FIELD(state, s8 *, 0x36) = 0;
    savedScale = M2C_FIELD(state, s32 *, 0x40);
    M2C_FIELD(state, s16 *, 0x54) = (s16) M2C_FIELD(state, s16 *, 0x50);
    M2C_FIELD(state, s16 *, 0x56) = (s16) M2C_FIELD(state, s16 *, 0x52);
    if (M2C_FIELD(state, s32 *, 0x40) == 0x1000) {
        M2C_FIELD(state, s8 *, 0x3A) = 1;
        M2C_FIELD(state, s32 *, 0x40) = 0x800;
        func_0208fe30(0x1001F);
    } else {
        M2C_FIELD(state, s8 *, 0x3A) = -1;
        M2C_FIELD(state, s32 *, 0x40) = 0x1000;
        M2C_FIELD(state, s16 *, 0x44) = (s16) M2C_FIELD(state, s16 *, 0x48);
        M2C_FIELD(state, s16 *, 0x46) = (s16) M2C_FIELD(state, s16 *, 0x4A);
        func_0208fe30(0x1001E);
    }
    scale = M2C_FIELD(state, s32 *, 0x40);
    if ((scale != 0x800) && (scale != 0x1000)) {

    } else {
        if ((s32) M2C_FIELD(state, s16 *, 0x50) < (s32) (0x60 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * scale, 0x1000))) {
            M2C_FIELD(state, s16 *, 0x50) = (s16) (0x60 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) < (s32) (0x39 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(state, s16 *, 0x52) = (s16) (0x39 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x50) > (s32) (0xA0 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * M2C_FIELD(state, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(state, s16 *, 0x50) = (s16) (0xA0 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) > (s32) (0x5F - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(state, s16 *, 0x52) = (s16) (0x5F - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
    }
    scale2 = M2C_FIELD(state, s32 *, 0x40);
    if ((scale2 != 0x800) && (scale2 != 0x1000)) {

    } else {
        if ((s32) M2C_FIELD(state, s16 *, 0x44) < 0) {
            M2C_FIELD(state, s16 *, 0x44) = 0;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x46) < 0) {
            M2C_FIELD(state, s16 *, 0x46) = 0;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x44) > 0x200) {
            M2C_FIELD(state, s16 *, 0x44) = 0x200;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x46) > 0x130) {
            M2C_FIELD(state, s16 *, 0x46) = 0x130;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x50) < (s32) (0x100 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) << 9, 0x1000))) {
            M2C_FIELD(state, s16 *, 0x50) = (s16) (0x100 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) << 9, 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) < (s32) (0xC0 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) * 0x158, 0x1000))) {
            M2C_FIELD(state, s16 *, 0x52) = (s16) (0xC0 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) * 0x158, 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x50) > 0) {
            M2C_FIELD(state, s16 *, 0x50) = 0;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) > 0) {
            M2C_FIELD(state, s16 *, 0x52) = 0;
        }
    }
    M2C_FIELD(state, s16 *, 0x58) = (s16) M2C_FIELD(state, s16 *, 0x50);
    M2C_FIELD(state, s16 *, 0x5A) = (s16) M2C_FIELD(state, s16 *, 0x52);
    M2C_FIELD(state, s16 *, 0x50) = (s16) M2C_FIELD(state, s16 *, 0x54);
    M2C_FIELD(state, s16 *, 0x52) = (s16) M2C_FIELD(state, s16 *, 0x56);
    M2C_FIELD(state, s32 *, 0x40) = savedScale;
}

/* Advances the zoom/pan interpolation one step and finalizes the transition. */
void func_ov004_02217e50(void *state) {
    M2C_UNK func_01ffa6fc(void *);
    u8 func_0207ca38(M2C_UNK, s16, s16, u8, s32);
    u8 step;

    M2C_FIELD(state, u8 *, 0x36) = (u8) (M2C_FIELD(state, u8 *, 0x36) + 1);
    step = func_0207ca38(4, 0, 0x3E8, M2C_FIELD(state, u8 *, 0x36), 0x10);
    if ((s32) M2C_FIELD(state, s8 *, 0x3A) > 0) {
        M2C_FIELD(state, s32 *, 0x40) = (s32) func_0207ca38(0, 0x1000, 0x800, step, 0x3E8);
    }
    if ((s32) M2C_FIELD(state, s8 *, 0x3A) < 0) {
        M2C_FIELD(state, s32 *, 0x40) = (s32) func_0207ca38(0, 0x800, 0x1000, step, 0x3E8);
    }
    M2C_FIELD(state, s16 *, 0x50) = (s16) func_0207ca38(0, M2C_FIELD(state, s16 *, 0x54), M2C_FIELD(state, s16 *, 0x58), step, 0x3E8);
    M2C_FIELD(state, s16 *, 0x52) = (s16) func_0207ca38(0, M2C_FIELD(state, s16 *, 0x56), M2C_FIELD(state, s16 *, 0x5A), step, 0x3E8);
    if ((s32) M2C_FIELD(state, u8 *, 0x36) < 0x10) {
        return;
    }
    func_01ffa6fc(state);
}

void func_ov004_02217f34(void) {
    M2C_UNK func_0209cd00(M2C_UNK *);
    M2C_UNK func_020ab200();
    M2C_UNK func_ov003_021ff3ac();
    extern M2C_UNK func_ov004_022148a4;
    extern M2C_UNK func_ov004_02214904;
    func_ov003_021ff3ac();
    func_020ab200();
    func_0209cd00(&func_ov004_022148a4);
    func_0209cd00(&func_ov004_02214904);
}
