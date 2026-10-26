/* 7 functions from 0x02185360 to 0x021862E8 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_02185fb8(u8 *a,u8 *b,s32 c){
 s32 func_0206409c(s32); s32 func_ov000_021a97e0(s32,u32); extern void **data_027e0058;
 s32 dist,n;
 dist=func_0206409c(a[1]-b[1]);
 dist+=func_0206409c(a[2]-b[2]);
 if(b){if(!b)n=0;else n=((s32)b-(s32)((u8 *)*data_027e0058+0x59a4))/14;n=(n>>6)+1;}else n=0;
 if(dist>c+(func_ov000_021a97e0(n,(u32)(b[0]<<26)>>26)+1))return 0;return 1;
}
