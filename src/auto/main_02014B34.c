/* 13 functions from 0x02014B34 to 0x02015AA0 (main), found by ds-decomp. */
#include "common.h"

s32 func_02014b34(u16 arg0) {
    s32 func_02015f10(M2C_UNK, u16, s32);
    s32 func_020189a4(s8 *);
    extern u8 data_020f5544;
    extern void *data_02136c4c;
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02008048(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 sp[0x18];
    s32 temp_r0;
    s8 temp_r3;
    s8 var_r4;
    u16 var_r0;
    u16 var_r0_3;
    u16 var_r5;
    s32 var_r0_2;
    s32 var_r3;

    (void)arg0;
    var_r5 = 0;
    var_r4 = -1;
    func_02007f8c(sp + 6, 0, 0x10);
    var_r0 = 1;
    do {
        if (M2C_FIELD((data_02136c4c + (var_r0 * 4)), s32 *, 0x14E4) == 5) {
            temp_r3 = M2C_FIELD((data_02136c4c + var_r0), s8 *, 0x1525);
            sp[6 + temp_r3] = sp[6 + temp_r3] + 1;
        }
        var_r0 += 1;
    } while ((u32) var_r0 <= 0xFU);
    var_r3 = data_020f5544;
    var_r0_2 = 0;
loop_5:
    var_r3 = (var_r3 + 1) % 16;
    if ((M2C_FIELD(((var_r3 * 0x5D4) + data_02136c4c), u8 *, 0x1D52) != 0) && (sp[6 + var_r3] != 0)) {
        var_r4 = (s8) var_r3;
    } else {
        var_r0_2 += 1;
        if (var_r0_2 < 0x10) {
            goto loop_5;
        }
    }
    if (var_r4 == -1) {
        return 0x15;
    }
    var_r0_3 = 1;
    data_020f5544 = (u8) var_r4;
    do {
        if ((M2C_FIELD((data_02136c4c + (var_r0_3 * 4)), s32 *, 0x14E4) == 5) && (var_r4 == M2C_FIELD((data_02136c4c + var_r0_3), s8 *, 0x1525))) {
            var_r5 |= 1 << var_r0_3;
        }
        var_r0_3 += 1;
    } while ((u32) var_r0_3 <= 0xFU);
    sp[0] = 3;
    *(s16 *)(sp + 2) = (s16) var_r4;
    temp_r0 = func_020189a4((s8 *)sp);
    if (temp_r0 != 0) {
        func_02008048((M2C_UNK)((var_r4 * 0x5D4) + (data_02136c4c + 0x1788)), temp_r0, 0xE4);
    }
    return func_02015f10(0xEA, var_r5, data_02136c4c);
}

void func_02014ccc(void *arg0) {
 s32 func_0200b144(void *,s32);
 void func_0200b774(void *);
 s32 func_0200b99c(void *,s32,s32,s32,s32);
 void func_0200ba9c(void *);
 s32 func_0200bbe0(void *,s32,s32);
 u32 sp4[18];
 s32 val;
 void *a,*b;
 b=M2C_FIELD(arg0,void **,0x14); a=M2C_FIELD(arg0,void **,0x10);
 func_0200b774(sp4);
 val=M2C_FIELD(a,s32 *,0);
 if(func_0200b99c(sp4,func_0200b144(b+16,M2C_FIELD(b,s32 *,0x14)),val,val+M2C_FIELD(a,s32 *,4),-1)!=0){
 if(M2C_FIELD(a,s32 *,4)==func_0200bbe0(sp4,M2C_FIELD(a,s32 *,8),M2C_FIELD(a,s32 *,4))) M2C_FIELD(a,s32 *,12)=2;
 func_0200ba9c(sp4);
 }
 if(M2C_FIELD(a,s32 *,12)==2)return;
 M2C_FIELD(a,s32 *,0)=0; M2C_FIELD(a,s32 *,12)=2;
}

/* Select units by state into priority groups, then dispatch the matching network action. */
void func_02015008(void) {
extern void *data_02136c4c;
void func_02007df8(s32,void *,s32); s32 func_02014af4(s32,u16); s32 func_02014b34(u16); s32 func_02014d6c(void);
u16 masks[5];u16 i; s32 result;
func_02007df8(0,masks,10);
for(i=1;i<=15;i++){
switch(M2C_FIELD((u8 *)data_02136c4c+4*i,s32 *,0x14e4)){
case 2:masks[0]|=1<<i;break;
case 5:masks[1]|=1<<i;break;
case 4:masks[2]|=1<<i;break;
case 8:masks[3]|=1<<i;break;
case 11:masks[4]|=1<<i;break;
}
}
if(masks[3])result=func_02014af4(5,masks[3]);
else if(masks[0])result=func_02014af4(1,masks[0]);
else if(masks[4])result=func_02014af4(6,masks[4]);
else if(masks[2])result=func_02014af4(2,masks[2]);
else if(masks[1])result=func_02014b34(masks[1]);
else result=func_02014d6c();
if(result==21)func_02014af4(0,0xffff);
}

void func_02015188(s32 arg0) {
 extern s32 data_02131180;
    extern void *data_02136c4c;
 u16 a,b; void *base;
 if(!(data_02131180 & (1<<arg0)))return;
 base=(void *)(arg0*0x5d4+data_02136c4c);
 if(M2C_FIELD(base,u8 *,0x1d52)!=0 && M2C_FIELD(base,u16 *,0x1d4c)!=0){
 a=M2C_FIELD(base+0x1d00,u16 *,0x48); b=M2C_FIELD(base,u16 *,0x1d4a);
 if((u32)b<=(u32)a && (s32)a<=b+2){M2C_FIELD(base+0x1d00,u16 *,0x48)=a+1;return;}
 M2C_FIELD(base+0x1d00,u16 *,0x48)=b;
 }
}

u32 func_02015204(u32 arg0, u32 arg1) {
    u32 var_r1;

    var_r1 = arg1;
    if (var_r1 <= arg0) {
        var_r1 = arg0;
    }
    return var_r1;
}

s32 func_02015214(u32 arg0) {
    if ((arg0 >= 1U) && (arg0 <= 0xFU)) {
        return 1;
    }
    return 0;
}

void func_02015230(M2C_UNK arg0, s16 arg1) {
    M2C_UNK func_0201409c(M2C_UNK, M2C_UNK, s16 *);
    s16 sp0;

    sp0 = arg1;
    func_0201409c(arg0, 0xD, &sp0);
}

