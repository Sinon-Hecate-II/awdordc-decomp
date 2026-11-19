/* 52 functions from 0x02098BD4 to 0x02099B18 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
typedef union { u32 word; u16 half[2]; u8 byte[4]; } Unk996Row;

typedef struct { s32 values[12]; } Unk02098BD4Table;
extern Unk02098BD4Table data_020f36bc;

/* Indexes the CO face layout table by expression (0..11, in three-step groups)
 * and by the face's variant flag, and returns the face tile record chosen. */
s32 func_02098bd4(M2C_UNK expr, u8 variant) {
Unk02098BD4Table table=data_020f36bc;
s32 i=0;
switch(expr) {
case 0: i=0; break;
case 1: i=2; break;
case 2: i=4; break;
case 3: i=4; break;
case 4: i=4; break;
case 5: i=6; break;
case 6: i=6; break;
case 7: i=6; break;
case 8: i=8; break;
case 9: i=8; break;
case 10: i=8; break;
case 11: i=10; break;
}
if(variant) i++;
return table.values[i];
}

void func_02098cb8(M2C_UNK arg0,s32 arg1,u32 arg2,M2C_UNK arg3,u8 arg4,s32 arg5) {
M2C_UNK AddSprite(u16,u8,M2C_UNK,s32,s32);
s32 func_02098bd4(M2C_UNK,u8);
s32 result=func_02098bd4(arg0,arg4);
arg2=(u8)arg2;
arg1 &= 0x1ff;
AddSprite((u16)arg1,arg2,arg3,result,arg5);
}

M2C_UNK func_02098d08(M2C_UNK arg0, s32 arg1) {
    M2C_UNK SetFileDirectory();
    M2C_UNK OpenNarcArchive(M2C_UNK *);
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    s32 GetFaceTexturePath(M2C_UNK);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern M2C_UNK data_02103274, data_02103280;
    if (GetFaceTexturePath(arg0) == 0) return;
    SetFileDirectory();
    OpenNarcArchive(&data_02103274);
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_02103280), arg1);
    CloseNarcArchive();
}

M2C_UNK func_02098d48(M2C_UNK arg0, u16 arg1) {
    M2C_UNK SetFileDirectory();
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, s32, M2C_UNK);
    s32 GetFaceTexturePath(M2C_UNK);
    extern M2C_UNK data_02103288;
    if (GetFaceTexturePath(arg0) == 0) return;
    SetFileDirectory();
    LoadFileToSpriteBuffer(&data_02103288, arg1 << 5, 0x20);
}

void LoadFaceTextureAndPalette(M2C_UNK arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02098d08(M2C_UNK, s32);
    M2C_UNK func_02098d48(M2C_UNK, u16);
    extern void *gCur3DSpriteEngine;
    func_02098d08(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg1);
    func_02098d48(arg0, (u16) (arg2 + 0x10));
}

M2C_UNK *GetFaceSpriteTemplate(void) {
    extern M2C_UNK data_020f3650;
    return &data_020f3650;
}

void func_02098dc0(s32 arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
 M2C_UNK AddSprite(u16,u8,M2C_UNK,s32,s32);
 s32 result = (s32)GetFaceSpriteTemplate();
 arg1 = (u8)arg1;
 arg0 &= 0x1FF;
 AddSprite((u16)arg0,arg1,arg2,result,arg3);
}

void func_02098e04(void *arg0, u32 arg1, s32 arg2) {
    M2C_UNK Hide3DSprite();
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    Hide3DSprite();
}

u8 IsFaceSpriteLoaded(void *);
/* Assigns face id `faceId` to a CO face sprite: resets its tile row and quad
 * template and, when a face is loaded, reloads its texture and palette on every
 * display engine it targets. */
void SetFaceSpriteFace(void *face, s32 faceId) {
extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
void *oldEngine; void *engine; s32 bank; u32 screen;
M2C_FIELD(face,u8*,FACE_SPRITE_FACE)=faceId;
M2C_FIELD(face,u8*,FACE_SPRITE_TILE_ROW)=3;
M2C_FIELD(face,M2C_UNK **,DS3D_SPRITE_TEMPLATE)=GetFaceSpriteTemplate();
if (!IsFaceSpriteLoaded(face)) return;
oldEngine=gCur3DSpriteEngine; bank=0;
do {
if(bank==0) engine=g3DSpriteEngineMain; else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
screen=((u32)M2C_FIELD(face,u8*,FACE_SPRITE_SCREEN)<<28)>>29;
if ((screen!=0 || engine==g3DSpriteEngineMain) && (screen!=1 || engine==g3DSpriteEngineSub) && (screen!=3 || engine==oldEngine))
LoadFaceTextureAndPalette(faceId,M2C_FIELD(face,u16*,0x3e)<<5,(u16)((M2C_FIELD(face,u32*,FACE_SPRITE_TILE)<<6)>>24));
bank += 1;
} while(bank<2);
gCur3DSpriteEngine=oldEngine;
}

void SetFaceSpriteExpression(void *arg0, u8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x59) = arg1;
}

/* Reload the palette of the face sprite's texture on every display engine it
 * is drawn on and, when no expression is set, darken its 32 colours by 6 steps. */
void RefreshFaceSpritePalette(void *face) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    M2C_UNK LoadFacePalette(M2C_UNK, u16);
    u8 IsFaceSpriteLoaded(void *);
    M2C_UNK FadePaletteTowardsBlack(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void *savedEngine;
    s32 bank;
    void *engine;
    u32 screen;
    s32 zero = 0;
    s32 steps = 10;

    if (!IsFaceSpriteLoaded(face)) return;
    savedEngine = gCur3DSpriteEngine;
    bank = 0;
    do {
        if (bank == 0) engine = g3DSpriteEngineMain; else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        screen = (u32)(M2C_FIELD(face, u8 *, FACE_SPRITE_SCREEN) << 28) >> 29;
        if (((screen != 0) || (engine == g3DSpriteEngineMain)) &&
            ((screen != 1) || (engine == g3DSpriteEngineSub)) &&
            ((screen != 3) || (engine == savedEngine))) {
            LoadFacePalette((M2C_UNK)M2C_FIELD(face, u8 *, FACE_SPRITE_FACE),
                (u16)(((M2C_FIELD(face, u32 *, FACE_SPRITE_TILE) << 6) >> 24) + 0x10));
            if (M2C_FIELD(face, u8 *, FACE_SPRITE_EXPRESSION) == 0) {
                FadePaletteTowardsBlack(
                    (M2C_UNK)(M2C_FIELD(gCur3DSpriteEngine, M2C_UNK *, 0x30) +
                        ((((M2C_FIELD(face, u32 *, FACE_SPRITE_TILE) << 6) >> 24) + 0x10) << 5 & ~1)),
                    zero, steps, 6);
            }
        }
        bank++;
    } while (bank < 2);
    gCur3DSpriteEngine = savedEngine;
}

u8 IsFaceSpriteLoaded(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x58) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK func_0209902c(void *arg0) {
 M2C_FIELD(arg0,s8 *,0x58)=0;
 M2C_FIELD(arg0,s8 *,0x59)=1;
}

M2C_UNK func_02099040(void *arg0) {
 void UpdateSpriteFade(void *);
 void UpdateSpriteSlide(void *);
 void func_020887ec(void *);
 if(IsFaceSpriteLoaded(arg0)==0) return;
 UpdateSpriteFade(arg0);
 UpdateSpriteSlide(arg0);
 func_020887ec(arg0);
}

void func_02099070(void) {
    M2C_UNK func_0209902c();
    func_0209902c();
}

void func_0209907c(void) {
    M2C_UNK func_02099040();
    func_02099040();
}

void **func_02099088(s32 arg0) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_02102fd4, data_02102f8c;
    void **result;
    if (arg0 == 0) arg0 = 7;
    result = CreateSpriteFromClass(&data_02102fd4, arg0);
    if (result != 0) {
        func_02089108();
        *result = &data_02102f8c;
    }
    return result;
}

void func_020990c0(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02102fd4;
    DeleteSpriteObjectsOfClass(&data_02102fd4);
}

void func_020990d4(void *arg0, u32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    Hide3DSprite();
}

void func_020990fc(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
u8 func_02097ce4(s32);
u8 func_02099320(void *);
void func_020985b0(s32, s32, s32);
void func_02098e2c(void *, s32);
void func_02099204(void *);
extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;

void *old; void *v; s32 i; u32 mode;
M2C_FIELD(arg0, u8 *, 0x58) = (u8)arg1;
M2C_FIELD(arg0, u8 *, 0x59) = (u8)arg2;
M2C_FIELD(arg0, u8 *, 0x49) = func_02097ce4(M2C_FIELD(arg0,u8*,0x58));
if (func_02099320(arg0)) {
old = gCur3DSpriteEngine;
i = 0;
do {
if (i == 0) v = data_027e00c8; else v = data_027e00c4;
gCur3DSpriteEngine = v;
mode = ((u32)M2C_FIELD(arg0, u8 *, 0x48) << 28) >> 29;
if ((mode != 0 || v == data_027e00c8) &&
(mode != 1 || v == data_027e00c4) &&
(mode != 3 || v == old)) {
func_020985b0(arg1, arg2, M2C_FIELD(v, s32 *, 0x1C) + (M2C_FIELD(arg0, u16 *, 0x3e) << 5));
}
i++;
} while (i < 2);
gCur3DSpriteEngine = old;
}
if (arg3) {
func_02098e2c(M2C_FIELD(arg0, void **, 0x60), arg1);
}
func_02099204(arg0);
}

void func_020991f4(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5C) = arg1;
}

void func_020991fc(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5D) = arg1;
}

/* Reloads a CO face sprite's palette on every engine it targets, choosing the
 * palette effects from whether the face is active and its palette style, then
 * refreshes its linked face object. */
void RefreshFaceSprite(void *p) {
u8 FaceSpriteIsLoaded(void *);void LoadFacePaletteAt(s32,s32,u16,u8);void SetFaceSpriteExpression(void *,u8);void RefreshFaceSpritePalette(void *);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*g3DSpriteEngineMain;
register void **engine;register u8 effects;register void *old;register s32 i;void *v;u32 mode;
if(FaceSpriteIsLoaded(p)){
engine=&gCur3DSpriteEngine;
effects=0;
if(M2C_FIELD(p,u8 *,FACE_SPRITE_ACTIVE)==0)effects|=FACE_EFFECT_DIM;
old=*engine;
if(M2C_FIELD(p,u8 *,FACE_SPRITE_PALETTE)==1)effects|=FACE_EFFECT_SEPIA;
if(M2C_FIELD(p,u8 *,FACE_SPRITE_PALETTE)==2)effects|=FACE_EFFECT_GRAY;
i=0;do{
if(i==0)v=g3DSpriteEngineMain;else v=g3DSpriteEngineSub;
*engine=v;mode=(u32)(M2C_FIELD(p,u8 *,FACE_SPRITE_SCREEN)<<28)>>29;
if((mode!=0 || v==g3DSpriteEngineMain)&&(mode!=1 || v==g3DSpriteEngineSub)&&(mode!=3 || v==old))
LoadFacePaletteAt(M2C_FIELD(p,u8 *,FACE_SPRITE_FACE),M2C_FIELD(p,u8 *,FACE_SPRITE_EXPRESSION),(u16)((M2C_FIELD(p,u32 *,FACE_SPRITE_TILE)<<6)>>24),effects);
i++;
}while(i<2);
gCur3DSpriteEngine=old;
}
if(M2C_FIELD(p,void **,FACE_SPRITE_CHILD)){SetFaceSpriteExpression(M2C_FIELD(p,void **,FACE_SPRITE_CHILD),M2C_FIELD(p,u8 *,FACE_SPRITE_ACTIVE));RefreshFaceSpritePalette(M2C_FIELD(p,void **,FACE_SPRITE_CHILD));}
}

void func_02099310(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5A) = arg1;
}

void func_02099318(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5B) = arg1;
}

u8 FaceSpriteIsLoaded(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x58) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK func_02099338(void *arg0) {
    s8 *p = (s8 *)arg0;
    p[0x58] = 0;
    p[0x59] = 0;
    p[0x5A] = 0;
    p[0x5B] = 0;
    p[0x5C] = 1;
    p[0x5D] = 0;
    M2C_FIELD(arg0, void ***, 0x60) = func_02099088((s32)arg0);
}

M2C_UNK func_0209936c(void *a){
 void UpdateSpriteFade(void*);void UpdateSpriteSlide(void*);
 s32 func_02098bd4(M2C_UNK,u8);
 void DrawSpriteActorAt(void*,s32,s32,s32,s32);
 s32 v;if(!FaceSpriteIsLoaded(a))return;
 v=func_02098bd4(M2C_FIELD(a,u8*,0x59),M2C_FIELD(a,u8*,0x5b));
 UpdateSpriteFade(a);UpdateSpriteSlide(a);
 DrawSpriteActorAt(a,M2C_FIELD(a,s16*,0x34),M2C_FIELD(a,s16*,0x36),M2C_FIELD(a,s8*,0x49),v);
}

void func_020993bc(void) {
    M2C_UNK func_02099338();
    func_02099338();
}

void func_020993c8(void) {
    M2C_UNK func_0209936c();
    func_0209936c();
}

void **func_020993d4(s32 arg0) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_02102fac, data_02102fa0;
    void **result;
    if (arg0 == 0) arg0 = 7;
    result = CreateSpriteFromClass(&data_02102fac, arg0);
    if (result != 0) {
        func_02089108();
        *result = &data_02102fa0;
    }
    return result;
}

void func_0209940c(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02102fac;
    DeleteSpriteObjectsOfClass(&data_02102fac);
}

void func_02099420(void) {

}

s32 func_02099424(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_02099438(void) {

}

s32 func_0209943c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Set up the current engine's text on `layer`: forget the cached strings, start
 * the next string at tile `baseTile` + TEXT_FIRST_TILE, and copy glyph tile set
 * `tileSet` (TEXT_GLYPH_TILES bytes) into the layer from tile `baseTile` + 16. */
M2C_UNK InitTextTiles(s32 layer, s32 baseTile, s32 tileSet) {
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_0211e9dc, data_0211f0dc;
    void MI_CpuCopy32(void *, void *, s32);
    void *text = M2C_FIELD(gCur3DSpriteEngine, void **, DS3D_ENGINE_TEXT_CACHE);
    M2C_FIELD(text, u16 *, TEXT_CACHE_NEXT_TILE) = baseTile + TEXT_FIRST_TILE;
    M2C_FIELD(text, u8 *, TEXT_CACHE_EMPTY) = 1;
    M2C_FIELD(text, u8 *, TEXT_CACHE_LAYER) = layer;
    switch (tileSet) {
    case 0:
        MI_CpuCopy32(&data_0211e9dc, (u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine + layer * 4, void **, 12) + ((baseTile + TEXT_GLYPH_OFFSET) << 5), TEXT_GLYPH_TILES);
        break;
    case 1:
        MI_CpuCopy32(&data_0211f0dc, (u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine + layer * 4, void **, 12) + ((baseTile + TEXT_GLYPH_OFFSET) << 5), TEXT_GLYPH_TILES);
        break;
    }
}

void func_020994e0(M2C_UNK arg0) {
    M2C_UNK InitTextTiles(M2C_UNK, M2C_UNK, M2C_UNK);
    InitTextTiles(1, arg0, 0);
}

void func_020994f8(u16 *a, s32 b, s32 c) {
    s32 i = 0;
    if (c <= 0) return;
    {
        s32 v = b;
        s32 w = 1;
        do {
            a[i] = (u16)v;
            a[i + 32] = (u16)(b + w);
            i++;
            v += 2;
            w += 2;
        } while (i < c);
    }
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_0209953c(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    extern void *gCur3DSpriteEngine;
    s32 StringCompare(void *, void *);
    s32 StringLength(M2C_UNK);
    void StringCopy(M2C_UNK, M2C_UNK);
    s32 func_0209b370(s32, s32, s32, s32, s32, s32, u16, u16, u16);
    void func_020994f8(u16 *, s32, s32);
    s32 MeasureStringWidth(M2C_UNK);

    register void *obj;
    register s32 cursor;
    register s32 idx;
    register void *engine;
    u16 u;
    u8 byte2;
    u8 byte302;
    s32 engineEntry;
    s32 funcResult;
    register s32 width;
    register s32 cur300;
    s32 len;
    s32 end;

    engine = gCur3DSpriteEngine;
    obj = M2C_FIELD(engine, void **, 0x50);

    if (arg3 == 0 || *(u8 *)arg3 == 0) return -1;
    cursor = 0;
    idx = 0;
    if (*(u8 *)obj != 1) {
        for (;;) {
            if (*((u8 *)obj + idx * 4 + 0x203) == arg5) {
                if (StringCompare((void *)((u8 *)obj + cursor), (void *)arg3) == 0) {
                    u = *(u16 *)((u8 *)obj + idx * 4 + 0x200);
                    byte2 = *((u8 *)obj + idx * 4 + 0x202);
                    func_020994f8((u16 *)(arg2 + arg0 * 2 + arg1 * 64),
                                 (u16)(arg4 + u), byte2);
                    return idx;
                }
            }
            len = StringLength((M2C_UNK)((u8 *)obj + cursor));
            cursor = cursor + len + 1;
            idx++;
            if (*((u8 *)obj + cursor) == 1) break;
        }
    }

    byte302 = *((u8 *)obj + 0x302);
    engineEntry = *(s32 *)((u8 *)engine + (byte302 * 4) + 0x0C);

    func_0209b370((s32)(s16)arg0, (s32)(s16)arg1, 4, engineEntry,
                   arg2, (s32)arg3, (u16)arg4, (u16)arg5, *(u16 *)((u8 *)obj + 0x300));

    funcResult = MeasureStringWidth(arg3);
    width = (funcResult + 7) >> 3;
    arg0 = *(u16 *)((u8 *)obj + 0x300);

    cur300 = arg0;
    *(u16 *)((u8 *)obj + idx * 4 + 0x200) = cur300;
    *((u8 *)obj + idx * 4 + 0x202) = (u8)width;
    *((u8 *)obj + idx * 4 + 0x203) = (u8)arg5;

    *(u16 *)((u8 *)obj + 0x300) = (u16)(*(u16 *)((u8 *)obj + 0x300) + width * 2);

    StringCopy((M2C_UNK)((u8 *)obj + cursor), (M2C_UNK)arg3);

    len = StringLength((M2C_UNK)arg3);
    end = cursor + len + 1;
    *((u8 *)obj + end) = 1;

    return idx;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
s32 func_020996d0(s32 a,u8 width,M2C_UNK d,M2C_UNK shift,s32 pal) {
u8 *src=(u8 *)a;u16 *dst=(u16 *)d;
Unk996Row buf[2];u16 *out; s32 clear1,clear2,offset; s32 left,right,i,j,n;u32 b;u8 byte;u8 *p;
shift&=7;
if(shift<=1){for(clear1=0;clear1<32;clear1++)dst[clear1]=0;}
if(shift+width>8){offset=((shift+width)&8)<<2;for(clear2=0;clear2<32;clear2++)dst[clear2+offset]=0;}
if(width!=0){
n=(width+1)>>1;left=shift*4;right=(8-shift)*4;
for(i=0;i<16;i++){
buf[1].word=0;buf[0].word=0;
for(j=0;j<n;j++){
b=*src;
src=src+1;
if(b&15)b+=pal;
if(b&240)b+=pal<<4;
buf[0].byte[j]=buf[1].byte[j]=b;
}
buf[0].word<<=left;
dst[0]|=buf[0].half[0];dst[1]|=buf[0].half[1];
buf[1].word>>=right;
if(buf[1].word){dst[32]|=buf[1].half[0];dst[33]|=buf[1].half[1];}
dst+=2;
}
}
return width;
}
#pragma scheduling on
u8 func_02099818(s32 arg0,M2C_UNK arg1,M2C_UNK arg2,s32 arg3) {
 M2C_UNK func_020996d0(s32,u8,M2C_UNK,M2C_UNK,s32);
 extern u8 gGlyphWidthTable[];
 extern s32 data_ov000_021b7f7c[];
 func_020996d0(data_ov000_021b7f7c[arg0],gGlyphWidthTable[arg0],arg1,arg2,arg3);
 return gGlyphWidthTable[arg0];
}

#pragma opt_common_subs off
void func_02099854(void *arg0,s32 arg1,s32 arg2,s32 arg3){
extern u8 data_0211dcf0[];
u16 *dst; s32 offset,row,col; u16 *src; u16 a=arg3*16,b=a*16,c=b*16,t,x,y,z,w;u8 key,index;void *node;
index=M2C_FIELD(arg0,u8 *,1);key=M2C_FIELD(arg0,u8 *,0);
if(index<0x40U){key=0x96;index=0xb2;}
retry:
node=M2C_FIELD(data_0211dcf0+index*4,void **,-0x100);
if(node!=0){
scan:
if(M2C_FIELD(node,u8 *,4)!=key){
node=M2C_FIELD(node,void **,0);
if(node==0){key=0x81;index=0x48;goto retry;}
if(node!=0)goto scan;
}}
if(node==0){key=0x81;index=0x48;goto retry;}
src=node+6;
if(arg2){func_020996d0(src,7,arg1,arg2,arg3);return;}
row=0;offset=0;
do{dst=(u16 *)(arg1+offset);col=0;
do{t=*src++;col++;x=t&15;y=t&0xf0;z=t&0xf00;w=t&0xf000;
if(x)x+=arg3;if(y)y+=a;if(z)z+=b;if(w)w+=c;
*dst++=w|(z|(x|y));
}while(col<16);row++;offset+=32;}while(row<2);
}
#pragma opt_common_subs reset
u8 func_020999b8(void *arg0) {
    s32 func_0209600c();
    u8 var_r0;

    if (func_0209600c() == 0) {
        return 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 0x5C) & 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020999e8(void *a){
 u16 *base=M2C_FIELD(a,u16**,0x40);s32 x,y;
 if(!base)return 0;
 x=M2C_FIELD(a,u8*,0x4a);y=M2C_FIELD(a,u8*,0x4b);
 return (s32)(base+x+(y<<5));
}

u16 *func_02099a0c(void *arg0) {
 u16 *base=M2C_FIELD(arg0,u16 **,0x40);
 if(base==0) return 0;
 return base + M2C_FIELD(arg0,u8 *,0x48) + (M2C_FIELD(arg0,u8 *,0x49)<<5);
}

void func_02099a30(void *arg0) {
 M2C_UNK ClearTileRect(s32,u8,u8);
 u16 *base=M2C_FIELD(arg0,u16 **,0x40);
 if(base==0) return;
 ClearTileRect((s32)(base+M2C_FIELD(arg0,u8 *,0x48)+(M2C_FIELD(arg0,u8 *,0x49)<<5)),M2C_FIELD(arg0,u8 *,0x58),M2C_FIELD(arg0,u8 *,0x59));
 M2C_FIELD(arg0,M2C_UNK (**)(),0x50)();
}

M2C_UNK func_02099a6c(void *arg0) {
 register s32 n=M2C_FIELD(arg0,u8 *,0x4A)-M2C_FIELD(arg0,u8 *,0x48)+2;
 if(M2C_FIELD(arg0,u8 *,0x58)<n) M2C_FIELD(arg0,u8 *,0x58)=n;
 M2C_FIELD(arg0,u8 *,0x4A)=M2C_FIELD(arg0,u8 *,0x48);
 M2C_FIELD(arg0,u8 *,0x56)=0;
}

M2C_UNK func_02099a9c(void *a){
 s32 n=M2C_FIELD(a,u8*,0x4b)-M2C_FIELD(a,u8*,0x49)+2;
 if(M2C_FIELD(a,u8*,0x59)<n)M2C_FIELD(a,u8*,0x59)=n;
 M2C_FIELD(a,u8*,0x4b)=M2C_FIELD(a,u8*,0x49);
}

void func_02099ac4(void *arg0) {
    M2C_UNK func_02099a6c();
    M2C_UNK func_02099a9c(void *);
    func_02099a6c();
    func_02099a9c(arg0);
    M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) | 2);
}

u8 IsLeadByte(u8 *arg0) {
    u8 var_r0;

    if (*arg0 & 0x80) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsGlyphEscape(u8 *arg0) {
    u8 var_r0;

    if (*arg0 == 0x1F) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

