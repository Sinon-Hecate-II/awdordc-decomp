/* 7 functions from 0x0217C9F4 to 0x0217D86C (ov000), found by ds-decomp. */
#include "common.h"

int func_ov000_0217d000(int r0, int r1) {
    r1 &= 0x1F;
    if (r1 == 0x11) {
        if ((unsigned int)r0 > 0x1A) {
            return 0;
        }
        switch (r0) {
        case 5: case 7: case 8: case 10: case 11:
        case 12: case 16: case 18: case 19: case 21:
        case 22: case 26:
            return 1;
        default:
            return 0;
        }
    }
    if (r1 == 0x12) {
        if (r0 >= 0 && r0 <= 0x11) {
            switch (r0) {
            case 6: case 12: case 14: case 16: case 17:
                return 1;
            default:
                goto case13;
            }
        } else if (r0 == 0x15) {
            return 1;
        } else {
            goto case13;
        }
    } else if (r1 != 0x13) {
        return 0;
    }
case13:
    r0 -= 0x0F;
    if ((unsigned int)r0 > 8) {
        return 0;
    }
    switch (r0) {
    case 0: case 2: case 3: case 5: case 6:
    case 7: case 8:
        return 1;
    default:
        return 0;
    }
}

void func_ov000_0217d3b8(s32 arg0) {
    s32 func_ov000_021a8ac8(void *);
    extern void **gCurrentMap;
    void *unit;
    if (arg0 != 3) return;
    unit = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) < 0x3DU) return;
    if (func_ov000_021a8ac8(unit) != 1) return;
    unit = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u8 *, 0xB) << 28) >> 28) == 0) {
        M2C_FIELD(unit, u8 *, 0xB) |= 0x20;
    }
}

void func_ov000_0217d6dc(void) {
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s32 func_ov000_021a98a8(u32);

    void ***mapSlot = &gCurrentMap;
    u16 *tblBase = data_ov000_021aeef4;

    void *map;
    void *m0;
    s32 i;
    u16 tbl;
    s32 off;
    u8 *rec;
    u32 kind;

    map = *mapSlot;
    m0 = *(void **)map;
    tbl = tblBase[M2C_FIELD(m0, u16 *, 0x52A4)];
    i = (s32)tbl + 1;
    if (i >= (s32)tbl + 0x33) return;

    off = i * 14;

    for (;;) {
        map = *mapSlot;
        m0 = *(void **)map;
        rec = (u8 *)m0 + 0x59A4 + off;

        kind = ((u32)rec[0] << 26) >> 26;
        if (kind == 0) goto loopinc;
        if (func_ov000_021a98a8(kind) == 0) goto loopinc;
        if ((((u32)rec[11] << 26) >> 31) == 0) goto loopinc;

        {
            u16 hw = *(u16 *)(rec + 8);
            u32 low = ((u32)hw << 26) >> 26;
            map = *mapSlot;
            m0 = *(void **)map;
            if (low != 0x3F) {
                u32 idx = ((u32)hw << 20) >> 26;
                u16 rowval = *(u16 *)((u8 *)m0 + idx * 2 + 0x3758);
                signed char attrib = *(signed char *)((u8 *)m0 + low + rowval + 0x1928);
                u8 *p = (u8 *)m0 + 0x6C60 + (s32)attrib * 6;
                if (p[3] != 0) p[3] = (u8)(p[3] - 1);
            } else {
                u8 rec2 = rec[2];
                u8 rec1 = rec[1];
                u16 rowval = *(u16 *)((u8 *)m0 + (u32)rec2 * 2 + 0x3758);
                signed char attrib = *(signed char *)((u8 *)m0 + (u32)rec1 + rowval + 0x1928);
                u8 *p = (u8 *)m0 + 0x6C60 + (s32)attrib * 6;
                if (p[3] != 0) p[3] = (u8)(p[3] - 1);
            }
        }

        {
            u16 t = *(u16 *)(rec + 8);
            t = (u16)((t & ~0x3F) | 0x3F);
            *(u16 *)(rec + 8) = t;
        }
        {
            u16 t = *(u16 *)(rec + 8);
            t = (u16)((t & ~0xFC0) | 0xFC0);
            *(u16 *)(rec + 8) = t;
        }
        rec[11] = (u8)(rec[11] & ~0x20);

loopinc:
        map = *mapSlot;
        m0 = *(void **)map;
        i++;
        off = off + 14;
        tbl = tblBase[M2C_FIELD(m0, u16 *, 0x52A4)];
        if (i < (s32)tbl + 0x33) continue;
        break;
    }
}

void func_ov000_0217d850(void) {
    extern void *data_ov000_021df580;
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8) (M2C_FIELD(data_ov000_021df580, u8 *, 7) & ~8);
}
