/* 11 functions from 0x0219A584 to 0x0219B3C8 (ov000), found by ds-decomp. */
#include "common.h"
extern u8 data_ov000_021df7e4[64];
extern u8 *data_ov000_021df580;
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
extern u8 data_ov000_021b5c05[];
extern u8 data_ov000_021b5c0a[];
extern void *data_ov000_021df57c;
extern void *data_ov000_021df644;

void func_ov000_0219a584(void) {
s32 func_ov000_0219a3b0(s32); s32 func_020d1938(s32); s32 func_020d273c(u16,s32);
s32 i;
data_ov000_021df580[4]=0;
data_ov000_021df580[4]+=func_ov000_0219a3b0(0);
for(i=1;i<5;i++) {
if(func_020d1938(i) && !func_020d273c(M2C_FIELD(*data_027e0058,u16 *,0x52a4),i))
data_ov000_021df580[4]+=func_ov000_0219a3b0(i);
}
}

void func_ov000_0219a618(void) {
s32 func_020d1938(s32); s32 i,j,end;
for(i=1;i<5;i++) if(func_020d1938(i)) {
s32 start=data_ov000_021aeef4[i];
for(j=start+1;j<start+0x33;j++) {
u8 *p=(u8 *)*data_027e0058+0x59a4+j*14;
if((u32)(p[0]<<26)>>26) {
M2C_FIELD(p,u16 *,8)&=~0xc000; p[11]&=~0x20; p[10]&=~0x80;
}
}
}
}

void func_ov000_0219a6c8(void) {
s32 i=0; u8 *p=data_ov000_021df7e4; u8 zero=i;
do { i++; *p++=zero; } while(i<64);
}

void func_ov000_0219a818(void *arg0) {
s32 func_020a8604(u32,u32);
u32 a,b;
a=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;
if(data_ov000_021b5c05[a*0x70]) {
b=(u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28;
if(b==0 && func_020a8604(a,b)==0) return;
}
if((s32)(data_ov000_021b5c0a[((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70]>>1)<(s32)((u32)(M2C_FIELD(arg0,u8 *,10)<<25)>>25))
M2C_FIELD(arg0,u16 *,8)&=~0x3000;
}

void func_ov000_0219a8a4(void *arg0) {
    if ((u32) ((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19) >= 0x3DU) {
        M2C_FIELD(arg0, u16 *, 8) = (u16) (M2C_FIELD(arg0, u16 *, 8) & ~0x3000);
    }
}

void func_ov000_0219a8c4(void) {
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    s32 i;
    u8 *e;
    u32 type;
    u32 state;
    u16 start;
    void *base;
    base = *data_027e0058;
    start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52a4)];
    for (i = start + 1; i < data_ov000_021aeef4[M2C_FIELD(*data_027e0058, u16 *, 0x52a4)] + 0x33; i++) {
        e = (u8 *)*data_027e0058 + 0x59a4 + i * 14;
        type = (u32)(e[0] << 26) >> 26;
        if (type == 0) continue;
        data_ov000_021df644 = (void *)((u8 *)data_ov000_021df57c + 0x14 + (type - 1) * 12);
        state = (u32)(M2C_FIELD(e, u16 *, 8) << 18) >> 30;
        switch (state) {
            case 1: func_ov000_0219a818(e); break;
            case 2: func_ov000_0219a8a4(e); break;
            default: func_ov000_0219a6ec(e); break;
        }
    }
}

s32 func_ov000_0219afa8(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0207c8ec(s32, M2C_UNK);
    s32 var_r0;

    var_r0 = arg0 + (func_0207c8ec(arg1 * arg2, 0x64) - (arg1 >> 1));
    if (var_r0 < 1) {
        var_r0 = 1;
    }
    if (var_r0 > 0xFF) {
        var_r0 = 0xFF;
    }
    return var_r0;
}

