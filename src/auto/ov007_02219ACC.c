/* 13 functions from 0x02219ACC to 0x0221A59C (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_02219acc(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
    func_0208fe30(0x10020);
}

void func_ov007_02219ae8(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s16 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s16, s32);
    void *func_ov007_02219430();
    void *temp_r4;

    temp_r4 = func_ov007_02219430();
    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (M2C_FIELD(arg0, s16 *, 0x54) + 1);
    M2C_FIELD(temp_r4, s16 *, 0x3E) = func_0207ca38(4, 0x100, 0, M2C_FIELD(arg0, s16 *, 0x54), 4);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x54) < 4) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov007_02219b38(void *arg0) {
M2C_UNK func_ov007_0221863c(void *);
void *p=func_ov007_02219430();
M2C_FIELD(p+M2C_FIELD(p,u8 *,0x37),u8 *,0x38)=M2C_FIELD(arg0,s32 *,0x5c);
func_ov007_0221863c(p);
M2C_FIELD(arg0,s16 *,0x54)=0;
}

void func_ov007_02219b64(void *arg0) {
    void *temp_r4;

    temp_r4 = func_ov007_02219430();
    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (M2C_FIELD(arg0, s16 *, 0x54) + 1);
    M2C_FIELD(temp_r4, s16 *, 0x3E) = func_0207ca38(4, 0, 0x100, M2C_FIELD(arg0, s16 *, 0x54), 4);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x54) < 4) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov007_02219bb4(M2C_UNK arg0, s32 arg1) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221fe48;
    M2C_FIELD(func_01ffa42c(&data_ov007_0221fe48, arg0), s32 *, 0x5C) = arg1;
}

void func_ov007_02219bd8(void) {
extern s32 gCur3DSpriteEngine,data_027e00c4;
void *func_ov000_0216ce84(s32);
void func_01ff9e44(void *,s32,s32);
s32 func_ov007_0221216c(s32);
void func_020ae528(void *);
s32 old=gCur3DSpriteEngine;
s32 i,offset;
gCur3DSpriteEngine=data_027e00c4;
for(i=0;i<4;i++){
offset=(i+0x15)<<5;
func_01ff9e44(func_ov000_0216ce84(i+1),offset,0x20);
if(!func_ov007_0221216c(i+1))
func_020ae528(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x30)+(offset&~1));
}
gCur3DSpriteEngine=old;
}

void func_ov007_02219c58(s32 a,s32 b,s32 c,s32 d) {
extern s32 gCur3DSpriteEngine;
void func_020809c0(void *,s32,s32);
void func_0209c048(s16,s16,void *,s32,s32,s32);
void func_020808dc(void *,s32,s32,u16);
s32 tile=c+4;
func_020809c0(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x20)+a*2+(b+1)*64,2,2);
if(d>0) {
func_0209c048(a+1,b+1,M2C_FIELD(gCur3DSpriteEngine,void **,0x20),d,0x1000,0);
tile+=5;
}
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+a*2+b*64,2,3,(u16)tile);
}

#pragma opt_strength_reduction off
void func_ov007_02219d10(void){
 extern s32 gCur3DSpriteEngine,data_027e00c4;
 s32 func_ov007_0221202c(s32,s32);u8 func_ov007_02211f00(void);
 void func_020808dc(void *,s32,s32,u16);
 s32 old,i,y;
 old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
 i=0;y=2;do{
 if(i==0)func_ov007_02219c58(17,y,i,func_ov007_0221202c(8,i));
 else func_ov007_02219c58(17,y,i,func_ov007_0221202c(0,i));
 func_ov007_02219c58(19,y,i,func_ov007_0221202c(1,i));
 func_ov007_02219c58(21,y,i,func_ov007_0221202c(2,i));
 func_ov007_02219c58(23,y,i,func_ov007_0221202c(3,i));
 func_ov007_02219c58(25,y,i,func_ov007_0221202c(4,i));
 func_ov007_02219c58(27,y,i,func_ov007_0221202c(7,i));
 func_ov007_02219c58(29,y,i,func_ov007_0221202c(9,i));
 y+=3;i++;
 }while(i<5);
 switch(func_ov007_02211f00()){
 case 0:
 func_020808dc(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x480,8,4,3);
 func_020808dc(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x490,8,4,2);
 break;
 case 1:
 func_020808dc(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x480,8,4,2);
 func_020808dc(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x490,8,4,3);
 break;
 }
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
 gCur3DSpriteEngine=old;
}
void func_ov007_02219f4c(void) {
    u8 func_ov007_02211f90(void);
    u8 func_ov007_02211fa0(void);
    s32 func_ov000_0216cda4(s32);
    void *func_ov000_0216cdcc(s32);
    void *func_ov000_0216cdec(s32, s32);
    void func_0207c3dc(s32, s32, s32, s32);
    void func_01ff9e44(void *, s32, s32);
    void func_020ae528(void *);
    u8 func_ov007_02211f00(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    u8 temp_r7;
    u8 temp_r4a;
    s32 temp_r5;
    void *temp_r6ptr;
    void *temp_r4ptr;
    s32 old;

    temp_r7 = func_ov007_02211f90();
    temp_r4a = func_ov007_02211fa0();
    temp_r5 = func_ov000_0216cda4(temp_r7);
    temp_r6ptr = func_ov000_0216cdcc(temp_r7);
    temp_r4ptr = func_ov000_0216cdec(temp_r7, temp_r4a);
    old = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_0207c3dc((s32)temp_r6ptr, M2C_FIELD(data_027e00c4, s32 *, 0x1C) + 0x2D80, 0x100, 0);
    func_0207c3dc(temp_r5, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2F80, 0x200, 0);
    func_01ff9e44(temp_r4ptr, 0x340, 0x20);
    if (func_ov007_02211f00() != 0) {
        func_020ae528((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x340));
    }
    gCur3DSpriteEngine = old;
}

void func_ov007_0221a018(void) {
    /* Prepare the tile graphics and schedule DMA transfers into the back buffer bank. */
    u8 func_ov007_02211f30(void);
    u8 func_ov007_02211f40(void);
    s32 func_ov000_0216cd4c(s32);
    void *func_ov000_0216cd78(s32, s32);
    void *func_ov000_0216cd90(s32);
    void func_0207c3dc(s32, s32, s32, s32);
    void func_01ff9e44(void *, s32, s32);
    void func_020ae528(void *);
    u8 func_ov007_02211f00(void);
    extern void *gCurrentMap;
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    u8 tileGroup;
    u8 slot;
    u8 tileAttr;
    s32 baseAddr;
    void *srcPtr;
    void *dstPtr;
    s32 savedBank;

    tileGroup = func_ov007_02211f30();
    slot = func_ov007_02211f40();
    tileAttr = (u8) M2C_FIELD((M2C_FIELD(gCurrentMap, s32 *, 0) + slot * 0x8C + 0x6000), u8 *, 0x7CD);
    baseAddr = func_ov000_0216cd4c(tileGroup);
    srcPtr = func_ov000_0216cd78(tileGroup, tileAttr);
    dstPtr = func_ov000_0216cd90(slot);
    savedBank = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_0207c3dc((s32)srcPtr, M2C_FIELD(data_027e00c4, s32 *, 0x1C) + 0x2D00, 0x80, 0);
    func_0207c3dc(baseAddr, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2E80, 0x100, 0);
    func_01ff9e44(dstPtr, 0x320, 0x20);
    if (func_ov007_02211f00() != 1) {
        func_020ae528((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x320));
    }
    gCur3DSpriteEngine = savedBank;
}

void func_ov007_0221a104(void) {
extern s32 gCur3DSpriteEngine,data_027e00c4;
extern void *gCurrentMap;
extern s32 data_ov007_02221e08;
s32 func_0209b5e4(void *,void *);
s32 old=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c4;
data_ov007_02221e08=func_0209b5e4(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x1c)+0x3980,M2C_FIELD(gCurrentMap,u8 **,0)+0x5120);
gCur3DSpriteEngine=old;
}

void func_ov007_0221a160(void) {
    M2C_UNK func_01ff9ce8(s32);
    M2C_UNK func_020822b8(M2C_UNK *);
    M2C_UNK func_0200bc5c(void);
    M2C_UNK *func_020e3218(M2C_UNK *);
    void func_020814e4(M2C_UNK);
    M2C_UNK func_02081590(M2C_UNK, M2C_UNK);
    void func_0208116c(M2C_UNK, s32, s32);
    s32 func_01ff9c34(s32);
    void func_01ff85b8(M2C_UNK, u16, s32);
    void func_020c1230(M2C_UNK, M2C_UNK);
    void func_020af04c(s32, s32, s32);
    void func_02099450(s32, s32, s32);
    void func_02091d4c(s32);
    void func_020a9a30(s32, s32, s32, M2C_UNK);
    M2C_UNK func_ov000_0216ce10(s32);
    void func_02007ef4(M2C_UNK, M2C_UNK, s32);
    void func_020c1a9c(s32, s32);
    void func_020ae528(void *);
    void func_ov007_0221ab68(void);

    extern u16 data_ov007_0221f508[];
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern M2C_UNK data_ov007_022200e4;
    extern M2C_UNK data_ov007_022200f0;
    extern M2C_UNK data_ov007_022200fc;
    extern M2C_UNK data_ov007_02220108;
    extern M2C_UNK data_ov007_02220114;
    extern M2C_UNK data_ov007_02220120;
    extern M2C_UNK data_ov007_02220130;
    extern M2C_UNK data_ov007_02220140;
    extern M2C_UNK data_ov007_0222014c;
    extern M2C_UNK data_ov007_02220158;
    extern M2C_UNK data_ov007_02220164;
    extern M2C_UNK data_ov007_02220170;

    s32 savedEngine;
    u16 arr[6];
    u8 i;
    s32 base;

    arr[0] = data_ov007_0221f508[0];
    arr[1] = data_ov007_0221f508[1];
    arr[2] = data_ov007_0221f508[2];
    arr[3] = data_ov007_0221f508[3];
    arr[4] = data_ov007_0221f508[4];
    arr[5] = data_ov007_0221f508[5];

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;

    func_01ff9ce8(0);
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    func_01ff9ce8(3);

    *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) &= ~7;
    func_020822b8(arr);

    *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) |= 0x10;
    *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) |= 0x20;
    *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) |= 0x40;
    *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) |= 0x80;
    *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) |= 0x100;

    func_0200bc5c();

    func_020814e4(func_020e3218(&data_ov007_022200e4));

    func_02081590(func_020e3218(&data_ov007_022200f0), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10));

    func_02081590(func_020e3218(&data_ov007_022200fc), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));

    func_02081528();

    func_0208116c(&data_ov007_02220108, 0x40, 0x180);

    {
        u16 w = *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        s32 sh = func_01ff9c34(w & 7);
        func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), (u16)sh, 0x2000);
    }

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x3A) = 2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x42) = 0;
    func_020c1230(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));

    func_020af04c(3, 0xF, 6);
    func_02099450(0, 0, 1);
    func_02091d4c(1);

    func_020a9a30(1, 0, 2, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2800);
    func_020a9a30(1, 0, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2980);
    func_020a9a30(1, 2, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x260);

    base = 0x158;
    for (i = 0; i < 4; i++) {
        M2C_UNK ret = func_ov000_0216ce10(i + 1);
        func_02007ef4(ret, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + ((base + i * 4) << 5), 0x80);
    }

    func_020c1a9c(0x80, 1);

    func_0200bc5c();

    func_0208116c(&data_ov007_02220120, 0x360, 0x20);
    func_0208116c(&data_ov007_02220130, 0x380, 0x20);

    func_020ae528((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x380));

    func_0200bc5c();

    func_020814e4(func_020e3218(&data_ov007_0222014c));

    func_02081590(func_020e3218(&data_ov007_02220158), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3180);

    func_02081590(func_020e3218(&data_ov007_02220164), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3580);

    func_02081528();

    func_0208116c(&data_ov007_02220170, 0x3A0, 0x20);

    func_02091d4c(0x1E);

    gCur3DSpriteEngine = savedEngine;

    func_ov007_0221ab68();
}

void func_ov007_0221a568(void) {
    M2C_UNK func_020af1e4();
    M2C_UNK func_020c127c();
    extern s32 data_027e00c4;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020c127c();
    func_020af1e4();
    gCur3DSpriteEngine = temp_r4;
}

