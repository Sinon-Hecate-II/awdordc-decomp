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
