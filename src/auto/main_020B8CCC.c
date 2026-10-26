/* 21 functions from 0x020B8CCC to 0x020B9C8C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 value; u8 flag; } Unk020BChoice;

void func_020b90d8(void) {M2C_UNK func_01ff9ce8(M2C_UNK,s32);void func_020cfd28();void func_020d472c();extern void *gCur3DSpriteEngine;extern void *data_027e00c8;void *old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;((M2C_UNK (*)())func_01ff9ce8)(1);((M2C_UNK (*)())func_01ff9ce8)(2);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;func_020cfd28();func_020d472c();gCur3DSpriteEngine=old;}

void func_020b9140(s32 arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, s32);
    extern M2C_UNK data_021290dc;
    if (arg0 == 0) {
        func_01ffa3dc(&data_021290dc, 7);
        return;
    }
    func_01ffa3dc(&data_021290dc, arg0);
}

void func_020b939c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    M2C_UNK func_0208fb0c(s32, s16, s16);
    s32 func_020cd674();
    extern void **data_027e0058;
    void *temp_r1;

    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 8;
    temp_r1 = *data_027e0058;
    func_0208fb0c(0x111, M2C_FIELD(temp_r1, s16 *, 0x52C2), M2C_FIELD(temp_r1, s16 *, 0x52C4));
    if (func_020cd674() == 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_020b93f4(void *a) {s32 func_020d2d38(s32,s32);s32 func_0207ca38(s32,s32,s32,s32,s32);void func_020b916c(s32,s32,s32,s32,s32);M2C_UNK func_0208fe30(s32);void func_01ffa6fc(void *);extern void **data_027e0058;
s32 n,limit,total,base,delta,v,index;void *g;
v=M2C_FIELD(a,s32 *,92);M2C_FIELD(a,s16 *,108)++;g=*data_027e0058;n=M2C_FIELD(a,s16 *,108);limit=M2C_FIELD(a,s16 *,110);
index=M2C_FIELD(g,u16 *,0x52a4);total=M2C_FIELD((u8 *)g+index*140,s32 *,0x67a4);
base=func_020d2d38(index,v);delta=total-base;
func_020b916c(0,1,func_0207ca38(0,total,delta,n,limit),-base,delta);
if((n&3)==1)func_0208fe30(0x10023);if(n<limit)return;func_01ffa6fc(a);
}

void func_020b94a4(void *a) {s32 func_020a67fc(s32,s32,s32);void func_ov000_02199f50(s32,u8,s32,s32);void func_ov000_0216aa44(s32,s32);extern void **data_027e0058;s32 v=M2C_FIELD(a,s32 *,92);s32 result;void *g=*data_027e0058;
result=func_020a67fc(M2C_FIELD(g,s16 *,0x52c2),M2C_FIELD(g,s16 *,0x52c4),v);
M2C_FIELD(*data_027e0058,s16 *,0x52dc)=M2C_FIELD(*data_027e0058,s16 *,0x52c2);
M2C_FIELD(*data_027e0058,s16 *,0x52de)=M2C_FIELD(*data_027e0058,s16 *,0x52c4);
func_ov000_02199f50(1,v,0,0);func_ov000_0216aa44(14,result);M2C_FIELD(*data_027e0058,s16 *,0x52b4)=0;
}

void func_020b953c(s32 arg0, s32 arg1) {
    void *func_01ffa42c(M2C_UNK *);
    extern M2C_UNK data_02129178;
    M2C_FIELD(func_01ffa42c(&data_02129178), s32 *, 0x5C) = arg0;
}

void func_020b9558(u8 a) {s32 func_020d2d38(s32,s32);void func_020b916c(s32,s32,s32,s32,s32);void func_ov000_02174d10(s32,s32);extern void **data_027e0058;void *g=*data_027e0058;s32 idx=M2C_FIELD(g,u16 *,0x52a4);s32 total=M2C_FIELD((u8 *)g+idx*140,s32 *,0x67a4);s32 base=func_020d2d38(idx,a);func_020b916c(0,1,total,-base,total-base);func_ov000_02174d10(M2C_FIELD(*data_027e0058,u16 *,0x52a4),a);}

void func_020b96e0(u8 *a) {s32 func_020d2dcc(s32);M2C_UNK func_0208fe30(s32);void func_02096b6c(u32);s32 func_01ffa770(M2C_UNK *);M2C_UNK func_020b2178();M2C_UNK func_01ffa9bc(M2C_UNK *);extern void **data_027e0058;extern u8 data_0215d859[];extern u8 data_0215d858[];extern M2C_UNK data_021291b0;u32 index=*a;
if(data_0215d859[index*2]==1){func_0208fe30(0x1001d);return;}
if(!func_020d2dcc(M2C_FIELD(*data_027e0058,u16 *,0x52a4))){func_0208fe30(0x1001d);func_02096b6c(0xc0000332);}else {s32 result=func_01ffa770(&data_021291b0);func_020b953c(data_0215d858[index*2],result);}
func_020b2178();func_01ffa9bc(&data_021291b0);
}

void func_020b9778(void) {
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b2178();
    extern M2C_UNK data_021291b0;
    func_0208fe30(0x10018);
    func_020b2178();
    func_01ffa9bc(&data_021291b0);
}

void func_020b979c(u8 *a) {void func_020b9558(u8);M2C_UNK func_0208fe30(s32);extern u8 data_0215d858[];func_020b9558(data_0215d858[*a*2]);func_0208fe30(0x10019);}

void func_020b97c4(s32 a,s32 b) {void func_020b9874(s8);M2C_UNK func_01ffa3dc(M2C_UNK *,s32);extern void **data_027e0058;extern M2C_UNK data_0215d850;extern M2C_UNK data_021291b0;u8 *g=*data_027e0058;u32 type=M2C_FIELD(g+(a+M2C_FIELD(g+b*2,u16 *,0x3758)),u8 *,0x1420)&31;switch(type){case 15:case 16:case 17:data_0215d850=7;break;case 18:data_0215d850=16;break;case 19:data_0215d850=32;break;}
func_020b9874((s8)data_0215d850);func_01ffa3dc(&data_021291b0,7);
}

void func_020b9978(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK, s32);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020b9b48(s32 a,s32 b,s32 c) {M2C_UNK func_020b22a4(s32,s32,M2C_UNK *,s32);extern u8 data_0215d858[];extern M2C_UNK data_02129150;s32 i;Unk020BChoice *p; a=(a+1)*8;b=(b+1)*8;i=0;p=(Unk020BChoice *)data_0215d858+c;do {if(p[i].value==0)return;func_020b22a4(a,b,&data_02129150,c+i);i++;b+=16;}while(i<7);}

void func_020b9bac(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020b99ac(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020c08f8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_020c08f8(arg0, arg1, 0x10, 0x10, 1);
    func_020b99ac(arg0, arg1, arg2);
}

void func_020b9bec(void) {void func_020b9b48(s32,s32,s32);void func_020b1c78(s32);extern M2C_UNK data_0215d850;if(M2C_FIELD(&data_0215d850,s32 *,4)<=7)func_020b9b48(8,4,0);else {func_020b9b48(0,4,0);func_020b9b48(16,4,7);}func_020b1c78(0);}

void func_020b9c40(void) {
    extern M2C_UNK data_0215d850;
    if ((s32) M2C_FIELD(&data_0215d850, s32 *, 4) <= 7) {
        func_020b9bac(8, 4, 0);
        return;
    }
    func_020b9bac(0, 4, 0);
    func_020b9bac(0x10, 4, 7);
}

