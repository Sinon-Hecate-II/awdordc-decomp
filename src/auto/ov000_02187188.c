/* 9 functions from 0x02187188 to 0x02187F7C (ov000), found by ds-decomp. */
#include "common.h"
extern void (*data_ov000_021df648)(void);
void func_ov000_02188338(void);
extern void **data_027e0058;

void func_ov000_02187e20(void) {
func_ov000_02187820();
if(data_ov000_021df648==func_ov000_02188338) func_ov000_021879f4();
func_ov000_02187c3c();
}

u8 func_ov000_02187e50(void) {
void *base=*data_027e0058;
s32 v=M2C_FIELD(M2C_FIELD(base,void **,0x52d0),u16 *,8);
u32 x=(u32)(v<<26)>>26;
u32 y; u8 result;
if(x==63) return 0;
y=(u32)(v<<20)>>26;
if(((s8 **)((u8 *)base+0x52e8))[y][x]>=0) result=1; else result=0;
return result;
}

u8 func_ov000_021a9084(s32);
s32 func_ov000_02187eac(u16 *arg0) {
    extern void **data_027e0058;
    void *base;
    s32 height;
    s32 width;
    s32 y = 0;
    s32 x;
    u16 rowoff;
    u8 v;

    base = *data_027e0058;
    height = *(u16 *)((u8 *)base + 0x5146);
    if (height <= 0) return 0;
outer:
    width = *(u16 *)((u8 *)base + 0x5144);
    x = y;
    if (width > 0) {
        do {
            if (((s8 **)((u8 *)base + 0x52e8))[y][x] >= 0) {
                rowoff = *(u16 *)((u8 *)base + 0x3758 + y * 2);
                v = *(u8 *)((u8 *)base + 0x1420 + rowoff + x);
                if (func_ov000_021a9084(v)) {
                    arg0[0] = (u16)x;
                    arg0[1] = (u16)y;
                    return 1;
                }
            }
            base = *data_027e0058;
            x = x + 1;
            width = *(u16 *)((u8 *)base + 0x5144);
        } while (x < width);
    }
    height = *(u16 *)((u8 *)base + 0x5146);
    y = y + 1;
    if (y < height) goto outer;
    return 0;
}

