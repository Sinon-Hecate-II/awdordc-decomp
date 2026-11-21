/* 6 functions from 0x021E5118 to 0x021E5E24 (ov003), found by ds-decomp. */
#include "common.h"
static inline void CallSlot20(void *p) { M2C_FIELD(M2C_FIELD(p,void **,0),void (**)(void *),32)(p); }

void func_ov003_021e5118(void *arg0) {
    M2C_UNK Apply3DSpriteBanks();
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK func_01ff9dd8(M2C_UNK);
    M2C_UNK CopyToObjPaletteShadow(s32, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy32(s32, s32, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadGraphicsBlock(s32, s32);
    M2C_UNK SetTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK AddTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK LoadDecompressedFileTo(M2C_UNK *, s32);
    s32 LoadFileToBuffer(M2C_UNK *, M2C_UNK);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_02081340(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK *, s32);
    s32 GetLocalPlayerName();
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK Hide3DSprite(void *);
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void *func_0208bc24(void *);
    M2C_UNK Load3DSpritePattern(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK LoadScenePanelPalette(M2C_UNK);
    void *func_0209b26c(s16, M2C_UNK, M2C_UNK, s32, s32, u32);
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK InitUnitSprite(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    u16 GetUnitSpriteWidth(void *);
    u16 GetUnitSpriteHeight(void *);
    void *func_020ab1c4(void *);
    s32 GetUiColor(M2C_UNK);
    M2C_UNK DimPalette(s32);
    M2C_UNK DrawMapPreview(s32, s32, M2C_UNK, M2C_UNK);
    M2C_UNK *GetLocalizedFileName(M2C_UNK *);
    M2C_UNK HeapFreeBlock(s32);
    M2C_UNK DrawGlyphString(s32, s32, s32, M2C_UNK, s32, s32, s32);
    M2C_UNK LoadRankIconGraphics(s32, s32, M2C_UNK);
    M2C_UNK GetEarnedRecordTierTotal();
    s32 GetRecordRank();
    s32 GetFavouriteRecordGroup();
    s32 GetFavouriteGroupTextId();
    M2C_UNK GetFavouriteRecordIndex();
    s32 GetFavouriteRecordTextId();
    s32 GetTerrainTileData(u8);
    s32 GetTerrainPalette(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f1b38(M2C_UNK, M2C_UNK *);
    M2C_UNK func_ov003_021f1b7c(M2C_UNK, M2C_UNK *);
    u8 GetPreviewTerrainId(u8);
    extern u16 **g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *data_027e01d8;
    extern M2C_UNK data_ov003_0220f604;
    extern M2C_UNK data_ov003_0220f606;
    extern M2C_UNK data_ov003_0220f608;
    extern M2C_UNK data_ov003_0220f60a;
    extern M2C_UNK data_ov003_0220f60c;
    extern M2C_UNK data_ov003_0220f76c;
    extern M2C_UNK data_ov003_0220f778;
    extern M2C_UNK data_ov003_0220f780;
    extern M2C_UNK data_ov003_0220f788;
    extern M2C_UNK data_ov003_0220f790;
    extern M2C_UNK data_ov003_0220f7a0;
    extern M2C_UNK data_ov003_0220f7b0;
    extern M2C_UNK data_ov003_0220f7c0;
    extern M2C_UNK data_ov003_0220f7c8;
    extern M2C_UNK data_ov003_0220f7dc;
    extern M2C_UNK data_ov003_0220f7ec;
    extern M2C_UNK data_ov003_0220f7fc;
    extern M2C_UNK data_ov003_0220f810;
    extern M2C_UNK data_ov003_0220f824;
    extern M2C_UNK data_ov003_0220f82c;
    extern M2C_UNK data_ov003_0220f83c;
    extern M2C_UNK data_ov003_0220f854;
    extern M2C_UNK data_ov003_0220f868;
    extern M2C_UNK data_ov003_0220f87c;
    s16 temp_r6;
    s16 temp_r6_3;
    s16 temp_r7;
    s32 temp_r0_3;
    s32 temp_r8;
    s32 var_r0;
    u16 temp_r4_5;
    u16 temp_r9;
    u8 var_r4;
    void **temp_r4;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r5;
    void *temp_r5_2;
    void *temp_r6_2;

    func_ov003_021f1b38(0, &data_ov003_0220f604);
    func_ov003_021f1b38(3, &data_ov003_0220f608);
    func_ov003_021f1b7c(0, &data_ov003_0220f60c);
    func_ov003_021f1b7c(1, &data_ov003_0220f606);
    func_ov003_021f1b7c(3, &data_ov003_0220f60a);
    Apply3DSpriteBanks();
    temp_r4 = M2C_FIELD(arg0, void ***, 0x48);
    *temp_r4 = func_020ab1c4(arg0);
    InitUnitSprite(*temp_r4, 2, 0x1A4, 3, 0);
    temp_r5 = *temp_r4;
    Set3DSpriteSlideTargetAndStart(temp_r5, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r9 = GetUnitSpriteWidth(temp_r5);
        func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7, temp_r6, (s32) temp_r9, (s32) GetUnitSpriteHeight(temp_r5));
    }
    Hide3DSprite(*temp_r4);
    temp_r0 = func_0208bc24(arg0);
    M2C_FIELD(arg0, void **, 0x5C) = temp_r0;
    M2C_FIELD(temp_r0, s16 *, 0x3E) = 0x36C;
    temp_r1 = M2C_FIELD(arg0, void **, 0x5C);
    M2C_FIELD(temp_r1, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r1, s32 *, 0x40) & ~0x03FC0000) | 0x300000);
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(temp_r4_2, s16 *, 0xE) = 0;
    M2C_FIELD(temp_r4_2, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r4_2, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r4_2, u16 *, 2) = (u16) M2C_FIELD(temp_r4_2, u16 *, 4);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r4_3, s16 *, 0xE) = 0;
    M2C_FIELD(temp_r4_3, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r4_3, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r4_3, u16 *, 2) = (u16) M2C_FIELD(temp_r4_3, u16 *, 4);
    temp_r4_4 = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(temp_r4_4, s16 *, 0xE) = 0;
    M2C_FIELD(temp_r4_4, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r4_4, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r4_4, u16 *, 2) = (u16) M2C_FIELD(temp_r4_4, u16 *, 4);
    temp_r5_2 = data_027e01d8;
    data_027e01d8 = g3DSpriteEngineMain;
    SetFileDirectory(&data_ov003_0220f76c);
    LoadDecompressedFileTo(&data_ov003_0220f778, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x3D00);
    func_02081340(&data_ov003_0220f780, 0x2E0, 0x60, 0x20);
    SetFileDirectory(&data_ov003_0220f788);
    GetLocalizedFileName(&data_ov003_0220f790);
    OpenNarcArchive();
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov003_0220f7a0), M2C_FIELD(data_027e01d8, s32 *, 0x18));
    CloseNarcArchive();
    func_02081340(&data_ov003_0220f7b0, 0xA0, 0x20, 0x20);
    AddTileRectPalette(M2C_FIELD(data_027e01d8, s32 *, 0x2C), 0x20, 0x20, 5);
    SetFileDirectory(&data_ov003_0220f7c0);
    LoadDecompressedFileTo(GetLocalizedFileName(&data_ov003_0220f7c8), M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x5180);
    LoadDecompressedFileTo(&data_ov003_0220f7dc, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x5100);
    LoadDecompressedFileTo(&data_ov003_0220f7ec, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x5D80);
    LoadDecompressedFileTo(&data_ov003_0220f7fc, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    SetTileRectPalette(M2C_FIELD(data_027e01d8, s32 *, 0x2C), 0x20, 0x18, 5);
    LoadFileToSpriteBuffer(&data_ov003_0220f810, 0x300, 0x20);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    LoadSpriteResource(1, 0, 3, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x3680);
    LoadSpriteResource(1, 2, 0, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x2C0);
    Clear3DSpriteLayer(0);
    func_01ff9dd8(0);
    LoadScenePanelPalette(7);
    temp_r6_2 = data_027e01d8;
    DrawGlyphString(GetLocalPlayerName(), M2C_FIELD(temp_r6_2, s32 *, 0xC), M2C_FIELD(temp_r6_2, s32 *, 0x20), 7, 6, 4, 2);
    GetEarnedRecordTierTotal();
    LoadRankIconGraphics(GetRecordRank(), 0x5F80, 9);
    if ((GetFavouriteRecordGroup() != -2) && (GetFavouriteRecordGroup() != -1)) {
        GetFavouriteRecordGroup();
        temp_r0_2 = func_0209b26c(0xC, 7, 0, GetFavouriteGroupTextId(), 0x7000, 0x320000U >> 0x10);
        temp_r4_5 = (M2C_FIELD(temp_r0_2, u16 *, 0x4C) - M2C_FIELD(temp_r0_2, u16 *, 0x4E)) + 2 + 0x32;
        temp_r6_3 = M2C_FIELD(temp_r0_2, u8 *, 0x4A) + 2;
        GetFavouriteRecordIndex();
        func_0209b26c(temp_r6_3, 7, 0, GetFavouriteRecordTextId(), 0x7000, (u32) temp_r4_5);
    }
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
    data_027e01d8 = g3DSpriteEngineSub;
    SetFileDirectory(&data_ov003_0220f824);
    LoadDecompressedFileTo(&data_ov003_0220f82c, M2C_FIELD(data_027e01d8, s32 *, 0x10));
    LoadDecompressedFileTo(&data_ov003_0220f83c, M2C_FIELD(data_027e01d8, s32 *, 0x24));
    LoadFileToSpriteBuffer(&data_ov003_0220f854, 0xE0, 0x20);
    SetTileRectPalette(M2C_FIELD(data_027e01d8, s32 *, 0x24), 0x20, 0x20, 7);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    LoadScenePanelPalette(9);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    DrawMapPreview(M2C_FIELD(data_027e01d8, s32 *, 0xC), M2C_FIELD(data_027e01d8, s32 *, 0x20), 1, 5);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
    Load3DSpritePattern(0x5100, 0xA, GetUiColor(0xA), 1);
    temp_r0_3 = LoadFileToBuffer(GetLocalizedFileName(&data_ov003_0220f868), 1);
    LoadGraphicsBlock(temp_r0_3, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800);
    HeapFreeBlock(temp_r0_3);
    LoadFileToSpriteBuffer(&data_ov003_0220f87c, 0x2C0, 0x20);
    LoadSpriteResource(1, 0, 4, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x6500);
    LoadSpriteResource(1, 2, 0, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x360);
    LoadSpriteResource(1, 0, 0, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x4B00);
    LoadSpriteResource(1, 0, 2, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x4E00);
    LoadSpriteResource(1, 2, 0, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x320);
    var_r4 = 0;
    do {
        temp_r8 = M2C_FIELD(data_027e01d8, s32 *, 0x1C) + ((u32) (((var_r4 * 8) + 0x210) << 0x10) >> 0xB);
        MI_CpuCopy32(GetTerrainTileData(GetPreviewTerrainId(var_r4)), temp_r8, 0x100);
        var_r4 += 1;
    } while ((u32) var_r4 <= 7U);
    CopyToObjPaletteShadow(GetTerrainPalette(0xF, 0), 0x2E0, 0x20);
    CopyToObjPaletteShadow(GetTerrainPalette(0xF, 0), 0x300, 0x20);
    DimPalette(M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x300);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 0x10);
    data_027e01d8 = temp_r5_2;
}

void Ov003_DrawUnitCategoryGrid(void *,s16,s16);
void func_ov003_021e583c(void *a) {
void AddSprite(u16,u8,u16,void *,s32);void UpdateSpriteAnimation(s32);s16 GetSpriteAnimValue(s32);void DrawTextSprite(void *);void AddSprite32x16(u16,s32,u16,s32);s32 func_ov003_021e50e0(s16,s32,s32,s32);void func_ov003_021e5e24(void *,s16,s16);
extern u16 **gCur3DSpriteEngine,**g3DSpriteEngineSub;extern void *g3DSpriteEngineMain;extern u8 gSpriteDesc16x16[],gSpriteDesc32x32[],data_ov003_0220f61c[];
u16 **old; s32 i; s16 pos; s32 x,scroll; s16 scroll2;u16 neg;
if(!M2C_FIELD(a,u8 *,0x39))return;
UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x3c));UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x40));UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x44));
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
scroll=GetSpriteAnimValue(M2C_FIELD(a,s32 *,0x3c));neg=-scroll;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x3e)=neg;
i=0;M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x46)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x38)=neg;M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x40)=0;
M2C_FIELD(M2C_FIELD(a,void **,0x58),s16 *,6)=scroll+0xab;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),s32 *,0x1c))DrawTextSprite(M2C_FIELD(a,void **,0x58));
else {x=0xab;do {pos=x;if(func_ov003_021e50e0(pos,0x80,0x20,0x20))AddSprite((scroll+pos)&0x1ff,0x80,(u16)((0x3ff&(0x2ec>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|0x8000),gSpriteDesc32x32,11);x+=0x22;i++;}while(i<2);}
AddSprite((scroll+0xc5)&0x1ff,0x8e,(u16)((0x3ff&(0x288>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|0x6000),gSpriteDesc16x16,11);
AddSprite(0,(u8)(u32)GetSpriteAnimValue(M2C_FIELD(a,s32 *,0x44)),(u16)((0x3ff&(0x28c>>((**gCur3DSpriteEngine>>13)&3)))|0x8c00),data_ov003_0220f61c,11);
AddSprite32x16((scroll+0x30)&0x1ff,0x38,(u16)((0x3ff&(0x2fc>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|0x9000),11);
gCur3DSpriteEngine=g3DSpriteEngineSub;scroll2=GetSpriteAnimValue(M2C_FIELD(a,s32 *,0x3c));
func_ov003_021e5e24(a,scroll2,0);Ov003_DrawUnitCategoryGrid(a,scroll2,0);
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x3e)=-44-scroll2;M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x46)=0xffe9;gCur3DSpriteEngine=old;
}

#pragma cplusplus on
/* Confirm input handler of the ov003 map-info scene: update its option sprite
 * every frame and, while the option is enabled (or a B press arrives), play the
 * confirm sound, step the sprite's press animation and invoke the scene's
 * virtual confirm method. */
extern "C" void Ov003_MapInfoConfirmInput(void *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK MenuSpriteUpdate(void *);
    extern u16 *gKeyState;
    extern void *gTouchState;
    struct MapInfoScene {
        virtual void Slot00();
        virtual void Slot04();
        virtual void Slot08();
        virtual void Slot0C();
        virtual void Slot10();
        virtual void Slot14();
        virtual void Slot18();
        virtual void Slot1C();
        virtual void Slot20();
    };
    register u8 touchActive;
    s32 check;
    u16 keys;
    unsigned int optionEnabled;
    void *sprite;
    void *sprite2;
    void *owner;
    void *optionSprite;

    touchActive = M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE);
    keys = *gKeyState;
    MenuSpriteUpdate(*M2C_FIELD(arg0, void ***, 0x48));
    optionEnabled = 1;
    optionSprite = *M2C_FIELD(arg0, void ***, 0x48);
    owner = M2C_FIELD(optionSprite, void **, 0x64);
    check = M2C_FIELD(owner, s8 *, 0xB);
    if ((check != 1) && ((check = (u32) ((u32) (M2C_FIELD(optionSprite, u8 *, MENU_SPRITE_BASE) << 0x1B) >> 0x1F), (!check)) || (check = M2C_FIELD(owner, s8 *, 0xC), (check != 1)))) {
        optionEnabled = 0;
    }
    if (optionEnabled & 0xFF) {
        PlaySoundEffect(0x1000F);
        sprite = *M2C_FIELD(arg0, void ***, 0x48);
        if (M2C_FIELD(sprite, s8 *, MENU_SPRITE_TIMER) >= 0) {
            M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(sprite, s8 *, MENU_SPRITE_TIMER) = 0xC;
        }
        ((MapInfoScene *)arg0)->Slot20();
    }
    if (touchActive != 0) {
        return;
    }
    if (!(keys & KEY_B)) {
        return;
    }
    PlaySoundEffect(0x1000F);
    sprite2 = *M2C_FIELD(arg0, void ***, 0x48);
    if ((s32) M2C_FIELD(sprite2, s8 *, MENU_SPRITE_TIMER) >= 0) {
        M2C_FIELD(sprite2, s32 *, (unsigned)MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(sprite2, s32 *, MENU_SPRITE_FRAME) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(sprite2, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(sprite2, s8 *, MENU_SPRITE_TIMER) = 0xC;
    }
    ((MapInfoScene *)arg0)->Slot20();
}
#pragma cplusplus off
void func_ov003_021e5c68(void *arg0) {
    M2C_UNK SetOv003SceneState(M2C_UNK);
    SetOv003SceneState(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    Sprite_ResumeAnimation(arg0);
}

void func_ov003_021e5c8c(void) {
    M2C_UNK Sprite_ResumeAnimation();
    Sprite_ResumeAnimation();
}

/* Draws the eight unit-category icons of the ov003 map-info screen in a
 * three-column grid and prints, in front of each icon, how many units of that
 * category are on the current map (summed over all player bands). */
void Ov003_DrawUnitCategoryGrid(void *arg0, s16 arg1, s16 arg2) {
    void AddSprite(u16, u8, u16, void *, s32);
    s32 Divide(s32, s32);
    s32 Modulo(s32, s32);
    void SetTextSpriteValue(void *, s16);
    void DrawTextSprite(void *);
    s32 GetUnitCategoryCount(void *, s32, s32);
    s32 GetPropertyGridCountIndex(u8);
    extern u8 gSpriteDesc16x32[];
    extern u16 **gCur3DSpriteEngine, **g3DSpriteEngineSub;
    s32 xMask, tileMask, allPlayers, baseY, baseX;
    s16 x, y, count;
    void *ptr;
    s32 i, palette, tile;
    u16 **savedEngine;

    baseX = arg1;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3A) = -arg1;
    i = 0;
    tile = 0x210;
    baseY = arg2;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    allPlayers = -1;
    xMask = 0x1FF;
    tileMask = 0x3FF;
    do {
        x = Modulo(i, 3) * 22 + baseX;
        y = Divide(i, 3) * 28 + baseY;
        ptr = M2C_FIELD(arg0, u8 **, OV003_UNIT_COUNT_GRID);
        count = GetUnitCategoryCount((u8 *)ptr + 4, GetPropertyGridCountIndex(i), allPlayers);
        if (count) {
            savedEngine = gCur3DSpriteEngine;
            gCur3DSpriteEngine = g3DSpriteEngineSub;
            SetTextSpriteValue(M2C_FIELD(arg0, void **, OV003_UNIT_COUNT_TEXT), count);
            ptr = M2C_FIELD(arg0, void **, OV003_UNIT_COUNT_TEXT);
            M2C_FIELD(ptr, s16 *, 6) = x + 20;
            M2C_FIELD(ptr, s16 *, 8) = y + 102;
            DrawTextSprite(M2C_FIELD(arg0, void **, OV003_UNIT_COUNT_TEXT));
            gCur3DSpriteEngine = savedEngine;
        }
        palette = count ? 7 : 8;
        AddSprite((x + 4) & xMask, y + 78,
            (tileMask & (tile >> ((u32)(**gCur3DSpriteEngine << 17) >> 30))) | (u16)(palette << 12) | 0x400,
            gSpriteDesc16x32, 17);
        tile += 8;
        i++;
    } while (i < 8);
}

