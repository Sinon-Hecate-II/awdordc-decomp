/* 2 functions from 0x022066A8 to 0x022066D8 (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_menu.h"

extern MenuLayout gUnitListLayouts[];
extern MenuRowGroup gUnitListRowGroups[];
/* The rows of unit-list menu `menu`: the row group its layout record points at. */
MenuRowGroup *Ov003_GetMenuRowGroup(s32 menu) {
    return &gUnitListRowGroups[gUnitListLayouts[menu].rowGroup];
}

u8 func_ov003_022066c8(s32 arg0) {
    extern u8 data_ov003_0220f239;
    return (&data_ov003_0220f239)[arg0 * 0x10];
}
