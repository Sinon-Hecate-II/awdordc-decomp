/* 3 functions from 0x021A2100 to 0x021A2FE8 (ov000), found by ds-decomp. */
#include "common.h"

/* Among candidate entries, return index of the one with highest score that is visible/passable. */
s16 func_ov000_021a2100(s32 areaX, s32 areaY) {
    void func_01ffb554(void *);
    void func_01ffada0(s32, s32, s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 *data_ov000_021df578;
    extern u8 data_ov000_021e00ac;
    extern s8 data_ov000_021e0f60[];
    u8 *entry;
    s32 i;
    s32 bestScore;
    s16 bestIndex;
    u8 score;

    bestScore = 0;
    bestIndex = -1;
    entry = &data_ov000_021e00ac;
    func_01ffb554(data_ov000_021e0f60);
    func_01ffada0(areaX, areaY, 1, 3, 0);
    func_01ffb554((u8 *)*gCurrentMap + 0x1E30);
    for (i = 0; i < *data_ov000_021df578; i++, entry += 12) {
        if (entry[3] < 252U && entry[2] == 1 &&
            data_ov000_021e0f60[entry[0] + entry[1] * M2C_FIELD(*gCurrentMap, u16 *, 0x5144)] >= 0) {
            score = entry[8];
            if (bestScore <= score) {
                bestScore = score;
                bestIndex = i;
            }
        }
    }
    return bestIndex;
}

s32 func_ov000_021a21f8(s32 arg0) { return 0; }

#pragma opt_propagation off
/* Plan a special-unit action if no conflicting units exist, a target is available, and the player can afford it. */
s32 func_ov000_021a2db8(void) {
 void func_01ffada0(s32,s32,s32,s32,s32);
 s32 func_020d243c(u16); s32 func_020d2d18(u16,u8);
 s32 func_ov000_0217bc84(s32,s32,s32);
 void func_ov000_021a07c0(s32); s32 func_ov000_021a6d4c(void);
 extern void **gCurrentMap; extern u16 data_ov000_021aeef4[];
 extern void *data_ov000_021df580; extern u8 data_ov000_021df7d0[];
 s32 unitIndex,choice; u32 unitKind; u8 *unit; void *map; void *lastMap; u16 player;
 if(!func_020d243c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))return 0;
 map=*gCurrentMap;
 unitIndex=data_ov000_021aeef4[M2C_FIELD(map,u16 *,0x52a4)]+1;
 if(unitIndex<data_ov000_021aeef4[M2C_FIELD(map,u16 *,0x52a4)]+51){
 unit=map+0x59a4+unitIndex*14;
 do{
 unitKind=(u32)(unit[0]<<26)>>26;
 if(unitKind==0)goto nextUnit;
 if(unitKind!=9 && unitKind!=7 && unitKind!=6)goto nextUnit;
 {
 if(((u32)(unit[11]<<28)>>28)==5)return 0;
 }
 nextUnit:unitIndex++;unit+=14;
 }while(unitIndex<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51);
 }
 unit=map+0x67a4+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*140;
 if(func_ov000_0217bc84(unit[43]&127,unit[44]&127,4)!=0 && (s32)M2C_FIELD(*gCurrentMap,u16 *,0x52a2)<10)return 0;
 map=*gCurrentMap;unit=map+0x67a4+M2C_FIELD(map,u16 *,0x52a4)*140;
 func_01ffada0(unit[43]&127,unit[44]&127,7,110,0);
 choice=func_ov000_021a6d4c();if(choice==-1)return 0;
 if(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,10)<<23)>>29)&2)data_ov000_021df7d0[6]=6;
 else data_ov000_021df7d0[6]=7;
 lastMap=*gCurrentMap;player=M2C_FIELD(lastMap,u16 *,0x52a4);
 if(func_020d2d18(player,data_ov000_021df7d0[6])*10>M2C_FIELD(lastMap+player*140,s32 *,0x67a4))return 0;
 func_ov000_021a07c0(choice);return 1;
}
