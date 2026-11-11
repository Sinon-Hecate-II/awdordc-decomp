/* 6 functions from 0x021E5118 to 0x021E5E24 (ov003), found by ds-decomp. */
#include "common.h"
static inline void CallSlot20(void *p) { M2C_FIELD(M2C_FIELD(p,void **,0),void (**)(void *),32)(p); }

void func_ov003_021e5118(void *arg0) {
    M2C_UNK func_01ff9b38();
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK func_01ff9dd8(M2C_UNK);
    M2C_UNK func_01ff9e44(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_02007ef4(s32, s32, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK func_0207c780(s32, s32);
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02080944(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK LoadDecompressedFileTo(M2C_UNK *, s32);
    s32 func_02080e30(M2C_UNK *, M2C_UNK);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_02081340(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK *, s32);
    s32 func_0208206c();
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void *func_0208bc24(void *);
    M2C_UNK func_0208ca2c(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02091d4c(M2C_UNK);
    void *func_0209b26c(s16, M2C_UNK, M2C_UNK, s32, s32, u32);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    void *func_020ab1c4(void *);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK func_020ae528(s32);
    M2C_UNK DrawMapPreview(s32, s32, M2C_UNK, M2C_UNK);
    M2C_UNK *GetLocalizedFileName(M2C_UNK *);
    M2C_UNK func_020e35cc(s32);
    M2C_UNK func_020e4cd8(s32, s32, s32, M2C_UNK, s32, s32, s32);
    M2C_UNK func_ov000_0216a30c(s32, s32, M2C_UNK);
    M2C_UNK func_ov000_0216a470();
    s32 func_ov000_0216a564();
    s32 func_ov000_0216a76c();
    s32 func_ov000_0216a77c();
    M2C_UNK func_ov000_0216a7c4();
    s32 func_ov000_0216a7d4();
    s32 func_ov000_0216cdcc(u8);
    s32 func_ov000_0216cdec(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f1b38(M2C_UNK, M2C_UNK *);
    M2C_UNK func_ov003_021f1b7c(M2C_UNK, M2C_UNK *);
    u8 func_ov003_02200b5c(u8);
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
    func_01ff9b38();
    temp_r4 = M2C_FIELD(arg0, void ***, 0x48);
    *temp_r4 = func_020ab1c4(arg0);
    func_020aab24(*temp_r4, 2, 0x1A4, 3, 0);
    temp_r5 = *temp_r4;
    func_02088e84(temp_r5, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r9 = func_020aae10(temp_r5);
        func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7, temp_r6, (s32) temp_r9, (s32) func_020aae44(temp_r5));
    }
    func_02088da8(*temp_r4);
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
    func_02080944(M2C_FIELD(data_027e01d8, s32 *, 0x2C), 0x20, 0x20, 5);
    SetFileDirectory(&data_ov003_0220f7c0);
    LoadDecompressedFileTo(GetLocalizedFileName(&data_ov003_0220f7c8), M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x5180);
    LoadDecompressedFileTo(&data_ov003_0220f7dc, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x5100);
    LoadDecompressedFileTo(&data_ov003_0220f7ec, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x5D80);
    LoadDecompressedFileTo(&data_ov003_0220f7fc, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    func_020808dc(M2C_FIELD(data_027e01d8, s32 *, 0x2C), 0x20, 0x18, 5);
    LoadFileToSpriteBuffer(&data_ov003_0220f810, 0x300, 0x20);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    func_020a9a30(1, 0, 3, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x3680);
    func_020a9a30(1, 2, 0, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x2C0);
    Clear3DSpriteLayer(0);
    func_01ff9dd8(0);
    func_02091d4c(7);
    temp_r6_2 = data_027e01d8;
    func_020e4cd8(func_0208206c(), M2C_FIELD(temp_r6_2, s32 *, 0xC), M2C_FIELD(temp_r6_2, s32 *, 0x20), 7, 6, 4, 2);
    func_ov000_0216a470();
    func_ov000_0216a30c(func_ov000_0216a564(), 0x5F80, 9);
    if ((func_ov000_0216a76c() != -2) && (func_ov000_0216a76c() != -1)) {
        func_ov000_0216a76c();
        temp_r0_2 = func_0209b26c(0xC, 7, 0, func_ov000_0216a77c(), 0x7000, 0x320000U >> 0x10);
        temp_r4_5 = (M2C_FIELD(temp_r0_2, u16 *, 0x4C) - M2C_FIELD(temp_r0_2, u16 *, 0x4E)) + 2 + 0x32;
        temp_r6_3 = M2C_FIELD(temp_r0_2, u8 *, 0x4A) + 2;
        func_ov000_0216a7c4();
        func_0209b26c(temp_r6_3, 7, 0, func_ov000_0216a7d4(), 0x7000, (u32) temp_r4_5);
    }
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
    data_027e01d8 = g3DSpriteEngineSub;
    SetFileDirectory(&data_ov003_0220f824);
    LoadDecompressedFileTo(&data_ov003_0220f82c, M2C_FIELD(data_027e01d8, s32 *, 0x10));
    LoadDecompressedFileTo(&data_ov003_0220f83c, M2C_FIELD(data_027e01d8, s32 *, 0x24));
    LoadFileToSpriteBuffer(&data_ov003_0220f854, 0xE0, 0x20);
    func_020808dc(M2C_FIELD(data_027e01d8, s32 *, 0x24), 0x20, 0x20, 7);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    func_02091d4c(9);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    DrawMapPreview(M2C_FIELD(data_027e01d8, s32 *, 0xC), M2C_FIELD(data_027e01d8, s32 *, 0x20), 1, 5);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
    func_0208ca2c(0x5100, 0xA, func_020ae22c(0xA), 1);
    temp_r0_3 = func_02080e30(GetLocalizedFileName(&data_ov003_0220f868), 1);
    func_0207c780(temp_r0_3, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800);
    func_020e35cc(temp_r0_3);
    LoadFileToSpriteBuffer(&data_ov003_0220f87c, 0x2C0, 0x20);
    func_020a9a30(1, 0, 4, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x6500);
    func_020a9a30(1, 2, 0, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x360);
    func_020a9a30(1, 0, 0, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x4B00);
    func_020a9a30(1, 0, 2, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x4E00);
    func_020a9a30(1, 2, 0, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x320);
    var_r4 = 0;
    do {
        temp_r8 = M2C_FIELD(data_027e01d8, s32 *, 0x1C) + ((u32) (((var_r4 * 8) + 0x210) << 0x10) >> 0xB);
        func_02007ef4(func_ov000_0216cdcc(func_ov003_02200b5c(var_r4)), temp_r8, 0x100);
        var_r4 += 1;
    } while ((u32) var_r4 <= 7U);
    func_01ff9e44(func_ov000_0216cdec(0xF, 0), 0x2E0, 0x20);
    func_01ff9e44(func_ov000_0216cdec(0xF, 0), 0x300, 0x20);
    func_020ae528(M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x300);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 0x10);
    data_027e01d8 = temp_r5_2;
}

void func_ov003_021e5c98(void *,s16,s16);
void func_ov003_021e583c(void *a) {
void AddSprite(u16,u8,u16,void *,s32);void UpdateSpriteAnimation(s32);s16 GetSpriteAnimValue(s32);void func_020a94fc(void *);void func_ov000_0216a374(u16,s32,u16,s32);s32 func_ov003_021e50e0(s16,s32,s32,s32);void func_ov003_021e5e24(void *,s16,s16);
extern u16 **gCur3DSpriteEngine,**g3DSpriteEngineSub;extern void *g3DSpriteEngineMain;extern u8 gSpriteDesc16x16[],data_027e00ac[],data_ov003_0220f61c[];
u16 **old; s32 i; s16 pos; s32 x,scroll; s16 scroll2;u16 neg;
if(!M2C_FIELD(a,u8 *,0x39))return;
UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x3c));UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x40));UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x44));
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
scroll=GetSpriteAnimValue(M2C_FIELD(a,s32 *,0x3c));neg=-scroll;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x3e)=neg;
i=0;M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x46)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x38)=neg;M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x40)=0;
M2C_FIELD(M2C_FIELD(a,void **,0x58),s16 *,6)=scroll+0xab;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),s32 *,0x1c))func_020a94fc(M2C_FIELD(a,void **,0x58));
else {x=0xab;do {pos=x;if(func_ov003_021e50e0(pos,0x80,0x20,0x20))AddSprite((scroll+pos)&0x1ff,0x80,(u16)((0x3ff&(0x2ec>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|0x8000),data_027e00ac,11);x+=0x22;i++;}while(i<2);}
AddSprite((scroll+0xc5)&0x1ff,0x8e,(u16)((0x3ff&(0x288>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|0x6000),gSpriteDesc16x16,11);
AddSprite(0,(u8)(u32)GetSpriteAnimValue(M2C_FIELD(a,s32 *,0x44)),(u16)((0x3ff&(0x28c>>((**gCur3DSpriteEngine>>13)&3)))|0x8c00),data_ov003_0220f61c,11);
func_ov000_0216a374((scroll+0x30)&0x1ff,0x38,(u16)((0x3ff&(0x2fc>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|0x9000),11);
gCur3DSpriteEngine=g3DSpriteEngineSub;scroll2=GetSpriteAnimValue(M2C_FIELD(a,s32 *,0x3c));
func_ov003_021e5e24(a,scroll2,0);func_ov003_021e5c98(a,scroll2,0);
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x3e)=-44-scroll2;M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x46)=0xffe9;gCur3DSpriteEngine=old;
}

void func_ov003_021e5b18(void *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK MenuSpriteUpdate(void *);
    extern u16 *gKeyState;
    extern void *gTouchState;
    register u8 temp_r4;
    s32 var_r0;
    u16 temp_r5;
    unsigned int var_r3;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *temp_r2;

    temp_r4 = M2C_FIELD(gTouchState, u8 *, 0x12);
    temp_r5 = *gKeyState;
    MenuSpriteUpdate(*M2C_FIELD(arg0, void ***, 0x48));
    var_r3 = 1;
    temp_r2 = *M2C_FIELD(arg0, void ***, 0x48);
    temp_r1 = M2C_FIELD(temp_r2, void **, 0x64);
    var_r0 = M2C_FIELD(temp_r1, s8 *, 0xB);
    if ((var_r0 != 1) && ((var_r0 = (u32) ((u32) (M2C_FIELD(temp_r2, u8 *, 0x59) << 0x1B) >> 0x1F), (!var_r0)) || (var_r0 = M2C_FIELD(temp_r1, s8 *, 0xC), (var_r0 != 1)))) {
        var_r3 = 0;
    }
    if (var_r3 & 0xFF) {
        PlaySoundEffect(0x1000F);
        temp_r0 = *M2C_FIELD(arg0, void ***, 0x48);
        if (M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
            M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
        }
        CallSlot20(arg0);
    }
    if (temp_r4 != 0) {
        return;
    }
    if (!(temp_r5 & 2)) {
        return;
    }
    PlaySoundEffect(0x1000F);
    temp_r0_2 = *M2C_FIELD(arg0, void ***, 0x48);
    if ((s32) M2C_FIELD(temp_r0_2, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0_2, s32 *, (unsigned)0x40) = (s32) ((M2C_FIELD(temp_r0_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0_2, s8 *, 0x5A) = 0xC;
    }
    CallSlot20(arg0);
}

void func_ov003_021e5c68(void *arg0) {
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021e5c8c(void) {
    M2C_UNK func_01ffa6fc();
    func_01ffa6fc();
}

void func_ov003_021e5c98(void *arg0,s16 arg1,s16 arg2){
void AddSprite(u16,u8,u16,void *,s32);s32 Divide(s32,s32);s32 Modulo(s32,s32);
void func_020a92bc(void *,s16);void func_020a94fc(void *);s32 func_020c1980(void *,s32,s32);s32 func_ov003_02200ae8(u8);
extern u8 gSpriteDesc16x32[];extern u16 **gCur3DSpriteEngine,**g3DSpriteEngineSub;
s32 sp14,sp10,spC,sp8,sp4; s16 x,y,value;void *p; s32 i,palette,tile;u16 **old;
sp4=arg1;
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x3a)=-arg1;
i=0;tile=0x210;sp8=arg2;
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x42)=0;
spC=-1;sp14=0x1ff;sp10=0x3ff;
do{
x=Modulo(i,3)*22+sp4;
y=Divide(i,3)*28+sp8;
p=M2C_FIELD(arg0,void **,0x68);
value=func_020c1980((u8 *)p+4,func_ov003_02200ae8(i),spC);
if(value){
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
func_020a92bc(M2C_FIELD(arg0,void **,0x50),value);
p=M2C_FIELD(arg0,void **,0x50);
M2C_FIELD(p,s16 *,6)=x+20;M2C_FIELD(p,s16 *,8)=y+102;
func_020a94fc(M2C_FIELD(arg0,void **,0x50));gCur3DSpriteEngine=old;
}
palette=value?7:8;
AddSprite((x+4)&sp14,y+78,(sp10&(tile>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|(u16)(palette<<12)|0x400,gSpriteDesc16x32,17);
tile+=8;i++;
}while(i<8);
}

