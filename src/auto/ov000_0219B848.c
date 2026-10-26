/* 11 functions from 0x0219B848 to 0x0219C7EC (ov000), found by ds-decomp. */
#include "common.h"
extern u8 *data_ov000_021df580;
extern u16 data_02168f14;
extern void **data_027e0058;

extern u8 *data_ov000_021df580;
extern u8 data_02168f0c[8];

void func_ov000_0219c444(void){extern void **data_027e0058;extern u16 data_ov000_021aeef4[];s32 found=0,i;void *base=*data_027e0058;u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];u8 *p;u32 type;for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52a4)]+51;i++){p=((u8 (*)[14])(base+0x59a4))[i];type=(u32)(p[0]<<26)>>26;if(type!=0&&(u8)(type+255)<=2&&((u32)(p[11]<<28)>>28)==0){found=1;break;}}if(!found)return;while(func_ov000_0219b848()){} }

void func_ov000_0219c508(s8 *arg0, s8 arg1) {
    u32 rows[40];
    s32 y=0,x;
    void *base=*data_027e0058;
    for(;y<M2C_FIELD(base,u16 *,0x5146);y++)
        rows[y]=(u32)(arg0+((u16 *)base)[y+0x1bac]);
    for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++) {
        for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++) {
            ((s8 *)rows[y])[x]=arg1;
            base=*data_027e0058;
        }
    }
    func_01ffb554(base+0x1e30);
}

void func_ov000_0219c5d4(void){for(;;){switch(*data_ov000_021df580){case 0:func_ov000_0219a1f4();break;case 1:func_ov000_0219e848();break;case 2:func_ov000_0219997c();break;case 4:if(((u32)data_02168f14<<22)>>31){if(func_020d19b4(M2C_FIELD(*data_027e0058,u16 *,0x52a4))){M2C_FIELD(*data_027e0058,u16 *,0x52b0)=13;return;}}func_ov000_0219fdc8();return;default:return;}}}

s32 func_ov000_0219c680(void){switch(*data_ov000_021df580){case 0:case 1:case 2:case 4:return 1;default:return 0;}}

u8 func_ov000_0219c6c0(void) {
    s32 func_0209e0dc(M2C_UNK);
    u8 var_r0;

    if (func_0209e0dc(6) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov000_0219c774(void);
void func_ov000_0219c6e0(void){if(func_020946d0())return;if(func_0209e0dc(6))return;if(func_ov000_0219c680()){func_0209e044(func_ov000_0219c5d4,6,0x2000,17,0);return;}switch(*data_ov000_021df580){case 3:func_ov000_0219e948();return;case 5:func_ov000_021a02ac();return;case 6:func_ov000_0219c774();return;}}

void func_ov000_0219c774(void) {
    func_ov000_0219a0e0();
    func_020bbb08();
    data_ov000_021df580[0] = 0;
    if (data_02168f0c[0] != 0) {
        func_020844f8();
    }
}

u8 func_ov000_0219c7b0(void) {
    extern u8 *data_ov000_021df580;
    return *data_ov000_021df580;
}

void func_ov000_0219c7c4(u8 a){*data_ov000_021df580=a;}

void func_ov000_0219c7d8(u8 arg0) {
    data_ov000_021df580[1] = arg0;
}

