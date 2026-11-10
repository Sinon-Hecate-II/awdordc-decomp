/* 3 functions from 0x0221CAA0 to 0x0221D818 (ov005), found by ds-decomp. */
#include "common.h"
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
void ResultsScreenAnimate(void *arg0) {
u16 *volatile p0;
u16 *volatile p1;
u16 *volatile p2;
u16 *volatile p3;
u16 *volatile p4;
u16 *volatile p5;
u16 *volatile p6;
u16 *volatile p7;
u16 *volatile p8;
u16 *volatile p9;
u16 *volatile p10;
u16 *volatile p11;
u16 *volatile p12;
u16 *volatile p13;
s32 n,v,i; void *saved,*sprite; s16 y,x,z; s32 a,b;
M2C_FIELD(arg0,s32*,0x3c)++;
n=EaseInterpolate(0,0,16,M2C_FIELD(arg0,s32*,0x3c),32);
saved=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
if(M2C_FIELD(arg0,s32*,0x3c)==1) {p0=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p0=(*p0 & ~0xc0)|0x40;
p1=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p1=*p1 & ~ 1;
p2=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p2=*p2 & ~ 2;
p3=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p3=*p3 | 4;
p4=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p4=*p4 & ~ 8;
p5=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p5=*p5 & ~ 16;
p6=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p6=*p6 & ~ 32;
p7=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p7=*p7 & ~ 256;
p8=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p8=*p8 & ~ 512;
p9=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p9=*p9 & ~ 1024;
p10=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p10=*p10 | 2048;
p11=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p11=*p11 & ~ 4096;
p12=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p12=*p12 & ~ 8192;
}
M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x51)=n;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x52)=16-n;
gCur3DSpriteEngine=saved;
v=EaseInterpolate(4,192,0,M2C_FIELD(arg0,s32*,0x3c),32);
M2C_FIELD(arg0,s32*,0x40)=M2C_FIELD(arg0,s32*,0x48)=v;
v=EaseInterpolate(4,-32,0,M2C_FIELD(arg0,s32*,0x3c),32);
M2C_FIELD(arg0,s32*,0x44)=M2C_FIELD(arg0,s32*,0x4c)=v;
z=(s16)M2C_FIELD(arg0,s32*,0x44);
sprite=M2C_FIELD(func_01ffa770(data_ov005_02220d50),void**,60);
func_02088e84(sprite,160,z,160,z);
if((u8)(M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,18)!=0)){
y=M2C_FIELD(sprite,s16*,0x52); x=M2C_FIELD(sprite,s16*,0x50);
a=func_020aae10(sprite); b=func_020aae44(sprite);
func_02087d84(M2C_FIELD(sprite,void**,0x64),1,x,y,(u16)a,(u16)b); }
M2C_FIELD(sprite,s16*,0x34)=160; M2C_FIELD(sprite,s16*,0x36)=z;
if((u8)(M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,18)!=0)){
y=M2C_FIELD(sprite,s16*,0x52); x=M2C_FIELD(sprite,s16*,0x50);
a=func_020aae10(sprite); b=func_020aae44(sprite);
func_02087d84(M2C_FIELD(sprite,void**,0x64),1,x,y,(u16)a,(u16)b); }
{ void *sprite2; s16 y2,x2,z2; s32 a2,b2;
z2=(s16)M2C_FIELD(arg0,s32*,0x44);
sprite2=M2C_FIELD(func_01ffa770(data_ov005_02220d50),void**,64);
func_02088e84(sprite2,224,z2,224,z2);
if((u8)(M2C_FIELD(M2C_FIELD(sprite2,void**,0x64),u8*,18)!=0)){
y2=M2C_FIELD(sprite2,s16*,0x52); x2=M2C_FIELD(sprite2,s16*,0x50);
a2=func_020aae10(sprite2); b2=func_020aae44(sprite2);
func_02087d84(M2C_FIELD(sprite2,void**,0x64),1,x2,y2,(u16)a2,(u16)b2); }
M2C_FIELD(sprite2,s16*,0x34)=224; M2C_FIELD(sprite2,s16*,0x36)=z2;
if((u8)(M2C_FIELD(M2C_FIELD(sprite2,void**,0x64),u8*,18)!=0)){
y2=M2C_FIELD(sprite2,s16*,0x52); x2=M2C_FIELD(sprite2,s16*,0x50);
a2=func_020aae10(sprite2); b2=func_020aae44(sprite2);
func_02087d84(M2C_FIELD(sprite2,void**,0x64),1,x2,y2,(u16)a2,(u16)b2); }
}
if(M2C_FIELD(arg0,s32*,0x3c)!=32)return;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
gCur3DSpriteEngine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
p13=(u16*)(*(u8**)gCur3DSpriteEngine+18); *p13=*p13 & ~0xc0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x51)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x52)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,0x53)=0;
} gCur3DSpriteEngine=saved;
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
extern u16 *data_02101e84;
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
void func_0208fe30(s32);
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
        if ((data_02101e84[1] & 32) && ((selection = M2C_FIELD(arg0, s32 *, 0x50)) != 0 || (data_02101e84[0] & 32))) {
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
        if ((data_02101e84[1] & 16) && (M2C_FIELD(arg0, s32 *, 0x50) < func_020cfb94() - 1 || (data_02101e84[0] & 16))) {
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
    if (data_02101e84[0] & 512) {
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
    if (data_02101e84[0] & 256) {
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
        func_0208fe30(sound);
    if (!(data_02101e84[0] & 1))
        return;
    func_0208fe30(0x1000e);
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
