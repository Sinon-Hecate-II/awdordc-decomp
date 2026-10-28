/* 3 functions from 0x0221CAA0 to 0x0221D818 (ov005), found by ds-decomp. */
#include "common.h"
static inline void boxBoundsSigned(s32 x,s32 y,s32 w,s32 h,void *p) { M2C_FIELD(p,s16*,0x34)=x; M2C_FIELD(p,s16*,0x36)=y; M2C_FIELD(p,s32*,0x40)=(((M2C_FIELD(p,s32*,0x40)&~511)|(w&(-512U>>23)))&0xfffc01ff)|((u32)(h<<23)>>14); }
static inline s32 boxWidth(void *p) { return p ? M2C_FIELD(p,u16*,4):0; }
static inline s32 boxHeight(void *p) { return p ? M2C_FIELD(p,u16*,6):0; }
static inline s32 boxX(void *p) { return p ? M2C_FIELD(p,s16*,0):0; }
static inline s32 boxY(void *p) { return p ? M2C_FIELD(p,s16*,2):0; }
static inline void boxPosition(void *p,s32 x,s32 y) { M2C_FIELD(p,s16*,0x34)=x; M2C_FIELD(p,s16*,0x36)=y; }
typedef struct { u32 width:9,height:9,other:14; } BoxSizeBits;
static inline void boxSize(void *p,u32 w,u32 h) { M2C_FIELD(p,u32*,0x40)=((M2C_FIELD(p,u32*,0x40)&~511)|(w&(-512U>>23)))&0xfffc01ff | ((h<<23)>>14); }

static inline void boxBounds(s32 x,s32 y,u32 w,u32 h,void *p) { boxPosition(p,x,y); boxSize(p,w,h); }
void func_ov005_0221cff8(void *arg0) {
void *func_01ffa770(void*);void *func_020896f0(void*);s32 func_020cfb94();s32 func_020ae22c();
extern u8 data_ov005_02220d50[];
s32 i,y;void *sprite,*p;s32 width,height;
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
extern void *data_027e00c8;
extern void *data_027e00c4;
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
                gCur3DSpriteEngine = data_027e00c8;
                func_01ff9e44(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = data_027e00c4;
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
                gCur3DSpriteEngine = data_027e00c8;
                func_01ff9e44(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = data_027e00c4;
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
                gCur3DSpriteEngine = data_027e00c8;
                func_01ff9e44(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = data_027e00c4;
                func_01ff9e44(func_ov000_0216cdec(16, M2C_FIELD((u8 *)*gCurrentMap + offset, u8 *, 0x67c1)), 960, 32);
                gCur3DSpriteEngine = saved;
                sound = 0x10010;
            }
        }
    }
    if (data_02101e84[0] & 512) {
        M2C_FIELD(arg0, s32 *, 0x54) = M2C_FIELD(arg0, s32 *, 0x54) ? M2C_FIELD(arg0, s32 *, 0x54) - 1 : 1;
        {
            s32 mode = M2C_FIELD(arg0, s32 *, 0x54);
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
    }
    if (data_02101e84[0] & 256) {
        M2C_FIELD(arg0, s32 *, 0x54) = M2C_FIELD(arg0, s32 *, 0x54) == 1 ? 0 : M2C_FIELD(arg0, s32 *, 0x54) + 1;
        {
            s32 mode = M2C_FIELD(arg0, s32 *, 0x54);
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
