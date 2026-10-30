/* 6 functions from 0x021E5118 to 0x021E5E24 (ov003), found by ds-decomp. */
#include "common.h"
static inline void CallSlot20(void *p) { M2C_FIELD(M2C_FIELD(p,void **,0),void (**)(void *),32)(p); }

void func_ov003_021e5b18(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020aacf0(void *);
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    register u8 temp_r4 asm("r4");
    s32 var_r0;
    u16 temp_r5;
    unsigned int var_r3;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *temp_r2;

    temp_r4 = M2C_FIELD(data_02101e88, u8 *, 0x12);
    temp_r5 = *data_02101e84;
    func_020aacf0(*M2C_FIELD(arg0, void ***, 0x48));
    var_r3 = 1;
    temp_r2 = *M2C_FIELD(arg0, void ***, 0x48);
    temp_r1 = M2C_FIELD(temp_r2, void **, 0x64);
    var_r0 = M2C_FIELD(temp_r1, s8 *, 0xB);
    if ((var_r0 != 1) && ((var_r0 = (u32) ((u32) (M2C_FIELD(temp_r2, u8 *, 0x59) << 0x1B) >> 0x1F), (!var_r0)) || (var_r0 = M2C_FIELD(temp_r1, s8 *, 0xC), (var_r0 != 1)))) {
        var_r3 = 0;
    }
    if (var_r3 & 0xFF) {
        func_0208fe30(0x1000F);
        temp_r0 = *M2C_FIELD(arg0, void ***, 0x48);
        if (M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
            M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
        }
        CallSlot20(arg0);
    }
    if (temp_r4 != 0) {
        return;
    }
    if (!(temp_r5 & 2)) {
        return;
    }
    func_0208fe30(0x1000F);
    temp_r0_2 = *M2C_FIELD(arg0, void ***, 0x48);
    if ((s32) M2C_FIELD(temp_r0_2, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0_2, s32 *, (unsigned)0x40) = (s32) ((M2C_FIELD(temp_r0_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0_2, s8 *, 0x5A) = 0xC;
    }
    CallSlot20(arg0);
}

void func_ov003_021e5c68(void *arg0) {
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021e5c8c(void) {
    M2C_UNK func_01ffa6fc();
    func_01ffa6fc();
}

void func_ov003_021e5c98(void *arg0,s16 arg1,s16 arg2){
void func_01ffaacc(u16,u8,u16,void *,s32);s32 func_0207c8ec(s32,s32);s32 func_0207c928(s32,s32);
void func_020a92bc(void *,s16);void func_020a94fc(void *);s32 func_020c1980(void *,s32,s32);s32 func_ov003_02200ae8(u8);
extern u8 data_027e0074[];extern u16 **gCur3DSpriteEngine,**data_027e00c4;
s32 sp14,sp10,spC,sp8,sp4; s16 x,y,value;void *p; s32 i,palette,tile;u16 **old;
sp4=arg1;
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x3a)=-arg1;
i=0;tile=0x210;sp8=arg2;
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x42)=0;
spC=-1;sp14=0x1ff;sp10=0x3ff;
do{
x=func_0207c928(i,3)*22+sp4;
y=func_0207c8ec(i,3)*28+sp8;
p=M2C_FIELD(arg0,void **,0x68);
value=func_020c1980((u8 *)p+4,func_ov003_02200ae8(i),spC);
if(value){
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
func_020a92bc(M2C_FIELD(arg0,void **,0x50),value);
p=M2C_FIELD(arg0,void **,0x50);
M2C_FIELD(p,s16 *,6)=x+20;M2C_FIELD(p,s16 *,8)=y+102;
func_020a94fc(M2C_FIELD(arg0,void **,0x50));gCur3DSpriteEngine=old;
}
palette=value?7:8;
func_01ffaacc((x+4)&sp14,y+78,(sp10&(tile>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|(u16)(palette<<12)|0x400,data_027e0074,17);
tile+=8;i++;
}while(i<8);
}

