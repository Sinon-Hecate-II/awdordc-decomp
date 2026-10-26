/* 32 functions from 0x020B6168 to 0x020B7138 (main), found by ds-decomp. */
#include "common.h"

void func_020b6320(void) {
    M2C_UNK func_020cfd28();
    M2C_UNK func_020b524c();
    func_020b524c();
    func_020cfd28();
}

void func_020b6330(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    void *func_01ffa42c();
    M2C_UNK func_02068c50(void *, M2C_UNK *);
    extern M2C_UNK data_02128cec, data_02128e98;
    void *p;
    p = func_01ffa42c(&data_02128cec, arg4);
    M2C_FIELD(p, s16 *, 0x44) = arg0;
    M2C_FIELD(p, s16 *, 0x46) = arg1;
    M2C_FIELD(p, s16 *, 0x4C) = arg2;
    M2C_FIELD(p, s16 *, 0x4E) = arg3;
    M2C_FIELD(p, s32 *, 0x50) = 0;
    func_02068c50(p + 0x34, &data_02128e98);
    func_0207b774(arg0, arg1);
}

void func_020b638c(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    void *func_01ffa42c();
    M2C_UNK func_02068c50(void *, M2C_UNK *);
    extern M2C_UNK data_02128cec, data_02128ea4;
    void *p;
    p = func_01ffa42c(&data_02128cec, arg4);
    M2C_FIELD(p, s16 *, 0x44) = arg0;
    M2C_FIELD(p, s16 *, 0x46) = arg1;
    M2C_FIELD(p, s16 *, 0x4C) = arg2;
    M2C_FIELD(p, s16 *, 0x4E) = arg3;
    M2C_FIELD(p, s32 *, 0x50) = 0;
    func_02068c50(p + 0x34, &data_02128ea4);
    func_0207b774(arg0, arg1);
}

void func_020b63e8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    void *func_01ffa42c();
    M2C_UNK func_02068c50(void *, M2C_UNK *);
    extern M2C_UNK data_02128cec, data_02128eb0;
    void *p;
    p = func_01ffa42c(&data_02128cec, arg4);
    M2C_FIELD(p, s16 *, 0x44) = arg0;
    M2C_FIELD(p, s16 *, 0x46) = arg1;
    M2C_FIELD(p, s16 *, 0x4C) = arg2;
    M2C_FIELD(p, s16 *, 0x4E) = arg3;
    M2C_FIELD(p, s32 *, 0x50) = 0;
    func_02068c50(p + 0x34, &data_02128eb0);
    func_0207b774(arg0, arg1);
}

void func_020b654c(s32 arg0) {
    void *func_01ffa42c(M2C_UNK *);
    M2C_UNK func_0207b7a4(s32);
    extern M2C_UNK data_02128adc;
    M2C_FIELD(func_01ffa42c(&data_02128adc), s32 *, 0x5C) = arg0;
    func_0207b7a4(arg0);
}

void func_020b6570(void *arg0) {
    s32 func_0207ca38(s32, s32, s32, u16, s32);
    M2C_UNK func_0208c0d0(void *, u8);
    u32 temp_r1;
    u32 upper;
    u16 temp_r7;
    u16 temp_r5;
    s32 temp_r6;
    s32 temp_r5_2;
    temp_r1 = M2C_FIELD(arg0, u32 *, 0x48);
    upper = temp_r1 >> 21;
    temp_r5 = (u16)upper;
    temp_r7 = (u16)((temp_r1 << 11) >> 21);
    temp_r6 = func_0207ca38(4, 31, 0, temp_r5, temp_r7);
    temp_r5_2 = func_0207ca38(4, 0, 0x40000, temp_r5, temp_r7);
    func_0208c0d0(arg0, (u8)temp_r6);
    M2C_FIELD(arg0, s32 *, 0x40) = temp_r5_2;
}

void func_020b65e4(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_r2 - 0x600);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_r2;
}

void func_020b65f8(void *arg0) {
    s32 func_0207ca38(s32, s32, s32, u16, s32);
    M2C_UNK func_020b5134(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    M2C_UNK func_0208c080(void *, s32);
    extern M2C_UNK data_02128ecc;
    u16 count;
    u32 bits;
    void *p;
    bits = M2C_FIELD(arg0, u32 *, 0x48);
    count = (u16)(bits >> 21);
    M2C_FIELD(arg0, s32 *, 0x38) = func_0207ca38(0, M2C_FIELD(arg0, s32 *, 0x58), M2C_FIELD(arg0, s32 *, 0x5C), count, (u16)((bits << 11) >> 21));
    if ((s32)count % 16 != 0) return;
    p = (void *)func_020b5134(&data_02128ecc, 0, 0, 16, 0, 0, arg0);
    func_0208c080(p, 2);
    M2C_FIELD(p, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(p, s32 *, 0x38) = M2C_FIELD(arg0, s32 *, 0x38);
}

void func_020b6698(void *arg0) {
    void *func_020b5188(M2C_UNK *, s16, s16, s32, s32, s32, void *);
    M2C_UNK func_0208c080(void *, s32);
    void func_020b65e4(void *);
    void func_020b65f8(void *);
    extern M2C_UNK data_02128ed4, data_02128edc;
    void *p;
    func_020b51dc();
    func_020b5200(&data_02128ed4, 0);
    p = func_020b5188(&data_02128edc, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46), 16, 0, 0, arg0);
    func_0208c080(p, 1);
    M2C_FIELD(p, void (**)(void *), 0x68) = func_020b65e4;
    M2C_FIELD(p, void (**)(void *), 0x6C) = func_020b65f8;
    func_0208fb0c(0x130, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
}

void func_020b6718(void *arg0) {
    M2C_UNK func_0208c080(void *, M2C_UNK);
    void *func_020b5188(M2C_UNK *, s16, s16, M2C_UNK, s32, s32, void *);
    M2C_UNK func_020cc6a4();
    extern M2C_UNK data_02128ee4;
    extern M2C_UNK data_02128eec;
    void func_020b6570(void *);
    void *temp_r0;

    func_020b51dc();
    func_020b5200(&data_02128ee4, 0);
    temp_r0 = func_020b5188(&data_02128eec, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46), 0x10, 0, 0, arg0);
    func_0208c080(temp_r0, 0);
    M2C_FIELD(temp_r0, void (**)(void *), 0x6C) = func_020b6570;
    func_020cc6a4();
    func_0208fb0c(0x131, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
}

void func_020b6794(void *arg0) {
    M2C_UNK func_020ce434(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    extern void **data_027e0058;
    func_020ce434(M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46), 2, 1, (s32) (u8) M2C_FIELD(*data_027e0058, u16 *, 0x52A4), 2);
    func_020cfd28();
}

void func_020b67e0(s16 arg0, s16 arg1, M2C_UNK arg2) {
    extern M2C_UNK data_02128b8c;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_02128b8c, arg2);
    M2C_FIELD(temp_r0, s16 *, 0x44) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x46) = arg1;
    func_0207b774(arg0, arg1);
}

void func_020b6814(void *arg0) {
s32 func_020b5594(s32,s32,s32);s32 func_020b5e00(s32,s32,void *);s32 func_020b5964(s32,void *);s32 func_020b5d94(s32,void *);
void *p=arg0;
s32 a=M2C_FIELD(arg0,s32 *,0x34);
if(M2C_FIELD(arg0,s16 *,0x6e)>0) {func_020b5594(M2C_FIELD(arg0,s32 *,0x38),M2C_FIELD(arg0,s32 *,0x3c),0 );return;}
switch(M2C_FIELD(arg0,s16 *,0x6c)) {
case 0:break;
case 1:func_020b5e00(M2C_FIELD(arg0,s32 *,0x38),M2C_FIELD(arg0,s32 *,0x3c),arg0);break;
case 2:break;case 3:break;
case 4:func_020b5964(a,arg0);break;
case 5:break;
case 6:case 7:func_020b5d94(a,arg0);break;
default:break;
}
}

s32 func_020b689c(s32 a,s32 b) {
void func_020a488c(s32,s16 *);extern M2C_UNK data_02128abc;
s16 xy[2];s32 p;
func_020a488c(a,xy);p=func_01ffa42c(&data_02128abc,b);
M2C_FIELD(p,s32 *,0x38)=xy[0];M2C_FIELD(p,s32 *,0x3c)=xy[1];
M2C_FIELD(p,s16 *,0x6c)=(u32)(M2C_FIELD(a,u16 *,2)<<22)>>28;
M2C_FIELD(p,s16 *,0x6e)=M2C_FIELD(a,u8 *,4);
M2C_FIELD(p,s32 *,0x34)=a;return p;
}

s32 func_020b68f0(s32 a,s32 b,s32 c) {
extern M2C_UNK data_02128abc;extern void **data_027e0058;
s32 p=func_01ffa42c(&data_02128abc,c);
void *base;
M2C_FIELD(p,s32 *,0x38)=a;M2C_FIELD(p,s32 *,0x3c)=b;
M2C_FIELD(p,s16 *,0x6c)=1;base=*data_027e0058;
M2C_FIELD(p,s16 *,0x6e)=M2C_FIELD(base+(a+M2C_FIELD(base+b*2,u16 *,0x3758)),u8 *,0x539c)&127;
M2C_FIELD(p,s32 *,0x34)=0;return p;
}

s32 func_020b6a9c(s16 start) {
s32 func_0209f8d4(void); void *func_0209f8e4(s32);s32 func_020720f0(s32,s32);
extern void **data_027e0058;
s32 x=0,y=0,n=0,i=start;void *p;u16 id;
for(;i<func_0209f8d4();i++){id=M2C_FIELD(func_0209f8e4(i),u16 *,0);p=*data_027e0058+0x59a4+id*14;x+=M2C_FIELD(p,u8 *,1);y+=M2C_FIELD(p,u8 *,2);n++;}
if(n>0)func_0207b774(func_020720f0(x,n),func_020720f0(y,n));
}

void func_020b6b40(void *arg0) {
s32 func_0208c1ec(void *); s32 func_0208c200(void *);
s32 a; u32 bits=M2C_FIELD(arg0,u32 *,0x48);
u16 count=(u16)(bits>>21);
if(count) return;
a=func_0208c1ec(arg0);
func_0208fb0c(0xfc,a,func_0208c200(arg0));
}

s32 func_020b6b80(void *p) {
s32 func_020b695c(s32,s32,s32);
s32 b=M2C_FIELD(p,s32 *,0x64);
s32 a=M2C_FIELD(p,s32 *,0x58);
if(!b)return a;
func_020b695c(a,b,8);M2C_FIELD(p,s32 *,0x64)=0;return 0;
}

void func_020b6bac(void *arg0) {
s32 func_0209f8d4(void);void *func_0209f8e4(s32);
void *func_020b5188(M2C_UNK *,s16,s16,s32,s32,s32,void *);
extern void **data_027e0058;extern M2C_UNK data_02128efc;
s32 v,n,i;void *p,*q;
i=M2C_FIELD(arg0,s32 *,0x58);v=M2C_FIELD(arg0,s32 *,0x5c);n=0;
for(;i<func_0209f8d4();i++){u16 id=M2C_FIELD(func_0209f8e4(i),u16 *,0);p=*data_027e0058+0x59a4+id*14;
q=func_020b5188(&data_02128efc,M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),16,v,0,arg0);
M2C_FIELD(q,u32 *,0x48)=(M2C_FIELD(q,u32 *,0x48)&~1023)|((u8)n&1023);
M2C_FIELD(q,void (**)(void *),0x6c)=func_020b6b40;n+=8;}
}

void func_020b6e4c(void) {
    M2C_UNK func_020b6b80();
    func_020b6b80();
}

void func_020b6e58(void *arg0) {
    M2C_UNK func_020b51dc();
    func_020b51dc();
    M2C_FIELD(arg0, s16 *, 0x56) = 0;
}

void func_020b6f98(s32 arg0, s32 arg1, s16 arg2, M2C_UNK arg3) {
    M2C_UNK func_020b6a9c(s16);
    extern M2C_UNK data_02128cac;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_02128cac, arg3);
    M2C_FIELD(temp_r0, s32 *, 0x38) = (s32) (arg0 + 1);
    M2C_FIELD(temp_r0, s32 *, 0x3C) = (s32) (arg1 + 1);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg2;
    func_020b6a9c(arg2);
}

void func_020b6fd8(void *arg0) {
    M2C_UNK func_0207b774(s32, s32);
    func_020b51dc();
    func_0207b774(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020b6ff4(void *arg0) {
    M2C_UNK func_0208fb0c(s32, s32, s32);
    M2C_UNK func_020b5134(M2C_UNK *, s32, s32, M2C_UNK, s32, s32, void *);
    extern M2C_UNK data_02128f3c;
    extern M2C_UNK data_02128f48;
    func_020b5134(&data_02128f48, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 0x10, func_020b5200(&data_02128f3c, 0), 0, arg0);
    func_0208fb0c(0x105, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020b7050(void *arg0) {
    M2C_UNK func_0207b7e8(s32);
    extern M2C_UNK data_02128f54;
    extern M2C_UNK data_02128f64;
    s32 temp_r4;

    temp_r4 = func_020b5134(&data_02128f64, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), 0x10, func_020b5200(&data_02128f54, 1), 1, arg0);
    func_0207b774(M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    func_0207b7e8(temp_r4);
}

void func_020b70b0(void *arg0) {
    extern M2C_UNK data_02128f74;
    extern M2C_UNK data_02128f80;
    func_020b5134(&data_02128f80, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), 0x10, func_020b5200(&data_02128f74, 2), 2, arg0);
    func_0208fb0c(0x106, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
}

void func_020b710c(void *arg0) {
    s32 func_020b5200(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020b695c(s32, s32, M2C_UNK);
    extern M2C_UNK data_02128f8c;
    func_020b695c(M2C_FIELD(arg0, s32 *, 0x44), func_020b5200(&data_02128f8c, 8), 8);
}

