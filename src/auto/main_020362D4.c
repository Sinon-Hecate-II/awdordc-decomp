/* 11 functions from 0x020362D4 to 0x02037214 (main), found by ds-decomp. */
#include "common.h"

void func_0203667c(void) {
 s32 func_02021688(s32,M2C_UNK *,s32); M2C_UNK func_02021750(s32,s32); M2C_UNK func_0202175c(s32); s32 func_02068c34(M2C_UNK *);
 extern M2C_UNK data_020fb968; extern M2C_UNK data_0213d138;
 s32 x;
 x=func_02068c34(&data_020fb968);
 x=func_02021688(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),&data_020fb968,x);
 if(x==-56) return;
 if(x<=0) {
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,60)=2;
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=3;
 func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),2);
 func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0)); return;
 }
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=2;
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,52)=0;
}

void func_02036ec0(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g) {
 M2C_UNK func_02036a7c(s32,s32,s32,s32,s32,s32,s8 *);
 s8 x[1];
 switch(g) {case 255: x[0]=65; break; default: x[0]=*(s8 *)0x027ffe0f; break;}
 func_02036a7c(a,b,c,d,e,f,x);
}

void func_020371f4(void) {
    M2C_UNK func_02037694(M2C_UNK);
    func_02037694(0);
}

void func_02037204(void) {
    M2C_UNK func_020376d8(M2C_UNK);
    func_020376d8(0);
}

