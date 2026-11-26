/* 17 functions from 0x01FF8F90 to 0x01FF9ED0 (itcm), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
static inline void SetSubWindow9690(volatile u16 *h, volatile u16 *v, s32 left, s32 right, s32 top, s32 bottom) { *h=((left<<8)&0xff00)|top; *v=((right<<8)&0xff00)|bottom; }
static inline void SetSubScroll9690(volatile u32 *reg, s32 x, s32 y) { s32 mask=0x1ff; *reg=(x&mask)|((mask<<16)&(y<<16)); }

#pragma push
#pragma opt_strength_reduction off
s32 func_01ff8f90(s32 arg0, s32 arg1, u16 *arg2) {
    s32 sp0;
    s32 var_ip;
    u16 temp_r3;
    s32 xMask = 0x1FF;

    if (arg2 != NULL) {
        temp_r3 = *arg2++;
        sp0 = (s32) temp_r3;
        for (var_ip = 0; var_ip < sp0; ++var_ip) {
            u16 temp_r3_2 = arg2[1];
            u16 temp_r7 = arg2[0];
            s32 var_r5 = 8;
            s32 temp_r8 = temp_r3_2 & 0x4000;
            s32 var_r6 = 8;
            s32 temp_r9 = temp_r3_2 & 0x8000;
            s32 temp_r10, temp_r3_3, temp_r5, temp_r7_2;
            u8 temp_r4;
            s32 temp_r8_2, xOffset, yOffset, rawY;
            if (temp_r8 == 0x4000) {
                var_r5 = 0x10;
                var_r6 = 0x10;
            }
            temp_r10 = temp_r3_2 & 0xC000;
            if (temp_r9 == 0x8000) {
                var_r5 = 0x20;
                var_r6 = 0x20;
            }
            xOffset = temp_r3_2 & xMask;
            if (temp_r10 == 0xC000) {
                var_r5 = 0x40;
                var_r6 = 0x40;
            }
            yOffset = (u8)temp_r7;
            if ((temp_r7 & 0x4000) == 0x4000) {
                var_r5 = 0x10;
                if (temp_r8 == 0x4000) {
                    var_r5 = 0x20;
                }
                var_r6 = 8;
                if (temp_r9 == 0x8000) {
                    var_r5 = 0x20;
                    var_r6 = 0x10;
                }
                if (temp_r10 == 0xC000) {
                    var_r5 = 0x40;
                    var_r6 = 0x20;
                }
            }
            if ((temp_r7 & 0x8000) == 0x8000) {
                var_r6 = 0x10;
                if (temp_r8 == 0x4000) {
                    var_r6 = 0x20;
                }
                var_r5 = 8;
                if (temp_r9 == 0x8000) {
                    var_r5 = 0x10;
                    var_r6 = 0x20;
                }
                if (temp_r10 == 0xC000) {
                    var_r5 = 0x20;
                    var_r6 = 0x40;
                }
            }
            temp_r7_2 = arg0 + xOffset;
            rawY = arg1 + yOffset;
            temp_r8_2 = (u8)rawY;
            temp_r3_3 = temp_r7_2 & xMask;
            if ((temp_r3_3 <= 0x100) && ((s32) temp_r8_2 <= 0xC0)) {
                return 1;
            }
            temp_r5 = (var_r5 + temp_r7_2) & xMask;
            if ((temp_r5 <= 0x100) && ((s32) temp_r8_2 <= 0xC0)) {
                return 1;
            }
            temp_r4 = var_r6 + rawY;
            if ((temp_r5 <= 0x100) && ((s32) temp_r4 <= 0xC0)) {
                return 1;
            }
            if ((temp_r3_3 <= 0x100) && ((s32) temp_r4 <= 0xC0)) {
                return 1;
            }
            arg2 += 3;
        }
    }
    return 0;
}
#pragma pop
/* Appends a SpriteQuadTemplate's attribute words to the current 3D-sprite
 * engine's OAM source list: x + xOffset (mod 0x200) into attr0's tile column,
 * y + yOffset (mod 0x100) into attr1, and tile + the template's tile number
 * (scaled by the bank's tile-size bits) into attr2. Gives up once the engine
 * has 128 sprites. */
void DS3D_AddSpriteQuad(s32 x, s32 y, u32 tile, u16 *template_)
{
    extern u16 **gCur3DSpriteEngine;
    u16 *oam;
    s32 count;
    s32 tileLow, tileHigh, mask = 0x3ff, xmask;
    s32 a, b, c, shift;
    u16 *src;
    void *engine;
    u8 index;

    count = *template_++;
    engine = gCur3DSpriteEngine;
    src = M2C_FIELD(engine, u16 * volatile *, 0x38);
    index = M2C_FIELD(engine, volatile u8 *, 0x4a);
    oam = src + index * 4;
    if (!count) {
        return;
    }
    tileHigh = tile & 0xfc00;
    tileLow = tile & mask;
    xmask = mask - 0x200;
    do {
        if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a) >= 128) {
            return;
        }
        a = template_[0];
        oam[0] = ((a | y) & 0xff00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3e) + (a + y)) & 255);
        b = template_[1];
        oam[1] = ((b | x) & 0xfe00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (b + x)) & xmask);
        c = template_[2];
        template_ += 3;
        shift = (u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30;
        oam[2] = (c & 0xfc00) + ((tileLow + (((c & mask) >> shift) & mask)) & mask) + tileHigh;
        oam += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a)++;
    } while (--count);
}

#pragma push
#pragma opt_strength_reduction off
void Apply3DSpriteBankMain(void) {
 void GX_ConfigureDisplay(s32,s32,s32); void GX_SetMasterBrightness(void *,s32); void func_02003f24(s32);
 extern u16 *g3DSpriteBankMain;
 extern s32 g3DSpriteEngineMain;
 s32 a,b,c,d,e;
 u32 mode;
 u16 f;
 volatile u32 *disp=(volatile u32 *)0x4000000;
 volatile u32 *regs=(volatile u32 *)0x4000010;
 f=g3DSpriteBankMain[0];
 GX_ConfigureDisplay(M2C_FIELD(g3DSpriteBankMain,s32 *,0x34),(u32)(f<<29)>>29,(u32)(f<<28)>>31);
 a=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<26)>>31)?2:0;
 b=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<27)>>31)?1:0;
 c=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<25)>>31)?4:0;
 d=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<24)>>31)?8:0;
 e=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<23)>>31)?16:0;
 *disp=(*disp&~0x1f00)|((e|(d|(c|(b|a))))<<8);
 a=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<21)>>31)?2:0;
 b=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<22)>>31)?1:0;
 c=((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<20)>>31)?4:0;
 *disp=(*disp&~0xe000)|((c|(b|a))<<13);
 a=*disp&0xffcfffef;
 f=M2C_FIELD(g3DSpriteBankMain,u16 *,0);
 mode=(((u32)(f<<19)>>31)<<4)|(((u32)(f<<17)>>30)<<20);
 *disp=a|mode;
 a=*disp&0xffbfff9f;
 f=g3DSpriteBankMain[1];
 mode=(((u32)(f<<24)>>30)<<5)|(((u32)(f<<23)>>31)<<22);
 *disp=a|mode;
 if((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<16)>>31) *disp &=~0x800000;else *disp|=0x800000;
 if((u32)(M2C_FIELD(g3DSpriteBankMain,volatile u16 *,0)<<28)>>31) {
 func_02003f24(M2C_FIELD(g3DSpriteBankMain,u16 *,56)-M2C_FIELD((void *)g3DSpriteEngineMain,s16 *,0x3c));
 } else
{void *engine=(void *)g3DSpriteEngineMain; void *bank=(void *)g3DSpriteBankMain; s32 y=M2C_FIELD(bank,u16 *,64)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,56)-M2C_FIELD(engine,s16 *,0x3c); regs[0]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineMain; void *bank=(void *)g3DSpriteBankMain; s32 y=M2C_FIELD(bank,u16 *,66)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,58)-M2C_FIELD(engine,s16 *,0x3c); regs[1]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineMain; void *bank=(void *)g3DSpriteBankMain; s32 y=M2C_FIELD(bank,u16 *,68)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,60)-M2C_FIELD(engine,s16 *,0x3c); regs[2]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineMain; void *bank=(void *)g3DSpriteBankMain; s32 y=M2C_FIELD(bank,u16 *,70)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,62)-M2C_FIELD(engine,s16 *,0x3c); regs[3]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{u16 f=M2C_FIELD(g3DSpriteBankMain,u16 *,2); *disp=(*disp&~0x38000000)|(((u32)(f<<29)>>29)<<27);}
 {u16 f=M2C_FIELD(g3DSpriteBankMain,u16 *,2); *disp=(*disp&~0x07000000)|(((u32)(f<<26)>>29)<<24);}
 M2C_FIELD(regs,volatile u16 *,-8)=M2C_FIELD(g3DSpriteBankMain,u16 *,6);
M2C_FIELD(regs,volatile u16 *,-6)=M2C_FIELD(g3DSpriteBankMain,u16 *,8);
M2C_FIELD(regs,volatile u16 *,-4)=M2C_FIELD(g3DSpriteBankMain,u16 *,10);
M2C_FIELD(regs,volatile u16 *,-2)=M2C_FIELD(g3DSpriteBankMain,u16 *,12);
M2C_FIELD(regs,volatile s16 *,16)=M2C_FIELD(g3DSpriteBankMain,s16 *,20);
M2C_FIELD(regs,volatile s16 *,18)=M2C_FIELD(g3DSpriteBankMain,s16 *,22);
M2C_FIELD(regs,volatile s16 *,20)=M2C_FIELD(g3DSpriteBankMain,s16 *,24);
M2C_FIELD(regs,volatile s16 *,22)=M2C_FIELD(g3DSpriteBankMain,s16 *,26);
M2C_FIELD(regs,volatile u32 *,24)=M2C_FIELD(g3DSpriteBankMain,u32 *,28);
M2C_FIELD(regs,volatile u32 *,28)=M2C_FIELD(g3DSpriteBankMain,u32 *,32);
M2C_FIELD(regs,volatile s16 *,32)=M2C_FIELD(g3DSpriteBankMain,s16 *,36);
M2C_FIELD(regs,volatile s16 *,34)=M2C_FIELD(g3DSpriteBankMain,s16 *,38);
M2C_FIELD(regs,volatile s16 *,36)=M2C_FIELD(g3DSpriteBankMain,s16 *,40);
M2C_FIELD(regs,volatile s16 *,38)=M2C_FIELD(g3DSpriteBankMain,s16 *,42);
M2C_FIELD(regs,volatile u32 *,40)=M2C_FIELD(g3DSpriteBankMain,u32 *,44);
M2C_FIELD(regs,volatile u32 *,44)=M2C_FIELD(g3DSpriteBankMain,u32 *,48);
M2C_FIELD(regs,volatile u16 *,56)=M2C_FIELD(g3DSpriteBankMain,u16 *,14);
M2C_FIELD(regs,volatile u16 *,58)=M2C_FIELD(g3DSpriteBankMain,u16 *,16);
{u8 *p=(u8 *)g3DSpriteBankMain; u8 bottom=p[75],top=p[73],right=p[74],left=p[72]; M2C_FIELD(regs,volatile u16 *,48)=((left<<8)&0xff00)|top; M2C_FIELD(regs,volatile u16 *,52)=((right<<8)&0xff00)|bottom;}
{u8 *p=(u8 *)g3DSpriteBankMain; u8 bottom=p[79],top=p[77],right=p[78],left=p[76]; M2C_FIELD(regs,volatile u16 *,50)=((left<<8)&0xff00)|top; M2C_FIELD(regs,volatile u16 *,54)=((right<<8)&0xff00)|bottom;}
M2C_FIELD(regs,volatile u16 *,0x40)=M2C_FIELD(g3DSpriteBankMain,u16 *,0x12);
 {u8 *p=(u8 *)g3DSpriteBankMain; M2C_FIELD(regs,volatile u16 *,0x42)=(p[0x51]&31)|((u32)(p[0x52]<<27)>>19);}
 M2C_FIELD(regs,volatile u16 *,0x44)=M2C_FIELD(g3DSpriteBankMain,u8 *,0x53)&31;
 {s32 brightness=M2C_FIELD(g3DSpriteBankMain,s8 *,0x50);GX_SetMasterBrightness((void *)((u8 *)regs+0x5c),brightness);}
}
#pragma pop
M2C_UNK Apply3DSpriteBankSub(void) {
 void GX_SetSubBgMode(s32); void GX_SetMasterBrightness(void *,s32);
 extern u16 *g3DSpriteBankSub;
 extern s32 g3DSpriteEngineSub;
 s32 a,b,c,d,e;
u32 mode;
 u16 f;
 volatile u32 *disp=(volatile u32 *)0x4001000;
 volatile u32 *regs=(volatile u32 *)0x4001010;
 GX_SetSubBgMode((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<29)>>29);
 a=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<26)>>31)?2:0;
 b=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<27)>>31)?1:0;
 c=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<25)>>31)?4:0;
 d=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<24)>>31)?8:0;
 e=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<23)>>31)?16:0;
 *disp=(*disp&~0x1f00)|((e|(d|(c|(b|a))))<<8);
 a=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<21)>>31)?2:0;
 b=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<22)>>31)?1:0;
 c=((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<20)>>31)?4:0;
 *disp=(*disp&~0xe000)|((c|(b|a))<<13);
 f=M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0);
 mode=(((u32)(f<<17)>>30)<<20)|(((u32)(f<<19)>>31)<<4);
 *disp=(*disp&0xffcfffef)|mode;
 f=g3DSpriteBankSub[1];
 mode=(((u32)(f<<23)>>31)<<22)|(((u32)(f<<24)>>30)<<5);
 *disp=(*disp&~0x60)|mode;
 if((u32)(M2C_FIELD(g3DSpriteBankSub,volatile u16 *,0)<<16)>>31) *disp &=~0x800000;else *disp|=0x800000;
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)g3DSpriteBankSub; s32 y=M2C_FIELD(bank,u16 *,64)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,56)-M2C_FIELD(engine,s16 *,0x3c); regs[0]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)g3DSpriteBankSub; s32 y=M2C_FIELD(bank,u16 *,66)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,58)-M2C_FIELD(engine,s16 *,0x3c); regs[1]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)g3DSpriteBankSub; s32 y=M2C_FIELD(bank,u16 *,68)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,60)-M2C_FIELD(engine,s16 *,0x3c); regs[2]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)g3DSpriteBankSub; s32 y=M2C_FIELD(bank,u16 *,70)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,62)-M2C_FIELD(engine,s16 *,0x3c); regs[3]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
M2C_FIELD(regs,volatile u16 *,-8)=M2C_FIELD(g3DSpriteBankSub,u16 *,6);
M2C_FIELD(regs,volatile u16 *,-6)=M2C_FIELD(g3DSpriteBankSub,u16 *,8);
M2C_FIELD(regs,volatile u16 *,-4)=M2C_FIELD(g3DSpriteBankSub,u16 *,10);
M2C_FIELD(regs,volatile u16 *,-2)=M2C_FIELD(g3DSpriteBankSub,u16 *,12);
M2C_FIELD(regs,volatile s16 *,16)=M2C_FIELD(g3DSpriteBankSub,s16 *,20);
M2C_FIELD(regs,volatile s16 *,18)=M2C_FIELD(g3DSpriteBankSub,s16 *,22);
M2C_FIELD(regs,volatile s16 *,20)=M2C_FIELD(g3DSpriteBankSub,s16 *,24);
M2C_FIELD(regs,volatile s16 *,22)=M2C_FIELD(g3DSpriteBankSub,s16 *,26);
M2C_FIELD(regs,volatile u32 *,24)=M2C_FIELD(g3DSpriteBankSub,u32 *,28);
M2C_FIELD(regs,volatile u32 *,28)=M2C_FIELD(g3DSpriteBankSub,u32 *,32);
M2C_FIELD(regs,volatile s16 *,32)=M2C_FIELD(g3DSpriteBankSub,s16 *,36);
M2C_FIELD(regs,volatile s16 *,34)=M2C_FIELD(g3DSpriteBankSub,s16 *,38);
M2C_FIELD(regs,volatile s16 *,36)=M2C_FIELD(g3DSpriteBankSub,s16 *,40);
M2C_FIELD(regs,volatile s16 *,38)=M2C_FIELD(g3DSpriteBankSub,s16 *,42);
M2C_FIELD(regs,volatile u32 *,40)=M2C_FIELD(g3DSpriteBankSub,u32 *,44);
M2C_FIELD(regs,volatile u32 *,44)=M2C_FIELD(g3DSpriteBankSub,u32 *,48);
M2C_FIELD(regs,volatile u16 *,56)=M2C_FIELD(g3DSpriteBankSub,u16 *,14);
M2C_FIELD(regs,volatile u16 *,58)=M2C_FIELD(g3DSpriteBankSub,u16 *,16);
{u8 *p=(u8 *)g3DSpriteBankSub; u8 bottom=p[75],top=p[73],right=p[74],left=p[72]; M2C_FIELD(regs,volatile u16 *,48)=((left<<8)&0xff00)|top; M2C_FIELD(regs,volatile u16 *,52)=((right<<8)&0xff00)|bottom;}
{u8 *p=(u8 *)g3DSpriteBankSub; u8 bottom=p[79],top=p[77],right=p[78],left=p[76]; M2C_FIELD(regs,volatile u16 *,50)=((left<<8)&0xff00)|top; M2C_FIELD(regs,volatile u16 *,54)=((right<<8)&0xff00)|bottom;}
M2C_FIELD(regs,volatile u16 *,0x40)=M2C_FIELD(g3DSpriteBankSub,u16 *,0x12);
 {u8 *p=(u8 *)g3DSpriteBankSub; M2C_FIELD(regs,volatile u16 *,0x42)=(p[0x51]&31)|((u32)(p[0x52]<<27)>>19);}
 M2C_FIELD(regs,volatile u16 *,0x44)=M2C_FIELD(g3DSpriteBankSub,u8 *,0x53)&31;
 {s32 brightness=M2C_FIELD(g3DSpriteBankSub,s8 *,0x50);GX_SetMasterBrightness((void *)((u8 *)regs+0x5c),brightness);}
}

void func_01ff9ab4(void) {
    extern u16 *g3DSpriteBankMain;
    GX_SetVBlankIrq(((u32)(M2C_FIELD(g3DSpriteBankMain, u16 *, 4) << 31) >> 31) != 0);
    GX_SetHBlankIrq(((u32)(M2C_FIELD(g3DSpriteBankMain, u16 *, 4) << 30) >> 31) != 0);
    if (((u32)(M2C_FIELD(g3DSpriteBankMain, u16 *, 4) << 29) >> 31) != 0) {
        *(volatile u16 *)0x04000004 |= 0x20;
    } else {
        *(volatile u16 *)0x04000004 &= ~0x20;
    }
}

void Apply3DSpriteBanks(void) {
    M2C_UNK Apply3DSpriteBankSub();
    void func_0207fafc(void);
    func_01ff9ab4();
    Apply3DSpriteBankMain();
    Apply3DSpriteBankSub();
    func_0207fafc();
}

/* Whether a 3D-sprite bank of this mode draws `layer` as one whole cell grid
 * (rather than a split layer): mode 0 on any layer, modes 1 and 3 up to layer 2,
 * modes 2, 4 and 5 up to layer 1. */
u8 Is3DSpriteWholeLayer(u8 bankMode,u32 layer) {
u8 whole;
switch(bankMode){case 0:return 1;case 1:case 3:if(layer<=2)whole=1;else whole=0;return whole;case 2:case 4:case 5:if(layer<=1)whole=1;else whole=0;return whole;default:return 0;}
}

/* True when `layer` of the 3D sprite bank in layout `bankMode` is a split layer:
 * in mode 1 layer 3 is split, in mode 2 layers 1 and 2, in mode 4 layer 2.  The
 * other layers, and every layer of the other modes, are whole layers. */
u8 Is3DSpriteSplitLayer(s32 bankMode,s32 layer) {
u8 split;
switch(bankMode){case 1:if(layer==3)split=1;else split=0;return split;case 2:if((u32)(u8)(layer+0xfe)<=1)split=1;else split=0;return split;case 4:if(layer==2)split=1;else split=0;return split;default:return 0;}
}

/* Byte size of the tile buffer of sprite layer `layer` in the current engine,
 * looked up from the layer's 2-bit size class (bits 14..15 of its packed
 * SpriteTile word in the bank): the whole cell grid for a layer that is a full
 * panel in this bank mode, one half of it for a split layer, and both halves
 * when the mode gives the layer neither role. */
s32 Get3DSpriteLayerSize(u8 bankMode, s32 layer) {
    extern u16 **gCur3DSpriteEngine;
    extern s32 data_01ff9b50[]; /* sizes per size class, whole cell grid */
    extern s32 data_01ff9b60[]; /* sizes per size class, one half of the grid */
    if (Is3DSpriteWholeLayer(bankMode, layer) != 0) {
        return data_01ff9b50[(u32)(M2C_FIELD(*gCur3DSpriteEngine + layer, u16 *, DS3D_BANK_LAYER_TILE0) << 16) >> 30];
    }
    if (Is3DSpriteSplitLayer(bankMode, layer) != 0) {
        return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + layer, u16 *, DS3D_BANK_LAYER_TILE0) << 16) >> 30];
    }
    return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + layer, u16 *, DS3D_BANK_LAYER_TILE0) << 16) >> 30] * 2;
}

/* Wipe the tile buffer of sprite layer `layer` in the current 3D-sprite engine:
 * the byte count is the layer's size for the bank's tile-size class, the
 * destination its buffer in the engine's layer table. */
void Clear3DSpriteLayer(u8 layer) {
    s32 Get3DSpriteLayerSize(u8, s32);
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, s32);
    extern u16 **gCur3DSpriteEngine;
    MI_CpuFill32(0, M2C_FIELD(&gCur3DSpriteEngine[layer], s32 *, DS3D_ENGINE_LAYER_TILES), Get3DSpriteLayerSize((u8)(((u32)(**gCur3DSpriteEngine << 0x1D) >> 0x1D)), layer));
}

/* Wipe the tile buffer of layer `layer` of the main 3D-sprite engine.  The byte
 * count is Get3DSpriteLayerSize for the bank's tile-size class; the destination
 * is the layer's buffer pointer in the main engine's layer table at +0x20. */
void Clear3DSpriteLayerMain(u8 layer) {
    extern u16 *g3DSpriteBankMain;
    extern s32 g3DSpriteEngineMain;
    MI_CpuFill32(0, M2C_FIELD((g3DSpriteEngineMain + (layer * 4)), s32 *, 0x20), Get3DSpriteLayerSize((u8) ((u32) (*g3DSpriteBankMain << 0x1D) >> 0x1D), layer));
}

/* Wipe the tile buffer of layer `layer` of the sub 3D-sprite engine.  The byte
 * count is Get3DSpriteLayerSize for the bank's tile-size class; the destination
 * is the layer's buffer pointer in the sub engine's layer table at +0x20. */
void Clear3DSpriteLayerSub(u8 layer) {
    extern u16 *g3DSpriteBankSub;
    extern s32 g3DSpriteEngineSub;
    MI_CpuFill32(0, M2C_FIELD((g3DSpriteEngineSub + (layer * 4)), s32 *, 0x20), Get3DSpriteLayerSize((u8) ((u32) (*g3DSpriteBankSub << 0x1D) >> 0x1D), layer));
}

#pragma opt_propagation off
/* Wipe layer `layer`'s decompressed texture block in VRAM: fill the current
 * 3D-sprite engine's DS3D_ENGINE_LAYER_VRAM slot of that layer with zero
 * (0x40 bytes). */
void Clear3DSpriteLayerVram(u8 layer) {
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, s32);
    extern u16 **gCur3DSpriteEngine;
    s32 vram;

    vram = M2C_FIELD((char *)gCur3DSpriteEngine + layer * 4, s32 *, DS3D_ENGINE_LAYER_VRAM);
    {
        s32 fill = 0;
        s32 size = 0x40;
        MI_CpuFill32(fill, vram, size);
    }
}
#pragma opt_propagation reset
/* Clear every 3D-sprite layer of the current engine: wipe layer `layer`'s VRAM
 * region and its tile buffer, then mark it dirty (bit `layer` of the engine's
 * dirty mask at +0x46) so the engine uploads it again. */
void ClearAll3DSpriteLayers(void) {
    extern u16 **gCur3DSpriteEngine;
    s32 layer;
    for (layer = 0; layer < 4; layer++) {
        Clear3DSpriteLayerVram((u8)layer);
        Clear3DSpriteLayer((u8)layer);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1 << layer;
    }
}

