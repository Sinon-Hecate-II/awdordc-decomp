/* 3 functions from 0x02222204 to 0x022231F8 (ov011), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#define ROTATE_RIGHT(x,n) (((x)>>(n)) | ((x)<<(32-(n))))

#pragma push
#pragma opt_propagation off
void InitIntroOpeningScene(M2C_UNK arg0) {
    M2C_UNK ClearAll3DSpriteLayers();
    M2C_UNK AddSpriteToMainEngine(M2C_UNK, M2C_UNK, s32, M2C_UNK *, s32);
    M2C_UNK LoadOpeningAssetSet(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK LoadOpeningScreenAssets(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov011_02224e04(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_02101f2c;
    extern M2C_UNK data_02101f5c;
    extern u16 **g3DSpriteEngineSub;
    extern u16 **g3DSpriteEngineMain;
    extern u16 **data_027e01d8;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    s32 var_r9;
    u16 **temp_r11;
    u16 **var_r0;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;

    var_r9 = 0;
    temp_r11 = data_027e01d8;
    do {
        if (var_r9 == 0) {
            var_r0 = g3DSpriteEngineMain;
        } else {
            var_r0 = g3DSpriteEngineSub;
        }
        data_027e01d8 = var_r0;
        temp_r0 = *var_r0;
        sp18 = temp_r0;
        *sp18 = *sp18 | 0x10;
        temp_r0_2 = *data_027e01d8;
        sp14 = temp_r0_2;
        *sp14 = *sp14 | 0x20;
        temp_r0_3 = *data_027e01d8;
        sp10 = temp_r0_3;
        *sp10 = *sp10 | 0x40;
        temp_r0_4 = *data_027e01d8;
        spC = temp_r0_4;
        *spC = *spC | 0x80;
        temp_r0_5 = *data_027e01d8;
        sp8 = temp_r0_5;
        *sp8 = *sp8 | 0x100;
        temp_r0_6 = *data_027e01d8;
        sp4 = (u16 *)((u8 *)temp_r0_6 + 0x12);
        *sp4 = (s16) (*sp4 & ~0xC0);
        M2C_FIELD(*data_027e01d8, s8 *, 0x51) = 0;
        M2C_FIELD(*data_027e01d8, s8 *, 0x52) = 0;
        M2C_FIELD(*data_027e01d8, s8 *, 0x53) = 0;
        ClearAll3DSpriteLayers();
        M2C_FIELD(*data_027e01d8, s16 *, 0x38) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x40) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x3A) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x42) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x3C) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x44) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x3E) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x46) = 0;
    } while (++var_r9 < 2);
    data_027e01d8 = temp_r11;
    func_ov011_02224e04(arg0, 2, 2, 0x80, 0x60);
    func_ov011_02224e04(arg0, 2, 3, 0x80, 0x60);
    LoadOpeningAssetSet(arg0, 3, 0, 3);
    LoadOpeningAssetSet(arg0, 4, 1, 3);
    LoadOpeningAssetSet(arg0, 0x13, 2, 0);
    LoadOpeningScreenAssets(arg0, 0, 0);
    LoadOpeningScreenAssets(arg0, 1, 0);
    LoadOpeningScreenAssets(arg0, 7, 1);
    AddSpriteToMainEngine(0x40, 0x50, 0, &data_02101f2c, 0);
    AddSpriteToMainEngine(0, 0xAA, 0x6040, &data_02101f5c, 0);
    AddSpriteToMainEngine(0x80, 0xAA, 0x6060, &data_02101f5c, 0);
}

void func_ov011_022224a8(void *arg0) {
    M2C_UNK AddSpriteToMainEngine(M2C_UNK, M2C_UNK, s32, M2C_UNK *, s32);
    M2C_UNK AddSpriteToSubEngine(u16, u16, u16, M2C_UNK *, s32);
    extern M2C_UNK data_02101f2c;
    extern M2C_UNK data_02101f5c;
    extern M2C_UNK gSpriteDesc64x64;
    extern u16 **g3DSpriteEngineSub;
    extern u16 **g3DSpriteEngineMain;
    extern u16 **gCur3DSpriteEngine;
    extern u32 gFrameCounter;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    s32 var_r1;
    s32 var_r3;
    u16 zero;
    u8 temp_r1;
    u8 var_r7;
    u16 **temp_r2;
    u16 **var_lr;
    u16 **var_r6;
    void *temp_r6;
    void *temp_r6_10;
    void *temp_r6_11;
    void *temp_r6_12;
    void *temp_r6_13;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r6_4;
    void *temp_r6_5;
    void *temp_r6_6;
    void *temp_r6_7;
    void *temp_r6_8;
    void *temp_r6_9;

    var_r1 = 0;
    temp_r2 = (*(u16 **volatile *)&gCur3DSpriteEngine);
    zero = 0;
    do {
        var_lr = var_r1 == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        (*(u16 **volatile *)&gCur3DSpriteEngine) = var_lr;
        M2C_FIELD(*var_lr, s16 *, 0x38) = (s16) (u8) ((u32) gFrameCounter >> 2);
        var_r1 += 1;
        M2C_FIELD(*(*(u16 **volatile *)&gCur3DSpriteEngine), u16 *, 0x40) = zero;
    } while (var_r1 < 2);
    (*(u16 **volatile *)&gCur3DSpriteEngine) = temp_r2;
    var_r3 = zero;
    do {
        if (var_r3 == 0) {
            var_r6 = g3DSpriteEngineMain;
        } else {
            var_r6 = g3DSpriteEngineSub;
        }
        (*(u16 **volatile *)&gCur3DSpriteEngine) = var_r6;
        temp_r6 = *var_r6;
        sp34 = (u16 *)((u8 *)temp_r6 + 0x12);
        *sp34 = (*sp34 & ~1) | 1;
        temp_r6_2 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp30 = (u16 *)((u8 *)temp_r6_2 + 0x12);
        *sp30 = *sp30 & ~2;
        temp_r6_3 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp2C = (u16 *)((u8 *)temp_r6_3 + 0x12);
        *sp2C = *sp2C & ~4;
        temp_r6_4 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp28 = (u16 *)((u8 *)temp_r6_4 + 0x12);
        *sp28 = *sp28 & ~8;
        temp_r6_5 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp24 = (u16 *)((u8 *)temp_r6_5 + 0x12);
        *sp24 = *sp24 & ~0x10;
        temp_r6_6 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp20 = (u16 *)((u8 *)temp_r6_6 + 0x12);
        *sp20 = *sp20 & ~0x20;
        temp_r6_7 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp1C = (u16 *)((u8 *)temp_r6_7 + 0x12);
        *sp1C = *sp1C & ~0x100;
        temp_r6_8 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp18 = (u16 *)((u8 *)temp_r6_8 + 0x12);
        *sp18 = *sp18 & ~0x200;
        temp_r6_9 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp14 = (u16 *)((u8 *)temp_r6_9 + 0x12);
        *sp14 = *sp14 & ~0x400;
        temp_r6_10 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp10 = (u16 *)((u8 *)temp_r6_10 + 0x12);
        *sp10 = *sp10 | 0x800;
            temp_r6_11 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        spC = (u16 *)((u8 *)temp_r6_11 + 0x12);
        *spC = *spC & ~0x1000;
        temp_r6_12 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp8 = (u16 *)((u8 *)temp_r6_12 + 0x12);
        *sp8 = *sp8 & ~0x2000;
        temp_r6_13 = *(*(u16 **volatile *)&gCur3DSpriteEngine);
        sp4 = (u16 *)((u8 *)temp_r6_13 + 0x12);
        *sp4 = (*sp4 & ~0xC0) | 0x40;
        M2C_FIELD(*(*(u16 **volatile *)&gCur3DSpriteEngine), s8 *, 0x51) = 8;
        M2C_FIELD(*(*(u16 **volatile *)&gCur3DSpriteEngine), s8 *, 0x52) = 8;
    } while (++var_r3 < 2);
    (*(u16 **volatile *)&gCur3DSpriteEngine) = temp_r2;
    temp_r1 = M2C_FIELD(arg0, u8 *, 0x37);
    if (temp_r1 == (temp_r1 & M2C_FIELD(arg0, u16 *, 0x34))) {
        AddSpriteToMainEngine(0x40, 0x50, 0, &data_02101f2c, 0);
    }
    AddSpriteToMainEngine(0, 0xAA, 0x6040, &data_02101f5c, 0);
    AddSpriteToMainEngine(0x80, 0xAA, 0x6060, &data_02101f5c, 0);
    var_r7 = 0;
    do {
        AddSpriteToSubEngine((u16) (0x1FF & ((var_r7 % 4) << 6)), (u16) ((u8) ((((u32)var_r7 >> 2) << 6) + 0x20) | 0x2000), (u16) (0x3FF & (var_r7 << 7)), &gSpriteDesc64x64, 0);
        var_r7 += 1;
    } while ((u32) var_r7 < 8U);
}

#pragma pop
/* Blend the 3D sprite's layers: on the selected engine(s) set the bank's blend
 * word to source layer `sourceLayer` and target layer `targetLayer` with the
 * alpha effect, and set the two blend weights to 16-blendAmount (source) and
 * blendAmount (target).  `engineSelect` is 0 for the main engine, 1 for the sub
 * engine, 3 for whichever engine is already current, and anything else (2 at the
 * call sites) for both engines. */
void Set3DSpriteBlendLayers(void *unused,u32 engineSelect,u32 sourceLayer,u32 targetLayer,u32 blendAmount) {
extern u16 **gCur3DSpriteEngine,**g3DSpriteEngineSub,**g3DSpriteEngineMain;
u8 rowsBelow,rowsAbove;
u16 **savedEngine,**engine;
s32 i;
u16 *volatile blendWord0;
u16 *volatile blendWord1;
u16 *volatile blendWord2;
u16 *volatile blendWord3;
u16 *volatile blendWord4;
u16 *volatile blendWord5;
u16 *volatile blendWord6;
u16 *volatile blendWord7;
u16 *volatile blendWord8;
u16 *volatile blendWord9;
u16 *volatile blendWord10;
u16 *volatile blendWord11;
u16 *volatile blendWord12;
u16 *volatile blendWord13;
u16 *volatile blendWord14;
u16 *volatile blendWord15;
u16 *volatile blendWord16;
u16 *volatile blendWord17;
u16 *volatile blendWord18;
u16 *volatile blendWord19;
u16 *volatile blendWord20;
u16 *volatile blendWord21;
u16 *volatile blendWord22;
u16 *volatile blendWord23;
u16 *volatile blendWord24;
u16 *volatile blendWord25;
u16 *volatile blendWord26;
u16 *volatile blendWord27;
u16 *volatile blendWord28;
u16 *volatile blendWord29;
u16 *volatile blendWord30;
u16 *volatile blendWord31;
u16 *volatile blendWord32;
u16 *volatile blendWord33;
u16 *volatile blendWord34;
u16 *volatile blendWord35;
u16 *volatile blendWord36;
u16 *volatile blendWord37;
u16 *volatile blendWord38;
u16 *volatile blendWord39;
u16 *volatile blendWord40;
u16 *volatile blendWord41;
u16 *volatile blendWord42;
u16 *volatile blendWord43;
u16 *volatile blendWord44;
u16 *volatile blendWord45;
u16 *volatile blendWord46;
u16 *volatile blendWord47;
u16 *volatile blendWord48;
u16 *volatile blendWord49;
u16 *volatile blendWord50;
u16 *volatile blendWord51;
u16 *volatile blendWord52;
u16 *volatile blendWord53;
u16 *volatile blendWord54;
u16 *volatile blendWord55;
u16 *volatile blendWord56;
u16 *volatile blendWord57;
u16 *volatile blendWord58;
u16 *volatile blendWord59;
u16 *volatile blendWord60;
i=0;
if(blendAmount>16)blendAmount=16;
rowsAbove=16-blendAmount;rowsBelow=blendAmount;
savedEngine=gCur3DSpriteEngine;
for(;i<2;i++){
engine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
if(engineSelect==0&&engine!=g3DSpriteEngineMain)continue;
if(engineSelect==1&&engine!=g3DSpriteEngineSub)continue;
if(engineSelect==3&&engine!=savedEngine)continue;
switch(sourceLayer){
case DS3D_BLEND_LAYER_BG0:
blendWord0=(u16 *)((u8 *)*engine+DS3D_BANK_OAMATTR);
*blendWord0=(*blendWord0&~DS3D_BLEND_SRC_BG0)|DS3D_BLEND_SRC_BG0;
blendWord1=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord1=*blendWord1&~DS3D_BLEND_SRC_BG1;
blendWord2=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord2=*blendWord2&~DS3D_BLEND_SRC_BG2;
blendWord3=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord3=*blendWord3&~DS3D_BLEND_SRC_BG3;
blendWord4=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord4=*blendWord4&~DS3D_BLEND_SRC_OBJ;
break;
case DS3D_BLEND_LAYER_BG1:
blendWord5=(u16 *)((u8 *)*engine+DS3D_BANK_OAMATTR);
*blendWord5=*blendWord5&~DS3D_BLEND_SRC_BG0;
blendWord6=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord6=*blendWord6|DS3D_BLEND_SRC_BG1;
blendWord7=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord7=*blendWord7&~DS3D_BLEND_SRC_BG2;
blendWord8=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord8=*blendWord8&~DS3D_BLEND_SRC_BG3;
blendWord9=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord9=*blendWord9&~DS3D_BLEND_SRC_OBJ;
break;
case DS3D_BLEND_LAYER_BG2:
blendWord10=(u16 *)((u8 *)*engine+DS3D_BANK_OAMATTR);
*blendWord10=*blendWord10&~DS3D_BLEND_SRC_BG0;
blendWord11=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord11=*blendWord11&~DS3D_BLEND_SRC_BG1;
blendWord12=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord12=*blendWord12|DS3D_BLEND_SRC_BG2;
blendWord13=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord13=*blendWord13&~DS3D_BLEND_SRC_BG3;
blendWord14=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord14=*blendWord14&~DS3D_BLEND_SRC_OBJ;
break;
case DS3D_BLEND_LAYER_BG3:
blendWord15=(u16 *)((u8 *)*engine+DS3D_BANK_OAMATTR);
*blendWord15=*blendWord15&~DS3D_BLEND_SRC_BG0;
blendWord16=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord16=*blendWord16&~DS3D_BLEND_SRC_BG1;
blendWord17=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord17=*blendWord17&~DS3D_BLEND_SRC_BG2;
blendWord18=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord18=*blendWord18|DS3D_BLEND_SRC_BG3;
blendWord19=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord19=*blendWord19&~DS3D_BLEND_SRC_OBJ;
break;
case DS3D_BLEND_LAYER_OBJ:
blendWord20=(u16 *)((u8 *)*engine+DS3D_BANK_OAMATTR);
*blendWord20=*blendWord20&~DS3D_BLEND_SRC_BG0;
blendWord21=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord21=*blendWord21&~DS3D_BLEND_SRC_BG1;
blendWord22=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord22=*blendWord22&~DS3D_BLEND_SRC_BG2;
blendWord23=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord23=*blendWord23&~DS3D_BLEND_SRC_BG3;
blendWord24=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord24=*blendWord24|DS3D_BLEND_SRC_OBJ;
break;
default:
blendWord25=(u16 *)((u8 *)*engine+DS3D_BANK_OAMATTR);
*blendWord25=*blendWord25&~DS3D_BLEND_SRC_BG0;
blendWord26=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord26=*blendWord26&~DS3D_BLEND_SRC_BG1;
blendWord27=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord27=*blendWord27&~DS3D_BLEND_SRC_BG2;
blendWord28=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord28=*blendWord28&~DS3D_BLEND_SRC_BG3;
blendWord29=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord29=*blendWord29&~DS3D_BLEND_SRC_OBJ;
break;
}
switch(targetLayer){
case DS3D_BLEND_LAYER_BG0:
blendWord30=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord30=*blendWord30|DS3D_BLEND_DST_BG0;
blendWord31=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord31=*blendWord31&~DS3D_BLEND_DST_BG1;
blendWord32=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord32=*blendWord32&~DS3D_BLEND_DST_BG2;
blendWord33=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord33=*blendWord33&~DS3D_BLEND_DST_BG3;
blendWord34=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord34=*blendWord34&~DS3D_BLEND_DST_OBJ;
break;
case DS3D_BLEND_LAYER_BG1:
blendWord35=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord35=*blendWord35&~DS3D_BLEND_DST_BG0;
blendWord36=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord36=*blendWord36|DS3D_BLEND_DST_BG1;
blendWord37=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord37=*blendWord37&~DS3D_BLEND_DST_BG2;
blendWord38=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord38=*blendWord38&~DS3D_BLEND_DST_BG3;
blendWord39=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord39=*blendWord39&~DS3D_BLEND_DST_OBJ;
break;
case DS3D_BLEND_LAYER_BG2:
blendWord40=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord40=*blendWord40&~DS3D_BLEND_DST_BG0;
blendWord41=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord41=*blendWord41&~DS3D_BLEND_DST_BG1;
blendWord42=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord42=*blendWord42|DS3D_BLEND_DST_BG2;
blendWord43=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord43=*blendWord43&~DS3D_BLEND_DST_BG3;
blendWord44=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord44=*blendWord44&~DS3D_BLEND_DST_OBJ;
break;
case DS3D_BLEND_LAYER_BG3:
blendWord45=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord45=*blendWord45&~DS3D_BLEND_DST_BG0;
blendWord46=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord46=*blendWord46&~DS3D_BLEND_DST_BG1;
blendWord47=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord47=*blendWord47&~DS3D_BLEND_DST_BG2;
blendWord48=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord48=*blendWord48|DS3D_BLEND_DST_BG3;
blendWord49=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord49=*blendWord49&~DS3D_BLEND_DST_OBJ;
break;
case DS3D_BLEND_LAYER_OBJ:
blendWord50=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord50=*blendWord50&~DS3D_BLEND_DST_BG0;
blendWord51=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord51=*blendWord51&~DS3D_BLEND_DST_BG1;
blendWord52=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord52=*blendWord52&~DS3D_BLEND_DST_BG2;
blendWord53=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord53=*blendWord53&~DS3D_BLEND_DST_BG3;
blendWord54=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord54=*blendWord54|DS3D_BLEND_DST_OBJ;
break;
default:
blendWord55=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord55=*blendWord55&~DS3D_BLEND_DST_BG0;
blendWord56=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord56=*blendWord56&~DS3D_BLEND_DST_BG1;
blendWord57=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord57=*blendWord57&~DS3D_BLEND_DST_BG2;
blendWord58=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord58=*blendWord58&~DS3D_BLEND_DST_BG3;
blendWord59=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord59=*blendWord59&~DS3D_BLEND_DST_OBJ;
break;
}
blendWord60=(u16 *)((u8 *)*gCur3DSpriteEngine+DS3D_BANK_OAMATTR);
*blendWord60=(*blendWord60&~DS3D_BANK_BLEND_EFFECT_MASK)|DS3D_BANK_BLEND_EFFECT_ALPHA;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_ABOVE)=rowsAbove;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_BELOW)=rowsBelow;
}
gCur3DSpriteEngine=savedEngine;
}
#pragma opt_common_subs reset

