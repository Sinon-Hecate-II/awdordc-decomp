/* 28 functions from 0x0200FC58 to 0x02010C14 (main), found by ds-decomp. */
#include "common.h"


s32 func_0200fd68(void) {
    extern s32 data_0212fd60;
    return data_0212fd60;
}

void func_0200fd78(void) {
    M2C_UNK func_02007958();
    if (func_0200fd68() != 0) {
        return;
    }
    func_02007958();
}

void func_0200fd90(s32 arg0) {
    extern s32 data_0212fd60;
    data_0212fd60 = arg0;
}

s32 func_0200fda0(void) {
 extern void *data_0212fde0;
 s32 func_0200751c(void); void func_02007530(s32); void func_02005da4(void *);
 void *p = &data_0212fde0;
 s32 state = func_0200751c();
 goto test;
 loop: func_02005da4((u8 *)p + 0x10c);
 test: if (M2C_FIELD(p, u32 *, 0x114) & 4) goto loop;
 func_02007530(state);
 return *M2C_FIELD(p, s32 **, 0) == 0;
}

s32 func_0200fdec(void) {
 extern void *data_0212fde0;
 return (M2C_FIELD(&data_0212fde0, u32 *, 0x114) & 4) == 0;
}

s32 func_0200fe08(void) {
 extern void *data_0212fde0;
 return M2C_FIELD(&data_0212fde0,u32 *,0x114) != 0;
}

void func_0200fe24(M2C_UNK arg0) {
    M2C_UNK func_0200551c(M2C_UNK);
    func_0200fb48(arg0, 1);
    func_0200551c(arg0);
}

void func_0200fe40(M2C_UNK arg0) {
    M2C_UNK func_02005538();
    M2C_UNK func_0200fbcc(M2C_UNK, M2C_UNK);
    func_02005538();
    func_0200fbcc(arg0, 1);
}

void func_0200fe5c(M2C_UNK arg0) {
    M2C_UNK func_0200fb48(M2C_UNK, M2C_UNK);
    func_0200fb48(arg0, 2);
}

void func_0200fe6c(M2C_UNK arg0) {
 s32 func_02010590(void); void func_02010584(void);
 M2C_UNK func_0200fbcc(M2C_UNK, M2C_UNK);
 if (func_02010590() == 0) { func_02010584(); }
 func_0200fbcc(arg0, 2);
}

s32 func_02010424(void) {
    extern void *data_0212fde0;
    return M2C_FIELD(data_0212fde0, s32 *, 4);
}

s32 func_02010438(void) {
    extern void *data_0212fde0;
    return M2C_FIELD(data_0212fde0, s32 *, 0x1C);
}

void func_02010584(void) {
    M2C_UNK func_0200fda0();
    func_0200fda0();
}

s32 func_02010590(void) {
    M2C_UNK func_0200fdec();
    return func_0200fdec();
}

s32 func_0201059c(void *arg0) {
 extern void *data_0212fde0;
 void func_02008048(void *, void *, u32);
 void *p = &data_0212fde0;
 u32 base = M2C_FIELD(p, volatile u32 *, 0x1c) & ~0x1ff;
 if (base == M2C_FIELD(arg0, u32 *, 8)) {
  u32 offset = M2C_FIELD(p, volatile u32 *, 0x1c) - base;
  u32 size = 0x200 - offset;
  u32 a,b,c;
  if (size > M2C_FIELD(p, u32 *, 0x24)) size = M2C_FIELD(p, u32 *, 0x24);
  func_02008048((u8 *)arg0 + 0x20 + offset, M2C_FIELD(p, void **, 0x20), size);
  a=M2C_FIELD(p,volatile u32 *,0x1c)+size; b=M2C_FIELD(p,volatile u32 *,0x20)+size; c=M2C_FIELD(p,volatile u32 *,0x24)-size;
  M2C_FIELD(p,volatile u32 *,0x1c)=a; M2C_FIELD(p,volatile u32 *,0x20)=b; M2C_FIELD(p,volatile u32 *,0x24)=c;
 }
 return M2C_FIELD(p, u32 *, 0x24) != 0;
}

void func_02010628(u32 arg0,u32 arg1) {
 volatile u8 *p=(volatile u8 *)0x040001A1;
 while (*(volatile u32 *)0x040001A4 & 0x80000000) {}
 p[0]=0xC0;
 p[7]=arg0>>24; p[8]=arg0>>16; p[9]=arg0>>8; p[10]=arg0;
 p[11]=arg1>>24; p[12]=arg1>>16; p[13]=arg1>>8; p[14]=arg1;
}

void func_02010688(void) {
 extern void *data_0212fde0;
 extern u32 data_02130420[];
 void func_02008538(u32,void *,u32,u32);
 u32 *p=(u32 *)&data_0212fde0;
 u32 *q=data_02130420;
 func_02008538(p[10],(void *)0x04100010,p[8],512);
 func_02010628((p[7]>>8)|0xB7000000,p[7]<<24);
 { u32 value=q[1]; *(u32 *)0x040001A4=value; }
}

s32 func_02010a28(void) {
 extern void *data_020f553c;
 func_02010628(0xB8000000,0);
 *(volatile u32 *)0x040001A4=((M2C_FIELD(data_020f553c,u32 *,0x60)&~0x07000000)|0xA7000000)&~0x1FFF;
 while (!(*(volatile u32 *)0x040001A4 & 0x800000)) {}
 return *(volatile s32 *)0x04100010;
}

void func_02010a84(void) {
    s32 func_0201059c(void *);
    s32 func_02010a28(void);
    void func_02010f84(s32);
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02005df4(void *);
    void func_02005e5c(void *);
    extern u32 data_02130420[];
    extern void *data_0212fde0;

    void *p0 = &data_02130420[0];
    s32 r;
    void *p1;
    s32 r5, r6;
    s32 state;

    r = func_0201059c(p0);
    if (r != 0) {
        void (*fp)(void *) = M2C_FIELD(p0, void (**)(void *), 0);
        fp(p0);
    }
    p1 = &data_0212fde0;
    r = func_02010a28();
    func_02010f84(r);
    M2C_FIELD(M2C_FIELD(p1, s32 **, 0), s32 *, 0) = 0;
    r5 = M2C_FIELD(p1, s32 *, 0x38);
    r6 = M2C_FIELD(p1, s32 *, 0x3c);
    state = func_0200751c();
    M2C_FIELD(p1, u32 *, 0x114) = M2C_FIELD(p1, u32 *, 0x114) & ~0x4c;
    func_02005df4((u8 *)p1 + 0x10c);
    if (M2C_FIELD(p1, u32 *, 0x114) & 0x10) {
        func_02005e5c((u8 *)p1 + 0x44);
    }
    func_02007530(state);
    if (r5 != 0) {
        ((void (*)(s32))r5)(r6);
    }
}

