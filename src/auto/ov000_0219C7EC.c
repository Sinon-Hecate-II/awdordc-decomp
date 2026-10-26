/* 18 functions from 0x0219C7EC to 0x0219D724 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0219c7ec(s32 a){extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;s32 n,i,j;u8 *p,*q;u8 x,y,t;if(a<2)return;n=a-2;i=0;if(n<0)return;do{j=n;if(n>=i){p=(u8 *)&data_ov000_021df868+n;q=&data_ov000_021df824+n;do{y=p[1];x=p[0];if((u32)x<(u32)y){p[0]=y;p[1]=x;t=q[0];q[0]=q[1];q[1]=t;}j--;p--;q--;}while(j>=i);}i++;}while(i<=n);}

void func_ov000_0219c874(s32 a){extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;s32 n,i,j;u8 *p,*q;u8 x,y,t;if(a<2)return;n=a-2;i=0;if(n<0)return;do{j=n;if(n>=i){p=(u8 *)&data_ov000_021df868+n;q=&data_ov000_021df824+n;do{y=p[1];x=p[0];if((u32)x>(u32)y){p[0]=y;p[1]=x;t=q[0];q[0]=q[1];q[1]=t;}j--;p--;q--;}while(j>=i);}i++;}while(i<=n);}

void func_ov000_0219c8fc(void){void func_ov000_0219c7ec(s32);extern s32 *data_027e0058;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;s32 *base=data_027e0058;u8 *p=&data_ov000_021df824;s8 *q=&data_ov000_021df868;s32 n=0;u8 x;loop: x=*p;if(x!=0){s32 a=x*14+(*base+0x59a4);p++;*q=(u32)(M2C_FIELD(a,u16 *,6)<<25)>>24;if(((u32)(M2C_FIELD(a,u16 *,8)<<26)>>26)!=63)(*q)++;q++;n++;goto loop;}func_ov000_0219c7ec(n);}
#pragma opt_common_subs reset
void func_ov000_0219c984(void){void func_ov000_0219c7ec(s32);extern s32 *data_027e0058;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;register s32 *base;register u8 *p;register s8 *q;s32 n;u8 x;base=data_027e0058;p=&data_ov000_021df824;q=&data_ov000_021df868;n=0;loop: x=*p;if(x!=0){p++;*q++=(u32)(M2C_FIELD(*base+x*14,u16 *,0x59aa)<<25)>>25;n++;goto loop;}func_ov000_0219c7ec(n);}
void func_ov000_0219cb98(void) {
    void func_ov000_0219c874(s32);
    s8 func_020a7bd4(u32);
    extern s32 *data_027e0058;
    extern u8 data_ov000_021df824;
    extern s8 data_ov000_021df868;
    s32 var_r4;
    u8 *var_r5;
    s8 *var_r6;
    u8 temp_r1;

    var_r5 = &data_ov000_021df824;
    var_r6 = &data_ov000_021df868;
    var_r4 = 0;
loop_1:
    temp_r1 = *var_r5;
    if (temp_r1 != 0) {
        *var_r6 = func_020a7bd4((u32) (M2C_FIELD(((temp_r1 * 0xE) + *data_027e0058), u8 *, 0x59A4) << 0x1A) >> 0x1A);
        var_r6 += 1;
        ++var_r5;
        ++var_r4;
        goto loop_1;
    }
    func_ov000_0219c874(var_r4);
}

void func_ov000_0219cc04(s32 arg0) {
s8 func_020a7824(s32,u8,u8);
extern s32 *data_027e0058;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;
s32 n;u8 *p;s8 *q;u8 x;s32 a;
p=&data_ov000_021df824;q=&data_ov000_021df868;n=0;
loop: x=*p;if(x){a=x*14+(*data_027e0058+0x59a4);*q=func_020a7824(a,M2C_FIELD(a,u8 *,1),M2C_FIELD(a,u8 *,2));q++;p++;n++;goto loop;}
if(arg0==0){func_ov000_0219c874(n);return;}func_ov000_0219c7ec(n);
}

void func_ov000_0219cc84(void) {
s8 func_020a7824(s32,u8,u8);
extern s32 *data_027e0058;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;
s32 n;u8 *p;s8 *q;u8 x;s32 a;
p=&data_ov000_021df824;q=&data_ov000_021df868;n=0;
loop: x=*p;if(x){a=x*14+(*data_027e0058+0x59a4);*q=func_020a7824(a,M2C_FIELD(a,u8 *,1),M2C_FIELD(a,u8 *,2));p++;n++;if(!(M2C_FIELD(a,u16 *,4)&8))*q=*(volatile u8*)q+10;q++;goto loop;}
func_ov000_0219c874(n);
}

void func_ov000_0219cdf4(void) {
    s32 func_020a7cfc(s32);
    extern s32 *data_027e0058;
    extern u8 data_ov000_021df824;
    unsigned var_r4;
    u8 var_r5;
    register u8 *var_r1;
    u8 temp_r0;
    u8 *var_r6;
    u8 temp_r1;
    long var_r7;

    var_r4 = 0;
    var_r6 = &data_ov000_021df824;
    var_r7 = 0;
    var_r5 = 0;
loop_1:
    temp_r1 = *var_r6;
    if (temp_r1) {
        if (func_020a7cfc((temp_r1 * 0xE) + (*data_027e0058 + 0x59A4)) != 0) {
            var_r7 = var_r4;
            var_r5 = (&data_ov000_021df824)[var_r4];
        } else {
            ++var_r6;
            ++var_r4;
            goto loop_1;
        }
    }
    if (var_r5 == 0) {
        return;
    }
    var_r1 = &(&data_ov000_021df824)[var_r7];
loop_8:
    temp_r0 = M2C_FIELD(var_r1, u8 *, 1);
    if (temp_r0) {
        ++var_r1;
        M2C_FIELD(var_r1, u8 *, 0) = temp_r0;
        ++var_r7;
        goto loop_8;
    }
    (&data_ov000_021df824)[var_r7] = var_r5;
}

