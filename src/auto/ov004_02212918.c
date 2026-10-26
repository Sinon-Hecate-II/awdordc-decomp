/* 23 functions from 0x02212918 to 0x022138B0 (ov004), found by ds-decomp. */
#include "common.h"

void func_ov004_022130f4(void) {
    M2C_UNK func_ov004_022120c0();
    func_ov004_022120c0();
}

void func_ov004_02213100(void) {
    M2C_UNK func_ov004_0221285c();
    func_ov004_0221285c();
}

void func_ov004_0221310c(void) {
    M2C_UNK func_ov004_02212918();
    func_ov004_02212918();
}

void func_ov004_02213118(void) {
    M2C_UNK func_ov004_022128b8();
    func_ov004_022128b8();
}

void func_ov004_02213124(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov004_02218da8;
    func_01ffa42c(&data_ov004_02218da8, arg0);
}

s32 func_ov004_0221313c(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 u32 bits; u8 v; s32 i; s32 p; s32 end;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=(s32)*data_027e0058+0x59A4+i*14;
 do {v=M2C_FIELD(p,u8 *,0); bits=(u32)(v<<26)>>26; if(bits&&((u32)(v<<24)>>30))return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_022131b0(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=90U)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_0221322c(void) {
 extern void **data_027e0058;
 s32 p; s32 x,y; s32 n;
 p=(s32)*data_027e0058+0x5200;
 n=M2C_FIELD(p,u16 *,0xA2); if(n<2)return 0;
 x=M2C_FIELD(p,s16 *,0xDC); y=M2C_FIELD(p,s16 *,0xDE);
 return x==11&&y==6;
}

s32 func_ov004_0221326c(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 i; u8 *p; s32 end; u8 *base;
 base=(u8 *)*data_027e0058;
 if((s32)M2C_FIELD(base,u16 *,0x52A2)<2)return 0;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=base+0x59A4+i*14;
 do {if(((u32)(*p<<26)>>26)&&p[1]==11&&p[2]==6)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_022132fc(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=70U&&bits==2)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_02213380(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=70U&&bits==7)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

u8 func_ov004_02213404(void) {
    extern void **data_027e0058;
    u8 temp_r1;
    u8 var_r0;
    void *temp_r2;

    temp_r2 = *data_027e0058;
    temp_r1 = M2C_FIELD((temp_r2 + (M2C_FIELD(temp_r2, u16 *, 0x3762) + 5)), u8 *, 0x508);
    if (temp_r1 == 0) {
        return 0U;
    }
    if ((u32) ((u32) (M2C_FIELD(((temp_r1 * 0xE) + (s32) temp_r2), u16 *, 0x59AA) << 0x19) >> 0x19) <= 0x5AU) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov004_02213460(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count<=4)return 1; return 0;
}

s32 func_ov004_022134d0(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 result; u32 bits; s32 i; u8 *p; s32 end; u8 *base;
 result=1; base=(u8 *)*data_027e0058;
 if((s32)M2C_FIELD(base,u16 *,0x52A2)>1)return 0;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=base+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&bits==1&&p[2]<=5U)result=0; i++; p+=14;}while(i<end);}
 return result;
}

s32 func_ov004_02213564(void) {
 extern void **data_027e0058; extern u8 data_ov000_021df7d0;
 u8 value; u8 *p; u8 *base; u8 x,y;
 base=*data_027e0058; p=M2C_FIELD(base,u8 **,0x52D0); x=p[1]; y=p[2];
 if(data_ov000_021df7d0==3) {
 p=base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)); value=p[0x1420];
 if(((s32)(value&0xE0)>>5)==1&&(value&0x1F)==0x10)return 1;
 } return 0;
}

s32 func_ov004_022135d8(void) {
extern void **data_027e0058;
extern u8 data_ov000_021df7d0;
u8 value,*p,*base,x,y;
base=*data_027e0058;
p=M2C_FIELD(base,u8 **,0x52d0);
x=p[1];y=p[2];
if(data_ov000_021df7d0==3) {
p=base+(x+M2C_FIELD(base+y*2,u16 *,0x3758));value=p[0x1420];
if(((s32)(value&0xe0)>>5)==1 && (value&0x1f)==0x11)return 1;
}
return 0;
}

s32 func_ov004_0221364c(void) {
extern void **data_027e0058;
extern u8 data_ov000_021df7d0;
u8 value,*p,*base,x,y;
base=*data_027e0058;
p=M2C_FIELD(base,u8 **,0x52d0);
x=p[1];y=p[2];
if(data_ov000_021df7d0==3 && M2C_FIELD(base,u16 *,0x52a4)==1) {
p=base+(x+M2C_FIELD(base+y*2,u16 *,0x3758));value=p[0x1420];
if((value&0x1f)==0x11)return 1;
}
return 0;
}

s32 func_ov004_022136c0(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=90U)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_0221373c(void) {
extern void **data_027e0058;
u8 *base; u32 i; u8 v;
base=*data_027e0058;
if(M2C_FIELD(base,u16 *,0x52a4)==1) {
i=M2C_FIELD(base,u16 *,0x3764)+3;
v=(base+i)[0x1420];
if(((s32)(v&0xe0)>>5)==1) {if(base[i]==0)return 1;}
}return 0;
}

s32 func_ov004_02213798(void) {
extern void **data_027e0058;extern u16 data_ov000_021aeef4[];
s32 count,i,end;u8 *p,v;
count=0;
if(func_02086b40(0))return count;
i=data_ov000_021aeef4[2]+1;end=data_ov000_021aeef4[2]+0x33;
if(i<end) {
p=(u8 *)*data_027e0058+0x59a4+i*14;
do {v=*p;if((u32)(v<<26)>>26)count++;i++;p+=14;}while(i<end);
}
if(count!=0)return 0;return 1;
}

u8 func_ov004_02213820(void) {
    s32 func_02086b40(M2C_UNK);
    u8 var_r0;

    if (func_02086b40(1) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov004_02213840(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

