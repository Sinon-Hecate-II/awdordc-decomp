/* 4 functions from 0x0218BBD0 to 0x0218CBC0 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0218ca94(void) {
extern void **data_027e0058;
switch(func_ov000_021a98e4((u32)(*M2C_FIELD(*data_027e0058,u8 **,0x52d0)<<26)>>26)){
case 0: func_ov000_0218b0d8(0); return;
case 1: if(func_020a85c8((u32)(*M2C_FIELD(*data_027e0058,u8 **,0x52d0)<<26)>>26))func_ov000_0218c400(0);else func_ov000_0218bbd0(0);return;
}}

s32 func_ov000_0218cb20(void) {
extern void **data_027e0058;
u32 x=(u32)(*M2C_FIELD(*data_027e0058,u8 **,0x52d0)<<26)>>26;
if(x==6)return 0;
switch(func_ov000_021a98e4(x)){
case 0: return func_ov000_0218b0d8(1);
case 1: if(func_020a85c8((u32)(*M2C_FIELD(*data_027e0058,u8 **,0x52d0)<<26)>>26))return func_ov000_0218c400(1);else return func_ov000_0218bbd0(1);
default:return 0;
}}

