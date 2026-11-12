/* 2 functions from 0x021F9B30 to 0x021F9FE0 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021f9b30(void *arg0) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK ScrollListTo(void *, u8, M2C_UNK);
    M2C_UNK func_020ab3b0(void *, u8, M2C_UNK);
    u32 func_020d886c();
    M2C_UNK func_ov003_021f92f4(void *, M2C_UNK);
    extern u16 **data_027e01d8;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 var_r1;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    s32 ptr_2;
    s32 ptr_3;
    u32 temp_r0_2;
    u32 temp_r0_3;
    void *temp_r0;

    MI_CpuFill8(M2C_FIELD(arg0, s32 *, 0x44) + 0x186C, 0, 0xD);
    Clear3DSpriteLayer(0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
    temp_r0 = M2C_FIELD(arg0, void **, 0x4C);
    M2C_FIELD(temp_r0, s32 *, 0x18) = (s32) (M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x44) + ((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4) << 9)), u8 *, 0x22D) - 1);
    if (M2C_FIELD(temp_r0, u8 *, 0x24) != 0) {
        var_r1 = M2C_FIELD(temp_r0, s32 *, 0x14);
        if (var_r1 > M2C_FIELD(temp_r0, s32 *, 0x18)) {
            do {
                var_r1 = M2C_FIELD(temp_r0, s32 *, 0x14) - ((M2C_FIELD(temp_r0, s32 *, 0x18) - M2C_FIELD(temp_r0, s32 *, 0x1C)) + 1);
                M2C_FIELD(temp_r0, s32 *, 0x14) = var_r1;
            } while (var_r1 > (s32) M2C_FIELD(temp_r0, s32 *, 0x18));
        }
        if (var_r1 < (s32) M2C_FIELD(temp_r0, s32 *, 0x1C)) {
            do {
                temp_r1 = M2C_FIELD(temp_r0, s32 *, 0x14) + ((M2C_FIELD(temp_r0, s32 *, 0x18) - M2C_FIELD(temp_r0, s32 *, 0x1C)) + 1);
                M2C_FIELD(temp_r0, s32 *, 0x14) = temp_r1;
            } while (temp_r1 < (s32) M2C_FIELD(temp_r0, s32 *, 0x1C));
        }
    } else {
        var_r2 = M2C_FIELD(temp_r0, s32 *, 0x18);
        temp_r1_2 = M2C_FIELD(temp_r0, s32 *, 0x14);
        if (temp_r1_2 <= var_r2) {
            var_r2 = M2C_FIELD(temp_r0, s32 *, 0x1C);
            if (temp_r1_2 >= var_r2) {
                var_r2 = temp_r1_2;
            }
        }
        M2C_FIELD(temp_r0, s32 *, 0x14) = var_r2;
    }
    temp_r0_2 = func_020d886c();
    switch (temp_r0_2) {
    case 28: var_r2_2 = 7; break;
    case 6: var_r2_2 = 1; break;
    case 22: case 23: var_r2_2 = 3; break;
    case 12: var_r2_2 = 5; break;
    case 5: case 7: var_r2_2 = 0; break;
    case 24: var_r2_2 = 2; break;
    case 8: var_r2_2 = 6; break;
    case 14: var_r2_2 = 9; break;
    case 15: var_r2_2 = 0xA; break;
    case 16: var_r2_2 = 0xB; break;
    case 17: var_r2_2 = 0xC; break;
    default:
    case 0: case 1: case 2: case 3: case 4: case 9: case 10: case 11: case 13: case 18: case 19: case 20: case 21: case 25: case 26: case 27:
        var_r2_2 = 4; break;
    }
    ptr_2 = (var_r2_2 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4);
    func_020ab3b0(M2C_FIELD(arg0, void **, 0x4C), M2C_FIELD(ptr_2, u8 *, 0xA9), 1);
    temp_r0_3 = func_020d886c();
    switch (temp_r0_3) {
    case 28: var_r2_3 = 7; break;
    case 6: var_r2_3 = 1; break;
    case 22: case 23: var_r2_3 = 3; break;
    case 12: var_r2_3 = 5; break;
    case 5: case 7: var_r2_3 = 0; break;
    case 24: var_r2_3 = 2; break;
    case 8: var_r2_3 = 6; break;
    case 14: var_r2_3 = 9; break;
    case 15: var_r2_3 = 0xA; break;
    case 16: var_r2_3 = 0xB; break;
    case 17: var_r2_3 = 0xC; break;
    default:
    case 0: case 1: case 2: case 3: case 4: case 9: case 10: case 11: case 13: case 18: case 19: case 20: case 21: case 25: case 26: case 27:
        var_r2_3 = 4; break;
    }
    ptr_3 = (var_r2_3 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4);
    ScrollListTo(M2C_FIELD(arg0, void **, 0x4C), M2C_FIELD(ptr_3, u8 *, 0xD), 1);
    func_ov003_021f92f4(arg0, 0);
}

/* Redraw the 3x3 icon grid at (baseX, baseY): for each of the eight slots look up
 * its count and draw the matching 16x32 tile plus the count in front of it. */
void Ov003_DrawIconGrid(void *arg0,s16 arg1,s16 arg2){
void AddSprite(u16,u8,u16,void *,s32);s32 Divide(s32,s32);s32 Modulo(s32,s32);
void SetTextSpriteValue(void *,s16);void DrawTextSprite(void *);s32 GetUnitCategoryCount(void *,s32,s32);s32 GetIconGridRecordIndex(u8);
extern u8 gSpriteDesc16x32[];extern u16 **gCur3DSpriteEngine,**g3DSpriteEngineSub;
s32 xMask,tileMask,allIndex,baseY,baseX; s16 x,y,count;void *p; s32 i,palette,tile;u16 **savedEngine;
baseX=arg1;
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x3a)=-arg1;
i=0;tile=0x210;baseY=arg2;
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x42)=0;
allIndex=-1;xMask=0x1ff;tileMask=0x3ff;
do{
x=Modulo(i,3)*22+baseX;
y=Divide(i,3)*28+baseY;
p=M2C_FIELD(arg0,void **,0x44);
count=GetUnitCategoryCount((u8 *)p+0x1830,GetIconGridRecordIndex(i),allIndex);
if(count){
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
SetTextSpriteValue(M2C_FIELD(arg0,void **,0x54),count);
p=M2C_FIELD(arg0,void **,0x54);
M2C_FIELD(p,s16 *,6)=x+20;M2C_FIELD(p,s16 *,8)=y+102;
DrawTextSprite(M2C_FIELD(arg0,void **,0x54));gCur3DSpriteEngine=savedEngine;
}
palette=count?7:8;
AddSprite((x+4)&xMask,y+78,(tileMask&(tile>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|(u16)(palette<<12)|0x400,gSpriteDesc16x32,17);
tile+=8;i++;
}while(i<8);
}
