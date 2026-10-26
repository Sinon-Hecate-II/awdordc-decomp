/* 30 functions from 0x020C7CD0 to 0x020C8CBC (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad0[0xa10]; u16 tiles[0x508]; u8 cells[0x2338]; u16 rows[0xcf6]; u16 width,height; } Map8484;
typedef union {u32 word; struct {u32 low:10;u32 kind:5;u32 gap:3;u32 mode:4;u32 high:10;} bits;} PackedEntry;

s32 func_020c7e58(s32 arg0) {
    extern M2C_UNK data_02164d64;
    return (0x54 * arg0) + (s32) &data_02164d64;
}

s32 func_020c7e6c(a)
s32 a;
{
 extern M2C_UNK data_02164d64;
 return (s32)&data_02164d64+0x54*func_020c8018(a);
}

s32 func_020c7e88(a)
s32 a; {
    s32 func_020c7e6c();
    return func_020c7e6c() + 0x40;
}

s32 func_020c7e98(void) {
    return func_020c7e6c() + 0x30;
}

s32 func_020c7ea8(a)
s32 a; {
    return func_020c8018() + 9;
}

u8 func_020c7eb8(s32 arg0) {
    u8 var_r0;

    if ((arg0 < 0xE1) || (arg0 >= 0x1A9)) {
        return 0U;
    }
    if (func_020c8020() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020c7ef4(s32 a) {
 s32 x;
 if(a<0xE1||a>=0x1A9)return 0;
 x=func_020c8020(a);
 if(x==0||x==255)return 0;
 return 1;
}

u8 func_020c7f30(s32 a) {
 s32 func_020c80a4(s32); s32 func_02086960(s32);
 s32 p;
 if(a<0xE1||a>=0x1A9)return 0;
 if(!func_020c7eb8(a))return 0;
 if(!func_020c7ef4(a))return 0;
 if(!func_020c80a4(a))return 0;
 if(!func_02086960(a))return 0;
 p=func_020c7e6c(a);
 if(M2C_FIELD(p,u8 *,4)>10)return 0;
 if(M2C_FIELD(p,u8 *,5)>10)return 0;
 return M2C_FIELD(p,u8 *,0x2F)<=50;
}

s32 func_020c7fe4(M2C_UNK arg0) {
    s32 func_02086680(s32);
    s32 func_020c8020(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_020c7e6c();
    if (func_020c8020(arg0) != 0) {
        return temp_r4 + 6;
    }
    return func_02086680(0xC00002EC);
}

s32 func_020c8018(s32 arg0) {
    return arg0 - 0xE1;
}

s32 func_020c8020(s32 a) {
 s32 p=func_020c7e6c(a); s32 r;
 if(M2C_FIELD(p,u32 *,0)!=0x20070731)return 0;
 if(M2C_FIELD(p,u8 *,6)==0)r=0;
 else r=M2C_FIELD(p,u8 *,0x27);
 return r;
}

s32 func_020c8054(s32 arg0) {
    s32 func_020bee64(M2C_UNK);
    u16 *func_020bfa60(M2C_UNK);
    u16 *temp_r0;

    if (func_020bee64(8) != 0) {
        temp_r0 = func_020bfa60(8);
        if ((arg0 >= 0xE1) && (arg0 < 0x1A9) && (arg0 == *temp_r0)) {
            return 1;
        }
    }
    return 0;
}

s32 func_020c80a4(s32 a) {
 s32 func_020c8c6c(s32);
 if(a<0xe1||a>=0x1a9)return 0;
 if(!func_020c7eb8(a))return 0;
 return func_020c8c6c(func_020c7e88(a));
}

u8 func_020c80ec(s32 a) {
 s32 func_02086980(s32);
 s32 p,q; u8 r;
 if(a>=0xe1&&a<0x1a9) {
 p=func_020c7e88(a);q=func_020c8018(a);
 if(!func_020c7eb8(a))return 0;
 if(func_020c80a4(a))return 0;
 if(func_02086980(q))return 0;
 if(M2C_FIELD(p,u32 *,0xc)>>29)return 0;
 if(M2C_FIELD(p,s32 *,0x10))r=1;else r=0;
 return r;
 }return 0;
}

s32 func_020c818c(s32 a,s32 b) {
 s32 func_020c79ec(); s32 func_020c7a14(); s32 func_020c85c4(s32,s32); void func_020868ac(s32,s32);
 s32 q,p,t;
 if(a<0xe1||a>=0x1a9)return 0;
 q=func_020c8018(a);p=func_020c79ec();t=func_020c7a14();
 if(!func_020c85c4(a,p))return 0;
 M2C_FIELD(t,u32 *,0xc)=(M2C_FIELD(t,u32 *,0xc)&~0xe0000000)|(b<<29);
 func_020868ac(q,1);
 return func_020c8624(a,p);
}

s32 func_020c8214(void *p){extern M2C_UNK data_ov000_021b5bfc;s32 i;PackedEntry *q;for(i=0;i<M2C_FIELD(p,u8 *,0x2f);i++){q=(PackedEntry *)((u8 *)p+0x3d8)+i;if(M2C_FIELD((u8 *)&data_ov000_021b5bfc+q->bits.kind*112,u8 *,108)){switch(q->bits.mode){case 0:case 1:q->bits.mode=0;break;case 6:q->bits.mode=6;break;case 8:q->bits.mode=8;break;}}}}

void func_020c83f4(u8 *p){extern void **data_027e0058;void func_02068c50(void *,void *);void func_020a231c(s32,s32);s32 i;u8 *base;func_02068c50((u8 *)*data_027e0058+0x5120,p+6);M2C_FIELD(*data_027e0058,u8 *,0x5141)=p[0x27];for(i=0;i<5;i++)func_020a231c(i,p[0x28+i]);base=(u8 *)*data_027e0058;M2C_FIELD(base,u16 *,0x5144)=p[4];base=(u8 *)*data_027e0058;M2C_FIELD(base,u16 *,0x5146)=p[5];}

s32 func_020c8484(s32 arg) {
extern void **data_027e0058;
void func_020ceffc(void); u16 func_0207f460(u32);
s32 x,y; Map8484 *base; u8 *a=(u8 *)arg;
func_020ceffc();
base=*data_027e0058;
for(y=0;y<base->height;y++) {
for(x=0;x<base->width;x++) {
u8 v;
base->cells[base->rows[y]+x]=(v=*a++);
base=*data_027e0058;
base->tiles[x+base->rows[y]]=func_0207f460(v);
base=*data_027e0058;
}
}
return (s32)base;
}

void func_020c854c(s32 arg0) {
    void func_020c83f4();
    M2C_UNK func_020c8484(s32);
    func_020c83f4();
    func_020c8484(arg0 + 0x54);
}

void func_020c8564(M2C_UNK arg0) {
    M2C_UNK func_020c8214();
    M2C_UNK func_020c82cc(M2C_UNK);
    func_020c8214();
    func_020c82cc(arg0);
}

s32 func_020c857c(M2C_UNK arg0) {
    s32 func_020c79ec();
    s32 func_020c85c4(M2C_UNK, s32);
    M2C_UNK func_020cf2c8();
    M2C_UNK func_020cfd28();
    s32 temp_r0;

    temp_r0 = func_020c79ec();
    if (func_020c85c4(arg0, temp_r0) == 0) {
        return 0;
    }
    func_020c854c(temp_r0);
    func_020c82cc(temp_r0);
    func_020cf2c8();
    func_020cfd28();
    return 1;
}

s32 func_020c85c4(s32 a,s32 b){u8 func_020c8664(s32,s32);void func_02007e98(s32,s32,s32);s32 func_020be324(s32,s32);s32 p=func_020c7ea8(a);u8 r;func_02007e98(0,b,0x6f8);if(!func_020be324(p,b))return 0;if(func_020c8664(a,b))r=1;else r=0;return r;}

s32 func_020c8624(s32 a,s32 b) {
 s32 func_020c7a3c(s32); void func_020be438(s32,s32,s32);
 s32 p=func_020c7ea8(a);
 if(!func_020c7a3c(b))return 0;
 func_020be438(p,b,0x6f8);return 1;
}

u8 func_020c8664(s32 a,s32 b){s32 func_020c7a3c(s32);s32 func_020c8b0c(s32,s32);s32 p=func_020c7e6c(a);u8 r;if(!func_020c7a3c(b))return 0;if(func_020c8b0c(b,p))r=1;else r=0;return r;}

void func_020c86a8(void *p) {
s32 func_020c7a24(); s32 func_0200f0ac(); void func_02007724(void *);
extern u32 data_027e15bc;
s32 date[4],time[3];s32 v=func_020c7a24(p);
func_0200f0ac(date,time);func_02007724((u8 *)p+64);
M2C_FIELD(p,u32 *,76)=(M2C_FIELD(p,u32 *,76)&0xfffc003f)|((data_027e15bc<<20)>>14);
M2C_FIELD(p,u16 *,70)=v;
M2C_FIELD(p,u32 *,72)=(M2C_FIELD(p,u32 *,72)&~0xff)|(u8)date[0];
M2C_FIELD(p,u32 *,72)=(M2C_FIELD(p,u32 *,72)&~0x3f00)|((u32)(date[1]<<26)>>18);
M2C_FIELD(p,u32 *,72)=(M2C_FIELD(p,u32 *,72)&~0xfc000)|((u32)(date[2]<<26)>>12);
M2C_FIELD(p,u32 *,72)=(M2C_FIELD(p,u32 *,72)&~0x3f00000)|((u32)(time[0]<<26)>>6);
M2C_FIELD(p,u32 *,72)=(M2C_FIELD(p,u32 *,72)&~0xfc000000)|(time[1]<<26);
M2C_FIELD(p,u32 *,76)=(M2C_FIELD(p,u32 *,76)&~0x3f)|(time[2]&0x3f);
M2C_FIELD(p,u32 *,76)&=0xf003ffff;
M2C_FIELD(p,u32 *,76)&=~0x10000000;
M2C_FIELD(p,u32 *,76)&=~0xe0000000;
M2C_FIELD(p,u32 *,80)=0;
}

s32 func_020c8c6c(s32 a) {
 void func_02007724(void *);
 u8 buf[6]; s32 i;
 func_02007724(buf);
 for(i=0;i<6;i++) {
 if(buf[i]!=*(u8 *)(a+i))return 0;
 }
 return 1;
}

