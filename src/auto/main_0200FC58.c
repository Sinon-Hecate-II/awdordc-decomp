/* 28 functions from 0x0200FC58 to 0x02010C14 (main), found by ds-decomp. */
#include "common.h"


void func_0200fc58(void) {
    extern void *data_0212fde0;
    extern void *data_0212fd80;
    void func_02007e98(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020067e0(void *, u32);
    void func_02008048(void *, void *, u32);
    void func_02005ac0(void *, void *, s32, u8 *, u32, s32);
    void func_02005e5c(void *);
    void func_02009e40(s32, void *);
    void func_0200fd90(s32);
    void func_02010cc4(void);
    void func_02010c90(s32, s32, s32);
    extern u32 data_02130400[];

    void *p = &data_0212fde0;

    *(s32 *)((u8 *)p + 8) = -3;
    *(s32 *)((u8 *)p + 0xC) = 0;
    *(s32 *)((u8 *)p + 0x18) = 0;
    *(void **)((u8 *)p) = &data_0212fd80;

    func_02007e98(0, &data_0212fd80, 0x60);
    func_020067e0(&data_0212fd80, 0x60);

    *(s32 *)((u8 *)p + 0x118) = -1;
    *(s32 *)((u8 *)p + 0x11C) = -1;

    {
        u16 v = *(volatile u16 *)0x27ffc40;
        s32 n = (v == 2) ? 1 : 0;
        if (n == 0) {
            func_02008048((void *)0x27ffe00, (void *)0x27ffa80, 0x160);
            *(s32 *)((u8 *)p + 0x108) = 4;
            *(s32 *)((u8 *)p + 0x14) = 0;
            *(s32 *)((u8 *)p + 0x10) = 0;
            *(s32 *)((u8 *)p + 0x110) = 0;
            *(s32 *)((u8 *)p + 0x10C) = 0;
            func_02005ac0((u8 *)p + 0x44, (void *)func_02010cc4, 0,
                          (u8 *)data_02130400, 0x400, 4);
            func_02005e5c((u8 *)p + 0x44);
        }
    }

    func_02009e40(0xB, (void *)func_02010c90);

    {
        u16 v = *(volatile u16 *)0x27ffc40;
        s32 n = (v == 2) ? 1 : 0;
        if (n != 0) {
            return;
        }
    }
    func_0200fd90(1);
}

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

void func_0200fe94(s32 arg0) { (void)arg0; }

s32 func_0201033c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    extern void *data_0212fde0;
    extern M2C_UNK data_0212dca4;
    void func_02000b9c(s32);
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02005da4(void *);
    void func_0200fb0c(void *);
    void func_02010164(void *);
    void *p = &data_0212fde0;
    s32 state;
    u32 oldf;
    u32 nf;
    s32 a4;
    s32 a6, a7, a8, a5;

    func_02000b9c(0x2000bc4);
    state = func_0200751c();
    while (M2C_FIELD(p, u32 *, 0x114) & 0x4) {
        func_02005da4((u8 *)p + 0x10c);
    }
    oldf = M2C_FIELD(p, u32 *, 0x114);
    a4 = arg4;
    a6 = arg6;
    a7 = arg7;
    a8 = arg8;
    a5 = arg5;
    nf = oldf | 0x4;
    M2C_FIELD(p, u32 *, 0x114) = nf;
    M2C_FIELD(p, s32 *, 0x38) = arg3;
    M2C_FIELD(p, s32 *, 0x3c) = a4;
    func_02007530(state);
    M2C_FIELD(p, s32 *, 0x1c) = arg0;
    M2C_FIELD(p, s32 *, 0x20) = arg1;
    M2C_FIELD(p, s32 *, 0x24) = arg2;
    M2C_FIELD(p, s32 *, 0x2c) = a6;
    M2C_FIELD(p, s32 *, 0x30) = a7;
    M2C_FIELD(p, s32 *, 0x34) = a8;
    if (a5 != 0) {
        func_0200fb0c((void *)func_02010164);
        return 1;
    }
    M2C_FIELD(&data_0212fde0, u32 *, 0x104) = M2C_FIELD(&data_0212dca4, u32 *, 0x4);
    func_02010164(p);
    return *M2C_FIELD(p, s32 **, 0) == 0;
}

s32 func_02010424(void) {
    extern void *data_0212fde0;
    return M2C_FIELD(data_0212fde0, s32 *, 4);
}

s32 func_02010438(void) {
    extern void *data_0212fde0;
    return M2C_FIELD(data_0212fde0, s32 *, 0x1C);
}

s32 func_0201044c(s32 arg0) {
extern void *data_0212fde0;extern M2C_UNK data_0212dca4;
void func_02000b9c(s32);s32 func_0200751c(void);void func_02007530(s32);void func_02005da4(void *);void func_02005df4(void *);void func_02005e5c(void *);void func_0200fe94(s32);s32 func_02010d14(void *,s32,s32);M2C_UNK func_02007958();
void *p=&data_0212fde0; s32 state,state2;s32 value;void (*callback)(s32);
func_02000b9c(0x2000bc4);
if(arg0==0)func_02007958();
func_0200fd78();
state=func_0200751c();
while(M2C_FIELD(p,u32 *,0x114)&4)func_02005da4(p+0x10c);
M2C_FIELD(p,u32 *,0x114)|=4;
M2C_FIELD(p,s32 *,0x38)=0;M2C_FIELD(p,s32 *,0x3c)=0;
func_02007530(state);
func_0200fe94(arg0);
M2C_FIELD(&data_0212fde0,s32 *,0x104)=M2C_FIELD(&data_0212dca4,s32 *,4);
func_02010d14(p,2,1);
M2C_FIELD(*(void **)p,s32 *,0xc)=0;
M2C_FIELD(*(void **)p,void **,0x10)=p+0x120;
M2C_FIELD(*(void **)p,s32 *,0x14)=1;
func_02010d14(p,6,1);
callback=M2C_FIELD(p,void (**)(s32),0x38);value=M2C_FIELD(p,s32 *,0x3c);
state2=func_0200751c();
M2C_FIELD(p,u32 *,0x114)&=~0x4c;
func_02005df4(p+0x10c);
if(M2C_FIELD(p,u32 *,0x114)&0x10)func_02005e5c(p+0x44);
func_02007530(state2);
if(callback)callback(value);
return **(s32 **)p==0;
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

void func_020106dc(void) {
    s32 func_02007ca4(s32);
    void func_020051f8(s32);
    void func_02005228(s32);
    s32 func_02010a28(void);
    void func_02010f84(s32);
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02005df4(void *);
    void func_02005e5c(void *);
    void func_02010688(void);
    extern void *data_0212fde0;
    s32 a;
    s32 c;
    s32 b;
    s32 flag;
    s32 r;
    s32 r5;
    s32 r6;
    s32 state;
    s32 *q;
    s32 *p;

    func_02007ca4(M2C_FIELD(&data_0212fde0, s32 *, 0x28));
    q = (s32 *)&data_0212fde0;
    a = M2C_FIELD(q, s32 *, 0x24);
    b = M2C_FIELD(q, s32 *, 0x1c) + 0x200;
    c = M2C_FIELD(q, s32 *, 0x20) + 0x200;
    a = a - 0x200;
    M2C_FIELD(q, s32 *, 0x24) = a;
    if (a != 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    M2C_FIELD(q, s32 *, 0x1c) = b;
    M2C_FIELD(q, s32 *, 0x20) = c;
    if (flag) goto fail;
    func_020051f8(0x80000);
    func_02005228(0x80000);
    p = (s32 *)&data_0212fde0;
    r = func_02010a28();
    func_02010f84(r);
    M2C_FIELD(M2C_FIELD(p, s32 **, 0), s32 *, 0) = 0;
    r5 = M2C_FIELD(p, s32 *, 0x38);
    r6 = M2C_FIELD(p, s32 *, 0x3c);
    state = func_0200751c();
    M2C_FIELD(p, u32 *, 0x114) = M2C_FIELD(p, u32 *, 0x114) & ~0x4c;
    func_02005df4((u8 *)p + 0x10c);
    if (M2C_FIELD(p, u32 *, 0x114) & 0x10) {
        func_02005e5c((u8 *)p + 0x44);
    }
    func_02007530(state);
    if (r5 != 0) {
        ((void (*)(s32))r5)(r6);
    }
    return;
fail:
    func_02010688();
}

s32 func_020107ac(void *arg0) {
    extern void *data_0212fde0;
    void *p = &data_0212fde0;
    s32 r6 = 0;
    s32 r9 = *(s32 *)((u8 *)p + 0x20);
    void *r11 = arg0;
    s32 r7 = 0;
    s32 r8 = 0;
    s32 r1 = 0;
    s32 r10 = r9 & 0x1f;
    s32 r5 = *(s32 *)((u8 *)p + 0x24);
    s32 r0;
    
    if (r10 == 0) {
        r0 = *(s32 *)((u8 *)p + 0x28);
        if (r0 <= 3) {
            r1 = 1;
        }
        if (r1 != 0) {
            s32 func_02006c8c(void);
            func_02006c8c();
            // ...
        }
    }
    return r6;
}

void func_02010938(void *arg0) {
    extern void *data_0212fde0;
    void func_02010628(u32, u32);
    s32 func_0201059c(void *);

    void *p;
    u32 aligned_src;
    void *dst_buf;
    u32 word_counter;
    u32 byte_counter;
    u32 ctrl_val;
    u32 data;

    p = &data_0212fde0;
    aligned_src = M2C_FIELD(p, u32 *, 0x1c) & ~0x1FF;
    if (aligned_src != M2C_FIELD(p, u32 *, 0x1c)) goto fail;

    if (M2C_FIELD(p, u32 *, 0x20) & 3) goto fail;

    if (M2C_FIELD(p, u32 *, 0x24) >= 0x200) goto fail;

    M2C_FIELD(arg0, u32 *, 0x8) = aligned_src;
    dst_buf = (u8 *)arg0 + 0x20;

    func_02010628((aligned_src >> 8) | 0xB7000000, aligned_src << 24);

    word_counter = 0;
    byte_counter = 0;
    *(volatile u32 *)0x040001A4 = M2C_FIELD(arg0, u32 *, 0x4);
    ctrl_val = *(volatile u32 *)0x040001A4;

    if ((ctrl_val & 0x800000) == 0) goto skip_copy;
    data = *(volatile u32 *)0x04100010;
    if (byte_counter < 0x200) {
        *(u32 *)((u8 *)dst_buf + word_counter * 4) = data;
        byte_counter += 4;
        word_counter += 1;
    }

skip_copy:
    if (ctrl_val & 0x80000000) goto fail;

    if (dst_buf != (void *)M2C_FIELD(p, u32 *, 0x20)) goto fail;

    p = &data_0212fde0;
    M2C_FIELD(p, u32 *, 0x1c) = M2C_FIELD(p, u32 *, 0x1c) + 0x200;
    M2C_FIELD(p, u32 *, 0x20) = M2C_FIELD(p, u32 *, 0x20) + 0x200;
    M2C_FIELD(p, u32 *, 0x24) = M2C_FIELD(p, u32 *, 0x24) - 0x200;

    if (M2C_FIELD(p, u32 *, 0x24) == 0) return;
    goto fail;

fail:
    while (func_0201059c(arg0) != 0) { }
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

void func_02010b1c(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, s32 arg6) {
    extern u32 data_02130420[];
    extern void *data_0212fde0;
    extern u32 data_02130400[];
    extern M2C_UNK data_0212dca4;
    void func_0200fd78(void);
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02005da4(void *);
    s32 func_02007ca4(s32);
    s32 func_020107ac(void *);
    void func_02010c78(void);
    void func_0200fb0c(void *);
    void func_02010a84(void);

    void *r4 = data_02130420;
    void *r5 = &data_0212fde0;
    u32 r10 = arg0;
    s32 r9 = arg1;
    s32 r8 = arg2;
    s32 r7 = arg3;
    s32 state;
    s32 r;

    func_0200fd78();
    state = func_0200751c();
    goto test;
loop:
    func_02005da4((u8 *)r5 + 0x10c);
test:
    if (M2C_FIELD(r5, volatile u32 *, 0x114) & 4) goto loop;
    {
        u32 _f = M2C_FIELD(r5, u32 *, 0x114);
        s32 _a4 = arg4;
        void *_a5 = arg5;
        M2C_FIELD(r5, u32 *, 0x114) = _f | 4;
        M2C_FIELD(r5, s32 *, 0x38) = _a4;
        M2C_FIELD(r5, void **, 0x3c) = _a5;
    }
    func_02007530(state);
    {
        u32 *_lit = data_02130400;
        M2C_FIELD(r5, u32 *, 0x28) = r10;
        M2C_FIELD(r5, u32 *, 0x20) = r8;
        M2C_FIELD(r5, u32 *, 0x1c) = r9 + _lit[0];
        M2C_FIELD(r5, u32 *, 0x24) = r7;
    }
    if (r10 <= 3) {
        func_02007ca4(r10);
    }
    r = func_020107ac(r4);
    if (r != 0) {
        if (arg6 != 0) {
            return;
        }
        func_02010c78();
        return;
    }
    if (arg6 != 0) {
        func_0200fb0c((void *)func_02010a84);
        return;
    }
    M2C_FIELD(r5, u32 *, 0x104) = M2C_FIELD(&data_0212dca4, u32 *, 4);
    func_02010a84();
}

