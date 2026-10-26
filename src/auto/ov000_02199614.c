/* 14 functions from 0x02199614 to 0x0219A584 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u16 value:7; } Field7;

void func_ov000_021998f0(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_02199614(u8);
    extern s32 *data_027e0058;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*data_027e0058, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), i) == 0) {
            func_ov000_02199614(i);
        }
    }
    M2C_FIELD(*data_027e0058, u16 *, 0x52B6) = saved;
}

void func_ov000_02199ce0(void) {
void func_02085348(void *,s32);
extern u8 data_ov000_021df7d0[];
extern u8 data_02156e50[];
s32 i;
u8 *s;
u8 *d;
u8 t;
s=data_ov000_021df7d0;
d=data_02156e50;
d[0]=s[0]; t=s[2]; d[2]=t; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[1]=s[1];
*(s32 *)(d+8)=*(s32 *)(s+8);
d[6]=s[6]; d[7]=s[7]; d[0x12]=s[0x12];
i=0;
do { i++; d[12]=s[12]; s++; d++; } while(i<6);
func_02085348(data_02156e50,0x14);
}

void func_ov000_02199f38(void) {
    M2C_UNK func_02072b10(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021df604;
    func_02072b10(&data_ov000_021df604, 1);
}

void func_ov000_0219a064(void) {
extern s32 *data_027e0058;
extern u8 data_ov000_021df7d0[];
u8 *p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);

if(!p || !((Field7 *)(p+6))->value) return;

if(data_ov000_021df7d0[0]==4) p[11]|=0x40;
else if(data_ov000_021df7d0[2]!=data_ov000_021df7d0[4] || data_ov000_021df7d0[3]!=data_ov000_021df7d0[5]) p[11]&=~0x40;
}

void func_ov000_0219a350(void) {
    extern void *data_ov000_021df578;
    M2C_FIELD(data_ov000_021df578, s8 *, 2) = 0;
    M2C_FIELD(data_ov000_021df578, s8 *, 3) = 0;
}

void func_ov000_0219a370(void) {
    extern s32 *data_027e0058;
    s32 var_r1;
    void *var_r2;

    var_r1 = 0;
    var_r2 = *data_027e0058 + 0x6C60;
    do {
        M2C_FIELD(var_r2, s8 *, 3) = 0;
        M2C_FIELD(var_r2, s8 *, 4) = 0;
        var_r1 += 1;
        M2C_FIELD(var_r2, s8 *, 5) = 0;
        var_r2 += 6;
    } while (var_r1 < 0x63);
}

s32 func_ov000_0219a3b0(s32 n) {
extern s32 *data_027e0058;
u8 *p=(u8 *)*data_027e0058+0x67a4+n*0x8c;
s32 sum=0;
sum+=p[0x11]; sum+=p[0x10]; sum+=p[0x12]; sum+=p[0x13]; sum+=p[0x14]; sum+=p[0x15]; sum+=p[0x16]; sum+=p[0x17];
return sum+1;
}

