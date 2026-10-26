/* 39 functions from 0x020CBACC to 0x020CC9C8 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 kind:6; u8 flags:2; } UnkCBUnit;

typedef struct { u8 unk_0 : 6; u8 unk_6 : 2; } Unk020cbc88;

void func_020cbacc(void *a){extern void **data_027e0058;s32 func_020c98b4(void *);s32 func_020cb550(void *);s32 func_020cb430(void *);s32 func_020cb6a4(void *);M2C_UNK func_01ffa6fc(void *);
u16 i;void *p,*q;u32 k;
if(func_020c98b4(a))return;
for(i=M2C_FIELD(a,u16 *,0x50);i<51;i++){
p=*data_027e0058;q=(u8 *)p+0x59a4+(M2C_FIELD(p,u16 *,0x52a8)+i)*14;
k=((UnkCBUnit *)q)->kind;if(!k)continue;if(M2C_FIELD(q,u16 *,4)&8)continue;
if(k==23||k==21){if(func_020cb550(q)){M2C_FIELD(a,u16 *,0x50)=i+1;break;}}
if(func_020cb430(q)&&func_020cb6a4(q)){M2C_FIELD(a,u16 *,0x50)=i+1;break;}
}if(i==51)func_01ffa6fc(a);
}

void func_020cbbac(void) {
 extern void **data_027e0058;
 void *p;
 void *q;
 if (!func_020d0590(M2C_FIELD(*data_027e0058,u16 *,0x52A4))) return;
 p=*data_027e0058;
 q=(u8 *)p+0x67A4+M2C_FIELD(p,u16 *,0x52A4)*0x8C;
 func_0207b764(M2C_FIELD(q,u8 *,0x2D),M2C_FIELD(q,u8 *,0x2E));
}

void func_020cbc08(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b534;
    func_01ffa3dc(&data_0212b534, 7);
}

void func_020cbc20(void *arg0) {
 extern void **data_027e0058;
 void *p=M2C_FIELD(arg0,void **,0x34);
 s32 n;
 func_020b5594(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),5);
 if (!p) n=0;
 else n=((s32)p-(s32)((u8 *)*data_027e0058+0x59A4))/14;
 func_020a6728(n);
 func_020cfd28();
}

void func_020cbc88(void *arg0) {
 void *func_01ffa42c(M2C_UNK *);
 extern M2C_UNK data_0212b22c;
 if (((Unk020cbc88 *)arg0)->unk_0==0) return;
 if (M2C_FIELD(arg0,u16 *,4)&8) return;
 M2C_FIELD(func_01ffa42c(&data_0212b22c),void **,0x34)=arg0;
}

void func_020cbcc0(void *arg0) {
    M2C_UNK func_0207b784(s32);
    func_0207b784(M2C_FIELD(arg0, s32 *, 0x34));
}

void func_020cbcd0(void *arg0) {
    M2C_UNK func_020b576c(s32);
    func_020b576c(M2C_FIELD(arg0, s32 *, 0x34));
}

void func_020cbce0(s32 arg0) {
    void *func_01ffa42c(M2C_UNK *);
    extern M2C_UNK data_0212b33c;
    M2C_FIELD(func_01ffa42c(&data_0212b33c), s32 *, 0x34) = arg0;
}

void func_020cbcfc(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
}

void func_020cbd08(void *a) {
extern void **data_027e0058;
s32 func_020a5b2c(void *);M2C_UNK func_01ffa6fc(void *);
while(M2C_FIELD(a,s16 *,0x6c)<51) {
void *p=(u8 *)*data_027e0058+0x59a4;
s32 n=(M2C_FIELD(a,s16 *,0x6c)+M2C_FIELD(*data_027e0058,u16 *,0x52a8))*14;
if((((UnkCBUnit *)((u8 *)p+n))->kind)&&func_020a5b2c((u8 *)p+n)) {((void (*)(void *,void *))func_020cbce0)((u8 *)p+n,a);return;}
M2C_FIELD(a,s16 *,0x6c)++;
}
if(M2C_FIELD(a,s16 *,0x6c)>=51)func_01ffa6fc(a);
}

void func_020cbda4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b25c;
    func_01ffa3dc(&data_0212b25c, 7);
}

void func_020cbdbc(void) {
extern void **data_027e0058;
void func_020d8804(void);void *p;
p=*data_027e0058;
M2C_FIELD(p,u16 *,0x52e6)=(M2C_FIELD(p,u16 *,0x52e6)&~0x1fc)|((u32)(M2C_FIELD(p,u16 *,0x52c2)<<25)>>23);
p=*data_027e0058;
M2C_FIELD(p,u16 *,0x52e6)=(M2C_FIELD(p,u16 *,0x52e6)&~0xfe00)|((u32)(M2C_FIELD(p,u16 *,0x52c4)<<25)>>16);
M2C_FIELD(*data_027e0058,u16 *,0x52e4)=0;
M2C_FIELD(*data_027e0058,u16 *,0x52e6)&=~3;
func_020d8804();
}

void func_020cbf94(M2C_UNK arg0) {
    M2C_UNK func_020cbe44(M2C_UNK, M2C_UNK);
    func_020cbe44(arg0, 0);
}

void func_020cbfa4(M2C_UNK arg0) {
    M2C_UNK func_020cbe44(M2C_UNK, M2C_UNK);
    func_020cbe44(arg0, 1);
}

void func_020cbfb4(void) {
    M2C_UNK func_02086720(s32);
    s32 func_020cd6d4();
    if (func_020cd6d4() != 0) {
        func_02086720(0xC000032F);
        return;
    }
    func_02086720(0xC0000328);
}

void func_020cbfe4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b5f4;
    func_01ffa3dc(&data_0212b5f4, 7);
}

void func_020cbffc(void) {
 extern void **data_027e0058;
 func_020d31f0(M2C_FIELD(*data_027e0058,u16 *,0x52A4),1);
 func_020ca484();
}

void func_020cc028(void) {
    M2C_UNK func_02096c7c(u16, M2C_UNK);
    extern void **data_027e0058;
    func_02096c7c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), 8);
}

void func_020cc050(void) {
extern void **data_027e0058;
func_020d31f0(M2C_FIELD(*data_027e0058,u16 *,0x52a4),1);
func_ov000_02199f50(17,0,0,0);
}

void func_020cc08c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b4ec;
    func_01ffa3dc(&data_0212b4ec, 7);
}

void func_020cc430(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020cf80c();
    extern u16 *data_02101e84;
    func_020cf80c();
    func_0207a7a4(1, 8);
    if (func_020d4dd0() != 0) {
        if (!(*data_02101e84 & 0xB)) {
            return;
        }
        func_0208fe30(0x10018);
        func_01ffa6fc(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x3A) = 1;
}

void func_020cc490(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020c127c();
    M2C_UNK func_020cfd28();
    extern void *gCur3DSpriteEngine;
    func_020cfd28();
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    func_01ff9ce8(3);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    func_020c127c();
    M2C_FIELD(arg0, s16 *, 0x34) = 6;
}

void func_020cc504(void *a) {
extern void *gCur3DSpriteEngine;M2C_UNK func_01ffa6fc(void *);
u16 *volatile p; s32 n;
M2C_FIELD(a,s16 *,0x34)--;
n=M2C_FIELD(a,s16 *,0x34);
p=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12);
*p=(*p&~0xc0)|0xc0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=n;
if(!M2C_FIELD(a,s16 *,0x34))func_01ffa6fc(a);
}

void func_020cc584(void *a) {
extern void **data_027e0058;
u32 func_0207d0b8(void);u32 func_0207d0d4(void);
void *p;
if(M2C_FIELD(a,s16 *,0x3a)) {
p=(u8 *)*data_027e0058+0x5120;
M2C_FIELD(*data_027e0058,u16 *,0x52c2)=(func_0207d0b8()>>1)+(M2C_FIELD(p,s16 *,0x28)>>4);
p=(u8 *)*data_027e0058+0x5120;
M2C_FIELD(*data_027e0058,u16 *,0x52c4)=(func_0207d0d4()>>1)+(M2C_FIELD(p,s16 *,0x2a)>>4);
func_020cbdbc();
}
func_02082770();func_020c0a88();
M2C_FIELD(*data_027e0058,u16 *,0x52b4)=0;
}

void func_020cc62c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b664;
    func_01ffa3dc(&data_0212b664, 7);
}

void func_020cc644(void *arg0) {
    M2C_UNK func_020cf674(s16, s16, M2C_UNK);
    func_020cf674((s16) (M2C_FIELD(arg0, s32 *, 0x38) * 0x10), (s16) (M2C_FIELD(arg0, s32 *, 0x3C) * 0x10), 2);
}

void func_020cc66c(s32 a,s32 b) {
extern M2C_UNK data_0212b1dc;s32 func_01ffa770(M2C_UNK *);M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);void *p;
if(func_01ffa770(&data_0212b1dc))return;
p=(void *)func_01ffa3dc(&data_0212b1dc,7);
M2C_FIELD(p,s32 *,0x38)=a;M2C_FIELD(p,s32 *,0x3c)=b;
}

void func_020cc6a4(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_0212b1dc;
    func_01ffa9e4(&data_0212b1dc);
}

void func_020cc7e0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b294;
    func_01ffa3dc(&data_0212b294, 7);
}

s32 func_020cc7f8(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_0211f8fc;
    extern M2C_UNK data_0211f984;
    if ((func_01ffa770(&data_0211f984) != 0) || (func_01ffa770(&data_0211f8fc) != 0)) {
        return 1;
    }
    return 0;
}

void func_020cc834(void) {
    M2C_UNK func_0207a768();
    func_0207a768();
}

void func_020cc840(void *a) {
extern void **data_027e0058;
void *p,*q; s32 x,y;
func_01ffb554((u8 *)*data_027e0058+0x1e30);func_01ffb3d0(-1);
p=*data_027e0058;
func_020cdfec(M2C_FIELD(p,s32 *,0x52d0),M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de));
func_0207a748(0);
p=*data_027e0058;
q=(u8 *)p+0x5000;
x=M2C_FIELD(p,volatile s16 *,0x52dc);y=M2C_FIELD(p,volatile s16 *,0x52de);
M2C_FIELD(a,s16 *,0x6c)=func_020ba320(M2C_FIELD(q,volatile s32 *,0x2d0),x,y);
M2C_FIELD(a,s16 *,0x6e)=3;
M2C_FIELD(a,s16 *,0x6e)=func_020cac1c(3,M2C_FIELD(a,s16 *,0x6c));
}

void func_020cc8d8(void *arg0) {
    M2C_UNK func_020cad1c(s32 *, M2C_UNK);
    M2C_UNK func_01ffa574(void *);
    void func_020d472c(void);
    void func_020c75cc(void);
    M2C_UNK func_020bbcec(s32);
    M2C_UNK func_01ffa6fc(void *);
    extern void **data_027e0058;
    s32 sp0;
    s32 ret;
    s32 tmp;

    tmp = M2C_FIELD(arg0, s16 *, 0x6c);
    sp0 = M2C_FIELD(arg0, s16 *, 0x6e);
    ret = func_020cad1c(&sp0, tmp);
    M2C_FIELD(arg0, s16 *, 0x6e) = (s16)sp0;
    if (ret & 0x20) {
        func_01ffa574(arg0);
        func_020d472c();
        func_020c75cc();
        M2C_FIELD(*data_027e0058, s16 *, 0x52c2) = M2C_FIELD(*data_027e0058, s16 *, 0x52d8);
        M2C_FIELD(*data_027e0058, s16 *, 0x52c4) = M2C_FIELD(*data_027e0058, s16 *, 0x52da);
        return;
    }
    if (ret & 0x10) {
        func_020bbcec(M2C_FIELD(arg0, s16 *, 0x6e));
        func_01ffa6fc(arg0);
    }
}

void func_020cc974(void) {
void func_020d468c(void);void func_020d472c(void);void func_020bac24(void);extern void **data_027e0058;
func_020d468c();func_020d472c();M2C_FIELD(*data_027e0058,u16 *,0x52b4)=0;func_020bac24();
}

s32 func_020cc9a4(void) {
    M2C_UNK func_0207a7a4(M2C_UNK, M2C_UNK);
    s32 func_020d4dd0();
    if (func_020d4dd0() != 0) {
        return 0;
    }
    func_0207a7a4(0, 4);
    return 1;
}

