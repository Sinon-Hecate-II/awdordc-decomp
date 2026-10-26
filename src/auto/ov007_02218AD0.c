/* 21 functions from 0x02218AD0 to 0x02219ACC (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_02219398(void) {
    M2C_UNK func_ov007_02217f8c();
    func_ov007_02217f8c();
}

void func_ov007_022193a4(void) {
    M2C_UNK func_ov007_02218570();
    func_ov007_02218570();
}

void func_ov007_022193b0(void) {
    M2C_UNK func_ov007_02218e98();
    func_ov007_02218e98();
}

void func_ov007_022193bc(void) {
    M2C_UNK func_ov007_0221863c();
    func_ov007_0221863c();
}

void func_ov007_022193c8(void) {
    M2C_UNK func_ov007_02218a60();
    func_ov007_02218a60();
}

void func_ov007_022193d4(void) {
    M2C_UNK func_ov007_02219230();
    func_ov007_02219230();
}

void func_ov007_022193e0(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x37);
    switch (temp_r1) {                              /* irregular */
    case 1:
        M2C_FIELD(arg0, u8 *, 0x37) = 0U;
        break;
    case 0:
        M2C_FIELD(arg0, u8 *, 0x37) = 1U;
        break;
    }
    func_0208fe30(0x10020);
}

void func_ov007_02219418(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221ff90;
    func_01ffa3dc(&data_ov007_0221ff90, 7);
}

M2C_UNK func_ov007_02219430(void) {
    M2C_UNK func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov007_0221ff90;
    return func_01ffa770(&data_ov007_0221ff90);
}

void func_ov007_02219444(void *arg0) {
M2C_UNK func_ov007_02219430(void); void func_02088eec(void *,s32); void func_02088da8(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **data_027e00c8;
u16 * volatile sp0; u16 **old; void *r4;
r4=(void *)func_ov007_02219430();
if(M2C_FIELD(r4,u8 *,0x34)!=0) {
old=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
sp0=(u16 *)((u8 *)*data_027e00c8+0x12);
*sp0=(*sp0 & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=0x10;
gCur3DSpriteEngine=old;
func_02088eec(M2C_FIELD(r4,void **,0x44),8);
func_02088eec(M2C_FIELD(r4,void **,0x48),8);
func_02088eec(M2C_FIELD(r4,void **,0x4c),8);
}
func_02088da8(M2C_FIELD(r4,void **,0x50));
func_02088da8(M2C_FIELD(r4,void **,0x54));
M2C_FIELD(arg0,u16 *,0x54)=0;
}

void func_ov007_02219634(void) {
    M2C_UNK func_ov007_02219430(void);
    void func_02088d94(void *);
    void func_02089438(void *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c8;
    u16 * volatile sp8;
    u16 * volatile sp4;
    u16 * volatile sp0;
    u16 **old;
    void *r4;

    r4 = (void *)func_ov007_02219430();
    old = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    sp8 = *data_027e00c8;
    *sp8 = (*sp8 & ~0x200);
    sp4 = *gCur3DSpriteEngine;
    *sp4 = (*sp4 & ~0x400);
    sp0 = *gCur3DSpriteEngine;
    *sp0 = (*sp0 & ~0x800);
    func_02088d94(M2C_FIELD(r4, void **, 0x50));
    func_02088d94(M2C_FIELD(r4, void **, 0x54));
    func_02089438(M2C_FIELD(r4, void **, 0x50));
    func_02089438(M2C_FIELD(r4, void **, 0x54));
    M2C_FIELD(r4, u8 *, 0x34) = 0;
    gCur3DSpriteEngine = old;
}

void func_ov007_022196f4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221fdf8;
    func_01ffa42c(&data_ov007_0221fdf8, arg0);
}

void func_ov007_0221970c(void *arg) {
M2C_UNK func_ov007_02219430(void);
void func_02088fc4(void *, int); void func_02088da8(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **data_027e00c8;
u16 * volatile sp0; u16 **old; void *r4;
r4=(void *)func_ov007_02219430();
if (M2C_FIELD(r4,u8 *,0x35)) {
old=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
sp0=*data_027e00c8+9; *sp0=(*sp0 & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0; M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=4; gCur3DSpriteEngine=old;
func_02088fc4(M2C_FIELD(r4,void **,0x44),6);
func_02088fc4(M2C_FIELD(r4,void **,0x48),6);
func_02088fc4(M2C_FIELD(r4,void **,0x4c),6);
}
func_02088da8(M2C_FIELD(r4,void **,0x50));
func_02088da8(M2C_FIELD(r4,void **,0x54));
M2C_FIELD(arg,u16 *,0x54)=0;
}

void func_ov007_02219ab4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221fe20;
    func_01ffa42c(&data_ov007_0221fe20, arg0);
}

