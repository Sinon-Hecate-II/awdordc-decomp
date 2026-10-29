/* 5 functions from 0x02225A9C to 0x02226658 (ov011), found by ds-decomp. */
#include "common.h"

void func_ov011_02225a9c(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void)arg0; (void)arg1; (void)arg2; (void)arg3;
}

void func_ov011_02225d98(void *arg0) {
    return;
}

void func_ov011_022264e4(void) {
    M2C_UNK func_0209cd00(M2C_UNK *);
    M2C_UNK func_020af1e4();
    extern M2C_UNK func_ov011_0222513c;
    extern M2C_UNK func_ov011_02225224;
    func_0209cd00(&func_ov011_0222513c);
    func_0209cd00(&func_ov011_02225224);
    func_020af1e4();
}

void func_ov011_02226508(void *arg0) {
extern s32 gCur3DSpriteEngine;
M2C_FIELD(arg0,u16 *,0x3A)++;
M2C_FIELD(arg0,u8 *,0x37)++;
if (((u32)(M2C_FIELD(arg0,u8 *,0x34)<<31)>>31)==0) return;
*(volatile s32 *)&gCur3DSpriteEngine = *(volatile s32 *)&gCur3DSpriteEngine;
M2C_FIELD(arg0,u8 *,0x38)++;
}

void func_ov011_02226550(s32 arg0,s32 arg1) {
s32 func_01ff9ce8(u8);
s32 func_0200bc5c(void *);
s32 func_02068c50(void *,s32);
s32 func_02068d68(void *,void *);
s32 func_020814e4(void *);
s32 func_02081528(void);
s32 func_02081590(void *,s32);
s32 func_02081644(void *,s32,s32,s32);
extern s32 gCur3DSpriteEngine;
extern M2C_UNK data_ov011_02228c14,data_ov011_02228c1c,data_ov011_02228c20,data_ov011_02228c24,data_ov011_02228c28;
u32 sp60[8],sp40[8],sp20[8],sp0[8];
func_02068c50(sp60,arg0);func_02068d68(sp60,&data_ov011_02228c14);
func_02068c50(sp40,arg0);func_02068d68(sp40,&data_ov011_02228c1c);
func_02068c50(sp20,arg0);func_02068d68(sp20,&data_ov011_02228c20);
func_02068c50(sp0,arg0);func_02068d68(sp0,&data_ov011_02228c24);
func_01ff9ce8((u8)arg1);func_0200bc5c(&data_ov011_02228c28);
func_020814e4(sp60);
func_02081590(sp40,M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32 *,12));
func_02081590(sp20,M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32 *,32));
func_02081644(sp0,arg1,0,0x200);func_02081528();
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1<<arg1;
}

