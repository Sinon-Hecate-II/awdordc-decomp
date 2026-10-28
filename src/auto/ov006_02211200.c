/* 3 functions from 0x02211200 to 0x02212184 (ov006), found by ds-decomp. */
#include "common.h"


void func_ov006_02211200(void *arg0) {
M2C_UNK func_01ff9b38();
M2C_UNK func_02002bb8(M2C_UNK);
M2C_UNK func_02003560();
M2C_UNK func_020822b8(M2C_UNK *);
M2C_UNK func_02082cb4();
void *func_0208931c(M2C_UNK);
M2C_UNK func_020a9a30(M2C_UNK,M2C_UNK,M2C_UNK,s32);
s32 func_020aaf74(void *);
M2C_UNK func_020aeebc(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_020aef7c(M2C_UNK,M2C_UNK,M2C_UNK);
extern s32 data_027e00c4;
extern s32 data_027e00c8;
extern s32 gCur3DSpriteEngine;
extern M2C_UNK data_ov006_022183c8;
extern M2C_UNK data_ov006_022183d4;
s32 saved; void *p;
func_02082cb4();func_02003560();func_02002bb8(64);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
func_020822b8(&data_ov006_022183c8);func_020aeebc(2,15,5);
gCur3DSpriteEngine=data_027e00c4;
func_020822b8(&data_ov006_022183d4);func_020aef7c(2,15,5);
p=M2C_FIELD(arg0,void **,0x38)=func_0208931c(9);
M2C_FIELD(p,u8 *,0x58)=6;
func_020a9a30(2,0,6,M2C_FIELD((void *)gCur3DSpriteEngine,u32 *,0x1c)+0x4580);
func_020a9a30(2,2,6,M2C_FIELD((void *)gCur3DSpriteEngine,u32 *,0x30)+0x320);
M2C_FIELD(p,s32 *,0x44)=func_020aaf74(p);
M2C_FIELD(p,u16 *,0x3e)=0x22c;
M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|0x640000;
M2C_FIELD(p,u16 *,0x3c)=0xc00;
gCur3DSpriteEngine=saved;func_01ff9b38();
}

void func_ov006_02211314(M2C_UNK arg0) {
    M2C_UNK func_020899cc(void *, M2C_UNK, s32, s32);
    void *func_0208b564(M2C_UNK);
    s64 func_020c53e4(M2C_UNK);
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;
    void *temp_r0;
    if (func_020c53e4(0) == 0) {
        temp_r4 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        temp_r0 = func_0208b564(arg0);
        func_020899cc(temp_r0, 2, 0x4640, 0x42000001);
        M2C_FIELD(temp_r0, s32 *, 0x58) |= 0x1000;
        gCur3DSpriteEngine = temp_r4;
    }
}

void func_ov006_02211388(void *arg0) {
}

