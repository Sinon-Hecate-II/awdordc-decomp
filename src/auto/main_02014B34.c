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

u32 func_02015248(void *arg0) {
 s32 func_0200bbe0(void *,s32,s32);
 void func_0200bbf0(void *,s32,s32);
 u32 sp0[24]; void *p; u32 result; s32 pos;
 p=NULL;result=0;
 if(arg0!=NULL){
 pos=M2C_FIELD(arg0,s32 *,0x2c)-M2C_FIELD(arg0,s32 *,0x24);
 if((u32)func_0200bbe0(arg0,(s32)sp0,0x60)>=0x60U)p=sp0;
 func_0200bbf0(arg0,pos,0);
 }else p=(void *)0x027ffe00;
 if(p!=NULL){result=M2C_FIELD(p,s32 *,0x2c)+0x268+M2C_FIELD(p,s32 *,0x3c);if(result<0x10000U)result=0x10000;}
 return result;
}

void func_02015724(void *arg0, u32 arg1, u32 arg2, s32 arg3) {
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    M2C_UNK func_02008048(s32, s32, s32);
    u32 temp_ip;
    u32 temp_r1;
    u32 var_lr;
    u32 var_r2;

    var_r2 = arg2;
    var_lr = arg1;
    temp_ip = M2C_FIELD(arg0, u32 *, 0);
    if (var_lr < 0x4000U) {
        var_lr = 0x4000;
    }
    if (var_r2 > 0x8000U) {
        var_r2 = 0x8000;
    }
    temp_r1 = temp_ip + M2C_FIELD(arg0, s32 *, 0xC);
    if (var_lr < temp_ip) {
        var_lr = temp_ip;
    }
    if (var_r2 > temp_r1) {
        var_r2 = temp_r1;
    }
    if (var_lr >= var_r2) {
        return;
    }
    if (arg3 != 0) {
        func_02007f8c(M2C_FIELD(arg0, s32 *, 8) + var_lr, 0, var_r2 - var_lr);
        return;
    }
    func_02008048(M2C_FIELD(arg0, s32 *, 4) + var_lr, M2C_FIELD(arg0, s32 *, 8) + var_lr, var_r2 - var_lr);
}

s32 func_0201579c(s32 arg0, s32 arg1) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    void func_02015a2c(void *, void *);
    s32 func_02015c18(void *, void *);
    M2C_UNK func_02015f94(void *, s32, void *);
    M2C_UNK func_020161bc(void *);
    s32 func_02018418();
    M2C_UNK func_0201869c(void *, M2C_UNK);
    s32 func_0201871c();
    M2C_UNK func_02018738(void *);
    extern u8 data_02131184;
    extern void *data_02136c4c;
    s32 temp_r2;
    s32 temp_r5;
    s32 temp_r6;
    u8 var_r4;
    u8 var_r6;
    void *temp_r9;

    var_r4 = 0xFF;
                      temp_r5 = func_0200751c();
    if (func_02018418() == 0) {
        func_02007530(temp_r5);
        return 0;
    }
    if ((s32) (M2C_FIELD(data_02136c4c, u8 *, 0x1524) + 1) > 0x10) {
        func_02007530(temp_r5);
        return 0;
    }
    var_r6 = 0;
loop_5:
    temp_r2 = (var_r6 * 0x5D4) + (s32) data_02136c4c;
    if (M2C_FIELD(temp_r2, s32 *, 0x1D40) == arg0) {
        func_02007530(temp_r5);
        return 0;
    }
    if (M2C_FIELD(temp_r2, u8 *, 0x1D52) == 0) {
        var_r4 = var_r6;
        goto block_10;
    }
    var_r6 += 1;
    if ((u32) var_r6 >= 0x10U) {
block_10:
        if (var_r6 == 0x10) {
            func_02007530(temp_r5);
            return 0;
        }
        temp_r6 = var_r4 * 0x5D4;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D40) = arg0;
        temp_r9 = data_02136c4c + 0x1788 + temp_r6;
        func_02015a2c(temp_r9, arg1);
        func_02008048(arg0 + 0x1C, temp_r9 + 0xC4, 0x20);
        if (func_02015c18(data_02136c4c + 0x1D2C + temp_r6, temp_r9) == 0) {
            func_02007530(temp_r5);
            return 0;
        }
        func_02015f94(data_02136c4c + 0x186C + temp_r6, arg0, data_02136c4c + 0x1300);
        M2C_FIELD((data_02136c4c + temp_r6), u8 *, 0x1D21) = var_r4;
        func_020161bc(data_02136c4c + 0x186C + temp_r6);
        M2C_FIELD((data_02136c4c + temp_r6), u8 *, 0x1D1F) = (u8) data_02131184;
        M2C_FIELD((data_02136c4c + temp_r6), s16 *, 0x1D4E) = 1;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D44) = arg1;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D54) = (s32) (arg1 + 0x1E8);
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D58) = (s32) (arg1 + 0x258);
        data_02131184 += 1;
        if ((M2C_FIELD(M2C_FIELD((data_02136c4c + temp_r6), void **, 0x1D54), s32 *, 0x6C) != 0) && (func_0201871c() == 0)) {
            func_02018738(data_02136c4c + 0x7CE0);
            func_0201869c(data_02136c4c + 0x74E0, 0x800);
        }
        M2C_FIELD((data_02136c4c + temp_r6), s8 *, 0x1D52) = 1;
        M2C_FIELD(data_02136c4c, u8 *, 0x1524) = (u8) (M2C_FIELD(data_02136c4c, u8 *, 0x1524) + 1);
        func_02007530(temp_r5);
        return 1;
    }
    goto loop_5;
}

void func_02015a2c(void *arg0, void *arg1) {
 M2C_UNK func_02008048(s32,s32,s32);
 void func_02015aa0(void *, void *, void *, s32 *);
 extern u8 data_020ea72c[];
 s32 sp0;
 u8 *p;
 void *out;
 s32 i;
 sp0=0x022C0000;
 p=data_020ea72c;
 M2C_FIELD(arg0,s32 *,0)=M2C_FIELD(arg1,s32 *,0x24);
 out=arg0+12;
 M2C_FIELD(arg0,s32 *,4)=M2C_FIELD(arg1,s32 *,0x34);
 i=0;
 do {func_02015aa0(arg1,p,out,&sp0); i++; out+=16; p+=4;} while(i<3);
 func_02008048((s32)arg1+0x160,(s32)arg0+0x3c,0x88);
}

