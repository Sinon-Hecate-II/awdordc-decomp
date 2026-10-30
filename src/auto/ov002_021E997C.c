/* 11 functions from 0x021E997C to 0x021EA674 (ov002), found by ds-decomp. */
#include "common.h"
static inline void *init_021ea37c(void *p) {
extern u8 data_ov002_021ea704[];
M2C_FIELD(p,void **,0)=data_ov002_021ea704;
M2C_FIELD(p,s32 *,8)=0;M2C_FIELD(p,s32 *,12)=0;return p;
}

void func_ov002_021e997c(void *arg0) {
void func_ov002_021e16dc(void *,s32,u16,u8,s32);
extern u8 data_ov002_021f3018[];
extern u8 data_ov002_021f3030[];
extern u8 data_ov002_021f3045[];
extern u8 data_ov002_021f30f4[];
u8 index = M2C_FIELD(arg0,u8 *,0x8C);
s32 offset = index*0x64;
s32 value = M2C_FIELD(data_ov002_021f3018,s32 *,offset);
if (!value) return;
func_ov002_021e16dc(arg0,value,M2C_FIELD(data_ov002_021f3030,u16 *,offset),M2C_FIELD(data_ov002_021f3045+offset,u8 *,M2C_FIELD(arg0,u8 *,0x8D)*8),M2C_FIELD(M2C_FIELD(data_ov002_021f30f4,void **,index*0x18),u8 *,0x38));
}

void func_ov002_021e99f0(void *arg0, s32 arg1) {
    void *func_02082028(s32);
    void func_ov002_021e16bc(void *, u8, u8);
    void func_ov002_021e16dc(void *, s32, u16, u8, s32);
    void func_ov002_021e179c(void *, s16, s16, s16);
    void func_ov002_021e17ac(void *, u32);
    extern u8 data_ov002_021ea704[];
    extern u8 data_ov002_021f301c[];
    extern u8 data_ov002_021f3032[];
    extern u8 data_ov002_021f3047[];
    extern u8 data_ov002_021f30f4[];
    extern u8 data_ov002_021f3103[];
    extern u8 data_ov002_021f3108[];
    extern u8 data_ov002_021f314e[];
    s16 temp_r7;
    s16 var_r5;
    s16 var_r6;
    s32 temp_r2;
    s32 temp_r5;
    u32 temp_r9;
    u8 temp_r1;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r2_2;
    void *var_r0;
    void *var_r3;

    if (M2C_FIELD(data_ov002_021f301c, s32 *, M2C_FIELD(arg0, u8 *, 0x8C) * 0x64) == 0) {
        return;
    }
    if (M2C_FIELD(arg0, void **, 0x54) != NULL) {
        temp_r0 = func_02082028(8);
        if (temp_r0 != NULL) {
            M2C_FIELD(temp_r0, void **, 0) = NULL;
            M2C_FIELD(temp_r0, void **, 4) = NULL;
        }
        M2C_FIELD(temp_r0, void **, 0) = (void *) M2C_FIELD(arg0, void **, 0x54);
        M2C_FIELD(temp_r0, void **, 4) = (void *) M2C_FIELD(arg0, void **, 0x58);
        M2C_FIELD(arg0, void **, 0x58) = temp_r0;
    }
    temp_r0_2 = func_02082028(0x54);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, void **, 0) = (void *)data_ov002_021ea704;
        M2C_FIELD(temp_r0_2, s32 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s32 *, 0xC) = 0;
    }
    M2C_FIELD(arg0, void **, 0x54) = temp_r0_2;
    temp_r1 = M2C_FIELD(arg0, u8 *, 0x8C);
    temp_r2 = temp_r1 * 0x18;
    if (M2C_FIELD(data_ov002_021f314e + (temp_r1 * 0x2C), u8 *, 0) != 0) {
        var_r0 = M2C_FIELD(data_ov002_021f30f4 + temp_r2, void **, 0x28);
        var_r3 = var_r0 + (arg1 * 8);
    } else {
        var_r0 = M2C_FIELD(data_ov002_021f30f4 + temp_r2, void **, 0x28);
        var_r3 = var_r0 + (M2C_FIELD(data_ov002_021f3103 + temp_r2, u8 *, 0) * 8);
    }
    var_r5 = M2C_FIELD(var_r3, s16 *, 0x28);
    var_r6 = M2C_FIELD(var_r3, s16 *, 0x2A);
    temp_r7 = M2C_FIELD(var_r3, s16 *, 0x2C);
    if (M2C_FIELD(data_ov002_021f3108 + temp_r2, u8 *, 0) != 0) {
        temp_r2_2 = (void *)((u8 *)M2C_FIELD(data_ov002_021f30f4 + temp_r2, void **, 0x28) + (M2C_FIELD(data_ov002_021f3103 + temp_r2, u8 *, 0) * 4));
        var_r5 += M2C_FIELD(temp_r2_2, s16 *, 0xC4);
        var_r6 += M2C_FIELD(temp_r2_2, s16 *, 0xC6);
    }
    temp_r9 = (u32) ((M2C_FIELD(var_r3, u16 *, 0x2E) * M2C_FIELD(var_r0, u16 *, 0xCC)) << 8) >> 0x10;
    func_ov002_021e16bc(temp_r0_2, temp_r1, M2C_FIELD(arg0, u8 *, 0x8D));
    func_ov002_021e179c(temp_r0_2, var_r5, var_r6, temp_r7);
    func_ov002_021e17ac(temp_r0_2, temp_r9);
    temp_r5 = M2C_FIELD(arg0, u8 *, 0x8C) * 0x64;
    func_ov002_021e16dc(temp_r0_2, M2C_FIELD(data_ov002_021f301c, s32 *, temp_r5), M2C_FIELD(data_ov002_021f3032, u16 *, temp_r5), M2C_FIELD(data_ov002_021f3047 + temp_r5, u8 *, M2C_FIELD(arg0, u8 *, 0x8D) * 8), 0);
}

void func_ov002_021e9e0c(void *arg0,s32 arg1) {
void *func_02082028(s32);void func_ov002_021e16bc(void *,u8,u8);void func_ov002_021e16dc(void *,s32,u16,u8,s32);void func_ov002_021e179c(void *,s16,s16,s16);void func_ov002_021e17ac(void *,u32);
extern u8 data_ov002_021ea704[],data_ov002_021f3024[],data_ov002_021f3036[],data_ov002_021f3049[],data_ov002_021f30f4[];
void *p,*q,*lr,*t;u32 v;s32 off;s16 x,y;
if(!M2C_FIELD(data_ov002_021f3024,s32 *,M2C_FIELD(arg0,u8 *,140)*100))return;
if(M2C_FIELD(arg0,void **,84)){
p=func_02082028(8);if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(arg0,void **,84);M2C_FIELD(p,void **,4)=M2C_FIELD(arg0,void **,88);M2C_FIELD(arg0,void **,88)=p;}
M2C_FIELD(arg0,void **,84)=((p=func_02082028(84)) ? init_021ea37c(p):p);
q=M2C_FIELD(arg0,void **,84);
func_ov002_021e16bc(q,M2C_FIELD(arg0,u8 *,140),M2C_FIELD(arg0,u8 *,141));
lr=M2C_FIELD(M2C_FIELD(data_ov002_021f30f4,void **,M2C_FIELD(arg0,u8 *,140)*24),void **,40);
x=M2C_FIELD(lr,s16 *,120);y=M2C_FIELD(lr,s16 *,122);
if(arg1!=-1){t=lr+arg1*4;x+=M2C_FIELD(t,s16 *,176);y+=M2C_FIELD(t,s16 *,178);}
v=(u32)((M2C_FIELD(lr,u16 *,126)*M2C_FIELD(lr,u16 *,204))<<8)>>16;
func_ov002_021e179c(q,x,y,M2C_FIELD(lr,s16 *,124));
func_ov002_021e17ac(q,v);
off=M2C_FIELD(arg0,u8 *,140)*100;
func_ov002_021e16dc(q,M2C_FIELD(data_ov002_021f3024,s32 *,off),M2C_FIELD(data_ov002_021f3036,u16 *,off),M2C_FIELD(data_ov002_021f3049+off,u8 *,M2C_FIELD(arg0,u8 *,141)*8),0);
}

void func_ov002_021e9f80(void *a, s32 b, s32 c) {
}

void func_ov002_021ea208(void *arg0,s32 arg1) {
void *func_02082028(s32);void func_ov002_021e16bc(void *,u8,u8);void func_ov002_021e16dc(void *,s32,u16,u8,s32);void func_ov002_021e179c(void *,s16,s16,s16);void func_ov002_021e17ac(void *,u32);
extern u8 data_ov002_021ea704[],data_ov002_021f3028[],data_ov002_021f3038[],data_ov002_021f304b[],data_ov002_021f30f4[];
void *p,*q,*lr,*t;u32 v;s32 off;s16 x,y;
if(!M2C_FIELD(data_ov002_021f3028,s32 *,M2C_FIELD(arg0,u8 *,140)*100))return;
if(M2C_FIELD(arg0,void **,84)){
p=func_02082028(8);if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(arg0,void **,84);M2C_FIELD(p,void **,4)=M2C_FIELD(arg0,void **,88);M2C_FIELD(arg0,void **,88)=p;}
M2C_FIELD(arg0,void **,84)=((p=func_02082028(84)) ? init_021ea37c(p):p);
q=M2C_FIELD(arg0,void **,84);
func_ov002_021e16bc(q,M2C_FIELD(arg0,u8 *,140),M2C_FIELD(arg0,u8 *,141));
lr=M2C_FIELD(M2C_FIELD(data_ov002_021f30f4,void **,M2C_FIELD(arg0,u8 *,140)*24),void **,40);
x=M2C_FIELD(lr,s16 *,128);y=M2C_FIELD(lr,s16 *,130);
if(arg1!=-1){t=lr+arg1*4;x+=M2C_FIELD(t,s16 *,176);y+=M2C_FIELD(t,s16 *,178);}
v=(u32)((M2C_FIELD(lr,u16 *,134)*M2C_FIELD(lr,u16 *,204))<<8)>>16;
func_ov002_021e179c(q,x,y,M2C_FIELD(lr,s16 *,132));
func_ov002_021e17ac(q,v);
off=M2C_FIELD(arg0,u8 *,140)*100;
func_ov002_021e16dc(q,M2C_FIELD(data_ov002_021f3028,s32 *,off),M2C_FIELD(data_ov002_021f3038,u16 *,off),M2C_FIELD(data_ov002_021f304b+off,u8 *,M2C_FIELD(arg0,u8 *,141)*8),0);
}

void func_ov002_021ea37c(void *arg0) {
void *func_02082028(s32);void func_ov002_021e16bc(void *,u8,u8);void func_ov002_021e16dc(void *,s32,u16,u8,s32);void func_ov002_021e179c(void *,s16,s16,s16);void func_ov002_021e17ac(void *,u32);
extern u8 data_ov002_021ea704[],data_ov002_021f302c[],data_ov002_021f303a[],data_ov002_021f304c[],data_ov002_021f30f4[];
void *p,*q,*lr;u32 v;s32 off;
if(!M2C_FIELD(data_ov002_021f302c,s32 *,M2C_FIELD(arg0,u8 *,140)*100))return;
if(M2C_FIELD(arg0,void **,84)){
p=func_02082028(8);if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(arg0,void **,84);M2C_FIELD(p,void **,4)=M2C_FIELD(arg0,void **,88);M2C_FIELD(arg0,void **,88)=p;}
M2C_FIELD(arg0,void **,84)=((p=func_02082028(84)) ? init_021ea37c(p):p);
q=M2C_FIELD(arg0,void **,84);
func_ov002_021e16bc(q,M2C_FIELD(arg0,u8 *,140),M2C_FIELD(arg0,u8 *,141));
lr=M2C_FIELD(M2C_FIELD(data_ov002_021f30f4,void **,M2C_FIELD(arg0,u8 *,140)*24),void **,40);
v=(u32)((M2C_FIELD(lr,u16 *,134)*M2C_FIELD(lr,u16 *,204))<<8)>>16;
func_ov002_021e179c(q,M2C_FIELD(lr,s16 *,128),M2C_FIELD(lr,s16 *,130),M2C_FIELD(lr,s16 *,132));
func_ov002_021e17ac(q,v);
off=M2C_FIELD(arg0,u8 *,140)*100;
func_ov002_021e16dc(q,M2C_FIELD(data_ov002_021f302c,s32 *,off),M2C_FIELD(data_ov002_021f303a,u16 *,off),M2C_FIELD(data_ov002_021f304c+off,u8 *,M2C_FIELD(arg0,u8 *,141)*8),0);
}

void func_ov002_021ea4bc(void *arg0, s32 arg1, s32 arg2) {
    void *func_02082028(s32);
    void func_ov002_021e3e0c(void *, s16, s16, s16, u16, u16, u16, u16, u8, u8, u8, u8);
    extern u8 data_ov002_021f30f4[];
    extern u8 data_ov002_021f306e[];
    u8 idx;
    u8 idx2;
    void *p;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u8 e;
    s16 x;
    s16 y;
    s16 z;
    if (M2C_FIELD(arg0, void **, 0x64) != 0) {
        void *tmp = func_02082028(8);
        if (tmp != 0) {
            M2C_FIELD(tmp, s32 *, 0) = 0;
            M2C_FIELD(tmp, s32 *, 4) = 0;
        }
        M2C_FIELD(tmp, void **, 0) = M2C_FIELD(arg0, void **, 0x64);
        M2C_FIELD(tmp, void **, 4) = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(arg0, void **, 0x68) = tmp;
        M2C_FIELD(arg0, void **, 0x64) = func_02082028(0x14);
    }
    idx = M2C_FIELD(arg0, u8 *, 0x8c);
    idx2 = M2C_FIELD(arg0, u8 *, 0x8d);
    p = M2C_FIELD(data_ov002_021f30f4, void **, idx * 0x18);
    p = M2C_FIELD(p, void **, 0x28);
    a = M2C_FIELD(p, u16 *, 0xaa);
    b = M2C_FIELD(p, u16 *, 0xac);
    c = M2C_FIELD(data_ov002_021f306e, u16 *, idx * 0x64 + idx2 * 0x2);
    d = M2C_FIELD(p, u16 *, 0xae);
    e = (idx2 + 1) & 0xff;
    x = (s16)(arg1 + M2C_FIELD(p, s16 *, 0xa4));
    y = (s16)(arg2 + M2C_FIELD(p, s16 *, 0xa6));
    z = M2C_FIELD(p, s16 *, 0xa8);
    func_ov002_021e3e0c(M2C_FIELD(arg0, void **, 0x64), x, y, z, a, b, c, d, e, 0x1f, idx, idx2);
}

void func_ov002_021ea5b8(void) {
    M2C_UNK func_ov002_021e24e8();
    func_ov002_021e24e8();
}

void func_ov002_021ea5c4(void *arg0) {
    void func_ov002_021e99f0(void *,s32);
    void func_ov002_021e9bc0(void *,s32);
    extern u8 data_ov002_021f314e[];
    if (data_ov002_021f314e[M2C_FIELD(arg0,u8 *,0x8C)*0x2C]) {
        func_ov002_021e99f0(arg0,M2C_FIELD(arg0,s32 *,0x84));
        func_ov002_021e9bc0(arg0,M2C_FIELD(arg0,s32 *,0x84));
        M2C_FIELD(arg0,s32 *,0x84)++;
    } else {
        func_ov002_021e99f0(arg0,-1);
        func_ov002_021e9bc0(arg0,-1);
    }
}

s32 func_ov002_021ea628(void *arg0) {
extern u8 data_ov002_021f314e[];
extern u8 data_ov002_021f2f44[];
u8 index = M2C_FIELD(arg0,u8 *,0x8C);
if (data_ov002_021f314e[index*0x2C] != 0 && M2C_FIELD(data_ov002_021f2f44 + index*0x68,u8 *,0x66) <= M2C_FIELD(arg0,s32 *,0x84)) return 1;
return 0;
}

