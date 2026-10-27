/* 15 functions from 0x0201AE0C to 0x0201BDE0 (main), found by ds-decomp. */
#include "common.h"

void func_0201af48(void *arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u32 arg4, u16 arg5) {
    M2C_UNK func_02008048(M2C_UNK *, void *, M2C_UNK);
    s32 func_0201a704(u32);
    s32 func_0201a764(u32);
    M2C_UNK func_0201a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK *func_0201abd0(void);
    M2C_UNK *func_0201ad9c(s32);
    extern M2C_UNK data_02137778;
    M2C_UNK *var_r0;
    s32 temp_r0;
    u32 val;

    val = ((u32) arg5 << 8);
    val = val | (arg5 >> 8);
    M2C_FIELD(arg0, s16 *, -2) = (s16) val;
    if (func_0201a764(arg4) == 0) {
        temp_r0 = func_0201a704(arg4);
        if (temp_r0 == 0) {
            return;
        }
        var_r0 = func_0201abd0();
        if (var_r0 == 0) {
            var_r0 = func_0201ad9c(temp_r0);
            if (var_r0 == 0) {
                return;
            }
        }
        func_02008048(var_r0, arg0 - 0xE, 6);
    } else {
        M2C_FIELD(arg0, u8 *, -0xE) = 1;
        M2C_FIELD(arg0, u8 *, -0xD) = 0;
        M2C_FIELD(arg0, u8 *, -0xC) = 0x5E;
        M2C_FIELD(arg0, u8 *, -0xB) = (u8) ((arg4 >> 0x10) & 0x7F);
        M2C_FIELD(arg0, u8 *, -0xA) = (u8) (arg4 >> 8);
        M2C_FIELD(arg0, u8 *, -9) = (u8) arg4;
        func_02008048(&data_02137778, arg0 - 8, 6);
    }
    func_0201a824(arg0 - 0xE, arg1 + 0xE, arg2, arg3);
}

void func_0201b338(void *arg0, void *arg1, void *arg2) {
    M2C_UNK func_0201a588(M2C_UNK, M2C_UNK);
    M2C_UNK func_0201a63c(M2C_UNK);
    M2C_UNK func_0201b140();
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_02137290;
    void *var_r4;
    u16 temp_lr;
    u32 temp_val;
    u32 sp_0;
    u32 sp_4;

    var_r4 = (void *) M2C_FIELD(arg2, u32 *, 0x4C);
    M2C_FIELD(var_r4, s16 *, 0x22) = 8;
    M2C_FIELD(var_r4, s16 *, 0x26) = (s16) ((u32)(&data_0212dca4) >> 4); // wait, ldr r2, [pc, #0x88] -> ldr r2, [data_0212dca4 + 4] or something. Let's use extern u32 data_02137290; extern u32 data_0212dca4;
}

void func_0201b798(void *arg0) {
    M2C_UNK func_02008048(M2C_UNK *, void *, M2C_UNK);
    M2C_UNK func_0201a824(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_02137778;
    u16 temp_ip;
    u16 temp_ip_2;

    M2C_FIELD(arg0, s16 *, 6) = 0x200;
    func_02008048(arg0 + 8, arg0 + 0x12, 0xA);
    func_02008048(&data_02137778, arg0 + 8, 6);
    temp_ip = (u16) ((u32) M2C_FIELD(&data_02137290, u32 *, 0x50) >> 0x10);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((temp_ip >> 8) | (temp_ip << 8));
    temp_ip_2 = (u16) M2C_FIELD(&data_02137290, u32 *, 0x50);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((temp_ip_2 >> 8) | (temp_ip_2 << 8));
    func_02008048(arg0 + 0x12, arg0 - 0xE, 6);
    func_02008048(&data_02137778, arg0 - 8, 6);
    func_0201a824(arg0 - 0xE, 0x2A, 0, 0);
}

#pragma optimization_level 2
M2C_UNK func_0201b984(void *arg0,u8 *arg1,s32 arg2){
s32 func_0201a658(u8 *,s32);s32 func_0201a704(u32);M2C_UNK *func_0201abd0(void);void func_0201aca0(s32);M2C_UNK func_0201b140();
s32 a,b;u16 hi,lo;u32 val;
lo=M2C_FIELD(arg0,u16*,14);hi=M2C_FIELD(arg0,u16*,12);
val=((u16)(((s32)hi>>8)|(hi<<8))<<16)|(u16)(((s32)lo>>8)|(lo<<8));
a=func_0201a704(val);if(!a)return;if(!func_0201abd0()){func_0201aca0(a);return;}
arg1[0]=0;M2C_FIELD(arg1,u16*,2)=0;b=func_0201a658(arg1,arg2);M2C_FIELD(arg1,u16*,2)=(b>>8)|(b<<8);
lo=M2C_FIELD(arg0,u16*,14);hi=M2C_FIELD(arg0,u16*,12);
val=((u16)(((s32)hi>>8)|(hi<<8))<<16)|(u16)(((s32)lo>>8)|(lo<<8));
func_0201b140(arg1,arg2,0,0,val,1);
}
#pragma optimization_level 4
M2C_UNK func_0201ba68(void *arg0,u8 *arg1,M2C_UNK arg2) {
s32 func_0200751c(void); void func_02007530(s32); void func_02005e5c(s32); M2C_UNK func_02008048(M2C_UNK *,void *,M2C_UNK);
extern M2C_UNK data_0212dca4;
void *entry; s32 saved,id; void *node; u16 low,high; u32 max,len;
saved=func_0200751c();
node=M2C_FIELD(&data_0212dca4,void **,8);
while(node){
entry=M2C_FIELD(node,void **,0xa4);
if(entry && (id=M2C_FIELD(entry,s32 *,0))!=0){
if(M2C_FIELD(entry,u8 *,8)==11 && M2C_FIELD(arg1,u16 *,4)==(u16)id && M2C_FIELD(entry,u16 *,10)==M2C_FIELD(arg1,u16 *,6) && M2C_FIELD(entry,u32 *,68)==0){
low=M2C_FIELD(arg0,u16 *,14);high=M2C_FIELD(arg0,u16 *,12);
if(M2C_FIELD(entry,u32 *,28)==(((u16)(((s32)high>>8)|(high<<8))<<16)|(u16)(((s32)low>>8)|(low<<8)))){
max=M2C_FIELD(entry,u32 *,60);len=arg2-8;
if(len>max)M2C_FIELD(entry,u32 *,68)=max;else M2C_FIELD(entry,u32 *,68)=len;
func_02008048((M2C_UNK *)(arg1+8),M2C_FIELD(entry,void **,64),M2C_FIELD(entry,u32 *,68));
if(M2C_FIELD(entry,s32 *,4)==3){M2C_FIELD(entry,s32 *,4)=0;func_02005e5c(M2C_FIELD(entry,s32 *,0));}
break;
}
}
}
node=M2C_FIELD(node,void **,104);
}
func_02007530(saved);
}

s32 func_0201bb68(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 != -1) && (arg1 != 0) && (arg1 != -1)) {
        return 1;
    }
    return 0;
}

void func_0201bb88(void *arg0, u8 *arg1, M2C_UNK arg2) {
    s32 func_0201a658(u8 *, M2C_UNK);
    M2C_UNK func_0201b984(void *, u8 *, M2C_UNK);
    M2C_UNK func_0201ba68(void *, u8 *, M2C_UNK);
    u16 temp_r0;
    u16 temp_r8;
    u16 temp_r7;
    u16 temp_lr;
    u32 var0;
    u32 var1;
    u8 temp_r0_2;

    if (func_0201a658(arg1, arg2) != 0xFFFF) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 0x12);
    temp_r8 = M2C_FIELD(arg0, u16 *, 0x10);
    temp_r7 = M2C_FIELD(arg0, u16 *, 0xE);
    temp_lr = M2C_FIELD(arg0, u16 *, 0xC);

    var0 = ((temp_r7 << 8) | ((s32)temp_r7 >> 8)) | ((((temp_lr << 8) | ((s32)temp_lr >> 8))) << 16);
    var1 = ((temp_r0 << 8) | ((s32)temp_r0 >> 8)) | ((((temp_r8 << 8) | ((s32)temp_r8 >> 8))) << 16);

    if (func_0201bb68(var0, var1) == 0) {
        return;
    }
    temp_r0_2 = *arg1;
    switch (temp_r0_2) {
    case 0:
        func_0201ba68(arg0, arg1, arg2);
        return;
    case 8:
        func_0201b984(arg0, arg1, arg2);
        return;
    }
}

void *func_0201bc58(void *arg0, void *arg1) {
extern M2C_UNK data_0212dca4;
void *entry,*node; u16 a,b,c,d,e;
node=M2C_FIELD(&data_0212dca4,void **,8);
while(node){
entry=M2C_FIELD(node,void **,0xa4);
if(entry && M2C_FIELD(entry,s32 *,0) && M2C_FIELD(entry,u8 *,8)==1){
a=M2C_FIELD(arg1,u16 *,2);
if(M2C_FIELD(entry,u16 *,10)!=(u16)(((s32)a>>8)|(a<<8)))goto next;
b=M2C_FIELD(entry,u16 *,24);
if(b){c=M2C_FIELD(arg1,u16 *,0);if(b!=(u16)(((s32)c>>8)|(c<<8)))goto next;}
if(M2C_FIELD(entry,u32 *,28)){
d=M2C_FIELD(arg0,u16 *,14);e=M2C_FIELD(arg0,u16 *,12);
if(M2C_FIELD(entry,u32 *,28)!=(((u16)(((s32)e>>8)|(e<<8))<<16)|(u16)(((s32)d>>8)|(d<<8))))goto next;
}
return entry;
}
next: node=M2C_FIELD(node,void **,0x68);
}
return 0;
}

s32 func_0201bd2c(void *arg0, void *arg1, void *arg2) {
    s32 var_ip;
    s32 var_r3;
    s32 var_r5;
    s32 var_r6;
    u16 temp_lr;
    u16 temp_lr_2;
    u16 temp_lr_3;
    u16 temp_r4_2;
    u8 temp_r4;

    temp_r4 = M2C_FIELD(arg2, u8 *, 8);
    var_r3 = 0;
    var_r5 = 0;
    if ((temp_r4 != 0xA) && (temp_r4 != 0xB)) {
        var_r5 = 1;
    }
    var_ip = 0;
    var_r6 = 0;
    if (var_r5 != 0) {
        temp_lr = M2C_FIELD(arg1, u16 *, 2);
        if (M2C_FIELD(arg2, u16 *, 0xA) == (u16) ((temp_lr >> 8) | (temp_lr << 8))) {
            var_r6 = 1;
        }
    }
    if (var_r6 != 0) {
        temp_lr_2 = M2C_FIELD(arg1, u16 *, 0);
        if (M2C_FIELD(arg2, u16 *, 0x18) == (u16) ((temp_lr_2 >> 8) | (temp_lr_2 << 8))) {
            var_ip = 1;
        }
    }
    if (var_ip != 0) {
        temp_lr_3 = M2C_FIELD(arg0, u16 *, 0xC);
        temp_r4_2 = M2C_FIELD(arg0, u16 *, 0xE);
        if (M2C_FIELD(arg2, s32 *, 0x1C) == ((u16) ((temp_r4_2 >> 8) | (temp_r4_2 << 8)) | ((u16) ((temp_lr_3 >> 8) | (temp_lr_3 << 8)) << 0x10))) {
            var_r3 = 1;
        }
    }
    return var_r3;
}

