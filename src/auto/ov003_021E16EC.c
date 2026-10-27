/* 2 functions from 0x021E16EC to 0x021E2628 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021e2518(void *arg0) {
M2C_UNK func_020a8f8c(s32); s32 func_020a8ff4(s32);
M2C_UNK func_ov003_021e3960(void *,s32,M2C_UNK);
M2C_UNK func_ov003_021e3aec(void *,s32,M2C_UNK);
M2C_UNK func_ov003_021e3ff8(void *,s16,M2C_UNK);
extern s32 data_027e00c4; extern s32 data_027e00c8; extern s32 gCur3DSpriteEngine;
s32 v; s32 saved;
if(M2C_FIELD(arg0,u8 *,0x39)==0)return;
func_020a8f8c(M2C_FIELD(arg0,s32 *,0x3c));
func_020a8f8c(M2C_FIELD(arg0,s32 *,0x40));
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c));
func_020a8ff4(M2C_FIELD(arg0,s32 *,0x40));
M2C_FIELD(*(void **)gCur3DSpriteEngine,s16 *,0x3a)=-func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c));
M2C_FIELD(*(void **)gCur3DSpriteEngine,s16 *,0x42)=0;
func_ov003_021e3ff8(arg0,(s16)(func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c))+6),40);
v=data_027e00c4;
*(volatile s32 *)&gCur3DSpriteEngine=v;
v=func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c));
func_ov003_021e3aec(arg0,v,0);func_ov003_021e3960(arg0,v,0);
M2C_FIELD(*(void **)gCur3DSpriteEngine,s16 *,0x3e)=-44-v;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x46)=0xffe9;
gCur3DSpriteEngine=saved;
}
