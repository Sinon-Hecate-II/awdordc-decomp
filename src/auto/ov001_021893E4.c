/* 27 functions from 0x021893E4 to 0x0218A384 (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_0218959c(void) {
    M2C_UNK func_ov001_02189828(void);
    void func_ov001_02188a20(s32);
    extern s32 func_ov001_021897ec(s32);
    extern void *data_ov001_02193e28;
    func_ov001_02189828();
    func_ov001_02188a20((s32) &func_ov001_021897ec);
    M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 8;
}

void func_ov001_021897a4(void) {
    extern void *data_ov001_02193e28;
    M2C_FIELD(data_ov001_02193e28, s8 *, 0xA90) = 0xC;
}

s32 func_ov001_021897bc(void) {
    M2C_UNK func_ov001_02188394(void);
    M2C_UNK func_ov001_02188c28(void);
    extern void *data_ov001_02193e28;
    if (func_ov001_02188394() != 1) {
        return 0;
    }
    func_ov001_02188c28();
    M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 1;
    return 1;
}

s32 func_ov001_021897ec(s32 arg0) {
    s32 func_ov001_02187a30(s32);
    s32 func_ov001_021879fc(s32);
    extern void *data_ov001_02193e28;
    s32 temp_r0;

    temp_r0 = func_ov001_02187a30(arg0 + 0xA);
    if (temp_r0 == 0) {
        return 0;
    }
    M2C_FIELD((u8 *) data_ov001_02193e28 + (temp_r0 - 1) * 4, s32 *, 0xAA0) = func_ov001_021879fc(temp_r0);
    return 1;
}

M2C_UNK func_ov001_02189828(void) {
    extern void *data_ov001_02193e28;
    void func_02007f8c(void *, s32, s32);
    
    func_02007f8c((u8 *)data_ov001_02193e28 + 0x100, 0, 0x100);
    func_02007f8c(data_ov001_02193e28, 0, 0x100);
    *(u32 *)((u8 *)data_ov001_02193e28 + 0xAB0) = (u32)data_ov001_02193e28;
}

#pragma optimization_level 2
void func_ov001_021899d4(void) {
extern void *data_ov001_02193e28;s32 i;u8 *p;
i=0;do {
if(M2C_FIELD((u8 *)data_ov001_02193e28+i*4,s32*,0x208)){
p=(u8 *)data_ov001_02193e28+0x100+i*0x44;
if(i==1){
if(M2C_FIELD(data_ov001_02193e28,u8*,0xa93)==1){
if(*(u16 *)p!=0x10)return;
M2C_FIELD(data_ov001_02193e28,s32*,0xa94)++;
if(!(M2C_FIELD(data_ov001_02193e28,s32*,0xa94)&1)){
M2C_FIELD(data_ov001_02193e28,u16*,0x200)++;
if(M2C_FIELD(data_ov001_02193e28,u16*,0x200)>=0x24)M2C_FIELD(data_ov001_02193e28,u16*,0x200)=0;
}
}else{
M2C_FIELD(data_ov001_02193e28,u16*,0x202)=0xbc;
if(*(u16 *)p==0xbd){
M2C_FIELD(data_ov001_02193e28,u8*,0xa93)=1;
M2C_FIELD(data_ov001_02193e28,u16*,0x200)=0;
M2C_FIELD(data_ov001_02193e28,s32*,0xa94)=0;
}
}
}
}
i++;
}while(i<16);
}
#pragma optimization_level 4
u16 func_ov001_02189ab8(void) {
    extern void *data_ov001_02193e28;
    void *ptr = data_ov001_02193e28;
    return M2C_FIELD((u8 *)ptr + 0x100, u16 *, 0x44);
}

void func_ov001_02189c80(void) {
    extern void *data_ov001_021917b4[2];
    extern void *data_ov001_02193e2c;
    void func_0200bc5c(void *);
    void func_0200b510(void *);
    void func_0200b32c(void *);
    void func_0200b238(void *);
    void func_020055f4(u16);
    void func_ov001_0218b71c(void *);
    u16 half;
    
    func_0200bc5c(data_ov001_021917b4);
    func_0200b510((u8 *)data_ov001_02193e2c + 0x88);
    func_0200b32c((u8 *)data_ov001_02193e2c + 0x88);
    func_0200b238((u8 *)data_ov001_02193e2c + 0x88);
    half = M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4);
    func_020055f4(half);
    M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4) = 0;
    func_ov001_0218b71c(data_ov001_02193e2c);
    M2C_FIELD(data_ov001_02193e2c, u32 *, 0) = 0;
    func_ov001_0218b71c(data_ov001_021917b4[1]);
}

s32 func_ov001_02189d0c(s32 arg0, s32 arg1) {
    M2C_UNK func_0200fe24(u16);
    M2C_UNK func_0200fe40(u16);
    extern void *data_ov001_02193e2c;
    
    switch (arg1) {
    case 9:
        func_0200fe24(M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4));
        return 0;
    case 10:
        func_0200fe40(M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4));
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}

void func_ov001_02189db0(M2C_UNK arg0);

s32 func_ov001_02189d70(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_02010b1c(M2C_UNK, s32, M2C_UNK, M2C_UNK *, void *, s32);
    func_02010b1c(-1, arg2 + M2C_FIELD(arg0, s32 *, 0x28), arg1, (M2C_UNK *) &func_ov001_02189db0, arg0, 1);
    return 6;
}

void func_ov001_02189db0(M2C_UNK arg0) {
    M2C_UNK func_0200b6c8(M2C_UNK, M2C_UNK);
    func_0200b6c8(arg0, 0);
}

s32 func_ov001_02189dc0(void) {
    return 1;
}

void *func_ov001_02189dc8(void *arg0,u32 *arg1,s32 arg2){
void func_ov001_0218a74c(s32);void func_0200b774(void *);s32 func_0200ba54(void *,void *);void func_02007958(void);void func_0200bbe0(void *,void *,s32);void func_0200ba9c(void *);void func_020081d0(void *,void *);void func_ov001_0218b71c(void *);s32 func_ov001_0218b6f8(s32,s32);
extern void *data_ov001_02193e2c;extern s32 data_ov001_021917bc;
void *buf;u32 work[18];u32 size;s32 align;void *out;
func_ov001_0218a74c(M2C_FIELD(data_ov001_02193e2c,s32*,0x84));
func_0200b774(work);if(!func_0200ba54(work,arg0))func_02007958();
size=work[10]-work[9];if(arg1)*arg1=size;
if(func_ov001_02189ef0(arg0,(s32)&data_ov001_021917bc,2))align=-4;else align=arg2;
buf=(void *)func_ov001_0218b6f8(size,align);
func_0200bbe0(work,buf,size);func_0200ba9c(work);
if(align>0)return buf;
size=*(u32 *)buf>>8;if(arg1)*arg1=size;
out=(void *)func_ov001_0218b6f8(size,arg2);func_020081d0(buf,out);func_ov001_0218b71c(&buf);return out;
}

void func_ov001_02189ebc(void) {
    M2C_UNK func_ov001_0218a6f4(s32, void *);
    void func_ov001_0218b71c(void *);
    extern void *data_ov001_02193e2c;
    s32 saved_r0;
    
    func_ov001_0218b71c(&saved_r0);
    func_ov001_0218a6f4(M2C_FIELD(data_ov001_02193e2c, s32 *, 0x84), (void *)saved_r0);
}

s32 func_ov001_02189ef0(void *arg0, s32 arg1, s32 arg2) {
    s32 func_02068c34(void *);
    s32 func_0206527c(void *, void *, s32);
    s32 temp_r4;
    s32 temp_r0;
    
    temp_r4 = func_02068c34(arg0);
    temp_r0 = func_02068c34(arg1);
    if (temp_r4 < arg2 || temp_r0 < arg2) {
        return 0;
    }
    if (func_0206527c(arg0 + (temp_r4 - arg2), arg1 + (temp_r0 - arg2), arg2) == 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02189f48(void) {
s32 func_ov001_0218a698(s32,s32,s32);s32 func_ov001_0218b6f8(s32,s32);s32 func_ov001_0218bf04();M2C_UNK func_ov001_0218bfb4(s32,void *);M2C_UNK func_ov001_0218bfc4(s32,void *);s32 func_ov001_0218c150(s32,s32);
extern s32 data_ov001_02193e30;
s32 i;void *p;
data_ov001_02193e30=func_ov001_0218b6f8(0x450,4);
for(i=0;i<2;i++){
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x224)=func_ov001_0218a698(0x20,data_ov001_02193e30+i*0x228,0x10);
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x220)=func_ov001_0218bf04();
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x208)=func_ov001_0218c150(i,0x40);
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x218)=func_ov001_0218c150(i,0x7f)+8;
p=(void *)(data_ov001_02193e30+i*0x228);func_ov001_0218bfc4(M2C_FIELD(p,s32*,0x220),p+0x200);
p=(void *)(data_ov001_02193e30+i*0x228);func_ov001_0218bfb4(M2C_FIELD(p,s32*,0x220),p+0x210);
}
}

void func_ov001_0218a01c(void) {
    void func_ov001_0218a6d8(s32);
    void func_ov001_0218b71c(void *);
    void func_ov001_0218bf30(s32);
    extern s32 data_ov001_02193e30;
    s32 var_r5;
    s32 var_r6;
    
    var_r5 = 0;
    var_r6 = 0;
    do {
        func_ov001_0218bf30(M2C_FIELD((data_ov001_02193e30 + var_r6), s32 *, 0x220));
        func_ov001_0218a6d8(M2C_FIELD((data_ov001_02193e30 + var_r6), s32 *, 0x224));
        var_r5 += 1;
        var_r6 += 0x228;
    } while (var_r5 < 2);
    func_ov001_0218b71c(&data_ov001_02193e30);
}

void func_ov001_0218a1cc(void *arg0) {
    M2C_UNK func_ov001_0218a6f4(s32, void *);
    M2C_UNK func_ov001_0218bf4c(void *);
    extern s32 data_ov001_02193e30;
    u8 *var_r2;
    s32 var_r3;
    s32 var_r4;

    var_r4 = 0;
    var_r3 = 0;
    var_r2 = M2C_FIELD(arg0, u8 **, 8);
    if ((s32) M2C_FIELD(arg0, u8 *, 0xC) > 0) {
        do {
            var_r3 += 1;
            M2C_FIELD(var_r2, s32 *, 0) = (M2C_FIELD(var_r2, s32 *, 0) & 0xC1FFFCFF) | 0x200;
            var_r2 += 8;
        } while (var_r3 < (s32) M2C_FIELD(arg0, u8 *, 0xC));
    }
    func_ov001_0218bf4c(arg0);
    if ((u32) arg0 >= (u32) (data_ov001_02193e30 + 0x228)) {
        var_r4 = 1;
    }
    func_ov001_0218a6f4(M2C_FIELD(((var_r4 * 0x228) + data_ov001_02193e30), s32 *, 0x224), arg0);
}

s32 func_ov001_0218a24c(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 8) + (arg1 * 8);
}

u8 func_ov001_0218a258(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0xC);
}

void func_ov001_0218a260(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 *array;
    u8 limit;
    u32 mask;
    u32 val;
    s32 i;
    
    if (arg1 < 0) return;
    array = M2C_FIELD(arg0, u32 *, 0x8);
    if (arg2 == 0x100 || arg2 == 0x300) {
        mask = 0xC1FFFCFF;
        val = array[arg1] & mask;
        val |= arg2;
        array[arg1] = val;
        return;
    }
    val = array[arg1] & 0xC1FFFCFF;
    val |= arg2;
    val |= arg3 << 25;
    array[arg1] = val;
    return;
    
    limit = M2C_FIELD(arg0, u8 *, 0xC);
    if (limit == 0) return;
    mask = 0xC1FFFCFF;
    i = 0;
    do {
        if (arg2 == 0x100 || arg2 == 0x300) {
            val = array[i] & mask;
            val |= arg2;
        } else {
            val = array[i] & mask;
            val |= arg2;
            val |= arg3 << 25;
        }
        array[i] = val;
        limit = M2C_FIELD(arg0, u8 *, 0xC);
        i++;
    } while (i < limit);
}

