/* 14 functions from 0x0204FED0 to 0x02050C24 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;

void func_0204fed0(s32 a,s32 b) {
void func_020675e4(void *,void *);void func_0204fea0(s32,s32,void *);
extern M2C_UNK data_020fdfb0;
u8 sp0[16];
func_020675e4(sp0,&data_020fdfb0);
func_0204fea0(a,b,sp0);
}

void func_020501d8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020500d8(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_02068c34(M2C_UNK);
    func_020500d8(arg0, arg1, arg2, func_02068c34(arg2));
}

s32 func_020506ec(s32 unused,void *p) {
s32 n;
if(!p || !M2C_FIELD(p,s32 *,0) || !M2C_FIELD(p,s32 *,12))return 0;
n=M2C_FIELD(p,s32 *,8)-M2C_FIELD(p,s32 *,12);
M2C_FIELD(p,s32 *,8)=n;
if(n)func_020651c4(M2C_FIELD(p,s32 *,0),M2C_FIELD(p,s32 *,0)+M2C_FIELD(p,s32 *,12),n);
M2C_FIELD(M2C_FIELD(p,s32 *,0)+M2C_FIELD(p,s32 *,8),u8 *,0)=0;
M2C_FIELD(p,s32 *,12)=0;return 0;
}

s32 func_02050838(void *arg0,volatile Unk02050838Pair pair,s32 c,s32 arg4,u32 arg5) {
void *func_02037794(s32);
extern M2C_UNK data_020fe1ac;
void *base=M2C_FIELD(arg0,void **,0);
void *p=func_02037794(24);
void *q;
if(!p) {func_02058644(arg0,&data_020fe1ac);return 1;}
M2C_FIELD(p,s32 *,0)=pair.unk_0;M2C_FIELD(p,s32 *,4)=pair.unk_4;M2C_FIELD(p,s32 *,8)=c;
M2C_FIELD(p,void **,16)=arg4?M2C_FIELD(arg4,void **,24):NULL;
M2C_FIELD(p,s32 *,12)=arg5;M2C_FIELD(p,s32 *,20)=0;
if(!M2C_FIELD(base,void **,0x438))M2C_FIELD(base,void **,0x438)=p;
q=M2C_FIELD(base,void **,0x43c);
if(q)M2C_FIELD(q,void **,20)=p;
M2C_FIELD(base,void **,0x43c)=p;return 0;
}

void func_02050bbc(s8 *p,s32 n) {
u32 func_02067774(void);extern s8 data_020fe250[];
s32 i=0;
for(;i<n;i++)p[i]=data_020fe250[func_02067774()%62U];
p[i]=0;
}

