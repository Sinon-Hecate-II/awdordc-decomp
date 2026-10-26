/* 28 functions from 0x020AF760 to 0x020B0658 (main), found by ds-decomp. */
#include "common.h"

void func_020af760(void) {
M2C_UNK func_02090448(s32); extern M2C_UNK gPlayerSettings;
s32 i=0; u8 *p=(u8*)&gPlayerSettings;
do { s32 v=*M2C_FIELD(M2C_FIELD(p,void **,4),s32 **,0x34); if(v)func_02090448(v); i++; p+=0x18; }while(i<2);
}

void func_020af79c(void) {
    M2C_UNK func_02090480(M2C_UNK);
    func_02090480(0);
}

void func_020af7ac(void) {
extern u8 data_0215c430; extern u8 data_0215c42c;
s32 i=0; volatile u8 *p=&data_0215c430; volatile u8 *q=&data_0215c42c; u8 zero=0;
do { i++; *p++=zero; *q++=zero; } while(i<2);
}

void func_020af7dc(void) {
    extern u8 data_0215c42c;
    extern u8 data_0215c430;
    s32 var_r1;
    u8 *var_r2;
    u8 *var_r3;
    u8 temp_r0;
    u8 temp_r0_2;

    var_r2 = &data_0215c430;
    var_r3 = &data_0215c42c;
    var_r1 = 0;
    do {
        temp_r0 = *var_r2;
        var_r1 += 1;
        if (temp_r0 != 0) {
            *var_r2 = temp_r0 - 1;
        }
        temp_r0_2 = *var_r3;
        var_r2 += 1;
        if (temp_r0_2 != 0) {
            *var_r3 = temp_r0_2 - 1;
        }
        var_r3 += 1;
    } while (var_r1 < 2);
}

void func_020af828(s32 arg0, s32 arg1) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_0208ff94(M2C_UNK);
    if (arg1 == 0) {
        return;
    }
    func_0208fe30(arg1);
    if (arg0 == 0) {
        func_0208ff94(-0x80);
        return;
    }
    func_0208ff94(0x7F);
}

void func_020af860(s32 arg0,s32 arg1) {
M2C_UNK func_0208ffe4(s32,s32); M2C_UNK func_02090100(s32,s32); M2C_UNK func_020af8c8(s32,s32);
extern M2C_UNK data_ov002_021f30f4;
s32 value; void *base=(u8*)&data_ov002_021f30f4+arg0*0x18;
value=M2C_FIELD(M2C_FIELD(*(void **)base,void **,0x34),s32 *,4);
if(value==0)return;
func_0208ffe4(arg0,-1);
if(arg0==0)func_02090100(arg0,-128);else func_02090100(arg0,127);
func_020af8c8(arg0,arg1);
}

void func_020af9cc(s32 arg0,s32 arg1,s32 arg2) {
M2C_UNK func_02090034(s32,s32); extern M2C_UNK data_ov002_021f30f4;
if(arg2==0 && M2C_FIELD(*(void **)((u8*)&data_ov002_021f30f4+arg0*0x18),u8 *,0x3d)==3)return;
func_02090034(arg0,arg1);
}

void func_020afa00(s32 a){extern M2C_UNK data_ov002_021f30f4;extern u8 data_ov002_021f3103;extern u8 data_0215c430;u32 n=*((u8 *)&data_ov002_021f3103+a*24);void *p=*(void **)((u8 *)&data_ov002_021f30f4+a*24);if(M2C_FIELD((u8 *)p+n,u8 *,0x3e)==1){if((&data_0215c430)[a])return;(&data_0215c430)[a]=4;}func_020af828(a,M2C_FIELD((u8 *)M2C_FIELD(p,void **,0x34)+n*4,s32 *,8));}

void func_020afa64(s32 a){extern M2C_UNK data_ov002_021f30f4;s32 b;if(a==0)b=1;else b=0;func_020af828(a,M2C_FIELD(M2C_FIELD(*(void **)((u8 *)&data_ov002_021f30f4+b*24),void **,0x34),s32 *,0x10));}

void func_020afa98(s32 a){extern M2C_UNK data_ov002_021f30f4;extern u8 data_ov002_021f3103;extern u8 data_0215c42c;s32 n;if(M2C_FIELD((u8 *)*(void **)((u8 *)&data_ov002_021f30f4+(a==0?1:0)*24)+*((u8 *)&data_ov002_021f3103+(a==0?1:0)*24),u8 *,0x3e)==1){if((&data_0215c42c)[a])return;(&data_0215c42c)[a]=4;n=1;}else n=0;func_020af828(a,M2C_FIELD((u8 *)M2C_FIELD(*(void **)((u8 *)&data_ov002_021f30f4+a*24),void **,0x34)+n*4,s32 *,0x14));}

void func_020afb34(s32 a){extern M2C_UNK data_ov002_021f30f4;switch(M2C_FIELD(*(void **)((u8 *)&data_ov002_021f30f4+a*24),u8 *,0x3d)){case 2:func_020af828(a,0x2000b);return;case 3:func_020af828(a,0x2000c);return;default:func_020af828(a,0x2000a);return;}}

void func_020afb94(s32 arg0) {
extern M2C_UNK data_ov002_021f30f4;
void func_020afb34(s32);
s32 v=M2C_FIELD(M2C_FIELD(*(void **)((u8*)&data_ov002_021f30f4+arg0*24),void **,0x34),s32 *,0x1c);
if(v){func_020af828(arg0,v);return;}func_020afb34(arg0);
}

void func_020afbcc(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020afbe8(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
}

void func_020afc04(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void func_020afc20(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
}

void func_020afc3c(void) {

}

void func_020afc40(void) {

}

void func_020b00c0(void) {
    M2C_UNK func_0207ce54(s32);
    extern s32 *data_027e0058;
    func_0207ce54(*data_027e0058 + 0x6EF8);
}

void func_020b00e4(void) {

}

void func_020b00e8(void) {

}

void func_020b00ec(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|3;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|2;
}

void func_020b0154(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|2;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|3;
}

