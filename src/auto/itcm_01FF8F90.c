/* 17 functions from 0x01FF8F90 to 0x01FF9ED0 (itcm), found by ds-decomp. */
#include "common.h"
static inline void SetSubWindow9690(volatile u16 *h, volatile u16 *v, s32 left, s32 right, s32 top, s32 bottom) { *h=((left<<8)&0xff00)|top; *v=((right<<8)&0xff00)|bottom; }
static inline void SetSubScroll9690(volatile u32 *reg, s32 x, s32 y) { s32 mask=0x1ff; *reg=(x&mask)|((mask<<16)&(y<<16)); }

s32 func_01ff8f90(s32 arg0, s32 arg1, u16 *arg2) {
    s32 sp0;
    s32 temp_r10;
    s32 temp_r3_3;
    s32 temp_r5;
    s32 temp_r7_2;
    s32 temp_r8;
    s32 temp_r9;
    s32 var_ip;
    s32 var_r5;
    s32 var_r6;
    u16 temp_r3;
    u16 temp_r3_2;
    u16 temp_r7;
    u8 temp_r4;
    u8 temp_r8_2;
    void *var_r2;

    if (arg2 != NULL) {
        temp_r3 = *arg2;
        var_r2 = arg2 + 2;
        var_ip = 0;
        sp0 = (s32) temp_r3;
        if ((s32) temp_r3 > 0) {
loop_3:
            temp_r3_2 = M2C_FIELD(var_r2, u16 *, 2);
            temp_r7 = M2C_FIELD(var_r2, u16 *, 0);
            var_r5 = 8;
            temp_r8 = temp_r3_2 & 0x4000;
            var_r6 = 8;
            temp_r9 = temp_r3_2 & 0x8000;
            if (temp_r8 == 0x4000) {
                var_r5 = 0x10;
                var_r6 = 0x10;
            }
            temp_r10 = temp_r3_2 & 0xC000;
            if (temp_r9 == 0x8000) {
                var_r5 = 0x20;
                var_r6 = 0x20;
            }
            if (temp_r10 == 0xC000) {
                var_r5 = 0x40;
                var_r6 = 0x40;
            }
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
            temp_r7_2 = arg0 + (temp_r3_2 & 0x1FF);
            temp_r8_2 = arg1 + (u8) temp_r7;
            temp_r3_3 = temp_r7_2 & 0x1FF;
            if ((temp_r3_3 <= 0x100) && ((s32) temp_r8_2 <= 0xC0)) {
                return 1;
            }
            temp_r5 = (var_r5 + temp_r7_2) & 0x1FF;
            if ((temp_r5 <= 0x100) && ((s32) temp_r8_2 <= 0xC0)) {
                return 1;
            }
            temp_r4 = var_r6 + temp_r8_2;
            if ((temp_r5 <= 0x100) && ((s32) temp_r4 <= 0xC0)) {
                return 1;
            }
            if ((temp_r3_3 <= 0x100) && ((s32) temp_r4 <= 0xC0)) {
                return 1;
            }
            var_ip += 1;
            var_r2 += 6;
            if (var_ip >= sp0) {
                /* Duplicate return node #36. Try simplifying control flow for better match */
                return 0;
            }
            goto loop_3;
        }
    }
    return 0;
}

void func_01ff90e4(s32 arg0, s32 arg1, u32 arg2, u16 *arg3)
{
    extern u16 **gCur3DSpriteEngine;
    u16 *dst;
    s32 count;
    s32 lo, hi, mask = 0x3ff, xmask;
    s32 a, b, c, shift;
    u16 *base;
    void *engine;
    u8 n;

    count = *arg3++;
    engine = gCur3DSpriteEngine;
    base = M2C_FIELD(engine, u16 * volatile *, 0x38);
    n = M2C_FIELD(engine, volatile u8 *, 0x4a);
    dst = base + n * 4;
    if (!count) {
        return;
    }
    hi = arg2 & 0xfc00;
    lo = arg2 & mask;
    xmask = mask - 0x200;
    do {
        if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a) >= 128) {
            return;
        }
        a = arg3[0];
        dst[0] = ((a | arg1) & 0xff00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3e) + (a + arg1)) & 255);
        b = arg3[1];
        dst[1] = ((b | arg0) & 0xfe00) + ((M2C_FIELD(gCur3DSpriteEngine, s16 *, 0x3c) + (b + arg0)) & xmask);
        c = arg3[2];
        arg3 += 3;
        shift = (u32)(*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30;
        dst[2] = (c & 0xfc00) + ((lo + (((c & mask) >> shift) & mask)) & mask) + hi;
        dst += 4;
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x4a)++;
    } while (--count);
}

#pragma push
#pragma opt_strength_reduction off
void func_01ff91d8(void) {
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
M2C_UNK func_01ff9690(void) {
 void GX_SetSubBgMode(s32); void GX_SetMasterBrightness(void *,s32);
 extern u16 *data_027e00c0;
 extern s32 g3DSpriteEngineSub;
 s32 a,b,c,d,e;
u32 mode;
 u16 f;
 volatile u32 *disp=(volatile u32 *)0x4001000;
 volatile u32 *regs=(volatile u32 *)0x4001010;
 GX_SetSubBgMode((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<29)>>29);
 a=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<26)>>31)?2:0;
 b=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<27)>>31)?1:0;
 c=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<25)>>31)?4:0;
 d=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<24)>>31)?8:0;
 e=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<23)>>31)?16:0;
 *disp=(*disp&~0x1f00)|((e|(d|(c|(b|a))))<<8);
 a=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<21)>>31)?2:0;
 b=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<22)>>31)?1:0;
 c=((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<20)>>31)?4:0;
 *disp=(*disp&~0xe000)|((c|(b|a))<<13);
 f=M2C_FIELD(data_027e00c0,volatile u16 *,0);
 mode=(((u32)(f<<17)>>30)<<20)|(((u32)(f<<19)>>31)<<4);
 *disp=(*disp&0xffcfffef)|mode;
 f=data_027e00c0[1];
 mode=(((u32)(f<<23)>>31)<<22)|(((u32)(f<<24)>>30)<<5);
 *disp=(*disp&~0x60)|mode;
 if((u32)(M2C_FIELD(data_027e00c0,volatile u16 *,0)<<16)>>31) *disp &=~0x800000;else *disp|=0x800000;
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)data_027e00c0; s32 y=M2C_FIELD(bank,u16 *,64)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,56)-M2C_FIELD(engine,s16 *,0x3c); regs[0]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)data_027e00c0; s32 y=M2C_FIELD(bank,u16 *,66)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,58)-M2C_FIELD(engine,s16 *,0x3c); regs[1]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)data_027e00c0; s32 y=M2C_FIELD(bank,u16 *,68)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,60)-M2C_FIELD(engine,s16 *,0x3c); regs[2]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
{void *engine=(void *)g3DSpriteEngineSub; void *bank=(void *)data_027e00c0; s32 y=M2C_FIELD(bank,u16 *,70)-M2C_FIELD(engine,s16 *,0x3e); s32 x=M2C_FIELD(bank,u16 *,62)-M2C_FIELD(engine,s16 *,0x3c); regs[3]=(x&0x1ff)|((0x1ff<<16)&(y<<16));}
M2C_FIELD(regs,volatile u16 *,-8)=M2C_FIELD(data_027e00c0,u16 *,6);
M2C_FIELD(regs,volatile u16 *,-6)=M2C_FIELD(data_027e00c0,u16 *,8);
M2C_FIELD(regs,volatile u16 *,-4)=M2C_FIELD(data_027e00c0,u16 *,10);
M2C_FIELD(regs,volatile u16 *,-2)=M2C_FIELD(data_027e00c0,u16 *,12);
M2C_FIELD(regs,volatile s16 *,16)=M2C_FIELD(data_027e00c0,s16 *,20);
M2C_FIELD(regs,volatile s16 *,18)=M2C_FIELD(data_027e00c0,s16 *,22);
M2C_FIELD(regs,volatile s16 *,20)=M2C_FIELD(data_027e00c0,s16 *,24);
M2C_FIELD(regs,volatile s16 *,22)=M2C_FIELD(data_027e00c0,s16 *,26);
M2C_FIELD(regs,volatile u32 *,24)=M2C_FIELD(data_027e00c0,u32 *,28);
M2C_FIELD(regs,volatile u32 *,28)=M2C_FIELD(data_027e00c0,u32 *,32);
M2C_FIELD(regs,volatile s16 *,32)=M2C_FIELD(data_027e00c0,s16 *,36);
M2C_FIELD(regs,volatile s16 *,34)=M2C_FIELD(data_027e00c0,s16 *,38);
M2C_FIELD(regs,volatile s16 *,36)=M2C_FIELD(data_027e00c0,s16 *,40);
M2C_FIELD(regs,volatile s16 *,38)=M2C_FIELD(data_027e00c0,s16 *,42);
M2C_FIELD(regs,volatile u32 *,40)=M2C_FIELD(data_027e00c0,u32 *,44);
M2C_FIELD(regs,volatile u32 *,44)=M2C_FIELD(data_027e00c0,u32 *,48);
M2C_FIELD(regs,volatile u16 *,56)=M2C_FIELD(data_027e00c0,u16 *,14);
M2C_FIELD(regs,volatile u16 *,58)=M2C_FIELD(data_027e00c0,u16 *,16);
{u8 *p=(u8 *)data_027e00c0; u8 bottom=p[75],top=p[73],right=p[74],left=p[72]; M2C_FIELD(regs,volatile u16 *,48)=((left<<8)&0xff00)|top; M2C_FIELD(regs,volatile u16 *,52)=((right<<8)&0xff00)|bottom;}
{u8 *p=(u8 *)data_027e00c0; u8 bottom=p[79],top=p[77],right=p[78],left=p[76]; M2C_FIELD(regs,volatile u16 *,50)=((left<<8)&0xff00)|top; M2C_FIELD(regs,volatile u16 *,54)=((right<<8)&0xff00)|bottom;}
M2C_FIELD(regs,volatile u16 *,0x40)=M2C_FIELD(data_027e00c0,u16 *,0x12);
 {u8 *p=(u8 *)data_027e00c0; M2C_FIELD(regs,volatile u16 *,0x42)=(p[0x51]&31)|((u32)(p[0x52]<<27)>>19);}
 M2C_FIELD(regs,volatile u16 *,0x44)=M2C_FIELD(data_027e00c0,u8 *,0x53)&31;
 {s32 brightness=M2C_FIELD(data_027e00c0,s8 *,0x50);GX_SetMasterBrightness((void *)((u8 *)regs+0x5c),brightness);}
}

void func_01ff9ab4(void) {
    extern u16 *g3DSpriteBankMain;
    GX_SetVBlankIrq(((u32)(M2C_FIELD(g3DSpriteBankMain, u16 *, 4) << 31) >> 31) != 0);
    func_02002428(((u32)(M2C_FIELD(g3DSpriteBankMain, u16 *, 4) << 30) >> 31) != 0);
    if (((u32)(M2C_FIELD(g3DSpriteBankMain, u16 *, 4) << 29) >> 31) != 0) {
        *(volatile u16 *)0x04000004 |= 0x20;
    } else {
        *(volatile u16 *)0x04000004 &= ~0x20;
    }
}

void func_01ff9b38(void) {
    M2C_UNK func_01ff9690();
    void func_0207fafc(void);
    func_01ff9ab4();
    func_01ff91d8();
    func_01ff9690();
    func_0207fafc();
}

u8 func_01ff9b70(u8 arg0,u32 arg1) {
u8 result;
switch(arg0){case 0:return 1;case 1:case 3:if(arg1<=2)result=1;else result=0;return result;case 2:case 4:case 5:if(arg1<=1)result=1;else result=0;return result;default:return 0;}
}

u8 func_01ff9bcc(s32 arg0,s32 arg1) {
u8 a,b,c;
switch(arg0){case 1:if(arg1==3)a=1;else a=0;return a;case 2:if((u32)(u8)(arg1+0xfe)<=1)b=1;else b=0;return b;case 4:if(arg1==2)c=1;else c=0;return c;default:return 0;}
}

s32 Get3DSpriteLayerSize(u8 arg0, s32 arg1) {
    extern u16 **gCur3DSpriteEngine;
    extern s32 data_01ff9b50[];
    extern s32 data_01ff9b60[];
    if (func_01ff9b70(arg0, arg1) != 0) {
        return data_01ff9b50[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30];
    }
    if (func_01ff9bcc(arg0, arg1) != 0) {
        return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30];
    }
    return data_01ff9b60[(u32)(M2C_FIELD(*gCur3DSpriteEngine + arg1, u16 *, 6) << 16) >> 30] * 2;
}

void Clear3DSpriteLayer(u8 arg0) {
    s32 Get3DSpriteLayerSize(u8, s32);
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, s32);
    extern u16 **gCur3DSpriteEngine;
    MI_CpuFill32(0, M2C_FIELD(&gCur3DSpriteEngine[arg0], s32 *, 0x20), Get3DSpriteLayerSize((u8)(((u32)(**gCur3DSpriteEngine << 0x1D) >> 0x1D)), arg0));
}

void func_01ff9d38(s32 arg0) {
    extern u16 *g3DSpriteBankMain;
    extern s32 g3DSpriteEngineMain;
    MI_CpuFill32(0, M2C_FIELD((g3DSpriteEngineMain + (arg0 * 4)), s32 *, 0x20), Get3DSpriteLayerSize((u8) ((u32) (*g3DSpriteBankMain << 0x1D) >> 0x1D), arg0));
}

void func_01ff9d88(s32 arg0) {
    extern u16 *data_027e00c0;
    extern s32 g3DSpriteEngineSub;
    MI_CpuFill32(0, M2C_FIELD((g3DSpriteEngineSub + (arg0 * 4)), s32 *, 0x20), Get3DSpriteLayerSize((u8) ((u32) (*data_027e00c0 << 0x1D) >> 0x1D), arg0));
}

#pragma opt_propagation off
void func_01ff9dd8(u8 arg0) { M2C_UNK MI_CpuFill32(M2C_UNK,s32,s32); extern u16 **gCur3DSpriteEngine; s32 dest; dest=M2C_FIELD((char *)gCur3DSpriteEngine + arg0*4,s32 *,0xC); { s32 zero=0; s32 size=0x40; MI_CpuFill32(zero,dest,size); } }
#pragma opt_propagation reset
void func_01ff9e00(void) {
    extern u16 **gCur3DSpriteEngine;
    s32 i;
    for (i = 0; i < 4; i++) {
        func_01ff9dd8((u8)i);
        Clear3DSpriteLayer((u8)i);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1 << i;
    }
}

