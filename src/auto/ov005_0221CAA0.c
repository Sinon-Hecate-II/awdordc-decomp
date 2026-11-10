/* 3 functions from 0x0221CAA0 to 0x0221D818 (ov005), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineMain;
extern void *g3DSpriteEngineSub;
extern u8 data_ov005_02220d50[];
static inline void boxBoundsSigned(s32 x,s32 y,s32 w,s32 h,void *p) { M2C_FIELD(p,s16*,0x34)=x; M2C_FIELD(p,s16*,0x36)=y; M2C_FIELD(p,s32*,0x40)=(((M2C_FIELD(p,s32*,0x40)&~511)|(w&(-512U>>23)))&0xfffc01ff)|((u32)(h<<23)>>14); }
static inline s32 boxWidth(void *p) { return p ? M2C_FIELD(p,u16*,4):0; }
static inline s32 boxHeight(void *p) { return p ? M2C_FIELD(p,u16*,6):0; }
static inline s32 boxX(void *p) { return p ? M2C_FIELD(p,s16*,0):0; }
static inline s32 boxY(void *p) { return p ? M2C_FIELD(p,s16*,2):0; }
static inline void boxPosition(void *p,s32 x,s32 y) { M2C_FIELD(p,s16*,0x34)=x; M2C_FIELD(p,s16*,0x36)=y; }
typedef struct { u32 width:9,height:9,other:14; } BoxSizeBits;
static inline void boxSize(void *p,u32 w,u32 h) { M2C_FIELD(p,u32*,0x40)=((M2C_FIELD(p,u32*,0x40)&~511)|(w&(-512U>>23)))&0xfffc01ff | ((h<<23)>>14); }

static inline void boxBounds(s32 x,s32 y,u32 w,u32 h,void *p) { boxPosition(p,x,y); boxSize(p,w,h); }
void *func_01ffa770(void*);
void func_01ffa6fc(void*);
s32 EaseInterpolate(s32,s32,s32,s32,s32);
void func_02088e84(void*,s32,s16,s32,s32);
s32 func_020aae10(void*);
s32 func_020aae44(void*);
void func_02087d84(void*,s32,s16,s16,s32,s32);
/* Results screen intro animation: over 32 frames it cuts the cell grid of the 3D sprite into
   an upper and a lower half (the cut travels down), scrolls the results in from the right and
   from below, slides the two marker sprites up into place and finally clears the 3D sprite
   state of both screens. */
void ResultsScreenAnimate(void *arg0) {
  u16 *volatile oamAttr0;
  u16 *volatile oamAttr1;
  u16 *volatile oamAttr2;
  u16 *volatile oamAttr3;
  u16 *volatile oamAttr4;
  u16 *volatile oamAttr5;
  u16 *volatile oamAttr6;
  u16 *volatile oamAttr7;
  u16 *volatile oamAttr8;
  u16 *volatile oamAttr9;
  u16 *volatile oamAttr10;
  u16 *volatile oamAttr11;
  u16 *volatile oamAttr12;
  u16 *volatile oamAttr13;
  s32 splitRow,scroll,i; void *savedEngine,*leftSprite; s16 spriteY,spriteX,panelY; s32 width,height;
  M2C_FIELD(arg0,s32*,0x3c)++;
  splitRow=EaseInterpolate(EASE_LINEAR,0,16,M2C_FIELD(arg0,s32*,0x3c),32);
  savedEngine=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
  if(M2C_FIELD(arg0,s32*,0x3c)==1) {
  /* the 3D sprite's OBJ attribute word: priority 1, affine off, not disabled, 256 colour
     palette, square shape, mosaic off, colour mode on, affine parameter 0 */
  oamAttr0=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr0=(*oamAttr0 & ~0xc0)|0x40;
  oamAttr1=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr1=*oamAttr1 & ~ 1;
  oamAttr2=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr2=*oamAttr2 & ~ 2;
  oamAttr3=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr3=*oamAttr3 | 4;
  oamAttr4=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr4=*oamAttr4 & ~ 8;
  oamAttr5=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr5=*oamAttr5 & ~ 16;
  oamAttr6=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr6=*oamAttr6 & ~ 32;
  oamAttr7=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr7=*oamAttr7 & ~ 256;
  oamAttr8=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr8=*oamAttr8 & ~ 512;
  oamAttr9=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr9=*oamAttr9 & ~ 1024;
  oamAttr10=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr10=*oamAttr10 | 2048;
  oamAttr11=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr11=*oamAttr11 & ~ 4096;
  oamAttr12=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr12=*oamAttr12 & ~ 8192;
  }
  /* rows of the 3D sprite's cell grid above and below the cut */
  M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x51)=splitRow;
  M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x52)=16-splitRow;
  gCur3DSpriteEngine=savedEngine;
  scroll=EaseInterpolate(EASE_OUT_QUAD,192,0,M2C_FIELD(arg0,s32*,0x3c),32);
  M2C_FIELD(arg0,s32*,0x40)=M2C_FIELD(arg0,s32*,0x48)=scroll;
  scroll=EaseInterpolate(EASE_OUT_QUAD,-32,0,M2C_FIELD(arg0,s32*,0x3c),32);
  M2C_FIELD(arg0,s32*,0x44)=M2C_FIELD(arg0,s32*,0x4c)=scroll;
  panelY=(s16)M2C_FIELD(arg0,s32*,0x44);
  /* the two marker sprites of the scene, at display object offsets 0x3c and 0x40 */
  leftSprite=M2C_FIELD(func_01ffa770(data_ov005_02220d50),void**,60);
  func_02088e84(leftSprite,160,panelY,160,panelY);
  if((u8)(M2C_FIELD(M2C_FIELD(leftSprite,void**,0x64),u8*,18)!=0)){
  spriteY=M2C_FIELD(leftSprite,s16*,0x52); spriteX=M2C_FIELD(leftSprite,s16*,0x50);
  width=func_020aae10(leftSprite); height=func_020aae44(leftSprite);
  func_02087d84(M2C_FIELD(leftSprite,void**,0x64),1,spriteX,spriteY,(u16)width,(u16)height); }
  M2C_FIELD(leftSprite,s16*,0x34)=160; M2C_FIELD(leftSprite,s16*,0x36)=panelY;
  if((u8)(M2C_FIELD(M2C_FIELD(leftSprite,void**,0x64),u8*,18)!=0)){
  spriteY=M2C_FIELD(leftSprite,s16*,0x52); spriteX=M2C_FIELD(leftSprite,s16*,0x50);
  width=func_020aae10(leftSprite); height=func_020aae44(leftSprite);
  func_02087d84(M2C_FIELD(leftSprite,void**,0x64),1,spriteX,spriteY,(u16)width,(u16)height); }
  { void *rightSprite; s16 spriteY2,spriteX2,panelY2; s32 width2,height2;
  panelY2=(s16)M2C_FIELD(arg0,s32*,0x44);
  rightSprite=M2C_FIELD(func_01ffa770(data_ov005_02220d50),void**,64);
  func_02088e84(rightSprite,224,panelY2,224,panelY2);
  if((u8)(M2C_FIELD(M2C_FIELD(rightSprite,void**,0x64),u8*,18)!=0)){
  spriteY2=M2C_FIELD(rightSprite,s16*,0x52); spriteX2=M2C_FIELD(rightSprite,s16*,0x50);
  width2=func_020aae10(rightSprite); height2=func_020aae44(rightSprite);
  func_02087d84(M2C_FIELD(rightSprite,void**,0x64),1,spriteX2,spriteY2,(u16)width2,(u16)height2); }
  M2C_FIELD(rightSprite,s16*,0x34)=224; M2C_FIELD(rightSprite,s16*,0x36)=panelY2;
  if((u8)(M2C_FIELD(M2C_FIELD(rightSprite,void**,0x64),u8*,18)!=0)){
  spriteY2=M2C_FIELD(rightSprite,s16*,0x52); spriteX2=M2C_FIELD(rightSprite,s16*,0x50);
  width2=func_020aae10(rightSprite); height2=func_020aae44(rightSprite);
  func_02087d84(M2C_FIELD(rightSprite,void**,0x64),1,spriteX2,spriteY2,(u16)width2,(u16)height2); }
  }
  if(M2C_FIELD(arg0,s32*,0x3c)!=32)return;
  /* the animation is over: clear the 3D sprite of both screens */
  savedEngine=gCur3DSpriteEngine;
  for(i=0;i<2;i++){
  gCur3DSpriteEngine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
  oamAttr13=(u16*)(*(u8**)gCur3DSpriteEngine+18); *oamAttr13=*oamAttr13 & ~0xc0;
  M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x51)=0;
  M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x52)=0;
  M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x53)=0;
  } gCur3DSpriteEngine=savedEngine;
  M2C_FIELD(arg0,u8*,0x58)=0; M2C_FIELD(arg0,s32*,0x3c)=0;func_01ffa6fc(arg0);
}

void func_ov005_0221cff8(void *arg0) {
void *func_01ffa770(void*);void *func_020896f0(void*);s32 func_020cfb94();s32 func_020ae22c();
extern u8 data_ov005_02220d50[];
s32 i,y;void *sprite,*p;u32 width,height;
func_020aad18(M2C_FIELD(func_01ffa770(data_ov005_02220d50),s32*,0x38));
func_020aad18(M2C_FIELD(func_01ffa770(data_ov005_02220d50),s32*,0x3c));
func_020aad18(M2C_FIELD(func_01ffa770(data_ov005_02220d50),s32*,0x40));
i=0;
if(func_020cfb94()>0){y=79;do{
func_02087d18(M2C_FIELD(arg0,void**,0x34),(s16)y,170,16,16,(u16)(i+3),12);
i++;y+=20;
}while(i<func_020cfb94());}
func_02087f00(M2C_FIELD(arg0,void**,0x34),3);
M2C_FIELD(arg0,void**,0x38)=func_020896f0(arg0);
func_020893a8(M2C_FIELD(arg0,void**,0x38),4096,1,func_020ae22c(9));
sprite=M2C_FIELD(arg0,void**,0x38);p=*(void**)M2C_FIELD(arg0,void**,0x34);
boxBounds(boxX(p)-1,boxY(p)-1,boxWidth(p)+2,boxHeight(p)+2,sprite);
func_02089438(M2C_FIELD(arg0,void**,0x38));
}

extern u8 *data_02101e88;
extern u16 *gKeyState;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineMain;
extern void *g3DSpriteEngineSub;
extern void **gCurrentMap;
extern u8 data_ov005_02220f1c[],data_ov005_02220e5c[],data_ov005_02220eec[],data_ov005_02220d50[];
void func_02088044(void *);
void func_02087ec0(void *,s16);
void func_01ff9e44(s32,s32,s32);
s32 func_020a72e8(u8);
s32 func_ov000_0216cdec(s32,u8);
s32 func_020cfb94(void);
void *func_020e3218(void *);
void func_020814e4(void);
void func_02081590(void *,void *);
void func_02081528(void);
void func_01ff85b8(void *,s32,s32);
void PlaySoundEffect(s32);
void *func_01ffa770(void *);
void func_02087db8(void *,s32);
void func_02087e34(void *);
void func_01ffa6fc(void *);
#pragma push
#pragma opt_common_subs off
void func_ov005_0221d160(void *arg0){
    s32 sound = 0;
    s32 selection;
    s32 mode;
    if (data_02101e88[0x12] || data_02101e88[0x16]) {
        s32 value;
        func_02088044(M2C_FIELD(arg0, void **, 0x34));
        value = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), s8 *, 9);
        if ((u8)(value >= 0)) {
            M2C_FIELD(arg0, s32 *, 0x50) = value - 3;
            {
                void *sprite = M2C_FIELD(arg0, void **, 0x38);
                void *p = *(void **)M2C_FIELD(arg0, void **, 0x34);
                boxBoundsSigned(boxX(p) - 1, boxY(p) - 1, boxWidth(p) + 2, boxHeight(p) + 2, sprite);
            }
            {
                s32 offset = (M2C_FIELD(arg0, s32 *, 0x50) + 1) * 140;
                void *saved = gCur3DSpriteEngine;
                gCur3DSpriteEngine = g3DSpriteEngineMain;
                func_01ff9e44(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = g3DSpriteEngineSub;
                func_01ff9e44(func_ov000_0216cdec(16, M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = saved;
                sound = 0x10010;
            }
        }
    } else {
        if ((gKeyState[1] & 32) && ((selection = M2C_FIELD(arg0, s32 *, 0x50)) != 0 || (gKeyState[0] & 32))) {
            s32 n;
            if (selection)
                n = M2C_FIELD(arg0, s32 *, 0x50);
            else
                n = func_020cfb94();
            M2C_FIELD(arg0, s32 *, 0x50) = n - 1;
            func_02087ec0(M2C_FIELD(arg0, void **, 0x34), (s16)((s16)M2C_FIELD(arg0, u16 *, 0x50) + 3));
            {
                void *sprite = M2C_FIELD(arg0, void **, 0x38);
                void *p = *(void **)M2C_FIELD(arg0, void **, 0x34);
                boxBoundsSigned(boxX(p) - 1, boxY(p) - 1, boxWidth(p) + 2, boxHeight(p) + 2, sprite);
            }
            {
                s32 offset = (M2C_FIELD(arg0, s32 *, 0x50) + 1) * 140;
                void *saved = gCur3DSpriteEngine;
                gCur3DSpriteEngine = g3DSpriteEngineMain;
                func_01ff9e44(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = g3DSpriteEngineSub;
                func_01ff9e44(func_ov000_0216cdec(16, M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = saved;
                sound = 0x10010;
            }
        }
        if ((gKeyState[1] & 16) && (M2C_FIELD(arg0, s32 *, 0x50) < func_020cfb94() - 1 || (gKeyState[0] & 16))) {
            M2C_FIELD(arg0, s32 *, 0x50) = M2C_FIELD(arg0, s32 *, 0x50) == func_020cfb94() - 1 ? 0 : M2C_FIELD(arg0, s32 *, 0x50) + 1;
            func_02087ec0(M2C_FIELD(arg0, void **, 0x34), (s16)((s16)M2C_FIELD(arg0, u16 *, 0x50) + 3));
            {
                void *sprite = M2C_FIELD(arg0, void **, 0x38);
                void *p = *(void **)M2C_FIELD(arg0, void **, 0x34);
                boxBoundsSigned(boxX(p) - 1, boxY(p) - 1, boxWidth(p) + 2, boxHeight(p) + 2, sprite);
            }
            {
                s32 offset = (M2C_FIELD(arg0, s32 *, 0x50) + 1) * 140;
                void *saved = gCur3DSpriteEngine;
                gCur3DSpriteEngine = g3DSpriteEngineMain;
                func_01ff9e44(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = g3DSpriteEngineSub;
                func_01ff9e44(func_ov000_0216cdec(16, M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = saved;
                sound = 0x10010;
            }
        }
    }
    if (gKeyState[0] & 512) {
        M2C_FIELD(arg0, s32 *, 0x54) = M2C_FIELD(arg0, s32 *, 0x54) ? M2C_FIELD(arg0, s32 *, 0x54) - 1 : 1;
        mode = M2C_FIELD(arg0, s32 *, 0x54);
        func_020e3218(data_ov005_02220f1c);
        func_020814e4();
        if (mode == 0)
            func_02081590(func_020e3218(data_ov005_02220e5c), M2C_FIELD(gCur3DSpriteEngine, void **, 0x28));
        else
            func_02081590(func_020e3218(data_ov005_02220eec), M2C_FIELD(gCur3DSpriteEngine, void **, 0x28));
        func_02081528();
        func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, void **, 0x28), 2048, 8192);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
        sound = 0x10020;
    }
    if (gKeyState[0] & 256) {
        M2C_FIELD(arg0, s32 *, 0x54) = M2C_FIELD(arg0, s32 *, 0x54) == 1 ? 0 : M2C_FIELD(arg0, s32 *, 0x54) + 1;
        mode = M2C_FIELD(arg0, s32 *, 0x54);
        func_020e3218(data_ov005_02220f1c);
        func_020814e4();
        if (mode == 0)
            func_02081590(func_020e3218(data_ov005_02220e5c), M2C_FIELD(gCur3DSpriteEngine, void **, 0x28));
        else
            func_02081590(func_020e3218(data_ov005_02220eec), M2C_FIELD(gCur3DSpriteEngine, void **, 0x28));
        func_02081528();
        func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, void **, 0x28), 2048, 8192);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
        sound = 0x10020;
    }
    if (sound)
        PlaySoundEffect(sound);
    if (!(gKeyState[0] & 1))
        return;
    PlaySoundEffect(0x1000e);
    {
        void *p = M2C_FIELD(M2C_FIELD(func_01ffa770(data_ov005_02220d50), void **, 56), void **, 100);
        if ((u8)(M2C_FIELD(p, u8 *, 18) != 0))
            func_02087db8(p, 1);
    }
    {
        void *p = M2C_FIELD(M2C_FIELD(func_01ffa770(data_ov005_02220d50), void **, 60), void**, 100);
        if ((u8)(M2C_FIELD(p, u8 *, 18) != 0))
            func_02087db8(p, 1);
    }
    {
        void *p = M2C_FIELD(M2C_FIELD(func_01ffa770(data_ov005_02220d50), void **, 64), void **, 100);
        if ((u8)(M2C_FIELD(p, u8 *, 18) != 0))
            func_02087db8(p, 1);
    }
    func_02087e34(M2C_FIELD(arg0, void **, 0x34));
    func_01ffa6fc(arg0);
}
#pragma pop
