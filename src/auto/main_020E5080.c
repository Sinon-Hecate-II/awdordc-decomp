/* 6 functions from 0x020E5080 to 0x020E5824 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_cse off
void func_020e5080(void *arg0) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub,data_02168ff4;
extern u8 data_0212da70[],data_0212da40[],data_0212db88[],data_0212db38[],data_0212db78[],data_0212da4c[],data_0212da7c[],data_0212da34[],data_0212db28[],data_0212db68[],data_0212db58[],data_0212da58[],data_0212db48[],data_0212da64[];
void func_02082cb4(void);void func_02003560(void);void func_02002bb8(s32);
void func_020822b8(void*);void func_020aeebc(s32,s32,s32);void func_020aef7c(s32,s32,s32);
void func_0200bc5c(void*);void *func_020e3218(void*);
void func_020814e4(void);void func_01ff9ce8(s32);
void func_02081590(void*,void*);void func_0208116c(void*,s32,s32);
void func_020808dc(void*,s32,s32,s32);void func_02081528(void);
void *func_020ab1c4(void*);void func_020aab24(void*,s32,s32,s32,s32);
void func_02088e84(void*,s32,s32,s32,s32);s32 func_020aae10(void*);s32 func_020aae44(void*);
void func_02087d84(void*,s32,s32,s32,u16,u16);void func_020aad18(void*);
void *func_0208931c(void*);void func_020a9a30(s32,s32,s32,void*);s32 func_020aaf74(void*);
void func_01ff9b38(void);M2C_UNK func_02090640(M2C_UNK,M2C_UNK);
void func_0200dd40(void);void func_0200e2f8(void);M2C_UNK func_0200e868(M2C_UNK);void func_0200e880(s32);
s32 saved;void *obj;s32 y,x,w,h;u16 *volatile p0, *volatile p1, *volatile p2, *volatile p3, *volatile p4, *volatile p5, *volatile p6, *volatile p7, *volatile p8, *volatile p9, *volatile p10, *volatile p11;
func_02082cb4();func_02003560();func_02002bb8(0x40);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
func_020822b8(data_0212da70);
p0=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p0=*p0 | 16;
p1=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p1=*p1 & ~32;
p2=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p2=*p2 | 64;
p3=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p3=*p3 & ~128;
p4=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p4=*p4 | 256;
p5=((u16 *)((u8 *)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0)+0x12)); *p5=*p5 & ~192;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,81)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,82)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,83)=0;
func_020aeebc(2,15,5);func_0200bc5c(data_0212da40);
func_020e3218(data_0212db88);func_020814e4();func_01ff9ce8(0);
func_02081590(func_020e3218(data_0212db38),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0xc));
func_02081590(func_020e3218(data_0212db78),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20));
func_0208116c(data_0212da4c,0xa0,0x20);
func_020808dc(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20),0x20,0x18,5);
M2C_FIELD((void*)gCur3DSpriteEngine,u8 *,0x46)|=1;func_02081528();
M2C_FIELD(arg0,void **,0x38)=func_020ab1c4(arg0);
func_020aab24(M2C_FIELD(arg0,void **,0x38),2,0x140,3,1);
obj=M2C_FIELD(arg0,void **,0x38);func_02088e84(obj,0xe0,0xa0,0xe0,0xa0);
if((u8)(M2C_FIELD(M2C_FIELD(obj,void **,0x64),u8 *,0x12)!=0)){
y=M2C_FIELD(obj,s16 *,0x52);x=M2C_FIELD(obj,s16 *,0x50);
w=func_020aae10(obj);h=func_020aae44(obj);
func_02087d84(M2C_FIELD(obj,void **,0x64),1,x,y,(u16)w,(u16)h);
}
M2C_FIELD(obj,s16 *,0x34)=0xe0;M2C_FIELD(obj,s16 *,0x36)=0xa0;
if((u8)(M2C_FIELD(M2C_FIELD(obj,void **,0x64),u8 *,0x12)!=0)){
y=M2C_FIELD(obj,s16 *,0x52);x=M2C_FIELD(obj,s16 *,0x50);
w=func_020aae10(obj);h=func_020aae44(obj);
func_02087d84(M2C_FIELD(obj,void **,0x64),1,x,y,(u16)w,(u16)h);
}
func_020aad18(M2C_FIELD(arg0,void **,0x38));
gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(data_0212da7c);
p6=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p6=*p6 | 16;
p7=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p7=*p7 & ~32;
p8=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p8=*p8 | 64;
p9=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p9=*p9 & ~128;
p10=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p10=*p10 | 256;
p11=((u16 *)((u8 *)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0)+0x12)); *p11=*p11 & ~192;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,81)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,82)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,83)=0;
func_020aef7c(2,15,5);func_0200bc5c(data_0212da34);
func_020e3218(data_0212db28);func_020814e4();func_01ff9ce8(0);
func_02081590(func_020e3218(data_0212db68),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0xc));
func_02081590(func_020e3218(data_0212db58),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20));
func_0208116c(data_0212da58,0xa0,0x20);
func_020808dc(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20),0x20,0x18,5);
M2C_FIELD((void*)gCur3DSpriteEngine,u8 *,0x46)|=1;
func_02081590(func_020e3218(data_0212db48),(u8*)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x1c)+0x2800);
func_0208116c(data_0212da64,0x2c0,0x20);func_02081528();
M2C_FIELD(arg0,void **,0x34)=func_0208931c(arg0);obj=M2C_FIELD(arg0,void **,0x34);
M2C_FIELD(obj,u8 *,0x58)=15;
func_020a9a30(2,0,15,(u8*)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x1c)+0x2a00);
func_020a9a30(2,2,15,(u8*)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x30)+0x2e0);
M2C_FIELD(obj,s32 *,0x44)=func_020aaf74(obj);
M2C_FIELD(obj,s16 *,0x3e)=0x150;
M2C_FIELD(obj,u32 *,0x40)=(M2C_FIELD(obj,u32 *,0x40)&~0x3fc0000)|0x5c0000;
M2C_FIELD(obj,s16 *,0x3c)=0xc00;
gCur3DSpriteEngine=saved;func_01ff9b38();func_02090640(2,0x20);func_0200dd40();func_0200e2f8();func_0200e868(1);func_0200e880(3);
M2C_FIELD(&data_02168ff4,s32 *,4)=0;
M2C_FIELD(&data_02168ff4,s32 *,8)=data_02168ff4;
M2C_FIELD(&data_02168ff4,s32 *,0xc)=0x20;
M2C_FIELD(&data_02168ff4,s32 *,0x10)=0x105d;
M2C_FIELD(&data_02168ff4,s32 *,0x14)=1;
M2C_FIELD(&data_02168ff4,s32 *,0x18)=0;
M2C_FIELD(&data_02168ff4,s32 *,0x1c)=0;
}
#pragma opt_cse reset
void func_020e5678(void) {
    M2C_UNK func_0200df70();
    M2C_UNK func_0200e868(M2C_UNK);
    M2C_UNK func_02090640(M2C_UNK, M2C_UNK);
    M2C_UNK func_020af1e4();
    func_020af1e4();
    func_02090640(2, 0x7F);
    func_0200df70();
    func_0200e868(0);
}

void func_020e569c(M2C_UNK arg0) {
 void *func_01ffa444(M2C_UNK *, M2C_UNK);
 M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
 s16 func_0207c8ec(s32, M2C_UNK);
 s32 func_020e3580(M2C_UNK, M2C_UNK);
 extern M2C_UNK data_0212da88;
 extern M2C_UNK data_0212dba0;
 extern s32 data_02168ff4, g3DSpriteEngineMain, gCur3DSpriteEngine;
 s32 saved;
 void *obj;
 saved = gCur3DSpriteEngine;
 gCur3DSpriteEngine = g3DSpriteEngineMain;
 obj = func_01ffa444(&data_0212da88, arg0);
 if (obj != NULL) {
 M2C_FIELD(obj, void **, 0) = &data_0212dba0;
 M2C_FIELD(obj, s32 *, 0x34) = 0;
 M2C_FIELD(obj, s32 *, 0x38) = 0;
 M2C_FIELD(obj, u8 *, 0x3C) = 0;
 M2C_FIELD(obj, s16 *, 0x3E) = func_0207c8ec(0x2BF20, 0x3E8);
 M2C_FIELD(obj, u8 *, 0x40) = 0;
 data_02168ff4 = func_020e3580(0x20, 0x20);
 MI_CpuFill8((u8 *)obj + 0x41, 0, 0xA);
 }
 gCur3DSpriteEngine = saved;
}

void func_020e5740(void) {
 void *func_01ffa770(M2C_UNK *);
 M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
 s16 func_0207c8ec(s32, M2C_UNK);
 extern M2C_UNK data_0212da88;
 u8 flags;
 void *obj;
 obj = func_01ffa770(&data_0212da88);
 if (obj == NULL) return;
 flags = M2C_FIELD(obj, u8 *, 0x3C);
 if (!(flags & 2)) {
 if (!(flags & 1)) return;
 }
 M2C_FIELD(obj, s16 *, 0x3E) = func_0207c8ec(0x2BF20, 0x3E8);
 if ((M2C_FIELD(obj, u8 *, 0x3C) &= ~1) & 2) return;
 M2C_FIELD(obj, u8 *, 0x3C) |= 2;
 SetSpriteAnimation(obj, 1);
}

M2C_UNK **func_020e57b4(M2C_UNK **arg0) {
 M2C_UNK func_020e35cc();
 M2C_UNK MemFree(M2C_UNK **);
 extern M2C_UNK data_0212dba0;
 extern s32 data_02168ff4;
 *arg0 = &data_0212dba0;
 if (data_02168ff4 != 0) func_020e35cc();
 MemFree(arg0);
 return arg0;
}

M2C_UNK **func_020e57f0(M2C_UNK **arg0) {
    M2C_UNK func_020e35cc();
    extern M2C_UNK data_0212dba0;
    extern s32 data_02168ff4;
    *arg0 = &data_0212dba0;
    if (data_02168ff4 != 0) {
        func_020e35cc();
    }
    return arg0;
}

