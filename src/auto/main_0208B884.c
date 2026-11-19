/* 33 functions from 0x0208B884 to 0x0208C830 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"


typedef struct { u32 low:16, mode:3, a:1, b:1, c:1, d:2, e:2, high:6; } Flags0208;
typedef struct { u32 low:10, middle:11, high:11; } Flags0208B;

void func_0208b884(void *sprite) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteEngineSub;
    extern u16 gSpriteDesc64x32[];
    void func_0209b9a8(s32, s32, s32, u16, s32);
    void DS3D_AddSpriteQuad(s32, s32, u32, u16 *);

    void *saved = gCur3DSpriteEngine;
    s32 screen;
    s32 x, y;
    for (screen = 0; screen < 2; screen++) {
        void *engine = *(screen == 0 ? &g3DSpriteEngineMain : &g3DSpriteEngineSub);
        u32 screenMode;
        u32 boundary;
        s32 length;
        u16 tile;
        u16 scroll;

        gCur3DSpriteEngine = engine;
        screenMode = ((u32)M2C_FIELD(sprite, u8 *, 0x48) << 28) >> 29;
        if ((screenMode == 0 && engine != g3DSpriteEngineMain) ||
            (screenMode == 1 && engine != g3DSpriteEngineSub) ||
            (screenMode == 3 && engine != saved)) continue;

        boundary = ((u32)**(u16 **)engine << 17) >> 30;
        tile = (u16)((((((u32)M2C_FIELD(sprite, u16 *, 0x3e) << 5) + 0x400) >> 5) >> boundary & 0x3ff) | 0x2000 | M2C_FIELD(sprite, u16 *, 0x3c));
        scroll = M2C_FIELD(sprite, u16 *, 0x5a);
        x = M2C_FIELD(sprite, s16 *, 0x34) + 1 - scroll;
        y = M2C_FIELD(sprite, s16 *, 0x36) + 15;
        length = M2C_FIELD(sprite, u16 *, 0x58);
        if (M2C_FIELD(sprite, u8 *, 0x5c) < M2C_FIELD(sprite, u8 *, 0x5d)) {
            M2C_FIELD(sprite, u8 *, 0x5c)++;
        } else {
            M2C_FIELD(sprite, u16 *, 0x5a) = (scroll + 1) & 0x1ff;
        }

        if (length > 256) {
            func_0209b9a8((u16)(x & 0x1ff), (u8)y, 256, tile, 1);
            boundary = ((u32)**(u16 **)gCur3DSpriteEngine << 17) >> 30;
            func_0209b9a8((u16)((x + 256) & 0x1ff), (u8)y, (u16)(length - 256), (u16)(tile + (0x3ff & (64 >> (s32)boundary))), 1);
        } else {
            func_0209b9a8((u16)(x & 0x1ff), (u8)y, (u16)length, tile, 1);
            func_0209b9a8((u16)((x + 256) & 0x1ff), (u8)y, (u16)(u32)length, tile, 1);
        }

        boundary = ((u32)**(u16 **)gCur3DSpriteEngine << 17) >> 30;
        tile = (u16)((((((u32)M2C_FIELD(sprite, u16 *, 0x3e) << 5) >> 5) >> boundary) & 0x3ff) |
               (((M2C_FIELD(sprite, u32 *, 0x40) << 6) >> 24) << 12) |
               M2C_FIELD(sprite, u16 *, 0x3c));
        x = M2C_FIELD(sprite, s16 *, 0x34);
        y = M2C_FIELD(sprite, s16 *, 0x36);
        DS3D_AddSpriteQuad((u16)(x & 0x1ff), (u8)y, tile, gSpriteDesc64x32);
        DS3D_AddSpriteQuad((u16)((x + 64) & 0x1ff), (u8)y, tile, gSpriteDesc64x32);
        DS3D_AddSpriteQuad((u16)((x + 128) & 0x1ff), (u8)y, tile, gSpriteDesc64x32);
        DS3D_AddSpriteQuad((u16)((x + 192) & 0x1ff), (u8)y, tile, gSpriteDesc64x32);
    }
    gCur3DSpriteEngine = saved;
}

void func_0208bc00(void) {
    M2C_UNK func_0208b778();
    func_0208b778();
}

void func_0208bc0c(void) {
    M2C_UNK func_0208b878();
    func_0208b878();
}

void func_0208bc18(void) {
    M2C_UNK func_0208b868();
    func_0208b868();
}

void func_0208bc24(M2C_UNK arg0) {
    void *func_0208b630();
    extern M2C_UNK data_02102760;
    void *var_r0;

    var_r0 = CreateSpriteFromClass(&data_02102760, arg0);
    if (var_r0 != NULL) {
        var_r0 = func_0208b630();
    }
    M2C_FIELD(var_r0, u8 *, 0x48) = (u8) ((M2C_FIELD(var_r0, u8 *, 0x48) & ~0xE) | 2);
}

/* Reset a newly allocated 3D sprite object: point it at the plain sprite class,
 * clear its position, attributes and timers, bind it to whichever engine is
 * current (main = screen 0, sub = screen 1) and drop its sprite and callbacks. */
M2C_UNK Init3DSpriteObject(void *obj){
extern void *g3DSpriteObjectClass;extern void *gCur3DSpriteEngine;extern void *g3DSpriteEngineMain;
u8 isMain;SpriteFlags *flags=(SpriteFlags *)((char *)obj+0x44);SpriteTimer *timer=(SpriteTimer *)((char *)obj+0x48);
M2C_FIELD(obj,void **,DS3D_SPRITE_CLASS)=&g3DSpriteObjectClass;
M2C_FIELD(obj,s32 *,0x34)=0;M2C_FIELD(obj,s32 *,0x38)=0;M2C_FIELD(obj,s32 *,0x3c)=0;M2C_FIELD(obj,s32 *,0x40)=0x1000;
M2C_FIELD(obj,u32 *,0x44)&=~0xffff;
isMain=gCur3DSpriteEngine==g3DSpriteEngineMain;
flags->screen=isMain!=1;flags->a=0;flags->closeOnInput=0;flags->yAttr=0;flags->drawMode=0;flags->easing=0;timer->delay=0;timer->elapsed=0;
M2C_FIELD(obj,s32 *,0x4c)=0;
M2C_FIELD(obj,s32 *,0x50)=0;
M2C_FIELD(obj,s32 *,0x54)=0;
M2C_FIELD(obj,s32 *,0x58)=0;
M2C_FIELD(obj,s32 *,0x5c)=0;
M2C_FIELD(obj,s32 *,0x60)=0;
M2C_FIELD(obj,s32 *,0x64)=0;
M2C_FIELD(obj,s32 *,0x68)=0;
M2C_FIELD(obj,s32 *,0x6c)=0;
M2C_FIELD(obj,s32 *,0x70)=0;
}

/* Load an animated sprite's assets from the effect NARC named by assetName: build
   the asset's .tex/.ctx/.cl paths, open the archive once and hand the paths to
   LoadAnimatedSpriteAssets (destOffset is the frame data's VRAM offset, frameCount
   its number of frames, loadGraphics says whether to load the texture and palette). */
void LoadAnimatedSpriteAssetsFromNarc(void *sprite, M2C_UNK assetName, s32 destOffset, u16 frameCount, u8 loadGraphics) {
    M2C_UNK StringCopy(M2C_UNK *, s32);
    M2C_UNK StringAppend(M2C_UNK *, M2C_UNK *);
    s32 BuildNarcPath(M2C_UNK);
    void LoadAnimatedSpriteAssets(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u8);
    void OpenEffectNarcArchive(M2C_UNK);
    void CloseEffectNarcArchive(void);
    extern M2C_UNK sSpriteTexExtension, sSpriteCtxExtension, sSpriteClExtension;
    M2C_UNK texPath[8], ctxPath[8], clPath[8];
    s32 narcPath;
    narcPath = BuildNarcPath(assetName);
    StringCopy(texPath, narcPath);
    StringAppend(texPath, &sSpriteTexExtension);
    StringCopy(ctxPath, narcPath);
    StringAppend(ctxPath, &sSpriteCtxExtension);
    StringCopy(clPath, narcPath);
    StringAppend(clPath, &sSpriteClExtension);
    OpenEffectNarcArchive(assetName);
    LoadAnimatedSpriteAssets(sprite, (M2C_UNK)texPath, (M2C_UNK)ctxPath, (M2C_UNK)clPath, destOffset, frameCount, loadGraphics);
    CloseEffectNarcArchive();
}

/* Load a compressed animated sprite's assets from the asset's NARC: build the
 * asset's .cg/.ctc/.cl paths, open the archive once and hand the paths to
 * LoadCompressedSpriteAssets (destOffset is the frame data's VRAM offset,
 * frameCount its number of frames, loadGraphics says whether to load the
 * graphics and palette). */
void LoadCompressedSpriteAssetsFromNarc(M2C_UNK sprite, M2C_UNK assetName, s32 destOffset, u16 frameCount, u8 loadGraphics) {
    M2C_UNK StringCopy(M2C_UNK *, s32);
    M2C_UNK StringAppend(M2C_UNK *, M2C_UNK *);
    s32 BuildNarcPath(M2C_UNK);
    void LoadCompressedSpriteAssets(void *, M2C_UNK, M2C_UNK, M2C_UNK *, u32, u16, u8);
    void OpenEffectNarcArchive(M2C_UNK);
    void CloseEffectNarcArchive(void);
    extern M2C_UNK sSpriteCgExtension, sSpriteCtcExtension, sSpriteAnimClExtension;
    M2C_UNK gfxPath[8], animPath[8], palPath[8];
    s32 narcPath;
    narcPath = BuildNarcPath(assetName);
    StringCopy(gfxPath, narcPath);
    StringAppend(gfxPath, &sSpriteCgExtension);
    StringCopy(animPath, narcPath);
    StringAppend(animPath, &sSpriteCtcExtension);
    StringCopy(palPath, narcPath);
    StringAppend(palPath, &sSpriteAnimClExtension);
    OpenEffectNarcArchive(assetName);
    LoadCompressedSpriteAssets(sprite, (M2C_UNK)gfxPath, (M2C_UNK)animPath, (M2C_UNK)palPath, destOffset, frameCount, loadGraphics);
    CloseEffectNarcArchive();
}

/* Set up a display object's buffers from three prepared lists. */
void LoadAnimatedSpriteAssets(void *obj, M2C_UNK list1, M2C_UNK list2, M2C_UNK list3, s32 value, u16 count, u8 flag) {
    s32 LoadFileToBuffer(M2C_UNK, M2C_UNK);
    s32 func_02081070(M2C_UNK, M2C_UNK);
    M2C_UNK func_0208143c(M2C_UNK, s32, M2C_UNK);
    void *CreateSpriteAnim(s32, M2C_UNK, M2C_UNK);

    s32 size;
    void *sub;
    void *ptr;

    size = count << 5;
    M2C_FIELD(obj, s32 *, 0x54) = LoadFileToBuffer(list2, 1);
    if (flag != 0) {
        M2C_FIELD(obj, s32 *, 0x50) = func_02081070(list1, 1);
        func_0208143c(list3, size, 0x20);
    }
    sub = CreateSpriteAnim(M2C_FIELD(obj, s32 *, 0x54), 0xD, 6);
    M2C_FIELD(obj, void **, 0x4C) = sub;
    SetSpriteAnimFrame(sub, 0);
    M2C_FIELD(M2C_FIELD(obj, void **, 0x4C), s32 *, 0x30) = (s32) M2C_FIELD(obj, s32 *, 0x50);
    M2C_FIELD(M2C_FIELD(obj, void **, 0x4C), s32 *, 0x28) = value;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x4C), s32 *, 0x2C) = size;
    ptr = M2C_FIELD(obj, void **, 0x4C);
    M2C_FIELD(ptr, u8 *, 0x22) = (u8) (M2C_FIELD(ptr, u8 *, 0x22) | 0x40);
    M2C_FIELD(obj, s32 *, 0x44) = (s32) ((M2C_FIELD(obj, s32 *, 0x44) & ~0xFC000000) | (func_02091ac0(M2C_FIELD(obj, void **, 0x4C)) << 0x1A));
    M2C_FIELD(obj, s32 *, 0x48) = (s32) ((M2C_FIELD(obj, s32 *, 0x48) & 0xFFE003FF) | ((u32) (func_02091a84(M2C_FIELD(obj, void **, 0x4C)) << 0x15) >> 0xB));
    M2C_FIELD(obj, s32 *, 0x44) = (s32) ((M2C_FIELD(obj, s32 *, 0x44) & ~0xC00000) | 0x400000);
}

void LoadCompressedSpriteAssets(void *obj, M2C_UNK a, M2C_UNK b, M2C_UNK *c,u32 value,u16 count,u8 flag){
s32 LoadFileToBuffer(M2C_UNK,M2C_UNK);s32 func_02081070(M2C_UNK,M2C_UNK);M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *,s32,M2C_UNK);void *CreateSpriteAnim(s32,M2C_UNK,M2C_UNK);
u16 packed;void *sub,*ptr;
packed=(u16)((0x3ff&(value>>5))+(u16)(count<<12));
M2C_FIELD(obj,s32 *,0x54)=LoadFileToBuffer(b,1);
if(flag){M2C_FIELD(obj,s32 *,0x50)=func_02081070(a,1);LoadFileToSpriteBuffer(c,(count+16)<<5,32);}
sub=CreateSpriteAnim(M2C_FIELD(obj,s32 *,0x54),13,2);
M2C_FIELD(obj,void **,0x4c)=sub;SetSpriteAnimFrame(sub,0);
M2C_FIELD(M2C_FIELD(obj,void **,0x4c),s32 *,0x30)=M2C_FIELD(obj,s32 *,0x50);
M2C_FIELD(M2C_FIELD(obj,void **,0x4c),s32 *,0x28)=packed;
ptr=M2C_FIELD(obj,void **,0x4c);M2C_FIELD(ptr,u8 *,0x22)|=0x40;
M2C_FIELD(obj,s32 *,0x44)=(M2C_FIELD(obj,s32 *,0x44)&~0xfc000000)|(func_02091ac0(M2C_FIELD(obj,void **,0x4c))<<26);
M2C_FIELD(obj,s32 *,0x48)=(M2C_FIELD(obj,s32 *,0x48)&0xffe003ff)|((u32)(func_02091a84(M2C_FIELD(obj,void **,0x4c))<<21)>>11);
M2C_FIELD(obj,s32 *,0x44)=(M2C_FIELD(obj,s32 *,0x44)&~0xc00000)|0x800000;
}

void SetAnimatedSpriteFrame(void *arg0) {
    M2C_UNK SetSpriteAnimFrame(s32);
    s32 func_02091a84(s32);
    s32 func_02091ac0(s32);
    SetSpriteAnimFrame(M2C_FIELD(arg0, s32 *, 0x4C));
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) ((M2C_FIELD(arg0, s32 *, 0x44) & ~0xFC000000) | (func_02091ac0(M2C_FIELD(arg0, s32 *, 0x4C)) << 0x1A));
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) ((M2C_FIELD(arg0, s32 *, 0x48) & 0xFFE003FF) | ((u32) (func_02091a84(M2C_FIELD(arg0, s32 *, 0x4C)) << 0x15) >> 0xB));
}

void func_0208c0d0(void *arg0, u8 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), u8 *, 0x21) = arg1;
}

/* Compute an interpolation factor from the object's mode/position fields and store it as a byte at +0x4C/0x21. */
void func_0208c0dc(void *obj) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32); void func_0208c0d0(void *, u8);
    u16 n = ((Flags0208B *)((char *)obj + 0x48))->middle;
    u16 mode = ((Flags0208 *)((char *)obj + 0x44))->e;
    u16 pos = ((Flags0208B *)((char *)obj + 0x48))->high;
    s32 half = n >> 1; s32 v = 31;
    switch (mode) {
        case 1: if (pos < half) v = EaseInterpolate(0, 0, 31, pos, half); break;
        case 2: if (pos > half) v = EaseInterpolate(0, 31, 0, pos - half, half); break;
        case 3: half = (s32)((s32)n + ((u32)(s32)n >> 31)) >> 1; if (pos < half) v = EaseInterpolate(0, 0, 31, pos, half); else v = EaseInterpolate(0, 31, 0, pos - half, half); break;
    }
    func_0208c0d0(obj, (u8)v);
}

s32 func_0208c1dc(void *arg0) {
    s32 func_02091a70(s32);
    return func_02091a70(M2C_FIELD(arg0, s32 *, 0x4C));
}

s32 GetObjectTileX(void *arg0) {
    M2C_UNK Divide(s32, M2C_UNK);
    return Divide(M2C_FIELD(arg0, s32 *, 0x34), 0x300);
}

s32 GetObjectTileY(void *arg0) {
    M2C_UNK Divide(s32, M2C_UNK);
    return Divide(M2C_FIELD(arg0, s32 *, 0x38), 0x300);
}

s32 func_0208c214(void *arg0) {
    s32 func_02094758();
    M2C_UNK func_020d4704();
    M2C_UNK (*temp_r1)(void *);
    u32 temp_r0;
    temp_r1 = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x68);
    if (temp_r1 != NULL) temp_r1(arg0);
    temp_r0 = (u32)(M2C_FIELD(arg0, u32 *, 0x44) << 12) >> 31;
    if (temp_r0 == 0) return temp_r0;
    func_020d4704();
    return func_02094758();
}

/* Updates one 3D sprite object: runs its fade and per-frame callback, then draws
 * it on each screen its flags select; frees it when drawing fails or the object
 * is flagged to close on an input. */
void UpdateSpriteObject(void *obj) {
extern u16 *gKeyState; extern u8 *gTouchState;
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*g3DSpriteEngineMain;
void DeleteSpriteObject(void *); s32 DrawSprite3D(s32,void *,s32,s32); s32 DrawSprite2D(s32,u16,u16);
SpriteFlags *f=(SpriteFlags *)((char *)obj+0x44);
SpriteTimer *g=(SpriteTimer *)((char *)obj+0x48);
void *savedEngine,*engine; s32 pass; s32 xyz[3]; u16 spriteX,spriteY,extraY; void (*callback)(void *);
if(g->delay) { --g->delay; return; }
if(g->elapsed && f->closeOnInput && ((*gKeyState & (KEY_A|KEY_B|KEY_START|KEY_X|KEY_Y)) || gTouchState[0x14])) {DeleteSpriteObject(obj);return;}
if((u16)f->easing) func_0208c0dc(obj);
callback=M2C_FIELD(obj,void (**)(void *),0x6c); if(callback) callback(obj);
savedEngine=gCur3DSpriteEngine;
for(pass=0;pass<2;pass++){
if(pass==0) engine=g3DSpriteEngineMain; else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
if(f->screen==0 && engine!=g3DSpriteEngineMain) continue;
if(f->screen==1 && engine!=g3DSpriteEngineSub) continue;
if(f->screen==3 && engine!=savedEngine) continue;
switch((u16)f->drawMode) {
case 1:
xyz[0]=M2C_FIELD(obj,s32 *,0x34); xyz[1]=M2C_FIELD(obj,s32 *,0x38);xyz[2]=M2C_FIELD(obj,s32 *,0x3c);
if(!DrawSprite3D(M2C_FIELD(obj,s32 *,0x4c),xyz,M2C_FIELD(obj,s32 *,0x40),(M2C_FIELD(obj,u32 *,0x44)&0xffff))) {DeleteSpriteObject(obj);return;} break;
case 2:
spriteX=(u16)(M2C_FIELD(obj,s32 *,0x34)&0x1ff); spriteY=M2C_FIELD(obj,s32 *,0x38)&0xff;extraY=(u16)f->yAttr;
if(extraY) spriteY|=0x400;
if(!DrawSprite2D(M2C_FIELD(obj,s32 *,0x4c),spriteX,spriteY)) {DeleteSpriteObject(obj);return;} break;
}
}
gCur3DSpriteEngine=savedEngine; ++g->elapsed;
}

s32 func_0208c49c(void *arg0) {
    void Sprite_ClearHandle(s32 *);
    s32 func_02094770();
    M2C_UNK func_020d472c();
    M2C_UNK HeapFreeBlock(s32);
    s32 (*temp_r1)(void *);
    s32 var_r0;
    if (M2C_FIELD(arg0, s32 *, 0x4C) != 0) Sprite_ClearHandle(M2C_FIELD(arg0, s32 *, 0x4C));
    if (M2C_FIELD(arg0, s32 *, 0x50) != 0) HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x50));
    if (M2C_FIELD(arg0, s32 *, 0x54) != 0) HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x54));
    var_r0 = (u32)(M2C_FIELD(arg0, u32 *, 0x44) << 12) >> 31;
    if (var_r0 != 0) {
        func_020d472c();
        var_r0 = func_02094770();
    }
    temp_r1 = M2C_FIELD(arg0, s32 (**)(void *), 0x70);
    if (temp_r1 == NULL) return var_r0;
    return temp_r1(arg0);
}

void func_0208c504(void) {
    M2C_UNK func_0208c214();
    func_0208c214();
}

void func_0208c510(void) {
    M2C_UNK func_0208c49c();
    func_0208c49c();
}

void func_0208c51c(void) {
    ((void (*)())UpdateSpriteObject)();
}

void CreateAnimatedSpriteObject(M2C_UNK arg0) {
    s32 CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    M2C_UNK Init3DSpriteObject();
    extern M2C_UNK data_02102790;
    if (CreateSpriteFromClass(&data_02102790, arg0) == 0) {
        return;
    }
    Init3DSpriteObject();
}

void func_0208c54c(M2C_UNK arg0) {
    s32 CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK Init3DSpriteObject();
    extern M2C_UNK data_02102790;
    if (CreateSpriteObject(&data_02102790, arg0) == 0) {
        return;
    }
    Init3DSpriteObject();
}

/* Load a sprite's uncompressed graphics from the effect NARC: the asset's .tex
 * goes into the texture bank at textureOffset, its .cl palette into palette
 * slot paletteSlot.  Returns the texture size. */
s32 LoadSpriteGraphics(M2C_UNK assetName, s32 textureOffset, s32 paletteSlot) {
    M2C_UNK StringCopy(M2C_UNK *, s32);
    M2C_UNK StringAppend(M2C_UNK *, M2C_UNK *);
    s32 func_020813c4(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208143c(M2C_UNK, s32, M2C_UNK);
    s32 BuildNarcPath();
    void OpenEffectNarcArchive(M2C_UNK);
    void CloseEffectNarcArchive(void);
    extern M2C_UNK sSpriteTextureExtension, sSpritePaletteExtension;
    M2C_UNK texPath[8], palPath[8];
    s32 narcPath, textureSize;

    narcPath = BuildNarcPath();
    StringCopy(texPath, narcPath);
    StringAppend(texPath, &sSpriteTextureExtension);
    StringCopy(palPath, narcPath);
    StringAppend(palPath, &sSpritePaletteExtension);
    OpenEffectNarcArchive(assetName);
    textureSize = func_020813c4(texPath, textureOffset);
    func_0208143c((M2C_UNK) palPath, paletteSlot << 5, 0x20);
    CloseEffectNarcArchive();
    return textureSize;
}

/* Load a compressed sprite asset's graphics and palette from the effect NARC:
 * build the asset's .cg and .cl paths, open the archive once, decompress the
 * graphics to the 3D sprite engine's texture area at destOffset and put the palette
 * into the sprite buffer behind the sixteen reserved palette slots, one per frame.
 * Returns the loaded graphics handle. */
s32 LoadCompressedSpriteGraphics(M2C_UNK assetName, s32 destOffset, s32 frameCount) {
    M2C_UNK StringCopy(M2C_UNK *, s32);
    M2C_UNK StringAppend(M2C_UNK *, M2C_UNK *);
    s32 LoadDecompressedFileTo(M2C_UNK *, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, s32, M2C_UNK);
    s32 BuildNarcPath();
    void OpenEffectNarcArchive(M2C_UNK);
    void CloseEffectNarcArchive(void);
    extern M2C_UNK sCompressedSpriteCgExtension;
    extern M2C_UNK sCompressedSpriteClExtension;
    extern void *gCur3DSpriteEngine;
    M2C_UNK gfxPath[8], palPath[8];
    s32 narcPath;
    s32 gfx;

    narcPath = BuildNarcPath();
    StringCopy(gfxPath, narcPath);
    StringAppend(gfxPath, &sCompressedSpriteCgExtension);
    StringCopy(palPath, narcPath);
    StringAppend(palPath, &sCompressedSpriteClExtension);
    OpenEffectNarcArchive(assetName);
    gfx = LoadDecompressedFileTo(gfxPath, M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_TEXTURE) + destOffset);
    LoadFileToSpriteBuffer(palPath, (frameCount + 0x10) << 5, DS3D_PALETTE_BYTES);
    CloseEffectNarcArchive();
    return gfx;
}

void OpenEffectNarcArchive(M2C_UNK arg0) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK StringCopy(M2C_UNK *, s32);
    M2C_UNK StringAppend(M2C_UNK *, M2C_UNK *);
    M2C_UNK OpenNarcArchive(M2C_UNK *);
    extern M2C_UNK data_02102878;
    extern M2C_UNK data_02102880;
    extern u8 data_021577e0;
    M2C_UNK sp0[8];
    u8 temp_r3;

    temp_r3 = data_021577e0;
    data_021577e0 = temp_r3 + 1;
    if (temp_r3 != 0) {
        return;
    }
    StringCopy(sp0, arg0);
    StringAppend(sp0, &data_02102878);
    SetFileDirectory(&data_02102880);
    OpenNarcArchive(sp0);
}

void CloseEffectNarcArchive(void) {
    M2C_UNK CloseNarcArchive();
    extern u8 data_021577e0;
    u32 temp_r1;

    temp_r1 = data_021577e0 - 1;
    data_021577e0 = (u8) temp_r1;
    if (temp_r1 & 0xFF) {
        return;
    }
    CloseNarcArchive();
}

u8 func_0208c724(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02102790;
    u8 var_r0;

    if (FindObjectByClass(&data_02102790) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0208c748(void)
{
  M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
  M2C_UNK *new_var;
  extern M2C_UNK data_02102790;
  new_var = &data_02102790;
  DeleteSpriteObjectsOfClass(new_var);
}

void func_0208c75c(void *arg0, s32 arg1) {
    extern void *gCur3DSpriteEngine;
    u16 *src;
    s32 i;
    src = (u16 *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + ((arg1 << 5) & ~1));
    for (i = 0; i < 15; i++) {
        ((u16 *)arg0)[i + 0x2B] = src[i + 1];
    }
}

void func_0208c79c(void *arg0, s16 arg1) {
    s32 i;
    for (i = 0; i < 15; i++) {
        ((s16 *)arg0)[i + 0x1C] = arg1;
    }
}

void func_0208c7b8(void *arg0, s8 arg1) {
    extern void *gCur3DSpriteEngine;
    s32 i;
    u16 *dest;
    if (arg1 == 0) {
        dest = (u16 *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + ((M2C_FIELD(arg0, u8 *, 0x34) << 5) & ~1));
        for (i = 0; i < 15; i++) {
            dest[i + 1] = ((u16 *)arg0)[i + 0x1C];
        }
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = arg1;
    M2C_FIELD(arg0, s8 *, 0x35) = 3;
}

