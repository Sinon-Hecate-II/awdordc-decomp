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

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov000_0219afdc(void *arg0,s32 arg1,s32 arg2){
s32 RandomIntRange(s32,s32);s32 func_0207c8ec(s32,s32);s32 func_ov000_0219afa8(s32,s32,s32);extern void **gCurrentMap;extern u8 data_ov000_021dee5c[],data_ov000_021df05c[];
u8 *out=arg0,*src;s32 rnd;u8 *in; s32 i;u8 *rec,*dst;s32 half;void *map;
src=data_ov000_021dee5c+arg1*64;in=data_ov000_021df05c+arg2*192;rnd=RandomIntRange(0,100);map=*gCurrentMap;
if(M2C_FIELD(M2C_FIELD(map,u16*,0x52a4)*140+(s32)((u8*)map+0x67a4),u8*,42)==3)rnd=0;else if(M2C_FIELD(M2C_FIELD(map,u16*,0x52a4)*140+(s32)((u8*)map+0x67a4),u8*,42)==1)rnd=100;
dst=out+12;*(s32*)out=*(s32*)in;rec=in+7;*(s32*)(out+4)=*(s32*)(in+4);half=rnd>>1;i=1;
out[8]=src[0];out[9]=src[1];out[10]=src[2];out[11]=src[3];out[12]=src[4];out[13]=src[5];out[14]=src[6];out[15]=src[7];out[16]=src[8];out[17]=src[9];out[18]=src[10];out[19]=src[11];
do{s32 a=M2C_FIELD((u16*)src+i,u8*,10);s32 b=rec[1];dst[8]=func_0207c8ec(a*b,100);dst[13]=M2C_FIELD((u16*)src+i,u8*,11);map=*gCurrentMap;if((s32)M2C_FIELD(map,u16*,0x52a2)<10&&((u8*)map+M2C_FIELD(map,u16*,0x52a4)*140)[0x67ce]==2){dst[9]=func_ov000_0219afa8(rec[2],rec[3],half);dst[10]=func_ov000_0219afa8(rec[4],rec[5],half);}else{dst[9]=func_ov000_0219afa8(rec[2],rec[3],rnd);dst[10]=func_ov000_0219afa8(rec[4],rec[5],rnd);}i++;dst[11]=rec[6];dst[12]=rec[7];rec+=7;dst+=12;}while(i<27);
}
#pragma opt_common_subs off
void func_ov000_0219b1ac(s32 arg0) {
s32 func_020a8938(u16);s32 func_020d19b4(u16);extern u16 data_02168f14;extern void **gCurrentMap;extern u8 data_ov000_021dee18[],data_ov000_021dee19[],data_ov000_021dee2c[],data_ov000_021dee3b[];extern void *data_ov000_021df57c;
void *map; s32 a,b;
if(func_020a8938(M2C_FIELD(*gCurrentMap,u16*,0x5142))){
if((u32)(data_02168f14<<18)>>31){map=*gCurrentMap;a=func_020a8938(M2C_FIELD(map,u16*,0x5142));b=func_020a8938(M2C_FIELD(map,u16*,0x5142));func_ov000_0219afdc(data_ov000_021df57c,data_ov000_021dee18[a*2],(data_ov000_021dee2c+data_ov000_021dee19[b*2]*15)[(u32)(M2C_FIELD(arg0*140+(s32)map,s32*,0x6810)<<24)>>24]);return;}
if(!(((u32)(data_02168f14<<29)>>29)&255)&&func_020d19b4(M2C_FIELD(*gCurrentMap,u16*,0x52a4))==1){map=*gCurrentMap;a=func_020a8938(M2C_FIELD(map,u16*,0x5142));func_ov000_0219afdc(data_ov000_021df57c,data_ov000_021dee18[a*2],data_ov000_021dee3b[(u32)(M2C_FIELD(arg0*140+(s32)map,s32*,0x6810)<<24)>>24]);return;}
map=*gCurrentMap;a=func_020a8938(M2C_FIELD(map,u16*,0x5142));b=func_020a8938(M2C_FIELD(map,u16*,0x5142));func_ov000_0219afdc(data_ov000_021df57c,data_ov000_021dee18[a*2],data_ov000_021dee2c[data_ov000_021dee19[b*2]*15]);return;
}
if((u32)(data_02168f14<<18)>>31){func_ov000_0219afdc(data_ov000_021df57c,data_ov000_021dee18[2],(data_ov000_021dee2c+data_ov000_021dee18[3]*15)[(u32)(M2C_FIELD(arg0*140+(s32)*gCurrentMap,s32*,0x6810)<<24)>>24]);return;}
func_ov000_0219afdc(data_ov000_021df57c,data_ov000_021dee18[2],data_ov000_021dee2c[data_ov000_021dee18[3]*15]);
}
#pragma opt_common_subs reset
