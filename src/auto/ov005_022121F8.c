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

void func_ov005_02212944(s32 arg0,s32 arg1) {
 M2C_UNK func_ov005_022122e0(s32,s32);
 M2C_UNK func_ov005_02212624(s32,s32);
 M2C_UNK func_ov005_022127b4(s32,s32);
 extern void *data_ov005_02221300;
 switch(M2C_FIELD(data_ov005_02221300,s8 *,1)) {
 case 0: func_ov005_022122e0(arg0,arg1); return;
 case 1: func_ov005_02212624(arg0,arg1); return;
 case 2: func_ov005_022127b4(arg0,arg1); return;
 }
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
    M2C_UNK func_ov005_0221298c(s16);
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
