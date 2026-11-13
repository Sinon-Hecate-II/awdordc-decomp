/* 18 functions from 0x020E24C0 to 0x020E34BC (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 low:4; u8 high:4; } MenuNibble;
typedef struct { u32 x:9; u32 y:9; u32 layer:8; u32 rest:6; } MenuSpriteFlags;
extern M2C_UNK data_0212c6a8, data_0212d1e8, gSpriteDesc64x32, data_0212c5c4;
extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
static inline void MenuSpriteOrigin(void *p,u16 x,u16 y) { M2C_FIELD(p,MenuSpriteFlags*,0x40).x=x; M2C_FIELD(p,MenuSpriteFlags*,0x40).y=y; }
static inline void MenuSetFrame(void *p,u16 frame) { M2C_FIELD(p,u16*,0x3e)=frame; }
static inline void MenuSetResource(void *p,void *resource) { M2C_FIELD(p,void**,0x44)=resource; }

extern s32 data_02168fd0[];
extern M2C_UNK data_0212d6c8, data_0212d6d4, data_0212d6e0, data_0212d6f0, data_0212d704, data_0212d714, data_0212d724, data_0212d734;

#pragma opt_propagation off
void func_020e24c0(s32 arg0) {
void *CreateSpriteObject(void*,s32); void *MemAlloc(s32);
void *func_020ab1c4(s32); s32 func_020aab24(void*,s32,s32,u8,s32);
s32 func_02088e84(void*,s16,s16,s16,s32); s32 func_020aae10(void*); s32 func_020aae44(void*);
s32 func_02087d84(void*,s32,s16,s16,s32,s32); s32 func_020aad18(void*);
void *func_0208931c(void*); void *func_0208bc24(void*); s32 func_0208b698(void*,void*); s32 func_02088da8(void*); void func_020e4c64(void);
void *obj=CreateSpriteObject(&data_0212c6a8,arg0); void *saved; void *p; void *q;
if(!obj)return;
M2C_FIELD(obj,void**,0)=&data_0212d1e8;
M2C_FIELD(obj,s32*,0x34)=2; M2C_FIELD(obj,s32*,0x38)=0;M2C_FIELD(obj,s32*,0x3c)=0;
M2C_FIELD(obj,u8*,0x40)=0;M2C_FIELD(obj,u8*,0x41)=0;M2C_FIELD(obj,u8*,0x42)=0;M2C_FIELD(obj,u8*,0x43)=4;M2C_FIELD(obj,u8*,0x44)=0;
M2C_FIELD(obj,u16*,0x46)=0x3a8;M2C_FIELD(obj,u16*,0x48)=0;M2C_FIELD(obj,u16*,0x4a)=0;M2C_FIELD(obj,u16*,0x4c)=0x708;
M2C_FIELD(obj,void**,0x50)=0;M2C_FIELD(obj,void**,0x54)=0;M2C_FIELD(obj,void**,0x58)=0;M2C_FIELD(obj,void**,0x5c)=0;M2C_FIELD(obj,void**,0x60)=0;M2C_FIELD(obj,void**,0x64)=0;
q=MemAlloc(18);
if(q){M2C_FIELD(q,u8*,0)=4;M2C_FIELD(q,u8*,1)=0;M2C_FIELD(q,u16*,2)=0;M2C_FIELD(q,u16*,4)=0;M2C_FIELD(q,u16*,6)=1;M2C_FIELD(q,u16*,8)=0;M2C_FIELD(q,u16*,10)=1;M2C_FIELD(q,u16*,12)=1;M2C_FIELD(q,u16*,14)=0;M2C_FIELD(q,u16*,16)=0;M2C_FIELD(q,u16*,2)=M2C_FIELD(q,u16*,4);}
M2C_FIELD(obj,void**,0x68)=q;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;

{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,80)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,80),0,832,3,1);
p=M2C_FIELD(obj,void**,80);func_02088e84(p,192,160,192,192);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,80);M2C_FIELD(q,s16*,0x34)=192;M2C_FIELD(q,s16*,0x36)=192;
func_020aad18(M2C_FIELD(obj,void**,80));
q=M2C_FIELD(obj,void**,80);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|((u32)((u16)(M2C_FIELD(q,MenuNibble*,0x59).low+2)<<24)>>6);M2C_FIELD(q,u8*,0x5a)=0;
}
{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,84)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,84),1,848,3,0);
p=M2C_FIELD(obj,void**,84);func_02088e84(p,192,160,192,192);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,84);M2C_FIELD(q,s16*,0x34)=192;M2C_FIELD(q,s16*,0x36)=192;
func_020aad18(M2C_FIELD(obj,void**,84));
q=M2C_FIELD(obj,void**,84);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|((u32)((u16)(M2C_FIELD(q,MenuNibble*,0x59).low+2)<<24)>>6);M2C_FIELD(q,u8*,0x5a)=0;
}
{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,88)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,88),2,864,3,0);
p=M2C_FIELD(obj,void**,88);func_02088e84(p,224,160,224,192);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,88);M2C_FIELD(q,s16*,0x34)=224;M2C_FIELD(q,s16*,0x36)=192;
func_020aad18(M2C_FIELD(obj,void**,88));

}
{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,92)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,92),42,880,3,0);
p=M2C_FIELD(obj,void**,92);func_02088e84(p,96,164,-159,164);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,92);M2C_FIELD(q,s16*,0x34)=-159;M2C_FIELD(q,s16*,0x36)=164;
func_020aad18(M2C_FIELD(obj,void**,92));

}
M2C_FIELD(obj,void**,0x60)=func_0208931c(obj);p=M2C_FIELD(obj,void**,0x60);
M2C_FIELD(p,s16*,0x34)=156;M2C_FIELD(p,s16*,0x36)=192;
M2C_FIELD(p,MenuSpriteFlags*,0x40).x=64;
M2C_FIELD(p,MenuSpriteFlags*,0x40).y=32;
func_02088e84(M2C_FIELD(obj,void**,0x60),156,160,156,192);
M2C_FIELD(M2C_FIELD(obj,void**,0x60),u16*,0x3c)=0;
q=M2C_FIELD(obj,void**,0x60);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|0x180000;
M2C_FIELD(M2C_FIELD(obj,void**,0x60),u16*,0x3e)=0x388;M2C_FIELD(M2C_FIELD(obj,void**,0x60),void**,0x44)=&gSpriteDesc64x32;
gCur3DSpriteEngine=g3DSpriteEngineSub;
p=func_0208bc24(obj);M2C_FIELD(obj,void**,0x64)=p;M2C_FIELD(p,u16*,0x3e)=0x140;
q=M2C_FIELD(obj,void**,0x64);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|0x180000;
func_0208b698(M2C_FIELD(obj,void**,0x64),&data_0212c5c4);func_02088da8(M2C_FIELD(obj,void**,0x64));
gCur3DSpriteEngine=saved;func_020e4c64();
}
#pragma opt_propagation reset
void func_020e2a2c(s32 arg0) {
void *CreateSpriteObject(void*,s32); void *MemAlloc(s32);
void *func_020ab1c4(s32); s32 func_020aab24(void*,s32,s32,u8,s32);
s32 func_02088e84(void*,s16,s16,s16,s32); s32 func_020aae10(void*); s32 func_020aae44(void*);
s32 func_02087d84(void*,s32,s16,s16,s32,s32); s32 func_020aad18(void*);
void *func_0208931c(void*); void *func_0208bc24(void*); s32 func_0208b698(void*,void*); s32 func_02088da8(void*); void func_020e4c64(void);
void *obj=CreateSpriteObject(&data_0212c6a8,arg0); void *p; void *q; void *saved;
if(!obj)return;
M2C_FIELD(obj,void**,0)=&data_0212d1e8;
M2C_FIELD(obj,s32*,0x34)=2; M2C_FIELD(obj,s32*,0x38)=1;M2C_FIELD(obj,s32*,0x3c)=0;
M2C_FIELD(obj,u8*,0x40)=0;M2C_FIELD(obj,u8*,0x41)=0;M2C_FIELD(obj,u8*,0x42)=0;M2C_FIELD(obj,u8*,0x43)=4;M2C_FIELD(obj,u8*,0x44)=0;
M2C_FIELD(obj,u16*,0x46)=0x3a8;M2C_FIELD(obj,u16*,0x48)=0;M2C_FIELD(obj,u16*,0x4a)=0;M2C_FIELD(obj,u16*,0x4c)=0x708;
M2C_FIELD(obj,void**,0x50)=0;M2C_FIELD(obj,void**,0x54)=0;M2C_FIELD(obj,void**,0x58)=0;M2C_FIELD(obj,void**,0x5c)=0;M2C_FIELD(obj,void**,0x60)=0;M2C_FIELD(obj,void**,0x64)=0;
q=MemAlloc(18);
if(q){M2C_FIELD(q,u8*,0)=4;M2C_FIELD(q,u8*,1)=0;M2C_FIELD(q,u16*,2)=0;M2C_FIELD(q,u16*,4)=0;M2C_FIELD(q,u16*,6)=1;M2C_FIELD(q,u16*,8)=0;M2C_FIELD(q,u16*,10)=1;M2C_FIELD(q,u16*,12)=1;M2C_FIELD(q,u16*,14)=0;M2C_FIELD(q,u16*,16)=0;M2C_FIELD(q,u16*,2)=M2C_FIELD(q,u16*,4);}
M2C_FIELD(obj,void**,0x68)=q;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;

{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,80)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,80),0,832,3,1);
p=M2C_FIELD(obj,void**,80);func_02088e84(p,192,160,192,192);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,80);M2C_FIELD(q,s16*,0x34)=192;M2C_FIELD(q,s16*,0x36)=192;
func_020aad18(M2C_FIELD(obj,void**,80));
q=M2C_FIELD(obj,void**,80);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|((u32)((u16)(M2C_FIELD(q,MenuNibble*,0x59).low+2)<<24)>>6);M2C_FIELD(q,u8*,0x5a)=0;
}
{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,84)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,84),1,848,3,0);
p=M2C_FIELD(obj,void**,84);func_02088e84(p,192,160,192,192);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,84);M2C_FIELD(q,s16*,0x34)=192;M2C_FIELD(q,s16*,0x36)=192;
func_020aad18(M2C_FIELD(obj,void**,84));
q=M2C_FIELD(obj,void**,84);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|((u32)((u16)(M2C_FIELD(q,MenuNibble*,0x59).low+2)<<24)>>6);M2C_FIELD(q,u8*,0x5a)=0;
}
{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,88)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,88),2,864,3,0);
p=M2C_FIELD(obj,void**,88);func_02088e84(p,224,160,224,192);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,88);M2C_FIELD(q,s16*,0x34)=224;M2C_FIELD(q,s16*,0x36)=192;
func_020aad18(M2C_FIELD(obj,void**,88));

}
{void *p,*q; s16 y,x; s32 w,v;
M2C_FIELD(obj,void**,92)=func_020ab1c4((s32)obj);
func_020aab24(M2C_FIELD(obj,void**,92),42,880,3,0);
p=M2C_FIELD(obj,void**,92);func_02088e84(p,96,164,-159,164);
if(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12))v=1;else v=0;
if(v&255){ y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
q=M2C_FIELD(obj,void**,92);M2C_FIELD(q,s16*,0x34)=-159;M2C_FIELD(q,s16*,0x36)=164;
func_020aad18(M2C_FIELD(obj,void**,92));

}
p=func_0208931c(obj);M2C_FIELD(obj,void**,0x60)=p;
{s16 x=156,y=192;M2C_FIELD(p,s16*,0x34)=x;M2C_FIELD(p,s16*,0x36)=y;}
M2C_FIELD(p,MenuSpriteFlags*,0x40).x=64;
M2C_FIELD(p,MenuSpriteFlags*,0x40).y=32;
func_02088e84(M2C_FIELD(obj,void**,0x60),156,160,156,192);
M2C_FIELD(M2C_FIELD(obj,void**,0x60),u16*,0x3c)=0;
q=M2C_FIELD(obj,void**,0x60);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|0x180000;
M2C_FIELD(M2C_FIELD(obj,void**,0x60),u16*,0x3e)=0x388;M2C_FIELD(M2C_FIELD(obj,void**,0x60),void**,0x44)=&gSpriteDesc64x32;
gCur3DSpriteEngine=g3DSpriteEngineSub;
p=func_0208bc24(obj);M2C_FIELD(obj,void**,0x64)=p;M2C_FIELD(p,u16*,0x3e)=0x140;
q=M2C_FIELD(obj,void**,0x64);M2C_FIELD(q,u32*,0x40)=(M2C_FIELD(q,u32*,0x40)&~0x3fc0000)|0x180000;
func_0208b698(M2C_FIELD(obj,void**,0x64),&data_0212c5c4);func_02088da8(M2C_FIELD(obj,void**,0x64));
gCur3DSpriteEngine=saved;func_020e4c64();
}

void *func_020e2f9c(void *arg0) {
 M2C_UNK MemFree();
 M2C_UNK func_020e4ca0();
 extern M2C_UNK data_0212d1e8;
 M2C_FIELD(arg0,M2C_UNK **,0)=&data_0212d1e8;
 if(M2C_FIELD(arg0,void **,0x68)!=0)MemFree(M2C_FIELD(arg0,void **,0x68));
 func_020e4ca0();
 MemFree(arg0);
 return arg0;
}

void *func_020e2fd4(void *arg0) {
    M2C_UNK MemFree();
    M2C_UNK func_020e4ca0();
    extern M2C_UNK data_0212d1e8;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0212d1e8;
    if (M2C_FIELD(arg0, s32 *, 0x68) != 0) {
        MemFree();
    }
    func_020e4ca0();
    return arg0;
}

void func_020e3004(void) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    extern M2C_UNK data_0212d678;
    SetFileDirectory(&data_0212d678);
}

s32 func_020e3018(s32 arg0) {
 extern u8 data_0212d600[];
 s32 i;
 u8 *p;
 p=data_0212d600;
 i=0;
 do {
 if(arg0==M2C_FIELD(p,s16*,0))return M2C_FIELD(p,s32*,4);
 i++;
 p+=8;
 }while(i<15);
 return 0;
}

M2C_UNK *func_020e304c(void) {
    extern M2C_UNK data_0212d68c;
    return &data_0212d68c;
}

/* Creates one menu text sprite for `owner` at (x, y), configures its tile and
 * style, clips and draws it, and stores it in *outSprite.  When `value` is not
 * -1 the sprite is also given that value to display. */
void CreateMenuTextSprite(void **outSprite, s32 x, s32 y, M2C_UNK kind, s32 resourceId, u8 style, s32 value, s32 owner, u8 secondLayer) {
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088e84(void *, s16, s16, s16, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, s32, u8, s32);
    M2C_UNK func_020aad18(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    M2C_UNK func_020ab150(void *, u16);
    void *func_020ab1c4(s32);
    void *sprite;
    s16 fh1, fw1;
    s16 yPos, xPos;
    s32 fw;
    s16 fh2, fw2;
    s32 fw3;
    s32 hasFrame1, hasFrame2;
    u8 second;

    *outSprite = func_020ab1c4(owner);
    if (secondLayer != 0) {
        second = 1;
    } else {
        second = 0;
    }
    func_020aab24(*outSprite, kind, resourceId, style, (s32) second);
    yPos = y;
    xPos = x;
    sprite = *outSprite;
    func_02088e84(sprite, xPos, yPos, xPos, (s32) yPos);
    if (M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0) {
        hasFrame1 = 1;
    } else {
        hasFrame1 = 0;
    }
    if (hasFrame1 & 0xFF) {
        fh1 = M2C_FIELD(sprite, s16 *, 0x52);
        fw1 = M2C_FIELD(sprite, s16 *, 0x50);
        fw = func_020aae10(sprite);
        func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, fw1, fh1, (s32)(u16) fw, (s32)(u16) func_020aae44(sprite));
    }
    M2C_FIELD(sprite, s16 *, 0x34) = xPos;
    M2C_FIELD(sprite, s16 *, 0x36) = yPos;
    if (M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0) {
        hasFrame2 = 1;
    } else {
        hasFrame2 = 0;
    }
    if (hasFrame2 & 0xFF) {
        fh2 = M2C_FIELD(sprite, s16 *, 0x52);
        fw2 = M2C_FIELD(sprite, s16 *, 0x50);
        fw3 = func_020aae10(sprite);
        func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, fw2, fh2, (s32)(u16) fw3, (s32)(u16) func_020aae44(sprite));
    }
    func_02088d94(*outSprite);
    func_020aad18(*outSprite);
    if (value == -1) {
        return;
    }
    func_020ab150(*outSprite, (u16) value);
}

u8 GetLanguage(void) {
    extern u8 data_02168f8c;
    return data_02168f8c;
}

void func_020e31f0(s32 arg0) {
 extern u8 data_02168f8c;
 data_02168f8c=1;
 if(arg0==1 || arg0==2 || arg0==5)data_02168f8c=arg0;
}

M2C_UNK *GetLocalizedFileName(s32 arg0) {
    M2C_UNK StringFormat(M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_0212d69c;
    extern M2C_UNK data_0212d6a0;
    extern M2C_UNK data_0212d6a8;
    extern M2C_UNK data_0212d6b0;
    extern M2C_UNK data_0212d6b8;
    extern M2C_UNK data_0212d6c0;
    extern M2C_UNK data_02168f90;
    u32 temp_r0;

    if (arg0 == 0) {
        return NULL;
    }
    temp_r0 = GetLanguage();
    switch (temp_r0) {
    default:
        break;
    case 0:
        StringFormat(&data_02168f90, &data_0212d69c, arg0);
        break;
    case 1:
        StringFormat(&data_02168f90, &data_0212d6a0, arg0);
        break;
    case 2:
        StringFormat(&data_02168f90, &data_0212d6a8, arg0);
        break;
    case 3:
        StringFormat(&data_02168f90, &data_0212d6b0, arg0);
        break;
    case 4:
        StringFormat(&data_02168f90, &data_0212d6b8, arg0);
        break;
    case 5:
        StringFormat(&data_02168f90, &data_0212d6c0, arg0);
        break;
    }
    return &data_02168f90;
}

M2C_UNK *func_020e32e8(s32 arg0) {
 M2C_UNK *r;
 u8 old;
 old=((s32 (*)(void))GetLanguage)();
 if(old==0)func_020e31f0(1);
 r=GetLocalizedFileName(arg0);
 func_020e31f0(old);
 return r;
}

void func_020e3320(void) {
 extern s32 data_02168fd0[];
 s32 i=0;
 do { data_02168fd0[i]=0; i++; } while(i<5);
}

void func_020e3344(void) {
 void func_020e3400(void);
 M2C_UNK SetFileDirectory();
 s32 func_02080e30();
 void OpenNarcArchive();
 s32 func_020815a8();
 void CloseNarcArchive();
 func_020e3400();
 SetFileDirectory(&data_0212d6c8);
 data_02168fd0[0]=func_02080e30(GetLocalizedFileName((s32)&data_0212d6d4),1);
 data_02168fd0[1]=func_02080e30(GetLocalizedFileName((s32)&data_0212d6e0),1);
 SetFileDirectory(&data_0212d6f0);
 OpenNarcArchive(GetLocalizedFileName((s32)&data_0212d704));
 data_02168fd0[2]=func_020815a8(GetLocalizedFileName((s32)&data_0212d714));
 data_02168fd0[3]=func_020815a8(GetLocalizedFileName((s32)&data_0212d724));
 data_02168fd0[4]=func_020815a8(GetLocalizedFileName((s32)&data_0212d734));
 CloseNarcArchive();
}

void func_020e3400(void) {
 void HeapFreeBlock(s32);
 s32 i=0;
 do {
 if(data_02168fd0[i]!=0)HeapFreeBlock(data_02168fd0[i]);
 data_02168fd0[i]=0;
 i++;
 }while(i<5);
}

s32 func_020e3438(s32 arg0) {
    extern s32 data_02168fd0[];
    return data_02168fd0[arg0];
}

void func_020e3448(void) {
    s32 func_02006a10(M2C_UNK);
    s32 func_02006a24(M2C_UNK);
    s32 func_02006bec(M2C_UNK, s32, M2C_UNK);
    s32 func_0202a424(s32, s32, M2C_UNK);
    M2C_UNK func_0202a4d4(s32, M2C_UNK);
    extern s32 data_02168fe4;
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r4_2;

    temp_r4 = func_02006a24(0);
    temp_r4_2 = (func_02006a10(0) - temp_r4) & ~7;
    temp_r0 = func_0202a424(func_02006bec(0, temp_r4_2, 8), temp_r4_2, 0);
    data_02168fe4 = temp_r0;
    func_0202a4d4(temp_r0, 0);
}

u16 func_020e349c(void) {
 u16 a,b;
 a=*(volatile u16*)0x04000208;
 *(volatile u16*)0x04000208=0;
 b=*(volatile u16*)0x04000208;
 *(volatile u16*)0x04000208=a;
 return b;
}

