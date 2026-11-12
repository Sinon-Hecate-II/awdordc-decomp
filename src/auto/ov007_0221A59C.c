/* 12 functions from 0x0221A59C to 0x0221B56C (ov007), found by ds-decomp. */
#include "common.h"
extern u8 gHeapObjectVTable[];
static inline void InitTextDescriptor(u8 *sp) {
sp[32]=(u8)((u8)(sp[32]&~1)&~30);sp[32]=(sp[32]&~224)|64;
sp[40]&=~224;
M2C_FIELD(sp,void **,0)=gHeapObjectVTable;sp[4]=0;
M2C_FIELD(sp,u16 *,18)=0x140;sp[20]=8;sp[21]=8;sp[22]=1;sp[23]=8;sp[24]=8;
sp[33]=0;M2C_FIELD(sp,s32 *,36)=0;sp[41]=0;

}
struct TileNeighbors_0221 { s16 values[24]; };

void func_ov007_0221a59c(void) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;extern void **gCurrentMap;
extern u8 gHeapObjectVTable[],gSpriteDesc16x16[],gSpriteDesc16x32[],gSpriteDesc32x16[],data_027e00b4[];
extern s32 data_ov007_02221e08;extern u32 gFrameCounter;
void AddSprite(u16,u8,u16,void*,s32);void func_020a9774(void*,s32,s32,s32,s32);
s32 func_ov007_02211ffc(s32);s32 func_ov007_02211f00(void);s32 func_ov007_02211f40(void);s32 func_ov007_0221204c(void);
void func_020c1acc(s32,s32,s32,s32);void SetTextSpriteValue(void*,s32);void DrawTextSprite(void*);
void DrawTileRow(u16,u8,u16,u16,s32);s32 func_ov007_0221216c(s32);
u8 sp[44];void *saved;s32 i,x,tile,mode,width,height;
saved=gCur3DSpriteEngine;
M2C_FIELD(sp,void **,0)=gHeapObjectVTable;sp[4]=0;
M2C_FIELD(sp,u16 *,18)=0x140;sp[20]=8;sp[21]=8;sp[22]=1;sp[23]=8;sp[24]=8;
sp[33]=0;M2C_FIELD(sp,s32 *,36)=0;sp[41]=0;
sp[32]=(u8)((u8)(sp[32]&~1)&~30);sp[32]=(sp[32]&~224)|64;

sp[40]&=~224;
gCur3DSpriteEngine=g3DSpriteEngineSub;
for(i=0,x=0x85,tile=0x158;i<4;x+=0x1d,tile+=4,i++){
AddSprite((u16)(x&0x1ff),0x9e,(u16)(((u16)((i+5)<<12)|0x400)|(tile&0x3ff)),gSpriteDesc16x16,0);
func_020a9774(sp,x+0x18,0xa6,3,func_ov007_02211ffc(i+1));
}
width=M2C_FIELD(*gCurrentMap,u16 *,0x5144);height=M2C_FIELD(*gCurrentMap,u16 *,0x5146);
func_020c1acc(64-((width*4)>>1),80-((height*4)>>1),0x80,1);
AddSprite(8,157,(u16)((0x3ff&(360>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(9<<12)),gSpriteDesc16x16,15);
AddSprite(72,141,(u16)((0x3ff&(364>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(10<<12)),gSpriteDesc16x32,15);
mode=func_ov007_02211f00();
switch(mode){
case 0:
AddSprite(24,160,(u16)((0x3ff&(372>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(12<<12)),gSpriteDesc32x16,15);
AddSprite(88,160,(u16)((0x3ff&(380>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(11<<12)),gSpriteDesc32x16,15);
func_020a9774(sp,0x38,0x92,4,50-func_ov007_02211ffc(func_ov007_02211f40()));
func_020a9774(sp,0x78,0x92,3,99-func_ov007_0221204c());
break;
case 1:
AddSprite(24,160,(u16)((0x3ff&(372>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(11<<12)),gSpriteDesc32x16,15);
AddSprite(88,160,(u16)((0x3ff&(380>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(12<<12)),gSpriteDesc32x16,15);
func_020a9774(sp,0x38,0x92,3,50-func_ov007_02211ffc(func_ov007_02211f40()));
func_020a9774(sp,0x78,0x92,4,99-func_ov007_0221204c());
break;
}
M2C_FIELD(sp,u16 *,18)=0x14c;sp[33]=3;
SetTextSpriteValue(sp,M2C_FIELD(*gCurrentMap,s16 *,0x52c2));
M2C_FIELD(sp,s16 *,6)=0x1e;M2C_FIELD(sp,s16 *,8)=0xb5;DrawTextSprite(sp);
SetTextSpriteValue(sp,M2C_FIELD(*gCurrentMap,s16 *,0x52c4));
M2C_FIELD(sp,s16 *,6)=0x47;M2C_FIELD(sp,s16 *,8)=0xb5;DrawTextSprite(sp);
DrawTileRow((u16)((((0x70-data_ov007_02221e08)>>1)+6)&0x1ff),0xff,(u16)data_ov007_02221e08,(u16)((0x3ff&(0x1cc>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xe000),15);
if(func_ov007_0221216c(-1)!=0){
if((gFrameCounter&63)<48){AddSprite(192,180,(u16)((0x3ff&(396>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(13<<12)),data_027e00b4,15);}
}else{AddSprite(192,180,(u16)((0x3ff&(428>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(13<<12)),data_027e00b4,15);}
gCur3DSpriteEngine=saved;
}

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
extern void *g3DSpriteEngineSub;
extern void *gCur3DSpriteEngine;
void *saved=gCur3DSpriteEngine;
void *p;
u32 x,y;
gCur3DSpriteEngine=g3DSpriteEngineSub;
Clear3DSpriteLayer(2);
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

void Map_SetTileAndRefresh(s32 a,s32 b,u16 c,u16 d) {
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

s32 Map_CanPlaceTile(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
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

s32 func_ov007_0221ad24(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    return 0;
}

s32 func_ov007_0221b030(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_020c1a80(s32);
    s32 func_ov007_0221b6c8(s32, s32);
    s32 func_ov007_0221202c(s32, s32);
    s32 func_ov007_0221204c(void);
    if (func_020c1a80(arg2) == 0) {
        goto ret1;
    }
    if (arg2 == 0xF) {
        if (func_ov007_0221202c(0, arg3) > 0) {
            return 0;
        }
    }
    if (func_ov007_0221204c() < 0x63) {
        goto ret1;
    }
    if (func_020c1a80(func_ov007_0221b6c8(arg0, arg1)) == 0) {
        return 0;
    }
ret1:
    return 1;
}

/* Paint tile/direction (tile, dir) at cell (x,y) unless the editor forbids it,
 * then optionally re-evaluate the eight neighbouring cells and redraw the 4x4
 * cells around the edited one. */
s32 Map_PaintTile(s32 x, s32 y, s32 tile, s32 dir, u8 refresh) {
    s32 func_0207f460(s32);
    void func_02076980(s32, s32, s32, s32);
    void func_0207843c(s32, s32, s32, s32);
    s32 Map_CanPlaceTile(s32, s32, s32, s32);
    void Map_SetTileAndRefresh(s32, s32, u16, u16);
    void func_ov007_0221b688(s32, s32);
    s32 func_ov007_0221b754(s32, s32);
    s32 func_ov007_0221bad0(s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov007_0221f574[];

    s32 encodedTile;
    s32 graphic;
    struct TileNeighbors_0221 neighbors;
    s32 result;
    s32 i;
    u8 *offset;

    encodedTile = tile | (dir << 5);
    graphic = func_0207f460(encodedTile);

    result = Map_CanPlaceTile(x, y, tile, dir);
    if (result != 1) {
        return result;
    }
    switch (tile) {
    case 0x1b:
        if (func_ov007_0221b754(x, y) != 0) {
            encodedTile = 0x3b;
            graphic = 0x146;
        }
        break;
    case 0x1c:
        if (func_ov007_0221b754(x, y) != 0) {
            encodedTile = 0x3c;
            graphic = 0x166;
        }
        break;
    case 0x0d:
        if (func_ov007_0221bad0(x, y) != 0) {
            encodedTile = 0x0e;
            graphic = 0x25;
        }
        break;
    }

    Map_SetTileAndRefresh(x, y, (u16)encodedTile, (u16)graphic);

    if (refresh != 0) {

    neighbors = *(const struct TileNeighbors_0221 *)data_ov007_0221f574;
    offset = (u8 *)&neighbors;
    i = 0;
    do {
        s32 nx = x + *(s16 *)offset;
        s32 ny = y + *(s16 *)(offset + 2);
        if (nx >= 0 && ny >= 0) {
            void *map = *gCurrentMap;
            if (nx < (s32) M2C_FIELD(map, u16 *, 0x5144) && ny < (s32) M2C_FIELD(map, u16 *, 0x5146)) {
                func_ov007_0221b688(nx, ny);
            }
        }
        i++;
        offset += 6;
    } while (i < 8);

    func_02076980(x - 2, y - 2, x + 2, y + 2);
    func_0207843c(x - 2, y - 2, x + 2, y + 2);

    }
    return 1;
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
    s32 Map_PaintTile(s32, s32, M2C_UNK, M2C_UNK, u8);
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
    if (Map_PaintTile(x, y, newTile, newDir, 0) == 0) {
        return 0;
    }
    leftX = x;
    rightX = x;
    topY = y;
    bottomY = y;
    iLeft = x - 1;
    if (iLeft >= 0) {
loop_5:
        if ((func_ov007_0221b24c(iLeft, y, oldTile, oldDir) != 0) && (Map_PaintTile(iLeft, y, newTile, newDir, 0) != 0)) {
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
        if ((func_ov007_0221b24c(iRight, y, oldTile, oldDir) != 0) && (Map_PaintTile(iRight, y, newTile, newDir, 0) != 0)) {
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
        if ((func_ov007_0221b24c(x, iUp, oldTile, oldDir) != 0) && (Map_PaintTile(x, iUp, newTile, newDir, 0) != 0)) {
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
        if ((func_ov007_0221b24c(x, iDown, oldTile, oldDir) != 0) && (Map_PaintTile(x, iDown, newTile, newDir, 0) != 0)) {
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

