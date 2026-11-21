/* 6 functions from 0x02200EE4 to 0x02201E88 (ov003), found by ds-decomp. */
#include "common.h"
s32 func_ov003_021f1b38();
s32 func_ov003_021f1b7c();
void *func_0208bc24();
s32 func_ov003_021e9810();
s32 func_ov003_021e9818();
s32 CreateMainWallpaperSprite();
s32 Apply3DSpriteBanks();
s32 Reset3DSpriteBankDisplay();
s32 func_ov003_021e9830();
s32 func_ov003_02201e88();
void *CreateFrameBorderSprite();
s32 func_020893f4();
s32 func_ov003_021e97bc();
s32 Sync3DSpriteToTarget();
s32 func_ov003_021e97fc();
s32 Ov003_SetSetupPanelState();
s32 Ov003_PlaceSetupCursor();
s32 Ov003_UpdateSelectedEntryText();
s32 func_ov003_02202380();
s32 func_ov003_02202388();
s32 func_ov003_02202390();
s32 func_ov003_02202398();
s32 func_ov003_022023a0();
s32 SetTextSpriteValue();
s32 func_ov003_022023a8();
s32 func_ov003_022023c4();
s32 func_ov003_022023cc();
s32 SetFileDirectory();
s32 Clear3DSpriteLayer();
void *LoadFileToBuffer();
void *GetLocalizedFileName();
s32 LoadGraphicsBlock();
s32 HeapFreeBlock();
s32 LoadFileToSpriteBuffer();
s32 SetTileRectPalette();
s32 func_ov003_021ea134();
s32 LoadDecompressedFileTo();
s32 func_ov003_022023e4();
s32 func_ov003_021ea294();
s32 Ov003_LoadPlayerSelectBg();
s32 func_ov003_022023fc();
s32 func_01ff9dd8();
s32 Modulo();
s32 func_ov003_02202408();
s32 func_ov003_022004f0();
s32 GetPlayerCoId();
s32 ClearTileRect();
s32 LoadFaceTexture();
s32 FillFaceTileMap();
s32 LoadFacePalette();
s32 func_ov003_021ea27c();
u8 func_ov003_02201500(void *);
u8 func_ov003_0220151c(void *);
void func_ov003_0220153c(s32,s32,s32,s32,u8);
void func_ov003_02201620(void *,s32);
void CreatePanelSprites(void *,s32);
void Hide3DSprite(void *);
extern u8 data_ov003_02210456[];
extern u8 data_ov003_02210454[];
extern u8 data_ov003_02210458[];
extern u8 data_ov003_0221045a[];
extern u8 data_ov003_0221045c[];
extern u8 data_ov003_02210472[];
extern u8 data_ov003_02210900[];
extern u8 data_ov003_02210908[];
extern u8 data_ov003_02210918[];
extern u8 data_ov003_0221092c[];
extern u8 data_ov003_02210934[];
extern u8 data_ov003_02210948[];
extern u8 data_ov003_02210958[];
extern u8 data_ov003_02210970[];
extern u8 data_ov003_02210980[];
extern u8 data_ov003_02210990[];
extern u8 data_ov003_022109a4[];
extern u8 data_ov003_022109ac[];
extern u8 data_ov003_022109b4[];
extern u16 *g3DSpriteEngineSub,*g3DSpriteEngineMain;
extern u16 **gCur3DSpriteEngine;

#pragma opt_common_subs off
#pragma opt_propagation off
void func_ov003_02200ee4(void *p) {
u16 **saved,**saved2;
void *res;
u8 i;
s32 side,side2,offset,slot;
s8 character;
func_ov003_021f1b38(3,data_ov003_02210456);
if(func_ov003_02201500(p)){
func_ov003_021f1b7c(0,data_ov003_02210454);
func_ov003_021f1b7c(1,data_ov003_02210458);
func_ov003_021f1b7c(3,data_ov003_0221045a);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(u16 **)g3DSpriteEngineSub;
M2C_FIELD(p,void**,0x58)=func_0208bc24(p);
func_ov003_021e9810(M2C_FIELD(p,void**,0x58),0x210);
func_ov003_021e9818(M2C_FIELD(p,void**,0x58),8);
gCur3DSpriteEngine=saved;
}else if(func_ov003_0220151c(p)){
func_ov003_021f1b38(2,data_ov003_0221045c);
CreateMainWallpaperSprite(2,15,6);
func_ov003_0220153c(0,0,1,1,1);
}
Apply3DSpriteBanks();Reset3DSpriteBankDisplay();
func_ov003_021e9830(M2C_FIELD(p,void**,0x48),-32);
func_ov003_02201620(M2C_FIELD(p,void**,0x44),p);
CreatePanelSprites(M2C_FIELD(p,void**,0x40),p);
if(func_ov003_02201500(p))func_ov003_02201e88(M2C_FIELD(p,void**,0x50),p);
M2C_FIELD(p,void**,0x4c)=CreateFrameBorderSprite(p);
func_020893f4(M2C_FIELD(p,void**,0x4c),0x2d80,1);
func_ov003_021e97bc(M2C_FIELD(p,void**,0x4c),112,164,58,58);
Sync3DSpriteToTarget(M2C_FIELD(p,void**,0x4c));
func_ov003_021e97fc(M2C_FIELD(p,void**,0x4c),1);
Hide3DSprite(M2C_FIELD(p,void**,0x4c));
Ov003_SetSetupPanelState(p,0);Ov003_PlaceSetupCursor(p);
Sync3DSpriteToTarget(M2C_FIELD(p,void**,0x4c));Ov003_UpdateSelectedEntryText(p);
func_ov003_02202380(M2C_FIELD(p,void**,0x54),0x18c);
func_ov003_02202388(M2C_FIELD(p,void**,0x54),4);
func_ov003_02202390(M2C_FIELD(p,void**,0x54),16);
func_ov003_02202398(M2C_FIELD(p,void**,0x54),6);
func_ov003_022023a0(M2C_FIELD(p,void**,0x54),10);
SetTextSpriteValue(M2C_FIELD(p,void**,0x54),0);
func_ov003_022023a8(M2C_FIELD(p,void**,0x54),1);
func_ov003_022023c4(M2C_FIELD(p,void**,0x54),data_ov003_02210472);
func_ov003_022023cc(M2C_FIELD(p,void**,0x54),1);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(u16 **)g3DSpriteEngineMain;
SetFileDirectory(data_ov003_02210900);Clear3DSpriteLayer(3);
res=LoadFileToBuffer(GetLocalizedFileName(data_ov003_02210908),1);
LoadGraphicsBlock(res,M2C_FIELD(gCur3DSpriteEngine,void**,0x18));
LoadGraphicsBlock((u8 *)res+0x3cc,M2C_FIELD(gCur3DSpriteEngine,void**,0x2c));
HeapFreeBlock(res);
LoadFileToSpriteBuffer(data_ov003_02210918,0,64);
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,void**,0x2c),32,32,0);
func_ov003_021ea134(3);
SetFileDirectory(data_ov003_0221092c);
res=LoadFileToBuffer(GetLocalizedFileName(data_ov003_02210934),1);
LoadGraphicsBlock(res,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3800);
HeapFreeBlock(res);
LoadDecompressedFileTo(data_ov003_02210948,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3c00);
LoadFileToSpriteBuffer(data_ov003_02210958,0x2e0,32);
LoadDecompressedFileTo(GetLocalizedFileName(data_ov003_02210970),(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x4000);
LoadFileToSpriteBuffer(data_ov003_02210980,0x300,32);
func_ov003_022023e4(1,3,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3180);
func_ov003_021ea294(1,0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x30)+0x2c0);
res=LoadFileToBuffer(GetLocalizedFileName(data_ov003_02210990),1);
LoadGraphicsBlock((u8 *)res+0x92c,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x6400);
HeapFreeBlock(res);gCur3DSpriteEngine=saved;
if(func_ov003_0220151c(p))return;
saved2=gCur3DSpriteEngine;gCur3DSpriteEngine=(u16 **)g3DSpriteEngineSub;
SetFileDirectory(data_ov003_022109a4);Clear3DSpriteLayer(3);
Ov003_LoadPlayerSelectBg(3,2,func_ov003_022023fc(p));
func_ov003_021ea134(3);
func_01ff9dd8(0);func_01ff9dd8(1);Clear3DSpriteLayer(0);Clear3DSpriteLayer(1);
for(i=0;i<(u32)func_ov003_022023fc(p);i++){
if(Modulo(i,2)==0)side=0;else side=1;
side2=(u8)side;
if(i<2)offset=0;else offset=func_ov003_02202408((u16)func_ov003_022004f0(2));
character=GetPlayerCoId(i+1);
if(character==0){
ClearTileRect((u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine+side*4,void**,0x20)+(offset+1)*2,7,7);
}else{
slot=(i<<7)+2;
LoadFaceTexture(character,1,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,12)+(slot<<5));
FillFaceTileMap(1,offset,0,(u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine+side*4,void**,0x20)+2,(u16)((u32)slot>>1),i,0);
LoadFacePalette(character,1,side2,i,0);
}
}
func_ov003_021ea134(0);func_ov003_021ea134(1);
SetFileDirectory(data_ov003_022109ac);
res=LoadFileToBuffer(GetLocalizedFileName(data_ov003_022109b4),1);
LoadGraphicsBlock((u8 *)res+0x67c,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x2800);
HeapFreeBlock(res);
func_ov003_021ea27c(4,0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3000);
func_ov003_021ea294(5,0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x30)+0x2c0);
Reset3DSpriteBankDisplay();gCur3DSpriteEngine=saved2;
}
u8 func_ov003_02201500(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_0220151c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Set bits 4-8 of the word pointed to by *gCur3DSpriteEngine from five boolean flags. */
void func_ov003_0220153c(s32 flag0, s32 flag1, s32 flag2, s32 flag3, u8 flag4) {
u16 * volatile reg0;
u16 * volatile reg1;
u16 * volatile reg2;
u16 * volatile reg3;
u16 * volatile reg4;
reg0 = *gCur3DSpriteEngine; *reg0 = (*reg0 & ~16) | ((u32)(flag0 << 31) >> 27);
reg1 = *gCur3DSpriteEngine; *reg1 = (*reg1 & ~32) | ((u32)(flag1 << 31) >> 26);
reg2 = *gCur3DSpriteEngine; *reg2 = (*reg2 & ~64) | ((u32)(flag2 << 31) >> 25);
reg3 = *gCur3DSpriteEngine; *reg3 = (*reg3 & ~128) | ((u32)(flag3 << 31) >> 24);
reg4 = *gCur3DSpriteEngine; *reg4 = (*reg4 & ~256) | ((u32)(flag4 << 31) >> 23);
}

void func_ov003_02201620(void *arg0, s32 arg1) {
    void *MemAlloc(s32);
    s32 Modulo(s32, s32);
    s32 Divide(s32, s32);
    void *func_020ab1c4(s32);
    void InitUnitSprite(void *, s32, s32, s32, s32);
    void Set3DSpriteSlideTargetAndStart(void *, s32, s32, s32, s32);
    u16 GetUnitSpriteWidth(void *);
    u16 GetUnitSpriteHeight(void *);
    void *func_02087d84(void *, s32, s16, s16, s32, s32);
    void func_ov003_02200dc8(void *, s32);
    extern u32 data_ov003_022107c4[];
    extern u32 data_ov003_02210774[];
    extern u32 data_ov003_0221088c[];
    extern u32 data_ov003_02210864[];
    extern u32 data_ov003_0221083c[];
    extern u32 data_ov003_02210814[];
    extern u32 data_ov003_022107ec[];
    extern u32 data_ov003_0221079c[];
    extern u16 data_ov003_022104fa[];
    s32 tmp1, tmp2;
    s32 r11, r10, r5, r6;
    u8 *cell;
    void *option;
    u32 result;
    void *sprite;
    void *newSprite;
    u16 bounds[4];
    const u16 (*rects)[4] = (const u16 (*)[4])data_ov003_022104fa;
    void *vt;
    u8 i;

    i = 0;
    do {
        if (i < 8) {
            switch (i) {
            case 0:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_022107c4;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            case 1:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_02210774;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            case 2:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_0221088c;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            case 3:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_02210864;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            case 4:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_0221083c;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            case 5:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_02210814;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            case 6:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_022107ec;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            case 7:
                option = MemAlloc(4);
                if (option != 0) M2C_FIELD(option, void **, 0) = data_ov003_0221079c;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = option;
                break;
            }
            option = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(option, void **, 0);
            result = ((s32 (*)(void *)) ((void **) vt)[3])(option);
            option = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(option, void **, 0);
            tmp2 = ((s32 (*)(void *)) ((void **) vt)[2])(option);
            cell = (u8 *)arg0 + i * 0x18;
            M2C_FIELD(cell, s32 *, 0x10) = result;
            if (M2C_FIELD(cell, u8 *, 0x1c) != 0) {
                while (M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10))
                    M2C_FIELD(cell, s32 *, 0xc) -= M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
                while (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14))
                    M2C_FIELD(cell, s32 *, 0xc) += M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
            } else {
                s32 limit = M2C_FIELD(cell,s32 *,0x10);
                s32 value = M2C_FIELD(cell,s32 *,0xc);
                if (value <= limit) {
                    limit = M2C_FIELD(cell,s32 *,0x14);
                    if (value >= limit) limit = value;
                }
                M2C_FIELD(cell,s32 *,0xc) = limit;
            }
            M2C_FIELD(cell, s32 *, 0x14) = tmp2;
            if (M2C_FIELD(cell, u8 *, 0x1c) != 0) {
                while (M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10))
                    M2C_FIELD(cell, s32 *, 0xc) -= M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
                while (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14))
                    M2C_FIELD(cell, s32 *, 0xc) += M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
            } else {
                s32 limit = M2C_FIELD(cell,s32 *,0x10);
                s32 value = M2C_FIELD(cell,s32 *,0xc);
                if (value <= limit) {
                    limit = M2C_FIELD(cell,s32 *,0x14);
                    if (value >= limit) limit = value;
                }
                M2C_FIELD(cell,s32 *,0xc) = limit;
            }
            option = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(option, void **, 0);
            if (((s32 (*)(void *)) ((void **) vt)[5])(option) != 0) M2C_FIELD(cell, u8 *, 0x1c) = 1;
            option = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(option, void **, 0);
            M2C_FIELD(cell, s32 *, 0x18) = ((s32 (*)(void *)) ((void **) vt)[4])(option);
            option = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(option, void **, 0);
            M2C_FIELD(cell, s32 *, 0xc) = ((s32 (*)(void *)) ((void **) vt)[6])(option);
            if (M2C_FIELD(cell, u8 *, 0x1c) != 0) {
                while (M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10))
                    M2C_FIELD(cell, s32 *, 0xc) -= M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
                while (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14))
                    M2C_FIELD(cell, s32 *, 0xc) += M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
            } else {
                s32 limit = M2C_FIELD(cell,s32 *,0x10);
                s32 value = M2C_FIELD(cell,s32 *,0xc);
                if (value <= limit) {
                    limit = M2C_FIELD(cell,s32 *,0x14);
                    if (value >= limit) limit = value;
                }
                M2C_FIELD(cell,s32 *,0xc) = limit;
            }
            r6 = (s16)(Modulo(i, 4) * 64 + 4);
            r5 = (s16)(Divide(i, 4) * 0x48 + 0x38);
            r11 = 0x38;
            r10 = 0x10;
        } else {
            r6 = 0x70;
            r5 = 0xa4;
            r11 = 0x20;
            r10 = 0x18;
        }
        newSprite = func_020ab1c4(arg1);
        M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8) = newSprite;
        M2C_FIELD(newSprite, u16 *, 0x2e) = i;
        InitUnitSprite(M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8), 0x47, 0x16c, 0, 0);
        result = (u32)M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8);
#define sprite ((void *)result)
        Set3DSpriteSlideTargetAndStart(sprite, r6, r5, r6, r5);
        {
            s32 b1;
            s32 a1, c1;
            s32 e1;
            s32 d1;
            if (M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0) b1 = 1; else b1 = 0;
            if ((u8)b1) {
                a1 = M2C_FIELD(sprite, s16 *, 0x52);
                c1 = M2C_FIELD(sprite, s16 *, 0x50);
                e1 = GetUnitSpriteWidth(sprite);
                d1 = GetUnitSpriteHeight(sprite);
                func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, c1, a1, (u16)e1, (u16)d1);
            }
        }
        M2C_FIELD(sprite, s16 *, 0x34) = (s16)r6;
        M2C_FIELD(sprite, s16 *, 0x36) = (s16)r5;
        {
            s32 b2;
            s32 a2, c2;
            s32 e2;
            s32 d2;
            if (M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0) b2 = 1; else b2 = 0;
            if ((u8)b2) {
                a2 = M2C_FIELD(sprite, s16 *, 0x52);
                c2 = M2C_FIELD(sprite, s16 *, 0x50);
                e2 = GetUnitSpriteWidth(sprite);
                d2 = GetUnitSpriteHeight(sprite);
                func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, c2, a2, (u16)e2, (u16)d2);
            }
        }
        M2C_FIELD(sprite, u32 *, 0x40) = (M2C_FIELD(sprite, u32 *, 0x40) & 0xFFFFFE00) | (r11 & 0x1FF);
        M2C_FIELD(sprite, u32 *, 0x40) = (M2C_FIELD(sprite, u32 *, 0x40) & 0xFFFC01FF) | ((u32)(r10 << 23) >> 14);
        {
            s32 b3;
            s32 a3, c3;
            s32 e3;
            s32 d3;
            if (M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0) b3 = 1; else b3 = 0;
            if ((u8)b3) {
                a3 = M2C_FIELD(sprite, s16 *, 0x52);
                c3 = M2C_FIELD(sprite, s16 *, 0x50);
                e3 = GetUnitSpriteWidth(sprite);
                d3 = GetUnitSpriteHeight(sprite);
                func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, c3, a3, (u16)e3, (u16)d3);
            }
        }
        bounds[3] = rects[i][3];
        bounds[2] = rects[i][2];
        bounds[1] = rects[i][1];
        bounds[0] = rects[i][0];
#undef sprite
        sprite = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8);
        M2C_FIELD(sprite, u16 *, 0x68) = bounds[0];
        M2C_FIELD(sprite, u16 *, 0x6a) = bounds[1];
        M2C_FIELD(sprite, u16 *, 0x6c) = bounds[2];
        M2C_FIELD(sprite, u16 *, 0x6e) = bounds[3];
        i++;
    } while (i < 9);
    func_ov003_02200dc8(arg0, 8);
}

#pragma push
#pragma opt_propagation on
/* Creates the versus-setup panel's two backdrop sprites and the eight pairs of
 * slot sprites (selection frame and icon) on the screen's sprite list. */
void CreatePanelSprites(void *panel, s32 screen) {
    void *func_02087d84(void *, s32, s16, s16, s32, s32);
    void Hide3DSprite(void *);
    void Set3DSpriteSlideTargetAndStart(void *, s32, s32, s32, s32);
    void InitUnitSprite(void *, s32, s32, s32, s32);
    u16 GetUnitSpriteWidth(void *);
    u16 GetUnitSpriteHeight(void *);
    void *func_020ab1c4(s32);
    void *sprite;
    s16 spriteY;
    s16 spriteX;
    u16 width;
    s32 height;
    s32 hasFrame;
    void *sprite2;
    s16 spriteY2;
    s16 spriteX2;
    u16 width2;
    s32 height2;
    s32 hasFrame2;
    s32 constZeroA;
    s32 constLayer;
    s32 constTile;
    s32 constStyle;
    s32 constZeroB;
    u8 slot;
    void *slotBase;
    void *newSprite;

    M2C_FIELD(panel, void **, 0) = func_020ab1c4(screen);
    InitUnitSprite(M2C_FIELD(panel, void **, 0), 2, 0x14C, 3, 1);
    sprite = M2C_FIELD(panel, void **, 0);
    Set3DSpriteSlideTargetAndStart(sprite, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12) != 0) {
        hasFrame = 1;
    } else {
        hasFrame = 0;
    }
    if (hasFrame & 0xFF) {
        spriteY = M2C_FIELD(sprite, s16 *, 0x52);
        spriteX = M2C_FIELD(sprite, s16 *, 0x50);
        width = GetUnitSpriteWidth(sprite);
        height = GetUnitSpriteHeight(sprite);
        func_02087d84(M2C_FIELD(sprite, void **, 0x64), 1, spriteX, spriteY,
                      (s32)((u32)width << 16 >> 16), (s32)((u32)height << 16 >> 16));
    }
    Hide3DSprite(M2C_FIELD(panel, void **, 0));
    M2C_FIELD(panel, void **, 4) = func_020ab1c4(screen);
    InitUnitSprite(M2C_FIELD(panel, void **, 4), 0x20, 0x140, 3, 0);
    sprite2 = M2C_FIELD(panel, void **, 4);
    Set3DSpriteSlideTargetAndStart(sprite2, 0x70, 0xA4, 0x70, 0xC0);
    if (M2C_FIELD(M2C_FIELD(sprite2, void **, 0x64), u8 *, 0x12) != 0) {
        hasFrame2 = 1;
    } else {
        hasFrame2 = 0;
    }
    if (hasFrame2 & 0xFF) {
        spriteY2 = M2C_FIELD(sprite2, s16 *, 0x52);
        spriteX2 = M2C_FIELD(sprite2, s16 *, 0x50);
        width2 = GetUnitSpriteWidth(sprite2);
        height2 = GetUnitSpriteHeight(sprite2);
        func_02087d84(M2C_FIELD(sprite2, void **, 0x64), 1, spriteX2, spriteY2,
                      (s32)((u32)width2 << 16 >> 16), (s32)((u32)height2 << 16 >> 16));
    }
    Hide3DSprite(M2C_FIELD(panel, void **, 4));

    slot = 0;
    constZeroB = slot;
    constStyle = 8;
    constTile = 0x15C;
    constLayer = 3;
    constZeroA = slot;
    do {
        newSprite = func_020ab1c4(screen);
        slotBase = (void *)((u8 *)panel + (slot * 4));
        M2C_FIELD((u8 *)panel + slot * 4, void **, 8) = newSprite;
        InitUnitSprite(M2C_FIELD((u8 *)panel + slot * 4, void **, 8), constStyle, constTile, constLayer, constZeroB);
        Hide3DSprite(M2C_FIELD((u8 *)panel + slot * 4, void **, 8));
        newSprite = func_020ab1c4(screen);
        M2C_FIELD((u8 *)panel + slot * 4, void **, 0x28) = newSprite;
        InitUnitSprite(M2C_FIELD((u8 *)panel + slot * 4, void **, 0x28), 9, 0x164, 3, constZeroA);
        Hide3DSprite(M2C_FIELD((u8 *)panel + slot * 4, void **, 0x28));
        slot += 1;
    } while ((u32)slot < 8U);
}
#pragma pop
