/* 12 functions from 0x0221A59C to 0x0221B56C (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_0221ab20(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_022200b0;
    func_01ffa3dc(&data_ov007_022200b0, 7);
}

void func_ov007_0221ab38(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_ov007_022200b0;
    func_01ffa9e4(&data_ov007_022200b0);
}

void func_ov007_0221ab4c(void) {
    M2C_UNK func_ov007_02219bd8();
    M2C_UNK func_ov007_02219d10();
    M2C_UNK func_ov007_02219f4c();
    M2C_UNK func_ov007_0221a018();
    M2C_UNK func_ov007_0221a104();
    func_ov007_02219f4c();
    func_ov007_0221a018();
    func_ov007_02219bd8();
    func_ov007_02219d10();
    func_ov007_0221a104();
}

void func_ov007_0221ab68(void) {
extern void **gCurrentMap;
extern void *data_027e00c4;
extern void *gCur3DSpriteEngine;
void *saved=gCur3DSpriteEngine;
void *p;
u32 x,y;
gCur3DSpriteEngine=data_027e00c4;
func_01ff9ce8(2);
func_020c12f8(M2C_FIELD(gCur3DSpriteEngine,s32 *,20),M2C_FIELD(gCur3DSpriteEngine,s32 *,40),1,14);
p=*gCurrentMap;
x=M2C_FIELD(p,u16 *,0x5144);
y=M2C_FIELD(p,u16 *,0x5146);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),s16 *,60)=-(64-((s32)(x*4)>>1));
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),s16 *,68)=-(80-((s32)(y*4)>>1));
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;
gCur3DSpriteEngine=saved;
func_ov007_0221ab4c();
}

void func_ov007_0221ac20(s32 a,s32 b,s8 c,s16 d) {
extern void **gCurrentMap;
s32 func_ov007_0221bd74(s32,s32);
s32 func_ov007_0221bd00(s32,s32,s32);
void *p=*gCurrentMap;
s32 t;
M2C_FIELD((u8 *)p+2*(a+M2C_FIELD((u8 *)p+2*b,u16 *,0x3758)),s16 *,0xa10)=d;
p=*gCurrentMap;
M2C_FIELD((u8 *)p+(a+M2C_FIELD((u8 *)p+2*b,u16 *,0x3758)),s8 *,0x1420)=c;
t=func_ov007_0221bd74(a,b);
if(t<0)return;
if(func_ov007_0221bd00(a,b,t)!=0)return;
func_ov007_0221bcc0(a,b);
}

s32 func_ov007_0221acac(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    s32 func_ov007_0221ad24(M2C_UNK, M2C_UNK, s32);
    s32 func_ov007_0221b030(M2C_UNK, M2C_UNK, s32, s32);
    s32 func_ov007_0221b6c8();
    s32 func_ov007_0221b704(M2C_UNK, M2C_UNK);
    if ((arg2 == func_ov007_0221b6c8()) && (arg3 == func_ov007_0221b704(arg0, arg1))) {
        return 2;
    }
    if (func_ov007_0221ad24(arg0, arg1, arg2) == 0) {
        return 0;
    }
    if (func_ov007_0221b030(arg0, arg1, arg2, arg3) != 0) {
        return 1;
    }
    return 0;
}

s32 func_ov007_0221b24c(s32 a,s32 b,s32 c,s32 d) {
extern void **gCurrentMap;
s32 func_ov007_0221b6c8();
s32 func_ov007_0221b704(s32,s32);
void *p;
if(a>=0 && b>=0) {
p=*gCurrentMap;
if(a<M2C_FIELD(p,u16 *,0x5144)&&b<M2C_FIELD(p,u16 *,0x5146)) goto valid;
}
return 0;
valid:
if(c!=func_ov007_0221b6c8(a,b))return 0;
return (u8)(d==func_ov007_0221b704(a,b));
}

/* Flood-fills a connected 30x30 region of tiles currently matching oldTile/oldDir,
   converting each one to newTile/newDir (and extending to its neighbours). */
s32 func_ov007_0221b2cc(s32 x, s32 y, M2C_UNK newTile, M2C_UNK newDir, s32 oldTile, s32 oldDir) {
    s32 func_ov007_0221b0a4(s32, s32, M2C_UNK, M2C_UNK, s32);
    s32 func_ov007_0221b24c(s32, s32, s32, s32);
    s32 rightX;
    s32 bottomY;
    s32 topY;
    s32 nextY;
    s32 iLeft;
    s32 iRight;
    s32 iUp;
    s32 iDown;
    s32 leftX;

    if (func_ov007_0221b24c(x, y, oldTile, oldDir) == 0) {
        return 0;
    }
    if (func_ov007_0221b0a4(x, y, newTile, newDir, 0) == 0) {
        return 0;
    }
    leftX = x;
    rightX = x;
    topY = y;
    bottomY = y;
    iLeft = x - 1;
    if (iLeft >= 0) {
loop_5:
        if ((func_ov007_0221b24c(iLeft, y, oldTile, oldDir) != 0) && (func_ov007_0221b0a4(iLeft, y, newTile, newDir, 0) != 0)) {
            leftX = iLeft;
            iLeft -= 1;
            if (iLeft >= 0) {
                goto loop_5;
            }
        }
    }
    iRight = x + 1;
    if (iRight < 0x1E) {
loop_9:
        if ((func_ov007_0221b24c(iRight, y, oldTile, oldDir) != 0) && (func_ov007_0221b0a4(iRight, y, newTile, newDir, 0) != 0)) {
            rightX = iRight;
            iRight += 1;
            if (iRight < 0x1E) {
                goto loop_9;
            }
        }
    }
    iUp = y - 1;
    if (iUp >= 0) {
loop_13:
        if ((func_ov007_0221b24c(x, iUp, oldTile, oldDir) != 0) && (func_ov007_0221b0a4(x, iUp, newTile, newDir, 0) != 0)) {
            topY = iUp;
            iUp -= 1;
            if (iUp >= 0) {
                goto loop_13;
            }
        }
    }
    iDown = y + 1;
    if (iDown < 0x1E) {
loop_17:
        if ((func_ov007_0221b24c(x, iDown, oldTile, oldDir) != 0) && (func_ov007_0221b0a4(x, iDown, newTile, newDir, 0) != 0)) {
            bottomY = iDown;
            iDown += 1;
            if (iDown < 0x1E) {
                goto loop_17;
            }
        }
    }
    if (leftX <= rightX) {
        do {
            func_ov007_0221b2cc(leftX, y - 1, newTile, newDir, oldTile, oldDir);
            func_ov007_0221b2cc(leftX, y + 1, newTile, newDir, oldTile, oldDir);
            leftX += 1;
        } while (leftX <= rightX);
    }
    if (topY <= bottomY) {
        do {
            func_ov007_0221b2cc(x - 1, topY, newTile, newDir, oldTile, oldDir);
            func_ov007_0221b2cc(x + 1, topY, newTile, newDir, oldTile, oldDir);
            nextY = topY + 1;
            topY = nextY;
        } while (nextY <= bottomY);
    }
    return 1;
}

