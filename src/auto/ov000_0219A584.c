/* 11 functions from 0x0219A584 to 0x0219B3C8 (ov000), found by ds-decomp. */
#include "common.h"
extern u8 data_ov000_021df7e4[64];
extern u8 *data_ov000_021df580;
extern void **gCurrentMap;
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
if(func_020d1938(i) && !func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),i))
data_ov000_021df580[4]+=func_ov000_0219a3b0(i);
}
}

void func_ov000_0219a618(void) {
s32 func_020d1938(s32); s32 i,j,end;
for(i=1;i<5;i++) if(func_020d1938(i)) {
s32 start=data_ov000_021aeef4[i];
for(j=start+1;j<start+0x33;j++) {
u8 *p=(u8 *)*gCurrentMap+0x59a4+j*14;
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

void func_ov000_0219a6ec(void *arg0) {
s32 func_020a7cfc(void); s32 func_020a8604(u32,u32); s32 func_0207c8ec(s32,s32);
u32 a,b;
if ((s32)M2C_FIELD(data_ov000_021df644,u8 *,4) > (s32)((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x2000; return;
}
if(func_020a7cfc() && ((u32)(M2C_FIELD(arg0,u16 *,6)<<25)>>25)<50) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x2000; return;
}
a=(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26;
if(data_ov000_021b5c05[a*0x70]) {
b=(u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28;
if(b==0 && func_020a8604(a,b)==0) {
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x1000; return;
}
}
if((u8)func_0207c8ec(((u32)(M2C_FIELD(arg0,u8 *,10)<<25)>>25)*100,data_ov000_021b5c0a[((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70]) >= (u32)M2C_FIELD(data_ov000_021df644,u8 *,3)) return;
M2C_FIELD(arg0,u16 *,8)=(M2C_FIELD(arg0,u16 *,8)&~0x3000)|0x1000;
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
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s32 i;
    u8 *e;
    u32 type;
    u32 state;
    u16 start;
    void *base;
    base = *gCurrentMap;
    start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52a4)];
    for (i = start + 1; i < data_ov000_021aeef4[M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)] + 0x33; i++) {
        e = (u8 *)*gCurrentMap + 0x59a4 + i * 14;
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

void func_ov000_0219a9b0(void) {
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

void func_ov000_0219afdc(void *arg0, s32 arg1, s32 arg2) {
    s32 RandomIntRange(s32, s32);
    s32 func_0207c8ec(s32, s32);
    s32 func_ov000_0219afa8(s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021dee5c[];
    extern u8 data_ov000_021df05c[];
    u8 *out;
    u8 *src;
    s32 rnd;
    u8 *in;
    u8 *rec;
    u8 *dst;
    s32 half;
    s32 i;
    void *map;
    u8 dummy;  // Force register pressure

    out = (u8 *)arg0;
    src = data_ov000_021dee5c + arg1 * 64;
    in = data_ov000_021df05c + arg2 * 0xC0;
    rnd = RandomIntRange(0, 100);
    map = *gCurrentMap;
    if (M2C_FIELD(M2C_FIELD(map, u16 *, 0x52a4) * 0x8c + (s32)((u8 *)map + 0x67a4), u8 *, 0x2a) == 3) {
        rnd = 0;
    } else if (M2C_FIELD(M2C_FIELD(map, u16 *, 0x52a4) * 0x8c + (s32)((u8 *)map + 0x67a4), u8 *, 0x2a) == 1) {
        rnd = 100;
    }
    dst = out + 0xc;
    *(s32 *)out = *(s32 *)in;
    rec = in + 7;
    *(s32 *)(out + 4) = *(s32 *)(in + 4);
    half = rnd >> 1;
    i = 1;
    out[8] = src[0];
    out[9] = src[1];
    out[0xa] = src[2];
    out[0xb] = src[3];
    out[0xc] = src[4];
    out[0xd] = src[5];
    out[0xe] = src[6];
    out[0xf] = src[7];
    out[0x10] = src[8];
    out[0x11] = src[9];
    out[0x12] = src[0xa];
    out[0x13] = src[0xb];
    do {
        dst[8] = func_0207c8ec(M2C_FIELD(((u16 *)src) + i, u8 *, 0xa) * rec[1], 100);
        dst[0xd] = M2C_FIELD(((u16 *)src) + i, u8 *, 0xb);
        map = *gCurrentMap;
        if ((s32)M2C_FIELD(map, u16 *, 0x52a2) < 0xa &&
            M2C_FIELD(M2C_FIELD(map, u16 *, 0x52a4) * 0x8c + (s32)map, u8 *, 0x67ce) == 2) {
            dst[9] = func_ov000_0219afa8(rec[2], rec[3], half);
            dst[0xa] = func_ov000_0219afa8(rec[4], rec[5], half);
        } else {
            dst[9] = func_ov000_0219afa8(rec[2], rec[3], rnd);
            dst[0xa] = func_ov000_0219afa8(rec[4], rec[5], rnd);
        }
        i++;
        dst[0xb] = rec[6];
        dst[0xc] = rec[7];
        rec += 7;
        dst += 0xc;
    } while (i < 27);
}

void func_ov000_0219b1ac(s32 arg0) {
    s32 func_020a8938(u16);
    s32 func_020d19b4(u16);
    void func_ov000_0219afdc(void*, s32, s32);
    extern u16 data_02168f14;
    extern void **data_027e0058;
    extern u8 data_ov000_021dee18[];
    extern u8 data_ov000_021dee19[];
    extern u8 data_ov000_021dee2c[];
    extern u8 data_ov000_021dee3b[];
    extern void* data_ov000_021df57c;
    void *temp_r6;
    s32 temp_r4;
    s32 temp_r4_4;
    void *temp_r4_2;
    void *temp_r4_3;

    if (func_020a8938(M2C_FIELD(*data_027e0058, u16 *, 0x5142)) != 0) {
        if (((u32) (data_02168f14 << 0x12) >> 0x1F) != 0) {
            temp_r6 = *data_027e0058;
            temp_r4 = func_020a8938(M2C_FIELD(temp_r6, u16 *, 0x5142));
            func_ov000_0219afdc(data_ov000_021df57c, data_ov000_021dee18[temp_r4], data_ov000_021dee2c[data_ov000_021dee19[func_020a8938(M2C_FIELD(temp_r6, u16 *, 0x5142))] * 15 + (u8) M2C_FIELD(((arg0 * 0x8C) + (s32) temp_r6), s32 *, 0x6810)]);
            return;
        }
        if (!(((u32) (data_02168f14 << 0x1D) >> 0x1D) & 0xFF) && (func_020d19b4(M2C_FIELD(*data_027e0058, u16 *, 0x52A4)) == 1)) {
            temp_r4_2 = *data_027e0058;
            func_ov000_0219afdc(data_ov000_021df57c, data_ov000_021dee18[func_020a8938(M2C_FIELD(temp_r4_2, u16 *, 0x5142))], data_ov000_021dee3b[(u8) M2C_FIELD(((arg0 * 0x8C) + (s32) temp_r4_2), s32 *, 0x6810)]);
            return;
        }
        temp_r4_3 = *data_027e0058;
        temp_r4_4 = func_020a8938(M2C_FIELD(temp_r4_3, u16 *, 0x5142));
        func_ov000_0219afdc(data_ov000_021df57c, data_ov000_021dee18[temp_r4_4], data_ov000_021dee2c[data_ov000_021dee19[func_020a8938(M2C_FIELD(temp_r4_3, u16 *, 0x5142))] * 15]);
        return;
    }
    if (((u32) (data_02168f14 << 0x12) >> 0x1F) != 0) {
        func_ov000_0219afdc(data_ov000_021df57c, data_ov000_021dee18[1], data_ov000_021dee2c[data_ov000_021dee18[1] * 15 + (u8) M2C_FIELD(((arg0 * 0x8C) + (s32) *data_027e0058), s32 *, 0x6810)]);
        return;
    }
    func_ov000_0219afdc(data_ov000_021df57c, data_ov000_021dee18[1], data_ov000_021dee2c[data_ov000_021dee18[1] * 15]);
}

