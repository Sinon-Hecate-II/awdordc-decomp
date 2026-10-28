/* 4 functions from 0x022148A4 to 0x02215814 (ov004), found by ds-decomp. */
#include "common.h"

void func_ov004_022148a4(void) {
    M2C_UNK func_02003bd0();
    func_02003bd0();
    *(u16 *)0x04000060 = (*(u16 *)0x04000060 & ~0x3000) | 8;
    M2C_FIELD((void *)0x040004C8, s32 *, 0) = 0x1FF00000;
    M2C_FIELD((void *)0x040004C8, s32 *, 4) = 0x7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -8) = 0x7FFFFFFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -4) = 0x7FFF7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, 0xB8) = 0xBFFF0000;
}

void func_ov004_02214904(void) {
    *(s32 *)0x04000540 = 1;
}

void func_ov004_02214918(void *arg0) {
}

void func_ov004_02215754(void *a){extern s32 gCur3DSpriteEngine,data_027e00c8,data_0215d8a0;void func_ov004_022148a4(void);void func_ov004_02214904(void);s32 old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;func_02082770(a);gCur3DSpriteEngine=old;func_ov003_021ff3ac();func_020ab200();func_0209cd00(func_ov004_022148a4);func_0209cd00(func_ov004_02214904);func_0209e9f4();func_0209bf7c();func_0208f890();func_0209c868();if(M2C_FIELD(a,s32*,0x40)==0x1000)data_0215d8a0 &=0xffffff;if(M2C_FIELD(a,s32*,0x40)==0x800)data_0215d8a0=(data_0215d8a0&0xffffff)|0x1000000;if(M2C_FIELD(a,s32*,0x5c))func_02082040(M2C_FIELD(a,s32*,0x5c));M2C_FIELD(a,s32*,0x5c)=0;func_02088624();}

