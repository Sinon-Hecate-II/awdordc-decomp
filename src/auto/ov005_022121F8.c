/* 13 functions from 0x022121F8 to 0x022131F8 (ov005), found by ds-decomp. */
#include "common.h"

s16 func_ov005_022121f8(void) {
 s16 *func_ov005_02211a38(s8);
 extern void *data_ov005_02221300;
 s16 old;
 s32 limit;
 void *p;
 p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
 old=M2C_FIELD(p,s16 *,2);
 M2C_FIELD(p,s16 *,2)=old+7;
 limit=M2C_FIELD(p,s16 *,8)-7;
 if(M2C_FIELD(p,s16 *,2)>limit) M2C_FIELD(p,s16 *,2)=limit;
 return M2C_FIELD(p,s16 *,2)-old;
}

void func_ov005_02212244(s32 arg0,s32 arg1) {
 M2C_UNK func_02080860(s32,s32,s32,u16,s32);
 extern void *data_027e00c8;
 extern void *gCur3DSpriteEngine;
 void *saved;
 s32 i, x;
 s32 tile;
 saved=gCur3DSpriteEngine;
 gCur3DSpriteEngine=data_027e00c8;
 i=0;
 x=0x18;
 do {
 if(i<arg1) tile=0xC4; else tile=0xC8;
 func_02080860(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24)+x*2+((arg0<<5)*2),2,2,(u16)tile,2);
 i++;
 x+=2;
 }while(i<3);
 gCur3DSpriteEngine=saved;
}

M2C_UNK func_ov005_022122e0(s32 arg0, s32 arg1) {
    void *func_ov000_0216a38c(M2C_UNK);
    u32 func_ov000_0216a3a8(M2C_UNK, M2C_UNK);
    s32 func_ov000_0216a414(M2C_UNK, M2C_UNK);
    s32 func_ov005_02211a54(M2C_UNK, M2C_UNK);
    M2C_UNK func_0209b26c(M2C_UNK, s16, M2C_UNK, s32, s32, s32);
    M2C_UNK func_0209b2dc(M2C_UNK, s16, M2C_UNK, M2C_UNK, s32, s32, s32);
    M2C_UNK func_0209b3e8(M2C_UNK, s16, M2C_UNK, u32, s32, s32);
    M2C_UNK func_0209b2b4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov005_02212244(s32, s32);
    void func_020675e4(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    extern void *data_ov005_02220274;
    extern M2C_UNK data_ov005_02220278[];
    extern M2C_UNK data_ov005_02220280[];
    extern M2C_UNK data_ov005_02220284[];
    void *p;
    u32 money;
    s32 status;
    s32 y;
    void *saved;
    M2C_UNK buf[4];
    M2C_UNK lo[4];

    p = func_ov000_0216a38c(0);
    money = func_ov000_0216a3a8(0, arg1);
    status = func_ov000_0216a414(0, arg1);
    y = (arg0 + 1) * 0x2E + 0x144;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    if (func_ov005_02211a54(0, arg1) == 0) {
        func_0209b26c(2, (s16)(arg0 + 5), 1, M2C_FIELD(p, s32 *, 0), 0x1000, (u16)y);
        if (M2C_FIELD(p, u16 *, 0x4) == 0) {
            func_0209b3e8(0x10, (s16)(arg0 + 5), 1, M2C_FIELD(data_ov005_02220274, s32 *, 0x4), 0x1000, (u16)(y + 0x1E));
            func_0209b2b4(0x11, (s16)(arg0 + 5), 1, (M2C_UNK)data_ov005_02220278, 0x1000, (u16)(y + 0x24));
            func_020675e4((M2C_UNK)buf, (M2C_UNK)data_ov005_02220284, M2C_FIELD(data_ov005_02220274, s32 *, 0xC));
            lo[0] = buf[0];
            lo[1] = buf[1];
            lo[2] = 0;
            lo[3] = 0;
            func_0209b2b4(0x12, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[2], 0x1000, (u16)(y + 0x26));
            func_0209b2b4(0x13, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[0], 0x1000, (u16)(y + 0x28));
            func_0209b2b4(0x14, (s16)(arg0 + 5), 1, (M2C_UNK)data_ov005_02220280, 0x1000, (u16)(y + 0x2A));
            func_020675e4((M2C_UNK)buf, (M2C_UNK)data_ov005_02220284, M2C_FIELD(data_ov005_02220274, s32 *, 0xC));
            func_0209b2b4(0x15, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[2], 0x1000, (u16)(y + 0x2C));
            func_0209b2b4(0x16, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[0], 0x1000, (u16)(y + 0x2E));
        } else {
            if (money > 0x5F5E0FFU) money = 0x5F5E0FF;
            func_0209b3e8(0x16, (s16)(arg0 + 5), 1, money, 0x1000, (u16)(y + 0x1E));
        }
    } else {
        if (money > 0x5F5E0FFU) money = 0x5F5E0FF;
        func_0209b3e8(0x16, (s16)(arg0 + 5), 1, money, 0x1000, (u16)(y + 0x1E));
    }
    func_ov005_02212244(arg0 + 5, status);
    gCur3DSpriteEngine = saved;
    return 0;
}

void func_ov005_02212624(s32 arg0,M2C_UNK arg1) {
M2C_UNK func_02080860(s32,s32,s32,u16,s32);
M2C_UNK func_0209b26c(M2C_UNK,s16,M2C_UNK,s32,s32,s32);
M2C_UNK func_0209b2dc(M2C_UNK,s16,M2C_UNK,M2C_UNK,s32,s32,s32);
M2C_UNK func_0209b3e8(M2C_UNK,s16,M2C_UNK,u32,s32,s32);
s32 func_020a7298(u16,M2C_UNK);
void *func_ov000_0216a38c(M2C_UNK);
u32 func_ov000_0216a3a8(M2C_UNK,M2C_UNK);
s32 func_ov000_0216a414(M2C_UNK,M2C_UNK);
s32 func_ov005_02211a54(M2C_UNK,M2C_UNK);
extern void *data_027e00c8,*gCur3DSpriteEngine;
void *p;u32 money;u32 t,y;void *saved;
p=func_ov000_0216a38c(1);money=func_ov000_0216a3a8(1,arg1);t=func_ov000_0216a414(1,arg1);
y=(arg0+1)*46+0x144;saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
if(func_ov005_02211a54(1,arg1)==0){
func_02080860(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24)+4+((arg0+5)<<6),2,2,(u16)(func_020a7298(M2C_FIELD(p,u16 *,4),0)*4+0xcc),3);
func_0209b26c(4,(s16)(arg0+5),1,M2C_FIELD(p,s32 *,0),0x1000,(u16)y);
if(money>0x5f5e0ffU)money=0x5f5e0ff;
func_0209b3e8(22,(s16)(arg0+5),1,money,0x1000,(u16)(y+30));
}else func_0209b2dc(2,(s16)(arg0+5),1,0x45000000,0x1000,3,(u16)y);
func_ov005_02212244(arg0+5,t);gCur3DSpriteEngine=saved;
}

#pragma opt_common_subs off
void func_ov005_022127b4(s32 arg0,s32 arg1){
M2C_UNK func_02080860(s32,s32,s32,u16,s32);
M2C_UNK func_0209b26c(s32,s16,s32,s32,s32,s32);
M2C_UNK func_0209b2dc(s32,s16,s32,s32,s32,s32,s32);
M2C_UNK func_0209b3e8(s32,s16,s32,u32,s32,s32);
s32 func_020a7298(u16,s32);
void *func_ov000_0216a38c(s32);
u32 func_ov000_0216a3a8(s32,s32);s32 func_ov000_0216a414(s32,s32);s32 func_ov005_02211a54(s32,s32);
extern void *gCur3DSpriteEngine,*data_027e00c8;
void *p;u32 value;s32 status;u32 position;void *saved;
p=func_ov000_0216a38c(2);value=func_ov000_0216a3a8(2,arg1);status=func_ov000_0216a414(2,arg1);
position=(arg0+1)*46+0x144;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
if(!func_ov005_02211a54(2,arg1)){
func_02080860(M2C_FIELD(gCur3DSpriteEngine,s32 *,36)+4+((arg0+5)<<6),2,2,(u16)(func_020a7298(M2C_FIELD(p,u16 *,4),1)*4+0xcc),6);
func_0209b26c(4,(s16)(arg0+5),1,M2C_FIELD(p,s32 *,0),4096,(u16)position);
if(value>99999999U)value=99999999;
func_0209b3e8(22,(s16)(arg0+5),1,value,4096,(u16)(position+30));
}else func_0209b2dc(2,(s16)(arg0+5),1,0x45000000,4096,3,(u16)position);
func_ov005_02212244(arg0+5,status);gCur3DSpriteEngine=saved;
}
#pragma opt_common_subs reset
void func_ov005_02212944(s32 arg0,s32 arg1) {
 M2C_UNK func_ov005_022122e0(s32,s32);
 void func_ov005_02212624(s32,s32);
 void func_ov005_022127b4(s32,s32);
 extern void *data_ov005_02221300;
 switch(M2C_FIELD(data_ov005_02221300,s8 *,1)) {
 case 0: func_ov005_022122e0(arg0,arg1); return;
 case 1: func_ov005_02212624(arg0,arg1); return;
 case 2: func_ov005_022127b4(arg0,arg1); return;
 }
}

int func_ov005_0221298c(s16 arg0) {
s16 *func_ov005_02211a38(s8);
void func_ov005_02212944(s32,s32);
void func_020809c0(void *,s32,s32);
void func_0209c048(s32,s16,void *,s32,s32,s32);
void func_0209c024(s32,s16,void *,s32,s32,s32);
s32 func_020a8b78(void);
extern void *data_ov005_02221300;
extern void *gCur3DSpriteEngine,*data_027e00c8;
s16 *p;
void *saved;
s32 a,b,c,d,e,f;
p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
func_020809c0((u8 *)M2C_FIELD(data_027e00c8,void **,0x24)+0x140,0x20,0xe);
if(arg0&1){
a=0;
b=arg0>>1;
c=-1;
do{func_ov005_02212944(c,b);a++;b++;c+=2;}while(a<8);
func_020809c0((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x100,0x20,1);
func_020809c0((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x4c0,0x20,1);
}else{
d=0;
e=0;
f=arg0>>1;
do{func_ov005_02212944(e,f);d++;f++;e+=2;}while(d<7);
func_020809c0((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0xf4,6,2);
}
func_0209c048(0x1b,3,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),M2C_FIELD(p,s16 *,6),0x1000,0);
func_0209c024(0x1c,3,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b78(),0x1000,0);
func_0209c048(0x1e,3,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),M2C_FIELD(p,s16 *,8),0x1000,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved;
}

void func_ov005_02212b40(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void)arg0;(void)arg1;(void)arg2;(void)arg3;
}

void func_ov005_02212db8(void) {
 M2C_UNK func_0200bc5c(M2C_UNK *);
 M2C_UNK func_020814e4();
 M2C_UNK func_02081528();
 M2C_UNK func_020816cc(s32,s32,s32,s32);
 s32 func_020e3218(M2C_UNK *);
 extern void *data_027e00c8;
 extern void *gCur3DSpriteEngine;
 extern M2C_UNK data_ov005_022202ac, data_ov005_022202bc, data_ov005_022202cc;
 func_0200bc5c(&data_ov005_022202ac);
 func_020e3218(&data_ov005_022202bc);
 func_020814e4();
 func_020816cc(func_020e3218(&data_ov005_022202cc),M2C_FIELD(data_027e00c8,s32 *,0x28),0,0);
 func_02081528();
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 4;
}

void func_ov005_02212e20(void) {
 M2C_UNK func_0200bc5c(M2C_UNK *);
 M2C_UNK func_020814e4();
 M2C_UNK func_02081528();
 M2C_UNK func_020816cc(s32,s32,s32,s32);
 s32 func_020e3218(M2C_UNK *);
 extern void *data_027e00c8;
 extern void *gCur3DSpriteEngine;
 extern M2C_UNK data_ov005_022202e0, data_ov005_022202f0, data_ov005_02220300;
 func_0200bc5c(&data_ov005_022202e0);
 func_020e3218(&data_ov005_022202f0);
 func_020814e4();
 func_020816cc(func_020e3218(&data_ov005_02220300),M2C_FIELD(data_027e00c8,s32 *,0x28),0,0);
 func_02081528();
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 4;
}

void func_ov005_02212e88(void) {
 M2C_UNK func_0200bc5c(M2C_UNK *);
 M2C_UNK func_020814e4();
 M2C_UNK func_02081528();
 M2C_UNK func_020816cc(s32,s32,s32,s32);
 s32 func_020e3218(M2C_UNK *);
 extern void *data_027e00c8;
 extern void *gCur3DSpriteEngine;
 extern M2C_UNK data_ov005_02220314, data_ov005_02220324, data_ov005_02220334;
 func_0200bc5c(&data_ov005_02220314);
 func_020e3218(&data_ov005_02220324);
 func_020814e4();
 func_020816cc(func_020e3218(&data_ov005_02220334),M2C_FIELD(data_027e00c8,s32 *,0x28),0,0);
 func_02081528();
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 4;
}

void func_ov005_02212ef0(void) {
    s16 *func_ov005_02211a38(s8);
    M2C_UNK func_ov005_02211a8c();
    int func_ov005_0221298c(s16);
    void func_ov005_02212db8();
    void func_ov005_02212e20();
    void func_ov005_02212e88();
    extern void *data_ov005_02221300;
    s8 temp_r0;

    temp_r0 = M2C_FIELD(data_ov005_02221300, s8 *, 1);
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_ov005_02212db8();
        break;
    case 1:
        func_ov005_02212e20();
        break;
    case 2:
        func_ov005_02212e88();
        break;
    }
    func_ov005_0221298c(*func_ov005_02211a38(M2C_FIELD(data_ov005_02221300, s8 *, 1)));
    func_ov005_02211a8c();
}

void func_ov005_02212f54(void) {
    return;
}

