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

u32 func_ov003_0220a6bc(void *a) {
M2C_UNK func_020c01ec(void *);M2C_UNK func_ov003_02207e80(void *);u32 func_ov003_02208034(void *);M2C_UNK func_ov003_02209d0c(void *,u8);M2C_UNK func_ov003_0220c414(void *,M2C_UNK);
extern M2C_UNK data_0215d9b8;
u8 count;u32 yes,bit; s32 test,other,remaining;void *p;
count=M2C_FIELD(a,u8 *,0x34);yes=count!=0?1:0;if(!(yes&255))return yes;
bit=(u32)(M2C_FIELD(a,u8 *,0x38)<<27)>>31;if(bit)return bit;
if(count==20){p=M2C_FIELD(a,void **,0x54);M2C_FIELD(p,s16 *,14)=16;M2C_FIELD(p,s16 *,16)=0;M2C_FIELD(p,s16 *,12)=10;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);}
if(M2C_FIELD(a,u8 *,0x34)==11) {
test=((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0?1:0;
if(test&255){
other=M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==8?1:0;
if((other&255)&&((u32)(M2C_FIELD(a,u8 *,0x38)<<24)>>31)){
p=M2C_FIELD(a,void **,0x40);
M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0x3000)|((u32)((u16)M2C_FIELD(p,s32 *,4)<<30)>>18);
M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0xc00)|((u32)((u16)M2C_FIELD(p,s32 *,28)<<30)>>20);
M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0x4000)|((u32)((u16)M2C_FIELD(p,s32 *,52)<<31)>>17);
func_ov003_0220c414(a,0);func_020c01ec(a);M2C_FIELD(a,u8 *,0x38)&=~128;
}}}
if(M2C_FIELD(a,u8 *,0x34)==10){M2C_FIELD(a,u8 *,0x38)=(M2C_FIELD(a,u8 *,0x38)&~1)|1;func_ov003_02209d0c(a,M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,17));M2C_FIELD(M2C_FIELD(a,void **,0x50),u8 *,1)=0;}
remaining=M2C_FIELD(a,u8 *,0x34)-1;M2C_FIELD(a,u8 *,0x34)=remaining;yes=(remaining&255)?1:0;if(yes&255)return yes;
func_ov003_02207e80(a);return func_ov003_02208034(a);
}

void func_ov003_0220a864(M2C_UNK arg0) {
    (void) arg0;
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

