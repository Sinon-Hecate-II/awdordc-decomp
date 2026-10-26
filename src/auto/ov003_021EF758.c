/* 21 functions from 0x021EF758 to 0x021F05FC (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021efb40(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021efb54(void) {
    M2C_UNK func_ov003_021ea57c();
    func_ov003_021ea57c();
}

void func_ov003_021efb60(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021efe90(void) {
    M2C_UNK func_ov003_021eaed0();
    func_ov003_021eaed0();
}

void func_ov003_021efe9c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

void func_ov003_021effb8(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021effcc(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x3C);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021efff8(void) {
    M2C_UNK func_ov003_021ea314();
    func_ov003_021ea314();
}

void func_ov003_021f0004(void) {
    M2C_UNK func_ov003_021ea3f4();
    func_ov003_021ea3f4();
}

void func_ov003_021f0010(void) {

}

void func_ov003_021f0014(void *arg0) {
s32 func_020846a4(); s32 func_020848c4(); s32 func_02084d3c(void *,s32); void func_02084d88(void *,s32); void func_02084e74(); s32 func_020a22fc(s32); s32 func_ov003_021e6d28(); void func_ov003_021f140c(s32); void func_ov003_021f152c(s32); void func_ov003_022006dc(s32); s32 func_ov003_02200808(u8); void func_ov006_022172b0(void *);
u8 buf[0x24]; s32 v;
if (!func_020846a4()) return;
if (((u32)(M2C_FIELD(arg0,u8 *,0x39)<<31)>>31)==1) v=1; else v=0;
if (!(v&255)) return;
func_ov003_022006dc(0); func_ov003_021f152c(1); func_ov003_021f140c(1); func_ov006_022172b0(arg0);
if (!func_ov003_021e6d28()) return;
if (!func_02084d3c(buf,0x24)) return;
buf[13]=func_ov003_02200808((u8)func_020a22fc(func_020848c4()+1));
func_02084d88(buf,0x24); func_02084e74();
}

void func_ov003_021f00cc(void) {

}

void func_ov003_021f00d0(void) {
    M2C_UNK func_ov003_021ee8b8();
    func_ov003_021ee8b8();
}

void func_ov003_021f00dc(void *arg0) {
void *func_02084e24(); void *func_02084e64(); s32 func_020a22fc(s32); s32 func_ov003_02200808(u8);
s32 flag; s8 old,count,value; u8 i; void *p,*q;
i=0; count=M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),s8 *,4);
if(count<=0)return;
do {
p=M2C_FIELD(arg0,void **,0x6c)+i;
old=M2C_FIELD(p,s8 *,10);
if(M2C_FIELD(p,u8 *,0x74)==255) flag=1; else flag=0;
if((u8)flag==0){
q=func_02084e24();
if(q) value=M2C_FIELD(q,s8 *,13); else value=func_ov003_02200808((u8)func_020a22fc(i+1));
}else{
q=func_02084e64();
if(q) value=M2C_FIELD(q+i,s8 *,0x12); else value=func_ov003_02200808((u8)func_020a22fc(i+1));
}
if(old!=value){
M2C_FIELD(M2C_FIELD(arg0,void **,0x6c)+i,u8 *,10)=(u8)value;
M2C_FIELD(arg0,u8 *,0x3a)|=8;
if(i==M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),u8 *,7)){
q=M2C_FIELD(arg0,void **,0x40); M2C_FIELD(q,u8 *,0x10)=i; M2C_FIELD(q,u8 *,0x11)=(u8)value;
}
}
i++;
}while(i<count);
}

void func_ov003_021f01cc(void *arg0) {
    M2C_UNK func_ov003_021f1bd4();
    M2C_UNK func_ov003_021f1be8();
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x18) >> 0x1F) != 0) {
        func_ov003_021f1bd4();
        return;
    }
    func_ov003_021f1be8();
}

void func_ov003_021f05cc(void *arg0) {
    extern M2C_UNK data_ov003_0220fb28;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_0220fb28;
    M2C_FIELD(arg0, s8 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
}

void func_ov003_021f05f8(void) {

}

