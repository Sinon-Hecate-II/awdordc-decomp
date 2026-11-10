/* 10 functions from 0x0221D818 to 0x0221E5A0 (ov005), found by ds-decomp. */
#include "common.h"
#define RESULT_ATTR(tile, palette) ((u16)((((tile) >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17) >> 30)) & 1023) | (palette)))

#pragma opt_peephole off
M2C_UNK func_ov005_0221d818(M2C_UNK arg0) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
extern void **gCurrentMap;
extern u8 gSpriteDesc32x16[],data_02101f4c[],gSpriteDesc16x16[],gSpriteDesc8x8[],gSpriteDesc16x32[];
extern u8 data_0215c34a[],data_0215c334[],data_ov005_02220a1c[],data_ov005_02220a24[];
void AddSprite(u16,u16,u16,void *,s32);
void func_02098cb8(s32,s16,s16,u16,s32,s32);
s32 func_020cfb94(void);
void DivMod(s32,s32,s32 *,s32 *);
s32 Modulo(s32,s32);
void *func_020a866c(s32);
s32 func_020d3014(s32,void *);
s32 func_020d3080(s32,void *);
s32 func_020a72b0(s32,void *);
void *saved,*saved2;
s32 y,i,n,d,dx,x,tile,palette,count,oy,ox,ay,mode,score;
s32 loop;
u16 attr;
u32 py;
void *map;
u8 *p,*q;
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
AddSprite(192,M2C_FIELD(arg0,s32 *,0x44)&255,RESULT_ATTR((M2C_FIELD(arg0,s32 *,0x54)<<3)+0x398,0xc000),gSpriteDesc32x16,5);
i=M2C_FIELD(arg0,s32 *,0x50);
y=(169-M2C_FIELD(arg0,s32 *,0x44))&255;
func_02098cb8(0,7,y,RESULT_ATTR(i*24+0x270,(u32)(i<<28)>>16),1,5);
AddSprite(5,(u16)((y&0xff00)|((y+1)&255)),RESULT_ATTR(0x1d8,0x7000),data_02101f4c,6);
for(loop=0;loop<func_020cfb94();loop++){
AddSprite((u16)((79+20*loop)&511),(170-M2C_FIELD(arg0,s32 *,0x44))&255,RESULT_ATTR(0x388+4*loop,(u32)((loop+8)<<28)>>16),gSpriteDesc16x16,8);
}
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=M2C_FIELD(arg0,s32 *,0x44);
gCur3DSpriteEngine=g3DSpriteEngineSub;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x44)=-M2C_FIELD(arg0,s32 *,0x48);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=-M2C_FIELD(arg0,s32 *,0x4c);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x40)=-M2C_FIELD(arg0,s32 *,0x4c);
{s32 number0,digit0;
y=M2C_FIELD(arg0,s32 *,0x48)+54;
if(y>=-8&&y<192){number0=data_0215c34a[(M2C_FIELD(arg0,s32 *,0x50)+1)*12];
ay=y&255;dx=0;
do{DivMod(number0,10,&number0,&digit0);
AddSprite((u16)((208-dx)&511),ay,(u16)((digit0&1023)+((0x140 >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17) >> 30)) & 1023)|0x6000),gSpriteDesc8x8,0);
dx+=8;}while(number0);}}
{s32 number1,digit1;
y=M2C_FIELD(arg0,s32 *,0x48)+70;
if(y>=-8&&y<192){map=*gCurrentMap;
map=(u8 *)map+(M2C_FIELD(arg0,s32 *,0x50)+1)*140;
number1=M2C_FIELD(map,s32 *,0x67a8);
ay=(u16)(y&255);dx=0;
do{DivMod(number1,10,&number1,&digit1);
AddSprite((u16)((208-dx)&511),ay,(u16)((digit1&1023)+((0x140 >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17) >> 30)) & 1023)|0x6000),gSpriteDesc8x8,0);
dx+=8;}while(number1);}}
{s32 number2,digit2;
y=M2C_FIELD(arg0,s32 *,0x48)+86;
if(y>=-8&&y<192){map=*gCurrentMap;
map=(u8 *)map+(M2C_FIELD(arg0,s32 *,0x50)+1)*140;
number2=M2C_FIELD(map,s32 *,0x67b0);
ay=(u16)(y&255);dx=0;
do{DivMod(number2,10,&number2,&digit2);
AddSprite((u16)((208-dx)&511),ay,(u16)((digit2&1023)+((0x140 >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17) >> 30)) & 1023)|0x6000),gSpriteDesc8x8,0);
dx+=8;}while(number2);}}

gCur3DSpriteEngine=saved;
p=data_ov005_02220a1c;
x=0;i=0;oy=96;
if(*p){q=data_ov005_02220a24;tile=0x3ac;
do{
if(!Modulo(i,3)){oy+=32;x=51;}
map=data_0215c334+M2C_FIELD(arg0,s32 *,0x50)*12;
count=M2C_FIELD((u8 *)map+*q,u8 *,26);
y=oy+M2C_FIELD(arg0,s32 *,0x48);
if(y<192){
saved2=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
ay=y&255;ox=x&511;
attr=RESULT_ATTR(tile,0xe000);
if(count>99)count=99;
AddSprite((u16)ox,(u16)((ay&0xff00)|((ay-16)&255)),attr,gSpriteDesc16x32,5);
{ s32 digit,number; number=count;dx=0;
ay=(ay&0xff00)|((ay+4)&255);ox=(ox+39)&511;
do{DivMod(number,10,&number,&digit);
AddSprite((u16)((ox-dx)&511),ay,(u16)(((digit&1023)+((0x140 >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17) >> 30)) & 1023))|0x6000),gSpriteDesc8x8,0);dx+=8;}while(number);
}
gCur3DSpriteEngine=saved2;
}
x+=56;q++;tile+=8;i++;
}while(*++p);}
ox=0;oy=-2;mode=M2C_FIELD(arg0,u8 *,0x58)?0x400:0;
for(i=0;func_020a866c(i);i++,ox+=64){
if(!Modulo(i,4)){oy+=20;ox=8;}
if(M2C_FIELD(arg0,s32 *,0x54)==0)score=func_020d3014(M2C_FIELD(arg0,s32 *,0x50)+1,func_020a866c(i));
else score=func_020d3080(M2C_FIELD(arg0,s32 *,0x50)+1,func_020a866c(i));
if(score){
if(score>99)score=99;
n=M2C_FIELD(arg0,s32 *,0x50);
map=func_020a866c(i);
ay=mode|(oy&255);x=ox&511;
py=(ay&0xff00)|(ay&255);
tile=func_020a72b0(n+1,map)+0x3ac;
AddSprite((u16)x,py,RESULT_ATTR(tile,0xe000),gSpriteDesc16x16,5);
AddSprite((u16)((x+19)&511),(u16)(((ay|(ay&255))&0xff00)|(py&255)),RESULT_ATTR(0x3a8,0xc000),gSpriteDesc16x16,5);
{ s32 digit,number; number=score;dx=0;
do{DivMod(number,10,&number,&digit);
AddSprite((u16)((x+42-dx)&511),(u16)((ay&0xff00)|((ay+5)&255)),(u16)(((digit&1023)+((0x140 >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17) >> 30)) & 1023))|0x6000),gSpriteDesc8x8,0);dx+=8;}while(number);}
}
}
}
#pragma opt_peephole reset
void func_ov005_0221e1b8(void) {
    M2C_UNK ResultsScreenAnimate();
    ResultsScreenAnimate();
}

void func_ov005_0221e1c4(void) {
    M2C_UNK func_ov005_0221cff8();
    func_ov005_0221cff8();
}

void func_ov005_0221e1d0(void) {
    M2C_UNK func_ov005_0221d160();
    func_ov005_0221d160();
}

void func_ov005_0221e1dc(void) {
    M2C_UNK func_01ffaa8c();
    func_01ffaa8c();
}

void func_ov005_0221e1e8(void) {
    M2C_UNK func_ov005_0221d818();
    func_ov005_0221d818();
}

void func_ov005_0221e1f4(M2C_UNK arg0) {
    M2C_UNK func_02086344();
    M2C_UNK func_02095ff8(M2C_UNK);
    M2C_UNK func_ov005_02218fd0(M2C_UNK);
    func_02095ff8(3);
    func_02086344();
    func_ov005_02218fd0(arg0);
}

void func_ov005_0221e214(void) {
    M2C_UNK func_02095fd4();
    M2C_UNK func_02086370();
    func_020ab200();
    func_0209bf7c();
    func_02095fd4();
    func_02086370();
}

#pragma opt_strength_reduction off
/* Creates the results medal sprites on both screens and seeds the surrounding effects. */
void func_ov005_0221e22c(M2C_UNK parent) {
    s32 func_020cd1e4(void);
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    void *func_02090eb8(M2C_UNK *, s32, s32, s32, u16, s32, void *);
    void func_ov005_0221a38c(void *);
    s32 RandomIntRange(s32, s32);
    void func_ov005_02219fa0(s32, s32, s32);
    extern M2C_UNK data_ov005_02220db8, data_ov005_02220f90, data_ov005_02220a4c, data_ov005_02220a78;
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
    extern u16 gMapConfig;
    extern u8 data_0215c334[];
    void *medalDisplay, *savedEngine;
    s32 i, x, y, isOtherMode;

    if (!func_020cd1e4()) return;
    medalDisplay = CreateSpriteObject(&data_ov005_02220db8, parent);
    if (medalDisplay) {
        M2C_FIELD(medalDisplay, void **, 0) = &data_ov005_02220f90;
        M2C_FIELD(medalDisplay, u8 *, 0x44) = 0;
        M2C_FIELD(medalDisplay, u8 *, 0x45) = 0;
        M2C_FIELD(medalDisplay, u8 *, 0x46) = 0;
        M2C_FIELD(medalDisplay, u8 *, 0x47) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x48) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x4a) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x4c) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x4e) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x50) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x52) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x54) = 0;
        M2C_FIELD(medalDisplay, u16 *, 0x56) = 0;
        M2C_FIELD(medalDisplay, s32 *, 0x40) = 0;
        M2C_FIELD(medalDisplay, s32 *, 0x3c) = 432;
        SetFileDirectory(&data_ov005_02220a4c);
        savedEngine = gCur3DSpriteEngine;
        for (i = 0; i < 2; i++) {
            gCur3DSpriteEngine = i == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
            M2C_FIELD(medalDisplay + i * 4, void **, 0x34) = func_02090eb8(&data_ov005_02220a78, 0, 0, 0, (u16)(0xa000 | ((472 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30)) & 1023)), 0, medalDisplay);
        }
        gCur3DSpriteEngine = savedEngine;
        func_ov005_0221a38c(medalDisplay);
    }
    if (((u32)(gMapConfig << 29) >> 29) != 1) isOtherMode = 1;
    else isOtherMode = 0;
    if ((isOtherMode & 255) && data_0215c334[3] != 4) return;
    for (i = 0; i < 8; i++) {
        x = RandomIntRange(-48, -16);
        y = RandomIntRange(288, 352);
        func_ov005_02219fa0(x, y, RandomIntRange(0, 3));
    }
    for (i = 0; i < 16; i++) {
        x = RandomIntRange(-32, 128);
        y = RandomIntRange(400, 432);
        func_ov005_02219fa0(x, y, RandomIntRange(0, 3));
    }
}
/* Initializes ov005's scene state when the system is ready and the global mode is not state 1. */
void func_ov005_0221e468(M2C_UNK arg0) {
    M2C_UNK func_01ff85b8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_01ff9ce8(M2C_UNK);
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02082134(M2C_UNK, M2C_UNK);
    s32 func_020cd1e4();
    s32 GetLocalizedFileName(M2C_UNK *);
    extern u16 gMapConfig;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02220a2c;
    extern M2C_UNK data_ov005_02220a90;
    extern M2C_UNK data_ov005_02220bf0;
    extern M2C_UNK data_ov005_02220e30;
    extern M2C_UNK data_ov005_02220ebc;
    extern M2C_UNK data_ov005_02220f7c;
    s32 flag;
    void *result;
    void *savedPtr;

    if (func_020cd1e4() == 0) {
        return;
    }
    if (((u32) (gMapConfig << 0x1D) >> 0x1D) != 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (!(flag & 0xFF)) {
        return;
    }
    result = CreateSpriteObject(&data_ov005_02220bf0, arg0);
    if (result == NULL) {
        return;
    }
    M2C_FIELD(result, M2C_UNK **, 0) = &data_ov005_02220f7c;
    SetFileDirectory(&data_ov005_02220a2c);
    savedPtr = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_02082134(2, 1);
    func_01ff9ce8(2);
    GetLocalizedFileName(&data_ov005_02220ebc);
    func_020814e4();
    func_02081590(GetLocalizedFileName(&data_ov005_02220a90), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
    func_02081590(GetLocalizedFileName(&data_ov005_02220e30), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
    func_02081528();
    func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 0x800, 0x2000);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    gCur3DSpriteEngine = savedPtr;
    M2C_FIELD(result, s32 *, 0x34) = 0;
    M2C_FIELD(result, s32 *, 0x3C) = 0;
    M2C_FIELD(result, s32 *, 0x40) = 0;
    M2C_FIELD(result, s32 *, 0x44) = 0;
    M2C_FIELD(result, s32 *, 0x38) = -0x100;
}

