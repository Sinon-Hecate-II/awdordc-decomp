/* 3 functions from 0x02197814 to 0x02197A8C (ov000), found by ds-decomp. */
#include "common.h"

/* Returns 1 if the grid distance between two units is within range, adjusted by speed and terrain bonuses. */
s32 func_ov000_02197814(void *unitA, void *unitB, s32 bonus) {
    extern void **gCurrentMap;
    s32 func_0206409c(s32);
    s32 func_ov000_021a89a4(void *);
    s32 func_ov000_021a97e0(s32, u32);
    s32 func_ov000_021a9820(s32, u32);
    s32 func_ov000_021a98e4(u32);
    s32 dist, n, idx, v, limit;
    if (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0xc)) bonus++;
    dist = func_0206409c(M2C_FIELD(unitA, u8 *, 1) - M2C_FIELD(unitB, u8 *, 1));
    dist += func_0206409c(M2C_FIELD(unitA, u8 *, 2) - M2C_FIELD(unitB, u8 *, 2));
    if (func_ov000_021a98e4((u32)(M2C_FIELD(unitB, u8 *, 0) << 26) >> 26) == 0) {
        if (unitB) { if (!unitB) n = 0; else n = ((s32)((u8 *)unitB - ((u8 *)*gCurrentMap + 0x59a4))) / 14; idx = (n >> 6) + 1; } else idx = 0;
        v = func_ov000_021a89a4(unitA);
        limit = bonus + (v + func_ov000_021a97e0(idx, (u32)(M2C_FIELD(unitB, u8 *, 0) << 26) >> 26) + 1);
    } else {
        if (unitB) { if (!unitB) n = 0; else n = ((s32)((u8 *)unitB - ((u8 *)*gCurrentMap + 0x59a4))) / 14; idx = (n >> 6) + 1; } else idx = 0;
        v = func_ov000_021a89a4(unitA);
        limit = bonus + (v + func_ov000_021a9820(idx, (u32)(M2C_FIELD(unitB, u8 *, 0) << 26) >> 26));
    }
    if (dist > limit) return 0;
    return 1;
}

void func_ov000_0219798c(void) {

}

void func_ov000_02197990(void){extern void **gCurrentMap;void *p;u8 t;u32 k,j;if(!func_ov000_021973f8((u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26))return;func_01ffb554(*gCurrentMap+0x2d48);p=*gCurrentMap+0x58a4;while((u32)(M2C_FIELD(p,u16 *,2)<<22)>>28){if(M2C_FIELD(p,s8 *,6)==1){t=M2C_FIELD(p,u8 *,5);j=(u32)(t<<28);if((j>>31)!=0 || (k=(u32)(t<<29)>>29)==0 || !func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),k))func_020a5364(p,-1,0);}p+=8;}func_01ffb554(*gCurrentMap+0x1e30);}

